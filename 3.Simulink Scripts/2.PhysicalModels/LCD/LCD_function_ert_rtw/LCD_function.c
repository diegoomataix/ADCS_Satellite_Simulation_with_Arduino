/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LCD_function.c
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

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  LCD_function_M->Timing.taskTime0 =
    ((time_T)(++LCD_function_M->Timing.clockTick0)) *
    LCD_function_M->Timing.stepSize0;
}

/* Model initialize function */
void LCD_function_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(LCD_function_M, 10.0);
  LCD_function_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  LCD_function_M->Sizes.checksums[0] = (2417868039U);
  LCD_function_M->Sizes.checksums[1] = (137805099U);
  LCD_function_M->Sizes.checksums[2] = (2823460208U);
  LCD_function_M->Sizes.checksums[3] = (885875393U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    LCD_function_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LCD_function_M->extModeInfo,
      &LCD_function_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LCD_function_M->extModeInfo,
                        LCD_function_M->Sizes.checksums);
    rteiSetTPtr(LCD_function_M->extModeInfo, rtmGetTPtr(LCD_function_M));
  }

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
