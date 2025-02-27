/*
 * s_torsion_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "s_torsion".
 *
 * Model version              : 27.0
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Feb 27 13:55:22 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "s_torsion.h"

/* Block parameters (default storage) */
P_s_torsion_T s_torsion_P = {
  /* Variable: A
   * Referenced by: '<Root>/State-Space'
   */
  { 0.0, 0.0, -288.99082568807341, 1155.9633027522937, 0.0, 0.0,
    288.99082568807341, -1155.9633027522937, 1.0, 0.0, -35.107911617039882, 0.0,
    0.0, 1.0, 0.0, -1.5137614678899083 },

  /* Variable: B
   * Referenced by: '<Root>/State-Space'
   */
  { 0.0, 0.0, 58.923552246259973, 0.0 },

  /* Variable: C
   * Referenced by: '<Root>/State-Space'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: K
   * Referenced by: '<Root>/Control Gain'
   */
  { 112.74597468285528, -57.973718932338656, 2.4343368938638235,
    1.4215241139816177 },

  /* Expression: [1 1 1 1]
   * Referenced by: '<Root>/Full-State Feedback'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Expression: [1 0 1 0]
   * Referenced by: '<Root>/Partial-State Feedback'
   */
  { 1.0, 0.0, 1.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S2>/Signal Generator'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S2>/Signal Generator'
   */
  0.5,

  /* Expression: 10
   * Referenced by: '<S2>/Amplitude (deg)'
   */
  10.0,

  /* Expression: 5*180
   * Referenced by: '<S2>/Rate Limiter'
   */
  900.0,

  /* Expression: -5*180
   * Referenced by: '<S2>/Rate Limiter'
   */
  -900.0,

  /* Expression: pi/180
   * Referenced by: '<S6>/Gain1'
   */
  0.017453292519943295,

  /* Expression: [1,1,0,0]
   * Referenced by: '<S2>/Convert to  Vector State'
   */
  { 1.0, 1.0, 0.0, 0.0 },

  /* Expression: 180/pi
   * Referenced by: '<S5>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<Root>/State-Space'
   */
  0.0,

  /* Expression: numz
   * Referenced by: '<S7>/Discrete Transfer Fcn'
   */
  { 59.306014133243821, 0.0, -59.306014133243821 },

  /* Expression: denz
   * Referenced by: '<S7>/Discrete Transfer Fcn'
   */
  { 1.0, -1.0831790815514077, 0.32040313808438325 },

  /* Expression: 0
   * Referenced by: '<S7>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: numz
   * Referenced by: '<S8>/Discrete Transfer Fcn'
   */
  { 59.306014133243821, 0.0, -59.306014133243821 },

  /* Expression: denz
   * Referenced by: '<S8>/Discrete Transfer Fcn'
   */
  { 1.0, -1.0831790815514077, 0.32040313808438325 },

  /* Expression: 0
   * Referenced by: '<S8>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: 10
   * Referenced by: '<Root>/Saturation (V)'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<Root>/Saturation (V)'
   */
  -10.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};
