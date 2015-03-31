/* Include files */

#include "blascompat32.h"
#include "viptrafficof_win_sfun.h"
#include "c1_viptrafficof_win.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_viptrafficof_winInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_viptrafficof_win(void);
static void initialize_params_c1_viptrafficof_win(void);
static void enable_c1_viptrafficof_win(void);
static void disable_c1_viptrafficof_win(void);
static const mxArray *get_sim_state_c1_viptrafficof_win(void);
static void set_sim_state_c1_viptrafficof_win(const mxArray *c1_st);
static void finalize_c1_viptrafficof_win(void);
static void sf_c1_viptrafficof_win(void);
static void c1_c1_viptrafficof_win(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_meshgrid(real_T c1_x[31], real_T c1_y[23], real_T c1_xx[713],
  real_T c1_yy[713]);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[65]);
static const mxArray *c1_emlrt_marshallOut(real32_T c1_u[2852]);
static const mxArray *c1_b_emlrt_marshallOut(real_T c1_u[31]);
static const mxArray *c1_c_emlrt_marshallOut(real_T c1_u[23]);
static const mxArray *c1_d_emlrt_marshallOut(real_T c1_u[713]);
static const mxArray *c1_e_emlrt_marshallOut(real_T c1_u[713]);
static const mxArray *c1_f_emlrt_marshallOut(real_T c1_u);
static const mxArray *c1_g_emlrt_marshallOut(uint8_T c1_u);
static void c1_emlrt_marshallIn(const mxArray *c1_vel_Lines, char *c1_name,
  real32_T c1_y[2852]);
static void c1_b_emlrt_marshallIn(const mxArray *c1_b_CV, char *c1_name, real_T
  c1_y[31]);
static void c1_c_emlrt_marshallIn(const mxArray *c1_b_RV, char *c1_name, real_T
  c1_y[23]);
static void c1_d_emlrt_marshallIn(const mxArray *c1_b_X, char *c1_name, real_T
  c1_y[713]);
static void c1_e_emlrt_marshallIn(const mxArray *c1_b_Y, char *c1_name, real_T
  c1_y[713]);
static real_T c1_f_emlrt_marshallIn(const mxArray *c1_b_first_time, char
  *c1_name);
static uint8_T c1_g_emlrt_marshallIn(const mxArray
  *c1_b_is_active_c1_viptrafficof_win, char *c1_name);
static void init_io_bus_offset(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_viptrafficof_win(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_first_time_not_empty = false;
  chartInstance.c1_RV_not_empty = false;
  chartInstance.c1_CV_not_empty = false;
  chartInstance.c1_Y_not_empty = false;
  chartInstance.c1_X_not_empty = false;
  chartInstance.c1_is_active_c1_viptrafficof_win = 0U;
}

static void initialize_params_c1_viptrafficof_win(void)
{
  real_T c1_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'scaleFactor' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c1_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c1_scaleFactor = c1_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_viptrafficof_win(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c1_viptrafficof_win(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static const mxArray *get_sim_state_c1_viptrafficof_win(void)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real32_T c1_fv0[2852];
  real_T c1_dv0[31];
  real_T c1_dv1[23];
  real_T c1_dv2[713];
  real32_T (*c1_vel_Lines)[2852];
  c1_vel_Lines = (real32_T (*)[2852])ssGetOutputPortSignal(chartInstance.S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(7));
  for (c1_i0 = 0; c1_i0 < 2852; c1_i0 = c1_i0 + 1) {
    c1_fv0[c1_i0] = (*c1_vel_Lines)[c1_i0];
  }

  sf_mex_setcell(c1_y, 0, c1_emlrt_marshallOut(c1_fv0));
  for (c1_i0 = 0; c1_i0 < 31; c1_i0 = c1_i0 + 1) {
    c1_dv0[c1_i0] = chartInstance.c1_CV[c1_i0];
  }

  sf_mex_setcell(c1_y, 1, c1_b_emlrt_marshallOut(c1_dv0));
  for (c1_i0 = 0; c1_i0 < 23; c1_i0 = c1_i0 + 1) {
    c1_dv1[c1_i0] = chartInstance.c1_RV[c1_i0];
  }

  sf_mex_setcell(c1_y, 2, c1_c_emlrt_marshallOut(c1_dv1));
  for (c1_i0 = 0; c1_i0 < 713; c1_i0 = c1_i0 + 1) {
    c1_dv2[c1_i0] = chartInstance.c1_X[c1_i0];
  }

  sf_mex_setcell(c1_y, 3, c1_d_emlrt_marshallOut(c1_dv2));
  for (c1_i0 = 0; c1_i0 < 713; c1_i0 = c1_i0 + 1) {
    c1_dv2[c1_i0] = chartInstance.c1_Y[c1_i0];
  }

  sf_mex_setcell(c1_y, 4, c1_e_emlrt_marshallOut(c1_dv2));
  sf_mex_setcell(c1_y, 5, c1_f_emlrt_marshallOut(chartInstance.c1_first_time));
  sf_mex_setcell(c1_y, 6, c1_g_emlrt_marshallOut
                 (chartInstance.c1_is_active_c1_viptrafficof_win));
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_viptrafficof_win(const mxArray *c1_st)
{
  const mxArray *c1_u;
  real32_T c1_fv1[2852];
  int32_T c1_i1;
  real_T c1_dv3[31];
  real_T c1_dv4[23];
  real_T c1_dv5[713];
  real32_T (*c1_vel_Lines)[2852];
  c1_vel_Lines = (real32_T (*)[2852])ssGetOutputPortSignal(chartInstance.S, 1);
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 0)), "vel_Lines", c1_fv1);
  for (c1_i1 = 0; c1_i1 < 2852; c1_i1 = c1_i1 + 1) {
    (*c1_vel_Lines)[c1_i1] = c1_fv1[c1_i1];
  }

  c1_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 1)), "CV", c1_dv3);
  for (c1_i1 = 0; c1_i1 < 31; c1_i1 = c1_i1 + 1) {
    chartInstance.c1_CV[c1_i1] = c1_dv3[c1_i1];
  }

  c1_c_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 2)), "RV", c1_dv4);
  for (c1_i1 = 0; c1_i1 < 23; c1_i1 = c1_i1 + 1) {
    chartInstance.c1_RV[c1_i1] = c1_dv4[c1_i1];
  }

  c1_d_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 3)), "X", c1_dv5);
  for (c1_i1 = 0; c1_i1 < 713; c1_i1 = c1_i1 + 1) {
    chartInstance.c1_X[c1_i1] = c1_dv5[c1_i1];
  }

  c1_e_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 4)), "Y", c1_dv5);
  for (c1_i1 = 0; c1_i1 < 713; c1_i1 = c1_i1 + 1) {
    chartInstance.c1_Y[c1_i1] = c1_dv5[c1_i1];
  }

  chartInstance.c1_first_time = c1_f_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 5)), "first_time");
  chartInstance.c1_is_active_c1_viptrafficof_win = c1_g_emlrt_marshallIn
    (sf_mex_dup(sf_mex_getcell(c1_u, 6)),
     "is_active_c1_viptrafficof_win");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_viptrafficof_win(void)
{
}

static void sf_c1_viptrafficof_win(void)
{
  uint8_T c1_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_viptrafficof_win();
  _sfEvent_ = c1_previousEvent;
}

static void c1_c1_viptrafficof_win(void)
{
  int32_T c1_i2;
  int32_T c1_i3;
  creal32_T c1_tmp[713];
  real32_T (*c1_vel_Lines)[2852];
  creal32_T (*c1_vel_Values)[19200];
  c1_vel_Values = (creal32_T (*)[19200])ssGetInputPortSignal(chartInstance.S, 0);
  c1_vel_Lines = (real32_T (*)[2852])ssGetOutputPortSignal(chartInstance.S, 1);

  /*  Generates the coordinate points of optical flow lines */
  if (!chartInstance.c1_first_time_not_empty) {
    chartInstance.c1_first_time = 1.0;
    chartInstance.c1_first_time_not_empty = true;

    /*     %% user may change the following three parameters */
    /*     %% */
    for (c1_i2 = 0; c1_i2 < 23; c1_i2 = c1_i2 + 1) {
      chartInstance.c1_RV[c1_i2] = 5.0 + 5.0 * (real_T)c1_i2;
    }

    chartInstance.c1_RV_not_empty = true;
    for (c1_i2 = 0; c1_i2 < 31; c1_i2 = c1_i2 + 1) {
      chartInstance.c1_CV[c1_i2] = 5.0 + 5.0 * (real_T)c1_i2;
    }

    chartInstance.c1_CV_not_empty = true;
    c1_meshgrid(chartInstance.c1_CV, chartInstance.c1_RV, chartInstance.c1_Y,
                chartInstance.c1_X);
    chartInstance.c1_Y_not_empty = true;
    chartInstance.c1_X_not_empty = true;
  }

  for (c1_i2 = 0; c1_i2 < 31; c1_i2 = c1_i2 + 1) {
    sf_mex_lw_bounds_check((int32_T)chartInstance.c1_CV[c1_i2], 1, 160);
  }

  for (c1_i2 = 0; c1_i2 < 23; c1_i2 = c1_i2 + 1) {
    sf_mex_lw_bounds_check((int32_T)chartInstance.c1_RV[c1_i2], 1, 120);
  }

  for (c1_i2 = 0; c1_i2 < 31; c1_i2 = c1_i2 + 1) {
    for (c1_i3 = 0; c1_i3 < 23; c1_i3 = c1_i3 + 1) {
      c1_tmp[c1_i3 + 23 * c1_i2].re = (real32_T)chartInstance.c1_scaleFactor * (*
        c1_vel_Values)[(sf_mex_lw_bounds_check((int32_T)
        chartInstance.c1_RV[c1_i3], 1, 120) - 1) + 120 * (sf_mex_lw_bounds_check
        ((int32_T)chartInstance.c1_CV[c1_i2], 1, 160) - 1)].re;
      c1_tmp[c1_i3 + 23 * c1_i2].im = (real32_T)chartInstance.c1_scaleFactor * (*
        c1_vel_Values)[(sf_mex_lw_bounds_check((int32_T)
        chartInstance.c1_RV[c1_i3], 1, 120) - 1) + 120 * (sf_mex_lw_bounds_check
        ((int32_T)chartInstance.c1_CV[c1_i2], 1, 160) - 1)].im;
    }
  }

  c1_i2 = 0;
  for (c1_i3 = 0; c1_i3 < 713; c1_i3 = c1_i3 + 1) {
    (*c1_vel_Lines)[c1_i2] = (real32_T)chartInstance.c1_X[c1_i3];
    (*c1_vel_Lines)[c1_i2 + 1] = (real32_T)chartInstance.c1_Y[c1_i3];
    (*c1_vel_Lines)[c1_i2 + 2] = (real32_T)chartInstance.c1_X[c1_i3] +
      c1_tmp[c1_i3].im;
    (*c1_vel_Lines)[c1_i2 + 3] = (real32_T)chartInstance.c1_Y[c1_i3] +
      c1_tmp[c1_i3].re;
    c1_i2 = c1_i2 + 4;
  }
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static void c1_meshgrid(real_T c1_x[31], real_T c1_y[23], real_T c1_xx[713],
  real_T c1_yy[713])
{
  int32_T c1_ia;
  real_T c1_a[31];
  int32_T c1_ib;
  int32_T c1_iacol;
  int32_T c1_jcol;
  int32_T c1_itilerow;
  real_T c1_b_a[23];
  for (c1_ia = 0; c1_ia < 31; c1_ia = c1_ia + 1) {
    c1_a[c1_ia] = c1_x[c1_ia];
  }

  c1_ia = 1;
  c1_ib = 1;
  c1_iacol = 1;
  for (c1_jcol = 0; c1_jcol < 31; c1_jcol = c1_jcol + 1) {
    for (c1_itilerow = 0; c1_itilerow < 23; c1_itilerow = c1_itilerow + 1) {
      c1_xx[sf_mex_lw_bounds_check(c1_ib, 1, 713) - 1] =
        c1_a[sf_mex_lw_bounds_check(c1_iacol, 1, 31) - 1];
      c1_ia = c1_iacol + 1;
      c1_ib = c1_ib + 1;
    }

    c1_iacol = c1_ia;
  }

  for (c1_ia = 0; c1_ia < 23; c1_ia = c1_ia + 1) {
    c1_b_a[c1_ia] = c1_y[c1_ia];
  }

  c1_ia = 1;
  for (c1_ib = 0; c1_ib < 31; c1_ib = c1_ib + 1) {
    c1_iacol = 1;
    for (c1_jcol = 0; c1_jcol < 23; c1_jcol = c1_jcol + 1) {
      c1_yy[sf_mex_lw_bounds_check(c1_ia, 1, 713) - 1] =
        c1_b_a[sf_mex_lw_bounds_check(c1_iacol, 1, 23) - 1];
      c1_iacol = c1_iacol + 1;
      c1_ia = c1_ia + 1;
    }
  }
}

const mxArray *sf_c1_viptrafficof_win_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[65];
  c1_ResolvedFunctionInfo (*c1_b_info)[65];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i4;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info = (c1_ResolvedFunctionInfo (*)[65])c1_info;
  (*c1_b_info)[64].context = "";
  (*c1_b_info)[64].name = "imag";
  (*c1_b_info)[64].dominantType = "single";
  (*c1_b_info)[64].resolved = "[B]imag";
  (*c1_b_info)[64].fileLength = 0U;
  (*c1_b_info)[64].fileTime1 = 0U;
  (*c1_b_info)[64].fileTime2 = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 65));
  for (c1_i4 = 0; c1_i4 < 65; c1_i4 = c1_i4 + 1) {
    c1_r0 = &c1_info[c1_i4];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i4);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[65])
{
  c1_info[0].context = "";
  c1_info[0].name = "size";
  c1_info[0].dominantType = "single";
  c1_info[0].resolved = "[B]size";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "minus";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[B]minus";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "colon";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[2].fileLength = 8271U;
  c1_info[2].fileTime1 = 1227645800U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[3].name = "nargin";
  c1_info[3].dominantType = "";
  c1_info[3].resolved = "[B]nargin";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[4].name = "ge";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]ge";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[5].name = "lt";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]lt";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[6].name = "isa";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]isa";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[7].name = "isreal";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]isreal";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[8].name = "isscalar";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]isscalar";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[9].name = "ischar";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]ischar";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[10].name = "isinteger";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]isinteger";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c1_info[11].name = "isfinite";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[11].fileLength = 364U;
  c1_info[11].fileTime1 = 1226021856U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[12].name = "gt";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]gt";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[13].name = "isinf";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[13].fileLength = 506U;
  c1_info[13].fileTime1 = 1227645788U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[14].name = "not";
  c1_info[14].dominantType = "logical";
  c1_info[14].resolved = "[B]not";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[15].name = "isnan";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[15].fileLength = 506U;
  c1_info[15].fileTime1 = 1227645788U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[16].name = "and";
  c1_info[16].dominantType = "logical";
  c1_info[16].resolved = "[B]and";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c1_info[17].name = "floor";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[17].fileLength = 332U;
  c1_info[17].fileTime1 = 1203480424U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[18].name = "eml_scalar_floor";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[18].fileLength = 260U;
  c1_info[18].fileTime1 = 1209363190U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c1_info[19].name = "eq";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[B]eq";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/maxabs";
  c1_info[20].name = "abs";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[20].fileLength = 566U;
  c1_info[20].fileTime1 = 1221299534U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[21].name = "islogical";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved = "[B]islogical";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[22].name = "class";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[B]class";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[23].name = "zeros";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved = "[B]zeros";
  c1_info[23].fileLength = 0U;
  c1_info[23].fileTime1 = 0U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[24].name = "eml_scalar_abs";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[24].fileLength = 461U;
  c1_info[24].fileTime1 = 1203480360U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/is_flint_colon";
  c1_info[25].name = "eps";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[25].fileLength = 1337U;
  c1_info[25].fileTime1 = 1227645786U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[26].name = "real";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[B]real";
  c1_info[26].fileLength = 0U;
  c1_info[26].fileTime1 = 0U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[27].name = "int32";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[B]int32";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[28].name = "realmin";
  c1_info[28].dominantType = "";
  c1_info[28].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[28].fileLength = 749U;
  c1_info[28].fileTime1 = 1226021858U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[29].name = "uminus";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved = "[B]uminus";
  c1_info[29].fileLength = 0U;
  c1_info[29].fileTime1 = 0U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[30].name = "mpower";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[30].fileLength = 3623U;
  c1_info[30].fileTime1 = 1227645802U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[31].name = "ndims";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[B]ndims";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[32].name = "power";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[32].fileLength = 5380U;
  c1_info[32].fileTime1 = 1227645802U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[33].name = "eml_scalar_eg";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[33].fileLength = 3524U;
  c1_info[33].fileTime1 = 1227645794U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c1_info[34].name = "false";
  c1_info[34].dominantType = "";
  c1_info[34].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[34].fileLength = 238U;
  c1_info[34].fileTime1 = 1192499120U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[35].name = "logical";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]logical";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[36].name = "isstruct";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]isstruct";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c1_info[37].name = "cast";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[37].fileLength = 889U;
  c1_info[37].fileTime1 = 1226021842U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[38].name = "double";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]double";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c1_info[39].name = "plus";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved = "[B]plus";
  c1_info[39].fileLength = 0U;
  c1_info[39].fileTime1 = 0U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[40].name = "eml_scalexp_alloc";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[40].fileLength = 794U;
  c1_info[40].fileTime1 = 1227645794U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[41].name = "ne";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved = "[B]ne";
  c1_info[41].fileLength = 0U;
  c1_info[41].fileTime1 = 0U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[42].name = "eml_error";
  c1_info[42].dominantType = "char";
  c1_info[42].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[42].fileLength = 315U;
  c1_info[42].fileTime1 = 1213959146U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[43].name = "strcmp";
  c1_info[43].dominantType = "char";
  c1_info[43].resolved = "[B]strcmp";
  c1_info[43].fileLength = 0U;
  c1_info[43].fileTime1 = 0U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[44].name = "le";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved = "[B]le";
  c1_info[44].fileLength = 0U;
  c1_info[44].fileTime1 = 0U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c1_info[45].name = "realmax";
  c1_info[45].dominantType = "char";
  c1_info[45].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[45].fileLength = 771U;
  c1_info[45].fileTime1 = 1226021858U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[46].name = "mtimes";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[46].fileLength = 2408U;
  c1_info[46].fileTime1 = 1227645802U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c1_info[47].name = "intmax";
  c1_info[47].dominantType = "";
  c1_info[47].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[47].fileLength = 1535U;
  c1_info[47].fileTime1 = 1192499128U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c1_info[48].name = "transpose";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved = "[B]transpose";
  c1_info[48].fileLength = 0U;
  c1_info[48].fileTime1 = 0U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context = "";
  c1_info[49].name = "meshgrid";
  c1_info[49].dominantType = "double";
  c1_info[49].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c1_info[49].fileLength = 1036U;
  c1_info[49].fileTime1 = 1227645790U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c1_info[50].name = "nargout";
  c1_info[50].dominantType = "";
  c1_info[50].resolved = "[B]nargout";
  c1_info[50].fileLength = 0U;
  c1_info[50].fileTime1 = 0U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c1_info[51].name = "isempty";
  c1_info[51].dominantType = "double";
  c1_info[51].resolved = "[B]isempty";
  c1_info[51].fileLength = 0U;
  c1_info[51].fileTime1 = 0U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c1_info[52].name = "repmat";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[52].fileLength = 3561U;
  c1_info[52].fileTime1 = 1227645792U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[53].name = "eml_assert_valid_size_arg";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[53].fileLength = 3237U;
  c1_info[53].fileTime1 = 1227645784U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[54].name = "isnumeric";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved = "[B]isnumeric";
  c1_info[54].fileLength = 0U;
  c1_info[54].fileTime1 = 0U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[55].name = "isvector";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved = "[B]isvector";
  c1_info[55].fileLength = 0U;
  c1_info[55].fileTime1 = 0U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c1_info[56].name = "true";
  c1_info[56].dominantType = "";
  c1_info[56].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c1_info[56].fileLength = 237U;
  c1_info[56].fileTime1 = 1192499162U;
  c1_info[56].fileTime2 = 0U;
  c1_info[57].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[57].name = "eml_index_class";
  c1_info[57].dominantType = "";
  c1_info[57].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[57].fileLength = 909U;
  c1_info[57].fileTime1 = 1192499182U;
  c1_info[57].fileTime2 = 0U;
  c1_info[58].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[58].name = "ones";
  c1_info[58].dominantType = "char";
  c1_info[58].resolved = "[B]ones";
  c1_info[58].fileLength = 0U;
  c1_info[58].fileTime1 = 0U;
  c1_info[58].fileTime2 = 0U;
  c1_info[59].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[59].name = "times";
  c1_info[59].dominantType = "double";
  c1_info[59].resolved = "[B]times";
  c1_info[59].fileLength = 0U;
  c1_info[59].fileTime1 = 0U;
  c1_info[59].fileTime2 = 0U;
  c1_info[60].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[60].name = "eml_index_prod";
  c1_info[60].dominantType = "double";
  c1_info[60].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c1_info[60].fileLength = 547U;
  c1_info[60].fileTime1 = 1211248426U;
  c1_info[60].fileTime2 = 0U;
  c1_info[61].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c1_info[61].name = "eml_index_times";
  c1_info[61].dominantType = "int32";
  c1_info[61].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[61].fileLength = 280U;
  c1_info[61].fileTime1 = 1192499188U;
  c1_info[61].fileTime2 = 0U;
  c1_info[62].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[62].name = "eml_index_plus";
  c1_info[62].dominantType = "int32";
  c1_info[62].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[62].fileLength = 272U;
  c1_info[62].fileTime1 = 1192499186U;
  c1_info[62].fileTime2 = 0U;
  c1_info[63].context = "";
  c1_info[63].name = "ctranspose";
  c1_info[63].dominantType = "double";
  c1_info[63].resolved = "[B]ctranspose";
  c1_info[63].fileLength = 0U;
  c1_info[63].fileTime1 = 0U;
  c1_info[63].fileTime2 = 0U;
}

static const mxArray *c1_emlrt_marshallOut(real32_T c1_u[2852])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 1, 0U, 1U, 0U, 2, 4, 713));
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(real_T c1_u[31])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  if (!chartInstance.c1_CV_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 31));
  }

  return c1_y;
}

static const mxArray *c1_c_emlrt_marshallOut(real_T c1_u[23])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  if (!chartInstance.c1_RV_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 23));
  }

  return c1_y;
}

static const mxArray *c1_d_emlrt_marshallOut(real_T c1_u[713])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  if (!chartInstance.c1_X_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 23, 31));
  }

  return c1_y;
}

static const mxArray *c1_e_emlrt_marshallOut(real_T c1_u[713])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  if (!chartInstance.c1_Y_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 23, 31));
  }

  return c1_y;
}

static const mxArray *c1_f_emlrt_marshallOut(real_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  if (!chartInstance.c1_first_time_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  }

  return c1_y;
}

static const mxArray *c1_g_emlrt_marshallOut(uint8_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  return c1_y;
}

static void c1_emlrt_marshallIn(const mxArray *c1_vel_Lines, char *c1_name,
  real32_T c1_y[2852])
{
  real32_T c1_fv2[2852];
  int32_T c1_i5;
  sf_mex_import(c1_name, sf_mex_dup(c1_vel_Lines), &c1_fv2, 1, 1, 0U, 1, 0U, 2,
                4, 713);
  for (c1_i5 = 0; c1_i5 < 2852; c1_i5 = c1_i5 + 1) {
    c1_y[c1_i5] = c1_fv2[c1_i5];
  }

  sf_mex_destroy(&c1_vel_Lines);
}

static void c1_b_emlrt_marshallIn(const mxArray *c1_b_CV, char *c1_name, real_T
  c1_y[31])
{
  real_T c1_dv6[31];
  int32_T c1_i6;
  if (mxIsEmpty(c1_b_CV)) {
    chartInstance.c1_CV_not_empty = false;
  } else {
    chartInstance.c1_CV_not_empty = true;
    sf_mex_import(c1_name, sf_mex_dup(c1_b_CV), &c1_dv6, 1, 0, 0U, 1, 0U, 2, 1,
                  31);
    for (c1_i6 = 0; c1_i6 < 31; c1_i6 = c1_i6 + 1) {
      c1_y[c1_i6] = c1_dv6[c1_i6];
    }
  }

  sf_mex_destroy(&c1_b_CV);
}

static void c1_c_emlrt_marshallIn(const mxArray *c1_b_RV, char *c1_name, real_T
  c1_y[23])
{
  real_T c1_dv7[23];
  int32_T c1_i7;
  if (mxIsEmpty(c1_b_RV)) {
    chartInstance.c1_RV_not_empty = false;
  } else {
    chartInstance.c1_RV_not_empty = true;
    sf_mex_import(c1_name, sf_mex_dup(c1_b_RV), &c1_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                  23);
    for (c1_i7 = 0; c1_i7 < 23; c1_i7 = c1_i7 + 1) {
      c1_y[c1_i7] = c1_dv7[c1_i7];
    }
  }

  sf_mex_destroy(&c1_b_RV);
}

static void c1_d_emlrt_marshallIn(const mxArray *c1_b_X, char *c1_name, real_T
  c1_y[713])
{
  real_T c1_dv8[713];
  int32_T c1_i8;
  if (mxIsEmpty(c1_b_X)) {
    chartInstance.c1_X_not_empty = false;
  } else {
    chartInstance.c1_X_not_empty = true;
    sf_mex_import(c1_name, sf_mex_dup(c1_b_X), &c1_dv8, 1, 0, 0U, 1, 0U, 2, 23,
                  31);
    for (c1_i8 = 0; c1_i8 < 713; c1_i8 = c1_i8 + 1) {
      c1_y[c1_i8] = c1_dv8[c1_i8];
    }
  }

  sf_mex_destroy(&c1_b_X);
}

static void c1_e_emlrt_marshallIn(const mxArray *c1_b_Y, char *c1_name, real_T
  c1_y[713])
{
  real_T c1_dv9[713];
  int32_T c1_i9;
  if (mxIsEmpty(c1_b_Y)) {
    chartInstance.c1_Y_not_empty = false;
  } else {
    chartInstance.c1_Y_not_empty = true;
    sf_mex_import(c1_name, sf_mex_dup(c1_b_Y), &c1_dv9, 1, 0, 0U, 1, 0U, 2, 23,
                  31);
    for (c1_i9 = 0; c1_i9 < 713; c1_i9 = c1_i9 + 1) {
      c1_y[c1_i9] = c1_dv9[c1_i9];
    }
  }

  sf_mex_destroy(&c1_b_Y);
}

static real_T c1_f_emlrt_marshallIn(const mxArray *c1_b_first_time, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d1;
  if (mxIsEmpty(c1_b_first_time)) {
    chartInstance.c1_first_time_not_empty = false;
  } else {
    chartInstance.c1_first_time_not_empty = true;
    sf_mex_import(c1_name, sf_mex_dup(c1_b_first_time), &c1_d1, 1, 0, 0U, 0, 0U,
                  0);
    c1_y = c1_d1;
  }

  sf_mex_destroy(&c1_b_first_time);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(const mxArray
  *c1_b_is_active_c1_viptrafficof_win, char *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_viptrafficof_win), &c1_u0,
                1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_viptrafficof_win);
  return c1_y;
}

static void init_io_bus_offset(void)
{
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c1_viptrafficof_win_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1642755728U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(914003692U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1429228628U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(207747840U);
}

mxArray *sf_c1_viptrafficof_win_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(606995228U);
    pr[1] = (double)(1766518355U);
    pr[2] = (double)(873864064U);
    pr[3] = (double)(1979873468U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(120);
      pr[1] = (double)(160);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(713);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_viptrafficof_win(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"vel_Lines\",},{M[4],M[0],T\"CV\",S'l','i','p'{{M1x2[197 199],M[0],}}},{M[4],M[0],T\"RV\",S'l','i','p'{{M1x2[182 184],M[0],}}},{M[4],M[0],T\"X\",S'l','i','p'{{M1x2[154 155],M[0],}}},{M[4],M[0],T\"Y\",S'l','i','p'{{M1x2[168 169],M[0],}}},{M[4],M[0],T\"first_time\",S'l','i','p'{{M1x2[131 141],M[0],}}},{M[8],M[0],T\"is_active_c1_viptrafficof_win\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_viptrafficof_win_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c1_viptrafficof_win(void *chartInstanceVar)
{
  initialize_params_c1_viptrafficof_win();
  initialize_c1_viptrafficof_win();
}

static void sf_opaque_enable_c1_viptrafficof_win(void *chartInstanceVar)
{
  enable_c1_viptrafficof_win();
}

static void sf_opaque_disable_c1_viptrafficof_win(void *chartInstanceVar)
{
  disable_c1_viptrafficof_win();
}

static void sf_opaque_gateway_c1_viptrafficof_win(void *chartInstanceVar)
{
  sf_c1_viptrafficof_win();
}

static mxArray* sf_opaque_get_sim_state_c1_viptrafficof_win(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_viptrafficof_win();
  return st;
}

static void sf_opaque_set_sim_state_c1_viptrafficof_win(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c1_viptrafficof_win(sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_viptrafficof_win(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c1_viptrafficof_win();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_viptrafficof_win(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_viptrafficof_win();
  }
}

static void mdlSetWorkWidths_c1_viptrafficof_win(SimStruct *S)
{
  /* Actual parameters from chart:
     scaleFactor
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for scaleFactor*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("viptrafficof_win","viptrafficof_win",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("viptrafficof_win","viptrafficof_win",1,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("viptrafficof_win",
      "viptrafficof_win",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"viptrafficof_win",
        "viptrafficof_win",1,1);
      sf_mark_chart_reusable_outputs(S,"viptrafficof_win","viptrafficof_win",1,1);
    }

    sf_set_rtw_dwork_info(S,"viptrafficof_win","viptrafficof_win",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2632050001U));
  ssSetChecksum1(S,(529846938U));
  ssSetChecksum2(S,(221637674U));
  ssSetChecksum3(S,(3125160667U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_viptrafficof_win(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "viptrafficof_win", "viptrafficof_win",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_viptrafficof_win(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_viptrafficof_win;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c1_viptrafficof_win;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c1_viptrafficof_win;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_viptrafficof_win;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_viptrafficof_win;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_viptrafficof_win;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_viptrafficof_win;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_viptrafficof_win;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_viptrafficof_win;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_viptrafficof_win;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_viptrafficof_win;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c1_viptrafficof_win_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_viptrafficof_win(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_viptrafficof_win(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_viptrafficof_win(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_viptrafficof_win_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
