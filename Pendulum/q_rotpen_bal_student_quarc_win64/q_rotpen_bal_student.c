/*
 * q_rotpen_bal_student.c
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
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
#include "q_rotpen_bal_student_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <float.h>
#include "q_rotpen_bal_student_dt.h"

/* Block signals (default storage) */
B_q_rotpen_bal_student_T q_rotpen_bal_student_B;

/* Continuous states */
X_q_rotpen_bal_student_T q_rotpen_bal_student_X;

/* Disabled State Vector */
XDis_q_rotpen_bal_student_T q_rotpen_bal_student_XDis;

/* Block states (default storage) */
DW_q_rotpen_bal_student_T q_rotpen_bal_student_DW;

/* Real-time model */
static RT_MODEL_q_rotpen_bal_student_T q_rotpen_bal_student_M_;
RT_MODEL_q_rotpen_bal_student_T *const q_rotpen_bal_student_M =
  &q_rotpen_bal_student_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  q_rotpen_bal_student_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model output function */
void q_rotpen_bal_student_output(void)
{
  __m128d tmp;
  real_T rtb_HILReadEncoderTimebase[2];
  real_T rtb_ConverttoVectorState_idx_0;
  real_T rtb_Gain1;
  if (rtmIsMajorTimeStep(q_rotpen_bal_student_M)) {
    /* set solver stop time */
    if (!(q_rotpen_bal_student_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_rotpen_bal_student_M->solverInfo,
                            ((q_rotpen_bal_student_M->Timing.clockTickH0 + 1) *
        q_rotpen_bal_student_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_rotpen_bal_student_M->solverInfo,
                            ((q_rotpen_bal_student_M->Timing.clockTick0 + 1) *
        q_rotpen_bal_student_M->Timing.stepSize0 +
        q_rotpen_bal_student_M->Timing.clockTickH0 *
        q_rotpen_bal_student_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_rotpen_bal_student_M)) {
    q_rotpen_bal_student_M->Timing.t[0] = rtsiGetT
      (&q_rotpen_bal_student_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_rotpen_bal_student_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

    /* S-Function Block: q_rotpen_bal_student/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (q_rotpen_bal_student_DW.HILReadEncoderTimebase_Task, 1,
         &q_rotpen_bal_student_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        rtb_HILReadEncoderTimebase[0] = 0;
        rtb_HILReadEncoderTimebase[1] = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase[0] =
          q_rotpen_bal_student_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase[1] =
          q_rotpen_bal_student_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Gain: '<S4>/Encoder Calibration  (rad//count)' */
    tmp = _mm_mul_pd(_mm_set1_pd(q_rotpen_bal_student_P.K_ENC), _mm_loadu_pd
                     (&rtb_HILReadEncoderTimebase[0]));

    /* Gain: '<S4>/Encoder Calibration  (rad//count)' */
    _mm_storeu_pd(&q_rotpen_bal_student_B.EncoderCalibrationradcount[0], tmp);

    /* Sum: '<S6>/Sum' incorporates:
     *  Constant: '<S6>/Mod Angle  (rad)'
     *  Constant: '<S6>/Offset Angle  (rad)'
     *  Math: '<S6>/Math Function'
     */
    q_rotpen_bal_student_B.Sum = rt_modd_snf
      (q_rotpen_bal_student_B.EncoderCalibrationradcount[1],
       q_rotpen_bal_student_P.ModAnglerad_Value) +
      q_rotpen_bal_student_P.OffsetAnglerad_Value;
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_Gain1 = q_rotpen_bal_student_P.SignalGenerator_Frequency *
    q_rotpen_bal_student_M->Timing.t[0];
  if (rtb_Gain1 - floor(rtb_Gain1) >= 0.5) {
    rtb_ConverttoVectorState_idx_0 =
      q_rotpen_bal_student_P.SignalGenerator_Amplitude;
  } else {
    rtb_ConverttoVectorState_idx_0 =
      -q_rotpen_bal_student_P.SignalGenerator_Amplitude;
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  Gain: '<Root>/Amplitude (deg)'
   *  SignalGenerator: '<Root>/Signal Generator'
   */
  rtb_Gain1 = q_rotpen_bal_student_P.Amplitudedeg_Gain *
    rtb_ConverttoVectorState_idx_0 * q_rotpen_bal_student_P.Gain1_Gain;

  /* Gain: '<Root>/Convert to  Vector State' */
  rtb_ConverttoVectorState_idx_0 =
    q_rotpen_bal_student_P.ConverttoVectorState_Gain[0] * rtb_Gain1;
  if (rtmIsMajorTimeStep(q_rotpen_bal_student_M)) {
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Abs: '<Root>/|alpha|'
     *  Constant: '<S2>/Constant'
     */
    q_rotpen_bal_student_B.Compare = (uint8_T)(fabs(q_rotpen_bal_student_B.Sum) <=
      q_rotpen_bal_student_P.epsilon);
  }

  /* Switch: '<Root>/Switch' */
  if (q_rotpen_bal_student_B.Compare > q_rotpen_bal_student_P.Switch_Threshold)
  {
    /* Switch: '<Root>/Switch' incorporates:
     *  Gain: '<Root>/Control  Gain'
     *  Gain: '<Root>/Convert to  Vector State'
     *  Sum: '<Root>/Sum'
     *  TransferFcn: '<S3>/HPF: alpha_dot (rad//s)'
     *  TransferFcn: '<S3>/HPF: theta_dot (rad//s)'
     */
    q_rotpen_bal_student_B.Switch =
      (((q_rotpen_bal_student_P.ConverttoVectorState_Gain[1] * rtb_Gain1 -
         q_rotpen_bal_student_B.Sum) * q_rotpen_bal_student_P.K[1] +
        (rtb_ConverttoVectorState_idx_0 -
         q_rotpen_bal_student_B.EncoderCalibrationradcount[0]) *
        q_rotpen_bal_student_P.K[0]) +
       (q_rotpen_bal_student_P.ConverttoVectorState_Gain[2] * rtb_Gain1 -
        (q_rotpen_bal_student_P.HPFtheta_dotrads_C *
         q_rotpen_bal_student_X.HPFtheta_dotrads_CSTATE +
         q_rotpen_bal_student_P.HPFtheta_dotrads_D *
         q_rotpen_bal_student_B.EncoderCalibrationradcount[0])) *
       q_rotpen_bal_student_P.K[2]) +
      (q_rotpen_bal_student_P.ConverttoVectorState_Gain[3] * rtb_Gain1 -
       (q_rotpen_bal_student_P.HPFalpha_dotrads_C *
        q_rotpen_bal_student_X.HPFalpha_dotrads_CSTATE +
        q_rotpen_bal_student_P.HPFalpha_dotrads_D * q_rotpen_bal_student_B.Sum))
      * q_rotpen_bal_student_P.K[3];
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/u = 0V'
     */
    q_rotpen_bal_student_B.Switch = q_rotpen_bal_student_P.u0V_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Gain: '<S4>/Direction Convention: (Right-Hand) system' */
  rtb_Gain1 = q_rotpen_bal_student_P.DirectionConventionRightHandsys *
    q_rotpen_bal_student_B.Switch;

  /* Saturate: '<S4>/Amplifier  Saturation (V)' */
  if (rtb_Gain1 > q_rotpen_bal_student_P.AmplifierSaturationV_UpperSat) {
    rtb_Gain1 = q_rotpen_bal_student_P.AmplifierSaturationV_UpperSat;
  } else if (rtb_Gain1 < q_rotpen_bal_student_P.AmplifierSaturationV_LowerSat) {
    rtb_Gain1 = q_rotpen_bal_student_P.AmplifierSaturationV_LowerSat;
  }

  /* Gain: '<S4>/Inverse Amplifier  Gain (V//V)' incorporates:
   *  Saturate: '<S4>/Amplifier  Saturation (V)'
   */
  q_rotpen_bal_student_B.InverseAmplifierGainVV = 1.0 /
    q_rotpen_bal_student_P.K_AMP * rtb_Gain1;
  if (rtmIsMajorTimeStep(q_rotpen_bal_student_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: q_rotpen_bal_student/Rotary Pendulum Interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_rotpen_bal_student_DW.HILInitialize_Card,
        &q_rotpen_bal_student_P.HILWriteAnalog_channels, 1,
        &q_rotpen_bal_student_B.InverseAmplifierGainVV);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
      }
    }

    /* Gain: '<S7>/Gain' */
    q_rotpen_bal_student_B.Gain = q_rotpen_bal_student_P.Gain_Gain *
      q_rotpen_bal_student_B.Sum;
  }

  /* Gain: '<S8>/Gain' */
  q_rotpen_bal_student_B.Gain_a[0] = q_rotpen_bal_student_P.Gain_Gain_n *
    rtb_ConverttoVectorState_idx_0;
  q_rotpen_bal_student_B.Gain_a[1] = q_rotpen_bal_student_P.Gain_Gain_n *
    q_rotpen_bal_student_B.EncoderCalibrationradcount[0];
  if (rtmIsMajorTimeStep(q_rotpen_bal_student_M)) {
  }
}

/* Model update function */
void q_rotpen_bal_student_update(void)
{
  if (rtmIsMajorTimeStep(q_rotpen_bal_student_M)) {
    rt_ertODEUpdateContinuousStates(&q_rotpen_bal_student_M->solverInfo);
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
  if (!(++q_rotpen_bal_student_M->Timing.clockTick0)) {
    ++q_rotpen_bal_student_M->Timing.clockTickH0;
  }

  q_rotpen_bal_student_M->Timing.t[0] = rtsiGetSolverStopTime
    (&q_rotpen_bal_student_M->solverInfo);

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
    if (!(++q_rotpen_bal_student_M->Timing.clockTick1)) {
      ++q_rotpen_bal_student_M->Timing.clockTickH1;
    }

    q_rotpen_bal_student_M->Timing.t[1] =
      q_rotpen_bal_student_M->Timing.clockTick1 *
      q_rotpen_bal_student_M->Timing.stepSize1 +
      q_rotpen_bal_student_M->Timing.clockTickH1 *
      q_rotpen_bal_student_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void q_rotpen_bal_student_derivatives(void)
{
  XDot_q_rotpen_bal_student_T *_rtXdot;
  _rtXdot = ((XDot_q_rotpen_bal_student_T *) q_rotpen_bal_student_M->derivs);

  /* Derivatives for TransferFcn: '<S3>/HPF: theta_dot (rad//s)' */
  _rtXdot->HPFtheta_dotrads_CSTATE = q_rotpen_bal_student_P.HPFtheta_dotrads_A *
    q_rotpen_bal_student_X.HPFtheta_dotrads_CSTATE;
  _rtXdot->HPFtheta_dotrads_CSTATE +=
    q_rotpen_bal_student_B.EncoderCalibrationradcount[0];

  /* Derivatives for TransferFcn: '<S3>/HPF: alpha_dot (rad//s)' */
  _rtXdot->HPFalpha_dotrads_CSTATE = q_rotpen_bal_student_P.HPFalpha_dotrads_A *
    q_rotpen_bal_student_X.HPFalpha_dotrads_CSTATE;
  _rtXdot->HPFalpha_dotrads_CSTATE += q_rotpen_bal_student_B.Sum;
}

/* Model initialize function */
void q_rotpen_bal_student_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: q_rotpen_bal_student/Rotary Pendulum Interface/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &q_rotpen_bal_student_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (q_rotpen_bal_student_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(q_rotpen_bal_student_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
      return;
    }

    if ((q_rotpen_bal_student_P.HILInitialize_AIPStart && !is_switching) ||
        (q_rotpen_bal_student_P.HILInitialize_AIPEnter && is_switching)) {
      q_rotpen_bal_student_DW.HILInitialize_AIMinimums[0] =
        (q_rotpen_bal_student_P.HILInitialize_AILow);
      q_rotpen_bal_student_DW.HILInitialize_AIMinimums[1] =
        (q_rotpen_bal_student_P.HILInitialize_AILow);
      q_rotpen_bal_student_DW.HILInitialize_AIMaximums[0] =
        q_rotpen_bal_student_P.HILInitialize_AIHigh;
      q_rotpen_bal_student_DW.HILInitialize_AIMaximums[1] =
        q_rotpen_bal_student_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (q_rotpen_bal_student_DW.HILInitialize_Card,
         q_rotpen_bal_student_P.HILInitialize_AIChannels, 2U,
         &q_rotpen_bal_student_DW.HILInitialize_AIMinimums[0],
         &q_rotpen_bal_student_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
        return;
      }
    }

    if ((q_rotpen_bal_student_P.HILInitialize_AOPStart && !is_switching) ||
        (q_rotpen_bal_student_P.HILInitialize_AOPEnter && is_switching)) {
      q_rotpen_bal_student_DW.HILInitialize_AOMinimums[0] =
        (q_rotpen_bal_student_P.HILInitialize_AOLow);
      q_rotpen_bal_student_DW.HILInitialize_AOMinimums[1] =
        (q_rotpen_bal_student_P.HILInitialize_AOLow);
      q_rotpen_bal_student_DW.HILInitialize_AOMaximums[0] =
        q_rotpen_bal_student_P.HILInitialize_AOHigh;
      q_rotpen_bal_student_DW.HILInitialize_AOMaximums[1] =
        q_rotpen_bal_student_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (q_rotpen_bal_student_DW.HILInitialize_Card,
         q_rotpen_bal_student_P.HILInitialize_AOChannels, 2U,
         &q_rotpen_bal_student_DW.HILInitialize_AOMinimums[0],
         &q_rotpen_bal_student_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
        return;
      }
    }

    if ((q_rotpen_bal_student_P.HILInitialize_AOStart && !is_switching) ||
        (q_rotpen_bal_student_P.HILInitialize_AOEnter && is_switching)) {
      q_rotpen_bal_student_DW.HILInitialize_AOVoltages[0] =
        q_rotpen_bal_student_P.HILInitialize_AOInitial;
      q_rotpen_bal_student_DW.HILInitialize_AOVoltages[1] =
        q_rotpen_bal_student_P.HILInitialize_AOInitial;
      result = hil_write_analog(q_rotpen_bal_student_DW.HILInitialize_Card,
        q_rotpen_bal_student_P.HILInitialize_AOChannels, 2U,
        &q_rotpen_bal_student_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
        return;
      }
    }

    if (q_rotpen_bal_student_P.HILInitialize_AOReset) {
      q_rotpen_bal_student_DW.HILInitialize_AOVoltages[0] =
        q_rotpen_bal_student_P.HILInitialize_AOWatchdog;
      q_rotpen_bal_student_DW.HILInitialize_AOVoltages[1] =
        q_rotpen_bal_student_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (q_rotpen_bal_student_DW.HILInitialize_Card,
         q_rotpen_bal_student_P.HILInitialize_AOChannels, 2U,
         &q_rotpen_bal_student_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
        return;
      }
    }

    if ((q_rotpen_bal_student_P.HILInitialize_EIPStart && !is_switching) ||
        (q_rotpen_bal_student_P.HILInitialize_EIPEnter && is_switching)) {
      q_rotpen_bal_student_DW.HILInitialize_QuadratureModes[0] =
        q_rotpen_bal_student_P.HILInitialize_EIQuadrature;
      q_rotpen_bal_student_DW.HILInitialize_QuadratureModes[1] =
        q_rotpen_bal_student_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (q_rotpen_bal_student_DW.HILInitialize_Card,
         q_rotpen_bal_student_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &q_rotpen_bal_student_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
        return;
      }
    }

    if ((q_rotpen_bal_student_P.HILInitialize_EIStart && !is_switching) ||
        (q_rotpen_bal_student_P.HILInitialize_EIEnter && is_switching)) {
      q_rotpen_bal_student_DW.HILInitialize_InitialEICounts[0] =
        q_rotpen_bal_student_P.HILInitialize_EIInitial;
      q_rotpen_bal_student_DW.HILInitialize_InitialEICounts[1] =
        q_rotpen_bal_student_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(q_rotpen_bal_student_DW.HILInitialize_Card,
        q_rotpen_bal_student_P.HILInitialize_EIChannels, 2U,
        &q_rotpen_bal_student_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_rotpen_bal_student/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (q_rotpen_bal_student_DW.HILInitialize_Card,
       q_rotpen_bal_student_P.HILReadEncoderTimebase_SamplesI,
       q_rotpen_bal_student_P.HILReadEncoderTimebase_Channels, 2,
       &q_rotpen_bal_student_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (q_rotpen_bal_student_DW.HILReadEncoderTimebase_Task,
         (t_buffer_overflow_mode)
         (q_rotpen_bal_student_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<S3>/HPF: theta_dot (rad//s)' */
  q_rotpen_bal_student_X.HPFtheta_dotrads_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/HPF: alpha_dot (rad//s)' */
  q_rotpen_bal_student_X.HPFalpha_dotrads_CSTATE = 0.0;
}

/* Model terminate function */
void q_rotpen_bal_student_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S4>/HIL Initialize' */

  /* S-Function Block: q_rotpen_bal_student/Rotary Pendulum Interface/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(q_rotpen_bal_student_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_rotpen_bal_student_DW.HILInitialize_Card);
    is_switching = false;
    if ((q_rotpen_bal_student_P.HILInitialize_AOTerminate && !is_switching) ||
        (q_rotpen_bal_student_P.HILInitialize_AOExit && is_switching)) {
      q_rotpen_bal_student_DW.HILInitialize_AOVoltages[0] =
        q_rotpen_bal_student_P.HILInitialize_AOFinal;
      q_rotpen_bal_student_DW.HILInitialize_AOVoltages[1] =
        q_rotpen_bal_student_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(q_rotpen_bal_student_DW.HILInitialize_Card,
        q_rotpen_bal_student_P.HILInitialize_AOChannels,
        num_final_analog_outputs,
        &q_rotpen_bal_student_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_rotpen_bal_student_M, _rt_error_message);
      }
    }

    hil_task_delete_all(q_rotpen_bal_student_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_rotpen_bal_student_DW.HILInitialize_Card);
    hil_close(q_rotpen_bal_student_DW.HILInitialize_Card);
    q_rotpen_bal_student_DW.HILInitialize_Card = NULL;
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
  q_rotpen_bal_student_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  q_rotpen_bal_student_update();
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
  q_rotpen_bal_student_initialize();
}

void MdlTerminate(void)
{
  q_rotpen_bal_student_terminate();
}

/* Registration function */
RT_MODEL_q_rotpen_bal_student_T *q_rotpen_bal_student(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_rotpen_bal_student_M, 0,
                sizeof(RT_MODEL_q_rotpen_bal_student_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_rotpen_bal_student_M->solverInfo,
                          &q_rotpen_bal_student_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_rotpen_bal_student_M->solverInfo, &rtmGetTPtr
                (q_rotpen_bal_student_M));
    rtsiSetStepSizePtr(&q_rotpen_bal_student_M->solverInfo,
                       &q_rotpen_bal_student_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_rotpen_bal_student_M->solverInfo,
                 &q_rotpen_bal_student_M->derivs);
    rtsiSetContStatesPtr(&q_rotpen_bal_student_M->solverInfo, (real_T **)
                         &q_rotpen_bal_student_M->contStates);
    rtsiSetNumContStatesPtr(&q_rotpen_bal_student_M->solverInfo,
      &q_rotpen_bal_student_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&q_rotpen_bal_student_M->solverInfo,
      &q_rotpen_bal_student_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&q_rotpen_bal_student_M->solverInfo,
      &q_rotpen_bal_student_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&q_rotpen_bal_student_M->solverInfo,
      &q_rotpen_bal_student_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&q_rotpen_bal_student_M->solverInfo, (boolean_T**)
      &q_rotpen_bal_student_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&q_rotpen_bal_student_M->solverInfo,
                          (&rtmGetErrorStatus(q_rotpen_bal_student_M)));
    rtsiSetRTModelPtr(&q_rotpen_bal_student_M->solverInfo,
                      q_rotpen_bal_student_M);
  }

  rtsiSetSimTimeStep(&q_rotpen_bal_student_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&q_rotpen_bal_student_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&q_rotpen_bal_student_M->solverInfo, false);
  q_rotpen_bal_student_M->intgData.f[0] = q_rotpen_bal_student_M->odeF[0];
  q_rotpen_bal_student_M->contStates = ((real_T *) &q_rotpen_bal_student_X);
  q_rotpen_bal_student_M->contStateDisabled = ((boolean_T *)
    &q_rotpen_bal_student_XDis);
  q_rotpen_bal_student_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&q_rotpen_bal_student_M->solverInfo, (void *)
                    &q_rotpen_bal_student_M->intgData);
  rtsiSetSolverName(&q_rotpen_bal_student_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_rotpen_bal_student_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "q_rotpen_bal_student_M points to
       static memory which is guaranteed to be non-NULL" */
    q_rotpen_bal_student_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_rotpen_bal_student_M->Timing.sampleTimes =
      (&q_rotpen_bal_student_M->Timing.sampleTimesArray[0]);
    q_rotpen_bal_student_M->Timing.offsetTimes =
      (&q_rotpen_bal_student_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_rotpen_bal_student_M->Timing.sampleTimes[0] = (0.0);
    q_rotpen_bal_student_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    q_rotpen_bal_student_M->Timing.offsetTimes[0] = (0.0);
    q_rotpen_bal_student_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(q_rotpen_bal_student_M, &q_rotpen_bal_student_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_rotpen_bal_student_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    q_rotpen_bal_student_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_rotpen_bal_student_M, -1);
  q_rotpen_bal_student_M->Timing.stepSize0 = 0.002;
  q_rotpen_bal_student_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  q_rotpen_bal_student_M->Sizes.checksums[0] = (603306102U);
  q_rotpen_bal_student_M->Sizes.checksums[1] = (1913323609U);
  q_rotpen_bal_student_M->Sizes.checksums[2] = (2617916755U);
  q_rotpen_bal_student_M->Sizes.checksums[3] = (4099299386U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    q_rotpen_bal_student_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_rotpen_bal_student_M->extModeInfo,
      &q_rotpen_bal_student_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_rotpen_bal_student_M->extModeInfo,
                        q_rotpen_bal_student_M->Sizes.checksums);
    rteiSetTPtr(q_rotpen_bal_student_M->extModeInfo, rtmGetTPtr
                (q_rotpen_bal_student_M));
  }

  q_rotpen_bal_student_M->solverInfoPtr = (&q_rotpen_bal_student_M->solverInfo);
  q_rotpen_bal_student_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&q_rotpen_bal_student_M->solverInfo, 0.002);
  rtsiSetSolverMode(&q_rotpen_bal_student_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  q_rotpen_bal_student_M->blockIO = ((void *) &q_rotpen_bal_student_B);
  (void) memset(((void *) &q_rotpen_bal_student_B), 0,
                sizeof(B_q_rotpen_bal_student_T));

  {
    q_rotpen_bal_student_B.EncoderCalibrationradcount[0] = 0.0;
    q_rotpen_bal_student_B.EncoderCalibrationradcount[1] = 0.0;
    q_rotpen_bal_student_B.Sum = 0.0;
    q_rotpen_bal_student_B.Switch = 0.0;
    q_rotpen_bal_student_B.InverseAmplifierGainVV = 0.0;
    q_rotpen_bal_student_B.Gain = 0.0;
    q_rotpen_bal_student_B.Gain_a[0] = 0.0;
    q_rotpen_bal_student_B.Gain_a[1] = 0.0;
  }

  /* parameters */
  q_rotpen_bal_student_M->defaultParam = ((real_T *)&q_rotpen_bal_student_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &q_rotpen_bal_student_X;
    q_rotpen_bal_student_M->contStates = (x);
    (void) memset((void *)&q_rotpen_bal_student_X, 0,
                  sizeof(X_q_rotpen_bal_student_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &q_rotpen_bal_student_XDis;
    q_rotpen_bal_student_M->contStateDisabled = (xdis);
    (void) memset((void *)&q_rotpen_bal_student_XDis, 0,
                  sizeof(XDis_q_rotpen_bal_student_T));
  }

  /* states (dwork) */
  q_rotpen_bal_student_M->dwork = ((void *) &q_rotpen_bal_student_DW);
  (void) memset((void *)&q_rotpen_bal_student_DW, 0,
                sizeof(DW_q_rotpen_bal_student_T));
  q_rotpen_bal_student_DW.HILInitialize_AIMinimums[0] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AIMinimums[1] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AIMaximums[0] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AIMaximums[1] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AOMinimums[0] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AOMinimums[1] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AOMaximums[0] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AOMaximums[1] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AOVoltages[0] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_AOVoltages[1] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_FilterFrequency[0] = 0.0;
  q_rotpen_bal_student_DW.HILInitialize_FilterFrequency[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_rotpen_bal_student_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_rotpen_bal_student_M->Sizes.numContStates = (2);/* Number of continuous states */
  q_rotpen_bal_student_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  q_rotpen_bal_student_M->Sizes.numY = (0);/* Number of model outputs */
  q_rotpen_bal_student_M->Sizes.numU = (0);/* Number of model inputs */
  q_rotpen_bal_student_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_rotpen_bal_student_M->Sizes.numSampTimes = (2);/* Number of sample times */
  q_rotpen_bal_student_M->Sizes.numBlocks = (30);/* Number of blocks */
  q_rotpen_bal_student_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  q_rotpen_bal_student_M->Sizes.numBlockPrms = (99);/* Sum of parameter "widths" */
  return q_rotpen_bal_student_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
