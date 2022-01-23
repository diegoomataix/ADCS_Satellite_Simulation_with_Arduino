/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DAL_Sat_HW_ExtendedControl.h
 *
 * Code generated for Simulink model 'DAL_Sat_HW_ExtendedControl'.
 *
 * Model version                  : 1.101
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Jan 23 00:20:36 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DAL_Sat_HW_ExtendedControl_h_
#define RTW_HEADER_DAL_Sat_HW_ExtendedControl_h_
#include <math.h>
#include <stddef.h>
#ifndef DAL_Sat_HW_ExtendedControl_COMMON_INCLUDES_
#define DAL_Sat_HW_ExtendedControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "LCDControlSF_cgen_wrapper.h"
#include "MW_ServoWriteRead.h"
#include "MW_AnalogIn.h"
#endif                         /* DAL_Sat_HW_ExtendedControl_COMMON_INCLUDES_ */

#include "DAL_Sat_HW_ExtendedControl_types.h"
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
  real_T Merge;                        /* '<S12>/Merge' */
  uint16_T DataTypeConversion1;        /* '<S28>/Data Type Conversion1' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead_pnae;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead;/* '<S7>/Standard Servo Read' */
  B_StandardServoRead_DAL_Sat_H_T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
} B_DAL_Sat_HW_ExtendedControl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_lx_T obj; /* '<S4>/Analog Input17' */
  codertarget_arduinobase_in_lx_T obj_i;/* '<S4>/Analog Input16' */
  codertarget_arduinobase_in_lx_T obj_c;/* '<S4>/Analog Input15' */
  codertarget_arduinobase_in_lx_T obj_c4;/* '<S4>/Analog Input14' */
  codertarget_arduinobase_in_lx_T obj_l;/* '<S4>/Analog Input13' */
  codertarget_arduinobase_in_lx_T obj_h;/* '<S4>/Analog Input12' */
  real_T SFunctionBuilder1_DSTATE;     /* '<S28>/S-Function Builder1' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead_pnae;/* '<S7>/Standard Servo Read' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead;/* '<S7>/Standard Servo Read' */
  DW_StandardServoRead_DAL_Sat__T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
} DW_DAL_Sat_HW_ExtendedControl_T;

/* Parameters for system: '<S7>/Standard Servo Read' */
struct P_StandardServoRead_DAL_Sat_H_T_ {
  real_T StandardServoRead_SampleTime; /* Expression: 0.1
                                        * Referenced by: '<S7>/Standard Servo Read'
                                        */
};

/* Parameters for system: '<S16>/If Action Subsystem' */
struct P_IfActionSubsystem_DAL_Sat_H_T_ {
  real_T Constant_Value;               /* Expression: -90
                                        * Referenced by: '<S18>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_DAL_Sat_HW_ExtendedControl_T_ {
  real_T Constant_Value;               /* Expression: 15
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 10
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 90
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 10
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 5
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T NominalControlCondition_Value;/* Expression: 100
                                        * Referenced by: '<S17>/Nominal Control Condition'
                                        */
  real_T Constant_Value_nv;            /* Expression: 50
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 90
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S14>/Merge'
                                       */
  real_T Constant_Value_m1;            /* Expression: 10
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 5
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T NominalControlCondition_Value_g;/* Expression: 100
                                          * Referenced by: '<S23>/Nominal Control Condition'
                                          */
  real_T Constant_Value_mh;            /* Expression: 50
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant2_Value_a;            /* Expression: 90
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real_T Merge_InitialOutput_j;     /* Computed Parameter: Merge_InitialOutput_j
                                     * Referenced by: '<S15>/Merge'
                                     */
  real_T Theta_Servo_New_Display_Y0;
                               /* Computed Parameter: Theta_Servo_New_Display_Y0
                                * Referenced by: '<S13>/Theta_Servo_New_Display'
                                */
  real_T Constant_Value_mx;            /* Expression: 90
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Merge_InitialOutput_g;     /* Computed Parameter: Merge_InitialOutput_g
                                     * Referenced by: '<S12>/Merge'
                                     */
  real_T NominalControlCondition_Value_p;/* Expression: 100
                                          * Referenced by: '<S11>/Nominal Control Condition'
                                          */
  real_T AnalogInput12_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S4>/Analog Input12'
                                        */
  real_T AnalogInput13_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S4>/Analog Input13'
                                        */
  real_T AnalogInput14_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S4>/Analog Input14'
                                        */
  real_T AnalogInput15_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S4>/Analog Input15'
                                        */
  real_T AnalogInput16_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S4>/Analog Input16'
                                        */
  real_T AnalogInput17_SampleTime;     /* Expression: -1
                                        * Referenced by: '<S4>/Analog Input17'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S29>/Constant3'
                                        */
  real_T Gain1_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Constant_Value_m0;            /* Expression: 90
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 90
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint16_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S4>/Gain5'
                                        */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead_pnae;/* '<S7>/Standard Servo Read' */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead_pna;/* '<S7>/Standard Servo Read' */
  P_IfActionSubsystem_DAL_Sat_H_T IfActionSubsystem_h;/* '<S22>/If Action Subsystem' */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead_pn;/* '<S7>/Standard Servo Read' */
  P_IfActionSubsystem_DAL_Sat_H_T IfActionSubsystem_p;/* '<S16>/If Action Subsystem' */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead;/* '<S7>/Standard Servo Read' */
  P_StandardServoRead_DAL_Sat_H_T StandardServoRead_p;/* '<S7>/Standard Servo Read' */
};

/* Real-time Model Data Structure */
struct tag_RTM_DAL_Sat_HW_ExtendedCo_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_DAL_Sat_HW_ExtendedControl_T DAL_Sat_HW_ExtendedControl_P;

/* Block signals (default storage) */
extern B_DAL_Sat_HW_ExtendedControl_T DAL_Sat_HW_ExtendedControl_B;

/* Block states (default storage) */
extern DW_DAL_Sat_HW_ExtendedControl_T DAL_Sat_HW_ExtendedControl_DW;

/* Model entry point functions */
extern void DAL_Sat_HW_ExtendedControl_initialize(void);
extern void DAL_Sat_HW_ExtendedControl_step(void);
extern void DAL_Sat_HW_ExtendedControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DAL_Sat_HW_ExtendedC_T *const DAL_Sat_HW_ExtendedControl_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display3' : Unused code path elimination
 * Block '<S2>/Display2' : Unused code path elimination
 * Block '<S12>/Display' : Unused code path elimination
 * Block '<S12>/Display1' : Unused code path elimination
 * Block '<S12>/Display2' : Unused code path elimination
 * Block '<S12>/Display3' : Unused code path elimination
 * Block '<S3>/Angle of incidence XY' : Unused code path elimination
 * Block '<S28>/Angle of incidenceXY_Display' : Unused code path elimination
 * Block '<S3>/Sat2Beam_VecUnit' : Unused code path elimination
 * Block '<S4>/xp_yn_DISPLAY' : Unused code path elimination
 * Block '<S4>/xp_yp_DISPLAY' : Unused code path elimination
 * Block '<S4>/yn_xn_DISPLAY' : Unused code path elimination
 * Block '<S4>/yn_xp_DISPLAY' : Unused code path elimination
 * Block '<S4>/yp_xn_DISPLAY' : Unused code path elimination
 * Block '<S4>/yp_xp_DISPLAY' : Unused code path elimination
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'DAL_Sat_HW_ExtendedControl'
 * '<S1>'   : 'DAL_Sat_HW_ExtendedControl/Actuator'
 * '<S2>'   : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control'
 * '<S3>'   : 'DAL_Sat_HW_ExtendedControl/OBC'
 * '<S4>'   : 'DAL_Sat_HW_ExtendedControl/Sensor'
 * '<S5>'   : 'DAL_Sat_HW_ExtendedControl/Actuator/If Action Subsystem'
 * '<S6>'   : 'DAL_Sat_HW_ExtendedControl/Actuator/If Action Subsystem1'
 * '<S7>'   : 'DAL_Sat_HW_ExtendedControl/Actuator/If Action Subsystem/If Action Subsystem1'
 * '<S8>'   : 'DAL_Sat_HW_ExtendedControl/Actuator/If Action Subsystem/If Action Subsystem4'
 * '<S9>'   : 'DAL_Sat_HW_ExtendedControl/Actuator/If Action Subsystem/If Action Subsystem1/If Action Subsystem1'
 * '<S10>'  : 'DAL_Sat_HW_ExtendedControl/Actuator/If Action Subsystem/If Action Subsystem1/If Action Subsystem4'
 * '<S11>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/If Action Subsystem'
 * '<S12>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp'
 * '<S13>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in xn'
 * '<S14>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yn'
 * '<S15>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yp'
 * '<S16>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yn/If Action Subsystem'
 * '<S17>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yn/If Action Subsystem1'
 * '<S18>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yn/If Action Subsystem/If Action Subsystem'
 * '<S19>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yn/If Action Subsystem/If Action Subsystem1'
 * '<S20>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yn/If Action Subsystem1/If Action Subsystem'
 * '<S21>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yn/If Action Subsystem1/If Action Subsystem1'
 * '<S22>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yp/If Action Subsystem'
 * '<S23>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yp/If Action Subsystem1'
 * '<S24>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yp/If Action Subsystem/If Action Subsystem'
 * '<S25>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yp/If Action Subsystem/If Action Subsystem1'
 * '<S26>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yp/If Action Subsystem1/If Action Subsystem'
 * '<S27>'  : 'DAL_Sat_HW_ExtendedControl/Extended Orientation Control/Light does not point at xp/Only Reads in yp/If Action Subsystem1/If Action Subsystem1'
 * '<S28>'  : 'DAL_Sat_HW_ExtendedControl/OBC/LCD'
 * '<S29>'  : 'DAL_Sat_HW_ExtendedControl/OBC/Threshold_Filter'
 * '<S30>'  : 'DAL_Sat_HW_ExtendedControl/OBC/Threshold_Filter/If Action Subsystem'
 * '<S31>'  : 'DAL_Sat_HW_ExtendedControl/OBC/Threshold_Filter/If Action Subsystem1'
 * '<S32>'  : 'DAL_Sat_HW_ExtendedControl/OBC/Threshold_Filter/If Action Subsystem4'
 * '<S33>'  : 'DAL_Sat_HW_ExtendedControl/OBC/Threshold_Filter/If Action Subsystem5'
 * '<S34>'  : 'DAL_Sat_HW_ExtendedControl/OBC/Threshold_Filter/If Action Subsystem6'
 * '<S35>'  : 'DAL_Sat_HW_ExtendedControl/OBC/Threshold_Filter/If Action Subsystem7'
 */
#endif                            /* RTW_HEADER_DAL_Sat_HW_ExtendedControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
