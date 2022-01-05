/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Jan  3 19:49:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "test_private.h"

/* Block states (default storage) */
DW_test_T test_DW;

/* Real-time model */
static RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;

/* Model step function */
void test_step(void)
{
  /* S-Function (LED_Function): '<Root>/Hello' */
  LED_Function_Outputs_wrapper_cgen(&test_DW.Hello_DSTATE);

  /* Update for S-Function (LED_Function): '<Root>/Hello' */

  /* S-Function "LED_Function_wrapper" Block: <Root>/Hello */
  LED_Function_Update_wrapper_cgen(&test_DW.Hello_DSTATE);

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test_M->Timing.taskTime0 =
    ((time_T)(++test_M->Timing.clockTick0)) * test_M->Timing.stepSize0;
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(test_M, 10.0);
  test_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  test_M->Sizes.checksums[0] = (2638124958U);
  test_M->Sizes.checksums[1] = (1613956300U);
  test_M->Sizes.checksums[2] = (1816816086U);
  test_M->Sizes.checksums[3] = (800064385U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_M->extModeInfo,
      &test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_M->extModeInfo, test_M->Sizes.checksums);
    rteiSetTPtr(test_M->extModeInfo, rtmGetTPtr(test_M));
  }

  /* InitializeConditions for S-Function (LED_Function): '<Root>/Hello' */

  /* S-Function Block: <Root>/Hello */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        test_DW.Hello_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
