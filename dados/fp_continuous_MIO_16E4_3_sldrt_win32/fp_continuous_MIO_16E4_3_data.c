/*
 * fp_continuous_MIO_16E4_3_data.c
 *
 * Code generation for model "fp_continuous_MIO_16E4_3".
 *
 * Model version              : 1.117
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri May 11 16:15:35 2018
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fp_continuous_MIO_16E4_3.h"
#include "fp_continuous_MIO_16E4_3_private.h"

/* Block parameters (auto storage) */
P_fp_continuous_MIO_16E4_3_T fp_continuous_MIO_16E4_3_P = {
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
  { -14.142135623748009, -6.9519705089212112, 60.321424011894621,
    8.8400105846795167, 0.33808699377880785 },

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
  0.0,                                 /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<S2>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: CounterInput_MaxMissedTicks
                                        * Referenced by: '<S2>/Counter Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<S2>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
                                        * Referenced by: '<S2>/Real-Time Synchronization'
                                        */
  0.0,                                 /* Mask Parameter: CounterInput_YieldWhenWaiting
                                        * Referenced by: '<S2>/Counter Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<S2>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
                                        * Referenced by: '<S2>/Real-Time Synchronization'
                                        */

  /*  Mask Parameter: CounterInput_Channels
   * Referenced by: '<S2>/Counter Input'
   */
  { 0, 1 },
  0,                                   /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<S2>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: CounterInput_CounterEdge
                                        * Referenced by: '<S2>/Counter Input'
                                        */
  0,                                   /* Mask Parameter: CounterInput_CounterGate
                                        * Referenced by: '<S2>/Counter Input'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<S2>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<S2>/Analog Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Zero1'
                                        */
  0.0061359231515425647,               /* Expression: 2*pi/1024
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
  0.0                                  /* Expression: 0
                                        * Referenced by: '<S1>/Time delay'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_fp_continuous_MIO_16E4_3_T fp_continuous_MIO_16E4_3_ConstP = {
  /* Expression: A-B*K-L*C
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 0.0, 0.0, 0.0, 0.0, -4714.0935004291114, 0.0, 0.0, 0.0, 0.0,
    -2317.3472425372556, 0.0, 0.0, 0.0, 0.0, 20107.347322676746, 0.0, 0.0, 0.0,
    0.0, 2946.70038172905, 0.0, 0.0, 0.0, 0.0, 112.69681909116827 },

  /* Expression: A-B*K-L*C
   * Referenced by: '<Root>/State-Space Controller'
   */
  { 17.352678901863374, 0.64016641532693763, 0.40603911077840105,
    2.6140040172282415, -0.19769871163375363, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.40603911077840105, 13.619365168336724, 22.627137708521513,
    106.07611431993979, -4.0900488547408305, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 }
};
