/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DAL_Sat_HW_v5.c
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

/* Block signals (default storage) */
B_DAL_Sat_HW_v5_T DAL_Sat_HW_v5_B;

/* Block states (default storage) */
DW_DAL_Sat_HW_v5_T DAL_Sat_HW_v5_DW;

/* Real-time model */
static RT_MODEL_DAL_Sat_HW_v5_T DAL_Sat_HW_v5_M_;
RT_MODEL_DAL_Sat_HW_v5_T *const DAL_Sat_HW_v5_M = &DAL_Sat_HW_v5_M_;

/* System initialize for atomic system: */
void DAL_Sat__StandardServoRead_Init(DW_StandardServoRead_DAL_Sat__T *localDW,
  P_StandardServoRead_DAL_Sat_H_T *localP)
{
  /* Start for MATLABSystem: '<S1>/Standard Servo Read' */
  localDW->objisempty = true;
  localDW->obj.SampleTime = localP->StandardServoRead_SampleTime;
  localDW->obj.isInitialized = 1L;
  MW_servoAttach(0, 9);
}

/* Output and update for atomic system: */
void DAL_Sat_HW_v5_StandardServoRead(B_StandardServoRead_DAL_Sat_H_T *localB,
  DW_StandardServoRead_DAL_Sat__T *localDW, P_StandardServoRead_DAL_Sat_H_T
  *localP)
{
  /* MATLABSystem: '<S1>/Standard Servo Read' */
  if (localDW->obj.SampleTime != localP->StandardServoRead_SampleTime) {
    localDW->obj.SampleTime = localP->StandardServoRead_SampleTime;
  }

  /* MATLABSystem: '<S1>/Standard Servo Read' */
  localB->Theta_ServoRF = MW_servoRead(0);
}

/*
 * Output and update for action system:
 *    '<S23>/If Action Subsystem'
 *    '<S27>/If Action Subsystem'
 */
void DAL_Sat_HW_v5_IfActionSubsystem(real_T *rty_Theta_Servo_New,
  P_IfActionSubsystem_DAL_Sat_H_T *localP)
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
void DAL_Sat_HW_v5_step(void)
{
  codertarget_arduinobase_in_cg_T *obj;
  real_T rtb_Abs1;
  int32_T rtb_StandardServoRead_0;
  uint16_T rtb_xp_max;
  uint16_T rtb_yn_max;
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanB_a);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_d);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanB_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanB_g4);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRan_hd);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem5_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem6_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem7_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_a);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.OnlyReadsinyn_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.OnlyReadsinyp_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.Lightdoesnotpointatxp_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC);

  /* MATLABSystem: '<S3>/Analog Input12' */
  if (DAL_Sat_HW_v5_DW.obj_e.SampleTime !=
      DAL_Sat_HW_v5_P.AnalogInput12_SampleTime) {
    DAL_Sat_HW_v5_DW.obj_e.SampleTime = DAL_Sat_HW_v5_P.AnalogInput12_SampleTime;
  }

  obj = &DAL_Sat_HW_v5_DW.obj_e;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);

  /* MATLABSystem: '<S3>/Analog Input12' */
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v5_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &DAL_Sat_HW_v5_B.xp_yp, 3);

  /* MATLABSystem: '<S3>/Analog Input14' */
  if (DAL_Sat_HW_v5_DW.obj_h.SampleTime !=
      DAL_Sat_HW_v5_P.AnalogInput14_SampleTime) {
    DAL_Sat_HW_v5_DW.obj_h.SampleTime = DAL_Sat_HW_v5_P.AnalogInput14_SampleTime;
  }

  obj = &DAL_Sat_HW_v5_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);

  /* MATLABSystem: '<S3>/Analog Input14' */
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v5_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &DAL_Sat_HW_v5_B.xp_yn, 3);

  /* MinMax: '<S3>/Max' */
  if (DAL_Sat_HW_v5_B.xp_yp >= DAL_Sat_HW_v5_B.xp_yn) {
    rtb_xp_max = DAL_Sat_HW_v5_B.xp_yp;
  } else {
    rtb_xp_max = DAL_Sat_HW_v5_B.xp_yn;
  }

  /* End of MinMax: '<S3>/Max' */

  /* MATLABSystem: '<S3>/Analog Input13' */
  if (DAL_Sat_HW_v5_DW.obj_a.SampleTime !=
      DAL_Sat_HW_v5_P.AnalogInput13_SampleTime) {
    DAL_Sat_HW_v5_DW.obj_a.SampleTime = DAL_Sat_HW_v5_P.AnalogInput13_SampleTime;
  }

  obj = &DAL_Sat_HW_v5_DW.obj_a;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);

  /* MATLABSystem: '<S3>/Analog Input13' */
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v5_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &DAL_Sat_HW_v5_B.yp_xp, 3);

  /* MATLABSystem: '<S3>/Analog Input16' */
  if (DAL_Sat_HW_v5_DW.obj_k.SampleTime !=
      DAL_Sat_HW_v5_P.AnalogInput16_SampleTime) {
    DAL_Sat_HW_v5_DW.obj_k.SampleTime = DAL_Sat_HW_v5_P.AnalogInput16_SampleTime;
  }

  obj = &DAL_Sat_HW_v5_DW.obj_k;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);

  /* MATLABSystem: '<S3>/Analog Input16' */
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v5_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &DAL_Sat_HW_v5_B.yp_xn, 3);

  /* MATLABSystem: '<S3>/Analog Input15' */
  if (DAL_Sat_HW_v5_DW.obj_m.SampleTime !=
      DAL_Sat_HW_v5_P.AnalogInput15_SampleTime) {
    DAL_Sat_HW_v5_DW.obj_m.SampleTime = DAL_Sat_HW_v5_P.AnalogInput15_SampleTime;
  }

  obj = &DAL_Sat_HW_v5_DW.obj_m;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);

  /* MATLABSystem: '<S3>/Analog Input15' */
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v5_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &DAL_Sat_HW_v5_B.yn_xp, 3);

  /* MATLABSystem: '<S3>/Analog Input17' */
  if (DAL_Sat_HW_v5_DW.obj.SampleTime !=
      DAL_Sat_HW_v5_P.AnalogInput17_SampleTime) {
    DAL_Sat_HW_v5_DW.obj.SampleTime = DAL_Sat_HW_v5_P.AnalogInput17_SampleTime;
  }

  obj = &DAL_Sat_HW_v5_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);

  /* MATLABSystem: '<S3>/Analog Input17' */
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v5_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &DAL_Sat_HW_v5_B.yn_xn, 3);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   *  SignalConversion generated from: '<S3>/Gain5'
   */
  DAL_Sat_HW_v5_B.DataTypeConversion2[0] = (real_T)((uint32_T)
    DAL_Sat_HW_v5_P.Gain5_Gain * rtb_xp_max) * 1.1920928955078125E-7;

  /* MinMax: '<S3>/Max1' */
  if (DAL_Sat_HW_v5_B.yp_xp >= DAL_Sat_HW_v5_B.yp_xn) {
    rtb_yn_max = DAL_Sat_HW_v5_B.yp_xp;
  } else {
    rtb_yn_max = DAL_Sat_HW_v5_B.yp_xn;
  }

  /* End of MinMax: '<S3>/Max1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   */
  DAL_Sat_HW_v5_B.DataTypeConversion2[1] = (real_T)((uint32_T)
    DAL_Sat_HW_v5_P.Gain5_Gain * rtb_yn_max) * 1.1920928955078125E-7;

  /* MinMax: '<S3>/Max2' */
  if (DAL_Sat_HW_v5_B.yn_xp >= DAL_Sat_HW_v5_B.yn_xn) {
    rtb_yn_max = DAL_Sat_HW_v5_B.yn_xp;
  } else {
    rtb_yn_max = DAL_Sat_HW_v5_B.yn_xn;
  }

  /* End of MinMax: '<S3>/Max2' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   */
  DAL_Sat_HW_v5_B.DataTypeConversion2[2] = (real_T)((uint32_T)
    DAL_Sat_HW_v5_P.Gain5_Gain * rtb_yn_max) * 1.1920928955078125E-7;

  /* If: '<S11>/If' */
  if (DAL_Sat_HW_v5_B.DataTypeConversion2[0] <= 0.19550342130987292) {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Merge: '<S11>/Merge' incorporates:
     *  Constant: '<S11>/Constant'
     *  Inport: '<S12>/In1'
     */
    DAL_Sat_HW_v5_B.Merge = DAL_Sat_HW_v5_P.Constant_Value_l;

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Update for If: '<S11>/If' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanB_g4);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Merge: '<S11>/Merge' incorporates:
     *  Inport: '<S13>/Vxp'
     */
    DAL_Sat_HW_v5_B.Merge = DAL_Sat_HW_v5_B.DataTypeConversion2[0];

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Update for If: '<S11>/If' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRan_hd);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem1' */
  }

  /* End of If: '<S11>/If' */

  /* If: '<S11>/If2' */
  if (DAL_Sat_HW_v5_B.DataTypeConversion2[1] <= 0.19550342130987292) {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Merge: '<S11>/Merge2' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Inport: '<S14>/In1'
     */
    DAL_Sat_HW_v5_B.Merge2 = DAL_Sat_HW_v5_P.Constant2_Value_e;

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem4' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Update for If: '<S11>/If2' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanBC);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Merge: '<S11>/Merge2' incorporates:
     *  Inport: '<S15>/Vxp'
     */
    DAL_Sat_HW_v5_B.Merge2 = DAL_Sat_HW_v5_B.DataTypeConversion2[1];

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem5' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Update for If: '<S11>/If2' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem5_SubsysRanBC);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem5' */
  }

  /* End of If: '<S11>/If2' */

  /* If: '<S11>/If3' */
  if (DAL_Sat_HW_v5_B.DataTypeConversion2[2] <= 0.19550342130987292) {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Merge: '<S11>/Merge3' incorporates:
     *  Constant: '<S11>/Constant3'
     *  Inport: '<S16>/In1'
     */
    DAL_Sat_HW_v5_B.Merge3 = DAL_Sat_HW_v5_P.Constant3_Value;

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem6' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Update for If: '<S11>/If3' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem6_SubsysRanBC);

    /* End of Update for SubSystem: '<S11>/If Action Subsystem6' */
  } else {
    /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Merge: '<S11>/Merge3' incorporates:
     *  Inport: '<S17>/Vxp'
     */
    DAL_Sat_HW_v5_B.Merge3 = DAL_Sat_HW_v5_B.DataTypeConversion2[2];

    /* End of Outputs for SubSystem: '<S11>/If Action Subsystem7' */

    /* Update for IfAction SubSystem: '<S11>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Update for If: '<S11>/If3' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem7_SubsysRanBC);

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
  rtb_Abs1 = sqrt((DAL_Sat_HW_v5_B.DataTypeConversion2[0] *
                   DAL_Sat_HW_v5_B.DataTypeConversion2[0] +
                   DAL_Sat_HW_v5_B.DataTypeConversion2[1] *
                   DAL_Sat_HW_v5_B.DataTypeConversion2[1]) +
                  DAL_Sat_HW_v5_B.DataTypeConversion2[2] *
                  DAL_Sat_HW_v5_B.DataTypeConversion2[2]);

  /* Product: '<S2>/Divide2' incorporates:
   *  Sum: '<S2>/Add3'
   */
  DAL_Sat_HW_v5_B.Sat2Beam_VecUnit[0] = DAL_Sat_HW_v5_B.Merge / rtb_Abs1;
  DAL_Sat_HW_v5_B.Sat2Beam_VecUnit[1] = (DAL_Sat_HW_v5_B.Merge2 -
    DAL_Sat_HW_v5_B.Merge3) / rtb_Abs1;

  /* Gain: '<S2>/Gain4' incorporates:
   *  Trigonometry: '<S2>/Trigonometric Function2'
   */
  DAL_Sat_HW_v5_B.Gain4 = DAL_Sat_HW_v5_P.Gain4_Gain * rt_atan2d_snf
    (DAL_Sat_HW_v5_B.Sat2Beam_VecUnit[1], DAL_Sat_HW_v5_B.Sat2Beam_VecUnit[0]);

  /* UnitDelay: '<S1>/Unit Delay1' */
  DAL_Sat_HW_v5_B.UnitDelay1 = DAL_Sat_HW_v5_DW.UnitDelay1_DSTATE;

  /* Sum: '<S1>/Sum' */
  DAL_Sat_HW_v5_B.Sum = DAL_Sat_HW_v5_B.Gain4 + DAL_Sat_HW_v5_B.UnitDelay1;

  /* If: '<S6>/If' incorporates:
   *  Abs: '<S6>/Abs1'
   */
  if (fabs(DAL_Sat_HW_v5_B.Sum) > 90.0) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* If: '<S7>/If' */
    if (DAL_Sat_HW_v5_B.Sum > 0.0) {
      /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Merge: '<S6>/Merge1' incorporates:
       *  Constant: '<S9>/Constant'
       *  Sum: '<S9>/Subtract'
       */
      DAL_Sat_HW_v5_B.Merge_b = DAL_Sat_HW_v5_B.Sum +
        DAL_Sat_HW_v5_P.Constant_Value;

      /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Update for If: '<S7>/If' */
      srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_m);

      /* End of Update for SubSystem: '<S7>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Merge: '<S6>/Merge1' incorporates:
       *  Constant: '<S10>/Constant'
       *  Sum: '<S10>/Subtract'
       */
      DAL_Sat_HW_v5_B.Merge_b = DAL_Sat_HW_v5_B.Sum -
        DAL_Sat_HW_v5_P.Constant_Value_i;

      /* End of Outputs for SubSystem: '<S7>/If Action Subsystem4' */

      /* Update for IfAction SubSystem: '<S7>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Update for If: '<S7>/If' */
      srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanB_a);

      /* End of Update for SubSystem: '<S7>/If Action Subsystem4' */
    }

    /* End of If: '<S7>/If' */
    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Update for If: '<S6>/If' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_d);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S6>/Merge1' incorporates:
     *  Inport: '<S8>/Theta_BeamRF'
     */
    DAL_Sat_HW_v5_B.Merge_b = DAL_Sat_HW_v5_B.Sum;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem4' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Update for If: '<S6>/If' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanB_h);

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
    if ((real_T)DAL_Sat_HW_v5_B.yp_xp >= DAL_Sat_HW_v5_B.yp_xn) {
      rtb_xp_max = DAL_Sat_HW_v5_B.yp_xp;
    } else {
      rtb_xp_max = DAL_Sat_HW_v5_B.yp_xn;
    }

    /* End of MinMax: '<S19>/Max' */

    /* MinMax: '<S19>/Max1' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion3'
     *  DataTypeConversion: '<S19>/Data Type Conversion4'
     */
    if ((real_T)DAL_Sat_HW_v5_B.yn_xp >= DAL_Sat_HW_v5_B.yn_xn) {
      rtb_yn_max = DAL_Sat_HW_v5_B.yn_xp;
    } else {
      rtb_yn_max = DAL_Sat_HW_v5_B.yn_xn;
    }

    /* End of MinMax: '<S19>/Max1' */

    /* If: '<S19>/If' */
    if ((rtb_xp_max < 40U) && (rtb_yn_max > 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/Only Reads in yn' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      DAL_Sat_HW_v5_StandardServoRead(&DAL_Sat_HW_v5_B.StandardServoRead_p,
        &DAL_Sat_HW_v5_DW.StandardServoRead_p,
        &DAL_Sat_HW_v5_P.StandardServoRead_p);

      /* Sum: '<S21>/Sum' incorporates:
       *  Constant: '<S21>/Constant2'
       */
      DAL_Sat_HW_v5_B.Merge_e = (real_T)
        DAL_Sat_HW_v5_B.StandardServoRead_p.Theta_ServoRF -
        DAL_Sat_HW_v5_P.Constant2_Value;

      /* If: '<S21>/If' incorporates:
       *  Constant: '<S21>/Constant'
       *  DataTypeConversion: '<S19>/Data Type Conversion3'
       *  DataTypeConversion: '<S19>/Data Type Conversion4'
       *  Sum: '<S21>/Add'
       */
      if ((real_T)DAL_Sat_HW_v5_B.yn_xp + DAL_Sat_HW_v5_P.Constant_Value_e <
          DAL_Sat_HW_v5_B.yn_xn) {
        /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        /* If: '<S23>/If' */
        if (DAL_Sat_HW_v5_B.Merge_e >= 86.0) {
          /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
           *  ActionPort: '<S25>/Action Port'
           */
          DAL_Sat_HW_v5_IfActionSubsystem(&DAL_Sat_HW_v5_B.Merge_e,
            &DAL_Sat_HW_v5_P.IfActionSubsystem_c);

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
          DAL_Sat_HW_v5_B.Merge_e += DAL_Sat_HW_v5_P.Constant_Value_j;

          /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* Update for If: '<S23>/If' */
          srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_h);

          /* End of Update for SubSystem: '<S23>/If Action Subsystem1' */
        }

        /* End of If: '<S23>/If' */
        /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */

        /* Update for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        /* Update for If: '<S21>/If' */
        srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_a);

        /* End of Update for SubSystem: '<S21>/If Action Subsystem' */
      } else {
        /* Update for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        /* Update for If: '<S21>/If' */
        srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_c);

        /* End of Update for SubSystem: '<S21>/If Action Subsystem1' */
      }

      /* End of If: '<S21>/If' */
      /* Merge: '<S19>/Merge' incorporates:
       *  SignalConversion generated from: '<S21>/Theta_Servo_New'
       */
      DAL_Sat_HW_v5_B.Merge_c = DAL_Sat_HW_v5_B.Merge_e;

      /* End of Outputs for SubSystem: '<S19>/Only Reads in yn' */

      /* Update for IfAction SubSystem: '<S19>/Only Reads in yn' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Update for If: '<S19>/If' */
      srUpdateBC(DAL_Sat_HW_v5_DW.OnlyReadsinyn_SubsysRanBC);

      /* End of Update for SubSystem: '<S19>/Only Reads in yn' */
    }

    /* End of If: '<S19>/If' */

    /* If: '<S19>/If1' */
    if ((rtb_yn_max < 40U) && (rtb_xp_max > 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/Only Reads in yp' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      DAL_Sat_HW_v5_StandardServoRead(&DAL_Sat_HW_v5_B.StandardServoRead_pn,
        &DAL_Sat_HW_v5_DW.StandardServoRead_pn,
        &DAL_Sat_HW_v5_P.StandardServoRead_pn);

      /* Sum: '<S22>/Sum' incorporates:
       *  Constant: '<S22>/Constant2'
       */
      DAL_Sat_HW_v5_B.Merge_o = (real_T)
        DAL_Sat_HW_v5_B.StandardServoRead_pn.Theta_ServoRF -
        DAL_Sat_HW_v5_P.Constant2_Value_h;

      /* If: '<S22>/If' incorporates:
       *  Constant: '<S22>/Constant'
       *  DataTypeConversion: '<S19>/Data Type Conversion1'
       *  DataTypeConversion: '<S19>/Data Type Conversion2'
       *  Sum: '<S22>/Add'
       */
      if ((real_T)DAL_Sat_HW_v5_B.yp_xp + DAL_Sat_HW_v5_P.Constant_Value_b <
          DAL_Sat_HW_v5_B.yp_xn) {
        /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* If: '<S27>/If' */
        if (DAL_Sat_HW_v5_B.Merge_o <= -86.0) {
          /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          DAL_Sat_HW_v5_IfActionSubsystem(&DAL_Sat_HW_v5_B.Merge_o,
            &DAL_Sat_HW_v5_P.IfActionSubsystem_l);

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
          DAL_Sat_HW_v5_B.Merge_o -= DAL_Sat_HW_v5_P.Constant_Value_eg;

          /* End of Outputs for SubSystem: '<S27>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S30>/Action Port'
           */
          /* Update for If: '<S27>/If' */
          srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_j);

          /* End of Update for SubSystem: '<S27>/If Action Subsystem1' */
        }

        /* End of If: '<S27>/If' */
        /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */

        /* Update for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Update for If: '<S22>/If' */
        srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_g);

        /* End of Update for SubSystem: '<S22>/If Action Subsystem' */
      } else {
        /* Update for IfAction SubSystem: '<S22>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Update for If: '<S22>/If' */
        srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanBC);

        /* End of Update for SubSystem: '<S22>/If Action Subsystem1' */
      }

      /* End of If: '<S22>/If' */

      /* Merge: '<S19>/Merge' incorporates:
       *  SignalConversion generated from: '<S22>/Theta_Servo_New'
       */
      DAL_Sat_HW_v5_B.Merge_c = DAL_Sat_HW_v5_B.Merge_o;

      /* End of Outputs for SubSystem: '<S19>/Only Reads in yp' */

      /* Update for IfAction SubSystem: '<S19>/Only Reads in yp' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Update for If: '<S19>/If1' */
      srUpdateBC(DAL_Sat_HW_v5_DW.OnlyReadsinyp_SubsysRanBC);

      /* End of Update for SubSystem: '<S19>/Only Reads in yp' */
    }

    /* End of If: '<S19>/If1' */

    /* If: '<S19>/If2' */
    if ((rtb_yn_max < 40U) && (rtb_xp_max < 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* MATLABSystem: '<S20>/Standard Servo Read' */
      if (DAL_Sat_HW_v5_DW.obj_m5.SampleTime !=
          DAL_Sat_HW_v5_P.StandardServoRead_SampleTime) {
        DAL_Sat_HW_v5_DW.obj_m5.SampleTime =
          DAL_Sat_HW_v5_P.StandardServoRead_SampleTime;
      }

      rtb_StandardServoRead_0 = MW_servoRead(1);

      /* DataTypeConversion: '<S20>/Data Type Conversion' incorporates:
       *  Constant: '<S20>/Constant'
       *  MATLABSystem: '<S20>/Standard Servo Read'
       *  Sum: '<S20>/Sum'
       */
      DAL_Sat_HW_v5_B.DataTypeConversion = (real_T)rtb_StandardServoRead_0 -
        DAL_Sat_HW_v5_P.Constant_Value_o;

      /* Merge: '<S19>/Merge' incorporates:
       *  SignalConversion generated from: '<S20>/Out1'
       */
      DAL_Sat_HW_v5_B.Merge_c = DAL_Sat_HW_v5_B.DataTypeConversion;

      /* SignalConversion generated from: '<S20>/Output' */
      DAL_Sat_HW_v5_B.OutportBufferForOutput =
        DAL_Sat_HW_v5_B.DataTypeConversion;

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Update for If: '<S19>/If2' */
      srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_f);

      /* End of Update for SubSystem: '<S19>/If Action Subsystem' */
    }

    /* End of If: '<S19>/If2' */
    /* Merge: '<S3>/Merge' incorporates:
     *  SignalConversion generated from: '<S19>/Output'
     */
    DAL_Sat_HW_v5_B.Merge_f = DAL_Sat_HW_v5_B.Merge_c;

    /* Update for IfAction SubSystem: '<S3>/Light does not point at xp' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Update for If: '<S3>/If' */
    srUpdateBC(DAL_Sat_HW_v5_DW.Lightdoesnotpointatxp_SubsysRan);

    /* End of Update for SubSystem: '<S3>/Light does not point at xp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S18>/Constant'
     *  SignalConversion generated from: '<S18>/Out1'
     */
    DAL_Sat_HW_v5_B.Merge_f = DAL_Sat_HW_v5_P.Constant_Value_c;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Update for If: '<S3>/If' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S3>/If Action Subsystem' */
  }

  /* End of If: '<S3>/If' */
  /* If: '<S1>/If' */
  if (DAL_Sat_HW_v5_B.Merge_f == 100.0) {
    /* Update for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Update for If: '<S1>/If' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_j);

    /* End of Update for SubSystem: '<S1>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<S6>/Merge1' incorporates:
     *  Inport: '<S5>/Input'
     *  Merge: '<S1>/Merge'
     */
    DAL_Sat_HW_v5_B.Merge_b = DAL_Sat_HW_v5_B.Merge_f;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Update for If: '<S1>/If' */
    srUpdateBC(DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_f);

    /* End of Update for SubSystem: '<S1>/If Action Subsystem1' */
  }

  /* End of If: '<S1>/If' */

  /* MATLABSystem: '<S1>/Continuous Servo Write' */
  if (DAL_Sat_HW_v5_B.Merge_b + 90.0 < 0.0) {
    tmp = 0U;
  } else if (DAL_Sat_HW_v5_B.Merge_b + 90.0 > 180.0) {
    tmp = 180U;
  } else {
    rtb_Abs1 = rt_roundd_snf(DAL_Sat_HW_v5_B.Merge_b + 90.0);
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
  DAL_Sat_HW_v5_StandardServoRead(&DAL_Sat_HW_v5_B.StandardServoRead,
    &DAL_Sat_HW_v5_DW.StandardServoRead, &DAL_Sat_HW_v5_P.StandardServoRead);

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  DAL_Sat_HW_v5_DW.UnitDelay1_DSTATE = (real_T)
    DAL_Sat_HW_v5_B.StandardServoRead.Theta_ServoRF -
    DAL_Sat_HW_v5_P.Constant_Value_lr;

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  DAL_Sat_HW_v5_M->Timing.taskTime0 =
    ((time_T)(++DAL_Sat_HW_v5_M->Timing.clockTick0)) *
    DAL_Sat_HW_v5_M->Timing.stepSize0;
}

/* Model initialize function */
void DAL_Sat_HW_v5_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(DAL_Sat_HW_v5_M, -1);
  DAL_Sat_HW_v5_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  DAL_Sat_HW_v5_M->Sizes.checksums[0] = (1879426260U);
  DAL_Sat_HW_v5_M->Sizes.checksums[1] = (3725654655U);
  DAL_Sat_HW_v5_M->Sizes.checksums[2] = (952199172U);
  DAL_Sat_HW_v5_M->Sizes.checksums[3] = (102872262U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[37];
    DAL_Sat_HW_v5_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_j;
    systemRan[3] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_f;
    systemRan[4] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_m;
    systemRan[5] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanB_a;
    systemRan[6] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_d;
    systemRan[7] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanB_h;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanB_g4;
    systemRan[10] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRan_hd;
    systemRan[11] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem4_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem5_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem6_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem7_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_f;
    systemRan[23] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_f;
    systemRan[24] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_h;
    systemRan[26] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_a;
    systemRan[27] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_c;
    systemRan[28] = (sysRanDType *)&DAL_Sat_HW_v5_DW.OnlyReadsinyn_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&DAL_Sat_HW_v5_DW.OnlyReadsinyn_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_l.IfActionSubsystem_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanB_j;
    systemRan[32] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem_SubsysRanBC_g;
    systemRan[33] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[34] = (sysRanDType *)&DAL_Sat_HW_v5_DW.OnlyReadsinyp_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&DAL_Sat_HW_v5_DW.OnlyReadsinyp_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &DAL_Sat_HW_v5_DW.Lightdoesnotpointatxp_SubsysRan;
    rteiSetModelMappingInfoPtr(DAL_Sat_HW_v5_M->extModeInfo,
      &DAL_Sat_HW_v5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DAL_Sat_HW_v5_M->extModeInfo,
                        DAL_Sat_HW_v5_M->Sizes.checksums);
    rteiSetTPtr(DAL_Sat_HW_v5_M->extModeInfo, rtmGetTPtr(DAL_Sat_HW_v5_M));
  }

  {
    codertarget_arduinobase_in_cg_T *obj;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
    DAL_Sat_HW_v5_DW.UnitDelay1_DSTATE =
      DAL_Sat_HW_v5_P.UnitDelay1_InitialCondition;

    /* SystemInitialize for Sum: '<S21>/Sum' incorporates:
     *  Merge: '<S21>/Merge'
     */
    DAL_Sat_HW_v5_B.Merge_e = DAL_Sat_HW_v5_P.Merge_InitialOutput;
    DAL_Sat__StandardServoRead_Init(&DAL_Sat_HW_v5_DW.StandardServoRead_p,
      &DAL_Sat_HW_v5_P.StandardServoRead_p);

    /* End of SystemInitialize for SubSystem: '<S19>/Only Reads in yn' */

    /* SystemInitialize for IfAction SubSystem: '<S19>/Only Reads in yp' */
    /* SystemInitialize for Sum: '<S22>/Sum' incorporates:
     *  Merge: '<S22>/Merge'
     */
    DAL_Sat_HW_v5_B.Merge_o = DAL_Sat_HW_v5_P.Merge_InitialOutput_k;
    DAL_Sat__StandardServoRead_Init(&DAL_Sat_HW_v5_DW.StandardServoRead_pn,
      &DAL_Sat_HW_v5_P.StandardServoRead_pn);

    /* End of SystemInitialize for SubSystem: '<S19>/Only Reads in yp' */

    /* SystemInitialize for IfAction SubSystem: '<S19>/If Action Subsystem' */
    /* Start for MATLABSystem: '<S20>/Standard Servo Read' */
    DAL_Sat_HW_v5_DW.obj_m5.SampleTime =
      DAL_Sat_HW_v5_P.StandardServoRead_SampleTime;
    DAL_Sat_HW_v5_DW.obj_m5.isInitialized = 1L;
    MW_servoAttach(1, 2);

    /* SystemInitialize for SignalConversion generated from: '<S20>/Output' incorporates:
     *  Outport: '<S20>/Output'
     */
    DAL_Sat_HW_v5_B.OutportBufferForOutput = DAL_Sat_HW_v5_P.Output_Y0;

    /* End of SystemInitialize for SubSystem: '<S19>/If Action Subsystem' */

    /* SystemInitialize for Merge: '<S19>/Merge' */
    DAL_Sat_HW_v5_B.Merge_c = DAL_Sat_HW_v5_P.Merge_InitialOutput_k2;

    /* End of SystemInitialize for SubSystem: '<S3>/Light does not point at xp' */

    /* Start for MATLABSystem: '<S3>/Analog Input12' */
    DAL_Sat_HW_v5_DW.obj_e.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v5_DW.obj_e.isInitialized = 0L;
    DAL_Sat_HW_v5_DW.obj_e.SampleTime = -1.0;
    DAL_Sat_HW_v5_DW.obj_e.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v5_DW.obj_e.SampleTime = DAL_Sat_HW_v5_P.AnalogInput12_SampleTime;
    obj = &DAL_Sat_HW_v5_DW.obj_e;
    DAL_Sat_HW_v5_DW.obj_e.isSetupComplete = false;
    DAL_Sat_HW_v5_DW.obj_e.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16UL);
    DAL_Sat_HW_v5_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input14' */
    DAL_Sat_HW_v5_DW.obj_h.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v5_DW.obj_h.isInitialized = 0L;
    DAL_Sat_HW_v5_DW.obj_h.SampleTime = -1.0;
    DAL_Sat_HW_v5_DW.obj_h.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v5_DW.obj_h.SampleTime = DAL_Sat_HW_v5_P.AnalogInput14_SampleTime;
    obj = &DAL_Sat_HW_v5_DW.obj_h;
    DAL_Sat_HW_v5_DW.obj_h.isSetupComplete = false;
    DAL_Sat_HW_v5_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17UL);
    DAL_Sat_HW_v5_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input13' */
    DAL_Sat_HW_v5_DW.obj_a.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v5_DW.obj_a.isInitialized = 0L;
    DAL_Sat_HW_v5_DW.obj_a.SampleTime = -1.0;
    DAL_Sat_HW_v5_DW.obj_a.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v5_DW.obj_a.SampleTime = DAL_Sat_HW_v5_P.AnalogInput13_SampleTime;
    obj = &DAL_Sat_HW_v5_DW.obj_a;
    DAL_Sat_HW_v5_DW.obj_a.isSetupComplete = false;
    DAL_Sat_HW_v5_DW.obj_a.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    DAL_Sat_HW_v5_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input16' */
    DAL_Sat_HW_v5_DW.obj_k.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v5_DW.obj_k.isInitialized = 0L;
    DAL_Sat_HW_v5_DW.obj_k.SampleTime = -1.0;
    DAL_Sat_HW_v5_DW.obj_k.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v5_DW.obj_k.SampleTime = DAL_Sat_HW_v5_P.AnalogInput16_SampleTime;
    obj = &DAL_Sat_HW_v5_DW.obj_k;
    DAL_Sat_HW_v5_DW.obj_k.isSetupComplete = false;
    DAL_Sat_HW_v5_DW.obj_k.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    DAL_Sat_HW_v5_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input15' */
    DAL_Sat_HW_v5_DW.obj_m.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v5_DW.obj_m.isInitialized = 0L;
    DAL_Sat_HW_v5_DW.obj_m.SampleTime = -1.0;
    DAL_Sat_HW_v5_DW.obj_m.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v5_DW.obj_m.SampleTime = DAL_Sat_HW_v5_P.AnalogInput15_SampleTime;
    obj = &DAL_Sat_HW_v5_DW.obj_m;
    DAL_Sat_HW_v5_DW.obj_m.isSetupComplete = false;
    DAL_Sat_HW_v5_DW.obj_m.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    DAL_Sat_HW_v5_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input17' */
    DAL_Sat_HW_v5_DW.obj.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v5_DW.obj.isInitialized = 0L;
    DAL_Sat_HW_v5_DW.obj.SampleTime = -1.0;
    DAL_Sat_HW_v5_DW.obj.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v5_DW.obj.SampleTime = DAL_Sat_HW_v5_P.AnalogInput17_SampleTime;
    obj = &DAL_Sat_HW_v5_DW.obj;
    DAL_Sat_HW_v5_DW.obj.isSetupComplete = false;
    DAL_Sat_HW_v5_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19UL);
    DAL_Sat_HW_v5_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Continuous Servo Write' */
    MW_servoAttach(0, 9);
    DAL_Sat__StandardServoRead_Init(&DAL_Sat_HW_v5_DW.StandardServoRead,
      &DAL_Sat_HW_v5_P.StandardServoRead);
  }
}

/* Model terminate function */
void DAL_Sat_HW_v5_terminate(void)
{
  codertarget_arduinobase_in_cg_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Analog Input12' */
  obj = &DAL_Sat_HW_v5_DW.obj_e;
  if (!DAL_Sat_HW_v5_DW.obj_e.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v5_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v5_DW.obj_e.isInitialized == 1L) &&
        DAL_Sat_HW_v5_DW.obj_e.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v5_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input12' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input14' */
  obj = &DAL_Sat_HW_v5_DW.obj_h;
  if (!DAL_Sat_HW_v5_DW.obj_h.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v5_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v5_DW.obj_h.isInitialized == 1L) &&
        DAL_Sat_HW_v5_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v5_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input14' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input13' */
  obj = &DAL_Sat_HW_v5_DW.obj_a;
  if (!DAL_Sat_HW_v5_DW.obj_a.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v5_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v5_DW.obj_a.isInitialized == 1L) &&
        DAL_Sat_HW_v5_DW.obj_a.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v5_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input13' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input16' */
  obj = &DAL_Sat_HW_v5_DW.obj_k;
  if (!DAL_Sat_HW_v5_DW.obj_k.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v5_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v5_DW.obj_k.isInitialized == 1L) &&
        DAL_Sat_HW_v5_DW.obj_k.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v5_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input16' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input15' */
  obj = &DAL_Sat_HW_v5_DW.obj_m;
  if (!DAL_Sat_HW_v5_DW.obj_m.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v5_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v5_DW.obj_m.isInitialized == 1L) &&
        DAL_Sat_HW_v5_DW.obj_m.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v5_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input15' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input17' */
  obj = &DAL_Sat_HW_v5_DW.obj;
  if (!DAL_Sat_HW_v5_DW.obj.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v5_DW.obj.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v5_DW.obj.isInitialized == 1L) &&
        DAL_Sat_HW_v5_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v5_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input17' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
