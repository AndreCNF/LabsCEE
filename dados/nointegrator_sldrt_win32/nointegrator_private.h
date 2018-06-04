/*
 * nointegrator_private.h
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

#ifndef RTW_HEADER_nointegrator_private_h_
#define RTW_HEADER_nointegrator_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);

/* private model entry point functions */
extern void nointegrator_derivatives(void);

#endif                                 /* RTW_HEADER_nointegrator_private_h_ */
