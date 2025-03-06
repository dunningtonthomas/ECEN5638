/*
 * pid_q_torsion.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pid_q_torsion".
 *
 * Model version              : 27.28
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Mar  6 14:21:37 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pid_q_torsion.h"
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
#include "pid_q_torsion_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "pid_q_torsion_dt.h"

/* Block signals (default storage) */
B_pid_q_torsion_T pid_q_torsion_B;

/* Block states (default storage) */
DW_pid_q_torsion_T pid_q_torsion_DW;

/* Real-time model */
static RT_MODEL_pid_q_torsion_T pid_q_torsion_M_;
RT_MODEL_pid_q_torsion_T *const pid_q_torsion_M = &pid_q_torsion_M_;

/* Model output function */
void pid_q_torsion_output(void)
{
  /* local block i/o variables */
  boolean_T rtb_HILWatchdog;
  __m128d tmp;
  real_T rtb_HILReadEncoderTimebase[2];
  real_T Amplitudedeg;
  real_T Amplitudedeg_tmp;
  real_T deltaT_tmp;
  real_T riseValLimit;
  real_T rtb_DACBSaturationV;
  boolean_T limitedCache;

  /* S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_read_encoder(pid_q_torsion_DW.HILReadEncoderTimebase_Task,
      1, &pid_q_torsion_DW.HILReadEncoderTimebase_Buffer[0]);
    if (result < 0) {
      rtb_HILReadEncoderTimebase[0] = 0;
      rtb_HILReadEncoderTimebase[1] = 0;
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
    } else {
      rtb_HILReadEncoderTimebase[0] =
        pid_q_torsion_DW.HILReadEncoderTimebase_Buffer[0];
      rtb_HILReadEncoderTimebase[1] =
        pid_q_torsion_DW.HILReadEncoderTimebase_Buffer[1];
    }
  }

  /* SignalGenerator: '<S6>/Signal Generator' incorporates:
   *  Clock: '<Root>/Clock'
   */
  Amplitudedeg_tmp = pid_q_torsion_M->Timing.t[0];
  Amplitudedeg = pid_q_torsion_P.SignalGenerator_Frequency * Amplitudedeg_tmp;
  if (Amplitudedeg - floor(Amplitudedeg) >= 0.5) {
    Amplitudedeg = pid_q_torsion_P.SignalGenerator_Amplitude;
  } else {
    Amplitudedeg = -pid_q_torsion_P.SignalGenerator_Amplitude;
  }

  /* Gain: '<S6>/Amplitude (deg)' incorporates:
   *  SignalGenerator: '<S6>/Signal Generator'
   */
  Amplitudedeg *= pid_q_torsion_P.Amplitudedeg_Gain;

  /* RateLimiter: '<S6>/Rate Limiter' */
  if (pid_q_torsion_DW.LastMajorTime == (rtInf)) {
    /* RateLimiter: '<S6>/Rate Limiter' */
    pid_q_torsion_B.RateLimiter = Amplitudedeg;
  } else {
    deltaT_tmp = pid_q_torsion_M->Timing.t[0];
    rtb_DACBSaturationV = deltaT_tmp - pid_q_torsion_DW.LastMajorTime;
    if (pid_q_torsion_DW.LastMajorTime == deltaT_tmp) {
      if (pid_q_torsion_DW.PrevLimited) {
        /* RateLimiter: '<S6>/Rate Limiter' */
        pid_q_torsion_B.RateLimiter = pid_q_torsion_DW.PrevY;
      } else {
        /* RateLimiter: '<S6>/Rate Limiter' */
        pid_q_torsion_B.RateLimiter = Amplitudedeg;
      }
    } else {
      riseValLimit = rtb_DACBSaturationV * pid_q_torsion_P.RateLimiter_RisingLim;
      deltaT_tmp = Amplitudedeg - pid_q_torsion_DW.PrevY;
      if (deltaT_tmp > riseValLimit) {
        /* RateLimiter: '<S6>/Rate Limiter' */
        pid_q_torsion_B.RateLimiter = pid_q_torsion_DW.PrevY + riseValLimit;
        limitedCache = true;
      } else {
        rtb_DACBSaturationV *= pid_q_torsion_P.RateLimiter_FallingLim;
        if (deltaT_tmp < rtb_DACBSaturationV) {
          /* RateLimiter: '<S6>/Rate Limiter' */
          pid_q_torsion_B.RateLimiter = pid_q_torsion_DW.PrevY +
            rtb_DACBSaturationV;
          limitedCache = true;
        } else {
          /* RateLimiter: '<S6>/Rate Limiter' */
          pid_q_torsion_B.RateLimiter = Amplitudedeg;
          limitedCache = false;
        }
      }

      if (rtsiIsModeUpdateTimeStep(&pid_q_torsion_M->solverInfo)) {
        pid_q_torsion_DW.PrevLimited = limitedCache;
      }
    }
  }

  /* End of RateLimiter: '<S6>/Rate Limiter' */

  /* Gain: '<S58>/Gain1' */
  Amplitudedeg = pid_q_torsion_P.Gain1_Gain * pid_q_torsion_B.RateLimiter;

  /* Gain: '<S1>/Encoder Calibration  (rad//count)' */
  tmp = _mm_mul_pd(_mm_set1_pd(pid_q_torsion_P.K_ENC), _mm_loadu_pd
                   (&rtb_HILReadEncoderTimebase[0]));

  /* Gain: '<S1>/Encoder Calibration  (rad//count)' */
  _mm_storeu_pd(&pid_q_torsion_B.EncoderCalibrationradcount[0], tmp);

  /* Sum: '<Root>/Sum' */
  pid_q_torsion_B.Sum = Amplitudedeg -
    pid_q_torsion_B.EncoderCalibrationradcount[1];

  /* Gain: '<S44>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S36>/Filter'
   *  Gain: '<S34>/Derivative Gain'
   *  Sum: '<S36>/SumD'
   */
  pid_q_torsion_B.FilterCoefficient = (pid_q_torsion_P.Kd * pid_q_torsion_B.Sum
    - pid_q_torsion_DW.Filter_DSTATE) * pid_q_torsion_P.PIDController_N;

  /* Sum: '<S50>/Sum' incorporates:
   *  DiscreteIntegrator: '<S41>/Integrator'
   *  Gain: '<S46>/Proportional Gain'
   */
  rtb_DACBSaturationV = (pid_q_torsion_P.Kp * pid_q_torsion_B.Sum +
    pid_q_torsion_DW.Integrator_DSTATE) + pid_q_torsion_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_DACBSaturationV > pid_q_torsion_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    pid_q_torsion_B.Saturation = pid_q_torsion_P.Saturation_UpperSat;
  } else if (rtb_DACBSaturationV < pid_q_torsion_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    pid_q_torsion_B.Saturation = pid_q_torsion_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    pid_q_torsion_B.Saturation = rtb_DACBSaturationV;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<S7>/Direction Convention: (Right-Hand) system' */
  rtb_DACBSaturationV = pid_q_torsion_P.DirectionConventionRightHandsys *
    pid_q_torsion_B.Saturation;

  /* Saturate: '<S7>/Amplifier  Saturation (V)' */
  if (rtb_DACBSaturationV > pid_q_torsion_P.VMAX_AMP) {
    rtb_DACBSaturationV = pid_q_torsion_P.VMAX_AMP;
  } else if (rtb_DACBSaturationV < -pid_q_torsion_P.VMAX_AMP) {
    rtb_DACBSaturationV = -pid_q_torsion_P.VMAX_AMP;
  }

  /* Gain: '<S7>/Inverse Amplifier  Gain (V//V)' incorporates:
   *  Saturate: '<S7>/Amplifier  Saturation (V)'
   */
  rtb_DACBSaturationV *= 1.0 / pid_q_torsion_P.K_AMP;

  /* Saturate: '<S7>/DACB Saturation (V)' */
  if (rtb_DACBSaturationV > pid_q_torsion_P.VMAX_DAC) {
    rtb_DACBSaturationV = pid_q_torsion_P.VMAX_DAC;
  } else if (rtb_DACBSaturationV < -pid_q_torsion_P.VMAX_DAC) {
    rtb_DACBSaturationV = -pid_q_torsion_P.VMAX_DAC;
  }

  /* End of Saturate: '<S7>/DACB Saturation (V)' */

  /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(pid_q_torsion_DW.HILInitialize_Card,
      &pid_q_torsion_P.HILWriteAnalog_channels, 1, &rtb_DACBSaturationV);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
    }
  }

  /* Gain: '<S7>/Amplifier  Gain (V//V)' */
  pid_q_torsion_B.AmplifierGainVV = -pid_q_torsion_P.K_AMP * rtb_DACBSaturationV;

  /* S-Function (hil_write_digital_block): '<S1>/HIL Write Digital' incorporates:
   *  Constant: '<S1>/Enable VoltPAQ-X2,X4'
   */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Write Digital (hil_write_digital_block) */
  {
    t_error result;
    pid_q_torsion_DW.HILWriteDigital_Buffer[0] =
      (pid_q_torsion_P.EnableVoltPAQX2X4_Value[0] != 0);
    pid_q_torsion_DW.HILWriteDigital_Buffer[1] =
      (pid_q_torsion_P.EnableVoltPAQX2X4_Value[1] != 0);
    pid_q_torsion_DW.HILWriteDigital_Buffer[2] =
      (pid_q_torsion_P.EnableVoltPAQX2X4_Value[2] != 0);
    pid_q_torsion_DW.HILWriteDigital_Buffer[3] =
      (pid_q_torsion_P.EnableVoltPAQX2X4_Value[3] != 0);
    result = hil_write_digital(pid_q_torsion_DW.HILInitialize_Card,
      pid_q_torsion_P.HILWriteDigital_channels, 4,
      &pid_q_torsion_DW.HILWriteDigital_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
    }
  }

  /* S-Function (hil_watchdog_block): '<S1>/HIL Watchdog' */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Watchdog (hil_watchdog_block) */
  {
    t_error result;
    if (pid_q_torsion_DW.HILWatchdog_IsStarted) {
      result = hil_watchdog_reload(pid_q_torsion_DW.HILInitialize_Card);
    } else {
      result = hil_watchdog_start(pid_q_torsion_DW.HILInitialize_Card,
        pid_q_torsion_P.HILWatchdog_Timeout);
      if (result == 0) {
        pid_q_torsion_DW.HILWatchdog_IsStarted = true;
        result = 1;                    /* indicate watchdog has not expired */
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
    }

    rtb_HILWatchdog = (result == 0);
  }

  /* S-Function (stop_with_error_block): '<S1>/Stop with Error' */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/Stop with Error (stop_with_error_block) */
  {
    if (rtb_HILWatchdog) {
      rtmSetErrorStatus(pid_q_torsion_M, "Stopped by watchdog.");
      return;
    }
  }

  /* Gain: '<S4>/Gain' */
  pid_q_torsion_B.Gain = pid_q_torsion_P.Gain_Gain *
    pid_q_torsion_B.EncoderCalibrationradcount[1];

  /* Gain: '<S5>/Gain' */
  pid_q_torsion_B.Gain_f = pid_q_torsion_P.Gain_Gain_m * Amplitudedeg;

  /* Gain: '<S38>/Integral Gain' */
  pid_q_torsion_B.IntegralGain = pid_q_torsion_P.Ki * pid_q_torsion_B.Sum;

  /* Clock: '<Root>/Clock' */
  pid_q_torsion_B.Clock = Amplitudedeg_tmp;
}

/* Model update function */
void pid_q_torsion_update(void)
{
  /* Update for RateLimiter: '<S6>/Rate Limiter' */
  pid_q_torsion_DW.PrevY = pid_q_torsion_B.RateLimiter;
  pid_q_torsion_DW.LastMajorTime = pid_q_torsion_M->Timing.t[0];

  /* Update for DiscreteIntegrator: '<S41>/Integrator' */
  pid_q_torsion_DW.Integrator_DSTATE += pid_q_torsion_P.Integrator_gainval *
    pid_q_torsion_B.IntegralGain;

  /* Update for DiscreteIntegrator: '<S36>/Filter' */
  pid_q_torsion_DW.Filter_DSTATE += pid_q_torsion_P.Filter_gainval *
    pid_q_torsion_B.FilterCoefficient;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++pid_q_torsion_M->Timing.clockTick0)) {
    ++pid_q_torsion_M->Timing.clockTickH0;
  }

  pid_q_torsion_M->Timing.t[0] = pid_q_torsion_M->Timing.clockTick0 *
    pid_q_torsion_M->Timing.stepSize0 + pid_q_torsion_M->Timing.clockTickH0 *
    pid_q_torsion_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++pid_q_torsion_M->Timing.clockTick1)) {
      ++pid_q_torsion_M->Timing.clockTickH1;
    }

    pid_q_torsion_M->Timing.t[1] = pid_q_torsion_M->Timing.clockTick1 *
      pid_q_torsion_M->Timing.stepSize1 + pid_q_torsion_M->Timing.clockTickH1 *
      pid_q_torsion_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void pid_q_torsion_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &pid_q_torsion_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(pid_q_torsion_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal", 50);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(pid_q_torsion_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
      return;
    }

    if ((pid_q_torsion_P.HILInitialize_AIPStart && !is_switching) ||
        (pid_q_torsion_P.HILInitialize_AIPEnter && is_switching)) {
      pid_q_torsion_DW.HILInitialize_AIMinimums[0] =
        (pid_q_torsion_P.HILInitialize_AILow);
      pid_q_torsion_DW.HILInitialize_AIMinimums[1] =
        (pid_q_torsion_P.HILInitialize_AILow);
      pid_q_torsion_DW.HILInitialize_AIMaximums[0] =
        pid_q_torsion_P.HILInitialize_AIHigh;
      pid_q_torsion_DW.HILInitialize_AIMaximums[1] =
        pid_q_torsion_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(pid_q_torsion_DW.HILInitialize_Card,
        pid_q_torsion_P.HILInitialize_AIChannels, 2U,
        &pid_q_torsion_DW.HILInitialize_AIMinimums[0],
        &pid_q_torsion_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        return;
      }
    }

    if ((pid_q_torsion_P.HILInitialize_AOPStart && !is_switching) ||
        (pid_q_torsion_P.HILInitialize_AOPEnter && is_switching)) {
      pid_q_torsion_DW.HILInitialize_AOMinimums[0] =
        (pid_q_torsion_P.HILInitialize_AOLow);
      pid_q_torsion_DW.HILInitialize_AOMinimums[1] =
        (pid_q_torsion_P.HILInitialize_AOLow);
      pid_q_torsion_DW.HILInitialize_AOMaximums[0] =
        pid_q_torsion_P.HILInitialize_AOHigh;
      pid_q_torsion_DW.HILInitialize_AOMaximums[1] =
        pid_q_torsion_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(pid_q_torsion_DW.HILInitialize_Card,
        pid_q_torsion_P.HILInitialize_AOChannels, 2U,
        &pid_q_torsion_DW.HILInitialize_AOMinimums[0],
        &pid_q_torsion_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        return;
      }
    }

    if ((pid_q_torsion_P.HILInitialize_AOStart && !is_switching) ||
        (pid_q_torsion_P.HILInitialize_AOEnter && is_switching)) {
      pid_q_torsion_DW.HILInitialize_AOVoltages[0] =
        pid_q_torsion_P.HILInitialize_AOInitial;
      pid_q_torsion_DW.HILInitialize_AOVoltages[1] =
        pid_q_torsion_P.HILInitialize_AOInitial;
      result = hil_write_analog(pid_q_torsion_DW.HILInitialize_Card,
        pid_q_torsion_P.HILInitialize_AOChannels, 2U,
        &pid_q_torsion_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        return;
      }
    }

    if (pid_q_torsion_P.HILInitialize_AOReset) {
      pid_q_torsion_DW.HILInitialize_AOVoltages[0] =
        pid_q_torsion_P.HILInitialize_AOWatchdog;
      pid_q_torsion_DW.HILInitialize_AOVoltages[1] =
        pid_q_torsion_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (pid_q_torsion_DW.HILInitialize_Card,
         pid_q_torsion_P.HILInitialize_AOChannels, 2U,
         &pid_q_torsion_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(pid_q_torsion_DW.HILInitialize_Card,
      NULL, 0U, pid_q_torsion_P.HILInitialize_DOChannels, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
      return;
    }

    if ((pid_q_torsion_P.HILInitialize_DOStart && !is_switching) ||
        (pid_q_torsion_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &pid_q_torsion_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = pid_q_torsion_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(pid_q_torsion_DW.HILInitialize_Card,
        pid_q_torsion_P.HILInitialize_DOChannels, 8U, (t_boolean *)
        &pid_q_torsion_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        return;
      }
    }

    if (pid_q_torsion_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &pid_q_torsion_DW.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = pid_q_torsion_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (pid_q_torsion_DW.HILInitialize_Card,
         pid_q_torsion_P.HILInitialize_DOChannels, 8U, (const t_digital_state *)
         &pid_q_torsion_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        return;
      }
    }

    if ((pid_q_torsion_P.HILInitialize_EIPStart && !is_switching) ||
        (pid_q_torsion_P.HILInitialize_EIPEnter && is_switching)) {
      pid_q_torsion_DW.HILInitialize_QuadratureModes[0] =
        pid_q_torsion_P.HILInitialize_EIQuadrature;
      pid_q_torsion_DW.HILInitialize_QuadratureModes[1] =
        pid_q_torsion_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (pid_q_torsion_DW.HILInitialize_Card,
         pid_q_torsion_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &pid_q_torsion_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        return;
      }
    }

    if ((pid_q_torsion_P.HILInitialize_EIStart && !is_switching) ||
        (pid_q_torsion_P.HILInitialize_EIEnter && is_switching)) {
      pid_q_torsion_DW.HILInitialize_InitialEICounts[0] =
        pid_q_torsion_P.HILInitialize_EIInitial;
      pid_q_torsion_DW.HILInitialize_InitialEICounts[1] =
        pid_q_torsion_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(pid_q_torsion_DW.HILInitialize_Card,
        pid_q_torsion_P.HILInitialize_EIChannels, 2U,
        &pid_q_torsion_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(pid_q_torsion_DW.HILInitialize_Card,
      pid_q_torsion_P.HILReadEncoderTimebase_SamplesI,
      pid_q_torsion_P.HILReadEncoderTimebase_Channels, 2,
      &pid_q_torsion_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (pid_q_torsion_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (pid_q_torsion_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (hil_watchdog_block): '<S1>/HIL Watchdog' */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Watchdog (hil_watchdog_block) */
  {
    pid_q_torsion_DW.HILWatchdog_IsStarted = false;
  }

  /* InitializeConditions for RateLimiter: '<S6>/Rate Limiter' */
  pid_q_torsion_DW.LastMajorTime = (rtInf);

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
  pid_q_torsion_DW.Integrator_DSTATE =
    pid_q_torsion_P.PIDController_InitialConditio_e;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Filter' */
  pid_q_torsion_DW.Filter_DSTATE =
    pid_q_torsion_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void pid_q_torsion_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(pid_q_torsion_DW.HILInitialize_Card);
    hil_monitor_stop_all(pid_q_torsion_DW.HILInitialize_Card);
    is_switching = false;

    /* S-Function Block: pid_q_torsion/1 DOF Torsion/HIL Watchdog (hil_watchdog_block) */
    {
      hil_watchdog_stop(pid_q_torsion_DW.HILInitialize_Card);
    }

    if ((pid_q_torsion_P.HILInitialize_AOTerminate && !is_switching) ||
        (pid_q_torsion_P.HILInitialize_AOExit && is_switching)) {
      pid_q_torsion_DW.HILInitialize_AOVoltages[0] =
        pid_q_torsion_P.HILInitialize_AOFinal;
      pid_q_torsion_DW.HILInitialize_AOVoltages[1] =
        pid_q_torsion_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((pid_q_torsion_P.HILInitialize_DOTerminate && !is_switching) ||
        (pid_q_torsion_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &pid_q_torsion_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = pid_q_torsion_P.HILInitialize_DOFinal;
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
      result = hil_write(pid_q_torsion_DW.HILInitialize_Card
                         , pid_q_torsion_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , pid_q_torsion_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &pid_q_torsion_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *) &pid_q_torsion_DW.HILInitialize_DOBits
                         [0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(pid_q_torsion_DW.HILInitialize_Card,
            pid_q_torsion_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &pid_q_torsion_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(pid_q_torsion_DW.HILInitialize_Card,
            pid_q_torsion_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &pid_q_torsion_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(pid_q_torsion_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(pid_q_torsion_DW.HILInitialize_Card);
    hil_monitor_delete_all(pid_q_torsion_DW.HILInitialize_Card);
    hil_close(pid_q_torsion_DW.HILInitialize_Card);
    pid_q_torsion_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  pid_q_torsion_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  pid_q_torsion_update();
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
  pid_q_torsion_initialize();
}

void MdlTerminate(void)
{
  pid_q_torsion_terminate();
}

/* Registration function */
RT_MODEL_pid_q_torsion_T *pid_q_torsion(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pid_q_torsion_M, 0,
                sizeof(RT_MODEL_pid_q_torsion_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pid_q_torsion_M->solverInfo,
                          &pid_q_torsion_M->Timing.simTimeStep);
    rtsiSetTPtr(&pid_q_torsion_M->solverInfo, &rtmGetTPtr(pid_q_torsion_M));
    rtsiSetStepSizePtr(&pid_q_torsion_M->solverInfo,
                       &pid_q_torsion_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&pid_q_torsion_M->solverInfo, (&rtmGetErrorStatus
      (pid_q_torsion_M)));
    rtsiSetRTModelPtr(&pid_q_torsion_M->solverInfo, pid_q_torsion_M);
  }

  rtsiSetSimTimeStep(&pid_q_torsion_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&pid_q_torsion_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&pid_q_torsion_M->solverInfo, false);
  rtsiSetSolverName(&pid_q_torsion_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pid_q_torsion_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "pid_q_torsion_M points to
       static memory which is guaranteed to be non-NULL" */
    pid_q_torsion_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pid_q_torsion_M->Timing.sampleTimes =
      (&pid_q_torsion_M->Timing.sampleTimesArray[0]);
    pid_q_torsion_M->Timing.offsetTimes =
      (&pid_q_torsion_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pid_q_torsion_M->Timing.sampleTimes[0] = (0.0);
    pid_q_torsion_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    pid_q_torsion_M->Timing.offsetTimes[0] = (0.0);
    pid_q_torsion_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(pid_q_torsion_M, &pid_q_torsion_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pid_q_torsion_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    pid_q_torsion_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pid_q_torsion_M, 5.0);
  pid_q_torsion_M->Timing.stepSize0 = 0.002;
  pid_q_torsion_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  pid_q_torsion_M->Sizes.checksums[0] = (2601446562U);
  pid_q_torsion_M->Sizes.checksums[1] = (515984333U);
  pid_q_torsion_M->Sizes.checksums[2] = (673995256U);
  pid_q_torsion_M->Sizes.checksums[3] = (1759387018U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    pid_q_torsion_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pid_q_torsion_M->extModeInfo,
      &pid_q_torsion_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pid_q_torsion_M->extModeInfo,
                        pid_q_torsion_M->Sizes.checksums);
    rteiSetTPtr(pid_q_torsion_M->extModeInfo, rtmGetTPtr(pid_q_torsion_M));
  }

  pid_q_torsion_M->solverInfoPtr = (&pid_q_torsion_M->solverInfo);
  pid_q_torsion_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&pid_q_torsion_M->solverInfo, 0.002);
  rtsiSetSolverMode(&pid_q_torsion_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  pid_q_torsion_M->blockIO = ((void *) &pid_q_torsion_B);

  {
    pid_q_torsion_B.RateLimiter = 0.0;
    pid_q_torsion_B.EncoderCalibrationradcount[0] = 0.0;
    pid_q_torsion_B.EncoderCalibrationradcount[1] = 0.0;
    pid_q_torsion_B.Sum = 0.0;
    pid_q_torsion_B.FilterCoefficient = 0.0;
    pid_q_torsion_B.Saturation = 0.0;
    pid_q_torsion_B.AmplifierGainVV = 0.0;
    pid_q_torsion_B.Gain = 0.0;
    pid_q_torsion_B.Gain_f = 0.0;
    pid_q_torsion_B.IntegralGain = 0.0;
    pid_q_torsion_B.Clock = 0.0;
  }

  /* parameters */
  pid_q_torsion_M->defaultParam = ((real_T *)&pid_q_torsion_P);

  /* states (dwork) */
  pid_q_torsion_M->dwork = ((void *) &pid_q_torsion_DW);
  (void) memset((void *)&pid_q_torsion_DW, 0,
                sizeof(DW_pid_q_torsion_T));
  pid_q_torsion_DW.Integrator_DSTATE = 0.0;
  pid_q_torsion_DW.Filter_DSTATE = 0.0;
  pid_q_torsion_DW.HILInitialize_AIMinimums[0] = 0.0;
  pid_q_torsion_DW.HILInitialize_AIMinimums[1] = 0.0;
  pid_q_torsion_DW.HILInitialize_AIMaximums[0] = 0.0;
  pid_q_torsion_DW.HILInitialize_AIMaximums[1] = 0.0;
  pid_q_torsion_DW.HILInitialize_AOMinimums[0] = 0.0;
  pid_q_torsion_DW.HILInitialize_AOMinimums[1] = 0.0;
  pid_q_torsion_DW.HILInitialize_AOMaximums[0] = 0.0;
  pid_q_torsion_DW.HILInitialize_AOMaximums[1] = 0.0;
  pid_q_torsion_DW.HILInitialize_AOVoltages[0] = 0.0;
  pid_q_torsion_DW.HILInitialize_AOVoltages[1] = 0.0;
  pid_q_torsion_DW.HILInitialize_FilterFrequency[0] = 0.0;
  pid_q_torsion_DW.HILInitialize_FilterFrequency[1] = 0.0;
  pid_q_torsion_DW.PrevY = 0.0;
  pid_q_torsion_DW.LastMajorTime = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pid_q_torsion_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  pid_q_torsion_M->Sizes.numContStates = (0);/* Number of continuous states */
  pid_q_torsion_M->Sizes.numY = (0);   /* Number of model outputs */
  pid_q_torsion_M->Sizes.numU = (0);   /* Number of model inputs */
  pid_q_torsion_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  pid_q_torsion_M->Sizes.numSampTimes = (2);/* Number of sample times */
  pid_q_torsion_M->Sizes.numBlocks = (36);/* Number of blocks */
  pid_q_torsion_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  pid_q_torsion_M->Sizes.numBlockPrms = (113);/* Sum of parameter "widths" */
  return pid_q_torsion_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
