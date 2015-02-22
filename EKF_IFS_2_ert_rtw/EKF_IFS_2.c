/*
 * File: EKF_IFS_2.c
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

#include "EKF_IFS_2.h"
#include "EKF_IFS_2_private.h"

/* Block signals (auto storage) */
B_EKF_IFS_2_T EKF_IFS_2_B;

/* Block states (auto storage) */
DW_EKF_IFS_2_T EKF_IFS_2_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_EKF_IFS_2_T EKF_IFS_2_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_EKF_IFS_2_T EKF_IFS_2_Y;

/* Real-time model */
RT_MODEL_EKF_IFS_2_T EKF_IFS_2_M_;
RT_MODEL_EKF_IFS_2_T *const EKF_IFS_2_M = &EKF_IFS_2_M_;

/* Forward declaration for local functions */
static void EKF_IFS_2_invNxN(const real_T x[36], real_T y[36]);
static void EKF_IFS_2_invNxN_i(const real_T x[64], real_T y[64]);

/*
 * Output and update for atomic system:
 *    '<S5>/Convert Lat//Lon//Alt to Flat Earth'
 *    '<S47>/Convert Lat//Lon//Alt to Flat Earth'
 */
void EKF_ConvertLatLonAlttoFlatEarth(const waypoint_bus *rtu_wpts, real_T
  rtu_alt, real_T rtu_lat, real_T rtu_lon, B_ConvertLatLonAlttoFlatEarth_T
  *localB)
{
  /* MATLAB Function 'Intelligent Flight System (subsystem)/GPS to Local/Convert Lat//Lon//Alt to Flat Earth': '<S19>:1' */
  /*  Convert the given LLA coordinates to Flat Earth coordinates. */
  /*  */
  /*  ref_alt - meters ASML */
  /*  ref_lat - deg. */
  /*  ref_lon - deg. */
  /*  */
  /*  Height, North, East are in feet */
  /* '<S19>:1:11' */
  localB->Height = (rtu_alt - rtu_wpts->ref_alt) * 3.280839895013123;

  /* '<S19>:1:12' */
  localB->North = (rtu_lat - rtu_wpts->ref_lat) * rtu_wpts->fact_lat;

  /* '<S19>:1:13' */
  localB->East = (rtu_lon - rtu_wpts->ref_lon) * rtu_wpts->fact_lon;
}

/*
 * Output and update for atomic system:
 *    '<S22>/Subsystem1'
 *    '<S23>/Subsystem2'
 *    '<S23>/Subsystem3'
 */
void EKF_IFS_2_Subsystem1(real_T rtu_u, real_T rtu_u_e, B_Subsystem1_EKF_IFS_2_T
  *localB)
{
  /* Sqrt: '<S31>/Sqrt' incorporates:
   *  Math: '<S31>/Math Function2'
   *  SignalConversion: '<S31>/TmpSignal ConversionAtMath Function2Inport1'
   *  Sum: '<S31>/Sum of Elements'
   */
  localB->Sqrt = sqrt(rtu_u * rtu_u + rtu_u_e * rtu_u_e);
}

/* Output and update for atomic system: '<S22>/Subsystem4' */
void EKF_IFS_2_Subsystem4(real_T rtu_u, real_T rtu_u_a, B_Subsystem4_EKF_IFS_2_T
  *localB)
{
  /* Sum: '<S32>/Sum of Elements' incorporates:
   *  Math: '<S32>/Math Function2'
   *  SignalConversion: '<S32>/TmpSignal ConversionAtMath Function2Inport1'
   */
  localB->SumofElements = rtu_u * rtu_u + rtu_u_a * rtu_u_a;
}

/*
 * Output and update for atomic system:
 *    '<S23>/Subsystem1'
 *    '<S24>/Subsystem1'
 *    '<S40>/Subsystem1'
 */
void EKF_IFS_2_Subsystem1_h(real_T rtu_u, real_T rtu_u_i, real_T rtu_u_o,
  B_Subsystem1_EKF_IFS_2_l_T *localB)
{
  /* Sqrt: '<S33>/Sqrt' incorporates:
   *  Math: '<S33>/Math Function2'
   *  SignalConversion: '<S33>/TmpSignal ConversionAtMath Function2Inport1'
   *  Sum: '<S33>/Sum of Elements'
   */
  localB->Sqrt = sqrt((rtu_u * rtu_u + rtu_u_i * rtu_u_i) + rtu_u_o * rtu_u_o);
}

/* Output and update for atomic system: '<S23>/Subsystem4' */
void EKF_IFS_2_Subsystem4_p(real_T rtu_u, real_T rtu_u_o, real_T rtu_u_od,
  B_Subsystem4_EKF_IFS_2_e_T *localB)
{
  /* Sum: '<S36>/Sum of Elements' incorporates:
   *  Math: '<S36>/Math Function2'
   *  SignalConversion: '<S36>/TmpSignal ConversionAtMath Function2Inport1'
   */
  localB->SumofElements = (rtu_u * rtu_u + rtu_u_o * rtu_u_o) + rtu_u_od *
    rtu_u_od;
}

/* Function for MATLAB Function: '<S58>/Inverse' */
static void EKF_IFS_2_invNxN(const real_T x[36], real_T y[36])
{
  int8_T p[6];
  real_T A[36];
  int8_T ipiv[6];
  int32_T b_j;
  int32_T b_c;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T jy;
  int32_T c_ix;
  int32_T ijA;
  int32_T jBcol;
  int32_T kAcol;
  for (b_j = 0; b_j < 36; b_j++) {
    y[b_j] = 0.0;
    A[b_j] = x[b_j];
  }

  for (b_j = 0; b_j < 6; b_j++) {
    ipiv[b_j] = (int8_T)(1 + b_j);
  }

  for (b_j = 0; b_j < 5; b_j++) {
    b_c = b_j * 7;
    jy = 0;
    ix = b_c;
    smax = fabs(A[b_c]);
    for (jBcol = 2; jBcol <= 6 - b_j; jBcol++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        jy = jBcol - 1;
        smax = s;
      }
    }

    if (A[b_c + jy] != 0.0) {
      if (jy != 0) {
        ipiv[b_j] = (int8_T)((b_j + jy) + 1);
        kAcol = b_j;
        jBcol = b_j + jy;
        for (jy = 0; jy < 6; jy++) {
          smax = A[kAcol];
          A[kAcol] = A[jBcol];
          A[jBcol] = smax;
          kAcol += 6;
          jBcol += 6;
        }
      }

      ix = (b_c - b_j) + 6;
      for (jBcol = b_c + 1; jBcol + 1 <= ix; jBcol++) {
        A[jBcol] /= A[b_c];
      }
    }

    jBcol = b_c;
    jy = b_c + 6;
    for (kAcol = 1; kAcol <= 5 - b_j; kAcol++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        c_ix = b_c + 1;
        ix = (jBcol - b_j) + 12;
        for (ijA = 7 + jBcol; ijA + 1 <= ix; ijA++) {
          A[ijA] += A[c_ix] * -smax;
          c_ix++;
        }
      }

      jy += 6;
      jBcol += 6;
    }
  }

  for (b_j = 0; b_j < 6; b_j++) {
    p[b_j] = (int8_T)(1 + b_j);
  }

  for (ix = 0; ix < 5; ix++) {
    if (ipiv[ix] > 1 + ix) {
      jBcol = p[ipiv[ix] - 1];
      p[ipiv[ix] - 1] = p[ix];
      p[ix] = (int8_T)jBcol;
    }
  }

  for (ix = 0; ix < 6; ix++) {
    jBcol = p[ix] - 1;
    y[ix + 6 * (p[ix] - 1)] = 1.0;
    for (jy = ix; jy + 1 < 7; jy++) {
      if (y[6 * jBcol + jy] != 0.0) {
        for (kAcol = jy + 1; kAcol + 1 < 7; kAcol++) {
          y[kAcol + 6 * jBcol] -= y[6 * jBcol + jy] * A[6 * jy + kAcol];
        }
      }
    }
  }

  for (ix = 0; ix < 6; ix++) {
    jBcol = 6 * ix;
    for (jy = 5; jy >= 0; jy += -1) {
      kAcol = 6 * jy;
      if (y[jy + jBcol] != 0.0) {
        y[jy + jBcol] /= A[jy + kAcol];
        for (c_ix = 0; c_ix + 1 <= jy; c_ix++) {
          y[c_ix + jBcol] -= y[jy + jBcol] * A[c_ix + kAcol];
        }
      }
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S149>/Inverse' */
static void EKF_IFS_2_invNxN_i(const real_T x[64], real_T y[64])
{
  int8_T p[8];
  real_T A[64];
  int8_T ipiv[8];
  int32_T b_j;
  int32_T b_c;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T jy;
  int32_T c_ix;
  int32_T ijA;
  int32_T jBcol;
  int32_T kAcol;
  for (b_j = 0; b_j < 64; b_j++) {
    y[b_j] = 0.0;
    A[b_j] = x[b_j];
  }

  for (b_j = 0; b_j < 8; b_j++) {
    ipiv[b_j] = (int8_T)(1 + b_j);
  }

  for (b_j = 0; b_j < 7; b_j++) {
    b_c = b_j * 9;
    jy = 0;
    ix = b_c;
    smax = fabs(A[b_c]);
    for (jBcol = 2; jBcol <= 8 - b_j; jBcol++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        jy = jBcol - 1;
        smax = s;
      }
    }

    if (A[b_c + jy] != 0.0) {
      if (jy != 0) {
        ipiv[b_j] = (int8_T)((b_j + jy) + 1);
        kAcol = b_j;
        jBcol = b_j + jy;
        for (jy = 0; jy < 8; jy++) {
          smax = A[kAcol];
          A[kAcol] = A[jBcol];
          A[jBcol] = smax;
          kAcol += 8;
          jBcol += 8;
        }
      }

      ix = (b_c - b_j) + 8;
      for (jBcol = b_c + 1; jBcol + 1 <= ix; jBcol++) {
        A[jBcol] /= A[b_c];
      }
    }

    jBcol = b_c;
    jy = b_c + 8;
    for (kAcol = 1; kAcol <= 7 - b_j; kAcol++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        c_ix = b_c + 1;
        ix = (jBcol - b_j) + 16;
        for (ijA = 9 + jBcol; ijA + 1 <= ix; ijA++) {
          A[ijA] += A[c_ix] * -smax;
          c_ix++;
        }
      }

      jy += 8;
      jBcol += 8;
    }
  }

  for (b_j = 0; b_j < 8; b_j++) {
    p[b_j] = (int8_T)(1 + b_j);
  }

  for (ix = 0; ix < 7; ix++) {
    if (ipiv[ix] > 1 + ix) {
      jBcol = p[ipiv[ix] - 1];
      p[ipiv[ix] - 1] = p[ix];
      p[ix] = (int8_T)jBcol;
    }
  }

  for (ix = 0; ix < 8; ix++) {
    jBcol = p[ix] - 1;
    y[ix + ((p[ix] - 1) << 3)] = 1.0;
    for (jy = ix; jy + 1 < 9; jy++) {
      if (y[(jBcol << 3) + jy] != 0.0) {
        for (kAcol = jy + 1; kAcol + 1 < 9; kAcol++) {
          y[kAcol + (jBcol << 3)] -= y[(jBcol << 3) + jy] * A[(jy << 3) + kAcol];
        }
      }
    }
  }

  for (ix = 0; ix < 8; ix++) {
    jBcol = ix << 3;
    for (jy = 7; jy >= 0; jy += -1) {
      kAcol = jy << 3;
      if (y[jy + jBcol] != 0.0) {
        y[jy + jBcol] /= A[jy + kAcol];
        for (c_ix = 0; c_ix + 1 <= jy; c_ix++) {
          y[c_ix + jBcol] -= y[jy + jBcol] * A[c_ix + kAcol];
        }
      }
    }
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void EKF_IFS_2_step(void)
{
  real_T wpts_h[32];
  real_T wpts_n[32];
  real_T wpts_e[32];
  real_T distance;
  int32_T rtb_DataTypeConversion1;
  real_T rtb_DataStoreRead4;
  real_T rtb_DataStoreRead3;
  real_T rtb_DataStoreRead1;
  real_T rtb_DataStoreRead2;
  real_T rtb_DataStoreRead5;
  real_T rtb_BusConversion_InsertedFor_0;
  real_T rtb_BusConversion_InsertedFor_1;
  real_T rtb_BusConversion_InsertedFor_2;
  real_T rtb_BusConversion_InsertedFor_3;
  uint8_T rtb_DataStoreRead2_h;
  boolean_T rtb_DataStoreRead1_b;
  uint8_T rtb_DataStoreRead4_n;
  real_T rtb_Subtract1[6];
  real_T rtb_Divide_bi;
  real_T rtb_Divide4_ot;
  real_T rtb_Divide4_jaz;
  real_T rtb_u_k1[6];
  real_T rtb_Add_ey;
  real_T rtb_Add1_ma;
  real_T rtb_Divide_bd;
  real_T rtb_Add1_bmn;
  real_T rtb_f_RDRx_est_kuk;
  real_T rtb_f_AILx_est_kuk;
  real_T rtb_Divide4_d0r;
  real_T rtb_Add_nv;
  real_T rtb_sin_atrack;
  real_T rtb_MathFunction5;
  real_T rtb_MathFunction6;
  real_T rtb_cos_atrack;
  real_T rtb_Divide1_mwl[6];
  real_T rtb_Divide2_fm[6];
  real_T rtb_Divide3_im[6];
  real_T rtb_Product1_gr[6];
  uint8_T rtb_FixPtRelationalOperator;
  real_T rtb_Add9;
  real_T rtb_Add5;
  real_T rtb_hd;
  real_T rtb_nd;
  real_T rtb_ed;
  real_T rtb_Vab_mod;
  real_T rtb_Divide4_dh;
  real_T rtb_Divide;
  real_T rtb_Add2_lg4;
  real_T rtb_Add2_c5;
  real_T rtb_Divide_niq;
  real_T rtb_Divide4_in;
  real_T rtb_Add_b4;
  real_T rtb_Azb;
  real_T rtb_Add2_jk;
  real_T rtb_Ayb;
  real_T rtb_Divide4_lez;
  real_T rtb_rudder_cmd;
  real_T rtb_Divide3_dt;
  real_T rtb_Axb;
  real_T rtb_Divide4_jbf;
  real_T rtb_Sum8;
  real_T rtb_Divide5_fi2;
  real_T rtb_elevator_cmd;
  real_T rtb_Divide_hc;
  real_T rtb_Divide3_p2;
  real_T rtb_Divide4_om;
  real_T rtb_MathFunction_hl;
  real_T rtb_MathFunction1_l0;
  real_T rtb_Add1_ds;
  real_T rtb_throttle_cmd;
  real_T rtb_TrigonometricFunction1_kv;
  real_T rtb_aileron_cmd;
  real_T rtb_Sum5;
  real_T rtb_Add_n2;
  real_T rtb_Divide_e5;
  real_T rtb_Add1_i3;
  real_T rtb_Add_a;
  real_T rtb_Divide4_kov;
  real_T rtb_Divide_c3;
  real_T rtb_etaLon;
  real_T rtb_Divide1_g0[14];
  real_T rtb_Add1_kk;
  real_T rtb_Divide4_fe;
  real_T rtb_Divide3_ppi;
  real_T rtb_Divide4_m2;
  real_T rtb_Divide5_kwv;
  real_T rtb_Divide_mrb;
  real_T rtb_Divide3_av;
  real_T rtb_Divide4_il;
  real_T rtb_MathFunction_e1;
  real_T rtb_MathFunction1_o5;
  real_T rtb_Add1_gx3;
  real_T rtb_Add_i;
  real_T rtb_Divide_a;
  real_T rtb_Add1_an;
  real_T rtb_Add_em1;
  real_T rtb_Add1_nj;
  real_T rtb_Divide4_lx;
  real_T rtb_Divide3_ob;
  real_T rtb_Divide4_mdl;
  real_T rtb_Divide5_mg;
  real_T rtb_Divide_e4;
  real_T rtb_Divide3_jc;
  real_T rtb_Divide4_gi;
  real_T rtb_MathFunction_bbq;
  real_T rtb_MathFunction1_ea;
  real_T rtb_Add1_b0;
  real_T rtb_Add_kw;
  real_T rtb_Divide_p;
  real_T rtb_Add1_br4;
  real_T rtb_Add_fs;
  real_T rtb_Divide_j;
  real_T rtb_Divide4_bpl[14];
  real_T rtb_Divide4_eb;
  real_T rtb_Divide3_cas;
  real_T rtb_Divide4_gka;
  real_T rtb_Divide5_bum;
  real_T rtb_Divide_du;
  real_T rtb_Divide3_eun;
  real_T rtb_Divide4_mz;
  real_T rtb_MathFunction_dx;
  real_T rtb_MathFunction1_jh;
  real_T rtb_Add1_ev;
  real_T rtb_Add_he1;
  real_T rtb_Divide_nzj;
  real_T rtb_Add1_bw;
  real_T rtb_Add_k3;
  real_T rtb_Add_nd;
  real_T rtb_Divide4_md;
  real_T rtb_Divide3_kk;
  real_T rtb_Divide4_hd;
  real_T rtb_Divide5_mk;
  real_T rtb_Divide_ep;
  real_T rtb_Divide3_ku;
  real_T rtb_Divide4_cj;
  real_T rtb_MathFunction_pu;
  real_T rtb_MathFunction1_a;
  real_T rtb_Add1_ca;
  real_T rtb_Add_jb;
  real_T rtb_Divide_h5;
  real_T rtb_Add1_ag;
  real_T rtb_Add_oj;
  real_T rtb_Divide4_gq;
  real_T rtb_Divide3_ox;
  real_T rtb_Divide4_hx;
  real_T rtb_Divide5_ps;
  real_T rtb_Divide_el;
  real_T rtb_Divide3_cv;
  real_T rtb_Divide4_ie;
  real_T rtb_MathFunction_ne;
  real_T rtb_MathFunction1_ft;
  real_T rtb_Add_gf1;
  real_T rtb_TrigonometricFunction1_dr;
  real_T rtb_TrigonometricFunction2_aw;
  real_T rtb_Add1_bg;
  real_T rtb_Add_p0d;
  real_T rtb_Divide_ok;
  real_T rtb_Add1_efz;
  real_T rtb_Add_md;
  real_T rtb_Divide4_lw3;
  real_T rtb_Divide3_ld;
  real_T rtb_Divide4_lc;
  real_T rtb_Divide5_egl;
  real_T rtb_Divide_bas;
  real_T rtb_Divide3_n1;
  real_T rtb_Divide4_c3;
  real_T rtb_MathFunction_jc;
  real_T rtb_MathFunction1_l;
  real_T rtb_Saturation_i;
  real_T rtb_Add1_i1;
  real_T rtb_Add_dre;
  real_T rtb_Divide_bg;
  real_T rtb_Add1_cf;
  real_T rtb_Add_adw;
  real_T rtb_Divide4_bv;
  real_T rtb_Add_co;
  real_T rtb_Divide4_ft;
  real_T rtb_Divide5_gk;
  real_T rtb_Divide_l;
  real_T rtb_Divide3_iu1;
  real_T rtb_Divide4_p3cp;
  real_T rtb_MathFunction_dp;
  real_T rtb_Add1_hkq;
  real_T rtb_Divide_mhp;
  real_T rtb_Divide4_lgu;
  real_T rtb_Divide3_bk;
  real_T rtb_Divide4_l2;
  real_T rtb_Divide_mg;
  real_T rtb_Divide3_mja;
  real_T rtb_x_est_kk_f[14];
  real_T rtb_Divide4_ea;
  real_T rtb_Divide_kts;
  real_T rtb_Divide_jn[8];
  real_T rtb_Divide1_h2s[8];
  real_T rtb_Divide2_omo[8];
  real_T rtb_Divide3_ma[8];
  real_T rtb_Divide4_gc[8];
  real_T rtb_Divide5_l2g[8];
  real_T rtb_Divide6_b4[8];
  real_T rtb_Divide17[8];
  real_T rtb_Divide7_pl[8];
  real_T rtb_Divide8[8];
  real_T rtb_Divide9[8];
  real_T rtb_Divide10[8];
  real_T rtb_Divide13[8];
  real_T rtb_Divide12[8];
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_k;
  boolean_T rtb_RelationalOperator1;
  real_T rtb_VectorConcatenate[20];
  real_T rtb_Add_lzz;
  real_T rtb_Add_iq;
  real_T rtb_Product4_p[4];
  real_T rtb_x_G_trim[12];
  real_T rtb_x_tilde_G[12];
  real_T rtb_Gain_cl;
  real_T rtb_Product3_g[36];
  real_T rtb_P_kk1[36];
  real_T rtb_Product1_n[36];
  real_T rtb_Gain4_c2[196];
  real_T rtb_P_kk1_f[196];
  real_T rtb_Product2_fp[196];
  real_T rtb_H_k[112];
  real_T rtb_Product1_f[112];
  real_T rtb_Add_cg4[36];
  real_T rtb_Add_l3[196];
  real_T rtb_HT_k[112];
  real_T rtb_x_k[24];
  int32_T i;
  real_T rtb_H_k_0[64];
  real_T rtb_Product1_g[36];
  real_T tmp[36];
  real_T tmp_0[6];
  real_T rtb_FixPtRelationalOperator_0[6];
  real_T rtb_Product2_hq[196];
  real_T rtb_Divide_ps[112];
  real_T rtb_H_k_1[64];
  real_T tmp_1[8];
  real_T rtb_Divide4_ji[4];
  real_T rtb_Divide4_ji_0[4];
  real_T tmp_2[24];
  real_T tmp_3[24];
  int32_T i_0;
  real_T tmp_4[80];
  int32_T i_1;
  real_T rtb_DataStoreRead3_b_idx_2;
  real_T rtb_DataStoreRead3_b_idx_1;
  real_T rtb_DataStoreRead3_b_idx_0;
  real_T rtb_x_W1_dot_idx_0;
  real_T tmp_5;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/PIC//CIC'
   */
  rtb_DataTypeConversion1 = EKF_IFS_2_U.PICCIC;

  /* DataStoreRead: '<S7>/Data Store Read4' */
  rtb_DataStoreRead4 = EKF_IFS_2_DW.sw_time;

  /* DataStoreRead: '<S7>/Data Store Read3' */
  rtb_DataStoreRead3 = EKF_IFS_2_DW.remote_throttle_mem;

  /* DataStoreRead: '<S7>/Data Store Read1' */
  rtb_DataStoreRead1 = EKF_IFS_2_DW.remote_elevator_mem;

  /* DataStoreRead: '<S7>/Data Store Read2' */
  rtb_DataStoreRead2 = EKF_IFS_2_DW.remote_aileron_mem;

  /* DataStoreRead: '<S7>/Data Store Read5' */
  rtb_DataStoreRead5 = EKF_IFS_2_DW.remote_rudder_mem;

  /* BusCreator: '<S7>/BusConversion_InsertedFor_Swtching Logic_at_inport_6' incorporates:
   *  Inport: '<Root>/R//C'
   */
  rtb_BusConversion_InsertedFor_0 = EKF_IFS_2_U.RC.throttle_cmd;
  rtb_BusConversion_InsertedFor_1 = EKF_IFS_2_U.RC.elevator_cmd;
  rtb_BusConversion_InsertedFor_2 = EKF_IFS_2_U.RC.aileron_cmd;
  rtb_BusConversion_InsertedFor_3 = EKF_IFS_2_U.RC.rudder_cmd;

  /* DataStoreRead: '<S8>/Data Store Read2' */
  rtb_DataStoreRead2_h = EKF_IFS_2_DW.Waypoint_Index;

  /* DataStoreRead: '<S8>/Data Store Read1' */
  rtb_DataStoreRead1_b = EKF_IFS_2_DW.PIC_CIC_Last;

  /* DataStoreRead: '<S8>/Data Store Read3' */
  rtb_DataStoreRead3_b_idx_0 = EKF_IFS_2_DW.Start_Wpt[0];
  rtb_DataStoreRead3_b_idx_1 = EKF_IFS_2_DW.Start_Wpt[1];
  rtb_DataStoreRead3_b_idx_2 = EKF_IFS_2_DW.Start_Wpt[2];

  /* DataStoreRead: '<S8>/Data Store Read4' */
  rtb_DataStoreRead4_n = EKF_IFS_2_DW.Home_reset;

  /* Gain: '<S80>/Gain' incorporates:
   *  UnitDelay: '<S46>/x_est_[0//0]'
   */
  rtb_Divide_bi = EKF_IFS_2_P.Gain_Gain_j * EKF_IFS_2_DW.x_est_00_DSTATE[3];

  /* Gain: '<S78>/Gain' incorporates:
   *  UnitDelay: '<S46>/x_est_[0//0]'
   */
  rtb_Divide4_ot = EKF_IFS_2_P.Gain_Gain_c * EKF_IFS_2_DW.x_est_00_DSTATE[4];

  /* Gain: '<S79>/Gain' incorporates:
   *  UnitDelay: '<S46>/x_est_[0//0]'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.Gain_Gain_pd * EKF_IFS_2_DW.x_est_00_DSTATE[5];

  /* Trigonometry: '<S77>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_ey = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S77>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S77>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S77>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_bmn = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S77>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_f_RDRx_est_kuk = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S77>/Add2' incorporates:
   *  Product: '<S77>/Divide1'
   *  Product: '<S77>/Divide2'
   *  Product: '<S77>/Divide3'
   *  Product: '<S77>/Divide4'
   *  Product: '<S77>/Divide5'
   *  Product: '<S77>/Divide6'
   *  Product: '<S77>/Divide7'
   *  Sum: '<S77>/Add1'
   *  Sum: '<S77>/Add3'
   *  Trigonometry: '<S77>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_f_RDRx_est_kuk = ((rtb_Add1_bmn * rtb_f_RDRx_est_kuk * rtb_Add_ey -
    rtb_Add1_ma * rtb_Divide_bd) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                        EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                        (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_Add_ey) +
    (rtb_Add1_bmn * rtb_Add1_ma * rtb_Add_ey + rtb_f_RDRx_est_kuk *
     rtb_Divide_bd) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S75>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_bmn = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S75>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S75>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S75>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_ey = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S75>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_f_AILx_est_kuk = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S75>/Add2' incorporates:
   *  Product: '<S75>/Divide1'
   *  Product: '<S75>/Divide2'
   *  Product: '<S75>/Divide3'
   *  Product: '<S75>/Divide4'
   *  Product: '<S75>/Divide5'
   *  Product: '<S75>/Divide6'
   *  Product: '<S75>/Divide7'
   *  Sum: '<S75>/Add1'
   *  Sum: '<S75>/Add3'
   *  Trigonometry: '<S75>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_f_AILx_est_kuk = ((rtb_Add_ey * rtb_f_AILx_est_kuk * rtb_Add1_bmn +
    rtb_Divide_bd * rtb_Add1_ma) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                        EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                        (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_Add1_bmn) +
    (rtb_Add_ey * rtb_Divide_bd * rtb_Add1_bmn - rtb_f_AILx_est_kuk *
     rtb_Add1_ma) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Sum: '<S76>/Sum' incorporates:
   *  Constant: '<S76>/gravity'
   *  Product: '<S76>/Divide1'
   *  Product: '<S76>/Divide2'
   *  Product: '<S76>/Divide3'
   *  Sum: '<S76>/Add1'
   *  Trigonometry: '<S76>/Trigonometric Function'
   *  Trigonometry: '<S76>/Trigonometric Function1'
   *  Trigonometry: '<S76>/Trigonometric Function2'
   *  Trigonometry: '<S76>/Trigonometric Function4'
   *  Trigonometry: '<S76>/Trigonometric Function5'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_bmn = ((EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * sin
                   (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) - cos
                   (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * sin
                   (EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) *
                   EKF_IFS_2_DW.UnitDelay1_DSTATE[4]) - cos
                  (EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * cos
                  (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) *
                  EKF_IFS_2_DW.UnitDelay1_DSTATE[5]) - EKF_IFS_2_P.g;

  /* Trigonometry: '<S98>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S98>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S98>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S98>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_MathFunction5 = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S98>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_MathFunction6 = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S98>/Add2' incorporates:
   *  Product: '<S98>/Divide1'
   *  Product: '<S98>/Divide2'
   *  Product: '<S98>/Divide3'
   *  Product: '<S98>/Divide4'
   *  Product: '<S98>/Divide5'
   *  Product: '<S98>/Divide6'
   *  Product: '<S98>/Divide7'
   *  Sum: '<S98>/Add1'
   *  Sum: '<S98>/Add3'
   *  Trigonometry: '<S98>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_MathFunction6 = ((rtb_MathFunction5 * rtb_MathFunction6 * rtb_Divide4_d0r
                        - rtb_Add_nv * rtb_sin_atrack) *
                       EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                       EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                       (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_Divide4_d0r) +
    (rtb_MathFunction5 * rtb_Add_nv * rtb_Divide4_d0r + rtb_MathFunction6 *
     rtb_sin_atrack) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S96>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_MathFunction5 = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S96>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S96>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S96>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S96>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_cos_atrack = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S96>/Add2' incorporates:
   *  Product: '<S96>/Divide1'
   *  Product: '<S96>/Divide2'
   *  Product: '<S96>/Divide3'
   *  Product: '<S96>/Divide4'
   *  Product: '<S96>/Divide5'
   *  Product: '<S96>/Divide6'
   *  Product: '<S96>/Divide7'
   *  Sum: '<S96>/Add1'
   *  Sum: '<S96>/Add3'
   *  Trigonometry: '<S96>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_cos_atrack = ((rtb_Divide4_d0r * rtb_cos_atrack * rtb_MathFunction5 +
                     rtb_sin_atrack * rtb_Add_nv) *
                    EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                    EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_MathFunction5) +
    (rtb_Divide4_d0r * rtb_sin_atrack * rtb_MathFunction5 - rtb_cos_atrack *
     rtb_Add_nv) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S84>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S84>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S84>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S84>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S84>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S84>/Add2' incorporates:
   *  Product: '<S84>/Divide1'
   *  Product: '<S84>/Divide2'
   *  Product: '<S84>/Divide3'
   *  Product: '<S84>/Divide4'
   *  Product: '<S84>/Divide5'
   *  Product: '<S84>/Divide6'
   *  Product: '<S84>/Divide7'
   *  Sum: '<S84>/Add1'
   *  Sum: '<S84>/Add3'
   *  Trigonometry: '<S84>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = ((rtb_Divide_bd * rtb_Add1_ma * rtb_sin_atrack - rtb_Add_nv *
                     rtb_Divide4_d0r) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                    EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_sin_atrack) +
    (rtb_Divide_bd * rtb_Add_nv * rtb_sin_atrack + rtb_Add1_ma * rtb_Divide4_d0r)
    * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S82>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S82>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S82>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S82>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S82>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_ey = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S82>/Add2' incorporates:
   *  Product: '<S82>/Divide1'
   *  Product: '<S82>/Divide2'
   *  Product: '<S82>/Divide3'
   *  Product: '<S82>/Divide4'
   *  Product: '<S82>/Divide5'
   *  Product: '<S82>/Divide6'
   *  Product: '<S82>/Divide7'
   *  Sum: '<S82>/Add1'
   *  Sum: '<S82>/Add3'
   *  Trigonometry: '<S82>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = ((rtb_Add1_ma * rtb_Add_ey * rtb_Add_nv + rtb_Divide4_d0r *
                 rtb_Divide_bd) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_Add_nv) + (rtb_Add1_ma
    * rtb_Divide4_d0r * rtb_Add_nv - rtb_Add_ey * rtb_Divide_bd) *
    EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Product: '<S57>/Divide1' incorporates:
   *  Constant: '<S57>/delta'
   *  Constant: '<S83>/gravity'
   *  Gain: '<S85>/Gain'
   *  Gain: '<S86>/Gain'
   *  Gain: '<S87>/Gain'
   *  Product: '<S83>/Divide1'
   *  Product: '<S83>/Divide2'
   *  Product: '<S83>/Divide3'
   *  Sum: '<S57>/Sum1'
   *  Sum: '<S83>/Add1'
   *  Sum: '<S83>/Sum'
   *  Trigonometry: '<S83>/Trigonometric Function'
   *  Trigonometry: '<S83>/Trigonometric Function1'
   *  Trigonometry: '<S83>/Trigonometric Function2'
   *  Trigonometry: '<S83>/Trigonometric Function4'
   *  Trigonometry: '<S83>/Trigonometric Function5'
   *  UnitDelay: '<S46>/Unit Delay1'
   *  UnitDelay: '<S46>/x_est_[0//0]'
   */
  rtb_Divide1_mwl[0] = (EKF_IFS_2_P.Gain_Gain_ae * EKF_IFS_2_DW.x_est_00_DSTATE
                        [3] - rtb_Divide_bi) / EKF_IFS_2_P.delta_Value;
  rtb_Divide1_mwl[1] = (EKF_IFS_2_P.Gain_Gain_a5 * EKF_IFS_2_DW.x_est_00_DSTATE
                        [4] - rtb_Divide4_ot) / EKF_IFS_2_P.delta_Value;
  rtb_Divide1_mwl[2] = (EKF_IFS_2_P.Gain_Gain_d * EKF_IFS_2_DW.x_est_00_DSTATE[5]
                        - rtb_Divide4_jaz) / EKF_IFS_2_P.delta_Value;
  rtb_Divide1_mwl[3] = (rtb_sin_atrack - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value;
  rtb_Divide1_mwl[4] = (rtb_Add_nv - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value;
  rtb_Divide1_mwl[5] = ((((EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * sin
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[1])
    * sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4])
    - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * cos
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5]) -
    EKF_IFS_2_P.g) - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value;

  /* Trigonometry: '<S91>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S91>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S91>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S91>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S91>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S91>/Add2' incorporates:
   *  Product: '<S91>/Divide1'
   *  Product: '<S91>/Divide2'
   *  Product: '<S91>/Divide3'
   *  Product: '<S91>/Divide4'
   *  Product: '<S91>/Divide5'
   *  Product: '<S91>/Divide6'
   *  Product: '<S91>/Divide7'
   *  Sum: '<S91>/Add1'
   *  Sum: '<S91>/Add3'
   *  Trigonometry: '<S91>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = ((rtb_Divide_bd * rtb_Add1_ma * rtb_sin_atrack - rtb_Add_nv *
                     rtb_Divide4_d0r) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                    EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_sin_atrack) +
    (rtb_Divide_bd * rtb_Add_nv * rtb_sin_atrack + rtb_Add1_ma * rtb_Divide4_d0r)
    * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S89>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S89>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S89>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S89>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S89>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_ey = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S89>/Add2' incorporates:
   *  Product: '<S89>/Divide1'
   *  Product: '<S89>/Divide2'
   *  Product: '<S89>/Divide3'
   *  Product: '<S89>/Divide4'
   *  Product: '<S89>/Divide5'
   *  Product: '<S89>/Divide6'
   *  Product: '<S89>/Divide7'
   *  Sum: '<S89>/Add1'
   *  Sum: '<S89>/Add3'
   *  Trigonometry: '<S89>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = ((rtb_Add1_ma * rtb_Add_ey * rtb_Add_nv + rtb_Divide4_d0r *
                 rtb_Divide_bd) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_Add_nv) + (rtb_Add1_ma
    * rtb_Divide4_d0r * rtb_Add_nv - rtb_Add_ey * rtb_Divide_bd) *
    EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Product: '<S57>/Divide2' incorporates:
   *  Constant: '<S57>/delta'
   *  Constant: '<S90>/gravity'
   *  Gain: '<S92>/Gain'
   *  Gain: '<S93>/Gain'
   *  Gain: '<S94>/Gain'
   *  Product: '<S90>/Divide1'
   *  Product: '<S90>/Divide2'
   *  Product: '<S90>/Divide3'
   *  Sum: '<S57>/Sum2'
   *  Sum: '<S90>/Add1'
   *  Sum: '<S90>/Sum'
   *  Trigonometry: '<S90>/Trigonometric Function'
   *  Trigonometry: '<S90>/Trigonometric Function1'
   *  Trigonometry: '<S90>/Trigonometric Function2'
   *  Trigonometry: '<S90>/Trigonometric Function4'
   *  Trigonometry: '<S90>/Trigonometric Function5'
   *  UnitDelay: '<S46>/Unit Delay1'
   *  UnitDelay: '<S46>/x_est_[0//0]'
   */
  rtb_Divide2_fm[0] = (EKF_IFS_2_P.Gain_Gain_d5 * EKF_IFS_2_DW.x_est_00_DSTATE[3]
                       - rtb_Divide_bi) / EKF_IFS_2_P.delta_Value;
  rtb_Divide2_fm[1] = (EKF_IFS_2_P.Gain_Gain_oi * EKF_IFS_2_DW.x_est_00_DSTATE[4]
                       - rtb_Divide4_ot) / EKF_IFS_2_P.delta_Value;
  rtb_Divide2_fm[2] = (EKF_IFS_2_P.Gain_Gain_ow * EKF_IFS_2_DW.x_est_00_DSTATE[5]
                       - rtb_Divide4_jaz) / EKF_IFS_2_P.delta_Value;
  rtb_Divide2_fm[3] = (rtb_sin_atrack - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value;
  rtb_Divide2_fm[4] = (rtb_Add_nv - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value;
  rtb_Divide2_fm[5] = ((((EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * sin
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[1])
    * sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4])
    - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * cos
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5]) -
                        EKF_IFS_2_P.g) - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value;

  /* Trigonometry: '<S119>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S119>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S119>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S119>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S119>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S119>/Add2' incorporates:
   *  Product: '<S119>/Divide1'
   *  Product: '<S119>/Divide2'
   *  Product: '<S119>/Divide3'
   *  Product: '<S119>/Divide4'
   *  Product: '<S119>/Divide5'
   *  Product: '<S119>/Divide6'
   *  Product: '<S119>/Divide7'
   *  Sum: '<S119>/Add1'
   *  Sum: '<S119>/Add3'
   *  Trigonometry: '<S119>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = ((rtb_Divide_bd * rtb_Add1_ma * rtb_sin_atrack - rtb_Add_nv *
                     rtb_Divide4_d0r) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                    EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_sin_atrack) +
    (rtb_Divide_bd * rtb_Add_nv * rtb_sin_atrack + rtb_Add1_ma * rtb_Divide4_d0r)
    * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S117>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S117>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S117>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S117>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S117>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_ey = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S117>/Add2' incorporates:
   *  Product: '<S117>/Divide1'
   *  Product: '<S117>/Divide2'
   *  Product: '<S117>/Divide3'
   *  Product: '<S117>/Divide4'
   *  Product: '<S117>/Divide5'
   *  Product: '<S117>/Divide6'
   *  Product: '<S117>/Divide7'
   *  Sum: '<S117>/Add1'
   *  Sum: '<S117>/Add3'
   *  Trigonometry: '<S117>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = ((rtb_Add1_ma * rtb_Add_ey * rtb_Add_nv + rtb_Divide4_d0r *
                 rtb_Divide_bd) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_Add_nv) + (rtb_Add1_ma
    * rtb_Divide4_d0r * rtb_Add_nv - rtb_Add_ey * rtb_Divide_bd) *
    EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Product: '<S57>/Divide3' incorporates:
   *  Constant: '<S118>/gravity'
   *  Constant: '<S57>/delta'
   *  Gain: '<S120>/Gain'
   *  Gain: '<S121>/Gain'
   *  Gain: '<S122>/Gain'
   *  Product: '<S118>/Divide1'
   *  Product: '<S118>/Divide2'
   *  Product: '<S118>/Divide3'
   *  Sum: '<S118>/Add1'
   *  Sum: '<S118>/Sum'
   *  Sum: '<S57>/Sum3'
   *  Sum: '<S66>/Add'
   *  Trigonometry: '<S118>/Trigonometric Function'
   *  Trigonometry: '<S118>/Trigonometric Function1'
   *  Trigonometry: '<S118>/Trigonometric Function2'
   *  Trigonometry: '<S118>/Trigonometric Function4'
   *  Trigonometry: '<S118>/Trigonometric Function5'
   *  UnitDelay: '<S46>/Unit Delay1'
   *  UnitDelay: '<S46>/x_est_[0//0]'
   */
  rtb_Divide3_im[0] = ((EKF_IFS_2_P.delta_Value + EKF_IFS_2_DW.x_est_00_DSTATE[3])
                       * EKF_IFS_2_P.Gain_Gain_bv - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value;
  rtb_Divide3_im[1] = (EKF_IFS_2_P.Gain_Gain_k * EKF_IFS_2_DW.x_est_00_DSTATE[4]
                       - rtb_Divide4_ot) / EKF_IFS_2_P.delta_Value;
  rtb_Divide3_im[2] = (EKF_IFS_2_P.Gain_Gain_gu * EKF_IFS_2_DW.x_est_00_DSTATE[5]
                       - rtb_Divide4_jaz) / EKF_IFS_2_P.delta_Value;
  rtb_Divide3_im[3] = (rtb_sin_atrack - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value;
  rtb_Divide3_im[4] = (rtb_Add_nv - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value;
  rtb_Divide3_im[5] = ((((EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * sin
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[1])
    * sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4])
    - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * cos
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5]) -
                        EKF_IFS_2_P.g) - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value;

  /* Trigonometry: '<S105>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S105>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S105>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S105>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S105>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S105>/Add2' incorporates:
   *  Product: '<S105>/Divide1'
   *  Product: '<S105>/Divide2'
   *  Product: '<S105>/Divide3'
   *  Product: '<S105>/Divide4'
   *  Product: '<S105>/Divide5'
   *  Product: '<S105>/Divide6'
   *  Product: '<S105>/Divide7'
   *  Sum: '<S105>/Add1'
   *  Sum: '<S105>/Add3'
   *  Trigonometry: '<S105>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = ((rtb_Divide_bd * rtb_Add1_ma * rtb_sin_atrack - rtb_Add_nv *
                     rtb_Divide4_d0r) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                    EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_sin_atrack) +
    (rtb_Divide_bd * rtb_Add_nv * rtb_sin_atrack + rtb_Add1_ma * rtb_Divide4_d0r)
    * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S103>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S103>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S103>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S103>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S103>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_ey = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S103>/Add2' incorporates:
   *  Product: '<S103>/Divide1'
   *  Product: '<S103>/Divide2'
   *  Product: '<S103>/Divide3'
   *  Product: '<S103>/Divide4'
   *  Product: '<S103>/Divide5'
   *  Product: '<S103>/Divide6'
   *  Product: '<S103>/Divide7'
   *  Sum: '<S103>/Add1'
   *  Sum: '<S103>/Add3'
   *  Trigonometry: '<S103>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = ((rtb_Add1_ma * rtb_Add_ey * rtb_Add_nv + rtb_Divide4_d0r *
                 rtb_Divide_bd) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_Add_nv) + (rtb_Add1_ma
    * rtb_Divide4_d0r * rtb_Add_nv - rtb_Add_ey * rtb_Divide_bd) *
    EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Product: '<S57>/Divide4' incorporates:
   *  Constant: '<S104>/gravity'
   *  Constant: '<S57>/delta'
   *  Gain: '<S106>/Gain'
   *  Gain: '<S107>/Gain'
   *  Gain: '<S108>/Gain'
   *  Product: '<S104>/Divide1'
   *  Product: '<S104>/Divide2'
   *  Product: '<S104>/Divide3'
   *  Sum: '<S104>/Add1'
   *  Sum: '<S104>/Sum'
   *  Sum: '<S57>/Sum4'
   *  Sum: '<S64>/Add'
   *  Trigonometry: '<S104>/Trigonometric Function'
   *  Trigonometry: '<S104>/Trigonometric Function1'
   *  Trigonometry: '<S104>/Trigonometric Function2'
   *  Trigonometry: '<S104>/Trigonometric Function4'
   *  Trigonometry: '<S104>/Trigonometric Function5'
   *  UnitDelay: '<S46>/Unit Delay1'
   *  UnitDelay: '<S46>/x_est_[0//0]'
   */
  rtb_Product1_gr[0] = (EKF_IFS_2_P.Gain_Gain_nh * EKF_IFS_2_DW.x_est_00_DSTATE
                        [3] - rtb_Divide_bi) / EKF_IFS_2_P.delta_Value;
  rtb_Product1_gr[1] = ((EKF_IFS_2_P.delta_Value + EKF_IFS_2_DW.x_est_00_DSTATE
    [4]) * EKF_IFS_2_P.Gain_Gain_dl - rtb_Divide4_ot) / EKF_IFS_2_P.delta_Value;
  rtb_Product1_gr[2] = (EKF_IFS_2_P.Gain_Gain_l * EKF_IFS_2_DW.x_est_00_DSTATE[5]
                        - rtb_Divide4_jaz) / EKF_IFS_2_P.delta_Value;
  rtb_Product1_gr[3] = (rtb_sin_atrack - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value;
  rtb_Product1_gr[4] = (rtb_Add_nv - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value;
  rtb_Product1_gr[5] = ((((EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * sin
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[1])
    * sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4])
    - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * cos
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5]) -
    EKF_IFS_2_P.g) - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value;

  /* Trigonometry: '<S112>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S112>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S112>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S112>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S112>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S112>/Add2' incorporates:
   *  Product: '<S112>/Divide1'
   *  Product: '<S112>/Divide2'
   *  Product: '<S112>/Divide3'
   *  Product: '<S112>/Divide4'
   *  Product: '<S112>/Divide5'
   *  Product: '<S112>/Divide6'
   *  Product: '<S112>/Divide7'
   *  Sum: '<S112>/Add1'
   *  Sum: '<S112>/Add3'
   *  Trigonometry: '<S112>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_sin_atrack = ((rtb_Divide_bd * rtb_Add1_ma * rtb_sin_atrack - rtb_Add_nv *
                     rtb_Divide4_d0r) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                    EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_sin_atrack) +
    (rtb_Divide_bd * rtb_Add_nv * rtb_sin_atrack + rtb_Add1_ma * rtb_Divide4_d0r)
    * EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S110>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S110>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide4_d0r = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S110>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Divide_bd = cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S110>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add1_ma = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S110>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_ey = sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S110>/Add2' incorporates:
   *  Product: '<S110>/Divide1'
   *  Product: '<S110>/Divide2'
   *  Product: '<S110>/Divide3'
   *  Product: '<S110>/Divide4'
   *  Product: '<S110>/Divide5'
   *  Product: '<S110>/Divide6'
   *  Product: '<S110>/Divide7'
   *  Sum: '<S110>/Add1'
   *  Sum: '<S110>/Add3'
   *  Trigonometry: '<S110>/Trigonometric Function1'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Add_nv = ((rtb_Add1_ma * rtb_Add_ey * rtb_Add_nv + rtb_Divide4_d0r *
                 rtb_Divide_bd) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4] +
                EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * cos
                (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * rtb_Add_nv) + (rtb_Add1_ma
    * rtb_Divide4_d0r * rtb_Add_nv - rtb_Add_ey * rtb_Divide_bd) *
    EKF_IFS_2_DW.UnitDelay1_DSTATE[5];

  /* Gain: '<S57>/Gain4' incorporates:
   *  Constant: '<S111>/gravity'
   *  Constant: '<S57>/delta'
   *  Constant: '<S97>/gravity'
   *  Gain: '<S100>/Gain'
   *  Gain: '<S101>/Gain'
   *  Gain: '<S113>/Gain'
   *  Gain: '<S114>/Gain'
   *  Gain: '<S115>/Gain'
   *  Gain: '<S99>/Gain'
   *  Product: '<S111>/Divide1'
   *  Product: '<S111>/Divide2'
   *  Product: '<S111>/Divide3'
   *  Product: '<S57>/Divide'
   *  Product: '<S57>/Divide5'
   *  Product: '<S97>/Divide1'
   *  Product: '<S97>/Divide2'
   *  Product: '<S97>/Divide3'
   *  Sum: '<S111>/Add1'
   *  Sum: '<S111>/Sum'
   *  Sum: '<S57>/Sum'
   *  Sum: '<S57>/Sum5'
   *  Sum: '<S65>/Add1'
   *  Sum: '<S97>/Add1'
   *  Sum: '<S97>/Sum'
   *  Trigonometry: '<S111>/Trigonometric Function'
   *  Trigonometry: '<S111>/Trigonometric Function1'
   *  Trigonometry: '<S111>/Trigonometric Function2'
   *  Trigonometry: '<S111>/Trigonometric Function4'
   *  Trigonometry: '<S111>/Trigonometric Function5'
   *  Trigonometry: '<S97>/Trigonometric Function'
   *  Trigonometry: '<S97>/Trigonometric Function1'
   *  Trigonometry: '<S97>/Trigonometric Function2'
   *  Trigonometry: '<S97>/Trigonometric Function4'
   *  Trigonometry: '<S97>/Trigonometric Function5'
   *  UnitDelay: '<S46>/Unit Delay1'
   *  UnitDelay: '<S46>/x_est_[0//0]'
   */
  rtb_Product3_g[0] = (EKF_IFS_2_P.Gain_Gain_fb * EKF_IFS_2_DW.x_est_00_DSTATE[3]
                       - rtb_Divide_bi) / EKF_IFS_2_P.delta_Value *
    EKF_IFS_2_P.dt;
  rtb_Product3_g[1] = (EKF_IFS_2_P.Gain_Gain_i * EKF_IFS_2_DW.x_est_00_DSTATE[4]
                       - rtb_Divide4_ot) / EKF_IFS_2_P.delta_Value *
    EKF_IFS_2_P.dt;
  rtb_Product3_g[2] = (EKF_IFS_2_P.Gain_Gain_nky * EKF_IFS_2_DW.x_est_00_DSTATE
                       [5] - rtb_Divide4_jaz) / EKF_IFS_2_P.delta_Value *
    EKF_IFS_2_P.dt;
  rtb_Product3_g[3] = (rtb_MathFunction6 - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value * EKF_IFS_2_P.dt;
  rtb_Product3_g[4] = (rtb_cos_atrack - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value * EKF_IFS_2_P.dt;
  rtb_Product3_g[5] = ((((EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * sin
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[1])
    * sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4])
    - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * cos
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5]) -
                        EKF_IFS_2_P.g) - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value
    * EKF_IFS_2_P.dt;
  for (i = 0; i < 6; i++) {
    rtb_Subtract1[i] = EKF_IFS_2_DW.x_est_00_DSTATE[i];
    rtb_u_k1[i] = EKF_IFS_2_DW.UnitDelay1_DSTATE[i];
    rtb_Product3_g[i + 6] = EKF_IFS_2_P.dt * rtb_Divide1_mwl[i];
  }

  for (i = 0; i < 6; i++) {
    rtb_Product3_g[i + 12] = EKF_IFS_2_P.dt * rtb_Divide2_fm[i];
  }

  for (i = 0; i < 6; i++) {
    rtb_Product3_g[i + 18] = EKF_IFS_2_P.dt * rtb_Divide3_im[i];
  }

  for (i = 0; i < 6; i++) {
    rtb_Product3_g[i + 24] = EKF_IFS_2_P.dt * rtb_Product1_gr[i];
  }

  rtb_Product3_g[30] = (EKF_IFS_2_P.Gain_Gain_fj * EKF_IFS_2_DW.x_est_00_DSTATE
                        [3] - rtb_Divide_bi) / EKF_IFS_2_P.delta_Value *
    EKF_IFS_2_P.dt;
  rtb_Product3_g[31] = (EKF_IFS_2_P.Gain_Gain_ag * EKF_IFS_2_DW.x_est_00_DSTATE
                        [4] - rtb_Divide4_ot) / EKF_IFS_2_P.delta_Value *
    EKF_IFS_2_P.dt;
  rtb_Product3_g[32] = ((EKF_IFS_2_P.delta_Value + EKF_IFS_2_DW.x_est_00_DSTATE
    [5]) * EKF_IFS_2_P.Gain_Gain_ir - rtb_Divide4_jaz) / EKF_IFS_2_P.delta_Value
    * EKF_IFS_2_P.dt;
  rtb_Product3_g[33] = (rtb_sin_atrack - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value * EKF_IFS_2_P.dt;
  rtb_Product3_g[34] = (rtb_Add_nv - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value * EKF_IFS_2_P.dt;
  rtb_Product3_g[35] = ((((EKF_IFS_2_DW.UnitDelay1_DSTATE[3] * sin
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[1])
    * sin(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[4])
    - cos(EKF_IFS_2_DW.UnitDelay1_DSTATE[0]) * cos
    (EKF_IFS_2_DW.UnitDelay1_DSTATE[1]) * EKF_IFS_2_DW.UnitDelay1_DSTATE[5]) -
    EKF_IFS_2_P.g) - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value * EKF_IFS_2_P.dt;

  /* End of Gain: '<S57>/Gain4' */

  /* Product: '<S60>/Matrix Multiply' */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_P_kk1[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_P_kk1[i + 6 * i_0] += rtb_Product3_g[6 * i_1 + i] * rtb_Product3_g[6
          * i_0 + i_1];
      }
    }
  }

  /* End of Product: '<S60>/Matrix Multiply' */

  /* Product: '<S60>/Matrix Multiply1' */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Product1_n[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product1_n[i + 6 * i_0] += rtb_P_kk1[6 * i_1 + i] * rtb_Product3_g[6
          * i_0 + i_1];
      }
    }
  }

  /* End of Product: '<S60>/Matrix Multiply1' */

  /* Product: '<S60>/Matrix Multiply2' incorporates:
   *  Gain: '<S60>/Gain2'
   */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Product1_g[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product1_g[i + 6 * i_0] += rtb_Product1_n[6 * i_1 + i] *
          rtb_Product3_g[6 * i_0 + i_1];
      }
    }
  }

  /* End of Product: '<S60>/Matrix Multiply2' */

  /* Sum: '<S60>/Add' incorporates:
   *  Constant: '<S60>/Constant'
   *  Gain: '<S60>/Gain'
   *  Gain: '<S60>/Gain1'
   *  Gain: '<S60>/Gain2'
   */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Add_cg4[i_0 + 6 * i] = (((EKF_IFS_2_P.Constant_Value_l[6 * i + i_0] +
        rtb_Product3_g[6 * i + i_0]) + rtb_P_kk1[6 * i + i_0] *
        EKF_IFS_2_P.Gain_Gain_ot) + rtb_Product1_n[6 * i + i_0] *
        EKF_IFS_2_P.Gain1_Gain) + rtb_Product1_g[6 * i + i_0] *
        EKF_IFS_2_P.Gain2_Gain;
    }
  }

  /* End of Sum: '<S60>/Add' */

  /* Product: '<S52>/Product1' incorporates:
   *  MATLAB Function: '<S52>/Transpose'
   *  UnitDelay: '<S52>/P_est_[0//0]'
   */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/EKF/K[k] (navigation)/Transpose': '<S59>:1' */
  /* '<S59>:1:4' */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp[i + 6 * i_0] += EKF_IFS_2_DW.P_est_00_DSTATE[6 * i_1 + i] *
          rtb_Add_cg4[6 * i_1 + i_0];
      }
    }
  }

  /* Sum: '<S52>/Subtract1' incorporates:
   *  Constant: '<S52>/Q_[k-1]'
   *  Product: '<S52>/Product1'
   */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_5 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp_5 += rtb_Add_cg4[6 * i_1 + i] * tmp[6 * i_0 + i_1];
      }

      rtb_P_kk1[i + 6 * i_0] = EKF_IFS_2_P.Q_obs_nav[6 * i_0 + i] + tmp_5;
    }
  }

  /* End of Sum: '<S52>/Subtract1' */

  /* MATLAB Function: '<S58>/Transpose' incorporates:
   *  Constant: '<S52>/H_[k]'
   */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/EKF/K[k] (navigation)/K_[k]/Transpose': '<S124>:1' */
  /* '<S124>:1:4' */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Product3_g[i_0 + 6 * i] = EKF_IFS_2_P.H_k_Value[6 * i_0 + i];
    }
  }

  /* End of MATLAB Function: '<S58>/Transpose' */

  /* Product: '<S58>/Product' */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/EKF/K[k] (navigation)/K_[k]/Inverse': '<S123>:1' */
  /* '<S123>:1:4' */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Product1_g[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product1_g[i + 6 * i_0] += rtb_P_kk1[6 * i_1 + i] * rtb_Product3_g[6
          * i_0 + i_1];
      }
    }
  }

  /* Sum: '<S58>/Subtract2' incorporates:
   *  Constant: '<S52>/H_[k]'
   *  Constant: '<S52>/R_[k]'
   *  Product: '<S58>/Product'
   */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_5 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp_5 += EKF_IFS_2_P.H_k_Value[6 * i_1 + i] * rtb_Product1_g[6 * i_0 +
          i_1];
      }

      tmp[i + 6 * i_0] = EKF_IFS_2_P.R_obs_nav[6 * i_0 + i] + tmp_5;
    }
  }

  memcpy(&rtb_Product1_g[0], &tmp[0], 36U * sizeof(real_T));

  /* End of Sum: '<S58>/Subtract2' */

  /* MATLAB Function: '<S58>/Inverse' */
  EKF_IFS_2_invNxN(rtb_Product1_g, tmp);

  /* Product: '<S58>/Product1' */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Product1_g[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product1_g[i + 6 * i_0] += rtb_Product3_g[6 * i_1 + i] * tmp[6 * i_0
          + i_1];
      }
    }
  }

  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Product1_n[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        rtb_Product1_n[i + 6 * i_0] += rtb_P_kk1[6 * i_1 + i] * rtb_Product1_g[6
          * i_0 + i_1];
      }
    }
  }

  /* End of Product: '<S58>/Product1' */

  /* Product: '<S46>/Product' incorporates:
   *  Inport: '<Root>/Enable//Disable'
   */
  for (i = 0; i < 36; i++) {
    rtb_Product3_g[i] = rtb_Product1_n[i] * (real_T)EKF_IFS_2_U.EnableDisable;
  }

  /* End of Product: '<S46>/Product' */

  /* MATLAB Function: '<S47>/Convert Lat//Lon//Alt to Flat Earth' incorporates:
   *  Inport: '<Root>/GPS Position'
   *  Inport: '<Root>/Waypoints IN'
   */
  EKF_ConvertLatLonAlttoFlatEarth(&EKF_IFS_2_U.WaypointsIN,
    EKF_IFS_2_U.GPSPosition.Altitude, EKF_IFS_2_U.GPSPosition.Latitude,
    EKF_IFS_2_U.GPSPosition.Longitude,
    &EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEarth);

  /* Trigonometry: '<S128>/Trigonometric Function4' */
  rtb_f_AILx_est_kuk = cos(rtb_u_k1[2]);

  /* Trigonometry: '<S128>/Trigonometric Function5' */
  rtb_f_RDRx_est_kuk = cos(rtb_u_k1[0]);

  /* Trigonometry: '<S128>/Trigonometric Function3' */
  rtb_Add1_bmn = sin(rtb_u_k1[2]);

  /* Trigonometry: '<S128>/Trigonometric Function2' */
  rtb_Divide_bd = sin(rtb_u_k1[1]);

  /* Trigonometry: '<S128>/Trigonometric Function' */
  rtb_Add1_ma = sin(rtb_u_k1[0]);

  /* Sum: '<S128>/Add2' incorporates:
   *  Product: '<S128>/Divide1'
   *  Product: '<S128>/Divide2'
   *  Product: '<S128>/Divide3'
   *  Product: '<S128>/Divide4'
   *  Product: '<S128>/Divide5'
   *  Product: '<S128>/Divide6'
   *  Product: '<S128>/Divide7'
   *  Sum: '<S128>/Add1'
   *  Sum: '<S128>/Add3'
   *  Trigonometry: '<S128>/Trigonometric Function1'
   */
  rtb_f_AILx_est_kuk = ((rtb_Divide_bd * rtb_Add1_ma * rtb_f_AILx_est_kuk -
    rtb_f_RDRx_est_kuk * rtb_Add1_bmn) * rtb_u_k1[4] + rtb_u_k1[3] * cos
                        (rtb_u_k1[1]) * rtb_f_AILx_est_kuk) + (rtb_Divide_bd *
    rtb_f_RDRx_est_kuk * rtb_f_AILx_est_kuk + rtb_Add1_ma * rtb_Add1_bmn) *
    rtb_u_k1[5];

  /* Trigonometry: '<S126>/Trigonometric Function3' */
  rtb_f_RDRx_est_kuk = sin(rtb_u_k1[2]);

  /* Trigonometry: '<S126>/Trigonometric Function5' */
  rtb_Add1_bmn = cos(rtb_u_k1[0]);

  /* Trigonometry: '<S126>/Trigonometric Function4' */
  rtb_Divide_bd = cos(rtb_u_k1[2]);

  /* Trigonometry: '<S126>/Trigonometric Function2' */
  rtb_Add1_ma = sin(rtb_u_k1[1]);

  /* Trigonometry: '<S126>/Trigonometric Function' */
  rtb_Add_ey = sin(rtb_u_k1[0]);

  /* Sum: '<S126>/Add2' incorporates:
   *  Product: '<S126>/Divide1'
   *  Product: '<S126>/Divide2'
   *  Product: '<S126>/Divide3'
   *  Product: '<S126>/Divide4'
   *  Product: '<S126>/Divide5'
   *  Product: '<S126>/Divide6'
   *  Product: '<S126>/Divide7'
   *  Sum: '<S126>/Add1'
   *  Sum: '<S126>/Add3'
   *  Trigonometry: '<S126>/Trigonometric Function1'
   */
  rtb_f_RDRx_est_kuk = ((rtb_Add1_ma * rtb_Add_ey * rtb_f_RDRx_est_kuk +
    rtb_Add1_bmn * rtb_Divide_bd) * rtb_u_k1[4] + rtb_u_k1[3] * cos(rtb_u_k1[1])
                        * rtb_f_RDRx_est_kuk) + (rtb_Add1_ma * rtb_Add1_bmn *
    rtb_f_RDRx_est_kuk - rtb_Add_ey * rtb_Divide_bd) * rtb_u_k1[5];

  /* Gain: '<S53>/Gain4' incorporates:
   *  Constant: '<S127>/gravity'
   *  Gain: '<S129>/Gain'
   *  Gain: '<S130>/Gain'
   *  Gain: '<S131>/Gain'
   *  Product: '<S127>/Divide1'
   *  Product: '<S127>/Divide2'
   *  Product: '<S127>/Divide3'
   *  Sum: '<S127>/Add1'
   *  Sum: '<S127>/Sum'
   *  Trigonometry: '<S127>/Trigonometric Function'
   *  Trigonometry: '<S127>/Trigonometric Function1'
   *  Trigonometry: '<S127>/Trigonometric Function2'
   *  Trigonometry: '<S127>/Trigonometric Function4'
   *  Trigonometry: '<S127>/Trigonometric Function5'
   */
  tmp_0[0] = EKF_IFS_2_P.Gain_Gain_c3 * rtb_Subtract1[3];
  tmp_0[1] = EKF_IFS_2_P.Gain_Gain_lq * rtb_Subtract1[4];
  tmp_0[2] = EKF_IFS_2_P.Gain_Gain_kw * rtb_Subtract1[5];
  tmp_0[3] = rtb_f_AILx_est_kuk;
  tmp_0[4] = rtb_f_RDRx_est_kuk;
  tmp_0[5] = ((rtb_u_k1[3] * sin(rtb_u_k1[1]) - cos(rtb_u_k1[1]) * sin(rtb_u_k1
    [0]) * rtb_u_k1[4]) - cos(rtb_u_k1[0]) * cos(rtb_u_k1[1]) * rtb_u_k1[5]) -
    EKF_IFS_2_P.g;

  /* Sum: '<S53>/Subtract1' incorporates:
   *  Gain: '<S53>/Gain4'
   */
  for (i = 0; i < 6; i++) {
    rtb_Subtract1[i] += EKF_IFS_2_P.dt * tmp_0[i];
  }

  /* End of Sum: '<S53>/Subtract1' */

  /* RelationalOperator: '<S56>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S56>/Delay Input1'
   */
  rtb_FixPtRelationalOperator = (uint8_T)
    (EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEarth.North !=
     EKF_IFS_2_DW.DelayInput1_DSTATE);

  /* Switch: '<S51>/Switch' */
  if (rtb_FixPtRelationalOperator > EKF_IFS_2_P.Switch_Threshold_m) {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Sum: '<S46>/Subtract'
     */
    rtb_FixPtRelationalOperator_0[0] =
      EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEarth.North - rtb_Subtract1[0];
  } else {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S51>/Constant'
     */
    rtb_FixPtRelationalOperator_0[0] = EKF_IFS_2_P.Constant_Value_f;
  }

  /* End of Switch: '<S51>/Switch' */

  /* Switch: '<S51>/Switch1' */
  if (rtb_FixPtRelationalOperator > EKF_IFS_2_P.Switch1_Threshold) {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Sum: '<S46>/Subtract'
     */
    rtb_FixPtRelationalOperator_0[1] =
      EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEarth.East - rtb_Subtract1[1];
  } else {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S51>/Constant'
     */
    rtb_FixPtRelationalOperator_0[1] = EKF_IFS_2_P.Constant_Value_f;
  }

  /* End of Switch: '<S51>/Switch1' */

  /* Switch: '<S51>/Switch2' */
  if (rtb_FixPtRelationalOperator > EKF_IFS_2_P.Switch2_Threshold) {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Sum: '<S46>/Subtract'
     */
    rtb_FixPtRelationalOperator_0[2] =
      EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEarth.Height - rtb_Subtract1[2];
  } else {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S51>/Constant'
     */
    rtb_FixPtRelationalOperator_0[2] = EKF_IFS_2_P.Constant_Value_f;
  }

  /* End of Switch: '<S51>/Switch2' */

  /* Switch: '<S51>/Switch3' */
  if (rtb_FixPtRelationalOperator > EKF_IFS_2_P.Switch3_Threshold) {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Gain: '<S47>/Gain3'
     *  Inport: '<Root>/GPS Velocity'
     *  Sum: '<S46>/Subtract'
     */
    rtb_FixPtRelationalOperator_0[3] = EKF_IFS_2_P.Gain3_Gain *
      EKF_IFS_2_U.GPSVelocity.V_north - rtb_Subtract1[3];
  } else {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S51>/Constant'
     */
    rtb_FixPtRelationalOperator_0[3] = EKF_IFS_2_P.Constant_Value_f;
  }

  /* End of Switch: '<S51>/Switch3' */

  /* Switch: '<S51>/Switch4' */
  if (rtb_FixPtRelationalOperator > EKF_IFS_2_P.Switch4_Threshold) {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Gain: '<S47>/Gain4'
     *  Inport: '<Root>/GPS Velocity'
     *  Sum: '<S46>/Subtract'
     */
    rtb_FixPtRelationalOperator_0[4] = EKF_IFS_2_P.Gain4_Gain *
      EKF_IFS_2_U.GPSVelocity.V_east - rtb_Subtract1[4];
  } else {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S51>/Constant'
     */
    rtb_FixPtRelationalOperator_0[4] = EKF_IFS_2_P.Constant_Value_f;
  }

  /* End of Switch: '<S51>/Switch4' */

  /* Switch: '<S51>/Switch5' */
  if (rtb_FixPtRelationalOperator > EKF_IFS_2_P.Switch5_Threshold) {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Gain: '<S47>/Gain1'
     *  Gain: '<S47>/Gain2'
     *  Inport: '<Root>/GPS Velocity'
     *  Sum: '<S46>/Subtract'
     */
    rtb_FixPtRelationalOperator_0[5] = EKF_IFS_2_P.Gain1_Gain_l *
      EKF_IFS_2_U.GPSVelocity.V_down * EKF_IFS_2_P.Gain2_Gain_a - rtb_Subtract1
      [5];
  } else {
    /* SignalConversion: '<S46>/TmpSignal ConversionAtProduct1Inport2' incorporates:
     *  Constant: '<S51>/Constant'
     */
    rtb_FixPtRelationalOperator_0[5] = EKF_IFS_2_P.Constant_Value_f;
  }

  for (i = 0; i < 6; i++) {
    /* Product: '<S46>/Product1' incorporates:
     *  Gain: '<S46>/Gain'
     */
    rtb_Divide2_fm[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Divide2_fm[i] += rtb_Product3_g[6 * i_0 + i] *
        rtb_FixPtRelationalOperator_0[i_0];
    }

    /* End of Product: '<S46>/Product1' */

    /* Sum: '<S46>/Subtract1' incorporates:
     *  Gain: '<S46>/Gain'
     */
    rtb_Divide1_mwl[i] = EKF_IFS_2_P.Gain_Gain_ab * rtb_Divide2_fm[i] +
      rtb_Subtract1[i];
  }

  /* End of Switch: '<S51>/Switch5' */

  /* MATLAB Function: '<S5>/Convert Lat//Lon//Alt to Flat Earth' incorporates:
   *  Inport: '<Root>/Waypoints IN'
   *  MATLAB Function: '<S48>/Convert Local Coordinates to LLA'
   */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/Local Position to GPS Position/Convert Local Coordinates to LLA': '<S134>:1' */
  /* '<S134>:1:4' */
  /* '<S134>:1:5' */
  /* '<S134>:1:6' */
  EKF_ConvertLatLonAlttoFlatEarth(&EKF_IFS_2_U.WaypointsIN, rtb_Divide1_mwl[2] *
    0.3048 + EKF_IFS_2_U.WaypointsIN.ref_alt, rtb_Divide1_mwl[0] /
    EKF_IFS_2_U.WaypointsIN.fact_lat + EKF_IFS_2_U.WaypointsIN.ref_lat,
    rtb_Divide1_mwl[1] / EKF_IFS_2_U.WaypointsIN.fact_lon +
    EKF_IFS_2_U.WaypointsIN.ref_lon,
    &EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o);

  /* MATLAB Function: '<S8>/Trajectory Generation' incorporates:
   *  BusCreator: '<S8>/BusConversion_InsertedFor_Trajectory Generation_at_inport_7'
   *  Inport: '<Root>/Home Cmd'
   *  Inport: '<Root>/PIC//CIC'
   *  Inport: '<Root>/Waypoints IN'
   *  Inport: '<Root>/e_op'
   *  Inport: '<Root>/h_op'
   *  Inport: '<Root>/n_op'
   *  Inport: '<Root>/ve_op'
   *  Inport: '<Root>/vh_op'
   *  Inport: '<Root>/vn_op'
   */
  for (i = 0; i < 32; i++) {
    wpts_h[i] = EKF_IFS_2_U.WaypointsIN.h[i];
    wpts_n[i] = EKF_IFS_2_U.WaypointsIN.n[i];
    wpts_e[i] = EKF_IFS_2_U.WaypointsIN.e[i];
  }

  /* MATLAB Function 'Intelligent Flight System (subsystem)/Trajectory/Trajectory Generation': '<S44>:1' */
  /*  Local Variable Assignment: */
  /*  -------------------------- */
  /* '<S44>:1:8' */
  /* '<S44>:1:9' */
  /* '<S44>:1:10' */
  /*  PIC/CIC Transition Logic: */
  /*  ------------------------- */
  /*  On transition to CIC or PIC, set index = 0 and current position to  */
  /*  current waypoint; hold current waypoint. */
  if (((int32_T)EKF_IFS_2_U.PICCIC > (int32_T)rtb_DataStoreRead1_b) ||
      (EKF_IFS_2_U.PICCIC == 0)) {
    /* '<S44>:1:17' */
    /* '<S44>:1:19' */
    rtb_DataStoreRead3_b_idx_0 =
      EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height;

    /* '<S44>:1:20' */
    rtb_DataStoreRead3_b_idx_1 =
      EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North;

    /* '<S44>:1:21' */
    rtb_DataStoreRead3_b_idx_2 =
      EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East;

    /* '<S44>:1:23' */
    rtb_DataStoreRead2_h = 0U;

    /* '<S44>:1:24' */
    rtb_DataStoreRead4_n = 0U;
  }

  /*  Change the waypoint index when home command */
  if ((EKF_IFS_2_U.HomeCmd == 1) && (EKF_IFS_2_U.PICCIC == 1) &&
      (rtb_DataStoreRead4_n == 0)) {
    /* '<S44>:1:29' */
    /* '<S44>:1:31' */
    rtb_DataStoreRead2_h = 23U;

    /* '<S44>:1:32' */
    rtb_DataStoreRead4_n = 1U;
  }

  /* OP trajectory generation */
  /* %reassigning the a and b waypoints */
  if ((EKF_IFS_2_P.TR == 1.0) && (rtb_DataStoreRead4_n == 0)) {
    /* '<S44>:1:38' */
    /* '<S44>:1:39' */
    rtb_DataStoreRead2_h = 1U;

    /* '<S44>:1:40' */
    wpts_n[0] = EKF_IFS_2_U.n_op[0] - 100.0 * EKF_IFS_2_U.vn_op[0];
    wpts_n[1] = 100.0 * EKF_IFS_2_U.vn_op[0] + EKF_IFS_2_U.n_op[0];

    /* '<S44>:1:41' */
    wpts_e[0] = EKF_IFS_2_U.e_op[0] - 100.0 * EKF_IFS_2_U.ve_op[0];
    wpts_e[1] = 100.0 * EKF_IFS_2_U.ve_op[0] + EKF_IFS_2_U.e_op[0];

    /* '<S44>:1:42' */
    wpts_h[0] = EKF_IFS_2_U.h_op[0] - 100.0 * EKF_IFS_2_U.vh_op[0];
    wpts_h[1] = 100.0 * EKF_IFS_2_U.vh_op[0] + EKF_IFS_2_U.h_op[0];
  }

  /*  Calculate the Next Waypoint Index: */
  /*  ---------------------------------- */
  /* '<S44>:1:47' */
  i = (int32_T)(rtb_DataStoreRead2_h + 1U);
  if ((uint32_T)i > 255U) {
    i = 255;
  }

  rtb_FixPtRelationalOperator = (uint8_T)i;

  /*  If beyond the final point, go to the return point */
  if ((uint8_T)i > EKF_IFS_2_U.WaypointsIN.fp) {
    /* '<S44>:1:50' */
    /* '<S44>:1:51' */
    rtb_FixPtRelationalOperator = EKF_IFS_2_U.WaypointsIN.rp;
  }

  /*  Calculate Distance to Next Waypoint: */
  /*  ------------------------------------ */
  /* '<S44>:1:57' */
  rtb_Gain_cl = EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North -
    wpts_n[rtb_FixPtRelationalOperator - 1];
  rtb_Add_lzz = EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East -
    wpts_e[rtb_FixPtRelationalOperator - 1];
  distance = sqrt(rtb_Gain_cl * rtb_Gain_cl + rtb_Add_lzz * rtb_Add_lzz);

  /*  Change to Next Waypoint if in Range: */
  /*  ------------------------------------ */
  if ((distance < EKF_IFS_2_P.dist2b) && (EKF_IFS_2_U.PICCIC == 1)) {
    /* '<S44>:1:61' */
    /*  Do not change index if sw=0 */
    /* '<S44>:1:63' */
    /* '<S44>:1:64' */
    rtb_DataStoreRead2_h = rtb_FixPtRelationalOperator;
    if (rtb_FixPtRelationalOperator == EKF_IFS_2_U.WaypointsIN.fp) {
      /* '<S44>:1:66' */
      /* '<S44>:1:67' */
      rtb_FixPtRelationalOperator = EKF_IFS_2_U.WaypointsIN.rp;
    } else {
      /* '<S44>:1:69' */
      i = (int32_T)(rtb_FixPtRelationalOperator + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      rtb_FixPtRelationalOperator = (uint8_T)i;
    }
  }

  /*  Function Outputs: */
  /*  ----------------- */
  if ((rtb_DataStoreRead2_h == 0) || (rtb_DataStoreRead2_h == 23)) {
    /* '<S44>:1:77' */
    /*  Assign the speed of the starting segment to the speed of the first */
    /*  waypoint */
    /* '<S44>:1:80' */
    rtb_Vab_mod = EKF_IFS_2_U.WaypointsIN.v[0];

    /* '<S44>:1:81' */
    rtb_Divide4_kov = rtb_DataStoreRead3_b_idx_0;

    /* '<S44>:1:82' */
    rtb_Divide4_dh = rtb_DataStoreRead3_b_idx_1;

    /* '<S44>:1:83' */
    rtb_Add_lzz = rtb_DataStoreRead3_b_idx_2;
  } else {
    /* '<S44>:1:85' */
    rtb_Vab_mod = EKF_IFS_2_U.WaypointsIN.v[rtb_DataStoreRead2_h - 1];

    /* '<S44>:1:86' */
    rtb_Divide4_kov = wpts_h[rtb_DataStoreRead2_h - 1];

    /* '<S44>:1:87' */
    rtb_Divide4_dh = wpts_n[rtb_DataStoreRead2_h - 1];

    /* '<S44>:1:88' */
    rtb_Add_lzz = wpts_e[rtb_DataStoreRead2_h - 1];
  }

  /* '<S44>:1:90' */
  /* '<S44>:1:91' */
  /* '<S44>:1:92' */
  /* '<S44>:1:94' */
  /* '<S44>:1:96' */
  /* '<S44>:1:98' */
  rtb_DataStoreRead1_b = EKF_IFS_2_U.PICCIC;

  /* Sum: '<S27>/Add4' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_cos_atrack = wpts_h[rtb_FixPtRelationalOperator - 1] - rtb_Divide4_kov;

  /* Sum: '<S27>/Add9' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Add9 = wpts_n[rtb_FixPtRelationalOperator - 1] - rtb_Divide4_dh;

  /* Math: '<S27>/Math Function4' */
  rtb_MathFunction6 = rtb_Add9 * rtb_Add9;

  /* Sum: '<S27>/Add5' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Add5 = wpts_e[rtb_FixPtRelationalOperator - 1] - rtb_Add_lzz;

  /* Math: '<S27>/Math Function5' */
  rtb_MathFunction5 = rtb_Add5 * rtb_Add5;

  /* Sum: '<S27>/Add6' incorporates:
   *  Math: '<S27>/Math Function7'
   */
  rtb_sin_atrack = (rtb_cos_atrack * rtb_cos_atrack + rtb_MathFunction6) +
    rtb_MathFunction5;

  /* Sqrt: '<S27>/Math Function9'
   *
   * About '<S27>/Math Function9':
   *  Operator: signedSqrt
   */
  if (rtb_sin_atrack < 0.0) {
    rtb_sin_atrack = -sqrt(fabs(rtb_sin_atrack));
  } else {
    rtb_sin_atrack = sqrt(rtb_sin_atrack);
  }

  /* End of Sqrt: '<S27>/Math Function9' */

  /* Product: '<S27>/Product6' */
  rtb_x_W1_dot_idx_0 = rtb_cos_atrack / rtb_sin_atrack;

  /* Trigonometry: '<S27>/Trigonometric Function5' */
  if (rtb_x_W1_dot_idx_0 > 1.0) {
    rtb_x_W1_dot_idx_0 = 1.0;
  } else {
    if (rtb_x_W1_dot_idx_0 < -1.0) {
      rtb_x_W1_dot_idx_0 = -1.0;
    }
  }

  rtb_cos_atrack = asin(rtb_x_W1_dot_idx_0);

  /* End of Trigonometry: '<S27>/Trigonometric Function5' */

  /* Trigonometry: '<S27>/Trigonometric Function' */
  rtb_sin_atrack = sin(rtb_cos_atrack);

  /* Fcn: '<S39>/hd' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_hd = ((((((((((((((((((wpts_e[rtb_FixPtRelationalOperator - 1] *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East *
    wpts_h[rtb_FixPtRelationalOperator - 1] - wpts_e[rtb_FixPtRelationalOperator
    - 1] * EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East * rtb_Divide4_kov) +
    rt_powd_snf(wpts_e[rtb_FixPtRelationalOperator - 1], 2.0) * rtb_Divide4_kov)
    - wpts_e[rtb_FixPtRelationalOperator - 1] * rtb_Add_lzz *
    wpts_h[rtb_FixPtRelationalOperator - 1]) - rtb_Add_lzz *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East *
    wpts_h[rtb_FixPtRelationalOperator - 1]) + rtb_Add_lzz *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East * rtb_Divide4_kov) -
                        rtb_Add_lzz * rtb_Divide4_kov *
                        wpts_e[rtb_FixPtRelationalOperator - 1]) +
                       wpts_h[rtb_FixPtRelationalOperator - 1] * rt_powd_snf
                       (rtb_Add_lzz, 2.0)) + wpts_n[rtb_FixPtRelationalOperator
                      - 1] * EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
                      wpts_h[rtb_FixPtRelationalOperator - 1]) -
                     wpts_n[rtb_FixPtRelationalOperator - 1] *
                     EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
                     rtb_Divide4_kov) + rt_powd_snf
                    (wpts_n[rtb_FixPtRelationalOperator - 1], 2.0) *
                    rtb_Divide4_kov) - wpts_n[rtb_FixPtRelationalOperator - 1] *
                   rtb_Divide4_dh * wpts_h[rtb_FixPtRelationalOperator - 1]) -
                  rtb_Divide4_dh *
                  EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
                  wpts_h[rtb_FixPtRelationalOperator - 1]) + rtb_Divide4_dh *
                 EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
                 rtb_Divide4_kov) - rtb_Divide4_dh * rtb_Divide4_kov *
                wpts_n[rtb_FixPtRelationalOperator - 1]) +
               wpts_h[rtb_FixPtRelationalOperator - 1] * rt_powd_snf
               (rtb_Divide4_dh, 2.0)) + rt_powd_snf
              (wpts_h[rtb_FixPtRelationalOperator - 1], 2.0) *
              EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height) - 2.0 *
             EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height *
             wpts_h[rtb_FixPtRelationalOperator - 1] * rtb_Divide4_kov) +
            EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height * rt_powd_snf
            (rtb_Divide4_kov, 2.0)) / ((((((((rt_powd_snf
    (wpts_e[rtb_FixPtRelationalOperator - 1], 2.0) -
    wpts_e[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Add_lzz) + rt_powd_snf
    (rtb_Add_lzz, 2.0)) + rt_powd_snf(wpts_n[rtb_FixPtRelationalOperator - 1],
    2.0)) - wpts_n[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Divide4_dh) +
    rt_powd_snf(rtb_Divide4_dh, 2.0)) + rt_powd_snf
    (wpts_h[rtb_FixPtRelationalOperator - 1], 2.0)) -
    wpts_h[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Divide4_kov) +
    rt_powd_snf(rtb_Divide4_kov, 2.0));

  /* Fcn: '<S39>/nd' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_nd = ((((((((((((((((((wpts_e[rtb_FixPtRelationalOperator - 1] *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East *
    wpts_n[rtb_FixPtRelationalOperator - 1] - wpts_e[rtb_FixPtRelationalOperator
    - 1] * EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East * rtb_Divide4_dh) +
    rt_powd_snf(wpts_e[rtb_FixPtRelationalOperator - 1], 2.0) * rtb_Divide4_dh)
    - wpts_e[rtb_FixPtRelationalOperator - 1] * rtb_Add_lzz *
    wpts_n[rtb_FixPtRelationalOperator - 1]) - rtb_Add_lzz *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East *
    wpts_n[rtb_FixPtRelationalOperator - 1]) + rtb_Add_lzz *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East * rtb_Divide4_dh) -
                        rtb_Add_lzz * rtb_Divide4_dh *
                        wpts_e[rtb_FixPtRelationalOperator - 1]) +
                       wpts_n[rtb_FixPtRelationalOperator - 1] * rt_powd_snf
                       (rtb_Add_lzz, 2.0)) + rt_powd_snf
                      (wpts_n[rtb_FixPtRelationalOperator - 1], 2.0) *
                      EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North) - 2.0 *
                     EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
                     wpts_n[rtb_FixPtRelationalOperator - 1] * rtb_Divide4_dh) +
                    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
                    rt_powd_snf(rtb_Divide4_dh, 2.0)) +
                   wpts_h[rtb_FixPtRelationalOperator - 1] *
                   EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height *
                   wpts_n[rtb_FixPtRelationalOperator - 1]) -
                  wpts_h[rtb_FixPtRelationalOperator - 1] *
                  EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height *
                  rtb_Divide4_dh) + rt_powd_snf
                 (wpts_h[rtb_FixPtRelationalOperator - 1], 2.0) * rtb_Divide4_dh)
                - wpts_h[rtb_FixPtRelationalOperator - 1] * rtb_Divide4_kov *
                wpts_n[rtb_FixPtRelationalOperator - 1]) - rtb_Divide4_kov *
               EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height *
               wpts_n[rtb_FixPtRelationalOperator - 1]) + rtb_Divide4_kov *
              EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height *
              rtb_Divide4_dh) - rtb_Divide4_kov * rtb_Divide4_dh *
             wpts_h[rtb_FixPtRelationalOperator - 1]) +
            wpts_n[rtb_FixPtRelationalOperator - 1] * rt_powd_snf
            (rtb_Divide4_kov, 2.0)) / ((((((((rt_powd_snf
    (wpts_e[rtb_FixPtRelationalOperator - 1], 2.0) -
    wpts_e[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Add_lzz) + rt_powd_snf
    (rtb_Add_lzz, 2.0)) + rt_powd_snf(wpts_n[rtb_FixPtRelationalOperator - 1],
    2.0)) - wpts_n[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Divide4_dh) +
    rt_powd_snf(rtb_Divide4_dh, 2.0)) + rt_powd_snf
    (wpts_h[rtb_FixPtRelationalOperator - 1], 2.0)) -
    wpts_h[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Divide4_kov) +
    rt_powd_snf(rtb_Divide4_kov, 2.0));

  /* Fcn: '<S39>/ed' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_ed = ((((((((((((((((((rt_powd_snf(wpts_e[rtb_FixPtRelationalOperator - 1],
    2.0) * EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East - 2.0 *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East *
    wpts_e[rtb_FixPtRelationalOperator - 1] * rtb_Add_lzz) +
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East * rt_powd_snf(rtb_Add_lzz,
    2.0)) + wpts_n[rtb_FixPtRelationalOperator - 1] *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
    wpts_e[rtb_FixPtRelationalOperator - 1]) -
    wpts_n[rtb_FixPtRelationalOperator - 1] *
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North * rtb_Add_lzz) +
    rt_powd_snf(wpts_n[rtb_FixPtRelationalOperator - 1], 2.0) * rtb_Add_lzz) -
                        wpts_n[rtb_FixPtRelationalOperator - 1] * rtb_Divide4_dh
                        * wpts_e[rtb_FixPtRelationalOperator - 1]) -
                       rtb_Divide4_dh *
                       EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
                       wpts_e[rtb_FixPtRelationalOperator - 1]) + rtb_Divide4_dh
                      * EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North *
                      rtb_Add_lzz) - rtb_Divide4_dh * rtb_Add_lzz *
                     wpts_n[rtb_FixPtRelationalOperator - 1]) +
                    wpts_e[rtb_FixPtRelationalOperator - 1] * rt_powd_snf
                    (rtb_Divide4_dh, 2.0)) + wpts_h[rtb_FixPtRelationalOperator
                   - 1] * EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height *
                   wpts_e[rtb_FixPtRelationalOperator - 1]) -
                  wpts_h[rtb_FixPtRelationalOperator - 1] *
                  EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height *
                  rtb_Add_lzz) + rt_powd_snf(wpts_h[rtb_FixPtRelationalOperator
    - 1], 2.0) * rtb_Add_lzz) - wpts_h[rtb_FixPtRelationalOperator - 1] *
                rtb_Divide4_kov * wpts_e[rtb_FixPtRelationalOperator - 1]) -
               rtb_Divide4_kov *
               EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height *
               wpts_e[rtb_FixPtRelationalOperator - 1]) + rtb_Divide4_kov *
              EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height * rtb_Add_lzz)
             - rtb_Divide4_kov * rtb_Add_lzz *
             wpts_h[rtb_FixPtRelationalOperator - 1]) +
            wpts_e[rtb_FixPtRelationalOperator - 1] * rt_powd_snf
            (rtb_Divide4_kov, 2.0)) / ((((((((rt_powd_snf
    (wpts_e[rtb_FixPtRelationalOperator - 1], 2.0) -
    wpts_e[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Add_lzz) + rt_powd_snf
    (rtb_Add_lzz, 2.0)) + rt_powd_snf(wpts_n[rtb_FixPtRelationalOperator - 1],
    2.0)) - wpts_n[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Divide4_dh) +
    rt_powd_snf(rtb_Divide4_dh, 2.0)) + rt_powd_snf
    (wpts_h[rtb_FixPtRelationalOperator - 1], 2.0)) -
    wpts_h[rtb_FixPtRelationalOperator - 1] * 2.0 * rtb_Divide4_kov) +
    rt_powd_snf(rtb_Divide4_kov, 2.0));

  /* MATLAB Function: '<S25>/Modification of VT' incorporates:
   *  Inport: '<Root>/e_op'
   *  Inport: '<Root>/h_op'
   *  Inport: '<Root>/n_op'
   *  Inport: '<Root>/ve_op'
   *  Inport: '<Root>/vh_op'
   *  Inport: '<Root>/vn_op'
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  /* MATLAB Function 'Intelligent Flight System (subsystem)/Guidance System/VT modification_moving points/Modification of VT': '<S38>:1' */
  /* OP trajectory generation (copied from uas_augm)model.m) */
  /* reassigning Vab (based on the new d point) */
  /* '<S38>:1:11' */
  if (EKF_IFS_2_P.TR == 1.0) {
    /* '<S38>:1:12' */
    /* '<S38>:1:13' */
    /* '<S38>:1:14' */
    rtb_Gain_cl = wpts_n[rtb_FixPtRelationalOperator - 1] - EKF_IFS_2_U.n_op[0];
    rtb_Add_lzz = wpts_e[rtb_FixPtRelationalOperator - 1] - EKF_IFS_2_U.e_op[0];
    rtb_Add_iq = wpts_h[rtb_FixPtRelationalOperator - 1] - EKF_IFS_2_U.h_op[0];

    /* '<S38>:1:15' */
    rtb_Divide4_dh = wpts_n[rtb_FixPtRelationalOperator - 1] - rtb_nd;
    rtb_Divide3_bk = wpts_e[rtb_FixPtRelationalOperator - 1] - rtb_ed;
    rtb_Divide4_kov = wpts_h[rtb_FixPtRelationalOperator - 1] - rtb_hd;

    /* '<S38>:1:16' */
    rtb_Divide3_mja = rtb_nd - EKF_IFS_2_U.n_op[0];
    rtb_Divide4_ea = rtb_ed - EKF_IFS_2_U.e_op[0];
    rtb_Divide4_ot = rtb_hd - EKF_IFS_2_U.h_op[0];

    /* '<S38>:1:17' */
    rtb_x_W1_dot_idx_0 = sqrt((rtb_Gain_cl * rtb_Gain_cl + rtb_Add_lzz *
      rtb_Add_lzz) + rtb_Add_iq * rtb_Add_iq) - sqrt((rtb_Divide4_dh *
      rtb_Divide4_dh + rtb_Divide3_bk * rtb_Divide3_bk) + rtb_Divide4_kov *
      rtb_Divide4_kov);
    if (rtb_x_W1_dot_idx_0 < 0.0) {
      rtb_x_W1_dot_idx_0 = -1.0;
    } else if (rtb_x_W1_dot_idx_0 > 0.0) {
      rtb_x_W1_dot_idx_0 = 1.0;
    } else {
      if (rtb_x_W1_dot_idx_0 == 0.0) {
        rtb_x_W1_dot_idx_0 = 0.0;
      }
    }

    rtb_Vab_mod = sqrt((EKF_IFS_2_U.vn_op[0] * EKF_IFS_2_U.vn_op[0] +
                        EKF_IFS_2_U.ve_op[0] * EKF_IFS_2_U.ve_op[0]) +
                       EKF_IFS_2_U.vh_op[0] * EKF_IFS_2_U.vh_op[0]) - atan(sqrt
      ((rtb_Divide3_mja * rtb_Divide3_mja + rtb_Divide4_ea * rtb_Divide4_ea) +
       rtb_Divide4_ot * rtb_Divide4_ot) * rtb_x_W1_dot_idx_0 / 100.0) *
      0.063661977236758135;

    /* (168.78) (5) (/100) */
  }

  /* End of MATLAB Function: '<S25>/Modification of VT' */

  /* Saturate: '<S177>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Sum: '<S177>/Add' incorporates:
   *  Gain: '<S177>/Gain'
   *  Gain: '<S177>/Gain1'
   *  Saturate: '<S177>/Throttle Limiter'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_nv = EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[0];

  /* Saturate: '<S177>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Sum: '<S177>/Add1' incorporates:
   *  Gain: '<S177>/Gain2'
   *  Gain: '<S177>/Gain3'
   *  Saturate: '<S177>/Elevator Limiter'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_d0r = EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[1];

  /* Saturate: '<S177>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Sum: '<S177>/Add2' incorporates:
   *  Gain: '<S177>/Gain4'
   *  Gain: '<S177>/Gain5'
   *  Saturate: '<S177>/Aileron Limiter'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_f_AILx_est_kuk = EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[2];

  /* Saturate: '<S177>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Sum: '<S177>/Add3' incorporates:
   *  Gain: '<S177>/Gain6'
   *  Gain: '<S177>/Gain7'
   *  Saturate: '<S177>/Rudder Limiter'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_f_RDRx_est_kuk = EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Product: '<S184>/Divide2' incorporates:
   *  Trigonometry: '<S184>/Trigonometric Function'
   *  Trigonometry: '<S184>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_bmn = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S186>/Divide2' incorporates:
   *  Trigonometry: '<S186>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_bd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S189>/Divide2' incorporates:
   *  Trigonometry: '<S189>/Trigonometric Function'
   *  Trigonometry: '<S189>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_ma = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S181>/Divide4' incorporates:
   *  Constant: '<S181>/Constant'
   *  Constant: '<S181>/Constant1'
   *  Math: '<S181>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_dh = EKF_IFS_2_P.Constant_Value_g * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S200>/Add' incorporates:
   *  Constant: '<S200>/Constant'
   *  Constant: '<S200>/Constant1'
   *  Constant: '<S200>/Constant10'
   *  Constant: '<S200>/Constant11'
   *  Constant: '<S200>/Constant12'
   *  Constant: '<S200>/Constant13'
   *  Constant: '<S200>/Constant14'
   *  Constant: '<S200>/Constant15'
   *  Constant: '<S200>/Constant2'
   *  Constant: '<S200>/Constant3'
   *  Constant: '<S200>/Constant4'
   *  Constant: '<S200>/Constant5'
   *  Constant: '<S200>/Constant6'
   *  Constant: '<S200>/Constant7'
   *  Constant: '<S200>/Constant8'
   *  Constant: '<S200>/Constant9'
   *  Gain: '<S200>/Gain1'
   *  Gain: '<S200>/Gain2'
   *  Gain: '<S200>/Gain3'
   *  Product: '<S200>/Divide1'
   *  Product: '<S200>/Divide2'
   *  Product: '<S200>/Divide3'
   *  Product: '<S200>/Divide4'
   *  Product: '<S200>/Divide5'
   *  Product: '<S200>/Divide6'
   *  Product: '<S200>/Divide7'
   *  Sum: '<S200>/Add1'
   *  Sum: '<S200>/Add2'
   *  Sum: '<S200>/Add3'
   *  Sum: '<S200>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S191>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_Add1_bmn - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_Add1_bmn - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_l * EKF_IFS_2_P.Gain1_Gain_o) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_b;

  /* ManualSwitch: '<S199>/Manual Switch' incorporates:
   *  Constant: '<S199>/AR'
   *  Constant: '<S199>/Constant15'
   *  Constant: '<S199>/Constant16'
   *  Constant: '<S199>/Constant17'
   *  Constant: '<S199>/Constant18'
   *  Constant: '<S199>/e'
   *  Math: '<S199>/Math Function'
   *  Product: '<S199>/Divide8'
   *  Product: '<S199>/Divide9'
   *  Sum: '<S199>/Add5'
   *  Sum: '<S199>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting == 1) {
    rtb_Add_ey = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Add_ey = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S199>/Manual Switch' */

  /* Sum: '<S199>/Add' incorporates:
   *  Constant: '<S199>/Constant1'
   *  Constant: '<S199>/Constant10'
   *  Constant: '<S199>/Constant11'
   *  Constant: '<S199>/Constant12'
   *  Constant: '<S199>/Constant13'
   *  Constant: '<S199>/Constant14'
   *  Constant: '<S199>/Constant2'
   *  Constant: '<S199>/Constant3'
   *  Constant: '<S199>/Constant4'
   *  Constant: '<S199>/Constant6'
   *  Constant: '<S199>/Constant7'
   *  Constant: '<S199>/Constant8'
   *  Constant: '<S199>/Constant9'
   *  Gain: '<S199>/Gain1'
   *  Gain: '<S199>/Gain2'
   *  Gain: '<S199>/Gain3'
   *  Product: '<S199>/Divide1'
   *  Product: '<S199>/Divide2'
   *  Product: '<S199>/Divide3'
   *  Product: '<S199>/Divide5'
   *  Product: '<S199>/Divide6'
   *  Product: '<S199>/Divide7'
   *  Sum: '<S199>/Add1'
   *  Sum: '<S199>/Add2'
   *  Sum: '<S199>/Add3'
   *  Sum: '<S199>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S191>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Add_ey) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_Add1_bmn - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_Add1_bmn - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_i * EKF_IFS_2_P.Gain1_Gain_lk) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_e;

  /* ManualSwitch: '<S185>/Manual Switch' incorporates:
   *  Constant: '<S185>/Constant1'
   *  Constant: '<S193>/Constant'
   *  Constant: '<S211>/Constant'
   *  Constant: '<S211>/Constant1'
   *  Constant: '<S211>/Constant2'
   *  Math: '<S211>/Math Function'
   *  Product: '<S185>/Divide'
   *  Product: '<S185>/Divide5'
   *  Product: '<S208>/Divide3'
   *  Product: '<S208>/Divide5'
   *  Product: '<S211>/Divide1'
   *  Product: '<S211>/Divide2'
   *  Sum: '<S185>/Add'
   *  Sum: '<S208>/Add'
   *  Sum: '<S211>/Add'
   *  Trigonometry: '<S208>/Trigonometric Function'
   *  Trigonometry: '<S208>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_g == 1) {
    /* Gain: '<S211>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Add_ey = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 +
                    EKF_IFS_2_P.xT1 * rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
      (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq * cos
      (EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_dh * EKF_IFS_2_P.S)) /
      (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Add_ey = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S185>/Manual Switch' */

  /* Sum: '<S185>/Add1' incorporates:
   *  Constant: '<S185>/Constant'
   *  Product: '<S185>/Divide2'
   *  Product: '<S185>/Divide3'
   *  Product: '<S185>/Divide4'
   *  Trigonometry: '<S185>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_ey += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_Divide_bd -
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Add1_ma) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* ManualSwitch: '<S188>/Manual Switch' incorporates:
   *  Constant: '<S188>/Constant1'
   *  Constant: '<S193>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S201>/Constant1'
   *  Constant: '<S201>/Constant10'
   *  Constant: '<S201>/Constant11'
   *  Constant: '<S201>/Constant12'
   *  Constant: '<S201>/Constant2'
   *  Constant: '<S201>/Constant3'
   *  Constant: '<S201>/Constant4'
   *  Constant: '<S201>/Constant5'
   *  Constant: '<S201>/Constant6'
   *  Constant: '<S201>/Constant8'
   *  Product: '<S188>/Divide'
   *  Product: '<S188>/Divide5'
   *  Product: '<S201>/Divide1'
   *  Product: '<S201>/Divide3'
   *  Product: '<S201>/Divide4'
   *  Product: '<S201>/Divide5'
   *  Product: '<S201>/Divide6'
   *  Sum: '<S201>/Add'
   *  Sum: '<S201>/Add1'
   *  Sum: '<S201>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_d == 1) {
    rtb_Divide4_jaz = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim)
                          * EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) /
                          EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cyb *
                          EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                         (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim)
                         * EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) /
                         EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cyda *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cydr *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) * (rtb_Divide4_dh *
      EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Divide4_jaz = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S188>/Manual Switch' */

  /* Sum: '<S188>/Add1' incorporates:
   *  Constant: '<S188>/Constant'
   *  Product: '<S188>/Divide2'
   *  Product: '<S188>/Divide3'
   *  Product: '<S188>/Divide4'
   *  Trigonometry: '<S188>/Trigonometric Function'
   *  Trigonometry: '<S188>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_jaz += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Add1_ma -
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_Add1_bmn) + sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* ManualSwitch: '<S190>/Manual Switch' incorporates:
   *  Constant: '<S190>/Constant1'
   *  Constant: '<S193>/Constant'
   *  Product: '<S190>/Divide'
   *  Product: '<S190>/Divide5'
   *  Product: '<S210>/Divide1'
   *  Product: '<S210>/Divide6'
   *  Sum: '<S210>/Add2'
   *  Trigonometry: '<S210>/Trigonometric Function4'
   *  Trigonometry: '<S210>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_a == 1) {
    rtb_Divide4_ot = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]))
                      - cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_dh * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Divide4_ot = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S190>/Manual Switch' */

  /* Sum: '<S190>/Add1' incorporates:
   *  Constant: '<S190>/Constant'
   *  Product: '<S190>/Divide2'
   *  Product: '<S190>/Divide3'
   *  Product: '<S190>/Divide4'
   *  Trigonometry: '<S190>/Trigonometric Function'
   *  Trigonometry: '<S190>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_ot += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Add1_bmn -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Divide_bd) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S187>/Divide' incorporates:
   *  Product: '<S187>/Divide3'
   *  Product: '<S187>/Divide4'
   *  Product: '<S187>/Divide5'
   *  Sum: '<S187>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_bi = ((rtb_Add1_bmn * rtb_Add_ey + rtb_Divide_bd * rtb_Divide4_jaz)
                   + rtb_Add1_ma * rtb_Divide4_ot) /
    EKF_IFS_2_DW.x_est_00_DSTATE_f[4];

  /* Product: '<S191>/Divide' incorporates:
   *  Math: '<S191>/Math Function'
   *  Math: '<S191>/Math Function1'
   *  Product: '<S191>/Divide3'
   *  Product: '<S191>/Divide4'
   *  Sum: '<S191>/Add'
   *  Sum: '<S191>/Add1'
   */
  rtb_Divide = (rtb_Add1_bmn * rtb_Divide4_ot - rtb_Add1_ma * rtb_Add_ey) /
    (rtb_Add1_bmn * rtb_Add1_bmn + rtb_Add1_ma * rtb_Add1_ma);

  /* Product: '<S192>/Divide' incorporates:
   *  Math: '<S192>/Math Function'
   *  Math: '<S192>/Math Function1'
   *  Product: '<S192>/Divide1'
   *  Product: '<S192>/Divide2'
   *  Product: '<S192>/Divide3'
   *  Product: '<S192>/Divide4'
   *  Product: '<S192>/Divide5'
   *  Product: '<S192>/Divide6'
   *  Sum: '<S192>/Add'
   *  Sum: '<S192>/Add1'
   *  Sum: '<S192>/Add2'
   *  Trigonometry: '<S192>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_bd = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Divide4_jaz -
                   ((rtb_Add1_bmn * rtb_Add_ey + rtb_Divide_bd * rtb_Divide4_jaz)
                    + rtb_Add1_ma * rtb_Divide4_ot) /
                   EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Divide_bd) /
    (rtb_Add1_bmn * rtb_Add1_bmn + rtb_Add1_ma * rtb_Add1_ma) * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Trigonometry: '<S195>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S195>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat;
    }
  }

  /* Sum: '<S195>/Add1' incorporates:
   *  Product: '<S195>/Divide1'
   *  Product: '<S195>/Divide2'
   *  Product: '<S195>/Divide4'
   *  Saturate: '<S195>/Saturation'
   *  Sum: '<S195>/Add'
   *  Trigonometry: '<S195>/Trigonometric Function1'
   *  Trigonometry: '<S195>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_ma = (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0 +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* Sum: '<S198>/Add' incorporates:
   *  Product: '<S198>/Divide2'
   *  Product: '<S198>/Divide4'
   *  Trigonometry: '<S198>/Trigonometric Function1'
   *  Trigonometry: '<S198>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_ey = EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7])
    * EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S221>/Add' incorporates:
   *  Constant: '<S221>/Ixx1'
   *  Constant: '<S221>/Ixz1'
   *  Constant: '<S221>/Izz1'
   *  Math: '<S221>/Math Function'
   *  Product: '<S221>/Divide1'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S213>/Divide4' incorporates:
   *  Constant: '<S213>/Ixx'
   *  Constant: '<S213>/Ixz'
   *  Constant: '<S213>/Iyy'
   *  Constant: '<S213>/Izz'
   *  Product: '<S213>/Divide3'
   *  Sum: '<S213>/Add'
   */
  rtb_Divide4_ot = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_Divide4_jaz;

  /* Sum: '<S203>/Add' incorporates:
   *  Constant: '<S203>/Constant10'
   *  Constant: '<S203>/Constant11'
   *  Constant: '<S203>/Constant12'
   *  Constant: '<S203>/Constant13'
   *  Constant: '<S203>/Constant14'
   *  Constant: '<S203>/Constant15'
   *  Constant: '<S203>/Constant5'
   *  Constant: '<S203>/Constant6'
   *  Constant: '<S203>/Constant7'
   *  Constant: '<S203>/Constant8'
   *  Constant: '<S203>/Constant9'
   *  Product: '<S203>/Divide3'
   *  Product: '<S203>/Divide4'
   *  Product: '<S203>/Divide5'
   *  Product: '<S203>/Divide6'
   *  Product: '<S203>/Divide7'
   *  Sum: '<S203>/Add1'
   *  Sum: '<S203>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_lg4 = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                    EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim
                    + EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                   (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                   EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                  + EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S207>/Add' incorporates:
   *  Constant: '<S207>/Constant'
   *  Constant: '<S207>/Constant10'
   *  Constant: '<S207>/Constant11'
   *  Constant: '<S207>/Constant12'
   *  Constant: '<S207>/Constant13'
   *  Constant: '<S207>/Constant14'
   *  Constant: '<S207>/Constant15'
   *  Constant: '<S207>/Constant5'
   *  Constant: '<S207>/Constant6'
   *  Constant: '<S207>/Constant8'
   *  Constant: '<S207>/Constant9'
   *  Product: '<S207>/Divide3'
   *  Product: '<S207>/Divide4'
   *  Product: '<S207>/Divide5'
   *  Product: '<S207>/Divide6'
   *  Product: '<S207>/Divide7'
   *  Sum: '<S207>/Add1'
   *  Sum: '<S207>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                   EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                   EKF_IFS_2_P.Cnb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                  (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                  EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                 EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S202>/Add' incorporates:
   *  Product: '<S202>/Divide3'
   *  Product: '<S202>/Divide5'
   *  Trigonometry: '<S202>/Trigonometric Function'
   *  Trigonometry: '<S202>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = rtb_Add2_lg4 * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add2_c5;

  /* Product: '<S215>/Divide4' incorporates:
   *  Constant: '<S215>/Ixz'
   */
  rtb_Divide4_in = EKF_IFS_2_P.IxzB / rtb_Divide4_jaz;

  /* Sum: '<S206>/Add2' incorporates:
   *  Product: '<S206>/Divide1'
   *  Product: '<S206>/Divide6'
   *  Trigonometry: '<S206>/Trigonometric Function4'
   *  Trigonometry: '<S206>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Add2_lg4 * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add2_c5;

  /* Sum: '<S180>/Add2' incorporates:
   *  Constant: '<S180>/Constant1'
   *  Constant: '<S180>/Constant2'
   *  Constant: '<S212>/Ixz'
   *  Constant: '<S212>/Iyy'
   *  Constant: '<S212>/Izz'
   *  Constant: '<S214>/Izz'
   *  Math: '<S212>/Math Function'
   *  Product: '<S180>/Divide'
   *  Product: '<S180>/Divide1'
   *  Product: '<S180>/Divide2'
   *  Product: '<S180>/Divide3'
   *  Product: '<S180>/Divide4'
   *  Product: '<S180>/Divide5'
   *  Product: '<S180>/Divide6'
   *  Product: '<S212>/Divide3'
   *  Product: '<S212>/Divide4'
   *  Product: '<S214>/Divide4'
   *  Sum: '<S180>/Add'
   *  Sum: '<S180>/Add1'
   *  Sum: '<S212>/Add'
   *  Sum: '<S212>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_lg4 = (((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                   EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Divide4_jaz *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Divide4_ot *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[10] + (EKF_IFS_2_P.IzzB / rtb_Divide4_jaz *
    rtb_Divide_niq + rtb_Divide4_in * rtb_Add2_c5) * (rtb_Divide4_dh *
    EKF_IFS_2_P.S * EKF_IFS_2_P.b);

  /* Sum: '<S182>/Add1' incorporates:
   *  Constant: '<S182>/Constant1'
   *  Constant: '<S182>/Constant2'
   *  Constant: '<S205>/Constant'
   *  Constant: '<S205>/Constant1'
   *  Constant: '<S205>/Constant11'
   *  Constant: '<S205>/Constant12'
   *  Constant: '<S205>/Constant13'
   *  Constant: '<S205>/Constant14'
   *  Constant: '<S205>/Constant2'
   *  Constant: '<S205>/Constant3'
   *  Constant: '<S205>/Constant4'
   *  Constant: '<S205>/Constant5'
   *  Constant: '<S205>/Constant6'
   *  Constant: '<S205>/Constant7'
   *  Constant: '<S205>/Constant8'
   *  Constant: '<S205>/Constant9'
   *  Constant: '<S216>/Ixx'
   *  Constant: '<S216>/Iyy'
   *  Constant: '<S216>/Izz'
   *  Constant: '<S217>/Ixz'
   *  Constant: '<S217>/Iyy'
   *  Constant: '<S218>/Ixz'
   *  Constant: '<S218>/Iyy'
   *  Gain: '<S205>/Gain1'
   *  Gain: '<S205>/Gain2'
   *  Math: '<S182>/Math Function'
   *  Math: '<S182>/Math Function1'
   *  Product: '<S182>/Divide'
   *  Product: '<S182>/Divide2'
   *  Product: '<S182>/Divide3'
   *  Product: '<S182>/Divide5'
   *  Product: '<S182>/Divide6'
   *  Product: '<S205>/Divide1'
   *  Product: '<S205>/Divide2'
   *  Product: '<S205>/Divide3'
   *  Product: '<S205>/Divide4'
   *  Product: '<S205>/Divide5'
   *  Product: '<S205>/Divide6'
   *  Product: '<S216>/Divide4'
   *  Product: '<S217>/Divide4'
   *  Product: '<S218>/Divide4'
   *  Sum: '<S182>/Add3'
   *  Sum: '<S205>/Add'
   *  Sum: '<S205>/Add1'
   *  Sum: '<S205>/Add2'
   *  Sum: '<S205>/Add3'
   *  Sum: '<S216>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S191>/Unit Delay'
   */
  rtb_Add1_bmn = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                      EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                      EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                     EKF_IFS_2_DW.UnitDelay_DSTATE * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim *
                    (rtb_Add1_bmn - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.Cmde *
                   EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                  (rtb_Add1_bmn - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1 *
                  EKF_IFS_2_P.Gain2_Gain_c * EKF_IFS_2_P.Gain1_Gain_c) *
    (EKF_IFS_2_P.Ixz_Value / EKF_IFS_2_P.IyyB) * (rtb_Divide4_dh * EKF_IFS_2_P.S
    * EKF_IFS_2_P.Cbar) + ((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB));

  /* Sum: '<S183>/Add2' incorporates:
   *  Constant: '<S183>/Constant1'
   *  Constant: '<S183>/Constant2'
   *  Constant: '<S219>/Ixx'
   *  Constant: '<S219>/Ixx1'
   *  Constant: '<S219>/Ixz'
   *  Constant: '<S219>/Iyy'
   *  Constant: '<S220>/Ixx'
   *  Math: '<S219>/Math Function'
   *  Product: '<S183>/Divide'
   *  Product: '<S183>/Divide1'
   *  Product: '<S183>/Divide2'
   *  Product: '<S183>/Divide3'
   *  Product: '<S183>/Divide4'
   *  Product: '<S183>/Divide5'
   *  Product: '<S183>/Divide6'
   *  Product: '<S219>/Divide3'
   *  Product: '<S219>/Divide4'
   *  Product: '<S220>/Divide4'
   *  Sum: '<S183>/Add'
   *  Sum: '<S183>/Add1'
   *  Sum: '<S219>/Add'
   *  Sum: '<S219>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_in = (((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
                     EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Divide4_jaz *
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Divide4_ot *
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[10] + (EKF_IFS_2_P.IxxB / rtb_Divide4_jaz *
    rtb_Add2_c5 + rtb_Divide4_in * rtb_Divide_niq) * (rtb_Divide4_dh *
    EKF_IFS_2_P.S * EKF_IFS_2_P.b);

  /* Sum: '<S158>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_b4 = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[0];

  /* Product: '<S499>/Divide2' incorporates:
   *  Trigonometry: '<S499>/Trigonometric Function'
   *  Trigonometry: '<S499>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S501>/Divide2' incorporates:
   *  Trigonometry: '<S501>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S504>/Divide2' incorporates:
   *  Trigonometry: '<S504>/Trigonometric Function'
   *  Trigonometry: '<S504>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S496>/Divide4' incorporates:
   *  Constant: '<S496>/Constant'
   *  Constant: '<S496>/Constant1'
   *  Math: '<S496>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_lez = EKF_IFS_2_P.Constant_Value_a * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S515>/Add' incorporates:
   *  Constant: '<S515>/Constant'
   *  Constant: '<S515>/Constant1'
   *  Constant: '<S515>/Constant10'
   *  Constant: '<S515>/Constant11'
   *  Constant: '<S515>/Constant12'
   *  Constant: '<S515>/Constant13'
   *  Constant: '<S515>/Constant14'
   *  Constant: '<S515>/Constant15'
   *  Constant: '<S515>/Constant2'
   *  Constant: '<S515>/Constant3'
   *  Constant: '<S515>/Constant4'
   *  Constant: '<S515>/Constant5'
   *  Constant: '<S515>/Constant6'
   *  Constant: '<S515>/Constant7'
   *  Constant: '<S515>/Constant8'
   *  Constant: '<S515>/Constant9'
   *  Gain: '<S515>/Gain1'
   *  Gain: '<S515>/Gain2'
   *  Gain: '<S515>/Gain3'
   *  Product: '<S515>/Divide1'
   *  Product: '<S515>/Divide2'
   *  Product: '<S515>/Divide3'
   *  Product: '<S515>/Divide4'
   *  Product: '<S515>/Divide5'
   *  Product: '<S515>/Divide6'
   *  Product: '<S515>/Divide7'
   *  Sum: '<S515>/Add1'
   *  Sum: '<S515>/Add2'
   *  Sum: '<S515>/Add3'
   *  Sum: '<S515>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S506>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_c * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_Azb - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_Azb - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_j * EKF_IFS_2_P.Gain1_Gain_m) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_e3;

  /* ManualSwitch: '<S514>/Manual Switch' incorporates:
   *  Constant: '<S514>/AR'
   *  Constant: '<S514>/Constant15'
   *  Constant: '<S514>/Constant16'
   *  Constant: '<S514>/Constant17'
   *  Constant: '<S514>/Constant18'
   *  Constant: '<S514>/e'
   *  Math: '<S514>/Math Function'
   *  Product: '<S514>/Divide8'
   *  Product: '<S514>/Divide9'
   *  Sum: '<S514>/Add5'
   *  Sum: '<S514>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_db == 1) {
    rtb_rudder_cmd = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_rudder_cmd = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_es
      / (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_dw +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S514>/Manual Switch' */

  /* Sum: '<S514>/Add' incorporates:
   *  Constant: '<S514>/Constant1'
   *  Constant: '<S514>/Constant10'
   *  Constant: '<S514>/Constant11'
   *  Constant: '<S514>/Constant12'
   *  Constant: '<S514>/Constant13'
   *  Constant: '<S514>/Constant14'
   *  Constant: '<S514>/Constant2'
   *  Constant: '<S514>/Constant3'
   *  Constant: '<S514>/Constant4'
   *  Constant: '<S514>/Constant6'
   *  Constant: '<S514>/Constant7'
   *  Constant: '<S514>/Constant8'
   *  Constant: '<S514>/Constant9'
   *  Gain: '<S514>/Gain1'
   *  Gain: '<S514>/Gain2'
   *  Gain: '<S514>/Gain3'
   *  Product: '<S514>/Divide1'
   *  Product: '<S514>/Divide2'
   *  Product: '<S514>/Divide3'
   *  Product: '<S514>/Divide5'
   *  Product: '<S514>/Divide6'
   *  Product: '<S514>/Divide7'
   *  Sum: '<S514>/Add1'
   *  Sum: '<S514>/Add2'
   *  Sum: '<S514>/Add3'
   *  Sum: '<S514>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S506>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_rudder_cmd) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_c * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_Azb - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_Azb - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_o * EKF_IFS_2_P.Gain1_Gain_lj) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_c;

  /* ManualSwitch: '<S500>/Manual Switch' incorporates:
   *  Constant: '<S500>/Constant1'
   *  Constant: '<S508>/Constant'
   *  Constant: '<S526>/Constant'
   *  Constant: '<S526>/Constant1'
   *  Constant: '<S526>/Constant2'
   *  Math: '<S526>/Math Function'
   *  Product: '<S500>/Divide'
   *  Product: '<S500>/Divide5'
   *  Product: '<S523>/Divide3'
   *  Product: '<S523>/Divide5'
   *  Product: '<S526>/Divide1'
   *  Product: '<S526>/Divide2'
   *  Sum: '<S500>/Add'
   *  Sum: '<S523>/Add'
   *  Sum: '<S526>/Add'
   *  Trigonometry: '<S523>/Trigonometric Function'
   *  Trigonometry: '<S523>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_e == 1) {
    /* Gain: '<S526>/Gain' */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_a * rtb_Add_b4;
    rtb_rudder_cmd = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 +
                        EKF_IFS_2_P.xT1 * rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz -
      rtb_Add_iq * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_lez *
      EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S500>/Manual Switch' */

  /* Sum: '<S500>/Add1' incorporates:
   *  Constant: '<S500>/Constant'
   *  Product: '<S500>/Divide2'
   *  Product: '<S500>/Divide3'
   *  Product: '<S500>/Divide4'
   *  Trigonometry: '<S500>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_Add2_jk -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Ayb) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S502>/Divide3' */
  rtb_Divide3_dt = rtb_Azb * rtb_rudder_cmd;

  /* ManualSwitch: '<S503>/Manual Switch' incorporates:
   *  Constant: '<S503>/Constant1'
   *  Constant: '<S508>/Constant'
   *  Constant: '<S516>/Constant'
   *  Constant: '<S516>/Constant1'
   *  Constant: '<S516>/Constant10'
   *  Constant: '<S516>/Constant11'
   *  Constant: '<S516>/Constant12'
   *  Constant: '<S516>/Constant2'
   *  Constant: '<S516>/Constant3'
   *  Constant: '<S516>/Constant4'
   *  Constant: '<S516>/Constant5'
   *  Constant: '<S516>/Constant6'
   *  Constant: '<S516>/Constant8'
   *  Product: '<S503>/Divide'
   *  Product: '<S503>/Divide5'
   *  Product: '<S516>/Divide1'
   *  Product: '<S516>/Divide3'
   *  Product: '<S516>/Divide4'
   *  Product: '<S516>/Divide5'
   *  Product: '<S516>/Divide6'
   *  Sum: '<S516>/Add'
   *  Sum: '<S516>/Add1'
   *  Sum: '<S516>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_ep == 1) {
    rtb_Axb = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                  EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                  EKF_IFS_2_P.Cyb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                 EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                EKF_IFS_2_P.Cyda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
               EKF_IFS_2_P.Cydr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) *
      (rtb_Divide4_lez * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S503>/Manual Switch' */

  /* Sum: '<S503>/Add1' incorporates:
   *  Constant: '<S503>/Constant'
   *  Product: '<S503>/Divide2'
   *  Product: '<S503>/Divide3'
   *  Product: '<S503>/Divide4'
   *  Trigonometry: '<S503>/Trigonometric Function'
   *  Trigonometry: '<S503>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Ayb -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_Azb) + sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S502>/Divide4' */
  rtb_Divide4_jbf = rtb_Add2_jk * rtb_Axb;

  /* ManualSwitch: '<S505>/Manual Switch' incorporates:
   *  Constant: '<S505>/Constant1'
   *  Constant: '<S508>/Constant'
   *  Product: '<S505>/Divide'
   *  Product: '<S505>/Divide5'
   *  Product: '<S525>/Divide1'
   *  Product: '<S525>/Divide6'
   *  Sum: '<S525>/Add2'
   *  Trigonometry: '<S525>/Trigonometric Function4'
   *  Trigonometry: '<S525>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_a5 == 1) {
    rtb_Sum8 = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) -
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_lez * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Sum8 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S505>/Manual Switch' */

  /* Sum: '<S505>/Add1' incorporates:
   *  Constant: '<S505>/Constant'
   *  Product: '<S505>/Divide2'
   *  Product: '<S505>/Divide3'
   *  Product: '<S505>/Divide4'
   *  Trigonometry: '<S505>/Trigonometric Function'
   *  Trigonometry: '<S505>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Azb -
               EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Add2_jk) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S502>/Divide5' */
  rtb_Divide5_fi2 = rtb_Ayb * rtb_Sum8;

  /* Product: '<S506>/Divide' incorporates:
   *  Math: '<S506>/Math Function'
   *  Math: '<S506>/Math Function1'
   *  Product: '<S506>/Divide3'
   *  Product: '<S506>/Divide4'
   *  Sum: '<S506>/Add'
   *  Sum: '<S506>/Add1'
   */
  rtb_Divide_hc = (rtb_Azb * rtb_Sum8 - rtb_Ayb * rtb_rudder_cmd) / (rtb_Azb *
    rtb_Azb + rtb_Ayb * rtb_Ayb);

  /* Product: '<S507>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_p2 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Axb;

  /* Product: '<S507>/Divide4' incorporates:
   *  Product: '<S507>/Divide1'
   *  Product: '<S507>/Divide2'
   *  Product: '<S507>/Divide5'
   *  Product: '<S507>/Divide6'
   *  Sum: '<S507>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_om = ((rtb_Azb * rtb_rudder_cmd + rtb_Add2_jk * rtb_Axb) + rtb_Ayb
                    * rtb_Sum8) / EKF_IFS_2_DW.x_est_00_DSTATE_f[4] *
    rtb_Add2_jk;

  /* Math: '<S507>/Math Function' */
  rtb_MathFunction_hl = rtb_Azb * rtb_Azb;

  /* Math: '<S507>/Math Function1' */
  rtb_MathFunction1_l0 = rtb_Ayb * rtb_Ayb;

  /* Sum: '<S536>/Add' incorporates:
   *  Constant: '<S536>/Ixx1'
   *  Constant: '<S536>/Ixz1'
   *  Constant: '<S536>/Izz1'
   *  Math: '<S536>/Math Function'
   *  Product: '<S536>/Divide1'
   */
  rtb_Ayb = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S528>/Divide4' incorporates:
   *  Constant: '<S528>/Ixx'
   *  Constant: '<S528>/Ixz'
   *  Constant: '<S528>/Iyy'
   *  Constant: '<S528>/Izz'
   *  Product: '<S528>/Divide3'
   *  Sum: '<S528>/Add'
   */
  rtb_Add2_jk = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_Ayb;

  /* Sum: '<S495>/Add1' incorporates:
   *  Constant: '<S527>/Ixz'
   *  Constant: '<S527>/Iyy'
   *  Constant: '<S527>/Izz'
   *  Math: '<S527>/Math Function'
   *  Product: '<S495>/Divide2'
   *  Product: '<S495>/Divide3'
   *  Product: '<S527>/Divide3'
   *  Product: '<S527>/Divide4'
   *  Sum: '<S527>/Add'
   *  Sum: '<S527>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_ds = ((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Add2_jk *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* Sum: '<S518>/Add' incorporates:
   *  Constant: '<S518>/Constant10'
   *  Constant: '<S518>/Constant11'
   *  Constant: '<S518>/Constant12'
   *  Constant: '<S518>/Constant13'
   *  Constant: '<S518>/Constant14'
   *  Constant: '<S518>/Constant15'
   *  Constant: '<S518>/Constant5'
   *  Constant: '<S518>/Constant6'
   *  Constant: '<S518>/Constant7'
   *  Constant: '<S518>/Constant8'
   *  Constant: '<S518>/Constant9'
   *  Product: '<S518>/Divide3'
   *  Product: '<S518>/Divide4'
   *  Product: '<S518>/Divide5'
   *  Product: '<S518>/Divide6'
   *  Product: '<S518>/Divide7'
   *  Sum: '<S518>/Add1'
   *  Sum: '<S518>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                        EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) /
                        EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Clb *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                       EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) /
                       EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Clda *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cldr *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S522>/Add' incorporates:
   *  Constant: '<S522>/Constant'
   *  Constant: '<S522>/Constant10'
   *  Constant: '<S522>/Constant11'
   *  Constant: '<S522>/Constant12'
   *  Constant: '<S522>/Constant13'
   *  Constant: '<S522>/Constant14'
   *  Constant: '<S522>/Constant15'
   *  Constant: '<S522>/Constant5'
   *  Constant: '<S522>/Constant6'
   *  Constant: '<S522>/Constant8'
   *  Constant: '<S522>/Constant9'
   *  Product: '<S522>/Divide3'
   *  Product: '<S522>/Divide4'
   *  Product: '<S522>/Divide5'
   *  Product: '<S522>/Divide6'
   *  Product: '<S522>/Divide7'
   *  Sum: '<S522>/Add1'
   *  Sum: '<S522>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_TrigonometricFunction1_kv = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] -
    EKF_IFS_2_P.Ptrim) * EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
    EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) * EKF_IFS_2_P.Cnr *
                                    (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
    EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cndr *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S517>/Add' incorporates:
   *  Product: '<S517>/Divide3'
   *  Product: '<S517>/Divide5'
   *  Trigonometry: '<S517>/Trigonometric Function'
   *  Trigonometry: '<S517>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_aileron_cmd = rtb_throttle_cmd * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) -
    sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_TrigonometricFunction1_kv;

  /* Product: '<S530>/Divide4' incorporates:
   *  Constant: '<S530>/Ixz'
   */
  rtb_Sum5 = EKF_IFS_2_P.IxzB / rtb_Ayb;

  /* Sum: '<S521>/Add2' incorporates:
   *  Product: '<S521>/Divide1'
   *  Product: '<S521>/Divide6'
   *  Trigonometry: '<S521>/Trigonometric Function4'
   *  Trigonometry: '<S521>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_TrigonometricFunction1_kv = rtb_throttle_cmd * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])
    * rtb_TrigonometricFunction1_kv;

  /* Sum: '<S495>/Add' incorporates:
   *  Constant: '<S529>/Izz'
   *  Product: '<S495>/Divide'
   *  Product: '<S495>/Divide4'
   *  Product: '<S529>/Divide4'
   */
  rtb_Add_n2 = EKF_IFS_2_P.IzzB / rtb_Ayb * rtb_aileron_cmd + rtb_Sum5 *
    rtb_TrigonometricFunction1_kv;

  /* Product: '<S497>/Divide' incorporates:
   *  Constant: '<S520>/Constant'
   *  Constant: '<S520>/Constant1'
   *  Constant: '<S520>/Constant11'
   *  Constant: '<S520>/Constant12'
   *  Constant: '<S520>/Constant13'
   *  Constant: '<S520>/Constant14'
   *  Constant: '<S520>/Constant2'
   *  Constant: '<S520>/Constant3'
   *  Constant: '<S520>/Constant4'
   *  Constant: '<S520>/Constant5'
   *  Constant: '<S520>/Constant6'
   *  Constant: '<S520>/Constant7'
   *  Constant: '<S520>/Constant8'
   *  Constant: '<S520>/Constant9'
   *  Constant: '<S533>/Ixz'
   *  Constant: '<S533>/Iyy'
   *  Gain: '<S520>/Gain1'
   *  Gain: '<S520>/Gain2'
   *  Product: '<S520>/Divide1'
   *  Product: '<S520>/Divide2'
   *  Product: '<S520>/Divide3'
   *  Product: '<S520>/Divide4'
   *  Product: '<S520>/Divide5'
   *  Product: '<S520>/Divide6'
   *  Product: '<S533>/Divide4'
   *  Sum: '<S520>/Add'
   *  Sum: '<S520>/Add1'
   *  Sum: '<S520>/Add2'
   *  Sum: '<S520>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S506>/Unit Delay'
   */
  rtb_Divide_e5 = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                       EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                       EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                      EKF_IFS_2_DW.UnitDelay_DSTATE_c * (EKF_IFS_2_P.Cbar / 2.0)
                      / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim
                     * (rtb_Azb - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.Cmde *
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim
                   * (rtb_Azb - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1 *
                   EKF_IFS_2_P.Gain2_Gain_h * EKF_IFS_2_P.Gain1_Gain_k) *
    (EKF_IFS_2_P.Ixz_Value_f / EKF_IFS_2_P.IyyB);

  /* Sum: '<S498>/Add1' incorporates:
   *  Constant: '<S534>/Ixx'
   *  Constant: '<S534>/Ixx1'
   *  Constant: '<S534>/Ixz'
   *  Constant: '<S534>/Iyy'
   *  Math: '<S534>/Math Function'
   *  Product: '<S498>/Divide2'
   *  Product: '<S498>/Divide3'
   *  Product: '<S534>/Divide3'
   *  Product: '<S534>/Divide4'
   *  Sum: '<S534>/Add'
   *  Sum: '<S534>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_i3 = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Add2_jk *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S498>/Add' incorporates:
   *  Constant: '<S535>/Ixx'
   *  Product: '<S498>/Divide'
   *  Product: '<S498>/Divide4'
   *  Product: '<S535>/Divide4'
   */
  rtb_Add_a = EKF_IFS_2_P.IxxB / rtb_Ayb * rtb_TrigonometricFunction1_kv +
    rtb_Sum5 * rtb_aileron_cmd;

  /* Sum: '<S153>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_aileron_cmd = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[1];

  /* Product: '<S274>/Divide2' incorporates:
   *  Trigonometry: '<S274>/Trigonometric Function'
   *  Trigonometry: '<S274>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S276>/Divide2' incorporates:
   *  Trigonometry: '<S276>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S279>/Divide2' incorporates:
   *  Trigonometry: '<S279>/Trigonometric Function'
   *  Trigonometry: '<S279>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S271>/Divide4' incorporates:
   *  Constant: '<S271>/Constant'
   *  Constant: '<S271>/Constant1'
   *  Math: '<S271>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_kov = EKF_IFS_2_P.Constant_Value_h * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S290>/Add' incorporates:
   *  Constant: '<S290>/Constant'
   *  Constant: '<S290>/Constant1'
   *  Constant: '<S290>/Constant10'
   *  Constant: '<S290>/Constant11'
   *  Constant: '<S290>/Constant12'
   *  Constant: '<S290>/Constant13'
   *  Constant: '<S290>/Constant14'
   *  Constant: '<S290>/Constant15'
   *  Constant: '<S290>/Constant2'
   *  Constant: '<S290>/Constant3'
   *  Constant: '<S290>/Constant4'
   *  Constant: '<S290>/Constant5'
   *  Constant: '<S290>/Constant6'
   *  Constant: '<S290>/Constant7'
   *  Constant: '<S290>/Constant8'
   *  Constant: '<S290>/Constant9'
   *  Gain: '<S290>/Gain1'
   *  Gain: '<S290>/Gain2'
   *  Gain: '<S290>/Gain3'
   *  Product: '<S290>/Divide1'
   *  Product: '<S290>/Divide2'
   *  Product: '<S290>/Divide3'
   *  Product: '<S290>/Divide4'
   *  Product: '<S290>/Divide5'
   *  Product: '<S290>/Divide6'
   *  Product: '<S290>/Divide7'
   *  Sum: '<S290>/Add1'
   *  Sum: '<S290>/Add2'
   *  Sum: '<S290>/Add3'
   *  Sum: '<S290>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S281>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_b * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_Sum8 - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  rtb_aileron_cmd) + 1.0 / EKF_IFS_2_P.Utrim * (rtb_Sum8 -
    EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain2_Gain_p *
                 EKF_IFS_2_P.Gain1_Gain_lq) + (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]
    - EKF_IFS_2_P.alphatrim) * EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_a;

  /* ManualSwitch: '<S289>/Manual Switch' incorporates:
   *  Constant: '<S289>/AR'
   *  Constant: '<S289>/Constant15'
   *  Constant: '<S289>/Constant16'
   *  Constant: '<S289>/Constant17'
   *  Constant: '<S289>/Constant18'
   *  Constant: '<S289>/e'
   *  Math: '<S289>/Math Function'
   *  Product: '<S289>/Divide8'
   *  Product: '<S289>/Divide9'
   *  Sum: '<S289>/Add5'
   *  Sum: '<S289>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_aq == 1) {
    rtb_Ayb = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Ayb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_e /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_n +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S289>/Manual Switch' */

  /* Sum: '<S289>/Add' incorporates:
   *  Constant: '<S289>/Constant1'
   *  Constant: '<S289>/Constant10'
   *  Constant: '<S289>/Constant11'
   *  Constant: '<S289>/Constant12'
   *  Constant: '<S289>/Constant13'
   *  Constant: '<S289>/Constant14'
   *  Constant: '<S289>/Constant2'
   *  Constant: '<S289>/Constant3'
   *  Constant: '<S289>/Constant4'
   *  Constant: '<S289>/Constant6'
   *  Constant: '<S289>/Constant7'
   *  Constant: '<S289>/Constant8'
   *  Constant: '<S289>/Constant9'
   *  Gain: '<S289>/Gain1'
   *  Gain: '<S289>/Gain2'
   *  Gain: '<S289>/Gain3'
   *  Product: '<S289>/Divide1'
   *  Product: '<S289>/Divide2'
   *  Product: '<S289>/Divide3'
   *  Product: '<S289>/Divide5'
   *  Product: '<S289>/Divide6'
   *  Product: '<S289>/Divide7'
   *  Sum: '<S289>/Add1'
   *  Sum: '<S289>/Add2'
   *  Sum: '<S289>/Add3'
   *  Sum: '<S289>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S281>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Ayb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_b * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_Sum8 - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 rtb_aileron_cmd) + 1.0 / EKF_IFS_2_P.Utrim * (rtb_Sum8 -
    EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain2_Gain_b *
                EKF_IFS_2_P.Gain1_Gain_e) - (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] -
    EKF_IFS_2_P.alphatrim) * EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_n;

  /* ManualSwitch: '<S275>/Manual Switch' incorporates:
   *  Constant: '<S275>/Constant1'
   *  Constant: '<S283>/Constant'
   *  Constant: '<S301>/Constant'
   *  Constant: '<S301>/Constant1'
   *  Constant: '<S301>/Constant2'
   *  Math: '<S301>/Math Function'
   *  Product: '<S275>/Divide'
   *  Product: '<S275>/Divide5'
   *  Product: '<S298>/Divide3'
   *  Product: '<S298>/Divide5'
   *  Product: '<S301>/Divide1'
   *  Product: '<S301>/Divide2'
   *  Sum: '<S275>/Add'
   *  Sum: '<S298>/Add'
   *  Sum: '<S301>/Add'
   *  Trigonometry: '<S298>/Trigonometric Function'
   *  Trigonometry: '<S298>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_gk == 1) {
    /* Gain: '<S301>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_g * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Ayb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq *
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_kov *
                EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S275>/Manual Switch' */

  /* Sum: '<S275>/Add1' incorporates:
   *  Constant: '<S275>/Constant'
   *  Product: '<S275>/Divide2'
   *  Product: '<S275>/Divide3'
   *  Product: '<S275>/Divide4'
   *  Trigonometry: '<S275>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_Axb -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_rudder_cmd) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* ManualSwitch: '<S278>/Manual Switch' incorporates:
   *  Constant: '<S278>/Constant1'
   *  Constant: '<S283>/Constant'
   *  Constant: '<S291>/Constant'
   *  Constant: '<S291>/Constant1'
   *  Constant: '<S291>/Constant10'
   *  Constant: '<S291>/Constant11'
   *  Constant: '<S291>/Constant12'
   *  Constant: '<S291>/Constant2'
   *  Constant: '<S291>/Constant3'
   *  Constant: '<S291>/Constant4'
   *  Constant: '<S291>/Constant5'
   *  Constant: '<S291>/Constant6'
   *  Constant: '<S291>/Constant8'
   *  Product: '<S278>/Divide'
   *  Product: '<S278>/Divide5'
   *  Product: '<S291>/Divide1'
   *  Product: '<S291>/Divide3'
   *  Product: '<S291>/Divide4'
   *  Product: '<S291>/Divide5'
   *  Product: '<S291>/Divide6'
   *  Sum: '<S291>/Add'
   *  Sum: '<S291>/Add1'
   *  Sum: '<S291>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_p == 1) {
    rtb_Add2_jk = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cyb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cyda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
                   EKF_IFS_2_P.Cydr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) *
      (rtb_Divide4_kov * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Add2_jk = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S278>/Manual Switch' */

  /* Sum: '<S278>/Add1' incorporates:
   *  Constant: '<S278>/Constant'
   *  Product: '<S278>/Divide2'
   *  Product: '<S278>/Divide3'
   *  Product: '<S278>/Divide4'
   *  Trigonometry: '<S278>/Trigonometric Function'
   *  Trigonometry: '<S278>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_rudder_cmd -
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_Sum8) + sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S277>/Divide4' */
  rtb_Divide4_dh = rtb_Axb * rtb_Add2_jk;

  /* ManualSwitch: '<S280>/Manual Switch' incorporates:
   *  Constant: '<S280>/Constant1'
   *  Constant: '<S283>/Constant'
   *  Product: '<S280>/Divide'
   *  Product: '<S280>/Divide5'
   *  Product: '<S300>/Divide1'
   *  Product: '<S300>/Divide6'
   *  Sum: '<S300>/Add2'
   *  Trigonometry: '<S300>/Trigonometric Function4'
   *  Trigonometry: '<S300>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_dt == 1) {
    rtb_Azb = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) - cos
               (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_kov * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Azb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S280>/Manual Switch' */

  /* Sum: '<S280>/Add1' incorporates:
   *  Constant: '<S280>/Constant'
   *  Product: '<S280>/Divide2'
   *  Product: '<S280>/Divide3'
   *  Product: '<S280>/Divide4'
   *  Trigonometry: '<S280>/Trigonometric Function'
   *  Trigonometry: '<S280>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8 -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Axb) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S277>/Divide5' */
  rtb_Add_lzz = rtb_rudder_cmd * rtb_Azb;

  /* Product: '<S281>/Divide' incorporates:
   *  Math: '<S281>/Math Function'
   *  Math: '<S281>/Math Function1'
   *  Product: '<S281>/Divide3'
   *  Product: '<S281>/Divide4'
   *  Sum: '<S281>/Add'
   *  Sum: '<S281>/Add1'
   */
  rtb_Divide_c3 = (rtb_Sum8 * rtb_Azb - rtb_rudder_cmd * rtb_Ayb) / (rtb_Sum8 *
    rtb_Sum8 + rtb_rudder_cmd * rtb_rudder_cmd);

  /* Product: '<S282>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_iq = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Add2_jk;

  /* Product: '<S282>/Divide4' incorporates:
   *  Product: '<S282>/Divide1'
   *  Product: '<S282>/Divide2'
   *  Product: '<S282>/Divide5'
   *  Product: '<S282>/Divide6'
   *  Sum: '<S282>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain_cl = ((rtb_Sum8 * rtb_Ayb + rtb_Axb * rtb_Add2_jk) + rtb_rudder_cmd *
                 rtb_Azb) / EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Axb;

  /* Sum: '<S311>/Add' incorporates:
   *  Constant: '<S311>/Ixx1'
   *  Constant: '<S311>/Ixz1'
   *  Constant: '<S311>/Izz1'
   *  Math: '<S311>/Math Function'
   *  Product: '<S311>/Divide1'
   */
  rtb_Add2_jk = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S303>/Divide4' incorporates:
   *  Constant: '<S303>/Ixx'
   *  Constant: '<S303>/Ixz'
   *  Constant: '<S303>/Iyy'
   *  Constant: '<S303>/Izz'
   *  Product: '<S303>/Divide3'
   *  Sum: '<S303>/Add'
   */
  rtb_Azb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_Add2_jk;

  /* Sum: '<S293>/Add' incorporates:
   *  Constant: '<S293>/Constant10'
   *  Constant: '<S293>/Constant11'
   *  Constant: '<S293>/Constant12'
   *  Constant: '<S293>/Constant13'
   *  Constant: '<S293>/Constant14'
   *  Constant: '<S293>/Constant15'
   *  Constant: '<S293>/Constant5'
   *  Constant: '<S293>/Constant6'
   *  Constant: '<S293>/Constant7'
   *  Constant: '<S293>/Constant8'
   *  Constant: '<S293>/Constant9'
   *  Product: '<S293>/Divide3'
   *  Product: '<S293>/Divide4'
   *  Product: '<S293>/Divide5'
   *  Product: '<S293>/Divide6'
   *  Product: '<S293>/Divide7'
   *  Sum: '<S293>/Add1'
   *  Sum: '<S293>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                   EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                   EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                  (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                  EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                 EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S297>/Add' incorporates:
   *  Constant: '<S297>/Constant'
   *  Constant: '<S297>/Constant10'
   *  Constant: '<S297>/Constant11'
   *  Constant: '<S297>/Constant12'
   *  Constant: '<S297>/Constant13'
   *  Constant: '<S297>/Constant14'
   *  Constant: '<S297>/Constant15'
   *  Constant: '<S297>/Constant5'
   *  Constant: '<S297>/Constant6'
   *  Constant: '<S297>/Constant8'
   *  Constant: '<S297>/Constant9'
   *  Product: '<S297>/Divide3'
   *  Product: '<S297>/Divide4'
   *  Product: '<S297>/Divide5'
   *  Product: '<S297>/Divide6'
   *  Product: '<S297>/Divide7'
   *  Sum: '<S297>/Add1'
   *  Sum: '<S297>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_jaz = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                       EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                       EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                      (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                      EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cnda *
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cndr *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S292>/Add' incorporates:
   *  Product: '<S292>/Divide3'
   *  Product: '<S292>/Divide5'
   *  Trigonometry: '<S292>/Trigonometric Function'
   *  Trigonometry: '<S292>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_ot = rtb_Add2_c5 * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide4_jaz;

  /* Product: '<S305>/Divide4' incorporates:
   *  Constant: '<S305>/Ixz'
   */
  rtb_etaLon = EKF_IFS_2_P.IxzB / rtb_Add2_jk;

  /* Sum: '<S296>/Add2' incorporates:
   *  Product: '<S296>/Divide1'
   *  Product: '<S296>/Divide6'
   *  Trigonometry: '<S296>/Trigonometric Function4'
   *  Trigonometry: '<S296>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Add2_c5 * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide4_jaz;

  /* Saturate: '<S267>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Product: '<S147>/Divide1' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S267>/Gain'
   *  Gain: '<S267>/Gain1'
   *  Saturate: '<S267>/Throttle Limiter'
   *  Sum: '<S147>/Sum1'
   *  Sum: '<S267>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide1_g0[0] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S267>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Product: '<S147>/Divide1' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S267>/Gain2'
   *  Gain: '<S267>/Gain3'
   *  Saturate: '<S267>/Elevator Limiter'
   *  Sum: '<S147>/Sum1'
   *  Sum: '<S267>/Add1'
   */
  rtb_Divide1_g0[1] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                        rtb_aileron_cmd) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S267>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Product: '<S147>/Divide1' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S267>/Gain4'
   *  Gain: '<S267>/Gain5'
   *  Saturate: '<S267>/Aileron Limiter'
   *  Sum: '<S147>/Sum1'
   *  Sum: '<S267>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide1_g0[2] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S267>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Product: '<S147>/Divide1' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S267>/Gain6'
   *  Gain: '<S267>/Gain7'
   *  Math: '<S282>/Math Function'
   *  Math: '<S282>/Math Function1'
   *  Product: '<S277>/Divide'
   *  Product: '<S277>/Divide3'
   *  Product: '<S282>/Divide'
   *  Saturate: '<S267>/Rudder Limiter'
   *  Sum: '<S147>/Sum1'
   *  Sum: '<S267>/Add3'
   *  Sum: '<S277>/Add'
   *  Sum: '<S282>/Add'
   *  Sum: '<S282>/Add1'
   *  Trigonometry: '<S282>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide1_g0[3] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[4] = (((rtb_Sum8 * rtb_Ayb + rtb_Divide4_dh) + rtb_Add_lzz) /
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[5] = (rtb_Divide_c3 - rtb_Divide) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[6] = ((rtb_Add_iq - rtb_Gain_cl) / (rtb_Sum8 * rtb_Sum8 +
    rtb_rudder_cmd * rtb_rudder_cmd) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) -
                       rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i;

  /* Trigonometry: '<S285>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S285>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_h) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_h;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_e) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_e;
    }
  }

  /* Product: '<S147>/Divide1' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S270>/Constant1'
   *  Constant: '<S270>/Constant2'
   *  Constant: '<S272>/Constant1'
   *  Constant: '<S272>/Constant2'
   *  Constant: '<S273>/Constant1'
   *  Constant: '<S273>/Constant2'
   *  Constant: '<S286>/Constant'
   *  Constant: '<S287>/Constant'
   *  Constant: '<S295>/Constant'
   *  Constant: '<S295>/Constant1'
   *  Constant: '<S295>/Constant11'
   *  Constant: '<S295>/Constant12'
   *  Constant: '<S295>/Constant13'
   *  Constant: '<S295>/Constant14'
   *  Constant: '<S295>/Constant2'
   *  Constant: '<S295>/Constant3'
   *  Constant: '<S295>/Constant4'
   *  Constant: '<S295>/Constant5'
   *  Constant: '<S295>/Constant6'
   *  Constant: '<S295>/Constant7'
   *  Constant: '<S295>/Constant8'
   *  Constant: '<S295>/Constant9'
   *  Constant: '<S302>/Ixz'
   *  Constant: '<S302>/Iyy'
   *  Constant: '<S302>/Izz'
   *  Constant: '<S304>/Izz'
   *  Constant: '<S306>/Ixx'
   *  Constant: '<S306>/Iyy'
   *  Constant: '<S306>/Izz'
   *  Constant: '<S307>/Ixz'
   *  Constant: '<S307>/Iyy'
   *  Constant: '<S308>/Ixz'
   *  Constant: '<S308>/Iyy'
   *  Constant: '<S309>/Ixx'
   *  Constant: '<S309>/Ixx1'
   *  Constant: '<S309>/Ixz'
   *  Constant: '<S309>/Iyy'
   *  Constant: '<S310>/Ixx'
   *  Gain: '<S295>/Gain1'
   *  Gain: '<S295>/Gain2'
   *  Math: '<S272>/Math Function'
   *  Math: '<S272>/Math Function1'
   *  Math: '<S302>/Math Function'
   *  Math: '<S309>/Math Function'
   *  Product: '<S270>/Divide'
   *  Product: '<S270>/Divide1'
   *  Product: '<S270>/Divide2'
   *  Product: '<S270>/Divide3'
   *  Product: '<S270>/Divide4'
   *  Product: '<S270>/Divide5'
   *  Product: '<S270>/Divide6'
   *  Product: '<S272>/Divide'
   *  Product: '<S272>/Divide2'
   *  Product: '<S272>/Divide3'
   *  Product: '<S272>/Divide5'
   *  Product: '<S272>/Divide6'
   *  Product: '<S273>/Divide'
   *  Product: '<S273>/Divide1'
   *  Product: '<S273>/Divide2'
   *  Product: '<S273>/Divide3'
   *  Product: '<S273>/Divide4'
   *  Product: '<S273>/Divide5'
   *  Product: '<S273>/Divide6'
   *  Product: '<S285>/Divide1'
   *  Product: '<S285>/Divide2'
   *  Product: '<S285>/Divide4'
   *  Product: '<S288>/Divide2'
   *  Product: '<S288>/Divide4'
   *  Product: '<S295>/Divide1'
   *  Product: '<S295>/Divide2'
   *  Product: '<S295>/Divide3'
   *  Product: '<S295>/Divide4'
   *  Product: '<S295>/Divide5'
   *  Product: '<S295>/Divide6'
   *  Product: '<S302>/Divide3'
   *  Product: '<S302>/Divide4'
   *  Product: '<S304>/Divide4'
   *  Product: '<S306>/Divide4'
   *  Product: '<S307>/Divide4'
   *  Product: '<S308>/Divide4'
   *  Product: '<S309>/Divide3'
   *  Product: '<S309>/Divide4'
   *  Product: '<S310>/Divide4'
   *  Saturate: '<S285>/Saturation'
   *  Sum: '<S147>/Sum1'
   *  Sum: '<S270>/Add'
   *  Sum: '<S270>/Add1'
   *  Sum: '<S270>/Add2'
   *  Sum: '<S272>/Add1'
   *  Sum: '<S272>/Add3'
   *  Sum: '<S273>/Add'
   *  Sum: '<S273>/Add1'
   *  Sum: '<S273>/Add2'
   *  Sum: '<S285>/Add'
   *  Sum: '<S285>/Add1'
   *  Sum: '<S288>/Add'
   *  Sum: '<S295>/Add'
   *  Sum: '<S295>/Add1'
   *  Sum: '<S295>/Add2'
   *  Sum: '<S295>/Add3'
   *  Sum: '<S302>/Add'
   *  Sum: '<S302>/Add1'
   *  Sum: '<S306>/Add'
   *  Sum: '<S309>/Add'
   *  Sum: '<S309>/Add1'
   *  Trigonometry: '<S285>/Trigonometric Function1'
   *  Trigonometry: '<S285>/Trigonometric Function2'
   *  Trigonometry: '<S288>/Trigonometric Function1'
   *  Trigonometry: '<S288>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S281>/Unit Delay'
   */
  rtb_Divide1_g0[7] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7])
    * EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0 +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[8] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[9] = (((((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Add2_jk *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Azb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) * EKF_IFS_2_DW.x_est_00_DSTATE_f[10] +
                        (EKF_IFS_2_P.IzzB / rtb_Add2_jk * rtb_Divide4_ot +
    rtb_etaLon * rtb_Add2_c5) * (rtb_Divide4_kov * EKF_IFS_2_P.S * EKF_IFS_2_P.b))
                       - rtb_Add2_lg4) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[10] = ((((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] -
    EKF_IFS_2_P.Qtrim) * EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
    EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
    EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot * EKF_IFS_2_DW.UnitDelay_DSTATE_b *
    (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu /
    EKF_IFS_2_P.Utrim * (rtb_Sum8 - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.Cmde *
    rtb_aileron_cmd) + 1.0 / EKF_IFS_2_P.Utrim * (rtb_Sum8 - EKF_IFS_2_P.Utrim) *
    EKF_IFS_2_P.Cm1 * EKF_IFS_2_P.Gain2_Gain_e * EKF_IFS_2_P.Gain1_Gain_b) *
    (EKF_IFS_2_P.Ixz_Value_g / EKF_IFS_2_P.IyyB) * (rtb_Divide4_kov *
    EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar) + ((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB)))
                        - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[11] = (((((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) *
    EKF_IFS_2_P.IxxB + EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Add2_jk *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Azb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * EKF_IFS_2_DW.x_est_00_DSTATE_f[10] +
    (EKF_IFS_2_P.IxxB / rtb_Add2_jk * rtb_Add2_c5 + rtb_etaLon * rtb_Divide4_ot)
    * (rtb_Divide4_kov * EKF_IFS_2_P.S * EKF_IFS_2_P.b)) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[12] = (EKF_IFS_2_P.Constant_Value_aw -
                        EKF_IFS_2_P.Constant_Value_b) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_Divide1_g0[13] = (EKF_IFS_2_P.Constant_Value_j -
                        EKF_IFS_2_P.Constant_Value_m) /
    EKF_IFS_2_P.delta_Value_i;

  /* Sum: '<S152>/Add1' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_kk = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[2];

  /* Product: '<S229>/Divide2' incorporates:
   *  Trigonometry: '<S229>/Trigonometric Function'
   *  Trigonometry: '<S229>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S231>/Divide2' incorporates:
   *  Trigonometry: '<S231>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S234>/Divide2' incorporates:
   *  Trigonometry: '<S234>/Trigonometric Function'
   *  Trigonometry: '<S234>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S226>/Divide4' incorporates:
   *  Constant: '<S226>/Constant'
   *  Constant: '<S226>/Constant1'
   *  Math: '<S226>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_fe = EKF_IFS_2_P.Constant_Value_m5 * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S245>/Add' incorporates:
   *  Constant: '<S245>/Constant'
   *  Constant: '<S245>/Constant1'
   *  Constant: '<S245>/Constant10'
   *  Constant: '<S245>/Constant11'
   *  Constant: '<S245>/Constant12'
   *  Constant: '<S245>/Constant13'
   *  Constant: '<S245>/Constant14'
   *  Constant: '<S245>/Constant15'
   *  Constant: '<S245>/Constant2'
   *  Constant: '<S245>/Constant3'
   *  Constant: '<S245>/Constant4'
   *  Constant: '<S245>/Constant5'
   *  Constant: '<S245>/Constant6'
   *  Constant: '<S245>/Constant7'
   *  Constant: '<S245>/Constant8'
   *  Constant: '<S245>/Constant9'
   *  Gain: '<S245>/Gain1'
   *  Gain: '<S245>/Gain2'
   *  Gain: '<S245>/Gain3'
   *  Product: '<S245>/Divide1'
   *  Product: '<S245>/Divide2'
   *  Product: '<S245>/Divide3'
   *  Product: '<S245>/Divide4'
   *  Product: '<S245>/Divide5'
   *  Product: '<S245>/Divide6'
   *  Product: '<S245>/Divide7'
   *  Sum: '<S245>/Add1'
   *  Sum: '<S245>/Add2'
   *  Sum: '<S245>/Add3'
   *  Sum: '<S245>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S236>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_d * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_h5 * EKF_IFS_2_P.Gain1_Gain_lb) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_by;

  /* ManualSwitch: '<S244>/Manual Switch' incorporates:
   *  Constant: '<S244>/AR'
   *  Constant: '<S244>/Constant15'
   *  Constant: '<S244>/Constant16'
   *  Constant: '<S244>/Constant17'
   *  Constant: '<S244>/Constant18'
   *  Constant: '<S244>/e'
   *  Math: '<S244>/Math Function'
   *  Product: '<S244>/Divide8'
   *  Product: '<S244>/Divide9'
   *  Sum: '<S244>/Add5'
   *  Sum: '<S244>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_ds == 1) {
    rtb_Axb = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Axb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_a /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_o +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S244>/Manual Switch' */

  /* Sum: '<S244>/Add' incorporates:
   *  Constant: '<S244>/Constant1'
   *  Constant: '<S244>/Constant10'
   *  Constant: '<S244>/Constant11'
   *  Constant: '<S244>/Constant12'
   *  Constant: '<S244>/Constant13'
   *  Constant: '<S244>/Constant14'
   *  Constant: '<S244>/Constant2'
   *  Constant: '<S244>/Constant3'
   *  Constant: '<S244>/Constant4'
   *  Constant: '<S244>/Constant6'
   *  Constant: '<S244>/Constant7'
   *  Constant: '<S244>/Constant8'
   *  Constant: '<S244>/Constant9'
   *  Gain: '<S244>/Gain1'
   *  Gain: '<S244>/Gain2'
   *  Gain: '<S244>/Gain3'
   *  Product: '<S244>/Divide1'
   *  Product: '<S244>/Divide2'
   *  Product: '<S244>/Divide3'
   *  Product: '<S244>/Divide5'
   *  Product: '<S244>/Divide6'
   *  Product: '<S244>/Divide7'
   *  Sum: '<S244>/Add1'
   *  Sum: '<S244>/Add2'
   *  Sum: '<S244>/Add3'
   *  Sum: '<S244>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S236>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Axb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_d * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_m * EKF_IFS_2_P.Gain1_Gain_ly) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_j;

  /* ManualSwitch: '<S230>/Manual Switch' incorporates:
   *  Constant: '<S230>/Constant1'
   *  Constant: '<S238>/Constant'
   *  Constant: '<S256>/Constant'
   *  Constant: '<S256>/Constant1'
   *  Constant: '<S256>/Constant2'
   *  Math: '<S256>/Math Function'
   *  Product: '<S230>/Divide'
   *  Product: '<S230>/Divide5'
   *  Product: '<S253>/Divide3'
   *  Product: '<S253>/Divide5'
   *  Product: '<S256>/Divide1'
   *  Product: '<S256>/Divide2'
   *  Sum: '<S230>/Add'
   *  Sum: '<S253>/Add'
   *  Sum: '<S256>/Add'
   *  Trigonometry: '<S253>/Trigonometric Function'
   *  Trigonometry: '<S253>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_gp == 1) {
    /* Gain: '<S256>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_n * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Axb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq *
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_fe *
                EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S230>/Manual Switch' */

  /* Sum: '<S230>/Add1' incorporates:
   *  Constant: '<S230>/Constant'
   *  Product: '<S230>/Divide2'
   *  Product: '<S230>/Divide3'
   *  Product: '<S230>/Divide4'
   *  Trigonometry: '<S230>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S232>/Divide3' */
  rtb_Divide3_ppi = rtb_throttle_cmd * rtb_Axb;

  /* ManualSwitch: '<S233>/Manual Switch' incorporates:
   *  Constant: '<S233>/Constant1'
   *  Constant: '<S238>/Constant'
   *  Constant: '<S246>/Constant'
   *  Constant: '<S246>/Constant1'
   *  Constant: '<S246>/Constant10'
   *  Constant: '<S246>/Constant11'
   *  Constant: '<S246>/Constant12'
   *  Constant: '<S246>/Constant2'
   *  Constant: '<S246>/Constant3'
   *  Constant: '<S246>/Constant4'
   *  Constant: '<S246>/Constant5'
   *  Constant: '<S246>/Constant6'
   *  Constant: '<S246>/Constant8'
   *  Product: '<S233>/Divide'
   *  Product: '<S233>/Divide5'
   *  Product: '<S246>/Divide1'
   *  Product: '<S246>/Divide3'
   *  Product: '<S246>/Divide4'
   *  Product: '<S246>/Divide5'
   *  Product: '<S246>/Divide6'
   *  Sum: '<S246>/Add'
   *  Sum: '<S246>/Add1'
   *  Sum: '<S246>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_o == 1) {
    rtb_rudder_cmd = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim)
                         * EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) /
                         EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cyb *
                         EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim)
                        * EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) /
                        EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cyda * rtb_Add1_kk) +
                      EKF_IFS_2_P.Cydr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) *
      (rtb_Divide4_fe * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S233>/Manual Switch' */

  /* Sum: '<S233>/Add1' incorporates:
   *  Constant: '<S233>/Constant'
   *  Product: '<S233>/Divide2'
   *  Product: '<S233>/Divide3'
   *  Product: '<S233>/Divide4'
   *  Trigonometry: '<S233>/Trigonometric Function'
   *  Trigonometry: '<S233>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8 -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_throttle_cmd) +
    sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f
    [8]) * EKF_IFS_2_P.g;

  /* Product: '<S232>/Divide4' */
  rtb_Divide4_m2 = rtb_elevator_cmd * rtb_rudder_cmd;

  /* ManualSwitch: '<S235>/Manual Switch' incorporates:
   *  Constant: '<S235>/Constant1'
   *  Constant: '<S238>/Constant'
   *  Product: '<S235>/Divide'
   *  Product: '<S235>/Divide5'
   *  Product: '<S255>/Divide1'
   *  Product: '<S255>/Divide6'
   *  Sum: '<S255>/Add2'
   *  Trigonometry: '<S255>/Trigonometric Function4'
   *  Trigonometry: '<S255>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_j == 1) {
    rtb_Ayb = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) - cos
               (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_fe * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S235>/Manual Switch' */

  /* Sum: '<S235>/Add1' incorporates:
   *  Constant: '<S235>/Constant'
   *  Product: '<S235>/Divide2'
   *  Product: '<S235>/Divide3'
   *  Product: '<S235>/Divide4'
   *  Trigonometry: '<S235>/Trigonometric Function'
   *  Trigonometry: '<S235>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_elevator_cmd) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S232>/Divide5' */
  rtb_Divide5_kwv = rtb_Sum8 * rtb_Ayb;

  /* Product: '<S236>/Divide' incorporates:
   *  Math: '<S236>/Math Function'
   *  Math: '<S236>/Math Function1'
   *  Product: '<S236>/Divide3'
   *  Product: '<S236>/Divide4'
   *  Sum: '<S236>/Add'
   *  Sum: '<S236>/Add1'
   */
  rtb_Divide_mrb = (rtb_throttle_cmd * rtb_Ayb - rtb_Sum8 * rtb_Axb) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8);

  /* Product: '<S237>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_av = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_rudder_cmd;

  /* Product: '<S237>/Divide4' incorporates:
   *  Product: '<S237>/Divide1'
   *  Product: '<S237>/Divide2'
   *  Product: '<S237>/Divide5'
   *  Product: '<S237>/Divide6'
   *  Sum: '<S237>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_il = ((rtb_throttle_cmd * rtb_Axb + rtb_elevator_cmd *
                     rtb_rudder_cmd) + rtb_Sum8 * rtb_Ayb) /
    EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_elevator_cmd;

  /* Math: '<S237>/Math Function' */
  rtb_MathFunction_e1 = rtb_throttle_cmd * rtb_throttle_cmd;

  /* Math: '<S237>/Math Function1' */
  rtb_MathFunction1_o5 = rtb_Sum8 * rtb_Sum8;

  /* Sum: '<S266>/Add' incorporates:
   *  Constant: '<S266>/Ixx1'
   *  Constant: '<S266>/Ixz1'
   *  Constant: '<S266>/Izz1'
   *  Math: '<S266>/Math Function'
   *  Product: '<S266>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S258>/Divide4' incorporates:
   *  Constant: '<S258>/Ixx'
   *  Constant: '<S258>/Ixz'
   *  Constant: '<S258>/Iyy'
   *  Constant: '<S258>/Izz'
   *  Product: '<S258>/Divide3'
   *  Sum: '<S258>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S225>/Add1' incorporates:
   *  Constant: '<S257>/Ixz'
   *  Constant: '<S257>/Iyy'
   *  Constant: '<S257>/Izz'
   *  Math: '<S257>/Math Function'
   *  Product: '<S225>/Divide2'
   *  Product: '<S225>/Divide3'
   *  Product: '<S257>/Divide3'
   *  Product: '<S257>/Divide4'
   *  Sum: '<S257>/Add'
   *  Sum: '<S257>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_gx3 = ((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                  EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* Sum: '<S248>/Add' incorporates:
   *  Constant: '<S248>/Constant10'
   *  Constant: '<S248>/Constant11'
   *  Constant: '<S248>/Constant12'
   *  Constant: '<S248>/Constant13'
   *  Constant: '<S248>/Constant14'
   *  Constant: '<S248>/Constant15'
   *  Constant: '<S248>/Constant5'
   *  Constant: '<S248>/Constant6'
   *  Constant: '<S248>/Constant7'
   *  Constant: '<S248>/Constant8'
   *  Constant: '<S248>/Constant9'
   *  Product: '<S248>/Divide3'
   *  Product: '<S248>/Divide4'
   *  Product: '<S248>/Divide5'
   *  Product: '<S248>/Divide6'
   *  Product: '<S248>/Divide7'
   *  Sum: '<S248>/Add1'
   *  Sum: '<S248>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
               EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
               EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
              (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
              EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
             EKF_IFS_2_P.Clda * rtb_Add1_kk) + EKF_IFS_2_P.Cldr *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S252>/Add' incorporates:
   *  Constant: '<S252>/Constant'
   *  Constant: '<S252>/Constant10'
   *  Constant: '<S252>/Constant11'
   *  Constant: '<S252>/Constant12'
   *  Constant: '<S252>/Constant13'
   *  Constant: '<S252>/Constant14'
   *  Constant: '<S252>/Constant15'
   *  Constant: '<S252>/Constant5'
   *  Constant: '<S252>/Constant6'
   *  Constant: '<S252>/Constant8'
   *  Constant: '<S252>/Constant9'
   *  Product: '<S252>/Divide3'
   *  Product: '<S252>/Divide4'
   *  Product: '<S252>/Divide5'
   *  Product: '<S252>/Divide6'
   *  Product: '<S252>/Divide7'
   *  Sum: '<S252>/Add1'
   *  Sum: '<S252>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cnda * rtb_Add1_kk) + EKF_IFS_2_P.Cndr *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S247>/Add' incorporates:
   *  Product: '<S247>/Divide3'
   *  Product: '<S247>/Divide5'
   *  Trigonometry: '<S247>/Trigonometric Function'
   *  Trigonometry: '<S247>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Azb * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Product: '<S260>/Divide4' incorporates:
   *  Constant: '<S260>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S251>/Add2' incorporates:
   *  Product: '<S251>/Divide1'
   *  Product: '<S251>/Divide6'
   *  Trigonometry: '<S251>/Trigonometric Function4'
   *  Trigonometry: '<S251>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = rtb_Azb * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Sum: '<S225>/Add' incorporates:
   *  Constant: '<S259>/Izz'
   *  Product: '<S225>/Divide'
   *  Product: '<S225>/Divide4'
   *  Product: '<S259>/Divide4'
   */
  rtb_Add_i = EKF_IFS_2_P.IzzB / rtb_rudder_cmd * rtb_Add2_c5 + rtb_Divide4_jaz *
    rtb_Azb;

  /* Product: '<S227>/Divide' incorporates:
   *  Constant: '<S250>/Constant'
   *  Constant: '<S250>/Constant1'
   *  Constant: '<S250>/Constant11'
   *  Constant: '<S250>/Constant12'
   *  Constant: '<S250>/Constant13'
   *  Constant: '<S250>/Constant14'
   *  Constant: '<S250>/Constant2'
   *  Constant: '<S250>/Constant3'
   *  Constant: '<S250>/Constant4'
   *  Constant: '<S250>/Constant5'
   *  Constant: '<S250>/Constant6'
   *  Constant: '<S250>/Constant7'
   *  Constant: '<S250>/Constant8'
   *  Constant: '<S250>/Constant9'
   *  Constant: '<S263>/Ixz'
   *  Constant: '<S263>/Iyy'
   *  Gain: '<S250>/Gain1'
   *  Gain: '<S250>/Gain2'
   *  Product: '<S250>/Divide1'
   *  Product: '<S250>/Divide2'
   *  Product: '<S250>/Divide3'
   *  Product: '<S250>/Divide4'
   *  Product: '<S250>/Divide5'
   *  Product: '<S250>/Divide6'
   *  Product: '<S263>/Divide4'
   *  Sum: '<S250>/Add'
   *  Sum: '<S250>/Add1'
   *  Sum: '<S250>/Add2'
   *  Sum: '<S250>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S236>/Unit Delay'
   */
  rtb_Divide_a = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                      EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                      EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                     EKF_IFS_2_DW.UnitDelay_DSTATE_d * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim *
                    (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.Cmde *
                   EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1 *
                  EKF_IFS_2_P.Gain2_Gain_f * EKF_IFS_2_P.Gain1_Gain_cm) *
    (EKF_IFS_2_P.Ixz_Value_a / EKF_IFS_2_P.IyyB);

  /* Sum: '<S228>/Add1' incorporates:
   *  Constant: '<S264>/Ixx'
   *  Constant: '<S264>/Ixx1'
   *  Constant: '<S264>/Ixz'
   *  Constant: '<S264>/Iyy'
   *  Math: '<S264>/Math Function'
   *  Product: '<S228>/Divide2'
   *  Product: '<S228>/Divide3'
   *  Product: '<S264>/Divide3'
   *  Product: '<S264>/Divide4'
   *  Sum: '<S264>/Add'
   *  Sum: '<S264>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_an = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S228>/Add' incorporates:
   *  Constant: '<S265>/Ixx'
   *  Product: '<S228>/Divide'
   *  Product: '<S228>/Divide4'
   *  Product: '<S265>/Divide4'
   */
  rtb_Add_em1 = EKF_IFS_2_P.IxxB / rtb_rudder_cmd * rtb_Azb + rtb_Divide4_jaz *
    rtb_Add2_c5;

  /* Sum: '<S157>/Add1' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_nj = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Product: '<S454>/Divide2' incorporates:
   *  Trigonometry: '<S454>/Trigonometric Function'
   *  Trigonometry: '<S454>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S456>/Divide2' incorporates:
   *  Trigonometry: '<S456>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S459>/Divide2' incorporates:
   *  Trigonometry: '<S459>/Trigonometric Function'
   *  Trigonometry: '<S459>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S451>/Divide4' incorporates:
   *  Constant: '<S451>/Constant'
   *  Constant: '<S451>/Constant1'
   *  Math: '<S451>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_lx = EKF_IFS_2_P.Constant_Value_e0 * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S470>/Add' incorporates:
   *  Constant: '<S470>/Constant'
   *  Constant: '<S470>/Constant1'
   *  Constant: '<S470>/Constant10'
   *  Constant: '<S470>/Constant11'
   *  Constant: '<S470>/Constant12'
   *  Constant: '<S470>/Constant13'
   *  Constant: '<S470>/Constant14'
   *  Constant: '<S470>/Constant15'
   *  Constant: '<S470>/Constant2'
   *  Constant: '<S470>/Constant3'
   *  Constant: '<S470>/Constant4'
   *  Constant: '<S470>/Constant5'
   *  Constant: '<S470>/Constant6'
   *  Constant: '<S470>/Constant7'
   *  Constant: '<S470>/Constant8'
   *  Constant: '<S470>/Constant9'
   *  Gain: '<S470>/Gain1'
   *  Gain: '<S470>/Gain2'
   *  Gain: '<S470>/Gain3'
   *  Product: '<S470>/Divide1'
   *  Product: '<S470>/Divide2'
   *  Product: '<S470>/Divide3'
   *  Product: '<S470>/Divide4'
   *  Product: '<S470>/Divide5'
   *  Product: '<S470>/Divide6'
   *  Product: '<S470>/Divide7'
   *  Sum: '<S470>/Add1'
   *  Sum: '<S470>/Add2'
   *  Sum: '<S470>/Add3'
   *  Sum: '<S470>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S461>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_j * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_oa * EKF_IFS_2_P.Gain1_Gain_mv) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_e1;

  /* ManualSwitch: '<S469>/Manual Switch' incorporates:
   *  Constant: '<S469>/AR'
   *  Constant: '<S469>/Constant15'
   *  Constant: '<S469>/Constant16'
   *  Constant: '<S469>/Constant17'
   *  Constant: '<S469>/Constant18'
   *  Constant: '<S469>/e'
   *  Math: '<S469>/Math Function'
   *  Product: '<S469>/Divide8'
   *  Product: '<S469>/Divide9'
   *  Sum: '<S469>/Add5'
   *  Sum: '<S469>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_l == 1) {
    rtb_Axb = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Axb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_i /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_i +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S469>/Manual Switch' */

  /* Sum: '<S469>/Add' incorporates:
   *  Constant: '<S469>/Constant1'
   *  Constant: '<S469>/Constant10'
   *  Constant: '<S469>/Constant11'
   *  Constant: '<S469>/Constant12'
   *  Constant: '<S469>/Constant13'
   *  Constant: '<S469>/Constant14'
   *  Constant: '<S469>/Constant2'
   *  Constant: '<S469>/Constant3'
   *  Constant: '<S469>/Constant4'
   *  Constant: '<S469>/Constant6'
   *  Constant: '<S469>/Constant7'
   *  Constant: '<S469>/Constant8'
   *  Constant: '<S469>/Constant9'
   *  Gain: '<S469>/Gain1'
   *  Gain: '<S469>/Gain2'
   *  Gain: '<S469>/Gain3'
   *  Product: '<S469>/Divide1'
   *  Product: '<S469>/Divide2'
   *  Product: '<S469>/Divide3'
   *  Product: '<S469>/Divide5'
   *  Product: '<S469>/Divide6'
   *  Product: '<S469>/Divide7'
   *  Sum: '<S469>/Add1'
   *  Sum: '<S469>/Add2'
   *  Sum: '<S469>/Add3'
   *  Sum: '<S469>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S461>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Axb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_j * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_lf * EKF_IFS_2_P.Gain1_Gain_o5) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_h;

  /* ManualSwitch: '<S455>/Manual Switch' incorporates:
   *  Constant: '<S455>/Constant1'
   *  Constant: '<S463>/Constant'
   *  Constant: '<S481>/Constant'
   *  Constant: '<S481>/Constant1'
   *  Constant: '<S481>/Constant2'
   *  Math: '<S481>/Math Function'
   *  Product: '<S455>/Divide'
   *  Product: '<S455>/Divide5'
   *  Product: '<S478>/Divide3'
   *  Product: '<S478>/Divide5'
   *  Product: '<S481>/Divide1'
   *  Product: '<S481>/Divide2'
   *  Sum: '<S455>/Add'
   *  Sum: '<S478>/Add'
   *  Sum: '<S481>/Add'
   *  Trigonometry: '<S478>/Trigonometric Function'
   *  Trigonometry: '<S478>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_h == 1) {
    /* Gain: '<S481>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_o * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Axb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq *
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_lx *
                EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S455>/Manual Switch' */

  /* Sum: '<S455>/Add1' incorporates:
   *  Constant: '<S455>/Constant'
   *  Product: '<S455>/Divide2'
   *  Product: '<S455>/Divide3'
   *  Product: '<S455>/Divide4'
   *  Trigonometry: '<S455>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S457>/Divide3' */
  rtb_Divide3_ob = rtb_throttle_cmd * rtb_Axb;

  /* ManualSwitch: '<S458>/Manual Switch' incorporates:
   *  Constant: '<S458>/Constant1'
   *  Constant: '<S463>/Constant'
   *  Constant: '<S471>/Constant'
   *  Constant: '<S471>/Constant1'
   *  Constant: '<S471>/Constant10'
   *  Constant: '<S471>/Constant11'
   *  Constant: '<S471>/Constant12'
   *  Constant: '<S471>/Constant2'
   *  Constant: '<S471>/Constant3'
   *  Constant: '<S471>/Constant4'
   *  Constant: '<S471>/Constant5'
   *  Constant: '<S471>/Constant6'
   *  Constant: '<S471>/Constant8'
   *  Product: '<S458>/Divide'
   *  Product: '<S458>/Divide5'
   *  Product: '<S471>/Divide1'
   *  Product: '<S471>/Divide3'
   *  Product: '<S471>/Divide4'
   *  Product: '<S471>/Divide5'
   *  Product: '<S471>/Divide6'
   *  Sum: '<S471>/Add'
   *  Sum: '<S471>/Add1'
   *  Sum: '<S471>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_hl == 1) {
    rtb_rudder_cmd = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim)
                         * EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) /
                         EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cyb *
                         EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim)
                        * EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) /
                        EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cyda *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cydr *
                      rtb_Add1_nj) * (rtb_Divide4_lx * EKF_IFS_2_P.S) /
      (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S458>/Manual Switch' */

  /* Sum: '<S458>/Add1' incorporates:
   *  Constant: '<S458>/Constant'
   *  Product: '<S458>/Divide2'
   *  Product: '<S458>/Divide3'
   *  Product: '<S458>/Divide4'
   *  Trigonometry: '<S458>/Trigonometric Function'
   *  Trigonometry: '<S458>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8 -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_throttle_cmd) +
    sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f
    [8]) * EKF_IFS_2_P.g;

  /* Product: '<S457>/Divide4' */
  rtb_Divide4_mdl = rtb_elevator_cmd * rtb_rudder_cmd;

  /* ManualSwitch: '<S460>/Manual Switch' incorporates:
   *  Constant: '<S460>/Constant1'
   *  Constant: '<S463>/Constant'
   *  Product: '<S460>/Divide'
   *  Product: '<S460>/Divide5'
   *  Product: '<S480>/Divide1'
   *  Product: '<S480>/Divide6'
   *  Sum: '<S480>/Add2'
   *  Trigonometry: '<S480>/Trigonometric Function4'
   *  Trigonometry: '<S480>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_n == 1) {
    rtb_Ayb = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) - cos
               (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_lx * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S460>/Manual Switch' */

  /* Sum: '<S460>/Add1' incorporates:
   *  Constant: '<S460>/Constant'
   *  Product: '<S460>/Divide2'
   *  Product: '<S460>/Divide3'
   *  Product: '<S460>/Divide4'
   *  Trigonometry: '<S460>/Trigonometric Function'
   *  Trigonometry: '<S460>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_elevator_cmd) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S457>/Divide5' */
  rtb_Divide5_mg = rtb_Sum8 * rtb_Ayb;

  /* Product: '<S461>/Divide' incorporates:
   *  Math: '<S461>/Math Function'
   *  Math: '<S461>/Math Function1'
   *  Product: '<S461>/Divide3'
   *  Product: '<S461>/Divide4'
   *  Sum: '<S461>/Add'
   *  Sum: '<S461>/Add1'
   */
  rtb_Divide_e4 = (rtb_throttle_cmd * rtb_Ayb - rtb_Sum8 * rtb_Axb) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8);

  /* Product: '<S462>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_jc = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_rudder_cmd;

  /* Product: '<S462>/Divide4' incorporates:
   *  Product: '<S462>/Divide1'
   *  Product: '<S462>/Divide2'
   *  Product: '<S462>/Divide5'
   *  Product: '<S462>/Divide6'
   *  Sum: '<S462>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_gi = ((rtb_throttle_cmd * rtb_Axb + rtb_elevator_cmd *
                     rtb_rudder_cmd) + rtb_Sum8 * rtb_Ayb) /
    EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_elevator_cmd;

  /* Math: '<S462>/Math Function' */
  rtb_MathFunction_bbq = rtb_throttle_cmd * rtb_throttle_cmd;

  /* Math: '<S462>/Math Function1' */
  rtb_MathFunction1_ea = rtb_Sum8 * rtb_Sum8;

  /* Sum: '<S491>/Add' incorporates:
   *  Constant: '<S491>/Ixx1'
   *  Constant: '<S491>/Ixz1'
   *  Constant: '<S491>/Izz1'
   *  Math: '<S491>/Math Function'
   *  Product: '<S491>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S483>/Divide4' incorporates:
   *  Constant: '<S483>/Ixx'
   *  Constant: '<S483>/Ixz'
   *  Constant: '<S483>/Iyy'
   *  Constant: '<S483>/Izz'
   *  Product: '<S483>/Divide3'
   *  Sum: '<S483>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S450>/Add1' incorporates:
   *  Constant: '<S482>/Ixz'
   *  Constant: '<S482>/Iyy'
   *  Constant: '<S482>/Izz'
   *  Math: '<S482>/Math Function'
   *  Product: '<S450>/Divide2'
   *  Product: '<S450>/Divide3'
   *  Product: '<S482>/Divide3'
   *  Product: '<S482>/Divide4'
   *  Sum: '<S482>/Add'
   *  Sum: '<S482>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_b0 = ((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* Sum: '<S473>/Add' incorporates:
   *  Constant: '<S473>/Constant10'
   *  Constant: '<S473>/Constant11'
   *  Constant: '<S473>/Constant12'
   *  Constant: '<S473>/Constant13'
   *  Constant: '<S473>/Constant14'
   *  Constant: '<S473>/Constant15'
   *  Constant: '<S473>/Constant5'
   *  Constant: '<S473>/Constant6'
   *  Constant: '<S473>/Constant7'
   *  Constant: '<S473>/Constant8'
   *  Constant: '<S473>/Constant9'
   *  Product: '<S473>/Divide3'
   *  Product: '<S473>/Divide4'
   *  Product: '<S473>/Divide5'
   *  Product: '<S473>/Divide6'
   *  Product: '<S473>/Divide7'
   *  Sum: '<S473>/Add1'
   *  Sum: '<S473>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
               EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
               EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
              (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
              EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
             EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * rtb_Add1_nj;

  /* Sum: '<S477>/Add' incorporates:
   *  Constant: '<S477>/Constant'
   *  Constant: '<S477>/Constant10'
   *  Constant: '<S477>/Constant11'
   *  Constant: '<S477>/Constant12'
   *  Constant: '<S477>/Constant13'
   *  Constant: '<S477>/Constant14'
   *  Constant: '<S477>/Constant15'
   *  Constant: '<S477>/Constant5'
   *  Constant: '<S477>/Constant6'
   *  Constant: '<S477>/Constant8'
   *  Constant: '<S477>/Constant9'
   *  Product: '<S477>/Divide3'
   *  Product: '<S477>/Divide4'
   *  Product: '<S477>/Divide5'
   *  Product: '<S477>/Divide6'
   *  Product: '<S477>/Divide7'
   *  Sum: '<S477>/Add1'
   *  Sum: '<S477>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * rtb_Add1_nj;

  /* Sum: '<S472>/Add' incorporates:
   *  Product: '<S472>/Divide3'
   *  Product: '<S472>/Divide5'
   *  Trigonometry: '<S472>/Trigonometric Function'
   *  Trigonometry: '<S472>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Azb * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Product: '<S485>/Divide4' incorporates:
   *  Constant: '<S485>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S476>/Add2' incorporates:
   *  Product: '<S476>/Divide1'
   *  Product: '<S476>/Divide6'
   *  Trigonometry: '<S476>/Trigonometric Function4'
   *  Trigonometry: '<S476>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = rtb_Azb * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Sum: '<S450>/Add' incorporates:
   *  Constant: '<S484>/Izz'
   *  Product: '<S450>/Divide'
   *  Product: '<S450>/Divide4'
   *  Product: '<S484>/Divide4'
   */
  rtb_Add_kw = EKF_IFS_2_P.IzzB / rtb_rudder_cmd * rtb_Add2_c5 + rtb_Divide4_jaz
    * rtb_Azb;

  /* Product: '<S452>/Divide' incorporates:
   *  Constant: '<S475>/Constant'
   *  Constant: '<S475>/Constant1'
   *  Constant: '<S475>/Constant11'
   *  Constant: '<S475>/Constant12'
   *  Constant: '<S475>/Constant13'
   *  Constant: '<S475>/Constant14'
   *  Constant: '<S475>/Constant2'
   *  Constant: '<S475>/Constant3'
   *  Constant: '<S475>/Constant4'
   *  Constant: '<S475>/Constant5'
   *  Constant: '<S475>/Constant6'
   *  Constant: '<S475>/Constant7'
   *  Constant: '<S475>/Constant8'
   *  Constant: '<S475>/Constant9'
   *  Constant: '<S488>/Ixz'
   *  Constant: '<S488>/Iyy'
   *  Gain: '<S475>/Gain1'
   *  Gain: '<S475>/Gain2'
   *  Product: '<S475>/Divide1'
   *  Product: '<S475>/Divide2'
   *  Product: '<S475>/Divide3'
   *  Product: '<S475>/Divide4'
   *  Product: '<S475>/Divide5'
   *  Product: '<S475>/Divide6'
   *  Product: '<S488>/Divide4'
   *  Sum: '<S475>/Add'
   *  Sum: '<S475>/Add1'
   *  Sum: '<S475>/Add2'
   *  Sum: '<S475>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S461>/Unit Delay'
   */
  rtb_Divide_p = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                      EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                      EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                     EKF_IFS_2_DW.UnitDelay_DSTATE_j * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim *
                    (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.Cmde *
                   EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1 *
                  EKF_IFS_2_P.Gain2_Gain_n * EKF_IFS_2_P.Gain1_Gain_d) *
    (EKF_IFS_2_P.Ixz_Value_au / EKF_IFS_2_P.IyyB);

  /* Sum: '<S453>/Add1' incorporates:
   *  Constant: '<S489>/Ixx'
   *  Constant: '<S489>/Ixx1'
   *  Constant: '<S489>/Ixz'
   *  Constant: '<S489>/Iyy'
   *  Math: '<S489>/Math Function'
   *  Product: '<S453>/Divide2'
   *  Product: '<S453>/Divide3'
   *  Product: '<S489>/Divide3'
   *  Product: '<S489>/Divide4'
   *  Sum: '<S489>/Add'
   *  Sum: '<S489>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_br4 = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
                  EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S453>/Add' incorporates:
   *  Constant: '<S490>/Ixx'
   *  Product: '<S453>/Divide'
   *  Product: '<S453>/Divide4'
   *  Product: '<S490>/Divide4'
   */
  rtb_Add_fs = EKF_IFS_2_P.IxxB / rtb_rudder_cmd * rtb_Azb + rtb_Divide4_jaz *
    rtb_Add2_c5;

  /* Sum: '<S159>/Add1' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f
    [4];

  /* Product: '<S544>/Divide2' incorporates:
   *  Trigonometry: '<S544>/Trigonometric Function'
   *  Trigonometry: '<S544>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = rtb_throttle_cmd * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) *
    cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S546>/Divide2' incorporates:
   *  Trigonometry: '<S546>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = rtb_throttle_cmd * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S549>/Divide2' incorporates:
   *  Trigonometry: '<S549>/Trigonometric Function'
   *  Trigonometry: '<S549>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb = rtb_throttle_cmd * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S541>/Divide4' incorporates:
   *  Constant: '<S541>/Constant'
   *  Constant: '<S541>/Constant1'
   *  Math: '<S541>/Math Function'
   */
  rtb_Divide4_dh = EKF_IFS_2_P.Constant_Value_is * EKF_IFS_2_P.rho_o *
    (rtb_throttle_cmd * rtb_throttle_cmd);

  /* Sum: '<S560>/Add' incorporates:
   *  Constant: '<S560>/Constant'
   *  Constant: '<S560>/Constant1'
   *  Constant: '<S560>/Constant10'
   *  Constant: '<S560>/Constant11'
   *  Constant: '<S560>/Constant12'
   *  Constant: '<S560>/Constant13'
   *  Constant: '<S560>/Constant14'
   *  Constant: '<S560>/Constant15'
   *  Constant: '<S560>/Constant2'
   *  Constant: '<S560>/Constant3'
   *  Constant: '<S560>/Constant4'
   *  Constant: '<S560>/Constant5'
   *  Constant: '<S560>/Constant6'
   *  Constant: '<S560>/Constant7'
   *  Constant: '<S560>/Constant8'
   *  Constant: '<S560>/Constant9'
   *  Gain: '<S560>/Gain1'
   *  Gain: '<S560>/Gain2'
   *  Gain: '<S560>/Gain3'
   *  Product: '<S560>/Divide1'
   *  Product: '<S560>/Divide2'
   *  Product: '<S560>/Divide3'
   *  Product: '<S560>/Divide4'
   *  Product: '<S560>/Divide5'
   *  Product: '<S560>/Divide6'
   *  Product: '<S560>/Divide7'
   *  Sum: '<S560>/Add1'
   *  Sum: '<S560>/Add2'
   *  Sum: '<S560>/Add3'
   *  Sum: '<S560>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S551>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_p * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_elevator_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_elevator_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_bi * EKF_IFS_2_P.Gain1_Gain_a) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_d;

  /* ManualSwitch: '<S559>/Manual Switch' incorporates:
   *  Constant: '<S559>/AR'
   *  Constant: '<S559>/Constant15'
   *  Constant: '<S559>/Constant16'
   *  Constant: '<S559>/Constant17'
   *  Constant: '<S559>/Constant18'
   *  Constant: '<S559>/e'
   *  Math: '<S559>/Math Function'
   *  Product: '<S559>/Divide8'
   *  Product: '<S559>/Divide9'
   *  Sum: '<S559>/Add5'
   *  Sum: '<S559>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_e4 == 1) {
    rtb_rudder_cmd = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_rudder_cmd = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_i5
      / (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_e +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S559>/Manual Switch' */

  /* Sum: '<S559>/Add' incorporates:
   *  Constant: '<S559>/Constant1'
   *  Constant: '<S559>/Constant10'
   *  Constant: '<S559>/Constant11'
   *  Constant: '<S559>/Constant12'
   *  Constant: '<S559>/Constant13'
   *  Constant: '<S559>/Constant14'
   *  Constant: '<S559>/Constant2'
   *  Constant: '<S559>/Constant3'
   *  Constant: '<S559>/Constant4'
   *  Constant: '<S559>/Constant6'
   *  Constant: '<S559>/Constant7'
   *  Constant: '<S559>/Constant8'
   *  Constant: '<S559>/Constant9'
   *  Gain: '<S559>/Gain1'
   *  Gain: '<S559>/Gain2'
   *  Gain: '<S559>/Gain3'
   *  Product: '<S559>/Divide1'
   *  Product: '<S559>/Divide2'
   *  Product: '<S559>/Divide3'
   *  Product: '<S559>/Divide5'
   *  Product: '<S559>/Divide6'
   *  Product: '<S559>/Divide7'
   *  Sum: '<S559>/Add1'
   *  Sum: '<S559>/Add2'
   *  Sum: '<S559>/Add3'
   *  Sum: '<S559>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S551>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_rudder_cmd) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_p * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_elevator_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_elevator_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_pm * EKF_IFS_2_P.Gain1_Gain_e0) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_m;

  /* ManualSwitch: '<S545>/Manual Switch' incorporates:
   *  Constant: '<S545>/Constant1'
   *  Constant: '<S553>/Constant'
   *  Constant: '<S571>/Constant'
   *  Constant: '<S571>/Constant1'
   *  Constant: '<S571>/Constant2'
   *  Math: '<S571>/Math Function'
   *  Product: '<S545>/Divide'
   *  Product: '<S545>/Divide5'
   *  Product: '<S568>/Divide3'
   *  Product: '<S568>/Divide5'
   *  Product: '<S571>/Divide1'
   *  Product: '<S571>/Divide2'
   *  Sum: '<S545>/Add'
   *  Sum: '<S568>/Add'
   *  Sum: '<S571>/Add'
   *  Trigonometry: '<S568>/Trigonometric Function'
   *  Trigonometry: '<S568>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_h0 == 1) {
    /* Gain: '<S571>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_f * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_rudder_cmd = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 +
                        EKF_IFS_2_P.xT1 * rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz -
      rtb_Add_iq * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_dh *
      EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S545>/Manual Switch' */

  /* Sum: '<S545>/Add1' incorporates:
   *  Constant: '<S545>/Constant'
   *  Product: '<S545>/Divide2'
   *  Product: '<S545>/Divide3'
   *  Product: '<S545>/Divide4'
   *  Trigonometry: '<S545>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_Sum8 -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Axb) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* ManualSwitch: '<S548>/Manual Switch' incorporates:
   *  Constant: '<S548>/Constant1'
   *  Constant: '<S553>/Constant'
   *  Constant: '<S561>/Constant'
   *  Constant: '<S561>/Constant1'
   *  Constant: '<S561>/Constant10'
   *  Constant: '<S561>/Constant11'
   *  Constant: '<S561>/Constant12'
   *  Constant: '<S561>/Constant2'
   *  Constant: '<S561>/Constant3'
   *  Constant: '<S561>/Constant4'
   *  Constant: '<S561>/Constant5'
   *  Constant: '<S561>/Constant6'
   *  Constant: '<S561>/Constant8'
   *  Product: '<S548>/Divide'
   *  Product: '<S548>/Divide5'
   *  Product: '<S561>/Divide1'
   *  Product: '<S561>/Divide3'
   *  Product: '<S561>/Divide4'
   *  Product: '<S561>/Divide5'
   *  Product: '<S561>/Divide6'
   *  Sum: '<S561>/Add'
   *  Sum: '<S561>/Add1'
   *  Sum: '<S561>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_pk == 1) {
    rtb_Ayb = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                  EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                  EKF_IFS_2_P.Cyb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                 EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                EKF_IFS_2_P.Cyda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
               EKF_IFS_2_P.Cydr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) *
      (rtb_Divide4_dh * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S548>/Manual Switch' */

  /* Sum: '<S548>/Add1' incorporates:
   *  Constant: '<S548>/Constant'
   *  Product: '<S548>/Divide2'
   *  Product: '<S548>/Divide3'
   *  Product: '<S548>/Divide4'
   *  Trigonometry: '<S548>/Trigonometric Function'
   *  Trigonometry: '<S548>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Axb -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd) + sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* ManualSwitch: '<S550>/Manual Switch' incorporates:
   *  Constant: '<S550>/Constant1'
   *  Constant: '<S553>/Constant'
   *  Product: '<S550>/Divide'
   *  Product: '<S550>/Divide5'
   *  Product: '<S570>/Divide1'
   *  Product: '<S570>/Divide6'
   *  Sum: '<S570>/Add2'
   *  Trigonometry: '<S570>/Trigonometric Function4'
   *  Trigonometry: '<S570>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_f == 1) {
    rtb_Add2_jk = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) -
                   cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_dh * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Add2_jk = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S550>/Manual Switch' */

  /* Sum: '<S550>/Add1' incorporates:
   *  Constant: '<S550>/Constant'
   *  Product: '<S550>/Divide2'
   *  Product: '<S550>/Divide3'
   *  Product: '<S550>/Divide4'
   *  Trigonometry: '<S550>/Trigonometric Function'
   *  Trigonometry: '<S550>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_elevator_cmd -
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S547>/Divide' incorporates:
   *  Product: '<S547>/Divide3'
   *  Product: '<S547>/Divide4'
   *  Product: '<S547>/Divide5'
   *  Sum: '<S547>/Add'
   */
  rtb_Azb = ((rtb_elevator_cmd * rtb_rudder_cmd + rtb_Sum8 * rtb_Ayb) + rtb_Axb *
             rtb_Add2_jk) / rtb_throttle_cmd;

  /* Product: '<S551>/Divide' incorporates:
   *  Math: '<S551>/Math Function'
   *  Math: '<S551>/Math Function1'
   *  Product: '<S551>/Divide3'
   *  Product: '<S551>/Divide4'
   *  Sum: '<S551>/Add'
   *  Sum: '<S551>/Add1'
   */
  rtb_Divide_j = (rtb_elevator_cmd * rtb_Add2_jk - rtb_Axb * rtb_rudder_cmd) /
    (rtb_elevator_cmd * rtb_elevator_cmd + rtb_Axb * rtb_Axb);

  /* Product: '<S552>/Divide3' */
  rtb_Add_lzz = rtb_throttle_cmd * rtb_Ayb;

  /* Product: '<S552>/Divide4' incorporates:
   *  Product: '<S552>/Divide1'
   *  Product: '<S552>/Divide2'
   *  Product: '<S552>/Divide5'
   *  Product: '<S552>/Divide6'
   *  Sum: '<S552>/Add2'
   */
  rtb_Gain_cl = ((rtb_elevator_cmd * rtb_rudder_cmd + rtb_Sum8 * rtb_Ayb) +
                 rtb_Axb * rtb_Add2_jk) / rtb_throttle_cmd * rtb_Sum8;

  /* Sum: '<S581>/Add' incorporates:
   *  Constant: '<S581>/Ixx1'
   *  Constant: '<S581>/Ixz1'
   *  Constant: '<S581>/Izz1'
   *  Math: '<S581>/Math Function'
   *  Product: '<S581>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S573>/Divide4' incorporates:
   *  Constant: '<S573>/Ixx'
   *  Constant: '<S573>/Ixz'
   *  Constant: '<S573>/Iyy'
   *  Constant: '<S573>/Izz'
   *  Product: '<S573>/Divide3'
   *  Sum: '<S573>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S563>/Add' incorporates:
   *  Constant: '<S563>/Constant10'
   *  Constant: '<S563>/Constant11'
   *  Constant: '<S563>/Constant12'
   *  Constant: '<S563>/Constant13'
   *  Constant: '<S563>/Constant14'
   *  Constant: '<S563>/Constant15'
   *  Constant: '<S563>/Constant5'
   *  Constant: '<S563>/Constant6'
   *  Constant: '<S563>/Constant7'
   *  Constant: '<S563>/Constant8'
   *  Constant: '<S563>/Constant9'
   *  Product: '<S563>/Divide3'
   *  Product: '<S563>/Divide4'
   *  Product: '<S563>/Divide5'
   *  Product: '<S563>/Divide6'
   *  Product: '<S563>/Divide7'
   *  Sum: '<S563>/Add1'
   *  Sum: '<S563>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                   EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                   EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                  (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                  EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                 EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S567>/Add' incorporates:
   *  Constant: '<S567>/Constant'
   *  Constant: '<S567>/Constant10'
   *  Constant: '<S567>/Constant11'
   *  Constant: '<S567>/Constant12'
   *  Constant: '<S567>/Constant13'
   *  Constant: '<S567>/Constant14'
   *  Constant: '<S567>/Constant15'
   *  Constant: '<S567>/Constant5'
   *  Constant: '<S567>/Constant6'
   *  Constant: '<S567>/Constant8'
   *  Constant: '<S567>/Constant9'
   *  Product: '<S567>/Divide3'
   *  Product: '<S567>/Divide4'
   *  Product: '<S567>/Divide5'
   *  Product: '<S567>/Divide6'
   *  Product: '<S567>/Divide7'
   *  Sum: '<S567>/Add1'
   *  Sum: '<S567>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S562>/Add' incorporates:
   *  Product: '<S562>/Divide3'
   *  Product: '<S562>/Divide5'
   *  Trigonometry: '<S562>/Trigonometric Function'
   *  Trigonometry: '<S562>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Add2_jk * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Product: '<S575>/Divide4' incorporates:
   *  Constant: '<S575>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S566>/Add2' incorporates:
   *  Product: '<S566>/Divide1'
   *  Product: '<S566>/Divide6'
   *  Trigonometry: '<S566>/Trigonometric Function4'
   *  Trigonometry: '<S566>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = rtb_Add2_jk * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Saturate: '<S537>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Product: '<S147>/Divide4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S537>/Gain'
   *  Gain: '<S537>/Gain1'
   *  Saturate: '<S537>/Throttle Limiter'
   *  Sum: '<S147>/Sum4'
   *  Sum: '<S537>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_bpl[0] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) / EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S537>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Product: '<S147>/Divide4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S537>/Gain2'
   *  Gain: '<S537>/Gain3'
   *  Saturate: '<S537>/Elevator Limiter'
   *  Sum: '<S147>/Sum4'
   *  Sum: '<S537>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_bpl[1] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S537>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Product: '<S147>/Divide4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S537>/Gain4'
   *  Gain: '<S537>/Gain5'
   *  Saturate: '<S537>/Aileron Limiter'
   *  Sum: '<S147>/Sum4'
   *  Sum: '<S537>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_bpl[2] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S537>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Product: '<S147>/Divide4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S537>/Gain6'
   *  Gain: '<S537>/Gain7'
   *  Math: '<S552>/Math Function'
   *  Math: '<S552>/Math Function1'
   *  Product: '<S552>/Divide'
   *  Saturate: '<S537>/Rudder Limiter'
   *  Sum: '<S147>/Sum4'
   *  Sum: '<S537>/Add3'
   *  Sum: '<S552>/Add'
   *  Sum: '<S552>/Add1'
   *  Trigonometry: '<S552>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_bpl[3] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[4] = (rtb_Azb - rtb_Divide_bi) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[5] = (rtb_Divide_j - rtb_Divide) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[6] = ((rtb_Add_lzz - rtb_Gain_cl) / (rtb_elevator_cmd *
    rtb_elevator_cmd + rtb_Axb * rtb_Axb) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6])
                        - rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i;

  /* Trigonometry: '<S555>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S555>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_h1) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_h1;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_c) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_c;
    }
  }

  /* Product: '<S147>/Divide4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S540>/Constant1'
   *  Constant: '<S540>/Constant2'
   *  Constant: '<S542>/Constant1'
   *  Constant: '<S542>/Constant2'
   *  Constant: '<S543>/Constant1'
   *  Constant: '<S543>/Constant2'
   *  Constant: '<S556>/Constant'
   *  Constant: '<S557>/Constant'
   *  Constant: '<S565>/Constant'
   *  Constant: '<S565>/Constant1'
   *  Constant: '<S565>/Constant11'
   *  Constant: '<S565>/Constant12'
   *  Constant: '<S565>/Constant13'
   *  Constant: '<S565>/Constant14'
   *  Constant: '<S565>/Constant2'
   *  Constant: '<S565>/Constant3'
   *  Constant: '<S565>/Constant4'
   *  Constant: '<S565>/Constant5'
   *  Constant: '<S565>/Constant6'
   *  Constant: '<S565>/Constant7'
   *  Constant: '<S565>/Constant8'
   *  Constant: '<S565>/Constant9'
   *  Constant: '<S572>/Ixz'
   *  Constant: '<S572>/Iyy'
   *  Constant: '<S572>/Izz'
   *  Constant: '<S574>/Izz'
   *  Constant: '<S576>/Ixx'
   *  Constant: '<S576>/Iyy'
   *  Constant: '<S576>/Izz'
   *  Constant: '<S577>/Ixz'
   *  Constant: '<S577>/Iyy'
   *  Constant: '<S578>/Ixz'
   *  Constant: '<S578>/Iyy'
   *  Constant: '<S579>/Ixx'
   *  Constant: '<S579>/Ixx1'
   *  Constant: '<S579>/Ixz'
   *  Constant: '<S579>/Iyy'
   *  Constant: '<S580>/Ixx'
   *  Gain: '<S565>/Gain1'
   *  Gain: '<S565>/Gain2'
   *  Math: '<S542>/Math Function'
   *  Math: '<S542>/Math Function1'
   *  Math: '<S572>/Math Function'
   *  Math: '<S579>/Math Function'
   *  Product: '<S540>/Divide'
   *  Product: '<S540>/Divide1'
   *  Product: '<S540>/Divide2'
   *  Product: '<S540>/Divide3'
   *  Product: '<S540>/Divide4'
   *  Product: '<S540>/Divide5'
   *  Product: '<S540>/Divide6'
   *  Product: '<S542>/Divide'
   *  Product: '<S542>/Divide2'
   *  Product: '<S542>/Divide3'
   *  Product: '<S542>/Divide5'
   *  Product: '<S542>/Divide6'
   *  Product: '<S543>/Divide'
   *  Product: '<S543>/Divide1'
   *  Product: '<S543>/Divide2'
   *  Product: '<S543>/Divide3'
   *  Product: '<S543>/Divide4'
   *  Product: '<S543>/Divide5'
   *  Product: '<S543>/Divide6'
   *  Product: '<S555>/Divide1'
   *  Product: '<S555>/Divide2'
   *  Product: '<S555>/Divide4'
   *  Product: '<S558>/Divide2'
   *  Product: '<S558>/Divide4'
   *  Product: '<S565>/Divide1'
   *  Product: '<S565>/Divide2'
   *  Product: '<S565>/Divide3'
   *  Product: '<S565>/Divide4'
   *  Product: '<S565>/Divide5'
   *  Product: '<S565>/Divide6'
   *  Product: '<S572>/Divide3'
   *  Product: '<S572>/Divide4'
   *  Product: '<S574>/Divide4'
   *  Product: '<S576>/Divide4'
   *  Product: '<S577>/Divide4'
   *  Product: '<S578>/Divide4'
   *  Product: '<S579>/Divide3'
   *  Product: '<S579>/Divide4'
   *  Product: '<S580>/Divide4'
   *  Saturate: '<S555>/Saturation'
   *  Sum: '<S147>/Sum4'
   *  Sum: '<S540>/Add'
   *  Sum: '<S540>/Add1'
   *  Sum: '<S540>/Add2'
   *  Sum: '<S542>/Add1'
   *  Sum: '<S542>/Add3'
   *  Sum: '<S543>/Add'
   *  Sum: '<S543>/Add1'
   *  Sum: '<S543>/Add2'
   *  Sum: '<S555>/Add'
   *  Sum: '<S555>/Add1'
   *  Sum: '<S558>/Add'
   *  Sum: '<S565>/Add'
   *  Sum: '<S565>/Add1'
   *  Sum: '<S565>/Add2'
   *  Sum: '<S565>/Add3'
   *  Sum: '<S572>/Add'
   *  Sum: '<S572>/Add1'
   *  Sum: '<S576>/Add'
   *  Sum: '<S579>/Add'
   *  Sum: '<S579>/Add1'
   *  Trigonometry: '<S555>/Trigonometric Function1'
   *  Trigonometry: '<S555>/Trigonometric Function2'
   *  Trigonometry: '<S558>/Trigonometric Function1'
   *  Trigonometry: '<S558>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S551>/Unit Delay'
   */
  rtb_Divide4_bpl[7] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7])
    * EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0 +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[8] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7])
    * EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[9] = (((((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) * EKF_IFS_2_DW.x_est_00_DSTATE_f[10] +
    (EKF_IFS_2_P.IzzB / rtb_rudder_cmd * rtb_Add2_c5 + rtb_Divide4_jaz *
     rtb_Add2_jk) * (rtb_Divide4_dh * EKF_IFS_2_P.S * EKF_IFS_2_P.b)) -
                        rtb_Add2_lg4) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[10] = ((((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] -
    EKF_IFS_2_P.Qtrim) * EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
    EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
    EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot * EKF_IFS_2_DW.UnitDelay_DSTATE_p *
    (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu /
    EKF_IFS_2_P.Utrim * (rtb_elevator_cmd - EKF_IFS_2_P.Utrim)) +
    EKF_IFS_2_P.Cmde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 /
    EKF_IFS_2_P.Utrim * (rtb_elevator_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1
    * EKF_IFS_2_P.Gain2_Gain_pv * EKF_IFS_2_P.Gain1_Gain_kb) *
    (EKF_IFS_2_P.Ixz_Value_l / EKF_IFS_2_P.IyyB) * (rtb_Divide4_dh *
    EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar) + ((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB)))
    - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[11] = (((((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) *
    EKF_IFS_2_P.IxxB + EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * EKF_IFS_2_DW.x_est_00_DSTATE_f[10] +
    (EKF_IFS_2_P.IxxB / rtb_rudder_cmd * rtb_Add2_jk + rtb_Divide4_jaz *
     rtb_Add2_c5) * (rtb_Divide4_dh * EKF_IFS_2_P.S * EKF_IFS_2_P.b)) -
    rtb_Divide4_in) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[12] = (EKF_IFS_2_P.Constant_Value_iu -
    EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i;
  rtb_Divide4_bpl[13] = (EKF_IFS_2_P.Constant_Value_mp -
    EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i;

  /* Sum: '<S160>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_dh = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[5];

  /* Product: '<S589>/Divide2' incorporates:
   *  Trigonometry: '<S589>/Trigonometric Function'
   *  Trigonometry: '<S589>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos(rtb_Divide4_dh) *
    cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S591>/Divide2' incorporates:
   *  Trigonometry: '<S591>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S594>/Divide2' incorporates:
   *  Trigonometry: '<S594>/Trigonometric Function'
   *  Trigonometry: '<S594>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin(rtb_Divide4_dh) * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S586>/Divide4' incorporates:
   *  Constant: '<S586>/Constant'
   *  Constant: '<S586>/Constant1'
   *  Math: '<S586>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_eb = EKF_IFS_2_P.Constant_Value_ih * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S605>/Add' incorporates:
   *  Constant: '<S605>/Constant'
   *  Constant: '<S605>/Constant1'
   *  Constant: '<S605>/Constant10'
   *  Constant: '<S605>/Constant11'
   *  Constant: '<S605>/Constant12'
   *  Constant: '<S605>/Constant13'
   *  Constant: '<S605>/Constant14'
   *  Constant: '<S605>/Constant15'
   *  Constant: '<S605>/Constant2'
   *  Constant: '<S605>/Constant3'
   *  Constant: '<S605>/Constant4'
   *  Constant: '<S605>/Constant5'
   *  Constant: '<S605>/Constant6'
   *  Constant: '<S605>/Constant7'
   *  Constant: '<S605>/Constant8'
   *  Constant: '<S605>/Constant9'
   *  Gain: '<S605>/Gain1'
   *  Gain: '<S605>/Gain2'
   *  Gain: '<S605>/Gain3'
   *  Product: '<S605>/Divide1'
   *  Product: '<S605>/Divide2'
   *  Product: '<S605>/Divide3'
   *  Product: '<S605>/Divide4'
   *  Product: '<S605>/Divide5'
   *  Product: '<S605>/Divide6'
   *  Product: '<S605>/Divide7'
   *  Sum: '<S605>/Add1'
   *  Sum: '<S605>/Add2'
   *  Sum: '<S605>/Add3'
   *  Sum: '<S605>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S596>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa * rtb_Divide4_dh +
    EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot * EKF_IFS_2_DW.UnitDelay_DSTATE_j3 *
                    (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim) +
                   EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim * (rtb_throttle_cmd -
    EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1])
                 + 1.0 / EKF_IFS_2_P.Utrim * (rtb_throttle_cmd -
    EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain2_Gain_k *
                 EKF_IFS_2_P.Gain1_Gain_n) + (rtb_Divide4_dh -
    EKF_IFS_2_P.alphatrim) * EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_av;

  /* ManualSwitch: '<S604>/Manual Switch' incorporates:
   *  Constant: '<S604>/AR'
   *  Constant: '<S604>/Constant15'
   *  Constant: '<S604>/Constant16'
   *  Constant: '<S604>/Constant17'
   *  Constant: '<S604>/Constant18'
   *  Constant: '<S604>/e'
   *  Math: '<S604>/Math Function'
   *  Product: '<S604>/Divide8'
   *  Product: '<S604>/Divide9'
   *  Sum: '<S604>/Add5'
   *  Sum: '<S604>/Add6'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_c == 1) {
    rtb_Axb = EKF_IFS_2_P.CDa * rtb_Divide4_dh + EKF_IFS_2_P.CD0;
  } else {
    rtb_Axb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_er /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_k1 +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S604>/Manual Switch' */

  /* Sum: '<S604>/Add' incorporates:
   *  Constant: '<S604>/Constant1'
   *  Constant: '<S604>/Constant10'
   *  Constant: '<S604>/Constant11'
   *  Constant: '<S604>/Constant12'
   *  Constant: '<S604>/Constant13'
   *  Constant: '<S604>/Constant14'
   *  Constant: '<S604>/Constant2'
   *  Constant: '<S604>/Constant3'
   *  Constant: '<S604>/Constant4'
   *  Constant: '<S604>/Constant6'
   *  Constant: '<S604>/Constant7'
   *  Constant: '<S604>/Constant8'
   *  Constant: '<S604>/Constant9'
   *  Gain: '<S604>/Gain1'
   *  Gain: '<S604>/Gain2'
   *  Gain: '<S604>/Gain3'
   *  Product: '<S604>/Divide1'
   *  Product: '<S604>/Divide2'
   *  Product: '<S604>/Divide3'
   *  Product: '<S604>/Divide5'
   *  Product: '<S604>/Divide6'
   *  Product: '<S604>/Divide7'
   *  Sum: '<S604>/Add1'
   *  Sum: '<S604>/Add2'
   *  Sum: '<S604>/Add3'
   *  Sum: '<S604>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S596>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Axb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_j3 * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_oc * EKF_IFS_2_P.Gain1_Gain_mvu) -
    (rtb_Divide4_dh - EKF_IFS_2_P.alphatrim) * EKF_IFS_2_P.CL1 *
    EKF_IFS_2_P.Gain3_Gain_p;

  /* ManualSwitch: '<S590>/Manual Switch' incorporates:
   *  Constant: '<S590>/Constant1'
   *  Constant: '<S598>/Constant'
   *  Constant: '<S616>/Constant'
   *  Constant: '<S616>/Constant1'
   *  Constant: '<S616>/Constant2'
   *  Math: '<S616>/Math Function'
   *  Product: '<S590>/Divide'
   *  Product: '<S590>/Divide5'
   *  Product: '<S613>/Divide3'
   *  Product: '<S613>/Divide5'
   *  Product: '<S616>/Divide1'
   *  Product: '<S616>/Divide2'
   *  Sum: '<S590>/Add'
   *  Sum: '<S613>/Add'
   *  Sum: '<S616>/Add'
   *  Trigonometry: '<S613>/Trigonometric Function'
   *  Trigonometry: '<S613>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_lc == 1) {
    /* Gain: '<S616>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_fu * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Axb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin(rtb_Divide4_dh) *
                rtb_Add_lzz - rtb_Add_iq * cos(rtb_Divide4_dh)) *
               (rtb_Divide4_eb * EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight /
      EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S590>/Manual Switch' */

  /* Sum: '<S590>/Add1' incorporates:
   *  Constant: '<S590>/Constant'
   *  Product: '<S590>/Divide2'
   *  Product: '<S590>/Divide3'
   *  Product: '<S590>/Divide4'
   *  Trigonometry: '<S590>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S592>/Divide3' */
  rtb_Divide3_cas = rtb_throttle_cmd * rtb_Axb;

  /* ManualSwitch: '<S593>/Manual Switch' incorporates:
   *  Constant: '<S593>/Constant1'
   *  Constant: '<S598>/Constant'
   *  Constant: '<S606>/Constant'
   *  Constant: '<S606>/Constant1'
   *  Constant: '<S606>/Constant10'
   *  Constant: '<S606>/Constant11'
   *  Constant: '<S606>/Constant12'
   *  Constant: '<S606>/Constant2'
   *  Constant: '<S606>/Constant3'
   *  Constant: '<S606>/Constant4'
   *  Constant: '<S606>/Constant5'
   *  Constant: '<S606>/Constant6'
   *  Constant: '<S606>/Constant8'
   *  Product: '<S593>/Divide'
   *  Product: '<S593>/Divide5'
   *  Product: '<S606>/Divide1'
   *  Product: '<S606>/Divide3'
   *  Product: '<S606>/Divide4'
   *  Product: '<S606>/Divide5'
   *  Product: '<S606>/Divide6'
   *  Sum: '<S606>/Add'
   *  Sum: '<S606>/Add1'
   *  Sum: '<S606>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_j4 == 1) {
    rtb_rudder_cmd = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim)
                         * EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) /
                         EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cyb *
                         EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim)
                        * EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) /
                        EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cyda *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cydr *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) * (rtb_Divide4_eb *
      EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S593>/Manual Switch' */

  /* Sum: '<S593>/Add1' incorporates:
   *  Constant: '<S593>/Constant'
   *  Product: '<S593>/Divide2'
   *  Product: '<S593>/Divide3'
   *  Product: '<S593>/Divide4'
   *  Trigonometry: '<S593>/Trigonometric Function'
   *  Trigonometry: '<S593>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8 -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_throttle_cmd) +
    sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f
    [8]) * EKF_IFS_2_P.g;

  /* Product: '<S592>/Divide4' */
  rtb_Divide4_gka = rtb_elevator_cmd * rtb_rudder_cmd;

  /* ManualSwitch: '<S595>/Manual Switch' incorporates:
   *  Constant: '<S595>/Constant1'
   *  Constant: '<S598>/Constant'
   *  Product: '<S595>/Divide'
   *  Product: '<S595>/Divide5'
   *  Product: '<S615>/Divide1'
   *  Product: '<S615>/Divide6'
   *  Sum: '<S615>/Add2'
   *  Trigonometry: '<S615>/Trigonometric Function4'
   *  Trigonometry: '<S615>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_l2 == 1) {
    rtb_Ayb = ((0.0 - rtb_Add_iq * sin(rtb_Divide4_dh)) - cos(rtb_Divide4_dh) *
               rtb_Add_lzz) * (rtb_Divide4_eb * EKF_IFS_2_P.S) /
      (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S595>/Manual Switch' */

  /* Sum: '<S595>/Add1' incorporates:
   *  Constant: '<S595>/Constant'
   *  Product: '<S595>/Divide2'
   *  Product: '<S595>/Divide3'
   *  Product: '<S595>/Divide4'
   *  Trigonometry: '<S595>/Trigonometric Function'
   *  Trigonometry: '<S595>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_elevator_cmd) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S592>/Divide5' */
  rtb_Divide5_bum = rtb_Sum8 * rtb_Ayb;

  /* Product: '<S596>/Divide' incorporates:
   *  Math: '<S596>/Math Function'
   *  Math: '<S596>/Math Function1'
   *  Product: '<S596>/Divide3'
   *  Product: '<S596>/Divide4'
   *  Sum: '<S596>/Add'
   *  Sum: '<S596>/Add1'
   */
  rtb_Divide_du = (rtb_throttle_cmd * rtb_Ayb - rtb_Sum8 * rtb_Axb) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8);

  /* Product: '<S597>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_eun = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_rudder_cmd;

  /* Product: '<S597>/Divide4' incorporates:
   *  Product: '<S597>/Divide1'
   *  Product: '<S597>/Divide2'
   *  Product: '<S597>/Divide5'
   *  Product: '<S597>/Divide6'
   *  Sum: '<S597>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_mz = ((rtb_throttle_cmd * rtb_Axb + rtb_elevator_cmd *
                     rtb_rudder_cmd) + rtb_Sum8 * rtb_Ayb) /
    EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_elevator_cmd;

  /* Math: '<S597>/Math Function' */
  rtb_MathFunction_dx = rtb_throttle_cmd * rtb_throttle_cmd;

  /* Math: '<S597>/Math Function1' */
  rtb_MathFunction1_jh = rtb_Sum8 * rtb_Sum8;

  /* Sum: '<S626>/Add' incorporates:
   *  Constant: '<S626>/Ixx1'
   *  Constant: '<S626>/Ixz1'
   *  Constant: '<S626>/Izz1'
   *  Math: '<S626>/Math Function'
   *  Product: '<S626>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S618>/Divide4' incorporates:
   *  Constant: '<S618>/Ixx'
   *  Constant: '<S618>/Ixz'
   *  Constant: '<S618>/Iyy'
   *  Constant: '<S618>/Izz'
   *  Product: '<S618>/Divide3'
   *  Sum: '<S618>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S585>/Add1' incorporates:
   *  Constant: '<S617>/Ixz'
   *  Constant: '<S617>/Iyy'
   *  Constant: '<S617>/Izz'
   *  Math: '<S617>/Math Function'
   *  Product: '<S585>/Divide2'
   *  Product: '<S585>/Divide3'
   *  Product: '<S617>/Divide3'
   *  Product: '<S617>/Divide4'
   *  Sum: '<S617>/Add'
   *  Sum: '<S617>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_ev = ((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* Sum: '<S608>/Add' incorporates:
   *  Constant: '<S608>/Constant10'
   *  Constant: '<S608>/Constant11'
   *  Constant: '<S608>/Constant12'
   *  Constant: '<S608>/Constant13'
   *  Constant: '<S608>/Constant14'
   *  Constant: '<S608>/Constant15'
   *  Constant: '<S608>/Constant5'
   *  Constant: '<S608>/Constant6'
   *  Constant: '<S608>/Constant7'
   *  Constant: '<S608>/Constant8'
   *  Constant: '<S608>/Constant9'
   *  Product: '<S608>/Divide3'
   *  Product: '<S608>/Divide4'
   *  Product: '<S608>/Divide5'
   *  Product: '<S608>/Divide6'
   *  Product: '<S608>/Divide7'
   *  Sum: '<S608>/Add1'
   *  Sum: '<S608>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
               EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
               EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
              (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
              EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
             EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S612>/Add' incorporates:
   *  Constant: '<S612>/Constant'
   *  Constant: '<S612>/Constant10'
   *  Constant: '<S612>/Constant11'
   *  Constant: '<S612>/Constant12'
   *  Constant: '<S612>/Constant13'
   *  Constant: '<S612>/Constant14'
   *  Constant: '<S612>/Constant15'
   *  Constant: '<S612>/Constant5'
   *  Constant: '<S612>/Constant6'
   *  Constant: '<S612>/Constant8'
   *  Constant: '<S612>/Constant9'
   *  Product: '<S612>/Divide3'
   *  Product: '<S612>/Divide4'
   *  Product: '<S612>/Divide5'
   *  Product: '<S612>/Divide6'
   *  Product: '<S612>/Divide7'
   *  Sum: '<S612>/Add1'
   *  Sum: '<S612>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S607>/Add' incorporates:
   *  Product: '<S607>/Divide3'
   *  Product: '<S607>/Divide5'
   *  Trigonometry: '<S607>/Trigonometric Function'
   *  Trigonometry: '<S607>/Trigonometric Function3'
   */
  rtb_Add2_c5 = rtb_Azb * cos(rtb_Divide4_dh) - sin(rtb_Divide4_dh) *
    rtb_Divide_niq;

  /* Product: '<S620>/Divide4' incorporates:
   *  Constant: '<S620>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S611>/Add2' incorporates:
   *  Product: '<S611>/Divide1'
   *  Product: '<S611>/Divide6'
   *  Trigonometry: '<S611>/Trigonometric Function4'
   *  Trigonometry: '<S611>/Trigonometric Function5'
   */
  rtb_Azb = rtb_Azb * sin(rtb_Divide4_dh) + cos(rtb_Divide4_dh) * rtb_Divide_niq;

  /* Sum: '<S585>/Add' incorporates:
   *  Constant: '<S619>/Izz'
   *  Product: '<S585>/Divide'
   *  Product: '<S585>/Divide4'
   *  Product: '<S619>/Divide4'
   */
  rtb_Add_he1 = EKF_IFS_2_P.IzzB / rtb_rudder_cmd * rtb_Add2_c5 +
    rtb_Divide4_jaz * rtb_Azb;

  /* Product: '<S587>/Divide' incorporates:
   *  Constant: '<S610>/Constant'
   *  Constant: '<S610>/Constant1'
   *  Constant: '<S610>/Constant11'
   *  Constant: '<S610>/Constant12'
   *  Constant: '<S610>/Constant13'
   *  Constant: '<S610>/Constant14'
   *  Constant: '<S610>/Constant2'
   *  Constant: '<S610>/Constant3'
   *  Constant: '<S610>/Constant4'
   *  Constant: '<S610>/Constant5'
   *  Constant: '<S610>/Constant6'
   *  Constant: '<S610>/Constant7'
   *  Constant: '<S610>/Constant8'
   *  Constant: '<S610>/Constant9'
   *  Constant: '<S623>/Ixz'
   *  Constant: '<S623>/Iyy'
   *  Gain: '<S610>/Gain1'
   *  Gain: '<S610>/Gain2'
   *  Product: '<S610>/Divide1'
   *  Product: '<S610>/Divide2'
   *  Product: '<S610>/Divide3'
   *  Product: '<S610>/Divide4'
   *  Product: '<S610>/Divide5'
   *  Product: '<S610>/Divide6'
   *  Product: '<S623>/Divide4'
   *  Sum: '<S610>/Add'
   *  Sum: '<S610>/Add1'
   *  Sum: '<S610>/Add2'
   *  Sum: '<S610>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S596>/Unit Delay'
   */
  rtb_Divide_nzj = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim)
                        * EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                        EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma * rtb_Divide4_dh +
    EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot * EKF_IFS_2_DW.UnitDelay_DSTATE_j3 *
                       (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim) +
                      EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim * (rtb_throttle_cmd -
    EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.Cmde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1])
                    + 1.0 / EKF_IFS_2_P.Utrim * (rtb_throttle_cmd -
    EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1 * EKF_IFS_2_P.Gain2_Gain_jb *
                    EKF_IFS_2_P.Gain1_Gain_j) * (EKF_IFS_2_P.Ixz_Value_ly /
    EKF_IFS_2_P.IyyB);

  /* Sum: '<S588>/Add1' incorporates:
   *  Constant: '<S624>/Ixx'
   *  Constant: '<S624>/Ixx1'
   *  Constant: '<S624>/Ixz'
   *  Constant: '<S624>/Iyy'
   *  Math: '<S624>/Math Function'
   *  Product: '<S588>/Divide2'
   *  Product: '<S588>/Divide3'
   *  Product: '<S624>/Divide3'
   *  Product: '<S624>/Divide4'
   *  Sum: '<S624>/Add'
   *  Sum: '<S624>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_bw = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S588>/Add' incorporates:
   *  Constant: '<S625>/Ixx'
   *  Product: '<S588>/Divide'
   *  Product: '<S588>/Divide4'
   *  Product: '<S625>/Divide4'
   */
  rtb_Add_k3 = EKF_IFS_2_P.IxxB / rtb_rudder_cmd * rtb_Azb + rtb_Divide4_jaz *
    rtb_Add2_c5;

  /* Sum: '<S161>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_nd = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[6];

  /* Product: '<S634>/Divide2' incorporates:
   *  Trigonometry: '<S634>/Trigonometric Function'
   *  Trigonometry: '<S634>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(rtb_Add_nd);

  /* Product: '<S636>/Divide2' incorporates:
   *  Trigonometry: '<S636>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin(rtb_Add_nd);

  /* Product: '<S639>/Divide2' incorporates:
   *  Trigonometry: '<S639>/Trigonometric Function'
   *  Trigonometry: '<S639>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(rtb_Add_nd);

  /* Product: '<S631>/Divide4' incorporates:
   *  Constant: '<S631>/Constant'
   *  Constant: '<S631>/Constant1'
   *  Math: '<S631>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_md = EKF_IFS_2_P.Constant_Value_if * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S650>/Add' incorporates:
   *  Constant: '<S650>/Constant'
   *  Constant: '<S650>/Constant1'
   *  Constant: '<S650>/Constant10'
   *  Constant: '<S650>/Constant11'
   *  Constant: '<S650>/Constant12'
   *  Constant: '<S650>/Constant13'
   *  Constant: '<S650>/Constant14'
   *  Constant: '<S650>/Constant15'
   *  Constant: '<S650>/Constant2'
   *  Constant: '<S650>/Constant3'
   *  Constant: '<S650>/Constant4'
   *  Constant: '<S650>/Constant5'
   *  Constant: '<S650>/Constant6'
   *  Constant: '<S650>/Constant7'
   *  Constant: '<S650>/Constant8'
   *  Constant: '<S650>/Constant9'
   *  Gain: '<S650>/Gain1'
   *  Gain: '<S650>/Gain2'
   *  Gain: '<S650>/Gain3'
   *  Product: '<S650>/Divide1'
   *  Product: '<S650>/Divide2'
   *  Product: '<S650>/Divide3'
   *  Product: '<S650>/Divide4'
   *  Product: '<S650>/Divide5'
   *  Product: '<S650>/Divide6'
   *  Product: '<S650>/Divide7'
   *  Sum: '<S650>/Add1'
   *  Sum: '<S650>/Add2'
   *  Sum: '<S650>/Add3'
   *  Sum: '<S650>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S641>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_cq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_lr * EKF_IFS_2_P.Gain1_Gain_nd) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_f;

  /* ManualSwitch: '<S649>/Manual Switch' incorporates:
   *  Constant: '<S649>/AR'
   *  Constant: '<S649>/Constant15'
   *  Constant: '<S649>/Constant16'
   *  Constant: '<S649>/Constant17'
   *  Constant: '<S649>/Constant18'
   *  Constant: '<S649>/e'
   *  Math: '<S649>/Math Function'
   *  Product: '<S649>/Divide8'
   *  Product: '<S649>/Divide9'
   *  Sum: '<S649>/Add5'
   *  Sum: '<S649>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_fo == 1) {
    rtb_Axb = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Axb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_aq /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_j +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S649>/Manual Switch' */

  /* Sum: '<S649>/Add' incorporates:
   *  Constant: '<S649>/Constant1'
   *  Constant: '<S649>/Constant10'
   *  Constant: '<S649>/Constant11'
   *  Constant: '<S649>/Constant12'
   *  Constant: '<S649>/Constant13'
   *  Constant: '<S649>/Constant14'
   *  Constant: '<S649>/Constant2'
   *  Constant: '<S649>/Constant3'
   *  Constant: '<S649>/Constant4'
   *  Constant: '<S649>/Constant6'
   *  Constant: '<S649>/Constant7'
   *  Constant: '<S649>/Constant8'
   *  Constant: '<S649>/Constant9'
   *  Gain: '<S649>/Gain1'
   *  Gain: '<S649>/Gain2'
   *  Gain: '<S649>/Gain3'
   *  Product: '<S649>/Divide1'
   *  Product: '<S649>/Divide2'
   *  Product: '<S649>/Divide3'
   *  Product: '<S649>/Divide5'
   *  Product: '<S649>/Divide6'
   *  Product: '<S649>/Divide7'
   *  Sum: '<S649>/Add1'
   *  Sum: '<S649>/Add2'
   *  Sum: '<S649>/Add3'
   *  Sum: '<S649>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S641>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Axb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_cq * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_po * EKF_IFS_2_P.Gain1_Gain_b0) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_jf;

  /* ManualSwitch: '<S635>/Manual Switch' incorporates:
   *  Constant: '<S635>/Constant1'
   *  Constant: '<S643>/Constant'
   *  Constant: '<S661>/Constant'
   *  Constant: '<S661>/Constant1'
   *  Constant: '<S661>/Constant2'
   *  Math: '<S661>/Math Function'
   *  Product: '<S635>/Divide'
   *  Product: '<S635>/Divide5'
   *  Product: '<S658>/Divide3'
   *  Product: '<S658>/Divide5'
   *  Product: '<S661>/Divide1'
   *  Product: '<S661>/Divide2'
   *  Sum: '<S635>/Add'
   *  Sum: '<S658>/Add'
   *  Sum: '<S661>/Add'
   *  Trigonometry: '<S658>/Trigonometric Function'
   *  Trigonometry: '<S658>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_du == 1) {
    /* Gain: '<S661>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_fy * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Axb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq *
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_md *
                EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S635>/Manual Switch' */

  /* Sum: '<S635>/Add1' incorporates:
   *  Constant: '<S635>/Constant'
   *  Product: '<S635>/Divide2'
   *  Product: '<S635>/Divide3'
   *  Product: '<S635>/Divide4'
   *  Trigonometry: '<S635>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S637>/Divide3' */
  rtb_Divide3_kk = rtb_throttle_cmd * rtb_Axb;

  /* ManualSwitch: '<S638>/Manual Switch' incorporates:
   *  Constant: '<S638>/Constant1'
   *  Constant: '<S643>/Constant'
   *  Constant: '<S651>/Constant'
   *  Constant: '<S651>/Constant1'
   *  Constant: '<S651>/Constant10'
   *  Constant: '<S651>/Constant11'
   *  Constant: '<S651>/Constant12'
   *  Constant: '<S651>/Constant2'
   *  Constant: '<S651>/Constant3'
   *  Constant: '<S651>/Constant4'
   *  Constant: '<S651>/Constant5'
   *  Constant: '<S651>/Constant6'
   *  Constant: '<S651>/Constant8'
   *  Product: '<S638>/Divide'
   *  Product: '<S638>/Divide5'
   *  Product: '<S651>/Divide1'
   *  Product: '<S651>/Divide3'
   *  Product: '<S651>/Divide4'
   *  Product: '<S651>/Divide5'
   *  Product: '<S651>/Divide6'
   *  Sum: '<S651>/Add'
   *  Sum: '<S651>/Add1'
   *  Sum: '<S651>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_au == 1) {
    rtb_rudder_cmd = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim)
                         * EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) /
                         EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cyb * rtb_Add_nd) +
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim)
                        * EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) /
                        EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cyda *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cydr *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) * (rtb_Divide4_md *
      EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S638>/Manual Switch' */

  /* Sum: '<S638>/Add1' incorporates:
   *  Constant: '<S638>/Constant'
   *  Product: '<S638>/Divide2'
   *  Product: '<S638>/Divide3'
   *  Product: '<S638>/Divide4'
   *  Trigonometry: '<S638>/Trigonometric Function'
   *  Trigonometry: '<S638>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8 -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_throttle_cmd) +
    sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f
    [8]) * EKF_IFS_2_P.g;

  /* Product: '<S637>/Divide4' */
  rtb_Divide4_hd = rtb_elevator_cmd * rtb_rudder_cmd;

  /* ManualSwitch: '<S640>/Manual Switch' incorporates:
   *  Constant: '<S640>/Constant1'
   *  Constant: '<S643>/Constant'
   *  Product: '<S640>/Divide'
   *  Product: '<S640>/Divide5'
   *  Product: '<S660>/Divide1'
   *  Product: '<S660>/Divide6'
   *  Sum: '<S660>/Add2'
   *  Trigonometry: '<S660>/Trigonometric Function4'
   *  Trigonometry: '<S660>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_hr == 1) {
    rtb_Ayb = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) - cos
               (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_md * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S640>/Manual Switch' */

  /* Sum: '<S640>/Add1' incorporates:
   *  Constant: '<S640>/Constant'
   *  Product: '<S640>/Divide2'
   *  Product: '<S640>/Divide3'
   *  Product: '<S640>/Divide4'
   *  Trigonometry: '<S640>/Trigonometric Function'
   *  Trigonometry: '<S640>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_elevator_cmd) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S637>/Divide5' */
  rtb_Divide5_mk = rtb_Sum8 * rtb_Ayb;

  /* Product: '<S641>/Divide' incorporates:
   *  Math: '<S641>/Math Function'
   *  Math: '<S641>/Math Function1'
   *  Product: '<S641>/Divide3'
   *  Product: '<S641>/Divide4'
   *  Sum: '<S641>/Add'
   *  Sum: '<S641>/Add1'
   */
  rtb_Divide_ep = (rtb_throttle_cmd * rtb_Ayb - rtb_Sum8 * rtb_Axb) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8);

  /* Product: '<S642>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_ku = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_rudder_cmd;

  /* Product: '<S642>/Divide4' incorporates:
   *  Product: '<S642>/Divide1'
   *  Product: '<S642>/Divide2'
   *  Product: '<S642>/Divide5'
   *  Product: '<S642>/Divide6'
   *  Sum: '<S642>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_cj = ((rtb_throttle_cmd * rtb_Axb + rtb_elevator_cmd *
                     rtb_rudder_cmd) + rtb_Sum8 * rtb_Ayb) /
    EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_elevator_cmd;

  /* Math: '<S642>/Math Function' */
  rtb_MathFunction_pu = rtb_throttle_cmd * rtb_throttle_cmd;

  /* Math: '<S642>/Math Function1' */
  rtb_MathFunction1_a = rtb_Sum8 * rtb_Sum8;

  /* Sum: '<S671>/Add' incorporates:
   *  Constant: '<S671>/Ixx1'
   *  Constant: '<S671>/Ixz1'
   *  Constant: '<S671>/Izz1'
   *  Math: '<S671>/Math Function'
   *  Product: '<S671>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S663>/Divide4' incorporates:
   *  Constant: '<S663>/Ixx'
   *  Constant: '<S663>/Ixz'
   *  Constant: '<S663>/Iyy'
   *  Constant: '<S663>/Izz'
   *  Product: '<S663>/Divide3'
   *  Sum: '<S663>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S630>/Add1' incorporates:
   *  Constant: '<S662>/Ixz'
   *  Constant: '<S662>/Iyy'
   *  Constant: '<S662>/Izz'
   *  Math: '<S662>/Math Function'
   *  Product: '<S630>/Divide2'
   *  Product: '<S630>/Divide3'
   *  Product: '<S662>/Divide3'
   *  Product: '<S662>/Divide4'
   *  Sum: '<S662>/Add'
   *  Sum: '<S662>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_ca = ((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* Sum: '<S653>/Add' incorporates:
   *  Constant: '<S653>/Constant10'
   *  Constant: '<S653>/Constant11'
   *  Constant: '<S653>/Constant12'
   *  Constant: '<S653>/Constant13'
   *  Constant: '<S653>/Constant14'
   *  Constant: '<S653>/Constant15'
   *  Constant: '<S653>/Constant5'
   *  Constant: '<S653>/Constant6'
   *  Constant: '<S653>/Constant7'
   *  Constant: '<S653>/Constant8'
   *  Constant: '<S653>/Constant9'
   *  Product: '<S653>/Divide3'
   *  Product: '<S653>/Divide4'
   *  Product: '<S653>/Divide5'
   *  Product: '<S653>/Divide6'
   *  Product: '<S653>/Divide7'
   *  Sum: '<S653>/Add1'
   *  Sum: '<S653>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
               EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
               EKF_IFS_2_P.Clb * rtb_Add_nd) + (EKF_IFS_2_DW.x_est_00_DSTATE_f
    [11] - EKF_IFS_2_P.Rtrim) * EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) /
              EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Clda *
             EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cldr *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S657>/Add' incorporates:
   *  Constant: '<S657>/Constant'
   *  Constant: '<S657>/Constant10'
   *  Constant: '<S657>/Constant11'
   *  Constant: '<S657>/Constant12'
   *  Constant: '<S657>/Constant13'
   *  Constant: '<S657>/Constant14'
   *  Constant: '<S657>/Constant15'
   *  Constant: '<S657>/Constant5'
   *  Constant: '<S657>/Constant6'
   *  Constant: '<S657>/Constant8'
   *  Constant: '<S657>/Constant9'
   *  Product: '<S657>/Divide3'
   *  Product: '<S657>/Divide4'
   *  Product: '<S657>/Divide5'
   *  Product: '<S657>/Divide6'
   *  Product: '<S657>/Divide7'
   *  Sum: '<S657>/Add1'
   *  Sum: '<S657>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb * rtb_Add_nd) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S652>/Add' incorporates:
   *  Product: '<S652>/Divide3'
   *  Product: '<S652>/Divide5'
   *  Trigonometry: '<S652>/Trigonometric Function'
   *  Trigonometry: '<S652>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Azb * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Product: '<S665>/Divide4' incorporates:
   *  Constant: '<S665>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S656>/Add2' incorporates:
   *  Product: '<S656>/Divide1'
   *  Product: '<S656>/Divide6'
   *  Trigonometry: '<S656>/Trigonometric Function4'
   *  Trigonometry: '<S656>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = rtb_Azb * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Sum: '<S630>/Add' incorporates:
   *  Constant: '<S664>/Izz'
   *  Product: '<S630>/Divide'
   *  Product: '<S630>/Divide4'
   *  Product: '<S664>/Divide4'
   */
  rtb_Add_jb = EKF_IFS_2_P.IzzB / rtb_rudder_cmd * rtb_Add2_c5 + rtb_Divide4_jaz
    * rtb_Azb;

  /* Product: '<S632>/Divide' incorporates:
   *  Constant: '<S655>/Constant'
   *  Constant: '<S655>/Constant1'
   *  Constant: '<S655>/Constant11'
   *  Constant: '<S655>/Constant12'
   *  Constant: '<S655>/Constant13'
   *  Constant: '<S655>/Constant14'
   *  Constant: '<S655>/Constant2'
   *  Constant: '<S655>/Constant3'
   *  Constant: '<S655>/Constant4'
   *  Constant: '<S655>/Constant5'
   *  Constant: '<S655>/Constant6'
   *  Constant: '<S655>/Constant7'
   *  Constant: '<S655>/Constant8'
   *  Constant: '<S655>/Constant9'
   *  Constant: '<S668>/Ixz'
   *  Constant: '<S668>/Iyy'
   *  Gain: '<S655>/Gain1'
   *  Gain: '<S655>/Gain2'
   *  Product: '<S655>/Divide1'
   *  Product: '<S655>/Divide2'
   *  Product: '<S655>/Divide3'
   *  Product: '<S655>/Divide4'
   *  Product: '<S655>/Divide5'
   *  Product: '<S655>/Divide6'
   *  Product: '<S668>/Divide4'
   *  Sum: '<S655>/Add'
   *  Sum: '<S655>/Add1'
   *  Sum: '<S655>/Add2'
   *  Sum: '<S655>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S641>/Unit Delay'
   */
  rtb_Divide_h5 = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                       EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                       EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                      EKF_IFS_2_DW.UnitDelay_DSTATE_cq * (EKF_IFS_2_P.Cbar / 2.0)
                      / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim
                     * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) +
                    EKF_IFS_2_P.Cmde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 /
                   EKF_IFS_2_P.Utrim * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) *
                   EKF_IFS_2_P.Cm1 * EKF_IFS_2_P.Gain2_Gain_k2 *
                   EKF_IFS_2_P.Gain1_Gain_on) * (EKF_IFS_2_P.Ixz_Value_at /
    EKF_IFS_2_P.IyyB);

  /* Sum: '<S633>/Add1' incorporates:
   *  Constant: '<S669>/Ixx'
   *  Constant: '<S669>/Ixx1'
   *  Constant: '<S669>/Ixz'
   *  Constant: '<S669>/Iyy'
   *  Math: '<S669>/Math Function'
   *  Product: '<S633>/Divide2'
   *  Product: '<S633>/Divide3'
   *  Product: '<S669>/Divide3'
   *  Product: '<S669>/Divide4'
   *  Sum: '<S669>/Add'
   *  Sum: '<S669>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_ag = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S633>/Add' incorporates:
   *  Constant: '<S670>/Ixx'
   *  Product: '<S633>/Divide'
   *  Product: '<S633>/Divide4'
   *  Product: '<S670>/Divide4'
   */
  rtb_Add_oj = EKF_IFS_2_P.IxxB / rtb_rudder_cmd * rtb_Azb + rtb_Divide4_jaz *
    rtb_Add2_c5;

  /* Product: '<S679>/Divide2' incorporates:
   *  Trigonometry: '<S679>/Trigonometric Function'
   *  Trigonometry: '<S679>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S681>/Divide2' incorporates:
   *  Trigonometry: '<S681>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S684>/Divide2' incorporates:
   *  Trigonometry: '<S684>/Trigonometric Function'
   *  Trigonometry: '<S684>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S676>/Divide4' incorporates:
   *  Constant: '<S676>/Constant'
   *  Constant: '<S676>/Constant1'
   *  Math: '<S676>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_gq = EKF_IFS_2_P.Constant_Value_iu4 * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S695>/Add' incorporates:
   *  Constant: '<S695>/Constant'
   *  Constant: '<S695>/Constant1'
   *  Constant: '<S695>/Constant10'
   *  Constant: '<S695>/Constant11'
   *  Constant: '<S695>/Constant12'
   *  Constant: '<S695>/Constant13'
   *  Constant: '<S695>/Constant14'
   *  Constant: '<S695>/Constant15'
   *  Constant: '<S695>/Constant2'
   *  Constant: '<S695>/Constant3'
   *  Constant: '<S695>/Constant4'
   *  Constant: '<S695>/Constant5'
   *  Constant: '<S695>/Constant6'
   *  Constant: '<S695>/Constant7'
   *  Constant: '<S695>/Constant8'
   *  Constant: '<S695>/Constant9'
   *  Gain: '<S695>/Gain1'
   *  Gain: '<S695>/Gain2'
   *  Gain: '<S695>/Gain3'
   *  Product: '<S695>/Divide1'
   *  Product: '<S695>/Divide2'
   *  Product: '<S695>/Divide3'
   *  Product: '<S695>/Divide4'
   *  Product: '<S695>/Divide5'
   *  Product: '<S695>/Divide6'
   *  Product: '<S695>/Divide7'
   *  Sum: '<S695>/Add1'
   *  Sum: '<S695>/Add2'
   *  Sum: '<S695>/Add3'
   *  Sum: '<S695>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S686>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_ja * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_o4 * EKF_IFS_2_P.Gain1_Gain_er) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_o;

  /* ManualSwitch: '<S694>/Manual Switch' incorporates:
   *  Constant: '<S694>/AR'
   *  Constant: '<S694>/Constant15'
   *  Constant: '<S694>/Constant16'
   *  Constant: '<S694>/Constant17'
   *  Constant: '<S694>/Constant18'
   *  Constant: '<S694>/e'
   *  Math: '<S694>/Math Function'
   *  Product: '<S694>/Divide8'
   *  Product: '<S694>/Divide9'
   *  Sum: '<S694>/Add5'
   *  Sum: '<S694>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_fc == 1) {
    rtb_Axb = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Axb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_g /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_c +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S694>/Manual Switch' */

  /* Sum: '<S694>/Add' incorporates:
   *  Constant: '<S694>/Constant1'
   *  Constant: '<S694>/Constant10'
   *  Constant: '<S694>/Constant11'
   *  Constant: '<S694>/Constant12'
   *  Constant: '<S694>/Constant13'
   *  Constant: '<S694>/Constant14'
   *  Constant: '<S694>/Constant2'
   *  Constant: '<S694>/Constant3'
   *  Constant: '<S694>/Constant4'
   *  Constant: '<S694>/Constant6'
   *  Constant: '<S694>/Constant7'
   *  Constant: '<S694>/Constant8'
   *  Constant: '<S694>/Constant9'
   *  Gain: '<S694>/Gain1'
   *  Gain: '<S694>/Gain2'
   *  Gain: '<S694>/Gain3'
   *  Product: '<S694>/Divide1'
   *  Product: '<S694>/Divide2'
   *  Product: '<S694>/Divide3'
   *  Product: '<S694>/Divide5'
   *  Product: '<S694>/Divide6'
   *  Product: '<S694>/Divide7'
   *  Sum: '<S694>/Add1'
   *  Sum: '<S694>/Add2'
   *  Sum: '<S694>/Add3'
   *  Sum: '<S694>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S686>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Axb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_ja * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_k5 * EKF_IFS_2_P.Gain1_Gain_bg) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_oa;

  /* ManualSwitch: '<S680>/Manual Switch' incorporates:
   *  Constant: '<S680>/Constant1'
   *  Constant: '<S688>/Constant'
   *  Constant: '<S706>/Constant'
   *  Constant: '<S706>/Constant1'
   *  Constant: '<S706>/Constant2'
   *  Math: '<S706>/Math Function'
   *  Product: '<S680>/Divide'
   *  Product: '<S680>/Divide5'
   *  Product: '<S703>/Divide3'
   *  Product: '<S703>/Divide5'
   *  Product: '<S706>/Divide1'
   *  Product: '<S706>/Divide2'
   *  Sum: '<S680>/Add'
   *  Sum: '<S703>/Add'
   *  Sum: '<S706>/Add'
   *  Trigonometry: '<S703>/Trigonometric Function'
   *  Trigonometry: '<S703>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_o5 == 1) {
    /* Gain: '<S706>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_gq * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Axb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq *
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_gq *
                EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S680>/Manual Switch' */

  /* Sum: '<S680>/Add1' incorporates:
   *  Constant: '<S680>/Constant'
   *  Product: '<S680>/Divide2'
   *  Product: '<S680>/Divide3'
   *  Product: '<S680>/Divide4'
   *  Trigonometry: '<S680>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S682>/Divide3' */
  rtb_Divide3_ox = rtb_throttle_cmd * rtb_Axb;

  /* Sum: '<S162>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[7];

  /* ManualSwitch: '<S683>/Manual Switch' incorporates:
   *  Constant: '<S683>/Constant1'
   *  Constant: '<S688>/Constant'
   *  Constant: '<S696>/Constant'
   *  Constant: '<S696>/Constant1'
   *  Constant: '<S696>/Constant10'
   *  Constant: '<S696>/Constant11'
   *  Constant: '<S696>/Constant12'
   *  Constant: '<S696>/Constant2'
   *  Constant: '<S696>/Constant3'
   *  Constant: '<S696>/Constant4'
   *  Constant: '<S696>/Constant5'
   *  Constant: '<S696>/Constant6'
   *  Constant: '<S696>/Constant8'
   *  Product: '<S683>/Divide'
   *  Product: '<S683>/Divide5'
   *  Product: '<S696>/Divide1'
   *  Product: '<S696>/Divide3'
   *  Product: '<S696>/Divide4'
   *  Product: '<S696>/Divide5'
   *  Product: '<S696>/Divide6'
   *  Sum: '<S696>/Add'
   *  Sum: '<S696>/Add1'
   *  Sum: '<S696>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_pz == 1) {
    rtb_Ayb = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                  EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                  EKF_IFS_2_P.Cyb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                 EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                EKF_IFS_2_P.Cyda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
               EKF_IFS_2_P.Cydr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) *
      (rtb_Divide4_gq * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S683>/Manual Switch' */

  /* Sum: '<S683>/Add1' incorporates:
   *  Constant: '<S683>/Constant'
   *  Product: '<S683>/Divide2'
   *  Product: '<S683>/Divide3'
   *  Product: '<S683>/Divide4'
   *  Trigonometry: '<S683>/Trigonometric Function'
   *  Trigonometry: '<S683>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8 -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_throttle_cmd) + sin
    (rtb_rudder_cmd) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S682>/Divide4' */
  rtb_Divide4_hx = rtb_elevator_cmd * rtb_Ayb;

  /* ManualSwitch: '<S685>/Manual Switch' incorporates:
   *  Constant: '<S685>/Constant1'
   *  Constant: '<S688>/Constant'
   *  Product: '<S685>/Divide'
   *  Product: '<S685>/Divide5'
   *  Product: '<S705>/Divide1'
   *  Product: '<S705>/Divide6'
   *  Sum: '<S705>/Add2'
   *  Trigonometry: '<S705>/Trigonometric Function4'
   *  Trigonometry: '<S705>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_p5 == 1) {
    rtb_Add2_jk = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) -
                   cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_gq * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Add2_jk = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S685>/Manual Switch' */

  /* Sum: '<S685>/Add1' incorporates:
   *  Constant: '<S685>/Constant'
   *  Product: '<S685>/Divide2'
   *  Product: '<S685>/Divide3'
   *  Product: '<S685>/Divide4'
   *  Trigonometry: '<S685>/Trigonometric Function'
   *  Trigonometry: '<S685>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd -
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_elevator_cmd) + cos
    (rtb_rudder_cmd) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S682>/Divide5' */
  rtb_Divide5_ps = rtb_Sum8 * rtb_Add2_jk;

  /* Product: '<S686>/Divide' incorporates:
   *  Math: '<S686>/Math Function'
   *  Math: '<S686>/Math Function1'
   *  Product: '<S686>/Divide3'
   *  Product: '<S686>/Divide4'
   *  Sum: '<S686>/Add'
   *  Sum: '<S686>/Add1'
   */
  rtb_Divide_el = (rtb_throttle_cmd * rtb_Add2_jk - rtb_Sum8 * rtb_Axb) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8);

  /* Product: '<S687>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_cv = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Ayb;

  /* Product: '<S687>/Divide4' incorporates:
   *  Product: '<S687>/Divide1'
   *  Product: '<S687>/Divide2'
   *  Product: '<S687>/Divide5'
   *  Product: '<S687>/Divide6'
   *  Sum: '<S687>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_ie = ((rtb_throttle_cmd * rtb_Axb + rtb_elevator_cmd * rtb_Ayb) +
                    rtb_Sum8 * rtb_Add2_jk) / EKF_IFS_2_DW.x_est_00_DSTATE_f[4] *
    rtb_elevator_cmd;

  /* Math: '<S687>/Math Function' */
  rtb_MathFunction_ne = rtb_throttle_cmd * rtb_throttle_cmd;

  /* Math: '<S687>/Math Function1' */
  rtb_MathFunction1_ft = rtb_Sum8 * rtb_Sum8;

  /* Sum: '<S690>/Add' incorporates:
   *  Product: '<S690>/Divide2'
   *  Product: '<S690>/Divide4'
   *  Trigonometry: '<S690>/Trigonometric Function1'
   *  Trigonometry: '<S690>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_gf1 = EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos(rtb_rudder_cmd) + sin
    (rtb_rudder_cmd) * EKF_IFS_2_DW.x_est_00_DSTATE_f[10];

  /* Trigonometry: '<S693>/Trigonometric Function1' */
  rtb_TrigonometricFunction1_dr = cos(rtb_rudder_cmd);

  /* Trigonometry: '<S693>/Trigonometric Function2' */
  rtb_TrigonometricFunction2_aw = sin(rtb_rudder_cmd);

  /* Sum: '<S716>/Add' incorporates:
   *  Constant: '<S716>/Ixx1'
   *  Constant: '<S716>/Ixz1'
   *  Constant: '<S716>/Izz1'
   *  Math: '<S716>/Math Function'
   *  Product: '<S716>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S708>/Divide4' incorporates:
   *  Constant: '<S708>/Ixx'
   *  Constant: '<S708>/Ixz'
   *  Constant: '<S708>/Iyy'
   *  Constant: '<S708>/Izz'
   *  Product: '<S708>/Divide3'
   *  Sum: '<S708>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S675>/Add1' incorporates:
   *  Constant: '<S707>/Ixz'
   *  Constant: '<S707>/Iyy'
   *  Constant: '<S707>/Izz'
   *  Math: '<S707>/Math Function'
   *  Product: '<S675>/Divide2'
   *  Product: '<S675>/Divide3'
   *  Product: '<S707>/Divide3'
   *  Product: '<S707>/Divide4'
   *  Sum: '<S707>/Add'
   *  Sum: '<S707>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_bg = ((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* Sum: '<S698>/Add' incorporates:
   *  Constant: '<S698>/Constant10'
   *  Constant: '<S698>/Constant11'
   *  Constant: '<S698>/Constant12'
   *  Constant: '<S698>/Constant13'
   *  Constant: '<S698>/Constant14'
   *  Constant: '<S698>/Constant15'
   *  Constant: '<S698>/Constant5'
   *  Constant: '<S698>/Constant6'
   *  Constant: '<S698>/Constant7'
   *  Constant: '<S698>/Constant8'
   *  Constant: '<S698>/Constant9'
   *  Product: '<S698>/Divide3'
   *  Product: '<S698>/Divide4'
   *  Product: '<S698>/Divide5'
   *  Product: '<S698>/Divide6'
   *  Product: '<S698>/Divide7'
   *  Sum: '<S698>/Add1'
   *  Sum: '<S698>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                   EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                   EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                  (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                  EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                 EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S702>/Add' incorporates:
   *  Constant: '<S702>/Constant'
   *  Constant: '<S702>/Constant10'
   *  Constant: '<S702>/Constant11'
   *  Constant: '<S702>/Constant12'
   *  Constant: '<S702>/Constant13'
   *  Constant: '<S702>/Constant14'
   *  Constant: '<S702>/Constant15'
   *  Constant: '<S702>/Constant5'
   *  Constant: '<S702>/Constant6'
   *  Constant: '<S702>/Constant8'
   *  Constant: '<S702>/Constant9'
   *  Product: '<S702>/Divide3'
   *  Product: '<S702>/Divide4'
   *  Product: '<S702>/Divide5'
   *  Product: '<S702>/Divide6'
   *  Product: '<S702>/Divide7'
   *  Sum: '<S702>/Add1'
   *  Sum: '<S702>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S697>/Add' incorporates:
   *  Product: '<S697>/Divide3'
   *  Product: '<S697>/Divide5'
   *  Trigonometry: '<S697>/Trigonometric Function'
   *  Trigonometry: '<S697>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Add2_jk * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Product: '<S710>/Divide4' incorporates:
   *  Constant: '<S710>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S701>/Add2' incorporates:
   *  Product: '<S701>/Divide1'
   *  Product: '<S701>/Divide6'
   *  Trigonometry: '<S701>/Trigonometric Function4'
   *  Trigonometry: '<S701>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = rtb_Add2_jk * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Sum: '<S675>/Add' incorporates:
   *  Constant: '<S709>/Izz'
   *  Product: '<S675>/Divide'
   *  Product: '<S675>/Divide4'
   *  Product: '<S709>/Divide4'
   */
  rtb_Add_p0d = EKF_IFS_2_P.IzzB / rtb_rudder_cmd * rtb_Add2_c5 +
    rtb_Divide4_jaz * rtb_Add2_jk;

  /* Product: '<S677>/Divide' incorporates:
   *  Constant: '<S700>/Constant'
   *  Constant: '<S700>/Constant1'
   *  Constant: '<S700>/Constant11'
   *  Constant: '<S700>/Constant12'
   *  Constant: '<S700>/Constant13'
   *  Constant: '<S700>/Constant14'
   *  Constant: '<S700>/Constant2'
   *  Constant: '<S700>/Constant3'
   *  Constant: '<S700>/Constant4'
   *  Constant: '<S700>/Constant5'
   *  Constant: '<S700>/Constant6'
   *  Constant: '<S700>/Constant7'
   *  Constant: '<S700>/Constant8'
   *  Constant: '<S700>/Constant9'
   *  Constant: '<S713>/Ixz'
   *  Constant: '<S713>/Iyy'
   *  Gain: '<S700>/Gain1'
   *  Gain: '<S700>/Gain2'
   *  Product: '<S700>/Divide1'
   *  Product: '<S700>/Divide2'
   *  Product: '<S700>/Divide3'
   *  Product: '<S700>/Divide4'
   *  Product: '<S700>/Divide5'
   *  Product: '<S700>/Divide6'
   *  Product: '<S713>/Divide4'
   *  Sum: '<S700>/Add'
   *  Sum: '<S700>/Add1'
   *  Sum: '<S700>/Add2'
   *  Sum: '<S700>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S686>/Unit Delay'
   */
  rtb_Divide_ok = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                       EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                       EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                      EKF_IFS_2_DW.UnitDelay_DSTATE_ja * (EKF_IFS_2_P.Cbar / 2.0)
                      / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim
                     * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) +
                    EKF_IFS_2_P.Cmde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 /
                   EKF_IFS_2_P.Utrim * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) *
                   EKF_IFS_2_P.Cm1 * EKF_IFS_2_P.Gain2_Gain_p1 *
                   EKF_IFS_2_P.Gain1_Gain_c2) * (EKF_IFS_2_P.Ixz_Value_fr /
    EKF_IFS_2_P.IyyB);

  /* Sum: '<S678>/Add1' incorporates:
   *  Constant: '<S714>/Ixx'
   *  Constant: '<S714>/Ixx1'
   *  Constant: '<S714>/Ixz'
   *  Constant: '<S714>/Iyy'
   *  Math: '<S714>/Math Function'
   *  Product: '<S678>/Divide2'
   *  Product: '<S678>/Divide3'
   *  Product: '<S714>/Divide3'
   *  Product: '<S714>/Divide4'
   *  Sum: '<S714>/Add'
   *  Sum: '<S714>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_efz = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
                  EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S678>/Add' incorporates:
   *  Constant: '<S715>/Ixx'
   *  Product: '<S678>/Divide'
   *  Product: '<S678>/Divide4'
   *  Product: '<S715>/Divide4'
   */
  rtb_Add_md = EKF_IFS_2_P.IxxB / rtb_rudder_cmd * rtb_Add2_jk + rtb_Divide4_jaz
    * rtb_Add2_c5;

  /* Product: '<S724>/Divide2' incorporates:
   *  Trigonometry: '<S724>/Trigonometric Function'
   *  Trigonometry: '<S724>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S726>/Divide2' incorporates:
   *  Trigonometry: '<S726>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S729>/Divide2' incorporates:
   *  Trigonometry: '<S729>/Trigonometric Function'
   *  Trigonometry: '<S729>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Sum: '<S163>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[8];

  /* Product: '<S721>/Divide4' incorporates:
   *  Constant: '<S721>/Constant'
   *  Constant: '<S721>/Constant1'
   *  Math: '<S721>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_lw3 = EKF_IFS_2_P.Constant_Value_fo2 * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S740>/Add' incorporates:
   *  Constant: '<S740>/Constant'
   *  Constant: '<S740>/Constant1'
   *  Constant: '<S740>/Constant10'
   *  Constant: '<S740>/Constant11'
   *  Constant: '<S740>/Constant12'
   *  Constant: '<S740>/Constant13'
   *  Constant: '<S740>/Constant14'
   *  Constant: '<S740>/Constant15'
   *  Constant: '<S740>/Constant2'
   *  Constant: '<S740>/Constant3'
   *  Constant: '<S740>/Constant4'
   *  Constant: '<S740>/Constant5'
   *  Constant: '<S740>/Constant6'
   *  Constant: '<S740>/Constant7'
   *  Constant: '<S740>/Constant8'
   *  Constant: '<S740>/Constant9'
   *  Gain: '<S740>/Gain1'
   *  Gain: '<S740>/Gain2'
   *  Gain: '<S740>/Gain3'
   *  Product: '<S740>/Divide1'
   *  Product: '<S740>/Divide2'
   *  Product: '<S740>/Divide3'
   *  Product: '<S740>/Divide4'
   *  Product: '<S740>/Divide5'
   *  Product: '<S740>/Divide6'
   *  Product: '<S740>/Divide7'
   *  Sum: '<S740>/Add1'
   *  Sum: '<S740>/Add2'
   *  Sum: '<S740>/Add3'
   *  Sum: '<S740>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S731>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_l * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_a2 * EKF_IFS_2_P.Gain1_Gain_om) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_c0;

  /* ManualSwitch: '<S739>/Manual Switch' incorporates:
   *  Constant: '<S739>/AR'
   *  Constant: '<S739>/Constant15'
   *  Constant: '<S739>/Constant16'
   *  Constant: '<S739>/Constant17'
   *  Constant: '<S739>/Constant18'
   *  Constant: '<S739>/e'
   *  Math: '<S739>/Math Function'
   *  Product: '<S739>/Divide8'
   *  Product: '<S739>/Divide9'
   *  Sum: '<S739>/Add5'
   *  Sum: '<S739>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_az == 1) {
    rtb_rudder_cmd = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_rudder_cmd = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_g3
      / (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_cc +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S739>/Manual Switch' */

  /* Sum: '<S739>/Add' incorporates:
   *  Constant: '<S739>/Constant1'
   *  Constant: '<S739>/Constant10'
   *  Constant: '<S739>/Constant11'
   *  Constant: '<S739>/Constant12'
   *  Constant: '<S739>/Constant13'
   *  Constant: '<S739>/Constant14'
   *  Constant: '<S739>/Constant2'
   *  Constant: '<S739>/Constant3'
   *  Constant: '<S739>/Constant4'
   *  Constant: '<S739>/Constant6'
   *  Constant: '<S739>/Constant7'
   *  Constant: '<S739>/Constant8'
   *  Constant: '<S739>/Constant9'
   *  Gain: '<S739>/Gain1'
   *  Gain: '<S739>/Gain2'
   *  Gain: '<S739>/Gain3'
   *  Product: '<S739>/Divide1'
   *  Product: '<S739>/Divide2'
   *  Product: '<S739>/Divide3'
   *  Product: '<S739>/Divide5'
   *  Product: '<S739>/Divide6'
   *  Product: '<S739>/Divide7'
   *  Sum: '<S739>/Add1'
   *  Sum: '<S739>/Add2'
   *  Sum: '<S739>/Add3'
   *  Sum: '<S739>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S731>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_rudder_cmd) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_l * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_oz * EKF_IFS_2_P.Gain1_Gain_c3) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_k;

  /* ManualSwitch: '<S725>/Manual Switch' incorporates:
   *  Constant: '<S725>/Constant1'
   *  Constant: '<S733>/Constant'
   *  Constant: '<S751>/Constant'
   *  Constant: '<S751>/Constant1'
   *  Constant: '<S751>/Constant2'
   *  Math: '<S751>/Math Function'
   *  Product: '<S725>/Divide'
   *  Product: '<S725>/Divide5'
   *  Product: '<S748>/Divide3'
   *  Product: '<S748>/Divide5'
   *  Product: '<S751>/Divide1'
   *  Product: '<S751>/Divide2'
   *  Sum: '<S725>/Add'
   *  Sum: '<S748>/Add'
   *  Sum: '<S751>/Add'
   *  Trigonometry: '<S748>/Trigonometric Function'
   *  Trigonometry: '<S748>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_b == 1) {
    /* Gain: '<S751>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_f1 * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_rudder_cmd = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 +
                        EKF_IFS_2_P.xT1 * rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz -
      rtb_Add_iq * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_lw3 *
      EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S725>/Manual Switch' */

  /* Sum: '<S725>/Add1' incorporates:
   *  Constant: '<S725>/Constant'
   *  Product: '<S725>/Divide2'
   *  Product: '<S725>/Divide3'
   *  Product: '<S725>/Divide4'
   *  Trigonometry: '<S725>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
    (rtb_Axb) * EKF_IFS_2_P.g;

  /* Product: '<S727>/Divide3' */
  rtb_Divide3_ld = rtb_throttle_cmd * rtb_rudder_cmd;

  /* ManualSwitch: '<S728>/Manual Switch' incorporates:
   *  Constant: '<S728>/Constant1'
   *  Constant: '<S733>/Constant'
   *  Constant: '<S741>/Constant'
   *  Constant: '<S741>/Constant1'
   *  Constant: '<S741>/Constant10'
   *  Constant: '<S741>/Constant11'
   *  Constant: '<S741>/Constant12'
   *  Constant: '<S741>/Constant2'
   *  Constant: '<S741>/Constant3'
   *  Constant: '<S741>/Constant4'
   *  Constant: '<S741>/Constant5'
   *  Constant: '<S741>/Constant6'
   *  Constant: '<S741>/Constant8'
   *  Product: '<S728>/Divide'
   *  Product: '<S728>/Divide5'
   *  Product: '<S741>/Divide1'
   *  Product: '<S741>/Divide3'
   *  Product: '<S741>/Divide4'
   *  Product: '<S741>/Divide5'
   *  Product: '<S741>/Divide6'
   *  Sum: '<S741>/Add'
   *  Sum: '<S741>/Add1'
   *  Sum: '<S741>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_dd == 1) {
    rtb_Ayb = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                  EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                  EKF_IFS_2_P.Cyb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                 EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                EKF_IFS_2_P.Cyda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
               EKF_IFS_2_P.Cydr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) *
      (rtb_Divide4_lw3 * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S728>/Manual Switch' */

  /* Sum: '<S728>/Add1' incorporates:
   *  Constant: '<S728>/Constant'
   *  Product: '<S728>/Divide2'
   *  Product: '<S728>/Divide3'
   *  Product: '<S728>/Divide4'
   *  Trigonometry: '<S728>/Trigonometric Function'
   *  Trigonometry: '<S728>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8 -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_throttle_cmd) + sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(rtb_Axb) * EKF_IFS_2_P.g;

  /* Product: '<S727>/Divide4' */
  rtb_Divide4_lc = rtb_elevator_cmd * rtb_Ayb;

  /* ManualSwitch: '<S730>/Manual Switch' incorporates:
   *  Constant: '<S730>/Constant1'
   *  Constant: '<S733>/Constant'
   *  Product: '<S730>/Divide'
   *  Product: '<S730>/Divide5'
   *  Product: '<S750>/Divide1'
   *  Product: '<S750>/Divide6'
   *  Sum: '<S750>/Add2'
   *  Trigonometry: '<S750>/Trigonometric Function4'
   *  Trigonometry: '<S750>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_eb == 1) {
    rtb_Add2_jk = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) -
                   cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_lw3 * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Add2_jk = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S730>/Manual Switch' */

  /* Sum: '<S730>/Add1' incorporates:
   *  Constant: '<S730>/Constant'
   *  Product: '<S730>/Divide2'
   *  Product: '<S730>/Divide3'
   *  Product: '<S730>/Divide4'
   *  Trigonometry: '<S730>/Trigonometric Function'
   *  Trigonometry: '<S730>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd -
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_elevator_cmd) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(rtb_Axb) * EKF_IFS_2_P.g;

  /* Product: '<S727>/Divide5' */
  rtb_Divide5_egl = rtb_Sum8 * rtb_Add2_jk;

  /* Product: '<S731>/Divide' incorporates:
   *  Math: '<S731>/Math Function'
   *  Math: '<S731>/Math Function1'
   *  Product: '<S731>/Divide3'
   *  Product: '<S731>/Divide4'
   *  Sum: '<S731>/Add'
   *  Sum: '<S731>/Add1'
   */
  rtb_Divide_bas = (rtb_throttle_cmd * rtb_Add2_jk - rtb_Sum8 * rtb_rudder_cmd) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8);

  /* Product: '<S732>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_n1 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Ayb;

  /* Product: '<S732>/Divide4' incorporates:
   *  Product: '<S732>/Divide1'
   *  Product: '<S732>/Divide2'
   *  Product: '<S732>/Divide5'
   *  Product: '<S732>/Divide6'
   *  Sum: '<S732>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_c3 = ((rtb_throttle_cmd * rtb_rudder_cmd + rtb_elevator_cmd *
                     rtb_Ayb) + rtb_Sum8 * rtb_Add2_jk) /
    EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_elevator_cmd;

  /* Math: '<S732>/Math Function' */
  rtb_MathFunction_jc = rtb_throttle_cmd * rtb_throttle_cmd;

  /* Math: '<S732>/Math Function1' */
  rtb_MathFunction1_l = rtb_Sum8 * rtb_Sum8;

  /* Trigonometry: '<S735>/Trigonometric Function3' */
  rtb_Axb = tan(rtb_Axb);

  /* Saturate: '<S735>/Saturation' */
  if (rtb_Axb > EKF_IFS_2_P.Saturation_UpperSat_h0) {
    rtb_Saturation_i = EKF_IFS_2_P.Saturation_UpperSat_h0;
  } else if (rtb_Axb < EKF_IFS_2_P.Saturation_LowerSat_k) {
    rtb_Saturation_i = EKF_IFS_2_P.Saturation_LowerSat_k;
  } else {
    rtb_Saturation_i = rtb_Axb;
  }

  /* End of Saturate: '<S735>/Saturation' */

  /* Sum: '<S761>/Add' incorporates:
   *  Constant: '<S761>/Ixx1'
   *  Constant: '<S761>/Ixz1'
   *  Constant: '<S761>/Izz1'
   *  Math: '<S761>/Math Function'
   *  Product: '<S761>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S753>/Divide4' incorporates:
   *  Constant: '<S753>/Ixx'
   *  Constant: '<S753>/Ixz'
   *  Constant: '<S753>/Iyy'
   *  Constant: '<S753>/Izz'
   *  Product: '<S753>/Divide3'
   *  Sum: '<S753>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S720>/Add1' incorporates:
   *  Constant: '<S752>/Ixz'
   *  Constant: '<S752>/Iyy'
   *  Constant: '<S752>/Izz'
   *  Math: '<S752>/Math Function'
   *  Product: '<S720>/Divide2'
   *  Product: '<S720>/Divide3'
   *  Product: '<S752>/Divide3'
   *  Product: '<S752>/Divide4'
   *  Sum: '<S752>/Add'
   *  Sum: '<S752>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_i1 = ((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* Sum: '<S743>/Add' incorporates:
   *  Constant: '<S743>/Constant10'
   *  Constant: '<S743>/Constant11'
   *  Constant: '<S743>/Constant12'
   *  Constant: '<S743>/Constant13'
   *  Constant: '<S743>/Constant14'
   *  Constant: '<S743>/Constant15'
   *  Constant: '<S743>/Constant5'
   *  Constant: '<S743>/Constant6'
   *  Constant: '<S743>/Constant7'
   *  Constant: '<S743>/Constant8'
   *  Constant: '<S743>/Constant9'
   *  Product: '<S743>/Divide3'
   *  Product: '<S743>/Divide4'
   *  Product: '<S743>/Divide5'
   *  Product: '<S743>/Divide6'
   *  Product: '<S743>/Divide7'
   *  Sum: '<S743>/Add1'
   *  Sum: '<S743>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                   EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                   EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                  (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                  EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                 EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S747>/Add' incorporates:
   *  Constant: '<S747>/Constant'
   *  Constant: '<S747>/Constant10'
   *  Constant: '<S747>/Constant11'
   *  Constant: '<S747>/Constant12'
   *  Constant: '<S747>/Constant13'
   *  Constant: '<S747>/Constant14'
   *  Constant: '<S747>/Constant15'
   *  Constant: '<S747>/Constant5'
   *  Constant: '<S747>/Constant6'
   *  Constant: '<S747>/Constant8'
   *  Constant: '<S747>/Constant9'
   *  Product: '<S747>/Divide3'
   *  Product: '<S747>/Divide4'
   *  Product: '<S747>/Divide5'
   *  Product: '<S747>/Divide6'
   *  Product: '<S747>/Divide7'
   *  Sum: '<S747>/Add1'
   *  Sum: '<S747>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S742>/Add' incorporates:
   *  Product: '<S742>/Divide3'
   *  Product: '<S742>/Divide5'
   *  Trigonometry: '<S742>/Trigonometric Function'
   *  Trigonometry: '<S742>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Add2_jk * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Product: '<S755>/Divide4' incorporates:
   *  Constant: '<S755>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S746>/Add2' incorporates:
   *  Product: '<S746>/Divide1'
   *  Product: '<S746>/Divide6'
   *  Trigonometry: '<S746>/Trigonometric Function4'
   *  Trigonometry: '<S746>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = rtb_Add2_jk * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Sum: '<S720>/Add' incorporates:
   *  Constant: '<S754>/Izz'
   *  Product: '<S720>/Divide'
   *  Product: '<S720>/Divide4'
   *  Product: '<S754>/Divide4'
   */
  rtb_Add_dre = EKF_IFS_2_P.IzzB / rtb_rudder_cmd * rtb_Add2_c5 +
    rtb_Divide4_jaz * rtb_Add2_jk;

  /* Product: '<S722>/Divide' incorporates:
   *  Constant: '<S745>/Constant'
   *  Constant: '<S745>/Constant1'
   *  Constant: '<S745>/Constant11'
   *  Constant: '<S745>/Constant12'
   *  Constant: '<S745>/Constant13'
   *  Constant: '<S745>/Constant14'
   *  Constant: '<S745>/Constant2'
   *  Constant: '<S745>/Constant3'
   *  Constant: '<S745>/Constant4'
   *  Constant: '<S745>/Constant5'
   *  Constant: '<S745>/Constant6'
   *  Constant: '<S745>/Constant7'
   *  Constant: '<S745>/Constant8'
   *  Constant: '<S745>/Constant9'
   *  Constant: '<S758>/Ixz'
   *  Constant: '<S758>/Iyy'
   *  Gain: '<S745>/Gain1'
   *  Gain: '<S745>/Gain2'
   *  Product: '<S745>/Divide1'
   *  Product: '<S745>/Divide2'
   *  Product: '<S745>/Divide3'
   *  Product: '<S745>/Divide4'
   *  Product: '<S745>/Divide5'
   *  Product: '<S745>/Divide6'
   *  Product: '<S758>/Divide4'
   *  Sum: '<S745>/Add'
   *  Sum: '<S745>/Add1'
   *  Sum: '<S745>/Add2'
   *  Sum: '<S745>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S731>/Unit Delay'
   */
  rtb_Divide_bg = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                       EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                       EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                      EKF_IFS_2_DW.UnitDelay_DSTATE_l * (EKF_IFS_2_P.Cbar / 2.0)
                      / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim
                     * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) +
                    EKF_IFS_2_P.Cmde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 /
                   EKF_IFS_2_P.Utrim * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) *
                   EKF_IFS_2_P.Cm1 * EKF_IFS_2_P.Gain2_Gain_kp *
                   EKF_IFS_2_P.Gain1_Gain_el) * (EKF_IFS_2_P.Ixz_Value_b /
    EKF_IFS_2_P.IyyB);

  /* Sum: '<S723>/Add1' incorporates:
   *  Constant: '<S759>/Ixx'
   *  Constant: '<S759>/Ixx1'
   *  Constant: '<S759>/Ixz'
   *  Constant: '<S759>/Iyy'
   *  Math: '<S759>/Math Function'
   *  Product: '<S723>/Divide2'
   *  Product: '<S723>/Divide3'
   *  Product: '<S759>/Divide3'
   *  Product: '<S759>/Divide4'
   *  Sum: '<S759>/Add'
   *  Sum: '<S759>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_cf = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
                 EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Ayb *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S723>/Add' incorporates:
   *  Constant: '<S760>/Ixx'
   *  Product: '<S723>/Divide'
   *  Product: '<S723>/Divide4'
   *  Product: '<S760>/Divide4'
   */
  rtb_Add_adw = EKF_IFS_2_P.IxxB / rtb_rudder_cmd * rtb_Add2_jk +
    rtb_Divide4_jaz * rtb_Add2_c5;

  /* Product: '<S319>/Divide2' incorporates:
   *  Trigonometry: '<S319>/Trigonometric Function'
   *  Trigonometry: '<S319>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S321>/Divide2' incorporates:
   *  Trigonometry: '<S321>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S324>/Divide2' incorporates:
   *  Trigonometry: '<S324>/Trigonometric Function'
   *  Trigonometry: '<S324>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S316>/Divide4' incorporates:
   *  Constant: '<S316>/Constant'
   *  Constant: '<S316>/Constant1'
   *  Math: '<S316>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_bv = EKF_IFS_2_P.Constant_Value_cr * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S335>/Add' incorporates:
   *  Constant: '<S335>/Constant'
   *  Constant: '<S335>/Constant1'
   *  Constant: '<S335>/Constant10'
   *  Constant: '<S335>/Constant11'
   *  Constant: '<S335>/Constant12'
   *  Constant: '<S335>/Constant13'
   *  Constant: '<S335>/Constant14'
   *  Constant: '<S335>/Constant15'
   *  Constant: '<S335>/Constant2'
   *  Constant: '<S335>/Constant3'
   *  Constant: '<S335>/Constant4'
   *  Constant: '<S335>/Constant5'
   *  Constant: '<S335>/Constant6'
   *  Constant: '<S335>/Constant7'
   *  Constant: '<S335>/Constant8'
   *  Constant: '<S335>/Constant9'
   *  Gain: '<S335>/Gain1'
   *  Gain: '<S335>/Gain2'
   *  Gain: '<S335>/Gain3'
   *  Product: '<S335>/Divide1'
   *  Product: '<S335>/Divide2'
   *  Product: '<S335>/Divide3'
   *  Product: '<S335>/Divide4'
   *  Product: '<S335>/Divide5'
   *  Product: '<S335>/Divide6'
   *  Product: '<S335>/Divide7'
   *  Sum: '<S335>/Add1'
   *  Sum: '<S335>/Add2'
   *  Sum: '<S335>/Add3'
   *  Sum: '<S335>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S326>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_e * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_cq * EKF_IFS_2_P.Gain1_Gain_i) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_po;

  /* ManualSwitch: '<S334>/Manual Switch' incorporates:
   *  Constant: '<S334>/AR'
   *  Constant: '<S334>/Constant15'
   *  Constant: '<S334>/Constant16'
   *  Constant: '<S334>/Constant17'
   *  Constant: '<S334>/Constant18'
   *  Constant: '<S334>/e'
   *  Math: '<S334>/Math Function'
   *  Product: '<S334>/Divide8'
   *  Product: '<S334>/Divide9'
   *  Sum: '<S334>/Add5'
   *  Sum: '<S334>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_k == 1) {
    rtb_Axb = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Axb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_m /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_d +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S334>/Manual Switch' */

  /* Sum: '<S334>/Add' incorporates:
   *  Constant: '<S334>/Constant1'
   *  Constant: '<S334>/Constant10'
   *  Constant: '<S334>/Constant11'
   *  Constant: '<S334>/Constant12'
   *  Constant: '<S334>/Constant13'
   *  Constant: '<S334>/Constant14'
   *  Constant: '<S334>/Constant2'
   *  Constant: '<S334>/Constant3'
   *  Constant: '<S334>/Constant4'
   *  Constant: '<S334>/Constant6'
   *  Constant: '<S334>/Constant7'
   *  Constant: '<S334>/Constant8'
   *  Constant: '<S334>/Constant9'
   *  Gain: '<S334>/Gain1'
   *  Gain: '<S334>/Gain2'
   *  Gain: '<S334>/Gain3'
   *  Product: '<S334>/Divide1'
   *  Product: '<S334>/Divide2'
   *  Product: '<S334>/Divide3'
   *  Product: '<S334>/Divide5'
   *  Product: '<S334>/Divide6'
   *  Product: '<S334>/Divide7'
   *  Sum: '<S334>/Add1'
   *  Sum: '<S334>/Add2'
   *  Sum: '<S334>/Add3'
   *  Sum: '<S334>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S326>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Axb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_e * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_ns * EKF_IFS_2_P.Gain1_Gain_m1) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_mr;

  /* ManualSwitch: '<S320>/Manual Switch' incorporates:
   *  Constant: '<S320>/Constant1'
   *  Constant: '<S328>/Constant'
   *  Constant: '<S346>/Constant'
   *  Constant: '<S346>/Constant1'
   *  Constant: '<S346>/Constant2'
   *  Math: '<S346>/Math Function'
   *  Product: '<S320>/Divide'
   *  Product: '<S320>/Divide5'
   *  Product: '<S343>/Divide3'
   *  Product: '<S343>/Divide5'
   *  Product: '<S346>/Divide1'
   *  Product: '<S346>/Divide2'
   *  Sum: '<S320>/Add'
   *  Sum: '<S343>/Add'
   *  Sum: '<S346>/Add'
   *  Trigonometry: '<S343>/Trigonometric Function'
   *  Trigonometry: '<S343>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_go == 1) {
    /* Gain: '<S346>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_p * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Axb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq *
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_bv *
                EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S320>/Manual Switch' */

  /* Sum: '<S320>/Add1' incorporates:
   *  Constant: '<S320>/Constant'
   *  Product: '<S320>/Divide2'
   *  Product: '<S320>/Divide3'
   *  Product: '<S320>/Divide4'
   *  Trigonometry: '<S320>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S322>/Divide3' */
  rtb_etaLon = rtb_throttle_cmd * rtb_Axb;

  /* Sum: '<S154>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_co = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[9];

  /* ManualSwitch: '<S323>/Manual Switch' incorporates:
   *  Constant: '<S323>/Constant1'
   *  Constant: '<S328>/Constant'
   *  Constant: '<S336>/Constant'
   *  Constant: '<S336>/Constant1'
   *  Constant: '<S336>/Constant10'
   *  Constant: '<S336>/Constant11'
   *  Constant: '<S336>/Constant12'
   *  Constant: '<S336>/Constant2'
   *  Constant: '<S336>/Constant3'
   *  Constant: '<S336>/Constant4'
   *  Constant: '<S336>/Constant5'
   *  Constant: '<S336>/Constant6'
   *  Constant: '<S336>/Constant8'
   *  Product: '<S323>/Divide'
   *  Product: '<S323>/Divide5'
   *  Product: '<S336>/Divide1'
   *  Product: '<S336>/Divide3'
   *  Product: '<S336>/Divide4'
   *  Product: '<S336>/Divide5'
   *  Product: '<S336>/Divide6'
   *  Sum: '<S336>/Add'
   *  Sum: '<S336>/Add1'
   *  Sum: '<S336>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_i == 1) {
    rtb_rudder_cmd = (((((rtb_Add_co - EKF_IFS_2_P.Ptrim) * EKF_IFS_2_P.Cyp *
                         (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                         EKF_IFS_2_P.Cyb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim)
                        * EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) /
                        EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cyda *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cydr *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) * (rtb_Divide4_bv *
      EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S323>/Manual Switch' */

  /* Sum: '<S323>/Add1' incorporates:
   *  Constant: '<S323>/Constant'
   *  Product: '<S323>/Divide2'
   *  Product: '<S323>/Divide3'
   *  Product: '<S323>/Divide4'
   *  Trigonometry: '<S323>/Trigonometric Function'
   *  Trigonometry: '<S323>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (rtb_Add_co * rtb_Sum8 - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
                     rtb_throttle_cmd) + sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
    cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S322>/Divide4' */
  rtb_Divide4_ft = rtb_elevator_cmd * rtb_rudder_cmd;

  /* ManualSwitch: '<S325>/Manual Switch' incorporates:
   *  Constant: '<S325>/Constant1'
   *  Constant: '<S328>/Constant'
   *  Product: '<S325>/Divide'
   *  Product: '<S325>/Divide5'
   *  Product: '<S345>/Divide1'
   *  Product: '<S345>/Divide6'
   *  Sum: '<S345>/Add2'
   *  Trigonometry: '<S345>/Trigonometric Function4'
   *  Trigonometry: '<S345>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_m == 1) {
    rtb_Ayb = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) - cos
               (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_bv * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S325>/Manual Switch' */

  /* Sum: '<S325>/Add1' incorporates:
   *  Constant: '<S325>/Constant'
   *  Product: '<S325>/Divide2'
   *  Product: '<S325>/Divide3'
   *  Product: '<S325>/Divide4'
   *  Trigonometry: '<S325>/Trigonometric Function'
   *  Trigonometry: '<S325>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd - rtb_Add_co
              * rtb_elevator_cmd) + cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S322>/Divide5' */
  rtb_Divide5_gk = rtb_Sum8 * rtb_Ayb;

  /* Product: '<S326>/Divide' incorporates:
   *  Math: '<S326>/Math Function'
   *  Math: '<S326>/Math Function1'
   *  Product: '<S326>/Divide3'
   *  Product: '<S326>/Divide4'
   *  Sum: '<S326>/Add'
   *  Sum: '<S326>/Add1'
   */
  rtb_Divide_l = (rtb_throttle_cmd * rtb_Ayb - rtb_Sum8 * rtb_Axb) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8);

  /* Product: '<S327>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_iu1 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_rudder_cmd;

  /* Product: '<S327>/Divide4' incorporates:
   *  Product: '<S327>/Divide1'
   *  Product: '<S327>/Divide2'
   *  Product: '<S327>/Divide5'
   *  Product: '<S327>/Divide6'
   *  Sum: '<S327>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_p3cp = ((rtb_throttle_cmd * rtb_Axb + rtb_elevator_cmd *
                       rtb_rudder_cmd) + rtb_Sum8 * rtb_Ayb) /
    EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_elevator_cmd;

  /* Math: '<S327>/Math Function' */
  rtb_MathFunction_dp = rtb_throttle_cmd * rtb_throttle_cmd;

  /* Math: '<S327>/Math Function1' */
  rtb_Divide4_kov = rtb_Sum8 * rtb_Sum8;

  /* Sum: '<S356>/Add' incorporates:
   *  Constant: '<S356>/Ixx1'
   *  Constant: '<S356>/Ixz1'
   *  Constant: '<S356>/Izz1'
   *  Math: '<S356>/Math Function'
   *  Product: '<S356>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S348>/Divide4' incorporates:
   *  Constant: '<S348>/Ixx'
   *  Constant: '<S348>/Ixz'
   *  Constant: '<S348>/Iyy'
   *  Constant: '<S348>/Izz'
   *  Product: '<S348>/Divide3'
   *  Sum: '<S348>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S315>/Add1' incorporates:
   *  Constant: '<S347>/Ixz'
   *  Constant: '<S347>/Iyy'
   *  Constant: '<S347>/Izz'
   *  Math: '<S347>/Math Function'
   *  Product: '<S315>/Divide2'
   *  Product: '<S315>/Divide3'
   *  Product: '<S347>/Divide3'
   *  Product: '<S347>/Divide4'
   *  Sum: '<S347>/Add'
   *  Sum: '<S347>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add1_hkq = ((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                  EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Ayb * rtb_Add_co;

  /* Sum: '<S338>/Add' incorporates:
   *  Constant: '<S338>/Constant10'
   *  Constant: '<S338>/Constant11'
   *  Constant: '<S338>/Constant12'
   *  Constant: '<S338>/Constant13'
   *  Constant: '<S338>/Constant14'
   *  Constant: '<S338>/Constant15'
   *  Constant: '<S338>/Constant5'
   *  Constant: '<S338>/Constant6'
   *  Constant: '<S338>/Constant7'
   *  Constant: '<S338>/Constant8'
   *  Constant: '<S338>/Constant9'
   *  Product: '<S338>/Divide3'
   *  Product: '<S338>/Divide4'
   *  Product: '<S338>/Divide5'
   *  Product: '<S338>/Divide6'
   *  Product: '<S338>/Divide7'
   *  Sum: '<S338>/Add1'
   *  Sum: '<S338>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = ((((rtb_Add_co - EKF_IFS_2_P.Ptrim) * EKF_IFS_2_P.Clp *
               (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Clb *
               EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
              (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
              EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
             EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S342>/Add' incorporates:
   *  Constant: '<S342>/Constant'
   *  Constant: '<S342>/Constant10'
   *  Constant: '<S342>/Constant11'
   *  Constant: '<S342>/Constant12'
   *  Constant: '<S342>/Constant13'
   *  Constant: '<S342>/Constant14'
   *  Constant: '<S342>/Constant15'
   *  Constant: '<S342>/Constant5'
   *  Constant: '<S342>/Constant6'
   *  Constant: '<S342>/Constant8'
   *  Constant: '<S342>/Constant9'
   *  Product: '<S342>/Divide3'
   *  Product: '<S342>/Divide4'
   *  Product: '<S342>/Divide5'
   *  Product: '<S342>/Divide6'
   *  Product: '<S342>/Divide7'
   *  Sum: '<S342>/Add1'
   *  Sum: '<S342>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((rtb_Add_co - EKF_IFS_2_P.Ptrim) * EKF_IFS_2_P.Cnp *
                      (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                      EKF_IFS_2_P.Cnb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S337>/Add' incorporates:
   *  Product: '<S337>/Divide3'
   *  Product: '<S337>/Divide5'
   *  Trigonometry: '<S337>/Trigonometric Function'
   *  Trigonometry: '<S337>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Azb * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Product: '<S350>/Divide4' incorporates:
   *  Constant: '<S350>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S341>/Add2' incorporates:
   *  Product: '<S341>/Divide1'
   *  Product: '<S341>/Divide6'
   *  Trigonometry: '<S341>/Trigonometric Function4'
   *  Trigonometry: '<S341>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = rtb_Azb * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Sum: '<S315>/Add' incorporates:
   *  Constant: '<S349>/Izz'
   *  Product: '<S315>/Divide'
   *  Product: '<S315>/Divide4'
   *  Product: '<S349>/Divide4'
   */
  rtb_Sum5 = EKF_IFS_2_P.IzzB / rtb_rudder_cmd * rtb_Add2_c5 + rtb_Divide4_jaz *
    rtb_Azb;

  /* Product: '<S317>/Divide' incorporates:
   *  Constant: '<S340>/Constant'
   *  Constant: '<S340>/Constant1'
   *  Constant: '<S340>/Constant11'
   *  Constant: '<S340>/Constant12'
   *  Constant: '<S340>/Constant13'
   *  Constant: '<S340>/Constant14'
   *  Constant: '<S340>/Constant2'
   *  Constant: '<S340>/Constant3'
   *  Constant: '<S340>/Constant4'
   *  Constant: '<S340>/Constant5'
   *  Constant: '<S340>/Constant6'
   *  Constant: '<S340>/Constant7'
   *  Constant: '<S340>/Constant8'
   *  Constant: '<S340>/Constant9'
   *  Constant: '<S353>/Ixz'
   *  Constant: '<S353>/Iyy'
   *  Gain: '<S340>/Gain1'
   *  Gain: '<S340>/Gain2'
   *  Product: '<S340>/Divide1'
   *  Product: '<S340>/Divide2'
   *  Product: '<S340>/Divide3'
   *  Product: '<S340>/Divide4'
   *  Product: '<S340>/Divide5'
   *  Product: '<S340>/Divide6'
   *  Product: '<S353>/Divide4'
   *  Sum: '<S340>/Add'
   *  Sum: '<S340>/Add1'
   *  Sum: '<S340>/Add2'
   *  Sum: '<S340>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S326>/Unit Delay'
   */
  rtb_Divide_mhp = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim)
                        * EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
                        EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                       EKF_IFS_2_DW.UnitDelay_DSTATE_e * (EKF_IFS_2_P.Cbar / 2.0)
                       / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu /
                      EKF_IFS_2_P.Utrim * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim))
                     + EKF_IFS_2_P.Cmde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) +
                    1.0 / EKF_IFS_2_P.Utrim * (rtb_throttle_cmd -
    EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1 * EKF_IFS_2_P.Gain2_Gain_c5 *
                    EKF_IFS_2_P.Gain1_Gain_ab) * (EKF_IFS_2_P.Ixz_Value_p /
    EKF_IFS_2_P.IyyB);

  /* Sum: '<S318>/Add1' incorporates:
   *  Constant: '<S354>/Ixx'
   *  Constant: '<S354>/Ixx1'
   *  Constant: '<S354>/Ixz'
   *  Constant: '<S354>/Iyy'
   *  Math: '<S354>/Math Function'
   *  Product: '<S318>/Divide2'
   *  Product: '<S318>/Divide3'
   *  Product: '<S354>/Divide3'
   *  Product: '<S354>/Divide4'
   *  Sum: '<S354>/Add'
   *  Sum: '<S354>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_TrigonometricFunction1_kv = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) *
    EKF_IFS_2_P.IxxB + EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    rtb_Add_co - rtb_Ayb * EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S318>/Add' incorporates:
   *  Constant: '<S355>/Ixx'
   *  Product: '<S318>/Divide'
   *  Product: '<S318>/Divide4'
   *  Product: '<S355>/Divide4'
   */
  rtb_aileron_cmd = EKF_IFS_2_P.IxxB / rtb_rudder_cmd * rtb_Azb +
    rtb_Divide4_jaz * rtb_Add2_c5;

  /* Product: '<S364>/Divide2' incorporates:
   *  Trigonometry: '<S364>/Trigonometric Function'
   *  Trigonometry: '<S364>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S366>/Divide2' incorporates:
   *  Trigonometry: '<S366>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Sum: '<S155>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[10];

  /* Product: '<S369>/Divide2' incorporates:
   *  Trigonometry: '<S369>/Trigonometric Function'
   *  Trigonometry: '<S369>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S361>/Divide4' incorporates:
   *  Constant: '<S361>/Constant'
   *  Constant: '<S361>/Constant1'
   *  Math: '<S361>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_lgu = EKF_IFS_2_P.Constant_Value_cx * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S380>/Add' incorporates:
   *  Constant: '<S380>/Constant'
   *  Constant: '<S380>/Constant1'
   *  Constant: '<S380>/Constant10'
   *  Constant: '<S380>/Constant11'
   *  Constant: '<S380>/Constant12'
   *  Constant: '<S380>/Constant13'
   *  Constant: '<S380>/Constant14'
   *  Constant: '<S380>/Constant15'
   *  Constant: '<S380>/Constant2'
   *  Constant: '<S380>/Constant3'
   *  Constant: '<S380>/Constant4'
   *  Constant: '<S380>/Constant5'
   *  Constant: '<S380>/Constant6'
   *  Constant: '<S380>/Constant7'
   *  Constant: '<S380>/Constant8'
   *  Constant: '<S380>/Constant9'
   *  Gain: '<S380>/Gain1'
   *  Gain: '<S380>/Gain2'
   *  Gain: '<S380>/Gain3'
   *  Product: '<S380>/Divide1'
   *  Product: '<S380>/Divide2'
   *  Product: '<S380>/Divide3'
   *  Product: '<S380>/Divide4'
   *  Product: '<S380>/Divide5'
   *  Product: '<S380>/Divide6'
   *  Product: '<S380>/Divide7'
   *  Sum: '<S380>/Add1'
   *  Sum: '<S380>/Add2'
   *  Sum: '<S380>/Add3'
   *  Sum: '<S380>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S371>/Unit Delay'
   */
  rtb_Add_lzz = ((((((rtb_Sum8 - EKF_IFS_2_P.Qtrim) * EKF_IFS_2_P.CLq *
                     (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim +
                     (EKF_IFS_2_P.CLa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                      EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_dx * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_jj * EKF_IFS_2_P.Gain1_Gain_nc) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_k5;

  /* ManualSwitch: '<S379>/Manual Switch' incorporates:
   *  Constant: '<S379>/AR'
   *  Constant: '<S379>/Constant15'
   *  Constant: '<S379>/Constant16'
   *  Constant: '<S379>/Constant17'
   *  Constant: '<S379>/Constant18'
   *  Constant: '<S379>/e'
   *  Math: '<S379>/Math Function'
   *  Product: '<S379>/Divide8'
   *  Product: '<S379>/Divide9'
   *  Sum: '<S379>/Add5'
   *  Sum: '<S379>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_fq == 1) {
    rtb_rudder_cmd = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_rudder_cmd = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_mf
      / (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_k +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S379>/Manual Switch' */

  /* Sum: '<S379>/Add' incorporates:
   *  Constant: '<S379>/Constant1'
   *  Constant: '<S379>/Constant10'
   *  Constant: '<S379>/Constant11'
   *  Constant: '<S379>/Constant12'
   *  Constant: '<S379>/Constant13'
   *  Constant: '<S379>/Constant14'
   *  Constant: '<S379>/Constant2'
   *  Constant: '<S379>/Constant3'
   *  Constant: '<S379>/Constant4'
   *  Constant: '<S379>/Constant6'
   *  Constant: '<S379>/Constant7'
   *  Constant: '<S379>/Constant8'
   *  Constant: '<S379>/Constant9'
   *  Gain: '<S379>/Gain1'
   *  Gain: '<S379>/Gain2'
   *  Gain: '<S379>/Gain3'
   *  Product: '<S379>/Divide1'
   *  Product: '<S379>/Divide2'
   *  Product: '<S379>/Divide3'
   *  Product: '<S379>/Divide5'
   *  Product: '<S379>/Divide6'
   *  Product: '<S379>/Divide7'
   *  Sum: '<S379>/Add1'
   *  Sum: '<S379>/Add2'
   *  Sum: '<S379>/Add3'
   *  Sum: '<S379>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S371>/Unit Delay'
   */
  rtb_Add_iq = ((((((rtb_Sum8 - EKF_IFS_2_P.Qtrim) * EKF_IFS_2_P.CDq *
                    (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim +
                    rtb_rudder_cmd) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_dx * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_bo * EKF_IFS_2_P.Gain1_Gain_h) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_fi;

  /* ManualSwitch: '<S365>/Manual Switch' incorporates:
   *  Constant: '<S365>/Constant1'
   *  Constant: '<S373>/Constant'
   *  Constant: '<S391>/Constant'
   *  Constant: '<S391>/Constant1'
   *  Constant: '<S391>/Constant2'
   *  Math: '<S391>/Math Function'
   *  Product: '<S365>/Divide'
   *  Product: '<S365>/Divide5'
   *  Product: '<S388>/Divide3'
   *  Product: '<S388>/Divide5'
   *  Product: '<S391>/Divide1'
   *  Product: '<S391>/Divide2'
   *  Sum: '<S365>/Add'
   *  Sum: '<S388>/Add'
   *  Sum: '<S391>/Add'
   *  Trigonometry: '<S388>/Trigonometric Function'
   *  Trigonometry: '<S388>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_kl == 1) {
    /* Gain: '<S391>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_nk * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_rudder_cmd = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 +
                        EKF_IFS_2_P.xT1 * rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz -
      rtb_Add_iq * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_lgu *
      EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S365>/Manual Switch' */

  /* Sum: '<S365>/Add1' incorporates:
   *  Constant: '<S365>/Constant'
   *  Product: '<S365>/Divide2'
   *  Product: '<S365>/Divide3'
   *  Product: '<S365>/Divide4'
   *  Trigonometry: '<S365>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
                     rtb_Sum8 * rtb_Axb) - sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S367>/Divide3' */
  rtb_Divide3_bk = rtb_throttle_cmd * rtb_rudder_cmd;

  /* ManualSwitch: '<S368>/Manual Switch' incorporates:
   *  Constant: '<S368>/Constant1'
   *  Constant: '<S373>/Constant'
   *  Constant: '<S381>/Constant'
   *  Constant: '<S381>/Constant1'
   *  Constant: '<S381>/Constant10'
   *  Constant: '<S381>/Constant11'
   *  Constant: '<S381>/Constant12'
   *  Constant: '<S381>/Constant2'
   *  Constant: '<S381>/Constant3'
   *  Constant: '<S381>/Constant4'
   *  Constant: '<S381>/Constant5'
   *  Constant: '<S381>/Constant6'
   *  Constant: '<S381>/Constant8'
   *  Product: '<S368>/Divide'
   *  Product: '<S368>/Divide5'
   *  Product: '<S381>/Divide1'
   *  Product: '<S381>/Divide3'
   *  Product: '<S381>/Divide4'
   *  Product: '<S381>/Divide5'
   *  Product: '<S381>/Divide6'
   *  Sum: '<S381>/Add'
   *  Sum: '<S381>/Add1'
   *  Sum: '<S381>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_ah == 1) {
    rtb_Ayb = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                  EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                  EKF_IFS_2_P.Cyb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                 EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                EKF_IFS_2_P.Cyda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
               EKF_IFS_2_P.Cydr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) *
      (rtb_Divide4_lgu * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S368>/Manual Switch' */

  /* Sum: '<S368>/Add1' incorporates:
   *  Constant: '<S368>/Constant'
   *  Product: '<S368>/Divide2'
   *  Product: '<S368>/Divide3'
   *  Product: '<S368>/Divide4'
   *  Trigonometry: '<S368>/Trigonometric Function'
   *  Trigonometry: '<S368>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Axb -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_throttle_cmd) + sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S367>/Divide4' */
  rtb_Divide4_l2 = rtb_elevator_cmd * rtb_Ayb;

  /* ManualSwitch: '<S370>/Manual Switch' incorporates:
   *  Constant: '<S370>/Constant1'
   *  Constant: '<S373>/Constant'
   *  Product: '<S370>/Divide'
   *  Product: '<S370>/Divide5'
   *  Product: '<S390>/Divide1'
   *  Product: '<S390>/Divide6'
   *  Sum: '<S390>/Add2'
   *  Trigonometry: '<S390>/Trigonometric Function4'
   *  Trigonometry: '<S390>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_gpw == 1) {
    rtb_Add2_jk = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) -
                   cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_lgu * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Add2_jk = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S370>/Manual Switch' */

  /* Sum: '<S370>/Add1' incorporates:
   *  Constant: '<S370>/Constant'
   *  Product: '<S370>/Divide2'
   *  Product: '<S370>/Divide3'
   *  Product: '<S370>/Divide4'
   *  Trigonometry: '<S370>/Trigonometric Function'
   *  Trigonometry: '<S370>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk += (rtb_Sum8 * rtb_throttle_cmd - EKF_IFS_2_DW.x_est_00_DSTATE_f[9]
                  * rtb_elevator_cmd) + cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
    cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* Product: '<S367>/Divide5' */
  rtb_Divide4_dh = rtb_Axb * rtb_Add2_jk;

  /* Product: '<S371>/Divide' incorporates:
   *  Math: '<S371>/Math Function'
   *  Math: '<S371>/Math Function1'
   *  Product: '<S371>/Divide3'
   *  Product: '<S371>/Divide4'
   *  Sum: '<S371>/Add'
   *  Sum: '<S371>/Add1'
   */
  rtb_Divide_mg = (rtb_throttle_cmd * rtb_Add2_jk - rtb_Axb * rtb_rudder_cmd) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Axb * rtb_Axb);

  /* Product: '<S372>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_mja = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Ayb;

  /* Product: '<S372>/Divide4' incorporates:
   *  Product: '<S372>/Divide1'
   *  Product: '<S372>/Divide2'
   *  Product: '<S372>/Divide5'
   *  Product: '<S372>/Divide6'
   *  Sum: '<S372>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain_cl = ((rtb_throttle_cmd * rtb_rudder_cmd + rtb_elevator_cmd * rtb_Ayb)
                 + rtb_Axb * rtb_Add2_jk) / EKF_IFS_2_DW.x_est_00_DSTATE_f[4] *
    rtb_elevator_cmd;

  /* Sum: '<S375>/Add' incorporates:
   *  Product: '<S375>/Divide2'
   *  Product: '<S375>/Divide4'
   *  Trigonometry: '<S375>/Trigonometric Function1'
   *  Trigonometry: '<S375>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_lzz = EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7])
    * rtb_Sum8;

  /* Sum: '<S378>/Add' incorporates:
   *  Product: '<S378>/Divide2'
   *  Product: '<S378>/Divide4'
   *  Trigonometry: '<S378>/Trigonometric Function1'
   *  Trigonometry: '<S378>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd = rtb_Sum8 * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Sum: '<S401>/Add' incorporates:
   *  Constant: '<S401>/Ixx1'
   *  Constant: '<S401>/Ixz1'
   *  Constant: '<S401>/Izz1'
   *  Math: '<S401>/Math Function'
   *  Product: '<S401>/Divide1'
   */
  rtb_Ayb = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S393>/Divide4' incorporates:
   *  Constant: '<S393>/Ixx'
   *  Constant: '<S393>/Ixz'
   *  Constant: '<S393>/Iyy'
   *  Constant: '<S393>/Izz'
   *  Product: '<S393>/Divide3'
   *  Sum: '<S393>/Add'
   */
  rtb_Add2_jk = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_Ayb;

  /* Sum: '<S383>/Add' incorporates:
   *  Constant: '<S383>/Constant10'
   *  Constant: '<S383>/Constant11'
   *  Constant: '<S383>/Constant12'
   *  Constant: '<S383>/Constant13'
   *  Constant: '<S383>/Constant14'
   *  Constant: '<S383>/Constant15'
   *  Constant: '<S383>/Constant5'
   *  Constant: '<S383>/Constant6'
   *  Constant: '<S383>/Constant7'
   *  Constant: '<S383>/Constant8'
   *  Constant: '<S383>/Constant9'
   *  Product: '<S383>/Divide3'
   *  Product: '<S383>/Divide4'
   *  Product: '<S383>/Divide5'
   *  Product: '<S383>/Divide6'
   *  Product: '<S383>/Divide7'
   *  Sum: '<S383>/Add1'
   *  Sum: '<S383>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Clb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                     (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                     EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                    + EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S387>/Add' incorporates:
   *  Constant: '<S387>/Constant'
   *  Constant: '<S387>/Constant10'
   *  Constant: '<S387>/Constant11'
   *  Constant: '<S387>/Constant12'
   *  Constant: '<S387>/Constant13'
   *  Constant: '<S387>/Constant14'
   *  Constant: '<S387>/Constant15'
   *  Constant: '<S387>/Constant5'
   *  Constant: '<S387>/Constant6'
   *  Constant: '<S387>/Constant8'
   *  Constant: '<S387>/Constant9'
   *  Product: '<S387>/Divide3'
   *  Product: '<S387>/Divide4'
   *  Product: '<S387>/Divide5'
   *  Product: '<S387>/Divide6'
   *  Product: '<S387>/Divide7'
   *  Sum: '<S387>/Add1'
   *  Sum: '<S387>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                   EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                   EKF_IFS_2_P.Cnb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                  (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                  EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                 EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S382>/Add' incorporates:
   *  Product: '<S382>/Divide3'
   *  Product: '<S382>/Divide5'
   *  Trigonometry: '<S382>/Trigonometric Function'
   *  Trigonometry: '<S382>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_jaz = rtb_Divide_niq * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) -
    sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add2_c5;

  /* Product: '<S395>/Divide4' incorporates:
   *  Constant: '<S395>/Ixz'
   */
  rtb_Divide4_ot = EKF_IFS_2_P.IxzB / rtb_Ayb;

  /* Sum: '<S386>/Add2' incorporates:
   *  Product: '<S386>/Divide1'
   *  Product: '<S386>/Divide6'
   *  Trigonometry: '<S386>/Trigonometric Function4'
   *  Trigonometry: '<S386>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = rtb_Divide_niq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add2_c5;

  /* Sum: '<S360>/Add2' incorporates:
   *  Constant: '<S360>/Constant1'
   *  Constant: '<S360>/Constant2'
   *  Constant: '<S392>/Ixz'
   *  Constant: '<S392>/Iyy'
   *  Constant: '<S392>/Izz'
   *  Constant: '<S394>/Izz'
   *  Math: '<S392>/Math Function'
   *  Product: '<S360>/Divide'
   *  Product: '<S360>/Divide1'
   *  Product: '<S360>/Divide2'
   *  Product: '<S360>/Divide3'
   *  Product: '<S360>/Divide4'
   *  Product: '<S360>/Divide5'
   *  Product: '<S360>/Divide6'
   *  Product: '<S392>/Divide3'
   *  Product: '<S392>/Divide4'
   *  Product: '<S394>/Divide4'
   *  Sum: '<S360>/Add'
   *  Sum: '<S360>/Add1'
   *  Sum: '<S392>/Add'
   *  Sum: '<S392>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = (((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) * EKF_IFS_2_P.IzzB -
                  EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Ayb *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Add2_jk *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) * rtb_Sum8 +
    (EKF_IFS_2_P.IzzB / rtb_Ayb * rtb_Divide4_jaz + rtb_Divide4_ot *
     rtb_Divide_niq) * (rtb_Divide4_lgu * EKF_IFS_2_P.S * EKF_IFS_2_P.b);

  /* Product: '<S362>/Divide' incorporates:
   *  Constant: '<S385>/Constant'
   *  Constant: '<S385>/Constant1'
   *  Constant: '<S385>/Constant11'
   *  Constant: '<S385>/Constant12'
   *  Constant: '<S385>/Constant13'
   *  Constant: '<S385>/Constant14'
   *  Constant: '<S385>/Constant2'
   *  Constant: '<S385>/Constant3'
   *  Constant: '<S385>/Constant4'
   *  Constant: '<S385>/Constant5'
   *  Constant: '<S385>/Constant6'
   *  Constant: '<S385>/Constant7'
   *  Constant: '<S385>/Constant8'
   *  Constant: '<S385>/Constant9'
   *  Constant: '<S398>/Ixz'
   *  Constant: '<S398>/Iyy'
   *  Gain: '<S385>/Gain1'
   *  Gain: '<S385>/Gain2'
   *  Product: '<S385>/Divide1'
   *  Product: '<S385>/Divide2'
   *  Product: '<S385>/Divide3'
   *  Product: '<S385>/Divide4'
   *  Product: '<S385>/Divide5'
   *  Product: '<S385>/Divide6'
   *  Product: '<S398>/Divide4'
   *  Sum: '<S385>/Add'
   *  Sum: '<S385>/Add1'
   *  Sum: '<S385>/Add2'
   *  Sum: '<S385>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S371>/Unit Delay'
   */
  rtb_Add_iq = ((((((rtb_Sum8 - EKF_IFS_2_P.Qtrim) * EKF_IFS_2_P.Cmq *
                    (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim +
                    (EKF_IFS_2_P.Cma * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                     EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_dx * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.Cmde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1 *
                EKF_IFS_2_P.Gain2_Gain_p4 * EKF_IFS_2_P.Gain1_Gain_db) *
    (EKF_IFS_2_P.Ixz_Value_c / EKF_IFS_2_P.IyyB);

  /* Sum: '<S363>/Add2' incorporates:
   *  Constant: '<S363>/Constant1'
   *  Constant: '<S363>/Constant2'
   *  Constant: '<S399>/Ixx'
   *  Constant: '<S399>/Ixx1'
   *  Constant: '<S399>/Ixz'
   *  Constant: '<S399>/Iyy'
   *  Constant: '<S400>/Ixx'
   *  Math: '<S399>/Math Function'
   *  Product: '<S363>/Divide'
   *  Product: '<S363>/Divide1'
   *  Product: '<S363>/Divide2'
   *  Product: '<S363>/Divide3'
   *  Product: '<S363>/Divide4'
   *  Product: '<S363>/Divide5'
   *  Product: '<S363>/Divide6'
   *  Product: '<S399>/Divide3'
   *  Product: '<S399>/Divide4'
   *  Product: '<S400>/Divide4'
   *  Sum: '<S363>/Add'
   *  Sum: '<S363>/Add1'
   *  Sum: '<S399>/Add'
   *  Sum: '<S399>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = (((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) * EKF_IFS_2_P.IxxB +
               EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Ayb *
              EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Add2_jk *
              EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * rtb_Sum8 + (EKF_IFS_2_P.IxxB
    / rtb_Ayb * rtb_Divide_niq + rtb_Divide4_ot * rtb_Divide4_jaz) *
    (rtb_Divide4_lgu * EKF_IFS_2_P.S * EKF_IFS_2_P.b);

  /* Saturate: '<S357>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Product: '<S147>/Divide9' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S357>/Gain'
   *  Gain: '<S357>/Gain1'
   *  Saturate: '<S357>/Throttle Limiter'
   *  Sum: '<S147>/Sum10'
   *  Sum: '<S357>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_est_kk_f[0] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S357>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Product: '<S147>/Divide9' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S357>/Gain2'
   *  Gain: '<S357>/Gain3'
   *  Saturate: '<S357>/Elevator Limiter'
   *  Sum: '<S147>/Sum10'
   *  Sum: '<S357>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_est_kk_f[1] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S357>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Product: '<S147>/Divide9' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S357>/Gain4'
   *  Gain: '<S357>/Gain5'
   *  Saturate: '<S357>/Aileron Limiter'
   *  Sum: '<S147>/Sum10'
   *  Sum: '<S357>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_est_kk_f[2] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i;

  /* Saturate: '<S357>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Product: '<S147>/Divide9' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S357>/Gain6'
   *  Gain: '<S357>/Gain7'
   *  Math: '<S372>/Math Function'
   *  Math: '<S372>/Math Function1'
   *  Product: '<S367>/Divide'
   *  Product: '<S372>/Divide'
   *  Saturate: '<S357>/Rudder Limiter'
   *  Sum: '<S147>/Sum10'
   *  Sum: '<S357>/Add3'
   *  Sum: '<S367>/Add'
   *  Sum: '<S372>/Add'
   *  Sum: '<S372>/Add1'
   *  Trigonometry: '<S372>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_est_kk_f[3] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[4] = (((rtb_Divide3_bk + rtb_Divide4_l2) + rtb_Divide4_dh) /
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[5] = (rtb_Divide_mg - rtb_Divide) / EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[6] = ((rtb_Divide3_mja - rtb_Gain_cl) / (rtb_throttle_cmd *
    rtb_throttle_cmd + rtb_Axb * rtb_Axb) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6])
                       - rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i;

  /* Trigonometry: '<S375>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S375>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_b) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_b;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_fo) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_fo;
    }
  }

  /* Product: '<S147>/Divide9' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S362>/Constant1'
   *  Constant: '<S362>/Constant2'
   *  Constant: '<S376>/Constant'
   *  Constant: '<S377>/Constant'
   *  Constant: '<S396>/Ixx'
   *  Constant: '<S396>/Iyy'
   *  Constant: '<S396>/Izz'
   *  Constant: '<S397>/Ixz'
   *  Constant: '<S397>/Iyy'
   *  Math: '<S362>/Math Function'
   *  Math: '<S362>/Math Function1'
   *  Product: '<S362>/Divide2'
   *  Product: '<S362>/Divide3'
   *  Product: '<S362>/Divide5'
   *  Product: '<S362>/Divide6'
   *  Product: '<S375>/Divide1'
   *  Product: '<S396>/Divide4'
   *  Product: '<S397>/Divide4'
   *  Saturate: '<S375>/Saturation'
   *  Sum: '<S147>/Sum10'
   *  Sum: '<S362>/Add1'
   *  Sum: '<S362>/Add3'
   *  Sum: '<S375>/Add1'
   *  Sum: '<S396>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_est_kk_f[7] = ((rtb_Add_lzz * rtb_x_W1_dot_idx_0 +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[8] = (rtb_rudder_cmd - rtb_Add_ey) / EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[9] = (rtb_Add2_c5 - rtb_Add2_lg4) / EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[10] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
    + rtb_Divide4_lgu * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar * rtb_Add_iq) -
                        rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[11] = (rtb_Sum8 - rtb_Divide4_in) / EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[12] = (EKF_IFS_2_P.Constant_Value_b1 -
                        EKF_IFS_2_P.Constant_Value_b) /
    EKF_IFS_2_P.delta_Value_i;
  rtb_x_est_kk_f[13] = (EKF_IFS_2_P.Constant_Value_ob -
                        EKF_IFS_2_P.Constant_Value_m) /
    EKF_IFS_2_P.delta_Value_i;

  /* Product: '<S409>/Divide2' incorporates:
   *  Trigonometry: '<S409>/Trigonometric Function'
   *  Trigonometry: '<S409>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Sum: '<S156>/Add' incorporates:
   *  Constant: '<S147>/delta'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_dh = EKF_IFS_2_P.delta_Value_i + EKF_IFS_2_DW.x_est_00_DSTATE_f[11];

  /* Product: '<S411>/Divide2' incorporates:
   *  Trigonometry: '<S411>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S414>/Divide2' incorporates:
   *  Trigonometry: '<S414>/Trigonometric Function'
   *  Trigonometry: '<S414>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S406>/Divide4' incorporates:
   *  Constant: '<S406>/Constant'
   *  Constant: '<S406>/Constant1'
   *  Math: '<S406>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_ea = EKF_IFS_2_P.Constant_Value_lb * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S425>/Add' incorporates:
   *  Constant: '<S425>/Constant'
   *  Constant: '<S425>/Constant1'
   *  Constant: '<S425>/Constant10'
   *  Constant: '<S425>/Constant11'
   *  Constant: '<S425>/Constant12'
   *  Constant: '<S425>/Constant13'
   *  Constant: '<S425>/Constant14'
   *  Constant: '<S425>/Constant15'
   *  Constant: '<S425>/Constant2'
   *  Constant: '<S425>/Constant3'
   *  Constant: '<S425>/Constant4'
   *  Constant: '<S425>/Constant5'
   *  Constant: '<S425>/Constant6'
   *  Constant: '<S425>/Constant7'
   *  Constant: '<S425>/Constant8'
   *  Constant: '<S425>/Constant9'
   *  Gain: '<S425>/Gain1'
   *  Gain: '<S425>/Gain2'
   *  Gain: '<S425>/Gain3'
   *  Product: '<S425>/Divide1'
   *  Product: '<S425>/Divide2'
   *  Product: '<S425>/Divide3'
   *  Product: '<S425>/Divide4'
   *  Product: '<S425>/Divide5'
   *  Product: '<S425>/Divide6'
   *  Product: '<S425>/Divide7'
   *  Sum: '<S425>/Add1'
   *  Sum: '<S425>/Add2'
   *  Sum: '<S425>/Add3'
   *  Sum: '<S425>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S416>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_f * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_kz * EKF_IFS_2_P.Gain1_Gain_f) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_l;

  /* ManualSwitch: '<S424>/Manual Switch' incorporates:
   *  Constant: '<S424>/AR'
   *  Constant: '<S424>/Constant15'
   *  Constant: '<S424>/Constant16'
   *  Constant: '<S424>/Constant17'
   *  Constant: '<S424>/Constant18'
   *  Constant: '<S424>/e'
   *  Math: '<S424>/Math Function'
   *  Product: '<S424>/Divide8'
   *  Product: '<S424>/Divide9'
   *  Sum: '<S424>/Add5'
   *  Sum: '<S424>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_ll == 1) {
    rtb_Axb = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Axb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_p /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_b +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S424>/Manual Switch' */

  /* Sum: '<S424>/Add' incorporates:
   *  Constant: '<S424>/Constant1'
   *  Constant: '<S424>/Constant10'
   *  Constant: '<S424>/Constant11'
   *  Constant: '<S424>/Constant12'
   *  Constant: '<S424>/Constant13'
   *  Constant: '<S424>/Constant14'
   *  Constant: '<S424>/Constant2'
   *  Constant: '<S424>/Constant3'
   *  Constant: '<S424>/Constant4'
   *  Constant: '<S424>/Constant6'
   *  Constant: '<S424>/Constant7'
   *  Constant: '<S424>/Constant8'
   *  Constant: '<S424>/Constant9'
   *  Gain: '<S424>/Gain1'
   *  Gain: '<S424>/Gain2'
   *  Gain: '<S424>/Gain3'
   *  Product: '<S424>/Divide1'
   *  Product: '<S424>/Divide2'
   *  Product: '<S424>/Divide3'
   *  Product: '<S424>/Divide5'
   *  Product: '<S424>/Divide6'
   *  Product: '<S424>/Divide7'
   *  Sum: '<S424>/Add1'
   *  Sum: '<S424>/Add2'
   *  Sum: '<S424>/Add3'
   *  Sum: '<S424>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S416>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Axb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_f * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_py * EKF_IFS_2_P.Gain1_Gain_dk) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_i;

  /* ManualSwitch: '<S410>/Manual Switch' incorporates:
   *  Constant: '<S410>/Constant1'
   *  Constant: '<S418>/Constant'
   *  Constant: '<S436>/Constant'
   *  Constant: '<S436>/Constant1'
   *  Constant: '<S436>/Constant2'
   *  Math: '<S436>/Math Function'
   *  Product: '<S410>/Divide'
   *  Product: '<S410>/Divide5'
   *  Product: '<S433>/Divide3'
   *  Product: '<S433>/Divide5'
   *  Product: '<S436>/Divide1'
   *  Product: '<S436>/Divide2'
   *  Sum: '<S410>/Add'
   *  Sum: '<S433>/Add'
   *  Sum: '<S436>/Add'
   *  Trigonometry: '<S433>/Trigonometric Function'
   *  Trigonometry: '<S433>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_jv == 1) {
    /* Gain: '<S436>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_b * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Axb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq *
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_ea *
                EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S410>/Manual Switch' */

  /* Sum: '<S410>/Add1' incorporates:
   *  Constant: '<S410>/Constant'
   *  Product: '<S410>/Divide2'
   *  Product: '<S410>/Divide3'
   *  Product: '<S410>/Divide4'
   *  Trigonometry: '<S410>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Axb += (rtb_Divide4_dh * rtb_elevator_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g;

  /* ManualSwitch: '<S413>/Manual Switch' incorporates:
   *  Constant: '<S413>/Constant1'
   *  Constant: '<S418>/Constant'
   *  Constant: '<S426>/Constant'
   *  Constant: '<S426>/Constant1'
   *  Constant: '<S426>/Constant10'
   *  Constant: '<S426>/Constant11'
   *  Constant: '<S426>/Constant12'
   *  Constant: '<S426>/Constant2'
   *  Constant: '<S426>/Constant3'
   *  Constant: '<S426>/Constant4'
   *  Constant: '<S426>/Constant5'
   *  Constant: '<S426>/Constant6'
   *  Constant: '<S426>/Constant8'
   *  Product: '<S413>/Divide'
   *  Product: '<S413>/Divide5'
   *  Product: '<S426>/Divide1'
   *  Product: '<S426>/Divide3'
   *  Product: '<S426>/Divide4'
   *  Product: '<S426>/Divide5'
   *  Product: '<S426>/Divide6'
   *  Sum: '<S426>/Add'
   *  Sum: '<S426>/Add1'
   *  Sum: '<S426>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_nh == 1) {
    rtb_rudder_cmd = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim)
                         * EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) /
                         EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cyb *
                         EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) + (rtb_Divide4_dh -
      EKF_IFS_2_P.Rtrim) * EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) /
                        EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cyda *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cydr *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) * (rtb_Divide4_ea *
      EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_rudder_cmd = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S413>/Manual Switch' */

  /* Sum: '<S413>/Add1' incorporates:
   *  Constant: '<S413>/Constant'
   *  Product: '<S413>/Divide2'
   *  Product: '<S413>/Divide3'
   *  Product: '<S413>/Divide4'
   *  Trigonometry: '<S413>/Trigonometric Function'
   *  Trigonometry: '<S413>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd += (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8 -
                     rtb_Divide4_dh * rtb_throttle_cmd) + sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* ManualSwitch: '<S415>/Manual Switch' incorporates:
   *  Constant: '<S415>/Constant1'
   *  Constant: '<S418>/Constant'
   *  Product: '<S415>/Divide'
   *  Product: '<S415>/Divide5'
   *  Product: '<S435>/Divide1'
   *  Product: '<S435>/Divide6'
   *  Sum: '<S435>/Add2'
   *  Trigonometry: '<S435>/Trigonometric Function4'
   *  Trigonometry: '<S435>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_ck == 1) {
    rtb_Ayb = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) - cos
               (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_ea * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S415>/Manual Switch' */

  /* Sum: '<S415>/Add1' incorporates:
   *  Constant: '<S415>/Constant'
   *  Product: '<S415>/Divide2'
   *  Product: '<S415>/Divide3'
   *  Product: '<S415>/Divide4'
   *  Trigonometry: '<S415>/Trigonometric Function'
   *  Trigonometry: '<S415>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Ayb += (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd -
              EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_elevator_cmd) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[8])
    * EKF_IFS_2_P.g;

  /* Product: '<S412>/Divide' incorporates:
   *  Product: '<S412>/Divide3'
   *  Product: '<S412>/Divide4'
   *  Product: '<S412>/Divide5'
   *  Sum: '<S412>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = ((rtb_throttle_cmd * rtb_Axb + rtb_elevator_cmd * rtb_rudder_cmd)
                 + rtb_Sum8 * rtb_Ayb) / EKF_IFS_2_DW.x_est_00_DSTATE_f[4];

  /* Product: '<S416>/Divide' incorporates:
   *  Math: '<S416>/Math Function'
   *  Math: '<S416>/Math Function1'
   *  Product: '<S416>/Divide3'
   *  Product: '<S416>/Divide4'
   *  Sum: '<S416>/Add'
   *  Sum: '<S416>/Add1'
   */
  rtb_Divide_kts = (rtb_throttle_cmd * rtb_Ayb - rtb_Sum8 * rtb_Axb) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8);

  /* Product: '<S417>/Divide' incorporates:
   *  Math: '<S417>/Math Function'
   *  Math: '<S417>/Math Function1'
   *  Product: '<S417>/Divide1'
   *  Product: '<S417>/Divide2'
   *  Product: '<S417>/Divide3'
   *  Product: '<S417>/Divide4'
   *  Product: '<S417>/Divide5'
   *  Product: '<S417>/Divide6'
   *  Sum: '<S417>/Add'
   *  Sum: '<S417>/Add1'
   *  Sum: '<S417>/Add2'
   *  Trigonometry: '<S417>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_rudder_cmd -
                      ((rtb_throttle_cmd * rtb_Axb + rtb_elevator_cmd *
                        rtb_rudder_cmd) + rtb_Sum8 * rtb_Ayb) /
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_elevator_cmd) /
    (rtb_throttle_cmd * rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8) * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Sum: '<S446>/Add' incorporates:
   *  Constant: '<S446>/Ixx1'
   *  Constant: '<S446>/Ixz1'
   *  Constant: '<S446>/Izz1'
   *  Math: '<S446>/Math Function'
   *  Product: '<S446>/Divide1'
   */
  rtb_rudder_cmd = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S438>/Divide4' incorporates:
   *  Constant: '<S438>/Ixx'
   *  Constant: '<S438>/Ixz'
   *  Constant: '<S438>/Iyy'
   *  Constant: '<S438>/Izz'
   *  Product: '<S438>/Divide3'
   *  Sum: '<S438>/Add'
   */
  rtb_Ayb = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S428>/Add' incorporates:
   *  Constant: '<S428>/Constant10'
   *  Constant: '<S428>/Constant11'
   *  Constant: '<S428>/Constant12'
   *  Constant: '<S428>/Constant13'
   *  Constant: '<S428>/Constant14'
   *  Constant: '<S428>/Constant15'
   *  Constant: '<S428>/Constant5'
   *  Constant: '<S428>/Constant6'
   *  Constant: '<S428>/Constant7'
   *  Constant: '<S428>/Constant8'
   *  Constant: '<S428>/Constant9'
   *  Product: '<S428>/Divide3'
   *  Product: '<S428>/Divide4'
   *  Product: '<S428>/Divide5'
   *  Product: '<S428>/Divide6'
   *  Product: '<S428>/Divide7'
   *  Sum: '<S428>/Add1'
   *  Sum: '<S428>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
               EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
               EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
              (rtb_Divide4_dh - EKF_IFS_2_P.Rtrim) * EKF_IFS_2_P.Clr *
              (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Clda *
             EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cldr *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S432>/Add' incorporates:
   *  Constant: '<S432>/Constant'
   *  Constant: '<S432>/Constant10'
   *  Constant: '<S432>/Constant11'
   *  Constant: '<S432>/Constant12'
   *  Constant: '<S432>/Constant13'
   *  Constant: '<S432>/Constant14'
   *  Constant: '<S432>/Constant15'
   *  Constant: '<S432>/Constant5'
   *  Constant: '<S432>/Constant6'
   *  Constant: '<S432>/Constant8'
   *  Constant: '<S432>/Constant9'
   *  Product: '<S432>/Divide3'
   *  Product: '<S432>/Divide4'
   *  Product: '<S432>/Divide5'
   *  Product: '<S432>/Divide6'
   *  Product: '<S432>/Divide7'
   *  Sum: '<S432>/Add1'
   *  Sum: '<S432>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_niq = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                      EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) /
                      EKF_IFS_2_P.Utrim + EKF_IFS_2_P.Cnb *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) + (rtb_Divide4_dh -
    EKF_IFS_2_P.Rtrim) * EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) /
                     EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cnda *
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) + EKF_IFS_2_P.Cndr *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S427>/Add' incorporates:
   *  Product: '<S427>/Divide3'
   *  Product: '<S427>/Divide5'
   *  Trigonometry: '<S427>/Trigonometric Function'
   *  Trigonometry: '<S427>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Azb * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Product: '<S440>/Divide4' incorporates:
   *  Constant: '<S440>/Ixz'
   */
  rtb_Divide4_jaz = EKF_IFS_2_P.IxzB / rtb_rudder_cmd;

  /* Sum: '<S431>/Add2' incorporates:
   *  Product: '<S431>/Divide1'
   *  Product: '<S431>/Divide6'
   *  Trigonometry: '<S431>/Trigonometric Function4'
   *  Trigonometry: '<S431>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Azb = rtb_Azb * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Divide_niq;

  /* Saturate: '<S492>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S492>/Gain'
   *  Gain: '<S492>/Gain1'
   *  Product: '<S147>/Divide'
   *  Saturate: '<S492>/Throttle Limiter'
   *  Sum: '<S147>/Sum'
   *  Sum: '<S492>/Add'
   */
  rtb_Gain4_c2[0] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                      rtb_Add_b4) - rtb_Add_nv) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;

  /* Saturate: '<S492>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S492>/Gain2'
   *  Gain: '<S492>/Gain3'
   *  Product: '<S147>/Divide'
   *  Saturate: '<S492>/Elevator Limiter'
   *  Sum: '<S147>/Sum'
   *  Sum: '<S492>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[1] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S492>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S492>/Gain4'
   *  Gain: '<S492>/Gain5'
   *  Product: '<S147>/Divide'
   *  Saturate: '<S492>/Aileron Limiter'
   *  Sum: '<S147>/Sum'
   *  Sum: '<S492>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[2] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S492>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S492>/Gain6'
   *  Gain: '<S492>/Gain7'
   *  Product: '<S147>/Divide'
   *  Product: '<S502>/Divide'
   *  Product: '<S507>/Divide'
   *  Saturate: '<S492>/Rudder Limiter'
   *  Sum: '<S147>/Sum'
   *  Sum: '<S492>/Add3'
   *  Sum: '<S502>/Add'
   *  Sum: '<S507>/Add'
   *  Sum: '<S507>/Add1'
   *  Trigonometry: '<S507>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[3] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[4] = (((rtb_Divide3_dt + rtb_Divide4_jbf) + rtb_Divide5_fi2) /
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[5] = (rtb_Divide_hc - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[6] = ((rtb_Divide3_p2 - rtb_Divide4_om) / (rtb_MathFunction_hl +
    rtb_MathFunction1_l0) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) -
                     rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Trigonometry: '<S510>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S510>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_a) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_a;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_n) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_n;
    }
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S495>/Constant1'
   *  Constant: '<S495>/Constant2'
   *  Constant: '<S497>/Constant1'
   *  Constant: '<S497>/Constant2'
   *  Constant: '<S498>/Constant1'
   *  Constant: '<S498>/Constant2'
   *  Constant: '<S511>/Constant'
   *  Constant: '<S512>/Constant'
   *  Constant: '<S531>/Ixx'
   *  Constant: '<S531>/Iyy'
   *  Constant: '<S531>/Izz'
   *  Constant: '<S532>/Ixz'
   *  Constant: '<S532>/Iyy'
   *  Math: '<S497>/Math Function'
   *  Math: '<S497>/Math Function1'
   *  Product: '<S147>/Divide'
   *  Product: '<S495>/Divide1'
   *  Product: '<S495>/Divide5'
   *  Product: '<S495>/Divide6'
   *  Product: '<S497>/Divide2'
   *  Product: '<S497>/Divide3'
   *  Product: '<S497>/Divide5'
   *  Product: '<S497>/Divide6'
   *  Product: '<S498>/Divide1'
   *  Product: '<S498>/Divide5'
   *  Product: '<S498>/Divide6'
   *  Product: '<S510>/Divide1'
   *  Product: '<S510>/Divide2'
   *  Product: '<S510>/Divide4'
   *  Product: '<S513>/Divide2'
   *  Product: '<S513>/Divide4'
   *  Product: '<S531>/Divide4'
   *  Product: '<S532>/Divide4'
   *  Saturate: '<S510>/Saturation'
   *  Sum: '<S147>/Sum'
   *  Sum: '<S495>/Add2'
   *  Sum: '<S497>/Add1'
   *  Sum: '<S497>/Add3'
   *  Sum: '<S498>/Add2'
   *  Sum: '<S510>/Add'
   *  Sum: '<S510>/Add1'
   *  Sum: '<S513>/Add'
   *  Sum: '<S531>/Add'
   *  Trigonometry: '<S510>/Trigonometric Function1'
   *  Trigonometry: '<S510>/Trigonometric Function2'
   *  Trigonometry: '<S513>/Trigonometric Function1'
   *  Trigonometry: '<S513>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[7] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0
                      + EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[8] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                      (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                      (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[9] = ((rtb_Divide4_lez * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                      rtb_Add_n2 + rtb_Add1_ds * EKF_IFS_2_DW.x_est_00_DSTATE_f
                      [10]) - rtb_Add2_lg4) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[10] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) / EKF_IFS_2_P.IyyB
                        * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
                       + rtb_Divide4_lez * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar *
                       rtb_Divide_e5) - rtb_Add1_bmn) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[11] = ((rtb_Divide4_lez * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_a + rtb_Add1_i3 * EKF_IFS_2_DW.x_est_00_DSTATE_f
                       [10]) - rtb_Divide4_in) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[12] = (EKF_IFS_2_P.Constant_Value_e -
                      EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[13] = (EKF_IFS_2_P.Constant_Value_fl -
                      EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  for (i = 0; i < 14; i++) {
    rtb_Gain4_c2[i + 14] = EKF_IFS_2_P.dt * rtb_Divide1_g0[i];
  }

  /* Saturate: '<S222>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S222>/Gain'
   *  Gain: '<S222>/Gain1'
   *  Product: '<S147>/Divide2'
   *  Saturate: '<S222>/Throttle Limiter'
   *  Sum: '<S147>/Sum2'
   *  Sum: '<S222>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[28] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S222>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S222>/Gain2'
   *  Gain: '<S222>/Gain3'
   *  Product: '<S147>/Divide2'
   *  Saturate: '<S222>/Elevator Limiter'
   *  Sum: '<S147>/Sum2'
   *  Sum: '<S222>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[29] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S222>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S222>/Gain4'
   *  Gain: '<S222>/Gain5'
   *  Product: '<S147>/Divide2'
   *  Saturate: '<S222>/Aileron Limiter'
   *  Sum: '<S147>/Sum2'
   *  Sum: '<S222>/Add2'
   */
  rtb_Gain4_c2[30] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                       rtb_Add1_kk) - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S222>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S222>/Gain6'
   *  Gain: '<S222>/Gain7'
   *  Product: '<S147>/Divide2'
   *  Product: '<S232>/Divide'
   *  Product: '<S237>/Divide'
   *  Saturate: '<S222>/Rudder Limiter'
   *  Sum: '<S147>/Sum2'
   *  Sum: '<S222>/Add3'
   *  Sum: '<S232>/Add'
   *  Sum: '<S237>/Add'
   *  Sum: '<S237>/Add1'
   *  Trigonometry: '<S237>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[31] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[32] = (((rtb_Divide3_ppi + rtb_Divide4_m2) + rtb_Divide5_kwv) /
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[33] = (rtb_Divide_mrb - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[34] = ((rtb_Divide3_av - rtb_Divide4_il) / (rtb_MathFunction_e1 +
    rtb_MathFunction1_o5) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) -
                      rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;

  /* Trigonometry: '<S240>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S240>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_d) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_d;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_ne) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_ne;
    }
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S225>/Constant1'
   *  Constant: '<S225>/Constant2'
   *  Constant: '<S227>/Constant1'
   *  Constant: '<S227>/Constant2'
   *  Constant: '<S228>/Constant1'
   *  Constant: '<S228>/Constant2'
   *  Constant: '<S241>/Constant'
   *  Constant: '<S242>/Constant'
   *  Constant: '<S261>/Ixx'
   *  Constant: '<S261>/Iyy'
   *  Constant: '<S261>/Izz'
   *  Constant: '<S262>/Ixz'
   *  Constant: '<S262>/Iyy'
   *  Math: '<S227>/Math Function'
   *  Math: '<S227>/Math Function1'
   *  Product: '<S147>/Divide2'
   *  Product: '<S225>/Divide1'
   *  Product: '<S225>/Divide5'
   *  Product: '<S225>/Divide6'
   *  Product: '<S227>/Divide2'
   *  Product: '<S227>/Divide3'
   *  Product: '<S227>/Divide5'
   *  Product: '<S227>/Divide6'
   *  Product: '<S228>/Divide1'
   *  Product: '<S228>/Divide5'
   *  Product: '<S228>/Divide6'
   *  Product: '<S240>/Divide1'
   *  Product: '<S240>/Divide2'
   *  Product: '<S240>/Divide4'
   *  Product: '<S243>/Divide2'
   *  Product: '<S243>/Divide4'
   *  Product: '<S261>/Divide4'
   *  Product: '<S262>/Divide4'
   *  Saturate: '<S240>/Saturation'
   *  Sum: '<S147>/Sum2'
   *  Sum: '<S225>/Add2'
   *  Sum: '<S227>/Add1'
   *  Sum: '<S227>/Add3'
   *  Sum: '<S228>/Add2'
   *  Sum: '<S240>/Add'
   *  Sum: '<S240>/Add1'
   *  Sum: '<S243>/Add'
   *  Sum: '<S261>/Add'
   *  Trigonometry: '<S240>/Trigonometric Function1'
   *  Trigonometry: '<S240>/Trigonometric Function2'
   *  Trigonometry: '<S243>/Trigonometric Function1'
   *  Trigonometry: '<S243>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[35] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0
                       + EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[36] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[37] = ((rtb_Divide4_fe * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_i + rtb_Add1_gx3 *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Add2_lg4) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[38] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) / EKF_IFS_2_P.IyyB
                        * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
                       + rtb_Divide4_fe * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar *
                       rtb_Divide_a) - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[39] = ((rtb_Divide4_fe * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_em1 + rtb_Add1_an *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[40] = (EKF_IFS_2_P.Constant_Value_jp -
                      EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[41] = (EKF_IFS_2_P.Constant_Value_i -
                      EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;

  /* Saturate: '<S447>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S447>/Gain'
   *  Gain: '<S447>/Gain1'
   *  Product: '<S147>/Divide3'
   *  Saturate: '<S447>/Throttle Limiter'
   *  Sum: '<S147>/Sum3'
   *  Sum: '<S447>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[42] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S447>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S447>/Gain2'
   *  Gain: '<S447>/Gain3'
   *  Product: '<S147>/Divide3'
   *  Saturate: '<S447>/Elevator Limiter'
   *  Sum: '<S147>/Sum3'
   *  Sum: '<S447>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[43] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S447>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S447>/Gain4'
   *  Gain: '<S447>/Gain5'
   *  Product: '<S147>/Divide3'
   *  Saturate: '<S447>/Aileron Limiter'
   *  Sum: '<S147>/Sum3'
   *  Sum: '<S447>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[44] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S447>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S447>/Gain6'
   *  Gain: '<S447>/Gain7'
   *  Product: '<S147>/Divide3'
   *  Product: '<S457>/Divide'
   *  Product: '<S462>/Divide'
   *  Saturate: '<S447>/Rudder Limiter'
   *  Sum: '<S147>/Sum3'
   *  Sum: '<S447>/Add3'
   *  Sum: '<S457>/Add'
   *  Sum: '<S462>/Add'
   *  Sum: '<S462>/Add1'
   *  Trigonometry: '<S462>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[45] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                       rtb_Add1_nj) - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[46] = (((rtb_Divide3_ob + rtb_Divide4_mdl) + rtb_Divide5_mg) /
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[47] = (rtb_Divide_e4 - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[48] = ((rtb_Divide3_jc - rtb_Divide4_gi) / (rtb_MathFunction_bbq
    + rtb_MathFunction1_ea) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) -
                      rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;

  /* Trigonometry: '<S465>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S465>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_ab) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_ab;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_d) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_d;
    }
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S450>/Constant1'
   *  Constant: '<S450>/Constant2'
   *  Constant: '<S452>/Constant1'
   *  Constant: '<S452>/Constant2'
   *  Constant: '<S453>/Constant1'
   *  Constant: '<S453>/Constant2'
   *  Constant: '<S466>/Constant'
   *  Constant: '<S467>/Constant'
   *  Constant: '<S486>/Ixx'
   *  Constant: '<S486>/Iyy'
   *  Constant: '<S486>/Izz'
   *  Constant: '<S487>/Ixz'
   *  Constant: '<S487>/Iyy'
   *  Math: '<S452>/Math Function'
   *  Math: '<S452>/Math Function1'
   *  Product: '<S147>/Divide3'
   *  Product: '<S450>/Divide1'
   *  Product: '<S450>/Divide5'
   *  Product: '<S450>/Divide6'
   *  Product: '<S452>/Divide2'
   *  Product: '<S452>/Divide3'
   *  Product: '<S452>/Divide5'
   *  Product: '<S452>/Divide6'
   *  Product: '<S453>/Divide1'
   *  Product: '<S453>/Divide5'
   *  Product: '<S453>/Divide6'
   *  Product: '<S465>/Divide1'
   *  Product: '<S465>/Divide2'
   *  Product: '<S465>/Divide4'
   *  Product: '<S468>/Divide2'
   *  Product: '<S468>/Divide4'
   *  Product: '<S486>/Divide4'
   *  Product: '<S487>/Divide4'
   *  Saturate: '<S465>/Saturation'
   *  Sum: '<S147>/Sum3'
   *  Sum: '<S450>/Add2'
   *  Sum: '<S452>/Add1'
   *  Sum: '<S452>/Add3'
   *  Sum: '<S453>/Add2'
   *  Sum: '<S465>/Add'
   *  Sum: '<S465>/Add1'
   *  Sum: '<S468>/Add'
   *  Sum: '<S486>/Add'
   *  Trigonometry: '<S465>/Trigonometric Function1'
   *  Trigonometry: '<S465>/Trigonometric Function2'
   *  Trigonometry: '<S468>/Trigonometric Function1'
   *  Trigonometry: '<S468>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[49] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0
                       + EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[50] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[51] = ((rtb_Divide4_lx * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_kw + rtb_Add1_b0 *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Add2_lg4) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[52] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) / EKF_IFS_2_P.IyyB
                        * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
                       + rtb_Divide4_lx * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar *
                       rtb_Divide_p) - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[53] = ((rtb_Divide4_lx * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_fs + rtb_Add1_br4 *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[54] = (EKF_IFS_2_P.Constant_Value_j2 -
                      EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[55] = (EKF_IFS_2_P.Constant_Value_d -
                      EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  for (i = 0; i < 14; i++) {
    rtb_Gain4_c2[i + 56] = EKF_IFS_2_P.dt * rtb_Divide4_bpl[i];
  }

  /* Saturate: '<S582>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S582>/Gain'
   *  Gain: '<S582>/Gain1'
   *  Product: '<S147>/Divide5'
   *  Saturate: '<S582>/Throttle Limiter'
   *  Sum: '<S147>/Sum5'
   *  Sum: '<S582>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[70] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S582>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S582>/Gain2'
   *  Gain: '<S582>/Gain3'
   *  Product: '<S147>/Divide5'
   *  Saturate: '<S582>/Elevator Limiter'
   *  Sum: '<S147>/Sum5'
   *  Sum: '<S582>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[71] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S582>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S582>/Gain4'
   *  Gain: '<S582>/Gain5'
   *  Product: '<S147>/Divide5'
   *  Saturate: '<S582>/Aileron Limiter'
   *  Sum: '<S147>/Sum5'
   *  Sum: '<S582>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[72] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S582>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S582>/Gain6'
   *  Gain: '<S582>/Gain7'
   *  Product: '<S147>/Divide5'
   *  Product: '<S592>/Divide'
   *  Product: '<S597>/Divide'
   *  Saturate: '<S582>/Rudder Limiter'
   *  Sum: '<S147>/Sum5'
   *  Sum: '<S582>/Add3'
   *  Sum: '<S592>/Add'
   *  Sum: '<S597>/Add'
   *  Sum: '<S597>/Add1'
   *  Trigonometry: '<S597>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[73] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[74] = (((rtb_Divide3_cas + rtb_Divide4_gka) + rtb_Divide5_bum) /
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[75] = (rtb_Divide_du - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[76] = ((rtb_Divide3_eun - rtb_Divide4_mz) / (rtb_MathFunction_dx
    + rtb_MathFunction1_jh) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) -
                      rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;

  /* Trigonometry: '<S600>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S600>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_f) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_f;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_f) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_f;
    }
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S585>/Constant1'
   *  Constant: '<S585>/Constant2'
   *  Constant: '<S587>/Constant1'
   *  Constant: '<S587>/Constant2'
   *  Constant: '<S588>/Constant1'
   *  Constant: '<S588>/Constant2'
   *  Constant: '<S601>/Constant'
   *  Constant: '<S602>/Constant'
   *  Constant: '<S621>/Ixx'
   *  Constant: '<S621>/Iyy'
   *  Constant: '<S621>/Izz'
   *  Constant: '<S622>/Ixz'
   *  Constant: '<S622>/Iyy'
   *  Math: '<S587>/Math Function'
   *  Math: '<S587>/Math Function1'
   *  Product: '<S147>/Divide5'
   *  Product: '<S585>/Divide1'
   *  Product: '<S585>/Divide5'
   *  Product: '<S585>/Divide6'
   *  Product: '<S587>/Divide2'
   *  Product: '<S587>/Divide3'
   *  Product: '<S587>/Divide5'
   *  Product: '<S587>/Divide6'
   *  Product: '<S588>/Divide1'
   *  Product: '<S588>/Divide5'
   *  Product: '<S588>/Divide6'
   *  Product: '<S600>/Divide1'
   *  Product: '<S600>/Divide2'
   *  Product: '<S600>/Divide4'
   *  Product: '<S603>/Divide2'
   *  Product: '<S603>/Divide4'
   *  Product: '<S621>/Divide4'
   *  Product: '<S622>/Divide4'
   *  Saturate: '<S600>/Saturation'
   *  Sum: '<S147>/Sum5'
   *  Sum: '<S585>/Add2'
   *  Sum: '<S587>/Add1'
   *  Sum: '<S587>/Add3'
   *  Sum: '<S588>/Add2'
   *  Sum: '<S600>/Add'
   *  Sum: '<S600>/Add1'
   *  Sum: '<S603>/Add'
   *  Sum: '<S621>/Add'
   *  Trigonometry: '<S600>/Trigonometric Function1'
   *  Trigonometry: '<S600>/Trigonometric Function2'
   *  Trigonometry: '<S603>/Trigonometric Function1'
   *  Trigonometry: '<S603>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[77] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0
                       + EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[78] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[79] = ((rtb_Divide4_eb * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_he1 + rtb_Add1_ev *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Add2_lg4) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[80] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) / EKF_IFS_2_P.IyyB
                        * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
                       + rtb_Divide4_eb * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar *
                       rtb_Divide_nzj) - rtb_Add1_bmn) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[81] = ((rtb_Divide4_eb * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_k3 + rtb_Add1_bw *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[82] = (EKF_IFS_2_P.Constant_Value_h4 -
                      EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[83] = (EKF_IFS_2_P.Constant_Value_c -
                      EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;

  /* Saturate: '<S627>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S627>/Gain'
   *  Gain: '<S627>/Gain1'
   *  Product: '<S147>/Divide6'
   *  Saturate: '<S627>/Throttle Limiter'
   *  Sum: '<S147>/Sum6'
   *  Sum: '<S627>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[84] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S627>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S627>/Gain2'
   *  Gain: '<S627>/Gain3'
   *  Product: '<S147>/Divide6'
   *  Saturate: '<S627>/Elevator Limiter'
   *  Sum: '<S147>/Sum6'
   *  Sum: '<S627>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[85] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S627>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S627>/Gain4'
   *  Gain: '<S627>/Gain5'
   *  Product: '<S147>/Divide6'
   *  Saturate: '<S627>/Aileron Limiter'
   *  Sum: '<S147>/Sum6'
   *  Sum: '<S627>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[86] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S627>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S627>/Gain6'
   *  Gain: '<S627>/Gain7'
   *  Product: '<S147>/Divide6'
   *  Product: '<S637>/Divide'
   *  Product: '<S642>/Divide'
   *  Saturate: '<S627>/Rudder Limiter'
   *  Sum: '<S147>/Sum6'
   *  Sum: '<S627>/Add3'
   *  Sum: '<S637>/Add'
   *  Sum: '<S642>/Add'
   *  Sum: '<S642>/Add1'
   *  Trigonometry: '<S642>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[87] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[88] = (((rtb_Divide3_kk + rtb_Divide4_hd) + rtb_Divide5_mk) /
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[89] = (rtb_Divide_ep - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[90] = ((rtb_Divide3_ku - rtb_Divide4_cj) / (rtb_MathFunction_pu +
    rtb_MathFunction1_a) * cos(rtb_Add_nd) - rtb_Divide_bd) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Trigonometry: '<S645>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S645>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_g) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_g;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_j) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_j;
    }
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S630>/Constant1'
   *  Constant: '<S630>/Constant2'
   *  Constant: '<S632>/Constant1'
   *  Constant: '<S632>/Constant2'
   *  Constant: '<S633>/Constant1'
   *  Constant: '<S633>/Constant2'
   *  Constant: '<S646>/Constant'
   *  Constant: '<S647>/Constant'
   *  Constant: '<S666>/Ixx'
   *  Constant: '<S666>/Iyy'
   *  Constant: '<S666>/Izz'
   *  Constant: '<S667>/Ixz'
   *  Constant: '<S667>/Iyy'
   *  Math: '<S632>/Math Function'
   *  Math: '<S632>/Math Function1'
   *  Product: '<S147>/Divide6'
   *  Product: '<S630>/Divide1'
   *  Product: '<S630>/Divide5'
   *  Product: '<S630>/Divide6'
   *  Product: '<S632>/Divide2'
   *  Product: '<S632>/Divide3'
   *  Product: '<S632>/Divide5'
   *  Product: '<S632>/Divide6'
   *  Product: '<S633>/Divide1'
   *  Product: '<S633>/Divide5'
   *  Product: '<S633>/Divide6'
   *  Product: '<S645>/Divide1'
   *  Product: '<S645>/Divide2'
   *  Product: '<S645>/Divide4'
   *  Product: '<S648>/Divide2'
   *  Product: '<S648>/Divide4'
   *  Product: '<S666>/Divide4'
   *  Product: '<S667>/Divide4'
   *  Saturate: '<S645>/Saturation'
   *  Sum: '<S147>/Sum6'
   *  Sum: '<S630>/Add2'
   *  Sum: '<S632>/Add1'
   *  Sum: '<S632>/Add3'
   *  Sum: '<S633>/Add2'
   *  Sum: '<S645>/Add'
   *  Sum: '<S645>/Add1'
   *  Sum: '<S648>/Add'
   *  Sum: '<S666>/Add'
   *  Trigonometry: '<S645>/Trigonometric Function1'
   *  Trigonometry: '<S645>/Trigonometric Function2'
   *  Trigonometry: '<S648>/Trigonometric Function1'
   *  Trigonometry: '<S648>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[91] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0
                       + EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[92] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[93] = ((rtb_Divide4_md * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_jb + rtb_Add1_ca *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Add2_lg4) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[94] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) / EKF_IFS_2_P.IyyB
                        * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
                       + rtb_Divide4_md * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar *
                       rtb_Divide_h5) - rtb_Add1_bmn) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[95] = ((rtb_Divide4_md * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                       rtb_Add_oj + rtb_Add1_ag *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[96] = (EKF_IFS_2_P.Constant_Value_dk -
                      EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[97] = (EKF_IFS_2_P.Constant_Value_e5 -
                      EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;

  /* Saturate: '<S672>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S672>/Gain'
   *  Gain: '<S672>/Gain1'
   *  Product: '<S147>/Divide17'
   *  Saturate: '<S672>/Throttle Limiter'
   *  Sum: '<S147>/Sum7'
   *  Sum: '<S672>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[98] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S672>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S672>/Gain2'
   *  Gain: '<S672>/Gain3'
   *  Product: '<S147>/Divide17'
   *  Saturate: '<S672>/Elevator Limiter'
   *  Sum: '<S147>/Sum7'
   *  Sum: '<S672>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[99] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S672>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S672>/Gain4'
   *  Gain: '<S672>/Gain5'
   *  Product: '<S147>/Divide17'
   *  Saturate: '<S672>/Aileron Limiter'
   *  Sum: '<S147>/Sum7'
   *  Sum: '<S672>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[100] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S672>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S672>/Gain6'
   *  Gain: '<S672>/Gain7'
   *  Product: '<S147>/Divide17'
   *  Product: '<S682>/Divide'
   *  Product: '<S687>/Divide'
   *  Saturate: '<S672>/Rudder Limiter'
   *  Sum: '<S147>/Sum7'
   *  Sum: '<S672>/Add3'
   *  Sum: '<S682>/Add'
   *  Sum: '<S687>/Add'
   *  Sum: '<S687>/Add1'
   *  Trigonometry: '<S687>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[101] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[102] = (((rtb_Divide3_ox + rtb_Divide4_hx) + rtb_Divide5_ps) /
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[103] = (rtb_Divide_el - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[104] = ((rtb_Divide3_cv - rtb_Divide4_ie) / (rtb_MathFunction_ne
    + rtb_MathFunction1_ft) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) -
                       rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;

  /* Trigonometry: '<S690>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S690>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_k) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_k;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_m) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_m;
    }
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S675>/Constant1'
   *  Constant: '<S675>/Constant2'
   *  Constant: '<S677>/Constant1'
   *  Constant: '<S677>/Constant2'
   *  Constant: '<S678>/Constant1'
   *  Constant: '<S678>/Constant2'
   *  Constant: '<S691>/Constant'
   *  Constant: '<S692>/Constant'
   *  Constant: '<S711>/Ixx'
   *  Constant: '<S711>/Iyy'
   *  Constant: '<S711>/Izz'
   *  Constant: '<S712>/Ixz'
   *  Constant: '<S712>/Iyy'
   *  Math: '<S677>/Math Function'
   *  Math: '<S677>/Math Function1'
   *  Product: '<S147>/Divide17'
   *  Product: '<S675>/Divide1'
   *  Product: '<S675>/Divide5'
   *  Product: '<S675>/Divide6'
   *  Product: '<S677>/Divide2'
   *  Product: '<S677>/Divide3'
   *  Product: '<S677>/Divide5'
   *  Product: '<S677>/Divide6'
   *  Product: '<S678>/Divide1'
   *  Product: '<S678>/Divide5'
   *  Product: '<S678>/Divide6'
   *  Product: '<S690>/Divide1'
   *  Product: '<S693>/Divide2'
   *  Product: '<S693>/Divide4'
   *  Product: '<S711>/Divide4'
   *  Product: '<S712>/Divide4'
   *  Saturate: '<S690>/Saturation'
   *  Sum: '<S147>/Sum7'
   *  Sum: '<S675>/Add2'
   *  Sum: '<S677>/Add1'
   *  Sum: '<S677>/Add3'
   *  Sum: '<S678>/Add2'
   *  Sum: '<S690>/Add1'
   *  Sum: '<S693>/Add'
   *  Sum: '<S711>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[105] = ((rtb_Add_gf1 * rtb_x_W1_dot_idx_0 +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[106] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] *
                        rtb_TrigonometricFunction1_dr -
                        rtb_TrigonometricFunction2_aw *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[107] = ((rtb_Divide4_gq * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                        rtb_Add_p0d + rtb_Add1_bg *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Add2_lg4) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[108] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
                        + rtb_Divide4_gq * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar *
                        rtb_Divide_ok) - rtb_Add1_bmn) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[109] = ((rtb_Divide4_gq * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                        rtb_Add_md + rtb_Add1_efz *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[110] = (EKF_IFS_2_P.Constant_Value_n -
                       EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[111] = (EKF_IFS_2_P.Constant_Value_ay -
                       EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;

  /* Saturate: '<S717>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S717>/Gain'
   *  Gain: '<S717>/Gain1'
   *  Product: '<S147>/Divide7'
   *  Saturate: '<S717>/Throttle Limiter'
   *  Sum: '<S147>/Sum8'
   *  Sum: '<S717>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[112] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S717>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S717>/Gain2'
   *  Gain: '<S717>/Gain3'
   *  Product: '<S147>/Divide7'
   *  Saturate: '<S717>/Elevator Limiter'
   *  Sum: '<S147>/Sum8'
   *  Sum: '<S717>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[113] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S717>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S717>/Gain4'
   *  Gain: '<S717>/Gain5'
   *  Product: '<S147>/Divide7'
   *  Saturate: '<S717>/Aileron Limiter'
   *  Sum: '<S147>/Sum8'
   *  Sum: '<S717>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[114] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S717>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S720>/Constant1'
   *  Constant: '<S720>/Constant2'
   *  Constant: '<S722>/Constant1'
   *  Constant: '<S722>/Constant2'
   *  Constant: '<S723>/Constant1'
   *  Constant: '<S723>/Constant2'
   *  Constant: '<S736>/Constant'
   *  Constant: '<S737>/Constant'
   *  Constant: '<S756>/Ixx'
   *  Constant: '<S756>/Iyy'
   *  Constant: '<S756>/Izz'
   *  Constant: '<S757>/Ixz'
   *  Constant: '<S757>/Iyy'
   *  Gain: '<S717>/Gain6'
   *  Gain: '<S717>/Gain7'
   *  Math: '<S722>/Math Function'
   *  Math: '<S722>/Math Function1'
   *  Product: '<S147>/Divide7'
   *  Product: '<S720>/Divide1'
   *  Product: '<S720>/Divide5'
   *  Product: '<S720>/Divide6'
   *  Product: '<S722>/Divide2'
   *  Product: '<S722>/Divide3'
   *  Product: '<S722>/Divide5'
   *  Product: '<S722>/Divide6'
   *  Product: '<S723>/Divide1'
   *  Product: '<S723>/Divide5'
   *  Product: '<S723>/Divide6'
   *  Product: '<S727>/Divide'
   *  Product: '<S732>/Divide'
   *  Product: '<S735>/Divide1'
   *  Product: '<S735>/Divide2'
   *  Product: '<S735>/Divide4'
   *  Product: '<S738>/Divide2'
   *  Product: '<S738>/Divide4'
   *  Product: '<S756>/Divide4'
   *  Product: '<S757>/Divide4'
   *  Saturate: '<S717>/Rudder Limiter'
   *  Sum: '<S147>/Sum8'
   *  Sum: '<S717>/Add3'
   *  Sum: '<S720>/Add2'
   *  Sum: '<S722>/Add1'
   *  Sum: '<S722>/Add3'
   *  Sum: '<S723>/Add2'
   *  Sum: '<S727>/Add'
   *  Sum: '<S732>/Add'
   *  Sum: '<S732>/Add1'
   *  Sum: '<S735>/Add'
   *  Sum: '<S735>/Add1'
   *  Sum: '<S738>/Add'
   *  Sum: '<S756>/Add'
   *  Trigonometry: '<S732>/Trigonometric Function1'
   *  Trigonometry: '<S735>/Trigonometric Function1'
   *  Trigonometry: '<S735>/Trigonometric Function2'
   *  Trigonometry: '<S738>/Trigonometric Function1'
   *  Trigonometry: '<S738>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[115] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[116] = (((rtb_Divide3_ld + rtb_Divide4_lc) + rtb_Divide5_egl) /
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[117] = (rtb_Divide_bas - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[118] = ((rtb_Divide3_n1 - rtb_Divide4_c3) / (rtb_MathFunction_jc
    + rtb_MathFunction1_l) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) -
                       rtb_Divide_bd) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[119] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7])
    * EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_Saturation_i +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) - rtb_Add1_ma) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[120] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[121] = ((rtb_Divide4_lw3 * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                        rtb_Add_dre + rtb_Add1_i1 *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Add2_lg4) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[122] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
                        + rtb_Divide4_lw3 * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar *
                        rtb_Divide_bg) - rtb_Add1_bmn) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[123] = ((rtb_Divide4_lw3 * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                        rtb_Add_adw + rtb_Add1_cf *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[124] = (EKF_IFS_2_P.Constant_Value_hm -
                       EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[125] = (EKF_IFS_2_P.Constant_Value_o -
                       EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;

  /* Saturate: '<S312>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S312>/Gain'
   *  Gain: '<S312>/Gain1'
   *  Product: '<S147>/Divide8'
   *  Saturate: '<S312>/Throttle Limiter'
   *  Sum: '<S147>/Sum9'
   *  Sum: '<S312>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[126] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S312>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S312>/Gain2'
   *  Gain: '<S312>/Gain3'
   *  Product: '<S147>/Divide8'
   *  Saturate: '<S312>/Elevator Limiter'
   *  Sum: '<S147>/Sum9'
   *  Sum: '<S312>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[127] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S312>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S312>/Gain4'
   *  Gain: '<S312>/Gain5'
   *  Product: '<S147>/Divide8'
   *  Saturate: '<S312>/Aileron Limiter'
   *  Sum: '<S147>/Sum9'
   *  Sum: '<S312>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[128] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S312>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S312>/Gain6'
   *  Gain: '<S312>/Gain7'
   *  Product: '<S147>/Divide8'
   *  Product: '<S322>/Divide'
   *  Product: '<S327>/Divide'
   *  Saturate: '<S312>/Rudder Limiter'
   *  Sum: '<S147>/Sum9'
   *  Sum: '<S312>/Add3'
   *  Sum: '<S322>/Add'
   *  Sum: '<S327>/Add'
   *  Sum: '<S327>/Add1'
   *  Trigonometry: '<S327>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[129] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[130] = (((rtb_etaLon + rtb_Divide4_ft) + rtb_Divide5_gk) /
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4] - rtb_Divide_bi) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[131] = (rtb_Divide_l - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[132] = ((rtb_Divide3_iu1 - rtb_Divide4_p3cp) /
                       (rtb_MathFunction_dp + rtb_Divide4_kov) * cos
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) - rtb_Divide_bd) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Trigonometry: '<S330>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S330>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_hr) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_hr;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_p) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_p;
    }
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S315>/Constant1'
   *  Constant: '<S315>/Constant2'
   *  Constant: '<S317>/Constant1'
   *  Constant: '<S317>/Constant2'
   *  Constant: '<S318>/Constant1'
   *  Constant: '<S318>/Constant2'
   *  Constant: '<S331>/Constant'
   *  Constant: '<S332>/Constant'
   *  Constant: '<S351>/Ixx'
   *  Constant: '<S351>/Iyy'
   *  Constant: '<S351>/Izz'
   *  Constant: '<S352>/Ixz'
   *  Constant: '<S352>/Iyy'
   *  Math: '<S317>/Math Function'
   *  Math: '<S317>/Math Function1'
   *  Product: '<S147>/Divide8'
   *  Product: '<S315>/Divide1'
   *  Product: '<S315>/Divide5'
   *  Product: '<S315>/Divide6'
   *  Product: '<S317>/Divide2'
   *  Product: '<S317>/Divide3'
   *  Product: '<S317>/Divide5'
   *  Product: '<S317>/Divide6'
   *  Product: '<S318>/Divide1'
   *  Product: '<S318>/Divide5'
   *  Product: '<S318>/Divide6'
   *  Product: '<S330>/Divide1'
   *  Product: '<S330>/Divide2'
   *  Product: '<S330>/Divide4'
   *  Product: '<S333>/Divide2'
   *  Product: '<S333>/Divide4'
   *  Product: '<S351>/Divide4'
   *  Product: '<S352>/Divide4'
   *  Saturate: '<S330>/Saturation'
   *  Sum: '<S147>/Sum9'
   *  Sum: '<S315>/Add2'
   *  Sum: '<S317>/Add1'
   *  Sum: '<S317>/Add3'
   *  Sum: '<S318>/Add2'
   *  Sum: '<S330>/Add'
   *  Sum: '<S330>/Add1'
   *  Sum: '<S333>/Add'
   *  Sum: '<S351>/Add'
   *  Trigonometry: '<S330>/Trigonometric Function1'
   *  Trigonometry: '<S330>/Trigonometric Function2'
   *  Trigonometry: '<S333>/Trigonometric Function1'
   *  Trigonometry: '<S333>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[133] = (((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7])
    * EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0 + rtb_Add_co) -
                       rtb_Add1_ma) / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[134] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) - rtb_Add_ey) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[135] = ((rtb_Divide4_bv * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                        rtb_Sum5 + rtb_Add1_hkq *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Add2_lg4) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[136] = ((((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * rtb_Add_co * EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
    (rtb_Add_co * rtb_Add_co - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
     EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB))
                        + rtb_Divide4_bv * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar *
                        rtb_Divide_mhp) - rtb_Add1_bmn) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[137] = ((rtb_Divide4_bv * EKF_IFS_2_P.S * EKF_IFS_2_P.b *
                        rtb_aileron_cmd + rtb_TrigonometricFunction1_kv *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[138] = (EKF_IFS_2_P.Constant_Value_mb -
                       EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[139] = (EKF_IFS_2_P.Constant_Value_em -
                       EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;
  for (i = 0; i < 14; i++) {
    rtb_Gain4_c2[i + 140] = EKF_IFS_2_P.dt * rtb_x_est_kk_f[i];
  }

  /* Saturate: '<S402>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S402>/Gain'
   *  Gain: '<S402>/Gain1'
   *  Product: '<S147>/Divide10'
   *  Saturate: '<S402>/Throttle Limiter'
   *  Sum: '<S147>/Sum11'
   *  Sum: '<S402>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[154] = ((EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) - rtb_Add_nv) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S402>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S402>/Gain2'
   *  Gain: '<S402>/Gain3'
   *  Product: '<S147>/Divide10'
   *  Saturate: '<S402>/Elevator Limiter'
   *  Sum: '<S147>/Sum11'
   *  Sum: '<S402>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[155] = ((EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) - rtb_Divide4_d0r) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S402>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S402>/Gain4'
   *  Gain: '<S402>/Gain5'
   *  Product: '<S147>/Divide10'
   *  Saturate: '<S402>/Aileron Limiter'
   *  Sum: '<S147>/Sum11'
   *  Sum: '<S402>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[156] = ((EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) - rtb_f_AILx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Saturate: '<S402>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/delta'
   *  Gain: '<S402>/Gain6'
   *  Gain: '<S402>/Gain7'
   *  Product: '<S147>/Divide10'
   *  Saturate: '<S402>/Rudder Limiter'
   *  Sum: '<S147>/Sum11'
   *  Sum: '<S402>/Add3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain4_c2[157] = ((EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) - rtb_f_RDRx_est_kuk)
    / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[158] = (rtb_Add2_jk - rtb_Divide_bi) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[159] = (rtb_Divide_kts - rtb_Divide) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[160] = (rtb_elevator_cmd - rtb_Divide_bd) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;

  /* Trigonometry: '<S420>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S420>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_e) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_e;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_fj) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_fj;
    }
  }

  /* Gain: '<S147>/Gain4' incorporates:
   *  Constant: '<S147>/Constant'
   *  Constant: '<S147>/delta'
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S405>/Constant1'
   *  Constant: '<S405>/Constant2'
   *  Constant: '<S407>/Constant1'
   *  Constant: '<S407>/Constant2'
   *  Constant: '<S408>/Constant1'
   *  Constant: '<S408>/Constant2'
   *  Constant: '<S421>/Constant'
   *  Constant: '<S422>/Constant'
   *  Constant: '<S430>/Constant'
   *  Constant: '<S430>/Constant1'
   *  Constant: '<S430>/Constant11'
   *  Constant: '<S430>/Constant12'
   *  Constant: '<S430>/Constant13'
   *  Constant: '<S430>/Constant14'
   *  Constant: '<S430>/Constant2'
   *  Constant: '<S430>/Constant3'
   *  Constant: '<S430>/Constant4'
   *  Constant: '<S430>/Constant5'
   *  Constant: '<S430>/Constant6'
   *  Constant: '<S430>/Constant7'
   *  Constant: '<S430>/Constant8'
   *  Constant: '<S430>/Constant9'
   *  Constant: '<S437>/Ixz'
   *  Constant: '<S437>/Iyy'
   *  Constant: '<S437>/Izz'
   *  Constant: '<S439>/Izz'
   *  Constant: '<S441>/Ixx'
   *  Constant: '<S441>/Iyy'
   *  Constant: '<S441>/Izz'
   *  Constant: '<S442>/Ixz'
   *  Constant: '<S442>/Iyy'
   *  Constant: '<S443>/Ixz'
   *  Constant: '<S443>/Iyy'
   *  Constant: '<S444>/Ixx'
   *  Constant: '<S444>/Ixx1'
   *  Constant: '<S444>/Ixz'
   *  Constant: '<S444>/Iyy'
   *  Constant: '<S445>/Ixx'
   *  Gain: '<S430>/Gain1'
   *  Gain: '<S430>/Gain2'
   *  Math: '<S407>/Math Function'
   *  Math: '<S407>/Math Function1'
   *  Math: '<S437>/Math Function'
   *  Math: '<S444>/Math Function'
   *  Product: '<S147>/Divide10'
   *  Product: '<S405>/Divide'
   *  Product: '<S405>/Divide1'
   *  Product: '<S405>/Divide2'
   *  Product: '<S405>/Divide3'
   *  Product: '<S405>/Divide4'
   *  Product: '<S405>/Divide5'
   *  Product: '<S405>/Divide6'
   *  Product: '<S407>/Divide'
   *  Product: '<S407>/Divide2'
   *  Product: '<S407>/Divide3'
   *  Product: '<S407>/Divide5'
   *  Product: '<S407>/Divide6'
   *  Product: '<S408>/Divide'
   *  Product: '<S408>/Divide1'
   *  Product: '<S408>/Divide2'
   *  Product: '<S408>/Divide3'
   *  Product: '<S408>/Divide4'
   *  Product: '<S408>/Divide5'
   *  Product: '<S408>/Divide6'
   *  Product: '<S420>/Divide1'
   *  Product: '<S420>/Divide2'
   *  Product: '<S420>/Divide4'
   *  Product: '<S423>/Divide2'
   *  Product: '<S423>/Divide4'
   *  Product: '<S430>/Divide1'
   *  Product: '<S430>/Divide2'
   *  Product: '<S430>/Divide3'
   *  Product: '<S430>/Divide4'
   *  Product: '<S430>/Divide5'
   *  Product: '<S430>/Divide6'
   *  Product: '<S437>/Divide3'
   *  Product: '<S437>/Divide4'
   *  Product: '<S439>/Divide4'
   *  Product: '<S441>/Divide4'
   *  Product: '<S442>/Divide4'
   *  Product: '<S443>/Divide4'
   *  Product: '<S444>/Divide3'
   *  Product: '<S444>/Divide4'
   *  Product: '<S445>/Divide4'
   *  Saturate: '<S420>/Saturation'
   *  Sum: '<S147>/Sum11'
   *  Sum: '<S405>/Add'
   *  Sum: '<S405>/Add1'
   *  Sum: '<S405>/Add2'
   *  Sum: '<S407>/Add1'
   *  Sum: '<S407>/Add3'
   *  Sum: '<S408>/Add'
   *  Sum: '<S408>/Add1'
   *  Sum: '<S408>/Add2'
   *  Sum: '<S420>/Add'
   *  Sum: '<S420>/Add1'
   *  Sum: '<S423>/Add'
   *  Sum: '<S430>/Add'
   *  Sum: '<S430>/Add1'
   *  Sum: '<S430>/Add2'
   *  Sum: '<S430>/Add3'
   *  Sum: '<S437>/Add'
   *  Sum: '<S437>/Add1'
   *  Sum: '<S441>/Add'
   *  Sum: '<S444>/Add'
   *  Sum: '<S444>/Add1'
   *  Trigonometry: '<S420>/Trigonometric Function1'
   *  Trigonometry: '<S420>/Trigonometric Function2'
   *  Trigonometry: '<S423>/Trigonometric Function1'
   *  Trigonometry: '<S423>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S416>/Unit Delay'
   */
  rtb_Gain4_c2[161] = (((rtb_Divide4_dh * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[7])
    + sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * EKF_IFS_2_DW.x_est_00_DSTATE_f[10])
                        * rtb_x_W1_dot_idx_0 + EKF_IFS_2_DW.x_est_00_DSTATE_f[9])
                       - rtb_Add1_ma) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[162] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * rtb_Divide4_dh) -
                       rtb_Add_ey) / EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[163] = (((((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    rtb_Divide4_dh + rtb_Ayb * EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10] + (EKF_IFS_2_P.IzzB /
    rtb_rudder_cmd * rtb_Add2_c5 + rtb_Divide4_jaz * rtb_Azb) * (rtb_Divide4_ea *
    EKF_IFS_2_P.S * EKF_IFS_2_P.b)) - rtb_Add2_lg4) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[164] = ((((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] -
    EKF_IFS_2_P.Qtrim) * EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
    EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
    EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot * EKF_IFS_2_DW.UnitDelay_DSTATE_f *
    (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.Cmu /
    EKF_IFS_2_P.Utrim * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) +
    EKF_IFS_2_P.Cmde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 /
    EKF_IFS_2_P.Utrim * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1
    * EKF_IFS_2_P.Gain2_Gain_g * EKF_IFS_2_P.Gain1_Gain_mb) *
                        (EKF_IFS_2_P.Ixz_Value_h / EKF_IFS_2_P.IyyB) *
                        (rtb_Divide4_ea * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar) +
                        ((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Divide4_dh -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] -
     rtb_Divide4_dh * rtb_Divide4_dh) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB)))
                       - rtb_Add1_bmn) / EKF_IFS_2_P.delta_Value_i *
    EKF_IFS_2_P.dt;
  rtb_Gain4_c2[165] = (((((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) *
    EKF_IFS_2_P.IxxB + EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_rudder_cmd *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Ayb * rtb_Divide4_dh) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10] + (EKF_IFS_2_P.IxxB /
    rtb_rudder_cmd * rtb_Azb + rtb_Divide4_jaz * rtb_Add2_c5) * (rtb_Divide4_ea *
    EKF_IFS_2_P.S * EKF_IFS_2_P.b)) - rtb_Divide4_in) /
    EKF_IFS_2_P.delta_Value_i * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[166] = (EKF_IFS_2_P.Constant_Value_ew -
                       EKF_IFS_2_P.Constant_Value_b) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;
  rtb_Gain4_c2[167] = (EKF_IFS_2_P.Constant_Value_na -
                       EKF_IFS_2_P.Constant_Value_m) / EKF_IFS_2_P.delta_Value_i
    * EKF_IFS_2_P.dt;
  for (i = 0; i < 14; i++) {
    rtb_Gain4_c2[i + 168] = EKF_IFS_2_P.dt * EKF_IFS_2_P.Constant_Value_lo[i];
  }

  for (i = 0; i < 14; i++) {
    rtb_Gain4_c2[i + 182] = EKF_IFS_2_P.dt * EKF_IFS_2_P.Constant_Value_lo[i];
  }

  /* Product: '<S151>/Matrix Multiply' */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_P_kk1_f[i + 14 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        rtb_P_kk1_f[i + 14 * i_0] += rtb_Gain4_c2[14 * i_1 + i] * rtb_Gain4_c2
          [14 * i_0 + i_1];
      }
    }
  }

  /* End of Product: '<S151>/Matrix Multiply' */

  /* Product: '<S151>/Matrix Multiply1' */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_Product2_fp[i + 14 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        rtb_Product2_fp[i + 14 * i_0] += rtb_P_kk1_f[14 * i_1 + i] *
          rtb_Gain4_c2[14 * i_0 + i_1];
      }
    }
  }

  /* End of Product: '<S151>/Matrix Multiply1' */

  /* Product: '<S151>/Matrix Multiply2' incorporates:
   *  Gain: '<S151>/Gain2'
   */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_Product2_hq[i + 14 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        rtb_Product2_hq[i + 14 * i_0] += rtb_Product2_fp[14 * i_1 + i] *
          rtb_Gain4_c2[14 * i_0 + i_1];
      }
    }
  }

  /* End of Product: '<S151>/Matrix Multiply2' */

  /* Sum: '<S151>/Add' incorporates:
   *  Constant: '<S151>/Constant'
   *  Gain: '<S151>/Gain'
   *  Gain: '<S151>/Gain1'
   *  Gain: '<S151>/Gain2'
   */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_Add_l3[i_0 + 14 * i] = (((EKF_IFS_2_P.Constant_Value_fo[14 * i + i_0]
        + rtb_Gain4_c2[14 * i + i_0]) + rtb_P_kk1_f[14 * i + i_0] *
        EKF_IFS_2_P.Gain_Gain_e) + rtb_Product2_fp[14 * i + i_0] *
        EKF_IFS_2_P.Gain1_Gain_le) + rtb_Product2_hq[14 * i + i_0] *
        EKF_IFS_2_P.Gain2_Gain_jl;
    }
  }

  /* End of Sum: '<S151>/Add' */

  /* Product: '<S143>/Product' incorporates:
   *  MATLAB Function: '<S143>/Transpose'
   *  UnitDelay: '<S143>/P_est_[0//0]'
   */
  /* MATLAB Function 'State Observer Yak54 40\% (subsystem)/State Observer/EKF/K[k] (states)/Transpose': '<S150>:1' */
  /* '<S150>:1:4' */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_Gain4_c2[i + 14 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        rtb_Gain4_c2[i + 14 * i_0] += EKF_IFS_2_DW.P_est_00_DSTATE_n[14 * i_1 +
          i] * rtb_Add_l3[14 * i_1 + i_0];
      }
    }
  }

  /* Sum: '<S143>/Subtract2' incorporates:
   *  Constant: '<S143>/Q_[k-1]'
   *  Product: '<S143>/Product'
   */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      tmp_5 = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        tmp_5 += rtb_Add_l3[14 * i_1 + i] * rtb_Gain4_c2[14 * i_0 + i_1];
      }

      rtb_P_kk1_f[i + 14 * i_0] = EKF_IFS_2_P.Q_obs_sta[14 * i_0 + i] + tmp_5;
    }
  }

  /* End of Sum: '<S143>/Subtract2' */

  /* Sum: '<S791>/Subtract1' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_etaLon = EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[12];

  /* Sum: '<S791>/Subtract2' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum5 = EKF_IFS_2_DW.x_est_00_DSTATE_f[6] + EKF_IFS_2_DW.x_est_00_DSTATE_f
    [13];

  /* Product: '<S148>/Divide' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum'
   *  Sum: '<S798>/Subtract1'
   *  Sum: '<S798>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide_jn[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide_jn[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide_jn[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide1' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum1'
   *  Sum: '<S793>/Subtract1'
   *  Sum: '<S793>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide1_h2s[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide1_h2s[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide1_h2s[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) / EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide2' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum2'
   *  Sum: '<S792>/Subtract1'
   *  Sum: '<S792>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide2_omo[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide2_omo[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide2_omo[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) / EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide3' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum3'
   *  Sum: '<S797>/Subtract1'
   *  Sum: '<S797>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide3_ma[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide3_ma[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide3_ma[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide4' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum4'
   *  Sum: '<S769>/Add1'
   *  Sum: '<S799>/Subtract1'
   *  Sum: '<S799>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_gc[0] = ((EKF_IFS_2_P.delta_Value_a +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide4_gc[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide4_gc[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide5' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum5'
   *  Sum: '<S770>/Add'
   *  Sum: '<S800>/Subtract1'
   *  Sum: '<S800>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide5_l2g[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide5_l2g[1] = (((EKF_IFS_2_P.delta_Value_a +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) -
                        rtb_etaLon) / EKF_IFS_2_P.delta_Value_a;
  rtb_Divide5_l2g[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) / EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide6' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum6'
   *  Sum: '<S772>/Add'
   *  Sum: '<S802>/Subtract1'
   *  Sum: '<S802>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide6_b4[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide6_b4[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide6_b4[2] = (((EKF_IFS_2_P.delta_Value_a +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) + EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) -
                       rtb_Sum5) / EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide17' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum7'
   *  Sum: '<S774>/Add'
   *  Sum: '<S804>/Subtract1'
   *  Sum: '<S804>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide17[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide17[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide17[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide17[3] = ((EKF_IFS_2_P.delta_Value_a +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide17[4] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[8] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide17[5] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide17[6] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide17[7] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide7' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum8'
   *  Sum: '<S775>/Add'
   *  Sum: '<S805>/Subtract1'
   *  Sum: '<S805>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide7_pl[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide7_pl[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide7_pl[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide7_pl[3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[7] -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide7_pl[4] = ((EKF_IFS_2_P.delta_Value_a +
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide7_pl[5] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide7_pl[6] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide7_pl[7] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide8' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum9'
   *  Sum: '<S764>/Add'
   *  Sum: '<S794>/Subtract1'
   *  Sum: '<S794>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide8[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide8[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide8[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide8[3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[7] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide8[4] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[8] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide8[5] = ((EKF_IFS_2_P.delta_Value_a + EKF_IFS_2_DW.x_est_00_DSTATE_f
                     [9]) - EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide8[6] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide8[7] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide9' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum10'
   *  Sum: '<S765>/Add'
   *  Sum: '<S795>/Subtract1'
   *  Sum: '<S795>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide9[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide9[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide9[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide9[3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[7] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide9[4] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[8] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide9[5] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide9[6] = ((EKF_IFS_2_P.delta_Value_a + EKF_IFS_2_DW.x_est_00_DSTATE_f
                     [10]) - EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide9[7] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] -
                    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide10' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum11'
   *  Sum: '<S766>/Add'
   *  Sum: '<S796>/Subtract1'
   *  Sum: '<S796>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide10[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide10[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide10[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide10[3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[7] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide10[4] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[8] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide10[5] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide10[6] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide10[7] = ((EKF_IFS_2_P.delta_Value_a +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide13' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum14'
   *  Sum: '<S771>/Add'
   *  Sum: '<S801>/Subtract1'
   *  Sum: '<S801>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide13[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide13[1] = (((EKF_IFS_2_P.delta_Value_a +
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide13[2] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[6] +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;

  /* Product: '<S148>/Divide12' incorporates:
   *  Constant: '<S148>/delta'
   *  Sum: '<S148>/Sum15'
   *  Sum: '<S773>/Add'
   *  Sum: '<S803>/Subtract1'
   *  Sum: '<S803>/Subtract2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide12[0] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[4]) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide12[1] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[12]) - rtb_etaLon) /
    EKF_IFS_2_P.delta_Value_a;
  rtb_Divide12[2] = (((EKF_IFS_2_P.delta_Value_a +
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[13]) +
                      EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) - rtb_Sum5) /
    EKF_IFS_2_P.delta_Value_a;
  for (i = 0; i < 5; i++) {
    /* Product: '<S148>/Divide' incorporates:
     *  Sum: '<S148>/Sum'
     */
    rtb_Divide_jn[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;

    /* Product: '<S148>/Divide1' incorporates:
     *  Sum: '<S148>/Sum1'
     */
    rtb_Divide1_h2s[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;

    /* Product: '<S148>/Divide2' incorporates:
     *  Sum: '<S148>/Sum2'
     */
    rtb_Divide2_omo[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;

    /* Product: '<S148>/Divide3' incorporates:
     *  Sum: '<S148>/Sum3'
     */
    rtb_Divide3_ma[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;

    /* Product: '<S148>/Divide4' incorporates:
     *  Sum: '<S148>/Sum4'
     */
    rtb_Divide4_gc[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;

    /* Product: '<S148>/Divide5' incorporates:
     *  Sum: '<S148>/Sum5'
     */
    rtb_Divide5_l2g[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;

    /* Product: '<S148>/Divide6' incorporates:
     *  Sum: '<S148>/Sum6'
     */
    rtb_Divide6_b4[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;

    /* Product: '<S148>/Divide13' incorporates:
     *  Sum: '<S148>/Sum14'
     */
    rtb_Divide13[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;
    rtb_Divide12[i + 3] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7] -
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i + 7]) / EKF_IFS_2_P.delta_Value_a;
  }

  /* End of Product: '<S148>/Divide12' */

  /* SignalConversion: '<S807>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S149>/Transpose'
   */
  /* MATLAB Function 'State Observer Yak54 40\% (subsystem)/State Observer/EKF/K[k] (states)/K_[k]/Transpose': '<S807>:1' */
  /* '<S807>:1:4' */
  memcpy(&rtb_Divide_ps[0], &rtb_Divide_jn[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[8], &rtb_Divide1_h2s[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[16], &rtb_Divide2_omo[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[24], &rtb_Divide3_ma[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[32], &rtb_Divide4_gc[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[40], &rtb_Divide5_l2g[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[48], &rtb_Divide6_b4[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[56], &rtb_Divide17[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[64], &rtb_Divide7_pl[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[72], &rtb_Divide8[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[80], &rtb_Divide9[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[88], &rtb_Divide10[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[96], &rtb_Divide13[0], sizeof(real_T) << 3U);
  memcpy(&rtb_Divide_ps[104], &rtb_Divide12[0], sizeof(real_T) << 3U);

  /* MATLAB Function: '<S149>/Transpose' incorporates:
   *  SignalConversion: '<S807>/TmpSignal ConversionAt SFunction Inport1'
   */
  for (i = 0; i < 8; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_HT_k[i_0 + 14 * i] = rtb_Divide_ps[(i_0 << 3) + i];
    }
  }

  /* SignalConversion: '<S149>/TmpSignal ConversionAtProductInport1' */
  memcpy(&rtb_H_k[0], &rtb_Divide_jn[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[8], &rtb_Divide1_h2s[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[16], &rtb_Divide2_omo[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[24], &rtb_Divide3_ma[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[32], &rtb_Divide4_gc[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[40], &rtb_Divide5_l2g[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[48], &rtb_Divide6_b4[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[56], &rtb_Divide17[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[64], &rtb_Divide7_pl[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[72], &rtb_Divide8[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[80], &rtb_Divide9[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[88], &rtb_Divide10[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[96], &rtb_Divide13[0], sizeof(real_T) << 3U);
  memcpy(&rtb_H_k[104], &rtb_Divide12[0], sizeof(real_T) << 3U);

  /* Product: '<S149>/Product' */
  /* MATLAB Function 'State Observer Yak54 40\% (subsystem)/State Observer/EKF/K[k] (states)/K_[k]/Inverse': '<S806>:1' */
  /* '<S806>:1:4' */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_Divide_ps[i + 14 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        rtb_Divide_ps[i + 14 * i_0] += rtb_P_kk1_f[14 * i_1 + i] * rtb_HT_k[14 *
          i_0 + i_1];
      }
    }
  }

  /* Sum: '<S149>/Subtract2' incorporates:
   *  Constant: '<S143>/R_[k]'
   *  Product: '<S149>/Product'
   */
  for (i = 0; i < 8; i++) {
    for (i_0 = 0; i_0 < 8; i_0++) {
      tmp_5 = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        tmp_5 += rtb_H_k[(i_1 << 3) + i] * rtb_Divide_ps[14 * i_0 + i_1];
      }

      rtb_H_k_1[i + (i_0 << 3)] = EKF_IFS_2_P.R_obs_sta[(i_0 << 3) + i] + tmp_5;
    }
  }

  memcpy(&rtb_H_k_0[0], &rtb_H_k_1[0], sizeof(real_T) << 6U);

  /* End of Sum: '<S149>/Subtract2' */

  /* MATLAB Function: '<S149>/Inverse' */
  EKF_IFS_2_invNxN_i(rtb_H_k_0, rtb_H_k_1);

  /* Product: '<S149>/Product1' */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_Divide_ps[i + 14 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 8; i_1++) {
        rtb_Divide_ps[i + 14 * i_0] += rtb_HT_k[14 * i_1 + i] * rtb_H_k_1[(i_0 <<
          3) + i_1];
      }
    }
  }

  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_Product1_f[i + 14 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        rtb_Product1_f[i + 14 * i_0] += rtb_P_kk1_f[14 * i_1 + i] *
          rtb_Divide_ps[14 * i_0 + i_1];
      }
    }
  }

  /* End of Product: '<S149>/Product1' */

  /* Product: '<S815>/Divide2' incorporates:
   *  Trigonometry: '<S815>/Trigonometric Function'
   *  Trigonometry: '<S815>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_throttle_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S817>/Divide2' incorporates:
   *  Trigonometry: '<S817>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_elevator_cmd = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S820>/Divide2' incorporates:
   *  Trigonometry: '<S820>/Trigonometric Function'
   *  Trigonometry: '<S820>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Sum8 = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[6]);

  /* Product: '<S812>/Divide4' incorporates:
   *  Constant: '<S812>/Constant'
   *  Constant: '<S812>/Constant1'
   *  Math: '<S812>/Math Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_dh = EKF_IFS_2_P.Constant_Value_d0 * EKF_IFS_2_P.rho_o *
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * EKF_IFS_2_DW.x_est_00_DSTATE_f[4]);

  /* Sum: '<S831>/Add' incorporates:
   *  Constant: '<S831>/Constant'
   *  Constant: '<S831>/Constant1'
   *  Constant: '<S831>/Constant10'
   *  Constant: '<S831>/Constant11'
   *  Constant: '<S831>/Constant12'
   *  Constant: '<S831>/Constant13'
   *  Constant: '<S831>/Constant14'
   *  Constant: '<S831>/Constant15'
   *  Constant: '<S831>/Constant2'
   *  Constant: '<S831>/Constant3'
   *  Constant: '<S831>/Constant4'
   *  Constant: '<S831>/Constant5'
   *  Constant: '<S831>/Constant6'
   *  Constant: '<S831>/Constant7'
   *  Constant: '<S831>/Constant8'
   *  Constant: '<S831>/Constant9'
   *  Gain: '<S831>/Gain1'
   *  Gain: '<S831>/Gain2'
   *  Gain: '<S831>/Gain3'
   *  Product: '<S831>/Divide1'
   *  Product: '<S831>/Divide2'
   *  Product: '<S831>/Divide3'
   *  Product: '<S831>/Divide4'
   *  Product: '<S831>/Divide5'
   *  Product: '<S831>/Divide6'
   *  Product: '<S831>/Divide7'
   *  Sum: '<S831>/Add1'
   *  Sum: '<S831>/Add2'
   *  Sum: '<S831>/Add3'
   *  Sum: '<S831>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S822>/Unit Delay'
   */
  rtb_Add_lzz = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                     EKF_IFS_2_P.CLq * (EKF_IFS_2_P.Cbar / 2.0) /
                     EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.CLa *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5] + EKF_IFS_2_P.CL0)) + EKF_IFS_2_P.CLadot *
                    EKF_IFS_2_DW.UnitDelay_DSTATE_di * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CLu / EKF_IFS_2_P.Utrim *
                   (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CLde *
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                 (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                 EKF_IFS_2_P.Gain2_Gain_ge * EKF_IFS_2_P.Gain1_Gain_dx) +
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CD1 * EKF_IFS_2_P.Gain3_Gain_mb;

  /* ManualSwitch: '<S830>/Manual Switch' incorporates:
   *  Constant: '<S830>/AR'
   *  Constant: '<S830>/Constant15'
   *  Constant: '<S830>/Constant16'
   *  Constant: '<S830>/Constant17'
   *  Constant: '<S830>/Constant18'
   *  Constant: '<S830>/e'
   *  Math: '<S830>/Math Function'
   *  Product: '<S830>/Divide8'
   *  Product: '<S830>/Divide9'
   *  Sum: '<S830>/Add5'
   *  Sum: '<S830>/Add6'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_lx == 1) {
    rtb_Axb = EKF_IFS_2_P.CDa * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
      EKF_IFS_2_P.CD0;
  } else {
    rtb_Axb = rtb_Add_lzz * rtb_Add_lzz / EKF_IFS_2_P.Constant15_Value_pw /
      (EKF_IFS_2_P.b / EKF_IFS_2_P.Cbar) / EKF_IFS_2_P.e_Value_p +
      EKF_IFS_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S830>/Manual Switch' */

  /* Sum: '<S830>/Add' incorporates:
   *  Constant: '<S830>/Constant1'
   *  Constant: '<S830>/Constant10'
   *  Constant: '<S830>/Constant11'
   *  Constant: '<S830>/Constant12'
   *  Constant: '<S830>/Constant13'
   *  Constant: '<S830>/Constant14'
   *  Constant: '<S830>/Constant2'
   *  Constant: '<S830>/Constant3'
   *  Constant: '<S830>/Constant4'
   *  Constant: '<S830>/Constant6'
   *  Constant: '<S830>/Constant7'
   *  Constant: '<S830>/Constant8'
   *  Constant: '<S830>/Constant9'
   *  Gain: '<S830>/Gain1'
   *  Gain: '<S830>/Gain2'
   *  Gain: '<S830>/Gain3'
   *  Product: '<S830>/Divide1'
   *  Product: '<S830>/Divide2'
   *  Product: '<S830>/Divide3'
   *  Product: '<S830>/Divide5'
   *  Product: '<S830>/Divide6'
   *  Product: '<S830>/Divide7'
   *  Sum: '<S830>/Add1'
   *  Sum: '<S830>/Add2'
   *  Sum: '<S830>/Add3'
   *  Sum: '<S830>/Add4'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S822>/Unit Delay'
   */
  rtb_Add_iq = ((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] - EKF_IFS_2_P.Qtrim) *
                    EKF_IFS_2_P.CDq * (EKF_IFS_2_P.Cbar / 2.0) /
                    EKF_IFS_2_P.Utrim + rtb_Axb) + EKF_IFS_2_P.CDadot *
                   EKF_IFS_2_DW.UnitDelay_DSTATE_di * (EKF_IFS_2_P.Cbar / 2.0) /
                   EKF_IFS_2_P.Utrim) + EKF_IFS_2_P.CDu / EKF_IFS_2_P.Utrim *
                  (rtb_throttle_cmd - EKF_IFS_2_P.Utrim)) + EKF_IFS_2_P.CDde *
                 EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 / EKF_IFS_2_P.Utrim *
                (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.CL1 *
                EKF_IFS_2_P.Gain2_Gain_kzv * EKF_IFS_2_P.Gain1_Gain_iz) -
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5] - EKF_IFS_2_P.alphatrim) *
    EKF_IFS_2_P.CL1 * EKF_IFS_2_P.Gain3_Gain_a4;

  /* ManualSwitch: '<S816>/Manual Switch' incorporates:
   *  Constant: '<S816>/Constant1'
   *  Constant: '<S824>/Constant'
   *  Constant: '<S842>/Constant'
   *  Constant: '<S842>/Constant1'
   *  Constant: '<S842>/Constant2'
   *  Math: '<S842>/Math Function'
   *  Product: '<S816>/Divide'
   *  Product: '<S816>/Divide5'
   *  Product: '<S839>/Divide3'
   *  Product: '<S839>/Divide5'
   *  Product: '<S842>/Divide1'
   *  Product: '<S842>/Divide2'
   *  Sum: '<S816>/Add'
   *  Sum: '<S839>/Add'
   *  Sum: '<S842>/Add'
   *  Trigonometry: '<S839>/Trigonometric Function'
   *  Trigonometry: '<S839>/Trigonometric Function3'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_hp == 1) {
    /* Gain: '<S842>/Gain' incorporates:
     *  UnitDelay: '<S142>/x_est_[0//0]'
     */
    rtb_Gain_cl = EKF_IFS_2_P.Gain_Gain_f3 * EKF_IFS_2_DW.x_est_00_DSTATE_f[0];
    rtb_Axb = (((rtb_Gain_cl * rtb_Gain_cl * EKF_IFS_2_P.xT2 + EKF_IFS_2_P.xT1 *
                 rtb_Gain_cl) + EKF_IFS_2_P.xT0) + (sin
                (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz - rtb_Add_iq *
                cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) * (rtb_Divide4_dh *
                EKF_IFS_2_P.S)) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Axb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4];
  }

  /* End of ManualSwitch: '<S816>/Manual Switch' */

  /* Sum: '<S816>/Add1' incorporates:
   *  Constant: '<S816>/Constant'
   *  Product: '<S816>/Divide2'
   *  Product: '<S816>/Divide3'
   *  Product: '<S816>/Divide4'
   *  Trigonometry: '<S816>/Trigonometric Function'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_rudder_cmd = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_elevator_cmd -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_Sum8) - sin
                    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g) +
    rtb_Axb;

  /* ManualSwitch: '<S819>/Manual Switch' incorporates:
   *  Constant: '<S819>/Constant1'
   *  Constant: '<S824>/Constant'
   *  Constant: '<S832>/Constant'
   *  Constant: '<S832>/Constant1'
   *  Constant: '<S832>/Constant10'
   *  Constant: '<S832>/Constant11'
   *  Constant: '<S832>/Constant12'
   *  Constant: '<S832>/Constant2'
   *  Constant: '<S832>/Constant3'
   *  Constant: '<S832>/Constant4'
   *  Constant: '<S832>/Constant5'
   *  Constant: '<S832>/Constant6'
   *  Constant: '<S832>/Constant8'
   *  Product: '<S819>/Divide'
   *  Product: '<S819>/Divide5'
   *  Product: '<S832>/Divide1'
   *  Product: '<S832>/Divide3'
   *  Product: '<S832>/Divide4'
   *  Product: '<S832>/Divide5'
   *  Product: '<S832>/Divide6'
   *  Sum: '<S832>/Add'
   *  Sum: '<S832>/Add1'
   *  Sum: '<S832>/Add2'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_og == 1) {
    rtb_Ayb = (((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                  EKF_IFS_2_P.Cyp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                  EKF_IFS_2_P.Cyb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                 EKF_IFS_2_P.Cyr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                EKF_IFS_2_P.Cyda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
               EKF_IFS_2_P.Cydr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) *
      (rtb_Divide4_dh * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Ayb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5];
  }

  /* End of ManualSwitch: '<S819>/Manual Switch' */

  /* Sum: '<S819>/Add1' incorporates:
   *  Constant: '<S819>/Constant'
   *  Product: '<S819>/Divide2'
   *  Product: '<S819>/Divide3'
   *  Product: '<S819>/Divide4'
   *  Trigonometry: '<S819>/Trigonometric Function'
   *  Trigonometry: '<S819>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_jk = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_Sum8 -
                  EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * rtb_throttle_cmd) + sin
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos
                 (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g) + rtb_Ayb;

  /* Product: '<S818>/Divide4' */
  rtb_Divide4_ot = rtb_elevator_cmd * rtb_Add2_jk;

  /* ManualSwitch: '<S821>/Manual Switch' incorporates:
   *  Constant: '<S821>/Constant1'
   *  Constant: '<S824>/Constant'
   *  Product: '<S821>/Divide'
   *  Product: '<S821>/Divide5'
   *  Product: '<S841>/Divide1'
   *  Product: '<S841>/Divide6'
   *  Sum: '<S841>/Add2'
   *  Trigonometry: '<S841>/Trigonometric Function4'
   *  Trigonometry: '<S841>/Trigonometric Function5'
   *  UnitDelay: '<S142>/Unit Delay1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  if (EKF_IFS_2_P.ManualSwitch_CurrentSetting_e2 == 1) {
    rtb_Azb = ((0.0 - rtb_Add_iq * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5])) - cos
               (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add_lzz) *
      (rtb_Divide4_dh * EKF_IFS_2_P.S) / (EKF_IFS_2_P.weight / EKF_IFS_2_P.g);
  } else {
    rtb_Azb = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6];
  }

  /* End of ManualSwitch: '<S821>/Manual Switch' */

  /* Sum: '<S821>/Add1' incorporates:
   *  Constant: '<S821>/Constant'
   *  Product: '<S821>/Divide2'
   *  Product: '<S821>/Divide3'
   *  Product: '<S821>/Divide4'
   *  Trigonometry: '<S821>/Trigonometric Function'
   *  Trigonometry: '<S821>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide4_in = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * rtb_throttle_cmd -
                     EKF_IFS_2_DW.x_est_00_DSTATE_f[9] * rtb_elevator_cmd) + cos
                    (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) * cos
                    (EKF_IFS_2_DW.x_est_00_DSTATE_f[8]) * EKF_IFS_2_P.g) +
    rtb_Azb;

  /* Product: '<S818>/Divide5' */
  rtb_Add_lzz = rtb_Sum8 * rtb_Divide4_in;

  /* Product: '<S822>/Divide' incorporates:
   *  Math: '<S822>/Math Function'
   *  Math: '<S822>/Math Function1'
   *  Product: '<S822>/Divide3'
   *  Product: '<S822>/Divide4'
   *  Sum: '<S822>/Add'
   *  Sum: '<S822>/Add1'
   */
  rtb_Divide_mhp = (rtb_throttle_cmd * rtb_Divide4_in - rtb_Sum8 *
                    rtb_rudder_cmd) / (rtb_throttle_cmd * rtb_throttle_cmd +
    rtb_Sum8 * rtb_Sum8);

  /* Product: '<S823>/Divide3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_iq = EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_Add2_jk;

  /* Product: '<S823>/Divide4' incorporates:
   *  Product: '<S823>/Divide1'
   *  Product: '<S823>/Divide2'
   *  Product: '<S823>/Divide5'
   *  Product: '<S823>/Divide6'
   *  Sum: '<S823>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Gain_cl = ((rtb_throttle_cmd * rtb_rudder_cmd + rtb_elevator_cmd *
                  rtb_Add2_jk) + rtb_Sum8 * rtb_Divide4_in) /
    EKF_IFS_2_DW.x_est_00_DSTATE_f[4] * rtb_elevator_cmd;

  /* Sum: '<S852>/Add' incorporates:
   *  Constant: '<S852>/Ixx1'
   *  Constant: '<S852>/Ixz1'
   *  Constant: '<S852>/Izz1'
   *  Math: '<S852>/Math Function'
   *  Product: '<S852>/Divide1'
   */
  rtb_Add2_jk = EKF_IFS_2_P.IxxB * EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB *
    EKF_IFS_2_P.IxzB;

  /* Product: '<S844>/Divide4' incorporates:
   *  Constant: '<S844>/Ixx'
   *  Constant: '<S844>/Ixz'
   *  Constant: '<S844>/Iyy'
   *  Constant: '<S844>/Izz'
   *  Product: '<S844>/Divide3'
   *  Sum: '<S844>/Add'
   */
  rtb_Divide4_in = ((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) + EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IxzB / rtb_Add2_jk;

  /* Sum: '<S834>/Add' incorporates:
   *  Constant: '<S834>/Constant10'
   *  Constant: '<S834>/Constant11'
   *  Constant: '<S834>/Constant12'
   *  Constant: '<S834>/Constant13'
   *  Constant: '<S834>/Constant14'
   *  Constant: '<S834>/Constant15'
   *  Constant: '<S834>/Constant5'
   *  Constant: '<S834>/Constant6'
   *  Constant: '<S834>/Constant7'
   *  Constant: '<S834>/Constant8'
   *  Constant: '<S834>/Constant9'
   *  Product: '<S834>/Divide3'
   *  Product: '<S834>/Divide4'
   *  Product: '<S834>/Divide5'
   *  Product: '<S834>/Divide6'
   *  Product: '<S834>/Divide7'
   *  Sum: '<S834>/Add1'
   *  Sum: '<S834>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                   EKF_IFS_2_P.Clp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim +
                   EKF_IFS_2_P.Clb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                  (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                  EKF_IFS_2_P.Clr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim) +
                 EKF_IFS_2_P.Clda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cldr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S838>/Add' incorporates:
   *  Constant: '<S838>/Constant'
   *  Constant: '<S838>/Constant10'
   *  Constant: '<S838>/Constant11'
   *  Constant: '<S838>/Constant12'
   *  Constant: '<S838>/Constant13'
   *  Constant: '<S838>/Constant14'
   *  Constant: '<S838>/Constant15'
   *  Constant: '<S838>/Constant5'
   *  Constant: '<S838>/Constant6'
   *  Constant: '<S838>/Constant8'
   *  Constant: '<S838>/Constant9'
   *  Product: '<S838>/Divide3'
   *  Product: '<S838>/Divide4'
   *  Product: '<S838>/Divide5'
   *  Product: '<S838>/Divide6'
   *  Product: '<S838>/Divide7'
   *  Sum: '<S838>/Add1'
   *  Sum: '<S838>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_lg4 = ((((EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_P.Ptrim) *
                    EKF_IFS_2_P.Cnp * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim
                    + EKF_IFS_2_P.Cnb * EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) +
                   (EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - EKF_IFS_2_P.Rtrim) *
                   EKF_IFS_2_P.Cnr * (EKF_IFS_2_P.b / 2.0) / EKF_IFS_2_P.Utrim)
                  + EKF_IFS_2_P.Cnda * EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) +
    EKF_IFS_2_P.Cndr * EKF_IFS_2_DW.x_est_00_DSTATE_f[3];

  /* Sum: '<S833>/Add' incorporates:
   *  Product: '<S833>/Divide3'
   *  Product: '<S833>/Divide5'
   *  Trigonometry: '<S833>/Trigonometric Function'
   *  Trigonometry: '<S833>/Trigonometric Function3'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add_nv = rtb_Add2_c5 * cos(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) - sin
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add2_lg4;

  /* Product: '<S846>/Divide4' incorporates:
   *  Constant: '<S846>/Ixz'
   */
  rtb_Divide4_d0r = EKF_IFS_2_P.IxzB / rtb_Add2_jk;

  /* Sum: '<S837>/Add2' incorporates:
   *  Product: '<S837>/Divide1'
   *  Product: '<S837>/Divide6'
   *  Trigonometry: '<S837>/Trigonometric Function4'
   *  Trigonometry: '<S837>/Trigonometric Function5'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Add2_c5 = rtb_Add2_c5 * sin(EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) + cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[5]) * rtb_Add2_lg4;

  /* Saturate: '<S808>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] > EKF_IFS_2_P.ThrottleMax) {
    tmp_5 = EKF_IFS_2_P.ThrottleMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] < EKF_IFS_2_P.ThrottleMin) {
    tmp_5 = EKF_IFS_2_P.ThrottleMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0];
  }

  /* Sum: '<S144>/Subtract1' incorporates:
   *  Gain: '<S144>/Gain4'
   *  Gain: '<S808>/Gain'
   *  Gain: '<S808>/Gain1'
   *  Saturate: '<S808>/Throttle Limiter'
   *  Sum: '<S808>/Add'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide1_g0[0] = (EKF_IFS_2_P.Bthrottle * tmp_5 + EKF_IFS_2_P.Athrottle *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[0]) * EKF_IFS_2_P.dt +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[0];

  /* Saturate: '<S808>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] > EKF_IFS_2_P.ElevatorMax) {
    tmp_5 = EKF_IFS_2_P.ElevatorMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] < EKF_IFS_2_P.ElevatorMin) {
    tmp_5 = EKF_IFS_2_P.ElevatorMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1];
  }

  /* Sum: '<S144>/Subtract1' incorporates:
   *  Gain: '<S144>/Gain4'
   *  Gain: '<S808>/Gain2'
   *  Gain: '<S808>/Gain3'
   *  Saturate: '<S808>/Elevator Limiter'
   *  Sum: '<S808>/Add1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide1_g0[1] = (EKF_IFS_2_P.Belevator * tmp_5 + EKF_IFS_2_P.Aelevator *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) * EKF_IFS_2_P.dt +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[1];

  /* Saturate: '<S808>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] > EKF_IFS_2_P.AileronMax) {
    tmp_5 = EKF_IFS_2_P.AileronMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] < EKF_IFS_2_P.AileronMin) {
    tmp_5 = EKF_IFS_2_P.AileronMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2];
  }

  /* Sum: '<S144>/Subtract1' incorporates:
   *  Gain: '<S144>/Gain4'
   *  Gain: '<S808>/Gain4'
   *  Gain: '<S808>/Gain5'
   *  Saturate: '<S808>/Aileron Limiter'
   *  Sum: '<S808>/Add2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide1_g0[2] = (EKF_IFS_2_P.Baileron * tmp_5 + EKF_IFS_2_P.Aaileron *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[2]) * EKF_IFS_2_P.dt +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[2];

  /* Saturate: '<S808>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S142>/Unit Delay1'
   */
  if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] > EKF_IFS_2_P.RudderMax) {
    tmp_5 = EKF_IFS_2_P.RudderMax;
  } else if (EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] < EKF_IFS_2_P.RudderMin) {
    tmp_5 = EKF_IFS_2_P.RudderMin;
  } else {
    tmp_5 = EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3];
  }

  /* Sum: '<S144>/Subtract1' incorporates:
   *  Gain: '<S144>/Gain4'
   *  Gain: '<S808>/Gain6'
   *  Gain: '<S808>/Gain7'
   *  Math: '<S823>/Math Function'
   *  Math: '<S823>/Math Function1'
   *  Product: '<S818>/Divide'
   *  Product: '<S818>/Divide3'
   *  Product: '<S823>/Divide'
   *  Saturate: '<S808>/Rudder Limiter'
   *  Sum: '<S808>/Add3'
   *  Sum: '<S818>/Add'
   *  Sum: '<S823>/Add'
   *  Sum: '<S823>/Add1'
   *  Trigonometry: '<S823>/Trigonometric Function1'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_Divide1_g0[3] = (EKF_IFS_2_P.Brudder * tmp_5 + EKF_IFS_2_P.Arudder *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[3]) * EKF_IFS_2_P.dt +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[3];
  rtb_Divide1_g0[4] = ((rtb_throttle_cmd * rtb_rudder_cmd + rtb_Divide4_ot) +
                       rtb_Add_lzz) / EKF_IFS_2_DW.x_est_00_DSTATE_f[4] *
    EKF_IFS_2_P.dt + EKF_IFS_2_DW.x_est_00_DSTATE_f[4];
  rtb_Divide1_g0[5] = EKF_IFS_2_P.dt * rtb_Divide_mhp +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[5];
  rtb_Divide1_g0[6] = (rtb_Add_iq - rtb_Gain_cl) / (rtb_throttle_cmd *
    rtb_throttle_cmd + rtb_Sum8 * rtb_Sum8) * cos
    (EKF_IFS_2_DW.x_est_00_DSTATE_f[6]) * EKF_IFS_2_P.dt +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[6];

  /* Trigonometry: '<S826>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S142>/x_est_[0//0]'
   */
  rtb_x_W1_dot_idx_0 = tan(EKF_IFS_2_DW.x_est_00_DSTATE_f[8]);

  /* Saturate: '<S826>/Saturation' */
  if (rtb_x_W1_dot_idx_0 > EKF_IFS_2_P.Saturation_UpperSat_l) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_UpperSat_l;
  } else {
    if (rtb_x_W1_dot_idx_0 < EKF_IFS_2_P.Saturation_LowerSat_l) {
      rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Saturation_LowerSat_l;
    }
  }

  /* Sum: '<S144>/Subtract1' incorporates:
   *  Constant: '<S811>/Constant1'
   *  Constant: '<S811>/Constant2'
   *  Constant: '<S813>/Constant1'
   *  Constant: '<S813>/Constant2'
   *  Constant: '<S814>/Constant1'
   *  Constant: '<S814>/Constant2'
   *  Constant: '<S827>/Constant'
   *  Constant: '<S828>/Constant'
   *  Constant: '<S836>/Constant'
   *  Constant: '<S836>/Constant1'
   *  Constant: '<S836>/Constant11'
   *  Constant: '<S836>/Constant12'
   *  Constant: '<S836>/Constant13'
   *  Constant: '<S836>/Constant14'
   *  Constant: '<S836>/Constant2'
   *  Constant: '<S836>/Constant3'
   *  Constant: '<S836>/Constant4'
   *  Constant: '<S836>/Constant5'
   *  Constant: '<S836>/Constant6'
   *  Constant: '<S836>/Constant7'
   *  Constant: '<S836>/Constant8'
   *  Constant: '<S836>/Constant9'
   *  Constant: '<S843>/Ixz'
   *  Constant: '<S843>/Iyy'
   *  Constant: '<S843>/Izz'
   *  Constant: '<S845>/Izz'
   *  Constant: '<S847>/Ixx'
   *  Constant: '<S847>/Iyy'
   *  Constant: '<S847>/Izz'
   *  Constant: '<S848>/Ixz'
   *  Constant: '<S848>/Iyy'
   *  Constant: '<S849>/Ixz'
   *  Constant: '<S849>/Iyy'
   *  Constant: '<S850>/Ixx'
   *  Constant: '<S850>/Ixx1'
   *  Constant: '<S850>/Ixz'
   *  Constant: '<S850>/Iyy'
   *  Constant: '<S851>/Ixx'
   *  Gain: '<S144>/Gain4'
   *  Gain: '<S836>/Gain1'
   *  Gain: '<S836>/Gain2'
   *  Math: '<S813>/Math Function'
   *  Math: '<S813>/Math Function1'
   *  Math: '<S843>/Math Function'
   *  Math: '<S850>/Math Function'
   *  Product: '<S811>/Divide'
   *  Product: '<S811>/Divide1'
   *  Product: '<S811>/Divide2'
   *  Product: '<S811>/Divide3'
   *  Product: '<S811>/Divide4'
   *  Product: '<S811>/Divide5'
   *  Product: '<S811>/Divide6'
   *  Product: '<S813>/Divide'
   *  Product: '<S813>/Divide2'
   *  Product: '<S813>/Divide3'
   *  Product: '<S813>/Divide5'
   *  Product: '<S813>/Divide6'
   *  Product: '<S814>/Divide'
   *  Product: '<S814>/Divide1'
   *  Product: '<S814>/Divide2'
   *  Product: '<S814>/Divide3'
   *  Product: '<S814>/Divide4'
   *  Product: '<S814>/Divide5'
   *  Product: '<S814>/Divide6'
   *  Product: '<S826>/Divide1'
   *  Product: '<S826>/Divide2'
   *  Product: '<S826>/Divide4'
   *  Product: '<S829>/Divide2'
   *  Product: '<S829>/Divide4'
   *  Product: '<S836>/Divide1'
   *  Product: '<S836>/Divide2'
   *  Product: '<S836>/Divide3'
   *  Product: '<S836>/Divide4'
   *  Product: '<S836>/Divide5'
   *  Product: '<S836>/Divide6'
   *  Product: '<S843>/Divide3'
   *  Product: '<S843>/Divide4'
   *  Product: '<S845>/Divide4'
   *  Product: '<S847>/Divide4'
   *  Product: '<S848>/Divide4'
   *  Product: '<S849>/Divide4'
   *  Product: '<S850>/Divide3'
   *  Product: '<S850>/Divide4'
   *  Product: '<S851>/Divide4'
   *  Saturate: '<S826>/Saturation'
   *  Sum: '<S811>/Add'
   *  Sum: '<S811>/Add1'
   *  Sum: '<S811>/Add2'
   *  Sum: '<S813>/Add1'
   *  Sum: '<S813>/Add3'
   *  Sum: '<S814>/Add'
   *  Sum: '<S814>/Add1'
   *  Sum: '<S814>/Add2'
   *  Sum: '<S826>/Add'
   *  Sum: '<S826>/Add1'
   *  Sum: '<S829>/Add'
   *  Sum: '<S836>/Add'
   *  Sum: '<S836>/Add1'
   *  Sum: '<S836>/Add2'
   *  Sum: '<S836>/Add3'
   *  Sum: '<S843>/Add'
   *  Sum: '<S843>/Add1'
   *  Sum: '<S847>/Add'
   *  Sum: '<S850>/Add'
   *  Sum: '<S850>/Add1'
   *  Trigonometry: '<S826>/Trigonometric Function1'
   *  Trigonometry: '<S826>/Trigonometric Function2'
   *  Trigonometry: '<S829>/Trigonometric Function1'
   *  Trigonometry: '<S829>/Trigonometric Function2'
   *  UnitDelay: '<S142>/x_est_[0//0]'
   *  UnitDelay: '<S822>/Unit Delay'
   */
  rtb_Divide1_g0[7] = ((EKF_IFS_2_DW.x_est_00_DSTATE_f[11] * cos
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) + sin
                        (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[10]) * rtb_x_W1_dot_idx_0
                       + EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) * EKF_IFS_2_P.dt +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[7];
  rtb_Divide1_g0[8] = (EKF_IFS_2_DW.x_est_00_DSTATE_f[10] * cos
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) - sin
                       (EKF_IFS_2_DW.x_est_00_DSTATE_f[7]) *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * EKF_IFS_2_P.dt +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[8];
  rtb_Divide1_g0[9] = ((((EKF_IFS_2_P.IyyB - EKF_IFS_2_P.IzzB) *
    EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Add2_jk *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[11] + rtb_Divide4_in *
                        EKF_IFS_2_DW.x_est_00_DSTATE_f[9]) *
                       EKF_IFS_2_DW.x_est_00_DSTATE_f[10] + (EKF_IFS_2_P.IzzB /
    rtb_Add2_jk * rtb_Add_nv + rtb_Divide4_d0r * rtb_Add2_c5) * (rtb_Divide4_dh *
    EKF_IFS_2_P.S * EKF_IFS_2_P.b)) * EKF_IFS_2_P.dt +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9];
  rtb_Divide1_g0[10] = (((((((EKF_IFS_2_DW.x_est_00_DSTATE_f[10] -
    EKF_IFS_2_P.Qtrim) * EKF_IFS_2_P.Cmq * (EKF_IFS_2_P.Cbar / 2.0) /
    EKF_IFS_2_P.Utrim + (EKF_IFS_2_P.Cma * EKF_IFS_2_DW.x_est_00_DSTATE_f[5] +
    EKF_IFS_2_P.Cm0)) + EKF_IFS_2_P.Cmadot * EKF_IFS_2_DW.UnitDelay_DSTATE_di *
                            (EKF_IFS_2_P.Cbar / 2.0) / EKF_IFS_2_P.Utrim) +
    EKF_IFS_2_P.Cmu / EKF_IFS_2_P.Utrim * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim))
    + EKF_IFS_2_P.Cmde * EKF_IFS_2_DW.x_est_00_DSTATE_f[1]) + 1.0 /
    EKF_IFS_2_P.Utrim * (rtb_throttle_cmd - EKF_IFS_2_P.Utrim) * EKF_IFS_2_P.Cm1
    * EKF_IFS_2_P.Gain2_Gain_p4x * EKF_IFS_2_P.Gain1_Gain_b0r) *
                        (EKF_IFS_2_P.Ixz_Value_f2 / EKF_IFS_2_P.IyyB) *
                        (rtb_Divide4_dh * EKF_IFS_2_P.S * EKF_IFS_2_P.Cbar) +
                        ((EKF_IFS_2_P.IzzB - EKF_IFS_2_P.IxxB) /
    EKF_IFS_2_P.IyyB * EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11] - (EKF_IFS_2_DW.x_est_00_DSTATE_f[9] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - EKF_IFS_2_DW.x_est_00_DSTATE_f[11] *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * (EKF_IFS_2_P.IxzB / EKF_IFS_2_P.IyyB)))
    * EKF_IFS_2_P.dt + EKF_IFS_2_DW.x_est_00_DSTATE_f[10];
  rtb_Divide1_g0[11] = ((((EKF_IFS_2_P.IxxB - EKF_IFS_2_P.IyyB) *
    EKF_IFS_2_P.IxxB + EKF_IFS_2_P.IxzB * EKF_IFS_2_P.IxzB) / rtb_Add2_jk *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[9] - rtb_Divide4_in *
    EKF_IFS_2_DW.x_est_00_DSTATE_f[11]) * EKF_IFS_2_DW.x_est_00_DSTATE_f[10] +
                        (EKF_IFS_2_P.IxxB / rtb_Add2_jk * rtb_Add2_c5 +
    rtb_Divide4_d0r * rtb_Add_nv) * (rtb_Divide4_dh * EKF_IFS_2_P.S *
    EKF_IFS_2_P.b)) * EKF_IFS_2_P.dt + EKF_IFS_2_DW.x_est_00_DSTATE_f[11];
  rtb_Divide1_g0[12] = EKF_IFS_2_P.dt * EKF_IFS_2_P.Constant_Value_co +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[12];
  rtb_Divide1_g0[13] = EKF_IFS_2_P.dt * EKF_IFS_2_P.Constant_Value_k +
    EKF_IFS_2_DW.x_est_00_DSTATE_f[13];

  /* Sum: '<S142>/Subtract' incorporates:
   *  Inport: '<Root>/Body Rates meas'
   *  Inport: '<Root>/Euler Angles'
   *  Inport: '<Root>/VT, alpha, beta meas'
   *  Sum: '<S853>/Subtract1'
   *  Sum: '<S853>/Subtract2'
   */
  tmp_1[0] = EKF_IFS_2_U.VTalphabetameas.VT;
  tmp_1[1] = EKF_IFS_2_U.VTalphabetameas.alpha;
  tmp_1[2] = EKF_IFS_2_U.VTalphabetameas.beta;
  tmp_1[3] = EKF_IFS_2_U.EulerAngles.phi;
  tmp_1[4] = EKF_IFS_2_U.EulerAngles.theta;
  tmp_1[5] = EKF_IFS_2_U.BodyRatesmeas.P;
  tmp_1[6] = EKF_IFS_2_U.BodyRatesmeas.Q;
  tmp_1[7] = EKF_IFS_2_U.BodyRatesmeas.R;
  rtb_Divide_jn[0] = rtb_Divide1_g0[4];
  rtb_Divide_jn[1] = rtb_Divide1_g0[5] + rtb_Divide1_g0[12];
  rtb_Divide_jn[2] = rtb_Divide1_g0[6] + rtb_Divide1_g0[13];
  for (i = 0; i < 5; i++) {
    rtb_Divide_jn[i + 3] = rtb_Divide1_g0[7 + i];
  }

  /* Product: '<S142>/Product1' incorporates:
   *  Sum: '<S142>/Subtract'
   */
  for (i = 0; i < 8; i++) {
    rtb_Divide1_h2s[i] = tmp_1[i] - rtb_Divide_jn[i];
  }

  /* Sum: '<S142>/Subtract1' incorporates:
   *  Inport: '<Root>/Enable//Disable'
   *  Product: '<S142>/Product'
   *  Product: '<S142>/Product1'
   */
  for (i = 0; i < 14; i++) {
    tmp_5 = 0.0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      tmp_5 += rtb_Product1_f[14 * i_0 + i] * (real_T)EKF_IFS_2_U.EnableDisable *
        rtb_Divide1_h2s[i_0];
    }

    rtb_x_est_kk_f[i] = tmp_5 + rtb_Divide1_g0[i];
  }

  /* End of Sum: '<S142>/Subtract1' */

  /* Product: '<S138>/Divide2' incorporates:
   *  BusCreator: '<S141>/Bus Creator'
   *  Trigonometry: '<S138>/Trigonometric Function'
   *  Trigonometry: '<S138>/Trigonometric Function1'
   */
  rtb_etaLon = rtb_x_est_kk_f[4] * cos(rtb_x_est_kk_f[5]) * cos(rtb_x_est_kk_f[6]);

  /* BusCreator: '<S141>/Bus Creator1' incorporates:
   *  Inport: '<Root>/Euler Angles'
   */
  rtb_Add1_hkq = EKF_IFS_2_U.EulerAngles.psi;

  /* Trigonometry: '<S137>/Trigonometric Function4' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   *  Inport: '<Root>/Euler Angles'
   */
  rtb_Sum5 = cos(EKF_IFS_2_U.EulerAngles.psi);

  /* Product: '<S137>/Divide3' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   *  Trigonometry: '<S137>/Trigonometric Function1'
   */
  rtb_Add_lzz = rtb_etaLon * cos(rtb_x_est_kk_f[8]) * rtb_Sum5;

  /* Trigonometry: '<S137>/Trigonometric Function5' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   */
  rtb_aileron_cmd = cos(rtb_x_est_kk_f[7]);

  /* Trigonometry: '<S137>/Trigonometric Function3' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   *  Inport: '<Root>/Euler Angles'
   */
  rtb_TrigonometricFunction1_kv = sin(EKF_IFS_2_U.EulerAngles.psi);

  /* Trigonometry: '<S137>/Trigonometric Function2' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   */
  rtb_throttle_cmd = sin(rtb_x_est_kk_f[8]);

  /* Trigonometry: '<S137>/Trigonometric Function' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   */
  rtb_elevator_cmd = sin(rtb_x_est_kk_f[7]);

  /* Product: '<S137>/Divide2' */
  rtb_Add_iq = rtb_throttle_cmd * rtb_elevator_cmd * rtb_Sum5;

  /* Product: '<S139>/Divide2' incorporates:
   *  BusCreator: '<S141>/Bus Creator'
   *  Trigonometry: '<S139>/Trigonometric Function1'
   */
  rtb_Sum8 = rtb_x_est_kk_f[4] * sin(rtb_x_est_kk_f[6]);

  /* Product: '<S137>/Divide5' */
  rtb_Gain_cl = rtb_throttle_cmd * rtb_aileron_cmd * rtb_Sum5;

  /* Product: '<S140>/Divide2' incorporates:
   *  BusCreator: '<S141>/Bus Creator'
   *  Trigonometry: '<S140>/Trigonometric Function'
   *  Trigonometry: '<S140>/Trigonometric Function1'
   */
  rtb_Sum5 = rtb_x_est_kk_f[4] * sin(rtb_x_est_kk_f[5]) * cos(rtb_x_est_kk_f[6]);

  /* Sum: '<S50>/Add3' incorporates:
   *  Product: '<S137>/Divide1'
   *  Product: '<S137>/Divide4'
   *  Product: '<S137>/Divide6'
   *  Product: '<S137>/Divide7'
   *  Sum: '<S137>/Add1'
   *  Sum: '<S137>/Add2'
   *  Sum: '<S137>/Add3'
   */
  rtb_Divide4_dh = (((rtb_Add_iq - rtb_aileron_cmd *
                      rtb_TrigonometricFunction1_kv) * rtb_Sum8 + rtb_Add_lzz) +
                    (rtb_elevator_cmd * rtb_TrigonometricFunction1_kv +
                     rtb_Gain_cl) * rtb_Sum5) - rtb_Divide1_mwl[3];

  /* Trigonometry: '<S135>/Trigonometric Function3' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   *  Inport: '<Root>/Euler Angles'
   */
  rtb_aileron_cmd = sin(EKF_IFS_2_U.EulerAngles.psi);

  /* Trigonometry: '<S135>/Trigonometric Function5' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   */
  rtb_TrigonometricFunction1_kv = cos(rtb_x_est_kk_f[7]);

  /* Trigonometry: '<S135>/Trigonometric Function4' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   *  Inport: '<Root>/Euler Angles'
   */
  rtb_throttle_cmd = cos(EKF_IFS_2_U.EulerAngles.psi);

  /* Trigonometry: '<S135>/Trigonometric Function2' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   */
  rtb_elevator_cmd = sin(rtb_x_est_kk_f[8]);

  /* Trigonometry: '<S135>/Trigonometric Function' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   */
  rtb_rudder_cmd = sin(rtb_x_est_kk_f[7]);

  /* Sum: '<S50>/Add1' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   *  Product: '<S135>/Divide1'
   *  Product: '<S135>/Divide2'
   *  Product: '<S135>/Divide3'
   *  Product: '<S135>/Divide4'
   *  Product: '<S135>/Divide5'
   *  Product: '<S135>/Divide6'
   *  Product: '<S135>/Divide7'
   *  Sum: '<S135>/Add1'
   *  Sum: '<S135>/Add2'
   *  Sum: '<S135>/Add3'
   *  Trigonometry: '<S135>/Trigonometric Function1'
   */
  rtb_Add_iq = (((rtb_elevator_cmd * rtb_rudder_cmd * rtb_aileron_cmd +
                  rtb_TrigonometricFunction1_kv * rtb_throttle_cmd) * rtb_Sum8 +
                 rtb_etaLon * cos(rtb_x_est_kk_f[8]) * rtb_aileron_cmd) +
                (rtb_elevator_cmd * rtb_TrigonometricFunction1_kv *
                 rtb_aileron_cmd - rtb_rudder_cmd * rtb_throttle_cmd) * rtb_Sum5)
    - rtb_Divide1_mwl[4];

  /* Sum: '<S50>/Add2' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   *  Product: '<S136>/Divide1'
   *  Product: '<S136>/Divide2'
   *  Product: '<S136>/Divide3'
   *  Sum: '<S136>/Add1'
   *  Trigonometry: '<S136>/Trigonometric Function'
   *  Trigonometry: '<S136>/Trigonometric Function1'
   *  Trigonometry: '<S136>/Trigonometric Function2'
   *  Trigonometry: '<S136>/Trigonometric Function4'
   *  Trigonometry: '<S136>/Trigonometric Function5'
   */
  rtb_Add_lzz = ((rtb_etaLon * sin(rtb_x_est_kk_f[8]) - cos(rtb_x_est_kk_f[8]) *
                  sin(rtb_x_est_kk_f[7]) * rtb_Sum8) - cos(rtb_x_est_kk_f[7]) *
                 cos(rtb_x_est_kk_f[8]) * rtb_Sum5) - rtb_Divide1_mwl[5];

  /* Trigonometry: '<S27>/Trigonometric Function1' */
  rtb_cos_atrack = cos(rtb_cos_atrack);

  /* Product: '<S24>/Product6' */
  rtb_etaLon = rtb_cos_atrack * rtb_Vab_mod;

  /* Sum: '<S27>/Add8' */
  rtb_MathFunction6 += rtb_MathFunction5;

  /* Sqrt: '<S27>/Math Function6'
   *
   * About '<S27>/Math Function6':
   *  Operator: signedSqrt
   */
  if (rtb_MathFunction6 < 0.0) {
    rtb_MathFunction6 = -sqrt(fabs(rtb_MathFunction6));
  } else {
    rtb_MathFunction6 = sqrt(rtb_MathFunction6);
  }

  /* End of Sqrt: '<S27>/Math Function6' */

  /* Product: '<S27>/Product2' */
  rtb_x_W1_dot_idx_0 = rtb_Add9 / rtb_MathFunction6;

  /* MATLAB Function: '<S28>/Embedded MATLAB Function' incorporates:
   *  SignalConversion: '<S29>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Intelligent Flight System (subsystem)/Guidance System/Coordinates transformation e-n-h to e-n-h_track/angles of rotation/Angle Correction/Embedded MATLAB Function': '<S29>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S29>:1:4' */
  i = 1;

  /* '<S29>:1:5' */
  rtb_Divide4_ot = 0.0;
  if (!((rtb_Add9 > 0.0) && (rtb_Add5 > 0.0))) {
    if ((rtb_Add9 > 0.0) && (rtb_Add5 < 0.0)) {
      /* '<S29>:1:10' */
      /* '<S29>:1:11' */
      rtb_Divide4_ot = 3.1415926535897931;

      /* '<S29>:1:12' */
      i = -1;
    } else {
      if ((rtb_Add9 < 0.0) && (rtb_Add5 < 0.0)) {
        /* '<S29>:1:13' */
        /* '<S29>:1:14' */
        rtb_Divide4_ot = -3.1415926535897931;

        /* '<S29>:1:15' */
        i = -1;
      }
    }
  } else {
    /* '<S29>:1:7' */
    /* '<S29>:1:8' */
    /* '<S29>:1:9' */
  }

  /* Trigonometry: '<S27>/Trigonometric Function4' */
  /* '<S29>:1:20' */
  if (rtb_x_W1_dot_idx_0 > 1.0) {
    rtb_x_W1_dot_idx_0 = 1.0;
  } else {
    if (rtb_x_W1_dot_idx_0 < -1.0) {
      rtb_x_W1_dot_idx_0 = -1.0;
    }
  }

  /* MATLAB Function: '<S28>/Embedded MATLAB Function' incorporates:
   *  Trigonometry: '<S27>/Trigonometric Function4'
   */
  rtb_Gain_cl = asin(rtb_x_W1_dot_idx_0) * (real_T)i + rtb_Divide4_ot;

  /* Trigonometry: '<S27>/Trigonometric Function2' */
  rtb_Sum5 = sin(rtb_Gain_cl);

  /* Trigonometry: '<S27>/Trigonometric Function3' */
  rtb_aileron_cmd = cos(rtb_Gain_cl);

  /* Outputs for Atomic SubSystem: '<S24>/Subsystem1' */

  /* Sum: '<S24>/Add4' incorporates:
   *  BusCreator: '<S50>/Bus Creator2'
   *  Gain: '<S24>/Gain'
   *  Gain: '<S24>/Gain1'
   *  Gain: '<S24>/Gain2'
   *  Product: '<S24>/Product1'
   *  Product: '<S24>/Product2'
   *  Product: '<S24>/Product3'
   *  Product: '<S24>/Product4'
   *  Product: '<S24>/Product5'
   *  Product: '<S24>/Product7'
   *  Sum: '<S24>/Add1'
   *  Sum: '<S24>/Add2'
   */
  EKF_IFS_2_Subsystem1_h(rtb_sin_atrack * rtb_Vab_mod + EKF_IFS_2_P.Gain_Gain_pc
    * rtb_Add_lzz * (real_T)rtb_DataTypeConversion1, rtb_etaLon * rtb_Sum5 +
    EKF_IFS_2_P.Gain1_Gain_ng * rtb_Divide4_dh * (real_T)rtb_DataTypeConversion1,
    rtb_etaLon * rtb_aileron_cmd + EKF_IFS_2_P.Gain2_Gain_hz * rtb_Add_iq *
    (real_T)rtb_DataTypeConversion1, &EKF_IFS_2_B.Subsystem1);

  /* End of Outputs for SubSystem: '<S24>/Subsystem1' */

  /* Gain: '<S5>/Gain2' incorporates:
   *  Gain: '<S49>/Gain3'
   *  Gain: '<S5>/Gain1'
   */
  rtb_Divide3_mja = EKF_IFS_2_P.Gain3_Gain_nb * rtb_Divide1_mwl[5] *
    EKF_IFS_2_P.Gain1_Gain_d3 * EKF_IFS_2_P.Gain2_Gain_hu;

  /* Gain: '<S5>/Gain3' incorporates:
   *  Gain: '<S49>/Gain2'
   */
  rtb_Divide3_bk = EKF_IFS_2_P.Gain2_Gain_bq * rtb_Divide1_mwl[3] *
    EKF_IFS_2_P.Gain3_Gain_p2;

  /* Gain: '<S5>/Gain4' incorporates:
   *  Gain: '<S49>/Gain1'
   */
  rtb_Divide4_l2 = EKF_IFS_2_P.Gain1_Gain_o4 * rtb_Divide1_mwl[4] *
    EKF_IFS_2_P.Gain4_Gain_i;

  /* Outputs for Atomic SubSystem: '<S23>/Subsystem4' */
  EKF_IFS_2_Subsystem4_p(rtb_Divide3_mja, rtb_Divide3_bk, rtb_Divide4_l2,
    &EKF_IFS_2_B.Subsystem4);

  /* End of Outputs for SubSystem: '<S23>/Subsystem4' */

  /* Gain: '<S23>/Gain' */
  rtb_Divide4_ot = EKF_IFS_2_P.Gain_Gain_fo *
    EKF_IFS_2_B.Subsystem4.SumofElements;

  /* Outputs for Atomic SubSystem: '<S23>/Subsystem3' */
  EKF_IFS_2_Subsystem1(rtb_Divide3_bk, rtb_Divide4_l2, &EKF_IFS_2_B.Subsystem3);

  /* End of Outputs for SubSystem: '<S23>/Subsystem3' */

  /* Trigonometry: '<S23>/Trigonometric Function' */
  rtb_Divide4_kov = rt_atan2d_snf(rtb_Divide3_mja, EKF_IFS_2_B.Subsystem3.Sqrt);

  /* Sum: '<S40>/Subtract2' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Gain_cl = wpts_h[rtb_FixPtRelationalOperator - 1] - rtb_hd;

  /* Sum: '<S40>/Subtract4' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Add_lzz = wpts_n[rtb_FixPtRelationalOperator - 1] - rtb_nd;

  /* Sum: '<S40>/Subtract5' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Add_iq = wpts_e[rtb_FixPtRelationalOperator - 1] - rtb_ed;

  /* Outputs for Atomic SubSystem: '<S40>/Subsystem1' */
  EKF_IFS_2_Subsystem1_h(rtb_Gain_cl, rtb_Add_lzz, rtb_Add_iq,
    &EKF_IFS_2_B.Subsystem1_c);

  /* End of Outputs for SubSystem: '<S40>/Subsystem1' */

  /* Product: '<S40>/Product' incorporates:
   *  Constant: '<S40>/dist d to r'
   */
  rtb_etaLon = EKF_IFS_2_P.L / EKF_IFS_2_B.Subsystem1_c.Sqrt;

  /* Sum: '<S21>/Add8' incorporates:
   *  Product: '<S40>/Product1'
   *  Sum: '<S40>/Subtract7'
   */
  rtb_Divide4_lgu = (rtb_etaLon * rtb_Gain_cl + rtb_hd) -
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.Height;

  /* Sum: '<S21>/Add7' incorporates:
   *  Product: '<S40>/Product2'
   *  Sum: '<S40>/Subtract6'
   */
  rtb_Divide4_dh = (rtb_etaLon * rtb_Add_lzz + rtb_nd) -
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.North;

  /* Sum: '<S21>/Add6' incorporates:
   *  Product: '<S40>/Product3'
   *  Sum: '<S40>/Subtract1'
   */
  rtb_Divide4_ea = (rtb_etaLon * rtb_Add_iq + rtb_ed) -
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEart_o.East;

  /* Outputs for Atomic SubSystem: '<S23>/Subsystem2' */
  EKF_IFS_2_Subsystem1(rtb_Divide4_dh, rtb_Divide4_ea, &EKF_IFS_2_B.Subsystem2);

  /* End of Outputs for SubSystem: '<S23>/Subsystem2' */

  /* Sum: '<S23>/Add2' incorporates:
   *  Trigonometry: '<S23>/Trigonometric Function3'
   */
  rtb_etaLon = rt_atan2d_snf(rtb_Divide4_lgu, EKF_IFS_2_B.Subsystem2.Sqrt) -
    rtb_Divide4_kov;

  /* Trigonometry: '<S23>/Trigonometric Function1' */
  rtb_TrigonometricFunction1_kv = atan(rtb_etaLon);

  /* Logic: '<S23>/Logical Operator' */
  rtb_LogicalOperator = !(rtb_DataTypeConversion1 != 0);

  /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator || (EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRese != 0))
  {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC_d;
  }

  if (EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE >=
      EKF_IFS_2_P.DiscreteTimeIntegrator_UpperSat) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE =
      EKF_IFS_2_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE <=
        EKF_IFS_2_P.DiscreteTimeIntegrator_LowerSat) {
      EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE =
        EKF_IFS_2_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* Sum: '<S23>/Sum' incorporates:
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
   *  Gain: '<S23>/Gain2'
   */
  rtb_Gain_cl = EKF_IFS_2_P.KpLon * rtb_TrigonometricFunction1_kv +
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outputs for Atomic SubSystem: '<S23>/Subsystem1' */
  EKF_IFS_2_Subsystem1_h(rtb_Divide4_ea, rtb_Divide4_dh, rtb_Divide4_lgu,
    &EKF_IFS_2_B.Subsystem1_h);

  /* End of Outputs for SubSystem: '<S23>/Subsystem1' */

  /* Trigonometry: '<S23>/Trigonometric Function2' incorporates:
   *  Product: '<S23>/Product2'
   */
  rtb_Divide4_p3cp = rt_atan2d_snf(rtb_Divide4_ot * rtb_Gain_cl,
    EKF_IFS_2_B.Subsystem1_h.Sqrt);

  /* Sum: '<S21>/Add' incorporates:
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product1'
   *  Product: '<S21>/Product4'
   *  Product: '<S21>/Product5'
   *  Product: '<S21>/Product6'
   */
  rtb_Add_iq = (rtb_cos_atrack * rtb_aileron_cmd * rtb_Divide4_l2 +
                rtb_Divide3_bk * rtb_Sum5) + rtb_sin_atrack * rtb_aileron_cmd *
    rtb_Divide3_mja;

  /* Sum: '<S21>/Add1' incorporates:
   *  Product: '<S21>/Product2'
   *  Product: '<S21>/Product3'
   *  Product: '<S21>/Product7'
   *  Product: '<S21>/Product8'
   *  Product: '<S21>/Product9'
   */
  rtb_Add_lzz = (rtb_Divide3_bk * rtb_aileron_cmd - rtb_cos_atrack * rtb_Sum5 *
                 rtb_Divide4_l2) - rtb_sin_atrack * rtb_Sum5 * rtb_Divide3_mja;

  /* Outputs for Atomic SubSystem: '<S22>/Subsystem4' */
  EKF_IFS_2_Subsystem4(rtb_Add_iq, rtb_Add_lzz, &EKF_IFS_2_B.Subsystem4_j);

  /* End of Outputs for SubSystem: '<S22>/Subsystem4' */

  /* Gain: '<S22>/Gain' */
  rtb_Divide5_gk = EKF_IFS_2_P.Gain_Gain_ci *
    EKF_IFS_2_B.Subsystem4_j.SumofElements;

  /* Sum: '<S21>/Add4' incorporates:
   *  Product: '<S21>/Product16'
   *  Product: '<S21>/Product17'
   *  Product: '<S21>/Product21'
   *  Product: '<S21>/Product22'
   *  Product: '<S21>/Product23'
   */
  rtb_Divide3_bk = (rtb_Divide4_dh * rtb_aileron_cmd - rtb_cos_atrack * rtb_Sum5
                    * rtb_Divide4_ea) - rtb_sin_atrack * rtb_Sum5 *
    rtb_Divide4_lgu;

  /* Sum: '<S21>/Add3' incorporates:
   *  Product: '<S21>/Product12'
   *  Product: '<S21>/Product13'
   *  Product: '<S21>/Product18'
   *  Product: '<S21>/Product19'
   *  Product: '<S21>/Product20'
   */
  rtb_Gain_cl = (rtb_cos_atrack * rtb_aileron_cmd * rtb_Divide4_ea +
                 rtb_Divide4_dh * rtb_Sum5) + rtb_sin_atrack * rtb_aileron_cmd *
    rtb_Divide4_lgu;

  /* Sum: '<S22>/Add2' incorporates:
   *  Trigonometry: '<S22>/Trigonometric Function'
   *  Trigonometry: '<S22>/Trigonometric Function1'
   */
  rtb_Divide4_ea = rt_atan2d_snf(rtb_Add_lzz, rtb_Add_iq) - rt_atan2d_snf
    (rtb_Divide3_bk, rtb_Gain_cl);

  /* MATLAB Function: '<S22>/Embedded MATLAB Function' */
  /* MATLAB Function 'Intelligent Flight System (subsystem)/Guidance System/Phi command/Embedded MATLAB Function': '<S30>:1' */
  /* '<S30>:1:3' */
  rtb_MathFunction_dp = rtb_Divide4_ea;
  if (rtb_Divide4_ea > 3.1415926535897931) {
    /* '<S30>:1:5' */
    /* '<S30>:1:6' */
    rtb_MathFunction_dp = rtb_Divide4_ea - 6.2831853071795862;
  }

  if (rtb_Divide4_ea < -3.1415926535897931) {
    /* '<S30>:1:9' */
    /* '<S30>:1:10' */
    rtb_MathFunction_dp = rtb_Divide4_ea + 6.2831853071795862;
  }

  /* End of MATLAB Function: '<S22>/Embedded MATLAB Function' */

  /* Logic: '<S22>/Logical Operator' */
  rtb_LogicalOperator_k = !(rtb_DataTypeConversion1 != 0);

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator_k || (EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_b !=
       0)) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC_g;
  }

  if (EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h >=
      EKF_IFS_2_P.DiscreteTimeIntegrator_UpperS_d) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h =
      EKF_IFS_2_P.DiscreteTimeIntegrator_UpperS_d;
  } else {
    if (EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h <=
        EKF_IFS_2_P.DiscreteTimeIntegrator_LowerS_j) {
      EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h =
        EKF_IFS_2_P.DiscreteTimeIntegrator_LowerS_j;
    }
  }

  /* Sum: '<S22>/Sum' incorporates:
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
   *  Gain: '<S22>/Gain2'
   */
  rtb_Divide4_ot = EKF_IFS_2_P.KpLat * rtb_MathFunction_dp +
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h;

  /* Outputs for Atomic SubSystem: '<S22>/Subsystem1' */
  EKF_IFS_2_Subsystem1(rtb_Gain_cl, rtb_Divide3_bk, &EKF_IFS_2_B.Subsystem1_d);

  /* End of Outputs for SubSystem: '<S22>/Subsystem1' */

  /* MATLAB Function: '<S7>/Swtching Logic' incorporates:
   *  BusCreator: '<S141>/Bus Creator'
   *  BusCreator: '<S141>/Bus Creator1'
   */
  /* MATLAB Function 'Intelligent Flight System (subsystem)/R//C AUTO Switching Subsystem/Swtching Logic': '<S43>:1' */
  /* initialization */
  /* '<S43>:1:14' */
  rtb_Gain_cl = rtb_DataStoreRead4;

  /* '<S43>:1:15' */
  rtb_Add_lzz = rtb_DataStoreRead3;

  /* '<S43>:1:16' */
  rtb_Add_iq = rtb_DataStoreRead1;

  /* '<S43>:1:17' */
  rtb_Divide3_bk = rtb_DataStoreRead2;

  /* '<S43>:1:18' */
  rtb_Divide4_kov = rtb_DataStoreRead5;

  /* '<S43>:1:20' */
  rtb_Divide3_iu1 = EKF_IFS_2_P.throttletrim;

  /* [-] */
  /* '<S43>:1:21' */
  rtb_Divide4_lgu = EKF_IFS_2_P.elevatortrim;

  /* [rad] */
  /* '<S43>:1:22' */
  rtb_Divide4_l2 = EKF_IFS_2_P.ailerontrim;

  /* [rad] */
  /* '<S43>:1:23' */
  rtb_Divide_niq = EKF_IFS_2_P.ruddertrim;

  /* [rad] */
  /* '<S43>:1:24' */
  rtb_Divide3_mja = EKF_IFS_2_B.Subsystem1.Sqrt;

  /* [ft/s] */
  /* '<S43>:1:25' */
  /* [rad] */
  /* '<S43>:1:26' */
  /* [rad] */
  /* '<S43>:1:27' */
  /* [rad] */
  /* '<S43>:1:29' */
  /* [s] */
  /* %updating/resseting values */
  if (rtb_DataTypeConversion1 == 0) {
    /* '<S43>:1:32' */
    /* '<S43>:1:33' */
    rtb_Add_lzz = rtb_BusConversion_InsertedFor_0;

    /* '<S43>:1:34' */
    rtb_Add_iq = rtb_BusConversion_InsertedFor_1;

    /* '<S43>:1:35' */
    rtb_Divide3_bk = rtb_BusConversion_InsertedFor_2;

    /* '<S43>:1:36' */
    rtb_Divide4_kov = rtb_BusConversion_InsertedFor_3;

    /* '<S43>:1:37' */
    rtb_Gain_cl = 0.0;
  }

  /* time interval counting after switching */
  if (rtb_DataTypeConversion1 == 1) {
    /* '<S43>:1:41' */
    /* '<S43>:1:42' */
    rtb_Add_lzz = rtb_DataStoreRead3;

    /* '<S43>:1:43' */
    rtb_Add_iq = rtb_DataStoreRead1;

    /* '<S43>:1:44' */
    rtb_Divide3_bk = rtb_DataStoreRead2;

    /* '<S43>:1:45' */
    rtb_Divide4_kov = rtb_DataStoreRead5;

    /* '<S43>:1:46' */
    rtb_Gain_cl = rtb_DataStoreRead4 + EKF_IFS_2_P.dt;
  }

  if (!((rtb_Gain_cl <= 0.0) || (rtb_Gain_cl > 2.0) || (!(rtb_Gain_cl > 0.0))))
  {
    /* '<S43>:1:60' */
    /* control trim weighting as a function of time */
    /* '<S43>:1:62' */
    rtb_Divide3_iu1 = (0.5 - cos(1.5707963267948966 * rtb_Gain_cl) * 0.5) *
      (EKF_IFS_2_P.throttletrim - rtb_Add_lzz) + rtb_Add_lzz;

    /* '<S43>:1:63' */
    rtb_Divide4_lgu = (0.5 - cos(1.5707963267948966 * rtb_Gain_cl) * 0.5) *
      (EKF_IFS_2_P.elevatortrim - rtb_Add_iq) + rtb_Add_iq;

    /* '<S43>:1:64' */
    rtb_Divide4_l2 = (0.5 - cos(1.5707963267948966 * rtb_Gain_cl) * 0.5) *
      (EKF_IFS_2_P.ailerontrim - rtb_Divide3_bk) + rtb_Divide3_bk;

    /* '<S43>:1:65' */
    rtb_Divide_niq = (0.5 - cos(1.5707963267948966 * rtb_Gain_cl) * 0.5) *
      (EKF_IFS_2_P.ruddertrim - rtb_Divide4_kov) + rtb_Divide4_kov;

    /* state command weighting as a function of time */
    /* '<S43>:1:67' */
    rtb_Divide3_mja = (0.5 - cos(1.5707963267948966 * rtb_Gain_cl) * 0.5) *
      (EKF_IFS_2_B.Subsystem1.Sqrt - rtb_x_est_kk_f[4]) + rtb_x_est_kk_f[4];

    /* '<S43>:1:68' */
    rtb_Divide4_p3cp = (0.5 - cos(1.5707963267948966 * rtb_Gain_cl) * 0.5) *
      (rtb_Divide4_p3cp - rtb_x_est_kk_f[8]) + rtb_x_est_kk_f[8];

    /* '<S43>:1:69' */
    /* '<S43>:1:70' */
  } else {
    /* '<S43>:1:49' */
    /* control trim */
    /* '<S43>:1:51' */
    /* '<S43>:1:52' */
    /* '<S43>:1:53' */
    /* '<S43>:1:54' */
    /* state command */
    /* '<S43>:1:56' */
    /* '<S43>:1:57' */
    /* '<S43>:1:58' */
    /* '<S43>:1:59' */
  }

  /* DataStoreWrite: '<S7>/Data Store Write1' incorporates:
   *  MATLAB Function: '<S7>/Swtching Logic'
   */
  EKF_IFS_2_DW.remote_elevator_mem = rtb_Add_iq;

  /* DataStoreWrite: '<S7>/Data Store Write2' incorporates:
   *  MATLAB Function: '<S7>/Swtching Logic'
   */
  EKF_IFS_2_DW.remote_aileron_mem = rtb_Divide3_bk;

  /* DataStoreWrite: '<S7>/Data Store Write3' incorporates:
   *  MATLAB Function: '<S7>/Swtching Logic'
   */
  EKF_IFS_2_DW.remote_throttle_mem = rtb_Add_lzz;

  /* DataStoreWrite: '<S7>/Data Store Write4' incorporates:
   *  MATLAB Function: '<S7>/Swtching Logic'
   */
  EKF_IFS_2_DW.sw_time = rtb_Gain_cl;

  /* DataStoreWrite: '<S7>/Data Store Write5' incorporates:
   *  MATLAB Function: '<S7>/Swtching Logic'
   */
  EKF_IFS_2_DW.remote_rudder_mem = rtb_Divide4_kov;

  /* Gain: '<S7>/Gain' */
  rtb_Divide4_ea = EKF_IFS_2_P.Gain_Gain_m * rtb_Divide3_mja;

  /* Gain: '<S7>/Gain1' */
  rtb_Add_iq = EKF_IFS_2_P.Gain1_Gain_mu * rtb_Divide4_p3cp;

  /* Gain: '<S7>/Gain2' incorporates:
   *  Product: '<S22>/Product'
   *  Trigonometry: '<S22>/Trigonometric Function3'
   */
  rtb_Gain_cl = rt_atan2d_snf(rtb_Divide5_gk * rtb_Divide4_ot,
    EKF_IFS_2_B.Subsystem1_d.Sqrt) * EKF_IFS_2_P.Gain2_Gain_cp;

  /* Gain: '<S7>/Gain3' incorporates:
   *  Constant: '<S20>/Beta command'
   */
  rtb_Add_lzz = EKF_IFS_2_P.Gain3_Gain_f1 * EKF_IFS_2_P.Betacommand_Value;

  /* DataStoreWrite: '<S8>/Data Store Write1' */
  EKF_IFS_2_DW.PIC_CIC_Last = rtb_DataStoreRead1_b;

  /* DataStoreWrite: '<S8>/Data Store Write2' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  EKF_IFS_2_DW.Waypoint_Index = rtb_DataStoreRead2_h;

  /* DataStoreWrite: '<S8>/Data Store Write3' */
  EKF_IFS_2_DW.Start_Wpt[0] = rtb_DataStoreRead3_b_idx_0;
  EKF_IFS_2_DW.Start_Wpt[1] = rtb_DataStoreRead3_b_idx_1;
  EKF_IFS_2_DW.Start_Wpt[2] = rtb_DataStoreRead3_b_idx_2;

  /* DataStoreWrite: '<S8>/Data Store Write4' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  EKF_IFS_2_DW.Home_reset = rtb_DataStoreRead4_n;

  /* Outputs for Atomic SubSystem: '<S4>/Discrete Output Feedback State Space Controller with Anti Windup' */
  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/x0'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  for (i = 0; i < 24; i++) {
    if (rtb_DataTypeConversion1 >= EKF_IFS_2_P.Switch_Threshold) {
      rtb_x_k[i] = EKF_IFS_2_DW.UnitDelay_DSTATE_m[i];
    } else {
      rtb_x_k[i] = EKF_IFS_2_P.x0_Value[i];
    }
  }

  /* End of Switch: '<S13>/Switch' */

  /* Sum: '<S10>/Sum1' incorporates:
   *  BusCreator: '<S141>/Bus Creator'
   *  BusCreator: '<S141>/Bus Creator1'
   *  Constant: '<S13>/C inv Matrix'
   *  Product: '<S10>/Product3'
   *  Product: '<S13>/Product3'
   *  Sum: '<S4>/Sum1'
   *  Sum: '<S4>/Sum2'
   *  Sum: '<S4>/Sum3'
   *  Sum: '<S4>/Sum4'
   */
  rtb_Divide4_ji[0] = rtb_Divide4_ea - rtb_x_est_kk_f[4];
  rtb_Divide4_ji[1] = rtb_Add_iq - rtb_x_est_kk_f[8];
  rtb_Divide4_ji[2] = rtb_Gain_cl - rtb_x_est_kk_f[7];
  rtb_Divide4_ji[3] = rtb_Add_lzz - rtb_x_est_kk_f[6];
  for (i = 0; i < 4; i++) {
    tmp_5 = 0.0;
    for (i_0 = 0; i_0 < 24; i_0++) {
      tmp_5 += EKF_IFS_2_P.CinvMatrix_Value[(i_0 << 2) + i] * rtb_x_k[i_0];
    }

    rtb_Divide4_ji_0[i] = rtb_Divide4_ji[i] - tmp_5;
  }

  /* End of Sum: '<S10>/Sum1' */

  /* Product: '<S10>/Product3' incorporates:
   *  Constant: '<S10>/D inv Matrix'
   */
  for (i = 0; i < 4; i++) {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.DinvMatrix_Value[i + 12] *
      rtb_Divide4_ji_0[3] + (EKF_IFS_2_P.DinvMatrix_Value[i + 8] *
      rtb_Divide4_ji_0[2] + (EKF_IFS_2_P.DinvMatrix_Value[i + 4] *
      rtb_Divide4_ji_0[1] + EKF_IFS_2_P.DinvMatrix_Value[i] * rtb_Divide4_ji_0[0]));
    rtb_Product4_p[i] = rtb_x_W1_dot_idx_0;
  }

  /* Saturate: '<S14>/Throttle Limiter' */
  rtb_Divide4_dh = EKF_IFS_2_P.ThrottleMin - EKF_IFS_2_P.throttletrim;
  rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.ThrottleMax - EKF_IFS_2_P.throttletrim;
  if (rtb_Product4_p[0] > rtb_x_W1_dot_idx_0) {
    rtb_Divide4_dh = rtb_x_W1_dot_idx_0;
  } else {
    if (!(rtb_Product4_p[0] < rtb_Divide4_dh)) {
      rtb_Divide4_dh = rtb_Product4_p[0];
    }
  }

  /* End of Saturate: '<S14>/Throttle Limiter' */

  /* Saturate: '<S14>/Elevator Limiter' */
  rtb_Divide3_bk = EKF_IFS_2_P.ElevatorMin - EKF_IFS_2_P.elevatortrim;
  rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.ElevatorMax - EKF_IFS_2_P.elevatortrim;
  if (rtb_Product4_p[1] > rtb_x_W1_dot_idx_0) {
    rtb_Divide3_bk = rtb_x_W1_dot_idx_0;
  } else {
    if (!(rtb_Product4_p[1] < rtb_Divide3_bk)) {
      rtb_Divide3_bk = rtb_Product4_p[1];
    }
  }

  /* End of Saturate: '<S14>/Elevator Limiter' */

  /* Saturate: '<S14>/Aileron Limiter' */
  rtb_Divide4_kov = EKF_IFS_2_P.AileronMin - EKF_IFS_2_P.ailerontrim;
  rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.AileronMax - EKF_IFS_2_P.ailerontrim;
  if (rtb_Product4_p[2] > rtb_x_W1_dot_idx_0) {
    rtb_Divide4_kov = rtb_x_W1_dot_idx_0;
  } else {
    if (!(rtb_Product4_p[2] < rtb_Divide4_kov)) {
      rtb_Divide4_kov = rtb_Product4_p[2];
    }
  }

  /* End of Saturate: '<S14>/Aileron Limiter' */

  /* Saturate: '<S14>/Rudder Limiter' */
  rtb_Divide3_mja = EKF_IFS_2_P.RudderMin - EKF_IFS_2_P.ruddertrim;
  rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.RudderMax - EKF_IFS_2_P.ruddertrim;
  if (rtb_Product4_p[3] > rtb_x_W1_dot_idx_0) {
    rtb_Divide3_mja = rtb_x_W1_dot_idx_0;
  } else {
    if (!(rtb_Product4_p[3] < rtb_Divide3_mja)) {
      rtb_Divide3_mja = rtb_Product4_p[3];
    }
  }

  for (i = 0; i < 24; i++) {
    /* Product: '<S13>/Product1' incorporates:
     *  Constant: '<S13>/B inv Matrix'
     *  Product: '<S13>/Product4'
     *  Sum: '<S13>/Add'
     */
    tmp_2[i] = 0.0;
    tmp_2[i] += (real_T)rtb_DataTypeConversion1 * rtb_Divide4_dh *
      EKF_IFS_2_P.BinvMatrix_Value[i];
    tmp_2[i] += EKF_IFS_2_P.BinvMatrix_Value[i + 24] * ((real_T)
      rtb_DataTypeConversion1 * rtb_Divide3_bk);
    tmp_2[i] += EKF_IFS_2_P.BinvMatrix_Value[i + 48] * ((real_T)
      rtb_DataTypeConversion1 * rtb_Divide4_kov);
    tmp_2[i] += EKF_IFS_2_P.BinvMatrix_Value[i + 72] * ((real_T)
      rtb_DataTypeConversion1 * rtb_Divide3_mja);

    /* Product: '<S13>/Product' incorporates:
     *  Constant: '<S13>/A inv Matrix'
     *  Sum: '<S13>/Add'
     */
    tmp_3[i] = 0.0;
    for (i_0 = 0; i_0 < 24; i_0++) {
      tmp_3[i] += EKF_IFS_2_P.AinvMatrix_Value[24 * i_0 + i] * rtb_x_k[i_0];
    }

    /* End of Product: '<S13>/Product' */

    /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
     *  Sum: '<S13>/Add'
     */
    EKF_IFS_2_DW.UnitDelay_DSTATE_m[i] = tmp_2[i] + tmp_3[i];
  }

  /* End of Saturate: '<S14>/Rudder Limiter' */
  /* End of Outputs for SubSystem: '<S4>/Discrete Output Feedback State Space Controller with Anti Windup' */

  /* Outputs for Atomic SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */
  /* SignalConversion: '<S11>/TmpSignal ConversionAtCh_tildeInport1' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant10'
   *  Constant: '<S9>/Constant11'
   *  Constant: '<S9>/Constant12'
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   *  Constant: '<S9>/Constant6'
   *  Constant: '<S9>/Constant7'
   *  Constant: '<S9>/Constant8'
   *  Constant: '<S9>/Constant9'
   */
  rtb_x_G_trim[0] = EKF_IFS_2_P.throttletrim;
  rtb_x_G_trim[1] = EKF_IFS_2_P.elevatortrim;
  rtb_x_G_trim[2] = EKF_IFS_2_P.ailerontrim;
  rtb_x_G_trim[3] = EKF_IFS_2_P.ruddertrim;
  rtb_x_G_trim[4] = EKF_IFS_2_P.VTtrim;
  rtb_x_G_trim[5] = EKF_IFS_2_P.alphatrim;
  rtb_x_G_trim[6] = EKF_IFS_2_P.betatrim;
  rtb_x_G_trim[7] = EKF_IFS_2_P.phitrim;
  rtb_x_G_trim[8] = EKF_IFS_2_P.thetatrim;
  rtb_x_G_trim[9] = EKF_IFS_2_P.Ptrim;
  rtb_x_G_trim[10] = EKF_IFS_2_P.Qtrim;
  rtb_x_G_trim[11] = EKF_IFS_2_P.Rtrim;

  /* Sum: '<S11>/Sum10' incorporates:
   *  BusCreator: '<S141>/Bus Creator'
   *  BusCreator: '<S141>/Bus Creator1'
   *  BusCreator: '<S141>/Bus Creator2'
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant10'
   *  Constant: '<S9>/Constant11'
   *  Constant: '<S9>/Constant12'
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   *  Constant: '<S9>/Constant6'
   *  Constant: '<S9>/Constant7'
   *  Constant: '<S9>/Constant8'
   *  Constant: '<S9>/Constant9'
   *  Inport: '<Root>/Servo deflection'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtCh_tildeInport1'
   */
  rtb_x_tilde_G[0] = EKF_IFS_2_U.Servodeflection[0] - EKF_IFS_2_P.throttletrim;
  rtb_x_tilde_G[1] = EKF_IFS_2_U.Servodeflection[1] - EKF_IFS_2_P.elevatortrim;
  rtb_x_tilde_G[2] = EKF_IFS_2_U.Servodeflection[2] - EKF_IFS_2_P.ailerontrim;
  rtb_x_tilde_G[3] = EKF_IFS_2_U.Servodeflection[3] - EKF_IFS_2_P.ruddertrim;
  rtb_x_tilde_G[4] = rtb_x_est_kk_f[4] - EKF_IFS_2_P.VTtrim;
  rtb_x_tilde_G[5] = rtb_x_est_kk_f[5] - EKF_IFS_2_P.alphatrim;
  rtb_x_tilde_G[6] = rtb_x_est_kk_f[6] - EKF_IFS_2_P.betatrim;
  rtb_x_tilde_G[7] = rtb_x_est_kk_f[7] - EKF_IFS_2_P.phitrim;
  rtb_x_tilde_G[8] = rtb_x_est_kk_f[8] - EKF_IFS_2_P.thetatrim;
  rtb_x_tilde_G[9] = rtb_x_est_kk_f[9] - EKF_IFS_2_P.Ptrim;
  rtb_x_tilde_G[10] = rtb_x_est_kk_f[10] - EKF_IFS_2_P.Qtrim;
  rtb_x_tilde_G[11] = rtb_x_est_kk_f[11] - EKF_IFS_2_P.Rtrim;

  /* Gain: '<S11>/Ch_tilde1' */
  for (i = 0; i < 4; i++) {
    rtb_Product4_p[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      rtb_Product4_p[i] += EKF_IFS_2_P.Ch_tilde[(i_0 << 2) + i] *
        rtb_x_tilde_G[i_0];
    }
  }

  /* End of Gain: '<S11>/Ch_tilde1' */

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Fcn: '<S16>/Fcn'
   */
  if (((int32_T)1.0 - rtb_DataTypeConversion1 != 0) ||
      (EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_c != 0)) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[0] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[1] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[2] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[3] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC;
  }

  /* SignalConversion: '<S11>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
   */
  rtb_VectorConcatenate[0] = EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[0];
  rtb_VectorConcatenate[1] = EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[1];
  rtb_VectorConcatenate[2] = EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[2];
  rtb_VectorConcatenate[3] = EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[3];

  /* SignalConversion: '<S11>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   */
  rtb_VectorConcatenate[4] = EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[0];
  rtb_VectorConcatenate[5] = EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[1];
  rtb_VectorConcatenate[6] = EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[2];
  rtb_VectorConcatenate[7] = EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[3];

  /* SignalConversion: '<S11>/ConcatBufferAtVector ConcatenateIn3' */
  memcpy(&rtb_VectorConcatenate[8], &rtb_x_tilde_G[0], 12U * sizeof(real_T));

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant'
   *  DataTypeConversion: '<S11>/Data Type Conversion1'
   *  Sum: '<S16>/Add7'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  if ((real_T)EKF_IFS_2_DW.UnitDelay_DSTATE_bs > EKF_IFS_2_P.Switch_Threshold_i)
  {
    rtb_x_W1_dot_idx_0 = EKF_IFS_2_P.Constant_Value;
    rtb_Divide_bi = EKF_IFS_2_P.Constant_Value;
    rtb_Divide4_jaz = EKF_IFS_2_P.Constant_Value;
    rtb_Add_ey = EKF_IFS_2_P.Constant_Value;
  } else {
    /* Gain: '<S11>/Ch_tilde' incorporates:
     *  Sum: '<S11>/Sum9'
     */
    for (i = 0; i < 4; i++) {
      rtb_Divide4_ji[i] = 0.0;
      for (i_0 = 0; i_0 < 12; i_0++) {
        rtb_Divide4_ji[i] += EKF_IFS_2_P.Ch_tilde[(i_0 << 2) + i] *
          rtb_x_G_trim[i_0];
      }
    }

    /* End of Gain: '<S11>/Ch_tilde' */

    /* Sum: '<S11>/Sum11' incorporates:
     *  Gain: '<S16>/B_W1'
     *  Sum: '<S11>/Sum9'
     */
    rtb_x_W1_dot_idx_0 = (rtb_Divide4_ea - rtb_Divide4_ji[0]) - rtb_Product4_p[0];
    rtb_Divide_bi = (rtb_Add_iq - rtb_Divide4_ji[1]) - rtb_Product4_p[1];
    rtb_Divide4_jaz = (rtb_Gain_cl - rtb_Divide4_ji[2]) - rtb_Product4_p[2];
    rtb_Add_ey = (rtb_Add_lzz - rtb_Divide4_ji[3]) - rtb_Product4_p[3];

    /* Gain: '<S16>/B_W1' incorporates:
     *  Sum: '<S16>/Add7'
     */
    for (i = 0; i < 4; i++) {
      tmp_5 = EKF_IFS_2_P.B_W1[i + 12] * rtb_Add_ey + (EKF_IFS_2_P.B_W1[i + 8] *
        rtb_Divide4_jaz + (EKF_IFS_2_P.B_W1[i + 4] * rtb_Divide_bi +
                           EKF_IFS_2_P.B_W1[i] * rtb_x_W1_dot_idx_0));
      rtb_Divide4_ji[i] = tmp_5;
    }

    /* Gain: '<S16>/A_W1' incorporates:
     *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
     *  Sum: '<S16>/Add7'
     */
    for (i = 0; i < 4; i++) {
      tmp_5 = EKF_IFS_2_P.A_W1[i + 12] *
        EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[3] + (EKF_IFS_2_P.A_W1[i +
        8] * EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[2] +
        (EKF_IFS_2_P.A_W1[i + 4] * EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e
         [1] + EKF_IFS_2_P.A_W1[i] *
         EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[0]));
      rtb_Divide4_ji_0[i] = tmp_5;
    }

    /* End of Gain: '<S16>/A_W1' */
    rtb_x_W1_dot_idx_0 = rtb_Divide4_ji[0] + rtb_Divide4_ji_0[0];
    rtb_Divide_bi = rtb_Divide4_ji[1] + rtb_Divide4_ji_0[1];
    rtb_Divide4_jaz = rtb_Divide4_ji[2] + rtb_Divide4_ji_0[2];
    rtb_Add_ey = rtb_Divide4_ji[3] + rtb_Divide4_ji_0[3];
  }

  /* End of Switch: '<S16>/Switch' */

  /* Gain: '<S15>/-F_second_hinf' incorporates:
   *  Product: '<S12>/Divide1'
   */
  for (i = 0; i < 20; i++) {
    tmp_4[i << 2] = -EKF_IFS_2_P.F_second_hinf[i << 2];
    tmp_4[1 + (i << 2)] = -EKF_IFS_2_P.F_second_hinf[(i << 2) + 1];
    tmp_4[2 + (i << 2)] = -EKF_IFS_2_P.F_second_hinf[(i << 2) + 2];
    tmp_4[3 + (i << 2)] = -EKF_IFS_2_P.F_second_hinf[(i << 2) + 3];
  }

  for (i = 0; i < 4; i++) {
    rtb_Divide4_ji[i] = 0.0;
    for (i_0 = 0; i_0 < 20; i_0++) {
      rtb_Divide4_ji[i] += tmp_4[(i_0 << 2) + i] * rtb_VectorConcatenate[i_0];
    }
  }

  /* End of Gain: '<S15>/-F_second_hinf' */
  /* End of Outputs for SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */

  /* Sum: '<S4>/Sum7' incorporates:
   *  Fcn: '<S12>/Fcn'
   *  Inport: '<Root>/State_output feedback selection'
   *  Product: '<S12>/Divide'
   *  Product: '<S12>/Divide1'
   *  Sum: '<S12>/Add'
   */
  rtb_Sum5 = ((1.0 - EKF_IFS_2_U.State_outputfeedbackselection) *
              rtb_Divide4_kov + rtb_Divide4_ji[2] *
              EKF_IFS_2_U.State_outputfeedbackselection) + rtb_Divide4_l2;

  /* Saturate: '<S4>/Aileron Limiter' */
  if (rtb_Sum5 > EKF_IFS_2_P.AileronMax) {
    rtb_aileron_cmd = EKF_IFS_2_P.AileronMax;
  } else if (rtb_Sum5 < EKF_IFS_2_P.AileronMin) {
    rtb_aileron_cmd = EKF_IFS_2_P.AileronMin;
  } else {
    rtb_aileron_cmd = rtb_Sum5;
  }

  /* End of Saturate: '<S4>/Aileron Limiter' */

  /* Sum: '<S4>/Sum6' incorporates:
   *  Fcn: '<S12>/Fcn'
   *  Inport: '<Root>/State_output feedback selection'
   *  Product: '<S12>/Divide'
   *  Product: '<S12>/Divide1'
   *  Sum: '<S12>/Add'
   */
  rtb_throttle_cmd = ((1.0 - EKF_IFS_2_U.State_outputfeedbackselection) *
                      rtb_Divide3_bk + rtb_Divide4_ji[1] *
                      EKF_IFS_2_U.State_outputfeedbackselection) +
    rtb_Divide4_lgu;

  /* Saturate: '<S4>/Elevator Limiter' */
  if (rtb_throttle_cmd > EKF_IFS_2_P.ElevatorMax) {
    rtb_elevator_cmd = EKF_IFS_2_P.ElevatorMax;
  } else if (rtb_throttle_cmd < EKF_IFS_2_P.ElevatorMin) {
    rtb_elevator_cmd = EKF_IFS_2_P.ElevatorMin;
  } else {
    rtb_elevator_cmd = rtb_throttle_cmd;
  }

  /* End of Saturate: '<S4>/Elevator Limiter' */

  /* Sum: '<S4>/Sum8' incorporates:
   *  Fcn: '<S12>/Fcn'
   *  Inport: '<Root>/State_output feedback selection'
   *  Product: '<S12>/Divide'
   *  Product: '<S12>/Divide1'
   *  Sum: '<S12>/Add'
   */
  rtb_Sum8 = ((1.0 - EKF_IFS_2_U.State_outputfeedbackselection) *
              rtb_Divide3_mja + rtb_Divide4_ji[3] *
              EKF_IFS_2_U.State_outputfeedbackselection) + rtb_Divide_niq;

  /* Saturate: '<S4>/Rudder Limiter' */
  if (rtb_Sum8 > EKF_IFS_2_P.RudderMax) {
    rtb_rudder_cmd = EKF_IFS_2_P.RudderMax;
  } else if (rtb_Sum8 < EKF_IFS_2_P.RudderMin) {
    rtb_rudder_cmd = EKF_IFS_2_P.RudderMin;
  } else {
    rtb_rudder_cmd = rtb_Sum8;
  }

  /* End of Saturate: '<S4>/Rudder Limiter' */

  /* RelationalOperator: '<S4>/Relational Operator2' */
  rtb_DataStoreRead1_b = (rtb_Sum5 != rtb_aileron_cmd);

  /* RelationalOperator: '<S4>/Relational Operator1' */
  rtb_RelationalOperator1 = (rtb_throttle_cmd != rtb_elevator_cmd);

  /* Sum: '<S4>/Sum5' incorporates:
   *  Fcn: '<S12>/Fcn'
   *  Inport: '<Root>/State_output feedback selection'
   *  Product: '<S12>/Divide'
   *  Product: '<S12>/Divide1'
   *  Sum: '<S12>/Add'
   */
  rtb_Sum5 = ((1.0 - EKF_IFS_2_U.State_outputfeedbackselection) * rtb_Divide4_dh
              + rtb_Divide4_ji[0] * EKF_IFS_2_U.State_outputfeedbackselection) +
    rtb_Divide3_iu1;

  /* Saturate: '<S4>/Throttle Limiter' */
  if (rtb_Sum5 > EKF_IFS_2_P.ThrottleMax) {
    rtb_throttle_cmd = EKF_IFS_2_P.ThrottleMax;
  } else if (rtb_Sum5 < EKF_IFS_2_P.ThrottleMin) {
    rtb_throttle_cmd = EKF_IFS_2_P.ThrottleMin;
  } else {
    rtb_throttle_cmd = rtb_Sum5;
  }

  /* End of Saturate: '<S4>/Throttle Limiter' */

  /* Outport: '<Root>/Control Surface Commands' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_Control Surface Commands_at_inport_0'
   */
  /* MATLAB Function 'Intelligent Flight System (subsystem)/Guidance System/r and d points/d distance/Embedded MATLAB Function': '<S41>:1' */
  /* '<S41>:1:4' */
  /* '<S41>:1:5' */
  /* '<S41>:1:6' */
  /* '<S41>:1:8' */
  EKF_IFS_2_Y.ControlSurfaceCommands.throttle_cmd = rtb_throttle_cmd;
  EKF_IFS_2_Y.ControlSurfaceCommands.elevator_cmd = rtb_elevator_cmd;
  EKF_IFS_2_Y.ControlSurfaceCommands.aileron_cmd = rtb_aileron_cmd;
  EKF_IFS_2_Y.ControlSurfaceCommands.rudder_cmd = rtb_rudder_cmd;

  /* Outport: '<Root>/Commanded States' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_Commanded States_at_inport_0'
   */
  EKF_IFS_2_Y.CommandedStates.VT_cmd = rtb_Divide4_ea;
  EKF_IFS_2_Y.CommandedStates.theta_cmd = rtb_Add_iq;
  EKF_IFS_2_Y.CommandedStates.phi_cmd = rtb_Gain_cl;
  EKF_IFS_2_Y.CommandedStates.beta_cmd = rtb_Add_lzz;

  /* Outport: '<Root>/Track Angles' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_Track Angles_at_inport_0'
   */
  EKF_IFS_2_Y.TrackAngles.etaLat = rtb_MathFunction_dp;
  EKF_IFS_2_Y.TrackAngles.etaLon = rtb_etaLon;

  /* Outport: '<Root>/Distance to Waypoint' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  EKF_IFS_2_Y.DistancetoWaypoint = (real32_T)distance;

  /* Outport: '<Root>/Waypoint Index' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  EKF_IFS_2_Y.WaypointIndex = rtb_DataStoreRead2_h;

  /* Outport: '<Root>/State feedback controller states' */
  memcpy(&EKF_IFS_2_Y.Statefeedbackcontrollerstates[0], &rtb_VectorConcatenate[0],
         20U * sizeof(real_T));

  /* Gain: '<S808>/Gain8' */
  rtb_Axb *= 1.0 / EKF_IFS_2_P.g;

  /* Gain: '<S808>/Gain9' */
  rtb_Ayb *= 1.0 / EKF_IFS_2_P.g;

  /* Gain: '<S808>/Gain10' */
  rtb_Azb *= 1.0 / EKF_IFS_2_P.g;

  /* Update for UnitDelay: '<S46>/x_est_[0//0]' */
  for (i = 0; i < 6; i++) {
    EKF_IFS_2_DW.x_est_00_DSTATE[i] = rtb_Divide1_mwl[i];
  }

  /* End of Update for UnitDelay: '<S46>/x_est_[0//0]' */

  /* Update for UnitDelay: '<S46>/Unit Delay1' incorporates:
   *  BusCreator: '<S141>/Bus Creator1'
   *  Gain: '<S45>/Gain4'
   */
  EKF_IFS_2_DW.UnitDelay1_DSTATE[0] = rtb_x_est_kk_f[7];
  EKF_IFS_2_DW.UnitDelay1_DSTATE[1] = rtb_x_est_kk_f[8];
  EKF_IFS_2_DW.UnitDelay1_DSTATE[2] = rtb_Add1_hkq;
  EKF_IFS_2_DW.UnitDelay1_DSTATE[3] = EKF_IFS_2_P.g * rtb_Axb;
  EKF_IFS_2_DW.UnitDelay1_DSTATE[4] = EKF_IFS_2_P.g * rtb_Ayb;
  EKF_IFS_2_DW.UnitDelay1_DSTATE[5] = EKF_IFS_2_P.g * rtb_Azb;

  /* Product: '<S52>/Product3' incorporates:
   *  Constant: '<S52>/H_[k]'
   */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp[i + 6 * i_0] += EKF_IFS_2_P.H_k_Value[6 * i_1 + i] * rtb_P_kk1[6 *
          i_0 + i_1];
      }
    }
  }

  /* Update for UnitDelay: '<S52>/P_est_[0//0]' incorporates:
   *  Product: '<S52>/Product3'
   *  Sum: '<S52>/Subtract4'
   */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_5 = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        tmp_5 += rtb_Product1_n[6 * i_1 + i] * tmp[6 * i_0 + i_1];
      }

      EKF_IFS_2_DW.P_est_00_DSTATE[i + 6 * i_0] = rtb_P_kk1[6 * i_0 + i] - tmp_5;
    }
  }

  /* End of Update for UnitDelay: '<S52>/P_est_[0//0]' */

  /* Update for UnitDelay: '<S56>/Delay Input1' */
  EKF_IFS_2_DW.DelayInput1_DSTATE =
    EKF_IFS_2_B.sf_ConvertLatLonAlttoFlatEarth.North;

  /* Update for UnitDelay: '<S142>/Unit Delay1' incorporates:
   *  Gain: '<S141>/Gain4'
   *  Inport: '<Root>/Accelerometer meas'
   *  Update for Inport: '<Root>/Servo Commands'
   */
  EKF_IFS_2_DW.UnitDelay1_DSTATE_b[0] = EKF_IFS_2_U.ServoCommands.throttle_cmd;
  EKF_IFS_2_DW.UnitDelay1_DSTATE_b[1] = EKF_IFS_2_U.ServoCommands.elevator_cmd;
  EKF_IFS_2_DW.UnitDelay1_DSTATE_b[2] = EKF_IFS_2_U.ServoCommands.aileron_cmd;
  EKF_IFS_2_DW.UnitDelay1_DSTATE_b[3] = EKF_IFS_2_U.ServoCommands.rudder_cmd;
  EKF_IFS_2_DW.UnitDelay1_DSTATE_b[4] = EKF_IFS_2_P.g *
    EKF_IFS_2_U.Accelerometermeas.Axb;
  EKF_IFS_2_DW.UnitDelay1_DSTATE_b[5] = EKF_IFS_2_P.g *
    EKF_IFS_2_U.Accelerometermeas.Ayb;
  EKF_IFS_2_DW.UnitDelay1_DSTATE_b[6] = EKF_IFS_2_P.g *
    EKF_IFS_2_U.Accelerometermeas.Azb;

  /* Update for UnitDelay: '<S142>/x_est_[0//0]' */
  for (i = 0; i < 14; i++) {
    /* Saturate: '<S142>/Saturation1' */
    if (rtb_x_est_kk_f[i] > EKF_IFS_2_P.saturation_max_sta[i]) {
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i] = EKF_IFS_2_P.saturation_max_sta[i];
    } else if (rtb_x_est_kk_f[i] < EKF_IFS_2_P.saturation_min_sta[i]) {
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i] = EKF_IFS_2_P.saturation_min_sta[i];
    } else {
      EKF_IFS_2_DW.x_est_00_DSTATE_f[i] = rtb_x_est_kk_f[i];
    }

    /* End of Saturate: '<S142>/Saturation1' */
  }

  /* End of Update for UnitDelay: '<S142>/x_est_[0//0]' */

  /* Update for UnitDelay: '<S191>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE = rtb_Divide;

  /* Update for UnitDelay: '<S506>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_c = rtb_Divide_hc;

  /* Update for UnitDelay: '<S281>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_b = rtb_Divide_c3;

  /* Update for UnitDelay: '<S236>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_d = rtb_Divide_mrb;

  /* Update for UnitDelay: '<S461>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_j = rtb_Divide_e4;

  /* Update for UnitDelay: '<S551>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_p = rtb_Divide_j;

  /* Update for UnitDelay: '<S596>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_j3 = rtb_Divide_du;

  /* Update for UnitDelay: '<S641>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_cq = rtb_Divide_ep;

  /* Update for UnitDelay: '<S686>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_ja = rtb_Divide_el;

  /* Update for UnitDelay: '<S731>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_l = rtb_Divide_bas;

  /* Update for UnitDelay: '<S326>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_e = rtb_Divide_l;

  /* Update for UnitDelay: '<S371>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_dx = rtb_Divide_mg;

  /* Update for UnitDelay: '<S416>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_f = rtb_Divide_kts;

  /* Product: '<S143>/Product2' */
  for (i = 0; i < 8; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      rtb_Divide_ps[i + (i_0 << 3)] = 0.0;
      for (i_1 = 0; i_1 < 14; i_1++) {
        rtb_Divide_ps[i + (i_0 << 3)] += rtb_H_k[(i_1 << 3) + i] * rtb_P_kk1_f
          [14 * i_0 + i_1];
      }
    }
  }

  /* Update for UnitDelay: '<S143>/P_est_[0//0]' incorporates:
   *  Product: '<S143>/Product2'
   *  Sum: '<S143>/Subtract3'
   */
  for (i = 0; i < 14; i++) {
    for (i_0 = 0; i_0 < 14; i_0++) {
      tmp_5 = 0.0;
      for (i_1 = 0; i_1 < 8; i_1++) {
        tmp_5 += rtb_Product1_f[14 * i_1 + i] * rtb_Divide_ps[(i_0 << 3) + i_1];
      }

      EKF_IFS_2_DW.P_est_00_DSTATE_n[i + 14 * i_0] = rtb_P_kk1_f[14 * i_0 + i] -
        tmp_5;
    }
  }

  /* End of Update for UnitDelay: '<S143>/P_est_[0//0]' */

  /* Update for UnitDelay: '<S822>/Unit Delay' */
  EKF_IFS_2_DW.UnitDelay_DSTATE_di = rtb_Divide_mhp;

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S23>/Gain1'
   */
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE += EKF_IFS_2_P.KiLon *
    rtb_TrigonometricFunction1_kv * EKF_IFS_2_P.DiscreteTimeIntegrator_gainva_e;
  if (EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE >=
      EKF_IFS_2_P.DiscreteTimeIntegrator_UpperSat) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE =
      EKF_IFS_2_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE <=
        EKF_IFS_2_P.DiscreteTimeIntegrator_LowerSat) {
      EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE =
        EKF_IFS_2_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  if (rtb_LogicalOperator) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRese = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S22>/Gain1'
   */
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h += EKF_IFS_2_P.KiLat *
    rtb_MathFunction_dp * EKF_IFS_2_P.DiscreteTimeIntegrator_gainva_f;
  if (EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h >=
      EKF_IFS_2_P.DiscreteTimeIntegrator_UpperS_d) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h =
      EKF_IFS_2_P.DiscreteTimeIntegrator_UpperS_d;
  } else {
    if (EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h <=
        EKF_IFS_2_P.DiscreteTimeIntegrator_LowerS_j) {
      EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h =
        EKF_IFS_2_P.DiscreteTimeIntegrator_LowerS_j;
    }
  }

  if (rtb_LogicalOperator_k) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_b = 1;
  } else {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_b = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

  /* Update for Atomic SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */
  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Fcn: '<S16>/Fcn'
   */
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[0] +=
    EKF_IFS_2_P.DiscreteTimeIntegrator_gainval * rtb_x_W1_dot_idx_0;
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[1] +=
    EKF_IFS_2_P.DiscreteTimeIntegrator_gainval * rtb_Divide_bi;
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[2] +=
    EKF_IFS_2_P.DiscreteTimeIntegrator_gainval * rtb_Divide4_jaz;
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[3] +=
    EKF_IFS_2_P.DiscreteTimeIntegrator_gainval * rtb_Add_ey;

  /* Outputs for Atomic SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */
  if ((int32_T)1.0 - rtb_DataTypeConversion1 > 0) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_c = 1;
  } else if ((int32_T)1.0 - rtb_DataTypeConversion1 == 0) {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_c = 0;
  } else {
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_c = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  /* End of Update for SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */

  /* Gain: '<S18>/B_W3' incorporates:
   *  Sum: '<S18>/Add7'
   */
  for (i = 0; i < 4; i++) {
    tmp_5 = EKF_IFS_2_P.B_W3[i + 12] * rtb_Product4_p[3] + (EKF_IFS_2_P.B_W3[i +
      8] * rtb_Product4_p[2] + (EKF_IFS_2_P.B_W3[i + 4] * rtb_Product4_p[1] +
      EKF_IFS_2_P.B_W3[i] * rtb_Product4_p[0]));
    rtb_Divide4_ji[i] = tmp_5;
  }

  /* End of Gain: '<S18>/B_W3' */

  /* Gain: '<S18>/A_W3' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  Sum: '<S18>/Add7'
   */
  for (i = 0; i < 4; i++) {
    tmp_5 = EKF_IFS_2_P.A_W3[i + 12] *
      EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[3] + (EKF_IFS_2_P.A_W3[i + 8]
      * EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[2] + (EKF_IFS_2_P.A_W3[i +
      4] * EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[1] + EKF_IFS_2_P.A_W3[i]
      * EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[0]));
    rtb_Divide4_ji_0[i] = tmp_5;
  }

  /* End of Gain: '<S18>/A_W3' */

  /* Update for Atomic SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */
  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S18>/Add7'
   */
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[0] += (rtb_Divide4_ji[0] +
    rtb_Divide4_ji_0[0]) * EKF_IFS_2_P.DiscreteTimeIntegrator_gainva_m;
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[1] += (rtb_Divide4_ji[1] +
    rtb_Divide4_ji_0[1]) * EKF_IFS_2_P.DiscreteTimeIntegrator_gainva_m;
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[2] += (rtb_Divide4_ji[2] +
    rtb_Divide4_ji_0[2]) * EKF_IFS_2_P.DiscreteTimeIntegrator_gainva_m;
  EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[3] += (rtb_Divide4_ji[3] +
    rtb_Divide4_ji_0[3]) * EKF_IFS_2_P.DiscreteTimeIntegrator_gainva_m;

  /* End of Outputs for SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */

  /* Update for UnitDelay: '<S11>/Unit Delay' incorporates:
   *  Logic: '<S4>/Logical Operator'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  RelationalOperator: '<S4>/Relational Operator3'
   */
  EKF_IFS_2_DW.UnitDelay_DSTATE_bs = ((rtb_Sum8 != rtb_rudder_cmd) ||
    rtb_DataStoreRead1_b || rtb_RelationalOperator1 || (rtb_Sum5 !=
    rtb_throttle_cmd));

  /* End of Update for SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */
}

/* Model initialize function */
void EKF_IFS_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(EKF_IFS_2_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &EKF_IFS_2_B), 0,
                sizeof(B_EKF_IFS_2_T));

  /* states (dwork) */
  (void) memset((void *)&EKF_IFS_2_DW, 0,
                sizeof(DW_EKF_IFS_2_T));

  /* external inputs */
  (void) memset((void *)&EKF_IFS_2_U, 0,
                sizeof(ExtU_EKF_IFS_2_T));

  /* external outputs */
  (void) memset((void *)&EKF_IFS_2_Y, 0,
                sizeof(ExtY_EKF_IFS_2_T));

  {
    int32_T i;

    /* Start for DataStoreMemory: '<S7>/Logic time control' */
    EKF_IFS_2_DW.sw_time = EKF_IFS_2_P.Logictimecontrol_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Remote aileron' */
    EKF_IFS_2_DW.remote_aileron_mem = EKF_IFS_2_P.Remoteaileron_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Remote elevator' */
    EKF_IFS_2_DW.remote_elevator_mem = EKF_IFS_2_P.Remoteelevator_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Remote rudder' */
    EKF_IFS_2_DW.remote_rudder_mem = EKF_IFS_2_P.Remoterudder_InitialValue;

    /* Start for DataStoreMemory: '<S7>/Remote throttle' */
    EKF_IFS_2_DW.remote_throttle_mem = EKF_IFS_2_P.Remotethrottle_InitialValue;

    /* Start for DataStoreMemory: '<S8>/Home Reset Memory' */
    EKF_IFS_2_DW.Home_reset = EKF_IFS_2_P.HomeResetMemory_InitialValue;

    /* Start for DataStoreMemory: '<S8>/PIC//CIC Last State Memory' */
    EKF_IFS_2_DW.PIC_CIC_Last = EKF_IFS_2_P.PICCICLastStateMemory_InitialVa;

    /* Start for DataStoreMemory: '<S8>/Start Waypoint Memory' */
    EKF_IFS_2_DW.Start_Wpt[0] = EKF_IFS_2_P.StartWaypointMemory_InitialValu[0];
    EKF_IFS_2_DW.Start_Wpt[1] = EKF_IFS_2_P.StartWaypointMemory_InitialValu[1];
    EKF_IFS_2_DW.Start_Wpt[2] = EKF_IFS_2_P.StartWaypointMemory_InitialValu[2];

    /* Start for DataStoreMemory: '<S8>/Waypoint Index Memory' */
    EKF_IFS_2_DW.Waypoint_Index = EKF_IFS_2_P.WaypointIndexMemory_InitialValu;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for UnitDelay: '<S46>/x_est_[0//0]' */
      EKF_IFS_2_DW.x_est_00_DSTATE[i] = EKF_IFS_2_P.x0_est_nav[i];

      /* InitializeConditions for UnitDelay: '<S46>/Unit Delay1' */
      EKF_IFS_2_DW.UnitDelay1_DSTATE[i] =
        EKF_IFS_2_P.UnitDelay1_InitialCondition;
    }

    /* InitializeConditions for UnitDelay: '<S52>/P_est_[0//0]' */
    memcpy(&EKF_IFS_2_DW.P_est_00_DSTATE[0], &EKF_IFS_2_P.P0_est_nav[0], 36U *
           sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S56>/Delay Input1' */
    EKF_IFS_2_DW.DelayInput1_DSTATE = EKF_IFS_2_P.DetectChange_vinit;

    /* InitializeConditions for UnitDelay: '<S142>/Unit Delay1' */
    for (i = 0; i < 7; i++) {
      EKF_IFS_2_DW.UnitDelay1_DSTATE_b[i] =
        EKF_IFS_2_P.UnitDelay1_InitialCondition_l;
    }

    /* End of InitializeConditions for UnitDelay: '<S142>/Unit Delay1' */

    /* InitializeConditions for UnitDelay: '<S142>/x_est_[0//0]' */
    memcpy(&EKF_IFS_2_DW.x_est_00_DSTATE_f[0], &EKF_IFS_2_P.x0_est_sta[0], 14U *
           sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S191>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE = EKF_IFS_2_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S506>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_c = EKF_IFS_2_P.UnitDelay_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S281>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_b = EKF_IFS_2_P.UnitDelay_InitialCondition_c;

    /* InitializeConditions for UnitDelay: '<S236>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_d = EKF_IFS_2_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S461>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_j = EKF_IFS_2_P.UnitDelay_InitialCondition_b;

    /* InitializeConditions for UnitDelay: '<S551>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_p = EKF_IFS_2_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for UnitDelay: '<S596>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_j3 = EKF_IFS_2_P.UnitDelay_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S641>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_cq = EKF_IFS_2_P.UnitDelay_InitialCondition_k;

    /* InitializeConditions for UnitDelay: '<S686>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_ja = EKF_IFS_2_P.UnitDelay_InitialCondition_oq;

    /* InitializeConditions for UnitDelay: '<S731>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_l = EKF_IFS_2_P.UnitDelay_InitialCondition_cw;

    /* InitializeConditions for UnitDelay: '<S326>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_e = EKF_IFS_2_P.UnitDelay_InitialCondition_h;

    /* InitializeConditions for UnitDelay: '<S371>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_dx = EKF_IFS_2_P.UnitDelay_InitialCondition_hq;

    /* InitializeConditions for UnitDelay: '<S416>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_f = EKF_IFS_2_P.UnitDelay_InitialCondition_oq2;

    /* InitializeConditions for UnitDelay: '<S143>/P_est_[0//0]' */
    memcpy(&EKF_IFS_2_DW.P_est_00_DSTATE_n[0], &EKF_IFS_2_P.P0_est_sta[0], 196U *
           sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S822>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_di = EKF_IFS_2_P.UnitDelay_InitialCondition_cf;

    /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC_d;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_h =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC_g;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_b = 0;

    /* InitializeConditions for Atomic SubSystem: '<S4>/Discrete Output Feedback State Space Controller with Anti Windup' */
    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    for (i = 0; i < 24; i++) {
      EKF_IFS_2_DW.UnitDelay_DSTATE_m[i] =
        EKF_IFS_2_P.UnitDelay_InitialCondition;
    }

    /* End of InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    /* End of InitializeConditions for SubSystem: '<S4>/Discrete Output Feedback State Space Controller with Anti Windup' */

    /* InitializeConditions for Atomic SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */
    /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[0] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[1] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[2] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_e[3] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_PrevRe_c = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC_n;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC_n;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC_n;
    EKF_IFS_2_DW.DiscreteTimeIntegrator_DSTATE_b[3] =
      EKF_IFS_2_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
    EKF_IFS_2_DW.UnitDelay_DSTATE_bs = EKF_IFS_2_P.UnitDelay_InitialCondition_g;

    /* End of InitializeConditions for SubSystem: '<S4>/Discrete State Feedback State Space Controller with Anti Windup' */
  }
}

/* Model terminate function */
void EKF_IFS_2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
