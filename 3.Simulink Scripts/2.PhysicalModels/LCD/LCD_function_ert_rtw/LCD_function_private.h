/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LCD_function_private.h
 *
 * Code generated for Simulink model 'LCD_function'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Jan  3 20:05:37 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LCD_function_private_h_
#define RTW_HEADER_LCD_function_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void Lcd_Start_wrapper(real_T *xD);
SFB_EXTERN_C void Lcd_Outputs_wrapper(const uint16_T *char_val,
  const real_T *xD);
SFB_EXTERN_C void Lcd_Update_wrapper(const uint16_T *char_val,
  real_T *xD);
SFB_EXTERN_C void Lcd_Terminate_wrapper(real_T *xD);

#undef SFB_EXTERN_C
#endif                                 /* RTW_HEADER_LCD_function_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
