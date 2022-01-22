/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test9.h
 *
 * Code generated for Simulink model 'Test9'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 11:43:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Test9_h_
#define RTW_HEADER_Test9_h_
#include <math.h>
#ifndef Test9_COMMON_INCLUDES_
#define Test9_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ServoWriteRead.h"
#include "MW_AnalogIn.h"
#endif                                 /* Test9_COMMON_INCLUDES_ */

#include "Test9_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<S7>/Standard Servo Read' */
typedef struct {
  int32_T StandardServoRead;           /* '<S7>/Standard Servo Read' */
} B_StandardServoRead_Test9_T;

/* Block states (default storage) for system '<S7>/Standard Servo Read' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S7>/Standard Servo Read' */
  boolean_T objisempty;                /* '<S7>/Standard Servo Read' */
} DW_StandardServoRead_Test9_T;

/* Block states (default storage) for system '<S23>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S23>/If Action Subsystem' */
} DW_IfActionSubsystem_Test9_T;

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion2[3];       /* '<S3>/Data Type Conversion2' */
  real_T Merge;                        /* '<S11>/Merge' */
  real_T Merge2;                       /* '<S11>/Merge2' */
  real_T Merge3;                       /* '<S11>/Merge3' */
  real_T Sat2Beam_VecUnit[2];          /* '<S2>/Divide2' */
  real_T Gain4;                        /* '<S2>/Gain4' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Merge_l;                      /* '<S3>/Merge' */
  real_T Merge_h;                      /* '<S1>/Merge' */
  real_T Merge_a;                      /* '<S19>/Merge' */
  real_T DataTypeConversion;           /* '<S20>/Data Type Conversion' */
  real_T OutportBufferForOutput;       /* '<S20>/OutportBufferForOutput' */
  real_T Merge_k;                      /* '<S22>/Merge' */
  real_T Merge_g;                      /* '<S21>/Merge' */
  int32_T Theta_ServoRF;               /* '<S1>/Standard Servo Read' */
  uint16_T yn_xn;                      /* '<S3>/Analog Input17' */
  uint16_T yp_xn;                      /* '<S3>/Analog Input16' */
  uint16_T yn_xp;                      /* '<S3>/Analog Input15' */
  uint16_T xp_yn;                      /* '<S3>/Analog Input14' */
  uint16_T yp_xp;                      /* '<S3>/Analog Input13' */
  uint16_T xp_yp;                      /* '<S3>/Analog Input12' */
  B_StandardServoRead_Test9_T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_Test9_T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_Test9_T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
} B_Test9_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_fs_T obj; /* '<S3>/Analog Input17' */
  codertarget_arduinobase_in_fs_T obj_i;/* '<S3>/Analog Input16' */
  codertarget_arduinobase_in_fs_T obj_c;/* '<S3>/Analog Input15' */
  codertarget_arduinobase_in_fs_T obj_c4;/* '<S3>/Analog Input14' */
  codertarget_arduinobase_in_fs_T obj_l;/* '<S3>/Analog Input13' */
  codertarget_arduinobase_in_fs_T obj_h;/* '<S3>/Analog Input12' */
  codertarget_arduinobase_inter_T obj_c2;/* '<S20>/Standard Servo Read' */
  codertarget_arduinobase_inter_T obj_p;/* '<S1>/Standard Servo Read' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Demux;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Divid;   /* synthesized block */

  struct {
    void *LoggedData;
  } Beam_PWORK;                        /* '<S1>/Beam' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Theta;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Gain4;   /* synthesized block */

  struct {
    void *LoggedData;
  } Added_PWORK;                       /* '<S1>/Added' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum_a;   /* synthesized block */

  struct {
    void *LoggedData;
  } Prev_PWORK;                        /* '<S1>/Prev' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum1_;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Stand;   /* synthesized block */

  struct {
    void *LoggedData[4];
  } Scope_PWORK_f;                     /* '<S3>/Scope' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Analo;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ana_a;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ana_m;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ana_n;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ana_f;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ana_j;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Merge;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mer_j;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Thres;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Thr_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Th_ow;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Me_jl;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_IfAct;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_OnlyR;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Onl_k;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_M_jlo;   /* synthesized block */

  int8_T IfActionSubsystem_SubsysRanBC;/* '<S3>/If Action Subsystem' */
  int8_T Lightdoesnotpointatxp_SubsysRan;/* '<S3>/Light does not point at xp' */
  int8_T IfActionSubsystem_SubsysRanBC_a;/* '<S19>/If Action Subsystem' */
  int8_T OnlyReadsinyp_SubsysRanBC;    /* '<S19>/Only Reads in yp' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S22>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_g;/* '<S22>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S27>/If Action Subsystem1' */
  int8_T OnlyReadsinyn_SubsysRanBC;    /* '<S19>/Only Reads in yn' */
  int8_T IfActionSubsystem1_SubsysRan_gm;/* '<S21>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S21>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_i;/* '<S23>/If Action Subsystem1' */
  int8_T IfActionSubsystem7_SubsysRanBC;/* '<S11>/If Action Subsystem7' */
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S11>/If Action Subsystem6' */
  int8_T IfActionSubsystem5_SubsysRanBC;/* '<S11>/If Action Subsystem5' */
  int8_T IfActionSubsystem4_SubsysRanBC;/* '<S11>/If Action Subsystem4' */
  int8_T IfActionSubsystem1_SubsysRanB_a;/* '<S11>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_c;/* '<S11>/If Action Subsystem' */
  int8_T IfActionSubsystem4_SubsysRanB_l;/* '<S6>/If Action Subsystem4' */
  int8_T IfActionSubsystem1_SubsysRanB_f;/* '<S6>/If Action Subsystem1' */
  int8_T IfActionSubsystem4_SubsysRanB_m;/* '<S7>/If Action Subsystem4' */
  int8_T IfActionSubsystem1_SubsysRanB_d;/* '<S7>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_o;/* '<S1>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanB_ay;/* '<S1>/If Action Subsystem' */
  DW_StandardServoRead_Test9_T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  DW_IfActionSubsystem_Test9_T IfActionSubsystem_h;/* '<S27>/If Action Subsystem' */
  DW_StandardServoRead_Test9_T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  DW_IfActionSubsystem_Test9_T IfActionSubsystem_ps;/* '<S23>/If Action Subsystem' */
  DW_StandardServoRead_Test9_T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
} DW_Test9_T;

/* Parameters for system: '<S7>/Standard Servo Read' */
struct P_StandardServoRead_Test9_T_ {
  real_T StandardServoRead_SampleTime; /* Expression: 0.1
                                        * Referenced by: '<S7>/Standard Servo Read'
                                        */
};

/* Parameters for system: '<S23>/If Action Subsystem' */
struct P_IfActionSubsystem_Test9_T_ {
  real_T Constant_Value;               /* Expression: -90
                                        * Referenced by: '<S25>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_Test9_T_ {
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 5
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 90
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T StandardServoRead_SampleTime; /* Expression: 0.1
                                        * Referenced by: '<S1>/Standard Servo Read'
                                        */
  real_T AnalogInput12_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S3>/Analog Input12'
                                        */
  real_T AnalogInput13_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S3>/Analog Input13'
                                        */
  real_T AnalogInput14_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S3>/Analog Input14'
                                        */
  real_T AnalogInput15_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S3>/Analog Input15'
                                        */
  real_T AnalogInput16_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S3>/Analog Input16'
                                        */
  real_T AnalogInput17_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S3>/Analog Input17'
                                        */
  real_T Constant_Value_n;             /* Expression: 5
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Constant_Value_nv;            /* Expression: 100
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 90
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S21>/Merge'
                                       */
  real_T Constant_Value_m1;            /* Expression: 5
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant_Value_mh;            /* Expression: 100
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant2_Value_a;            /* Expression: 90
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Merge_InitialOutput_j;     /* Computed Parameter: Merge_InitialOutput_j
                                     * Referenced by: '<S22>/Merge'
                                     */
  real_T StandardServoRead_SampleTime_e;/* Expression: 0.1
                                         * Referenced by: '<S20>/Standard Servo Read'
                                         */
  real_T Output_Y0;                    /* Computed Parameter: Output_Y0
                                        * Referenced by: '<S20>/Output'
                                        */
  real_T Constant_Value_mx;            /* Expression: 90
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Merge_InitialOutput_g;     /* Computed Parameter: Merge_InitialOutput_g
                                     * Referenced by: '<S19>/Merge'
                                     */
  real_T Constant_Value_p;             /* Expression: 100
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T Constant_Value_d;             /* Expression: 90
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint16_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S3>/Gain5'
                                        */
  P_StandardServoRead_Test9_T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  P_IfActionSubsystem_Test9_T IfActionSubsystem_h;/* '<S27>/If Action Subsystem' */
  P_StandardServoRead_Test9_T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  P_IfActionSubsystem_Test9_T IfActionSubsystem_ps;/* '<S23>/If Action Subsystem' */
  P_StandardServoRead_Test9_T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Test9_T {
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
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Test9_T Test9_P;

/* Block signals (default storage) */
extern B_Test9_T Test9_B;

/* Block states (default storage) */
extern DW_Test9_T Test9_DW;

/* Model entry point functions */
extern void Test9_initialize(void);
extern void Test9_step(void);
extern void Test9_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Test9_T *const Test9_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S22>/Constant1' : Unused code path elimination
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
 * '<Root>' : 'Test9'
 * '<S1>'   : 'Test9/Control'
 * '<S2>'   : 'Test9/OBC'
 * '<S3>'   : 'Test9/Sensor'
 * '<S4>'   : 'Test9/Control/If Action Subsystem'
 * '<S5>'   : 'Test9/Control/If Action Subsystem1'
 * '<S6>'   : 'Test9/Control/Orientation'
 * '<S7>'   : 'Test9/Control/Orientation/If Action Subsystem1'
 * '<S8>'   : 'Test9/Control/Orientation/If Action Subsystem4'
 * '<S9>'   : 'Test9/Control/Orientation/If Action Subsystem1/If Action Subsystem1'
 * '<S10>'  : 'Test9/Control/Orientation/If Action Subsystem1/If Action Subsystem4'
 * '<S11>'  : 'Test9/OBC/Threshold_Filter2'
 * '<S12>'  : 'Test9/OBC/Threshold_Filter2/If Action Subsystem'
 * '<S13>'  : 'Test9/OBC/Threshold_Filter2/If Action Subsystem1'
 * '<S14>'  : 'Test9/OBC/Threshold_Filter2/If Action Subsystem4'
 * '<S15>'  : 'Test9/OBC/Threshold_Filter2/If Action Subsystem5'
 * '<S16>'  : 'Test9/OBC/Threshold_Filter2/If Action Subsystem6'
 * '<S17>'  : 'Test9/OBC/Threshold_Filter2/If Action Subsystem7'
 * '<S18>'  : 'Test9/Sensor/If Action Subsystem'
 * '<S19>'  : 'Test9/Sensor/Light does not point at xp'
 * '<S20>'  : 'Test9/Sensor/Light does not point at xp/If Action Subsystem'
 * '<S21>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yn'
 * '<S22>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yp'
 * '<S23>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yn/If Action Subsystem'
 * '<S24>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yn/If Action Subsystem1'
 * '<S25>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yn/If Action Subsystem/If Action Subsystem'
 * '<S26>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yn/If Action Subsystem/If Action Subsystem1'
 * '<S27>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yp/If Action Subsystem'
 * '<S28>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yp/If Action Subsystem1'
 * '<S29>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yp/If Action Subsystem/If Action Subsystem'
 * '<S30>'  : 'Test9/Sensor/Light does not point at xp/Only Reads in yp/If Action Subsystem/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_Test9_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
