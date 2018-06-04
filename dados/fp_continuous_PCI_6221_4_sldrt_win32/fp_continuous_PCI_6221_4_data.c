/*
 * fp_continuous_PCI_6221_4_data.c
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

/* Block parameters (auto storage) */
P_fp_continuous_PCI_6221_4_T fp_continuous_PCI_6221_4_P = {
  /*  Variable: A
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -0.017404859575843416, 0.0,
    -0.017375920561817897, -232.02520137511431, 0.0, 20.786124708700459, 0.0,
    63.831866309774568, 0.0, 0.0, -0.0023164464704312983, 1.0,
    -0.0071135482677263393, 0.0, 0.0, 57.534432075073113, 0.0,
    57.438769726892971, -755.4249991873927 },

  /*  Variable: K
   * Referenced by: '<Root>/State-Space Controller'
   */
  { -10.000000000007836, -5.4347738508671783, 48.111999688980312,
    7.1732888494921569, 0.32834271246641433 },

  /*  Variable: L
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 17.352678901863374, 0.64016641532693763, 0.40603911077840105,
    2.6140040172282415, -0.19769871163375363, 0.40603911077840105,
    13.619365168336724, 22.627137708521513, 106.07611431993979,
    -4.0900488547408305 },
  5.0,                                 /* Variable: MOTOR_SAT
                                        * Referenced by: '<S4>/Amplifier  Saturation [V]'
                                        */
  2.0943951023931953,                  /* Variable: TH1_BOUND
                                        * Referenced by: '<S4>/protection th1'
                                        */
  0.52359877559829882,                 /* Variable: TH2_BOUND
                                        * Referenced by: '<S4>/protection th2'
                                        */
  6.0,                                 /* Variable: TIME_DELAY
                                        * Referenced by: '<S1>/Step'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S3>/Analog Output1'
                                        */
  0.5,                                 /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S3>/Encoder Input'
                                        */
  1.0,                                 /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S2>/Kb'
                                        */
  -5.0,                                /* Mask Parameter: PIDController_LowerSaturationLimit
                                        * Referenced by: '<S2>/Saturate'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S3>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S3>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
                                        * Referenced by: '<S3>/Real-Time Synchronization'
                                        */
  1.0,                                 /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  5.0,                                 /* Mask Parameter: PIDController_UpperSaturationLimit
                                        * Referenced by: '<S2>/Saturate'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S3>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                        * Referenced by: '<S3>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
                                        * Referenced by: '<S3>/Real-Time Synchronization'
                                        */

  /*  Mask Parameter: EncoderInput_Channels
   * Referenced by: '<S3>/Encoder Input'
   */
  { 0, 1 },
  0,                                   /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S3>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S3>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S3>/Analog Output1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Zero1'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S3>/Encoder Calibration 2*pi//ENCODER_RES  (rad//count)'
                                        */

  /*  Expression: [0 pi]
   * Referenced by: '<S3>/Bias'
   */
  { 0.0, 3.1415926535897931 },
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S5>/Bias2'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S5>/Constant1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S5>/Bias3'
                                        */

  /*  Expression: [1 0]
   * Referenced by: '<S4>/Select ang1'
   */
  { 1.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Zero'
                                        */

  /*  Expression: [0 1]
   * Referenced by: '<S4>/Select ang2'
   */
  { 0.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/State-Space Controller'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Time delay'
                                        */
  0.0                                  /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S2>/Integrator'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_fp_continuous_PCI_6221_4_T fp_continuous_PCI_6221_4_ConstP = {
  /* Expression: A-B*K-L*C
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 0.0, 0.0, 0.0, 0.0, -3333.3674812994445, 0.0, 0.0, 0.0, 0.0,
    -1811.6098422683015, 0.0, 0.0, 0.0, 0.0, 16037.497522341029, 0.0, 0.0, 0.0,
    0.0, 2391.1207784846324, 0.0, 0.0, 0.0, 0.0, 109.44869204563416 },

  /* Expression: A-B*K-L*C
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 17.352678901863374, 0.64016641532693763, 0.40603911077840105,
    2.6140040172282415, -0.19769871163375363, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.40603911077840105, 13.619365168336724, 22.627137708521513,
    106.07611431993979, -4.0900488547408305, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 }
};
