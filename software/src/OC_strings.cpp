#include "OC_strings.h"

namespace OC {

  namespace Strings {

  const char * const VERSION =
#include "OC_version.h"
#ifdef OC_VERSION_EXTRA
    OC_VERSION_EXTRA
#endif
#ifdef OC_BUILD_TAG
    "-"
    OC_BUILD_TAG
#endif
    ;
#ifdef BUCHLA_cOC
  const char * const NAME = "NLM card O_C";
  const char * const SHORT_NAME = "cOC";
#elif defined(VOR)
  const char * const NAME = "Plum Audio O_C+";
  const char * const SHORT_NAME = "OC+";
#else
  const char * const NAME = "Ornaments & Crimes";
  const char * const SHORT_NAME = "o_C";
#endif

  const char * const seq_playmodes[] = {" -", "SEQ+1", "SEQ+2", "SEQ+3", "TR+1", "TR+2", "TR+3", "ARP", "S+H#1", "S+H#2", "S+H#3", "S+H#4", "CV#1", "CV#2", "CV#3", "CV#4"};

  const char * const channel_trigger_sources[] = {"TR1", "TR2", "TR3", "TR4", "cnt+", "cnt-"};

  const char * const seq_directions[] = {"fwd", "rev", "pnd1", "pnd2", "rnd", "brwn"};

  const char * const scale_degrees_maj[] = {"I", "II", "III", "IV", "V", "VI", "VII"};
  
  const char* const scale_degrees_min[] = {"i", "ii", "iii", "iv", "v", "vi", "vii"};

  const char* const accidentals[] = {"bb", "b", "", "#", "##"};

  const char * const scale_id[] = { ">#1", ">#2", ">#3", ">#4", " #1", " #2", " #3", " #4"};
  
  const char * const note_names[12] = { "C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B " };
  
  const char * const note_names_unpadded[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

  const char * const VOR_offsets[3] = { "-5V", "-3V", "0V"};

  const char * const trigger_input_names[4] = { "TR1", "TR2", "TR3", "TR4" };

  const char * const trigger_input_names_none[] = { " - ", "TR1", "TR2", "TR3", "TR4",
    "CV1", "CV2", "CV3", "CV4",
#ifdef ARDUINO_TEENSY41
    "CV5", "CV6", "CV7", "CV8",
#endif
    "A", "B", "C", "D",
#ifdef ARDUINO_TEENSY41
    "E", "F", "G", "H",
#endif
  };

  const char * const cv_input_names[4] = { "CV1", "CV2", "CV3", "CV4" };

  const char * const cv_input_names_none[] = { " - ", "CV1", "CV2", "CV3", "CV4",
#ifdef ARDUINO_TEENSY41
    "CV5", "CV6", "CV7", "CV8",
#endif
    "A", "B", "C", "D",
#ifdef ARDUINO_TEENSY41
    "E", "F", "G", "H",
#endif
  };

  const char * const channel_id[4] = { "#A", "#B", "#C", "#D" };

  const char * const capital_letters[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

  const char * const no_yes[] = { "No", "Yes" };

  const char * const off_on[] = { "off", "on" };

  const char * const scaling_string[] = {"scaling "};

  const char * const encoder_config_strings[] = { "normal", "R reversed", "L reversed", "LR reversed" };

  const char * const trigger_delay_times[kNumDelayTimes] = {
      "off", "120us", "240us", "360us", "480us", "1ms", "2ms", "4ms"
  };

  const char* const bytebeat_equation_names[] = {
    "hope", "love", "life", "age", "clysm", "monk", "NERV", "Trurl", "Pirx", "Snaut", "Hari" , "Kris", "Tichy", "Bregg", "Avon", "Orac"
  };

  const char* const envelope_shapes[11] = {
    "Lin", "Exp", "Quart", "Sine", "Ledge", "Cliff", "Gate", "BgDip", "MeDip", "LtDip", "Wiggl"
  };

  const char* const integer_sequence_names[] = {
    "pi", "vnEck", "ssdn", "Dress", "PNinf" , "Dsum", "Dsum4", "Dsum5", "CDn2", "Frcti" 
  };     

  const char* const integer_sequence_dirs[] = {
    "swing", "loop"
  };

  const char* const chord_property_names[] = {"Q", "V", "I", "B", "O"};

  const char* const mult[] = {
    "0.05", "0.10", "0.15", "0.20", "0.25", "0.30", "0.35", "0.40", "0.45", "0.50", 
    "0.55", "0.60", "0.65", "0.70", "0.75", "0.80", "0.85", "0.90", "0.95", "1.00", 
    "1.05", "1.10", "1.15", "1.20", "1.25", "1.30", "1.35", "1.40", "1.45", "1.50",
    "1.55", "1.60", "1.65", "1.70", "1.75", "1.80", "1.85", "1.90", "1.95", "2.00"
  };

  const char* const TM_aux_cv_destinations[] = {
  "-", "rng", "len", "prb"
  };

  const char* const reset_behaviours[] = {
  "None",  "SP", "SLP", "SL", "P", 
  };

  const char* const falling_gate_behaviours[] = {
  "Ignor",  "Honor", 
  };

  const uint8_t pi_digits[kIntSeqLen] =     
 {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,7,5,1,0,5,8,2,0,9,7,4,9,4,4,5,9,2,
  3,0,7,8,1,6,4,0,6,2,8,6,2,0,8,9,9,8,6,2,8,0,3,4,8,2,5,3,4,2,1,1,7,0,6,7,9,8,2,1,4,8,0,8,6,5,1,3,2,8,2,3,0,6,6,4,7,0,9,3,8,4,4,6} ;
//  0,9,5,5,0,5,8,2,2,3,1,7,2,5,3,5,9,4,0,8,1,2,8,4,8,1,1,1,7,4,5,0,2,8,4,1,0,2,7,0,1,9,3,8,5,2,1,1,0,5,5,5,9,6,4,4,6,2,2,9,4,8,9,5,
//  4,9,3,0,3,8,1,9,6,4,4,2,8,8,1,0,9,7,5,6,6,5,9,3,3,4,4,6,1,2,8,4,7,5,6,4,8,2,3,3,7,8,6,7,8,3,1,6,5,2,7,1,2,0,1,9,0,9,1,4,5,6,4};

//  const uint8_t phi_digits[256] =    {1,6,1,8,0,3,3,9,8,8,7,4,9,8,9,4,8,4,8,2,0,4,5,8,6,8,3,4,3,6,5,6,3,8,1,1,7,7,2,0,3,0,9,1,7,9,8,0,5,7,6,2,8,6,2,
//  1,3,5,4,4,8,6,2,2,7,0,5,2,6,0,4,6,2,8,1,8,9,0,2,4,4,9,7,0,7,2,0,7,2,0,4,1,8,9,3,9,1,1,3,7,4,8,4,7,5,4,0,8,8,0,7,5,3,8,6,8,9,1,7,5,2,1,2,
//  6,6,3,3,8,6,2,2,2,3,5,3,6,9,3,1,7,9,3,1,8,0,0,6,0,7,6,6,7,2,6,3,5,4,4,3,3,3,8,9,0,8,6,5,9,5,9,3,9,5,8,2,9,0,5,6,3,8,3,2,2,6,6,1,3,1,9,9,
//  2,8,2,9,0,2,6,7,8,8,0,6,7,5,2,0,8,7,6,6,8,9,2,5,0,1,7,1,1,6,9,6,2,0,7,0,3,2,2,2,1,0,4,3,2,1,6,2,6,9,5,4,8,6,2,6,2,9,6,3,1,3,6,1};
    
//  const uint8_t tau_digits[256] =    {6,2,8,3,1,8,5,3,0,7,1,7,9,5,8,6,4,7,6,9,2,5,2,8,6,7,6,6,5,5,9,0,0,5,7,6,8,3,9,4,3,3,8,7,9,8,7,5,0,2,1,1,6,4,1,
//  9,4,9,8,8,9,1,8,4,6,1,5,6,3,2,8,1,2,5,7,2,4,1,7,9,9,7,2,5,6,0,6,9,6,5,0,6,8,4,2,3,4,1,3,5,9,6,4,2,9,6,1,7,3,0,2,6,5,6,4,6,1,3,2,9,4,1,8,
//  7,6,8,9,2,1,9,1,0,1,1,6,4,4,6,3,4,5,0,7,1,8,8,1,6,2,5,6,9,6,2,2,3,4,9,0,0,5,6,8,2,0,5,4,0,3,8,7,7,0,4,2,2,1,1,1,1,9,2,8,9,2,4,5,8,9,7,9,
//  0,9,8,6,0,7,6,3,9,2,8,8,5,7,6,2,1,9,5,1,3,3,1,8,6,6,8,9,2,2,5,6,9,5,1,2,9,6,4,6,7,5,7,3,5,6,6,3,3,0,5,4,2,4,0,3,8,1,8,2,9,1,2,9};

//  const uint8_t eul_digits[256] =    {2,7,1,8,2,8,1,8,2,8,4,5,9,0,4,5,2,3,5,3,6,0,2,8,7,4,7,1,3,5,2,6,6,2,4,9,7,7,5,7,2,4,7,0,9,3,6,9,9,9,5,9,5,7,4,
//  9,6,6,9,6,7,6,2,7,7,2,4,0,7,6,6,3,0,3,5,3,5,4,7,5,9,4,5,7,1,3,8,2,1,7,8,5,2,5,1,6,6,4,2,7,4,2,7,4,6,6,3,9,1,9,3,2,0,0,3,0,5,9,9,2,1,8,1,
//  7,4,1,3,5,9,6,6,2,9,0,4,3,5,7,2,9,0,0,3,3,4,2,9,5,2,6,0,5,9,5,6,3,0,7,3,8,1,3,2,3,2,8,6,2,7,9,4,3,4,9,0,7,6,3,2,3,3,8,2,9,8,8,0,7,5,3,1,
//  9,5,2,5,1,0,1,9,0,1,1,5,7,3,8,3,4,1,8,7,9,3,0,7,0,2,1,5,4,0,8,9,1,4,9,9,3,4,8,8,4,1,6,7,5,0,9,2,4,4,7,6,1,4,6,0,6,6,8,0,8,2,2,6};
//
//  const uint8_t rt2_digits[256] =    {1,4,1,4,2,1,3,5,6,2,3,7,3,0,9,5,0,4,8,8,0,1,6,8,8,7,2,4,2,0,9,6,9,8,0,7,8,5,6,9,6,7,1,8,7,5,3,7,6,9,4,8,0,7,3,
//  1,7,6,6,7,9,7,3,7,9,9,0,7,3,2,4,7,8,4,6,2,1,0,7,0,3,8,8,5,0,3,8,7,5,3,4,3,2,7,6,4,1,5,7,2,7,3,5,0,1,3,8,4,6,2,3,0,9,1,2,2,9,7,0,2,4,9,2,
//  4,8,3,6,0,5,5,8,5,0,7,3,7,2,1,2,6,4,4,1,2,1,4,9,7,0,9,9,9,3,5,8,3,1,4,1,3,2,2,2,6,6,5,9,2,7,5,0,5,5,9,2,7,5,5,7,9,9,9,5,0,5,0,1,1,5,2,7,
//  8,2,0,6,0,5,7,1,4,7,0,1,0,9,5,5,9,9,7,1,6,0,5,9,7,0,2,7,4,5,3,4,5,9,6,8,6,2,0,1,4,7,2,8,5,1,7,4,1,8,6,4,0,8,8,9,1,9,8,6,0,9,5,5};

  // van Eck sequence - generated using Python code found at https://oeis.org/A181391
    const uint8_t van_eck[kIntSeqLen] =       {0,0,1,0,2,0,2,2,1,6,0,5,0,2,6,5,4,0,5,3,0,3,2,9,0,4,9,3,6,14,0,6,3,5,15,0,5,3,5,2,17,0,6,11,
                                                             0,3,8,0,3,3,1,42,0,5,15,20,0,4,32,0,3,11,18,0,4,7,0,3,7,3,2,31,0,6,31,3,6,3,2,8,33,0,9,56,0,
                                                             3,8,7,19,0,5,37,0,3,8,8,1,46,0,6,23,0,3,9,21,0,4,42,56,25,0,5,21,8,18,52,0,6,18,4,13,0,5,11,62,0,4,7};  
//  const uint8_t van_eck[256] =       {0,0,1,0,2,0,2,2,1,6,0,5,0,2,6,5,4,0,5,3,0,3,2,9,0,4,9,3,6,14,0,6,3,5,15,0,5,3,5,2,17,0,6,11,0,3,8,0,3,3,1,42,0,5,
//  15,20,0,4,32,0,3,11,18,0,4,7,0,3,7,3,2,31,0,6,31,3,6,3,2,8,33,0,9,56,0,3,8,7,19,0,5,37,0,3,8,8,1,46,0,6,23,0,3,9,21,0,4,42,56,25,0,5,21,8,18,52,0,6,18,
//  4,13,0,5,11,62,0,4,7,40,0,4,4,1,36,0,5,13,16,0,4,8,27,0,4,4,1,13,10,0,6,32,92,0,4,9,51,0,4,4,1,14,131,0,6,14,4,7,39,0,6,6,1,12,0,5,39,8,36,44,0,6,10,34,
//  0,4,19,97,0,4,4,1,19,6,12,21,82,0,9,43,0,3,98,0,3,3,1,15,152,0,6,17,170,0,4,24,0,3,12,24,4,6,11,98,21,29,0,10,45,0,3,13,84,0,4,14,70,0,4,4,1,34,58,0,6,
//  23,144,0,4,9,51,94,0,5,78,0,3} ;

    // Sum of squares of digits of n - see https://oeis.org/A003132
    const uint8_t sum_of_squares_of_digits_of_n[kIntSeqLen] =       {0,1,4,9,16,25,36,49,64,81,1,2,5,10,17,26,37,50,65,82,4,5,8,13,20,29,40,53,68,85,9,10,13,18,25,34,45,58,73,
                                                              90,16,17,20,25,32,41,52,65,80,97,25,26,29,34,41,50,61,74,89,106,36,37,40,45,52,61,72,85,100,117,49,50,53,58,
                                                              65,74,85,98,113,130,64,65,68,73,80,89,100,113,128,145,81,82,85,90,97,106,117,130,145,162,1,2,5,10,17,26,37,
                                                              50,65,82,2,3,6,11,18,27,38,51,66,83,5,6,9,14,21,30,41,54} ;
  
//  const uint8_t sum_of_squares_of_digits_of_n[256] =       {0,1,4,9,16,25,36,49,64,81,1,2,5,10,17,26,37,50,65,82,4,5,8,13,20,29,40,53,68,85,9,10,13,18,25,
//  34,45,58,73,90,16,17,20,25,32,41,52,65,80,97,25,26,29,34,41,50,61,74,89,106,36,37,40,45,52,61,72,85,100,117,49,50,53,58,65,74,85,98,113,130,64,65,68,73,
//  80,89,100,113,128,145,81,82,85,90,97,106,117,130,145,162,1,2,5,10,17,26,37,50,65,82,2,3,6,11,18,27,38,51,66,83,5,6,9,14,21,30,41,54,69,86,10,11,14,19,26,
//  35,46,59,74,91,17,18,21,26,33,42,53,66,81,98,26,27,30,35,42,51,62,75,90,107,37,38,41,46,53,62,73,86,101,118,50,51,54,59,66,75,86,99,114,131,65,66,69,74,
//  81,90,101,114,129,146,82,83,86,91,98,107,118,131,146,163,4,5,8,13,20,29,40,53,68,85,5,6,9,14,21,30,41,54,69,86,8,9,12,17,24,33,44,57,72,89,13,14,17,22,29,
//  38,49,62,77,94,20,21,24,29,36,45,56,69,84,101,29,30,33,38,45,54} ;

  //  Digital sum (i.e., sum of digits) of n; also called digsum(n). - see https://oeis.org/A007953
  const uint8_t digsum_of_n[kIntSeqLen] =       {0,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8,9,10,11,3,4,5,6,7,8,9,10,11,12,4,5,6,7,8,9,10,11,12,13,5,6,7,8,9,
                                          10,11,12,13,14,6,7,8,9,10,11,12,13,14,15,7,8,9,10,11,12,13,14,15,16,8,9,10,11,12,13,14,15,16,17,9,10,11,12,13,14,15,16,17,
                                          18,1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8,9,10,11,3,4,5,6,7,8,9,10};

//  //  Digital sum (i.e., sum of digits) of n; also called digsum(n). - see https://oeis.org/A007953
//  const uint8_t digsum_of_n[256] =       {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 3, 4,
// 5, 6, 7, 8, 9, 10, 11, 12, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 6, 7, 8, 9,
// 10, 11, 12, 13, 14, 15, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 9, 10, 11, 12, 13, 14, 
// 15, 16, 17, 18, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 3, 4, 5, 6, 7, 8, 9, 10,
// 11, 12, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
// 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 10, 11,
// 12, 13, 14, 15, 16, 17, 18, 19, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 4, 5, 6, 7,
// 8, 9, 10, 11, 12, 13, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 7, 8, 9, 10, 11, 12};

  // Sum of digits of n written in base 4 - see https://oeis.org/A053737
  const uint8_t digsum_of_n_base4[kIntSeqLen] = {0,1,2,3,1,2,3,4,2,3,4,5,3,4,5,6,1,2,3,4,2,3,4,5,3,4,5,6,4,5,6,7,2,3,4,5,3,4,5,6,4,5,6,7,
                                          5,6,7,8,3,4,5,6,4,5,6,7,5,6,7,8,6,7,8,9,1,2,3,4,2,3,4,5,3,4,5,6,4,5,6,7,2,3,4,5,3,4,5,6,
                                          4,5,6,7,5,6,7,8,3,4,5,6,4,5,6,7,5,6,7,8,6,7,8,9,4,5,6,7,5,6,7,8,6,7,8,9,7,8,9,10};

//  // Sum of digits of n written in base 4 - see https://oeis.org/A053737
//  const uint8_t digsum_of_n_base4[256] = {0 , 1 , 2 , 3 , 1 , 2 , 3 , 4 , 2 , 3 , 4 , 5 , 3 , 4 , 5 , 6 , 1 , 2 , 3 , 4 , 2 , 3 , 4 ,
//  5 , 3 , 4 , 5 , 6 , 4 , 5 , 6 , 7 , 2 , 3 , 4 , 5 , 3 , 4 , 5 , 6 , 4 , 5 , 6 , 7 , 5 , 6 ,
//  7 , 8 , 3 , 4 , 5 , 6 , 4 , 5 , 6 , 7 , 5 , 6 , 7 , 8 , 6 , 7 , 8 , 9 , 1 , 2 , 3 , 4 , 2 ,
//  3 , 4 , 5 , 3 , 4 , 5 , 6 , 4 , 5 , 6 , 7 , 2 , 3 , 4 , 5 , 3 , 4 , 5 , 6 , 4 , 5 , 6 , 7 ,
//  5 , 6 , 7 , 8 , 3 , 4 , 5 , 6 , 4 , 5 , 6 , 7 , 5 , 6 , 7 , 8 , 6 , 7 , 8 , 9 , 4 , 5 , 6 ,
//  7 , 5 , 6 , 7 , 8 , 6 , 7 , 8 , 9 , 7 , 8 , 9 , 10 , 2 , 3 , 4 , 5 , 3 , 4 , 5 , 6 , 4 , 5 ,
//  6 , 7 , 5 , 6 , 7 , 8 , 3 , 4 , 5 , 6 , 4 , 5 , 6 , 7 , 5 , 6 , 7 , 8 , 6 , 7 , 8 , 9 , 4 ,
//  5 , 6 , 7 , 5 , 6 , 7 , 8 , 6 , 7 , 8 , 9 , 7 , 8 , 9 , 10 , 5 , 6 , 7 , 8 , 6 , 7 , 8 , 9 ,
//  7 , 8 , 9 , 10 , 8 , 9 , 10 , 11 , 3 , 4 , 5 , 6 , 4 , 5 , 6 , 7 , 5 , 6 , 7 , 8 , 6 , 7 ,
//  8 , 9 , 4 , 5 , 6 , 7 , 5 , 6 , 7 , 8 , 6 , 7 , 8 , 9 , 7 , 8 , 9 , 10 , 5 , 6 , 7 , 8 , 6 ,
//  7 , 8 , 9 , 7 , 8 , 9 , 10 , 8 , 9 , 10 , 11 , 6 , 7 , 8 , 9 , 7 , 8 , 9 , 10 , 8 , 9 , 10 ,
//  11 , 9 , 10 , 11 , 12};

  // Sum of digits of n written in base 5 - see https://oeis.org/A053824
  const uint8_t digsum_of_n_base5[kIntSeqLen] = {0,1,2,3,4,1,2,3,4,5,2,3,4,5,6,3,4,5,6,7,4,5,6,7,8,1,2,3,4,5,2,3,4,5,6,3,4,5,6,7,4,5,6,7,8,5,6,
                                          7,8,9,2,3,4,5,6,3,4,5,6,7,4,5,6,7,8,5,6,7,8,9,6,7,8,9,10,3,4,5,6,7,4,5,6,7,8,5,6,7,8,9,6,7,8,9,
                                          10,7,8,9,10,11,4,5,6,7,8,5,6,7,8,9,6,7,8,9,10,7,8,9,10,11,8,9,10,11,12,1,2,3};

//  // Sum of digits of n written in base 5 - see https://oeis.org/A053824
//  const uint8_t digsum_of_n_base5[256] = {0 , 1 , 2 , 3 , 4 , 1 , 2 , 3 , 4 , 5 , 2 , 3 , 4 , 5 , 6 , 3 , 4 , 5 , 6 , 7 , 4 , 5 , 6 ,
//  7 , 8 , 1 , 2 , 3 , 4 , 5 , 2 , 3 , 4 , 5 , 6 , 3 , 4 , 5 , 6 , 7 , 4 , 5 , 6 , 7 , 8 , 5 ,
//  6 , 7 , 8 , 9 , 2 , 3 , 4 , 5 , 6 , 3 , 4 , 5 , 6 , 7 , 4 , 5 , 6 , 7 , 8 , 5 , 6 , 7 , 8 ,
//  9 , 6 , 7 , 8 , 9 , 10 , 3 , 4 , 5 , 6 , 7 , 4 , 5 , 6 , 7 , 8 , 5 , 6 , 7 , 8 , 9 , 6 , 7 ,
//  8 , 9 , 10 , 7 , 8 , 9 , 10 , 11 , 4 , 5 , 6 , 7 , 8 , 5 , 6 , 7 , 8 , 9 , 6 , 7 , 8 , 9 ,
//  10 , 7 , 8 , 9 , 10 , 11 , 8 , 9 , 10 , 11 , 12 , 1 , 2 , 3 , 4 , 5 , 2 , 3 , 4 , 5 , 6 , 3 ,
//  4 , 5 , 6 , 7 , 4 , 5 , 6 , 7 , 8 , 5 , 6 , 7 , 8 , 9 , 2 , 3 , 4 , 5 , 6 , 3 , 4 , 5 , 6 ,
//  7 , 4 , 5 , 6 , 7 , 8 , 5 , 6 , 7 , 8 , 9 , 6 , 7 , 8 , 9 , 10 , 3 , 4 , 5 , 6 , 7 , 4 , 5 ,
//  6 , 7 , 8 , 5 , 6 , 7 , 8 , 9 , 6 , 7 , 8 , 9 , 10 , 7 , 8 , 9 , 10 , 11 , 4 , 5 , 6 , 7 ,
//  8 , 5 , 6 , 7 , 8 , 9 , 6 , 7 , 8 , 9 , 10 , 7 , 8 , 9 , 10 , 11 , 8 , 9 , 10 , 11 , 12 ,
//  5 , 6 , 7 , 8 , 9 , 6 , 7 , 8 , 9 , 10 , 7 , 8 , 9 , 10 , 11 , 8 , 9 , 10 , 11 , 12 , 9 ,
//  10 , 11 , 12 , 13 , 2 , 3 , 4 , 5 , 6 , 3};

  // Fractal sequence: count down by 2's from successive integers - see https://oeis.org/A122196
  const uint8_t count_down_by_2[kIntSeqLen] = {1,2,3,1,4,2,5,3,1,6,4,2,7,5,3,1,8,6,4,2,9,7,5,3,1,10,8,6,4,2,11,9,7,5,3,1,12,10,8,6,4,2,13,11,9,
                                        7,5,3,1,14,12,10,8,6,4,2,15,13,11,9,7,5,3,1,16,14,12,10,8,6,4,2,17,15,13,11,9,7,5,3,1,18,16,14,12,
                                        10,8,6,4,2,19,17,15,13,11,9,7,5,3,1,20,18,16,14,12,10,8,6,4,2,21,19,17,15,13,11,9,7,5,3,1,22,20,18,16,14,12,10};

//  // Fractal sequence: count down by 2's from successive integers - see https://oeis.org/A122196
//  const uint8_t count_down_by_2[256] = {1 , 2 , 3 , 1 , 4 , 2 , 5 , 3 , 1 , 6 , 4 , 2 , 7 , 5 , 3 , 1 , 8 , 6 , 4 , 2 , 9 , 7 , 5 ,
//  3 , 1 , 10 , 8 , 6 , 4 , 2 , 11 , 9 , 7 , 5 , 3 , 1 , 12 , 10 , 8 , 6 , 4 , 2 , 13 , 11 ,
//  9 , 7 , 5 , 3 , 1 , 14 , 12 , 10 , 8 , 6 , 4 , 2 , 15 , 13 , 11 , 9 , 7 , 5 , 3 , 1 , 16 ,
//  14 , 12 , 10 , 8 , 6 , 4 , 2 , 17 , 15 , 13 , 11 , 9 , 7 , 5 , 3 , 1 , 18 , 16 , 14 , 12 ,
//  10 , 8 , 6 , 4 , 2 , 19 , 17 , 15 , 13 , 11 , 9 , 7 , 5 , 3 , 1 , 20 , 18 , 16 , 14 , 12 ,
//  10 , 8 , 6 , 4 , 2 , 21 , 19 , 17 , 15 , 13 , 11 , 9 , 7 , 5 , 3 , 1 , 22 , 20 , 18 , 16 ,
//  14 , 12 , 10 , 8 , 6 , 4 , 2 , 23 , 21 , 19 , 17 , 15 , 13 , 11 , 9 , 7 , 5 , 3 , 1 , 24 ,
//  22 , 20 , 18 , 16 , 14 , 12 , 10 , 8 , 6 , 4 , 2 , 25 , 23 , 21 , 19 , 17 , 15 , 13 , 11 ,
//  9 , 7 , 5 , 3 , 1 , 26 , 24 , 22 , 20 , 18 , 16 , 14 , 12 , 10 , 8 , 6 , 4 , 2 , 27 , 25 ,
//  23 , 21 , 19 , 17 , 15 , 13 , 11 , 9 , 7 , 5 , 3 , 1 , 28 , 26 , 24 , 22 , 20 , 18 , 16 ,
//  14 , 12 , 10 , 8 , 6 , 4 , 2 , 29 , 27 , 25 , 23 , 21 , 19 , 17 , 15 , 13 , 11 , 9 , 7 ,
//  5 , 3 , 1 , 30 , 28 , 26 , 24 , 22 , 20 , 18 , 16 , 14 , 12 , 10 , 8 , 6 , 4 , 2 , 31 , 29 ,
//  27 , 25 , 23 , 21 , 19 , 17 , 15 , 13 , 11 , 9 , 7 , 5 , 3 , 1};


  // Fractal sequence of the interspersion A163253 - see https://oeis.org/A163256
  const uint8_t interspersion_of_A163253[kIntSeqLen] = {1,2,3,1,2,4,3,5,1,2,4,6,3,5,7,1,2,4,6,8,3,5,7,9,1,2,4,6,8,10,3,5,7,9,11,1,2,4,6,8,10,12,3,5,7,
                                                 9,11,13,1,2,4,6,8,10,12,14,3,5,7,9,11,13,15,1,2,4,6,8,10,12,14,16,3,5,7,9,11,13,15,17,1,2,4,6,
                                                 8,10,12,14,16,18,3,5,7,9,11,13,15,17,19,1,2,4,6,8,10,12,14,16,18,20,3,5,7,9,11,13,15,17,19,21,1,2,4,6,8,10,12,14};

//  // Fractal sequence of the interspersion A163253 - see https://oeis.org/A163256
//  const uint8_t interspersion_of_A163253[256] = {1 , 2 , 3 , 1 , 2 , 4 , 3 , 5 , 1 , 2 , 4 , 6 , 3 , 5 , 7 , 1 , 2 , 4 , 6 , 8 , 3 , 5 , 7 ,
//  9 , 1 , 2 , 4 , 6 , 8 , 10 , 3 , 5 , 7 , 9 , 11 , 1 , 2 , 4 , 6 , 8 , 10 , 12 , 3 , 5 , 7 ,
//  9 , 11 , 13 , 1 , 2 , 4 , 6 , 8 , 10 , 12 , 14 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 1 , 2 , 4 ,
//  6 , 8 , 10 , 12 , 14 , 16 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 17 , 1 , 2 , 4 , 6 , 8 , 10 , 12 ,
//  14 , 16 , 18 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 17 , 19 , 1 , 2 , 4 , 6 , 8 , 10 , 12 , 14 ,
//  16 , 18 , 20 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 17 , 19 , 21 , 1 , 2 , 4 , 6 , 8 , 10 , 12 ,
//  14 , 16 , 18 , 20 , 22 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 17 , 19 , 21 , 23 , 1 , 2 , 4 , 6 ,
//  8 , 10 , 12 , 14 , 16 , 18 , 20 , 22 , 24 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 17 , 19 , 21 ,
//  23 , 25 , 1 , 2 , 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 , 22 , 24 , 26 , 3 , 5 , 7 , 9 ,
//  11 , 13 , 15 , 17 , 19 , 21 , 23 , 25 , 27 , 1 , 2 , 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 
//  20 , 22 , 24 , 26 , 28 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 17 , 19 , 21 , 23 , 25 , 27 , 29 ,
//  1 , 2 , 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 , 22 , 24 , 26 , 28 , 30 , 3 , 5 , 7 , 9 ,
//  11 , 13 , 15 , 17 , 19 , 21 , 23 , 25 , 27 , 29 , 31 , 1};
  
//  const uint8_t rt3_digits[256] =    {1,7,3,2,0,5,0,8,0,7,5,6,8,8,7,7,2,9,3,5,2,7,4,4,6,3,4,1,5,0,5,8,7,2,3,6,6,9,4,2,8,0,5,2,5,3,8,1,0,3,8,0,6,2,8,
//  0,5,5,8,0,6,9,7,9,4,5,1,9,3,3,0,1,6,9,0,8,8,0,0,0,3,7,0,8,1,1,4,6,1,8,6,7,5,7,2,4,8,5,7,5,6,7,5,6,2,6,1,4,1,4,1,5,4,0,6,7,0,3,0,2,9,9,6,
//  9,9,4,5,0,9,4,9,9,8,9,5,2,4,7,8,8,1,1,6,5,5,5,1,2,0,9,4,3,7,3,6,4,8,5,2,8,0,9,3,2,3,1,9,0,2,3,0,5,5,8,2,0,6,7,9,7,4,8,2,0,1,0,1,0,8,4,6,
//  7,4,9,2,3,2,6,5,0,1,5,3,1,2,3,4,3,2,6,6,9,0,3,3,2,2,8,8,6,6,5,0,6,7,2,2,5,4,6,6,8,9,2,1,8,3,7,9,7,1,2,2,7,0,4,7,1,3,1,6,6,0,3,6};

//  const uint8_t rt5_digits[256] =    {2,2,3,6,0,6,7,9,7,7,4,9,9,7,8,9,6,9,6,4,0,9,1,7,3,6,6,8,7,3,1,2,7,6,2,3,5,4,4,0,6,1,8,3,5,9,6,1,1,5,2,5,7,2,4,
//  2,7,0,8,9,7,2,4,5,4,1,0,5,2,0,9,2,5,6,3,7,8,0,4,8,9,9,4,1,4,4,1,4,4,0,8,3,7,8,7,8,2,2,7,4,9,6,9,5,0,8,1,7,6,1,5,0,7,7,3,7,8,3,5,0,4,2,5,
//  3,2,6,7,7,2,4,4,4,7,0,7,3,8,6,3,5,8,6,3,6,0,1,2,1,5,3,3,4,5,2,7,0,8,8,6,6,7,7,8,1,7,3,1,9,1,8,7,9,1,6,5,8,1,1,2,7,6,6,4,5,3,2,2,6,3,9,8,
//  5,6,5,8,0,5,3,5,7,6,1,3,5,0,4,1,7,5,3,3,7,8,5,0,0,3,4,2,3,3,9,2,4,1,4,0,6,4,4,4,2,0,8,6,4,3,2,5,3,9,0,9,7,2,5,2,5,9,2,6,2,7,2,2};

//  The following are redundant - now calculate the Dress sequence on the fly using bit-counting (bit population counts)
//  const uint8_t dress_digits[256] =  {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,
//  5,3,4,4,5,4,5,5,6,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,
//  6,5,6,6,7,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,
//  7,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7};
//    
//  const uint8_t dress31_digits[256] ={0,4,5,4,6,4,5,4,7,4,5,4,6,4,5,4,8,4,5,4,6,4,5,4,7,4,5,4,6,4,5,4,9,9,5,5,6,6,5,5,7,7,5,5,6,6,5,5,8,8,5,5,6,6,5,
//  5,7,7,5,5,6,6,5,5,10,9,10,4,6,5,6,4,7,6,7,4,6,5,6,4,8,7,8,4,6,5,6,4,7,6,7,4,6,5,6,4,9,9,9,9,6,6,6,6,7,7,7,7,6,6,6,6,8,8,8,8,6,6,6,6,7,7,
//  7,7,6,6,6,6,11,9,10,9,11,4,5,4,7,5,6,5,7,4,5,4,8,6,7,6,8,4,5,4,7,5,6,5,7,4,5,4,9,9,8,8,9,9,5,5,7,7,6,6,7,7,5,5,8,8,7,7,8,8,5,5,7,7,6,6,7,7,
//  5,5,10,9,10,8,10,9,10,4,7,6,7,5,7,6,7,4,8,7,8,6,8,7,8,4,7,6,7,5,7,6,7,4,9,9,9,9,9,9,9,9,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7};
//
//  const uint8_t dress63_digits[256] ={0,5,6,5,7,5,6,5,8,5,6,5,7,5,6,5,9,5,6,5,7,5,6,5,8,5,6,5,7,5,6,5,10,5,6,5,7,5,6,5,8,5,6,5,7,5,6,5,9,5,6,5,7,5,6,
//  5,8,5,6,5,7,5,6,5,11,11,6,6,7,7,6,6,8,8,6,6,7,7,6,6,9,9,6,6,7,7,6,6,8,8,6,6,7,7,6,6,10,10,6,6,7,7,6,6,8,8,6,6,7,7,6,6,9,9,6,6,7,7,6,6,8,
//  8,6,6,7,7,6,6,12,11,12,5,7,6,7,5,8,7,8,5,7,6,7,5,9,8,9,5,7,6,7,5,8,7,8,5,7,6,7,5,10,9,10,5,7,6,7,5,8,7,8,5,7,6,7,5,9,8,9,5,7,6,7,5,8,7,8,
//  5,7,6,7,5,11,11,11,11,7,7,7,7,8,8,8,8,7,7,7,7,9,9,9,9,7,7,7,7,8,8,8,8,7,7,7,7,10,10,10,10,7,7,7,7,8,8,8,8,7,7,7,7,9,9,9,9,7,7,7,7,8,8,8,8,7,7,7,7} ;

  
 }; // Strings

  // \sa OC_config.h -> kMaxTriggerDelayTicks
  const uint8_t trigger_delay_ticks[kNumDelayTimes] = {
    0, 2, 4, 6, 8, 16, 33, 66
  };

 
};
