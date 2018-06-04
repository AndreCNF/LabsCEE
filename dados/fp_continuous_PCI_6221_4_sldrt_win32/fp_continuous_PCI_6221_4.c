/*
 * fp_continuous_PCI_6221_4.c
 *
 * Code generation for model "fp_continuous_PCI_6221_4".
 *
 * Model version              : 1.132
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Jun 01 17:34:52 2018
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fp_continuous_PCI_6221_4.h"
#include "fp_continuous_PCI_6221_4_private.h"
#include "fp_continuous_PCI_6221_4_dt.h"

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
B_fp_continuous_PCI_6221_4_T fp_continuous_PCI_6221_4_B;

/* Continuous states */
X_fp_continuous_PCI_6221_4_T fp_continuous_PCI_6221_4_X;

/* Block states (auto storage) */
DW_fp_continuous_PCI_6221_4_T fp_continuous_PCI_6221_4_DW;

/* Real-time model */
RT_MODEL_fp_continuous_PCI_6221_4_T fp_continuous_PCI_6221_4_M_;
RT_MODEL_fp_continuous_PCI_6221_4_T *const fp_continuous_PCI_6221_4_M =
  &fp_continuous_PCI_6221_4_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  fp_continuous_PCI_6221_4_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  fp_continuous_PCI_6221_4_output();
  fp_continuous_PCI_6221_4_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  fp_continuous_PCI_6221_4_output();
  fp_continuous_PCI_6221_4_derivatives();

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
void fp_continuous_PCI_6221_4_output(void)
{
  /* local block i/o variables */
  real_T rtb_Abs2[2];
  int_T ci;
  real_T rtb_Sum;
  real_T rtb_Saturate;
  if (rtmIsMajorTimeStep(fp_continuous_PCI_6221_4_M)) {
    /* set solver stop time */
    if (!(fp_continuous_PCI_6221_4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&fp_continuous_PCI_6221_4_M->solverInfo,
                            ((fp_continuous_PCI_6221_4_M->Timing.clockTickH0 + 1)
        * fp_continuous_PCI_6221_4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&fp_continuous_PCI_6221_4_M->solverInfo,
                            ((fp_continuous_PCI_6221_4_M->Timing.clockTick0 + 1)
        * fp_continuous_PCI_6221_4_M->Timing.stepSize0 +
        fp_continuous_PCI_6221_4_M->Timing.clockTickH0 *
        fp_continuous_PCI_6221_4_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(fp_continuous_PCI_6221_4_M)) {
    fp_continuous_PCI_6221_4_M->Timing.t[0] = rtsiGetT
      (&fp_continuous_PCI_6221_4_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(fp_continuous_PCI_6221_4_M)) {
    /* S-Function Block: <S3>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = fp_continuous_PCI_6221_4_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 2,
                     fp_continuous_PCI_6221_4_P.EncoderInput_Channels,
                     &rtb_Abs2[0], &parm);
    }

    /* Bias: '<S3>/Bias' incorporates:
     *  Gain: '<S3>/Encoder Calibration 2*pi//ENCODER_RES  (rad//count)'
     */
    fp_continuous_PCI_6221_4_B.Bias[0] =
      fp_continuous_PCI_6221_4_P.EncoderCalibration2piENCODER_RESradcount_Gain *
      rtb_Abs2[0] + fp_continuous_PCI_6221_4_P.Bias_Bias[0];
    fp_continuous_PCI_6221_4_B.Bias[1] =
      fp_continuous_PCI_6221_4_P.EncoderCalibration2piENCODER_RESradcount_Gain *
      rtb_Abs2[1] + fp_continuous_PCI_6221_4_P.Bias_Bias[1];

    /* Bias: '<S5>/Bias3' incorporates:
     *  Bias: '<S5>/Bias2'
     *  Constant: '<S5>/Constant1'
     *  Math: '<S5>/Math Function1'
     */
    fp_continuous_PCI_6221_4_B.Bias3 = rt_modd_snf
      (fp_continuous_PCI_6221_4_B.Bias[1] +
       fp_continuous_PCI_6221_4_P.Bias2_Bias,
       fp_continuous_PCI_6221_4_P.Constant1_Value) +
      fp_continuous_PCI_6221_4_P.Bias3_Bias;

    /* Abs: '<S4>/Abs2' */
    rtb_Abs2[0] = fabs(fp_continuous_PCI_6221_4_B.Bias[0]);
    rtb_Abs2[1] = fabs(fp_continuous_PCI_6221_4_B.Bias3);

    /* Gain: '<S4>/Select ang1' */
    fp_continuous_PCI_6221_4_B.Selectang1 =
      fp_continuous_PCI_6221_4_P.Selectang1_Gain[0] * rtb_Abs2[0] +
      fp_continuous_PCI_6221_4_P.Selectang1_Gain[1] * rtb_Abs2[1];

    /* Gain: '<S4>/Select ang2' */
    fp_continuous_PCI_6221_4_B.Selectang2 =
      fp_continuous_PCI_6221_4_P.Selectang2_Gain[0] * rtb_Abs2[0] +
      fp_continuous_PCI_6221_4_P.Selectang2_Gain[1] * rtb_Abs2[1];
  }

  /* StateSpace: '<Root>/State-Space Controller' */
  fp_continuous_PCI_6221_4_B.StateSpaceController = 0.0;
  for (ci = 0; ci < 5; ci++) {
    fp_continuous_PCI_6221_4_B.StateSpaceController +=
      -fp_continuous_PCI_6221_4_P.K[ci] *
      fp_continuous_PCI_6221_4_X.StateSpaceController_CSTATE[ci];
  }

  /* End of StateSpace: '<Root>/State-Space Controller' */

  /* Switch: '<S4>/protection th1' incorporates:
   *  Constant: '<S4>/Zero1'
   *  Switch: '<S4>/protection th2'
   */
  if (fp_continuous_PCI_6221_4_B.Selectang1 >=
      fp_continuous_PCI_6221_4_P.TH1_BOUND) {
    rtb_Sum = fp_continuous_PCI_6221_4_P.Zero1_Value;
  } else if (fp_continuous_PCI_6221_4_B.Selectang2 >=
             fp_continuous_PCI_6221_4_P.TH2_BOUND) {
    /* Switch: '<S4>/protection th2' incorporates:
     *  Constant: '<S4>/Zero'
     */
    rtb_Sum = fp_continuous_PCI_6221_4_P.Zero_Value;
  } else {
    rtb_Sum = fp_continuous_PCI_6221_4_B.StateSpaceController;
  }

  /* End of Switch: '<S4>/protection th1' */

  /* Saturate: '<S4>/Amplifier  Saturation [V]' */
  if (rtb_Sum > fp_continuous_PCI_6221_4_P.MOTOR_SAT) {
    rtb_Sum = fp_continuous_PCI_6221_4_P.MOTOR_SAT;
  } else {
    if (rtb_Sum < -fp_continuous_PCI_6221_4_P.MOTOR_SAT) {
      rtb_Sum = -fp_continuous_PCI_6221_4_P.MOTOR_SAT;
    }
  }

  /* Gain: '<S3>/Gain' incorporates:
   *  Saturate: '<S4>/Amplifier  Saturation [V]'
   */
  fp_continuous_PCI_6221_4_B.Gain = fp_continuous_PCI_6221_4_P.Gain_Gain *
    rtb_Sum;
  if (rtmIsMajorTimeStep(fp_continuous_PCI_6221_4_M)) {
    /* S-Function Block: <S3>/Analog Output1 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          fp_continuous_PCI_6221_4_P.AnalogOutput1_RangeMode;
        parm.rangeidx = fp_continuous_PCI_6221_4_P.AnalogOutput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &fp_continuous_PCI_6221_4_P.AnalogOutput1_Channels,
                       &fp_continuous_PCI_6221_4_B.Gain, &parm);
      }
    }

    /* S-Function Block: <S3>/Real-Time Synchronization */
    {
    }
  }

  /* Step: '<S1>/Step' */
  if (fp_continuous_PCI_6221_4_M->Timing.t[0] <
      fp_continuous_PCI_6221_4_P.TIME_DELAY) {
    rtb_Sum = fp_continuous_PCI_6221_4_P.Step_Y0;
  } else {
    rtb_Sum = fp_continuous_PCI_6221_4_P.Step_YFinal;
  }

  /* End of Step: '<S1>/Step' */

  /* Switch: '<S1>/Time delay' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (rtb_Sum > fp_continuous_PCI_6221_4_P.Timedelay_Threshold) {
    fp_continuous_PCI_6221_4_B.Timedelay[0] = fp_continuous_PCI_6221_4_B.Bias[0];
    fp_continuous_PCI_6221_4_B.Timedelay[1] = fp_continuous_PCI_6221_4_B.Bias3;
  } else {
    fp_continuous_PCI_6221_4_B.Timedelay[0] =
      fp_continuous_PCI_6221_4_P.Constant_Value;
    fp_continuous_PCI_6221_4_B.Timedelay[1] =
      fp_continuous_PCI_6221_4_P.Constant_Value;
  }

  /* End of Switch: '<S1>/Time delay' */
  if (rtmIsMajorTimeStep(fp_continuous_PCI_6221_4_M)) {
  }

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Proportional Gain'
   *  Integrator: '<S2>/Integrator'
   */
  rtb_Sum = fp_continuous_PCI_6221_4_P.PIDController_P *
    fp_continuous_PCI_6221_4_B.Timedelay[0] +
    fp_continuous_PCI_6221_4_X.Integrator_CSTATE;

  /* Saturate: '<S2>/Saturate' */
  if (rtb_Sum > fp_continuous_PCI_6221_4_P.PIDController_UpperSaturationLimit) {
    rtb_Saturate = fp_continuous_PCI_6221_4_P.PIDController_UpperSaturationLimit;
  } else if (rtb_Sum <
             fp_continuous_PCI_6221_4_P.PIDController_LowerSaturationLimit) {
    rtb_Saturate = fp_continuous_PCI_6221_4_P.PIDController_LowerSaturationLimit;
  } else {
    rtb_Saturate = rtb_Sum;
  }

  /* End of Saturate: '<S2>/Saturate' */

  /* Sum: '<S2>/SumI1' incorporates:
   *  Gain: '<S2>/Integral Gain'
   *  Gain: '<S2>/Kb'
   *  Sum: '<S2>/SumI2'
   */
  fp_continuous_PCI_6221_4_B.SumI1 = (rtb_Saturate - rtb_Sum) *
    fp_continuous_PCI_6221_4_P.PIDController_Kb +
    fp_continuous_PCI_6221_4_P.PIDController_I *
    fp_continuous_PCI_6221_4_B.Timedelay[0];

  /* SignalConversion: '<Root>/TmpSignal ConversionAtState-Space ControllerInport1' */
  fp_continuous_PCI_6221_4_B.TmpSignalConversionAtStateSpaceControllerInport1[0]
    = rtb_Saturate;
  fp_continuous_PCI_6221_4_B.TmpSignalConversionAtStateSpaceControllerInport1[1]
    = fp_continuous_PCI_6221_4_B.Timedelay[1];
}

/* Model update function */
void fp_continuous_PCI_6221_4_update(void)
{
  if (rtmIsMajorTimeStep(fp_continuous_PCI_6221_4_M)) {
    rt_ertODEUpdateContinuousStates(&fp_continuous_PCI_6221_4_M->solverInfo);
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
  if (!(++fp_continuous_PCI_6221_4_M->Timing.clockTick0)) {
    ++fp_continuous_PCI_6221_4_M->Timing.clockTickH0;
  }

  fp_continuous_PCI_6221_4_M->Timing.t[0] = rtsiGetSolverStopTime
    (&fp_continuous_PCI_6221_4_M->solverInfo);

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
    if (!(++fp_continuous_PCI_6221_4_M->Timing.clockTick1)) {
      ++fp_continuous_PCI_6221_4_M->Timing.clockTickH1;
    }

    fp_continuous_PCI_6221_4_M->Timing.t[1] =
      fp_continuous_PCI_6221_4_M->Timing.clockTick1 *
      fp_continuous_PCI_6221_4_M->Timing.stepSize1 +
      fp_continuous_PCI_6221_4_M->Timing.clockTickH1 *
      fp_continuous_PCI_6221_4_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void fp_continuous_PCI_6221_4_derivatives(void)
{
  int_T is;
  int_T ci;
  int_T ci_0;
  XDot_fp_continuous_PCI_6221_4_T *_rtXdot;
  _rtXdot = ((XDot_fp_continuous_PCI_6221_4_T *)
             fp_continuous_PCI_6221_4_M->ModelData.derivs);

  /* Derivatives for StateSpace: '<Root>/State-Space Controller' */
  for (is = 0; is < 5; is++) {
    _rtXdot->StateSpaceController_CSTATE[is] = 0.0;
    for (ci = 0; ci < 5; ci++) {
      ci_0 = ci * 5 + is;
      _rtXdot->StateSpaceController_CSTATE[is] +=
        ((fp_continuous_PCI_6221_4_P.A[ci_0] -
          fp_continuous_PCI_6221_4_ConstP.StateSpaceController_rtw_collapsed_sub_expr_10
          [ci_0]) -
         fp_continuous_PCI_6221_4_ConstP.StateSpaceController_rtw_collapsed_sub_expr_11
         [ci_0]) * fp_continuous_PCI_6221_4_X.StateSpaceController_CSTATE[ci];
    }

    _rtXdot->StateSpaceController_CSTATE[is] += fp_continuous_PCI_6221_4_P.L[is]
      * fp_continuous_PCI_6221_4_B.TmpSignalConversionAtStateSpaceControllerInport1
      [0];
    _rtXdot->StateSpaceController_CSTATE[is] += fp_continuous_PCI_6221_4_P.L[5 +
      is] *
      fp_continuous_PCI_6221_4_B.TmpSignalConversionAtStateSpaceControllerInport1
      [1];
  }

  /* End of Derivatives for StateSpace: '<Root>/State-Space Controller' */

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = fp_continuous_PCI_6221_4_B.SumI1;
}

/* Model initialize function */
void fp_continuous_PCI_6221_4_initialize(void)
{
  /* S-Function Block: <S3>/Analog Output1 */

  /* no initial value should be set */
  {
    int_T is;

    /* S-Function Block: <S3>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = fp_continuous_PCI_6221_4_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 2,
                     fp_continuous_PCI_6221_4_P.EncoderInput_Channels, NULL,
                     &parm);
    }

    /* InitializeConditions for StateSpace: '<Root>/State-Space Controller' */
    for (is = 0; is < 5; is++) {
      fp_continuous_PCI_6221_4_X.StateSpaceController_CSTATE[is] =
        fp_continuous_PCI_6221_4_P.StateSpaceController_X0;
    }

    /* End of InitializeConditions for StateSpace: '<Root>/State-Space Controller' */

    /* InitializeConditions for Integrator: '<S2>/Integrator' */
    fp_continuous_PCI_6221_4_X.Integrator_CSTATE =
      fp_continuous_PCI_6221_4_P.Integrator_IC;
  }
}

/* Model terminate function */
void fp_continuous_PCI_6221_4_terminate(void)
{
  /* S-Function Block: <S3>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) fp_continuous_PCI_6221_4_P.AnalogOutput1_RangeMode;
      parm.rangeidx = fp_continuous_PCI_6221_4_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &fp_continuous_PCI_6221_4_P.AnalogOutput1_Channels,
                     &fp_continuous_PCI_6221_4_P.AnalogOutput1_FinalValue, &parm);
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
  fp_continuous_PCI_6221_4_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  fp_continuous_PCI_6221_4_update();
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
  fp_continuous_PCI_6221_4_initialize();
}

void MdlTerminate(void)
{
  fp_continuous_PCI_6221_4_terminate();
}

/* Registration function */
RT_MODEL_fp_continuous_PCI_6221_4_T *fp_continuous_PCI_6221_4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  fp_continuous_PCI_6221_4_P.EncoderInput_InputFilter = rtInf;
  fp_continuous_PCI_6221_4_P.EncoderInput_MaxMissedTicks = rtInf;
  fp_continuous_PCI_6221_4_P.AnalogOutput1_MaxMissedTicks = rtInf;
  fp_continuous_PCI_6221_4_P.RealTimeSynchronization_MaxMissedTicks = rtInf;

  /* initialize real-time model */
  (void) memset((void *)fp_continuous_PCI_6221_4_M, 0,
                sizeof(RT_MODEL_fp_continuous_PCI_6221_4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&fp_continuous_PCI_6221_4_M->solverInfo,
                          &fp_continuous_PCI_6221_4_M->Timing.simTimeStep);
    rtsiSetTPtr(&fp_continuous_PCI_6221_4_M->solverInfo, &rtmGetTPtr
                (fp_continuous_PCI_6221_4_M));
    rtsiSetStepSizePtr(&fp_continuous_PCI_6221_4_M->solverInfo,
                       &fp_continuous_PCI_6221_4_M->Timing.stepSize0);
    rtsiSetdXPtr(&fp_continuous_PCI_6221_4_M->solverInfo,
                 &fp_continuous_PCI_6221_4_M->ModelData.derivs);
    rtsiSetContStatesPtr(&fp_continuous_PCI_6221_4_M->solverInfo, (real_T **)
                         &fp_continuous_PCI_6221_4_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&fp_continuous_PCI_6221_4_M->solverInfo,
      &fp_continuous_PCI_6221_4_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&fp_continuous_PCI_6221_4_M->solverInfo,
                          (&rtmGetErrorStatus(fp_continuous_PCI_6221_4_M)));
    rtsiSetRTModelPtr(&fp_continuous_PCI_6221_4_M->solverInfo,
                      fp_continuous_PCI_6221_4_M);
  }

  rtsiSetSimTimeStep(&fp_continuous_PCI_6221_4_M->solverInfo, MAJOR_TIME_STEP);
  fp_continuous_PCI_6221_4_M->ModelData.intgData.y =
    fp_continuous_PCI_6221_4_M->ModelData.odeY;
  fp_continuous_PCI_6221_4_M->ModelData.intgData.f[0] =
    fp_continuous_PCI_6221_4_M->ModelData.odeF[0];
  fp_continuous_PCI_6221_4_M->ModelData.intgData.f[1] =
    fp_continuous_PCI_6221_4_M->ModelData.odeF[1];
  fp_continuous_PCI_6221_4_M->ModelData.intgData.f[2] =
    fp_continuous_PCI_6221_4_M->ModelData.odeF[2];
  fp_continuous_PCI_6221_4_M->ModelData.contStates = ((real_T *)
    &fp_continuous_PCI_6221_4_X);
  rtsiSetSolverData(&fp_continuous_PCI_6221_4_M->solverInfo, (void *)
                    &fp_continuous_PCI_6221_4_M->ModelData.intgData);
  rtsiSetSolverName(&fp_continuous_PCI_6221_4_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = fp_continuous_PCI_6221_4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    fp_continuous_PCI_6221_4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    fp_continuous_PCI_6221_4_M->Timing.sampleTimes =
      (&fp_continuous_PCI_6221_4_M->Timing.sampleTimesArray[0]);
    fp_continuous_PCI_6221_4_M->Timing.offsetTimes =
      (&fp_continuous_PCI_6221_4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    fp_continuous_PCI_6221_4_M->Timing.sampleTimes[0] = (0.0);
    fp_continuous_PCI_6221_4_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    fp_continuous_PCI_6221_4_M->Timing.offsetTimes[0] = (0.0);
    fp_continuous_PCI_6221_4_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(fp_continuous_PCI_6221_4_M,
             &fp_continuous_PCI_6221_4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = fp_continuous_PCI_6221_4_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    fp_continuous_PCI_6221_4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(fp_continuous_PCI_6221_4_M, 60.0);
  fp_continuous_PCI_6221_4_M->Timing.stepSize0 = 0.001;
  fp_continuous_PCI_6221_4_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  fp_continuous_PCI_6221_4_M->Sizes.checksums[0] = (1212786068U);
  fp_continuous_PCI_6221_4_M->Sizes.checksums[1] = (657300336U);
  fp_continuous_PCI_6221_4_M->Sizes.checksums[2] = (4170352396U);
  fp_continuous_PCI_6221_4_M->Sizes.checksums[3] = (4160496604U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    fp_continuous_PCI_6221_4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(fp_continuous_PCI_6221_4_M->extModeInfo,
      &fp_continuous_PCI_6221_4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(fp_continuous_PCI_6221_4_M->extModeInfo,
                        fp_continuous_PCI_6221_4_M->Sizes.checksums);
    rteiSetTPtr(fp_continuous_PCI_6221_4_M->extModeInfo, rtmGetTPtr
                (fp_continuous_PCI_6221_4_M));
  }

  fp_continuous_PCI_6221_4_M->solverInfoPtr =
    (&fp_continuous_PCI_6221_4_M->solverInfo);
  fp_continuous_PCI_6221_4_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&fp_continuous_PCI_6221_4_M->solverInfo, 0.001);
  rtsiSetSolverMode(&fp_continuous_PCI_6221_4_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  fp_continuous_PCI_6221_4_M->ModelData.blockIO = ((void *)
    &fp_continuous_PCI_6221_4_B);
  (void) memset(((void *) &fp_continuous_PCI_6221_4_B), 0,
                sizeof(B_fp_continuous_PCI_6221_4_T));

  /* parameters */
  fp_continuous_PCI_6221_4_M->ModelData.defaultParam = ((real_T *)
    &fp_continuous_PCI_6221_4_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &fp_continuous_PCI_6221_4_X;
    fp_continuous_PCI_6221_4_M->ModelData.contStates = (x);
    (void) memset((void *)&fp_continuous_PCI_6221_4_X, 0,
                  sizeof(X_fp_continuous_PCI_6221_4_T));
  }

  /* states (dwork) */
  fp_continuous_PCI_6221_4_M->ModelData.dwork = ((void *)
    &fp_continuous_PCI_6221_4_DW);
  (void) memset((void *)&fp_continuous_PCI_6221_4_DW, 0,
                sizeof(DW_fp_continuous_PCI_6221_4_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    fp_continuous_PCI_6221_4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  fp_continuous_PCI_6221_4_M->Sizes.numContStates = (6);/* Number of continuous states */
  fp_continuous_PCI_6221_4_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  fp_continuous_PCI_6221_4_M->Sizes.numY = (0);/* Number of model outputs */
  fp_continuous_PCI_6221_4_M->Sizes.numU = (0);/* Number of model inputs */
  fp_continuous_PCI_6221_4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  fp_continuous_PCI_6221_4_M->Sizes.numSampTimes = (2);/* Number of sample times */
  fp_continuous_PCI_6221_4_M->Sizes.numBlocks = (34);/* Number of blocks */
  fp_continuous_PCI_6221_4_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  fp_continuous_PCI_6221_4_M->Sizes.numBlockPrms = (81);/* Sum of parameter "widths" */
  return fp_continuous_PCI_6221_4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
