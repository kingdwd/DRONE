/*
 * File: NMPC_Controller_data.c
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

#include "NMPC_Controller.h"
#include "NMPC_Controller_private.h"

/* Constant parameters (auto storage) */
const ConstP_NMPC_Controller_T NMPC_Controller_ConstP = {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  {
    0.99998000019999866,
    0.5,
    0.39999598002686648,
    0.0005
  },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  {
    0.77782300443900354,
    1.0,
    -1.0942718103248184,
    5.0251256281407031
  },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  {
    0.77782300443900354,
    1.0,
    -0.89451227385639021,
    5.0251256281407031
  },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  {
    0.513417119032592,
    1.0,
    -1.6219186074139784,
    3.3333333333333335
  },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  { 168.0, 0.2, 0.01, 1.0, 0.5, 1.0, 0.2 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/Control System'
   */
  { 162.0, -0.2, -0.01, -1.0, -0.5, 0.1, -0.2 },

  /* Expression: Y_maxXin
   * Referenced by: '<Root>/Control System'
   */
  { 168.0, 0.01, 2.0, 1.0, 0.2, 0.6, 0.5 },

  /* Expression: Y_minXin
   * Referenced by: '<Root>/Control System'
   */
  { 162.0, -0.01, -2.0, -1.0, -0.2, -0.6, -0.5 },

  /* Pooled Parameter (Expression: u_IC(:,1:N_nmpc+1))
   * Referenced by:
   *   '<Root>/NMPC Memory'
   *   '<Root>/Unit Delay'
   */
  { 0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0, 0.315, -0.03438298626428829, 0.0, 0.0,
    0.315, -0.03438298626428829, 0.0, 0.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
