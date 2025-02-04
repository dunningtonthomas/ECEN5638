/*
 * SRV02_systemID_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SRV02_systemID".
 *
 * Model version              : 9.4
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Feb  4 14:30:47 2025
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
  15.0,

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
  { 5.5782369912323349, 0.6555595846458625, 5.8867329958429133,
    2.3467846461664328, 1.014828015539003, 0.0929582668477915,
    2.3018350724189767, 2.7013752868637217, 2.6801325425326343,
    0.10758439300236856, 1.9323265146367752, 1.6981986607687332,
    5.4489294655574438, 4.5116879762233433, 1.4448111098896226,
    1.9723234584464113, 6.1512697896478379, 5.9159183995174836,
    4.8570722634118937, 5.2222122000912092, 0.35030546303252841,
    0.89396205084658109, 3.1685325769050574, 4.2366934725067775,
    1.1048898812715118, 2.4514537240301504, 5.770922751903262,
    6.0464264805734071, 4.7756909150979956, 0.45866063267542628,
    2.6578588851835327, 1.117942345426252, 1.6337928709658602,
    2.6183327728182348, 1.4614942128123047, 1.0748503613232936,
    2.7310910326332536, 1.4139243613632939, 5.9527153057452713, 2.37201240473037,
    2.2576709878801271, 6.2276533420479687, 2.0477503246552811,
    5.6066588298071736, 2.3245094885273017, 0.015126528221414871,
    4.7810865778659233, 2.6808120794009263, 0.81799728832075735,
    5.3532421150666041, 2.9564711896260931, 0.081616306935321264,
    5.89989225924768, 2.371057479063583, 5.4492814089453292, 5.4843863721168358,
    0.13612477198113471, 5.490967288333275, 5.4682981169393887,
    0.67351018832474718, 6.0270681653871119, 2.605507809022054,
    5.7626666753911762, 3.3664370073035963, 1.5615925759131279, 4.91279533195322,
    3.7754601919581074, 1.2794810783302439, 2.3642981332362618,
    0.41071284031461591, 6.2045311562035605, 3.2442037543661142,
    5.9423747656590953, 1.3632989068386552, 4.3149241356696741,
    2.9309613452492012, 1.6074642843161322, 5.2579811195134338,
    1.8303567965029424, 0.7292454320402102, 2.4035011074904054,
    1.3367800340438689, 3.1954073307108404, 3.26756190722057, 5.77435035490012,
    5.9387882593542027, 5.9708508600098984, 3.119260696304583,
    3.6219086951811987, 6.22108450866588, 3.5748395709745036, 3.8580048163709084,
    0.94256514955392523, 1.9293687496695187, 4.5626040010407474,
    3.5444157280482473, 0.9156699262017991, 3.4655898718112064,
    3.9284366650883911, 4.294611063189703 },

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
    93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0 }
};
