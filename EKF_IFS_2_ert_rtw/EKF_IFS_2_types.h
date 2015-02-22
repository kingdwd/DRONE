/*
 * File: EKF_IFS_2_types.h
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

#ifndef RTW_HEADER_EKF_IFS_2_types_h_
#define RTW_HEADER_EKF_IFS_2_types_h_
#include "rtwtypes.h"
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
  real_T ref_lat;
  real_T ref_lon;
  real_T ref_alt;
  uint8_T fp;
  uint8_T rp;
  real_T h[32];
  real_T n[32];
  real_T e[32];
  real_T v[32];
  uint8_T cmd[32];
  int16_T params[256];
  real_T fact_lat;
  real_T fact_lon;
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

#ifndef _DEFINED_TYPEDEF_FOR_INS_rates_bus_
#define _DEFINED_TYPEDEF_FOR_INS_rates_bus_

typedef struct {
  real_T P;
  real_T Q;
  real_T R;
} INS_rates_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_VT_A_B_bus_
#define _DEFINED_TYPEDEF_FOR_VT_A_B_bus_

typedef struct {
  real_T VT;
  real_T alpha;
  real_T beta;
} VT_A_B_bus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Accelerometer_
#define _DEFINED_TYPEDEF_FOR_Accelerometer_

typedef struct {
  real_T Axb;
  real_T Ayb;
  real_T Azb;
} Accelerometer;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Wind_bus_
#define _DEFINED_TYPEDEF_FOR_Wind_bus_

typedef struct {
  real_T VwN;
  real_T VwE;
  real_T VwH;
} Wind_bus;

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

#ifndef _DEFINED_TYPEDEF_FOR_ControlSurfaceDeflections_
#define _DEFINED_TYPEDEF_FOR_ControlSurfaceDeflections_

typedef struct {
  real_T Throttle;
  real_T Elevator;
  real_T Aileron;
  real_T Rudder;
} ControlSurfaceDeflections;

#endif

/* Parameters (auto storage) */
typedef struct P_EKF_IFS_2_T_ P_EKF_IFS_2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_EKF_IFS_2_T RT_MODEL_EKF_IFS_2_T;

#endif                                 /* RTW_HEADER_EKF_IFS_2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
