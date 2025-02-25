/*
 * q_torsion_val.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_torsion_val".
 *
 * Model version              : 27.6
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Feb 20 14:43:55 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_torsion_val.h"
#include "rtwtypes.h"
#include <emmintrin.h>
#include "q_torsion_val_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "q_torsion_val_dt.h"

/* Block signals (default storage) */
B_q_torsion_val_T q_torsion_val_B;

/* Continuous states */
X_q_torsion_val_T q_torsion_val_X;

/* Disabled State Vector */
XDis_q_torsion_val_T q_torsion_val_XDis;

/* Block states (default storage) */
DW_q_torsion_val_T q_torsion_val_DW;

/* Real-time model */
static RT_MODEL_q_torsion_val_T q_torsion_val_M_;
RT_MODEL_q_torsion_val_T *const q_torsion_val_M = &q_torsion_val_M_;

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
  q_torsion_val_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void q_torsion_val_output(void)
{
  __m128d tmp;
  real_T rtb_HILReadEncoderTimebase[2];
  real_T StateSpace_CSTATE;
  real_T StateSpace_CSTATE_0;
  real_T StateSpace_CSTATE_1;
  real_T u0;
  int_T iy;
  if (rtmIsMajorTimeStep(q_torsion_val_M)) {
    /* set solver stop time */
    if (!(q_torsion_val_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_torsion_val_M->solverInfo,
                            ((q_torsion_val_M->Timing.clockTickH0 + 1) *
        q_torsion_val_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_torsion_val_M->solverInfo,
                            ((q_torsion_val_M->Timing.clockTick0 + 1) *
        q_torsion_val_M->Timing.stepSize0 + q_torsion_val_M->Timing.clockTickH0 *
        q_torsion_val_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_torsion_val_M)) {
    q_torsion_val_M->Timing.t[0] = rtsiGetT(&q_torsion_val_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_torsion_val_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

    /* S-Function Block: q_torsion_val/1 DOF Torsion/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (q_torsion_val_DW.HILReadEncoderTimebase_Task, 1,
         &q_torsion_val_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        rtb_HILReadEncoderTimebase[0] = 0;
        rtb_HILReadEncoderTimebase[1] = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase[0] =
          q_torsion_val_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase[1] =
          q_torsion_val_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Gain: '<S1>/Encoder Calibration  (rad//count)' */
    tmp = _mm_mul_pd(_mm_set1_pd(q_torsion_val_P.K_ENC), _mm_loadu_pd
                     (&rtb_HILReadEncoderTimebase[0]));

    /* Gain: '<S1>/Encoder Calibration  (rad//count)' */
    _mm_storeu_pd(&q_torsion_val_B.EncoderCalibrationradcount[0], tmp);
  }

  /* Step: '<Root>/Step' incorporates:
   *  Step: '<Root>/Step1'
   */
  u0 = q_torsion_val_M->Timing.t[0];
  if (u0 < q_torsion_val_P.Step_Time) {
    StateSpace_CSTATE = q_torsion_val_P.Step_Y0;
  } else {
    StateSpace_CSTATE = q_torsion_val_P.Step_YFinal;
  }

  /* Step: '<Root>/Step1' */
  if (u0 < q_torsion_val_P.Step1_Time) {
    u0 = q_torsion_val_P.Step1_Y0;
  } else {
    u0 = q_torsion_val_P.Step1_YFinal;
  }

  /* Gain: '<Root>/Amplitude (V)' incorporates:
   *  Step: '<Root>/Step'
   *  Step: '<Root>/Step1'
   *  Sum: '<Root>/Add'
   */
  q_torsion_val_B.AmplitudeV = (StateSpace_CSTATE + u0) *
    q_torsion_val_P.AmplitudeV_Gain;

  /* Gain: '<S4>/Direction Convention: (Right-Hand) system' */
  u0 = q_torsion_val_P.DirectionConventionRightHandsys *
    q_torsion_val_B.AmplitudeV;

  /* Saturate: '<S4>/Amplifier  Saturation (V)' */
  if (u0 > q_torsion_val_P.VMAX_AMP) {
    u0 = q_torsion_val_P.VMAX_AMP;
  } else if (u0 < -q_torsion_val_P.VMAX_AMP) {
    u0 = -q_torsion_val_P.VMAX_AMP;
  }

  /* Gain: '<S4>/Inverse Amplifier  Gain (V//V)' incorporates:
   *  Saturate: '<S4>/Amplifier  Saturation (V)'
   */
  u0 *= 1.0 / q_torsion_val_P.K_AMP;

  /* Saturate: '<S4>/DACB Saturation (V)' */
  if (u0 > q_torsion_val_P.VMAX_DAC) {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    q_torsion_val_B.DACBSaturationV = q_torsion_val_P.VMAX_DAC;
  } else if (u0 < -q_torsion_val_P.VMAX_DAC) {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    q_torsion_val_B.DACBSaturationV = -q_torsion_val_P.VMAX_DAC;
  } else {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    q_torsion_val_B.DACBSaturationV = u0;
  }

  /* End of Saturate: '<S4>/DACB Saturation (V)' */
  if (rtmIsMajorTimeStep(q_torsion_val_M)) {
    /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

    /* S-Function Block: q_torsion_val/1 DOF Torsion/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_torsion_val_DW.HILInitialize_Card,
        &q_torsion_val_P.HILWriteAnalog_channels, 1,
        &q_torsion_val_B.DACBSaturationV);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S4>/Amplifier  Gain (V//V)' */
  q_torsion_val_B.AmplifierGainVV = -q_torsion_val_P.K_AMP *
    q_torsion_val_B.DACBSaturationV;

  /* StateSpace: '<Root>/State-Space' */
  u0 = q_torsion_val_X.StateSpace_CSTATE[1];
  StateSpace_CSTATE = q_torsion_val_X.StateSpace_CSTATE[0];
  StateSpace_CSTATE_0 = q_torsion_val_X.StateSpace_CSTATE[2];
  StateSpace_CSTATE_1 = q_torsion_val_X.StateSpace_CSTATE[3];
  for (iy = 0; iy <= 0; iy += 2) {
    _mm_storeu_pd(&rtb_HILReadEncoderTimebase[iy], _mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&q_torsion_val_P.C[iy + 2]),
      _mm_set1_pd(u0)), _mm_mul_pd(_mm_loadu_pd(&q_torsion_val_P.C[iy]),
      _mm_set1_pd(StateSpace_CSTATE))), _mm_mul_pd(_mm_loadu_pd
      (&q_torsion_val_P.C[iy + 4]), _mm_set1_pd(StateSpace_CSTATE_0))),
      _mm_mul_pd(_mm_loadu_pd(&q_torsion_val_P.C[iy + 6]), _mm_set1_pd
                 (StateSpace_CSTATE_1))));
  }

  /* End of StateSpace: '<Root>/State-Space' */

  /* Gain: '<S2>/Gain' */
  _mm_storeu_pd(&q_torsion_val_B.Gain[0], _mm_mul_pd(_mm_set1_pd
    (q_torsion_val_P.Gain_Gain), _mm_set_pd(rtb_HILReadEncoderTimebase[0],
    q_torsion_val_B.EncoderCalibrationradcount[0])));
  if (rtmIsMajorTimeStep(q_torsion_val_M)) {
  }

  /* Gain: '<S3>/Gain' */
  _mm_storeu_pd(&q_torsion_val_B.Gain_k[0], _mm_mul_pd(_mm_set1_pd
    (q_torsion_val_P.Gain_Gain_e), _mm_set_pd(rtb_HILReadEncoderTimebase[1],
    q_torsion_val_B.EncoderCalibrationradcount[1])));
  if (rtmIsMajorTimeStep(q_torsion_val_M)) {
  }

  /* Clock: '<Root>/Clock' */
  q_torsion_val_B.Clock = q_torsion_val_M->Timing.t[0];
  if (rtmIsMajorTimeStep(q_torsion_val_M)) {
  }
}

/* Model update function */
void q_torsion_val_update(void)
{
  if (rtmIsMajorTimeStep(q_torsion_val_M)) {
    rt_ertODEUpdateContinuousStates(&q_torsion_val_M->solverInfo);
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
  if (!(++q_torsion_val_M->Timing.clockTick0)) {
    ++q_torsion_val_M->Timing.clockTickH0;
  }

  q_torsion_val_M->Timing.t[0] = rtsiGetSolverStopTime
    (&q_torsion_val_M->solverInfo);

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
    if (!(++q_torsion_val_M->Timing.clockTick1)) {
      ++q_torsion_val_M->Timing.clockTickH1;
    }

    q_torsion_val_M->Timing.t[1] = q_torsion_val_M->Timing.clockTick1 *
      q_torsion_val_M->Timing.stepSize1 + q_torsion_val_M->Timing.clockTickH1 *
      q_torsion_val_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void q_torsion_val_derivatives(void)
{
  XDot_q_torsion_val_T *_rtXdot;
  real_T StateSpace_CSTATE;
  real_T StateSpace_CSTATE_0;
  real_T StateSpace_CSTATE_1;
  real_T StateSpace_CSTATE_2;
  int_T is;
  _rtXdot = ((XDot_q_torsion_val_T *) q_torsion_val_M->derivs);

  /* Derivatives for StateSpace: '<Root>/State-Space' */
  StateSpace_CSTATE = q_torsion_val_X.StateSpace_CSTATE[1];
  StateSpace_CSTATE_0 = q_torsion_val_X.StateSpace_CSTATE[0];
  StateSpace_CSTATE_1 = q_torsion_val_X.StateSpace_CSTATE[2];
  StateSpace_CSTATE_2 = q_torsion_val_X.StateSpace_CSTATE[3];
  for (is = 0; is <= 2; is += 2) {
    _mm_storeu_pd(&_rtXdot->StateSpace_CSTATE[is], _mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&q_torsion_val_P.A[is + 4]),
      _mm_set1_pd(StateSpace_CSTATE)), _mm_mul_pd(_mm_loadu_pd
      (&q_torsion_val_P.A[is]), _mm_set1_pd(StateSpace_CSTATE_0))), _mm_mul_pd
                  (_mm_loadu_pd(&q_torsion_val_P.A[is + 8]), _mm_set1_pd
                   (StateSpace_CSTATE_1))), _mm_mul_pd(_mm_loadu_pd
      (&q_torsion_val_P.A[is + 12]), _mm_set1_pd(StateSpace_CSTATE_2))),
      _mm_mul_pd(_mm_loadu_pd(&q_torsion_val_P.B[is]), _mm_set1_pd
                 (q_torsion_val_B.AmplitudeV))));
  }

  /* End of Derivatives for StateSpace: '<Root>/State-Space' */
}

/* Model initialize function */
void q_torsion_val_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_torsion_val/1 DOF Torsion/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &q_torsion_val_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(q_torsion_val_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal", 50);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(q_torsion_val_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
      return;
    }

    if ((q_torsion_val_P.HILInitialize_AIPStart && !is_switching) ||
        (q_torsion_val_P.HILInitialize_AIPEnter && is_switching)) {
      q_torsion_val_DW.HILInitialize_AIMinimums[0] =
        (q_torsion_val_P.HILInitialize_AILow);
      q_torsion_val_DW.HILInitialize_AIMinimums[1] =
        (q_torsion_val_P.HILInitialize_AILow);
      q_torsion_val_DW.HILInitialize_AIMaximums[0] =
        q_torsion_val_P.HILInitialize_AIHigh;
      q_torsion_val_DW.HILInitialize_AIMaximums[1] =
        q_torsion_val_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(q_torsion_val_DW.HILInitialize_Card,
        q_torsion_val_P.HILInitialize_AIChannels, 2U,
        &q_torsion_val_DW.HILInitialize_AIMinimums[0],
        &q_torsion_val_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        return;
      }
    }

    if ((q_torsion_val_P.HILInitialize_AOPStart && !is_switching) ||
        (q_torsion_val_P.HILInitialize_AOPEnter && is_switching)) {
      q_torsion_val_DW.HILInitialize_AOMinimums[0] =
        (q_torsion_val_P.HILInitialize_AOLow);
      q_torsion_val_DW.HILInitialize_AOMinimums[1] =
        (q_torsion_val_P.HILInitialize_AOLow);
      q_torsion_val_DW.HILInitialize_AOMaximums[0] =
        q_torsion_val_P.HILInitialize_AOHigh;
      q_torsion_val_DW.HILInitialize_AOMaximums[1] =
        q_torsion_val_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(q_torsion_val_DW.HILInitialize_Card,
        q_torsion_val_P.HILInitialize_AOChannels, 2U,
        &q_torsion_val_DW.HILInitialize_AOMinimums[0],
        &q_torsion_val_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        return;
      }
    }

    if ((q_torsion_val_P.HILInitialize_AOStart && !is_switching) ||
        (q_torsion_val_P.HILInitialize_AOEnter && is_switching)) {
      q_torsion_val_DW.HILInitialize_AOVoltages[0] =
        q_torsion_val_P.HILInitialize_AOInitial;
      q_torsion_val_DW.HILInitialize_AOVoltages[1] =
        q_torsion_val_P.HILInitialize_AOInitial;
      result = hil_write_analog(q_torsion_val_DW.HILInitialize_Card,
        q_torsion_val_P.HILInitialize_AOChannels, 2U,
        &q_torsion_val_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        return;
      }
    }

    if (q_torsion_val_P.HILInitialize_AOReset) {
      q_torsion_val_DW.HILInitialize_AOVoltages[0] =
        q_torsion_val_P.HILInitialize_AOWatchdog;
      q_torsion_val_DW.HILInitialize_AOVoltages[1] =
        q_torsion_val_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (q_torsion_val_DW.HILInitialize_Card,
         q_torsion_val_P.HILInitialize_AOChannels, 2U,
         &q_torsion_val_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(q_torsion_val_DW.HILInitialize_Card,
      NULL, 0U, q_torsion_val_P.HILInitialize_DOChannels, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
      return;
    }

    if ((q_torsion_val_P.HILInitialize_DOStart && !is_switching) ||
        (q_torsion_val_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &q_torsion_val_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = q_torsion_val_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(q_torsion_val_DW.HILInitialize_Card,
        q_torsion_val_P.HILInitialize_DOChannels, 8U, (t_boolean *)
        &q_torsion_val_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        return;
      }
    }

    if (q_torsion_val_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &q_torsion_val_DW.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = q_torsion_val_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (q_torsion_val_DW.HILInitialize_Card,
         q_torsion_val_P.HILInitialize_DOChannels, 8U, (const t_digital_state *)
         &q_torsion_val_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        return;
      }
    }

    if ((q_torsion_val_P.HILInitialize_EIPStart && !is_switching) ||
        (q_torsion_val_P.HILInitialize_EIPEnter && is_switching)) {
      q_torsion_val_DW.HILInitialize_QuadratureModes[0] =
        q_torsion_val_P.HILInitialize_EIQuadrature;
      q_torsion_val_DW.HILInitialize_QuadratureModes[1] =
        q_torsion_val_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (q_torsion_val_DW.HILInitialize_Card,
         q_torsion_val_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &q_torsion_val_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        return;
      }
    }

    if ((q_torsion_val_P.HILInitialize_EIStart && !is_switching) ||
        (q_torsion_val_P.HILInitialize_EIEnter && is_switching)) {
      q_torsion_val_DW.HILInitialize_InitialEICounts[0] =
        q_torsion_val_P.HILInitialize_EIInitial;
      q_torsion_val_DW.HILInitialize_InitialEICounts[1] =
        q_torsion_val_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(q_torsion_val_DW.HILInitialize_Card,
        q_torsion_val_P.HILInitialize_EIChannels, 2U,
        &q_torsion_val_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_torsion_val/1 DOF Torsion/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(q_torsion_val_DW.HILInitialize_Card,
      q_torsion_val_P.HILReadEncoderTimebase_SamplesI,
      q_torsion_val_P.HILReadEncoderTimebase_Channels, 2,
      &q_torsion_val_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (q_torsion_val_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (q_torsion_val_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
    }
  }

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  q_torsion_val_X.StateSpace_CSTATE[0] =
    q_torsion_val_P.StateSpace_InitialCondition;
  q_torsion_val_X.StateSpace_CSTATE[1] =
    q_torsion_val_P.StateSpace_InitialCondition;
  q_torsion_val_X.StateSpace_CSTATE[2] =
    q_torsion_val_P.StateSpace_InitialCondition;
  q_torsion_val_X.StateSpace_CSTATE[3] =
    q_torsion_val_P.StateSpace_InitialCondition;
}

/* Model terminate function */
void q_torsion_val_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_torsion_val/1 DOF Torsion/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(q_torsion_val_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_torsion_val_DW.HILInitialize_Card);
    is_switching = false;
    if ((q_torsion_val_P.HILInitialize_AOTerminate && !is_switching) ||
        (q_torsion_val_P.HILInitialize_AOExit && is_switching)) {
      q_torsion_val_DW.HILInitialize_AOVoltages[0] =
        q_torsion_val_P.HILInitialize_AOFinal;
      q_torsion_val_DW.HILInitialize_AOVoltages[1] =
        q_torsion_val_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((q_torsion_val_P.HILInitialize_DOTerminate && !is_switching) ||
        (q_torsion_val_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &q_torsion_val_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = q_torsion_val_P.HILInitialize_DOFinal;
        }
      }

      num_final_digital_outputs = 8U;
    } else {
      num_final_digital_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(q_torsion_val_DW.HILInitialize_Card
                         , q_torsion_val_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , q_torsion_val_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &q_torsion_val_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *) &q_torsion_val_DW.HILInitialize_DOBits
                         [0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(q_torsion_val_DW.HILInitialize_Card,
            q_torsion_val_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &q_torsion_val_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(q_torsion_val_DW.HILInitialize_Card,
            q_torsion_val_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &q_torsion_val_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_torsion_val_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(q_torsion_val_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_torsion_val_DW.HILInitialize_Card);
    hil_close(q_torsion_val_DW.HILInitialize_Card);
    q_torsion_val_DW.HILInitialize_Card = NULL;
  }
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
  q_torsion_val_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  q_torsion_val_update();
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
  q_torsion_val_initialize();
}

void MdlTerminate(void)
{
  q_torsion_val_terminate();
}

/* Registration function */
RT_MODEL_q_torsion_val_T *q_torsion_val(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_torsion_val_M, 0,
                sizeof(RT_MODEL_q_torsion_val_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_torsion_val_M->solverInfo,
                          &q_torsion_val_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_torsion_val_M->solverInfo, &rtmGetTPtr(q_torsion_val_M));
    rtsiSetStepSizePtr(&q_torsion_val_M->solverInfo,
                       &q_torsion_val_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_torsion_val_M->solverInfo, &q_torsion_val_M->derivs);
    rtsiSetContStatesPtr(&q_torsion_val_M->solverInfo, (real_T **)
                         &q_torsion_val_M->contStates);
    rtsiSetNumContStatesPtr(&q_torsion_val_M->solverInfo,
      &q_torsion_val_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&q_torsion_val_M->solverInfo,
      &q_torsion_val_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&q_torsion_val_M->solverInfo,
      &q_torsion_val_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&q_torsion_val_M->solverInfo,
      &q_torsion_val_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&q_torsion_val_M->solverInfo, (boolean_T**)
      &q_torsion_val_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&q_torsion_val_M->solverInfo, (&rtmGetErrorStatus
      (q_torsion_val_M)));
    rtsiSetRTModelPtr(&q_torsion_val_M->solverInfo, q_torsion_val_M);
  }

  rtsiSetSimTimeStep(&q_torsion_val_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&q_torsion_val_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&q_torsion_val_M->solverInfo, false);
  q_torsion_val_M->intgData.f[0] = q_torsion_val_M->odeF[0];
  q_torsion_val_M->contStates = ((real_T *) &q_torsion_val_X);
  q_torsion_val_M->contStateDisabled = ((boolean_T *) &q_torsion_val_XDis);
  q_torsion_val_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&q_torsion_val_M->solverInfo, (void *)
                    &q_torsion_val_M->intgData);
  rtsiSetSolverName(&q_torsion_val_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_torsion_val_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "q_torsion_val_M points to
       static memory which is guaranteed to be non-NULL" */
    q_torsion_val_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_torsion_val_M->Timing.sampleTimes =
      (&q_torsion_val_M->Timing.sampleTimesArray[0]);
    q_torsion_val_M->Timing.offsetTimes =
      (&q_torsion_val_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_torsion_val_M->Timing.sampleTimes[0] = (0.0);
    q_torsion_val_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    q_torsion_val_M->Timing.offsetTimes[0] = (0.0);
    q_torsion_val_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(q_torsion_val_M, &q_torsion_val_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_torsion_val_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    q_torsion_val_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_torsion_val_M, 5.0);
  q_torsion_val_M->Timing.stepSize0 = 0.002;
  q_torsion_val_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  q_torsion_val_M->Sizes.checksums[0] = (2082005228U);
  q_torsion_val_M->Sizes.checksums[1] = (230643877U);
  q_torsion_val_M->Sizes.checksums[2] = (3477180362U);
  q_torsion_val_M->Sizes.checksums[3] = (1655781463U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    q_torsion_val_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_torsion_val_M->extModeInfo,
      &q_torsion_val_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_torsion_val_M->extModeInfo,
                        q_torsion_val_M->Sizes.checksums);
    rteiSetTPtr(q_torsion_val_M->extModeInfo, rtmGetTPtr(q_torsion_val_M));
  }

  q_torsion_val_M->solverInfoPtr = (&q_torsion_val_M->solverInfo);
  q_torsion_val_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&q_torsion_val_M->solverInfo, 0.002);
  rtsiSetSolverMode(&q_torsion_val_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  q_torsion_val_M->blockIO = ((void *) &q_torsion_val_B);

  {
    q_torsion_val_B.EncoderCalibrationradcount[0] = 0.0;
    q_torsion_val_B.EncoderCalibrationradcount[1] = 0.0;
    q_torsion_val_B.AmplitudeV = 0.0;
    q_torsion_val_B.DACBSaturationV = 0.0;
    q_torsion_val_B.AmplifierGainVV = 0.0;
    q_torsion_val_B.Gain[0] = 0.0;
    q_torsion_val_B.Gain[1] = 0.0;
    q_torsion_val_B.Gain_k[0] = 0.0;
    q_torsion_val_B.Gain_k[1] = 0.0;
    q_torsion_val_B.Clock = 0.0;
  }

  /* parameters */
  q_torsion_val_M->defaultParam = ((real_T *)&q_torsion_val_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &q_torsion_val_X;
    q_torsion_val_M->contStates = (x);
    (void) memset((void *)&q_torsion_val_X, 0,
                  sizeof(X_q_torsion_val_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &q_torsion_val_XDis;
    q_torsion_val_M->contStateDisabled = (xdis);
    (void) memset((void *)&q_torsion_val_XDis, 0,
                  sizeof(XDis_q_torsion_val_T));
  }

  /* states (dwork) */
  q_torsion_val_M->dwork = ((void *) &q_torsion_val_DW);
  (void) memset((void *)&q_torsion_val_DW, 0,
                sizeof(DW_q_torsion_val_T));
  q_torsion_val_DW.HILInitialize_AIMinimums[0] = 0.0;
  q_torsion_val_DW.HILInitialize_AIMinimums[1] = 0.0;
  q_torsion_val_DW.HILInitialize_AIMaximums[0] = 0.0;
  q_torsion_val_DW.HILInitialize_AIMaximums[1] = 0.0;
  q_torsion_val_DW.HILInitialize_AOMinimums[0] = 0.0;
  q_torsion_val_DW.HILInitialize_AOMinimums[1] = 0.0;
  q_torsion_val_DW.HILInitialize_AOMaximums[0] = 0.0;
  q_torsion_val_DW.HILInitialize_AOMaximums[1] = 0.0;
  q_torsion_val_DW.HILInitialize_AOVoltages[0] = 0.0;
  q_torsion_val_DW.HILInitialize_AOVoltages[1] = 0.0;
  q_torsion_val_DW.HILInitialize_FilterFrequency[0] = 0.0;
  q_torsion_val_DW.HILInitialize_FilterFrequency[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_torsion_val_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_torsion_val_M->Sizes.numContStates = (4);/* Number of continuous states */
  q_torsion_val_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  q_torsion_val_M->Sizes.numY = (0);   /* Number of model outputs */
  q_torsion_val_M->Sizes.numU = (0);   /* Number of model inputs */
  q_torsion_val_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_torsion_val_M->Sizes.numSampTimes = (2);/* Number of sample times */
  q_torsion_val_M->Sizes.numBlocks = (23);/* Number of blocks */
  q_torsion_val_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  q_torsion_val_M->Sizes.numBlockPrms = (122);/* Sum of parameter "widths" */
  return q_torsion_val_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
