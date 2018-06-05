/*
 * fp_continuous_PCI_6221_3_data.c
 *
 * Code generation for model "fp_continuous_PCI_6221_3".
 *
 * Model version              : 1.123
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri May 11 18:24:23 2018
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fp_continuous_PCI_6221_3.h"
#include "fp_continuous_PCI_6221_3_private.h"

/* Block parameters (auto storage) */
P_fp_continuous_PCI_6221_3_T fp_continuous_PCI_6221_3_P = {
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
  { -34.641016151091804, -14.383246959774381, 118.68312016905818,
    16.892573692018843, 0.37806828114846508 },

  /*  Variable: L
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 17.352678901863374, 0.64016641532693763, 0.40603911077840105,
    2.6140040172282415, -0.19769871163375363, 0.40603911077840105,
    13.619365168336724, 22.627137708521513, 106.07611431993979,
    -4.0900488547408305 },
  5.0,                                 /* Variable: MOTOR_SAT
                                        * Referenced by: '<S3>/Amplifier  Saturation [V]'
                                        */
  2.0943951023931953,                  /* Variable: TH1_BOUND
                                        * Referenced by: '<S3>/protection th1'
                                        */
  0.52359877559829882,                 /* Variable: TH2_BOUND
                                        * Referenced by: '<S3>/protection th2'
                                        */
  6.0,                                 /* Variable: TIME_DELAY
                                        * Referenced by: '<S1>/Step'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S2>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S2>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
                                        * Referenced by: '<S2>/Real-Time Synchronization'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S2>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
                                        * Referenced by: '<S2>/Real-Time Synchronization'
                                        */

  /*  Mask Parameter: EncoderInput_Channels
   * Referenced by: '<S2>/Encoder Input'
   */
  { 0, 1 },
  0,                                   /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Zero1'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/Encoder Calibration 2*pi//ENCODER_RES  (rad//count)'
                                        */

  /*  Expression: [0 pi]
   * Referenced by: '<S2>/Bias'
   */
  { 0.0, 3.1415926535897931 },
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S4>/Bias2'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S4>/Constant1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S4>/Bias3'
                                        */

  /*  Expression: [1 0]
   * Referenced by: '<S3>/Select ang1'
   */
  { 1.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Zero'
                                        */

  /*  Expression: [0 1]
   * Referenced by: '<S3>/Select ang2'
   */
  { 0.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/State-Space Controller'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
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
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  3.0,                                 /* Expression:  3
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -3.0                                 /* Expression: -3
                                        * Referenced by: '<Root>/Saturation'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_fp_continuous_PCI_6221_3_T fp_continuous_PCI_6221_3_ConstP = {
  /* Expression: A-B*K-L*C
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 0.0, 0.0, 0.0, 0.0, -11547.123675712779, 0.0, 0.0, 0.0, 0.0,
    -4794.464769117345, 0.0, 0.0, 0.0, 0.0, 39561.445335038283, 0.0, 0.0, 0.0,
    0.0, 5630.9155820385986, 0.0, 0.0, 0.0, 0.0, 126.02405140900818 },

  /* Expression: A-B*K-L*C
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 17.352678901863374, 0.64016641532693763, 0.40603911077840105,
    2.6140040172282415, -0.19769871163375363, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.40603911077840105, 13.619365168336724, 22.627137708521513,
    106.07611431993979, -4.0900488547408305, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 }
};
