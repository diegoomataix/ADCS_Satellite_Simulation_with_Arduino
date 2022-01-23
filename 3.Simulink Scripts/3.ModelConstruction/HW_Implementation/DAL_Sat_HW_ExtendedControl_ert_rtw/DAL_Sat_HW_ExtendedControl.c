/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DAL_Sat_HW_ExtendedControl.c
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

#include "DAL_Sat_HW_ExtendedControl.h"
#include "DAL_Sat_HW_ExtendedControl_private.h"

/* Block signals (default storage) */
B_DAL_Sat_HW_ExtendedControl_T DAL_Sat_HW_ExtendedControl_B;

/* Block states (default storage) */
DW_DAL_Sat_HW_ExtendedControl_T DAL_Sat_HW_ExtendedControl_DW;

/* Real-time model */
static RT_MODEL_DAL_Sat_HW_ExtendedC_T DAL_Sat_HW_ExtendedControl_M_;
RT_MODEL_DAL_Sat_HW_ExtendedC_T *const DAL_Sat_HW_ExtendedControl_M =
  &DAL_Sat_HW_ExtendedControl_M_;

/* System initialize for atomic system: */
void DAL_Sat__StandardServoRead_Init(DW_StandardServoRead_DAL_Sat__T *localDW,
  P_StandardServoRead_DAL_Sat_H_T *localP)
{
  /* Start for MATLABSystem: '<S7>/Standard Servo Read' */
  localDW->objisempty = true;
  localDW->obj.SampleTime = localP->StandardServoRead_SampleTime;
  localDW->obj.isInitialized = 1L;
  MW_servoAttach(0, 9);
}

/* Output and update for atomic system: */
void DAL_Sat_HW_Ex_StandardServoRead(B_StandardServoRead_DAL_Sat_H_T *localB,
  DW_StandardServoRead_DAL_Sat__T *localDW, P_StandardServoRead_DAL_Sat_H_T
  *localP)
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
 *    '<S16>/If Action Subsystem'
 *    '<S22>/If Action Subsystem'
 */
void DAL_Sat_HW_Ex_IfActionSubsystem(real_T *rty_Theta_Servo_New,
  P_IfActionSubsystem_DAL_Sat_H_T *localP)
{
  /* SignalConversion generated from: '<S18>/Theta_Servo_New' incorporates:
   *  Constant: '<S18>/Constant'
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
void DAL_Sat_HW_ExtendedControl_step(void)
{
  codertarget_arduinobase_in_lx_T *obj;
  real_T rtb_DataTypeConversion2_idx_0;
  real_T rtb_DataTypeConversion2_idx_1;
  real_T rtb_DataTypeConversion2_idx_2;
  real_T rtb_Gain1;
  uint16_T rtb_xp_max;
  uint16_T rtb_xp_yp_0;
  uint16_T rtb_yn_max;
  uint16_T rtb_yn_xn_0;
  uint16_T rtb_yn_xp_0;
  uint16_T rtb_yp_xn_0;
  uint8_T rtb_Merge_h_0;

  /* MATLABSystem: '<S4>/Analog Input12' */
  if (DAL_Sat_HW_ExtendedControl_DW.obj_h.SampleTime !=
      DAL_Sat_HW_ExtendedControl_P.AnalogInput12_SampleTime) {
    DAL_Sat_HW_ExtendedControl_DW.obj_h.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput12_SampleTime;
  }

  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_ExtendedControl_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_xp_yp_0, 3);

  /* MATLABSystem: '<S4>/Analog Input14' */
  if (DAL_Sat_HW_ExtendedControl_DW.obj_c4.SampleTime !=
      DAL_Sat_HW_ExtendedControl_P.AnalogInput14_SampleTime) {
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput14_SampleTime;
  }

  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_c4;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_ExtendedControl_DW.obj_c4.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_xp_max, 3);

  /* MinMax: '<S4>/Max' incorporates:
   *  MATLABSystem: '<S4>/Analog Input12'
   *  MATLABSystem: '<S4>/Analog Input14'
   */
  if (rtb_xp_yp_0 >= rtb_xp_max) {
    rtb_xp_max = rtb_xp_yp_0;
  }

  /* End of MinMax: '<S4>/Max' */

  /* MATLABSystem: '<S4>/Analog Input13' */
  if (DAL_Sat_HW_ExtendedControl_DW.obj_l.SampleTime !=
      DAL_Sat_HW_ExtendedControl_P.AnalogInput13_SampleTime) {
    DAL_Sat_HW_ExtendedControl_DW.obj_l.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput13_SampleTime;
  }

  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_l;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_ExtendedControl_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_xp_yp_0, 3);

  /* MATLABSystem: '<S4>/Analog Input16' */
  if (DAL_Sat_HW_ExtendedControl_DW.obj_i.SampleTime !=
      DAL_Sat_HW_ExtendedControl_P.AnalogInput16_SampleTime) {
    DAL_Sat_HW_ExtendedControl_DW.obj_i.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput16_SampleTime;
  }

  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_i;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_ExtendedControl_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_yp_xn_0, 3);

  /* MATLABSystem: '<S4>/Analog Input15' */
  if (DAL_Sat_HW_ExtendedControl_DW.obj_c.SampleTime !=
      DAL_Sat_HW_ExtendedControl_P.AnalogInput15_SampleTime) {
    DAL_Sat_HW_ExtendedControl_DW.obj_c.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput15_SampleTime;
  }

  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_c;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_ExtendedControl_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_yn_xp_0, 3);

  /* MATLABSystem: '<S4>/Analog Input17' */
  if (DAL_Sat_HW_ExtendedControl_DW.obj.SampleTime !=
      DAL_Sat_HW_ExtendedControl_P.AnalogInput17_SampleTime) {
    DAL_Sat_HW_ExtendedControl_DW.obj.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput17_SampleTime;
  }

  obj = &DAL_Sat_HW_ExtendedControl_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_ExtendedControl_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_yn_xn_0, 3);

  /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
   *  Gain: '<S4>/Gain5'
   *  SignalConversion generated from: '<S4>/Gain5'
   */
  rtb_DataTypeConversion2_idx_0 = (real_T)((uint32_T)
    DAL_Sat_HW_ExtendedControl_P.Gain5_Gain * rtb_xp_max) *
    1.1920928955078125E-7;

  /* MinMax: '<S4>/Max1' incorporates:
   *  MATLABSystem: '<S4>/Analog Input13'
   *  MATLABSystem: '<S4>/Analog Input16'
   */
  if (rtb_xp_yp_0 >= rtb_yp_xn_0) {
    rtb_yn_max = rtb_xp_yp_0;
  } else {
    rtb_yn_max = rtb_yp_xn_0;
  }

  /* End of MinMax: '<S4>/Max1' */

  /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
   *  Gain: '<S4>/Gain5'
   */
  rtb_DataTypeConversion2_idx_1 = (real_T)((uint32_T)
    DAL_Sat_HW_ExtendedControl_P.Gain5_Gain * rtb_yn_max) *
    1.1920928955078125E-7;

  /* MinMax: '<S4>/Max2' incorporates:
   *  MATLABSystem: '<S4>/Analog Input15'
   *  MATLABSystem: '<S4>/Analog Input17'
   */
  if (rtb_yn_xp_0 >= rtb_yn_xn_0) {
    rtb_yn_max = rtb_yn_xp_0;
  } else {
    rtb_yn_max = rtb_yn_xn_0;
  }

  /* End of MinMax: '<S4>/Max2' */

  /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
   *  Gain: '<S4>/Gain5'
   */
  rtb_DataTypeConversion2_idx_2 = (real_T)((uint32_T)
    DAL_Sat_HW_ExtendedControl_P.Gain5_Gain * rtb_yn_max) *
    1.1920928955078125E-7;

  /* Sqrt: '<S3>/Sqrt1' incorporates:
   *  Math: '<S3>/Math Function1'
   *  Sum: '<S3>/Sum of Elements1'
   *
   * About '<S3>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Gain1 = sqrt((rtb_DataTypeConversion2_idx_0 *
                    rtb_DataTypeConversion2_idx_0 +
                    rtb_DataTypeConversion2_idx_1 *
                    rtb_DataTypeConversion2_idx_1) +
                   rtb_DataTypeConversion2_idx_2 * rtb_DataTypeConversion2_idx_2);

  /* If: '<S29>/If2' incorporates:
   *  Constant: '<S29>/Constant2'
   */
  if (rtb_DataTypeConversion2_idx_1 <= 0.19550342130987292) {
    rtb_DataTypeConversion2_idx_1 =
      DAL_Sat_HW_ExtendedControl_P.Constant2_Value_g;
  }

  /* End of If: '<S29>/If2' */

  /* If: '<S29>/If3' incorporates:
   *  Constant: '<S29>/Constant3'
   */
  if (rtb_DataTypeConversion2_idx_2 <= 0.19550342130987292) {
    rtb_DataTypeConversion2_idx_2 = DAL_Sat_HW_ExtendedControl_P.Constant3_Value;
  }

  /* End of If: '<S29>/If3' */

  /* If: '<S29>/If' incorporates:
   *  Constant: '<S29>/Constant'
   */
  if (rtb_DataTypeConversion2_idx_0 <= 0.19550342130987292) {
    rtb_DataTypeConversion2_idx_0 =
      DAL_Sat_HW_ExtendedControl_P.Constant_Value_e;
  }

  /* End of If: '<S29>/If' */

  /* Gain: '<S3>/Gain1' incorporates:
   *  Product: '<S3>/Divide1'
   *  Sum: '<S3>/Add1'
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  rtb_Gain1 = rt_atan2d_snf((rtb_DataTypeConversion2_idx_1 -
    rtb_DataTypeConversion2_idx_2) / rtb_Gain1, rtb_DataTypeConversion2_idx_0 /
    rtb_Gain1) * DAL_Sat_HW_ExtendedControl_P.Gain1_Gain;

  /* DataTypeConversion: '<S28>/Data Type Conversion1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Rounding: '<S28>/Round'
   *  Sum: '<S28>/Sum'
   */
  rtb_DataTypeConversion2_idx_0 = rt_roundd_snf(rtb_Gain1 +
    DAL_Sat_HW_ExtendedControl_P.Constant_Value_m0);
  if (rtIsNaN(rtb_DataTypeConversion2_idx_0) || rtIsInf
      (rtb_DataTypeConversion2_idx_0)) {
    rtb_DataTypeConversion2_idx_0 = 0.0;
  } else {
    rtb_DataTypeConversion2_idx_0 = fmod(rtb_DataTypeConversion2_idx_0, 65536.0);
  }

  /* DataTypeConversion: '<S28>/Data Type Conversion1' */
  DAL_Sat_HW_ExtendedControl_B.DataTypeConversion1 =
    rtb_DataTypeConversion2_idx_0 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)
    -rtb_DataTypeConversion2_idx_0 : (uint16_T)rtb_DataTypeConversion2_idx_0;

  /* S-Function (LCDControlSF): '<S28>/S-Function Builder1' */
  LCDControlSF_Outputs_wrapper_cgen
    (&DAL_Sat_HW_ExtendedControl_B.DataTypeConversion1,
     &DAL_Sat_HW_ExtendedControl_DW.SFunctionBuilder1_DSTATE);
  DAL_Sat_HW_Ex_StandardServoRead
    (&DAL_Sat_HW_ExtendedControl_B.StandardServoRead,
     &DAL_Sat_HW_ExtendedControl_DW.StandardServoRead,
     &DAL_Sat_HW_ExtendedControl_P.StandardServoRead);

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  Sum: '<S1>/Sum1'
   */
  rtb_Gain1 += (real_T)
    DAL_Sat_HW_ExtendedControl_B.StandardServoRead.StandardServoRead -
    DAL_Sat_HW_ExtendedControl_P.Constant_Value_d;

  /* If: '<S2>/If' */
  if (rtb_xp_max < 40U) {
    /* Outputs for IfAction SubSystem: '<S2>/Light does not point at xp' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* MinMax: '<S12>/Max' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion1'
     *  DataTypeConversion: '<S12>/Data Type Conversion2'
     *  MATLABSystem: '<S4>/Analog Input13'
     *  MATLABSystem: '<S4>/Analog Input16'
     */
    if ((real_T)rtb_xp_yp_0 >= rtb_yp_xn_0) {
      rtb_xp_max = rtb_xp_yp_0;
    } else {
      rtb_xp_max = rtb_yp_xn_0;
    }

    /* End of MinMax: '<S12>/Max' */

    /* MinMax: '<S12>/Max1' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion3'
     *  DataTypeConversion: '<S12>/Data Type Conversion4'
     *  MATLABSystem: '<S4>/Analog Input15'
     *  MATLABSystem: '<S4>/Analog Input17'
     */
    if ((real_T)rtb_yn_xp_0 >= rtb_yn_xn_0) {
      rtb_yn_max = rtb_yn_xp_0;
    } else {
      rtb_yn_max = rtb_yn_xn_0;
    }

    /* End of MinMax: '<S12>/Max1' */

    /* If: '<S12>/If' */
    if ((rtb_xp_max < 40U) && (rtb_yn_max > 40U)) {
      /* Outputs for IfAction SubSystem: '<S12>/Only Reads in yn' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      DAL_Sat_HW_Ex_StandardServoRead
        (&DAL_Sat_HW_ExtendedControl_B.StandardServoRead_pn,
         &DAL_Sat_HW_ExtendedControl_DW.StandardServoRead_pn,
         &DAL_Sat_HW_ExtendedControl_P.StandardServoRead_pn);

      /* Sum: '<S14>/Sum' incorporates:
       *  Constant: '<S14>/Constant2'
       */
      rtb_DataTypeConversion2_idx_0 = (real_T)
        DAL_Sat_HW_ExtendedControl_B.StandardServoRead_pn.StandardServoRead -
        DAL_Sat_HW_ExtendedControl_P.Constant2_Value;

      /* If: '<S14>/If' incorporates:
       *  Constant: '<S14>/Constant'
       *  DataTypeConversion: '<S12>/Data Type Conversion3'
       *  DataTypeConversion: '<S12>/Data Type Conversion4'
       *  If: '<S17>/If'
       *  MATLABSystem: '<S4>/Analog Input15'
       *  MATLABSystem: '<S4>/Analog Input17'
       *  Sum: '<S14>/Add'
       */
      if ((real_T)rtb_yn_xp_0 + DAL_Sat_HW_ExtendedControl_P.Constant_Value_nv <
          rtb_yn_xn_0) {
        /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
         *  ActionPort: '<S16>/Action Port'
         */
        /* If: '<S16>/If' */
        if (rtb_DataTypeConversion2_idx_0 >= 86.0) {
          /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem' incorporates:
           *  ActionPort: '<S18>/Action Port'
           */
          /* Merge: '<S12>/Merge' */
          DAL_Sat_HW_Ex_IfActionSubsystem(&DAL_Sat_HW_ExtendedControl_B.Merge,
            &DAL_Sat_HW_ExtendedControl_P.IfActionSubsystem_p);

          /* End of Outputs for SubSystem: '<S16>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S19>/Action Port'
           */
          /* Merge: '<S12>/Merge' incorporates:
           *  Constant: '<S19>/Constant'
           *  Merge: '<S14>/Merge'
           *  Sum: '<S19>/Add'
           */
          DAL_Sat_HW_ExtendedControl_B.Merge = rtb_DataTypeConversion2_idx_0 +
            DAL_Sat_HW_ExtendedControl_P.Constant_Value_n;

          /* End of Outputs for SubSystem: '<S16>/If Action Subsystem1' */
        }

        /* End of If: '<S16>/If' */
        /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */

        /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S17>/Action Port'
         */
      } else if ((rtb_DataTypeConversion2_idx_0 < 5.0) &&
                 (rtb_DataTypeConversion2_idx_0 > -5.0)) {
        /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
         *  ActionPort: '<S20>/Action Port'
         */
        /* If: '<S17>/If' incorporates:
         *  Constant: '<S17>/Nominal Control Condition'
         *  Inport: '<S20>/Nominal Control Condition_IN'
         *  Merge: '<S12>/Merge'
         *  Merge: '<S14>/Merge'
         */
        DAL_Sat_HW_ExtendedControl_B.Merge =
          DAL_Sat_HW_ExtendedControl_P.NominalControlCondition_Value;

        /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S21>/Action Port'
         */
        /* If: '<S17>/If' incorporates:
         *  Constant: '<S17>/Constant1'
         *  Inport: '<S21>/Theta_ServoRF'
         *  Merge: '<S12>/Merge'
         *  Merge: '<S14>/Merge'
         *  Sum: '<S17>/Sum'
         */
        DAL_Sat_HW_ExtendedControl_B.Merge = rtb_DataTypeConversion2_idx_0 +
          DAL_Sat_HW_ExtendedControl_P.Constant1_Value;

        /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */

        /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
      }

      /* End of If: '<S14>/If' */
      /* End of Outputs for SubSystem: '<S12>/Only Reads in yn' */
    }

    /* End of If: '<S12>/If' */

    /* If: '<S12>/If1' */
    if ((rtb_yn_max < 40U) && (rtb_xp_max > 40U)) {
      /* Outputs for IfAction SubSystem: '<S12>/Only Reads in yp' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      DAL_Sat_HW_Ex_StandardServoRead
        (&DAL_Sat_HW_ExtendedControl_B.StandardServoRead_pna,
         &DAL_Sat_HW_ExtendedControl_DW.StandardServoRead_pna,
         &DAL_Sat_HW_ExtendedControl_P.StandardServoRead_pna);

      /* Sum: '<S15>/Sum' incorporates:
       *  Constant: '<S15>/Constant2'
       */
      rtb_DataTypeConversion2_idx_0 = (real_T)
        DAL_Sat_HW_ExtendedControl_B.StandardServoRead_pna.StandardServoRead -
        DAL_Sat_HW_ExtendedControl_P.Constant2_Value_a;

      /* If: '<S15>/If' incorporates:
       *  Constant: '<S15>/Constant'
       *  DataTypeConversion: '<S12>/Data Type Conversion1'
       *  DataTypeConversion: '<S12>/Data Type Conversion2'
       *  If: '<S23>/If'
       *  MATLABSystem: '<S4>/Analog Input13'
       *  MATLABSystem: '<S4>/Analog Input16'
       *  Sum: '<S15>/Add'
       */
      if ((real_T)rtb_xp_yp_0 + DAL_Sat_HW_ExtendedControl_P.Constant_Value_mh <
          rtb_yp_xn_0) {
        /* Outputs for IfAction SubSystem: '<S15>/If Action Subsystem' incorporates:
         *  ActionPort: '<S22>/Action Port'
         */
        /* If: '<S22>/If' */
        if (rtb_DataTypeConversion2_idx_0 <= -86.0) {
          /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
           *  ActionPort: '<S24>/Action Port'
           */
          /* Merge: '<S12>/Merge' */
          DAL_Sat_HW_Ex_IfActionSubsystem(&DAL_Sat_HW_ExtendedControl_B.Merge,
            &DAL_Sat_HW_ExtendedControl_P.IfActionSubsystem_h);

          /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S25>/Action Port'
           */
          /* Merge: '<S12>/Merge' incorporates:
           *  Constant: '<S25>/Constant'
           *  Merge: '<S15>/Merge'
           *  Sum: '<S25>/Add'
           */
          DAL_Sat_HW_ExtendedControl_B.Merge = rtb_DataTypeConversion2_idx_0 -
            DAL_Sat_HW_ExtendedControl_P.Constant_Value_m1;

          /* End of Outputs for SubSystem: '<S22>/If Action Subsystem1' */
        }

        /* End of If: '<S22>/If' */
        /* End of Outputs for SubSystem: '<S15>/If Action Subsystem' */

        /* Outputs for IfAction SubSystem: '<S15>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
      } else if ((rtb_DataTypeConversion2_idx_0 < 5.0) &&
                 (rtb_DataTypeConversion2_idx_0 > -5.0)) {
        /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* If: '<S23>/If' incorporates:
         *  Constant: '<S23>/Nominal Control Condition'
         *  Inport: '<S26>/Nominal Control Condition_In'
         *  Merge: '<S12>/Merge'
         *  Merge: '<S15>/Merge'
         */
        DAL_Sat_HW_ExtendedControl_B.Merge =
          DAL_Sat_HW_ExtendedControl_P.NominalControlCondition_Value_g;

        /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* If: '<S23>/If' incorporates:
         *  Constant: '<S23>/Constant1'
         *  Inport: '<S27>/Theta_ServoRF'
         *  Merge: '<S12>/Merge'
         *  Merge: '<S15>/Merge'
         *  Sum: '<S23>/Sum'
         */
        DAL_Sat_HW_ExtendedControl_B.Merge = rtb_DataTypeConversion2_idx_0 -
          DAL_Sat_HW_ExtendedControl_P.Constant1_Value_f;

        /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */

        /* End of Outputs for SubSystem: '<S15>/If Action Subsystem1' */
      }

      /* End of If: '<S15>/If' */
      /* End of Outputs for SubSystem: '<S12>/Only Reads in yp' */
    }

    /* End of If: '<S12>/If1' */

    /* If: '<S12>/If2' */
    if ((rtb_yn_max < 40U) && (rtb_xp_max < 40U)) {
      /* Outputs for IfAction SubSystem: '<S12>/Only Reads in xn' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      DAL_Sat_HW_Ex_StandardServoRead
        (&DAL_Sat_HW_ExtendedControl_B.StandardServoRead_pnae,
         &DAL_Sat_HW_ExtendedControl_DW.StandardServoRead_pnae,
         &DAL_Sat_HW_ExtendedControl_P.StandardServoRead_pnae);

      /* Merge: '<S12>/Merge' incorporates:
       *  Constant: '<S13>/Constant'
       *  SignalConversion generated from: '<S13>/Theta_Servo_New'
       *  Sum: '<S13>/Sum'
       */
      DAL_Sat_HW_ExtendedControl_B.Merge = (real_T)
        DAL_Sat_HW_ExtendedControl_B.StandardServoRead_pnae.StandardServoRead -
        DAL_Sat_HW_ExtendedControl_P.Constant_Value_mx;

      /* End of Outputs for SubSystem: '<S12>/Only Reads in xn' */
    }

    /* End of If: '<S12>/If2' */

    /* SignalConversion generated from: '<S12>/Theta_Servo_New' */
    rtb_DataTypeConversion2_idx_0 = DAL_Sat_HW_ExtendedControl_B.Merge;

    /* End of Outputs for SubSystem: '<S2>/Light does not point at xp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* SignalConversion generated from: '<S11>/Out1' incorporates:
     *  Constant: '<S11>/Nominal Control Condition'
     */
    rtb_DataTypeConversion2_idx_0 =
      DAL_Sat_HW_ExtendedControl_P.NominalControlCondition_Value_p;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  }

  /* End of If: '<S2>/If' */

  /* If: '<S1>/If' */
  if (rtb_DataTypeConversion2_idx_0 == 100.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* If: '<S5>/If' incorporates:
     *  Abs: '<S5>/Abs1'
     *  Inport: '<S8>/Theta_BeamRF'
     */
    if (fabs(rtb_Gain1) > 90.0) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      DAL_Sat_HW_Ex_StandardServoRead
        (&DAL_Sat_HW_ExtendedControl_B.StandardServoRead_p,
         &DAL_Sat_HW_ExtendedControl_DW.StandardServoRead_p,
         &DAL_Sat_HW_ExtendedControl_P.StandardServoRead_p);

      /* If: '<S7>/If' */
      if (rtb_Gain1 > 0.0) {
        /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S9>/Action Port'
         */
        /* Sum: '<S9>/Subtract' incorporates:
         *  Constant: '<S7>/Constant'
         *  Constant: '<S9>/Constant'
         *  Sum: '<S7>/Sum'
         */
        rtb_DataTypeConversion2_idx_0 = ((real_T)
          DAL_Sat_HW_ExtendedControl_B.StandardServoRead_p.StandardServoRead -
          DAL_Sat_HW_ExtendedControl_P.Constant_Value_m) -
          DAL_Sat_HW_ExtendedControl_P.Constant_Value;

        /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem4' incorporates:
         *  ActionPort: '<S10>/Action Port'
         */
        /* Sum: '<S10>/Subtract' incorporates:
         *  Constant: '<S10>/Constant'
         *  Constant: '<S7>/Constant'
         *  Sum: '<S7>/Sum'
         */
        rtb_DataTypeConversion2_idx_0 = ((real_T)
          DAL_Sat_HW_ExtendedControl_B.StandardServoRead_p.StandardServoRead -
          DAL_Sat_HW_ExtendedControl_P.Constant_Value_m) +
          DAL_Sat_HW_ExtendedControl_P.Constant_Value_a;

        /* End of Outputs for SubSystem: '<S7>/If Action Subsystem4' */
      }

      /* End of If: '<S7>/If' */
      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      rtb_DataTypeConversion2_idx_0 = rtb_Gain1;

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem4' */
    }

    /* End of If: '<S5>/If' */
    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
  }

  /* End of If: '<S1>/If' */

  /* MATLABSystem: '<S1>/Continuous Servo Write' */
  if (rtb_DataTypeConversion2_idx_0 + 90.0 < 0.0) {
    rtb_Merge_h_0 = 0U;
  } else if (rtb_DataTypeConversion2_idx_0 + 90.0 > 180.0) {
    rtb_Merge_h_0 = 180U;
  } else {
    rtb_DataTypeConversion2_idx_0 = rt_roundd_snf(rtb_DataTypeConversion2_idx_0
      + 90.0);
    if (rtb_DataTypeConversion2_idx_0 < 256.0) {
      if (rtb_DataTypeConversion2_idx_0 >= 0.0) {
        rtb_Merge_h_0 = (uint8_T)rtb_DataTypeConversion2_idx_0;
      } else {
        rtb_Merge_h_0 = 0U;
      }
    } else {
      rtb_Merge_h_0 = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, rtb_Merge_h_0);

  /* End of MATLABSystem: '<S1>/Continuous Servo Write' */

  /* Update for S-Function (LCDControlSF): '<S28>/S-Function Builder1' */

  /* S-Function "LCDControlSF_wrapper" Block: <S28>/S-Function Builder1 */
  LCDControlSF_Update_wrapper_cgen
    (&DAL_Sat_HW_ExtendedControl_B.DataTypeConversion1,
     &DAL_Sat_HW_ExtendedControl_DW.SFunctionBuilder1_DSTATE);
}

/* Model initialize function */
void DAL_Sat_HW_ExtendedControl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_in_lx_T *obj;

    /* InitializeConditions for S-Function (LCDControlSF): '<S28>/S-Function Builder1' */

    /* S-Function Block: <S28>/S-Function Builder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          DAL_Sat_HW_ExtendedControl_DW.SFunctionBuilder1_DSTATE = initVector[0];
        }
      }
    }

    /* SystemInitialize for IfAction SubSystem: '<S2>/Light does not point at xp' */
    /* SystemInitialize for IfAction SubSystem: '<S12>/Only Reads in yn' */
    DAL_Sat__StandardServoRead_Init
      (&DAL_Sat_HW_ExtendedControl_DW.StandardServoRead_pn,
       &DAL_Sat_HW_ExtendedControl_P.StandardServoRead_pn);

    /* End of SystemInitialize for SubSystem: '<S12>/Only Reads in yn' */

    /* SystemInitialize for IfAction SubSystem: '<S12>/Only Reads in yp' */
    DAL_Sat__StandardServoRead_Init
      (&DAL_Sat_HW_ExtendedControl_DW.StandardServoRead_pna,
       &DAL_Sat_HW_ExtendedControl_P.StandardServoRead_pna);

    /* End of SystemInitialize for SubSystem: '<S12>/Only Reads in yp' */

    /* SystemInitialize for IfAction SubSystem: '<S12>/Only Reads in xn' */
    DAL_Sat__StandardServoRead_Init
      (&DAL_Sat_HW_ExtendedControl_DW.StandardServoRead_pnae,
       &DAL_Sat_HW_ExtendedControl_P.StandardServoRead_pnae);

    /* End of SystemInitialize for SubSystem: '<S12>/Only Reads in xn' */

    /* SystemInitialize for Merge: '<S12>/Merge' */
    DAL_Sat_HW_ExtendedControl_B.Merge =
      DAL_Sat_HW_ExtendedControl_P.Merge_InitialOutput_g;

    /* End of SystemInitialize for SubSystem: '<S2>/Light does not point at xp' */

    /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem' */
    /* SystemInitialize for IfAction SubSystem: '<S5>/If Action Subsystem1' */
    DAL_Sat__StandardServoRead_Init
      (&DAL_Sat_HW_ExtendedControl_DW.StandardServoRead_p,
       &DAL_Sat_HW_ExtendedControl_P.StandardServoRead_p);

    /* End of SystemInitialize for SubSystem: '<S5>/If Action Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem' */

    /* Start for MATLABSystem: '<S4>/Analog Input12' */
    DAL_Sat_HW_ExtendedControl_DW.obj_h.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_ExtendedControl_DW.obj_h.isInitialized = 0L;
    DAL_Sat_HW_ExtendedControl_DW.obj_h.SampleTime = -1.0;
    DAL_Sat_HW_ExtendedControl_DW.obj_h.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_h.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput12_SampleTime;
    obj = &DAL_Sat_HW_ExtendedControl_DW.obj_h;
    DAL_Sat_HW_ExtendedControl_DW.obj_h.isSetupComplete = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16UL);
    DAL_Sat_HW_ExtendedControl_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Analog Input14' */
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.isInitialized = 0L;
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.SampleTime = -1.0;
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput14_SampleTime;
    obj = &DAL_Sat_HW_ExtendedControl_DW.obj_c4;
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.isSetupComplete = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17UL);
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Analog Input13' */
    DAL_Sat_HW_ExtendedControl_DW.obj_l.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_ExtendedControl_DW.obj_l.isInitialized = 0L;
    DAL_Sat_HW_ExtendedControl_DW.obj_l.SampleTime = -1.0;
    DAL_Sat_HW_ExtendedControl_DW.obj_l.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_l.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput13_SampleTime;
    obj = &DAL_Sat_HW_ExtendedControl_DW.obj_l;
    DAL_Sat_HW_ExtendedControl_DW.obj_l.isSetupComplete = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_l.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    DAL_Sat_HW_ExtendedControl_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Analog Input16' */
    DAL_Sat_HW_ExtendedControl_DW.obj_i.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_ExtendedControl_DW.obj_i.isInitialized = 0L;
    DAL_Sat_HW_ExtendedControl_DW.obj_i.SampleTime = -1.0;
    DAL_Sat_HW_ExtendedControl_DW.obj_i.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_i.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput16_SampleTime;
    obj = &DAL_Sat_HW_ExtendedControl_DW.obj_i;
    DAL_Sat_HW_ExtendedControl_DW.obj_i.isSetupComplete = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_i.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    DAL_Sat_HW_ExtendedControl_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Analog Input15' */
    DAL_Sat_HW_ExtendedControl_DW.obj_c.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_ExtendedControl_DW.obj_c.isInitialized = 0L;
    DAL_Sat_HW_ExtendedControl_DW.obj_c.SampleTime = -1.0;
    DAL_Sat_HW_ExtendedControl_DW.obj_c.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_c.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput15_SampleTime;
    obj = &DAL_Sat_HW_ExtendedControl_DW.obj_c;
    DAL_Sat_HW_ExtendedControl_DW.obj_c.isSetupComplete = false;
    DAL_Sat_HW_ExtendedControl_DW.obj_c.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    DAL_Sat_HW_ExtendedControl_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Analog Input17' */
    DAL_Sat_HW_ExtendedControl_DW.obj.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_ExtendedControl_DW.obj.isInitialized = 0L;
    DAL_Sat_HW_ExtendedControl_DW.obj.SampleTime = -1.0;
    DAL_Sat_HW_ExtendedControl_DW.obj.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_ExtendedControl_DW.obj.SampleTime =
      DAL_Sat_HW_ExtendedControl_P.AnalogInput17_SampleTime;
    obj = &DAL_Sat_HW_ExtendedControl_DW.obj;
    DAL_Sat_HW_ExtendedControl_DW.obj.isSetupComplete = false;
    DAL_Sat_HW_ExtendedControl_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19UL);
    DAL_Sat_HW_ExtendedControl_DW.obj.isSetupComplete = true;
    DAL_Sat__StandardServoRead_Init
      (&DAL_Sat_HW_ExtendedControl_DW.StandardServoRead,
       &DAL_Sat_HW_ExtendedControl_P.StandardServoRead);

    /* Start for MATLABSystem: '<S1>/Continuous Servo Write' */
    MW_servoAttach(0, 9);
  }
}

/* Model terminate function */
void DAL_Sat_HW_ExtendedControl_terminate(void)
{
  codertarget_arduinobase_in_lx_T *obj;

  /* Terminate for MATLABSystem: '<S4>/Analog Input12' */
  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_h;
  if (!DAL_Sat_HW_ExtendedControl_DW.obj_h.matlabCodegenIsDeleted) {
    DAL_Sat_HW_ExtendedControl_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_ExtendedControl_DW.obj_h.isInitialized == 1L) &&
        DAL_Sat_HW_ExtendedControl_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_ExtendedControl_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input12' */

  /* Terminate for MATLABSystem: '<S4>/Analog Input14' */
  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_c4;
  if (!DAL_Sat_HW_ExtendedControl_DW.obj_c4.matlabCodegenIsDeleted) {
    DAL_Sat_HW_ExtendedControl_DW.obj_c4.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_ExtendedControl_DW.obj_c4.isInitialized == 1L) &&
        DAL_Sat_HW_ExtendedControl_DW.obj_c4.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_ExtendedControl_DW.obj_c4.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input14' */

  /* Terminate for MATLABSystem: '<S4>/Analog Input13' */
  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_l;
  if (!DAL_Sat_HW_ExtendedControl_DW.obj_l.matlabCodegenIsDeleted) {
    DAL_Sat_HW_ExtendedControl_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_ExtendedControl_DW.obj_l.isInitialized == 1L) &&
        DAL_Sat_HW_ExtendedControl_DW.obj_l.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_ExtendedControl_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input13' */

  /* Terminate for MATLABSystem: '<S4>/Analog Input16' */
  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_i;
  if (!DAL_Sat_HW_ExtendedControl_DW.obj_i.matlabCodegenIsDeleted) {
    DAL_Sat_HW_ExtendedControl_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_ExtendedControl_DW.obj_i.isInitialized == 1L) &&
        DAL_Sat_HW_ExtendedControl_DW.obj_i.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_ExtendedControl_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input16' */

  /* Terminate for MATLABSystem: '<S4>/Analog Input15' */
  obj = &DAL_Sat_HW_ExtendedControl_DW.obj_c;
  if (!DAL_Sat_HW_ExtendedControl_DW.obj_c.matlabCodegenIsDeleted) {
    DAL_Sat_HW_ExtendedControl_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_ExtendedControl_DW.obj_c.isInitialized == 1L) &&
        DAL_Sat_HW_ExtendedControl_DW.obj_c.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_ExtendedControl_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input15' */

  /* Terminate for MATLABSystem: '<S4>/Analog Input17' */
  obj = &DAL_Sat_HW_ExtendedControl_DW.obj;
  if (!DAL_Sat_HW_ExtendedControl_DW.obj.matlabCodegenIsDeleted) {
    DAL_Sat_HW_ExtendedControl_DW.obj.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_ExtendedControl_DW.obj.isInitialized == 1L) &&
        DAL_Sat_HW_ExtendedControl_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_ExtendedControl_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Analog Input17' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
