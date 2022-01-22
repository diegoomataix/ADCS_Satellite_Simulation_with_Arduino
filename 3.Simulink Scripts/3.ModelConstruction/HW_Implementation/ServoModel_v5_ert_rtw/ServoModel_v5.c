/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ServoModel_v5.c
 *
 * Code generated for Simulink model 'ServoModel_v5'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 13:02:19 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ServoModel_v5.h"
#include "ServoModel_v5_private.h"

/* Block signals (default storage) */
B_ServoModel_v5_T ServoModel_v5_B;

/* Block states (default storage) */
DW_ServoModel_v5_T ServoModel_v5_DW;

/* Real-time model */
static RT_MODEL_ServoModel_v5_T ServoModel_v5_M_;
RT_MODEL_ServoModel_v5_T *const ServoModel_v5_M = &ServoModel_v5_M_;

/* Forward declaration for local functions */
static void ServoModel_v_SystemCore_release(codertarget_arduinobase_inter_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ServoModel_v5_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ServoModel_v5_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(ServoModel_v5_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ServoModel_v5_M->Timing.TaskCounters.TID[1])++;
  if ((ServoModel_v5_M->Timing.TaskCounters.TID[1]) > 32) {/* Sample time: [1.65s, 0.0s] */
    ServoModel_v5_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ServoModel_v5_M->Timing.TaskCounters.TID[2])++;
  if ((ServoModel_v5_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [5.0s, 0.0s] */
    ServoModel_v5_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void ServoModel_v_SystemCore_release(codertarget_arduinobase_inter_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }
}

/* Model step function for TID0 */
void ServoModel_v5_step0(void)  /* Sample time: [0.049999999999999996s, 0.0s] */
{
  {                             /* Sample time: [0.049999999999999996s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ServoModel_v5_M->Timing.taskTime0 =
    ((time_T)(++ServoModel_v5_M->Timing.clockTick0)) *
    ServoModel_v5_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void ServoModel_v5_step1(void)         /* Sample time: [1.65s, 0.0s] */
{
  codertarget_arduinobase_inter_T *obj;
  real_T y;

  /* Reset subsysRan breadcrumbs */
  srClearBC(ServoModel_v5_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ServoModel_v5_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ServoModel_v5_DW.IfActionSubsystem2_SubsysRanBC);

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Desired Angle'
   */
  ServoModel_v5_B.Sum = ServoModel_v5_P.DesiredAngle_Value +
    ServoModel_v5_P.Constant_Value;

  /* If: '<Root>/If' */
  if (ServoModel_v5_B.Sum == 0.0) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Inport: '<S2>/In1'
     */
    ServoModel_v5_B.Merge = ServoModel_v5_P.Constant1_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(ServoModel_v5_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem' */
  } else if (ServoModel_v5_B.Sum <= 180.0) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Offset'
     *  Constant: '<Root>/Slope'
     *  Inport: '<S3>/In1'
     *  Product: '<Root>/Product1'
     *  Sum: '<Root>/Sum1'
     */
    ServoModel_v5_B.Merge = ServoModel_v5_P.Slope_Value * ServoModel_v5_B.Sum +
      ServoModel_v5_P.Offset_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(ServoModel_v5_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Inport: '<S4>/In1'
     */
    ServoModel_v5_B.Merge = ServoModel_v5_P.Constant2_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(ServoModel_v5_DW.IfActionSubsystem2_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem2' */
  }

  /* End of If: '<Root>/If' */

  /* MATLABSystem: '<Root>/PWM' */
  obj = &ServoModel_v5_DW.obj;
  if (ServoModel_v5_B.Merge <= 255.0) {
    y = ServoModel_v5_B.Merge;
  } else {
    y = 255.0;
  }

  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
  if (!(y >= 0.0)) {
    y = 0.0;
  }

  MW_PWM_SetDutyCycle(ServoModel_v5_DW.obj.PWMDriverObj.MW_PWM_HANDLE, -(y *
    20000.0 / 255.0));

  /* End of MATLABSystem: '<Root>/PWM' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.65, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ServoModel_v5_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void ServoModel_v5_step2(void)         /* Sample time: [5.0s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 5.0, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ServoModel_v5_M->Timing.clockTick2++;
}

/* Model initialize function */
void ServoModel_v5_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ServoModel_v5_M, -1);
  ServoModel_v5_M->Timing.stepSize0 = 0.049999999999999996;

  /* External mode info */
  ServoModel_v5_M->Sizes.checksums[0] = (208809908U);
  ServoModel_v5_M->Sizes.checksums[1] = (618070911U);
  ServoModel_v5_M->Sizes.checksums[2] = (626992433U);
  ServoModel_v5_M->Sizes.checksums[3] = (3159797334U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    ServoModel_v5_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &ServoModel_v5_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &ServoModel_v5_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &ServoModel_v5_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ServoModel_v5_M->extModeInfo,
      &ServoModel_v5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ServoModel_v5_M->extModeInfo,
                        ServoModel_v5_M->Sizes.checksums);
    rteiSetTPtr(ServoModel_v5_M->extModeInfo, rtmGetTPtr(ServoModel_v5_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/PWM' */
    ServoModel_v5_DW.obj.matlabCodegenIsDeleted = true;
    ServoModel_v5_DW.obj.isInitialized = 0L;
    ServoModel_v5_DW.obj.matlabCodegenIsDeleted = false;
    obj = &ServoModel_v5_DW.obj;
    ServoModel_v5_DW.obj.isSetupComplete = false;
    ServoModel_v5_DW.obj.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 1.0, 20000.0);
    ServoModel_v5_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void ServoModel_v5_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!ServoModel_v5_DW.obj.matlabCodegenIsDeleted) {
    ServoModel_v5_DW.obj.matlabCodegenIsDeleted = true;
    ServoModel_v_SystemCore_release(&ServoModel_v5_DW.obj);
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
