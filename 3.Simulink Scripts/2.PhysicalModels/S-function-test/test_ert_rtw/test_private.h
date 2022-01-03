/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_private.h
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Jan  3 16:16:05 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_private_h_
#define RTW_HEADER_test_private_h_
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

SFB_EXTERN_C void LED_Function_Start_wrapper(real_T *xD);
SFB_EXTERN_C void LED_Function_Outputs_wrapper(const real_T *xD);
SFB_EXTERN_C void LED_Function_Update_wrapper(real_T *xD);
SFB_EXTERN_C void LED_Function_Terminate_wrapper(real_T *xD);

#undef SFB_EXTERN_C
#endif                                 /* RTW_HEADER_test_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
