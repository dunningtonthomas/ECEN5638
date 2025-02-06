/*
 * q_gyro.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_gyro".
 *
 * Model version              : 27.0
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Feb  6 13:17:21 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_gyro.h"
#include "rtwtypes.h"
#include "q_gyro_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "q_gyro_dt.h"

/* Block signals (default storage) */
B_q_gyro_T q_gyro_B;

/* Continuous states */
X_q_gyro_T q_gyro_X;

/* Disabled State Vector */
XDis_q_gyro_T q_gyro_XDis;

/* Block states (default storage) */
DW_q_gyro_T q_gyro_DW;

/* Real-time model */
static RT_MODEL_q_gyro_T q_gyro_M_;
RT_MODEL_q_gyro_T *const q_gyro_M = &q_gyro_M_;

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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  q_gyro_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void q_gyro_output(void)
{
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(q_gyro_M)) {
    /* set solver stop time */
    if (!(q_gyro_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_gyro_M->solverInfo,
                            ((q_gyro_M->Timing.clockTickH0 + 1) *
        q_gyro_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_gyro_M->solverInfo, ((q_gyro_M->Timing.clockTick0
        + 1) * q_gyro_M->Timing.stepSize0 + q_gyro_M->Timing.clockTickH0 *
        q_gyro_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_gyro_M)) {
    q_gyro_M->Timing.t[0] = rtsiGetT(&q_gyro_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_gyro_M)) {
    /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder' */

    /* S-Function Block: q_gyro/SRV02 Gyroscope/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(q_gyro_DW.HILInitialize_Card,
        q_gyro_P.HILReadEncoder_channels, 2, &q_gyro_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
      } else {
        q_gyro_B.HILReadEncoder_o1 = q_gyro_DW.HILReadEncoder_Buffer[0];
        q_gyro_B.HILReadEncoder_o2 = q_gyro_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S1>/GYRO-E: counts to rad' */
    q_gyro_B.GYROEcountstorad = q_gyro_P.K_ENC * q_gyro_B.HILReadEncoder_o2;

    /* Gain: '<S1>/Gear ratio' */
    q_gyro_B.Gearratio = q_gyro_P.Gearratio_Gain * q_gyro_B.GYROEcountstorad;

    /* Gain: '<Root>/Neg. Fdbk' */
    q_gyro_B.seps = q_gyro_P.NegFdbk_Gain * q_gyro_B.Gearratio;

    /* Gain: '<Root>/Derivative Gain' */
    q_gyro_B.DerivativeGain = q_gyro_P.kd * q_gyro_B.seps;
  }

  /* Integrator: '<Root>/epsilon = alpha//s' */
  /* Limited  Integrator  */
  if (q_gyro_X.epsilonalphas_CSTATE >= q_gyro_P.epsilonalphas_UpperSat) {
    q_gyro_X.epsilonalphas_CSTATE = q_gyro_P.epsilonalphas_UpperSat;
  } else if (q_gyro_X.epsilonalphas_CSTATE <= q_gyro_P.epsilonalphas_LowerSat) {
    q_gyro_X.epsilonalphas_CSTATE = q_gyro_P.epsilonalphas_LowerSat;
  }

  /* Integrator: '<Root>/epsilon = alpha//s' */
  q_gyro_B.epsilon = q_gyro_X.epsilonalphas_CSTATE;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (q_gyro_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Control OFF'
     */
    q_gyro_B.ManualSwitch = q_gyro_P.ControlOFF_Value;
  } else {
    /* Gain: '<Root>/Negative Feedback' */
    q_gyro_B.epsilon_h = q_gyro_P.NegativeFeedback_Gain * q_gyro_B.epsilon;

    /* Gain: '<Root>/Proportional Gain' */
    q_gyro_B.ProportionalGain = q_gyro_P.kp * q_gyro_B.epsilon_h;

    /* Sum: '<Root>/Add' */
    q_gyro_B.Add = q_gyro_B.DerivativeGain + q_gyro_B.ProportionalGain;

    /* ManualSwitch: '<Root>/Manual Switch' */
    q_gyro_B.ManualSwitch = q_gyro_B.Add;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<S4>/Direction Convention: (Right-Hand) system' */
  q_gyro_B.DirectionConventionRightHandsys =
    q_gyro_P.DirectionConventionRightHandsys * q_gyro_B.ManualSwitch;

  /* Saturate: '<S4>/Amplifier  Saturation (V)' */
  u1 = -q_gyro_P.VMAX_AMP;
  u0 = q_gyro_B.DirectionConventionRightHandsys;
  u2 = q_gyro_P.VMAX_AMP;
  if (u0 > u2) {
    /* Saturate: '<S4>/Amplifier  Saturation (V)' */
    q_gyro_B.AmplifierSaturationV = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S4>/Amplifier  Saturation (V)' */
    q_gyro_B.AmplifierSaturationV = u1;
  } else {
    /* Saturate: '<S4>/Amplifier  Saturation (V)' */
    q_gyro_B.AmplifierSaturationV = u0;
  }

  /* End of Saturate: '<S4>/Amplifier  Saturation (V)' */

  /* Gain: '<S4>/Inverse Amplifier  Gain (V//V)' */
  u1 = 1.0 / q_gyro_P.K_AMP;

  /* Gain: '<S4>/Inverse Amplifier  Gain (V//V)' */
  q_gyro_B.InverseAmplifierGainVV = u1 * q_gyro_B.AmplifierSaturationV;

  /* Saturate: '<S4>/DACB Saturation (V)' */
  u1 = -q_gyro_P.VMAX_DAC;
  u0 = q_gyro_B.InverseAmplifierGainVV;
  u2 = q_gyro_P.VMAX_DAC;
  if (u0 > u2) {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    q_gyro_B.DACBSaturationV = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    q_gyro_B.DACBSaturationV = u1;
  } else {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    q_gyro_B.DACBSaturationV = u0;
  }

  /* End of Saturate: '<S4>/DACB Saturation (V)' */
  if (rtmIsMajorTimeStep(q_gyro_M)) {
    /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

    /* S-Function Block: q_gyro/SRV02 Gyroscope/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_gyro_DW.HILInitialize_Card,
        &q_gyro_P.HILWriteAnalog_channels, 1, &q_gyro_B.DACBSaturationV);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S4>/Amplifier  Gain (V//V)' */
  u1 = -q_gyro_P.K_AMP;

  /* Gain: '<S4>/Amplifier  Gain (V//V)' */
  q_gyro_B.AmplifierGainVV = u1 * q_gyro_B.DACBSaturationV;
  if (rtmIsMajorTimeStep(q_gyro_M)) {
    /* Gain: '<S1>/SRV02: counts to rad' */
    q_gyro_B.SRV02countstorad = q_gyro_P.K_ENC * q_gyro_B.HILReadEncoder_o1;

    /* S-Function (hil_write_digital_block): '<S1>/HIL Write Digital' incorporates:
     *  Constant: '<S1>/Enable VoltPAQ-X2,X4'
     */

    /* S-Function Block: q_gyro/SRV02 Gyroscope/HIL Write Digital (hil_write_digital_block) */
    {
      t_error result;
      q_gyro_DW.HILWriteDigital_Buffer[0] = (q_gyro_P.EnableVoltPAQX2X4_Value[0]
        != 0);
      q_gyro_DW.HILWriteDigital_Buffer[1] = (q_gyro_P.EnableVoltPAQX2X4_Value[1]
        != 0);
      q_gyro_DW.HILWriteDigital_Buffer[2] = (q_gyro_P.EnableVoltPAQX2X4_Value[2]
        != 0);
      q_gyro_DW.HILWriteDigital_Buffer[3] = (q_gyro_P.EnableVoltPAQX2X4_Value[3]
        != 0);
      result = hil_write_digital(q_gyro_DW.HILInitialize_Card,
        q_gyro_P.HILWriteDigital_channels, 4, &q_gyro_DW.HILWriteDigital_Buffer
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
      }
    }

    /* Gain: '<S2>/Gain' */
    q_gyro_B.Gain = q_gyro_P.Gain_Gain * q_gyro_B.Gearratio;

    /* Gain: '<S3>/Gain' */
    q_gyro_B.Gain_i = q_gyro_P.Gain_Gain_f * q_gyro_B.SRV02countstorad;
  }
}

/* Model update function */
void q_gyro_update(void)
{
  if (rtmIsMajorTimeStep(q_gyro_M)) {
    rt_ertODEUpdateContinuousStates(&q_gyro_M->solverInfo);
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
  if (!(++q_gyro_M->Timing.clockTick0)) {
    ++q_gyro_M->Timing.clockTickH0;
  }

  q_gyro_M->Timing.t[0] = rtsiGetSolverStopTime(&q_gyro_M->solverInfo);

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
    if (!(++q_gyro_M->Timing.clockTick1)) {
      ++q_gyro_M->Timing.clockTickH1;
    }

    q_gyro_M->Timing.t[1] = q_gyro_M->Timing.clockTick1 *
      q_gyro_M->Timing.stepSize1 + q_gyro_M->Timing.clockTickH1 *
      q_gyro_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void q_gyro_derivatives(void)
{
  XDot_q_gyro_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_q_gyro_T *) q_gyro_M->derivs);

  /* Derivatives for Integrator: '<Root>/epsilon = alpha//s' */
  lsat = (q_gyro_X.epsilonalphas_CSTATE <= q_gyro_P.epsilonalphas_LowerSat);
  usat = (q_gyro_X.epsilonalphas_CSTATE >= q_gyro_P.epsilonalphas_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (q_gyro_B.Gearratio > 0.0)) || (usat &&
       (q_gyro_B.Gearratio < 0.0))) {
    _rtXdot->epsilonalphas_CSTATE = q_gyro_B.Gearratio;
  } else {
    /* in saturation */
    _rtXdot->epsilonalphas_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<Root>/epsilon = alpha//s' */
}

/* Model initialize function */
void q_gyro_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_gyro/SRV02 Gyroscope/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &q_gyro_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_gyro_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(q_gyro_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal", 50);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_gyro_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(q_gyro_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_gyro_M, _rt_error_message);
      return;
    }

    if ((q_gyro_P.HILInitialize_AIPStart && !is_switching) ||
        (q_gyro_P.HILInitialize_AIPEnter && is_switching)) {
      q_gyro_DW.HILInitialize_AIMinimums[0] = (q_gyro_P.HILInitialize_AILow);
      q_gyro_DW.HILInitialize_AIMinimums[1] = (q_gyro_P.HILInitialize_AILow);
      q_gyro_DW.HILInitialize_AIMaximums[0] = q_gyro_P.HILInitialize_AIHigh;
      q_gyro_DW.HILInitialize_AIMaximums[1] = q_gyro_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(q_gyro_DW.HILInitialize_Card,
        q_gyro_P.HILInitialize_AIChannels, 2U,
        &q_gyro_DW.HILInitialize_AIMinimums[0],
        &q_gyro_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        return;
      }
    }

    if ((q_gyro_P.HILInitialize_AOPStart && !is_switching) ||
        (q_gyro_P.HILInitialize_AOPEnter && is_switching)) {
      q_gyro_DW.HILInitialize_AOMinimums[0] = (q_gyro_P.HILInitialize_AOLow);
      q_gyro_DW.HILInitialize_AOMinimums[1] = (q_gyro_P.HILInitialize_AOLow);
      q_gyro_DW.HILInitialize_AOMaximums[0] = q_gyro_P.HILInitialize_AOHigh;
      q_gyro_DW.HILInitialize_AOMaximums[1] = q_gyro_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(q_gyro_DW.HILInitialize_Card,
        q_gyro_P.HILInitialize_AOChannels, 2U,
        &q_gyro_DW.HILInitialize_AOMinimums[0],
        &q_gyro_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        return;
      }
    }

    if ((q_gyro_P.HILInitialize_AOStart && !is_switching) ||
        (q_gyro_P.HILInitialize_AOEnter && is_switching)) {
      q_gyro_DW.HILInitialize_AOVoltages[0] = q_gyro_P.HILInitialize_AOInitial;
      q_gyro_DW.HILInitialize_AOVoltages[1] = q_gyro_P.HILInitialize_AOInitial;
      result = hil_write_analog(q_gyro_DW.HILInitialize_Card,
        q_gyro_P.HILInitialize_AOChannels, 2U,
        &q_gyro_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        return;
      }
    }

    if (q_gyro_P.HILInitialize_AOReset) {
      q_gyro_DW.HILInitialize_AOVoltages[0] = q_gyro_P.HILInitialize_AOWatchdog;
      q_gyro_DW.HILInitialize_AOVoltages[1] = q_gyro_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (q_gyro_DW.HILInitialize_Card, q_gyro_P.HILInitialize_AOChannels, 2U,
         &q_gyro_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(q_gyro_DW.HILInitialize_Card, NULL, 0U,
      q_gyro_P.HILInitialize_DOChannels, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_gyro_M, _rt_error_message);
      return;
    }

    if ((q_gyro_P.HILInitialize_DOStart && !is_switching) ||
        (q_gyro_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &q_gyro_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = q_gyro_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(q_gyro_DW.HILInitialize_Card,
        q_gyro_P.HILInitialize_DOChannels, 8U, (t_boolean *)
        &q_gyro_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        return;
      }
    }

    if (q_gyro_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &q_gyro_DW.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = q_gyro_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (q_gyro_DW.HILInitialize_Card, q_gyro_P.HILInitialize_DOChannels, 8U, (
          const t_digital_state *) &q_gyro_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        return;
      }
    }

    if ((q_gyro_P.HILInitialize_EIPStart && !is_switching) ||
        (q_gyro_P.HILInitialize_EIPEnter && is_switching)) {
      q_gyro_DW.HILInitialize_QuadratureModes[0] =
        q_gyro_P.HILInitialize_EIQuadrature;
      q_gyro_DW.HILInitialize_QuadratureModes[1] =
        q_gyro_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(q_gyro_DW.HILInitialize_Card,
        q_gyro_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &q_gyro_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        return;
      }
    }

    if ((q_gyro_P.HILInitialize_EIStart && !is_switching) ||
        (q_gyro_P.HILInitialize_EIEnter && is_switching)) {
      q_gyro_DW.HILInitialize_InitialEICounts[0] =
        q_gyro_P.HILInitialize_EIInitial;
      q_gyro_DW.HILInitialize_InitialEICounts[1] =
        q_gyro_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(q_gyro_DW.HILInitialize_Card,
        q_gyro_P.HILInitialize_EIChannels, 2U,
        &q_gyro_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<Root>/epsilon = alpha//s' */
  q_gyro_X.epsilonalphas_CSTATE = q_gyro_P.epsilonalphas_IC;
}

/* Model terminate function */
void q_gyro_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_gyro/SRV02 Gyroscope/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(q_gyro_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_gyro_DW.HILInitialize_Card);
    is_switching = false;
    if ((q_gyro_P.HILInitialize_AOTerminate && !is_switching) ||
        (q_gyro_P.HILInitialize_AOExit && is_switching)) {
      q_gyro_DW.HILInitialize_AOVoltages[0] = q_gyro_P.HILInitialize_AOFinal;
      q_gyro_DW.HILInitialize_AOVoltages[1] = q_gyro_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((q_gyro_P.HILInitialize_DOTerminate && !is_switching) ||
        (q_gyro_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &q_gyro_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = q_gyro_P.HILInitialize_DOFinal;
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
      result = hil_write(q_gyro_DW.HILInitialize_Card
                         , q_gyro_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , q_gyro_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &q_gyro_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *) &q_gyro_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(q_gyro_DW.HILInitialize_Card,
            q_gyro_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &q_gyro_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(q_gyro_DW.HILInitialize_Card,
            q_gyro_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &q_gyro_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_gyro_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(q_gyro_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_gyro_DW.HILInitialize_Card);
    hil_close(q_gyro_DW.HILInitialize_Card);
    q_gyro_DW.HILInitialize_Card = NULL;
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
  q_gyro_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  q_gyro_update();
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
  q_gyro_initialize();
}

void MdlTerminate(void)
{
  q_gyro_terminate();
}

/* Registration function */
RT_MODEL_q_gyro_T *q_gyro(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_gyro_M, 0,
                sizeof(RT_MODEL_q_gyro_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_gyro_M->solverInfo, &q_gyro_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_gyro_M->solverInfo, &rtmGetTPtr(q_gyro_M));
    rtsiSetStepSizePtr(&q_gyro_M->solverInfo, &q_gyro_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_gyro_M->solverInfo, &q_gyro_M->derivs);
    rtsiSetContStatesPtr(&q_gyro_M->solverInfo, (real_T **)
                         &q_gyro_M->contStates);
    rtsiSetNumContStatesPtr(&q_gyro_M->solverInfo,
      &q_gyro_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&q_gyro_M->solverInfo,
      &q_gyro_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&q_gyro_M->solverInfo,
      &q_gyro_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&q_gyro_M->solverInfo,
      &q_gyro_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&q_gyro_M->solverInfo, (boolean_T**)
      &q_gyro_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&q_gyro_M->solverInfo, (&rtmGetErrorStatus(q_gyro_M)));
    rtsiSetRTModelPtr(&q_gyro_M->solverInfo, q_gyro_M);
  }

  rtsiSetSimTimeStep(&q_gyro_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&q_gyro_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&q_gyro_M->solverInfo, false);
  q_gyro_M->intgData.f[0] = q_gyro_M->odeF[0];
  q_gyro_M->contStates = ((real_T *) &q_gyro_X);
  q_gyro_M->contStateDisabled = ((boolean_T *) &q_gyro_XDis);
  q_gyro_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&q_gyro_M->solverInfo, (void *)&q_gyro_M->intgData);
  rtsiSetSolverName(&q_gyro_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_gyro_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "q_gyro_M points to
       static memory which is guaranteed to be non-NULL" */
    q_gyro_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_gyro_M->Timing.sampleTimes = (&q_gyro_M->Timing.sampleTimesArray[0]);
    q_gyro_M->Timing.offsetTimes = (&q_gyro_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_gyro_M->Timing.sampleTimes[0] = (0.0);
    q_gyro_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    q_gyro_M->Timing.offsetTimes[0] = (0.0);
    q_gyro_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(q_gyro_M, &q_gyro_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_gyro_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    q_gyro_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_gyro_M, -1);
  q_gyro_M->Timing.stepSize0 = 0.002;
  q_gyro_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  q_gyro_M->Sizes.checksums[0] = (4274244631U);
  q_gyro_M->Sizes.checksums[1] = (2560633345U);
  q_gyro_M->Sizes.checksums[2] = (2696968552U);
  q_gyro_M->Sizes.checksums[3] = (3237162321U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    q_gyro_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_gyro_M->extModeInfo,
      &q_gyro_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_gyro_M->extModeInfo, q_gyro_M->Sizes.checksums);
    rteiSetTPtr(q_gyro_M->extModeInfo, rtmGetTPtr(q_gyro_M));
  }

  q_gyro_M->solverInfoPtr = (&q_gyro_M->solverInfo);
  q_gyro_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&q_gyro_M->solverInfo, 0.002);
  rtsiSetSolverMode(&q_gyro_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  q_gyro_M->blockIO = ((void *) &q_gyro_B);

  {
    q_gyro_B.HILReadEncoder_o1 = 0.0;
    q_gyro_B.HILReadEncoder_o2 = 0.0;
    q_gyro_B.GYROEcountstorad = 0.0;
    q_gyro_B.Gearratio = 0.0;
    q_gyro_B.seps = 0.0;
    q_gyro_B.DerivativeGain = 0.0;
    q_gyro_B.epsilon = 0.0;
    q_gyro_B.ManualSwitch = 0.0;
    q_gyro_B.DirectionConventionRightHandsys = 0.0;
    q_gyro_B.AmplifierSaturationV = 0.0;
    q_gyro_B.InverseAmplifierGainVV = 0.0;
    q_gyro_B.DACBSaturationV = 0.0;
    q_gyro_B.AmplifierGainVV = 0.0;
    q_gyro_B.SRV02countstorad = 0.0;
    q_gyro_B.Gain = 0.0;
    q_gyro_B.Gain_i = 0.0;
    q_gyro_B.epsilon_h = 0.0;
    q_gyro_B.ProportionalGain = 0.0;
    q_gyro_B.Add = 0.0;
  }

  /* parameters */
  q_gyro_M->defaultParam = ((real_T *)&q_gyro_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &q_gyro_X;
    q_gyro_M->contStates = (x);
    (void) memset((void *)&q_gyro_X, 0,
                  sizeof(X_q_gyro_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &q_gyro_XDis;
    q_gyro_M->contStateDisabled = (xdis);
    (void) memset((void *)&q_gyro_XDis, 0,
                  sizeof(XDis_q_gyro_T));
  }

  /* states (dwork) */
  q_gyro_M->dwork = ((void *) &q_gyro_DW);
  (void) memset((void *)&q_gyro_DW, 0,
                sizeof(DW_q_gyro_T));
  q_gyro_DW.HILInitialize_AIMinimums[0] = 0.0;
  q_gyro_DW.HILInitialize_AIMinimums[1] = 0.0;
  q_gyro_DW.HILInitialize_AIMaximums[0] = 0.0;
  q_gyro_DW.HILInitialize_AIMaximums[1] = 0.0;
  q_gyro_DW.HILInitialize_AOMinimums[0] = 0.0;
  q_gyro_DW.HILInitialize_AOMinimums[1] = 0.0;
  q_gyro_DW.HILInitialize_AOMaximums[0] = 0.0;
  q_gyro_DW.HILInitialize_AOMaximums[1] = 0.0;
  q_gyro_DW.HILInitialize_AOVoltages[0] = 0.0;
  q_gyro_DW.HILInitialize_AOVoltages[1] = 0.0;
  q_gyro_DW.HILInitialize_FilterFrequency[0] = 0.0;
  q_gyro_DW.HILInitialize_FilterFrequency[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_gyro_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_gyro_M->Sizes.numContStates = (1); /* Number of continuous states */
  q_gyro_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  q_gyro_M->Sizes.numY = (0);          /* Number of model outputs */
  q_gyro_M->Sizes.numU = (0);          /* Number of model inputs */
  q_gyro_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_gyro_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  q_gyro_M->Sizes.numBlocks = (27);    /* Number of blocks */
  q_gyro_M->Sizes.numBlockIO = (19);   /* Number of block outputs */
  q_gyro_M->Sizes.numBlockPrms = (102);/* Sum of parameter "widths" */
  return q_gyro_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
