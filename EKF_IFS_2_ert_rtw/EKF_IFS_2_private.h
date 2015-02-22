/*
 * File: EKF_IFS_2_private.h
 *
 * Code generated for Simulink model 'EKF_IFS_2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Wed Jan 14 22:50:56 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EKF_IFS_2_private_h_
#define RTW_HEADER_EKF_IFS_2_private_h_
#include "rtwtypes.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void EKF_ConvertLatLonAlttoFlatEarth(const waypoint_bus *rtu_wpts, real_T
  rtu_alt, real_T rtu_lat, real_T rtu_lon, B_ConvertLatLonAlttoFlatEarth_T
  *localB);
extern void EKF_IFS_2_Subsystem1(real_T rtu_u, real_T rtu_u_e,
  B_Subsystem1_EKF_IFS_2_T *localB);
extern void EKF_IFS_2_Subsystem4(real_T rtu_u, real_T rtu_u_a,
  B_Subsystem4_EKF_IFS_2_T *localB);
extern void EKF_IFS_2_Subsystem1_h(real_T rtu_u, real_T rtu_u_i, real_T rtu_u_o,
  B_Subsystem1_EKF_IFS_2_l_T *localB);
extern void EKF_IFS_2_Subsystem4_p(real_T rtu_u, real_T rtu_u_o, real_T rtu_u_od,
  B_Subsystem4_EKF_IFS_2_e_T *localB);

#endif                                 /* RTW_HEADER_EKF_IFS_2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
