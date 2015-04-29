/*
 * File: NMPC_Controller_types.h
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

#ifndef RTW_HEADER_NMPC_Controller_types_h_
#define RTW_HEADER_NMPC_Controller_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_struct_4Fd1bnpyLecBuwBUBUAQfC_
#define _DEFINED_TYPEDEF_FOR_struct_4Fd1bnpyLecBuwBUBUAQfC_

typedef struct {
  real_T a;
  real_T b;
  real_T c;
  real_T d;
} struct_4Fd1bnpyLecBuwBUBUAQfC;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_xYjaDAhINEeuZgQvvu1iQH_
#define _DEFINED_TYPEDEF_FOR_struct_xYjaDAhINEeuZgQvvu1iQH_

typedef struct {
  real_T ref_lat;
  real_T ref_lon;
  real_T ref_alt;
  real_T fact_lat;
  real_T fact_lon;
} struct_xYjaDAhINEeuZgQvvu1iQH;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Control_cmd_bus_
#define _DEFINED_TYPEDEF_FOR_Control_cmd_bus_

typedef struct {
  real_T throttle_cmd;
  real_T elevator_cmd;
  real_T aileron_cmd;
  real_T rudder_cmd;
} Control_cmd_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_waypoint_bus_
#define _DEFINED_TYPEDEF_FOR_waypoint_bus_

typedef struct {
  uint8_T fp;
  uint8_T rp;
  real_T h[32];
  real_T n[32];
  real_T e[32];
  real_T v[32];
} waypoint_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_GPS_position_bus_
#define _DEFINED_TYPEDEF_FOR_GPS_position_bus_

typedef struct {
  real_T Latitude;
  real_T Longitude;
  real_T Altitude;
} GPS_position_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_GPS_velocity_bus_
#define _DEFINED_TYPEDEF_FOR_GPS_velocity_bus_

typedef struct {
  real_T V_north;
  real_T V_east;
  real_T V_down;
} GPS_velocity_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_INS_angles_bus_
#define _DEFINED_TYPEDEF_FOR_INS_angles_bus_

typedef struct {
  real_T phi;
  real_T theta;
  real_T psi;
} INS_angles_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Wind_bus_
#define _DEFINED_TYPEDEF_FOR_Wind_bus_

typedef struct {
  real_T VwN;
  real_T VwE;
  real_T VwH;
} Wind_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_VT_A_B_bus_
#define _DEFINED_TYPEDEF_FOR_VT_A_B_bus_

typedef struct {
  real_T VT;
  real_T alpha;
  real_T beta;
} VT_A_B_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_INS_rates_bus_
#define _DEFINED_TYPEDEF_FOR_INS_rates_bus_

typedef struct {
  real_T P;
  real_T Q;
  real_T R;
} INS_rates_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Inertial_local_bus_
#define _DEFINED_TYPEDEF_FOR_Inertial_local_bus_

typedef struct {
  real_T fact_lat;
  real_T fact_lon;
  real_T ref_alt;
  real_T ref_lon;
  real_T ref_lat;
} Inertial_local_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Track_angles_bus_
#define _DEFINED_TYPEDEF_FOR_Track_angles_bus_

typedef struct {
  real_T etaLat;
  real_T etaLon;
} Track_angles_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Local_position_bus_
#define _DEFINED_TYPEDEF_FOR_Local_position_bus_

typedef struct {
  real_T Height;
  real_T North;
  real_T East;
} Local_position_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_d_point_bus_
#define _DEFINED_TYPEDEF_FOR_d_point_bus_

typedef struct {
  real_T hd;
  real_T nd;
  real_T ed;
} d_point_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Guidance_cmd_bus_
#define _DEFINED_TYPEDEF_FOR_Guidance_cmd_bus_

typedef struct {
  real_T VT_cmd;
  real_T theta_cmd;
  real_T phi_cmd;
  real_T beta_cmd;
} Guidance_cmd_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_trajectory_bus_
#define _DEFINED_TYPEDEF_FOR_trajectory_bus_

typedef struct {
  real_T Vab;
  real_T ha;
  real_T na;
  real_T ea;
  real_T hb;
  real_T nb;
  real_T eb;
} trajectory_bus;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_NMPC_Controller_T RT_MODEL_NMPC_Controller_T;

#endif                                 /* RTW_HEADER_NMPC_Controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
