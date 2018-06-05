/*
 * fp_continuous_MIO_16E4_3_private.h
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

#ifndef RTW_HEADER_fp_continuous_MIO_16E4_3_private_h_
#define RTW_HEADER_fp_continuous_MIO_16E4_3_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);

/* private model entry point functions */
extern void fp_continuous_MIO_16E4_3_derivatives(void);

#endif                                 /* RTW_HEADER_fp_continuous_MIO_16E4_3_private_h_ */
