// Copyright (c) 2015, 2016 Max Stadler, Patrick Dowling
//
// Original Author : Max Stadler
// Heavily modified: Patrick Dowling (pld@gurkenkiste.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Main startup/loop for O&C firmware

#include <Arduino.h>
#include <EEPROM.h>

#include "OC_core.h"
#include "OC_apps.h"
#include "OC_DAC.h"
#include "OC_debug.h"
#include "OC_gpio.h"
#include "OC_ADC.h"
#include "OC_calibration.h"
#include "OC_digital_inputs.h"
#include "OC_menus.h"
#include "OC_strings.h"
#include "OC_ui.h"
#include "OC_options.h"
#include "src/drivers/display.h"
#include "src/drivers/ADC/OC_util_ADC.h"
#include "util/util_debugpins.h"
#include "VBiasManager.h"
#include "HSMIDI.h"

#if defined(__IMXRT1062__)
USBHost thisUSB;
USBHub hub1(thisUSB);
MIDIDevice usbHostMIDI(thisUSB);

#if defined(ARDUINO_TEENSY41)
MIDI_CREATE_INSTANCE(HardwareSerial, Serial8, MIDI1);
#include "AudioSetup.h"
#endif

#endif // __IMXRT1062__

unsigned long LAST_REDRAW_TIME = 0;
uint_fast8_t MENU_REDRAW = true;
OC::UiMode ui_mode = OC::UI_MODE_MENU;
const bool DUMMY = false;

/*  ------------------------ UI timer ISR ---------------------------   */

IntervalTimer UI_timer;

void FASTRUN UI_timer_ISR() {
  OC_DEBUG_PROFILE_SCOPE(OC::DEBUG::UI_cycles);
  OC::ui.Poll();
  OC_DEBUG_RESET_CYCLES(OC::ui.ticks(), 2048, OC::DEBUG::UI_cycles);
}

/*  ------------------------ core timer ISR ---------------------------   */
IntervalTimer CORE_timer;
volatile bool OC::CORE::app_isr_enabled = false;
volatile uint32_t OC::CORE::ticks = 0;

void FASTRUN CORE_timer_ISR() {
  DEBUG_PIN_SCOPE(OC_GPIO_DEBUG_PIN2);
  OC_DEBUG_PROFILE_SCOPE(OC::DEBUG::ISR_cycles);

  // DAC and display share SPI. By first updating the DAC values, then starting
  // a DMA transfer to the display things are fairly nicely interleaved. In the
  // next ISR, the display transfer is finalized (CS update).

  display::Flush();
  OC::DAC::Update();
  display::Update();

  // see OC_ADC.h for details; empirically (with current parameters), Scan_DMA() picks up new samples @ 5.55kHz
  OC::ADC::Scan_DMA();

  // Pin changes are tracked in separate ISRs, so depending on prio it might
  // need extra precautions.
  OC::DigitalInputs::Scan();

#ifndef OC_UI_SEPARATE_ISR
  TODO needs a counter
  UI_timer_ISR();
#endif

  ++OC::CORE::ticks;
  if (OC::CORE::app_isr_enabled)
    OC::apps::ISR();

  OC_DEBUG_RESET_CYCLES(OC::CORE::ticks, 16384, OC::DEBUG::ISR_cycles);
}

/*       ---------------------------------------------------------         */

void setup() {
  delay(50);
  Serial.begin(9600);

#if defined(__IMXRT1062__)
  if (CrashReport) {
    while (!Serial && millis() < 3000) ; // wait
    Serial.println(CrashReport);
    delay(1500);
  }

  #if defined(ARDUINO_TEENSY41)
  OC::Pinout_Detect();

  // Standard MIDI I/O on Serial8, only for Teensy 4.1
  if (MIDI_Uses_Serial8) {
    Serial8.begin(31250);
    MIDI1.begin(MIDI_CHANNEL_OMNI);
  }

  if (I2S2_Audio_ADC && I2S2_Audio_DAC) {
    OC::AudioDSP::Init();
  }
  #endif

  // USB Host support for both 4.0 and 4.1
  usbHostMIDI.begin();
#endif
#if defined(__MK20DX256__)
  NVIC_SET_PRIORITY(IRQ_PORTB, 0); // TR1 = 0 = PTB16
#endif
  SPI_init();
  SERIAL_PRINTLN("* O&C BOOTING...");
  SERIAL_PRINTLN("* %s", OC::Strings::VERSION);

  OC::DEBUG::Init();
  OC::DigitalInputs::Init();
  #if defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41)
  if (DAC8568_Uses_SPI) {
    // DAC8568 Vref does not turn on by default like DAC8565
    // best to turn on Vref as early as possible for analog
    // circuitry to settle
    OC::DAC::DAC8568_Vref_enable();
  }
  if (ADC33131D_Uses_FlexIO) {
    // ADC33131D wants calibration for Vref, takes ~1150 ms
    OC::ADC::ADC33131D_Vref_calibrate();
  } else {
  #endif
    delay(400);
  #if defined(__IMXRT1062__) && defined(ARDUINO_TEENSY41)
  }
  #endif
  OC::ADC::Init(&OC::calibration_data.adc); // Yes, it's using the calibration_data before it's loaded...
  OC::ADC::Init_DMA();
  OC::DAC::Init(&OC::calibration_data.dac);

  display::Init();

  GRAPHICS_BEGIN_FRAME(true);
  GRAPHICS_END_FRAME();

  OC::calibration_load();
  
  display::AdjustOffset(OC::calibration_data.display_offset);

  OC::menu::Init();
  OC::ui.Init();
  OC::ui.configure_encoders(OC::calibration_data.encoder_config());

  SERIAL_PRINTLN("* CORE ISR @%luus", OC_CORE_TIMER_RATE);
  CORE_timer.begin(CORE_timer_ISR, OC_CORE_TIMER_RATE);
  CORE_timer.priority(OC_CORE_TIMER_PRIO);

#ifdef OC_UI_SEPARATE_ISR
  SERIAL_PRINTLN("* UI ISR @%luus", OC_UI_TIMER_RATE);
  UI_timer.begin(UI_timer_ISR, OC_UI_TIMER_RATE);
  UI_timer.priority(OC_UI_TIMER_PRIO);
#endif

  // Display splash screen and optional calibration
  bool reset_settings = false;
  ui_mode = OC::ui.Splashscreen(reset_settings);

  bool start_cal = false;
  if (ui_mode == OC::UI_MODE_CALIBRATE) {
    start_cal = true;
    ui_mode = OC::UI_MODE_MENU;
  }
  OC::ui.set_screensaver_timeout(OC::calibration_data.screensaver_timeout);

#ifdef VOR
  VBiasManager *vbias_m = vbias_m->get();
  vbias_m->SetState(VBiasManager::BI);
#endif

  // initialize apps
  OC::apps::Init(reset_settings);

  if (start_cal)
    OC::start_calibration();
}

/*  ---------    main loop  --------  */

void FASTRUN loop() {

  OC::CORE::app_isr_enabled = true;
  uint32_t menu_redraws = 0;
  while (true) {

    // don't change current_app while it's running
    if (OC::UI_MODE_APP_SETTINGS == ui_mode) {
      OC::ui.AppSettings();
      ui_mode = OC::UI_MODE_MENU;
    }

    // Refresh display
    if (MENU_REDRAW) {
      GRAPHICS_BEGIN_FRAME(false); // Don't busy wait
        if (OC::UI_MODE_MENU == ui_mode) {
          OC_DEBUG_RESET_CYCLES(menu_redraws, 512, OC::DEBUG::MENU_draw_cycles);
          OC_DEBUG_PROFILE_SCOPE(OC::DEBUG::MENU_draw_cycles);
          OC::apps::current_app->DrawMenu();
          ++menu_redraws;

          #ifdef VOR
          // JEJ:On app screens, show the bias popup, if necessary
          VBiasManager *vbias_m = vbias_m->get();
          vbias_m->DrawPopupPerhaps();
          #endif

        } else {
          OC::apps::current_app->DrawScreensaver();
        }
        MENU_REDRAW = 0;
        LAST_REDRAW_TIME = millis();
      GRAPHICS_END_FRAME();
    }

    // Run current app
    OC::apps::current_app->loop();

    // UI events
    OC::UiMode mode = OC::ui.DispatchEvents(OC::apps::current_app);

    // State transition for app
    if (mode != ui_mode) {
      if (OC::UI_MODE_SCREENSAVER == mode)
        OC::apps::current_app->HandleAppEvent(OC::APP_EVENT_SCREENSAVER_ON);
      else if (OC::UI_MODE_SCREENSAVER == ui_mode)
        OC::apps::current_app->HandleAppEvent(OC::APP_EVENT_SCREENSAVER_OFF);
      ui_mode = mode;
    }

    if (millis() - LAST_REDRAW_TIME > REDRAW_TIMEOUT_MS)
      MENU_REDRAW = 1;

    static size_t cap_idx = 0;
    // check for request from PC to capture the screen
    if (Serial && Serial.available() > 0) {
      do { Serial.read(); } while (Serial.available() > 0);
      display::frame_buffer.capture_request();
      cap_idx = 0;
    }

    // check for frame buffer to have capture data ready
    const uint8_t *capture_data = display::frame_buffer.captured();
    if (capture_data && MENU_REDRAW) {
      capture_data += cap_idx; // start where we left off

      // limit to n bytes every 1ms
      const size_t chunk_size = 32;
      for (size_t i=0; i < chunk_size; i++) {
        uint8_t n = *capture_data++;
        if (n < 16) Serial.print("0");
        Serial.print(n, HEX);

        if (++cap_idx >= display::frame_buffer.kFrameSize) {
          // we're done sending this one
          Serial.println();
          Serial.flush();
          cap_idx = 0;
          display::frame_buffer.capture_retire();
          break;
        }
      }
    }

  }
}


