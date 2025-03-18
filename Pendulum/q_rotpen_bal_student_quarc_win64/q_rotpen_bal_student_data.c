/*
 * q_rotpen_bal_student_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_rotpen_bal_student".
 *
 * Model version              : 12.5
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Mar 18 13:57:03 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_rotpen_bal_student.h"

/* Block parameters (default storage) */
P_q_rotpen_bal_student_T q_rotpen_bal_student_P = {
  /* Variable: K
   * Referenced by: '<Root>/Control  Gain'
   */
  { -5.2611594041654977, 28.156796760065014, -2.7575720928759342,
    3.2190264882033341 },

  /* Variable: K_AMP
   * Referenced by: '<S4>/Inverse Amplifier  Gain (V//V)'
   */
  1.0,

  /* Variable: K_ENC
   * Referenced by: '<S4>/Encoder Calibration  (rad//count)'
   */
  0.0015339807878856412,

  /* Variable: epsilon
   * Referenced by: '<S2>/Constant'
   */
  0.20943951023931953,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S4>/HIL Write Analog'
   */
  0U,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S4>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S4>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S4>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S4>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S4>/HIL Initialize'
   */
  50.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S4>/HIL Initialize'
   */
  0.0,

  /* Expression: 2*pi
   * Referenced by: '<S6>/Mod Angle  (rad)'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S6>/Offset Angle  (rad)'
   */
  -3.1415926535897931,

  /* Expression: 1
   * Referenced by: '<Root>/Signal Generator'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Signal Generator'
   */
  0.1,

  /* Expression: 20
   * Referenced by: '<Root>/Amplitude (deg)'
   */
  20.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.017453292519943295,

  /* Expression: [1,0,0,0]
   * Referenced by: '<Root>/Convert to  Vector State'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: HPFtheta_dotrads_A
   * Referenced by: '<S3>/HPF: theta_dot (rad//s)'
   */
  -62.831853071795862,

  /* Computed Parameter: HPFtheta_dotrads_C
   * Referenced by: '<S3>/HPF: theta_dot (rad//s)'
   */
  -3947.8417604357433,

  /* Computed Parameter: HPFtheta_dotrads_D
   * Referenced by: '<S3>/HPF: theta_dot (rad//s)'
   */
  62.831853071795862,

  /* Computed Parameter: HPFalpha_dotrads_A
   * Referenced by: '<S3>/HPF: alpha_dot (rad//s)'
   */
  -62.831853071795862,

  /* Computed Parameter: HPFalpha_dotrads_C
   * Referenced by: '<S3>/HPF: alpha_dot (rad//s)'
   */
  -3947.8417604357433,

  /* Computed Parameter: HPFalpha_dotrads_D
   * Referenced by: '<S3>/HPF: alpha_dot (rad//s)'
   */
  62.831853071795862,

  /* Expression: 0
   * Referenced by: '<Root>/u = 0V'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S4>/Direction Convention: (Right-Hand) system'
   */
  -1.0,

  /* Expression: 5
   * Referenced by: '<S4>/Amplifier  Saturation (V)'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S4>/Amplifier  Saturation (V)'
   */
  -5.0,

  /* Expression: 180/pi
   * Referenced by: '<S7>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S8>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S4>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S4>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S4>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S4>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S4>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S4>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S4>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S4>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  { 0U, 1U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S4>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S4>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S4>/HIL Write Analog'
   */
  false,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  1U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<Root>/Switch'
   */
  0U
};
