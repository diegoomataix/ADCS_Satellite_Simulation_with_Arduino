/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ServoModel_v5.h
 *
 * Code generated for Simulink model 'ServoModel_v5'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 13:02:19 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ServoModel_v5_h_
#define RTW_HEADER_ServoModel_v5_h_
#ifndef ServoModel_v5_COMMON_INCLUDES_
#define ServoModel_v5_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#endif                                 /* ServoModel_v5_COMMON_INCLUDES_ */

#include "ServoModel_v5_types.h"

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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Merge;                        /* '<Root>/Merge' */
} B_ServoModel_v5_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/PWM' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Merge;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum_a;   /* synthesized block */

  int8_T IfActionSubsystem2_SubsysRanBC;/* '<Root>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<Root>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
} DW_ServoModel_v5_T;

/* Parameters (default storage) */
struct P_ServoModel_v5_T_ {
  real_T DesiredAngle_Value;           /* Expression: 75
                                        * Referenced by: '<Root>/Desired Angle'
                                        */
  real_T Constant_Value;               /* Expression: 90
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 254
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Slope_Value;                  /* Expression: 97/90
                                        * Referenced by: '<Root>/Slope'
                                        */
  real_T Offset_Value;                 /* Expression: 60
                                        * Referenced by: '<Root>/Offset'
                                        */
  real_T Constant1_Value;              /* Expression: 60
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ServoModel_v5_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint16_T clockTick1;
    uint16_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ServoModel_v5_T ServoModel_v5_P;

/* Block signals (default storage) */
extern B_ServoModel_v5_T ServoModel_v5_B;

/* Block states (default storage) */
extern DW_ServoModel_v5_T ServoModel_v5_DW;

/* External function called from main */
extern void ServoModel_v5_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ServoModel_v5_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void ServoModel_v5_initialize(void);
extern void ServoModel_v5_step0(void);
extern void ServoModel_v5_step1(void);
extern void ServoModel_v5_step2(void);
extern void ServoModel_v5_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ServoModel_v5_T *const ServoModel_v5_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Angle Input' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/FixPt Constant' : Unused code path elimination
 * Block '<S6>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/FixPt Sum1' : Unused code path elimination
 * Block '<S5>/Output' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/FixPt Switch' : Unused code path elimination
 * Block '<S1>/Out' : Unused code path elimination
 * Block '<S1>/Output' : Unused code path elimination
 * Block '<S1>/Vector' : Unused code path elimination
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
 * '<Root>' : 'ServoModel_v5'
 * '<S1>'   : 'ServoModel_v5/Angle Input signal'
 * '<S2>'   : 'ServoModel_v5/If Action Subsystem'
 * '<S3>'   : 'ServoModel_v5/If Action Subsystem1'
 * '<S4>'   : 'ServoModel_v5/If Action Subsystem2'
 * '<S5>'   : 'ServoModel_v5/Angle Input signal/LimitedCounter'
 * '<S6>'   : 'ServoModel_v5/Angle Input signal/LimitedCounter/Increment Real World'
 * '<S7>'   : 'ServoModel_v5/Angle Input signal/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_ServoModel_v5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
