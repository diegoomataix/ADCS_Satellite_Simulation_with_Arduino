/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LCD_function.h
 *
 * Code generated for Simulink model 'LCD_function'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Jan 20 22:07:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LCD_function_h_
#define RTW_HEADER_LCD_function_h_
#include <math.h>
#include <stddef.h>
#ifndef LCD_function_COMMON_INCLUDES_
#define LCD_function_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Lcd_cgen_wrapper.h"
#endif                                 /* LCD_function_COMMON_INCLUDES_ */

#include "LCD_function_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T DataTypeConversion;         /* '<Root>/Data Type Conversion' */
} B_LCD_function_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
} DW_LCD_function_T;

/* Parameters (default storage) */
struct P_LCD_function_T_ {
  real_T Constant_Value;               /* Expression: 33
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_LCD_function_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_LCD_function_T LCD_function_P;

/* Block signals (default storage) */
extern B_LCD_function_T LCD_function_B;

/* Block states (default storage) */
extern DW_LCD_function_T LCD_function_DW;

/* Model entry point functions */
extern void LCD_function_initialize(void);
extern void LCD_function_step(void);
extern void LCD_function_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LCD_function_T *const LCD_function_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
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
 * '<Root>' : 'LCD_function'
 */
#endif                                 /* RTW_HEADER_LCD_function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
