/*
 * File: NMPC_Controller_private.h
 *
 * Code generated for Simulink model 'NMPC_Controller'.
 *
 * Model version                  : 1.654
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Mon Apr 27 19:38:57 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Emulation hardware selection:
 *    Differs from embedded hardware (Generic->MATLAB Host Computer)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NMPC_Controller_private_h_
#define RTW_HEADER_NMPC_Controller_private_h_
#include "rtwtypes.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern void NMPC_Controller_Subsystem1(real_T rtu_u, real_T rtu_u_o,
  B_Subsystem1_NMPC_Controller_T *localB);
extern void NMPC_Controller_Subsystem4(real_T rtu_u, real_T rtu_u_e,
  B_Subsystem4_NMPC_Controller_T *localB);
extern void NMPC_Controller_Subsystem1_j(real_T rtu_u, real_T rtu_u_d, real_T
  rtu_u_f, B_Subsystem1_NMPC_Controller_l_T *localB);
extern void NMPC_Controller_Subsystem4_g(real_T rtu_u, real_T rtu_u_k, real_T
  rtu_u_j, B_Subsystem4_NMPC_Controller_l_T *localB);

#endif                                 /* RTW_HEADER_NMPC_Controller_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
