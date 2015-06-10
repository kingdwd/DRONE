/*
 * File: quadrotor_FCS_0_data.c
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

/* Block parameters (auto storage) */
P_quadrotor_FCS_0_T quadrotor_FCS_0_P = {
  /*  Variable: K_LQR
   * Referenced by: '<Root>/LQR1'
   */
  { 0.4564064053610436, 0.011239893669935126, -0.00053766069741647247,
    0.011239893669935021, 0.011239893669935126, 0.45674284218033184,
    0.011239893669935035, -0.00087409751670633278, -0.00053766069741647247,
    0.011239893669935035, 0.4564064053610431, 0.011239893669935091,
    0.011239893669935021, -0.00087409751670633278, 0.011239893669935091,
    0.45674284218033273, -42.8321306317057, -42.832130631704729,
    -42.832130631704842, -42.83213063170497, -4.5136397005407205E-16,
    -0.70710678118655634, -2.0726414736144564E-16, 0.70710678118655712,
    0.70710678118655412, 7.5479527112652724E-15, -0.70710678118654258,
    4.1620253850105539E-16, -1.0521651382078899E-14, -3.4523751924088275,
    6.5304209444181756E-15, 3.4523751924088519, 3.501656683615002,
    2.1182164037126066E-14, -3.5016566836149057, 4.4674880528461335E-15,
    50.000000000001066, -49.999999999997769, 49.999999999998593,
    -49.999999999999112, 15.811388300842165, 15.811388300841628,
    15.811388300841474, 15.811388300841717 },
  0.0,                                 /* Variable: Rotor1_vel_Max
                                        * Referenced by: '<Root>/Rotor1 vel Limiter'
                                        */
  0.0,                                 /* Variable: Rotor1_vel_Min
                                        * Referenced by: '<Root>/Rotor1 vel Limiter'
                                        */
  0.0,                                 /* Variable: Rotor2_vel_Max
                                        * Referenced by: '<Root>/Rotor 2 vel Limiter'
                                        */
  0.0,                                 /* Variable: Rotor2_vel_Min
                                        * Referenced by: '<Root>/Rotor 2 vel Limiter'
                                        */
  0.0,                                 /* Variable: Rotor3_vel_Max
                                        * Referenced by: '<Root>/Rotor 3 vel Limiter'
                                        */
  0.0,                                 /* Variable: Rotor3_vel_Min
                                        * Referenced by: '<Root>/Rotor 3 vel Limiter'
                                        */
  0.0,                                 /* Variable: Rotor4_vel_Max
                                        * Referenced by: '<Root>/Rodot 4 vel Limiter'
                                        */
  0.0,                                 /* Variable: Rotor4_vel_Min
                                        * Referenced by: '<Root>/Rodot 4 vel Limiter'
                                        */
  0.005,                               /* Variable: dt
                                        * Referenced by: '<S1>/dt'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
