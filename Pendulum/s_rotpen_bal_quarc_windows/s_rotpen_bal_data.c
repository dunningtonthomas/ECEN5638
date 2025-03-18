/*
 * s_rotpen_bal_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "s_rotpen_bal".
 *
 * Model version              : 12.0
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Mar 18 13:34:41 2025
 *
 * Target selection: quarc_windows.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "s_rotpen_bal.h"

/* Block parameters (default storage) */
P_s_rotpen_bal_T s_rotpen_bal_P = {
  /* Variable: A
   * Referenced by: '<Root>/Inverted Pendulum  Model'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 81.40328231616877, 122.054532693699, 1.0, 0.0,
    -45.82587472493573, -44.096596433448148, 0.0, 1.0, -0.93188180211109284,
    -1.3972458437347086 },

  /* Variable: B
   * Referenced by: '<Root>/Inverted Pendulum  Model'
   */
  { 0.0, 0.0, 83.46590309589412, 80.316246375330678 },

  /* Variable: C
   * Referenced by: '<Root>/Inverted Pendulum  Model'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: K
   * Referenced by: '<Root>/Control  Gain'
   */
  { -5.2611594041654932, 16.479740507381965, 0.92523949003984862,
    -0.74765782634078481 },

  /* Expression: 0
   * Referenced by: '<Root>/Inverted Pendulum  Model'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

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

  /* Expression: 180/pi
   * Referenced by: '<S5>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: HPFtheta_dotrads_A
   * Referenced by: '<S2>/HPF: theta_dot (rad//s)'
   */
  -62.831853071795862,

  /* Computed Parameter: HPFtheta_dotrads_C
   * Referenced by: '<S2>/HPF: theta_dot (rad//s)'
   */
  -3947.8417604357433,

  /* Computed Parameter: HPFtheta_dotrads_D
   * Referenced by: '<S2>/HPF: theta_dot (rad//s)'
   */
  62.831853071795862,

  /* Computed Parameter: HPFalpha_dotrads_A
   * Referenced by: '<S2>/HPF: alpha_dot (rad//s)'
   */
  -62.831853071795862,

  /* Computed Parameter: HPFalpha_dotrads_C
   * Referenced by: '<S2>/HPF: alpha_dot (rad//s)'
   */
  -3947.8417604357433,

  /* Computed Parameter: HPFalpha_dotrads_D
   * Referenced by: '<S2>/HPF: alpha_dot (rad//s)'
   */
  62.831853071795862
};
