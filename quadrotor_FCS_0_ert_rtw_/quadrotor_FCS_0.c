/*
 * File: quadrotor_FCS_0.c
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

#include "quadrotor_FCS_0.h"
#include "quadrotor_FCS_0_private.h"

/* Block states (auto storage) */
DW_quadrotor_FCS_0_T quadrotor_FCS_0_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_quadrotor_FCS_0_T quadrotor_FCS_0_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_quadrotor_FCS_0_T quadrotor_FCS_0_Y;

/* Real-time model */
RT_MODEL_quadrotor_FCS_0_T quadrotor_FCS_0_M_;
RT_MODEL_quadrotor_FCS_0_T *const quadrotor_FCS_0_M = &quadrotor_FCS_0_M_;

/* Model step function */
void quadrotor_FCS_0_step(void)
{
  real_T rtb_LQR1[4];
  real_T tmp[44];
  int32_T i;
  real_T tmp_0[11];
  int32_T i_0;
  real_T u0;

  /* Gain: '<Root>/LQR1' */
  for (i = 0; i < 44; i++) {
    tmp[i] = -quadrotor_FCS_0_P.K_LQR[i];
  }

  /* SignalConversion: '<Root>/TmpSignal ConversionAtLQR1Inport1' incorporates:
   *  Gain: '<Root>/LQR1'
   *  Inport: '<Root>/Control trim'
   *  Inport: '<Root>/Internal states'
   *  Inport: '<Root>/Rotor speed'
   *  Inport: '<Root>/States cmd'
   *  Sum: '<Root>/Sum10'
   *  Sum: '<Root>/Sum11'
   *  Sum: '<Root>/Sum12'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<Root>/Sum4'
   *  Sum: '<Root>/Sum9'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  tmp_0[0] = quadrotor_FCS_0_U.Rotorspeed[0] - quadrotor_FCS_0_U.Controltrim[0];
  tmp_0[1] = quadrotor_FCS_0_U.Rotorspeed[1] - quadrotor_FCS_0_U.Controltrim[1];
  tmp_0[2] = quadrotor_FCS_0_U.Rotorspeed[2] - quadrotor_FCS_0_U.Controltrim[2];
  tmp_0[3] = quadrotor_FCS_0_U.Rotorspeed[3] - quadrotor_FCS_0_U.Controltrim[3];
  tmp_0[4] = quadrotor_FCS_0_U.Internalstates[2];
  tmp_0[5] = quadrotor_FCS_0_U.Internalstates[3] - quadrotor_FCS_0_U.Statescmd[1];
  tmp_0[6] = quadrotor_FCS_0_U.Internalstates[4] - quadrotor_FCS_0_U.Statescmd[2];
  tmp_0[7] = quadrotor_FCS_0_U.Internalstates[6];
  tmp_0[8] = quadrotor_FCS_0_U.Internalstates[7];
  tmp_0[9] = quadrotor_FCS_0_U.Internalstates[8] - quadrotor_FCS_0_U.Statescmd[3];
  tmp_0[10] = quadrotor_FCS_0_DW.UnitDelay_DSTATE;

  /* Gain: '<Root>/LQR1' */
  for (i = 0; i < 4; i++) {
    rtb_LQR1[i] = 0.0;
    for (i_0 = 0; i_0 < 11; i_0++) {
      rtb_LQR1[i] += tmp[(i_0 << 2) + i] * tmp_0[i_0];
    }
  }

  /* Sum: '<Root>/Sum5' incorporates:
   *  Inport: '<Root>/Control trim'
   */
  u0 = quadrotor_FCS_0_U.Controltrim[0] + rtb_LQR1[0];

  /* Saturate: '<Root>/Rotor1 vel Limiter' */
  if (u0 > quadrotor_FCS_0_P.Rotor1_vel_Max) {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[0] = quadrotor_FCS_0_P.Rotor1_vel_Max;
  } else if (u0 < quadrotor_FCS_0_P.Rotor1_vel_Min) {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[0] = quadrotor_FCS_0_P.Rotor1_vel_Min;
  } else {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[0] = u0;
  }

  /* End of Saturate: '<Root>/Rotor1 vel Limiter' */

  /* Sum: '<Root>/Sum6' incorporates:
   *  Inport: '<Root>/Control trim'
   */
  u0 = quadrotor_FCS_0_U.Controltrim[1] + rtb_LQR1[1];

  /* Saturate: '<Root>/Rotor 2 vel Limiter' */
  if (u0 > quadrotor_FCS_0_P.Rotor2_vel_Max) {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[1] = quadrotor_FCS_0_P.Rotor2_vel_Max;
  } else if (u0 < quadrotor_FCS_0_P.Rotor2_vel_Min) {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[1] = quadrotor_FCS_0_P.Rotor2_vel_Min;
  } else {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[1] = u0;
  }

  /* End of Saturate: '<Root>/Rotor 2 vel Limiter' */

  /* Sum: '<Root>/Sum7' incorporates:
   *  Inport: '<Root>/Control trim'
   */
  u0 = quadrotor_FCS_0_U.Controltrim[2] + rtb_LQR1[2];

  /* Saturate: '<Root>/Rotor 3 vel Limiter' */
  if (u0 > quadrotor_FCS_0_P.Rotor3_vel_Max) {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[2] = quadrotor_FCS_0_P.Rotor3_vel_Max;
  } else if (u0 < quadrotor_FCS_0_P.Rotor3_vel_Min) {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[2] = quadrotor_FCS_0_P.Rotor3_vel_Min;
  } else {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[2] = u0;
  }

  /* End of Saturate: '<Root>/Rotor 3 vel Limiter' */

  /* Sum: '<Root>/Sum8' incorporates:
   *  Inport: '<Root>/Control trim'
   */
  u0 = quadrotor_FCS_0_U.Controltrim[3] + rtb_LQR1[3];

  /* Saturate: '<Root>/Rodot 4 vel Limiter' */
  if (u0 > quadrotor_FCS_0_P.Rotor4_vel_Max) {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[3] = quadrotor_FCS_0_P.Rotor4_vel_Max;
  } else if (u0 < quadrotor_FCS_0_P.Rotor4_vel_Min) {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[3] = quadrotor_FCS_0_P.Rotor4_vel_Min;
  } else {
    /* Outport: '<Root>/Auto' */
    quadrotor_FCS_0_Y.Auto[3] = u0;
  }

  /* End of Saturate: '<Root>/Rodot 4 vel Limiter' */

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Gain: '<S1>/dt'
   *  Inport: '<Root>/Internal states'
   *  Inport: '<Root>/States cmd'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S1>/Add'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  quadrotor_FCS_0_DW.UnitDelay_DSTATE += (quadrotor_FCS_0_U.Statescmd[0] -
    quadrotor_FCS_0_U.Internalstates[2]) * quadrotor_FCS_0_P.dt;
}

/* Model initialize function */
void quadrotor_FCS_0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  quadrotor_FCS_0_P.Rotor1_vel_Max = rtInf;
  quadrotor_FCS_0_P.Rotor2_vel_Max = rtInf;
  quadrotor_FCS_0_P.Rotor3_vel_Max = rtInf;
  quadrotor_FCS_0_P.Rotor4_vel_Max = rtInf;

  /* initialize error status */
  rtmSetErrorStatus(quadrotor_FCS_0_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&quadrotor_FCS_0_DW, 0,
                sizeof(DW_quadrotor_FCS_0_T));

  /* external inputs */
  (void) memset((void *)&quadrotor_FCS_0_U, 0,
                sizeof(ExtU_quadrotor_FCS_0_T));

  /* external outputs */
  (void) memset(&quadrotor_FCS_0_Y.Auto[0], 0,
                4U*sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  quadrotor_FCS_0_DW.UnitDelay_DSTATE =
    quadrotor_FCS_0_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void quadrotor_FCS_0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
