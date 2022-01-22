/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DAL_Sat_HW_v5_data.c
 *
 * Code generated for Simulink model 'DAL_Sat_HW_v5'.
 *
 * Model version                  : 1.152
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 11:50:22 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DAL_Sat_HW_v5.h"
#include "DAL_Sat_HW_v5_private.h"

/* Block parameters (default storage) */
P_DAL_Sat_HW_v5_T DAL_Sat_HW_v5_P = {
  /* Expression: 180
   * Referenced by: '<S9>/Constant'
   */
  180.0,

  /* Expression: 180
   * Referenced by: '<S10>/Constant'
   */
  180.0,

  /* Expression: -1
   * Referenced by: '<S3>/Analog Input12'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S3>/Analog Input13'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S3>/Analog Input14'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S3>/Analog Input15'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S3>/Analog Input16'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S3>/Analog Input17'
   */
  -1.0,

  /* Expression: 5
   * Referenced by: '<S26>/Constant'
   */
  5.0,

  /* Expression: 100
   * Referenced by: '<S21>/Constant'
   */
  100.0,

  /* Expression: 90
   * Referenced by: '<S21>/Constant2'
   */
  90.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S21>/Merge'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S30>/Constant'
   */
  5.0,

  /* Expression: 100
   * Referenced by: '<S22>/Constant'
   */
  100.0,

  /* Expression: 90
   * Referenced by: '<S22>/Constant2'
   */
  90.0,

  /* Computed Parameter: Merge_InitialOutput_k
   * Referenced by: '<S22>/Merge'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S20>/Standard Servo Read'
   */
  0.1,

  /* Computed Parameter: Output_Y0
   * Referenced by: '<S20>/Output'
   */
  0.0,

  /* Expression: 90
   * Referenced by: '<S20>/Constant'
   */
  90.0,

  /* Computed Parameter: Merge_InitialOutput_k2
   * Referenced by: '<S19>/Merge'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S18>/Constant'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant3'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S2>/Gain4'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay1'
   */
  0.0,

  /* Expression: 90
   * Referenced by: '<S1>/Constant'
   */
  90.0,

  /* Computed Parameter: Gain5_Gain
   * Referenced by: '<S3>/Gain5'
   */
  41000U,

  /* Start of '<S22>/Standard Servo Read' */
  {
    /* Expression: 0.1
     * Referenced by: '<S22>/Standard Servo Read'
     */
    0.1
  }
  ,

  /* End of '<S22>/Standard Servo Read' */

  /* Start of '<S27>/If Action Subsystem' */
  {
    /* Expression: 90
     * Referenced by: '<S29>/Constant'
     */
    90.0
  }
  ,

  /* End of '<S27>/If Action Subsystem' */

  /* Start of '<S21>/Standard Servo Read' */
  {
    /* Expression: 0.1
     * Referenced by: '<S21>/Standard Servo Read'
     */
    0.1
  }
  ,

  /* End of '<S21>/Standard Servo Read' */

  /* Start of '<S23>/If Action Subsystem' */
  {
    /* Expression: -90
     * Referenced by: '<S25>/Constant'
     */
    -90.0
  }
  ,

  /* End of '<S23>/If Action Subsystem' */

  /* Start of '<S1>/Standard Servo Read' */
  {
    /* Expression: 0.1
     * Referenced by: '<S1>/Standard Servo Read'
     */
    0.1
  }
  /* End of '<S1>/Standard Servo Read' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
