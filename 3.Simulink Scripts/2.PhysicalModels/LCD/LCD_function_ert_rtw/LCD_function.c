/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LCD_function.c
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

#include "LCD_function.h"
#include "LCD_function_private.h"

/* Block signals (default storage) */
B_LCD_function_T LCD_function_B;

/* Block states (default storage) */
DW_LCD_function_T LCD_function_DW;

/* Real-time model */
static RT_MODEL_LCD_function_T LCD_function_M_;
RT_MODEL_LCD_function_T *const LCD_function_M = &LCD_function_M_;

/* Model step function */
void LCD_function_step(void)
{
  real_T tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(LCD_function_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  LCD_function_B.DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)
    -tmp : (uint16_T)tmp;

  /* S-Function (Lcd): '<Root>/S-Function Builder' */
  Lcd_Outputs_wrapper_cgen(&LCD_function_B.DataTypeConversion,
    &LCD_function_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (Lcd): '<Root>/S-Function Builder' */

  /* S-Function "Lcd_wrapper" Block: <Root>/S-Function Builder */
  Lcd_Update_wrapper_cgen(&LCD_function_B.DataTypeConversion,
    &LCD_function_DW.SFunctionBuilder_DSTATE);
}

/* Model initialize function */
void LCD_function_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for S-Function (Lcd): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LCD_function_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void LCD_function_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
