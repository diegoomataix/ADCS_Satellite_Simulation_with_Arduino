/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DAL_Sat_HW_v7.h
 *
 * Code generated for Simulink model 'DAL_Sat_HW_v7'.
 *
 * Model version                  : 1.151
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 11:28:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DAL_Sat_HW_v7_h_
#define RTW_HEADER_DAL_Sat_HW_v7_h_
#include <math.h>
#include <stddef.h>
#ifndef DAL_Sat_HW_v7_COMMON_INCLUDES_
#define DAL_Sat_HW_v7_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ServoWriteRead.h"
#include "MW_AnalogIn.h"
#endif                                 /* DAL_Sat_HW_v7_COMMON_INCLUDES_ */

#include "DAL_Sat_HW_v7_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S7>/Standard Servo Read' */
typedef struct {
  int32_T StandardServoRead;           /* '<S7>/Standard Servo Read' */
} B_StandardServoRead_DAL_Sat_H_T;

/* Block states (default storage) for system '<S7>/Standard Servo Read' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S7>/Standard Servo Read' */
  boolean_T objisempty;                /* '<S7>/Standard Servo Read' */
} DW_StandardServoRead_DAL_Sat__T;

/* Block signals (default storage) */
typedef struct {
  real_T Merge;                        /* '<S19>/Merge' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
} B_DAL_Sat_HW_v7_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_co_T obj; /* '<S3>/Analog Input17' */
  codertarget_arduinobase_in_co_T obj_k;/* '<S3>/Analog Input16' */
  codertarget_arduinobase_in_co_T obj_m;/* '<S3>/Analog Input15' */
  codertarget_arduinobase_in_co_T obj_h;/* '<S3>/Analog Input14' */
  codertarget_arduinobase_in_co_T obj_a;/* '<S3>/Analog Input13' */
  codertarget_arduinobase_in_co_T obj_e;/* '<S3>/Analog Input12' */
  codertarget_arduinobase_inter_T obj_m5;/* '<S20>/Standard Servo Read' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead;/* '<S7>/Standard Servo Read' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
} DW_DAL_Sat_HW_v7_T;

/* Parameters for system: '<S7>/Standard Servo Read' */
struct P_StandardServoRead_DAL_Sat_H_T_ {
  real_T StandardServoRead_SampleTime; /* Expression: 0.1
                                        * Referenced by: '<S7>/Standard Servo Read'
                                        */
};

/* Parameters for system: '<S23>/If Action Subsystem' */
struct P_IfActionSubsystem_DAL_Sat_H_T_ {
  real_T Constant_Value;               /* Expression: -90
                                        * Referenced by: '<S25>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_DAL_Sat_HW_v7_T_ {
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 5
                                        * Referenced by: '<S10>/Constant'
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
  real_T Constant_Value_j;             /* Expression: 5
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 100
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 90
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S21>/Merge'
                                       */
  real_T Constant_Value_eg;            /* Expression: 5
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: 100
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant2_Value_h;            /* Expression: 90
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Merge_InitialOutput_k;     /* Computed Parameter: Merge_InitialOutput_k
                                     * Referenced by: '<S22>/Merge'
                                     */
  real_T StandardServoRead_SampleTime; /* Expression: 0.1
                                        * Referenced by: '<S20>/Standard Servo Read'
                                        */
  real_T Output_Y0;                    /* Computed Parameter: Output_Y0
                                        * Referenced by: '<S20>/Output'
                                        */
  real_T Constant_Value_o;             /* Expression: 90
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Merge_InitialOutput_k2;   /* Computed Parameter: Merge_InitialOutput_k2
                                    * Referenced by: '<S19>/Merge'
                                    */
  real_T Constant_Value_c;             /* Expression: 100
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  real_T Constant_Value_lr;            /* Expression: 90
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint16_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S3>/Gain5'
                                        */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  P_IfActionSubsystem_DAL_Sat_H_T IfActionSubsystem_l;/* '<S27>/If Action Subsystem' */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  P_IfActionSubsystem_DAL_Sat_H_T IfActionSubsystem_c;/* '<S23>/If Action Subsystem' */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead;/* '<S7>/Standard Servo Read' */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
};

/* Real-time Model Data Structure */
struct tag_RTM_DAL_Sat_HW_v7_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_DAL_Sat_HW_v7_T DAL_Sat_HW_v7_P;

/* Block signals (default storage) */
extern B_DAL_Sat_HW_v7_T DAL_Sat_HW_v7_B;

/* Block states (default storage) */
extern DW_DAL_Sat_HW_v7_T DAL_Sat_HW_v7_DW;

/* Model entry point functions */
extern void DAL_Sat_HW_v7_initialize(void);
extern void DAL_Sat_HW_v7_step(void);
extern void DAL_Sat_HW_v7_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DAL_Sat_HW_v7_T *const DAL_Sat_HW_v7_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Added' : Unused code path elimination
 * Block '<S1>/Angle of incidence' : Unused code path elimination
 * Block '<S1>/Beam' : Unused code path elimination
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S1>/Display3' : Unused code path elimination
 * Block '<S1>/Prev' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S2>/Angle of incidence' : Unused code path elimination
 * Block '<S2>/Sat2Beam_VecUnit2' : Unused code path elimination
 * Block '<S2>/vxp2' : Unused code path elimination
 * Block '<S2>/vyn2' : Unused code path elimination
 * Block '<S2>/vyp2' : Unused code path elimination
 * Block '<S3>/Display' : Unused code path elimination
 * Block '<S3>/Display1' : Unused code path elimination
 * Block '<S3>/Display2' : Unused code path elimination
 * Block '<S19>/Display' : Unused code path elimination
 * Block '<S19>/Display1' : Unused code path elimination
 * Block '<S19>/Display2' : Unused code path elimination
 * Block '<S19>/Display3' : Unused code path elimination
 * Block '<S21>/Display' : Unused code path elimination
 * Block '<S22>/Constant1' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/xp_yn' : Unused code path elimination
 * Block '<S3>/xp_yp' : Unused code path elimination
 * Block '<S3>/yn_xn' : Unused code path elimination
 * Block '<S3>/yn_xp' : Unused code path elimination
 * Block '<S3>/yp_xn' : Unused code path elimination
 * Block '<S3>/yp_xp' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'DAL_Sat_HW_v7'
 * '<S1>'   : 'DAL_Sat_HW_v7/Control'
 * '<S2>'   : 'DAL_Sat_HW_v7/OBC'
 * '<S3>'   : 'DAL_Sat_HW_v7/Sensor'
 * '<S4>'   : 'DAL_Sat_HW_v7/Control/If Action Subsystem'
 * '<S5>'   : 'DAL_Sat_HW_v7/Control/If Action Subsystem1'
 * '<S6>'   : 'DAL_Sat_HW_v7/Control/Orientation'
 * '<S7>'   : 'DAL_Sat_HW_v7/Control/Orientation/If Action Subsystem1'
 * '<S8>'   : 'DAL_Sat_HW_v7/Control/Orientation/If Action Subsystem4'
 * '<S9>'   : 'DAL_Sat_HW_v7/Control/Orientation/If Action Subsystem1/If Action Subsystem1'
 * '<S10>'  : 'DAL_Sat_HW_v7/Control/Orientation/If Action Subsystem1/If Action Subsystem4'
 * '<S11>'  : 'DAL_Sat_HW_v7/OBC/Threshold_Filter2'
 * '<S12>'  : 'DAL_Sat_HW_v7/OBC/Threshold_Filter2/If Action Subsystem'
 * '<S13>'  : 'DAL_Sat_HW_v7/OBC/Threshold_Filter2/If Action Subsystem1'
 * '<S14>'  : 'DAL_Sat_HW_v7/OBC/Threshold_Filter2/If Action Subsystem4'
 * '<S15>'  : 'DAL_Sat_HW_v7/OBC/Threshold_Filter2/If Action Subsystem5'
 * '<S16>'  : 'DAL_Sat_HW_v7/OBC/Threshold_Filter2/If Action Subsystem6'
 * '<S17>'  : 'DAL_Sat_HW_v7/OBC/Threshold_Filter2/If Action Subsystem7'
 * '<S18>'  : 'DAL_Sat_HW_v7/Sensor/If Action Subsystem'
 * '<S19>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp'
 * '<S20>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/If Action Subsystem'
 * '<S21>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yn'
 * '<S22>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yp'
 * '<S23>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yn/If Action Subsystem'
 * '<S24>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yn/If Action Subsystem1'
 * '<S25>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yn/If Action Subsystem/If Action Subsystem'
 * '<S26>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yn/If Action Subsystem/If Action Subsystem1'
 * '<S27>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yp/If Action Subsystem'
 * '<S28>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yp/If Action Subsystem1'
 * '<S29>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yp/If Action Subsystem/If Action Subsystem'
 * '<S30>'  : 'DAL_Sat_HW_v7/Sensor/Light does not point at xp/Only Reads in yp/If Action Subsystem/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_DAL_Sat_HW_v7_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
