/*
 * q_torsion.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_torsion".
 *
 * Model version              : 27.11
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Feb 27 15:02:37 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_torsion.h"
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
#include "q_torsion_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "q_torsion_dt.h"

/* Block signals (default storage) */
B_q_torsion_T q_torsion_B;

/* Block states (default storage) */
DW_q_torsion_T q_torsion_DW;

/* Real-time model */
static RT_MODEL_q_torsion_T q_torsion_M_;
RT_MODEL_q_torsion_T *const q_torsion_M = &q_torsion_M_;

/* Model output function */
void q_torsion_output(void)
{
  /* local block i/o variables */
  boolean_T rtb_HILWatchdog;
  __m128d tmp_0;
  real_T rtb_HILReadEncoderTimebase[2];
  real_T tmp[2];
  real_T Amplitudedeg;
  real_T rtb_ConverttoVectorState_idx_1;
  real_T rtb_DiscreteTransferFcn;
  real_T rtb_DiscreteTransferFcn_i;
  real_T rtb_ManualSwitch_idx_0;
  real_T rtb_ManualSwitch_idx_1;
  real_T rtb_ManualSwitch_idx_2;
  real_T rtb_ManualSwitch_idx_3;
  boolean_T limitedCache;

  /* S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_torsion/1 DOF Torsion/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_read_encoder(q_torsion_DW.HILReadEncoderTimebase_Task, 1,
      &q_torsion_DW.HILReadEncoderTimebase_Buffer[0]);
    if (result < 0) {
      rtb_HILReadEncoderTimebase[0] = 0;
      rtb_HILReadEncoderTimebase[1] = 0;
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
    } else {
      rtb_HILReadEncoderTimebase[0] =
        q_torsion_DW.HILReadEncoderTimebase_Buffer[0];
      rtb_HILReadEncoderTimebase[1] =
        q_torsion_DW.HILReadEncoderTimebase_Buffer[1];
    }
  }

  /* SignalGenerator: '<S5>/Signal Generator' */
  Amplitudedeg = q_torsion_P.SignalGenerator_Frequency * q_torsion_M->Timing.t[0];
  if (Amplitudedeg - floor(Amplitudedeg) >= 0.5) {
    Amplitudedeg = q_torsion_P.SignalGenerator_Amplitude;
  } else {
    Amplitudedeg = -q_torsion_P.SignalGenerator_Amplitude;
  }

  /* Gain: '<S5>/Amplitude (deg)' incorporates:
   *  SignalGenerator: '<S5>/Signal Generator'
   */
  Amplitudedeg *= q_torsion_P.Amplitudedeg_Gain;

  /* RateLimiter: '<S5>/Rate Limiter' */
  if (q_torsion_DW.LastMajorTime == (rtInf)) {
    /* RateLimiter: '<S5>/Rate Limiter' */
    q_torsion_B.RateLimiter = Amplitudedeg;
  } else {
    rtb_ConverttoVectorState_idx_1 = q_torsion_M->Timing.t[0];
    rtb_DiscreteTransferFcn = rtb_ConverttoVectorState_idx_1 -
      q_torsion_DW.LastMajorTime;
    if (q_torsion_DW.LastMajorTime == rtb_ConverttoVectorState_idx_1) {
      if (q_torsion_DW.PrevLimited) {
        /* RateLimiter: '<S5>/Rate Limiter' */
        q_torsion_B.RateLimiter = q_torsion_DW.PrevY;
      } else {
        /* RateLimiter: '<S5>/Rate Limiter' */
        q_torsion_B.RateLimiter = Amplitudedeg;
      }
    } else {
      rtb_DiscreteTransferFcn_i = rtb_DiscreteTransferFcn *
        q_torsion_P.RateLimiter_RisingLim;
      rtb_ConverttoVectorState_idx_1 = Amplitudedeg - q_torsion_DW.PrevY;
      if (rtb_ConverttoVectorState_idx_1 > rtb_DiscreteTransferFcn_i) {
        /* RateLimiter: '<S5>/Rate Limiter' */
        q_torsion_B.RateLimiter = q_torsion_DW.PrevY + rtb_DiscreteTransferFcn_i;
        limitedCache = true;
      } else {
        rtb_DiscreteTransferFcn *= q_torsion_P.RateLimiter_FallingLim;
        if (rtb_ConverttoVectorState_idx_1 < rtb_DiscreteTransferFcn) {
          /* RateLimiter: '<S5>/Rate Limiter' */
          q_torsion_B.RateLimiter = q_torsion_DW.PrevY + rtb_DiscreteTransferFcn;
          limitedCache = true;
        } else {
          /* RateLimiter: '<S5>/Rate Limiter' */
          q_torsion_B.RateLimiter = Amplitudedeg;
          limitedCache = false;
        }
      }

      if (rtsiIsModeUpdateTimeStep(&q_torsion_M->solverInfo)) {
        q_torsion_DW.PrevLimited = limitedCache;
      }
    }
  }

  /* End of RateLimiter: '<S5>/Rate Limiter' */

  /* Gain: '<S11>/Gain1' */
  tmp_0 = _mm_set1_pd(q_torsion_P.Gain1_Gain * q_torsion_B.RateLimiter);

  /* Gain: '<S5>/Convert to  Vector State' */
  _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_loadu_pd
    (&q_torsion_P.ConverttoVectorState_Gain[0]), tmp_0));

  /* Gain: '<S5>/Convert to  Vector State' */
  Amplitudedeg = tmp[0];
  rtb_ConverttoVectorState_idx_1 = tmp[1];

  /* Gain: '<S5>/Convert to  Vector State' */
  _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_loadu_pd
    (&q_torsion_P.ConverttoVectorState_Gain[2]), tmp_0));

  /* Gain: '<S1>/Encoder Calibration  (rad//count)' */
  tmp_0 = _mm_mul_pd(_mm_set1_pd(q_torsion_P.K_ENC), _mm_loadu_pd
                     (&rtb_HILReadEncoderTimebase[0]));

  /* Gain: '<S1>/Encoder Calibration  (rad//count)' */
  _mm_storeu_pd(&rtb_HILReadEncoderTimebase[0], tmp_0);

  /* DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  q_torsion_DW.DiscreteTransferFcn_tmp = ((rtb_HILReadEncoderTimebase[0] -
    q_torsion_DW.DiscreteTransferFcn_states[0] *
    q_torsion_P.DiscreteTransferFcn_DenCoef[1]) -
    q_torsion_DW.DiscreteTransferFcn_states[1] *
    q_torsion_P.DiscreteTransferFcn_DenCoef[2]) /
    q_torsion_P.DiscreteTransferFcn_DenCoef[0];
  rtb_DiscreteTransferFcn = (q_torsion_P.DiscreteTransferFcn_NumCoef[0] *
    q_torsion_DW.DiscreteTransferFcn_tmp +
    q_torsion_DW.DiscreteTransferFcn_states[0] *
    q_torsion_P.DiscreteTransferFcn_NumCoef[1]) +
    q_torsion_DW.DiscreteTransferFcn_states[1] *
    q_torsion_P.DiscreteTransferFcn_NumCoef[2];

  /* DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  q_torsion_DW.DiscreteTransferFcn_tmp_d = ((rtb_HILReadEncoderTimebase[1] -
    q_torsion_DW.DiscreteTransferFcn_states_g[0] *
    q_torsion_P.DiscreteTransferFcn_DenCoef_k[1]) -
    q_torsion_DW.DiscreteTransferFcn_states_g[1] *
    q_torsion_P.DiscreteTransferFcn_DenCoef_k[2]) /
    q_torsion_P.DiscreteTransferFcn_DenCoef_k[0];
  rtb_DiscreteTransferFcn_i = (q_torsion_P.DiscreteTransferFcn_NumCoef_h[0] *
    q_torsion_DW.DiscreteTransferFcn_tmp_d +
    q_torsion_DW.DiscreteTransferFcn_states_g[0] *
    q_torsion_P.DiscreteTransferFcn_NumCoef_h[1]) +
    q_torsion_DW.DiscreteTransferFcn_states_g[1] *
    q_torsion_P.DiscreteTransferFcn_NumCoef_h[2];

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Full-State Feedback'
   *  Constant: '<Root>/Partial-State Feedback'
   */
  if (q_torsion_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch_idx_0 = q_torsion_P.FullStateFeedback_Value[0];
    rtb_ManualSwitch_idx_1 = q_torsion_P.FullStateFeedback_Value[1];
    rtb_ManualSwitch_idx_2 = q_torsion_P.FullStateFeedback_Value[2];
    rtb_ManualSwitch_idx_3 = q_torsion_P.FullStateFeedback_Value[3];
  } else {
    rtb_ManualSwitch_idx_0 = q_torsion_P.PartialStateFeedback_Value[0];
    rtb_ManualSwitch_idx_1 = q_torsion_P.PartialStateFeedback_Value[1];
    rtb_ManualSwitch_idx_2 = q_torsion_P.PartialStateFeedback_Value[2];
    rtb_ManualSwitch_idx_3 = q_torsion_P.PartialStateFeedback_Value[3];
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Product: '<Root>/FS // PS' */
  tmp_0 = _mm_mul_pd(_mm_loadu_pd(&rtb_HILReadEncoderTimebase[0]), _mm_set_pd
                     (rtb_ManualSwitch_idx_1, rtb_ManualSwitch_idx_0));

  /* Product: '<Root>/FS // PS' */
  _mm_storeu_pd(&q_torsion_B.FSPS[0], tmp_0);
  q_torsion_B.FSPS[2] = rtb_DiscreteTransferFcn * rtb_ManualSwitch_idx_2;
  q_torsion_B.FSPS[3] = rtb_DiscreteTransferFcn_i * rtb_ManualSwitch_idx_3;

  /* Gain: '<Root>/Control Gain' incorporates:
   *  Sum: '<Root>/Sum'
   */
  rtb_ManualSwitch_idx_0 = (((Amplitudedeg - q_torsion_B.FSPS[0]) *
    q_torsion_P.K[0] + (rtb_ConverttoVectorState_idx_1 - q_torsion_B.FSPS[1]) *
    q_torsion_P.K[1]) + (tmp[0] - q_torsion_B.FSPS[2]) * q_torsion_P.K[2]) +
    (tmp[1] - q_torsion_B.FSPS[3]) * q_torsion_P.K[3];

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Gain: '<Root>/Control Gain'
   */
  if (rtb_ManualSwitch_idx_0 > q_torsion_P.Saturation_UpperSat) {
    rtb_ManualSwitch_idx_0 = q_torsion_P.Saturation_UpperSat;
  } else if (rtb_ManualSwitch_idx_0 < q_torsion_P.Saturation_LowerSat) {
    rtb_ManualSwitch_idx_0 = q_torsion_P.Saturation_LowerSat;
  }

  /* Gain: '<S6>/Direction Convention: (Right-Hand) system' incorporates:
   *  Saturate: '<Root>/Saturation'
   */
  rtb_ManualSwitch_idx_0 *= q_torsion_P.DirectionConventionRightHandsys;

  /* Saturate: '<S6>/Amplifier  Saturation (V)' */
  if (rtb_ManualSwitch_idx_0 > q_torsion_P.VMAX_AMP) {
    rtb_ManualSwitch_idx_0 = q_torsion_P.VMAX_AMP;
  } else if (rtb_ManualSwitch_idx_0 < -q_torsion_P.VMAX_AMP) {
    rtb_ManualSwitch_idx_0 = -q_torsion_P.VMAX_AMP;
  }

  /* Gain: '<S6>/Inverse Amplifier  Gain (V//V)' incorporates:
   *  Saturate: '<S6>/Amplifier  Saturation (V)'
   */
  rtb_ManualSwitch_idx_0 *= 1.0 / q_torsion_P.K_AMP;

  /* Saturate: '<S6>/DACB Saturation (V)' */
  if (rtb_ManualSwitch_idx_0 > q_torsion_P.VMAX_DAC) {
    /* Saturate: '<S6>/DACB Saturation (V)' */
    q_torsion_B.DACBSaturationV = q_torsion_P.VMAX_DAC;
  } else if (rtb_ManualSwitch_idx_0 < -q_torsion_P.VMAX_DAC) {
    /* Saturate: '<S6>/DACB Saturation (V)' */
    q_torsion_B.DACBSaturationV = -q_torsion_P.VMAX_DAC;
  } else {
    /* Saturate: '<S6>/DACB Saturation (V)' */
    q_torsion_B.DACBSaturationV = rtb_ManualSwitch_idx_0;
  }

  /* End of Saturate: '<S6>/DACB Saturation (V)' */

  /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

  /* S-Function Block: q_torsion/1 DOF Torsion/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(q_torsion_DW.HILInitialize_Card,
      &q_torsion_P.HILWriteAnalog_channels, 1, &q_torsion_B.DACBSaturationV);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
    }
  }

  /* Gain: '<S6>/Amplifier  Gain (V//V)' */
  q_torsion_B.AmplifierGainVV = -q_torsion_P.K_AMP * q_torsion_B.DACBSaturationV;

  /* S-Function (hil_write_digital_block): '<S1>/HIL Write Digital' incorporates:
   *  Constant: '<S1>/Enable VoltPAQ-X2,X4'
   */

  /* S-Function Block: q_torsion/1 DOF Torsion/HIL Write Digital (hil_write_digital_block) */
  {
    t_error result;
    q_torsion_DW.HILWriteDigital_Buffer[0] =
      (q_torsion_P.EnableVoltPAQX2X4_Value[0] != 0);
    q_torsion_DW.HILWriteDigital_Buffer[1] =
      (q_torsion_P.EnableVoltPAQX2X4_Value[1] != 0);
    q_torsion_DW.HILWriteDigital_Buffer[2] =
      (q_torsion_P.EnableVoltPAQX2X4_Value[2] != 0);
    q_torsion_DW.HILWriteDigital_Buffer[3] =
      (q_torsion_P.EnableVoltPAQX2X4_Value[3] != 0);
    result = hil_write_digital(q_torsion_DW.HILInitialize_Card,
      q_torsion_P.HILWriteDigital_channels, 4,
      &q_torsion_DW.HILWriteDigital_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
    }
  }

  /* S-Function (hil_watchdog_block): '<S1>/HIL Watchdog' */

  /* S-Function Block: q_torsion/1 DOF Torsion/HIL Watchdog (hil_watchdog_block) */
  {
    t_error result;
    if (q_torsion_DW.HILWatchdog_IsStarted) {
      result = hil_watchdog_reload(q_torsion_DW.HILInitialize_Card);
    } else {
      result = hil_watchdog_start(q_torsion_DW.HILInitialize_Card,
        q_torsion_P.HILWatchdog_Timeout);
      if (result == 0) {
        q_torsion_DW.HILWatchdog_IsStarted = true;
        result = 1;                    /* indicate watchdog has not expired */
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
    }

    rtb_HILWatchdog = (result == 0);
  }

  /* S-Function (stop_with_error_block): '<S1>/Stop with Error' */

  /* S-Function Block: q_torsion/1 DOF Torsion/Stop with Error (stop_with_error_block) */
  {
    if (rtb_HILWatchdog) {
      rtmSetErrorStatus(q_torsion_M, "Stopped by watchdog.");
      return;
    }
  }

  /* Gain: '<S10>/Gain' */
  q_torsion_B.Gain[0] = q_torsion_P.Gain_Gain * Amplitudedeg;
  q_torsion_B.Gain[1] = q_torsion_P.Gain_Gain * rtb_ConverttoVectorState_idx_1;
  q_torsion_B.Gain[2] = q_torsion_P.Gain_Gain * tmp[0];
  q_torsion_B.Gain[3] = q_torsion_P.Gain_Gain * tmp[1];

  /* Gain: '<S9>/Gain' */
  tmp_0 = _mm_mul_pd(_mm_set1_pd(q_torsion_P.Gain_Gain_p), _mm_loadu_pd
                     (&rtb_HILReadEncoderTimebase[0]));

  /* Gain: '<S9>/Gain' */
  _mm_storeu_pd(&q_torsion_B.Gain_i[0], tmp_0);
  q_torsion_B.Gain_i[2] = q_torsion_P.Gain_Gain_p * rtb_DiscreteTransferFcn;
  q_torsion_B.Gain_i[3] = q_torsion_P.Gain_Gain_p * rtb_DiscreteTransferFcn_i;
}

/* Model update function */
void q_torsion_update(void)
{
  /* Update for RateLimiter: '<S5>/Rate Limiter' */
  q_torsion_DW.PrevY = q_torsion_B.RateLimiter;
  q_torsion_DW.LastMajorTime = q_torsion_M->Timing.t[0];

  /* Update for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  q_torsion_DW.DiscreteTransferFcn_states[1] =
    q_torsion_DW.DiscreteTransferFcn_states[0];
  q_torsion_DW.DiscreteTransferFcn_states[0] =
    q_torsion_DW.DiscreteTransferFcn_tmp;

  /* Update for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  q_torsion_DW.DiscreteTransferFcn_states_g[1] =
    q_torsion_DW.DiscreteTransferFcn_states_g[0];
  q_torsion_DW.DiscreteTransferFcn_states_g[0] =
    q_torsion_DW.DiscreteTransferFcn_tmp_d;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++q_torsion_M->Timing.clockTick0)) {
    ++q_torsion_M->Timing.clockTickH0;
  }

  q_torsion_M->Timing.t[0] = q_torsion_M->Timing.clockTick0 *
    q_torsion_M->Timing.stepSize0 + q_torsion_M->Timing.clockTickH0 *
    q_torsion_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++q_torsion_M->Timing.clockTick1)) {
      ++q_torsion_M->Timing.clockTickH1;
    }

    q_torsion_M->Timing.t[1] = q_torsion_M->Timing.clockTick1 *
      q_torsion_M->Timing.stepSize1 + q_torsion_M->Timing.clockTickH1 *
      q_torsion_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void q_torsion_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_torsion/1 DOF Torsion/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &q_torsion_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(q_torsion_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal", 50);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(q_torsion_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
      return;
    }

    if ((q_torsion_P.HILInitialize_AIPStart && !is_switching) ||
        (q_torsion_P.HILInitialize_AIPEnter && is_switching)) {
      q_torsion_DW.HILInitialize_AIMinimums[0] =
        (q_torsion_P.HILInitialize_AILow);
      q_torsion_DW.HILInitialize_AIMinimums[1] =
        (q_torsion_P.HILInitialize_AILow);
      q_torsion_DW.HILInitialize_AIMaximums[0] =
        q_torsion_P.HILInitialize_AIHigh;
      q_torsion_DW.HILInitialize_AIMaximums[1] =
        q_torsion_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(q_torsion_DW.HILInitialize_Card,
        q_torsion_P.HILInitialize_AIChannels, 2U,
        &q_torsion_DW.HILInitialize_AIMinimums[0],
        &q_torsion_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        return;
      }
    }

    if ((q_torsion_P.HILInitialize_AOPStart && !is_switching) ||
        (q_torsion_P.HILInitialize_AOPEnter && is_switching)) {
      q_torsion_DW.HILInitialize_AOMinimums[0] =
        (q_torsion_P.HILInitialize_AOLow);
      q_torsion_DW.HILInitialize_AOMinimums[1] =
        (q_torsion_P.HILInitialize_AOLow);
      q_torsion_DW.HILInitialize_AOMaximums[0] =
        q_torsion_P.HILInitialize_AOHigh;
      q_torsion_DW.HILInitialize_AOMaximums[1] =
        q_torsion_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(q_torsion_DW.HILInitialize_Card,
        q_torsion_P.HILInitialize_AOChannels, 2U,
        &q_torsion_DW.HILInitialize_AOMinimums[0],
        &q_torsion_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        return;
      }
    }

    if ((q_torsion_P.HILInitialize_AOStart && !is_switching) ||
        (q_torsion_P.HILInitialize_AOEnter && is_switching)) {
      q_torsion_DW.HILInitialize_AOVoltages[0] =
        q_torsion_P.HILInitialize_AOInitial;
      q_torsion_DW.HILInitialize_AOVoltages[1] =
        q_torsion_P.HILInitialize_AOInitial;
      result = hil_write_analog(q_torsion_DW.HILInitialize_Card,
        q_torsion_P.HILInitialize_AOChannels, 2U,
        &q_torsion_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        return;
      }
    }

    if (q_torsion_P.HILInitialize_AOReset) {
      q_torsion_DW.HILInitialize_AOVoltages[0] =
        q_torsion_P.HILInitialize_AOWatchdog;
      q_torsion_DW.HILInitialize_AOVoltages[1] =
        q_torsion_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (q_torsion_DW.HILInitialize_Card, q_torsion_P.HILInitialize_AOChannels,
         2U, &q_torsion_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(q_torsion_DW.HILInitialize_Card, NULL,
      0U, q_torsion_P.HILInitialize_DOChannels, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
      return;
    }

    if ((q_torsion_P.HILInitialize_DOStart && !is_switching) ||
        (q_torsion_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &q_torsion_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = q_torsion_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(q_torsion_DW.HILInitialize_Card,
        q_torsion_P.HILInitialize_DOChannels, 8U, (t_boolean *)
        &q_torsion_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        return;
      }
    }

    if (q_torsion_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &q_torsion_DW.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = q_torsion_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (q_torsion_DW.HILInitialize_Card, q_torsion_P.HILInitialize_DOChannels,
         8U, (const t_digital_state *) &q_torsion_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        return;
      }
    }

    if ((q_torsion_P.HILInitialize_EIPStart && !is_switching) ||
        (q_torsion_P.HILInitialize_EIPEnter && is_switching)) {
      q_torsion_DW.HILInitialize_QuadratureModes[0] =
        q_torsion_P.HILInitialize_EIQuadrature;
      q_torsion_DW.HILInitialize_QuadratureModes[1] =
        q_torsion_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(q_torsion_DW.HILInitialize_Card,
        q_torsion_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &q_torsion_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        return;
      }
    }

    if ((q_torsion_P.HILInitialize_EIStart && !is_switching) ||
        (q_torsion_P.HILInitialize_EIEnter && is_switching)) {
      q_torsion_DW.HILInitialize_InitialEICounts[0] =
        q_torsion_P.HILInitialize_EIInitial;
      q_torsion_DW.HILInitialize_InitialEICounts[1] =
        q_torsion_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(q_torsion_DW.HILInitialize_Card,
        q_torsion_P.HILInitialize_EIChannels, 2U,
        &q_torsion_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_torsion/1 DOF Torsion/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(q_torsion_DW.HILInitialize_Card,
      q_torsion_P.HILReadEncoderTimebase_SamplesI,
      q_torsion_P.HILReadEncoderTimebase_Channels, 2,
      &q_torsion_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (q_torsion_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (q_torsion_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_torsion_M, _rt_error_message);
    }
  }

  /* Start for S-Function (hil_watchdog_block): '<S1>/HIL Watchdog' */

  /* S-Function Block: q_torsion/1 DOF Torsion/HIL Watchdog (hil_watchdog_block) */
  {
    q_torsion_DW.HILWatchdog_IsStarted = false;
  }

  /* InitializeConditions for RateLimiter: '<S5>/Rate Limiter' */
  q_torsion_DW.LastMajorTime = (rtInf);

  /* InitializeConditions for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  q_torsion_DW.DiscreteTransferFcn_states[0] =
    q_torsion_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  q_torsion_DW.DiscreteTransferFcn_states_g[0] =
    q_torsion_P.DiscreteTransferFcn_InitialSt_n;

  /* InitializeConditions for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  q_torsion_DW.DiscreteTransferFcn_states[1] =
    q_torsion_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteTransferFcn: '<S8>/Discrete Transfer Fcn' */
  q_torsion_DW.DiscreteTransferFcn_states_g[1] =
    q_torsion_P.DiscreteTransferFcn_InitialSt_n;
}

/* Model terminate function */
void q_torsion_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_torsion/1 DOF Torsion/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(q_torsion_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_torsion_DW.HILInitialize_Card);
    is_switching = false;

    /* S-Function Block: q_torsion/1 DOF Torsion/HIL Watchdog (hil_watchdog_block) */
    {
      hil_watchdog_stop(q_torsion_DW.HILInitialize_Card);
    }

    if ((q_torsion_P.HILInitialize_AOTerminate && !is_switching) ||
        (q_torsion_P.HILInitialize_AOExit && is_switching)) {
      q_torsion_DW.HILInitialize_AOVoltages[0] =
        q_torsion_P.HILInitialize_AOFinal;
      q_torsion_DW.HILInitialize_AOVoltages[1] =
        q_torsion_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((q_torsion_P.HILInitialize_DOTerminate && !is_switching) ||
        (q_torsion_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &q_torsion_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = q_torsion_P.HILInitialize_DOFinal;
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
      result = hil_write(q_torsion_DW.HILInitialize_Card
                         , q_torsion_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , q_torsion_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &q_torsion_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *) &q_torsion_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(q_torsion_DW.HILInitialize_Card,
            q_torsion_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &q_torsion_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(q_torsion_DW.HILInitialize_Card,
            q_torsion_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &q_torsion_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_torsion_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(q_torsion_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_torsion_DW.HILInitialize_Card);
    hil_close(q_torsion_DW.HILInitialize_Card);
    q_torsion_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  q_torsion_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  q_torsion_update();
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
  q_torsion_initialize();
}

void MdlTerminate(void)
{
  q_torsion_terminate();
}

/* Registration function */
RT_MODEL_q_torsion_T *q_torsion(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_torsion_M, 0,
                sizeof(RT_MODEL_q_torsion_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_torsion_M->solverInfo,
                          &q_torsion_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_torsion_M->solverInfo, &rtmGetTPtr(q_torsion_M));
    rtsiSetStepSizePtr(&q_torsion_M->solverInfo, &q_torsion_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&q_torsion_M->solverInfo, (&rtmGetErrorStatus
      (q_torsion_M)));
    rtsiSetRTModelPtr(&q_torsion_M->solverInfo, q_torsion_M);
  }

  rtsiSetSimTimeStep(&q_torsion_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&q_torsion_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&q_torsion_M->solverInfo, false);
  rtsiSetSolverName(&q_torsion_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_torsion_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "q_torsion_M points to
       static memory which is guaranteed to be non-NULL" */
    q_torsion_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_torsion_M->Timing.sampleTimes = (&q_torsion_M->Timing.sampleTimesArray[0]);
    q_torsion_M->Timing.offsetTimes = (&q_torsion_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_torsion_M->Timing.sampleTimes[0] = (0.0);
    q_torsion_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    q_torsion_M->Timing.offsetTimes[0] = (0.0);
    q_torsion_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(q_torsion_M, &q_torsion_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_torsion_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    q_torsion_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_torsion_M, 5.0);
  q_torsion_M->Timing.stepSize0 = 0.002;
  q_torsion_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  q_torsion_M->Sizes.checksums[0] = (2696868110U);
  q_torsion_M->Sizes.checksums[1] = (3885134512U);
  q_torsion_M->Sizes.checksums[2] = (1457859589U);
  q_torsion_M->Sizes.checksums[3] = (233956950U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    q_torsion_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_torsion_M->extModeInfo,
      &q_torsion_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_torsion_M->extModeInfo, q_torsion_M->Sizes.checksums);
    rteiSetTPtr(q_torsion_M->extModeInfo, rtmGetTPtr(q_torsion_M));
  }

  q_torsion_M->solverInfoPtr = (&q_torsion_M->solverInfo);
  q_torsion_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&q_torsion_M->solverInfo, 0.002);
  rtsiSetSolverMode(&q_torsion_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  q_torsion_M->blockIO = ((void *) &q_torsion_B);

  {
    q_torsion_B.RateLimiter = 0.0;
    q_torsion_B.FSPS[0] = 0.0;
    q_torsion_B.FSPS[1] = 0.0;
    q_torsion_B.FSPS[2] = 0.0;
    q_torsion_B.FSPS[3] = 0.0;
    q_torsion_B.DACBSaturationV = 0.0;
    q_torsion_B.AmplifierGainVV = 0.0;
    q_torsion_B.Gain[0] = 0.0;
    q_torsion_B.Gain[1] = 0.0;
    q_torsion_B.Gain[2] = 0.0;
    q_torsion_B.Gain[3] = 0.0;
    q_torsion_B.Gain_i[0] = 0.0;
    q_torsion_B.Gain_i[1] = 0.0;
    q_torsion_B.Gain_i[2] = 0.0;
    q_torsion_B.Gain_i[3] = 0.0;
  }

  /* parameters */
  q_torsion_M->defaultParam = ((real_T *)&q_torsion_P);

  /* states (dwork) */
  q_torsion_M->dwork = ((void *) &q_torsion_DW);
  (void) memset((void *)&q_torsion_DW, 0,
                sizeof(DW_q_torsion_T));
  q_torsion_DW.DiscreteTransferFcn_states[0] = 0.0;
  q_torsion_DW.DiscreteTransferFcn_states[1] = 0.0;
  q_torsion_DW.DiscreteTransferFcn_states_g[0] = 0.0;
  q_torsion_DW.DiscreteTransferFcn_states_g[1] = 0.0;
  q_torsion_DW.HILInitialize_AIMinimums[0] = 0.0;
  q_torsion_DW.HILInitialize_AIMinimums[1] = 0.0;
  q_torsion_DW.HILInitialize_AIMaximums[0] = 0.0;
  q_torsion_DW.HILInitialize_AIMaximums[1] = 0.0;
  q_torsion_DW.HILInitialize_AOMinimums[0] = 0.0;
  q_torsion_DW.HILInitialize_AOMinimums[1] = 0.0;
  q_torsion_DW.HILInitialize_AOMaximums[0] = 0.0;
  q_torsion_DW.HILInitialize_AOMaximums[1] = 0.0;
  q_torsion_DW.HILInitialize_AOVoltages[0] = 0.0;
  q_torsion_DW.HILInitialize_AOVoltages[1] = 0.0;
  q_torsion_DW.HILInitialize_FilterFrequency[0] = 0.0;
  q_torsion_DW.HILInitialize_FilterFrequency[1] = 0.0;
  q_torsion_DW.PrevY = 0.0;
  q_torsion_DW.LastMajorTime = 0.0;
  q_torsion_DW.DiscreteTransferFcn_tmp = 0.0;
  q_torsion_DW.DiscreteTransferFcn_tmp_d = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_torsion_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_torsion_M->Sizes.numContStates = (0);/* Number of continuous states */
  q_torsion_M->Sizes.numY = (0);       /* Number of model outputs */
  q_torsion_M->Sizes.numU = (0);       /* Number of model inputs */
  q_torsion_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_torsion_M->Sizes.numSampTimes = (2);/* Number of sample times */
  q_torsion_M->Sizes.numBlocks = (34); /* Number of blocks */
  q_torsion_M->Sizes.numBlockIO = (8); /* Number of block outputs */
  q_torsion_M->Sizes.numBlockPrms = (136);/* Sum of parameter "widths" */
  return q_torsion_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
