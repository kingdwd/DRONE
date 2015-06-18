/*
 * File: ANN_EKF_NMPC_2_private.h
 *
 * Code generated for Simulink model 'ANN_EKF_NMPC_2'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Jun 16 09:17:13 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ANN_EKF_NMPC_2_private_h_
#define RTW_HEADER_ANN_EKF_NMPC_2_private_h_
#include "rtwtypes.h"

extern real_T rt_atan2d_snf(real_T loctmp_u0, real_T loctmp_u1);
extern real_T rt_roundd_snf(real_T loctmp_u);
extern real_T rt_powd_snf(real_T loctmp_u0, real_T loctmp_u1);
extern void ANN_EKF_NMPC_2_Subsystem1(real_T rtu_u, real_T rtu_u_k,
  B_Subsystem1_ANN_EKF_NMPC_2_T *localB);
extern void ANN_EKF_NMPC_2_Subsystem4(real_T rtu_u, real_T rtu_u_h,
  B_Subsystem4_ANN_EKF_NMPC_2_T *localB);
extern void ANN_EKF_NMPC_2_Subsystem1_p(real_T rtu_u, real_T rtu_u_n, real_T
  rtu_u_d, B_Subsystem1_ANN_EKF_NMPC_2_d_T *localB);
extern void ANN_EKF_NMPC_2_Subsystem4_k(real_T rtu_u, real_T rtu_u_g, real_T
  rtu_u_b, B_Subsystem4_ANN_EKF_NMPC_2_k_T *localB);

#endif                                 /* RTW_HEADER_ANN_EKF_NMPC_2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
