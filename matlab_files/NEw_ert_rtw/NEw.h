/*
 * File: NEw.h
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

#ifndef RTW_HEADER_NEw_h_
#define RTW_HEADER_NEw_h_
#ifndef NEw_COMMON_INCLUDES_
#define NEw_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_AnalogIn.h"
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* NEw_COMMON_INCLUDES_ */

#include "NEw_types.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  int64_T RPMforWL;                    /* '<Root>/Gain1' */
  real_T TransferFcn1;                 /* '<Root>/Transfer Fcn1' */
  real_T Vin;                          /* '<Root>/Gain2' */
  real_T Delay1;                       /* '<S1>/Delay1' */
  real_T Divide;                       /* '<S1>/Divide' */
  real_T Add;                          /* '<S1>/Add' */
  real_T TransferFcn;                  /* '<Root>/Transfer Fcn' */
  int32_T Privousestate;               /* '<Root>/Delay' */
  int32_T currentstatePoistion;        /* '<Root>/Encoder' */
} B_NEw_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_g_T obj; /* '<Root>/Encoder' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_e;/* '<S2>/Digital Output4' */
  codertarget_arduinobase_block_T obj_j;/* '<S2>/Digital Output' */
  codertarget_arduinobase_in_g3_T obj_pe;/* '<S2>/PWM EN' */
  real_T Delay1_DSTATE;                /* '<S1>/Delay1' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S3>/fromWS_Signal 1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  int32_T Delay_DSTATE;                /* '<Root>/Delay' */
  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S3>/fromWS_Signal 1' */
} DW_NEw_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
} X_NEw_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
} XDot_NEw_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
} XDis_NEw_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_NEw_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<Root>/Encoder'
                                        */
  real_T Constant_Value;               /* Expression: 4
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 5
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T Constant1_Value_k;            /* Expression: 5
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 5
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/5
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 255/5
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 15/1023
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 255/5
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T Constant4_Value_g;            /* Expression: 0.01
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0.1
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  int32_T Delay_InitialCondition;  /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
  int32_T Gain1_Gain_o;                /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<Root>/Gain1'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_NEw_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_NEw_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_NEw_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_NEw_T NEw_P;

/* Block signals (default storage) */
extern B_NEw_T NEw_B;

/* Continuous states (default storage) */
extern X_NEw_T NEw_X;

/* Block states (default storage) */
extern DW_NEw_T NEw_DW;

/* Model entry point functions */
extern void NEw_initialize(void);
extern void NEw_step(void);
extern void NEw_terminate(void);

/* Real-time Model object */
extern RT_MODEL_NEw_T *const NEw_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'NEw'
 * '<S1>'   : 'NEw/Filter'
 * '<S2>'   : 'NEw/Motor Driver (H-bridge)'
 * '<S3>'   : 'NEw/Signal Editor'
 * '<S4>'   : 'NEw/Motor Driver (H-bridge)/CCW'
 * '<S5>'   : 'NEw/Motor Driver (H-bridge)/CW'
 * '<S6>'   : 'NEw/Motor Driver (H-bridge)/Stop'
 */
#endif                                 /* RTW_HEADER_NEw_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
