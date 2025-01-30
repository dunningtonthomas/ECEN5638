/*
 * SRV02_systemID_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SRV02_systemID".
 *
 * Model version              : 9.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 30 14:48:05 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_card),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_card",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&SRV02_systemID_B.ServoCountstoRad), 0, 0, 5 }
  ,

  { (char_T *)(&SRV02_systemID_DW.HILInitialize_AIMinimums[0]), 0, 0, 13 },

  { (char_T *)(&SRV02_systemID_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&SRV02_systemID_DW.HILReadEncoder_PWORK), 11, 0, 9 },

  { (char_T *)(&SRV02_systemID_DW.HILInitialize_ClockModes), 6, 0, 6 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&SRV02_systemID_P.T), 0, 0, 1 },

  { (char_T *)(&SRV02_systemID_P.HILWrite_analog_channels), 7, 0, 3 },

  { (char_T *)(&SRV02_systemID_P.HILInitialize_OOTerminate), 0, 0, 220 },

  { (char_T *)(&SRV02_systemID_P.HILInitialize_CKChannels), 6, 0, 4 },

  { (char_T *)(&SRV02_systemID_P.HILInitialize_AIChannels[0]), 7, 0, 7 },

  { (char_T *)(&SRV02_systemID_P.HILInitialize_Active), 8, 0, 38 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] SRV02_systemID_dt.h */
