/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DAL_Sat_HW_ExtendedControl_private.h
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

#ifndef RTW_HEADER_DAL_Sat_HW_ExtendedControl_private_h_
#define RTW_HEADER_DAL_Sat_HW_ExtendedControl_private_h_
#include "rtwtypes.h"
#include "DAL_Sat_HW_ExtendedControl.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void LCDControlSF_Start_wrapper(real_T *xD);
SFB_EXTERN_C void LCDControlSF_Outputs_wrapper(const uint16_T *char_val,
  const real_T *xD);
SFB_EXTERN_C void LCDControlSF_Update_wrapper(const uint16_T *char_val,
  real_T *xD);
SFB_EXTERN_C void LCDControlSF_Terminate_wrapper(real_T *xD);

#undef SFB_EXTERN_C

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern void DAL_Sat__StandardServoRead_Init(DW_StandardServoRead_DAL_Sat__T
  *localDW, P_StandardServoRead_DAL_Sat_H_T *localP);
extern void DAL_Sat_HW_Ex_StandardServoRead(B_StandardServoRead_DAL_Sat_H_T
  *localB, DW_StandardServoRead_DAL_Sat__T *localDW,
  P_StandardServoRead_DAL_Sat_H_T *localP);
extern void DAL_Sat_HW_Ex_IfActionSubsystem(real_T *rty_Theta_Servo_New,
  P_IfActionSubsystem_DAL_Sat_H_T *localP);

#endif                    /* RTW_HEADER_DAL_Sat_HW_ExtendedControl_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
