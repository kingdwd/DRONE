/*
 * File: NMPC_Controller.c
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
//#include "rt_zcfcn.c"

/* Named constants for MATLAB Function: '<Root>/Control System' */
#define NMPC_Controller_nz             (12.0)

/* Block signals (auto storage) */
B_NMPC_Controller_T NMPC_Controller_B;

/* Block states (auto storage) */
DW_NMPC_Controller_T NMPC_Controller_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_NMPC_Controller_T NMPC_Controller_PrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU_NMPC_Controller_T NMPC_Controller_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_NMPC_Controller_T NMPC_Controller_Y;

/* Real-time model */
RT_MODEL_NMPC_Controller_T NMPC_Controller_M_;
RT_MODEL_NMPC_Controller_T *const NMPC_Controller_M = &NMPC_Controller_M_;

/* Forward declaration for local functions */
static void NMPC_Controller_ann_norm_X(const real_T x_ann_un[7], const real_T
  minXin[7], const real_T maxXin[7], real_T minYin, real_T maxYin, real_T x_ann
  [7]);
static real_T NMPC_Controller_ann_denorm_Y(real_T y_ann, real_T minXout, real_T
  maxXout, real_T minYout, real_T maxYout);
static real_T NMPC_Controller_norm(const real_T x[2]);
static real_T NMPC_Controller_norm_l(const real_T x[3]);
static void NMPC_Controller_uas_augm_model(real_T sw, boolean_T home_cmd, real_T
  b_dt, real_T b_TR, uint8_T wpts_fp, uint8_T wpts_rp, real_T wpts_h[32], real_T
  wpts_n[32], real_T wpts_e[32], const real_T wpts_v[32], real_T n_op_k, real_T
  e_op_k, real_T h_op_k, real_T vn_op_k, real_T ve_op_k, real_T vh_op_k, real_T
  alphadot_k, real_T betadot_k, uint8_T wpt_index_k, real_T start_wpt_k[3],
  boolean_T pic_cic_k, uint8_T home_reset_k, real_T THL_k, real_T EL_k, real_T
  AIL_k, real_T RDR_k, real_T VT_k, real_T alpha_k, real_T beta_k, real_T phi_k,
  real_T theta_k, real_T psi_k, real_T P_k, real_T Q_k, real_T R_k, real_T n_k,
  real_T e_k, real_T h_k, real_T ro_k, real_T THLcmd_k, real_T ELcmd_k, real_T
  AILcmd_k, real_T RDRcmd_k, real_T xw11_k, real_T xw12_k, real_T xw13_k, real_T
  xw14_k, real_T xw21_k, real_T xw22_k, real_T xw23_k, real_T xw24_k, real_T
  xw31_k, real_T xw32_k, real_T xw33_k, real_T xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W11d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W12d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W14d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W21d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W23d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W24d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W32d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W33d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W34d, real_T b_rho, real_T b_S,
  real_T b_Cbar, real_T b_b, real_T b_weight, real_T b_g, real_T b_IxxB, real_T
  b_IyyB, real_T b_IzzB, real_T b_IxzB, real_T b_CDu, real_T b_CDq, real_T
  b_CDadot, real_T b_CDde, real_T b_CD0_bar, real_T b_Cyb, real_T b_Cyp, real_T
  b_Cyr, real_T b_Cyda, real_T b_Cydr, real_T b_CL0, real_T b_CLa, real_T b_CLq,
  real_T b_CLadot, real_T b_CLu, real_T b_CLde, real_T b_Clb, real_T b_Clp,
  real_T b_Clr, real_T b_Clda, real_T b_Cldr, real_T b_Cm0, real_T b_Cma, real_T
  b_Cmq, real_T b_Cmadot, real_T b_Cmu, real_T b_Cmde, real_T b_Cnb, real_T
  b_Cnp, real_T b_Cnr, real_T b_Cnda, real_T b_Cndr, real_T b_xT0, real_T b_xT1,
  real_T b_xT2, real_T b_Ptrim, real_T b_Qtrim, real_T b_Rtrim, real_T b_Utrim,
  real_T b_Athrottle, real_T b_Bthrottle, real_T b_Aelevator, real_T b_Belevator,
  real_T b_Aaileron, real_T b_Baileron, real_T b_Arudder, real_T b_Brudder,
  real_T b_ThrottleMax, real_T b_ThrottleMin, real_T b_ElevatorMax, real_T
  b_ElevatorMin, real_T b_AileronMax, real_T b_AileronMin, real_T b_RudderMax,
  real_T b_RudderMin, real_T b_KpLat, real_T b_KiLon, real_T b_KpLon, real_T b_L,
  real_T b_dist2b, real_T FL_ann, const real_T a_ann_X[40], const real_T
  b_ann_X[40], real_T c_ann_X, const real_T w_ann_X[280], const real_T a_ann_Y
  [40], const real_T b_ann_Y[40], real_T c_ann_Y, const real_T w_ann_Y[280],
  const real_T a_ann_Z[40], const real_T b_ann_Z[40], real_T c_ann_Z, const
  real_T w_ann_Z[280], const real_T b_X_minXin[7], const real_T b_X_maxXin[7],
  real_T b_X_minYin, real_T b_X_maxYin, real_T b_X_minXout, real_T b_X_maxXout,
  real_T b_X_minYout, real_T b_X_maxYout, const real_T b_Y_minXin[7], const
  real_T b_Y_maxXin[7], real_T b_Y_minYin, real_T b_Y_maxYin, real_T b_Y_minXout,
  real_T b_Y_maxXout, real_T b_Y_minYout, real_T b_Y_maxYout, const real_T
  b_Z_minXin[7], const real_T b_Z_maxXin[7], real_T b_Z_minYin, real_T
  b_Z_maxYin, real_T b_Z_minXout, real_T b_Z_maxXout, real_T b_Z_minYout, real_T
  b_Z_maxYout, real32_T *distance2b, uint8_T *wpt_index_kk, real_T *pic_cic_kk,
  uint8_T *home_reset_kk, real_T *nr_k, real_T *er_k, real_T *hr_k, real_T
  *etaLon_k, real_T *etaLat_k, real_T *VTcmd_k, real_T *thetacmd_k, real_T
  *phicmd_k, real_T *Vab_k, real_T *accelX_scd_k, real_T *accelX_ann_k, real_T
  *accelY_scd_k, real_T *accelY_ann_k, real_T *accelZ_scd_k, real_T
  *accelZ_ann_k, real_T z_augm_k[12], real_T e_augm_k[4], real_T *THL_kk, real_T
  *EL_kk, real_T *AIL_kk, real_T *RDR_kk, real_T *VT_kk, real_T *alpha_kk,
  real_T *beta_kk, real_T *phi_kk, real_T *theta_kk, real_T *psi_kk, real_T
  *P_kk, real_T *Q_kk, real_T *R_kk, real_T *falpha_k, real_T *fbeta_k, real_T
  *n_kk, real_T *e_kk, real_T *h_kk, real_T *ro_kk, real_T *xw11_kk, real_T
  *xw12_kk, real_T *xw13_kk, real_T *xw14_kk, real_T *xw21_kk, real_T *xw22_kk,
  real_T *xw23_kk, real_T *xw24_kk, real_T *xw31_kk, real_T *xw32_kk, real_T
  *xw33_kk, real_T *xw34_kk);
static void NMPC_Controller_eml_ipiv2perm(const int32_T ipiv[80], int32_T perm
  [80]);
static void NMPC_Controller_eml_xtrsm(const real_T A[6400], real_T B[6400]);
static void NMPC_Controller_eml_xswap(real_T x[6400], int32_T ix0, int32_T iy0);
static void NMPC_Controller_invNxN(const real_T x[6400], real_T y[6400]);
static void NMPC_Controller_mpower(const real_T a[6400], real_T c[6400]);
static real_T NMPC_Controller_sum(const boolean_T x[40]);
static real_T NMPC_Controller_sum_p(const boolean_T x[20]);
static void NMPC_Controller_eml_ipiv2perm_k(const int32_T ipiv_data[], const
  int32_T ipiv_sizes[2], int32_T m, int32_T perm_data[], int32_T perm_sizes[2]);
static void NMPC_Controller_eml_xtrsm_b(int32_T m, int32_T n, const real_T
  A_data[], int32_T lda, real_T B_data[], int32_T ldb);
static void NMPC_Controller_eml_xswap_d(int32_T n, real_T x_data[], int32_T ix0,
  int32_T incx, int32_T iy0, int32_T incy);
static void NMPC_Controller_invNxN_l(const real_T x_data[], const int32_T
  x_sizes[2], real_T y_data[], int32_T y_sizes[2]);
static void NMPC_Controller_mpower_h(const real_T a_data[], const int32_T
  a_sizes[2], real_T c_data[], int32_T c_sizes[2]);
static void NMPC_Controller_squeeze(const real_T a[12], real_T b_b[12]);
static void NMPC_Controller_uas_augm_model_bm(real_T sw, boolean_T home_cmd,
  real_T b_dt, real_T b_TR, uint8_T wpts_fp, uint8_T wpts_rp, real_T wpts_h[32],
  real_T wpts_n[32], real_T wpts_e[32], const real_T wpts_v[32], real_T n_op_k,
  real_T e_op_k, real_T h_op_k, real_T vn_op_k, real_T ve_op_k, real_T vh_op_k,
  real_T alphadot_k, real_T betadot_k, uint8_T wpt_index_k, real_T start_wpt_k[3],
  real_T pic_cic_k, real_T home_reset_k, real_T THL_k, real_T EL_k, real_T AIL_k,
  real_T RDR_k, real_T VT_k, real_T alpha_k, real_T beta_k, real_T phi_k, real_T
  theta_k, real_T psi_k, real_T P_k, real_T Q_k, real_T R_k, real_T n_k, real_T
  e_k, real_T h_k, real_T ro_k, real_T THLcmd_k, real_T ELcmd_k, real_T AILcmd_k,
  real_T RDRcmd_k, real_T xw11_k, real_T xw12_k, real_T xw13_k, real_T xw14_k,
  real_T xw21_k, real_T xw22_k, real_T xw23_k, real_T xw24_k, real_T xw31_k,
  real_T xw32_k, real_T xw33_k, real_T xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W11d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W12d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W14d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W21d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W23d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W24d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W32d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W33d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W34d, real_T b_rho, real_T b_S,
  real_T b_Cbar, real_T b_b, real_T b_weight, real_T b_g, real_T b_IxxB, real_T
  b_IyyB, real_T b_IzzB, real_T b_IxzB, real_T b_CDu, real_T b_CDq, real_T
  b_CDadot, real_T b_CDde, real_T b_CD0_bar, real_T b_Cyb, real_T b_Cyp, real_T
  b_Cyr, real_T b_Cyda, real_T b_Cydr, real_T b_CL0, real_T b_CLa, real_T b_CLq,
  real_T b_CLadot, real_T b_CLu, real_T b_CLde, real_T b_Clb, real_T b_Clp,
  real_T b_Clr, real_T b_Clda, real_T b_Cldr, real_T b_Cm0, real_T b_Cma, real_T
  b_Cmq, real_T b_Cmadot, real_T b_Cmu, real_T b_Cmde, real_T b_Cnb, real_T
  b_Cnp, real_T b_Cnr, real_T b_Cnda, real_T b_Cndr, real_T b_xT0, real_T b_xT1,
  real_T b_xT2, real_T b_Ptrim, real_T b_Qtrim, real_T b_Rtrim, real_T b_Utrim,
  real_T b_Athrottle, real_T b_Bthrottle, real_T b_Aelevator, real_T b_Belevator,
  real_T b_Aaileron, real_T b_Baileron, real_T b_Arudder, real_T b_Brudder,
  real_T b_ThrottleMax, real_T b_ThrottleMin, real_T b_ElevatorMax, real_T
  b_ElevatorMin, real_T b_AileronMax, real_T b_AileronMin, real_T b_RudderMax,
  real_T b_RudderMin, real_T b_KpLat, real_T b_KiLon, real_T b_KpLon, real_T b_L,
  real_T b_dist2b, real_T FL_ann, const real_T a_ann_X[40], const real_T
  b_ann_X[40], real_T c_ann_X, const real_T w_ann_X[280], const real_T a_ann_Y
  [40], const real_T b_ann_Y[40], real_T c_ann_Y, const real_T w_ann_Y[280],
  const real_T a_ann_Z[40], const real_T b_ann_Z[40], real_T c_ann_Z, const
  real_T w_ann_Z[280], const real_T b_X_minXin[7], const real_T b_X_maxXin[7],
  real_T b_X_minYin, real_T b_X_maxYin, real_T b_X_minXout, real_T b_X_maxXout,
  real_T b_X_minYout, real_T b_X_maxYout, const real_T b_Y_minXin[7], const
  real_T b_Y_maxXin[7], real_T b_Y_minYin, real_T b_Y_maxYin, real_T b_Y_minXout,
  real_T b_Y_maxXout, real_T b_Y_minYout, real_T b_Y_maxYout, const real_T
  b_Z_minXin[7], const real_T b_Z_maxXin[7], real_T b_Z_minYin, real_T
  b_Z_maxYin, real_T b_Z_minXout, real_T b_Z_maxXout, real_T b_Z_minYout, real_T
  b_Z_maxYout, real32_T *distance2b, uint8_T *wpt_index_kk, real_T *pic_cic_kk,
  uint8_T *home_reset_kk, real_T *nr_k, real_T *er_k, real_T *hr_k, real_T
  *etaLon_k, real_T *etaLat_k, real_T *VTcmd_k, real_T *thetacmd_k, real_T
  *phicmd_k, real_T *Vab_k, real_T *accelX_scd_k, real_T *accelX_ann_k, real_T
  *accelY_scd_k, real_T *accelY_ann_k, real_T *accelZ_scd_k, real_T
  *accelZ_ann_k, real_T z_augm_k[12], real_T e_augm_k[4], real_T *THL_kk, real_T
  *EL_kk, real_T *AIL_kk, real_T *RDR_kk, real_T *VT_kk, real_T *alpha_kk,
  real_T *beta_kk, real_T *phi_kk, real_T *theta_kk, real_T *psi_kk, real_T
  *P_kk, real_T *Q_kk, real_T *R_kk, real_T *falpha_k, real_T *fbeta_k, real_T
  *n_kk, real_T *e_kk, real_T *h_kk, real_T *ro_kk, real_T *xw11_kk, real_T
  *xw12_kk, real_T *xw13_kk, real_T *xw14_kk, real_T *xw21_kk, real_T *xw22_kk,
  real_T *xw23_kk, real_T *xw24_kk, real_T *xw31_kk, real_T *xw32_kk, real_T
  *xw33_kk, real_T *xw34_kk);
static void NMPC_Controller_nmpc_iteration(real_T sw, boolean_T home_cmd, real_T
  b_dt, real_T b_TR, uint8_T wpts_fp, uint8_T wpts_rp, const real_T wpts_h[32],
  const real_T wpts_n[32], const real_T wpts_e[32], const real_T wpts_v[32],
  const real_T n_op_N[21], const real_T e_op_N[21], const real_T h_op_N[21],
  const real_T vn_op_N[21], const real_T ve_op_N[21], const real_T vh_op_N[21],
  const real_T u_hor[84], const real_T z_hor[252], const real_T n_hor[21], const
  real_T e_hor[21], const real_T h_hor[21], const real_T THL_hor[21], const
  real_T EL_hor[21], const real_T AIL_hor[21], const real_T RDR_hor[21], const
  real_T VT_hor[21], const real_T alpha_hor[21], const real_T beta_hor[21],
  const real_T phi_hor[21], const real_T theta_hor[21], const real_T psi_hor[21],
  const real_T P_hor[21], const real_T Q_hor[21], const real_T R_hor[21], const
  real_T wpt_index_hor[21], const real_T start_wpt_hor[63], const real_T
  pic_cic_hor[21], const real_T home_reset_hor[21], const real_T alphadot_hor[21],
  const real_T betadot_hor[21], const real_T ro_hor[21], const real_T xw11_hor
  [21], const real_T xw12_hor[21], const real_T xw13_hor[21], const real_T
  xw14_hor[21], const real_T xw21_hor[21], const real_T xw22_hor[21], const
  real_T xw23_hor[21], const real_T xw24_hor[21], const real_T xw31_hor[21],
  const real_T xw32_hor[21], const real_T xw33_hor[21], const real_T xw34_hor[21],
  const struct_4Fd1bnpyLecBuwBUBUAQfC b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W12d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W13d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W21d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W22d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W24d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W31d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W33d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W34d, real_T b_rho, real_T b_S, real_T b_Cbar, real_T b_b, real_T b_weight,
  real_T b_g, real_T b_IxxB, real_T b_IyyB, real_T b_IzzB, real_T b_IxzB, real_T
  b_CDu, real_T b_CDq, real_T b_CDadot, real_T b_CDde, real_T b_CD0_bar, real_T
  b_Cyb, real_T b_Cyp, real_T b_Cyr, real_T b_Cyda, real_T b_Cydr, real_T b_CL0,
  real_T b_CLa, real_T b_CLq, real_T b_CLadot, real_T b_CLu, real_T b_CLde,
  real_T b_Clb, real_T b_Clp, real_T b_Clr, real_T b_Clda, real_T b_Cldr, real_T
  b_Cm0, real_T b_Cma, real_T b_Cmq, real_T b_Cmadot, real_T b_Cmu, real_T
  b_Cmde, real_T b_Cnb, real_T b_Cnp, real_T b_Cnr, real_T b_Cnda, real_T b_Cndr,
  real_T b_xT0, real_T b_xT1, real_T b_xT2, real_T b_Ptrim, real_T b_Qtrim,
  real_T b_Rtrim, real_T b_Utrim, real_T b_Athrottle, real_T b_Bthrottle, real_T
  b_Aelevator, real_T b_Belevator, real_T b_Aaileron, real_T b_Baileron, real_T
  b_Arudder, real_T b_Brudder, real_T b_ThrottleMax, real_T b_ThrottleMin,
  real_T b_ElevatorMax, real_T b_ElevatorMin, real_T b_AileronMax, real_T
  b_AileronMin, real_T b_RudderMax, real_T b_RudderMin, real_T b_KpLat, real_T
  b_KiLon, real_T b_KpLon, real_T b_L, real_T b_dist2b, real_T FL_ann, const
  real_T a_ann_X[40], const real_T b_ann_X[40], real_T c_ann_X, const real_T
  w_ann_X[280], const real_T a_ann_Y[40], const real_T b_ann_Y[40], real_T
  c_ann_Y, const real_T w_ann_Y[280], const real_T a_ann_Z[40], const real_T
  b_ann_Z[40], real_T c_ann_Z, const real_T w_ann_Z[280], const real_T
  b_X_minXin[7], const real_T b_X_maxXin[7], real_T b_X_minYin, real_T
  b_X_maxYin, real_T b_X_minXout, real_T b_X_maxXout, real_T b_X_minYout, real_T
  b_X_maxYout, const real_T b_Y_minXin[7], const real_T b_Y_maxXin[7], real_T
  b_Y_minYin, real_T b_Y_maxYin, real_T b_Y_minXout, real_T b_Y_maxXout, real_T
  b_Y_minYout, real_T b_Y_maxYout, const real_T b_Z_minXin[7], const real_T
  b_Z_maxXin[7], real_T b_Z_minYin, real_T b_Z_maxYin, real_T b_Z_minXout,
  real_T b_Z_maxXout, real_T b_Z_minYout, real_T b_Z_maxYout, real_T u_nmpc[84],
  real_T *V_nmpc);
static void NMPC_Controller_uas_augm_model_b(real_T sw, boolean_T home_cmd,
  real_T b_dt, real_T b_TR, uint8_T wpts_fp, uint8_T wpts_rp, real_T wpts_h[32],
  real_T wpts_n[32], real_T wpts_e[32], const real_T wpts_v[32], real_T n_op_k,
  real_T e_op_k, real_T h_op_k, real_T vn_op_k, real_T ve_op_k, real_T vh_op_k,
  real_T alphadot_k, real_T betadot_k, real_T wpt_index_k, real_T start_wpt_k[3],
  real_T pic_cic_k, real_T home_reset_k, real_T THL_k, real_T EL_k, real_T AIL_k,
  real_T RDR_k, real_T VT_k, real_T alpha_k, real_T beta_k, real_T phi_k, real_T
  theta_k, real_T psi_k, real_T P_k, real_T Q_k, real_T R_k, real_T n_k, real_T
  e_k, real_T h_k, real_T ro_k, real_T THLcmd_k, real_T ELcmd_k, real_T AILcmd_k,
  real_T RDRcmd_k, real_T xw11_k, real_T xw12_k, real_T xw13_k, real_T xw14_k,
  real_T xw21_k, real_T xw22_k, real_T xw23_k, real_T xw24_k, real_T xw31_k,
  real_T xw32_k, real_T xw33_k, real_T xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W11d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W12d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W14d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W21d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W23d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W24d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W32d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W33d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W34d, real_T b_rho, real_T b_S,
  real_T b_Cbar, real_T b_b, real_T b_weight, real_T b_g, real_T b_IxxB, real_T
  b_IyyB, real_T b_IzzB, real_T b_IxzB, real_T b_CDu, real_T b_CDq, real_T
  b_CDadot, real_T b_CDde, real_T b_CD0_bar, real_T b_Cyb, real_T b_Cyp, real_T
  b_Cyr, real_T b_Cyda, real_T b_Cydr, real_T b_CL0, real_T b_CLa, real_T b_CLq,
  real_T b_CLadot, real_T b_CLu, real_T b_CLde, real_T b_Clb, real_T b_Clp,
  real_T b_Clr, real_T b_Clda, real_T b_Cldr, real_T b_Cm0, real_T b_Cma, real_T
  b_Cmq, real_T b_Cmadot, real_T b_Cmu, real_T b_Cmde, real_T b_Cnb, real_T
  b_Cnp, real_T b_Cnr, real_T b_Cnda, real_T b_Cndr, real_T b_xT0, real_T b_xT1,
  real_T b_xT2, real_T b_Ptrim, real_T b_Qtrim, real_T b_Rtrim, real_T b_Utrim,
  real_T b_Athrottle, real_T b_Bthrottle, real_T b_Aelevator, real_T b_Belevator,
  real_T b_Aaileron, real_T b_Baileron, real_T b_Arudder, real_T b_Brudder,
  real_T b_ThrottleMax, real_T b_ThrottleMin, real_T b_ElevatorMax, real_T
  b_ElevatorMin, real_T b_AileronMax, real_T b_AileronMin, real_T b_RudderMax,
  real_T b_RudderMin, real_T b_KpLat, real_T b_KiLon, real_T b_KpLon, real_T b_L,
  real_T b_dist2b, real_T FL_ann, const real_T a_ann_X[40], const real_T
  b_ann_X[40], real_T c_ann_X, const real_T w_ann_X[280], const real_T a_ann_Y
  [40], const real_T b_ann_Y[40], real_T c_ann_Y, const real_T w_ann_Y[280],
  const real_T a_ann_Z[40], const real_T b_ann_Z[40], real_T c_ann_Z, const
  real_T w_ann_Z[280], const real_T b_X_minXin[7], const real_T b_X_maxXin[7],
  real_T b_X_minYin, real_T b_X_maxYin, real_T b_X_minXout, real_T b_X_maxXout,
  real_T b_X_minYout, real_T b_X_maxYout, const real_T b_Y_minXin[7], const
  real_T b_Y_maxXin[7], real_T b_Y_minYin, real_T b_Y_maxYin, real_T b_Y_minXout,
  real_T b_Y_maxXout, real_T b_Y_minYout, real_T b_Y_maxYout, const real_T
  b_Z_minXin[7], const real_T b_Z_maxXin[7], real_T b_Z_minYin, real_T
  b_Z_maxYin, real_T b_Z_minXout, real_T b_Z_maxXout, real_T b_Z_minYout, real_T
  b_Z_maxYout, real32_T *distance2b, uint8_T *wpt_index_kk, real_T *pic_cic_kk,
  uint8_T *home_reset_kk, real_T *nr_k, real_T *er_k, real_T *hr_k, real_T
  *etaLon_k, real_T *etaLat_k, real_T *VTcmd_k, real_T *thetacmd_k, real_T
  *phicmd_k, real_T *Vab_k, real_T *accelX_scd_k, real_T *accelX_ann_k, real_T
  *accelY_scd_k, real_T *accelY_ann_k, real_T *accelZ_scd_k, real_T
  *accelZ_ann_k, real_T z_augm_k[12], real_T e_augm_k[4], real_T *THL_kk, real_T
  *EL_kk, real_T *AIL_kk, real_T *RDR_kk, real_T *VT_kk, real_T *alpha_kk,
  real_T *beta_kk, real_T *phi_kk, real_T *theta_kk, real_T *psi_kk, real_T
  *P_kk, real_T *Q_kk, real_T *R_kk, real_T *falpha_k, real_T *fbeta_k, real_T
  *n_kk, real_T *e_kk, real_T *h_kk, real_T *ro_kk, real_T *xw11_kk, real_T
  *xw12_kk, real_T *xw13_kk, real_T *xw14_kk, real_T *xw21_kk, real_T *xw22_kk,
  real_T *xw23_kk, real_T *xw24_kk, real_T *xw31_kk, real_T *xw32_kk, real_T
  *xw33_kk, real_T *xw34_kk);

/*
 * Output and update for atomic system:
 *    '<S12>/Subsystem1'
 *    '<S13>/Subsystem2'
 *    '<S13>/Subsystem3'
 */
void NMPC_Controller_Subsystem1(real_T rtu_u, real_T rtu_u_o,
  B_Subsystem1_NMPC_Controller_T *localB)
{
  /* Sqrt: '<S21>/Sqrt' incorporates:
   *  Math: '<S21>/Math Function2'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtMath Function2Inport1'
   *  Sum: '<S21>/Sum of Elements'
   */
  localB->Sqrt = sqrt(rtu_u * rtu_u + rtu_u_o * rtu_u_o);
}

/* Output and update for atomic system: '<S12>/Subsystem4' */
void NMPC_Controller_Subsystem4(real_T rtu_u, real_T rtu_u_e,
  B_Subsystem4_NMPC_Controller_T *localB)
{
  /* Sum: '<S22>/Sum of Elements' incorporates:
   *  Math: '<S22>/Math Function2'
   *  SignalConversion: '<S22>/TmpSignal ConversionAtMath Function2Inport1'
   */
  localB->SumofElements = rtu_u * rtu_u + rtu_u_e * rtu_u_e;
}

/*
 * Output and update for atomic system:
 *    '<S13>/Subsystem1'
 *    '<S14>/Subsystem1'
 *    '<S30>/Subsystem1'
 */
void NMPC_Controller_Subsystem1_j(real_T rtu_u, real_T rtu_u_d, real_T rtu_u_f,
  B_Subsystem1_NMPC_Controller_l_T *localB)
{
  /* Sqrt: '<S23>/Sqrt' incorporates:
   *  Math: '<S23>/Math Function2'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtMath Function2Inport1'
   *  Sum: '<S23>/Sum of Elements'
   */
  localB->Sqrt = sqrt((rtu_u * rtu_u + rtu_u_d * rtu_u_d) + rtu_u_f * rtu_u_f);
}

/* Output and update for atomic system: '<S13>/Subsystem4' */
void NMPC_Controller_Subsystem4_g(real_T rtu_u, real_T rtu_u_k, real_T rtu_u_j,
  B_Subsystem4_NMPC_Controller_l_T *localB)
{
  /* Sum: '<S26>/Sum of Elements' incorporates:
   *  Math: '<S26>/Math Function2'
   *  SignalConversion: '<S26>/TmpSignal ConversionAtMath Function2Inport1'
   */
  localB->SumofElements = (rtu_u * rtu_u + rtu_u_k * rtu_u_k) + rtu_u_j *
    rtu_u_j;
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

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_ann_norm_X(const real_T x_ann_un[7], const real_T
  minXin[7], const real_T maxXin[7], real_T minYin, real_T maxYin, real_T x_ann
  [7])
{
  int32_T i;

  /* %%x_ann_un dimension is [number of inputs,ann_samples] */
  /* %number of samples */
  /* %allocation */
  for (i = 0; i < 7; i++) {
    x_ann[i] = (x_ann_un[i] - minXin[i]) * (maxYin - minYin) / (maxXin[i] -
      minXin[i]) + minYin;
  }
}

/* Function for MATLAB Function: '<Root>/Control System' */
static real_T NMPC_Controller_ann_denorm_Y(real_T y_ann, real_T minXout, real_T
  maxXout, real_T minYout, real_T maxYout)
{
  /* %%y_ann_un dimension is [ann_samples,number of inputs] */
  /* %number of samples */
  /* %allocation */
  return (y_ann - minYout) * (maxXout - minXout) / (maxYout - minYout) + minXout;
}

/* Function for MATLAB Function: '<Root>/Control System' */
static real_T NMPC_Controller_norm(const real_T x[2])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<Root>/Control System' */
static real_T NMPC_Controller_norm_l(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_uas_augm_model(real_T sw, boolean_T home_cmd, real_T
  b_dt, real_T b_TR, uint8_T wpts_fp, uint8_T wpts_rp, real_T wpts_h[32], real_T
  wpts_n[32], real_T wpts_e[32], const real_T wpts_v[32], real_T n_op_k, real_T
  e_op_k, real_T h_op_k, real_T vn_op_k, real_T ve_op_k, real_T vh_op_k, real_T
  alphadot_k, real_T betadot_k, uint8_T wpt_index_k, real_T start_wpt_k[3],
  boolean_T pic_cic_k, uint8_T home_reset_k, real_T THL_k, real_T EL_k, real_T
  AIL_k, real_T RDR_k, real_T VT_k, real_T alpha_k, real_T beta_k, real_T phi_k,
  real_T theta_k, real_T psi_k, real_T P_k, real_T Q_k, real_T R_k, real_T n_k,
  real_T e_k, real_T h_k, real_T ro_k, real_T THLcmd_k, real_T ELcmd_k, real_T
  AILcmd_k, real_T RDRcmd_k, real_T xw11_k, real_T xw12_k, real_T xw13_k, real_T
  xw14_k, real_T xw21_k, real_T xw22_k, real_T xw23_k, real_T xw24_k, real_T
  xw31_k, real_T xw32_k, real_T xw33_k, real_T xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W11d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W12d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W14d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W21d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W23d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W24d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W32d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W33d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W34d, real_T b_rho, real_T b_S,
  real_T b_Cbar, real_T b_b, real_T b_weight, real_T b_g, real_T b_IxxB, real_T
  b_IyyB, real_T b_IzzB, real_T b_IxzB, real_T b_CDu, real_T b_CDq, real_T
  b_CDadot, real_T b_CDde, real_T b_CD0_bar, real_T b_Cyb, real_T b_Cyp, real_T
  b_Cyr, real_T b_Cyda, real_T b_Cydr, real_T b_CL0, real_T b_CLa, real_T b_CLq,
  real_T b_CLadot, real_T b_CLu, real_T b_CLde, real_T b_Clb, real_T b_Clp,
  real_T b_Clr, real_T b_Clda, real_T b_Cldr, real_T b_Cm0, real_T b_Cma, real_T
  b_Cmq, real_T b_Cmadot, real_T b_Cmu, real_T b_Cmde, real_T b_Cnb, real_T
  b_Cnp, real_T b_Cnr, real_T b_Cnda, real_T b_Cndr, real_T b_xT0, real_T b_xT1,
  real_T b_xT2, real_T b_Ptrim, real_T b_Qtrim, real_T b_Rtrim, real_T b_Utrim,
  real_T b_Athrottle, real_T b_Bthrottle, real_T b_Aelevator, real_T b_Belevator,
  real_T b_Aaileron, real_T b_Baileron, real_T b_Arudder, real_T b_Brudder,
  real_T b_ThrottleMax, real_T b_ThrottleMin, real_T b_ElevatorMax, real_T
  b_ElevatorMin, real_T b_AileronMax, real_T b_AileronMin, real_T b_RudderMax,
  real_T b_RudderMin, real_T b_KpLat, real_T b_KiLon, real_T b_KpLon, real_T b_L,
  real_T b_dist2b, real_T FL_ann, const real_T a_ann_X[40], const real_T
  b_ann_X[40], real_T c_ann_X, const real_T w_ann_X[280], const real_T a_ann_Y
  [40], const real_T b_ann_Y[40], real_T c_ann_Y, const real_T w_ann_Y[280],
  const real_T a_ann_Z[40], const real_T b_ann_Z[40], real_T c_ann_Z, const
  real_T w_ann_Z[280], const real_T b_X_minXin[7], const real_T b_X_maxXin[7],
  real_T b_X_minYin, real_T b_X_maxYin, real_T b_X_minXout, real_T b_X_maxXout,
  real_T b_X_minYout, real_T b_X_maxYout, const real_T b_Y_minXin[7], const
  real_T b_Y_maxXin[7], real_T b_Y_minYin, real_T b_Y_maxYin, real_T b_Y_minXout,
  real_T b_Y_maxXout, real_T b_Y_minYout, real_T b_Y_maxYout, const real_T
  b_Z_minXin[7], const real_T b_Z_maxXin[7], real_T b_Z_minYin, real_T
  b_Z_maxYin, real_T b_Z_minXout, real_T b_Z_maxXout, real_T b_Z_minYout, real_T
  b_Z_maxYout, real32_T *distance2b, uint8_T *wpt_index_kk, real_T *pic_cic_kk,
  uint8_T *home_reset_kk, real_T *nr_k, real_T *er_k, real_T *hr_k, real_T
  *etaLon_k, real_T *etaLat_k, real_T *VTcmd_k, real_T *thetacmd_k, real_T
  *phicmd_k, real_T *Vab_k, real_T *accelX_scd_k, real_T *accelX_ann_k, real_T
  *accelY_scd_k, real_T *accelY_ann_k, real_T *accelZ_scd_k, real_T
  *accelZ_ann_k, real_T z_augm_k[12], real_T e_augm_k[4], real_T *THL_kk, real_T
  *EL_kk, real_T *AIL_kk, real_T *RDR_kk, real_T *VT_kk, real_T *alpha_kk,
  real_T *beta_kk, real_T *phi_kk, real_T *theta_kk, real_T *psi_kk, real_T
  *P_kk, real_T *Q_kk, real_T *R_kk, real_T *falpha_k, real_T *fbeta_k, real_T
  *n_kk, real_T *e_kk, real_T *h_kk, real_T *ro_kk, real_T *xw11_kk, real_T
  *xw12_kk, real_T *xw13_kk, real_T *xw14_kk, real_T *xw21_kk, real_T *xw22_kk,
  real_T *xw23_kk, real_T *xw24_kk, real_T *xw31_kk, real_T *xw32_kk, real_T
  *xw33_kk, real_T *xw34_kk)
{
  real_T mass;
  real_T delta_I;
  real_T c2;
  real_T c4;
  real_T Qbar_k;
  real_T U_k;
  real_T V_k;
  real_T W_k;
  real_T CL_k;
  real_T CD_k;
  real_T Cls_k;
  real_T Cms_k;
  real_T Cns_k;
  real_T Cl_k;
  real_T Cn_k;
  real_T Udot_k;
  real_T Vdot_k;
  real_T Wdot_k;
  real_T fn_k;
  real_T fe_k;
  real_T fh_k;
  uint8_T next_wpt_index;
  real_T ea;
  real_T hd_k;
  real_T nd_k;
  real_T ed_k;
  real_T atrack;
  int32_T factor;
  real_T btrack;
  real_T edot_track_k;
  real_T ndot_track_k;
  real_T r_a;
  real_T s_a;
  real_T t_a;
  real_T er_k_0[2];
  real_T er_k_1[3];
  real_T nr_k_0[2];
  real_T fn_k_0[2];
  real_T VT_k_0[7];
  real_T VT_k_1[7];
  real_T VT_k_2[7];
  real_T tmp[7];
  real_T w_ann_X_0[40];
  int32_T i;

  /* %temporary */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %mass and inertia coefficients%% */
  mass = b_weight / b_g;
  delta_I = b_IxxB * b_IzzB - b_IxzB * b_IxzB;
  c2 = ((b_IxxB - b_IyyB) + b_IzzB) * b_IxzB / delta_I;
  c4 = b_IxzB / delta_I;

  /* %dynamic pressure%% */
  Qbar_k = 0.5 * b_rho * (VT_k * VT_k);

  /* %body velocities%% */
  U_k = VT_k * cos(alpha_k) * cos(beta_k);
  V_k = VT_k * sin(beta_k);
  W_k = VT_k * sin(alpha_k) * cos(beta_k);

  /* %aerodynamic coefficients%% */
  CL_k = ((((Q_k - b_Qtrim) * b_CLq * b_Cbar / 2.0 / b_Utrim + (b_CLa * alpha_k
             + b_CL0)) + b_CLadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k
           - b_Utrim) * b_CLu / b_Utrim) + b_CLde * EL_k;

  /* CD_k=CD0+CDa*alpha_k+CDq*(Q_k-Qtrim)*Cbar/2/Utrim+CDadot*alphadot_k*Cbar/2/Utrim+CDu*(U_k-Utrim)/Utrim+CDde*EL_k; %lin */
  CD_k = ((((CL_k * CL_k / (3.1415926535897931 * b_b / b_Cbar * 0.87) +
             b_CD0_bar) + (Q_k - b_Qtrim) * b_CDq * b_Cbar / 2.0 / b_Utrim) +
           b_CDadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k - b_Utrim) *
          b_CDu / b_Utrim) + b_CDde * EL_k;

  /* nonlin */
  Cls_k = ((((P_k - b_Ptrim) * b_Clp * b_b / 2.0 / b_Utrim + b_Clb * beta_k) +
            (R_k - b_Rtrim) * b_Clr * b_b / 2.0 / b_Utrim) + b_Clda * AIL_k) +
    b_Cldr * RDR_k;
  Cms_k = ((((Q_k - b_Qtrim) * b_Cmq * b_Cbar / 2.0 / b_Utrim + (b_Cma * alpha_k
              + b_Cm0)) + b_Cmadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k
            - b_Utrim) * b_Cmu / b_Utrim) + b_Cmde * EL_k;
  Cns_k = ((((P_k - b_Ptrim) * b_Cnp * b_b / 2.0 / b_Utrim + b_Cnb * beta_k) +
            (R_k - b_Rtrim) * b_Cnr * b_b / 2.0 / b_Utrim) + b_Cnda * AIL_k) +
    b_Cndr * RDR_k;
  Cl_k = Cls_k * cos(alpha_k) - Cns_k * sin(alpha_k);
  Cn_k = Cls_k * sin(alpha_k) + Cns_k * cos(alpha_k);

  /* %engine thrust%% */
  Cls_k = 100.0 * THL_k;

  /* %S&C aerodynamic and thrust linear accelerations%% */
  *accelX_scd_k = (((Cls_k * Cls_k * b_xT2 + 100.0 * THL_k * b_xT1) + b_xT0) + (
    -CD_k * cos(alpha_k) + CL_k * sin(alpha_k)) * (Qbar_k * b_S)) / mass;

  /* [ft/s2] */
  *accelY_scd_k = (((((P_k - b_Ptrim) * b_Cyp * b_b / 2.0 / b_Utrim + b_Cyb *
                      beta_k) + (R_k - b_Rtrim) * b_Cyr * b_b / 2.0 / b_Utrim) +
                    b_Cyda * AIL_k) + b_Cydr * RDR_k) * (Qbar_k * b_S) / mass;

  /* [ft/s2] */
  *accelZ_scd_k = (-CD_k * sin(alpha_k) - CL_k * cos(alpha_k)) * (Qbar_k * b_S) /
    mass;

  /* [ft/s2] */
  /* ANN linear accelerations */
  /* X-axis */
  VT_k_2[0] = VT_k;
  VT_k_2[1] = alpha_k;
  VT_k_2[2] = beta_k;
  VT_k_2[3] = Q_k;
  VT_k_2[4] = alphadot_k;
  VT_k_2[5] = THL_k;
  VT_k_2[6] = EL_k;
  NMPC_Controller_ann_norm_X(VT_k_2, b_X_minXin, b_X_maxXin, b_X_minYin,
    b_X_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_X[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_X[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_X[factor] * w_ann_X_0[factor];
  }

  *accelX_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_X, b_X_minXout,
    b_X_maxXout, b_X_minYout, b_X_maxYout) * b_g;

  /* [ft/s2] no tansig */
  /* Y_axis */
  VT_k_1[0] = VT_k;
  VT_k_1[1] = beta_k;
  VT_k_1[2] = P_k;
  VT_k_1[3] = R_k;
  VT_k_1[4] = betadot_k;
  VT_k_1[5] = AIL_k;
  VT_k_1[6] = RDR_k;
  NMPC_Controller_ann_norm_X(VT_k_1, b_Y_minXin, b_Y_maxXin, b_Y_minYin,
    b_Y_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_Y[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_Y[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_Y[factor] * w_ann_X_0[factor];
  }

  *accelY_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_Y, b_Y_minXout,
    b_Y_maxXout, b_Y_minYout, b_Y_maxYout) * b_g;

  /* [ft/s2] no tansig */
  /* Z-axis */
  VT_k_0[0] = VT_k;
  VT_k_0[1] = alpha_k;
  VT_k_0[2] = beta_k;
  VT_k_0[3] = Q_k;
  VT_k_0[4] = alphadot_k;
  VT_k_0[5] = THL_k;
  VT_k_0[6] = EL_k;
  NMPC_Controller_ann_norm_X(VT_k_0, b_Z_minXin, b_Z_maxXin, b_Z_minYin,
    b_Z_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_Z[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_Z[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_Z[factor] * w_ann_X_0[factor];
  }

  *accelZ_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_Z, b_Z_minXout,
    b_Z_maxXout, b_Z_minYout, b_Z_maxYout) * b_g;

  /* [ft/s2] no tansig */
  Cls_k = 0.0;

  /* initialization */
  Cns_k = 0.0;

  /* initialization */
  mass = 0.0;

  /* initialization */
  if (FL_ann == 0.0) {
    /* scd */
    Cls_k = *accelX_scd_k;
    Cns_k = *accelY_scd_k;
    mass = *accelZ_scd_k;
  } else {
    if (FL_ann == 1.0) {
      /* ann */
      Cls_k = *accelX_ann_k;
      Cns_k = *accelY_ann_k;
      mass = *accelZ_ann_k;
    }
  }

  /* body accelerations */
  Udot_k = ((R_k * V_k - Q_k * W_k) - b_g * sin(theta_k)) + Cls_k;
  Vdot_k = ((P_k * W_k - R_k * U_k) + b_g * sin(phi_k) * cos(theta_k)) + Cns_k;
  Wdot_k = ((Q_k * U_k - P_k * V_k) + b_g * cos(phi_k) * cos(theta_k)) + mass;

  /* %inertial speed (with no wind)%% */
  fn_k = ((sin(phi_k) * sin(theta_k) * cos(psi_k) - cos(phi_k) * sin(psi_k)) *
          V_k + U_k * cos(theta_k) * cos(psi_k)) + (cos(phi_k) * sin(theta_k) *
    cos(psi_k) + sin(phi_k) * sin(psi_k)) * W_k;
  fe_k = ((sin(phi_k) * sin(theta_k) * sin(psi_k) + cos(phi_k) * cos(psi_k)) *
          V_k + U_k * cos(theta_k) * sin(psi_k)) + (cos(phi_k) * sin(theta_k) *
    sin(psi_k) - sin(phi_k) * cos(psi_k)) * W_k;
  fh_k = (U_k * sin(theta_k) - V_k * sin(phi_k) * cos(theta_k)) - W_k * cos
    (phi_k) * cos(theta_k);

  /* %inertial speed%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Local variable assignment */
  *wpt_index_kk = wpt_index_k;
  *home_reset_kk = home_reset_k;

  /* PIC/CIC Transition Logic: */
  /*  On transition to CIC or PIC, set index = 0 and current position to  */
  /*  current waypoint; hold current waypoint. */
  if ((sw > (real_T)pic_cic_k) || (sw == 0.0)) {
    start_wpt_k[0] = h_k;
    start_wpt_k[1] = n_k;
    start_wpt_k[2] = e_k;
    *wpt_index_kk = 0U;
    *home_reset_kk = 0U;
  }

  /*  Change the waypoint index when home command */
  if ((home_cmd == 1) && (sw == 1.0) && (*home_reset_kk == 0)) {
    *wpt_index_kk = 23U;
    *home_reset_kk = 1U;
  }

  /* OP trajectory generation */
  /* %reassigning the a and b waypoints */
  if ((b_TR == 2.0) && (*home_reset_kk == 0)) {
    *wpt_index_kk = 1U;
    wpts_n[wpt_index_k - 1] = n_op_k - 100.0 * vn_op_k;
    factor = (int32_T)(wpt_index_k + 1U);
    if ((uint32_T)factor > 255U) {
      factor = 255;
    }

    wpts_n[factor - 1] = 100.0 * vn_op_k + n_op_k;
    wpts_e[wpt_index_k - 1] = e_op_k - 100.0 * ve_op_k;
    factor = (int32_T)(wpt_index_k + 1U);
    if ((uint32_T)factor > 255U) {
      factor = 255;
    }

    wpts_e[factor - 1] = 100.0 * ve_op_k + e_op_k;
    wpts_h[wpt_index_k - 1] = h_op_k - 100.0 * vh_op_k;
    factor = (int32_T)(wpt_index_k + 1U);
    if ((uint32_T)factor > 255U) {
      factor = 255;
    }

    wpts_h[factor - 1] = 100.0 * vh_op_k + h_op_k;
  }

  /* calculate the next waypoint index */
  factor = (int32_T)(*wpt_index_kk + 1U);
  if ((uint32_T)factor > 255U) {
    factor = 255;
  }

  next_wpt_index = (uint8_T)factor;

  /* beyond final point (fp), go to return point (rp) */
  if ((uint8_T)factor > wpts_fp) {
    next_wpt_index = wpts_rp;
  }

  /* calculate distance to next waypoint */
  Cls_k = n_k - wpts_n[next_wpt_index - 1];
  Cns_k = e_k - wpts_e[next_wpt_index - 1];
  Cls_k = sqrt(Cls_k * Cls_k + Cns_k * Cns_k);

  /* change to next waypoint if in range */
  if ((Cls_k < b_dist2b) && (sw == 1.0)) {
    /*  Do not change index if sw=0 */
    *wpt_index_kk = next_wpt_index;
    if (next_wpt_index == wpts_fp) {
      next_wpt_index = wpts_rp;
    } else {
      factor = (int32_T)(next_wpt_index + 1U);
      if ((uint32_T)factor > 255U) {
        factor = 255;
      }

      next_wpt_index = (uint8_T)factor;
    }
  }

  /* function outputs */
  if ((*wpt_index_kk == 0) || (*wpt_index_kk == 23)) {
    /*  Assign the speed of the starting segment to the speed of the first */
    /*  waypoint */
    *Vab_k = wpts_v[0];
    CL_k = start_wpt_k[0];
    CD_k = start_wpt_k[1];
    ea = start_wpt_k[2];
  } else {
    *Vab_k = wpts_v[*wpt_index_kk - 1];
    CL_k = wpts_h[*wpt_index_kk - 1];
    CD_k = wpts_n[*wpt_index_kk - 1];
    ea = wpts_e[*wpt_index_kk - 1];
  }

  *distance2b = (real32_T)Cls_k;
  *pic_cic_kk = sw;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %reference point r%% */
  Cls_k = wpts_h[next_wpt_index - 1] - CL_k;
  Cns_k = wpts_n[next_wpt_index - 1] - CD_k;
  mass = wpts_e[next_wpt_index - 1] - ea;
  Cls_k = (((wpts_h[next_wpt_index - 1] - CL_k) * (h_k - CL_k) +
            (wpts_n[next_wpt_index - 1] - CD_k) * (n_k - CD_k)) +
           (wpts_e[next_wpt_index - 1] - ea) * (e_k - ea)) / ((Cls_k * Cls_k +
    Cns_k * Cns_k) + mass * mass);
  hd_k = (wpts_h[next_wpt_index - 1] - CL_k) * Cls_k + CL_k;
  nd_k = (wpts_n[next_wpt_index - 1] - CD_k) * Cls_k + CD_k;
  ed_k = (wpts_e[next_wpt_index - 1] - ea) * Cls_k + ea;
  Cls_k = wpts_h[next_wpt_index - 1] - hd_k;
  Cns_k = wpts_n[next_wpt_index - 1] - nd_k;
  mass = wpts_e[next_wpt_index - 1] - ed_k;
  Cls_k = b_L / sqrt((Cls_k * Cls_k + Cns_k * Cns_k) + mass * mass);
  *er_k = (wpts_e[next_wpt_index - 1] - ed_k) * Cls_k + ed_k;
  *nr_k = (wpts_n[next_wpt_index - 1] - nd_k) * Cls_k + nd_k;
  *hr_k = (wpts_h[next_wpt_index - 1] - hd_k) * Cls_k + hd_k;

  /* %alpha and beta track%% */
  Cls_k = wpts_h[next_wpt_index - 1] - CL_k;
  Cns_k = wpts_n[next_wpt_index - 1] - CD_k;
  mass = wpts_e[next_wpt_index - 1] - ea;
  atrack = asin((wpts_h[next_wpt_index - 1] - CL_k) / sqrt((Cls_k * Cls_k +
    Cns_k * Cns_k) + mass * mass));
  Cls_k = wpts_n[next_wpt_index - 1] - CD_k;
  Cns_k = wpts_e[next_wpt_index - 1] - ea;
  factor = 1;
  mass = 0.0;
  if (!((wpts_n[next_wpt_index - 1] - CD_k > 0.0) && (wpts_e[next_wpt_index - 1]
        - ea > 0.0))) {
    if ((wpts_n[next_wpt_index - 1] - CD_k > 0.0) && (wpts_e[next_wpt_index - 1]
         - ea < 0.0)) {
      mass = 3.1415926535897931;
      factor = -1;
    } else {
      if ((wpts_n[next_wpt_index - 1] - CD_k < 0.0) && (wpts_e[next_wpt_index -
           1] - ea < 0.0)) {
        mass = -3.1415926535897931;
        factor = -1;
      }
    }
  }

  btrack = asin((wpts_n[next_wpt_index - 1] - CD_k) / sqrt(Cls_k * Cls_k + Cns_k
    * Cns_k)) * (real_T)factor + mass;

  /* %edot, ndot and hdot relative to track%% */
  edot_track_k = (sin(atrack) * cos(btrack) * fh_k + sin(btrack) * fn_k) + cos
    (atrack) * cos(btrack) * fe_k;
  ndot_track_k = (-sin(atrack) * sin(btrack) * fh_k + cos(btrack) * fn_k) - cos
    (atrack) * sin(btrack) * fe_k;

  /* %er-e, nr-n and hr-h relative to track%% */
  /* %etaLon at time [k]%% */
  nr_k_0[0] = *nr_k - n_k;
  nr_k_0[1] = *er_k - e_k;
  fn_k_0[0] = fn_k;
  fn_k_0[1] = fe_k;
  *etaLon_k = rt_atan2d_snf(*hr_k - h_k, NMPC_Controller_norm(nr_k_0)) -
    rt_atan2d_snf(fh_k, NMPC_Controller_norm(fn_k_0));

  /* %etaLat at time [k]%% */
  Cls_k = rt_atan2d_snf(ndot_track_k, edot_track_k) - rt_atan2d_snf((-sin(atrack)
    * sin(btrack) * (*hr_k - h_k) + (*nr_k - n_k) * cos(btrack)) - cos(atrack) *
    sin(btrack) * (*er_k - e_k), (sin(atrack) * cos(btrack) * (*hr_k - h_k) +
    (*nr_k - n_k) * sin(btrack)) + cos(atrack) * cos(btrack) * (*er_k - e_k));
  *etaLat_k = Cls_k;
  if (Cls_k > 3.1415926535897931) {
    *etaLat_k = Cls_k - 6.2831853071795862;
  }

  if (Cls_k < -3.1415926535897931) {
    *etaLat_k = Cls_k + 6.2831853071795862;
  }

  /* OP trajectory generation */
  /* reassigning Vab (based on the new d point) */
  if (b_TR == 2.0) {
    CL_k = wpts_n[next_wpt_index - 1] - n_op_k;
    CD_k = wpts_e[next_wpt_index - 1] - e_op_k;
    ea = wpts_h[next_wpt_index - 1] - h_op_k;
    r_a = wpts_n[next_wpt_index - 1] - nd_k;
    s_a = wpts_e[next_wpt_index - 1] - ed_k;
    t_a = wpts_h[next_wpt_index - 1] - hd_k;
    mass = nd_k - n_op_k;
    Cns_k = ed_k - e_op_k;
    Cls_k = hd_k - h_op_k;
    r_a = sqrt((CL_k * CL_k + CD_k * CD_k) + ea * ea) - sqrt((r_a * r_a + s_a *
      s_a) + t_a * t_a);
    if (r_a < 0.0) {
      r_a = -1.0;
    } else if (r_a > 0.0) {
      r_a = 1.0;
    } else {
      if (r_a == 0.0) {
        r_a = 0.0;
      }
    }

    *Vab_k = sqrt((vn_op_k * vn_op_k + ve_op_k * ve_op_k) + vh_op_k * vh_op_k) -
      atan(sqrt((mass * mass + Cns_k * Cns_k) + Cls_k * Cls_k) * r_a / 100.0) *
      0.063661977236758135;

    /* (168.78) (5) (/100) */
  }

  /* %VT theta phi and beta command%% */
  /* %consider wind in VTcmd [0]: no [1]:yes */
  mass = *Vab_k * cos(atrack) * sin(btrack) + 0.0 * sw;
  Cns_k = *Vab_k * cos(atrack) * cos(btrack) + 0.0 * sw;
  Cls_k = *Vab_k * sin(atrack) + 0.0 * sw;
  *VTcmd_k = sqrt((mass * mass + Cns_k * Cns_k) + Cls_k * Cls_k);
  Cls_k = atan(*etaLon_k * sw);
  er_k_1[0] = *er_k - e_k;
  er_k_1[1] = *nr_k - n_k;
  er_k_1[2] = *hr_k - h_k;
  *thetacmd_k = rt_atan2d_snf(((fe_k * fe_k + fn_k * fn_k) + fh_k * fh_k) * 2.0 *
                              (Cls_k * b_KpLon + ro_k), NMPC_Controller_norm_l
    (er_k_1));
  er_k_0[0] = *er_k - e_k;
  er_k_0[1] = *nr_k - n_k;
  *phicmd_k = rt_atan2d_snf((edot_track_k * edot_track_k + ndot_track_k *
    ndot_track_k) * 2.0 * b_KpLat * sw * *etaLat_k, NMPC_Controller_norm(er_k_0));

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%implementing saturation of actuators%% */
  /* %deflection max and min */
  if (THL_k > b_ThrottleMax) {
    THL_k = b_ThrottleMax;
  } else {
    if (THL_k < b_ThrottleMin) {
      THL_k = b_ThrottleMin;
    }
  }

  if (EL_k > b_ElevatorMax) {
    EL_k = b_ElevatorMax;
  } else {
    if (EL_k < b_ElevatorMin) {
      EL_k = b_ElevatorMin;
    }
  }

  if (AIL_k > b_AileronMax) {
    AIL_k = b_AileronMax;
  } else {
    if (AIL_k < b_AileronMin) {
      AIL_k = b_AileronMin;
    }
  }

  if (RDR_k > b_RudderMax) {
    RDR_k = b_RudderMax;
  } else {
    if (RDR_k < b_RudderMin) {
      RDR_k = b_RudderMin;
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %longitudinal guidance integrator */
  *ro_kk = b_dt * Cls_k * b_KiLon + ro_k;

  /* %servos prediction%% */
  *THL_kk = (b_Athrottle * THL_k + b_Bthrottle * THLcmd_k) * b_dt + THL_k;
  *EL_kk = (b_Aelevator * EL_k + b_Belevator * ELcmd_k) * b_dt + EL_k;
  *AIL_kk = (b_Aaileron * AIL_k + b_Baileron * AILcmd_k) * b_dt + AIL_k;
  *RDR_kk = (b_Arudder * RDR_k + b_Brudder * RDRcmd_k) * b_dt + RDR_k;

  /* %UAV prediction%% */
  Cls_k = ((U_k * Udot_k + V_k * Vdot_k) + W_k * Wdot_k) / VT_k;
  *falpha_k = (U_k * Wdot_k - W_k * Udot_k) / (U_k * U_k + W_k * W_k);
  *fbeta_k = (VT_k * Vdot_k - V_k * Cls_k) / (U_k * U_k + W_k * W_k) * cos
    (beta_k);
  *VT_kk = b_dt * Cls_k + VT_k;
  *alpha_kk = b_dt * *falpha_k + alpha_k;
  *beta_kk = b_dt * *fbeta_k + beta_k;
  *phi_kk = ((R_k * cos(phi_k) + Q_k * sin(phi_k)) * tan(theta_k) + P_k) * b_dt
    + phi_k;
  *theta_kk = (Q_k * cos(phi_k) - R_k * sin(phi_k)) * b_dt + theta_k;
  *psi_kk = (R_k * cos(phi_k) + Q_k * sin(phi_k)) / cos(theta_k) * b_dt + psi_k;
  *P_kk = ((((b_IyyB - b_IzzB) * b_IzzB - b_IxzB * b_IxzB) / delta_I * R_k + c2 *
            P_k) * Q_k + (b_IzzB / delta_I * Cl_k + c4 * Cn_k) * (Qbar_k * b_S *
            b_b)) * b_dt + P_k;
  *Q_kk = (((b_IzzB - b_IxxB) / b_IyyB * P_k * R_k - (P_k * P_k - R_k * R_k) *
            (b_IxzB / b_IyyB)) + Qbar_k * b_S * b_Cbar * (1.0 / b_IyyB) * Cms_k)
    * b_dt + Q_k;
  *R_kk = ((((b_IxxB - b_IyyB) * b_IxxB + b_IxzB * b_IxzB) / delta_I * P_k - c2 *
            R_k) * Q_k + (b_IxxB / delta_I * Cn_k + c4 * Cl_k) * (Qbar_k * b_S *
            b_b)) * b_dt + R_k;

  /* %inertial frame prediction%% */
  *n_kk = b_dt * fn_k + n_k;
  *e_kk = b_dt * fe_k + e_k;
  *h_kk = b_dt * fh_k + h_k;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %outputs e, y and z%% */
  e_augm_k[0] = *VTcmd_k - VT_k;
  e_augm_k[1] = *thetacmd_k - theta_k;
  e_augm_k[2] = *phicmd_k - phi_k;
  e_augm_k[3] = 0.0 - beta_k;

  /* %Robustness states at [k+1]%% */
  *xw11_kk = b_W11d.a * xw11_k + b_W11d.b * e_augm_k[0];

  /* W11 e_VT */
  *xw12_kk = b_W12d.a * xw12_k + b_W12d.b * e_augm_k[1];

  /* W12 e_theta */
  *xw13_kk = b_W13d.a * xw13_k + b_W13d.b * e_augm_k[2];

  /* W13 e_phi */
  *xw14_kk = (0.0 - beta_k) * b_W14d.b + b_W14d.a * xw14_k;

  /* W14 e_beta */
  *xw21_kk = b_W21d.a * xw21_k + b_W21d.b * THLcmd_k;

  /* W21 Throttle cmd */
  *xw22_kk = b_W22d.a * xw22_k + b_W22d.b * ELcmd_k;

  /* W22 Elevator cmd */
  *xw23_kk = b_W23d.a * xw23_k + b_W23d.b * AILcmd_k;

  /* W23 Aileron cmd */
  *xw24_kk = b_W24d.a * xw24_k + b_W24d.b * RDRcmd_k;

  /* W24 Rudder cmd */
  *xw31_kk = b_W31d.a * xw31_k + b_W31d.b * VT_k;

  /* W31 VT */
  *xw32_kk = b_W32d.a * xw32_k + b_W32d.b * theta_k;

  /* W32 theta */
  *xw33_kk = b_W33d.a * xw33_k + b_W33d.b * phi_k;

  /* W33 phi */
  *xw34_kk = b_W34d.a * xw34_k + b_W34d.b * beta_k;

  /* W34 beta */
  /* %Robustness output at [k] */
  z_augm_k[0] = b_W11d.c * xw11_k + b_W11d.d * e_augm_k[0];

  /* W11 e_VT */
  z_augm_k[1] = b_W12d.c * xw12_k + b_W12d.d * e_augm_k[1];

  /* W12 e_theta */
  z_augm_k[2] = b_W13d.c * xw13_k + b_W13d.d * e_augm_k[2];

  /* W13 e_phi */
  z_augm_k[3] = (0.0 - beta_k) * b_W14d.d + b_W14d.c * xw14_k;

  /* W14 e_beta */
  z_augm_k[4] = b_W21d.c * xw21_k + b_W21d.d * THLcmd_k;

  /* W21 Throttle cmd */
  z_augm_k[5] = b_W22d.c * xw22_k + b_W22d.d * ELcmd_k;

  /* W22 Elevator cmd */
  z_augm_k[6] = b_W23d.c * xw23_k + b_W23d.d * AILcmd_k;

  /* W23 Aileron cmd */
  z_augm_k[7] = b_W24d.c * xw24_k + b_W24d.d * RDRcmd_k;

  /* W24 Rudder cmd */
  z_augm_k[8] = b_W31d.c * xw31_k + b_W31d.d * VT_k;

  /* W31 VT */
  z_augm_k[9] = b_W32d.c * xw32_k + b_W32d.d * theta_k;

  /* W32 theta */
  z_augm_k[10] = b_W33d.c * xw33_k + b_W33d.d * phi_k;

  /* W33 phi */
  z_augm_k[11] = b_W34d.c * xw34_k + b_W34d.d * beta_k;

  /* W34 beta */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_eml_ipiv2perm(const int32_T ipiv[80], int32_T perm
  [80])
{
  int32_T pipk;
  int32_T k;
  for (k = 0; k < 80; k++) {
    perm[k] = 1 + k;
  }

  for (k = 0; k < 79; k++) {
    if (ipiv[k] > 1 + k) {
      pipk = perm[ipiv[k] - 1];
      perm[ipiv[k] - 1] = perm[k];
      perm[k] = pipk;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_eml_xtrsm(const real_T A[6400], real_T B[6400])
{
  int32_T jBcol;
  int32_T kAcol;
  int32_T j;
  int32_T k;
  int32_T i;
  for (j = 0; j < 80; j++) {
    jBcol = 80 * j;
    for (k = 79; k >= 0; k += -1) {
      kAcol = 80 * k;
      if (B[k + jBcol] != 0.0) {
        B[k + jBcol] /= A[k + kAcol];
        for (i = 0; i + 1 <= k; i++) {
          B[i + jBcol] -= B[k + jBcol] * A[i + kAcol];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_eml_xswap(real_T x[6400], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 80; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix += 80;
    iy += 80;
  }
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_invNxN(const real_T x[6400], real_T y[6400])
{
  int32_T p[80];
  int32_T c;
  int32_T j;
  int32_T ipiv[80];
  int32_T b_j;
  int32_T c_c;
  real_T smax;
  real_T s;
  int32_T jA;
  int32_T b_ix;
  int32_T e;
  int32_T ijA;
  for (b_j = 0; b_j < 6400; b_j++) {
    y[b_j] = 0.0;
    NMPC_Controller_B.A[b_j] = x[b_j];
  }

  for (b_j = 0; b_j < 80; b_j++) {
    ipiv[b_j] = 1 + b_j;
  }

  for (b_j = 0; b_j < 79; b_j++) {
    c_c = b_j * 81;
    jA = 1;
    c = c_c;
    smax = fabs(NMPC_Controller_B.A[c_c]);
    for (j = 2; j <= 80 - b_j; j++) {
      c++;
      s = fabs(NMPC_Controller_B.A[c]);
      if (s > smax) {
        jA = j;
        smax = s;
      }
    }

    if (NMPC_Controller_B.A[(c_c + jA) - 1] != 0.0) {
      if (jA - 1 != 0) {
        ipiv[b_j] = b_j + jA;
        NMPC_Controller_eml_xswap(NMPC_Controller_B.A, b_j + 1, b_j + jA);
      }

      jA = (c_c - b_j) + 80;
      for (c = c_c + 1; c + 1 <= jA; c++) {
        NMPC_Controller_B.A[c] /= NMPC_Controller_B.A[c_c];
      }
    }

    jA = c_c;
    c = c_c + 80;
    for (j = 1; j <= 79 - b_j; j++) {
      smax = NMPC_Controller_B.A[c];
      if (NMPC_Controller_B.A[c] != 0.0) {
        b_ix = c_c + 1;
        e = (jA - b_j) + 160;
        for (ijA = 81 + jA; ijA + 1 <= e; ijA++) {
          NMPC_Controller_B.A[ijA] += NMPC_Controller_B.A[b_ix] * -smax;
          b_ix++;
        }
      }

      c += 80;
      jA += 80;
    }
  }

  NMPC_Controller_eml_ipiv2perm(ipiv, p);
  for (jA = 0; jA < 80; jA++) {
    c = p[jA] - 1;
    y[jA + 80 * (p[jA] - 1)] = 1.0;
    for (j = jA; j + 1 < 81; j++) {
      if (y[80 * c + j] != 0.0) {
        for (b_ix = j + 1; b_ix + 1 < 81; b_ix++) {
          y[b_ix + 80 * c] -= y[80 * c + j] * NMPC_Controller_B.A[80 * j + b_ix];
        }
      }
    }
  }

  NMPC_Controller_eml_xtrsm(NMPC_Controller_B.A, y);
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_mpower(const real_T a[6400], real_T c[6400])
{
  NMPC_Controller_invNxN(a, c);
}

/* Function for MATLAB Function: '<Root>/Control System' */
static real_T NMPC_Controller_sum(const boolean_T x[40])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 39; k++) {
    y += (real_T)x[k + 1];
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/Control System' */
static real_T NMPC_Controller_sum_p(const boolean_T x[20])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 19; k++) {
    y += (real_T)x[k + 1];
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_eml_ipiv2perm_k(const int32_T ipiv_data[], const
  int32_T ipiv_sizes[2], int32_T m, int32_T perm_data[], int32_T perm_sizes[2])
{
  int32_T pipk;
  int32_T yk;
  perm_sizes[0] = 1;
  perm_sizes[1] = m;
  perm_data[0] = 1;
  yk = 1;
  for (pipk = 2; pipk <= m; pipk++) {
    yk++;
    perm_data[pipk - 1] = yk;
  }

  for (yk = 0; yk < ipiv_sizes[1]; yk++) {
    if (ipiv_data[yk] > 1 + yk) {
      pipk = perm_data[ipiv_data[yk] - 1];
      perm_data[ipiv_data[yk] - 1] = perm_data[yk];
      perm_data[yk] = pipk;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_eml_xtrsm_b(int32_T m, int32_T n, const real_T
  A_data[], int32_T lda, real_T B_data[], int32_T ldb)
{
  int32_T jBcol;
  int32_T kAcol;
  int32_T j;
  int32_T k;
  int32_T i;
  for (j = 1; j <= n; j++) {
    jBcol = (j - 1) * ldb;
    for (k = m - 1; k + 1 > 0; k--) {
      kAcol = lda * k;
      if (B_data[k + jBcol] != 0.0) {
        B_data[k + jBcol] /= A_data[k + kAcol];
        for (i = 0; i + 1 <= k; i++) {
          B_data[i + jBcol] -= B_data[k + jBcol] * A_data[i + kAcol];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_eml_xswap_d(int32_T n, real_T x_data[], int32_T ix0,
  int32_T incx, int32_T iy0, int32_T incy)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 1; k <= n; k++) {
    temp = x_data[ix];
    x_data[ix] = x_data[iy];
    x_data[iy] = temp;
    ix += incx;
    iy += incy;
  }
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_invNxN_l(const real_T x_data[], const int32_T
  x_sizes[2], real_T y_data[], int32_T y_sizes[2])
{
  int32_T n;
  int32_T i;
  int32_T mmj;
  int32_T b_j;
  int32_T c_c;
  int32_T yk;
  real_T smax;
  real_T s;
  int32_T jy;
  int32_T b_ix;
  int32_T f;
  int32_T ijA;
  int32_T loop_ub;
  int32_T p_data[120];
  int32_T p_sizes[2];
  int32_T A_sizes[2];
  int32_T ipiv_data[120];
  int32_T ipiv_sizes[2];
  int32_T u0;
  n = x_sizes[0];
  y_sizes[0] = x_sizes[0];
  y_sizes[1] = x_sizes[1];
  loop_ub = x_sizes[0] * x_sizes[1];
  for (yk = 0; yk < loop_ub; yk++) {
    y_data[yk] = 0.0;
  }

  A_sizes[0] = x_sizes[0];
  A_sizes[1] = x_sizes[1];
  loop_ub = x_sizes[0] * x_sizes[1];
  for (yk = 0; yk < loop_ub; yk++) {
    NMPC_Controller_B.A_data[yk] = x_data[yk];
  }

  loop_ub = x_sizes[0];
  ipiv_sizes[0] = 1;
  ipiv_sizes[1] = loop_ub;
  ipiv_data[0] = 1;
  yk = 1;
  for (jy = 2; jy <= loop_ub; jy++) {
    yk++;
    ipiv_data[jy - 1] = yk;
  }

  u0 = x_sizes[0] - 1;
  if (!(u0 <= x_sizes[0])) {
    u0 = x_sizes[0];
  }

  for (b_j = 1; b_j <= u0; b_j++) {
    mmj = (n - b_j) + 1;
    c_c = (b_j - 1) * (n + 1);
    if (mmj < 1) {
      loop_ub = -1;
    } else {
      loop_ub = 0;
      if (mmj > 1) {
        yk = c_c;
        smax = fabs(NMPC_Controller_B.A_data[c_c]);
        for (jy = 1; jy + 1 <= mmj; jy++) {
          yk++;
          s = fabs(NMPC_Controller_B.A_data[yk]);
          if (s > smax) {
            loop_ub = jy;
            smax = s;
          }
        }
      }
    }

    if (NMPC_Controller_B.A_data[c_c + loop_ub] != 0.0) {
      if (loop_ub != 0) {
        ipiv_data[b_j - 1] = b_j + loop_ub;
        NMPC_Controller_eml_xswap_d(n, NMPC_Controller_B.A_data, b_j, n, b_j +
          loop_ub, n);
      }

      loop_ub = c_c + mmj;
      for (yk = c_c + 1; yk + 1 <= loop_ub; yk++) {
        NMPC_Controller_B.A_data[yk] /= NMPC_Controller_B.A_data[c_c];
      }
    }

    loop_ub = n - b_j;
    yk = c_c + n;
    jy = c_c + n;
    for (i = 1; i <= loop_ub; i++) {
      smax = NMPC_Controller_B.A_data[jy];
      if (NMPC_Controller_B.A_data[jy] != 0.0) {
        b_ix = c_c + 1;
        f = mmj + yk;
        for (ijA = 1 + yk; ijA + 1 <= f; ijA++) {
          NMPC_Controller_B.A_data[ijA] += NMPC_Controller_B.A_data[b_ix] *
            -smax;
          b_ix++;
        }
      }

      jy += n;
      yk += n;
    }
  }

  NMPC_Controller_eml_ipiv2perm_k(ipiv_data, ipiv_sizes, x_sizes[0], p_data,
    p_sizes);
  for (loop_ub = 0; loop_ub + 1 <= n; loop_ub++) {
    yk = p_data[loop_ub] - 1;
    y_data[loop_ub + y_sizes[0] * (p_data[loop_ub] - 1)] = 1.0;
    for (jy = loop_ub; jy + 1 <= n; jy++) {
      if (y_data[y_sizes[0] * yk + jy] != 0.0) {
        for (i = jy + 1; i + 1 <= n; i++) {
          y_data[i + y_sizes[0] * yk] -= y_data[y_sizes[0] * yk + jy] *
            NMPC_Controller_B.A_data[A_sizes[0] * jy + i];
        }
      }
    }
  }

  NMPC_Controller_eml_xtrsm_b(x_sizes[0], x_sizes[0], NMPC_Controller_B.A_data,
    x_sizes[0], y_data, x_sizes[0]);
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_mpower_h(const real_T a_data[], const int32_T
  a_sizes[2], real_T c_data[], int32_T c_sizes[2])
{
  NMPC_Controller_invNxN_l(a_data, a_sizes, c_data, c_sizes);
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_squeeze(const real_T a[12], real_T b_b[12])
{
  memcpy(&b_b[0], &a[0], 12U * sizeof(real_T));
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_uas_augm_model_bm(real_T sw, boolean_T home_cmd,
  real_T b_dt, real_T b_TR, uint8_T wpts_fp, uint8_T wpts_rp, real_T wpts_h[32],
  real_T wpts_n[32], real_T wpts_e[32], const real_T wpts_v[32], real_T n_op_k,
  real_T e_op_k, real_T h_op_k, real_T vn_op_k, real_T ve_op_k, real_T vh_op_k,
  real_T alphadot_k, real_T betadot_k, uint8_T wpt_index_k, real_T start_wpt_k[3],
  real_T pic_cic_k, real_T home_reset_k, real_T THL_k, real_T EL_k, real_T AIL_k,
  real_T RDR_k, real_T VT_k, real_T alpha_k, real_T beta_k, real_T phi_k, real_T
  theta_k, real_T psi_k, real_T P_k, real_T Q_k, real_T R_k, real_T n_k, real_T
  e_k, real_T h_k, real_T ro_k, real_T THLcmd_k, real_T ELcmd_k, real_T AILcmd_k,
  real_T RDRcmd_k, real_T xw11_k, real_T xw12_k, real_T xw13_k, real_T xw14_k,
  real_T xw21_k, real_T xw22_k, real_T xw23_k, real_T xw24_k, real_T xw31_k,
  real_T xw32_k, real_T xw33_k, real_T xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W11d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W12d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W14d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W21d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W23d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W24d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W32d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W33d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W34d, real_T b_rho, real_T b_S,
  real_T b_Cbar, real_T b_b, real_T b_weight, real_T b_g, real_T b_IxxB, real_T
  b_IyyB, real_T b_IzzB, real_T b_IxzB, real_T b_CDu, real_T b_CDq, real_T
  b_CDadot, real_T b_CDde, real_T b_CD0_bar, real_T b_Cyb, real_T b_Cyp, real_T
  b_Cyr, real_T b_Cyda, real_T b_Cydr, real_T b_CL0, real_T b_CLa, real_T b_CLq,
  real_T b_CLadot, real_T b_CLu, real_T b_CLde, real_T b_Clb, real_T b_Clp,
  real_T b_Clr, real_T b_Clda, real_T b_Cldr, real_T b_Cm0, real_T b_Cma, real_T
  b_Cmq, real_T b_Cmadot, real_T b_Cmu, real_T b_Cmde, real_T b_Cnb, real_T
  b_Cnp, real_T b_Cnr, real_T b_Cnda, real_T b_Cndr, real_T b_xT0, real_T b_xT1,
  real_T b_xT2, real_T b_Ptrim, real_T b_Qtrim, real_T b_Rtrim, real_T b_Utrim,
  real_T b_Athrottle, real_T b_Bthrottle, real_T b_Aelevator, real_T b_Belevator,
  real_T b_Aaileron, real_T b_Baileron, real_T b_Arudder, real_T b_Brudder,
  real_T b_ThrottleMax, real_T b_ThrottleMin, real_T b_ElevatorMax, real_T
  b_ElevatorMin, real_T b_AileronMax, real_T b_AileronMin, real_T b_RudderMax,
  real_T b_RudderMin, real_T b_KpLat, real_T b_KiLon, real_T b_KpLon, real_T b_L,
  real_T b_dist2b, real_T FL_ann, const real_T a_ann_X[40], const real_T
  b_ann_X[40], real_T c_ann_X, const real_T w_ann_X[280], const real_T a_ann_Y
  [40], const real_T b_ann_Y[40], real_T c_ann_Y, const real_T w_ann_Y[280],
  const real_T a_ann_Z[40], const real_T b_ann_Z[40], real_T c_ann_Z, const
  real_T w_ann_Z[280], const real_T b_X_minXin[7], const real_T b_X_maxXin[7],
  real_T b_X_minYin, real_T b_X_maxYin, real_T b_X_minXout, real_T b_X_maxXout,
  real_T b_X_minYout, real_T b_X_maxYout, const real_T b_Y_minXin[7], const
  real_T b_Y_maxXin[7], real_T b_Y_minYin, real_T b_Y_maxYin, real_T b_Y_minXout,
  real_T b_Y_maxXout, real_T b_Y_minYout, real_T b_Y_maxYout, const real_T
  b_Z_minXin[7], const real_T b_Z_maxXin[7], real_T b_Z_minYin, real_T
  b_Z_maxYin, real_T b_Z_minXout, real_T b_Z_maxXout, real_T b_Z_minYout, real_T
  b_Z_maxYout, real32_T *distance2b, uint8_T *wpt_index_kk, real_T *pic_cic_kk,
  uint8_T *home_reset_kk, real_T *nr_k, real_T *er_k, real_T *hr_k, real_T
  *etaLon_k, real_T *etaLat_k, real_T *VTcmd_k, real_T *thetacmd_k, real_T
  *phicmd_k, real_T *Vab_k, real_T *accelX_scd_k, real_T *accelX_ann_k, real_T
  *accelY_scd_k, real_T *accelY_ann_k, real_T *accelZ_scd_k, real_T
  *accelZ_ann_k, real_T z_augm_k[12], real_T e_augm_k[4], real_T *THL_kk, real_T
  *EL_kk, real_T *AIL_kk, real_T *RDR_kk, real_T *VT_kk, real_T *alpha_kk,
  real_T *beta_kk, real_T *phi_kk, real_T *theta_kk, real_T *psi_kk, real_T
  *P_kk, real_T *Q_kk, real_T *R_kk, real_T *falpha_k, real_T *fbeta_k, real_T
  *n_kk, real_T *e_kk, real_T *h_kk, real_T *ro_kk, real_T *xw11_kk, real_T
  *xw12_kk, real_T *xw13_kk, real_T *xw14_kk, real_T *xw21_kk, real_T *xw22_kk,
  real_T *xw23_kk, real_T *xw24_kk, real_T *xw31_kk, real_T *xw32_kk, real_T
  *xw33_kk, real_T *xw34_kk)
{
  real_T mass;
  real_T delta_I;
  real_T c2;
  real_T c4;
  real_T Qbar_k;
  real_T U_k;
  real_T V_k;
  real_T W_k;
  real_T CL_k;
  real_T CD_k;
  real_T Cls_k;
  real_T Cms_k;
  real_T Cns_k;
  real_T Cl_k;
  real_T Cn_k;
  real_T Udot_k;
  real_T Vdot_k;
  real_T Wdot_k;
  real_T fn_k;
  real_T fe_k;
  real_T fh_k;
  uint8_T next_wpt_index;
  real_T ea;
  real_T hd_k;
  real_T nd_k;
  real_T ed_k;
  real_T atrack;
  int32_T factor;
  real_T btrack;
  real_T edot_track_k;
  real_T ndot_track_k;
  real_T r_a;
  real_T s_a;
  real_T t_a;
  real_T er_k_0[2];
  real_T er_k_1[3];
  real_T nr_k_0[2];
  real_T fn_k_0[2];
  real_T VT_k_0[7];
  real_T VT_k_1[7];
  real_T VT_k_2[7];
  real_T tmp[7];
  real_T w_ann_X_0[40];
  int32_T i;

  /* %temporary */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %mass and inertia coefficients%% */
  mass = b_weight / b_g;
  delta_I = b_IxxB * b_IzzB - b_IxzB * b_IxzB;
  c2 = ((b_IxxB - b_IyyB) + b_IzzB) * b_IxzB / delta_I;
  c4 = b_IxzB / delta_I;

  /* %dynamic pressure%% */
  Qbar_k = 0.5 * b_rho * (VT_k * VT_k);

  /* %body velocities%% */
  U_k = VT_k * cos(alpha_k) * cos(beta_k);
  V_k = VT_k * sin(beta_k);
  W_k = VT_k * sin(alpha_k) * cos(beta_k);

  /* %aerodynamic coefficients%% */
  CL_k = ((((Q_k - b_Qtrim) * b_CLq * b_Cbar / 2.0 / b_Utrim + (b_CLa * alpha_k
             + b_CL0)) + b_CLadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k
           - b_Utrim) * b_CLu / b_Utrim) + b_CLde * EL_k;

  /* CD_k=CD0+CDa*alpha_k+CDq*(Q_k-Qtrim)*Cbar/2/Utrim+CDadot*alphadot_k*Cbar/2/Utrim+CDu*(U_k-Utrim)/Utrim+CDde*EL_k; %lin */
  CD_k = ((((CL_k * CL_k / (3.1415926535897931 * b_b / b_Cbar * 0.87) +
             b_CD0_bar) + (Q_k - b_Qtrim) * b_CDq * b_Cbar / 2.0 / b_Utrim) +
           b_CDadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k - b_Utrim) *
          b_CDu / b_Utrim) + b_CDde * EL_k;

  /* nonlin */
  Cls_k = ((((P_k - b_Ptrim) * b_Clp * b_b / 2.0 / b_Utrim + b_Clb * beta_k) +
            (R_k - b_Rtrim) * b_Clr * b_b / 2.0 / b_Utrim) + b_Clda * AIL_k) +
    b_Cldr * RDR_k;
  Cms_k = ((((Q_k - b_Qtrim) * b_Cmq * b_Cbar / 2.0 / b_Utrim + (b_Cma * alpha_k
              + b_Cm0)) + b_Cmadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k
            - b_Utrim) * b_Cmu / b_Utrim) + b_Cmde * EL_k;
  Cns_k = ((((P_k - b_Ptrim) * b_Cnp * b_b / 2.0 / b_Utrim + b_Cnb * beta_k) +
            (R_k - b_Rtrim) * b_Cnr * b_b / 2.0 / b_Utrim) + b_Cnda * AIL_k) +
    b_Cndr * RDR_k;
  Cl_k = Cls_k * cos(alpha_k) - Cns_k * sin(alpha_k);
  Cn_k = Cls_k * sin(alpha_k) + Cns_k * cos(alpha_k);

  /* %engine thrust%% */
  Cls_k = 100.0 * THL_k;

  /* %S&C aerodynamic and thrust linear accelerations%% */
  *accelX_scd_k = (((Cls_k * Cls_k * b_xT2 + 100.0 * THL_k * b_xT1) + b_xT0) + (
    -CD_k * cos(alpha_k) + CL_k * sin(alpha_k)) * (Qbar_k * b_S)) / mass;

  /* [ft/s2] */
  *accelY_scd_k = (((((P_k - b_Ptrim) * b_Cyp * b_b / 2.0 / b_Utrim + b_Cyb *
                      beta_k) + (R_k - b_Rtrim) * b_Cyr * b_b / 2.0 / b_Utrim) +
                    b_Cyda * AIL_k) + b_Cydr * RDR_k) * (Qbar_k * b_S) / mass;

  /* [ft/s2] */
  *accelZ_scd_k = (-CD_k * sin(alpha_k) - CL_k * cos(alpha_k)) * (Qbar_k * b_S) /
    mass;

  /* [ft/s2] */
  /* ANN linear accelerations */
  /* X-axis */
  VT_k_2[0] = VT_k;
  VT_k_2[1] = alpha_k;
  VT_k_2[2] = beta_k;
  VT_k_2[3] = Q_k;
  VT_k_2[4] = alphadot_k;
  VT_k_2[5] = THL_k;
  VT_k_2[6] = EL_k;
  NMPC_Controller_ann_norm_X(VT_k_2, b_X_minXin, b_X_maxXin, b_X_minYin,
    b_X_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_X[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_X[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_X[factor] * w_ann_X_0[factor];
  }

  *accelX_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_X, b_X_minXout,
    b_X_maxXout, b_X_minYout, b_X_maxYout) * b_g;

  /* [ft/s2] no tansig */
  /* Y_axis */
  VT_k_1[0] = VT_k;
  VT_k_1[1] = beta_k;
  VT_k_1[2] = P_k;
  VT_k_1[3] = R_k;
  VT_k_1[4] = betadot_k;
  VT_k_1[5] = AIL_k;
  VT_k_1[6] = RDR_k;
  NMPC_Controller_ann_norm_X(VT_k_1, b_Y_minXin, b_Y_maxXin, b_Y_minYin,
    b_Y_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_Y[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_Y[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_Y[factor] * w_ann_X_0[factor];
  }

  *accelY_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_Y, b_Y_minXout,
    b_Y_maxXout, b_Y_minYout, b_Y_maxYout) * b_g;

  /* [ft/s2] no tansig */
  /* Z-axis */
  VT_k_0[0] = VT_k;
  VT_k_0[1] = alpha_k;
  VT_k_0[2] = beta_k;
  VT_k_0[3] = Q_k;
  VT_k_0[4] = alphadot_k;
  VT_k_0[5] = THL_k;
  VT_k_0[6] = EL_k;
  NMPC_Controller_ann_norm_X(VT_k_0, b_Z_minXin, b_Z_maxXin, b_Z_minYin,
    b_Z_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_Z[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_Z[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_Z[factor] * w_ann_X_0[factor];
  }

  *accelZ_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_Z, b_Z_minXout,
    b_Z_maxXout, b_Z_minYout, b_Z_maxYout) * b_g;

  /* [ft/s2] no tansig */
  Cls_k = 0.0;

  /* initialization */
  Cns_k = 0.0;

  /* initialization */
  mass = 0.0;

  /* initialization */
  if (FL_ann == 0.0) {
    /* scd */
    Cls_k = *accelX_scd_k;
    Cns_k = *accelY_scd_k;
    mass = *accelZ_scd_k;
  } else {
    if (FL_ann == 1.0) {
      /* ann */
      Cls_k = *accelX_ann_k;
      Cns_k = *accelY_ann_k;
      mass = *accelZ_ann_k;
    }
  }

  /* body accelerations */
  Udot_k = ((R_k * V_k - Q_k * W_k) - b_g * sin(theta_k)) + Cls_k;
  Vdot_k = ((P_k * W_k - R_k * U_k) + b_g * sin(phi_k) * cos(theta_k)) + Cns_k;
  Wdot_k = ((Q_k * U_k - P_k * V_k) + b_g * cos(phi_k) * cos(theta_k)) + mass;

  /* %inertial speed (with no wind)%% */
  fn_k = ((sin(phi_k) * sin(theta_k) * cos(psi_k) - cos(phi_k) * sin(psi_k)) *
          V_k + U_k * cos(theta_k) * cos(psi_k)) + (cos(phi_k) * sin(theta_k) *
    cos(psi_k) + sin(phi_k) * sin(psi_k)) * W_k;
  fe_k = ((sin(phi_k) * sin(theta_k) * sin(psi_k) + cos(phi_k) * cos(psi_k)) *
          V_k + U_k * cos(theta_k) * sin(psi_k)) + (cos(phi_k) * sin(theta_k) *
    sin(psi_k) - sin(phi_k) * cos(psi_k)) * W_k;
  fh_k = (U_k * sin(theta_k) - V_k * sin(phi_k) * cos(theta_k)) - W_k * cos
    (phi_k) * cos(theta_k);

  /* %inertial speed%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Local variable assignment */
  *wpt_index_kk = wpt_index_k;
  r_a = rt_roundd_snf(home_reset_k);
  if (r_a < 256.0) {
    if (r_a >= 0.0) {
      *home_reset_kk = (uint8_T)r_a;
    } else {
      *home_reset_kk = 0U;
    }
  } else {
    *home_reset_kk = MAX_uint8_T;
  }

  /* PIC/CIC Transition Logic: */
  /*  On transition to CIC or PIC, set index = 0 and current position to  */
  /*  current waypoint; hold current waypoint. */
  if ((sw > pic_cic_k) || (sw == 0.0)) {
    start_wpt_k[0] = h_k;
    start_wpt_k[1] = n_k;
    start_wpt_k[2] = e_k;
    *wpt_index_kk = 0U;
    *home_reset_kk = 0U;
  }

  /*  Change the waypoint index when home command */
  if ((home_cmd == 1) && (sw == 1.0) && (*home_reset_kk == 0)) {
    *wpt_index_kk = 23U;
    *home_reset_kk = 1U;
  }

  /* OP trajectory generation */
  /* %reassigning the a and b waypoints */
  if ((b_TR == 2.0) && (*home_reset_kk == 0)) {
    *wpt_index_kk = 1U;
    wpts_n[wpt_index_k - 1] = n_op_k - 100.0 * vn_op_k;
    factor = (int32_T)(wpt_index_k + 1U);
    if ((uint32_T)factor > 255U) {
      factor = 255;
    }

    wpts_n[factor - 1] = 100.0 * vn_op_k + n_op_k;
    wpts_e[wpt_index_k - 1] = e_op_k - 100.0 * ve_op_k;
    factor = (int32_T)(wpt_index_k + 1U);
    if ((uint32_T)factor > 255U) {
      factor = 255;
    }

    wpts_e[factor - 1] = 100.0 * ve_op_k + e_op_k;
    wpts_h[wpt_index_k - 1] = h_op_k - 100.0 * vh_op_k;
    factor = (int32_T)(wpt_index_k + 1U);
    if ((uint32_T)factor > 255U) {
      factor = 255;
    }

    wpts_h[factor - 1] = 100.0 * vh_op_k + h_op_k;
  }

  /* calculate the next waypoint index */
  factor = (int32_T)(*wpt_index_kk + 1U);
  if ((uint32_T)factor > 255U) {
    factor = 255;
  }

  next_wpt_index = (uint8_T)factor;

  /* beyond final point (fp), go to return point (rp) */
  if ((uint8_T)factor > wpts_fp) {
    next_wpt_index = wpts_rp;
  }

  /* calculate distance to next waypoint */
  Cls_k = n_k - wpts_n[next_wpt_index - 1];
  Cns_k = e_k - wpts_e[next_wpt_index - 1];
  Cls_k = sqrt(Cls_k * Cls_k + Cns_k * Cns_k);

  /* change to next waypoint if in range */
  if ((Cls_k < b_dist2b) && (sw == 1.0)) {
    /*  Do not change index if sw=0 */
    *wpt_index_kk = next_wpt_index;
    if (next_wpt_index == wpts_fp) {
      next_wpt_index = wpts_rp;
    } else {
      factor = (int32_T)(next_wpt_index + 1U);
      if ((uint32_T)factor > 255U) {
        factor = 255;
      }

      next_wpt_index = (uint8_T)factor;
    }
  }

  /* function outputs */
  if ((*wpt_index_kk == 0) || (*wpt_index_kk == 23)) {
    /*  Assign the speed of the starting segment to the speed of the first */
    /*  waypoint */
    *Vab_k = wpts_v[0];
    CL_k = start_wpt_k[0];
    CD_k = start_wpt_k[1];
    ea = start_wpt_k[2];
  } else {
    *Vab_k = wpts_v[*wpt_index_kk - 1];
    CL_k = wpts_h[*wpt_index_kk - 1];
    CD_k = wpts_n[*wpt_index_kk - 1];
    ea = wpts_e[*wpt_index_kk - 1];
  }

  *distance2b = (real32_T)Cls_k;
  *pic_cic_kk = sw;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %reference point r%% */
  Cls_k = wpts_h[next_wpt_index - 1] - CL_k;
  Cns_k = wpts_n[next_wpt_index - 1] - CD_k;
  mass = wpts_e[next_wpt_index - 1] - ea;
  Cls_k = (((wpts_h[next_wpt_index - 1] - CL_k) * (h_k - CL_k) +
            (wpts_n[next_wpt_index - 1] - CD_k) * (n_k - CD_k)) +
           (wpts_e[next_wpt_index - 1] - ea) * (e_k - ea)) / ((Cls_k * Cls_k +
    Cns_k * Cns_k) + mass * mass);
  hd_k = (wpts_h[next_wpt_index - 1] - CL_k) * Cls_k + CL_k;
  nd_k = (wpts_n[next_wpt_index - 1] - CD_k) * Cls_k + CD_k;
  ed_k = (wpts_e[next_wpt_index - 1] - ea) * Cls_k + ea;
  Cls_k = wpts_h[next_wpt_index - 1] - hd_k;
  Cns_k = wpts_n[next_wpt_index - 1] - nd_k;
  mass = wpts_e[next_wpt_index - 1] - ed_k;
  Cls_k = b_L / sqrt((Cls_k * Cls_k + Cns_k * Cns_k) + mass * mass);
  *er_k = (wpts_e[next_wpt_index - 1] - ed_k) * Cls_k + ed_k;
  *nr_k = (wpts_n[next_wpt_index - 1] - nd_k) * Cls_k + nd_k;
  *hr_k = (wpts_h[next_wpt_index - 1] - hd_k) * Cls_k + hd_k;

  /* %alpha and beta track%% */
  Cls_k = wpts_h[next_wpt_index - 1] - CL_k;
  Cns_k = wpts_n[next_wpt_index - 1] - CD_k;
  mass = wpts_e[next_wpt_index - 1] - ea;
  atrack = asin((wpts_h[next_wpt_index - 1] - CL_k) / sqrt((Cls_k * Cls_k +
    Cns_k * Cns_k) + mass * mass));
  Cls_k = wpts_n[next_wpt_index - 1] - CD_k;
  Cns_k = wpts_e[next_wpt_index - 1] - ea;
  factor = 1;
  mass = 0.0;
  if (!((wpts_n[next_wpt_index - 1] - CD_k > 0.0) && (wpts_e[next_wpt_index - 1]
        - ea > 0.0))) {
    if ((wpts_n[next_wpt_index - 1] - CD_k > 0.0) && (wpts_e[next_wpt_index - 1]
         - ea < 0.0)) {
      mass = 3.1415926535897931;
      factor = -1;
    } else {
      if ((wpts_n[next_wpt_index - 1] - CD_k < 0.0) && (wpts_e[next_wpt_index -
           1] - ea < 0.0)) {
        mass = -3.1415926535897931;
        factor = -1;
      }
    }
  }

  btrack = asin((wpts_n[next_wpt_index - 1] - CD_k) / sqrt(Cls_k * Cls_k + Cns_k
    * Cns_k)) * (real_T)factor + mass;

  /* %edot, ndot and hdot relative to track%% */
  edot_track_k = (sin(atrack) * cos(btrack) * fh_k + sin(btrack) * fn_k) + cos
    (atrack) * cos(btrack) * fe_k;
  ndot_track_k = (-sin(atrack) * sin(btrack) * fh_k + cos(btrack) * fn_k) - cos
    (atrack) * sin(btrack) * fe_k;

  /* %er-e, nr-n and hr-h relative to track%% */
  /* %etaLon at time [k]%% */
  nr_k_0[0] = *nr_k - n_k;
  nr_k_0[1] = *er_k - e_k;
  fn_k_0[0] = fn_k;
  fn_k_0[1] = fe_k;
  *etaLon_k = rt_atan2d_snf(*hr_k - h_k, NMPC_Controller_norm(nr_k_0)) -
    rt_atan2d_snf(fh_k, NMPC_Controller_norm(fn_k_0));

  /* %etaLat at time [k]%% */
  Cls_k = rt_atan2d_snf(ndot_track_k, edot_track_k) - rt_atan2d_snf((-sin(atrack)
    * sin(btrack) * (*hr_k - h_k) + (*nr_k - n_k) * cos(btrack)) - cos(atrack) *
    sin(btrack) * (*er_k - e_k), (sin(atrack) * cos(btrack) * (*hr_k - h_k) +
    (*nr_k - n_k) * sin(btrack)) + cos(atrack) * cos(btrack) * (*er_k - e_k));
  *etaLat_k = Cls_k;
  if (Cls_k > 3.1415926535897931) {
    *etaLat_k = Cls_k - 6.2831853071795862;
  }

  if (Cls_k < -3.1415926535897931) {
    *etaLat_k = Cls_k + 6.2831853071795862;
  }

  /* OP trajectory generation */
  /* reassigning Vab (based on the new d point) */
  if (b_TR == 2.0) {
    CL_k = wpts_n[next_wpt_index - 1] - n_op_k;
    CD_k = wpts_e[next_wpt_index - 1] - e_op_k;
    ea = wpts_h[next_wpt_index - 1] - h_op_k;
    r_a = wpts_n[next_wpt_index - 1] - nd_k;
    s_a = wpts_e[next_wpt_index - 1] - ed_k;
    t_a = wpts_h[next_wpt_index - 1] - hd_k;
    mass = nd_k - n_op_k;
    Cns_k = ed_k - e_op_k;
    Cls_k = hd_k - h_op_k;
    r_a = sqrt((CL_k * CL_k + CD_k * CD_k) + ea * ea) - sqrt((r_a * r_a + s_a *
      s_a) + t_a * t_a);
    if (r_a < 0.0) {
      r_a = -1.0;
    } else if (r_a > 0.0) {
      r_a = 1.0;
    } else {
      if (r_a == 0.0) {
        r_a = 0.0;
      }
    }

    *Vab_k = sqrt((vn_op_k * vn_op_k + ve_op_k * ve_op_k) + vh_op_k * vh_op_k) -
      atan(sqrt((mass * mass + Cns_k * Cns_k) + Cls_k * Cls_k) * r_a / 100.0) *
      0.063661977236758135;

    /* (168.78) (5) (/100) */
  }

  /* %VT theta phi and beta command%% */
  /* %consider wind in VTcmd [0]: no [1]:yes */
  mass = *Vab_k * cos(atrack) * sin(btrack) + 0.0 * sw;
  Cns_k = *Vab_k * cos(atrack) * cos(btrack) + 0.0 * sw;
  Cls_k = *Vab_k * sin(atrack) + 0.0 * sw;
  *VTcmd_k = sqrt((mass * mass + Cns_k * Cns_k) + Cls_k * Cls_k);
  Cls_k = atan(*etaLon_k * sw);
  er_k_1[0] = *er_k - e_k;
  er_k_1[1] = *nr_k - n_k;
  er_k_1[2] = *hr_k - h_k;
  *thetacmd_k = rt_atan2d_snf(((fe_k * fe_k + fn_k * fn_k) + fh_k * fh_k) * 2.0 *
                              (Cls_k * b_KpLon + ro_k), NMPC_Controller_norm_l
    (er_k_1));
  er_k_0[0] = *er_k - e_k;
  er_k_0[1] = *nr_k - n_k;
  *phicmd_k = rt_atan2d_snf((edot_track_k * edot_track_k + ndot_track_k *
    ndot_track_k) * 2.0 * b_KpLat * sw * *etaLat_k, NMPC_Controller_norm(er_k_0));

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%implementing saturation of actuators%% */
  /* %deflection max and min */
  if (THL_k > b_ThrottleMax) {
    THL_k = b_ThrottleMax;
  } else {
    if (THL_k < b_ThrottleMin) {
      THL_k = b_ThrottleMin;
    }
  }

  if (EL_k > b_ElevatorMax) {
    EL_k = b_ElevatorMax;
  } else {
    if (EL_k < b_ElevatorMin) {
      EL_k = b_ElevatorMin;
    }
  }

  if (AIL_k > b_AileronMax) {
    AIL_k = b_AileronMax;
  } else {
    if (AIL_k < b_AileronMin) {
      AIL_k = b_AileronMin;
    }
  }

  if (RDR_k > b_RudderMax) {
    RDR_k = b_RudderMax;
  } else {
    if (RDR_k < b_RudderMin) {
      RDR_k = b_RudderMin;
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %longitudinal guidance integrator */
  *ro_kk = b_dt * Cls_k * b_KiLon + ro_k;

  /* %servos prediction%% */
  *THL_kk = (b_Athrottle * THL_k + b_Bthrottle * THLcmd_k) * b_dt + THL_k;
  *EL_kk = (b_Aelevator * EL_k + b_Belevator * ELcmd_k) * b_dt + EL_k;
  *AIL_kk = (b_Aaileron * AIL_k + b_Baileron * AILcmd_k) * b_dt + AIL_k;
  *RDR_kk = (b_Arudder * RDR_k + b_Brudder * RDRcmd_k) * b_dt + RDR_k;

  /* %UAV prediction%% */
  Cls_k = ((U_k * Udot_k + V_k * Vdot_k) + W_k * Wdot_k) / VT_k;
  *falpha_k = (U_k * Wdot_k - W_k * Udot_k) / (U_k * U_k + W_k * W_k);
  *fbeta_k = (VT_k * Vdot_k - V_k * Cls_k) / (U_k * U_k + W_k * W_k) * cos
    (beta_k);
  *VT_kk = b_dt * Cls_k + VT_k;
  *alpha_kk = b_dt * *falpha_k + alpha_k;
  *beta_kk = b_dt * *fbeta_k + beta_k;
  *phi_kk = ((R_k * cos(phi_k) + Q_k * sin(phi_k)) * tan(theta_k) + P_k) * b_dt
    + phi_k;
  *theta_kk = (Q_k * cos(phi_k) - R_k * sin(phi_k)) * b_dt + theta_k;
  *psi_kk = (R_k * cos(phi_k) + Q_k * sin(phi_k)) / cos(theta_k) * b_dt + psi_k;
  *P_kk = ((((b_IyyB - b_IzzB) * b_IzzB - b_IxzB * b_IxzB) / delta_I * R_k + c2 *
            P_k) * Q_k + (b_IzzB / delta_I * Cl_k + c4 * Cn_k) * (Qbar_k * b_S *
            b_b)) * b_dt + P_k;
  *Q_kk = (((b_IzzB - b_IxxB) / b_IyyB * P_k * R_k - (P_k * P_k - R_k * R_k) *
            (b_IxzB / b_IyyB)) + Qbar_k * b_S * b_Cbar * (1.0 / b_IyyB) * Cms_k)
    * b_dt + Q_k;
  *R_kk = ((((b_IxxB - b_IyyB) * b_IxxB + b_IxzB * b_IxzB) / delta_I * P_k - c2 *
            R_k) * Q_k + (b_IxxB / delta_I * Cn_k + c4 * Cl_k) * (Qbar_k * b_S *
            b_b)) * b_dt + R_k;

  /* %inertial frame prediction%% */
  *n_kk = b_dt * fn_k + n_k;
  *e_kk = b_dt * fe_k + e_k;
  *h_kk = b_dt * fh_k + h_k;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %outputs e, y and z%% */
  e_augm_k[0] = *VTcmd_k - VT_k;
  e_augm_k[1] = *thetacmd_k - theta_k;
  e_augm_k[2] = *phicmd_k - phi_k;
  e_augm_k[3] = 0.0 - beta_k;

  /* %Robustness states at [k+1]%% */
  *xw11_kk = b_W11d.a * xw11_k + b_W11d.b * e_augm_k[0];

  /* W11 e_VT */
  *xw12_kk = b_W12d.a * xw12_k + b_W12d.b * e_augm_k[1];

  /* W12 e_theta */
  *xw13_kk = b_W13d.a * xw13_k + b_W13d.b * e_augm_k[2];

  /* W13 e_phi */
  *xw14_kk = (0.0 - beta_k) * b_W14d.b + b_W14d.a * xw14_k;

  /* W14 e_beta */
  *xw21_kk = b_W21d.a * xw21_k + b_W21d.b * THLcmd_k;

  /* W21 Throttle cmd */
  *xw22_kk = b_W22d.a * xw22_k + b_W22d.b * ELcmd_k;

  /* W22 Elevator cmd */
  *xw23_kk = b_W23d.a * xw23_k + b_W23d.b * AILcmd_k;

  /* W23 Aileron cmd */
  *xw24_kk = b_W24d.a * xw24_k + b_W24d.b * RDRcmd_k;

  /* W24 Rudder cmd */
  *xw31_kk = b_W31d.a * xw31_k + b_W31d.b * VT_k;

  /* W31 VT */
  *xw32_kk = b_W32d.a * xw32_k + b_W32d.b * theta_k;

  /* W32 theta */
  *xw33_kk = b_W33d.a * xw33_k + b_W33d.b * phi_k;

  /* W33 phi */
  *xw34_kk = b_W34d.a * xw34_k + b_W34d.b * beta_k;

  /* W34 beta */
  /* %Robustness output at [k] */
  z_augm_k[0] = b_W11d.c * xw11_k + b_W11d.d * e_augm_k[0];

  /* W11 e_VT */
  z_augm_k[1] = b_W12d.c * xw12_k + b_W12d.d * e_augm_k[1];

  /* W12 e_theta */
  z_augm_k[2] = b_W13d.c * xw13_k + b_W13d.d * e_augm_k[2];

  /* W13 e_phi */
  z_augm_k[3] = (0.0 - beta_k) * b_W14d.d + b_W14d.c * xw14_k;

  /* W14 e_beta */
  z_augm_k[4] = b_W21d.c * xw21_k + b_W21d.d * THLcmd_k;

  /* W21 Throttle cmd */
  z_augm_k[5] = b_W22d.c * xw22_k + b_W22d.d * ELcmd_k;

  /* W22 Elevator cmd */
  z_augm_k[6] = b_W23d.c * xw23_k + b_W23d.d * AILcmd_k;

  /* W23 Aileron cmd */
  z_augm_k[7] = b_W24d.c * xw24_k + b_W24d.d * RDRcmd_k;

  /* W24 Rudder cmd */
  z_augm_k[8] = b_W31d.c * xw31_k + b_W31d.d * VT_k;

  /* W31 VT */
  z_augm_k[9] = b_W32d.c * xw32_k + b_W32d.d * theta_k;

  /* W32 theta */
  z_augm_k[10] = b_W33d.c * xw33_k + b_W33d.d * phi_k;

  /* W33 phi */
  z_augm_k[11] = b_W34d.c * xw34_k + b_W34d.d * beta_k;

  /* W34 beta */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_nmpc_iteration(real_T sw, boolean_T home_cmd, real_T
  b_dt, real_T b_TR, uint8_T wpts_fp, uint8_T wpts_rp, const real_T wpts_h[32],
  const real_T wpts_n[32], const real_T wpts_e[32], const real_T wpts_v[32],
  const real_T n_op_N[21], const real_T e_op_N[21], const real_T h_op_N[21],
  const real_T vn_op_N[21], const real_T ve_op_N[21], const real_T vh_op_N[21],
  const real_T u_hor[84], const real_T z_hor[252], const real_T n_hor[21], const
  real_T e_hor[21], const real_T h_hor[21], const real_T THL_hor[21], const
  real_T EL_hor[21], const real_T AIL_hor[21], const real_T RDR_hor[21], const
  real_T VT_hor[21], const real_T alpha_hor[21], const real_T beta_hor[21],
  const real_T phi_hor[21], const real_T theta_hor[21], const real_T psi_hor[21],
  const real_T P_hor[21], const real_T Q_hor[21], const real_T R_hor[21], const
  real_T wpt_index_hor[21], const real_T start_wpt_hor[63], const real_T
  pic_cic_hor[21], const real_T home_reset_hor[21], const real_T alphadot_hor[21],
  const real_T betadot_hor[21], const real_T ro_hor[21], const real_T xw11_hor
  [21], const real_T xw12_hor[21], const real_T xw13_hor[21], const real_T
  xw14_hor[21], const real_T xw21_hor[21], const real_T xw22_hor[21], const
  real_T xw23_hor[21], const real_T xw24_hor[21], const real_T xw31_hor[21],
  const real_T xw32_hor[21], const real_T xw33_hor[21], const real_T xw34_hor[21],
  const struct_4Fd1bnpyLecBuwBUBUAQfC b_W11d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W12d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W13d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W14d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W21d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W22d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W23d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W24d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W31d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W32d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W33d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W34d, real_T b_rho, real_T b_S, real_T b_Cbar, real_T b_b, real_T b_weight,
  real_T b_g, real_T b_IxxB, real_T b_IyyB, real_T b_IzzB, real_T b_IxzB, real_T
  b_CDu, real_T b_CDq, real_T b_CDadot, real_T b_CDde, real_T b_CD0_bar, real_T
  b_Cyb, real_T b_Cyp, real_T b_Cyr, real_T b_Cyda, real_T b_Cydr, real_T b_CL0,
  real_T b_CLa, real_T b_CLq, real_T b_CLadot, real_T b_CLu, real_T b_CLde,
  real_T b_Clb, real_T b_Clp, real_T b_Clr, real_T b_Clda, real_T b_Cldr, real_T
  b_Cm0, real_T b_Cma, real_T b_Cmq, real_T b_Cmadot, real_T b_Cmu, real_T
  b_Cmde, real_T b_Cnb, real_T b_Cnp, real_T b_Cnr, real_T b_Cnda, real_T b_Cndr,
  real_T b_xT0, real_T b_xT1, real_T b_xT2, real_T b_Ptrim, real_T b_Qtrim,
  real_T b_Rtrim, real_T b_Utrim, real_T b_Athrottle, real_T b_Bthrottle, real_T
  b_Aelevator, real_T b_Belevator, real_T b_Aaileron, real_T b_Baileron, real_T
  b_Arudder, real_T b_Brudder, real_T b_ThrottleMax, real_T b_ThrottleMin,
  real_T b_ElevatorMax, real_T b_ElevatorMin, real_T b_AileronMax, real_T
  b_AileronMin, real_T b_RudderMax, real_T b_RudderMin, real_T b_KpLat, real_T
  b_KiLon, real_T b_KpLon, real_T b_L, real_T b_dist2b, real_T FL_ann, const
  real_T a_ann_X[40], const real_T b_ann_X[40], real_T c_ann_X, const real_T
  w_ann_X[280], const real_T a_ann_Y[40], const real_T b_ann_Y[40], real_T
  c_ann_Y, const real_T w_ann_Y[280], const real_T a_ann_Z[40], const real_T
  b_ann_Z[40], real_T c_ann_Z, const real_T w_ann_Z[280], const real_T
  b_X_minXin[7], const real_T b_X_maxXin[7], real_T b_X_minYin, real_T
  b_X_maxYin, real_T b_X_minXout, real_T b_X_maxXout, real_T b_X_minYout, real_T
  b_X_maxYout, const real_T b_Y_minXin[7], const real_T b_Y_maxXin[7], real_T
  b_Y_minYin, real_T b_Y_maxYin, real_T b_Y_minXout, real_T b_Y_maxXout, real_T
  b_Y_minYout, real_T b_Y_maxYout, const real_T b_Z_minXin[7], const real_T
  b_Z_maxXin[7], real_T b_Z_minYin, real_T b_Z_maxYin, real_T b_Z_minXout,
  real_T b_Z_maxXout, real_T b_Z_minYout, real_T b_Z_maxYout, real_T u_nmpc[84],
  real_T *V_nmpc)
{
  real_T v_nmpc[480];
  real_T gradV_nmpc[80];
  real_T deltaV_nmpc[80];
  real_T u_nmpc_temp[80];
  real_T RDR_k;
  real_T VT_k;
  real_T alpha_k;
  real_T beta_k;
  real_T phi_k;
  real_T theta_k;
  real_T psi_k;
  real_T P_k;
  real_T Q_k;
  real_T R_k;
  real_T n_k;
  real_T e_k;
  real_T h_k;
  real_T ro_k;
  real_T alphadot_k;
  real_T betadot_k;
  real_T xw11_k;
  real_T xw12_k;
  real_T xw13_k;
  real_T xw14_k;
  real_T xw21_k;
  real_T xw22_k;
  real_T xw23_k;
  real_T xw24_k;
  real_T xw31_k;
  real_T xw32_k;
  real_T xw33_k;
  real_T xw34_k;
  real_T z_k[12];
  int8_T constrMIN_ext[80];
  int8_T constrMAX_ext[80];
  boolean_T constrMIN[20];
  boolean_T constrMAX[20];
  real_T pMIN;
  real_T pMAX;
  real_T p_nmpc;
  real32_T unusedU2;
  uint8_T unusedU3;
  real_T unusedU4[3];
  real_T unusedU5;
  uint8_T unusedU6;
  real_T unusedU7;
  real_T unusedU8;
  real_T unusedU9;
  real_T unusedUa;
  real_T unusedUb;
  real_T unusedUc;
  real_T unusedUd;
  real_T unusedUe;
  real_T unusedU10;
  real_T unusedU11;
  real_T unusedU12;
  real_T unusedU13;
  real_T unusedU14;
  real_T unusedU15;
  real_T unusedU16;
  real_T unusedU17[4];
  real_T THL_kk;
  real_T EL_kk;
  real_T AIL_kk;
  real_T RDR_kk;
  real_T VT_kk;
  real_T alpha_kk;
  real_T beta_kk;
  real_T phi_kk;
  real_T theta_kk;
  real_T psi_kk;
  real_T P_kk;
  real_T Q_kk;
  real_T R_kk;
  real_T falpha_k;
  real_T fbeta_k;
  real_T n_kk;
  real_T e_kk;
  real_T h_kk;
  real_T ro_kk;
  real_T xw11_kk;
  real_T xw12_kk;
  real_T xw13_kk;
  real_T xw14_kk;
  real_T xw21_kk;
  real_T xw22_kk;
  real_T xw23_kk;
  real_T xw24_kk;
  real_T xw31_kk;
  real_T xw32_kk;
  real_T xw33_kk;
  real_T xw34_kk;
  int32_T y;
  int32_T ab;
  int32_T idx;
  int32_T b_k;
  int32_T b_m;
  int32_T ia;
  static const int8_T c_a[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const int16_T d_a[144] = { 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000 };

  boolean_T exitg4;
  boolean_T guard1;
  boolean_T u_nmpc_temp_0[40];
  real_T wpts_h_0[32];
  real_T wpts_n_0[32];
  real_T wpts_e_0[32];
  int32_T i;
  real_T tmp[12];
  int8_T lambda_indexMIN_ext_data[80];
  int8_T lambda_indexMAX_ext_data[80];
  real_T gradL_nmpc_data[120];
  real_T deltaL_nmpc_data[120];
  int16_T db_data[240];
  int32_T b_a_sizes[2];
  int8_T ii_data[20];
  int8_T c_ii_data[20];
  int8_T e_ii_data[80];
  int32_T hessianL_nmpc_sizes[2];
  int32_T idx_data[120];
  int32_T ii_sizes_idx_1;
  int32_T c_ii_sizes_idx_1;
  int32_T e_ii_sizes_idx_1;
  int32_T lambda_indexMIN_ext_sizes_idx_1;
  uint8_T tmp_0;
  int32_T exitg1;

  /* %embedded definitions - by assuming p_nmpc=2*N_nmpc we have: */
  memset(&NMPC_Controller_B.A_c[0], 0, 3200U * sizeof(real_T));

  /* [2*N_nmpc,nu*N_nmpc] */
  memset(&NMPC_Controller_B.hessianL_nmpc[0], 0, 14400U * sizeof(real_T));

  /* [nu*N_nmpc+2*N_nmpc,nu*N_nmpc+2*N_nmpc] */
  /* %NMPC numerical perturbation */
  /* 0.001 */
  /* %%%mpc variable allocation%% */
  /*  Rs_nmpc=zeros(1,nu*N_nmpc); */
  memset(&u_nmpc[0], 0, 84U * sizeof(real_T));
  memset(&NMPC_Controller_B.z_it_nmpc[0], 0, 20160U * sizeof(real_T));

  /* v_nmpc=zeros(nz*N_nmpc+nu*N_nmpc,2); */
  memset(&v_nmpc[0], 0, 480U * sizeof(real_T));

  /* J_nmpc=zeros(nz*N_nmpc+nu*N_nmpc,nu*N_nmpc); */
  memset(&NMPC_Controller_B.J_nmpc[0], 0, 19200U * sizeof(real_T));

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
  for (idx = 0; idx < 80; idx++) {
    /* %%%variables definition%% */
    /* %servo states%% */
    pMIN = THL_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    pMAX = EL_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    p_nmpc = AIL_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    RDR_k = RDR_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];

    /* %uav states%% */
    VT_k = VT_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    alpha_k = alpha_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    beta_k = beta_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    phi_k = phi_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    theta_k = theta_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    psi_k = psi_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    P_k = P_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    Q_k = Q_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    R_k = R_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];

    /* %uav inertial position%% */
    n_k = n_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    e_k = e_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    h_k = h_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];

    /* %long. integrator state */
    ro_k = ro_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];

    /* %auxiliary variables */
    alphadot_k = alphadot_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    betadot_k = betadot_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw11_k = rt_roundd_snf(wpt_index_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0)
      - 1]);
    if (xw11_k < 256.0) {
      if (xw11_k >= 0.0) {
        tmp_0 = (uint8_T)xw11_k;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    i = (int32_T)ceil((1.0 + (real_T)idx) / 4.0);
    y = (int32_T)ceil((1.0 + (real_T)idx) / 4.0);
    ab = (int32_T)ceil((1.0 + (real_T)idx) / 4.0);

    /* %robustness */
    xw11_k = xw11_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw12_k = xw12_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw13_k = xw13_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw14_k = xw14_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw21_k = xw21_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw22_k = xw22_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw23_k = xw23_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw24_k = xw24_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw31_k = xw31_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw32_k = xw32_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw33_k = xw33_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];
    xw34_k = xw34_hor[(int32_T)ceil((1.0 + (real_T)idx) / 4.0) - 1];

    /* %nmpc output */
    b_k = (int32_T)ceil((1.0 + (real_T)idx) / 4.0);
    memcpy(&z_k[0], &z_hor[(b_k - 1) * 12], 12U * sizeof(real_T));
    for (ia = 0; ia < 21; ia++) {
      /* %forming nmpc state before perturbation */
      if (1 + ia < (int32_T)ceil((1.0 + (real_T)idx) / 4.0)) {
        memcpy(&NMPC_Controller_B.z_it_nmpc[12 * ia + 252 * idx], &z_hor[12 * ia],
               12U * sizeof(real_T));
      }

      /* %forming nmpc state after perturbation */
      if (1 + ia >= (int32_T)ceil((1.0 + (real_T)idx) / 4.0)) {
        memcpy(&NMPC_Controller_B.z_it_nmpc[12 * ia + 252 * idx], &z_k[0], 12U *
               sizeof(real_T));

        /* %command with perturbation at time k%% */
        /* %propagating */
        /*  %assumed zero wind */
        unusedU4[0] = start_wpt_hor[(i - 1) * 3];
        unusedU4[1] = start_wpt_hor[(i - 1) * 3 + 1];
        unusedU4[2] = start_wpt_hor[(i - 1) * 3 + 2];
        for (b_k = 0; b_k < 32; b_k++) {
          wpts_h_0[b_k] = wpts_h[b_k];
          wpts_n_0[b_k] = wpts_n[b_k];
          wpts_e_0[b_k] = wpts_e[b_k];
        }

        NMPC_Controller_uas_augm_model_bm(sw, home_cmd, b_dt, b_TR, wpts_fp,
          wpts_rp, wpts_h_0, wpts_n_0, wpts_e_0, wpts_v, n_op_N[ia], e_op_N[ia],
          h_op_N[ia], vn_op_N[ia], ve_op_N[ia], vh_op_N[ia], alphadot_k,
          betadot_k, tmp_0, unusedU4, pic_cic_hor[y - 1], home_reset_hor[ab - 1],
          pMIN, pMAX, p_nmpc, RDR_k, VT_k, alpha_k, beta_k, phi_k, theta_k,
          psi_k, P_k, Q_k, R_k, n_k, e_k, h_k, ro_k, u_hor[ia << 2] + 0.0001 *
          (real_T)(((1 + ia) << 2) - 3 == 1 + idx), u_hor[1 + (ia << 2)] +
          0.0001 * (real_T)(((1 + ia) << 2) - 2 == 1 + idx), u_hor[2 + (ia << 2)]
          + 0.0001 * (real_T)(((1 + ia) << 2) - 1 == 1 + idx), u_hor[3 + (ia <<
          2)] + 0.0001 * (real_T)((1 + ia) << 2 == 1 + idx), xw11_k, xw12_k,
          xw13_k, xw14_k, xw21_k, xw22_k, xw23_k, xw24_k, xw31_k, xw32_k, xw33_k,
          xw34_k, b_W11d, b_W12d, b_W13d, b_W14d, b_W21d, b_W22d, b_W23d, b_W24d,
          b_W31d, b_W32d, b_W33d, b_W34d, b_rho, b_S, b_Cbar, b_b, b_weight, b_g,
          b_IxxB, b_IyyB, b_IzzB, b_IxzB, b_CDu, b_CDq, b_CDadot, b_CDde,
          b_CD0_bar, b_Cyb, b_Cyp, b_Cyr, b_Cyda, b_Cydr, b_CL0, b_CLa, b_CLq,
          b_CLadot, b_CLu, b_CLde, b_Clb, b_Clp, b_Clr, b_Clda, b_Cldr, b_Cm0,
          b_Cma, b_Cmq, b_Cmadot, b_Cmu, b_Cmde, b_Cnb, b_Cnp, b_Cnr, b_Cnda,
          b_Cndr, b_xT0, b_xT1, b_xT2, b_Ptrim, b_Qtrim, b_Rtrim, b_Utrim,
          b_Athrottle, b_Bthrottle, b_Aelevator, b_Belevator, b_Aaileron,
          b_Baileron, b_Arudder, b_Brudder, b_ThrottleMax, b_ThrottleMin,
          b_ElevatorMax, b_ElevatorMin, b_AileronMax, b_AileronMin, b_RudderMax,
          b_RudderMin, b_KpLat, b_KiLon, b_KpLon, b_L, b_dist2b, FL_ann, a_ann_X,
          b_ann_X, c_ann_X, w_ann_X, a_ann_Y, b_ann_Y, c_ann_Y, w_ann_Y, a_ann_Z,
          b_ann_Z, c_ann_Z, w_ann_Z, b_X_minXin, b_X_maxXin, b_X_minYin,
          b_X_maxYin, b_X_minXout, b_X_maxXout, b_X_minYout, b_X_maxYout,
          b_Y_minXin, b_Y_maxXin, b_Y_minYin, b_Y_maxYin, b_Y_minXout,
          b_Y_maxXout, b_Y_minYout, b_Y_maxYout, b_Z_minXin, b_Z_maxXin,
          b_Z_minYin, b_Z_maxYin, b_Z_minXout, b_Z_maxXout, b_Z_minYout,
          b_Z_maxYout, &unusedU2, &unusedU3, &unusedU5, &unusedU6, &unusedU7,
          &unusedU8, &unusedU9, &unusedUa, &unusedUb, &unusedUc, &unusedUd,
          &unusedUe, &unusedU10, &unusedU11, &unusedU12, &unusedU13, &unusedU14,
          &unusedU15, &unusedU16, z_k, unusedU17, &THL_kk, &EL_kk, &AIL_kk,
          &RDR_kk, &VT_kk, &alpha_kk, &beta_kk, &phi_kk, &theta_kk, &psi_kk,
          &P_kk, &Q_kk, &R_kk, &falpha_k, &fbeta_k, &n_kk, &e_kk, &h_kk, &ro_kk,
          &xw11_kk, &xw12_kk, &xw13_kk, &xw14_kk, &xw21_kk, &xw22_kk, &xw23_kk,
          &xw24_kk, &xw31_kk, &xw32_kk, &xw33_kk, &xw34_kk);

        /* %%%next step kk-->k%%%%%%%%%%%%%% */
        /* %predicted servo states%% */
        pMIN = THL_kk;
        pMAX = EL_kk;
        p_nmpc = AIL_kk;
        RDR_k = RDR_kk;

        /* %predicted uav states%% */
        VT_k = VT_kk;
        alpha_k = alpha_kk;
        beta_k = beta_kk;
        phi_k = phi_kk;
        theta_k = theta_kk;
        psi_k = psi_kk;
        P_k = P_kk;
        Q_k = Q_kk;
        R_k = R_kk;
        alphadot_k = falpha_k;
        betadot_k = fbeta_k;

        /* %predicted uav inertial position%% */
        n_k = n_kk;
        e_k = e_kk;
        h_k = h_kk;

        /* %predicted longitudinal integrator state%% */
        ro_k = ro_kk;

        /* %robustness */
        xw11_k = xw11_kk;
        xw12_k = xw12_kk;
        xw13_k = xw13_kk;
        xw14_k = xw14_kk;
        xw21_k = xw21_kk;
        xw22_k = xw22_kk;
        xw23_k = xw23_kk;
        xw24_k = xw24_kk;
        xw31_k = xw31_kk;
        xw32_k = xw32_kk;
        xw33_k = xw33_kk;
        xw34_k = xw34_kk;
      }
    }

    /* i */
  }

  /* j */
  /* %%%gradient, jacobian and u_mpc correction */
  /* %v vector */
  for (idx = 0; idx < 20; idx++) {
    /* [nz*N_nmpc+nu*N_nmpc,2] */
    y = (1 + idx) * (int32_T)NMPC_Controller_nz - 12;
    ab = (1 + idx) * (int32_T)NMPC_Controller_nz;
    if (y + 1 > ab) {
      y = 0;
      ab = 0;
    }

    c_ii_sizes_idx_1 = ab - y;
    ii_sizes_idx_1 = ab - y;
    for (i = 0; i < ii_sizes_idx_1; i++) {
      db_data[i] = (int16_T)(y + i);
    }

    for (i = 0; i < 12; i++) {
      z_k[i] = 0.0;
      for (b_k = 0; b_k < 12; b_k++) {
        z_k[i] += z_hor[(idx + 1) * 12 + b_k] * (real_T)c_a[12 * b_k + i];
      }
    }

    for (i = 0; i < c_ii_sizes_idx_1; i++) {
      v_nmpc[db_data[i]] = z_k[i];
    }

    /*      v_nmpc(nu*i-nu+1+nz*N_nmpc:nu*i+nz*N_nmpc,1)=diag(Rs_nmpc(1,nu*i-nu+1:nu*i))*u_nmpc(:,i); */
  }

  /* %jacobian matrix */
  for (idx = 0; idx < 80; idx++) {
    /* [nz*N_nmpc+nu*N_nmpc,nu*N_nmpc] */
    for (y = 0; y < 20; y++) {
      ab = (1 + y) * (int32_T)NMPC_Controller_nz - 12;
      ia = (1 + y) * (int32_T)NMPC_Controller_nz;
      if (ab + 1 > ia) {
        ab = 0;
        ia = 0;
      }

      c_ii_sizes_idx_1 = ia - ab;
      ii_sizes_idx_1 = ia - ab;
      for (i = 0; i < ii_sizes_idx_1; i++) {
        db_data[i] = (int16_T)(ab + i);
      }

      NMPC_Controller_squeeze(*(real_T (*)[12])&NMPC_Controller_B.z_it_nmpc[(1 +
        y) * 12 + 252 * idx], z_k);
      for (i = 0; i < 12; i++) {
        tmp[i] = z_k[i] - z_hor[(y + 1) * 12 + i];
      }

      for (i = 0; i < 12; i++) {
        z_k[i] = 0.0;
        for (b_k = 0; b_k < 12; b_k++) {
          z_k[i] += (real_T)d_a[12 * b_k + i] * tmp[b_k];
        }
      }

      for (i = 0; i < c_ii_sizes_idx_1; i++) {
        NMPC_Controller_B.J_nmpc[db_data[i] + 240 * idx] = z_k[i];
      }
    }

    /*          J_nmpc(j+nz*N_nmpc,j)=Rs_nmpc(1,j); */
  }

  /* %gradient and hessian */
  for (i = 0; i < 80; i++) {
    gradV_nmpc[i] = 0.0;
    for (b_k = 0; b_k < 240; b_k++) {
      gradV_nmpc[i] += NMPC_Controller_B.J_nmpc[240 * i + b_k] * 2.0 *
        v_nmpc[b_k];
    }
  }

  /* [nu*N_nmpc,1] */
  for (i = 0; i < 80; i++) {
    for (b_k = 0; b_k < 80; b_k++) {
      NMPC_Controller_B.J_nmpc_m[i + 80 * b_k] = 0.0;
      for (c_ii_sizes_idx_1 = 0; c_ii_sizes_idx_1 < 240; c_ii_sizes_idx_1++) {
        NMPC_Controller_B.J_nmpc_m[i + 80 * b_k] += NMPC_Controller_B.J_nmpc[240
          * i + c_ii_sizes_idx_1] * NMPC_Controller_B.J_nmpc[240 * b_k +
          c_ii_sizes_idx_1];
      }
    }
  }

  for (i = 0; i < 80; i++) {
    for (b_k = 0; b_k < 80; b_k++) {
      NMPC_Controller_B.hessianV_nmpc[b_k + 80 * i] =
        NMPC_Controller_B.J_nmpc_m[80 * i + b_k] * 2.0;
    }
  }

  /* [nu*N_nmpc,nu*N_nmpc] */
  NMPC_Controller_mpower(NMPC_Controller_B.hessianV_nmpc,
    NMPC_Controller_B.J_nmpc_m);
  for (i = 0; i < 80; i++) {
    deltaV_nmpc[i] = 0.0;
    for (b_k = 0; b_k < 80; b_k++) {
      deltaV_nmpc[i] += NMPC_Controller_B.J_nmpc_m[80 * b_k + i] *
        gradV_nmpc[b_k];
    }
  }

  /* [nu*N_nmpc,1] */
  for (i = 0; i < 20; i++) {
    u_nmpc[i << 2] = u_hor[i << 2] - deltaV_nmpc[i << 2];
  }

  for (i = 0; i < 20; i++) {
    u_nmpc[1 + (i << 2)] = u_hor[(i << 2) + 1] - deltaV_nmpc[(i << 2) + 1];
  }

  for (i = 0; i < 20; i++) {
    u_nmpc[2 + (i << 2)] = u_hor[(i << 2) + 2] - deltaV_nmpc[(i << 2) + 2];
  }

  for (i = 0; i < 20; i++) {
    u_nmpc[3 + (i << 2)] = u_hor[(i << 2) + 3] - deltaV_nmpc[(i << 2) + 3];
  }

  /* %constraints correction%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %saturation limits */
  /* 1.0 */
  /* 0.1 */
  memset(&deltaV_nmpc[0], 0, 80U * sizeof(real_T));

  /* [nu*N_nmpc,1] */
  for (i = 0; i < 20; i++) {
    u_nmpc_temp[i << 2] = u_nmpc[i << 2];
    u_nmpc_temp[1 + (i << 2)] = u_nmpc[(i << 2) + 1];
    u_nmpc_temp[2 + (i << 2)] = u_nmpc[(i << 2) + 2];
    u_nmpc_temp[3 + (i << 2)] = u_nmpc[(i << 2) + 3];
  }

  /* [nu,N_nmpc] */
  for (i = 0; i < 80; i++) {
    constrMIN_ext[i] = 0;
    constrMAX_ext[i] = 0;
  }

  do {
    exitg1 = 0;
    for (i = 0; i < 20; i++) {
      u_nmpc_temp_0[i] = (u_nmpc_temp[i << 2] < b_ThrottleMin - 0.0001);
    }

    for (i = 0; i < 20; i++) {
      u_nmpc_temp_0[i + 20] = (u_nmpc_temp[i << 2] > b_ThrottleMax + 0.0001);
    }

    if (NMPC_Controller_sum(u_nmpc_temp_0) > 0.0) {
      /* [1,N_nmpc] */
      for (i = 0; i < 20; i++) {
        constrMIN[i] = (u_nmpc_temp[i << 2] < b_ThrottleMin + 0.0001);
        constrMAX[i] = (u_nmpc_temp[i << 2] > b_ThrottleMax - 0.0001);
      }

      /* [1,N_nmpc] */
      idx = 0;
      y = 1;
      exitg4 = false;
      while ((!exitg4) && (y < 21)) {
        guard1 = false;
        if (constrMIN[y - 1]) {
          idx++;
          ii_data[idx - 1] = (int8_T)y;
          if (idx >= 20) {
            exitg4 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          y++;
        }
      }

      if (1 > idx) {
        ii_sizes_idx_1 = 0;
      } else {
        ii_sizes_idx_1 = idx;
      }

      /* [1,pMIN] */
      idx = 0;
      y = 1;
      exitg4 = false;
      while ((!exitg4) && (y < 21)) {
        guard1 = false;
        if (constrMAX[y - 1]) {
          idx++;
          c_ii_data[idx - 1] = (int8_T)y;
          if (idx >= 20) {
            exitg4 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          y++;
        }
      }

      if (1 > idx) {
        c_ii_sizes_idx_1 = 0;
      } else {
        c_ii_sizes_idx_1 = idx;
      }

      /* [1,pMAX] */
      for (i = 0; i < 20; i++) {
        constrMIN_ext[i << 2] = (int8_T)constrMIN[i];
      }

      /* [1,nu*N_nmpc] */
      for (i = 0; i < 20; i++) {
        constrMAX_ext[i << 2] = (int8_T)constrMAX[i];
      }

      /* [1,nu*N_nmpc] */
      idx = 0;
      y = 1;
      exitg4 = false;
      while ((!exitg4) && (y < 81)) {
        guard1 = false;
        if (constrMIN_ext[y - 1] != 0) {
          idx++;
          e_ii_data[idx - 1] = (int8_T)y;
          if (idx >= 80) {
            exitg4 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          y++;
        }
      }

      if (1 > idx) {
        e_ii_sizes_idx_1 = 0;
      } else {
        e_ii_sizes_idx_1 = idx;
      }

      lambda_indexMIN_ext_sizes_idx_1 = e_ii_sizes_idx_1;
      for (i = 0; i < e_ii_sizes_idx_1; i++) {
        lambda_indexMIN_ext_data[i] = e_ii_data[i];
      }

      /* [1,pMIN] check! */
      idx = 0;
      y = 1;
      exitg4 = false;
      while ((!exitg4) && (y < 81)) {
        guard1 = false;
        if (constrMAX_ext[y - 1] != 0) {
          idx++;
          e_ii_data[idx - 1] = (int8_T)y;
          if (idx >= 80) {
            exitg4 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          y++;
        }
      }

      if (1 > idx) {
        e_ii_sizes_idx_1 = 0;
      } else {
        e_ii_sizes_idx_1 = idx;
      }

      for (i = 0; i < e_ii_sizes_idx_1; i++) {
        lambda_indexMAX_ext_data[i] = e_ii_data[i];
      }

      /* [1,pMAX] check! */
      pMIN = NMPC_Controller_sum_p(constrMIN);

      /* [1,1] */
      pMAX = NMPC_Controller_sum_p(constrMAX);

      /* [1,1] */
      p_nmpc = pMIN + pMAX;

      /* [1,1] */
      if (1.0 > p_nmpc) {
        idx = 0;
      } else {
        idx = (int32_T)p_nmpc;
      }

      for (i = 0; i < 80; i++) {
        for (b_k = 0; b_k < idx; b_k++) {
          NMPC_Controller_B.A_c[b_k + 40 * i] = 0.0;
        }
      }

      /* [p_nmpc,nu*N_nmpc] */
      for (idx = 0; idx < (int32_T)pMIN; idx++) {
        NMPC_Controller_B.A_c[idx + 40 * (lambda_indexMIN_ext_data[idx] - 1)] =
          -1.0;

        /* [pMIN,nu*N_nmpc] */
      }

      for (idx = 0; idx < (int32_T)pMAX; idx++) {
        NMPC_Controller_B.A_c[((int32_T)((1.0 + (real_T)idx) + pMIN) + 40 *
          (lambda_indexMAX_ext_data[idx] - 1)) - 1] = 1.0;

        /* [pMAX,nu*N_nmpc] */
      }

      /* %constraints */
      /*            %[p_nmpc,1] */
      /*                 %[nu*N_nmpc+p_nmpc,1] */
      for (i = 0; i < 80; i++) {
        gradL_nmpc_data[i] = gradV_nmpc[i] - deltaV_nmpc[i];
      }

      for (i = 0; i < ii_sizes_idx_1; i++) {
        gradL_nmpc_data[i + 80] = -u_hor[(ii_data[i] - 1) << 2] + b_ThrottleMin;
      }

      for (i = 0; i < c_ii_sizes_idx_1; i++) {
        gradL_nmpc_data[(i + ii_sizes_idx_1) + 80] = u_hor[(c_ii_data[i] - 1) <<
          2] - b_ThrottleMax;
      }

      c_ii_sizes_idx_1 = (int32_T)(80.0 + p_nmpc);
      ii_sizes_idx_1 = (int32_T)(80.0 + p_nmpc);
      for (i = 0; i < ii_sizes_idx_1; i++) {
        for (b_k = 0; b_k < c_ii_sizes_idx_1; b_k++) {
          NMPC_Controller_B.hessianL_nmpc[b_k + 120 * i] = 0.0;
        }
      }

      /* [nu*N_nmpc+p_nmpc,nu*N_nmpc+p_nmpc] */
      for (i = 0; i < 80; i++) {
        memcpy(&NMPC_Controller_B.hessianL_nmpc[120 * i],
               &NMPC_Controller_B.hessianV_nmpc[80 * i], 80U * sizeof(real_T));
      }

      /* block (1,1) */
      if (81.0 > 80.0 + p_nmpc) {
        idx = 0;
      } else {
        idx = 80;
      }

      if (1.0 > p_nmpc) {
        i = 0;
      } else {
        i = (int32_T)p_nmpc;
      }

      ii_sizes_idx_1 = i - 1;
      for (i = 0; i <= ii_sizes_idx_1; i++) {
        for (b_k = 0; b_k < 80; b_k++) {
          NMPC_Controller_B.hessianL_nmpc[b_k + 120 * (idx + i)] =
            -NMPC_Controller_B.A_c[40 * b_k + i];
        }
      }

      /* block (1,2) */
      if (81.0 > 80.0 + p_nmpc) {
        idx = 0;
      } else {
        idx = 80;
      }

      if (1.0 > p_nmpc) {
        i = 0;
      } else {
        i = (int32_T)p_nmpc;
      }

      ii_sizes_idx_1 = i - 1;
      for (i = 0; i < 80; i++) {
        for (b_k = 0; b_k <= ii_sizes_idx_1; b_k++) {
          NMPC_Controller_B.hessianL_nmpc[(idx + b_k) + 120 * i] =
            NMPC_Controller_B.A_c[40 * i + b_k];
        }
      }

      /* block (2,1) */
      ii_sizes_idx_1 = (int32_T)(80.0 + p_nmpc);
      c_ii_sizes_idx_1 = (int32_T)(80.0 + p_nmpc);
      hessianL_nmpc_sizes[0] = ii_sizes_idx_1;
      hessianL_nmpc_sizes[1] = c_ii_sizes_idx_1;
      for (i = 0; i < c_ii_sizes_idx_1; i++) {
        for (b_k = 0; b_k < ii_sizes_idx_1; b_k++) {
          NMPC_Controller_B.hessianL_nmpc_data[b_k + ii_sizes_idx_1 * i] =
            NMPC_Controller_B.hessianL_nmpc[120 * i + b_k];
        }
      }

      NMPC_Controller_mpower_h(NMPC_Controller_B.hessianL_nmpc_data,
        hessianL_nmpc_sizes, NMPC_Controller_B.b_a_data, b_a_sizes);
      b_k = b_a_sizes[1];
      b_m = b_a_sizes[0];
      c_ii_sizes_idx_1 = (int8_T)b_a_sizes[0];
      for (i = 0; i < c_ii_sizes_idx_1; i++) {
        deltaL_nmpc_data[i] = 0.0;
      }

      idx = 0;
      while (idx <= 0) {
        for (idx = 1; idx <= b_m; idx++) {
          deltaL_nmpc_data[idx - 1] = 0.0;
        }

        idx = b_m;
      }

      ii_sizes_idx_1 = 0;
      idx = 0;
      while (idx <= 0) {
        idx = 0;
        y = ii_sizes_idx_1 + b_k;
        for (ab = ii_sizes_idx_1; ab + 1 <= y; ab++) {
          if (gradL_nmpc_data[ab] != 0.0) {
            ia = idx;
            for (c_ii_sizes_idx_1 = 0; c_ii_sizes_idx_1 + 1 <= b_m;
                 c_ii_sizes_idx_1++) {
              ia++;
              deltaL_nmpc_data[c_ii_sizes_idx_1] +=
                NMPC_Controller_B.b_a_data[ia - 1] * gradL_nmpc_data[ab];
            }
          }

          idx += b_m;
        }

        ii_sizes_idx_1 += b_k;
        idx = b_m;
      }

      /* [nu*N_nmpc+p_nmpc,1] */
      for (i = 0; i < 20; i++) {
        u_nmpc_temp[i << 2] = u_hor[i << 2] - deltaL_nmpc_data[i << 2];
      }

      if (81.0 > 80.0 + pMIN) {
        idx = 1;
        y = 0;
      } else {
        idx = 81;
        y = (int32_T)(80.0 + pMIN);
      }

      for (i = 0; i < lambda_indexMIN_ext_sizes_idx_1; i++) {
        e_ii_data[i] = lambda_indexMIN_ext_data[i];
      }

      ii_sizes_idx_1 = y - idx;
      for (i = 0; i <= ii_sizes_idx_1; i++) {
        idx_data[i] = idx + i;
      }

      for (i = 0; i < lambda_indexMIN_ext_sizes_idx_1; i++) {
        deltaV_nmpc[e_ii_data[i] - 1] = -deltaL_nmpc_data[idx_data[i] - 1];
      }

      if ((80.0 + pMIN) + 1.0 > 80.0 + p_nmpc) {
        idx = 1;
        y = 0;
      } else {
        idx = (int32_T)((80.0 + pMIN) + 1.0);
        y = (int32_T)(80.0 + p_nmpc);
      }

      for (i = 0; i < e_ii_sizes_idx_1; i++) {
        e_ii_data[i] = lambda_indexMAX_ext_data[i];
      }

      ii_sizes_idx_1 = y - idx;
      for (i = 0; i <= ii_sizes_idx_1; i++) {
        idx_data[i] = idx + i;
      }

      for (i = 0; i < e_ii_sizes_idx_1; i++) {
        deltaV_nmpc[e_ii_data[i] - 1] = -deltaL_nmpc_data[idx_data[i] - 1];
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  for (i = 0; i < 20; i++) {
    u_nmpc[i << 2] = u_nmpc_temp[i << 2];
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
  for (idx = 0; idx < 20; idx++) {
    y = (1 + idx) * (int32_T)NMPC_Controller_nz - 12;
    ab = (1 + idx) * (int32_T)NMPC_Controller_nz;
    if (y + 1 > ab) {
      y = 0;
      ab = 0;
    }

    c_ii_sizes_idx_1 = ab - y;
    ii_sizes_idx_1 = ab - y;
    for (i = 0; i < ii_sizes_idx_1; i++) {
      db_data[i] = (int16_T)(y + i);
    }

    for (i = 0; i < 12; i++) {
      z_k[i] = 0.0;
      for (b_k = 0; b_k < 12; b_k++) {
        z_k[i] += z_hor[(idx + 1) * 12 + b_k] * (real_T)c_a[12 * b_k + i];
      }
    }

    for (i = 0; i < c_ii_sizes_idx_1; i++) {
      v_nmpc[240 + db_data[i]] = z_k[i];
    }

    /*      v_nmpc(nu*i-nu+1+nz*N_nmpc:nu*i+nz*N_nmpc,2)=diag(Rs_nmpc(1,nu*i-nu+1:nu*i))*u_nmpc(:,i); */
  }

  /* %Cost */
  *V_nmpc = 0.0;
  for (i = 0; i < 240; i++) {
    *V_nmpc += v_nmpc[240 + i] * v_nmpc[240 + i];
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
}

/* Function for MATLAB Function: '<Root>/Control System' */
static void NMPC_Controller_uas_augm_model_b(real_T sw, boolean_T home_cmd,
  real_T b_dt, real_T b_TR, uint8_T wpts_fp, uint8_T wpts_rp, real_T wpts_h[32],
  real_T wpts_n[32], real_T wpts_e[32], const real_T wpts_v[32], real_T n_op_k,
  real_T e_op_k, real_T h_op_k, real_T vn_op_k, real_T ve_op_k, real_T vh_op_k,
  real_T alphadot_k, real_T betadot_k, real_T wpt_index_k, real_T start_wpt_k[3],
  real_T pic_cic_k, real_T home_reset_k, real_T THL_k, real_T EL_k, real_T AIL_k,
  real_T RDR_k, real_T VT_k, real_T alpha_k, real_T beta_k, real_T phi_k, real_T
  theta_k, real_T psi_k, real_T P_k, real_T Q_k, real_T R_k, real_T n_k, real_T
  e_k, real_T h_k, real_T ro_k, real_T THLcmd_k, real_T ELcmd_k, real_T AILcmd_k,
  real_T RDRcmd_k, real_T xw11_k, real_T xw12_k, real_T xw13_k, real_T xw14_k,
  real_T xw21_k, real_T xw22_k, real_T xw23_k, real_T xw24_k, real_T xw31_k,
  real_T xw32_k, real_T xw33_k, real_T xw34_k, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W11d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W12d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W13d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W14d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W21d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W22d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W23d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W24d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W31d, const
  struct_4Fd1bnpyLecBuwBUBUAQfC b_W32d, const struct_4Fd1bnpyLecBuwBUBUAQfC
  b_W33d, const struct_4Fd1bnpyLecBuwBUBUAQfC b_W34d, real_T b_rho, real_T b_S,
  real_T b_Cbar, real_T b_b, real_T b_weight, real_T b_g, real_T b_IxxB, real_T
  b_IyyB, real_T b_IzzB, real_T b_IxzB, real_T b_CDu, real_T b_CDq, real_T
  b_CDadot, real_T b_CDde, real_T b_CD0_bar, real_T b_Cyb, real_T b_Cyp, real_T
  b_Cyr, real_T b_Cyda, real_T b_Cydr, real_T b_CL0, real_T b_CLa, real_T b_CLq,
  real_T b_CLadot, real_T b_CLu, real_T b_CLde, real_T b_Clb, real_T b_Clp,
  real_T b_Clr, real_T b_Clda, real_T b_Cldr, real_T b_Cm0, real_T b_Cma, real_T
  b_Cmq, real_T b_Cmadot, real_T b_Cmu, real_T b_Cmde, real_T b_Cnb, real_T
  b_Cnp, real_T b_Cnr, real_T b_Cnda, real_T b_Cndr, real_T b_xT0, real_T b_xT1,
  real_T b_xT2, real_T b_Ptrim, real_T b_Qtrim, real_T b_Rtrim, real_T b_Utrim,
  real_T b_Athrottle, real_T b_Bthrottle, real_T b_Aelevator, real_T b_Belevator,
  real_T b_Aaileron, real_T b_Baileron, real_T b_Arudder, real_T b_Brudder,
  real_T b_ThrottleMax, real_T b_ThrottleMin, real_T b_ElevatorMax, real_T
  b_ElevatorMin, real_T b_AileronMax, real_T b_AileronMin, real_T b_RudderMax,
  real_T b_RudderMin, real_T b_KpLat, real_T b_KiLon, real_T b_KpLon, real_T b_L,
  real_T b_dist2b, real_T FL_ann, const real_T a_ann_X[40], const real_T
  b_ann_X[40], real_T c_ann_X, const real_T w_ann_X[280], const real_T a_ann_Y
  [40], const real_T b_ann_Y[40], real_T c_ann_Y, const real_T w_ann_Y[280],
  const real_T a_ann_Z[40], const real_T b_ann_Z[40], real_T c_ann_Z, const
  real_T w_ann_Z[280], const real_T b_X_minXin[7], const real_T b_X_maxXin[7],
  real_T b_X_minYin, real_T b_X_maxYin, real_T b_X_minXout, real_T b_X_maxXout,
  real_T b_X_minYout, real_T b_X_maxYout, const real_T b_Y_minXin[7], const
  real_T b_Y_maxXin[7], real_T b_Y_minYin, real_T b_Y_maxYin, real_T b_Y_minXout,
  real_T b_Y_maxXout, real_T b_Y_minYout, real_T b_Y_maxYout, const real_T
  b_Z_minXin[7], const real_T b_Z_maxXin[7], real_T b_Z_minYin, real_T
  b_Z_maxYin, real_T b_Z_minXout, real_T b_Z_maxXout, real_T b_Z_minYout, real_T
  b_Z_maxYout, real32_T *distance2b, uint8_T *wpt_index_kk, real_T *pic_cic_kk,
  uint8_T *home_reset_kk, real_T *nr_k, real_T *er_k, real_T *hr_k, real_T
  *etaLon_k, real_T *etaLat_k, real_T *VTcmd_k, real_T *thetacmd_k, real_T
  *phicmd_k, real_T *Vab_k, real_T *accelX_scd_k, real_T *accelX_ann_k, real_T
  *accelY_scd_k, real_T *accelY_ann_k, real_T *accelZ_scd_k, real_T
  *accelZ_ann_k, real_T z_augm_k[12], real_T e_augm_k[4], real_T *THL_kk, real_T
  *EL_kk, real_T *AIL_kk, real_T *RDR_kk, real_T *VT_kk, real_T *alpha_kk,
  real_T *beta_kk, real_T *phi_kk, real_T *theta_kk, real_T *psi_kk, real_T
  *P_kk, real_T *Q_kk, real_T *R_kk, real_T *falpha_k, real_T *fbeta_k, real_T
  *n_kk, real_T *e_kk, real_T *h_kk, real_T *ro_kk, real_T *xw11_kk, real_T
  *xw12_kk, real_T *xw13_kk, real_T *xw14_kk, real_T *xw21_kk, real_T *xw22_kk,
  real_T *xw23_kk, real_T *xw24_kk, real_T *xw31_kk, real_T *xw32_kk, real_T
  *xw33_kk, real_T *xw34_kk)
{
  real_T mass;
  real_T delta_I;
  real_T c2;
  real_T c4;
  real_T Qbar_k;
  real_T U_k;
  real_T V_k;
  real_T W_k;
  real_T CL_k;
  real_T CD_k;
  real_T Cls_k;
  real_T Cms_k;
  real_T Cns_k;
  real_T Cl_k;
  real_T Cn_k;
  real_T Udot_k;
  real_T Vdot_k;
  real_T Wdot_k;
  real_T fn_k;
  real_T fe_k;
  real_T fh_k;
  uint8_T next_wpt_index;
  real_T ea;
  real_T hd_k;
  real_T nd_k;
  real_T ed_k;
  real_T atrack;
  int32_T factor;
  real_T btrack;
  real_T edot_track_k;
  real_T ndot_track_k;
  real_T r_a;
  real_T s_a;
  real_T t_a;
  real_T er_k_0[2];
  real_T er_k_1[3];
  real_T nr_k_0[2];
  real_T fn_k_0[2];
  real_T VT_k_0[7];
  real_T VT_k_1[7];
  real_T VT_k_2[7];
  real_T tmp[7];
  real_T w_ann_X_0[40];
  int32_T i;

  /* %temporary */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %mass and inertia coefficients%% */
  mass = b_weight / b_g;
  delta_I = b_IxxB * b_IzzB - b_IxzB * b_IxzB;
  c2 = ((b_IxxB - b_IyyB) + b_IzzB) * b_IxzB / delta_I;
  c4 = b_IxzB / delta_I;

  /* %dynamic pressure%% */
  Qbar_k = 0.5 * b_rho * (VT_k * VT_k);

  /* %body velocities%% */
  U_k = VT_k * cos(alpha_k) * cos(beta_k);
  V_k = VT_k * sin(beta_k);
  W_k = VT_k * sin(alpha_k) * cos(beta_k);

  /* %aerodynamic coefficients%% */
  CL_k = ((((Q_k - b_Qtrim) * b_CLq * b_Cbar / 2.0 / b_Utrim + (b_CLa * alpha_k
             + b_CL0)) + b_CLadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k
           - b_Utrim) * b_CLu / b_Utrim) + b_CLde * EL_k;

  /* CD_k=CD0+CDa*alpha_k+CDq*(Q_k-Qtrim)*Cbar/2/Utrim+CDadot*alphadot_k*Cbar/2/Utrim+CDu*(U_k-Utrim)/Utrim+CDde*EL_k; %lin */
  CD_k = ((((CL_k * CL_k / (3.1415926535897931 * b_b / b_Cbar * 0.87) +
             b_CD0_bar) + (Q_k - b_Qtrim) * b_CDq * b_Cbar / 2.0 / b_Utrim) +
           b_CDadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k - b_Utrim) *
          b_CDu / b_Utrim) + b_CDde * EL_k;

  /* nonlin */
  Cls_k = ((((P_k - b_Ptrim) * b_Clp * b_b / 2.0 / b_Utrim + b_Clb * beta_k) +
            (R_k - b_Rtrim) * b_Clr * b_b / 2.0 / b_Utrim) + b_Clda * AIL_k) +
    b_Cldr * RDR_k;
  Cms_k = ((((Q_k - b_Qtrim) * b_Cmq * b_Cbar / 2.0 / b_Utrim + (b_Cma * alpha_k
              + b_Cm0)) + b_Cmadot * alphadot_k * b_Cbar / 2.0 / b_Utrim) + (U_k
            - b_Utrim) * b_Cmu / b_Utrim) + b_Cmde * EL_k;
  Cns_k = ((((P_k - b_Ptrim) * b_Cnp * b_b / 2.0 / b_Utrim + b_Cnb * beta_k) +
            (R_k - b_Rtrim) * b_Cnr * b_b / 2.0 / b_Utrim) + b_Cnda * AIL_k) +
    b_Cndr * RDR_k;
  Cl_k = Cls_k * cos(alpha_k) - Cns_k * sin(alpha_k);
  Cn_k = Cls_k * sin(alpha_k) + Cns_k * cos(alpha_k);

  /* %engine thrust%% */
  Cls_k = 100.0 * THL_k;

  /* %S&C aerodynamic and thrust linear accelerations%% */
  *accelX_scd_k = (((Cls_k * Cls_k * b_xT2 + 100.0 * THL_k * b_xT1) + b_xT0) + (
    -CD_k * cos(alpha_k) + CL_k * sin(alpha_k)) * (Qbar_k * b_S)) / mass;

  /* [ft/s2] */
  *accelY_scd_k = (((((P_k - b_Ptrim) * b_Cyp * b_b / 2.0 / b_Utrim + b_Cyb *
                      beta_k) + (R_k - b_Rtrim) * b_Cyr * b_b / 2.0 / b_Utrim) +
                    b_Cyda * AIL_k) + b_Cydr * RDR_k) * (Qbar_k * b_S) / mass;

  /* [ft/s2] */
  *accelZ_scd_k = (-CD_k * sin(alpha_k) - CL_k * cos(alpha_k)) * (Qbar_k * b_S) /
    mass;

  /* [ft/s2] */
  /* ANN linear accelerations */
  /* X-axis */
  VT_k_2[0] = VT_k;
  VT_k_2[1] = alpha_k;
  VT_k_2[2] = beta_k;
  VT_k_2[3] = Q_k;
  VT_k_2[4] = alphadot_k;
  VT_k_2[5] = THL_k;
  VT_k_2[6] = EL_k;
  NMPC_Controller_ann_norm_X(VT_k_2, b_X_minXin, b_X_maxXin, b_X_minYin,
    b_X_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_X[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_X[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_X[factor] * w_ann_X_0[factor];
  }

  *accelX_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_X, b_X_minXout,
    b_X_maxXout, b_X_minYout, b_X_maxYout) * b_g;

  /* [ft/s2] no tansig */
  /* Y_axis */
  VT_k_1[0] = VT_k;
  VT_k_1[1] = beta_k;
  VT_k_1[2] = P_k;
  VT_k_1[3] = R_k;
  VT_k_1[4] = betadot_k;
  VT_k_1[5] = AIL_k;
  VT_k_1[6] = RDR_k;
  NMPC_Controller_ann_norm_X(VT_k_1, b_Y_minXin, b_Y_maxXin, b_Y_minYin,
    b_Y_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_Y[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_Y[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_Y[factor] * w_ann_X_0[factor];
  }

  *accelY_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_Y, b_Y_minXout,
    b_Y_maxXout, b_Y_minYout, b_Y_maxYout) * b_g;

  /* [ft/s2] no tansig */
  /* Z-axis */
  VT_k_0[0] = VT_k;
  VT_k_0[1] = alpha_k;
  VT_k_0[2] = beta_k;
  VT_k_0[3] = Q_k;
  VT_k_0[4] = alphadot_k;
  VT_k_0[5] = THL_k;
  VT_k_0[6] = EL_k;
  NMPC_Controller_ann_norm_X(VT_k_0, b_Z_minXin, b_Z_maxXin, b_Z_minYin,
    b_Z_maxYin, tmp);
  for (factor = 0; factor < 40; factor++) {
    r_a = 0.0;
    for (i = 0; i < 7; i++) {
      r_a += w_ann_Z[40 * i + factor] * tmp[i];
    }

    w_ann_X_0[factor] = r_a + b_ann_Z[factor];
  }

  r_a = 0.0;
  for (factor = 0; factor < 40; factor++) {
    r_a += a_ann_Z[factor] * w_ann_X_0[factor];
  }

  *accelZ_ann_k = NMPC_Controller_ann_denorm_Y(r_a + c_ann_Z, b_Z_minXout,
    b_Z_maxXout, b_Z_minYout, b_Z_maxYout) * b_g;

  /* [ft/s2] no tansig */
  Cls_k = 0.0;

  /* initialization */
  Cns_k = 0.0;

  /* initialization */
  mass = 0.0;

  /* initialization */
  if (FL_ann == 0.0) {
    /* scd */
    Cls_k = *accelX_scd_k;
    Cns_k = *accelY_scd_k;
    mass = *accelZ_scd_k;
  } else {
    if (FL_ann == 1.0) {
      /* ann */
      Cls_k = *accelX_ann_k;
      Cns_k = *accelY_ann_k;
      mass = *accelZ_ann_k;
    }
  }

  /* body accelerations */
  Udot_k = ((R_k * V_k - Q_k * W_k) - b_g * sin(theta_k)) + Cls_k;
  Vdot_k = ((P_k * W_k - R_k * U_k) + b_g * sin(phi_k) * cos(theta_k)) + Cns_k;
  Wdot_k = ((Q_k * U_k - P_k * V_k) + b_g * cos(phi_k) * cos(theta_k)) + mass;

  /* %inertial speed (with no wind)%% */
  fn_k = ((sin(phi_k) * sin(theta_k) * cos(psi_k) - cos(phi_k) * sin(psi_k)) *
          V_k + U_k * cos(theta_k) * cos(psi_k)) + (cos(phi_k) * sin(theta_k) *
    cos(psi_k) + sin(phi_k) * sin(psi_k)) * W_k;
  fe_k = ((sin(phi_k) * sin(theta_k) * sin(psi_k) + cos(phi_k) * cos(psi_k)) *
          V_k + U_k * cos(theta_k) * sin(psi_k)) + (cos(phi_k) * sin(theta_k) *
    sin(psi_k) - sin(phi_k) * cos(psi_k)) * W_k;
  fh_k = (U_k * sin(theta_k) - V_k * sin(phi_k) * cos(theta_k)) - W_k * cos
    (phi_k) * cos(theta_k);

  /* %inertial speed%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%uas at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* Local variable assignment */
  r_a = rt_roundd_snf(wpt_index_k);
  if (r_a < 256.0) {
    if (r_a >= 0.0) {
      *wpt_index_kk = (uint8_T)r_a;
    } else {
      *wpt_index_kk = 0U;
    }
  } else {
    *wpt_index_kk = MAX_uint8_T;
  }

  r_a = rt_roundd_snf(home_reset_k);
  if (r_a < 256.0) {
    if (r_a >= 0.0) {
      *home_reset_kk = (uint8_T)r_a;
    } else {
      *home_reset_kk = 0U;
    }
  } else {
    *home_reset_kk = MAX_uint8_T;
  }

  /* PIC/CIC Transition Logic: */
  /*  On transition to CIC or PIC, set index = 0 and current position to  */
  /*  current waypoint; hold current waypoint. */
  if ((sw > pic_cic_k) || (sw == 0.0)) {
    start_wpt_k[0] = h_k;
    start_wpt_k[1] = n_k;
    start_wpt_k[2] = e_k;
    *wpt_index_kk = 0U;
    *home_reset_kk = 0U;
  }

  /*  Change the waypoint index when home command */
  if ((home_cmd == 1) && (sw == 1.0) && (*home_reset_kk == 0)) {
    *wpt_index_kk = 23U;
    *home_reset_kk = 1U;
  }

  /* OP trajectory generation */
  /* %reassigning the a and b waypoints */
  if ((b_TR == 2.0) && (*home_reset_kk == 0)) {
    *wpt_index_kk = 1U;
    wpts_n[(int32_T)wpt_index_k - 1] = n_op_k - 100.0 * vn_op_k;
    wpts_n[(int32_T)(wpt_index_k + 1.0) - 1] = 100.0 * vn_op_k + n_op_k;
    wpts_e[(int32_T)wpt_index_k - 1] = e_op_k - 100.0 * ve_op_k;
    wpts_e[(int32_T)(wpt_index_k + 1.0) - 1] = 100.0 * ve_op_k + e_op_k;
    wpts_h[(int32_T)wpt_index_k - 1] = h_op_k - 100.0 * vh_op_k;
    wpts_h[(int32_T)(wpt_index_k + 1.0) - 1] = 100.0 * vh_op_k + h_op_k;
  }

  /* calculate the next waypoint index */
  factor = (int32_T)(*wpt_index_kk + 1U);
  if ((uint32_T)factor > 255U) {
    factor = 255;
  }

  next_wpt_index = (uint8_T)factor;

  /* beyond final point (fp), go to return point (rp) */
  if ((uint8_T)factor > wpts_fp) {
    next_wpt_index = wpts_rp;
  }

  /* calculate distance to next waypoint */
  Cls_k = n_k - wpts_n[next_wpt_index - 1];
  Cns_k = e_k - wpts_e[next_wpt_index - 1];
  Cls_k = sqrt(Cls_k * Cls_k + Cns_k * Cns_k);

  /* change to next waypoint if in range */
  if ((Cls_k < b_dist2b) && (sw == 1.0)) {
    /*  Do not change index if sw=0 */
    *wpt_index_kk = next_wpt_index;
    if (next_wpt_index == wpts_fp) {
      next_wpt_index = wpts_rp;
    } else {
      factor = (int32_T)(next_wpt_index + 1U);
      if ((uint32_T)factor > 255U) {
        factor = 255;
      }

      next_wpt_index = (uint8_T)factor;
    }
  }

  /* function outputs */
  if ((*wpt_index_kk == 0) || (*wpt_index_kk == 23)) {
    /*  Assign the speed of the starting segment to the speed of the first */
    /*  waypoint */
    *Vab_k = wpts_v[0];
    CL_k = start_wpt_k[0];
    CD_k = start_wpt_k[1];
    ea = start_wpt_k[2];
  } else {
    *Vab_k = wpts_v[*wpt_index_kk - 1];
    CL_k = wpts_h[*wpt_index_kk - 1];
    CD_k = wpts_n[*wpt_index_kk - 1];
    ea = wpts_e[*wpt_index_kk - 1];
  }

  *distance2b = (real32_T)Cls_k;
  *pic_cic_kk = sw;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %reference point r%% */
  Cls_k = wpts_h[next_wpt_index - 1] - CL_k;
  Cns_k = wpts_n[next_wpt_index - 1] - CD_k;
  mass = wpts_e[next_wpt_index - 1] - ea;
  Cls_k = (((wpts_h[next_wpt_index - 1] - CL_k) * (h_k - CL_k) +
            (wpts_n[next_wpt_index - 1] - CD_k) * (n_k - CD_k)) +
           (wpts_e[next_wpt_index - 1] - ea) * (e_k - ea)) / ((Cls_k * Cls_k +
    Cns_k * Cns_k) + mass * mass);
  hd_k = (wpts_h[next_wpt_index - 1] - CL_k) * Cls_k + CL_k;
  nd_k = (wpts_n[next_wpt_index - 1] - CD_k) * Cls_k + CD_k;
  ed_k = (wpts_e[next_wpt_index - 1] - ea) * Cls_k + ea;
  Cls_k = wpts_h[next_wpt_index - 1] - hd_k;
  Cns_k = wpts_n[next_wpt_index - 1] - nd_k;
  mass = wpts_e[next_wpt_index - 1] - ed_k;
  Cls_k = b_L / sqrt((Cls_k * Cls_k + Cns_k * Cns_k) + mass * mass);
  *er_k = (wpts_e[next_wpt_index - 1] - ed_k) * Cls_k + ed_k;
  *nr_k = (wpts_n[next_wpt_index - 1] - nd_k) * Cls_k + nd_k;
  *hr_k = (wpts_h[next_wpt_index - 1] - hd_k) * Cls_k + hd_k;

  /* %alpha and beta track%% */
  Cls_k = wpts_h[next_wpt_index - 1] - CL_k;
  Cns_k = wpts_n[next_wpt_index - 1] - CD_k;
  mass = wpts_e[next_wpt_index - 1] - ea;
  atrack = asin((wpts_h[next_wpt_index - 1] - CL_k) / sqrt((Cls_k * Cls_k +
    Cns_k * Cns_k) + mass * mass));
  Cls_k = wpts_n[next_wpt_index - 1] - CD_k;
  Cns_k = wpts_e[next_wpt_index - 1] - ea;
  factor = 1;
  mass = 0.0;
  if (!((wpts_n[next_wpt_index - 1] - CD_k > 0.0) && (wpts_e[next_wpt_index - 1]
        - ea > 0.0))) {
    if ((wpts_n[next_wpt_index - 1] - CD_k > 0.0) && (wpts_e[next_wpt_index - 1]
         - ea < 0.0)) {
      mass = 3.1415926535897931;
      factor = -1;
    } else {
      if ((wpts_n[next_wpt_index - 1] - CD_k < 0.0) && (wpts_e[next_wpt_index -
           1] - ea < 0.0)) {
        mass = -3.1415926535897931;
        factor = -1;
      }
    }
  }

  btrack = asin((wpts_n[next_wpt_index - 1] - CD_k) / sqrt(Cls_k * Cls_k + Cns_k
    * Cns_k)) * (real_T)factor + mass;

  /* %edot, ndot and hdot relative to track%% */
  edot_track_k = (sin(atrack) * cos(btrack) * fh_k + sin(btrack) * fn_k) + cos
    (atrack) * cos(btrack) * fe_k;
  ndot_track_k = (-sin(atrack) * sin(btrack) * fh_k + cos(btrack) * fn_k) - cos
    (atrack) * sin(btrack) * fe_k;

  /* %er-e, nr-n and hr-h relative to track%% */
  /* %etaLon at time [k]%% */
  nr_k_0[0] = *nr_k - n_k;
  nr_k_0[1] = *er_k - e_k;
  fn_k_0[0] = fn_k;
  fn_k_0[1] = fe_k;
  *etaLon_k = rt_atan2d_snf(*hr_k - h_k, NMPC_Controller_norm(nr_k_0)) -
    rt_atan2d_snf(fh_k, NMPC_Controller_norm(fn_k_0));

  /* %etaLat at time [k]%% */
  Cls_k = rt_atan2d_snf(ndot_track_k, edot_track_k) - rt_atan2d_snf((-sin(atrack)
    * sin(btrack) * (*hr_k - h_k) + (*nr_k - n_k) * cos(btrack)) - cos(atrack) *
    sin(btrack) * (*er_k - e_k), (sin(atrack) * cos(btrack) * (*hr_k - h_k) +
    (*nr_k - n_k) * sin(btrack)) + cos(atrack) * cos(btrack) * (*er_k - e_k));
  *etaLat_k = Cls_k;
  if (Cls_k > 3.1415926535897931) {
    *etaLat_k = Cls_k - 6.2831853071795862;
  }

  if (Cls_k < -3.1415926535897931) {
    *etaLat_k = Cls_k + 6.2831853071795862;
  }

  /* OP trajectory generation */
  /* reassigning Vab (based on the new d point) */
  if (b_TR == 2.0) {
    CL_k = wpts_n[next_wpt_index - 1] - n_op_k;
    CD_k = wpts_e[next_wpt_index - 1] - e_op_k;
    ea = wpts_h[next_wpt_index - 1] - h_op_k;
    r_a = wpts_n[next_wpt_index - 1] - nd_k;
    s_a = wpts_e[next_wpt_index - 1] - ed_k;
    t_a = wpts_h[next_wpt_index - 1] - hd_k;
    mass = nd_k - n_op_k;
    Cns_k = ed_k - e_op_k;
    Cls_k = hd_k - h_op_k;
    r_a = sqrt((CL_k * CL_k + CD_k * CD_k) + ea * ea) - sqrt((r_a * r_a + s_a *
      s_a) + t_a * t_a);
    if (r_a < 0.0) {
      r_a = -1.0;
    } else if (r_a > 0.0) {
      r_a = 1.0;
    } else {
      if (r_a == 0.0) {
        r_a = 0.0;
      }
    }

    *Vab_k = sqrt((vn_op_k * vn_op_k + ve_op_k * ve_op_k) + vh_op_k * vh_op_k) -
      atan(sqrt((mass * mass + Cns_k * Cns_k) + Cls_k * Cls_k) * r_a / 100.0) *
      0.063661977236758135;

    /* (168.78) (5) (/100) */
  }

  /* %VT theta phi and beta command%% */
  /* %consider wind in VTcmd [0]: no [1]:yes */
  mass = *Vab_k * cos(atrack) * sin(btrack) + 0.0 * sw;
  Cns_k = *Vab_k * cos(atrack) * cos(btrack) + 0.0 * sw;
  Cls_k = *Vab_k * sin(atrack) + 0.0 * sw;
  *VTcmd_k = sqrt((mass * mass + Cns_k * Cns_k) + Cls_k * Cls_k);
  Cls_k = atan(*etaLon_k * sw);
  er_k_1[0] = *er_k - e_k;
  er_k_1[1] = *nr_k - n_k;
  er_k_1[2] = *hr_k - h_k;
  *thetacmd_k = rt_atan2d_snf(((fe_k * fe_k + fn_k * fn_k) + fh_k * fh_k) * 2.0 *
                              (Cls_k * b_KpLon + ro_k), NMPC_Controller_norm_l
    (er_k_1));
  er_k_0[0] = *er_k - e_k;
  er_k_0[1] = *nr_k - n_k;
  *phicmd_k = rt_atan2d_snf((edot_track_k * edot_track_k + ndot_track_k *
    ndot_track_k) * 2.0 * b_KpLat * sw * *etaLat_k, NMPC_Controller_norm(er_k_0));

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%guidance system at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%implementing saturation of actuators%% */
  /* %deflection max and min */
  if (THL_k > b_ThrottleMax) {
    THL_k = b_ThrottleMax;
  } else {
    if (THL_k < b_ThrottleMin) {
      THL_k = b_ThrottleMin;
    }
  }

  if (EL_k > b_ElevatorMax) {
    EL_k = b_ElevatorMax;
  } else {
    if (EL_k < b_ElevatorMin) {
      EL_k = b_ElevatorMin;
    }
  }

  if (AIL_k > b_AileronMax) {
    AIL_k = b_AileronMax;
  } else {
    if (AIL_k < b_AileronMin) {
      AIL_k = b_AileronMin;
    }
  }

  if (RDR_k > b_RudderMax) {
    RDR_k = b_RudderMax;
  } else {
    if (RDR_k < b_RudderMin) {
      RDR_k = b_RudderMin;
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %longitudinal guidance integrator */
  *ro_kk = b_dt * Cls_k * b_KiLon + ro_k;

  /* %servos prediction%% */
  *THL_kk = (b_Athrottle * THL_k + b_Bthrottle * THLcmd_k) * b_dt + THL_k;
  *EL_kk = (b_Aelevator * EL_k + b_Belevator * ELcmd_k) * b_dt + EL_k;
  *AIL_kk = (b_Aaileron * AIL_k + b_Baileron * AILcmd_k) * b_dt + AIL_k;
  *RDR_kk = (b_Arudder * RDR_k + b_Brudder * RDRcmd_k) * b_dt + RDR_k;

  /* %UAV prediction%% */
  Cls_k = ((U_k * Udot_k + V_k * Vdot_k) + W_k * Wdot_k) / VT_k;
  *falpha_k = (U_k * Wdot_k - W_k * Udot_k) / (U_k * U_k + W_k * W_k);
  *fbeta_k = (VT_k * Vdot_k - V_k * Cls_k) / (U_k * U_k + W_k * W_k) * cos
    (beta_k);
  *VT_kk = b_dt * Cls_k + VT_k;
  *alpha_kk = b_dt * *falpha_k + alpha_k;
  *beta_kk = b_dt * *fbeta_k + beta_k;
  *phi_kk = ((R_k * cos(phi_k) + Q_k * sin(phi_k)) * tan(theta_k) + P_k) * b_dt
    + phi_k;
  *theta_kk = (Q_k * cos(phi_k) - R_k * sin(phi_k)) * b_dt + theta_k;
  *psi_kk = (R_k * cos(phi_k) + Q_k * sin(phi_k)) / cos(theta_k) * b_dt + psi_k;
  *P_kk = ((((b_IyyB - b_IzzB) * b_IzzB - b_IxzB * b_IxzB) / delta_I * R_k + c2 *
            P_k) * Q_k + (b_IzzB / delta_I * Cl_k + c4 * Cn_k) * (Qbar_k * b_S *
            b_b)) * b_dt + P_k;
  *Q_kk = (((b_IzzB - b_IxxB) / b_IyyB * P_k * R_k - (P_k * P_k - R_k * R_k) *
            (b_IxzB / b_IyyB)) + Qbar_k * b_S * b_Cbar * (1.0 / b_IyyB) * Cms_k)
    * b_dt + Q_k;
  *R_kk = ((((b_IxxB - b_IyyB) * b_IxxB + b_IxzB * b_IxzB) / delta_I * P_k - c2 *
            R_k) * Q_k + (b_IxxB / delta_I * Cn_k + c4 * Cl_k) * (Qbar_k * b_S *
            b_b)) * b_dt + R_k;

  /* %inertial frame prediction%% */
  *n_kk = b_dt * fn_k + n_k;
  *e_kk = b_dt * fe_k + e_k;
  *h_kk = b_dt * fh_k + h_k;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of kk%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %outputs e, y and z%% */
  e_augm_k[0] = *VTcmd_k - VT_k;
  e_augm_k[1] = *thetacmd_k - theta_k;
  e_augm_k[2] = *phicmd_k - phi_k;
  e_augm_k[3] = 0.0 - beta_k;

  /* %Robustness states at [k+1]%% */
  *xw11_kk = b_W11d.a * xw11_k + b_W11d.b * e_augm_k[0];

  /* W11 e_VT */
  *xw12_kk = b_W12d.a * xw12_k + b_W12d.b * e_augm_k[1];

  /* W12 e_theta */
  *xw13_kk = b_W13d.a * xw13_k + b_W13d.b * e_augm_k[2];

  /* W13 e_phi */
  *xw14_kk = (0.0 - beta_k) * b_W14d.b + b_W14d.a * xw14_k;

  /* W14 e_beta */
  *xw21_kk = b_W21d.a * xw21_k + b_W21d.b * THLcmd_k;

  /* W21 Throttle cmd */
  *xw22_kk = b_W22d.a * xw22_k + b_W22d.b * ELcmd_k;

  /* W22 Elevator cmd */
  *xw23_kk = b_W23d.a * xw23_k + b_W23d.b * AILcmd_k;

  /* W23 Aileron cmd */
  *xw24_kk = b_W24d.a * xw24_k + b_W24d.b * RDRcmd_k;

  /* W24 Rudder cmd */
  *xw31_kk = b_W31d.a * xw31_k + b_W31d.b * VT_k;

  /* W31 VT */
  *xw32_kk = b_W32d.a * xw32_k + b_W32d.b * theta_k;

  /* W32 theta */
  *xw33_kk = b_W33d.a * xw33_k + b_W33d.b * phi_k;

  /* W33 phi */
  *xw34_kk = b_W34d.a * xw34_k + b_W34d.b * beta_k;

  /* W34 beta */
  /* %Robustness output at [k] */
  z_augm_k[0] = b_W11d.c * xw11_k + b_W11d.d * e_augm_k[0];

  /* W11 e_VT */
  z_augm_k[1] = b_W12d.c * xw12_k + b_W12d.d * e_augm_k[1];

  /* W12 e_theta */
  z_augm_k[2] = b_W13d.c * xw13_k + b_W13d.d * e_augm_k[2];

  /* W13 e_phi */
  z_augm_k[3] = (0.0 - beta_k) * b_W14d.d + b_W14d.c * xw14_k;

  /* W14 e_beta */
  z_augm_k[4] = b_W21d.c * xw21_k + b_W21d.d * THLcmd_k;

  /* W21 Throttle cmd */
  z_augm_k[5] = b_W22d.c * xw22_k + b_W22d.d * ELcmd_k;

  /* W22 Elevator cmd */
  z_augm_k[6] = b_W23d.c * xw23_k + b_W23d.d * AILcmd_k;

  /* W23 Aileron cmd */
  z_augm_k[7] = b_W24d.c * xw24_k + b_W24d.d * RDRcmd_k;

  /* W24 Rudder cmd */
  z_augm_k[8] = b_W31d.c * xw31_k + b_W31d.d * VT_k;

  /* W31 VT */
  z_augm_k[9] = b_W32d.c * xw32_k + b_W32d.d * theta_k;

  /* W32 theta */
  z_augm_k[10] = b_W33d.c * xw33_k + b_W33d.d * phi_k;

  /* W33 phi */
  z_augm_k[11] = b_W34d.c * xw34_k + b_W34d.d * beta_k;

  /* W34 beta */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%Robustness nmpc calculations%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
}

/* Model step function */
void NMPC_Controller_step(void)
{
  ZCEventType zcEvent;
  real_T wpts_h[32];
  real_T wpts_n[32];
  real_T wpts_e[32];
  uint8_T home_reset_out;
  uint8_T b_index;
  uint8_T next_wpt_index;
  real_T distance;
  int32_T factor;
  real_T z_augm_hor[252];
  real_T u_hor[84];
  real_T n_hor[21];
  real_T e_hor[21];
  real_T h_hor[21];
  real_T THL_hor[21];
  real_T EL_hor[21];
  real_T AIL_hor[21];
  real_T RDR_hor[21];
  real_T VT_hor[21];
  real_T alpha_hor[21];
  real_T beta_hor[21];
  real_T phi_hor[21];
  real_T theta_hor[21];
  real_T psi_hor[21];
  real_T P_hor[21];
  real_T Q_hor[21];
  real_T R_hor[21];
  real_T wpt_index_hor[21];
  real_T start_wpt_hor[63];
  real_T pic_cic_hor[21];
  real_T home_reset_hor[21];
  real_T alphadot_hor[21];
  real_T betadot_hor[21];
  real_T ro_hor[21];
  real_T xw11_hor[21];
  real_T xw12_hor[21];
  real_T xw13_hor[21];
  real_T xw14_hor[21];
  real_T xw21_hor[21];
  real_T xw22_hor[21];
  real_T xw23_hor[21];
  real_T xw24_hor[21];
  real_T xw31_hor[21];
  real_T xw32_hor[21];
  real_T xw33_hor[21];
  real_T xw34_hor[21];
  real32_T unusedU0;
  uint8_T f;
  real_T h[12];
  real_T i[4];
  real_T k;
  real_T l;
  real_T m;
  real_T n;
  real_T o;
  real_T p;
  real_T q;
  real_T r;
  real_T s;
  real_T t;
  real_T u;
  real_T v;
  real_T w;
  real_T x;
  real_T y;
  real_T ab;
  real_T bb;
  real_T cb;
  real_T db;
  real_T eb;
  real_T fb;
  real_T gb;
  real_T hb;
  real_T ib;
  real_T jb;
  real_T kb;
  real_T lb;
  real_T mb;
  real_T nb;
  real_T ob;
  int32_T rtb_DataTypeConversion1;
  real_T rtb_sw_time_out;
  real_T rtb_Height;
  real_T rtb_North;
  real_T rtb_East;
  boolean_T rtb_pic_cic_out;
  real_T rtb_start_wpt_mem[3];
  real_T rtb_throttle_cmd_out;
  real_T rtb_elevator_cmd_out;
  real_T rtb_aileron_cmd_out;
  real_T rtb_rudder_cmd_out;
  real_T rtb_z2_k;
  real_T rtb_Add9;
  real_T rtb_z1_k;
  real_T rtb_Add5;
  real_T rtb_e_augm31_k;
  real_T rtb_Product4_i;
  real_T rtb_hd;
  real_T rtb_nd;
  real_T rtb_ed;
  real_T rtb_Vab_mod;
  real_T rtb_e_augm11_k;
  real_T rtb_V_east;
  real_T rtb_TrigonometricFunction;
  real_T rtb_Subtract4;
  real_T rtb_Subtract5;
  real_T rtb_TrigonometricFunction1_a;
  boolean_T rtb_LogicalOperator;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_e_augm21_k;
  real_T rtb_er_e;
  boolean_T rtb_LogicalOperator_f;
  real_T rtb_xw11_k;
  real_T rtb_xw12_k;
  real_T rtb_xw13_k;
  real_T rtb_e_augm41_k;
  real_T rtb_xw14_k;
  real_T rtb_xw21_k;
  real_T rtb_xw22_k;
  real_T rtb_xw23_k;
  real_T rtb_xw24_k;
  real_T rtb_xw31_k;
  real_T rtb_xw32_k;
  real_T rtb_xw33_k;
  real_T rtb_xw34_k;
  uint8_T rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_0;
  uint8_T rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_1;
  real_T rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_2[32];
  real_T rtb_TSamp;
  real_T rtb_TSamp_d;
  real_T rtb_u_nmpc_out[84];
  int32_T i_0;
  real_T wpts_h_0[32];
  real_T wpts_n_0[32];
  real_T wpts_e_0[32];
  real_T rtb_DataStoreRead1_f_idx_3;
  real_T rtb_DataStoreRead1_f_idx_2;
  real_T rtb_DataStoreRead1_f_idx_1;
  real_T rtb_DataStoreRead1_f_idx_0;

  /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  memcpy(&NMPC_Controller_DW.u_nmpc[0], &NMPC_Controller_DW.UnitDelay_DSTATE[0],
         84U * sizeof(real_T));

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/PIC//CIC'
   */
  rtb_DataTypeConversion1 = NMPC_Controller_U.PICCIC;

  /* DataStoreRead: '<Root>/Data Store Read1' */
  rtb_DataStoreRead1_f_idx_0 = NMPC_Controller_DW.u_nmpc[0];
  rtb_DataStoreRead1_f_idx_1 = NMPC_Controller_DW.u_nmpc[1];
  rtb_DataStoreRead1_f_idx_2 = NMPC_Controller_DW.u_nmpc[2];
  rtb_DataStoreRead1_f_idx_3 = NMPC_Controller_DW.u_nmpc[3];

  /* MATLAB Function: '<S6>/Swtching Logic' incorporates:
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Swtching Logic_at_inport_0'
   *  DataStoreRead: '<Root>/Data Store Read1'
   *  DataStoreRead: '<S6>/Data Store Read1'
   *  DataStoreRead: '<S6>/Data Store Read2'
   *  DataStoreRead: '<S6>/Data Store Read3'
   *  DataStoreRead: '<S6>/Data Store Read4'
   *  DataStoreRead: '<S6>/Data Store Read5'
   *  Inport: '<Root>/PIC//CIC'
   *  Inport: '<Root>/R//C'
   */
  /* MATLAB Function 'R//C to AUTO smooth transition Subsystem/Swtching Logic': '<S33>:1' */
  /* initialization */
  /* '<S33>:1:12' */
  rtb_sw_time_out = NMPC_Controller_DW.sw_time;

  /* '<S33>:1:13' */
  rtb_TrigonometricFunction = NMPC_Controller_DW.remote_throttle_mem;

  /* '<S33>:1:14' */
  rtb_er_e = NMPC_Controller_DW.remote_elevator_mem;

  /* '<S33>:1:15' */
  rtb_Subtract4 = NMPC_Controller_DW.remote_aileron_mem;

  /* '<S33>:1:16' */
  rtb_Subtract5 = NMPC_Controller_DW.remote_rudder_mem;

  /* '<S33>:1:18' */
  rtb_throttle_cmd_out = NMPC_Controller_U.RC.throttle_cmd;

  /* [-] */
  /* '<S33>:1:19' */
  rtb_elevator_cmd_out = NMPC_Controller_U.RC.elevator_cmd;

  /* [rad] */
  /* '<S33>:1:20' */
  rtb_aileron_cmd_out = NMPC_Controller_U.RC.aileron_cmd;

  /* [rad] */
  /* '<S33>:1:21' */
  rtb_rudder_cmd_out = NMPC_Controller_U.RC.rudder_cmd;

  /* [rad] */
  /* '<S33>:1:23' */
  /* [s] */
  /* %updating/reseting values */
  if ((NMPC_Controller_U.PICCIC == 1) && (NMPC_Controller_DW.sw_time == 0.0)) {
    /* '<S33>:1:26' */
    /* '<S33>:1:27' */
    rtb_TrigonometricFunction = NMPC_Controller_U.RC.throttle_cmd;

    /* '<S33>:1:28' */
    rtb_er_e = NMPC_Controller_U.RC.elevator_cmd;

    /* '<S33>:1:29' */
    rtb_Subtract4 = NMPC_Controller_U.RC.aileron_cmd;

    /* '<S33>:1:30' */
    rtb_Subtract5 = NMPC_Controller_U.RC.rudder_cmd;
  }

  /* servo command value */
  if ((NMPC_Controller_U.PICCIC == 1) && (NMPC_Controller_DW.sw_time >= 0.0) &&
      (NMPC_Controller_DW.sw_time <= 0.5)) {
    /* '<S33>:1:39' */
    /* '<S33>:1:40' */
    rtb_throttle_cmd_out = (0.5 - cos(6.2831853071795862 *
      NMPC_Controller_DW.sw_time) * 0.5) * (NMPC_Controller_DW.u_nmpc[0] -
      rtb_TrigonometricFunction) + rtb_TrigonometricFunction;

    /* '<S33>:1:41' */
    rtb_elevator_cmd_out = (0.5 - cos(6.2831853071795862 *
      NMPC_Controller_DW.sw_time) * 0.5) * (NMPC_Controller_DW.u_nmpc[1] -
      rtb_er_e) + rtb_er_e;

    /* '<S33>:1:42' */
    rtb_aileron_cmd_out = (0.5 - cos(6.2831853071795862 *
      NMPC_Controller_DW.sw_time) * 0.5) * (NMPC_Controller_DW.u_nmpc[2] -
      rtb_Subtract4) + rtb_Subtract4;

    /* '<S33>:1:43' */
    rtb_rudder_cmd_out = (0.5 - cos(6.2831853071795862 *
      NMPC_Controller_DW.sw_time) * 0.5) * (NMPC_Controller_DW.u_nmpc[3] -
      rtb_Subtract5) + rtb_Subtract5;
  } else {
    if ((NMPC_Controller_U.PICCIC == 1) && (NMPC_Controller_DW.sw_time > 0.5)) {
      /* '<S33>:1:44' */
      /* '<S33>:1:45' */
      rtb_throttle_cmd_out = NMPC_Controller_DW.u_nmpc[0];

      /* '<S33>:1:46' */
      rtb_elevator_cmd_out = NMPC_Controller_DW.u_nmpc[1];

      /* '<S33>:1:47' */
      rtb_aileron_cmd_out = NMPC_Controller_DW.u_nmpc[2];

      /* '<S33>:1:48' */
      rtb_rudder_cmd_out = NMPC_Controller_DW.u_nmpc[3];
    }
  }

  /* time counting */
  if (NMPC_Controller_U.PICCIC == 1) {
    /* '<S33>:1:52' */
    /* '<S33>:1:53' */
    rtb_sw_time_out = NMPC_Controller_DW.sw_time + 0.05;
  }

  /* DataStoreWrite: '<S6>/Data Store Write1' incorporates:
   *  MATLAB Function: '<S6>/Swtching Logic'
   */
  NMPC_Controller_DW.remote_elevator_mem = rtb_er_e;

  /* DataStoreWrite: '<S6>/Data Store Write2' incorporates:
   *  MATLAB Function: '<S6>/Swtching Logic'
   */
  NMPC_Controller_DW.remote_aileron_mem = rtb_Subtract4;

  /* DataStoreWrite: '<S6>/Data Store Write3' incorporates:
   *  MATLAB Function: '<S6>/Swtching Logic'
   */
  NMPC_Controller_DW.remote_throttle_mem = rtb_TrigonometricFunction;

  /* DataStoreWrite: '<S6>/Data Store Write4' */
  NMPC_Controller_DW.sw_time = rtb_sw_time_out;

  /* DataStoreWrite: '<S6>/Data Store Write5' incorporates:
   *  MATLAB Function: '<S6>/Swtching Logic'
   */
  NMPC_Controller_DW.remote_rudder_mem = rtb_Subtract5;

  /* MATLAB Function: '<S4>/Convert Lat//Lon//Alt to Flat Earth' incorporates:
   *  Inport: '<Root>/GPS Position'
   */
  /* MATLAB Function 'GPS to Local/Convert Lat//Lon//Alt to Flat Earth': '<S9>:1' */
  /*  Convert the given LLA coordinates to Flat Earth coordinates. */
  /*  */
  /*  ref_alt - meters ASML */
  /*  ref_lat - deg. */
  /*  ref_lon - deg. */
  /*  */
  /*  Height, North, East are in feet */
  /* '<S9>:1:11' */
  rtb_Height = (NMPC_Controller_U.GPSPosition.Altitude - 390.144) *
    3.280839895013123;

  /* '<S9>:1:12' */
  rtb_North = (NMPC_Controller_U.GPSPosition.Latitude - 282315.2392) * 39.252732;

  /* '<S9>:1:13' */
  rtb_East = (NMPC_Controller_U.GPSPosition.Longitude - 364574.1647) *
    -96.938825;

  /* MATLAB Function: '<S8>/Trajectory Generation' incorporates:
   *  BusCreator: '<S37>/BusConversion_InsertedFor_ SFunction _at_inport_6'
   *  BusCreator: '<S8>/BusConversion_InsertedFor_Trajectory Generation_at_inport_7'
   *  DataStoreRead: '<S8>/Data Store Read1'
   *  DataStoreRead: '<S8>/Data Store Read2'
   *  DataStoreRead: '<S8>/Data Store Read3'
   *  DataStoreRead: '<S8>/Data Store Read4'
   *  Inport: '<Root>/Home Cmd'
   *  Inport: '<Root>/PIC//CIC'
   *  Inport: '<Root>/wpts'
   */
  for (i_0 = 0; i_0 < 32; i_0++) {
    wpts_h[i_0] = NMPC_Controller_U.wpts.h[i_0];
    wpts_n[i_0] = NMPC_Controller_U.wpts.n[i_0];
    wpts_e[i_0] = NMPC_Controller_U.wpts.e[i_0];
  }

  /* MATLAB Function 'Trajectory/Trajectory Generation': '<S37>:1' */
  /* Local Variable Assignment: */
  /* '<S37>:1:7' */
  b_index = NMPC_Controller_DW.Waypoint_Index;

  /* '<S37>:1:8' */
  rtb_start_wpt_mem[0] = NMPC_Controller_DW.Start_Wpt[0];
  rtb_start_wpt_mem[1] = NMPC_Controller_DW.Start_Wpt[1];
  rtb_start_wpt_mem[2] = NMPC_Controller_DW.Start_Wpt[2];

  /* '<S37>:1:9' */
  home_reset_out = NMPC_Controller_DW.Home_reset;

  /* PIC/CIC Transition Logic: */
  /*  On transition to CIC or PIC, set index = 0 and current position to  */
  /*  current waypoint; hold current waypoint. */
  if (((int32_T)NMPC_Controller_U.PICCIC > (int32_T)
       NMPC_Controller_DW.PIC_CIC_Last) || (NMPC_Controller_U.PICCIC == 0)) {
    /* '<S37>:1:14' */
    /* '<S37>:1:15' */
    rtb_start_wpt_mem[0] = rtb_Height;

    /* '<S37>:1:16' */
    rtb_start_wpt_mem[1] = rtb_North;

    /* '<S37>:1:17' */
    rtb_start_wpt_mem[2] = rtb_East;

    /* '<S37>:1:19' */
    b_index = 0U;

    /* '<S37>:1:20' */
    home_reset_out = 0U;
  }

  /*  Change the waypoint index when home command */
  if ((NMPC_Controller_U.HomeCmd == 1) && (NMPC_Controller_U.PICCIC == 1) &&
      (home_reset_out == 0)) {
    /* '<S37>:1:24' */
    /* '<S37>:1:26' */
    b_index = 23U;

    /* '<S37>:1:27' */
    home_reset_out = 1U;
  }

  /* %%%trajectory logic at time [k]%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* OP trajectory generation */
  /* %reassigning the a and b waypoints */
  /* calculate the next waypoint index: */
  /* '<S37>:1:43' */
  i_0 = (int32_T)(b_index + 1U);
  if ((uint32_T)i_0 > 255U) {
    i_0 = 255;
  }

  next_wpt_index = (uint8_T)i_0;

  /* beyond final point (fp), go to return point (rp) */
  if ((uint8_T)i_0 > NMPC_Controller_U.wpts.fp) {
    /* '<S37>:1:45' */
    /* '<S37>:1:46' */
    next_wpt_index = NMPC_Controller_U.wpts.rp;
  }

  /* calculate distance to next waypoint */
  /* '<S37>:1:49' */
  rtb_Subtract4 = rtb_North - wpts_n[next_wpt_index - 1];
  rtb_Subtract5 = rtb_East - wpts_e[next_wpt_index - 1];
  distance = sqrt(rtb_Subtract4 * rtb_Subtract4 + rtb_Subtract5 * rtb_Subtract5);

  /* change to next waypoint if in range */
  if ((distance < 320.0) && (NMPC_Controller_U.PICCIC == 1)) {
    /* '<S37>:1:51' */
    /* '<S37>:1:52' */
    /*  Do not change index if sw=0 */
    /* '<S37>:1:53' */
    b_index = next_wpt_index;
    if (next_wpt_index == NMPC_Controller_U.wpts.fp) {
      /* '<S37>:1:54' */
      /* '<S37>:1:55' */
      next_wpt_index = NMPC_Controller_U.wpts.rp;
    } else {
      /* '<S37>:1:57' */
      i_0 = (int32_T)(next_wpt_index + 1U);
      if ((uint32_T)i_0 > 255U) {
        i_0 = 255;
      }

      next_wpt_index = (uint8_T)i_0;
    }
  }

  /* function outputs */
  if ((b_index == 0) || (b_index == 23)) {
    /* '<S37>:1:63' */
    /*  Assign the speed of the starting segment to the speed of the first */
    /*  waypoint */
    /* '<S37>:1:66' */
    rtb_Vab_mod = NMPC_Controller_U.wpts.v[0];

    /* '<S37>:1:67' */
    rtb_V_east = rtb_start_wpt_mem[0];

    /* '<S37>:1:68' */
    rtb_Subtract5 = rtb_start_wpt_mem[1];

    /* '<S37>:1:69' */
    rtb_Subtract4 = rtb_start_wpt_mem[2];
  } else {
    /* '<S37>:1:71' */
    rtb_Vab_mod = NMPC_Controller_U.wpts.v[b_index - 1];

    /* '<S37>:1:72' */
    rtb_V_east = wpts_h[b_index - 1];

    /* '<S37>:1:73' */
    rtb_Subtract5 = wpts_n[b_index - 1];

    /* '<S37>:1:74' */
    rtb_Subtract4 = wpts_e[b_index - 1];
  }

  /* '<S37>:1:76' */
  /* '<S37>:1:77' */
  /* '<S37>:1:78' */
  /* '<S37>:1:80' */
  /* '<S37>:1:81' */
  /* '<S37>:1:82' */
  rtb_pic_cic_out = NMPC_Controller_U.PICCIC;

  /* DataStoreWrite: '<S8>/Data Store Write1' incorporates:
   *  Inport: '<Root>/PIC//CIC'
   */
  NMPC_Controller_DW.PIC_CIC_Last = NMPC_Controller_U.PICCIC;

  /* DataStoreWrite: '<S8>/Data Store Write2' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  NMPC_Controller_DW.Waypoint_Index = b_index;

  /* DataStoreWrite: '<S8>/Data Store Write3' */
  NMPC_Controller_DW.Start_Wpt[0] = rtb_start_wpt_mem[0];
  NMPC_Controller_DW.Start_Wpt[1] = rtb_start_wpt_mem[1];
  NMPC_Controller_DW.Start_Wpt[2] = rtb_start_wpt_mem[2];

  /* DataStoreWrite: '<S8>/Data Store Write4' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  NMPC_Controller_DW.Home_reset = home_reset_out;

  /* Outport: '<Root>/Control  Surface Commands' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_Control  Surface Commands_at_inport_0'
   */
  NMPC_Controller_Y.ControlSurfaceCommands.throttle_cmd = rtb_throttle_cmd_out;
  NMPC_Controller_Y.ControlSurfaceCommands.elevator_cmd = rtb_elevator_cmd_out;
  NMPC_Controller_Y.ControlSurfaceCommands.aileron_cmd = rtb_aileron_cmd_out;
  NMPC_Controller_Y.ControlSurfaceCommands.rudder_cmd = rtb_rudder_cmd_out;

  /* Sum: '<S17>/Add4' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_z2_k = wpts_h[next_wpt_index - 1] - rtb_V_east;

  /* Sum: '<S17>/Add9' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Add9 = wpts_n[next_wpt_index - 1] - rtb_Subtract5;

  /* Math: '<S17>/Math Function4' */
  rtb_z1_k = rtb_Add9 * rtb_Add9;

  /* Sum: '<S17>/Add5' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Add5 = wpts_e[next_wpt_index - 1] - rtb_Subtract4;

  /* Math: '<S17>/Math Function5' */
  rtb_e_augm31_k = rtb_Add5 * rtb_Add5;

  /* Sum: '<S17>/Add6' incorporates:
   *  Math: '<S17>/Math Function7'
   */
  rtb_Product4_i = (rtb_z2_k * rtb_z2_k + rtb_z1_k) + rtb_e_augm31_k;

  /* Sqrt: '<S17>/Math Function9'
   *
   * About '<S17>/Math Function9':
   *  Operator: signedSqrt
   */
  if (rtb_Product4_i < 0.0) {
    rtb_Product4_i = -sqrt(fabs(rtb_Product4_i));
  } else {
    rtb_Product4_i = sqrt(rtb_Product4_i);
  }

  /* End of Sqrt: '<S17>/Math Function9' */

  /* Product: '<S17>/Product6' */
  rtb_TrigonometricFunction = rtb_z2_k / rtb_Product4_i;

  /* Trigonometry: '<S17>/Trigonometric Function5' */
  if (rtb_TrigonometricFunction > 1.0) {
    rtb_TrigonometricFunction = 1.0;
  } else {
    if (rtb_TrigonometricFunction < -1.0) {
      rtb_TrigonometricFunction = -1.0;
    }
  }

  rtb_Product4_i = asin(rtb_TrigonometricFunction);

  /* End of Trigonometry: '<S17>/Trigonometric Function5' */

  /* Trigonometry: '<S17>/Trigonometric Function' */
  rtb_z2_k = sin(rtb_Product4_i);

  /* Fcn: '<S29>/hd' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_hd = ((((((((((((((((((wpts_e[next_wpt_index - 1] * rtb_East *
    wpts_h[next_wpt_index - 1] - wpts_e[next_wpt_index - 1] * rtb_East *
    rtb_V_east) + rt_powd_snf(wpts_e[next_wpt_index - 1], 2.0) * rtb_V_east) -
    wpts_e[next_wpt_index - 1] * rtb_Subtract4 * wpts_h[next_wpt_index - 1]) -
    rtb_Subtract4 * rtb_East * wpts_h[next_wpt_index - 1]) + rtb_Subtract4 *
    rtb_East * rtb_V_east) - rtb_Subtract4 * rtb_V_east * wpts_e[next_wpt_index
                        - 1]) + wpts_h[next_wpt_index - 1] * rt_powd_snf
                       (rtb_Subtract4, 2.0)) + wpts_n[next_wpt_index - 1] *
                      rtb_North * wpts_h[next_wpt_index - 1]) -
                     wpts_n[next_wpt_index - 1] * rtb_North * rtb_V_east) +
                    rt_powd_snf(wpts_n[next_wpt_index - 1], 2.0) * rtb_V_east) -
                   wpts_n[next_wpt_index - 1] * rtb_Subtract5 *
                   wpts_h[next_wpt_index - 1]) - rtb_Subtract5 * rtb_North *
                  wpts_h[next_wpt_index - 1]) + rtb_Subtract5 * rtb_North *
                 rtb_V_east) - rtb_Subtract5 * rtb_V_east *
                wpts_n[next_wpt_index - 1]) + wpts_h[next_wpt_index - 1] *
               rt_powd_snf(rtb_Subtract5, 2.0)) + rt_powd_snf
              (wpts_h[next_wpt_index - 1], 2.0) * rtb_Height) - 2.0 * rtb_Height
             * wpts_h[next_wpt_index - 1] * rtb_V_east) + rtb_Height *
            rt_powd_snf(rtb_V_east, 2.0)) / ((((((((rt_powd_snf
    (wpts_e[next_wpt_index - 1], 2.0) - wpts_e[next_wpt_index - 1] * 2.0 *
    rtb_Subtract4) + rt_powd_snf(rtb_Subtract4, 2.0)) + rt_powd_snf
    (wpts_n[next_wpt_index - 1], 2.0)) - wpts_n[next_wpt_index - 1] * 2.0 *
    rtb_Subtract5) + rt_powd_snf(rtb_Subtract5, 2.0)) + rt_powd_snf
    (wpts_h[next_wpt_index - 1], 2.0)) - wpts_h[next_wpt_index - 1] * 2.0 *
    rtb_V_east) + rt_powd_snf(rtb_V_east, 2.0));

  /* Fcn: '<S29>/nd' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_nd = ((((((((((((((((((wpts_e[next_wpt_index - 1] * rtb_East *
    wpts_n[next_wpt_index - 1] - wpts_e[next_wpt_index - 1] * rtb_East *
    rtb_Subtract5) + rt_powd_snf(wpts_e[next_wpt_index - 1], 2.0) *
    rtb_Subtract5) - wpts_e[next_wpt_index - 1] * rtb_Subtract4 *
    wpts_n[next_wpt_index - 1]) - rtb_Subtract4 * rtb_East *
    wpts_n[next_wpt_index - 1]) + rtb_Subtract4 * rtb_East * rtb_Subtract5) -
                        rtb_Subtract4 * rtb_Subtract5 * wpts_e[next_wpt_index -
                        1]) + wpts_n[next_wpt_index - 1] * rt_powd_snf
                       (rtb_Subtract4, 2.0)) + rt_powd_snf(wpts_n[next_wpt_index
    - 1], 2.0) * rtb_North) - 2.0 * rtb_North * wpts_n[next_wpt_index - 1] *
                     rtb_Subtract5) + rtb_North * rt_powd_snf(rtb_Subtract5, 2.0))
                   + wpts_h[next_wpt_index - 1] * rtb_Height *
                   wpts_n[next_wpt_index - 1]) - wpts_h[next_wpt_index - 1] *
                  rtb_Height * rtb_Subtract5) + rt_powd_snf
                 (wpts_h[next_wpt_index - 1], 2.0) * rtb_Subtract5) -
                wpts_h[next_wpt_index - 1] * rtb_V_east * wpts_n[next_wpt_index
                - 1]) - rtb_V_east * rtb_Height * wpts_n[next_wpt_index - 1]) +
              rtb_V_east * rtb_Height * rtb_Subtract5) - rtb_V_east *
             rtb_Subtract5 * wpts_h[next_wpt_index - 1]) + wpts_n[next_wpt_index
            - 1] * rt_powd_snf(rtb_V_east, 2.0)) / ((((((((rt_powd_snf
    (wpts_e[next_wpt_index - 1], 2.0) - wpts_e[next_wpt_index - 1] * 2.0 *
    rtb_Subtract4) + rt_powd_snf(rtb_Subtract4, 2.0)) + rt_powd_snf
    (wpts_n[next_wpt_index - 1], 2.0)) - wpts_n[next_wpt_index - 1] * 2.0 *
    rtb_Subtract5) + rt_powd_snf(rtb_Subtract5, 2.0)) + rt_powd_snf
    (wpts_h[next_wpt_index - 1], 2.0)) - wpts_h[next_wpt_index - 1] * 2.0 *
    rtb_V_east) + rt_powd_snf(rtb_V_east, 2.0));

  /* Fcn: '<S29>/ed' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_ed = ((((((((((((((((((rt_powd_snf(wpts_e[next_wpt_index - 1], 2.0) *
    rtb_East - 2.0 * rtb_East * wpts_e[next_wpt_index - 1] * rtb_Subtract4) +
    rtb_East * rt_powd_snf(rtb_Subtract4, 2.0)) + wpts_n[next_wpt_index - 1] *
    rtb_North * wpts_e[next_wpt_index - 1]) - wpts_n[next_wpt_index - 1] *
    rtb_North * rtb_Subtract4) + rt_powd_snf(wpts_n[next_wpt_index - 1], 2.0) *
    rtb_Subtract4) - wpts_n[next_wpt_index - 1] * rtb_Subtract5 *
                        wpts_e[next_wpt_index - 1]) - rtb_Subtract5 * rtb_North *
                       wpts_e[next_wpt_index - 1]) + rtb_Subtract5 * rtb_North *
                      rtb_Subtract4) - rtb_Subtract5 * rtb_Subtract4 *
                     wpts_n[next_wpt_index - 1]) + wpts_e[next_wpt_index - 1] *
                    rt_powd_snf(rtb_Subtract5, 2.0)) + wpts_h[next_wpt_index - 1]
                   * rtb_Height * wpts_e[next_wpt_index - 1]) -
                  wpts_h[next_wpt_index - 1] * rtb_Height * rtb_Subtract4) +
                 rt_powd_snf(wpts_h[next_wpt_index - 1], 2.0) * rtb_Subtract4) -
                wpts_h[next_wpt_index - 1] * rtb_V_east * wpts_e[next_wpt_index
                - 1]) - rtb_V_east * rtb_Height * wpts_e[next_wpt_index - 1]) +
              rtb_V_east * rtb_Height * rtb_Subtract4) - rtb_V_east *
             rtb_Subtract4 * wpts_h[next_wpt_index - 1]) + wpts_e[next_wpt_index
            - 1] * rt_powd_snf(rtb_V_east, 2.0)) / ((((((((rt_powd_snf
    (wpts_e[next_wpt_index - 1], 2.0) - wpts_e[next_wpt_index - 1] * 2.0 *
    rtb_Subtract4) + rt_powd_snf(rtb_Subtract4, 2.0)) + rt_powd_snf
    (wpts_n[next_wpt_index - 1], 2.0)) - wpts_n[next_wpt_index - 1] * 2.0 *
    rtb_Subtract5) + rt_powd_snf(rtb_Subtract5, 2.0)) + rt_powd_snf
    (wpts_h[next_wpt_index - 1], 2.0)) - wpts_h[next_wpt_index - 1] * 2.0 *
    rtb_V_east) + rt_powd_snf(rtb_V_east, 2.0));

  /* Trigonometry: '<S17>/Trigonometric Function1' */
  /* MATLAB Function 'Guidance System/VT modification_moving points/Modification of VT': '<S28>:1' */
  /* OP trajectory generation (copied from uas_augm)model.m) */
  /* reassigning Vab (based on the new d point) */
  /* '<S28>:1:11' */
  rtb_Product4_i = cos(rtb_Product4_i);

  /* Product: '<S14>/Product6' */
  rtb_e_augm11_k = rtb_Product4_i * rtb_Vab_mod;

  /* Sum: '<S17>/Add8' */
  rtb_z1_k += rtb_e_augm31_k;

  /* Sqrt: '<S17>/Math Function6'
   *
   * About '<S17>/Math Function6':
   *  Operator: signedSqrt
   */
  if (rtb_z1_k < 0.0) {
    rtb_z1_k = -sqrt(fabs(rtb_z1_k));
  } else {
    rtb_z1_k = sqrt(rtb_z1_k);
  }

  /* End of Sqrt: '<S17>/Math Function6' */

  /* Product: '<S17>/Product2' */
  rtb_TrigonometricFunction = rtb_Add9 / rtb_z1_k;

  /* MATLAB Function: '<S18>/Embedded MATLAB Function' incorporates:
   *  SignalConversion: '<S19>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Guidance System/Coordinates transformation e-n-h to e-n-h_track/angles of rotation/Angle Correction/Embedded MATLAB Function': '<S19>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S19>:1:4' */
  factor = 1;

  /* '<S19>:1:5' */
  rtb_sw_time_out = 0.0;
  if (!((rtb_Add9 > 0.0) && (rtb_Add5 > 0.0))) {
    if ((rtb_Add9 > 0.0) && (rtb_Add5 < 0.0)) {
      /* '<S19>:1:10' */
      /* '<S19>:1:11' */
      rtb_sw_time_out = 3.1415926535897931;

      /* '<S19>:1:12' */
      factor = -1;
    } else {
      if ((rtb_Add9 < 0.0) && (rtb_Add5 < 0.0)) {
        /* '<S19>:1:13' */
        /* '<S19>:1:14' */
        rtb_sw_time_out = -3.1415926535897931;

        /* '<S19>:1:15' */
        factor = -1;
      }
    }
  } else {
    /* '<S19>:1:7' */
    /* '<S19>:1:8' */
    /* '<S19>:1:9' */
  }

  /* Trigonometry: '<S17>/Trigonometric Function4' */
  /* '<S19>:1:20' */
  if (rtb_TrigonometricFunction > 1.0) {
    rtb_TrigonometricFunction = 1.0;
  } else {
    if (rtb_TrigonometricFunction < -1.0) {
      rtb_TrigonometricFunction = -1.0;
    }
  }

  /* MATLAB Function: '<S18>/Embedded MATLAB Function' incorporates:
   *  Trigonometry: '<S17>/Trigonometric Function4'
   */
  rtb_sw_time_out += asin(rtb_TrigonometricFunction) * (real_T)factor;

  /* Trigonometry: '<S17>/Trigonometric Function2' */
  rtb_e_augm31_k = sin(rtb_sw_time_out);

  /* Trigonometry: '<S17>/Trigonometric Function3' */
  rtb_z1_k = cos(rtb_sw_time_out);

  /* Outputs for Atomic SubSystem: '<S14>/Subsystem1' */

  /* Sum: '<S14>/Add4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Gain: '<S14>/Gain'
   *  Gain: '<S14>/Gain1'
   *  Gain: '<S14>/Gain2'
   *  Inport: '<Root>/PIC//CIC'
   *  Inport: '<Root>/True Wind'
   *  Product: '<S14>/Product1'
   *  Product: '<S14>/Product2'
   *  Product: '<S14>/Product3'
   *  Product: '<S14>/Product4'
   *  Product: '<S14>/Product5'
   *  Product: '<S14>/Product7'
   *  Sum: '<S14>/Add1'
   *  Sum: '<S14>/Add2'
   */
  NMPC_Controller_Subsystem1_j(rtb_z2_k * rtb_Vab_mod + 0.0 *
    NMPC_Controller_U.TrueWind.VwH * (real_T)NMPC_Controller_U.PICCIC,
    rtb_e_augm11_k * rtb_e_augm31_k + 0.0 * NMPC_Controller_U.TrueWind.VwN *
    (real_T)NMPC_Controller_U.PICCIC, rtb_e_augm11_k * rtb_z1_k + 0.0 *
    NMPC_Controller_U.TrueWind.VwE * (real_T)NMPC_Controller_U.PICCIC,
    &NMPC_Controller_B.Subsystem1);

  /* End of Outputs for SubSystem: '<S14>/Subsystem1' */

  /* Gain: '<S4>/Gain2' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/GPS Velocity'
   */
  rtb_throttle_cmd_out = 3.280839895013123 *
    -NMPC_Controller_U.GPSVelocity.V_down;

  /* Gain: '<S4>/Gain3' incorporates:
   *  Inport: '<Root>/GPS Velocity'
   */
  rtb_rudder_cmd_out = 3.280839895013123 * NMPC_Controller_U.GPSVelocity.V_north;

  /* Gain: '<S4>/Gain4' incorporates:
   *  Inport: '<Root>/GPS Velocity'
   */
  rtb_V_east = 3.280839895013123 * NMPC_Controller_U.GPSVelocity.V_east;

  /* Outputs for Atomic SubSystem: '<S13>/Subsystem4' */
  NMPC_Controller_Subsystem4_g(rtb_throttle_cmd_out, rtb_rudder_cmd_out,
    rtb_V_east, &NMPC_Controller_B.Subsystem4);

  /* End of Outputs for SubSystem: '<S13>/Subsystem4' */

  /* Outputs for Atomic SubSystem: '<S13>/Subsystem3' */
  NMPC_Controller_Subsystem1(rtb_rudder_cmd_out, rtb_V_east,
    &NMPC_Controller_B.Subsystem3);

  /* End of Outputs for SubSystem: '<S13>/Subsystem3' */

  /* Trigonometry: '<S13>/Trigonometric Function' */
  rtb_TrigonometricFunction = rt_atan2d_snf(rtb_throttle_cmd_out,
    NMPC_Controller_B.Subsystem3.Sqrt);

  /* Sum: '<S30>/Subtract2' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_sw_time_out = wpts_h[next_wpt_index - 1] - rtb_hd;

  /* Sum: '<S30>/Subtract4' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Subtract4 = wpts_n[next_wpt_index - 1] - rtb_nd;

  /* Sum: '<S30>/Subtract5' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  rtb_Subtract5 = wpts_e[next_wpt_index - 1] - rtb_ed;

  /* Outputs for Atomic SubSystem: '<S30>/Subsystem1' */
  NMPC_Controller_Subsystem1_j(rtb_sw_time_out, rtb_Subtract4, rtb_Subtract5,
    &NMPC_Controller_B.Subsystem1_d);

  /* End of Outputs for SubSystem: '<S30>/Subsystem1' */

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S30>/dist d to r'
   */
  rtb_e_augm11_k = 300.0 / NMPC_Controller_B.Subsystem1_d.Sqrt;

  /* Sum: '<S11>/Add8' incorporates:
   *  Product: '<S30>/Product1'
   *  Sum: '<S30>/Subtract7'
   */
  rtb_Vab_mod = (rtb_e_augm11_k * rtb_sw_time_out + rtb_hd) - rtb_Height;

  /* Sum: '<S11>/Add7' incorporates:
   *  Product: '<S30>/Product2'
   *  Sum: '<S30>/Subtract6'
   */
  rtb_aileron_cmd_out = (rtb_e_augm11_k * rtb_Subtract4 + rtb_nd) - rtb_North;

  /* Sum: '<S11>/Add6' incorporates:
   *  Product: '<S30>/Product3'
   *  Sum: '<S30>/Subtract1'
   */
  rtb_er_e = (rtb_e_augm11_k * rtb_Subtract5 + rtb_ed) - rtb_East;

  /* Outputs for Atomic SubSystem: '<S13>/Subsystem2' */
  NMPC_Controller_Subsystem1(rtb_aileron_cmd_out, rtb_er_e,
    &NMPC_Controller_B.Subsystem2);

  /* End of Outputs for SubSystem: '<S13>/Subsystem2' */

  /* Sum: '<S13>/Add2' incorporates:
   *  Trigonometry: '<S13>/Trigonometric Function3'
   */
  rtb_e_augm11_k = rt_atan2d_snf(rtb_Vab_mod, NMPC_Controller_B.Subsystem2.Sqrt)
    - rtb_TrigonometricFunction;

  /* Trigonometry: '<S13>/Trigonometric Function1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Inport: '<Root>/PIC//CIC'
   *  Product: '<S13>/Product4'
   */
  rtb_TrigonometricFunction1_a = atan(rtb_e_augm11_k * (real_T)
    NMPC_Controller_U.PICCIC);

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  Inport: '<Root>/PIC//CIC'
   */
  rtb_LogicalOperator = !NMPC_Controller_U.PICCIC;

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator ||
      (NMPC_Controller_DW.DiscreteTimeIntegrator_PrevResetState != 0)) {
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE = 0.0007255;
  }

  if (NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE >= 3.1415926535897931) {
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE = 3.1415926535897931;
  } else {
    if (NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE <= -3.1415926535897931)
    {
      NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE = -3.1415926535897931;
    }
  }

  rtb_DiscreteTimeIntegrator = NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outputs for Atomic SubSystem: '<S13>/Subsystem1' */
  NMPC_Controller_Subsystem1_j(rtb_er_e, rtb_aileron_cmd_out, rtb_Vab_mod,
    &NMPC_Controller_B.Subsystem1_j);

  /* End of Outputs for SubSystem: '<S13>/Subsystem1' */

  /* Trigonometry: '<S13>/Trigonometric Function2' incorporates:
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain2'
   *  Product: '<S13>/Product2'
   *  Sum: '<S13>/Sum'
   */
  rtb_e_augm21_k = rt_atan2d_snf((0.00625 * rtb_TrigonometricFunction1_a +
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE) * (2.0 *
    NMPC_Controller_B.Subsystem4.SumofElements),
    NMPC_Controller_B.Subsystem1_j.Sqrt);

  /* Sum: '<S11>/Add' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product4'
   *  Product: '<S11>/Product5'
   *  Product: '<S11>/Product6'
   */
  rtb_elevator_cmd_out = (rtb_Product4_i * rtb_z1_k * rtb_V_east +
    rtb_rudder_cmd_out * rtb_e_augm31_k) + rtb_z2_k * rtb_z1_k *
    rtb_throttle_cmd_out;

  /* Sum: '<S11>/Add1' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Product: '<S11>/Product7'
   *  Product: '<S11>/Product8'
   *  Product: '<S11>/Product9'
   */
  rtb_sw_time_out = (rtb_rudder_cmd_out * rtb_z1_k - rtb_Product4_i *
                     rtb_e_augm31_k * rtb_V_east) - rtb_z2_k * rtb_e_augm31_k *
    rtb_throttle_cmd_out;

  /* Outputs for Atomic SubSystem: '<S12>/Subsystem4' */
  NMPC_Controller_Subsystem4(rtb_elevator_cmd_out, rtb_sw_time_out,
    &NMPC_Controller_B.Subsystem4_h);

  /* End of Outputs for SubSystem: '<S12>/Subsystem4' */

  /* Sum: '<S11>/Add4' incorporates:
   *  Product: '<S11>/Product16'
   *  Product: '<S11>/Product17'
   *  Product: '<S11>/Product21'
   *  Product: '<S11>/Product22'
   *  Product: '<S11>/Product23'
   */
  rtb_throttle_cmd_out = (rtb_aileron_cmd_out * rtb_z1_k - rtb_Product4_i *
    rtb_e_augm31_k * rtb_er_e) - rtb_z2_k * rtb_e_augm31_k * rtb_Vab_mod;

  /* Sum: '<S11>/Add3' incorporates:
   *  Product: '<S11>/Product12'
   *  Product: '<S11>/Product13'
   *  Product: '<S11>/Product18'
   *  Product: '<S11>/Product19'
   *  Product: '<S11>/Product20'
   */
  rtb_er_e = (rtb_Product4_i * rtb_z1_k * rtb_er_e + rtb_aileron_cmd_out *
              rtb_e_augm31_k) + rtb_z2_k * rtb_z1_k * rtb_Vab_mod;

  /* Sum: '<S12>/Add2' incorporates:
   *  Trigonometry: '<S12>/Trigonometric Function'
   *  Trigonometry: '<S12>/Trigonometric Function1'
   */
  rtb_sw_time_out = rt_atan2d_snf(rtb_sw_time_out, rtb_elevator_cmd_out) -
    rt_atan2d_snf(rtb_throttle_cmd_out, rtb_er_e);

  /* MATLAB Function: '<S12>/Embedded MATLAB Function' */
  /* MATLAB Function 'Guidance System/Phi command/Embedded MATLAB Function': '<S20>:1' */
  /* '<S20>:1:3' */
  rtb_TrigonometricFunction = rtb_sw_time_out;
  if (rtb_sw_time_out > 3.1415926535897931) {
    /* '<S20>:1:5' */
    /* '<S20>:1:6' */
    rtb_TrigonometricFunction = rtb_sw_time_out - 6.2831853071795862;
  }

  if (rtb_sw_time_out < -3.1415926535897931) {
    /* '<S20>:1:9' */
    /* '<S20>:1:10' */
    rtb_TrigonometricFunction = rtb_sw_time_out + 6.2831853071795862;
  }

  /* End of MATLAB Function: '<S12>/Embedded MATLAB Function' */

  /* Product: '<S12>/Product4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Inport: '<Root>/PIC//CIC'
   */
  rtb_Product4_i = rtb_TrigonometricFunction * (real_T)NMPC_Controller_U.PICCIC;

  /* Logic: '<S12>/Logical Operator' incorporates:
   *  Inport: '<Root>/PIC//CIC'
   */
  rtb_LogicalOperator_f = !NMPC_Controller_U.PICCIC;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator_f ||
      (NMPC_Controller_DW.DiscreteTimeIntegrator_PrevResetState_f != 0)) {
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h = 0.0;
  }

  if (NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h >= 3.1415926535897931)
  {
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h = 3.1415926535897931;
  } else {
    if (NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h <=
        -3.1415926535897931) {
      NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h = -3.1415926535897931;
    }
  }

  /* Outputs for Atomic SubSystem: '<S12>/Subsystem1' */
  NMPC_Controller_Subsystem1(rtb_er_e, rtb_throttle_cmd_out,
    &NMPC_Controller_B.Subsystem1_a);

  /* End of Outputs for SubSystem: '<S12>/Subsystem1' */

  /* Trigonometry: '<S12>/Trigonometric Function3' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S12>/Gain2'
   *  Product: '<S12>/Product'
   *  Sum: '<S12>/Sum'
   */
  rtb_e_augm31_k = rt_atan2d_snf((0.015625 * rtb_Product4_i +
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h) * (2.0 *
    NMPC_Controller_B.Subsystem4_h.SumofElements),
    NMPC_Controller_B.Subsystem1_a.Sqrt);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_Commanded States_at_inport_0' incorporates:
   *  Constant: '<S10>/Beta command'
   */
  NMPC_Controller_Y.CommandedStates.VT_cmd = NMPC_Controller_B.Subsystem1.Sqrt;
  NMPC_Controller_Y.CommandedStates.theta_cmd = rtb_e_augm21_k;
  NMPC_Controller_Y.CommandedStates.phi_cmd = rtb_e_augm31_k;
  NMPC_Controller_Y.CommandedStates.beta_cmd = 0.0;

  /* Outport: '<Root>/Track Angles' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_Track Angles_at_inport_0'
   */
  NMPC_Controller_Y.TrackAngles.etaLat = rtb_TrigonometricFunction;
  NMPC_Controller_Y.TrackAngles.etaLon = rtb_e_augm11_k;

  /* Outport: '<Root>/Distance to Waypoint' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  NMPC_Controller_Y.DistancetoWaypoint = (real32_T)distance;

  /* Outport: '<Root>/Waypoint Index' incorporates:
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  NMPC_Controller_Y.WaypointIndex = b_index;

  /* UnitDelay: '<S34>/Unit Delay' */
  rtb_xw11_k = NMPC_Controller_DW.UnitDelay_DSTATE_p;

  /* UnitDelay: '<S34>/Unit Delay1' */
  rtb_xw12_k = NMPC_Controller_DW.UnitDelay1_DSTATE;

  /* UnitDelay: '<S34>/Unit Delay2' */
  rtb_xw13_k = NMPC_Controller_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S34>/Unit Delay3' */
  rtb_xw14_k = NMPC_Controller_DW.UnitDelay3_DSTATE;

  /* UnitDelay: '<S35>/Unit Delay' */
  rtb_xw21_k = NMPC_Controller_DW.UnitDelay_DSTATE_j;

  /* UnitDelay: '<S35>/Unit Delay1' */
  rtb_xw22_k = NMPC_Controller_DW.UnitDelay1_DSTATE_g;

  /* UnitDelay: '<S35>/Unit Delay2' */
  rtb_xw23_k = NMPC_Controller_DW.UnitDelay2_DSTATE_a;

  /* UnitDelay: '<S35>/Unit Delay3' */
  rtb_xw24_k = NMPC_Controller_DW.UnitDelay3_DSTATE_g;

  /* UnitDelay: '<S36>/Unit Delay' */
  rtb_xw31_k = NMPC_Controller_DW.UnitDelay_DSTATE_m;

  /* UnitDelay: '<S36>/Unit Delay1' */
  rtb_xw32_k = NMPC_Controller_DW.UnitDelay1_DSTATE_m;

  /* UnitDelay: '<S36>/Unit Delay2' */
  rtb_xw33_k = NMPC_Controller_DW.UnitDelay2_DSTATE_p;

  /* UnitDelay: '<S36>/Unit Delay3' */
  rtb_xw34_k = NMPC_Controller_DW.UnitDelay3_DSTATE_j;

  /* Sum: '<S7>/Add' incorporates:
   *  Inport: '<Root>/VT, alpha, beta'
   */
  rtb_e_augm11_k = NMPC_Controller_B.Subsystem1.Sqrt -
    NMPC_Controller_U.VTalphabeta.VT;

  /* Sum: '<S7>/Add1' incorporates:
   *  Inport: '<Root>/phi, theta, psi'
   */
  rtb_e_augm21_k -= NMPC_Controller_U.phithetapsi.theta;

  /* Sum: '<S7>/Add2' incorporates:
   *  Inport: '<Root>/phi, theta, psi'
   */
  rtb_e_augm31_k -= NMPC_Controller_U.phithetapsi.phi;

  /* Sum: '<S7>/Add3' incorporates:
   *  Constant: '<S10>/Beta command'
   *  Inport: '<Root>/VT, alpha, beta'
   */
  rtb_e_augm41_k = 0.0 - NMPC_Controller_U.VTalphabeta.beta;

  /* Outport: '<Root>/W_data' incorporates:
   *  Constant: '<S10>/Beta command'
   *  DataStoreRead: '<Root>/Data Store Read1'
   *  Gain: '<S34>/Gain10'
   *  Gain: '<S34>/Gain11'
   *  Gain: '<S34>/Gain12'
   *  Gain: '<S34>/Gain13'
   *  Gain: '<S34>/Gain14'
   *  Gain: '<S34>/Gain15'
   *  Gain: '<S34>/Gain16'
   *  Gain: '<S34>/Gain9'
   *  Gain: '<S35>/Gain11'
   *  Gain: '<S35>/Gain12'
   *  Gain: '<S35>/Gain13'
   *  Gain: '<S35>/Gain14'
   *  Gain: '<S35>/Gain15'
   *  Gain: '<S35>/Gain16'
   *  Gain: '<S35>/Gain7'
   *  Gain: '<S35>/Gain8'
   *  Gain: '<S36>/Gain11'
   *  Gain: '<S36>/Gain12'
   *  Gain: '<S36>/Gain13'
   *  Gain: '<S36>/Gain14'
   *  Gain: '<S36>/Gain15'
   *  Gain: '<S36>/Gain16'
   *  Gain: '<S36>/Gain7'
   *  Gain: '<S36>/Gain8'
   *  Inport: '<Root>/VT, alpha, beta'
   *  Inport: '<Root>/phi, theta, psi'
   *  Sum: '<S34>/Add1'
   *  Sum: '<S34>/Add2'
   *  Sum: '<S34>/Add3'
   *  Sum: '<S34>/Add8'
   *  Sum: '<S35>/Add1'
   *  Sum: '<S35>/Add2'
   *  Sum: '<S35>/Add3'
   *  Sum: '<S35>/Add8'
   *  Sum: '<S36>/Add1'
   *  Sum: '<S36>/Add2'
   *  Sum: '<S36>/Add3'
   *  Sum: '<S36>/Add8'
   *  Sum: '<S7>/Add3'
   *  UnitDelay: '<S34>/Unit Delay'
   *  UnitDelay: '<S34>/Unit Delay1'
   *  UnitDelay: '<S34>/Unit Delay2'
   *  UnitDelay: '<S34>/Unit Delay3'
   *  UnitDelay: '<S35>/Unit Delay'
   *  UnitDelay: '<S35>/Unit Delay1'
   *  UnitDelay: '<S35>/Unit Delay2'
   *  UnitDelay: '<S35>/Unit Delay3'
   *  UnitDelay: '<S36>/Unit Delay'
   *  UnitDelay: '<S36>/Unit Delay1'
   *  UnitDelay: '<S36>/Unit Delay2'
   *  UnitDelay: '<S36>/Unit Delay3'
   */
  NMPC_Controller_Y.W_data[0] = NMPC_Controller_DW.UnitDelay_DSTATE_p;
  NMPC_Controller_Y.W_data[1] = NMPC_Controller_DW.UnitDelay1_DSTATE;
  NMPC_Controller_Y.W_data[2] = NMPC_Controller_DW.UnitDelay2_DSTATE;
  NMPC_Controller_Y.W_data[3] = NMPC_Controller_DW.UnitDelay3_DSTATE;
  NMPC_Controller_Y.W_data[4] = NMPC_Controller_DW.UnitDelay_DSTATE_j;
  NMPC_Controller_Y.W_data[5] = NMPC_Controller_DW.UnitDelay1_DSTATE_g;
  NMPC_Controller_Y.W_data[6] = NMPC_Controller_DW.UnitDelay2_DSTATE_a;
  NMPC_Controller_Y.W_data[7] = NMPC_Controller_DW.UnitDelay3_DSTATE_g;
  NMPC_Controller_Y.W_data[8] = NMPC_Controller_DW.UnitDelay_DSTATE_m;
  NMPC_Controller_Y.W_data[9] = NMPC_Controller_DW.UnitDelay1_DSTATE_m;
  NMPC_Controller_Y.W_data[10] = NMPC_Controller_DW.UnitDelay2_DSTATE_p;
  NMPC_Controller_Y.W_data[11] = NMPC_Controller_DW.UnitDelay3_DSTATE_j;
  NMPC_Controller_Y.W_data[12] = 0.0005 * rtb_e_augm11_k + 0.39999598002686648 *
    NMPC_Controller_DW.UnitDelay_DSTATE_p;
  NMPC_Controller_Y.W_data[13] = 0.0005 * rtb_e_augm21_k + 0.39999598002686648 *
    NMPC_Controller_DW.UnitDelay1_DSTATE;
  NMPC_Controller_Y.W_data[14] = 0.0005 * rtb_e_augm31_k + 0.39999598002686648 *
    NMPC_Controller_DW.UnitDelay2_DSTATE;
  NMPC_Controller_Y.W_data[15] = (0.0 - NMPC_Controller_U.VTalphabeta.beta) *
    0.0005 + 0.39999598002686648 * NMPC_Controller_DW.UnitDelay3_DSTATE;
  NMPC_Controller_Y.W_data[16] = 5.0251256281407031 * NMPC_Controller_DW.u_nmpc
    [0] + -1.0942718103248184 * NMPC_Controller_DW.UnitDelay_DSTATE_j;
  NMPC_Controller_Y.W_data[17] = 5.0251256281407031 * NMPC_Controller_DW.u_nmpc
    [1] + -1.0942718103248184 * NMPC_Controller_DW.UnitDelay1_DSTATE_g;
  NMPC_Controller_Y.W_data[18] = 5.0251256281407031 * NMPC_Controller_DW.u_nmpc
    [2] + -0.89451227385639021 * NMPC_Controller_DW.UnitDelay2_DSTATE_a;
  NMPC_Controller_Y.W_data[19] = 5.0251256281407031 * NMPC_Controller_DW.u_nmpc
    [3] + -0.89451227385639021 * NMPC_Controller_DW.UnitDelay3_DSTATE_g;
  NMPC_Controller_Y.W_data[20] = 3.3333333333333335 *
    NMPC_Controller_U.VTalphabeta.VT + -1.6219186074139784 *
    NMPC_Controller_DW.UnitDelay_DSTATE_m;
  NMPC_Controller_Y.W_data[21] = 3.3333333333333335 *
    NMPC_Controller_U.phithetapsi.theta + -1.6219186074139784 *
    NMPC_Controller_DW.UnitDelay1_DSTATE_m;
  NMPC_Controller_Y.W_data[22] = 3.3333333333333335 *
    NMPC_Controller_U.phithetapsi.phi + -1.6219186074139784 *
    NMPC_Controller_DW.UnitDelay2_DSTATE_p;
  NMPC_Controller_Y.W_data[23] = 3.3333333333333335 *
    NMPC_Controller_U.VTalphabeta.beta + -1.6219186074139784 *
    NMPC_Controller_DW.UnitDelay3_DSTATE_j;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_Control System_at_inport_2' incorporates:
   *  Inport: '<Root>/wpts'
   */
  rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_0 =
    NMPC_Controller_U.wpts.fp;
  rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_1 =
    NMPC_Controller_U.wpts.rp;
  for (i_0 = 0; i_0 < 32; i_0++) {
    /* BusCreator: '<Root>/BusConversion_InsertedFor_Control System_at_inport_2' incorporates:
     *  Inport: '<Root>/wpts'
     */
    wpts_h[i_0] = NMPC_Controller_U.wpts.h[i_0];
    wpts_n[i_0] = NMPC_Controller_U.wpts.n[i_0];
    wpts_e[i_0] = NMPC_Controller_U.wpts.e[i_0];
    rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_2[i_0] =
      NMPC_Controller_U.wpts.v[i_0];
  }

  /* SampleTimeMath: '<S2>/TSamp' incorporates:
   *  Inport: '<Root>/VT, alpha, beta'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = NMPC_Controller_U.VTalphabeta.alpha * 20.0;

  /* Sum: '<S2>/Diff' incorporates:
   *  UnitDelay: '<S2>/UD'
   */
  rtb_sw_time_out = rtb_TSamp - NMPC_Controller_DW.UD_DSTATE;

  /* SampleTimeMath: '<S3>/TSamp' incorporates:
   *  Inport: '<Root>/VT, alpha, beta'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_d = NMPC_Controller_U.VTalphabeta.beta * 20.0;

  /* Sum: '<S3>/Diff' incorporates:
   *  UnitDelay: '<S3>/UD'
   */
  rtb_throttle_cmd_out = rtb_TSamp_d - NMPC_Controller_DW.UD_DSTATE_j;

  /* Delay: '<Root>/Delay 5 seconds' incorporates:
   *  Inport: '<Root>/FL_ann'
   */
  /*zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                     &NMPC_Controller_PrevZCX.Delay5seconds_Reset_ZCE,
                     (NMPC_Controller_U.FL_ann));*/
  if (zcEvent != NO_ZCEVENT) {
    memset(&NMPC_Controller_DW.Delay5seconds_DSTATE[0], 0, 100U * sizeof(real_T));
  }

  /* MATLAB Function: '<Root>/Control System' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   *  Delay: '<Root>/Delay 5 seconds'
   *  Inport: '<Root>/Home Cmd'
   *  Inport: '<Root>/P,Q,R'
   *  Inport: '<Root>/Servo deflection'
   *  Inport: '<Root>/VT, alpha, beta'
   *  Inport: '<Root>/a_ann_X'
   *  Inport: '<Root>/a_ann_Y'
   *  Inport: '<Root>/a_ann_Z'
   *  Inport: '<Root>/b_ann_X'
   *  Inport: '<Root>/b_ann_Y'
   *  Inport: '<Root>/b_ann_Z'
   *  Inport: '<Root>/c_ann_X'
   *  Inport: '<Root>/c_ann_Y'
   *  Inport: '<Root>/c_ann_Z'
   *  Inport: '<Root>/e_op'
   *  Inport: '<Root>/h_op'
   *  Inport: '<Root>/n_op'
   *  Inport: '<Root>/phi, theta, psi'
   *  Inport: '<Root>/ve_op'
   *  Inport: '<Root>/vh_op'
   *  Inport: '<Root>/vn_op'
   *  Inport: '<Root>/w_ann_X'
   *  Inport: '<Root>/w_ann_Y'
   *  Inport: '<Root>/w_ann_Z'
   *  MATLAB Function: '<S8>/Trajectory Generation'
   */
  /* MATLAB Function 'Control System': '<S1>:1' */
  /* %allocation */
  /* '<S1>:1:59' */
  memset(&z_augm_hor[0], 0, 252U * sizeof(real_T));

  /* %nmpc input */
  /* '<S1>:1:62' */
  /* %state horizon */
  /* '<S1>:1:64' */
  /* '<S1>:1:65' */
  /* '<S1>:1:66' */
  /* '<S1>:1:67' */
  /* '<S1>:1:68' */
  /* '<S1>:1:69' */
  /* '<S1>:1:70' */
  /* '<S1>:1:71' */
  /* '<S1>:1:72' */
  /* '<S1>:1:73' */
  /* '<S1>:1:74' */
  /* '<S1>:1:75' */
  /* '<S1>:1:76' */
  /* '<S1>:1:77' */
  /* '<S1>:1:78' */
  /* '<S1>:1:79' */
  /* '<S1>:1:80' */
  for (i_0 = 0; i_0 < 21; i_0++) {
    n_hor[i_0] = 0.0;
    e_hor[i_0] = 0.0;
    h_hor[i_0] = 0.0;
    THL_hor[i_0] = 0.0;
    EL_hor[i_0] = 0.0;
    AIL_hor[i_0] = 0.0;
    RDR_hor[i_0] = 0.0;
    VT_hor[i_0] = 0.0;
    alpha_hor[i_0] = 0.0;
    beta_hor[i_0] = 0.0;
    phi_hor[i_0] = 0.0;
    theta_hor[i_0] = 0.0;
    psi_hor[i_0] = 0.0;
    P_hor[i_0] = 0.0;
    Q_hor[i_0] = 0.0;
    R_hor[i_0] = 0.0;
    wpt_index_hor[i_0] = 0.0;
  }

  /* '<S1>:1:81' */
  memset(&start_wpt_hor[0], 0, 63U * sizeof(real_T));

  /* '<S1>:1:82' */
  /* '<S1>:1:83' */
  /* '<S1>:1:84' */
  /* '<S1>:1:85' */
  /* '<S1>:1:86' */
  /* '<S1>:1:87' */
  /* '<S1>:1:88' */
  /* '<S1>:1:89' */
  /* '<S1>:1:90' */
  /* '<S1>:1:91' */
  /* '<S1>:1:92' */
  /* '<S1>:1:93' */
  /* '<S1>:1:94' */
  /* '<S1>:1:95' */
  /* '<S1>:1:96' */
  /* '<S1>:1:97' */
  /* '<S1>:1:98' */
  for (i_0 = 0; i_0 < 21; i_0++) {
    pic_cic_hor[i_0] = 0.0;
    home_reset_hor[i_0] = 0.0;
    alphadot_hor[i_0] = 0.0;
    betadot_hor[i_0] = 0.0;
    ro_hor[i_0] = 0.0;
    xw11_hor[i_0] = 0.0;
    xw12_hor[i_0] = 0.0;
    xw13_hor[i_0] = 0.0;
    xw14_hor[i_0] = 0.0;
    xw21_hor[i_0] = 0.0;
    xw22_hor[i_0] = 0.0;
    xw23_hor[i_0] = 0.0;
    xw24_hor[i_0] = 0.0;
    xw31_hor[i_0] = 0.0;
    xw32_hor[i_0] = 0.0;
    xw33_hor[i_0] = 0.0;
    xw34_hor[i_0] = 0.0;
  }

  /* %%%horizon prediction: x_1 to x_N_nmpc+1%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %servo commands%% */
  /* '<S1>:1:103' */
  /* '<S1>:1:104' */
  /* '<S1>:1:105' */
  /* '<S1>:1:106' */
  /*  %assumed zero wind */
  for (i_0 = 0; i_0 < 32; i_0++) {
    wpts_h_0[i_0] = wpts_h[i_0];
    wpts_n_0[i_0] = wpts_n[i_0];
    wpts_e_0[i_0] = wpts_e[i_0];
  }

  NMPC_Controller_uas_augm_model((real_T)rtb_DataTypeConversion1,
    NMPC_Controller_U.HomeCmd, 0.05, 1.0,
    rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_0,
    rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_1, wpts_h_0,
    wpts_n_0, wpts_e_0,
    rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_2,
    NMPC_Controller_U.n_op[0], NMPC_Controller_U.e_op[0],
    NMPC_Controller_U.h_op[0], NMPC_Controller_U.vn_op[0],
    NMPC_Controller_U.ve_op[0], NMPC_Controller_U.vh_op[0], rtb_sw_time_out,
    rtb_throttle_cmd_out, b_index, rtb_start_wpt_mem, rtb_pic_cic_out,
    home_reset_out, NMPC_Controller_U.Servodeflection[0],
    NMPC_Controller_U.Servodeflection[1], NMPC_Controller_U.Servodeflection[2],
    NMPC_Controller_U.Servodeflection[3], NMPC_Controller_U.VTalphabeta.VT,
    NMPC_Controller_U.VTalphabeta.alpha, NMPC_Controller_U.VTalphabeta.beta,
    NMPC_Controller_U.phithetapsi.phi, NMPC_Controller_U.phithetapsi.theta,
    NMPC_Controller_U.phithetapsi.psi, NMPC_Controller_U.PQR.P,
    NMPC_Controller_U.PQR.Q, NMPC_Controller_U.PQR.R, rtb_North, rtb_East,
    rtb_Height, rtb_DiscreteTimeIntegrator, NMPC_Controller_DW.u_nmpc[0],
    NMPC_Controller_DW.u_nmpc[1], NMPC_Controller_DW.u_nmpc[2],
    NMPC_Controller_DW.u_nmpc[3], rtb_xw11_k, rtb_xw12_k, rtb_xw13_k, rtb_xw14_k,
    rtb_xw21_k, rtb_xw22_k, rtb_xw23_k, rtb_xw24_k, rtb_xw31_k, rtb_xw32_k,
    rtb_xw33_k, rtb_xw34_k, NMPC_Controller_ConstP.pooled1,
    NMPC_Controller_ConstP.pooled1, NMPC_Controller_ConstP.pooled1,
    NMPC_Controller_ConstP.pooled1, NMPC_Controller_ConstP.pooled2,
    NMPC_Controller_ConstP.pooled2, NMPC_Controller_ConstP.pooled3,
    NMPC_Controller_ConstP.pooled3, NMPC_Controller_ConstP.pooled4,
    NMPC_Controller_ConstP.pooled4, NMPC_Controller_ConstP.pooled4,
    NMPC_Controller_ConstP.pooled4, 0.002295, 21.11, 2.19, 10.16, 59.0, 32.174,
    4.2, 9.9, 11.5, 0.0, 0.0, 0.0, 0.0, -0.00025, 0.0183, -0.35488, 0.01681,
    0.314151, 0.0, 0.258448, -0.00419, 4.609306, 6.450127, 1.904332, 0.001916,
    0.430417, -0.03114, -0.37443, 0.072757, 0.259592, 0.018248, 0.012115,
    -0.86779, -9.50961, -4.74712, 0.000264, -1.07294, 0.126004, -0.02996,
    -0.17559, -0.01165, -0.14802, 0.4301, -0.0025080000000000002, 0.0052503, 0.0,
    -0.00020412914737191596, 0.0, 99.998552624300657, -10.0, 10.0, -14.28, 14.28,
    -14.28, 14.28, -5.0, 5.0, 1.0, 0.15, 0.26179938779914941,
    -0.26179938779914941, 0.3490658503988659, -0.3490658503988659,
    0.17453292519943295, -0.17453292519943295, 0.015625, 0.00093750000000000018,
    0.00625, 300.0, 320.0, NMPC_Controller_DW.Delay5seconds_DSTATE[0],
    NMPC_Controller_U.a_ann_X, NMPC_Controller_U.b_ann_X,
    NMPC_Controller_U.c_ann_X, NMPC_Controller_U.w_ann_X,
    NMPC_Controller_U.a_ann_Y, NMPC_Controller_U.b_ann_Y,
    NMPC_Controller_U.c_ann_Y, NMPC_Controller_U.w_ann_Y,
    NMPC_Controller_U.a_ann_Z, NMPC_Controller_U.b_ann_Z,
    NMPC_Controller_U.c_ann_Z, NMPC_Controller_U.w_ann_Z,
    NMPC_Controller_ConstP.pooled17, NMPC_Controller_ConstP.pooled15, -1.0, 1.0,
    0.01, 0.2, -1.0, 1.0, NMPC_Controller_ConstP.ControlSystem_Y_minXin,
    NMPC_Controller_ConstP.ControlSystem_Y_maxXin, -1.0, 1.0, -0.2, 0.2, -1.0,
    1.0, NMPC_Controller_ConstP.pooled17, NMPC_Controller_ConstP.pooled15, -1.0,
    1.0, -3.0, -0.5, -1.0, 1.0, &unusedU0, &next_wpt_index,
    &rtb_elevator_cmd_out, &f, &rtb_aileron_cmd_out, &rtb_rudder_cmd_out,
    &rtb_Subtract4, &rtb_Subtract5, &rtb_TrigonometricFunction, &rtb_er_e,
    &rtb_V_east, &rtb_Vab_mod, &rtb_Add9, &rtb_Add5, &rtb_ed, &rtb_hd, &rtb_nd,
    &rtb_z1_k, &rtb_z2_k, h, i, &distance, &k, &l, &m, &n, &o, &p, &q, &r, &s,
    &t, &u, &v, &w, &x, &y, &ab, &bb, &cb, &db, &eb, &fb, &gb, &hb, &ib, &jb,
    &kb, &lb, &mb, &nb, &ob);

  /* '<S1>:1:109' */
  wpt_index_hor[0] = next_wpt_index;

  /* '<S1>:1:109' */
  start_wpt_hor[0] = rtb_start_wpt_mem[0];
  start_wpt_hor[1] = rtb_start_wpt_mem[1];
  start_wpt_hor[2] = rtb_start_wpt_mem[2];

  /* '<S1>:1:109' */
  pic_cic_hor[0] = rtb_elevator_cmd_out;

  /* '<S1>:1:109' */
  home_reset_hor[0] = f;

  /* '<S1>:1:117' */
  memcpy(&z_augm_hor[0], &h[0], 12U * sizeof(real_T));

  /* '<S1>:1:118' */
  THL_hor[0] = distance;

  /* '<S1>:1:118' */
  EL_hor[0] = k;

  /* '<S1>:1:118' */
  AIL_hor[0] = l;

  /* '<S1>:1:118' */
  RDR_hor[0] = m;

  /* '<S1>:1:119' */
  VT_hor[0] = n;

  /* '<S1>:1:119' */
  alpha_hor[0] = o;

  /* '<S1>:1:119' */
  beta_hor[0] = p;

  /* '<S1>:1:119' */
  phi_hor[0] = q;

  /* '<S1>:1:119' */
  theta_hor[0] = r;

  /* '<S1>:1:119' */
  psi_hor[0] = s;

  /* '<S1>:1:119' */
  P_hor[0] = t;

  /* '<S1>:1:119' */
  Q_hor[0] = u;

  /* '<S1>:1:119' */
  R_hor[0] = v;

  /* '<S1>:1:120' */
  alphadot_hor[0] = w;

  /* '<S1>:1:120' */
  betadot_hor[0] = x;

  /* '<S1>:1:121' */
  n_hor[0] = y;

  /* '<S1>:1:121' */
  e_hor[0] = ab;

  /* '<S1>:1:121' */
  h_hor[0] = bb;

  /* '<S1>:1:122' */
  ro_hor[0] = cb;

  /* '<S1>:1:123' */
  xw11_hor[0] = db;

  /* '<S1>:1:123' */
  xw12_hor[0] = eb;

  /* '<S1>:1:123' */
  xw13_hor[0] = fb;

  /* '<S1>:1:123' */
  xw14_hor[0] = gb;

  /* '<S1>:1:124' */
  xw21_hor[0] = hb;

  /* '<S1>:1:124' */
  xw22_hor[0] = ib;

  /* '<S1>:1:124' */
  xw23_hor[0] = jb;

  /* '<S1>:1:124' */
  xw24_hor[0] = kb;

  /* '<S1>:1:125' */
  xw31_hor[0] = lb;

  /* '<S1>:1:125' */
  xw32_hor[0] = mb;

  /* '<S1>:1:125' */
  xw33_hor[0] = nb;

  /* '<S1>:1:125' */
  xw34_hor[0] = ob;

  /* %horizon */
  /* '<S1>:1:180' */
  for (i_0 = 0; i_0 < 20; i_0++) {
    u_hor[i_0 << 2] = NMPC_Controller_DW.u_nmpc[(1 + i_0) << 2];
    u_hor[1 + (i_0 << 2)] = NMPC_Controller_DW.u_nmpc[((1 + i_0) << 2) + 1];
    u_hor[2 + (i_0 << 2)] = NMPC_Controller_DW.u_nmpc[((1 + i_0) << 2) + 2];
    u_hor[3 + (i_0 << 2)] = NMPC_Controller_DW.u_nmpc[((1 + i_0) << 2) + 3];
  }

  u_hor[80] = NMPC_Controller_DW.u_nmpc[80];
  u_hor[81] = NMPC_Controller_DW.u_nmpc[81];
  u_hor[82] = NMPC_Controller_DW.u_nmpc[82];
  u_hor[83] = NMPC_Controller_DW.u_nmpc[83];

  /* '<S1>:1:182' */
  for (factor = 0; factor < 20; factor++) {
    /* '<S1>:1:182' */
    /*  %assumed zero wind */
    rtb_start_wpt_mem[0] = start_wpt_hor[3 * factor];
    rtb_start_wpt_mem[1] = start_wpt_hor[3 * factor + 1];
    rtb_start_wpt_mem[2] = start_wpt_hor[3 * factor + 2];
    for (i_0 = 0; i_0 < 32; i_0++) {
      wpts_h_0[i_0] = wpts_h[i_0];
      wpts_n_0[i_0] = wpts_n[i_0];
      wpts_e_0[i_0] = wpts_e[i_0];
    }

    NMPC_Controller_uas_augm_model_b((real_T)rtb_DataTypeConversion1,
      NMPC_Controller_U.HomeCmd, 0.05, 1.0,
      rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_0,
      rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_1, wpts_h_0,
      wpts_n_0, wpts_e_0,
      rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_2,
      NMPC_Controller_U.n_op[1 + factor], NMPC_Controller_U.e_op[1 + factor],
      NMPC_Controller_U.h_op[1 + factor], NMPC_Controller_U.vn_op[1 + factor],
      NMPC_Controller_U.ve_op[1 + factor], NMPC_Controller_U.vh_op[1 + factor],
      alphadot_hor[factor], betadot_hor[factor], wpt_index_hor[factor],
      rtb_start_wpt_mem, pic_cic_hor[factor], home_reset_hor[factor],
      THL_hor[factor], EL_hor[factor], AIL_hor[factor], RDR_hor[factor],
      VT_hor[factor], alpha_hor[factor], beta_hor[factor], phi_hor[factor],
      theta_hor[factor], psi_hor[factor], P_hor[factor], Q_hor[factor],
      R_hor[factor], n_hor[factor], e_hor[factor], h_hor[factor], ro_hor[factor],
      u_hor[factor << 2], u_hor[1 + (factor << 2)], u_hor[2 + (factor << 2)],
      u_hor[3 + (factor << 2)], xw11_hor[factor], xw12_hor[factor],
      xw13_hor[factor], xw14_hor[factor], xw21_hor[factor], xw22_hor[factor],
      xw23_hor[factor], xw24_hor[factor], xw31_hor[factor], xw32_hor[factor],
      xw33_hor[factor], xw34_hor[factor], NMPC_Controller_ConstP.pooled1,
      NMPC_Controller_ConstP.pooled1, NMPC_Controller_ConstP.pooled1,
      NMPC_Controller_ConstP.pooled1, NMPC_Controller_ConstP.pooled2,
      NMPC_Controller_ConstP.pooled2, NMPC_Controller_ConstP.pooled3,
      NMPC_Controller_ConstP.pooled3, NMPC_Controller_ConstP.pooled4,
      NMPC_Controller_ConstP.pooled4, NMPC_Controller_ConstP.pooled4,
      NMPC_Controller_ConstP.pooled4, 0.002295, 21.11, 2.19, 10.16, 59.0, 32.174,
      4.2, 9.9, 11.5, 0.0, 0.0, 0.0, 0.0, -0.00025, 0.0183, -0.35488, 0.01681,
      0.314151, 0.0, 0.258448, -0.00419, 4.609306, 6.450127, 1.904332, 0.001916,
      0.430417, -0.03114, -0.37443, 0.072757, 0.259592, 0.018248, 0.012115,
      -0.86779, -9.50961, -4.74712, 0.000264, -1.07294, 0.126004, -0.02996,
      -0.17559, -0.01165, -0.14802, 0.4301, -0.0025080000000000002, 0.0052503,
      0.0, -0.00020412914737191596, 0.0, 99.998552624300657, -10.0, 10.0, -14.28,
      14.28, -14.28, 14.28, -5.0, 5.0, 1.0, 0.15, 0.26179938779914941,
      -0.26179938779914941, 0.3490658503988659, -0.3490658503988659,
      0.17453292519943295, -0.17453292519943295, 0.015625,
      0.00093750000000000018, 0.00625, 300.0, 320.0,
      NMPC_Controller_DW.Delay5seconds_DSTATE[0], NMPC_Controller_U.a_ann_X,
      NMPC_Controller_U.b_ann_X, NMPC_Controller_U.c_ann_X,
      NMPC_Controller_U.w_ann_X, NMPC_Controller_U.a_ann_Y,
      NMPC_Controller_U.b_ann_Y, NMPC_Controller_U.c_ann_Y,
      NMPC_Controller_U.w_ann_Y, NMPC_Controller_U.a_ann_Z,
      NMPC_Controller_U.b_ann_Z, NMPC_Controller_U.c_ann_Z,
      NMPC_Controller_U.w_ann_Z, NMPC_Controller_ConstP.pooled17,
      NMPC_Controller_ConstP.pooled15, -1.0, 1.0, 0.01, 0.2, -1.0, 1.0,
      NMPC_Controller_ConstP.ControlSystem_Y_minXin,
      NMPC_Controller_ConstP.ControlSystem_Y_maxXin, -1.0, 1.0, -0.2, 0.2, -1.0,
      1.0, NMPC_Controller_ConstP.pooled17, NMPC_Controller_ConstP.pooled15,
      -1.0, 1.0, -3.0, -0.5, -1.0, 1.0, &unusedU0, &next_wpt_index,
      &rtb_sw_time_out, &f, &rtb_throttle_cmd_out, &rtb_elevator_cmd_out,
      &rtb_aileron_cmd_out, &rtb_rudder_cmd_out, &rtb_Subtract4, &rtb_Subtract5,
      &rtb_TrigonometricFunction, &rtb_er_e, &rtb_V_east, &rtb_Vab_mod,
      &rtb_Add9, &rtb_Add5, &rtb_ed, &rtb_hd, &rtb_nd, h, i, &rtb_z1_k,
      &rtb_z2_k, &distance, &k, &l, &m, &n, &o, &p, &q, &r, &s, &t, &u, &v, &w,
      &x, &y, &ab, &bb, &cb, &db, &eb, &fb, &gb, &hb, &ib, &jb, &kb, &lb, &mb);

    /* '<S1>:1:185' */
    wpt_index_hor[1 + factor] = next_wpt_index;

    /* '<S1>:1:185' */
    start_wpt_hor[3 * (factor + 1)] = rtb_start_wpt_mem[0];
    start_wpt_hor[1 + 3 * (factor + 1)] = rtb_start_wpt_mem[1];
    start_wpt_hor[2 + 3 * (factor + 1)] = rtb_start_wpt_mem[2];

    /* '<S1>:1:185' */
    pic_cic_hor[1 + factor] = rtb_sw_time_out;

    /* '<S1>:1:185' */
    home_reset_hor[1 + factor] = f;

    /* '<S1>:1:193' */
    memcpy(&z_augm_hor[12 * (factor + 1)], &h[0], 12U * sizeof(real_T));

    /* '<S1>:1:194' */
    THL_hor[1 + factor] = rtb_z1_k;

    /* '<S1>:1:194' */
    EL_hor[1 + factor] = rtb_z2_k;

    /* '<S1>:1:194' */
    AIL_hor[1 + factor] = distance;

    /* '<S1>:1:194' */
    RDR_hor[1 + factor] = k;

    /* '<S1>:1:195' */
    VT_hor[1 + factor] = l;

    /* '<S1>:1:195' */
    alpha_hor[1 + factor] = m;

    /* '<S1>:1:195' */
    beta_hor[1 + factor] = n;

    /* '<S1>:1:195' */
    phi_hor[1 + factor] = o;

    /* '<S1>:1:195' */
    theta_hor[1 + factor] = p;

    /* '<S1>:1:195' */
    psi_hor[1 + factor] = q;

    /* '<S1>:1:195' */
    P_hor[1 + factor] = r;

    /* '<S1>:1:195' */
    Q_hor[1 + factor] = s;

    /* '<S1>:1:195' */
    R_hor[1 + factor] = t;

    /* '<S1>:1:196' */
    alphadot_hor[1 + factor] = u;

    /* '<S1>:1:196' */
    betadot_hor[1 + factor] = v;

    /* '<S1>:1:197' */
    n_hor[1 + factor] = w;

    /* '<S1>:1:197' */
    e_hor[1 + factor] = x;

    /* '<S1>:1:197' */
    h_hor[1 + factor] = y;

    /* '<S1>:1:198' */
    ro_hor[1 + factor] = ab;

    /* '<S1>:1:199' */
    xw11_hor[1 + factor] = bb;

    /* '<S1>:1:199' */
    xw12_hor[1 + factor] = cb;

    /* '<S1>:1:199' */
    xw13_hor[1 + factor] = db;

    /* '<S1>:1:199' */
    xw14_hor[1 + factor] = eb;

    /* '<S1>:1:200' */
    xw21_hor[1 + factor] = fb;

    /* '<S1>:1:200' */
    xw22_hor[1 + factor] = gb;

    /* '<S1>:1:200' */
    xw23_hor[1 + factor] = hb;

    /* '<S1>:1:200' */
    xw24_hor[1 + factor] = ib;

    /* '<S1>:1:201' */
    xw31_hor[1 + factor] = jb;

    /* '<S1>:1:201' */
    xw32_hor[1 + factor] = kb;

    /* '<S1>:1:201' */
    xw33_hor[1 + factor] = lb;

    /* '<S1>:1:201' */
    xw34_hor[1 + factor] = mb;

    /* '<S1>:1:182' */
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%prediction of x_2 to x_N_nmp1+1%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%calculation of control signal%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  NMPC_Controller_nmpc_iteration((real_T)rtb_DataTypeConversion1,
    NMPC_Controller_U.HomeCmd, 0.05, 1.0,
    rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_0,
    rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_1, wpts_h,
    wpts_n, wpts_e,
    rtb_BusConversion_InsertedFor_ControlSystem_at_inport_2_BusCr_2, *(real_T (*)
    [21])&NMPC_Controller_U.n_op[1], *(real_T (*)[21])&NMPC_Controller_U.e_op[1],
    *(real_T (*)[21])&NMPC_Controller_U.h_op[1], *(real_T (*)[21])&
    NMPC_Controller_U.vn_op[1], *(real_T (*)[21])&NMPC_Controller_U.ve_op[1],
    *(real_T (*)[21])&NMPC_Controller_U.vh_op[1], u_hor, z_augm_hor, n_hor,
    e_hor, h_hor, THL_hor, EL_hor, AIL_hor, RDR_hor, VT_hor, alpha_hor, beta_hor,
    phi_hor, theta_hor, psi_hor, P_hor, Q_hor, R_hor, wpt_index_hor,
    start_wpt_hor, pic_cic_hor, home_reset_hor, alphadot_hor, betadot_hor,
    ro_hor, xw11_hor, xw12_hor, xw13_hor, xw14_hor, xw21_hor, xw22_hor, xw23_hor,
    xw24_hor, xw31_hor, xw32_hor, xw33_hor, xw34_hor,
    NMPC_Controller_ConstP.pooled1, NMPC_Controller_ConstP.pooled1,
    NMPC_Controller_ConstP.pooled1, NMPC_Controller_ConstP.pooled1,
    NMPC_Controller_ConstP.pooled2, NMPC_Controller_ConstP.pooled2,
    NMPC_Controller_ConstP.pooled3, NMPC_Controller_ConstP.pooled3,
    NMPC_Controller_ConstP.pooled4, NMPC_Controller_ConstP.pooled4,
    NMPC_Controller_ConstP.pooled4, NMPC_Controller_ConstP.pooled4, 0.002295,
    21.11, 2.19, 10.16, 59.0, 32.174, 4.2, 9.9, 11.5, 0.0, 0.0, 0.0, 0.0,
    -0.00025, 0.0183, -0.35488, 0.01681, 0.314151, 0.0, 0.258448, -0.00419,
    4.609306, 6.450127, 1.904332, 0.001916, 0.430417, -0.03114, -0.37443,
    0.072757, 0.259592, 0.018248, 0.012115, -0.86779, -9.50961, -4.74712,
    0.000264, -1.07294, 0.126004, -0.02996, -0.17559, -0.01165, -0.14802, 0.4301,
    -0.0025080000000000002, 0.0052503, 0.0, -0.00020412914737191596, 0.0,
    99.998552624300657, -10.0, 10.0, -14.28, 14.28, -14.28, 14.28, -5.0, 5.0,
    1.0, 0.15, 0.26179938779914941, -0.26179938779914941, 0.3490658503988659,
    -0.3490658503988659, 0.17453292519943295, -0.17453292519943295, 0.015625,
    0.00093750000000000018, 0.00625, 300.0, 320.0,
    NMPC_Controller_DW.Delay5seconds_DSTATE[0], NMPC_Controller_U.a_ann_X,
    NMPC_Controller_U.b_ann_X, NMPC_Controller_U.c_ann_X,
    NMPC_Controller_U.w_ann_X, NMPC_Controller_U.a_ann_Y,
    NMPC_Controller_U.b_ann_Y, NMPC_Controller_U.c_ann_Y,
    NMPC_Controller_U.w_ann_Y, NMPC_Controller_U.a_ann_Z,
    NMPC_Controller_U.b_ann_Z, NMPC_Controller_U.c_ann_Z,
    NMPC_Controller_U.w_ann_Z, NMPC_Controller_ConstP.pooled17,
    NMPC_Controller_ConstP.pooled15, -1.0, 1.0, 0.01, 0.2, -1.0, 1.0,
    NMPC_Controller_ConstP.ControlSystem_Y_minXin,
    NMPC_Controller_ConstP.ControlSystem_Y_maxXin, -1.0, 1.0, -0.2, 0.2, -1.0,
    1.0, NMPC_Controller_ConstP.pooled17, NMPC_Controller_ConstP.pooled15, -1.0,
    1.0, -3.0, -0.5, -1.0, 1.0, rtb_u_nmpc_out, &rtb_sw_time_out);

  /* Outport: '<Root>/V_nmpc' incorporates:
   *  MATLAB Function: '<Root>/Control System'
   */
  /* '<S1>:1:261' */
  /* '<S1>:1:262' */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%calculation of control signal%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  NMPC_Controller_Y.V_nmpc = rtb_sw_time_out;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  /* MATLAB Function 'Guidance System/r and d points/d distance/Embedded MATLAB Function': '<S31>:1' */
  /* '<S31>:1:4' */
  /* '<S31>:1:5' */
  /* '<S31>:1:6' */
  /* '<S31>:1:8' */
  memcpy(&NMPC_Controller_DW.UnitDelay_DSTATE[0], &rtb_u_nmpc_out[0], 84U *
         sizeof(real_T));

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S13>/Gain1'
   */
  NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE += 0.00093750000000000018 *
    rtb_TrigonometricFunction1_a * 0.05;
  if (NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE >= 3.1415926535897931) {
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE = 3.1415926535897931;
  } else {
    if (NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE <= -3.1415926535897931)
    {
      NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE = -3.1415926535897931;
    }
  }

  if (rtb_LogicalOperator) {
    NMPC_Controller_DW.DiscreteTimeIntegrator_PrevResetState = 1;
  } else {
    NMPC_Controller_DW.DiscreteTimeIntegrator_PrevResetState = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S12>/Gain1'
   */
  NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h += 0.0 * rtb_Product4_i *
    0.05;
  if (NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h >= 3.1415926535897931)
  {
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h = 3.1415926535897931;
  } else {
    if (NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h <=
        -3.1415926535897931) {
      NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE_h = -3.1415926535897931;
    }
  }

  if (rtb_LogicalOperator_f) {
    NMPC_Controller_DW.DiscreteTimeIntegrator_PrevResetState_f = 1;
  } else {
    NMPC_Controller_DW.DiscreteTimeIntegrator_PrevResetState_f = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S34>/Unit Delay' incorporates:
   *  Gain: '<S34>/Gain1'
   *  Gain: '<S34>/Gain2'
   *  Sum: '<S34>/Add4'
   */
  NMPC_Controller_DW.UnitDelay_DSTATE_p = 0.5 * rtb_e_augm11_k +
    0.99998000019999866 * rtb_xw11_k;

  /* Update for UnitDelay: '<S34>/Unit Delay1' incorporates:
   *  Gain: '<S34>/Gain3'
   *  Gain: '<S34>/Gain4'
   *  Sum: '<S34>/Add5'
   */
  NMPC_Controller_DW.UnitDelay1_DSTATE = 0.5 * rtb_e_augm21_k +
    0.99998000019999866 * rtb_xw12_k;

  /* Update for UnitDelay: '<S34>/Unit Delay2' incorporates:
   *  Gain: '<S34>/Gain5'
   *  Gain: '<S34>/Gain6'
   *  Sum: '<S34>/Add6'
   */
  NMPC_Controller_DW.UnitDelay2_DSTATE = 0.5 * rtb_e_augm31_k +
    0.99998000019999866 * rtb_xw13_k;

  /* Update for UnitDelay: '<S34>/Unit Delay3' incorporates:
   *  Gain: '<S34>/Gain7'
   *  Gain: '<S34>/Gain8'
   *  Sum: '<S34>/Add7'
   */
  NMPC_Controller_DW.UnitDelay3_DSTATE = 0.5 * rtb_e_augm41_k +
    0.99998000019999866 * rtb_xw14_k;

  /* Update for UnitDelay: '<S35>/Unit Delay' incorporates:
   *  Gain: '<S35>/Gain10'
   *  Sum: '<S35>/Add4'
   */
  NMPC_Controller_DW.UnitDelay_DSTATE_j = 0.77782300443900354 * rtb_xw21_k +
    rtb_DataStoreRead1_f_idx_0;

  /* Update for UnitDelay: '<S35>/Unit Delay1' incorporates:
   *  Gain: '<S35>/Gain1'
   *  Sum: '<S35>/Add5'
   */
  NMPC_Controller_DW.UnitDelay1_DSTATE_g = 0.77782300443900354 * rtb_xw22_k +
    rtb_DataStoreRead1_f_idx_1;

  /* Update for UnitDelay: '<S35>/Unit Delay2' incorporates:
   *  Gain: '<S35>/Gain3'
   *  Sum: '<S35>/Add6'
   */
  NMPC_Controller_DW.UnitDelay2_DSTATE_a = 0.77782300443900354 * rtb_xw23_k +
    rtb_DataStoreRead1_f_idx_2;

  /* Update for UnitDelay: '<S35>/Unit Delay3' incorporates:
   *  Gain: '<S35>/Gain5'
   *  Sum: '<S35>/Add7'
   */
  NMPC_Controller_DW.UnitDelay3_DSTATE_g = 0.77782300443900354 * rtb_xw24_k +
    rtb_DataStoreRead1_f_idx_3;

  /* Update for UnitDelay: '<S36>/Unit Delay' incorporates:
   *  Gain: '<S36>/Gain10'
   *  Inport: '<Root>/VT, alpha, beta'
   *  Sum: '<S36>/Add4'
   */
  NMPC_Controller_DW.UnitDelay_DSTATE_m = 0.513417119032592 * rtb_xw31_k +
    NMPC_Controller_U.VTalphabeta.VT;

  /* Update for UnitDelay: '<S36>/Unit Delay1' incorporates:
   *  Gain: '<S36>/Gain1'
   *  Inport: '<Root>/phi, theta, psi'
   *  Sum: '<S36>/Add5'
   */
  NMPC_Controller_DW.UnitDelay1_DSTATE_m = 0.513417119032592 * rtb_xw32_k +
    NMPC_Controller_U.phithetapsi.theta;

  /* Update for UnitDelay: '<S36>/Unit Delay2' incorporates:
   *  Gain: '<S36>/Gain3'
   *  Inport: '<Root>/phi, theta, psi'
   *  Sum: '<S36>/Add6'
   */
  NMPC_Controller_DW.UnitDelay2_DSTATE_p = 0.513417119032592 * rtb_xw33_k +
    NMPC_Controller_U.phithetapsi.phi;

  /* Update for UnitDelay: '<S36>/Unit Delay3' incorporates:
   *  Gain: '<S36>/Gain5'
   *  Inport: '<Root>/VT, alpha, beta'
   *  Sum: '<S36>/Add7'
   */
  NMPC_Controller_DW.UnitDelay3_DSTATE_j = 0.513417119032592 * rtb_xw34_k +
    NMPC_Controller_U.VTalphabeta.beta;

  /* Update for UnitDelay: '<S2>/UD' */
  NMPC_Controller_DW.UD_DSTATE = rtb_TSamp;

  /* Update for UnitDelay: '<S3>/UD' */
  NMPC_Controller_DW.UD_DSTATE_j = rtb_TSamp_d;

  /* Update for Delay: '<Root>/Delay 5 seconds' incorporates:
   *  Update for Inport: '<Root>/FL_ann'
   */
  for (factor = 0; factor < 99; factor++) {
    NMPC_Controller_DW.Delay5seconds_DSTATE[factor] =
      NMPC_Controller_DW.Delay5seconds_DSTATE[factor + 1];
  }

  NMPC_Controller_DW.Delay5seconds_DSTATE[99] = NMPC_Controller_U.FL_ann;

  /* End of Update for Delay: '<Root>/Delay 5 seconds' */
}

/* Model initialize function */
void NMPC_Controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(NMPC_Controller_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &NMPC_Controller_B), 0,
                sizeof(B_NMPC_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&NMPC_Controller_DW, 0,
                sizeof(DW_NMPC_Controller_T));

  /* external inputs */
  (void) memset((void *)&NMPC_Controller_U, 0,
                sizeof(ExtU_NMPC_Controller_T));

  /* external outputs */
  (void) memset((void *)&NMPC_Controller_Y, 0,
                sizeof(ExtY_NMPC_Controller_T));

  {
    int32_T i;

    /* Start for DataStoreMemory: '<S8>/Waypoint Index Memory' */
    NMPC_Controller_DW.Waypoint_Index = 1U;
    NMPC_Controller_PrevZCX.Delay5seconds_Reset_ZCE = UNINITIALIZED_ZCSIG;
    for (i = 0; i < 84; i++) {
      /* Start for DataStoreMemory: '<Root>/NMPC Memory' */
      NMPC_Controller_DW.u_nmpc[i] = NMPC_Controller_ConstP.pooled22[i];

      /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
      NMPC_Controller_DW.UnitDelay_DSTATE[i] = NMPC_Controller_ConstP.pooled22[i];
    }

    /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
    NMPC_Controller_DW.DiscreteTimeIntegrator_DSTATE = 0.0007255;
    NMPC_Controller_DW.DiscreteTimeIntegrator_PrevResetState = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    NMPC_Controller_DW.DiscreteTimeIntegrator_PrevResetState_f = 0;

    /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
    NMPC_Controller_DW.UnitDelay_DSTATE_p = 11.5;

    /* InitializeConditions for UnitDelay: '<S34>/Unit Delay1' */
    NMPC_Controller_DW.UnitDelay1_DSTATE = 0.125;

    /* InitializeConditions for UnitDelay: '<S35>/Unit Delay' */
    NMPC_Controller_DW.UnitDelay_DSTATE_j = 0.08;

    /* InitializeConditions for UnitDelay: '<S35>/Unit Delay1' */
    NMPC_Controller_DW.UnitDelay1_DSTATE_g = -0.011;

    /* InitializeConditions for UnitDelay: '<S36>/Unit Delay' */
    NMPC_Controller_DW.UnitDelay_DSTATE_m = 2.0;

    /* InitializeConditions for UnitDelay: '<S36>/Unit Delay1' */
    NMPC_Controller_DW.UnitDelay1_DSTATE_m = 0.0044;

    /* InitializeConditions for Delay: '<Root>/Delay 5 seconds' */
    memset(&NMPC_Controller_DW.Delay5seconds_DSTATE[0], 0, 100U * sizeof(real_T));
  }
}

/* Model terminate function */
void NMPC_Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
