/*
 * s_rotpen_bal.c
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
#include <math.h>
#include "rtwtypes.h"
#include "s_rotpen_bal_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "s_rotpen_bal_dt.h"

/* Block signals (default storage) */
B_s_rotpen_bal_T s_rotpen_bal_B;

/* Continuous states */
X_s_rotpen_bal_T s_rotpen_bal_X;

/* Disabled State Vector */
XDis_s_rotpen_bal_T s_rotpen_bal_XDis;

/* Block states (default storage) */
DW_s_rotpen_bal_T s_rotpen_bal_DW;

/* Real-time model */
static RT_MODEL_s_rotpen_bal_T s_rotpen_bal_M_;
RT_MODEL_s_rotpen_bal_T *const s_rotpen_bal_M = &s_rotpen_bal_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  s_rotpen_bal_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void s_rotpen_bal_output(void)
{
  real_T InvertedPendulumModel;
  real_T InvertedPendulumModel_CSTATE;
  real_T InvertedPendulumModel_CSTATE_0;
  real_T InvertedPendulumModel_CSTATE_1;
  real_T InvertedPendulumModel_CSTATE_2;
  int_T iy;
  if (rtmIsMajorTimeStep(s_rotpen_bal_M)) {
    /* set solver stop time */
    if (!(s_rotpen_bal_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&s_rotpen_bal_M->solverInfo,
                            ((s_rotpen_bal_M->Timing.clockTickH0 + 1) *
        s_rotpen_bal_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&s_rotpen_bal_M->solverInfo,
                            ((s_rotpen_bal_M->Timing.clockTick0 + 1) *
        s_rotpen_bal_M->Timing.stepSize0 + s_rotpen_bal_M->Timing.clockTickH0 *
        s_rotpen_bal_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(s_rotpen_bal_M)) {
    s_rotpen_bal_M->Timing.t[0] = rtsiGetT(&s_rotpen_bal_M->solverInfo);
  }

  /* StateSpace: '<Root>/Inverted Pendulum  Model' */
  InvertedPendulumModel_CSTATE = s_rotpen_bal_X.InvertedPendulumModel_CSTATE[0];
  InvertedPendulumModel_CSTATE_0 = s_rotpen_bal_X.InvertedPendulumModel_CSTATE[1];
  InvertedPendulumModel_CSTATE_1 = s_rotpen_bal_X.InvertedPendulumModel_CSTATE[2];
  InvertedPendulumModel_CSTATE_2 = s_rotpen_bal_X.InvertedPendulumModel_CSTATE[3];
  for (iy = 0; iy < 2; iy++) {
    InvertedPendulumModel = s_rotpen_bal_P.C[iy] * InvertedPendulumModel_CSTATE;
    InvertedPendulumModel += s_rotpen_bal_P.C[iy + 2] *
      InvertedPendulumModel_CSTATE_0;
    InvertedPendulumModel += s_rotpen_bal_P.C[iy + 4] *
      InvertedPendulumModel_CSTATE_1;
    InvertedPendulumModel += s_rotpen_bal_P.C[iy + 6] *
      InvertedPendulumModel_CSTATE_2;

    /* StateSpace: '<Root>/Inverted Pendulum  Model' */
    s_rotpen_bal_B.InvertedPendulumModel[iy] = InvertedPendulumModel;
  }

  /* End of StateSpace: '<Root>/Inverted Pendulum  Model' */

  /* Gain: '<S4>/Gain' */
  s_rotpen_bal_B.Gain = s_rotpen_bal_P.Gain_Gain *
    s_rotpen_bal_B.InvertedPendulumModel[1];
  if (rtmIsMajorTimeStep(s_rotpen_bal_M)) {
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  InvertedPendulumModel_CSTATE = s_rotpen_bal_P.SignalGenerator_Frequency *
    s_rotpen_bal_M->Timing.t[0];
  if (InvertedPendulumModel_CSTATE - floor(InvertedPendulumModel_CSTATE) >= 0.5)
  {
    /* SignalGenerator: '<Root>/Signal Generator' */
    s_rotpen_bal_B.SignalGenerator = s_rotpen_bal_P.SignalGenerator_Amplitude;
  } else {
    /* SignalGenerator: '<Root>/Signal Generator' */
    s_rotpen_bal_B.SignalGenerator = -s_rotpen_bal_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/Amplitude (deg)' */
  s_rotpen_bal_B.Amplitudedeg = s_rotpen_bal_P.Amplitudedeg_Gain *
    s_rotpen_bal_B.SignalGenerator;

  /* Gain: '<S1>/Gain1' */
  s_rotpen_bal_B.Gain1 = s_rotpen_bal_P.Gain1_Gain * s_rotpen_bal_B.Amplitudedeg;

  /* Gain: '<Root>/Convert to  Vector State' */
  s_rotpen_bal_B.ConverttoVectorState[0] =
    s_rotpen_bal_P.ConverttoVectorState_Gain[0] * s_rotpen_bal_B.Gain1;
  s_rotpen_bal_B.ConverttoVectorState[1] =
    s_rotpen_bal_P.ConverttoVectorState_Gain[1] * s_rotpen_bal_B.Gain1;
  s_rotpen_bal_B.ConverttoVectorState[2] =
    s_rotpen_bal_P.ConverttoVectorState_Gain[2] * s_rotpen_bal_B.Gain1;
  s_rotpen_bal_B.ConverttoVectorState[3] =
    s_rotpen_bal_P.ConverttoVectorState_Gain[3] * s_rotpen_bal_B.Gain1;

  /* Gain: '<S5>/Gain' */
  s_rotpen_bal_B.Gain_j[0] = s_rotpen_bal_P.Gain_Gain_g *
    s_rotpen_bal_B.ConverttoVectorState[0];
  s_rotpen_bal_B.Gain_j[1] = s_rotpen_bal_P.Gain_Gain_g *
    s_rotpen_bal_B.InvertedPendulumModel[0];
  if (rtmIsMajorTimeStep(s_rotpen_bal_M)) {
  }

  /* TransferFcn: '<S2>/HPF: theta_dot (rad//s)' */
  s_rotpen_bal_B.HPFtheta_dotrads = s_rotpen_bal_P.HPFtheta_dotrads_C *
    s_rotpen_bal_X.HPFtheta_dotrads_CSTATE;
  s_rotpen_bal_B.HPFtheta_dotrads += s_rotpen_bal_P.HPFtheta_dotrads_D *
    s_rotpen_bal_B.InvertedPendulumModel[0];

  /* TransferFcn: '<S2>/HPF: alpha_dot (rad//s)' */
  s_rotpen_bal_B.HPFalpha_dotrads = s_rotpen_bal_P.HPFalpha_dotrads_C *
    s_rotpen_bal_X.HPFalpha_dotrads_CSTATE;
  s_rotpen_bal_B.HPFalpha_dotrads += s_rotpen_bal_P.HPFalpha_dotrads_D *
    s_rotpen_bal_B.InvertedPendulumModel[1];

  /* Sum: '<Root>/Sum' */
  s_rotpen_bal_B.Sum[0] = s_rotpen_bal_B.ConverttoVectorState[0] -
    s_rotpen_bal_B.InvertedPendulumModel[0];
  s_rotpen_bal_B.Sum[1] = s_rotpen_bal_B.ConverttoVectorState[1] -
    s_rotpen_bal_B.InvertedPendulumModel[1];
  s_rotpen_bal_B.Sum[2] = s_rotpen_bal_B.ConverttoVectorState[2] -
    s_rotpen_bal_B.HPFtheta_dotrads;
  s_rotpen_bal_B.Sum[3] = s_rotpen_bal_B.ConverttoVectorState[3] -
    s_rotpen_bal_B.HPFalpha_dotrads;

  /* Gain: '<Root>/Control  Gain' */
  InvertedPendulumModel_CSTATE = s_rotpen_bal_P.K[0] * s_rotpen_bal_B.Sum[0];
  InvertedPendulumModel_CSTATE += s_rotpen_bal_P.K[1] * s_rotpen_bal_B.Sum[1];
  InvertedPendulumModel_CSTATE += s_rotpen_bal_P.K[2] * s_rotpen_bal_B.Sum[2];
  InvertedPendulumModel_CSTATE += s_rotpen_bal_P.K[3] * s_rotpen_bal_B.Sum[3];

  /* Gain: '<Root>/Control  Gain' */
  s_rotpen_bal_B.ControlGain = InvertedPendulumModel_CSTATE;
  if (rtmIsMajorTimeStep(s_rotpen_bal_M)) {
  }
}

/* Model update function */
void s_rotpen_bal_update(void)
{
  if (rtmIsMajorTimeStep(s_rotpen_bal_M)) {
    rt_ertODEUpdateContinuousStates(&s_rotpen_bal_M->solverInfo);
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
  if (!(++s_rotpen_bal_M->Timing.clockTick0)) {
    ++s_rotpen_bal_M->Timing.clockTickH0;
  }

  s_rotpen_bal_M->Timing.t[0] = rtsiGetSolverStopTime
    (&s_rotpen_bal_M->solverInfo);

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
    if (!(++s_rotpen_bal_M->Timing.clockTick1)) {
      ++s_rotpen_bal_M->Timing.clockTickH1;
    }

    s_rotpen_bal_M->Timing.t[1] = s_rotpen_bal_M->Timing.clockTick1 *
      s_rotpen_bal_M->Timing.stepSize1 + s_rotpen_bal_M->Timing.clockTickH1 *
      s_rotpen_bal_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void s_rotpen_bal_derivatives(void)
{
  XDot_s_rotpen_bal_T *_rtXdot;
  real_T InvertedPendulumModel_CSTATE;
  real_T InvertedPendulumModel_CSTATE_0;
  real_T InvertedPendulumModel_CSTATE_1;
  real_T InvertedPendulumModel_CSTATE_2;
  real_T InvertedPendulumModel_CSTATE_3;
  int_T is;
  _rtXdot = ((XDot_s_rotpen_bal_T *) s_rotpen_bal_M->derivs);

  /* Derivatives for StateSpace: '<Root>/Inverted Pendulum  Model' */
  InvertedPendulumModel_CSTATE_0 = s_rotpen_bal_X.InvertedPendulumModel_CSTATE[0];
  InvertedPendulumModel_CSTATE_1 = s_rotpen_bal_X.InvertedPendulumModel_CSTATE[1];
  InvertedPendulumModel_CSTATE_2 = s_rotpen_bal_X.InvertedPendulumModel_CSTATE[2];
  InvertedPendulumModel_CSTATE_3 = s_rotpen_bal_X.InvertedPendulumModel_CSTATE[3];
  for (is = 0; is < 4; is++) {
    InvertedPendulumModel_CSTATE = s_rotpen_bal_P.A[is] *
      InvertedPendulumModel_CSTATE_0;
    InvertedPendulumModel_CSTATE += s_rotpen_bal_P.A[is + 4] *
      InvertedPendulumModel_CSTATE_1;
    InvertedPendulumModel_CSTATE += s_rotpen_bal_P.A[is + 8] *
      InvertedPendulumModel_CSTATE_2;
    InvertedPendulumModel_CSTATE += s_rotpen_bal_P.A[is + 12] *
      InvertedPendulumModel_CSTATE_3;
    InvertedPendulumModel_CSTATE += s_rotpen_bal_P.B[is] *
      s_rotpen_bal_B.ControlGain;
    _rtXdot->InvertedPendulumModel_CSTATE[is] = InvertedPendulumModel_CSTATE;
  }

  /* End of Derivatives for StateSpace: '<Root>/Inverted Pendulum  Model' */

  /* Derivatives for TransferFcn: '<S2>/HPF: theta_dot (rad//s)' */
  _rtXdot->HPFtheta_dotrads_CSTATE = s_rotpen_bal_P.HPFtheta_dotrads_A *
    s_rotpen_bal_X.HPFtheta_dotrads_CSTATE;
  _rtXdot->HPFtheta_dotrads_CSTATE += s_rotpen_bal_B.InvertedPendulumModel[0];

  /* Derivatives for TransferFcn: '<S2>/HPF: alpha_dot (rad//s)' */
  _rtXdot->HPFalpha_dotrads_CSTATE = s_rotpen_bal_P.HPFalpha_dotrads_A *
    s_rotpen_bal_X.HPFalpha_dotrads_CSTATE;
  _rtXdot->HPFalpha_dotrads_CSTATE += s_rotpen_bal_B.InvertedPendulumModel[1];
}

/* Model initialize function */
void s_rotpen_bal_initialize(void)
{
  /* InitializeConditions for StateSpace: '<Root>/Inverted Pendulum  Model' */
  s_rotpen_bal_X.InvertedPendulumModel_CSTATE[0] =
    s_rotpen_bal_P.InvertedPendulumModel_InitialCo;
  s_rotpen_bal_X.InvertedPendulumModel_CSTATE[1] =
    s_rotpen_bal_P.InvertedPendulumModel_InitialCo;
  s_rotpen_bal_X.InvertedPendulumModel_CSTATE[2] =
    s_rotpen_bal_P.InvertedPendulumModel_InitialCo;
  s_rotpen_bal_X.InvertedPendulumModel_CSTATE[3] =
    s_rotpen_bal_P.InvertedPendulumModel_InitialCo;

  /* InitializeConditions for TransferFcn: '<S2>/HPF: theta_dot (rad//s)' */
  s_rotpen_bal_X.HPFtheta_dotrads_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/HPF: alpha_dot (rad//s)' */
  s_rotpen_bal_X.HPFalpha_dotrads_CSTATE = 0.0;
}

/* Model terminate function */
void s_rotpen_bal_terminate(void)
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
  s_rotpen_bal_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  s_rotpen_bal_update();
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
  s_rotpen_bal_initialize();
}

void MdlTerminate(void)
{
  s_rotpen_bal_terminate();
}

/* Registration function */
RT_MODEL_s_rotpen_bal_T *s_rotpen_bal(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)s_rotpen_bal_M, 0,
                sizeof(RT_MODEL_s_rotpen_bal_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&s_rotpen_bal_M->solverInfo,
                          &s_rotpen_bal_M->Timing.simTimeStep);
    rtsiSetTPtr(&s_rotpen_bal_M->solverInfo, &rtmGetTPtr(s_rotpen_bal_M));
    rtsiSetStepSizePtr(&s_rotpen_bal_M->solverInfo,
                       &s_rotpen_bal_M->Timing.stepSize0);
    rtsiSetdXPtr(&s_rotpen_bal_M->solverInfo, &s_rotpen_bal_M->derivs);
    rtsiSetContStatesPtr(&s_rotpen_bal_M->solverInfo, (real_T **)
                         &s_rotpen_bal_M->contStates);
    rtsiSetNumContStatesPtr(&s_rotpen_bal_M->solverInfo,
      &s_rotpen_bal_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&s_rotpen_bal_M->solverInfo,
      &s_rotpen_bal_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&s_rotpen_bal_M->solverInfo,
      &s_rotpen_bal_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&s_rotpen_bal_M->solverInfo,
      &s_rotpen_bal_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&s_rotpen_bal_M->solverInfo, (boolean_T**)
      &s_rotpen_bal_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&s_rotpen_bal_M->solverInfo, (&rtmGetErrorStatus
      (s_rotpen_bal_M)));
    rtsiSetRTModelPtr(&s_rotpen_bal_M->solverInfo, s_rotpen_bal_M);
  }

  rtsiSetSimTimeStep(&s_rotpen_bal_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&s_rotpen_bal_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&s_rotpen_bal_M->solverInfo, false);
  s_rotpen_bal_M->intgData.f[0] = s_rotpen_bal_M->odeF[0];
  s_rotpen_bal_M->contStates = ((real_T *) &s_rotpen_bal_X);
  s_rotpen_bal_M->contStateDisabled = ((boolean_T *) &s_rotpen_bal_XDis);
  s_rotpen_bal_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&s_rotpen_bal_M->solverInfo, (void *)
                    &s_rotpen_bal_M->intgData);
  rtsiSetSolverName(&s_rotpen_bal_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = s_rotpen_bal_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "s_rotpen_bal_M points to
       static memory which is guaranteed to be non-NULL" */
    s_rotpen_bal_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    s_rotpen_bal_M->Timing.sampleTimes =
      (&s_rotpen_bal_M->Timing.sampleTimesArray[0]);
    s_rotpen_bal_M->Timing.offsetTimes =
      (&s_rotpen_bal_M->Timing.offsetTimesArray[0]);

    /* task periods */
    s_rotpen_bal_M->Timing.sampleTimes[0] = (0.0);
    s_rotpen_bal_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    s_rotpen_bal_M->Timing.offsetTimes[0] = (0.0);
    s_rotpen_bal_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(s_rotpen_bal_M, &s_rotpen_bal_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = s_rotpen_bal_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    s_rotpen_bal_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(s_rotpen_bal_M, 10.0);
  s_rotpen_bal_M->Timing.stepSize0 = 0.002;
  s_rotpen_bal_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  s_rotpen_bal_M->Sizes.checksums[0] = (4093483053U);
  s_rotpen_bal_M->Sizes.checksums[1] = (1869852445U);
  s_rotpen_bal_M->Sizes.checksums[2] = (235411782U);
  s_rotpen_bal_M->Sizes.checksums[3] = (2578978309U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    s_rotpen_bal_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(s_rotpen_bal_M->extModeInfo,
      &s_rotpen_bal_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(s_rotpen_bal_M->extModeInfo,
                        s_rotpen_bal_M->Sizes.checksums);
    rteiSetTPtr(s_rotpen_bal_M->extModeInfo, rtmGetTPtr(s_rotpen_bal_M));
  }

  s_rotpen_bal_M->solverInfoPtr = (&s_rotpen_bal_M->solverInfo);
  s_rotpen_bal_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&s_rotpen_bal_M->solverInfo, 0.002);
  rtsiSetSolverMode(&s_rotpen_bal_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  s_rotpen_bal_M->blockIO = ((void *) &s_rotpen_bal_B);

  {
    s_rotpen_bal_B.InvertedPendulumModel[0] = 0.0;
    s_rotpen_bal_B.InvertedPendulumModel[1] = 0.0;
    s_rotpen_bal_B.Gain = 0.0;
    s_rotpen_bal_B.SignalGenerator = 0.0;
    s_rotpen_bal_B.Amplitudedeg = 0.0;
    s_rotpen_bal_B.Gain1 = 0.0;
    s_rotpen_bal_B.ConverttoVectorState[0] = 0.0;
    s_rotpen_bal_B.ConverttoVectorState[1] = 0.0;
    s_rotpen_bal_B.ConverttoVectorState[2] = 0.0;
    s_rotpen_bal_B.ConverttoVectorState[3] = 0.0;
    s_rotpen_bal_B.Gain_j[0] = 0.0;
    s_rotpen_bal_B.Gain_j[1] = 0.0;
    s_rotpen_bal_B.HPFtheta_dotrads = 0.0;
    s_rotpen_bal_B.HPFalpha_dotrads = 0.0;
    s_rotpen_bal_B.Sum[0] = 0.0;
    s_rotpen_bal_B.Sum[1] = 0.0;
    s_rotpen_bal_B.Sum[2] = 0.0;
    s_rotpen_bal_B.Sum[3] = 0.0;
    s_rotpen_bal_B.ControlGain = 0.0;
  }

  /* parameters */
  s_rotpen_bal_M->defaultParam = ((real_T *)&s_rotpen_bal_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &s_rotpen_bal_X;
    s_rotpen_bal_M->contStates = (x);
    (void) memset((void *)&s_rotpen_bal_X, 0,
                  sizeof(X_s_rotpen_bal_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &s_rotpen_bal_XDis;
    s_rotpen_bal_M->contStateDisabled = (xdis);
    (void) memset((void *)&s_rotpen_bal_XDis, 0,
                  sizeof(XDis_s_rotpen_bal_T));
  }

  /* states (dwork) */
  s_rotpen_bal_M->dwork = ((void *) &s_rotpen_bal_DW);
  (void) memset((void *)&s_rotpen_bal_DW, 0,
                sizeof(DW_s_rotpen_bal_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    s_rotpen_bal_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  s_rotpen_bal_M->Sizes.numContStates = (6);/* Number of continuous states */
  s_rotpen_bal_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  s_rotpen_bal_M->Sizes.numY = (0);    /* Number of model outputs */
  s_rotpen_bal_M->Sizes.numU = (0);    /* Number of model inputs */
  s_rotpen_bal_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  s_rotpen_bal_M->Sizes.numSampTimes = (2);/* Number of sample times */
  s_rotpen_bal_M->Sizes.numBlocks = (14);/* Number of blocks */
  s_rotpen_bal_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  s_rotpen_bal_M->Sizes.numBlockPrms = (49);/* Sum of parameter "widths" */
  return s_rotpen_bal_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
