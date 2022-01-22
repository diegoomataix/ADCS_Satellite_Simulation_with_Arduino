/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DAL_Sat_HW_ExtendedControl_types.h
 *
 * Code generated for Simulink model 'DAL_Sat_HW_ExtendedControl'.
 *
 * Model version                  : 1.97
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 23:58:00 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DAL_Sat_HW_ExtendedControl_types_h_
#define RTW_HEADER_DAL_Sat_HW_ExtendedControl_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_eMx5YEhcvDiTtSOZu1RVWH
#define struct_tag_eMx5YEhcvDiTtSOZu1RVWH

struct tag_eMx5YEhcvDiTtSOZu1RVWH
{
  int32_T isInitialized;
  real_T SampleTime;
};

#endif                                 /* struct_tag_eMx5YEhcvDiTtSOZu1RVWH */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_eMx5YEhcvDiTtSOZu1RVWH codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_UhdjAlk5m2xbK6E3oTj7hC
#define struct_tag_UhdjAlk5m2xbK6E3oTj7hC

struct tag_UhdjAlk5m2xbK6E3oTj7hC
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_UhdjAlk5m2xbK6E3oTj7hC */

#ifndef typedef_codertarget_arduinobase_int_l_T
#define typedef_codertarget_arduinobase_int_l_T

typedef struct tag_UhdjAlk5m2xbK6E3oTj7hC codertarget_arduinobase_int_l_T;

#endif                             /* typedef_codertarget_arduinobase_int_l_T */

/* Custom Type definition for MATLABSystem: '<S4>/Analog Input17' */
#include "MW_SVD.h"
#ifndef struct_tag_UTG5XI0vJCsmjbgura8BP
#define struct_tag_UTG5XI0vJCsmjbgura8BP

struct tag_UTG5XI0vJCsmjbgura8BP
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /* struct_tag_UTG5XI0vJCsmjbgura8BP */

#ifndef typedef_f_arduinodriver_ArduinoAnalog_T
#define typedef_f_arduinodriver_ArduinoAnalog_T

typedef struct tag_UTG5XI0vJCsmjbgura8BP f_arduinodriver_ArduinoAnalog_T;

#endif                             /* typedef_f_arduinodriver_ArduinoAnalog_T */

#ifndef struct_tag_8ohiN1FAOgR98njPNu14NC
#define struct_tag_8ohiN1FAOgR98njPNu14NC

struct tag_8ohiN1FAOgR98njPNu14NC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_8ohiN1FAOgR98njPNu14NC */

#ifndef typedef_codertarget_arduinobase_in_lx_T
#define typedef_codertarget_arduinobase_in_lx_T

typedef struct tag_8ohiN1FAOgR98njPNu14NC codertarget_arduinobase_in_lx_T;

#endif                             /* typedef_codertarget_arduinobase_in_lx_T */

/* Parameters for system: '<S7>/Standard Servo Read' */
typedef struct P_StandardServoRead_DAL_Sat_H_T_ P_StandardServoRead_DAL_Sat_H_T;

/* Parameters for system: '<S16>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_DAL_Sat_H_T_ P_IfActionSubsystem_DAL_Sat_H_T;

/* Parameters (default storage) */
typedef struct P_DAL_Sat_HW_ExtendedControl_T_ P_DAL_Sat_HW_ExtendedControl_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_DAL_Sat_HW_ExtendedCo_T RT_MODEL_DAL_Sat_HW_ExtendedC_T;

#endif                      /* RTW_HEADER_DAL_Sat_HW_ExtendedControl_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
