/*
 * control_experiment.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "control_experiment".
 *
 * Model version              : 27.11
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Feb 11 14:53:31 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "control_experiment.h"
#include "rtwtypes.h"
#include "control_experiment_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "control_experiment_dt.h"

/* Block signals (default storage) */
B_control_experiment_T control_experiment_B;

/* Continuous states */
X_control_experiment_T control_experiment_X;

/* Disabled State Vector */
XDis_control_experiment_T control_experiment_XDis;

/* Block states (default storage) */
DW_control_experiment_T control_experiment_DW;

/* Real-time model */
static RT_MODEL_control_experiment_T control_experiment_M_;
RT_MODEL_control_experiment_T *const control_experiment_M =
  &control_experiment_M_;

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
  control_experiment_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void control_experiment_output(void)
{
  real_T currentTime;
  real_T u0;
  real_T u2;
  real_T *lastU;
  if (rtmIsMajorTimeStep(control_experiment_M)) {
    /* set solver stop time */
    if (!(control_experiment_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&control_experiment_M->solverInfo,
                            ((control_experiment_M->Timing.clockTickH0 + 1) *
        control_experiment_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&control_experiment_M->solverInfo,
                            ((control_experiment_M->Timing.clockTick0 + 1) *
        control_experiment_M->Timing.stepSize0 +
        control_experiment_M->Timing.clockTickH0 *
        control_experiment_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(control_experiment_M)) {
    control_experiment_M->Timing.t[0] = rtsiGetT
      (&control_experiment_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(control_experiment_M)) {
  }

  /* Step: '<Root>/Step' */
  currentTime = control_experiment_M->Timing.t[0];
  if (currentTime < control_experiment_P.Step_Time) {
    /* Step: '<Root>/Step' */
    control_experiment_B.thetaR = control_experiment_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    control_experiment_B.thetaR = control_experiment_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
  if (rtmIsMajorTimeStep(control_experiment_M)) {
    /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder' */

    /* S-Function Block: control_experiment/SRV02 Gyroscope/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(control_experiment_DW.HILInitialize_Card,
        control_experiment_P.HILReadEncoder_channels, 2,
        &control_experiment_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
      } else {
        control_experiment_B.HILReadEncoder_o1 =
          control_experiment_DW.HILReadEncoder_Buffer[0];
        control_experiment_B.HILReadEncoder_o2 =
          control_experiment_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S1>/SRV02: counts to rad' */
    control_experiment_B.SRV02countstorad = control_experiment_P.K_ENC *
      control_experiment_B.HILReadEncoder_o1;
  }

  /* Sum: '<Root>/Sum' */
  control_experiment_B.Sum = control_experiment_B.thetaR -
    control_experiment_B.SRV02countstorad;

  /* Gain: '<Root>/Gain' */
  control_experiment_B.Gain = control_experiment_P.Kp * control_experiment_B.Sum;

  /* Integrator: '<Root>/Integrator' */
  control_experiment_B.Integrator = control_experiment_X.Integrator_CSTATE;

  /* Gain: '<Root>/Gain2' */
  control_experiment_B.Gain2 = control_experiment_P.Ki *
    control_experiment_B.Integrator;

  /* Derivative: '<Root>/Derivative' */
  if ((control_experiment_DW.TimeStampA >= control_experiment_M->Timing.t[0]) &&
      (control_experiment_DW.TimeStampB >= control_experiment_M->Timing.t[0])) {
    /* Derivative: '<Root>/Derivative' */
    control_experiment_B.Derivative = 0.0;
  } else {
    currentTime = control_experiment_DW.TimeStampA;
    lastU = &control_experiment_DW.LastUAtTimeA;
    if (control_experiment_DW.TimeStampA < control_experiment_DW.TimeStampB) {
      if (control_experiment_DW.TimeStampB < control_experiment_M->Timing.t[0])
      {
        currentTime = control_experiment_DW.TimeStampB;
        lastU = &control_experiment_DW.LastUAtTimeB;
      }
    } else if (control_experiment_DW.TimeStampA >=
               control_experiment_M->Timing.t[0]) {
      currentTime = control_experiment_DW.TimeStampB;
      lastU = &control_experiment_DW.LastUAtTimeB;
    }

    currentTime = control_experiment_M->Timing.t[0] - currentTime;

    /* Derivative: '<Root>/Derivative' */
    control_experiment_B.Derivative = (control_experiment_B.Sum - *lastU) /
      currentTime;
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Gain: '<Root>/Gain1' */
  control_experiment_B.Gain1 = control_experiment_P.Kd *
    control_experiment_B.Derivative;

  /* Sum: '<Root>/Add' */
  control_experiment_B.Vm = (control_experiment_B.Gain +
    control_experiment_B.Gain2) + control_experiment_B.Gain1;

  /* Saturate: '<Root>/Saturation' */
  u0 = control_experiment_B.Vm;
  currentTime = control_experiment_P.Saturation_LowerSat;
  u2 = control_experiment_P.Saturation_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<Root>/Saturation' */
    control_experiment_B.Saturation = u2;
  } else if (u0 < currentTime) {
    /* Saturate: '<Root>/Saturation' */
    control_experiment_B.Saturation = currentTime;
  } else {
    /* Saturate: '<Root>/Saturation' */
    control_experiment_B.Saturation = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<S4>/Direction Convention: (Right-Hand) system' */
  control_experiment_B.DirectionConventionRightHandsys =
    control_experiment_P.DirectionConventionRightHandsys *
    control_experiment_B.Saturation;

  /* Saturate: '<S4>/Amplifier  Saturation (V)' */
  currentTime = -control_experiment_P.VMAX_AMP;
  u0 = control_experiment_B.DirectionConventionRightHandsys;
  u2 = control_experiment_P.VMAX_AMP;
  if (u0 > u2) {
    /* Saturate: '<S4>/Amplifier  Saturation (V)' */
    control_experiment_B.AmplifierSaturationV = u2;
  } else if (u0 < currentTime) {
    /* Saturate: '<S4>/Amplifier  Saturation (V)' */
    control_experiment_B.AmplifierSaturationV = currentTime;
  } else {
    /* Saturate: '<S4>/Amplifier  Saturation (V)' */
    control_experiment_B.AmplifierSaturationV = u0;
  }

  /* End of Saturate: '<S4>/Amplifier  Saturation (V)' */

  /* Gain: '<S4>/Inverse Amplifier  Gain (V//V)' */
  currentTime = 1.0 / control_experiment_P.K_AMP;

  /* Gain: '<S4>/Inverse Amplifier  Gain (V//V)' */
  control_experiment_B.InverseAmplifierGainVV = currentTime *
    control_experiment_B.AmplifierSaturationV;

  /* Saturate: '<S4>/DACB Saturation (V)' */
  currentTime = -control_experiment_P.VMAX_DAC;
  u0 = control_experiment_B.InverseAmplifierGainVV;
  u2 = control_experiment_P.VMAX_DAC;
  if (u0 > u2) {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    control_experiment_B.DACBSaturationV = u2;
  } else if (u0 < currentTime) {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    control_experiment_B.DACBSaturationV = currentTime;
  } else {
    /* Saturate: '<S4>/DACB Saturation (V)' */
    control_experiment_B.DACBSaturationV = u0;
  }

  /* End of Saturate: '<S4>/DACB Saturation (V)' */
  if (rtmIsMajorTimeStep(control_experiment_M)) {
    /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

    /* S-Function Block: control_experiment/SRV02 Gyroscope/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(control_experiment_DW.HILInitialize_Card,
        &control_experiment_P.HILWriteAnalog_channels, 1,
        &control_experiment_B.DACBSaturationV);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S4>/Amplifier  Gain (V//V)' */
  currentTime = -control_experiment_P.K_AMP;

  /* Gain: '<S4>/Amplifier  Gain (V//V)' */
  control_experiment_B.AmplifierGainVV = currentTime *
    control_experiment_B.DACBSaturationV;
  if (rtmIsMajorTimeStep(control_experiment_M)) {
    /* Gain: '<S1>/GYRO-E: counts to rad' */
    control_experiment_B.GYROEcountstorad = control_experiment_P.K_ENC *
      control_experiment_B.HILReadEncoder_o2;

    /* Gain: '<S1>/Gear ratio' */
    control_experiment_B.Gearratio = control_experiment_P.Gearratio_Gain *
      control_experiment_B.GYROEcountstorad;

    /* S-Function (hil_write_digital_block): '<S1>/HIL Write Digital' incorporates:
     *  Constant: '<S1>/Enable VoltPAQ-X2,X4'
     */

    /* S-Function Block: control_experiment/SRV02 Gyroscope/HIL Write Digital (hil_write_digital_block) */
    {
      t_error result;
      control_experiment_DW.HILWriteDigital_Buffer[0] =
        (control_experiment_P.EnableVoltPAQX2X4_Value[0] != 0);
      control_experiment_DW.HILWriteDigital_Buffer[1] =
        (control_experiment_P.EnableVoltPAQX2X4_Value[1] != 0);
      control_experiment_DW.HILWriteDigital_Buffer[2] =
        (control_experiment_P.EnableVoltPAQX2X4_Value[2] != 0);
      control_experiment_DW.HILWriteDigital_Buffer[3] =
        (control_experiment_P.EnableVoltPAQX2X4_Value[3] != 0);
      result = hil_write_digital(control_experiment_DW.HILInitialize_Card,
        control_experiment_P.HILWriteDigital_channels, 4,
        &control_experiment_DW.HILWriteDigital_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
      }
    }

    /* Gain: '<S2>/Gain' */
    control_experiment_B.Gain_c = control_experiment_P.Gain_Gain *
      control_experiment_B.Gearratio;

    /* Gain: '<S3>/Gain' */
    control_experiment_B.Gain_i = control_experiment_P.Gain_Gain_f *
      control_experiment_B.SRV02countstorad;
  }

  /* Clock: '<Root>/Clock' */
  control_experiment_B.Clock = control_experiment_M->Timing.t[0];
  if (rtmIsMajorTimeStep(control_experiment_M)) {
  }
}

/* Model update function */
void control_experiment_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (control_experiment_DW.TimeStampA == (rtInf)) {
    control_experiment_DW.TimeStampA = control_experiment_M->Timing.t[0];
    lastU = &control_experiment_DW.LastUAtTimeA;
  } else if (control_experiment_DW.TimeStampB == (rtInf)) {
    control_experiment_DW.TimeStampB = control_experiment_M->Timing.t[0];
    lastU = &control_experiment_DW.LastUAtTimeB;
  } else if (control_experiment_DW.TimeStampA < control_experiment_DW.TimeStampB)
  {
    control_experiment_DW.TimeStampA = control_experiment_M->Timing.t[0];
    lastU = &control_experiment_DW.LastUAtTimeA;
  } else {
    control_experiment_DW.TimeStampB = control_experiment_M->Timing.t[0];
    lastU = &control_experiment_DW.LastUAtTimeB;
  }

  *lastU = control_experiment_B.Sum;

  /* End of Update for Derivative: '<Root>/Derivative' */
  if (rtmIsMajorTimeStep(control_experiment_M)) {
    rt_ertODEUpdateContinuousStates(&control_experiment_M->solverInfo);
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
  if (!(++control_experiment_M->Timing.clockTick0)) {
    ++control_experiment_M->Timing.clockTickH0;
  }

  control_experiment_M->Timing.t[0] = rtsiGetSolverStopTime
    (&control_experiment_M->solverInfo);

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
    if (!(++control_experiment_M->Timing.clockTick1)) {
      ++control_experiment_M->Timing.clockTickH1;
    }

    control_experiment_M->Timing.t[1] = control_experiment_M->Timing.clockTick1 *
      control_experiment_M->Timing.stepSize1 +
      control_experiment_M->Timing.clockTickH1 *
      control_experiment_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void control_experiment_derivatives(void)
{
  XDot_control_experiment_T *_rtXdot;
  _rtXdot = ((XDot_control_experiment_T *) control_experiment_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = control_experiment_B.Sum;
}

/* Model initialize function */
void control_experiment_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: control_experiment/SRV02 Gyroscope/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &control_experiment_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(control_experiment_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (control_experiment_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal", 50);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(control_experiment_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(control_experiment_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(control_experiment_M, _rt_error_message);
      return;
    }

    if ((control_experiment_P.HILInitialize_AIPStart && !is_switching) ||
        (control_experiment_P.HILInitialize_AIPEnter && is_switching)) {
      control_experiment_DW.HILInitialize_AIMinimums[0] =
        (control_experiment_P.HILInitialize_AILow);
      control_experiment_DW.HILInitialize_AIMinimums[1] =
        (control_experiment_P.HILInitialize_AILow);
      control_experiment_DW.HILInitialize_AIMaximums[0] =
        control_experiment_P.HILInitialize_AIHigh;
      control_experiment_DW.HILInitialize_AIMaximums[1] =
        control_experiment_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (control_experiment_DW.HILInitialize_Card,
         control_experiment_P.HILInitialize_AIChannels, 2U,
         &control_experiment_DW.HILInitialize_AIMinimums[0],
         &control_experiment_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        return;
      }
    }

    if ((control_experiment_P.HILInitialize_AOPStart && !is_switching) ||
        (control_experiment_P.HILInitialize_AOPEnter && is_switching)) {
      control_experiment_DW.HILInitialize_AOMinimums[0] =
        (control_experiment_P.HILInitialize_AOLow);
      control_experiment_DW.HILInitialize_AOMinimums[1] =
        (control_experiment_P.HILInitialize_AOLow);
      control_experiment_DW.HILInitialize_AOMaximums[0] =
        control_experiment_P.HILInitialize_AOHigh;
      control_experiment_DW.HILInitialize_AOMaximums[1] =
        control_experiment_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (control_experiment_DW.HILInitialize_Card,
         control_experiment_P.HILInitialize_AOChannels, 2U,
         &control_experiment_DW.HILInitialize_AOMinimums[0],
         &control_experiment_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        return;
      }
    }

    if ((control_experiment_P.HILInitialize_AOStart && !is_switching) ||
        (control_experiment_P.HILInitialize_AOEnter && is_switching)) {
      control_experiment_DW.HILInitialize_AOVoltages[0] =
        control_experiment_P.HILInitialize_AOInitial;
      control_experiment_DW.HILInitialize_AOVoltages[1] =
        control_experiment_P.HILInitialize_AOInitial;
      result = hil_write_analog(control_experiment_DW.HILInitialize_Card,
        control_experiment_P.HILInitialize_AOChannels, 2U,
        &control_experiment_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        return;
      }
    }

    if (control_experiment_P.HILInitialize_AOReset) {
      control_experiment_DW.HILInitialize_AOVoltages[0] =
        control_experiment_P.HILInitialize_AOWatchdog;
      control_experiment_DW.HILInitialize_AOVoltages[1] =
        control_experiment_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (control_experiment_DW.HILInitialize_Card,
         control_experiment_P.HILInitialize_AOChannels, 2U,
         &control_experiment_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(control_experiment_DW.HILInitialize_Card,
      NULL, 0U, control_experiment_P.HILInitialize_DOChannels, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(control_experiment_M, _rt_error_message);
      return;
    }

    if ((control_experiment_P.HILInitialize_DOStart && !is_switching) ||
        (control_experiment_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &control_experiment_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = control_experiment_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(control_experiment_DW.HILInitialize_Card,
        control_experiment_P.HILInitialize_DOChannels, 8U, (t_boolean *)
        &control_experiment_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        return;
      }
    }

    if (control_experiment_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &control_experiment_DW.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = control_experiment_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (control_experiment_DW.HILInitialize_Card,
         control_experiment_P.HILInitialize_DOChannels, 8U, (const
          t_digital_state *) &control_experiment_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        return;
      }
    }

    if ((control_experiment_P.HILInitialize_EIPStart && !is_switching) ||
        (control_experiment_P.HILInitialize_EIPEnter && is_switching)) {
      control_experiment_DW.HILInitialize_QuadratureModes[0] =
        control_experiment_P.HILInitialize_EIQuadrature;
      control_experiment_DW.HILInitialize_QuadratureModes[1] =
        control_experiment_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (control_experiment_DW.HILInitialize_Card,
         control_experiment_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &control_experiment_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        return;
      }
    }

    if ((control_experiment_P.HILInitialize_EIStart && !is_switching) ||
        (control_experiment_P.HILInitialize_EIEnter && is_switching)) {
      control_experiment_DW.HILInitialize_InitialEICounts[0] =
        control_experiment_P.HILInitialize_EIInitial;
      control_experiment_DW.HILInitialize_InitialEICounts[1] =
        control_experiment_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(control_experiment_DW.HILInitialize_Card,
        control_experiment_P.HILInitialize_EIChannels, 2U,
        &control_experiment_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  control_experiment_X.Integrator_CSTATE = control_experiment_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  control_experiment_DW.TimeStampA = (rtInf);
  control_experiment_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void control_experiment_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: control_experiment/SRV02 Gyroscope/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(control_experiment_DW.HILInitialize_Card);
    hil_monitor_stop_all(control_experiment_DW.HILInitialize_Card);
    is_switching = false;
    if ((control_experiment_P.HILInitialize_AOTerminate && !is_switching) ||
        (control_experiment_P.HILInitialize_AOExit && is_switching)) {
      control_experiment_DW.HILInitialize_AOVoltages[0] =
        control_experiment_P.HILInitialize_AOFinal;
      control_experiment_DW.HILInitialize_AOVoltages[1] =
        control_experiment_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((control_experiment_P.HILInitialize_DOTerminate && !is_switching) ||
        (control_experiment_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &control_experiment_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = control_experiment_P.HILInitialize_DOFinal;
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
      result = hil_write(control_experiment_DW.HILInitialize_Card
                         , control_experiment_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , control_experiment_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &control_experiment_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *)
                         &control_experiment_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (control_experiment_DW.HILInitialize_Card,
             control_experiment_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &control_experiment_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (control_experiment_DW.HILInitialize_Card,
             control_experiment_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &control_experiment_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(control_experiment_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(control_experiment_DW.HILInitialize_Card);
    hil_monitor_delete_all(control_experiment_DW.HILInitialize_Card);
    hil_close(control_experiment_DW.HILInitialize_Card);
    control_experiment_DW.HILInitialize_Card = NULL;
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
  control_experiment_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  control_experiment_update();
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
  control_experiment_initialize();
}

void MdlTerminate(void)
{
  control_experiment_terminate();
}

/* Registration function */
RT_MODEL_control_experiment_T *control_experiment(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)control_experiment_M, 0,
                sizeof(RT_MODEL_control_experiment_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&control_experiment_M->solverInfo,
                          &control_experiment_M->Timing.simTimeStep);
    rtsiSetTPtr(&control_experiment_M->solverInfo, &rtmGetTPtr
                (control_experiment_M));
    rtsiSetStepSizePtr(&control_experiment_M->solverInfo,
                       &control_experiment_M->Timing.stepSize0);
    rtsiSetdXPtr(&control_experiment_M->solverInfo,
                 &control_experiment_M->derivs);
    rtsiSetContStatesPtr(&control_experiment_M->solverInfo, (real_T **)
                         &control_experiment_M->contStates);
    rtsiSetNumContStatesPtr(&control_experiment_M->solverInfo,
      &control_experiment_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&control_experiment_M->solverInfo,
      &control_experiment_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&control_experiment_M->solverInfo,
      &control_experiment_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&control_experiment_M->solverInfo,
      &control_experiment_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&control_experiment_M->solverInfo, (boolean_T**)
      &control_experiment_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&control_experiment_M->solverInfo, (&rtmGetErrorStatus
      (control_experiment_M)));
    rtsiSetRTModelPtr(&control_experiment_M->solverInfo, control_experiment_M);
  }

  rtsiSetSimTimeStep(&control_experiment_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&control_experiment_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&control_experiment_M->solverInfo, false);
  control_experiment_M->intgData.f[0] = control_experiment_M->odeF[0];
  control_experiment_M->contStates = ((real_T *) &control_experiment_X);
  control_experiment_M->contStateDisabled = ((boolean_T *)
    &control_experiment_XDis);
  control_experiment_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&control_experiment_M->solverInfo, (void *)
                    &control_experiment_M->intgData);
  rtsiSetSolverName(&control_experiment_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = control_experiment_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "control_experiment_M points to
       static memory which is guaranteed to be non-NULL" */
    control_experiment_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    control_experiment_M->Timing.sampleTimes =
      (&control_experiment_M->Timing.sampleTimesArray[0]);
    control_experiment_M->Timing.offsetTimes =
      (&control_experiment_M->Timing.offsetTimesArray[0]);

    /* task periods */
    control_experiment_M->Timing.sampleTimes[0] = (0.0);
    control_experiment_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    control_experiment_M->Timing.offsetTimes[0] = (0.0);
    control_experiment_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(control_experiment_M, &control_experiment_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = control_experiment_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    control_experiment_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(control_experiment_M, 6.0);
  control_experiment_M->Timing.stepSize0 = 0.002;
  control_experiment_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  control_experiment_M->Sizes.checksums[0] = (279221741U);
  control_experiment_M->Sizes.checksums[1] = (772076655U);
  control_experiment_M->Sizes.checksums[2] = (2184070134U);
  control_experiment_M->Sizes.checksums[3] = (1484621358U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    control_experiment_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(control_experiment_M->extModeInfo,
      &control_experiment_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(control_experiment_M->extModeInfo,
                        control_experiment_M->Sizes.checksums);
    rteiSetTPtr(control_experiment_M->extModeInfo, rtmGetTPtr
                (control_experiment_M));
  }

  control_experiment_M->solverInfoPtr = (&control_experiment_M->solverInfo);
  control_experiment_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&control_experiment_M->solverInfo, 0.002);
  rtsiSetSolverMode(&control_experiment_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  control_experiment_M->blockIO = ((void *) &control_experiment_B);

  {
    control_experiment_B.thetaR = 0.0;
    control_experiment_B.HILReadEncoder_o1 = 0.0;
    control_experiment_B.HILReadEncoder_o2 = 0.0;
    control_experiment_B.SRV02countstorad = 0.0;
    control_experiment_B.Sum = 0.0;
    control_experiment_B.Gain = 0.0;
    control_experiment_B.Integrator = 0.0;
    control_experiment_B.Gain2 = 0.0;
    control_experiment_B.Derivative = 0.0;
    control_experiment_B.Gain1 = 0.0;
    control_experiment_B.Vm = 0.0;
    control_experiment_B.Saturation = 0.0;
    control_experiment_B.DirectionConventionRightHandsys = 0.0;
    control_experiment_B.AmplifierSaturationV = 0.0;
    control_experiment_B.InverseAmplifierGainVV = 0.0;
    control_experiment_B.DACBSaturationV = 0.0;
    control_experiment_B.AmplifierGainVV = 0.0;
    control_experiment_B.GYROEcountstorad = 0.0;
    control_experiment_B.Gearratio = 0.0;
    control_experiment_B.Gain_c = 0.0;
    control_experiment_B.Gain_i = 0.0;
    control_experiment_B.Clock = 0.0;
  }

  /* parameters */
  control_experiment_M->defaultParam = ((real_T *)&control_experiment_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &control_experiment_X;
    control_experiment_M->contStates = (x);
    (void) memset((void *)&control_experiment_X, 0,
                  sizeof(X_control_experiment_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &control_experiment_XDis;
    control_experiment_M->contStateDisabled = (xdis);
    (void) memset((void *)&control_experiment_XDis, 0,
                  sizeof(XDis_control_experiment_T));
  }

  /* states (dwork) */
  control_experiment_M->dwork = ((void *) &control_experiment_DW);
  (void) memset((void *)&control_experiment_DW, 0,
                sizeof(DW_control_experiment_T));
  control_experiment_DW.HILInitialize_AIMinimums[0] = 0.0;
  control_experiment_DW.HILInitialize_AIMinimums[1] = 0.0;
  control_experiment_DW.HILInitialize_AIMaximums[0] = 0.0;
  control_experiment_DW.HILInitialize_AIMaximums[1] = 0.0;
  control_experiment_DW.HILInitialize_AOMinimums[0] = 0.0;
  control_experiment_DW.HILInitialize_AOMinimums[1] = 0.0;
  control_experiment_DW.HILInitialize_AOMaximums[0] = 0.0;
  control_experiment_DW.HILInitialize_AOMaximums[1] = 0.0;
  control_experiment_DW.HILInitialize_AOVoltages[0] = 0.0;
  control_experiment_DW.HILInitialize_AOVoltages[1] = 0.0;
  control_experiment_DW.HILInitialize_FilterFrequency[0] = 0.0;
  control_experiment_DW.HILInitialize_FilterFrequency[1] = 0.0;
  control_experiment_DW.TimeStampA = 0.0;
  control_experiment_DW.LastUAtTimeA = 0.0;
  control_experiment_DW.TimeStampB = 0.0;
  control_experiment_DW.LastUAtTimeB = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    control_experiment_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  control_experiment_M->Sizes.numContStates = (1);/* Number of continuous states */
  control_experiment_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  control_experiment_M->Sizes.numY = (0);/* Number of model outputs */
  control_experiment_M->Sizes.numU = (0);/* Number of model inputs */
  control_experiment_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  control_experiment_M->Sizes.numSampTimes = (2);/* Number of sample times */
  control_experiment_M->Sizes.numBlocks = (31);/* Number of blocks */
  control_experiment_M->Sizes.numBlockIO = (22);/* Number of block outputs */
  control_experiment_M->Sizes.numBlockPrms = (102);/* Sum of parameter "widths" */
  return control_experiment_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
