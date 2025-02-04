/*
 * SRV02_demo.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SRV02_demo".
 *
 * Model version              : 9.0
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 23 14:07:10 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SRV02_demo.h"
#include <math.h>
#include "rtwtypes.h"
#include "SRV02_demo_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "SRV02_demo_dt.h"

/* Block signals (default storage) */
B_SRV02_demo_T SRV02_demo_B;

/* Block states (default storage) */
DW_SRV02_demo_T SRV02_demo_DW;

/* Real-time model */
static RT_MODEL_SRV02_demo_T SRV02_demo_M_;
RT_MODEL_SRV02_demo_T *const SRV02_demo_M = &SRV02_demo_M_;

/* Model output function */
void SRV02_demo_output(void)
{
  real_T rtb_HILReadEncoder;

  /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder' */

  /* S-Function Block: SRV02_demo/SRV-02/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(SRV02_demo_DW.HILInitialize_Card,
      &SRV02_demo_P.HILReadEncoder_channels, 1,
      &SRV02_demo_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder = SRV02_demo_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<S1>/Servo:  Counts to Rad' */
  SRV02_demo_B.ServoCountstoRad = SRV02_demo_P.ServoCountstoRad_Gain *
    rtb_HILReadEncoder;

  /* S-Function (hil_read_analog_block): '<S1>/HIL Read Analog' */

  /* S-Function Block: SRV02_demo/SRV-02/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(SRV02_demo_DW.HILInitialize_Card,
      &SRV02_demo_P.HILReadAnalog_channels, 1,
      &SRV02_demo_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
    }

    SRV02_demo_B.HILReadAnalog = SRV02_demo_DW.HILReadAnalog_Buffer;
  }

  /* Sin: '<Root>/Sine Wave' */
  rtb_HILReadEncoder = sin(SRV02_demo_P.SineWave_Freq * SRV02_demo_M->Timing.t[0]
    + SRV02_demo_P.SineWave_Phase) * SRV02_demo_P.SineWave_Amp +
    SRV02_demo_P.SineWave_Bias;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_HILReadEncoder > SRV02_demo_P.Saturation_UpperSat) {
    /* Saturate: '<S1>/Saturation' */
    SRV02_demo_B.Saturation = SRV02_demo_P.Saturation_UpperSat;
  } else if (rtb_HILReadEncoder < SRV02_demo_P.Saturation_LowerSat) {
    /* Saturate: '<S1>/Saturation' */
    SRV02_demo_B.Saturation = SRV02_demo_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S1>/Saturation' */
    SRV02_demo_B.Saturation = rtb_HILReadEncoder;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (hil_write_block): '<S1>/HIL Write' */

  /* S-Function Block: SRV02_demo/SRV-02/HIL Write (hil_write_block) */
  {
    t_error result;
    result = hil_write(SRV02_demo_DW.HILInitialize_Card,
                       &SRV02_demo_P.HILWrite_analog_channels, 1U,
                       NULL, 0U,
                       NULL, 0U,
                       NULL, 0U,
                       &SRV02_demo_B.Saturation,
                       NULL,
                       NULL,
                       NULL
                       );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
    }
  }
}

/* Model update function */
void SRV02_demo_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++SRV02_demo_M->Timing.clockTick0)) {
    ++SRV02_demo_M->Timing.clockTickH0;
  }

  SRV02_demo_M->Timing.t[0] = SRV02_demo_M->Timing.clockTick0 *
    SRV02_demo_M->Timing.stepSize0 + SRV02_demo_M->Timing.clockTickH0 *
    SRV02_demo_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++SRV02_demo_M->Timing.clockTick1)) {
      ++SRV02_demo_M->Timing.clockTickH1;
    }

    SRV02_demo_M->Timing.t[1] = SRV02_demo_M->Timing.clockTick1 *
      SRV02_demo_M->Timing.stepSize1 + SRV02_demo_M->Timing.clockTickH1 *
      SRV02_demo_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void SRV02_demo_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: SRV02_demo/SRV-02/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &SRV02_demo_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(SRV02_demo_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(SRV02_demo_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
      return;
    }

    if ((SRV02_demo_P.HILInitialize_AIPStart && !is_switching) ||
        (SRV02_demo_P.HILInitialize_AIPEnter && is_switching)) {
      SRV02_demo_DW.HILInitialize_AIMinimums[0] =
        (SRV02_demo_P.HILInitialize_AILow);
      SRV02_demo_DW.HILInitialize_AIMinimums[1] =
        (SRV02_demo_P.HILInitialize_AILow);
      SRV02_demo_DW.HILInitialize_AIMaximums[0] =
        SRV02_demo_P.HILInitialize_AIHigh;
      SRV02_demo_DW.HILInitialize_AIMaximums[1] =
        SRV02_demo_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(SRV02_demo_DW.HILInitialize_Card,
        SRV02_demo_P.HILInitialize_AIChannels, 2U,
        &SRV02_demo_DW.HILInitialize_AIMinimums[0],
        &SRV02_demo_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
        return;
      }
    }

    if ((SRV02_demo_P.HILInitialize_AOPStart && !is_switching) ||
        (SRV02_demo_P.HILInitialize_AOPEnter && is_switching)) {
      SRV02_demo_DW.HILInitialize_AOMinimums[0] =
        (SRV02_demo_P.HILInitialize_AOLow);
      SRV02_demo_DW.HILInitialize_AOMinimums[1] =
        (SRV02_demo_P.HILInitialize_AOLow);
      SRV02_demo_DW.HILInitialize_AOMaximums[0] =
        SRV02_demo_P.HILInitialize_AOHigh;
      SRV02_demo_DW.HILInitialize_AOMaximums[1] =
        SRV02_demo_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(SRV02_demo_DW.HILInitialize_Card,
        SRV02_demo_P.HILInitialize_AOChannels, 2U,
        &SRV02_demo_DW.HILInitialize_AOMinimums[0],
        &SRV02_demo_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
        return;
      }
    }

    if ((SRV02_demo_P.HILInitialize_AOStart && !is_switching) ||
        (SRV02_demo_P.HILInitialize_AOEnter && is_switching)) {
      SRV02_demo_DW.HILInitialize_AOVoltages[0] =
        SRV02_demo_P.HILInitialize_AOInitial;
      SRV02_demo_DW.HILInitialize_AOVoltages[1] =
        SRV02_demo_P.HILInitialize_AOInitial;
      result = hil_write_analog(SRV02_demo_DW.HILInitialize_Card,
        SRV02_demo_P.HILInitialize_AOChannels, 2U,
        &SRV02_demo_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
        return;
      }
    }

    if (SRV02_demo_P.HILInitialize_AOReset) {
      SRV02_demo_DW.HILInitialize_AOVoltages[0] =
        SRV02_demo_P.HILInitialize_AOWatchdog;
      SRV02_demo_DW.HILInitialize_AOVoltages[1] =
        SRV02_demo_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (SRV02_demo_DW.HILInitialize_Card, SRV02_demo_P.HILInitialize_AOChannels,
         2U, &SRV02_demo_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
        return;
      }
    }

    if ((SRV02_demo_P.HILInitialize_EIPStart && !is_switching) ||
        (SRV02_demo_P.HILInitialize_EIPEnter && is_switching)) {
      SRV02_demo_DW.HILInitialize_QuadratureModes[0] =
        SRV02_demo_P.HILInitialize_EIQuadrature;
      SRV02_demo_DW.HILInitialize_QuadratureModes[1] =
        SRV02_demo_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(SRV02_demo_DW.HILInitialize_Card,
        SRV02_demo_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &SRV02_demo_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
        return;
      }
    }

    if ((SRV02_demo_P.HILInitialize_EIStart && !is_switching) ||
        (SRV02_demo_P.HILInitialize_EIEnter && is_switching)) {
      SRV02_demo_DW.HILInitialize_InitialEICounts[0] =
        SRV02_demo_P.HILInitialize_EIInitial;
      SRV02_demo_DW.HILInitialize_InitialEICounts[1] =
        SRV02_demo_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(SRV02_demo_DW.HILInitialize_Card,
        SRV02_demo_P.HILInitialize_EIChannels, 2U,
        &SRV02_demo_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void SRV02_demo_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: SRV02_demo/SRV-02/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(SRV02_demo_DW.HILInitialize_Card);
    hil_monitor_stop_all(SRV02_demo_DW.HILInitialize_Card);
    is_switching = false;
    if ((SRV02_demo_P.HILInitialize_AOTerminate && !is_switching) ||
        (SRV02_demo_P.HILInitialize_AOExit && is_switching)) {
      SRV02_demo_DW.HILInitialize_AOVoltages[0] =
        SRV02_demo_P.HILInitialize_AOFinal;
      SRV02_demo_DW.HILInitialize_AOVoltages[1] =
        SRV02_demo_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(SRV02_demo_DW.HILInitialize_Card,
        SRV02_demo_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &SRV02_demo_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(SRV02_demo_M, _rt_error_message);
      }
    }

    hil_task_delete_all(SRV02_demo_DW.HILInitialize_Card);
    hil_monitor_delete_all(SRV02_demo_DW.HILInitialize_Card);
    hil_close(SRV02_demo_DW.HILInitialize_Card);
    SRV02_demo_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  SRV02_demo_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  SRV02_demo_update();
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
  SRV02_demo_initialize();
}

void MdlTerminate(void)
{
  SRV02_demo_terminate();
}

/* Registration function */
RT_MODEL_SRV02_demo_T *SRV02_demo(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SRV02_demo_M, 0,
                sizeof(RT_MODEL_SRV02_demo_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SRV02_demo_M->solverInfo,
                          &SRV02_demo_M->Timing.simTimeStep);
    rtsiSetTPtr(&SRV02_demo_M->solverInfo, &rtmGetTPtr(SRV02_demo_M));
    rtsiSetStepSizePtr(&SRV02_demo_M->solverInfo,
                       &SRV02_demo_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&SRV02_demo_M->solverInfo, (&rtmGetErrorStatus
      (SRV02_demo_M)));
    rtsiSetRTModelPtr(&SRV02_demo_M->solverInfo, SRV02_demo_M);
  }

  rtsiSetSimTimeStep(&SRV02_demo_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&SRV02_demo_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&SRV02_demo_M->solverInfo, false);
  rtsiSetSolverName(&SRV02_demo_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = SRV02_demo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "SRV02_demo_M points to
       static memory which is guaranteed to be non-NULL" */
    SRV02_demo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SRV02_demo_M->Timing.sampleTimes = (&SRV02_demo_M->Timing.sampleTimesArray[0]);
    SRV02_demo_M->Timing.offsetTimes = (&SRV02_demo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SRV02_demo_M->Timing.sampleTimes[0] = (0.0);
    SRV02_demo_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    SRV02_demo_M->Timing.offsetTimes[0] = (0.0);
    SRV02_demo_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(SRV02_demo_M, &SRV02_demo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = SRV02_demo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    SRV02_demo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SRV02_demo_M, -1);
  SRV02_demo_M->Timing.stepSize0 = 0.002;
  SRV02_demo_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  SRV02_demo_M->Sizes.checksums[0] = (4278095746U);
  SRV02_demo_M->Sizes.checksums[1] = (3039447201U);
  SRV02_demo_M->Sizes.checksums[2] = (1970314540U);
  SRV02_demo_M->Sizes.checksums[3] = (3297069348U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    SRV02_demo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SRV02_demo_M->extModeInfo,
      &SRV02_demo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SRV02_demo_M->extModeInfo, SRV02_demo_M->Sizes.checksums);
    rteiSetTPtr(SRV02_demo_M->extModeInfo, rtmGetTPtr(SRV02_demo_M));
  }

  SRV02_demo_M->solverInfoPtr = (&SRV02_demo_M->solverInfo);
  SRV02_demo_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&SRV02_demo_M->solverInfo, 0.002);
  rtsiSetSolverMode(&SRV02_demo_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  SRV02_demo_M->blockIO = ((void *) &SRV02_demo_B);

  {
    SRV02_demo_B.ServoCountstoRad = 0.0;
    SRV02_demo_B.HILReadAnalog = 0.0;
    SRV02_demo_B.Saturation = 0.0;
  }

  /* parameters */
  SRV02_demo_M->defaultParam = ((real_T *)&SRV02_demo_P);

  /* states (dwork) */
  SRV02_demo_M->dwork = ((void *) &SRV02_demo_DW);
  (void) memset((void *)&SRV02_demo_DW, 0,
                sizeof(DW_SRV02_demo_T));
  SRV02_demo_DW.HILInitialize_AIMinimums[0] = 0.0;
  SRV02_demo_DW.HILInitialize_AIMinimums[1] = 0.0;
  SRV02_demo_DW.HILInitialize_AIMaximums[0] = 0.0;
  SRV02_demo_DW.HILInitialize_AIMaximums[1] = 0.0;
  SRV02_demo_DW.HILInitialize_AOMinimums[0] = 0.0;
  SRV02_demo_DW.HILInitialize_AOMinimums[1] = 0.0;
  SRV02_demo_DW.HILInitialize_AOMaximums[0] = 0.0;
  SRV02_demo_DW.HILInitialize_AOMaximums[1] = 0.0;
  SRV02_demo_DW.HILInitialize_AOVoltages[0] = 0.0;
  SRV02_demo_DW.HILInitialize_AOVoltages[1] = 0.0;
  SRV02_demo_DW.HILInitialize_FilterFrequency[0] = 0.0;
  SRV02_demo_DW.HILInitialize_FilterFrequency[1] = 0.0;
  SRV02_demo_DW.HILReadAnalog_Buffer = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SRV02_demo_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  SRV02_demo_M->Sizes.numContStates = (0);/* Number of continuous states */
  SRV02_demo_M->Sizes.numY = (0);      /* Number of model outputs */
  SRV02_demo_M->Sizes.numU = (0);      /* Number of model inputs */
  SRV02_demo_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  SRV02_demo_M->Sizes.numSampTimes = (2);/* Number of sample times */
  SRV02_demo_M->Sizes.numBlocks = (9); /* Number of blocks */
  SRV02_demo_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  SRV02_demo_M->Sizes.numBlockPrms = (74);/* Sum of parameter "widths" */
  return SRV02_demo_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
