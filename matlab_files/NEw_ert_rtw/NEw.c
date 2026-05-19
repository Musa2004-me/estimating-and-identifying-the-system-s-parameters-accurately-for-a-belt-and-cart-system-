/*
 * File: NEw.c
 *
 * Code generated for Simulink model 'NEw'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Dec 16 22:06:49 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "NEw.h"
#include "rtwtypes.h"
#include "NEw_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "NEw_types.h"

/* Block signals (default storage) */
B_NEw_T NEw_B;

/* Continuous states */
X_NEw_T NEw_X;

/* Block states (default storage) */
DW_NEw_T NEw_DW;

/* Real-time model */
static RT_MODEL_NEw_T NEw_M_;
RT_MODEL_NEw_T *const NEw_M = &NEw_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  NEw_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  NEw_step();
  NEw_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  NEw_step();
  NEw_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
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
void NEw_step(void)
{
  /* local block i/o variables */
  real_T rtb_Step;
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_in_g3_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_MultiportSwitch_idx_0;
  real_T rtb_MultiportSwitch_idx_1;
  uint16_T b_varargout_1;
  uint16_T b_varargout_1_0;
  uint8_T tmp;
  if (rtmIsMajorTimeStep(NEw_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&NEw_M->solverInfo,((NEw_M->Timing.clockTick0+1)*
      NEw_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(NEw_M)) {
    NEw_M->Timing.t[0] = rtsiGetT(&NEw_M->solverInfo);
  }

  /* FromWorkspace: '<S3>/fromWS_Signal 1' */
  {
    real_T t = NEw_M->Timing.t[0];
    real_T *pTimeValues = (real_T *) NEw_DW.fromWS_Signal1_PWORK.TimePtr;
    real_T *pDataValues = (real_T *) NEw_DW.fromWS_Signal1_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      rtb_Step = 0.0;
    } else if (t == pTimeValues[4]) {
      rtb_Step = pDataValues[4];
    } else if (t > pTimeValues[4]) {
      rtb_Step = 0.0;
    } else {
      int_T currTimeIndex = NEw_DW.fromWS_Signal1_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      rtb_Step = pDataValues[currTimeIndex];
      NEw_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant3'
   */
  switch ((int16_T)rtb_Step) {
   case 0:
    rtb_MultiportSwitch_idx_0 = NEw_P.Constant2_Value;
    rtb_MultiportSwitch_idx_1 = NEw_P.Constant3_Value;
    break;

   case 1:
    rtb_MultiportSwitch_idx_0 = NEw_P.Constant1_Value_k;
    rtb_MultiportSwitch_idx_1 = NEw_P.Constant2_Value_e;
    break;

   default:
    rtb_MultiportSwitch_idx_0 = NEw_P.Constant3_Value_e;
    rtb_MultiportSwitch_idx_1 = NEw_P.Constant4_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch' */

  /* MATLABSystem: '<S2>/Digital Output' incorporates:
   *  Gain: '<S2>/Gain1'
   */
  rtb_MultiportSwitch_idx_1 = rt_roundd_snf(NEw_P.Gain1_Gain *
    rtb_MultiportSwitch_idx_1);
  if (rtb_MultiportSwitch_idx_1 < 256.0) {
    if (rtb_MultiportSwitch_idx_1 >= 0.0) {
      tmp = (uint8_T)rtb_MultiportSwitch_idx_1;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(9, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output' */

  /* MATLABSystem: '<S2>/Digital Output4' incorporates:
   *  Gain: '<S2>/Gain2'
   */
  rtb_MultiportSwitch_idx_1 = rt_roundd_snf(NEw_P.Gain2_Gain *
    rtb_MultiportSwitch_idx_0);
  if (rtb_MultiportSwitch_idx_1 < 256.0) {
    if (rtb_MultiportSwitch_idx_1 >= 0.0) {
      tmp = (uint8_T)rtb_MultiportSwitch_idx_1;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp);

  /* End of MATLABSystem: '<S2>/Digital Output4' */

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  NEw_B.TransferFcn1 = 0.0;
  NEw_B.TransferFcn1 += NEw_P.TransferFcn1_C * NEw_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(NEw_M)) {
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  if (NEw_DW.obj_l.SampleTime != NEw_P.AnalogInput_SampleTime) {
    NEw_DW.obj_l.SampleTime = NEw_P.AnalogInput_SampleTime;
  }

  obj = &NEw_DW.obj_l;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult(NEw_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1, datatype_id);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (NEw_DW.obj_p.SampleTime != NEw_P.AnalogInput1_SampleTime) {
    NEw_DW.obj_p.SampleTime = NEw_P.AnalogInput1_SampleTime;
  }

  obj = &NEw_DW.obj_p;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult(NEw_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1_0, datatype_id);

  /* Gain: '<Root>/Gain2' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   *  MATLABSystem: '<Root>/Analog Input1'
   *  Sum: '<Root>/Sum'
   */
  NEw_B.Vin = (real_T)((int32_T)b_varargout_1_0 - b_varargout_1) *
    NEw_P.Gain2_Gain_e;
  if (rtmIsMajorTimeStep(NEw_M)) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    if (NEw_P.ManualSwitch_CurrentSetting == 1) {
      rtb_MultiportSwitch_idx_1 = NEw_P.Constant_Value;
    } else {
      if (NEw_P.Constant1_Value < 0.0) {
        /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
         *  Constant: '<Root>/Constant1'
         */
        rtb_MultiportSwitch_idx_1 = ceil(NEw_P.Constant1_Value);
      } else {
        /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
         *  Constant: '<Root>/Constant1'
         */
        rtb_MultiportSwitch_idx_1 = floor(NEw_P.Constant1_Value);
      }

      /* DataTypeConversion: '<Root>/Data Type Conversion' */
      if (rtIsNaN(rtb_MultiportSwitch_idx_1) || rtIsInf
          (rtb_MultiportSwitch_idx_1)) {
        rtb_MultiportSwitch_idx_1 = 0.0;
      } else {
        rtb_MultiportSwitch_idx_1 = fmod(rtb_MultiportSwitch_idx_1, 256.0);
      }

      rtb_MultiportSwitch_idx_1 = rtb_MultiportSwitch_idx_1 < 0.0 ? (int16_T)
        (uint8_T)-(int8_T)(uint8_T)-rtb_MultiportSwitch_idx_1 : (int16_T)
        (uint8_T)rtb_MultiportSwitch_idx_1;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* MATLABSystem: '<S2>/PWM EN' */
    obj_0 = &NEw_DW.obj_pe;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

    /* Gain: '<S2>/Gain' */
    rtb_MultiportSwitch_idx_1 *= NEw_P.Gain_Gain;

    /* MATLABSystem: '<S2>/PWM EN' */
    if (!(rtb_MultiportSwitch_idx_1 <= 255.0)) {
      rtb_MultiportSwitch_idx_1 = 255.0;
    }

    if (!(rtb_MultiportSwitch_idx_1 >= 0.0)) {
      rtb_MultiportSwitch_idx_1 = 0.0;
    }

    MW_PWM_SetDutyCycle(NEw_DW.obj_pe.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_MultiportSwitch_idx_1);
  }

  /* MATLABSystem: '<Root>/Encoder' */
  if (NEw_DW.obj.SampleTime != NEw_P.Encoder_SampleTime) {
    NEw_DW.obj.SampleTime = NEw_P.Encoder_SampleTime;
  }

  if (NEw_DW.obj.TunablePropsChanged) {
    NEw_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/Encoder' */
  MW_EncoderRead(NEw_DW.obj.Index, &NEw_B.currentstatePoistion);
  if (rtmIsMajorTimeStep(NEw_M)) {
    /* Delay: '<Root>/Delay' */
    NEw_B.Privousestate = NEw_DW.Delay_DSTATE;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Subtract'
   */
  NEw_B.RPMforWL = (int64_T)(NEw_B.currentstatePoistion - NEw_B.Privousestate) *
    NEw_P.Gain1_Gain_o;
  if (rtmIsMajorTimeStep(NEw_M)) {
    /* Delay: '<S1>/Delay1' */
    NEw_B.Delay1 = NEw_DW.Delay1_DSTATE;

    /* Product: '<S1>/Divide' incorporates:
     *  Constant: '<S1>/Constant4'
     *  Constant: '<S1>/Constant5'
     */
    NEw_B.Divide = NEw_P.Constant4_Value_g / NEw_P.Constant5_Value;
  }

  /* Sum: '<S1>/Add' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Subtract1'
   */
  NEw_B.Add = ((real_T)NEw_B.RPMforWL * 1.862645149230957E-9 - NEw_B.Delay1) *
    NEw_B.Divide + NEw_B.Delay1;
  if (rtmIsMajorTimeStep(NEw_M)) {
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  NEw_B.TransferFcn = 0.0;
  NEw_B.TransferFcn += NEw_P.TransferFcn_C * NEw_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(NEw_M)) {
  }

  if (rtmIsMajorTimeStep(NEw_M)) {
    if (rtmIsMajorTimeStep(NEw_M)) {
      /* Update for Delay: '<Root>/Delay' */
      NEw_DW.Delay_DSTATE = NEw_B.currentstatePoistion;

      /* Update for Delay: '<S1>/Delay1' */
      NEw_DW.Delay1_DSTATE = NEw_B.Add;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((NEw_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(NEw_M)) {   /* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((NEw_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(NEw_M)) {
    rt_ertODEUpdateContinuousStates(&NEw_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++NEw_M->Timing.clockTick0;
    NEw_M->Timing.t[0] = rtsiGetSolverStopTime(&NEw_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      NEw_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void NEw_derivatives(void)
{
  XDot_NEw_T *_rtXdot;
  _rtXdot = ((XDot_NEw_T *) NEw_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = NEw_P.TransferFcn1_A *
    NEw_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += NEw_B.Vin;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = NEw_P.TransferFcn_A * NEw_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += NEw_B.Add;
}

/* Model initialize function */
void NEw_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&NEw_M->solverInfo, &NEw_M->Timing.simTimeStep);
    rtsiSetTPtr(&NEw_M->solverInfo, &rtmGetTPtr(NEw_M));
    rtsiSetStepSizePtr(&NEw_M->solverInfo, &NEw_M->Timing.stepSize0);
    rtsiSetdXPtr(&NEw_M->solverInfo, &NEw_M->derivs);
    rtsiSetContStatesPtr(&NEw_M->solverInfo, (real_T **) &NEw_M->contStates);
    rtsiSetNumContStatesPtr(&NEw_M->solverInfo, &NEw_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&NEw_M->solverInfo,
      &NEw_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&NEw_M->solverInfo,
      &NEw_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&NEw_M->solverInfo,
      &NEw_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&NEw_M->solverInfo, (&rtmGetErrorStatus(NEw_M)));
    rtsiSetRTModelPtr(&NEw_M->solverInfo, NEw_M);
  }

  rtsiSetSimTimeStep(&NEw_M->solverInfo, MAJOR_TIME_STEP);
  NEw_M->intgData.y = NEw_M->odeY;
  NEw_M->intgData.f[0] = NEw_M->odeF[0];
  NEw_M->intgData.f[1] = NEw_M->odeF[1];
  NEw_M->intgData.f[2] = NEw_M->odeF[2];
  NEw_M->contStates = ((X_NEw_T *) &NEw_X);
  rtsiSetSolverData(&NEw_M->solverInfo, (void *)&NEw_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&NEw_M->solverInfo, false);
  rtsiSetSolverName(&NEw_M->solverInfo,"ode3");
  rtmSetTPtr(NEw_M, &NEw_M->Timing.tArray[0]);
  rtmSetTFinal(NEw_M, 10.0);
  NEw_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  NEw_M->Sizes.checksums[0] = (2192212167U);
  NEw_M->Sizes.checksums[1] = (3700494059U);
  NEw_M->Sizes.checksums[2] = (3501668985U);
  NEw_M->Sizes.checksums[3] = (4205872066U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    NEw_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(NEw_M->extModeInfo,
      &NEw_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(NEw_M->extModeInfo, NEw_M->Sizes.checksums);
    rteiSetTPtr(NEw_M->extModeInfo, rtmGetTPtr(NEw_M));
  }

  {
    codertarget_arduinobase_in_g3_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for FromWorkspace: '<S3>/fromWS_Signal 1' */
    {
      static real_T pTimeValues0[] = { 0.0, 2.5, 5.0, 7.5, 10.0 } ;

      static real_T pDataValues0[] = { 1.0, 0.0, 2.0, 0.0, 0.0 } ;

      NEw_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
      NEw_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
      NEw_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
    }

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
    NEw_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    NEw_DW.Delay_DSTATE = NEw_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    NEw_DW.Delay1_DSTATE = NEw_P.Delay1_InitialCondition;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
    NEw_X.TransferFcn_CSTATE = 0.0;

    /* Start for MATLABSystem: '<S2>/Digital Output' */
    NEw_DW.obj_j.matlabCodegenIsDeleted = false;
    NEw_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(9, 1);
    NEw_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Output4' */
    NEw_DW.obj_e.matlabCodegenIsDeleted = false;
    NEw_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(7, 1);
    NEw_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    NEw_DW.obj_l.matlabCodegenIsDeleted = false;
    NEw_DW.obj_l.SampleTime = NEw_P.AnalogInput_SampleTime;
    obj = &NEw_DW.obj_l;
    NEw_DW.obj_l.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    NEw_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    NEw_DW.obj_p.matlabCodegenIsDeleted = false;
    NEw_DW.obj_p.SampleTime = NEw_P.AnalogInput1_SampleTime;
    obj = &NEw_DW.obj_p;
    NEw_DW.obj_p.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    NEw_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM EN' */
    NEw_DW.obj_pe.matlabCodegenIsDeleted = false;
    obj_0 = &NEw_DW.obj_pe;
    NEw_DW.obj_pe.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
    NEw_DW.obj_pe.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Encoder' */
    NEw_DW.obj.Index = 0U;
    NEw_DW.obj.matlabCodegenIsDeleted = false;
    NEw_DW.obj.SampleTime = NEw_P.Encoder_SampleTime;
    NEw_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(3UL, 2UL, &NEw_DW.obj.Index);
    NEw_DW.obj.isSetupComplete = true;
    NEw_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
    MW_EncoderReset(NEw_DW.obj.Index);
  }
}

/* Model terminate function */
void NEw_terminate(void)
{
  codertarget_arduinobase_in_g3_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  if (!NEw_DW.obj_j.matlabCodegenIsDeleted) {
    NEw_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output4' */
  if (!NEw_DW.obj_e.matlabCodegenIsDeleted) {
    NEw_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Output4' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &NEw_DW.obj_l;
  if (!NEw_DW.obj_l.matlabCodegenIsDeleted) {
    NEw_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((NEw_DW.obj_l.isInitialized == 1L) && NEw_DW.obj_l.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close(NEw_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &NEw_DW.obj_p;
  if (!NEw_DW.obj_p.matlabCodegenIsDeleted) {
    NEw_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((NEw_DW.obj_p.isInitialized == 1L) && NEw_DW.obj_p.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close(NEw_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
  /* Terminate for MATLABSystem: '<S2>/PWM EN' */
  obj_0 = &NEw_DW.obj_pe;
  if (!NEw_DW.obj_pe.matlabCodegenIsDeleted) {
    NEw_DW.obj_pe.matlabCodegenIsDeleted = true;
    if ((NEw_DW.obj_pe.isInitialized == 1L) && NEw_DW.obj_pe.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(NEw_DW.obj_pe.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(NEw_DW.obj_pe.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM EN' */

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!NEw_DW.obj.matlabCodegenIsDeleted) {
    NEw_DW.obj.matlabCodegenIsDeleted = true;
    if ((NEw_DW.obj.isInitialized == 1L) && NEw_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
