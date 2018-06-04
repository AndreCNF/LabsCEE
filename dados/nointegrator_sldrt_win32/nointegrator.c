/*
 * nointegrator.c
 *
 * Code generation for model "nointegrator".
 *
 * Model version              : 1.124
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Jun 01 16:40:20 2018
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "nointegrator.h"
#include "nointegrator_private.h"
#include "nointegrator_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double RTWinBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  2.0,
};

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
B_nointegrator_T nointegrator_B;

/* Continuous states */
X_nointegrator_T nointegrator_X;

/* Block states (auto storage) */
DW_nointegrator_T nointegrator_DW;

/* Real-time model */
RT_MODEL_nointegrator_T nointegrator_M_;
RT_MODEL_nointegrator_T *const nointegrator_M = &nointegrator_M_;

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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  nointegrator_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  nointegrator_output();
  nointegrator_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  nointegrator_output();
  nointegrator_derivatives();

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

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
      y = 0.0;
    } else {
      y = (tmp - floor(tmp)) * u1;
    }
  }

  return y;
}

/* Model output function */
void nointegrator_output(void)
{
  /* local block i/o variables */
  real_T rtb_Abs2[2];
  int_T ci;
  real_T rtb_Step;
  if (rtmIsMajorTimeStep(nointegrator_M)) {
    /* set solver stop time */
    if (!(nointegrator_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&nointegrator_M->solverInfo,
                            ((nointegrator_M->Timing.clockTickH0 + 1) *
        nointegrator_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&nointegrator_M->solverInfo,
                            ((nointegrator_M->Timing.clockTick0 + 1) *
        nointegrator_M->Timing.stepSize0 + nointegrator_M->Timing.clockTickH0 *
        nointegrator_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(nointegrator_M)) {
    nointegrator_M->Timing.t[0] = rtsiGetT(&nointegrator_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(nointegrator_M)) {
    /* S-Function Block: <S2>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = nointegrator_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 2,
                     nointegrator_P.EncoderInput_Channels, &rtb_Abs2[0], &parm);
    }

    /* Bias: '<S2>/Bias' incorporates:
     *  Gain: '<S2>/Encoder Calibration 2*pi//ENCODER_RES  (rad//count)'
     */
    nointegrator_B.Bias[0] =
      nointegrator_P.EncoderCalibration2piENCODER_RESradcount_Gain * rtb_Abs2[0]
      + nointegrator_P.Bias_Bias[0];
    nointegrator_B.Bias[1] =
      nointegrator_P.EncoderCalibration2piENCODER_RESradcount_Gain * rtb_Abs2[1]
      + nointegrator_P.Bias_Bias[1];

    /* Bias: '<S4>/Bias3' incorporates:
     *  Bias: '<S4>/Bias2'
     *  Constant: '<S4>/Constant1'
     *  Math: '<S4>/Math Function1'
     */
    nointegrator_B.Bias3 = rt_modd_snf(nointegrator_B.Bias[1] +
      nointegrator_P.Bias2_Bias, nointegrator_P.Constant1_Value) +
      nointegrator_P.Bias3_Bias;

    /* Abs: '<S3>/Abs2' */
    rtb_Abs2[0] = fabs(nointegrator_B.Bias[0]);
    rtb_Abs2[1] = fabs(nointegrator_B.Bias3);

    /* Gain: '<S3>/Select ang1' */
    nointegrator_B.Selectang1 = nointegrator_P.Selectang1_Gain[0] * rtb_Abs2[0]
      + nointegrator_P.Selectang1_Gain[1] * rtb_Abs2[1];

    /* Gain: '<S3>/Select ang2' */
    nointegrator_B.Selectang2 = nointegrator_P.Selectang2_Gain[0] * rtb_Abs2[0]
      + nointegrator_P.Selectang2_Gain[1] * rtb_Abs2[1];
  }

  /* StateSpace: '<Root>/State-Space Controller' */
  nointegrator_B.StateSpaceController = 0.0;
  for (ci = 0; ci < 5; ci++) {
    nointegrator_B.StateSpaceController += -nointegrator_P.K[ci] *
      nointegrator_X.StateSpaceController_CSTATE[ci];
  }

  /* End of StateSpace: '<Root>/State-Space Controller' */

  /* Backlash: '<Root>/Backlash' */
  rtb_Step = nointegrator_P.Backlash_BacklashWidth / 2.0;
  if (nointegrator_B.StateSpaceController < nointegrator_DW.PrevY - rtb_Step) {
    nointegrator_B.Backlash = nointegrator_B.StateSpaceController + rtb_Step;
  } else if (nointegrator_B.StateSpaceController <= nointegrator_DW.PrevY +
             rtb_Step) {
    nointegrator_B.Backlash = nointegrator_DW.PrevY;
  } else {
    nointegrator_B.Backlash = nointegrator_B.StateSpaceController - rtb_Step;
  }

  /* End of Backlash: '<Root>/Backlash' */

  /* Switch: '<S3>/protection th1' incorporates:
   *  Constant: '<S3>/Zero1'
   *  Switch: '<S3>/protection th2'
   */
  if (nointegrator_B.Selectang1 >= nointegrator_P.TH1_BOUND) {
    rtb_Step = nointegrator_P.Zero1_Value;
  } else if (nointegrator_B.Selectang2 >= nointegrator_P.TH2_BOUND) {
    /* Switch: '<S3>/protection th2' incorporates:
     *  Constant: '<S3>/Zero'
     */
    rtb_Step = nointegrator_P.Zero_Value;
  } else {
    rtb_Step = nointegrator_B.Backlash;
  }

  /* End of Switch: '<S3>/protection th1' */

  /* Saturate: '<S3>/Amplifier  Saturation [V]' */
  if (rtb_Step > nointegrator_P.MOTOR_SAT) {
    rtb_Step = nointegrator_P.MOTOR_SAT;
  } else {
    if (rtb_Step < -nointegrator_P.MOTOR_SAT) {
      rtb_Step = -nointegrator_P.MOTOR_SAT;
    }
  }

  /* Gain: '<S2>/Gain' incorporates:
   *  Saturate: '<S3>/Amplifier  Saturation [V]'
   */
  nointegrator_B.Gain = nointegrator_P.Gain_Gain * rtb_Step;
  if (rtmIsMajorTimeStep(nointegrator_M)) {
    /* S-Function Block: <S2>/Analog Output1 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) nointegrator_P.AnalogOutput1_RangeMode;
        parm.rangeidx = nointegrator_P.AnalogOutput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &nointegrator_P.AnalogOutput1_Channels,
                       &nointegrator_B.Gain, &parm);
      }
    }

    /* S-Function Block: <S2>/Real-Time Synchronization */
    {
    }
  }

  /* Step: '<S1>/Step' */
  if (nointegrator_M->Timing.t[0] < nointegrator_P.TIME_DELAY) {
    rtb_Step = nointegrator_P.Step_Y0;
  } else {
    rtb_Step = nointegrator_P.Step_YFinal;
  }

  /* End of Step: '<S1>/Step' */

  /* Switch: '<S1>/Time delay' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (rtb_Step > nointegrator_P.Timedelay_Threshold) {
    nointegrator_B.Timedelay[0] = nointegrator_B.Bias[0];
    nointegrator_B.Timedelay[1] = nointegrator_B.Bias3;
  } else {
    nointegrator_B.Timedelay[0] = nointegrator_P.Constant_Value;
    nointegrator_B.Timedelay[1] = nointegrator_P.Constant_Value;
  }

  /* End of Switch: '<S1>/Time delay' */
  if (rtmIsMajorTimeStep(nointegrator_M)) {
  }
}

/* Model update function */
void nointegrator_update(void)
{
  /* Update for Backlash: '<Root>/Backlash' */
  nointegrator_DW.PrevY = nointegrator_B.Backlash;
  if (rtmIsMajorTimeStep(nointegrator_M)) {
    rt_ertODEUpdateContinuousStates(&nointegrator_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++nointegrator_M->Timing.clockTick0)) {
    ++nointegrator_M->Timing.clockTickH0;
  }

  nointegrator_M->Timing.t[0] = rtsiGetSolverStopTime
    (&nointegrator_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++nointegrator_M->Timing.clockTick1)) {
      ++nointegrator_M->Timing.clockTickH1;
    }

    nointegrator_M->Timing.t[1] = nointegrator_M->Timing.clockTick1 *
      nointegrator_M->Timing.stepSize1 + nointegrator_M->Timing.clockTickH1 *
      nointegrator_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void nointegrator_derivatives(void)
{
  int_T is;
  int_T ci;
  int_T ci_0;
  XDot_nointegrator_T *_rtXdot;
  _rtXdot = ((XDot_nointegrator_T *) nointegrator_M->ModelData.derivs);

  /* Derivatives for StateSpace: '<Root>/State-Space Controller' */
  for (is = 0; is < 5; is++) {
    _rtXdot->StateSpaceController_CSTATE[is] = 0.0;
    for (ci = 0; ci < 5; ci++) {
      ci_0 = ci * 5 + is;
      _rtXdot->StateSpaceController_CSTATE[is] += ((nointegrator_P.A[ci_0] -
        nointegrator_ConstP.StateSpaceController_rtw_collapsed_sub_expr_10[ci_0])
        - nointegrator_ConstP.StateSpaceController_rtw_collapsed_sub_expr_11[ci_0])
        * nointegrator_X.StateSpaceController_CSTATE[ci];
    }

    _rtXdot->StateSpaceController_CSTATE[is] += nointegrator_P.L[is] *
      nointegrator_B.Timedelay[0];
    _rtXdot->StateSpaceController_CSTATE[is] += nointegrator_P.L[5 + is] *
      nointegrator_B.Timedelay[1];
  }

  /* End of Derivatives for StateSpace: '<Root>/State-Space Controller' */
}

/* Model initialize function */
void nointegrator_initialize(void)
{
  /* S-Function Block: <S2>/Analog Output1 */

  /* no initial value should be set */
  {
    int_T is;

    /* S-Function Block: <S2>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = nointegrator_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 2,
                     nointegrator_P.EncoderInput_Channels, NULL, &parm);
    }

    /* InitializeConditions for StateSpace: '<Root>/State-Space Controller' */
    for (is = 0; is < 5; is++) {
      nointegrator_X.StateSpaceController_CSTATE[is] =
        nointegrator_P.StateSpaceController_X0;
    }

    /* End of InitializeConditions for StateSpace: '<Root>/State-Space Controller' */

    /* InitializeConditions for Backlash: '<Root>/Backlash' */
    nointegrator_DW.PrevY = nointegrator_P.Backlash_InitialOutput;
  }
}

/* Model terminate function */
void nointegrator_terminate(void)
{
  /* S-Function Block: <S2>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) nointegrator_P.AnalogOutput1_RangeMode;
      parm.rangeidx = nointegrator_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &nointegrator_P.AnalogOutput1_Channels,
                     &nointegrator_P.AnalogOutput1_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  nointegrator_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  nointegrator_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  nointegrator_initialize();
}

void MdlTerminate(void)
{
  nointegrator_terminate();
}

/* Registration function */
RT_MODEL_nointegrator_T *nointegrator(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  nointegrator_P.EncoderInput_InputFilter = rtInf;
  nointegrator_P.EncoderInput_MaxMissedTicks = rtInf;
  nointegrator_P.AnalogOutput1_MaxMissedTicks = rtInf;
  nointegrator_P.RealTimeSynchronization_MaxMissedTicks = rtInf;

  /* initialize real-time model */
  (void) memset((void *)nointegrator_M, 0,
                sizeof(RT_MODEL_nointegrator_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&nointegrator_M->solverInfo,
                          &nointegrator_M->Timing.simTimeStep);
    rtsiSetTPtr(&nointegrator_M->solverInfo, &rtmGetTPtr(nointegrator_M));
    rtsiSetStepSizePtr(&nointegrator_M->solverInfo,
                       &nointegrator_M->Timing.stepSize0);
    rtsiSetdXPtr(&nointegrator_M->solverInfo, &nointegrator_M->ModelData.derivs);
    rtsiSetContStatesPtr(&nointegrator_M->solverInfo, (real_T **)
                         &nointegrator_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&nointegrator_M->solverInfo,
      &nointegrator_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&nointegrator_M->solverInfo, (&rtmGetErrorStatus
      (nointegrator_M)));
    rtsiSetRTModelPtr(&nointegrator_M->solverInfo, nointegrator_M);
  }

  rtsiSetSimTimeStep(&nointegrator_M->solverInfo, MAJOR_TIME_STEP);
  nointegrator_M->ModelData.intgData.y = nointegrator_M->ModelData.odeY;
  nointegrator_M->ModelData.intgData.f[0] = nointegrator_M->ModelData.odeF[0];
  nointegrator_M->ModelData.intgData.f[1] = nointegrator_M->ModelData.odeF[1];
  nointegrator_M->ModelData.intgData.f[2] = nointegrator_M->ModelData.odeF[2];
  nointegrator_M->ModelData.contStates = ((real_T *) &nointegrator_X);
  rtsiSetSolverData(&nointegrator_M->solverInfo, (void *)
                    &nointegrator_M->ModelData.intgData);
  rtsiSetSolverName(&nointegrator_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = nointegrator_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    nointegrator_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    nointegrator_M->Timing.sampleTimes =
      (&nointegrator_M->Timing.sampleTimesArray[0]);
    nointegrator_M->Timing.offsetTimes =
      (&nointegrator_M->Timing.offsetTimesArray[0]);

    /* task periods */
    nointegrator_M->Timing.sampleTimes[0] = (0.0);
    nointegrator_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    nointegrator_M->Timing.offsetTimes[0] = (0.0);
    nointegrator_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(nointegrator_M, &nointegrator_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = nointegrator_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    nointegrator_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(nointegrator_M, 60.0);
  nointegrator_M->Timing.stepSize0 = 0.001;
  nointegrator_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  nointegrator_M->Sizes.checksums[0] = (21386234U);
  nointegrator_M->Sizes.checksums[1] = (3183576253U);
  nointegrator_M->Sizes.checksums[2] = (1336835628U);
  nointegrator_M->Sizes.checksums[3] = (2660123903U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    nointegrator_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(nointegrator_M->extModeInfo,
      &nointegrator_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(nointegrator_M->extModeInfo,
                        nointegrator_M->Sizes.checksums);
    rteiSetTPtr(nointegrator_M->extModeInfo, rtmGetTPtr(nointegrator_M));
  }

  nointegrator_M->solverInfoPtr = (&nointegrator_M->solverInfo);
  nointegrator_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&nointegrator_M->solverInfo, 0.001);
  rtsiSetSolverMode(&nointegrator_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  nointegrator_M->ModelData.blockIO = ((void *) &nointegrator_B);
  (void) memset(((void *) &nointegrator_B), 0,
                sizeof(B_nointegrator_T));

  /* parameters */
  nointegrator_M->ModelData.defaultParam = ((real_T *)&nointegrator_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &nointegrator_X;
    nointegrator_M->ModelData.contStates = (x);
    (void) memset((void *)&nointegrator_X, 0,
                  sizeof(X_nointegrator_T));
  }

  /* states (dwork) */
  nointegrator_M->ModelData.dwork = ((void *) &nointegrator_DW);
  (void) memset((void *)&nointegrator_DW, 0,
                sizeof(DW_nointegrator_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    nointegrator_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  nointegrator_M->Sizes.numContStates = (5);/* Number of continuous states */
  nointegrator_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  nointegrator_M->Sizes.numY = (0);    /* Number of model outputs */
  nointegrator_M->Sizes.numU = (0);    /* Number of model inputs */
  nointegrator_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  nointegrator_M->Sizes.numSampTimes = (2);/* Number of sample times */
  nointegrator_M->Sizes.numBlocks = (26);/* Number of blocks */
  nointegrator_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  nointegrator_M->Sizes.numBlockPrms = (77);/* Sum of parameter "widths" */
  return nointegrator_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
