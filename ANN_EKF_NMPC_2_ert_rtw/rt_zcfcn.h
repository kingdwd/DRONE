/*
 * File: rt_zcfcn.h
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

#ifndef RTW_HEADER_rt_zcfcn_h_
#define RTW_HEADER_rt_zcfcn_h_
#include "rtwtypes.h"
//#include "solver_zc.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);

#endif                                 /* RTW_HEADER_rt_zcfcn_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
