/*
 * File: NMPC_Controller.h
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

#ifndef RTW_HEADER_NMPC_Controller_h_
#define RTW_HEADER_NMPC_Controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef NMPC_Controller_COMMON_INCLUDES_
# define NMPC_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* NMPC_Controller_COMMON_INCLUDES_ */

#include "NMPC_Controller_types.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S12>/Subsystem1' */
typedef struct {
  real_T Sqrt;                         /* '<S21>/Sqrt' */
} B_Subsystem1_NMPC_Controller_T;

/* Block signals for system '<S12>/Subsystem4' */
typedef struct {
  real_T SumofElements;                /* '<S22>/Sum of Elements' */
} B_Subsystem4_NMPC_Controller_T;

/* Block signals for system '<S13>/Subsystem1' */
typedef struct {
  real_T Sqrt;                         /* '<S23>/Sqrt' */
} B_Subsystem1_NMPC_Controller_l_T;

/* Block signals for system '<S13>/Subsystem4' */
typedef struct {
  real_T SumofElements;                /* '<S26>/Sum of Elements' */
} B_Subsystem4_NMPC_Controller_l_T;

/* Block signals (auto storage) */
typedef struct {
  real_T z_it_nmpc[20160];
  real_T J_nmpc[19200];
  real_T hessianL_nmpc[14400];
  real_T b_a_data[14400];
  real_T hessianL_nmpc_data[14400];
  real_T A_data[14400];
  real_T hessianV_nmpc[6400];
  real_T J_nmpc_m[6400];
  real_T A[6400];
  real_T A_c[3200];
  B_Subsystem1_NMPC_Controller_l_T Subsystem1_d;/* '<S30>/Subsystem1' */
  B_Subsystem1_NMPC_Controller_l_T Subsystem1;/* '<S14>/Subsystem1' */
  B_Subsystem4_NMPC_Controller_l_T Subsystem4;/* '<S13>/Subsystem4' */
  B_Subsystem1_NMPC_Controller_T Subsystem3;/* '<S13>/Subsystem3' */
  B_Subsystem1_NMPC_Controller_T Subsystem2;/* '<S13>/Subsystem2' */
  B_Subsystem1_NMPC_Controller_l_T Subsystem1_j;/* '<S13>/Subsystem1' */
  B_Subsystem4_NMPC_Controller_T Subsystem4_h;/* '<S12>/Subsystem4' */
  B_Subsystem1_NMPC_Controller_T Subsystem1_a;/* '<S12>/Subsystem1' */
} B_NMPC_Controller_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[84];         /* '<Root>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S13>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S12>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_p;           /* '<S34>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S34>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S34>/Unit Delay2' */
  real_T UnitDelay3_DSTATE;            /* '<S34>/Unit Delay3' */
  real_T UnitDelay_DSTATE_j;           /* '<S35>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g;          /* '<S35>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_a;          /* '<S35>/Unit Delay2' */
  real_T UnitDelay3_DSTATE_g;          /* '<S35>/Unit Delay3' */
  real_T UnitDelay_DSTATE_m;           /* '<S36>/Unit Delay' */
  real_T UnitDelay1_DSTATE_m;          /* '<S36>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_p;          /* '<S36>/Unit Delay2' */
  real_T UnitDelay3_DSTATE_j;          /* '<S36>/Unit Delay3' */
  real_T UD_DSTATE;                    /* '<S2>/UD' */
  real_T UD_DSTATE_j;                  /* '<S3>/UD' */
  real_T Delay5seconds_DSTATE[100];    /* '<Root>/Delay 5 seconds' */
  real_T sw_time;                      /* '<S6>/Logic time control' */
  real_T remote_aileron_mem;           /* '<S6>/Remote aileron' */
  real_T remote_elevator_mem;          /* '<S6>/Remote elevator' */
  real_T remote_rudder_mem;            /* '<S6>/Remote rudder' */
  real_T remote_throttle_mem;          /* '<S6>/Remote throttle' */
  real_T Start_Wpt[3];                 /* '<S8>/Start Waypoint Memory' */
  real_T u_nmpc[84];                   /* '<Root>/NMPC Memory' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S13>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_f;/* '<S12>/Discrete-Time Integrator' */
  uint8_T Home_reset;                  /* '<S8>/Home Reset Memory' */
  uint8_T Waypoint_Index;              /* '<S8>/Waypoint Index Memory' */
  boolean_T PIC_CIC_Last;              /* '<S8>/PIC//CIC Last State Memory' */
} DW_NMPC_Controller_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay5seconds_Reset_ZCE;  /* '<Root>/Delay 5 seconds' */
} PrevZCX_NMPC_Controller_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  struct_4Fd1bnpyLecBuwBUBUAQfC pooled1;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  struct_4Fd1bnpyLecBuwBUBUAQfC pooled2;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  struct_4Fd1bnpyLecBuwBUBUAQfC pooled3;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  struct_4Fd1bnpyLecBuwBUBUAQfC pooled4;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  real_T pooled15[7];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  real_T pooled17[7];

  /* Expression: Y_maxXin
   * Referenced by: '<Root>/Control System'
   */
  real_T ControlSystem_Y_maxXin[7];

  /* Expression: Y_minXin
   * Referenced by: '<Root>/Control System'
   */
  real_T ControlSystem_Y_minXin[7];

  /* Pooled Parameter (Expression: u_IC(:,1:N_nmpc+1))
   * Referenced by:
   *   '<Root>/NMPC Memory'
   *   '<Root>/Unit Delay'
   */
  real_T pooled22[84];
} ConstP_NMPC_Controller_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  Control_cmd_bus RC;                  /* '<Root>/R//C' */
  boolean_T PICCIC;                    /* '<Root>/PIC//CIC' */
  boolean_T HomeCmd;                   /* '<Root>/Home Cmd' */
  waypoint_bus wpts;                   /* '<Root>/wpts' */
  GPS_position_bus GPSPosition;        /* '<Root>/GPS Position' */
  GPS_velocity_bus GPSVelocity;        /* '<Root>/GPS Velocity' */
  INS_angles_bus phithetapsi;          /* '<Root>/phi, theta, psi' */
  Wind_bus TrueWind;                   /* '<Root>/True Wind' */
  VT_A_B_bus VTalphabeta;              /* '<Root>/VT, alpha, beta' */
  INS_rates_bus PQR;                   /* '<Root>/P,Q,R' */
  real_T Servodeflection[4];           /* '<Root>/Servo deflection' */
  real_T n_op[22];                     /* '<Root>/n_op' */
  real_T e_op[22];                     /* '<Root>/e_op' */
  real_T h_op[22];                     /* '<Root>/h_op' */
  real_T vn_op[22];                    /* '<Root>/vn_op' */
  real_T ve_op[22];                    /* '<Root>/ve_op' */
  real_T vh_op[22];                    /* '<Root>/vh_op' */
  real_T FL_ann;                       /* '<Root>/FL_ann' */
  real_T a_ann_X[40];                  /* '<Root>/a_ann_X' */
  real_T b_ann_X[40];                  /* '<Root>/b_ann_X' */
  real_T c_ann_X;                      /* '<Root>/c_ann_X' */
  real_T w_ann_X[280];                 /* '<Root>/w_ann_X' */
  real_T a_ann_Y[40];                  /* '<Root>/a_ann_Y' */
  real_T b_ann_Y[40];                  /* '<Root>/b_ann_Y' */
  real_T c_ann_Y;                      /* '<Root>/c_ann_Y' */
  real_T w_ann_Y[280];                 /* '<Root>/w_ann_Y' */
  real_T a_ann_Z[40];                  /* '<Root>/a_ann_Z' */
  real_T b_ann_Z[40];                  /* '<Root>/b_ann_Z' */
  real_T c_ann_Z;                      /* '<Root>/c_ann_Z' */
  real_T w_ann_Z[280];                 /* '<Root>/w_ann_Z' */
} ExtU_NMPC_Controller_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  Control_cmd_bus ControlSurfaceCommands;/* '<Root>/Control  Surface Commands' */
  Guidance_cmd_bus CommandedStates;    /* '<Root>/Commanded States' */
  Track_angles_bus TrackAngles;        /* '<Root>/Track Angles' */
  real32_T DistancetoWaypoint;         /* '<Root>/Distance to Waypoint' */
  uint8_T WaypointIndex;               /* '<Root>/Waypoint Index' */
  real_T W_data[24];                   /* '<Root>/W_data' */
  real_T V_nmpc;                       /* '<Root>/V_nmpc' */
} ExtY_NMPC_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_NMPC_Controller_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_NMPC_Controller_T NMPC_Controller_B;

/* Block states (auto storage) */
extern DW_NMPC_Controller_T NMPC_Controller_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_NMPC_Controller_T NMPC_Controller_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_NMPC_Controller_T NMPC_Controller_Y;

/* Constant parameters (auto storage) */
extern const ConstP_NMPC_Controller_T NMPC_Controller_ConstP;

/* Model entry point functions */
extern void NMPC_Controller_initialize(void);
extern void NMPC_Controller_step(void);
extern void NMPC_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_NMPC_Controller_T *const NMPC_Controller_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'NMPC_Controller'
 * '<S1>'   : 'NMPC_Controller/Control System'
 * '<S2>'   : 'NMPC_Controller/Discrete Derivative'
 * '<S3>'   : 'NMPC_Controller/Discrete Derivative1'
 * '<S4>'   : 'NMPC_Controller/GPS to Local'
 * '<S5>'   : 'NMPC_Controller/Guidance System'
 * '<S6>'   : 'NMPC_Controller/R//C to AUTO smooth transition Subsystem'
 * '<S7>'   : 'NMPC_Controller/Robustness States at [k]'
 * '<S8>'   : 'NMPC_Controller/Trajectory'
 * '<S9>'   : 'NMPC_Controller/GPS to Local/Convert Lat//Lon//Alt to Flat Earth'
 * '<S10>'  : 'NMPC_Controller/Guidance System/Beta command'
 * '<S11>'  : 'NMPC_Controller/Guidance System/Coordinates transformation e-n-h to e-n-h_track'
 * '<S12>'  : 'NMPC_Controller/Guidance System/Phi command'
 * '<S13>'  : 'NMPC_Controller/Guidance System/Theta command'
 * '<S14>'  : 'NMPC_Controller/Guidance System/VT command'
 * '<S15>'  : 'NMPC_Controller/Guidance System/VT modification_moving points'
 * '<S16>'  : 'NMPC_Controller/Guidance System/r and d points'
 * '<S17>'  : 'NMPC_Controller/Guidance System/Coordinates transformation e-n-h to e-n-h_track/angles of rotation'
 * '<S18>'  : 'NMPC_Controller/Guidance System/Coordinates transformation e-n-h to e-n-h_track/angles of rotation/Angle Correction'
 * '<S19>'  : 'NMPC_Controller/Guidance System/Coordinates transformation e-n-h to e-n-h_track/angles of rotation/Angle Correction/Embedded MATLAB Function'
 * '<S20>'  : 'NMPC_Controller/Guidance System/Phi command/Embedded MATLAB Function'
 * '<S21>'  : 'NMPC_Controller/Guidance System/Phi command/Subsystem1'
 * '<S22>'  : 'NMPC_Controller/Guidance System/Phi command/Subsystem4'
 * '<S23>'  : 'NMPC_Controller/Guidance System/Theta command/Subsystem1'
 * '<S24>'  : 'NMPC_Controller/Guidance System/Theta command/Subsystem2'
 * '<S25>'  : 'NMPC_Controller/Guidance System/Theta command/Subsystem3'
 * '<S26>'  : 'NMPC_Controller/Guidance System/Theta command/Subsystem4'
 * '<S27>'  : 'NMPC_Controller/Guidance System/VT command/Subsystem1'
 * '<S28>'  : 'NMPC_Controller/Guidance System/VT modification_moving points/Modification of VT'
 * '<S29>'  : 'NMPC_Controller/Guidance System/r and d points/d distance'
 * '<S30>'  : 'NMPC_Controller/Guidance System/r and d points/r point'
 * '<S31>'  : 'NMPC_Controller/Guidance System/r and d points/d distance/Embedded MATLAB Function'
 * '<S32>'  : 'NMPC_Controller/Guidance System/r and d points/r point/Subsystem1'
 * '<S33>'  : 'NMPC_Controller/R//C to AUTO smooth transition Subsystem/Swtching Logic'
 * '<S34>'  : 'NMPC_Controller/Robustness States at [k]/W1'
 * '<S35>'  : 'NMPC_Controller/Robustness States at [k]/W2'
 * '<S36>'  : 'NMPC_Controller/Robustness States at [k]/W3'
 * '<S37>'  : 'NMPC_Controller/Trajectory/Trajectory Generation'
 */
#endif                                 /* RTW_HEADER_NMPC_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
