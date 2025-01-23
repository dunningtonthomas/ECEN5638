/*
 * SRV02_systemID_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SRV02_systemID".
 *
 * Model version              : 9.0
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 23 15:19:34 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SRV02_systemID.h"

/* Block parameters (default storage) */
P_SRV02_systemID_T SRV02_systemID_P = {
  /* Variable: T
   * Referenced by: '<Root>/Sine Wave'
   */
  7.0,

  /* Mask Parameter: HILWrite_analog_channels
   * Referenced by: '<S1>/HIL Write'
   */
  0U,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<S1>/HIL Read Encoder'
   */
  0U,

  /* Mask Parameter: HILReadAnalog_channels
   * Referenced by: '<S1>/HIL Read Analog'
   */
  0U,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S1>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S1>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S1>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S1>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S1>/HIL Initialize'
   */
  50.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: -2*pi/2^12
   * Referenced by: '<S1>/Servo:  Counts to Rad'
   */
  -0.0015339807878856412,

  /* Expression: 1/3
   * Referenced by: '<Root>/Sine Wave'
   */
  0.33333333333333331,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: rand(1,N)*2*pi
   * Referenced by: '<Root>/Sine Wave'
   */
  { 2.3908544263967157, 1.8986137594728583, 1.8505577069809132,
    1.6324567773258336, 2.9120994070831068, 6.2068588939558662,
    2.4195031036195491, 5.9265153069379846, 1.0492994762221879,
    5.8119719136719885, 4.7396414646309051, 5.3821729949042121,
    3.7849061110164732, 0.67460563576613175, 2.8618165943634226,
    4.1129084511676446, 0.36149125917273439, 0.13359859538869528,
    1.8208780357892949, 5.8526541066040139, 3.2296788743771447,
    5.499662237086973, 2.3756692963483035, 5.5575497836234913, 3.36008332357846,
    5.6083883915937314, 0.645681652579863, 1.3323232611865941, 4.408318873938085,
    2.2704342231859731, 0.008769534146607, 2.4146805143952461, 2.011517243346951,
    2.4714619285490769, 1.1388350229978699, 1.3155527373697318,
    3.7304818903293926, 3.7351422716028013, 1.083662738070666, 5.86222173514193,
    0.3532203784651306, 1.2674701635022507, 3.193441907004066,
    4.7702876507470178, 0.91767235726437724, 5.8501041067285291,
    2.6511778850667551, 0.35499203664544349, 4.2361262914463707,
    1.7580901154297062, 4.9014314485308876, 6.0497097817542711, 4.32436984539912,
    3.1316813070436957, 0.62223929792335, 1.8079944092363021, 3.3810591889054238,
    0.071188812383591649, 1.7771580265141844, 3.70438567110914,
    1.0810101686606886, 1.0687582931746258, 4.2495871047028491,
    3.5788673593241009, 3.4662479874648393, 6.0786109797548864,
    3.9484912617522592, 2.0392060165410384, 3.2736381336691376, 5.43455741483401,
    6.2461662545570906, 5.2683769278646206, 2.182760655649024, 4.708681145732843,
    5.9025049080344987, 4.1976819930824005, 3.0234858436224692,
    1.7980156408728247, 3.7394742132234118, 2.1137084294746185,
    6.0290340269608782, 2.7776392811360076, 6.0444004425812672,
    4.249843625488384, 4.4364178896413637, 6.0173610354107812,
    5.9054209662114419, 5.2386530928686312, 0.975409986034215,
    5.2177592386422562, 2.9162796577504664, 1.8767147402109763,
    3.2880242961673605, 5.2252881310997825, 3.3874684777973134,
    1.6325717230217303, 2.2244890372850823, 1.1733103128655171,
    2.2032412396147203, 1.1920367124518345, 5.2508010243874272,
    2.4136916399560109, 0.059688516088734531, 1.9416594245742043,
    5.2574379277662429, 1.7676913810970361, 4.9093248184466516,
    3.3396025214061189, 0.9670734236890437, 3.3002662308532664,
    1.7796480727723227, 4.4916362672832, 4.614303964761505, 2.8251453227192562,
    1.1440262579788643, 0.851625615733262, 1.7138745951985983,
    3.9938659446087494, 5.0654280838742629, 4.1963969808543142,
    1.8006927195068034, 0.89498673420882657, 1.5448796656377575,
    4.3473171493751126, 0.45079871296490148, 3.1331786839147879,
    6.1952067474411558, 5.685658441917206, 3.6141365535883216,
    4.8161700734975943, 4.6920782601219919, 4.36889607992082, 4.25570979752959,
    1.7743704484781575, 3.6559843440931079, 3.8884892851215866,
    5.116020281990437, 0.10044966326025843, 1.3468171308416756,
    6.2069536726927552, 5.1354814239874225, 3.971486517815328,
    4.2860588136420139, 5.0781760667024463, 1.7571690376097697,
    4.1781251338548513, 0.18424883184911894, 3.4204413866896077,
    3.3236180762655367, 5.4862529632538806, 1.1787777380677769,
    5.8525393973188562, 6.13460227469419, 2.0810187930750006, 3.9188806958693747,
    3.3116201625084485, 2.8844942708602583, 2.2529342711151576,
    2.1002775343275086, 0.52273117172275774, 2.452967283404063,
    1.5038423645229388, 3.0553370178118153, 4.398817850093911,
    0.86249493008996825, 5.1928474395063882, 5.8436967238500888,
    5.2070673444895137, 3.0470480735771761, 4.1454525453973208,
    2.8676525720598196, 2.6292746304648604, 0.21548976948935081,
    5.8235548850709851, 0.27256492848157665, 2.9911738211088141,
    2.4237244991571996, 3.3555874789149907, 6.2716762162286708,
    5.6704125600336788, 0.092711530445599669, 4.9041199326043809,
    3.04916354457916, 2.4518230912187611, 5.1716276533513508, 5.494127468332751,
    6.2728559165942048, 1.2293717398056974, 5.4661759244705879,
    1.9320268202796276, 2.5838748415968973, 5.1292167411349556,
    2.3138128183589513, 2.6779904983922731, 0.57313212254763657,
    4.1940147649979069, 4.5949446929921152, 1.8900978121232139,
    2.1236990995197869, 4.6138834618713167 },

  /* Expression: 10
   * Referenced by: '<S1>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation'
   */
  -10.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S1>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<S1>/HIL Read Encoder'
   */
  true,

  /* Computed Parameter: HILReadAnalog_Active
   * Referenced by: '<S1>/HIL Read Analog'
   */
  true,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S1>/HIL Write'
   */
  false
};

/* Constant parameters (default storage) */
const ConstP_SRV02_systemID_T SRV02_systemID_ConstP = {
  /* Expression: (1:N)*2*pi/T
   * Referenced by: '<Root>/Sine Wave'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0,
    15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
    28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0,
    41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0,
    54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0,
    67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,
    80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0,
    93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 104.0,
    105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0, 113.0, 114.0, 115.0,
    116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0, 123.0, 124.0, 125.0, 126.0,
    127.0, 128.0, 129.0, 130.0, 131.0, 132.0, 133.0, 134.0, 135.0, 136.0, 137.0,
    138.0, 139.0, 140.0, 141.0, 142.0, 143.0, 144.0, 145.0, 146.0, 147.0, 148.0,
    149.0, 150.0, 151.0, 152.0, 153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0,
    160.0, 161.0, 162.0, 163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0,
    171.0, 172.0, 173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0,
    182.0, 183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
    193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0 }
};
