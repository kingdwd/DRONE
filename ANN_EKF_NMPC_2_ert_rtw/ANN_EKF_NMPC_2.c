/*
 * File: ANN_EKF_NMPC_2.c
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

#include "ANN_EKF_NMPC_2.h"
#include "ANN_EKF_NMPC_2_private.h"

/* Named constants for MATLAB Function: '<S2>/Control System' */
#define ANN_EKF_NMPC_2_nz              (12.0)

/* Block signals (auto storage) */
B_ANN_EKF_NMPC_2_T ANN_EKF_NMPC_2_B;

/* Block states (auto storage) */
DW_ANN_EKF_NMPC_2_T ANN_EKF_NMPC_2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ANN_EKF_NMPC_2_T ANN_EKF_NMPC_2_PrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU_ANN_EKF_NMPC_2_T ANN_EKF_NMPC_2_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_ANN_EKF_NMPC_2_T ANN_EKF_NMPC_2_Y;

/* Real-time model */
RT_MODEL_ANN_EKF_NMPC_2_T ANN_EKF_NMPC_2_M_;
RT_MODEL_ANN_EKF_NMPC_2_T *const ANN_EKF_NMPC_2_M = &ANN_EKF_NMPC_2_M_;

/* Forward declaration for local functions */
static void ANN_EKF_NMPC_2_invNxN_c(const real_T loctmp_x[36], real_T loctmp_y
  [36]);
static void ANN_EKF_NMPC_2_invNxN_a(const real_T loctmp_x[64], real_T loctmp_y
  [64]);
static void ANN_EKF_NMPC_2_eye(real_T loctmp_I[130321]);
static void ANN_EKF_NMPC_2_eml_xtrsm(const real_T loctmp_A[130321], real_T
  loctmp_B[361]);
static void ANN_EKF_NMPC_2_eml_xtrsm_b(const real_T loctmp_A[130321], real_T
  loctmp_B[361]);
static void ANN_EKF_NMPC_2_eml_xswap(real_T loctmp_x[130321], int32_T loctmp_ix0,
  int32_T loctmp_iy0);
static void ANN_EKF_NMPC_2_mldivide(const real_T loctmp_A[130321], real_T
  loctmp_B[361]);
static void ANN_EKF_NMPC_2_ann_iteration(const real_T loctmp_x_ann[49], const
  real_T loctmp_y_ann[7], real_T loctmp_a_ann[40], real_T loctmp_b_ann[40],
  real_T loctmp_c_ann, real_T loctmp_w_ann[280], real_T loctmp_lambda_ann,
  real_T *loctmp_c_ann_out, real_T *loctmp_lambda_ann_out, real_T
  *loctmp_V_ann_out);
static void ANN_EKF_NMPC_2_ann_iteration_f(const real_T loctmp_x_ann[49], const
  real_T loctmp_y_ann[7], real_T loctmp_a_ann[40], real_T loctmp_b_ann[40],
  real_T loctmp_c_ann, real_T loctmp_w_ann[280], real_T loctmp_lambda_ann,
  real_T *loctmp_c_ann_out, real_T *loctmp_lambda_ann_out, real_T
  *loctmp_V_ann_out);
static void ANN_EKF_NMPC_2_ann_iteration_fj(const real_T loctmp_x_ann[49], const
  real_T loctmp_y_ann[7], real_T loctmp_a_ann[40], real_T loctmp_b_ann[40],
  real_T loctmp_c_ann, real_T loctmp_w_ann[280], real_T loctmp_lambda_ann,
  real_T *loctmp_c_ann_out, real_T *loctmp_lambda_ann_out, real_T
  *loctmp_V_ann_out);
static void ANN_EKF_NMPC_2_ann_norm_X(const real_T loctmp_x_ann_un[7], const
  real_T loctmp_minXin[7], const real_T loctmp_maxXin[7], real_T loctmp_minYin,
  real_T loctmp_maxYin, real_T loctmp_x_ann[7]);
static real_T ANN_EKF_NMPC_2_ann_denorm_Y(real_T loctmp_y_ann, real_T
  loctmp_minXout, real_T loctmp_maxXout, real_T loctmp_minYout, real_T
  loctmp_maxYout);
static real_T ANN_EKF_NMPC_2_norm(const real_T loctmp_x[2]);
static real_T ANN_EKF_NMPC_2_norm_h(const real_T loctmp_x[3]);
static void ANN_EKF_NMPC_2_uas_augm_model(real_T loctmp_sw, boolean_T
  loctmp_home_cmd, real_T loctmp_b_dt, real_T loctmp_b_TR, uint8_T
  loctmp_wpts_fp, uint8_T loctmp_wpts_rp, real_T loctmp_wpts_h[32], real_T
  loctmp_wpts_n[32], real_T loctmp_wpts_e[32], const real_T loctmp_wpts_v[32],
  real_T loctmp_n_op_k, real_T loctmp_e_op_k, real_T loctmp_h_op_k, real_T
  loctmp_vn_op_k, real_T loctmp_ve_op_k, real_T loctmp_vh_op_k, real_T
  loctmp_alphadot_k, real_T loctmp_betadot_k, uint8_T loctmp_wpt_index_k, real_T
  loctmp_start_wpt_k[3], boolean_T loctmp_pic_cic_k, uint8_T loctmp_home_reset_k,
  real_T loctmp_THL_k, real_T loctmp_EL_k, real_T loctmp_AIL_k, real_T
  loctmp_RDR_k, real_T loctmp_VT_k, real_T loctmp_alpha_k, real_T loctmp_beta_k,
  real_T loctmp_phi_k, real_T loctmp_theta_k, real_T loctmp_psi_k, real_T
  loctmp_P_k, real_T loctmp_Q_k, real_T loctmp_R_k, real_T loctmp_n_k, real_T
  loctmp_e_k, real_T loctmp_h_k, real_T loctmp_ro_k, real_T loctmp_THLcmd_k,
  real_T loctmp_ELcmd_k, real_T loctmp_AILcmd_k, real_T loctmp_RDRcmd_k, real_T
  loctmp_xw11_k, real_T loctmp_xw12_k, real_T loctmp_xw13_k, real_T
  loctmp_xw14_k, real_T loctmp_xw21_k, real_T loctmp_xw22_k, real_T
  loctmp_xw23_k, real_T loctmp_xw24_k, real_T loctmp_xw31_k, real_T
  loctmp_xw32_k, real_T loctmp_xw33_k, real_T loctmp_xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W12d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W21d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W24d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W33d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W34d, real_T loctmp_b_rho, real_T
  loctmp_b_S, real_T loctmp_b_Cbar, real_T loctmp_b_b, real_T loctmp_b_weight,
  real_T loctmp_b_g, real_T loctmp_b_IxxB, real_T loctmp_b_IyyB, real_T
  loctmp_b_IzzB, real_T loctmp_b_IxzB, real_T loctmp_b_CDu, real_T loctmp_b_CDq,
  real_T loctmp_b_CDadot, real_T loctmp_b_CDde, real_T loctmp_b_CD0_bar, real_T
  loctmp_b_Cyb, real_T loctmp_b_Cyp, real_T loctmp_b_Cyr, real_T loctmp_b_Cyda,
  real_T loctmp_b_Cydr, real_T loctmp_b_CL0, real_T loctmp_b_CLa, real_T
  loctmp_b_CLq, real_T loctmp_b_CLadot, real_T loctmp_b_CLu, real_T
  loctmp_b_CLde, real_T loctmp_b_Clb, real_T loctmp_b_Clp, real_T loctmp_b_Clr,
  real_T loctmp_b_Clda, real_T loctmp_b_Cldr, real_T loctmp_b_Cm0, real_T
  loctmp_b_Cma, real_T loctmp_b_Cmq, real_T loctmp_b_Cmadot, real_T loctmp_b_Cmu,
  real_T loctmp_b_Cmde, real_T loctmp_b_Cnb, real_T loctmp_b_Cnp, real_T
  loctmp_b_Cnr, real_T loctmp_b_Cnda, real_T loctmp_b_Cndr, real_T loctmp_b_xT0,
  real_T loctmp_b_xT1, real_T loctmp_b_xT2, real_T loctmp_b_Ptrim, real_T
  loctmp_b_Qtrim, real_T loctmp_b_Rtrim, real_T loctmp_b_Utrim, real_T
  loctmp_b_Athrottle, real_T loctmp_b_Bthrottle, real_T loctmp_b_Aelevator,
  real_T loctmp_b_Belevator, real_T loctmp_b_Aaileron, real_T loctmp_b_Baileron,
  real_T loctmp_b_Arudder, real_T loctmp_b_Brudder, real_T loctmp_b_ThrottleMax,
  real_T loctmp_b_ThrottleMin, real_T loctmp_b_ElevatorMax, real_T
  loctmp_b_ElevatorMin, real_T loctmp_b_AileronMax, real_T loctmp_b_AileronMin,
  real_T loctmp_b_RudderMax, real_T loctmp_b_RudderMin, real_T loctmp_b_KpLat,
  real_T loctmp_b_KiLon, real_T loctmp_b_KpLon, real_T loctmp_b_L, real_T
  loctmp_b_dist2b, real_T loctmp_FL_ann, const real_T loctmp_a_ann_X[40], const
  real_T loctmp_b_ann_X[40], real_T loctmp_c_ann_X, const real_T loctmp_w_ann_X
  [280], const real_T loctmp_a_ann_Y[40], const real_T loctmp_b_ann_Y[40],
  real_T loctmp_c_ann_Y, const real_T loctmp_w_ann_Y[280], const real_T
  loctmp_a_ann_Z[40], const real_T loctmp_b_ann_Z[40], real_T loctmp_c_ann_Z,
  const real_T loctmp_w_ann_Z[280], const real_T loctmp_b_X_minXin[7], const
  real_T loctmp_b_X_maxXin[7], real_T loctmp_b_X_minYin, real_T
  loctmp_b_X_maxYin, real_T loctmp_b_X_minXout, real_T loctmp_b_X_maxXout,
  real_T loctmp_b_X_minYout, real_T loctmp_b_X_maxYout, const real_T
  loctmp_b_Y_minXin[7], const real_T loctmp_b_Y_maxXin[7], real_T
  loctmp_b_Y_minYin, real_T loctmp_b_Y_maxYin, real_T loctmp_b_Y_minXout, real_T
  loctmp_b_Y_maxXout, real_T loctmp_b_Y_minYout, real_T loctmp_b_Y_maxYout,
  const real_T loctmp_b_Z_minXin[7], const real_T loctmp_b_Z_maxXin[7], real_T
  loctmp_b_Z_minYin, real_T loctmp_b_Z_maxYin, real_T loctmp_b_Z_minXout, real_T
  loctmp_b_Z_maxXout, real_T loctmp_b_Z_minYout, real_T loctmp_b_Z_maxYout,
  real32_T *loctmp_distance2b, uint8_T *loctmp_wpt_index_kk, real_T
  *loctmp_pic_cic_kk, uint8_T *loctmp_home_reset_kk, real_T *loctmp_nr_k, real_T
  *loctmp_er_k, real_T *loctmp_hr_k, real_T *loctmp_etaLon_k, real_T
  *loctmp_etaLat_k, real_T *loctmp_VTcmd_k, real_T *loctmp_thetacmd_k, real_T
  *loctmp_phicmd_k, real_T *loctmp_Vab_k, real_T *loctmp_accelX_scd_k, real_T
  *loctmp_accelX_ann_k, real_T *loctmp_accelY_scd_k, real_T *loctmp_accelY_ann_k,
  real_T *loctmp_accelZ_scd_k, real_T *loctmp_accelZ_ann_k, real_T
  loctmp_z_augm_k[12], real_T loctmp_e_augm_k[4], real_T *loctmp_THL_kk, real_T *
  loctmp_EL_kk, real_T *loctmp_AIL_kk, real_T *loctmp_RDR_kk, real_T
  *loctmp_VT_kk, real_T *loctmp_alpha_kk, real_T *loctmp_beta_kk, real_T
  *loctmp_phi_kk, real_T *loctmp_theta_kk, real_T *loctmp_psi_kk, real_T
  *loctmp_P_kk, real_T *loctmp_Q_kk, real_T *loctmp_R_kk, real_T
  *loctmp_falpha_k, real_T *loctmp_fbeta_k, real_T *loctmp_n_kk, real_T
  *loctmp_e_kk, real_T *loctmp_h_kk, real_T *loctmp_ro_kk, real_T
  *loctmp_xw11_kk, real_T *loctmp_xw12_kk, real_T *loctmp_xw13_kk, real_T
  *loctmp_xw14_kk, real_T *loctmp_xw21_kk, real_T *loctmp_xw22_kk, real_T
  *loctmp_xw23_kk, real_T *loctmp_xw24_kk, real_T *loctmp_xw31_kk, real_T
  *loctmp_xw32_kk, real_T *loctmp_xw33_kk, real_T *loctmp_xw34_kk);
static void ANN_EKF_NMPC_2_eml_ipiv2perm(const int32_T loctmp_ipiv[80], int32_T
  loctmp_perm[80]);
static void ANN_EKF_NMPC_2_eml_xtrsm_c(const real_T loctmp_A[6400], real_T
  loctmp_B[6400]);
static void ANN_EKF_NMPC_2_eml_xswap_e(real_T loctmp_x[6400], int32_T loctmp_ix0,
  int32_T loctmp_iy0);
static void ANN_EKF_NMPC_2_invNxN(const real_T loctmp_x[6400], real_T loctmp_y
  [6400]);
static void ANN_EKF_NMPC_2_mpower(const real_T loctmp_a[6400], real_T loctmp_c
  [6400]);
static real_T ANN_EKF_NMPC_2_sum(const boolean_T loctmp_x[40]);
static real_T ANN_EKF_NMPC_2_sum_n(const boolean_T loctmp_x[20]);
static void ANN_EKF_NMPC_2_eml_ipiv2perm_g(const int32_T loctmp_ipiv_data[],
  const int32_T loctmp_ipiv_sizes[2], int32_T loctmp_m, int32_T
  loctmp_perm_data[], int32_T loctmp_perm_sizes[2]);
static void ANN_EKF_NMPC_2_eml_xtrsm_cy(int32_T loctmp_m, int32_T loctmp_n,
  const real_T loctmp_A_data[], int32_T loctmp_lda, real_T loctmp_B_data[],
  int32_T loctmp_ldb);
static void ANN_EKF_NMPC_2_eml_xswap_et(int32_T loctmp_n, real_T loctmp_x_data[],
  int32_T loctmp_ix0, int32_T loctmp_incx, int32_T loctmp_iy0, int32_T
  loctmp_incy);
static void ANN_EKF_NMPC_2_invNxN_h(const real_T loctmp_x_data[], const int32_T
  loctmp_x_sizes[2], real_T loctmp_y_data[], int32_T loctmp_y_sizes[2]);
static void ANN_EKF_NMPC_2_mpower_k(const real_T loctmp_a_data[], const int32_T
  loctmp_a_sizes[2], real_T loctmp_c_data[], int32_T loctmp_c_sizes[2]);
static void ANN_EKF_NMPC_2_squeeze(const real_T loctmp_a[12], real_T loctmp_b_b
  [12]);
static void ANN_EKF_NMPC_2_uas_augm_model_ms(real_T loctmp_sw, boolean_T
  loctmp_home_cmd, real_T loctmp_b_dt, real_T loctmp_b_TR, uint8_T
  loctmp_wpts_fp, uint8_T loctmp_wpts_rp, real_T loctmp_wpts_h[32], real_T
  loctmp_wpts_n[32], real_T loctmp_wpts_e[32], const real_T loctmp_wpts_v[32],
  real_T loctmp_n_op_k, real_T loctmp_e_op_k, real_T loctmp_h_op_k, real_T
  loctmp_vn_op_k, real_T loctmp_ve_op_k, real_T loctmp_vh_op_k, real_T
  loctmp_alphadot_k, real_T loctmp_betadot_k, uint8_T loctmp_wpt_index_k, real_T
  loctmp_start_wpt_k[3], real_T loctmp_pic_cic_k, real_T loctmp_home_reset_k,
  real_T loctmp_THL_k, real_T loctmp_EL_k, real_T loctmp_AIL_k, real_T
  loctmp_RDR_k, real_T loctmp_VT_k, real_T loctmp_alpha_k, real_T loctmp_beta_k,
  real_T loctmp_phi_k, real_T loctmp_theta_k, real_T loctmp_psi_k, real_T
  loctmp_P_k, real_T loctmp_Q_k, real_T loctmp_R_k, real_T loctmp_n_k, real_T
  loctmp_e_k, real_T loctmp_h_k, real_T loctmp_ro_k, real_T loctmp_THLcmd_k,
  real_T loctmp_ELcmd_k, real_T loctmp_AILcmd_k, real_T loctmp_RDRcmd_k, real_T
  loctmp_xw11_k, real_T loctmp_xw12_k, real_T loctmp_xw13_k, real_T
  loctmp_xw14_k, real_T loctmp_xw21_k, real_T loctmp_xw22_k, real_T
  loctmp_xw23_k, real_T loctmp_xw24_k, real_T loctmp_xw31_k, real_T
  loctmp_xw32_k, real_T loctmp_xw33_k, real_T loctmp_xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W12d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W21d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W24d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W33d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W34d, real_T loctmp_b_rho, real_T
  loctmp_b_S, real_T loctmp_b_Cbar, real_T loctmp_b_b, real_T loctmp_b_weight,
  real_T loctmp_b_g, real_T loctmp_b_IxxB, real_T loctmp_b_IyyB, real_T
  loctmp_b_IzzB, real_T loctmp_b_IxzB, real_T loctmp_b_CDu, real_T loctmp_b_CDq,
  real_T loctmp_b_CDadot, real_T loctmp_b_CDde, real_T loctmp_b_CD0_bar, real_T
  loctmp_b_Cyb, real_T loctmp_b_Cyp, real_T loctmp_b_Cyr, real_T loctmp_b_Cyda,
  real_T loctmp_b_Cydr, real_T loctmp_b_CL0, real_T loctmp_b_CLa, real_T
  loctmp_b_CLq, real_T loctmp_b_CLadot, real_T loctmp_b_CLu, real_T
  loctmp_b_CLde, real_T loctmp_b_Clb, real_T loctmp_b_Clp, real_T loctmp_b_Clr,
  real_T loctmp_b_Clda, real_T loctmp_b_Cldr, real_T loctmp_b_Cm0, real_T
  loctmp_b_Cma, real_T loctmp_b_Cmq, real_T loctmp_b_Cmadot, real_T loctmp_b_Cmu,
  real_T loctmp_b_Cmde, real_T loctmp_b_Cnb, real_T loctmp_b_Cnp, real_T
  loctmp_b_Cnr, real_T loctmp_b_Cnda, real_T loctmp_b_Cndr, real_T loctmp_b_xT0,
  real_T loctmp_b_xT1, real_T loctmp_b_xT2, real_T loctmp_b_Ptrim, real_T
  loctmp_b_Qtrim, real_T loctmp_b_Rtrim, real_T loctmp_b_Utrim, real_T
  loctmp_b_Athrottle, real_T loctmp_b_Bthrottle, real_T loctmp_b_Aelevator,
  real_T loctmp_b_Belevator, real_T loctmp_b_Aaileron, real_T loctmp_b_Baileron,
  real_T loctmp_b_Arudder, real_T loctmp_b_Brudder, real_T loctmp_b_ThrottleMax,
  real_T loctmp_b_ThrottleMin, real_T loctmp_b_ElevatorMax, real_T
  loctmp_b_ElevatorMin, real_T loctmp_b_AileronMax, real_T loctmp_b_AileronMin,
  real_T loctmp_b_RudderMax, real_T loctmp_b_RudderMin, real_T loctmp_b_KpLat,
  real_T loctmp_b_KiLon, real_T loctmp_b_KpLon, real_T loctmp_b_L, real_T
  loctmp_b_dist2b, real_T loctmp_FL_ann, const real_T loctmp_a_ann_X[40], const
  real_T loctmp_b_ann_X[40], real_T loctmp_c_ann_X, const real_T loctmp_w_ann_X
  [280], const real_T loctmp_a_ann_Y[40], const real_T loctmp_b_ann_Y[40],
  real_T loctmp_c_ann_Y, const real_T loctmp_w_ann_Y[280], const real_T
  loctmp_a_ann_Z[40], const real_T loctmp_b_ann_Z[40], real_T loctmp_c_ann_Z,
  const real_T loctmp_w_ann_Z[280], const real_T loctmp_b_X_minXin[7], const
  real_T loctmp_b_X_maxXin[7], real_T loctmp_b_X_minYin, real_T
  loctmp_b_X_maxYin, real_T loctmp_b_X_minXout, real_T loctmp_b_X_maxXout,
  real_T loctmp_b_X_minYout, real_T loctmp_b_X_maxYout, const real_T
  loctmp_b_Y_minXin[7], const real_T loctmp_b_Y_maxXin[7], real_T
  loctmp_b_Y_minYin, real_T loctmp_b_Y_maxYin, real_T loctmp_b_Y_minXout, real_T
  loctmp_b_Y_maxXout, real_T loctmp_b_Y_minYout, real_T loctmp_b_Y_maxYout,
  const real_T loctmp_b_Z_minXin[7], const real_T loctmp_b_Z_maxXin[7], real_T
  loctmp_b_Z_minYin, real_T loctmp_b_Z_maxYin, real_T loctmp_b_Z_minXout, real_T
  loctmp_b_Z_maxXout, real_T loctmp_b_Z_minYout, real_T loctmp_b_Z_maxYout,
  real32_T *loctmp_distance2b, uint8_T *loctmp_wpt_index_kk, real_T
  *loctmp_pic_cic_kk, uint8_T *loctmp_home_reset_kk, real_T *loctmp_nr_k, real_T
  *loctmp_er_k, real_T *loctmp_hr_k, real_T *loctmp_etaLon_k, real_T
  *loctmp_etaLat_k, real_T *loctmp_VTcmd_k, real_T *loctmp_thetacmd_k, real_T
  *loctmp_phicmd_k, real_T *loctmp_Vab_k, real_T *loctmp_accelX_scd_k, real_T
  *loctmp_accelX_ann_k, real_T *loctmp_accelY_scd_k, real_T *loctmp_accelY_ann_k,
  real_T *loctmp_accelZ_scd_k, real_T *loctmp_accelZ_ann_k, real_T
  loctmp_z_augm_k[12], real_T loctmp_e_augm_k[4], real_T *loctmp_THL_kk, real_T *
  loctmp_EL_kk, real_T *loctmp_AIL_kk, real_T *loctmp_RDR_kk, real_T
  *loctmp_VT_kk, real_T *loctmp_alpha_kk, real_T *loctmp_beta_kk, real_T
  *loctmp_phi_kk, real_T *loctmp_theta_kk, real_T *loctmp_psi_kk, real_T
  *loctmp_P_kk, real_T *loctmp_Q_kk, real_T *loctmp_R_kk, real_T
  *loctmp_falpha_k, real_T *loctmp_fbeta_k, real_T *loctmp_n_kk, real_T
  *loctmp_e_kk, real_T *loctmp_h_kk, real_T *loctmp_ro_kk, real_T
  *loctmp_xw11_kk, real_T *loctmp_xw12_kk, real_T *loctmp_xw13_kk, real_T
  *loctmp_xw14_kk, real_T *loctmp_xw21_kk, real_T *loctmp_xw22_kk, real_T
  *loctmp_xw23_kk, real_T *loctmp_xw24_kk, real_T *loctmp_xw31_kk, real_T
  *loctmp_xw32_kk, real_T *loctmp_xw33_kk, real_T *loctmp_xw34_kk);
static void ANN_EKF_NMPC_2_nmpc_iteration(real_T loctmp_sw, boolean_T
  loctmp_home_cmd, real_T loctmp_b_dt, real_T loctmp_b_TR, uint8_T
  loctmp_wpts_fp, uint8_T loctmp_wpts_rp, const real_T loctmp_wpts_h[32], const
  real_T loctmp_wpts_n[32], const real_T loctmp_wpts_e[32], const real_T
  loctmp_wpts_v[32], const real_T loctmp_n_op_N[21], const real_T loctmp_e_op_N
  [21], const real_T loctmp_h_op_N[21], const real_T loctmp_vn_op_N[21], const
  real_T loctmp_ve_op_N[21], const real_T loctmp_vh_op_N[21], const real_T
  loctmp_u_hor[84], const real_T loctmp_z_hor[252], const real_T loctmp_n_hor[21],
  const real_T loctmp_e_hor[21], const real_T loctmp_h_hor[21], const real_T
  loctmp_THL_hor[21], const real_T loctmp_EL_hor[21], const real_T
  loctmp_AIL_hor[21], const real_T loctmp_RDR_hor[21], const real_T
  loctmp_VT_hor[21], const real_T loctmp_alpha_hor[21], const real_T
  loctmp_beta_hor[21], const real_T loctmp_phi_hor[21], const real_T
  loctmp_theta_hor[21], const real_T loctmp_psi_hor[21], const real_T
  loctmp_P_hor[21], const real_T loctmp_Q_hor[21], const real_T loctmp_R_hor[21],
  const real_T loctmp_wpt_index_hor[21], const real_T loctmp_start_wpt_hor[63],
  const real_T loctmp_pic_cic_hor[21], const real_T loctmp_home_reset_hor[21],
  const real_T loctmp_alphadot_hor[21], const real_T loctmp_betadot_hor[21],
  const real_T loctmp_ro_hor[21], const real_T loctmp_xw11_hor[21], const real_T
  loctmp_xw12_hor[21], const real_T loctmp_xw13_hor[21], const real_T
  loctmp_xw14_hor[21], const real_T loctmp_xw21_hor[21], const real_T
  loctmp_xw22_hor[21], const real_T loctmp_xw23_hor[21], const real_T
  loctmp_xw24_hor[21], const real_T loctmp_xw31_hor[21], const real_T
  loctmp_xw32_hor[21], const real_T loctmp_xw33_hor[21], const real_T
  loctmp_xw34_hor[21], const struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W12d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W21d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W24d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W33d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W34d, real_T loctmp_b_rho, real_T
  loctmp_b_S, real_T loctmp_b_Cbar, real_T loctmp_b_b, real_T loctmp_b_weight,
  real_T loctmp_b_g, real_T loctmp_b_IxxB, real_T loctmp_b_IyyB, real_T
  loctmp_b_IzzB, real_T loctmp_b_IxzB, real_T loctmp_b_CDu, real_T loctmp_b_CDq,
  real_T loctmp_b_CDadot, real_T loctmp_b_CDde, real_T loctmp_b_CD0_bar, real_T
  loctmp_b_Cyb, real_T loctmp_b_Cyp, real_T loctmp_b_Cyr, real_T loctmp_b_Cyda,
  real_T loctmp_b_Cydr, real_T loctmp_b_CL0, real_T loctmp_b_CLa, real_T
  loctmp_b_CLq, real_T loctmp_b_CLadot, real_T loctmp_b_CLu, real_T
  loctmp_b_CLde, real_T loctmp_b_Clb, real_T loctmp_b_Clp, real_T loctmp_b_Clr,
  real_T loctmp_b_Clda, real_T loctmp_b_Cldr, real_T loctmp_b_Cm0, real_T
  loctmp_b_Cma, real_T loctmp_b_Cmq, real_T loctmp_b_Cmadot, real_T loctmp_b_Cmu,
  real_T loctmp_b_Cmde, real_T loctmp_b_Cnb, real_T loctmp_b_Cnp, real_T
  loctmp_b_Cnr, real_T loctmp_b_Cnda, real_T loctmp_b_Cndr, real_T loctmp_b_xT0,
  real_T loctmp_b_xT1, real_T loctmp_b_xT2, real_T loctmp_b_Ptrim, real_T
  loctmp_b_Qtrim, real_T loctmp_b_Rtrim, real_T loctmp_b_Utrim, real_T
  loctmp_b_Athrottle, real_T loctmp_b_Bthrottle, real_T loctmp_b_Aelevator,
  real_T loctmp_b_Belevator, real_T loctmp_b_Aaileron, real_T loctmp_b_Baileron,
  real_T loctmp_b_Arudder, real_T loctmp_b_Brudder, real_T loctmp_b_ThrottleMax,
  real_T loctmp_b_ThrottleMin, real_T loctmp_b_ElevatorMax, real_T
  loctmp_b_ElevatorMin, real_T loctmp_b_AileronMax, real_T loctmp_b_AileronMin,
  real_T loctmp_b_RudderMax, real_T loctmp_b_RudderMin, real_T loctmp_b_KpLat,
  real_T loctmp_b_KiLon, real_T loctmp_b_KpLon, real_T loctmp_b_L, real_T
  loctmp_b_dist2b, real_T loctmp_FL_ann, const real_T loctmp_a_ann_X[40], const
  real_T loctmp_b_ann_X[40], real_T loctmp_c_ann_X, const real_T loctmp_w_ann_X
  [280], const real_T loctmp_a_ann_Y[40], const real_T loctmp_b_ann_Y[40],
  real_T loctmp_c_ann_Y, const real_T loctmp_w_ann_Y[280], const real_T
  loctmp_a_ann_Z[40], const real_T loctmp_b_ann_Z[40], real_T loctmp_c_ann_Z,
  const real_T loctmp_w_ann_Z[280], const real_T loctmp_b_X_minXin[7], const
  real_T loctmp_b_X_maxXin[7], real_T loctmp_b_X_minYin, real_T
  loctmp_b_X_maxYin, real_T loctmp_b_X_minXout, real_T loctmp_b_X_maxXout,
  real_T loctmp_b_X_minYout, real_T loctmp_b_X_maxYout, const real_T
  loctmp_b_Y_minXin[7], const real_T loctmp_b_Y_maxXin[7], real_T
  loctmp_b_Y_minYin, real_T loctmp_b_Y_maxYin, real_T loctmp_b_Y_minXout, real_T
  loctmp_b_Y_maxXout, real_T loctmp_b_Y_minYout, real_T loctmp_b_Y_maxYout,
  const real_T loctmp_b_Z_minXin[7], const real_T loctmp_b_Z_maxXin[7], real_T
  loctmp_b_Z_minYin, real_T loctmp_b_Z_maxYin, real_T loctmp_b_Z_minXout, real_T
  loctmp_b_Z_maxXout, real_T loctmp_b_Z_minYout, real_T loctmp_b_Z_maxYout,
  real_T loctmp_u_nmpc[84], real_T *loctmp_V_nmpc);
static void ANN_EKF_NMPC_2_uas_augm_model_m(real_T loctmp_sw, boolean_T
  loctmp_home_cmd, real_T loctmp_b_dt, real_T loctmp_b_TR, uint8_T
  loctmp_wpts_fp, uint8_T loctmp_wpts_rp, real_T loctmp_wpts_h[32], real_T
  loctmp_wpts_n[32], real_T loctmp_wpts_e[32], const real_T loctmp_wpts_v[32],
  real_T loctmp_n_op_k, real_T loctmp_e_op_k, real_T loctmp_h_op_k, real_T
  loctmp_vn_op_k, real_T loctmp_ve_op_k, real_T loctmp_vh_op_k, real_T
  loctmp_alphadot_k, real_T loctmp_betadot_k, real_T loctmp_wpt_index_k, real_T
  loctmp_start_wpt_k[3], real_T loctmp_pic_cic_k, real_T loctmp_home_reset_k,
  real_T loctmp_THL_k, real_T loctmp_EL_k, real_T loctmp_AIL_k, real_T
  loctmp_RDR_k, real_T loctmp_VT_k, real_T loctmp_alpha_k, real_T loctmp_beta_k,
  real_T loctmp_phi_k, real_T loctmp_theta_k, real_T loctmp_psi_k, real_T
  loctmp_P_k, real_T loctmp_Q_k, real_T loctmp_R_k, real_T loctmp_n_k, real_T
  loctmp_e_k, real_T loctmp_h_k, real_T loctmp_ro_k, real_T loctmp_THLcmd_k,
  real_T loctmp_ELcmd_k, real_T loctmp_AILcmd_k, real_T loctmp_RDRcmd_k, real_T
  loctmp_xw11_k, real_T loctmp_xw12_k, real_T loctmp_xw13_k, real_T
  loctmp_xw14_k, real_T loctmp_xw21_k, real_T loctmp_xw22_k, real_T
  loctmp_xw23_k, real_T loctmp_xw24_k, real_T loctmp_xw31_k, real_T
  loctmp_xw32_k, real_T loctmp_xw33_k, real_T loctmp_xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W12d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W21d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W24d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W33d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W34d, real_T loctmp_b_rho, real_T
  loctmp_b_S, real_T loctmp_b_Cbar, real_T loctmp_b_b, real_T loctmp_b_weight,
  real_T loctmp_b_g, real_T loctmp_b_IxxB, real_T loctmp_b_IyyB, real_T
  loctmp_b_IzzB, real_T loctmp_b_IxzB, real_T loctmp_b_CDu, real_T loctmp_b_CDq,
  real_T loctmp_b_CDadot, real_T loctmp_b_CDde, real_T loctmp_b_CD0_bar, real_T
  loctmp_b_Cyb, real_T loctmp_b_Cyp, real_T loctmp_b_Cyr, real_T loctmp_b_Cyda,
  real_T loctmp_b_Cydr, real_T loctmp_b_CL0, real_T loctmp_b_CLa, real_T
  loctmp_b_CLq, real_T loctmp_b_CLadot, real_T loctmp_b_CLu, real_T
  loctmp_b_CLde, real_T loctmp_b_Clb, real_T loctmp_b_Clp, real_T loctmp_b_Clr,
  real_T loctmp_b_Clda, real_T loctmp_b_Cldr, real_T loctmp_b_Cm0, real_T
  loctmp_b_Cma, real_T loctmp_b_Cmq, real_T loctmp_b_Cmadot, real_T loctmp_b_Cmu,
  real_T loctmp_b_Cmde, real_T loctmp_b_Cnb, real_T loctmp_b_Cnp, real_T
  loctmp_b_Cnr, real_T loctmp_b_Cnda, real_T loctmp_b_Cndr, real_T loctmp_b_xT0,
  real_T loctmp_b_xT1, real_T loctmp_b_xT2, real_T loctmp_b_Ptrim, real_T
  loctmp_b_Qtrim, real_T loctmp_b_Rtrim, real_T loctmp_b_Utrim, real_T
  loctmp_b_Athrottle, real_T loctmp_b_Bthrottle, real_T loctmp_b_Aelevator,
  real_T loctmp_b_Belevator, real_T loctmp_b_Aaileron, real_T loctmp_b_Baileron,
  real_T loctmp_b_Arudder, real_T loctmp_b_Brudder, real_T loctmp_b_ThrottleMax,
  real_T loctmp_b_ThrottleMin, real_T loctmp_b_ElevatorMax, real_T
  loctmp_b_ElevatorMin, real_T loctmp_b_AileronMax, real_T loctmp_b_AileronMin,
  real_T loctmp_b_RudderMax, real_T loctmp_b_RudderMin, real_T loctmp_b_KpLat,
  real_T loctmp_b_KiLon, real_T loctmp_b_KpLon, real_T loctmp_b_L, real_T
  loctmp_b_dist2b, real_T loctmp_FL_ann, const real_T loctmp_a_ann_X[40], const
  real_T loctmp_b_ann_X[40], real_T loctmp_c_ann_X, const real_T loctmp_w_ann_X
  [280], const real_T loctmp_a_ann_Y[40], const real_T loctmp_b_ann_Y[40],
  real_T loctmp_c_ann_Y, const real_T loctmp_w_ann_Y[280], const real_T
  loctmp_a_ann_Z[40], const real_T loctmp_b_ann_Z[40], real_T loctmp_c_ann_Z,
  const real_T loctmp_w_ann_Z[280], const real_T loctmp_b_X_minXin[7], const
  real_T loctmp_b_X_maxXin[7], real_T loctmp_b_X_minYin, real_T
  loctmp_b_X_maxYin, real_T loctmp_b_X_minXout, real_T loctmp_b_X_maxXout,
  real_T loctmp_b_X_minYout, real_T loctmp_b_X_maxYout, const real_T
  loctmp_b_Y_minXin[7], const real_T loctmp_b_Y_maxXin[7], real_T
  loctmp_b_Y_minYin, real_T loctmp_b_Y_maxYin, real_T loctmp_b_Y_minXout, real_T
  loctmp_b_Y_maxXout, real_T loctmp_b_Y_minYout, real_T loctmp_b_Y_maxYout,
  const real_T loctmp_b_Z_minXin[7], const real_T loctmp_b_Z_maxXin[7], real_T
  loctmp_b_Z_minYin, real_T loctmp_b_Z_maxYin, real_T loctmp_b_Z_minXout, real_T
  loctmp_b_Z_maxXout, real_T loctmp_b_Z_minYout, real_T loctmp_b_Z_maxYout,
  real32_T *loctmp_distance2b, uint8_T *loctmp_wpt_index_kk, real_T
  *loctmp_pic_cic_kk, uint8_T *loctmp_home_reset_kk, real_T *loctmp_nr_k, real_T
  *loctmp_er_k, real_T *loctmp_hr_k, real_T *loctmp_etaLon_k, real_T
  *loctmp_etaLat_k, real_T *loctmp_VTcmd_k, real_T *loctmp_thetacmd_k, real_T
  *loctmp_phicmd_k, real_T *loctmp_Vab_k, real_T *loctmp_accelX_scd_k, real_T
  *loctmp_accelX_ann_k, real_T *loctmp_accelY_scd_k, real_T *loctmp_accelY_ann_k,
  real_T *loctmp_accelZ_scd_k, real_T *loctmp_accelZ_ann_k, real_T
  loctmp_z_augm_k[12], real_T loctmp_e_augm_k[4], real_T *loctmp_THL_kk, real_T *
  loctmp_EL_kk, real_T *loctmp_AIL_kk, real_T *loctmp_RDR_kk, real_T
  *loctmp_VT_kk, real_T *loctmp_alpha_kk, real_T *loctmp_beta_kk, real_T
  *loctmp_phi_kk, real_T *loctmp_theta_kk, real_T *loctmp_psi_kk, real_T
  *loctmp_P_kk, real_T *loctmp_Q_kk, real_T *loctmp_R_kk, real_T
  *loctmp_falpha_k, real_T *loctmp_fbeta_k, real_T *loctmp_n_kk, real_T
  *loctmp_e_kk, real_T *loctmp_h_kk, real_T *loctmp_ro_kk, real_T
  *loctmp_xw11_kk, real_T *loctmp_xw12_kk, real_T *loctmp_xw13_kk, real_T
  *loctmp_xw14_kk, real_T *loctmp_xw21_kk, real_T *loctmp_xw22_kk, real_T
  *loctmp_xw23_kk, real_T *loctmp_xw24_kk, real_T *loctmp_xw31_kk, real_T
  *loctmp_xw32_kk, real_T *loctmp_xw33_kk, real_T *loctmp_xw34_kk);

/*
 * Output and update for atomic system:
 *    '<S23>/Subsystem1'
 *    '<S24>/Subsystem2'
 *    '<S24>/Subsystem3'
 */
void ANN_EKF_NMPC_2_Subsystem1(real_T rtu_u, real_T rtu_u_k,
  B_Subsystem1_ANN_EKF_NMPC_2_T *localB)
{
  /* Sqrt: '<S32>/Sqrt' incorporates:
   *  Math: '<S32>/Math Function2'
   *  SignalConversion: '<S32>/TmpSignal ConversionAtMath Function2Inport1'
   *  Sum: '<S32>/Sum of Elements'
   */
  localB->Sqrt = sqrt(rtu_u * rtu_u + rtu_u_k * rtu_u_k);
}

/* Output and update for atomic system: '<S23>/Subsystem4' */
void ANN_EKF_NMPC_2_Subsystem4(real_T rtu_u, real_T rtu_u_h,
  B_Subsystem4_ANN_EKF_NMPC_2_T *localB)
{
  /* Sum: '<S33>/Sum of Elements' incorporates:
   *  Math: '<S33>/Math Function2'
   *  SignalConversion: '<S33>/TmpSignal ConversionAtMath Function2Inport1'
   */
  localB->SumofElements = rtu_u * rtu_u + rtu_u_h * rtu_u_h;
}

/*
 * Output and update for atomic system:
 *    '<S24>/Subsystem1'
 *    '<S25>/Subsystem1'
 *    '<S41>/Subsystem1'
 */
void ANN_EKF_NMPC_2_Subsystem1_p(real_T rtu_u, real_T rtu_u_n, real_T rtu_u_d,
  B_Subsystem1_ANN_EKF_NMPC_2_d_T *localB)
{
  /* Sqrt: '<S34>/Sqrt' incorporates:
   *  Math: '<S34>/Math Function2'
   *  SignalConversion: '<S34>/TmpSignal ConversionAtMath Function2Inport1'
   *  Sum: '<S34>/Sum of Elements'
   */
  localB->Sqrt = sqrt((rtu_u * rtu_u + rtu_u_n * rtu_u_n) + rtu_u_d * rtu_u_d);
}

/* Output and update for atomic system: '<S24>/Subsystem4' */
void ANN_EKF_NMPC_2_Subsystem4_k(real_T rtu_u, real_T rtu_u_g, real_T rtu_u_b,
  B_Subsystem4_ANN_EKF_NMPC_2_k_T *localB)
{
  /* Sum: '<S37>/Sum of Elements' incorporates:
   *  Math: '<S37>/Math Function2'
   *  SignalConversion: '<S37>/TmpSignal ConversionAtMath Function2Inport1'
   */
  localB->SumofElements = (rtu_u * rtu_u + rtu_u_g * rtu_u_g) + rtu_u_b *
    rtu_u_b;
}

/* Function for MATLAB Function: '<S62>/Inverse' */
static void ANN_EKF_NMPC_2_invNxN_c(const real_T loctmp_x[36], real_T loctmp_y
  [36])
{
  int8_T loctmp_p[6];
  real_T loctmp_A[36];
  int8_T loctmp_ipiv[6];
  int32_T loctmp_b_j;
  int32_T loctmp_b_c;
  int32_T loctmp_ix;
  real_T loctmp_smax;
  real_T loctmp_s;
  int32_T loctmp_jy;
  int32_T loctmp_c_ix;
  int32_T loctmp_ijA;
  int32_T loctmp_jBcol;
  int32_T loctmp_kAcol;
  for (loctmp_b_j = 0; loctmp_b_j < 36; loctmp_b_j++) {
    loctmp_y[loctmp_b_j] = 0.0;
    loctmp_A[loctmp_b_j] = loctmp_x[loctmp_b_j];
  }

  for (loctmp_b_j = 0; loctmp_b_j < 6; loctmp_b_j++) {
    loctmp_ipiv[loctmp_b_j] = (int8_T)(1 + loctmp_b_j);
  }

  for (loctmp_b_j = 0; loctmp_b_j < 5; loctmp_b_j++) {
    loctmp_b_c = loctmp_b_j * 7;
    loctmp_jy = 0;
    loctmp_ix = loctmp_b_c;
    loctmp_smax = fabs(loctmp_A[loctmp_b_c]);
    for (loctmp_jBcol = 2; loctmp_jBcol <= 6 - loctmp_b_j; loctmp_jBcol++) {
      loctmp_ix++;
      loctmp_s = fabs(loctmp_A[loctmp_ix]);
      if (loctmp_s > loctmp_smax) {
        loctmp_jy = loctmp_jBcol - 1;
        loctmp_smax = loctmp_s;
      }
    }

    if (loctmp_A[loctmp_b_c + loctmp_jy] != 0.0) {
      if (loctmp_jy != 0) {
        loctmp_ipiv[loctmp_b_j] = (int8_T)((loctmp_b_j + loctmp_jy) + 1);
        loctmp_kAcol = loctmp_b_j;
        loctmp_jBcol = loctmp_b_j + loctmp_jy;
        for (loctmp_jy = 0; loctmp_jy < 6; loctmp_jy++) {
          loctmp_smax = loctmp_A[loctmp_kAcol];
          loctmp_A[loctmp_kAcol] = loctmp_A[loctmp_jBcol];
          loctmp_A[loctmp_jBcol] = loctmp_smax;
          loctmp_kAcol += 6;
          loctmp_jBcol += 6;
        }
      }

      loctmp_ix = (loctmp_b_c - loctmp_b_j) + 6;
      for (loctmp_jBcol = loctmp_b_c + 1; loctmp_jBcol + 1 <= loctmp_ix;
           loctmp_jBcol++) {
        loctmp_A[loctmp_jBcol] /= loctmp_A[loctmp_b_c];
      }
    }

    loctmp_jBcol = loctmp_b_c;
    loctmp_jy = loctmp_b_c + 6;
    for (loctmp_kAcol = 1; loctmp_kAcol <= 5 - loctmp_b_j; loctmp_kAcol++) {
      loctmp_smax = loctmp_A[loctmp_jy];
      if (loctmp_A[loctmp_jy] != 0.0) {
        loctmp_c_ix = loctmp_b_c + 1;
        loctmp_ix = (loctmp_jBcol - loctmp_b_j) + 12;
        for (loctmp_ijA = 7 + loctmp_jBcol; loctmp_ijA + 1 <= loctmp_ix;
             loctmp_ijA++) {
          loctmp_A[loctmp_ijA] += loctmp_A[loctmp_c_ix] * -loctmp_smax;
          loctmp_c_ix++;
        }
      }

      loctmp_jy += 6;
      loctmp_jBcol += 6;
    }
  }

  for (loctmp_b_j = 0; loctmp_b_j < 6; loctmp_b_j++) {
    loctmp_p[loctmp_b_j] = (int8_T)(1 + loctmp_b_j);
  }

  for (loctmp_ix = 0; loctmp_ix < 5; loctmp_ix++) {
    if (loctmp_ipiv[loctmp_ix] > 1 + loctmp_ix) {
      loctmp_jBcol = loctmp_p[loctmp_ipiv[loctmp_ix] - 1];
      loctmp_p[loctmp_ipiv[loctmp_ix] - 1] = loctmp_p[loctmp_ix];
      loctmp_p[loctmp_ix] = (int8_T)loctmp_jBcol;
    }
  }

  for (loctmp_ix = 0; loctmp_ix < 6; loctmp_ix++) {
    loctmp_jBcol = loctmp_p[loctmp_ix] - 1;
    loctmp_y[loctmp_ix + 6 * (loctmp_p[loctmp_ix] - 1)] = 1.0;
    for (loctmp_jy = loctmp_ix; loctmp_jy + 1 < 7; loctmp_jy++) {
      if (loctmp_y[6 * loctmp_jBcol + loctmp_jy] != 0.0) {
        for (loctmp_kAcol = loctmp_jy + 1; loctmp_kAcol + 1 < 7; loctmp_kAcol++)
        {
          loctmp_y[loctmp_kAcol + 6 * loctmp_jBcol] -= loctmp_y[6 * loctmp_jBcol
            + loctmp_jy] * loctmp_A[6 * loctmp_jy + loctmp_kAcol];
        }
      }
    }
  }

  for (loctmp_ix = 0; loctmp_ix < 6; loctmp_ix++) {
    loctmp_jBcol = 6 * loctmp_ix;
    for (loctmp_jy = 5; loctmp_jy >= 0; loctmp_jy += -1) {
      loctmp_kAcol = 6 * loctmp_jy;
      if (loctmp_y[loctmp_jy + loctmp_jBcol] != 0.0) {
        loctmp_y[loctmp_jy + loctmp_jBcol] /= loctmp_A[loctmp_jy + loctmp_kAcol];
        for (loctmp_c_ix = 0; loctmp_c_ix + 1 <= loctmp_jy; loctmp_c_ix++) {
          loctmp_y[loctmp_c_ix + loctmp_jBcol] -= loctmp_y[loctmp_jy +
            loctmp_jBcol] * loctmp_A[loctmp_c_ix + loctmp_kAcol];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S153>/Inverse' */
static void ANN_EKF_NMPC_2_invNxN_a(const real_T loctmp_x[64], real_T loctmp_y
  [64])
{
  int8_T loctmp_p[8];
  real_T loctmp_A[64];
  int8_T loctmp_ipiv[8];
  int32_T loctmp_b_j;
  int32_T loctmp_b_c;
  int32_T loctmp_ix;
  real_T loctmp_smax;
  real_T loctmp_s;
  int32_T loctmp_jy;
  int32_T loctmp_c_ix;
  int32_T loctmp_ijA;
  int32_T loctmp_jBcol;
  int32_T loctmp_kAcol;
  for (loctmp_b_j = 0; loctmp_b_j < 64; loctmp_b_j++) {
    loctmp_y[loctmp_b_j] = 0.0;
    loctmp_A[loctmp_b_j] = loctmp_x[loctmp_b_j];
  }

  for (loctmp_b_j = 0; loctmp_b_j < 8; loctmp_b_j++) {
    loctmp_ipiv[loctmp_b_j] = (int8_T)(1 + loctmp_b_j);
  }

  for (loctmp_b_j = 0; loctmp_b_j < 7; loctmp_b_j++) {
    loctmp_b_c = loctmp_b_j * 9;
    loctmp_jy = 0;
    loctmp_ix = loctmp_b_c;
    loctmp_smax = fabs(loctmp_A[loctmp_b_c]);
    for (loctmp_jBcol = 2; loctmp_jBcol <= 8 - loctmp_b_j; loctmp_jBcol++) {
      loctmp_ix++;
      loctmp_s = fabs(loctmp_A[loctmp_ix]);
      if (loctmp_s > loctmp_smax) {
        loctmp_jy = loctmp_jBcol - 1;
        loctmp_smax = loctmp_s;
      }
    }

    if (loctmp_A[loctmp_b_c + loctmp_jy] != 0.0) {
      if (loctmp_jy != 0) {
        loctmp_ipiv[loctmp_b_j] = (int8_T)((loctmp_b_j + loctmp_jy) + 1);
        loctmp_kAcol = loctmp_b_j;
        loctmp_jBcol = loctmp_b_j + loctmp_jy;
        for (loctmp_jy = 0; loctmp_jy < 8; loctmp_jy++) {
          loctmp_smax = loctmp_A[loctmp_kAcol];
          loctmp_A[loctmp_kAcol] = loctmp_A[loctmp_jBcol];
          loctmp_A[loctmp_jBcol] = loctmp_smax;
          loctmp_kAcol += 8;
          loctmp_jBcol += 8;
        }
      }

      loctmp_ix = (loctmp_b_c - loctmp_b_j) + 8;
      for (loctmp_jBcol = loctmp_b_c + 1; loctmp_jBcol + 1 <= loctmp_ix;
           loctmp_jBcol++) {
        loctmp_A[loctmp_jBcol] /= loctmp_A[loctmp_b_c];
      }
    }

    loctmp_jBcol = loctmp_b_c;
    loctmp_jy = loctmp_b_c + 8;
    for (loctmp_kAcol = 1; loctmp_kAcol <= 7 - loctmp_b_j; loctmp_kAcol++) {
      loctmp_smax = loctmp_A[loctmp_jy];
      if (loctmp_A[loctmp_jy] != 0.0) {
        loctmp_c_ix = loctmp_b_c + 1;
        loctmp_ix = (loctmp_jBcol - loctmp_b_j) + 16;
        for (loctmp_ijA = 9 + loctmp_jBcol; loctmp_ijA + 1 <= loctmp_ix;
             loctmp_ijA++) {
          loctmp_A[loctmp_ijA] += loctmp_A[loctmp_c_ix] * -loctmp_smax;
          loctmp_c_ix++;
        }
      }

      loctmp_jy += 8;
      loctmp_jBcol += 8;
    }
  }

  for (loctmp_b_j = 0; loctmp_b_j < 8; loctmp_b_j++) {
    loctmp_p[loctmp_b_j] = (int8_T)(1 + loctmp_b_j);
  }

  for (loctmp_ix = 0; loctmp_ix < 7; loctmp_ix++) {
    if (loctmp_ipiv[loctmp_ix] > 1 + loctmp_ix) {
      loctmp_jBcol = loctmp_p[loctmp_ipiv[loctmp_ix] - 1];
      loctmp_p[loctmp_ipiv[loctmp_ix] - 1] = loctmp_p[loctmp_ix];
      loctmp_p[loctmp_ix] = (int8_T)loctmp_jBcol;
    }
  }

  for (loctmp_ix = 0; loctmp_ix < 8; loctmp_ix++) {
    loctmp_jBcol = loctmp_p[loctmp_ix] - 1;
    loctmp_y[loctmp_ix + ((loctmp_p[loctmp_ix] - 1) << 3)] = 1.0;
    for (loctmp_jy = loctmp_ix; loctmp_jy + 1 < 9; loctmp_jy++) {
      if (loctmp_y[(loctmp_jBcol << 3) + loctmp_jy] != 0.0) {
        for (loctmp_kAcol = loctmp_jy + 1; loctmp_kAcol + 1 < 9; loctmp_kAcol++)
        {
          loctmp_y[loctmp_kAcol + (loctmp_jBcol << 3)] -= loctmp_y[(loctmp_jBcol
            << 3) + loctmp_jy] * loctmp_A[(loctmp_jy << 3) + loctmp_kAcol];
        }
      }
    }
  }

  for (loctmp_ix = 0; loctmp_ix < 8; loctmp_ix++) {
    loctmp_jBcol = loctmp_ix << 3;
    for (loctmp_jy = 7; loctmp_jy >= 0; loctmp_jy += -1) {
      loctmp_kAcol = loctmp_jy << 3;
      if (loctmp_y[loctmp_jy + loctmp_jBcol] != 0.0) {
        loctmp_y[loctmp_jy + loctmp_jBcol] /= loctmp_A[loctmp_jy + loctmp_kAcol];
        for (loctmp_c_ix = 0; loctmp_c_ix + 1 <= loctmp_jy; loctmp_c_ix++) {
          loctmp_y[loctmp_c_ix + loctmp_jBcol] -= loctmp_y[loctmp_jy +
            loctmp_jBcol] * loctmp_A[loctmp_c_ix + loctmp_kAcol];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S1>/ann' */
static void ANN_EKF_NMPC_2_eye(real_T loctmp_I[130321])
{
  int32_T loctmp_k;
  memset(&loctmp_I[0], 0, 130321U * sizeof(real_T));
  for (loctmp_k = 0; loctmp_k < 361; loctmp_k++) {
    loctmp_I[loctmp_k + 361 * loctmp_k] = 1.0;
  }
}

/* Function for MATLAB Function: '<S1>/ann' */
static void ANN_EKF_NMPC_2_eml_xtrsm(const real_T loctmp_A[130321], real_T
  loctmp_B[361])
{
  int32_T loctmp_kAcol;
  int32_T loctmp_k;
  int32_T loctmp_i;
  for (loctmp_k = 0; loctmp_k < 361; loctmp_k++) {
    loctmp_kAcol = 361 * loctmp_k;
    if (loctmp_B[loctmp_k] != 0.0) {
      for (loctmp_i = loctmp_k + 1; loctmp_i + 1 < 362; loctmp_i++) {
        loctmp_B[loctmp_i] -= loctmp_A[loctmp_i + loctmp_kAcol] *
          loctmp_B[loctmp_k];
      }
    }
  }
}

/* Function for MATLAB Function: '<S1>/ann' */
static void ANN_EKF_NMPC_2_eml_xtrsm_b(const real_T loctmp_A[130321], real_T
  loctmp_B[361])
{
  int32_T loctmp_kAcol;
  int32_T loctmp_k;
  int32_T loctmp_i;
  for (loctmp_k = 360; loctmp_k >= 0; loctmp_k += -1) {
    loctmp_kAcol = 361 * loctmp_k;
    if (loctmp_B[loctmp_k] != 0.0) {
      loctmp_B[loctmp_k] /= loctmp_A[loctmp_k + loctmp_kAcol];
      for (loctmp_i = 0; loctmp_i + 1 <= loctmp_k; loctmp_i++) {
        loctmp_B[loctmp_i] -= loctmp_A[loctmp_i + loctmp_kAcol] *
          loctmp_B[loctmp_k];
      }
    }
  }
}

/* Function for MATLAB Function: '<S1>/ann' */
static void ANN_EKF_NMPC_2_eml_xswap(real_T loctmp_x[130321], int32_T loctmp_ix0,
  int32_T loctmp_iy0)
{
  int32_T loctmp_ix;
  int32_T loctmp_iy;
  real_T loctmp_temp;
  int32_T loctmp_k;
  loctmp_ix = loctmp_ix0 - 1;
  loctmp_iy = loctmp_iy0 - 1;
  for (loctmp_k = 0; loctmp_k < 361; loctmp_k++) {
    loctmp_temp = loctmp_x[loctmp_ix];
    loctmp_x[loctmp_ix] = loctmp_x[loctmp_iy];
    loctmp_x[loctmp_iy] = loctmp_temp;
    loctmp_ix += 361;
    loctmp_iy += 361;
  }
}

/* Function for MATLAB Function: '<S1>/ann' */
static void ANN_EKF_NMPC_2_mldivide(const real_T loctmp_A[130321], real_T
  loctmp_B[361])
{
  real_T loctmp_temp;
  int16_T loctmp_ipiv[361];
  int32_T loctmp_j;
  int32_T loctmp_c;
  int32_T loctmp_ix;
  real_T loctmp_s;
  int32_T loctmp_k;
  int32_T loctmp_jA;
  int32_T loctmp_b_ix;
  int32_T loctmp_d;
  int32_T loctmp_ijA;
  memcpy(&ANN_EKF_NMPC_2_B.b_A[0], &loctmp_A[0], 130321U * sizeof(real_T));
  for (loctmp_j = 0; loctmp_j < 361; loctmp_j++) {
    loctmp_ipiv[loctmp_j] = (int16_T)(1 + loctmp_j);
  }

  for (loctmp_j = 0; loctmp_j < 360; loctmp_j++) {
    loctmp_c = loctmp_j * 362;
    loctmp_jA = 1;
    loctmp_ix = loctmp_c;
    loctmp_temp = fabs(ANN_EKF_NMPC_2_B.b_A[loctmp_c]);
    for (loctmp_k = 2; loctmp_k <= 361 - loctmp_j; loctmp_k++) {
      loctmp_ix++;
      loctmp_s = fabs(ANN_EKF_NMPC_2_B.b_A[loctmp_ix]);
      if (loctmp_s > loctmp_temp) {
        loctmp_jA = loctmp_k;
        loctmp_temp = loctmp_s;
      }
    }

    if (ANN_EKF_NMPC_2_B.b_A[(loctmp_c + loctmp_jA) - 1] != 0.0) {
      if (loctmp_jA - 1 != 0) {
        loctmp_ipiv[loctmp_j] = (int16_T)(loctmp_j + loctmp_jA);
        ANN_EKF_NMPC_2_eml_xswap(ANN_EKF_NMPC_2_B.b_A, loctmp_j + 1, loctmp_j +
          loctmp_jA);
      }

      loctmp_jA = (loctmp_c - loctmp_j) + 361;
      for (loctmp_ix = loctmp_c + 1; loctmp_ix + 1 <= loctmp_jA; loctmp_ix++) {
        ANN_EKF_NMPC_2_B.b_A[loctmp_ix] /= ANN_EKF_NMPC_2_B.b_A[loctmp_c];
      }
    }

    loctmp_jA = loctmp_c;
    loctmp_ix = loctmp_c + 361;
    for (loctmp_k = 1; loctmp_k <= 360 - loctmp_j; loctmp_k++) {
      loctmp_temp = ANN_EKF_NMPC_2_B.b_A[loctmp_ix];
      if (ANN_EKF_NMPC_2_B.b_A[loctmp_ix] != 0.0) {
        loctmp_b_ix = loctmp_c + 1;
        loctmp_d = (loctmp_jA - loctmp_j) + 722;
        for (loctmp_ijA = 362 + loctmp_jA; loctmp_ijA + 1 <= loctmp_d;
             loctmp_ijA++) {
          ANN_EKF_NMPC_2_B.b_A[loctmp_ijA] += ANN_EKF_NMPC_2_B.b_A[loctmp_b_ix] *
            -loctmp_temp;
          loctmp_b_ix++;
        }
      }

      loctmp_ix += 361;
      loctmp_jA += 361;
    }
  }

  for (loctmp_jA = 0; loctmp_jA < 360; loctmp_jA++) {
    if (loctmp_jA + 1 != loctmp_ipiv[loctmp_jA]) {
      loctmp_temp = loctmp_B[loctmp_jA];
      loctmp_B[loctmp_jA] = loctmp_B[loctmp_ipiv[loctmp_jA] - 1];
      loctmp_B[loctmp_ipiv[loctmp_jA] - 1] = loctmp_temp;
    }
  }

  ANN_EKF_NMPC_2_eml_xtrsm(ANN_EKF_NMPC_2_B.b_A, loctmp_B);
  ANN_EKF_NMPC_2_eml_xtrsm_b(ANN_EKF_NMPC_2_B.b_A, loctmp_B);
}

/* Function for MATLAB Function: '<S1>/ann' */
static void ANN_EKF_NMPC_2_ann_iteration(const real_T loctmp_x_ann[49], const
  real_T loctmp_y_ann[7], real_T loctmp_a_ann[40], real_T loctmp_b_ann[40],
  real_T loctmp_c_ann, real_T loctmp_w_ann[280], real_T loctmp_lambda_ann,
  real_T *loctmp_c_ann_out, real_T *loctmp_lambda_ann_out, real_T
  *loctmp_V_ann_out)
{
  real_T loctmp_y_est[7];
  real_T loctmp_e_ann[7];
  real_T loctmp_theta_pert[361];
  real_T loctmp_a_pert[40];
  real_T loctmp_b_pert[40];
  real_T loctmp_w_pert[280];
  int32_T loctmp_k;
  int32_T loctmp_i;
  int32_T loctmp_c_k;
  int32_T loctmp_i_0;
  real_T loctmp_theta_ann_it[361];
  int32_T loctmp_i_1;
  real_T loctmp_tmp;
  real_T loctmp_w_pert_0[40];

  /* %allocation */
  for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
    loctmp_e_ann[loctmp_i_0] = 0.0;
  }

  memset(&ANN_EKF_NMPC_2_B.theta_ann_it[0], 0, 722U * sizeof(real_T));

  /* %definitions */
  /* theta vector construction */
  for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
    loctmp_b_pert[loctmp_c_k] = loctmp_a_ann[loctmp_c_k];
  }

  for (loctmp_c_k = 0; loctmp_c_k < 280; loctmp_c_k++) {
    loctmp_w_pert[loctmp_c_k] = loctmp_w_ann[loctmp_c_k];
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it[0], &loctmp_b_pert[0], 40U * sizeof
         (real_T));
  for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
    ANN_EKF_NMPC_2_B.theta_ann_it[loctmp_i_0 + 40] = loctmp_b_ann[loctmp_i_0];
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it[80], &loctmp_w_pert[0], 280U * sizeof
         (real_T));
  ANN_EKF_NMPC_2_B.theta_ann_it[360] = loctmp_c_ann;

  /* cost function calculation */
  /* %perturbation step for numerical calculations */
  for (loctmp_k = 0; loctmp_k < 7; loctmp_k++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp = 0.0;
      for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
        loctmp_tmp += loctmp_w_ann[40 * loctmp_i_1 + loctmp_i_0] * loctmp_x_ann
          [7 * loctmp_k + loctmp_i_1];
      }

      loctmp_b_pert[loctmp_i_0] = loctmp_tmp + loctmp_b_ann[loctmp_i_0];
    }

    loctmp_tmp = 0.0;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp += loctmp_a_ann[loctmp_i_0] * loctmp_b_pert[loctmp_i_0];
    }

    loctmp_y_est[loctmp_k] = loctmp_tmp + loctmp_c_ann;

    /* %*tansig(w_... */
    loctmp_e_ann[loctmp_k] = loctmp_y_ann[loctmp_k] - loctmp_y_est[loctmp_k];

    /* %[1,ann_window_samples] */
    for (loctmp_i = 0; loctmp_i < 361; loctmp_i++) {
      memcpy(&loctmp_theta_pert[0], &ANN_EKF_NMPC_2_B.theta_ann_it[0], 361U *
             sizeof(real_T));
      loctmp_theta_pert[loctmp_i] = ANN_EKF_NMPC_2_B.theta_ann_it[loctmp_i] +
        1.0E-6;
      for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
        loctmp_a_pert[loctmp_c_k] = loctmp_theta_pert[loctmp_c_k];
        loctmp_b_pert[loctmp_c_k] = loctmp_theta_pert[40 + loctmp_c_k];
      }

      memcpy(&loctmp_w_pert[0], &loctmp_theta_pert[80], 280U * sizeof(real_T));
      for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
        loctmp_tmp = 0.0;
        for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
          loctmp_tmp += loctmp_w_pert[40 * loctmp_i_1 + loctmp_i_0] *
            loctmp_x_ann[7 * loctmp_k + loctmp_i_1];
        }

        loctmp_w_pert_0[loctmp_i_0] = loctmp_tmp + loctmp_b_pert[loctmp_i_0];
      }

      loctmp_tmp = 0.0;
      for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
        loctmp_tmp += loctmp_a_pert[loctmp_i_0] * loctmp_w_pert_0[loctmp_i_0];
      }

      ANN_EKF_NMPC_2_B.y_est_pert[loctmp_i + 361 * loctmp_k] = loctmp_tmp +
        loctmp_theta_pert[360];

      /* %*tansig(w_... */
      ANN_EKF_NMPC_2_B.e_pert[loctmp_i + 361 * loctmp_k] = loctmp_y_ann[loctmp_k]
        - ANN_EKF_NMPC_2_B.y_est_pert[361 * loctmp_k + loctmp_i];

      /* [m_ann,ann_window_samples] */
      ANN_EKF_NMPC_2_B.J_ann_b[loctmp_i + 361 * loctmp_k] =
        (ANN_EKF_NMPC_2_B.e_pert[361 * loctmp_k + loctmp_i] -
         loctmp_e_ann[loctmp_k]) / 1.0E-6;

      /* [m_ann,ann_window_sample] */
    }
  }

  /* [1,m_ann] */
  /* [m_ann,m_ann] */
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    loctmp_theta_pert[loctmp_i_0] = 0.0;
    for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
      loctmp_theta_pert[loctmp_i_0] += ANN_EKF_NMPC_2_B.J_ann_b[361 * loctmp_i_1
        + loctmp_i_0] * loctmp_e_ann[loctmp_i_1];
    }
  }

  ANN_EKF_NMPC_2_eye(ANN_EKF_NMPC_2_B.dv0);
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    for (loctmp_i_1 = 0; loctmp_i_1 < 361; loctmp_i_1++) {
      loctmp_tmp = 0.0;
      for (loctmp_c_k = 0; loctmp_c_k < 7; loctmp_c_k++) {
        loctmp_tmp += ANN_EKF_NMPC_2_B.J_ann_b[361 * loctmp_c_k + loctmp_i_0] *
          ANN_EKF_NMPC_2_B.J_ann_b[361 * loctmp_c_k + loctmp_i_1];
      }

      ANN_EKF_NMPC_2_B.J_ann[loctmp_i_0 + 361 * loctmp_i_1] =
        ANN_EKF_NMPC_2_B.dv0[361 * loctmp_i_1 + loctmp_i_0] * loctmp_lambda_ann
        + loctmp_tmp;
    }
  }

  ANN_EKF_NMPC_2_mldivide(ANN_EKF_NMPC_2_B.J_ann, loctmp_theta_pert);
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    loctmp_theta_ann_it[loctmp_i_0] = ANN_EKF_NMPC_2_B.theta_ann_it[loctmp_i_0]
      - loctmp_theta_pert[loctmp_i_0] * 0.1;
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it[361], &loctmp_theta_ann_it[0], 361U *
         sizeof(real_T));

  /* 0.1 faster / 0.01 slower */
  /* %cost function calculation and acceleration estimation */
  for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
    loctmp_a_ann[loctmp_c_k] = ANN_EKF_NMPC_2_B.theta_ann_it[361 + loctmp_c_k];
    loctmp_b_ann[loctmp_c_k] = ANN_EKF_NMPC_2_B.theta_ann_it[loctmp_c_k + 401];
  }

  memcpy(&loctmp_w_ann[0], &ANN_EKF_NMPC_2_B.theta_ann_it[441], 280U * sizeof
         (real_T));
  for (loctmp_c_k = 0; loctmp_c_k < 7; loctmp_c_k++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp = 0.0;
      for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
        loctmp_tmp += loctmp_w_ann[40 * loctmp_i_1 + loctmp_i_0] * loctmp_x_ann
          [7 * loctmp_c_k + loctmp_i_1];
      }

      loctmp_b_pert[loctmp_i_0] = loctmp_tmp + loctmp_b_ann[loctmp_i_0];
    }

    loctmp_tmp = 0.0;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp += loctmp_a_ann[loctmp_i_0] * loctmp_b_pert[loctmp_i_0];
    }

    loctmp_e_ann[loctmp_c_k] = loctmp_tmp + ANN_EKF_NMPC_2_B.theta_ann_it[721];

    /* %*tansig(w_... */
    loctmp_y_est[loctmp_c_k] = loctmp_y_ann[loctmp_c_k] -
      loctmp_e_ann[loctmp_c_k];
  }

  /* cost function calculation */
  /* this is transitory */
  /*      %%Lambda update and theta update */
  /*      if V_ann_it(1,it+1)>=V_ann_it(1,it) */
  /*           */
  /*          theta_ann_it(:,it+1)=theta_ann_it(:,it); */
  /*          a_ann=reshape(theta_ann_it(1:p_ann*N_ann,it+1),p_ann,N_ann); */
  /*          b_ann=reshape(theta_ann_it(p_ann*N_ann+1:(p_ann+1)*N_ann,it+1),N_ann,1); */
  /*          w_ann=reshape(theta_ann_it((p_ann+1)*N_ann+1:(p_ann+1)*N_ann+N_ann*n_ann,it+1),N_ann,n_ann); */
  /*          c_ann=reshape(theta_ann_it((p_ann+1)*N_ann+N_ann*n_ann+1:m_ann,it+1),p_ann,1); */
  /*           */
  /*          V_ann_it(1,it+1)=V_ann_it(1,it); */
  /*           */
  /*          lambda_ann_it(1,it+1)=lambda_ann_it(1,it)*1;%2;%1.1 */
  /*          %     if lambda_ann(it+1)>100 %1 */
  /*          %         lambda_ann(it+1)=0.001; */
  /*          %     end; */
  /*      elseif V_ann_it(it+1)<V_ann_it(it) */
  /*          lambda_ann_it(1,it+1)=lambda_ann_it(1,it)/1;%3;%1.5 */
  /*          %     if lambda_ann_X(it+1)<0.0000001 %0.00001 */
  /*          %         lambda_ann_X(it+1)=0.001; */
  /*          %     end; */
  /*      end; */
  *loctmp_c_ann_out = ANN_EKF_NMPC_2_B.theta_ann_it[721];
  *loctmp_lambda_ann_out = loctmp_lambda_ann;
  *loctmp_V_ann_out = 0.0;
  for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
    *loctmp_V_ann_out += loctmp_y_est[loctmp_i_0] * loctmp_y_est[loctmp_i_0];
  }
}

/* Function for MATLAB Function: '<S1>/ann' */
static void ANN_EKF_NMPC_2_ann_iteration_f(const real_T loctmp_x_ann[49], const
  real_T loctmp_y_ann[7], real_T loctmp_a_ann[40], real_T loctmp_b_ann[40],
  real_T loctmp_c_ann, real_T loctmp_w_ann[280], real_T loctmp_lambda_ann,
  real_T *loctmp_c_ann_out, real_T *loctmp_lambda_ann_out, real_T
  *loctmp_V_ann_out)
{
  real_T loctmp_y_est[7];
  real_T loctmp_e_ann[7];
  real_T loctmp_theta_pert[361];
  real_T loctmp_a_pert[40];
  real_T loctmp_b_pert[40];
  real_T loctmp_w_pert[280];
  int32_T loctmp_k;
  int32_T loctmp_i;
  int32_T loctmp_c_k;
  int32_T loctmp_i_0;
  real_T loctmp_theta_ann_it[361];
  int32_T loctmp_i_1;
  real_T loctmp_tmp;
  real_T loctmp_w_pert_0[40];

  /* %allocation */
  for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
    loctmp_e_ann[loctmp_i_0] = 0.0;
  }

  memset(&ANN_EKF_NMPC_2_B.theta_ann_it_n[0], 0, 722U * sizeof(real_T));

  /* %definitions */
  /* theta vector construction */
  for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
    loctmp_b_pert[loctmp_c_k] = loctmp_a_ann[loctmp_c_k];
  }

  for (loctmp_c_k = 0; loctmp_c_k < 280; loctmp_c_k++) {
    loctmp_w_pert[loctmp_c_k] = loctmp_w_ann[loctmp_c_k];
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it_n[0], &loctmp_b_pert[0], 40U * sizeof
         (real_T));
  for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
    ANN_EKF_NMPC_2_B.theta_ann_it_n[loctmp_i_0 + 40] = loctmp_b_ann[loctmp_i_0];
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it_n[80], &loctmp_w_pert[0], 280U * sizeof
         (real_T));
  ANN_EKF_NMPC_2_B.theta_ann_it_n[360] = loctmp_c_ann;

  /* cost function calculation */
  /* %perturbation step for numerical calculations */
  for (loctmp_k = 0; loctmp_k < 7; loctmp_k++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp = 0.0;
      for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
        loctmp_tmp += loctmp_w_ann[40 * loctmp_i_1 + loctmp_i_0] * loctmp_x_ann
          [7 * loctmp_k + loctmp_i_1];
      }

      loctmp_b_pert[loctmp_i_0] = loctmp_tmp + loctmp_b_ann[loctmp_i_0];
    }

    loctmp_tmp = 0.0;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp += loctmp_a_ann[loctmp_i_0] * loctmp_b_pert[loctmp_i_0];
    }

    loctmp_y_est[loctmp_k] = loctmp_tmp + loctmp_c_ann;

    /* %*tansig(w_... */
    loctmp_e_ann[loctmp_k] = loctmp_y_ann[loctmp_k] - loctmp_y_est[loctmp_k];

    /* %[1,ann_window_samples] */
    for (loctmp_i = 0; loctmp_i < 361; loctmp_i++) {
      memcpy(&loctmp_theta_pert[0], &ANN_EKF_NMPC_2_B.theta_ann_it_n[0], 361U *
             sizeof(real_T));
      loctmp_theta_pert[loctmp_i] = ANN_EKF_NMPC_2_B.theta_ann_it_n[loctmp_i] +
        1.0E-6;
      for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
        loctmp_a_pert[loctmp_c_k] = loctmp_theta_pert[loctmp_c_k];
        loctmp_b_pert[loctmp_c_k] = loctmp_theta_pert[40 + loctmp_c_k];
      }

      memcpy(&loctmp_w_pert[0], &loctmp_theta_pert[80], 280U * sizeof(real_T));
      for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
        loctmp_tmp = 0.0;
        for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
          loctmp_tmp += loctmp_w_pert[40 * loctmp_i_1 + loctmp_i_0] *
            loctmp_x_ann[7 * loctmp_k + loctmp_i_1];
        }

        loctmp_w_pert_0[loctmp_i_0] = loctmp_tmp + loctmp_b_pert[loctmp_i_0];
      }

      loctmp_tmp = 0.0;
      for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
        loctmp_tmp += loctmp_a_pert[loctmp_i_0] * loctmp_w_pert_0[loctmp_i_0];
      }

      ANN_EKF_NMPC_2_B.y_est_pert_p[loctmp_i + 361 * loctmp_k] = loctmp_tmp +
        loctmp_theta_pert[360];

      /* %*tansig(w_... */
      ANN_EKF_NMPC_2_B.e_pert_c[loctmp_i + 361 * loctmp_k] =
        loctmp_y_ann[loctmp_k] - ANN_EKF_NMPC_2_B.y_est_pert_p[361 * loctmp_k +
        loctmp_i];

      /* [m_ann,ann_window_samples] */
      ANN_EKF_NMPC_2_B.J_ann_f[loctmp_i + 361 * loctmp_k] =
        (ANN_EKF_NMPC_2_B.e_pert_c[361 * loctmp_k + loctmp_i] -
         loctmp_e_ann[loctmp_k]) / 1.0E-6;

      /* [m_ann,ann_window_sample] */
    }
  }

  /* [1,m_ann] */
  /* [m_ann,m_ann] */
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    loctmp_theta_pert[loctmp_i_0] = 0.0;
    for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
      loctmp_theta_pert[loctmp_i_0] += ANN_EKF_NMPC_2_B.J_ann_f[361 * loctmp_i_1
        + loctmp_i_0] * loctmp_e_ann[loctmp_i_1];
    }
  }

  ANN_EKF_NMPC_2_eye(ANN_EKF_NMPC_2_B.dv1);
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    for (loctmp_i_1 = 0; loctmp_i_1 < 361; loctmp_i_1++) {
      loctmp_tmp = 0.0;
      for (loctmp_c_k = 0; loctmp_c_k < 7; loctmp_c_k++) {
        loctmp_tmp += ANN_EKF_NMPC_2_B.J_ann_f[361 * loctmp_c_k + loctmp_i_0] *
          ANN_EKF_NMPC_2_B.J_ann_f[361 * loctmp_c_k + loctmp_i_1];
      }

      ANN_EKF_NMPC_2_B.J_ann_m[loctmp_i_0 + 361 * loctmp_i_1] =
        ANN_EKF_NMPC_2_B.dv1[361 * loctmp_i_1 + loctmp_i_0] * loctmp_lambda_ann
        + loctmp_tmp;
    }
  }

  ANN_EKF_NMPC_2_mldivide(ANN_EKF_NMPC_2_B.J_ann_m, loctmp_theta_pert);
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    loctmp_theta_ann_it[loctmp_i_0] = ANN_EKF_NMPC_2_B.theta_ann_it_n[loctmp_i_0]
      - loctmp_theta_pert[loctmp_i_0] * 0.1;
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it_n[361], &loctmp_theta_ann_it[0], 361U *
         sizeof(real_T));

  /* 0.1 faster / 0.01 slower */
  /* %cost function calculation and acceleration estimation */
  for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
    loctmp_a_ann[loctmp_c_k] = ANN_EKF_NMPC_2_B.theta_ann_it_n[361 + loctmp_c_k];
    loctmp_b_ann[loctmp_c_k] = ANN_EKF_NMPC_2_B.theta_ann_it_n[loctmp_c_k + 401];
  }

  memcpy(&loctmp_w_ann[0], &ANN_EKF_NMPC_2_B.theta_ann_it_n[441], 280U * sizeof
         (real_T));
  for (loctmp_c_k = 0; loctmp_c_k < 7; loctmp_c_k++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp = 0.0;
      for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
        loctmp_tmp += loctmp_w_ann[40 * loctmp_i_1 + loctmp_i_0] * loctmp_x_ann
          [7 * loctmp_c_k + loctmp_i_1];
      }

      loctmp_b_pert[loctmp_i_0] = loctmp_tmp + loctmp_b_ann[loctmp_i_0];
    }

    loctmp_tmp = 0.0;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp += loctmp_a_ann[loctmp_i_0] * loctmp_b_pert[loctmp_i_0];
    }

    loctmp_e_ann[loctmp_c_k] = loctmp_tmp + ANN_EKF_NMPC_2_B.theta_ann_it_n[721];

    /* %*tansig(w_... */
    loctmp_y_est[loctmp_c_k] = loctmp_y_ann[loctmp_c_k] -
      loctmp_e_ann[loctmp_c_k];
  }

  /* cost function calculation */
  /* this is transitory */
  /*      %%Lambda update and theta update */
  /*      if V_ann_it(1,it+1)>=V_ann_it(1,it) */
  /*           */
  /*          theta_ann_it(:,it+1)=theta_ann_it(:,it); */
  /*          a_ann=reshape(theta_ann_it(1:p_ann*N_ann,it+1),p_ann,N_ann); */
  /*          b_ann=reshape(theta_ann_it(p_ann*N_ann+1:(p_ann+1)*N_ann,it+1),N_ann,1); */
  /*          w_ann=reshape(theta_ann_it((p_ann+1)*N_ann+1:(p_ann+1)*N_ann+N_ann*n_ann,it+1),N_ann,n_ann); */
  /*          c_ann=reshape(theta_ann_it((p_ann+1)*N_ann+N_ann*n_ann+1:m_ann,it+1),p_ann,1); */
  /*           */
  /*          V_ann_it(1,it+1)=V_ann_it(1,it); */
  /*           */
  /*          lambda_ann_it(1,it+1)=lambda_ann_it(1,it)*1;%2;%1.1 */
  /*          %     if lambda_ann(it+1)>100 %1 */
  /*          %         lambda_ann(it+1)=0.001; */
  /*          %     end; */
  /*      elseif V_ann_it(it+1)<V_ann_it(it) */
  /*          lambda_ann_it(1,it+1)=lambda_ann_it(1,it)/1;%3;%1.5 */
  /*          %     if lambda_ann_X(it+1)<0.0000001 %0.00001 */
  /*          %         lambda_ann_X(it+1)=0.001; */
  /*          %     end; */
  /*      end; */
  *loctmp_c_ann_out = ANN_EKF_NMPC_2_B.theta_ann_it_n[721];
  *loctmp_lambda_ann_out = loctmp_lambda_ann;
  *loctmp_V_ann_out = 0.0;
  for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
    *loctmp_V_ann_out += loctmp_y_est[loctmp_i_0] * loctmp_y_est[loctmp_i_0];
  }
}

/* Function for MATLAB Function: '<S1>/ann' */
static void ANN_EKF_NMPC_2_ann_iteration_fj(const real_T loctmp_x_ann[49], const
  real_T loctmp_y_ann[7], real_T loctmp_a_ann[40], real_T loctmp_b_ann[40],
  real_T loctmp_c_ann, real_T loctmp_w_ann[280], real_T loctmp_lambda_ann,
  real_T *loctmp_c_ann_out, real_T *loctmp_lambda_ann_out, real_T
  *loctmp_V_ann_out)
{
  real_T loctmp_y_est[7];
  real_T loctmp_e_ann[7];
  real_T loctmp_theta_pert[361];
  real_T loctmp_a_pert[40];
  real_T loctmp_b_pert[40];
  real_T loctmp_w_pert[280];
  int32_T loctmp_k;
  int32_T loctmp_i;
  int32_T loctmp_c_k;
  int32_T loctmp_i_0;
  real_T loctmp_theta_ann_it[361];
  int32_T loctmp_i_1;
  real_T loctmp_tmp;
  real_T loctmp_w_pert_0[40];

  /* %allocation */
  for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
    loctmp_e_ann[loctmp_i_0] = 0.0;
  }

  memset(&ANN_EKF_NMPC_2_B.theta_ann_it_p[0], 0, 722U * sizeof(real_T));

  /* %definitions */
  /* theta vector construction */
  for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
    loctmp_b_pert[loctmp_c_k] = loctmp_a_ann[loctmp_c_k];
  }

  for (loctmp_c_k = 0; loctmp_c_k < 280; loctmp_c_k++) {
    loctmp_w_pert[loctmp_c_k] = loctmp_w_ann[loctmp_c_k];
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it_p[0], &loctmp_b_pert[0], 40U * sizeof
         (real_T));
  for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
    ANN_EKF_NMPC_2_B.theta_ann_it_p[loctmp_i_0 + 40] = loctmp_b_ann[loctmp_i_0];
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it_p[80], &loctmp_w_pert[0], 280U * sizeof
         (real_T));
  ANN_EKF_NMPC_2_B.theta_ann_it_p[360] = loctmp_c_ann;

  /* cost function calculation */
  /* %perturbation step for numerical calculations */
  for (loctmp_k = 0; loctmp_k < 7; loctmp_k++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp = 0.0;
      for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
        loctmp_tmp += loctmp_w_ann[40 * loctmp_i_1 + loctmp_i_0] * loctmp_x_ann
          [7 * loctmp_k + loctmp_i_1];
      }

      loctmp_b_pert[loctmp_i_0] = loctmp_tmp + loctmp_b_ann[loctmp_i_0];
    }

    loctmp_tmp = 0.0;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp += loctmp_a_ann[loctmp_i_0] * loctmp_b_pert[loctmp_i_0];
    }

    loctmp_y_est[loctmp_k] = loctmp_tmp + loctmp_c_ann;

    /* %*tansig(w_... */
    loctmp_e_ann[loctmp_k] = loctmp_y_ann[loctmp_k] - loctmp_y_est[loctmp_k];

    /* %[1,ann_window_samples] */
    for (loctmp_i = 0; loctmp_i < 361; loctmp_i++) {
      memcpy(&loctmp_theta_pert[0], &ANN_EKF_NMPC_2_B.theta_ann_it_p[0], 361U *
             sizeof(real_T));
      loctmp_theta_pert[loctmp_i] = ANN_EKF_NMPC_2_B.theta_ann_it_p[loctmp_i] +
        1.0E-6;
      for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
        loctmp_a_pert[loctmp_c_k] = loctmp_theta_pert[loctmp_c_k];
        loctmp_b_pert[loctmp_c_k] = loctmp_theta_pert[40 + loctmp_c_k];
      }

      memcpy(&loctmp_w_pert[0], &loctmp_theta_pert[80], 280U * sizeof(real_T));
      for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
        loctmp_tmp = 0.0;
        for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
          loctmp_tmp += loctmp_w_pert[40 * loctmp_i_1 + loctmp_i_0] *
            loctmp_x_ann[7 * loctmp_k + loctmp_i_1];
        }

        loctmp_w_pert_0[loctmp_i_0] = loctmp_tmp + loctmp_b_pert[loctmp_i_0];
      }

      loctmp_tmp = 0.0;
      for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
        loctmp_tmp += loctmp_a_pert[loctmp_i_0] * loctmp_w_pert_0[loctmp_i_0];
      }

      ANN_EKF_NMPC_2_B.y_est_pert_g[loctmp_i + 361 * loctmp_k] = loctmp_tmp +
        loctmp_theta_pert[360];

      /* %*tansig(w_... */
      ANN_EKF_NMPC_2_B.e_pert_g[loctmp_i + 361 * loctmp_k] =
        loctmp_y_ann[loctmp_k] - ANN_EKF_NMPC_2_B.y_est_pert_g[361 * loctmp_k +
        loctmp_i];

      /* [m_ann,ann_window_samples] */
      ANN_EKF_NMPC_2_B.J_ann_me[loctmp_i + 361 * loctmp_k] =
        (ANN_EKF_NMPC_2_B.e_pert_g[361 * loctmp_k + loctmp_i] -
         loctmp_e_ann[loctmp_k]) / 1.0E-6;

      /* [m_ann,ann_window_sample] */
    }
  }

  /* [1,m_ann] */
  /* [m_ann,m_ann] */
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    loctmp_theta_pert[loctmp_i_0] = 0.0;
    for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
      loctmp_theta_pert[loctmp_i_0] += ANN_EKF_NMPC_2_B.J_ann_me[361 *
        loctmp_i_1 + loctmp_i_0] * loctmp_e_ann[loctmp_i_1];
    }
  }

  ANN_EKF_NMPC_2_eye(ANN_EKF_NMPC_2_B.dv2);
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    for (loctmp_i_1 = 0; loctmp_i_1 < 361; loctmp_i_1++) {
      loctmp_tmp = 0.0;
      for (loctmp_c_k = 0; loctmp_c_k < 7; loctmp_c_k++) {
        loctmp_tmp += ANN_EKF_NMPC_2_B.J_ann_me[361 * loctmp_c_k + loctmp_i_0] *
          ANN_EKF_NMPC_2_B.J_ann_me[361 * loctmp_c_k + loctmp_i_1];
      }

      ANN_EKF_NMPC_2_B.J_ann_c[loctmp_i_0 + 361 * loctmp_i_1] =
        ANN_EKF_NMPC_2_B.dv2[361 * loctmp_i_1 + loctmp_i_0] * loctmp_lambda_ann
        + loctmp_tmp;
    }
  }

  ANN_EKF_NMPC_2_mldivide(ANN_EKF_NMPC_2_B.J_ann_c, loctmp_theta_pert);
  for (loctmp_i_0 = 0; loctmp_i_0 < 361; loctmp_i_0++) {
    loctmp_theta_ann_it[loctmp_i_0] = ANN_EKF_NMPC_2_B.theta_ann_it_p[loctmp_i_0]
      - loctmp_theta_pert[loctmp_i_0] * 0.1;
  }

  memcpy(&ANN_EKF_NMPC_2_B.theta_ann_it_p[361], &loctmp_theta_ann_it[0], 361U *
         sizeof(real_T));

  /* 0.1 faster / 0.01 slower */
  /* %cost function calculation and acceleration estimation */
  for (loctmp_c_k = 0; loctmp_c_k < 40; loctmp_c_k++) {
    loctmp_a_ann[loctmp_c_k] = ANN_EKF_NMPC_2_B.theta_ann_it_p[361 + loctmp_c_k];
    loctmp_b_ann[loctmp_c_k] = ANN_EKF_NMPC_2_B.theta_ann_it_p[loctmp_c_k + 401];
  }

  memcpy(&loctmp_w_ann[0], &ANN_EKF_NMPC_2_B.theta_ann_it_p[441], 280U * sizeof
         (real_T));
  for (loctmp_c_k = 0; loctmp_c_k < 7; loctmp_c_k++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp = 0.0;
      for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
        loctmp_tmp += loctmp_w_ann[40 * loctmp_i_1 + loctmp_i_0] * loctmp_x_ann
          [7 * loctmp_c_k + loctmp_i_1];
      }

      loctmp_b_pert[loctmp_i_0] = loctmp_tmp + loctmp_b_ann[loctmp_i_0];
    }

    loctmp_tmp = 0.0;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      loctmp_tmp += loctmp_a_ann[loctmp_i_0] * loctmp_b_pert[loctmp_i_0];
    }

    loctmp_e_ann[loctmp_c_k] = loctmp_tmp + ANN_EKF_NMPC_2_B.theta_ann_it_p[721];

    /* %*tansig(w_... */
    loctmp_y_est[loctmp_c_k] = loctmp_y_ann[loctmp_c_k] -
      loctmp_e_ann[loctmp_c_k];
  }

  /* cost function calculation */
  /* this is transitory */
  /*      %%Lambda update and theta update */
  /*      if V_ann_it(1,it+1)>=V_ann_it(1,it) */
  /*           */
  /*          theta_ann_it(:,it+1)=theta_ann_it(:,it); */
  /*          a_ann=reshape(theta_ann_it(1:p_ann*N_ann,it+1),p_ann,N_ann); */
  /*          b_ann=reshape(theta_ann_it(p_ann*N_ann+1:(p_ann+1)*N_ann,it+1),N_ann,1); */
  /*          w_ann=reshape(theta_ann_it((p_ann+1)*N_ann+1:(p_ann+1)*N_ann+N_ann*n_ann,it+1),N_ann,n_ann); */
  /*          c_ann=reshape(theta_ann_it((p_ann+1)*N_ann+N_ann*n_ann+1:m_ann,it+1),p_ann,1); */
  /*           */
  /*          V_ann_it(1,it+1)=V_ann_it(1,it); */
  /*           */
  /*          lambda_ann_it(1,it+1)=lambda_ann_it(1,it)*1;%2;%1.1 */
  /*          %     if lambda_ann(it+1)>100 %1 */
  /*          %         lambda_ann(it+1)=0.001; */
  /*          %     end; */
  /*      elseif V_ann_it(it+1)<V_ann_it(it) */
  /*          lambda_ann_it(1,it+1)=lambda_ann_it(1,it)/1;%3;%1.5 */
  /*          %     if lambda_ann_X(it+1)<0.0000001 %0.00001 */
  /*          %         lambda_ann_X(it+1)=0.001; */
  /*          %     end; */
  /*      end; */
  *loctmp_c_ann_out = ANN_EKF_NMPC_2_B.theta_ann_it_p[721];
  *loctmp_lambda_ann_out = loctmp_lambda_ann;
  *loctmp_V_ann_out = 0.0;
  for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
    *loctmp_V_ann_out += loctmp_y_est[loctmp_i_0] * loctmp_y_est[loctmp_i_0];
  }
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_ann_norm_X(const real_T loctmp_x_ann_un[7], const
  real_T loctmp_minXin[7], const real_T loctmp_maxXin[7], real_T loctmp_minYin,
  real_T loctmp_maxYin, real_T loctmp_x_ann[7])
{
  int32_T loctmp_i;

  /* %%x_ann_un dimension is [number of inputs,ann_samples] */
  /* %number of samples */
  /* %allocation */
  for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
    loctmp_x_ann[loctmp_i] = (loctmp_x_ann_un[loctmp_i] - loctmp_minXin[loctmp_i])
      * (loctmp_maxYin - loctmp_minYin) / (loctmp_maxXin[loctmp_i] -
      loctmp_minXin[loctmp_i]) + loctmp_minYin;
  }
}

/* Function for MATLAB Function: '<S2>/Control System' */
static real_T ANN_EKF_NMPC_2_ann_denorm_Y(real_T loctmp_y_ann, real_T
  loctmp_minXout, real_T loctmp_maxXout, real_T loctmp_minYout, real_T
  loctmp_maxYout)
{
  /* %%y_ann_un dimension is [ann_samples,number of inputs] */
  /* %number of samples */
  /* %allocation */
  return (loctmp_y_ann - loctmp_minYout) * (loctmp_maxXout - loctmp_minXout) /
    (loctmp_maxYout - loctmp_minYout) + loctmp_minXout;
}

/* Function for MATLAB Function: '<S2>/Control System' */
static real_T ANN_EKF_NMPC_2_norm(const real_T loctmp_x[2])
{
  real_T loctmp_y;
  real_T loctmp_scale;
  real_T loctmp_absxk;
  real_T loctmp_t;
  loctmp_scale = 2.2250738585072014E-308;
  loctmp_absxk = fabs(loctmp_x[0]);
  if (loctmp_absxk > 2.2250738585072014E-308) {
    loctmp_y = 1.0;
    loctmp_scale = loctmp_absxk;
  } else {
    loctmp_t = loctmp_absxk / 2.2250738585072014E-308;
    loctmp_y = loctmp_t * loctmp_t;
  }

  loctmp_absxk = fabs(loctmp_x[1]);
  if (loctmp_absxk > loctmp_scale) {
    loctmp_t = loctmp_scale / loctmp_absxk;
    loctmp_y = loctmp_y * loctmp_t * loctmp_t + 1.0;
    loctmp_scale = loctmp_absxk;
  } else {
    loctmp_t = loctmp_absxk / loctmp_scale;
    loctmp_y += loctmp_t * loctmp_t;
  }

  return loctmp_scale * sqrt(loctmp_y);
}

real_T rt_atan2d_snf(real_T loctmp_u0, real_T loctmp_u1)
{
  real_T loctmp_y;
  int32_T loctmp_u0_0;
  int32_T loctmp_u1_0;
  if (rtIsNaN(loctmp_u0) || rtIsNaN(loctmp_u1)) {
    loctmp_y = (rtNaN);
  } else if (rtIsInf(loctmp_u0) && rtIsInf(loctmp_u1)) {
    if (loctmp_u0 > 0.0) {
      loctmp_u0_0 = 1;
    } else {
      loctmp_u0_0 = -1;
    }

    if (loctmp_u1 > 0.0) {
      loctmp_u1_0 = 1;
    } else {
      loctmp_u1_0 = -1;
    }

    loctmp_y = atan2(loctmp_u0_0, loctmp_u1_0);
  } else if (loctmp_u1 == 0.0) {
    if (loctmp_u0 > 0.0) {
      loctmp_y = RT_PI / 2.0;
    } else if (loctmp_u0 < 0.0) {
      loctmp_y = -(RT_PI / 2.0);
    } else {
      loctmp_y = 0.0;
    }
  } else {
    loctmp_y = atan2(loctmp_u0, loctmp_u1);
  }

  return loctmp_y;
}

/* Function for MATLAB Function: '<S2>/Control System' */
static real_T ANN_EKF_NMPC_2_norm_h(const real_T loctmp_x[3])
{
  real_T loctmp_y;
  real_T loctmp_scale;
  real_T loctmp_absxk;
  real_T loctmp_t;
  loctmp_scale = 2.2250738585072014E-308;
  loctmp_absxk = fabs(loctmp_x[0]);
  if (loctmp_absxk > 2.2250738585072014E-308) {
    loctmp_y = 1.0;
    loctmp_scale = loctmp_absxk;
  } else {
    loctmp_t = loctmp_absxk / 2.2250738585072014E-308;
    loctmp_y = loctmp_t * loctmp_t;
  }

  loctmp_absxk = fabs(loctmp_x[1]);
  if (loctmp_absxk > loctmp_scale) {
    loctmp_t = loctmp_scale / loctmp_absxk;
    loctmp_y = loctmp_y * loctmp_t * loctmp_t + 1.0;
    loctmp_scale = loctmp_absxk;
  } else {
    loctmp_t = loctmp_absxk / loctmp_scale;
    loctmp_y += loctmp_t * loctmp_t;
  }

  loctmp_absxk = fabs(loctmp_x[2]);
  if (loctmp_absxk > loctmp_scale) {
    loctmp_t = loctmp_scale / loctmp_absxk;
    loctmp_y = loctmp_y * loctmp_t * loctmp_t + 1.0;
    loctmp_scale = loctmp_absxk;
  } else {
    loctmp_t = loctmp_absxk / loctmp_scale;
    loctmp_y += loctmp_t * loctmp_t;
  }

  return loctmp_scale * sqrt(loctmp_y);
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_uas_augm_model(real_T loctmp_sw, boolean_T
  loctmp_home_cmd, real_T loctmp_b_dt, real_T loctmp_b_TR, uint8_T
  loctmp_wpts_fp, uint8_T loctmp_wpts_rp, real_T loctmp_wpts_h[32], real_T
  loctmp_wpts_n[32], real_T loctmp_wpts_e[32], const real_T loctmp_wpts_v[32],
  real_T loctmp_n_op_k, real_T loctmp_e_op_k, real_T loctmp_h_op_k, real_T
  loctmp_vn_op_k, real_T loctmp_ve_op_k, real_T loctmp_vh_op_k, real_T
  loctmp_alphadot_k, real_T loctmp_betadot_k, uint8_T loctmp_wpt_index_k, real_T
  loctmp_start_wpt_k[3], boolean_T loctmp_pic_cic_k, uint8_T loctmp_home_reset_k,
  real_T loctmp_THL_k, real_T loctmp_EL_k, real_T loctmp_AIL_k, real_T
  loctmp_RDR_k, real_T loctmp_VT_k, real_T loctmp_alpha_k, real_T loctmp_beta_k,
  real_T loctmp_phi_k, real_T loctmp_theta_k, real_T loctmp_psi_k, real_T
  loctmp_P_k, real_T loctmp_Q_k, real_T loctmp_R_k, real_T loctmp_n_k, real_T
  loctmp_e_k, real_T loctmp_h_k, real_T loctmp_ro_k, real_T loctmp_THLcmd_k,
  real_T loctmp_ELcmd_k, real_T loctmp_AILcmd_k, real_T loctmp_RDRcmd_k, real_T
  loctmp_xw11_k, real_T loctmp_xw12_k, real_T loctmp_xw13_k, real_T
  loctmp_xw14_k, real_T loctmp_xw21_k, real_T loctmp_xw22_k, real_T
  loctmp_xw23_k, real_T loctmp_xw24_k, real_T loctmp_xw31_k, real_T
  loctmp_xw32_k, real_T loctmp_xw33_k, real_T loctmp_xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W12d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W21d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W24d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W33d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W34d, real_T loctmp_b_rho, real_T
  loctmp_b_S, real_T loctmp_b_Cbar, real_T loctmp_b_b, real_T loctmp_b_weight,
  real_T loctmp_b_g, real_T loctmp_b_IxxB, real_T loctmp_b_IyyB, real_T
  loctmp_b_IzzB, real_T loctmp_b_IxzB, real_T loctmp_b_CDu, real_T loctmp_b_CDq,
  real_T loctmp_b_CDadot, real_T loctmp_b_CDde, real_T loctmp_b_CD0_bar, real_T
  loctmp_b_Cyb, real_T loctmp_b_Cyp, real_T loctmp_b_Cyr, real_T loctmp_b_Cyda,
  real_T loctmp_b_Cydr, real_T loctmp_b_CL0, real_T loctmp_b_CLa, real_T
  loctmp_b_CLq, real_T loctmp_b_CLadot, real_T loctmp_b_CLu, real_T
  loctmp_b_CLde, real_T loctmp_b_Clb, real_T loctmp_b_Clp, real_T loctmp_b_Clr,
  real_T loctmp_b_Clda, real_T loctmp_b_Cldr, real_T loctmp_b_Cm0, real_T
  loctmp_b_Cma, real_T loctmp_b_Cmq, real_T loctmp_b_Cmadot, real_T loctmp_b_Cmu,
  real_T loctmp_b_Cmde, real_T loctmp_b_Cnb, real_T loctmp_b_Cnp, real_T
  loctmp_b_Cnr, real_T loctmp_b_Cnda, real_T loctmp_b_Cndr, real_T loctmp_b_xT0,
  real_T loctmp_b_xT1, real_T loctmp_b_xT2, real_T loctmp_b_Ptrim, real_T
  loctmp_b_Qtrim, real_T loctmp_b_Rtrim, real_T loctmp_b_Utrim, real_T
  loctmp_b_Athrottle, real_T loctmp_b_Bthrottle, real_T loctmp_b_Aelevator,
  real_T loctmp_b_Belevator, real_T loctmp_b_Aaileron, real_T loctmp_b_Baileron,
  real_T loctmp_b_Arudder, real_T loctmp_b_Brudder, real_T loctmp_b_ThrottleMax,
  real_T loctmp_b_ThrottleMin, real_T loctmp_b_ElevatorMax, real_T
  loctmp_b_ElevatorMin, real_T loctmp_b_AileronMax, real_T loctmp_b_AileronMin,
  real_T loctmp_b_RudderMax, real_T loctmp_b_RudderMin, real_T loctmp_b_KpLat,
  real_T loctmp_b_KiLon, real_T loctmp_b_KpLon, real_T loctmp_b_L, real_T
  loctmp_b_dist2b, real_T loctmp_FL_ann, const real_T loctmp_a_ann_X[40], const
  real_T loctmp_b_ann_X[40], real_T loctmp_c_ann_X, const real_T loctmp_w_ann_X
  [280], const real_T loctmp_a_ann_Y[40], const real_T loctmp_b_ann_Y[40],
  real_T loctmp_c_ann_Y, const real_T loctmp_w_ann_Y[280], const real_T
  loctmp_a_ann_Z[40], const real_T loctmp_b_ann_Z[40], real_T loctmp_c_ann_Z,
  const real_T loctmp_w_ann_Z[280], const real_T loctmp_b_X_minXin[7], const
  real_T loctmp_b_X_maxXin[7], real_T loctmp_b_X_minYin, real_T
  loctmp_b_X_maxYin, real_T loctmp_b_X_minXout, real_T loctmp_b_X_maxXout,
  real_T loctmp_b_X_minYout, real_T loctmp_b_X_maxYout, const real_T
  loctmp_b_Y_minXin[7], const real_T loctmp_b_Y_maxXin[7], real_T
  loctmp_b_Y_minYin, real_T loctmp_b_Y_maxYin, real_T loctmp_b_Y_minXout, real_T
  loctmp_b_Y_maxXout, real_T loctmp_b_Y_minYout, real_T loctmp_b_Y_maxYout,
  const real_T loctmp_b_Z_minXin[7], const real_T loctmp_b_Z_maxXin[7], real_T
  loctmp_b_Z_minYin, real_T loctmp_b_Z_maxYin, real_T loctmp_b_Z_minXout, real_T
  loctmp_b_Z_maxXout, real_T loctmp_b_Z_minYout, real_T loctmp_b_Z_maxYout,
  real32_T *loctmp_distance2b, uint8_T *loctmp_wpt_index_kk, real_T
  *loctmp_pic_cic_kk, uint8_T *loctmp_home_reset_kk, real_T *loctmp_nr_k, real_T
  *loctmp_er_k, real_T *loctmp_hr_k, real_T *loctmp_etaLon_k, real_T
  *loctmp_etaLat_k, real_T *loctmp_VTcmd_k, real_T *loctmp_thetacmd_k, real_T
  *loctmp_phicmd_k, real_T *loctmp_Vab_k, real_T *loctmp_accelX_scd_k, real_T
  *loctmp_accelX_ann_k, real_T *loctmp_accelY_scd_k, real_T *loctmp_accelY_ann_k,
  real_T *loctmp_accelZ_scd_k, real_T *loctmp_accelZ_ann_k, real_T
  loctmp_z_augm_k[12], real_T loctmp_e_augm_k[4], real_T *loctmp_THL_kk, real_T *
  loctmp_EL_kk, real_T *loctmp_AIL_kk, real_T *loctmp_RDR_kk, real_T
  *loctmp_VT_kk, real_T *loctmp_alpha_kk, real_T *loctmp_beta_kk, real_T
  *loctmp_phi_kk, real_T *loctmp_theta_kk, real_T *loctmp_psi_kk, real_T
  *loctmp_P_kk, real_T *loctmp_Q_kk, real_T *loctmp_R_kk, real_T
  *loctmp_falpha_k, real_T *loctmp_fbeta_k, real_T *loctmp_n_kk, real_T
  *loctmp_e_kk, real_T *loctmp_h_kk, real_T *loctmp_ro_kk, real_T
  *loctmp_xw11_kk, real_T *loctmp_xw12_kk, real_T *loctmp_xw13_kk, real_T
  *loctmp_xw14_kk, real_T *loctmp_xw21_kk, real_T *loctmp_xw22_kk, real_T
  *loctmp_xw23_kk, real_T *loctmp_xw24_kk, real_T *loctmp_xw31_kk, real_T
  *loctmp_xw32_kk, real_T *loctmp_xw33_kk, real_T *loctmp_xw34_kk)
{
  real_T loctmp_mass;
  real_T loctmp_delta_I;
  real_T loctmp_c2;
  real_T loctmp_c4;
  real_T loctmp_Qbar_k;
  real_T loctmp_U_k;
  real_T loctmp_V_k;
  real_T loctmp_W_k;
  real_T loctmp_CL_k;
  real_T loctmp_CD_k;
  real_T loctmp_Cls_k;
  real_T loctmp_Cms_k;
  real_T loctmp_Cns_k;
  real_T loctmp_Cl_k;
  real_T loctmp_Cn_k;
  real_T loctmp_Udot_k;
  real_T loctmp_Vdot_k;
  real_T loctmp_Wdot_k;
  real_T loctmp_fn_k;
  real_T loctmp_fe_k;
  real_T loctmp_fh_k;
  uint8_T loctmp_next_wpt_index;
  real_T loctmp_ea;
  real_T loctmp_hd_k;
  real_T loctmp_nd_k;
  real_T loctmp_ed_k;
  real_T loctmp_atrack;
  int32_T loctmp_factor;
  real_T loctmp_btrack;
  real_T loctmp_edot_track_k;
  real_T loctmp_ndot_track_k;
  real_T loctmp_r_a;
  real_T loctmp_s_a;
  real_T loctmp_t_a;
  real_T loctmp_er_k_0[2];
  real_T loctmp_er_k_1[3];
  real_T loctmp_nr_k_0[2];
  real_T loctmp_fn_k_0[2];
  real_T loctmp_VT_k_0[7];
  real_T loctmp_VT_k_1[7];
  real_T loctmp_VT_k_2[7];
  real_T loctmp_tmp[7];
  real_T loctmp_w_ann_X_0[40];
  int32_T loctmp_i;

  /* %temporary */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %mass and inertia coefficients%% */
  loctmp_mass = loctmp_b_weight / loctmp_b_g;
  loctmp_delta_I = loctmp_b_IxxB * loctmp_b_IzzB - loctmp_b_IxzB * loctmp_b_IxzB;
  loctmp_c2 = ((loctmp_b_IxxB - loctmp_b_IyyB) + loctmp_b_IzzB) * loctmp_b_IxzB /
    loctmp_delta_I;
  loctmp_c4 = loctmp_b_IxzB / loctmp_delta_I;

  /* %dynamic pressure%% */
  loctmp_Qbar_k = 0.5 * loctmp_b_rho * (loctmp_VT_k * loctmp_VT_k);

  /* %body velocities%% */
  loctmp_U_k = loctmp_VT_k * cos(loctmp_alpha_k) * cos(loctmp_beta_k);
  loctmp_V_k = loctmp_VT_k * sin(loctmp_beta_k);
  loctmp_W_k = loctmp_VT_k * sin(loctmp_alpha_k) * cos(loctmp_beta_k);

  /* %aerodynamic coefficients%% */
  loctmp_CL_k = ((((loctmp_Q_k - loctmp_b_Qtrim) * loctmp_b_CLq * loctmp_b_Cbar /
                   2.0 / loctmp_b_Utrim + (loctmp_b_CLa * loctmp_alpha_k +
    loctmp_b_CL0)) + loctmp_b_CLadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                  loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) * loctmp_b_CLu
                 / loctmp_b_Utrim) + loctmp_b_CLde * loctmp_EL_k;

  /* CD_k=CD0+CDa*alpha_k+CDq*(Q_k-Qtrim)*Cbar/2/Utrim+CDadot*alphadot_k*Cbar/2/Utrim+CDu*(U_k-Utrim)/Utrim+CDde*EL_k; %lin */
  loctmp_CD_k = ((((loctmp_CL_k * loctmp_CL_k / (3.1415926535897931 * loctmp_b_b
    / loctmp_b_Cbar * 0.87) + loctmp_b_CD0_bar) + (loctmp_Q_k - loctmp_b_Qtrim) *
                   loctmp_b_CDq * loctmp_b_Cbar / 2.0 / loctmp_b_Utrim) +
                  loctmp_b_CDadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                  loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) * loctmp_b_CDu
                 / loctmp_b_Utrim) + loctmp_b_CDde * loctmp_EL_k;

  /* nonlin */
  loctmp_Cls_k = ((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Clp * loctmp_b_b /
                    2.0 / loctmp_b_Utrim + loctmp_b_Clb * loctmp_beta_k) +
                   (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Clr * loctmp_b_b /
                   2.0 / loctmp_b_Utrim) + loctmp_b_Clda * loctmp_AIL_k) +
    loctmp_b_Cldr * loctmp_RDR_k;
  loctmp_Cms_k = ((((loctmp_Q_k - loctmp_b_Qtrim) * loctmp_b_Cmq * loctmp_b_Cbar
                    / 2.0 / loctmp_b_Utrim + (loctmp_b_Cma * loctmp_alpha_k +
    loctmp_b_Cm0)) + loctmp_b_Cmadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                   loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) *
                  loctmp_b_Cmu / loctmp_b_Utrim) + loctmp_b_Cmde * loctmp_EL_k;
  loctmp_Cns_k = ((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Cnp * loctmp_b_b /
                    2.0 / loctmp_b_Utrim + loctmp_b_Cnb * loctmp_beta_k) +
                   (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Cnr * loctmp_b_b /
                   2.0 / loctmp_b_Utrim) + loctmp_b_Cnda * loctmp_AIL_k) +
    loctmp_b_Cndr * loctmp_RDR_k;
  loctmp_Cl_k = loctmp_Cls_k * cos(loctmp_alpha_k) - loctmp_Cns_k * sin
    (loctmp_alpha_k);
  loctmp_Cn_k = loctmp_Cls_k * sin(loctmp_alpha_k) + loctmp_Cns_k * cos
    (loctmp_alpha_k);

  /* %engine thrust%% */
  loctmp_Cls_k = 100.0 * loctmp_THL_k;

  /* %S&C aerodynamic and thrust linear accelerations%% */
  *loctmp_accelX_scd_k = (((loctmp_Cls_k * loctmp_Cls_k * loctmp_b_xT2 + 100.0 *
    loctmp_THL_k * loctmp_b_xT1) + loctmp_b_xT0) + (-loctmp_CD_k * cos
    (loctmp_alpha_k) + loctmp_CL_k * sin(loctmp_alpha_k)) * (loctmp_Qbar_k *
    loctmp_b_S)) / loctmp_mass;

  /* [ft/s2] */
  *loctmp_accelY_scd_k = (((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Cyp *
    loctmp_b_b / 2.0 / loctmp_b_Utrim + loctmp_b_Cyb * loctmp_beta_k) +
    (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Cyr * loctmp_b_b / 2.0 /
    loctmp_b_Utrim) + loctmp_b_Cyda * loctmp_AIL_k) + loctmp_b_Cydr *
    loctmp_RDR_k) * (loctmp_Qbar_k * loctmp_b_S) / loctmp_mass;

  /* [ft/s2] */
  *loctmp_accelZ_scd_k = (-loctmp_CD_k * sin(loctmp_alpha_k) - loctmp_CL_k * cos
                          (loctmp_alpha_k)) * (loctmp_Qbar_k * loctmp_b_S) /
    loctmp_mass;

  /* [ft/s2] */
  /* ANN linear accelerations */
  /* X-axis */
  loctmp_VT_k_2[0] = loctmp_VT_k;
  loctmp_VT_k_2[1] = loctmp_alpha_k;
  loctmp_VT_k_2[2] = loctmp_beta_k;
  loctmp_VT_k_2[3] = loctmp_Q_k;
  loctmp_VT_k_2[4] = loctmp_alphadot_k;
  loctmp_VT_k_2[5] = loctmp_THL_k;
  loctmp_VT_k_2[6] = loctmp_EL_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_2, loctmp_b_X_minXin, loctmp_b_X_maxXin,
    loctmp_b_X_minYin, loctmp_b_X_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_X[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_X[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_X[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelX_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_X,
    loctmp_b_X_minXout, loctmp_b_X_maxXout, loctmp_b_X_minYout,
    loctmp_b_X_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  /* Y_axis */
  loctmp_VT_k_1[0] = loctmp_VT_k;
  loctmp_VT_k_1[1] = loctmp_beta_k;
  loctmp_VT_k_1[2] = loctmp_P_k;
  loctmp_VT_k_1[3] = loctmp_R_k;
  loctmp_VT_k_1[4] = loctmp_betadot_k;
  loctmp_VT_k_1[5] = loctmp_AIL_k;
  loctmp_VT_k_1[6] = loctmp_RDR_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_1, loctmp_b_Y_minXin, loctmp_b_Y_maxXin,
    loctmp_b_Y_minYin, loctmp_b_Y_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_Y[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_Y[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_Y[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelY_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_Y,
    loctmp_b_Y_minXout, loctmp_b_Y_maxXout, loctmp_b_Y_minYout,
    loctmp_b_Y_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  /* Z-axis */
  loctmp_VT_k_0[0] = loctmp_VT_k;
  loctmp_VT_k_0[1] = loctmp_alpha_k;
  loctmp_VT_k_0[2] = loctmp_beta_k;
  loctmp_VT_k_0[3] = loctmp_Q_k;
  loctmp_VT_k_0[4] = loctmp_alphadot_k;
  loctmp_VT_k_0[5] = loctmp_THL_k;
  loctmp_VT_k_0[6] = loctmp_EL_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_0, loctmp_b_Z_minXin, loctmp_b_Z_maxXin,
    loctmp_b_Z_minYin, loctmp_b_Z_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_Z[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_Z[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_Z[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelZ_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_Z,
    loctmp_b_Z_minXout, loctmp_b_Z_maxXout, loctmp_b_Z_minYout,
    loctmp_b_Z_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  loctmp_Cls_k = 0.0;

  /* initialization */
  loctmp_Cns_k = 0.0;

  /* initialization */
  loctmp_mass = 0.0;

  /* initialization */
  if (loctmp_FL_ann == 0.0) {
    /* scd */
    loctmp_Cls_k = *loctmp_accelX_scd_k;
    loctmp_Cns_k = *loctmp_accelY_scd_k;
    loctmp_mass = *loctmp_accelZ_scd_k;
  } else {
    if (loctmp_FL_ann == 1.0) {
      /* ann */
      loctmp_Cls_k = *loctmp_accelX_ann_k;
      loctmp_Cns_k = *loctmp_accelY_ann_k;
      loctmp_mass = *loctmp_accelZ_ann_k;
    }
  }

  /* body accelerations */
  loctmp_Udot_k = ((loctmp_R_k * loctmp_V_k - loctmp_Q_k * loctmp_W_k) -
                   loctmp_b_g * sin(loctmp_theta_k)) + loctmp_Cls_k;
  loctmp_Vdot_k = ((loctmp_P_k * loctmp_W_k - loctmp_R_k * loctmp_U_k) +
                   loctmp_b_g * sin(loctmp_phi_k) * cos(loctmp_theta_k)) +
    loctmp_Cns_k;
  loctmp_Wdot_k = ((loctmp_Q_k * loctmp_U_k - loctmp_P_k * loctmp_V_k) +
                   loctmp_b_g * cos(loctmp_phi_k) * cos(loctmp_theta_k)) +
    loctmp_mass;

  /* %inertial speed (with no wind)%% */
  loctmp_fn_k = ((sin(loctmp_phi_k) * sin(loctmp_theta_k) * cos(loctmp_psi_k) -
                  cos(loctmp_phi_k) * sin(loctmp_psi_k)) * loctmp_V_k +
                 loctmp_U_k * cos(loctmp_theta_k) * cos(loctmp_psi_k)) + (cos
    (loctmp_phi_k) * sin(loctmp_theta_k) * cos(loctmp_psi_k) + sin(loctmp_phi_k)
    * sin(loctmp_psi_k)) * loctmp_W_k;
  loctmp_fe_k = ((sin(loctmp_phi_k) * sin(loctmp_theta_k) * sin(loctmp_psi_k) +
                  cos(loctmp_phi_k) * cos(loctmp_psi_k)) * loctmp_V_k +
                 loctmp_U_k * cos(loctmp_theta_k) * sin(loctmp_psi_k)) + (cos
    (loctmp_phi_k) * sin(loctmp_theta_k) * sin(loctmp_psi_k) - sin(loctmp_phi_k)
    * cos(loctmp_psi_k)) * loctmp_W_k;
  loctmp_fh_k = (loctmp_U_k * sin(loctmp_theta_k) - loctmp_V_k * sin
                 (loctmp_phi_k) * cos(loctmp_theta_k)) - loctmp_W_k * cos
    (loctmp_phi_k) * cos(loctmp_theta_k);

  /* %inertial speed%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Local variable assignment */
  *loctmp_wpt_index_kk = loctmp_wpt_index_k;
  *loctmp_home_reset_kk = loctmp_home_reset_k;

  /* PIC/CIC Transition Logic: */
  /*  On transition to CIC or PIC, set index = 0 and current position to  */
  /*  current waypoint; hold current waypoint. */
  if ((loctmp_sw > (real_T)loctmp_pic_cic_k) || (loctmp_sw == 0.0)) {
    loctmp_start_wpt_k[0] = loctmp_h_k;
    loctmp_start_wpt_k[1] = loctmp_n_k;
    loctmp_start_wpt_k[2] = loctmp_e_k;
    *loctmp_wpt_index_kk = 0U;
    *loctmp_home_reset_kk = 0U;
  }

  /*  Change the waypoint index when home command */
  if ((loctmp_home_cmd == 1) && (loctmp_sw == 1.0) && (*loctmp_home_reset_kk ==
       0)) {
    *loctmp_wpt_index_kk = 23U;
    *loctmp_home_reset_kk = 1U;
  }

  /* OP trajectory generation */
  /* %reassigning the a and b waypoints */
  if ((loctmp_b_TR == 2.0) && (*loctmp_home_reset_kk == 0)) {
    *loctmp_wpt_index_kk = 1U;
    loctmp_wpts_n[loctmp_wpt_index_k - 1] = loctmp_n_op_k - 100.0 *
      loctmp_vn_op_k;
    loctmp_factor = (int32_T)(loctmp_wpt_index_k + 1U);
    if ((uint32_T)loctmp_factor > 255U) {
      loctmp_factor = 255;
    }

    loctmp_wpts_n[loctmp_factor - 1] = 100.0 * loctmp_vn_op_k + loctmp_n_op_k;
    loctmp_wpts_e[loctmp_wpt_index_k - 1] = loctmp_e_op_k - 100.0 *
      loctmp_ve_op_k;
    loctmp_factor = (int32_T)(loctmp_wpt_index_k + 1U);
    if ((uint32_T)loctmp_factor > 255U) {
      loctmp_factor = 255;
    }

    loctmp_wpts_e[loctmp_factor - 1] = 100.0 * loctmp_ve_op_k + loctmp_e_op_k;
    loctmp_wpts_h[loctmp_wpt_index_k - 1] = loctmp_h_op_k - 100.0 *
      loctmp_vh_op_k;
    loctmp_factor = (int32_T)(loctmp_wpt_index_k + 1U);
    if ((uint32_T)loctmp_factor > 255U) {
      loctmp_factor = 255;
    }

    loctmp_wpts_h[loctmp_factor - 1] = 100.0 * loctmp_vh_op_k + loctmp_h_op_k;
  }

  /* calculate the next waypoint index */
  loctmp_factor = (int32_T)(*loctmp_wpt_index_kk + 1U);
  if ((uint32_T)loctmp_factor > 255U) {
    loctmp_factor = 255;
  }

  loctmp_next_wpt_index = (uint8_T)loctmp_factor;

  /* beyond final point (fp), go to return point (rp) */
  if ((uint8_T)loctmp_factor > loctmp_wpts_fp) {
    loctmp_next_wpt_index = loctmp_wpts_rp;
  }

  /* calculate distance to next waypoint */
  loctmp_Cls_k = loctmp_n_k - loctmp_wpts_n[loctmp_next_wpt_index - 1];
  loctmp_Cns_k = loctmp_e_k - loctmp_wpts_e[loctmp_next_wpt_index - 1];
  loctmp_Cls_k = sqrt(loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k * loctmp_Cns_k);

  /* change to next waypoint if in range */
  if ((loctmp_Cls_k < loctmp_b_dist2b) && (loctmp_sw == 1.0)) {
    /*  Do not change index if sw=0 */
    *loctmp_wpt_index_kk = loctmp_next_wpt_index;
    if (loctmp_next_wpt_index == loctmp_wpts_fp) {
      loctmp_next_wpt_index = loctmp_wpts_rp;
    } else {
      loctmp_factor = (int32_T)(loctmp_next_wpt_index + 1U);
      if ((uint32_T)loctmp_factor > 255U) {
        loctmp_factor = 255;
      }

      loctmp_next_wpt_index = (uint8_T)loctmp_factor;
    }
  }

  /* function outputs */
  if ((*loctmp_wpt_index_kk == 0) || (*loctmp_wpt_index_kk == 23)) {
    /*  Assign the speed of the starting segment to the speed of the first */
    /*  waypoint */
    *loctmp_Vab_k = loctmp_wpts_v[0];
    loctmp_CL_k = loctmp_start_wpt_k[0];
    loctmp_CD_k = loctmp_start_wpt_k[1];
    loctmp_ea = loctmp_start_wpt_k[2];
  } else {
    *loctmp_Vab_k = loctmp_wpts_v[*loctmp_wpt_index_kk - 1];
    loctmp_CL_k = loctmp_wpts_h[*loctmp_wpt_index_kk - 1];
    loctmp_CD_k = loctmp_wpts_n[*loctmp_wpt_index_kk - 1];
    loctmp_ea = loctmp_wpts_e[*loctmp_wpt_index_kk - 1];
  }

  *loctmp_distance2b = (real32_T)loctmp_Cls_k;
  *loctmp_pic_cic_kk = loctmp_sw;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %reference point r%% */
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_Cls_k = (((loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) *
                   (loctmp_h_k - loctmp_CL_k) +
                   (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) *
                   (loctmp_n_k - loctmp_CD_k)) +
                  (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea) *
                  (loctmp_e_k - loctmp_ea)) / ((loctmp_Cls_k * loctmp_Cls_k +
    loctmp_Cns_k * loctmp_Cns_k) + loctmp_mass * loctmp_mass);
  loctmp_hd_k = (loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) *
    loctmp_Cls_k + loctmp_CL_k;
  loctmp_nd_k = (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) *
    loctmp_Cls_k + loctmp_CD_k;
  loctmp_ed_k = (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea) *
    loctmp_Cls_k + loctmp_ea;
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k;
  loctmp_Cls_k = loctmp_b_L / sqrt((loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_mass * loctmp_mass);
  *loctmp_er_k = (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k) *
    loctmp_Cls_k + loctmp_ed_k;
  *loctmp_nr_k = (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k) *
    loctmp_Cls_k + loctmp_nd_k;
  *loctmp_hr_k = (loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k) *
    loctmp_Cls_k + loctmp_hd_k;

  /* %alpha and beta track%% */
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_atrack = asin((loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) /
                       sqrt((loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_mass * loctmp_mass));
  loctmp_Cls_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_Cns_k = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_factor = 1;
  loctmp_mass = 0.0;
  if (!((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k > 0.0) &&
        (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea > 0.0))) {
    if ((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k > 0.0) &&
        (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea < 0.0)) {
      loctmp_mass = 3.1415926535897931;
      loctmp_factor = -1;
    } else {
      if ((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k < 0.0) &&
          (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea < 0.0)) {
        loctmp_mass = -3.1415926535897931;
        loctmp_factor = -1;
      }
    }
  }

  loctmp_btrack = asin((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) /
                       sqrt(loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k)) * (real_T)loctmp_factor + loctmp_mass;

  /* %edot, ndot and hdot relative to track%% */
  loctmp_edot_track_k = (sin(loctmp_atrack) * cos(loctmp_btrack) * loctmp_fh_k +
    sin(loctmp_btrack) * loctmp_fn_k) + cos(loctmp_atrack) * cos(loctmp_btrack) *
    loctmp_fe_k;
  loctmp_ndot_track_k = (-sin(loctmp_atrack) * sin(loctmp_btrack) * loctmp_fh_k
    + cos(loctmp_btrack) * loctmp_fn_k) - cos(loctmp_atrack) * sin(loctmp_btrack)
    * loctmp_fe_k;

  /* %er-e, nr-n and hr-h relative to track%% */
  /* %etaLon at time [k]%% */
  loctmp_nr_k_0[0] = *loctmp_nr_k - loctmp_n_k;
  loctmp_nr_k_0[1] = *loctmp_er_k - loctmp_e_k;
  loctmp_fn_k_0[0] = loctmp_fn_k;
  loctmp_fn_k_0[1] = loctmp_fe_k;
  *loctmp_etaLon_k = rt_atan2d_snf(*loctmp_hr_k - loctmp_h_k,
    ANN_EKF_NMPC_2_norm(loctmp_nr_k_0)) - rt_atan2d_snf(loctmp_fh_k,
    ANN_EKF_NMPC_2_norm(loctmp_fn_k_0));

  /* %etaLat at time [k]%% */
  loctmp_Cls_k = rt_atan2d_snf(loctmp_ndot_track_k, loctmp_edot_track_k) -
    rt_atan2d_snf((-sin(loctmp_atrack) * sin(loctmp_btrack) * (*loctmp_hr_k -
    loctmp_h_k) + (*loctmp_nr_k - loctmp_n_k) * cos(loctmp_btrack)) - cos
                  (loctmp_atrack) * sin(loctmp_btrack) * (*loctmp_er_k -
    loctmp_e_k), (sin(loctmp_atrack) * cos(loctmp_btrack) * (*loctmp_hr_k -
    loctmp_h_k) + (*loctmp_nr_k - loctmp_n_k) * sin(loctmp_btrack)) + cos
                  (loctmp_atrack) * cos(loctmp_btrack) * (*loctmp_er_k -
    loctmp_e_k));
  *loctmp_etaLat_k = loctmp_Cls_k;
  if (loctmp_Cls_k > 3.1415926535897931) {
    *loctmp_etaLat_k = loctmp_Cls_k - 6.2831853071795862;
  }

  if (loctmp_Cls_k < -3.1415926535897931) {
    *loctmp_etaLat_k = loctmp_Cls_k + 6.2831853071795862;
  }

  /* OP trajectory generation */
  /* reassigning Vab (based on the new d point) */
  if (loctmp_b_TR == 2.0) {
    loctmp_CL_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_n_op_k;
    loctmp_CD_k = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_e_op_k;
    loctmp_ea = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_h_op_k;
    loctmp_r_a = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k;
    loctmp_s_a = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k;
    loctmp_t_a = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k;
    loctmp_mass = loctmp_nd_k - loctmp_n_op_k;
    loctmp_Cns_k = loctmp_ed_k - loctmp_e_op_k;
    loctmp_Cls_k = loctmp_hd_k - loctmp_h_op_k;
    loctmp_r_a = sqrt((loctmp_CL_k * loctmp_CL_k + loctmp_CD_k * loctmp_CD_k) +
                      loctmp_ea * loctmp_ea) - sqrt((loctmp_r_a * loctmp_r_a +
      loctmp_s_a * loctmp_s_a) + loctmp_t_a * loctmp_t_a);
    if (loctmp_r_a < 0.0) {
      loctmp_r_a = -1.0;
    } else if (loctmp_r_a > 0.0) {
      loctmp_r_a = 1.0;
    } else {
      if (loctmp_r_a == 0.0) {
        loctmp_r_a = 0.0;
      }
    }

    *loctmp_Vab_k = sqrt((loctmp_vn_op_k * loctmp_vn_op_k + loctmp_ve_op_k *
                          loctmp_ve_op_k) + loctmp_vh_op_k * loctmp_vh_op_k) -
      atan(sqrt((loctmp_mass * loctmp_mass + loctmp_Cns_k * loctmp_Cns_k) +
                loctmp_Cls_k * loctmp_Cls_k) * loctmp_r_a / 100.0) *
      0.063661977236758135;

    /* (168.78) (5) (/100) */
  }

  /* %VT theta phi and beta command%% */
  /* %consider wind in VTcmd [0]: no [1]:yes */
  loctmp_mass = *loctmp_Vab_k * cos(loctmp_atrack) * sin(loctmp_btrack) + 0.0 *
    loctmp_sw;
  loctmp_Cns_k = *loctmp_Vab_k * cos(loctmp_atrack) * cos(loctmp_btrack) + 0.0 *
    loctmp_sw;
  loctmp_Cls_k = *loctmp_Vab_k * sin(loctmp_atrack) + 0.0 * loctmp_sw;
  *loctmp_VTcmd_k = sqrt((loctmp_mass * loctmp_mass + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_Cls_k * loctmp_Cls_k);
  loctmp_Cls_k = atan(*loctmp_etaLon_k * loctmp_sw);
  loctmp_er_k_1[0] = *loctmp_er_k - loctmp_e_k;
  loctmp_er_k_1[1] = *loctmp_nr_k - loctmp_n_k;
  loctmp_er_k_1[2] = *loctmp_hr_k - loctmp_h_k;
  *loctmp_thetacmd_k = rt_atan2d_snf(((loctmp_fe_k * loctmp_fe_k + loctmp_fn_k *
    loctmp_fn_k) + loctmp_fh_k * loctmp_fh_k) * 2.0 * (loctmp_Cls_k *
    loctmp_b_KpLon + loctmp_ro_k), ANN_EKF_NMPC_2_norm_h(loctmp_er_k_1));
  loctmp_er_k_0[0] = *loctmp_er_k - loctmp_e_k;
  loctmp_er_k_0[1] = *loctmp_nr_k - loctmp_n_k;
  *loctmp_phicmd_k = rt_atan2d_snf((loctmp_edot_track_k * loctmp_edot_track_k +
    loctmp_ndot_track_k * loctmp_ndot_track_k) * 2.0 * loctmp_b_KpLat *
    loctmp_sw * *loctmp_etaLat_k, ANN_EKF_NMPC_2_norm(loctmp_er_k_0));

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%implementing saturation of actuators%% */
  /* %deflection max and min */
  if (loctmp_THL_k > loctmp_b_ThrottleMax) {
    loctmp_THL_k = loctmp_b_ThrottleMax;
  } else {
    if (loctmp_THL_k < loctmp_b_ThrottleMin) {
      loctmp_THL_k = loctmp_b_ThrottleMin;
    }
  }

  if (loctmp_EL_k > loctmp_b_ElevatorMax) {
    loctmp_EL_k = loctmp_b_ElevatorMax;
  } else {
    if (loctmp_EL_k < loctmp_b_ElevatorMin) {
      loctmp_EL_k = loctmp_b_ElevatorMin;
    }
  }

  if (loctmp_AIL_k > loctmp_b_AileronMax) {
    loctmp_AIL_k = loctmp_b_AileronMax;
  } else {
    if (loctmp_AIL_k < loctmp_b_AileronMin) {
      loctmp_AIL_k = loctmp_b_AileronMin;
    }
  }

  if (loctmp_RDR_k > loctmp_b_RudderMax) {
    loctmp_RDR_k = loctmp_b_RudderMax;
  } else {
    if (loctmp_RDR_k < loctmp_b_RudderMin) {
      loctmp_RDR_k = loctmp_b_RudderMin;
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %longitudinal guidance integrator */
  *loctmp_ro_kk = loctmp_b_dt * loctmp_Cls_k * loctmp_b_KiLon + loctmp_ro_k;

  /* %servos prediction%% */
  *loctmp_THL_kk = (loctmp_b_Athrottle * loctmp_THL_k + loctmp_b_Bthrottle *
                    loctmp_THLcmd_k) * loctmp_b_dt + loctmp_THL_k;
  *loctmp_EL_kk = (loctmp_b_Aelevator * loctmp_EL_k + loctmp_b_Belevator *
                   loctmp_ELcmd_k) * loctmp_b_dt + loctmp_EL_k;
  *loctmp_AIL_kk = (loctmp_b_Aaileron * loctmp_AIL_k + loctmp_b_Baileron *
                    loctmp_AILcmd_k) * loctmp_b_dt + loctmp_AIL_k;
  *loctmp_RDR_kk = (loctmp_b_Arudder * loctmp_RDR_k + loctmp_b_Brudder *
                    loctmp_RDRcmd_k) * loctmp_b_dt + loctmp_RDR_k;

  /* %UAV prediction%% */
  loctmp_Cls_k = ((loctmp_U_k * loctmp_Udot_k + loctmp_V_k * loctmp_Vdot_k) +
                  loctmp_W_k * loctmp_Wdot_k) / loctmp_VT_k;
  *loctmp_falpha_k = (loctmp_U_k * loctmp_Wdot_k - loctmp_W_k * loctmp_Udot_k) /
    (loctmp_U_k * loctmp_U_k + loctmp_W_k * loctmp_W_k);
  *loctmp_fbeta_k = (loctmp_VT_k * loctmp_Vdot_k - loctmp_V_k * loctmp_Cls_k) /
    (loctmp_U_k * loctmp_U_k + loctmp_W_k * loctmp_W_k) * cos(loctmp_beta_k);
  *loctmp_VT_kk = loctmp_b_dt * loctmp_Cls_k + loctmp_VT_k;
  *loctmp_alpha_kk = loctmp_b_dt * *loctmp_falpha_k + loctmp_alpha_k;
  *loctmp_beta_kk = loctmp_b_dt * *loctmp_fbeta_k + loctmp_beta_k;
  *loctmp_phi_kk = ((loctmp_R_k * cos(loctmp_phi_k) + loctmp_Q_k * sin
                     (loctmp_phi_k)) * tan(loctmp_theta_k) + loctmp_P_k) *
    loctmp_b_dt + loctmp_phi_k;
  *loctmp_theta_kk = (loctmp_Q_k * cos(loctmp_phi_k) - loctmp_R_k * sin
                      (loctmp_phi_k)) * loctmp_b_dt + loctmp_theta_k;
  *loctmp_psi_kk = (loctmp_R_k * cos(loctmp_phi_k) + loctmp_Q_k * sin
                    (loctmp_phi_k)) / cos(loctmp_theta_k) * loctmp_b_dt +
    loctmp_psi_k;
  *loctmp_P_kk = ((((loctmp_b_IyyB - loctmp_b_IzzB) * loctmp_b_IzzB -
                    loctmp_b_IxzB * loctmp_b_IxzB) / loctmp_delta_I * loctmp_R_k
                   + loctmp_c2 * loctmp_P_k) * loctmp_Q_k + (loctmp_b_IzzB /
    loctmp_delta_I * loctmp_Cl_k + loctmp_c4 * loctmp_Cn_k) * (loctmp_Qbar_k *
    loctmp_b_S * loctmp_b_b)) * loctmp_b_dt + loctmp_P_k;
  *loctmp_Q_kk = (((loctmp_b_IzzB - loctmp_b_IxxB) / loctmp_b_IyyB * loctmp_P_k *
                   loctmp_R_k - (loctmp_P_k * loctmp_P_k - loctmp_R_k *
    loctmp_R_k) * (loctmp_b_IxzB / loctmp_b_IyyB)) + loctmp_Qbar_k * loctmp_b_S *
                  loctmp_b_Cbar * (1.0 / loctmp_b_IyyB) * loctmp_Cms_k) *
    loctmp_b_dt + loctmp_Q_k;
  *loctmp_R_kk = ((((loctmp_b_IxxB - loctmp_b_IyyB) * loctmp_b_IxxB +
                    loctmp_b_IxzB * loctmp_b_IxzB) / loctmp_delta_I * loctmp_P_k
                   - loctmp_c2 * loctmp_R_k) * loctmp_Q_k + (loctmp_b_IxxB /
    loctmp_delta_I * loctmp_Cn_k + loctmp_c4 * loctmp_Cl_k) * (loctmp_Qbar_k *
    loctmp_b_S * loctmp_b_b)) * loctmp_b_dt + loctmp_R_k;

  /* %inertial frame prediction%% */
  *loctmp_n_kk = loctmp_b_dt * loctmp_fn_k + loctmp_n_k;
  *loctmp_e_kk = loctmp_b_dt * loctmp_fe_k + loctmp_e_k;
  *loctmp_h_kk = loctmp_b_dt * loctmp_fh_k + loctmp_h_k;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %outputs e, y and z%% */
  loctmp_e_augm_k[0] = *loctmp_VTcmd_k - loctmp_VT_k;
  loctmp_e_augm_k[1] = *loctmp_thetacmd_k - loctmp_theta_k;
  loctmp_e_augm_k[2] = *loctmp_phicmd_k - loctmp_phi_k;
  loctmp_e_augm_k[3] = 0.0 - loctmp_beta_k;

  /* %Robustness states at [k+1]%% */
  *loctmp_xw11_kk = loctmp_b_W11d.a * loctmp_xw11_k + loctmp_b_W11d.b *
    loctmp_e_augm_k[0];

  /* W11 e_VT */
  *loctmp_xw12_kk = loctmp_b_W12d.a * loctmp_xw12_k + loctmp_b_W12d.b *
    loctmp_e_augm_k[1];

  /* W12 e_theta */
  *loctmp_xw13_kk = loctmp_b_W13d.a * loctmp_xw13_k + loctmp_b_W13d.b *
    loctmp_e_augm_k[2];

  /* W13 e_phi */
  *loctmp_xw14_kk = (0.0 - loctmp_beta_k) * loctmp_b_W14d.b + loctmp_b_W14d.a *
    loctmp_xw14_k;

  /* W14 e_beta */
  *loctmp_xw21_kk = loctmp_b_W21d.a * loctmp_xw21_k + loctmp_b_W21d.b *
    loctmp_THLcmd_k;

  /* W21 Throttle cmd */
  *loctmp_xw22_kk = loctmp_b_W22d.a * loctmp_xw22_k + loctmp_b_W22d.b *
    loctmp_ELcmd_k;

  /* W22 Elevator cmd */
  *loctmp_xw23_kk = loctmp_b_W23d.a * loctmp_xw23_k + loctmp_b_W23d.b *
    loctmp_AILcmd_k;

  /* W23 Aileron cmd */
  *loctmp_xw24_kk = loctmp_b_W24d.a * loctmp_xw24_k + loctmp_b_W24d.b *
    loctmp_RDRcmd_k;

  /* W24 Rudder cmd */
  *loctmp_xw31_kk = loctmp_b_W31d.a * loctmp_xw31_k + loctmp_b_W31d.b *
    loctmp_VT_k;

  /* W31 VT */
  *loctmp_xw32_kk = loctmp_b_W32d.a * loctmp_xw32_k + loctmp_b_W32d.b *
    loctmp_theta_k;

  /* W32 theta */
  *loctmp_xw33_kk = loctmp_b_W33d.a * loctmp_xw33_k + loctmp_b_W33d.b *
    loctmp_phi_k;

  /* W33 phi */
  *loctmp_xw34_kk = loctmp_b_W34d.a * loctmp_xw34_k + loctmp_b_W34d.b *
    loctmp_beta_k;

  /* W34 beta */
  /* %Robustness output at [k] */
  loctmp_z_augm_k[0] = loctmp_b_W11d.c * loctmp_xw11_k + loctmp_b_W11d.d *
    loctmp_e_augm_k[0];

  /* W11 e_VT */
  loctmp_z_augm_k[1] = loctmp_b_W12d.c * loctmp_xw12_k + loctmp_b_W12d.d *
    loctmp_e_augm_k[1];

  /* W12 e_theta */
  loctmp_z_augm_k[2] = loctmp_b_W13d.c * loctmp_xw13_k + loctmp_b_W13d.d *
    loctmp_e_augm_k[2];

  /* W13 e_phi */
  loctmp_z_augm_k[3] = (0.0 - loctmp_beta_k) * loctmp_b_W14d.d + loctmp_b_W14d.c
    * loctmp_xw14_k;

  /* W14 e_beta */
  loctmp_z_augm_k[4] = loctmp_b_W21d.c * loctmp_xw21_k + loctmp_b_W21d.d *
    loctmp_THLcmd_k;

  /* W21 Throttle cmd */
  loctmp_z_augm_k[5] = loctmp_b_W22d.c * loctmp_xw22_k + loctmp_b_W22d.d *
    loctmp_ELcmd_k;

  /* W22 Elevator cmd */
  loctmp_z_augm_k[6] = loctmp_b_W23d.c * loctmp_xw23_k + loctmp_b_W23d.d *
    loctmp_AILcmd_k;

  /* W23 Aileron cmd */
  loctmp_z_augm_k[7] = loctmp_b_W24d.c * loctmp_xw24_k + loctmp_b_W24d.d *
    loctmp_RDRcmd_k;

  /* W24 Rudder cmd */
  loctmp_z_augm_k[8] = loctmp_b_W31d.c * loctmp_xw31_k + loctmp_b_W31d.d *
    loctmp_VT_k;

  /* W31 VT */
  loctmp_z_augm_k[9] = loctmp_b_W32d.c * loctmp_xw32_k + loctmp_b_W32d.d *
    loctmp_theta_k;

  /* W32 theta */
  loctmp_z_augm_k[10] = loctmp_b_W33d.c * loctmp_xw33_k + loctmp_b_W33d.d *
    loctmp_phi_k;

  /* W33 phi */
  loctmp_z_augm_k[11] = loctmp_b_W34d.c * loctmp_xw34_k + loctmp_b_W34d.d *
    loctmp_beta_k;

  /* W34 beta */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_eml_ipiv2perm(const int32_T loctmp_ipiv[80], int32_T
  loctmp_perm[80])
{
  int32_T loctmp_pipk;
  int32_T loctmp_k;
  for (loctmp_k = 0; loctmp_k < 80; loctmp_k++) {
    loctmp_perm[loctmp_k] = 1 + loctmp_k;
  }

  for (loctmp_k = 0; loctmp_k < 79; loctmp_k++) {
    if (loctmp_ipiv[loctmp_k] > 1 + loctmp_k) {
      loctmp_pipk = loctmp_perm[loctmp_ipiv[loctmp_k] - 1];
      loctmp_perm[loctmp_ipiv[loctmp_k] - 1] = loctmp_perm[loctmp_k];
      loctmp_perm[loctmp_k] = loctmp_pipk;
    }
  }
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_eml_xtrsm_c(const real_T loctmp_A[6400], real_T
  loctmp_B[6400])
{
  int32_T loctmp_jBcol;
  int32_T loctmp_kAcol;
  int32_T loctmp_j;
  int32_T loctmp_k;
  int32_T loctmp_i;
  for (loctmp_j = 0; loctmp_j < 80; loctmp_j++) {
    loctmp_jBcol = 80 * loctmp_j;
    for (loctmp_k = 79; loctmp_k >= 0; loctmp_k += -1) {
      loctmp_kAcol = 80 * loctmp_k;
      if (loctmp_B[loctmp_k + loctmp_jBcol] != 0.0) {
        loctmp_B[loctmp_k + loctmp_jBcol] /= loctmp_A[loctmp_k + loctmp_kAcol];
        for (loctmp_i = 0; loctmp_i + 1 <= loctmp_k; loctmp_i++) {
          loctmp_B[loctmp_i + loctmp_jBcol] -= loctmp_B[loctmp_k + loctmp_jBcol]
            * loctmp_A[loctmp_i + loctmp_kAcol];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_eml_xswap_e(real_T loctmp_x[6400], int32_T loctmp_ix0,
  int32_T loctmp_iy0)
{
  int32_T loctmp_ix;
  int32_T loctmp_iy;
  real_T loctmp_temp;
  int32_T loctmp_k;
  loctmp_ix = loctmp_ix0 - 1;
  loctmp_iy = loctmp_iy0 - 1;
  for (loctmp_k = 0; loctmp_k < 80; loctmp_k++) {
    loctmp_temp = loctmp_x[loctmp_ix];
    loctmp_x[loctmp_ix] = loctmp_x[loctmp_iy];
    loctmp_x[loctmp_iy] = loctmp_temp;
    loctmp_ix += 80;
    loctmp_iy += 80;
  }
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_invNxN(const real_T loctmp_x[6400], real_T loctmp_y
  [6400])
{
  int32_T loctmp_p[80];
  int32_T loctmp_c;
  int32_T loctmp_j;
  int32_T loctmp_ipiv[80];
  int32_T loctmp_b_j;
  int32_T loctmp_c_c;
  real_T loctmp_smax;
  real_T loctmp_s;
  int32_T loctmp_jA;
  int32_T loctmp_b_ix;
  int32_T loctmp_e;
  int32_T loctmp_ijA;
  for (loctmp_b_j = 0; loctmp_b_j < 6400; loctmp_b_j++) {
    loctmp_y[loctmp_b_j] = 0.0;
    ANN_EKF_NMPC_2_B.A[loctmp_b_j] = loctmp_x[loctmp_b_j];
  }

  for (loctmp_b_j = 0; loctmp_b_j < 80; loctmp_b_j++) {
    loctmp_ipiv[loctmp_b_j] = 1 + loctmp_b_j;
  }

  for (loctmp_b_j = 0; loctmp_b_j < 79; loctmp_b_j++) {
    loctmp_c_c = loctmp_b_j * 81;
    loctmp_jA = 1;
    loctmp_c = loctmp_c_c;
    loctmp_smax = fabs(ANN_EKF_NMPC_2_B.A[loctmp_c_c]);
    for (loctmp_j = 2; loctmp_j <= 80 - loctmp_b_j; loctmp_j++) {
      loctmp_c++;
      loctmp_s = fabs(ANN_EKF_NMPC_2_B.A[loctmp_c]);
      if (loctmp_s > loctmp_smax) {
        loctmp_jA = loctmp_j;
        loctmp_smax = loctmp_s;
      }
    }

    if (ANN_EKF_NMPC_2_B.A[(loctmp_c_c + loctmp_jA) - 1] != 0.0) {
      if (loctmp_jA - 1 != 0) {
        loctmp_ipiv[loctmp_b_j] = loctmp_b_j + loctmp_jA;
        ANN_EKF_NMPC_2_eml_xswap_e(ANN_EKF_NMPC_2_B.A, loctmp_b_j + 1,
          loctmp_b_j + loctmp_jA);
      }

      loctmp_jA = (loctmp_c_c - loctmp_b_j) + 80;
      for (loctmp_c = loctmp_c_c + 1; loctmp_c + 1 <= loctmp_jA; loctmp_c++) {
        ANN_EKF_NMPC_2_B.A[loctmp_c] /= ANN_EKF_NMPC_2_B.A[loctmp_c_c];
      }
    }

    loctmp_jA = loctmp_c_c;
    loctmp_c = loctmp_c_c + 80;
    for (loctmp_j = 1; loctmp_j <= 79 - loctmp_b_j; loctmp_j++) {
      loctmp_smax = ANN_EKF_NMPC_2_B.A[loctmp_c];
      if (ANN_EKF_NMPC_2_B.A[loctmp_c] != 0.0) {
        loctmp_b_ix = loctmp_c_c + 1;
        loctmp_e = (loctmp_jA - loctmp_b_j) + 160;
        for (loctmp_ijA = 81 + loctmp_jA; loctmp_ijA + 1 <= loctmp_e; loctmp_ijA
             ++) {
          ANN_EKF_NMPC_2_B.A[loctmp_ijA] += ANN_EKF_NMPC_2_B.A[loctmp_b_ix] *
            -loctmp_smax;
          loctmp_b_ix++;
        }
      }

      loctmp_c += 80;
      loctmp_jA += 80;
    }
  }

  ANN_EKF_NMPC_2_eml_ipiv2perm(loctmp_ipiv, loctmp_p);
  for (loctmp_jA = 0; loctmp_jA < 80; loctmp_jA++) {
    loctmp_c = loctmp_p[loctmp_jA] - 1;
    loctmp_y[loctmp_jA + 80 * (loctmp_p[loctmp_jA] - 1)] = 1.0;
    for (loctmp_j = loctmp_jA; loctmp_j + 1 < 81; loctmp_j++) {
      if (loctmp_y[80 * loctmp_c + loctmp_j] != 0.0) {
        for (loctmp_b_ix = loctmp_j + 1; loctmp_b_ix + 1 < 81; loctmp_b_ix++) {
          loctmp_y[loctmp_b_ix + 80 * loctmp_c] -= loctmp_y[80 * loctmp_c +
            loctmp_j] * ANN_EKF_NMPC_2_B.A[80 * loctmp_j + loctmp_b_ix];
        }
      }
    }
  }

  ANN_EKF_NMPC_2_eml_xtrsm_c(ANN_EKF_NMPC_2_B.A, loctmp_y);
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_mpower(const real_T loctmp_a[6400], real_T loctmp_c
  [6400])
{
  ANN_EKF_NMPC_2_invNxN(loctmp_a, loctmp_c);
}

/* Function for MATLAB Function: '<S2>/Control System' */
static real_T ANN_EKF_NMPC_2_sum(const boolean_T loctmp_x[40])
{
  real_T loctmp_y;
  int32_T loctmp_k;
  loctmp_y = loctmp_x[0];
  for (loctmp_k = 0; loctmp_k < 39; loctmp_k++) {
    loctmp_y += (real_T)loctmp_x[loctmp_k + 1];
  }

  return loctmp_y;
}

/* Function for MATLAB Function: '<S2>/Control System' */
static real_T ANN_EKF_NMPC_2_sum_n(const boolean_T loctmp_x[20])
{
  real_T loctmp_y;
  int32_T loctmp_k;
  loctmp_y = loctmp_x[0];
  for (loctmp_k = 0; loctmp_k < 19; loctmp_k++) {
    loctmp_y += (real_T)loctmp_x[loctmp_k + 1];
  }

  return loctmp_y;
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_eml_ipiv2perm_g(const int32_T loctmp_ipiv_data[],
  const int32_T loctmp_ipiv_sizes[2], int32_T loctmp_m, int32_T
  loctmp_perm_data[], int32_T loctmp_perm_sizes[2])
{
  int32_T loctmp_pipk;
  int32_T loctmp_yk;
  loctmp_perm_sizes[0] = 1;
  loctmp_perm_sizes[1] = loctmp_m;
  loctmp_perm_data[0] = 1;
  loctmp_yk = 1;
  for (loctmp_pipk = 2; loctmp_pipk <= loctmp_m; loctmp_pipk++) {
    loctmp_yk++;
    loctmp_perm_data[loctmp_pipk - 1] = loctmp_yk;
  }

  for (loctmp_yk = 0; loctmp_yk < loctmp_ipiv_sizes[1]; loctmp_yk++) {
    if (loctmp_ipiv_data[loctmp_yk] > 1 + loctmp_yk) {
      loctmp_pipk = loctmp_perm_data[loctmp_ipiv_data[loctmp_yk] - 1];
      loctmp_perm_data[loctmp_ipiv_data[loctmp_yk] - 1] =
        loctmp_perm_data[loctmp_yk];
      loctmp_perm_data[loctmp_yk] = loctmp_pipk;
    }
  }
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_eml_xtrsm_cy(int32_T loctmp_m, int32_T loctmp_n,
  const real_T loctmp_A_data[], int32_T loctmp_lda, real_T loctmp_B_data[],
  int32_T loctmp_ldb)
{
  int32_T loctmp_jBcol;
  int32_T loctmp_kAcol;
  int32_T loctmp_j;
  int32_T loctmp_k;
  int32_T loctmp_i;
  for (loctmp_j = 1; loctmp_j <= loctmp_n; loctmp_j++) {
    loctmp_jBcol = (loctmp_j - 1) * loctmp_ldb;
    for (loctmp_k = loctmp_m - 1; loctmp_k + 1 > 0; loctmp_k--) {
      loctmp_kAcol = loctmp_lda * loctmp_k;
      if (loctmp_B_data[loctmp_k + loctmp_jBcol] != 0.0) {
        loctmp_B_data[loctmp_k + loctmp_jBcol] /= loctmp_A_data[loctmp_k +
          loctmp_kAcol];
        for (loctmp_i = 0; loctmp_i + 1 <= loctmp_k; loctmp_i++) {
          loctmp_B_data[loctmp_i + loctmp_jBcol] -= loctmp_B_data[loctmp_k +
            loctmp_jBcol] * loctmp_A_data[loctmp_i + loctmp_kAcol];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_eml_xswap_et(int32_T loctmp_n, real_T loctmp_x_data[],
  int32_T loctmp_ix0, int32_T loctmp_incx, int32_T loctmp_iy0, int32_T
  loctmp_incy)
{
  int32_T loctmp_ix;
  int32_T loctmp_iy;
  real_T loctmp_temp;
  int32_T loctmp_k;
  loctmp_ix = loctmp_ix0 - 1;
  loctmp_iy = loctmp_iy0 - 1;
  for (loctmp_k = 1; loctmp_k <= loctmp_n; loctmp_k++) {
    loctmp_temp = loctmp_x_data[loctmp_ix];
    loctmp_x_data[loctmp_ix] = loctmp_x_data[loctmp_iy];
    loctmp_x_data[loctmp_iy] = loctmp_temp;
    loctmp_ix += loctmp_incx;
    loctmp_iy += loctmp_incy;
  }
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_invNxN_h(const real_T loctmp_x_data[], const int32_T
  loctmp_x_sizes[2], real_T loctmp_y_data[], int32_T loctmp_y_sizes[2])
{
  int32_T loctmp_n;
  int32_T loctmp_i;
  int32_T loctmp_mmj;
  int32_T loctmp_b_j;
  int32_T loctmp_c_c;
  int32_T loctmp_yk;
  real_T loctmp_smax;
  real_T loctmp_s;
  int32_T loctmp_jy;
  int32_T loctmp_b_ix;
  int32_T loctmp_f;
  int32_T loctmp_ijA;
  int32_T loctmp_loop_ub;
  int32_T loctmp_p_data[120];
  int32_T loctmp_p_sizes[2];
  int32_T loctmp_A_sizes[2];
  int32_T loctmp_ipiv_data[120];
  int32_T loctmp_ipiv_sizes[2];
  int32_T loctmp_u0;
  loctmp_n = loctmp_x_sizes[0];
  loctmp_y_sizes[0] = loctmp_x_sizes[0];
  loctmp_y_sizes[1] = loctmp_x_sizes[1];
  loctmp_loop_ub = loctmp_x_sizes[0] * loctmp_x_sizes[1];
  for (loctmp_yk = 0; loctmp_yk < loctmp_loop_ub; loctmp_yk++) {
    loctmp_y_data[loctmp_yk] = 0.0;
  }

  loctmp_A_sizes[0] = loctmp_x_sizes[0];
  loctmp_A_sizes[1] = loctmp_x_sizes[1];
  loctmp_loop_ub = loctmp_x_sizes[0] * loctmp_x_sizes[1];
  for (loctmp_yk = 0; loctmp_yk < loctmp_loop_ub; loctmp_yk++) {
    ANN_EKF_NMPC_2_B.A_data[loctmp_yk] = loctmp_x_data[loctmp_yk];
  }

  loctmp_loop_ub = loctmp_x_sizes[0];
  loctmp_ipiv_sizes[0] = 1;
  loctmp_ipiv_sizes[1] = loctmp_loop_ub;
  loctmp_ipiv_data[0] = 1;
  loctmp_yk = 1;
  for (loctmp_jy = 2; loctmp_jy <= loctmp_loop_ub; loctmp_jy++) {
    loctmp_yk++;
    loctmp_ipiv_data[loctmp_jy - 1] = loctmp_yk;
  }

  loctmp_u0 = loctmp_x_sizes[0] - 1;
  if (!(loctmp_u0 <= loctmp_x_sizes[0])) {
    loctmp_u0 = loctmp_x_sizes[0];
  }

  for (loctmp_b_j = 1; loctmp_b_j <= loctmp_u0; loctmp_b_j++) {
    loctmp_mmj = (loctmp_n - loctmp_b_j) + 1;
    loctmp_c_c = (loctmp_b_j - 1) * (loctmp_n + 1);
    if (loctmp_mmj < 1) {
      loctmp_loop_ub = -1;
    } else {
      loctmp_loop_ub = 0;
      if (loctmp_mmj > 1) {
        loctmp_yk = loctmp_c_c;
        loctmp_smax = fabs(ANN_EKF_NMPC_2_B.A_data[loctmp_c_c]);
        for (loctmp_jy = 1; loctmp_jy + 1 <= loctmp_mmj; loctmp_jy++) {
          loctmp_yk++;
          loctmp_s = fabs(ANN_EKF_NMPC_2_B.A_data[loctmp_yk]);
          if (loctmp_s > loctmp_smax) {
            loctmp_loop_ub = loctmp_jy;
            loctmp_smax = loctmp_s;
          }
        }
      }
    }

    if (ANN_EKF_NMPC_2_B.A_data[loctmp_c_c + loctmp_loop_ub] != 0.0) {
      if (loctmp_loop_ub != 0) {
        loctmp_ipiv_data[loctmp_b_j - 1] = loctmp_b_j + loctmp_loop_ub;
        ANN_EKF_NMPC_2_eml_xswap_et(loctmp_n, ANN_EKF_NMPC_2_B.A_data,
          loctmp_b_j, loctmp_n, loctmp_b_j + loctmp_loop_ub, loctmp_n);
      }

      loctmp_loop_ub = loctmp_c_c + loctmp_mmj;
      for (loctmp_yk = loctmp_c_c + 1; loctmp_yk + 1 <= loctmp_loop_ub;
           loctmp_yk++) {
        ANN_EKF_NMPC_2_B.A_data[loctmp_yk] /= ANN_EKF_NMPC_2_B.A_data[loctmp_c_c];
      }
    }

    loctmp_loop_ub = loctmp_n - loctmp_b_j;
    loctmp_yk = loctmp_c_c + loctmp_n;
    loctmp_jy = loctmp_c_c + loctmp_n;
    for (loctmp_i = 1; loctmp_i <= loctmp_loop_ub; loctmp_i++) {
      loctmp_smax = ANN_EKF_NMPC_2_B.A_data[loctmp_jy];
      if (ANN_EKF_NMPC_2_B.A_data[loctmp_jy] != 0.0) {
        loctmp_b_ix = loctmp_c_c + 1;
        loctmp_f = loctmp_mmj + loctmp_yk;
        for (loctmp_ijA = 1 + loctmp_yk; loctmp_ijA + 1 <= loctmp_f; loctmp_ijA
             ++) {
          ANN_EKF_NMPC_2_B.A_data[loctmp_ijA] +=
            ANN_EKF_NMPC_2_B.A_data[loctmp_b_ix] * -loctmp_smax;
          loctmp_b_ix++;
        }
      }

      loctmp_jy += loctmp_n;
      loctmp_yk += loctmp_n;
    }
  }

  ANN_EKF_NMPC_2_eml_ipiv2perm_g(loctmp_ipiv_data, loctmp_ipiv_sizes,
    loctmp_x_sizes[0], loctmp_p_data, loctmp_p_sizes);
  for (loctmp_loop_ub = 0; loctmp_loop_ub + 1 <= loctmp_n; loctmp_loop_ub++) {
    loctmp_yk = loctmp_p_data[loctmp_loop_ub] - 1;
    loctmp_y_data[loctmp_loop_ub + loctmp_y_sizes[0] *
      (loctmp_p_data[loctmp_loop_ub] - 1)] = 1.0;
    for (loctmp_jy = loctmp_loop_ub; loctmp_jy + 1 <= loctmp_n; loctmp_jy++) {
      if (loctmp_y_data[loctmp_y_sizes[0] * loctmp_yk + loctmp_jy] != 0.0) {
        for (loctmp_i = loctmp_jy + 1; loctmp_i + 1 <= loctmp_n; loctmp_i++) {
          loctmp_y_data[loctmp_i + loctmp_y_sizes[0] * loctmp_yk] -=
            loctmp_y_data[loctmp_y_sizes[0] * loctmp_yk + loctmp_jy] *
            ANN_EKF_NMPC_2_B.A_data[loctmp_A_sizes[0] * loctmp_jy + loctmp_i];
        }
      }
    }
  }

  ANN_EKF_NMPC_2_eml_xtrsm_cy(loctmp_x_sizes[0], loctmp_x_sizes[0],
    ANN_EKF_NMPC_2_B.A_data, loctmp_x_sizes[0], loctmp_y_data, loctmp_x_sizes[0]);
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_mpower_k(const real_T loctmp_a_data[], const int32_T
  loctmp_a_sizes[2], real_T loctmp_c_data[], int32_T loctmp_c_sizes[2])
{
  ANN_EKF_NMPC_2_invNxN_h(loctmp_a_data, loctmp_a_sizes, loctmp_c_data,
    loctmp_c_sizes);
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_squeeze(const real_T loctmp_a[12], real_T loctmp_b_b
  [12])
{
  memcpy(&loctmp_b_b[0], &loctmp_a[0], 12U * sizeof(real_T));
}

real_T rt_roundd_snf(real_T loctmp_u)
{
  real_T loctmp_y;
  if (fabs(loctmp_u) < 4.503599627370496E+15) {
    if (loctmp_u >= 0.5) {
      loctmp_y = floor(loctmp_u + 0.5);
    } else if (loctmp_u > -0.5) {
      loctmp_y = loctmp_u * 0.0;
    } else {
      loctmp_y = ceil(loctmp_u - 0.5);
    }
  } else {
    loctmp_y = loctmp_u;
  }

  return loctmp_y;
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_uas_augm_model_ms(real_T loctmp_sw, boolean_T
  loctmp_home_cmd, real_T loctmp_b_dt, real_T loctmp_b_TR, uint8_T
  loctmp_wpts_fp, uint8_T loctmp_wpts_rp, real_T loctmp_wpts_h[32], real_T
  loctmp_wpts_n[32], real_T loctmp_wpts_e[32], const real_T loctmp_wpts_v[32],
  real_T loctmp_n_op_k, real_T loctmp_e_op_k, real_T loctmp_h_op_k, real_T
  loctmp_vn_op_k, real_T loctmp_ve_op_k, real_T loctmp_vh_op_k, real_T
  loctmp_alphadot_k, real_T loctmp_betadot_k, uint8_T loctmp_wpt_index_k, real_T
  loctmp_start_wpt_k[3], real_T loctmp_pic_cic_k, real_T loctmp_home_reset_k,
  real_T loctmp_THL_k, real_T loctmp_EL_k, real_T loctmp_AIL_k, real_T
  loctmp_RDR_k, real_T loctmp_VT_k, real_T loctmp_alpha_k, real_T loctmp_beta_k,
  real_T loctmp_phi_k, real_T loctmp_theta_k, real_T loctmp_psi_k, real_T
  loctmp_P_k, real_T loctmp_Q_k, real_T loctmp_R_k, real_T loctmp_n_k, real_T
  loctmp_e_k, real_T loctmp_h_k, real_T loctmp_ro_k, real_T loctmp_THLcmd_k,
  real_T loctmp_ELcmd_k, real_T loctmp_AILcmd_k, real_T loctmp_RDRcmd_k, real_T
  loctmp_xw11_k, real_T loctmp_xw12_k, real_T loctmp_xw13_k, real_T
  loctmp_xw14_k, real_T loctmp_xw21_k, real_T loctmp_xw22_k, real_T
  loctmp_xw23_k, real_T loctmp_xw24_k, real_T loctmp_xw31_k, real_T
  loctmp_xw32_k, real_T loctmp_xw33_k, real_T loctmp_xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W12d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W21d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W24d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W33d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W34d, real_T loctmp_b_rho, real_T
  loctmp_b_S, real_T loctmp_b_Cbar, real_T loctmp_b_b, real_T loctmp_b_weight,
  real_T loctmp_b_g, real_T loctmp_b_IxxB, real_T loctmp_b_IyyB, real_T
  loctmp_b_IzzB, real_T loctmp_b_IxzB, real_T loctmp_b_CDu, real_T loctmp_b_CDq,
  real_T loctmp_b_CDadot, real_T loctmp_b_CDde, real_T loctmp_b_CD0_bar, real_T
  loctmp_b_Cyb, real_T loctmp_b_Cyp, real_T loctmp_b_Cyr, real_T loctmp_b_Cyda,
  real_T loctmp_b_Cydr, real_T loctmp_b_CL0, real_T loctmp_b_CLa, real_T
  loctmp_b_CLq, real_T loctmp_b_CLadot, real_T loctmp_b_CLu, real_T
  loctmp_b_CLde, real_T loctmp_b_Clb, real_T loctmp_b_Clp, real_T loctmp_b_Clr,
  real_T loctmp_b_Clda, real_T loctmp_b_Cldr, real_T loctmp_b_Cm0, real_T
  loctmp_b_Cma, real_T loctmp_b_Cmq, real_T loctmp_b_Cmadot, real_T loctmp_b_Cmu,
  real_T loctmp_b_Cmde, real_T loctmp_b_Cnb, real_T loctmp_b_Cnp, real_T
  loctmp_b_Cnr, real_T loctmp_b_Cnda, real_T loctmp_b_Cndr, real_T loctmp_b_xT0,
  real_T loctmp_b_xT1, real_T loctmp_b_xT2, real_T loctmp_b_Ptrim, real_T
  loctmp_b_Qtrim, real_T loctmp_b_Rtrim, real_T loctmp_b_Utrim, real_T
  loctmp_b_Athrottle, real_T loctmp_b_Bthrottle, real_T loctmp_b_Aelevator,
  real_T loctmp_b_Belevator, real_T loctmp_b_Aaileron, real_T loctmp_b_Baileron,
  real_T loctmp_b_Arudder, real_T loctmp_b_Brudder, real_T loctmp_b_ThrottleMax,
  real_T loctmp_b_ThrottleMin, real_T loctmp_b_ElevatorMax, real_T
  loctmp_b_ElevatorMin, real_T loctmp_b_AileronMax, real_T loctmp_b_AileronMin,
  real_T loctmp_b_RudderMax, real_T loctmp_b_RudderMin, real_T loctmp_b_KpLat,
  real_T loctmp_b_KiLon, real_T loctmp_b_KpLon, real_T loctmp_b_L, real_T
  loctmp_b_dist2b, real_T loctmp_FL_ann, const real_T loctmp_a_ann_X[40], const
  real_T loctmp_b_ann_X[40], real_T loctmp_c_ann_X, const real_T loctmp_w_ann_X
  [280], const real_T loctmp_a_ann_Y[40], const real_T loctmp_b_ann_Y[40],
  real_T loctmp_c_ann_Y, const real_T loctmp_w_ann_Y[280], const real_T
  loctmp_a_ann_Z[40], const real_T loctmp_b_ann_Z[40], real_T loctmp_c_ann_Z,
  const real_T loctmp_w_ann_Z[280], const real_T loctmp_b_X_minXin[7], const
  real_T loctmp_b_X_maxXin[7], real_T loctmp_b_X_minYin, real_T
  loctmp_b_X_maxYin, real_T loctmp_b_X_minXout, real_T loctmp_b_X_maxXout,
  real_T loctmp_b_X_minYout, real_T loctmp_b_X_maxYout, const real_T
  loctmp_b_Y_minXin[7], const real_T loctmp_b_Y_maxXin[7], real_T
  loctmp_b_Y_minYin, real_T loctmp_b_Y_maxYin, real_T loctmp_b_Y_minXout, real_T
  loctmp_b_Y_maxXout, real_T loctmp_b_Y_minYout, real_T loctmp_b_Y_maxYout,
  const real_T loctmp_b_Z_minXin[7], const real_T loctmp_b_Z_maxXin[7], real_T
  loctmp_b_Z_minYin, real_T loctmp_b_Z_maxYin, real_T loctmp_b_Z_minXout, real_T
  loctmp_b_Z_maxXout, real_T loctmp_b_Z_minYout, real_T loctmp_b_Z_maxYout,
  real32_T *loctmp_distance2b, uint8_T *loctmp_wpt_index_kk, real_T
  *loctmp_pic_cic_kk, uint8_T *loctmp_home_reset_kk, real_T *loctmp_nr_k, real_T
  *loctmp_er_k, real_T *loctmp_hr_k, real_T *loctmp_etaLon_k, real_T
  *loctmp_etaLat_k, real_T *loctmp_VTcmd_k, real_T *loctmp_thetacmd_k, real_T
  *loctmp_phicmd_k, real_T *loctmp_Vab_k, real_T *loctmp_accelX_scd_k, real_T
  *loctmp_accelX_ann_k, real_T *loctmp_accelY_scd_k, real_T *loctmp_accelY_ann_k,
  real_T *loctmp_accelZ_scd_k, real_T *loctmp_accelZ_ann_k, real_T
  loctmp_z_augm_k[12], real_T loctmp_e_augm_k[4], real_T *loctmp_THL_kk, real_T *
  loctmp_EL_kk, real_T *loctmp_AIL_kk, real_T *loctmp_RDR_kk, real_T
  *loctmp_VT_kk, real_T *loctmp_alpha_kk, real_T *loctmp_beta_kk, real_T
  *loctmp_phi_kk, real_T *loctmp_theta_kk, real_T *loctmp_psi_kk, real_T
  *loctmp_P_kk, real_T *loctmp_Q_kk, real_T *loctmp_R_kk, real_T
  *loctmp_falpha_k, real_T *loctmp_fbeta_k, real_T *loctmp_n_kk, real_T
  *loctmp_e_kk, real_T *loctmp_h_kk, real_T *loctmp_ro_kk, real_T
  *loctmp_xw11_kk, real_T *loctmp_xw12_kk, real_T *loctmp_xw13_kk, real_T
  *loctmp_xw14_kk, real_T *loctmp_xw21_kk, real_T *loctmp_xw22_kk, real_T
  *loctmp_xw23_kk, real_T *loctmp_xw24_kk, real_T *loctmp_xw31_kk, real_T
  *loctmp_xw32_kk, real_T *loctmp_xw33_kk, real_T *loctmp_xw34_kk)
{
  real_T loctmp_mass;
  real_T loctmp_delta_I;
  real_T loctmp_c2;
  real_T loctmp_c4;
  real_T loctmp_Qbar_k;
  real_T loctmp_U_k;
  real_T loctmp_V_k;
  real_T loctmp_W_k;
  real_T loctmp_CL_k;
  real_T loctmp_CD_k;
  real_T loctmp_Cls_k;
  real_T loctmp_Cms_k;
  real_T loctmp_Cns_k;
  real_T loctmp_Cl_k;
  real_T loctmp_Cn_k;
  real_T loctmp_Udot_k;
  real_T loctmp_Vdot_k;
  real_T loctmp_Wdot_k;
  real_T loctmp_fn_k;
  real_T loctmp_fe_k;
  real_T loctmp_fh_k;
  uint8_T loctmp_next_wpt_index;
  real_T loctmp_ea;
  real_T loctmp_hd_k;
  real_T loctmp_nd_k;
  real_T loctmp_ed_k;
  real_T loctmp_atrack;
  int32_T loctmp_factor;
  real_T loctmp_btrack;
  real_T loctmp_edot_track_k;
  real_T loctmp_ndot_track_k;
  real_T loctmp_r_a;
  real_T loctmp_s_a;
  real_T loctmp_t_a;
  real_T loctmp_er_k_0[2];
  real_T loctmp_er_k_1[3];
  real_T loctmp_nr_k_0[2];
  real_T loctmp_fn_k_0[2];
  real_T loctmp_VT_k_0[7];
  real_T loctmp_VT_k_1[7];
  real_T loctmp_VT_k_2[7];
  real_T loctmp_tmp[7];
  real_T loctmp_w_ann_X_0[40];
  int32_T loctmp_i;

  /* %temporary */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %mass and inertia coefficients%% */
  loctmp_mass = loctmp_b_weight / loctmp_b_g;
  loctmp_delta_I = loctmp_b_IxxB * loctmp_b_IzzB - loctmp_b_IxzB * loctmp_b_IxzB;
  loctmp_c2 = ((loctmp_b_IxxB - loctmp_b_IyyB) + loctmp_b_IzzB) * loctmp_b_IxzB /
    loctmp_delta_I;
  loctmp_c4 = loctmp_b_IxzB / loctmp_delta_I;

  /* %dynamic pressure%% */
  loctmp_Qbar_k = 0.5 * loctmp_b_rho * (loctmp_VT_k * loctmp_VT_k);

  /* %body velocities%% */
  loctmp_U_k = loctmp_VT_k * cos(loctmp_alpha_k) * cos(loctmp_beta_k);
  loctmp_V_k = loctmp_VT_k * sin(loctmp_beta_k);
  loctmp_W_k = loctmp_VT_k * sin(loctmp_alpha_k) * cos(loctmp_beta_k);

  /* %aerodynamic coefficients%% */
  loctmp_CL_k = ((((loctmp_Q_k - loctmp_b_Qtrim) * loctmp_b_CLq * loctmp_b_Cbar /
                   2.0 / loctmp_b_Utrim + (loctmp_b_CLa * loctmp_alpha_k +
    loctmp_b_CL0)) + loctmp_b_CLadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                  loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) * loctmp_b_CLu
                 / loctmp_b_Utrim) + loctmp_b_CLde * loctmp_EL_k;

  /* CD_k=CD0+CDa*alpha_k+CDq*(Q_k-Qtrim)*Cbar/2/Utrim+CDadot*alphadot_k*Cbar/2/Utrim+CDu*(U_k-Utrim)/Utrim+CDde*EL_k; %lin */
  loctmp_CD_k = ((((loctmp_CL_k * loctmp_CL_k / (3.1415926535897931 * loctmp_b_b
    / loctmp_b_Cbar * 0.87) + loctmp_b_CD0_bar) + (loctmp_Q_k - loctmp_b_Qtrim) *
                   loctmp_b_CDq * loctmp_b_Cbar / 2.0 / loctmp_b_Utrim) +
                  loctmp_b_CDadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                  loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) * loctmp_b_CDu
                 / loctmp_b_Utrim) + loctmp_b_CDde * loctmp_EL_k;

  /* nonlin */
  loctmp_Cls_k = ((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Clp * loctmp_b_b /
                    2.0 / loctmp_b_Utrim + loctmp_b_Clb * loctmp_beta_k) +
                   (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Clr * loctmp_b_b /
                   2.0 / loctmp_b_Utrim) + loctmp_b_Clda * loctmp_AIL_k) +
    loctmp_b_Cldr * loctmp_RDR_k;
  loctmp_Cms_k = ((((loctmp_Q_k - loctmp_b_Qtrim) * loctmp_b_Cmq * loctmp_b_Cbar
                    / 2.0 / loctmp_b_Utrim + (loctmp_b_Cma * loctmp_alpha_k +
    loctmp_b_Cm0)) + loctmp_b_Cmadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                   loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) *
                  loctmp_b_Cmu / loctmp_b_Utrim) + loctmp_b_Cmde * loctmp_EL_k;
  loctmp_Cns_k = ((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Cnp * loctmp_b_b /
                    2.0 / loctmp_b_Utrim + loctmp_b_Cnb * loctmp_beta_k) +
                   (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Cnr * loctmp_b_b /
                   2.0 / loctmp_b_Utrim) + loctmp_b_Cnda * loctmp_AIL_k) +
    loctmp_b_Cndr * loctmp_RDR_k;
  loctmp_Cl_k = loctmp_Cls_k * cos(loctmp_alpha_k) - loctmp_Cns_k * sin
    (loctmp_alpha_k);
  loctmp_Cn_k = loctmp_Cls_k * sin(loctmp_alpha_k) + loctmp_Cns_k * cos
    (loctmp_alpha_k);

  /* %engine thrust%% */
  loctmp_Cls_k = 100.0 * loctmp_THL_k;

  /* %S&C aerodynamic and thrust linear accelerations%% */
  *loctmp_accelX_scd_k = (((loctmp_Cls_k * loctmp_Cls_k * loctmp_b_xT2 + 100.0 *
    loctmp_THL_k * loctmp_b_xT1) + loctmp_b_xT0) + (-loctmp_CD_k * cos
    (loctmp_alpha_k) + loctmp_CL_k * sin(loctmp_alpha_k)) * (loctmp_Qbar_k *
    loctmp_b_S)) / loctmp_mass;

  /* [ft/s2] */
  *loctmp_accelY_scd_k = (((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Cyp *
    loctmp_b_b / 2.0 / loctmp_b_Utrim + loctmp_b_Cyb * loctmp_beta_k) +
    (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Cyr * loctmp_b_b / 2.0 /
    loctmp_b_Utrim) + loctmp_b_Cyda * loctmp_AIL_k) + loctmp_b_Cydr *
    loctmp_RDR_k) * (loctmp_Qbar_k * loctmp_b_S) / loctmp_mass;

  /* [ft/s2] */
  *loctmp_accelZ_scd_k = (-loctmp_CD_k * sin(loctmp_alpha_k) - loctmp_CL_k * cos
                          (loctmp_alpha_k)) * (loctmp_Qbar_k * loctmp_b_S) /
    loctmp_mass;

  /* [ft/s2] */
  /* ANN linear accelerations */
  /* X-axis */
  loctmp_VT_k_2[0] = loctmp_VT_k;
  loctmp_VT_k_2[1] = loctmp_alpha_k;
  loctmp_VT_k_2[2] = loctmp_beta_k;
  loctmp_VT_k_2[3] = loctmp_Q_k;
  loctmp_VT_k_2[4] = loctmp_alphadot_k;
  loctmp_VT_k_2[5] = loctmp_THL_k;
  loctmp_VT_k_2[6] = loctmp_EL_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_2, loctmp_b_X_minXin, loctmp_b_X_maxXin,
    loctmp_b_X_minYin, loctmp_b_X_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_X[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_X[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_X[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelX_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_X,
    loctmp_b_X_minXout, loctmp_b_X_maxXout, loctmp_b_X_minYout,
    loctmp_b_X_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  /* Y_axis */
  loctmp_VT_k_1[0] = loctmp_VT_k;
  loctmp_VT_k_1[1] = loctmp_beta_k;
  loctmp_VT_k_1[2] = loctmp_P_k;
  loctmp_VT_k_1[3] = loctmp_R_k;
  loctmp_VT_k_1[4] = loctmp_betadot_k;
  loctmp_VT_k_1[5] = loctmp_AIL_k;
  loctmp_VT_k_1[6] = loctmp_RDR_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_1, loctmp_b_Y_minXin, loctmp_b_Y_maxXin,
    loctmp_b_Y_minYin, loctmp_b_Y_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_Y[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_Y[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_Y[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelY_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_Y,
    loctmp_b_Y_minXout, loctmp_b_Y_maxXout, loctmp_b_Y_minYout,
    loctmp_b_Y_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  /* Z-axis */
  loctmp_VT_k_0[0] = loctmp_VT_k;
  loctmp_VT_k_0[1] = loctmp_alpha_k;
  loctmp_VT_k_0[2] = loctmp_beta_k;
  loctmp_VT_k_0[3] = loctmp_Q_k;
  loctmp_VT_k_0[4] = loctmp_alphadot_k;
  loctmp_VT_k_0[5] = loctmp_THL_k;
  loctmp_VT_k_0[6] = loctmp_EL_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_0, loctmp_b_Z_minXin, loctmp_b_Z_maxXin,
    loctmp_b_Z_minYin, loctmp_b_Z_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_Z[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_Z[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_Z[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelZ_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_Z,
    loctmp_b_Z_minXout, loctmp_b_Z_maxXout, loctmp_b_Z_minYout,
    loctmp_b_Z_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  loctmp_Cls_k = 0.0;

  /* initialization */
  loctmp_Cns_k = 0.0;

  /* initialization */
  loctmp_mass = 0.0;

  /* initialization */
  if (loctmp_FL_ann == 0.0) {
    /* scd */
    loctmp_Cls_k = *loctmp_accelX_scd_k;
    loctmp_Cns_k = *loctmp_accelY_scd_k;
    loctmp_mass = *loctmp_accelZ_scd_k;
  } else {
    if (loctmp_FL_ann == 1.0) {
      /* ann */
      loctmp_Cls_k = *loctmp_accelX_ann_k;
      loctmp_Cns_k = *loctmp_accelY_ann_k;
      loctmp_mass = *loctmp_accelZ_ann_k;
    }
  }

  /* body accelerations */
  loctmp_Udot_k = ((loctmp_R_k * loctmp_V_k - loctmp_Q_k * loctmp_W_k) -
                   loctmp_b_g * sin(loctmp_theta_k)) + loctmp_Cls_k;
  loctmp_Vdot_k = ((loctmp_P_k * loctmp_W_k - loctmp_R_k * loctmp_U_k) +
                   loctmp_b_g * sin(loctmp_phi_k) * cos(loctmp_theta_k)) +
    loctmp_Cns_k;
  loctmp_Wdot_k = ((loctmp_Q_k * loctmp_U_k - loctmp_P_k * loctmp_V_k) +
                   loctmp_b_g * cos(loctmp_phi_k) * cos(loctmp_theta_k)) +
    loctmp_mass;

  /* %inertial speed (with no wind)%% */
  loctmp_fn_k = ((sin(loctmp_phi_k) * sin(loctmp_theta_k) * cos(loctmp_psi_k) -
                  cos(loctmp_phi_k) * sin(loctmp_psi_k)) * loctmp_V_k +
                 loctmp_U_k * cos(loctmp_theta_k) * cos(loctmp_psi_k)) + (cos
    (loctmp_phi_k) * sin(loctmp_theta_k) * cos(loctmp_psi_k) + sin(loctmp_phi_k)
    * sin(loctmp_psi_k)) * loctmp_W_k;
  loctmp_fe_k = ((sin(loctmp_phi_k) * sin(loctmp_theta_k) * sin(loctmp_psi_k) +
                  cos(loctmp_phi_k) * cos(loctmp_psi_k)) * loctmp_V_k +
                 loctmp_U_k * cos(loctmp_theta_k) * sin(loctmp_psi_k)) + (cos
    (loctmp_phi_k) * sin(loctmp_theta_k) * sin(loctmp_psi_k) - sin(loctmp_phi_k)
    * cos(loctmp_psi_k)) * loctmp_W_k;
  loctmp_fh_k = (loctmp_U_k * sin(loctmp_theta_k) - loctmp_V_k * sin
                 (loctmp_phi_k) * cos(loctmp_theta_k)) - loctmp_W_k * cos
    (loctmp_phi_k) * cos(loctmp_theta_k);

  /* %inertial speed%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Local variable assignment */
  *loctmp_wpt_index_kk = loctmp_wpt_index_k;
  loctmp_r_a = rt_roundd_snf(loctmp_home_reset_k);
  if (loctmp_r_a < 256.0) {
    if (loctmp_r_a >= 0.0) {
      *loctmp_home_reset_kk = (uint8_T)loctmp_r_a;
    } else {
      *loctmp_home_reset_kk = 0U;
    }
  } else {
    *loctmp_home_reset_kk = MAX_uint8_T;
  }

  /* PIC/CIC Transition Logic: */
  /*  On transition to CIC or PIC, set index = 0 and current position to  */
  /*  current waypoint; hold current waypoint. */
  if ((loctmp_sw > loctmp_pic_cic_k) || (loctmp_sw == 0.0)) {
    loctmp_start_wpt_k[0] = loctmp_h_k;
    loctmp_start_wpt_k[1] = loctmp_n_k;
    loctmp_start_wpt_k[2] = loctmp_e_k;
    *loctmp_wpt_index_kk = 0U;
    *loctmp_home_reset_kk = 0U;
  }

  /*  Change the waypoint index when home command */
  if ((loctmp_home_cmd == 1) && (loctmp_sw == 1.0) && (*loctmp_home_reset_kk ==
       0)) {
    *loctmp_wpt_index_kk = 23U;
    *loctmp_home_reset_kk = 1U;
  }

  /* OP trajectory generation */
  /* %reassigning the a and b waypoints */
  if ((loctmp_b_TR == 2.0) && (*loctmp_home_reset_kk == 0)) {
    *loctmp_wpt_index_kk = 1U;
    loctmp_wpts_n[loctmp_wpt_index_k - 1] = loctmp_n_op_k - 100.0 *
      loctmp_vn_op_k;
    loctmp_factor = (int32_T)(loctmp_wpt_index_k + 1U);
    if ((uint32_T)loctmp_factor > 255U) {
      loctmp_factor = 255;
    }

    loctmp_wpts_n[loctmp_factor - 1] = 100.0 * loctmp_vn_op_k + loctmp_n_op_k;
    loctmp_wpts_e[loctmp_wpt_index_k - 1] = loctmp_e_op_k - 100.0 *
      loctmp_ve_op_k;
    loctmp_factor = (int32_T)(loctmp_wpt_index_k + 1U);
    if ((uint32_T)loctmp_factor > 255U) {
      loctmp_factor = 255;
    }

    loctmp_wpts_e[loctmp_factor - 1] = 100.0 * loctmp_ve_op_k + loctmp_e_op_k;
    loctmp_wpts_h[loctmp_wpt_index_k - 1] = loctmp_h_op_k - 100.0 *
      loctmp_vh_op_k;
    loctmp_factor = (int32_T)(loctmp_wpt_index_k + 1U);
    if ((uint32_T)loctmp_factor > 255U) {
      loctmp_factor = 255;
    }

    loctmp_wpts_h[loctmp_factor - 1] = 100.0 * loctmp_vh_op_k + loctmp_h_op_k;
  }

  /* calculate the next waypoint index */
  loctmp_factor = (int32_T)(*loctmp_wpt_index_kk + 1U);
  if ((uint32_T)loctmp_factor > 255U) {
    loctmp_factor = 255;
  }

  loctmp_next_wpt_index = (uint8_T)loctmp_factor;

  /* beyond final point (fp), go to return point (rp) */
  if ((uint8_T)loctmp_factor > loctmp_wpts_fp) {
    loctmp_next_wpt_index = loctmp_wpts_rp;
  }

  /* calculate distance to next waypoint */
  loctmp_Cls_k = loctmp_n_k - loctmp_wpts_n[loctmp_next_wpt_index - 1];
  loctmp_Cns_k = loctmp_e_k - loctmp_wpts_e[loctmp_next_wpt_index - 1];
  loctmp_Cls_k = sqrt(loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k * loctmp_Cns_k);

  /* change to next waypoint if in range */
  if ((loctmp_Cls_k < loctmp_b_dist2b) && (loctmp_sw == 1.0)) {
    /*  Do not change index if sw=0 */
    *loctmp_wpt_index_kk = loctmp_next_wpt_index;
    if (loctmp_next_wpt_index == loctmp_wpts_fp) {
      loctmp_next_wpt_index = loctmp_wpts_rp;
    } else {
      loctmp_factor = (int32_T)(loctmp_next_wpt_index + 1U);
      if ((uint32_T)loctmp_factor > 255U) {
        loctmp_factor = 255;
      }

      loctmp_next_wpt_index = (uint8_T)loctmp_factor;
    }
  }

  /* function outputs */
  if ((*loctmp_wpt_index_kk == 0) || (*loctmp_wpt_index_kk == 23)) {
    /*  Assign the speed of the starting segment to the speed of the first */
    /*  waypoint */
    *loctmp_Vab_k = loctmp_wpts_v[0];
    loctmp_CL_k = loctmp_start_wpt_k[0];
    loctmp_CD_k = loctmp_start_wpt_k[1];
    loctmp_ea = loctmp_start_wpt_k[2];
  } else {
    *loctmp_Vab_k = loctmp_wpts_v[*loctmp_wpt_index_kk - 1];
    loctmp_CL_k = loctmp_wpts_h[*loctmp_wpt_index_kk - 1];
    loctmp_CD_k = loctmp_wpts_n[*loctmp_wpt_index_kk - 1];
    loctmp_ea = loctmp_wpts_e[*loctmp_wpt_index_kk - 1];
  }

  *loctmp_distance2b = (real32_T)loctmp_Cls_k;
  *loctmp_pic_cic_kk = loctmp_sw;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %reference point r%% */
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_Cls_k = (((loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) *
                   (loctmp_h_k - loctmp_CL_k) +
                   (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) *
                   (loctmp_n_k - loctmp_CD_k)) +
                  (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea) *
                  (loctmp_e_k - loctmp_ea)) / ((loctmp_Cls_k * loctmp_Cls_k +
    loctmp_Cns_k * loctmp_Cns_k) + loctmp_mass * loctmp_mass);
  loctmp_hd_k = (loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) *
    loctmp_Cls_k + loctmp_CL_k;
  loctmp_nd_k = (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) *
    loctmp_Cls_k + loctmp_CD_k;
  loctmp_ed_k = (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea) *
    loctmp_Cls_k + loctmp_ea;
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k;
  loctmp_Cls_k = loctmp_b_L / sqrt((loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_mass * loctmp_mass);
  *loctmp_er_k = (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k) *
    loctmp_Cls_k + loctmp_ed_k;
  *loctmp_nr_k = (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k) *
    loctmp_Cls_k + loctmp_nd_k;
  *loctmp_hr_k = (loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k) *
    loctmp_Cls_k + loctmp_hd_k;

  /* %alpha and beta track%% */
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_atrack = asin((loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) /
                       sqrt((loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_mass * loctmp_mass));
  loctmp_Cls_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_Cns_k = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_factor = 1;
  loctmp_mass = 0.0;
  if (!((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k > 0.0) &&
        (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea > 0.0))) {
    if ((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k > 0.0) &&
        (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea < 0.0)) {
      loctmp_mass = 3.1415926535897931;
      loctmp_factor = -1;
    } else {
      if ((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k < 0.0) &&
          (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea < 0.0)) {
        loctmp_mass = -3.1415926535897931;
        loctmp_factor = -1;
      }
    }
  }

  loctmp_btrack = asin((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) /
                       sqrt(loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k)) * (real_T)loctmp_factor + loctmp_mass;

  /* %edot, ndot and hdot relative to track%% */
  loctmp_edot_track_k = (sin(loctmp_atrack) * cos(loctmp_btrack) * loctmp_fh_k +
    sin(loctmp_btrack) * loctmp_fn_k) + cos(loctmp_atrack) * cos(loctmp_btrack) *
    loctmp_fe_k;
  loctmp_ndot_track_k = (-sin(loctmp_atrack) * sin(loctmp_btrack) * loctmp_fh_k
    + cos(loctmp_btrack) * loctmp_fn_k) - cos(loctmp_atrack) * sin(loctmp_btrack)
    * loctmp_fe_k;

  /* %er-e, nr-n and hr-h relative to track%% */
  /* %etaLon at time [k]%% */
  loctmp_nr_k_0[0] = *loctmp_nr_k - loctmp_n_k;
  loctmp_nr_k_0[1] = *loctmp_er_k - loctmp_e_k;
  loctmp_fn_k_0[0] = loctmp_fn_k;
  loctmp_fn_k_0[1] = loctmp_fe_k;
  *loctmp_etaLon_k = rt_atan2d_snf(*loctmp_hr_k - loctmp_h_k,
    ANN_EKF_NMPC_2_norm(loctmp_nr_k_0)) - rt_atan2d_snf(loctmp_fh_k,
    ANN_EKF_NMPC_2_norm(loctmp_fn_k_0));

  /* %etaLat at time [k]%% */
  loctmp_Cls_k = rt_atan2d_snf(loctmp_ndot_track_k, loctmp_edot_track_k) -
    rt_atan2d_snf((-sin(loctmp_atrack) * sin(loctmp_btrack) * (*loctmp_hr_k -
    loctmp_h_k) + (*loctmp_nr_k - loctmp_n_k) * cos(loctmp_btrack)) - cos
                  (loctmp_atrack) * sin(loctmp_btrack) * (*loctmp_er_k -
    loctmp_e_k), (sin(loctmp_atrack) * cos(loctmp_btrack) * (*loctmp_hr_k -
    loctmp_h_k) + (*loctmp_nr_k - loctmp_n_k) * sin(loctmp_btrack)) + cos
                  (loctmp_atrack) * cos(loctmp_btrack) * (*loctmp_er_k -
    loctmp_e_k));
  *loctmp_etaLat_k = loctmp_Cls_k;
  if (loctmp_Cls_k > 3.1415926535897931) {
    *loctmp_etaLat_k = loctmp_Cls_k - 6.2831853071795862;
  }

  if (loctmp_Cls_k < -3.1415926535897931) {
    *loctmp_etaLat_k = loctmp_Cls_k + 6.2831853071795862;
  }

  /* OP trajectory generation */
  /* reassigning Vab (based on the new d point) */
  if (loctmp_b_TR == 2.0) {
    loctmp_CL_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_n_op_k;
    loctmp_CD_k = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_e_op_k;
    loctmp_ea = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_h_op_k;
    loctmp_r_a = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k;
    loctmp_s_a = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k;
    loctmp_t_a = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k;
    loctmp_mass = loctmp_nd_k - loctmp_n_op_k;
    loctmp_Cns_k = loctmp_ed_k - loctmp_e_op_k;
    loctmp_Cls_k = loctmp_hd_k - loctmp_h_op_k;
    loctmp_r_a = sqrt((loctmp_CL_k * loctmp_CL_k + loctmp_CD_k * loctmp_CD_k) +
                      loctmp_ea * loctmp_ea) - sqrt((loctmp_r_a * loctmp_r_a +
      loctmp_s_a * loctmp_s_a) + loctmp_t_a * loctmp_t_a);
    if (loctmp_r_a < 0.0) {
      loctmp_r_a = -1.0;
    } else if (loctmp_r_a > 0.0) {
      loctmp_r_a = 1.0;
    } else {
      if (loctmp_r_a == 0.0) {
        loctmp_r_a = 0.0;
      }
    }

    *loctmp_Vab_k = sqrt((loctmp_vn_op_k * loctmp_vn_op_k + loctmp_ve_op_k *
                          loctmp_ve_op_k) + loctmp_vh_op_k * loctmp_vh_op_k) -
      atan(sqrt((loctmp_mass * loctmp_mass + loctmp_Cns_k * loctmp_Cns_k) +
                loctmp_Cls_k * loctmp_Cls_k) * loctmp_r_a / 100.0) *
      0.063661977236758135;

    /* (168.78) (5) (/100) */
  }

  /* %VT theta phi and beta command%% */
  /* %consider wind in VTcmd [0]: no [1]:yes */
  loctmp_mass = *loctmp_Vab_k * cos(loctmp_atrack) * sin(loctmp_btrack) + 0.0 *
    loctmp_sw;
  loctmp_Cns_k = *loctmp_Vab_k * cos(loctmp_atrack) * cos(loctmp_btrack) + 0.0 *
    loctmp_sw;
  loctmp_Cls_k = *loctmp_Vab_k * sin(loctmp_atrack) + 0.0 * loctmp_sw;
  *loctmp_VTcmd_k = sqrt((loctmp_mass * loctmp_mass + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_Cls_k * loctmp_Cls_k);
  loctmp_Cls_k = atan(*loctmp_etaLon_k * loctmp_sw);
  loctmp_er_k_1[0] = *loctmp_er_k - loctmp_e_k;
  loctmp_er_k_1[1] = *loctmp_nr_k - loctmp_n_k;
  loctmp_er_k_1[2] = *loctmp_hr_k - loctmp_h_k;
  *loctmp_thetacmd_k = rt_atan2d_snf(((loctmp_fe_k * loctmp_fe_k + loctmp_fn_k *
    loctmp_fn_k) + loctmp_fh_k * loctmp_fh_k) * 2.0 * (loctmp_Cls_k *
    loctmp_b_KpLon + loctmp_ro_k), ANN_EKF_NMPC_2_norm_h(loctmp_er_k_1));
  loctmp_er_k_0[0] = *loctmp_er_k - loctmp_e_k;
  loctmp_er_k_0[1] = *loctmp_nr_k - loctmp_n_k;
  *loctmp_phicmd_k = rt_atan2d_snf((loctmp_edot_track_k * loctmp_edot_track_k +
    loctmp_ndot_track_k * loctmp_ndot_track_k) * 2.0 * loctmp_b_KpLat *
    loctmp_sw * *loctmp_etaLat_k, ANN_EKF_NMPC_2_norm(loctmp_er_k_0));

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%implementing saturation of actuators%% */
  /* %deflection max and min */
  if (loctmp_THL_k > loctmp_b_ThrottleMax) {
    loctmp_THL_k = loctmp_b_ThrottleMax;
  } else {
    if (loctmp_THL_k < loctmp_b_ThrottleMin) {
      loctmp_THL_k = loctmp_b_ThrottleMin;
    }
  }

  if (loctmp_EL_k > loctmp_b_ElevatorMax) {
    loctmp_EL_k = loctmp_b_ElevatorMax;
  } else {
    if (loctmp_EL_k < loctmp_b_ElevatorMin) {
      loctmp_EL_k = loctmp_b_ElevatorMin;
    }
  }

  if (loctmp_AIL_k > loctmp_b_AileronMax) {
    loctmp_AIL_k = loctmp_b_AileronMax;
  } else {
    if (loctmp_AIL_k < loctmp_b_AileronMin) {
      loctmp_AIL_k = loctmp_b_AileronMin;
    }
  }

  if (loctmp_RDR_k > loctmp_b_RudderMax) {
    loctmp_RDR_k = loctmp_b_RudderMax;
  } else {
    if (loctmp_RDR_k < loctmp_b_RudderMin) {
      loctmp_RDR_k = loctmp_b_RudderMin;
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %longitudinal guidance integrator */
  *loctmp_ro_kk = loctmp_b_dt * loctmp_Cls_k * loctmp_b_KiLon + loctmp_ro_k;

  /* %servos prediction%% */
  *loctmp_THL_kk = (loctmp_b_Athrottle * loctmp_THL_k + loctmp_b_Bthrottle *
                    loctmp_THLcmd_k) * loctmp_b_dt + loctmp_THL_k;
  *loctmp_EL_kk = (loctmp_b_Aelevator * loctmp_EL_k + loctmp_b_Belevator *
                   loctmp_ELcmd_k) * loctmp_b_dt + loctmp_EL_k;
  *loctmp_AIL_kk = (loctmp_b_Aaileron * loctmp_AIL_k + loctmp_b_Baileron *
                    loctmp_AILcmd_k) * loctmp_b_dt + loctmp_AIL_k;
  *loctmp_RDR_kk = (loctmp_b_Arudder * loctmp_RDR_k + loctmp_b_Brudder *
                    loctmp_RDRcmd_k) * loctmp_b_dt + loctmp_RDR_k;

  /* %UAV prediction%% */
  loctmp_Cls_k = ((loctmp_U_k * loctmp_Udot_k + loctmp_V_k * loctmp_Vdot_k) +
                  loctmp_W_k * loctmp_Wdot_k) / loctmp_VT_k;
  *loctmp_falpha_k = (loctmp_U_k * loctmp_Wdot_k - loctmp_W_k * loctmp_Udot_k) /
    (loctmp_U_k * loctmp_U_k + loctmp_W_k * loctmp_W_k);
  *loctmp_fbeta_k = (loctmp_VT_k * loctmp_Vdot_k - loctmp_V_k * loctmp_Cls_k) /
    (loctmp_U_k * loctmp_U_k + loctmp_W_k * loctmp_W_k) * cos(loctmp_beta_k);
  *loctmp_VT_kk = loctmp_b_dt * loctmp_Cls_k + loctmp_VT_k;
  *loctmp_alpha_kk = loctmp_b_dt * *loctmp_falpha_k + loctmp_alpha_k;
  *loctmp_beta_kk = loctmp_b_dt * *loctmp_fbeta_k + loctmp_beta_k;
  *loctmp_phi_kk = ((loctmp_R_k * cos(loctmp_phi_k) + loctmp_Q_k * sin
                     (loctmp_phi_k)) * tan(loctmp_theta_k) + loctmp_P_k) *
    loctmp_b_dt + loctmp_phi_k;
  *loctmp_theta_kk = (loctmp_Q_k * cos(loctmp_phi_k) - loctmp_R_k * sin
                      (loctmp_phi_k)) * loctmp_b_dt + loctmp_theta_k;
  *loctmp_psi_kk = (loctmp_R_k * cos(loctmp_phi_k) + loctmp_Q_k * sin
                    (loctmp_phi_k)) / cos(loctmp_theta_k) * loctmp_b_dt +
    loctmp_psi_k;
  *loctmp_P_kk = ((((loctmp_b_IyyB - loctmp_b_IzzB) * loctmp_b_IzzB -
                    loctmp_b_IxzB * loctmp_b_IxzB) / loctmp_delta_I * loctmp_R_k
                   + loctmp_c2 * loctmp_P_k) * loctmp_Q_k + (loctmp_b_IzzB /
    loctmp_delta_I * loctmp_Cl_k + loctmp_c4 * loctmp_Cn_k) * (loctmp_Qbar_k *
    loctmp_b_S * loctmp_b_b)) * loctmp_b_dt + loctmp_P_k;
  *loctmp_Q_kk = (((loctmp_b_IzzB - loctmp_b_IxxB) / loctmp_b_IyyB * loctmp_P_k *
                   loctmp_R_k - (loctmp_P_k * loctmp_P_k - loctmp_R_k *
    loctmp_R_k) * (loctmp_b_IxzB / loctmp_b_IyyB)) + loctmp_Qbar_k * loctmp_b_S *
                  loctmp_b_Cbar * (1.0 / loctmp_b_IyyB) * loctmp_Cms_k) *
    loctmp_b_dt + loctmp_Q_k;
  *loctmp_R_kk = ((((loctmp_b_IxxB - loctmp_b_IyyB) * loctmp_b_IxxB +
                    loctmp_b_IxzB * loctmp_b_IxzB) / loctmp_delta_I * loctmp_P_k
                   - loctmp_c2 * loctmp_R_k) * loctmp_Q_k + (loctmp_b_IxxB /
    loctmp_delta_I * loctmp_Cn_k + loctmp_c4 * loctmp_Cl_k) * (loctmp_Qbar_k *
    loctmp_b_S * loctmp_b_b)) * loctmp_b_dt + loctmp_R_k;

  /* %inertial frame prediction%% */
  *loctmp_n_kk = loctmp_b_dt * loctmp_fn_k + loctmp_n_k;
  *loctmp_e_kk = loctmp_b_dt * loctmp_fe_k + loctmp_e_k;
  *loctmp_h_kk = loctmp_b_dt * loctmp_fh_k + loctmp_h_k;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %outputs e, y and z%% */
  loctmp_e_augm_k[0] = *loctmp_VTcmd_k - loctmp_VT_k;
  loctmp_e_augm_k[1] = *loctmp_thetacmd_k - loctmp_theta_k;
  loctmp_e_augm_k[2] = *loctmp_phicmd_k - loctmp_phi_k;
  loctmp_e_augm_k[3] = 0.0 - loctmp_beta_k;

  /* %Robustness states at [k+1]%% */
  *loctmp_xw11_kk = loctmp_b_W11d.a * loctmp_xw11_k + loctmp_b_W11d.b *
    loctmp_e_augm_k[0];

  /* W11 e_VT */
  *loctmp_xw12_kk = loctmp_b_W12d.a * loctmp_xw12_k + loctmp_b_W12d.b *
    loctmp_e_augm_k[1];

  /* W12 e_theta */
  *loctmp_xw13_kk = loctmp_b_W13d.a * loctmp_xw13_k + loctmp_b_W13d.b *
    loctmp_e_augm_k[2];

  /* W13 e_phi */
  *loctmp_xw14_kk = (0.0 - loctmp_beta_k) * loctmp_b_W14d.b + loctmp_b_W14d.a *
    loctmp_xw14_k;

  /* W14 e_beta */
  *loctmp_xw21_kk = loctmp_b_W21d.a * loctmp_xw21_k + loctmp_b_W21d.b *
    loctmp_THLcmd_k;

  /* W21 Throttle cmd */
  *loctmp_xw22_kk = loctmp_b_W22d.a * loctmp_xw22_k + loctmp_b_W22d.b *
    loctmp_ELcmd_k;

  /* W22 Elevator cmd */
  *loctmp_xw23_kk = loctmp_b_W23d.a * loctmp_xw23_k + loctmp_b_W23d.b *
    loctmp_AILcmd_k;

  /* W23 Aileron cmd */
  *loctmp_xw24_kk = loctmp_b_W24d.a * loctmp_xw24_k + loctmp_b_W24d.b *
    loctmp_RDRcmd_k;

  /* W24 Rudder cmd */
  *loctmp_xw31_kk = loctmp_b_W31d.a * loctmp_xw31_k + loctmp_b_W31d.b *
    loctmp_VT_k;

  /* W31 VT */
  *loctmp_xw32_kk = loctmp_b_W32d.a * loctmp_xw32_k + loctmp_b_W32d.b *
    loctmp_theta_k;

  /* W32 theta */
  *loctmp_xw33_kk = loctmp_b_W33d.a * loctmp_xw33_k + loctmp_b_W33d.b *
    loctmp_phi_k;

  /* W33 phi */
  *loctmp_xw34_kk = loctmp_b_W34d.a * loctmp_xw34_k + loctmp_b_W34d.b *
    loctmp_beta_k;

  /* W34 beta */
  /* %Robustness output at [k] */
  loctmp_z_augm_k[0] = loctmp_b_W11d.c * loctmp_xw11_k + loctmp_b_W11d.d *
    loctmp_e_augm_k[0];

  /* W11 e_VT */
  loctmp_z_augm_k[1] = loctmp_b_W12d.c * loctmp_xw12_k + loctmp_b_W12d.d *
    loctmp_e_augm_k[1];

  /* W12 e_theta */
  loctmp_z_augm_k[2] = loctmp_b_W13d.c * loctmp_xw13_k + loctmp_b_W13d.d *
    loctmp_e_augm_k[2];

  /* W13 e_phi */
  loctmp_z_augm_k[3] = (0.0 - loctmp_beta_k) * loctmp_b_W14d.d + loctmp_b_W14d.c
    * loctmp_xw14_k;

  /* W14 e_beta */
  loctmp_z_augm_k[4] = loctmp_b_W21d.c * loctmp_xw21_k + loctmp_b_W21d.d *
    loctmp_THLcmd_k;

  /* W21 Throttle cmd */
  loctmp_z_augm_k[5] = loctmp_b_W22d.c * loctmp_xw22_k + loctmp_b_W22d.d *
    loctmp_ELcmd_k;

  /* W22 Elevator cmd */
  loctmp_z_augm_k[6] = loctmp_b_W23d.c * loctmp_xw23_k + loctmp_b_W23d.d *
    loctmp_AILcmd_k;

  /* W23 Aileron cmd */
  loctmp_z_augm_k[7] = loctmp_b_W24d.c * loctmp_xw24_k + loctmp_b_W24d.d *
    loctmp_RDRcmd_k;

  /* W24 Rudder cmd */
  loctmp_z_augm_k[8] = loctmp_b_W31d.c * loctmp_xw31_k + loctmp_b_W31d.d *
    loctmp_VT_k;

  /* W31 VT */
  loctmp_z_augm_k[9] = loctmp_b_W32d.c * loctmp_xw32_k + loctmp_b_W32d.d *
    loctmp_theta_k;

  /* W32 theta */
  loctmp_z_augm_k[10] = loctmp_b_W33d.c * loctmp_xw33_k + loctmp_b_W33d.d *
    loctmp_phi_k;

  /* W33 phi */
  loctmp_z_augm_k[11] = loctmp_b_W34d.c * loctmp_xw34_k + loctmp_b_W34d.d *
    loctmp_beta_k;

  /* W34 beta */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_nmpc_iteration(real_T loctmp_sw, boolean_T
  loctmp_home_cmd, real_T loctmp_b_dt, real_T loctmp_b_TR, uint8_T
  loctmp_wpts_fp, uint8_T loctmp_wpts_rp, const real_T loctmp_wpts_h[32], const
  real_T loctmp_wpts_n[32], const real_T loctmp_wpts_e[32], const real_T
  loctmp_wpts_v[32], const real_T loctmp_n_op_N[21], const real_T loctmp_e_op_N
  [21], const real_T loctmp_h_op_N[21], const real_T loctmp_vn_op_N[21], const
  real_T loctmp_ve_op_N[21], const real_T loctmp_vh_op_N[21], const real_T
  loctmp_u_hor[84], const real_T loctmp_z_hor[252], const real_T loctmp_n_hor[21],
  const real_T loctmp_e_hor[21], const real_T loctmp_h_hor[21], const real_T
  loctmp_THL_hor[21], const real_T loctmp_EL_hor[21], const real_T
  loctmp_AIL_hor[21], const real_T loctmp_RDR_hor[21], const real_T
  loctmp_VT_hor[21], const real_T loctmp_alpha_hor[21], const real_T
  loctmp_beta_hor[21], const real_T loctmp_phi_hor[21], const real_T
  loctmp_theta_hor[21], const real_T loctmp_psi_hor[21], const real_T
  loctmp_P_hor[21], const real_T loctmp_Q_hor[21], const real_T loctmp_R_hor[21],
  const real_T loctmp_wpt_index_hor[21], const real_T loctmp_start_wpt_hor[63],
  const real_T loctmp_pic_cic_hor[21], const real_T loctmp_home_reset_hor[21],
  const real_T loctmp_alphadot_hor[21], const real_T loctmp_betadot_hor[21],
  const real_T loctmp_ro_hor[21], const real_T loctmp_xw11_hor[21], const real_T
  loctmp_xw12_hor[21], const real_T loctmp_xw13_hor[21], const real_T
  loctmp_xw14_hor[21], const real_T loctmp_xw21_hor[21], const real_T
  loctmp_xw22_hor[21], const real_T loctmp_xw23_hor[21], const real_T
  loctmp_xw24_hor[21], const real_T loctmp_xw31_hor[21], const real_T
  loctmp_xw32_hor[21], const real_T loctmp_xw33_hor[21], const real_T
  loctmp_xw34_hor[21], const struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W12d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W21d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W24d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W33d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W34d, real_T loctmp_b_rho, real_T
  loctmp_b_S, real_T loctmp_b_Cbar, real_T loctmp_b_b, real_T loctmp_b_weight,
  real_T loctmp_b_g, real_T loctmp_b_IxxB, real_T loctmp_b_IyyB, real_T
  loctmp_b_IzzB, real_T loctmp_b_IxzB, real_T loctmp_b_CDu, real_T loctmp_b_CDq,
  real_T loctmp_b_CDadot, real_T loctmp_b_CDde, real_T loctmp_b_CD0_bar, real_T
  loctmp_b_Cyb, real_T loctmp_b_Cyp, real_T loctmp_b_Cyr, real_T loctmp_b_Cyda,
  real_T loctmp_b_Cydr, real_T loctmp_b_CL0, real_T loctmp_b_CLa, real_T
  loctmp_b_CLq, real_T loctmp_b_CLadot, real_T loctmp_b_CLu, real_T
  loctmp_b_CLde, real_T loctmp_b_Clb, real_T loctmp_b_Clp, real_T loctmp_b_Clr,
  real_T loctmp_b_Clda, real_T loctmp_b_Cldr, real_T loctmp_b_Cm0, real_T
  loctmp_b_Cma, real_T loctmp_b_Cmq, real_T loctmp_b_Cmadot, real_T loctmp_b_Cmu,
  real_T loctmp_b_Cmde, real_T loctmp_b_Cnb, real_T loctmp_b_Cnp, real_T
  loctmp_b_Cnr, real_T loctmp_b_Cnda, real_T loctmp_b_Cndr, real_T loctmp_b_xT0,
  real_T loctmp_b_xT1, real_T loctmp_b_xT2, real_T loctmp_b_Ptrim, real_T
  loctmp_b_Qtrim, real_T loctmp_b_Rtrim, real_T loctmp_b_Utrim, real_T
  loctmp_b_Athrottle, real_T loctmp_b_Bthrottle, real_T loctmp_b_Aelevator,
  real_T loctmp_b_Belevator, real_T loctmp_b_Aaileron, real_T loctmp_b_Baileron,
  real_T loctmp_b_Arudder, real_T loctmp_b_Brudder, real_T loctmp_b_ThrottleMax,
  real_T loctmp_b_ThrottleMin, real_T loctmp_b_ElevatorMax, real_T
  loctmp_b_ElevatorMin, real_T loctmp_b_AileronMax, real_T loctmp_b_AileronMin,
  real_T loctmp_b_RudderMax, real_T loctmp_b_RudderMin, real_T loctmp_b_KpLat,
  real_T loctmp_b_KiLon, real_T loctmp_b_KpLon, real_T loctmp_b_L, real_T
  loctmp_b_dist2b, real_T loctmp_FL_ann, const real_T loctmp_a_ann_X[40], const
  real_T loctmp_b_ann_X[40], real_T loctmp_c_ann_X, const real_T loctmp_w_ann_X
  [280], const real_T loctmp_a_ann_Y[40], const real_T loctmp_b_ann_Y[40],
  real_T loctmp_c_ann_Y, const real_T loctmp_w_ann_Y[280], const real_T
  loctmp_a_ann_Z[40], const real_T loctmp_b_ann_Z[40], real_T loctmp_c_ann_Z,
  const real_T loctmp_w_ann_Z[280], const real_T loctmp_b_X_minXin[7], const
  real_T loctmp_b_X_maxXin[7], real_T loctmp_b_X_minYin, real_T
  loctmp_b_X_maxYin, real_T loctmp_b_X_minXout, real_T loctmp_b_X_maxXout,
  real_T loctmp_b_X_minYout, real_T loctmp_b_X_maxYout, const real_T
  loctmp_b_Y_minXin[7], const real_T loctmp_b_Y_maxXin[7], real_T
  loctmp_b_Y_minYin, real_T loctmp_b_Y_maxYin, real_T loctmp_b_Y_minXout, real_T
  loctmp_b_Y_maxXout, real_T loctmp_b_Y_minYout, real_T loctmp_b_Y_maxYout,
  const real_T loctmp_b_Z_minXin[7], const real_T loctmp_b_Z_maxXin[7], real_T
  loctmp_b_Z_minYin, real_T loctmp_b_Z_maxYin, real_T loctmp_b_Z_minXout, real_T
  loctmp_b_Z_maxXout, real_T loctmp_b_Z_minYout, real_T loctmp_b_Z_maxYout,
  real_T loctmp_u_nmpc[84], real_T *loctmp_V_nmpc)
{
  real_T loctmp_v_nmpc[480];
  real_T loctmp_gradV_nmpc[80];
  real_T loctmp_deltaV_nmpc[80];
  real_T loctmp_u_nmpc_temp[80];
  real_T loctmp_RDR_k;
  real_T loctmp_VT_k;
  real_T loctmp_alpha_k;
  real_T loctmp_beta_k;
  real_T loctmp_phi_k;
  real_T loctmp_theta_k;
  real_T loctmp_psi_k;
  real_T loctmp_P_k;
  real_T loctmp_Q_k;
  real_T loctmp_R_k;
  real_T loctmp_n_k;
  real_T loctmp_e_k;
  real_T loctmp_h_k;
  real_T loctmp_ro_k;
  real_T loctmp_alphadot_k;
  real_T loctmp_betadot_k;
  real_T loctmp_xw11_k;
  real_T loctmp_xw12_k;
  real_T loctmp_xw13_k;
  real_T loctmp_xw14_k;
  real_T loctmp_xw21_k;
  real_T loctmp_xw22_k;
  real_T loctmp_xw23_k;
  real_T loctmp_xw24_k;
  real_T loctmp_xw31_k;
  real_T loctmp_xw32_k;
  real_T loctmp_xw33_k;
  real_T loctmp_xw34_k;
  real_T loctmp_z_k[12];
  int8_T loctmp_constrMIN_ext[80];
  int8_T loctmp_constrMAX_ext[80];
  boolean_T loctmp_constrMIN[20];
  boolean_T loctmp_constrMAX[20];
  real_T loctmp_pMIN;
  real_T loctmp_pMAX;
  real_T loctmp_p_nmpc;
  real32_T loctmp_unusedU2;
  uint8_T loctmp_unusedU3;
  real_T loctmp_unusedU4[3];
  real_T loctmp_unusedU5;
  uint8_T loctmp_unusedU6;
  real_T loctmp_unusedU7;
  real_T loctmp_unusedU8;
  real_T loctmp_unusedU9;
  real_T loctmp_unusedUa;
  real_T loctmp_unusedUb;
  real_T loctmp_unusedUc;
  real_T loctmp_unusedUd;
  real_T loctmp_unusedUe;
  real_T loctmp_unusedU10;
  real_T loctmp_unusedU11;
  real_T loctmp_unusedU12;
  real_T loctmp_unusedU13;
  real_T loctmp_unusedU14;
  real_T loctmp_unusedU15;
  real_T loctmp_unusedU16;
  real_T loctmp_unusedU17[4];
  real_T loctmp_THL_kk;
  real_T loctmp_EL_kk;
  real_T loctmp_AIL_kk;
  real_T loctmp_RDR_kk;
  real_T loctmp_VT_kk;
  real_T loctmp_alpha_kk;
  real_T loctmp_beta_kk;
  real_T loctmp_phi_kk;
  real_T loctmp_theta_kk;
  real_T loctmp_psi_kk;
  real_T loctmp_P_kk;
  real_T loctmp_Q_kk;
  real_T loctmp_R_kk;
  real_T loctmp_falpha_k;
  real_T loctmp_fbeta_k;
  real_T loctmp_n_kk;
  real_T loctmp_e_kk;
  real_T loctmp_h_kk;
  real_T loctmp_ro_kk;
  real_T loctmp_xw11_kk;
  real_T loctmp_xw12_kk;
  real_T loctmp_xw13_kk;
  real_T loctmp_xw14_kk;
  real_T loctmp_xw21_kk;
  real_T loctmp_xw22_kk;
  real_T loctmp_xw23_kk;
  real_T loctmp_xw24_kk;
  real_T loctmp_xw31_kk;
  real_T loctmp_xw32_kk;
  real_T loctmp_xw33_kk;
  real_T loctmp_xw34_kk;
  int32_T loctmp_y;
  int32_T loctmp_ab;
  int32_T loctmp_idx;
  int32_T loctmp_b_k;
  int32_T loctmp_b_m;
  int32_T loctmp_ia;
  static const int8_T loctmp_c_a[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1 };

  static const int16_T loctmp_d_a[144] = { 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000 };

  boolean_T loctmp_exitg4;
  boolean_T loctmp_guard1;
  boolean_T loctmp_u_nmpc_temp_0[40];
  real_T loctmp_wpts_h_0[32];
  real_T loctmp_wpts_n_0[32];
  real_T loctmp_wpts_e_0[32];
  int32_T loctmp_i;
  real_T loctmp_tmp[12];
  int8_T loctmp_lambda_indexMIN_ext_data[80];
  int8_T loctmp_lambda_indexMAX_ext_data[80];
  real_T loctmp_gradL_nmpc_data[120];
  real_T loctmp_deltaL_nmpc_data[120];
  int16_T loctmp_db_data[240];
  int32_T loctmp_b_a_sizes[2];
  int8_T loctmp_ii_data[20];
  int8_T loctmp_c_ii_data[20];
  int8_T loctmp_e_ii_data[80];
  int32_T loctmp_hessianL_nmpc_sizes[2];
  int32_T loctmp_idx_data[120];
  int32_T loctmp_ii_sizes_idx_1;
  int32_T loctmp_c_ii_sizes_idx_1;
  int32_T loctmp_e_ii_sizes_idx_1;
  int32_T loctmp_lambda_indexMIN_ext_sizes_idx_1;
  uint8_T loctmp_tmp_0;
  int32_T exitg1;

  /* %embedded definitions - by assuming p_nmpc=2*N_nmpc we have: */
  memset(&ANN_EKF_NMPC_2_B.A_c[0], 0, 3200U * sizeof(real_T));

  /* [2*N_nmpc,nu*N_nmpc] */
  memset(&ANN_EKF_NMPC_2_B.hessianL_nmpc[0], 0, 14400U * sizeof(real_T));

  /* [nu*N_nmpc+2*N_nmpc,nu*N_nmpc+2*N_nmpc] */
  /* %NMPC numerical perturbation */
  /* 0.001 */
  /* %%%mpc variable allocation%% */
  /*  Rs_nmpc=zeros(1,nu*N_nmpc); */
  memset(&loctmp_u_nmpc[0], 0, 84U * sizeof(real_T));
  memset(&ANN_EKF_NMPC_2_B.z_it_nmpc[0], 0, 20160U * sizeof(real_T));

  /* v_nmpc=zeros(nz*N_nmpc+nu*N_nmpc,2); */
  memset(&loctmp_v_nmpc[0], 0, 480U * sizeof(real_T));

  /* J_nmpc=zeros(nz*N_nmpc+nu*N_nmpc,nu*N_nmpc); */
  memset(&ANN_EKF_NMPC_2_B.J_nmpc[0], 0, 19200U * sizeof(real_T));

  /* %local assignation */
  /* [nz,N_nmpc+1] */
  /* [nu,N_nmpc+1] */
  /* %weighting matrices */
  /* W1 - error in VT */
  /* W1 - error in theta */
  /* W1 - error in phi */
  /* W1 - error in beta */
  /* W2 - weigthed Throttle */
  /* W2 - weigthed Elevator */
  /* W2 - weigthed Aileron */
  /* W2 - weigthed Rudder */
  /* W3 - weigthed VT */
  /* W3 - weigthed theta */
  /* W3 - weigthed phi */
  /* W3 - weigthed beta */
  /*  for i=1:N_nmpc */
  /*      Rs_nmpc(1,nu*i-nu+1:nu*i)=[r11 r22 r33 r44]; */
  /*  end; */
  /* %%%numerical search%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (loctmp_idx = 0; loctmp_idx < 80; loctmp_idx++) {
    /* %%%variables definition%% */
    /* %servo states%% */
    loctmp_pMIN = loctmp_THL_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)
      - 1];
    loctmp_pMAX = loctmp_EL_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)
      - 1];
    loctmp_p_nmpc = loctmp_AIL_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_RDR_k = loctmp_RDR_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)
      - 1];

    /* %uav states%% */
    loctmp_VT_k = loctmp_VT_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)
      - 1];
    loctmp_alpha_k = loctmp_alpha_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_beta_k = loctmp_beta_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_phi_k = loctmp_phi_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)
      - 1];
    loctmp_theta_k = loctmp_theta_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_psi_k = loctmp_psi_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)
      - 1];
    loctmp_P_k = loctmp_P_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0) -
      1];
    loctmp_Q_k = loctmp_Q_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0) -
      1];
    loctmp_R_k = loctmp_R_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0) -
      1];

    /* %uav inertial position%% */
    loctmp_n_k = loctmp_n_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0) -
      1];
    loctmp_e_k = loctmp_e_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0) -
      1];
    loctmp_h_k = loctmp_h_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0) -
      1];

    /* %long. integrator state */
    loctmp_ro_k = loctmp_ro_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)
      - 1];

    /* %auxiliary variables */
    loctmp_alphadot_k = loctmp_alphadot_hor[(int32_T)ceil((1.0 + (real_T)
      loctmp_idx) / 4.0) - 1];
    loctmp_betadot_k = loctmp_betadot_hor[(int32_T)ceil((1.0 + (real_T)
      loctmp_idx) / 4.0) - 1];
    loctmp_xw11_k = rt_roundd_snf(loctmp_wpt_index_hor[(int32_T)ceil((1.0 +
      (real_T)loctmp_idx) / 4.0) - 1]);
    if (loctmp_xw11_k < 256.0) {
      if (loctmp_xw11_k >= 0.0) {
        loctmp_tmp_0 = (uint8_T)loctmp_xw11_k;
      } else {
        loctmp_tmp_0 = 0U;
      }
    } else {
      loctmp_tmp_0 = MAX_uint8_T;
    }

    loctmp_i = (int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0);
    loctmp_y = (int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0);
    loctmp_ab = (int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0);

    /* %robustness */
    loctmp_xw11_k = loctmp_xw11_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw12_k = loctmp_xw12_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw13_k = loctmp_xw13_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw14_k = loctmp_xw14_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw21_k = loctmp_xw21_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw22_k = loctmp_xw22_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw23_k = loctmp_xw23_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw24_k = loctmp_xw24_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw31_k = loctmp_xw31_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw32_k = loctmp_xw32_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw33_k = loctmp_xw33_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];
    loctmp_xw34_k = loctmp_xw34_hor[(int32_T)ceil((1.0 + (real_T)loctmp_idx) /
      4.0) - 1];

    /* %nmpc output */
    loctmp_b_k = (int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0);
    memcpy(&loctmp_z_k[0], &loctmp_z_hor[(loctmp_b_k - 1) * 12], 12U * sizeof
           (real_T));
    for (loctmp_ia = 0; loctmp_ia < 21; loctmp_ia++) {
      /* %forming nmpc state before perturbation */
      if (1 + loctmp_ia < (int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)) {
        memcpy(&ANN_EKF_NMPC_2_B.z_it_nmpc[12 * loctmp_ia + 252 * loctmp_idx],
               &loctmp_z_hor[12 * loctmp_ia], 12U * sizeof(real_T));
      }

      /* %forming nmpc state after perturbation */
      if (1 + loctmp_ia >= (int32_T)ceil((1.0 + (real_T)loctmp_idx) / 4.0)) {
        memcpy(&ANN_EKF_NMPC_2_B.z_it_nmpc[12 * loctmp_ia + 252 * loctmp_idx],
               &loctmp_z_k[0], 12U * sizeof(real_T));

        /* %command with perturbation at time k%% */
        /* %propagating */
        /*  %assumed zero wind */
        loctmp_unusedU4[0] = loctmp_start_wpt_hor[(loctmp_i - 1) * 3];
        loctmp_unusedU4[1] = loctmp_start_wpt_hor[(loctmp_i - 1) * 3 + 1];
        loctmp_unusedU4[2] = loctmp_start_wpt_hor[(loctmp_i - 1) * 3 + 2];
        for (loctmp_b_k = 0; loctmp_b_k < 32; loctmp_b_k++) {
          loctmp_wpts_h_0[loctmp_b_k] = loctmp_wpts_h[loctmp_b_k];
          loctmp_wpts_n_0[loctmp_b_k] = loctmp_wpts_n[loctmp_b_k];
          loctmp_wpts_e_0[loctmp_b_k] = loctmp_wpts_e[loctmp_b_k];
        }

        ANN_EKF_NMPC_2_uas_augm_model_ms(loctmp_sw, loctmp_home_cmd, loctmp_b_dt,
          loctmp_b_TR, loctmp_wpts_fp, loctmp_wpts_rp, loctmp_wpts_h_0,
          loctmp_wpts_n_0, loctmp_wpts_e_0, loctmp_wpts_v,
          loctmp_n_op_N[loctmp_ia], loctmp_e_op_N[loctmp_ia],
          loctmp_h_op_N[loctmp_ia], loctmp_vn_op_N[loctmp_ia],
          loctmp_ve_op_N[loctmp_ia], loctmp_vh_op_N[loctmp_ia],
          loctmp_alphadot_k, loctmp_betadot_k, loctmp_tmp_0, loctmp_unusedU4,
          loctmp_pic_cic_hor[loctmp_y - 1], loctmp_home_reset_hor[loctmp_ab - 1],
          loctmp_pMIN, loctmp_pMAX, loctmp_p_nmpc, loctmp_RDR_k, loctmp_VT_k,
          loctmp_alpha_k, loctmp_beta_k, loctmp_phi_k, loctmp_theta_k,
          loctmp_psi_k, loctmp_P_k, loctmp_Q_k, loctmp_R_k, loctmp_n_k,
          loctmp_e_k, loctmp_h_k, loctmp_ro_k, loctmp_u_hor[loctmp_ia << 2] +
          0.0001 * (real_T)(((1 + loctmp_ia) << 2) - 3 == 1 + loctmp_idx),
          loctmp_u_hor[1 + (loctmp_ia << 2)] + 0.0001 * (real_T)(((1 + loctmp_ia)
          << 2) - 2 == 1 + loctmp_idx), loctmp_u_hor[2 + (loctmp_ia << 2)] +
          0.0001 * (real_T)(((1 + loctmp_ia) << 2) - 1 == 1 + loctmp_idx),
          loctmp_u_hor[3 + (loctmp_ia << 2)] + 0.0001 * (real_T)((1 + loctmp_ia)
          << 2 == 1 + loctmp_idx), loctmp_xw11_k, loctmp_xw12_k, loctmp_xw13_k,
          loctmp_xw14_k, loctmp_xw21_k, loctmp_xw22_k, loctmp_xw23_k,
          loctmp_xw24_k, loctmp_xw31_k, loctmp_xw32_k, loctmp_xw33_k,
          loctmp_xw34_k, loctmp_b_W11d, loctmp_b_W12d, loctmp_b_W13d,
          loctmp_b_W14d, loctmp_b_W21d, loctmp_b_W22d, loctmp_b_W23d,
          loctmp_b_W24d, loctmp_b_W31d, loctmp_b_W32d, loctmp_b_W33d,
          loctmp_b_W34d, loctmp_b_rho, loctmp_b_S, loctmp_b_Cbar, loctmp_b_b,
          loctmp_b_weight, loctmp_b_g, loctmp_b_IxxB, loctmp_b_IyyB,
          loctmp_b_IzzB, loctmp_b_IxzB, loctmp_b_CDu, loctmp_b_CDq,
          loctmp_b_CDadot, loctmp_b_CDde, loctmp_b_CD0_bar, loctmp_b_Cyb,
          loctmp_b_Cyp, loctmp_b_Cyr, loctmp_b_Cyda, loctmp_b_Cydr, loctmp_b_CL0,
          loctmp_b_CLa, loctmp_b_CLq, loctmp_b_CLadot, loctmp_b_CLu,
          loctmp_b_CLde, loctmp_b_Clb, loctmp_b_Clp, loctmp_b_Clr, loctmp_b_Clda,
          loctmp_b_Cldr, loctmp_b_Cm0, loctmp_b_Cma, loctmp_b_Cmq,
          loctmp_b_Cmadot, loctmp_b_Cmu, loctmp_b_Cmde, loctmp_b_Cnb,
          loctmp_b_Cnp, loctmp_b_Cnr, loctmp_b_Cnda, loctmp_b_Cndr, loctmp_b_xT0,
          loctmp_b_xT1, loctmp_b_xT2, loctmp_b_Ptrim, loctmp_b_Qtrim,
          loctmp_b_Rtrim, loctmp_b_Utrim, loctmp_b_Athrottle, loctmp_b_Bthrottle,
          loctmp_b_Aelevator, loctmp_b_Belevator, loctmp_b_Aaileron,
          loctmp_b_Baileron, loctmp_b_Arudder, loctmp_b_Brudder,
          loctmp_b_ThrottleMax, loctmp_b_ThrottleMin, loctmp_b_ElevatorMax,
          loctmp_b_ElevatorMin, loctmp_b_AileronMax, loctmp_b_AileronMin,
          loctmp_b_RudderMax, loctmp_b_RudderMin, loctmp_b_KpLat, loctmp_b_KiLon,
          loctmp_b_KpLon, loctmp_b_L, loctmp_b_dist2b, loctmp_FL_ann,
          loctmp_a_ann_X, loctmp_b_ann_X, loctmp_c_ann_X, loctmp_w_ann_X,
          loctmp_a_ann_Y, loctmp_b_ann_Y, loctmp_c_ann_Y, loctmp_w_ann_Y,
          loctmp_a_ann_Z, loctmp_b_ann_Z, loctmp_c_ann_Z, loctmp_w_ann_Z,
          loctmp_b_X_minXin, loctmp_b_X_maxXin, loctmp_b_X_minYin,
          loctmp_b_X_maxYin, loctmp_b_X_minXout, loctmp_b_X_maxXout,
          loctmp_b_X_minYout, loctmp_b_X_maxYout, loctmp_b_Y_minXin,
          loctmp_b_Y_maxXin, loctmp_b_Y_minYin, loctmp_b_Y_maxYin,
          loctmp_b_Y_minXout, loctmp_b_Y_maxXout, loctmp_b_Y_minYout,
          loctmp_b_Y_maxYout, loctmp_b_Z_minXin, loctmp_b_Z_maxXin,
          loctmp_b_Z_minYin, loctmp_b_Z_maxYin, loctmp_b_Z_minXout,
          loctmp_b_Z_maxXout, loctmp_b_Z_minYout, loctmp_b_Z_maxYout,
          &loctmp_unusedU2, &loctmp_unusedU3, &loctmp_unusedU5, &loctmp_unusedU6,
          &loctmp_unusedU7, &loctmp_unusedU8, &loctmp_unusedU9, &loctmp_unusedUa,
          &loctmp_unusedUb, &loctmp_unusedUc, &loctmp_unusedUd, &loctmp_unusedUe,
          &loctmp_unusedU10, &loctmp_unusedU11, &loctmp_unusedU12,
          &loctmp_unusedU13, &loctmp_unusedU14, &loctmp_unusedU15,
          &loctmp_unusedU16, loctmp_z_k, loctmp_unusedU17, &loctmp_THL_kk,
          &loctmp_EL_kk, &loctmp_AIL_kk, &loctmp_RDR_kk, &loctmp_VT_kk,
          &loctmp_alpha_kk, &loctmp_beta_kk, &loctmp_phi_kk, &loctmp_theta_kk,
          &loctmp_psi_kk, &loctmp_P_kk, &loctmp_Q_kk, &loctmp_R_kk,
          &loctmp_falpha_k, &loctmp_fbeta_k, &loctmp_n_kk, &loctmp_e_kk,
          &loctmp_h_kk, &loctmp_ro_kk, &loctmp_xw11_kk, &loctmp_xw12_kk,
          &loctmp_xw13_kk, &loctmp_xw14_kk, &loctmp_xw21_kk, &loctmp_xw22_kk,
          &loctmp_xw23_kk, &loctmp_xw24_kk, &loctmp_xw31_kk, &loctmp_xw32_kk,
          &loctmp_xw33_kk, &loctmp_xw34_kk);

        /* %%%next step kk-->k%%%%%%%%%%%%%% */
        /* %predicted servo states%% */
        loctmp_pMIN = loctmp_THL_kk;
        loctmp_pMAX = loctmp_EL_kk;
        loctmp_p_nmpc = loctmp_AIL_kk;
        loctmp_RDR_k = loctmp_RDR_kk;

        /* %predicted uav states%% */
        loctmp_VT_k = loctmp_VT_kk;
        loctmp_alpha_k = loctmp_alpha_kk;
        loctmp_beta_k = loctmp_beta_kk;
        loctmp_phi_k = loctmp_phi_kk;
        loctmp_theta_k = loctmp_theta_kk;
        loctmp_psi_k = loctmp_psi_kk;
        loctmp_P_k = loctmp_P_kk;
        loctmp_Q_k = loctmp_Q_kk;
        loctmp_R_k = loctmp_R_kk;
        loctmp_alphadot_k = loctmp_falpha_k;
        loctmp_betadot_k = loctmp_fbeta_k;

        /* %predicted uav inertial position%% */
        loctmp_n_k = loctmp_n_kk;
        loctmp_e_k = loctmp_e_kk;
        loctmp_h_k = loctmp_h_kk;

        /* %predicted longitudinal integrator state%% */
        loctmp_ro_k = loctmp_ro_kk;

        /* %robustness */
        loctmp_xw11_k = loctmp_xw11_kk;
        loctmp_xw12_k = loctmp_xw12_kk;
        loctmp_xw13_k = loctmp_xw13_kk;
        loctmp_xw14_k = loctmp_xw14_kk;
        loctmp_xw21_k = loctmp_xw21_kk;
        loctmp_xw22_k = loctmp_xw22_kk;
        loctmp_xw23_k = loctmp_xw23_kk;
        loctmp_xw24_k = loctmp_xw24_kk;
        loctmp_xw31_k = loctmp_xw31_kk;
        loctmp_xw32_k = loctmp_xw32_kk;
        loctmp_xw33_k = loctmp_xw33_kk;
        loctmp_xw34_k = loctmp_xw34_kk;
      }
    }

    /* i */
  }

  /* j */
  /* %%%gradient, jacobian and u_mpc correction */
  /* %v vector */
  for (loctmp_idx = 0; loctmp_idx < 20; loctmp_idx++) {
    /* [nz*N_nmpc+nu*N_nmpc,2] */
    loctmp_y = (1 + loctmp_idx) * (int32_T)ANN_EKF_NMPC_2_nz - 12;
    loctmp_ab = (1 + loctmp_idx) * (int32_T)ANN_EKF_NMPC_2_nz;
    if (loctmp_y + 1 > loctmp_ab) {
      loctmp_y = 0;
      loctmp_ab = 0;
    }

    loctmp_c_ii_sizes_idx_1 = loctmp_ab - loctmp_y;
    loctmp_ii_sizes_idx_1 = loctmp_ab - loctmp_y;
    for (loctmp_i = 0; loctmp_i < loctmp_ii_sizes_idx_1; loctmp_i++) {
      loctmp_db_data[loctmp_i] = (int16_T)(loctmp_y + loctmp_i);
    }

    for (loctmp_i = 0; loctmp_i < 12; loctmp_i++) {
      loctmp_z_k[loctmp_i] = 0.0;
      for (loctmp_b_k = 0; loctmp_b_k < 12; loctmp_b_k++) {
        loctmp_z_k[loctmp_i] += loctmp_z_hor[(loctmp_idx + 1) * 12 + loctmp_b_k]
          * (real_T)loctmp_c_a[12 * loctmp_b_k + loctmp_i];
      }
    }

    for (loctmp_i = 0; loctmp_i < loctmp_c_ii_sizes_idx_1; loctmp_i++) {
      loctmp_v_nmpc[loctmp_db_data[loctmp_i]] = loctmp_z_k[loctmp_i];
    }

    /*      v_nmpc(nu*i-nu+1+nz*N_nmpc:nu*i+nz*N_nmpc,1)=diag(Rs_nmpc(1,nu*i-nu+1:nu*i))*u_nmpc(:,i); */
  }

  /* %jacobian matrix */
  for (loctmp_idx = 0; loctmp_idx < 80; loctmp_idx++) {
    /* [nz*N_nmpc+nu*N_nmpc,nu*N_nmpc] */
    for (loctmp_y = 0; loctmp_y < 20; loctmp_y++) {
      loctmp_ab = (1 + loctmp_y) * (int32_T)ANN_EKF_NMPC_2_nz - 12;
      loctmp_ia = (1 + loctmp_y) * (int32_T)ANN_EKF_NMPC_2_nz;
      if (loctmp_ab + 1 > loctmp_ia) {
        loctmp_ab = 0;
        loctmp_ia = 0;
      }

      loctmp_c_ii_sizes_idx_1 = loctmp_ia - loctmp_ab;
      loctmp_ii_sizes_idx_1 = loctmp_ia - loctmp_ab;
      for (loctmp_i = 0; loctmp_i < loctmp_ii_sizes_idx_1; loctmp_i++) {
        loctmp_db_data[loctmp_i] = (int16_T)(loctmp_ab + loctmp_i);
      }

      ANN_EKF_NMPC_2_squeeze(*(real_T (*)[12])&ANN_EKF_NMPC_2_B.z_it_nmpc[(1 +
        loctmp_y) * 12 + 252 * loctmp_idx], loctmp_z_k);
      for (loctmp_i = 0; loctmp_i < 12; loctmp_i++) {
        loctmp_tmp[loctmp_i] = loctmp_z_k[loctmp_i] - loctmp_z_hor[(loctmp_y + 1)
          * 12 + loctmp_i];
      }

      for (loctmp_i = 0; loctmp_i < 12; loctmp_i++) {
        loctmp_z_k[loctmp_i] = 0.0;
        for (loctmp_b_k = 0; loctmp_b_k < 12; loctmp_b_k++) {
          loctmp_z_k[loctmp_i] += (real_T)loctmp_d_a[12 * loctmp_b_k + loctmp_i]
            * loctmp_tmp[loctmp_b_k];
        }
      }

      for (loctmp_i = 0; loctmp_i < loctmp_c_ii_sizes_idx_1; loctmp_i++) {
        ANN_EKF_NMPC_2_B.J_nmpc[loctmp_db_data[loctmp_i] + 240 * loctmp_idx] =
          loctmp_z_k[loctmp_i];
      }
    }

    /*          J_nmpc(j+nz*N_nmpc,j)=Rs_nmpc(1,j); */
  }

  /* %gradient and hessian */
  for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
    loctmp_gradV_nmpc[loctmp_i] = 0.0;
    for (loctmp_b_k = 0; loctmp_b_k < 240; loctmp_b_k++) {
      loctmp_gradV_nmpc[loctmp_i] += ANN_EKF_NMPC_2_B.J_nmpc[240 * loctmp_i +
        loctmp_b_k] * 2.0 * loctmp_v_nmpc[loctmp_b_k];
    }
  }

  /* [nu*N_nmpc,1] */
  for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
    for (loctmp_b_k = 0; loctmp_b_k < 80; loctmp_b_k++) {
      ANN_EKF_NMPC_2_B.J_nmpc_k[loctmp_i + 80 * loctmp_b_k] = 0.0;
      for (loctmp_c_ii_sizes_idx_1 = 0; loctmp_c_ii_sizes_idx_1 < 240;
           loctmp_c_ii_sizes_idx_1++) {
        ANN_EKF_NMPC_2_B.J_nmpc_k[loctmp_i + 80 * loctmp_b_k] +=
          ANN_EKF_NMPC_2_B.J_nmpc[240 * loctmp_i + loctmp_c_ii_sizes_idx_1] *
          ANN_EKF_NMPC_2_B.J_nmpc[240 * loctmp_b_k + loctmp_c_ii_sizes_idx_1];
      }
    }
  }

  for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
    for (loctmp_b_k = 0; loctmp_b_k < 80; loctmp_b_k++) {
      ANN_EKF_NMPC_2_B.hessianV_nmpc[loctmp_b_k + 80 * loctmp_i] =
        ANN_EKF_NMPC_2_B.J_nmpc_k[80 * loctmp_i + loctmp_b_k] * 2.0;
    }
  }

  /* [nu*N_nmpc,nu*N_nmpc] */
  ANN_EKF_NMPC_2_mpower(ANN_EKF_NMPC_2_B.hessianV_nmpc,
                        ANN_EKF_NMPC_2_B.J_nmpc_k);
  for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
    loctmp_deltaV_nmpc[loctmp_i] = 0.0;
    for (loctmp_b_k = 0; loctmp_b_k < 80; loctmp_b_k++) {
      loctmp_deltaV_nmpc[loctmp_i] += ANN_EKF_NMPC_2_B.J_nmpc_k[80 * loctmp_b_k
        + loctmp_i] * loctmp_gradV_nmpc[loctmp_b_k];
    }
  }

  /* [nu*N_nmpc,1] */
  for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
    loctmp_u_nmpc[loctmp_i << 2] = loctmp_u_hor[loctmp_i << 2] -
      loctmp_deltaV_nmpc[loctmp_i << 2];
  }

  for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
    loctmp_u_nmpc[1 + (loctmp_i << 2)] = loctmp_u_hor[(loctmp_i << 2) + 1] -
      loctmp_deltaV_nmpc[(loctmp_i << 2) + 1];
  }

  for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
    loctmp_u_nmpc[2 + (loctmp_i << 2)] = loctmp_u_hor[(loctmp_i << 2) + 2] -
      loctmp_deltaV_nmpc[(loctmp_i << 2) + 2];
  }

  for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
    loctmp_u_nmpc[3 + (loctmp_i << 2)] = loctmp_u_hor[(loctmp_i << 2) + 3] -
      loctmp_deltaV_nmpc[(loctmp_i << 2) + 3];
  }

  /* %constraints correction%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %saturation limits */
  /* 1.0 */
  /* 0.1 */
  memset(&loctmp_deltaV_nmpc[0], 0, 80U * sizeof(real_T));

  /* [nu*N_nmpc,1] */
  for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
    loctmp_u_nmpc_temp[loctmp_i << 2] = loctmp_u_nmpc[loctmp_i << 2];
    loctmp_u_nmpc_temp[1 + (loctmp_i << 2)] = loctmp_u_nmpc[(loctmp_i << 2) + 1];
    loctmp_u_nmpc_temp[2 + (loctmp_i << 2)] = loctmp_u_nmpc[(loctmp_i << 2) + 2];
    loctmp_u_nmpc_temp[3 + (loctmp_i << 2)] = loctmp_u_nmpc[(loctmp_i << 2) + 3];
  }

  /* [nu,N_nmpc] */
  for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
    loctmp_constrMIN_ext[loctmp_i] = 0;
    loctmp_constrMAX_ext[loctmp_i] = 0;
  }

  do {
    exitg1 = 0;
    for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
      loctmp_u_nmpc_temp_0[loctmp_i] = (loctmp_u_nmpc_temp[loctmp_i << 2] <
        loctmp_b_ThrottleMin - 0.0001);
    }

    for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
      loctmp_u_nmpc_temp_0[loctmp_i + 20] = (loctmp_u_nmpc_temp[loctmp_i << 2] >
        loctmp_b_ThrottleMax + 0.0001);
    }

    if (ANN_EKF_NMPC_2_sum(loctmp_u_nmpc_temp_0) > 0.0) {
      /* [1,N_nmpc] */
      for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
        loctmp_constrMIN[loctmp_i] = (loctmp_u_nmpc_temp[loctmp_i << 2] <
          loctmp_b_ThrottleMin + 0.0001);
        loctmp_constrMAX[loctmp_i] = (loctmp_u_nmpc_temp[loctmp_i << 2] >
          loctmp_b_ThrottleMax - 0.0001);
      }

      /* [1,N_nmpc] */
      loctmp_idx = 0;
      loctmp_y = 1;
      loctmp_exitg4 = false;
      while ((!loctmp_exitg4) && (loctmp_y < 21)) {
        loctmp_guard1 = false;
        if (loctmp_constrMIN[loctmp_y - 1]) {
          loctmp_idx++;
          loctmp_ii_data[loctmp_idx - 1] = (int8_T)loctmp_y;
          if (loctmp_idx >= 20) {
            loctmp_exitg4 = true;
          } else {
            loctmp_guard1 = true;
          }
        } else {
          loctmp_guard1 = true;
        }

        if (loctmp_guard1) {
          loctmp_y++;
        }
      }

      if (1 > loctmp_idx) {
        loctmp_ii_sizes_idx_1 = 0;
      } else {
        loctmp_ii_sizes_idx_1 = loctmp_idx;
      }

      /* [1,pMIN] */
      loctmp_idx = 0;
      loctmp_y = 1;
      loctmp_exitg4 = false;
      while ((!loctmp_exitg4) && (loctmp_y < 21)) {
        loctmp_guard1 = false;
        if (loctmp_constrMAX[loctmp_y - 1]) {
          loctmp_idx++;
          loctmp_c_ii_data[loctmp_idx - 1] = (int8_T)loctmp_y;
          if (loctmp_idx >= 20) {
            loctmp_exitg4 = true;
          } else {
            loctmp_guard1 = true;
          }
        } else {
          loctmp_guard1 = true;
        }

        if (loctmp_guard1) {
          loctmp_y++;
        }
      }

      if (1 > loctmp_idx) {
        loctmp_c_ii_sizes_idx_1 = 0;
      } else {
        loctmp_c_ii_sizes_idx_1 = loctmp_idx;
      }

      /* [1,pMAX] */
      for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
        loctmp_constrMIN_ext[loctmp_i << 2] = (int8_T)loctmp_constrMIN[loctmp_i];
      }

      /* [1,nu*N_nmpc] */
      for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
        loctmp_constrMAX_ext[loctmp_i << 2] = (int8_T)loctmp_constrMAX[loctmp_i];
      }

      /* [1,nu*N_nmpc] */
      loctmp_idx = 0;
      loctmp_y = 1;
      loctmp_exitg4 = false;
      while ((!loctmp_exitg4) && (loctmp_y < 81)) {
        loctmp_guard1 = false;
        if (loctmp_constrMIN_ext[loctmp_y - 1] != 0) {
          loctmp_idx++;
          loctmp_e_ii_data[loctmp_idx - 1] = (int8_T)loctmp_y;
          if (loctmp_idx >= 80) {
            loctmp_exitg4 = true;
          } else {
            loctmp_guard1 = true;
          }
        } else {
          loctmp_guard1 = true;
        }

        if (loctmp_guard1) {
          loctmp_y++;
        }
      }

      if (1 > loctmp_idx) {
        loctmp_e_ii_sizes_idx_1 = 0;
      } else {
        loctmp_e_ii_sizes_idx_1 = loctmp_idx;
      }

      loctmp_lambda_indexMIN_ext_sizes_idx_1 = loctmp_e_ii_sizes_idx_1;
      for (loctmp_i = 0; loctmp_i < loctmp_e_ii_sizes_idx_1; loctmp_i++) {
        loctmp_lambda_indexMIN_ext_data[loctmp_i] = loctmp_e_ii_data[loctmp_i];
      }

      /* [1,pMIN] check! */
      loctmp_idx = 0;
      loctmp_y = 1;
      loctmp_exitg4 = false;
      while ((!loctmp_exitg4) && (loctmp_y < 81)) {
        loctmp_guard1 = false;
        if (loctmp_constrMAX_ext[loctmp_y - 1] != 0) {
          loctmp_idx++;
          loctmp_e_ii_data[loctmp_idx - 1] = (int8_T)loctmp_y;
          if (loctmp_idx >= 80) {
            loctmp_exitg4 = true;
          } else {
            loctmp_guard1 = true;
          }
        } else {
          loctmp_guard1 = true;
        }

        if (loctmp_guard1) {
          loctmp_y++;
        }
      }

      if (1 > loctmp_idx) {
        loctmp_e_ii_sizes_idx_1 = 0;
      } else {
        loctmp_e_ii_sizes_idx_1 = loctmp_idx;
      }

      for (loctmp_i = 0; loctmp_i < loctmp_e_ii_sizes_idx_1; loctmp_i++) {
        loctmp_lambda_indexMAX_ext_data[loctmp_i] = loctmp_e_ii_data[loctmp_i];
      }

      /* [1,pMAX] check! */
      loctmp_pMIN = ANN_EKF_NMPC_2_sum_n(loctmp_constrMIN);

      /* [1,1] */
      loctmp_pMAX = ANN_EKF_NMPC_2_sum_n(loctmp_constrMAX);

      /* [1,1] */
      loctmp_p_nmpc = loctmp_pMIN + loctmp_pMAX;

      /* [1,1] */
      if (1.0 > loctmp_p_nmpc) {
        loctmp_idx = 0;
      } else {
        loctmp_idx = (int32_T)loctmp_p_nmpc;
      }

      for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
        for (loctmp_b_k = 0; loctmp_b_k < loctmp_idx; loctmp_b_k++) {
          ANN_EKF_NMPC_2_B.A_c[loctmp_b_k + 40 * loctmp_i] = 0.0;
        }
      }

      /* [p_nmpc,nu*N_nmpc] */
      for (loctmp_idx = 0; loctmp_idx < (int32_T)loctmp_pMIN; loctmp_idx++) {
        ANN_EKF_NMPC_2_B.A_c[loctmp_idx + 40 *
          (loctmp_lambda_indexMIN_ext_data[loctmp_idx] - 1)] = -1.0;

        /* [pMIN,nu*N_nmpc] */
      }

      for (loctmp_idx = 0; loctmp_idx < (int32_T)loctmp_pMAX; loctmp_idx++) {
        ANN_EKF_NMPC_2_B.A_c[((int32_T)((1.0 + (real_T)loctmp_idx) + loctmp_pMIN)
                              + 40 * (loctmp_lambda_indexMAX_ext_data[loctmp_idx]
          - 1)) - 1] = 1.0;

        /* [pMAX,nu*N_nmpc] */
      }

      /* %constraints */
      /*            %[p_nmpc,1] */
      /*                 %[nu*N_nmpc+p_nmpc,1] */
      for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
        loctmp_gradL_nmpc_data[loctmp_i] = loctmp_gradV_nmpc[loctmp_i] -
          loctmp_deltaV_nmpc[loctmp_i];
      }

      for (loctmp_i = 0; loctmp_i < loctmp_ii_sizes_idx_1; loctmp_i++) {
        loctmp_gradL_nmpc_data[loctmp_i + 80] = -loctmp_u_hor
          [(loctmp_ii_data[loctmp_i] - 1) << 2] + loctmp_b_ThrottleMin;
      }

      for (loctmp_i = 0; loctmp_i < loctmp_c_ii_sizes_idx_1; loctmp_i++) {
        loctmp_gradL_nmpc_data[(loctmp_i + loctmp_ii_sizes_idx_1) + 80] =
          loctmp_u_hor[(loctmp_c_ii_data[loctmp_i] - 1) << 2] -
          loctmp_b_ThrottleMax;
      }

      loctmp_c_ii_sizes_idx_1 = (int32_T)(80.0 + loctmp_p_nmpc);
      loctmp_ii_sizes_idx_1 = (int32_T)(80.0 + loctmp_p_nmpc);
      for (loctmp_i = 0; loctmp_i < loctmp_ii_sizes_idx_1; loctmp_i++) {
        for (loctmp_b_k = 0; loctmp_b_k < loctmp_c_ii_sizes_idx_1; loctmp_b_k++)
        {
          ANN_EKF_NMPC_2_B.hessianL_nmpc[loctmp_b_k + 120 * loctmp_i] = 0.0;
        }
      }

      /* [nu*N_nmpc+p_nmpc,nu*N_nmpc+p_nmpc] */
      for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
        memcpy(&ANN_EKF_NMPC_2_B.hessianL_nmpc[120 * loctmp_i],
               &ANN_EKF_NMPC_2_B.hessianV_nmpc[80 * loctmp_i], 80U * sizeof
               (real_T));
      }

      /* block (1,1) */
      if (81.0 > 80.0 + loctmp_p_nmpc) {
        loctmp_idx = 0;
      } else {
        loctmp_idx = 80;
      }

      if (1.0 > loctmp_p_nmpc) {
        loctmp_i = 0;
      } else {
        loctmp_i = (int32_T)loctmp_p_nmpc;
      }

      loctmp_ii_sizes_idx_1 = loctmp_i - 1;
      for (loctmp_i = 0; loctmp_i <= loctmp_ii_sizes_idx_1; loctmp_i++) {
        for (loctmp_b_k = 0; loctmp_b_k < 80; loctmp_b_k++) {
          ANN_EKF_NMPC_2_B.hessianL_nmpc[loctmp_b_k + 120 * (loctmp_idx +
            loctmp_i)] = -ANN_EKF_NMPC_2_B.A_c[40 * loctmp_b_k + loctmp_i];
        }
      }

      /* block (1,2) */
      if (81.0 > 80.0 + loctmp_p_nmpc) {
        loctmp_idx = 0;
      } else {
        loctmp_idx = 80;
      }

      if (1.0 > loctmp_p_nmpc) {
        loctmp_i = 0;
      } else {
        loctmp_i = (int32_T)loctmp_p_nmpc;
      }

      loctmp_ii_sizes_idx_1 = loctmp_i - 1;
      for (loctmp_i = 0; loctmp_i < 80; loctmp_i++) {
        for (loctmp_b_k = 0; loctmp_b_k <= loctmp_ii_sizes_idx_1; loctmp_b_k++)
        {
          ANN_EKF_NMPC_2_B.hessianL_nmpc[(loctmp_idx + loctmp_b_k) + 120 *
            loctmp_i] = ANN_EKF_NMPC_2_B.A_c[40 * loctmp_i + loctmp_b_k];
        }
      }

      /* block (2,1) */
      loctmp_ii_sizes_idx_1 = (int32_T)(80.0 + loctmp_p_nmpc);
      loctmp_c_ii_sizes_idx_1 = (int32_T)(80.0 + loctmp_p_nmpc);
      loctmp_hessianL_nmpc_sizes[0] = loctmp_ii_sizes_idx_1;
      loctmp_hessianL_nmpc_sizes[1] = loctmp_c_ii_sizes_idx_1;
      for (loctmp_i = 0; loctmp_i < loctmp_c_ii_sizes_idx_1; loctmp_i++) {
        for (loctmp_b_k = 0; loctmp_b_k < loctmp_ii_sizes_idx_1; loctmp_b_k++) {
          ANN_EKF_NMPC_2_B.hessianL_nmpc_data[loctmp_b_k + loctmp_ii_sizes_idx_1
            * loctmp_i] = ANN_EKF_NMPC_2_B.hessianL_nmpc[120 * loctmp_i +
            loctmp_b_k];
        }
      }

      ANN_EKF_NMPC_2_mpower_k(ANN_EKF_NMPC_2_B.hessianL_nmpc_data,
        loctmp_hessianL_nmpc_sizes, ANN_EKF_NMPC_2_B.b_a_data, loctmp_b_a_sizes);
      loctmp_b_k = loctmp_b_a_sizes[1];
      loctmp_b_m = loctmp_b_a_sizes[0];
      loctmp_c_ii_sizes_idx_1 = (int8_T)loctmp_b_a_sizes[0];
      for (loctmp_i = 0; loctmp_i < loctmp_c_ii_sizes_idx_1; loctmp_i++) {
        loctmp_deltaL_nmpc_data[loctmp_i] = 0.0;
      }

      loctmp_idx = 0;
      while (loctmp_idx <= 0) {
        for (loctmp_idx = 1; loctmp_idx <= loctmp_b_m; loctmp_idx++) {
          loctmp_deltaL_nmpc_data[loctmp_idx - 1] = 0.0;
        }

        loctmp_idx = loctmp_b_m;
      }

      loctmp_ii_sizes_idx_1 = 0;
      loctmp_idx = 0;
      while (loctmp_idx <= 0) {
        loctmp_idx = 0;
        loctmp_y = loctmp_ii_sizes_idx_1 + loctmp_b_k;
        for (loctmp_ab = loctmp_ii_sizes_idx_1; loctmp_ab + 1 <= loctmp_y;
             loctmp_ab++) {
          if (loctmp_gradL_nmpc_data[loctmp_ab] != 0.0) {
            loctmp_ia = loctmp_idx;
            for (loctmp_c_ii_sizes_idx_1 = 0; loctmp_c_ii_sizes_idx_1 + 1 <=
                 loctmp_b_m; loctmp_c_ii_sizes_idx_1++) {
              loctmp_ia++;
              loctmp_deltaL_nmpc_data[loctmp_c_ii_sizes_idx_1] +=
                ANN_EKF_NMPC_2_B.b_a_data[loctmp_ia - 1] *
                loctmp_gradL_nmpc_data[loctmp_ab];
            }
          }

          loctmp_idx += loctmp_b_m;
        }

        loctmp_ii_sizes_idx_1 += loctmp_b_k;
        loctmp_idx = loctmp_b_m;
      }

      /* [nu*N_nmpc+p_nmpc,1] */
      for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
        loctmp_u_nmpc_temp[loctmp_i << 2] = loctmp_u_hor[loctmp_i << 2] -
          loctmp_deltaL_nmpc_data[loctmp_i << 2];
      }

      if (81.0 > 80.0 + loctmp_pMIN) {
        loctmp_idx = 1;
        loctmp_y = 0;
      } else {
        loctmp_idx = 81;
        loctmp_y = (int32_T)(80.0 + loctmp_pMIN);
      }

      for (loctmp_i = 0; loctmp_i < loctmp_lambda_indexMIN_ext_sizes_idx_1;
           loctmp_i++) {
        loctmp_e_ii_data[loctmp_i] = loctmp_lambda_indexMIN_ext_data[loctmp_i];
      }

      loctmp_ii_sizes_idx_1 = loctmp_y - loctmp_idx;
      for (loctmp_i = 0; loctmp_i <= loctmp_ii_sizes_idx_1; loctmp_i++) {
        loctmp_idx_data[loctmp_i] = loctmp_idx + loctmp_i;
      }

      for (loctmp_i = 0; loctmp_i < loctmp_lambda_indexMIN_ext_sizes_idx_1;
           loctmp_i++) {
        loctmp_deltaV_nmpc[loctmp_e_ii_data[loctmp_i] - 1] =
          -loctmp_deltaL_nmpc_data[loctmp_idx_data[loctmp_i] - 1];
      }

      if ((80.0 + loctmp_pMIN) + 1.0 > 80.0 + loctmp_p_nmpc) {
        loctmp_idx = 1;
        loctmp_y = 0;
      } else {
        loctmp_idx = (int32_T)((80.0 + loctmp_pMIN) + 1.0);
        loctmp_y = (int32_T)(80.0 + loctmp_p_nmpc);
      }

      for (loctmp_i = 0; loctmp_i < loctmp_e_ii_sizes_idx_1; loctmp_i++) {
        loctmp_e_ii_data[loctmp_i] = loctmp_lambda_indexMAX_ext_data[loctmp_i];
      }

      loctmp_ii_sizes_idx_1 = loctmp_y - loctmp_idx;
      for (loctmp_i = 0; loctmp_i <= loctmp_ii_sizes_idx_1; loctmp_i++) {
        loctmp_idx_data[loctmp_i] = loctmp_idx + loctmp_i;
      }

      for (loctmp_i = 0; loctmp_i < loctmp_e_ii_sizes_idx_1; loctmp_i++) {
        loctmp_deltaV_nmpc[loctmp_e_ii_data[loctmp_i] - 1] =
          -loctmp_deltaL_nmpc_data[loctmp_idx_data[loctmp_i] - 1];
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  for (loctmp_i = 0; loctmp_i < 20; loctmp_i++) {
    loctmp_u_nmpc[loctmp_i << 2] = loctmp_u_nmpc_temp[loctmp_i << 2];
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %constraints correction%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  %%constraints correction%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  %%saturation limits */
  /*  u1MAX=ThrottleMax; %1.0 */
  /*  u1MIN=ThrottleMin; %0.1 */
  /*  u2MAX=ElevatorMax; % */
  /*  u2MIN=ElevatorMin; % */
  /*  u3MAX=AileronMax;  % */
  /*  u3MIN=AileronMin;  % */
  /*  u4MAX=RudderMax;   % */
  /*  u4MIN=RudderMin;   % */
  /*   */
  /*  uMIN=diag([u1MIN,u2MIN,u3MIN,u4MIN])*ones(nu,N_nmpc);         %[nu,N_nmpc] */
  /*  uMAX=diag([u1MAX,u2MAX,u3MAX,u4MAX])*ones(nu,N_nmpc);         %[nu,N_nmpc] */
  /*   */
  /*  u_nmpc_temp(1:nu,1:N_nmpc)=u_it_nmpc(1:nu,1:N_nmpc);          %[nu,N_nmpc] */
  /*  lambda=zeros(nu*N_nmpc,1);                                    %[nu*N_nmpc,1] */
  /*   */
  /*  while nnz([u_nmpc_temp<(uMIN-0.0001) u_nmpc_temp>(uMAX+0.0001)])>0 */
  /*   */
  /*      %%active constraints */
  /*      constrMIN=u_nmpc_temp<(uMIN+0.0001);                      %[nu,N_nmpc] */
  /*      constrMAX=u_nmpc_temp>(uMAX-0.0001);                      %[nu,N_nmpc] */
  /*      pMIN=nnz(constrMIN);                                      %[1,1] */
  /*      pMAX=nnz(constrMAX);                                      %[1,1] */
  /*      p_nmpc=pMIN+pMAX;                                         %[1,1] */
  /*      lambda_indexMIN=find(constrMIN);                          %[1,pMIN] */
  /*      lambda_indexMAX=find(constrMAX);                          %[1,pMAX] */
  /*   */
  /*      %%jacobian of constraints */
  /*      A(1:p_nmpc,1:nu*N_nmpc)=0;                                %[p_nmpc,nu*N_nmpc] */
  /*      for i=1:pMIN */
  /*          A(i,lambda_indexMIN(i))=-1;                           %[pMIN,nu*N_nmpc] */
  /*      end; */
  /*      for i=1:pMAX */
  /*          A(i+pMIN,lambda_indexMAX(i))=1;                       %[pMAX,nu*N_nmpc] */
  /*      end; */
  /*   */
  /*      %%constraint vector */
  /*      c_nmpc=[-u_nmpc(lambda_indexMIN)+uMIN(lambda_indexMIN);...%[p_nmpc,1] */
  /*               u_nmpc(lambda_indexMAX)-uMAX(lambda_indexMAX)]; */
  /*   */
  /*      gradL_nmpc=[-gradV_nmpc+A'*lambda([lambda_indexMIN;lambda_indexMAX]);... */
  /*                  -c_nmpc];                                     %[nu*N_nmpc+p_nmpc,1] */
  /*      hessianL_nmpc(1:nu*N_nmpc+p_nmpc,1:nu*N_nmpc+p_nmpc)=0;   %[nu*N_nmpc+p_nmpc,nu*N_nmpc+p_nmpc] */
  /*      hessianL_nmpc(1:nu*N_nmpc,1:nu*N_nmpc)=hessianV_nmpc(1:nu*N_nmpc,1:nu*N_nmpc);      %block (1,1) */
  /*      hessianL_nmpc(1:nu*N_nmpc,nu*N_nmpc+1:nu*N_nmpc+p_nmpc)=-A(1:p_nmpc,1:nu*N_nmpc)';  %block (1,2) */
  /*      hessianL_nmpc(nu*N_nmpc+1:nu*N_nmpc+p_nmpc,1:nu*N_nmpc)=A(1:p_nmpc,1:nu*N_nmpc);    %block (2,1) */
  /*       */
  /*      deltaL_nmpc=hessianL_nmpc(1:nu*N_nmpc+p_nmpc,1:nu*N_nmpc+p_nmpc)^-1*... */
  /*                  gradL_nmpc;                                   %[nu*N_nmpc+p_nmpc,1] */
  /*      u_nmpc_temp(1:nu,1:N_nmpc)=u_nmpc(1:nu,1:N_nmpc)+reshape(deltaL_nmpc(1:nu*N_nmpc,1),nu,N_nmpc); */
  /*      lambda([lambda_indexMIN;lambda_indexMAX])=deltaL_nmpc(nu*N_nmpc+1:nu*N_nmpc+p_nmpc);%[p_nmpc,1] */
  /*   */
  /*  end; */
  /*  u_it_nmpc(1:nu,1:N_nmpc)=u_nmpc_temp(1:nu,1:N_nmpc); */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  %%constraints correction%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %numerical solution%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%numerical search%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %updated v */
  for (loctmp_idx = 0; loctmp_idx < 20; loctmp_idx++) {
    loctmp_y = (1 + loctmp_idx) * (int32_T)ANN_EKF_NMPC_2_nz - 12;
    loctmp_ab = (1 + loctmp_idx) * (int32_T)ANN_EKF_NMPC_2_nz;
    if (loctmp_y + 1 > loctmp_ab) {
      loctmp_y = 0;
      loctmp_ab = 0;
    }

    loctmp_c_ii_sizes_idx_1 = loctmp_ab - loctmp_y;
    loctmp_ii_sizes_idx_1 = loctmp_ab - loctmp_y;
    for (loctmp_i = 0; loctmp_i < loctmp_ii_sizes_idx_1; loctmp_i++) {
      loctmp_db_data[loctmp_i] = (int16_T)(loctmp_y + loctmp_i);
    }

    for (loctmp_i = 0; loctmp_i < 12; loctmp_i++) {
      loctmp_z_k[loctmp_i] = 0.0;
      for (loctmp_b_k = 0; loctmp_b_k < 12; loctmp_b_k++) {
        loctmp_z_k[loctmp_i] += loctmp_z_hor[(loctmp_idx + 1) * 12 + loctmp_b_k]
          * (real_T)loctmp_c_a[12 * loctmp_b_k + loctmp_i];
      }
    }

    for (loctmp_i = 0; loctmp_i < loctmp_c_ii_sizes_idx_1; loctmp_i++) {
      loctmp_v_nmpc[240 + loctmp_db_data[loctmp_i]] = loctmp_z_k[loctmp_i];
    }

    /*      v_nmpc(nu*i-nu+1+nz*N_nmpc:nu*i+nz*N_nmpc,2)=diag(Rs_nmpc(1,nu*i-nu+1:nu*i))*u_nmpc(:,i); */
  }

  /* %Cost */
  *loctmp_V_nmpc = 0.0;
  for (loctmp_i = 0; loctmp_i < 240; loctmp_i++) {
    *loctmp_V_nmpc += loctmp_v_nmpc[240 + loctmp_i] * loctmp_v_nmpc[240 +
      loctmp_i];
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
}

real_T rt_powd_snf(real_T loctmp_u0, real_T loctmp_u1)
{
  real_T loctmp_y;
  real_T loctmp_tmp;
  real_T loctmp_tmp_0;
  if (rtIsNaN(loctmp_u0) || rtIsNaN(loctmp_u1)) {
    loctmp_y = (rtNaN);
  } else {
    loctmp_tmp = fabs(loctmp_u0);
    loctmp_tmp_0 = fabs(loctmp_u1);
    if (rtIsInf(loctmp_u1)) {
      if (loctmp_tmp == 1.0) {
        loctmp_y = (rtNaN);
      } else if (loctmp_tmp > 1.0) {
        if (loctmp_u1 > 0.0) {
          loctmp_y = (rtInf);
        } else {
          loctmp_y = 0.0;
        }
      } else if (loctmp_u1 > 0.0) {
        loctmp_y = 0.0;
      } else {
        loctmp_y = (rtInf);
      }
    } else if (loctmp_tmp_0 == 0.0) {
      loctmp_y = 1.0;
    } else if (loctmp_tmp_0 == 1.0) {
      if (loctmp_u1 > 0.0) {
        loctmp_y = loctmp_u0;
      } else {
        loctmp_y = 1.0 / loctmp_u0;
      }
    } else if (loctmp_u1 == 2.0) {
      loctmp_y = loctmp_u0 * loctmp_u0;
    } else if ((loctmp_u1 == 0.5) && (loctmp_u0 >= 0.0)) {
      loctmp_y = sqrt(loctmp_u0);
    } else if ((loctmp_u0 < 0.0) && (loctmp_u1 > floor(loctmp_u1))) {
      loctmp_y = (rtNaN);
    } else {
      loctmp_y = pow(loctmp_u0, loctmp_u1);
    }
  }

  return loctmp_y;
}

/* Function for MATLAB Function: '<S2>/Control System' */
static void ANN_EKF_NMPC_2_uas_augm_model_m(real_T loctmp_sw, boolean_T
  loctmp_home_cmd, real_T loctmp_b_dt, real_T loctmp_b_TR, uint8_T
  loctmp_wpts_fp, uint8_T loctmp_wpts_rp, real_T loctmp_wpts_h[32], real_T
  loctmp_wpts_n[32], real_T loctmp_wpts_e[32], const real_T loctmp_wpts_v[32],
  real_T loctmp_n_op_k, real_T loctmp_e_op_k, real_T loctmp_h_op_k, real_T
  loctmp_vn_op_k, real_T loctmp_ve_op_k, real_T loctmp_vh_op_k, real_T
  loctmp_alphadot_k, real_T loctmp_betadot_k, real_T loctmp_wpt_index_k, real_T
  loctmp_start_wpt_k[3], real_T loctmp_pic_cic_k, real_T loctmp_home_reset_k,
  real_T loctmp_THL_k, real_T loctmp_EL_k, real_T loctmp_AIL_k, real_T
  loctmp_RDR_k, real_T loctmp_VT_k, real_T loctmp_alpha_k, real_T loctmp_beta_k,
  real_T loctmp_phi_k, real_T loctmp_theta_k, real_T loctmp_psi_k, real_T
  loctmp_P_k, real_T loctmp_Q_k, real_T loctmp_R_k, real_T loctmp_n_k, real_T
  loctmp_e_k, real_T loctmp_h_k, real_T loctmp_ro_k, real_T loctmp_THLcmd_k,
  real_T loctmp_ELcmd_k, real_T loctmp_AILcmd_k, real_T loctmp_RDRcmd_k, real_T
  loctmp_xw11_k, real_T loctmp_xw12_k, real_T loctmp_xw13_k, real_T
  loctmp_xw14_k, real_T loctmp_xw21_k, real_T loctmp_xw22_k, real_T
  loctmp_xw23_k, real_T loctmp_xw24_k, real_T loctmp_xw31_k, real_T
  loctmp_xw32_k, real_T loctmp_xw33_k, real_T loctmp_xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W12d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W21d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W24d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W33d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC loctmp_b_W34d, real_T loctmp_b_rho, real_T
  loctmp_b_S, real_T loctmp_b_Cbar, real_T loctmp_b_b, real_T loctmp_b_weight,
  real_T loctmp_b_g, real_T loctmp_b_IxxB, real_T loctmp_b_IyyB, real_T
  loctmp_b_IzzB, real_T loctmp_b_IxzB, real_T loctmp_b_CDu, real_T loctmp_b_CDq,
  real_T loctmp_b_CDadot, real_T loctmp_b_CDde, real_T loctmp_b_CD0_bar, real_T
  loctmp_b_Cyb, real_T loctmp_b_Cyp, real_T loctmp_b_Cyr, real_T loctmp_b_Cyda,
  real_T loctmp_b_Cydr, real_T loctmp_b_CL0, real_T loctmp_b_CLa, real_T
  loctmp_b_CLq, real_T loctmp_b_CLadot, real_T loctmp_b_CLu, real_T
  loctmp_b_CLde, real_T loctmp_b_Clb, real_T loctmp_b_Clp, real_T loctmp_b_Clr,
  real_T loctmp_b_Clda, real_T loctmp_b_Cldr, real_T loctmp_b_Cm0, real_T
  loctmp_b_Cma, real_T loctmp_b_Cmq, real_T loctmp_b_Cmadot, real_T loctmp_b_Cmu,
  real_T loctmp_b_Cmde, real_T loctmp_b_Cnb, real_T loctmp_b_Cnp, real_T
  loctmp_b_Cnr, real_T loctmp_b_Cnda, real_T loctmp_b_Cndr, real_T loctmp_b_xT0,
  real_T loctmp_b_xT1, real_T loctmp_b_xT2, real_T loctmp_b_Ptrim, real_T
  loctmp_b_Qtrim, real_T loctmp_b_Rtrim, real_T loctmp_b_Utrim, real_T
  loctmp_b_Athrottle, real_T loctmp_b_Bthrottle, real_T loctmp_b_Aelevator,
  real_T loctmp_b_Belevator, real_T loctmp_b_Aaileron, real_T loctmp_b_Baileron,
  real_T loctmp_b_Arudder, real_T loctmp_b_Brudder, real_T loctmp_b_ThrottleMax,
  real_T loctmp_b_ThrottleMin, real_T loctmp_b_ElevatorMax, real_T
  loctmp_b_ElevatorMin, real_T loctmp_b_AileronMax, real_T loctmp_b_AileronMin,
  real_T loctmp_b_RudderMax, real_T loctmp_b_RudderMin, real_T loctmp_b_KpLat,
  real_T loctmp_b_KiLon, real_T loctmp_b_KpLon, real_T loctmp_b_L, real_T
  loctmp_b_dist2b, real_T loctmp_FL_ann, const real_T loctmp_a_ann_X[40], const
  real_T loctmp_b_ann_X[40], real_T loctmp_c_ann_X, const real_T loctmp_w_ann_X
  [280], const real_T loctmp_a_ann_Y[40], const real_T loctmp_b_ann_Y[40],
  real_T loctmp_c_ann_Y, const real_T loctmp_w_ann_Y[280], const real_T
  loctmp_a_ann_Z[40], const real_T loctmp_b_ann_Z[40], real_T loctmp_c_ann_Z,
  const real_T loctmp_w_ann_Z[280], const real_T loctmp_b_X_minXin[7], const
  real_T loctmp_b_X_maxXin[7], real_T loctmp_b_X_minYin, real_T
  loctmp_b_X_maxYin, real_T loctmp_b_X_minXout, real_T loctmp_b_X_maxXout,
  real_T loctmp_b_X_minYout, real_T loctmp_b_X_maxYout, const real_T
  loctmp_b_Y_minXin[7], const real_T loctmp_b_Y_maxXin[7], real_T
  loctmp_b_Y_minYin, real_T loctmp_b_Y_maxYin, real_T loctmp_b_Y_minXout, real_T
  loctmp_b_Y_maxXout, real_T loctmp_b_Y_minYout, real_T loctmp_b_Y_maxYout,
  const real_T loctmp_b_Z_minXin[7], const real_T loctmp_b_Z_maxXin[7], real_T
  loctmp_b_Z_minYin, real_T loctmp_b_Z_maxYin, real_T loctmp_b_Z_minXout, real_T
  loctmp_b_Z_maxXout, real_T loctmp_b_Z_minYout, real_T loctmp_b_Z_maxYout,
  real32_T *loctmp_distance2b, uint8_T *loctmp_wpt_index_kk, real_T
  *loctmp_pic_cic_kk, uint8_T *loctmp_home_reset_kk, real_T *loctmp_nr_k, real_T
  *loctmp_er_k, real_T *loctmp_hr_k, real_T *loctmp_etaLon_k, real_T
  *loctmp_etaLat_k, real_T *loctmp_VTcmd_k, real_T *loctmp_thetacmd_k, real_T
  *loctmp_phicmd_k, real_T *loctmp_Vab_k, real_T *loctmp_accelX_scd_k, real_T
  *loctmp_accelX_ann_k, real_T *loctmp_accelY_scd_k, real_T *loctmp_accelY_ann_k,
  real_T *loctmp_accelZ_scd_k, real_T *loctmp_accelZ_ann_k, real_T
  loctmp_z_augm_k[12], real_T loctmp_e_augm_k[4], real_T *loctmp_THL_kk, real_T *
  loctmp_EL_kk, real_T *loctmp_AIL_kk, real_T *loctmp_RDR_kk, real_T
  *loctmp_VT_kk, real_T *loctmp_alpha_kk, real_T *loctmp_beta_kk, real_T
  *loctmp_phi_kk, real_T *loctmp_theta_kk, real_T *loctmp_psi_kk, real_T
  *loctmp_P_kk, real_T *loctmp_Q_kk, real_T *loctmp_R_kk, real_T
  *loctmp_falpha_k, real_T *loctmp_fbeta_k, real_T *loctmp_n_kk, real_T
  *loctmp_e_kk, real_T *loctmp_h_kk, real_T *loctmp_ro_kk, real_T
  *loctmp_xw11_kk, real_T *loctmp_xw12_kk, real_T *loctmp_xw13_kk, real_T
  *loctmp_xw14_kk, real_T *loctmp_xw21_kk, real_T *loctmp_xw22_kk, real_T
  *loctmp_xw23_kk, real_T *loctmp_xw24_kk, real_T *loctmp_xw31_kk, real_T
  *loctmp_xw32_kk, real_T *loctmp_xw33_kk, real_T *loctmp_xw34_kk)
{
  real_T loctmp_mass;
  real_T loctmp_delta_I;
  real_T loctmp_c2;
  real_T loctmp_c4;
  real_T loctmp_Qbar_k;
  real_T loctmp_U_k;
  real_T loctmp_V_k;
  real_T loctmp_W_k;
  real_T loctmp_CL_k;
  real_T loctmp_CD_k;
  real_T loctmp_Cls_k;
  real_T loctmp_Cms_k;
  real_T loctmp_Cns_k;
  real_T loctmp_Cl_k;
  real_T loctmp_Cn_k;
  real_T loctmp_Udot_k;
  real_T loctmp_Vdot_k;
  real_T loctmp_Wdot_k;
  real_T loctmp_fn_k;
  real_T loctmp_fe_k;
  real_T loctmp_fh_k;
  uint8_T loctmp_next_wpt_index;
  real_T loctmp_ea;
  real_T loctmp_hd_k;
  real_T loctmp_nd_k;
  real_T loctmp_ed_k;
  real_T loctmp_atrack;
  int32_T loctmp_factor;
  real_T loctmp_btrack;
  real_T loctmp_edot_track_k;
  real_T loctmp_ndot_track_k;
  real_T loctmp_r_a;
  real_T loctmp_s_a;
  real_T loctmp_t_a;
  real_T loctmp_er_k_0[2];
  real_T loctmp_er_k_1[3];
  real_T loctmp_nr_k_0[2];
  real_T loctmp_fn_k_0[2];
  real_T loctmp_VT_k_0[7];
  real_T loctmp_VT_k_1[7];
  real_T loctmp_VT_k_2[7];
  real_T loctmp_tmp[7];
  real_T loctmp_w_ann_X_0[40];
  int32_T loctmp_i;

  /* %temporary */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %mass and inertia coefficients%% */
  loctmp_mass = loctmp_b_weight / loctmp_b_g;
  loctmp_delta_I = loctmp_b_IxxB * loctmp_b_IzzB - loctmp_b_IxzB * loctmp_b_IxzB;
  loctmp_c2 = ((loctmp_b_IxxB - loctmp_b_IyyB) + loctmp_b_IzzB) * loctmp_b_IxzB /
    loctmp_delta_I;
  loctmp_c4 = loctmp_b_IxzB / loctmp_delta_I;

  /* %dynamic pressure%% */
  loctmp_Qbar_k = 0.5 * loctmp_b_rho * (loctmp_VT_k * loctmp_VT_k);

  /* %body velocities%% */
  loctmp_U_k = loctmp_VT_k * cos(loctmp_alpha_k) * cos(loctmp_beta_k);
  loctmp_V_k = loctmp_VT_k * sin(loctmp_beta_k);
  loctmp_W_k = loctmp_VT_k * sin(loctmp_alpha_k) * cos(loctmp_beta_k);

  /* %aerodynamic coefficients%% */
  loctmp_CL_k = ((((loctmp_Q_k - loctmp_b_Qtrim) * loctmp_b_CLq * loctmp_b_Cbar /
                   2.0 / loctmp_b_Utrim + (loctmp_b_CLa * loctmp_alpha_k +
    loctmp_b_CL0)) + loctmp_b_CLadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                  loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) * loctmp_b_CLu
                 / loctmp_b_Utrim) + loctmp_b_CLde * loctmp_EL_k;

  /* CD_k=CD0+CDa*alpha_k+CDq*(Q_k-Qtrim)*Cbar/2/Utrim+CDadot*alphadot_k*Cbar/2/Utrim+CDu*(U_k-Utrim)/Utrim+CDde*EL_k; %lin */
  loctmp_CD_k = ((((loctmp_CL_k * loctmp_CL_k / (3.1415926535897931 * loctmp_b_b
    / loctmp_b_Cbar * 0.87) + loctmp_b_CD0_bar) + (loctmp_Q_k - loctmp_b_Qtrim) *
                   loctmp_b_CDq * loctmp_b_Cbar / 2.0 / loctmp_b_Utrim) +
                  loctmp_b_CDadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                  loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) * loctmp_b_CDu
                 / loctmp_b_Utrim) + loctmp_b_CDde * loctmp_EL_k;

  /* nonlin */
  loctmp_Cls_k = ((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Clp * loctmp_b_b /
                    2.0 / loctmp_b_Utrim + loctmp_b_Clb * loctmp_beta_k) +
                   (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Clr * loctmp_b_b /
                   2.0 / loctmp_b_Utrim) + loctmp_b_Clda * loctmp_AIL_k) +
    loctmp_b_Cldr * loctmp_RDR_k;
  loctmp_Cms_k = ((((loctmp_Q_k - loctmp_b_Qtrim) * loctmp_b_Cmq * loctmp_b_Cbar
                    / 2.0 / loctmp_b_Utrim + (loctmp_b_Cma * loctmp_alpha_k +
    loctmp_b_Cm0)) + loctmp_b_Cmadot * loctmp_alphadot_k * loctmp_b_Cbar / 2.0 /
                   loctmp_b_Utrim) + (loctmp_U_k - loctmp_b_Utrim) *
                  loctmp_b_Cmu / loctmp_b_Utrim) + loctmp_b_Cmde * loctmp_EL_k;
  loctmp_Cns_k = ((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Cnp * loctmp_b_b /
                    2.0 / loctmp_b_Utrim + loctmp_b_Cnb * loctmp_beta_k) +
                   (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Cnr * loctmp_b_b /
                   2.0 / loctmp_b_Utrim) + loctmp_b_Cnda * loctmp_AIL_k) +
    loctmp_b_Cndr * loctmp_RDR_k;
  loctmp_Cl_k = loctmp_Cls_k * cos(loctmp_alpha_k) - loctmp_Cns_k * sin
    (loctmp_alpha_k);
  loctmp_Cn_k = loctmp_Cls_k * sin(loctmp_alpha_k) + loctmp_Cns_k * cos
    (loctmp_alpha_k);

  /* %engine thrust%% */
  loctmp_Cls_k = 100.0 * loctmp_THL_k;

  /* %S&C aerodynamic and thrust linear accelerations%% */
  *loctmp_accelX_scd_k = (((loctmp_Cls_k * loctmp_Cls_k * loctmp_b_xT2 + 100.0 *
    loctmp_THL_k * loctmp_b_xT1) + loctmp_b_xT0) + (-loctmp_CD_k * cos
    (loctmp_alpha_k) + loctmp_CL_k * sin(loctmp_alpha_k)) * (loctmp_Qbar_k *
    loctmp_b_S)) / loctmp_mass;

  /* [ft/s2] */
  *loctmp_accelY_scd_k = (((((loctmp_P_k - loctmp_b_Ptrim) * loctmp_b_Cyp *
    loctmp_b_b / 2.0 / loctmp_b_Utrim + loctmp_b_Cyb * loctmp_beta_k) +
    (loctmp_R_k - loctmp_b_Rtrim) * loctmp_b_Cyr * loctmp_b_b / 2.0 /
    loctmp_b_Utrim) + loctmp_b_Cyda * loctmp_AIL_k) + loctmp_b_Cydr *
    loctmp_RDR_k) * (loctmp_Qbar_k * loctmp_b_S) / loctmp_mass;

  /* [ft/s2] */
  *loctmp_accelZ_scd_k = (-loctmp_CD_k * sin(loctmp_alpha_k) - loctmp_CL_k * cos
                          (loctmp_alpha_k)) * (loctmp_Qbar_k * loctmp_b_S) /
    loctmp_mass;

  /* [ft/s2] */
  /* ANN linear accelerations */
  /* X-axis */
  loctmp_VT_k_2[0] = loctmp_VT_k;
  loctmp_VT_k_2[1] = loctmp_alpha_k;
  loctmp_VT_k_2[2] = loctmp_beta_k;
  loctmp_VT_k_2[3] = loctmp_Q_k;
  loctmp_VT_k_2[4] = loctmp_alphadot_k;
  loctmp_VT_k_2[5] = loctmp_THL_k;
  loctmp_VT_k_2[6] = loctmp_EL_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_2, loctmp_b_X_minXin, loctmp_b_X_maxXin,
    loctmp_b_X_minYin, loctmp_b_X_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_X[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_X[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_X[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelX_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_X,
    loctmp_b_X_minXout, loctmp_b_X_maxXout, loctmp_b_X_minYout,
    loctmp_b_X_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  /* Y_axis */
  loctmp_VT_k_1[0] = loctmp_VT_k;
  loctmp_VT_k_1[1] = loctmp_beta_k;
  loctmp_VT_k_1[2] = loctmp_P_k;
  loctmp_VT_k_1[3] = loctmp_R_k;
  loctmp_VT_k_1[4] = loctmp_betadot_k;
  loctmp_VT_k_1[5] = loctmp_AIL_k;
  loctmp_VT_k_1[6] = loctmp_RDR_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_1, loctmp_b_Y_minXin, loctmp_b_Y_maxXin,
    loctmp_b_Y_minYin, loctmp_b_Y_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_Y[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_Y[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_Y[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelY_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_Y,
    loctmp_b_Y_minXout, loctmp_b_Y_maxXout, loctmp_b_Y_minYout,
    loctmp_b_Y_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  /* Z-axis */
  loctmp_VT_k_0[0] = loctmp_VT_k;
  loctmp_VT_k_0[1] = loctmp_alpha_k;
  loctmp_VT_k_0[2] = loctmp_beta_k;
  loctmp_VT_k_0[3] = loctmp_Q_k;
  loctmp_VT_k_0[4] = loctmp_alphadot_k;
  loctmp_VT_k_0[5] = loctmp_THL_k;
  loctmp_VT_k_0[6] = loctmp_EL_k;
  ANN_EKF_NMPC_2_ann_norm_X(loctmp_VT_k_0, loctmp_b_Z_minXin, loctmp_b_Z_maxXin,
    loctmp_b_Z_minYin, loctmp_b_Z_maxYin, loctmp_tmp);
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a = 0.0;
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      loctmp_r_a += loctmp_w_ann_Z[40 * loctmp_i + loctmp_factor] *
        loctmp_tmp[loctmp_i];
    }

    loctmp_w_ann_X_0[loctmp_factor] = loctmp_r_a + loctmp_b_ann_Z[loctmp_factor];
  }

  loctmp_r_a = 0.0;
  for (loctmp_factor = 0; loctmp_factor < 40; loctmp_factor++) {
    loctmp_r_a += loctmp_a_ann_Z[loctmp_factor] * loctmp_w_ann_X_0[loctmp_factor];
  }

  *loctmp_accelZ_ann_k = ANN_EKF_NMPC_2_ann_denorm_Y(loctmp_r_a + loctmp_c_ann_Z,
    loctmp_b_Z_minXout, loctmp_b_Z_maxXout, loctmp_b_Z_minYout,
    loctmp_b_Z_maxYout) * loctmp_b_g;

  /* [ft/s2] no tansig */
  loctmp_Cls_k = 0.0;

  /* initialization */
  loctmp_Cns_k = 0.0;

  /* initialization */
  loctmp_mass = 0.0;

  /* initialization */
  if (loctmp_FL_ann == 0.0) {
    /* scd */
    loctmp_Cls_k = *loctmp_accelX_scd_k;
    loctmp_Cns_k = *loctmp_accelY_scd_k;
    loctmp_mass = *loctmp_accelZ_scd_k;
  } else {
    if (loctmp_FL_ann == 1.0) {
      /* ann */
      loctmp_Cls_k = *loctmp_accelX_ann_k;
      loctmp_Cns_k = *loctmp_accelY_ann_k;
      loctmp_mass = *loctmp_accelZ_ann_k;
    }
  }

  /* body accelerations */
  loctmp_Udot_k = ((loctmp_R_k * loctmp_V_k - loctmp_Q_k * loctmp_W_k) -
                   loctmp_b_g * sin(loctmp_theta_k)) + loctmp_Cls_k;
  loctmp_Vdot_k = ((loctmp_P_k * loctmp_W_k - loctmp_R_k * loctmp_U_k) +
                   loctmp_b_g * sin(loctmp_phi_k) * cos(loctmp_theta_k)) +
    loctmp_Cns_k;
  loctmp_Wdot_k = ((loctmp_Q_k * loctmp_U_k - loctmp_P_k * loctmp_V_k) +
                   loctmp_b_g * cos(loctmp_phi_k) * cos(loctmp_theta_k)) +
    loctmp_mass;

  /* %inertial speed (with no wind)%% */
  loctmp_fn_k = ((sin(loctmp_phi_k) * sin(loctmp_theta_k) * cos(loctmp_psi_k) -
                  cos(loctmp_phi_k) * sin(loctmp_psi_k)) * loctmp_V_k +
                 loctmp_U_k * cos(loctmp_theta_k) * cos(loctmp_psi_k)) + (cos
    (loctmp_phi_k) * sin(loctmp_theta_k) * cos(loctmp_psi_k) + sin(loctmp_phi_k)
    * sin(loctmp_psi_k)) * loctmp_W_k;
  loctmp_fe_k = ((sin(loctmp_phi_k) * sin(loctmp_theta_k) * sin(loctmp_psi_k) +
                  cos(loctmp_phi_k) * cos(loctmp_psi_k)) * loctmp_V_k +
                 loctmp_U_k * cos(loctmp_theta_k) * sin(loctmp_psi_k)) + (cos
    (loctmp_phi_k) * sin(loctmp_theta_k) * sin(loctmp_psi_k) - sin(loctmp_phi_k)
    * cos(loctmp_psi_k)) * loctmp_W_k;
  loctmp_fh_k = (loctmp_U_k * sin(loctmp_theta_k) - loctmp_V_k * sin
                 (loctmp_phi_k) * cos(loctmp_theta_k)) - loctmp_W_k * cos
    (loctmp_phi_k) * cos(loctmp_theta_k);

  /* %inertial speed%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Local variable assignment */
  loctmp_r_a = rt_roundd_snf(loctmp_wpt_index_k);
  if (loctmp_r_a < 256.0) {
    if (loctmp_r_a >= 0.0) {
      *loctmp_wpt_index_kk = (uint8_T)loctmp_r_a;
    } else {
      *loctmp_wpt_index_kk = 0U;
    }
  } else {
    *loctmp_wpt_index_kk = MAX_uint8_T;
  }

  loctmp_r_a = rt_roundd_snf(loctmp_home_reset_k);
  if (loctmp_r_a < 256.0) {
    if (loctmp_r_a >= 0.0) {
      *loctmp_home_reset_kk = (uint8_T)loctmp_r_a;
    } else {
      *loctmp_home_reset_kk = 0U;
    }
  } else {
    *loctmp_home_reset_kk = MAX_uint8_T;
  }

  /* PIC/CIC Transition Logic: */
  /*  On transition to CIC or PIC, set index = 0 and current position to  */
  /*  current waypoint; hold current waypoint. */
  if ((loctmp_sw > loctmp_pic_cic_k) || (loctmp_sw == 0.0)) {
    loctmp_start_wpt_k[0] = loctmp_h_k;
    loctmp_start_wpt_k[1] = loctmp_n_k;
    loctmp_start_wpt_k[2] = loctmp_e_k;
    *loctmp_wpt_index_kk = 0U;
    *loctmp_home_reset_kk = 0U;
  }

  /*  Change the waypoint index when home command */
  if ((loctmp_home_cmd == 1) && (loctmp_sw == 1.0) && (*loctmp_home_reset_kk ==
       0)) {
    *loctmp_wpt_index_kk = 23U;
    *loctmp_home_reset_kk = 1U;
  }

  /* OP trajectory generation */
  /* %reassigning the a and b waypoints */
  if ((loctmp_b_TR == 2.0) && (*loctmp_home_reset_kk == 0)) {
    *loctmp_wpt_index_kk = 1U;
    loctmp_wpts_n[(int32_T)loctmp_wpt_index_k - 1] = loctmp_n_op_k - 100.0 *
      loctmp_vn_op_k;
    loctmp_wpts_n[(int32_T)(loctmp_wpt_index_k + 1.0) - 1] = 100.0 *
      loctmp_vn_op_k + loctmp_n_op_k;
    loctmp_wpts_e[(int32_T)loctmp_wpt_index_k - 1] = loctmp_e_op_k - 100.0 *
      loctmp_ve_op_k;
    loctmp_wpts_e[(int32_T)(loctmp_wpt_index_k + 1.0) - 1] = 100.0 *
      loctmp_ve_op_k + loctmp_e_op_k;
    loctmp_wpts_h[(int32_T)loctmp_wpt_index_k - 1] = loctmp_h_op_k - 100.0 *
      loctmp_vh_op_k;
    loctmp_wpts_h[(int32_T)(loctmp_wpt_index_k + 1.0) - 1] = 100.0 *
      loctmp_vh_op_k + loctmp_h_op_k;
  }

  /* calculate the next waypoint index */
  loctmp_factor = (int32_T)(*loctmp_wpt_index_kk + 1U);
  if ((uint32_T)loctmp_factor > 255U) {
    loctmp_factor = 255;
  }

  loctmp_next_wpt_index = (uint8_T)loctmp_factor;

  /* beyond final point (fp), go to return point (rp) */
  if ((uint8_T)loctmp_factor > loctmp_wpts_fp) {
    loctmp_next_wpt_index = loctmp_wpts_rp;
  }

  /* calculate distance to next waypoint */
  loctmp_Cls_k = loctmp_n_k - loctmp_wpts_n[loctmp_next_wpt_index - 1];
  loctmp_Cns_k = loctmp_e_k - loctmp_wpts_e[loctmp_next_wpt_index - 1];
  loctmp_Cls_k = sqrt(loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k * loctmp_Cns_k);

  /* change to next waypoint if in range */
  if ((loctmp_Cls_k < loctmp_b_dist2b) && (loctmp_sw == 1.0)) {
    /*  Do not change index if sw=0 */
    *loctmp_wpt_index_kk = loctmp_next_wpt_index;
    if (loctmp_next_wpt_index == loctmp_wpts_fp) {
      loctmp_next_wpt_index = loctmp_wpts_rp;
    } else {
      loctmp_factor = (int32_T)(loctmp_next_wpt_index + 1U);
      if ((uint32_T)loctmp_factor > 255U) {
        loctmp_factor = 255;
      }

      loctmp_next_wpt_index = (uint8_T)loctmp_factor;
    }
  }

  /* function outputs */
  if ((*loctmp_wpt_index_kk == 0) || (*loctmp_wpt_index_kk == 23)) {
    /*  Assign the speed of the starting segment to the speed of the first */
    /*  waypoint */
    *loctmp_Vab_k = loctmp_wpts_v[0];
    loctmp_CL_k = loctmp_start_wpt_k[0];
    loctmp_CD_k = loctmp_start_wpt_k[1];
    loctmp_ea = loctmp_start_wpt_k[2];
  } else {
    *loctmp_Vab_k = loctmp_wpts_v[*loctmp_wpt_index_kk - 1];
    loctmp_CL_k = loctmp_wpts_h[*loctmp_wpt_index_kk - 1];
    loctmp_CD_k = loctmp_wpts_n[*loctmp_wpt_index_kk - 1];
    loctmp_ea = loctmp_wpts_e[*loctmp_wpt_index_kk - 1];
  }

  *loctmp_distance2b = (real32_T)loctmp_Cls_k;
  *loctmp_pic_cic_kk = loctmp_sw;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %reference point r%% */
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_Cls_k = (((loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) *
                   (loctmp_h_k - loctmp_CL_k) +
                   (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) *
                   (loctmp_n_k - loctmp_CD_k)) +
                  (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea) *
                  (loctmp_e_k - loctmp_ea)) / ((loctmp_Cls_k * loctmp_Cls_k +
    loctmp_Cns_k * loctmp_Cns_k) + loctmp_mass * loctmp_mass);
  loctmp_hd_k = (loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) *
    loctmp_Cls_k + loctmp_CL_k;
  loctmp_nd_k = (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) *
    loctmp_Cls_k + loctmp_CD_k;
  loctmp_ed_k = (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea) *
    loctmp_Cls_k + loctmp_ea;
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k;
  loctmp_Cls_k = loctmp_b_L / sqrt((loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_mass * loctmp_mass);
  *loctmp_er_k = (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k) *
    loctmp_Cls_k + loctmp_ed_k;
  *loctmp_nr_k = (loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k) *
    loctmp_Cls_k + loctmp_nd_k;
  *loctmp_hr_k = (loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k) *
    loctmp_Cls_k + loctmp_hd_k;

  /* %alpha and beta track%% */
  loctmp_Cls_k = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k;
  loctmp_Cns_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_mass = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_atrack = asin((loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_CL_k) /
                       sqrt((loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_mass * loctmp_mass));
  loctmp_Cls_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k;
  loctmp_Cns_k = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea;
  loctmp_factor = 1;
  loctmp_mass = 0.0;
  if (!((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k > 0.0) &&
        (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea > 0.0))) {
    if ((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k > 0.0) &&
        (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea < 0.0)) {
      loctmp_mass = 3.1415926535897931;
      loctmp_factor = -1;
    } else {
      if ((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k < 0.0) &&
          (loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ea < 0.0)) {
        loctmp_mass = -3.1415926535897931;
        loctmp_factor = -1;
      }
    }
  }

  loctmp_btrack = asin((loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_CD_k) /
                       sqrt(loctmp_Cls_k * loctmp_Cls_k + loctmp_Cns_k *
    loctmp_Cns_k)) * (real_T)loctmp_factor + loctmp_mass;

  /* %edot, ndot and hdot relative to track%% */
  loctmp_edot_track_k = (sin(loctmp_atrack) * cos(loctmp_btrack) * loctmp_fh_k +
    sin(loctmp_btrack) * loctmp_fn_k) + cos(loctmp_atrack) * cos(loctmp_btrack) *
    loctmp_fe_k;
  loctmp_ndot_track_k = (-sin(loctmp_atrack) * sin(loctmp_btrack) * loctmp_fh_k
    + cos(loctmp_btrack) * loctmp_fn_k) - cos(loctmp_atrack) * sin(loctmp_btrack)
    * loctmp_fe_k;

  /* %er-e, nr-n and hr-h relative to track%% */
  /* %etaLon at time [k]%% */
  loctmp_nr_k_0[0] = *loctmp_nr_k - loctmp_n_k;
  loctmp_nr_k_0[1] = *loctmp_er_k - loctmp_e_k;
  loctmp_fn_k_0[0] = loctmp_fn_k;
  loctmp_fn_k_0[1] = loctmp_fe_k;
  *loctmp_etaLon_k = rt_atan2d_snf(*loctmp_hr_k - loctmp_h_k,
    ANN_EKF_NMPC_2_norm(loctmp_nr_k_0)) - rt_atan2d_snf(loctmp_fh_k,
    ANN_EKF_NMPC_2_norm(loctmp_fn_k_0));

  /* %etaLat at time [k]%% */
  loctmp_Cls_k = rt_atan2d_snf(loctmp_ndot_track_k, loctmp_edot_track_k) -
    rt_atan2d_snf((-sin(loctmp_atrack) * sin(loctmp_btrack) * (*loctmp_hr_k -
    loctmp_h_k) + (*loctmp_nr_k - loctmp_n_k) * cos(loctmp_btrack)) - cos
                  (loctmp_atrack) * sin(loctmp_btrack) * (*loctmp_er_k -
    loctmp_e_k), (sin(loctmp_atrack) * cos(loctmp_btrack) * (*loctmp_hr_k -
    loctmp_h_k) + (*loctmp_nr_k - loctmp_n_k) * sin(loctmp_btrack)) + cos
                  (loctmp_atrack) * cos(loctmp_btrack) * (*loctmp_er_k -
    loctmp_e_k));
  *loctmp_etaLat_k = loctmp_Cls_k;
  if (loctmp_Cls_k > 3.1415926535897931) {
    *loctmp_etaLat_k = loctmp_Cls_k - 6.2831853071795862;
  }

  if (loctmp_Cls_k < -3.1415926535897931) {
    *loctmp_etaLat_k = loctmp_Cls_k + 6.2831853071795862;
  }

  /* OP trajectory generation */
  /* reassigning Vab (based on the new d point) */
  if (loctmp_b_TR == 2.0) {
    loctmp_CL_k = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_n_op_k;
    loctmp_CD_k = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_e_op_k;
    loctmp_ea = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_h_op_k;
    loctmp_r_a = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_nd_k;
    loctmp_s_a = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_ed_k;
    loctmp_t_a = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_hd_k;
    loctmp_mass = loctmp_nd_k - loctmp_n_op_k;
    loctmp_Cns_k = loctmp_ed_k - loctmp_e_op_k;
    loctmp_Cls_k = loctmp_hd_k - loctmp_h_op_k;
    loctmp_r_a = sqrt((loctmp_CL_k * loctmp_CL_k + loctmp_CD_k * loctmp_CD_k) +
                      loctmp_ea * loctmp_ea) - sqrt((loctmp_r_a * loctmp_r_a +
      loctmp_s_a * loctmp_s_a) + loctmp_t_a * loctmp_t_a);
    if (loctmp_r_a < 0.0) {
      loctmp_r_a = -1.0;
    } else if (loctmp_r_a > 0.0) {
      loctmp_r_a = 1.0;
    } else {
      if (loctmp_r_a == 0.0) {
        loctmp_r_a = 0.0;
      }
    }

    *loctmp_Vab_k = sqrt((loctmp_vn_op_k * loctmp_vn_op_k + loctmp_ve_op_k *
                          loctmp_ve_op_k) + loctmp_vh_op_k * loctmp_vh_op_k) -
      atan(sqrt((loctmp_mass * loctmp_mass + loctmp_Cns_k * loctmp_Cns_k) +
                loctmp_Cls_k * loctmp_Cls_k) * loctmp_r_a / 100.0) *
      0.063661977236758135;

    /* (168.78) (5) (/100) */
  }

  /* %VT theta phi and beta command%% */
  /* %consider wind in VTcmd [0]: no [1]:yes */
  loctmp_mass = *loctmp_Vab_k * cos(loctmp_atrack) * sin(loctmp_btrack) + 0.0 *
    loctmp_sw;
  loctmp_Cns_k = *loctmp_Vab_k * cos(loctmp_atrack) * cos(loctmp_btrack) + 0.0 *
    loctmp_sw;
  loctmp_Cls_k = *loctmp_Vab_k * sin(loctmp_atrack) + 0.0 * loctmp_sw;
  *loctmp_VTcmd_k = sqrt((loctmp_mass * loctmp_mass + loctmp_Cns_k *
    loctmp_Cns_k) + loctmp_Cls_k * loctmp_Cls_k);
  loctmp_Cls_k = atan(*loctmp_etaLon_k * loctmp_sw);
  loctmp_er_k_1[0] = *loctmp_er_k - loctmp_e_k;
  loctmp_er_k_1[1] = *loctmp_nr_k - loctmp_n_k;
  loctmp_er_k_1[2] = *loctmp_hr_k - loctmp_h_k;
  *loctmp_thetacmd_k = rt_atan2d_snf(((loctmp_fe_k * loctmp_fe_k + loctmp_fn_k *
    loctmp_fn_k) + loctmp_fh_k * loctmp_fh_k) * 2.0 * (loctmp_Cls_k *
    loctmp_b_KpLon + loctmp_ro_k), ANN_EKF_NMPC_2_norm_h(loctmp_er_k_1));
  loctmp_er_k_0[0] = *loctmp_er_k - loctmp_e_k;
  loctmp_er_k_0[1] = *loctmp_nr_k - loctmp_n_k;
  *loctmp_phicmd_k = rt_atan2d_snf((loctmp_edot_track_k * loctmp_edot_track_k +
    loctmp_ndot_track_k * loctmp_ndot_track_k) * 2.0 * loctmp_b_KpLat *
    loctmp_sw * *loctmp_etaLat_k, ANN_EKF_NMPC_2_norm(loctmp_er_k_0));

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%implementing saturation of actuators%% */
  /* %deflection max and min */
  if (loctmp_THL_k > loctmp_b_ThrottleMax) {
    loctmp_THL_k = loctmp_b_ThrottleMax;
  } else {
    if (loctmp_THL_k < loctmp_b_ThrottleMin) {
      loctmp_THL_k = loctmp_b_ThrottleMin;
    }
  }

  if (loctmp_EL_k > loctmp_b_ElevatorMax) {
    loctmp_EL_k = loctmp_b_ElevatorMax;
  } else {
    if (loctmp_EL_k < loctmp_b_ElevatorMin) {
      loctmp_EL_k = loctmp_b_ElevatorMin;
    }
  }

  if (loctmp_AIL_k > loctmp_b_AileronMax) {
    loctmp_AIL_k = loctmp_b_AileronMax;
  } else {
    if (loctmp_AIL_k < loctmp_b_AileronMin) {
      loctmp_AIL_k = loctmp_b_AileronMin;
    }
  }

  if (loctmp_RDR_k > loctmp_b_RudderMax) {
    loctmp_RDR_k = loctmp_b_RudderMax;
  } else {
    if (loctmp_RDR_k < loctmp_b_RudderMin) {
      loctmp_RDR_k = loctmp_b_RudderMin;
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %longitudinal guidance integrator */
  *loctmp_ro_kk = loctmp_b_dt * loctmp_Cls_k * loctmp_b_KiLon + loctmp_ro_k;

  /* %servos prediction%% */
  *loctmp_THL_kk = (loctmp_b_Athrottle * loctmp_THL_k + loctmp_b_Bthrottle *
                    loctmp_THLcmd_k) * loctmp_b_dt + loctmp_THL_k;
  *loctmp_EL_kk = (loctmp_b_Aelevator * loctmp_EL_k + loctmp_b_Belevator *
                   loctmp_ELcmd_k) * loctmp_b_dt + loctmp_EL_k;
  *loctmp_AIL_kk = (loctmp_b_Aaileron * loctmp_AIL_k + loctmp_b_Baileron *
                    loctmp_AILcmd_k) * loctmp_b_dt + loctmp_AIL_k;
  *loctmp_RDR_kk = (loctmp_b_Arudder * loctmp_RDR_k + loctmp_b_Brudder *
                    loctmp_RDRcmd_k) * loctmp_b_dt + loctmp_RDR_k;

  /* %UAV prediction%% */
  loctmp_Cls_k = ((loctmp_U_k * loctmp_Udot_k + loctmp_V_k * loctmp_Vdot_k) +
                  loctmp_W_k * loctmp_Wdot_k) / loctmp_VT_k;
  *loctmp_falpha_k = (loctmp_U_k * loctmp_Wdot_k - loctmp_W_k * loctmp_Udot_k) /
    (loctmp_U_k * loctmp_U_k + loctmp_W_k * loctmp_W_k);
  *loctmp_fbeta_k = (loctmp_VT_k * loctmp_Vdot_k - loctmp_V_k * loctmp_Cls_k) /
    (loctmp_U_k * loctmp_U_k + loctmp_W_k * loctmp_W_k) * cos(loctmp_beta_k);
  *loctmp_VT_kk = loctmp_b_dt * loctmp_Cls_k + loctmp_VT_k;
  *loctmp_alpha_kk = loctmp_b_dt * *loctmp_falpha_k + loctmp_alpha_k;
  *loctmp_beta_kk = loctmp_b_dt * *loctmp_fbeta_k + loctmp_beta_k;
  *loctmp_phi_kk = ((loctmp_R_k * cos(loctmp_phi_k) + loctmp_Q_k * sin
                     (loctmp_phi_k)) * tan(loctmp_theta_k) + loctmp_P_k) *
    loctmp_b_dt + loctmp_phi_k;
  *loctmp_theta_kk = (loctmp_Q_k * cos(loctmp_phi_k) - loctmp_R_k * sin
                      (loctmp_phi_k)) * loctmp_b_dt + loctmp_theta_k;
  *loctmp_psi_kk = (loctmp_R_k * cos(loctmp_phi_k) + loctmp_Q_k * sin
                    (loctmp_phi_k)) / cos(loctmp_theta_k) * loctmp_b_dt +
    loctmp_psi_k;
  *loctmp_P_kk = ((((loctmp_b_IyyB - loctmp_b_IzzB) * loctmp_b_IzzB -
                    loctmp_b_IxzB * loctmp_b_IxzB) / loctmp_delta_I * loctmp_R_k
                   + loctmp_c2 * loctmp_P_k) * loctmp_Q_k + (loctmp_b_IzzB /
    loctmp_delta_I * loctmp_Cl_k + loctmp_c4 * loctmp_Cn_k) * (loctmp_Qbar_k *
    loctmp_b_S * loctmp_b_b)) * loctmp_b_dt + loctmp_P_k;
  *loctmp_Q_kk = (((loctmp_b_IzzB - loctmp_b_IxxB) / loctmp_b_IyyB * loctmp_P_k *
                   loctmp_R_k - (loctmp_P_k * loctmp_P_k - loctmp_R_k *
    loctmp_R_k) * (loctmp_b_IxzB / loctmp_b_IyyB)) + loctmp_Qbar_k * loctmp_b_S *
                  loctmp_b_Cbar * (1.0 / loctmp_b_IyyB) * loctmp_Cms_k) *
    loctmp_b_dt + loctmp_Q_k;
  *loctmp_R_kk = ((((loctmp_b_IxxB - loctmp_b_IyyB) * loctmp_b_IxxB +
                    loctmp_b_IxzB * loctmp_b_IxzB) / loctmp_delta_I * loctmp_P_k
                   - loctmp_c2 * loctmp_R_k) * loctmp_Q_k + (loctmp_b_IxxB /
    loctmp_delta_I * loctmp_Cn_k + loctmp_c4 * loctmp_Cl_k) * (loctmp_Qbar_k *
    loctmp_b_S * loctmp_b_b)) * loctmp_b_dt + loctmp_R_k;

  /* %inertial frame prediction%% */
  *loctmp_n_kk = loctmp_b_dt * loctmp_fn_k + loctmp_n_k;
  *loctmp_e_kk = loctmp_b_dt * loctmp_fe_k + loctmp_e_k;
  *loctmp_h_kk = loctmp_b_dt * loctmp_fh_k + loctmp_h_k;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %outputs e, y and z%% */
  loctmp_e_augm_k[0] = *loctmp_VTcmd_k - loctmp_VT_k;
  loctmp_e_augm_k[1] = *loctmp_thetacmd_k - loctmp_theta_k;
  loctmp_e_augm_k[2] = *loctmp_phicmd_k - loctmp_phi_k;
  loctmp_e_augm_k[3] = 0.0 - loctmp_beta_k;

  /* %Robustness states at [k+1]%% */
  *loctmp_xw11_kk = loctmp_b_W11d.a * loctmp_xw11_k + loctmp_b_W11d.b *
    loctmp_e_augm_k[0];

  /* W11 e_VT */
  *loctmp_xw12_kk = loctmp_b_W12d.a * loctmp_xw12_k + loctmp_b_W12d.b *
    loctmp_e_augm_k[1];

  /* W12 e_theta */
  *loctmp_xw13_kk = loctmp_b_W13d.a * loctmp_xw13_k + loctmp_b_W13d.b *
    loctmp_e_augm_k[2];

  /* W13 e_phi */
  *loctmp_xw14_kk = (0.0 - loctmp_beta_k) * loctmp_b_W14d.b + loctmp_b_W14d.a *
    loctmp_xw14_k;

  /* W14 e_beta */
  *loctmp_xw21_kk = loctmp_b_W21d.a * loctmp_xw21_k + loctmp_b_W21d.b *
    loctmp_THLcmd_k;

  /* W21 Throttle cmd */
  *loctmp_xw22_kk = loctmp_b_W22d.a * loctmp_xw22_k + loctmp_b_W22d.b *
    loctmp_ELcmd_k;

  /* W22 Elevator cmd */
  *loctmp_xw23_kk = loctmp_b_W23d.a * loctmp_xw23_k + loctmp_b_W23d.b *
    loctmp_AILcmd_k;

  /* W23 Aileron cmd */
  *loctmp_xw24_kk = loctmp_b_W24d.a * loctmp_xw24_k + loctmp_b_W24d.b *
    loctmp_RDRcmd_k;

  /* W24 Rudder cmd */
  *loctmp_xw31_kk = loctmp_b_W31d.a * loctmp_xw31_k + loctmp_b_W31d.b *
    loctmp_VT_k;

  /* W31 VT */
  *loctmp_xw32_kk = loctmp_b_W32d.a * loctmp_xw32_k + loctmp_b_W32d.b *
    loctmp_theta_k;

  /* W32 theta */
  *loctmp_xw33_kk = loctmp_b_W33d.a * loctmp_xw33_k + loctmp_b_W33d.b *
    loctmp_phi_k;

  /* W33 phi */
  *loctmp_xw34_kk = loctmp_b_W34d.a * loctmp_xw34_k + loctmp_b_W34d.b *
    loctmp_beta_k;

  /* W34 beta */
  /* %Robustness output at [k] */
  loctmp_z_augm_k[0] = loctmp_b_W11d.c * loctmp_xw11_k + loctmp_b_W11d.d *
    loctmp_e_augm_k[0];

  /* W11 e_VT */
  loctmp_z_augm_k[1] = loctmp_b_W12d.c * loctmp_xw12_k + loctmp_b_W12d.d *
    loctmp_e_augm_k[1];

  /* W12 e_theta */
  loctmp_z_augm_k[2] = loctmp_b_W13d.c * loctmp_xw13_k + loctmp_b_W13d.d *
    loctmp_e_augm_k[2];

  /* W13 e_phi */
  loctmp_z_augm_k[3] = (0.0 - loctmp_beta_k) * loctmp_b_W14d.d + loctmp_b_W14d.c
    * loctmp_xw14_k;

  /* W14 e_beta */
  loctmp_z_augm_k[4] = loctmp_b_W21d.c * loctmp_xw21_k + loctmp_b_W21d.d *
    loctmp_THLcmd_k;

  /* W21 Throttle cmd */
  loctmp_z_augm_k[5] = loctmp_b_W22d.c * loctmp_xw22_k + loctmp_b_W22d.d *
    loctmp_ELcmd_k;

  /* W22 Elevator cmd */
  loctmp_z_augm_k[6] = loctmp_b_W23d.c * loctmp_xw23_k + loctmp_b_W23d.d *
    loctmp_AILcmd_k;

  /* W23 Aileron cmd */
  loctmp_z_augm_k[7] = loctmp_b_W24d.c * loctmp_xw24_k + loctmp_b_W24d.d *
    loctmp_RDRcmd_k;

  /* W24 Rudder cmd */
  loctmp_z_augm_k[8] = loctmp_b_W31d.c * loctmp_xw31_k + loctmp_b_W31d.d *
    loctmp_VT_k;

  /* W31 VT */
  loctmp_z_augm_k[9] = loctmp_b_W32d.c * loctmp_xw32_k + loctmp_b_W32d.d *
    loctmp_theta_k;

  /* W32 theta */
  loctmp_z_augm_k[10] = loctmp_b_W33d.c * loctmp_xw33_k + loctmp_b_W33d.d *
    loctmp_phi_k;

  /* W33 phi */
  loctmp_z_augm_k[11] = loctmp_b_W34d.c * loctmp_xw34_k + loctmp_b_W34d.d *
    loctmp_beta_k;

  /* W34 beta */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
}

/* Model step function */
void ANN_EKF_NMPC_2_step(void)
{
  /* local block i/o variables */
  ControlSurfaceDeflections locvar_BusCreator3;
  real_T locvar_Add1_pe;
  real_T locvar_Add_htd;
  real_T locvar_Add_fm;
  real_T locvar_Azb;
  real_T locvar_Axb;
  real_T locvar_Ayb;
  real_T locvar_Azb_d;
  real_T locvar_Axb_d;
  real_T locvar_Ayb_f;
  real_T locvar_Azb_j;
  real_T locvar_Axb_f;
  real_T locvar_Ayb_fd;
  real_T locvar_Azb_jr;
  real_T locvar_Axb_k;
  real_T locvar_Ayb_d;
  real_T locvar_Azb_c;
  real_T locvar_Axb_m;
  real_T locvar_Ayb_i;
  real_T locvar_Azb_dq;
  real_T locvar_Axb_dd;
  real_T locvar_Ayb_j;
  real_T locvar_Azb_k;
  real_T locvar_Axb_p;
  real_T locvar_Ayb_b;
  real_T locvar_Azb_n;
  real_T locvar_Axb_h;
  real_T locvar_Ayb_n;
  real_T locvar_Azb_l;
  real_T locvar_Axb_mh;
  real_T locvar_Ayb_n3;
  real_T locvar_Azb_o;
  real_T locvar_Axb_i;
  real_T locvar_Ayb_o;
  real_T locvar_Azb_oy;
  real_T locvar_Axb_m3;
  real_T locvar_Ayb_g;
  real_T locvar_Azb_jc;
  real_T locvar_Axb_l;
  real_T locvar_Ayb_h;
  real_T locvar_Azb_e;
  real_T locvar_Axb_c;
  real_T locvar_Ayb_a;
  real_T locvar_Add1_i5;
  real_T locvar_Add_cih;
  real_T locvar_Add1_ktx;
  real_T locvar_Add_c1;
  real_T locvar_Gain_o5[2];
  real_T locvar_V_height;
  real_T locvar_V_north_c;
  real_T locvar_V_east_b;
  real_T locvar_edot_track;
  real_T locvar_ndot_track;
  real_T locvar_hdot_track;
  real_T locvar_Subtract2_e;
  real_T locvar_Subtract4;
  real_T locvar_Subtract5;
  real_T locvar_er_e;
  real_T locvar_nr_n;
  real_T locvar_hr_h;
  real_T locvar_er_e_track;
  real_T locvar_nr_n_track;
  real_T locvar_hr_h_track;
  real_T locvar_Add1_c0;
  real_T locvar_Add2_koh;
  real_T locvar_Add4_dr;
  real_T locvar_OutportBufferForV_nmpc;
  real_T locvar_z1_k;
  real_T locvar_z2_k;
  real_T locvar_z3_k;
  real_T locvar_z4_k;
  real_T locvar_z5_k;
  real_T locvar_z6_k;
  real_T locvar_z7_k;
  real_T locvar_z8_k;
  real_T locvar_z9_k;
  real_T locvar_z10_k;
  real_T locvar_z11_k;
  real_T locvar_z12_k;
  real_T locvar_distance;
  real_T locvar_DataStoreRead7_p[7];
  real_T locvar_DataStoreRead9_l[7];
  real_T locvar_DataStoreRead8_a[7];
  real_T locvar_OutportBufferForV_ann_X;
  real_T locvar_OutportBufferForV_ann_Y;
  real_T locvar_OutportBufferForV_ann_Z;
  uint8_T locvar_FixPtSwitch;
  boolean_T locvar_LogicalOperator;
  boolean_T locvar_LogicalOperator_h;
  ZCEventType loctmp_zcEvent;
  real_T loctmp_b_b;
  real_T loctmp_wpts_h[32];
  real_T loctmp_wpts_n[32];
  real_T loctmp_wpts_e[32];
  uint8_T loctmp_b_index;
  uint8_T loctmp_next_wpt_index;
  real_T loctmp_distance;
  boolean_T loctmp_home_cmd;
  real_T loctmp_b_KiLon;
  real_T loctmp_b_KpLon;
  real_T loctmp_b_L;
  real_T loctmp_b_dist2b;
  real_T loctmp_z_augm_hor[252];
  real_T loctmp_u_hor[84];
  real_T loctmp_n_hor[21];
  real_T loctmp_e_hor[21];
  real_T loctmp_h_hor[21];
  real_T loctmp_THL_hor[21];
  real_T loctmp_EL_hor[21];
  real_T loctmp_AIL_hor[21];
  real_T loctmp_RDR_hor[21];
  real_T loctmp_VT_hor[21];
  real_T loctmp_alpha_hor[21];
  real_T loctmp_beta_hor[21];
  real_T loctmp_phi_hor[21];
  real_T loctmp_theta_hor[21];
  real_T loctmp_psi_hor[21];
  real_T loctmp_P_hor[21];
  real_T loctmp_Q_hor[21];
  real_T loctmp_R_hor[21];
  real_T loctmp_wpt_index_hor[21];
  real_T loctmp_start_wpt_hor[63];
  real_T loctmp_pic_cic_hor[21];
  real_T loctmp_home_reset_hor[21];
  real_T loctmp_alphadot_hor[21];
  real_T loctmp_betadot_hor[21];
  real_T loctmp_ro_hor[21];
  real_T loctmp_xw11_hor[21];
  real_T loctmp_xw12_hor[21];
  real_T loctmp_xw13_hor[21];
  real_T loctmp_xw14_hor[21];
  real_T loctmp_xw21_hor[21];
  real_T loctmp_xw22_hor[21];
  real_T loctmp_xw23_hor[21];
  real_T loctmp_xw24_hor[21];
  real_T loctmp_xw31_hor[21];
  real_T loctmp_xw32_hor[21];
  real_T loctmp_xw33_hor[21];
  real_T loctmp_xw34_hor[21];
  real32_T loctmp_unusedU0;
  uint8_T loctmp_c;
  uint8_T loctmp_f;
  real_T loctmp_h[12];
  real_T loctmp_i[4];
  real_T locvar_x_est_k1k1_m[6];
  real_T locvar_Add2_ga;
  real_T locvar_Divide_ad;
  real_T locvar_Add2_db;
  real_T locvar_ManualSwitch_ap;
  real_T locvar_Add2_o3;
  real_T locvar_ManualSwitch_ds;
  real_T locvar_Add_b1;
  real_T locvar_ManualSwitch_d4;
  real_T locvar_Add1_md;
  real_T locvar_Divide_je;
  real_T locvar_Add1_ir;
  real_T locvar_Divide4_ky;
  real_T locvar_Add_eqw;
  real_T locvar_Add2_ap;
  real_T locvar_Add2_fi;
  real_T locvar_Divide1_ip[6];
  real_T locvar_Divide2_gle[6];
  real_T locvar_Product1_i0[6];
  real_T locvar_Reshape2[6];
  real_T locvar_North;
  uint8_T locvar_FixPtRelationalOperator;
  real_T locvar_Latitude;
  real_T locvar_Longitude;
  real_T locvar_Altitude;
  real_T locvar_V_north;
  real_T locvar_V_east;
  real_T locvar_V_down;
  real_T locvar_x_est_k1k1[14];
  real_T locvar_Divide4_c1v;
  real_T locvar_Divide;
  real_T locvar_ManualSwitch_co;
  real_T locvar_ManualSwitch_i1;
  real_T locvar_Divide_j0;
  real_T locvar_Add_nwv;
  real_T locvar_ManualSwitch_hd;
  real_T locvar_ManualSwitch_jq;
  real_T locvar_ManualSwitch_na;
  real_T locvar_Divide4_kga;
  real_T locvar_ManualSwitch_i;
  real_T locvar_Divide3_bc;
  real_T locvar_ManualSwitch_ga;
  real_T locvar_Divide4_mgn;
  real_T locvar_ManualSwitch_ce;
  real_T locvar_Divide5_ni;
  real_T locvar_ManualSwitch_if;
  real_T locvar_Divide_o;
  real_T locvar_Divide3_hfk;
  real_T locvar_Divide4_ng;
  real_T locvar_MathFunction_e;
  real_T locvar_MathFunction1_bt;
  real_T locvar_Add1_cl;
  real_T locvar_ManualSwitch_h5;
  real_T locvar_ManualSwitch_py;
  real_T locvar_ManualSwitch_b;
  real_T locvar_ManualSwitch_gl;
  real_T locvar_Add_mtb;
  real_T locvar_Divide_em;
  real_T locvar_Add1_j2;
  real_T locvar_Add_oq1;
  real_T locvar_Divide4_ch;
  real_T locvar_Divide_p3;
  real_T locvar_ManualSwitch_e4;
  real_T locvar_ManualSwitch_k5;
  real_T locvar_ManualSwitch_oa;
  real_T locvar_ManualSwitch_c;
  real_T locvar_Divide1_gv[14];
  real_T locvar_Add1_cn2;
  real_T locvar_Divide4_m3;
  real_T locvar_Divide3_b10;
  real_T locvar_Divide4_nh;
  real_T locvar_Divide5_pq;
  real_T locvar_Divide_f5;
  real_T locvar_Divide3_jze;
  real_T locvar_Divide4_ncd;
  real_T locvar_MathFunction_pp;
  real_T locvar_MathFunction1_jr;
  real_T locvar_Add1_ef;
  real_T locvar_ManualSwitch_il;
  real_T locvar_ManualSwitch_p0l;
  real_T locvar_Add_ccv;
  real_T locvar_Divide_prh;
  real_T locvar_Add1_es;
  real_T locvar_Add_ifv;
  real_T locvar_Add1_lq2;
  real_T locvar_Divide4_ko;
  real_T locvar_Divide3_npq;
  real_T locvar_Divide4_lhf;
  real_T locvar_Divide5_ol;
  real_T locvar_Divide_hc;
  real_T locvar_Divide3_io;
  real_T locvar_Divide4_fy;
  real_T locvar_MathFunction_iy;
  real_T locvar_MathFunction1_cr;
  real_T locvar_Add1_k4;
  real_T locvar_ManualSwitch_ex;
  real_T locvar_ManualSwitch_li;
  real_T locvar_ManualSwitch_d;
  real_T locvar_Add_mx3;
  real_T locvar_Divide_dc;
  real_T locvar_Add1_e0;
  real_T locvar_Add_df5;
  real_T locvar_Divide_en;
  real_T locvar_ManualSwitch_h2;
  real_T locvar_ManualSwitch_lz;
  real_T locvar_ManualSwitch_m;
  real_T locvar_Divide4_ok[14];
  real_T locvar_Divide4_ipd;
  real_T locvar_Divide3_mnp;
  real_T locvar_Divide4_jr4;
  real_T locvar_Divide5_nv;
  real_T locvar_Divide_ml;
  real_T locvar_Divide3_at;
  real_T locvar_Divide4_h3;
  real_T locvar_MathFunction_hi4;
  real_T locvar_MathFunction1_ed;
  real_T locvar_Add1_co;
  real_T locvar_ManualSwitch_p;
  real_T locvar_Divide4_dh;
  real_T locvar_ManualSwitch_bs;
  real_T locvar_Add_cn;
  real_T locvar_Divide_jg;
  real_T locvar_Add1_dy;
  real_T locvar_Add_nl;
  real_T locvar_Add_ow;
  real_T locvar_Divide4_m3z;
  real_T locvar_Divide3_ef;
  real_T locvar_Divide4_j0a;
  real_T locvar_Divide5_dki;
  real_T locvar_Divide_hvn;
  real_T locvar_Divide3_poh;
  real_T locvar_Divide4_hl4;
  real_T locvar_MathFunction_ld;
  real_T locvar_MathFunction1_j;
  real_T locvar_Add1_ot;
  real_T locvar_ManualSwitch_c0;
  real_T locvar_ManualSwitch_pp;
  real_T locvar_Azb_h;
  real_T locvar_Add_jbj;
  real_T locvar_Divide_b;
  real_T locvar_Add1_i0;
  real_T locvar_Add_oj;
  real_T locvar_Divide4_hvl;
  real_T locvar_Divide3_p0a;
  real_T locvar_Divide4_i0;
  real_T locvar_Divide5_luy;
  real_T locvar_Divide_hz;
  real_T locvar_Divide3_n5;
  real_T locvar_Divide4_pem;
  real_T locvar_MathFunction_p2;
  real_T locvar_MathFunction1_ot;
  real_T locvar_Add_me;
  real_T locvar_TrigonometricFunction1_d5j;
  real_T locvar_TrigonometricFunction2_lt;
  real_T locvar_Add1_jqe;
  real_T locvar_ManualSwitch_le;
  real_T locvar_ManualSwitch_e;
  real_T locvar_Add2_ai;
  real_T locvar_Add_ay;
  real_T locvar_Divide_ft;
  real_T locvar_Add1_mq;
  real_T locvar_Add_bs;
  real_T locvar_Divide4_dt;
  real_T locvar_Divide3_bt;
  real_T locvar_Divide4_fqv;
  real_T locvar_Divide5_ny;
  real_T locvar_Divide_n;
  real_T locvar_Divide3_ai5;
  real_T locvar_Divide4_ik;
  real_T locvar_MathFunction_bv;
  real_T locvar_MathFunction1_id;
  real_T locvar_Saturation_m;
  real_T locvar_Add1_ety;
  real_T locvar_ManualSwitch_cx;
  real_T locvar_Ayb_k;
  real_T locvar_ManualSwitch_dl;
  real_T locvar_Add_ez;
  real_T locvar_Divide_n0;
  real_T locvar_Add1_pkj;
  real_T locvar_Add_df3;
  real_T locvar_Divide4_kz;
  real_T locvar_Divide3_oc;
  real_T locvar_Add_ev;
  real_T locvar_Divide4_oem;
  real_T locvar_Divide5_kh;
  real_T locvar_Divide_c;
  real_T locvar_Divide3_j0;
  real_T locvar_Divide4_afp;
  real_T locvar_MathFunction_di;
  real_T locvar_MathFunction1_e4;
  real_T locvar_Add1_o3;
  real_T locvar_TrigonometricFunction_m2;
  real_T locvar_Axb_e;
  real_T locvar_Divide2_op;
  real_T locvar_Add_au;
  real_T locvar_Divide_aa;
  real_T locvar_Add1_ob;
  real_T locvar_Add_pii;
  real_T locvar_Divide_k2;
  real_T locvar_TrigonometricFunction2_ly;
  real_T locvar_TrigonometricFunction4_ef;
  real_T locvar_TrigonometricFunction5_h0;
  real_T locvar_TrigonometricFunction3_p;
  real_T locvar_Reshape1[14];
  real_T locvar_Divide_jpd;
  real_T locvar_Divide2_ic;
  real_T locvar_Divide2_em;
  real_T locvar_Divide_ow;
  real_T loctmp_locvar_BusCreator1_psi;
  real_T locvar_Divide3_ik;
  real_T locvar_Divide4_ii;
  real_T locvar_Divide2_h2o;
  real_T locvar_Divide6_d5;
  real_T locvar_Divide5_cg1;
  real_T locvar_ManualSwitch_gd;
  real_T locvar_ManualSwitch_n;
  real_T locvar_ManualSwitch;
  real_T locvar_Add_kq;
  real_T locvar_Delay100dt;
  int32_T locvar_DataTypeConversion1;
  real_T locvar_Height_k;
  real_T locvar_North_e;
  real_T locvar_East_k;
  real_T locvar_start_wpt_mem[3];
  real_T locvar_TSamp;
  real_T locvar_TSamp_j;
  real_T loctmp_tmp;
  real_T loctmp_tmp_0;
  real_T locvar_Vab_mod;
  real_T locvar_xw11_k;
  real_T locvar_xw12_k;
  real_T locvar_xw13_k;
  real_T locvar_xw14_k;
  real_T locvar_xw21_k;
  real_T locvar_xw22_k;
  real_T locvar_xw23_k;
  real_T locvar_xw24_k;
  real_T locvar_xw31_k;
  real_T locvar_xw32_k;
  real_T locvar_xw33_k;
  real_T locvar_xw34_k;
  real_T locvar_Gain_ar;
  real_T locvar_Product3_j[36];
  real_T locvar_P_kk1[36];
  real_T locvar_Product1_b[36];
  real_T locvar_Gain4_dz[196];
  real_T locvar_P_kk1_m[196];
  real_T locvar_Product2_d[196];
  real_T locvar_Reshape[112];
  real_T locvar_Product1_oh[112];
  real_T locvar_Add_p[36];
  real_T locvar_Add_o[196];
  real_T locvar_DataStoreRead11[40];
  real_T locvar_DataStoreRead6_o[40];
  real_T locvar_b_ann_X_out[40];
  real_T locvar_b_ann_Y_out[40];
  real_T locvar_a_ann_Y_out[40];
  real_T locvar_w_ann_Y_out[280];
  real_T locvar_a_ann_X_out[40];
  real_T locvar_w_ann_X_out[280];
  real_T locvar_b_ann_Z_out[40];
  real_T locvar_a_ann_Z_out[40];
  real_T locvar_w_ann_Z_out[280];
  real_T locvar_x_ann_Y_out[49];
  real_T locvar_x_ann_X_out[49];
  real_T locvar_x_ann_Z_out[49];
  real_T locvar_y_ann_X_out[7];
  real_T locvar_y_ann_Y_out[7];
  real_T locvar_y_ann_Z_out[7];
  real_T locvar_DataStoreRead2_p[84];
  real_T locvar_HT_k[112];
  int32_T loctmp_i_0;
  real_T loctmp_tmp_1[32];
  real_T loctmp_tmp_2[32];
  real_T loctmp_tmp_3[32];
  real_T loctmp_locvar_Reshape[64];
  int32_T loctmp_i_1;
  real_T loctmp_locvar_Product1_b[36];
  real_T loctmp_tmp_4[36];
  real_T loctmp_locvar_FixPtRelationalOperator[6];
  real_T loctmp_locvar_Product2_c[196];
  real_T loctmp_locvar_P_kk1_m[112];
  real_T loctmp_locvar_Reshape_0[64];
  real_T loctmp_tmp_5[8];
  real_T loctmp_locvar_Divide1_h5[8];
  real_T loctmp_tmp_6[8];
  real_T loctmp_locvar_DataStoreRead1_m_idx_0;
  real_T loctmp_locvar_DataStoreRead1_m_idx_1;
  real_T loctmp_locvar_DataStoreRead1_m_idx_2;
  real_T loctmp_locvar_DataStoreRead1_m_idx_3;
  real_T loctmp_tmp_7;

  /* Gain: '<S84>/Gain' incorporates:
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Add2_ga = ANN_EKF_NMPC_2_P.Gain_Gain_or *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3];

  /* Gain: '<S82>/Gain' incorporates:
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Divide_ad = ANN_EKF_NMPC_2_P.Gain_Gain_h *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4];

  /* Gain: '<S83>/Gain' incorporates:
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Add2_db = ANN_EKF_NMPC_2_P.Gain_Gain_b *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5];

  /* Trigonometry: '<S81>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ap = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S81>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S81>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S81>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add_b1 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S81>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_d4 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S81>/Add2' incorporates:
   *  Product: '<S81>/Divide1'
   *  Product: '<S81>/Divide2'
   *  Product: '<S81>/Divide3'
   *  Product: '<S81>/Divide4'
   *  Product: '<S81>/Divide5'
   *  Product: '<S81>/Divide6'
   *  Product: '<S81>/Divide7'
   *  Sum: '<S81>/Add1'
   *  Sum: '<S81>/Add3'
   *  Trigonometry: '<S81>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_d4 = ((locvar_Add_b1 * locvar_ManualSwitch_d4 *
    locvar_ManualSwitch_ap - locvar_Add2_o3 * locvar_ManualSwitch_ds) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_ManualSwitch_ap) +
    (locvar_Add_b1 * locvar_Add2_o3 * locvar_ManualSwitch_ap +
     locvar_ManualSwitch_d4 * locvar_ManualSwitch_ds) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S79>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add_b1 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S79>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S79>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S79>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ap = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S79>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_md = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S79>/Add2' incorporates:
   *  Product: '<S79>/Divide1'
   *  Product: '<S79>/Divide2'
   *  Product: '<S79>/Divide3'
   *  Product: '<S79>/Divide4'
   *  Product: '<S79>/Divide5'
   *  Product: '<S79>/Divide6'
   *  Product: '<S79>/Divide7'
   *  Sum: '<S79>/Add1'
   *  Sum: '<S79>/Add3'
   *  Trigonometry: '<S79>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_md = ((locvar_ManualSwitch_ap * locvar_Add1_md * locvar_Add_b1 +
                     locvar_ManualSwitch_ds * locvar_Add2_o3) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Add_b1) +
    (locvar_ManualSwitch_ap * locvar_ManualSwitch_ds * locvar_Add_b1 -
     locvar_Add1_md * locvar_Add2_o3) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Sum: '<S80>/Sum' incorporates:
   *  Constant: '<S80>/gravity'
   *  Product: '<S80>/Divide1'
   *  Product: '<S80>/Divide2'
   *  Product: '<S80>/Divide3'
   *  Sum: '<S80>/Add1'
   *  Trigonometry: '<S80>/Trigonometric Function'
   *  Trigonometry: '<S80>/Trigonometric Function1'
   *  Trigonometry: '<S80>/Trigonometric Function2'
   *  Trigonometry: '<S80>/Trigonometric Function4'
   *  Trigonometry: '<S80>/Trigonometric Function5'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add_b1 = ((ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * sin
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) - cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * sin
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4]) - cos
                   (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) * cos
                   (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
                   ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5]) - ANN_EKF_NMPC_2_P.g;

  /* Trigonometry: '<S102>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S102>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S102>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S102>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add_eqw = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S102>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_ap = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S102>/Add2' incorporates:
   *  Product: '<S102>/Divide1'
   *  Product: '<S102>/Divide2'
   *  Product: '<S102>/Divide3'
   *  Product: '<S102>/Divide4'
   *  Product: '<S102>/Divide5'
   *  Product: '<S102>/Divide6'
   *  Product: '<S102>/Divide7'
   *  Sum: '<S102>/Add1'
   *  Sum: '<S102>/Add3'
   *  Trigonometry: '<S102>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_ap = ((locvar_Add_eqw * locvar_Add2_ap * locvar_Divide_je -
                     locvar_Add1_ir * locvar_Divide4_ky) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Divide_je)
    + (locvar_Add_eqw * locvar_Add1_ir * locvar_Divide_je + locvar_Add2_ap *
       locvar_Divide4_ky) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S100>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add_eqw = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S100>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S100>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S100>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S100>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_fi = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S100>/Add2' incorporates:
   *  Product: '<S100>/Divide1'
   *  Product: '<S100>/Divide2'
   *  Product: '<S100>/Divide3'
   *  Product: '<S100>/Divide4'
   *  Product: '<S100>/Divide5'
   *  Product: '<S100>/Divide6'
   *  Product: '<S100>/Divide7'
   *  Sum: '<S100>/Add1'
   *  Sum: '<S100>/Add3'
   *  Trigonometry: '<S100>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_fi = ((locvar_Divide_je * locvar_Add2_fi * locvar_Add_eqw +
                     locvar_Divide4_ky * locvar_Add1_ir) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Add_eqw) +
    (locvar_Divide_je * locvar_Divide4_ky * locvar_Add_eqw - locvar_Add2_fi *
     locvar_Add1_ir) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S88>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S88>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S88>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S88>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S88>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S88>/Add2' incorporates:
   *  Product: '<S88>/Divide1'
   *  Product: '<S88>/Divide2'
   *  Product: '<S88>/Divide3'
   *  Product: '<S88>/Divide4'
   *  Product: '<S88>/Divide5'
   *  Product: '<S88>/Divide6'
   *  Product: '<S88>/Divide7'
   *  Sum: '<S88>/Add1'
   *  Sum: '<S88>/Add3'
   *  Trigonometry: '<S88>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = ((locvar_ManualSwitch_ds * locvar_Add2_o3 *
                        locvar_Divide4_ky - locvar_Add1_ir * locvar_Divide_je) *
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                       (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
                       locvar_Divide4_ky) + (locvar_ManualSwitch_ds *
    locvar_Add1_ir * locvar_Divide4_ky + locvar_Add2_o3 * locvar_Divide_je) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S86>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S86>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S86>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S86>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S86>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ap = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S86>/Add2' incorporates:
   *  Product: '<S86>/Divide1'
   *  Product: '<S86>/Divide2'
   *  Product: '<S86>/Divide3'
   *  Product: '<S86>/Divide4'
   *  Product: '<S86>/Divide5'
   *  Product: '<S86>/Divide6'
   *  Product: '<S86>/Divide7'
   *  Sum: '<S86>/Add1'
   *  Sum: '<S86>/Add3'
   *  Trigonometry: '<S86>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = ((locvar_Add2_o3 * locvar_ManualSwitch_ap * locvar_Add1_ir +
                     locvar_Divide_je * locvar_ManualSwitch_ds) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Add1_ir) +
    (locvar_Add2_o3 * locvar_Divide_je * locvar_Add1_ir - locvar_ManualSwitch_ap
     * locvar_ManualSwitch_ds) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Product: '<S61>/Divide1' incorporates:
   *  Constant: '<S61>/delta'
   *  Constant: '<S87>/gravity'
   *  Gain: '<S89>/Gain'
   *  Gain: '<S90>/Gain'
   *  Gain: '<S91>/Gain'
   *  Product: '<S87>/Divide1'
   *  Product: '<S87>/Divide2'
   *  Product: '<S87>/Divide3'
   *  Sum: '<S61>/Sum1'
   *  Sum: '<S87>/Add1'
   *  Sum: '<S87>/Sum'
   *  Trigonometry: '<S87>/Trigonometric Function'
   *  Trigonometry: '<S87>/Trigonometric Function1'
   *  Trigonometry: '<S87>/Trigonometric Function2'
   *  Trigonometry: '<S87>/Trigonometric Function4'
   *  Trigonometry: '<S87>/Trigonometric Function5'
   *  UnitDelay: '<S50>/Unit Delay1'
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Divide1_ip[0] = (ANN_EKF_NMPC_2_P.Gain_Gain_am *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3] - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide1_ip[1] = (ANN_EKF_NMPC_2_P.Gain_Gain_bs *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4] - locvar_Divide_ad) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide1_ip[2] = (ANN_EKF_NMPC_2_P.Gain_Gain_f4 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5] - locvar_Add2_db) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide1_ip[3] = (locvar_Divide4_ky - locvar_ManualSwitch_d4) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide1_ip[4] = (locvar_Add1_ir - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide1_ip[5] = ((((ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5]) - ANN_EKF_NMPC_2_P.g) -
    locvar_Add_b1) / ANN_EKF_NMPC_2_P.delta_Value;

  /* Trigonometry: '<S95>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S95>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S95>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S95>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S95>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S95>/Add2' incorporates:
   *  Product: '<S95>/Divide1'
   *  Product: '<S95>/Divide2'
   *  Product: '<S95>/Divide3'
   *  Product: '<S95>/Divide4'
   *  Product: '<S95>/Divide5'
   *  Product: '<S95>/Divide6'
   *  Product: '<S95>/Divide7'
   *  Sum: '<S95>/Add1'
   *  Sum: '<S95>/Add3'
   *  Trigonometry: '<S95>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = ((locvar_ManualSwitch_ds * locvar_Add2_o3 *
                        locvar_Divide4_ky - locvar_Add1_ir * locvar_Divide_je) *
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                       (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
                       locvar_Divide4_ky) + (locvar_ManualSwitch_ds *
    locvar_Add1_ir * locvar_Divide4_ky + locvar_Add2_o3 * locvar_Divide_je) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S93>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S93>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S93>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S93>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S93>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ap = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S93>/Add2' incorporates:
   *  Product: '<S93>/Divide1'
   *  Product: '<S93>/Divide2'
   *  Product: '<S93>/Divide3'
   *  Product: '<S93>/Divide4'
   *  Product: '<S93>/Divide5'
   *  Product: '<S93>/Divide6'
   *  Product: '<S93>/Divide7'
   *  Sum: '<S93>/Add1'
   *  Sum: '<S93>/Add3'
   *  Trigonometry: '<S93>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = ((locvar_Add2_o3 * locvar_ManualSwitch_ap * locvar_Add1_ir +
                     locvar_Divide_je * locvar_ManualSwitch_ds) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Add1_ir) +
    (locvar_Add2_o3 * locvar_Divide_je * locvar_Add1_ir - locvar_ManualSwitch_ap
     * locvar_ManualSwitch_ds) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Product: '<S61>/Divide2' incorporates:
   *  Constant: '<S61>/delta'
   *  Constant: '<S94>/gravity'
   *  Gain: '<S96>/Gain'
   *  Gain: '<S97>/Gain'
   *  Gain: '<S98>/Gain'
   *  Product: '<S94>/Divide1'
   *  Product: '<S94>/Divide2'
   *  Product: '<S94>/Divide3'
   *  Sum: '<S61>/Sum2'
   *  Sum: '<S94>/Add1'
   *  Sum: '<S94>/Sum'
   *  Trigonometry: '<S94>/Trigonometric Function'
   *  Trigonometry: '<S94>/Trigonometric Function1'
   *  Trigonometry: '<S94>/Trigonometric Function2'
   *  Trigonometry: '<S94>/Trigonometric Function4'
   *  Trigonometry: '<S94>/Trigonometric Function5'
   *  UnitDelay: '<S50>/Unit Delay1'
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Divide2_gle[0] = (ANN_EKF_NMPC_2_P.Gain_Gain_c *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3] - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide2_gle[1] = (ANN_EKF_NMPC_2_P.Gain_Gain_o0 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4] - locvar_Divide_ad) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide2_gle[2] = (ANN_EKF_NMPC_2_P.Gain_Gain_fs *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5] - locvar_Add2_db) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide2_gle[3] = (locvar_Divide4_ky - locvar_ManualSwitch_d4) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide2_gle[4] = (locvar_Add1_ir - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Divide2_gle[5] = ((((ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5]) - ANN_EKF_NMPC_2_P.g) -
    locvar_Add_b1) / ANN_EKF_NMPC_2_P.delta_Value;

  /* Trigonometry: '<S123>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S123>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S123>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S123>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S123>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S123>/Add2' incorporates:
   *  Product: '<S123>/Divide1'
   *  Product: '<S123>/Divide2'
   *  Product: '<S123>/Divide3'
   *  Product: '<S123>/Divide4'
   *  Product: '<S123>/Divide5'
   *  Product: '<S123>/Divide6'
   *  Product: '<S123>/Divide7'
   *  Sum: '<S123>/Add1'
   *  Sum: '<S123>/Add3'
   *  Trigonometry: '<S123>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = ((locvar_ManualSwitch_ds * locvar_Add2_o3 *
                        locvar_Divide4_ky - locvar_Add1_ir * locvar_Divide_je) *
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                       (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
                       locvar_Divide4_ky) + (locvar_ManualSwitch_ds *
    locvar_Add1_ir * locvar_Divide4_ky + locvar_Add2_o3 * locvar_Divide_je) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S121>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S121>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S121>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S121>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S121>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ap = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S121>/Add2' incorporates:
   *  Product: '<S121>/Divide1'
   *  Product: '<S121>/Divide2'
   *  Product: '<S121>/Divide3'
   *  Product: '<S121>/Divide4'
   *  Product: '<S121>/Divide5'
   *  Product: '<S121>/Divide6'
   *  Product: '<S121>/Divide7'
   *  Sum: '<S121>/Add1'
   *  Sum: '<S121>/Add3'
   *  Trigonometry: '<S121>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = ((locvar_Add2_o3 * locvar_ManualSwitch_ap * locvar_Add1_ir +
                     locvar_Divide_je * locvar_ManualSwitch_ds) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Add1_ir) +
    (locvar_Add2_o3 * locvar_Divide_je * locvar_Add1_ir - locvar_ManualSwitch_ap
     * locvar_ManualSwitch_ds) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Product: '<S61>/Divide3' incorporates:
   *  Constant: '<S122>/gravity'
   *  Constant: '<S61>/delta'
   *  Gain: '<S124>/Gain'
   *  Gain: '<S125>/Gain'
   *  Gain: '<S126>/Gain'
   *  Product: '<S122>/Divide1'
   *  Product: '<S122>/Divide2'
   *  Product: '<S122>/Divide3'
   *  Sum: '<S122>/Add1'
   *  Sum: '<S122>/Sum'
   *  Sum: '<S61>/Sum3'
   *  Sum: '<S70>/Add'
   *  Trigonometry: '<S122>/Trigonometric Function'
   *  Trigonometry: '<S122>/Trigonometric Function1'
   *  Trigonometry: '<S122>/Trigonometric Function2'
   *  Trigonometry: '<S122>/Trigonometric Function4'
   *  Trigonometry: '<S122>/Trigonometric Function5'
   *  UnitDelay: '<S50>/Unit Delay1'
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Product1_i0[0] = ((ANN_EKF_NMPC_2_P.delta_Value +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3]) * ANN_EKF_NMPC_2_P.Gain_Gain_gz -
    locvar_Add2_ga) / ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Product1_i0[1] = (ANN_EKF_NMPC_2_P.Gain_Gain_j *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4] - locvar_Divide_ad) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Product1_i0[2] = (ANN_EKF_NMPC_2_P.Gain_Gain_jn *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5] - locvar_Add2_db) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Product1_i0[3] = (locvar_Divide4_ky - locvar_ManualSwitch_d4) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Product1_i0[4] = (locvar_Add1_ir - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Product1_i0[5] = ((((ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5]) - ANN_EKF_NMPC_2_P.g) -
    locvar_Add_b1) / ANN_EKF_NMPC_2_P.delta_Value;

  /* Trigonometry: '<S109>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S109>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S109>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S109>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S109>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S109>/Add2' incorporates:
   *  Product: '<S109>/Divide1'
   *  Product: '<S109>/Divide2'
   *  Product: '<S109>/Divide3'
   *  Product: '<S109>/Divide4'
   *  Product: '<S109>/Divide5'
   *  Product: '<S109>/Divide6'
   *  Product: '<S109>/Divide7'
   *  Sum: '<S109>/Add1'
   *  Sum: '<S109>/Add3'
   *  Trigonometry: '<S109>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = ((locvar_ManualSwitch_ds * locvar_Add2_o3 *
                        locvar_Divide4_ky - locvar_Add1_ir * locvar_Divide_je) *
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                       (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
                       locvar_Divide4_ky) + (locvar_ManualSwitch_ds *
    locvar_Add1_ir * locvar_Divide4_ky + locvar_Add2_o3 * locvar_Divide_je) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S107>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S107>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S107>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S107>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S107>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ap = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S107>/Add2' incorporates:
   *  Product: '<S107>/Divide1'
   *  Product: '<S107>/Divide2'
   *  Product: '<S107>/Divide3'
   *  Product: '<S107>/Divide4'
   *  Product: '<S107>/Divide5'
   *  Product: '<S107>/Divide6'
   *  Product: '<S107>/Divide7'
   *  Sum: '<S107>/Add1'
   *  Sum: '<S107>/Add3'
   *  Trigonometry: '<S107>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = ((locvar_Add2_o3 * locvar_ManualSwitch_ap * locvar_Add1_ir +
                     locvar_Divide_je * locvar_ManualSwitch_ds) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Add1_ir) +
    (locvar_Add2_o3 * locvar_Divide_je * locvar_Add1_ir - locvar_ManualSwitch_ap
     * locvar_ManualSwitch_ds) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Product: '<S61>/Divide4' incorporates:
   *  Constant: '<S108>/gravity'
   *  Constant: '<S61>/delta'
   *  Gain: '<S110>/Gain'
   *  Gain: '<S111>/Gain'
   *  Gain: '<S112>/Gain'
   *  Product: '<S108>/Divide1'
   *  Product: '<S108>/Divide2'
   *  Product: '<S108>/Divide3'
   *  Sum: '<S108>/Add1'
   *  Sum: '<S108>/Sum'
   *  Sum: '<S61>/Sum4'
   *  Sum: '<S68>/Add'
   *  Trigonometry: '<S108>/Trigonometric Function'
   *  Trigonometry: '<S108>/Trigonometric Function1'
   *  Trigonometry: '<S108>/Trigonometric Function2'
   *  Trigonometry: '<S108>/Trigonometric Function4'
   *  Trigonometry: '<S108>/Trigonometric Function5'
   *  UnitDelay: '<S50>/Unit Delay1'
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Reshape2[0] = (ANN_EKF_NMPC_2_P.Gain_Gain_mn *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3] - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Reshape2[1] = ((ANN_EKF_NMPC_2_P.delta_Value +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4]) * ANN_EKF_NMPC_2_P.Gain_Gain_bv -
                        locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Reshape2[2] = (ANN_EKF_NMPC_2_P.Gain_Gain_kf *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5] - locvar_Add2_db) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Reshape2[3] = (locvar_Divide4_ky - locvar_ManualSwitch_d4) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Reshape2[4] = (locvar_Add1_ir - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value;
  locvar_Reshape2[5] = ((((ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5]) - ANN_EKF_NMPC_2_P.g) -
                        locvar_Add_b1) / ANN_EKF_NMPC_2_P.delta_Value;

  /* Trigonometry: '<S116>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S116>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S116>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S116>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S116>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S116>/Add2' incorporates:
   *  Product: '<S116>/Divide1'
   *  Product: '<S116>/Divide2'
   *  Product: '<S116>/Divide3'
   *  Product: '<S116>/Divide4'
   *  Product: '<S116>/Divide5'
   *  Product: '<S116>/Divide6'
   *  Product: '<S116>/Divide7'
   *  Sum: '<S116>/Add1'
   *  Sum: '<S116>/Add3'
   *  Trigonometry: '<S116>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide4_ky = ((locvar_ManualSwitch_ds * locvar_Add2_o3 *
                        locvar_Divide4_ky - locvar_Add1_ir * locvar_Divide_je) *
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                       ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                       (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
                       locvar_Divide4_ky) + (locvar_ManualSwitch_ds *
    locvar_Add1_ir * locvar_Divide4_ky + locvar_Add2_o3 * locvar_Divide_je) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S114>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S114>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Divide_je = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S114>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S114>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S114>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ap = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S114>/Add2' incorporates:
   *  Product: '<S114>/Divide1'
   *  Product: '<S114>/Divide2'
   *  Product: '<S114>/Divide3'
   *  Product: '<S114>/Divide4'
   *  Product: '<S114>/Divide5'
   *  Product: '<S114>/Divide6'
   *  Product: '<S114>/Divide7'
   *  Sum: '<S114>/Add1'
   *  Sum: '<S114>/Add3'
   *  Trigonometry: '<S114>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_ir = ((locvar_Add2_o3 * locvar_ManualSwitch_ap * locvar_Add1_ir +
                     locvar_Divide_je * locvar_ManualSwitch_ds) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Add1_ir) +
    (locvar_Add2_o3 * locvar_Divide_je * locvar_Add1_ir - locvar_ManualSwitch_ap
     * locvar_ManualSwitch_ds) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Gain: '<S61>/Gain4' incorporates:
   *  Constant: '<S101>/gravity'
   *  Constant: '<S115>/gravity'
   *  Constant: '<S61>/delta'
   *  Gain: '<S103>/Gain'
   *  Gain: '<S104>/Gain'
   *  Gain: '<S105>/Gain'
   *  Gain: '<S117>/Gain'
   *  Gain: '<S118>/Gain'
   *  Gain: '<S119>/Gain'
   *  Product: '<S101>/Divide1'
   *  Product: '<S101>/Divide2'
   *  Product: '<S101>/Divide3'
   *  Product: '<S115>/Divide1'
   *  Product: '<S115>/Divide2'
   *  Product: '<S115>/Divide3'
   *  Product: '<S61>/Divide'
   *  Product: '<S61>/Divide5'
   *  Reshape: '<S61>/Reshape'
   *  Sum: '<S101>/Add1'
   *  Sum: '<S101>/Sum'
   *  Sum: '<S115>/Add1'
   *  Sum: '<S115>/Sum'
   *  Sum: '<S61>/Sum'
   *  Sum: '<S61>/Sum5'
   *  Sum: '<S69>/Add1'
   *  Trigonometry: '<S101>/Trigonometric Function'
   *  Trigonometry: '<S101>/Trigonometric Function1'
   *  Trigonometry: '<S101>/Trigonometric Function2'
   *  Trigonometry: '<S101>/Trigonometric Function4'
   *  Trigonometry: '<S101>/Trigonometric Function5'
   *  Trigonometry: '<S115>/Trigonometric Function'
   *  Trigonometry: '<S115>/Trigonometric Function1'
   *  Trigonometry: '<S115>/Trigonometric Function2'
   *  Trigonometry: '<S115>/Trigonometric Function4'
   *  Trigonometry: '<S115>/Trigonometric Function5'
   *  UnitDelay: '<S50>/Unit Delay1'
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Product3_j[0] = (ANN_EKF_NMPC_2_P.Gain_Gain_pe *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3] - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[1] = (ANN_EKF_NMPC_2_P.Gain_Gain_aw *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4] - locvar_Divide_ad) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[2] = (ANN_EKF_NMPC_2_P.Gain_Gain_bt *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5] - locvar_Add2_db) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[3] = (locvar_Add2_ap - locvar_ManualSwitch_d4) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[4] = (locvar_Add2_fi - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[5] = ((((ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5]) - ANN_EKF_NMPC_2_P.g) -
    locvar_Add_b1) / ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
    locvar_x_est_k1k1_m[loctmp_i_0] =
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[loctmp_i_0];
    locvar_Product3_j[loctmp_i_0 + 6] = ANN_EKF_NMPC_2_P.dt *
      locvar_Divide1_ip[loctmp_i_0];
  }

  for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
    locvar_Product3_j[loctmp_i_0 + 12] = ANN_EKF_NMPC_2_P.dt *
      locvar_Divide2_gle[loctmp_i_0];
  }

  for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
    locvar_Product3_j[loctmp_i_0 + 18] = ANN_EKF_NMPC_2_P.dt *
      locvar_Product1_i0[loctmp_i_0];
  }

  for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
    locvar_Product3_j[loctmp_i_0 + 24] = ANN_EKF_NMPC_2_P.dt *
      locvar_Reshape2[loctmp_i_0];
  }

  locvar_Product3_j[30] = (ANN_EKF_NMPC_2_P.Gain_Gain_by *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3] - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[31] = (ANN_EKF_NMPC_2_P.Gain_Gain_ne *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4] - locvar_Divide_ad) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[32] = ((ANN_EKF_NMPC_2_P.delta_Value +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5]) * ANN_EKF_NMPC_2_P.Gain_Gain_be -
    locvar_Add2_db) / ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[33] = (locvar_Divide4_ky - locvar_ManualSwitch_d4) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[34] = (locvar_Add1_ir - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;
  locvar_Product3_j[35] = ((((ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5]) - ANN_EKF_NMPC_2_P.g) -
    locvar_Add_b1) / ANN_EKF_NMPC_2_P.delta_Value * ANN_EKF_NMPC_2_P.dt;

  /* End of Gain: '<S61>/Gain4' */

  /* Product: '<S64>/Matrix Multiply' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      locvar_P_kk1[loctmp_i_1 + 6 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        locvar_P_kk1[loctmp_i_1 + 6 * loctmp_i_0] += locvar_Product3_j[6 *
          locvar_DataTypeConversion1 + loctmp_i_1] * locvar_Product3_j[6 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* End of Product: '<S64>/Matrix Multiply' */

  /* Product: '<S64>/Matrix Multiply1' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] += locvar_P_kk1[6 *
          locvar_DataTypeConversion1 + loctmp_i_1] * locvar_Product3_j[6 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* End of Product: '<S64>/Matrix Multiply1' */

  /* Product: '<S64>/Matrix Multiply2' incorporates:
   *  Gain: '<S64>/Gain2'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      loctmp_locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        loctmp_locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] +=
          locvar_Product1_b[6 * locvar_DataTypeConversion1 + loctmp_i_1] *
          locvar_Product3_j[6 * loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* End of Product: '<S64>/Matrix Multiply2' */

  /* Sum: '<S64>/Add' incorporates:
   *  Constant: '<S64>/Constant'
   *  Gain: '<S64>/Gain'
   *  Gain: '<S64>/Gain1'
   *  Gain: '<S64>/Gain2'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      locvar_Add_p[loctmp_i_0 + 6 * loctmp_i_1] =
        (((ANN_EKF_NMPC_2_P.Constant_Value_i[6 * loctmp_i_1 + loctmp_i_0] +
           locvar_Product3_j[6 * loctmp_i_1 + loctmp_i_0]) + locvar_P_kk1[6 *
          loctmp_i_1 + loctmp_i_0] * ANN_EKF_NMPC_2_P.Gain_Gain_hu) +
         locvar_Product1_b[6 * loctmp_i_1 + loctmp_i_0] *
         ANN_EKF_NMPC_2_P.Gain1_Gain_d) + loctmp_locvar_Product1_b[6 *
        loctmp_i_1 + loctmp_i_0] * ANN_EKF_NMPC_2_P.Gain2_Gain_c;
    }
  }

  /* End of Sum: '<S64>/Add' */

  /* Product: '<S56>/Product1' incorporates:
   *  MATLAB Function: '<S56>/Transpose'
   *  UnitDelay: '<S56>/P_est_[0//0]'
   */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/EKF/K[k] (navigation)/Transpose': '<S63>:1' */
  /* '<S63>:1:4' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      loctmp_tmp_4[loctmp_i_1 + 6 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        loctmp_tmp_4[loctmp_i_1 + 6 * loctmp_i_0] +=
          ANN_EKF_NMPC_2_DW.P_est_00_DSTATE[6 * locvar_DataTypeConversion1 +
          loctmp_i_1] * locvar_Add_p[6 * locvar_DataTypeConversion1 + loctmp_i_0];
      }
    }
  }

  /* Sum: '<S56>/Subtract1' incorporates:
   *  Constant: '<S56>/Q_[k-1]'
   *  Product: '<S56>/Product1'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      loctmp_tmp_7 = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        loctmp_tmp_7 += locvar_Add_p[6 * locvar_DataTypeConversion1 + loctmp_i_1]
          * loctmp_tmp_4[6 * loctmp_i_0 + locvar_DataTypeConversion1];
      }

      locvar_P_kk1[loctmp_i_1 + 6 * loctmp_i_0] = ANN_EKF_NMPC_2_P.Q_obs_nav[6 *
        loctmp_i_0 + loctmp_i_1] + loctmp_tmp_7;
    }
  }

  /* End of Sum: '<S56>/Subtract1' */

  /* MATLAB Function: '<S62>/Transpose' incorporates:
   *  Constant: '<S56>/H_[k]'
   */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/EKF/K[k] (navigation)/K_[k]/Transpose': '<S128>:1' */
  /* '<S128>:1:4' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      locvar_Product3_j[loctmp_i_0 + 6 * loctmp_i_1] =
        ANN_EKF_NMPC_2_P.H_k_Value[6 * loctmp_i_0 + loctmp_i_1];
    }
  }

  /* End of MATLAB Function: '<S62>/Transpose' */

  /* Product: '<S62>/Product' */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/EKF/K[k] (navigation)/K_[k]/Inverse': '<S127>:1' */
  /* '<S127>:1:4' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      loctmp_locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        loctmp_locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] += locvar_P_kk1[6 *
          locvar_DataTypeConversion1 + loctmp_i_1] * locvar_Product3_j[6 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* Sum: '<S62>/Subtract2' incorporates:
   *  Constant: '<S56>/H_[k]'
   *  Constant: '<S56>/R_[k]'
   *  Product: '<S62>/Product'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      loctmp_tmp_7 = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        loctmp_tmp_7 += ANN_EKF_NMPC_2_P.H_k_Value[6 *
          locvar_DataTypeConversion1 + loctmp_i_1] * loctmp_locvar_Product1_b[6 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }

      loctmp_tmp_4[loctmp_i_1 + 6 * loctmp_i_0] = ANN_EKF_NMPC_2_P.R_obs_nav[6 *
        loctmp_i_0 + loctmp_i_1] + loctmp_tmp_7;
    }
  }

  memcpy(&loctmp_locvar_Product1_b[0], &loctmp_tmp_4[0], 36U * sizeof(real_T));

  /* End of Sum: '<S62>/Subtract2' */

  /* MATLAB Function: '<S62>/Inverse' */
  ANN_EKF_NMPC_2_invNxN_c(loctmp_locvar_Product1_b, loctmp_tmp_4);

  /* Product: '<S62>/Product1' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      loctmp_locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        loctmp_locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] +=
          locvar_Product3_j[6 * locvar_DataTypeConversion1 + loctmp_i_1] *
          loctmp_tmp_4[6 * loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        locvar_Product1_b[loctmp_i_1 + 6 * loctmp_i_0] += locvar_P_kk1[6 *
          locvar_DataTypeConversion1 + loctmp_i_1] * loctmp_locvar_Product1_b[6 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* End of Product: '<S62>/Product1' */

  /* MATLAB Function: '<S51>/Convert Lat//Lon//Alt to Flat Earth' incorporates:
   *  Inport: '<Root>/GPS Position meas'
   */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/GPS to Local/Convert Lat//Lon//Alt to Flat Earth': '<S137>:1' */
  /*  Convert the given LLA coordinates to Flat Earth coordinates. */
  /*  */
  /*  ref_alt - meters ASML */
  /*  ref_lat - deg. */
  /*  ref_lon - deg. */
  /*  */
  /*  Height, North, East are in feet */
  /* '<S137>:1:11' */
  /* '<S137>:1:12' */
  locvar_North = (ANN_EKF_NMPC_2_U.GPSPositionmeas.Latitude -
                  ANN_EKF_NMPC_2_P.inertial_local_data.ref_lat) *
    ANN_EKF_NMPC_2_P.inertial_local_data.fact_lat;

  /* Trigonometry: '<S132>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  /* '<S137>:1:13' */
  locvar_Add1_md = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S132>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_d4 = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S132>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add_b1 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S132>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S132>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S132>/Add2' incorporates:
   *  Product: '<S132>/Divide1'
   *  Product: '<S132>/Divide2'
   *  Product: '<S132>/Divide3'
   *  Product: '<S132>/Divide4'
   *  Product: '<S132>/Divide5'
   *  Product: '<S132>/Divide6'
   *  Product: '<S132>/Divide7'
   *  Sum: '<S132>/Add1'
   *  Sum: '<S132>/Add3'
   *  Trigonometry: '<S132>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add1_md = ((locvar_ManualSwitch_ds * locvar_Add2_o3 * locvar_Add1_md -
                     locvar_ManualSwitch_d4 * locvar_Add_b1) *
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
                    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
                    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_Add1_md) +
    (locvar_ManualSwitch_ds * locvar_ManualSwitch_d4 * locvar_Add1_md +
     locvar_Add2_o3 * locvar_Add_b1) * ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Trigonometry: '<S130>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_d4 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S130>/Trigonometric Function5' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add_b1 = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Trigonometry: '<S130>/Trigonometric Function4' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ds = cos(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2]);

  /* Trigonometry: '<S130>/Trigonometric Function2' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_Add2_o3 = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]);

  /* Trigonometry: '<S130>/Trigonometric Function' incorporates:
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_ap = sin(ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]);

  /* Sum: '<S130>/Add2' incorporates:
   *  Product: '<S130>/Divide1'
   *  Product: '<S130>/Divide2'
   *  Product: '<S130>/Divide3'
   *  Product: '<S130>/Divide4'
   *  Product: '<S130>/Divide5'
   *  Product: '<S130>/Divide6'
   *  Product: '<S130>/Divide7'
   *  Sum: '<S130>/Add1'
   *  Sum: '<S130>/Add3'
   *  Trigonometry: '<S130>/Trigonometric Function1'
   *  UnitDelay: '<S50>/Unit Delay1'
   */
  locvar_ManualSwitch_d4 = ((locvar_Add2_o3 * locvar_ManualSwitch_ap *
    locvar_ManualSwitch_d4 + locvar_Add_b1 * locvar_ManualSwitch_ds) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] +
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * locvar_ManualSwitch_d4) +
    (locvar_Add2_o3 * locvar_Add_b1 * locvar_ManualSwitch_d4 -
     locvar_ManualSwitch_ap * locvar_ManualSwitch_ds) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5];

  /* Sum: '<S57>/Subtract1' incorporates:
   *  Constant: '<S131>/gravity'
   *  Gain: '<S133>/Gain'
   *  Gain: '<S134>/Gain'
   *  Gain: '<S135>/Gain'
   *  Gain: '<S57>/Gain4'
   *  Product: '<S131>/Divide1'
   *  Product: '<S131>/Divide2'
   *  Product: '<S131>/Divide3'
   *  Sum: '<S131>/Add1'
   *  Sum: '<S131>/Sum'
   *  Trigonometry: '<S131>/Trigonometric Function'
   *  Trigonometry: '<S131>/Trigonometric Function1'
   *  Trigonometry: '<S131>/Trigonometric Function2'
   *  Trigonometry: '<S131>/Trigonometric Function4'
   *  Trigonometry: '<S131>/Trigonometric Function5'
   *  UnitDelay: '<S50>/Unit Delay1'
   *  UnitDelay: '<S50>/x_est_[0//0]'
   */
  locvar_Divide1_ip[0] = ANN_EKF_NMPC_2_P.Gain_Gain_en *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3] * ANN_EKF_NMPC_2_P.dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[0];
  locvar_Divide1_ip[1] = ANN_EKF_NMPC_2_P.Gain_Gain_fm *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4] * ANN_EKF_NMPC_2_P.dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[1];
  locvar_Divide1_ip[2] = ANN_EKF_NMPC_2_P.Gain_Gain_n2 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5] * ANN_EKF_NMPC_2_P.dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[2];
  locvar_Divide1_ip[3] = ANN_EKF_NMPC_2_P.dt * locvar_Add1_md +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[3];
  locvar_Divide1_ip[4] = ANN_EKF_NMPC_2_P.dt * locvar_ManualSwitch_d4 +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[4];
  locvar_Divide1_ip[5] = (((ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) * sin
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4]) - cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0]) * cos
    (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1]) *
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5]) - ANN_EKF_NMPC_2_P.g) *
    ANN_EKF_NMPC_2_P.dt + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[5];

  /* RelationalOperator: '<S60>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S60>/Delay Input1'
   */
  locvar_FixPtRelationalOperator = (uint8_T)(locvar_North !=
    ANN_EKF_NMPC_2_DW.DelayInput1_DSTATE);

  /* Switch: '<S55>/Switch' */
  if (locvar_FixPtRelationalOperator > ANN_EKF_NMPC_2_P.Switch_Threshold) {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Sum: '<S50>/Subtract'
     */
    loctmp_locvar_FixPtRelationalOperator[0] = locvar_North - locvar_Divide1_ip
      [0];
  } else {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Constant: '<S55>/Constant'
     */
    loctmp_locvar_FixPtRelationalOperator[0] = ANN_EKF_NMPC_2_P.Constant_Value_m;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Switch: '<S55>/Switch1' */
  if (locvar_FixPtRelationalOperator > ANN_EKF_NMPC_2_P.Switch1_Threshold) {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Inport: '<Root>/GPS Position meas'
     *  MATLAB Function: '<S51>/Convert Lat//Lon//Alt to Flat Earth'
     *  Sum: '<S50>/Subtract'
     */
    loctmp_locvar_FixPtRelationalOperator[1] =
      (ANN_EKF_NMPC_2_U.GPSPositionmeas.Longitude -
       ANN_EKF_NMPC_2_P.inertial_local_data.ref_lon) *
      ANN_EKF_NMPC_2_P.inertial_local_data.fact_lon - locvar_Divide1_ip[1];
  } else {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Constant: '<S55>/Constant'
     */
    loctmp_locvar_FixPtRelationalOperator[1] = ANN_EKF_NMPC_2_P.Constant_Value_m;
  }

  /* End of Switch: '<S55>/Switch1' */

  /* Switch: '<S55>/Switch2' */
  if (locvar_FixPtRelationalOperator > ANN_EKF_NMPC_2_P.Switch2_Threshold) {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Inport: '<Root>/GPS Position meas'
     *  MATLAB Function: '<S51>/Convert Lat//Lon//Alt to Flat Earth'
     *  Sum: '<S50>/Subtract'
     */
    loctmp_locvar_FixPtRelationalOperator[2] =
      (ANN_EKF_NMPC_2_U.GPSPositionmeas.Altitude -
       ANN_EKF_NMPC_2_P.inertial_local_data.ref_alt) * 3.280839895013123 -
      locvar_Divide1_ip[2];
  } else {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Constant: '<S55>/Constant'
     */
    loctmp_locvar_FixPtRelationalOperator[2] = ANN_EKF_NMPC_2_P.Constant_Value_m;
  }

  /* End of Switch: '<S55>/Switch2' */

  /* Switch: '<S55>/Switch3' */
  if (locvar_FixPtRelationalOperator > ANN_EKF_NMPC_2_P.Switch3_Threshold) {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Gain: '<S51>/Gain3'
     *  Inport: '<Root>/GPS Velocity meas'
     *  Sum: '<S50>/Subtract'
     */
    loctmp_locvar_FixPtRelationalOperator[3] = ANN_EKF_NMPC_2_P.Gain3_Gain_c *
      ANN_EKF_NMPC_2_U.GPSVelocitymeas.V_north - locvar_Divide1_ip[3];
  } else {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Constant: '<S55>/Constant'
     */
    loctmp_locvar_FixPtRelationalOperator[3] = ANN_EKF_NMPC_2_P.Constant_Value_m;
  }

  /* End of Switch: '<S55>/Switch3' */

  /* Switch: '<S55>/Switch4' */
  if (locvar_FixPtRelationalOperator > ANN_EKF_NMPC_2_P.Switch4_Threshold) {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Gain: '<S51>/Gain4'
     *  Inport: '<Root>/GPS Velocity meas'
     *  Sum: '<S50>/Subtract'
     */
    loctmp_locvar_FixPtRelationalOperator[4] = ANN_EKF_NMPC_2_P.Gain4_Gain_l *
      ANN_EKF_NMPC_2_U.GPSVelocitymeas.V_east - locvar_Divide1_ip[4];
  } else {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Constant: '<S55>/Constant'
     */
    loctmp_locvar_FixPtRelationalOperator[4] = ANN_EKF_NMPC_2_P.Constant_Value_m;
  }

  /* End of Switch: '<S55>/Switch4' */

  /* Switch: '<S55>/Switch5' */
  if (locvar_FixPtRelationalOperator > ANN_EKF_NMPC_2_P.Switch5_Threshold) {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Gain: '<S51>/Gain1'
     *  Gain: '<S51>/Gain2'
     *  Inport: '<Root>/GPS Velocity meas'
     *  Sum: '<S50>/Subtract'
     */
    loctmp_locvar_FixPtRelationalOperator[5] = ANN_EKF_NMPC_2_P.Gain1_Gain_n *
      ANN_EKF_NMPC_2_U.GPSVelocitymeas.V_down * ANN_EKF_NMPC_2_P.Gain2_Gain_i -
      locvar_Divide1_ip[5];
  } else {
    /* Reshape: '<S50>/Reshape2' incorporates:
     *  Constant: '<S55>/Constant'
     */
    loctmp_locvar_FixPtRelationalOperator[5] = ANN_EKF_NMPC_2_P.Constant_Value_m;
  }

  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    /* Product: '<S50>/Product1' incorporates:
     *  Gain: '<S50>/Gain'
     *  Inport: '<Root>/Enable//Disable'
     *  Product: '<S50>/Product'
     */
    locvar_Divide2_gle[loctmp_i_1] = 0.0;
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      locvar_Divide2_gle[loctmp_i_1] += locvar_Product1_b[6 * loctmp_i_0 +
        loctmp_i_1] * (real_T)ANN_EKF_NMPC_2_U.EnableDisable *
        loctmp_locvar_FixPtRelationalOperator[loctmp_i_0];
    }

    /* End of Product: '<S50>/Product1' */

    /* Sum: '<S50>/Subtract1' incorporates:
     *  Gain: '<S50>/Gain'
     */
    locvar_Divide1_ip[loctmp_i_1] += ANN_EKF_NMPC_2_P.Gain_Gain_gc *
      locvar_Divide2_gle[loctmp_i_1];
  }

  /* End of Switch: '<S55>/Switch5' */

  /* MATLAB Function: '<S52>/Convert Local Coordinates to LLA' incorporates:
   *  Reshape: '<S50>/Reshape3'
   */
  /* MATLAB Function 'Navigation Observer Yak54 40\% (subsystem)/Navigation Observer/Local Position to GPS Position/Convert Local Coordinates to LLA': '<S138>:1' */
  /* '<S138>:1:4' */
  locvar_Latitude = locvar_Divide1_ip[0] /
    ANN_EKF_NMPC_2_P.inertial_local_data.fact_lat +
    ANN_EKF_NMPC_2_P.inertial_local_data.ref_lat;

  /* '<S138>:1:5' */
  locvar_Longitude = locvar_Divide1_ip[1] /
    ANN_EKF_NMPC_2_P.inertial_local_data.fact_lon +
    ANN_EKF_NMPC_2_P.inertial_local_data.ref_lon;

  /* '<S138>:1:6' */
  locvar_Altitude = locvar_Divide1_ip[2] * 0.3048 +
    ANN_EKF_NMPC_2_P.inertial_local_data.ref_alt;

  /* Gain: '<S53>/Gain2' incorporates:
   *  Reshape: '<S50>/Reshape3'
   */
  locvar_V_north = ANN_EKF_NMPC_2_P.Gain2_Gain_l * locvar_Divide1_ip[3];

  /* Gain: '<S53>/Gain1' incorporates:
   *  Reshape: '<S50>/Reshape3'
   */
  locvar_V_east = ANN_EKF_NMPC_2_P.Gain1_Gain_h * locvar_Divide1_ip[4];

  /* Gain: '<S53>/Gain3' incorporates:
   *  Reshape: '<S50>/Reshape3'
   */
  locvar_V_down = ANN_EKF_NMPC_2_P.Gain3_Gain_i * locvar_Divide1_ip[5];

  /* UnitDelay: '<S146>/x_est_[0//0]' */
  memcpy(&locvar_x_est_k1k1[0], &ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0], 14U *
         sizeof(real_T));

  /* Saturate: '<S181>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Sum: '<S181>/Add' incorporates:
   *  Gain: '<S181>/Gain'
   *  Gain: '<S181>/Gain1'
   *  Saturate: '<S181>/Throttle Limiter'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_fi = ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];

  /* Saturate: '<S181>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Sum: '<S181>/Add1' incorporates:
   *  Gain: '<S181>/Gain2'
   *  Gain: '<S181>/Gain3'
   *  Saturate: '<S181>/Elevator Limiter'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_ap = ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1];

  /* Saturate: '<S181>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Sum: '<S181>/Add2' incorporates:
   *  Gain: '<S181>/Gain4'
   *  Gain: '<S181>/Gain5'
   *  Saturate: '<S181>/Aileron Limiter'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add_eqw = ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2];

  /* Saturate: '<S181>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Sum: '<S181>/Add3' incorporates:
   *  Gain: '<S181>/Gain6'
   *  Gain: '<S181>/Gain7'
   *  Saturate: '<S181>/Rudder Limiter'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ky = ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Product: '<S188>/Divide2' incorporates:
   *  Trigonometry: '<S188>/Trigonometric Function'
   *  Trigonometry: '<S188>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_ir = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S190>/Divide2' incorporates:
   *  Trigonometry: '<S190>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide_je = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S193>/Divide2' incorporates:
   *  Trigonometry: '<S193>/Trigonometric Function'
   *  Trigonometry: '<S193>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_md = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S185>/Divide4' incorporates:
   *  Constant: '<S185>/Constant'
   *  Constant: '<S185>/Constant1'
   *  Math: '<S185>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_c1v = ANN_EKF_NMPC_2_P.Constant_Value_iy *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S204>/Add' incorporates:
   *  Constant: '<S204>/Constant'
   *  Constant: '<S204>/Constant1'
   *  Constant: '<S204>/Constant10'
   *  Constant: '<S204>/Constant11'
   *  Constant: '<S204>/Constant12'
   *  Constant: '<S204>/Constant13'
   *  Constant: '<S204>/Constant14'
   *  Constant: '<S204>/Constant15'
   *  Constant: '<S204>/Constant2'
   *  Constant: '<S204>/Constant3'
   *  Constant: '<S204>/Constant4'
   *  Constant: '<S204>/Constant5'
   *  Constant: '<S204>/Constant6'
   *  Constant: '<S204>/Constant7'
   *  Constant: '<S204>/Constant8'
   *  Constant: '<S204>/Constant9'
   *  Gain: '<S204>/Gain1'
   *  Gain: '<S204>/Gain2'
   *  Gain: '<S204>/Gain3'
   *  Product: '<S204>/Divide1'
   *  Product: '<S204>/Divide2'
   *  Product: '<S204>/Divide3'
   *  Product: '<S204>/Divide4'
   *  Product: '<S204>/Divide5'
   *  Product: '<S204>/Divide6'
   *  Product: '<S204>/Divide7'
   *  Sum: '<S204>/Add1'
   *  Sum: '<S204>/Add2'
   *  Sum: '<S204>/Add3'
   *  Sum: '<S204>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S195>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_Add1_ir - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim * (locvar_Add1_ir -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                   ANN_EKF_NMPC_2_P.Gain2_Gain_o * ANN_EKF_NMPC_2_P.Gain1_Gain_j)
    + (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_a;

  /* ManualSwitch: '<S203>/Manual Switch' incorporates:
   *  Constant: '<S203>/AR'
   *  Constant: '<S203>/Constant15'
   *  Constant: '<S203>/Constant16'
   *  Constant: '<S203>/Constant17'
   *  Constant: '<S203>/Constant18'
   *  Constant: '<S203>/e'
   *  Math: '<S203>/Math Function'
   *  Product: '<S203>/Divide8'
   *  Product: '<S203>/Divide9'
   *  Sum: '<S203>/Add5'
   *  Sum: '<S203>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting == 1) {
    locvar_ManualSwitch_d4 = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_d4 = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S203>/Manual Switch' */

  /* Sum: '<S203>/Add' incorporates:
   *  Constant: '<S203>/Constant1'
   *  Constant: '<S203>/Constant10'
   *  Constant: '<S203>/Constant11'
   *  Constant: '<S203>/Constant12'
   *  Constant: '<S203>/Constant13'
   *  Constant: '<S203>/Constant14'
   *  Constant: '<S203>/Constant2'
   *  Constant: '<S203>/Constant3'
   *  Constant: '<S203>/Constant4'
   *  Constant: '<S203>/Constant6'
   *  Constant: '<S203>/Constant7'
   *  Constant: '<S203>/Constant8'
   *  Constant: '<S203>/Constant9'
   *  Gain: '<S203>/Gain1'
   *  Gain: '<S203>/Gain2'
   *  Gain: '<S203>/Gain3'
   *  Product: '<S203>/Divide1'
   *  Product: '<S203>/Divide2'
   *  Product: '<S203>/Divide3'
   *  Product: '<S203>/Divide5'
   *  Product: '<S203>/Divide6'
   *  Product: '<S203>/Divide7'
   *  Sum: '<S203>/Add1'
   *  Sum: '<S203>/Add2'
   *  Sum: '<S203>/Add3'
   *  Sum: '<S203>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S195>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_d4) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_Add1_ir - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_Add1_ir -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_n *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_b) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_o;

  /* ManualSwitch: '<S189>/Manual Switch' incorporates:
   *  Constant: '<S189>/Constant1'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S215>/Constant'
   *  Constant: '<S215>/Constant1'
   *  Constant: '<S215>/Constant2'
   *  Math: '<S215>/Math Function'
   *  Product: '<S189>/Divide'
   *  Product: '<S189>/Divide5'
   *  Product: '<S212>/Divide3'
   *  Product: '<S212>/Divide5'
   *  Product: '<S215>/Divide1'
   *  Product: '<S215>/Divide2'
   *  Sum: '<S189>/Add'
   *  Sum: '<S212>/Add'
   *  Sum: '<S215>/Add'
   *  Trigonometry: '<S212>/Trigonometric Function'
   *  Trigonometry: '<S212>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_i == 1) {
    /* Gain: '<S215>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_d1 *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_d4 = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_d4 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S189>/Manual Switch' */

  /* Sum: '<S189>/Add1' incorporates:
   *  Constant: '<S189>/Constant'
   *  Product: '<S189>/Divide2'
   *  Product: '<S189>/Divide3'
   *  Product: '<S189>/Divide4'
   *  Trigonometry: '<S189>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add_b1 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * locvar_Divide_je -
                    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * locvar_Add1_md) -
                   sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                   ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_d4;

  /* ManualSwitch: '<S192>/Manual Switch' incorporates:
   *  Constant: '<S192>/Constant1'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S205>/Constant'
   *  Constant: '<S205>/Constant1'
   *  Constant: '<S205>/Constant10'
   *  Constant: '<S205>/Constant11'
   *  Constant: '<S205>/Constant12'
   *  Constant: '<S205>/Constant2'
   *  Constant: '<S205>/Constant3'
   *  Constant: '<S205>/Constant4'
   *  Constant: '<S205>/Constant5'
   *  Constant: '<S205>/Constant6'
   *  Constant: '<S205>/Constant8'
   *  Product: '<S192>/Divide'
   *  Product: '<S192>/Divide5'
   *  Product: '<S205>/Divide1'
   *  Product: '<S205>/Divide3'
   *  Product: '<S205>/Divide4'
   *  Product: '<S205>/Divide5'
   *  Product: '<S205>/Divide6'
   *  Sum: '<S205>/Add'
   *  Sum: '<S205>/Add1'
   *  Sum: '<S205>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_b == 1) {
    locvar_ManualSwitch_ds = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_ds = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S192>/Manual Switch' */

  /* Sum: '<S192>/Add1' incorporates:
   *  Constant: '<S192>/Constant'
   *  Product: '<S192>/Divide2'
   *  Product: '<S192>/Divide3'
   *  Product: '<S192>/Divide4'
   *  Trigonometry: '<S192>/Trigonometric Function'
   *  Trigonometry: '<S192>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] * locvar_Add1_md -
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * locvar_Add1_ir) +
                    sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_ds;

  /* ManualSwitch: '<S194>/Manual Switch' incorporates:
   *  Constant: '<S194>/Constant1'
   *  Constant: '<S197>/Constant'
   *  Product: '<S194>/Divide'
   *  Product: '<S194>/Divide5'
   *  Product: '<S214>/Divide1'
   *  Product: '<S214>/Divide6'
   *  Sum: '<S214>/Add2'
   *  Trigonometry: '<S214>/Trigonometric Function4'
   *  Trigonometry: '<S214>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_bt == 1) {
    locvar_ManualSwitch_ap = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_ap = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S194>/Manual Switch' */

  /* Sum: '<S194>/Add1' incorporates:
   *  Constant: '<S194>/Constant'
   *  Product: '<S194>/Divide2'
   *  Product: '<S194>/Divide3'
   *  Product: '<S194>/Divide4'
   *  Trigonometry: '<S194>/Trigonometric Function'
   *  Trigonometry: '<S194>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * locvar_Add1_ir -
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] * locvar_Divide_je)
                    + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_ap;

  /* Product: '<S191>/Divide' incorporates:
   *  Product: '<S191>/Divide3'
   *  Product: '<S191>/Divide4'
   *  Product: '<S191>/Divide5'
   *  Sum: '<S191>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide_ad = ((locvar_Add1_ir * locvar_Add_b1 + locvar_Divide_je *
                       locvar_Add2_o3) + locvar_Add1_md * locvar_Add2_db) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4];

  /* Product: '<S195>/Divide' incorporates:
   *  Math: '<S195>/Math Function'
   *  Math: '<S195>/Math Function1'
   *  Product: '<S195>/Divide3'
   *  Product: '<S195>/Divide4'
   *  Sum: '<S195>/Add'
   *  Sum: '<S195>/Add1'
   */
  locvar_Divide = (locvar_Add1_ir * locvar_Add2_db - locvar_Add1_md *
                   locvar_Add_b1) / (locvar_Add1_ir * locvar_Add1_ir +
    locvar_Add1_md * locvar_Add1_md);

  /* Product: '<S196>/Divide' incorporates:
   *  Math: '<S196>/Math Function'
   *  Math: '<S196>/Math Function1'
   *  Product: '<S196>/Divide1'
   *  Product: '<S196>/Divide2'
   *  Product: '<S196>/Divide3'
   *  Product: '<S196>/Divide4'
   *  Product: '<S196>/Divide5'
   *  Product: '<S196>/Divide6'
   *  Sum: '<S196>/Add'
   *  Sum: '<S196>/Add1'
   *  Sum: '<S196>/Add2'
   *  Trigonometry: '<S196>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide_je = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_Add2_o3 -
                      ((locvar_Add1_ir * locvar_Add_b1 + locvar_Divide_je *
                        locvar_Add2_o3) + locvar_Add1_md * locvar_Add2_db) /
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_Divide_je)
    / (locvar_Add1_ir * locvar_Add1_ir + locvar_Add1_md * locvar_Add1_md) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Trigonometry: '<S199>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S199>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat;
    }
  }

  /* Sum: '<S199>/Add1' incorporates:
   *  Product: '<S199>/Divide1'
   *  Product: '<S199>/Divide2'
   *  Product: '<S199>/Divide4'
   *  Saturate: '<S199>/Saturation'
   *  Sum: '<S199>/Add'
   *  Trigonometry: '<S199>/Trigonometric Function1'
   *  Trigonometry: '<S199>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_md = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
                    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt
    + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* Sum: '<S202>/Add' incorporates:
   *  Product: '<S202>/Divide2'
   *  Product: '<S202>/Divide4'
   *  Trigonometry: '<S202>/Trigonometric Function1'
   *  Trigonometry: '<S202>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add_b1 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S225>/Add' incorporates:
   *  Constant: '<S225>/Ixx1'
   *  Constant: '<S225>/Ixz1'
   *  Constant: '<S225>/Izz1'
   *  Math: '<S225>/Math Function'
   *  Product: '<S225>/Divide1'
   */
  locvar_Add2_o3 = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S217>/Divide4' incorporates:
   *  Constant: '<S217>/Ixx'
   *  Constant: '<S217>/Ixz'
   *  Constant: '<S217>/Iyy'
   *  Constant: '<S217>/Izz'
   *  Product: '<S217>/Divide3'
   *  Sum: '<S217>/Add'
   */
  locvar_Add2_db = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
                    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB /
    locvar_Add2_o3;

  /* Sum: '<S207>/Add' incorporates:
   *  Constant: '<S207>/Constant10'
   *  Constant: '<S207>/Constant11'
   *  Constant: '<S207>/Constant12'
   *  Constant: '<S207>/Constant13'
   *  Constant: '<S207>/Constant14'
   *  Constant: '<S207>/Constant15'
   *  Constant: '<S207>/Constant5'
   *  Constant: '<S207>/Constant6'
   *  Constant: '<S207>/Constant7'
   *  Constant: '<S207>/Constant8'
   *  Constant: '<S207>/Constant9'
   *  Product: '<S207>/Divide3'
   *  Product: '<S207>/Divide4'
   *  Product: '<S207>/Divide5'
   *  Product: '<S207>/Divide6'
   *  Product: '<S207>/Divide7'
   *  Sum: '<S207>/Add1'
   *  Sum: '<S207>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_ga = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S211>/Add' incorporates:
   *  Constant: '<S211>/Constant'
   *  Constant: '<S211>/Constant10'
   *  Constant: '<S211>/Constant11'
   *  Constant: '<S211>/Constant12'
   *  Constant: '<S211>/Constant13'
   *  Constant: '<S211>/Constant14'
   *  Constant: '<S211>/Constant15'
   *  Constant: '<S211>/Constant5'
   *  Constant: '<S211>/Constant6'
   *  Constant: '<S211>/Constant8'
   *  Constant: '<S211>/Constant9'
   *  Product: '<S211>/Divide3'
   *  Product: '<S211>/Divide4'
   *  Product: '<S211>/Divide5'
   *  Product: '<S211>/Divide6'
   *  Product: '<S211>/Divide7'
   *  Sum: '<S211>/Add1'
   *  Sum: '<S211>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_co = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S206>/Add' incorporates:
   *  Product: '<S206>/Divide3'
   *  Product: '<S206>/Divide5'
   *  Trigonometry: '<S206>/Trigonometric Function'
   *  Trigonometry: '<S206>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_i1 = locvar_Add2_ga * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_co;

  /* Product: '<S219>/Divide4' incorporates:
   *  Constant: '<S219>/Ixz'
   */
  locvar_Divide_j0 = ANN_EKF_NMPC_2_P.IxzB / locvar_Add2_o3;

  /* Sum: '<S210>/Add2' incorporates:
   *  Product: '<S210>/Divide1'
   *  Product: '<S210>/Divide6'
   *  Trigonometry: '<S210>/Trigonometric Function4'
   *  Trigonometry: '<S210>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_co = locvar_Add2_ga * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_co;

  /* Sum: '<S184>/Add2' incorporates:
   *  Constant: '<S184>/Constant1'
   *  Constant: '<S184>/Constant2'
   *  Constant: '<S216>/Ixz'
   *  Constant: '<S216>/Iyy'
   *  Constant: '<S216>/Izz'
   *  Constant: '<S218>/Izz'
   *  Math: '<S216>/Math Function'
   *  Product: '<S184>/Divide'
   *  Product: '<S184>/Divide1'
   *  Product: '<S184>/Divide2'
   *  Product: '<S184>/Divide3'
   *  Product: '<S184>/Divide4'
   *  Product: '<S184>/Divide5'
   *  Product: '<S184>/Divide6'
   *  Product: '<S216>/Divide3'
   *  Product: '<S216>/Divide4'
   *  Product: '<S218>/Divide4'
   *  Sum: '<S184>/Add'
   *  Sum: '<S184>/Add1'
   *  Sum: '<S216>/Add'
   *  Sum: '<S216>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_ga = (((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                     ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                     ANN_EKF_NMPC_2_P.IxzB) / locvar_Add2_o3 *
                    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_Add2_db *
                    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IzzB /
    locvar_Add2_o3 * locvar_ManualSwitch_i1 + locvar_Divide_j0 *
    locvar_ManualSwitch_co) * (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b);

  /* Sum: '<S186>/Add1' incorporates:
   *  Constant: '<S186>/Constant1'
   *  Constant: '<S186>/Constant2'
   *  Constant: '<S209>/Constant'
   *  Constant: '<S209>/Constant1'
   *  Constant: '<S209>/Constant11'
   *  Constant: '<S209>/Constant12'
   *  Constant: '<S209>/Constant13'
   *  Constant: '<S209>/Constant14'
   *  Constant: '<S209>/Constant2'
   *  Constant: '<S209>/Constant3'
   *  Constant: '<S209>/Constant4'
   *  Constant: '<S209>/Constant5'
   *  Constant: '<S209>/Constant6'
   *  Constant: '<S209>/Constant7'
   *  Constant: '<S209>/Constant8'
   *  Constant: '<S209>/Constant9'
   *  Constant: '<S220>/Ixx'
   *  Constant: '<S220>/Iyy'
   *  Constant: '<S220>/Izz'
   *  Constant: '<S221>/Ixz'
   *  Constant: '<S221>/Iyy'
   *  Constant: '<S222>/Ixz'
   *  Constant: '<S222>/Iyy'
   *  Gain: '<S209>/Gain1'
   *  Gain: '<S209>/Gain2'
   *  Math: '<S186>/Math Function'
   *  Math: '<S186>/Math Function1'
   *  Product: '<S186>/Divide'
   *  Product: '<S186>/Divide2'
   *  Product: '<S186>/Divide3'
   *  Product: '<S186>/Divide5'
   *  Product: '<S186>/Divide6'
   *  Product: '<S209>/Divide1'
   *  Product: '<S209>/Divide2'
   *  Product: '<S209>/Divide3'
   *  Product: '<S209>/Divide4'
   *  Product: '<S209>/Divide5'
   *  Product: '<S209>/Divide6'
   *  Product: '<S220>/Divide4'
   *  Product: '<S221>/Divide4'
   *  Product: '<S222>/Divide4'
   *  Sum: '<S186>/Add3'
   *  Sum: '<S209>/Add'
   *  Sum: '<S209>/Add1'
   *  Sum: '<S209>/Add2'
   *  Sum: '<S209>/Add3'
   *  Sum: '<S220>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S195>/Unit Delay'
   */
  locvar_Add1_ir = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
                       ANN_EKF_NMPC_2_P.Cmadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_Add1_ir - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.Cmde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_Add1_ir -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_m *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_ds) *
    (ANN_EKF_NMPC_2_P.Ixz_Value / ANN_EKF_NMPC_2_P.IyyB) * (locvar_Divide4_c1v *
    ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.Cbar) + ((ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxxB) / ANN_EKF_NMPC_2_P.IyyB *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB));

  /* Sum: '<S187>/Add2' incorporates:
   *  Constant: '<S187>/Constant1'
   *  Constant: '<S187>/Constant2'
   *  Constant: '<S223>/Ixx'
   *  Constant: '<S223>/Ixx1'
   *  Constant: '<S223>/Ixz'
   *  Constant: '<S223>/Iyy'
   *  Constant: '<S224>/Ixx'
   *  Math: '<S223>/Math Function'
   *  Product: '<S187>/Divide'
   *  Product: '<S187>/Divide1'
   *  Product: '<S187>/Divide2'
   *  Product: '<S187>/Divide3'
   *  Product: '<S187>/Divide4'
   *  Product: '<S187>/Divide5'
   *  Product: '<S187>/Divide6'
   *  Product: '<S223>/Divide3'
   *  Product: '<S223>/Divide4'
   *  Product: '<S224>/Divide4'
   *  Sum: '<S187>/Add'
   *  Sum: '<S187>/Add1'
   *  Sum: '<S223>/Add'
   *  Sum: '<S223>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide_j0 = (((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                       ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                       ANN_EKF_NMPC_2_P.IxzB) / locvar_Add2_o3 *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_Add2_db *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IxxB /
    locvar_Add2_o3 * locvar_ManualSwitch_co + locvar_Divide_j0 *
    locvar_ManualSwitch_i1) * (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b);

  /* Sum: '<S162>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add_nwv = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];

  /* Product: '<S503>/Divide2' incorporates:
   *  Trigonometry: '<S503>/Trigonometric Function'
   *  Trigonometry: '<S503>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_hd = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S505>/Divide2' incorporates:
   *  Trigonometry: '<S505>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_jq = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S508>/Divide2' incorporates:
   *  Trigonometry: '<S508>/Trigonometric Function'
   *  Trigonometry: '<S508>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_na = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S500>/Divide4' incorporates:
   *  Constant: '<S500>/Constant'
   *  Constant: '<S500>/Constant1'
   *  Math: '<S500>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_kga = ANN_EKF_NMPC_2_P.Constant_Value_l *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S519>/Add' incorporates:
   *  Constant: '<S519>/Constant'
   *  Constant: '<S519>/Constant1'
   *  Constant: '<S519>/Constant10'
   *  Constant: '<S519>/Constant11'
   *  Constant: '<S519>/Constant12'
   *  Constant: '<S519>/Constant13'
   *  Constant: '<S519>/Constant14'
   *  Constant: '<S519>/Constant15'
   *  Constant: '<S519>/Constant2'
   *  Constant: '<S519>/Constant3'
   *  Constant: '<S519>/Constant4'
   *  Constant: '<S519>/Constant5'
   *  Constant: '<S519>/Constant6'
   *  Constant: '<S519>/Constant7'
   *  Constant: '<S519>/Constant8'
   *  Constant: '<S519>/Constant9'
   *  Gain: '<S519>/Gain1'
   *  Gain: '<S519>/Gain2'
   *  Gain: '<S519>/Gain3'
   *  Product: '<S519>/Divide1'
   *  Product: '<S519>/Divide2'
   *  Product: '<S519>/Divide3'
   *  Product: '<S519>/Divide4'
   *  Product: '<S519>/Divide5'
   *  Product: '<S519>/Divide6'
   *  Product: '<S519>/Divide7'
   *  Sum: '<S519>/Add1'
   *  Sum: '<S519>/Add2'
   *  Sum: '<S519>/Add3'
   *  Sum: '<S519>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S510>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_k *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_hd - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
                   (locvar_ManualSwitch_hd - ANN_EKF_NMPC_2_P.Utrim) *
                   ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain2_Gain_n1 *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_m) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_m;

  /* ManualSwitch: '<S518>/Manual Switch' incorporates:
   *  Constant: '<S518>/AR'
   *  Constant: '<S518>/Constant15'
   *  Constant: '<S518>/Constant16'
   *  Constant: '<S518>/Constant17'
   *  Constant: '<S518>/Constant18'
   *  Constant: '<S518>/e'
   *  Math: '<S518>/Math Function'
   *  Product: '<S518>/Divide8'
   *  Product: '<S518>/Divide9'
   *  Sum: '<S518>/Add5'
   *  Sum: '<S518>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_c == 1) {
    locvar_ManualSwitch_n = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_n = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_d / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_k +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S518>/Manual Switch' */

  /* Sum: '<S518>/Add' incorporates:
   *  Constant: '<S518>/Constant1'
   *  Constant: '<S518>/Constant10'
   *  Constant: '<S518>/Constant11'
   *  Constant: '<S518>/Constant12'
   *  Constant: '<S518>/Constant13'
   *  Constant: '<S518>/Constant14'
   *  Constant: '<S518>/Constant2'
   *  Constant: '<S518>/Constant3'
   *  Constant: '<S518>/Constant4'
   *  Constant: '<S518>/Constant6'
   *  Constant: '<S518>/Constant7'
   *  Constant: '<S518>/Constant8'
   *  Constant: '<S518>/Constant9'
   *  Gain: '<S518>/Gain1'
   *  Gain: '<S518>/Gain2'
   *  Gain: '<S518>/Gain3'
   *  Product: '<S518>/Divide1'
   *  Product: '<S518>/Divide2'
   *  Product: '<S518>/Divide3'
   *  Product: '<S518>/Divide5'
   *  Product: '<S518>/Divide6'
   *  Product: '<S518>/Divide7'
   *  Sum: '<S518>/Add1'
   *  Sum: '<S518>/Add2'
   *  Sum: '<S518>/Add3'
   *  Sum: '<S518>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S510>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_n) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_k *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_hd - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_hd -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_mq *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_g) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_j;

  /* ManualSwitch: '<S504>/Manual Switch' incorporates:
   *  Constant: '<S504>/Constant1'
   *  Constant: '<S512>/Constant'
   *  Constant: '<S530>/Constant'
   *  Constant: '<S530>/Constant1'
   *  Constant: '<S530>/Constant2'
   *  Math: '<S530>/Math Function'
   *  Product: '<S504>/Divide'
   *  Product: '<S504>/Divide5'
   *  Product: '<S527>/Divide3'
   *  Product: '<S527>/Divide5'
   *  Product: '<S530>/Divide1'
   *  Product: '<S530>/Divide2'
   *  Sum: '<S504>/Add'
   *  Sum: '<S527>/Add'
   *  Sum: '<S530>/Add'
   *  Trigonometry: '<S527>/Trigonometric Function'
   *  Trigonometry: '<S527>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_e == 1) {
    /* Gain: '<S530>/Gain' */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_is * locvar_Add_nwv;
    locvar_ManualSwitch_n = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_kga * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_n = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S504>/Manual Switch' */

  /* Sum: '<S504>/Add1' incorporates:
   *  Constant: '<S504>/Constant'
   *  Product: '<S504>/Divide2'
   *  Product: '<S504>/Divide3'
   *  Product: '<S504>/Divide4'
   *  Trigonometry: '<S504>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_i = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_jq - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_na) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_n;

  /* Product: '<S506>/Divide3' */
  locvar_Divide3_bc = locvar_ManualSwitch_hd * locvar_ManualSwitch_i;

  /* ManualSwitch: '<S507>/Manual Switch' incorporates:
   *  Constant: '<S507>/Constant1'
   *  Constant: '<S512>/Constant'
   *  Constant: '<S520>/Constant'
   *  Constant: '<S520>/Constant1'
   *  Constant: '<S520>/Constant10'
   *  Constant: '<S520>/Constant11'
   *  Constant: '<S520>/Constant12'
   *  Constant: '<S520>/Constant2'
   *  Constant: '<S520>/Constant3'
   *  Constant: '<S520>/Constant4'
   *  Constant: '<S520>/Constant5'
   *  Constant: '<S520>/Constant6'
   *  Constant: '<S520>/Constant8'
   *  Product: '<S507>/Divide'
   *  Product: '<S507>/Divide5'
   *  Product: '<S520>/Divide1'
   *  Product: '<S520>/Divide3'
   *  Product: '<S520>/Divide4'
   *  Product: '<S520>/Divide5'
   *  Product: '<S520>/Divide6'
   *  Sum: '<S520>/Add'
   *  Sum: '<S520>/Add1'
   *  Sum: '<S520>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_n == 1) {
    locvar_ManualSwitch = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_kga * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S507>/Manual Switch' */

  /* Sum: '<S507>/Add1' incorporates:
   *  Constant: '<S507>/Constant'
   *  Product: '<S507>/Divide2'
   *  Product: '<S507>/Divide3'
   *  Product: '<S507>/Divide4'
   *  Trigonometry: '<S507>/Trigonometric Function'
   *  Trigonometry: '<S507>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_na - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_hd) + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch;

  /* Product: '<S506>/Divide4' */
  locvar_Divide4_mgn = locvar_ManualSwitch_jq * locvar_ManualSwitch_ga;

  /* ManualSwitch: '<S509>/Manual Switch' incorporates:
   *  Constant: '<S509>/Constant1'
   *  Constant: '<S512>/Constant'
   *  Product: '<S509>/Divide'
   *  Product: '<S509>/Divide5'
   *  Product: '<S529>/Divide1'
   *  Product: '<S529>/Divide6'
   *  Sum: '<S529>/Add2'
   *  Trigonometry: '<S529>/Trigonometric Function4'
   *  Trigonometry: '<S529>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_a == 1) {
    locvar_ManualSwitch_gd = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_kga * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_gd = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S509>/Manual Switch' */

  /* Sum: '<S509>/Add1' incorporates:
   *  Constant: '<S509>/Constant'
   *  Product: '<S509>/Divide2'
   *  Product: '<S509>/Divide3'
   *  Product: '<S509>/Divide4'
   *  Trigonometry: '<S509>/Trigonometric Function'
   *  Trigonometry: '<S509>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ce = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_hd - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_jq) + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_gd;

  /* Product: '<S506>/Divide5' */
  locvar_Divide5_ni = locvar_ManualSwitch_na * locvar_ManualSwitch_ce;

  /* Product: '<S510>/Divide' incorporates:
   *  Math: '<S510>/Math Function'
   *  Math: '<S510>/Math Function1'
   *  Product: '<S510>/Divide3'
   *  Product: '<S510>/Divide4'
   *  Sum: '<S510>/Add'
   *  Sum: '<S510>/Add1'
   */
  locvar_Divide_o = (locvar_ManualSwitch_hd * locvar_ManualSwitch_ce -
                     locvar_ManualSwitch_na * locvar_ManualSwitch_i) /
    (locvar_ManualSwitch_hd * locvar_ManualSwitch_hd + locvar_ManualSwitch_na *
     locvar_ManualSwitch_na);

  /* Product: '<S511>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide3_hfk = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    locvar_ManualSwitch_ga;

  /* Product: '<S511>/Divide4' incorporates:
   *  Product: '<S511>/Divide1'
   *  Product: '<S511>/Divide2'
   *  Product: '<S511>/Divide5'
   *  Product: '<S511>/Divide6'
   *  Sum: '<S511>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ng = ((locvar_ManualSwitch_hd * locvar_ManualSwitch_i +
                        locvar_ManualSwitch_jq * locvar_ManualSwitch_ga) +
                       locvar_ManualSwitch_na * locvar_ManualSwitch_ce) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_jq;

  /* Math: '<S511>/Math Function' */
  locvar_MathFunction_e = locvar_ManualSwitch_hd * locvar_ManualSwitch_hd;

  /* Math: '<S511>/Math Function1' */
  locvar_MathFunction1_bt = locvar_ManualSwitch_na * locvar_ManualSwitch_na;

  /* Sum: '<S540>/Add' incorporates:
   *  Constant: '<S540>/Ixx1'
   *  Constant: '<S540>/Ixz1'
   *  Constant: '<S540>/Izz1'
   *  Math: '<S540>/Math Function'
   *  Product: '<S540>/Divide1'
   */
  locvar_ManualSwitch_na = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S532>/Divide4' incorporates:
   *  Constant: '<S532>/Ixx'
   *  Constant: '<S532>/Ixz'
   *  Constant: '<S532>/Iyy'
   *  Constant: '<S532>/Izz'
   *  Product: '<S532>/Divide3'
   *  Sum: '<S532>/Add'
   */
  locvar_ManualSwitch_jq = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_na;

  /* Sum: '<S499>/Add1' incorporates:
   *  Constant: '<S531>/Ixz'
   *  Constant: '<S531>/Iyy'
   *  Constant: '<S531>/Izz'
   *  Math: '<S531>/Math Function'
   *  Product: '<S499>/Divide2'
   *  Product: '<S499>/Divide3'
   *  Product: '<S531>/Divide3'
   *  Product: '<S531>/Divide4'
   *  Sum: '<S531>/Add'
   *  Sum: '<S531>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_cl = ((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_na *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_ManualSwitch_jq *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* Sum: '<S522>/Add' incorporates:
   *  Constant: '<S522>/Constant10'
   *  Constant: '<S522>/Constant11'
   *  Constant: '<S522>/Constant12'
   *  Constant: '<S522>/Constant13'
   *  Constant: '<S522>/Constant14'
   *  Constant: '<S522>/Constant15'
   *  Constant: '<S522>/Constant5'
   *  Constant: '<S522>/Constant6'
   *  Constant: '<S522>/Constant7'
   *  Constant: '<S522>/Constant8'
   *  Constant: '<S522>/Constant9'
   *  Product: '<S522>/Divide3'
   *  Product: '<S522>/Divide4'
   *  Product: '<S522>/Divide5'
   *  Product: '<S522>/Divide6'
   *  Product: '<S522>/Divide7'
   *  Sum: '<S522>/Add1'
   *  Sum: '<S522>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_h5 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Clb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Clr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cldr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S526>/Add' incorporates:
   *  Constant: '<S526>/Constant'
   *  Constant: '<S526>/Constant10'
   *  Constant: '<S526>/Constant11'
   *  Constant: '<S526>/Constant12'
   *  Constant: '<S526>/Constant13'
   *  Constant: '<S526>/Constant14'
   *  Constant: '<S526>/Constant15'
   *  Constant: '<S526>/Constant5'
   *  Constant: '<S526>/Constant6'
   *  Constant: '<S526>/Constant8'
   *  Constant: '<S526>/Constant9'
   *  Product: '<S526>/Divide3'
   *  Product: '<S526>/Divide4'
   *  Product: '<S526>/Divide5'
   *  Product: '<S526>/Divide6'
   *  Product: '<S526>/Divide7'
   *  Sum: '<S526>/Add1'
   *  Sum: '<S526>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_py = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S521>/Add' incorporates:
   *  Product: '<S521>/Divide3'
   *  Product: '<S521>/Divide5'
   *  Trigonometry: '<S521>/Trigonometric Function'
   *  Trigonometry: '<S521>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_b = locvar_ManualSwitch_h5 * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_py;

  /* Product: '<S534>/Divide4' incorporates:
   *  Constant: '<S534>/Ixz'
   */
  locvar_ManualSwitch_gl = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_na;

  /* Sum: '<S525>/Add2' incorporates:
   *  Product: '<S525>/Divide1'
   *  Product: '<S525>/Divide6'
   *  Trigonometry: '<S525>/Trigonometric Function4'
   *  Trigonometry: '<S525>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_py = locvar_ManualSwitch_h5 * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_py;

  /* Sum: '<S499>/Add' incorporates:
   *  Constant: '<S533>/Izz'
   *  Product: '<S499>/Divide'
   *  Product: '<S499>/Divide4'
   *  Product: '<S533>/Divide4'
   */
  locvar_Add_mtb = ANN_EKF_NMPC_2_P.IzzB / locvar_ManualSwitch_na *
    locvar_ManualSwitch_b + locvar_ManualSwitch_gl * locvar_ManualSwitch_py;

  /* Product: '<S501>/Divide' incorporates:
   *  Constant: '<S524>/Constant'
   *  Constant: '<S524>/Constant1'
   *  Constant: '<S524>/Constant11'
   *  Constant: '<S524>/Constant12'
   *  Constant: '<S524>/Constant13'
   *  Constant: '<S524>/Constant14'
   *  Constant: '<S524>/Constant2'
   *  Constant: '<S524>/Constant3'
   *  Constant: '<S524>/Constant4'
   *  Constant: '<S524>/Constant5'
   *  Constant: '<S524>/Constant6'
   *  Constant: '<S524>/Constant7'
   *  Constant: '<S524>/Constant8'
   *  Constant: '<S524>/Constant9'
   *  Constant: '<S537>/Ixz'
   *  Constant: '<S537>/Iyy'
   *  Gain: '<S524>/Gain1'
   *  Gain: '<S524>/Gain2'
   *  Product: '<S524>/Divide1'
   *  Product: '<S524>/Divide2'
   *  Product: '<S524>/Divide3'
   *  Product: '<S524>/Divide4'
   *  Product: '<S524>/Divide5'
   *  Product: '<S524>/Divide6'
   *  Product: '<S537>/Divide4'
   *  Sum: '<S524>/Add'
   *  Sum: '<S524>/Add1'
   *  Sum: '<S524>/Add2'
   *  Sum: '<S524>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S510>/Unit Delay'
   */
  locvar_Divide_em = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_k *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                        ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
                        (locvar_ManualSwitch_hd - ANN_EKF_NMPC_2_P.Utrim)) +
                       ANN_EKF_NMPC_2_P.Cmde *
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                      ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_hd -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                      ANN_EKF_NMPC_2_P.Gain2_Gain_h *
                      ANN_EKF_NMPC_2_P.Gain1_Gain_mr) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_m / ANN_EKF_NMPC_2_P.IyyB);

  /* Sum: '<S502>/Add1' incorporates:
   *  Constant: '<S538>/Ixx'
   *  Constant: '<S538>/Ixx1'
   *  Constant: '<S538>/Ixz'
   *  Constant: '<S538>/Iyy'
   *  Math: '<S538>/Math Function'
   *  Product: '<S502>/Divide2'
   *  Product: '<S502>/Divide3'
   *  Product: '<S538>/Divide3'
   *  Product: '<S538>/Divide4'
   *  Sum: '<S538>/Add'
   *  Sum: '<S538>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_j2 = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_na *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_ManualSwitch_jq *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S502>/Add' incorporates:
   *  Constant: '<S539>/Ixx'
   *  Product: '<S502>/Divide'
   *  Product: '<S502>/Divide4'
   *  Product: '<S539>/Divide4'
   */
  locvar_Add_oq1 = ANN_EKF_NMPC_2_P.IxxB / locvar_ManualSwitch_na *
    locvar_ManualSwitch_py + locvar_ManualSwitch_gl * locvar_ManualSwitch_b;

  /* Sum: '<S157>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_b = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1];

  /* Product: '<S278>/Divide2' incorporates:
   *  Trigonometry: '<S278>/Trigonometric Function'
   *  Trigonometry: '<S278>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ce = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S280>/Divide2' incorporates:
   *  Trigonometry: '<S280>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ga = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S283>/Divide2' incorporates:
   *  Trigonometry: '<S283>/Trigonometric Function'
   *  Trigonometry: '<S283>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_i = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S275>/Divide4' incorporates:
   *  Constant: '<S275>/Constant'
   *  Constant: '<S275>/Constant1'
   *  Math: '<S275>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ch = ANN_EKF_NMPC_2_P.Constant_Value_n * ANN_EKF_NMPC_2_P.rho_o
    * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S294>/Add' incorporates:
   *  Constant: '<S294>/Constant'
   *  Constant: '<S294>/Constant1'
   *  Constant: '<S294>/Constant10'
   *  Constant: '<S294>/Constant11'
   *  Constant: '<S294>/Constant12'
   *  Constant: '<S294>/Constant13'
   *  Constant: '<S294>/Constant14'
   *  Constant: '<S294>/Constant15'
   *  Constant: '<S294>/Constant2'
   *  Constant: '<S294>/Constant3'
   *  Constant: '<S294>/Constant4'
   *  Constant: '<S294>/Constant5'
   *  Constant: '<S294>/Constant6'
   *  Constant: '<S294>/Constant7'
   *  Constant: '<S294>/Constant8'
   *  Constant: '<S294>/Constant9'
   *  Gain: '<S294>/Gain1'
   *  Gain: '<S294>/Gain2'
   *  Gain: '<S294>/Gain3'
   *  Product: '<S294>/Divide1'
   *  Product: '<S294>/Divide2'
   *  Product: '<S294>/Divide3'
   *  Product: '<S294>/Divide4'
   *  Product: '<S294>/Divide5'
   *  Product: '<S294>/Divide6'
   *  Product: '<S294>/Divide7'
   *  Sum: '<S294>/Add1'
   *  Sum: '<S294>/Add2'
   *  Sum: '<S294>/Add3'
   *  Sum: '<S294>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S285>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_a *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_ce - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * locvar_ManualSwitch_b) + 1.0 /
                   ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_ce -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                   ANN_EKF_NMPC_2_P.Gain2_Gain_hd *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_hy) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_b;

  /* ManualSwitch: '<S293>/Manual Switch' incorporates:
   *  Constant: '<S293>/AR'
   *  Constant: '<S293>/Constant15'
   *  Constant: '<S293>/Constant16'
   *  Constant: '<S293>/Constant17'
   *  Constant: '<S293>/Constant18'
   *  Constant: '<S293>/e'
   *  Math: '<S293>/Math Function'
   *  Product: '<S293>/Divide8'
   *  Product: '<S293>/Divide9'
   *  Sum: '<S293>/Add5'
   *  Sum: '<S293>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_g == 1) {
    locvar_ManualSwitch_na = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_na = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_a / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_h +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S293>/Manual Switch' */

  /* Sum: '<S293>/Add' incorporates:
   *  Constant: '<S293>/Constant1'
   *  Constant: '<S293>/Constant10'
   *  Constant: '<S293>/Constant11'
   *  Constant: '<S293>/Constant12'
   *  Constant: '<S293>/Constant13'
   *  Constant: '<S293>/Constant14'
   *  Constant: '<S293>/Constant2'
   *  Constant: '<S293>/Constant3'
   *  Constant: '<S293>/Constant4'
   *  Constant: '<S293>/Constant6'
   *  Constant: '<S293>/Constant7'
   *  Constant: '<S293>/Constant8'
   *  Constant: '<S293>/Constant9'
   *  Gain: '<S293>/Gain1'
   *  Gain: '<S293>/Gain2'
   *  Gain: '<S293>/Gain3'
   *  Product: '<S293>/Divide1'
   *  Product: '<S293>/Divide2'
   *  Product: '<S293>/Divide3'
   *  Product: '<S293>/Divide5'
   *  Product: '<S293>/Divide6'
   *  Product: '<S293>/Divide7'
   *  Sum: '<S293>/Add1'
   *  Sum: '<S293>/Add2'
   *  Sum: '<S293>/Add3'
   *  Sum: '<S293>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S285>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_na) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_a *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_ce - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde * locvar_ManualSwitch_b) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_ce -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_dl *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_gz) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_bh;

  /* ManualSwitch: '<S279>/Manual Switch' incorporates:
   *  Constant: '<S279>/Constant1'
   *  Constant: '<S287>/Constant'
   *  Constant: '<S305>/Constant'
   *  Constant: '<S305>/Constant1'
   *  Constant: '<S305>/Constant2'
   *  Math: '<S305>/Math Function'
   *  Product: '<S279>/Divide'
   *  Product: '<S279>/Divide5'
   *  Product: '<S302>/Divide3'
   *  Product: '<S302>/Divide5'
   *  Product: '<S305>/Divide1'
   *  Product: '<S305>/Divide2'
   *  Sum: '<S279>/Add'
   *  Sum: '<S302>/Add'
   *  Sum: '<S305>/Add'
   *  Trigonometry: '<S302>/Trigonometric Function'
   *  Trigonometry: '<S302>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_nc == 1) {
    /* Gain: '<S305>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_ie *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_na = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_na = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S279>/Manual Switch' */

  /* Sum: '<S279>/Add1' incorporates:
   *  Constant: '<S279>/Constant'
   *  Product: '<S279>/Divide2'
   *  Product: '<S279>/Divide3'
   *  Product: '<S279>/Divide4'
   *  Trigonometry: '<S279>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_jq = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_ga - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_i) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_na;

  /* ManualSwitch: '<S282>/Manual Switch' incorporates:
   *  Constant: '<S282>/Constant1'
   *  Constant: '<S287>/Constant'
   *  Constant: '<S295>/Constant'
   *  Constant: '<S295>/Constant1'
   *  Constant: '<S295>/Constant10'
   *  Constant: '<S295>/Constant11'
   *  Constant: '<S295>/Constant12'
   *  Constant: '<S295>/Constant2'
   *  Constant: '<S295>/Constant3'
   *  Constant: '<S295>/Constant4'
   *  Constant: '<S295>/Constant5'
   *  Constant: '<S295>/Constant6'
   *  Constant: '<S295>/Constant8'
   *  Product: '<S282>/Divide'
   *  Product: '<S282>/Divide5'
   *  Product: '<S295>/Divide1'
   *  Product: '<S295>/Divide3'
   *  Product: '<S295>/Divide4'
   *  Product: '<S295>/Divide5'
   *  Product: '<S295>/Divide6'
   *  Sum: '<S295>/Add'
   *  Sum: '<S295>/Add1'
   *  Sum: '<S295>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_d == 1) {
    locvar_ManualSwitch_hd = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_hd = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S282>/Manual Switch' */

  /* Sum: '<S282>/Add1' incorporates:
   *  Constant: '<S282>/Constant'
   *  Product: '<S282>/Divide2'
   *  Product: '<S282>/Divide3'
   *  Product: '<S282>/Divide4'
   *  Trigonometry: '<S282>/Trigonometric Function'
   *  Trigonometry: '<S282>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_i1 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_i - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_ce) + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_hd;

  /* Product: '<S281>/Divide4' */
  locvar_Divide4_c1v = locvar_ManualSwitch_ga * locvar_ManualSwitch_i1;

  /* ManualSwitch: '<S284>/Manual Switch' incorporates:
   *  Constant: '<S284>/Constant1'
   *  Constant: '<S287>/Constant'
   *  Product: '<S284>/Divide'
   *  Product: '<S284>/Divide5'
   *  Product: '<S304>/Divide1'
   *  Product: '<S304>/Divide6'
   *  Sum: '<S304>/Add2'
   *  Trigonometry: '<S304>/Trigonometric Function4'
   *  Trigonometry: '<S304>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_es == 1) {
    locvar_ManualSwitch_co = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_co = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S284>/Manual Switch' */

  /* Sum: '<S284>/Add1' incorporates:
   *  Constant: '<S284>/Constant'
   *  Product: '<S284>/Divide2'
   *  Product: '<S284>/Divide3'
   *  Product: '<S284>/Divide4'
   *  Trigonometry: '<S284>/Trigonometric Function'
   *  Trigonometry: '<S284>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
                     locvar_ManualSwitch_ce -
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
                     locvar_ManualSwitch_ga) + cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_co;

  /* Product: '<S281>/Divide5' */
  locvar_Add_kq = locvar_ManualSwitch_i * locvar_Add2_o3;

  /* Product: '<S285>/Divide' incorporates:
   *  Math: '<S285>/Math Function'
   *  Math: '<S285>/Math Function1'
   *  Product: '<S285>/Divide3'
   *  Product: '<S285>/Divide4'
   *  Sum: '<S285>/Add'
   *  Sum: '<S285>/Add1'
   */
  locvar_Divide_p3 = (locvar_ManualSwitch_ce * locvar_Add2_o3 -
                      locvar_ManualSwitch_i * locvar_ManualSwitch_jq) /
    (locvar_ManualSwitch_ce * locvar_ManualSwitch_ce + locvar_ManualSwitch_i *
     locvar_ManualSwitch_i);

  /* Product: '<S286>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    locvar_ManualSwitch_i1;

  /* Product: '<S286>/Divide4' incorporates:
   *  Product: '<S286>/Divide1'
   *  Product: '<S286>/Divide2'
   *  Product: '<S286>/Divide5'
   *  Product: '<S286>/Divide6'
   *  Sum: '<S286>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain_ar = ((locvar_ManualSwitch_ce * locvar_ManualSwitch_jq +
                     locvar_ManualSwitch_ga * locvar_ManualSwitch_i1) +
                    locvar_ManualSwitch_i * locvar_Add2_o3) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_ga;

  /* Sum: '<S315>/Add' incorporates:
   *  Constant: '<S315>/Ixx1'
   *  Constant: '<S315>/Ixz1'
   *  Constant: '<S315>/Izz1'
   *  Math: '<S315>/Math Function'
   *  Product: '<S315>/Divide1'
   */
  locvar_ManualSwitch_i1 = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S307>/Divide4' incorporates:
   *  Constant: '<S307>/Ixx'
   *  Constant: '<S307>/Ixz'
   *  Constant: '<S307>/Iyy'
   *  Constant: '<S307>/Izz'
   *  Product: '<S307>/Divide3'
   *  Sum: '<S307>/Add'
   */
  locvar_Add2_o3 = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
                    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB /
    locvar_ManualSwitch_i1;

  /* Sum: '<S297>/Add' incorporates:
   *  Constant: '<S297>/Constant10'
   *  Constant: '<S297>/Constant11'
   *  Constant: '<S297>/Constant12'
   *  Constant: '<S297>/Constant13'
   *  Constant: '<S297>/Constant14'
   *  Constant: '<S297>/Constant15'
   *  Constant: '<S297>/Constant5'
   *  Constant: '<S297>/Constant6'
   *  Constant: '<S297>/Constant7'
   *  Constant: '<S297>/Constant8'
   *  Constant: '<S297>/Constant9'
   *  Product: '<S297>/Divide3'
   *  Product: '<S297>/Divide4'
   *  Product: '<S297>/Divide5'
   *  Product: '<S297>/Divide6'
   *  Product: '<S297>/Divide7'
   *  Sum: '<S297>/Add1'
   *  Sum: '<S297>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_e4 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Clb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Clr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cldr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S301>/Add' incorporates:
   *  Constant: '<S301>/Constant'
   *  Constant: '<S301>/Constant10'
   *  Constant: '<S301>/Constant11'
   *  Constant: '<S301>/Constant12'
   *  Constant: '<S301>/Constant13'
   *  Constant: '<S301>/Constant14'
   *  Constant: '<S301>/Constant15'
   *  Constant: '<S301>/Constant5'
   *  Constant: '<S301>/Constant6'
   *  Constant: '<S301>/Constant8'
   *  Constant: '<S301>/Constant9'
   *  Product: '<S301>/Divide3'
   *  Product: '<S301>/Divide4'
   *  Product: '<S301>/Divide5'
   *  Product: '<S301>/Divide6'
   *  Product: '<S301>/Divide7'
   *  Sum: '<S301>/Add1'
   *  Sum: '<S301>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_k5 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S296>/Add' incorporates:
   *  Product: '<S296>/Divide3'
   *  Product: '<S296>/Divide5'
   *  Trigonometry: '<S296>/Trigonometric Function'
   *  Trigonometry: '<S296>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_oa = locvar_ManualSwitch_e4 * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_k5;

  /* Product: '<S309>/Divide4' incorporates:
   *  Constant: '<S309>/Ixz'
   */
  locvar_ManualSwitch_c = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_i1;

  /* Sum: '<S300>/Add2' incorporates:
   *  Product: '<S300>/Divide1'
   *  Product: '<S300>/Divide6'
   *  Trigonometry: '<S300>/Trigonometric Function4'
   *  Trigonometry: '<S300>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_k5 = locvar_ManualSwitch_e4 * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_k5;

  /* Saturate: '<S271>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Product: '<S151>/Divide1' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S271>/Gain'
   *  Gain: '<S271>/Gain1'
   *  Saturate: '<S271>/Throttle Limiter'
   *  Sum: '<S151>/Sum1'
   *  Sum: '<S271>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide1_gv[0] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S271>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Product: '<S151>/Divide1' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S271>/Gain2'
   *  Gain: '<S271>/Gain3'
   *  Saturate: '<S271>/Elevator Limiter'
   *  Sum: '<S151>/Sum1'
   *  Sum: '<S271>/Add1'
   */
  locvar_Divide1_gv[1] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * locvar_ManualSwitch_b) - locvar_Add2_ap) /
    ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S271>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Product: '<S151>/Divide1' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S271>/Gain4'
   *  Gain: '<S271>/Gain5'
   *  Saturate: '<S271>/Aileron Limiter'
   *  Sum: '<S151>/Sum1'
   *  Sum: '<S271>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide1_gv[2] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S271>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Product: '<S151>/Divide1' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S271>/Gain6'
   *  Gain: '<S271>/Gain7'
   *  Math: '<S286>/Math Function'
   *  Math: '<S286>/Math Function1'
   *  Product: '<S281>/Divide'
   *  Product: '<S281>/Divide3'
   *  Product: '<S286>/Divide'
   *  Saturate: '<S271>/Rudder Limiter'
   *  Sum: '<S151>/Sum1'
   *  Sum: '<S271>/Add3'
   *  Sum: '<S281>/Add'
   *  Sum: '<S286>/Add'
   *  Sum: '<S286>/Add1'
   *  Trigonometry: '<S286>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide1_gv[3] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[4] = (((locvar_ManualSwitch_ce * locvar_ManualSwitch_jq +
    locvar_Divide4_c1v) + locvar_Add_kq) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]
    - locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[5] = (locvar_Divide_p3 - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[6] = ((locvar_Add2_db - locvar_Gain_ar) /
    (locvar_ManualSwitch_ce * locvar_ManualSwitch_ce + locvar_ManualSwitch_i *
     locvar_ManualSwitch_i) * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) -
    locvar_Divide_je) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Trigonometry: '<S289>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S289>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_e) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_e;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_h) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_h;
    }
  }

  /* Product: '<S151>/Divide1' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S274>/Constant1'
   *  Constant: '<S274>/Constant2'
   *  Constant: '<S276>/Constant1'
   *  Constant: '<S276>/Constant2'
   *  Constant: '<S277>/Constant1'
   *  Constant: '<S277>/Constant2'
   *  Constant: '<S290>/Constant'
   *  Constant: '<S291>/Constant'
   *  Constant: '<S299>/Constant'
   *  Constant: '<S299>/Constant1'
   *  Constant: '<S299>/Constant11'
   *  Constant: '<S299>/Constant12'
   *  Constant: '<S299>/Constant13'
   *  Constant: '<S299>/Constant14'
   *  Constant: '<S299>/Constant2'
   *  Constant: '<S299>/Constant3'
   *  Constant: '<S299>/Constant4'
   *  Constant: '<S299>/Constant5'
   *  Constant: '<S299>/Constant6'
   *  Constant: '<S299>/Constant7'
   *  Constant: '<S299>/Constant8'
   *  Constant: '<S299>/Constant9'
   *  Constant: '<S306>/Ixz'
   *  Constant: '<S306>/Iyy'
   *  Constant: '<S306>/Izz'
   *  Constant: '<S308>/Izz'
   *  Constant: '<S310>/Ixx'
   *  Constant: '<S310>/Iyy'
   *  Constant: '<S310>/Izz'
   *  Constant: '<S311>/Ixz'
   *  Constant: '<S311>/Iyy'
   *  Constant: '<S312>/Ixz'
   *  Constant: '<S312>/Iyy'
   *  Constant: '<S313>/Ixx'
   *  Constant: '<S313>/Ixx1'
   *  Constant: '<S313>/Ixz'
   *  Constant: '<S313>/Iyy'
   *  Constant: '<S314>/Ixx'
   *  Gain: '<S299>/Gain1'
   *  Gain: '<S299>/Gain2'
   *  Math: '<S276>/Math Function'
   *  Math: '<S276>/Math Function1'
   *  Math: '<S306>/Math Function'
   *  Math: '<S313>/Math Function'
   *  Product: '<S274>/Divide'
   *  Product: '<S274>/Divide1'
   *  Product: '<S274>/Divide2'
   *  Product: '<S274>/Divide3'
   *  Product: '<S274>/Divide4'
   *  Product: '<S274>/Divide5'
   *  Product: '<S274>/Divide6'
   *  Product: '<S276>/Divide'
   *  Product: '<S276>/Divide2'
   *  Product: '<S276>/Divide3'
   *  Product: '<S276>/Divide5'
   *  Product: '<S276>/Divide6'
   *  Product: '<S277>/Divide'
   *  Product: '<S277>/Divide1'
   *  Product: '<S277>/Divide2'
   *  Product: '<S277>/Divide3'
   *  Product: '<S277>/Divide4'
   *  Product: '<S277>/Divide5'
   *  Product: '<S277>/Divide6'
   *  Product: '<S289>/Divide1'
   *  Product: '<S289>/Divide2'
   *  Product: '<S289>/Divide4'
   *  Product: '<S292>/Divide2'
   *  Product: '<S292>/Divide4'
   *  Product: '<S299>/Divide1'
   *  Product: '<S299>/Divide2'
   *  Product: '<S299>/Divide3'
   *  Product: '<S299>/Divide4'
   *  Product: '<S299>/Divide5'
   *  Product: '<S299>/Divide6'
   *  Product: '<S306>/Divide3'
   *  Product: '<S306>/Divide4'
   *  Product: '<S308>/Divide4'
   *  Product: '<S310>/Divide4'
   *  Product: '<S311>/Divide4'
   *  Product: '<S312>/Divide4'
   *  Product: '<S313>/Divide3'
   *  Product: '<S313>/Divide4'
   *  Product: '<S314>/Divide4'
   *  Saturate: '<S289>/Saturation'
   *  Sum: '<S151>/Sum1'
   *  Sum: '<S274>/Add'
   *  Sum: '<S274>/Add1'
   *  Sum: '<S274>/Add2'
   *  Sum: '<S276>/Add1'
   *  Sum: '<S276>/Add3'
   *  Sum: '<S277>/Add'
   *  Sum: '<S277>/Add1'
   *  Sum: '<S277>/Add2'
   *  Sum: '<S289>/Add'
   *  Sum: '<S289>/Add1'
   *  Sum: '<S292>/Add'
   *  Sum: '<S299>/Add'
   *  Sum: '<S299>/Add1'
   *  Sum: '<S299>/Add2'
   *  Sum: '<S299>/Add3'
   *  Sum: '<S306>/Add'
   *  Sum: '<S306>/Add1'
   *  Sum: '<S310>/Add'
   *  Sum: '<S313>/Add'
   *  Sum: '<S313>/Add1'
   *  Trigonometry: '<S289>/Trigonometric Function1'
   *  Trigonometry: '<S289>/Trigonometric Function2'
   *  Trigonometry: '<S292>/Trigonometric Function1'
   *  Trigonometry: '<S292>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S285>/Unit Delay'
   */
  locvar_Divide1_gv[7] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[8] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[9] = (((((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB) /
    locvar_ManualSwitch_i1 * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] +
    locvar_Add2_o3 * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IzzB /
    locvar_ManualSwitch_i1 * locvar_ManualSwitch_oa + locvar_ManualSwitch_c *
    locvar_ManualSwitch_k5) * (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b)) - locvar_Add2_ga) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[10] = ((((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_a *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
    ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_ce -
    ANN_EKF_NMPC_2_P.Utrim)) + ANN_EKF_NMPC_2_P.Cmde * locvar_ManualSwitch_b) +
    1.0 / ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_ce -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
    ANN_EKF_NMPC_2_P.Gain2_Gain_p * ANN_EKF_NMPC_2_P.Gain1_Gain_e) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_p / ANN_EKF_NMPC_2_P.IyyB) * (locvar_Divide4_ch *
    ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.Cbar) + ((ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxxB) / ANN_EKF_NMPC_2_P.IyyB *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB))) - locvar_Add1_ir) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[11] = (((((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB) /
    locvar_ManualSwitch_i1 * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    locvar_Add2_o3 * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IxxB /
    locvar_ManualSwitch_i1 * locvar_ManualSwitch_k5 + locvar_ManualSwitch_c *
    locvar_ManualSwitch_oa) * (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b)) - locvar_Divide_j0) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[12] = (ANN_EKF_NMPC_2_P.Constant_Value_g -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide1_gv[13] = (ANN_EKF_NMPC_2_P.Constant_Value_d -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Sum: '<S156>/Add1' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_cn2 = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2];

  /* Product: '<S233>/Divide2' incorporates:
   *  Trigonometry: '<S233>/Trigonometric Function'
   *  Trigonometry: '<S233>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_gl = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S235>/Divide2' incorporates:
   *  Trigonometry: '<S235>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_b = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S238>/Divide2' incorporates:
   *  Trigonometry: '<S238>/Trigonometric Function'
   *  Trigonometry: '<S238>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_py = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S230>/Divide4' incorporates:
   *  Constant: '<S230>/Constant'
   *  Constant: '<S230>/Constant1'
   *  Math: '<S230>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_m3 = ANN_EKF_NMPC_2_P.Constant_Value_fh *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S249>/Add' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S249>/Constant1'
   *  Constant: '<S249>/Constant10'
   *  Constant: '<S249>/Constant11'
   *  Constant: '<S249>/Constant12'
   *  Constant: '<S249>/Constant13'
   *  Constant: '<S249>/Constant14'
   *  Constant: '<S249>/Constant15'
   *  Constant: '<S249>/Constant2'
   *  Constant: '<S249>/Constant3'
   *  Constant: '<S249>/Constant4'
   *  Constant: '<S249>/Constant5'
   *  Constant: '<S249>/Constant6'
   *  Constant: '<S249>/Constant7'
   *  Constant: '<S249>/Constant8'
   *  Constant: '<S249>/Constant9'
   *  Gain: '<S249>/Gain1'
   *  Gain: '<S249>/Gain2'
   *  Gain: '<S249>/Gain3'
   *  Product: '<S249>/Divide1'
   *  Product: '<S249>/Divide2'
   *  Product: '<S249>/Divide3'
   *  Product: '<S249>/Divide4'
   *  Product: '<S249>/Divide5'
   *  Product: '<S249>/Divide6'
   *  Product: '<S249>/Divide7'
   *  Sum: '<S249>/Add1'
   *  Sum: '<S249>/Add2'
   *  Sum: '<S249>/Add3'
   *  Sum: '<S249>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S240>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_m *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_gl - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
                   (locvar_ManualSwitch_gl - ANN_EKF_NMPC_2_P.Utrim) *
                   ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain2_Gain_hx *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_c) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_ag;

  /* ManualSwitch: '<S248>/Manual Switch' incorporates:
   *  Constant: '<S248>/AR'
   *  Constant: '<S248>/Constant15'
   *  Constant: '<S248>/Constant16'
   *  Constant: '<S248>/Constant17'
   *  Constant: '<S248>/Constant18'
   *  Constant: '<S248>/e'
   *  Math: '<S248>/Math Function'
   *  Product: '<S248>/Divide8'
   *  Product: '<S248>/Divide9'
   *  Sum: '<S248>/Add5'
   *  Sum: '<S248>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_f == 1) {
    locvar_ManualSwitch_h5 = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_h5 = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_e / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_m +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S248>/Manual Switch' */

  /* Sum: '<S248>/Add' incorporates:
   *  Constant: '<S248>/Constant1'
   *  Constant: '<S248>/Constant10'
   *  Constant: '<S248>/Constant11'
   *  Constant: '<S248>/Constant12'
   *  Constant: '<S248>/Constant13'
   *  Constant: '<S248>/Constant14'
   *  Constant: '<S248>/Constant2'
   *  Constant: '<S248>/Constant3'
   *  Constant: '<S248>/Constant4'
   *  Constant: '<S248>/Constant6'
   *  Constant: '<S248>/Constant7'
   *  Constant: '<S248>/Constant8'
   *  Constant: '<S248>/Constant9'
   *  Gain: '<S248>/Gain1'
   *  Gain: '<S248>/Gain2'
   *  Gain: '<S248>/Gain3'
   *  Product: '<S248>/Divide1'
   *  Product: '<S248>/Divide2'
   *  Product: '<S248>/Divide3'
   *  Product: '<S248>/Divide5'
   *  Product: '<S248>/Divide6'
   *  Product: '<S248>/Divide7'
   *  Sum: '<S248>/Add1'
   *  Sum: '<S248>/Add2'
   *  Sum: '<S248>/Add3'
   *  Sum: '<S248>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S240>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_h5) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_m *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_gl - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_gl -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_g *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_kp) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_g;

  /* ManualSwitch: '<S234>/Manual Switch' incorporates:
   *  Constant: '<S234>/Constant1'
   *  Constant: '<S242>/Constant'
   *  Constant: '<S260>/Constant'
   *  Constant: '<S260>/Constant1'
   *  Constant: '<S260>/Constant2'
   *  Math: '<S260>/Math Function'
   *  Product: '<S234>/Divide'
   *  Product: '<S234>/Divide5'
   *  Product: '<S257>/Divide3'
   *  Product: '<S257>/Divide5'
   *  Product: '<S260>/Divide1'
   *  Product: '<S260>/Divide2'
   *  Sum: '<S234>/Add'
   *  Sum: '<S257>/Add'
   *  Sum: '<S260>/Add'
   *  Trigonometry: '<S257>/Trigonometric Function'
   *  Trigonometry: '<S257>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_fr == 1) {
    /* Gain: '<S260>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_i *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_h5 = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_m3 * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_h5 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S234>/Manual Switch' */

  /* Sum: '<S234>/Add1' incorporates:
   *  Constant: '<S234>/Constant'
   *  Product: '<S234>/Divide2'
   *  Product: '<S234>/Divide3'
   *  Product: '<S234>/Divide4'
   *  Trigonometry: '<S234>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_if = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_b - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_py) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_h5;

  /* Product: '<S236>/Divide3' */
  locvar_Divide3_b10 = locvar_ManualSwitch_gl * locvar_ManualSwitch_if;

  /* ManualSwitch: '<S237>/Manual Switch' incorporates:
   *  Constant: '<S237>/Constant1'
   *  Constant: '<S242>/Constant'
   *  Constant: '<S250>/Constant'
   *  Constant: '<S250>/Constant1'
   *  Constant: '<S250>/Constant10'
   *  Constant: '<S250>/Constant11'
   *  Constant: '<S250>/Constant12'
   *  Constant: '<S250>/Constant2'
   *  Constant: '<S250>/Constant3'
   *  Constant: '<S250>/Constant4'
   *  Constant: '<S250>/Constant5'
   *  Constant: '<S250>/Constant6'
   *  Constant: '<S250>/Constant8'
   *  Product: '<S237>/Divide'
   *  Product: '<S237>/Divide5'
   *  Product: '<S250>/Divide1'
   *  Product: '<S250>/Divide3'
   *  Product: '<S250>/Divide4'
   *  Product: '<S250>/Divide5'
   *  Product: '<S250>/Divide6'
   *  Sum: '<S250>/Add'
   *  Sum: '<S250>/Add1'
   *  Sum: '<S250>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_k == 1) {
    locvar_ManualSwitch_ce = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * locvar_Add1_cn2) + ANN_EKF_NMPC_2_P.Cydr *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) * (locvar_Divide4_m3 *
      ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight / ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_ce = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S237>/Manual Switch' */

  /* Sum: '<S237>/Add1' incorporates:
   *  Constant: '<S237>/Constant'
   *  Product: '<S237>/Divide2'
   *  Product: '<S237>/Divide3'
   *  Product: '<S237>/Divide4'
   *  Trigonometry: '<S237>/Trigonometric Function'
   *  Trigonometry: '<S237>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_py - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_gl) + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_ce;

  /* Product: '<S236>/Divide4' */
  locvar_Divide4_nh = locvar_ManualSwitch_b * locvar_ManualSwitch_ga;

  /* ManualSwitch: '<S239>/Manual Switch' incorporates:
   *  Constant: '<S239>/Constant1'
   *  Constant: '<S242>/Constant'
   *  Product: '<S239>/Divide'
   *  Product: '<S239>/Divide5'
   *  Product: '<S259>/Divide1'
   *  Product: '<S259>/Divide6'
   *  Sum: '<S259>/Add2'
   *  Trigonometry: '<S259>/Trigonometric Function4'
   *  Trigonometry: '<S259>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_d1 == 1) {
    locvar_ManualSwitch_i = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_m3 * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_i = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S239>/Manual Switch' */

  /* Sum: '<S239>/Add1' incorporates:
   *  Constant: '<S239>/Constant'
   *  Product: '<S239>/Divide2'
   *  Product: '<S239>/Divide3'
   *  Product: '<S239>/Divide4'
   *  Trigonometry: '<S239>/Trigonometric Function'
   *  Trigonometry: '<S239>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_jq = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_gl - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_b) + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_i;

  /* Product: '<S236>/Divide5' */
  locvar_Divide5_pq = locvar_ManualSwitch_py * locvar_ManualSwitch_jq;

  /* Product: '<S240>/Divide' incorporates:
   *  Math: '<S240>/Math Function'
   *  Math: '<S240>/Math Function1'
   *  Product: '<S240>/Divide3'
   *  Product: '<S240>/Divide4'
   *  Sum: '<S240>/Add'
   *  Sum: '<S240>/Add1'
   */
  locvar_Divide_f5 = (locvar_ManualSwitch_gl * locvar_ManualSwitch_jq -
                      locvar_ManualSwitch_py * locvar_ManualSwitch_if) /
    (locvar_ManualSwitch_gl * locvar_ManualSwitch_gl + locvar_ManualSwitch_py *
     locvar_ManualSwitch_py);

  /* Product: '<S241>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide3_jze = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    locvar_ManualSwitch_ga;

  /* Product: '<S241>/Divide4' incorporates:
   *  Product: '<S241>/Divide1'
   *  Product: '<S241>/Divide2'
   *  Product: '<S241>/Divide5'
   *  Product: '<S241>/Divide6'
   *  Sum: '<S241>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ncd = ((locvar_ManualSwitch_gl * locvar_ManualSwitch_if +
    locvar_ManualSwitch_b * locvar_ManualSwitch_ga) + locvar_ManualSwitch_py *
                        locvar_ManualSwitch_jq) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_b;

  /* Math: '<S241>/Math Function' */
  locvar_MathFunction_pp = locvar_ManualSwitch_gl * locvar_ManualSwitch_gl;

  /* Math: '<S241>/Math Function1' */
  locvar_MathFunction1_jr = locvar_ManualSwitch_py * locvar_ManualSwitch_py;

  /* Sum: '<S270>/Add' incorporates:
   *  Constant: '<S270>/Ixx1'
   *  Constant: '<S270>/Ixz1'
   *  Constant: '<S270>/Izz1'
   *  Math: '<S270>/Math Function'
   *  Product: '<S270>/Divide1'
   */
  locvar_ManualSwitch_ga = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S262>/Divide4' incorporates:
   *  Constant: '<S262>/Ixx'
   *  Constant: '<S262>/Ixz'
   *  Constant: '<S262>/Iyy'
   *  Constant: '<S262>/Izz'
   *  Product: '<S262>/Divide3'
   *  Sum: '<S262>/Add'
   */
  locvar_ManualSwitch_jq = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_ga;

  /* Sum: '<S229>/Add1' incorporates:
   *  Constant: '<S261>/Ixz'
   *  Constant: '<S261>/Iyy'
   *  Constant: '<S261>/Izz'
   *  Math: '<S261>/Math Function'
   *  Product: '<S229>/Divide2'
   *  Product: '<S229>/Divide3'
   *  Product: '<S261>/Divide3'
   *  Product: '<S261>/Divide4'
   *  Sum: '<S261>/Add'
   *  Sum: '<S261>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_ef = ((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_ga *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_ManualSwitch_jq *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* Sum: '<S252>/Add' incorporates:
   *  Constant: '<S252>/Constant10'
   *  Constant: '<S252>/Constant11'
   *  Constant: '<S252>/Constant12'
   *  Constant: '<S252>/Constant13'
   *  Constant: '<S252>/Constant14'
   *  Constant: '<S252>/Constant15'
   *  Constant: '<S252>/Constant5'
   *  Constant: '<S252>/Constant6'
   *  Constant: '<S252>/Constant7'
   *  Constant: '<S252>/Constant8'
   *  Constant: '<S252>/Constant9'
   *  Product: '<S252>/Divide3'
   *  Product: '<S252>/Divide4'
   *  Product: '<S252>/Divide5'
   *  Product: '<S252>/Divide6'
   *  Product: '<S252>/Divide7'
   *  Sum: '<S252>/Add1'
   *  Sum: '<S252>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * locvar_Add1_cn2) +
    ANN_EKF_NMPC_2_P.Cldr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S256>/Add' incorporates:
   *  Constant: '<S256>/Constant'
   *  Constant: '<S256>/Constant10'
   *  Constant: '<S256>/Constant11'
   *  Constant: '<S256>/Constant12'
   *  Constant: '<S256>/Constant13'
   *  Constant: '<S256>/Constant14'
   *  Constant: '<S256>/Constant15'
   *  Constant: '<S256>/Constant5'
   *  Constant: '<S256>/Constant6'
   *  Constant: '<S256>/Constant8'
   *  Constant: '<S256>/Constant9'
   *  Product: '<S256>/Divide3'
   *  Product: '<S256>/Divide4'
   *  Product: '<S256>/Divide5'
   *  Product: '<S256>/Divide6'
   *  Product: '<S256>/Divide7'
   *  Sum: '<S256>/Add1'
   *  Sum: '<S256>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Cnb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Cnr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Cnda * locvar_Add1_cn2) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S251>/Add' incorporates:
   *  Product: '<S251>/Divide3'
   *  Product: '<S251>/Divide5'
   *  Trigonometry: '<S251>/Trigonometric Function'
   *  Trigonometry: '<S251>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_il = locvar_Add2_o3 * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add2_db;

  /* Product: '<S264>/Divide4' incorporates:
   *  Constant: '<S264>/Ixz'
   */
  locvar_ManualSwitch_p0l = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_ga;

  /* Sum: '<S255>/Add2' incorporates:
   *  Product: '<S255>/Divide1'
   *  Product: '<S255>/Divide6'
   *  Trigonometry: '<S255>/Trigonometric Function4'
   *  Trigonometry: '<S255>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = locvar_Add2_o3 * sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])
    + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add2_db;

  /* Sum: '<S229>/Add' incorporates:
   *  Constant: '<S263>/Izz'
   *  Product: '<S229>/Divide'
   *  Product: '<S229>/Divide4'
   *  Product: '<S263>/Divide4'
   */
  locvar_Add_ccv = ANN_EKF_NMPC_2_P.IzzB / locvar_ManualSwitch_ga *
    locvar_ManualSwitch_il + locvar_ManualSwitch_p0l * locvar_Add2_o3;

  /* Product: '<S231>/Divide' incorporates:
   *  Constant: '<S254>/Constant'
   *  Constant: '<S254>/Constant1'
   *  Constant: '<S254>/Constant11'
   *  Constant: '<S254>/Constant12'
   *  Constant: '<S254>/Constant13'
   *  Constant: '<S254>/Constant14'
   *  Constant: '<S254>/Constant2'
   *  Constant: '<S254>/Constant3'
   *  Constant: '<S254>/Constant4'
   *  Constant: '<S254>/Constant5'
   *  Constant: '<S254>/Constant6'
   *  Constant: '<S254>/Constant7'
   *  Constant: '<S254>/Constant8'
   *  Constant: '<S254>/Constant9'
   *  Constant: '<S267>/Ixz'
   *  Constant: '<S267>/Iyy'
   *  Gain: '<S254>/Gain1'
   *  Gain: '<S254>/Gain2'
   *  Product: '<S254>/Divide1'
   *  Product: '<S254>/Divide2'
   *  Product: '<S254>/Divide3'
   *  Product: '<S254>/Divide4'
   *  Product: '<S254>/Divide5'
   *  Product: '<S254>/Divide6'
   *  Product: '<S267>/Divide4'
   *  Sum: '<S254>/Add'
   *  Sum: '<S254>/Add1'
   *  Sum: '<S254>/Add2'
   *  Sum: '<S254>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S240>/Unit Delay'
   */
  locvar_Divide_prh = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_m *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
    ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_gl -
    ANN_EKF_NMPC_2_P.Utrim)) + ANN_EKF_NMPC_2_P.Cmde *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                       ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_gl -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                       ANN_EKF_NMPC_2_P.Gain2_Gain_a *
                       ANN_EKF_NMPC_2_P.Gain1_Gain_a) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_l / ANN_EKF_NMPC_2_P.IyyB);

  /* Sum: '<S232>/Add1' incorporates:
   *  Constant: '<S268>/Ixx'
   *  Constant: '<S268>/Ixx1'
   *  Constant: '<S268>/Ixz'
   *  Constant: '<S268>/Iyy'
   *  Math: '<S268>/Math Function'
   *  Product: '<S232>/Divide2'
   *  Product: '<S232>/Divide3'
   *  Product: '<S268>/Divide3'
   *  Product: '<S268>/Divide4'
   *  Sum: '<S268>/Add'
   *  Sum: '<S268>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_es = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_ga *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_ManualSwitch_jq *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S232>/Add' incorporates:
   *  Constant: '<S269>/Ixx'
   *  Product: '<S232>/Divide'
   *  Product: '<S232>/Divide4'
   *  Product: '<S269>/Divide4'
   */
  locvar_Add_ifv = ANN_EKF_NMPC_2_P.IxxB / locvar_ManualSwitch_ga *
    locvar_Add2_o3 + locvar_ManualSwitch_p0l * locvar_ManualSwitch_il;

  /* Sum: '<S161>/Add1' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_lq2 = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Product: '<S458>/Divide2' incorporates:
   *  Trigonometry: '<S458>/Trigonometric Function'
   *  Trigonometry: '<S458>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_k5 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S460>/Divide2' incorporates:
   *  Trigonometry: '<S460>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_e4 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S463>/Divide2' incorporates:
   *  Trigonometry: '<S463>/Trigonometric Function'
   *  Trigonometry: '<S463>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_gl = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S455>/Divide4' incorporates:
   *  Constant: '<S455>/Constant'
   *  Constant: '<S455>/Constant1'
   *  Math: '<S455>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ko = ANN_EKF_NMPC_2_P.Constant_Value_nx *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S474>/Add' incorporates:
   *  Constant: '<S474>/Constant'
   *  Constant: '<S474>/Constant1'
   *  Constant: '<S474>/Constant10'
   *  Constant: '<S474>/Constant11'
   *  Constant: '<S474>/Constant12'
   *  Constant: '<S474>/Constant13'
   *  Constant: '<S474>/Constant14'
   *  Constant: '<S474>/Constant15'
   *  Constant: '<S474>/Constant2'
   *  Constant: '<S474>/Constant3'
   *  Constant: '<S474>/Constant4'
   *  Constant: '<S474>/Constant5'
   *  Constant: '<S474>/Constant6'
   *  Constant: '<S474>/Constant7'
   *  Constant: '<S474>/Constant8'
   *  Constant: '<S474>/Constant9'
   *  Gain: '<S474>/Gain1'
   *  Gain: '<S474>/Gain2'
   *  Gain: '<S474>/Gain3'
   *  Product: '<S474>/Divide1'
   *  Product: '<S474>/Divide2'
   *  Product: '<S474>/Divide3'
   *  Product: '<S474>/Divide4'
   *  Product: '<S474>/Divide5'
   *  Product: '<S474>/Divide6'
   *  Product: '<S474>/Divide7'
   *  Sum: '<S474>/Add1'
   *  Sum: '<S474>/Add2'
   *  Sum: '<S474>/Add3'
   *  Sum: '<S474>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S465>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_f *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_k5 - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
                   (locvar_ManualSwitch_k5 - ANN_EKF_NMPC_2_P.Utrim) *
                   ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain2_Gain_j *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_p) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_ln;

  /* ManualSwitch: '<S473>/Manual Switch' incorporates:
   *  Constant: '<S473>/AR'
   *  Constant: '<S473>/Constant15'
   *  Constant: '<S473>/Constant16'
   *  Constant: '<S473>/Constant17'
   *  Constant: '<S473>/Constant18'
   *  Constant: '<S473>/e'
   *  Math: '<S473>/Math Function'
   *  Product: '<S473>/Divide8'
   *  Product: '<S473>/Divide9'
   *  Sum: '<S473>/Add5'
   *  Sum: '<S473>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_i5 == 1) {
    locvar_ManualSwitch_b = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_b = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_am / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_l +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S473>/Manual Switch' */

  /* Sum: '<S473>/Add' incorporates:
   *  Constant: '<S473>/Constant1'
   *  Constant: '<S473>/Constant10'
   *  Constant: '<S473>/Constant11'
   *  Constant: '<S473>/Constant12'
   *  Constant: '<S473>/Constant13'
   *  Constant: '<S473>/Constant14'
   *  Constant: '<S473>/Constant2'
   *  Constant: '<S473>/Constant3'
   *  Constant: '<S473>/Constant4'
   *  Constant: '<S473>/Constant6'
   *  Constant: '<S473>/Constant7'
   *  Constant: '<S473>/Constant8'
   *  Constant: '<S473>/Constant9'
   *  Gain: '<S473>/Gain1'
   *  Gain: '<S473>/Gain2'
   *  Gain: '<S473>/Gain3'
   *  Product: '<S473>/Divide1'
   *  Product: '<S473>/Divide2'
   *  Product: '<S473>/Divide3'
   *  Product: '<S473>/Divide5'
   *  Product: '<S473>/Divide6'
   *  Product: '<S473>/Divide7'
   *  Sum: '<S473>/Add1'
   *  Sum: '<S473>/Add2'
   *  Sum: '<S473>/Add3'
   *  Sum: '<S473>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S465>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_b) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_f *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_k5 - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_k5 -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_fs *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_dh) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_p;

  /* ManualSwitch: '<S459>/Manual Switch' incorporates:
   *  Constant: '<S459>/Constant1'
   *  Constant: '<S467>/Constant'
   *  Constant: '<S485>/Constant'
   *  Constant: '<S485>/Constant1'
   *  Constant: '<S485>/Constant2'
   *  Math: '<S485>/Math Function'
   *  Product: '<S459>/Divide'
   *  Product: '<S459>/Divide5'
   *  Product: '<S482>/Divide3'
   *  Product: '<S482>/Divide5'
   *  Product: '<S485>/Divide1'
   *  Product: '<S485>/Divide2'
   *  Sum: '<S459>/Add'
   *  Sum: '<S482>/Add'
   *  Sum: '<S485>/Add'
   *  Trigonometry: '<S482>/Trigonometric Function'
   *  Trigonometry: '<S482>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_gx == 1) {
    /* Gain: '<S485>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_o *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_b = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_ko * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_b = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S459>/Manual Switch' */

  /* Sum: '<S459>/Add1' incorporates:
   *  Constant: '<S459>/Constant'
   *  Product: '<S459>/Divide2'
   *  Product: '<S459>/Divide3'
   *  Product: '<S459>/Divide4'
   *  Trigonometry: '<S459>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_py = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_e4 - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_gl) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_b;

  /* Product: '<S461>/Divide3' */
  locvar_Divide3_npq = locvar_ManualSwitch_k5 * locvar_ManualSwitch_py;

  /* ManualSwitch: '<S462>/Manual Switch' incorporates:
   *  Constant: '<S462>/Constant1'
   *  Constant: '<S467>/Constant'
   *  Constant: '<S475>/Constant'
   *  Constant: '<S475>/Constant1'
   *  Constant: '<S475>/Constant10'
   *  Constant: '<S475>/Constant11'
   *  Constant: '<S475>/Constant12'
   *  Constant: '<S475>/Constant2'
   *  Constant: '<S475>/Constant3'
   *  Constant: '<S475>/Constant4'
   *  Constant: '<S475>/Constant5'
   *  Constant: '<S475>/Constant6'
   *  Constant: '<S475>/Constant8'
   *  Product: '<S462>/Divide'
   *  Product: '<S462>/Divide5'
   *  Product: '<S475>/Divide1'
   *  Product: '<S475>/Divide3'
   *  Product: '<S475>/Divide4'
   *  Product: '<S475>/Divide5'
   *  Product: '<S475>/Divide6'
   *  Sum: '<S475>/Add'
   *  Sum: '<S475>/Add1'
   *  Sum: '<S475>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_l == 1) {
    locvar_ManualSwitch_if = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * locvar_Add1_lq2) * (locvar_Divide4_ko *
      ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight / ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_if = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S462>/Manual Switch' */

  /* Sum: '<S462>/Add1' incorporates:
   *  Constant: '<S462>/Constant'
   *  Product: '<S462>/Divide2'
   *  Product: '<S462>/Divide3'
   *  Product: '<S462>/Divide4'
   *  Trigonometry: '<S462>/Trigonometric Function'
   *  Trigonometry: '<S462>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_gl - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_k5) + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_if;

  /* Product: '<S461>/Divide4' */
  locvar_Divide4_lhf = locvar_ManualSwitch_e4 * locvar_ManualSwitch_ga;

  /* ManualSwitch: '<S464>/Manual Switch' incorporates:
   *  Constant: '<S464>/Constant1'
   *  Constant: '<S467>/Constant'
   *  Product: '<S464>/Divide'
   *  Product: '<S464>/Divide5'
   *  Product: '<S484>/Divide1'
   *  Product: '<S484>/Divide6'
   *  Sum: '<S484>/Add2'
   *  Trigonometry: '<S484>/Trigonometric Function4'
   *  Trigonometry: '<S484>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ih == 1) {
    locvar_ManualSwitch_jq = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_ko * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_jq = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S464>/Manual Switch' */

  /* Sum: '<S464>/Add1' incorporates:
   *  Constant: '<S464>/Constant'
   *  Product: '<S464>/Divide2'
   *  Product: '<S464>/Divide3'
   *  Product: '<S464>/Divide4'
   *  Trigonometry: '<S464>/Trigonometric Function'
   *  Trigonometry: '<S464>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_i1 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_k5 - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_e4) + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_jq;

  /* Product: '<S461>/Divide5' */
  locvar_Divide5_ol = locvar_ManualSwitch_gl * locvar_ManualSwitch_i1;

  /* Product: '<S465>/Divide' incorporates:
   *  Math: '<S465>/Math Function'
   *  Math: '<S465>/Math Function1'
   *  Product: '<S465>/Divide3'
   *  Product: '<S465>/Divide4'
   *  Sum: '<S465>/Add'
   *  Sum: '<S465>/Add1'
   */
  locvar_Divide_hc = (locvar_ManualSwitch_k5 * locvar_ManualSwitch_i1 -
                      locvar_ManualSwitch_gl * locvar_ManualSwitch_py) /
    (locvar_ManualSwitch_k5 * locvar_ManualSwitch_k5 + locvar_ManualSwitch_gl *
     locvar_ManualSwitch_gl);

  /* Product: '<S466>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide3_io = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    locvar_ManualSwitch_ga;

  /* Product: '<S466>/Divide4' incorporates:
   *  Product: '<S466>/Divide1'
   *  Product: '<S466>/Divide2'
   *  Product: '<S466>/Divide5'
   *  Product: '<S466>/Divide6'
   *  Sum: '<S466>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_fy = ((locvar_ManualSwitch_k5 * locvar_ManualSwitch_py +
                        locvar_ManualSwitch_e4 * locvar_ManualSwitch_ga) +
                       locvar_ManualSwitch_gl * locvar_ManualSwitch_i1) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_e4;

  /* Math: '<S466>/Math Function' */
  locvar_MathFunction_iy = locvar_ManualSwitch_k5 * locvar_ManualSwitch_k5;

  /* Math: '<S466>/Math Function1' */
  locvar_MathFunction1_cr = locvar_ManualSwitch_gl * locvar_ManualSwitch_gl;

  /* Sum: '<S495>/Add' incorporates:
   *  Constant: '<S495>/Ixx1'
   *  Constant: '<S495>/Ixz1'
   *  Constant: '<S495>/Izz1'
   *  Math: '<S495>/Math Function'
   *  Product: '<S495>/Divide1'
   */
  locvar_ManualSwitch_ga = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S487>/Divide4' incorporates:
   *  Constant: '<S487>/Ixx'
   *  Constant: '<S487>/Ixz'
   *  Constant: '<S487>/Iyy'
   *  Constant: '<S487>/Izz'
   *  Product: '<S487>/Divide3'
   *  Sum: '<S487>/Add'
   */
  locvar_ManualSwitch_i1 = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_ga;

  /* Sum: '<S454>/Add1' incorporates:
   *  Constant: '<S486>/Ixz'
   *  Constant: '<S486>/Iyy'
   *  Constant: '<S486>/Izz'
   *  Math: '<S486>/Math Function'
   *  Product: '<S454>/Divide2'
   *  Product: '<S454>/Divide3'
   *  Product: '<S486>/Divide3'
   *  Product: '<S486>/Divide4'
   *  Sum: '<S486>/Add'
   *  Sum: '<S486>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_k4 = ((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_ga *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_ManualSwitch_i1 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* Sum: '<S477>/Add' incorporates:
   *  Constant: '<S477>/Constant10'
   *  Constant: '<S477>/Constant11'
   *  Constant: '<S477>/Constant12'
   *  Constant: '<S477>/Constant13'
   *  Constant: '<S477>/Constant14'
   *  Constant: '<S477>/Constant15'
   *  Constant: '<S477>/Constant5'
   *  Constant: '<S477>/Constant6'
   *  Constant: '<S477>/Constant7'
   *  Constant: '<S477>/Constant8'
   *  Constant: '<S477>/Constant9'
   *  Product: '<S477>/Divide3'
   *  Product: '<S477>/Divide4'
   *  Product: '<S477>/Divide5'
   *  Product: '<S477>/Divide6'
   *  Product: '<S477>/Divide7'
   *  Sum: '<S477>/Add1'
   *  Sum: '<S477>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr * locvar_Add1_lq2;

  /* Sum: '<S481>/Add' incorporates:
   *  Constant: '<S481>/Constant'
   *  Constant: '<S481>/Constant10'
   *  Constant: '<S481>/Constant11'
   *  Constant: '<S481>/Constant12'
   *  Constant: '<S481>/Constant13'
   *  Constant: '<S481>/Constant14'
   *  Constant: '<S481>/Constant15'
   *  Constant: '<S481>/Constant5'
   *  Constant: '<S481>/Constant6'
   *  Constant: '<S481>/Constant8'
   *  Constant: '<S481>/Constant9'
   *  Product: '<S481>/Divide3'
   *  Product: '<S481>/Divide4'
   *  Product: '<S481>/Divide5'
   *  Product: '<S481>/Divide6'
   *  Product: '<S481>/Divide7'
   *  Sum: '<S481>/Add1'
   *  Sum: '<S481>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ex = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * locvar_Add1_lq2;

  /* Sum: '<S476>/Add' incorporates:
   *  Product: '<S476>/Divide3'
   *  Product: '<S476>/Divide5'
   *  Trigonometry: '<S476>/Trigonometric Function'
   *  Trigonometry: '<S476>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_li = locvar_Add2_db * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_ex;

  /* Product: '<S489>/Divide4' incorporates:
   *  Constant: '<S489>/Ixz'
   */
  locvar_ManualSwitch_d = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_ga;

  /* Sum: '<S480>/Add2' incorporates:
   *  Product: '<S480>/Divide1'
   *  Product: '<S480>/Divide6'
   *  Trigonometry: '<S480>/Trigonometric Function4'
   *  Trigonometry: '<S480>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ex = locvar_Add2_db * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_ex;

  /* Sum: '<S454>/Add' incorporates:
   *  Constant: '<S488>/Izz'
   *  Product: '<S454>/Divide'
   *  Product: '<S454>/Divide4'
   *  Product: '<S488>/Divide4'
   */
  locvar_Add_mx3 = ANN_EKF_NMPC_2_P.IzzB / locvar_ManualSwitch_ga *
    locvar_ManualSwitch_li + locvar_ManualSwitch_d * locvar_ManualSwitch_ex;

  /* Product: '<S456>/Divide' incorporates:
   *  Constant: '<S479>/Constant'
   *  Constant: '<S479>/Constant1'
   *  Constant: '<S479>/Constant11'
   *  Constant: '<S479>/Constant12'
   *  Constant: '<S479>/Constant13'
   *  Constant: '<S479>/Constant14'
   *  Constant: '<S479>/Constant2'
   *  Constant: '<S479>/Constant3'
   *  Constant: '<S479>/Constant4'
   *  Constant: '<S479>/Constant5'
   *  Constant: '<S479>/Constant6'
   *  Constant: '<S479>/Constant7'
   *  Constant: '<S479>/Constant8'
   *  Constant: '<S479>/Constant9'
   *  Constant: '<S492>/Ixz'
   *  Constant: '<S492>/Iyy'
   *  Gain: '<S479>/Gain1'
   *  Gain: '<S479>/Gain2'
   *  Product: '<S479>/Divide1'
   *  Product: '<S479>/Divide2'
   *  Product: '<S479>/Divide3'
   *  Product: '<S479>/Divide4'
   *  Product: '<S479>/Divide5'
   *  Product: '<S479>/Divide6'
   *  Product: '<S492>/Divide4'
   *  Sum: '<S479>/Add'
   *  Sum: '<S479>/Add1'
   *  Sum: '<S479>/Add2'
   *  Sum: '<S479>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S465>/Unit Delay'
   */
  locvar_Divide_dc = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_f *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                        ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
                        (locvar_ManualSwitch_k5 - ANN_EKF_NMPC_2_P.Utrim)) +
                       ANN_EKF_NMPC_2_P.Cmde *
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                      ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_k5 -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                      ANN_EKF_NMPC_2_P.Gain2_Gain_if *
                      ANN_EKF_NMPC_2_P.Gain1_Gain_e4) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_n / ANN_EKF_NMPC_2_P.IyyB);

  /* Sum: '<S457>/Add1' incorporates:
   *  Constant: '<S493>/Ixx'
   *  Constant: '<S493>/Ixx1'
   *  Constant: '<S493>/Ixz'
   *  Constant: '<S493>/Iyy'
   *  Math: '<S493>/Math Function'
   *  Product: '<S457>/Divide2'
   *  Product: '<S457>/Divide3'
   *  Product: '<S493>/Divide3'
   *  Product: '<S493>/Divide4'
   *  Sum: '<S493>/Add'
   *  Sum: '<S493>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_e0 = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_ga *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_ManualSwitch_i1 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S457>/Add' incorporates:
   *  Constant: '<S494>/Ixx'
   *  Product: '<S457>/Divide'
   *  Product: '<S457>/Divide4'
   *  Product: '<S494>/Divide4'
   */
  locvar_Add_df5 = ANN_EKF_NMPC_2_P.IxxB / locvar_ManualSwitch_ga *
    locvar_ManualSwitch_ex + locvar_ManualSwitch_d * locvar_ManualSwitch_li;

  /* Sum: '<S163>/Add1' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_il = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4];

  /* Product: '<S548>/Divide2' incorporates:
   *  Trigonometry: '<S548>/Trigonometric Function'
   *  Trigonometry: '<S548>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_c = locvar_ManualSwitch_il * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S550>/Divide2' incorporates:
   *  Trigonometry: '<S550>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_oa = locvar_ManualSwitch_il * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S553>/Divide2' incorporates:
   *  Trigonometry: '<S553>/Trigonometric Function'
   *  Trigonometry: '<S553>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_k5 = locvar_ManualSwitch_il * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S545>/Divide4' incorporates:
   *  Constant: '<S545>/Constant'
   *  Constant: '<S545>/Constant1'
   *  Math: '<S545>/Math Function'
   */
  locvar_Divide4_c1v = ANN_EKF_NMPC_2_P.Constant_Value_dw *
    ANN_EKF_NMPC_2_P.rho_o * (locvar_ManualSwitch_il * locvar_ManualSwitch_il);

  /* Sum: '<S564>/Add' incorporates:
   *  Constant: '<S564>/Constant'
   *  Constant: '<S564>/Constant1'
   *  Constant: '<S564>/Constant10'
   *  Constant: '<S564>/Constant11'
   *  Constant: '<S564>/Constant12'
   *  Constant: '<S564>/Constant13'
   *  Constant: '<S564>/Constant14'
   *  Constant: '<S564>/Constant15'
   *  Constant: '<S564>/Constant2'
   *  Constant: '<S564>/Constant3'
   *  Constant: '<S564>/Constant4'
   *  Constant: '<S564>/Constant5'
   *  Constant: '<S564>/Constant6'
   *  Constant: '<S564>/Constant7'
   *  Constant: '<S564>/Constant8'
   *  Constant: '<S564>/Constant9'
   *  Gain: '<S564>/Gain1'
   *  Gain: '<S564>/Gain2'
   *  Gain: '<S564>/Gain3'
   *  Product: '<S564>/Divide1'
   *  Product: '<S564>/Divide2'
   *  Product: '<S564>/Divide3'
   *  Product: '<S564>/Divide4'
   *  Product: '<S564>/Divide5'
   *  Product: '<S564>/Divide6'
   *  Product: '<S564>/Divide7'
   *  Sum: '<S564>/Add1'
   *  Sum: '<S564>/Add2'
   *  Sum: '<S564>/Add3'
   *  Sum: '<S564>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S555>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_i *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_c - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_c
    - ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                   ANN_EKF_NMPC_2_P.Gain2_Gain_py *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_gj) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_ov;

  /* ManualSwitch: '<S563>/Manual Switch' incorporates:
   *  Constant: '<S563>/AR'
   *  Constant: '<S563>/Constant15'
   *  Constant: '<S563>/Constant16'
   *  Constant: '<S563>/Constant17'
   *  Constant: '<S563>/Constant18'
   *  Constant: '<S563>/e'
   *  Math: '<S563>/Math Function'
   *  Product: '<S563>/Divide8'
   *  Product: '<S563>/Divide9'
   *  Sum: '<S563>/Add5'
   *  Sum: '<S563>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_m == 1) {
    locvar_ManualSwitch_e4 = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_e4 = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_lw / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_be +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S563>/Manual Switch' */

  /* Sum: '<S563>/Add' incorporates:
   *  Constant: '<S563>/Constant1'
   *  Constant: '<S563>/Constant10'
   *  Constant: '<S563>/Constant11'
   *  Constant: '<S563>/Constant12'
   *  Constant: '<S563>/Constant13'
   *  Constant: '<S563>/Constant14'
   *  Constant: '<S563>/Constant2'
   *  Constant: '<S563>/Constant3'
   *  Constant: '<S563>/Constant4'
   *  Constant: '<S563>/Constant6'
   *  Constant: '<S563>/Constant7'
   *  Constant: '<S563>/Constant8'
   *  Constant: '<S563>/Constant9'
   *  Gain: '<S563>/Gain1'
   *  Gain: '<S563>/Gain2'
   *  Gain: '<S563>/Gain3'
   *  Product: '<S563>/Divide1'
   *  Product: '<S563>/Divide2'
   *  Product: '<S563>/Divide3'
   *  Product: '<S563>/Divide5'
   *  Product: '<S563>/Divide6'
   *  Product: '<S563>/Divide7'
   *  Sum: '<S563>/Add1'
   *  Sum: '<S563>/Add2'
   *  Sum: '<S563>/Add3'
   *  Sum: '<S563>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S555>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_e4) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_i *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_c - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_c -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_ne *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_ch) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_h;

  /* ManualSwitch: '<S549>/Manual Switch' incorporates:
   *  Constant: '<S549>/Constant1'
   *  Constant: '<S557>/Constant'
   *  Constant: '<S575>/Constant'
   *  Constant: '<S575>/Constant1'
   *  Constant: '<S575>/Constant2'
   *  Math: '<S575>/Math Function'
   *  Product: '<S549>/Divide'
   *  Product: '<S549>/Divide5'
   *  Product: '<S572>/Divide3'
   *  Product: '<S572>/Divide5'
   *  Product: '<S575>/Divide1'
   *  Product: '<S575>/Divide2'
   *  Sum: '<S549>/Add'
   *  Sum: '<S572>/Add'
   *  Sum: '<S575>/Add'
   *  Trigonometry: '<S572>/Trigonometric Function'
   *  Trigonometry: '<S572>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_o == 1) {
    /* Gain: '<S575>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_k *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_e4 = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_e4 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S549>/Manual Switch' */

  /* Sum: '<S549>/Add1' incorporates:
   *  Constant: '<S549>/Constant'
   *  Product: '<S549>/Divide2'
   *  Product: '<S549>/Divide3'
   *  Product: '<S549>/Divide4'
   *  Trigonometry: '<S549>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_gl = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_oa - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_k5) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_e4;

  /* ManualSwitch: '<S552>/Manual Switch' incorporates:
   *  Constant: '<S552>/Constant1'
   *  Constant: '<S557>/Constant'
   *  Constant: '<S565>/Constant'
   *  Constant: '<S565>/Constant1'
   *  Constant: '<S565>/Constant10'
   *  Constant: '<S565>/Constant11'
   *  Constant: '<S565>/Constant12'
   *  Constant: '<S565>/Constant2'
   *  Constant: '<S565>/Constant3'
   *  Constant: '<S565>/Constant4'
   *  Constant: '<S565>/Constant5'
   *  Constant: '<S565>/Constant6'
   *  Constant: '<S565>/Constant8'
   *  Product: '<S552>/Divide'
   *  Product: '<S552>/Divide5'
   *  Product: '<S565>/Divide1'
   *  Product: '<S565>/Divide3'
   *  Product: '<S565>/Divide4'
   *  Product: '<S565>/Divide5'
   *  Product: '<S565>/Divide6'
   *  Sum: '<S565>/Add'
   *  Sum: '<S565>/Add1'
   *  Sum: '<S565>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_fk == 1) {
    locvar_ManualSwitch_py = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_py = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S552>/Manual Switch' */

  /* Sum: '<S552>/Add1' incorporates:
   *  Constant: '<S552>/Constant'
   *  Product: '<S552>/Divide2'
   *  Product: '<S552>/Divide3'
   *  Product: '<S552>/Divide4'
   *  Trigonometry: '<S552>/Trigonometric Function'
   *  Trigonometry: '<S552>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_k5 - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_c) + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_py;

  /* ManualSwitch: '<S554>/Manual Switch' incorporates:
   *  Constant: '<S554>/Constant1'
   *  Constant: '<S557>/Constant'
   *  Product: '<S554>/Divide'
   *  Product: '<S554>/Divide5'
   *  Product: '<S574>/Divide1'
   *  Product: '<S574>/Divide6'
   *  Sum: '<S574>/Add2'
   *  Trigonometry: '<S574>/Trigonometric Function4'
   *  Trigonometry: '<S574>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ae == 1) {
    locvar_ManualSwitch_i1 = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_i1 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S554>/Manual Switch' */

  /* Sum: '<S554>/Add1' incorporates:
   *  Constant: '<S554>/Constant'
   *  Product: '<S554>/Divide2'
   *  Product: '<S554>/Divide3'
   *  Product: '<S554>/Divide4'
   *  Trigonometry: '<S554>/Trigonometric Function'
   *  Trigonometry: '<S554>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
                     locvar_ManualSwitch_c -
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
                     locvar_ManualSwitch_oa) + cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_i1;

  /* Product: '<S551>/Divide' incorporates:
   *  Product: '<S551>/Divide3'
   *  Product: '<S551>/Divide4'
   *  Product: '<S551>/Divide5'
   *  Sum: '<S551>/Add'
   */
  locvar_Add2_db = ((locvar_ManualSwitch_c * locvar_ManualSwitch_gl +
                     locvar_ManualSwitch_oa * locvar_ManualSwitch_ga) +
                    locvar_ManualSwitch_k5 * locvar_Add2_o3) /
    locvar_ManualSwitch_il;

  /* Product: '<S555>/Divide' incorporates:
   *  Math: '<S555>/Math Function'
   *  Math: '<S555>/Math Function1'
   *  Product: '<S555>/Divide3'
   *  Product: '<S555>/Divide4'
   *  Sum: '<S555>/Add'
   *  Sum: '<S555>/Add1'
   */
  locvar_Divide_en = (locvar_ManualSwitch_c * locvar_Add2_o3 -
                      locvar_ManualSwitch_k5 * locvar_ManualSwitch_gl) /
    (locvar_ManualSwitch_c * locvar_ManualSwitch_c + locvar_ManualSwitch_k5 *
     locvar_ManualSwitch_k5);

  /* Product: '<S556>/Divide3' */
  locvar_Add_kq = locvar_ManualSwitch_il * locvar_ManualSwitch_ga;

  /* Product: '<S556>/Divide4' incorporates:
   *  Product: '<S556>/Divide1'
   *  Product: '<S556>/Divide2'
   *  Product: '<S556>/Divide5'
   *  Product: '<S556>/Divide6'
   *  Sum: '<S556>/Add2'
   */
  locvar_Gain_ar = ((locvar_ManualSwitch_c * locvar_ManualSwitch_gl +
                     locvar_ManualSwitch_oa * locvar_ManualSwitch_ga) +
                    locvar_ManualSwitch_k5 * locvar_Add2_o3) /
    locvar_ManualSwitch_il * locvar_ManualSwitch_oa;

  /* Sum: '<S585>/Add' incorporates:
   *  Constant: '<S585>/Ixx1'
   *  Constant: '<S585>/Ixz1'
   *  Constant: '<S585>/Izz1'
   *  Math: '<S585>/Math Function'
   *  Product: '<S585>/Divide1'
   */
  locvar_ManualSwitch_gl = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S577>/Divide4' incorporates:
   *  Constant: '<S577>/Ixx'
   *  Constant: '<S577>/Ixz'
   *  Constant: '<S577>/Iyy'
   *  Constant: '<S577>/Izz'
   *  Product: '<S577>/Divide3'
   *  Sum: '<S577>/Add'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_gl;

  /* Sum: '<S567>/Add' incorporates:
   *  Constant: '<S567>/Constant10'
   *  Constant: '<S567>/Constant11'
   *  Constant: '<S567>/Constant12'
   *  Constant: '<S567>/Constant13'
   *  Constant: '<S567>/Constant14'
   *  Constant: '<S567>/Constant15'
   *  Constant: '<S567>/Constant5'
   *  Constant: '<S567>/Constant6'
   *  Constant: '<S567>/Constant7'
   *  Constant: '<S567>/Constant8'
   *  Constant: '<S567>/Constant9'
   *  Product: '<S567>/Divide3'
   *  Product: '<S567>/Divide4'
   *  Product: '<S567>/Divide5'
   *  Product: '<S567>/Divide6'
   *  Product: '<S567>/Divide7'
   *  Sum: '<S567>/Add1'
   *  Sum: '<S567>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S571>/Add' incorporates:
   *  Constant: '<S571>/Constant'
   *  Constant: '<S571>/Constant10'
   *  Constant: '<S571>/Constant11'
   *  Constant: '<S571>/Constant12'
   *  Constant: '<S571>/Constant13'
   *  Constant: '<S571>/Constant14'
   *  Constant: '<S571>/Constant15'
   *  Constant: '<S571>/Constant5'
   *  Constant: '<S571>/Constant6'
   *  Constant: '<S571>/Constant8'
   *  Constant: '<S571>/Constant9'
   *  Product: '<S571>/Divide3'
   *  Product: '<S571>/Divide4'
   *  Product: '<S571>/Divide5'
   *  Product: '<S571>/Divide6'
   *  Product: '<S571>/Divide7'
   *  Sum: '<S571>/Add1'
   *  Sum: '<S571>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_h2 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S566>/Add' incorporates:
   *  Product: '<S566>/Divide3'
   *  Product: '<S566>/Divide5'
   *  Trigonometry: '<S566>/Trigonometric Function'
   *  Trigonometry: '<S566>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_lz = locvar_Add2_o3 * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_h2;

  /* Product: '<S579>/Divide4' incorporates:
   *  Constant: '<S579>/Ixz'
   */
  locvar_ManualSwitch_m = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_gl;

  /* Sum: '<S570>/Add2' incorporates:
   *  Product: '<S570>/Divide1'
   *  Product: '<S570>/Divide6'
   *  Trigonometry: '<S570>/Trigonometric Function4'
   *  Trigonometry: '<S570>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_h2 = locvar_Add2_o3 * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_h2;

  /* Saturate: '<S541>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Product: '<S151>/Divide4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S541>/Gain'
   *  Gain: '<S541>/Gain1'
   *  Saturate: '<S541>/Throttle Limiter'
   *  Sum: '<S151>/Sum4'
   *  Sum: '<S541>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ok[0] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S541>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Product: '<S151>/Divide4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S541>/Gain2'
   *  Gain: '<S541>/Gain3'
   *  Saturate: '<S541>/Elevator Limiter'
   *  Sum: '<S151>/Sum4'
   *  Sum: '<S541>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ok[1] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S541>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Product: '<S151>/Divide4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S541>/Gain4'
   *  Gain: '<S541>/Gain5'
   *  Saturate: '<S541>/Aileron Limiter'
   *  Sum: '<S151>/Sum4'
   *  Sum: '<S541>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ok[2] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S541>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Product: '<S151>/Divide4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S541>/Gain6'
   *  Gain: '<S541>/Gain7'
   *  Math: '<S556>/Math Function'
   *  Math: '<S556>/Math Function1'
   *  Product: '<S556>/Divide'
   *  Saturate: '<S541>/Rudder Limiter'
   *  Sum: '<S151>/Sum4'
   *  Sum: '<S541>/Add3'
   *  Sum: '<S556>/Add'
   *  Sum: '<S556>/Add1'
   *  Trigonometry: '<S556>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ok[3] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[4] = (locvar_Add2_db - locvar_Divide_ad) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[5] = (locvar_Divide_en - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[6] = ((locvar_Add_kq - locvar_Gain_ar) /
    (locvar_ManualSwitch_c * locvar_ManualSwitch_c + locvar_ManualSwitch_k5 *
     locvar_ManualSwitch_k5) * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) -
    locvar_Divide_je) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Trigonometry: '<S559>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S559>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_b) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_b;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_m) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_m;
    }
  }

  /* Product: '<S151>/Divide4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S544>/Constant1'
   *  Constant: '<S544>/Constant2'
   *  Constant: '<S546>/Constant1'
   *  Constant: '<S546>/Constant2'
   *  Constant: '<S547>/Constant1'
   *  Constant: '<S547>/Constant2'
   *  Constant: '<S560>/Constant'
   *  Constant: '<S561>/Constant'
   *  Constant: '<S569>/Constant'
   *  Constant: '<S569>/Constant1'
   *  Constant: '<S569>/Constant11'
   *  Constant: '<S569>/Constant12'
   *  Constant: '<S569>/Constant13'
   *  Constant: '<S569>/Constant14'
   *  Constant: '<S569>/Constant2'
   *  Constant: '<S569>/Constant3'
   *  Constant: '<S569>/Constant4'
   *  Constant: '<S569>/Constant5'
   *  Constant: '<S569>/Constant6'
   *  Constant: '<S569>/Constant7'
   *  Constant: '<S569>/Constant8'
   *  Constant: '<S569>/Constant9'
   *  Constant: '<S576>/Ixz'
   *  Constant: '<S576>/Iyy'
   *  Constant: '<S576>/Izz'
   *  Constant: '<S578>/Izz'
   *  Constant: '<S580>/Ixx'
   *  Constant: '<S580>/Iyy'
   *  Constant: '<S580>/Izz'
   *  Constant: '<S581>/Ixz'
   *  Constant: '<S581>/Iyy'
   *  Constant: '<S582>/Ixz'
   *  Constant: '<S582>/Iyy'
   *  Constant: '<S583>/Ixx'
   *  Constant: '<S583>/Ixx1'
   *  Constant: '<S583>/Ixz'
   *  Constant: '<S583>/Iyy'
   *  Constant: '<S584>/Ixx'
   *  Gain: '<S569>/Gain1'
   *  Gain: '<S569>/Gain2'
   *  Math: '<S546>/Math Function'
   *  Math: '<S546>/Math Function1'
   *  Math: '<S576>/Math Function'
   *  Math: '<S583>/Math Function'
   *  Product: '<S544>/Divide'
   *  Product: '<S544>/Divide1'
   *  Product: '<S544>/Divide2'
   *  Product: '<S544>/Divide3'
   *  Product: '<S544>/Divide4'
   *  Product: '<S544>/Divide5'
   *  Product: '<S544>/Divide6'
   *  Product: '<S546>/Divide'
   *  Product: '<S546>/Divide2'
   *  Product: '<S546>/Divide3'
   *  Product: '<S546>/Divide5'
   *  Product: '<S546>/Divide6'
   *  Product: '<S547>/Divide'
   *  Product: '<S547>/Divide1'
   *  Product: '<S547>/Divide2'
   *  Product: '<S547>/Divide3'
   *  Product: '<S547>/Divide4'
   *  Product: '<S547>/Divide5'
   *  Product: '<S547>/Divide6'
   *  Product: '<S559>/Divide1'
   *  Product: '<S559>/Divide2'
   *  Product: '<S559>/Divide4'
   *  Product: '<S562>/Divide2'
   *  Product: '<S562>/Divide4'
   *  Product: '<S569>/Divide1'
   *  Product: '<S569>/Divide2'
   *  Product: '<S569>/Divide3'
   *  Product: '<S569>/Divide4'
   *  Product: '<S569>/Divide5'
   *  Product: '<S569>/Divide6'
   *  Product: '<S576>/Divide3'
   *  Product: '<S576>/Divide4'
   *  Product: '<S578>/Divide4'
   *  Product: '<S580>/Divide4'
   *  Product: '<S581>/Divide4'
   *  Product: '<S582>/Divide4'
   *  Product: '<S583>/Divide3'
   *  Product: '<S583>/Divide4'
   *  Product: '<S584>/Divide4'
   *  Saturate: '<S559>/Saturation'
   *  Sum: '<S151>/Sum4'
   *  Sum: '<S544>/Add'
   *  Sum: '<S544>/Add1'
   *  Sum: '<S544>/Add2'
   *  Sum: '<S546>/Add1'
   *  Sum: '<S546>/Add3'
   *  Sum: '<S547>/Add'
   *  Sum: '<S547>/Add1'
   *  Sum: '<S547>/Add2'
   *  Sum: '<S559>/Add'
   *  Sum: '<S559>/Add1'
   *  Sum: '<S562>/Add'
   *  Sum: '<S569>/Add'
   *  Sum: '<S569>/Add1'
   *  Sum: '<S569>/Add2'
   *  Sum: '<S569>/Add3'
   *  Sum: '<S576>/Add'
   *  Sum: '<S576>/Add1'
   *  Sum: '<S580>/Add'
   *  Sum: '<S583>/Add'
   *  Sum: '<S583>/Add1'
   *  Trigonometry: '<S559>/Trigonometric Function1'
   *  Trigonometry: '<S559>/Trigonometric Function2'
   *  Trigonometry: '<S562>/Trigonometric Function1'
   *  Trigonometry: '<S562>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S555>/Unit Delay'
   */
  locvar_Divide4_ok[7] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[8] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[9] = (((((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB) /
    locvar_ManualSwitch_gl * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] +
    locvar_ManualSwitch_ga * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IzzB /
    locvar_ManualSwitch_gl * locvar_ManualSwitch_lz + locvar_ManualSwitch_m *
    locvar_ManualSwitch_h2) * (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b)) - locvar_Add2_ga) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[10] = ((((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_i *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
    ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_c -
    ANN_EKF_NMPC_2_P.Utrim)) + ANN_EKF_NMPC_2_P.Cmde *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
    (locvar_ManualSwitch_c - ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
    ANN_EKF_NMPC_2_P.Gain2_Gain_k * ANN_EKF_NMPC_2_P.Gain1_Gain_he) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_a / ANN_EKF_NMPC_2_P.IyyB) * (locvar_Divide4_c1v
    * ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.Cbar) + ((ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxxB) / ANN_EKF_NMPC_2_P.IyyB *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB))) - locvar_Add1_ir) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[11] = (((((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB) /
    locvar_ManualSwitch_gl * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    locvar_ManualSwitch_ga * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IxxB /
    locvar_ManualSwitch_gl * locvar_ManualSwitch_h2 + locvar_ManualSwitch_m *
    locvar_ManualSwitch_lz) * (locvar_Divide4_c1v * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b)) - locvar_Divide_j0) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[12] = (ANN_EKF_NMPC_2_P.Constant_Value_e -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Divide4_ok[13] = (ANN_EKF_NMPC_2_P.Constant_Value_mb -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Sum: '<S164>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_c1v = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5];

  /* Product: '<S593>/Divide2' incorporates:
   *  Trigonometry: '<S593>/Trigonometric Function'
   *  Trigonometry: '<S593>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_li = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (locvar_Divide4_c1v) * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S595>/Divide2' incorporates:
   *  Trigonometry: '<S595>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ex = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S598>/Divide2' incorporates:
   *  Trigonometry: '<S598>/Trigonometric Function'
   *  Trigonometry: '<S598>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_p0l = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (locvar_Divide4_c1v) * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S590>/Divide4' incorporates:
   *  Constant: '<S590>/Constant'
   *  Constant: '<S590>/Constant1'
   *  Math: '<S590>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ipd = ANN_EKF_NMPC_2_P.Constant_Value_my *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S609>/Add' incorporates:
   *  Constant: '<S609>/Constant'
   *  Constant: '<S609>/Constant1'
   *  Constant: '<S609>/Constant10'
   *  Constant: '<S609>/Constant11'
   *  Constant: '<S609>/Constant12'
   *  Constant: '<S609>/Constant13'
   *  Constant: '<S609>/Constant14'
   *  Constant: '<S609>/Constant15'
   *  Constant: '<S609>/Constant2'
   *  Constant: '<S609>/Constant3'
   *  Constant: '<S609>/Constant4'
   *  Constant: '<S609>/Constant5'
   *  Constant: '<S609>/Constant6'
   *  Constant: '<S609>/Constant7'
   *  Constant: '<S609>/Constant8'
   *  Constant: '<S609>/Constant9'
   *  Gain: '<S609>/Gain1'
   *  Gain: '<S609>/Gain2'
   *  Gain: '<S609>/Gain3'
   *  Product: '<S609>/Divide1'
   *  Product: '<S609>/Divide2'
   *  Product: '<S609>/Divide3'
   *  Product: '<S609>/Divide4'
   *  Product: '<S609>/Divide5'
   *  Product: '<S609>/Divide6'
   *  Product: '<S609>/Divide7'
   *  Sum: '<S609>/Add1'
   *  Sum: '<S609>/Add2'
   *  Sum: '<S609>/Add3'
   *  Sum: '<S609>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S600>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa * locvar_Divide4_c1v +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_j *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_li - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
                   (locvar_ManualSwitch_li - ANN_EKF_NMPC_2_P.Utrim) *
                   ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain2_Gain_ai *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_ca) + (locvar_Divide4_c1v -
    ANN_EKF_NMPC_2_P.alphatrim) * ANN_EKF_NMPC_2_P.CD1 *
    ANN_EKF_NMPC_2_P.Gain3_Gain_po;

  /* ManualSwitch: '<S608>/Manual Switch' incorporates:
   *  Constant: '<S608>/AR'
   *  Constant: '<S608>/Constant15'
   *  Constant: '<S608>/Constant16'
   *  Constant: '<S608>/Constant17'
   *  Constant: '<S608>/Constant18'
   *  Constant: '<S608>/e'
   *  Math: '<S608>/Math Function'
   *  Product: '<S608>/Divide8'
   *  Product: '<S608>/Divide9'
   *  Sum: '<S608>/Add5'
   *  Sum: '<S608>/Add6'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_cq == 1) {
    locvar_ManualSwitch_il = ANN_EKF_NMPC_2_P.CDa * locvar_Divide4_c1v +
      ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_il = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_ei / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_n +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S608>/Manual Switch' */

  /* Sum: '<S608>/Add' incorporates:
   *  Constant: '<S608>/Constant1'
   *  Constant: '<S608>/Constant10'
   *  Constant: '<S608>/Constant11'
   *  Constant: '<S608>/Constant12'
   *  Constant: '<S608>/Constant13'
   *  Constant: '<S608>/Constant14'
   *  Constant: '<S608>/Constant2'
   *  Constant: '<S608>/Constant3'
   *  Constant: '<S608>/Constant4'
   *  Constant: '<S608>/Constant6'
   *  Constant: '<S608>/Constant7'
   *  Constant: '<S608>/Constant8'
   *  Constant: '<S608>/Constant9'
   *  Gain: '<S608>/Gain1'
   *  Gain: '<S608>/Gain2'
   *  Gain: '<S608>/Gain3'
   *  Product: '<S608>/Divide1'
   *  Product: '<S608>/Divide2'
   *  Product: '<S608>/Divide3'
   *  Product: '<S608>/Divide5'
   *  Product: '<S608>/Divide6'
   *  Product: '<S608>/Divide7'
   *  Sum: '<S608>/Add1'
   *  Sum: '<S608>/Add2'
   *  Sum: '<S608>/Add3'
   *  Sum: '<S608>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S600>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_il) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_j *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_li - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_li -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_on *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_pl) - (locvar_Divide4_c1v -
    ANN_EKF_NMPC_2_P.alphatrim) * ANN_EKF_NMPC_2_P.CL1 *
    ANN_EKF_NMPC_2_P.Gain3_Gain_jo;

  /* ManualSwitch: '<S594>/Manual Switch' incorporates:
   *  Constant: '<S594>/Constant1'
   *  Constant: '<S602>/Constant'
   *  Constant: '<S620>/Constant'
   *  Constant: '<S620>/Constant1'
   *  Constant: '<S620>/Constant2'
   *  Math: '<S620>/Math Function'
   *  Product: '<S594>/Divide'
   *  Product: '<S594>/Divide5'
   *  Product: '<S617>/Divide3'
   *  Product: '<S617>/Divide5'
   *  Product: '<S620>/Divide1'
   *  Product: '<S620>/Divide2'
   *  Sum: '<S594>/Add'
   *  Sum: '<S617>/Add'
   *  Sum: '<S620>/Add'
   *  Trigonometry: '<S617>/Trigonometric Function'
   *  Trigonometry: '<S617>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_fa == 1) {
    /* Gain: '<S620>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_g *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_il = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(locvar_Divide4_c1v) * locvar_Add_kq -
      locvar_Add2_db * cos(locvar_Divide4_c1v)) * (locvar_Divide4_ipd *
      ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight / ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_il = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S594>/Manual Switch' */

  /* Sum: '<S594>/Add1' incorporates:
   *  Constant: '<S594>/Constant'
   *  Product: '<S594>/Divide2'
   *  Product: '<S594>/Divide3'
   *  Product: '<S594>/Divide4'
   *  Trigonometry: '<S594>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_c = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_ex - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_p0l) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_il;

  /* Product: '<S596>/Divide3' */
  locvar_Divide3_mnp = locvar_ManualSwitch_li * locvar_ManualSwitch_c;

  /* ManualSwitch: '<S597>/Manual Switch' incorporates:
   *  Constant: '<S597>/Constant1'
   *  Constant: '<S602>/Constant'
   *  Constant: '<S610>/Constant'
   *  Constant: '<S610>/Constant1'
   *  Constant: '<S610>/Constant10'
   *  Constant: '<S610>/Constant11'
   *  Constant: '<S610>/Constant12'
   *  Constant: '<S610>/Constant2'
   *  Constant: '<S610>/Constant3'
   *  Constant: '<S610>/Constant4'
   *  Constant: '<S610>/Constant5'
   *  Constant: '<S610>/Constant6'
   *  Constant: '<S610>/Constant8'
   *  Product: '<S597>/Divide'
   *  Product: '<S597>/Divide5'
   *  Product: '<S610>/Divide1'
   *  Product: '<S610>/Divide3'
   *  Product: '<S610>/Divide4'
   *  Product: '<S610>/Divide5'
   *  Product: '<S610>/Divide6'
   *  Sum: '<S610>/Add'
   *  Sum: '<S610>/Add1'
   *  Sum: '<S610>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_k1 == 1) {
    locvar_ManualSwitch_oa = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_ipd * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_oa = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S597>/Manual Switch' */

  /* Sum: '<S597>/Add1' incorporates:
   *  Constant: '<S597>/Constant'
   *  Product: '<S597>/Divide2'
   *  Product: '<S597>/Divide3'
   *  Product: '<S597>/Divide4'
   *  Trigonometry: '<S597>/Trigonometric Function'
   *  Trigonometry: '<S597>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_k5 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_p0l - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_li) + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_oa;

  /* Product: '<S596>/Divide4' */
  locvar_Divide4_jr4 = locvar_ManualSwitch_ex * locvar_ManualSwitch_k5;

  /* ManualSwitch: '<S599>/Manual Switch' incorporates:
   *  Constant: '<S599>/Constant1'
   *  Constant: '<S602>/Constant'
   *  Product: '<S599>/Divide'
   *  Product: '<S599>/Divide5'
   *  Product: '<S619>/Divide1'
   *  Product: '<S619>/Divide6'
   *  Sum: '<S619>/Add2'
   *  Trigonometry: '<S619>/Trigonometric Function4'
   *  Trigonometry: '<S619>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ms == 1) {
    locvar_ManualSwitch_gl = ((0.0 - locvar_Add2_db * sin(locvar_Divide4_c1v)) -
      cos(locvar_Divide4_c1v) * locvar_Add_kq) * (locvar_Divide4_ipd *
      ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight / ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_gl = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S599>/Manual Switch' */

  /* Sum: '<S599>/Add1' incorporates:
   *  Constant: '<S599>/Constant'
   *  Product: '<S599>/Divide2'
   *  Product: '<S599>/Divide3'
   *  Product: '<S599>/Divide4'
   *  Trigonometry: '<S599>/Trigonometric Function'
   *  Trigonometry: '<S599>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_li - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_ex) + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_gl;

  /* Product: '<S596>/Divide5' */
  locvar_Divide5_nv = locvar_ManualSwitch_p0l * locvar_ManualSwitch_ga;

  /* Product: '<S600>/Divide' incorporates:
   *  Math: '<S600>/Math Function'
   *  Math: '<S600>/Math Function1'
   *  Product: '<S600>/Divide3'
   *  Product: '<S600>/Divide4'
   *  Sum: '<S600>/Add'
   *  Sum: '<S600>/Add1'
   */
  locvar_Divide_ml = (locvar_ManualSwitch_li * locvar_ManualSwitch_ga -
                      locvar_ManualSwitch_p0l * locvar_ManualSwitch_c) /
    (locvar_ManualSwitch_li * locvar_ManualSwitch_li + locvar_ManualSwitch_p0l *
     locvar_ManualSwitch_p0l);

  /* Product: '<S601>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide3_at = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    locvar_ManualSwitch_k5;

  /* Product: '<S601>/Divide4' incorporates:
   *  Product: '<S601>/Divide1'
   *  Product: '<S601>/Divide2'
   *  Product: '<S601>/Divide5'
   *  Product: '<S601>/Divide6'
   *  Sum: '<S601>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_h3 = ((locvar_ManualSwitch_li * locvar_ManualSwitch_c +
                        locvar_ManualSwitch_ex * locvar_ManualSwitch_k5) +
                       locvar_ManualSwitch_p0l * locvar_ManualSwitch_ga) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_ex;

  /* Math: '<S601>/Math Function' */
  locvar_MathFunction_hi4 = locvar_ManualSwitch_li * locvar_ManualSwitch_li;

  /* Math: '<S601>/Math Function1' */
  locvar_MathFunction1_ed = locvar_ManualSwitch_p0l * locvar_ManualSwitch_p0l;

  /* Sum: '<S630>/Add' incorporates:
   *  Constant: '<S630>/Ixx1'
   *  Constant: '<S630>/Ixz1'
   *  Constant: '<S630>/Izz1'
   *  Math: '<S630>/Math Function'
   *  Product: '<S630>/Divide1'
   */
  locvar_ManualSwitch_k5 = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S622>/Divide4' incorporates:
   *  Constant: '<S622>/Ixx'
   *  Constant: '<S622>/Ixz'
   *  Constant: '<S622>/Iyy'
   *  Constant: '<S622>/Izz'
   *  Product: '<S622>/Divide3'
   *  Sum: '<S622>/Add'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_k5;

  /* Sum: '<S589>/Add1' incorporates:
   *  Constant: '<S621>/Ixz'
   *  Constant: '<S621>/Iyy'
   *  Constant: '<S621>/Izz'
   *  Math: '<S621>/Math Function'
   *  Product: '<S589>/Divide2'
   *  Product: '<S589>/Divide3'
   *  Product: '<S621>/Divide3'
   *  Product: '<S621>/Divide4'
   *  Sum: '<S621>/Add'
   *  Sum: '<S621>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_co = ((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_k5 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_ManualSwitch_ga *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* Sum: '<S612>/Add' incorporates:
   *  Constant: '<S612>/Constant10'
   *  Constant: '<S612>/Constant11'
   *  Constant: '<S612>/Constant12'
   *  Constant: '<S612>/Constant13'
   *  Constant: '<S612>/Constant14'
   *  Constant: '<S612>/Constant15'
   *  Constant: '<S612>/Constant5'
   *  Constant: '<S612>/Constant6'
   *  Constant: '<S612>/Constant7'
   *  Constant: '<S612>/Constant8'
   *  Constant: '<S612>/Constant9'
   *  Product: '<S612>/Divide3'
   *  Product: '<S612>/Divide4'
   *  Product: '<S612>/Divide5'
   *  Product: '<S612>/Divide6'
   *  Product: '<S612>/Divide7'
   *  Sum: '<S612>/Add1'
   *  Sum: '<S612>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S616>/Add' incorporates:
   *  Constant: '<S616>/Constant'
   *  Constant: '<S616>/Constant10'
   *  Constant: '<S616>/Constant11'
   *  Constant: '<S616>/Constant12'
   *  Constant: '<S616>/Constant13'
   *  Constant: '<S616>/Constant14'
   *  Constant: '<S616>/Constant15'
   *  Constant: '<S616>/Constant5'
   *  Constant: '<S616>/Constant6'
   *  Constant: '<S616>/Constant8'
   *  Constant: '<S616>/Constant9'
   *  Product: '<S616>/Divide3'
   *  Product: '<S616>/Divide4'
   *  Product: '<S616>/Divide5'
   *  Product: '<S616>/Divide6'
   *  Product: '<S616>/Divide7'
   *  Sum: '<S616>/Add1'
   *  Sum: '<S616>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_p = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S611>/Add' incorporates:
   *  Product: '<S611>/Divide3'
   *  Product: '<S611>/Divide5'
   *  Trigonometry: '<S611>/Trigonometric Function'
   *  Trigonometry: '<S611>/Trigonometric Function3'
   */
  locvar_Divide4_dh = locvar_Add2_db * cos(locvar_Divide4_c1v) - sin
    (locvar_Divide4_c1v) * locvar_ManualSwitch_p;

  /* Product: '<S624>/Divide4' incorporates:
   *  Constant: '<S624>/Ixz'
   */
  locvar_ManualSwitch_bs = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_k5;

  /* Sum: '<S615>/Add2' incorporates:
   *  Product: '<S615>/Divide1'
   *  Product: '<S615>/Divide6'
   *  Trigonometry: '<S615>/Trigonometric Function4'
   *  Trigonometry: '<S615>/Trigonometric Function5'
   */
  locvar_ManualSwitch_p = locvar_Add2_db * sin(locvar_Divide4_c1v) + cos
    (locvar_Divide4_c1v) * locvar_ManualSwitch_p;

  /* Sum: '<S589>/Add' incorporates:
   *  Constant: '<S623>/Izz'
   *  Product: '<S589>/Divide'
   *  Product: '<S589>/Divide4'
   *  Product: '<S623>/Divide4'
   */
  locvar_Add_cn = ANN_EKF_NMPC_2_P.IzzB / locvar_ManualSwitch_k5 *
    locvar_Divide4_dh + locvar_ManualSwitch_bs * locvar_ManualSwitch_p;

  /* Product: '<S591>/Divide' incorporates:
   *  Constant: '<S614>/Constant'
   *  Constant: '<S614>/Constant1'
   *  Constant: '<S614>/Constant11'
   *  Constant: '<S614>/Constant12'
   *  Constant: '<S614>/Constant13'
   *  Constant: '<S614>/Constant14'
   *  Constant: '<S614>/Constant2'
   *  Constant: '<S614>/Constant3'
   *  Constant: '<S614>/Constant4'
   *  Constant: '<S614>/Constant5'
   *  Constant: '<S614>/Constant6'
   *  Constant: '<S614>/Constant7'
   *  Constant: '<S614>/Constant8'
   *  Constant: '<S614>/Constant9'
   *  Constant: '<S627>/Ixz'
   *  Constant: '<S627>/Iyy'
   *  Gain: '<S614>/Gain1'
   *  Gain: '<S614>/Gain2'
   *  Product: '<S614>/Divide1'
   *  Product: '<S614>/Divide2'
   *  Product: '<S614>/Divide3'
   *  Product: '<S614>/Divide4'
   *  Product: '<S614>/Divide5'
   *  Product: '<S614>/Divide6'
   *  Product: '<S627>/Divide4'
   *  Sum: '<S614>/Add'
   *  Sum: '<S614>/Add1'
   *  Sum: '<S614>/Add2'
   *  Sum: '<S614>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S600>/Unit Delay'
   */
  locvar_Divide_jg = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma * locvar_Divide4_c1v +
    ANN_EKF_NMPC_2_P.Cm0)) + ANN_EKF_NMPC_2_P.Cmadot *
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_j * (ANN_EKF_NMPC_2_P.Cbar / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim) + ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
                        (locvar_ManualSwitch_li - ANN_EKF_NMPC_2_P.Utrim)) +
                       ANN_EKF_NMPC_2_P.Cmde *
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                      ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_li -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                      ANN_EKF_NMPC_2_P.Gain2_Gain_l1 *
                      ANN_EKF_NMPC_2_P.Gain1_Gain_hj) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_mu / ANN_EKF_NMPC_2_P.IyyB);

  /* Sum: '<S592>/Add1' incorporates:
   *  Constant: '<S628>/Ixx'
   *  Constant: '<S628>/Ixx1'
   *  Constant: '<S628>/Ixz'
   *  Constant: '<S628>/Iyy'
   *  Math: '<S628>/Math Function'
   *  Product: '<S592>/Divide2'
   *  Product: '<S592>/Divide3'
   *  Product: '<S628>/Divide3'
   *  Product: '<S628>/Divide4'
   *  Sum: '<S628>/Add'
   *  Sum: '<S628>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_dy = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_k5 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_ManualSwitch_ga *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S592>/Add' incorporates:
   *  Constant: '<S629>/Ixx'
   *  Product: '<S592>/Divide'
   *  Product: '<S592>/Divide4'
   *  Product: '<S629>/Divide4'
   */
  locvar_Add_nl = ANN_EKF_NMPC_2_P.IxxB / locvar_ManualSwitch_k5 *
    locvar_ManualSwitch_p + locvar_ManualSwitch_bs * locvar_Divide4_dh;

  /* Sum: '<S165>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add_ow = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6];

  /* Product: '<S638>/Divide2' incorporates:
   *  Trigonometry: '<S638>/Trigonometric Function'
   *  Trigonometry: '<S638>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_lz = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos(locvar_Add_ow);

  /* Product: '<S640>/Divide2' incorporates:
   *  Trigonometry: '<S640>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_h2 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (locvar_Add_ow);

  /* Product: '<S643>/Divide2' incorporates:
   *  Trigonometry: '<S643>/Trigonometric Function'
   *  Trigonometry: '<S643>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_d = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos(locvar_Add_ow);

  /* Product: '<S635>/Divide4' incorporates:
   *  Constant: '<S635>/Constant'
   *  Constant: '<S635>/Constant1'
   *  Math: '<S635>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_m3z = ANN_EKF_NMPC_2_P.Constant_Value_o4 *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S654>/Add' incorporates:
   *  Constant: '<S654>/Constant'
   *  Constant: '<S654>/Constant1'
   *  Constant: '<S654>/Constant10'
   *  Constant: '<S654>/Constant11'
   *  Constant: '<S654>/Constant12'
   *  Constant: '<S654>/Constant13'
   *  Constant: '<S654>/Constant14'
   *  Constant: '<S654>/Constant15'
   *  Constant: '<S654>/Constant2'
   *  Constant: '<S654>/Constant3'
   *  Constant: '<S654>/Constant4'
   *  Constant: '<S654>/Constant5'
   *  Constant: '<S654>/Constant6'
   *  Constant: '<S654>/Constant7'
   *  Constant: '<S654>/Constant8'
   *  Constant: '<S654>/Constant9'
   *  Gain: '<S654>/Gain1'
   *  Gain: '<S654>/Gain2'
   *  Gain: '<S654>/Gain3'
   *  Product: '<S654>/Divide1'
   *  Product: '<S654>/Divide2'
   *  Product: '<S654>/Divide3'
   *  Product: '<S654>/Divide4'
   *  Product: '<S654>/Divide5'
   *  Product: '<S654>/Divide6'
   *  Product: '<S654>/Divide7'
   *  Sum: '<S654>/Add1'
   *  Sum: '<S654>/Add2'
   *  Sum: '<S654>/Add3'
   *  Sum: '<S654>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S645>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_b *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_lz - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
                   (locvar_ManualSwitch_lz - ANN_EKF_NMPC_2_P.Utrim) *
                   ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain2_Gain_gg *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_o) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_pl;

  /* ManualSwitch: '<S653>/Manual Switch' incorporates:
   *  Constant: '<S653>/AR'
   *  Constant: '<S653>/Constant15'
   *  Constant: '<S653>/Constant16'
   *  Constant: '<S653>/Constant17'
   *  Constant: '<S653>/Constant18'
   *  Constant: '<S653>/e'
   *  Math: '<S653>/Math Function'
   *  Product: '<S653>/Divide8'
   *  Product: '<S653>/Divide9'
   *  Sum: '<S653>/Add5'
   *  Sum: '<S653>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ci == 1) {
    locvar_ManualSwitch_li = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_li = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_h / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_e +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S653>/Manual Switch' */

  /* Sum: '<S653>/Add' incorporates:
   *  Constant: '<S653>/Constant1'
   *  Constant: '<S653>/Constant10'
   *  Constant: '<S653>/Constant11'
   *  Constant: '<S653>/Constant12'
   *  Constant: '<S653>/Constant13'
   *  Constant: '<S653>/Constant14'
   *  Constant: '<S653>/Constant2'
   *  Constant: '<S653>/Constant3'
   *  Constant: '<S653>/Constant4'
   *  Constant: '<S653>/Constant6'
   *  Constant: '<S653>/Constant7'
   *  Constant: '<S653>/Constant8'
   *  Constant: '<S653>/Constant9'
   *  Gain: '<S653>/Gain1'
   *  Gain: '<S653>/Gain2'
   *  Gain: '<S653>/Gain3'
   *  Product: '<S653>/Divide1'
   *  Product: '<S653>/Divide2'
   *  Product: '<S653>/Divide3'
   *  Product: '<S653>/Divide5'
   *  Product: '<S653>/Divide6'
   *  Product: '<S653>/Divide7'
   *  Sum: '<S653>/Add1'
   *  Sum: '<S653>/Add2'
   *  Sum: '<S653>/Add3'
   *  Sum: '<S653>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S645>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_li) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_b *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_lz - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_lz -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_gk *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_hs) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_mq;

  /* ManualSwitch: '<S639>/Manual Switch' incorporates:
   *  Constant: '<S639>/Constant1'
   *  Constant: '<S647>/Constant'
   *  Constant: '<S665>/Constant'
   *  Constant: '<S665>/Constant1'
   *  Constant: '<S665>/Constant2'
   *  Math: '<S665>/Math Function'
   *  Product: '<S639>/Divide'
   *  Product: '<S639>/Divide5'
   *  Product: '<S662>/Divide3'
   *  Product: '<S662>/Divide5'
   *  Product: '<S665>/Divide1'
   *  Product: '<S665>/Divide2'
   *  Sum: '<S639>/Add'
   *  Sum: '<S662>/Add'
   *  Sum: '<S665>/Add'
   *  Trigonometry: '<S662>/Trigonometric Function'
   *  Trigonometry: '<S662>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_br == 1) {
    /* Gain: '<S665>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_ke *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_li = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_m3z * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_li = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S639>/Manual Switch' */

  /* Sum: '<S639>/Add1' incorporates:
   *  Constant: '<S639>/Constant'
   *  Product: '<S639>/Divide2'
   *  Product: '<S639>/Divide3'
   *  Product: '<S639>/Divide4'
   *  Trigonometry: '<S639>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ex = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_h2 - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_d) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_li;

  /* Product: '<S641>/Divide3' */
  locvar_Divide3_ef = locvar_ManualSwitch_lz * locvar_ManualSwitch_ex;

  /* ManualSwitch: '<S642>/Manual Switch' incorporates:
   *  Constant: '<S642>/Constant1'
   *  Constant: '<S647>/Constant'
   *  Constant: '<S655>/Constant'
   *  Constant: '<S655>/Constant1'
   *  Constant: '<S655>/Constant10'
   *  Constant: '<S655>/Constant11'
   *  Constant: '<S655>/Constant12'
   *  Constant: '<S655>/Constant2'
   *  Constant: '<S655>/Constant3'
   *  Constant: '<S655>/Constant4'
   *  Constant: '<S655>/Constant5'
   *  Constant: '<S655>/Constant6'
   *  Constant: '<S655>/Constant8'
   *  Product: '<S642>/Divide'
   *  Product: '<S642>/Divide5'
   *  Product: '<S655>/Divide1'
   *  Product: '<S655>/Divide3'
   *  Product: '<S655>/Divide4'
   *  Product: '<S655>/Divide5'
   *  Product: '<S655>/Divide6'
   *  Sum: '<S655>/Add'
   *  Sum: '<S655>/Add1'
   *  Sum: '<S655>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_nu == 1) {
    locvar_ManualSwitch_p0l = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb * locvar_Add_ow) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_m3z * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_p0l = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S642>/Manual Switch' */

  /* Sum: '<S642>/Add1' incorporates:
   *  Constant: '<S642>/Constant'
   *  Product: '<S642>/Divide2'
   *  Product: '<S642>/Divide3'
   *  Product: '<S642>/Divide4'
   *  Trigonometry: '<S642>/Trigonometric Function'
   *  Trigonometry: '<S642>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_c = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_d - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_lz) + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_p0l;

  /* Product: '<S641>/Divide4' */
  locvar_Divide4_j0a = locvar_ManualSwitch_h2 * locvar_ManualSwitch_c;

  /* ManualSwitch: '<S644>/Manual Switch' incorporates:
   *  Constant: '<S644>/Constant1'
   *  Constant: '<S647>/Constant'
   *  Product: '<S644>/Divide'
   *  Product: '<S644>/Divide5'
   *  Product: '<S664>/Divide1'
   *  Product: '<S664>/Divide6'
   *  Sum: '<S664>/Add2'
   *  Trigonometry: '<S664>/Trigonometric Function4'
   *  Trigonometry: '<S664>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_nq == 1) {
    locvar_ManualSwitch_k5 = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_m3z * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_k5 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S644>/Manual Switch' */

  /* Sum: '<S644>/Add1' incorporates:
   *  Constant: '<S644>/Constant'
   *  Product: '<S644>/Divide2'
   *  Product: '<S644>/Divide3'
   *  Product: '<S644>/Divide4'
   *  Trigonometry: '<S644>/Trigonometric Function'
   *  Trigonometry: '<S644>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_lz - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_h2) + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_k5;

  /* Product: '<S641>/Divide5' */
  locvar_Divide5_dki = locvar_ManualSwitch_d * locvar_ManualSwitch_ga;

  /* Product: '<S645>/Divide' incorporates:
   *  Math: '<S645>/Math Function'
   *  Math: '<S645>/Math Function1'
   *  Product: '<S645>/Divide3'
   *  Product: '<S645>/Divide4'
   *  Sum: '<S645>/Add'
   *  Sum: '<S645>/Add1'
   */
  locvar_Divide_hvn = (locvar_ManualSwitch_lz * locvar_ManualSwitch_ga -
                       locvar_ManualSwitch_d * locvar_ManualSwitch_ex) /
    (locvar_ManualSwitch_lz * locvar_ManualSwitch_lz + locvar_ManualSwitch_d *
     locvar_ManualSwitch_d);

  /* Product: '<S646>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide3_poh = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    locvar_ManualSwitch_c;

  /* Product: '<S646>/Divide4' incorporates:
   *  Product: '<S646>/Divide1'
   *  Product: '<S646>/Divide2'
   *  Product: '<S646>/Divide5'
   *  Product: '<S646>/Divide6'
   *  Sum: '<S646>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_hl4 = ((locvar_ManualSwitch_lz * locvar_ManualSwitch_ex +
    locvar_ManualSwitch_h2 * locvar_ManualSwitch_c) + locvar_ManualSwitch_d *
                        locvar_ManualSwitch_ga) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_h2;

  /* Math: '<S646>/Math Function' */
  locvar_MathFunction_ld = locvar_ManualSwitch_lz * locvar_ManualSwitch_lz;

  /* Math: '<S646>/Math Function1' */
  locvar_MathFunction1_j = locvar_ManualSwitch_d * locvar_ManualSwitch_d;

  /* Sum: '<S675>/Add' incorporates:
   *  Constant: '<S675>/Ixx1'
   *  Constant: '<S675>/Ixz1'
   *  Constant: '<S675>/Izz1'
   *  Math: '<S675>/Math Function'
   *  Product: '<S675>/Divide1'
   */
  locvar_ManualSwitch_c = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S667>/Divide4' incorporates:
   *  Constant: '<S667>/Ixx'
   *  Constant: '<S667>/Ixz'
   *  Constant: '<S667>/Iyy'
   *  Constant: '<S667>/Izz'
   *  Product: '<S667>/Divide3'
   *  Sum: '<S667>/Add'
   */
  locvar_ManualSwitch_ga = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_c;

  /* Sum: '<S634>/Add1' incorporates:
   *  Constant: '<S666>/Ixz'
   *  Constant: '<S666>/Iyy'
   *  Constant: '<S666>/Izz'
   *  Math: '<S666>/Math Function'
   *  Product: '<S634>/Divide2'
   *  Product: '<S634>/Divide3'
   *  Product: '<S666>/Divide3'
   *  Product: '<S666>/Divide4'
   *  Sum: '<S666>/Add'
   *  Sum: '<S666>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_ot = ((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_c *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_ManualSwitch_ga *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* Sum: '<S657>/Add' incorporates:
   *  Constant: '<S657>/Constant10'
   *  Constant: '<S657>/Constant11'
   *  Constant: '<S657>/Constant12'
   *  Constant: '<S657>/Constant13'
   *  Constant: '<S657>/Constant14'
   *  Constant: '<S657>/Constant15'
   *  Constant: '<S657>/Constant5'
   *  Constant: '<S657>/Constant6'
   *  Constant: '<S657>/Constant7'
   *  Constant: '<S657>/Constant8'
   *  Constant: '<S657>/Constant9'
   *  Product: '<S657>/Divide3'
   *  Product: '<S657>/Divide4'
   *  Product: '<S657>/Divide5'
   *  Product: '<S657>/Divide6'
   *  Product: '<S657>/Divide7'
   *  Sum: '<S657>/Add1'
   *  Sum: '<S657>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb * locvar_Add_ow) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S661>/Add' incorporates:
   *  Constant: '<S661>/Constant'
   *  Constant: '<S661>/Constant10'
   *  Constant: '<S661>/Constant11'
   *  Constant: '<S661>/Constant12'
   *  Constant: '<S661>/Constant13'
   *  Constant: '<S661>/Constant14'
   *  Constant: '<S661>/Constant15'
   *  Constant: '<S661>/Constant5'
   *  Constant: '<S661>/Constant6'
   *  Constant: '<S661>/Constant8'
   *  Constant: '<S661>/Constant9'
   *  Product: '<S661>/Divide3'
   *  Product: '<S661>/Divide4'
   *  Product: '<S661>/Divide5'
   *  Product: '<S661>/Divide6'
   *  Product: '<S661>/Divide7'
   *  Sum: '<S661>/Add1'
   *  Sum: '<S661>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_c0 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb * locvar_Add_ow) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S656>/Add' incorporates:
   *  Product: '<S656>/Divide3'
   *  Product: '<S656>/Divide5'
   *  Trigonometry: '<S656>/Trigonometric Function'
   *  Trigonometry: '<S656>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_pp = locvar_Add2_db * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_c0;

  /* Product: '<S669>/Divide4' incorporates:
   *  Constant: '<S669>/Ixz'
   */
  locvar_Azb_h = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_c;

  /* Sum: '<S660>/Add2' incorporates:
   *  Product: '<S660>/Divide1'
   *  Product: '<S660>/Divide6'
   *  Trigonometry: '<S660>/Trigonometric Function4'
   *  Trigonometry: '<S660>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_c0 = locvar_Add2_db * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_c0;

  /* Sum: '<S634>/Add' incorporates:
   *  Constant: '<S668>/Izz'
   *  Product: '<S634>/Divide'
   *  Product: '<S634>/Divide4'
   *  Product: '<S668>/Divide4'
   */
  locvar_Add_jbj = ANN_EKF_NMPC_2_P.IzzB / locvar_ManualSwitch_c *
    locvar_ManualSwitch_pp + locvar_Azb_h * locvar_ManualSwitch_c0;

  /* Product: '<S636>/Divide' incorporates:
   *  Constant: '<S659>/Constant'
   *  Constant: '<S659>/Constant1'
   *  Constant: '<S659>/Constant11'
   *  Constant: '<S659>/Constant12'
   *  Constant: '<S659>/Constant13'
   *  Constant: '<S659>/Constant14'
   *  Constant: '<S659>/Constant2'
   *  Constant: '<S659>/Constant3'
   *  Constant: '<S659>/Constant4'
   *  Constant: '<S659>/Constant5'
   *  Constant: '<S659>/Constant6'
   *  Constant: '<S659>/Constant7'
   *  Constant: '<S659>/Constant8'
   *  Constant: '<S659>/Constant9'
   *  Constant: '<S672>/Ixz'
   *  Constant: '<S672>/Iyy'
   *  Gain: '<S659>/Gain1'
   *  Gain: '<S659>/Gain2'
   *  Product: '<S659>/Divide1'
   *  Product: '<S659>/Divide2'
   *  Product: '<S659>/Divide3'
   *  Product: '<S659>/Divide4'
   *  Product: '<S659>/Divide5'
   *  Product: '<S659>/Divide6'
   *  Product: '<S672>/Divide4'
   *  Sum: '<S659>/Add'
   *  Sum: '<S659>/Add1'
   *  Sum: '<S659>/Add2'
   *  Sum: '<S659>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S645>/Unit Delay'
   */
  locvar_Divide_b = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
                        ANN_EKF_NMPC_2_P.Cmadot *
                        ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_b *
                        (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
                       + ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
                       (locvar_ManualSwitch_lz - ANN_EKF_NMPC_2_P.Utrim)) +
                      ANN_EKF_NMPC_2_P.Cmde *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                     ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_lz -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                     ANN_EKF_NMPC_2_P.Gain2_Gain_oh *
                     ANN_EKF_NMPC_2_P.Gain1_Gain_ky) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_lt / ANN_EKF_NMPC_2_P.IyyB);

  /* Sum: '<S637>/Add1' incorporates:
   *  Constant: '<S673>/Ixx'
   *  Constant: '<S673>/Ixx1'
   *  Constant: '<S673>/Ixz'
   *  Constant: '<S673>/Iyy'
   *  Math: '<S673>/Math Function'
   *  Product: '<S637>/Divide2'
   *  Product: '<S637>/Divide3'
   *  Product: '<S673>/Divide3'
   *  Product: '<S673>/Divide4'
   *  Sum: '<S673>/Add'
   *  Sum: '<S673>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_i0 = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_c *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_ManualSwitch_ga *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S637>/Add' incorporates:
   *  Constant: '<S674>/Ixx'
   *  Product: '<S637>/Divide'
   *  Product: '<S637>/Divide4'
   *  Product: '<S674>/Divide4'
   */
  locvar_Add_oj = ANN_EKF_NMPC_2_P.IxxB / locvar_ManualSwitch_c *
    locvar_ManualSwitch_c0 + locvar_Azb_h * locvar_ManualSwitch_pp;

  /* Product: '<S683>/Divide2' incorporates:
   *  Trigonometry: '<S683>/Trigonometric Function'
   *  Trigonometry: '<S683>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_dh = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S685>/Divide2' incorporates:
   *  Trigonometry: '<S685>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_p = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S688>/Divide2' incorporates:
   *  Trigonometry: '<S688>/Trigonometric Function'
   *  Trigonometry: '<S688>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_m = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S680>/Divide4' incorporates:
   *  Constant: '<S680>/Constant'
   *  Constant: '<S680>/Constant1'
   *  Math: '<S680>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_hvl = ANN_EKF_NMPC_2_P.Constant_Value_c *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S699>/Add' incorporates:
   *  Constant: '<S699>/Constant'
   *  Constant: '<S699>/Constant1'
   *  Constant: '<S699>/Constant10'
   *  Constant: '<S699>/Constant11'
   *  Constant: '<S699>/Constant12'
   *  Constant: '<S699>/Constant13'
   *  Constant: '<S699>/Constant14'
   *  Constant: '<S699>/Constant15'
   *  Constant: '<S699>/Constant2'
   *  Constant: '<S699>/Constant3'
   *  Constant: '<S699>/Constant4'
   *  Constant: '<S699>/Constant5'
   *  Constant: '<S699>/Constant6'
   *  Constant: '<S699>/Constant7'
   *  Constant: '<S699>/Constant8'
   *  Constant: '<S699>/Constant9'
   *  Gain: '<S699>/Gain1'
   *  Gain: '<S699>/Gain2'
   *  Gain: '<S699>/Gain3'
   *  Product: '<S699>/Divide1'
   *  Product: '<S699>/Divide2'
   *  Product: '<S699>/Divide3'
   *  Product: '<S699>/Divide4'
   *  Product: '<S699>/Divide5'
   *  Product: '<S699>/Divide6'
   *  Product: '<S699>/Divide7'
   *  Sum: '<S699>/Add1'
   *  Sum: '<S699>/Add2'
   *  Sum: '<S699>/Add3'
   *  Sum: '<S699>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S690>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_c *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_Divide4_dh - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim * (locvar_Divide4_dh -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                   ANN_EKF_NMPC_2_P.Gain2_Gain_e * ANN_EKF_NMPC_2_P.Gain1_Gain_i)
    + (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_ovm;

  /* ManualSwitch: '<S698>/Manual Switch' incorporates:
   *  Constant: '<S698>/AR'
   *  Constant: '<S698>/Constant15'
   *  Constant: '<S698>/Constant16'
   *  Constant: '<S698>/Constant17'
   *  Constant: '<S698>/Constant18'
   *  Constant: '<S698>/e'
   *  Math: '<S698>/Math Function'
   *  Product: '<S698>/Divide8'
   *  Product: '<S698>/Divide9'
   *  Sum: '<S698>/Add5'
   *  Sum: '<S698>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_db == 1) {
    locvar_ManualSwitch_lz = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_lz = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_b / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_ms +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S698>/Manual Switch' */

  /* Sum: '<S698>/Add' incorporates:
   *  Constant: '<S698>/Constant1'
   *  Constant: '<S698>/Constant10'
   *  Constant: '<S698>/Constant11'
   *  Constant: '<S698>/Constant12'
   *  Constant: '<S698>/Constant13'
   *  Constant: '<S698>/Constant14'
   *  Constant: '<S698>/Constant2'
   *  Constant: '<S698>/Constant3'
   *  Constant: '<S698>/Constant4'
   *  Constant: '<S698>/Constant6'
   *  Constant: '<S698>/Constant7'
   *  Constant: '<S698>/Constant8'
   *  Constant: '<S698>/Constant9'
   *  Gain: '<S698>/Gain1'
   *  Gain: '<S698>/Gain2'
   *  Gain: '<S698>/Gain3'
   *  Product: '<S698>/Divide1'
   *  Product: '<S698>/Divide2'
   *  Product: '<S698>/Divide3'
   *  Product: '<S698>/Divide5'
   *  Product: '<S698>/Divide6'
   *  Product: '<S698>/Divide7'
   *  Sum: '<S698>/Add1'
   *  Sum: '<S698>/Add2'
   *  Sum: '<S698>/Add3'
   *  Sum: '<S698>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S690>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_lz) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_c *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_Divide4_dh - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_Divide4_dh -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_fm *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_ah) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_md;

  /* ManualSwitch: '<S684>/Manual Switch' incorporates:
   *  Constant: '<S684>/Constant1'
   *  Constant: '<S692>/Constant'
   *  Constant: '<S710>/Constant'
   *  Constant: '<S710>/Constant1'
   *  Constant: '<S710>/Constant2'
   *  Math: '<S710>/Math Function'
   *  Product: '<S684>/Divide'
   *  Product: '<S684>/Divide5'
   *  Product: '<S707>/Divide3'
   *  Product: '<S707>/Divide5'
   *  Product: '<S710>/Divide1'
   *  Product: '<S710>/Divide2'
   *  Sum: '<S684>/Add'
   *  Sum: '<S707>/Add'
   *  Sum: '<S710>/Add'
   *  Trigonometry: '<S707>/Trigonometric Function'
   *  Trigonometry: '<S707>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ft == 1) {
    /* Gain: '<S710>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_p *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_lz = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_hvl * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_lz = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S684>/Manual Switch' */

  /* Sum: '<S684>/Add1' incorporates:
   *  Constant: '<S684>/Constant'
   *  Product: '<S684>/Divide2'
   *  Product: '<S684>/Divide3'
   *  Product: '<S684>/Divide4'
   *  Trigonometry: '<S684>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_h2 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_p - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_m) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_lz;

  /* Product: '<S686>/Divide3' */
  locvar_Divide3_p0a = locvar_Divide4_dh * locvar_ManualSwitch_h2;

  /* Sum: '<S166>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_d = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7];

  /* ManualSwitch: '<S687>/Manual Switch' incorporates:
   *  Constant: '<S687>/Constant1'
   *  Constant: '<S692>/Constant'
   *  Constant: '<S700>/Constant'
   *  Constant: '<S700>/Constant1'
   *  Constant: '<S700>/Constant10'
   *  Constant: '<S700>/Constant11'
   *  Constant: '<S700>/Constant12'
   *  Constant: '<S700>/Constant2'
   *  Constant: '<S700>/Constant3'
   *  Constant: '<S700>/Constant4'
   *  Constant: '<S700>/Constant5'
   *  Constant: '<S700>/Constant6'
   *  Constant: '<S700>/Constant8'
   *  Product: '<S687>/Divide'
   *  Product: '<S687>/Divide5'
   *  Product: '<S700>/Divide1'
   *  Product: '<S700>/Divide3'
   *  Product: '<S700>/Divide4'
   *  Product: '<S700>/Divide5'
   *  Product: '<S700>/Divide6'
   *  Sum: '<S700>/Add'
   *  Sum: '<S700>/Add1'
   *  Sum: '<S700>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_fy == 1) {
    locvar_ManualSwitch_ex = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_hvl * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_ex = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S687>/Manual Switch' */

  /* Sum: '<S687>/Add1' incorporates:
   *  Constant: '<S687>/Constant'
   *  Product: '<S687>/Divide2'
   *  Product: '<S687>/Divide3'
   *  Product: '<S687>/Divide4'
   *  Trigonometry: '<S687>/Trigonometric Function'
   *  Trigonometry: '<S687>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_c = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_m - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_Divide4_dh) + sin(locvar_ManualSwitch_d) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_ex;

  /* Product: '<S686>/Divide4' */
  locvar_Divide4_i0 = locvar_ManualSwitch_p * locvar_ManualSwitch_c;

  /* ManualSwitch: '<S689>/Manual Switch' incorporates:
   *  Constant: '<S689>/Constant1'
   *  Constant: '<S692>/Constant'
   *  Product: '<S689>/Divide'
   *  Product: '<S689>/Divide5'
   *  Product: '<S709>/Divide1'
   *  Product: '<S709>/Divide6'
   *  Sum: '<S709>/Add2'
   *  Trigonometry: '<S709>/Trigonometric Function4'
   *  Trigonometry: '<S709>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ik == 1) {
    locvar_ManualSwitch_ga = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_hvl * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_ga = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S689>/Manual Switch' */

  /* Sum: '<S689>/Add1' incorporates:
   *  Constant: '<S689>/Constant'
   *  Product: '<S689>/Divide2'
   *  Product: '<S689>/Divide3'
   *  Product: '<S689>/Divide4'
   *  Trigonometry: '<S689>/Trigonometric Function'
   *  Trigonometry: '<S689>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * locvar_Divide4_dh
                     - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
                     locvar_ManualSwitch_p) + cos(locvar_ManualSwitch_d) * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_ga;

  /* Product: '<S686>/Divide5' */
  locvar_Divide5_luy = locvar_ManualSwitch_m * locvar_Add2_o3;

  /* Product: '<S690>/Divide' incorporates:
   *  Math: '<S690>/Math Function'
   *  Math: '<S690>/Math Function1'
   *  Product: '<S690>/Divide3'
   *  Product: '<S690>/Divide4'
   *  Sum: '<S690>/Add'
   *  Sum: '<S690>/Add1'
   */
  locvar_Divide_hz = (locvar_Divide4_dh * locvar_Add2_o3 - locvar_ManualSwitch_m
                      * locvar_ManualSwitch_h2) / (locvar_Divide4_dh *
    locvar_Divide4_dh + locvar_ManualSwitch_m * locvar_ManualSwitch_m);

  /* Product: '<S691>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide3_n5 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    locvar_ManualSwitch_c;

  /* Product: '<S691>/Divide4' incorporates:
   *  Product: '<S691>/Divide1'
   *  Product: '<S691>/Divide2'
   *  Product: '<S691>/Divide5'
   *  Product: '<S691>/Divide6'
   *  Sum: '<S691>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_pem = ((locvar_Divide4_dh * locvar_ManualSwitch_h2 +
    locvar_ManualSwitch_p * locvar_ManualSwitch_c) + locvar_ManualSwitch_m *
                        locvar_Add2_o3) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]
    * locvar_ManualSwitch_p;

  /* Math: '<S691>/Math Function' */
  locvar_MathFunction_p2 = locvar_Divide4_dh * locvar_Divide4_dh;

  /* Math: '<S691>/Math Function1' */
  locvar_MathFunction1_ot = locvar_ManualSwitch_m * locvar_ManualSwitch_m;

  /* Sum: '<S694>/Add' incorporates:
   *  Product: '<S694>/Divide2'
   *  Product: '<S694>/Divide4'
   *  Trigonometry: '<S694>/Trigonometric Function1'
   *  Trigonometry: '<S694>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add_me = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (locvar_ManualSwitch_d) + sin(locvar_ManualSwitch_d) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10];

  /* Trigonometry: '<S697>/Trigonometric Function1' */
  locvar_TrigonometricFunction1_d5j = cos(locvar_ManualSwitch_d);

  /* Trigonometry: '<S697>/Trigonometric Function2' */
  locvar_TrigonometricFunction2_lt = sin(locvar_ManualSwitch_d);

  /* Sum: '<S720>/Add' incorporates:
   *  Constant: '<S720>/Ixx1'
   *  Constant: '<S720>/Ixz1'
   *  Constant: '<S720>/Izz1'
   *  Math: '<S720>/Math Function'
   *  Product: '<S720>/Divide1'
   */
  locvar_ManualSwitch_d = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S712>/Divide4' incorporates:
   *  Constant: '<S712>/Ixx'
   *  Constant: '<S712>/Ixz'
   *  Constant: '<S712>/Iyy'
   *  Constant: '<S712>/Izz'
   *  Product: '<S712>/Divide3'
   *  Sum: '<S712>/Add'
   */
  locvar_ManualSwitch_c = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_d;

  /* Sum: '<S679>/Add1' incorporates:
   *  Constant: '<S711>/Ixz'
   *  Constant: '<S711>/Iyy'
   *  Constant: '<S711>/Izz'
   *  Math: '<S711>/Math Function'
   *  Product: '<S679>/Divide2'
   *  Product: '<S679>/Divide3'
   *  Product: '<S711>/Divide3'
   *  Product: '<S711>/Divide4'
   *  Sum: '<S711>/Add'
   *  Sum: '<S711>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_jqe = ((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                     ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                     ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_d *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_ManualSwitch_c *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* Sum: '<S702>/Add' incorporates:
   *  Constant: '<S702>/Constant10'
   *  Constant: '<S702>/Constant11'
   *  Constant: '<S702>/Constant12'
   *  Constant: '<S702>/Constant13'
   *  Constant: '<S702>/Constant14'
   *  Constant: '<S702>/Constant15'
   *  Constant: '<S702>/Constant5'
   *  Constant: '<S702>/Constant6'
   *  Constant: '<S702>/Constant7'
   *  Constant: '<S702>/Constant8'
   *  Constant: '<S702>/Constant9'
   *  Product: '<S702>/Divide3'
   *  Product: '<S702>/Divide4'
   *  Product: '<S702>/Divide5'
   *  Product: '<S702>/Divide6'
   *  Product: '<S702>/Divide7'
   *  Sum: '<S702>/Add1'
   *  Sum: '<S702>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S706>/Add' incorporates:
   *  Constant: '<S706>/Constant'
   *  Constant: '<S706>/Constant10'
   *  Constant: '<S706>/Constant11'
   *  Constant: '<S706>/Constant12'
   *  Constant: '<S706>/Constant13'
   *  Constant: '<S706>/Constant14'
   *  Constant: '<S706>/Constant15'
   *  Constant: '<S706>/Constant5'
   *  Constant: '<S706>/Constant6'
   *  Constant: '<S706>/Constant8'
   *  Constant: '<S706>/Constant9'
   *  Product: '<S706>/Divide3'
   *  Product: '<S706>/Divide4'
   *  Product: '<S706>/Divide5'
   *  Product: '<S706>/Divide6'
   *  Product: '<S706>/Divide7'
   *  Sum: '<S706>/Add1'
   *  Sum: '<S706>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_le = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S701>/Add' incorporates:
   *  Product: '<S701>/Divide3'
   *  Product: '<S701>/Divide5'
   *  Trigonometry: '<S701>/Trigonometric Function'
   *  Trigonometry: '<S701>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_e = locvar_Add2_o3 * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_le;

  /* Product: '<S714>/Divide4' incorporates:
   *  Constant: '<S714>/Ixz'
   */
  locvar_Add2_ai = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_d;

  /* Sum: '<S705>/Add2' incorporates:
   *  Product: '<S705>/Divide1'
   *  Product: '<S705>/Divide6'
   *  Trigonometry: '<S705>/Trigonometric Function4'
   *  Trigonometry: '<S705>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_le = locvar_Add2_o3 * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_le;

  /* Sum: '<S679>/Add' incorporates:
   *  Constant: '<S713>/Izz'
   *  Product: '<S679>/Divide'
   *  Product: '<S679>/Divide4'
   *  Product: '<S713>/Divide4'
   */
  locvar_Add_ay = ANN_EKF_NMPC_2_P.IzzB / locvar_ManualSwitch_d *
    locvar_ManualSwitch_e + locvar_Add2_ai * locvar_ManualSwitch_le;

  /* Product: '<S681>/Divide' incorporates:
   *  Constant: '<S704>/Constant'
   *  Constant: '<S704>/Constant1'
   *  Constant: '<S704>/Constant11'
   *  Constant: '<S704>/Constant12'
   *  Constant: '<S704>/Constant13'
   *  Constant: '<S704>/Constant14'
   *  Constant: '<S704>/Constant2'
   *  Constant: '<S704>/Constant3'
   *  Constant: '<S704>/Constant4'
   *  Constant: '<S704>/Constant5'
   *  Constant: '<S704>/Constant6'
   *  Constant: '<S704>/Constant7'
   *  Constant: '<S704>/Constant8'
   *  Constant: '<S704>/Constant9'
   *  Constant: '<S717>/Ixz'
   *  Constant: '<S717>/Iyy'
   *  Gain: '<S704>/Gain1'
   *  Gain: '<S704>/Gain2'
   *  Product: '<S704>/Divide1'
   *  Product: '<S704>/Divide2'
   *  Product: '<S704>/Divide3'
   *  Product: '<S704>/Divide4'
   *  Product: '<S704>/Divide5'
   *  Product: '<S704>/Divide6'
   *  Product: '<S717>/Divide4'
   *  Sum: '<S704>/Add'
   *  Sum: '<S704>/Add1'
   *  Sum: '<S704>/Add2'
   *  Sum: '<S704>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S690>/Unit Delay'
   */
  locvar_Divide_ft = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_c *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                        ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
                        (locvar_Divide4_dh - ANN_EKF_NMPC_2_P.Utrim)) +
                       ANN_EKF_NMPC_2_P.Cmde *
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                      ANN_EKF_NMPC_2_P.Utrim * (locvar_Divide4_dh -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                      ANN_EKF_NMPC_2_P.Gain2_Gain_pq *
                      ANN_EKF_NMPC_2_P.Gain1_Gain_l) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_g / ANN_EKF_NMPC_2_P.IyyB);

  /* Sum: '<S682>/Add1' incorporates:
   *  Constant: '<S718>/Ixx'
   *  Constant: '<S718>/Ixx1'
   *  Constant: '<S718>/Ixz'
   *  Constant: '<S718>/Iyy'
   *  Math: '<S718>/Math Function'
   *  Product: '<S682>/Divide2'
   *  Product: '<S682>/Divide3'
   *  Product: '<S718>/Divide3'
   *  Product: '<S718>/Divide4'
   *  Sum: '<S718>/Add'
   *  Sum: '<S718>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_mq = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_d *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_ManualSwitch_c *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S682>/Add' incorporates:
   *  Constant: '<S719>/Ixx'
   *  Product: '<S682>/Divide'
   *  Product: '<S682>/Divide4'
   *  Product: '<S719>/Divide4'
   */
  locvar_Add_bs = ANN_EKF_NMPC_2_P.IxxB / locvar_ManualSwitch_d *
    locvar_ManualSwitch_le + locvar_Add2_ai * locvar_ManualSwitch_e;

  /* Product: '<S728>/Divide2' incorporates:
   *  Trigonometry: '<S728>/Trigonometric Function'
   *  Trigonometry: '<S728>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_pp = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S730>/Divide2' incorporates:
   *  Trigonometry: '<S730>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_c0 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S733>/Divide2' incorporates:
   *  Trigonometry: '<S733>/Trigonometric Function'
   *  Trigonometry: '<S733>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_bs = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Sum: '<S167>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_dh = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8];

  /* Product: '<S725>/Divide4' incorporates:
   *  Constant: '<S725>/Constant'
   *  Constant: '<S725>/Constant1'
   *  Math: '<S725>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_dt = ANN_EKF_NMPC_2_P.Constant_Value_li *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S744>/Add' incorporates:
   *  Constant: '<S744>/Constant'
   *  Constant: '<S744>/Constant1'
   *  Constant: '<S744>/Constant10'
   *  Constant: '<S744>/Constant11'
   *  Constant: '<S744>/Constant12'
   *  Constant: '<S744>/Constant13'
   *  Constant: '<S744>/Constant14'
   *  Constant: '<S744>/Constant15'
   *  Constant: '<S744>/Constant2'
   *  Constant: '<S744>/Constant3'
   *  Constant: '<S744>/Constant4'
   *  Constant: '<S744>/Constant5'
   *  Constant: '<S744>/Constant6'
   *  Constant: '<S744>/Constant7'
   *  Constant: '<S744>/Constant8'
   *  Constant: '<S744>/Constant9'
   *  Gain: '<S744>/Gain1'
   *  Gain: '<S744>/Gain2'
   *  Gain: '<S744>/Gain3'
   *  Product: '<S744>/Divide1'
   *  Product: '<S744>/Divide2'
   *  Product: '<S744>/Divide3'
   *  Product: '<S744>/Divide4'
   *  Product: '<S744>/Divide5'
   *  Product: '<S744>/Divide6'
   *  Product: '<S744>/Divide7'
   *  Sum: '<S744>/Add1'
   *  Sum: '<S744>/Add2'
   *  Sum: '<S744>/Add3'
   *  Sum: '<S744>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S735>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_cp *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_pp - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
                   (locvar_ManualSwitch_pp - ANN_EKF_NMPC_2_P.Utrim) *
                   ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain2_Gain_gd *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_aa) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_e;

  /* ManualSwitch: '<S743>/Manual Switch' incorporates:
   *  Constant: '<S743>/AR'
   *  Constant: '<S743>/Constant15'
   *  Constant: '<S743>/Constant16'
   *  Constant: '<S743>/Constant17'
   *  Constant: '<S743>/Constant18'
   *  Constant: '<S743>/e'
   *  Math: '<S743>/Math Function'
   *  Product: '<S743>/Divide8'
   *  Product: '<S743>/Divide9'
   *  Sum: '<S743>/Add5'
   *  Sum: '<S743>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_mf == 1) {
    locvar_ManualSwitch_p = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_p = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_m / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_f +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S743>/Manual Switch' */

  /* Sum: '<S743>/Add' incorporates:
   *  Constant: '<S743>/Constant1'
   *  Constant: '<S743>/Constant10'
   *  Constant: '<S743>/Constant11'
   *  Constant: '<S743>/Constant12'
   *  Constant: '<S743>/Constant13'
   *  Constant: '<S743>/Constant14'
   *  Constant: '<S743>/Constant2'
   *  Constant: '<S743>/Constant3'
   *  Constant: '<S743>/Constant4'
   *  Constant: '<S743>/Constant6'
   *  Constant: '<S743>/Constant7'
   *  Constant: '<S743>/Constant8'
   *  Constant: '<S743>/Constant9'
   *  Gain: '<S743>/Gain1'
   *  Gain: '<S743>/Gain2'
   *  Gain: '<S743>/Gain3'
   *  Product: '<S743>/Divide1'
   *  Product: '<S743>/Divide2'
   *  Product: '<S743>/Divide3'
   *  Product: '<S743>/Divide5'
   *  Product: '<S743>/Divide6'
   *  Product: '<S743>/Divide7'
   *  Sum: '<S743>/Add1'
   *  Sum: '<S743>/Add2'
   *  Sum: '<S743>/Add3'
   *  Sum: '<S743>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S735>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_p) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_cp *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_pp - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_pp -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_oz *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_iy) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_lu;

  /* ManualSwitch: '<S729>/Manual Switch' incorporates:
   *  Constant: '<S729>/Constant1'
   *  Constant: '<S737>/Constant'
   *  Constant: '<S755>/Constant'
   *  Constant: '<S755>/Constant1'
   *  Constant: '<S755>/Constant2'
   *  Math: '<S755>/Math Function'
   *  Product: '<S729>/Divide'
   *  Product: '<S729>/Divide5'
   *  Product: '<S752>/Divide3'
   *  Product: '<S752>/Divide5'
   *  Product: '<S755>/Divide1'
   *  Product: '<S755>/Divide2'
   *  Sum: '<S729>/Add'
   *  Sum: '<S752>/Add'
   *  Sum: '<S755>/Add'
   *  Trigonometry: '<S752>/Trigonometric Function'
   *  Trigonometry: '<S752>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_j == 1) {
    /* Gain: '<S755>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_ii *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_p = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_dt * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_p = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S729>/Manual Switch' */

  /* Sum: '<S729>/Add1' incorporates:
   *  Constant: '<S729>/Constant'
   *  Product: '<S729>/Divide2'
   *  Product: '<S729>/Divide3'
   *  Product: '<S729>/Divide4'
   *  Trigonometry: '<S729>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_m = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_c0 - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_bs) - sin(locvar_Divide4_dh) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_p;

  /* Product: '<S731>/Divide3' */
  locvar_Divide3_bt = locvar_ManualSwitch_pp * locvar_ManualSwitch_m;

  /* ManualSwitch: '<S732>/Manual Switch' incorporates:
   *  Constant: '<S732>/Constant1'
   *  Constant: '<S737>/Constant'
   *  Constant: '<S745>/Constant'
   *  Constant: '<S745>/Constant1'
   *  Constant: '<S745>/Constant10'
   *  Constant: '<S745>/Constant11'
   *  Constant: '<S745>/Constant12'
   *  Constant: '<S745>/Constant2'
   *  Constant: '<S745>/Constant3'
   *  Constant: '<S745>/Constant4'
   *  Constant: '<S745>/Constant5'
   *  Constant: '<S745>/Constant6'
   *  Constant: '<S745>/Constant8'
   *  Product: '<S732>/Divide'
   *  Product: '<S732>/Divide5'
   *  Product: '<S745>/Divide1'
   *  Product: '<S745>/Divide3'
   *  Product: '<S745>/Divide4'
   *  Product: '<S745>/Divide5'
   *  Product: '<S745>/Divide6'
   *  Sum: '<S745>/Add'
   *  Sum: '<S745>/Add1'
   *  Sum: '<S745>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ls == 1) {
    locvar_ManualSwitch_h2 = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_dt * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_h2 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S732>/Manual Switch' */

  /* Sum: '<S732>/Add1' incorporates:
   *  Constant: '<S732>/Constant'
   *  Product: '<S732>/Divide2'
   *  Product: '<S732>/Divide3'
   *  Product: '<S732>/Divide4'
   *  Trigonometry: '<S732>/Trigonometric Function'
   *  Trigonometry: '<S732>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_d = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    locvar_ManualSwitch_bs - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_pp) + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (locvar_Divide4_dh) * ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_h2;

  /* Product: '<S731>/Divide4' */
  locvar_Divide4_fqv = locvar_ManualSwitch_c0 * locvar_ManualSwitch_d;

  /* ManualSwitch: '<S734>/Manual Switch' incorporates:
   *  Constant: '<S734>/Constant1'
   *  Constant: '<S737>/Constant'
   *  Product: '<S734>/Divide'
   *  Product: '<S734>/Divide5'
   *  Product: '<S754>/Divide1'
   *  Product: '<S754>/Divide6'
   *  Sum: '<S754>/Add2'
   *  Trigonometry: '<S754>/Trigonometric Function4'
   *  Trigonometry: '<S754>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_lc == 1) {
    locvar_ManualSwitch_c = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_dt * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_c = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S734>/Manual Switch' */

  /* Sum: '<S734>/Add1' incorporates:
   *  Constant: '<S734>/Constant'
   *  Product: '<S734>/Divide2'
   *  Product: '<S734>/Divide3'
   *  Product: '<S734>/Divide4'
   *  Trigonometry: '<S734>/Trigonometric Function'
   *  Trigonometry: '<S734>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
                     locvar_ManualSwitch_pp -
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
                     locvar_ManualSwitch_c0) + cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                    (locvar_Divide4_dh) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_c;

  /* Product: '<S731>/Divide5' */
  locvar_Divide5_ny = locvar_ManualSwitch_bs * locvar_Add2_o3;

  /* Product: '<S735>/Divide' incorporates:
   *  Math: '<S735>/Math Function'
   *  Math: '<S735>/Math Function1'
   *  Product: '<S735>/Divide3'
   *  Product: '<S735>/Divide4'
   *  Sum: '<S735>/Add'
   *  Sum: '<S735>/Add1'
   */
  locvar_Divide_n = (locvar_ManualSwitch_pp * locvar_Add2_o3 -
                     locvar_ManualSwitch_bs * locvar_ManualSwitch_m) /
    (locvar_ManualSwitch_pp * locvar_ManualSwitch_pp + locvar_ManualSwitch_bs *
     locvar_ManualSwitch_bs);

  /* Product: '<S736>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide3_ai5 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    locvar_ManualSwitch_d;

  /* Product: '<S736>/Divide4' incorporates:
   *  Product: '<S736>/Divide1'
   *  Product: '<S736>/Divide2'
   *  Product: '<S736>/Divide5'
   *  Product: '<S736>/Divide6'
   *  Sum: '<S736>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ik = ((locvar_ManualSwitch_pp * locvar_ManualSwitch_m +
                        locvar_ManualSwitch_c0 * locvar_ManualSwitch_d) +
                       locvar_ManualSwitch_bs * locvar_Add2_o3) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_c0;

  /* Math: '<S736>/Math Function' */
  locvar_MathFunction_bv = locvar_ManualSwitch_pp * locvar_ManualSwitch_pp;

  /* Math: '<S736>/Math Function1' */
  locvar_MathFunction1_id = locvar_ManualSwitch_bs * locvar_ManualSwitch_bs;

  /* Trigonometry: '<S739>/Trigonometric Function3' */
  locvar_Divide4_dh = tan(locvar_Divide4_dh);

  /* Saturate: '<S739>/Saturation' */
  if (locvar_Divide4_dh > ANN_EKF_NMPC_2_P.Saturation_UpperSat_i) {
    locvar_Saturation_m = ANN_EKF_NMPC_2_P.Saturation_UpperSat_i;
  } else if (locvar_Divide4_dh < ANN_EKF_NMPC_2_P.Saturation_LowerSat_n) {
    locvar_Saturation_m = ANN_EKF_NMPC_2_P.Saturation_LowerSat_n;
  } else {
    locvar_Saturation_m = locvar_Divide4_dh;
  }

  /* End of Saturate: '<S739>/Saturation' */

  /* Sum: '<S765>/Add' incorporates:
   *  Constant: '<S765>/Ixx1'
   *  Constant: '<S765>/Ixz1'
   *  Constant: '<S765>/Izz1'
   *  Math: '<S765>/Math Function'
   *  Product: '<S765>/Divide1'
   */
  locvar_ManualSwitch_m = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S757>/Divide4' incorporates:
   *  Constant: '<S757>/Ixx'
   *  Constant: '<S757>/Ixz'
   *  Constant: '<S757>/Iyy'
   *  Constant: '<S757>/Izz'
   *  Product: '<S757>/Divide3'
   *  Sum: '<S757>/Add'
   */
  locvar_ManualSwitch_d = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_m;

  /* Sum: '<S724>/Add1' incorporates:
   *  Constant: '<S756>/Ixz'
   *  Constant: '<S756>/Iyy'
   *  Constant: '<S756>/Izz'
   *  Math: '<S756>/Math Function'
   *  Product: '<S724>/Divide2'
   *  Product: '<S724>/Divide3'
   *  Product: '<S756>/Divide3'
   *  Product: '<S756>/Divide4'
   *  Sum: '<S756>/Add'
   *  Sum: '<S756>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_ety = ((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                     ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                     ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_m *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_ManualSwitch_d *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* Sum: '<S747>/Add' incorporates:
   *  Constant: '<S747>/Constant10'
   *  Constant: '<S747>/Constant11'
   *  Constant: '<S747>/Constant12'
   *  Constant: '<S747>/Constant13'
   *  Constant: '<S747>/Constant14'
   *  Constant: '<S747>/Constant15'
   *  Constant: '<S747>/Constant5'
   *  Constant: '<S747>/Constant6'
   *  Constant: '<S747>/Constant7'
   *  Constant: '<S747>/Constant8'
   *  Constant: '<S747>/Constant9'
   *  Product: '<S747>/Divide3'
   *  Product: '<S747>/Divide4'
   *  Product: '<S747>/Divide5'
   *  Product: '<S747>/Divide6'
   *  Product: '<S747>/Divide7'
   *  Sum: '<S747>/Add1'
   *  Sum: '<S747>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S751>/Add' incorporates:
   *  Constant: '<S751>/Constant'
   *  Constant: '<S751>/Constant10'
   *  Constant: '<S751>/Constant11'
   *  Constant: '<S751>/Constant12'
   *  Constant: '<S751>/Constant13'
   *  Constant: '<S751>/Constant14'
   *  Constant: '<S751>/Constant15'
   *  Constant: '<S751>/Constant5'
   *  Constant: '<S751>/Constant6'
   *  Constant: '<S751>/Constant8'
   *  Constant: '<S751>/Constant9'
   *  Product: '<S751>/Divide3'
   *  Product: '<S751>/Divide4'
   *  Product: '<S751>/Divide5'
   *  Product: '<S751>/Divide6'
   *  Product: '<S751>/Divide7'
   *  Sum: '<S751>/Add1'
   *  Sum: '<S751>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_cx = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
    ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S746>/Add' incorporates:
   *  Product: '<S746>/Divide3'
   *  Product: '<S746>/Divide5'
   *  Trigonometry: '<S746>/Trigonometric Function'
   *  Trigonometry: '<S746>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Ayb_k = locvar_Add2_o3 * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) -
    sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_cx;

  /* Product: '<S759>/Divide4' incorporates:
   *  Constant: '<S759>/Ixz'
   */
  locvar_ManualSwitch_dl = ANN_EKF_NMPC_2_P.IxzB / locvar_ManualSwitch_m;

  /* Sum: '<S750>/Add2' incorporates:
   *  Product: '<S750>/Divide1'
   *  Product: '<S750>/Divide6'
   *  Trigonometry: '<S750>/Trigonometric Function4'
   *  Trigonometry: '<S750>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_cx = locvar_Add2_o3 * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_ManualSwitch_cx;

  /* Sum: '<S724>/Add' incorporates:
   *  Constant: '<S758>/Izz'
   *  Product: '<S724>/Divide'
   *  Product: '<S724>/Divide4'
   *  Product: '<S758>/Divide4'
   */
  locvar_Add_ez = ANN_EKF_NMPC_2_P.IzzB / locvar_ManualSwitch_m * locvar_Ayb_k +
    locvar_ManualSwitch_dl * locvar_ManualSwitch_cx;

  /* Product: '<S726>/Divide' incorporates:
   *  Constant: '<S749>/Constant'
   *  Constant: '<S749>/Constant1'
   *  Constant: '<S749>/Constant11'
   *  Constant: '<S749>/Constant12'
   *  Constant: '<S749>/Constant13'
   *  Constant: '<S749>/Constant14'
   *  Constant: '<S749>/Constant2'
   *  Constant: '<S749>/Constant3'
   *  Constant: '<S749>/Constant4'
   *  Constant: '<S749>/Constant5'
   *  Constant: '<S749>/Constant6'
   *  Constant: '<S749>/Constant7'
   *  Constant: '<S749>/Constant8'
   *  Constant: '<S749>/Constant9'
   *  Constant: '<S762>/Ixz'
   *  Constant: '<S762>/Iyy'
   *  Gain: '<S749>/Gain1'
   *  Gain: '<S749>/Gain2'
   *  Product: '<S749>/Divide1'
   *  Product: '<S749>/Divide2'
   *  Product: '<S749>/Divide3'
   *  Product: '<S749>/Divide4'
   *  Product: '<S749>/Divide5'
   *  Product: '<S749>/Divide6'
   *  Product: '<S762>/Divide4'
   *  Sum: '<S749>/Add'
   *  Sum: '<S749>/Add1'
   *  Sum: '<S749>/Add2'
   *  Sum: '<S749>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S735>/Unit Delay'
   */
  locvar_Divide_n0 = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_cp *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                        ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
                        (locvar_ManualSwitch_pp - ANN_EKF_NMPC_2_P.Utrim)) +
                       ANN_EKF_NMPC_2_P.Cmde *
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                      ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_pp -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                      ANN_EKF_NMPC_2_P.Gain2_Gain_gp *
                      ANN_EKF_NMPC_2_P.Gain1_Gain_gi) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_o / ANN_EKF_NMPC_2_P.IyyB);

  /* Sum: '<S727>/Add1' incorporates:
   *  Constant: '<S763>/Ixx'
   *  Constant: '<S763>/Ixx1'
   *  Constant: '<S763>/Ixz'
   *  Constant: '<S763>/Iyy'
   *  Math: '<S763>/Math Function'
   *  Product: '<S727>/Divide2'
   *  Product: '<S727>/Divide3'
   *  Product: '<S763>/Divide3'
   *  Product: '<S763>/Divide4'
   *  Sum: '<S763>/Add'
   *  Sum: '<S763>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_pkj = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                     ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                     ANN_EKF_NMPC_2_P.IxzB) / locvar_ManualSwitch_m *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_ManualSwitch_d *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S727>/Add' incorporates:
   *  Constant: '<S764>/Ixx'
   *  Product: '<S727>/Divide'
   *  Product: '<S727>/Divide4'
   *  Product: '<S764>/Divide4'
   */
  locvar_Add_df3 = ANN_EKF_NMPC_2_P.IxxB / locvar_ManualSwitch_m *
    locvar_ManualSwitch_cx + locvar_ManualSwitch_dl * locvar_Ayb_k;

  /* Product: '<S323>/Divide2' incorporates:
   *  Trigonometry: '<S323>/Trigonometric Function'
   *  Trigonometry: '<S323>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_e = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S325>/Divide2' incorporates:
   *  Trigonometry: '<S325>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_le = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S328>/Divide2' incorporates:
   *  Trigonometry: '<S328>/Trigonometric Function'
   *  Trigonometry: '<S328>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Azb_h = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S320>/Divide4' incorporates:
   *  Constant: '<S320>/Constant'
   *  Constant: '<S320>/Constant1'
   *  Math: '<S320>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_kz = ANN_EKF_NMPC_2_P.Constant_Value_hr *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S339>/Add' incorporates:
   *  Constant: '<S339>/Constant'
   *  Constant: '<S339>/Constant1'
   *  Constant: '<S339>/Constant10'
   *  Constant: '<S339>/Constant11'
   *  Constant: '<S339>/Constant12'
   *  Constant: '<S339>/Constant13'
   *  Constant: '<S339>/Constant14'
   *  Constant: '<S339>/Constant15'
   *  Constant: '<S339>/Constant2'
   *  Constant: '<S339>/Constant3'
   *  Constant: '<S339>/Constant4'
   *  Constant: '<S339>/Constant5'
   *  Constant: '<S339>/Constant6'
   *  Constant: '<S339>/Constant7'
   *  Constant: '<S339>/Constant8'
   *  Constant: '<S339>/Constant9'
   *  Gain: '<S339>/Gain1'
   *  Gain: '<S339>/Gain2'
   *  Gain: '<S339>/Gain3'
   *  Product: '<S339>/Divide1'
   *  Product: '<S339>/Divide2'
   *  Product: '<S339>/Divide3'
   *  Product: '<S339>/Divide4'
   *  Product: '<S339>/Divide5'
   *  Product: '<S339>/Divide6'
   *  Product: '<S339>/Divide7'
   *  Sum: '<S339>/Add1'
   *  Sum: '<S339>/Add2'
   *  Sum: '<S339>/Add3'
   *  Sum: '<S339>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S330>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_g *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_ManualSwitch_e - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_e
    - ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                   ANN_EKF_NMPC_2_P.Gain2_Gain_os *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_o2) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_jg;

  /* ManualSwitch: '<S338>/Manual Switch' incorporates:
   *  Constant: '<S338>/AR'
   *  Constant: '<S338>/Constant15'
   *  Constant: '<S338>/Constant16'
   *  Constant: '<S338>/Constant17'
   *  Constant: '<S338>/Constant18'
   *  Constant: '<S338>/e'
   *  Math: '<S338>/Math Function'
   *  Product: '<S338>/Divide8'
   *  Product: '<S338>/Divide9'
   *  Sum: '<S338>/Add5'
   *  Sum: '<S338>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_gj == 1) {
    locvar_ManualSwitch_pp = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_pp = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_l / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_i +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S338>/Manual Switch' */

  /* Sum: '<S338>/Add' incorporates:
   *  Constant: '<S338>/Constant1'
   *  Constant: '<S338>/Constant10'
   *  Constant: '<S338>/Constant11'
   *  Constant: '<S338>/Constant12'
   *  Constant: '<S338>/Constant13'
   *  Constant: '<S338>/Constant14'
   *  Constant: '<S338>/Constant2'
   *  Constant: '<S338>/Constant3'
   *  Constant: '<S338>/Constant4'
   *  Constant: '<S338>/Constant6'
   *  Constant: '<S338>/Constant7'
   *  Constant: '<S338>/Constant8'
   *  Constant: '<S338>/Constant9'
   *  Gain: '<S338>/Gain1'
   *  Gain: '<S338>/Gain2'
   *  Gain: '<S338>/Gain3'
   *  Product: '<S338>/Divide1'
   *  Product: '<S338>/Divide2'
   *  Product: '<S338>/Divide3'
   *  Product: '<S338>/Divide5'
   *  Product: '<S338>/Divide6'
   *  Product: '<S338>/Divide7'
   *  Sum: '<S338>/Add1'
   *  Sum: '<S338>/Add2'
   *  Sum: '<S338>/Add3'
   *  Sum: '<S338>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S330>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_pp) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_g *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_ManualSwitch_e - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_e -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_pu *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_dd) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_of;

  /* ManualSwitch: '<S324>/Manual Switch' incorporates:
   *  Constant: '<S324>/Constant1'
   *  Constant: '<S332>/Constant'
   *  Constant: '<S350>/Constant'
   *  Constant: '<S350>/Constant1'
   *  Constant: '<S350>/Constant2'
   *  Math: '<S350>/Math Function'
   *  Product: '<S324>/Divide'
   *  Product: '<S324>/Divide5'
   *  Product: '<S347>/Divide3'
   *  Product: '<S347>/Divide5'
   *  Product: '<S350>/Divide1'
   *  Product: '<S350>/Divide2'
   *  Sum: '<S324>/Add'
   *  Sum: '<S347>/Add'
   *  Sum: '<S350>/Add'
   *  Trigonometry: '<S347>/Trigonometric Function'
   *  Trigonometry: '<S347>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_p == 1) {
    /* Gain: '<S350>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_a *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_pp = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_kz * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_pp = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S324>/Manual Switch' */

  /* Sum: '<S324>/Add1' incorporates:
   *  Constant: '<S324>/Constant'
   *  Product: '<S324>/Divide2'
   *  Product: '<S324>/Divide3'
   *  Product: '<S324>/Divide4'
   *  Trigonometry: '<S324>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_c0 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_ManualSwitch_le - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_Azb_h) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_pp;

  /* Product: '<S326>/Divide3' */
  locvar_Divide3_oc = locvar_ManualSwitch_e * locvar_ManualSwitch_c0;

  /* Sum: '<S158>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add_ev = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];

  /* ManualSwitch: '<S327>/Manual Switch' incorporates:
   *  Constant: '<S327>/Constant1'
   *  Constant: '<S332>/Constant'
   *  Constant: '<S340>/Constant'
   *  Constant: '<S340>/Constant1'
   *  Constant: '<S340>/Constant10'
   *  Constant: '<S340>/Constant11'
   *  Constant: '<S340>/Constant12'
   *  Constant: '<S340>/Constant2'
   *  Constant: '<S340>/Constant3'
   *  Constant: '<S340>/Constant4'
   *  Constant: '<S340>/Constant5'
   *  Constant: '<S340>/Constant6'
   *  Constant: '<S340>/Constant8'
   *  Product: '<S327>/Divide'
   *  Product: '<S327>/Divide5'
   *  Product: '<S340>/Divide1'
   *  Product: '<S340>/Divide3'
   *  Product: '<S340>/Divide4'
   *  Product: '<S340>/Divide5'
   *  Product: '<S340>/Divide6'
   *  Sum: '<S340>/Add'
   *  Sum: '<S340>/Add1'
   *  Sum: '<S340>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_gk == 1) {
    locvar_ManualSwitch_bs = (((((locvar_Add_ev - ANN_EKF_NMPC_2_P.Ptrim) *
      ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim
      + ANN_EKF_NMPC_2_P.Cyb * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_kz * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_bs = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S327>/Manual Switch' */

  /* Sum: '<S327>/Add1' incorporates:
   *  Constant: '<S327>/Constant'
   *  Product: '<S327>/Divide2'
   *  Product: '<S327>/Divide3'
   *  Product: '<S327>/Divide4'
   *  Trigonometry: '<S327>/Trigonometric Function'
   *  Trigonometry: '<S327>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_dh = ((locvar_Add_ev * locvar_Azb_h -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
                        locvar_ManualSwitch_e) + sin
                       (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                       (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                       ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_bs;

  /* Product: '<S326>/Divide4' */
  locvar_Divide4_oem = locvar_ManualSwitch_le * locvar_Divide4_dh;

  /* ManualSwitch: '<S329>/Manual Switch' incorporates:
   *  Constant: '<S329>/Constant1'
   *  Constant: '<S332>/Constant'
   *  Product: '<S329>/Divide'
   *  Product: '<S329>/Divide5'
   *  Product: '<S349>/Divide1'
   *  Product: '<S349>/Divide6'
   *  Sum: '<S349>/Add2'
   *  Trigonometry: '<S349>/Trigonometric Function4'
   *  Trigonometry: '<S349>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ir == 1) {
    locvar_ManualSwitch_m = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_kz * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_m = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S329>/Manual Switch' */

  /* Sum: '<S329>/Add1' incorporates:
   *  Constant: '<S329>/Constant'
   *  Product: '<S329>/Divide2'
   *  Product: '<S329>/Divide3'
   *  Product: '<S329>/Divide4'
   *  Trigonometry: '<S329>/Trigonometric Function'
   *  Trigonometry: '<S329>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_d = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_ManualSwitch_e - locvar_Add_ev * locvar_ManualSwitch_le) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g) +
    locvar_ManualSwitch_m;

  /* Product: '<S326>/Divide5' */
  locvar_Divide5_kh = locvar_Azb_h * locvar_ManualSwitch_d;

  /* Product: '<S330>/Divide' incorporates:
   *  Math: '<S330>/Math Function'
   *  Math: '<S330>/Math Function1'
   *  Product: '<S330>/Divide3'
   *  Product: '<S330>/Divide4'
   *  Sum: '<S330>/Add'
   *  Sum: '<S330>/Add1'
   */
  locvar_Divide_c = (locvar_ManualSwitch_e * locvar_ManualSwitch_d -
                     locvar_Azb_h * locvar_ManualSwitch_c0) /
    (locvar_ManualSwitch_e * locvar_ManualSwitch_e + locvar_Azb_h * locvar_Azb_h);

  /* Product: '<S331>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide3_j0 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_Divide4_dh;

  /* Product: '<S331>/Divide4' incorporates:
   *  Product: '<S331>/Divide1'
   *  Product: '<S331>/Divide2'
   *  Product: '<S331>/Divide5'
   *  Product: '<S331>/Divide6'
   *  Sum: '<S331>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_afp = ((locvar_ManualSwitch_e * locvar_ManualSwitch_c0 +
    locvar_ManualSwitch_le * locvar_Divide4_dh) + locvar_Azb_h *
                        locvar_ManualSwitch_d) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_le;

  /* Math: '<S331>/Math Function' */
  locvar_MathFunction_di = locvar_ManualSwitch_e * locvar_ManualSwitch_e;

  /* Math: '<S331>/Math Function1' */
  locvar_MathFunction1_e4 = locvar_Azb_h * locvar_Azb_h;

  /* Sum: '<S360>/Add' incorporates:
   *  Constant: '<S360>/Ixx1'
   *  Constant: '<S360>/Ixz1'
   *  Constant: '<S360>/Izz1'
   *  Math: '<S360>/Math Function'
   *  Product: '<S360>/Divide1'
   */
  locvar_Divide4_dh = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S352>/Divide4' incorporates:
   *  Constant: '<S352>/Ixx'
   *  Constant: '<S352>/Ixz'
   *  Constant: '<S352>/Iyy'
   *  Constant: '<S352>/Izz'
   *  Product: '<S352>/Divide3'
   *  Sum: '<S352>/Add'
   */
  locvar_ManualSwitch_d = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB / locvar_Divide4_dh;

  /* Sum: '<S319>/Add1' incorporates:
   *  Constant: '<S351>/Ixz'
   *  Constant: '<S351>/Iyy'
   *  Constant: '<S351>/Izz'
   *  Math: '<S351>/Math Function'
   *  Product: '<S319>/Divide2'
   *  Product: '<S319>/Divide3'
   *  Product: '<S351>/Divide3'
   *  Product: '<S351>/Divide4'
   *  Sum: '<S351>/Add'
   *  Sum: '<S351>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_o3 = ((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_Divide4_dh *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_ManualSwitch_d *
    locvar_Add_ev;

  /* Sum: '<S342>/Add' incorporates:
   *  Constant: '<S342>/Constant10'
   *  Constant: '<S342>/Constant11'
   *  Constant: '<S342>/Constant12'
   *  Constant: '<S342>/Constant13'
   *  Constant: '<S342>/Constant14'
   *  Constant: '<S342>/Constant15'
   *  Constant: '<S342>/Constant5'
   *  Constant: '<S342>/Constant6'
   *  Constant: '<S342>/Constant7'
   *  Constant: '<S342>/Constant8'
   *  Constant: '<S342>/Constant9'
   *  Product: '<S342>/Divide3'
   *  Product: '<S342>/Divide4'
   *  Product: '<S342>/Divide5'
   *  Product: '<S342>/Divide6'
   *  Product: '<S342>/Divide7'
   *  Sum: '<S342>/Add1'
   *  Sum: '<S342>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ((((locvar_Add_ev - ANN_EKF_NMPC_2_P.Ptrim) *
                      ANN_EKF_NMPC_2_P.Clp * (ANN_EKF_NMPC_2_P.b / 2.0) /
                      ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S346>/Add' incorporates:
   *  Constant: '<S346>/Constant'
   *  Constant: '<S346>/Constant10'
   *  Constant: '<S346>/Constant11'
   *  Constant: '<S346>/Constant12'
   *  Constant: '<S346>/Constant13'
   *  Constant: '<S346>/Constant14'
   *  Constant: '<S346>/Constant15'
   *  Constant: '<S346>/Constant5'
   *  Constant: '<S346>/Constant6'
   *  Constant: '<S346>/Constant8'
   *  Constant: '<S346>/Constant9'
   *  Product: '<S346>/Divide3'
   *  Product: '<S346>/Divide4'
   *  Product: '<S346>/Divide5'
   *  Product: '<S346>/Divide6'
   *  Product: '<S346>/Divide7'
   *  Sum: '<S346>/Add1'
   *  Sum: '<S346>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction_m2 = ((((locvar_Add_ev - ANN_EKF_NMPC_2_P.Ptrim) *
    ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
    ANN_EKF_NMPC_2_P.Cnb * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S341>/Add' incorporates:
   *  Product: '<S341>/Divide3'
   *  Product: '<S341>/Divide5'
   *  Trigonometry: '<S341>/Trigonometric Function'
   *  Trigonometry: '<S341>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Axb_e = locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) -
    sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
    locvar_TrigonometricFunction_m2;

  /* Product: '<S354>/Divide4' incorporates:
   *  Constant: '<S354>/Ixz'
   */
  locvar_Divide2_op = ANN_EKF_NMPC_2_P.IxzB / locvar_Divide4_dh;

  /* Sum: '<S345>/Add2' incorporates:
   *  Product: '<S345>/Divide1'
   *  Product: '<S345>/Divide6'
   *  Trigonometry: '<S345>/Trigonometric Function4'
   *  Trigonometry: '<S345>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction_m2 = locvar_Add2_db * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_TrigonometricFunction_m2;

  /* Sum: '<S319>/Add' incorporates:
   *  Constant: '<S353>/Izz'
   *  Product: '<S319>/Divide'
   *  Product: '<S319>/Divide4'
   *  Product: '<S353>/Divide4'
   */
  locvar_Add_au = ANN_EKF_NMPC_2_P.IzzB / locvar_Divide4_dh * locvar_Axb_e +
    locvar_Divide2_op * locvar_TrigonometricFunction_m2;

  /* Product: '<S321>/Divide' incorporates:
   *  Constant: '<S344>/Constant'
   *  Constant: '<S344>/Constant1'
   *  Constant: '<S344>/Constant11'
   *  Constant: '<S344>/Constant12'
   *  Constant: '<S344>/Constant13'
   *  Constant: '<S344>/Constant14'
   *  Constant: '<S344>/Constant2'
   *  Constant: '<S344>/Constant3'
   *  Constant: '<S344>/Constant4'
   *  Constant: '<S344>/Constant5'
   *  Constant: '<S344>/Constant6'
   *  Constant: '<S344>/Constant7'
   *  Constant: '<S344>/Constant8'
   *  Constant: '<S344>/Constant9'
   *  Constant: '<S357>/Ixz'
   *  Constant: '<S357>/Iyy'
   *  Gain: '<S344>/Gain1'
   *  Gain: '<S344>/Gain2'
   *  Product: '<S344>/Divide1'
   *  Product: '<S344>/Divide2'
   *  Product: '<S344>/Divide3'
   *  Product: '<S344>/Divide4'
   *  Product: '<S344>/Divide5'
   *  Product: '<S344>/Divide6'
   *  Product: '<S357>/Divide4'
   *  Sum: '<S344>/Add'
   *  Sum: '<S344>/Add1'
   *  Sum: '<S344>/Add2'
   *  Sum: '<S344>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S330>/Unit Delay'
   */
  locvar_Divide_aa = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_g *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                        ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
                        (locvar_ManualSwitch_e - ANN_EKF_NMPC_2_P.Utrim)) +
                       ANN_EKF_NMPC_2_P.Cmde *
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                      ANN_EKF_NMPC_2_P.Utrim * (locvar_ManualSwitch_e -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
                      ANN_EKF_NMPC_2_P.Gain2_Gain_eu *
                      ANN_EKF_NMPC_2_P.Gain1_Gain_g3) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_og / ANN_EKF_NMPC_2_P.IyyB);

  /* Sum: '<S322>/Add1' incorporates:
   *  Constant: '<S358>/Ixx'
   *  Constant: '<S358>/Ixx1'
   *  Constant: '<S358>/Ixz'
   *  Constant: '<S358>/Iyy'
   *  Math: '<S358>/Math Function'
   *  Product: '<S322>/Divide2'
   *  Product: '<S322>/Divide3'
   *  Product: '<S358>/Divide3'
   *  Product: '<S358>/Divide4'
   *  Sum: '<S358>/Add'
   *  Sum: '<S358>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add1_ob = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                    ANN_EKF_NMPC_2_P.IxzB) / locvar_Divide4_dh * locvar_Add_ev -
    locvar_ManualSwitch_d * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Sum: '<S322>/Add' incorporates:
   *  Constant: '<S359>/Ixx'
   *  Product: '<S322>/Divide'
   *  Product: '<S322>/Divide4'
   *  Product: '<S359>/Divide4'
   */
  locvar_Add_pii = ANN_EKF_NMPC_2_P.IxxB / locvar_Divide4_dh *
    locvar_TrigonometricFunction_m2 + locvar_Divide2_op * locvar_Axb_e;

  /* Product: '<S368>/Divide2' incorporates:
   *  Trigonometry: '<S368>/Trigonometric Function'
   *  Trigonometry: '<S368>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Ayb_k = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S370>/Divide2' incorporates:
   *  Trigonometry: '<S370>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_cx = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Sum: '<S159>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_ai = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10];

  /* Product: '<S373>/Divide2' incorporates:
   *  Trigonometry: '<S373>/Trigonometric Function'
   *  Trigonometry: '<S373>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_ManualSwitch_e = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S365>/Divide4' incorporates:
   *  Constant: '<S365>/Constant'
   *  Constant: '<S365>/Constant1'
   *  Math: '<S365>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ch = ANN_EKF_NMPC_2_P.Constant_Value_es *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S384>/Add' incorporates:
   *  Constant: '<S384>/Constant'
   *  Constant: '<S384>/Constant1'
   *  Constant: '<S384>/Constant10'
   *  Constant: '<S384>/Constant11'
   *  Constant: '<S384>/Constant12'
   *  Constant: '<S384>/Constant13'
   *  Constant: '<S384>/Constant14'
   *  Constant: '<S384>/Constant15'
   *  Constant: '<S384>/Constant2'
   *  Constant: '<S384>/Constant3'
   *  Constant: '<S384>/Constant4'
   *  Constant: '<S384>/Constant5'
   *  Constant: '<S384>/Constant6'
   *  Constant: '<S384>/Constant7'
   *  Constant: '<S384>/Constant8'
   *  Constant: '<S384>/Constant9'
   *  Gain: '<S384>/Gain1'
   *  Gain: '<S384>/Gain2'
   *  Gain: '<S384>/Gain3'
   *  Product: '<S384>/Divide1'
   *  Product: '<S384>/Divide2'
   *  Product: '<S384>/Divide3'
   *  Product: '<S384>/Divide4'
   *  Product: '<S384>/Divide5'
   *  Product: '<S384>/Divide6'
   *  Product: '<S384>/Divide7'
   *  Sum: '<S384>/Add1'
   *  Sum: '<S384>/Add2'
   *  Sum: '<S384>/Add3'
   *  Sum: '<S384>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S375>/Unit Delay'
   */
  locvar_Add_kq = ((((((locvar_Add2_ai - ANN_EKF_NMPC_2_P.Qtrim) *
                       ANN_EKF_NMPC_2_P.CLq * (ANN_EKF_NMPC_2_P.Cbar / 2.0) /
                       ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.CLa *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CL0)) +
                      ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_o *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_Ayb_k - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim * (locvar_Ayb_k -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                   ANN_EKF_NMPC_2_P.Gain2_Gain_nt *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_de) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_gw;

  /* ManualSwitch: '<S383>/Manual Switch' incorporates:
   *  Constant: '<S383>/AR'
   *  Constant: '<S383>/Constant15'
   *  Constant: '<S383>/Constant16'
   *  Constant: '<S383>/Constant17'
   *  Constant: '<S383>/Constant18'
   *  Constant: '<S383>/e'
   *  Math: '<S383>/Math Function'
   *  Product: '<S383>/Divide8'
   *  Product: '<S383>/Divide9'
   *  Sum: '<S383>/Add5'
   *  Sum: '<S383>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ff == 1) {
    locvar_ManualSwitch_le = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_le = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_i / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_mo +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S383>/Manual Switch' */

  /* Sum: '<S383>/Add' incorporates:
   *  Constant: '<S383>/Constant1'
   *  Constant: '<S383>/Constant10'
   *  Constant: '<S383>/Constant11'
   *  Constant: '<S383>/Constant12'
   *  Constant: '<S383>/Constant13'
   *  Constant: '<S383>/Constant14'
   *  Constant: '<S383>/Constant2'
   *  Constant: '<S383>/Constant3'
   *  Constant: '<S383>/Constant4'
   *  Constant: '<S383>/Constant6'
   *  Constant: '<S383>/Constant7'
   *  Constant: '<S383>/Constant8'
   *  Constant: '<S383>/Constant9'
   *  Gain: '<S383>/Gain1'
   *  Gain: '<S383>/Gain2'
   *  Gain: '<S383>/Gain3'
   *  Product: '<S383>/Divide1'
   *  Product: '<S383>/Divide2'
   *  Product: '<S383>/Divide3'
   *  Product: '<S383>/Divide5'
   *  Product: '<S383>/Divide6'
   *  Product: '<S383>/Divide7'
   *  Sum: '<S383>/Add1'
   *  Sum: '<S383>/Add2'
   *  Sum: '<S383>/Add3'
   *  Sum: '<S383>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S375>/Unit Delay'
   */
  locvar_Add2_db = ((((((locvar_Add2_ai - ANN_EKF_NMPC_2_P.Qtrim) *
                        ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar / 2.0) /
                        ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_le) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_o *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_Ayb_k - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_Ayb_k -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_nf *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_ic) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_g2;

  /* ManualSwitch: '<S369>/Manual Switch' incorporates:
   *  Constant: '<S369>/Constant1'
   *  Constant: '<S377>/Constant'
   *  Constant: '<S395>/Constant'
   *  Constant: '<S395>/Constant1'
   *  Constant: '<S395>/Constant2'
   *  Math: '<S395>/Math Function'
   *  Product: '<S369>/Divide'
   *  Product: '<S369>/Divide5'
   *  Product: '<S392>/Divide3'
   *  Product: '<S392>/Divide5'
   *  Product: '<S395>/Divide1'
   *  Product: '<S395>/Divide2'
   *  Sum: '<S369>/Add'
   *  Sum: '<S392>/Add'
   *  Sum: '<S395>/Add'
   *  Trigonometry: '<S392>/Trigonometric Function'
   *  Trigonometry: '<S392>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_h == 1) {
    /* Gain: '<S395>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_f *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_le = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_le = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S369>/Manual Switch' */

  /* Sum: '<S369>/Add1' incorporates:
   *  Constant: '<S369>/Constant'
   *  Product: '<S369>/Divide2'
   *  Product: '<S369>/Divide3'
   *  Product: '<S369>/Divide4'
   *  Trigonometry: '<S369>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Azb_h = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
                   locvar_ManualSwitch_cx - locvar_Add2_ai *
                   locvar_ManualSwitch_e) - sin
                  (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g)
    + locvar_ManualSwitch_le;

  /* ManualSwitch: '<S372>/Manual Switch' incorporates:
   *  Constant: '<S372>/Constant1'
   *  Constant: '<S377>/Constant'
   *  Constant: '<S385>/Constant'
   *  Constant: '<S385>/Constant1'
   *  Constant: '<S385>/Constant10'
   *  Constant: '<S385>/Constant11'
   *  Constant: '<S385>/Constant12'
   *  Constant: '<S385>/Constant2'
   *  Constant: '<S385>/Constant3'
   *  Constant: '<S385>/Constant4'
   *  Constant: '<S385>/Constant5'
   *  Constant: '<S385>/Constant6'
   *  Constant: '<S385>/Constant8'
   *  Product: '<S372>/Divide'
   *  Product: '<S372>/Divide5'
   *  Product: '<S385>/Divide1'
   *  Product: '<S385>/Divide3'
   *  Product: '<S385>/Divide4'
   *  Product: '<S385>/Divide5'
   *  Product: '<S385>/Divide6'
   *  Sum: '<S385>/Add'
   *  Sum: '<S385>/Add1'
   *  Sum: '<S385>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_mh == 1) {
    locvar_ManualSwitch_c0 = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
      ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
      + ANN_EKF_NMPC_2_P.Cyda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
      ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
      (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_c0 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S372>/Manual Switch' */

  /* Sum: '<S372>/Add1' incorporates:
   *  Constant: '<S372>/Constant'
   *  Product: '<S372>/Divide2'
   *  Product: '<S372>/Divide3'
   *  Product: '<S372>/Divide4'
   *  Trigonometry: '<S372>/Trigonometric Function'
   *  Trigonometry: '<S372>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_dh = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
                        locvar_ManualSwitch_e -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * locvar_Ayb_k)
                       + sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                       (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                       ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_c0;

  /* Product: '<S371>/Divide4' */
  locvar_Divide4_c1v = locvar_ManualSwitch_cx * locvar_Divide4_dh;

  /* ManualSwitch: '<S374>/Manual Switch' incorporates:
   *  Constant: '<S374>/Constant1'
   *  Constant: '<S377>/Constant'
   *  Product: '<S374>/Divide'
   *  Product: '<S374>/Divide5'
   *  Product: '<S394>/Divide1'
   *  Product: '<S394>/Divide6'
   *  Sum: '<S394>/Add2'
   *  Trigonometry: '<S394>/Trigonometric Function4'
   *  Trigonometry: '<S394>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_nc1 == 1) {
    locvar_ManualSwitch_d = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_d = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S374>/Manual Switch' */

  /* Sum: '<S374>/Add1' incorporates:
   *  Constant: '<S374>/Constant'
   *  Product: '<S374>/Divide2'
   *  Product: '<S374>/Divide3'
   *  Product: '<S374>/Divide4'
   *  Trigonometry: '<S374>/Trigonometric Function'
   *  Trigonometry: '<S374>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((locvar_Add2_ai * locvar_Ayb_k -
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
                     locvar_ManualSwitch_cx) + cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_d;

  /* Product: '<S371>/Divide5' */
  locvar_Add_kq = locvar_ManualSwitch_e * locvar_Add2_o3;

  /* Product: '<S375>/Divide' incorporates:
   *  Math: '<S375>/Math Function'
   *  Math: '<S375>/Math Function1'
   *  Product: '<S375>/Divide3'
   *  Product: '<S375>/Divide4'
   *  Sum: '<S375>/Add'
   *  Sum: '<S375>/Add1'
   */
  locvar_Divide_k2 = (locvar_Ayb_k * locvar_Add2_o3 - locvar_ManualSwitch_e *
                      locvar_Azb_h) / (locvar_Ayb_k * locvar_Ayb_k +
    locvar_ManualSwitch_e * locvar_ManualSwitch_e);

  /* Product: '<S376>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_Divide4_dh;

  /* Product: '<S376>/Divide4' incorporates:
   *  Product: '<S376>/Divide1'
   *  Product: '<S376>/Divide2'
   *  Product: '<S376>/Divide5'
   *  Product: '<S376>/Divide6'
   *  Sum: '<S376>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain_ar = ((locvar_Ayb_k * locvar_Azb_h + locvar_ManualSwitch_cx *
                     locvar_Divide4_dh) + locvar_ManualSwitch_e * locvar_Add2_o3)
    / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_ManualSwitch_cx;

  /* Sum: '<S405>/Add' incorporates:
   *  Constant: '<S405>/Ixx1'
   *  Constant: '<S405>/Ixz1'
   *  Constant: '<S405>/Izz1'
   *  Math: '<S405>/Math Function'
   *  Product: '<S405>/Divide1'
   */
  locvar_Divide4_dh = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S397>/Divide4' incorporates:
   *  Constant: '<S397>/Ixx'
   *  Constant: '<S397>/Ixz'
   *  Constant: '<S397>/Iyy'
   *  Constant: '<S397>/Izz'
   *  Product: '<S397>/Divide3'
   *  Sum: '<S397>/Add'
   */
  locvar_Add2_o3 = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
                    ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB /
    locvar_Divide4_dh;

  /* Sum: '<S387>/Add' incorporates:
   *  Constant: '<S387>/Constant10'
   *  Constant: '<S387>/Constant11'
   *  Constant: '<S387>/Constant12'
   *  Constant: '<S387>/Constant13'
   *  Constant: '<S387>/Constant14'
   *  Constant: '<S387>/Constant15'
   *  Constant: '<S387>/Constant5'
   *  Constant: '<S387>/Constant6'
   *  Constant: '<S387>/Constant7'
   *  Constant: '<S387>/Constant8'
   *  Constant: '<S387>/Constant9'
   *  Product: '<S387>/Divide3'
   *  Product: '<S387>/Divide4'
   *  Product: '<S387>/Divide5'
   *  Product: '<S387>/Divide6'
   *  Product: '<S387>/Divide7'
   *  Sum: '<S387>/Add1'
   *  Sum: '<S387>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction2_ly = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]
    - ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp * (ANN_EKF_NMPC_2_P.b / 2.0)
    / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Clb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Clr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cldr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S391>/Add' incorporates:
   *  Constant: '<S391>/Constant'
   *  Constant: '<S391>/Constant10'
   *  Constant: '<S391>/Constant11'
   *  Constant: '<S391>/Constant12'
   *  Constant: '<S391>/Constant13'
   *  Constant: '<S391>/Constant14'
   *  Constant: '<S391>/Constant15'
   *  Constant: '<S391>/Constant5'
   *  Constant: '<S391>/Constant6'
   *  Constant: '<S391>/Constant8'
   *  Constant: '<S391>/Constant9'
   *  Product: '<S391>/Divide3'
   *  Product: '<S391>/Divide4'
   *  Product: '<S391>/Divide5'
   *  Product: '<S391>/Divide6'
   *  Product: '<S391>/Divide7'
   *  Sum: '<S391>/Add1'
   *  Sum: '<S391>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction4_ef = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]
    - ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp * (ANN_EKF_NMPC_2_P.b / 2.0)
    / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cnb *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] - ANN_EKF_NMPC_2_P.Rtrim) *
    ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim)
    + ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S386>/Add' incorporates:
   *  Product: '<S386>/Divide3'
   *  Product: '<S386>/Divide5'
   *  Trigonometry: '<S386>/Trigonometric Function'
   *  Trigonometry: '<S386>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction5_h0 = locvar_TrigonometricFunction2_ly * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_TrigonometricFunction4_ef;

  /* Product: '<S399>/Divide4' incorporates:
   *  Constant: '<S399>/Ixz'
   */
  locvar_TrigonometricFunction3_p = ANN_EKF_NMPC_2_P.IxzB / locvar_Divide4_dh;

  /* Sum: '<S390>/Add2' incorporates:
   *  Product: '<S390>/Divide1'
   *  Product: '<S390>/Divide6'
   *  Trigonometry: '<S390>/Trigonometric Function4'
   *  Trigonometry: '<S390>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction4_ef = locvar_TrigonometricFunction2_ly * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) + cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_TrigonometricFunction4_ef;

  /* Saturate: '<S361>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Product: '<S151>/Divide9' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S361>/Gain'
   *  Gain: '<S361>/Gain1'
   *  Saturate: '<S361>/Throttle Limiter'
   *  Sum: '<S151>/Sum10'
   *  Sum: '<S361>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Reshape1[0] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
                        locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S361>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Product: '<S151>/Divide9' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S361>/Gain2'
   *  Gain: '<S361>/Gain3'
   *  Saturate: '<S361>/Elevator Limiter'
   *  Sum: '<S151>/Sum10'
   *  Sum: '<S361>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Reshape1[1] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
                        locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S361>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Product: '<S151>/Divide9' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S361>/Gain4'
   *  Gain: '<S361>/Gain5'
   *  Saturate: '<S361>/Aileron Limiter'
   *  Sum: '<S151>/Sum10'
   *  Sum: '<S361>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Reshape1[2] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
                        locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Saturate: '<S361>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Product: '<S151>/Divide9' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S361>/Gain6'
   *  Gain: '<S361>/Gain7'
   *  Math: '<S376>/Math Function'
   *  Math: '<S376>/Math Function1'
   *  Product: '<S371>/Divide'
   *  Product: '<S371>/Divide3'
   *  Product: '<S376>/Divide'
   *  Saturate: '<S361>/Rudder Limiter'
   *  Sum: '<S151>/Sum10'
   *  Sum: '<S361>/Add3'
   *  Sum: '<S371>/Add'
   *  Sum: '<S376>/Add'
   *  Sum: '<S376>/Add1'
   *  Trigonometry: '<S376>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Reshape1[3] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
                        locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[4] = (((locvar_Ayb_k * locvar_Azb_h + locvar_Divide4_c1v) +
    locvar_Add_kq) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] - locvar_Divide_ad) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[5] = (locvar_Divide_k2 - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[6] = ((locvar_Add2_db - locvar_Gain_ar) / (locvar_Ayb_k *
    locvar_Ayb_k + locvar_ManualSwitch_e * locvar_ManualSwitch_e) * cos
                        (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) -
                        locvar_Divide_je) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Trigonometry: '<S379>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S379>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_e3) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_e3;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_p) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_p;
    }
  }

  /* Product: '<S151>/Divide9' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S364>/Constant1'
   *  Constant: '<S364>/Constant2'
   *  Constant: '<S366>/Constant1'
   *  Constant: '<S366>/Constant2'
   *  Constant: '<S367>/Constant1'
   *  Constant: '<S367>/Constant2'
   *  Constant: '<S380>/Constant'
   *  Constant: '<S381>/Constant'
   *  Constant: '<S389>/Constant'
   *  Constant: '<S389>/Constant1'
   *  Constant: '<S389>/Constant11'
   *  Constant: '<S389>/Constant12'
   *  Constant: '<S389>/Constant13'
   *  Constant: '<S389>/Constant14'
   *  Constant: '<S389>/Constant2'
   *  Constant: '<S389>/Constant3'
   *  Constant: '<S389>/Constant4'
   *  Constant: '<S389>/Constant5'
   *  Constant: '<S389>/Constant6'
   *  Constant: '<S389>/Constant7'
   *  Constant: '<S389>/Constant8'
   *  Constant: '<S389>/Constant9'
   *  Constant: '<S396>/Ixz'
   *  Constant: '<S396>/Iyy'
   *  Constant: '<S396>/Izz'
   *  Constant: '<S398>/Izz'
   *  Constant: '<S400>/Ixx'
   *  Constant: '<S400>/Iyy'
   *  Constant: '<S400>/Izz'
   *  Constant: '<S401>/Ixz'
   *  Constant: '<S401>/Iyy'
   *  Constant: '<S402>/Ixz'
   *  Constant: '<S402>/Iyy'
   *  Constant: '<S403>/Ixx'
   *  Constant: '<S403>/Ixx1'
   *  Constant: '<S403>/Ixz'
   *  Constant: '<S403>/Iyy'
   *  Constant: '<S404>/Ixx'
   *  Gain: '<S389>/Gain1'
   *  Gain: '<S389>/Gain2'
   *  Math: '<S366>/Math Function'
   *  Math: '<S366>/Math Function1'
   *  Math: '<S396>/Math Function'
   *  Math: '<S403>/Math Function'
   *  Product: '<S364>/Divide'
   *  Product: '<S364>/Divide1'
   *  Product: '<S364>/Divide2'
   *  Product: '<S364>/Divide3'
   *  Product: '<S364>/Divide4'
   *  Product: '<S364>/Divide5'
   *  Product: '<S364>/Divide6'
   *  Product: '<S366>/Divide'
   *  Product: '<S366>/Divide2'
   *  Product: '<S366>/Divide3'
   *  Product: '<S366>/Divide5'
   *  Product: '<S366>/Divide6'
   *  Product: '<S367>/Divide'
   *  Product: '<S367>/Divide1'
   *  Product: '<S367>/Divide2'
   *  Product: '<S367>/Divide3'
   *  Product: '<S367>/Divide4'
   *  Product: '<S367>/Divide5'
   *  Product: '<S367>/Divide6'
   *  Product: '<S379>/Divide1'
   *  Product: '<S379>/Divide2'
   *  Product: '<S379>/Divide4'
   *  Product: '<S382>/Divide2'
   *  Product: '<S382>/Divide4'
   *  Product: '<S389>/Divide1'
   *  Product: '<S389>/Divide2'
   *  Product: '<S389>/Divide3'
   *  Product: '<S389>/Divide4'
   *  Product: '<S389>/Divide5'
   *  Product: '<S389>/Divide6'
   *  Product: '<S396>/Divide3'
   *  Product: '<S396>/Divide4'
   *  Product: '<S398>/Divide4'
   *  Product: '<S400>/Divide4'
   *  Product: '<S401>/Divide4'
   *  Product: '<S402>/Divide4'
   *  Product: '<S403>/Divide3'
   *  Product: '<S403>/Divide4'
   *  Product: '<S404>/Divide4'
   *  Saturate: '<S379>/Saturation'
   *  Sum: '<S151>/Sum10'
   *  Sum: '<S364>/Add'
   *  Sum: '<S364>/Add1'
   *  Sum: '<S364>/Add2'
   *  Sum: '<S366>/Add1'
   *  Sum: '<S366>/Add3'
   *  Sum: '<S367>/Add'
   *  Sum: '<S367>/Add1'
   *  Sum: '<S367>/Add2'
   *  Sum: '<S379>/Add'
   *  Sum: '<S379>/Add1'
   *  Sum: '<S382>/Add'
   *  Sum: '<S389>/Add'
   *  Sum: '<S389>/Add1'
   *  Sum: '<S389>/Add2'
   *  Sum: '<S389>/Add3'
   *  Sum: '<S396>/Add'
   *  Sum: '<S396>/Add1'
   *  Sum: '<S400>/Add'
   *  Sum: '<S403>/Add'
   *  Sum: '<S403>/Add1'
   *  Trigonometry: '<S379>/Trigonometric Function1'
   *  Trigonometry: '<S379>/Trigonometric Function2'
   *  Trigonometry: '<S382>/Trigonometric Function1'
   *  Trigonometry: '<S382>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S375>/Unit Delay'
   */
  locvar_Reshape1[7] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * locvar_Add2_ai) *
    locvar_Delay100dt + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md)
    / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[8] = ((locvar_Add2_ai * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[9] = (((((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB) /
    locvar_Divide4_dh * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_Add2_o3
    * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) * locvar_Add2_ai +
    (ANN_EKF_NMPC_2_P.IzzB / locvar_Divide4_dh *
     locvar_TrigonometricFunction5_h0 + locvar_TrigonometricFunction3_p *
     locvar_TrigonometricFunction4_ef) * (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S
    * ANN_EKF_NMPC_2_P.b)) - locvar_Add2_ga) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[10] = ((((((((locvar_Add2_ai - ANN_EKF_NMPC_2_P.Qtrim) *
    ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar / 2.0) /
    ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_o *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
    ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim * (locvar_Ayb_k -
    ANN_EKF_NMPC_2_P.Utrim)) + ANN_EKF_NMPC_2_P.Cmde *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
    (locvar_Ayb_k - ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
    ANN_EKF_NMPC_2_P.Gain2_Gain_ld * ANN_EKF_NMPC_2_P.Gain1_Gain_ob) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_aq / ANN_EKF_NMPC_2_P.IyyB) * (locvar_Divide4_ch
    * ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.Cbar) + ((ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxxB) / ANN_EKF_NMPC_2_P.IyyB *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB))) - locvar_Add1_ir) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[11] = (((((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB) /
    locvar_Divide4_dh * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_Add2_o3 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * locvar_Add2_ai +
    (ANN_EKF_NMPC_2_P.IxxB / locvar_Divide4_dh *
     locvar_TrigonometricFunction4_ef + locvar_TrigonometricFunction3_p *
     locvar_TrigonometricFunction5_h0) * (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S
    * ANN_EKF_NMPC_2_P.b)) - locvar_Divide_j0) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[12] = (ANN_EKF_NMPC_2_P.Constant_Value_p -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e;
  locvar_Reshape1[13] = (ANN_EKF_NMPC_2_P.Constant_Value_jz -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e;

  /* Product: '<S413>/Divide2' incorporates:
   *  Trigonometry: '<S413>/Trigonometric Function'
   *  Trigonometry: '<S413>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide2_op = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Sum: '<S160>/Add' incorporates:
   *  Constant: '<S151>/delta'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_c1v = ANN_EKF_NMPC_2_P.delta_Value_e +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];

  /* Product: '<S415>/Divide2' incorporates:
   *  Trigonometry: '<S415>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Axb_e = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S418>/Divide2' incorporates:
   *  Trigonometry: '<S418>/Trigonometric Function'
   *  Trigonometry: '<S418>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction_m2 = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S410>/Divide4' incorporates:
   *  Constant: '<S410>/Constant'
   *  Constant: '<S410>/Constant1'
   *  Math: '<S410>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ch = ANN_EKF_NMPC_2_P.Constant_Value_ij *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S429>/Add' incorporates:
   *  Constant: '<S429>/Constant'
   *  Constant: '<S429>/Constant1'
   *  Constant: '<S429>/Constant10'
   *  Constant: '<S429>/Constant11'
   *  Constant: '<S429>/Constant12'
   *  Constant: '<S429>/Constant13'
   *  Constant: '<S429>/Constant14'
   *  Constant: '<S429>/Constant15'
   *  Constant: '<S429>/Constant2'
   *  Constant: '<S429>/Constant3'
   *  Constant: '<S429>/Constant4'
   *  Constant: '<S429>/Constant5'
   *  Constant: '<S429>/Constant6'
   *  Constant: '<S429>/Constant7'
   *  Constant: '<S429>/Constant8'
   *  Constant: '<S429>/Constant9'
   *  Gain: '<S429>/Gain1'
   *  Gain: '<S429>/Gain2'
   *  Gain: '<S429>/Gain3'
   *  Product: '<S429>/Divide1'
   *  Product: '<S429>/Divide2'
   *  Product: '<S429>/Divide3'
   *  Product: '<S429>/Divide4'
   *  Product: '<S429>/Divide5'
   *  Product: '<S429>/Divide6'
   *  Product: '<S429>/Divide7'
   *  Sum: '<S429>/Add1'
   *  Sum: '<S429>/Add2'
   *  Sum: '<S429>/Add3'
   *  Sum: '<S429>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S420>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_or *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_Divide2_op - ANN_EKF_NMPC_2_P.Utrim)) +
                    ANN_EKF_NMPC_2_P.CLde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim * (locvar_Divide2_op -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                   ANN_EKF_NMPC_2_P.Gain2_Gain_oq *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_pm) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_h4;

  /* ManualSwitch: '<S428>/Manual Switch' incorporates:
   *  Constant: '<S428>/AR'
   *  Constant: '<S428>/Constant15'
   *  Constant: '<S428>/Constant16'
   *  Constant: '<S428>/Constant17'
   *  Constant: '<S428>/Constant18'
   *  Constant: '<S428>/e'
   *  Math: '<S428>/Math Function'
   *  Product: '<S428>/Divide8'
   *  Product: '<S428>/Divide9'
   *  Sum: '<S428>/Add5'
   *  Sum: '<S428>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_fv == 1) {
    locvar_ManualSwitch_dl = ANN_EKF_NMPC_2_P.CDa *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_ManualSwitch_dl = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_li / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_b +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S428>/Manual Switch' */

  /* Sum: '<S428>/Add' incorporates:
   *  Constant: '<S428>/Constant1'
   *  Constant: '<S428>/Constant10'
   *  Constant: '<S428>/Constant11'
   *  Constant: '<S428>/Constant12'
   *  Constant: '<S428>/Constant13'
   *  Constant: '<S428>/Constant14'
   *  Constant: '<S428>/Constant2'
   *  Constant: '<S428>/Constant3'
   *  Constant: '<S428>/Constant4'
   *  Constant: '<S428>/Constant6'
   *  Constant: '<S428>/Constant7'
   *  Constant: '<S428>/Constant8'
   *  Constant: '<S428>/Constant9'
   *  Gain: '<S428>/Gain1'
   *  Gain: '<S428>/Gain2'
   *  Gain: '<S428>/Gain3'
   *  Product: '<S428>/Divide1'
   *  Product: '<S428>/Divide2'
   *  Product: '<S428>/Divide3'
   *  Product: '<S428>/Divide5'
   *  Product: '<S428>/Divide6'
   *  Product: '<S428>/Divide7'
   *  Sum: '<S428>/Add1'
   *  Sum: '<S428>/Add2'
   *  Sum: '<S428>/Add3'
   *  Sum: '<S428>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S420>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_ManualSwitch_dl) +
                       ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_or *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_Divide2_op - ANN_EKF_NMPC_2_P.Utrim)) +
                     ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_Divide2_op -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_ma *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_jy) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_k;

  /* ManualSwitch: '<S414>/Manual Switch' incorporates:
   *  Constant: '<S414>/Constant1'
   *  Constant: '<S422>/Constant'
   *  Constant: '<S440>/Constant'
   *  Constant: '<S440>/Constant1'
   *  Constant: '<S440>/Constant2'
   *  Math: '<S440>/Math Function'
   *  Product: '<S414>/Divide'
   *  Product: '<S414>/Divide5'
   *  Product: '<S437>/Divide3'
   *  Product: '<S437>/Divide5'
   *  Product: '<S440>/Divide1'
   *  Product: '<S440>/Divide2'
   *  Sum: '<S414>/Add'
   *  Sum: '<S437>/Add'
   *  Sum: '<S440>/Add'
   *  Trigonometry: '<S437>/Trigonometric Function'
   *  Trigonometry: '<S437>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_ko == 1) {
    /* Gain: '<S440>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_n1 *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_ManualSwitch_dl = (((locvar_Gain_ar * locvar_Gain_ar *
      ANN_EKF_NMPC_2_P.xT2 + ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
      ANN_EKF_NMPC_2_P.xT0) + (sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) *
      locvar_Add_kq - locvar_Add2_db * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]))
      * (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_dl = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S414>/Manual Switch' */

  /* Sum: '<S414>/Add1' incorporates:
   *  Constant: '<S414>/Constant'
   *  Product: '<S414>/Divide2'
   *  Product: '<S414>/Divide3'
   *  Product: '<S414>/Divide4'
   *  Trigonometry: '<S414>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Ayb_k = ((locvar_Divide4_c1v * locvar_Axb_e -
                   ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
                   locvar_TrigonometricFunction_m2) - sin
                  (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g)
    + locvar_ManualSwitch_dl;

  /* ManualSwitch: '<S417>/Manual Switch' incorporates:
   *  Constant: '<S417>/Constant1'
   *  Constant: '<S422>/Constant'
   *  Constant: '<S430>/Constant'
   *  Constant: '<S430>/Constant1'
   *  Constant: '<S430>/Constant10'
   *  Constant: '<S430>/Constant11'
   *  Constant: '<S430>/Constant12'
   *  Constant: '<S430>/Constant2'
   *  Constant: '<S430>/Constant3'
   *  Constant: '<S430>/Constant4'
   *  Constant: '<S430>/Constant5'
   *  Constant: '<S430>/Constant6'
   *  Constant: '<S430>/Constant8'
   *  Product: '<S417>/Divide'
   *  Product: '<S417>/Divide5'
   *  Product: '<S430>/Divide1'
   *  Product: '<S430>/Divide3'
   *  Product: '<S430>/Divide4'
   *  Product: '<S430>/Divide5'
   *  Product: '<S430>/Divide6'
   *  Sum: '<S430>/Add'
   *  Sum: '<S430>/Add1'
   *  Sum: '<S430>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_gq == 1) {
    locvar_ManualSwitch_cx = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
      ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim + ANN_EKF_NMPC_2_P.Cyb *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) + (locvar_Divide4_c1v -
      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Cyr * (ANN_EKF_NMPC_2_P.b / 2.0)
      / ANN_EKF_NMPC_2_P.Utrim) + ANN_EKF_NMPC_2_P.Cyda *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) + ANN_EKF_NMPC_2_P.Cydr *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) * (locvar_Divide4_ch *
      ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight / ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_cx = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S417>/Manual Switch' */

  /* Sum: '<S417>/Add1' incorporates:
   *  Constant: '<S417>/Constant'
   *  Product: '<S417>/Divide2'
   *  Product: '<S417>/Divide3'
   *  Product: '<S417>/Divide4'
   *  Trigonometry: '<S417>/Trigonometric Function'
   *  Trigonometry: '<S417>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_ai = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
                     locvar_TrigonometricFunction_m2 - locvar_Divide4_c1v *
                     locvar_Divide2_op) + sin
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                    ANN_EKF_NMPC_2_P.g) + locvar_ManualSwitch_cx;

  /* ManualSwitch: '<S419>/Manual Switch' incorporates:
   *  Constant: '<S419>/Constant1'
   *  Constant: '<S422>/Constant'
   *  Product: '<S419>/Divide'
   *  Product: '<S419>/Divide5'
   *  Product: '<S439>/Divide1'
   *  Product: '<S439>/Divide6'
   *  Sum: '<S439>/Add2'
   *  Trigonometry: '<S439>/Trigonometric Function4'
   *  Trigonometry: '<S439>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_mr == 1) {
    locvar_ManualSwitch_e = ((0.0 - locvar_Add2_db * sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_ManualSwitch_e = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S419>/Manual Switch' */

  /* Sum: '<S419>/Add1' incorporates:
   *  Constant: '<S419>/Constant'
   *  Product: '<S419>/Divide2'
   *  Product: '<S419>/Divide3'
   *  Product: '<S419>/Divide4'
   *  Trigonometry: '<S419>/Trigonometric Function'
   *  Trigonometry: '<S419>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Azb_h = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * locvar_Divide2_op -
                   ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] * locvar_Axb_e) + cos
                  (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                  (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) * ANN_EKF_NMPC_2_P.g)
    + locvar_ManualSwitch_e;

  /* Product: '<S416>/Divide' incorporates:
   *  Product: '<S416>/Divide3'
   *  Product: '<S416>/Divide4'
   *  Product: '<S416>/Divide5'
   *  Sum: '<S416>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_dh = ((locvar_Divide2_op * locvar_Ayb_k + locvar_Axb_e *
                        locvar_Add2_ai) + locvar_TrigonometricFunction_m2 *
                       locvar_Azb_h) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4];

  /* Product: '<S420>/Divide' incorporates:
   *  Math: '<S420>/Math Function'
   *  Math: '<S420>/Math Function1'
   *  Product: '<S420>/Divide3'
   *  Product: '<S420>/Divide4'
   *  Sum: '<S420>/Add'
   *  Sum: '<S420>/Add1'
   */
  locvar_Divide_jpd = (locvar_Divide2_op * locvar_Azb_h -
                       locvar_TrigonometricFunction_m2 * locvar_Ayb_k) /
    (locvar_Divide2_op * locvar_Divide2_op + locvar_TrigonometricFunction_m2 *
     locvar_TrigonometricFunction_m2);

  /* Product: '<S421>/Divide' incorporates:
   *  Math: '<S421>/Math Function'
   *  Math: '<S421>/Math Function1'
   *  Product: '<S421>/Divide1'
   *  Product: '<S421>/Divide2'
   *  Product: '<S421>/Divide3'
   *  Product: '<S421>/Divide4'
   *  Product: '<S421>/Divide5'
   *  Product: '<S421>/Divide6'
   *  Sum: '<S421>/Add'
   *  Sum: '<S421>/Add1'
   *  Sum: '<S421>/Add2'
   *  Trigonometry: '<S421>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Axb_e = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_Add2_ai -
                  ((locvar_Divide2_op * locvar_Ayb_k + locvar_Axb_e *
                    locvar_Add2_ai) + locvar_TrigonometricFunction_m2 *
                   locvar_Azb_h) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
                  locvar_Axb_e) / (locvar_Divide2_op * locvar_Divide2_op +
    locvar_TrigonometricFunction_m2 * locvar_TrigonometricFunction_m2) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Sum: '<S450>/Add' incorporates:
   *  Constant: '<S450>/Ixx1'
   *  Constant: '<S450>/Ixz1'
   *  Constant: '<S450>/Izz1'
   *  Math: '<S450>/Math Function'
   *  Product: '<S450>/Divide1'
   */
  locvar_Add2_ai = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S442>/Divide4' incorporates:
   *  Constant: '<S442>/Ixx'
   *  Constant: '<S442>/Ixz'
   *  Constant: '<S442>/Iyy'
   *  Constant: '<S442>/Izz'
   *  Product: '<S442>/Divide3'
   *  Sum: '<S442>/Add'
   */
  locvar_Azb_h = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
                  ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB /
    locvar_Add2_ai;

  /* Sum: '<S432>/Add' incorporates:
   *  Constant: '<S432>/Constant10'
   *  Constant: '<S432>/Constant11'
   *  Constant: '<S432>/Constant12'
   *  Constant: '<S432>/Constant13'
   *  Constant: '<S432>/Constant14'
   *  Constant: '<S432>/Constant15'
   *  Constant: '<S432>/Constant5'
   *  Constant: '<S432>/Constant6'
   *  Constant: '<S432>/Constant7'
   *  Constant: '<S432>/Constant8'
   *  Constant: '<S432>/Constant9'
   *  Product: '<S432>/Divide3'
   *  Product: '<S432>/Divide4'
   *  Product: '<S432>/Divide5'
   *  Product: '<S432>/Divide6'
   *  Product: '<S432>/Divide7'
   *  Sum: '<S432>/Add1'
   *  Sum: '<S432>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (locvar_Divide4_c1v - ANN_EKF_NMPC_2_P.Rtrim) *
                     ANN_EKF_NMPC_2_P.Clr * (ANN_EKF_NMPC_2_P.b / 2.0) /
                     ANN_EKF_NMPC_2_P.Utrim) + ANN_EKF_NMPC_2_P.Clda *
                    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cldr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S436>/Add' incorporates:
   *  Constant: '<S436>/Constant'
   *  Constant: '<S436>/Constant10'
   *  Constant: '<S436>/Constant11'
   *  Constant: '<S436>/Constant12'
   *  Constant: '<S436>/Constant13'
   *  Constant: '<S436>/Constant14'
   *  Constant: '<S436>/Constant15'
   *  Constant: '<S436>/Constant5'
   *  Constant: '<S436>/Constant6'
   *  Constant: '<S436>/Constant8'
   *  Constant: '<S436>/Constant9'
   *  Product: '<S436>/Divide3'
   *  Product: '<S436>/Divide4'
   *  Product: '<S436>/Divide5'
   *  Product: '<S436>/Divide6'
   *  Product: '<S436>/Divide7'
   *  Sum: '<S436>/Add1'
   *  Sum: '<S436>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Cnb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (locvar_Divide4_c1v - ANN_EKF_NMPC_2_P.Rtrim) *
                     ANN_EKF_NMPC_2_P.Cnr * (ANN_EKF_NMPC_2_P.b / 2.0) /
                     ANN_EKF_NMPC_2_P.Utrim) + ANN_EKF_NMPC_2_P.Cnda *
                    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
    ANN_EKF_NMPC_2_P.Cndr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S431>/Add' incorporates:
   *  Product: '<S431>/Divide3'
   *  Product: '<S431>/Divide5'
   *  Trigonometry: '<S431>/Trigonometric Function'
   *  Trigonometry: '<S431>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide2_ic = locvar_Add2_o3 * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])
    - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add2_db;

  /* Product: '<S444>/Divide4' incorporates:
   *  Constant: '<S444>/Ixz'
   */
  locvar_Divide2_em = ANN_EKF_NMPC_2_P.IxzB / locvar_Add2_ai;

  /* Sum: '<S435>/Add2' incorporates:
   *  Product: '<S435>/Divide1'
   *  Product: '<S435>/Divide6'
   *  Trigonometry: '<S435>/Trigonometric Function4'
   *  Trigonometry: '<S435>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_o3 = locvar_Add2_o3 * sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])
    + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add2_db;

  /* Sum: '<S409>/Add2' incorporates:
   *  Constant: '<S409>/Constant1'
   *  Constant: '<S409>/Constant2'
   *  Constant: '<S441>/Ixz'
   *  Constant: '<S441>/Iyy'
   *  Constant: '<S441>/Izz'
   *  Constant: '<S443>/Izz'
   *  Math: '<S441>/Math Function'
   *  Product: '<S409>/Divide'
   *  Product: '<S409>/Divide1'
   *  Product: '<S409>/Divide2'
   *  Product: '<S409>/Divide3'
   *  Product: '<S409>/Divide4'
   *  Product: '<S409>/Divide5'
   *  Product: '<S409>/Divide6'
   *  Product: '<S441>/Divide3'
   *  Product: '<S441>/Divide4'
   *  Product: '<S443>/Divide4'
   *  Sum: '<S409>/Add'
   *  Sum: '<S409>/Add1'
   *  Sum: '<S441>/Add'
   *  Sum: '<S441>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = (((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
                     ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB *
                     ANN_EKF_NMPC_2_P.IxzB) / locvar_Add2_ai *
                    locvar_Divide4_c1v + locvar_Azb_h *
                    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IzzB /
    locvar_Add2_ai * locvar_Divide2_ic + locvar_Divide2_em * locvar_Add2_o3) *
    (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.b);

  /* Sum: '<S412>/Add2' incorporates:
   *  Constant: '<S412>/Constant1'
   *  Constant: '<S412>/Constant2'
   *  Constant: '<S448>/Ixx'
   *  Constant: '<S448>/Ixx1'
   *  Constant: '<S448>/Ixz'
   *  Constant: '<S448>/Iyy'
   *  Constant: '<S449>/Ixx'
   *  Math: '<S448>/Math Function'
   *  Product: '<S412>/Divide'
   *  Product: '<S412>/Divide1'
   *  Product: '<S412>/Divide2'
   *  Product: '<S412>/Divide3'
   *  Product: '<S412>/Divide4'
   *  Product: '<S412>/Divide5'
   *  Product: '<S412>/Divide6'
   *  Product: '<S448>/Divide3'
   *  Product: '<S448>/Divide4'
   *  Product: '<S449>/Divide4'
   *  Sum: '<S412>/Add'
   *  Sum: '<S412>/Add1'
   *  Sum: '<S448>/Add'
   *  Sum: '<S448>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide2_em = (((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
                        ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB *
                        ANN_EKF_NMPC_2_P.IxzB) / locvar_Add2_ai *
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_Azb_h *
                       locvar_Divide4_c1v) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IxxB /
    locvar_Add2_ai * locvar_Add2_o3 + locvar_Divide2_em * locvar_Divide2_ic) *
    (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.b);

  /* Saturate: '<S496>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S496>/Gain'
   *  Gain: '<S496>/Gain1'
   *  Product: '<S151>/Divide'
   *  Saturate: '<S496>/Throttle Limiter'
   *  Sum: '<S151>/Sum'
   *  Sum: '<S496>/Add'
   */
  locvar_Gain4_dz[0] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * locvar_Add_nwv) - locvar_Add2_fi) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S496>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S496>/Gain2'
   *  Gain: '<S496>/Gain3'
   *  Product: '<S151>/Divide'
   *  Saturate: '<S496>/Elevator Limiter'
   *  Sum: '<S151>/Sum'
   *  Sum: '<S496>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[1] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
                        locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S496>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S496>/Gain4'
   *  Gain: '<S496>/Gain5'
   *  Product: '<S151>/Divide'
   *  Saturate: '<S496>/Aileron Limiter'
   *  Sum: '<S151>/Sum'
   *  Sum: '<S496>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[2] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
                        locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S496>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S496>/Gain6'
   *  Gain: '<S496>/Gain7'
   *  Product: '<S151>/Divide'
   *  Product: '<S506>/Divide'
   *  Product: '<S511>/Divide'
   *  Saturate: '<S496>/Rudder Limiter'
   *  Sum: '<S151>/Sum'
   *  Sum: '<S496>/Add3'
   *  Sum: '<S506>/Add'
   *  Sum: '<S511>/Add'
   *  Sum: '<S511>/Add1'
   *  Trigonometry: '<S511>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[3] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
                        locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[4] = (((locvar_Divide3_bc + locvar_Divide4_mgn) +
    locvar_Divide5_ni) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[5] = (locvar_Divide_o - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[6] = ((locvar_Divide3_hfk - locvar_Divide4_ng) /
                        (locvar_MathFunction_e + locvar_MathFunction1_bt) * cos
                        (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) -
                        locvar_Divide_je) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;

  /* Trigonometry: '<S514>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S514>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_g) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_g;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_e) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_e;
    }
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S499>/Constant1'
   *  Constant: '<S499>/Constant2'
   *  Constant: '<S501>/Constant1'
   *  Constant: '<S501>/Constant2'
   *  Constant: '<S502>/Constant1'
   *  Constant: '<S502>/Constant2'
   *  Constant: '<S515>/Constant'
   *  Constant: '<S516>/Constant'
   *  Constant: '<S535>/Ixx'
   *  Constant: '<S535>/Iyy'
   *  Constant: '<S535>/Izz'
   *  Constant: '<S536>/Ixz'
   *  Constant: '<S536>/Iyy'
   *  Math: '<S501>/Math Function'
   *  Math: '<S501>/Math Function1'
   *  Product: '<S151>/Divide'
   *  Product: '<S499>/Divide1'
   *  Product: '<S499>/Divide5'
   *  Product: '<S499>/Divide6'
   *  Product: '<S501>/Divide2'
   *  Product: '<S501>/Divide3'
   *  Product: '<S501>/Divide5'
   *  Product: '<S501>/Divide6'
   *  Product: '<S502>/Divide1'
   *  Product: '<S502>/Divide5'
   *  Product: '<S502>/Divide6'
   *  Product: '<S514>/Divide1'
   *  Product: '<S514>/Divide2'
   *  Product: '<S514>/Divide4'
   *  Product: '<S517>/Divide2'
   *  Product: '<S517>/Divide4'
   *  Product: '<S535>/Divide4'
   *  Product: '<S536>/Divide4'
   *  Reshape: '<S151>/Reshape'
   *  Saturate: '<S514>/Saturation'
   *  Sum: '<S151>/Sum'
   *  Sum: '<S499>/Add2'
   *  Sum: '<S501>/Add1'
   *  Sum: '<S501>/Add3'
   *  Sum: '<S502>/Add2'
   *  Sum: '<S514>/Add'
   *  Sum: '<S514>/Add1'
   *  Sum: '<S517>/Add'
   *  Sum: '<S535>/Add'
   *  Trigonometry: '<S514>/Trigonometric Function1'
   *  Trigonometry: '<S514>/Trigonometric Function2'
   *  Trigonometry: '<S517>/Trigonometric Function1'
   *  Trigonometry: '<S517>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[7] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[8] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[9] = ((locvar_Divide4_kga * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_mtb + locvar_Add1_cl *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[10] = ((((ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxxB) /
    ANN_EKF_NMPC_2_P.IyyB * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB)) + locvar_Divide4_kga * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.Cbar * locvar_Divide_em) - locvar_Add1_ir) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[11] = ((locvar_Divide4_kga * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_oq1 + locvar_Add1_j2 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[12] = (ANN_EKF_NMPC_2_P.Constant_Value_o -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[13] = (ANN_EKF_NMPC_2_P.Constant_Value_k -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
    locvar_Gain4_dz[loctmp_i_0 + 14] = ANN_EKF_NMPC_2_P.dt *
      locvar_Divide1_gv[loctmp_i_0];
  }

  /* Saturate: '<S226>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S226>/Gain'
   *  Gain: '<S226>/Gain1'
   *  Product: '<S151>/Divide2'
   *  Saturate: '<S226>/Throttle Limiter'
   *  Sum: '<S151>/Sum2'
   *  Sum: '<S226>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[28] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S226>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S226>/Gain2'
   *  Gain: '<S226>/Gain3'
   *  Product: '<S151>/Divide2'
   *  Saturate: '<S226>/Elevator Limiter'
   *  Sum: '<S151>/Sum2'
   *  Sum: '<S226>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[29] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S226>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S226>/Gain4'
   *  Gain: '<S226>/Gain5'
   *  Product: '<S151>/Divide2'
   *  Saturate: '<S226>/Aileron Limiter'
   *  Sum: '<S151>/Sum2'
   *  Sum: '<S226>/Add2'
   */
  locvar_Gain4_dz[30] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * locvar_Add1_cn2) - locvar_Add_eqw) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S226>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S226>/Gain6'
   *  Gain: '<S226>/Gain7'
   *  Product: '<S151>/Divide2'
   *  Product: '<S236>/Divide'
   *  Product: '<S241>/Divide'
   *  Saturate: '<S226>/Rudder Limiter'
   *  Sum: '<S151>/Sum2'
   *  Sum: '<S226>/Add3'
   *  Sum: '<S236>/Add'
   *  Sum: '<S241>/Add'
   *  Sum: '<S241>/Add1'
   *  Trigonometry: '<S241>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[31] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[32] = (((locvar_Divide3_b10 + locvar_Divide4_nh) +
    locvar_Divide5_pq) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
    locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[33] = (locvar_Divide_f5 - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[34] = ((locvar_Divide3_jze - locvar_Divide4_ncd) /
    (locvar_MathFunction_pp + locvar_MathFunction1_jr) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) - locvar_Divide_je) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Trigonometry: '<S244>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S244>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_n) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_n;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_ea) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_ea;
    }
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S229>/Constant1'
   *  Constant: '<S229>/Constant2'
   *  Constant: '<S231>/Constant1'
   *  Constant: '<S231>/Constant2'
   *  Constant: '<S232>/Constant1'
   *  Constant: '<S232>/Constant2'
   *  Constant: '<S245>/Constant'
   *  Constant: '<S246>/Constant'
   *  Constant: '<S265>/Ixx'
   *  Constant: '<S265>/Iyy'
   *  Constant: '<S265>/Izz'
   *  Constant: '<S266>/Ixz'
   *  Constant: '<S266>/Iyy'
   *  Math: '<S231>/Math Function'
   *  Math: '<S231>/Math Function1'
   *  Product: '<S151>/Divide2'
   *  Product: '<S229>/Divide1'
   *  Product: '<S229>/Divide5'
   *  Product: '<S229>/Divide6'
   *  Product: '<S231>/Divide2'
   *  Product: '<S231>/Divide3'
   *  Product: '<S231>/Divide5'
   *  Product: '<S231>/Divide6'
   *  Product: '<S232>/Divide1'
   *  Product: '<S232>/Divide5'
   *  Product: '<S232>/Divide6'
   *  Product: '<S244>/Divide1'
   *  Product: '<S244>/Divide2'
   *  Product: '<S244>/Divide4'
   *  Product: '<S247>/Divide2'
   *  Product: '<S247>/Divide4'
   *  Product: '<S265>/Divide4'
   *  Product: '<S266>/Divide4'
   *  Saturate: '<S244>/Saturation'
   *  Sum: '<S151>/Sum2'
   *  Sum: '<S229>/Add2'
   *  Sum: '<S231>/Add1'
   *  Sum: '<S231>/Add3'
   *  Sum: '<S232>/Add2'
   *  Sum: '<S244>/Add'
   *  Sum: '<S244>/Add1'
   *  Sum: '<S247>/Add'
   *  Sum: '<S265>/Add'
   *  Trigonometry: '<S244>/Trigonometric Function1'
   *  Trigonometry: '<S244>/Trigonometric Function2'
   *  Trigonometry: '<S247>/Trigonometric Function1'
   *  Trigonometry: '<S247>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[35] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[36] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[37] = ((locvar_Divide4_m3 * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_ccv + locvar_Add1_ef *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[38] = ((((ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxxB) /
    ANN_EKF_NMPC_2_P.IyyB * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB)) + locvar_Divide4_m3 * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.Cbar * locvar_Divide_prh) - locvar_Add1_ir) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[39] = ((locvar_Divide4_m3 * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_ifv + locvar_Add1_es *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[40] = (ANN_EKF_NMPC_2_P.Constant_Value_i4 -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[41] = (ANN_EKF_NMPC_2_P.Constant_Value_h -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S451>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S451>/Gain'
   *  Gain: '<S451>/Gain1'
   *  Product: '<S151>/Divide3'
   *  Saturate: '<S451>/Throttle Limiter'
   *  Sum: '<S151>/Sum3'
   *  Sum: '<S451>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[42] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S451>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S451>/Gain2'
   *  Gain: '<S451>/Gain3'
   *  Product: '<S151>/Divide3'
   *  Saturate: '<S451>/Elevator Limiter'
   *  Sum: '<S151>/Sum3'
   *  Sum: '<S451>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[43] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S451>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S451>/Gain4'
   *  Gain: '<S451>/Gain5'
   *  Product: '<S151>/Divide3'
   *  Saturate: '<S451>/Aileron Limiter'
   *  Sum: '<S151>/Sum3'
   *  Sum: '<S451>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[44] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S451>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S451>/Gain6'
   *  Gain: '<S451>/Gain7'
   *  Product: '<S151>/Divide3'
   *  Product: '<S461>/Divide'
   *  Product: '<S466>/Divide'
   *  Saturate: '<S451>/Rudder Limiter'
   *  Sum: '<S151>/Sum3'
   *  Sum: '<S451>/Add3'
   *  Sum: '<S461>/Add'
   *  Sum: '<S466>/Add'
   *  Sum: '<S466>/Add1'
   *  Trigonometry: '<S466>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[45] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * locvar_Add1_lq2) - locvar_Divide4_ky) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[46] = (((locvar_Divide3_npq + locvar_Divide4_lhf) +
    locvar_Divide5_ol) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
    locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[47] = (locvar_Divide_hc - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[48] = ((locvar_Divide3_io - locvar_Divide4_fy) /
    (locvar_MathFunction_iy + locvar_MathFunction1_cr) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) - locvar_Divide_je) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Trigonometry: '<S469>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S469>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_p) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_p;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_l) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_l;
    }
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S454>/Constant1'
   *  Constant: '<S454>/Constant2'
   *  Constant: '<S456>/Constant1'
   *  Constant: '<S456>/Constant2'
   *  Constant: '<S457>/Constant1'
   *  Constant: '<S457>/Constant2'
   *  Constant: '<S470>/Constant'
   *  Constant: '<S471>/Constant'
   *  Constant: '<S490>/Ixx'
   *  Constant: '<S490>/Iyy'
   *  Constant: '<S490>/Izz'
   *  Constant: '<S491>/Ixz'
   *  Constant: '<S491>/Iyy'
   *  Math: '<S456>/Math Function'
   *  Math: '<S456>/Math Function1'
   *  Product: '<S151>/Divide3'
   *  Product: '<S454>/Divide1'
   *  Product: '<S454>/Divide5'
   *  Product: '<S454>/Divide6'
   *  Product: '<S456>/Divide2'
   *  Product: '<S456>/Divide3'
   *  Product: '<S456>/Divide5'
   *  Product: '<S456>/Divide6'
   *  Product: '<S457>/Divide1'
   *  Product: '<S457>/Divide5'
   *  Product: '<S457>/Divide6'
   *  Product: '<S469>/Divide1'
   *  Product: '<S469>/Divide2'
   *  Product: '<S469>/Divide4'
   *  Product: '<S472>/Divide2'
   *  Product: '<S472>/Divide4'
   *  Product: '<S490>/Divide4'
   *  Product: '<S491>/Divide4'
   *  Reshape: '<S151>/Reshape'
   *  Saturate: '<S469>/Saturation'
   *  Sum: '<S151>/Sum3'
   *  Sum: '<S454>/Add2'
   *  Sum: '<S456>/Add1'
   *  Sum: '<S456>/Add3'
   *  Sum: '<S457>/Add2'
   *  Sum: '<S469>/Add'
   *  Sum: '<S469>/Add1'
   *  Sum: '<S472>/Add'
   *  Sum: '<S490>/Add'
   *  Trigonometry: '<S469>/Trigonometric Function1'
   *  Trigonometry: '<S469>/Trigonometric Function2'
   *  Trigonometry: '<S472>/Trigonometric Function1'
   *  Trigonometry: '<S472>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[49] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[50] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[51] = ((locvar_Divide4_ko * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_mx3 + locvar_Add1_k4 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[52] = ((((ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxxB) /
    ANN_EKF_NMPC_2_P.IyyB * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB)) + locvar_Divide4_ko * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.Cbar * locvar_Divide_dc) - locvar_Add1_ir) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[53] = ((locvar_Divide4_ko * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_df5 + locvar_Add1_e0 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[54] = (ANN_EKF_NMPC_2_P.Constant_Value_oe -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[55] = (ANN_EKF_NMPC_2_P.Constant_Value_j -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
    locvar_Gain4_dz[loctmp_i_0 + 56] = ANN_EKF_NMPC_2_P.dt *
      locvar_Divide4_ok[loctmp_i_0];
  }

  /* Saturate: '<S586>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S586>/Gain'
   *  Gain: '<S586>/Gain1'
   *  Product: '<S151>/Divide5'
   *  Saturate: '<S586>/Throttle Limiter'
   *  Sum: '<S151>/Sum5'
   *  Sum: '<S586>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[70] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S586>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S586>/Gain2'
   *  Gain: '<S586>/Gain3'
   *  Product: '<S151>/Divide5'
   *  Saturate: '<S586>/Elevator Limiter'
   *  Sum: '<S151>/Sum5'
   *  Sum: '<S586>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[71] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S586>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S586>/Gain4'
   *  Gain: '<S586>/Gain5'
   *  Product: '<S151>/Divide5'
   *  Saturate: '<S586>/Aileron Limiter'
   *  Sum: '<S151>/Sum5'
   *  Sum: '<S586>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[72] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S586>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S586>/Gain6'
   *  Gain: '<S586>/Gain7'
   *  Product: '<S151>/Divide5'
   *  Product: '<S596>/Divide'
   *  Product: '<S601>/Divide'
   *  Saturate: '<S586>/Rudder Limiter'
   *  Sum: '<S151>/Sum5'
   *  Sum: '<S586>/Add3'
   *  Sum: '<S596>/Add'
   *  Sum: '<S601>/Add'
   *  Sum: '<S601>/Add1'
   *  Trigonometry: '<S601>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[73] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[74] = (((locvar_Divide3_mnp + locvar_Divide4_jr4) +
    locvar_Divide5_nv) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
    locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[75] = (locvar_Divide_ml - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[76] = ((locvar_Divide3_at - locvar_Divide4_h3) /
    (locvar_MathFunction_hi4 + locvar_MathFunction1_ed) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) - locvar_Divide_je) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Trigonometry: '<S604>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S604>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_f) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_f;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_hc) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_hc;
    }
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S589>/Constant1'
   *  Constant: '<S589>/Constant2'
   *  Constant: '<S591>/Constant1'
   *  Constant: '<S591>/Constant2'
   *  Constant: '<S592>/Constant1'
   *  Constant: '<S592>/Constant2'
   *  Constant: '<S605>/Constant'
   *  Constant: '<S606>/Constant'
   *  Constant: '<S625>/Ixx'
   *  Constant: '<S625>/Iyy'
   *  Constant: '<S625>/Izz'
   *  Constant: '<S626>/Ixz'
   *  Constant: '<S626>/Iyy'
   *  Math: '<S591>/Math Function'
   *  Math: '<S591>/Math Function1'
   *  Product: '<S151>/Divide5'
   *  Product: '<S589>/Divide1'
   *  Product: '<S589>/Divide5'
   *  Product: '<S589>/Divide6'
   *  Product: '<S591>/Divide2'
   *  Product: '<S591>/Divide3'
   *  Product: '<S591>/Divide5'
   *  Product: '<S591>/Divide6'
   *  Product: '<S592>/Divide1'
   *  Product: '<S592>/Divide5'
   *  Product: '<S592>/Divide6'
   *  Product: '<S604>/Divide1'
   *  Product: '<S604>/Divide2'
   *  Product: '<S604>/Divide4'
   *  Product: '<S607>/Divide2'
   *  Product: '<S607>/Divide4'
   *  Product: '<S625>/Divide4'
   *  Product: '<S626>/Divide4'
   *  Saturate: '<S604>/Saturation'
   *  Sum: '<S151>/Sum5'
   *  Sum: '<S589>/Add2'
   *  Sum: '<S591>/Add1'
   *  Sum: '<S591>/Add3'
   *  Sum: '<S592>/Add2'
   *  Sum: '<S604>/Add'
   *  Sum: '<S604>/Add1'
   *  Sum: '<S607>/Add'
   *  Sum: '<S625>/Add'
   *  Trigonometry: '<S604>/Trigonometric Function1'
   *  Trigonometry: '<S604>/Trigonometric Function2'
   *  Trigonometry: '<S607>/Trigonometric Function1'
   *  Trigonometry: '<S607>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[77] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[78] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[79] = ((locvar_Divide4_ipd * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_cn + locvar_Add1_co *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[80] = ((((ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxxB) /
    ANN_EKF_NMPC_2_P.IyyB * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB)) + locvar_Divide4_ipd * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.Cbar * locvar_Divide_jg) - locvar_Add1_ir) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[81] = ((locvar_Divide4_ipd * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_nl + locvar_Add1_dy *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[82] = (ANN_EKF_NMPC_2_P.Constant_Value_je -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[83] = (ANN_EKF_NMPC_2_P.Constant_Value_fj -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S631>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S631>/Gain'
   *  Gain: '<S631>/Gain1'
   *  Product: '<S151>/Divide6'
   *  Saturate: '<S631>/Throttle Limiter'
   *  Sum: '<S151>/Sum6'
   *  Sum: '<S631>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[84] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S631>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S631>/Gain2'
   *  Gain: '<S631>/Gain3'
   *  Product: '<S151>/Divide6'
   *  Saturate: '<S631>/Elevator Limiter'
   *  Sum: '<S151>/Sum6'
   *  Sum: '<S631>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[85] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S631>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S631>/Gain4'
   *  Gain: '<S631>/Gain5'
   *  Product: '<S151>/Divide6'
   *  Saturate: '<S631>/Aileron Limiter'
   *  Sum: '<S151>/Sum6'
   *  Sum: '<S631>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[86] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S631>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S631>/Gain6'
   *  Gain: '<S631>/Gain7'
   *  Product: '<S151>/Divide6'
   *  Product: '<S641>/Divide'
   *  Product: '<S646>/Divide'
   *  Saturate: '<S631>/Rudder Limiter'
   *  Sum: '<S151>/Sum6'
   *  Sum: '<S631>/Add3'
   *  Sum: '<S641>/Add'
   *  Sum: '<S646>/Add'
   *  Sum: '<S646>/Add1'
   *  Trigonometry: '<S646>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[87] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[88] = (((locvar_Divide3_ef + locvar_Divide4_j0a) +
    locvar_Divide5_dki) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
    locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[89] = (locvar_Divide_hvn - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[90] = ((locvar_Divide3_poh - locvar_Divide4_hl4) /
    (locvar_MathFunction_ld + locvar_MathFunction1_j) * cos(locvar_Add_ow) -
    locvar_Divide_je) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Trigonometry: '<S649>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S649>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_f4) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_f4;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_c) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_c;
    }
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S634>/Constant1'
   *  Constant: '<S634>/Constant2'
   *  Constant: '<S636>/Constant1'
   *  Constant: '<S636>/Constant2'
   *  Constant: '<S637>/Constant1'
   *  Constant: '<S637>/Constant2'
   *  Constant: '<S650>/Constant'
   *  Constant: '<S651>/Constant'
   *  Constant: '<S670>/Ixx'
   *  Constant: '<S670>/Iyy'
   *  Constant: '<S670>/Izz'
   *  Constant: '<S671>/Ixz'
   *  Constant: '<S671>/Iyy'
   *  Math: '<S636>/Math Function'
   *  Math: '<S636>/Math Function1'
   *  Product: '<S151>/Divide6'
   *  Product: '<S634>/Divide1'
   *  Product: '<S634>/Divide5'
   *  Product: '<S634>/Divide6'
   *  Product: '<S636>/Divide2'
   *  Product: '<S636>/Divide3'
   *  Product: '<S636>/Divide5'
   *  Product: '<S636>/Divide6'
   *  Product: '<S637>/Divide1'
   *  Product: '<S637>/Divide5'
   *  Product: '<S637>/Divide6'
   *  Product: '<S649>/Divide1'
   *  Product: '<S649>/Divide2'
   *  Product: '<S649>/Divide4'
   *  Product: '<S652>/Divide2'
   *  Product: '<S652>/Divide4'
   *  Product: '<S670>/Divide4'
   *  Product: '<S671>/Divide4'
   *  Saturate: '<S649>/Saturation'
   *  Sum: '<S151>/Sum6'
   *  Sum: '<S634>/Add2'
   *  Sum: '<S636>/Add1'
   *  Sum: '<S636>/Add3'
   *  Sum: '<S637>/Add2'
   *  Sum: '<S649>/Add'
   *  Sum: '<S649>/Add1'
   *  Sum: '<S652>/Add'
   *  Sum: '<S670>/Add'
   *  Trigonometry: '<S649>/Trigonometric Function1'
   *  Trigonometry: '<S649>/Trigonometric Function2'
   *  Trigonometry: '<S652>/Trigonometric Function1'
   *  Trigonometry: '<S652>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[91] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[92] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[93] = ((locvar_Divide4_m3z * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_jbj + locvar_Add1_ot *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[94] = ((((ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxxB) /
    ANN_EKF_NMPC_2_P.IyyB * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB)) + locvar_Divide4_m3z * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.Cbar * locvar_Divide_b) - locvar_Add1_ir) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[95] = ((locvar_Divide4_m3z * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_oj + locvar_Add1_i0 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[96] = (ANN_EKF_NMPC_2_P.Constant_Value_b -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[97] = (ANN_EKF_NMPC_2_P.Constant_Value_lq -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S676>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S676>/Gain'
   *  Gain: '<S676>/Gain1'
   *  Product: '<S151>/Divide17'
   *  Saturate: '<S676>/Throttle Limiter'
   *  Sum: '<S151>/Sum7'
   *  Sum: '<S676>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[98] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S676>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S676>/Gain2'
   *  Gain: '<S676>/Gain3'
   *  Product: '<S151>/Divide17'
   *  Saturate: '<S676>/Elevator Limiter'
   *  Sum: '<S151>/Sum7'
   *  Sum: '<S676>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[99] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S676>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S676>/Gain4'
   *  Gain: '<S676>/Gain5'
   *  Product: '<S151>/Divide17'
   *  Saturate: '<S676>/Aileron Limiter'
   *  Sum: '<S151>/Sum7'
   *  Sum: '<S676>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[100] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S676>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S676>/Gain6'
   *  Gain: '<S676>/Gain7'
   *  Product: '<S151>/Divide17'
   *  Product: '<S686>/Divide'
   *  Product: '<S691>/Divide'
   *  Saturate: '<S676>/Rudder Limiter'
   *  Sum: '<S151>/Sum7'
   *  Sum: '<S676>/Add3'
   *  Sum: '<S686>/Add'
   *  Sum: '<S691>/Add'
   *  Sum: '<S691>/Add1'
   *  Trigonometry: '<S691>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[101] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[102] = (((locvar_Divide3_p0a + locvar_Divide4_i0) +
    locvar_Divide5_luy) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
    locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[103] = (locvar_Divide_hz - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[104] = ((locvar_Divide3_n5 - locvar_Divide4_pem) /
    (locvar_MathFunction_p2 + locvar_MathFunction1_ot) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) - locvar_Divide_je) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Trigonometry: '<S694>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S694>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_o) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_o;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_cc) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_cc;
    }
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S679>/Constant1'
   *  Constant: '<S679>/Constant2'
   *  Constant: '<S681>/Constant1'
   *  Constant: '<S681>/Constant2'
   *  Constant: '<S682>/Constant1'
   *  Constant: '<S682>/Constant2'
   *  Constant: '<S695>/Constant'
   *  Constant: '<S696>/Constant'
   *  Constant: '<S715>/Ixx'
   *  Constant: '<S715>/Iyy'
   *  Constant: '<S715>/Izz'
   *  Constant: '<S716>/Ixz'
   *  Constant: '<S716>/Iyy'
   *  Math: '<S681>/Math Function'
   *  Math: '<S681>/Math Function1'
   *  Product: '<S151>/Divide17'
   *  Product: '<S679>/Divide1'
   *  Product: '<S679>/Divide5'
   *  Product: '<S679>/Divide6'
   *  Product: '<S681>/Divide2'
   *  Product: '<S681>/Divide3'
   *  Product: '<S681>/Divide5'
   *  Product: '<S681>/Divide6'
   *  Product: '<S682>/Divide1'
   *  Product: '<S682>/Divide5'
   *  Product: '<S682>/Divide6'
   *  Product: '<S694>/Divide1'
   *  Product: '<S697>/Divide2'
   *  Product: '<S697>/Divide4'
   *  Product: '<S715>/Divide4'
   *  Product: '<S716>/Divide4'
   *  Saturate: '<S694>/Saturation'
   *  Sum: '<S151>/Sum7'
   *  Sum: '<S679>/Add2'
   *  Sum: '<S681>/Add1'
   *  Sum: '<S681>/Add3'
   *  Sum: '<S682>/Add2'
   *  Sum: '<S694>/Add1'
   *  Sum: '<S697>/Add'
   *  Sum: '<S715>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[105] = ((locvar_Add_me * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[106] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_TrigonometricFunction1_d5j - locvar_TrigonometricFunction2_lt *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[107] = ((locvar_Divide4_hvl * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_ay + locvar_Add1_jqe *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[108] = ((((ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxxB) /
    ANN_EKF_NMPC_2_P.IyyB * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB)) + locvar_Divide4_hvl * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.Cbar * locvar_Divide_ft) - locvar_Add1_ir) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[109] = ((locvar_Divide4_hvl * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_bs + locvar_Add1_mq *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[110] = (ANN_EKF_NMPC_2_P.Constant_Value_j0 -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[111] = (ANN_EKF_NMPC_2_P.Constant_Value_nxv -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S721>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S721>/Gain'
   *  Gain: '<S721>/Gain1'
   *  Product: '<S151>/Divide7'
   *  Saturate: '<S721>/Throttle Limiter'
   *  Sum: '<S151>/Sum8'
   *  Sum: '<S721>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[112] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S721>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S721>/Gain2'
   *  Gain: '<S721>/Gain3'
   *  Product: '<S151>/Divide7'
   *  Saturate: '<S721>/Elevator Limiter'
   *  Sum: '<S151>/Sum8'
   *  Sum: '<S721>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[113] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S721>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S721>/Gain4'
   *  Gain: '<S721>/Gain5'
   *  Product: '<S151>/Divide7'
   *  Saturate: '<S721>/Aileron Limiter'
   *  Sum: '<S151>/Sum8'
   *  Sum: '<S721>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[114] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S721>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S724>/Constant1'
   *  Constant: '<S724>/Constant2'
   *  Constant: '<S726>/Constant1'
   *  Constant: '<S726>/Constant2'
   *  Constant: '<S727>/Constant1'
   *  Constant: '<S727>/Constant2'
   *  Constant: '<S740>/Constant'
   *  Constant: '<S741>/Constant'
   *  Constant: '<S760>/Ixx'
   *  Constant: '<S760>/Iyy'
   *  Constant: '<S760>/Izz'
   *  Constant: '<S761>/Ixz'
   *  Constant: '<S761>/Iyy'
   *  Gain: '<S721>/Gain6'
   *  Gain: '<S721>/Gain7'
   *  Math: '<S726>/Math Function'
   *  Math: '<S726>/Math Function1'
   *  Product: '<S151>/Divide7'
   *  Product: '<S724>/Divide1'
   *  Product: '<S724>/Divide5'
   *  Product: '<S724>/Divide6'
   *  Product: '<S726>/Divide2'
   *  Product: '<S726>/Divide3'
   *  Product: '<S726>/Divide5'
   *  Product: '<S726>/Divide6'
   *  Product: '<S727>/Divide1'
   *  Product: '<S727>/Divide5'
   *  Product: '<S727>/Divide6'
   *  Product: '<S731>/Divide'
   *  Product: '<S736>/Divide'
   *  Product: '<S739>/Divide1'
   *  Product: '<S739>/Divide2'
   *  Product: '<S739>/Divide4'
   *  Product: '<S742>/Divide2'
   *  Product: '<S742>/Divide4'
   *  Product: '<S760>/Divide4'
   *  Product: '<S761>/Divide4'
   *  Saturate: '<S721>/Rudder Limiter'
   *  Sum: '<S151>/Sum8'
   *  Sum: '<S721>/Add3'
   *  Sum: '<S724>/Add2'
   *  Sum: '<S726>/Add1'
   *  Sum: '<S726>/Add3'
   *  Sum: '<S727>/Add2'
   *  Sum: '<S731>/Add'
   *  Sum: '<S736>/Add'
   *  Sum: '<S736>/Add1'
   *  Sum: '<S739>/Add'
   *  Sum: '<S739>/Add1'
   *  Sum: '<S742>/Add'
   *  Sum: '<S760>/Add'
   *  Trigonometry: '<S736>/Trigonometric Function1'
   *  Trigonometry: '<S739>/Trigonometric Function1'
   *  Trigonometry: '<S739>/Trigonometric Function2'
   *  Trigonometry: '<S742>/Trigonometric Function1'
   *  Trigonometry: '<S742>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[115] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[116] = (((locvar_Divide3_bt + locvar_Divide4_fqv) +
    locvar_Divide5_ny) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
    locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[117] = (locvar_Divide_n - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[118] = ((locvar_Divide3_ai5 - locvar_Divide4_ik) /
    (locvar_MathFunction_bv + locvar_MathFunction1_id) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) - locvar_Divide_je) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[119] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Saturation_m +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[120] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[121] = ((locvar_Divide4_dt * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_ez + locvar_Add1_ety *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[122] = ((((ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxxB) /
    ANN_EKF_NMPC_2_P.IyyB * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB)) + locvar_Divide4_dt * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.Cbar * locvar_Divide_n0) - locvar_Add1_ir) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[123] = ((locvar_Divide4_dt * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_df3 + locvar_Add1_pkj *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[124] = (ANN_EKF_NMPC_2_P.Constant_Value_am -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[125] = (ANN_EKF_NMPC_2_P.Constant_Value_ik -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S316>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S316>/Gain'
   *  Gain: '<S316>/Gain1'
   *  Product: '<S151>/Divide8'
   *  Saturate: '<S316>/Throttle Limiter'
   *  Sum: '<S151>/Sum9'
   *  Sum: '<S316>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[126] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S316>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S316>/Gain2'
   *  Gain: '<S316>/Gain3'
   *  Product: '<S151>/Divide8'
   *  Saturate: '<S316>/Elevator Limiter'
   *  Sum: '<S151>/Sum9'
   *  Sum: '<S316>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[127] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S316>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S316>/Gain4'
   *  Gain: '<S316>/Gain5'
   *  Product: '<S151>/Divide8'
   *  Saturate: '<S316>/Aileron Limiter'
   *  Sum: '<S151>/Sum9'
   *  Sum: '<S316>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[128] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S316>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S316>/Gain6'
   *  Gain: '<S316>/Gain7'
   *  Product: '<S151>/Divide8'
   *  Product: '<S326>/Divide'
   *  Product: '<S331>/Divide'
   *  Saturate: '<S316>/Rudder Limiter'
   *  Sum: '<S151>/Sum9'
   *  Sum: '<S316>/Add3'
   *  Sum: '<S326>/Add'
   *  Sum: '<S331>/Add'
   *  Sum: '<S331>/Add1'
   *  Trigonometry: '<S331>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[129] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[130] = (((locvar_Divide3_oc + locvar_Divide4_oem) +
    locvar_Divide5_kh) / ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
    locvar_Divide_ad) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[131] = (locvar_Divide_c - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[132] = ((locvar_Divide3_j0 - locvar_Divide4_afp) /
    (locvar_MathFunction_di + locvar_MathFunction1_e4) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) - locvar_Divide_je) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Trigonometry: '<S334>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S334>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_o2) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_o2;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_o) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_o;
    }
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S319>/Constant1'
   *  Constant: '<S319>/Constant2'
   *  Constant: '<S321>/Constant1'
   *  Constant: '<S321>/Constant2'
   *  Constant: '<S322>/Constant1'
   *  Constant: '<S322>/Constant2'
   *  Constant: '<S335>/Constant'
   *  Constant: '<S336>/Constant'
   *  Constant: '<S355>/Ixx'
   *  Constant: '<S355>/Iyy'
   *  Constant: '<S355>/Izz'
   *  Constant: '<S356>/Ixz'
   *  Constant: '<S356>/Iyy'
   *  Math: '<S321>/Math Function'
   *  Math: '<S321>/Math Function1'
   *  Product: '<S151>/Divide8'
   *  Product: '<S319>/Divide1'
   *  Product: '<S319>/Divide5'
   *  Product: '<S319>/Divide6'
   *  Product: '<S321>/Divide2'
   *  Product: '<S321>/Divide3'
   *  Product: '<S321>/Divide5'
   *  Product: '<S321>/Divide6'
   *  Product: '<S322>/Divide1'
   *  Product: '<S322>/Divide5'
   *  Product: '<S322>/Divide6'
   *  Product: '<S334>/Divide1'
   *  Product: '<S334>/Divide2'
   *  Product: '<S334>/Divide4'
   *  Product: '<S337>/Divide2'
   *  Product: '<S337>/Divide4'
   *  Product: '<S355>/Divide4'
   *  Product: '<S356>/Divide4'
   *  Reshape: '<S151>/Reshape'
   *  Saturate: '<S334>/Saturation'
   *  Sum: '<S151>/Sum9'
   *  Sum: '<S319>/Add2'
   *  Sum: '<S321>/Add1'
   *  Sum: '<S321>/Add3'
   *  Sum: '<S322>/Add2'
   *  Sum: '<S334>/Add'
   *  Sum: '<S334>/Add1'
   *  Sum: '<S337>/Add'
   *  Sum: '<S355>/Add'
   *  Trigonometry: '<S334>/Trigonometric Function1'
   *  Trigonometry: '<S334>/Trigonometric Function2'
   *  Trigonometry: '<S337>/Trigonometric Function1'
   *  Trigonometry: '<S337>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[133] = (((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt + locvar_Add_ev)
    - locvar_Add1_md) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[134] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) - locvar_Add_b1) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[135] = ((locvar_Divide4_kz * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_au + locvar_Add1_o3 *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[136] = ((((ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxxB) /
    ANN_EKF_NMPC_2_P.IyyB * locvar_Add_ev * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
    [11] - (locvar_Add_ev * locvar_Add_ev - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
            [11] * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) *
    (ANN_EKF_NMPC_2_P.IxzB / ANN_EKF_NMPC_2_P.IyyB)) + locvar_Divide4_kz *
    ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.Cbar * locvar_Divide_aa) -
    locvar_Add1_ir) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[137] = ((locvar_Divide4_kz * ANN_EKF_NMPC_2_P.S *
    ANN_EKF_NMPC_2_P.b * locvar_Add_pii + locvar_Add1_ob *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[138] = (ANN_EKF_NMPC_2_P.Constant_Value_g1 -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[139] = (ANN_EKF_NMPC_2_P.Constant_Value_gu -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
    locvar_Gain4_dz[loctmp_i_0 + 140] = ANN_EKF_NMPC_2_P.dt *
      locvar_Reshape1[loctmp_i_0];
  }

  /* Saturate: '<S406>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S406>/Gain'
   *  Gain: '<S406>/Gain1'
   *  Product: '<S151>/Divide10'
   *  Saturate: '<S406>/Throttle Limiter'
   *  Sum: '<S151>/Sum11'
   *  Sum: '<S406>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[154] = ((ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) -
    locvar_Add2_fi) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S406>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S406>/Gain2'
   *  Gain: '<S406>/Gain3'
   *  Product: '<S151>/Divide10'
   *  Saturate: '<S406>/Elevator Limiter'
   *  Sum: '<S151>/Sum11'
   *  Sum: '<S406>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[155] = ((ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) -
    locvar_Add2_ap) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S406>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S406>/Gain4'
   *  Gain: '<S406>/Gain5'
   *  Product: '<S151>/Divide10'
   *  Saturate: '<S406>/Aileron Limiter'
   *  Sum: '<S151>/Sum11'
   *  Sum: '<S406>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[156] = ((ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) -
    locvar_Add_eqw) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Saturate: '<S406>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/delta'
   *  Gain: '<S406>/Gain6'
   *  Gain: '<S406>/Gain7'
   *  Product: '<S151>/Divide10'
   *  Saturate: '<S406>/Rudder Limiter'
   *  Sum: '<S151>/Sum11'
   *  Sum: '<S406>/Add3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain4_dz[157] = ((ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) -
    locvar_Divide4_ky) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[158] = (locvar_Divide4_dh - locvar_Divide_ad) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[159] = (locvar_Divide_jpd - locvar_Divide) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[160] = (locvar_Axb_e - locvar_Divide_je) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;

  /* Trigonometry: '<S424>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S424>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_gk) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_gk;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_i) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_i;
    }
  }

  /* Gain: '<S151>/Gain4' incorporates:
   *  Constant: '<S151>/Constant'
   *  Constant: '<S151>/delta'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S411>/Constant1'
   *  Constant: '<S411>/Constant2'
   *  Constant: '<S425>/Constant'
   *  Constant: '<S426>/Constant'
   *  Constant: '<S434>/Constant'
   *  Constant: '<S434>/Constant1'
   *  Constant: '<S434>/Constant11'
   *  Constant: '<S434>/Constant12'
   *  Constant: '<S434>/Constant13'
   *  Constant: '<S434>/Constant14'
   *  Constant: '<S434>/Constant2'
   *  Constant: '<S434>/Constant3'
   *  Constant: '<S434>/Constant4'
   *  Constant: '<S434>/Constant5'
   *  Constant: '<S434>/Constant6'
   *  Constant: '<S434>/Constant7'
   *  Constant: '<S434>/Constant8'
   *  Constant: '<S434>/Constant9'
   *  Constant: '<S445>/Ixx'
   *  Constant: '<S445>/Iyy'
   *  Constant: '<S445>/Izz'
   *  Constant: '<S446>/Ixz'
   *  Constant: '<S446>/Iyy'
   *  Constant: '<S447>/Ixz'
   *  Constant: '<S447>/Iyy'
   *  Gain: '<S434>/Gain1'
   *  Gain: '<S434>/Gain2'
   *  Math: '<S411>/Math Function'
   *  Math: '<S411>/Math Function1'
   *  Product: '<S151>/Divide10'
   *  Product: '<S411>/Divide'
   *  Product: '<S411>/Divide2'
   *  Product: '<S411>/Divide3'
   *  Product: '<S411>/Divide5'
   *  Product: '<S411>/Divide6'
   *  Product: '<S424>/Divide1'
   *  Product: '<S424>/Divide2'
   *  Product: '<S424>/Divide4'
   *  Product: '<S427>/Divide2'
   *  Product: '<S427>/Divide4'
   *  Product: '<S434>/Divide1'
   *  Product: '<S434>/Divide2'
   *  Product: '<S434>/Divide3'
   *  Product: '<S434>/Divide4'
   *  Product: '<S434>/Divide5'
   *  Product: '<S434>/Divide6'
   *  Product: '<S445>/Divide4'
   *  Product: '<S446>/Divide4'
   *  Product: '<S447>/Divide4'
   *  Reshape: '<S151>/Reshape'
   *  Saturate: '<S424>/Saturation'
   *  Sum: '<S151>/Sum11'
   *  Sum: '<S411>/Add1'
   *  Sum: '<S411>/Add3'
   *  Sum: '<S424>/Add'
   *  Sum: '<S424>/Add1'
   *  Sum: '<S427>/Add'
   *  Sum: '<S434>/Add'
   *  Sum: '<S434>/Add1'
   *  Sum: '<S434>/Add2'
   *  Sum: '<S434>/Add3'
   *  Sum: '<S445>/Add'
   *  Trigonometry: '<S424>/Trigonometric Function1'
   *  Trigonometry: '<S424>/Trigonometric Function2'
   *  Trigonometry: '<S427>/Trigonometric Function1'
   *  Trigonometry: '<S427>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S420>/Unit Delay'
   */
  locvar_Gain4_dz[161] = (((locvar_Divide4_c1v * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) - locvar_Add1_md) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[162] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * locvar_Divide4_c1v) -
    locvar_Add_b1) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[163] = (locvar_Add2_db - locvar_Add2_ga) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[164] = ((((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_or *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
    ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim * (locvar_Divide2_op -
    ANN_EKF_NMPC_2_P.Utrim)) + ANN_EKF_NMPC_2_P.Cmde *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 / ANN_EKF_NMPC_2_P.Utrim *
    (locvar_Divide2_op - ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
    ANN_EKF_NMPC_2_P.Gain2_Gain_m1 * ANN_EKF_NMPC_2_P.Gain1_Gain_hz) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_k / ANN_EKF_NMPC_2_P.IyyB) * (locvar_Divide4_ch *
    ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.Cbar) + ((ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxxB) / ANN_EKF_NMPC_2_P.IyyB *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] * locvar_Divide4_c1v -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_Divide4_c1v *
     locvar_Divide4_c1v) * (ANN_EKF_NMPC_2_P.IxzB / ANN_EKF_NMPC_2_P.IyyB))) -
    locvar_Add1_ir) / ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[165] = (locvar_Divide2_em - locvar_Divide_j0) /
    ANN_EKF_NMPC_2_P.delta_Value_e * ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[166] = (ANN_EKF_NMPC_2_P.Constant_Value_ol -
    ANN_EKF_NMPC_2_P.Constant_Value_f) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  locvar_Gain4_dz[167] = (ANN_EKF_NMPC_2_P.Constant_Value_cb -
    ANN_EKF_NMPC_2_P.Constant_Value_a) / ANN_EKF_NMPC_2_P.delta_Value_e *
    ANN_EKF_NMPC_2_P.dt;
  for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
    locvar_Gain4_dz[loctmp_i_0 + 168] = ANN_EKF_NMPC_2_P.dt *
      ANN_EKF_NMPC_2_P.Constant_Value_ax[loctmp_i_0];
  }

  for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
    locvar_Gain4_dz[loctmp_i_0 + 182] = ANN_EKF_NMPC_2_P.dt *
      ANN_EKF_NMPC_2_P.Constant_Value_ax[loctmp_i_0];
  }

  /* Product: '<S155>/Matrix Multiply' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      locvar_P_kk1_m[loctmp_i_1 + 14 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        locvar_P_kk1_m[loctmp_i_1 + 14 * loctmp_i_0] += locvar_Gain4_dz[14 *
          locvar_DataTypeConversion1 + loctmp_i_1] * locvar_Gain4_dz[14 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* End of Product: '<S155>/Matrix Multiply' */

  /* Product: '<S155>/Matrix Multiply1' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      locvar_Product2_d[loctmp_i_1 + 14 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        locvar_Product2_d[loctmp_i_1 + 14 * loctmp_i_0] += locvar_P_kk1_m[14 *
          locvar_DataTypeConversion1 + loctmp_i_1] * locvar_Gain4_dz[14 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* End of Product: '<S155>/Matrix Multiply1' */

  /* Product: '<S155>/Matrix Multiply2' incorporates:
   *  Gain: '<S155>/Gain2'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      loctmp_locvar_Product2_c[loctmp_i_1 + 14 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        loctmp_locvar_Product2_c[loctmp_i_1 + 14 * loctmp_i_0] +=
          locvar_Product2_d[14 * locvar_DataTypeConversion1 + loctmp_i_1] *
          locvar_Gain4_dz[14 * loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* End of Product: '<S155>/Matrix Multiply2' */

  /* Sum: '<S155>/Add' incorporates:
   *  Constant: '<S155>/Constant'
   *  Gain: '<S155>/Gain'
   *  Gain: '<S155>/Gain1'
   *  Gain: '<S155>/Gain2'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      locvar_Add_o[loctmp_i_0 + 14 * loctmp_i_1] =
        (((ANN_EKF_NMPC_2_P.Constant_Value_mp[14 * loctmp_i_1 + loctmp_i_0] +
           locvar_Gain4_dz[14 * loctmp_i_1 + loctmp_i_0]) + locvar_P_kk1_m[14 *
          loctmp_i_1 + loctmp_i_0] * ANN_EKF_NMPC_2_P.Gain_Gain_fk) +
         locvar_Product2_d[14 * loctmp_i_1 + loctmp_i_0] *
         ANN_EKF_NMPC_2_P.Gain1_Gain_hu) + loctmp_locvar_Product2_c[14 *
        loctmp_i_1 + loctmp_i_0] * ANN_EKF_NMPC_2_P.Gain2_Gain_mc;
    }
  }

  /* End of Sum: '<S155>/Add' */

  /* Product: '<S147>/Product' incorporates:
   *  MATLAB Function: '<S147>/Transpose'
   *  UnitDelay: '<S147>/P_est_[0//0]'
   */
  /* MATLAB Function 'State Observer Yak54 40\% (subsystem)/State Observer/EKF/K[k] (states)/Transpose': '<S154>:1' */
  /* '<S154>:1:4' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      locvar_Gain4_dz[loctmp_i_1 + 14 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        locvar_Gain4_dz[loctmp_i_1 + 14 * loctmp_i_0] +=
          ANN_EKF_NMPC_2_DW.P_est_00_DSTATE_o[14 * locvar_DataTypeConversion1 +
          loctmp_i_1] * locvar_Add_o[14 * locvar_DataTypeConversion1 +
          loctmp_i_0];
      }
    }
  }

  /* Sum: '<S147>/Subtract2' incorporates:
   *  Constant: '<S147>/Q_[k-1]'
   *  Product: '<S147>/Product'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      loctmp_tmp_7 = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        loctmp_tmp_7 += locvar_Add_o[14 * locvar_DataTypeConversion1 +
          loctmp_i_1] * locvar_Gain4_dz[14 * loctmp_i_0 +
          locvar_DataTypeConversion1];
      }

      locvar_P_kk1_m[loctmp_i_1 + 14 * loctmp_i_0] = ANN_EKF_NMPC_2_P.Q_obs_sta
        [14 * loctmp_i_0 + loctmp_i_1] + loctmp_tmp_7;
    }
  }

  /* End of Sum: '<S147>/Subtract2' */

  /* Sum: '<S795>/Subtract1' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide2_em = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12];

  /* Sum: '<S795>/Subtract2' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide2_ic = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13];

  /* Reshape: '<S152>/Reshape' incorporates:
   *  Constant: '<S152>/delta'
   *  Product: '<S152>/Divide'
   *  Product: '<S152>/Divide1'
   *  Product: '<S152>/Divide10'
   *  Product: '<S152>/Divide12'
   *  Product: '<S152>/Divide13'
   *  Product: '<S152>/Divide17'
   *  Product: '<S152>/Divide2'
   *  Product: '<S152>/Divide3'
   *  Product: '<S152>/Divide4'
   *  Product: '<S152>/Divide5'
   *  Product: '<S152>/Divide6'
   *  Product: '<S152>/Divide7'
   *  Product: '<S152>/Divide8'
   *  Product: '<S152>/Divide9'
   *  Sum: '<S152>/Sum'
   *  Sum: '<S152>/Sum1'
   *  Sum: '<S152>/Sum10'
   *  Sum: '<S152>/Sum11'
   *  Sum: '<S152>/Sum14'
   *  Sum: '<S152>/Sum15'
   *  Sum: '<S152>/Sum2'
   *  Sum: '<S152>/Sum3'
   *  Sum: '<S152>/Sum4'
   *  Sum: '<S152>/Sum5'
   *  Sum: '<S152>/Sum6'
   *  Sum: '<S152>/Sum7'
   *  Sum: '<S152>/Sum8'
   *  Sum: '<S152>/Sum9'
   *  Sum: '<S768>/Add'
   *  Sum: '<S769>/Add'
   *  Sum: '<S770>/Add'
   *  Sum: '<S773>/Add1'
   *  Sum: '<S774>/Add'
   *  Sum: '<S775>/Add'
   *  Sum: '<S776>/Add'
   *  Sum: '<S777>/Add'
   *  Sum: '<S778>/Add'
   *  Sum: '<S779>/Add'
   *  Sum: '<S796>/Subtract1'
   *  Sum: '<S796>/Subtract2'
   *  Sum: '<S797>/Subtract1'
   *  Sum: '<S797>/Subtract2'
   *  Sum: '<S798>/Subtract1'
   *  Sum: '<S798>/Subtract2'
   *  Sum: '<S799>/Subtract1'
   *  Sum: '<S799>/Subtract2'
   *  Sum: '<S800>/Subtract1'
   *  Sum: '<S800>/Subtract2'
   *  Sum: '<S801>/Subtract1'
   *  Sum: '<S801>/Subtract2'
   *  Sum: '<S802>/Subtract1'
   *  Sum: '<S802>/Subtract2'
   *  Sum: '<S803>/Subtract1'
   *  Sum: '<S803>/Subtract2'
   *  Sum: '<S804>/Subtract1'
   *  Sum: '<S804>/Subtract2'
   *  Sum: '<S805>/Subtract1'
   *  Sum: '<S805>/Subtract2'
   *  Sum: '<S806>/Subtract1'
   *  Sum: '<S806>/Subtract2'
   *  Sum: '<S807>/Subtract1'
   *  Sum: '<S807>/Subtract2'
   *  Sum: '<S808>/Subtract1'
   *  Sum: '<S808>/Subtract2'
   *  Sum: '<S809>/Subtract1'
   *  Sum: '<S809>/Subtract2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Reshape[0] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[1] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) -
                       locvar_Divide2_em) / ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[2] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) -
                       locvar_Divide2_ic) / ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 3] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  locvar_Reshape[8] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[9] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) -
                       locvar_Divide2_em) / ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[10] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 11] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  locvar_Reshape[16] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[17] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[18] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 19] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  locvar_Reshape[24] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[25] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[26] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 27] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  locvar_Reshape[32] = ((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[33] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[34] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 35] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  locvar_Reshape[40] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[41] = (((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[42] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 43] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  locvar_Reshape[48] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[49] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[50] = (((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 51] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  locvar_Reshape[56] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[57] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[58] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[59] = ((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[60] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[61] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[62] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[63] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[64] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[65] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[66] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[67] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[68] = ((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[69] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[70] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[71] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[72] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[73] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[74] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[75] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[76] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[77] = ((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[78] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[79] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[80] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[81] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[82] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[83] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[84] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[85] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[86] = ((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[87] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[88] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[89] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[90] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[91] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[92] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[93] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[94] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[95] = ((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[96] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[97] = (((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[98] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 99] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  locvar_Reshape[104] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] -
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]) / ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[105] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12]) - locvar_Divide2_em) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  locvar_Reshape[106] = (((ANN_EKF_NMPC_2_P.delta_Value_o +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13]) +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) - locvar_Divide2_ic) /
    ANN_EKF_NMPC_2_P.delta_Value_o;
  for (loctmp_i_0 = 0; loctmp_i_0 < 5; loctmp_i_0++) {
    locvar_Reshape[loctmp_i_0 + 107] =
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7] -
       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0 + 7]) /
      ANN_EKF_NMPC_2_P.delta_Value_o;
  }

  /* End of Reshape: '<S152>/Reshape' */

  /* MATLAB Function: '<S153>/Transpose' */
  /* MATLAB Function 'State Observer Yak54 40\% (subsystem)/State Observer/EKF/K[k] (states)/K_[k]/Transpose': '<S811>:1' */
  /* '<S811>:1:4' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 8; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      locvar_HT_k[loctmp_i_0 + 14 * loctmp_i_1] = locvar_Reshape[(loctmp_i_0 <<
        3) + loctmp_i_1];
    }
  }

  /* End of MATLAB Function: '<S153>/Transpose' */

  /* Product: '<S153>/Product' */
  /* MATLAB Function 'State Observer Yak54 40\% (subsystem)/State Observer/EKF/K[k] (states)/K_[k]/Inverse': '<S810>:1' */
  /* '<S810>:1:4' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 8; loctmp_i_0++) {
      loctmp_locvar_P_kk1_m[loctmp_i_1 + 14 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        loctmp_locvar_P_kk1_m[loctmp_i_1 + 14 * loctmp_i_0] += locvar_P_kk1_m[14
          * locvar_DataTypeConversion1 + loctmp_i_1] * locvar_HT_k[14 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* Sum: '<S153>/Subtract2' incorporates:
   *  Constant: '<S147>/R_[k]'
   *  Product: '<S153>/Product'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 8; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 8; loctmp_i_0++) {
      loctmp_tmp_7 = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        loctmp_tmp_7 += locvar_Reshape[(locvar_DataTypeConversion1 << 3) +
          loctmp_i_1] * loctmp_locvar_P_kk1_m[14 * loctmp_i_0 +
          locvar_DataTypeConversion1];
      }

      loctmp_locvar_Reshape_0[loctmp_i_1 + (loctmp_i_0 << 3)] =
        ANN_EKF_NMPC_2_P.R_obs_sta[(loctmp_i_0 << 3) + loctmp_i_1] +
        loctmp_tmp_7;
    }
  }

  memcpy(&loctmp_locvar_Reshape[0], &loctmp_locvar_Reshape_0[0], sizeof(real_T) <<
         6U);

  /* End of Sum: '<S153>/Subtract2' */

  /* MATLAB Function: '<S153>/Inverse' */
  ANN_EKF_NMPC_2_invNxN_a(loctmp_locvar_Reshape, loctmp_locvar_Reshape_0);

  /* Product: '<S153>/Product1' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 8; loctmp_i_0++) {
      loctmp_locvar_P_kk1_m[loctmp_i_1 + 14 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 8;
           locvar_DataTypeConversion1++) {
        loctmp_locvar_P_kk1_m[loctmp_i_1 + 14 * loctmp_i_0] += locvar_HT_k[14 *
          locvar_DataTypeConversion1 + loctmp_i_1] * loctmp_locvar_Reshape_0
          [(loctmp_i_0 << 3) + locvar_DataTypeConversion1];
      }
    }
  }

  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 8; loctmp_i_0++) {
      locvar_Product1_oh[loctmp_i_1 + 14 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        locvar_Product1_oh[loctmp_i_1 + 14 * loctmp_i_0] += locvar_P_kk1_m[14 *
          locvar_DataTypeConversion1 + loctmp_i_1] * loctmp_locvar_P_kk1_m[14 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* End of Product: '<S153>/Product1' */

  /* Product: '<S819>/Divide2' incorporates:
   *  Trigonometry: '<S819>/Trigonometric Function'
   *  Trigonometry: '<S819>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction4_ef = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S821>/Divide2' incorporates:
   *  Trigonometry: '<S821>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction2_ly = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S824>/Divide2' incorporates:
   *  Trigonometry: '<S824>/Trigonometric Function'
   *  Trigonometry: '<S824>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide2_op = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]);

  /* Product: '<S816>/Divide4' incorporates:
   *  Constant: '<S816>/Constant'
   *  Constant: '<S816>/Constant1'
   *  Math: '<S816>/Math Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_ch = ANN_EKF_NMPC_2_P.Constant_Value_gg *
    ANN_EKF_NMPC_2_P.rho_o * (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4]);

  /* Sum: '<S835>/Add' incorporates:
   *  Constant: '<S835>/Constant'
   *  Constant: '<S835>/Constant1'
   *  Constant: '<S835>/Constant10'
   *  Constant: '<S835>/Constant11'
   *  Constant: '<S835>/Constant12'
   *  Constant: '<S835>/Constant13'
   *  Constant: '<S835>/Constant14'
   *  Constant: '<S835>/Constant15'
   *  Constant: '<S835>/Constant2'
   *  Constant: '<S835>/Constant3'
   *  Constant: '<S835>/Constant4'
   *  Constant: '<S835>/Constant5'
   *  Constant: '<S835>/Constant6'
   *  Constant: '<S835>/Constant7'
   *  Constant: '<S835>/Constant8'
   *  Constant: '<S835>/Constant9'
   *  Gain: '<S835>/Gain1'
   *  Gain: '<S835>/Gain2'
   *  Gain: '<S835>/Gain3'
   *  Product: '<S835>/Divide1'
   *  Product: '<S835>/Divide2'
   *  Product: '<S835>/Divide3'
   *  Product: '<S835>/Divide4'
   *  Product: '<S835>/Divide5'
   *  Product: '<S835>/Divide6'
   *  Product: '<S835>/Divide7'
   *  Sum: '<S835>/Add1'
   *  Sum: '<S835>/Add2'
   *  Sum: '<S835>/Add3'
   *  Sum: '<S835>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S826>/Unit Delay'
   */
  locvar_Add_kq = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
                        ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CLq *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       (ANN_EKF_NMPC_2_P.CLa *
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] +
                        ANN_EKF_NMPC_2_P.CL0)) + ANN_EKF_NMPC_2_P.CLadot *
                      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_p *
                      (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.CLu / ANN_EKF_NMPC_2_P.Utrim *
                     (locvar_TrigonometricFunction4_ef - ANN_EKF_NMPC_2_P.Utrim))
                    + ANN_EKF_NMPC_2_P.CLde *
                    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                   ANN_EKF_NMPC_2_P.Utrim * (locvar_TrigonometricFunction4_ef -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                   ANN_EKF_NMPC_2_P.Gain2_Gain_pn *
                   ANN_EKF_NMPC_2_P.Gain1_Gain_pu) +
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CD1 * ANN_EKF_NMPC_2_P.Gain3_Gain_g1;

  /* ManualSwitch: '<S834>/Manual Switch' incorporates:
   *  Constant: '<S834>/AR'
   *  Constant: '<S834>/Constant15'
   *  Constant: '<S834>/Constant16'
   *  Constant: '<S834>/Constant17'
   *  Constant: '<S834>/Constant18'
   *  Constant: '<S834>/e'
   *  Math: '<S834>/Math Function'
   *  Product: '<S834>/Divide8'
   *  Product: '<S834>/Divide9'
   *  Sum: '<S834>/Add5'
   *  Sum: '<S834>/Add6'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_eo == 1) {
    locvar_Axb_e = ANN_EKF_NMPC_2_P.CDa * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]
      + ANN_EKF_NMPC_2_P.CD0;
  } else {
    locvar_Axb_e = locvar_Add_kq * locvar_Add_kq /
      ANN_EKF_NMPC_2_P.Constant15_Value_n / (ANN_EKF_NMPC_2_P.b /
      ANN_EKF_NMPC_2_P.Cbar) / ANN_EKF_NMPC_2_P.e_Value_c +
      ANN_EKF_NMPC_2_P.CD0_bar;
  }

  /* End of ManualSwitch: '<S834>/Manual Switch' */

  /* Sum: '<S834>/Add' incorporates:
   *  Constant: '<S834>/Constant1'
   *  Constant: '<S834>/Constant10'
   *  Constant: '<S834>/Constant11'
   *  Constant: '<S834>/Constant12'
   *  Constant: '<S834>/Constant13'
   *  Constant: '<S834>/Constant14'
   *  Constant: '<S834>/Constant2'
   *  Constant: '<S834>/Constant3'
   *  Constant: '<S834>/Constant4'
   *  Constant: '<S834>/Constant6'
   *  Constant: '<S834>/Constant7'
   *  Constant: '<S834>/Constant8'
   *  Constant: '<S834>/Constant9'
   *  Gain: '<S834>/Gain1'
   *  Gain: '<S834>/Gain2'
   *  Gain: '<S834>/Gain3'
   *  Product: '<S834>/Divide1'
   *  Product: '<S834>/Divide2'
   *  Product: '<S834>/Divide3'
   *  Product: '<S834>/Divide5'
   *  Product: '<S834>/Divide6'
   *  Product: '<S834>/Divide7'
   *  Sum: '<S834>/Add1'
   *  Sum: '<S834>/Add2'
   *  Sum: '<S834>/Add3'
   *  Sum: '<S834>/Add4'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S826>/Unit Delay'
   */
  locvar_Add2_db = ((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.CDq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + locvar_Axb_e) + ANN_EKF_NMPC_2_P.CDadot *
                       ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_p *
                       (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                      ANN_EKF_NMPC_2_P.CDu / ANN_EKF_NMPC_2_P.Utrim *
                      (locvar_TrigonometricFunction4_ef - ANN_EKF_NMPC_2_P.Utrim))
                     + ANN_EKF_NMPC_2_P.CDde *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
                    ANN_EKF_NMPC_2_P.Utrim * (locvar_TrigonometricFunction4_ef -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.CL1 *
                    ANN_EKF_NMPC_2_P.Gain2_Gain_le *
                    ANN_EKF_NMPC_2_P.Gain1_Gain_my) -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] - ANN_EKF_NMPC_2_P.alphatrim) *
    ANN_EKF_NMPC_2_P.CL1 * ANN_EKF_NMPC_2_P.Gain3_Gain_cy;

  /* ManualSwitch: '<S820>/Manual Switch' incorporates:
   *  Constant: '<S820>/Constant1'
   *  Constant: '<S828>/Constant'
   *  Constant: '<S846>/Constant'
   *  Constant: '<S846>/Constant1'
   *  Constant: '<S846>/Constant2'
   *  Math: '<S846>/Math Function'
   *  Product: '<S820>/Divide'
   *  Product: '<S820>/Divide5'
   *  Product: '<S843>/Divide3'
   *  Product: '<S843>/Divide5'
   *  Product: '<S846>/Divide1'
   *  Product: '<S846>/Divide2'
   *  Sum: '<S820>/Add'
   *  Sum: '<S843>/Add'
   *  Sum: '<S846>/Add'
   *  Trigonometry: '<S843>/Trigonometric Function'
   *  Trigonometry: '<S843>/Trigonometric Function3'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_nv == 1) {
    /* Gain: '<S846>/Gain' incorporates:
     *  UnitDelay: '<S146>/x_est_[0//0]'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Gain_Gain_e *
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];
    locvar_Axb_e = (((locvar_Gain_ar * locvar_Gain_ar * ANN_EKF_NMPC_2_P.xT2 +
                      ANN_EKF_NMPC_2_P.xT1 * locvar_Gain_ar) +
                     ANN_EKF_NMPC_2_P.xT0) + (sin
      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq - locvar_Add2_db *
      cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) * (locvar_Divide4_ch *
      ANN_EKF_NMPC_2_P.S)) / (ANN_EKF_NMPC_2_P.weight / ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_Axb_e = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4];
  }

  /* End of ManualSwitch: '<S820>/Manual Switch' */

  /* Sum: '<S820>/Add1' incorporates:
   *  Constant: '<S820>/Constant'
   *  Product: '<S820>/Divide2'
   *  Product: '<S820>/Divide3'
   *  Product: '<S820>/Divide4'
   *  Trigonometry: '<S820>/Trigonometric Function'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_TrigonometricFunction_m2 = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
    locvar_TrigonometricFunction2_ly - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
    locvar_Divide2_op) - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
    ANN_EKF_NMPC_2_P.g) + locvar_Axb_e;

  /* ManualSwitch: '<S823>/Manual Switch' incorporates:
   *  Constant: '<S823>/Constant1'
   *  Constant: '<S828>/Constant'
   *  Constant: '<S836>/Constant'
   *  Constant: '<S836>/Constant1'
   *  Constant: '<S836>/Constant10'
   *  Constant: '<S836>/Constant11'
   *  Constant: '<S836>/Constant12'
   *  Constant: '<S836>/Constant2'
   *  Constant: '<S836>/Constant3'
   *  Constant: '<S836>/Constant4'
   *  Constant: '<S836>/Constant5'
   *  Constant: '<S836>/Constant6'
   *  Constant: '<S836>/Constant8'
   *  Product: '<S823>/Divide'
   *  Product: '<S823>/Divide5'
   *  Product: '<S836>/Divide1'
   *  Product: '<S836>/Divide3'
   *  Product: '<S836>/Divide4'
   *  Product: '<S836>/Divide5'
   *  Product: '<S836>/Divide6'
   *  Sum: '<S836>/Add'
   *  Sum: '<S836>/Add1'
   *  Sum: '<S836>/Add2'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_lv == 1) {
    locvar_Ayb_k = (((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                        ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cyp *
                       (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                       ANN_EKF_NMPC_2_P.Cyb *
                       ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                      (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                       ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Cyr *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                     ANN_EKF_NMPC_2_P.Cyda *
                     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) +
                    ANN_EKF_NMPC_2_P.Cydr * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [3]) * (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S) /
      (ANN_EKF_NMPC_2_P.weight / ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_Ayb_k = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5];
  }

  /* End of ManualSwitch: '<S823>/Manual Switch' */

  /* Sum: '<S823>/Add1' incorporates:
   *  Constant: '<S823>/Constant'
   *  Product: '<S823>/Divide2'
   *  Product: '<S823>/Divide3'
   *  Product: '<S823>/Divide4'
   *  Trigonometry: '<S823>/Trigonometric Function'
   *  Trigonometry: '<S823>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_ai = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] * locvar_Divide2_op
                     - ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
                     locvar_TrigonometricFunction4_ef) + sin
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                    ANN_EKF_NMPC_2_P.g) + locvar_Ayb_k;

  /* Product: '<S822>/Divide4' */
  locvar_Divide4_c1v = locvar_TrigonometricFunction2_ly * locvar_Add2_ai;

  /* ManualSwitch: '<S825>/Manual Switch' incorporates:
   *  Constant: '<S825>/Constant1'
   *  Constant: '<S828>/Constant'
   *  Product: '<S825>/Divide'
   *  Product: '<S825>/Divide5'
   *  Product: '<S845>/Divide1'
   *  Product: '<S845>/Divide6'
   *  Sum: '<S845>/Add2'
   *  Trigonometry: '<S845>/Trigonometric Function4'
   *  Trigonometry: '<S845>/Trigonometric Function5'
   *  UnitDelay: '<S146>/Unit Delay1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  if (ANN_EKF_NMPC_2_P.ManualSwitch_CurrentSetting_nqm == 1) {
    locvar_Azb_h = ((0.0 - locvar_Add2_db * sin
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])) - cos
                    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add_kq) *
      (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S) / (ANN_EKF_NMPC_2_P.weight /
      ANN_EKF_NMPC_2_P.g);
  } else {
    locvar_Azb_h = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6];
  }

  /* End of ManualSwitch: '<S825>/Manual Switch' */

  /* Sum: '<S825>/Add1' incorporates:
   *  Constant: '<S825>/Constant'
   *  Product: '<S825>/Divide2'
   *  Product: '<S825>/Divide3'
   *  Product: '<S825>/Divide4'
   *  Trigonometry: '<S825>/Trigonometric Function'
   *  Trigonometry: '<S825>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide4_dh = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] *
                        locvar_TrigonometricFunction4_ef -
                        ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
                        locvar_TrigonometricFunction2_ly) + cos
                       (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) * cos
                       (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]) *
                       ANN_EKF_NMPC_2_P.g) + locvar_Azb_h;

  /* Product: '<S822>/Divide5' */
  locvar_Add_kq = locvar_Divide2_op * locvar_Divide4_dh;

  /* Product: '<S826>/Divide' incorporates:
   *  Math: '<S826>/Math Function'
   *  Math: '<S826>/Math Function1'
   *  Product: '<S826>/Divide3'
   *  Product: '<S826>/Divide4'
   *  Sum: '<S826>/Add'
   *  Sum: '<S826>/Add1'
   */
  locvar_Divide_ow = (locvar_TrigonometricFunction4_ef * locvar_Divide4_dh -
                      locvar_Divide2_op * locvar_TrigonometricFunction_m2) /
    (locvar_TrigonometricFunction4_ef * locvar_TrigonometricFunction4_ef +
     locvar_Divide2_op * locvar_Divide2_op);

  /* Product: '<S827>/Divide3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_db = ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_Add2_ai;

  /* Product: '<S827>/Divide4' incorporates:
   *  Product: '<S827>/Divide1'
   *  Product: '<S827>/Divide2'
   *  Product: '<S827>/Divide5'
   *  Product: '<S827>/Divide6'
   *  Sum: '<S827>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Gain_ar = ((locvar_TrigonometricFunction4_ef *
                     locvar_TrigonometricFunction_m2 +
                     locvar_TrigonometricFunction2_ly * locvar_Add2_ai) +
                    locvar_Divide2_op * locvar_Divide4_dh) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * locvar_TrigonometricFunction2_ly;

  /* Sum: '<S856>/Add' incorporates:
   *  Constant: '<S856>/Ixx1'
   *  Constant: '<S856>/Ixz1'
   *  Constant: '<S856>/Izz1'
   *  Math: '<S856>/Math Function'
   *  Product: '<S856>/Divide1'
   */
  locvar_Add2_ai = ANN_EKF_NMPC_2_P.IxxB * ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB;

  /* Product: '<S848>/Divide4' incorporates:
   *  Constant: '<S848>/Ixx'
   *  Constant: '<S848>/Ixz'
   *  Constant: '<S848>/Iyy'
   *  Constant: '<S848>/Izz'
   *  Product: '<S848>/Divide3'
   *  Sum: '<S848>/Add'
   */
  locvar_Divide4_dh = ((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) +
                       ANN_EKF_NMPC_2_P.IzzB) * ANN_EKF_NMPC_2_P.IxzB /
    locvar_Add2_ai;

  /* Sum: '<S838>/Add' incorporates:
   *  Constant: '<S838>/Constant10'
   *  Constant: '<S838>/Constant11'
   *  Constant: '<S838>/Constant12'
   *  Constant: '<S838>/Constant13'
   *  Constant: '<S838>/Constant14'
   *  Constant: '<S838>/Constant15'
   *  Constant: '<S838>/Constant5'
   *  Constant: '<S838>/Constant6'
   *  Constant: '<S838>/Constant7'
   *  Constant: '<S838>/Constant8'
   *  Constant: '<S838>/Constant9'
   *  Product: '<S838>/Divide3'
   *  Product: '<S838>/Divide4'
   *  Product: '<S838>/Divide5'
   *  Product: '<S838>/Divide6'
   *  Product: '<S838>/Divide7'
   *  Sum: '<S838>/Add1'
   *  Sum: '<S838>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_fi = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Clp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Clb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Clr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Clda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cldr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S842>/Add' incorporates:
   *  Constant: '<S842>/Constant'
   *  Constant: '<S842>/Constant10'
   *  Constant: '<S842>/Constant11'
   *  Constant: '<S842>/Constant12'
   *  Constant: '<S842>/Constant13'
   *  Constant: '<S842>/Constant14'
   *  Constant: '<S842>/Constant15'
   *  Constant: '<S842>/Constant5'
   *  Constant: '<S842>/Constant6'
   *  Constant: '<S842>/Constant8'
   *  Constant: '<S842>/Constant9'
   *  Product: '<S842>/Divide3'
   *  Product: '<S842>/Divide4'
   *  Product: '<S842>/Divide5'
   *  Product: '<S842>/Divide6'
   *  Product: '<S842>/Divide7'
   *  Sum: '<S842>/Add1'
   *  Sum: '<S842>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_ap = ((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
                       ANN_EKF_NMPC_2_P.Ptrim) * ANN_EKF_NMPC_2_P.Cnp *
                      (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim +
                      ANN_EKF_NMPC_2_P.Cnb *
                      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) +
                     (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
                      ANN_EKF_NMPC_2_P.Rtrim) * ANN_EKF_NMPC_2_P.Cnr *
                     (ANN_EKF_NMPC_2_P.b / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
                    ANN_EKF_NMPC_2_P.Cnda * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p
                    [2]) + ANN_EKF_NMPC_2_P.Cndr *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];

  /* Sum: '<S837>/Add' incorporates:
   *  Product: '<S837>/Divide3'
   *  Product: '<S837>/Divide5'
   *  Trigonometry: '<S837>/Trigonometric Function'
   *  Trigonometry: '<S837>/Trigonometric Function3'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add_eqw = locvar_Add2_fi * cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])
    - sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add2_ap;

  /* Product: '<S850>/Divide4' incorporates:
   *  Constant: '<S850>/Ixz'
   */
  locvar_Divide4_ky = ANN_EKF_NMPC_2_P.IxzB / locvar_Add2_ai;

  /* Sum: '<S841>/Add2' incorporates:
   *  Product: '<S841>/Divide1'
   *  Product: '<S841>/Divide6'
   *  Trigonometry: '<S841>/Trigonometric Function4'
   *  Trigonometry: '<S841>/Trigonometric Function5'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Add2_fi = locvar_Add2_fi * sin(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5])
    + cos(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5]) * locvar_Add2_ap;

  /* Saturate: '<S812>/Throttle Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] > ANN_EKF_NMPC_2_P.ThrottleMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] <
             ANN_EKF_NMPC_2_P.ThrottleMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ThrottleMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0];
  }

  /* Sum: '<S148>/Subtract1' incorporates:
   *  Gain: '<S148>/Gain4'
   *  Gain: '<S812>/Gain'
   *  Gain: '<S812>/Gain1'
   *  Saturate: '<S812>/Throttle Limiter'
   *  Sum: '<S812>/Add'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide1_gv[0] = (ANN_EKF_NMPC_2_P.Bthrottle * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Athrottle * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0]) *
    ANN_EKF_NMPC_2_P.dt + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0];

  /* Saturate: '<S812>/Elevator Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] > ANN_EKF_NMPC_2_P.ElevatorMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] <
             ANN_EKF_NMPC_2_P.ElevatorMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.ElevatorMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1];
  }

  /* Sum: '<S148>/Subtract1' incorporates:
   *  Gain: '<S148>/Gain4'
   *  Gain: '<S812>/Gain2'
   *  Gain: '<S812>/Gain3'
   *  Saturate: '<S812>/Elevator Limiter'
   *  Sum: '<S812>/Add1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide1_gv[1] = (ANN_EKF_NMPC_2_P.Belevator * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aelevator * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) *
    ANN_EKF_NMPC_2_P.dt + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1];

  /* Saturate: '<S812>/Aileron Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] > ANN_EKF_NMPC_2_P.AileronMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] <
             ANN_EKF_NMPC_2_P.AileronMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.AileronMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2];
  }

  /* Sum: '<S148>/Subtract1' incorporates:
   *  Gain: '<S148>/Gain4'
   *  Gain: '<S812>/Gain4'
   *  Gain: '<S812>/Gain5'
   *  Saturate: '<S812>/Aileron Limiter'
   *  Sum: '<S812>/Add2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide1_gv[2] = (ANN_EKF_NMPC_2_P.Baileron * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Aaileron * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2]) *
    ANN_EKF_NMPC_2_P.dt + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[2];

  /* Saturate: '<S812>/Rudder Limiter' incorporates:
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] > ANN_EKF_NMPC_2_P.RudderMax) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMax;
  } else if (ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] <
             ANN_EKF_NMPC_2_P.RudderMin) {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_P.RudderMin;
  } else {
    loctmp_tmp_7 = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3];
  }

  /* Sum: '<S148>/Subtract1' incorporates:
   *  Gain: '<S148>/Gain4'
   *  Gain: '<S812>/Gain6'
   *  Gain: '<S812>/Gain7'
   *  Math: '<S827>/Math Function'
   *  Math: '<S827>/Math Function1'
   *  Product: '<S822>/Divide'
   *  Product: '<S822>/Divide3'
   *  Product: '<S827>/Divide'
   *  Saturate: '<S812>/Rudder Limiter'
   *  Sum: '<S812>/Add3'
   *  Sum: '<S822>/Add'
   *  Sum: '<S827>/Add'
   *  Sum: '<S827>/Add1'
   *  Trigonometry: '<S827>/Trigonometric Function1'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Divide1_gv[3] = (ANN_EKF_NMPC_2_P.Brudder * loctmp_tmp_7 +
    ANN_EKF_NMPC_2_P.Arudder * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3]) *
    ANN_EKF_NMPC_2_P.dt + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[3];
  locvar_Divide1_gv[4] = ((locvar_TrigonometricFunction4_ef *
    locvar_TrigonometricFunction_m2 + locvar_Divide4_c1v) + locvar_Add_kq) /
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4] * ANN_EKF_NMPC_2_P.dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[4];
  locvar_Divide1_gv[5] = ANN_EKF_NMPC_2_P.dt * locvar_Divide_ow +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5];
  locvar_Divide1_gv[6] = (locvar_Add2_db - locvar_Gain_ar) /
    (locvar_TrigonometricFunction4_ef * locvar_TrigonometricFunction4_ef +
     locvar_Divide2_op * locvar_Divide2_op) * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6]) * ANN_EKF_NMPC_2_P.dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[6];

  /* Trigonometry: '<S830>/Trigonometric Function3' incorporates:
   *  UnitDelay: '<S146>/x_est_[0//0]'
   */
  locvar_Delay100dt = tan(ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8]);

  /* Saturate: '<S830>/Saturation' */
  if (locvar_Delay100dt > ANN_EKF_NMPC_2_P.Saturation_UpperSat_c) {
    locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_UpperSat_c;
  } else {
    if (locvar_Delay100dt < ANN_EKF_NMPC_2_P.Saturation_LowerSat_f) {
      locvar_Delay100dt = ANN_EKF_NMPC_2_P.Saturation_LowerSat_f;
    }
  }

  /* Sum: '<S148>/Subtract1' incorporates:
   *  Constant: '<S815>/Constant1'
   *  Constant: '<S815>/Constant2'
   *  Constant: '<S817>/Constant1'
   *  Constant: '<S817>/Constant2'
   *  Constant: '<S818>/Constant1'
   *  Constant: '<S818>/Constant2'
   *  Constant: '<S831>/Constant'
   *  Constant: '<S832>/Constant'
   *  Constant: '<S840>/Constant'
   *  Constant: '<S840>/Constant1'
   *  Constant: '<S840>/Constant11'
   *  Constant: '<S840>/Constant12'
   *  Constant: '<S840>/Constant13'
   *  Constant: '<S840>/Constant14'
   *  Constant: '<S840>/Constant2'
   *  Constant: '<S840>/Constant3'
   *  Constant: '<S840>/Constant4'
   *  Constant: '<S840>/Constant5'
   *  Constant: '<S840>/Constant6'
   *  Constant: '<S840>/Constant7'
   *  Constant: '<S840>/Constant8'
   *  Constant: '<S840>/Constant9'
   *  Constant: '<S847>/Ixz'
   *  Constant: '<S847>/Iyy'
   *  Constant: '<S847>/Izz'
   *  Constant: '<S849>/Izz'
   *  Constant: '<S851>/Ixx'
   *  Constant: '<S851>/Iyy'
   *  Constant: '<S851>/Izz'
   *  Constant: '<S852>/Ixz'
   *  Constant: '<S852>/Iyy'
   *  Constant: '<S853>/Ixz'
   *  Constant: '<S853>/Iyy'
   *  Constant: '<S854>/Ixx'
   *  Constant: '<S854>/Ixx1'
   *  Constant: '<S854>/Ixz'
   *  Constant: '<S854>/Iyy'
   *  Constant: '<S855>/Ixx'
   *  Gain: '<S148>/Gain4'
   *  Gain: '<S840>/Gain1'
   *  Gain: '<S840>/Gain2'
   *  Math: '<S817>/Math Function'
   *  Math: '<S817>/Math Function1'
   *  Math: '<S847>/Math Function'
   *  Math: '<S854>/Math Function'
   *  Product: '<S815>/Divide'
   *  Product: '<S815>/Divide1'
   *  Product: '<S815>/Divide2'
   *  Product: '<S815>/Divide3'
   *  Product: '<S815>/Divide4'
   *  Product: '<S815>/Divide5'
   *  Product: '<S815>/Divide6'
   *  Product: '<S817>/Divide'
   *  Product: '<S817>/Divide2'
   *  Product: '<S817>/Divide3'
   *  Product: '<S817>/Divide5'
   *  Product: '<S817>/Divide6'
   *  Product: '<S818>/Divide'
   *  Product: '<S818>/Divide1'
   *  Product: '<S818>/Divide2'
   *  Product: '<S818>/Divide3'
   *  Product: '<S818>/Divide4'
   *  Product: '<S818>/Divide5'
   *  Product: '<S818>/Divide6'
   *  Product: '<S830>/Divide1'
   *  Product: '<S830>/Divide2'
   *  Product: '<S830>/Divide4'
   *  Product: '<S833>/Divide2'
   *  Product: '<S833>/Divide4'
   *  Product: '<S840>/Divide1'
   *  Product: '<S840>/Divide2'
   *  Product: '<S840>/Divide3'
   *  Product: '<S840>/Divide4'
   *  Product: '<S840>/Divide5'
   *  Product: '<S840>/Divide6'
   *  Product: '<S847>/Divide3'
   *  Product: '<S847>/Divide4'
   *  Product: '<S849>/Divide4'
   *  Product: '<S851>/Divide4'
   *  Product: '<S852>/Divide4'
   *  Product: '<S853>/Divide4'
   *  Product: '<S854>/Divide3'
   *  Product: '<S854>/Divide4'
   *  Product: '<S855>/Divide4'
   *  Saturate: '<S830>/Saturation'
   *  Sum: '<S815>/Add'
   *  Sum: '<S815>/Add1'
   *  Sum: '<S815>/Add2'
   *  Sum: '<S817>/Add1'
   *  Sum: '<S817>/Add3'
   *  Sum: '<S818>/Add'
   *  Sum: '<S818>/Add1'
   *  Sum: '<S818>/Add2'
   *  Sum: '<S830>/Add'
   *  Sum: '<S830>/Add1'
   *  Sum: '<S833>/Add'
   *  Sum: '<S840>/Add'
   *  Sum: '<S840>/Add1'
   *  Sum: '<S840>/Add2'
   *  Sum: '<S840>/Add3'
   *  Sum: '<S847>/Add'
   *  Sum: '<S847>/Add1'
   *  Sum: '<S851>/Add'
   *  Sum: '<S854>/Add'
   *  Sum: '<S854>/Add1'
   *  Trigonometry: '<S830>/Trigonometric Function1'
   *  Trigonometry: '<S830>/Trigonometric Function2'
   *  Trigonometry: '<S833>/Trigonometric Function1'
   *  Trigonometry: '<S833>/Trigonometric Function2'
   *  UnitDelay: '<S146>/x_est_[0//0]'
   *  UnitDelay: '<S826>/Unit Delay'
   */
  locvar_Divide1_gv[7] = ((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) + sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10]) * locvar_Delay100dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) * ANN_EKF_NMPC_2_P.dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7];
  locvar_Divide1_gv[8] = (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] * cos
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) - sin
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[7]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * ANN_EKF_NMPC_2_P.dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[8];
  locvar_Divide1_gv[9] = ((((ANN_EKF_NMPC_2_P.IyyB - ANN_EKF_NMPC_2_P.IzzB) *
    ANN_EKF_NMPC_2_P.IzzB - ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB) /
    locvar_Add2_ai * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] + locvar_Divide4_dh
    * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IzzB /
    locvar_Add2_ai * locvar_Add_eqw + locvar_Divide4_ky * locvar_Add2_fi) *
    (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.b)) *
    ANN_EKF_NMPC_2_P.dt + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9];
  locvar_Divide1_gv[10] = (((((((ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] -
    ANN_EKF_NMPC_2_P.Qtrim) * ANN_EKF_NMPC_2_P.Cmq * (ANN_EKF_NMPC_2_P.Cbar /
    2.0) / ANN_EKF_NMPC_2_P.Utrim + (ANN_EKF_NMPC_2_P.Cma *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[5] + ANN_EKF_NMPC_2_P.Cm0)) +
    ANN_EKF_NMPC_2_P.Cmadot * ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_p *
    (ANN_EKF_NMPC_2_P.Cbar / 2.0) / ANN_EKF_NMPC_2_P.Utrim) +
    ANN_EKF_NMPC_2_P.Cmu / ANN_EKF_NMPC_2_P.Utrim *
    (locvar_TrigonometricFunction4_ef - ANN_EKF_NMPC_2_P.Utrim)) +
    ANN_EKF_NMPC_2_P.Cmde * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[1]) + 1.0 /
    ANN_EKF_NMPC_2_P.Utrim * (locvar_TrigonometricFunction4_ef -
    ANN_EKF_NMPC_2_P.Utrim) * ANN_EKF_NMPC_2_P.Cm1 *
    ANN_EKF_NMPC_2_P.Gain2_Gain_fv * ANN_EKF_NMPC_2_P.Gain1_Gain_mq) *
    (ANN_EKF_NMPC_2_P.Ixz_Value_f / ANN_EKF_NMPC_2_P.IyyB) * (locvar_Divide4_ch *
    ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.Cbar) + ((ANN_EKF_NMPC_2_P.IzzB -
    ANN_EKF_NMPC_2_P.IxxB) / ANN_EKF_NMPC_2_P.IyyB *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] -
    (ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] -
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11] *
     ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) * (ANN_EKF_NMPC_2_P.IxzB /
    ANN_EKF_NMPC_2_P.IyyB))) * ANN_EKF_NMPC_2_P.dt +
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10];
  locvar_Divide1_gv[11] = ((((ANN_EKF_NMPC_2_P.IxxB - ANN_EKF_NMPC_2_P.IyyB) *
    ANN_EKF_NMPC_2_P.IxxB + ANN_EKF_NMPC_2_P.IxzB * ANN_EKF_NMPC_2_P.IxzB) /
    locvar_Add2_ai * ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[9] - locvar_Divide4_dh *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11]) *
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[10] + (ANN_EKF_NMPC_2_P.IxxB /
    locvar_Add2_ai * locvar_Add2_fi + locvar_Divide4_ky * locvar_Add_eqw) *
    (locvar_Divide4_ch * ANN_EKF_NMPC_2_P.S * ANN_EKF_NMPC_2_P.b)) *
    ANN_EKF_NMPC_2_P.dt + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[11];
  locvar_Divide1_gv[12] = ANN_EKF_NMPC_2_P.dt *
    ANN_EKF_NMPC_2_P.Constant_Value_fn + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[12];
  locvar_Divide1_gv[13] = ANN_EKF_NMPC_2_P.dt *
    ANN_EKF_NMPC_2_P.Constant_Value_lm + ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[13];

  /* Sum: '<S146>/Subtract' incorporates:
   *  Inport: '<Root>/Body Rates meas'
   *  Inport: '<Root>/Euler Angles meas'
   *  Inport: '<Root>/VT, alpha, beta meas'
   *  Sum: '<S857>/Subtract1'
   *  Sum: '<S857>/Subtract2'
   */
  loctmp_tmp_5[0] = ANN_EKF_NMPC_2_U.VTalphabetameas.VT;
  loctmp_tmp_5[1] = ANN_EKF_NMPC_2_U.VTalphabetameas.alpha;
  loctmp_tmp_5[2] = ANN_EKF_NMPC_2_U.VTalphabetameas.beta;
  loctmp_tmp_5[3] = ANN_EKF_NMPC_2_U.EulerAnglesmeas.phi;
  loctmp_tmp_5[4] = ANN_EKF_NMPC_2_U.EulerAnglesmeas.theta;
  loctmp_tmp_5[5] = ANN_EKF_NMPC_2_U.BodyRatesmeas.P;
  loctmp_tmp_5[6] = ANN_EKF_NMPC_2_U.BodyRatesmeas.Q;
  loctmp_tmp_5[7] = ANN_EKF_NMPC_2_U.BodyRatesmeas.R;
  loctmp_locvar_Divide1_h5[0] = locvar_Divide1_gv[4];
  loctmp_locvar_Divide1_h5[1] = locvar_Divide1_gv[5] + locvar_Divide1_gv[12];
  loctmp_locvar_Divide1_h5[2] = locvar_Divide1_gv[6] + locvar_Divide1_gv[13];
  for (loctmp_i_1 = 0; loctmp_i_1 < 5; loctmp_i_1++) {
    loctmp_locvar_Divide1_h5[loctmp_i_1 + 3] = locvar_Divide1_gv[7 + loctmp_i_1];
  }

  /* Product: '<S146>/Product1' incorporates:
   *  Sum: '<S146>/Subtract'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 8; loctmp_i_1++) {
    loctmp_tmp_6[loctmp_i_1] = loctmp_tmp_5[loctmp_i_1] -
      loctmp_locvar_Divide1_h5[loctmp_i_1];
  }

  /* Sum: '<S146>/Subtract1' incorporates:
   *  Inport: '<Root>/Enable//Disable'
   *  Product: '<S146>/Product'
   *  Product: '<S146>/Product1'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    loctmp_tmp_7 = 0.0;
    for (loctmp_i_0 = 0; loctmp_i_0 < 8; loctmp_i_0++) {
      loctmp_tmp_7 += locvar_Product1_oh[14 * loctmp_i_0 + loctmp_i_1] * (real_T)
        ANN_EKF_NMPC_2_U.EnableDisable * loctmp_tmp_6[loctmp_i_0];
    }

    locvar_Reshape1[loctmp_i_1] = loctmp_tmp_7 + locvar_Divide1_gv[loctmp_i_1];
  }

  /* End of Sum: '<S146>/Subtract1' */

  /* BusCreator: '<S145>/Bus Creator1' incorporates:
   *  Inport: '<Root>/Euler Angles meas'
   */
  loctmp_locvar_BusCreator1_psi = ANN_EKF_NMPC_2_U.EulerAnglesmeas.psi;

  /* Product: '<S142>/Divide2' incorporates:
   *  BusCreator: '<S145>/Bus Creator'
   *  Trigonometry: '<S142>/Trigonometric Function'
   *  Trigonometry: '<S142>/Trigonometric Function1'
   */
  locvar_Divide2_em = locvar_Reshape1[4] * cos(locvar_Reshape1[5]) * cos
    (locvar_Reshape1[6]);

  /* Trigonometry: '<S141>/Trigonometric Function4' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   *  Inport: '<Root>/Euler Angles meas'
   */
  locvar_Divide2_ic = cos(ANN_EKF_NMPC_2_U.EulerAnglesmeas.psi);

  /* Product: '<S141>/Divide3' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   *  Trigonometry: '<S141>/Trigonometric Function1'
   */
  locvar_Divide3_ik = locvar_Divide2_em * cos(locvar_Reshape1[8]) *
    locvar_Divide2_ic;

  /* Trigonometry: '<S141>/Trigonometric Function5' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   */
  locvar_TrigonometricFunction3_p = cos(locvar_Reshape1[7]);

  /* Trigonometry: '<S141>/Trigonometric Function3' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   *  Inport: '<Root>/Euler Angles meas'
   */
  locvar_TrigonometricFunction5_h0 = sin(ANN_EKF_NMPC_2_U.EulerAnglesmeas.psi);

  /* Product: '<S141>/Divide4' */
  locvar_Divide4_ii = locvar_TrigonometricFunction3_p *
    locvar_TrigonometricFunction5_h0;

  /* Trigonometry: '<S141>/Trigonometric Function2' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   */
  locvar_TrigonometricFunction4_ef = sin(locvar_Reshape1[8]);

  /* Trigonometry: '<S141>/Trigonometric Function' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   */
  locvar_TrigonometricFunction2_ly = sin(locvar_Reshape1[7]);

  /* Product: '<S141>/Divide2' */
  locvar_Divide2_h2o = locvar_TrigonometricFunction4_ef *
    locvar_TrigonometricFunction2_ly * locvar_Divide2_ic;

  /* Product: '<S143>/Divide2' incorporates:
   *  BusCreator: '<S145>/Bus Creator'
   *  Trigonometry: '<S143>/Trigonometric Function1'
   */
  locvar_Divide2_op = locvar_Reshape1[4] * sin(locvar_Reshape1[6]);

  /* Product: '<S141>/Divide6' */
  locvar_Divide6_d5 = locvar_TrigonometricFunction2_ly *
    locvar_TrigonometricFunction5_h0;

  /* Product: '<S141>/Divide5' */
  locvar_Divide5_cg1 = locvar_TrigonometricFunction4_ef *
    locvar_TrigonometricFunction3_p * locvar_Divide2_ic;

  /* Product: '<S144>/Divide2' incorporates:
   *  BusCreator: '<S145>/Bus Creator'
   *  Trigonometry: '<S144>/Trigonometric Function'
   *  Trigonometry: '<S144>/Trigonometric Function1'
   */
  locvar_Divide2_ic = locvar_Reshape1[4] * sin(locvar_Reshape1[5]) * cos
    (locvar_Reshape1[6]);

  /* Trigonometry: '<S139>/Trigonometric Function3' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   *  Inport: '<Root>/Euler Angles meas'
   */
  locvar_TrigonometricFunction3_p = sin(ANN_EKF_NMPC_2_U.EulerAnglesmeas.psi);

  /* Trigonometry: '<S139>/Trigonometric Function5' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   */
  locvar_TrigonometricFunction5_h0 = cos(locvar_Reshape1[7]);

  /* Trigonometry: '<S139>/Trigonometric Function4' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   *  Inport: '<Root>/Euler Angles meas'
   */
  locvar_TrigonometricFunction4_ef = cos(ANN_EKF_NMPC_2_U.EulerAnglesmeas.psi);

  /* Trigonometry: '<S139>/Trigonometric Function2' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   */
  locvar_TrigonometricFunction2_ly = sin(locvar_Reshape1[8]);

  /* Trigonometry: '<S139>/Trigonometric Function' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   */
  locvar_TrigonometricFunction_m2 = sin(locvar_Reshape1[7]);

  /* Delay: '<Root>/Delay 100 dt' incorporates:
   *  Inport: '<Root>/FL_ann'
   */
  //loctmp_zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
   // &ANN_EKF_NMPC_2_PrevZCX.Delay100dt_Reset_ZCE,
    //                        (ANN_EKF_NMPC_2_U.FL_ann));
  if (loctmp_zcEvent != NO_ZCEVENT) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 100; loctmp_i_0++) {
      ANN_EKF_NMPC_2_DW.Delay100dt_DSTATE[loctmp_i_0] =
        ANN_EKF_NMPC_2_P.Delay100dt_InitialCondition;
    }
  }

  locvar_Delay100dt = ANN_EKF_NMPC_2_DW.Delay100dt_DSTATE[0];

  /* End of Delay: '<Root>/Delay 100 dt' */

  /* Outputs for Enabled SubSystem: '<Root>/ANN (subsystem)' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* Inport: '<Root>/FL_ann' */
  if (ANN_EKF_NMPC_2_U.FL_ann > 0.0) {
    /* DiscreteFilter: '<S7>/Discrete Filter' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     */
    locvar_Add1_ob = (locvar_Reshape1[5] -
                      ANN_EKF_NMPC_2_P.DiscreteFilter_DenCoef[1] *
                      ANN_EKF_NMPC_2_DW.DiscreteFilter_states) /
      ANN_EKF_NMPC_2_P.DiscreteFilter_DenCoef[0];
    ANN_EKF_NMPC_2_B.alphadot = ANN_EKF_NMPC_2_P.DiscreteFilter_NumCoef[0] *
      locvar_Add1_ob + ANN_EKF_NMPC_2_P.DiscreteFilter_NumCoef[1] *
      ANN_EKF_NMPC_2_DW.DiscreteFilter_states;

    /* DiscreteFilter: '<S7>/Discrete Filter1' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     */
    locvar_Add_pii = (locvar_Reshape1[6] -
                      ANN_EKF_NMPC_2_P.DiscreteFilter1_DenCoef[1] *
                      ANN_EKF_NMPC_2_DW.DiscreteFilter1_states) /
      ANN_EKF_NMPC_2_P.DiscreteFilter1_DenCoef[0];
    ANN_EKF_NMPC_2_B.betadot = ANN_EKF_NMPC_2_P.DiscreteFilter1_NumCoef[0] *
      locvar_Add_pii + ANN_EKF_NMPC_2_P.DiscreteFilter1_NumCoef[1] *
      ANN_EKF_NMPC_2_DW.DiscreteFilter1_states;

    /* MATLAB Function: '<S7>/ANN Inputs-Outputs Normalization' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *  BusCreator: '<S145>/Bus Creator2'
     *  DataStoreRead: '<S7>/Data Store Read1'
     *  DataStoreRead: '<S7>/Data Store Read2'
     *  DataStoreRead: '<S7>/Data Store Read3'
     *  DataStoreRead: '<S7>/Data Store Read4'
     *  DataStoreRead: '<S7>/Data Store Read5'
     *  DataStoreRead: '<S7>/Data Store Read6'
     *  Inport: '<Root>/Accelerometer meas'
     *  Inport: '<Root>/Servo Commands'
     */
    /* MATLAB Function 'ANN (subsystem)/Normalization/ANN Inputs-Outputs Normalization': '<S11>:1' */
    /* %allocation */
    /* '<S11>:1:21' */
    /* '<S11>:1:22' */
    /* '<S11>:1:23' */
    /* %normalization */
    /* %allocation */
    /* %normalization values */
    /* %X-axis */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.X_maxYin - ANN_EKF_NMPC_2_P.X_minYin;
    locvar_y_ann_X_out[0] = (locvar_Reshape1[4] - ANN_EKF_NMPC_2_P.X_minXin[0]) *
      locvar_Gain_ar / (ANN_EKF_NMPC_2_P.X_maxXin[0] -
                        ANN_EKF_NMPC_2_P.X_minXin[0]) +
      ANN_EKF_NMPC_2_P.X_minYin;
    locvar_y_ann_X_out[1] = (locvar_Reshape1[5] - ANN_EKF_NMPC_2_P.X_minXin[1]) *
      locvar_Gain_ar / (ANN_EKF_NMPC_2_P.X_maxXin[1] -
                        ANN_EKF_NMPC_2_P.X_minXin[1]) +
      ANN_EKF_NMPC_2_P.X_minYin;
    locvar_y_ann_X_out[2] = (locvar_Reshape1[6] - ANN_EKF_NMPC_2_P.X_minXin[2]) *
      locvar_Gain_ar / (ANN_EKF_NMPC_2_P.X_maxXin[2] -
                        ANN_EKF_NMPC_2_P.X_minXin[2]) +
      ANN_EKF_NMPC_2_P.X_minYin;
    locvar_y_ann_X_out[3] = (locvar_Reshape1[10] - ANN_EKF_NMPC_2_P.X_minXin[3])
      * locvar_Gain_ar / (ANN_EKF_NMPC_2_P.X_maxXin[3] -
                          ANN_EKF_NMPC_2_P.X_minXin[3]) +
      ANN_EKF_NMPC_2_P.X_minYin;
    locvar_y_ann_X_out[4] = (ANN_EKF_NMPC_2_B.alphadot -
      ANN_EKF_NMPC_2_P.X_minXin[4]) * locvar_Gain_ar /
      (ANN_EKF_NMPC_2_P.X_maxXin[4] - ANN_EKF_NMPC_2_P.X_minXin[4]) +
      ANN_EKF_NMPC_2_P.X_minYin;
    locvar_y_ann_X_out[5] = (ANN_EKF_NMPC_2_U.ServoCommands.throttle_cmd -
      ANN_EKF_NMPC_2_P.X_minXin[5]) * locvar_Gain_ar /
      (ANN_EKF_NMPC_2_P.X_maxXin[5] - ANN_EKF_NMPC_2_P.X_minXin[5]) +
      ANN_EKF_NMPC_2_P.X_minYin;
    locvar_y_ann_X_out[6] = (ANN_EKF_NMPC_2_U.ServoCommands.elevator_cmd -
      ANN_EKF_NMPC_2_P.X_minXin[6]) * locvar_Gain_ar /
      (ANN_EKF_NMPC_2_P.X_maxXin[6] - ANN_EKF_NMPC_2_P.X_minXin[6]) +
      ANN_EKF_NMPC_2_P.X_minYin;

    /* %Y-axis                 */
    loctmp_b_b = ANN_EKF_NMPC_2_P.Y_maxYin - ANN_EKF_NMPC_2_P.Y_minYin;
    locvar_y_ann_Y_out[0] = (locvar_Reshape1[4] - ANN_EKF_NMPC_2_P.Y_minXin[0]) *
      loctmp_b_b / (ANN_EKF_NMPC_2_P.Y_maxXin[0] - ANN_EKF_NMPC_2_P.Y_minXin[0])
      + ANN_EKF_NMPC_2_P.Y_minYin;
    locvar_y_ann_Y_out[1] = (locvar_Reshape1[6] - ANN_EKF_NMPC_2_P.Y_minXin[1]) *
      loctmp_b_b / (ANN_EKF_NMPC_2_P.Y_maxXin[1] - ANN_EKF_NMPC_2_P.Y_minXin[1])
      + ANN_EKF_NMPC_2_P.Y_minYin;
    locvar_y_ann_Y_out[2] = (locvar_Reshape1[9] - ANN_EKF_NMPC_2_P.Y_minXin[2]) *
      loctmp_b_b / (ANN_EKF_NMPC_2_P.Y_maxXin[2] - ANN_EKF_NMPC_2_P.Y_minXin[2])
      + ANN_EKF_NMPC_2_P.Y_minYin;
    locvar_y_ann_Y_out[3] = (locvar_Reshape1[11] - ANN_EKF_NMPC_2_P.Y_minXin[3])
      * loctmp_b_b / (ANN_EKF_NMPC_2_P.Y_maxXin[3] - ANN_EKF_NMPC_2_P.Y_minXin[3])
      + ANN_EKF_NMPC_2_P.Y_minYin;
    locvar_y_ann_Y_out[4] = (ANN_EKF_NMPC_2_B.betadot -
      ANN_EKF_NMPC_2_P.Y_minXin[4]) * loctmp_b_b / (ANN_EKF_NMPC_2_P.Y_maxXin[4]
      - ANN_EKF_NMPC_2_P.Y_minXin[4]) + ANN_EKF_NMPC_2_P.Y_minYin;
    locvar_y_ann_Y_out[5] = (ANN_EKF_NMPC_2_U.ServoCommands.aileron_cmd -
      ANN_EKF_NMPC_2_P.Y_minXin[5]) * loctmp_b_b / (ANN_EKF_NMPC_2_P.Y_maxXin[5]
      - ANN_EKF_NMPC_2_P.Y_minXin[5]) + ANN_EKF_NMPC_2_P.Y_minYin;
    locvar_y_ann_Y_out[6] = (ANN_EKF_NMPC_2_U.ServoCommands.rudder_cmd -
      ANN_EKF_NMPC_2_P.Y_minXin[6]) * loctmp_b_b / (ANN_EKF_NMPC_2_P.Y_maxXin[6]
      - ANN_EKF_NMPC_2_P.Y_minXin[6]) + ANN_EKF_NMPC_2_P.Y_minYin;

    /* %Z-axis  */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.Z_maxYin - ANN_EKF_NMPC_2_P.Z_minYin;
    locvar_y_ann_Z_out[0] = (locvar_Reshape1[4] - ANN_EKF_NMPC_2_P.Z_minXin[0]) *
      locvar_Gain_ar / (ANN_EKF_NMPC_2_P.Z_maxXin[0] -
                        ANN_EKF_NMPC_2_P.Z_minXin[0]) +
      ANN_EKF_NMPC_2_P.Z_minYin;
    locvar_y_ann_Z_out[1] = (locvar_Reshape1[5] - ANN_EKF_NMPC_2_P.Z_minXin[1]) *
      locvar_Gain_ar / (ANN_EKF_NMPC_2_P.Z_maxXin[1] -
                        ANN_EKF_NMPC_2_P.Z_minXin[1]) +
      ANN_EKF_NMPC_2_P.Z_minYin;
    locvar_y_ann_Z_out[2] = (locvar_Reshape1[6] - ANN_EKF_NMPC_2_P.Z_minXin[2]) *
      locvar_Gain_ar / (ANN_EKF_NMPC_2_P.Z_maxXin[2] -
                        ANN_EKF_NMPC_2_P.Z_minXin[2]) +
      ANN_EKF_NMPC_2_P.Z_minYin;
    locvar_y_ann_Z_out[3] = (locvar_Reshape1[10] - ANN_EKF_NMPC_2_P.Z_minXin[3])
      * locvar_Gain_ar / (ANN_EKF_NMPC_2_P.Z_maxXin[3] -
                          ANN_EKF_NMPC_2_P.Z_minXin[3]) +
      ANN_EKF_NMPC_2_P.Z_minYin;
    locvar_y_ann_Z_out[4] = (ANN_EKF_NMPC_2_B.alphadot -
      ANN_EKF_NMPC_2_P.Z_minXin[4]) * locvar_Gain_ar /
      (ANN_EKF_NMPC_2_P.Z_maxXin[4] - ANN_EKF_NMPC_2_P.Z_minXin[4]) +
      ANN_EKF_NMPC_2_P.Z_minYin;
    locvar_y_ann_Z_out[5] = (ANN_EKF_NMPC_2_U.ServoCommands.throttle_cmd -
      ANN_EKF_NMPC_2_P.Z_minXin[5]) * locvar_Gain_ar /
      (ANN_EKF_NMPC_2_P.Z_maxXin[5] - ANN_EKF_NMPC_2_P.Z_minXin[5]) +
      ANN_EKF_NMPC_2_P.Z_minYin;
    locvar_y_ann_Z_out[6] = (ANN_EKF_NMPC_2_U.ServoCommands.elevator_cmd -
      ANN_EKF_NMPC_2_P.Z_minXin[6]) * locvar_Gain_ar /
      (ANN_EKF_NMPC_2_P.Z_maxXin[6] - ANN_EKF_NMPC_2_P.Z_minXin[6]) +
      ANN_EKF_NMPC_2_P.Z_minYin;

    /* %normalized window */
    /* '<S11>:1:40' */
    for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
      for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
        locvar_x_ann_X_out[loctmp_i_0 + 7 * loctmp_i_1] =
          ANN_EKF_NMPC_2_DW.x_ann_X[(1 + loctmp_i_1) * 7 + loctmp_i_0];
      }
    }

    for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
      locvar_x_ann_X_out[42 + loctmp_i_1] = locvar_y_ann_X_out[loctmp_i_1];
    }

    /* '<S11>:1:41' */
    for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
      for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
        locvar_x_ann_Y_out[loctmp_i_0 + 7 * loctmp_i_1] =
          ANN_EKF_NMPC_2_DW.x_ann_Y[(1 + loctmp_i_1) * 7 + loctmp_i_0];
      }
    }

    for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
      locvar_x_ann_Y_out[42 + loctmp_i_1] = locvar_y_ann_Y_out[loctmp_i_1];
    }

    /* '<S11>:1:42' */
    for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
      for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
        locvar_x_ann_Z_out[loctmp_i_0 + 7 * loctmp_i_1] =
          ANN_EKF_NMPC_2_DW.x_ann_Z[(1 + loctmp_i_1) * 7 + loctmp_i_0];
      }
    }

    for (loctmp_i_1 = 0; loctmp_i_1 < 7; loctmp_i_1++) {
      locvar_x_ann_Z_out[42 + loctmp_i_1] = locvar_y_ann_Z_out[loctmp_i_1];
    }

    /* '<S11>:1:43' */
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      locvar_y_ann_X_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.y_ann_X[loctmp_i_0 + 1];
      locvar_y_ann_Y_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.y_ann_Y[loctmp_i_0 + 1];
      locvar_y_ann_Z_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.y_ann_Z[loctmp_i_0 + 1];
    }

    locvar_y_ann_X_out[6] = (ANN_EKF_NMPC_2_U.Accelerometermeas.Axb -
      ANN_EKF_NMPC_2_P.X_minXout) * (ANN_EKF_NMPC_2_P.X_maxYout -
      ANN_EKF_NMPC_2_P.X_minYout) / (ANN_EKF_NMPC_2_P.X_maxXout -
      ANN_EKF_NMPC_2_P.X_minXout) + ANN_EKF_NMPC_2_P.X_minYout;

    /* '<S11>:1:44' */
    locvar_y_ann_Y_out[6] = (ANN_EKF_NMPC_2_U.Accelerometermeas.Ayb -
      ANN_EKF_NMPC_2_P.Y_minXout) * (ANN_EKF_NMPC_2_P.Y_maxYout -
      ANN_EKF_NMPC_2_P.Y_minYout) / (ANN_EKF_NMPC_2_P.Y_maxXout -
      ANN_EKF_NMPC_2_P.Y_minXout) + ANN_EKF_NMPC_2_P.Y_minYout;

    /* '<S11>:1:45' */
    locvar_y_ann_Z_out[6] = (ANN_EKF_NMPC_2_U.Accelerometermeas.Azb -
      ANN_EKF_NMPC_2_P.Z_minXout) * (ANN_EKF_NMPC_2_P.Z_maxYout -
      ANN_EKF_NMPC_2_P.Z_minYout) / (ANN_EKF_NMPC_2_P.Z_maxXout -
      ANN_EKF_NMPC_2_P.Z_minXout) + ANN_EKF_NMPC_2_P.Z_minYout;

    /* End of MATLAB Function: '<S7>/ANN Inputs-Outputs Normalization' */

    /* UnitDelay: '<S5>/Output' */
    locvar_FixPtRelationalOperator = ANN_EKF_NMPC_2_DW.Output_DSTATE;

    /* MATLAB Function: '<S1>/ann' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read1'
     *  DataStoreRead: '<S1>/Data Store Read10'
     *  DataStoreRead: '<S1>/Data Store Read11'
     *  DataStoreRead: '<S1>/Data Store Read12'
     *  DataStoreRead: '<S1>/Data Store Read13'
     *  DataStoreRead: '<S1>/Data Store Read14'
     *  DataStoreRead: '<S1>/Data Store Read15'
     *  DataStoreRead: '<S1>/Data Store Read2'
     *  DataStoreRead: '<S1>/Data Store Read3'
     *  DataStoreRead: '<S1>/Data Store Read4'
     *  DataStoreRead: '<S1>/Data Store Read5'
     *  DataStoreRead: '<S1>/Data Store Read6'
     *  DataStoreRead: '<S1>/Data Store Read7'
     *  DataStoreRead: '<S1>/Data Store Read8'
     *  DataStoreRead: '<S1>/Data Store Read9'
     *  UnitDelay: '<S5>/Output'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_DW.c_ann_Y;
    locvar_Add_kq = ANN_EKF_NMPC_2_DW.c_ann_Z;
    locvar_Add2_db = ANN_EKF_NMPC_2_DW.lambda_ann_Y;
    locvar_Divide4_c1v = ANN_EKF_NMPC_2_DW.lambda_ann_Z;

    /* MATLAB Function 'ANN (subsystem)/ann': '<S8>:1' */
    /* %number of ann parameters */
    /* X-axis */
    /* Y-axis */
    /* Z-axis */
    /* %no parameter updating */
    /* X-axis */
    /* '<S8>:1:33' */
    /* '<S8>:1:34' */
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* DataStoreRead: '<S1>/Data Store Read11' */
      locvar_DataStoreRead11[loctmp_i_0] = ANN_EKF_NMPC_2_DW.b_ann_Y[loctmp_i_0];

      /* DataStoreRead: '<S1>/Data Store Read6' */
      locvar_DataStoreRead6_o[loctmp_i_0] = ANN_EKF_NMPC_2_DW.b_ann_Z[loctmp_i_0];
      locvar_a_ann_X_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.a_ann_X[loctmp_i_0];
      locvar_b_ann_X_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.b_ann_X[loctmp_i_0];
    }

    /* '<S8>:1:35' */
    locvar_Divide4_ch = ANN_EKF_NMPC_2_DW.c_ann_X;

    /* '<S8>:1:36' */
    memcpy(&locvar_w_ann_X_out[0], &ANN_EKF_NMPC_2_DW.w_ann_X[0], 280U * sizeof
           (real_T));

    /* '<S8>:1:37' */
    locvar_Divide5_kh = ANN_EKF_NMPC_2_DW.lambda_ann_X;

    /* '<S8>:1:38' */
    locvar_Divide3_j0 = 0.0;

    /* Y-axis */
    /* '<S8>:1:40' */
    /* '<S8>:1:41' */
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      locvar_a_ann_Y_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.a_ann_Y[loctmp_i_0];
      locvar_b_ann_Y_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.b_ann_Y[loctmp_i_0];
    }

    /* '<S8>:1:42' */
    locvar_Divide4_afp = ANN_EKF_NMPC_2_DW.c_ann_Y;

    /* '<S8>:1:43' */
    memcpy(&locvar_w_ann_Y_out[0], &ANN_EKF_NMPC_2_DW.w_ann_Y[0], 280U * sizeof
           (real_T));

    /* '<S8>:1:44' */
    locvar_MathFunction_di = ANN_EKF_NMPC_2_DW.lambda_ann_Y;

    /* '<S8>:1:45' */
    locvar_MathFunction1_e4 = 0.0;

    /* Z-axis */
    /* '<S8>:1:47' */
    /* '<S8>:1:48' */
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      locvar_a_ann_Z_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.a_ann_Z[loctmp_i_0];
      locvar_b_ann_Z_out[loctmp_i_0] = ANN_EKF_NMPC_2_DW.b_ann_Z[loctmp_i_0];
    }

    /* '<S8>:1:49' */
    locvar_Add1_o3 = ANN_EKF_NMPC_2_DW.c_ann_Z;

    /* '<S8>:1:50' */
    memcpy(&locvar_w_ann_Z_out[0], &ANN_EKF_NMPC_2_DW.w_ann_Z[0], 280U * sizeof
           (real_T));

    /* '<S8>:1:51' */
    locvar_Add_au = ANN_EKF_NMPC_2_DW.lambda_ann_Z;

    /* '<S8>:1:52' */
    locvar_Divide_aa = 0.0;

    /* %parameter updating */
    if (ANN_EKF_NMPC_2_DW.Output_DSTATE == 1) {
      /* '<S8>:1:55' */
      memcpy(&locvar_b_ann_Z_out[0], &ANN_EKF_NMPC_2_DW.b_ann_X[0], 40U * sizeof
             (real_T));
      ANN_EKF_NMPC_2_ann_iteration(locvar_x_ann_X_out, locvar_y_ann_X_out,
        locvar_a_ann_X_out, locvar_b_ann_Z_out, ANN_EKF_NMPC_2_DW.c_ann_X,
        locvar_w_ann_X_out, ANN_EKF_NMPC_2_DW.lambda_ann_X, &locvar_Divide4_ch,
        &locvar_Divide5_kh, &locvar_Divide3_j0);

      /* '<S8>:1:56' */
      /* '<S8>:1:57' */
      /* '<S8>:1:58' */
      for (loctmp_i_1 = 0; loctmp_i_1 < 40; loctmp_i_1++) {
        locvar_b_ann_X_out[loctmp_i_1] = locvar_b_ann_Z_out[loctmp_i_1];
        locvar_b_ann_Z_out[loctmp_i_1] = locvar_DataStoreRead11[loctmp_i_1];
      }

      ANN_EKF_NMPC_2_ann_iteration_f(locvar_x_ann_Y_out, locvar_y_ann_Y_out,
        locvar_a_ann_Y_out, locvar_b_ann_Z_out, locvar_Gain_ar,
        locvar_w_ann_Y_out, locvar_Add2_db, &locvar_Divide4_afp,
        &locvar_MathFunction_di, &locvar_MathFunction1_e4);

      /* '<S8>:1:63' */
      /* '<S8>:1:64' */
      /* '<S8>:1:65' */
      for (loctmp_i_1 = 0; loctmp_i_1 < 40; loctmp_i_1++) {
        locvar_b_ann_Y_out[loctmp_i_1] = locvar_b_ann_Z_out[loctmp_i_1];
        locvar_b_ann_Z_out[loctmp_i_1] = locvar_DataStoreRead6_o[loctmp_i_1];
      }

      ANN_EKF_NMPC_2_ann_iteration_fj(locvar_x_ann_Z_out, locvar_y_ann_Z_out,
        locvar_a_ann_Z_out, locvar_b_ann_Z_out, locvar_Add_kq,
        locvar_w_ann_Z_out, locvar_Divide4_c1v, &locvar_Add1_o3, &locvar_Add_au,
        &locvar_Divide_aa);

      /* '<S8>:1:70' */
      /* '<S8>:1:71' */
      /* '<S8>:1:72' */
    }

    /* End of MATLAB Function: '<S1>/ann' */

    /* DataStoreWrite: '<S1>/Data Store Write10' */
    ANN_EKF_NMPC_2_DW.lambda_ann_Z = locvar_Add_au;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* DataStoreWrite: '<S1>/Data Store Write1' */
      ANN_EKF_NMPC_2_DW.b_ann_X[loctmp_i_0] = locvar_b_ann_X_out[loctmp_i_0];

      /* DataStoreWrite: '<S1>/Data Store Write11' */
      ANN_EKF_NMPC_2_DW.b_ann_Y[loctmp_i_0] = locvar_b_ann_Y_out[loctmp_i_0];

      /* DataStoreWrite: '<S1>/Data Store Write12' */
      ANN_EKF_NMPC_2_DW.a_ann_Y[loctmp_i_0] = locvar_a_ann_Y_out[loctmp_i_0];
    }

    /* DataStoreWrite: '<S1>/Data Store Write13' */
    ANN_EKF_NMPC_2_DW.c_ann_Y = locvar_Divide4_afp;

    /* DataStoreWrite: '<S1>/Data Store Write14' */
    memcpy(&ANN_EKF_NMPC_2_DW.w_ann_Y[0], &locvar_w_ann_Y_out[0], 280U * sizeof
           (real_T));

    /* DataStoreWrite: '<S1>/Data Store Write15' */
    ANN_EKF_NMPC_2_DW.lambda_ann_Y = locvar_MathFunction_di;

    /* DataStoreWrite: '<S1>/Data Store Write2' */
    memcpy(&ANN_EKF_NMPC_2_DW.a_ann_X[0], &locvar_a_ann_X_out[0], 40U * sizeof
           (real_T));

    /* DataStoreWrite: '<S1>/Data Store Write3' */
    ANN_EKF_NMPC_2_DW.c_ann_X = locvar_Divide4_ch;

    /* DataStoreWrite: '<S1>/Data Store Write4' */
    memcpy(&ANN_EKF_NMPC_2_DW.w_ann_X[0], &locvar_w_ann_X_out[0], 280U * sizeof
           (real_T));

    /* DataStoreWrite: '<S1>/Data Store Write5' */
    ANN_EKF_NMPC_2_DW.lambda_ann_X = locvar_Divide5_kh;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* DataStoreWrite: '<S1>/Data Store Write6' */
      ANN_EKF_NMPC_2_DW.b_ann_Z[loctmp_i_0] = locvar_b_ann_Z_out[loctmp_i_0];

      /* DataStoreWrite: '<S1>/Data Store Write7' */
      ANN_EKF_NMPC_2_DW.a_ann_Z[loctmp_i_0] = locvar_a_ann_Z_out[loctmp_i_0];
    }

    /* DataStoreWrite: '<S1>/Data Store Write8' */
    ANN_EKF_NMPC_2_DW.c_ann_Z = locvar_Add1_o3;

    /* DataStoreWrite: '<S1>/Data Store Write9' */
    memcpy(&ANN_EKF_NMPC_2_DW.w_ann_Z[0], &locvar_w_ann_Z_out[0], 280U * sizeof
           (real_T));
    for (loctmp_i_0 = 0; loctmp_i_0 < 49; loctmp_i_0++) {
      /* DataStoreWrite: '<S7>/Data Store Write1' */
      ANN_EKF_NMPC_2_DW.x_ann_Y[loctmp_i_0] = locvar_x_ann_Y_out[loctmp_i_0];

      /* DataStoreWrite: '<S7>/Data Store Write2' */
      ANN_EKF_NMPC_2_DW.x_ann_X[loctmp_i_0] = locvar_x_ann_X_out[loctmp_i_0];

      /* DataStoreWrite: '<S7>/Data Store Write3' */
      ANN_EKF_NMPC_2_DW.x_ann_Z[loctmp_i_0] = locvar_x_ann_Z_out[loctmp_i_0];
    }

    for (loctmp_i_0 = 0; loctmp_i_0 < 7; loctmp_i_0++) {
      /* DataStoreWrite: '<S7>/Data Store Write4' */
      ANN_EKF_NMPC_2_DW.y_ann_X[loctmp_i_0] = locvar_y_ann_X_out[loctmp_i_0];

      /* DataStoreWrite: '<S7>/Data Store Write5' */
      ANN_EKF_NMPC_2_DW.y_ann_Y[loctmp_i_0] = locvar_y_ann_Y_out[loctmp_i_0];

      /* DataStoreWrite: '<S7>/Data Store Write6' */
      ANN_EKF_NMPC_2_DW.y_ann_Z[loctmp_i_0] = locvar_y_ann_Z_out[loctmp_i_0];

      /* DataStoreRead: '<S7>/Data Store Read7' */
      locvar_DataStoreRead7_p[loctmp_i_0] = ANN_EKF_NMPC_2_DW.x_ann_X[loctmp_i_0
        + 42];

      /* DataStoreRead: '<S7>/Data Store Read9' */
      locvar_DataStoreRead9_l[loctmp_i_0] = ANN_EKF_NMPC_2_DW.x_ann_Y[loctmp_i_0
        + 42];

      /* DataStoreRead: '<S7>/Data Store Read8' */
      locvar_DataStoreRead8_a[loctmp_i_0] = ANN_EKF_NMPC_2_DW.x_ann_Z[loctmp_i_0
        + 42];
    }

    /* Sum: '<S9>/FixPt Sum1' incorporates:
     *  Constant: '<S9>/FixPt Constant'
     */
    locvar_FixPtRelationalOperator = (uint8_T)((uint32_T)
      locvar_FixPtRelationalOperator + ANN_EKF_NMPC_2_P.FixPtConstant_Value);

    /* Switch: '<S10>/FixPt Switch' incorporates:
     *  Constant: '<S10>/Constant'
     */
    if (locvar_FixPtRelationalOperator > ANN_EKF_NMPC_2_P.u0_uplimit) {
      locvar_FixPtSwitch = ANN_EKF_NMPC_2_P.Constant_Value_em;
    } else {
      locvar_FixPtSwitch = locvar_FixPtRelationalOperator;
    }

    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* UnitDelay: '<S6>/a_ann_X_ic' */
      ANN_EKF_NMPC_2_B.a_ann_X_ic[loctmp_i_0] =
        ANN_EKF_NMPC_2_DW.a_ann_X_ic_DSTATE[loctmp_i_0];

      /* UnitDelay: '<S6>/b_ann_X_ic' */
      ANN_EKF_NMPC_2_B.b_ann_X_ic[loctmp_i_0] =
        ANN_EKF_NMPC_2_DW.b_ann_X_ic_DSTATE[loctmp_i_0];
    }

    /* End of Switch: '<S10>/FixPt Switch' */

    /* UnitDelay: '<S6>/c_ann_X_ic' */
    ANN_EKF_NMPC_2_B.c_ann_X_ic = ANN_EKF_NMPC_2_DW.c_ann_X_ic_DSTATE;

    /* UnitDelay: '<S6>/w_ann_X_ic' */
    memcpy(&ANN_EKF_NMPC_2_B.w_ann_X_ic[0],
           &ANN_EKF_NMPC_2_DW.w_ann_X_ic_DSTATE[0], 280U * sizeof(real_T));
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* UnitDelay: '<S6>/a_ann_Y_ic' */
      ANN_EKF_NMPC_2_B.a_ann_Y_ic[loctmp_i_0] =
        ANN_EKF_NMPC_2_DW.a_ann_Y_ic_DSTATE[loctmp_i_0];

      /* UnitDelay: '<S6>/b_ann_Y_ic' */
      ANN_EKF_NMPC_2_B.b_ann_Y_ic[loctmp_i_0] =
        ANN_EKF_NMPC_2_DW.b_ann_Y_ic_DSTATE[loctmp_i_0];
    }

    /* UnitDelay: '<S6>/c_ann_Y_ic' */
    ANN_EKF_NMPC_2_B.c_ann_Y_ic = ANN_EKF_NMPC_2_DW.c_ann_Y_ic_DSTATE;

    /* UnitDelay: '<S6>/w_ann_Y_ic' */
    memcpy(&ANN_EKF_NMPC_2_B.w_ann_Y_ic[0],
           &ANN_EKF_NMPC_2_DW.w_ann_Y_ic_DSTATE[0], 280U * sizeof(real_T));
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* UnitDelay: '<S6>/a_ann_Z_ic' */
      ANN_EKF_NMPC_2_B.a_ann_Z_ic[loctmp_i_0] =
        ANN_EKF_NMPC_2_DW.a_ann_Z_ic_DSTATE[loctmp_i_0];

      /* UnitDelay: '<S6>/b_ann_Z_ic' */
      ANN_EKF_NMPC_2_B.b_ann_Z_ic[loctmp_i_0] =
        ANN_EKF_NMPC_2_DW.b_ann_Z_ic_DSTATE[loctmp_i_0];
    }

    /* UnitDelay: '<S6>/c_ann_Z_ic' */
    ANN_EKF_NMPC_2_B.c_ann_Z_ic = ANN_EKF_NMPC_2_DW.c_ann_Z_ic_DSTATE;

    /* UnitDelay: '<S6>/w_ann_Z_ic' */
    memcpy(&ANN_EKF_NMPC_2_B.w_ann_Z_ic[0],
           &ANN_EKF_NMPC_2_DW.w_ann_Z_ic_DSTATE[0], 280U * sizeof(real_T));

    /* SignalConversion: '<S1>/OutportBufferForV_ann_X' */
    locvar_OutportBufferForV_ann_X = locvar_Divide3_j0;

    /* SignalConversion: '<S1>/OutportBufferForV_ann_Y' */
    locvar_OutportBufferForV_ann_Y = locvar_MathFunction1_e4;

    /* SignalConversion: '<S1>/OutportBufferForV_ann_Z' */
    locvar_OutportBufferForV_ann_Z = locvar_Divide_aa;

    /* Update for DiscreteFilter: '<S7>/Discrete Filter' */
    ANN_EKF_NMPC_2_DW.DiscreteFilter_states = locvar_Add1_ob;

    /* Update for DiscreteFilter: '<S7>/Discrete Filter1' */
    ANN_EKF_NMPC_2_DW.DiscreteFilter1_states = locvar_Add_pii;

    /* Update for UnitDelay: '<S5>/Output' */
    ANN_EKF_NMPC_2_DW.Output_DSTATE = locvar_FixPtSwitch;
    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* Update for UnitDelay: '<S6>/a_ann_X_ic' incorporates:
       *  Gain: '<S6>/Gain'
       *  Gain: '<S6>/Gain1'
       *  Sum: '<S6>/Add'
       */
      ANN_EKF_NMPC_2_DW.a_ann_X_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.a_ann_X_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_a_ann_X_out[loctmp_i_0];

      /* Update for UnitDelay: '<S6>/b_ann_X_ic' incorporates:
       *  Gain: '<S6>/Gain2'
       *  Gain: '<S6>/Gain3'
       *  Sum: '<S6>/Add1'
       */
      ANN_EKF_NMPC_2_DW.b_ann_X_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.b_ann_X_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_b_ann_X_out[loctmp_i_0];
    }

    /* Update for UnitDelay: '<S6>/c_ann_X_ic' incorporates:
     *  Gain: '<S6>/Gain4'
     *  Gain: '<S6>/Gain5'
     *  Sum: '<S6>/Add2'
     */
    ANN_EKF_NMPC_2_DW.c_ann_X_ic_DSTATE = (1.0 - ANN_EKF_NMPC_2_P.alpha_ann) *
      ANN_EKF_NMPC_2_B.c_ann_X_ic + ANN_EKF_NMPC_2_P.alpha_ann *
      locvar_Divide4_ch;

    /* Update for UnitDelay: '<S6>/w_ann_X_ic' incorporates:
     *  Gain: '<S6>/Gain6'
     *  Gain: '<S6>/Gain7'
     *  Sum: '<S6>/Add3'
     */
    for (loctmp_i_0 = 0; loctmp_i_0 < 280; loctmp_i_0++) {
      ANN_EKF_NMPC_2_DW.w_ann_X_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.w_ann_X_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_w_ann_X_out[loctmp_i_0];
    }

    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* Update for UnitDelay: '<S6>/a_ann_Y_ic' incorporates:
       *  Gain: '<S6>/Gain8'
       *  Gain: '<S6>/Gain9'
       *  Sum: '<S6>/Add4'
       */
      ANN_EKF_NMPC_2_DW.a_ann_Y_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.a_ann_Y_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_a_ann_Y_out[loctmp_i_0];

      /* Update for UnitDelay: '<S6>/b_ann_Y_ic' incorporates:
       *  Gain: '<S6>/Gain10'
       *  Gain: '<S6>/Gain11'
       *  Sum: '<S6>/Add5'
       */
      ANN_EKF_NMPC_2_DW.b_ann_Y_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.b_ann_Y_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_b_ann_Y_out[loctmp_i_0];
    }

    /* End of Update for UnitDelay: '<S6>/w_ann_X_ic' */

    /* Update for UnitDelay: '<S6>/c_ann_Y_ic' incorporates:
     *  Gain: '<S6>/Gain12'
     *  Gain: '<S6>/Gain13'
     *  Sum: '<S6>/Add6'
     */
    ANN_EKF_NMPC_2_DW.c_ann_Y_ic_DSTATE = (1.0 - ANN_EKF_NMPC_2_P.alpha_ann) *
      ANN_EKF_NMPC_2_B.c_ann_Y_ic + ANN_EKF_NMPC_2_P.alpha_ann *
      locvar_Divide4_afp;

    /* Update for UnitDelay: '<S6>/w_ann_Y_ic' incorporates:
     *  Gain: '<S6>/Gain14'
     *  Gain: '<S6>/Gain15'
     *  Sum: '<S6>/Add7'
     */
    for (loctmp_i_0 = 0; loctmp_i_0 < 280; loctmp_i_0++) {
      ANN_EKF_NMPC_2_DW.w_ann_Y_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.w_ann_Y_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_w_ann_Y_out[loctmp_i_0];
    }

    for (loctmp_i_0 = 0; loctmp_i_0 < 40; loctmp_i_0++) {
      /* Update for UnitDelay: '<S6>/a_ann_Z_ic' incorporates:
       *  Gain: '<S6>/Gain16'
       *  Gain: '<S6>/Gain17'
       *  Sum: '<S6>/Add8'
       */
      ANN_EKF_NMPC_2_DW.a_ann_Z_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.a_ann_Z_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_a_ann_Z_out[loctmp_i_0];

      /* Update for UnitDelay: '<S6>/b_ann_Z_ic' incorporates:
       *  Gain: '<S6>/Gain18'
       *  Gain: '<S6>/Gain19'
       *  Sum: '<S6>/Add9'
       */
      ANN_EKF_NMPC_2_DW.b_ann_Z_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.b_ann_Z_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_b_ann_Z_out[loctmp_i_0];
    }

    /* End of Update for UnitDelay: '<S6>/w_ann_Y_ic' */

    /* Update for UnitDelay: '<S6>/c_ann_Z_ic' incorporates:
     *  Gain: '<S6>/Gain20'
     *  Gain: '<S6>/Gain21'
     *  Sum: '<S6>/Add10'
     */
    ANN_EKF_NMPC_2_DW.c_ann_Z_ic_DSTATE = (1.0 - ANN_EKF_NMPC_2_P.alpha_ann) *
      ANN_EKF_NMPC_2_B.c_ann_Z_ic + ANN_EKF_NMPC_2_P.alpha_ann * locvar_Add1_o3;

    /* Update for UnitDelay: '<S6>/w_ann_Z_ic' incorporates:
     *  Gain: '<S6>/Gain22'
     *  Gain: '<S6>/Gain23'
     *  Sum: '<S6>/Add11'
     */
    for (loctmp_i_0 = 0; loctmp_i_0 < 280; loctmp_i_0++) {
      ANN_EKF_NMPC_2_DW.w_ann_Z_ic_DSTATE[loctmp_i_0] = (1.0 -
        ANN_EKF_NMPC_2_P.alpha_ann) * ANN_EKF_NMPC_2_B.w_ann_Z_ic[loctmp_i_0] +
        ANN_EKF_NMPC_2_P.alpha_ann * locvar_w_ann_Z_out[loctmp_i_0];
    }

    /* End of Update for UnitDelay: '<S6>/w_ann_Z_ic' */
  }

  /* End of Outputs for SubSystem: '<Root>/ANN (subsystem)' */

  /* Outputs for Enabled SubSystem: '<Root>/NMPC (subsystem)' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Inport: '<Root>/IFS // NMPC' */
  if (ANN_EKF_NMPC_2_U.IFSNMPC > 0.0) {
    if (!ANN_EKF_NMPC_2_DW.NMPCsubsystem_MODE) {
      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
      memcpy(&ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_am[0],
             &ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition[0], 84U * sizeof
             (real_T));

      /* InitializeConditions for UnitDelay: '<S13>/UD' */
      ANN_EKF_NMPC_2_DW.UD_DSTATE =
        ANN_EKF_NMPC_2_P.DiscreteDerivative_ICPrevScaledInput;

      /* InitializeConditions for UnitDelay: '<S14>/UD' */
      ANN_EKF_NMPC_2_DW.UD_DSTATE_o =
        ANN_EKF_NMPC_2_P.DiscreteDerivative1_ICPrevScaledInput;

      /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE = ANN_EKF_NMPC_2_P.ro0;
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState = 0;

      /* InitializeConditions for UnitDelay: '<S45>/Unit Delay' */
      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_mi = ANN_EKF_NMPC_2_P.xw110;

      /* InitializeConditions for UnitDelay: '<S45>/Unit Delay1' */
      ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_e = ANN_EKF_NMPC_2_P.xw120;

      /* InitializeConditions for UnitDelay: '<S45>/Unit Delay2' */
      ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE = ANN_EKF_NMPC_2_P.xw130;

      /* InitializeConditions for UnitDelay: '<S45>/Unit Delay3' */
      ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE = ANN_EKF_NMPC_2_P.xw140;

      /* InitializeConditions for UnitDelay: '<S46>/Unit Delay' */
      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_jh = ANN_EKF_NMPC_2_P.xw210;

      /* InitializeConditions for UnitDelay: '<S46>/Unit Delay1' */
      ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_n = ANN_EKF_NMPC_2_P.xw220;

      /* InitializeConditions for UnitDelay: '<S46>/Unit Delay2' */
      ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_n = ANN_EKF_NMPC_2_P.xw230;

      /* InitializeConditions for UnitDelay: '<S46>/Unit Delay3' */
      ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_f = ANN_EKF_NMPC_2_P.xw240;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_d = ANN_EKF_NMPC_2_P.xw310;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay1' */
      ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_j = ANN_EKF_NMPC_2_P.xw320;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay2' */
      ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_l = ANN_EKF_NMPC_2_P.xw330;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay3' */
      ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_j = ANN_EKF_NMPC_2_P.xw340;

      /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k =
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_IC;
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState_a = 0;
      ANN_EKF_NMPC_2_DW.NMPCsubsystem_MODE = true;
    }

    /* DataStoreWrite: '<S2>/Data Store Write2' incorporates:
     *  UnitDelay: '<S2>/Unit Delay'
     */
    memcpy(&ANN_EKF_NMPC_2_DW.u_nmpc[0], &ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_am
           [0], 84U * sizeof(real_T));

    /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/PIC//CIC'
     */
    locvar_DataTypeConversion1 = ANN_EKF_NMPC_2_U.PICCIC;

    /* DataStoreRead: '<S2>/Data Store Read1' */
    loctmp_locvar_DataStoreRead1_m_idx_0 = ANN_EKF_NMPC_2_DW.u_nmpc[0];
    loctmp_locvar_DataStoreRead1_m_idx_1 = ANN_EKF_NMPC_2_DW.u_nmpc[1];
    loctmp_locvar_DataStoreRead1_m_idx_2 = ANN_EKF_NMPC_2_DW.u_nmpc[2];
    loctmp_locvar_DataStoreRead1_m_idx_3 = ANN_EKF_NMPC_2_DW.u_nmpc[3];

    /* MATLAB Function: '<S17>/Swtching Logic' incorporates:
     *  BusCreator: '<S17>/BusConversion_InsertedFor_Swtching Logic_at_inport_0'
     *  DataStoreRead: '<S17>/Data Store Read1'
     *  DataStoreRead: '<S17>/Data Store Read2'
     *  DataStoreRead: '<S17>/Data Store Read3'
     *  DataStoreRead: '<S17>/Data Store Read4'
     *  DataStoreRead: '<S17>/Data Store Read5'
     *  DataStoreRead: '<S2>/Data Store Read1'
     *  Inport: '<Root>/PIC//CIC'
     *  Inport: '<Root>/R//C'
     */
    /* MATLAB Function 'NMPC (subsystem)/R//C to AUTO smooth transition Subsystem/Swtching Logic': '<S44>:1' */
    /* initialization */
    /* '<S44>:1:12' */
    locvar_Gain_ar = ANN_EKF_NMPC_2_DW.sw_time;

    /* '<S44>:1:13' */
    locvar_Add_kq = ANN_EKF_NMPC_2_DW.remote_throttle_mem;

    /* '<S44>:1:14' */
    locvar_Add2_db = ANN_EKF_NMPC_2_DW.remote_elevator_mem;

    /* '<S44>:1:15' */
    locvar_Divide4_c1v = ANN_EKF_NMPC_2_DW.remote_aileron_mem;

    /* '<S44>:1:16' */
    locvar_Divide4_ch = ANN_EKF_NMPC_2_DW.remote_rudder_mem;

    /* '<S44>:1:18' */
    locvar_Divide5_kh = ANN_EKF_NMPC_2_U.RC.throttle_cmd;

    /* [-] */
    /* '<S44>:1:19' */
    locvar_Divide3_j0 = ANN_EKF_NMPC_2_U.RC.elevator_cmd;

    /* [rad] */
    /* '<S44>:1:20' */
    locvar_Divide4_afp = ANN_EKF_NMPC_2_U.RC.aileron_cmd;

    /* [rad] */
    /* '<S44>:1:21' */
    locvar_MathFunction_di = ANN_EKF_NMPC_2_U.RC.rudder_cmd;

    /* [rad] */
    /* '<S44>:1:23' */
    /* [s] */
    /* %updating/reseting values */
    if ((ANN_EKF_NMPC_2_U.PICCIC == 1) && (ANN_EKF_NMPC_2_DW.sw_time == 0.0)) {
      /* '<S44>:1:26' */
      /* '<S44>:1:27' */
      locvar_Add_kq = ANN_EKF_NMPC_2_U.RC.throttle_cmd;

      /* '<S44>:1:28' */
      locvar_Add2_db = ANN_EKF_NMPC_2_U.RC.elevator_cmd;

      /* '<S44>:1:29' */
      locvar_Divide4_c1v = ANN_EKF_NMPC_2_U.RC.aileron_cmd;

      /* '<S44>:1:30' */
      locvar_Divide4_ch = ANN_EKF_NMPC_2_U.RC.rudder_cmd;
    }

    /* servo command value */
    if ((ANN_EKF_NMPC_2_U.PICCIC == 1) && (ANN_EKF_NMPC_2_DW.sw_time >= 0.0) &&
        (ANN_EKF_NMPC_2_DW.sw_time <= 0.5)) {
      /* '<S44>:1:39' */
      /* '<S44>:1:40' */
      locvar_Divide5_kh = (0.5 - cos(6.2831853071795862 *
        ANN_EKF_NMPC_2_DW.sw_time) * 0.5) * (ANN_EKF_NMPC_2_DW.u_nmpc[0] -
        locvar_Add_kq) + locvar_Add_kq;

      /* '<S44>:1:41' */
      locvar_Divide3_j0 = (0.5 - cos(6.2831853071795862 *
        ANN_EKF_NMPC_2_DW.sw_time) * 0.5) * (ANN_EKF_NMPC_2_DW.u_nmpc[1] -
        locvar_Add2_db) + locvar_Add2_db;

      /* '<S44>:1:42' */
      locvar_Divide4_afp = (0.5 - cos(6.2831853071795862 *
        ANN_EKF_NMPC_2_DW.sw_time) * 0.5) * (ANN_EKF_NMPC_2_DW.u_nmpc[2] -
        locvar_Divide4_c1v) + locvar_Divide4_c1v;

      /* '<S44>:1:43' */
      locvar_MathFunction_di = (0.5 - cos(6.2831853071795862 *
        ANN_EKF_NMPC_2_DW.sw_time) * 0.5) * (ANN_EKF_NMPC_2_DW.u_nmpc[3] -
        locvar_Divide4_ch) + locvar_Divide4_ch;
    } else {
      if ((ANN_EKF_NMPC_2_U.PICCIC == 1) && (ANN_EKF_NMPC_2_DW.sw_time > 0.5)) {
        /* '<S44>:1:44' */
        /* '<S44>:1:45' */
        locvar_Divide5_kh = ANN_EKF_NMPC_2_DW.u_nmpc[0];

        /* '<S44>:1:46' */
        locvar_Divide3_j0 = ANN_EKF_NMPC_2_DW.u_nmpc[1];

        /* '<S44>:1:47' */
        locvar_Divide4_afp = ANN_EKF_NMPC_2_DW.u_nmpc[2];

        /* '<S44>:1:48' */
        locvar_MathFunction_di = ANN_EKF_NMPC_2_DW.u_nmpc[3];
      }
    }

    /* time counting */
    if (ANN_EKF_NMPC_2_U.PICCIC == 1) {
      /* '<S44>:1:52' */
      /* '<S44>:1:53' */
      locvar_Gain_ar = ANN_EKF_NMPC_2_DW.sw_time + ANN_EKF_NMPC_2_P.dt;
    }

    /* DataStoreWrite: '<S17>/Data Store Write1' incorporates:
     *  MATLAB Function: '<S17>/Swtching Logic'
     */
    ANN_EKF_NMPC_2_DW.remote_elevator_mem = locvar_Add2_db;

    /* DataStoreWrite: '<S17>/Data Store Write2' incorporates:
     *  MATLAB Function: '<S17>/Swtching Logic'
     */
    ANN_EKF_NMPC_2_DW.remote_aileron_mem = locvar_Divide4_c1v;

    /* DataStoreWrite: '<S17>/Data Store Write3' incorporates:
     *  MATLAB Function: '<S17>/Swtching Logic'
     */
    ANN_EKF_NMPC_2_DW.remote_throttle_mem = locvar_Add_kq;

    /* DataStoreWrite: '<S17>/Data Store Write4' */
    ANN_EKF_NMPC_2_DW.sw_time = locvar_Gain_ar;

    /* DataStoreWrite: '<S17>/Data Store Write5' incorporates:
     *  MATLAB Function: '<S17>/Swtching Logic'
     */
    ANN_EKF_NMPC_2_DW.remote_rudder_mem = locvar_Divide4_ch;

    /* Gain: '<S17>/Gain' */
    ANN_EKF_NMPC_2_B.throttle_cmd = ANN_EKF_NMPC_2_P.Gain_Gain *
      locvar_Divide5_kh;

    /* Gain: '<S17>/Gain1' */
    ANN_EKF_NMPC_2_B.elevator_cmd = ANN_EKF_NMPC_2_P.Gain1_Gain *
      locvar_Divide3_j0;

    /* Gain: '<S17>/Gain2' */
    ANN_EKF_NMPC_2_B.aileron_cmd = ANN_EKF_NMPC_2_P.Gain2_Gain *
      locvar_Divide4_afp;

    /* Gain: '<S17>/Gain3' */
    ANN_EKF_NMPC_2_B.rudder_cmd = ANN_EKF_NMPC_2_P.Gain3_Gain *
      locvar_MathFunction_di;

    /* MATLAB Function: '<S15>/Convert Lat//Lon//Alt to Flat Earth' incorporates:
     *  BusCreator: '<S52>/Bus Creator'
     */
    /* MATLAB Function 'NMPC (subsystem)/GPS to Local/Convert Lat//Lon//Alt to Flat Earth': '<S20>:1' */
    /*  Convert the given LLA coordinates to Flat Earth coordinates. */
    /*  */
    /*  ref_alt - meters ASML */
    /*  ref_lat - deg. */
    /*  ref_lon - deg. */
    /*  */
    /*  Height, North, East are in feet */
    /* '<S20>:1:11' */
    locvar_Height_k = (locvar_Altitude -
                       ANN_EKF_NMPC_2_P.inertial_local_data.ref_alt) *
      3.280839895013123;

    /* '<S20>:1:12' */
    locvar_North_e = (locvar_Latitude -
                      ANN_EKF_NMPC_2_P.inertial_local_data.ref_lat) *
      ANN_EKF_NMPC_2_P.inertial_local_data.fact_lat;

    /* '<S20>:1:13' */
    locvar_East_k = (locvar_Longitude -
                     ANN_EKF_NMPC_2_P.inertial_local_data.ref_lon) *
      ANN_EKF_NMPC_2_P.inertial_local_data.fact_lon;

    /* MATLAB Function: '<S19>/Trajectory Generation' incorporates:
     *  BusCreator: '<S19>/BusConversion_InsertedFor_Trajectory Generation_at_inport_7'
     *  DataStoreRead: '<S19>/Data Store Read1'
     *  DataStoreRead: '<S19>/Data Store Read2'
     *  DataStoreRead: '<S19>/Data Store Read3'
     *  DataStoreRead: '<S19>/Data Store Read4'
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
    for (loctmp_i_0 = 0; loctmp_i_0 < 32; loctmp_i_0++) {
      loctmp_wpts_h[loctmp_i_0] = ANN_EKF_NMPC_2_U.WaypointsIN.h[loctmp_i_0];
      loctmp_wpts_n[loctmp_i_0] = ANN_EKF_NMPC_2_U.WaypointsIN.n[loctmp_i_0];
      loctmp_wpts_e[loctmp_i_0] = ANN_EKF_NMPC_2_U.WaypointsIN.e[loctmp_i_0];
    }

    /* MATLAB Function 'NMPC (subsystem)/Trajectory/Trajectory Generation': '<S48>:1' */
    /* Local Variable Assignment: */
    /* '<S48>:1:7' */
    loctmp_b_index = ANN_EKF_NMPC_2_DW.Waypoint_Index;

    /* '<S48>:1:8' */
    locvar_start_wpt_mem[0] = ANN_EKF_NMPC_2_DW.Start_Wpt[0];
    locvar_start_wpt_mem[1] = ANN_EKF_NMPC_2_DW.Start_Wpt[1];
    locvar_start_wpt_mem[2] = ANN_EKF_NMPC_2_DW.Start_Wpt[2];

    /* '<S48>:1:9' */
    locvar_FixPtRelationalOperator = ANN_EKF_NMPC_2_DW.Home_reset;

    /* PIC/CIC Transition Logic: */
    /*  On transition to CIC or PIC, set index = 0 and current position to  */
    /*  current waypoint; hold current waypoint. */
    if (((int32_T)ANN_EKF_NMPC_2_U.PICCIC > (int32_T)
         ANN_EKF_NMPC_2_DW.PIC_CIC_Last) || (ANN_EKF_NMPC_2_U.PICCIC == 0)) {
      /* '<S48>:1:14' */
      /* '<S48>:1:15' */
      locvar_start_wpt_mem[0] = locvar_Height_k;

      /* '<S48>:1:16' */
      locvar_start_wpt_mem[1] = locvar_North_e;

      /* '<S48>:1:17' */
      locvar_start_wpt_mem[2] = locvar_East_k;

      /* '<S48>:1:19' */
      loctmp_b_index = 0U;

      /* '<S48>:1:20' */
      locvar_FixPtRelationalOperator = 0U;
    }

    /*  Change the waypoint index when home command */
    if ((ANN_EKF_NMPC_2_U.HomeCmd == 1) && (ANN_EKF_NMPC_2_U.PICCIC == 1) &&
        (locvar_FixPtRelationalOperator == 0)) {
      /* '<S48>:1:24' */
      /* '<S48>:1:26' */
      loctmp_b_index = 23U;

      /* '<S48>:1:27' */
      locvar_FixPtRelationalOperator = 1U;
    }

    /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* OP trajectory generation */
    /* %reassigning the a and b waypoints */
    if ((ANN_EKF_NMPC_2_P.TR == 2.0) && (locvar_FixPtRelationalOperator == 0)) {
      /* '<S48>:1:35' */
      /* '<S48>:1:36' */
      loctmp_b_index = 1U;

      /* '<S48>:1:37' */
      loctmp_wpts_n[0] = ANN_EKF_NMPC_2_U.n_op[0] - 100.0 *
        ANN_EKF_NMPC_2_U.vn_op[0];
      loctmp_wpts_n[1] = 100.0 * ANN_EKF_NMPC_2_U.vn_op[0] +
        ANN_EKF_NMPC_2_U.n_op[0];

      /* '<S48>:1:38' */
      loctmp_wpts_e[0] = ANN_EKF_NMPC_2_U.e_op[0] - 100.0 *
        ANN_EKF_NMPC_2_U.ve_op[0];
      loctmp_wpts_e[1] = 100.0 * ANN_EKF_NMPC_2_U.ve_op[0] +
        ANN_EKF_NMPC_2_U.e_op[0];

      /* '<S48>:1:39' */
      loctmp_wpts_h[0] = ANN_EKF_NMPC_2_U.h_op[0] - 100.0 *
        ANN_EKF_NMPC_2_U.vh_op[0];
      loctmp_wpts_h[1] = 100.0 * ANN_EKF_NMPC_2_U.vh_op[0] +
        ANN_EKF_NMPC_2_U.h_op[0];
    }

    /* calculate the next waypoint index: */
    /* '<S48>:1:43' */
    loctmp_i_1 = (int32_T)(loctmp_b_index + 1U);
    if ((uint32_T)loctmp_i_1 > 255U) {
      loctmp_i_1 = 255;
    }

    loctmp_next_wpt_index = (uint8_T)loctmp_i_1;

    /* beyond final point (fp), go to return point (rp) */
    if ((uint8_T)loctmp_i_1 > ANN_EKF_NMPC_2_U.WaypointsIN.fp) {
      /* '<S48>:1:45' */
      /* '<S48>:1:46' */
      loctmp_next_wpt_index = ANN_EKF_NMPC_2_U.WaypointsIN.rp;
    }

    /* calculate distance to next waypoint */
    /* '<S48>:1:49' */
    locvar_Divide4_afp = locvar_North_e - loctmp_wpts_n[loctmp_next_wpt_index -
      1];
    locvar_MathFunction_di = locvar_East_k - loctmp_wpts_e[loctmp_next_wpt_index
      - 1];
    loctmp_distance = sqrt(locvar_Divide4_afp * locvar_Divide4_afp +
      locvar_MathFunction_di * locvar_MathFunction_di);

    /* change to next waypoint if in range */
    if ((loctmp_distance < ANN_EKF_NMPC_2_P.dist2b) && (ANN_EKF_NMPC_2_U.PICCIC ==
         1)) {
      /* '<S48>:1:51' */
      /* '<S48>:1:52' */
      /*  Do not change index if sw=0 */
      /* '<S48>:1:53' */
      loctmp_b_index = loctmp_next_wpt_index;
      if (loctmp_next_wpt_index == ANN_EKF_NMPC_2_U.WaypointsIN.fp) {
        /* '<S48>:1:54' */
        /* '<S48>:1:55' */
        loctmp_next_wpt_index = ANN_EKF_NMPC_2_U.WaypointsIN.rp;
      } else {
        /* '<S48>:1:57' */
        loctmp_i_1 = (int32_T)(loctmp_next_wpt_index + 1U);
        if ((uint32_T)loctmp_i_1 > 255U) {
          loctmp_i_1 = 255;
        }

        loctmp_next_wpt_index = (uint8_T)loctmp_i_1;
      }
    }

    /* function outputs */
    if ((loctmp_b_index == 0) || (loctmp_b_index == 23)) {
      /* '<S48>:1:63' */
      /*  Assign the speed of the starting segment to the speed of the first */
      /*  waypoint */
      /* '<S48>:1:66' */
      locvar_Vab_mod = ANN_EKF_NMPC_2_U.WaypointsIN.v[0];

      /* '<S48>:1:67' */
      loctmp_tmp_7 = locvar_start_wpt_mem[0];

      /* '<S48>:1:68' */
      loctmp_tmp_0 = locvar_start_wpt_mem[1];

      /* '<S48>:1:69' */
      loctmp_tmp = locvar_start_wpt_mem[2];
    } else {
      /* '<S48>:1:71' */
      locvar_Vab_mod = ANN_EKF_NMPC_2_U.WaypointsIN.v[loctmp_b_index - 1];

      /* '<S48>:1:72' */
      loctmp_tmp_7 = loctmp_wpts_h[loctmp_b_index - 1];

      /* '<S48>:1:73' */
      loctmp_tmp_0 = loctmp_wpts_n[loctmp_b_index - 1];

      /* '<S48>:1:74' */
      loctmp_tmp = loctmp_wpts_e[loctmp_b_index - 1];
    }

    /* DataStoreWrite: '<S19>/Data Store Write1' incorporates:
     *  Inport: '<Root>/PIC//CIC'
     */
    /* '<S48>:1:76' */
    /* '<S48>:1:77' */
    /* '<S48>:1:78' */
    /* '<S48>:1:80' */
    /* '<S48>:1:81' */
    /* '<S48>:1:82' */
    ANN_EKF_NMPC_2_DW.PIC_CIC_Last = ANN_EKF_NMPC_2_U.PICCIC;

    /* DataStoreWrite: '<S19>/Data Store Write2' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    ANN_EKF_NMPC_2_DW.Waypoint_Index = loctmp_b_index;

    /* DataStoreWrite: '<S19>/Data Store Write3' */
    ANN_EKF_NMPC_2_DW.Start_Wpt[0] = locvar_start_wpt_mem[0];
    ANN_EKF_NMPC_2_DW.Start_Wpt[1] = locvar_start_wpt_mem[1];
    ANN_EKF_NMPC_2_DW.Start_Wpt[2] = locvar_start_wpt_mem[2];

    /* DataStoreWrite: '<S19>/Data Store Write4' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    ANN_EKF_NMPC_2_DW.Home_reset = locvar_FixPtRelationalOperator;

    /* SampleTimeMath: '<S13>/TSamp' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *
     * About '<S13>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    locvar_TSamp = locvar_Reshape1[5] * ANN_EKF_NMPC_2_P.TSamp_WtEt;

    /* SampleTimeMath: '<S14>/TSamp' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *
     * About '<S14>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    locvar_TSamp_j = locvar_Reshape1[6] * ANN_EKF_NMPC_2_P.TSamp_WtEt_j;

    /* Logic: '<S24>/Logical Operator' incorporates:
     *  Inport: '<Root>/PIC//CIC'
     */
    locvar_LogicalOperator = !ANN_EKF_NMPC_2_U.PICCIC;

    /* DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
    if (locvar_LogicalOperator ||
        (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState != 0)) {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE = ANN_EKF_NMPC_2_P.ro0;
    }

    if (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE >=
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_UpperSat) {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE =
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_UpperSat;
    } else {
      if (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE <=
          ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_LowerSat) {
        ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE =
          ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_LowerSat;
      }
    }

    ANN_EKF_NMPC_2_B.DiscreteTimeIntegrator =
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */

    /* UnitDelay: '<S45>/Unit Delay' */
    locvar_xw11_k = ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_mi;

    /* UnitDelay: '<S45>/Unit Delay1' */
    locvar_xw12_k = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_e;

    /* UnitDelay: '<S45>/Unit Delay2' */
    locvar_xw13_k = ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE;

    /* UnitDelay: '<S45>/Unit Delay3' */
    locvar_xw14_k = ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE;

    /* UnitDelay: '<S46>/Unit Delay' */
    locvar_xw21_k = ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_jh;

    /* UnitDelay: '<S46>/Unit Delay1' */
    locvar_xw22_k = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_n;

    /* UnitDelay: '<S46>/Unit Delay2' */
    locvar_xw23_k = ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_n;

    /* UnitDelay: '<S46>/Unit Delay3' */
    locvar_xw24_k = ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_f;

    /* UnitDelay: '<S47>/Unit Delay' */
    locvar_xw31_k = ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_d;

    /* UnitDelay: '<S47>/Unit Delay1' */
    locvar_xw32_k = ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_j;

    /* UnitDelay: '<S47>/Unit Delay2' */
    locvar_xw33_k = ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_l;

    /* UnitDelay: '<S47>/Unit Delay3' */
    locvar_xw34_k = ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_j;

    /* DataStoreRead: '<S2>/Data Store Read2' */
    memcpy(&locvar_DataStoreRead2_p[0], &ANN_EKF_NMPC_2_DW.u_nmpc[0], 84U *
           sizeof(real_T));

    /* MATLAB Function: '<S2>/Control System' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *  BusCreator: '<S145>/Bus Creator1'
     *  BusCreator: '<S145>/Bus Creator2'
     *  DataStoreRead: '<S2>/Data Store Read2'
     *  DataTypeConversion: '<S2>/Data Type Conversion1'
     *  Inport: '<Root>/Home Cmd'
     *  Inport: '<Root>/PIC//CIC'
     *  Inport: '<Root>/Servo deflection'
     *  Inport: '<Root>/Waypoints IN'
     *  Inport: '<Root>/e_op'
     *  Inport: '<Root>/h_op'
     *  Inport: '<Root>/n_op'
     *  Inport: '<Root>/ve_op'
     *  Inport: '<Root>/vh_op'
     *  Inport: '<Root>/vn_op'
     *  MATLAB Function: '<S19>/Trajectory Generation'
     *  Sum: '<S13>/Diff'
     *  Sum: '<S14>/Diff'
     *  UnitDelay: '<S13>/UD'
     *  UnitDelay: '<S14>/UD'
     *  UnitDelay: '<S45>/Unit Delay'
     *  UnitDelay: '<S45>/Unit Delay1'
     *  UnitDelay: '<S45>/Unit Delay2'
     *  UnitDelay: '<S45>/Unit Delay3'
     *  UnitDelay: '<S46>/Unit Delay'
     *  UnitDelay: '<S46>/Unit Delay1'
     *  UnitDelay: '<S46>/Unit Delay2'
     *  UnitDelay: '<S46>/Unit Delay3'
     *  UnitDelay: '<S47>/Unit Delay'
     *  UnitDelay: '<S47>/Unit Delay1'
     *  UnitDelay: '<S47>/Unit Delay2'
     *  UnitDelay: '<S47>/Unit Delay3'
     */
    loctmp_home_cmd = ANN_EKF_NMPC_2_U.HomeCmd;
    locvar_Add2_ai = ANN_EKF_NMPC_2_P.dt;
    locvar_Divide3_p0a = ANN_EKF_NMPC_2_P.TR;
    locvar_Divide4_i0 = ANN_EKF_NMPC_2_B.c_ann_X_ic;
    locvar_Divide5_dki = ANN_EKF_NMPC_2_B.c_ann_Y_ic;
    locvar_Divide3_poh = ANN_EKF_NMPC_2_B.c_ann_Z_ic;
    locvar_Divide4_hl4 = ANN_EKF_NMPC_2_P.X_minYin;
    locvar_MathFunction_ld = ANN_EKF_NMPC_2_P.X_maxYin;
    locvar_MathFunction1_j = ANN_EKF_NMPC_2_P.X_minXout;
    locvar_Add1_ot = ANN_EKF_NMPC_2_P.X_maxXout;
    locvar_Add_jbj = ANN_EKF_NMPC_2_P.X_minYout;
    locvar_Divide_b = ANN_EKF_NMPC_2_P.X_maxYout;
    locvar_Add1_i0 = ANN_EKF_NMPC_2_P.Y_minYin;
    locvar_Add_oj = ANN_EKF_NMPC_2_P.Y_maxYin;
    locvar_Divide4_hvl = ANN_EKF_NMPC_2_P.Y_minXout;
    locvar_Divide4_dh = ANN_EKF_NMPC_2_P.Y_maxXout;
    locvar_Divide3_ef = ANN_EKF_NMPC_2_P.Y_minYout;
    locvar_Divide4_j0a = ANN_EKF_NMPC_2_P.Y_maxYout;
    locvar_Divide_jg = ANN_EKF_NMPC_2_P.Z_minYin;
    locvar_Add1_dy = ANN_EKF_NMPC_2_P.Z_maxYin;
    locvar_Add_nl = ANN_EKF_NMPC_2_P.Z_minXout;
    locvar_Add_ow = ANN_EKF_NMPC_2_P.Z_maxXout;
    locvar_Divide4_m3z = ANN_EKF_NMPC_2_P.Z_minYout;
    locvar_Divide5_nv = ANN_EKF_NMPC_2_P.Z_maxYout;
    locvar_Divide3_at = ANN_EKF_NMPC_2_P.rho;
    locvar_Divide4_h3 = ANN_EKF_NMPC_2_P.S;
    locvar_MathFunction_hi4 = ANN_EKF_NMPC_2_P.Cbar;
    loctmp_b_b = ANN_EKF_NMPC_2_P.b;
    locvar_MathFunction1_ed = ANN_EKF_NMPC_2_P.weight;
    locvar_Add1_co = ANN_EKF_NMPC_2_P.g;
    locvar_Add_cn = ANN_EKF_NMPC_2_P.IxxB;
    locvar_Divide3_mnp = ANN_EKF_NMPC_2_P.IyyB;
    locvar_Divide4_jr4 = ANN_EKF_NMPC_2_P.IzzB;
    locvar_Divide4_ipd = ANN_EKF_NMPC_2_P.IxzB;
    locvar_Divide5_ol = ANN_EKF_NMPC_2_P.CDu;
    locvar_Divide3_io = ANN_EKF_NMPC_2_P.CDq;
    locvar_Divide4_fy = ANN_EKF_NMPC_2_P.CDadot;
    locvar_MathFunction_iy = ANN_EKF_NMPC_2_P.CDde;
    locvar_MathFunction1_cr = ANN_EKF_NMPC_2_P.CD0_bar;
    locvar_Add1_k4 = ANN_EKF_NMPC_2_P.Cyb;
    locvar_Add_mx3 = ANN_EKF_NMPC_2_P.Cyp;
    locvar_Divide_dc = ANN_EKF_NMPC_2_P.Cyr;
    locvar_Add1_e0 = ANN_EKF_NMPC_2_P.Cyda;
    locvar_Add_df5 = ANN_EKF_NMPC_2_P.Cydr;
    locvar_Divide3_npq = ANN_EKF_NMPC_2_P.CL0;
    locvar_Divide4_lhf = ANN_EKF_NMPC_2_P.CLa;
    locvar_Divide5_pq = ANN_EKF_NMPC_2_P.CLq;
    locvar_Divide3_jze = ANN_EKF_NMPC_2_P.CLadot;
    locvar_Divide4_ncd = ANN_EKF_NMPC_2_P.CLu;
    locvar_MathFunction_pp = ANN_EKF_NMPC_2_P.CLde;
    locvar_MathFunction1_jr = ANN_EKF_NMPC_2_P.Clb;
    locvar_Add1_ef = ANN_EKF_NMPC_2_P.Clp;
    locvar_Add_ccv = ANN_EKF_NMPC_2_P.Clr;
    locvar_Divide_prh = ANN_EKF_NMPC_2_P.Clda;
    locvar_Add1_es = ANN_EKF_NMPC_2_P.Cldr;
    locvar_Add_ifv = ANN_EKF_NMPC_2_P.Cm0;
    locvar_Add1_lq2 = ANN_EKF_NMPC_2_P.Cma;
    locvar_Divide4_ko = ANN_EKF_NMPC_2_P.Cmq;
    locvar_Divide3_b10 = ANN_EKF_NMPC_2_P.Cmadot;
    locvar_Divide4_nh = ANN_EKF_NMPC_2_P.Cmu;
    locvar_Add1_cn2 = ANN_EKF_NMPC_2_P.Cmde;
    locvar_Divide4_m3 = ANN_EKF_NMPC_2_P.Cnb;
    locvar_Divide5_ni = ANN_EKF_NMPC_2_P.Cnp;
    locvar_Divide3_hfk = ANN_EKF_NMPC_2_P.Cnr;
    locvar_Divide4_ng = ANN_EKF_NMPC_2_P.Cnda;
    locvar_MathFunction_e = ANN_EKF_NMPC_2_P.Cndr;
    locvar_MathFunction1_bt = ANN_EKF_NMPC_2_P.xT0;
    locvar_Add1_cl = ANN_EKF_NMPC_2_P.xT1;
    locvar_Add_mtb = ANN_EKF_NMPC_2_P.xT2;
    locvar_Divide_em = ANN_EKF_NMPC_2_P.Ptrim;
    locvar_Add1_j2 = ANN_EKF_NMPC_2_P.Qtrim;
    locvar_Add_oq1 = ANN_EKF_NMPC_2_P.Rtrim;
    locvar_Divide3_bc = ANN_EKF_NMPC_2_P.Utrim;
    locvar_Divide4_mgn = ANN_EKF_NMPC_2_P.Athrottle;
    locvar_Add_nwv = ANN_EKF_NMPC_2_P.Bthrottle;
    locvar_Divide4_kga = ANN_EKF_NMPC_2_P.Aelevator;
    locvar_Add2_ga = ANN_EKF_NMPC_2_P.Belevator;
    locvar_Divide_ad = ANN_EKF_NMPC_2_P.Aaileron;
    locvar_Divide_j0 = ANN_EKF_NMPC_2_P.Baileron;
    locvar_Add_b1 = ANN_EKF_NMPC_2_P.Arudder;
    locvar_Add1_md = ANN_EKF_NMPC_2_P.Brudder;
    locvar_Divide_je = ANN_EKF_NMPC_2_P.ThrottleMax;
    locvar_Add1_ir = ANN_EKF_NMPC_2_P.ThrottleMin;
    locvar_Divide4_ky = ANN_EKF_NMPC_2_P.ElevatorMax;
    locvar_Add_eqw = ANN_EKF_NMPC_2_P.ElevatorMin;
    locvar_Add2_ap = ANN_EKF_NMPC_2_P.AileronMax;
    locvar_Add2_fi = ANN_EKF_NMPC_2_P.AileronMin;
    locvar_Altitude = ANN_EKF_NMPC_2_P.RudderMax;
    locvar_Latitude = ANN_EKF_NMPC_2_P.RudderMin;
    locvar_Longitude = ANN_EKF_NMPC_2_P.KpLat;
    loctmp_b_KiLon = ANN_EKF_NMPC_2_P.KiLon;
    loctmp_b_KpLon = ANN_EKF_NMPC_2_P.KpLon;
    loctmp_b_L = ANN_EKF_NMPC_2_P.L;
    loctmp_b_dist2b = ANN_EKF_NMPC_2_P.dist2b;

    /* MATLAB Function 'NMPC (subsystem)/Control System': '<S12>:1' */
    /* %allocation */
    /* '<S12>:1:59' */
    memset(&loctmp_z_augm_hor[0], 0, 252U * sizeof(real_T));

    /* %nmpc input */
    /* '<S12>:1:62' */
    /* %state horizon */
    /* '<S12>:1:64' */
    /* '<S12>:1:65' */
    /* '<S12>:1:66' */
    /* '<S12>:1:67' */
    /* '<S12>:1:68' */
    /* '<S12>:1:69' */
    /* '<S12>:1:70' */
    /* '<S12>:1:71' */
    /* '<S12>:1:72' */
    /* '<S12>:1:73' */
    /* '<S12>:1:74' */
    /* '<S12>:1:75' */
    /* '<S12>:1:76' */
    /* '<S12>:1:77' */
    /* '<S12>:1:78' */
    /* '<S12>:1:79' */
    /* '<S12>:1:80' */
    for (loctmp_i_1 = 0; loctmp_i_1 < 21; loctmp_i_1++) {
      loctmp_n_hor[loctmp_i_1] = 0.0;
      loctmp_e_hor[loctmp_i_1] = 0.0;
      loctmp_h_hor[loctmp_i_1] = 0.0;
      loctmp_THL_hor[loctmp_i_1] = 0.0;
      loctmp_EL_hor[loctmp_i_1] = 0.0;
      loctmp_AIL_hor[loctmp_i_1] = 0.0;
      loctmp_RDR_hor[loctmp_i_1] = 0.0;
      loctmp_VT_hor[loctmp_i_1] = 0.0;
      loctmp_alpha_hor[loctmp_i_1] = 0.0;
      loctmp_beta_hor[loctmp_i_1] = 0.0;
      loctmp_phi_hor[loctmp_i_1] = 0.0;
      loctmp_theta_hor[loctmp_i_1] = 0.0;
      loctmp_psi_hor[loctmp_i_1] = 0.0;
      loctmp_P_hor[loctmp_i_1] = 0.0;
      loctmp_Q_hor[loctmp_i_1] = 0.0;
      loctmp_R_hor[loctmp_i_1] = 0.0;
      loctmp_wpt_index_hor[loctmp_i_1] = 0.0;
    }

    /* '<S12>:1:81' */
    memset(&loctmp_start_wpt_hor[0], 0, 63U * sizeof(real_T));

    /* '<S12>:1:82' */
    /* '<S12>:1:83' */
    /* '<S12>:1:84' */
    /* '<S12>:1:85' */
    /* '<S12>:1:86' */
    /* '<S12>:1:87' */
    /* '<S12>:1:88' */
    /* '<S12>:1:89' */
    /* '<S12>:1:90' */
    /* '<S12>:1:91' */
    /* '<S12>:1:92' */
    /* '<S12>:1:93' */
    /* '<S12>:1:94' */
    /* '<S12>:1:95' */
    /* '<S12>:1:96' */
    /* '<S12>:1:97' */
    /* '<S12>:1:98' */
    for (loctmp_i_1 = 0; loctmp_i_1 < 21; loctmp_i_1++) {
      loctmp_pic_cic_hor[loctmp_i_1] = 0.0;
      loctmp_home_reset_hor[loctmp_i_1] = 0.0;
      loctmp_alphadot_hor[loctmp_i_1] = 0.0;
      loctmp_betadot_hor[loctmp_i_1] = 0.0;
      loctmp_ro_hor[loctmp_i_1] = 0.0;
      loctmp_xw11_hor[loctmp_i_1] = 0.0;
      loctmp_xw12_hor[loctmp_i_1] = 0.0;
      loctmp_xw13_hor[loctmp_i_1] = 0.0;
      loctmp_xw14_hor[loctmp_i_1] = 0.0;
      loctmp_xw21_hor[loctmp_i_1] = 0.0;
      loctmp_xw22_hor[loctmp_i_1] = 0.0;
      loctmp_xw23_hor[loctmp_i_1] = 0.0;
      loctmp_xw24_hor[loctmp_i_1] = 0.0;
      loctmp_xw31_hor[loctmp_i_1] = 0.0;
      loctmp_xw32_hor[loctmp_i_1] = 0.0;
      loctmp_xw33_hor[loctmp_i_1] = 0.0;
      loctmp_xw34_hor[loctmp_i_1] = 0.0;
    }

    /* %%%horizon prediction: x_1 to x_N_nmpc+1%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %servo commands%% */
    /* '<S12>:1:103' */
    /* '<S12>:1:104' */
    /* '<S12>:1:105' */
    /* '<S12>:1:106' */
    /*  %assumed zero wind */
    for (loctmp_i_1 = 0; loctmp_i_1 < 32; loctmp_i_1++) {
      loctmp_tmp_1[loctmp_i_1] = ANN_EKF_NMPC_2_U.WaypointsIN.h[loctmp_i_1];
      loctmp_tmp_2[loctmp_i_1] = ANN_EKF_NMPC_2_U.WaypointsIN.n[loctmp_i_1];
      loctmp_tmp_3[loctmp_i_1] = ANN_EKF_NMPC_2_U.WaypointsIN.e[loctmp_i_1];
    }

    ANN_EKF_NMPC_2_uas_augm_model((real_T)ANN_EKF_NMPC_2_U.PICCIC,
      ANN_EKF_NMPC_2_U.HomeCmd, ANN_EKF_NMPC_2_P.dt, ANN_EKF_NMPC_2_P.TR,
      ANN_EKF_NMPC_2_U.WaypointsIN.fp, ANN_EKF_NMPC_2_U.WaypointsIN.rp,
      loctmp_tmp_1, loctmp_tmp_2, loctmp_tmp_3, ANN_EKF_NMPC_2_U.WaypointsIN.v,
      ANN_EKF_NMPC_2_U.n_op[0], ANN_EKF_NMPC_2_U.e_op[0], ANN_EKF_NMPC_2_U.h_op
      [0], ANN_EKF_NMPC_2_U.vn_op[0], ANN_EKF_NMPC_2_U.ve_op[0],
      ANN_EKF_NMPC_2_U.vh_op[0], locvar_TSamp - ANN_EKF_NMPC_2_DW.UD_DSTATE,
      locvar_TSamp_j - ANN_EKF_NMPC_2_DW.UD_DSTATE_o, loctmp_b_index,
      locvar_start_wpt_mem, ANN_EKF_NMPC_2_U.PICCIC,
      locvar_FixPtRelationalOperator, ANN_EKF_NMPC_2_U.Servodeflection[0],
      ANN_EKF_NMPC_2_U.Servodeflection[1], ANN_EKF_NMPC_2_U.Servodeflection[2],
      ANN_EKF_NMPC_2_U.Servodeflection[3], locvar_Reshape1[4], locvar_Reshape1[5],
      locvar_Reshape1[6], locvar_Reshape1[7], locvar_Reshape1[8],
      loctmp_locvar_BusCreator1_psi, locvar_Reshape1[9], locvar_Reshape1[10],
      locvar_Reshape1[11], locvar_North_e, locvar_East_k, locvar_Height_k,
      ANN_EKF_NMPC_2_B.DiscreteTimeIntegrator, ANN_EKF_NMPC_2_DW.u_nmpc[0],
      ANN_EKF_NMPC_2_DW.u_nmpc[1], ANN_EKF_NMPC_2_DW.u_nmpc[2],
      ANN_EKF_NMPC_2_DW.u_nmpc[3], ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_mi,
      ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_e, ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE,
      ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE, ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_jh,
      ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_n,
      ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_n,
      ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_f,
      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_d,
      ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_j,
      ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_l,
      ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_j, ANN_EKF_NMPC_2_P.W11d,
      ANN_EKF_NMPC_2_P.W12d, ANN_EKF_NMPC_2_P.W13d, ANN_EKF_NMPC_2_P.W14d,
      ANN_EKF_NMPC_2_P.W21d, ANN_EKF_NMPC_2_P.W22d, ANN_EKF_NMPC_2_P.W23d,
      ANN_EKF_NMPC_2_P.W24d, ANN_EKF_NMPC_2_P.W31d, ANN_EKF_NMPC_2_P.W32d,
      ANN_EKF_NMPC_2_P.W33d, ANN_EKF_NMPC_2_P.W34d, ANN_EKF_NMPC_2_P.rho,
      ANN_EKF_NMPC_2_P.S, ANN_EKF_NMPC_2_P.Cbar, ANN_EKF_NMPC_2_P.b,
      ANN_EKF_NMPC_2_P.weight, ANN_EKF_NMPC_2_P.g, ANN_EKF_NMPC_2_P.IxxB,
      ANN_EKF_NMPC_2_P.IyyB, ANN_EKF_NMPC_2_P.IzzB, ANN_EKF_NMPC_2_P.IxzB,
      ANN_EKF_NMPC_2_P.CDu, ANN_EKF_NMPC_2_P.CDq, ANN_EKF_NMPC_2_P.CDadot,
      ANN_EKF_NMPC_2_P.CDde, ANN_EKF_NMPC_2_P.CD0_bar, ANN_EKF_NMPC_2_P.Cyb,
      ANN_EKF_NMPC_2_P.Cyp, ANN_EKF_NMPC_2_P.Cyr, ANN_EKF_NMPC_2_P.Cyda,
      ANN_EKF_NMPC_2_P.Cydr, ANN_EKF_NMPC_2_P.CL0, ANN_EKF_NMPC_2_P.CLa,
      ANN_EKF_NMPC_2_P.CLq, ANN_EKF_NMPC_2_P.CLadot, ANN_EKF_NMPC_2_P.CLu,
      ANN_EKF_NMPC_2_P.CLde, ANN_EKF_NMPC_2_P.Clb, ANN_EKF_NMPC_2_P.Clp,
      ANN_EKF_NMPC_2_P.Clr, ANN_EKF_NMPC_2_P.Clda, ANN_EKF_NMPC_2_P.Cldr,
      ANN_EKF_NMPC_2_P.Cm0, ANN_EKF_NMPC_2_P.Cma, ANN_EKF_NMPC_2_P.Cmq,
      ANN_EKF_NMPC_2_P.Cmadot, ANN_EKF_NMPC_2_P.Cmu, ANN_EKF_NMPC_2_P.Cmde,
      ANN_EKF_NMPC_2_P.Cnb, ANN_EKF_NMPC_2_P.Cnp, ANN_EKF_NMPC_2_P.Cnr,
      ANN_EKF_NMPC_2_P.Cnda, ANN_EKF_NMPC_2_P.Cndr, ANN_EKF_NMPC_2_P.xT0,
      ANN_EKF_NMPC_2_P.xT1, ANN_EKF_NMPC_2_P.xT2, ANN_EKF_NMPC_2_P.Ptrim,
      ANN_EKF_NMPC_2_P.Qtrim, ANN_EKF_NMPC_2_P.Rtrim, ANN_EKF_NMPC_2_P.Utrim,
      ANN_EKF_NMPC_2_P.Athrottle, ANN_EKF_NMPC_2_P.Bthrottle,
      ANN_EKF_NMPC_2_P.Aelevator, ANN_EKF_NMPC_2_P.Belevator,
      ANN_EKF_NMPC_2_P.Aaileron, ANN_EKF_NMPC_2_P.Baileron,
      ANN_EKF_NMPC_2_P.Arudder, ANN_EKF_NMPC_2_P.Brudder,
      ANN_EKF_NMPC_2_P.ThrottleMax, ANN_EKF_NMPC_2_P.ThrottleMin,
      ANN_EKF_NMPC_2_P.ElevatorMax, ANN_EKF_NMPC_2_P.ElevatorMin,
      ANN_EKF_NMPC_2_P.AileronMax, ANN_EKF_NMPC_2_P.AileronMin,
      ANN_EKF_NMPC_2_P.RudderMax, ANN_EKF_NMPC_2_P.RudderMin,
      ANN_EKF_NMPC_2_P.KpLat, ANN_EKF_NMPC_2_P.KiLon, ANN_EKF_NMPC_2_P.KpLon,
      ANN_EKF_NMPC_2_P.L, ANN_EKF_NMPC_2_P.dist2b, locvar_Delay100dt,
      ANN_EKF_NMPC_2_B.a_ann_X_ic, ANN_EKF_NMPC_2_B.b_ann_X_ic,
      ANN_EKF_NMPC_2_B.c_ann_X_ic, ANN_EKF_NMPC_2_B.w_ann_X_ic,
      ANN_EKF_NMPC_2_B.a_ann_Y_ic, ANN_EKF_NMPC_2_B.b_ann_Y_ic,
      ANN_EKF_NMPC_2_B.c_ann_Y_ic, ANN_EKF_NMPC_2_B.w_ann_Y_ic,
      ANN_EKF_NMPC_2_B.a_ann_Z_ic, ANN_EKF_NMPC_2_B.b_ann_Z_ic,
      ANN_EKF_NMPC_2_B.c_ann_Z_ic, ANN_EKF_NMPC_2_B.w_ann_Z_ic,
      ANN_EKF_NMPC_2_P.X_minXin, ANN_EKF_NMPC_2_P.X_maxXin,
      ANN_EKF_NMPC_2_P.X_minYin, ANN_EKF_NMPC_2_P.X_maxYin,
      ANN_EKF_NMPC_2_P.X_minXout, ANN_EKF_NMPC_2_P.X_maxXout,
      ANN_EKF_NMPC_2_P.X_minYout, ANN_EKF_NMPC_2_P.X_maxYout,
      ANN_EKF_NMPC_2_P.Y_minXin, ANN_EKF_NMPC_2_P.Y_maxXin,
      ANN_EKF_NMPC_2_P.Y_minYin, ANN_EKF_NMPC_2_P.Y_maxYin,
      ANN_EKF_NMPC_2_P.Y_minXout, ANN_EKF_NMPC_2_P.Y_maxXout,
      ANN_EKF_NMPC_2_P.Y_minYout, ANN_EKF_NMPC_2_P.Y_maxYout,
      ANN_EKF_NMPC_2_P.Z_minXin, ANN_EKF_NMPC_2_P.Z_maxXin,
      ANN_EKF_NMPC_2_P.Z_minYin, ANN_EKF_NMPC_2_P.Z_maxYin,
      ANN_EKF_NMPC_2_P.Z_minXout, ANN_EKF_NMPC_2_P.Z_maxXout,
      ANN_EKF_NMPC_2_P.Z_minYout, ANN_EKF_NMPC_2_P.Z_maxYout, &loctmp_unusedU0,
      &loctmp_c, &locvar_Gain_ar, &loctmp_f, &locvar_Add_kq, &locvar_Divide4_c1v,
      &locvar_Divide4_ch, &locvar_Add2_db, &locvar_Divide5_kh,
      &locvar_Divide3_j0, &locvar_Divide4_afp, &locvar_MathFunction_di,
      &locvar_MathFunction1_e4, &locvar_Add1_o3, &locvar_Add_au,
      &locvar_Divide_aa, &locvar_Add1_ob, &locvar_Add_pii, &locvar_Divide3_oc,
      loctmp_h, loctmp_i, &locvar_Add_ev, &locvar_Divide4_oem,
      &locvar_Divide5_ny, &locvar_Divide3_ai5, &locvar_Divide4_ik,
      &locvar_MathFunction_bv, &locvar_MathFunction1_id, &locvar_Saturation_m,
      &locvar_Add1_ety, &locvar_Add_ez, &locvar_Divide_n0, &locvar_Add1_pkj,
      &locvar_Add_df3, &locvar_Divide4_kz, &locvar_Add2_o3, &locvar_Divide3_bt,
      &locvar_Divide4_fqv, &locvar_Divide5_luy, &locvar_Divide3_n5,
      &locvar_Divide4_pem, &locvar_MathFunction_p2, &locvar_MathFunction1_ot,
      &locvar_Add_me, &locvar_TrigonometricFunction1_d5j,
      &locvar_TrigonometricFunction2_lt, &locvar_Add1_jqe, &locvar_Add_ay,
      &locvar_Divide_ft, &locvar_Add1_mq, &locvar_Add_bs, &locvar_Divide4_dt);

    /* '<S12>:1:109' */
    loctmp_wpt_index_hor[0] = loctmp_c;

    /* '<S12>:1:109' */
    loctmp_start_wpt_hor[0] = locvar_start_wpt_mem[0];
    loctmp_start_wpt_hor[1] = locvar_start_wpt_mem[1];
    loctmp_start_wpt_hor[2] = locvar_start_wpt_mem[2];

    /* '<S12>:1:109' */
    loctmp_pic_cic_hor[0] = locvar_Gain_ar;

    /* '<S12>:1:109' */
    loctmp_home_reset_hor[0] = loctmp_f;

    /* '<S12>:1:117' */
    memcpy(&loctmp_z_augm_hor[0], &loctmp_h[0], 12U * sizeof(real_T));

    /* '<S12>:1:118' */
    loctmp_THL_hor[0] = locvar_Add_ev;

    /* '<S12>:1:118' */
    loctmp_EL_hor[0] = locvar_Divide4_oem;

    /* '<S12>:1:118' */
    loctmp_AIL_hor[0] = locvar_Divide5_ny;

    /* '<S12>:1:118' */
    loctmp_RDR_hor[0] = locvar_Divide3_ai5;

    /* '<S12>:1:119' */
    loctmp_VT_hor[0] = locvar_Divide4_ik;

    /* '<S12>:1:119' */
    loctmp_alpha_hor[0] = locvar_MathFunction_bv;

    /* '<S12>:1:119' */
    loctmp_beta_hor[0] = locvar_MathFunction1_id;

    /* '<S12>:1:119' */
    loctmp_phi_hor[0] = locvar_Saturation_m;

    /* '<S12>:1:119' */
    loctmp_theta_hor[0] = locvar_Add1_ety;

    /* '<S12>:1:119' */
    loctmp_psi_hor[0] = locvar_Add_ez;

    /* '<S12>:1:119' */
    loctmp_P_hor[0] = locvar_Divide_n0;

    /* '<S12>:1:119' */
    loctmp_Q_hor[0] = locvar_Add1_pkj;

    /* '<S12>:1:119' */
    loctmp_R_hor[0] = locvar_Add_df3;

    /* '<S12>:1:120' */
    loctmp_alphadot_hor[0] = locvar_Divide4_kz;

    /* '<S12>:1:120' */
    loctmp_betadot_hor[0] = locvar_Add2_o3;

    /* '<S12>:1:121' */
    loctmp_n_hor[0] = locvar_Divide3_bt;

    /* '<S12>:1:121' */
    loctmp_e_hor[0] = locvar_Divide4_fqv;

    /* '<S12>:1:121' */
    loctmp_h_hor[0] = locvar_Divide5_luy;

    /* '<S12>:1:122' */
    loctmp_ro_hor[0] = locvar_Divide3_n5;

    /* '<S12>:1:123' */
    loctmp_xw11_hor[0] = locvar_Divide4_pem;

    /* '<S12>:1:123' */
    loctmp_xw12_hor[0] = locvar_MathFunction_p2;

    /* '<S12>:1:123' */
    loctmp_xw13_hor[0] = locvar_MathFunction1_ot;

    /* '<S12>:1:123' */
    loctmp_xw14_hor[0] = locvar_Add_me;

    /* '<S12>:1:124' */
    loctmp_xw21_hor[0] = locvar_TrigonometricFunction1_d5j;

    /* '<S12>:1:124' */
    loctmp_xw22_hor[0] = locvar_TrigonometricFunction2_lt;

    /* '<S12>:1:124' */
    loctmp_xw23_hor[0] = locvar_Add1_jqe;

    /* '<S12>:1:124' */
    loctmp_xw24_hor[0] = locvar_Add_ay;

    /* '<S12>:1:125' */
    loctmp_xw31_hor[0] = locvar_Divide_ft;

    /* '<S12>:1:125' */
    loctmp_xw32_hor[0] = locvar_Add1_mq;

    /* '<S12>:1:125' */
    loctmp_xw33_hor[0] = locvar_Add_bs;

    /* '<S12>:1:125' */
    loctmp_xw34_hor[0] = locvar_Divide4_dt;

    /* %horizon */
    /* '<S12>:1:180' */
    for (loctmp_i_1 = 0; loctmp_i_1 < 20; loctmp_i_1++) {
      loctmp_u_hor[loctmp_i_1 << 2] = locvar_DataStoreRead2_p[(1 + loctmp_i_1) <<
        2];
      loctmp_u_hor[1 + (loctmp_i_1 << 2)] = locvar_DataStoreRead2_p[((1 +
        loctmp_i_1) << 2) + 1];
      loctmp_u_hor[2 + (loctmp_i_1 << 2)] = locvar_DataStoreRead2_p[((1 +
        loctmp_i_1) << 2) + 2];
      loctmp_u_hor[3 + (loctmp_i_1 << 2)] = locvar_DataStoreRead2_p[((1 +
        loctmp_i_1) << 2) + 3];
    }

    loctmp_u_hor[80] = locvar_DataStoreRead2_p[80];
    loctmp_u_hor[81] = locvar_DataStoreRead2_p[81];
    loctmp_u_hor[82] = locvar_DataStoreRead2_p[82];
    loctmp_u_hor[83] = locvar_DataStoreRead2_p[83];

    /* '<S12>:1:182' */
    for (loctmp_i_0 = 0; loctmp_i_0 < 20; loctmp_i_0++) {
      /* '<S12>:1:182' */
      /*  %assumed zero wind */
      locvar_start_wpt_mem[0] = loctmp_start_wpt_hor[3 * loctmp_i_0];
      locvar_start_wpt_mem[1] = loctmp_start_wpt_hor[3 * loctmp_i_0 + 1];
      locvar_start_wpt_mem[2] = loctmp_start_wpt_hor[3 * loctmp_i_0 + 2];
      for (loctmp_i_1 = 0; loctmp_i_1 < 32; loctmp_i_1++) {
        loctmp_tmp_1[loctmp_i_1] = ANN_EKF_NMPC_2_U.WaypointsIN.h[loctmp_i_1];
        loctmp_tmp_2[loctmp_i_1] = ANN_EKF_NMPC_2_U.WaypointsIN.n[loctmp_i_1];
        loctmp_tmp_3[loctmp_i_1] = ANN_EKF_NMPC_2_U.WaypointsIN.e[loctmp_i_1];
      }

      ANN_EKF_NMPC_2_uas_augm_model_m((real_T)locvar_DataTypeConversion1,
        loctmp_home_cmd, locvar_Add2_ai, locvar_Divide3_p0a,
        ANN_EKF_NMPC_2_U.WaypointsIN.fp, ANN_EKF_NMPC_2_U.WaypointsIN.rp,
        loctmp_tmp_1, loctmp_tmp_2, loctmp_tmp_3, ANN_EKF_NMPC_2_U.WaypointsIN.v,
        ANN_EKF_NMPC_2_U.n_op[1 + loctmp_i_0], ANN_EKF_NMPC_2_U.e_op[1 +
        loctmp_i_0], ANN_EKF_NMPC_2_U.h_op[1 + loctmp_i_0],
        ANN_EKF_NMPC_2_U.vn_op[1 + loctmp_i_0], ANN_EKF_NMPC_2_U.ve_op[1 +
        loctmp_i_0], ANN_EKF_NMPC_2_U.vh_op[1 + loctmp_i_0],
        loctmp_alphadot_hor[loctmp_i_0], loctmp_betadot_hor[loctmp_i_0],
        loctmp_wpt_index_hor[loctmp_i_0], locvar_start_wpt_mem,
        loctmp_pic_cic_hor[loctmp_i_0], loctmp_home_reset_hor[loctmp_i_0],
        loctmp_THL_hor[loctmp_i_0], loctmp_EL_hor[loctmp_i_0],
        loctmp_AIL_hor[loctmp_i_0], loctmp_RDR_hor[loctmp_i_0],
        loctmp_VT_hor[loctmp_i_0], loctmp_alpha_hor[loctmp_i_0],
        loctmp_beta_hor[loctmp_i_0], loctmp_phi_hor[loctmp_i_0],
        loctmp_theta_hor[loctmp_i_0], loctmp_psi_hor[loctmp_i_0],
        loctmp_P_hor[loctmp_i_0], loctmp_Q_hor[loctmp_i_0],
        loctmp_R_hor[loctmp_i_0], loctmp_n_hor[loctmp_i_0],
        loctmp_e_hor[loctmp_i_0], loctmp_h_hor[loctmp_i_0],
        loctmp_ro_hor[loctmp_i_0], loctmp_u_hor[loctmp_i_0 << 2], loctmp_u_hor[1
        + (loctmp_i_0 << 2)], loctmp_u_hor[2 + (loctmp_i_0 << 2)], loctmp_u_hor
        [3 + (loctmp_i_0 << 2)], loctmp_xw11_hor[loctmp_i_0],
        loctmp_xw12_hor[loctmp_i_0], loctmp_xw13_hor[loctmp_i_0],
        loctmp_xw14_hor[loctmp_i_0], loctmp_xw21_hor[loctmp_i_0],
        loctmp_xw22_hor[loctmp_i_0], loctmp_xw23_hor[loctmp_i_0],
        loctmp_xw24_hor[loctmp_i_0], loctmp_xw31_hor[loctmp_i_0],
        loctmp_xw32_hor[loctmp_i_0], loctmp_xw33_hor[loctmp_i_0],
        loctmp_xw34_hor[loctmp_i_0], ANN_EKF_NMPC_2_P.W11d,
        ANN_EKF_NMPC_2_P.W12d, ANN_EKF_NMPC_2_P.W13d, ANN_EKF_NMPC_2_P.W14d,
        ANN_EKF_NMPC_2_P.W21d, ANN_EKF_NMPC_2_P.W22d, ANN_EKF_NMPC_2_P.W23d,
        ANN_EKF_NMPC_2_P.W24d, ANN_EKF_NMPC_2_P.W31d, ANN_EKF_NMPC_2_P.W32d,
        ANN_EKF_NMPC_2_P.W33d, ANN_EKF_NMPC_2_P.W34d, locvar_Divide3_at,
        locvar_Divide4_h3, locvar_MathFunction_hi4, loctmp_b_b,
        locvar_MathFunction1_ed, locvar_Add1_co, locvar_Add_cn,
        locvar_Divide3_mnp, locvar_Divide4_jr4, locvar_Divide4_ipd,
        locvar_Divide5_ol, locvar_Divide3_io, locvar_Divide4_fy,
        locvar_MathFunction_iy, locvar_MathFunction1_cr, locvar_Add1_k4,
        locvar_Add_mx3, locvar_Divide_dc, locvar_Add1_e0, locvar_Add_df5,
        locvar_Divide3_npq, locvar_Divide4_lhf, locvar_Divide5_pq,
        locvar_Divide3_jze, locvar_Divide4_ncd, locvar_MathFunction_pp,
        locvar_MathFunction1_jr, locvar_Add1_ef, locvar_Add_ccv,
        locvar_Divide_prh, locvar_Add1_es, locvar_Add_ifv, locvar_Add1_lq2,
        locvar_Divide4_ko, locvar_Divide3_b10, locvar_Divide4_nh,
        locvar_Add1_cn2, locvar_Divide4_m3, locvar_Divide5_ni,
        locvar_Divide3_hfk, locvar_Divide4_ng, locvar_MathFunction_e,
        locvar_MathFunction1_bt, locvar_Add1_cl, locvar_Add_mtb,
        locvar_Divide_em, locvar_Add1_j2, locvar_Add_oq1, locvar_Divide3_bc,
        locvar_Divide4_mgn, locvar_Add_nwv, locvar_Divide4_kga, locvar_Add2_ga,
        locvar_Divide_ad, locvar_Divide_j0, locvar_Add_b1, locvar_Add1_md,
        locvar_Divide_je, locvar_Add1_ir, locvar_Divide4_ky, locvar_Add_eqw,
        locvar_Add2_ap, locvar_Add2_fi, locvar_Altitude, locvar_Latitude,
        locvar_Longitude, loctmp_b_KiLon, loctmp_b_KpLon, loctmp_b_L,
        loctmp_b_dist2b, locvar_Delay100dt, ANN_EKF_NMPC_2_B.a_ann_X_ic,
        ANN_EKF_NMPC_2_B.b_ann_X_ic, locvar_Divide4_i0,
        ANN_EKF_NMPC_2_B.w_ann_X_ic, ANN_EKF_NMPC_2_B.a_ann_Y_ic,
        ANN_EKF_NMPC_2_B.b_ann_Y_ic, locvar_Divide5_dki,
        ANN_EKF_NMPC_2_B.w_ann_Y_ic, ANN_EKF_NMPC_2_B.a_ann_Z_ic,
        ANN_EKF_NMPC_2_B.b_ann_Z_ic, locvar_Divide3_poh,
        ANN_EKF_NMPC_2_B.w_ann_Z_ic, ANN_EKF_NMPC_2_P.X_minXin,
        ANN_EKF_NMPC_2_P.X_maxXin, locvar_Divide4_hl4, locvar_MathFunction_ld,
        locvar_MathFunction1_j, locvar_Add1_ot, locvar_Add_jbj, locvar_Divide_b,
        ANN_EKF_NMPC_2_P.Y_minXin, ANN_EKF_NMPC_2_P.Y_maxXin, locvar_Add1_i0,
        locvar_Add_oj, locvar_Divide4_hvl, locvar_Divide4_dh, locvar_Divide3_ef,
        locvar_Divide4_j0a, ANN_EKF_NMPC_2_P.Z_minXin, ANN_EKF_NMPC_2_P.Z_maxXin,
        locvar_Divide_jg, locvar_Add1_dy, locvar_Add_nl, locvar_Add_ow,
        locvar_Divide4_m3z, locvar_Divide5_nv, &loctmp_unusedU0,
        &locvar_FixPtRelationalOperator, &locvar_Gain_ar, &loctmp_c,
        &locvar_Add_kq, &locvar_Divide4_c1v, &locvar_Divide4_ch, &locvar_Add2_db,
        &locvar_Divide5_kh, &locvar_Divide3_j0, &locvar_Divide4_afp,
        &locvar_MathFunction_di, &locvar_MathFunction1_e4, &locvar_Add1_o3,
        &locvar_Add_au, &locvar_Divide_aa, &locvar_Add1_ob, &locvar_Add_pii,
        &locvar_Divide3_oc, loctmp_h, loctmp_i, &locvar_Add_ev,
        &locvar_Divide4_oem, &locvar_Divide5_ny, &locvar_Divide3_ai5,
        &locvar_Divide4_ik, &locvar_MathFunction_bv, &locvar_MathFunction1_id,
        &locvar_Saturation_m, &locvar_Add1_ety, &locvar_Add_ez,
        &locvar_Divide_n0, &locvar_Add1_pkj, &locvar_Add_df3, &locvar_Divide4_kz,
        &locvar_Add2_o3, &locvar_Divide3_bt, &locvar_Divide4_fqv,
        &locvar_Divide5_luy, &locvar_Divide3_n5, &locvar_Divide4_pem,
        &locvar_MathFunction_p2, &locvar_MathFunction1_ot, &locvar_Add_me,
        &locvar_TrigonometricFunction1_d5j, &locvar_TrigonometricFunction2_lt,
        &locvar_Add1_jqe, &locvar_Add_ay, &locvar_Divide_ft, &locvar_Add1_mq,
        &locvar_Add_bs, &locvar_Divide4_dt);

      /* '<S12>:1:185' */
      loctmp_wpt_index_hor[1 + loctmp_i_0] = locvar_FixPtRelationalOperator;

      /* '<S12>:1:185' */
      loctmp_start_wpt_hor[3 * (loctmp_i_0 + 1)] = locvar_start_wpt_mem[0];
      loctmp_start_wpt_hor[1 + 3 * (loctmp_i_0 + 1)] = locvar_start_wpt_mem[1];
      loctmp_start_wpt_hor[2 + 3 * (loctmp_i_0 + 1)] = locvar_start_wpt_mem[2];

      /* '<S12>:1:185' */
      loctmp_pic_cic_hor[1 + loctmp_i_0] = locvar_Gain_ar;

      /* '<S12>:1:185' */
      loctmp_home_reset_hor[1 + loctmp_i_0] = loctmp_c;

      /* '<S12>:1:193' */
      memcpy(&loctmp_z_augm_hor[12 * (loctmp_i_0 + 1)], &loctmp_h[0], 12U *
             sizeof(real_T));

      /* '<S12>:1:194' */
      loctmp_THL_hor[1 + loctmp_i_0] = locvar_Add_ev;

      /* '<S12>:1:194' */
      loctmp_EL_hor[1 + loctmp_i_0] = locvar_Divide4_oem;

      /* '<S12>:1:194' */
      loctmp_AIL_hor[1 + loctmp_i_0] = locvar_Divide5_ny;

      /* '<S12>:1:194' */
      loctmp_RDR_hor[1 + loctmp_i_0] = locvar_Divide3_ai5;

      /* '<S12>:1:195' */
      loctmp_VT_hor[1 + loctmp_i_0] = locvar_Divide4_ik;

      /* '<S12>:1:195' */
      loctmp_alpha_hor[1 + loctmp_i_0] = locvar_MathFunction_bv;

      /* '<S12>:1:195' */
      loctmp_beta_hor[1 + loctmp_i_0] = locvar_MathFunction1_id;

      /* '<S12>:1:195' */
      loctmp_phi_hor[1 + loctmp_i_0] = locvar_Saturation_m;

      /* '<S12>:1:195' */
      loctmp_theta_hor[1 + loctmp_i_0] = locvar_Add1_ety;

      /* '<S12>:1:195' */
      loctmp_psi_hor[1 + loctmp_i_0] = locvar_Add_ez;

      /* '<S12>:1:195' */
      loctmp_P_hor[1 + loctmp_i_0] = locvar_Divide_n0;

      /* '<S12>:1:195' */
      loctmp_Q_hor[1 + loctmp_i_0] = locvar_Add1_pkj;

      /* '<S12>:1:195' */
      loctmp_R_hor[1 + loctmp_i_0] = locvar_Add_df3;

      /* '<S12>:1:196' */
      loctmp_alphadot_hor[1 + loctmp_i_0] = locvar_Divide4_kz;

      /* '<S12>:1:196' */
      loctmp_betadot_hor[1 + loctmp_i_0] = locvar_Add2_o3;

      /* '<S12>:1:197' */
      loctmp_n_hor[1 + loctmp_i_0] = locvar_Divide3_bt;

      /* '<S12>:1:197' */
      loctmp_e_hor[1 + loctmp_i_0] = locvar_Divide4_fqv;

      /* '<S12>:1:197' */
      loctmp_h_hor[1 + loctmp_i_0] = locvar_Divide5_luy;

      /* '<S12>:1:198' */
      loctmp_ro_hor[1 + loctmp_i_0] = locvar_Divide3_n5;

      /* '<S12>:1:199' */
      loctmp_xw11_hor[1 + loctmp_i_0] = locvar_Divide4_pem;

      /* '<S12>:1:199' */
      loctmp_xw12_hor[1 + loctmp_i_0] = locvar_MathFunction_p2;

      /* '<S12>:1:199' */
      loctmp_xw13_hor[1 + loctmp_i_0] = locvar_MathFunction1_ot;

      /* '<S12>:1:199' */
      loctmp_xw14_hor[1 + loctmp_i_0] = locvar_Add_me;

      /* '<S12>:1:200' */
      loctmp_xw21_hor[1 + loctmp_i_0] = locvar_TrigonometricFunction1_d5j;

      /* '<S12>:1:200' */
      loctmp_xw22_hor[1 + loctmp_i_0] = locvar_TrigonometricFunction2_lt;

      /* '<S12>:1:200' */
      loctmp_xw23_hor[1 + loctmp_i_0] = locvar_Add1_jqe;

      /* '<S12>:1:200' */
      loctmp_xw24_hor[1 + loctmp_i_0] = locvar_Add_ay;

      /* '<S12>:1:201' */
      loctmp_xw31_hor[1 + loctmp_i_0] = locvar_Divide_ft;

      /* '<S12>:1:201' */
      loctmp_xw32_hor[1 + loctmp_i_0] = locvar_Add1_mq;

      /* '<S12>:1:201' */
      loctmp_xw33_hor[1 + loctmp_i_0] = locvar_Add_bs;

      /* '<S12>:1:201' */
      loctmp_xw34_hor[1 + loctmp_i_0] = locvar_Divide4_dt;

      /* '<S12>:1:182' */
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%prediction of x_2 to x_N_nmp1+1%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%calculation of control signal%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    ANN_EKF_NMPC_2_nmpc_iteration((real_T)locvar_DataTypeConversion1,
      loctmp_home_cmd, locvar_Add2_ai, locvar_Divide3_p0a,
      ANN_EKF_NMPC_2_U.WaypointsIN.fp, ANN_EKF_NMPC_2_U.WaypointsIN.rp,
      ANN_EKF_NMPC_2_U.WaypointsIN.h, ANN_EKF_NMPC_2_U.WaypointsIN.n,
      ANN_EKF_NMPC_2_U.WaypointsIN.e, ANN_EKF_NMPC_2_U.WaypointsIN.v, *(real_T (*)
      [21])&ANN_EKF_NMPC_2_U.n_op[1], *(real_T (*)[21])&ANN_EKF_NMPC_2_U.e_op[1],
      *(real_T (*)[21])&ANN_EKF_NMPC_2_U.h_op[1], *(real_T (*)[21])&
      ANN_EKF_NMPC_2_U.vn_op[1], *(real_T (*)[21])&ANN_EKF_NMPC_2_U.ve_op[1],
      *(real_T (*)[21])&ANN_EKF_NMPC_2_U.vh_op[1], loctmp_u_hor,
      loctmp_z_augm_hor, loctmp_n_hor, loctmp_e_hor, loctmp_h_hor,
      loctmp_THL_hor, loctmp_EL_hor, loctmp_AIL_hor, loctmp_RDR_hor,
      loctmp_VT_hor, loctmp_alpha_hor, loctmp_beta_hor, loctmp_phi_hor,
      loctmp_theta_hor, loctmp_psi_hor, loctmp_P_hor, loctmp_Q_hor, loctmp_R_hor,
      loctmp_wpt_index_hor, loctmp_start_wpt_hor, loctmp_pic_cic_hor,
      loctmp_home_reset_hor, loctmp_alphadot_hor, loctmp_betadot_hor,
      loctmp_ro_hor, loctmp_xw11_hor, loctmp_xw12_hor, loctmp_xw13_hor,
      loctmp_xw14_hor, loctmp_xw21_hor, loctmp_xw22_hor, loctmp_xw23_hor,
      loctmp_xw24_hor, loctmp_xw31_hor, loctmp_xw32_hor, loctmp_xw33_hor,
      loctmp_xw34_hor, ANN_EKF_NMPC_2_P.W11d, ANN_EKF_NMPC_2_P.W12d,
      ANN_EKF_NMPC_2_P.W13d, ANN_EKF_NMPC_2_P.W14d, ANN_EKF_NMPC_2_P.W21d,
      ANN_EKF_NMPC_2_P.W22d, ANN_EKF_NMPC_2_P.W23d, ANN_EKF_NMPC_2_P.W24d,
      ANN_EKF_NMPC_2_P.W31d, ANN_EKF_NMPC_2_P.W32d, ANN_EKF_NMPC_2_P.W33d,
      ANN_EKF_NMPC_2_P.W34d, locvar_Divide3_at, locvar_Divide4_h3,
      locvar_MathFunction_hi4, loctmp_b_b, locvar_MathFunction1_ed,
      locvar_Add1_co, locvar_Add_cn, locvar_Divide3_mnp, locvar_Divide4_jr4,
      locvar_Divide4_ipd, locvar_Divide5_ol, locvar_Divide3_io,
      locvar_Divide4_fy, locvar_MathFunction_iy, locvar_MathFunction1_cr,
      locvar_Add1_k4, locvar_Add_mx3, locvar_Divide_dc, locvar_Add1_e0,
      locvar_Add_df5, locvar_Divide3_npq, locvar_Divide4_lhf, locvar_Divide5_pq,
      locvar_Divide3_jze, locvar_Divide4_ncd, locvar_MathFunction_pp,
      locvar_MathFunction1_jr, locvar_Add1_ef, locvar_Add_ccv, locvar_Divide_prh,
      locvar_Add1_es, locvar_Add_ifv, locvar_Add1_lq2, locvar_Divide4_ko,
      locvar_Divide3_b10, locvar_Divide4_nh, locvar_Add1_cn2, locvar_Divide4_m3,
      locvar_Divide5_ni, locvar_Divide3_hfk, locvar_Divide4_ng,
      locvar_MathFunction_e, locvar_MathFunction1_bt, locvar_Add1_cl,
      locvar_Add_mtb, locvar_Divide_em, locvar_Add1_j2, locvar_Add_oq1,
      locvar_Divide3_bc, locvar_Divide4_mgn, locvar_Add_nwv, locvar_Divide4_kga,
      locvar_Add2_ga, locvar_Divide_ad, locvar_Divide_j0, locvar_Add_b1,
      locvar_Add1_md, locvar_Divide_je, locvar_Add1_ir, locvar_Divide4_ky,
      locvar_Add_eqw, locvar_Add2_ap, locvar_Add2_fi, locvar_Altitude,
      locvar_Latitude, locvar_Longitude, loctmp_b_KiLon, loctmp_b_KpLon,
      loctmp_b_L, loctmp_b_dist2b, locvar_Delay100dt,
      ANN_EKF_NMPC_2_B.a_ann_X_ic, ANN_EKF_NMPC_2_B.b_ann_X_ic,
      locvar_Divide4_i0, ANN_EKF_NMPC_2_B.w_ann_X_ic,
      ANN_EKF_NMPC_2_B.a_ann_Y_ic, ANN_EKF_NMPC_2_B.b_ann_Y_ic,
      locvar_Divide5_dki, ANN_EKF_NMPC_2_B.w_ann_Y_ic,
      ANN_EKF_NMPC_2_B.a_ann_Z_ic, ANN_EKF_NMPC_2_B.b_ann_Z_ic,
      locvar_Divide3_poh, ANN_EKF_NMPC_2_B.w_ann_Z_ic, ANN_EKF_NMPC_2_P.X_minXin,
      ANN_EKF_NMPC_2_P.X_maxXin, locvar_Divide4_hl4, locvar_MathFunction_ld,
      locvar_MathFunction1_j, locvar_Add1_ot, locvar_Add_jbj, locvar_Divide_b,
      ANN_EKF_NMPC_2_P.Y_minXin, ANN_EKF_NMPC_2_P.Y_maxXin, locvar_Add1_i0,
      locvar_Add_oj, locvar_Divide4_hvl, locvar_Divide4_dh, locvar_Divide3_ef,
      locvar_Divide4_j0a, ANN_EKF_NMPC_2_P.Z_minXin, ANN_EKF_NMPC_2_P.Z_maxXin,
      locvar_Divide_jg, locvar_Add1_dy, locvar_Add_nl, locvar_Add_ow,
      locvar_Divide4_m3z, locvar_Divide5_nv, locvar_DataStoreRead2_p,
      &locvar_MathFunction1_id);

    /* Gain: '<S15>/Gain2' incorporates:
     *  BusCreator: '<S53>/Bus Creator'
     *  Gain: '<S15>/Gain1'
     */
    /* '<S12>:1:261' */
    /* '<S12>:1:262' */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%calculation of control signal%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    locvar_V_height = ANN_EKF_NMPC_2_P.Gain1_Gain_k * locvar_V_down *
      ANN_EKF_NMPC_2_P.Gain2_Gain_f;

    /* Gain: '<S15>/Gain3' incorporates:
     *  BusCreator: '<S53>/Bus Creator'
     */
    locvar_V_north_c = ANN_EKF_NMPC_2_P.Gain3_Gain_l * locvar_V_north;

    /* Gain: '<S15>/Gain4' incorporates:
     *  BusCreator: '<S53>/Bus Creator'
     */
    locvar_V_east_b = ANN_EKF_NMPC_2_P.Gain4_Gain * locvar_V_east;

    /* Sum: '<S28>/Add4' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Divide4_ik = loctmp_wpts_h[loctmp_next_wpt_index - 1] - loctmp_tmp_7;

    /* Sum: '<S28>/Add9' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Gain_ar = loctmp_wpts_n[loctmp_next_wpt_index - 1] - loctmp_tmp_0;

    /* Math: '<S28>/Math Function4' */
    locvar_Divide5_ny = locvar_Gain_ar * locvar_Gain_ar;

    /* Sum: '<S28>/Add5' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Add_kq = loctmp_wpts_e[loctmp_next_wpt_index - 1] - loctmp_tmp;

    /* Math: '<S28>/Math Function5' */
    locvar_Divide3_ai5 = locvar_Add_kq * locvar_Add_kq;

    /* Sum: '<S28>/Add6' incorporates:
     *  Math: '<S28>/Math Function7'
     */
    locvar_MathFunction_bv = (locvar_Divide4_ik * locvar_Divide4_ik +
      locvar_Divide5_ny) + locvar_Divide3_ai5;

    /* Sqrt: '<S28>/Math Function9'
     *
     * About '<S28>/Math Function9':
     *  Operator: signedSqrt
     */
    if (locvar_MathFunction_bv < 0.0) {
      locvar_MathFunction_bv = -sqrt(fabs(locvar_MathFunction_bv));
    } else {
      locvar_MathFunction_bv = sqrt(locvar_MathFunction_bv);
    }

    /* End of Sqrt: '<S28>/Math Function9' */

    /* Product: '<S28>/Product6' */
    locvar_Delay100dt = locvar_Divide4_ik / locvar_MathFunction_bv;

    /* Trigonometry: '<S28>/Trigonometric Function5' */
    if (locvar_Delay100dt > 1.0) {
      locvar_Delay100dt = 1.0;
    } else {
      if (locvar_Delay100dt < -1.0) {
        locvar_Delay100dt = -1.0;
      }
    }

    locvar_MathFunction_bv = asin(locvar_Delay100dt);

    /* End of Trigonometry: '<S28>/Trigonometric Function5' */

    /* Trigonometry: '<S28>/Trigonometric Function1' */
    locvar_Divide4_ik = cos(locvar_MathFunction_bv);

    /* Sum: '<S28>/Add8' */
    locvar_Divide5_ny += locvar_Divide3_ai5;

    /* Sqrt: '<S28>/Math Function6'
     *
     * About '<S28>/Math Function6':
     *  Operator: signedSqrt
     */
    if (locvar_Divide5_ny < 0.0) {
      locvar_Divide5_ny = -sqrt(fabs(locvar_Divide5_ny));
    } else {
      locvar_Divide5_ny = sqrt(locvar_Divide5_ny);
    }

    /* End of Sqrt: '<S28>/Math Function6' */

    /* Product: '<S28>/Product2' */
    locvar_Delay100dt = locvar_Gain_ar / locvar_Divide5_ny;

    /* SignalConversion: '<S30>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  MATLAB Function: '<S29>/Embedded MATLAB Function'
     */
    locvar_start_wpt_mem[1] = locvar_Gain_ar;

    /* MATLAB Function: '<S29>/Embedded MATLAB Function' incorporates:
     *  SignalConversion: '<S30>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'NMPC (subsystem)/Guidance System/Coordinates transformation e-n-h to e-n-h_track/angles of rotation/Angle Correction/Embedded MATLAB Function': '<S30>:1' */
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    /* '<S30>:1:4' */
    loctmp_i_0 = 1;

    /* '<S30>:1:5' */
    locvar_Gain_ar = 0.0;
    if (!((locvar_start_wpt_mem[1] > 0.0) && (locvar_Add_kq > 0.0))) {
      if ((locvar_start_wpt_mem[1] > 0.0) && (locvar_Add_kq < 0.0)) {
        /* '<S30>:1:10' */
        /* '<S30>:1:11' */
        locvar_Gain_ar = 3.1415926535897931;

        /* '<S30>:1:12' */
        loctmp_i_0 = -1;
      } else {
        if ((locvar_start_wpt_mem[1] < 0.0) && (locvar_Add_kq < 0.0)) {
          /* '<S30>:1:13' */
          /* '<S30>:1:14' */
          locvar_Gain_ar = -3.1415926535897931;

          /* '<S30>:1:15' */
          loctmp_i_0 = -1;
        }
      }
    } else {
      /* '<S30>:1:7' */
      /* '<S30>:1:8' */
      /* '<S30>:1:9' */
    }

    /* Trigonometry: '<S28>/Trigonometric Function4' */
    /* '<S30>:1:20' */
    if (locvar_Delay100dt > 1.0) {
      locvar_Delay100dt = 1.0;
    } else {
      if (locvar_Delay100dt < -1.0) {
        locvar_Delay100dt = -1.0;
      }
    }

    /* MATLAB Function: '<S29>/Embedded MATLAB Function' incorporates:
     *  Trigonometry: '<S28>/Trigonometric Function4'
     */
    locvar_Gain_ar += asin(locvar_Delay100dt) * (real_T)loctmp_i_0;

    /* Trigonometry: '<S28>/Trigonometric Function3' */
    locvar_Divide3_ai5 = cos(locvar_Gain_ar);

    /* Trigonometry: '<S28>/Trigonometric Function2' */
    locvar_Divide5_ny = sin(locvar_Gain_ar);

    /* Trigonometry: '<S28>/Trigonometric Function' */
    locvar_MathFunction_bv = sin(locvar_MathFunction_bv);

    /* Sum: '<S22>/Add' incorporates:
     *  Product: '<S22>/Product'
     *  Product: '<S22>/Product1'
     *  Product: '<S22>/Product4'
     *  Product: '<S22>/Product5'
     *  Product: '<S22>/Product6'
     */
    locvar_edot_track = (locvar_Divide4_ik * locvar_Divide3_ai5 *
                         locvar_V_east_b + locvar_V_north_c * locvar_Divide5_ny)
      + locvar_MathFunction_bv * locvar_Divide3_ai5 * locvar_V_height;

    /* Sum: '<S22>/Add1' incorporates:
     *  Product: '<S22>/Product2'
     *  Product: '<S22>/Product3'
     *  Product: '<S22>/Product7'
     *  Product: '<S22>/Product8'
     *  Product: '<S22>/Product9'
     */
    locvar_ndot_track = (locvar_V_north_c * locvar_Divide3_ai5 -
                         locvar_Divide4_ik * locvar_Divide5_ny * locvar_V_east_b)
      - locvar_MathFunction_bv * locvar_Divide5_ny * locvar_V_height;

    /* Sum: '<S22>/Add2' incorporates:
     *  Constant: '<S22>/Constant'
     *  Product: '<S22>/Product10'
     *  Product: '<S22>/Product11'
     */
    locvar_hdot_track = (ANN_EKF_NMPC_2_P.Constant_Value - locvar_V_east_b *
                         locvar_MathFunction_bv) + locvar_V_height *
      locvar_Divide4_ik;

    /* Fcn: '<S40>/hd' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Add_ev = ((((((((((((((((((loctmp_wpts_e[loctmp_next_wpt_index - 1] *
      locvar_East_k * loctmp_wpts_h[loctmp_next_wpt_index - 1] -
      loctmp_wpts_e[loctmp_next_wpt_index - 1] * locvar_East_k * loctmp_tmp_7) +
      rt_powd_snf(loctmp_wpts_e[loctmp_next_wpt_index - 1], 2.0) * loctmp_tmp_7)
      - loctmp_wpts_e[loctmp_next_wpt_index - 1] * loctmp_tmp *
      loctmp_wpts_h[loctmp_next_wpt_index - 1]) - loctmp_tmp * locvar_East_k *
      loctmp_wpts_h[loctmp_next_wpt_index - 1]) + loctmp_tmp * locvar_East_k *
      loctmp_tmp_7) - loctmp_tmp * loctmp_tmp_7 *
      loctmp_wpts_e[loctmp_next_wpt_index - 1]) +
      loctmp_wpts_h[loctmp_next_wpt_index - 1] * rt_powd_snf(loctmp_tmp, 2.0)) +
      loctmp_wpts_n[loctmp_next_wpt_index - 1] * locvar_North_e *
      loctmp_wpts_h[loctmp_next_wpt_index - 1]) -
      loctmp_wpts_n[loctmp_next_wpt_index - 1] * locvar_North_e * loctmp_tmp_7)
      + rt_powd_snf(loctmp_wpts_n[loctmp_next_wpt_index - 1], 2.0) *
      loctmp_tmp_7) - loctmp_wpts_n[loctmp_next_wpt_index - 1] * loctmp_tmp_0 *
      loctmp_wpts_h[loctmp_next_wpt_index - 1]) - loctmp_tmp_0 * locvar_North_e *
      loctmp_wpts_h[loctmp_next_wpt_index - 1]) + loctmp_tmp_0 * locvar_North_e *
                          loctmp_tmp_7) - loctmp_tmp_0 * loctmp_tmp_7 *
                         loctmp_wpts_n[loctmp_next_wpt_index - 1]) +
                        loctmp_wpts_h[loctmp_next_wpt_index - 1] * rt_powd_snf
                        (loctmp_tmp_0, 2.0)) + rt_powd_snf
                       (loctmp_wpts_h[loctmp_next_wpt_index - 1], 2.0) *
                       locvar_Height_k) - 2.0 * locvar_Height_k *
                      loctmp_wpts_h[loctmp_next_wpt_index - 1] * loctmp_tmp_7) +
                     locvar_Height_k * rt_powd_snf(loctmp_tmp_7, 2.0)) /
      ((((((((rt_powd_snf(loctmp_wpts_e[loctmp_next_wpt_index - 1], 2.0) -
              loctmp_wpts_e[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp) +
             rt_powd_snf(loctmp_tmp, 2.0)) + rt_powd_snf
            (loctmp_wpts_n[loctmp_next_wpt_index - 1], 2.0)) -
           loctmp_wpts_n[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp_0) +
          rt_powd_snf(loctmp_tmp_0, 2.0)) + rt_powd_snf
         (loctmp_wpts_h[loctmp_next_wpt_index - 1], 2.0)) -
        loctmp_wpts_h[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp_7) +
       rt_powd_snf(loctmp_tmp_7, 2.0));

    /* Sum: '<S41>/Subtract2' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Subtract2_e = loctmp_wpts_h[loctmp_next_wpt_index - 1] -
      locvar_Add_ev;

    /* Fcn: '<S40>/nd' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Divide4_oem = ((((((((((((((((((loctmp_wpts_e[loctmp_next_wpt_index -
      1] * locvar_East_k * loctmp_wpts_n[loctmp_next_wpt_index - 1] -
      loctmp_wpts_e[loctmp_next_wpt_index - 1] * locvar_East_k * loctmp_tmp_0) +
      rt_powd_snf(loctmp_wpts_e[loctmp_next_wpt_index - 1], 2.0) * loctmp_tmp_0)
      - loctmp_wpts_e[loctmp_next_wpt_index - 1] * loctmp_tmp *
      loctmp_wpts_n[loctmp_next_wpt_index - 1]) - loctmp_tmp * locvar_East_k *
      loctmp_wpts_n[loctmp_next_wpt_index - 1]) + loctmp_tmp * locvar_East_k *
      loctmp_tmp_0) - loctmp_tmp * loctmp_tmp_0 *
      loctmp_wpts_e[loctmp_next_wpt_index - 1]) +
      loctmp_wpts_n[loctmp_next_wpt_index - 1] * rt_powd_snf(loctmp_tmp, 2.0)) +
      rt_powd_snf(loctmp_wpts_n[loctmp_next_wpt_index - 1], 2.0) *
      locvar_North_e) - 2.0 * locvar_North_e *
      loctmp_wpts_n[loctmp_next_wpt_index - 1] * loctmp_tmp_0) + locvar_North_e *
      rt_powd_snf(loctmp_tmp_0, 2.0)) + loctmp_wpts_h[loctmp_next_wpt_index - 1]
      * locvar_Height_k * loctmp_wpts_n[loctmp_next_wpt_index - 1]) -
      loctmp_wpts_h[loctmp_next_wpt_index - 1] * locvar_Height_k * loctmp_tmp_0)
      + rt_powd_snf(loctmp_wpts_h[loctmp_next_wpt_index - 1], 2.0) *
      loctmp_tmp_0) - loctmp_wpts_h[loctmp_next_wpt_index - 1] * loctmp_tmp_7 *
      loctmp_wpts_n[loctmp_next_wpt_index - 1]) - loctmp_tmp_7 * locvar_Height_k
      * loctmp_wpts_n[loctmp_next_wpt_index - 1]) + loctmp_tmp_7 *
      locvar_Height_k * loctmp_tmp_0) - loctmp_tmp_7 * loctmp_tmp_0 *
      loctmp_wpts_h[loctmp_next_wpt_index - 1]) +
                          loctmp_wpts_n[loctmp_next_wpt_index - 1] * rt_powd_snf
                          (loctmp_tmp_7, 2.0)) / ((((((((rt_powd_snf
      (loctmp_wpts_e[loctmp_next_wpt_index - 1], 2.0) -
      loctmp_wpts_e[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp) + rt_powd_snf
      (loctmp_tmp, 2.0)) + rt_powd_snf(loctmp_wpts_n[loctmp_next_wpt_index - 1],
      2.0)) - loctmp_wpts_n[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp_0) +
      rt_powd_snf(loctmp_tmp_0, 2.0)) + rt_powd_snf
      (loctmp_wpts_h[loctmp_next_wpt_index - 1], 2.0)) -
      loctmp_wpts_h[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp_7) +
      rt_powd_snf(loctmp_tmp_7, 2.0));

    /* Sum: '<S41>/Subtract4' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Subtract4 = loctmp_wpts_n[loctmp_next_wpt_index - 1] -
      locvar_Divide4_oem;

    /* Fcn: '<S40>/ed' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Add1_ob = ((((((((((((((((((rt_powd_snf
      (loctmp_wpts_e[loctmp_next_wpt_index - 1], 2.0) * locvar_East_k - 2.0 *
      locvar_East_k * loctmp_wpts_e[loctmp_next_wpt_index - 1] * loctmp_tmp) +
      locvar_East_k * rt_powd_snf(loctmp_tmp, 2.0)) +
      loctmp_wpts_n[loctmp_next_wpt_index - 1] * locvar_North_e *
      loctmp_wpts_e[loctmp_next_wpt_index - 1]) -
      loctmp_wpts_n[loctmp_next_wpt_index - 1] * locvar_North_e * loctmp_tmp) +
      rt_powd_snf(loctmp_wpts_n[loctmp_next_wpt_index - 1], 2.0) * loctmp_tmp) -
      loctmp_wpts_n[loctmp_next_wpt_index - 1] * loctmp_tmp_0 *
      loctmp_wpts_e[loctmp_next_wpt_index - 1]) - loctmp_tmp_0 * locvar_North_e *
      loctmp_wpts_e[loctmp_next_wpt_index - 1]) + loctmp_tmp_0 * locvar_North_e *
      loctmp_tmp) - loctmp_tmp_0 * loctmp_tmp *
      loctmp_wpts_n[loctmp_next_wpt_index - 1]) +
      loctmp_wpts_e[loctmp_next_wpt_index - 1] * rt_powd_snf(loctmp_tmp_0, 2.0))
      + loctmp_wpts_h[loctmp_next_wpt_index - 1] * locvar_Height_k *
      loctmp_wpts_e[loctmp_next_wpt_index - 1]) -
      loctmp_wpts_h[loctmp_next_wpt_index - 1] * locvar_Height_k * loctmp_tmp) +
      rt_powd_snf(loctmp_wpts_h[loctmp_next_wpt_index - 1], 2.0) * loctmp_tmp) -
                          loctmp_wpts_h[loctmp_next_wpt_index - 1] *
                          loctmp_tmp_7 * loctmp_wpts_e[loctmp_next_wpt_index - 1])
                         - loctmp_tmp_7 * locvar_Height_k *
                         loctmp_wpts_e[loctmp_next_wpt_index - 1]) +
                        loctmp_tmp_7 * locvar_Height_k * loctmp_tmp) -
                       loctmp_tmp_7 * loctmp_tmp *
                       loctmp_wpts_h[loctmp_next_wpt_index - 1]) +
                      loctmp_wpts_e[loctmp_next_wpt_index - 1] * rt_powd_snf
                      (loctmp_tmp_7, 2.0)) / ((((((((rt_powd_snf
      (loctmp_wpts_e[loctmp_next_wpt_index - 1], 2.0) -
      loctmp_wpts_e[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp) + rt_powd_snf
      (loctmp_tmp, 2.0)) + rt_powd_snf(loctmp_wpts_n[loctmp_next_wpt_index - 1],
      2.0)) - loctmp_wpts_n[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp_0) +
      rt_powd_snf(loctmp_tmp_0, 2.0)) + rt_powd_snf
      (loctmp_wpts_h[loctmp_next_wpt_index - 1], 2.0)) -
      loctmp_wpts_h[loctmp_next_wpt_index - 1] * 2.0 * loctmp_tmp_7) +
      rt_powd_snf(loctmp_tmp_7, 2.0));

    /* Sum: '<S41>/Subtract5' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    locvar_Subtract5 = loctmp_wpts_e[loctmp_next_wpt_index - 1] - locvar_Add1_ob;

    /* Outputs for Atomic SubSystem: '<S41>/Subsystem1' */
    ANN_EKF_NMPC_2_Subsystem1_p(locvar_Subtract2_e, locvar_Subtract4,
      locvar_Subtract5, &ANN_EKF_NMPC_2_B.Subsystem1);

    /* End of Outputs for SubSystem: '<S41>/Subsystem1' */

    /* Product: '<S41>/Product' incorporates:
     *  Constant: '<S41>/dist d to r'
     */
    locvar_Divide_aa = ANN_EKF_NMPC_2_P.L / ANN_EKF_NMPC_2_B.Subsystem1.Sqrt;

    /* Sum: '<S22>/Add6' incorporates:
     *  Product: '<S41>/Product3'
     *  Sum: '<S41>/Subtract1'
     */
    locvar_er_e = (locvar_Divide_aa * locvar_Subtract5 + locvar_Add1_ob) -
      locvar_East_k;

    /* Sum: '<S22>/Add7' incorporates:
     *  Product: '<S41>/Product2'
     *  Sum: '<S41>/Subtract6'
     */
    locvar_nr_n = (locvar_Divide_aa * locvar_Subtract4 + locvar_Divide4_oem) -
      locvar_North_e;

    /* Sum: '<S22>/Add8' incorporates:
     *  Product: '<S41>/Product1'
     *  Sum: '<S41>/Subtract7'
     */
    locvar_hr_h = (locvar_Divide_aa * locvar_Subtract2_e + locvar_Add_ev) -
      locvar_Height_k;

    /* Sum: '<S22>/Add3' incorporates:
     *  Product: '<S22>/Product12'
     *  Product: '<S22>/Product13'
     *  Product: '<S22>/Product18'
     *  Product: '<S22>/Product19'
     *  Product: '<S22>/Product20'
     */
    locvar_er_e_track = (locvar_Divide4_ik * locvar_Divide3_ai5 * locvar_er_e +
                         locvar_nr_n * locvar_Divide5_ny) +
      locvar_MathFunction_bv * locvar_Divide3_ai5 * locvar_hr_h;

    /* Sum: '<S22>/Add4' incorporates:
     *  Product: '<S22>/Product16'
     *  Product: '<S22>/Product17'
     *  Product: '<S22>/Product21'
     *  Product: '<S22>/Product22'
     *  Product: '<S22>/Product23'
     */
    locvar_nr_n_track = (locvar_nr_n * locvar_Divide3_ai5 - locvar_Divide4_ik *
                         locvar_Divide5_ny * locvar_er_e) -
      locvar_MathFunction_bv * locvar_Divide5_ny * locvar_hr_h;

    /* Sum: '<S22>/Add5' incorporates:
     *  Constant: '<S22>/Constant1'
     *  Product: '<S22>/Product14'
     *  Product: '<S22>/Product15'
     */
    locvar_hr_h_track = (ANN_EKF_NMPC_2_P.Constant1_Value - locvar_er_e *
                         locvar_MathFunction_bv) + locvar_hr_h *
      locvar_Divide4_ik;

    /* Sum: '<S23>/Add2' incorporates:
     *  Trigonometry: '<S23>/Trigonometric Function'
     *  Trigonometry: '<S23>/Trigonometric Function1'
     */
    locvar_Gain_ar = rt_atan2d_snf(locvar_ndot_track, locvar_edot_track) -
      rt_atan2d_snf(locvar_nr_n_track, locvar_er_e_track);

    /* Logic: '<S23>/Logical Operator' */
    locvar_LogicalOperator_h = !(locvar_DataTypeConversion1 != 0);

    /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
    if (locvar_LogicalOperator_h ||
        (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState_a != 0)) {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k =
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_IC;
    }

    if (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k >=
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_UpperSat_o) {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k =
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_UpperSat_o;
    } else {
      if (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k <=
          ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_LowerSat_p) {
        ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k =
          ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_LowerSat_p;
      }
    }

    ANN_EKF_NMPC_2_B.DiscreteTimeIntegrator_h =
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k;

    /* End of DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S23>/Embedded MATLAB Function' */
    /* MATLAB Function 'NMPC (subsystem)/Guidance System/Phi command/Embedded MATLAB Function': '<S31>:1' */
    /* '<S31>:1:3' */
    locvar_Divide3_oc = locvar_Gain_ar;
    if (locvar_Gain_ar > 3.1415926535897931) {
      /* '<S31>:1:5' */
      /* '<S31>:1:6' */
      locvar_Divide3_oc = locvar_Gain_ar - 6.2831853071795862;
    }

    if (locvar_Gain_ar < -3.1415926535897931) {
      /* '<S31>:1:9' */
      /* '<S31>:1:10' */
      locvar_Divide3_oc = locvar_Gain_ar + 6.2831853071795862;
    }

    /* End of MATLAB Function: '<S23>/Embedded MATLAB Function' */

    /* Outputs for Atomic SubSystem: '<S23>/Subsystem4' */
    ANN_EKF_NMPC_2_Subsystem4(locvar_edot_track, locvar_ndot_track,
      &ANN_EKF_NMPC_2_B.Subsystem4);

    /* End of Outputs for SubSystem: '<S23>/Subsystem4' */

    /* Gain: '<S23>/Gain' */
    locvar_Add_kq = ANN_EKF_NMPC_2_P.Gain_Gain_n *
      ANN_EKF_NMPC_2_B.Subsystem4.SumofElements;

    /* Product: '<S23>/Product4' */
    locvar_Divide_aa = locvar_Divide3_oc * (real_T)locvar_DataTypeConversion1;

    /* Gain: '<S23>/Gain1' */
    locvar_Add_pii = ANN_EKF_NMPC_2_P.KiLat * locvar_Divide_aa;

    /* Sum: '<S23>/Sum' incorporates:
     *  Gain: '<S23>/Gain2'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.KpLat * locvar_Divide_aa +
      ANN_EKF_NMPC_2_B.DiscreteTimeIntegrator_h;

    /* Outputs for Atomic SubSystem: '<S23>/Subsystem1' */
    ANN_EKF_NMPC_2_Subsystem1(locvar_er_e_track, locvar_nr_n_track,
      &ANN_EKF_NMPC_2_B.Subsystem1_m);

    /* End of Outputs for SubSystem: '<S23>/Subsystem1' */

    /* Trigonometry: '<S23>/Trigonometric Function3' incorporates:
     *  Product: '<S23>/Product'
     */
    locvar_Divide_aa = rt_atan2d_snf(locvar_Add_kq * locvar_Gain_ar,
      ANN_EKF_NMPC_2_B.Subsystem1_m.Sqrt);

    /* Outputs for Atomic SubSystem: '<S24>/Subsystem3' */
    ANN_EKF_NMPC_2_Subsystem1(locvar_V_north_c, locvar_V_east_b,
      &ANN_EKF_NMPC_2_B.Subsystem3);

    /* End of Outputs for SubSystem: '<S24>/Subsystem3' */

    /* Trigonometry: '<S24>/Trigonometric Function' */
    locvar_Gain_ar = rt_atan2d_snf(locvar_V_height,
      ANN_EKF_NMPC_2_B.Subsystem3.Sqrt);

    /* Outputs for Atomic SubSystem: '<S24>/Subsystem2' */
    ANN_EKF_NMPC_2_Subsystem1(locvar_nr_n, locvar_er_e,
      &ANN_EKF_NMPC_2_B.Subsystem2);

    /* End of Outputs for SubSystem: '<S24>/Subsystem2' */

    /* Sum: '<S24>/Add2' incorporates:
     *  Trigonometry: '<S24>/Trigonometric Function3'
     */
    locvar_Add1_o3 = rt_atan2d_snf(locvar_hr_h, ANN_EKF_NMPC_2_B.Subsystem2.Sqrt)
      - locvar_Gain_ar;

    /* Outputs for Atomic SubSystem: '<S24>/Subsystem4' */
    ANN_EKF_NMPC_2_Subsystem4_k(locvar_V_height, locvar_V_north_c,
      locvar_V_east_b, &ANN_EKF_NMPC_2_B.Subsystem4_k);

    /* End of Outputs for SubSystem: '<S24>/Subsystem4' */

    /* Gain: '<S24>/Gain' */
    locvar_Add_kq = ANN_EKF_NMPC_2_P.Gain_Gain_m *
      ANN_EKF_NMPC_2_B.Subsystem4_k.SumofElements;

    /* Trigonometry: '<S24>/Trigonometric Function1' incorporates:
     *  Product: '<S24>/Product4'
     */
    locvar_MathFunction1_e4 = atan(locvar_Add1_o3 * (real_T)
      locvar_DataTypeConversion1);

    /* Gain: '<S24>/Gain1' */
    locvar_Add_au = ANN_EKF_NMPC_2_P.KiLon * locvar_MathFunction1_e4;

    /* Sum: '<S24>/Sum' incorporates:
     *  Gain: '<S24>/Gain2'
     */
    locvar_Gain_ar = ANN_EKF_NMPC_2_P.KpLon * locvar_MathFunction1_e4 +
      ANN_EKF_NMPC_2_B.DiscreteTimeIntegrator;

    /* Outputs for Atomic SubSystem: '<S24>/Subsystem1' */
    ANN_EKF_NMPC_2_Subsystem1_p(locvar_er_e, locvar_nr_n, locvar_hr_h,
      &ANN_EKF_NMPC_2_B.Subsystem1_p);

    /* End of Outputs for SubSystem: '<S24>/Subsystem1' */

    /* Trigonometry: '<S24>/Trigonometric Function2' incorporates:
     *  Product: '<S24>/Product2'
     */
    locvar_MathFunction1_e4 = rt_atan2d_snf(locvar_Add_kq * locvar_Gain_ar,
      ANN_EKF_NMPC_2_B.Subsystem1_p.Sqrt);

    /* MATLAB Function: '<S26>/Modification of VT' incorporates:
     *  Inport: '<Root>/e_op'
     *  Inport: '<Root>/h_op'
     *  Inport: '<Root>/n_op'
     *  Inport: '<Root>/ve_op'
     *  Inport: '<Root>/vh_op'
     *  Inport: '<Root>/vn_op'
     *  MATLAB Function: '<S19>/Trajectory Generation'
     */
    /* MATLAB Function 'NMPC (subsystem)/Guidance System/VT modification_moving points/Modification of VT': '<S39>:1' */
    /* OP trajectory generation (copied from uas_augm)model.m) */
    /* reassigning Vab (based on the new d point) */
    /* '<S39>:1:11' */
    if (ANN_EKF_NMPC_2_P.TR == 2.0) {
      /* '<S39>:1:12' */
      /* '<S39>:1:13' */
      /* '<S39>:1:14' */
      locvar_Divide4_afp = loctmp_wpts_n[loctmp_next_wpt_index - 1] -
        ANN_EKF_NMPC_2_U.n_op[0];
      locvar_MathFunction_di = loctmp_wpts_e[loctmp_next_wpt_index - 1] -
        ANN_EKF_NMPC_2_U.e_op[0];
      locvar_Gain_ar = loctmp_wpts_h[loctmp_next_wpt_index - 1] -
        ANN_EKF_NMPC_2_U.h_op[0];

      /* '<S39>:1:15' */
      locvar_Add_kq = loctmp_wpts_n[loctmp_next_wpt_index - 1] -
        locvar_Divide4_oem;
      locvar_Add2_db = loctmp_wpts_e[loctmp_next_wpt_index - 1] - locvar_Add1_ob;
      locvar_Divide4_c1v = loctmp_wpts_h[loctmp_next_wpt_index - 1] -
        locvar_Add_ev;

      /* '<S39>:1:16' */
      locvar_Divide4_ch = locvar_Divide4_oem - ANN_EKF_NMPC_2_U.n_op[0];
      locvar_Divide5_kh = locvar_Add1_ob - ANN_EKF_NMPC_2_U.e_op[0];
      locvar_Divide3_j0 = locvar_Add_ev - ANN_EKF_NMPC_2_U.h_op[0];

      /* '<S39>:1:17' */
      locvar_Delay100dt = sqrt((locvar_Divide4_afp * locvar_Divide4_afp +
        locvar_MathFunction_di * locvar_MathFunction_di) + locvar_Gain_ar *
        locvar_Gain_ar) - sqrt((locvar_Add_kq * locvar_Add_kq + locvar_Add2_db *
        locvar_Add2_db) + locvar_Divide4_c1v * locvar_Divide4_c1v);
      if (locvar_Delay100dt < 0.0) {
        locvar_Delay100dt = -1.0;
      } else if (locvar_Delay100dt > 0.0) {
        locvar_Delay100dt = 1.0;
      } else {
        if (locvar_Delay100dt == 0.0) {
          locvar_Delay100dt = 0.0;
        }
      }

      locvar_Vab_mod = sqrt((ANN_EKF_NMPC_2_U.vn_op[0] * ANN_EKF_NMPC_2_U.vn_op
        [0] + ANN_EKF_NMPC_2_U.ve_op[0] * ANN_EKF_NMPC_2_U.ve_op[0]) +
                            ANN_EKF_NMPC_2_U.vh_op[0] * ANN_EKF_NMPC_2_U.vh_op[0])
        - atan(sqrt((locvar_Divide4_ch * locvar_Divide4_ch + locvar_Divide5_kh *
                     locvar_Divide5_kh) + locvar_Divide3_j0 * locvar_Divide3_j0)
               * locvar_Delay100dt / 100.0) * 0.063661977236758135;

      /* (168.78) (5) (/100) */
    }

    /* End of MATLAB Function: '<S26>/Modification of VT' */

    /* Product: '<S25>/Product6' */
    locvar_Divide4_ik *= locvar_Vab_mod;

    /* Sum: '<S25>/Add1' incorporates:
     *  BusCreator: '<S145>/Bus Creator1'
     *  Gain: '<S25>/Gain2'
     *  Product: '<S139>/Divide1'
     *  Product: '<S139>/Divide2'
     *  Product: '<S139>/Divide3'
     *  Product: '<S139>/Divide4'
     *  Product: '<S139>/Divide5'
     *  Product: '<S139>/Divide6'
     *  Product: '<S139>/Divide7'
     *  Product: '<S25>/Product3'
     *  Product: '<S25>/Product5'
     *  Reshape: '<S50>/Reshape3'
     *  Sum: '<S139>/Add1'
     *  Sum: '<S139>/Add2'
     *  Sum: '<S139>/Add3'
     *  Sum: '<S54>/Add1'
     *  Trigonometry: '<S139>/Trigonometric Function1'
     */
    locvar_Add1_c0 = ((((locvar_TrigonometricFunction2_ly *
                         locvar_TrigonometricFunction_m2 *
                         locvar_TrigonometricFunction3_p +
                         locvar_TrigonometricFunction5_h0 *
                         locvar_TrigonometricFunction4_ef) * locvar_Divide2_op +
                        locvar_Divide2_em * cos(locvar_Reshape1[8]) *
                        locvar_TrigonometricFunction3_p) +
                       (locvar_TrigonometricFunction2_ly *
                        locvar_TrigonometricFunction5_h0 *
                        locvar_TrigonometricFunction3_p -
                        locvar_TrigonometricFunction_m2 *
                        locvar_TrigonometricFunction4_ef) * locvar_Divide2_ic) -
                      locvar_Divide1_ip[4]) * ANN_EKF_NMPC_2_P.Gain2_Gain_d *
      (real_T)locvar_DataTypeConversion1 + locvar_Divide4_ik *
      locvar_Divide3_ai5;

    /* Sum: '<S25>/Add2' incorporates:
     *  Gain: '<S25>/Gain1'
     *  Product: '<S141>/Divide1'
     *  Product: '<S141>/Divide7'
     *  Product: '<S25>/Product2'
     *  Product: '<S25>/Product4'
     *  Reshape: '<S50>/Reshape3'
     *  Sum: '<S141>/Add1'
     *  Sum: '<S141>/Add2'
     *  Sum: '<S141>/Add3'
     *  Sum: '<S54>/Add3'
     */
    locvar_Add2_koh = ((((locvar_Divide2_h2o - locvar_Divide4_ii) *
                         locvar_Divide2_op + locvar_Divide3_ik) +
                        (locvar_Divide6_d5 + locvar_Divide5_cg1) *
                        locvar_Divide2_ic) - locvar_Divide1_ip[3]) *
      ANN_EKF_NMPC_2_P.Gain1_Gain_k0 * (real_T)locvar_DataTypeConversion1 +
      locvar_Divide4_ik * locvar_Divide5_ny;

    /* Sum: '<S25>/Add4' incorporates:
     *  BusCreator: '<S145>/Bus Creator1'
     *  Gain: '<S25>/Gain'
     *  Product: '<S140>/Divide1'
     *  Product: '<S140>/Divide2'
     *  Product: '<S140>/Divide3'
     *  Product: '<S25>/Product1'
     *  Product: '<S25>/Product7'
     *  Reshape: '<S50>/Reshape3'
     *  Sum: '<S140>/Add1'
     *  Sum: '<S54>/Add2'
     *  Trigonometry: '<S140>/Trigonometric Function'
     *  Trigonometry: '<S140>/Trigonometric Function1'
     *  Trigonometry: '<S140>/Trigonometric Function2'
     *  Trigonometry: '<S140>/Trigonometric Function4'
     *  Trigonometry: '<S140>/Trigonometric Function5'
     */
    locvar_Add4_dr = (((locvar_Divide2_em * sin(locvar_Reshape1[8]) - cos
                        (locvar_Reshape1[8]) * sin(locvar_Reshape1[7]) *
                        locvar_Divide2_op) - cos(locvar_Reshape1[7]) * cos
                       (locvar_Reshape1[8]) * locvar_Divide2_ic) -
                      locvar_Divide1_ip[5]) * ANN_EKF_NMPC_2_P.Gain_Gain_d *
      (real_T)locvar_DataTypeConversion1 + locvar_MathFunction_bv *
      locvar_Vab_mod;

    /* Outputs for Atomic SubSystem: '<S25>/Subsystem1' */
    ANN_EKF_NMPC_2_Subsystem1_p(locvar_Add4_dr, locvar_Add2_koh, locvar_Add1_c0,
      &ANN_EKF_NMPC_2_B.Subsystem1_mx);

    /* End of Outputs for SubSystem: '<S25>/Subsystem1' */

    /* MATLAB Function: '<S40>/Embedded MATLAB Function' incorporates:
     *  BusCreator: '<S40>/BusConversion_InsertedFor_Embedded MATLAB Function_at_inport_0'
     *  BusCreator: '<S40>/BusConversion_InsertedFor_Embedded MATLAB Function_at_inport_1'
     */
    /* MATLAB Function 'NMPC (subsystem)/Guidance System/r and d points/d distance/Embedded MATLAB Function': '<S42>:1' */
    /* '<S42>:1:4' */
    locvar_Add2_db = locvar_Add_ev - locvar_Height_k;

    /* '<S42>:1:5' */
    locvar_Add_kq = locvar_Divide4_oem - locvar_North_e;

    /* '<S42>:1:6' */
    locvar_Gain_ar = locvar_Add1_ob - locvar_East_k;

    /* '<S42>:1:8' */
    locvar_distance = (locvar_Add2_db * locvar_Add2_db + locvar_Add_kq *
                       locvar_Add_kq) + locvar_Gain_ar * locvar_Gain_ar;
    locvar_distance = sqrt(locvar_distance);

    /* Outport: '<Root>/Distance to Waypoint' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     *  SignalConversion: '<S2>/OutportBufferForDistance to Waypoint'
     */
    ANN_EKF_NMPC_2_Y.DistancetoWaypoint = (real32_T)loctmp_distance;

    /* SignalConversion: '<S2>/OutportBufferForV_nmpc' incorporates:
     *  MATLAB Function: '<S2>/Control System'
     */
    locvar_OutportBufferForV_nmpc = locvar_MathFunction1_id;

    /* Outport: '<Root>/Waypoint Index' incorporates:
     *  MATLAB Function: '<S19>/Trajectory Generation'
     *  SignalConversion: '<S2>/OutportBufferForWaypoint Index'
     */
    ANN_EKF_NMPC_2_Y.WaypointIndex = loctmp_b_index;

    /* Sum: '<S18>/Add' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     */
    locvar_MathFunction_bv = ANN_EKF_NMPC_2_B.Subsystem1_mx.Sqrt -
      locvar_Reshape1[4];

    /* Sum: '<S18>/Add1' incorporates:
     *  BusCreator: '<S145>/Bus Creator1'
     */
    locvar_Divide3_ai5 = locvar_MathFunction1_e4 - locvar_Reshape1[8];

    /* Sum: '<S18>/Add2' incorporates:
     *  BusCreator: '<S145>/Bus Creator1'
     */
    locvar_Divide5_ny = locvar_Divide_aa - locvar_Reshape1[7];

    /* Sum: '<S18>/Add3' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *  Constant: '<S21>/Beta command'
     */
    locvar_Divide4_ik = ANN_EKF_NMPC_2_P.Betacommand_Value - locvar_Reshape1[6];

    /* Sum: '<S45>/Add1' incorporates:
     *  Gain: '<S45>/Gain10'
     *  Gain: '<S45>/Gain9'
     */
    locvar_z1_k = ANN_EKF_NMPC_2_P.W11d.d * locvar_MathFunction_bv +
      ANN_EKF_NMPC_2_P.W11d.c * locvar_xw11_k;

    /* Sum: '<S45>/Add2' incorporates:
     *  Gain: '<S45>/Gain11'
     *  Gain: '<S45>/Gain12'
     */
    locvar_z2_k = ANN_EKF_NMPC_2_P.W12d.d * locvar_Divide3_ai5 +
      ANN_EKF_NMPC_2_P.W12d.c * locvar_xw12_k;

    /* Sum: '<S45>/Add3' incorporates:
     *  Gain: '<S45>/Gain13'
     *  Gain: '<S45>/Gain14'
     */
    locvar_z3_k = ANN_EKF_NMPC_2_P.W13d.d * locvar_Divide5_ny +
      ANN_EKF_NMPC_2_P.W13d.c * locvar_xw13_k;

    /* Sum: '<S45>/Add8' incorporates:
     *  Gain: '<S45>/Gain15'
     *  Gain: '<S45>/Gain16'
     */
    locvar_z4_k = ANN_EKF_NMPC_2_P.W14d.d * locvar_Divide4_ik +
      ANN_EKF_NMPC_2_P.W14d.c * locvar_xw14_k;

    /* Sum: '<S46>/Add1' incorporates:
     *  Gain: '<S46>/Gain7'
     *  Gain: '<S46>/Gain8'
     */
    locvar_z5_k = ANN_EKF_NMPC_2_P.W21d.d * loctmp_locvar_DataStoreRead1_m_idx_0
      + ANN_EKF_NMPC_2_P.W21d.c * locvar_xw21_k;

    /* Sum: '<S46>/Add2' incorporates:
     *  Gain: '<S46>/Gain11'
     *  Gain: '<S46>/Gain12'
     */
    locvar_z6_k = ANN_EKF_NMPC_2_P.W22d.d * loctmp_locvar_DataStoreRead1_m_idx_1
      + ANN_EKF_NMPC_2_P.W22d.c * locvar_xw22_k;

    /* Sum: '<S46>/Add3' incorporates:
     *  Gain: '<S46>/Gain13'
     *  Gain: '<S46>/Gain14'
     */
    locvar_z7_k = ANN_EKF_NMPC_2_P.W23d.d * loctmp_locvar_DataStoreRead1_m_idx_2
      + ANN_EKF_NMPC_2_P.W23d.c * locvar_xw23_k;

    /* Sum: '<S46>/Add8' incorporates:
     *  Gain: '<S46>/Gain15'
     *  Gain: '<S46>/Gain16'
     */
    locvar_z8_k = ANN_EKF_NMPC_2_P.W24d.d * loctmp_locvar_DataStoreRead1_m_idx_3
      + ANN_EKF_NMPC_2_P.W24d.c * locvar_xw24_k;

    /* Sum: '<S47>/Add1' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *  Gain: '<S47>/Gain7'
     *  Gain: '<S47>/Gain8'
     */
    locvar_z9_k = ANN_EKF_NMPC_2_P.W31d.d * locvar_Reshape1[4] +
      ANN_EKF_NMPC_2_P.W31d.c * locvar_xw31_k;

    /* Sum: '<S47>/Add2' incorporates:
     *  BusCreator: '<S145>/Bus Creator1'
     *  Gain: '<S47>/Gain11'
     *  Gain: '<S47>/Gain12'
     */
    locvar_z10_k = ANN_EKF_NMPC_2_P.W32d.d * locvar_Reshape1[8] +
      ANN_EKF_NMPC_2_P.W32d.c * locvar_xw32_k;

    /* Sum: '<S47>/Add3' incorporates:
     *  BusCreator: '<S145>/Bus Creator1'
     *  Gain: '<S47>/Gain13'
     *  Gain: '<S47>/Gain14'
     */
    locvar_z11_k = ANN_EKF_NMPC_2_P.W33d.d * locvar_Reshape1[7] +
      ANN_EKF_NMPC_2_P.W33d.c * locvar_xw33_k;

    /* Sum: '<S47>/Add8' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *  Gain: '<S47>/Gain15'
     *  Gain: '<S47>/Gain16'
     */
    locvar_z12_k = ANN_EKF_NMPC_2_P.W34d.d * locvar_Reshape1[6] +
      ANN_EKF_NMPC_2_P.W34d.c * locvar_xw34_k;

    /* SignalConversion: '<S2>/Signal Conversion' */
    ANN_EKF_NMPC_2_B.VT_cmd = ANN_EKF_NMPC_2_B.Subsystem1_mx.Sqrt;

    /* SignalConversion: '<S2>/Signal Conversion' */
    ANN_EKF_NMPC_2_B.theta_cmd = locvar_MathFunction1_e4;

    /* SignalConversion: '<S2>/Signal Conversion' */
    ANN_EKF_NMPC_2_B.phi_cmd = locvar_Divide_aa;

    /* SignalConversion: '<S2>/Signal Conversion' incorporates:
     *  Constant: '<S21>/Beta command'
     */
    ANN_EKF_NMPC_2_B.beta_cmd = ANN_EKF_NMPC_2_P.Betacommand_Value;

    /* SignalConversion: '<S2>/Signal Conversion1' */
    ANN_EKF_NMPC_2_B.etaLat = locvar_Divide3_oc;

    /* SignalConversion: '<S2>/Signal Conversion1' */
    ANN_EKF_NMPC_2_B.etaLon = locvar_Add1_o3;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    memcpy(&ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_am[0], &locvar_DataStoreRead2_p[0],
           84U * sizeof(real_T));

    /* Update for UnitDelay: '<S13>/UD' */
    ANN_EKF_NMPC_2_DW.UD_DSTATE = locvar_TSamp;

    /* Update for UnitDelay: '<S14>/UD' */
    ANN_EKF_NMPC_2_DW.UD_DSTATE_o = locvar_TSamp_j;

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
    ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE +=
      ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_gainval * locvar_Add_au;
    if (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE >=
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_UpperSat) {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE =
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_UpperSat;
    } else {
      if (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE <=
          ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_LowerSat) {
        ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE =
          ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_LowerSat;
      }
    }

    if (locvar_LogicalOperator) {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState = 1;
    } else {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState = 0;
    }

    /* End of Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */

    /* Update for UnitDelay: '<S45>/Unit Delay' incorporates:
     *  Gain: '<S45>/Gain1'
     *  Gain: '<S45>/Gain2'
     *  Sum: '<S45>/Add4'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_mi = ANN_EKF_NMPC_2_P.W11d.b *
      locvar_MathFunction_bv + ANN_EKF_NMPC_2_P.W11d.a * locvar_xw11_k;

    /* Update for UnitDelay: '<S45>/Unit Delay1' incorporates:
     *  Gain: '<S45>/Gain3'
     *  Gain: '<S45>/Gain4'
     *  Sum: '<S45>/Add5'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_e = ANN_EKF_NMPC_2_P.W12d.b *
      locvar_Divide3_ai5 + ANN_EKF_NMPC_2_P.W12d.a * locvar_xw12_k;

    /* Update for UnitDelay: '<S45>/Unit Delay2' incorporates:
     *  Gain: '<S45>/Gain5'
     *  Gain: '<S45>/Gain6'
     *  Sum: '<S45>/Add6'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE = ANN_EKF_NMPC_2_P.W13d.b *
      locvar_Divide5_ny + ANN_EKF_NMPC_2_P.W13d.a * locvar_xw13_k;

    /* Update for UnitDelay: '<S45>/Unit Delay3' incorporates:
     *  Gain: '<S45>/Gain7'
     *  Gain: '<S45>/Gain8'
     *  Sum: '<S45>/Add7'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE = ANN_EKF_NMPC_2_P.W14d.b *
      locvar_Divide4_ik + ANN_EKF_NMPC_2_P.W14d.a * locvar_xw14_k;

    /* Update for UnitDelay: '<S46>/Unit Delay' incorporates:
     *  Gain: '<S46>/Gain10'
     *  Gain: '<S46>/Gain9'
     *  Sum: '<S46>/Add4'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_jh = ANN_EKF_NMPC_2_P.W21d.b *
      loctmp_locvar_DataStoreRead1_m_idx_0 + ANN_EKF_NMPC_2_P.W21d.a *
      locvar_xw21_k;

    /* Update for UnitDelay: '<S46>/Unit Delay1' incorporates:
     *  Gain: '<S46>/Gain1'
     *  Gain: '<S46>/Gain2'
     *  Sum: '<S46>/Add5'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_n = ANN_EKF_NMPC_2_P.W22d.b *
      loctmp_locvar_DataStoreRead1_m_idx_1 + ANN_EKF_NMPC_2_P.W22d.a *
      locvar_xw22_k;

    /* Update for UnitDelay: '<S46>/Unit Delay2' incorporates:
     *  Gain: '<S46>/Gain3'
     *  Gain: '<S46>/Gain4'
     *  Sum: '<S46>/Add6'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_n = ANN_EKF_NMPC_2_P.W23d.b *
      loctmp_locvar_DataStoreRead1_m_idx_2 + ANN_EKF_NMPC_2_P.W23d.a *
      locvar_xw23_k;

    /* Update for UnitDelay: '<S46>/Unit Delay3' incorporates:
     *  Gain: '<S46>/Gain5'
     *  Gain: '<S46>/Gain6'
     *  Sum: '<S46>/Add7'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_f = ANN_EKF_NMPC_2_P.W24d.b *
      loctmp_locvar_DataStoreRead1_m_idx_3 + ANN_EKF_NMPC_2_P.W24d.a *
      locvar_xw24_k;

    /* Update for UnitDelay: '<S47>/Unit Delay' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *  Gain: '<S47>/Gain10'
     *  Gain: '<S47>/Gain9'
     *  Sum: '<S47>/Add4'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_d = ANN_EKF_NMPC_2_P.W31d.b *
      locvar_Reshape1[4] + ANN_EKF_NMPC_2_P.W31d.a * locvar_xw31_k;

    /* Update for UnitDelay: '<S47>/Unit Delay1' incorporates:
     *  BusCreator: '<S145>/Bus Creator1'
     *  Gain: '<S47>/Gain1'
     *  Gain: '<S47>/Gain2'
     *  Sum: '<S47>/Add5'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_j = ANN_EKF_NMPC_2_P.W32d.b *
      locvar_Reshape1[8] + ANN_EKF_NMPC_2_P.W32d.a * locvar_xw32_k;

    /* Update for UnitDelay: '<S47>/Unit Delay2' incorporates:
     *  BusCreator: '<S145>/Bus Creator1'
     *  Gain: '<S47>/Gain3'
     *  Gain: '<S47>/Gain4'
     *  Sum: '<S47>/Add6'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_l = ANN_EKF_NMPC_2_P.W33d.b *
      locvar_Reshape1[7] + ANN_EKF_NMPC_2_P.W33d.a * locvar_xw33_k;

    /* Update for UnitDelay: '<S47>/Unit Delay3' incorporates:
     *  BusCreator: '<S145>/Bus Creator'
     *  Gain: '<S47>/Gain5'
     *  Gain: '<S47>/Gain6'
     *  Sum: '<S47>/Add7'
     */
    ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_j = ANN_EKF_NMPC_2_P.W34d.b *
      locvar_Reshape1[6] + ANN_EKF_NMPC_2_P.W34d.a * locvar_xw34_k;

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
    ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k +=
      ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_gainval_p * locvar_Add_pii;
    if (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k >=
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_UpperSat_o) {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k =
        ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_UpperSat_o;
    } else {
      if (ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k <=
          ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_LowerSat_p) {
        ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k =
          ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_LowerSat_p;
      }
    }

    if (locvar_LogicalOperator_h) {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState_a = 1;
    } else {
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState_a = 0;
    }

    /* End of Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
  } else {
    if (ANN_EKF_NMPC_2_DW.NMPCsubsystem_MODE) {
      /* Disable for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE =
        ANN_EKF_NMPC_2_B.DiscreteTimeIntegrator;

      /* Disable for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
      ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k =
        ANN_EKF_NMPC_2_B.DiscreteTimeIntegrator_h;
      ANN_EKF_NMPC_2_DW.NMPCsubsystem_MODE = false;
    }
  }

  /* End of Inport: '<Root>/IFS // NMPC' */
  /* End of Outputs for SubSystem: '<Root>/NMPC (subsystem)' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_Control Surface Commands_at_inport_0' */
  ANN_EKF_NMPC_2_Y.ControlSurfaceCommands.throttle_cmd =
    ANN_EKF_NMPC_2_B.throttle_cmd;
  ANN_EKF_NMPC_2_Y.ControlSurfaceCommands.elevator_cmd =
    ANN_EKF_NMPC_2_B.elevator_cmd;
  ANN_EKF_NMPC_2_Y.ControlSurfaceCommands.aileron_cmd =
    ANN_EKF_NMPC_2_B.aileron_cmd;
  ANN_EKF_NMPC_2_Y.ControlSurfaceCommands.rudder_cmd =
    ANN_EKF_NMPC_2_B.rudder_cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_Commanded States_at_inport_0' */
  ANN_EKF_NMPC_2_Y.CommandedStates.VT_cmd = ANN_EKF_NMPC_2_B.VT_cmd;
  ANN_EKF_NMPC_2_Y.CommandedStates.theta_cmd = ANN_EKF_NMPC_2_B.theta_cmd;
  ANN_EKF_NMPC_2_Y.CommandedStates.phi_cmd = ANN_EKF_NMPC_2_B.phi_cmd;
  ANN_EKF_NMPC_2_Y.CommandedStates.beta_cmd = ANN_EKF_NMPC_2_B.beta_cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_Track Angles_at_inport_0' */
  ANN_EKF_NMPC_2_Y.TrackAngles.etaLat = ANN_EKF_NMPC_2_B.etaLat;
  ANN_EKF_NMPC_2_Y.TrackAngles.etaLon = ANN_EKF_NMPC_2_B.etaLon;

  /* Sum: '<S65>/Add1' incorporates:
   *  Constant: '<S61>/delta'
   */
  locvar_Add1_pe = ANN_EKF_NMPC_2_P.delta_Value + locvar_x_est_k1k1_m[1];

  /* Sum: '<S66>/Add' incorporates:
   *  Constant: '<S61>/delta'
   */
  locvar_Add_htd = ANN_EKF_NMPC_2_P.delta_Value + locvar_x_est_k1k1_m[2];

  /* Sum: '<S67>/Add' incorporates:
   *  Constant: '<S61>/delta'
   */
  locvar_Add_fm = ANN_EKF_NMPC_2_P.delta_Value + locvar_x_est_k1k1_m[0];

  /* Gain: '<S812>/Gain8' */
  locvar_Axb_e *= 1.0 / ANN_EKF_NMPC_2_P.g;

  /* Gain: '<S812>/Gain9' */
  locvar_Ayb_k *= 1.0 / ANN_EKF_NMPC_2_P.g;

  /* Gain: '<S812>/Gain10' */
  locvar_Azb_h *= 1.0 / ANN_EKF_NMPC_2_P.g;

  /* BusCreator: '<S145>/Bus Creator3' */
  locvar_BusCreator3.Throttle = locvar_Reshape1[0];
  locvar_BusCreator3.Elevator = locvar_Reshape1[1];
  locvar_BusCreator3.Aileron = locvar_Reshape1[2];
  locvar_BusCreator3.Rudder = locvar_Reshape1[3];

  /* Gain: '<S181>/Gain10' */
  locvar_Azb = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_ap;

  /* Gain: '<S181>/Gain8' */
  locvar_Axb = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_d4;

  /* Gain: '<S181>/Gain9' */
  locvar_Ayb = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_ds;

  /* Gain: '<S226>/Gain10' */
  locvar_Azb_d = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_i;

  /* Gain: '<S226>/Gain8' */
  locvar_Axb_d = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_h5;

  /* Gain: '<S226>/Gain9' */
  locvar_Ayb_f = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_ce;

  /* Gain: '<S271>/Gain10' */
  locvar_Azb_j = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_co;

  /* Gain: '<S271>/Gain8' */
  locvar_Axb_f = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_na;

  /* Gain: '<S271>/Gain9' */
  locvar_Ayb_fd = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_hd;

  /* Gain: '<S316>/Gain10' */
  locvar_Azb_jr = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_m;

  /* Gain: '<S316>/Gain8' */
  locvar_Axb_k = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_pp;

  /* Gain: '<S316>/Gain9' */
  locvar_Ayb_d = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_bs;

  /* Gain: '<S361>/Gain10' */
  locvar_Azb_c = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_d;

  /* Gain: '<S361>/Gain8' */
  locvar_Axb_m = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_le;

  /* Gain: '<S361>/Gain9' */
  locvar_Ayb_i = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_c0;

  /* Gain: '<S406>/Gain10' */
  locvar_Azb_dq = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_e;

  /* Gain: '<S406>/Gain8' */
  locvar_Axb_dd = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_dl;

  /* Gain: '<S406>/Gain9' */
  locvar_Ayb_j = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_cx;

  /* Gain: '<S451>/Gain10' */
  locvar_Azb_k = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_jq;

  /* Gain: '<S451>/Gain8' */
  locvar_Axb_p = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_b;

  /* Gain: '<S451>/Gain9' */
  locvar_Ayb_b = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_if;

  /* Gain: '<S496>/Gain10' */
  locvar_Azb_n = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_gd;

  /* Gain: '<S496>/Gain8' */
  locvar_Axb_h = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_n;

  /* Gain: '<S496>/Gain9' */
  locvar_Ayb_n = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch;

  /* Gain: '<S541>/Gain10' */
  locvar_Azb_l = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_i1;

  /* Gain: '<S541>/Gain8' */
  locvar_Axb_mh = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_e4;

  /* Gain: '<S541>/Gain9' */
  locvar_Ayb_n3 = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_py;

  /* Gain: '<S586>/Gain10' */
  locvar_Azb_o = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_gl;

  /* Gain: '<S586>/Gain8' */
  locvar_Axb_i = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_il;

  /* Gain: '<S586>/Gain9' */
  locvar_Ayb_o = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_oa;

  /* Gain: '<S631>/Gain10' */
  locvar_Azb_oy = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_k5;

  /* Gain: '<S631>/Gain8' */
  locvar_Axb_m3 = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_li;

  /* Gain: '<S631>/Gain9' */
  locvar_Ayb_g = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_p0l;

  /* Gain: '<S676>/Gain10' */
  locvar_Azb_jc = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_ga;

  /* Gain: '<S676>/Gain8' */
  locvar_Axb_l = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_lz;

  /* Gain: '<S676>/Gain9' */
  locvar_Ayb_h = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_ex;

  /* Gain: '<S721>/Gain10' */
  locvar_Azb_e = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_c;

  /* Gain: '<S721>/Gain8' */
  locvar_Axb_c = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_p;

  /* Gain: '<S721>/Gain9' */
  locvar_Ayb_a = 1.0 / ANN_EKF_NMPC_2_P.g * locvar_ManualSwitch_h2;

  /* Sum: '<S766>/Add1' incorporates:
   *  Constant: '<S152>/delta'
   */
  locvar_Add1_i5 = ANN_EKF_NMPC_2_P.delta_Value_o + locvar_x_est_k1k1[2];

  /* Sum: '<S767>/Add' incorporates:
   *  Constant: '<S152>/delta'
   */
  locvar_Add_cih = ANN_EKF_NMPC_2_P.delta_Value_o + locvar_x_est_k1k1[1];

  /* Sum: '<S771>/Add1' incorporates:
   *  Constant: '<S152>/delta'
   */
  locvar_Add1_ktx = ANN_EKF_NMPC_2_P.delta_Value_o + locvar_x_est_k1k1[3];

  /* Sum: '<S772>/Add' incorporates:
   *  Constant: '<S152>/delta'
   */
  locvar_Add_c1 = ANN_EKF_NMPC_2_P.delta_Value_o + locvar_x_est_k1k1[0];

  /* Gain: '<S145>/Gain' */
  locvar_Gain_o5[0] = ANN_EKF_NMPC_2_P.Gain_Gain_cw * locvar_Reshape1[12];
  locvar_Gain_o5[1] = ANN_EKF_NMPC_2_P.Gain_Gain_cw * locvar_Reshape1[13];

  /* Update for UnitDelay: '<S50>/x_est_[0//0]' incorporates:
   *  Reshape: '<S50>/Reshape3'
   */
  for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
    ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[loctmp_i_0] = locvar_Divide1_ip[loctmp_i_0];
  }

  /* End of Update for UnitDelay: '<S50>/x_est_[0//0]' */

  /* Update for UnitDelay: '<S50>/Unit Delay1' incorporates:
   *  BusCreator: '<S145>/Bus Creator1'
   *  Gain: '<S49>/Gain4'
   */
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[0] = locvar_Reshape1[7];
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[1] = locvar_Reshape1[8];
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[2] = loctmp_locvar_BusCreator1_psi;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[3] = ANN_EKF_NMPC_2_P.g * locvar_Axb_e;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[4] = ANN_EKF_NMPC_2_P.g * locvar_Ayb_k;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[5] = ANN_EKF_NMPC_2_P.g * locvar_Azb_h;

  /* Product: '<S56>/Product3' incorporates:
   *  Constant: '<S56>/H_[k]'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      loctmp_tmp_4[loctmp_i_1 + 6 * loctmp_i_0] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        loctmp_tmp_4[loctmp_i_1 + 6 * loctmp_i_0] += ANN_EKF_NMPC_2_P.H_k_Value
          [6 * locvar_DataTypeConversion1 + loctmp_i_1] * locvar_P_kk1[6 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* Update for UnitDelay: '<S56>/P_est_[0//0]' incorporates:
   *  Product: '<S56>/Product3'
   *  Sum: '<S56>/Subtract4'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 6; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 6; loctmp_i_0++) {
      loctmp_tmp_7 = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 6;
           locvar_DataTypeConversion1++) {
        loctmp_tmp_7 += locvar_Product1_b[6 * locvar_DataTypeConversion1 +
          loctmp_i_1] * loctmp_tmp_4[6 * loctmp_i_0 + locvar_DataTypeConversion1];
      }

      ANN_EKF_NMPC_2_DW.P_est_00_DSTATE[loctmp_i_1 + 6 * loctmp_i_0] =
        locvar_P_kk1[6 * loctmp_i_0 + loctmp_i_1] - loctmp_tmp_7;
    }
  }

  /* End of Update for UnitDelay: '<S56>/P_est_[0//0]' */

  /* Update for UnitDelay: '<S60>/Delay Input1' */
  ANN_EKF_NMPC_2_DW.DelayInput1_DSTATE = locvar_North;

  /* Update for UnitDelay: '<S146>/Unit Delay1' incorporates:
   *  Gain: '<S145>/Gain4'
   *  Inport: '<Root>/Accelerometer meas'
   *  Update for Inport: '<Root>/Servo Commands'
   */
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[0] =
    ANN_EKF_NMPC_2_U.ServoCommands.throttle_cmd;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[1] =
    ANN_EKF_NMPC_2_U.ServoCommands.elevator_cmd;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[2] =
    ANN_EKF_NMPC_2_U.ServoCommands.aileron_cmd;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[3] =
    ANN_EKF_NMPC_2_U.ServoCommands.rudder_cmd;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[4] = ANN_EKF_NMPC_2_P.g *
    ANN_EKF_NMPC_2_U.Accelerometermeas.Axb;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[5] = ANN_EKF_NMPC_2_P.g *
    ANN_EKF_NMPC_2_U.Accelerometermeas.Ayb;
  ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[6] = ANN_EKF_NMPC_2_P.g *
    ANN_EKF_NMPC_2_U.Accelerometermeas.Azb;

  /* Update for UnitDelay: '<S146>/x_est_[0//0]' */
  for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
    /* Saturate: '<S146>/Saturation1' */
    if (locvar_Reshape1[loctmp_i_0] >
        ANN_EKF_NMPC_2_P.saturation_max_sta[loctmp_i_0]) {
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0] =
        ANN_EKF_NMPC_2_P.saturation_max_sta[loctmp_i_0];
    } else if (locvar_Reshape1[loctmp_i_0] <
               ANN_EKF_NMPC_2_P.saturation_min_sta[loctmp_i_0]) {
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0] =
        ANN_EKF_NMPC_2_P.saturation_min_sta[loctmp_i_0];
    } else {
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[loctmp_i_0] =
        locvar_Reshape1[loctmp_i_0];
    }

    /* End of Saturate: '<S146>/Saturation1' */
  }

  /* End of Update for UnitDelay: '<S146>/x_est_[0//0]' */

  /* Update for UnitDelay: '<S195>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE = locvar_Divide;

  /* Update for UnitDelay: '<S510>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_k = locvar_Divide_o;

  /* Update for UnitDelay: '<S285>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_a = locvar_Divide_p3;

  /* Update for UnitDelay: '<S240>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_m = locvar_Divide_f5;

  /* Update for UnitDelay: '<S465>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_f = locvar_Divide_hc;

  /* Update for UnitDelay: '<S555>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_i = locvar_Divide_en;

  /* Update for UnitDelay: '<S600>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_j = locvar_Divide_ml;

  /* Update for UnitDelay: '<S645>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_b = locvar_Divide_hvn;

  /* Update for UnitDelay: '<S690>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_c = locvar_Divide_hz;

  /* Update for UnitDelay: '<S735>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_cp = locvar_Divide_n;

  /* Update for UnitDelay: '<S330>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_g = locvar_Divide_c;

  /* Update for UnitDelay: '<S375>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_o = locvar_Divide_k2;

  /* Update for UnitDelay: '<S420>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_or = locvar_Divide_jpd;

  /* Product: '<S147>/Product2' */
  for (loctmp_i_1 = 0; loctmp_i_1 < 8; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      loctmp_locvar_P_kk1_m[loctmp_i_1 + (loctmp_i_0 << 3)] = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 14;
           locvar_DataTypeConversion1++) {
        loctmp_locvar_P_kk1_m[loctmp_i_1 + (loctmp_i_0 << 3)] += locvar_Reshape
          [(locvar_DataTypeConversion1 << 3) + loctmp_i_1] * locvar_P_kk1_m[14 *
          loctmp_i_0 + locvar_DataTypeConversion1];
      }
    }
  }

  /* Update for UnitDelay: '<S147>/P_est_[0//0]' incorporates:
   *  Product: '<S147>/Product2'
   *  Sum: '<S147>/Subtract3'
   */
  for (loctmp_i_1 = 0; loctmp_i_1 < 14; loctmp_i_1++) {
    for (loctmp_i_0 = 0; loctmp_i_0 < 14; loctmp_i_0++) {
      loctmp_tmp_7 = 0.0;
      for (locvar_DataTypeConversion1 = 0; locvar_DataTypeConversion1 < 8;
           locvar_DataTypeConversion1++) {
        loctmp_tmp_7 += locvar_Product1_oh[14 * locvar_DataTypeConversion1 +
          loctmp_i_1] * loctmp_locvar_P_kk1_m[(loctmp_i_0 << 3) +
          locvar_DataTypeConversion1];
      }

      ANN_EKF_NMPC_2_DW.P_est_00_DSTATE_o[loctmp_i_1 + 14 * loctmp_i_0] =
        locvar_P_kk1_m[14 * loctmp_i_0 + loctmp_i_1] - loctmp_tmp_7;
    }
  }

  /* End of Update for UnitDelay: '<S147>/P_est_[0//0]' */

  /* Update for UnitDelay: '<S826>/Unit Delay' */
  ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_p = locvar_Divide_ow;

  /* Update for Delay: '<Root>/Delay 100 dt' incorporates:
   *  Update for Inport: '<Root>/FL_ann'
   */
  for (loctmp_i_0 = 0; loctmp_i_0 < 99; loctmp_i_0++) {
    ANN_EKF_NMPC_2_DW.Delay100dt_DSTATE[loctmp_i_0] =
      ANN_EKF_NMPC_2_DW.Delay100dt_DSTATE[loctmp_i_0 + 1];
  }

  ANN_EKF_NMPC_2_DW.Delay100dt_DSTATE[99] = ANN_EKF_NMPC_2_U.FL_ann;

  /* End of Update for Delay: '<Root>/Delay 100 dt' */
}

/* Model initialize function */
void ANN_EKF_NMPC_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(ANN_EKF_NMPC_2_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &ANN_EKF_NMPC_2_B), 0,
                sizeof(B_ANN_EKF_NMPC_2_T));

  /* states (dwork) */
  (void) memset((void *)&ANN_EKF_NMPC_2_DW, 0,
                sizeof(DW_ANN_EKF_NMPC_2_T));

  /* external inputs */
  (void) memset((void *)&ANN_EKF_NMPC_2_U, 0,
                sizeof(ExtU_ANN_EKF_NMPC_2_T));

  /* external outputs */
  (void) memset((void *)&ANN_EKF_NMPC_2_Y, 0,
                sizeof(ExtY_ANN_EKF_NMPC_2_T));

  {
    int32_T loctmp_i;

    /* Start for Enabled SubSystem: '<Root>/ANN (subsystem)' */
    for (loctmp_i = 0; loctmp_i < 49; loctmp_i++) {
      /* Start for DataStoreMemory: '<S7>/NMPC Memory' */
      ANN_EKF_NMPC_2_DW.x_ann_X[loctmp_i] =
        ANN_EKF_NMPC_2_P.NMPCMemory_InitialValue[loctmp_i];

      /* Start for DataStoreMemory: '<S7>/NMPC Memory1' */
      ANN_EKF_NMPC_2_DW.x_ann_Y[loctmp_i] =
        ANN_EKF_NMPC_2_P.NMPCMemory1_InitialValue[loctmp_i];

      /* Start for DataStoreMemory: '<S7>/NMPC Memory2' */
      ANN_EKF_NMPC_2_DW.x_ann_Z[loctmp_i] =
        ANN_EKF_NMPC_2_P.NMPCMemory2_InitialValue[loctmp_i];
    }

    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      /* Start for DataStoreMemory: '<S7>/NMPC Memory3' */
      ANN_EKF_NMPC_2_DW.y_ann_X[loctmp_i] =
        ANN_EKF_NMPC_2_P.NMPCMemory3_InitialValue[loctmp_i];

      /* Start for DataStoreMemory: '<S7>/NMPC Memory4' */
      ANN_EKF_NMPC_2_DW.y_ann_Y[loctmp_i] =
        ANN_EKF_NMPC_2_P.NMPCMemory4_InitialValue[loctmp_i];

      /* Start for DataStoreMemory: '<S7>/NMPC Memory5' */
      ANN_EKF_NMPC_2_DW.y_ann_Z[loctmp_i] =
        ANN_EKF_NMPC_2_P.NMPCMemory5_InitialValue[loctmp_i];
    }

    for (loctmp_i = 0; loctmp_i < 40; loctmp_i++) {
      /* Start for DataStoreMemory: '<S1>/NMPC Memory' */
      ANN_EKF_NMPC_2_DW.a_ann_X[loctmp_i] = ANN_EKF_NMPC_2_P.a_ann_X_ic[loctmp_i];

      /* Start for DataStoreMemory: '<S1>/NMPC Memory1' */
      ANN_EKF_NMPC_2_DW.b_ann_X[loctmp_i] = ANN_EKF_NMPC_2_P.b_ann_X_ic[loctmp_i];

      /* Start for DataStoreMemory: '<S1>/NMPC Memory10' */
      ANN_EKF_NMPC_2_DW.a_ann_Y[loctmp_i] = ANN_EKF_NMPC_2_P.a_ann_Y_ic[loctmp_i];

      /* Start for DataStoreMemory: '<S1>/NMPC Memory11' */
      ANN_EKF_NMPC_2_DW.b_ann_Y[loctmp_i] = ANN_EKF_NMPC_2_P.b_ann_Y_ic[loctmp_i];
    }

    /* Start for DataStoreMemory: '<S1>/NMPC Memory12' */
    ANN_EKF_NMPC_2_DW.c_ann_Y = ANN_EKF_NMPC_2_P.c_ann_Y_ic;

    /* Start for DataStoreMemory: '<S1>/NMPC Memory14' */
    ANN_EKF_NMPC_2_DW.lambda_ann_Y = ANN_EKF_NMPC_2_P.lambda_ann_Y_ic;

    /* Start for DataStoreMemory: '<S1>/NMPC Memory2' */
    ANN_EKF_NMPC_2_DW.c_ann_X = ANN_EKF_NMPC_2_P.c_ann_X_ic;
    for (loctmp_i = 0; loctmp_i < 280; loctmp_i++) {
      /* Start for DataStoreMemory: '<S1>/NMPC Memory13' */
      ANN_EKF_NMPC_2_DW.w_ann_Y[loctmp_i] = ANN_EKF_NMPC_2_P.w_ann_Y_ic[loctmp_i];

      /* Start for DataStoreMemory: '<S1>/NMPC Memory3' */
      ANN_EKF_NMPC_2_DW.w_ann_X[loctmp_i] = ANN_EKF_NMPC_2_P.w_ann_X_ic[loctmp_i];
    }

    /* Start for DataStoreMemory: '<S1>/NMPC Memory4' */
    ANN_EKF_NMPC_2_DW.lambda_ann_X = ANN_EKF_NMPC_2_P.lambda_ann_X_ic;
    for (loctmp_i = 0; loctmp_i < 40; loctmp_i++) {
      /* Start for DataStoreMemory: '<S1>/NMPC Memory5' */
      ANN_EKF_NMPC_2_DW.a_ann_Z[loctmp_i] = ANN_EKF_NMPC_2_P.a_ann_Z_ic[loctmp_i];

      /* Start for DataStoreMemory: '<S1>/NMPC Memory6' */
      ANN_EKF_NMPC_2_DW.b_ann_Z[loctmp_i] = ANN_EKF_NMPC_2_P.b_ann_Z_ic[loctmp_i];
    }

    /* Start for DataStoreMemory: '<S1>/NMPC Memory7' */
    ANN_EKF_NMPC_2_DW.c_ann_Z = ANN_EKF_NMPC_2_P.c_ann_Z_ic;

    /* Start for DataStoreMemory: '<S1>/NMPC Memory8' */
    memcpy(&ANN_EKF_NMPC_2_DW.w_ann_Z[0], &ANN_EKF_NMPC_2_P.w_ann_Z_ic[0], 280U *
           sizeof(real_T));

    /* Start for DataStoreMemory: '<S1>/NMPC Memory9' */
    ANN_EKF_NMPC_2_DW.lambda_ann_Z = ANN_EKF_NMPC_2_P.lambda_ann_Z_ic;

    /* End of Start for SubSystem: '<Root>/ANN (subsystem)' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/ANN (subsystem)' */
    /* InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter' */
    ANN_EKF_NMPC_2_DW.DiscreteFilter_states =
      ANN_EKF_NMPC_2_P.DiscreteFilter_InitialStates;

    /* InitializeConditions for DiscreteFilter: '<S7>/Discrete Filter1' */
    ANN_EKF_NMPC_2_DW.DiscreteFilter1_states =
      ANN_EKF_NMPC_2_P.DiscreteFilter1_InitialStates;

    /* InitializeConditions for UnitDelay: '<S5>/Output' */
    ANN_EKF_NMPC_2_DW.Output_DSTATE = ANN_EKF_NMPC_2_P.Output_InitialCondition;
    for (loctmp_i = 0; loctmp_i < 40; loctmp_i++) {
      /* InitializeConditions for UnitDelay: '<S6>/a_ann_X_ic' */
      ANN_EKF_NMPC_2_DW.a_ann_X_ic_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.a_ann_X_ic[loctmp_i];

      /* InitializeConditions for UnitDelay: '<S6>/b_ann_X_ic' */
      ANN_EKF_NMPC_2_DW.b_ann_X_ic_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.b_ann_X_ic[loctmp_i];
    }

    /* InitializeConditions for UnitDelay: '<S6>/c_ann_X_ic' */
    ANN_EKF_NMPC_2_DW.c_ann_X_ic_DSTATE = ANN_EKF_NMPC_2_P.c_ann_X_ic;

    /* InitializeConditions for UnitDelay: '<S6>/w_ann_X_ic' */
    memcpy(&ANN_EKF_NMPC_2_DW.w_ann_X_ic_DSTATE[0],
           &ANN_EKF_NMPC_2_P.w_ann_X_ic[0], 280U * sizeof(real_T));
    for (loctmp_i = 0; loctmp_i < 40; loctmp_i++) {
      /* InitializeConditions for UnitDelay: '<S6>/a_ann_Y_ic' */
      ANN_EKF_NMPC_2_DW.a_ann_Y_ic_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.a_ann_Y_ic[loctmp_i];

      /* InitializeConditions for UnitDelay: '<S6>/b_ann_Y_ic' */
      ANN_EKF_NMPC_2_DW.b_ann_Y_ic_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.b_ann_Y_ic[loctmp_i];
    }

    /* InitializeConditions for UnitDelay: '<S6>/c_ann_Y_ic' */
    ANN_EKF_NMPC_2_DW.c_ann_Y_ic_DSTATE = ANN_EKF_NMPC_2_P.c_ann_Y_ic;

    /* InitializeConditions for UnitDelay: '<S6>/w_ann_Y_ic' */
    memcpy(&ANN_EKF_NMPC_2_DW.w_ann_Y_ic_DSTATE[0],
           &ANN_EKF_NMPC_2_P.w_ann_Y_ic[0], 280U * sizeof(real_T));
    for (loctmp_i = 0; loctmp_i < 40; loctmp_i++) {
      /* InitializeConditions for UnitDelay: '<S6>/a_ann_Z_ic' */
      ANN_EKF_NMPC_2_DW.a_ann_Z_ic_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.a_ann_Z_ic[loctmp_i];

      /* InitializeConditions for UnitDelay: '<S6>/b_ann_Z_ic' */
      ANN_EKF_NMPC_2_DW.b_ann_Z_ic_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.b_ann_Z_ic[loctmp_i];
    }

    /* InitializeConditions for UnitDelay: '<S6>/c_ann_Z_ic' */
    ANN_EKF_NMPC_2_DW.c_ann_Z_ic_DSTATE = ANN_EKF_NMPC_2_P.c_ann_Z_ic;

    /* InitializeConditions for UnitDelay: '<S6>/w_ann_Z_ic' */
    memcpy(&ANN_EKF_NMPC_2_DW.w_ann_Z_ic_DSTATE[0],
           &ANN_EKF_NMPC_2_P.w_ann_Z_ic[0], 280U * sizeof(real_T));

    /* End of InitializeConditions for SubSystem: '<Root>/ANN (subsystem)' */

    /* Start for Enabled SubSystem: '<Root>/ANN (subsystem)' */
    for (loctmp_i = 0; loctmp_i < 40; loctmp_i++) {
      /* VirtualOutportStart for Outport: '<S1>/a_ann_X' */
      ANN_EKF_NMPC_2_B.a_ann_X_ic[loctmp_i] = ANN_EKF_NMPC_2_P.a_ann_X_Y0;

      /* VirtualOutportStart for Outport: '<S1>/b_ann_X' */
      ANN_EKF_NMPC_2_B.b_ann_X_ic[loctmp_i] = ANN_EKF_NMPC_2_P.b_ann_X_Y0;
    }

    /* VirtualOutportStart for Outport: '<S1>/c_ann_X' */
    ANN_EKF_NMPC_2_B.c_ann_X_ic = ANN_EKF_NMPC_2_P.c_ann_X_Y0;

    /* VirtualOutportStart for Outport: '<S1>/w_ann_X' */
    for (loctmp_i = 0; loctmp_i < 280; loctmp_i++) {
      ANN_EKF_NMPC_2_B.w_ann_X_ic[loctmp_i] = ANN_EKF_NMPC_2_P.w_ann_X_Y0;
    }

    for (loctmp_i = 0; loctmp_i < 40; loctmp_i++) {
      /* VirtualOutportStart for Outport: '<S1>/a_ann_Y' */
      ANN_EKF_NMPC_2_B.a_ann_Y_ic[loctmp_i] = ANN_EKF_NMPC_2_P.a_ann_Y_Y0;

      /* VirtualOutportStart for Outport: '<S1>/b_ann_Y' */
      ANN_EKF_NMPC_2_B.b_ann_Y_ic[loctmp_i] = ANN_EKF_NMPC_2_P.b_ann_Y_Y0;
    }

    /* End of VirtualOutportStart for Outport: '<S1>/w_ann_X' */

    /* VirtualOutportStart for Outport: '<S1>/c_ann_Y' */
    ANN_EKF_NMPC_2_B.c_ann_Y_ic = ANN_EKF_NMPC_2_P.c_ann_Y_Y0;

    /* VirtualOutportStart for Outport: '<S1>/w_ann_Y' */
    for (loctmp_i = 0; loctmp_i < 280; loctmp_i++) {
      ANN_EKF_NMPC_2_B.w_ann_Y_ic[loctmp_i] = ANN_EKF_NMPC_2_P.w_ann_Y_Y0;
    }

    for (loctmp_i = 0; loctmp_i < 40; loctmp_i++) {
      /* VirtualOutportStart for Outport: '<S1>/a_ann_Z' */
      ANN_EKF_NMPC_2_B.a_ann_Z_ic[loctmp_i] = ANN_EKF_NMPC_2_P.a_ann_Z_Y0;

      /* VirtualOutportStart for Outport: '<S1>/b_ann_Z' */
      ANN_EKF_NMPC_2_B.b_ann_Z_ic[loctmp_i] = ANN_EKF_NMPC_2_P.b_ann_Z_Y0;
    }

    /* End of VirtualOutportStart for Outport: '<S1>/w_ann_Y' */

    /* VirtualOutportStart for Outport: '<S1>/c_ann_Z' */
    ANN_EKF_NMPC_2_B.c_ann_Z_ic = ANN_EKF_NMPC_2_P.c_ann_Z_Y0;

    /* VirtualOutportStart for Outport: '<S1>/w_ann_Z' */
    for (loctmp_i = 0; loctmp_i < 280; loctmp_i++) {
      ANN_EKF_NMPC_2_B.w_ann_Z_ic[loctmp_i] = ANN_EKF_NMPC_2_P.w_ann_Z_Y0;
    }

    /* End of VirtualOutportStart for Outport: '<S1>/w_ann_Z' */
    /* End of Start for SubSystem: '<Root>/ANN (subsystem)' */

    /* Start for Enabled SubSystem: '<Root>/NMPC (subsystem)' */
    /* Start for DataStoreMemory: '<S17>/Logic time control' */
    ANN_EKF_NMPC_2_DW.sw_time = ANN_EKF_NMPC_2_P.Logictimecontrol_InitialValue;

    /* Start for DataStoreMemory: '<S17>/Remote aileron' */
    ANN_EKF_NMPC_2_DW.remote_aileron_mem =
      ANN_EKF_NMPC_2_P.Remoteaileron_InitialValue;

    /* Start for DataStoreMemory: '<S17>/Remote elevator' */
    ANN_EKF_NMPC_2_DW.remote_elevator_mem =
      ANN_EKF_NMPC_2_P.Remoteelevator_InitialValue;

    /* Start for DataStoreMemory: '<S17>/Remote rudder' */
    ANN_EKF_NMPC_2_DW.remote_rudder_mem =
      ANN_EKF_NMPC_2_P.Remoterudder_InitialValue;

    /* Start for DataStoreMemory: '<S17>/Remote throttle' */
    ANN_EKF_NMPC_2_DW.remote_throttle_mem =
      ANN_EKF_NMPC_2_P.Remotethrottle_InitialValue;

    /* Start for DataStoreMemory: '<S19>/Home Reset Memory' */
    ANN_EKF_NMPC_2_DW.Home_reset = ANN_EKF_NMPC_2_P.HomeResetMemory_InitialValue;

    /* Start for DataStoreMemory: '<S19>/PIC//CIC Last State Memory' */
    ANN_EKF_NMPC_2_DW.PIC_CIC_Last =
      ANN_EKF_NMPC_2_P.PICCICLastStateMemory_InitialValue;

    /* Start for DataStoreMemory: '<S19>/Start Waypoint Memory' */
    ANN_EKF_NMPC_2_DW.Start_Wpt[0] =
      ANN_EKF_NMPC_2_P.StartWaypointMemory_InitialValue[0];
    ANN_EKF_NMPC_2_DW.Start_Wpt[1] =
      ANN_EKF_NMPC_2_P.StartWaypointMemory_InitialValue[1];
    ANN_EKF_NMPC_2_DW.Start_Wpt[2] =
      ANN_EKF_NMPC_2_P.StartWaypointMemory_InitialValue[2];

    /* Start for DataStoreMemory: '<S19>/Waypoint Index Memory' */
    ANN_EKF_NMPC_2_DW.Waypoint_Index =
      ANN_EKF_NMPC_2_P.WaypointIndexMemory_InitialValue;

    /* InitializeConditions for Enabled SubSystem: '<Root>/NMPC (subsystem)' */
    for (loctmp_i = 0; loctmp_i < 84; loctmp_i++) {
      /* Start for DataStoreMemory: '<S2>/NMPC Memory' */
      ANN_EKF_NMPC_2_DW.u_nmpc[loctmp_i] =
        ANN_EKF_NMPC_2_P.NMPCMemory_InitialValue_d[loctmp_i];

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
      ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_am[loctmp_i] =
        ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition[loctmp_i];
    }

    /* End of Start for SubSystem: '<Root>/NMPC (subsystem)' */

    /* InitializeConditions for UnitDelay: '<S13>/UD' */
    ANN_EKF_NMPC_2_DW.UD_DSTATE =
      ANN_EKF_NMPC_2_P.DiscreteDerivative_ICPrevScaledInput;

    /* InitializeConditions for UnitDelay: '<S14>/UD' */
    ANN_EKF_NMPC_2_DW.UD_DSTATE_o =
      ANN_EKF_NMPC_2_P.DiscreteDerivative1_ICPrevScaledInput;

    /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
    ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE = ANN_EKF_NMPC_2_P.ro0;
    ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState = 0;

    /* InitializeConditions for UnitDelay: '<S45>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_mi = ANN_EKF_NMPC_2_P.xw110;

    /* InitializeConditions for UnitDelay: '<S45>/Unit Delay1' */
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_e = ANN_EKF_NMPC_2_P.xw120;

    /* InitializeConditions for UnitDelay: '<S45>/Unit Delay2' */
    ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE = ANN_EKF_NMPC_2_P.xw130;

    /* InitializeConditions for UnitDelay: '<S45>/Unit Delay3' */
    ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE = ANN_EKF_NMPC_2_P.xw140;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_jh = ANN_EKF_NMPC_2_P.xw210;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay1' */
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_n = ANN_EKF_NMPC_2_P.xw220;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay2' */
    ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_n = ANN_EKF_NMPC_2_P.xw230;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay3' */
    ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_f = ANN_EKF_NMPC_2_P.xw240;

    /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_d = ANN_EKF_NMPC_2_P.xw310;

    /* InitializeConditions for UnitDelay: '<S47>/Unit Delay1' */
    ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_j = ANN_EKF_NMPC_2_P.xw320;

    /* InitializeConditions for UnitDelay: '<S47>/Unit Delay2' */
    ANN_EKF_NMPC_2_DW.UnitDelay2_DSTATE_l = ANN_EKF_NMPC_2_P.xw330;

    /* InitializeConditions for UnitDelay: '<S47>/Unit Delay3' */
    ANN_EKF_NMPC_2_DW.UnitDelay3_DSTATE_j = ANN_EKF_NMPC_2_P.xw340;

    /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
    ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_DSTATE_k =
      ANN_EKF_NMPC_2_P.DiscreteTimeIntegrator_IC;
    ANN_EKF_NMPC_2_DW.DiscreteTimeIntegrator_PrevResetState_a = 0;

    /* End of InitializeConditions for SubSystem: '<Root>/NMPC (subsystem)' */

    /* Start for Enabled SubSystem: '<Root>/NMPC (subsystem)' */
    /* VirtualOutportStart for Outport: '<S2>/Control  Surface Commands' */
    ANN_EKF_NMPC_2_B.throttle_cmd = ANN_EKF_NMPC_2_P.ControlSurfaceCommands_Y0;
    ANN_EKF_NMPC_2_B.elevator_cmd = ANN_EKF_NMPC_2_P.ControlSurfaceCommands_Y0;
    ANN_EKF_NMPC_2_B.aileron_cmd = ANN_EKF_NMPC_2_P.ControlSurfaceCommands_Y0;
    ANN_EKF_NMPC_2_B.rudder_cmd = ANN_EKF_NMPC_2_P.ControlSurfaceCommands_Y0;

    /* VirtualOutportStart for Outport: '<S2>/Commanded States' */
    ANN_EKF_NMPC_2_B.VT_cmd = ANN_EKF_NMPC_2_P.CommandedStates_Y0;
    ANN_EKF_NMPC_2_B.theta_cmd = ANN_EKF_NMPC_2_P.CommandedStates_Y0;
    ANN_EKF_NMPC_2_B.phi_cmd = ANN_EKF_NMPC_2_P.CommandedStates_Y0;
    ANN_EKF_NMPC_2_B.beta_cmd = ANN_EKF_NMPC_2_P.CommandedStates_Y0;

    /* VirtualOutportStart for Outport: '<S2>/Track Angles' */
    ANN_EKF_NMPC_2_B.etaLat = ANN_EKF_NMPC_2_P.TrackAngles_Y0;
    ANN_EKF_NMPC_2_B.etaLon = ANN_EKF_NMPC_2_P.TrackAngles_Y0;

    /* VirtualOutportStart for Outport: '<Root>/Distance to Waypoint' incorporates:
     *  VirtualOutportStart for Outport: '<S2>/Distance to Waypoint'
     */
    ANN_EKF_NMPC_2_Y.DistancetoWaypoint = ANN_EKF_NMPC_2_P.DistancetoWaypoint_Y0;

    /* VirtualOutportStart for Outport: '<Root>/Waypoint Index' incorporates:
     *  VirtualOutportStart for Outport: '<S2>/Waypoint Index'
     */
    ANN_EKF_NMPC_2_Y.WaypointIndex = ANN_EKF_NMPC_2_P.WaypointIndex_Y0;

    /* End of Start for SubSystem: '<Root>/NMPC (subsystem)' */
    ANN_EKF_NMPC_2_PrevZCX.Delay100dt_Reset_ZCE = UNINITIALIZED_ZCSIG;
    for (loctmp_i = 0; loctmp_i < 6; loctmp_i++) {
      /* InitializeConditions for UnitDelay: '<S50>/x_est_[0//0]' */
      ANN_EKF_NMPC_2_DW.x_est_00_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.x0_est_nav[loctmp_i];

      /* InitializeConditions for UnitDelay: '<S50>/Unit Delay1' */
      ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.UnitDelay1_InitialCondition;
    }

    /* InitializeConditions for UnitDelay: '<S56>/P_est_[0//0]' */
    memcpy(&ANN_EKF_NMPC_2_DW.P_est_00_DSTATE[0], &ANN_EKF_NMPC_2_P.P0_est_nav[0],
           36U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S60>/Delay Input1' */
    ANN_EKF_NMPC_2_DW.DelayInput1_DSTATE = ANN_EKF_NMPC_2_P.DetectChange_vinit;

    /* InitializeConditions for UnitDelay: '<S146>/Unit Delay1' */
    for (loctmp_i = 0; loctmp_i < 7; loctmp_i++) {
      ANN_EKF_NMPC_2_DW.UnitDelay1_DSTATE_d[loctmp_i] =
        ANN_EKF_NMPC_2_P.UnitDelay1_InitialCondition_p;
    }

    /* End of InitializeConditions for UnitDelay: '<S146>/Unit Delay1' */

    /* InitializeConditions for UnitDelay: '<S146>/x_est_[0//0]' */
    memcpy(&ANN_EKF_NMPC_2_DW.x_est_00_DSTATE_p[0],
           &ANN_EKF_NMPC_2_P.x0_est_sta[0], 14U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S195>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_a;

    /* InitializeConditions for UnitDelay: '<S510>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_k =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S285>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_a =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_k;

    /* InitializeConditions for UnitDelay: '<S240>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_m =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S465>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_f =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_h;

    /* InitializeConditions for UnitDelay: '<S555>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_i =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_f;

    /* InitializeConditions for UnitDelay: '<S600>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_j =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_n;

    /* InitializeConditions for UnitDelay: '<S645>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_b =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_fv;

    /* InitializeConditions for UnitDelay: '<S690>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_c =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S735>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_cp =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S330>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_g =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_ow;

    /* InitializeConditions for UnitDelay: '<S375>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_o =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_kg;

    /* InitializeConditions for UnitDelay: '<S420>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_or =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_e;

    /* InitializeConditions for UnitDelay: '<S147>/P_est_[0//0]' */
    memcpy(&ANN_EKF_NMPC_2_DW.P_est_00_DSTATE_o[0],
           &ANN_EKF_NMPC_2_P.P0_est_sta[0], 196U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S826>/Unit Delay' */
    ANN_EKF_NMPC_2_DW.UnitDelay_DSTATE_p =
      ANN_EKF_NMPC_2_P.UnitDelay_InitialCondition_d;

    /* InitializeConditions for Delay: '<Root>/Delay 100 dt' */
    for (loctmp_i = 0; loctmp_i < 100; loctmp_i++) {
      ANN_EKF_NMPC_2_DW.Delay100dt_DSTATE[loctmp_i] =
        ANN_EKF_NMPC_2_P.Delay100dt_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay 100 dt' */
  }
}

/* Model terminate function */
void ANN_EKF_NMPC_2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
