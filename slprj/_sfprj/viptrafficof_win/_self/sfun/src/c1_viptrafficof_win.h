#ifndef __c1_viptrafficof_win_h__
#define __c1_viptrafficof_win_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  char *context;
  char *name;
  char *dominantType;
  char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c1_ResolvedFunctionInfo;

typedef struct {
  real_T c1_CV[31];
  real_T c1_RV[23];
  real_T c1_X[713];
  real_T c1_Y[713];
  real_T c1_first_time;
  real_T c1_scaleFactor;
  SimStruct *S;
  boolean_T c1_CV_not_empty;
  boolean_T c1_RV_not_empty;
  boolean_T c1_X_not_empty;
  boolean_T c1_Y_not_empty;
  boolean_T c1_first_time_not_empty;
  uint8_T c1_is_active_c1_viptrafficof_win;
  ChartInfoStruct chartInfo;
} SFc1_viptrafficof_winInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c1_viptrafficof_win_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_viptrafficof_win_get_check_sum(mxArray *plhs[]);
extern void c1_viptrafficof_win_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
