/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test2_basic_private.h
 *
 * Code generated for Simulink model 'Test2_basic'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 12:42:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Test2_basic_private_h_
#define RTW_HEADER_Test2_basic_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Test2_basic.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern void Test2_ba_StandardServoRead_Init(DW_StandardServoRead_Test2_ba_T
  *localDW, P_StandardServoRead_Test2_bas_T *localP);
extern void Test2_basic_StandardServoRead(B_StandardServoRead_Test2_bas_T
  *localB, DW_StandardServoRead_Test2_ba_T *localDW,
  P_StandardServoRead_Test2_bas_T *localP);

#endif                                 /* RTW_HEADER_Test2_basic_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
