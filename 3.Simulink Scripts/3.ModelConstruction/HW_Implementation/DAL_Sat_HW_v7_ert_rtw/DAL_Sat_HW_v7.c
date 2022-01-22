/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DAL_Sat_HW_v7.c
 *
 * Code generated for Simulink model 'DAL_Sat_HW_v7'.
 *
 * Model version                  : 1.151
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jan 22 11:28:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DAL_Sat_HW_v7.h"
#include "DAL_Sat_HW_v7_private.h"

/* Block signals (default storage) */
B_DAL_Sat_HW_v7_T DAL_Sat_HW_v7_B;

/* Block states (default storage) */
DW_DAL_Sat_HW_v7_T DAL_Sat_HW_v7_DW;

/* Real-time model */
static RT_MODEL_DAL_Sat_HW_v7_T DAL_Sat_HW_v7_M_;
RT_MODEL_DAL_Sat_HW_v7_T *const DAL_Sat_HW_v7_M = &DAL_Sat_HW_v7_M_;

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
void DAL_Sat_HW_v7_StandardServoRead(B_StandardServoRead_DAL_Sat_H_T *localB,
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
 *    '<S23>/If Action Subsystem'
 *    '<S27>/If Action Subsystem'
 */
void DAL_Sat_HW_v7_IfActionSubsystem(real_T *rty_Theta_Servo_New,
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
void DAL_Sat_HW_v7_step(void)
{
  codertarget_arduinobase_in_co_T *obj;
  real_T rtb_Abs1;
  real_T rtb_DataTypeConversion2_idx_0;
  real_T rtb_DataTypeConversion2_idx_1;
  real_T rtb_DataTypeConversion2_idx_2;
  int32_T rtb_StandardServoRead_0;
  uint16_T rtb_xp_max;
  uint16_T rtb_xp_yp_0;
  uint16_T rtb_yn_max;
  uint16_T rtb_yn_xn_0;
  uint16_T rtb_yn_xp_0;
  uint16_T rtb_yp_xn_0;
  uint8_T rtb_Merge_b_0;

  /* MATLABSystem: '<S3>/Analog Input12' */
  if (DAL_Sat_HW_v7_DW.obj_e.SampleTime !=
      DAL_Sat_HW_v7_P.AnalogInput12_SampleTime) {
    DAL_Sat_HW_v7_DW.obj_e.SampleTime = DAL_Sat_HW_v7_P.AnalogInput12_SampleTime;
  }

  obj = &DAL_Sat_HW_v7_DW.obj_e;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v7_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_xp_yp_0,
     3);

  /* MATLABSystem: '<S3>/Analog Input14' */
  if (DAL_Sat_HW_v7_DW.obj_h.SampleTime !=
      DAL_Sat_HW_v7_P.AnalogInput14_SampleTime) {
    DAL_Sat_HW_v7_DW.obj_h.SampleTime = DAL_Sat_HW_v7_P.AnalogInput14_SampleTime;
  }

  obj = &DAL_Sat_HW_v7_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v7_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_xp_max, 3);

  /* MinMax: '<S3>/Max' incorporates:
   *  MATLABSystem: '<S3>/Analog Input12'
   *  MATLABSystem: '<S3>/Analog Input14'
   */
  if (rtb_xp_yp_0 >= rtb_xp_max) {
    rtb_xp_max = rtb_xp_yp_0;
  }

  /* End of MinMax: '<S3>/Max' */

  /* MATLABSystem: '<S3>/Analog Input13' */
  if (DAL_Sat_HW_v7_DW.obj_a.SampleTime !=
      DAL_Sat_HW_v7_P.AnalogInput13_SampleTime) {
    DAL_Sat_HW_v7_DW.obj_a.SampleTime = DAL_Sat_HW_v7_P.AnalogInput13_SampleTime;
  }

  obj = &DAL_Sat_HW_v7_DW.obj_a;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v7_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_xp_yp_0,
     3);

  /* MATLABSystem: '<S3>/Analog Input16' */
  if (DAL_Sat_HW_v7_DW.obj_k.SampleTime !=
      DAL_Sat_HW_v7_P.AnalogInput16_SampleTime) {
    DAL_Sat_HW_v7_DW.obj_k.SampleTime = DAL_Sat_HW_v7_P.AnalogInput16_SampleTime;
  }

  obj = &DAL_Sat_HW_v7_DW.obj_k;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v7_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_yp_xn_0,
     3);

  /* MATLABSystem: '<S3>/Analog Input15' */
  if (DAL_Sat_HW_v7_DW.obj_m.SampleTime !=
      DAL_Sat_HW_v7_P.AnalogInput15_SampleTime) {
    DAL_Sat_HW_v7_DW.obj_m.SampleTime = DAL_Sat_HW_v7_P.AnalogInput15_SampleTime;
  }

  obj = &DAL_Sat_HW_v7_DW.obj_m;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v7_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_yn_xp_0,
     3);

  /* MATLABSystem: '<S3>/Analog Input17' */
  if (DAL_Sat_HW_v7_DW.obj.SampleTime !=
      DAL_Sat_HW_v7_P.AnalogInput17_SampleTime) {
    DAL_Sat_HW_v7_DW.obj.SampleTime = DAL_Sat_HW_v7_P.AnalogInput17_SampleTime;
  }

  obj = &DAL_Sat_HW_v7_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
  MW_AnalogInSingle_ReadResult
    (DAL_Sat_HW_v7_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_yn_xn_0, 3);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   *  SignalConversion generated from: '<S3>/Gain5'
   */
  rtb_DataTypeConversion2_idx_0 = (real_T)((uint32_T)DAL_Sat_HW_v7_P.Gain5_Gain *
    rtb_xp_max) * 1.1920928955078125E-7;

  /* MinMax: '<S3>/Max1' incorporates:
   *  MATLABSystem: '<S3>/Analog Input13'
   *  MATLABSystem: '<S3>/Analog Input16'
   */
  if (rtb_xp_yp_0 >= rtb_yp_xn_0) {
    rtb_yn_max = rtb_xp_yp_0;
  } else {
    rtb_yn_max = rtb_yp_xn_0;
  }

  /* End of MinMax: '<S3>/Max1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   */
  rtb_DataTypeConversion2_idx_1 = (real_T)((uint32_T)DAL_Sat_HW_v7_P.Gain5_Gain *
    rtb_yn_max) * 1.1920928955078125E-7;

  /* MinMax: '<S3>/Max2' incorporates:
   *  MATLABSystem: '<S3>/Analog Input15'
   *  MATLABSystem: '<S3>/Analog Input17'
   */
  if (rtb_yn_xp_0 >= rtb_yn_xn_0) {
    rtb_yn_max = rtb_yn_xp_0;
  } else {
    rtb_yn_max = rtb_yn_xn_0;
  }

  /* End of MinMax: '<S3>/Max2' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain5'
   */
  rtb_DataTypeConversion2_idx_2 = (real_T)((uint32_T)DAL_Sat_HW_v7_P.Gain5_Gain *
    rtb_yn_max) * 1.1920928955078125E-7;

  /* Sqrt: '<S2>/Sqrt2' incorporates:
   *  Math: '<S2>/Math Function2'
   *  Sum: '<S2>/Sum of Elements2'
   *
   * About '<S2>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_Abs1 = sqrt((rtb_DataTypeConversion2_idx_0 * rtb_DataTypeConversion2_idx_0
                   + rtb_DataTypeConversion2_idx_1 *
                   rtb_DataTypeConversion2_idx_1) +
                  rtb_DataTypeConversion2_idx_2 * rtb_DataTypeConversion2_idx_2);

  /* If: '<S11>/If2' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  if (rtb_DataTypeConversion2_idx_1 <= 0.19550342130987292) {
    rtb_DataTypeConversion2_idx_1 = DAL_Sat_HW_v7_P.Constant2_Value_e;
  }

  /* End of If: '<S11>/If2' */

  /* If: '<S11>/If3' incorporates:
   *  Constant: '<S11>/Constant3'
   */
  if (rtb_DataTypeConversion2_idx_2 <= 0.19550342130987292) {
    rtb_DataTypeConversion2_idx_2 = DAL_Sat_HW_v7_P.Constant3_Value;
  }

  /* End of If: '<S11>/If3' */

  /* If: '<S11>/If' incorporates:
   *  Constant: '<S11>/Constant'
   */
  if (rtb_DataTypeConversion2_idx_0 <= 0.19550342130987292) {
    rtb_DataTypeConversion2_idx_0 = DAL_Sat_HW_v7_P.Constant_Value_l;
  }

  /* End of If: '<S11>/If' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S2>/Gain4'
   *  Product: '<S2>/Divide2'
   *  Sum: '<S2>/Add3'
   *  Trigonometry: '<S2>/Trigonometric Function2'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_DataTypeConversion2_idx_0 = rt_atan2d_snf((rtb_DataTypeConversion2_idx_1 -
    rtb_DataTypeConversion2_idx_2) / rtb_Abs1, rtb_DataTypeConversion2_idx_0 /
    rtb_Abs1) * DAL_Sat_HW_v7_P.Gain4_Gain + DAL_Sat_HW_v7_DW.UnitDelay_DSTATE;

  /* If: '<S6>/If' incorporates:
   *  Abs: '<S6>/Abs1'
   */
  if (fabs(rtb_DataTypeConversion2_idx_0) > 90.0) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    DAL_Sat_HW_v7_StandardServoRead(&DAL_Sat_HW_v7_B.StandardServoRead_p,
      &DAL_Sat_HW_v7_DW.StandardServoRead_p,
      &DAL_Sat_HW_v7_P.StandardServoRead_p);

    /* If: '<S7>/If' */
    if (rtb_DataTypeConversion2_idx_0 > 0.0) {
      /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Sum: '<S9>/Subtract' incorporates:
       *  Constant: '<S9>/Constant'
       */
      rtb_DataTypeConversion2_idx_0 = (real_T)
        DAL_Sat_HW_v7_B.StandardServoRead_p.StandardServoRead -
        DAL_Sat_HW_v7_P.Constant_Value;

      /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Sum: '<S10>/Subtract' incorporates:
       *  Constant: '<S10>/Constant'
       */
      rtb_DataTypeConversion2_idx_0 = (real_T)
        DAL_Sat_HW_v7_B.StandardServoRead_p.StandardServoRead +
        DAL_Sat_HW_v7_P.Constant_Value_i;

      /* End of Outputs for SubSystem: '<S7>/If Action Subsystem4' */
    }

    /* End of If: '<S7>/If' */
    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
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
     *  MATLABSystem: '<S3>/Analog Input13'
     *  MATLABSystem: '<S3>/Analog Input16'
     */
    if ((real_T)rtb_xp_yp_0 >= rtb_yp_xn_0) {
      rtb_xp_max = rtb_xp_yp_0;
    } else {
      rtb_xp_max = rtb_yp_xn_0;
    }

    /* End of MinMax: '<S19>/Max' */

    /* MinMax: '<S19>/Max1' incorporates:
     *  DataTypeConversion: '<S19>/Data Type Conversion3'
     *  DataTypeConversion: '<S19>/Data Type Conversion4'
     *  MATLABSystem: '<S3>/Analog Input15'
     *  MATLABSystem: '<S3>/Analog Input17'
     */
    if ((real_T)rtb_yn_xp_0 >= rtb_yn_xn_0) {
      rtb_yn_max = rtb_yn_xp_0;
    } else {
      rtb_yn_max = rtb_yn_xn_0;
    }

    /* End of MinMax: '<S19>/Max1' */

    /* If: '<S19>/If' */
    if ((rtb_xp_max < 40U) && (rtb_yn_max > 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/Only Reads in yn' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      DAL_Sat_HW_v7_StandardServoRead(&DAL_Sat_HW_v7_B.StandardServoRead_pn,
        &DAL_Sat_HW_v7_DW.StandardServoRead_pn,
        &DAL_Sat_HW_v7_P.StandardServoRead_pn);

      /* Sum: '<S21>/Sum' incorporates:
       *  Constant: '<S21>/Constant2'
       */
      DAL_Sat_HW_v7_B.Merge = (real_T)
        DAL_Sat_HW_v7_B.StandardServoRead_pn.StandardServoRead -
        DAL_Sat_HW_v7_P.Constant2_Value;

      /* If: '<S21>/If' incorporates:
       *  Constant: '<S21>/Constant'
       *  DataTypeConversion: '<S19>/Data Type Conversion3'
       *  DataTypeConversion: '<S19>/Data Type Conversion4'
       *  MATLABSystem: '<S3>/Analog Input15'
       *  MATLABSystem: '<S3>/Analog Input17'
       *  Sum: '<S21>/Add'
       */
      if ((real_T)rtb_yn_xp_0 + DAL_Sat_HW_v7_P.Constant_Value_e < rtb_yn_xn_0)
      {
        /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        /* If: '<S23>/If' */
        if (DAL_Sat_HW_v7_B.Merge >= 86.0) {
          /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
           *  ActionPort: '<S25>/Action Port'
           */
          /* Merge: '<S19>/Merge' */
          DAL_Sat_HW_v7_IfActionSubsystem(&DAL_Sat_HW_v7_B.Merge,
            &DAL_Sat_HW_v7_P.IfActionSubsystem_c);

          /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* Sum: '<S21>/Sum' incorporates:
           *  Constant: '<S26>/Constant'
           *  Merge: '<S19>/Merge'
           *  Merge: '<S21>/Merge'
           *  Sum: '<S26>/Add'
           */
          DAL_Sat_HW_v7_B.Merge += DAL_Sat_HW_v7_P.Constant_Value_j;

          /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */
        }

        /* End of If: '<S23>/If' */
        /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */
      }

      /* End of If: '<S21>/If' */
      /* End of Outputs for SubSystem: '<S19>/Only Reads in yn' */
    }

    /* End of If: '<S19>/If' */

    /* If: '<S19>/If2' */
    if ((rtb_yn_max < 40U) && (rtb_xp_max < 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* MATLABSystem: '<S20>/Standard Servo Read' */
      if (DAL_Sat_HW_v7_DW.obj_m5.SampleTime !=
          DAL_Sat_HW_v7_P.StandardServoRead_SampleTime) {
        DAL_Sat_HW_v7_DW.obj_m5.SampleTime =
          DAL_Sat_HW_v7_P.StandardServoRead_SampleTime;
      }

      rtb_StandardServoRead_0 = MW_servoRead(1);

      /* Sum: '<S21>/Sum' incorporates:
       *  Constant: '<S20>/Constant'
       *  MATLABSystem: '<S20>/Standard Servo Read'
       *  Merge: '<S19>/Merge'
       *  SignalConversion generated from: '<S20>/Out1'
       *  Sum: '<S20>/Sum'
       */
      DAL_Sat_HW_v7_B.Merge = (real_T)rtb_StandardServoRead_0 -
        DAL_Sat_HW_v7_P.Constant_Value_o;

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */
    }

    /* End of If: '<S19>/If2' */

    /* If: '<S19>/If1' */
    if ((rtb_yn_max < 40U) && (rtb_xp_max > 40U)) {
      /* Outputs for IfAction SubSystem: '<S19>/Only Reads in yp' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      DAL_Sat_HW_v7_StandardServoRead(&DAL_Sat_HW_v7_B.StandardServoRead_pna,
        &DAL_Sat_HW_v7_DW.StandardServoRead_pna,
        &DAL_Sat_HW_v7_P.StandardServoRead_pna);

      /* Sum: '<S21>/Sum' incorporates:
       *  Constant: '<S22>/Constant2'
       *  Sum: '<S22>/Sum'
       */
      DAL_Sat_HW_v7_B.Merge = (real_T)
        DAL_Sat_HW_v7_B.StandardServoRead_pna.StandardServoRead -
        DAL_Sat_HW_v7_P.Constant2_Value_h;

      /* If: '<S22>/If' incorporates:
       *  Constant: '<S22>/Constant'
       *  DataTypeConversion: '<S19>/Data Type Conversion1'
       *  DataTypeConversion: '<S19>/Data Type Conversion2'
       *  MATLABSystem: '<S3>/Analog Input13'
       *  MATLABSystem: '<S3>/Analog Input16'
       *  Sum: '<S22>/Add'
       */
      if ((real_T)rtb_xp_yp_0 + DAL_Sat_HW_v7_P.Constant_Value_b < rtb_yp_xn_0)
      {
        /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* If: '<S27>/If' */
        if (DAL_Sat_HW_v7_B.Merge <= -86.0) {
          /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* Merge: '<S19>/Merge' */
          DAL_Sat_HW_v7_IfActionSubsystem(&DAL_Sat_HW_v7_B.Merge,
            &DAL_Sat_HW_v7_P.IfActionSubsystem_l);

          /* End of Outputs for SubSystem: '<S27>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S30>/Action Port'
           */
          /* Sum: '<S21>/Sum' incorporates:
           *  Constant: '<S30>/Constant'
           *  Merge: '<S19>/Merge'
           *  Merge: '<S22>/Merge'
           *  Sum: '<S30>/Add'
           */
          DAL_Sat_HW_v7_B.Merge -= DAL_Sat_HW_v7_P.Constant_Value_eg;

          /* End of Outputs for SubSystem: '<S27>/If Action Subsystem1' */
        }

        /* End of If: '<S27>/If' */
        /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */
      }

      /* End of If: '<S22>/If' */
      /* End of Outputs for SubSystem: '<S19>/Only Reads in yp' */
    }

    /* End of If: '<S19>/If1' */

    /* SignalConversion generated from: '<S19>/Output' */
    rtb_DataTypeConversion2_idx_1 = DAL_Sat_HW_v7_B.Merge;

    /* End of Outputs for SubSystem: '<S3>/Light does not point at xp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* SignalConversion generated from: '<S18>/Out1' incorporates:
     *  Constant: '<S18>/Constant'
     */
    rtb_DataTypeConversion2_idx_1 = DAL_Sat_HW_v7_P.Constant_Value_c;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
  }

  /* End of If: '<S3>/If' */

  /* If: '<S1>/If' incorporates:
   *  Inport: '<S4>/Theta_OrientedRF'
   */
  if (rtb_DataTypeConversion2_idx_1 == 100.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    rtb_DataTypeConversion2_idx_1 = rtb_DataTypeConversion2_idx_0;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
  }

  /* End of If: '<S1>/If' */

  /* MATLABSystem: '<S1>/Continuous Servo Write' */
  if (rtb_DataTypeConversion2_idx_1 + 90.0 < 0.0) {
    rtb_Merge_b_0 = 0U;
  } else if (rtb_DataTypeConversion2_idx_1 + 90.0 > 180.0) {
    rtb_Merge_b_0 = 180U;
  } else {
    rtb_DataTypeConversion2_idx_0 = rt_roundd_snf(rtb_DataTypeConversion2_idx_1
      + 90.0);
    if (rtb_DataTypeConversion2_idx_0 < 256.0) {
      if (rtb_DataTypeConversion2_idx_0 >= 0.0) {
        rtb_Merge_b_0 = (uint8_T)rtb_DataTypeConversion2_idx_0;
      } else {
        rtb_Merge_b_0 = 0U;
      }
    } else {
      rtb_Merge_b_0 = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, rtb_Merge_b_0);

  /* End of MATLABSystem: '<S1>/Continuous Servo Write' */
  DAL_Sat_HW_v7_StandardServoRead(&DAL_Sat_HW_v7_B.StandardServoRead,
    &DAL_Sat_HW_v7_DW.StandardServoRead, &DAL_Sat_HW_v7_P.StandardServoRead);

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  DAL_Sat_HW_v7_DW.UnitDelay_DSTATE = (real_T)
    DAL_Sat_HW_v7_B.StandardServoRead.StandardServoRead -
    DAL_Sat_HW_v7_P.Constant_Value_lr;
}

/* Model initialize function */
void DAL_Sat_HW_v7_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_in_co_T *obj;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
    DAL_Sat_HW_v7_DW.UnitDelay_DSTATE =
      DAL_Sat_HW_v7_P.UnitDelay_InitialCondition;

    /* SystemInitialize for IfAction SubSystem: '<S6>/If Action Subsystem1' */
    DAL_Sat__StandardServoRead_Init(&DAL_Sat_HW_v7_DW.StandardServoRead_p,
      &DAL_Sat_HW_v7_P.StandardServoRead_p);

    /* End of SystemInitialize for SubSystem: '<S6>/If Action Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S3>/Light does not point at xp' */
    /* SystemInitialize for IfAction SubSystem: '<S19>/Only Reads in yn' */
    DAL_Sat__StandardServoRead_Init(&DAL_Sat_HW_v7_DW.StandardServoRead_pn,
      &DAL_Sat_HW_v7_P.StandardServoRead_pn);

    /* End of SystemInitialize for SubSystem: '<S19>/Only Reads in yn' */

    /* SystemInitialize for IfAction SubSystem: '<S19>/If Action Subsystem' */
    /* Start for MATLABSystem: '<S20>/Standard Servo Read' */
    DAL_Sat_HW_v7_DW.obj_m5.SampleTime =
      DAL_Sat_HW_v7_P.StandardServoRead_SampleTime;
    DAL_Sat_HW_v7_DW.obj_m5.isInitialized = 1L;
    MW_servoAttach(1, 2);

    /* End of SystemInitialize for SubSystem: '<S19>/If Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<S19>/Only Reads in yp' */
    DAL_Sat__StandardServoRead_Init(&DAL_Sat_HW_v7_DW.StandardServoRead_pna,
      &DAL_Sat_HW_v7_P.StandardServoRead_pna);

    /* End of SystemInitialize for SubSystem: '<S19>/Only Reads in yp' */

    /* SystemInitialize for Sum: '<S21>/Sum' incorporates:
     *  Merge: '<S19>/Merge'
     */
    DAL_Sat_HW_v7_B.Merge = DAL_Sat_HW_v7_P.Merge_InitialOutput_k2;

    /* End of SystemInitialize for SubSystem: '<S3>/Light does not point at xp' */

    /* Start for MATLABSystem: '<S3>/Analog Input12' */
    DAL_Sat_HW_v7_DW.obj_e.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v7_DW.obj_e.isInitialized = 0L;
    DAL_Sat_HW_v7_DW.obj_e.SampleTime = -1.0;
    DAL_Sat_HW_v7_DW.obj_e.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v7_DW.obj_e.SampleTime = DAL_Sat_HW_v7_P.AnalogInput12_SampleTime;
    obj = &DAL_Sat_HW_v7_DW.obj_e;
    DAL_Sat_HW_v7_DW.obj_e.isSetupComplete = false;
    DAL_Sat_HW_v7_DW.obj_e.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16UL);
    DAL_Sat_HW_v7_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input14' */
    DAL_Sat_HW_v7_DW.obj_h.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v7_DW.obj_h.isInitialized = 0L;
    DAL_Sat_HW_v7_DW.obj_h.SampleTime = -1.0;
    DAL_Sat_HW_v7_DW.obj_h.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v7_DW.obj_h.SampleTime = DAL_Sat_HW_v7_P.AnalogInput14_SampleTime;
    obj = &DAL_Sat_HW_v7_DW.obj_h;
    DAL_Sat_HW_v7_DW.obj_h.isSetupComplete = false;
    DAL_Sat_HW_v7_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17UL);
    DAL_Sat_HW_v7_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input13' */
    DAL_Sat_HW_v7_DW.obj_a.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v7_DW.obj_a.isInitialized = 0L;
    DAL_Sat_HW_v7_DW.obj_a.SampleTime = -1.0;
    DAL_Sat_HW_v7_DW.obj_a.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v7_DW.obj_a.SampleTime = DAL_Sat_HW_v7_P.AnalogInput13_SampleTime;
    obj = &DAL_Sat_HW_v7_DW.obj_a;
    DAL_Sat_HW_v7_DW.obj_a.isSetupComplete = false;
    DAL_Sat_HW_v7_DW.obj_a.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    DAL_Sat_HW_v7_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input16' */
    DAL_Sat_HW_v7_DW.obj_k.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v7_DW.obj_k.isInitialized = 0L;
    DAL_Sat_HW_v7_DW.obj_k.SampleTime = -1.0;
    DAL_Sat_HW_v7_DW.obj_k.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v7_DW.obj_k.SampleTime = DAL_Sat_HW_v7_P.AnalogInput16_SampleTime;
    obj = &DAL_Sat_HW_v7_DW.obj_k;
    DAL_Sat_HW_v7_DW.obj_k.isSetupComplete = false;
    DAL_Sat_HW_v7_DW.obj_k.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    DAL_Sat_HW_v7_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input15' */
    DAL_Sat_HW_v7_DW.obj_m.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v7_DW.obj_m.isInitialized = 0L;
    DAL_Sat_HW_v7_DW.obj_m.SampleTime = -1.0;
    DAL_Sat_HW_v7_DW.obj_m.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v7_DW.obj_m.SampleTime = DAL_Sat_HW_v7_P.AnalogInput15_SampleTime;
    obj = &DAL_Sat_HW_v7_DW.obj_m;
    DAL_Sat_HW_v7_DW.obj_m.isSetupComplete = false;
    DAL_Sat_HW_v7_DW.obj_m.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    DAL_Sat_HW_v7_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input17' */
    DAL_Sat_HW_v7_DW.obj.matlabCodegenIsDeleted = true;
    DAL_Sat_HW_v7_DW.obj.isInitialized = 0L;
    DAL_Sat_HW_v7_DW.obj.SampleTime = -1.0;
    DAL_Sat_HW_v7_DW.obj.matlabCodegenIsDeleted = false;
    DAL_Sat_HW_v7_DW.obj.SampleTime = DAL_Sat_HW_v7_P.AnalogInput17_SampleTime;
    obj = &DAL_Sat_HW_v7_DW.obj;
    DAL_Sat_HW_v7_DW.obj.isSetupComplete = false;
    DAL_Sat_HW_v7_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19UL);
    DAL_Sat_HW_v7_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Continuous Servo Write' */
    MW_servoAttach(0, 9);
    DAL_Sat__StandardServoRead_Init(&DAL_Sat_HW_v7_DW.StandardServoRead,
      &DAL_Sat_HW_v7_P.StandardServoRead);
  }
}

/* Model terminate function */
void DAL_Sat_HW_v7_terminate(void)
{
  codertarget_arduinobase_in_co_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Analog Input12' */
  obj = &DAL_Sat_HW_v7_DW.obj_e;
  if (!DAL_Sat_HW_v7_DW.obj_e.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v7_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v7_DW.obj_e.isInitialized == 1L) &&
        DAL_Sat_HW_v7_DW.obj_e.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v7_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input12' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input14' */
  obj = &DAL_Sat_HW_v7_DW.obj_h;
  if (!DAL_Sat_HW_v7_DW.obj_h.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v7_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v7_DW.obj_h.isInitialized == 1L) &&
        DAL_Sat_HW_v7_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v7_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input14' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input13' */
  obj = &DAL_Sat_HW_v7_DW.obj_a;
  if (!DAL_Sat_HW_v7_DW.obj_a.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v7_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v7_DW.obj_a.isInitialized == 1L) &&
        DAL_Sat_HW_v7_DW.obj_a.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v7_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input13' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input16' */
  obj = &DAL_Sat_HW_v7_DW.obj_k;
  if (!DAL_Sat_HW_v7_DW.obj_k.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v7_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v7_DW.obj_k.isInitialized == 1L) &&
        DAL_Sat_HW_v7_DW.obj_k.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v7_DW.obj_k.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input16' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input15' */
  obj = &DAL_Sat_HW_v7_DW.obj_m;
  if (!DAL_Sat_HW_v7_DW.obj_m.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v7_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v7_DW.obj_m.isInitialized == 1L) &&
        DAL_Sat_HW_v7_DW.obj_m.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v7_DW.obj_m.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input15' */

  /* Terminate for MATLABSystem: '<S3>/Analog Input17' */
  obj = &DAL_Sat_HW_v7_DW.obj;
  if (!DAL_Sat_HW_v7_DW.obj.matlabCodegenIsDeleted) {
    DAL_Sat_HW_v7_DW.obj.matlabCodegenIsDeleted = true;
    if ((DAL_Sat_HW_v7_DW.obj.isInitialized == 1L) &&
        DAL_Sat_HW_v7_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close
        (DAL_Sat_HW_v7_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog Input17' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
