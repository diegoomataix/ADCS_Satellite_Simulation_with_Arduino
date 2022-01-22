/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test2_basic.h
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

#ifndef RTW_HEADER_Test2_basic_h_
#define RTW_HEADER_Test2_basic_h_
#include <math.h>
#ifndef Test2_basic_COMMON_INCLUDES_
#define Test2_basic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ServoWriteRead.h"
#endif                                 /* Test2_basic_COMMON_INCLUDES_ */

#include "Test2_basic_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<Root>/Standard Servo Read' */
typedef struct {
  int32_T StandardServoRead;           /* '<Root>/Standard Servo Read' */
} B_StandardServoRead_Test2_bas_T;

/* Block states (default storage) for system '<Root>/Standard Servo Read' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Standard Servo Read' */
  boolean_T objisempty;                /* '<Root>/Standard Servo Read' */
} DW_StandardServoRead_Test2_ba_T;

/* Block signals (default storage) */
typedef struct {
  B_StandardServoRead_Test2_bas_T StandardServoRead1;/* '<Root>/Standard Servo Read' */
  B_StandardServoRead_Test2_bas_T StandardServoRead;/* '<Root>/Standard Servo Read' */
} B_Test2_basic_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Stand;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sta_a;   /* synthesized block */

  DW_StandardServoRead_Test2_ba_T StandardServoRead1;/* '<Root>/Standard Servo Read' */
  DW_StandardServoRead_Test2_ba_T StandardServoRead;/* '<Root>/Standard Servo Read' */
} DW_Test2_basic_T;

/* Parameters for system: '<Root>/Standard Servo Read' */
struct P_StandardServoRead_Test2_bas_T_ {
  real_T StandardServoRead_SampleTime; /* Expression: 0.1
                                        * Referenced by: '<Root>/Standard Servo Read'
                                        */
};

/* Parameters (default storage) */
struct P_Test2_basic_T_ {
  real_T target_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/target'
                                        */
  P_StandardServoRead_Test2_bas_T StandardServoRead1;/* '<Root>/Standard Servo Read' */
  P_StandardServoRead_Test2_bas_T StandardServoRead;/* '<Root>/Standard Servo Read' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Test2_basic_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Test2_basic_T Test2_basic_P;

/* Block signals (default storage) */
extern B_Test2_basic_T Test2_basic_B;

/* Block states (default storage) */
extern DW_Test2_basic_T Test2_basic_DW;

/* Model entry point functions */
extern void Test2_basic_initialize(void);
extern void Test2_basic_step(void);
extern void Test2_basic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Test2_basic_T *const Test2_basic_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Sine Wave' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Test2_basic'
 */
#endif                                 /* RTW_HEADER_Test2_basic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
