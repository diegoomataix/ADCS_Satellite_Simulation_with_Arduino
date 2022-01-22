/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Test9.c
 *
 * Code generated for Simulink model 'Test9'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 11:43:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Test9.h"
#include "Test9_private.h"

/* Block signals (default storage) */
B_Test9_T Test9_B;

/* Block states (default storage) */
DW_Test9_T Test9_DW;

/* Real-time model */
static RT_MODEL_Test9_T Test9_M_;
RT_MODEL_Test9_T *const Test9_M = &Test9_M_;

/* System initialize for atomic system: */
void Test9_StandardServoRead_Init(DW_StandardServoRead_Test9_T *localDW,
  P_StandardServoRead_Test9_T *localP)
{
  /* Start for MATLABSystem: '<S7>/Standard Servo Read' */
  localDW->objisempty = true;
  localDW->obj.SampleTime = localP->StandardServoRead_SampleTime;
  localDW->obj.isInitialized = 1L;
  MW_servoAttach(0, 9);
}

/* Output and update for atomic system: */
void Test9_StandardServoRead(B_StandardServoRead_Test9_T *localB,
  DW_StandardServoRead_Test9_T *localDW, P_StandardServoRead_Test9_T *localP)
{
  /* MATLABSystem: '<S7>/Standard Servo Read' */
  if (localDW->obj.SampleTime != localP->StandardServoRead_SampleTime) {
    localDW->obj.SampleTime = localP->StandardServoRead_SampleTime;
  }

  /* MATLABSystem: '<S7>/Standard Servo Read' */
  localB->StandardServoRead = MW_servoRead(0);
}

/*
 * Output and update for action system:
 *    '<S23>/If Action Subsystem'
 *    '<S27>/If Action Subsystem'
 */
void Test9_IfActionSubsystem(real_T *rty_Theta_Servo_New,
  P_IfActionSubsystem_Test9_T *localP)
{
  /* SignalConversion generated from: '<S25>/Theta_Servo_New' incorporates:
   *  Constant: '<S25>/Constant'
   */
  *rty_Theta_Servo_New = localP->Constant_Value;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
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
void Test9_step(void)
{
  codertarget_arduinobase_in_fs_T *obj;
  real_T rtb_Abs1;
  int32_T rtb_StandardServoRead_0;
  uint16_T rtb_xp_max;
  uint16_T rtb_yn_max;
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem_SubsysRanB_ay);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem1_SubsysRanB_o);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem1_SubsysRanB_d);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem4_SubsysRanB_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem1_SubsysRanB_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem4_SubsysRanB_l);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem_SubsysRanBC_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem1_SubsysRanB_a);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem4_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem5_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem6_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem7_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem_ps.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem1_SubsysRanB_i);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem_SubsysRanBC_n);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem1_SubsysRan_gm);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.OnlyReadsinyn_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem1_SubsysRanB_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem_SubsysRanBC_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.OnlyReadsinyp_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem_SubsysRanBC_a);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.Lightdoesnotpointatxp_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test9_DW.IfActionSubsystem_SubsysRanBC);

  /* MATLABSystem: '<S3>/Analog Input12' */
  if (Test9_DW.obj_h.SampleTime != Test9_P.AnalogInput12_SampleTime) {
    Test9_DW.obj_h.SampleTime = Test9_P.AnalogInput12_SampleTime;
  }

  obj = &Test9_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);

  /* MATLABSystem: '<S3>/Analog Input12' */
  MW_AnalogInSingle_ReadResult
    (Test9_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &Test9_B.xp_yp, 3);

  /* MATLABSystem: '<S3>/Analog Input14' */
  if (Test9_DW.obj_c4.SampleTime != Test9_P.AnalogInput14_SampleTime) {
    Test9_DW.obj_c4.SampleTime = Test9_P.AnalogInput14_SampleTime;
  }

  obj = &Test9_DW.obj_c4;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);

  /* MATLABSystem: '<S3>/Analog Input14' */
  MW_AnalogInSingle_ReadResult
    (Test9_DW.obj_c4.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &Test9_B.xp_yn, 3);

  /* MinMax: '<S3>/Max' */
  if (Test9_B.xp_yp >= Test9_B.xp_yn) {
    rtb_xp_max = Test9_B.xp_yp;
  } else {
    rtb_xp_max = Test9_B.xp_yn;
  }

  /* End of MinMax: '<S3>/Max' */

  /* MATLABSystem: '<S3>/Analog Input13' */
  if (Test9_DW.obj_l.SampleTime != Test9_P.AnalogInput13_SampleTime) {
    Test9_DW.obj_l.SampleTime = Test9_P.AnalogInput13_SampleTime;
  }

  obj = &Test9_DW.obj_l;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);

  /* MATLABSystem: '<S3>/Analog Input13' */
  MW_AnalogInSingle_ReadResult
    (Test9_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &Test9_B.yp_xp, 3);

  /* MATLABSystem: '<S3>/Analog Input16' */
  if (Test9_DW.obj_i.SampleTime != Test9_P.AnalogInput16_SampleTime) {
    Test9_DW.obj_i.SampleTime = Test9_P.AnalogInput16_SampleTime;
  }

  obj = &Test9_DW.obj_i;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);

  /* MATLABSystem: '<S3>/Analog Input16' */
  MW_AnalogInSingle_ReadResult
    (Test9_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &Test9_B.yp_xn, 3);

  /* MATLABSystem: '<S3>/Analog Input15' */
  if (Test9_DW.obj_c.SampleTime != Test9_P.AnalogInput15_SampleTime) {
    Test9_DW.obj_c.SampleTime = Test9_P.AnalogInput15_SampleTime;
  }

  obj = &Test9_DW.obj_c;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);

  /* MATLABSystem: '<S3>/Analog Input15' */
  MW_AnalogInSingle_ReadResult
    (Test9_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &Test9_B.yn_xp, 3);

  /* MATLABSystem: '<S3>/Analog Input17' */
  if (Test9_DW.obj.SampleTime != Test9_P.AnalogInput17_SampleTime) {
    Test9_DW.obj.SampleTime = Test9_P.AnalogInput17_SampleTime;
  }

  obj = &Test9_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);

  /* MATLABSystem: '<S3>/Analog Input17' */
  MW_AnalogInSingle_ReadResult(Test9_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &Test9_B.yn_xn, 3);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   *  SignalConversion generated from: '<S3>/Gain5'
   */
  Test9_B.DataTypeConversion2[0] = (real_T)((uint32_T)Test9_P.Gain5_Gain *
    rtb_xp_max) * 1.1920928955078125E-7;

  /* MinMax: '<S3>/Max1' */
  if (Test9_B.yp_xp >= Test9_B.yp_xn) {
    rtb_yn_max = Test9_B.yp_xp;
  } else {
    rtb_yn_max = Test9_B.yp_xn;
  }

  /* End of MinMax: '<S3>/Max1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   */
  Test9_B.DataTypeConversion2[1] = (real_T)((uint32_T)Test9_P.Gain5_Gain *
    rtb_yn_max) * 1.1920928955078125E-7;

  /* MinMax: '<S3>/Max2' */
  if (Test9_B.yn_xp >= Test9_B.yn_xn) {
    rtb_yn_max = Test9_B.yn_xp;
  } else {
    rtb_yn_max = Test9_B.yn_xn;
  }

  /* End of MinMax: '<S3>/Max2' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   */
  Test9_B.DataTypeConversion2[2] = (real_T)((uint32_T)Test9_P.Gain5_Gain *
    rtb_yn_max) * 1.1920928955078125E-7;

  /* If: '<S11>/If' */
  if (Test9_B.DataTypeConversion2[0] <= 0.19550342130987292) {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Merge: '<S11>/Merge' incorporates:
     *  Constant: '<S11>/Constant'
     *  Inport: '<S12>/In1'
     */
    Test9_B.Merge = Test9_P.Constant_Value_i;

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Update for If: '<S11>/If' */
    srUpdateBC(Test9_DW.IfActionSubsystem_SubsysRanBC_c);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Merge: '<S11>/Merge' incorporates:
     *  Inport: '<S13>/Vxp'
     */
    Test9_B.Merge = Test9_B.DataTypeConversion2[0];

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Update for If: '<S11>/If' */
    srUpdateBC(Test9_DW.IfActionSubsystem1_SubsysRanB_a);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem1' */
  }

  /* End of If: '<S11>/If' */

  /* If: '<S11>/If2' */
  if (Test9_B.DataTypeConversion2[1] <= 0.19550342130987292) {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Merge: '<S11>/Merge2' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Inport: '<S14>/In1'
     */
    Test9_B.Merge2 = Test9_P.Constant2_Value_g;

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem4' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Update for If: '<S11>/If2' */
    srUpdateBC(Test9_DW.IfActionSubsystem4_SubsysRanBC);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Merge: '<S11>/Merge2' incorporates:
     *  Inport: '<S15>/Vxp'
     */
    Test9_B.Merge2 = Test9_B.DataTypeConversion2[1];

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem5' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Update for If: '<S11>/If2' */
    srUpdateBC(Test9_DW.IfActionSubsystem5_SubsysRanBC);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem5' */
  }

  /* End of If: '<S11>/If2' */

  /* If: '<S11>/If3' */
  if (Test9_B.DataTypeConversion2[2] <= 0.19550342130987292) {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Merge: '<S11>/Merge3' incorporates:
     *  Constant: '<S11>/Constant3'
     *  Inport: '<S16>/In1'
     */
    Test9_B.Merge3 = Test9_P.Constant3_Value;

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem6' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Update for If: '<S11>/If3' */
    srUpdateBC(Test9_DW.IfActionSubsystem6_SubsysRanBC);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem6' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Merge: '<S11>/Merge3' incorporates:
     *  Inport: '<S17>/Vxp'
     */
    Test9_B.Merge3 = Test9_B.DataTypeConversion2[2];

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem7' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Update for If: '<S11>/If3' */
    srUpdateBC(Test9_DW.IfActionSubsystem7_SubsysRanBC);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem7' */
  }

  /* End of If: '<S11>/If3' */
  /* Sqrt: '<S2>/Sqrt2' incorporates:
   *  Math: '<S2>/Math Function2'
   *  Sum: '<S2>/Sum of Elements2'
   *
   * About '<S2>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_Abs1 = sqrt((Test9_B.DataTypeConversion2[0] * Test9_B.DataTypeConversion2
                   [0] + Test9_B.DataTypeConversion2[1] *
                   Test9_B.DataTypeConversion2[1]) +
                  Test9_B.DataTypeConversion2[2] * Test9_B.DataTypeConversion2[2]);

  /* Product: '<S2>/Divide2' incorporates:
   *  Sum: '<S2>/Add3'
   */
  Test9_B.Sat2Beam_VecUnit[0] = Test9_B.Merge / rtb_Abs1;
  Test9_B.Sat2Beam_VecUnit[1] = (Test9_B.Merge2 - Test9_B.Merge3) / rtb_Abs1;

  /* Gain: '<S2>/Gain4' incorporates:
   *  Trigonometry: '<S2>/Trigonometric Function2'
   */
  Test9_B.Gain4 = Test9_P.Gain4_Gain * rt_atan2d_snf(Test9_B.Sat2Beam_VecUnit[1],
    Test9_B.Sat2Beam_VecUnit[0]);

  /* MATLABSystem: '<S1>/Standard Servo Read' */
  if (Test9_DW.obj_p.SampleTime != Test9_P.StandardServoRead_SampleTime) {
    Test9_DW.obj_p.SampleTime = Test9_P.StandardServoRead_SampleTime;
  }

  /* MATLABSystem: '<S1>/Standard Servo Read' */
  Test9_B.Theta_ServoRF = MW_servoRead(0);

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Test9_B.Sum1 = (real_T)Test9_B.Theta_ServoRF - Test9_P.Constant_Value_d;

  /* Sum: '<S1>/Sum' */
  Test9_B.Sum = Test9_B.Gain4 + Test9_B.Sum1;

  /* If: '<S6>/If' incorporates:
   *  Abs: '<S6>/Abs1'
   */
  if (fabs(Test9_B.Sum) > 90.0) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    Test9_StandardServoRead(&Test9_B.StandardServoRead_p,
      &Test9_DW.StandardServoRead_p, &Test9_P.StandardServoRead_p);

    /* If: '<S7>/If' */
    if (Test9_B.Sum > 0.0) {
      /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Merge: '<S6>/Merge1' incorporates:
       *  Constant: '<S7>/Constant'
       *  Constant: '<S9>/Constant'
       *  Sum: '<S7>/Sum'
       *  Sum: '<S9>/Subtract'
       */
      Test9_B.Merge_h = ((real_T)Test9_B.StandardServoRead_p.StandardServoRead -
                         Test9_P.Constant_Value_m) - Test9_P.Constant_Value;

      /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Update for If: '<S7>/If' */
      srUpdateBC(Test9_DW.IfActionSubsystem1_SubsysRanB_d);

      /* End of Update for SubSystem: '<S7>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Merge: '<S6>/Merge1' incorporates:
       *  Constant: '<S10>/Constant'
       *  Sum: '<S10>/Subtract'
       */
      Test9_B.Merge_h = (real_T)Test9_B.StandardServoRead_p.StandardServoRead +
        Test9_P.Constant_Value_a;

      /* End of Outputs for SubSystem: '<S7>/If Action Subsystem4' */

      /* Update for IfAction SubSystem: '<S7>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Update for If: '<S7>/If' */
      srUpdateBC(Test9_DW.IfActionSubsystem4_SubsysRanB_m);

      /* End of Update for SubSystem: '<S7>/If Action Subsystem4' */
    }

    /* End of If: '<S7>/If' */
    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Update for If: '<S6>/If' */
    srUpdateBC(Test9_DW.IfActionSubsystem1_SubsysRanB_f);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S6>/Merge1' incorporates:
     *  Inport: '<S8>/Theta_BeamRF'
     */
    Test9_B.Merge_h = Test9_B.Sum;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem4' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Update for If: '<S6>/If' */
    srUpdateBC(Test9_DW.IfActionSubsystem4_SubsysRanB_l);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem4' */
  }

  /* End of If: '<S6>/If' */
  /* If: '<S3>/If' */
  if (rtb_xp_max < 30U) {
    /* Outputs for IfAction SubSystem: '<S3>/Light does not point at xp' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* MinMax: '<S19>/Max' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion1'
     *  DataTypeConversion: '<S19>/Data Type Conversion2'
     */
    if ((real_T)Test9_B.yp_xp >= Test9_B.yp_xn) {
      rtb_xp_max = Test9_B.yp_xp;
    } else {
      rtb_xp_max = Test9_B.yp_xn;
    }

    /* End of MinMax: '<S19>/Max' */

    /* MinMax: '<S19>/Max1' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion3'
     *  DataTypeConversion: '<S19>/Data Type Conversion4'
     */
    if ((real_T)Test9_B.yn_xp >= Test9_B.yn_xn) {
      rtb_yn_max = Test9_B.yn_xp;
    } else {
      rtb_yn_max = Test9_B.yn_xn;
    }

    /* End of MinMax: '<S19>/Max1' */

    /* If: '<S19>/If' */
    if ((rtb_xp_max < 40U) && (rtb_yn_max > 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/Only Reads in yn' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      Test9_StandardServoRead(&Test9_B.StandardServoRead_pn,
        &Test9_DW.StandardServoRead_pn, &Test9_P.StandardServoRead_pn);

      /* Sum: '<S21>/Sum' incorporates:
       *  Constant: '<S21>/Constant2'
       */
      Test9_B.Merge_g = (real_T)Test9_B.StandardServoRead_pn.StandardServoRead -
        Test9_P.Constant2_Value;

      /* If: '<S21>/If' incorporates:
       *  Constant: '<S21>/Constant'
       *  DataTypeConversion: '<S19>/Data Type Conversion3'
       *  DataTypeConversion: '<S19>/Data Type Conversion4'
       *  Sum: '<S21>/Add'
       */
      if ((real_T)Test9_B.yn_xp + Test9_P.Constant_Value_nv < Test9_B.yn_xn) {
        /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        /* If: '<S23>/If' */
        if (Test9_B.Merge_g >= 86.0) {
          /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
           *  ActionPort: '<S25>/Action Port'
           */
          Test9_IfActionSubsystem(&Test9_B.Merge_g,
            &Test9_P.IfActionSubsystem_ps);

          /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* Sum: '<S21>/Sum' incorporates:
           *  Constant: '<S26>/Constant'
           *  Merge: '<S21>/Merge'
           *  Sum: '<S26>/Add'
           */
          Test9_B.Merge_g += Test9_P.Constant_Value_n;

          /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* Update for If: '<S23>/If' */
          srUpdateBC(Test9_DW.IfActionSubsystem1_SubsysRanB_i);

          /* End of Update for SubSystem: '<S23>/If Action Subsystem1' */
        }

        /* End of If: '<S23>/If' */
        /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */

        /* Update for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        /* Update for If: '<S21>/If' */
        srUpdateBC(Test9_DW.IfActionSubsystem_SubsysRanBC_n);

        /* End of Update for SubSystem: '<S21>/If Action Subsystem' */
      } else {
        /* Update for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        /* Update for If: '<S21>/If' */
        srUpdateBC(Test9_DW.IfActionSubsystem1_SubsysRan_gm);

        /* End of Update for SubSystem: '<S21>/If Action Subsystem1' */
      }

      /* End of If: '<S21>/If' */
      /* Merge: '<S19>/Merge' incorporates:
       *  SignalConversion generated from: '<S21>/Theta_Servo_New'
       */
      Test9_B.Merge_a = Test9_B.Merge_g;

      /* End of Outputs for SubSystem: '<S19>/Only Reads in yn' */

      /* Update for IfAction SubSystem: '<S19>/Only Reads in yn' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Update for If: '<S19>/If' */
      srUpdateBC(Test9_DW.OnlyReadsinyn_SubsysRanBC);

      /* End of Update for SubSystem: '<S19>/Only Reads in yn' */
    }

    /* End of If: '<S19>/If' */

    /* If: '<S19>/If1' */
    if ((rtb_yn_max < 40U) && (rtb_xp_max > 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/Only Reads in yp' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      Test9_StandardServoRead(&Test9_B.StandardServoRead_pna,
        &Test9_DW.StandardServoRead_pna, &Test9_P.StandardServoRead_pna);

      /* Sum: '<S22>/Sum' incorporates:
       *  Constant: '<S22>/Constant2'
       */
      Test9_B.Merge_k = (real_T)Test9_B.StandardServoRead_pna.StandardServoRead
        - Test9_P.Constant2_Value_a;

      /* If: '<S22>/If' incorporates:
       *  Constant: '<S22>/Constant'
       *  DataTypeConversion: '<S19>/Data Type Conversion1'
       *  DataTypeConversion: '<S19>/Data Type Conversion2'
       *  Sum: '<S22>/Add'
       */
      if ((real_T)Test9_B.yp_xp + Test9_P.Constant_Value_mh < Test9_B.yp_xn) {
        /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* If: '<S27>/If' */
        if (Test9_B.Merge_k <= -86.0) {
          /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          Test9_IfActionSubsystem(&Test9_B.Merge_k, &Test9_P.IfActionSubsystem_h);

          /* End of Outputs for SubSystem: '<S27>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S30>/Action Port'
           */
          /* Sum: '<S22>/Sum' incorporates:
           *  Constant: '<S30>/Constant'
           *  Merge: '<S22>/Merge'
           *  Sum: '<S30>/Add'
           */
          Test9_B.Merge_k -= Test9_P.Constant_Value_m1;

          /* End of Outputs for SubSystem: '<S27>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S30>/Action Port'
           */
          /* Update for If: '<S27>/If' */
          srUpdateBC(Test9_DW.IfActionSubsystem1_SubsysRanB_g);

          /* End of Update for SubSystem: '<S27>/If Action Subsystem1' */
        }

        /* End of If: '<S27>/If' */
        /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */

        /* Update for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Update for If: '<S22>/If' */
        srUpdateBC(Test9_DW.IfActionSubsystem_SubsysRanBC_g);

        /* End of Update for SubSystem: '<S22>/If Action Subsystem' */
      } else {
        /* Update for IfAction SubSystem: '<S22>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Update for If: '<S22>/If' */
        srUpdateBC(Test9_DW.IfActionSubsystem1_SubsysRanBC);

        /* End of Update for SubSystem: '<S22>/If Action Subsystem1' */
      }

      /* End of If: '<S22>/If' */

      /* Merge: '<S19>/Merge' incorporates:
       *  SignalConversion generated from: '<S22>/Theta_Servo_New'
       */
      Test9_B.Merge_a = Test9_B.Merge_k;

      /* End of Outputs for SubSystem: '<S19>/Only Reads in yp' */

      /* Update for IfAction SubSystem: '<S19>/Only Reads in yp' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Update for If: '<S19>/If1' */
      srUpdateBC(Test9_DW.OnlyReadsinyp_SubsysRanBC);

      /* End of Update for SubSystem: '<S19>/Only Reads in yp' */
    }

    /* End of If: '<S19>/If1' */

    /* If: '<S19>/If2' */
    if ((rtb_yn_max < 40U) && (rtb_xp_max < 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* MATLABSystem: '<S20>/Standard Servo Read' */
      if (Test9_DW.obj_c2.SampleTime != Test9_P.StandardServoRead_SampleTime_e)
      {
        Test9_DW.obj_c2.SampleTime = Test9_P.StandardServoRead_SampleTime_e;
      }

      rtb_StandardServoRead_0 = MW_servoRead(1);

      /* DataTypeConversion: '<S20>/Data Type Conversion' incorporates:
       *  Constant: '<S20>/Constant'
       *  MATLABSystem: '<S20>/Standard Servo Read'
       *  Sum: '<S20>/Sum'
       */
      Test9_B.DataTypeConversion = (real_T)rtb_StandardServoRead_0 -
        Test9_P.Constant_Value_mx;

      /* Merge: '<S19>/Merge' incorporates:
       *  SignalConversion generated from: '<S20>/Out1'
       */
      Test9_B.Merge_a = Test9_B.DataTypeConversion;

      /* SignalConversion generated from: '<S20>/Output' */
      Test9_B.OutportBufferForOutput = Test9_B.DataTypeConversion;

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Update for If: '<S19>/If2' */
      srUpdateBC(Test9_DW.IfActionSubsystem_SubsysRanBC_a);

      /* End of Update for SubSystem: '<S19>/If Action Subsystem' */
    }

    /* End of If: '<S19>/If2' */
    /* Merge: '<S3>/Merge' incorporates:
     *  SignalConversion generated from: '<S19>/Output'
     */
    Test9_B.Merge_l = Test9_B.Merge_a;

    /* Update for IfAction SubSystem: '<S3>/Light does not point at xp' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Update for If: '<S3>/If' */
    srUpdateBC(Test9_DW.Lightdoesnotpointatxp_SubsysRan);

    /* End of Update for SubSystem: '<S3>/Light does not point at xp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S18>/Constant'
     *  SignalConversion generated from: '<S18>/Out1'
     */
    Test9_B.Merge_l = Test9_P.Constant_Value_p;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Update for If: '<S3>/If' */
    srUpdateBC(Test9_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S3>/If Action Subsystem' */
  }

  /* End of If: '<S3>/If' */
  /* If: '<S1>/If' */
  if (Test9_B.Merge_l == 100.0) {
    /* Update for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Update for If: '<S1>/If' */
    srUpdateBC(Test9_DW.IfActionSubsystem_SubsysRanB_ay);

    /* End of Update for SubSystem: '<S1>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<S6>/Merge1' incorporates:
     *  Inport: '<S5>/Input'
     *  Merge: '<S1>/Merge'
     */
    Test9_B.Merge_h = Test9_B.Merge_l;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Update for If: '<S1>/If' */
    srUpdateBC(Test9_DW.IfActionSubsystem1_SubsysRanB_o);

    /* End of Update for SubSystem: '<S1>/If Action Subsystem1' */
  }

  /* End of If: '<S1>/If' */

  /* MATLABSystem: '<S1>/Continuous Servo Write' */
  if (Test9_B.Merge_h + 90.0 < 0.0) {
    tmp = 0U;
  } else if (Test9_B.Merge_h + 90.0 > 180.0) {
    tmp = 180U;
  } else {
    rtb_Abs1 = rt_roundd_snf(Test9_B.Merge_h + 90.0);
    if (rtb_Abs1 < 256.0) {
      if (rtb_Abs1 >= 0.0) {
        tmp = (uint8_T)rtb_Abs1;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, tmp);

  /* End of MATLABSystem: '<S1>/Continuous Servo Write' */
  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Test9_M->Timing.taskTime0 =
    ((time_T)(++Test9_M->Timing.clockTick0)) * Test9_M->Timing.stepSize0;
}

/* Model initialize function */
void Test9_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Test9_M, -1);
  Test9_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Test9_M->Sizes.checksums[0] = (2440665666U);
  Test9_M->Sizes.checksums[1] = (942710560U);
  Test9_M->Sizes.checksums[2] = (1385264403U);
  Test9_M->Sizes.checksums[3] = (2036576402U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[38];
    Test9_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&Test9_DW.IfActionSubsystem_SubsysRanB_ay;
    systemRan[3] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRanB_o;
    systemRan[4] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRanB_d;
    systemRan[5] = (sysRanDType *)&Test9_DW.IfActionSubsystem4_SubsysRanB_m;
    systemRan[6] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRanB_f;
    systemRan[7] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRanB_f;
    systemRan[8] = (sysRanDType *)&Test9_DW.IfActionSubsystem4_SubsysRanB_l;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)&Test9_DW.IfActionSubsystem_SubsysRanBC_c;
    systemRan[11] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRanB_a;
    systemRan[12] = (sysRanDType *)&Test9_DW.IfActionSubsystem4_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&Test9_DW.IfActionSubsystem5_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&Test9_DW.IfActionSubsystem6_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&Test9_DW.IfActionSubsystem7_SubsysRanBC;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = (sysRanDType *)&Test9_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&Test9_DW.IfActionSubsystem_SubsysRanBC_a;
    systemRan[24] = (sysRanDType *)&Test9_DW.IfActionSubsystem_SubsysRanBC_a;
    systemRan[25] = (sysRanDType *)
      &Test9_DW.IfActionSubsystem_ps.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRanB_i;
    systemRan[27] = (sysRanDType *)&Test9_DW.IfActionSubsystem_SubsysRanBC_n;
    systemRan[28] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRan_gm;
    systemRan[29] = (sysRanDType *)&Test9_DW.OnlyReadsinyn_SubsysRanBC;
    systemRan[30] = (sysRanDType *)&Test9_DW.OnlyReadsinyn_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &Test9_DW.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC;
    systemRan[32] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRanB_g;
    systemRan[33] = (sysRanDType *)&Test9_DW.IfActionSubsystem_SubsysRanBC_g;
    systemRan[34] = (sysRanDType *)&Test9_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&Test9_DW.OnlyReadsinyp_SubsysRanBC;
    systemRan[36] = (sysRanDType *)&Test9_DW.OnlyReadsinyp_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&Test9_DW.Lightdoesnotpointatxp_SubsysRan;
    rteiSetModelMappingInfoPtr(Test9_M->extModeInfo,
      &Test9_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Test9_M->extModeInfo, Test9_M->Sizes.checksums);
    rteiSetTPtr(Test9_M->extModeInfo, rtmGetTPtr(Test9_M));
  }

  {
    codertarget_arduinobase_in_fs_T *obj;

    /* SystemInitialize for IfAction SubSystem: '<S6>/If Action Subsystem1' */
    Test9_StandardServoRead_Init(&Test9_DW.StandardServoRead_p,
      &Test9_P.StandardServoRead_p);

    /* End of SystemInitialize for SubSystem: '<S6>/If Action Subsystem1' */

    /* SystemInitialize for Sum: '<S21>/Sum' incorporates:
     *  Merge: '<S21>/Merge'
     */
    Test9_B.Merge_g = Test9_P.Merge_InitialOutput;
    Test9_StandardServoRead_Init(&Test9_DW.StandardServoRead_pn,
      &Test9_P.StandardServoRead_pn);

    /* End of SystemInitialize for SubSystem: '<S19>/Only Reads in yn' */

    /* SystemInitialize for IfAction SubSystem: '<S19>/Only Reads in yp' */
    /* SystemInitialize for Sum: '<S22>/Sum' incorporates:
     *  Merge: '<S22>/Merge'
     */
    Test9_B.Merge_k = Test9_P.Merge_InitialOutput_j;
    Test9_StandardServoRead_Init(&Test9_DW.StandardServoRead_pna,
      &Test9_P.StandardServoRead_pna);

    /* End of SystemInitialize for SubSystem: '<S19>/Only Reads in yp' */

    /* SystemInitialize for IfAction SubSystem: '<S19>/If Action Subsystem' */
    /* Start for MATLABSystem: '<S20>/Standard Servo Read' */
    Test9_DW.obj_c2.SampleTime = Test9_P.StandardServoRead_SampleTime_e;
    Test9_DW.obj_c2.isInitialized = 1L;
    MW_servoAttach(1, 2);

    /* SystemInitialize for SignalConversion generated from: '<S20>/Output' incorporates:
     *  Outport: '<S20>/Output'
     */
    Test9_B.OutportBufferForOutput = Test9_P.Output_Y0;

    /* End of SystemInitialize for SubSystem: '<S19>/If Action Subsystem' */

    /* SystemInitialize for Merge: '<S19>/Merge' */
    Test9_B.Merge_a = Test9_P.Merge_InitialOutput_g;

    /* End of SystemInitialize for SubSystem: '<S3>/Light does not point at xp' */

    /* Start for MATLABSystem: '<S3>/Analog Input12' */
    Test9_DW.obj_h.matlabCodegenIsDeleted = true;
    Test9_DW.obj_h.isInitialized = 0L;
    Test9_DW.obj_h.SampleTime = -1.0;
    Test9_DW.obj_h.matlabCodegenIsDeleted = false;
    Test9_DW.obj_h.SampleTime = Test9_P.AnalogInput12_SampleTime;
    obj = &Test9_DW.obj_h;
    Test9_DW.obj_h.isSetupComplete = false;
    Test9_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16UL);
    Test9_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input14' */
    Test9_DW.obj_c4.matlabCodegenIsDeleted = true;
    Test9_DW.obj_c4.isInitialized = 0L;
    Test9_DW.obj_c4.SampleTime = -1.0;
    Test9_DW.obj_c4.matlabCodegenIsDeleted = false;
    Test9_DW.obj_c4.SampleTime = Test9_P.AnalogInput14_SampleTime;
    obj = &Test9_DW.obj_c4;
    Test9_DW.obj_c4.isSetupComplete = false;
    Test9_DW.obj_c4.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17UL);
    Test9_DW.obj_c4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input13' */
    Test9_DW.obj_l.matlabCodegenIsDeleted = true;
    Test9_DW.obj_l.isInitialized = 0L;
    Test9_DW.obj_l.SampleTime = -1.0;
    Test9_DW.obj_l.matlabCodegenIsDeleted = false;
    Test9_DW.obj_l.SampleTime = Test9_P.AnalogInput13_SampleTime;
    obj = &Test9_DW.obj_l;
    Test9_DW.obj_l.isSetupComplete = false;
    Test9_DW.obj_l.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    Test9_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input16' */
    Test9_DW.obj_i.matlabCodegenIsDeleted = true;
    Test9_DW.obj_i.isInitialized = 0L;
    Test9_DW.obj_i.SampleTime = -1.0;
    Test9_DW.obj_i.matlabCodegenIsDeleted = false;
    Test9_DW.obj_i.SampleTime = Test9_P.AnalogInput16_SampleTime;
    obj = &Test9_DW.obj_i;
    Test9_DW.obj_i.isSetupComplete = false;
    Test9_DW.obj_i.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    Test9_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input15' */
    Test9_DW.obj_c.matlabCodegenIsDeleted = true;
    Test9_DW.obj_c.isInitialized = 0L;
    Test9_DW.obj_c.SampleTime = -1.0;
    Test9_DW.obj_c.matlabCodegenIsDeleted = false;
    Test9_DW.obj_c.SampleTime = Test9_P.AnalogInput15_SampleTime;
    obj = &Test9_DW.obj_c;
    Test9_DW.obj_c.isSetupComplete = false;
    Test9_DW.obj_c.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    Test9_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input17' */
    Test9_DW.obj.matlabCodegenIsDeleted = true;
    Test9_DW.obj.isInitialized = 0L;
    Test9_DW.obj.SampleTime = -1.0;
    Test9_DW.obj.matlabCodegenIsDeleted = false;
    Test9_DW.obj.SampleTime = Test9_P.AnalogInput17_SampleTime;
    obj = &Test9_DW.obj;
    Test9_DW.obj.isSetupComplete = false;
    Test9_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19UL);
    Test9_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Standard Servo Read' */
    Test9_DW.obj_p.SampleTime = Test9_P.StandardServoRead_SampleTime;
    Test9_DW.obj_p.isInitialized = 1L;
    MW_servoAttach(0, 9);

    /* Start for MATLABSystem: '<S1>/Continuous Servo Write' */
    MW_servoAttach(0, 9);
  }
}

/* Model terminate function */
void Test9_terminate(void)
{
  codertarget_arduinobase_in_fs_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Analog Input12' */
  obj = &Test9_DW.obj_h;
  if (!Test9_DW.obj_h.matlabCodegenIsDeleted) {
    Test9_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Test9_DW.obj_h.isInitialized == 1L) && Test9_DW.obj_h.isSetupComplete)
    {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close(Test9_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input12' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input14' */
  obj = &Test9_DW.obj_c4;
  if (!Test9_DW.obj_c4.matlabCodegenIsDeleted) {
    Test9_DW.obj_c4.matlabCodegenIsDeleted = true;
    if ((Test9_DW.obj_c4.isInitialized == 1L) && Test9_DW.obj_c4.isSetupComplete)
    {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close(Test9_DW.obj_c4.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input14' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input13' */
  obj = &Test9_DW.obj_l;
  if (!Test9_DW.obj_l.matlabCodegenIsDeleted) {
    Test9_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Test9_DW.obj_l.isInitialized == 1L) && Test9_DW.obj_l.isSetupComplete)
    {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close(Test9_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input13' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input16' */
  obj = &Test9_DW.obj_i;
  if (!Test9_DW.obj_i.matlabCodegenIsDeleted) {
    Test9_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Test9_DW.obj_i.isInitialized == 1L) && Test9_DW.obj_i.isSetupComplete)
    {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close(Test9_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input16' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input15' */
  obj = &Test9_DW.obj_c;
  if (!Test9_DW.obj_c.matlabCodegenIsDeleted) {
    Test9_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Test9_DW.obj_c.isInitialized == 1L) && Test9_DW.obj_c.isSetupComplete)
    {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close(Test9_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input15' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input17' */
  obj = &Test9_DW.obj;
  if (!Test9_DW.obj.matlabCodegenIsDeleted) {
    Test9_DW.obj.matlabCodegenIsDeleted = true;
    if ((Test9_DW.obj.isInitialized == 1L) && Test9_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close(Test9_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input17' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
