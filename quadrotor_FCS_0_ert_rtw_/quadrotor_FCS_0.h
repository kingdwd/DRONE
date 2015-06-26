/*
 * File: quadrotor_FCS_0.h
 *
 * Code generated for Simulink model 'quadrotor_FCS_0'.
 *
 * Model version                  : 1.48
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Jun 02 14:15:35 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_quadrotor_FCS_0_h_
#define RTW_HEADER_quadrotor_FCS_0_h_
#include <stddef.h>
#include <string.h>
#ifndef quadrotor_FCS_0_COMMON_INCLUDES_
# define quadrotor_FCS_0_COMMON_INCLUDES_
#include "rtwtypes.h"
//#include "rtw_continuous.h"
//#include "rtw_solver.h"
#endif                                 /* quadrotor_FCS_0_COMMON_INCLUDES_ */

#include "quadrotor_FCS_0_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
} DW_quadrotor_FCS_0_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Statescmd[4];                 /* '<Root>/States cmd' */
  real_T Controltrim[4];               /* '<Root>/Control trim' */
  real_T Rotorspeed[4];                /* '<Root>/Rotor speed' */
  real_T Internalstates[9];            /* '<Root>/Internal states' */
  real_T RC[5];
  real_T ORC[4];
  real_T lla[3];
  real_T Acc[3];
  real_T rpm[4];	
} ExtU_quadrotor_FCS_0_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Auto[4];                      /* '<Root>/Auto' */
} ExtY_quadrotor_FCS_0_T;

/* Parameters (auto storage) */
struct P_quadrotor_FCS_0_T_ {
  real_T K_LQR[44];                    /* Variable: K_LQR
                                        * Referenced by: '<Root>/LQR1'
                                        */
  real_T Rotor1_vel_Max;               /* Variable: Rotor1_vel_Max
                                        * Referenced by: '<Root>/Rotor1 vel Limiter'
                                        */
  real_T Rotor1_vel_Min;               /* Variable: Rotor1_vel_Min
                                        * Referenced by: '<Root>/Rotor1 vel Limiter'
                                        */
  real_T Rotor2_vel_Max;               /* Variable: Rotor2_vel_Max
                                        * Referenced by: '<Root>/Rotor 2 vel Limiter'
                                        */
  real_T Rotor2_vel_Min;               /* Variable: Rotor2_vel_Min
                                        * Referenced by: '<Root>/Rotor 2 vel Limiter'
                                        */
  real_T Rotor3_vel_Max;               /* Variable: Rotor3_vel_Max
                                        * Referenced by: '<Root>/Rotor 3 vel Limiter'
                                        */
  real_T Rotor3_vel_Min;               /* Variable: Rotor3_vel_Min
                                        * Referenced by: '<Root>/Rotor 3 vel Limiter'
                                        */
  real_T Rotor4_vel_Max;               /* Variable: Rotor4_vel_Max
                                        * Referenced by: '<Root>/Rodot 4 vel Limiter'
                                        */
  real_T Rotor4_vel_Min;               /* Variable: Rotor4_vel_Min
                                        * Referenced by: '<Root>/Rodot 4 vel Limiter'
                                        */
  real_T dt;                           /* Variable: dt
                                        * Referenced by: '<S1>/dt'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_quadrotor_FCS_0_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_quadrotor_FCS_0_T quadrotor_FCS_0_P;

/* Block states (auto storage) */
extern DW_quadrotor_FCS_0_T quadrotor_FCS_0_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_quadrotor_FCS_0_T quadrotor_FCS_0_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_quadrotor_FCS_0_T quadrotor_FCS_0_Y;

/* Model entry point functions */
extern void quadrotor_FCS_0_initialize(void);
extern void quadrotor_FCS_0_step(void);
extern void quadrotor_FCS_0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_quadrotor_FCS_0_T *const quadrotor_FCS_0_M;

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
 * '<Root>' : 'quadrotor_FCS_0'
 * '<S1>'   : 'quadrotor_FCS_0/Discrete integrator'
 */
#endif                                 /* RTW_HEADER_quadrotor_FCS_0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
