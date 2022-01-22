/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test2_basic.c
 *
 * Code generated for Simulink model 'Test2_basic'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 12:42:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Test2_basic.h"
#include "Test2_basic_private.h"

/* Block signals (default storage) */
B_Test2_basic_T Test2_basic_B;

/* Block states (default storage) */
DW_Test2_basic_T Test2_basic_DW;

/* Real-time model */
static RT_MODEL_Test2_basic_T Test2_basic_M_;
RT_MODEL_Test2_basic_T *const Test2_basic_M = &Test2_basic_M_;

/* System initialize for atomic system: */
void Test2_ba_StandardServoRead_Init(DW_StandardServoRead_Test2_ba_T *localDW,
  P_StandardServoRead_Test2_bas_T *localP)
{
  /* Start for MATLABSystem: '<Root>/Standard Servo Read' */
  localDW->objisempty = true;
  localDW->obj.SampleTime = localP->StandardServoRead_SampleTime;
  localDW->obj.isInitialized = 1L;
  MW_servoAttach(0, 9);
}

/* Output and update for atomic system: */
void Test2_basic_StandardServoRead(B_StandardServoRead_Test2_bas_T *localB,
  DW_StandardServoRead_Test2_ba_T *localDW, P_StandardServoRead_Test2_bas_T
  *localP)
{
  /* MATLABSystem: '<Root>/Standard Servo Read' */
  if (localDW->obj.SampleTime != localP->StandardServoRead_SampleTime) {
    localDW->obj.SampleTime = localP->StandardServoRead_SampleTime;
  }

  /* MATLABSystem: '<Root>/Standard Servo Read' */
  localB->StandardServoRead = MW_servoRead(0);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Test2_basic_step(void)
{
  real_T tmp_0;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Continuous Servo Write' incorporates:
   *  Constant: '<Root>/target'
   */
  if (Test2_basic_P.target_Value + 90.0 < 0.0) {
    tmp = 0U;
  } else if (Test2_basic_P.target_Value + 90.0 > 180.0) {
    tmp = 180U;
  } else {
    tmp_0 = rt_roundd_snf(Test2_basic_P.target_Value + 90.0);
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint8_T)tmp_0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, tmp);

  /* End of MATLABSystem: '<Root>/Continuous Servo Write' */
  Test2_basic_StandardServoRead(&Test2_basic_B.StandardServoRead,
    &Test2_basic_DW.StandardServoRead, &Test2_basic_P.StandardServoRead);
  Test2_basic_StandardServoRead(&Test2_basic_B.StandardServoRead1,
    &Test2_basic_DW.StandardServoRead1, &Test2_basic_P.StandardServoRead1);

  /* MATLABSystem: '<Root>/Standard Servo Write2' */
  MW_servoWrite(1, 0);

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Test2_basic_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.1s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Test2_basic_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Test2_basic_M->Timing.t[0] =
    ((time_T)(++Test2_basic_M->Timing.clockTick0)) *
    Test2_basic_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Test2_basic_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Test2_basic_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Test2_basic_M->solverInfo,
                          &Test2_basic_M->Timing.simTimeStep);
    rtsiSetTPtr(&Test2_basic_M->solverInfo, &rtmGetTPtr(Test2_basic_M));
    rtsiSetStepSizePtr(&Test2_basic_M->solverInfo,
                       &Test2_basic_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Test2_basic_M->solverInfo, (&rtmGetErrorStatus
      (Test2_basic_M)));
    rtsiSetRTModelPtr(&Test2_basic_M->solverInfo, Test2_basic_M);
  }

  rtsiSetSimTimeStep(&Test2_basic_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Test2_basic_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Test2_basic_M, &Test2_basic_M->Timing.tArray[0]);
  rtmSetTFinal(Test2_basic_M, -1);
  Test2_basic_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Test2_basic_M->Sizes.checksums[0] = (3303306885U);
  Test2_basic_M->Sizes.checksums[1] = (2925279828U);
  Test2_basic_M->Sizes.checksums[2] = (3735635930U);
  Test2_basic_M->Sizes.checksums[3] = (4197222413U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Test2_basic_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Test2_basic_M->extModeInfo,
      &Test2_basic_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Test2_basic_M->extModeInfo,
                        Test2_basic_M->Sizes.checksums);
    rteiSetTPtr(Test2_basic_M->extModeInfo, rtmGetTPtr(Test2_basic_M));
  }

  /* Start for MATLABSystem: '<Root>/Continuous Servo Write' */
  MW_servoAttach(0, 9);
  Test2_ba_StandardServoRead_Init(&Test2_basic_DW.StandardServoRead,
    &Test2_basic_P.StandardServoRead);
  Test2_ba_StandardServoRead_Init(&Test2_basic_DW.StandardServoRead1,
    &Test2_basic_P.StandardServoRead1);

  /* Start for MATLABSystem: '<Root>/Standard Servo Write2' */
  MW_servoAttach(1, 2);
}

/* Model terminate function */
void Test2_basic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
