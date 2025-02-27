/*
 * s_torsion.c
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
#include <math.h>
#include <emmintrin.h>
#include "rtwtypes.h"
#include "s_torsion_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "s_torsion_dt.h"

/* Block signals (default storage) */
B_s_torsion_T s_torsion_B;

/* Continuous states */
X_s_torsion_T s_torsion_X;

/* Disabled State Vector */
XDis_s_torsion_T s_torsion_XDis;

/* Block states (default storage) */
DW_s_torsion_T s_torsion_DW;

/* Real-time model */
static RT_MODEL_s_torsion_T s_torsion_M_;
RT_MODEL_s_torsion_T *const s_torsion_M = &s_torsion_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  s_torsion_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void s_torsion_output(void)
{
  __m128d tmp;
  real_T Amplitudedeg;
  real_T StateSpace_CSTATE;
  real_T StateSpace_CSTATE_0;
  real_T StateSpace_CSTATE_1;
  real_T deltaT_tmp;
  real_T rtb_Sum_idx_0;
  real_T rtb_Sum_idx_1;
  real_T rtb_Sum_idx_2;
  int_T iy;
  boolean_T limitedCache;
  if (rtmIsMajorTimeStep(s_torsion_M)) {
    /* set solver stop time */
    if (!(s_torsion_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&s_torsion_M->solverInfo,
                            ((s_torsion_M->Timing.clockTickH0 + 1) *
        s_torsion_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&s_torsion_M->solverInfo,
                            ((s_torsion_M->Timing.clockTick0 + 1) *
        s_torsion_M->Timing.stepSize0 + s_torsion_M->Timing.clockTickH0 *
        s_torsion_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(s_torsion_M)) {
    s_torsion_M->Timing.t[0] = rtsiGetT(&s_torsion_M->solverInfo);
  }

  /* SignalGenerator: '<S2>/Signal Generator' */
  Amplitudedeg = s_torsion_P.SignalGenerator_Frequency * s_torsion_M->Timing.t[0];
  if (Amplitudedeg - floor(Amplitudedeg) >= 0.5) {
    deltaT_tmp = s_torsion_P.SignalGenerator_Amplitude;
  } else {
    deltaT_tmp = -s_torsion_P.SignalGenerator_Amplitude;
  }

  /* Gain: '<S2>/Amplitude (deg)' incorporates:
   *  SignalGenerator: '<S2>/Signal Generator'
   */
  Amplitudedeg = s_torsion_P.Amplitudedeg_Gain * deltaT_tmp;

  /* RateLimiter: '<S2>/Rate Limiter' */
  if (s_torsion_DW.LastMajorTime == (rtInf)) {
    /* RateLimiter: '<S2>/Rate Limiter' */
    s_torsion_B.RateLimiter = Amplitudedeg;
  } else {
    deltaT_tmp = s_torsion_M->Timing.t[0];
    rtb_Sum_idx_0 = deltaT_tmp - s_torsion_DW.LastMajorTime;
    if (s_torsion_DW.LastMajorTime == deltaT_tmp) {
      if (s_torsion_DW.PrevLimited) {
        /* RateLimiter: '<S2>/Rate Limiter' */
        s_torsion_B.RateLimiter = s_torsion_DW.PrevY;
      } else {
        /* RateLimiter: '<S2>/Rate Limiter' */
        s_torsion_B.RateLimiter = Amplitudedeg;
      }
    } else {
      rtb_Sum_idx_1 = rtb_Sum_idx_0 * s_torsion_P.RateLimiter_RisingLim;
      deltaT_tmp = Amplitudedeg - s_torsion_DW.PrevY;
      if (deltaT_tmp > rtb_Sum_idx_1) {
        /* RateLimiter: '<S2>/Rate Limiter' */
        s_torsion_B.RateLimiter = s_torsion_DW.PrevY + rtb_Sum_idx_1;
        limitedCache = true;
      } else {
        rtb_Sum_idx_0 *= s_torsion_P.RateLimiter_FallingLim;
        if (deltaT_tmp < rtb_Sum_idx_0) {
          /* RateLimiter: '<S2>/Rate Limiter' */
          s_torsion_B.RateLimiter = s_torsion_DW.PrevY + rtb_Sum_idx_0;
          limitedCache = true;
        } else {
          /* RateLimiter: '<S2>/Rate Limiter' */
          s_torsion_B.RateLimiter = Amplitudedeg;
          limitedCache = false;
        }
      }

      if (rtsiIsModeUpdateTimeStep(&s_torsion_M->solverInfo)) {
        s_torsion_DW.PrevLimited = limitedCache;
      }
    }
  }

  /* End of RateLimiter: '<S2>/Rate Limiter' */

  /* Gain: '<S6>/Gain1' */
  Amplitudedeg = s_torsion_P.Gain1_Gain * s_torsion_B.RateLimiter;

  /* Gain: '<S2>/Convert to  Vector State' */
  deltaT_tmp = s_torsion_P.ConverttoVectorState_Gain[0] * Amplitudedeg;
  rtb_Sum_idx_0 = deltaT_tmp;

  /* Gain: '<S5>/Gain' */
  s_torsion_B.Gain[0] = s_torsion_P.Gain_Gain * deltaT_tmp;

  /* Gain: '<S2>/Convert to  Vector State' */
  deltaT_tmp = s_torsion_P.ConverttoVectorState_Gain[1] * Amplitudedeg;
  rtb_Sum_idx_1 = deltaT_tmp;

  /* Gain: '<S5>/Gain' */
  s_torsion_B.Gain[1] = s_torsion_P.Gain_Gain * deltaT_tmp;

  /* Gain: '<S2>/Convert to  Vector State' */
  deltaT_tmp = s_torsion_P.ConverttoVectorState_Gain[2] * Amplitudedeg;
  rtb_Sum_idx_2 = deltaT_tmp;

  /* Gain: '<S5>/Gain' */
  s_torsion_B.Gain[2] = s_torsion_P.Gain_Gain * deltaT_tmp;

  /* Gain: '<S2>/Convert to  Vector State' */
  deltaT_tmp = s_torsion_P.ConverttoVectorState_Gain[3] * Amplitudedeg;

  /* Gain: '<S5>/Gain' */
  s_torsion_B.Gain[3] = s_torsion_P.Gain_Gain * deltaT_tmp;

  /* StateSpace: '<Root>/State-Space' */
  Amplitudedeg = s_torsion_X.StateSpace_CSTATE[1];
  StateSpace_CSTATE = s_torsion_X.StateSpace_CSTATE[0];
  StateSpace_CSTATE_0 = s_torsion_X.StateSpace_CSTATE[2];
  StateSpace_CSTATE_1 = s_torsion_X.StateSpace_CSTATE[3];
  for (iy = 0; iy <= 0; iy += 2) {
    /* StateSpace: '<Root>/State-Space' */
    _mm_storeu_pd(&s_torsion_B.StateSpace[iy], _mm_add_pd(_mm_add_pd(_mm_add_pd
      (_mm_mul_pd(_mm_loadu_pd(&s_torsion_P.C[iy + 2]), _mm_set1_pd(Amplitudedeg)),
       _mm_mul_pd(_mm_loadu_pd(&s_torsion_P.C[iy]), _mm_set1_pd
                  (StateSpace_CSTATE))), _mm_mul_pd(_mm_loadu_pd
      (&s_torsion_P.C[iy + 4]), _mm_set1_pd(StateSpace_CSTATE_0))), _mm_mul_pd
      (_mm_loadu_pd(&s_torsion_P.C[iy + 6]), _mm_set1_pd(StateSpace_CSTATE_1))));
  }

  /* End of StateSpace: '<Root>/State-Space' */
  if (rtmIsMajorTimeStep(s_torsion_M)) {
    /* DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
    s_torsion_DW.DiscreteTransferFcn_tmp = ((s_torsion_B.StateSpace[0] -
      s_torsion_DW.DiscreteTransferFcn_states[0] *
      s_torsion_P.DiscreteTransferFcn_DenCoef[1]) -
      s_torsion_DW.DiscreteTransferFcn_states[1] *
      s_torsion_P.DiscreteTransferFcn_DenCoef[2]) /
      s_torsion_P.DiscreteTransferFcn_DenCoef[0];

    /* DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
    s_torsion_B.DiscreteTransferFcn = (s_torsion_P.DiscreteTransferFcn_NumCoef[0]
      * s_torsion_DW.DiscreteTransferFcn_tmp +
      s_torsion_DW.DiscreteTransferFcn_states[0] *
      s_torsion_P.DiscreteTransferFcn_NumCoef[1]) +
      s_torsion_DW.DiscreteTransferFcn_states[1] *
      s_torsion_P.DiscreteTransferFcn_NumCoef[2];

    /* DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
    s_torsion_DW.DiscreteTransferFcn_tmp_k = ((s_torsion_B.StateSpace[1] -
      s_torsion_DW.DiscreteTransferFcn_states_k[0] *
      s_torsion_P.DiscreteTransferFcn_DenCoef_c[1]) -
      s_torsion_DW.DiscreteTransferFcn_states_k[1] *
      s_torsion_P.DiscreteTransferFcn_DenCoef_c[2]) /
      s_torsion_P.DiscreteTransferFcn_DenCoef_c[0];

    /* DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
    s_torsion_B.DiscreteTransferFcn_n =
      (s_torsion_P.DiscreteTransferFcn_NumCoef_l[0] *
       s_torsion_DW.DiscreteTransferFcn_tmp_k +
       s_torsion_DW.DiscreteTransferFcn_states_k[0] *
       s_torsion_P.DiscreteTransferFcn_NumCoef_l[1]) +
      s_torsion_DW.DiscreteTransferFcn_states_k[1] *
      s_torsion_P.DiscreteTransferFcn_NumCoef_l[2];
  }

  /* Gain: '<S4>/Gain' */
  tmp = _mm_mul_pd(_mm_set1_pd(s_torsion_P.Gain_Gain_i), _mm_loadu_pd
                   (&s_torsion_B.StateSpace[0]));

  /* Gain: '<S4>/Gain' */
  _mm_storeu_pd(&s_torsion_B.Gain_o[0], tmp);
  s_torsion_B.Gain_o[2] = s_torsion_P.Gain_Gain_i *
    s_torsion_B.DiscreteTransferFcn;
  s_torsion_B.Gain_o[3] = s_torsion_P.Gain_Gain_i *
    s_torsion_B.DiscreteTransferFcn_n;
  if (rtmIsMajorTimeStep(s_torsion_M)) {
    /* ManualSwitch: '<Root>/Manual Switch' */
    if (s_torsion_P.ManualSwitch_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Full-State Feedback'
       */
      s_torsion_B.ManualSwitch[0] = s_torsion_P.FullStateFeedback_Value[0];
      s_torsion_B.ManualSwitch[1] = s_torsion_P.FullStateFeedback_Value[1];
      s_torsion_B.ManualSwitch[2] = s_torsion_P.FullStateFeedback_Value[2];
      s_torsion_B.ManualSwitch[3] = s_torsion_P.FullStateFeedback_Value[3];
    } else {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Partial-State Feedback'
       */
      s_torsion_B.ManualSwitch[0] = s_torsion_P.PartialStateFeedback_Value[0];
      s_torsion_B.ManualSwitch[1] = s_torsion_P.PartialStateFeedback_Value[1];
      s_torsion_B.ManualSwitch[2] = s_torsion_P.PartialStateFeedback_Value[2];
      s_torsion_B.ManualSwitch[3] = s_torsion_P.PartialStateFeedback_Value[3];
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */
  }

  /* Gain: '<Root>/Control Gain' incorporates:
   *  Gain: '<S2>/Convert to  Vector State'
   *  Product: '<Root>/FS // PS'
   *  Sum: '<Root>/Sum'
   */
  deltaT_tmp = (((rtb_Sum_idx_0 - s_torsion_B.StateSpace[0] *
                  s_torsion_B.ManualSwitch[0]) * s_torsion_P.K[0] +
                 (rtb_Sum_idx_1 - s_torsion_B.StateSpace[1] *
                  s_torsion_B.ManualSwitch[1]) * s_torsion_P.K[1]) +
                (rtb_Sum_idx_2 - s_torsion_B.DiscreteTransferFcn *
                 s_torsion_B.ManualSwitch[2]) * s_torsion_P.K[2]) + (deltaT_tmp
    - s_torsion_B.DiscreteTransferFcn_n * s_torsion_B.ManualSwitch[3]) *
    s_torsion_P.K[3];

  /* Saturate: '<Root>/Saturation (V)' incorporates:
   *  Gain: '<Root>/Control Gain'
   */
  if (deltaT_tmp > s_torsion_P.SaturationV_UpperSat) {
    /* Saturate: '<Root>/Saturation (V)' */
    s_torsion_B.SaturationV = s_torsion_P.SaturationV_UpperSat;
  } else if (deltaT_tmp < s_torsion_P.SaturationV_LowerSat) {
    /* Saturate: '<Root>/Saturation (V)' */
    s_torsion_B.SaturationV = s_torsion_P.SaturationV_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation (V)' */
    s_torsion_B.SaturationV = deltaT_tmp;
  }

  /* End of Saturate: '<Root>/Saturation (V)' */
  if (rtmIsMajorTimeStep(s_torsion_M)) {
  }
}

/* Model update function */
void s_torsion_update(void)
{
  /* Update for RateLimiter: '<S2>/Rate Limiter' */
  s_torsion_DW.PrevY = s_torsion_B.RateLimiter;
  s_torsion_DW.LastMajorTime = s_torsion_M->Timing.t[0];
  if (rtmIsMajorTimeStep(s_torsion_M)) {
    /* Update for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
    s_torsion_DW.DiscreteTransferFcn_states[1] =
      s_torsion_DW.DiscreteTransferFcn_states[0];
    s_torsion_DW.DiscreteTransferFcn_states[0] =
      s_torsion_DW.DiscreteTransferFcn_tmp;

    /* Update for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
    s_torsion_DW.DiscreteTransferFcn_states_k[1] =
      s_torsion_DW.DiscreteTransferFcn_states_k[0];
    s_torsion_DW.DiscreteTransferFcn_states_k[0] =
      s_torsion_DW.DiscreteTransferFcn_tmp_k;
  }

  if (rtmIsMajorTimeStep(s_torsion_M)) {
    rt_ertODEUpdateContinuousStates(&s_torsion_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++s_torsion_M->Timing.clockTick0)) {
    ++s_torsion_M->Timing.clockTickH0;
  }

  s_torsion_M->Timing.t[0] = rtsiGetSolverStopTime(&s_torsion_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++s_torsion_M->Timing.clockTick1)) {
      ++s_torsion_M->Timing.clockTickH1;
    }

    s_torsion_M->Timing.t[1] = s_torsion_M->Timing.clockTick1 *
      s_torsion_M->Timing.stepSize1 + s_torsion_M->Timing.clockTickH1 *
      s_torsion_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void s_torsion_derivatives(void)
{
  XDot_s_torsion_T *_rtXdot;
  real_T StateSpace_CSTATE;
  real_T StateSpace_CSTATE_0;
  real_T StateSpace_CSTATE_1;
  real_T StateSpace_CSTATE_2;
  int_T is;
  _rtXdot = ((XDot_s_torsion_T *) s_torsion_M->derivs);

  /* Derivatives for StateSpace: '<Root>/State-Space' */
  StateSpace_CSTATE = s_torsion_X.StateSpace_CSTATE[1];
  StateSpace_CSTATE_0 = s_torsion_X.StateSpace_CSTATE[0];
  StateSpace_CSTATE_1 = s_torsion_X.StateSpace_CSTATE[2];
  StateSpace_CSTATE_2 = s_torsion_X.StateSpace_CSTATE[3];
  for (is = 0; is <= 2; is += 2) {
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&s_torsion_P.A[is + 4]),
      _mm_set1_pd(StateSpace_CSTATE)), _mm_mul_pd(_mm_loadu_pd(&s_torsion_P.A[is]),
      _mm_set1_pd(StateSpace_CSTATE_0))), _mm_mul_pd(_mm_loadu_pd
      (&s_torsion_P.A[is + 8]), _mm_set1_pd(StateSpace_CSTATE_1))), _mm_mul_pd
       (_mm_loadu_pd(&s_torsion_P.A[is + 12]), _mm_set1_pd(StateSpace_CSTATE_2))),
      _mm_mul_pd(_mm_loadu_pd(&s_torsion_P.B[is]), _mm_set1_pd
                 (s_torsion_B.SaturationV))));
  }

  /* End of Derivatives for StateSpace: '<Root>/State-Space' */
}

/* Model initialize function */
void s_torsion_initialize(void)
{
  /* InitializeConditions for RateLimiter: '<S2>/Rate Limiter' */
  s_torsion_DW.LastMajorTime = (rtInf);

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  s_torsion_X.StateSpace_CSTATE[0] = s_torsion_P.StateSpace_InitialCondition;
  s_torsion_X.StateSpace_CSTATE[1] = s_torsion_P.StateSpace_InitialCondition;
  s_torsion_X.StateSpace_CSTATE[2] = s_torsion_P.StateSpace_InitialCondition;
  s_torsion_X.StateSpace_CSTATE[3] = s_torsion_P.StateSpace_InitialCondition;

  /* InitializeConditions for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  s_torsion_DW.DiscreteTransferFcn_states[0] =
    s_torsion_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  s_torsion_DW.DiscreteTransferFcn_states_k[0] =
    s_torsion_P.DiscreteTransferFcn_InitialSt_b;

  /* InitializeConditions for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  s_torsion_DW.DiscreteTransferFcn_states[1] =
    s_torsion_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  s_torsion_DW.DiscreteTransferFcn_states_k[1] =
    s_torsion_P.DiscreteTransferFcn_InitialSt_b;
}

/* Model terminate function */
void s_torsion_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  s_torsion_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  s_torsion_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  s_torsion_initialize();
}

void MdlTerminate(void)
{
  s_torsion_terminate();
}

/* Registration function */
RT_MODEL_s_torsion_T *s_torsion(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)s_torsion_M, 0,
                sizeof(RT_MODEL_s_torsion_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&s_torsion_M->solverInfo,
                          &s_torsion_M->Timing.simTimeStep);
    rtsiSetTPtr(&s_torsion_M->solverInfo, &rtmGetTPtr(s_torsion_M));
    rtsiSetStepSizePtr(&s_torsion_M->solverInfo, &s_torsion_M->Timing.stepSize0);
    rtsiSetdXPtr(&s_torsion_M->solverInfo, &s_torsion_M->derivs);
    rtsiSetContStatesPtr(&s_torsion_M->solverInfo, (real_T **)
                         &s_torsion_M->contStates);
    rtsiSetNumContStatesPtr(&s_torsion_M->solverInfo,
      &s_torsion_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&s_torsion_M->solverInfo,
      &s_torsion_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&s_torsion_M->solverInfo,
      &s_torsion_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&s_torsion_M->solverInfo,
      &s_torsion_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&s_torsion_M->solverInfo, (boolean_T**)
      &s_torsion_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&s_torsion_M->solverInfo, (&rtmGetErrorStatus
      (s_torsion_M)));
    rtsiSetRTModelPtr(&s_torsion_M->solverInfo, s_torsion_M);
  }

  rtsiSetSimTimeStep(&s_torsion_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&s_torsion_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&s_torsion_M->solverInfo, false);
  s_torsion_M->intgData.f[0] = s_torsion_M->odeF[0];
  s_torsion_M->contStates = ((real_T *) &s_torsion_X);
  s_torsion_M->contStateDisabled = ((boolean_T *) &s_torsion_XDis);
  s_torsion_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&s_torsion_M->solverInfo, (void *)&s_torsion_M->intgData);
  rtsiSetSolverName(&s_torsion_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = s_torsion_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "s_torsion_M points to
       static memory which is guaranteed to be non-NULL" */
    s_torsion_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    s_torsion_M->Timing.sampleTimes = (&s_torsion_M->Timing.sampleTimesArray[0]);
    s_torsion_M->Timing.offsetTimes = (&s_torsion_M->Timing.offsetTimesArray[0]);

    /* task periods */
    s_torsion_M->Timing.sampleTimes[0] = (0.0);
    s_torsion_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    s_torsion_M->Timing.offsetTimes[0] = (0.0);
    s_torsion_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(s_torsion_M, &s_torsion_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = s_torsion_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    s_torsion_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(s_torsion_M, 5.0);
  s_torsion_M->Timing.stepSize0 = 0.002;
  s_torsion_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  s_torsion_M->Sizes.checksums[0] = (210498291U);
  s_torsion_M->Sizes.checksums[1] = (481767036U);
  s_torsion_M->Sizes.checksums[2] = (207521249U);
  s_torsion_M->Sizes.checksums[3] = (450995880U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    s_torsion_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(s_torsion_M->extModeInfo,
      &s_torsion_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(s_torsion_M->extModeInfo, s_torsion_M->Sizes.checksums);
    rteiSetTPtr(s_torsion_M->extModeInfo, rtmGetTPtr(s_torsion_M));
  }

  s_torsion_M->solverInfoPtr = (&s_torsion_M->solverInfo);
  s_torsion_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&s_torsion_M->solverInfo, 0.002);
  rtsiSetSolverMode(&s_torsion_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  s_torsion_M->blockIO = ((void *) &s_torsion_B);

  {
    s_torsion_B.RateLimiter = 0.0;
    s_torsion_B.Gain[0] = 0.0;
    s_torsion_B.Gain[1] = 0.0;
    s_torsion_B.Gain[2] = 0.0;
    s_torsion_B.Gain[3] = 0.0;
    s_torsion_B.StateSpace[0] = 0.0;
    s_torsion_B.StateSpace[1] = 0.0;
    s_torsion_B.DiscreteTransferFcn = 0.0;
    s_torsion_B.DiscreteTransferFcn_n = 0.0;
    s_torsion_B.Gain_o[0] = 0.0;
    s_torsion_B.Gain_o[1] = 0.0;
    s_torsion_B.Gain_o[2] = 0.0;
    s_torsion_B.Gain_o[3] = 0.0;
    s_torsion_B.ManualSwitch[0] = 0.0;
    s_torsion_B.ManualSwitch[1] = 0.0;
    s_torsion_B.ManualSwitch[2] = 0.0;
    s_torsion_B.ManualSwitch[3] = 0.0;
    s_torsion_B.SaturationV = 0.0;
  }

  /* parameters */
  s_torsion_M->defaultParam = ((real_T *)&s_torsion_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &s_torsion_X;
    s_torsion_M->contStates = (x);
    (void) memset((void *)&s_torsion_X, 0,
                  sizeof(X_s_torsion_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &s_torsion_XDis;
    s_torsion_M->contStateDisabled = (xdis);
    (void) memset((void *)&s_torsion_XDis, 0,
                  sizeof(XDis_s_torsion_T));
  }

  /* states (dwork) */
  s_torsion_M->dwork = ((void *) &s_torsion_DW);
  (void) memset((void *)&s_torsion_DW, 0,
                sizeof(DW_s_torsion_T));
  s_torsion_DW.DiscreteTransferFcn_states[0] = 0.0;
  s_torsion_DW.DiscreteTransferFcn_states[1] = 0.0;
  s_torsion_DW.DiscreteTransferFcn_states_k[0] = 0.0;
  s_torsion_DW.DiscreteTransferFcn_states_k[1] = 0.0;
  s_torsion_DW.PrevY = 0.0;
  s_torsion_DW.LastMajorTime = 0.0;
  s_torsion_DW.DiscreteTransferFcn_tmp = 0.0;
  s_torsion_DW.DiscreteTransferFcn_tmp_k = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    s_torsion_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  s_torsion_M->Sizes.numContStates = (4);/* Number of continuous states */
  s_torsion_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  s_torsion_M->Sizes.numY = (0);       /* Number of model outputs */
  s_torsion_M->Sizes.numU = (0);       /* Number of model inputs */
  s_torsion_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  s_torsion_M->Sizes.numSampTimes = (2);/* Number of sample times */
  s_torsion_M->Sizes.numBlocks = (22); /* Number of blocks */
  s_torsion_M->Sizes.numBlockIO = (9); /* Number of block outputs */
  s_torsion_M->Sizes.numBlockPrms = (70);/* Sum of parameter "widths" */
  return s_torsion_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
