/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c1_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatefinite.m"/* pName */
};

static emlrtMCInfo c1_b_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnegative",               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnegative.m"/* pName */
};

static emlrtMCInfo c1_c_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtMCInfo c1_d_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtMCInfo c1_e_emlrtMCI = { 88,/* lineNo */
  9,                                   /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c1_f_emlrtMCI = { 121,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c1_g_emlrtMCI = { 85,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c1_h_emlrtMCI = { 184,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c1_i_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

static emlrtMCInfo c1_j_emlrtMCI = { 41,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtMCInfo c1_k_emlrtMCI = { 31,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtMCInfo c1_l_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c1_m_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnan.m"/* pName */
};

static emlrtMCInfo c1_n_emlrtMCI = { 1271,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtMCInfo c1_o_emlrtMCI = { 47,/* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtMCInfo c1_p_emlrtMCI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c1_q_emlrtMCI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c1_r_emlrtMCI = { 38,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtMCInfo c1_s_emlrtMCI = { 283,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtMCInfo c1_t_emlrtMCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pName */
};

static emlrtMCInfo c1_u_emlrtMCI = { 81,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c1_v_emlrtMCI = { 297,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c1_w_emlrtMCI = { 81,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtMCInfo c1_x_emlrtMCI = { 392,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtMCInfo c1_y_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatepositive.m"/* pName */
};

static emlrtMCInfo c1_ab_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validatenonempty",                  /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonempty.m"/* pName */
};

static emlrtMCInfo c1_bb_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "validatencols",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatencols.m"/* pName */
};

static emlrtMCInfo c1_cb_emlrtMCI = { 72,/* lineNo */
  1,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtMCInfo c1_db_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validateinteger.m"/* pName */
};

static emlrtMCInfo c1_eb_emlrtMCI = { 395,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pName */
};

static emlrtMCInfo c1_fb_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validateodd",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validateodd.m"/* pName */
};

static emlrtMCInfo c1_gb_emlrtMCI = { 415,/* lineNo */
  1,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pName */
};

static emlrtMCInfo c1_hb_emlrtMCI = { 642,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtMCInfo c1_ib_emlrtMCI = { 56,/* lineNo */
  27,                                  /* colNo */
  "parseSortrowsOptions",              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/parseSortrowsOptions.m"/* pName */
};

static emlrtRSInfo c1_emlrtRSI = { 4,  /* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2785"          /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 5,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2785"          /* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 6,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2785"          /* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 7,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2785"          /* pathName */
};

static emlrtRSInfo c1_e_emlrtRSI = { 8,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2785"          /* pathName */
};

static emlrtRSInfo c1_f_emlrtRSI = { 9,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2785"          /* pathName */
};

static emlrtRSInfo c1_g_emlrtRSI = { 10,/* lineNo */
  "Image Processing System/MATLAB Function",/* fcnName */
  "#flightControlSystem:2785"          /* pathName */
};

static emlrtRSInfo c1_h_emlrtRSI = { 70,/* lineNo */
  "imbinarize",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imbinarize.m"/* pathName */
};

static emlrtRSInfo c1_i_emlrtRSI = { 102,/* lineNo */
  "imbinarize",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imbinarize.m"/* pathName */
};

static emlrtRSInfo c1_j_emlrtRSI = { 39,/* lineNo */
  "im2uint8",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

static emlrtRSInfo c1_k_emlrtRSI = { 138,/* lineNo */
  "im2uint8",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

static emlrtRSInfo c1_l_emlrtRSI = { 19,/* lineNo */
  "grayto8",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/grayto8.m"/* pathName */
};

static emlrtRSInfo c1_m_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c1_n_emlrtRSI = { 207,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c1_o_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c1_p_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"/* pathName */
};

static emlrtRSInfo c1_q_emlrtRSI = { 37,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/otsuthresh.m"/* pathName */
};

static emlrtRSInfo c1_r_emlrtRSI = { 71,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/otsuthresh.m"/* pathName */
};

static emlrtRSInfo c1_s_emlrtRSI = { 76,/* lineNo */
  "validateattributes",                /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pathName */
};

static emlrtRSInfo c1_t_emlrtRSI = { 45,/* lineNo */
  "mpower",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

static emlrtRSInfo c1_u_emlrtRSI = { 70,/* lineNo */
  "power",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo c1_v_emlrtRSI = { 112,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_w_emlrtRSI = { 128,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_x_emlrtRSI = { 134,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_y_emlrtRSI = { 698,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_ab_emlrtRSI = { 699,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_bb_emlrtRSI = { 704,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_cb_emlrtRSI = { 705,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_db_emlrtRSI = { 106,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c1_eb_emlrtRSI = { 110,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c1_fb_emlrtRSI = { 849,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c1_gb_emlrtRSI = { 1021,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_hb_emlrtRSI = { 934,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_ib_emlrtRSI = { 926,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_jb_emlrtRSI = { 977,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_kb_emlrtRSI = { 21,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c1_lb_emlrtRSI = { 994,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_mb_emlrtRSI = { 923,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c1_nb_emlrtRSI = { 997,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c1_ob_emlrtRSI = { 1025,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c1_pb_emlrtRSI = { 1037,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c1_qb_emlrtRSI = { 714,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_rb_emlrtRSI = { 456,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c1_sb_emlrtRSI = { 757,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_tb_emlrtRSI = { 751,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_ub_emlrtRSI = { 859,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c1_vb_emlrtRSI = { 76,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c1_wb_emlrtRSI = { 77,/* lineNo */
  "bwmorph",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwmorph.m"/* pathName */
};

static emlrtRSInfo c1_xb_emlrtRSI = { 33,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_yb_emlrtRSI = { 322,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_ac_emlrtRSI = { 325,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_bc_emlrtRSI = { 145,/* lineNo */
  "bwlookup",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwlookup.m"/* pathName */
};

static emlrtRSInfo c1_cc_emlrtRSI = { 216,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_dc_emlrtRSI = { 174,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_ec_emlrtRSI = { 175,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_fc_emlrtRSI = { 14,/* lineNo */
  "max",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo c1_gc_emlrtRSI = { 44,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_hc_emlrtRSI = { 79,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_ic_emlrtRSI = { 147,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_jc_emlrtRSI = { 28,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_kc_emlrtRSI = { 38,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_lc_emlrtRSI = { 46,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_mc_emlrtRSI = { 64,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_nc_emlrtRSI = { 24,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_oc_emlrtRSI = { 28,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_pc_emlrtRSI = { 31,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_qc_emlrtRSI = { 32,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_rc_emlrtRSI = { 76,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_sc_emlrtRSI = { 136,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_tc_emlrtRSI = { 187,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_uc_emlrtRSI = { 190,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_vc_emlrtRSI = { 195,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_wc_emlrtRSI = { 35,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_xc_emlrtRSI = { 40,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_yc_emlrtRSI = { 60,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_ad_emlrtRSI = { 101,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_bd_emlrtRSI = { 103,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_cd_emlrtRSI = { 105,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_dd_emlrtRSI = { 107,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_ed_emlrtRSI = { 149,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_fd_emlrtRSI = { 151,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_gd_emlrtRSI = { 152,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_hd_emlrtRSI = { 155,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_id_emlrtRSI = { 575,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_jd_emlrtRSI = { 576,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_kd_emlrtRSI = { 754,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_ld_emlrtRSI = { 755,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_md_emlrtRSI = { 14,/* lineNo */
  "min",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo c1_nd_emlrtRSI = { 46,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_od_emlrtRSI = { 92,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_pd_emlrtRSI = { 157,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_qd_emlrtRSI = { 1017,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c1_rd_emlrtRSI = { 452,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c1_sd_emlrtRSI = { 196,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c1_td_emlrtRSI = { 145,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_ud_emlrtRSI = { 113,/* lineNo */
  "mergesort",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo c1_vd_emlrtRSI = { 40,/* lineNo */
  "safeEq",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/safeEq.m"/* pathName */
};

static emlrtRSInfo c1_wd_emlrtRSI = { 46,/* lineNo */
  "eps",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/eps.m"/* pathName */
};

static emlrtRSInfo c1_xd_emlrtRSI = { 912,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_yd_emlrtRSI = { 917,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_ae_emlrtRSI = { 44,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_be_emlrtRSI = { 240,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_ce_emlrtRSI = { 234,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_de_emlrtRSI = { 226,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_ee_emlrtRSI = { 215,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_fe_emlrtRSI = { 202,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_ge_emlrtRSI = { 195,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_he_emlrtRSI = { 177,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_ie_emlrtRSI = { 158,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_je_emlrtRSI = { 43,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c1_ke_emlrtRSI = { 13,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_le_emlrtRSI = { 17,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_me_emlrtRSI = { 169,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_ne_emlrtRSI = { 172,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_oe_emlrtRSI = { 132,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_pe_emlrtRSI = { 1027,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_qe_emlrtRSI = { 1028,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_re_emlrtRSI = { 1037,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_se_emlrtRSI = { 18,/* lineNo */
  "abs",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo c1_te_emlrtRSI = { 75,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo c1_ue_emlrtRSI = { 13,/* lineNo */
  "any",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/any.m"/* pathName */
};

static emlrtRSInfo c1_ve_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pathName */
};

static emlrtRSInfo c1_we_emlrtRSI = { 32,/* lineNo */
  "sort",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo c1_xe_emlrtRSI = { 72,/* lineNo */
  "sort",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c1_ye_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_af_emlrtRSI = { 308,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_bf_emlrtRSI = { 316,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_cf_emlrtRSI = { 317,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_df_emlrtRSI = { 325,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_ef_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_ff_emlrtRSI = { 392,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_gf_emlrtRSI = { 420,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_hf_emlrtRSI = { 427,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_if_emlrtRSI = { 587,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_jf_emlrtRSI = { 589,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_kf_emlrtRSI = { 617,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_lf_emlrtRSI = { 499,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_mf_emlrtRSI = { 506,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_nf_emlrtRSI = { 507,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_of_emlrtRSI = { 514,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_pf_emlrtRSI = { 561,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_qf_emlrtRSI = { 530,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_rf_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_sf_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_tf_emlrtRSI = { 255,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_uf_emlrtRSI = { 254,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_vf_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_wf_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c1_xf_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c1_yf_emlrtRSI = { 103,/* lineNo */
  "colon",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c1_ag_emlrtRSI = { 305,/* lineNo */
  "colon",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c1_bg_emlrtRSI = { 161,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_cg_emlrtRSI = { 37,/* lineNo */
  "medfilt2",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/medfilt2.m"/* pathName */
};

static emlrtRSInfo c1_dg_emlrtRSI = { 25,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c1_eg_emlrtRSI = { 155,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c1_fg_emlrtRSI = { 179,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c1_gg_emlrtRSI = { 29,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_hg_emlrtRSI = { 34,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_ig_emlrtRSI = { 35,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_jg_emlrtRSI = { 36,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_kg_emlrtRSI = { 48,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_lg_emlrtRSI = { 53,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_mg_emlrtRSI = { 55,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_ng_emlrtRSI = { 66,/* lineNo */
  "imhmax",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/imhmax.m"/* pathName */
};

static emlrtRSInfo c1_og_emlrtRSI = { 10,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c1_pg_emlrtRSI = { 14,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c1_qg_emlrtRSI = { 14,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c1_rg_emlrtRSI = { 35,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c1_sg_emlrtRSI = { 37,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c1_tg_emlrtRSI = { 32,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_ug_emlrtRSI = { 73,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_vg_emlrtRSI = { 75,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_wg_emlrtRSI = { 78,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_xg_emlrtRSI = { 168,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_yg_emlrtRSI = { 197,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_ah_emlrtRSI = { 79,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_bh_emlrtRSI = { 71,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_ch_emlrtRSI = { 70,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_dh_emlrtRSI = { 69,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_eh_emlrtRSI = { 57,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_fh_emlrtRSI = { 44,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_gh_emlrtRSI = { 23,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_hh_emlrtRSI = { 51,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_ih_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_jh_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_kh_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_lh_emlrtRSI = { 153,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c1_mh_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo c1_nh_emlrtRSI = { 99,/* lineNo */
  "sumprod",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo c1_oh_emlrtRSI = { 133,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c1_ph_emlrtRSI = { 194,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c1_qh_emlrtRSI = { 14,/* lineNo */
  "cumsum",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/cumsum.m"/* pathName */
};

static emlrtRSInfo c1_rh_emlrtRSI = { 16,/* lineNo */
  "cumop",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c1_sh_emlrtRSI = { 32,/* lineNo */
  "useConstantDim",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/useConstantDim.m"/* pathName */
};

static emlrtRSInfo c1_th_emlrtRSI = { 99,/* lineNo */
  "cumop",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c1_uh_emlrtRSI = { 125,/* lineNo */
  "cumop",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c1_vh_emlrtRSI = { 290,/* lineNo */
  "cumop",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c1_wh_emlrtRSI = { 1283,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_xh_emlrtRSI = { 1468,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_yh_emlrtRSI = { 28,/* lineNo */
  "repmat",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo c1_ai_emlrtRSI = { 1840,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_bi_emlrtRSI = { 295,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_ci_emlrtRSI = { 1152,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_di_emlrtRSI = { 1143,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_ei_emlrtRSI = { 1138,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_fi_emlrtRSI = { 1135,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_gi_emlrtRSI = { 772,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_hi_emlrtRSI = { 770,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_ii_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pathName */
};

static emlrtRSInfo c1_ji_emlrtRSI = { 22,/* lineNo */
  "cat",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo c1_ki_emlrtRSI = { 102,/* lineNo */
  "cat",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo c1_li_emlrtRSI = { 1121,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_mi_emlrtRSI = { 22,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_ni_emlrtRSI = { 26,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_oi_emlrtRSI = { 274,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_pi_emlrtRSI = { 275,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c1_qi_emlrtRSI = { 10,/* lineNo */
  "round",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/round.m"/* pathName */
};

static emlrtRSInfo c1_ri_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c1_si_emlrtRSI = { 27,/* lineNo */
  "sort",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo c1_ti_emlrtRSI = { 104,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_ui_emlrtRSI = { 340,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_vi_emlrtRSI = { 354,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_wi_emlrtRSI = { 363,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_xi_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_yi_emlrtRSI = { 144,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_aj_emlrtRSI = { 382,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_bj_emlrtRSI = { 402,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c1_cj_emlrtRSI = { 6,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_dj_emlrtRSI = { 14,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_ej_emlrtRSI = { 16,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_fj_emlrtRSI = { 32,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_gj_emlrtRSI = { 35,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_hj_emlrtRSI = { 44,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_ij_emlrtRSI = { 72,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_jj_emlrtRSI = { 73,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c1_kj_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/all.m"/* pathName */
};

static emlrtRSInfo c1_lj_emlrtRSI = { 9,/* lineNo */
  "angle",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/angle.m"/* pathName */
};

static emlrtRSInfo c1_mj_emlrtRSI = { 10,/* lineNo */
  "exp",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/exp.m"/* pathName */
};

static emlrtRSInfo c1_nj_emlrtRSI = { 58,/* lineNo */
  "hough",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m"/* pathName */
};

static emlrtRSInfo c1_oj_emlrtRSI = { 288,/* lineNo */
  "hough",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m"/* pathName */
};

static emlrtRSInfo c1_pj_emlrtRSI = { 295,/* lineNo */
  "hough",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m"/* pathName */
};

static emlrtRSInfo c1_qj_emlrtRSI = { 138,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_rj_emlrtRSI = { 137,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_sj_emlrtRSI = { 91,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_tj_emlrtRSI = { 90,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_uj_emlrtRSI = { 61,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_vj_emlrtRSI = { 219,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_wj_emlrtRSI = { 262,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_xj_emlrtRSI = { 265,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_yj_emlrtRSI = { 268,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_ak_emlrtRSI = { 371,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_bk_emlrtRSI = { 383,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_ck_emlrtRSI = { 415,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_dk_emlrtRSI = { 410,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_ek_emlrtRSI = { 407,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_fk_emlrtRSI = { 404,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_gk_emlrtRSI = { 74,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_hk_emlrtRSI = { 91,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_ik_emlrtRSI = { 127,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_jk_emlrtRSI = { 137,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_kk_emlrtRSI = { 145,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_lk_emlrtRSI = { 159,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_mk_emlrtRSI = { 638,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_nk_emlrtRSI = { 531,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_ok_emlrtRSI = { 501,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_pk_emlrtRSI = { 420,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_qk_emlrtRSI = { 24,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c1_rk_emlrtRSI = { 27,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c1_sk_emlrtRSI = { 28,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c1_tk_emlrtRSI = { 86,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c1_uk_emlrtRSI = { 40,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c1_vk_emlrtRSI = { 43,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c1_wk_emlrtRSI = { 543,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_xk_emlrtRSI = { 587,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_yk_emlrtRSI = { 590,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_al_emlrtRSI = { 608,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRTEInfo c1_emlrtRTEI = { 147,/* lineNo */
  38,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 7,/* lineNo */
  2,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785"          /* pName */
};

static emlrtRTEInfo c1_c_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785"          /* pName */
};

static emlrtRTEInfo c1_d_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785"          /* pName */
};

static emlrtRTEInfo c1_e_emlrtRTEI = { 729,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c1_f_emlrtRTEI = { 730,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c1_g_emlrtRTEI = { 65,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c1_h_emlrtRTEI = { 730,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c1_i_emlrtRTEI = { 128,/* lineNo */
  6,                                   /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c1_j_emlrtRTEI = { 128,/* lineNo */
  17,                                  /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c1_k_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

static emlrtRTEInfo c1_l_emlrtRTEI = { 38,/* lineNo */
  2,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_m_emlrtRTEI = { 38,/* lineNo */
  11,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_n_emlrtRTEI = { 46,/* lineNo */
  17,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_o_emlrtRTEI = { 369,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_p_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_q_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_r_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_s_emlrtRTEI = { 48,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_t_emlrtRTEI = { 64,/* lineNo */
  45,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_u_emlrtRTEI = { 64,/* lineNo */
  17,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_v_emlrtRTEI = { 1,/* lineNo */
  43,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c1_w_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_x_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_y_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_ab_emlrtRTEI = { 32,/* lineNo */
  35,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_bb_emlrtRTEI = { 32,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_cb_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_db_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_eb_emlrtRTEI = { 76,/* lineNo */
  23,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_fb_emlrtRTEI = { 77,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_gb_emlrtRTEI = { 78,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_hb_emlrtRTEI = { 79,/* lineNo */
  33,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ib_emlrtRTEI = { 91,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_jb_emlrtRTEI = { 92,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_kb_emlrtRTEI = { 94,/* lineNo */
  24,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_lb_emlrtRTEI = { 95,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_mb_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_nb_emlrtRTEI = { 120,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ob_emlrtRTEI = { 121,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_pb_emlrtRTEI = { 122,/* lineNo */
  28,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_qb_emlrtRTEI = { 298,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c1_rb_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_sb_emlrtRTEI = { 78,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_tb_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ub_emlrtRTEI = { 91,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_vb_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_wb_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_xb_emlrtRTEI = { 95,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_yb_emlrtRTEI = { 120,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ac_emlrtRTEI = { 121,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_bc_emlrtRTEI = { 122,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_cc_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_dc_emlrtRTEI = { 32,/* lineNo */
  8,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c1_ec_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_fc_emlrtRTEI = { 35,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_gc_emlrtRTEI = { 585,/* lineNo */
  15,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_hc_emlrtRTEI = { 12,/* lineNo */
  20,                                  /* colNo */
  "grayto8",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/grayto8.m"/* pName */
};

static emlrtRTEInfo c1_ic_emlrtRTEI = { 94,/* lineNo */
  13,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_jc_emlrtRTEI = { 912,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_kc_emlrtRTEI = { 917,/* lineNo */
  16,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_lc_emlrtRTEI = { 903,/* lineNo */
  28,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_mc_emlrtRTEI = { 917,/* lineNo */
  36,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_nc_emlrtRTEI = { 903,/* lineNo */
  1,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_oc_emlrtRTEI = { 141,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_pc_emlrtRTEI = { 995,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_qc_emlrtRTEI = { 1044,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_rc_emlrtRTEI = { 1011,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_sc_emlrtRTEI = { 107,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_tc_emlrtRTEI = { 152,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_uc_emlrtRTEI = { 1039,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_vc_emlrtRTEI = { 1020,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_wc_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c1_xc_emlrtRTEI = { 1021,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_yc_emlrtRTEI = { 1008,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_ad_emlrtRTEI = { 157,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_bd_emlrtRTEI = { 1027,/* lineNo */
  24,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_cd_emlrtRTEI = { 1027,/* lineNo */
  20,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_dd_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_ed_emlrtRTEI = { 917,/* lineNo */
  22,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_fd_emlrtRTEI = { 585,/* lineNo */
  17,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c1_gd_emlrtRTEI = { 157,/* lineNo */
  38,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c1_hd_emlrtRTEI = { 159,/* lineNo */
  20,                                  /* colNo */
  "unique",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c1_id_emlrtRTEI = { 170,/* lineNo */
  50,                                  /* colNo */
  "unique",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c1_jd_emlrtRTEI = { 234,/* lineNo */
  1,                                   /* colNo */
  "unique",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c1_kd_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c1_ld_emlrtRTEI = { 31,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pName */
};

static emlrtRTEInfo c1_md_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c1_nd_emlrtRTEI = { 572,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_od_emlrtRTEI = { 482,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_pd_emlrtRTEI = { 520,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_qd_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_rd_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_sd_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_td_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c1_ud_emlrtRTEI = { 41,/* lineNo */
  30,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_vd_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_wd_emlrtRTEI = { 48,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_xd_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_yd_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c1_ae_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_be_emlrtRTEI = { 42,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_ce_emlrtRTEI = { 53,/* lineNo */
  38,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_de_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_ee_emlrtRTEI = { 53,/* lineNo */
  58,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_fe_emlrtRTEI = { 53,/* lineNo */
  18,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_ge_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_he_emlrtRTEI = { 55,/* lineNo */
  33,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_ie_emlrtRTEI = { 298,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c1_je_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"/* pName */
};

static emlrtRTEInfo c1_ke_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c1_le_emlrtRTEI = { 55,/* lineNo */
  10,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_me_emlrtRTEI = { 56,/* lineNo */
  19,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_ne_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_oe_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_pe_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_qe_emlrtRTEI = { 53,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_re_emlrtRTEI = { 291,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_se_emlrtRTEI = { 292,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_te_emlrtRTEI = { 17,/* lineNo */
  25,                                  /* colNo */
  "cumop",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pName */
};

static emlrtRTEInfo c1_ue_emlrtRTEI = { 295,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ve_emlrtRTEI = { 298,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_we_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_xe_emlrtRTEI = { 75,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ye_emlrtRTEI = { 220,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_af_emlrtRTEI = { 233,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_bf_emlrtRTEI = { 234,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_cf_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_df_emlrtRTEI = { 49,/* lineNo */
  25,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_ef_emlrtRTEI = { 50,/* lineNo */
  28,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_ff_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_gf_emlrtRTEI = { 39,/* lineNo */
  35,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_hf_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_if_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_jf_emlrtRTEI = { 69,/* lineNo */
  31,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_kf_emlrtRTEI = { 70,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_lf_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_mf_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_nf_emlrtRTEI = { 90,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_of_emlrtRTEI = { 11,/* lineNo */
  6,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_pf_emlrtRTEI = { 11,/* lineNo */
  19,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_qf_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c1_rf_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_sf_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_tf_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c1_uf_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "useConstantDim",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/useConstantDim.m"/* pName */
};

static emlrtRTEInfo c1_vf_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo c1_wf_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo c1_xf_emlrtRTEI = { 1840,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_yf_emlrtRTEI = { 1719,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ag_emlrtRTEI = { 1130,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_bg_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "round",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/round.m"/* pName */
};

static emlrtRTEInfo c1_cg_emlrtRTEI = { 72,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_dg_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_eg_emlrtRTEI = { 14,/* lineNo */
  56,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_fg_emlrtRTEI = { 14,/* lineNo */
  76,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_gg_emlrtRTEI = { 14,/* lineNo */
  18,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_hg_emlrtRTEI = { 16,/* lineNo */
  20,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_ig_emlrtRTEI = { 16,/* lineNo */
  19,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_jg_emlrtRTEI = { 14,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c1_kg_emlrtRTEI = { 181,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pName */
};

static emlrtRTEInfo c1_lg_emlrtRTEI = { 637,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_mg_emlrtRTEI = { 74,/* lineNo */
  15,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ng_emlrtRTEI = { 531,/* lineNo */
  12,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_og_emlrtRTEI = { 547,/* lineNo */
  29,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_pg_emlrtRTEI = { 531,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_qg_emlrtRTEI = { 560,/* lineNo */
  31,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_rg_emlrtRTEI = { 142,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_sg_emlrtRTEI = { 143,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_tg_emlrtRTEI = { 150,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ug_emlrtRTEI = { 150,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_vg_emlrtRTEI = { 151,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_wg_emlrtRTEI = { 151,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_xg_emlrtRTEI = { 152,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_yg_emlrtRTEI = { 152,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ah_emlrtRTEI = { 153,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_bh_emlrtRTEI = { 153,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ch_emlrtRTEI = { 102,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_dh_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_eh_emlrtRTEI = { 108,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_fh_emlrtRTEI = { 111,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_gh_emlrtRTEI = { 137,/* lineNo */
  5,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_hh_emlrtRTEI = { 1,/* lineNo */
  18,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_ih_emlrtRTEI = { 127,/* lineNo */
  22,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_jh_emlrtRTEI = { 547,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c1_kh_emlrtRTEI = { 11,/* lineNo */
  40,                                  /* colNo */
  "validatepositive",                  /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatepositive.m"/* pName */
};

static emlrtRTEInfo c1_lh_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c1_mh_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c1_nh_emlrtRTEI = { 33,/* lineNo */
  14,                                  /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c1_oh_emlrtRTEI = { 13,/* lineNo */
  21,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c1_ph_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c1_qh_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_rh_emlrtRTEI = { 267,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_sh_emlrtRTEI = { 385,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_th_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_uh_emlrtRTEI = { 274,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_vh_emlrtRTEI = { 387,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_wh_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_xh_emlrtRTEI = { 105,/* lineNo */
  40,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_yh_emlrtRTEI = { 769,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ai_emlrtRTEI = { 770,/* lineNo */
  41,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_bi_emlrtRTEI = { 1120,/* lineNo */
  57,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ci_emlrtRTEI = { 774,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_di_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_ei_emlrtRTEI = { 1142,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_fi_emlrtRTEI = { 1120,/* lineNo */
  47,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_gi_emlrtRTEI = { 40,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_hi_emlrtRTEI = { 1121,/* lineNo */
  33,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ii_emlrtRTEI = { 1143,/* lineNo */
  28,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ji_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_ki_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_li_emlrtRTEI = { 44,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_mi_emlrtRTEI = { 1152,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ni_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_oi_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_pi_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c1_qi_emlrtRTEI = { 1122,/* lineNo */
  27,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ri_emlrtRTEI = { 110,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c1_si_emlrtRTEI = { 117,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c1_ti_emlrtRTEI = { 772,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_ui_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c1_vi_emlrtRTEI = { 770,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c1_wi_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c1_xi_emlrtRTEI = { 27,/* lineNo */
  30,                                  /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c1_yi_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c1_aj_emlrtRTEI = { 52,/* lineNo */
  20,                                  /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c1_bj_emlrtRTEI = { 148,/* lineNo */
  24,                                  /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c1_cj_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c1_dj_emlrtRTEI = { 1,/* lineNo */
  34,                                  /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c1_ej_emlrtRTEI = { 38,/* lineNo */
  23,                                  /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c1_fj_emlrtRTEI = { 38,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtBCInfo c1_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  26,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_emlrtDCI = { 20, /* lineNo */
  26,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  57,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_b_emlrtDCI = { 20,/* lineNo */
  57,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  34,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_c_emlrtDCI = { 23,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  34,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_d_emlrtDCI = { 21,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  13,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_e_emlrtDCI = { 19,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  46,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_f_emlrtDCI = { 19,/* lineNo */
  46,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  21,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_g_emlrtDCI = { 25,/* lineNo */
  21,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2785",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_h_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1049,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_i_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1050,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_j_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1051,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_k_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1052,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  138,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_n_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_o_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  756,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  751,                                 /* lineNo */
  70,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c1_gj_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtBCInfo c1_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ob_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_tb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ub_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  81,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  104,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ec_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1022,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1008,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ic_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1005,                                /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c1_emlrtECI = { 2,  /* nDims */
  917,                                 /* lineNo */
  16,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtBCInfo c1_jc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1032,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1049,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1050,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1064,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_oc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1051,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1052,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c1_b_emlrtECI = { -1,/* nDims */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c1_hj_emlrtRTEI = { 46,/* lineNo */
  15,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtBCInfo c1_rc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_tc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_uc_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1896,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ad_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1898,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_h_emlrtDCI = { 48,/* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c1_ed_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_i_emlrtDCI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_id_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ld_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_md_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_od_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_td_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ud_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ae_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_be_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ce_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_de_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ee_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ge_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_he_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ie_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_je_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_j_emlrtDCI = { 69,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c1_k_emlrtDCI = { 69,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c1_ke_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_le_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_me_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ne_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_oe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_re_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_se_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_te_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ue_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ve_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  72,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_we_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  92,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ye_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_af_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  14,                                  /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bf_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  299,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_cf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  346,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_df_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  299,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ef_emlrtBCI = { 1,/* iFirst */
  71820,                               /* iLast */
  110,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_ff_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  107,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gf_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  107,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  142,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_if_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  150,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  150,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  248,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_of_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  591,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  592,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qf_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  531,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rf_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  398,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_tf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_uf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_vf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ag_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_cg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  591,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_eg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  592,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  593,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  593,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  594,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ig_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  594,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_l_emlrtDCI = { 547,/* lineNo */
  35,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c1_jg_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  503,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_kg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  429,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_m_emlrtDCI = { 560,/* lineNo */
  37,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_lg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ng_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_og_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_pg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_qg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_rg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  554,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_sg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  565,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_tg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  567,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ug_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  152,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_n_emlrtDCI = { 31,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c1_o_emlrtDCI = { 31,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo c1_c_emlrtECI = { -1,/* nDims */
  1152,                                /* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtBCInfo c1_vg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1144,                                /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_wg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_xg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1120,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_yg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  774,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ah_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1152,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_bh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1156,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ch_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_dh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_eh_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_fh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_gh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  772,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_hh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  769,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_ih_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  770,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_jh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1120,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_kh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1142,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_lh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1142,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_mh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1121,                                /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_nh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1152,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_oh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1122,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c1_bl_emlrtRSI = { 1142,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c1_cl_emlrtRSI = { 41,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c1_dl_emlrtRSI = { 79,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_el_emlrtRSI = { 78,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_fl_emlrtRSI = { 77,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_gl_emlrtRSI = { 153,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_hl_emlrtRSI = { 152,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_il_emlrtRSI = { 170,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_jl_emlrtRSI = { 159,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c1_kl_emlrtRSI = { 122,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_ll_emlrtRSI = { 181,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c1_ml_emlrtRSI = { 56,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_nl_emlrtRSI = { 40,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c1_ol_emlrtRSI = { 94,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c1_pl_emlrtRSI = { 48,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_ql_emlrtRSI = { 47,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c1_rl_emlrtRSI = { 31,/* lineNo */
  "repmat",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo c1_sl_emlrtRSI = { 95,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_tl_emlrtRSI = { 38,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c1_ul_emlrtRSI = { 52,/* lineNo */
  "mergesort",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo c1_vl_emlrtRSI = { 55,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_wl_emlrtRSI = { 39,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c1_xl_emlrtRSI = { 48,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c1_yl_emlrtRSI = { 46,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c1_am_emlrtRSI = { 121,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_bm_emlrtRSI = { 120,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_cm_emlrtRSI = { 92,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_dm_emlrtRSI = { 91,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_em_emlrtRSI = { 94,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c1_fm_emlrtRSI = { 1,/* lineNo */
  "mergesort",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo c1_gm_emlrtRSI = { 151,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_hm_emlrtRSI = { 150,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c1_im_emlrtRSI = { 53,/* lineNo */
  "repmat",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static const char_T c1_cv[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
  'i', 'n', 'i', 't', 'e' };

static const real_T c1_dv[13] = { 3.4813359214923059E-5, 0.00054457256285105158,
  0.0051667606200595222, 0.029732654490475543, 0.10377716120747747,
  0.21969625200024598, 0.28209557151935094, 0.21969625200024598,
  0.10377716120747747, 0.029732654490475543, 0.0051667606200595222,
  0.00054457256285105158, 3.4813359214923059E-5 };

static const real_T c1_dv1[13] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, 0.0, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static const real_T c1_dv2[12] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static const boolean_T c1_bv[13] = { true, true, true, true, true, true, false,
  true, true, true, true, true, true };

static const char_T c1_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i',
  'l', 't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
  'a', 'i', 'l', 'e', 'd' };

static const char_T c1_cv2[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
  'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm',
  'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

static const char_T c1_cv3[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c', 'h'
};

static const char_T c1_cv4[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N',
  'o', 'n', 'N', 'a', 'N' };

static const char_T c1_cv5[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
  'a', 'x', 's', 'i', 'z', 'e' };

static const char_T c1_cv6[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'P',
  'o', 's', 'i', 't', 'i', 'v', 'e' };

static const char_T c1_cv7[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
  'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
  'd', 'F', 'i', 'n', 'i', 't', 'e' };

static const char_T c1_cv8[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
  'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
  'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

static const char_T c1_cv9[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
  'n', 't', 'e', 'g', 'e', 'r' };

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_imhist(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, uint8_T c1_d_varargin_1[19200],
                      real_T c1_yout[256]);
static real_T c1_otsuthresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_counts[256]);
static void c1_edge(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200],
                    boolean_T c1_varargout_1[19200]);
static void c1_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200]);
static void c1_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[19200], real32_T c1_g_a[21120]);
static void c1_check_forloop_overflow_error
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp);
static void c1_b_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200]);
static void c1_b_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[19200], real32_T c1_g_a[20640]);
static void c1_c_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200]);
static void c1_d_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200]);
static void c1_b_imhist(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real_T c1_yout[64]);
static void c1_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp);
static void c1_thinAndThreshold(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, boolean_T c1_E[19200], real32_T
  c1_c_dx[19200], real32_T c1_c_dy[19200], real32_T c1_magGrad[19200], real_T
  c1_lowThresh_data[], int32_T c1_lowThresh_size[1], real_T c1_highThresh_data[],
  int32_T c1_highThresh_size[1], boolean_T c1_b_H[19200]);
static void c1_imreconstruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c1_marker[19200], boolean_T c1_mask[19200],
  boolean_T c1_im[19200]);
static void c1_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_bw[19200]);
static void c1_bwmorphApplyOnce(SFc1_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c1_bw[19200], boolean_T c1_b_bw[19200]);
static void c1_bwlookup(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_B[19200]);
static void c1_b_bwlookup(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_B[19200]);
static void c1_e_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200]);
static void c1_c_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[19200], real32_T c1_g_a[20336]);
static void c1_f_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200]);
static void c1_d_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[19200], real32_T c1_g_a[19764]);
static void c1_g_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200]);
static void c1_hypot(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     real32_T c1_c_x[19200], real32_T c1_y[19200], real32_T
                     c1_r[19200]);
static real32_T c1_maximum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_x[19200]);
static void c1_imfindcircles(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200],
  c1_emxArray_real_T *c1_centers, c1_emxArray_real_T *c1_r_estimated,
  c1_emxArray_real_T *c1_metric);
static void c1_chaccum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200], creal_T
  c1_c_accumMatrix[19200], real32_T c1_b_gradientImg[19200]);
static real32_T c1_multithresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200]);
static real32_T c1_minimum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_x[19200]);
static void c1_c_imhist(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, uint8_T c1_varargin_1_data[], int32_T
  c1_varargin_1_size[1], real_T c1_yout[256]);
static real_T c1_sum(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     real_T c1_c_x[256]);
static void c1_b_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp);
static void c1_power(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     real_T c1_g_a[256], real_T c1_y[256]);
static real_T c1_b_maximum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_c_x[256]);
static void c1_mergesort(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, int32_T c1_b_idx[19200], real32_T c1_c_x[19200],
  int32_T c1_c_idx[19200]);
static void c1_unique_vector(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real32_T c1_g_a[19200],
  c1_emxArray_real32_T *c1_b);
static void c1_indexShapeCheck(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, int32_T c1_matrixSize, int32_T
  c1_indexSize[2]);
static void c1_nullAssignment(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T *c1_c_x,
  boolean_T c1_idx_data[], int32_T c1_idx_size[2], c1_emxArray_real32_T *c1_d_x);
static void c1_c_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp);
static void c1_abs(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x,
                   c1_emxArray_real_T *c1_y);
static real_T c1_eps(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     real_T c1_c_x);
static boolean_T c1_any(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_b_x_data[], int32_T c1_x_size[1]);
static void c1_sort(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, c1_emxArray_real32_T *c1_c_x,
                    c1_emxArray_real32_T *c1_d_x);
static void c1_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real32_T *c1_c_x, int32_T c1_offset, c1_emxArray_int32_T *c1_c_idx,
  c1_emxArray_real32_T *c1_d_x);
static void c1_merge_block(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_real32_T
  *c1_c_x, int32_T c1_offset, int32_T c1_n, int32_T c1_preSortLevel,
  c1_emxArray_int32_T *c1_b_iwork, c1_emxArray_real32_T *c1_xwork,
  c1_emxArray_int32_T *c1_c_idx, c1_emxArray_real32_T *c1_d_x,
  c1_emxArray_int32_T *c1_c_iwork, c1_emxArray_real32_T *c1_b_xwork);
static void c1_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
                     c1_emxArray_real32_T *c1_c_x, int32_T c1_offset, int32_T
                     c1_np, int32_T c1_nq, c1_emxArray_int32_T *c1_b_iwork,
                     c1_emxArray_real32_T *c1_xwork, c1_emxArray_int32_T
                     *c1_c_idx, c1_emxArray_real32_T *c1_d_x,
                     c1_emxArray_int32_T *c1_c_iwork, c1_emxArray_real32_T
                     *c1_b_xwork);
static void c1_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_x[19200], c1_emxArray_int32_T *c1_i,
  c1_emxArray_int32_T *c1_j);
static boolean_T c1_allinrange(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T *c1_c_x, int32_T c1_hi);
static void c1_eml_sub2ind(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_real_T *c1_d_varargin_1,
  c1_emxArray_real_T *c1_b_varargin_2, c1_emxArray_int32_T *c1_b_idx);
static void c1_medfilt2(SFc1_flightControlSystemInstanceStruct *chartInstance,
  real_T c1_d_varargin_1[19200], real_T c1_b[19200]);
static void c1_chcenters(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, creal_T c1_d_varargin_1[19200], c1_emxArray_real_T
  *c1_centers, c1_emxArray_real_T *c1_metric);
static void c1_imhmax(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real_T c1_I[19200], real_T
                      c1_b_J[19200]);
static void c1_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_g_a[19200]);
static void c1_imregionalmax(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_d_varargin_1[19200],
  boolean_T c1_c_BW[19200]);
static void c1_regionprops(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200], real_T
  c1_b_varargin_2[19200], c1_emxArray_sBO2RC5RVZVTbundPSRqHn *c1_outstats);
static void c1_bwconncomp(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200],
  c1_s_VSLwMee4Kv1oTF0BcoITHB *c1_CC);
static void c1_useConstantDim(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_varargin_2,
  int32_T c1_varargin_3, c1_emxArray_int32_T *c1_varargout_1);
static void c1_repmat(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real_T c1_d_varargin_1,
                      c1_emxArray_sBO2RC5RVZVTbundPSRqHn *c1_b);
static void c1_assertValidSizeArg(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_d_varargin_1);
static void c1_initializeStatsStruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_numObjs,
  c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_statsAlreadyComputed);
static void c1_ComputeWeightedCentroid(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_I[19200],
  c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  c1_statsAlreadyComputed, c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_b_stats,
  c1_sHtk0WM4OMtyqkehwQYcq2 *c1_b_statsAlreadyComputed);
static real_T c1_b_sum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x);
static void c1_round(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x,
                     c1_emxArray_real_T *c1_d_x);
static void c1_b_sort(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x,
                      c1_emxArray_real_T *c1_d_x, c1_emxArray_int32_T *c1_b_idx);
static void c1_b_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real_T *c1_c_x, int32_T c1_offset, c1_emxArray_int32_T *c1_c_idx,
  c1_emxArray_real_T *c1_d_x);
static void c1_b_merge_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real_T *c1_c_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_emxArray_int32_T *c1_b_iwork, c1_emxArray_real_T *c1_xwork,
  c1_emxArray_int32_T *c1_c_idx, c1_emxArray_real_T *c1_d_x, c1_emxArray_int32_T
  *c1_c_iwork, c1_emxArray_real_T *c1_b_xwork);
static void c1_b_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_real_T
  *c1_c_x, int32_T c1_offset, int32_T c1_np, int32_T c1_nq, c1_emxArray_int32_T *
  c1_b_iwork, c1_emxArray_real_T *c1_xwork, c1_emxArray_int32_T *c1_c_idx,
  c1_emxArray_real_T *c1_d_x, c1_emxArray_int32_T *c1_c_iwork,
  c1_emxArray_real_T *c1_b_xwork);
static void c1_chradiiphcode(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_d_varargin_1,
  creal_T c1_b_varargin_2[19200], c1_emxArray_real_T *c1_r_estimated);
static boolean_T c1_all(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_boolean_T *c1_c_x);
static void c1_angle(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_emxArray_creal_T *c1_c_x,
                     c1_emxArray_real_T *c1_y);
static void c1_hough(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200],
                     real_T c1_h[71820]);
static void c1_houghpeaks(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_d_varargin_1[71820], real_T c1_varargin_4,
  c1_emxArray_real_T *c1_peaks);
static void c1_b_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_g_a[2]);
static real_T c1_b_minimum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_c_x[180]);
static real_T c1_c_maximum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_c_x[180]);
static void c1_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                    real_T c1_c_x[180], real_T c1_y[179]);
static void c1_b_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      real_T c1_c_x[179], real_T c1_y[178]);
static void c1_houghlines(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200], c1_emxArray_real_T *
  c1_varargin_4, c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *c1_lines);
static void c1_c_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_g_a);
static void c1_sortrows(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_y, real_T c1_d_varargin_1[2],
  c1_emxArray_int32_T *c1_b_y);
static void c1_b_mergesort(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_int32_T
  *c1_c_x, int32_T c1_dir[2], int32_T c1_n, c1_emxArray_int32_T *c1_c_idx);
static boolean_T c1_sortLE(SFc1_flightControlSystemInstanceStruct *chartInstance,
  c1_emxArray_int32_T *c1_v, int32_T c1_dir[2], int32_T c1_idx1, int32_T c1_idx2);
static void c1_apply_row_permutation(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_y,
  c1_emxArray_int32_T *c1_b_idx, c1_emxArray_int32_T *c1_b_y);
static int32_T c1_b_power(SFc1_flightControlSystemInstanceStruct *chartInstance,
  int32_T c1_g_a);
static void c1_b_repmat(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, int32_T c1_b_varargin_2,
  c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *c1_b);
static const mxArray *c1_emlrt_marshallOut
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const char_T c1_c_u[30]);
static real_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_angelina, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId);
static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_flightControlSystem, const
  char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_chart_data_browse_helper
  (SFc1_flightControlSystemInstanceStruct *chartInstance, int32_T c1_ssIdNumber);
static const mxArray *c1_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1);
static void c1_b_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1);
static const mxArray *c1_c_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1, const mxArray *c1_input2);
static void c1_d_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1);
static const mxArray *c1_e_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1);
static void c1_f_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1);
static void c1_b_bwmorphApplyOnce(SFc1_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c1_bw[19200]);
static void c1_c_mergesort(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, int32_T c1_b_idx[19200], real32_T c1_c_x[19200]);
static void c1_b_nullAssignment(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T *c1_c_x,
  boolean_T c1_idx_data[], int32_T c1_idx_size[2]);
static void c1_c_sort(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_emxArray_real32_T *c1_c_x);
static void c1_c_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real32_T *c1_c_x, int32_T c1_offset);
static void c1_c_merge_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real32_T *c1_c_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_emxArray_int32_T *c1_b_iwork, c1_emxArray_real32_T
  *c1_xwork);
static void c1_c_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_real32_T
  *c1_c_x, int32_T c1_offset, int32_T c1_np, int32_T c1_nq, c1_emxArray_int32_T *
  c1_b_iwork, c1_emxArray_real32_T *c1_xwork);
static void c1_b_ComputeWeightedCentroid(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, real_T c1_I[19200],
  c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_statsAlreadyComputed);
static void c1_b_round(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x);
static void c1_d_sort(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x,
                      c1_emxArray_int32_T *c1_b_idx);
static void c1_d_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real_T *c1_c_x, int32_T c1_offset);
static void c1_d_merge_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real_T *c1_c_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_emxArray_int32_T *c1_b_iwork, c1_emxArray_real_T *c1_xwork);
static void c1_d_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_real_T
  *c1_c_x, int32_T c1_offset, int32_T c1_np, int32_T c1_nq, c1_emxArray_int32_T *
  c1_b_iwork, c1_emxArray_real_T *c1_xwork);
static void c1_b_sortrows(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_y, real_T c1_d_varargin_1[2]);
static void c1_d_mergesort(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_int32_T
  *c1_c_x, int32_T c1_dir[2], int32_T c1_n);
static void c1_b_apply_row_permutation(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_y,
  c1_emxArray_int32_T *c1_b_idx);
static void c1_emxEnsureCapacity_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_skoeQIuVNKJRHNtBIlOCZhD
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_skoeQIuVNKJRHNtBIlOCZh **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFree_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray);
static void c1_emxFree_skoeQIuVNKJRHNtBIlOCZhD
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_skoeQIuVNKJRHNtBIlOCZh **c1_pEmxArray);
static void c1_emxEnsureCapacity_real32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFree_real32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray);
static void c1_emxEnsureCapacity_creal_T(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_creal_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_real_T1(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_boolean_T
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_boolean_T *c1_emxArray, int32_T c1_oldNumel, const
   emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_int32_T(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_boolean_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_boolean_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_creal_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_creal_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFree_boolean_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray);
static void c1_emxFree_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_int32_T **c1_pEmxArray);
static void c1_emxFree_creal_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_creal_T **c1_pEmxArray);
static void c1_emxEnsureCapacity_real32_T1
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_real32_T *c1_emxArray, int32_T c1_oldNumel, const
   emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_creal_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_creal_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_real32_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_creal_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_creal_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_int32_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_sBO2RC5RVZVTbundPSRqHnH
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_sBO2RC5RVZVTbundPSRqHn **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_int32_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFree_sBO2RC5RVZVTbundPSRqHnH
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_sBO2RC5RVZVTbundPSRqHn **c1_pEmxArray);
static void c1_emxInitStruct_s_VSLwMee4Kv1oTF0
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s_VSLwMee4Kv1oTF0BcoITHB *c1_pStruct, const emlrtRTEInfo
   *c1_srcLocation);
static void c1_emxInit_s_nrlUwWofUDGxo1t78e6dw
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s_nrlUwWofUDGxo1t78e6d **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxFreeStruct_s_VSLwMee4Kv1oTF0
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_VSLwMee4Kv1oTF0BcoITHB *c1_pStruct);
static void c1_emxFree_s_nrlUwWofUDGxo1t78e6dw
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_s_nrlUwWofUDGxo1t78e6d **c1_pEmxArray);
static void c1_emxFreeStruct_s_nrlUwWofUDGxo1t
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_nrlUwWofUDGxo1t78e6dwC *c1_pStruct);
static void c1_emxEnsureCapacity_boolean_T1
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_boolean_T *c1_emxArray, int32_T c1_oldNumel, const
   emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_sBO2RC5RVZVTb
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_sBO2RC5RVZVTbundPSRqHn *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInit_boolean_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_boolean_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxTrim_s_nrlUwWofUDGxo1t78e6dw
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_emxArray, int32_T c1_fromIndex,
   int32_T c1_toIndex);
static void c1_emxInitStruct_s_nrlUwWofUDGxo1t
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s_nrlUwWofUDGxo1t78e6dwC *c1_pStruct, const emlrtRTEInfo
   *c1_srcLocation);
static void c1_emxExpand_s_nrlUwWofUDGxo1t78e6
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_emxArray, int32_T c1_fromIndex,
   int32_T c1_toIndex, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxEnsureCapacity_s_nrlUwWofUDG
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopyStruct_s_nrlUwWofUDGxo1t
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s_nrlUwWofUDGxo1t78e6dwC *c1_dst, const
   c1_s_nrlUwWofUDGxo1t78e6dwC *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopyMatrix_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[2], const real_T c1_src[2]);
static void c1_emxCopyMatrix_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[4], const real_T c1_src[4]);
static void c1_emxCopy_boolean_T_0x0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_boolean_T_0x0 *c1_dst, const
  c1_emxArray_boolean_T_0x0 *c1_src);
static void c1_emxCopyMatrix_real_T2(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[16], const real_T c1_src[16]);
static void c1_emxCopy_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_dst,
  c1_emxArray_real_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopy_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_dst,
  c1_emxArray_real_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation);
static void c1_emxCopy_real_T_1x0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T_1x0 *c1_dst, const c1_emxArray_real_T_1x0
  *c1_src);
static void c1_emxEnsureCapacity_skoeQIuVNKJRH
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation);
static void c1_emxInitMatrix_cell_wrap_52(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_52 c1_pMatrix[2], const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxInitStruct_cell_wrap_52(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_52 *c1_pStruct, const
  emlrtRTEInfo *c1_srcLocation);
static void c1_emxFreeMatrix_cell_wrap_52(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_cell_wrap_52 c1_pMatrix[2]);
static void c1_emxFreeStruct_cell_wrap_52(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_cell_wrap_52 *c1_pStruct);
static int32_T c1_div_nzp_s32(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, int32_T
  c1_EMLOvCount_src_loc, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc,
  int32_T c1_length_src_loc);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c1_st, "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_flightControlSystem = 0U;
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_jit_animation_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(5, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", chartInstance->c1_angelina, 0, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", chartInstance->c1_data1, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", chartInstance->c1_mode, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", chartInstance->c1_output_angle, 0,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y",
    &chartInstance->c1_is_active_c1_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_c_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_c_u = sf_mex_dup(c1_st);
  *chartInstance->c1_angelina = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_c_u, 0)), "angelina");
  *chartInstance->c1_data1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_c_u, 1)), "data1");
  *chartInstance->c1_mode = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_c_u, 2)), "mode");
  *chartInstance->c1_output_angle = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_c_u, 3)), "output_angle");
  chartInstance->c1_is_active_c1_flightControlSystem = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_c_u, 4)),
     "is_active_c1_flightControlSystem");
  sf_mex_destroy(&c1_c_u);
  sf_mex_destroy(&c1_st);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  c1_emxArray_real_T *c1_P;
  c1_emxArray_real_T *c1_c_x;
  c1_emxArray_real_T *c1_centers;
  c1_emxArray_real_T *c1_unusedU0;
  c1_emxArray_real_T *c1_unusedU1;
  c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *c1_lines;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_g_st;
  emlrtStack c1_h_st;
  emlrtStack c1_i_st;
  emlrtStack c1_j_st;
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c1_b_dv[256];
  real_T c1_T;
  real_T c1_b_ang;
  real_T c1_b_angelina;
  real_T c1_b_angle;
  real_T c1_b_angle_;
  real_T c1_b_data;
  real_T c1_b_data1;
  real_T c1_b_mode;
  real_T c1_b_output_angle;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d_n;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_ex;
  real_T c1_f_n;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_maxval;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r;
  real_T c1_sig;
  real_T c1_t;
  int32_T c1_ang;
  int32_T c1_b_b;
  int32_T c1_b_idx;
  int32_T c1_b_k;
  int32_T c1_b_n;
  int32_T c1_b_varargin_2;
  int32_T c1_c_b;
  int32_T c1_c_n;
  int32_T c1_c_varargin_2;
  int32_T c1_d_b;
  int32_T c1_d_varargin_1;
  int32_T c1_d_varargin_2;
  int32_T c1_e_b;
  int32_T c1_e_n;
  int32_T c1_e_varargin_1;
  int32_T c1_e_varargin_2;
  int32_T c1_exitg2;
  int32_T c1_f_varargin_1;
  int32_T c1_first;
  int32_T c1_g_a;
  int32_T c1_g_varargin_1;
  int32_T c1_h_a;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_k;
  int32_T c1_last;
  int32_T c1_n;
  boolean_T c1_b;
  boolean_T c1_b_overflow;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_guard1 = false;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_g_st.prev = &c1_f_st;
  c1_g_st.tls = c1_f_st.tls;
  c1_h_st.prev = &c1_g_st;
  c1_h_st.tls = c1_g_st.tls;
  c1_i_st.prev = &c1_h_st;
  c1_i_st.tls = c1_h_st.tls;
  c1_j_st.prev = &c1_i_st;
  c1_j_st.tls = c1_i_st.tls;
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 2U,
                    *chartInstance->c1_angle_);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, *chartInstance->c1_data);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U,
                      (*chartInstance->c1_b_u)[c1_i]);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_b_data = *chartInstance->c1_data;
  c1_b_angle_ = *chartInstance->c1_angle_;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  c1_b_angelina = c1_b_angle_;
  c1_b_data1 = c1_b_data;
  c1_b_st.site = &c1_emlrtRSI;
  c1_c_st.site = &c1_h_emlrtRSI;
  c1_d_st.site = &c1_i_emlrtRSI;
  c1_e_st.site = &c1_j_emlrtRSI;
  c1_f_st.site = &c1_k_emlrtRSI;
  c1_g_st.site = &c1_l_emlrtRSI;
  grayto8_real64(&(*chartInstance->c1_b_u)[0], &chartInstance->c1_u[0], 19200.0);
  c1_d_st.site = &c1_i_emlrtRSI;
  c1_imhist(chartInstance, &c1_d_st, chartInstance->c1_u, c1_b_dv);
  c1_d_st.site = &c1_i_emlrtRSI;
  c1_t = c1_otsuthresh(chartInstance, &c1_d_st, c1_b_dv);
  c1_T = c1_t;
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    chartInstance->c1_BW3[c1_i1] = ((*chartInstance->c1_b_u)[c1_i1] > c1_T);
  }

  c1_emxInit_real_T(chartInstance, &c1_b_st, &c1_centers, 2, &c1_b_emlrtRTEI);
  c1_emxInit_real_T(chartInstance, &c1_b_st, &c1_unusedU0, 2, (emlrtRTEInfo *)
                    NULL);
  c1_emxInit_real_T(chartInstance, &c1_b_st, &c1_unusedU1, 2, (emlrtRTEInfo *)
                    NULL);
  c1_b_st.site = &c1_b_emlrtRSI;
  for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
    chartInstance->c1_b_BW3[c1_i2] = chartInstance->c1_BW3[c1_i2];
  }

  c1_edge(chartInstance, &c1_b_st, chartInstance->c1_b_BW3, chartInstance->c1_BW);
  c1_b_st.site = &c1_c_emlrtRSI;
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    chartInstance->c1_b_BW[c1_i3] = chartInstance->c1_BW[c1_i3];
  }

  c1_bwmorph(chartInstance, chartInstance->c1_b_BW, chartInstance->c1_BW4);
  c1_b_st.site = &c1_d_emlrtRSI;
  c1_imfindcircles(chartInstance, &c1_b_st, chartInstance->c1_BW3, c1_centers,
                   c1_unusedU0, c1_unusedU1);
  c1_b_st.site = &c1_e_emlrtRSI;
  c1_hough(chartInstance, &c1_b_st, chartInstance->c1_BW4, chartInstance->c1_H);
  c1_b_st.site = &c1_f_emlrtRSI;
  c1_emxFree_real_T(chartInstance, &c1_unusedU1);
  c1_emxFree_real_T(chartInstance, &c1_unusedU0);
  for (c1_i4 = 0; c1_i4 < 71820; c1_i4++) {
    chartInstance->c1_varargin_1[c1_i4] = chartInstance->c1_H[c1_i4];
  }

  c1_emxInit_real_T1(chartInstance, &c1_b_st, &c1_c_x, 1, &c1_emlrtRTEI);
  c1_c_st.site = &c1_fc_emlrtRSI;
  c1_d_st.site = &c1_gc_emlrtRSI;
  c1_e_st.site = &c1_hc_emlrtRSI;
  c1_f_st.site = &c1_ic_emlrtRSI;
  c1_i5 = c1_c_x->size[0];
  c1_c_x->size[0] = 71820;
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_f_st, c1_c_x, c1_i5,
    &c1_emlrtRTEI);
  for (c1_i6 = 0; c1_i6 < 71820; c1_i6++) {
    c1_c_x->data[c1_i6] = chartInstance->c1_varargin_1[c1_i6];
  }

  c1_g_st.site = &c1_gb_emlrtRSI;
  c1_n = c1_c_x->size[0];
  c1_h_st.site = &c1_ib_emlrtRSI;
  c1_b_n = c1_c_x->size[0];
  c1_d_x = c1_c_x->data[0];
  c1_e_x = c1_d_x;
  c1_b = muDoubleScalarIsNaN(c1_e_x);
  c1_p = !c1_b;
  if (c1_p) {
    c1_b_idx = 1;
  } else {
    c1_b_idx = 0;
    c1_i_st.site = &c1_jb_emlrtRSI;
    c1_b_b = c1_b_n;
    c1_c_b = c1_b_b;
    if (2 > c1_c_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_j_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_j_st);
    }

    c1_k = 2;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k <= c1_b_n)) {
      c1_h_x = c1_c_x->data[c1_k - 1];
      c1_i_x = c1_h_x;
      c1_f_b = muDoubleScalarIsNaN(c1_i_x);
      c1_b_p = !c1_f_b;
      if (c1_b_p) {
        c1_b_idx = c1_k;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }
  }

  if (c1_b_idx == 0) {
    c1_maxval = c1_c_x->data[0];
  } else {
    c1_h_st.site = &c1_hb_emlrtRSI;
    c1_first = c1_b_idx - 1;
    c1_last = c1_n;
    c1_ex = c1_c_x->data[c1_first];
    c1_i7 = c1_first + 2;
    c1_i_st.site = &c1_lb_emlrtRSI;
    c1_g_a = c1_i7;
    c1_d_b = c1_last;
    c1_h_a = c1_g_a;
    c1_e_b = c1_d_b;
    if (c1_h_a > c1_e_b) {
      c1_b_overflow = false;
    } else {
      c1_b_overflow = (c1_e_b > 2147483646);
    }

    if (c1_b_overflow) {
      c1_j_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_j_st);
    }

    for (c1_b_k = c1_i7 - 1; c1_b_k < c1_last; c1_b_k++) {
      if (c1_ex < c1_c_x->data[c1_b_k]) {
        c1_ex = c1_c_x->data[c1_b_k];
      }
    }

    c1_maxval = c1_ex;
  }

  c1_emxFree_real_T(chartInstance, &c1_c_x);
  c1_emxInit_real_T(chartInstance, &c1_g_st, &c1_P, 2, &c1_c_emlrtRTEI);
  c1_emxInit_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c1_g_st, &c1_lines, 2,
    &c1_d_emlrtRTEI);
  c1_f_x = 0.3 * c1_maxval;
  c1_g_x = c1_f_x;
  c1_g_x = muDoubleScalarCeil(c1_g_x);
  c1_b_st.site = &c1_f_emlrtRSI;
  c1_houghpeaks(chartInstance, &c1_b_st, chartInstance->c1_H, c1_g_x, c1_P);
  c1_b_st.site = &c1_g_emlrtRSI;
  c1_houghlines(chartInstance, &c1_b_st, chartInstance->c1_BW, c1_P, c1_lines);
  c1_b_angle = 0.0;
  c1_r = 0.0;
  c1_b_mode = 0.0;
  c1_emxFree_real_T(chartInstance, &c1_P);
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 0U, (real_T)c1_lines->size[1], 4.0, -1, 0U, (real_T)
        c1_lines->size[1] == 4.0))) {
    c1_b_mode = 1.0;
    c1_sig = 0.0;
    c1_ang = 0;
    c1_guard1 = false;
    do {
      c1_exitg2 = 0;
      if (c1_ang < 4) {
        c1_b_ang = 1.0 + (real_T)c1_ang;
        covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 0, 1);
        c1_i8 = c1_lines->size[1];
        c1_i9 = (int32_T)emlrtIntegerCheckR2012b(c1_b_ang, &c1_e_emlrtDCI,
          &c1_st);
        c1_d = c1_lines->data[emlrtDynamicBoundsCheckR2012b(c1_i9, 1, c1_i8,
          &c1_e_emlrtBCI, &c1_st) - 1].theta;
        if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c1_covrtInstance, 4U, 0U, 1U, c1_d,
                              c1_b_angle_ + 5.0, -1, 4U, c1_d > c1_b_angle_ +
                              5.0))) {
          c1_guard1 = true;
          c1_exitg2 = 1;
        } else {
          c1_i10 = c1_lines->size[1];
          c1_i12 = (int32_T)emlrtIntegerCheckR2012b(c1_b_ang, &c1_f_emlrtDCI,
            &c1_st);
          c1_d1 = c1_lines->data[emlrtDynamicBoundsCheckR2012b(c1_i12, 1, c1_i10,
            &c1_f_emlrtBCI, &c1_st) - 1].theta;
          if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 1,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c1_covrtInstance, 4U, 0U, 2U,
                                c1_d1, c1_b_angle_ - 5.0, -1, 2U, c1_d1 <
                                c1_b_angle_ - 5.0))) {
            c1_guard1 = true;
            c1_exitg2 = 1;
          } else {
            covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 0, false);
            covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 1, false);
            c1_ang++;
            _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
            c1_guard1 = false;
          }
        }
      } else {
        covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 0, 0);
        c1_exitg2 = 1;
      }
    } while (c1_exitg2 == 0);

    if (c1_guard1) {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 0, true);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 1, true);
      c1_i11 = c1_lines->size[1];
      c1_i13 = (int32_T)emlrtIntegerCheckR2012b(c1_b_ang, &c1_emlrtDCI, &c1_st);
      c1_i14 = emlrtDynamicBoundsCheckR2012b(c1_i13, 1, c1_i11, &c1_emlrtBCI,
        &c1_st) - 1;
      c1_j_x = c1_lines->data[c1_i14].point1[0] - 90.0;
      c1_k_x = c1_j_x;
      c1_l_x = c1_k_x;
      c1_d2 = muDoubleScalarAbs(c1_l_x);
      c1_i15 = c1_lines->size[1];
      c1_i16 = (int32_T)emlrtIntegerCheckR2012b(c1_b_ang, &c1_b_emlrtDCI, &c1_st);
      c1_i17 = emlrtDynamicBoundsCheckR2012b(c1_i16, 1, c1_i15, &c1_b_emlrtBCI,
        &c1_st) - 1;
      c1_m_x = c1_lines->data[c1_i17].point2[0] - 90.0;
      c1_n_x = c1_m_x;
      c1_o_x = c1_n_x;
      c1_d3 = muDoubleScalarAbs(c1_o_x);
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 2,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 3U, c1_d2,
                          c1_d3, -1, 4U, c1_d2 > c1_d3))) {
        c1_i19 = c1_lines->size[1];
        c1_i21 = (int32_T)emlrtIntegerCheckR2012b(c1_b_ang, &c1_d_emlrtDCI,
          &c1_st);
        c1_i23 = emlrtDynamicBoundsCheckR2012b(c1_i21, 1, c1_i19, &c1_d_emlrtBCI,
          &c1_st) - 1;
        c1_q_x = c1_lines->data[c1_i23].point1[0] - 90.0;
        c1_sig = c1_q_x;
        c1_sig = muDoubleScalarSign(c1_sig);
      } else {
        c1_i18 = c1_lines->size[1];
        c1_i20 = (int32_T)emlrtIntegerCheckR2012b(c1_b_ang, &c1_c_emlrtDCI,
          &c1_st);
        c1_i22 = emlrtDynamicBoundsCheckR2012b(c1_i20, 1, c1_i18, &c1_c_emlrtBCI,
          &c1_st) - 1;
        c1_p_x = c1_lines->data[c1_i22].point2[0] - 90.0;
        c1_sig = c1_p_x;
        c1_sig = muDoubleScalarSign(c1_sig);
      }

      c1_i24 = c1_lines->size[1];
      c1_i25 = (int32_T)emlrtIntegerCheckR2012b(c1_b_ang, &c1_g_emlrtDCI, &c1_st);
      c1_b_angle = c1_lines->data[emlrtDynamicBoundsCheckR2012b(c1_i25, 1,
        c1_i24, &c1_g_emlrtBCI, &c1_st) - 1].theta;
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 3,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 4U, c1_b_data,
                          0.0, -1, 0U, c1_b_data == 0.0))) {
        c1_b_data1 = 1.0;
        c1_b_angelina = c1_b_angle;
      }
    }

    c1_r = c1_sig;
  } else {
    if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 4,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c1_covrtInstance, 4U, 0U, 5U, c1_b_data,
                        1.0, -1, 0U, c1_b_data == 1.0))) {
      c1_b_data1 = 0.0;
    }
  }

  c1_emxFree_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c1_lines);
  if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 2,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c1_covrtInstance, 4U, 0U, 6U, c1_b_angle,
                        0.0, -1, 2U, c1_b_angle < 0.0)) && covrtEmlCondEval
      (chartInstance->c1_covrtInstance, 4U, 0, 3, covrtRelationalopUpdateFcn
       (chartInstance->c1_covrtInstance, 4U, 0U, 7U, c1_r, 1.0, -1, 0U, c1_r ==
        1.0))) {
    covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 1, true);
    covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 5, true);
    c1_b_angle += 180.0;
  } else {
    covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 1, false);
    covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 5, false);
    if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 4,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 8U,
                          c1_b_angle, 0.0, -1, 4U, c1_b_angle > 0.0)) &&
        covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 5,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 9U, c1_r,
                          -1.0, -1, 0U, c1_r == -1.0))) {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 2, true);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 6, true);
      c1_b_angle -= 180.0;
    } else {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 2, false);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 6, false);
    }
  }

  c1_d_varargin_1 = c1_centers->size[0];
  c1_b_varargin_2 = c1_centers->size[1];
  c1_e_varargin_1 = c1_d_varargin_1;
  c1_c_varargin_2 = c1_b_varargin_2;
  if ((c1_e_varargin_1 == 0) || (c1_c_varargin_2 == 0)) {
    c1_c_n = 0;
  } else if (c1_e_varargin_1 > c1_c_varargin_2) {
    c1_c_n = c1_e_varargin_1;
  } else {
    c1_c_n = c1_c_varargin_2;
  }

  c1_d_n = (real_T)c1_c_n;
  c1_f_varargin_1 = c1_centers->size[0];
  c1_d_varargin_2 = c1_centers->size[1];
  c1_g_varargin_1 = c1_f_varargin_1;
  c1_e_varargin_2 = c1_d_varargin_2;
  c1_emxFree_real_T(chartInstance, &c1_centers);
  if ((c1_g_varargin_1 == 0) || (c1_e_varargin_2 == 0)) {
    c1_e_n = 0;
  } else if (c1_g_varargin_1 > c1_e_varargin_2) {
    c1_e_n = c1_g_varargin_1;
  } else {
    c1_e_n = c1_e_varargin_2;
  }

  c1_f_n = (real_T)c1_e_n;
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 7,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 10U, c1_d_n, 2.0, -1, 0U, c1_f_n == 2.0))) {
    c1_b_mode = 2.0;
  }

  c1_b_output_angle = c1_b_angle;
  *chartInstance->c1_output_angle = c1_b_output_angle;
  *chartInstance->c1_mode = c1_b_mode;
  *chartInstance->c1_data1 = c1_b_data1;
  *chartInstance->c1_angelina = c1_b_angelina;
  c1_do_animation_call_c1_flightControlSystem(chartInstance);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 3U,
                    *chartInstance->c1_output_angle);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 4U, *chartInstance->c1_mode);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 5U,
                    *chartInstance->c1_data1);
  covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 6U,
                    *chartInstance->c1_angelina);
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c1_b_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c1_c_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c1_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c1_b_condTxtEndIdx[2] = { 1032, 1042 };

  static const int32_T c1_b_condTxtStartIdx[2] = { 1023, 1036 };

  static const int32_T c1_c_condTxtEndIdx[2] = { 1084, 1095 };

  static const int32_T c1_c_condTxtStartIdx[2] = { 1075, 1088 };

  static const int32_T c1_condTxtEndIdx[2] = { 526, 559 };

  static const int32_T c1_condTxtStartIdx[2] = { 499, 532 };

  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    67U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 8U, 0U,
                  0U, 0U, 1U, 0U, 6U, 3U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 1193);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 415, 436, 967,
                    1019);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 495, 560, 950,
                    953);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 573, 635, 701,
                    774);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 825, 837, -1,
                    914);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 976, 988, -1,
                    1015);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 1020, 1042,
                    1068, 1095);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 1068, 1095, -1,
                    1095);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 7U, 1125, 1148, -1,
                    1170);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 473, 487, 953);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 498, 560, 2U,
                      0U, c1_condTxtStartIdx, c1_condTxtEndIdx, 3U,
                      c1_postfixPredicateTree);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 1023, 1042,
                      2U, 2U, c1_b_condTxtStartIdx, c1_b_condTxtEndIdx, 3U,
                      c1_b_postfixPredicateTree);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 1075, 1095,
                      2U, 4U, c1_c_condTxtStartIdx, c1_c_condTxtEndIdx, 3U,
                      c1_c_postfixPredicateTree);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 418,
    436, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 499,
    526, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 532,
    559, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 576,
    635, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 828,
    837, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 979,
    988, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 1023,
    1032, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 7U, 1036,
    1042, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 8U, 1075,
    1084, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 9U, 1088,
    1095, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 10U, 1128,
    1148, -1, 0U);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void initSimStructsc1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_imhist(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, uint8_T c1_d_varargin_1[19200],
                      real_T c1_yout[256])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_localBins1[256];
  real_T c1_localBins2[256];
  real_T c1_localBins3[256];
  real_T c1_b_out;
  real_T c1_d_i;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_b_idx;
  int32_T c1_c;
  int32_T c1_c_c;
  int32_T c1_c_i;
  int32_T c1_d_c;
  int32_T c1_e_c;
  int32_T c1_f_c;
  int32_T c1_g_a;
  int32_T c1_g_c;
  int32_T c1_h_a;
  int32_T c1_h_c;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i_a;
  int32_T c1_i_c;
  int32_T c1_idx1;
  int32_T c1_idx2;
  int32_T c1_idx3;
  int32_T c1_idx4;
  int32_T c1_j_a;
  int32_T c1_j_c;
  int32_T c1_k_a;
  int32_T c1_l_a;
  int32_T c1_m_a;
  int32_T c1_n_a;
  int32_T c1_o_a;
  int32_T c1_p_a;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_m_emlrtRSI;
  c1_b_st.site = &c1_o_emlrtRSI;
  c1_b_out = 1.0;
  getnumcores(&c1_b_out);
  c1_b_st.site = &c1_n_emlrtRSI;
  for (c1_i = 0; c1_i < 256; c1_i++) {
    c1_yout[c1_i] = 0.0;
  }

  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    c1_localBins1[c1_i1] = 0.0;
  }

  for (c1_i2 = 0; c1_i2 < 256; c1_i2++) {
    c1_localBins2[c1_i2] = 0.0;
  }

  for (c1_i3 = 0; c1_i3 < 256; c1_i3++) {
    c1_localBins3[c1_i3] = 0.0;
  }

  for (c1_b_i = 4; c1_b_i <= 19200; c1_b_i += 4) {
    c1_i4 = c1_b_i - 3;
    c1_idx1 = c1_d_varargin_1[emlrtDynamicBoundsCheckR2012b(c1_i4, 1, 19200,
      &c1_h_emlrtBCI, &c1_b_st) - 1];
    c1_i5 = c1_b_i - 2;
    c1_idx2 = c1_d_varargin_1[emlrtDynamicBoundsCheckR2012b(c1_i5, 1, 19200,
      &c1_i_emlrtBCI, &c1_b_st) - 1];
    c1_i6 = c1_b_i - 1;
    c1_idx3 = c1_d_varargin_1[emlrtDynamicBoundsCheckR2012b(c1_i6, 1, 19200,
      &c1_j_emlrtBCI, &c1_b_st) - 1];
    c1_idx4 = c1_d_varargin_1[emlrtDynamicBoundsCheckR2012b(c1_b_i, 1, 19200,
      &c1_k_emlrtBCI, &c1_b_st) - 1];
    c1_i_a = c1_idx1 + 1;
    c1_c_c = c1_i_a - 1;
    c1_j_a = c1_idx1 + 1;
    c1_d_c = c1_j_a - 1;
    c1_localBins1[c1_c_c] = c1_localBins1[c1_d_c] + 1.0;
    c1_k_a = c1_idx2 + 1;
    c1_e_c = c1_k_a - 1;
    c1_l_a = c1_idx2 + 1;
    c1_f_c = c1_l_a - 1;
    c1_localBins2[c1_e_c] = c1_localBins2[c1_f_c] + 1.0;
    c1_m_a = c1_idx3 + 1;
    c1_g_c = c1_m_a - 1;
    c1_n_a = c1_idx3 + 1;
    c1_h_c = c1_n_a - 1;
    c1_localBins3[c1_g_c] = c1_localBins3[c1_h_c] + 1.0;
    c1_o_a = c1_idx4 + 1;
    c1_i_c = c1_o_a - 1;
    c1_p_a = c1_idx4 + 1;
    c1_j_c = c1_p_a - 1;
    c1_yout[c1_i_c] = c1_yout[c1_j_c] + 1.0;
  }

  while (c1_b_i - 3 <= 19200) {
    c1_b_idx = c1_d_varargin_1[c1_b_i - 4];
    c1_g_a = c1_b_idx + 1;
    c1_c = c1_g_a - 1;
    c1_h_a = c1_b_idx + 1;
    c1_b_c = c1_h_a - 1;
    c1_yout[c1_c] = c1_yout[c1_b_c] + 1.0;
    c1_b_i++;
  }

  for (c1_c_i = 0; c1_c_i < 256; c1_c_i++) {
    c1_d_i = (real_T)c1_c_i + 1.0;
    c1_yout[(int32_T)c1_d_i - 1] = ((c1_yout[(int32_T)c1_d_i - 1] +
      c1_localBins1[(int32_T)c1_d_i - 1]) + c1_localBins2[(int32_T)c1_d_i - 1])
      + c1_localBins3[(int32_T)c1_d_i - 1];
  }
}

static real_T c1_otsuthresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_counts[256])
{
  static char_T c1_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 't', 's',
    'u', 't', 'h', 'r', 'e', 's', 'h', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c1_b_cv1[6] = { 'C', 'O', 'U', 'N', 'T', 'S' };

  emlrtStack c1_b_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_mu[256];
  real_T c1_omega[256];
  real_T c1_sigma_b_squared[256];
  real_T c1_b_idx;
  real_T c1_b_k;
  real_T c1_b_p;
  real_T c1_b_varargin_2;
  real_T c1_c;
  real_T c1_c_x;
  real_T c1_d_k;
  real_T c1_d_varargin_1;
  real_T c1_d_x;
  real_T c1_d_y;
  real_T c1_e_x;
  real_T c1_e_y;
  real_T c1_f_x;
  real_T c1_f_y;
  real_T c1_g_a;
  real_T c1_g_x;
  real_T c1_g_y;
  real_T c1_h_a;
  real_T c1_h_x;
  real_T c1_h_y;
  real_T c1_i_a;
  real_T c1_i_x;
  real_T c1_i_y;
  real_T c1_j_a;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_maxval;
  real_T c1_mu_t;
  real_T c1_n_x;
  real_T c1_num_elems;
  real_T c1_num_maxval;
  real_T c1_o_x;
  real_T c1_t;
  int32_T c1_c_k;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_g_k;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b_b;
  boolean_T c1_c_b;
  boolean_T c1_d_b;
  boolean_T c1_e_b;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_isfinite_maxval;
  boolean_T c1_p;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_q_emlrtRSI;
  c1_b_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 256)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_c_x = c1_counts[(int32_T)c1_b_k - 1];
    c1_d_x = c1_c_x;
    c1_b_b = muDoubleScalarIsInf(c1_d_x);
    c1_b1 = !c1_b_b;
    c1_e_x = c1_c_x;
    c1_c_b = muDoubleScalarIsNaN(c1_e_x);
    c1_b2 = !c1_c_b;
    c1_d_b = (c1_b1 && c1_b2);
    if (c1_d_b) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c1_b_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_b_st, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  c1_b_st.site = &c1_s_emlrtRSI;
  c1_num_elems = 0.0;
  for (c1_c_k = 0; c1_c_k < 256; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_num_elems += c1_counts[(int32_T)c1_d_k - 1];
  }

  c1_omega[0] = c1_counts[0] / c1_num_elems;
  c1_mu[0] = c1_omega[0];
  for (c1_e_k = 0; c1_e_k < 255; c1_e_k++) {
    c1_d_k = (real_T)c1_e_k + 2.0;
    c1_b_p = c1_counts[(int32_T)c1_d_k - 1] / c1_num_elems;
    c1_omega[(int32_T)c1_d_k - 1] = c1_omega[(int32_T)(c1_d_k - 1.0) - 1] +
      c1_b_p;
    c1_mu[(int32_T)c1_d_k - 1] = c1_mu[(int32_T)(c1_d_k - 1.0) - 1] + c1_b_p *
      c1_d_k;
  }

  c1_mu_t = c1_mu[255];
  c1_maxval = rtMinusInf;
  for (c1_f_k = 0; c1_f_k < 256; c1_f_k++) {
    c1_d_k = (real_T)c1_f_k + 1.0;
    c1_st.site = &c1_r_emlrtRSI;
    c1_g_a = c1_mu_t * c1_omega[(int32_T)c1_d_k - 1] - c1_mu[(int32_T)c1_d_k - 1];
    c1_b_st.site = &c1_t_emlrtRSI;
    c1_h_a = c1_g_a;
    c1_i_a = c1_h_a;
    c1_i_x = c1_i_a;
    c1_j_a = c1_i_x;
    c1_c = c1_j_a * c1_j_a;
    c1_sigma_b_squared[(int32_T)c1_d_k - 1] = c1_c / (c1_omega[(int32_T)c1_d_k -
      1] * (1.0 - c1_omega[(int32_T)c1_d_k - 1]));
    c1_d_varargin_1 = c1_maxval;
    c1_b_varargin_2 = c1_sigma_b_squared[(int32_T)c1_d_k - 1];
    c1_j_x = c1_d_varargin_1;
    c1_d_y = c1_b_varargin_2;
    c1_k_x = c1_j_x;
    c1_e_y = c1_d_y;
    c1_l_x = c1_k_x;
    c1_f_y = c1_e_y;
    c1_m_x = c1_l_x;
    c1_g_y = c1_f_y;
    c1_n_x = c1_m_x;
    c1_h_y = c1_g_y;
    c1_o_x = c1_n_x;
    c1_i_y = c1_h_y;
    c1_maxval = muDoubleScalarMax(c1_o_x, c1_i_y);
  }

  c1_f_x = c1_maxval;
  c1_g_x = c1_f_x;
  c1_e_b = muDoubleScalarIsInf(c1_g_x);
  c1_b3 = !c1_e_b;
  c1_h_x = c1_f_x;
  c1_f_b = muDoubleScalarIsNaN(c1_h_x);
  c1_b4 = !c1_f_b;
  c1_isfinite_maxval = (c1_b3 && c1_b4);
  if (c1_isfinite_maxval) {
    c1_b_idx = 0.0;
    c1_num_maxval = 0.0;
    for (c1_g_k = 0; c1_g_k < 256; c1_g_k++) {
      c1_d_k = (real_T)c1_g_k + 1.0;
      c1_b_idx += c1_d_k * (real_T)(c1_sigma_b_squared[(int32_T)c1_d_k - 1] ==
        c1_maxval);
      c1_num_maxval += (real_T)(c1_sigma_b_squared[(int32_T)c1_d_k - 1] ==
        c1_maxval);
    }

    c1_b_idx /= c1_num_maxval;
    c1_t = (c1_b_idx - 1.0) / 255.0;
  } else {
    c1_t = 0.0;
  }

  return c1_t;
}

static void c1_edge(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200],
                    boolean_T c1_varargout_1[19200])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_counts[64];
  real_T c1_b_data[1];
  real_T c1_b_highThresh_data[1];
  real_T c1_b_lowThresh_data[1];
  real_T c1_highThresh_data[1];
  real_T c1_lowThresh_data[1];
  real_T c1_c_idx;
  real_T c1_c_sum;
  real_T c1_highThreshTemp;
  int32_T c1_b_highThresh_size[1];
  int32_T c1_b_lowThresh_size[1];
  int32_T c1_highThresh_size[1];
  int32_T c1_lowThresh_size[1];
  int32_T c1_b_idx;
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_loop_ub;
  real32_T c1_b;
  real32_T c1_b_b;
  real32_T c1_b_r;
  real32_T c1_b_varargin_2;
  real32_T c1_b_x1;
  real32_T c1_b_x2;
  real32_T c1_b_y;
  real32_T c1_c_x;
  real32_T c1_c_y;
  real32_T c1_d_x;
  real32_T c1_d_y;
  real32_T c1_e_varargin_1;
  real32_T c1_e_x;
  real32_T c1_e_y;
  real32_T c1_f_x;
  real32_T c1_f_y;
  real32_T c1_g_a;
  real32_T c1_g_x;
  real32_T c1_g_y;
  real32_T c1_h_a;
  real32_T c1_h_x;
  real32_T c1_h_y;
  real32_T c1_i_x;
  real32_T c1_i_y;
  real32_T c1_j_x;
  real32_T c1_j_y;
  real32_T c1_k_x;
  real32_T c1_k_y;
  real32_T c1_l_x;
  real32_T c1_l_y;
  real32_T c1_m_x;
  real32_T c1_m_y;
  real32_T c1_magmax;
  real32_T c1_n_x;
  real32_T c1_n_y;
  real32_T c1_r;
  real32_T c1_x1;
  real32_T c1_x2;
  real32_T c1_y;
  int8_T c1_d_idx;
  boolean_T c1_b_bv[19200];
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    chartInstance->c1_c_a[c1_i] = (real32_T)c1_d_varargin_1[c1_i];
  }

  c1_st.site = &c1_v_emlrtRSI;
  c1_b_st.site = &c1_y_emlrtRSI;
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    chartInstance->c1_d_a[c1_i1] = chartInstance->c1_c_a[c1_i1];
  }

  c1_imfilter(chartInstance, &c1_b_st, chartInstance->c1_d_a,
              chartInstance->c1_dx);
  c1_b_st.site = &c1_ab_emlrtRSI;
  for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
    chartInstance->c1_b_dx[c1_i2] = chartInstance->c1_dx[c1_i2];
  }

  c1_b_imfilter(chartInstance, &c1_b_st, chartInstance->c1_b_dx,
                chartInstance->c1_dx);
  c1_b_st.site = &c1_bb_emlrtRSI;
  c1_c_imfilter(chartInstance, &c1_b_st, chartInstance->c1_c_a,
                chartInstance->c1_dy);
  c1_b_st.site = &c1_cb_emlrtRSI;
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    chartInstance->c1_b_dy[c1_i3] = chartInstance->c1_dy[c1_i3];
  }

  c1_d_imfilter(chartInstance, &c1_b_st, chartInstance->c1_b_dy,
                chartInstance->c1_dy);
  c1_c_x = chartInstance->c1_dx[0];
  c1_y = chartInstance->c1_dy[0];
  c1_d_x = c1_c_x;
  c1_b_y = c1_y;
  c1_e_x = c1_d_x;
  c1_c_y = c1_b_y;
  c1_x1 = c1_e_x;
  c1_x2 = c1_c_y;
  c1_g_a = c1_x1;
  c1_b = c1_x2;
  c1_r = muSingleScalarHypot(c1_g_a, c1_b);
  chartInstance->c1_c_a[0] = c1_r;
  c1_magmax = chartInstance->c1_c_a[0];
  for (c1_b_idx = 0; c1_b_idx < 19199; c1_b_idx++) {
    c1_c_idx = (real_T)c1_b_idx + 2.0;
    c1_f_x = chartInstance->c1_dx[(int32_T)c1_c_idx - 1];
    c1_f_y = chartInstance->c1_dy[(int32_T)c1_c_idx - 1];
    c1_g_x = c1_f_x;
    c1_g_y = c1_f_y;
    c1_h_x = c1_g_x;
    c1_h_y = c1_g_y;
    c1_b_x1 = c1_h_x;
    c1_b_x2 = c1_h_y;
    c1_h_a = c1_b_x1;
    c1_b_b = c1_b_x2;
    c1_b_r = muSingleScalarHypot(c1_h_a, c1_b_b);
    chartInstance->c1_c_a[(int32_T)c1_c_idx - 1] = c1_b_r;
    c1_e_varargin_1 = chartInstance->c1_c_a[(int32_T)c1_c_idx - 1];
    c1_b_varargin_2 = c1_magmax;
    c1_i_x = c1_e_varargin_1;
    c1_i_y = c1_b_varargin_2;
    c1_j_x = c1_i_x;
    c1_j_y = c1_i_y;
    c1_k_x = c1_j_x;
    c1_k_y = c1_j_y;
    c1_l_x = c1_k_x;
    c1_l_y = c1_k_y;
    c1_m_x = c1_l_x;
    c1_m_y = c1_l_y;
    c1_n_x = c1_m_x;
    c1_n_y = c1_m_y;
    c1_magmax = muSingleScalarMax(c1_n_x, c1_n_y);
  }

  if (c1_magmax > 0.0F) {
    c1_d_y = c1_magmax;
    c1_e_y = c1_d_y;
    for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
      chartInstance->c1_c_a[c1_i4] /= c1_e_y;
    }
  }

  c1_st.site = &c1_w_emlrtRSI;
  c1_b_st.site = &c1_qb_emlrtRSI;
  for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
    chartInstance->c1_f_a[c1_i5] = chartInstance->c1_c_a[c1_i5];
  }

  c1_b_imhist(chartInstance, &c1_b_st, chartInstance->c1_f_a, c1_counts);
  c1_c_sum = 0.0;
  c1_d_idx = 1;
  while ((!(c1_c_sum > 13440.0)) && ((real_T)c1_d_idx <= 64.0)) {
    c1_c_sum += c1_counts[c1_d_idx - 1];
    c1_i7 = c1_d_idx + 1;
    if (c1_i7 > 127) {
      c1_i7 = 127;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    } else {
      if (c1_i7 < -128) {
        c1_i7 = -128;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }
    }

    c1_d_idx = (int8_T)c1_i7;
  }

  c1_i6 = c1_d_idx - 1;
  if (c1_i6 > 127) {
    c1_i6 = 127;
    sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
  } else {
    if (c1_i6 < -128) {
      c1_i6 = -128;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    }
  }

  c1_highThreshTemp = (real_T)(int8_T)c1_i6 / 64.0;
  if (((real_T)c1_d_idx > 64.0) && (!(c1_c_sum > 13440.0))) {
    c1_highThresh_size[0] = 0;
    c1_lowThresh_size[0] = 0;
  } else {
    c1_highThresh_size[0] = 1;
    c1_highThresh_data[0] = c1_highThreshTemp;
    c1_loop_ub = c1_highThresh_size[0] - 1;
    for (c1_i8 = 0; c1_i8 <= c1_loop_ub; c1_i8++) {
      c1_b_data[c1_i8] = c1_highThresh_data[c1_i8];
    }

    c1_b_data[0] *= 0.4;
    c1_lowThresh_size[0] = 1;
    c1_lowThresh_data[0] = c1_b_data[0];
  }

  for (c1_i9 = 0; c1_i9 < 19200; c1_i9++) {
    c1_b_bv[c1_i9] = false;
  }

  c1_b_lowThresh_size[0] = c1_lowThresh_size[0];
  c1_b_loop_ub = c1_lowThresh_size[0] - 1;
  for (c1_i10 = 0; c1_i10 <= c1_b_loop_ub; c1_i10++) {
    c1_b_lowThresh_data[c1_i10] = c1_lowThresh_data[c1_i10];
  }

  c1_b_highThresh_size[0] = c1_highThresh_size[0];
  c1_c_loop_ub = c1_highThresh_size[0] - 1;
  for (c1_i11 = 0; c1_i11 <= c1_c_loop_ub; c1_i11++) {
    c1_b_highThresh_data[c1_i11] = c1_highThresh_data[c1_i11];
  }

  c1_st.site = &c1_x_emlrtRSI;
  c1_thinAndThreshold(chartInstance, &c1_st, c1_b_bv, chartInstance->c1_dx,
                      chartInstance->c1_dy, chartInstance->c1_c_a,
                      c1_b_lowThresh_data, c1_b_lowThresh_size,
                      c1_b_highThresh_data, c1_b_highThresh_size, c1_varargout_1);
  c1_i12 = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i12, 1, c1_lowThresh_size[0], &c1_l_emlrtBCI,
    c1_sp);
  c1_i13 = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i13, 1, c1_highThresh_size[0], &c1_m_emlrtBCI,
    c1_sp);
}

static void c1_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200])
{
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real32_T c1_e_varargin_1[19200];
  boolean_T c1_conn[13];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_e_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_padImage(chartInstance, &c1_st, c1_e_varargin_1, chartInstance->c1_b_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 132.0 + 28.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 13.0 + -12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&chartInstance->c1_b_a[0], &c1_b[0], &c1_outSizeT[0], 2.0,
                     &c1_padSizeT[0], &c1_dv[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 13; c1_i1++) {
      c1_conn[c1_i1] = true;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_padSizeT[c1_i3] = 132.0 + 28.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_outSizeT[c1_i5] = 120.0 + 40.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_connDimsT[c1_i7] = 13.0 + -12.0 * (real_T)c1_i7;
    }

    for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
      c1_startT[c1_i8] = 6.0 + -6.0 * (real_T)c1_i8;
    }

    imfilter_real32(&chartInstance->c1_b_a[0], &c1_b[0], 2.0, &c1_outSizeT[0],
                    2.0, &c1_padSizeT[0], &c1_dv[0], 13.0, &c1_conn[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[19200], real32_T c1_g_a[21120])
{
  static int32_T c1_idxA[320] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
    119, 120, 120, 120, 120, 120, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
    119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133,
    134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148,
    149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160 };

  emlrtStack c1_st;
  real_T c1_b_i;
  real_T c1_b_j;
  int32_T c1_c_i;
  int32_T c1_i;
  int32_T c1_j;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 132; c1_i++) {
      c1_b_i = (real_T)c1_i + 1.0;
      c1_c_i = c1_idxA[(int32_T)c1_b_j + 159];
      c1_g_a[((int32_T)c1_b_i + 132 * ((int32_T)c1_b_j - 1)) - 1] = c1_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_b_i - 1], 1, 120,
           &c1_n_emlrtBCI, &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c1_c_i,
            1, 160, &c1_o_emlrtBCI, &c1_st) - 1)) - 1];
    }
  }
}

static void c1_check_forloop_overflow_error
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp)
{
  static char_T c1_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c1_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c1_sp, &c1_e_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14, sf_mex_call
              (c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c1_sp, NULL,
    "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
}

static void c1_b_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200])
{
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real32_T c1_g_a[20640];
  real32_T c1_e_varargin_1[19200];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_e_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_b_padImage(chartInstance, &c1_st, c1_e_varargin_1, c1_g_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 120.0 + 52.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 1.0 + 12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&c1_g_a[0], &c1_b[0], &c1_outSizeT[0], 2.0, &c1_padSizeT[0],
                     &c1_dv1[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 120.0 + 52.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 1.0 + 12.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 6.0 * (real_T)c1_i7;
    }

    imfilter_real32(&c1_g_a[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_dv2[0], 12.0, &c1_bv[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_b_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[19200], real32_T c1_g_a[20640])
{
  static int32_T c1_idxA[344] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
    108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
    59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
    78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
    113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142,
    143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157,
    158, 159, 160, 160, 160, 160, 160, 160, 160 };

  emlrtStack c1_st;
  real_T c1_b_i;
  real_T c1_b_j;
  int32_T c1_c_i;
  int32_T c1_i;
  int32_T c1_j;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 172; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 120; c1_i++) {
      c1_b_i = (real_T)c1_i + 1.0;
      c1_c_i = c1_idxA[(int32_T)c1_b_j + 171];
      c1_g_a[((int32_T)c1_b_i + 120 * ((int32_T)c1_b_j - 1)) - 1] = c1_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_b_i - 1], 1, 120,
           &c1_n_emlrtBCI, &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c1_c_i,
            1, 160, &c1_o_emlrtBCI, &c1_st) - 1)) - 1];
    }
  }
}

static void c1_c_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200])
{
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real32_T c1_g_a[20640];
  real32_T c1_e_varargin_1[19200];
  boolean_T c1_conn[13];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_e_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_b_padImage(chartInstance, &c1_st, c1_e_varargin_1, c1_g_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 120.0 + 52.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 1.0 + 12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&c1_g_a[0], &c1_b[0], &c1_outSizeT[0], 2.0, &c1_padSizeT[0],
                     &c1_dv[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 13; c1_i1++) {
      c1_conn[c1_i1] = true;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_padSizeT[c1_i3] = 120.0 + 52.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_outSizeT[c1_i5] = 120.0 + 40.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_connDimsT[c1_i7] = 1.0 + 12.0 * (real_T)c1_i7;
    }

    for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
      c1_startT[c1_i8] = 6.0 * (real_T)c1_i8;
    }

    imfilter_real32(&c1_g_a[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_dv[0], 13.0, &c1_conn[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_d_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200])
{
  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real32_T c1_e_varargin_1[19200];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_e_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_padImage(chartInstance, &c1_st, c1_e_varargin_1, chartInstance->c1_e_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 132.0 + 28.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 13.0 + -12.0 * (real_T)c1_i6;
    }

    ippfilter_real32(&chartInstance->c1_e_a[0], &c1_b[0], &c1_outSizeT[0], 2.0,
                     &c1_padSizeT[0], &c1_dv1[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 132.0 + 28.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 13.0 + -12.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 6.0 + -6.0 * (real_T)c1_i7;
    }

    imfilter_real32(&chartInstance->c1_e_a[0], &c1_b[0], 2.0, &c1_outSizeT[0],
                    2.0, &c1_padSizeT[0], &c1_dv2[0], 12.0, &c1_bv[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_b_imhist(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real_T c1_yout[64])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_b_out;
  real_T c1_c_i;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_c;
  int32_T c1_i;
  real32_T c1_b_idx;
  real32_T c1_c_x;
  real32_T c1_d_x;
  real32_T c1_g_a;
  real32_T c1_h_a;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_nanFlag;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_m_emlrtRSI;
  c1_b_st.site = &c1_o_emlrtRSI;
  c1_b_out = 1.0;
  getnumcores(&c1_b_out);
  for (c1_i = 0; c1_i < 64; c1_i++) {
    c1_yout[c1_i] = 0.0;
  }

  c1_nanFlag = false;
  for (c1_b_i = 0; c1_b_i < 19200; c1_b_i++) {
    c1_c_i = (real_T)c1_b_i + 1.0;
    c1_c_x = c1_d_varargin_1[(int32_T)c1_c_i - 1];
    c1_b = muSingleScalarIsNaN(c1_c_x);
    if (c1_b) {
      c1_nanFlag = true;
      c1_b_idx = 0.0F;
    } else {
      c1_b_idx = c1_d_varargin_1[(int32_T)c1_c_i - 1] * 63.0F + 0.5F;
    }

    if (c1_b_idx > 63.0F) {
      c1_yout[63]++;
    } else {
      c1_d_x = c1_d_varargin_1[(int32_T)c1_c_i - 1];
      c1_b_b = muSingleScalarIsInf(c1_d_x);
      if (c1_b_b) {
        c1_yout[63]++;
      } else {
        c1_g_a = c1_b_idx;
        c1_c = (int32_T)c1_g_a;
        c1_h_a = c1_b_idx;
        c1_b_c = (int32_T)c1_h_a;
        c1_yout[c1_c] = c1_yout[c1_b_c] + 1.0;
      }
    }
  }

  if (c1_nanFlag) {
    c1_b_st.site = &c1_rb_emlrtRSI;
    c1_warning(chartInstance, &c1_b_st);
  }
}

static void c1_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp)
{
  static char_T c1_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  static char_T c1_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c1_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  c1_st.site = &c1_p_emlrtRSI;
  c1_b_feval(chartInstance, &c1_st, c1_y, c1_feval(chartInstance, &c1_st, c1_b_y,
              c1_c_y));
}

static void c1_thinAndThreshold(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, boolean_T c1_E[19200], real32_T
  c1_c_dx[19200], real32_T c1_c_dy[19200], real32_T c1_magGrad[19200], real_T
  c1_lowThresh_data[], int32_T c1_lowThresh_size[1], real_T c1_highThresh_data[],
  int32_T c1_highThresh_size[1], boolean_T c1_b_H[19200])
{
  real_T c1_szT[2];
  real_T c1_b_lowThresh;
  real_T c1_highThresh;
  real_T c1_lowThresh;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  boolean_T c1_b_E[19200];
  boolean_T c1_marker[19200];
  c1_i = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i, 1, c1_lowThresh_size[0], &c1_q_emlrtBCI,
    c1_sp);
  c1_lowThresh = c1_lowThresh_data[0];
  c1_b_lowThresh = c1_lowThresh;
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_szT[c1_i1] = 120.0 + 40.0 * (real_T)c1_i1;
  }

  cannythresholding_real32_tbb(&c1_c_dx[0], &c1_c_dy[0], &c1_magGrad[0],
    &c1_szT[0], c1_b_lowThresh, &c1_E[0]);
  c1_i2 = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i2, 1, c1_highThresh_size[0], &c1_p_emlrtBCI,
    c1_sp);
  c1_highThresh = c1_highThresh_data[0];
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    c1_marker[c1_i3] = ((real_T)c1_magGrad[c1_i3] > c1_highThresh);
  }

  for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
    c1_b_E[c1_i4] = c1_E[c1_i4];
  }

  c1_imreconstruct(chartInstance, c1_marker, c1_b_E, c1_b_H);
}

static void c1_imreconstruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c1_marker[19200], boolean_T c1_mask[19200],
  boolean_T c1_im[19200])
{
  real_T c1_imSizeT[2];
  int32_T c1_i;
  int32_T c1_i1;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_im[c1_i] = c1_marker[c1_i];
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_imSizeT[c1_i1] = 120.0 + 40.0 * (real_T)c1_i1;
  }

  ippreconstruct_uint8((uint8_T *)&c1_im[0], (uint8_T *)&c1_mask[0],
                       &c1_imSizeT[0], 2.0);
}

static void c1_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_bw[19200])
{
  real_T c1_b_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_k;
  boolean_T c1_last_aout[19200];
  boolean_T c1_b_p;
  boolean_T c1_c_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  boolean_T c1_x1;
  boolean_T c1_x2;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_bw[c1_i] = c1_bwin[c1_i];
  }

  do {
    for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
      c1_last_aout[c1_i1] = c1_bw[c1_i1];
    }

    c1_b_bwmorphApplyOnce(chartInstance, c1_bw);
    c1_p = false;
    c1_b_p = true;
    c1_k = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 19200)) {
      c1_b_k = (real_T)c1_k + 1.0;
      c1_x1 = c1_last_aout[(int32_T)c1_b_k - 1];
      c1_x2 = c1_bw[(int32_T)c1_b_k - 1];
      c1_c_p = ((int32_T)c1_x1 == (int32_T)c1_x2);
      if (!c1_c_p) {
        c1_b_p = false;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }

    if (c1_b_p) {
      c1_p = true;
    }
  } while (!c1_p);
}

static void c1_bwmorphApplyOnce(SFc1_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c1_bw[19200], boolean_T c1_b_bw[19200])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_b_bw[c1_i] = c1_bw[c1_i];
  }

  c1_b_bwmorphApplyOnce(chartInstance, c1_b_bw);
}

static void c1_bwlookup(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_B[19200])
{
  static boolean_T c1_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, false,
    false, true, true, false, false, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, false, false, false, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, false, false, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, false, false, false, true, false, false, true, true, false, false,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, true, false, false, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true };

  real_T c1_sizeIn[2];
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_sizeIn[c1_i] = 120.0 + 40.0 * (real_T)c1_i;
  }

  bwlookup_tbb_boolean(&c1_bwin[0], &c1_sizeIn[0], 2.0, &c1_lut[0], 512.0,
                       &c1_B[0]);
}

static void c1_b_bwlookup(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_B[19200])
{
  static boolean_T c1_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, false, true, true, true, false, false, true, true, false, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, false, false, true, false, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, true, true, true, false,
    false, true, true, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, false, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, false, false,
    true, false, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, true, true, true, false, false, true, true,
    false, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, false, true, false, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, false, false, true, true, false, true, true, true };

  real_T c1_sizeIn[2];
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_sizeIn[c1_i] = 120.0 + 40.0 * (real_T)c1_i;
  }

  bwlookup_tbb_boolean(&c1_bwin[0], &c1_sizeIn[0], 2.0, &c1_lut[0], 512.0,
                       &c1_B[0]);
}

static void c1_e_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200])
{
  static real_T c1_kernel[25] = { 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822,
    0.028084023356349175, 0.054700208300935887, 0.068312293270780214,
    0.054700208300935887, 0.028084023356349175, 0.0350727008055935,
    0.068312293270780214, 0.085311730190125085, 0.068312293270780214,
    0.0350727008055935, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.0350727008055935,
    0.028084023356349175, 0.014418818362460822 };

  static real_T c1_nonZeroKernel[25] = { 0.014418818362460822,
    0.028084023356349175, 0.0350727008055935, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.0350727008055935, 0.068312293270780214, 0.085311730190125085,
    0.068312293270780214, 0.0350727008055935, 0.028084023356349175,
    0.054700208300935887, 0.068312293270780214, 0.054700208300935887,
    0.028084023356349175, 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822 };

  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real32_T c1_g_a[20336];
  real32_T c1_e_varargin_1[19200];
  boolean_T c1_conn[25];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_e_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_c_padImage(chartInstance, &c1_st, c1_e_varargin_1, c1_g_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 124.0 + 40.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 5.0;
    }

    ippfilter_real32(&c1_g_a[0], &c1_b[0], &c1_outSizeT[0], 2.0, &c1_padSizeT[0],
                     &c1_kernel[0], &c1_connDimsT[0], false);
  } else {
    for (c1_i1 = 0; c1_i1 < 25; c1_i1++) {
      c1_conn[c1_i1] = true;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_padSizeT[c1_i3] = 124.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_outSizeT[c1_i5] = 120.0 + 40.0 * (real_T)c1_i5;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_connDimsT[c1_i7] = 5.0;
    }

    for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
      c1_startT[c1_i8] = 2.0;
    }

    imfilter_real32(&c1_g_a[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_nonZeroKernel[0], 25.0, &c1_conn[0],
                    2.0, &c1_connDimsT[0], &c1_startT[0], 2.0, true, false);
  }
}

static void c1_c_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[19200], real32_T c1_g_a[20336])
{
  static int32_T c1_idxA[328] = { 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
    117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
    132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
    147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160,
    160 };

  emlrtStack c1_st;
  real_T c1_b_i;
  real_T c1_b_j;
  int32_T c1_c_i;
  int32_T c1_i;
  int32_T c1_j;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 164; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 124; c1_i++) {
      c1_b_i = (real_T)c1_i + 1.0;
      c1_c_i = c1_idxA[(int32_T)c1_b_j + 163];
      c1_g_a[((int32_T)c1_b_i + 124 * ((int32_T)c1_b_j - 1)) - 1] = c1_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_b_i - 1], 1, 120,
           &c1_n_emlrtBCI, &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c1_c_i,
            1, 160, &c1_o_emlrtBCI, &c1_st) - 1)) - 1];
    }
  }
}

static void c1_f_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200])
{
  static real_T c1_kernel[9] = { -1.0, -2.0, -1.0, -0.0, -0.0, -0.0, 1.0, 2.0,
    1.0 };

  static real_T c1_nonZeroKernel[6] = { -1.0, -2.0, -1.0, 1.0, 2.0, 1.0 };

  static boolean_T c1_conn[9] = { true, true, true, false, false, false, true,
    true, true };

  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real32_T c1_g_a[19764];
  real32_T c1_e_varargin_1[19200];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_e_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_d_padImage(chartInstance, &c1_st, c1_e_varargin_1, c1_g_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 122.0 + 40.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 3.0;
    }

    ippfilter_real32(&c1_g_a[0], &c1_b[0], &c1_outSizeT[0], 2.0, &c1_padSizeT[0],
                     &c1_kernel[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 122.0 + 40.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 3.0;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 1.0;
    }

    imfilter_real32(&c1_g_a[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_nonZeroKernel[0], 6.0, &c1_conn[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_d_padImage(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_a_tmp[19200], real32_T c1_g_a[19764])
{
  static int32_T c1_idxA[324] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
    88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135,
    136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150,
    151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160 };

  emlrtStack c1_st;
  real_T c1_b_i;
  real_T c1_b_j;
  int32_T c1_c_i;
  int32_T c1_i;
  int32_T c1_j;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_fb_emlrtRSI;
  for (c1_j = 0; c1_j < 162; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 122; c1_i++) {
      c1_b_i = (real_T)c1_i + 1.0;
      c1_c_i = c1_idxA[(int32_T)c1_b_j + 161];
      c1_g_a[((int32_T)c1_b_i + 122 * ((int32_T)c1_b_j - 1)) - 1] = c1_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c1_idxA[(int32_T)c1_b_i - 1], 1, 120,
           &c1_n_emlrtBCI, &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c1_c_i,
            1, 160, &c1_o_emlrtBCI, &c1_st) - 1)) - 1];
    }
  }
}

static void c1_g_imfilter(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200], real32_T c1_b[19200])
{
  static real_T c1_kernel[9] = { -1.0, -0.0, 1.0, -2.0, -0.0, 2.0, -1.0, -0.0,
    1.0 };

  static real_T c1_nonZeroKernel[6] = { -1.0, 1.0, -2.0, 2.0, -1.0, 1.0 };

  static boolean_T c1_conn[9] = { true, false, true, true, false, true, true,
    false, true };

  emlrtStack c1_st;
  real_T c1_connDimsT[2];
  real_T c1_outSizeT[2];
  real_T c1_padSizeT[2];
  real_T c1_startT[2];
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real32_T c1_g_a[19764];
  real32_T c1_e_varargin_1[19200];
  boolean_T c1_b_modeFlag;
  boolean_T c1_c_modeFlag;
  boolean_T c1_modeFlag;
  boolean_T c1_tooBig;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_db_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_e_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_d_padImage(chartInstance, &c1_st, c1_e_varargin_1, c1_g_a);
  c1_tooBig = true;
  for (c1_b_i = 0; c1_b_i < 2; c1_b_i++) {
    c1_tooBig = false;
  }

  if (!c1_tooBig) {
    c1_modeFlag = true;
  } else {
    c1_modeFlag = false;
  }

  if (c1_modeFlag) {
    c1_b_modeFlag = true;
  } else {
    c1_b_modeFlag = false;
  }

  c1_c_modeFlag = c1_b_modeFlag;
  if (c1_c_modeFlag) {
    for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
      c1_padSizeT[c1_i2] = 122.0 + 40.0 * (real_T)c1_i2;
    }

    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_outSizeT[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_connDimsT[c1_i6] = 3.0;
    }

    ippfilter_real32(&c1_g_a[0], &c1_b[0], &c1_outSizeT[0], 2.0, &c1_padSizeT[0],
                     &c1_kernel[0], &c1_connDimsT[0], true);
  } else {
    for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
      c1_padSizeT[c1_i1] = 122.0 + 40.0 * (real_T)c1_i1;
    }

    for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
      c1_outSizeT[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
    }

    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      c1_connDimsT[c1_i5] = 3.0;
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_startT[c1_i7] = 1.0;
    }

    imfilter_real32(&c1_g_a[0], &c1_b[0], 2.0, &c1_outSizeT[0], 2.0,
                    &c1_padSizeT[0], &c1_nonZeroKernel[0], 6.0, &c1_conn[0], 2.0,
                    &c1_connDimsT[0], &c1_startT[0], 2.0, true, true);
  }
}

static void c1_hypot(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     real32_T c1_c_x[19200], real32_T c1_y[19200], real32_T
                     c1_r[19200])
{
  int32_T c1_b_k;
  int32_T c1_k;
  real32_T c1_b;
  real32_T c1_b_y;
  real32_T c1_d_x;
  real32_T c1_g_a;
  real32_T c1_x1;
  real32_T c1_x2;
  real32_T c1_z;
  (void)chartInstance;
  for (c1_k = 0; c1_k < 19200; c1_k++) {
    c1_b_k = c1_k;
    c1_d_x = c1_c_x[c1_b_k];
    c1_b_y = c1_y[c1_b_k];
    c1_x1 = c1_d_x;
    c1_x2 = c1_b_y;
    c1_g_a = c1_x1;
    c1_b = c1_x2;
    c1_z = muSingleScalarHypot(c1_g_a, c1_b);
    c1_r[c1_b_k] = c1_z;
  }
}

static real32_T c1_maximum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_x[19200])
{
  c1_emxArray_real32_T *c1_d_x;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_st;
  int32_T c1_b_idx;
  int32_T c1_b_k;
  int32_T c1_first;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_k;
  real32_T c1_b_ex;
  real32_T c1_e_x;
  real32_T c1_ex;
  real32_T c1_f_x;
  real32_T c1_g_x;
  real32_T c1_h_x;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_emxInit_real32_T(chartInstance, c1_sp, &c1_d_x, 1, &c1_emlrtRTEI);
  c1_st.site = &c1_hc_emlrtRSI;
  c1_b_st.site = &c1_ic_emlrtRSI;
  c1_i = c1_d_x->size[0];
  c1_d_x->size[0] = 19200;
  c1_emxEnsureCapacity_real32_T(chartInstance, &c1_b_st, c1_d_x, c1_i,
    &c1_emlrtRTEI);
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_d_x->data[c1_i1] = c1_c_x[c1_i1];
  }

  c1_c_st.site = &c1_gb_emlrtRSI;
  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_e_x = c1_d_x->data[0];
  c1_f_x = c1_e_x;
  c1_b = muSingleScalarIsNaN(c1_f_x);
  c1_p = !c1_b;
  if (c1_p) {
    c1_b_idx = 1;
  } else {
    c1_b_idx = 0;
    c1_e_st.site = &c1_jb_emlrtRSI;
    c1_k = 2;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 19201)) {
      c1_g_x = c1_d_x->data[c1_k - 1];
      c1_h_x = c1_g_x;
      c1_b_b = muSingleScalarIsNaN(c1_h_x);
      c1_b_p = !c1_b_b;
      if (c1_b_p) {
        c1_b_idx = c1_k;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }
  }

  if (c1_b_idx == 0) {
    c1_ex = c1_d_x->data[0];
  } else {
    c1_d_st.site = &c1_hb_emlrtRSI;
    c1_first = c1_b_idx - 1;
    c1_b_ex = c1_d_x->data[c1_first];
    c1_i2 = c1_first;
    c1_e_st.site = &c1_lb_emlrtRSI;
    c1_overflow = false;
    if (c1_overflow) {
      c1_f_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
    }

    for (c1_b_k = c1_i2 + 1; c1_b_k + 1 < 19201; c1_b_k++) {
      if (c1_b_ex < c1_d_x->data[c1_b_k]) {
        c1_b_ex = c1_d_x->data[c1_b_k];
      }
    }

    c1_ex = c1_b_ex;
  }

  c1_emxFree_real32_T(chartInstance, &c1_d_x);
  return c1_ex;
}

static void c1_imfindcircles(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200],
  c1_emxArray_real_T *c1_centers, c1_emxArray_real_T *c1_r_estimated,
  c1_emxArray_real_T *c1_metric)
{
  static creal_T c1_dc = { 0.0,        /* re */
    0.0                                /* im */
  };

  c1_emxArray_boolean_T *c1_f_x;
  c1_emxArray_creal_T *c1_c_x;
  c1_emxArray_int32_T *c1_ii;
  c1_emxArray_real_T *c1_b_centers;
  c1_emxArray_real_T *c1_b_metric;
  c1_emxArray_real_T *c1_d_centers;
  c1_emxArray_real_T *c1_idx2Keep;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  creal_T c1_e_x;
  real_T c1_b_k;
  int32_T c1_iv[2];
  int32_T c1_b_idx;
  int32_T c1_b_ii;
  int32_T c1_b_loop_ub;
  int32_T c1_b_nx;
  int32_T c1_c_b;
  int32_T c1_c_centers;
  int32_T c1_c_ii;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_metric;
  int32_T c1_d_b;
  int32_T c1_d_loop_ub;
  int32_T c1_e_loop_ub;
  int32_T c1_f_loop_ub;
  int32_T c1_g_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_loop_ub;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_nx;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b6;
  boolean_T c1_b7;
  boolean_T c1_b_b;
  boolean_T c1_d_x;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_y;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_centers->size[0] = 0;
  c1_centers->size[1] = 0;
  c1_r_estimated->size[0] = 0;
  c1_r_estimated->size[1] = 0;
  c1_metric->size[0] = 0;
  c1_metric->size[1] = 0;
  c1_st.site = &c1_jc_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    chartInstance->c1_c_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_chaccum(chartInstance, &c1_st, chartInstance->c1_c_varargin_1,
             chartInstance->c1_accumMatrix, chartInstance->c1_gradientImg);
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    chartInstance->c1_x[c1_i1] = chartInstance->c1_accumMatrix[c1_i1];
  }

  c1_emxInit_creal_T(chartInstance, c1_sp, &c1_c_x, 1, &c1_k_emlrtRTEI);
  c1_i2 = c1_c_x->size[0];
  c1_c_x->size[0] = 19200;
  c1_emxEnsureCapacity_creal_T(chartInstance, c1_sp, c1_c_x, c1_i2,
    &c1_k_emlrtRTEI);
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    c1_c_x->data[c1_i3] = chartInstance->c1_x[c1_i3];
  }

  c1_y = false;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 19200)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_d_x = ((c1_c_x->data[(int32_T)c1_b_k - 1].re == c1_dc.re) &&
              (c1_c_x->data[(int32_T)c1_b_k - 1].im == c1_dc.im));
    if (c1_d_x) {
      c1_b = true;
    } else {
      c1_e_x = c1_c_x->data[(int32_T)c1_b_k - 1];
      c1_b1 = muDoubleScalarIsNaN(c1_e_x.re);
      c1_b2 = muDoubleScalarIsNaN(c1_e_x.im);
      c1_b_b = (c1_b1 || c1_b2);
      if (c1_b_b) {
        c1_b = true;
      } else {
        c1_b = false;
      }
    }

    if (!c1_b) {
      c1_y = true;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  c1_emxFree_creal_T(chartInstance, &c1_c_x);
  if (c1_y) {
    c1_emxInit_real_T(chartInstance, c1_sp, &c1_b_centers, 2, &c1_v_emlrtRTEI);
    c1_emxInit_real_T(chartInstance, c1_sp, &c1_b_metric, 2, &c1_v_emlrtRTEI);
    c1_st.site = &c1_kc_emlrtRSI;
    for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
      chartInstance->c1_b_accumMatrix[c1_i4] = chartInstance->
        c1_accumMatrix[c1_i4];
    }

    c1_chcenters(chartInstance, &c1_st, chartInstance->c1_b_accumMatrix,
                 c1_b_centers, c1_b_metric);
    c1_i5 = c1_centers->size[0] * c1_centers->size[1];
    c1_centers->size[0] = c1_b_centers->size[0];
    c1_centers->size[1] = c1_b_centers->size[1];
    c1_st.site = &c1_kc_emlrtRSI;
    c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_centers, c1_i5,
      &c1_l_emlrtRTEI);
    c1_loop_ub = c1_b_centers->size[0] * c1_b_centers->size[1] - 1;
    for (c1_i6 = 0; c1_i6 <= c1_loop_ub; c1_i6++) {
      c1_centers->data[c1_i6] = c1_b_centers->data[c1_i6];
    }

    c1_i7 = c1_metric->size[0] * c1_metric->size[1];
    c1_metric->size[0] = c1_b_metric->size[0];
    c1_metric->size[1] = c1_b_metric->size[1];
    c1_st.site = &c1_kc_emlrtRSI;
    c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_metric, c1_i7,
      &c1_m_emlrtRTEI);
    c1_b_loop_ub = c1_b_metric->size[0] * c1_b_metric->size[1] - 1;
    for (c1_i8 = 0; c1_i8 <= c1_b_loop_ub; c1_i8++) {
      c1_metric->data[c1_i8] = c1_b_metric->data[c1_i8];
    }

    c1_b3 = (c1_b_centers->size[0] == 0);
    c1_b4 = (c1_b_centers->size[1] == 0);
    if (!(c1_b3 || c1_b4)) {
      c1_emxInit_boolean_T(chartInstance, c1_sp, &c1_f_x, 2, &c1_n_emlrtRTEI);
      c1_st.site = &c1_lc_emlrtRSI;
      c1_i9 = c1_f_x->size[0] * c1_f_x->size[1];
      c1_f_x->size[0] = c1_b_metric->size[0];
      c1_f_x->size[1] = c1_b_metric->size[1];
      c1_b_st.site = &c1_lc_emlrtRSI;
      c1_emxEnsureCapacity_boolean_T(chartInstance, &c1_b_st, c1_f_x, c1_i9,
        &c1_n_emlrtRTEI);
      c1_c_loop_ub = c1_b_metric->size[0] * c1_b_metric->size[1] - 1;
      for (c1_i10 = 0; c1_i10 <= c1_c_loop_ub; c1_i10++) {
        c1_f_x->data[c1_i10] = (c1_b_metric->data[c1_i10] >= 0.15000000000000002);
      }

      c1_emxInit_int32_T(chartInstance, &c1_st, &c1_ii, 1, &c1_w_emlrtRTEI);
      c1_b_st.site = &c1_xi_emlrtRSI;
      c1_nx = c1_f_x->size[0] * c1_f_x->size[1];
      c1_c_st.site = &c1_yi_emlrtRSI;
      c1_c_k = c1_nx;
      c1_b_nx = c1_nx;
      c1_b_idx = 0;
      c1_i11 = c1_ii->size[0];
      c1_ii->size[0] = c1_c_k;
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_ii, c1_i11,
        &c1_o_emlrtRTEI);
      c1_d_st.site = &c1_aj_emlrtRSI;
      c1_c_b = c1_b_nx;
      c1_d_b = c1_c_b;
      if (1 > c1_d_b) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_d_b > 2147483646);
      }

      if (c1_overflow) {
        c1_e_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
      }

      c1_b_ii = 1;
      c1_exitg1 = false;
      while ((!c1_exitg1) && (c1_b_ii - 1 <= c1_b_nx - 1)) {
        c1_c_ii = c1_b_ii;
        if (c1_f_x->data[c1_c_ii - 1]) {
          c1_b_idx++;
          c1_ii->data[c1_b_idx - 1] = c1_c_ii;
          if (c1_b_idx >= c1_c_k) {
            c1_exitg1 = true;
          } else {
            c1_b_ii++;
          }
        } else {
          c1_b_ii++;
        }
      }

      c1_emxFree_boolean_T(chartInstance, &c1_f_x);
      if (!(c1_b_idx <= c1_c_k)) {
        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call(&c1_c_st, &c1_x_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                    sf_mex_call(&c1_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c1_c_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
      }

      if (c1_c_k == 1) {
        if (c1_b_idx == 0) {
          c1_ii->size[0] = 0;
        }
      } else {
        c1_b5 = (1 > c1_b_idx);
        if (c1_b5) {
          c1_i12 = 0;
        } else {
          c1_i12 = c1_b_idx;
        }

        c1_iv[0] = 1;
        c1_iv[1] = c1_i12;
        c1_d_st.site = &c1_bj_emlrtRSI;
        c1_indexShapeCheck(chartInstance, &c1_d_st, c1_ii->size[0], c1_iv);
        c1_i14 = c1_ii->size[0];
        c1_ii->size[0] = c1_i12;
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_ii, c1_i14,
          &c1_q_emlrtRTEI);
      }

      c1_emxInit_real_T1(chartInstance, &c1_c_st, &c1_idx2Keep, 1,
                         &c1_p_emlrtRTEI);
      c1_i13 = c1_idx2Keep->size[0];
      c1_idx2Keep->size[0] = c1_ii->size[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_idx2Keep, c1_i13,
        &c1_p_emlrtRTEI);
      c1_d_loop_ub = c1_ii->size[0] - 1;
      for (c1_i15 = 0; c1_i15 <= c1_d_loop_ub; c1_i15++) {
        c1_idx2Keep->data[c1_i15] = (real_T)c1_ii->data[c1_i15];
      }

      c1_emxFree_int32_T(chartInstance, &c1_ii);
      c1_c_centers = c1_b_centers->size[0];
      c1_i16 = c1_b_centers->size[1] - 1;
      c1_i17 = c1_centers->size[0] * c1_centers->size[1];
      c1_centers->size[0] = c1_idx2Keep->size[0];
      c1_centers->size[1] = c1_i16 + 1;
      c1_st.site = &c1_ql_emlrtRSI;
      c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_centers, c1_i17,
        &c1_r_emlrtRTEI);
      c1_e_loop_ub = c1_i16;
      for (c1_i18 = 0; c1_i18 <= c1_e_loop_ub; c1_i18++) {
        c1_f_loop_ub = c1_idx2Keep->size[0] - 1;
        for (c1_i20 = 0; c1_i20 <= c1_f_loop_ub; c1_i20++) {
          c1_i22 = (int32_T)c1_idx2Keep->data[c1_i20];
          c1_centers->data[c1_i20 + c1_centers->size[0] * c1_i18] =
            c1_b_centers->data[(emlrtDynamicBoundsCheckR2012b(c1_i22, 1,
            c1_c_centers, &c1_r_emlrtBCI, c1_sp) + c1_b_centers->size[0] *
                                c1_i18) - 1];
        }
      }

      c1_c_metric = c1_b_metric->size[0];
      c1_i19 = c1_b_metric->size[1] - 1;
      c1_i21 = c1_metric->size[0] * c1_metric->size[1];
      c1_metric->size[0] = c1_idx2Keep->size[0];
      c1_metric->size[1] = c1_i19 + 1;
      c1_st.site = &c1_pl_emlrtRSI;
      c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_metric, c1_i21,
        &c1_s_emlrtRTEI);
      c1_g_loop_ub = c1_i19;
      for (c1_i23 = 0; c1_i23 <= c1_g_loop_ub; c1_i23++) {
        c1_h_loop_ub = c1_idx2Keep->size[0] - 1;
        for (c1_i24 = 0; c1_i24 <= c1_h_loop_ub; c1_i24++) {
          c1_i25 = (int32_T)c1_idx2Keep->data[c1_i24];
          c1_metric->data[c1_i24 + c1_metric->size[0] * c1_i23] =
            c1_b_metric->data[(emlrtDynamicBoundsCheckR2012b(c1_i25, 1,
            c1_c_metric, &c1_s_emlrtBCI, c1_sp) + c1_b_metric->size[0] * c1_i23)
            - 1];
        }
      }

      c1_b6 = (c1_centers->size[0] == 0);
      c1_b7 = (c1_centers->size[1] == 0);
      if (c1_b6 || c1_b7) {
        c1_centers->size[0] = 0;
        c1_centers->size[1] = 0;
        c1_metric->size[0] = 0;
        c1_metric->size[1] = 0;
      } else {
        c1_emxInit_real_T(chartInstance, c1_sp, &c1_d_centers, 2,
                          &c1_t_emlrtRTEI);
        c1_i26 = c1_d_centers->size[0] * c1_d_centers->size[1];
        c1_d_centers->size[0] = c1_centers->size[0];
        c1_d_centers->size[1] = c1_centers->size[1];
        c1_st.site = &c1_mc_emlrtRSI;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_d_centers, c1_i26,
          &c1_t_emlrtRTEI);
        c1_i_loop_ub = c1_centers->size[0] * c1_centers->size[1] - 1;
        for (c1_i27 = 0; c1_i27 <= c1_i_loop_ub; c1_i27++) {
          c1_d_centers->data[c1_i27] = c1_centers->data[c1_i27];
        }

        c1_st.site = &c1_mc_emlrtRSI;
        c1_chradiiphcode(chartInstance, &c1_st, c1_d_centers,
                         chartInstance->c1_accumMatrix, c1_idx2Keep);
        c1_i28 = c1_r_estimated->size[0] * c1_r_estimated->size[1];
        c1_r_estimated->size[0] = c1_idx2Keep->size[0];
        c1_r_estimated->size[1] = 1;
        c1_st.site = &c1_mc_emlrtRSI;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_r_estimated,
          c1_i28, &c1_u_emlrtRTEI);
        c1_j_loop_ub = c1_idx2Keep->size[0] - 1;
        c1_emxFree_real_T(chartInstance, &c1_d_centers);
        for (c1_i29 = 0; c1_i29 <= c1_j_loop_ub; c1_i29++) {
          c1_r_estimated->data[c1_i29] = c1_idx2Keep->data[c1_i29];
        }
      }

      c1_emxFree_real_T(chartInstance, &c1_idx2Keep);
    }

    c1_emxFree_real_T(chartInstance, &c1_b_metric);
    c1_emxFree_real_T(chartInstance, &c1_b_centers);
  }
}

static void c1_chaccum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200], creal_T
  c1_c_accumMatrix[19200], real32_T c1_b_gradientImg[19200])
{
  static creal_T c1_Opca[51] = { { -1.0,/* re */
      -1.2246467991473532E-16          /* im */
    }, { -0.97802020385900779,         /* re */
      -0.20851014566103235             /* im */
    }, { -0.91574686949728124,         /* re */
      -0.40175573549848592             /* im */
    }, { -0.81932918047886227,         /* re */
      -0.57332337647773957             /* im */
    }, { -0.6954184976738389,          /* re */
      -0.71860497708620208             /* im */
    }, { -0.5507880805072134,          /* re */
      -0.83464512840558736             /* im */
    }, { -0.39203783842097073,         /* re */
      -0.91994909274710024             /* im */
    }, { -0.22537515221469892,         /* re */
      -0.974272056852808               /* im */
    }, { -0.056461432538574136,        /* re */
      -0.99840478095594676             /* im */
    }, { 0.10968616958136543,          /* re */
      -0.99396626914728248             /* im */
    }, { 0.26874803229707556,          /* re */
      -0.96321051444450612             /* im */
    }, { 0.41711958165892082,          /* re */
      -0.90885161307921269             /* im */
    }, { 0.55190126013242324,          /* re */
      -0.833909466947248               /* im */
    }, { 0.67086800873377794,          /* re */
      -0.74157677610452155             /* im */
    }, { 0.77242420945745627,          /* re */
      -0.63510695213013046             /* im */
    }, { 0.85554899027289855,          /* re */
      -0.51772186088963223             /* im */
    }, { 0.91973585215372922,          /* re */
      -0.39253784819180626             /* im */
    }, { 0.96492974879251492,          /* re */
      -0.26250824728989758             /* im */
    }, { 0.99146403654932613,          /* re */
      -0.13038045953790983             /* im */
    }, { 0.9999991098166704,           /* re */
      0.0013343035137634166            /* im */
    }, { 0.99146403654932613,          /* re */
      0.13038045953790983              /* im */
    }, { 0.96700209948356886,          /* re */
      0.2547684038384076               /* im */
    }, { 0.92792081920064406,          /* re */
      0.37277735083291419              /* im */
    }, { 0.87564677449936246,          /* re */
      0.48295209525258576              /* im */
    }, { 0.81168533303058732,          /* re */
      0.584094958155799                /* im */
    }, { 0.73758525125122842,          /* re */
      0.675254024154364                /* im */
    }, { 0.65490798897553737,          /* re */
      0.75570862505069869              /* im */
    }, { 0.56520150271535452,          /* re */
      0.82495288430813141              /* im */
    }, { 0.46997822722670263,          /* re */
      0.88267800807137242              /* im */
    }, { 0.37069692079986849,          /* re */
      0.92875389254069673              /* im */
    }, { 0.26874803229707572,          /* re */
      0.963210514444506                /* im */
    }, { 0.16544224297915311,          /* re */
      0.98621948076380384              /* im */
    }, { 0.0620018406648306,           /* re */
      0.99807603505653464              /* im */
    }, { -0.040445404795224314,        /* re */
      0.99918174984882024              /* im */
    }, { -0.14087017941092603,         /* re */
      0.99002807664870474              /* im */
    }, { -0.23834367138338119,         /* re */
      0.97118087620766647              /* im */
    }, { -0.33203799934291556,         /* re */
      0.94326601072674832              /* im */
    }, { -0.42122527336382581,         /* re */
      0.90695604583660516              /* im */
    }, { -0.50527551678875027,         /* re */
      0.86295808248944594              /* im */
    }, { -0.58365365439243577,         /* re */
      0.81200271656833456              /* im */
    }, { -0.65591575066114749,         /* re */
      0.75483410630059855              /* im */
    }, { -0.72170466125252131,         /* re */
      0.69220111378585891              /* im */
    }, { -0.78074524122605593,         /* re */
      0.62484947651643885              /* im */
    }, { -0.83283923551494521,         /* re */
      0.55351495714829757              /* im */
    }, { -0.87785996040374592,         /* re */
      0.478917414508946                /* im */
    }, { -0.91574686949728124,         /* re */
      0.40175573549848592              /* im */
    }, { -0.94650008379301576,         /* re */
      0.32270356579965792              /* im */
    }, { -0.97017495295719258,         /* re */
      0.24240577685878117              /* im */
    }, { -0.98687670369103553,         /* re */
      0.16147560717308376              /* im */
    }, { -0.99675522108353054,         /* re */
      0.0804924172995329               /* im */
    }, { -1.0,                         /* re */
      1.2246467991473532E-16           /* im */
    } };

  static real_T c1_b_dv[51] = { 94.247779607693786, 97.389372261283583,
    100.53096491487338, 103.67255756846318, 106.81415022205297,
    109.95574287564276, 113.09733552923255, 116.23892818282235,
    119.38052083641213, 122.52211349000193, 125.66370614359172,
    128.80529879718151, 131.94689145077132, 135.0884841043611,
    138.23007675795088, 141.37166941154069, 144.51326206513048,
    147.65485471872029, 150.79644737231007, 153.93804002589985,
    157.07963267948966, 160.22122533307945, 163.36281798666926,
    166.50441064025904, 169.64600329384882, 172.78759594743863,
    175.92918860102841, 179.0707812546182, 182.212373908208, 185.35396656179779,
    188.49555921538757, 191.63715186897738, 194.77874452256717,
    197.92033717615698, 201.06192982974676, 204.20352248333654,
    207.34511513692635, 210.48670779051614, 213.62830044410595,
    216.76989309769573, 219.91148575128551, 223.05307840487532,
    226.1946710584651, 229.33626371205489, 232.4778563656447, 235.61944901923448,
    238.76104167282426, 241.90263432641407, 245.04422698000386,
    248.18581963359367, 251.32741228718345 };

  c1_emxArray_boolean_T *c1_inside;
  c1_emxArray_creal_T *c1_w;
  c1_emxArray_creal_T *c1_wkeep;
  c1_emxArray_int32_T *c1_ii;
  c1_emxArray_int32_T *c1_jj;
  c1_emxArray_int32_T *c1_r;
  c1_emxArray_int32_T *c1_xckeep;
  c1_emxArray_int32_T *c1_yckeep;
  c1_emxArray_real32_T *c1_xc;
  c1_emxArray_real32_T *c1_yc;
  c1_emxArray_real_T *c1_Ex;
  c1_emxArray_real_T *c1_Ex_chunk;
  c1_emxArray_real_T *c1_Ey;
  c1_emxArray_real_T *c1_Ey_chunk;
  c1_emxArray_real_T *c1_b_varargin_2;
  c1_emxArray_real_T *c1_idxE;
  c1_emxArray_real_T *c1_idxE_chunk;
  c1_emxArray_real_T *c1_ndx;
  c1_emxArray_real_T *c1_r1;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  creal_T c1_w0[51];
  real_T c1_a1;
  real_T c1_absa;
  real_T c1_absb;
  real_T c1_ai;
  real_T c1_apnd;
  real_T c1_ar;
  real_T c1_b;
  real_T c1_b1;
  real_T c1_b_d;
  real_T c1_b_idx1;
  real_T c1_b_idx2;
  real_T c1_b_k;
  real_T c1_b_s;
  real_T c1_bi;
  real_T c1_bim;
  real_T c1_br;
  real_T c1_brm;
  real_T c1_c;
  real_T c1_c_i;
  real_T c1_c_idx;
  real_T c1_c_varargin_2;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_cdiff;
  real_T c1_d;
  real_T c1_d_x;
  real_T c1_d_y;
  real_T c1_dim1;
  real_T c1_e_x;
  real_T c1_e_y;
  real_T c1_f_b;
  real_T c1_f_varargin_1;
  real_T c1_f_x;
  real_T c1_f_y;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_g_x;
  real_T c1_g_y;
  real_T c1_h_a;
  real_T c1_h_b;
  real_T c1_h_x;
  real_T c1_h_y;
  real_T c1_i_a;
  real_T c1_i_x;
  real_T c1_i_y;
  real_T c1_j_a;
  real_T c1_j_x;
  real_T c1_k_a;
  real_T c1_k_x;
  real_T c1_kd;
  real_T c1_l_x;
  real_T c1_lenE;
  real_T c1_m_a;
  real_T c1_m_x;
  real_T c1_minval;
  real_T c1_n_a;
  real_T c1_n_x;
  real_T c1_ndbl;
  real_T c1_ni;
  real_T c1_nr;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_sgnbi;
  real_T c1_sgnbr;
  real_T c1_sizeChunk;
  real_T c1_t_x;
  real_T c1_thresh;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_x_x;
  int32_T c1_rows_to_keep_size[1];
  int32_T c1_b_i;
  int32_T c1_b_idx;
  int32_T c1_b_loop_ub;
  int32_T c1_c_idx1;
  int32_T c1_c_idx2;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_d_idx;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_e_idx;
  int32_T c1_e_loop_ub;
  int32_T c1_f_loop_ub;
  int32_T c1_g_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  int32_T c1_i104;
  int32_T c1_i105;
  int32_T c1_i106;
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  int32_T c1_i11;
  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  int32_T c1_i114;
  int32_T c1_i115;
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  int32_T c1_i119;
  int32_T c1_i12;
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i9;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i_b;
  int32_T c1_idx1;
  int32_T c1_idx2;
  int32_T c1_idxEdge;
  int32_T c1_idxkeep;
  int32_T c1_j_b;
  int32_T c1_k;
  int32_T c1_l_a;
  int32_T c1_l_b;
  int32_T c1_loop_ub;
  int32_T c1_m_b;
  int32_T c1_m_y;
  int32_T c1_n;
  int32_T c1_n_b;
  int32_T c1_nm1;
  int32_T c1_nm1d2;
  int32_T c1_szxc;
  real32_T c1_Gmax;
  real32_T c1_ab_x;
  real32_T c1_b_y;
  real32_T c1_b_z;
  real32_T c1_bb_x;
  real32_T c1_cb_x;
  real32_T c1_db_x;
  real32_T c1_eb_x;
  real32_T c1_edgeThresh;
  real32_T c1_j_y;
  real32_T c1_k_b;
  real32_T c1_k_y;
  real32_T c1_l_y;
  real32_T c1_n_y;
  real32_T c1_o_b;
  real32_T c1_o_y;
  real32_T c1_p_y;
  real32_T c1_q_y;
  real32_T c1_r_y;
  real32_T c1_t;
  real32_T c1_y;
  real32_T c1_y_x;
  real32_T c1_z;
  boolean_T c1_rows_to_keep_data[19200];
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b_b;
  boolean_T c1_b_b1;
  boolean_T c1_b_overflow;
  boolean_T c1_c_b;
  boolean_T c1_d_b;
  boolean_T c1_e_b;
  boolean_T c1_e_varargin_1;
  boolean_T c1_exitg1;
  boolean_T c1_flat;
  boolean_T c1_guard1 = false;
  boolean_T c1_guard2 = false;
  boolean_T c1_guard3 = false;
  boolean_T c1_overflow;
  boolean_T c1_p_b;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_e_varargin_1 = c1_d_varargin_1[0];
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    chartInstance->c1_b_x[c1_i] = ((int32_T)c1_d_varargin_1[c1_i] == (int32_T)
      c1_e_varargin_1);
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    chartInstance->c1_x_data[c1_i1] = chartInstance->c1_b_x[c1_i1];
  }

  c1_flat = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 19200)) {
    c1_b_k = (real_T)c1_k + 1.0;
    if (!chartInstance->c1_x_data[(int32_T)c1_b_k - 1]) {
      c1_flat = false;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (c1_flat) {
    for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
      c1_c_accumMatrix[c1_i2].re = 0.0;
      c1_c_accumMatrix[c1_i2].im = 0.0;
    }

    for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
      c1_b_gradientImg[c1_i4] = 0.0F;
    }
  } else {
    c1_st.site = &c1_nc_emlrtRSI;
    for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
      chartInstance->c1_s[c1_i3] = (real32_T)c1_d_varargin_1[c1_i3];
    }

    c1_b_st.site = &c1_cc_emlrtRSI;
    c1_e_imfilter(chartInstance, &c1_b_st, chartInstance->c1_s,
                  chartInstance->c1_A);
    c1_st.site = &c1_oc_emlrtRSI;
    c1_b_st.site = &c1_dc_emlrtRSI;
    for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
      chartInstance->c1_b_A[c1_i5] = chartInstance->c1_A[c1_i5];
    }

    c1_f_imfilter(chartInstance, &c1_b_st, chartInstance->c1_b_A,
                  chartInstance->c1_Gx);
    c1_b_st.site = &c1_ec_emlrtRSI;
    c1_g_imfilter(chartInstance, &c1_b_st, chartInstance->c1_A,
                  chartInstance->c1_Gy);
    for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
      chartInstance->c1_b_Gx[c1_i6] = chartInstance->c1_Gx[c1_i6];
    }

    for (c1_i7 = 0; c1_i7 < 19200; c1_i7++) {
      chartInstance->c1_b_Gy[c1_i7] = chartInstance->c1_Gy[c1_i7];
    }

    c1_hypot(chartInstance, chartInstance->c1_b_Gx, chartInstance->c1_b_Gy,
             c1_b_gradientImg);
    c1_st.site = &c1_pc_emlrtRSI;
    c1_b_st.site = &c1_tc_emlrtRSI;
    for (c1_i8 = 0; c1_i8 < 19200; c1_i8++) {
      chartInstance->c1_s[c1_i8] = c1_b_gradientImg[c1_i8];
    }

    c1_c_st.site = &c1_fc_emlrtRSI;
    c1_d_st.site = &c1_gc_emlrtRSI;
    c1_Gmax = c1_maximum(chartInstance, &c1_d_st, chartInstance->c1_s);
    c1_y = c1_Gmax;
    c1_b_y = c1_y;
    for (c1_i9 = 0; c1_i9 < 19200; c1_i9++) {
      chartInstance->c1_s[c1_i9] = c1_b_gradientImg[c1_i9] / c1_b_y;
    }

    c1_b_st.site = &c1_uc_emlrtRSI;
    c1_edgeThresh = c1_multithresh(chartInstance, &c1_b_st, chartInstance->c1_s);
    c1_t = c1_Gmax * c1_edgeThresh;
    c1_b_st.site = &c1_vc_emlrtRSI;
    for (c1_i10 = 0; c1_i10 < 19200; c1_i10++) {
      chartInstance->c1_b_x[c1_i10] = (c1_b_gradientImg[c1_i10] > c1_t);
    }

    c1_emxInit_real_T1(chartInstance, &c1_b_st, &c1_Ey, 1, &c1_cc_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, &c1_b_st, &c1_ii, 1, &c1_cc_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, &c1_b_st, &c1_jj, 1, &c1_cc_emlrtRTEI);
    c1_c_st.site = &c1_rf_emlrtRSI;
    c1_eml_find(chartInstance, &c1_c_st, chartInstance->c1_b_x, c1_ii, c1_jj);
    c1_i11 = c1_Ey->size[0];
    c1_Ey->size[0] = c1_ii->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_Ey, c1_i11,
      &c1_x_emlrtRTEI);
    c1_loop_ub = c1_ii->size[0] - 1;
    for (c1_i12 = 0; c1_i12 <= c1_loop_ub; c1_i12++) {
      c1_Ey->data[c1_i12] = (real_T)c1_ii->data[c1_i12];
    }

    c1_emxFree_int32_T(chartInstance, &c1_ii);
    c1_emxInit_real_T1(chartInstance, &c1_b_st, &c1_Ex, 1, &c1_cc_emlrtRTEI);
    c1_i13 = c1_Ex->size[0];
    c1_Ex->size[0] = c1_jj->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_Ex, c1_i13,
      &c1_y_emlrtRTEI);
    c1_b_loop_ub = c1_jj->size[0] - 1;
    for (c1_i14 = 0; c1_i14 <= c1_b_loop_ub; c1_i14++) {
      c1_Ex->data[c1_i14] = (real_T)c1_jj->data[c1_i14];
    }

    c1_emxFree_int32_T(chartInstance, &c1_jj);
    c1_emxInit_real_T1(chartInstance, &c1_b_st, &c1_ndx, 1, &c1_dc_emlrtRTEI);
    c1_st.site = &c1_qc_emlrtRSI;
    c1_i15 = c1_ndx->size[0];
    c1_ndx->size[0] = c1_Ey->size[0];
    c1_b_st.site = &c1_qc_emlrtRSI;
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_ndx, c1_i15,
      &c1_ab_emlrtRTEI);
    c1_c_loop_ub = c1_Ey->size[0] - 1;
    for (c1_i16 = 0; c1_i16 <= c1_c_loop_ub; c1_i16++) {
      c1_ndx->data[c1_i16] = c1_Ey->data[c1_i16];
    }

    c1_emxInit_real_T1(chartInstance, &c1_st, &c1_b_varargin_2, 1,
                       &c1_bb_emlrtRTEI);
    c1_i17 = c1_b_varargin_2->size[0];
    c1_b_varargin_2->size[0] = c1_Ex->size[0];
    c1_b_st.site = &c1_qc_emlrtRSI;
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_b_varargin_2, c1_i17,
      &c1_bb_emlrtRTEI);
    c1_d_loop_ub = c1_Ex->size[0] - 1;
    for (c1_i18 = 0; c1_i18 <= c1_d_loop_ub; c1_i18++) {
      c1_b_varargin_2->data[c1_i18] = c1_Ex->data[c1_i18];
    }

    c1_emxInit_int32_T(chartInstance, &c1_st, &c1_r, 1, &c1_ec_emlrtRTEI);
    c1_b_st.site = &c1_wf_emlrtRSI;
    c1_eml_sub2ind(chartInstance, &c1_b_st, c1_ndx, c1_b_varargin_2, c1_r);
    c1_i19 = c1_ndx->size[0];
    c1_ndx->size[0] = c1_r->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_ndx, c1_i19,
      &c1_cb_emlrtRTEI);
    c1_e_loop_ub = c1_r->size[0] - 1;
    c1_emxFree_real_T(chartInstance, &c1_b_varargin_2);
    for (c1_i20 = 0; c1_i20 <= c1_e_loop_ub; c1_i20++) {
      c1_ndx->data[c1_i20] = (real_T)c1_r->data[c1_i20];
    }

    c1_emxFree_int32_T(chartInstance, &c1_r);
    c1_emxInit_real_T1(chartInstance, &c1_st, &c1_idxE, 1, &c1_db_emlrtRTEI);
    c1_i21 = c1_idxE->size[0];
    c1_idxE->size[0] = c1_ndx->size[0];
    c1_st.site = &c1_qc_emlrtRSI;
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_idxE, c1_i21,
      &c1_db_emlrtRTEI);
    c1_f_loop_ub = c1_ndx->size[0] - 1;
    for (c1_i22 = 0; c1_i22 <= c1_f_loop_ub; c1_i22++) {
      c1_idxE->data[c1_i22] = c1_ndx->data[c1_i22];
    }

    c1_emxFree_real_T(chartInstance, &c1_ndx);
    for (c1_i23 = 0; c1_i23 < 51; c1_i23++) {
      c1_ar = c1_Opca[c1_i23].re;
      c1_ai = c1_Opca[c1_i23].im;
      c1_br = c1_b_dv[c1_i23];
      c1_bi = 0.0;
      if (c1_bi == 0.0) {
        if (c1_ai == 0.0) {
          c1_w0[c1_i23].re = c1_ar / c1_br;
          c1_w0[c1_i23].im = 0.0;
        } else if (c1_ar == 0.0) {
          c1_w0[c1_i23].re = 0.0;
          c1_w0[c1_i23].im = c1_ai / c1_br;
        } else {
          c1_w0[c1_i23].re = c1_ar / c1_br;
          c1_w0[c1_i23].im = c1_ai / c1_br;
        }
      } else if (c1_br == 0.0) {
        if (c1_ar == 0.0) {
          c1_w0[c1_i23].re = c1_ai / c1_bi;
          c1_w0[c1_i23].im = 0.0;
        } else if (c1_ai == 0.0) {
          c1_w0[c1_i23].re = 0.0;
          c1_w0[c1_i23].im = -(c1_ar / c1_bi);
        } else {
          c1_w0[c1_i23].re = c1_ai / c1_bi;
          c1_w0[c1_i23].im = -(c1_ar / c1_bi);
        }
      } else {
        c1_brm = muDoubleScalarAbs(c1_br);
        c1_bim = muDoubleScalarAbs(c1_bi);
        if (c1_brm > c1_bim) {
          c1_b_s = c1_bi / c1_br;
          c1_d = c1_br + c1_b_s * c1_bi;
          c1_nr = c1_ar + c1_b_s * c1_ai;
          c1_ni = c1_ai - c1_b_s * c1_ar;
          c1_w0[c1_i23].re = c1_nr / c1_d;
          c1_w0[c1_i23].im = c1_ni / c1_d;
        } else if (c1_bim == c1_brm) {
          if (c1_br > 0.0) {
            c1_sgnbr = 0.5;
          } else {
            c1_sgnbr = -0.5;
          }

          if (c1_bi > 0.0) {
            c1_sgnbi = 0.5;
          } else {
            c1_sgnbi = -0.5;
          }

          c1_nr = c1_ar * c1_sgnbr + c1_ai * c1_sgnbi;
          c1_ni = c1_ai * c1_sgnbr - c1_ar * c1_sgnbi;
          c1_w0[c1_i23].re = c1_nr / c1_brm;
          c1_w0[c1_i23].im = c1_ni / c1_brm;
        } else {
          c1_b_s = c1_br / c1_bi;
          c1_d = c1_bi + c1_b_s * c1_br;
          c1_nr = c1_b_s * c1_ar + c1_ai;
          c1_ni = c1_b_s * c1_ai - c1_ar;
          c1_w0[c1_i23].re = c1_nr / c1_d;
          c1_w0[c1_i23].im = c1_ni / c1_d;
        }
      }
    }

    c1_lenE = (real_T)c1_Ex->size[0];
    for (c1_i24 = 0; c1_i24 < 19200; c1_i24++) {
      c1_c_accumMatrix[c1_i24].re = 0.0;
      c1_c_accumMatrix[c1_i24].im = 0.0;
    }

    c1_i25 = (int32_T)((c1_lenE + 19606.0) / 19607.0);
    emlrtForLoopVectorCheckR2012b(1.0, 19607.0, c1_lenE, mxDOUBLE_CLASS, c1_i25,
      &c1_gj_emlrtRTEI, c1_sp);
    c1_b_i = 0;
    c1_emxInit_real_T1(chartInstance, c1_sp, &c1_Ex_chunk, 1, &c1_rb_emlrtRTEI);
    c1_emxInit_real_T1(chartInstance, c1_sp, &c1_Ey_chunk, 1, &c1_sb_emlrtRTEI);
    c1_emxInit_real_T1(chartInstance, c1_sp, &c1_idxE_chunk, 1, &c1_tb_emlrtRTEI);
    c1_emxInit_real32_T1(chartInstance, c1_sp, &c1_xc, 2, &c1_ub_emlrtRTEI);
    c1_emxInit_real32_T1(chartInstance, c1_sp, &c1_yc, 2, &c1_vb_emlrtRTEI);
    c1_emxInit_creal_T1(chartInstance, c1_sp, &c1_w, 2, &c1_wb_emlrtRTEI);
    c1_emxInit_boolean_T(chartInstance, c1_sp, &c1_inside, 2, &c1_xb_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, c1_sp, &c1_xckeep, 1, &c1_yb_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, c1_sp, &c1_yckeep, 1, &c1_ac_emlrtRTEI);
    c1_emxInit_creal_T(chartInstance, c1_sp, &c1_wkeep, 1, &c1_bc_emlrtRTEI);
    c1_emxInit_real_T(chartInstance, c1_sp, &c1_r1, 2, &c1_cc_emlrtRTEI);
    while (c1_b_i <= c1_i25 - 1) {
      c1_c_i = (real_T)c1_b_i * 19607.0 + 1.0;
      c1_f_varargin_1 = (c1_c_i + 19607.0) - 1.0;
      c1_c_varargin_2 = c1_lenE;
      c1_c_x = c1_f_varargin_1;
      c1_c_y = c1_c_varargin_2;
      c1_d_x = c1_c_x;
      c1_d_y = c1_c_y;
      c1_e_x = c1_d_x;
      c1_e_y = c1_d_y;
      c1_f_x = c1_e_x;
      c1_f_y = c1_e_y;
      c1_g_x = c1_f_x;
      c1_g_y = c1_f_y;
      c1_h_x = c1_g_x;
      c1_h_y = c1_g_y;
      c1_minval = muDoubleScalarMin(c1_h_x, c1_h_y);
      c1_st.site = &c1_rc_emlrtRSI;
      c1_g_a = c1_c_i;
      c1_b_d = c1_minval;
      c1_b_st.site = &c1_xf_emlrtRSI;
      c1_h_a = c1_g_a;
      c1_b = c1_b_d;
      c1_i_x = c1_h_a;
      c1_b_b = muDoubleScalarIsNaN(c1_i_x);
      c1_guard1 = false;
      c1_guard2 = false;
      c1_guard3 = false;
      if (c1_b_b) {
        c1_guard2 = true;
      } else {
        c1_j_x = c1_b;
        c1_c_b = muDoubleScalarIsNaN(c1_j_x);
        if (c1_c_b) {
          c1_guard2 = true;
        } else if (c1_b < c1_h_a) {
          c1_r1->size[0] = 1;
          c1_r1->size[1] = 0;
        } else {
          c1_k_x = c1_h_a;
          c1_d_b = muDoubleScalarIsInf(c1_k_x);
          if (c1_d_b) {
            c1_guard3 = true;
          } else {
            c1_l_x = c1_b;
            c1_e_b = muDoubleScalarIsInf(c1_l_x);
            if (c1_e_b) {
              c1_guard3 = true;
            } else {
              c1_guard1 = true;
            }
          }
        }
      }

      if (c1_guard3) {
        if (c1_h_a == c1_b) {
          c1_i26 = c1_r1->size[0] * c1_r1->size[1];
          c1_r1->size[0] = 1;
          c1_r1->size[1] = 1;
          c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_r1, c1_i26,
            &c1_eb_emlrtRTEI);
          c1_r1->data[0] = rtNaN;
        } else {
          c1_guard1 = true;
        }
      }

      if (c1_guard2) {
        c1_i27 = c1_r1->size[0] * c1_r1->size[1];
        c1_r1->size[0] = 1;
        c1_r1->size[1] = 1;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_r1, c1_i27,
          &c1_eb_emlrtRTEI);
        c1_r1->data[0] = rtNaN;
      }

      if (c1_guard1) {
        c1_m_x = c1_h_a;
        c1_n_x = c1_m_x;
        c1_n_x = muDoubleScalarFloor(c1_n_x);
        if (c1_n_x == c1_h_a) {
          c1_i29 = c1_r1->size[0] * c1_r1->size[1];
          c1_r1->size[0] = 1;
          c1_r1->size[1] = (int32_T)muDoubleScalarFloor(c1_b - c1_h_a) + 1;
          c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_r1, c1_i29,
            &c1_eb_emlrtRTEI);
          c1_g_loop_ub = (int32_T)muDoubleScalarFloor(c1_b - c1_h_a);
          for (c1_i31 = 0; c1_i31 <= c1_g_loop_ub; c1_i31++) {
            c1_r1->data[c1_i31] = c1_h_a + (real_T)c1_i31;
          }
        } else {
          c1_c_st.site = &c1_yf_emlrtRSI;
          c1_i_a = c1_h_a;
          c1_f_b = c1_b;
          c1_j_a = c1_i_a;
          c1_g_b = c1_f_b;
          c1_a1 = c1_j_a;
          c1_o_x = (c1_g_b - c1_j_a) + 0.5;
          c1_ndbl = c1_o_x;
          c1_ndbl = muDoubleScalarFloor(c1_ndbl);
          c1_apnd = c1_j_a + c1_ndbl;
          c1_cdiff = c1_apnd - c1_g_b;
          c1_k_a = c1_j_a;
          c1_h_b = c1_g_b;
          c1_p_x = c1_k_a;
          c1_q_x = c1_p_x;
          c1_r_x = c1_q_x;
          c1_absa = muDoubleScalarAbs(c1_r_x);
          c1_s_x = c1_h_b;
          c1_t_x = c1_s_x;
          c1_u_x = c1_t_x;
          c1_absb = muDoubleScalarAbs(c1_u_x);
          if (c1_absa > c1_absb) {
            c1_c = c1_absa;
          } else {
            c1_c = c1_absb;
          }

          c1_thresh = 4.4408920985006262E-16 * c1_c;
          c1_v_x = c1_cdiff;
          c1_w_x = c1_v_x;
          c1_x_x = c1_w_x;
          c1_i_y = muDoubleScalarAbs(c1_x_x);
          if (c1_i_y < c1_thresh) {
            c1_ndbl++;
            c1_b1 = c1_g_b;
          } else if (c1_cdiff > 0.0) {
            c1_b1 = c1_j_a + (c1_ndbl - 1.0);
          } else {
            c1_ndbl++;
            c1_b1 = c1_apnd;
          }

          if (c1_ndbl >= 0.0) {
            c1_n = (int32_T)muDoubleScalarFloor(c1_ndbl);
          } else {
            c1_n = 0;
          }

          c1_i47 = c1_r1->size[0] * c1_r1->size[1];
          c1_r1->size[0] = 1;
          c1_r1->size[1] = c1_n;
          c1_emxEnsureCapacity_real_T1(chartInstance, &c1_c_st, c1_r1, c1_i47,
            &c1_qb_emlrtRTEI);
          if (c1_n > 0) {
            c1_r1->data[0] = c1_a1;
            if (c1_n > 1) {
              c1_r1->data[c1_n - 1] = c1_b1;
              c1_nm1 = c1_n - 1;
              c1_l_a = c1_nm1;
              c1_nm1d2 = c1_div_nzp_s32(chartInstance, c1_l_a, 2, 0, 1U, 0, 0);
              c1_i52 = c1_nm1d2 - 2;
              c1_d_st.site = &c1_ag_emlrtRSI;
              c1_i_b = c1_i52 + 1;
              c1_j_b = c1_i_b;
              if (1 > c1_j_b) {
                c1_overflow = false;
              } else {
                c1_overflow = (c1_j_b > 2147483646);
              }

              if (c1_overflow) {
                c1_e_st.site = &c1_kb_emlrtRSI;
                c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
              }

              for (c1_c_k = 1; c1_c_k - 1 <= c1_i52; c1_c_k++) {
                c1_d_k = c1_c_k;
                c1_kd = (real_T)c1_d_k;
                c1_r1->data[c1_d_k] = c1_a1 + c1_kd;
                c1_r1->data[(c1_n - c1_d_k) - 1] = c1_b1 - c1_kd;
              }

              c1_l_b = c1_nm1d2;
              c1_m_y = c1_l_b << 1;
              if (c1_m_y == c1_nm1) {
                c1_r1->data[c1_nm1d2] = (c1_a1 + c1_b1) / 2.0;
              } else {
                c1_kd = (real_T)c1_nm1d2;
                c1_r1->data[c1_nm1d2] = c1_a1 + c1_kd;
                c1_r1->data[c1_nm1d2 + 1] = c1_b1 - c1_kd;
              }
            }
          }
        }
      }

      c1_sizeChunk = (real_T)c1_r1->size[1];
      c1_i28 = c1_Ex_chunk->size[0];
      c1_Ex_chunk->size[0] = (int32_T)c1_sizeChunk;
      c1_st.site = &c1_fl_emlrtRSI;
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_Ex_chunk, c1_i28,
        &c1_fb_emlrtRTEI);
      c1_i30 = c1_Ey_chunk->size[0];
      c1_Ey_chunk->size[0] = (int32_T)c1_sizeChunk;
      c1_st.site = &c1_el_emlrtRSI;
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_Ey_chunk, c1_i30,
        &c1_gb_emlrtRTEI);
      c1_i32 = c1_idxE_chunk->size[0];
      c1_idxE_chunk->size[0] = (int32_T)c1_sizeChunk;
      c1_st.site = &c1_dl_emlrtRSI;
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_idxE_chunk, c1_i32,
        &c1_hb_emlrtRTEI);
      c1_idxEdge = (int32_T)c1_c_i;
      c1_i33 = (int32_T)c1_sizeChunk - 1;
      for (c1_b_idx = 0; c1_b_idx <= c1_i33; c1_b_idx++) {
        c1_c_idx = (real_T)c1_b_idx + 1.0;
        c1_i35 = c1_Ex->size[0];
        c1_i36 = c1_Ex_chunk->size[0];
        c1_i37 = (int32_T)c1_c_idx;
        c1_Ex_chunk->data[emlrtDynamicBoundsCheckR2012b(c1_i37, 1, c1_i36,
          &c1_u_emlrtBCI, c1_sp) - 1] = c1_Ex->
          data[emlrtDynamicBoundsCheckR2012b(c1_idxEdge, 1, c1_i35,
          &c1_t_emlrtBCI, c1_sp) - 1];
        c1_i38 = c1_Ey->size[0];
        c1_i40 = c1_Ey_chunk->size[0];
        c1_i41 = (int32_T)c1_c_idx;
        c1_Ey_chunk->data[emlrtDynamicBoundsCheckR2012b(c1_i41, 1, c1_i40,
          &c1_w_emlrtBCI, c1_sp) - 1] = c1_Ey->
          data[emlrtDynamicBoundsCheckR2012b(c1_idxEdge, 1, c1_i38,
          &c1_v_emlrtBCI, c1_sp) - 1];
        c1_i42 = c1_idxE->size[0];
        c1_i43 = c1_idxE_chunk->size[0];
        c1_i45 = (int32_T)c1_c_idx;
        c1_idxE_chunk->data[emlrtDynamicBoundsCheckR2012b(c1_i45, 1, c1_i43,
          &c1_y_emlrtBCI, c1_sp) - 1] = c1_idxE->
          data[emlrtDynamicBoundsCheckR2012b(c1_idxEdge, 1, c1_i42,
          &c1_x_emlrtBCI, c1_sp) - 1];
        c1_idxEdge++;
      }

      c1_dim1 = (real_T)c1_idxE_chunk->size[0];
      c1_i34 = c1_xc->size[0] * c1_xc->size[1];
      c1_xc->size[0] = (int32_T)c1_dim1;
      c1_xc->size[1] = 51;
      c1_st.site = &c1_dm_emlrtRSI;
      c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_xc, c1_i34,
        &c1_ib_emlrtRTEI);
      c1_i39 = c1_yc->size[0] * c1_yc->size[1];
      c1_yc->size[0] = (int32_T)c1_dim1;
      c1_yc->size[1] = 51;
      c1_st.site = &c1_cm_emlrtRSI;
      c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_yc, c1_i39,
        &c1_jb_emlrtRTEI);
      c1_i44 = c1_w->size[0] * c1_w->size[1];
      c1_w->size[0] = (int32_T)c1_dim1;
      c1_w->size[1] = 51;
      c1_st.site = &c1_em_emlrtRSI;
      c1_emxEnsureCapacity_creal_T1(chartInstance, &c1_st, c1_w, c1_i44,
        &c1_kb_emlrtRTEI);
      c1_i46 = c1_inside->size[0] * c1_inside->size[1];
      c1_inside->size[0] = (int32_T)c1_dim1;
      c1_inside->size[1] = 51;
      c1_st.site = &c1_sl_emlrtRSI;
      c1_emxEnsureCapacity_boolean_T(chartInstance, &c1_st, c1_inside, c1_i46,
        &c1_lb_emlrtRTEI);
      c1_rows_to_keep_size[0] = (int32_T)c1_dim1;
      c1_h_loop_ub = (int32_T)c1_dim1 - 1;
      for (c1_i48 = 0; c1_i48 <= c1_h_loop_ub; c1_i48++) {
        c1_rows_to_keep_data[c1_i48] = false;
      }

      for (c1_idx2 = 0; c1_idx2 < 51; c1_idx2++) {
        c1_b_idx2 = (real_T)c1_idx2 + 1.0;
        c1_i50 = (int32_T)c1_dim1 - 1;
        for (c1_idx1 = 0; c1_idx1 <= c1_i50; c1_idx1++) {
          c1_b_idx1 = (real_T)c1_idx1 + 1.0;
          c1_i53 = c1_idxE_chunk->size[0];
          c1_i54 = (int32_T)c1_b_idx1;
          c1_y_x = chartInstance->c1_Gx[(int32_T)c1_idxE_chunk->
            data[emlrtDynamicBoundsCheckR2012b(c1_i54, 1, c1_i53,
            &c1_ab_emlrtBCI, c1_sp) - 1] - 1];
          c1_i56 = c1_idxE_chunk->size[0];
          c1_i57 = (int32_T)c1_b_idx1;
          c1_j_y = c1_b_gradientImg[(int32_T)c1_idxE_chunk->
            data[emlrtDynamicBoundsCheckR2012b(c1_i57, 1, c1_i56,
            &c1_bb_emlrtBCI, c1_sp) - 1] - 1];
          c1_ab_x = c1_y_x;
          c1_k_y = c1_j_y;
          c1_z = c1_ab_x / c1_k_y;
          c1_m_a = -(15.0 + 0.5 * (real_T)((int32_T)c1_b_idx2 - 1));
          c1_k_b = c1_z;
          c1_l_y = (real32_T)c1_m_a * c1_k_b;
          c1_i60 = c1_Ex_chunk->size[0];
          c1_i61 = (int32_T)c1_b_idx1;
          c1_bb_x = (real32_T)c1_Ex_chunk->data[emlrtDynamicBoundsCheckR2012b
            (c1_i61, 1, c1_i60, &c1_cb_emlrtBCI, c1_sp) - 1] + c1_l_y;
          if (c1_bb_x > 0.0F) {
            c1_n_y = c1_bb_x + 0.5F;
          } else if (c1_bb_x < 0.0F) {
            c1_n_y = c1_bb_x - 0.5F;
          } else {
            c1_n_y = 0.0F;
          }

          c1_i65 = c1_xc->size[0];
          c1_i66 = (int32_T)c1_b_idx1;
          c1_xc->data[(emlrtDynamicBoundsCheckR2012b(c1_i66, 1, c1_i65,
            &c1_fb_emlrtBCI, c1_sp) + c1_xc->size[0] * ((int32_T)c1_b_idx2 - 1))
            - 1] = c1_n_y;
          c1_i68 = c1_idxE_chunk->size[0];
          c1_i70 = (int32_T)c1_b_idx1;
          c1_cb_x = chartInstance->c1_Gy[(int32_T)c1_idxE_chunk->
            data[emlrtDynamicBoundsCheckR2012b(c1_i70, 1, c1_i68,
            &c1_ib_emlrtBCI, c1_sp) - 1] - 1];
          c1_i73 = c1_idxE_chunk->size[0];
          c1_i76 = (int32_T)c1_b_idx1;
          c1_o_y = c1_b_gradientImg[(int32_T)c1_idxE_chunk->
            data[emlrtDynamicBoundsCheckR2012b(c1_i76, 1, c1_i73,
            &c1_jb_emlrtBCI, c1_sp) - 1] - 1];
          c1_db_x = c1_cb_x;
          c1_p_y = c1_o_y;
          c1_b_z = c1_db_x / c1_p_y;
          c1_n_a = -(15.0 + 0.5 * (real_T)((int32_T)c1_b_idx2 - 1));
          c1_o_b = c1_b_z;
          c1_q_y = (real32_T)c1_n_a * c1_o_b;
          c1_i91 = c1_Ey_chunk->size[0];
          c1_i93 = (int32_T)c1_b_idx1;
          c1_eb_x = (real32_T)c1_Ey_chunk->data[emlrtDynamicBoundsCheckR2012b
            (c1_i93, 1, c1_i91, &c1_vb_emlrtBCI, c1_sp) - 1] + c1_q_y;
          if (c1_eb_x > 0.0F) {
            c1_r_y = c1_eb_x + 0.5F;
          } else if (c1_eb_x < 0.0F) {
            c1_r_y = c1_eb_x - 0.5F;
          } else {
            c1_r_y = 0.0F;
          }

          c1_i100 = c1_yc->size[0];
          c1_i102 = (int32_T)c1_b_idx1;
          c1_yc->data[(emlrtDynamicBoundsCheckR2012b(c1_i102, 1, c1_i100,
            &c1_wb_emlrtBCI, c1_sp) + c1_yc->size[0] * ((int32_T)c1_b_idx2 - 1))
            - 1] = c1_r_y;
          c1_i105 = c1_w->size[0];
          c1_i107 = (int32_T)c1_b_idx1;
          c1_w->data[(emlrtDynamicBoundsCheckR2012b(c1_i107, 1, c1_i105,
            &c1_xb_emlrtBCI, c1_sp) + c1_w->size[0] * ((int32_T)c1_b_idx2 - 1))
            - 1].re = c1_w0[(int32_T)c1_b_idx2 - 1].re;
          c1_i108 = c1_w->size[0];
          c1_i109 = (int32_T)c1_b_idx1;
          c1_w->data[(emlrtDynamicBoundsCheckR2012b(c1_i109, 1, c1_i108,
            &c1_xb_emlrtBCI, c1_sp) + c1_w->size[0] * ((int32_T)c1_b_idx2 - 1))
            - 1].im = c1_w0[(int32_T)c1_b_idx2 - 1].im;
          c1_i110 = c1_xc->size[0];
          c1_i111 = (int32_T)c1_b_idx1;
          c1_p_b = (c1_xc->data[(emlrtDynamicBoundsCheckR2012b(c1_i111, 1,
                      c1_i110, &c1_yb_emlrtBCI, c1_sp) + c1_xc->size[0] *
                     ((int32_T)c1_b_idx2 - 1)) - 1] >= 1.0F);
          c1_i112 = c1_xc->size[0];
          c1_i113 = (int32_T)c1_b_idx1;
          c1_b_b1 = (c1_xc->data[(emlrtDynamicBoundsCheckR2012b(c1_i113, 1,
            c1_i112, &c1_ac_emlrtBCI, c1_sp) + c1_xc->size[0] * ((int32_T)
            c1_b_idx2 - 1)) - 1] <= 160.0F);
          c1_b2 = (c1_p_b && c1_b_b1);
          c1_i114 = c1_yc->size[0];
          c1_i115 = (int32_T)c1_b_idx1;
          c1_b3 = (c1_yc->data[(emlrtDynamicBoundsCheckR2012b(c1_i115, 1,
                     c1_i114, &c1_bc_emlrtBCI, c1_sp) + c1_yc->size[0] *
                                ((int32_T)c1_b_idx2 - 1)) - 1] >= 1.0F);
          c1_b4 = (c1_b2 && c1_b3);
          c1_i116 = c1_yc->size[0];
          c1_i117 = (int32_T)c1_b_idx1;
          c1_b5 = (c1_yc->data[(emlrtDynamicBoundsCheckR2012b(c1_i117, 1,
                     c1_i116, &c1_cc_emlrtBCI, c1_sp) + c1_yc->size[0] *
                                ((int32_T)c1_b_idx2 - 1)) - 1] < 120.0F);
          c1_i118 = c1_inside->size[0];
          c1_i119 = (int32_T)c1_b_idx1;
          c1_inside->data[(emlrtDynamicBoundsCheckR2012b(c1_i119, 1, c1_i118,
            &c1_dc_emlrtBCI, c1_sp) + c1_inside->size[0] * ((int32_T)c1_b_idx2 -
            1)) - 1] = (c1_b4 && c1_b5);
          c1_i120 = c1_inside->size[0];
          c1_i121 = (int32_T)c1_b_idx1;
          if (c1_inside->data[(emlrtDynamicBoundsCheckR2012b(c1_i121, 1, c1_i120,
                &c1_ec_emlrtBCI, c1_sp) + c1_inside->size[0] * ((int32_T)
                c1_b_idx2 - 1)) - 1]) {
            c1_i122 = (int32_T)c1_b_idx1;
            c1_rows_to_keep_data[emlrtDynamicBoundsCheckR2012b(c1_i122, 1,
              c1_rows_to_keep_size[0], &c1_fc_emlrtBCI, c1_sp) - 1] = true;
          }
        }
      }

      c1_i49 = c1_xckeep->size[0];
      c1_xckeep->size[0] = c1_xc->size[0] * 51;
      c1_st.site = &c1_bm_emlrtRSI;
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_xckeep, c1_i49,
        &c1_nb_emlrtRTEI);
      c1_i51 = c1_yckeep->size[0];
      c1_yckeep->size[0] = c1_yc->size[0] * 51;
      c1_st.site = &c1_am_emlrtRSI;
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_yckeep, c1_i51,
        &c1_ob_emlrtRTEI);
      c1_i55 = c1_wkeep->size[0];
      c1_wkeep->size[0] = c1_w->size[0] * 51;
      c1_st.site = &c1_kl_emlrtRSI;
      c1_emxEnsureCapacity_creal_T(chartInstance, &c1_st, c1_wkeep, c1_i55,
        &c1_pb_emlrtRTEI);
      c1_idxkeep = 0;
      for (c1_c_idx2 = 0; c1_c_idx2 < 51; c1_c_idx2++) {
        c1_b_idx2 = (real_T)c1_c_idx2 + 1.0;
        c1_i58 = (int32_T)c1_dim1 - 1;
        for (c1_c_idx1 = 0; c1_c_idx1 <= c1_i58; c1_c_idx1++) {
          c1_b_idx1 = (real_T)c1_c_idx1 + 1.0;
          c1_i62 = (int32_T)c1_b_idx1;
          if (c1_rows_to_keep_data[emlrtDynamicBoundsCheckR2012b(c1_i62, 1,
               c1_rows_to_keep_size[0], &c1_db_emlrtBCI, c1_sp) - 1]) {
            c1_i63 = c1_inside->size[0];
            c1_i64 = (int32_T)c1_b_idx1;
            if (c1_inside->data[(emlrtDynamicBoundsCheckR2012b(c1_i64, 1, c1_i63,
                  &c1_eb_emlrtBCI, c1_sp) + c1_inside->size[0] * ((int32_T)
                  c1_b_idx2 - 1)) - 1]) {
              c1_idxkeep++;
              c1_i67 = c1_xc->size[0];
              c1_i69 = (int32_T)c1_b_idx1;
              c1_i71 = c1_xckeep->size[0];
              c1_xckeep->data[emlrtDynamicBoundsCheckR2012b(c1_idxkeep, 1,
                c1_i71, &c1_hb_emlrtBCI, c1_sp) - 1] = (int32_T)c1_xc->data
                [(emlrtDynamicBoundsCheckR2012b(c1_i69, 1, c1_i67,
                   &c1_gb_emlrtBCI, c1_sp) + c1_xc->size[0] * ((int32_T)
                   c1_b_idx2 - 1)) - 1];
              c1_i75 = c1_yc->size[0];
              c1_i78 = (int32_T)c1_b_idx1;
              c1_i80 = c1_yckeep->size[0];
              c1_yckeep->data[emlrtDynamicBoundsCheckR2012b(c1_idxkeep, 1,
                c1_i80, &c1_lb_emlrtBCI, c1_sp) - 1] = (int32_T)c1_yc->data
                [(emlrtDynamicBoundsCheckR2012b(c1_i78, 1, c1_i75,
                   &c1_kb_emlrtBCI, c1_sp) + c1_yc->size[0] * ((int32_T)
                   c1_b_idx2 - 1)) - 1];
              c1_i83 = c1_wkeep->size[0];
              c1_i85 = c1_w->size[0];
              c1_i87 = (int32_T)c1_b_idx1;
              c1_wkeep->data[emlrtDynamicBoundsCheckR2012b(c1_idxkeep, 1, c1_i83,
                &c1_nb_emlrtBCI, c1_sp) - 1].re = c1_w->data
                [(emlrtDynamicBoundsCheckR2012b(c1_i87, 1, c1_i85,
                   &c1_mb_emlrtBCI, c1_sp) + c1_w->size[0] * ((int32_T)c1_b_idx2
                   - 1)) - 1].re;
              c1_i90 = c1_w->size[0];
              c1_i92 = (int32_T)c1_b_idx1;
              c1_i95 = c1_wkeep->size[0];
              c1_wkeep->data[emlrtDynamicBoundsCheckR2012b(c1_idxkeep, 1, c1_i95,
                &c1_nb_emlrtBCI, c1_sp) - 1].im = c1_w->data
                [(emlrtDynamicBoundsCheckR2012b(c1_i92, 1, c1_i90,
                   &c1_mb_emlrtBCI, c1_sp) + c1_w->size[0] * ((int32_T)c1_b_idx2
                   - 1)) - 1].im;
            }
          }
        }
      }

      c1_st.site = &c1_sc_emlrtRSI;
      c1_szxc = c1_idxkeep;
      for (c1_i59 = 0; c1_i59 < 19200; c1_i59++) {
        chartInstance->c1_out[c1_i59].re = 0.0;
        chartInstance->c1_out[c1_i59].im = 0.0;
      }

      c1_b_st.site = &c1_bg_emlrtRSI;
      c1_m_b = c1_szxc;
      c1_n_b = c1_m_b;
      if (1 > c1_n_b) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_n_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_c_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_d_idx = 1; c1_d_idx - 1 < c1_szxc; c1_d_idx++) {
        c1_e_idx = c1_d_idx;
        c1_i74 = c1_yckeep->size[0];
        c1_i77 = c1_yckeep->data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1,
          c1_i74, &c1_tb_emlrtBCI, &c1_st) - 1];
        c1_i79 = c1_xckeep->size[0];
        c1_i81 = c1_xckeep->data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1,
          c1_i79, &c1_tb_emlrtBCI, &c1_st) - 1];
        c1_i82 = c1_yckeep->size[0];
        c1_i84 = c1_yckeep->data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1,
          c1_i82, &c1_pb_emlrtBCI, &c1_st) - 1];
        c1_i86 = c1_xckeep->size[0];
        c1_i88 = c1_xckeep->data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1,
          c1_i86, &c1_pb_emlrtBCI, &c1_st) - 1];
        c1_i89 = c1_wkeep->size[0];
        chartInstance->c1_out[(emlrtDynamicBoundsCheckR2012b(c1_i77, 1, 120,
          &c1_sb_emlrtBCI, &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c1_i81,
          1, 160, &c1_ub_emlrtBCI, &c1_st) - 1)) - 1].re = chartInstance->
          c1_out[(emlrtDynamicBoundsCheckR2012b(c1_i84, 1, 120, &c1_ob_emlrtBCI,
                   &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c1_i88, 1, 160,
                    &c1_qb_emlrtBCI, &c1_st) - 1)) - 1].re + c1_wkeep->
          data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i89,
          &c1_rb_emlrtBCI, &c1_st) - 1].re;
        c1_i94 = c1_yckeep->size[0];
        c1_i96 = c1_yckeep->data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1,
          c1_i94, &c1_pb_emlrtBCI, &c1_st) - 1];
        c1_i97 = c1_xckeep->size[0];
        c1_i98 = c1_xckeep->data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1,
          c1_i97, &c1_pb_emlrtBCI, &c1_st) - 1];
        c1_i99 = c1_wkeep->size[0];
        c1_i101 = c1_yckeep->size[0];
        c1_i103 = c1_yckeep->data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1,
          c1_i101, &c1_tb_emlrtBCI, &c1_st) - 1];
        c1_i104 = c1_xckeep->size[0];
        c1_i106 = c1_xckeep->data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1,
          c1_i104, &c1_tb_emlrtBCI, &c1_st) - 1];
        chartInstance->c1_out[(emlrtDynamicBoundsCheckR2012b(c1_i103, 1, 120,
          &c1_sb_emlrtBCI, &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b
          (c1_i106, 1, 160, &c1_ub_emlrtBCI, &c1_st) - 1)) - 1].im =
          chartInstance->c1_out[(emlrtDynamicBoundsCheckR2012b(c1_i96, 1, 120,
          &c1_ob_emlrtBCI, &c1_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c1_i98,
          1, 160, &c1_qb_emlrtBCI, &c1_st) - 1)) - 1].im + c1_wkeep->
          data[emlrtDynamicBoundsCheckR2012b(c1_e_idx, 1, c1_i99,
          &c1_rb_emlrtBCI, &c1_st) - 1].im;
      }

      for (c1_i72 = 0; c1_i72 < 19200; c1_i72++) {
        c1_c_accumMatrix[c1_i72].re += chartInstance->c1_out[c1_i72].re;
        c1_c_accumMatrix[c1_i72].im += chartInstance->c1_out[c1_i72].im;
      }

      c1_b_i++;
    }

    c1_emxFree_real_T(chartInstance, &c1_Ex);
    c1_emxFree_real_T(chartInstance, &c1_Ey);
    c1_emxFree_real_T(chartInstance, &c1_r1);
    c1_emxFree_creal_T(chartInstance, &c1_wkeep);
    c1_emxFree_int32_T(chartInstance, &c1_yckeep);
    c1_emxFree_int32_T(chartInstance, &c1_xckeep);
    c1_emxFree_boolean_T(chartInstance, &c1_inside);
    c1_emxFree_creal_T(chartInstance, &c1_w);
    c1_emxFree_real32_T(chartInstance, &c1_yc);
    c1_emxFree_real32_T(chartInstance, &c1_xc);
    c1_emxFree_real_T(chartInstance, &c1_idxE_chunk);
    c1_emxFree_real_T(chartInstance, &c1_Ey_chunk);
    c1_emxFree_real_T(chartInstance, &c1_Ex_chunk);
    c1_emxFree_real_T(chartInstance, &c1_idxE);
  }
}

static real32_T c1_multithresh(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real32_T c1_d_varargin_1[19200])
{
  c1_emxArray_int32_T *c1_r;
  c1_emxArray_real32_T *c1_b_threshout;
  c1_emxArray_real32_T *c1_img;
  c1_emxArray_real32_T *c1_threshL;
  c1_emxArray_real32_T *c1_uniqueVals;
  c1_emxArray_real_T *c1_b_uniqueVals_d;
  c1_emxArray_real_T *c1_d_uniqueVals_d;
  c1_emxArray_real_T *c1_r1;
  c1_emxArray_real_T *c1_threshRaw;
  c1_emxArray_real_T *c1_uniqueVals_d;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  real_T c1_b_counts[256];
  real_T c1_c_counts[256];
  real_T c1_counts[256];
  real_T c1_d_counts[256];
  real_T c1_mu[256];
  real_T c1_omega[256];
  real_T c1_b_ind;
  real_T c1_b_lenThreshOrig;
  real_T c1_b_mu_t;
  real_T c1_b_numElems;
  real_T c1_b_q;
  real_T c1_b_thNeeded1;
  real_T c1_b_thNeeded2;
  real_T c1_b_threshCandidate_d;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_h_a;
  real_T c1_idxNum;
  real_T c1_idxSum;
  real_T c1_lenThreshOrig;
  real_T c1_m_x;
  real_T c1_maxval;
  real_T c1_mu_t;
  real_T c1_n_b;
  real_T c1_n_x;
  real_T c1_numElems;
  real_T c1_o_b;
  real_T c1_o_x;
  real_T c1_q;
  real_T c1_thNeeded1;
  real_T c1_thNeeded2;
  real_T c1_threshCandidate_d;
  int32_T c1_b_tmp_size[2];
  int32_T c1_c_tmp_size[2];
  int32_T c1_d_tmp_size[2];
  int32_T c1_tmp_size[2];
  int32_T c1_y_size[2];
  int32_T c1_Auint8_size[1];
  int32_T c1_c_uniqueVals_d[1];
  int32_T c1_e_tmp_size[1];
  int32_T c1_e_uniqueVals_d[1];
  int32_T c1_f_tmp_size[1];
  int32_T c1_g_tmp_size[1];
  int32_T c1_h_tmp_size[1];
  int32_T c1_ab_loop_ub;
  int32_T c1_b_i;
  int32_T c1_b_idx;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_b_trueCount;
  int32_T c1_bb_loop_ub;
  int32_T c1_c_i;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_cb_loop_ub;
  int32_T c1_d_i;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_db_loop_ub;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_eb_loop_ub;
  int32_T c1_f_loop_ub;
  int32_T c1_fb_loop_ub;
  int32_T c1_g_loop_ub;
  int32_T c1_gb_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_hb_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  int32_T c1_i104;
  int32_T c1_i105;
  int32_T c1_i106;
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  int32_T c1_i11;
  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i9;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i_loop_ub;
  int32_T c1_ib_loop_ub;
  int32_T c1_ind;
  int32_T c1_j_loop_ub;
  int32_T c1_jb_loop_ub;
  int32_T c1_k;
  int32_T c1_k_loop_ub;
  int32_T c1_kb_loop_ub;
  int32_T c1_l_loop_ub;
  int32_T c1_loop_ub;
  int32_T c1_m_loop_ub;
  int32_T c1_n_loop_ub;
  int32_T c1_o_loop_ub;
  int32_T c1_p_loop_ub;
  int32_T c1_partialTrueCount;
  int32_T c1_q_loop_ub;
  int32_T c1_r_loop_ub;
  int32_T c1_s_loop_ub;
  int32_T c1_t_loop_ub;
  int32_T c1_trueCount;
  int32_T c1_u_loop_ub;
  int32_T c1_v_loop_ub;
  int32_T c1_w_loop_ub;
  int32_T c1_x_loop_ub;
  int32_T c1_y_loop_ub;
  real32_T c1_y_data[1];
  real32_T c1_ab_x;
  real32_T c1_b_d;
  real32_T c1_b_maxA;
  real32_T c1_b_minA;
  real32_T c1_b_minval;
  real32_T c1_b_threshCandidate;
  real32_T c1_b_varargin_2;
  real32_T c1_b_y;
  real32_T c1_bb_x;
  real32_T c1_c_d;
  real32_T c1_c_maxA;
  real32_T c1_c_minA;
  real32_T c1_c_varargin_2;
  real32_T c1_c_x;
  real32_T c1_c_y;
  real32_T c1_cb_x;
  real32_T c1_d_minA;
  real32_T c1_d_x;
  real32_T c1_d_y;
  real32_T c1_db_x;
  real32_T c1_e_varargin_1;
  real32_T c1_e_x;
  real32_T c1_e_y;
  real32_T c1_eb_x;
  real32_T c1_f_varargin_1;
  real32_T c1_f_x;
  real32_T c1_f_y;
  real32_T c1_fb_x;
  real32_T c1_g_a;
  real32_T c1_g_x;
  real32_T c1_g_y;
  real32_T c1_gb_x;
  real32_T c1_h_x;
  real32_T c1_h_y;
  real32_T c1_hb_x;
  real32_T c1_i_x;
  real32_T c1_i_y;
  real32_T c1_ib_x;
  real32_T c1_j_x;
  real32_T c1_j_y;
  real32_T c1_jb_x;
  real32_T c1_k_x;
  real32_T c1_k_y;
  real32_T c1_l_x;
  real32_T c1_l_y;
  real32_T c1_m_y;
  real32_T c1_maxA;
  real32_T c1_minA;
  real32_T c1_minval;
  real32_T c1_n_y;
  real32_T c1_p_b;
  real32_T c1_p_x;
  real32_T c1_q_x;
  real32_T c1_r_b;
  real32_T c1_r_x;
  real32_T c1_s_x;
  real32_T c1_t_x;
  real32_T c1_thresh;
  real32_T c1_threshCandidate;
  real32_T c1_threshout;
  real32_T c1_u_x;
  real32_T c1_v_x;
  real32_T c1_w_x;
  real32_T c1_x_x;
  real32_T c1_y;
  real32_T c1_y_x;
  uint8_T c1_Auint8_data[19200];
  boolean_T c1_b_tmp_data[19200];
  boolean_T c1_c_tmp_data[19200];
  boolean_T c1_d_tmp_data[19200];
  boolean_T c1_e_tmp_data[19200];
  boolean_T c1_f_tmp_data[19200];
  boolean_T c1_nans[19200];
  boolean_T c1_tmp_data[19200];
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b6;
  boolean_T c1_b7;
  boolean_T c1_b8;
  boolean_T c1_b9;
  boolean_T c1_b_b;
  boolean_T c1_b_isDegenerate;
  boolean_T c1_c_b;
  boolean_T c1_d_b;
  boolean_T c1_e_b;
  boolean_T c1_emptyp;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_g_b;
  boolean_T c1_guard1 = false;
  boolean_T c1_h_b;
  boolean_T c1_i_b;
  boolean_T c1_isDegenerate;
  boolean_T c1_isvalid_maxval;
  boolean_T c1_j_b;
  boolean_T c1_k_b;
  boolean_T c1_l_b;
  boolean_T c1_m_b;
  boolean_T c1_q_b;
  boolean_T c1_s_b;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_st.site = &c1_wc_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    chartInstance->c1_c_A[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_emptyp = true;
  c1_b_idx = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_b_idx + 1 <= 19200)) {
    c1_c_x = chartInstance->c1_c_A[c1_b_idx];
    c1_d_x = c1_c_x;
    c1_b = muSingleScalarIsInf(c1_d_x);
    c1_b_b = !c1_b;
    c1_e_x = c1_c_x;
    c1_c_b = muSingleScalarIsNaN(c1_e_x);
    c1_b1 = !c1_c_b;
    c1_d_b = (c1_b_b && c1_b1);
    if (!c1_d_b) {
      c1_b_idx++;
    } else {
      c1_exitg1 = true;
    }
  }

  c1_emxInit_real32_T(chartInstance, &c1_st, &c1_img, 1, &c1_gc_emlrtRTEI);
  if (c1_b_idx + 1 <= 19200) {
    c1_minA = chartInstance->c1_c_A[c1_b_idx];
    c1_maxA = chartInstance->c1_c_A[c1_b_idx];
    c1_i2 = c1_b_idx;
    for (c1_k = c1_i2 + 2; c1_k < 19201; c1_k++) {
      c1_g_a = chartInstance->c1_c_A[c1_k - 1];
      c1_guard1 = false;
      if (c1_g_a < c1_minA) {
        c1_f_x = c1_g_a;
        c1_g_x = c1_f_x;
        c1_e_b = muSingleScalarIsInf(c1_g_x);
        c1_b2 = !c1_e_b;
        c1_j_x = c1_f_x;
        c1_g_b = muSingleScalarIsNaN(c1_j_x);
        c1_b3 = !c1_g_b;
        c1_i_b = (c1_b2 && c1_b3);
        if (c1_i_b) {
          c1_minA = c1_g_a;
        } else {
          c1_guard1 = true;
        }
      } else {
        c1_guard1 = true;
      }

      if (c1_guard1 && (c1_g_a > c1_maxA)) {
        c1_i_x = c1_g_a;
        c1_k_x = c1_i_x;
        c1_h_b = muSingleScalarIsInf(c1_k_x);
        c1_b4 = !c1_h_b;
        c1_l_x = c1_i_x;
        c1_j_b = muSingleScalarIsNaN(c1_l_x);
        c1_b5 = !c1_j_b;
        c1_k_b = (c1_b4 && c1_b5);
        if (c1_k_b) {
          c1_maxA = c1_g_a;
        }
      }
    }

    if (!(c1_minA == c1_maxA)) {
      for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
        chartInstance->c1_c_A[c1_i3] -= c1_minA;
      }

      c1_y = c1_maxA - c1_minA;
      c1_b_y = c1_y;
      for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
        chartInstance->c1_c_A[c1_i5] /= c1_b_y;
      }

      for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
        c1_nans[c1_i6] = muSingleScalarIsNaN(chartInstance->c1_c_A[c1_i6]);
      }

      c1_trueCount = 0;
      for (c1_b_i = 0; c1_b_i < 19200; c1_b_i++) {
        if (!c1_nans[c1_b_i]) {
          c1_trueCount++;
        }
      }

      if (c1_trueCount != 0) {
        c1_b_trueCount = 0;
        for (c1_c_i = 0; c1_c_i < 19200; c1_c_i++) {
          if (!c1_nans[c1_c_i]) {
            c1_b_trueCount++;
          }
        }

        c1_emxInit_int32_T(chartInstance, &c1_st, &c1_r, 1, &c1_fd_emlrtRTEI);
        c1_i10 = c1_r->size[0];
        c1_r->size[0] = c1_b_trueCount;
        c1_b_st.site = &c1_wc_emlrtRSI;
        c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_r, c1_i10,
          &c1_fc_emlrtRTEI);
        c1_partialTrueCount = 0;
        for (c1_d_i = 0; c1_d_i < 19200; c1_d_i++) {
          if (!c1_nans[c1_d_i]) {
            c1_r->data[c1_partialTrueCount] = c1_d_i + 1;
            c1_partialTrueCount++;
          }
        }

        c1_b_st.site = &c1_kd_emlrtRSI;
        c1_i13 = c1_img->size[0];
        c1_img->size[0] = c1_r->size[0];
        c1_emxEnsureCapacity_real32_T(chartInstance, &c1_b_st, c1_img, c1_i13,
          &c1_gc_emlrtRTEI);
        c1_loop_ub = c1_r->size[0] - 1;
        for (c1_i14 = 0; c1_i14 <= c1_loop_ub; c1_i14++) {
          c1_img->data[c1_i14] = chartInstance->c1_c_A[c1_r->data[c1_i14] - 1];
        }

        c1_emxFree_int32_T(chartInstance, &c1_r);
        c1_c_st.site = &c1_j_emlrtRSI;
        c1_Auint8_size[0] = c1_img->size[0];
        c1_numElems = (real_T)c1_img->size[0];
        c1_b_numElems = c1_numElems;
        grayto8_real32(&c1_img->data[0], &c1_Auint8_data[0], c1_b_numElems);
        c1_b_st.site = &c1_ld_emlrtRSI;
        c1_c_imhist(chartInstance, &c1_b_st, c1_Auint8_data, c1_Auint8_size,
                    c1_counts);
        for (c1_i15 = 0; c1_i15 < 256; c1_i15++) {
          c1_d_counts[c1_i15] = c1_counts[c1_i15];
        }

        c1_d = c1_sum(chartInstance, c1_d_counts);
        for (c1_i17 = 0; c1_i17 < 256; c1_i17++) {
          c1_mu[c1_i17] = c1_counts[c1_i17] / c1_d;
        }

        c1_emptyp = false;
      }
    }
  } else {
    c1_b_st.site = &c1_id_emlrtRSI;
    for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
      chartInstance->c1_b_varargin_1[c1_i1] = chartInstance->c1_c_A[c1_i1];
    }

    c1_c_st.site = &c1_md_emlrtRSI;
    c1_d_st.site = &c1_nd_emlrtRSI;
    c1_minA = c1_minimum(chartInstance, &c1_d_st, chartInstance->c1_b_varargin_1);
    c1_b_st.site = &c1_jd_emlrtRSI;
    c1_c_st.site = &c1_fc_emlrtRSI;
    c1_d_st.site = &c1_gc_emlrtRSI;
    c1_maxA = c1_maximum(chartInstance, &c1_d_st, chartInstance->c1_c_A);
  }

  if (c1_emptyp) {
    c1_st.site = &c1_xc_emlrtRSI;
    c1_b_warning(chartInstance, &c1_st);
    c1_b_minA = c1_minA;
    c1_h_x = c1_b_minA;
    c1_f_b = muSingleScalarIsNaN(c1_h_x);
    if (c1_f_b) {
      c1_b_minA = 1.0F;
    }

    c1_threshout = c1_b_minA;
    c1_thresh = c1_threshout;
  } else {
    for (c1_i4 = 0; c1_i4 < 256; c1_i4++) {
      c1_omega[c1_i4] = c1_mu[c1_i4];
    }

    for (c1_b_k = 0; c1_b_k < 255; c1_b_k++) {
      c1_c_k = c1_b_k;
      c1_omega[c1_c_k + 1] += c1_omega[c1_c_k];
    }

    for (c1_i7 = 0; c1_i7 < 256; c1_i7++) {
      c1_mu[c1_i7] *= 1.0 + (real_T)c1_i7;
    }

    for (c1_d_k = 0; c1_d_k < 255; c1_d_k++) {
      c1_e_k = c1_d_k;
      c1_mu[c1_e_k + 1] += c1_mu[c1_e_k];
    }

    c1_mu_t = c1_mu[255];
    c1_b_mu_t = c1_mu_t;
    c1_h_a = c1_b_mu_t;
    for (c1_i8 = 0; c1_i8 < 256; c1_i8++) {
      c1_counts[c1_i8] = c1_h_a * c1_omega[c1_i8];
    }

    for (c1_i9 = 0; c1_i9 < 256; c1_i9++) {
      c1_b_counts[c1_i9] = c1_counts[c1_i9] - c1_mu[c1_i9];
    }

    c1_power(chartInstance, c1_b_counts, c1_counts);
    for (c1_i11 = 0; c1_i11 < 256; c1_i11++) {
      c1_counts[c1_i11] /= c1_omega[c1_i11] * (1.0 - c1_omega[c1_i11]);
    }

    c1_st.site = &c1_yc_emlrtRSI;
    c1_b_st.site = &c1_fc_emlrtRSI;
    c1_c_st.site = &c1_gc_emlrtRSI;
    for (c1_i12 = 0; c1_i12 < 256; c1_i12++) {
      c1_c_counts[c1_i12] = c1_counts[c1_i12];
    }

    c1_maxval = c1_b_maximum(chartInstance, &c1_c_st, c1_c_counts);
    c1_m_x = c1_maxval;
    c1_n_x = c1_m_x;
    c1_l_b = muDoubleScalarIsInf(c1_n_x);
    c1_b6 = !c1_l_b;
    c1_o_x = c1_m_x;
    c1_m_b = muDoubleScalarIsNaN(c1_o_x);
    c1_b7 = !c1_m_b;
    c1_isvalid_maxval = (c1_b6 && c1_b7);
    c1_emxInit_real32_T1(chartInstance, c1_sp, &c1_b_threshout, 2,
                         &c1_dd_emlrtRTEI);
    c1_emxInit_real_T(chartInstance, c1_sp, &c1_threshRaw, 2, &c1_ic_emlrtRTEI);
    c1_emxInit_real32_T1(chartInstance, c1_sp, &c1_uniqueVals, 2,
                         &c1_ed_emlrtRTEI);
    c1_emxInit_real32_T1(chartInstance, c1_sp, &c1_threshL, 2, &c1_yc_emlrtRTEI);
    c1_emxInit_real_T(chartInstance, c1_sp, &c1_uniqueVals_d, 2,
                      &c1_xc_emlrtRTEI);
    c1_emxInit_real_T1(chartInstance, c1_sp, &c1_r1, 1, &c1_cd_emlrtRTEI);
    if (c1_isvalid_maxval) {
      c1_idxSum = 0.0;
      c1_idxNum = 0.0;
      for (c1_ind = 0; c1_ind < 256; c1_ind++) {
        c1_b_ind = (real_T)c1_ind + 1.0;
        if (c1_counts[(int32_T)c1_b_ind - 1] == c1_maxval) {
          c1_idxSum += c1_b_ind;
          c1_idxNum++;
        }
      }

      c1_i18 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
      c1_threshRaw->size[0] = 1;
      c1_threshRaw->size[1] = 1;
      c1_st.site = &c1_ol_emlrtRSI;
      c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_threshRaw, c1_i18,
        &c1_ic_emlrtRTEI);
      c1_threshRaw->data[0] = c1_idxSum / c1_idxNum - 1.0;
    } else {
      c1_st.site = &c1_ad_emlrtRSI;
      c1_b_st.site = &c1_xd_emlrtRSI;
      for (c1_i16 = 0; c1_i16 < 19200; c1_i16++) {
        chartInstance->c1_b_varargin_1[c1_i16] = c1_d_varargin_1[c1_i16];
      }

      c1_c_st.site = &c1_ae_emlrtRSI;
      c1_unique_vector(chartInstance, &c1_c_st, chartInstance->c1_b_varargin_1,
                       c1_img);
      c1_i19 = c1_uniqueVals->size[0] * c1_uniqueVals->size[1];
      c1_uniqueVals->size[0] = 1;
      c1_uniqueVals->size[1] = c1_img->size[0];
      c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_uniqueVals,
        c1_i19, &c1_jc_emlrtRTEI);
      c1_b_loop_ub = c1_img->size[0] - 1;
      for (c1_i20 = 0; c1_i20 <= c1_b_loop_ub; c1_i20++) {
        c1_uniqueVals->data[c1_i20] = c1_img->data[c1_i20];
      }

      c1_tmp_size[0] = 1;
      c1_tmp_size[1] = c1_uniqueVals->size[1];
      c1_c_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
      for (c1_i24 = 0; c1_i24 <= c1_c_loop_ub; c1_i24++) {
        c1_tmp_data[c1_i24] = muSingleScalarIsInf(c1_uniqueVals->data[c1_i24]);
      }

      c1_b_tmp_size[0] = 1;
      c1_b_tmp_size[1] = c1_uniqueVals->size[1];
      c1_e_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
      for (c1_i28 = 0; c1_i28 <= c1_e_loop_ub; c1_i28++) {
        c1_b_tmp_data[c1_i28] = muSingleScalarIsNaN(c1_uniqueVals->data[c1_i28]);
      }

      emlrtSizeEqCheckNDR2012b(c1_tmp_size, c1_b_tmp_size, &c1_emlrtECI, &c1_st);
      c1_c_tmp_size[0] = 1;
      c1_c_tmp_size[1] = c1_tmp_size[1];
      c1_g_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
      for (c1_i32 = 0; c1_i32 <= c1_g_loop_ub; c1_i32++) {
        c1_c_tmp_data[c1_i32] = (c1_tmp_data[c1_i32] || c1_b_tmp_data[c1_i32]);
      }

      c1_b_st.site = &c1_yd_emlrtRSI;
      c1_b_nullAssignment(chartInstance, &c1_b_st, c1_uniqueVals, c1_c_tmp_data,
                          c1_c_tmp_size);
      c1_isDegenerate = ((real_T)c1_uniqueVals->size[1] <= 1.0);
      if (c1_isDegenerate) {
        c1_st.site = &c1_bd_emlrtRSI;
        c1_b_warning(chartInstance, &c1_st);
      } else {
        c1_st.site = &c1_cd_emlrtRSI;
        c1_c_warning(chartInstance, &c1_st);
      }

      c1_st.site = &c1_dd_emlrtRSI;
      c1_b8 = (c1_uniqueVals->size[1] == 0);
      if (c1_b8) {
        c1_i41 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
        c1_b_threshout->size[0] = 1;
        c1_b_threshout->size[1] = 1;
        c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_b_threshout,
          c1_i41, &c1_pc_emlrtRTEI);
        c1_b_threshout->data[0] = 1.0F;
      } else {
        c1_thNeeded1 = 1.0 - (real_T)c1_uniqueVals->size[1];
        if (c1_thNeeded1 > 0.0) {
          c1_i45 = c1_uniqueVals->size[1];
          c1_i46 = 1;
          emlrtDynamicBoundsCheckR2012b(c1_i46, 1, c1_i45, &c1_ic_emlrtBCI,
            &c1_st);
          if (c1_uniqueVals->data[0] > 1.0F) {
            c1_i49 = c1_uniqueVals->size[1];
            c1_i52 = 1;
            emlrtDynamicBoundsCheckR2012b(c1_i52, 1, c1_i49, &c1_hc_emlrtBCI,
              &c1_st);
            c1_p_x = c1_uniqueVals->data[0];
            c1_q_x = c1_p_x;
            c1_q_x = muSingleScalarCeil(c1_q_x);
            c1_b_varargin_2 = c1_q_x - 1.0F;
            c1_c_y = c1_b_varargin_2;
            c1_d_y = c1_c_y;
            c1_e_y = c1_d_y;
            c1_f_y = c1_e_y;
            c1_g_y = c1_f_y;
            c1_h_y = c1_g_y;
            c1_minval = muSingleScalarMin(1.0F, c1_h_y);
            c1_b_d = c1_minval;
            c1_p_b = c1_b_d;
            c1_t_x = c1_p_b;
            c1_q_b = muSingleScalarIsNaN(c1_t_x);
            if (c1_q_b) {
              c1_y_size[1] = 1;
              c1_y_data[0] = rtNaNF;
            } else if (c1_p_b < 1.0F) {
              c1_y_size[1] = 0;
            } else {
              c1_y_size[1] = 1;
              c1_y_data[0] = 1.0F;
            }

            c1_i81 = c1_threshL->size[0] * c1_threshL->size[1];
            c1_threshL->size[0] = 1;
            c1_threshL->size[1] = c1_y_size[1] + c1_uniqueVals->size[1];
            c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_threshL,
              c1_i81, &c1_yc_emlrtRTEI);
            c1_y_loop_ub = c1_y_size[1] - 1;
            for (c1_i89 = 0; c1_i89 <= c1_y_loop_ub; c1_i89++) {
              c1_threshL->data[c1_i89] = c1_y_data[c1_i89];
            }

            c1_cb_loop_ub = c1_uniqueVals->size[1] - 1;
            for (c1_i93 = 0; c1_i93 <= c1_cb_loop_ub; c1_i93++) {
              c1_threshL->data[c1_i93 + c1_y_size[1]] = c1_uniqueVals->
                data[c1_i93];
            }
          } else {
            c1_i48 = c1_threshL->size[0] * c1_threshL->size[1];
            c1_threshL->size[0] = 1;
            c1_threshL->size[1] = c1_uniqueVals->size[1];
            c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_threshL,
              c1_i48, &c1_rc_emlrtRTEI);
            c1_o_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
            for (c1_i54 = 0; c1_i54 <= c1_o_loop_ub; c1_i54++) {
              c1_threshL->data[c1_i54] = c1_uniqueVals->data[c1_i54];
            }
          }

          c1_thNeeded2 = 1.0 - (real_T)c1_threshL->size[1];
          if (c1_thNeeded2 > 0.0) {
            c1_lenThreshOrig = (real_T)c1_threshL->size[1];
            c1_i66 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
            c1_b_threshout->size[0] = 1;
            c1_b_threshout->size[1] = c1_threshL->size[1] + 1;
            c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_b_threshout,
              c1_i66, &c1_vc_emlrtRTEI);
            c1_t_loop_ub = c1_threshL->size[1] - 1;
            for (c1_i74 = 0; c1_i74 <= c1_t_loop_ub; c1_i74++) {
              c1_b_threshout->data[c1_i74] = c1_threshL->data[c1_i74];
            }

            c1_b_threshout->data[c1_threshL->size[1]] = 0.0F;
            c1_i77 = c1_uniqueVals_d->size[0] * c1_uniqueVals_d->size[1];
            c1_uniqueVals_d->size[0] = 1;
            c1_uniqueVals_d->size[1] = c1_uniqueVals->size[1];
            c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_uniqueVals_d,
              c1_i77, &c1_xc_emlrtRTEI);
            c1_w_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
            for (c1_i84 = 0; c1_i84 <= c1_w_loop_ub; c1_i84++) {
              c1_uniqueVals_d->data[c1_i84] = c1_uniqueVals->data[c1_i84];
            }

            c1_i86 = c1_uniqueVals->size[1];
            c1_i88 = 1;
            emlrtDynamicBoundsCheckR2012b(c1_i88, 1, c1_i86, &c1_gc_emlrtBCI,
              &c1_st);
            c1_v_x = c1_uniqueVals->data[0];
            c1_e_varargin_1 = c1_v_x;
            c1_e_varargin_1 = muSingleScalarFloor(c1_e_varargin_1);
            c1_w_x = c1_e_varargin_1;
            c1_x_x = c1_w_x;
            c1_y_x = c1_x_x;
            c1_ab_x = c1_y_x;
            c1_bb_x = c1_ab_x;
            c1_cb_x = c1_bb_x;
            c1_threshCandidate = muSingleScalarMax(c1_cb_x, 0.0F);
            c1_q = 1.0;
            c1_emxInit_real_T1(chartInstance, &c1_st, &c1_b_uniqueVals_d, 1,
                               &c1_bd_emlrtRTEI);
            while (c1_q <= 1.0) {
              c1_threshCandidate++;
              c1_threshCandidate_d = c1_threshCandidate;
              c1_c_uniqueVals_d[0] = c1_uniqueVals_d->size[1];
              c1_i102 = c1_b_uniqueVals_d->size[0];
              c1_b_uniqueVals_d->size[0] = c1_c_uniqueVals_d[0];
              c1_emxEnsureCapacity_real_T(chartInstance, &c1_st,
                c1_b_uniqueVals_d, c1_i102, &c1_bd_emlrtRTEI);
              c1_hb_loop_ub = c1_c_uniqueVals_d[0] - 1;
              for (c1_i103 = 0; c1_i103 <= c1_hb_loop_ub; c1_i103++) {
                c1_b_uniqueVals_d->data[c1_i103] = c1_uniqueVals_d->data[c1_i103]
                  - c1_threshCandidate_d;
              }

              c1_b_st.site = &c1_pe_emlrtRSI;
              c1_abs(chartInstance, &c1_b_st, c1_b_uniqueVals_d, c1_r1);
              c1_b_st.site = &c1_qe_emlrtRSI;
              c1_d1 = c1_eps(chartInstance, c1_threshCandidate_d);
              c1_e_tmp_size[0] = c1_r1->size[0];
              c1_ib_loop_ub = c1_r1->size[0] - 1;
              for (c1_i105 = 0; c1_i105 <= c1_ib_loop_ub; c1_i105++) {
                c1_e_tmp_data[c1_i105] = (c1_r1->data[c1_i105] < c1_d1);
              }

              c1_b_st.site = &c1_pe_emlrtRSI;
              c1_f_tmp_size[0] = c1_e_tmp_size[0];
              if (!c1_any(chartInstance, &c1_b_st, c1_e_tmp_data, c1_f_tmp_size))
              {
                c1_i107 = c1_b_threshout->size[1];
                c1_i108 = (int32_T)(c1_lenThreshOrig + 1.0);
                c1_b_threshout->data[emlrtDynamicBoundsCheckR2012b(c1_i108, 1,
                  c1_i107, &c1_kc_emlrtBCI, &c1_st) - 1] = c1_threshCandidate;
                c1_q = 2.0;
              }
            }

            c1_emxFree_real_T(chartInstance, &c1_b_uniqueVals_d);
            c1_b_st.site = &c1_re_emlrtRSI;
            c1_c_st.site = &c1_we_emlrtRSI;
            c1_c_sort(chartInstance, &c1_c_st, c1_b_threshout);
          } else {
            c1_i64 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
            c1_b_threshout->size[0] = 1;
            c1_b_threshout->size[1] = c1_threshL->size[1];
            c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_b_threshout,
              c1_i64, &c1_uc_emlrtRTEI);
            c1_s_loop_ub = c1_threshL->size[0] * c1_threshL->size[1] - 1;
            for (c1_i73 = 0; c1_i73 <= c1_s_loop_ub; c1_i73++) {
              c1_b_threshout->data[c1_i73] = c1_threshL->data[c1_i73];
            }
          }
        } else {
          c1_i44 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
          c1_b_threshout->size[0] = 1;
          c1_b_threshout->size[1] = c1_uniqueVals->size[1];
          c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_b_threshout,
            c1_i44, &c1_qc_emlrtRTEI);
          c1_n_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
          for (c1_i51 = 0; c1_i51 <= c1_n_loop_ub; c1_i51++) {
            c1_b_threshout->data[c1_i51] = c1_uniqueVals->data[c1_i51];
          }
        }
      }

      c1_i50 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
      c1_threshRaw->size[0] = 1;
      c1_threshRaw->size[1] = c1_b_threshout->size[1];
      c1_st.site = &c1_dd_emlrtRSI;
      c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_threshRaw, c1_i50,
        &c1_sc_emlrtRTEI);
      c1_p_loop_ub = c1_b_threshout->size[0] * c1_b_threshout->size[1] - 1;
      for (c1_i57 = 0; c1_i57 <= c1_p_loop_ub; c1_i57++) {
        c1_threshRaw->data[c1_i57] = c1_b_threshout->data[c1_i57];
      }
    }

    if (c1_isvalid_maxval) {
      c1_c_minA = c1_minA;
      c1_b_maxA = c1_maxA;
      c1_i22 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
      c1_i23 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
      c1_threshRaw->size[0] = 1;
      c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_threshRaw, c1_i23,
        &c1_lc_emlrtRTEI);
      c1_i26 = c1_i22;
      c1_d_loop_ub = c1_i26 - 1;
      for (c1_i27 = 0; c1_i27 <= c1_d_loop_ub; c1_i27++) {
        c1_threshRaw->data[c1_i27] /= 255.0;
      }

      c1_n_b = (real_T)c1_b_maxA - (real_T)c1_c_minA;
      c1_i30 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
      c1_i31 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
      c1_threshRaw->size[0] = 1;
      c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_threshRaw, c1_i31,
        &c1_g_emlrtRTEI);
      c1_i33 = c1_i30;
      c1_i_loop_ub = c1_i33 - 1;
      for (c1_i35 = 0; c1_i35 <= c1_i_loop_ub; c1_i35++) {
        c1_threshRaw->data[c1_i35] *= c1_n_b;
      }

      c1_i36 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
      c1_i37 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
      c1_threshRaw->size[0] = 1;
      c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_threshRaw, c1_i37,
        &c1_nc_emlrtRTEI);
      c1_i39 = c1_i36;
      c1_k_loop_ub = c1_i39 - 1;
      for (c1_i40 = 0; c1_i40 <= c1_k_loop_ub; c1_i40++) {
        c1_threshRaw->data[c1_i40] += (real_T)c1_c_minA;
      }

      c1_i43 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
      c1_b_threshout->size[0] = 1;
      c1_b_threshout->size[1] = c1_threshRaw->size[1];
      c1_emxEnsureCapacity_real32_T1(chartInstance, c1_sp, c1_b_threshout,
        c1_i43, &c1_oc_emlrtRTEI);
      c1_m_loop_ub = c1_threshRaw->size[0] * c1_threshRaw->size[1] - 1;
      for (c1_i47 = 0; c1_i47 <= c1_m_loop_ub; c1_i47++) {
        c1_b_threshout->data[c1_i47] = (real32_T)c1_threshRaw->data[c1_i47];
      }
    } else {
      c1_st.site = &c1_ed_emlrtRSI;
      c1_b_st.site = &c1_xd_emlrtRSI;
      for (c1_i21 = 0; c1_i21 < 19200; c1_i21++) {
        chartInstance->c1_b_varargin_1[c1_i21] = c1_d_varargin_1[c1_i21];
      }

      c1_c_st.site = &c1_ae_emlrtRSI;
      c1_unique_vector(chartInstance, &c1_c_st, chartInstance->c1_b_varargin_1,
                       c1_img);
      c1_i25 = c1_uniqueVals->size[0] * c1_uniqueVals->size[1];
      c1_uniqueVals->size[0] = 1;
      c1_uniqueVals->size[1] = c1_img->size[0];
      c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_uniqueVals,
        c1_i25, &c1_jc_emlrtRTEI);
      c1_f_loop_ub = c1_img->size[0] - 1;
      for (c1_i29 = 0; c1_i29 <= c1_f_loop_ub; c1_i29++) {
        c1_uniqueVals->data[c1_i29] = c1_img->data[c1_i29];
      }

      c1_tmp_size[0] = 1;
      c1_tmp_size[1] = c1_uniqueVals->size[1];
      c1_h_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
      for (c1_i34 = 0; c1_i34 <= c1_h_loop_ub; c1_i34++) {
        c1_tmp_data[c1_i34] = muSingleScalarIsInf(c1_uniqueVals->data[c1_i34]);
      }

      c1_b_tmp_size[0] = 1;
      c1_b_tmp_size[1] = c1_uniqueVals->size[1];
      c1_j_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
      for (c1_i38 = 0; c1_i38 <= c1_j_loop_ub; c1_i38++) {
        c1_b_tmp_data[c1_i38] = muSingleScalarIsNaN(c1_uniqueVals->data[c1_i38]);
      }

      emlrtSizeEqCheckNDR2012b(c1_tmp_size, c1_b_tmp_size, &c1_emlrtECI, &c1_st);
      c1_d_tmp_size[0] = 1;
      c1_d_tmp_size[1] = c1_tmp_size[1];
      c1_l_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
      for (c1_i42 = 0; c1_i42 <= c1_l_loop_ub; c1_i42++) {
        c1_d_tmp_data[c1_i42] = (c1_tmp_data[c1_i42] || c1_b_tmp_data[c1_i42]);
      }

      c1_b_st.site = &c1_yd_emlrtRSI;
      c1_b_nullAssignment(chartInstance, &c1_b_st, c1_uniqueVals, c1_d_tmp_data,
                          c1_d_tmp_size);
      c1_b_isDegenerate = ((real_T)c1_uniqueVals->size[1] <= 1.0);
      if (c1_b_isDegenerate) {
        c1_st.site = &c1_fd_emlrtRSI;
        c1_b_warning(chartInstance, &c1_st);
        c1_st.site = &c1_gd_emlrtRSI;
        c1_b9 = (c1_uniqueVals->size[1] == 0);
        if (c1_b9) {
          c1_i56 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
          c1_b_threshout->size[0] = 1;
          c1_b_threshout->size[1] = 1;
          c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_b_threshout,
            c1_i56, &c1_tc_emlrtRTEI);
          c1_b_threshout->data[0] = 1.0F;
        } else {
          c1_b_thNeeded1 = 1.0 - (real_T)c1_uniqueVals->size[1];
          if (c1_b_thNeeded1 > 0.0) {
            c1_i59 = c1_uniqueVals->size[1];
            c1_i62 = 1;
            emlrtDynamicBoundsCheckR2012b(c1_i62, 1, c1_i59, &c1_ic_emlrtBCI,
              &c1_st);
            if (c1_uniqueVals->data[0] > 1.0F) {
              c1_i68 = c1_uniqueVals->size[1];
              c1_i70 = 1;
              emlrtDynamicBoundsCheckR2012b(c1_i70, 1, c1_i68, &c1_hc_emlrtBCI,
                &c1_st);
              c1_r_x = c1_uniqueVals->data[0];
              c1_s_x = c1_r_x;
              c1_s_x = muSingleScalarCeil(c1_s_x);
              c1_c_varargin_2 = c1_s_x - 1.0F;
              c1_i_y = c1_c_varargin_2;
              c1_j_y = c1_i_y;
              c1_k_y = c1_j_y;
              c1_l_y = c1_k_y;
              c1_m_y = c1_l_y;
              c1_n_y = c1_m_y;
              c1_b_minval = muSingleScalarMin(1.0F, c1_n_y);
              c1_c_d = c1_b_minval;
              c1_r_b = c1_c_d;
              c1_u_x = c1_r_b;
              c1_s_b = muSingleScalarIsNaN(c1_u_x);
              if (c1_s_b) {
                c1_y_size[1] = 1;
                c1_y_data[0] = rtNaNF;
              } else if (c1_r_b < 1.0F) {
                c1_y_size[1] = 0;
              } else {
                c1_y_size[1] = 1;
                c1_y_data[0] = 1.0F;
              }

              c1_i95 = c1_threshL->size[0] * c1_threshL->size[1];
              c1_threshL->size[0] = 1;
              c1_threshL->size[1] = c1_y_size[1] + c1_uniqueVals->size[1];
              c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_threshL,
                c1_i95, &c1_yc_emlrtRTEI);
              c1_fb_loop_ub = c1_y_size[1] - 1;
              for (c1_i100 = 0; c1_i100 <= c1_fb_loop_ub; c1_i100++) {
                c1_threshL->data[c1_i100] = c1_y_data[c1_i100];
              }

              c1_gb_loop_ub = c1_uniqueVals->size[1] - 1;
              for (c1_i101 = 0; c1_i101 <= c1_gb_loop_ub; c1_i101++) {
                c1_threshL->data[c1_i101 + c1_y_size[1]] = c1_uniqueVals->
                  data[c1_i101];
              }
            } else {
              c1_i67 = c1_threshL->size[0] * c1_threshL->size[1];
              c1_threshL->size[0] = 1;
              c1_threshL->size[1] = c1_uniqueVals->size[1];
              c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_threshL,
                c1_i67, &c1_rc_emlrtRTEI);
              c1_u_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
              for (c1_i75 = 0; c1_i75 <= c1_u_loop_ub; c1_i75++) {
                c1_threshL->data[c1_i75] = c1_uniqueVals->data[c1_i75];
              }
            }

            c1_b_thNeeded2 = 1.0 - (real_T)c1_threshL->size[1];
            if (c1_b_thNeeded2 > 0.0) {
              c1_b_lenThreshOrig = (real_T)c1_threshL->size[1];
              c1_i83 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
              c1_b_threshout->size[0] = 1;
              c1_b_threshout->size[1] = c1_threshL->size[1] + 1;
              c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st,
                c1_b_threshout, c1_i83, &c1_tc_emlrtRTEI);
              c1_bb_loop_ub = c1_threshL->size[1] - 1;
              for (c1_i91 = 0; c1_i91 <= c1_bb_loop_ub; c1_i91++) {
                c1_b_threshout->data[c1_i91] = c1_threshL->data[c1_i91];
              }

              c1_b_threshout->data[c1_threshL->size[1]] = 0.0F;
              c1_i94 = c1_uniqueVals_d->size[0] * c1_uniqueVals_d->size[1];
              c1_uniqueVals_d->size[0] = 1;
              c1_uniqueVals_d->size[1] = c1_uniqueVals->size[1];
              c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st,
                c1_uniqueVals_d, c1_i94, &c1_xc_emlrtRTEI);
              c1_eb_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] -
                1;
              for (c1_i97 = 0; c1_i97 <= c1_eb_loop_ub; c1_i97++) {
                c1_uniqueVals_d->data[c1_i97] = c1_uniqueVals->data[c1_i97];
              }

              c1_i98 = c1_uniqueVals->size[1];
              c1_i99 = 1;
              emlrtDynamicBoundsCheckR2012b(c1_i99, 1, c1_i98, &c1_gc_emlrtBCI,
                &c1_st);
              c1_db_x = c1_uniqueVals->data[0];
              c1_f_varargin_1 = c1_db_x;
              c1_f_varargin_1 = muSingleScalarFloor(c1_f_varargin_1);
              c1_eb_x = c1_f_varargin_1;
              c1_fb_x = c1_eb_x;
              c1_gb_x = c1_fb_x;
              c1_hb_x = c1_gb_x;
              c1_ib_x = c1_hb_x;
              c1_jb_x = c1_ib_x;
              c1_b_threshCandidate = muSingleScalarMax(c1_jb_x, 0.0F);
              c1_b_q = 1.0;
              c1_emxInit_real_T1(chartInstance, &c1_st, &c1_d_uniqueVals_d, 1,
                                 &c1_bd_emlrtRTEI);
              while (c1_b_q <= 1.0) {
                c1_b_threshCandidate++;
                c1_b_threshCandidate_d = c1_b_threshCandidate;
                c1_e_uniqueVals_d[0] = c1_uniqueVals_d->size[1];
                c1_i104 = c1_d_uniqueVals_d->size[0];
                c1_d_uniqueVals_d->size[0] = c1_e_uniqueVals_d[0];
                c1_emxEnsureCapacity_real_T(chartInstance, &c1_st,
                  c1_d_uniqueVals_d, c1_i104, &c1_bd_emlrtRTEI);
                c1_jb_loop_ub = c1_e_uniqueVals_d[0] - 1;
                for (c1_i106 = 0; c1_i106 <= c1_jb_loop_ub; c1_i106++) {
                  c1_d_uniqueVals_d->data[c1_i106] = c1_uniqueVals_d->
                    data[c1_i106] - c1_b_threshCandidate_d;
                }

                c1_b_st.site = &c1_pe_emlrtRSI;
                c1_abs(chartInstance, &c1_b_st, c1_d_uniqueVals_d, c1_r1);
                c1_b_st.site = &c1_qe_emlrtRSI;
                c1_d2 = c1_eps(chartInstance, c1_b_threshCandidate_d);
                c1_g_tmp_size[0] = c1_r1->size[0];
                c1_kb_loop_ub = c1_r1->size[0] - 1;
                for (c1_i109 = 0; c1_i109 <= c1_kb_loop_ub; c1_i109++) {
                  c1_f_tmp_data[c1_i109] = (c1_r1->data[c1_i109] < c1_d2);
                }

                c1_b_st.site = &c1_pe_emlrtRSI;
                c1_h_tmp_size[0] = c1_g_tmp_size[0];
                if (!c1_any(chartInstance, &c1_b_st, c1_f_tmp_data,
                            c1_h_tmp_size)) {
                  c1_i110 = c1_b_threshout->size[1];
                  c1_i111 = (int32_T)(c1_b_lenThreshOrig + 1.0);
                  c1_b_threshout->data[emlrtDynamicBoundsCheckR2012b(c1_i111, 1,
                    c1_i110, &c1_kc_emlrtBCI, &c1_st) - 1] =
                    c1_b_threshCandidate;
                  c1_b_q = 2.0;
                }
              }

              c1_emxFree_real_T(chartInstance, &c1_d_uniqueVals_d);
              c1_b_st.site = &c1_re_emlrtRSI;
              c1_c_st.site = &c1_we_emlrtRSI;
              c1_c_sort(chartInstance, &c1_c_st, c1_b_threshout);
            } else {
              c1_i80 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
              c1_b_threshout->size[0] = 1;
              c1_b_threshout->size[1] = c1_threshL->size[1];
              c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st,
                c1_b_threshout, c1_i80, &c1_tc_emlrtRTEI);
              c1_x_loop_ub = c1_threshL->size[0] * c1_threshL->size[1] - 1;
              for (c1_i87 = 0; c1_i87 <= c1_x_loop_ub; c1_i87++) {
                c1_b_threshout->data[c1_i87] = c1_threshL->data[c1_i87];
              }
            }
          } else {
            c1_i58 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
            c1_b_threshout->size[0] = 1;
            c1_b_threshout->size[1] = c1_uniqueVals->size[1];
            c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_b_threshout,
              c1_i58, &c1_tc_emlrtRTEI);
            c1_r_loop_ub = c1_uniqueVals->size[0] * c1_uniqueVals->size[1] - 1;
            for (c1_i69 = 0; c1_i69 <= c1_r_loop_ub; c1_i69++) {
              c1_b_threshout->data[c1_i69] = c1_uniqueVals->data[c1_i69];
            }
          }
        }
      } else {
        c1_st.site = &c1_hd_emlrtRSI;
        c1_c_warning(chartInstance, &c1_st);
        c1_d_minA = c1_minA;
        c1_c_maxA = c1_maxA;
        c1_i53 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
        c1_i55 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
        c1_threshRaw->size[0] = 1;
        c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_threshRaw, c1_i55,
          &c1_lc_emlrtRTEI);
        c1_i61 = c1_i53;
        c1_q_loop_ub = c1_i61 - 1;
        for (c1_i65 = 0; c1_i65 <= c1_q_loop_ub; c1_i65++) {
          c1_threshRaw->data[c1_i65] /= 255.0;
        }

        c1_o_b = (real_T)c1_c_maxA - (real_T)c1_d_minA;
        c1_i71 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
        c1_i72 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
        c1_threshRaw->size[0] = 1;
        c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_threshRaw, c1_i72,
          &c1_g_emlrtRTEI);
        c1_i76 = c1_i71;
        c1_v_loop_ub = c1_i76 - 1;
        for (c1_i78 = 0; c1_i78 <= c1_v_loop_ub; c1_i78++) {
          c1_threshRaw->data[c1_i78] *= c1_o_b;
        }

        c1_i79 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
        c1_i82 = c1_threshRaw->size[0] * c1_threshRaw->size[1];
        c1_threshRaw->size[0] = 1;
        c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_threshRaw, c1_i82,
          &c1_nc_emlrtRTEI);
        c1_i85 = c1_i79;
        c1_ab_loop_ub = c1_i85 - 1;
        for (c1_i90 = 0; c1_i90 <= c1_ab_loop_ub; c1_i90++) {
          c1_threshRaw->data[c1_i90] += (real_T)c1_d_minA;
        }

        c1_i92 = c1_b_threshout->size[0] * c1_b_threshout->size[1];
        c1_b_threshout->size[0] = 1;
        c1_b_threshout->size[1] = c1_threshRaw->size[1];
        c1_emxEnsureCapacity_real32_T1(chartInstance, c1_sp, c1_b_threshout,
          c1_i92, &c1_ad_emlrtRTEI);
        c1_db_loop_ub = c1_threshRaw->size[0] * c1_threshRaw->size[1] - 1;
        for (c1_i96 = 0; c1_i96 <= c1_db_loop_ub; c1_i96++) {
          c1_b_threshout->data[c1_i96] = (real32_T)c1_threshRaw->data[c1_i96];
        }
      }
    }

    c1_emxFree_real_T(chartInstance, &c1_r1);
    c1_emxFree_real_T(chartInstance, &c1_uniqueVals_d);
    c1_emxFree_real32_T(chartInstance, &c1_threshL);
    c1_emxFree_real32_T(chartInstance, &c1_uniqueVals);
    c1_emxFree_real_T(chartInstance, &c1_threshRaw);
    c1_i60 = c1_b_threshout->size[1];
    c1_i63 = 1;
    emlrtDynamicBoundsCheckR2012b(c1_i63, 1, c1_i60, &c1_jc_emlrtBCI, c1_sp);
    c1_thresh = c1_b_threshout->data[0];
    c1_emxFree_real32_T(chartInstance, &c1_b_threshout);
  }

  c1_emxFree_real32_T(chartInstance, &c1_img);
  return c1_thresh;
}

static real32_T c1_minimum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_c_x[19200])
{
  c1_emxArray_real32_T *c1_d_x;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_st;
  int32_T c1_b_idx;
  int32_T c1_b_k;
  int32_T c1_first;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_k;
  real32_T c1_b_ex;
  real32_T c1_e_x;
  real32_T c1_ex;
  real32_T c1_f_x;
  real32_T c1_g_x;
  real32_T c1_h_x;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_emxInit_real32_T(chartInstance, c1_sp, &c1_d_x, 1, &c1_gd_emlrtRTEI);
  c1_st.site = &c1_od_emlrtRSI;
  c1_b_st.site = &c1_pd_emlrtRSI;
  c1_i = c1_d_x->size[0];
  c1_d_x->size[0] = 19200;
  c1_emxEnsureCapacity_real32_T(chartInstance, &c1_b_st, c1_d_x, c1_i,
    &c1_gd_emlrtRTEI);
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_d_x->data[c1_i1] = c1_c_x[c1_i1];
  }

  c1_c_st.site = &c1_qd_emlrtRSI;
  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_e_x = c1_d_x->data[0];
  c1_f_x = c1_e_x;
  c1_b = muSingleScalarIsNaN(c1_f_x);
  c1_p = !c1_b;
  if (c1_p) {
    c1_b_idx = 1;
  } else {
    c1_b_idx = 0;
    c1_e_st.site = &c1_jb_emlrtRSI;
    c1_k = 2;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 19201)) {
      c1_g_x = c1_d_x->data[c1_k - 1];
      c1_h_x = c1_g_x;
      c1_b_b = muSingleScalarIsNaN(c1_h_x);
      c1_b_p = !c1_b_b;
      if (c1_b_p) {
        c1_b_idx = c1_k;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }
  }

  if (c1_b_idx == 0) {
    c1_ex = c1_d_x->data[0];
  } else {
    c1_d_st.site = &c1_hb_emlrtRSI;
    c1_first = c1_b_idx - 1;
    c1_b_ex = c1_d_x->data[c1_first];
    c1_i2 = c1_first;
    c1_e_st.site = &c1_lb_emlrtRSI;
    c1_overflow = false;
    if (c1_overflow) {
      c1_f_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
    }

    for (c1_b_k = c1_i2 + 1; c1_b_k + 1 < 19201; c1_b_k++) {
      if (c1_b_ex > c1_d_x->data[c1_b_k]) {
        c1_b_ex = c1_d_x->data[c1_b_k];
      }
    }

    c1_ex = c1_b_ex;
  }

  c1_emxFree_real32_T(chartInstance, &c1_d_x);
  return c1_ex;
}

static void c1_c_imhist(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, uint8_T c1_varargin_1_data[], int32_T
  c1_varargin_1_size[1], real_T c1_yout[256])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_localBins1[256];
  real_T c1_localBins2[256];
  real_T c1_localBins3[256];
  real_T c1_b_out;
  real_T c1_d_i;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_b_idx;
  int32_T c1_c;
  int32_T c1_c_c;
  int32_T c1_c_i;
  int32_T c1_d_c;
  int32_T c1_e_c;
  int32_T c1_f_c;
  int32_T c1_g_a;
  int32_T c1_g_c;
  int32_T c1_h_a;
  int32_T c1_h_c;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i_a;
  int32_T c1_i_c;
  int32_T c1_idx1;
  int32_T c1_idx2;
  int32_T c1_idx3;
  int32_T c1_idx4;
  int32_T c1_j_a;
  int32_T c1_j_c;
  int32_T c1_k_a;
  int32_T c1_l_a;
  int32_T c1_m_a;
  int32_T c1_n_a;
  int32_T c1_o_a;
  int32_T c1_p_a;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_m_emlrtRSI;
  c1_b_st.site = &c1_o_emlrtRSI;
  c1_b_out = 1.0;
  getnumcores(&c1_b_out);
  c1_b_st.site = &c1_n_emlrtRSI;
  for (c1_i = 0; c1_i < 256; c1_i++) {
    c1_yout[c1_i] = 0.0;
  }

  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    c1_localBins1[c1_i1] = 0.0;
  }

  for (c1_i2 = 0; c1_i2 < 256; c1_i2++) {
    c1_localBins2[c1_i2] = 0.0;
  }

  for (c1_i3 = 0; c1_i3 < 256; c1_i3++) {
    c1_localBins3[c1_i3] = 0.0;
  }

  for (c1_b_i = 1; c1_b_i + 3 <= c1_varargin_1_size[0]; c1_b_i += 4) {
    c1_idx1 = c1_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c1_b_i, 1,
      c1_varargin_1_size[0], &c1_lc_emlrtBCI, &c1_b_st) - 1];
    c1_i4 = c1_b_i + 1;
    c1_idx2 = c1_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c1_i4, 1,
      c1_varargin_1_size[0], &c1_mc_emlrtBCI, &c1_b_st) - 1];
    c1_i5 = c1_b_i + 2;
    c1_idx3 = c1_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c1_i5, 1,
      c1_varargin_1_size[0], &c1_oc_emlrtBCI, &c1_b_st) - 1];
    c1_i6 = c1_b_i + 3;
    c1_idx4 = c1_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c1_i6, 1,
      c1_varargin_1_size[0], &c1_pc_emlrtBCI, &c1_b_st) - 1];
    c1_i_a = c1_idx1 + 1;
    c1_c_c = c1_i_a - 1;
    c1_j_a = c1_idx1 + 1;
    c1_d_c = c1_j_a - 1;
    c1_localBins1[c1_c_c] = c1_localBins1[c1_d_c] + 1.0;
    c1_k_a = c1_idx2 + 1;
    c1_e_c = c1_k_a - 1;
    c1_l_a = c1_idx2 + 1;
    c1_f_c = c1_l_a - 1;
    c1_localBins2[c1_e_c] = c1_localBins2[c1_f_c] + 1.0;
    c1_m_a = c1_idx3 + 1;
    c1_g_c = c1_m_a - 1;
    c1_n_a = c1_idx3 + 1;
    c1_h_c = c1_n_a - 1;
    c1_localBins3[c1_g_c] = c1_localBins3[c1_h_c] + 1.0;
    c1_o_a = c1_idx4 + 1;
    c1_i_c = c1_o_a - 1;
    c1_p_a = c1_idx4 + 1;
    c1_j_c = c1_p_a - 1;
    c1_yout[c1_i_c] = c1_yout[c1_j_c] + 1.0;
  }

  while (c1_b_i <= c1_varargin_1_size[0]) {
    c1_b_idx = c1_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c1_b_i, 1,
      c1_varargin_1_size[0], &c1_nc_emlrtBCI, &c1_b_st) - 1];
    c1_g_a = c1_b_idx + 1;
    c1_c = c1_g_a - 1;
    c1_h_a = c1_b_idx + 1;
    c1_b_c = c1_h_a - 1;
    c1_yout[c1_c] = c1_yout[c1_b_c] + 1.0;
    c1_b_i++;
  }

  for (c1_c_i = 0; c1_c_i < 256; c1_c_i++) {
    c1_d_i = (real_T)c1_c_i + 1.0;
    c1_yout[(int32_T)c1_d_i - 1] = ((c1_yout[(int32_T)c1_d_i - 1] +
      c1_localBins1[(int32_T)c1_d_i - 1]) + c1_localBins2[(int32_T)c1_d_i - 1])
      + c1_localBins3[(int32_T)c1_d_i - 1];
  }
}

static real_T c1_sum(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     real_T c1_c_x[256])
{
  real_T c1_y;
  int32_T c1_ix;
  int32_T c1_k;
  int32_T c1_xoffset;
  (void)chartInstance;
  c1_y = c1_c_x[0];
  for (c1_k = 0; c1_k < 255; c1_k++) {
    c1_xoffset = c1_k;
    c1_ix = c1_xoffset;
    c1_y += c1_c_x[c1_ix + 1];
  }

  return c1_y;
}

static void c1_b_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp)
{
  static char_T c1_msgID[34] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'm', 'u',
    'l', 't', 'i', 't', 'h', 'r', 'e', 's', 'h', ':', 'd', 'e', 'g', 'e', 'n',
    'e', 'r', 'a', 't', 'e', 'I', 'n', 'p', 'u', 't' };

  static char_T c1_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c1_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_c_u;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_msgID, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c1_c_u = 1.0;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  c1_st.site = &c1_p_emlrtRSI;
  c1_d_feval(chartInstance, &c1_st, c1_y, c1_c_feval(chartInstance, &c1_st,
              c1_b_y, c1_c_y, c1_d_y));
}

static void c1_power(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     real_T c1_g_a[256], real_T c1_y[256])
{
  real_T c1_b_y;
  real_T c1_h_a;
  int32_T c1_b_k;
  int32_T c1_k;
  (void)chartInstance;
  for (c1_k = 0; c1_k < 256; c1_k++) {
    c1_b_k = c1_k;
    c1_h_a = c1_g_a[c1_b_k];
    c1_b_y = c1_h_a * c1_h_a;
    c1_y[c1_b_k] = c1_b_y;
  }
}

static real_T c1_b_maximum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_c_x[256])
{
  c1_emxArray_real_T *c1_d_x;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_st;
  real_T c1_b_ex;
  real_T c1_e_x;
  real_T c1_ex;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  int32_T c1_b_b;
  int32_T c1_b_idx;
  int32_T c1_b_k;
  int32_T c1_b_n;
  int32_T c1_c_b;
  int32_T c1_d_b;
  int32_T c1_e_b;
  int32_T c1_first;
  int32_T c1_g_a;
  int32_T c1_h_a;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_k;
  int32_T c1_last;
  int32_T c1_n;
  boolean_T c1_b;
  boolean_T c1_b_overflow;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_d_x, 1, &c1_emlrtRTEI);
  c1_st.site = &c1_hc_emlrtRSI;
  c1_b_st.site = &c1_ic_emlrtRSI;
  c1_i = c1_d_x->size[0];
  c1_d_x->size[0] = 256;
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_d_x, c1_i,
    &c1_emlrtRTEI);
  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    c1_d_x->data[c1_i1] = c1_c_x[c1_i1];
  }

  c1_c_st.site = &c1_gb_emlrtRSI;
  c1_n = c1_d_x->size[0];
  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_b_n = c1_d_x->size[0];
  c1_e_x = c1_d_x->data[0];
  c1_f_x = c1_e_x;
  c1_b = muDoubleScalarIsNaN(c1_f_x);
  c1_p = !c1_b;
  if (c1_p) {
    c1_b_idx = 1;
  } else {
    c1_b_idx = 0;
    c1_e_st.site = &c1_jb_emlrtRSI;
    c1_b_b = c1_b_n;
    c1_c_b = c1_b_b;
    if (2 > c1_c_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_f_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
    }

    c1_k = 2;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k <= c1_b_n)) {
      c1_g_x = c1_d_x->data[c1_k - 1];
      c1_h_x = c1_g_x;
      c1_f_b = muDoubleScalarIsNaN(c1_h_x);
      c1_b_p = !c1_f_b;
      if (c1_b_p) {
        c1_b_idx = c1_k;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }
  }

  if (c1_b_idx == 0) {
    c1_ex = c1_d_x->data[0];
  } else {
    c1_d_st.site = &c1_hb_emlrtRSI;
    c1_first = c1_b_idx - 1;
    c1_last = c1_n;
    c1_b_ex = c1_d_x->data[c1_first];
    c1_i2 = c1_first + 2;
    c1_e_st.site = &c1_lb_emlrtRSI;
    c1_g_a = c1_i2;
    c1_d_b = c1_last;
    c1_h_a = c1_g_a;
    c1_e_b = c1_d_b;
    if (c1_h_a > c1_e_b) {
      c1_b_overflow = false;
    } else {
      c1_b_overflow = (c1_e_b > 2147483646);
    }

    if (c1_b_overflow) {
      c1_f_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
    }

    for (c1_b_k = c1_i2 - 1; c1_b_k < c1_last; c1_b_k++) {
      if (c1_b_ex < c1_d_x->data[c1_b_k]) {
        c1_b_ex = c1_d_x->data[c1_b_k];
      }
    }

    c1_ex = c1_b_ex;
  }

  c1_emxFree_real_T(chartInstance, &c1_d_x);
  return c1_ex;
}

static void c1_mergesort(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, int32_T c1_b_idx[19200], real32_T c1_c_x[19200],
  int32_T c1_c_idx[19200])
{
  int32_T c1_i;
  int32_T c1_i1;
  real32_T c1_d_x[19200];
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_c_idx[c1_i] = c1_b_idx[c1_i];
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_d_x[c1_i1] = c1_c_x[c1_i1];
  }

  c1_c_mergesort(chartInstance, c1_sp, c1_c_idx, c1_d_x);
}

static void c1_unique_vector(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real32_T c1_g_a[19200],
  c1_emxArray_real32_T *c1_b)
{
  c1_emxArray_real32_T *c1_b_b;
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_iv[2];
  int32_T c1_b_c;
  int32_T c1_b_exponent;
  int32_T c1_b_j;
  int32_T c1_b_k;
  int32_T c1_c;
  int32_T c1_c_b;
  int32_T c1_c_c;
  int32_T c1_c_k;
  int32_T c1_e_b;
  int32_T c1_exitg2;
  int32_T c1_exponent;
  int32_T c1_g_b;
  int32_T c1_h_a;
  int32_T c1_h_b;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i_a;
  int32_T c1_i_b;
  int32_T c1_j;
  int32_T c1_j_a;
  int32_T c1_j_b;
  int32_T c1_k;
  int32_T c1_k0;
  int32_T c1_k_a;
  int32_T c1_k_b;
  int32_T c1_khi;
  int32_T c1_l_a;
  int32_T c1_l_b;
  int32_T c1_loop_ub;
  int32_T c1_m_a;
  int32_T c1_m_b;
  int32_T c1_nFinite;
  int32_T c1_nInf;
  int32_T c1_nNaN;
  int32_T c1_n_a;
  int32_T c1_nb;
  int32_T c1_o_a;
  int32_T c1_p_b;
  int32_T c1_q_a;
  int32_T c1_q_b;
  int32_T c1_r_a;
  int32_T c1_r_b;
  int32_T c1_s_a;
  int32_T c1_t_a;
  int32_T c1_t_b;
  int32_T c1_u_a;
  int32_T c1_v_a;
  int32_T c1_v_b;
  real32_T c1_absx;
  real32_T c1_c_x;
  real32_T c1_d_x;
  real32_T c1_e_x;
  real32_T c1_f_x;
  real32_T c1_g_x;
  real32_T c1_h_x;
  real32_T c1_i_x;
  real32_T c1_j_x;
  real32_T c1_k_x;
  real32_T c1_l_x;
  real32_T c1_m_x;
  real32_T c1_n_b;
  real32_T c1_n_x;
  real32_T c1_o_x;
  real32_T c1_p_a;
  real32_T c1_p_x;
  real32_T c1_q_x;
  real32_T c1_r;
  real32_T c1_r_x;
  real32_T c1_s_x;
  real32_T c1_t_x;
  real32_T c1_y;
  real32_T c1_z;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b_overflow;
  boolean_T c1_b_p;
  boolean_T c1_c_overflow;
  boolean_T c1_d_b;
  boolean_T c1_d_overflow;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_o_b;
  boolean_T c1_overflow;
  boolean_T c1_p;
  boolean_T c1_s_b;
  boolean_T c1_u_b;
  boolean_T c1_w_b;
  boolean_T c1_x_b;
  boolean_T c1_y_b;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_ie_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    chartInstance->c1_idx[c1_i] = 0;
  }

  c1_b_st.site = &c1_td_emlrtRSI;
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    chartInstance->c1_a[c1_i1] = c1_g_a[c1_i1];
  }

  c1_c_mergesort(chartInstance, &c1_b_st, chartInstance->c1_idx,
                 chartInstance->c1_a);
  c1_i2 = c1_b->size[0];
  c1_b->size[0] = 19200;
  c1_st.site = &c1_jl_emlrtRSI;
  c1_emxEnsureCapacity_real32_T(chartInstance, &c1_st, c1_b, c1_i2,
    &c1_hd_emlrtRTEI);
  for (c1_k = 0; c1_k < 19200; c1_k++) {
    c1_b_k = c1_k;
    c1_b->data[c1_b_k] = c1_g_a[chartInstance->c1_idx[c1_b_k] - 1];
  }

  c1_emxInit_real32_T(chartInstance, c1_sp, &c1_b_b, 1, &c1_id_emlrtRTEI);
  c1_i3 = c1_b_b->size[0];
  c1_b_b->size[0] = c1_b->size[0];
  c1_st.site = &c1_il_emlrtRSI;
  c1_emxEnsureCapacity_real32_T(chartInstance, &c1_st, c1_b_b, c1_i3,
    &c1_id_emlrtRTEI);
  c1_loop_ub = c1_b->size[0] - 1;
  for (c1_i4 = 0; c1_i4 <= c1_loop_ub; c1_i4++) {
    c1_b_b->data[c1_i4] = c1_b->data[c1_i4];
  }

  c1_c_k = 19200;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k >= 1)) {
    c1_c_x = c1_b_b->data[c1_c_k - 1];
    c1_d_b = muSingleScalarIsNaN(c1_c_x);
    if (c1_d_b) {
      c1_h_a = c1_c_k - 1;
      c1_c_k = c1_h_a;
    } else {
      c1_exitg1 = true;
    }
  }

  c1_c_b = c1_c_k;
  c1_nNaN = 19200 - c1_c_b;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k >= 1)) {
    c1_d_x = c1_b_b->data[c1_c_k - 1];
    c1_f_b = muSingleScalarIsInf(c1_d_x);
    if (c1_f_b && (c1_b_b->data[c1_c_k - 1] > 0.0F)) {
      c1_j_a = c1_c_k - 1;
      c1_c_k = c1_j_a;
    } else {
      c1_exitg1 = true;
    }
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_b);
  c1_e_b = c1_c_k;
  c1_c = 19200 - c1_e_b;
  c1_i_a = c1_c;
  c1_g_b = c1_nNaN;
  c1_nInf = c1_i_a - c1_g_b;
  c1_k_a = c1_c_k;
  c1_nFinite = c1_k_a;
  c1_nb = -1;
  c1_h_b = c1_nFinite;
  c1_khi = c1_h_b;
  c1_b_k = 1;
  while (c1_b_k <= c1_khi) {
    c1_e_x = c1_b->data[c1_b_k - 1];
    c1_k0 = c1_b_k;
    do {
      c1_exitg2 = 0;
      c1_o_a = c1_b_k + 1;
      c1_b_k = c1_o_a;
      if (c1_b_k > c1_khi) {
        c1_exitg2 = 1;
      } else {
        c1_st.site = &c1_ge_emlrtRSI;
        c1_p_a = c1_b->data[c1_b_k - 1];
        c1_n_b = c1_e_x;
        c1_f_x = c1_n_b;
        c1_g_x = c1_f_x;
        c1_z = c1_g_x / 2.0F;
        c1_h_x = c1_n_b - c1_p_a;
        c1_i_x = c1_h_x;
        c1_j_x = c1_i_x;
        c1_y = muSingleScalarAbs(c1_j_x);
        c1_b_st.site = &c1_vd_emlrtRSI;
        c1_k_x = c1_z;
        c1_l_x = c1_k_x;
        c1_m_x = c1_l_x;
        c1_n_x = c1_m_x;
        c1_o_x = c1_n_x;
        c1_absx = muSingleScalarAbs(c1_o_x);
        c1_p_x = c1_absx;
        c1_q_x = c1_p_x;
        c1_s_b = muSingleScalarIsInf(c1_q_x);
        c1_b1 = !c1_s_b;
        c1_r_x = c1_p_x;
        c1_u_b = muSingleScalarIsNaN(c1_r_x);
        c1_b2 = !c1_u_b;
        c1_w_b = (c1_b1 && c1_b2);
        if (c1_w_b) {
          if (c1_absx <= 1.17549435E-38F) {
            c1_r = 1.4013E-45F;
          } else {
            frexpf(c1_absx, &c1_exponent);
            c1_b_exponent = c1_exponent;
            c1_r = ldexpf(1.0F, c1_b_exponent - 24);
          }
        } else {
          c1_r = rtNaNF;
        }

        if (c1_y < c1_r) {
          c1_p = true;
        } else {
          c1_s_x = c1_p_a;
          c1_x_b = muSingleScalarIsInf(c1_s_x);
          if (c1_x_b) {
            c1_t_x = c1_n_b;
            c1_y_b = muSingleScalarIsInf(c1_t_x);
            if (c1_y_b && ((c1_p_a > 0.0F) == (c1_n_b > 0.0F))) {
              c1_p = true;
            } else {
              c1_p = false;
            }
          } else {
            c1_p = false;
          }
        }

        c1_b_p = c1_p;
        if (!c1_b_p) {
          c1_exitg2 = 1;
        }
      }
    } while (c1_exitg2 == 0);

    c1_q_a = c1_nb + 1;
    c1_nb = c1_q_a;
    c1_b->data[c1_nb] = c1_e_x;
    c1_r_a = c1_b_k - 1;
    c1_i5 = c1_r_a;
    c1_st.site = &c1_fe_emlrtRSI;
    c1_s_a = c1_k0;
    c1_p_b = c1_i5;
    c1_u_a = c1_s_a;
    c1_q_b = c1_p_b;
    if (c1_u_a > c1_q_b) {
      c1_c_overflow = false;
    } else {
      c1_c_overflow = (c1_q_b > 2147483646);
    }

    if (c1_c_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }
  }

  if (c1_nInf > 0) {
    c1_l_a = c1_nb + 1;
    c1_nb = c1_l_a;
    c1_n_a = c1_khi + 1;
    c1_b_c = c1_n_a - 1;
    c1_b->data[c1_nb] = c1_b->data[c1_b_c];
    c1_st.site = &c1_ee_emlrtRSI;
    c1_l_b = c1_nInf;
    c1_m_b = c1_l_b;
    if (1 > c1_m_b) {
      c1_b_overflow = false;
    } else {
      c1_b_overflow = (c1_m_b > 2147483646);
    }

    if (c1_b_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }
  }

  c1_m_a = c1_khi;
  c1_i_b = c1_nInf;
  c1_b_k = c1_m_a + c1_i_b;
  c1_st.site = &c1_de_emlrtRSI;
  c1_j_b = c1_nNaN;
  c1_k_b = c1_j_b;
  if (1 > c1_k_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_k_b > 2147483646);
  }

  if (c1_overflow) {
    c1_b_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
  }

  for (c1_j = 1; c1_j - 1 < c1_nNaN; c1_j++) {
    c1_b_j = c1_j;
    c1_t_a = c1_nb + 1;
    c1_nb = c1_t_a;
    c1_v_a = c1_b_k;
    c1_r_b = c1_b_j;
    c1_c_c = (c1_v_a + c1_r_b) - 1;
    c1_b->data[c1_nb] = c1_b->data[c1_c_c];
  }

  c1_o_b = (1 > c1_nb + 1);
  if (c1_o_b) {
    c1_i6 = 0;
  } else {
    c1_i6 = c1_nb + 1;
  }

  c1_iv[0] = 1;
  c1_iv[1] = c1_i6;
  c1_st.site = &c1_ce_emlrtRSI;
  c1_indexShapeCheck(chartInstance, &c1_st, 19200, c1_iv);
  c1_i7 = c1_b->size[0];
  c1_b->size[0] = c1_i6;
  c1_st.site = &c1_ce_emlrtRSI;
  c1_emxEnsureCapacity_real32_T(chartInstance, &c1_st, c1_b, c1_i7,
    &c1_jd_emlrtRTEI);
  c1_st.site = &c1_be_emlrtRSI;
  c1_t_b = c1_nb + 1;
  c1_v_b = c1_t_b;
  if (1 > c1_v_b) {
    c1_d_overflow = false;
  } else {
    c1_d_overflow = (c1_v_b > 2147483646);
  }

  if (c1_d_overflow) {
    c1_b_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
  }
}

static void c1_indexShapeCheck(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, int32_T c1_matrixSize, int32_T
  c1_indexSize[2])
{
  static char_T c1_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_size1;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_c;
  boolean_T c1_c;
  boolean_T c1_nonSingletonDimFound;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_size1 = c1_matrixSize;
  if (c1_size1 != 1) {
    c1_b = false;
  } else {
    c1_b = true;
  }

  if (c1_b) {
    c1_nonSingletonDimFound = false;
    if (c1_indexSize[1] != 1) {
      c1_nonSingletonDimFound = true;
    }

    c1_b_b = c1_nonSingletonDimFound;
    if (c1_b_b) {
      c1_c = true;
    } else {
      c1_c = false;
    }
  } else {
    c1_c = false;
  }

  c1_st.site = &c1_je_emlrtRSI;
  c1_b_c = c1_c;
  if (c1_b_c) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c1_st, &c1_f_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_b_y)));
  }
}

static void c1_nullAssignment(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T *c1_c_x,
  boolean_T c1_idx_data[], int32_T c1_idx_size[2], c1_emxArray_real32_T *c1_d_x)
{
  int32_T c1_b_idx_size[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_loop_ub;
  boolean_T c1_b_idx_data[19200];
  c1_i = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = 1;
  c1_d_x->size[1] = c1_c_x->size[1];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_sp, c1_d_x, c1_i,
    &c1_kd_emlrtRTEI);
  c1_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_d_x->data[c1_i1] = c1_c_x->data[c1_i1];
  }

  c1_b_idx_size[0] = 1;
  c1_b_idx_size[1] = c1_idx_size[1];
  c1_b_loop_ub = c1_idx_size[0] * c1_idx_size[1] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_b_loop_ub; c1_i2++) {
    c1_b_idx_data[c1_i2] = c1_idx_data[c1_i2];
  }

  c1_b_nullAssignment(chartInstance, c1_sp, c1_d_x, c1_b_idx_data, c1_b_idx_size);
}

static void c1_c_warning(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp)
{
  static char_T c1_msgID[32] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'm', 'u',
    'l', 't', 'i', 't', 'h', 'r', 'e', 's', 'h', ':', 'n', 'o', 'C', 'o', 'n',
    'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  static char_T c1_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c1_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_msgID, 10, 0U, 1U, 0U, 2, 1, 32),
                false);
  c1_st.site = &c1_p_emlrtRSI;
  c1_f_feval(chartInstance, &c1_st, c1_y, c1_e_feval(chartInstance, &c1_st,
              c1_b_y, c1_c_y));
}

static void c1_abs(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x,
                   c1_emxArray_real_T *c1_y)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_b_dv[2];
  real_T c1_b_y;
  real_T c1_d_x;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_i;
  int32_T c1_k;
  int32_T c1_nx;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_se_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_nx = c1_c_x->size[0];
  c1_b_dv[0] = (real_T)c1_c_x->size[0];
  c1_i = c1_y->size[0];
  c1_y->size[0] = (int32_T)c1_b_dv[0];
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_y, c1_i,
    &c1_ld_emlrtRTEI);
  c1_b_st.site = &c1_te_emlrtRSI;
  c1_b = c1_nx;
  c1_b_b = c1_b;
  if (1 > c1_b_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  for (c1_k = 1; c1_k - 1 < c1_nx; c1_k++) {
    c1_b_k = c1_k - 1;
    c1_d_x = c1_c_x->data[c1_b_k];
    c1_b_y = muDoubleScalarAbs(c1_d_x);
    c1_y->data[c1_b_k] = c1_b_y;
  }
}

static real_T c1_eps(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     real_T c1_c_x)
{
  real_T c1_absx;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_r;
  int32_T c1_b_exponent;
  int32_T c1_exponent;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b_b;
  boolean_T c1_c_b;
  boolean_T c1_d_b;
  (void)chartInstance;
  c1_d_x = c1_c_x;
  c1_e_x = c1_d_x;
  c1_f_x = c1_e_x;
  c1_g_x = c1_f_x;
  c1_absx = muDoubleScalarAbs(c1_g_x);
  c1_h_x = c1_absx;
  c1_i_x = c1_h_x;
  c1_b = muDoubleScalarIsInf(c1_i_x);
  c1_b_b = !c1_b;
  c1_j_x = c1_h_x;
  c1_c_b = muDoubleScalarIsNaN(c1_j_x);
  c1_b1 = !c1_c_b;
  c1_d_b = (c1_b_b && c1_b1);
  if (c1_d_b) {
    if (c1_absx <= 2.2250738585072014E-308) {
      c1_r = 4.94065645841247E-324;
    } else {
      frexp(c1_absx, &c1_exponent);
      c1_b_exponent = c1_exponent;
      c1_r = ldexp(1.0, c1_b_exponent - 53);
    }
  } else {
    c1_r = rtNaN;
  }

  return c1_r;
}

static boolean_T c1_any(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_b_x_data[], int32_T c1_x_size[1])
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  real_T c1_g_a;
  real_T c1_vlen;
  int32_T c1_b_b;
  int32_T c1_c;
  int32_T c1_c_b;
  int32_T c1_d_b;
  int32_T c1_h_a;
  int32_T c1_i2;
  int32_T c1_i_a;
  int32_T c1_ix;
  int32_T c1_vspread;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_y;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_st.site = &c1_ue_emlrtRSI;
  if ((c1_x_size[0] == 1) || ((real_T)c1_x_size[0] != 1.0)) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c1_st, &c1_i_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  c1_y = false;
  c1_vlen = (real_T)c1_x_size[0];
  c1_g_a = c1_vlen;
  c1_c = (int32_T)c1_g_a;
  c1_h_a = c1_c - 1;
  c1_vspread = c1_h_a;
  c1_b_b = c1_vspread;
  c1_i2 = c1_b_b;
  c1_i_a = c1_i2 + 1;
  c1_i2 = c1_i_a;
  c1_b_st.site = &c1_ve_emlrtRSI;
  c1_c_b = c1_i2;
  c1_d_b = c1_c_b;
  if (1 > c1_d_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_d_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  c1_ix = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_ix + 1 <= c1_i2)) {
    if (!c1_b_x_data[c1_ix]) {
      c1_b1 = true;
    } else {
      c1_b1 = false;
    }

    if (!c1_b1) {
      c1_y = true;
      c1_exitg1 = true;
    } else {
      c1_ix++;
    }
  }

  return c1_y;
}

static void c1_sort(SFc1_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c1_sp, c1_emxArray_real32_T *c1_c_x,
                    c1_emxArray_real32_T *c1_d_x)
{
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_loop_ub;
  c1_i = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = 1;
  c1_d_x->size[1] = c1_c_x->size[1];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_sp, c1_d_x, c1_i,
    &c1_md_emlrtRTEI);
  c1_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_d_x->data[c1_i1] = c1_c_x->data[c1_i1];
  }

  c1_c_sort(chartInstance, c1_sp, c1_d_x);
}

static void c1_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real32_T *c1_c_x, int32_T c1_offset, c1_emxArray_int32_T *c1_c_idx,
  c1_emxArray_real32_T *c1_d_x)
{
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_loop_ub;
  c1_i = c1_c_idx->size[0] * c1_c_idx->size[1];
  c1_c_idx->size[0] = 1;
  c1_c_idx->size[1] = c1_b_idx->size[1];
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_c_idx, c1_i,
    &c1_nd_emlrtRTEI);
  c1_loop_ub = c1_b_idx->size[0] * c1_b_idx->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_c_idx->data[c1_i1] = c1_b_idx->data[c1_i1];
  }

  c1_i2 = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = 1;
  c1_d_x->size[1] = c1_c_x->size[1];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_sp, c1_d_x, c1_i2,
    &c1_nd_emlrtRTEI);
  c1_b_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_d_x->data[c1_i3] = c1_c_x->data[c1_i3];
  }

  c1_c_merge_pow2_block(chartInstance, c1_sp, c1_c_idx, c1_d_x, c1_offset);
}

static void c1_merge_block(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_real32_T
  *c1_c_x, int32_T c1_offset, int32_T c1_n, int32_T c1_preSortLevel,
  c1_emxArray_int32_T *c1_b_iwork, c1_emxArray_real32_T *c1_xwork,
  c1_emxArray_int32_T *c1_c_idx, c1_emxArray_real32_T *c1_d_x,
  c1_emxArray_int32_T *c1_c_iwork, c1_emxArray_real32_T *c1_b_xwork)
{
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_loop_ub;
  c1_i = c1_c_idx->size[0] * c1_c_idx->size[1];
  c1_c_idx->size[0] = 1;
  c1_c_idx->size[1] = c1_b_idx->size[1];
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_c_idx, c1_i,
    &c1_od_emlrtRTEI);
  c1_loop_ub = c1_b_idx->size[0] * c1_b_idx->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_c_idx->data[c1_i1] = c1_b_idx->data[c1_i1];
  }

  c1_i2 = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = 1;
  c1_d_x->size[1] = c1_c_x->size[1];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_sp, c1_d_x, c1_i2,
    &c1_od_emlrtRTEI);
  c1_b_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_d_x->data[c1_i3] = c1_c_x->data[c1_i3];
  }

  c1_i4 = c1_c_iwork->size[0];
  c1_c_iwork->size[0] = c1_b_iwork->size[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_c_iwork, c1_i4,
    &c1_od_emlrtRTEI);
  c1_c_loop_ub = c1_b_iwork->size[0] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_c_loop_ub; c1_i5++) {
    c1_c_iwork->data[c1_i5] = c1_b_iwork->data[c1_i5];
  }

  c1_i6 = c1_b_xwork->size[0];
  c1_b_xwork->size[0] = c1_xwork->size[0];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_sp, c1_b_xwork, c1_i6,
    &c1_od_emlrtRTEI);
  c1_d_loop_ub = c1_xwork->size[0] - 1;
  for (c1_i7 = 0; c1_i7 <= c1_d_loop_ub; c1_i7++) {
    c1_b_xwork->data[c1_i7] = c1_xwork->data[c1_i7];
  }

  c1_c_merge_block(chartInstance, c1_sp, c1_c_idx, c1_d_x, c1_offset, c1_n,
                   c1_preSortLevel, c1_c_iwork, c1_b_xwork);
}

static void c1_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
                     c1_emxArray_real32_T *c1_c_x, int32_T c1_offset, int32_T
                     c1_np, int32_T c1_nq, c1_emxArray_int32_T *c1_b_iwork,
                     c1_emxArray_real32_T *c1_xwork, c1_emxArray_int32_T
                     *c1_c_idx, c1_emxArray_real32_T *c1_d_x,
                     c1_emxArray_int32_T *c1_c_iwork, c1_emxArray_real32_T
                     *c1_b_xwork)
{
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_loop_ub;
  c1_i = c1_c_idx->size[0] * c1_c_idx->size[1];
  c1_c_idx->size[0] = 1;
  c1_c_idx->size[1] = c1_b_idx->size[1];
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_c_idx, c1_i,
    &c1_pd_emlrtRTEI);
  c1_loop_ub = c1_b_idx->size[0] * c1_b_idx->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_c_idx->data[c1_i1] = c1_b_idx->data[c1_i1];
  }

  c1_i2 = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = 1;
  c1_d_x->size[1] = c1_c_x->size[1];
  c1_emxEnsureCapacity_real32_T1(chartInstance, c1_sp, c1_d_x, c1_i2,
    &c1_pd_emlrtRTEI);
  c1_b_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_d_x->data[c1_i3] = c1_c_x->data[c1_i3];
  }

  c1_i4 = c1_c_iwork->size[0];
  c1_c_iwork->size[0] = c1_b_iwork->size[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_c_iwork, c1_i4,
    &c1_pd_emlrtRTEI);
  c1_c_loop_ub = c1_b_iwork->size[0] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_c_loop_ub; c1_i5++) {
    c1_c_iwork->data[c1_i5] = c1_b_iwork->data[c1_i5];
  }

  c1_i6 = c1_b_xwork->size[0];
  c1_b_xwork->size[0] = c1_xwork->size[0];
  c1_emxEnsureCapacity_real32_T(chartInstance, c1_sp, c1_b_xwork, c1_i6,
    &c1_pd_emlrtRTEI);
  c1_d_loop_ub = c1_xwork->size[0] - 1;
  for (c1_i7 = 0; c1_i7 <= c1_d_loop_ub; c1_i7++) {
    c1_b_xwork->data[c1_i7] = c1_xwork->data[c1_i7];
  }

  c1_c_merge(chartInstance, c1_sp, c1_c_idx, c1_d_x, c1_offset, c1_np, c1_nq,
             c1_c_iwork, c1_b_xwork);
}

static void c1_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_c_x[19200], c1_emxArray_int32_T *c1_i,
  c1_emxArray_int32_T *c1_j)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_iv[2];
  int32_T c1_iv1[2];
  int32_T c1_iv2[2];
  int32_T c1_b_i;
  int32_T c1_b_idx;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_ii;
  int32_T c1_jj;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_exitg1;
  boolean_T c1_guard1 = false;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_sf_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_b_idx = 0;
  c1_b_i = c1_i->size[0];
  c1_i->size[0] = 19200;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_i, c1_b_i,
    &c1_qd_emlrtRTEI);
  c1_i1 = c1_j->size[0];
  c1_j->size[0] = 19200;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_j, c1_i1,
    &c1_rd_emlrtRTEI);
  c1_ii = 1;
  c1_jj = 1;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_jj <= 160)) {
    c1_guard1 = false;
    if (c1_c_x[(c1_ii + 120 * (c1_jj - 1)) - 1]) {
      c1_b_idx++;
      c1_i->data[c1_b_idx - 1] = c1_ii;
      c1_j->data[c1_b_idx - 1] = c1_jj;
      if (c1_b_idx >= 19200) {
        c1_exitg1 = true;
      } else {
        c1_guard1 = true;
      }
    } else {
      c1_guard1 = true;
    }

    if (c1_guard1) {
      c1_ii++;
      if (c1_ii > 120) {
        c1_ii = 1;
        c1_jj++;
      }
    }
  }

  c1_b = (1 > c1_b_idx);
  if (c1_b) {
    c1_i2 = 0;
  } else {
    c1_i2 = c1_b_idx;
  }

  c1_iv[0] = 1;
  c1_iv[1] = c1_i2;
  c1_b_st.site = &c1_vf_emlrtRSI;
  c1_indexShapeCheck(chartInstance, &c1_b_st, 19200, c1_iv);
  c1_i3 = c1_i->size[0];
  c1_i->size[0] = c1_i2;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_i, c1_i3,
    &c1_sd_emlrtRTEI);
  c1_b1 = (1 > c1_b_idx);
  if (c1_b1) {
    c1_i4 = 0;
  } else {
    c1_i4 = c1_b_idx;
  }

  c1_iv1[0] = 1;
  c1_iv1[1] = c1_i4;
  c1_b_st.site = &c1_uf_emlrtRSI;
  c1_indexShapeCheck(chartInstance, &c1_b_st, 19200, c1_iv1);
  c1_i5 = c1_j->size[0];
  c1_j->size[0] = c1_i4;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_j, c1_i5,
    &c1_td_emlrtRTEI);
  c1_b2 = (1 > c1_b_idx);
  if (c1_b2) {
    c1_i6 = 0;
  } else {
    c1_i6 = c1_b_idx;
  }

  c1_iv2[0] = 1;
  c1_iv2[1] = c1_i6;
  c1_b_st.site = &c1_tf_emlrtRSI;
  c1_indexShapeCheck(chartInstance, &c1_b_st, 19200, c1_iv2);
}

static boolean_T c1_allinrange(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T *c1_c_x, int32_T c1_hi)
{
  real_T c1_b_k;
  real_T c1_d;
  int32_T c1_exitg1;
  int32_T c1_i;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_p;
  (void)chartInstance;
  c1_d = (real_T)c1_c_x->size[0];
  c1_i = (int32_T)c1_d - 1;
  c1_k = 0;
  do {
    c1_exitg1 = 0;
    if (c1_k <= c1_i) {
      c1_b_k = (real_T)c1_k + 1.0;
      if ((c1_c_x->data[(int32_T)c1_b_k - 1] >= 1.0) && (c1_c_x->data[(int32_T)
           c1_b_k - 1] <= (real_T)c1_hi)) {
        c1_b = true;
      } else {
        c1_b = false;
      }

      if (!c1_b) {
        c1_p = false;
        c1_exitg1 = 1;
      } else {
        c1_k++;
      }
    } else {
      c1_p = true;
      c1_exitg1 = 1;
    }
  } while (c1_exitg1 == 0);

  return c1_p;
}

static void c1_eml_sub2ind(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_real_T *c1_d_varargin_1,
  c1_emxArray_real_T *c1_b_varargin_2, c1_emxArray_int32_T *c1_b_idx)
{
  static char_T c1_b_cv1[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't',
    'V', 'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  static char_T c1_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  c1_emxArray_int32_T *c1_b;
  c1_emxArray_real_T *c1_d_varargin_2;
  c1_emxArray_real_T *c1_e_varargin_1;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_c_varargin_2[2];
  real_T c1_f_varargin_1[2];
  real_T c1_b_k;
  real_T c1_x1;
  real_T c1_x2;
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_e_loop_ub;
  int32_T c1_f_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_k;
  int32_T c1_loop_ub;
  boolean_T c1_b_p;
  boolean_T c1_c_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_e_varargin_1, 1, &c1_ud_emlrtRTEI);
  c1_i = c1_e_varargin_1->size[0];
  c1_e_varargin_1->size[0] = c1_d_varargin_1->size[0];
  c1_st.site = &c1_cl_emlrtRSI;
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_e_varargin_1, c1_i,
    &c1_ud_emlrtRTEI);
  c1_loop_ub = c1_d_varargin_1->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_e_varargin_1->data[c1_i1] = c1_d_varargin_1->data[c1_i1];
  }

  if (!c1_allinrange(chartInstance, c1_e_varargin_1, 120)) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c1_sp, &c1_j_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_b_y)));
  }

  c1_emxFree_real_T(chartInstance, &c1_e_varargin_1);
  c1_f_varargin_1[0] = (real_T)c1_d_varargin_1->size[0];
  c1_f_varargin_1[1] = 1.0;
  c1_c_varargin_2[0] = (real_T)c1_b_varargin_2->size[0];
  c1_c_varargin_2[1] = 1.0;
  c1_p = false;
  c1_b_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 2)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_x1 = c1_f_varargin_1[(int32_T)c1_b_k - 1];
    c1_x2 = c1_c_varargin_2[(int32_T)c1_b_k - 1];
    c1_c_p = (c1_x1 == c1_x2);
    if (!c1_c_p) {
      c1_b_p = false;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (c1_b_p) {
    c1_p = true;
  }

  if (!c1_p) {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    sf_mex_call(c1_sp, &c1_k_emlrtMCI, "error", 0U, 2U, 14, c1_c_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_d_y)));
  }

  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_d_varargin_2, 1, &c1_ud_emlrtRTEI);
  c1_i2 = c1_d_varargin_2->size[0];
  c1_d_varargin_2->size[0] = c1_b_varargin_2->size[0];
  c1_st.site = &c1_cl_emlrtRSI;
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_d_varargin_2, c1_i2,
    &c1_ud_emlrtRTEI);
  c1_b_loop_ub = c1_b_varargin_2->size[0] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_d_varargin_2->data[c1_i3] = c1_b_varargin_2->data[c1_i3];
  }

  if (!c1_allinrange(chartInstance, c1_d_varargin_2, 160)) {
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c1_sp, &c1_j_emlrtMCI, "error", 0U, 2U, 14, c1_e_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_f_y)));
  }

  c1_emxFree_real_T(chartInstance, &c1_d_varargin_2);
  c1_i4 = c1_b_idx->size[0];
  c1_b_idx->size[0] = c1_d_varargin_1->size[0];
  c1_st.site = &c1_yl_emlrtRSI;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_b_idx, c1_i4,
    &c1_vd_emlrtRTEI);
  c1_c_loop_ub = c1_d_varargin_1->size[0] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_c_loop_ub; c1_i5++) {
    c1_b_idx->data[c1_i5] = (int32_T)c1_d_varargin_1->data[c1_i5];
  }

  c1_emxInit_int32_T(chartInstance, c1_sp, &c1_b, 1, &c1_wd_emlrtRTEI);
  c1_i6 = c1_b->size[0];
  c1_b->size[0] = c1_b_varargin_2->size[0];
  c1_st.site = &c1_xl_emlrtRSI;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_b, c1_i6,
    &c1_wd_emlrtRTEI);
  c1_d_loop_ub = c1_b_varargin_2->size[0] - 1;
  for (c1_i7 = 0; c1_i7 <= c1_d_loop_ub; c1_i7++) {
    c1_b->data[c1_i7] = (int32_T)c1_b_varargin_2->data[c1_i7] - 1;
  }

  c1_i8 = c1_b->size[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_b, c1_i8,
    &c1_xd_emlrtRTEI);
  c1_e_loop_ub = c1_b->size[0] - 1;
  for (c1_i9 = 0; c1_i9 <= c1_e_loop_ub; c1_i9++) {
    c1_b->data[c1_i9] *= 120;
  }

  c1_i10 = c1_b_idx->size[0];
  c1_st.site = &c1_xl_emlrtRSI;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_b_idx, c1_i10,
    &c1_yd_emlrtRTEI);
  c1_f_loop_ub = c1_b_idx->size[0] - 1;
  for (c1_i11 = 0; c1_i11 <= c1_f_loop_ub; c1_i11++) {
    c1_b_idx->data[c1_i11] += c1_b->data[c1_i11];
  }

  c1_emxFree_int32_T(chartInstance, &c1_b);
}

static void c1_medfilt2(SFc1_flightControlSystemInstanceStruct *chartInstance,
  real_T c1_d_varargin_1[19200], real_T c1_b[19200])
{
  static int32_T c1_offsets[25] = { -250, -249, -248, -247, -246, -126, -125,
    -124, -123, -122, -2, -1, 0, 1, 2, 122, 123, 124, 125, 126, 246, 247, 248,
    249, 250 };

  real_T c1_domainSizeT[2];
  real_T c1_sizeB[2];
  real_T c1_startIdxT[2];
  real_T c1_c_i;
  real_T c1_c_j;
  real_T c1_g_a;
  real_T c1_h_a;
  real_T c1_i_a;
  real_T c1_j_a;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_b_j;
  int32_T c1_c;
  int32_T c1_c_c;
  int32_T c1_d_c;
  int32_T c1_d_i;
  int32_T c1_d_j;
  int32_T c1_e_i;
  int32_T c1_e_j;
  int32_T c1_f_i;
  int32_T c1_f_j;
  int32_T c1_g_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_j;
  for (c1_j = 0; c1_j < 2; c1_j++) {
    c1_c_j = (real_T)c1_j + 1.0;
    for (c1_i = 0; c1_i < 124; c1_i++) {
      c1_c_i = (real_T)c1_i + 1.0;
      chartInstance->c1_Apad[((int32_T)c1_c_i + 124 * ((int32_T)c1_c_j - 1)) - 1]
        = 0.0;
    }
  }

  for (c1_b_j = 0; c1_b_j < 2; c1_b_j++) {
    for (c1_b_i = 0; c1_b_i < 124; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i + 1.0;
      chartInstance->c1_Apad[((int32_T)c1_c_i + 124 * (c1_b_j + 162)) - 1] = 0.0;
    }
  }

  for (c1_d_j = 0; c1_d_j < 160; c1_d_j++) {
    c1_c_j = (real_T)c1_d_j + 1.0;
    for (c1_d_i = 0; c1_d_i < 2; c1_d_i++) {
      c1_c_i = (real_T)c1_d_i + 1.0;
      c1_g_a = c1_c_j;
      c1_c = (int32_T)c1_g_a;
      chartInstance->c1_Apad[((int32_T)c1_c_i + 124 * (c1_c + 1)) - 1] = 0.0;
    }
  }

  for (c1_e_j = 0; c1_e_j < 160; c1_e_j++) {
    c1_c_j = (real_T)c1_e_j + 1.0;
    for (c1_e_i = 0; c1_e_i < 2; c1_e_i++) {
      c1_h_a = c1_c_j;
      c1_b_c = (int32_T)c1_h_a;
      chartInstance->c1_Apad[(c1_e_i + 124 * (c1_b_c + 1)) + 122] = 0.0;
    }
  }

  for (c1_f_j = 0; c1_f_j < 160; c1_f_j++) {
    c1_c_j = (real_T)c1_f_j + 1.0;
    for (c1_g_i = 0; c1_g_i < 120; c1_g_i++) {
      c1_c_i = (real_T)c1_g_i + 1.0;
      c1_i_a = c1_c_i;
      c1_c_c = (int32_T)c1_i_a;
      c1_j_a = c1_c_j;
      c1_d_c = (int32_T)c1_j_a;
      chartInstance->c1_Apad[(c1_c_c + 124 * (c1_d_c + 1)) + 1] =
        c1_d_varargin_1[((int32_T)c1_c_i + 120 * ((int32_T)c1_c_j - 1)) - 1];
    }
  }

  for (c1_f_i = 0; c1_f_i < 2; c1_f_i++) {
    c1_domainSizeT[c1_f_i] = 5.0;
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_startIdxT[c1_i1] = 2.0;
  }

  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_sizeB[c1_i2] = 120.0 + 40.0 * (real_T)c1_i2;
  }

  ordfilt2_real64(&chartInstance->c1_Apad[0], 124.0, &c1_startIdxT[0],
                  &c1_offsets[0], 25.0, &c1_domainSizeT[0], 12.0, &c1_b[0],
                  &c1_sizeB[0], true);
}

static void c1_chcenters(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, creal_T c1_d_varargin_1[19200], c1_emxArray_real_T
  *c1_centers, c1_emxArray_real_T *c1_metric)
{
  c1_emxArray_int32_T *c1_iidx;
  c1_emxArray_int32_T *c1_r;
  c1_emxArray_real_T *c1_b_centers;
  c1_emxArray_real_T *c1_b_varargin_2;
  c1_emxArray_real_T *c1_d_x;
  c1_emxArray_real_T *c1_e_x;
  c1_emxArray_real_T *c1_j_x;
  c1_emxArray_real_T *c1_ndx;
  c1_emxArray_real_T *c1_sortIdx;
  c1_emxArray_sBO2RC5RVZVTbundPSRqHn *c1_b_s;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  creal_T c1_c_x;
  real_T c1_b;
  real_T c1_c_accumMatrixRe;
  real_T c1_c_idx;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d_k;
  real_T c1_f_x;
  real_T c1_g_a;
  real_T c1_g_x;
  real_T c1_x1;
  real_T c1_x2;
  real_T c1_y;
  int32_T c1_iv[2];
  int32_T c1_iv1[2];
  int32_T c1_tmp_data[2];
  int32_T c1_b_sortIdx[1];
  int32_T c1_b_i;
  int32_T c1_b_idx;
  int32_T c1_b_j;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_c_centers;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_d_idx;
  int32_T c1_d_loop_ub;
  int32_T c1_e_b;
  int32_T c1_e_idx;
  int32_T c1_e_loop_ub;
  int32_T c1_f_b;
  int32_T c1_f_idx;
  int32_T c1_f_loop_ub;
  int32_T c1_g_idx;
  int32_T c1_g_loop_ub;
  int32_T c1_h_a;
  int32_T c1_h_idx;
  int32_T c1_h_loop_ub;
  int32_T c1_h_x;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_a;
  int32_T c1_i_loop_ub;
  int32_T c1_i_x;
  int32_T c1_j;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_k_loop_ub;
  int32_T c1_l_loop_ub;
  int32_T c1_loop_ub;
  int32_T c1_m_loop_ub;
  int32_T c1_n;
  int32_T c1_n_loop_ub;
  int32_T c1_nrows;
  int32_T c1_nrowx;
  boolean_T c1_b_x_data[19200];
  boolean_T c1_bw[19200];
  boolean_T c1_b1;
  boolean_T c1_b_b;
  boolean_T c1_c_b;
  boolean_T c1_d_b;
  boolean_T c1_exitg1;
  boolean_T c1_flat;
  boolean_T c1_guard1 = false;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_centers->size[0] = 0;
  c1_centers->size[1] = 0;
  c1_metric->size[0] = 0;
  c1_metric->size[1] = 0;
  for (c1_k = 0; c1_k < 19200; c1_k++) {
    c1_b_k = c1_k;
    c1_c_x = c1_d_varargin_1[c1_b_k];
    c1_x1 = c1_c_x.re;
    c1_x2 = c1_c_x.im;
    c1_g_a = c1_x1;
    c1_b = c1_x2;
    c1_y = muDoubleScalarHypot(c1_g_a, c1_b);
    chartInstance->c1_accumMatrixRe[c1_b_k] = c1_y;
  }

  c1_c_accumMatrixRe = chartInstance->c1_accumMatrixRe[0];
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_bw[c1_i] = (chartInstance->c1_accumMatrixRe[c1_i] == c1_c_accumMatrixRe);
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_b_x_data[c1_i1] = c1_bw[c1_i1];
  }

  c1_flat = true;
  c1_c_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k < 19200)) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    if (!c1_b_x_data[(int32_T)c1_d_k - 1]) {
      c1_flat = false;
      c1_exitg1 = true;
    } else {
      c1_c_k++;
    }
  }

  if (!c1_flat) {
    c1_emxInit_sBO2RC5RVZVTbundPSRqHnH(chartInstance, c1_sp, &c1_b_s, 1,
      &c1_oe_emlrtRTEI);
    c1_st.site = &c1_gg_emlrtRSI;
    for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
      chartInstance->c1_b_accumMatrixRe[c1_i2] = chartInstance->
        c1_accumMatrixRe[c1_i2];
    }

    c1_medfilt2(chartInstance, chartInstance->c1_b_accumMatrixRe,
                chartInstance->c1_Hd);
    c1_st.site = &c1_hg_emlrtRSI;
    for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
      chartInstance->c1_b_Hd[c1_i3] = chartInstance->c1_Hd[c1_i3];
    }

    c1_imhmax(chartInstance, &c1_st, chartInstance->c1_b_Hd,
              chartInstance->c1_Hd);
    c1_st.site = &c1_ig_emlrtRSI;
    for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
      chartInstance->c1_c_Hd[c1_i4] = chartInstance->c1_Hd[c1_i4];
    }

    c1_imregionalmax(chartInstance, &c1_st, chartInstance->c1_c_Hd, c1_bw);
    c1_st.site = &c1_jg_emlrtRSI;
    c1_regionprops(chartInstance, &c1_st, c1_bw, chartInstance->c1_accumMatrixRe,
                   c1_b_s);
    if (c1_b_s->size[0] != 0) {
      c1_i5 = c1_centers->size[0] * c1_centers->size[1];
      c1_centers->size[0] = c1_b_s->size[0];
      c1_centers->size[1] = 2;
      c1_st.site = &c1_nl_emlrtRSI;
      c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_centers, c1_i5,
        &c1_ae_emlrtRTEI);
      c1_d = (real_T)c1_b_s->size[0];
      c1_i6 = (int32_T)c1_d - 1;
      for (c1_b_idx = 0; c1_b_idx <= c1_i6; c1_b_idx++) {
        c1_c_idx = (real_T)c1_b_idx + 1.0;
        c1_i8 = c1_centers->size[0];
        c1_i9 = (int32_T)c1_c_idx;
        c1_i10 = emlrtDynamicBoundsCheckR2012b(c1_i9, 1, c1_i8, &c1_qc_emlrtBCI,
          c1_sp);
        for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
          c1_tmp_data[c1_i11] = c1_i11;
        }

        for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
          c1_iv[c1_i12] = 1 + c1_i12;
        }

        for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
          c1_iv1[c1_i13] = 1 + c1_i13;
        }

        emlrtSubAssignSizeCheckR2012b(c1_iv, 2, c1_iv1, 2, &c1_b_emlrtECI, c1_sp);
        c1_i16 = c1_i10 - 1;
        for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
          c1_i19 = c1_b_s->size[0];
          c1_i22 = (int32_T)c1_c_idx;
          c1_centers->data[c1_i16 + c1_centers->size[0] * c1_tmp_data[c1_i17]] =
            c1_b_s->data[emlrtDynamicBoundsCheckR2012b(c1_i22, 1, c1_i19,
            &c1_sc_emlrtBCI, c1_sp) - 1].WeightedCentroid[c1_i17];
        }
      }

      c1_d1 = (real_T)c1_centers->size[0];
      c1_i7 = (int32_T)(((-1.0 - c1_d1) + 1.0) / -1.0);
      emlrtForLoopVectorCheckR2012b(c1_d1, -1.0, 1.0, mxDOUBLE_CLASS, c1_i7,
        &c1_hj_emlrtRTEI, c1_sp);
      c1_d_idx = 0;
      c1_emxInit_real_T(chartInstance, c1_sp, &c1_d_x, 2, &c1_de_emlrtRTEI);
      c1_emxInit_real_T(chartInstance, c1_sp, &c1_e_x, 2, &c1_ie_emlrtRTEI);
      while (c1_d_idx <= c1_i7 - 1) {
        c1_c_idx = c1_d1 + -(real_T)c1_d_idx;
        c1_i14 = c1_centers->size[0];
        c1_i15 = (int32_T)c1_c_idx;
        c1_f_x = c1_centers->data[emlrtDynamicBoundsCheckR2012b(c1_i15, 1,
          c1_i14, &c1_rc_emlrtBCI, c1_sp) - 1];
        c1_c_b = muDoubleScalarIsNaN(c1_f_x);
        c1_guard1 = false;
        if (c1_c_b) {
          c1_guard1 = true;
        } else {
          c1_i21 = c1_centers->size[0];
          c1_i23 = (int32_T)c1_c_idx;
          c1_g_x = c1_centers->data[(emlrtDynamicBoundsCheckR2012b(c1_i23, 1,
            c1_i21, &c1_tc_emlrtBCI, c1_sp) + c1_centers->size[0]) - 1];
          c1_d_b = muDoubleScalarIsNaN(c1_g_x);
          if (c1_d_b) {
            c1_guard1 = true;
          }
        }

        if (c1_guard1) {
          c1_st.site = &c1_kg_emlrtRSI;
          c1_i24 = c1_d_x->size[0] * c1_d_x->size[1];
          c1_d_x->size[0] = c1_centers->size[0];
          c1_d_x->size[1] = c1_centers->size[1];
          c1_b_st.site = &c1_kg_emlrtRSI;
          c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_d_x, c1_i24,
            &c1_de_emlrtRTEI);
          c1_b_loop_ub = c1_centers->size[0] * c1_centers->size[1] - 1;
          for (c1_i27 = 0; c1_i27 <= c1_b_loop_ub; c1_i27++) {
            c1_d_x->data[c1_i27] = c1_centers->data[c1_i27];
          }

          c1_e_idx = (int32_T)c1_c_idx;
          c1_b_st.site = &c1_mi_emlrtRSI;
          c1_f_idx = c1_e_idx;
          c1_g_idx = c1_f_idx;
          c1_d2 = (real_T)c1_d_x->size[0];
          c1_n = (int32_T)c1_d2;
          c1_p = true;
          if (c1_g_idx > c1_n) {
            c1_p = false;
          } else {
            c1_h_x = c1_g_idx;
            c1_i_x = c1_h_x;
            if (c1_g_idx != c1_i_x) {
              c1_p = false;
            }
          }

          if (!c1_p) {
            c1_b_y = NULL;
            sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2,
              1, 25), false);
            c1_c_y = NULL;
            sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2,
              1, 25), false);
            sf_mex_call(&c1_b_st, &c1_u_emlrtMCI, "error", 0U, 2U, 14, c1_b_y,
                        14, sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c1_b_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
          }

          c1_b_st.site = &c1_ni_emlrtRSI;
          c1_h_idx = c1_e_idx;
          c1_nrowx = c1_d_x->size[0];
          c1_nrows = c1_nrowx - 1;
          c1_c_st.site = &c1_oi_emlrtRSI;
          for (c1_j = 0; c1_j < 2; c1_j++) {
            c1_b_j = c1_j;
            c1_c_st.site = &c1_pi_emlrtRSI;
            c1_h_a = c1_h_idx;
            c1_e_b = c1_nrows;
            c1_i_a = c1_h_a;
            c1_f_b = c1_e_b;
            if (c1_i_a > c1_f_b) {
              c1_overflow = false;
            } else {
              c1_overflow = (c1_f_b > 2147483646);
            }

            if (c1_overflow) {
              c1_d_st.site = &c1_kb_emlrtRSI;
              c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
            }

            for (c1_b_i = c1_h_idx; c1_b_i <= c1_nrows; c1_b_i++) {
              c1_d_x->data[(c1_b_i + c1_d_x->size[0] * c1_b_j) - 1] =
                c1_d_x->data[c1_b_i + c1_d_x->size[0] * c1_b_j];
            }
          }

          if (!(c1_nrows <= c1_nrowx)) {
            c1_d_y = NULL;
            sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            c1_e_y = NULL;
            sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            sf_mex_call(&c1_b_st, &c1_v_emlrtMCI, "error", 0U, 2U, 14, c1_d_y,
                        14, sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c1_b_st, NULL, "message", 1U, 1U, 14, c1_e_y)));
          }

          c1_b1 = (1 > c1_nrows);
          if (c1_b1) {
            c1_i34 = -1;
          } else {
            c1_i34 = c1_nrows - 1;
          }

          c1_i36 = c1_e_x->size[0] * c1_e_x->size[1];
          c1_e_x->size[0] = c1_i34 + 1;
          c1_e_x->size[1] = 2;
          c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_e_x, c1_i36,
            &c1_ie_emlrtRTEI);
          for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
            c1_g_loop_ub = c1_i34;
            for (c1_i41 = 0; c1_i41 <= c1_g_loop_ub; c1_i41++) {
              c1_e_x->data[c1_i41 + c1_e_x->size[0] * c1_i38] = c1_d_x->
                data[c1_i41 + c1_d_x->size[0] * c1_i38];
            }
          }

          c1_i39 = c1_d_x->size[0] * c1_d_x->size[1];
          c1_d_x->size[0] = c1_e_x->size[0];
          c1_d_x->size[1] = 2;
          c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_d_x, c1_i39,
            &c1_ke_emlrtRTEI);
          c1_h_loop_ub = c1_e_x->size[0] * c1_e_x->size[1] - 1;
          for (c1_i42 = 0; c1_i42 <= c1_h_loop_ub; c1_i42++) {
            c1_d_x->data[c1_i42] = c1_e_x->data[c1_i42];
          }

          c1_i44 = c1_centers->size[0] * c1_centers->size[1];
          c1_centers->size[0] = c1_d_x->size[0];
          c1_centers->size[1] = 2;
          c1_st.site = &c1_kg_emlrtRSI;
          c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_centers, c1_i44,
            &c1_de_emlrtRTEI);
          c1_j_loop_ub = c1_d_x->size[0] * c1_d_x->size[1] - 1;
          for (c1_i46 = 0; c1_i46 <= c1_j_loop_ub; c1_i46++) {
            c1_centers->data[c1_i46] = c1_d_x->data[c1_i46];
          }
        }

        c1_d_idx++;
      }

      c1_emxFree_real_T(chartInstance, &c1_e_x);
      c1_emxFree_real_T(chartInstance, &c1_d_x);
      c1_b_b = (c1_centers->size[0] == 0);
      if (!c1_b_b) {
        c1_emxInit_real_T1(chartInstance, c1_sp, &c1_ndx, 1, &c1_qe_emlrtRTEI);
        c1_st.site = &c1_lg_emlrtRSI;
        c1_i18 = c1_centers->size[0] - 1;
        c1_i20 = c1_ndx->size[0];
        c1_ndx->size[0] = c1_i18 + 1;
        c1_b_st.site = &c1_lg_emlrtRSI;
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_ndx, c1_i20,
          &c1_ce_emlrtRTEI);
        c1_loop_ub = c1_i18;
        for (c1_i25 = 0; c1_i25 <= c1_loop_ub; c1_i25++) {
          c1_ndx->data[c1_i25] = c1_centers->data[c1_i25 + c1_centers->size[0]];
        }

        c1_emxInit_real_T1(chartInstance, &c1_st, &c1_b_varargin_2, 1,
                           &c1_ee_emlrtRTEI);
        c1_b_st.site = &c1_lg_emlrtRSI;
        c1_b_round(chartInstance, &c1_b_st, c1_ndx);
        c1_i26 = c1_centers->size[0] - 1;
        c1_i28 = c1_b_varargin_2->size[0];
        c1_b_varargin_2->size[0] = c1_i26 + 1;
        c1_b_st.site = &c1_lg_emlrtRSI;
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_b_varargin_2,
          c1_i28, &c1_ee_emlrtRTEI);
        c1_c_loop_ub = c1_i26;
        for (c1_i29 = 0; c1_i29 <= c1_c_loop_ub; c1_i29++) {
          c1_b_varargin_2->data[c1_i29] = c1_centers->data[c1_i29];
        }

        c1_emxInit_int32_T(chartInstance, &c1_st, &c1_r, 1, &c1_ec_emlrtRTEI);
        c1_b_st.site = &c1_lg_emlrtRSI;
        c1_b_round(chartInstance, &c1_b_st, c1_b_varargin_2);
        c1_b_st.site = &c1_wf_emlrtRSI;
        c1_eml_sub2ind(chartInstance, &c1_b_st, c1_ndx, c1_b_varargin_2, c1_r);
        c1_i30 = c1_ndx->size[0];
        c1_ndx->size[0] = c1_r->size[0];
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_ndx, c1_i30,
          &c1_cb_emlrtRTEI);
        c1_d_loop_ub = c1_r->size[0] - 1;
        for (c1_i31 = 0; c1_i31 <= c1_d_loop_ub; c1_i31++) {
          c1_ndx->data[c1_i31] = (real_T)c1_r->data[c1_i31];
        }

        c1_emxFree_int32_T(chartInstance, &c1_r);
        c1_i32 = c1_b_varargin_2->size[0];
        c1_b_varargin_2->size[0] = c1_ndx->size[0];
        c1_st.site = &c1_lg_emlrtRSI;
        c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_b_varargin_2,
          c1_i32, &c1_fe_emlrtRTEI);
        c1_e_loop_ub = c1_ndx->size[0] - 1;
        for (c1_i33 = 0; c1_i33 <= c1_e_loop_ub; c1_i33++) {
          c1_i35 = (int32_T)c1_ndx->data[c1_i33];
          c1_b_varargin_2->data[c1_i33] = chartInstance->
            c1_Hd[emlrtDynamicBoundsCheckR2012b(c1_i35, 1, 19200,
            &c1_uc_emlrtBCI, c1_sp) - 1];
        }

        c1_emxFree_real_T(chartInstance, &c1_ndx);
        c1_i37 = c1_metric->size[0] * c1_metric->size[1];
        c1_metric->size[0] = c1_b_varargin_2->size[0];
        c1_metric->size[1] = 1;
        c1_st.site = &c1_lg_emlrtRSI;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_metric, c1_i37,
          &c1_ge_emlrtRTEI);
        c1_f_loop_ub = c1_b_varargin_2->size[0] - 1;
        for (c1_i40 = 0; c1_i40 <= c1_f_loop_ub; c1_i40++) {
          c1_metric->data[c1_i40] = c1_b_varargin_2->data[c1_i40];
        }

        c1_emxFree_real_T(chartInstance, &c1_b_varargin_2);
        c1_emxInit_real_T(chartInstance, c1_sp, &c1_j_x, 2, &c1_he_emlrtRTEI);
        c1_st.site = &c1_mg_emlrtRSI;
        c1_i43 = c1_j_x->size[0] * c1_j_x->size[1];
        c1_j_x->size[0] = c1_metric->size[0];
        c1_j_x->size[1] = c1_metric->size[1];
        c1_b_st.site = &c1_mg_emlrtRSI;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_b_st, c1_j_x, c1_i43,
          &c1_he_emlrtRTEI);
        c1_i_loop_ub = c1_metric->size[0] * c1_metric->size[1] - 1;
        for (c1_i45 = 0; c1_i45 <= c1_i_loop_ub; c1_i45++) {
          c1_j_x->data[c1_i45] = c1_metric->data[c1_i45];
        }

        c1_emxInit_real_T(chartInstance, &c1_st, &c1_sortIdx, 2,
                          &c1_pe_emlrtRTEI);
        c1_emxInit_int32_T1(chartInstance, &c1_st, &c1_iidx, 2, &c1_pe_emlrtRTEI);
        c1_b_st.site = &c1_si_emlrtRSI;
        c1_d_sort(chartInstance, &c1_b_st, c1_j_x, c1_iidx);
        c1_i47 = c1_sortIdx->size[0] * c1_sortIdx->size[1];
        c1_sortIdx->size[0] = c1_iidx->size[0];
        c1_sortIdx->size[1] = 1;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_sortIdx, c1_i47,
          &c1_je_emlrtRTEI);
        c1_k_loop_ub = c1_iidx->size[0] * c1_iidx->size[1] - 1;
        for (c1_i48 = 0; c1_i48 <= c1_k_loop_ub; c1_i48++) {
          c1_sortIdx->data[c1_i48] = (real_T)c1_iidx->data[c1_i48];
        }

        c1_emxFree_int32_T(chartInstance, &c1_iidx);
        c1_i49 = c1_metric->size[0] * c1_metric->size[1];
        c1_metric->size[0] = c1_j_x->size[0];
        c1_metric->size[1] = 1;
        c1_st.site = &c1_mg_emlrtRSI;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_metric, c1_i49,
          &c1_le_emlrtRTEI);
        c1_l_loop_ub = c1_j_x->size[0] * c1_j_x->size[1] - 1;
        for (c1_i50 = 0; c1_i50 <= c1_l_loop_ub; c1_i50++) {
          c1_metric->data[c1_i50] = c1_j_x->data[c1_i50];
        }

        c1_emxFree_real_T(chartInstance, &c1_j_x);
        c1_emxInit_real_T(chartInstance, c1_sp, &c1_b_centers, 2,
                          &c1_me_emlrtRTEI);
        c1_c_centers = c1_centers->size[0];
        c1_b_sortIdx[0] = c1_sortIdx->size[0];
        c1_i51 = c1_b_centers->size[0] * c1_b_centers->size[1];
        c1_b_centers->size[0] = c1_b_sortIdx[0];
        c1_b_centers->size[1] = 2;
        c1_st.site = &c1_ml_emlrtRSI;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_b_centers, c1_i51,
          &c1_me_emlrtRTEI);
        for (c1_i52 = 0; c1_i52 < 2; c1_i52++) {
          c1_m_loop_ub = c1_b_sortIdx[0] - 1;
          for (c1_i54 = 0; c1_i54 <= c1_m_loop_ub; c1_i54++) {
            c1_i55 = (int32_T)c1_sortIdx->data[c1_i54];
            c1_b_centers->data[c1_i54 + c1_b_centers->size[0] * c1_i52] =
              c1_centers->data[(emlrtDynamicBoundsCheckR2012b(c1_i55, 1,
              c1_c_centers, &c1_vc_emlrtBCI, c1_sp) + c1_centers->size[0] *
                                c1_i52) - 1];
          }
        }

        c1_emxFree_real_T(chartInstance, &c1_sortIdx);
        c1_i53 = c1_centers->size[0] * c1_centers->size[1];
        c1_centers->size[0] = c1_b_centers->size[0];
        c1_centers->size[1] = c1_b_centers->size[1];
        c1_st.site = &c1_ml_emlrtRSI;
        c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_centers, c1_i53,
          &c1_ne_emlrtRTEI);
        c1_n_loop_ub = c1_b_centers->size[0] * c1_b_centers->size[1] - 1;
        for (c1_i56 = 0; c1_i56 <= c1_n_loop_ub; c1_i56++) {
          c1_centers->data[c1_i56] = c1_b_centers->data[c1_i56];
        }

        c1_emxFree_real_T(chartInstance, &c1_b_centers);
      }
    }

    c1_emxFree_sBO2RC5RVZVTbundPSRqHnH(chartInstance, &c1_b_s);
  }
}

static void c1_imhmax(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real_T c1_I[19200], real_T
                      c1_b_J[19200])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_b_I[19200];
  real_T c1_imSizeT[2];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_ng_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_b_J[c1_i] = c1_I[c1_i] - 0.15;
  }

  c1_b_st.site = &c1_og_emlrtRSI;
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    chartInstance->c1_J[c1_i1] = c1_b_J[c1_i1];
  }

  c1_validateattributes(chartInstance, &c1_b_st, chartInstance->c1_J);
  c1_b_st.site = &c1_pg_emlrtRSI;
  for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
    c1_b_I[c1_i2] = c1_I[c1_i2];
  }

  c1_validateattributes(chartInstance, &c1_b_st, c1_b_I);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_imSizeT[c1_i3] = 120.0 + 40.0 * (real_T)c1_i3;
  }

  ippreconstruct_real64(&c1_b_J[0], &c1_I[0], &c1_imSizeT[0], 2.0);
}

static void c1_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_g_a[19200])
{
  static char_T c1_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'c', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c1_b_cv1[5] = { 'i', 'n', 'p', 'u', 't' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_b_k;
  real_T c1_c_x;
  real_T c1_d_x;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 19200)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_c_x = c1_g_a[(int32_T)c1_b_k - 1];
    c1_d_x = c1_c_x;
    c1_b_b = muDoubleScalarIsNaN(c1_d_x);
    c1_b_p = !c1_b_b;
    if (c1_b_p) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c1_st, &c1_m_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }
}

static void c1_imregionalmax(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_d_varargin_1[19200],
  boolean_T c1_c_BW[19200])
{
  static char_T c1_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'g', 'i', 'o', 'n', 'a', 'l', 'm', 'a', 'x', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c1_b_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c1_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'I', ',' };

  emlrtStack c1_b_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_connSizeT[2];
  real_T c1_imSizeT[2];
  real_T c1_b_k;
  real_T c1_c_x;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_e_x;
  int32_T c1_c_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_k;
  boolean_T c1_conn[9];
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_qg_emlrtRSI;
  c1_b_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 19200)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_c_x = c1_d_varargin_1[(int32_T)c1_b_k - 1];
    c1_d_x = c1_c_x;
    c1_b_b = muDoubleScalarIsNaN(c1_d_x);
    c1_b_p = !c1_b_b;
    if (c1_b_p) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c1_b_st, &c1_m_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_b_st, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  c1_st.site = &c1_rg_emlrtRSI;
  for (c1_c_k = 0; c1_c_k < 19200; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_e_x = c1_d_varargin_1[(int32_T)c1_d_k - 1];
    c1_c_b = muDoubleScalarIsNaN(c1_e_x);
    if (c1_c_b) {
      c1_d_y = NULL;
      sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        19), false);
      c1_e_y = NULL;
      sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        19), false);
      sf_mex_call(&c1_st, &c1_l_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                  sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c1_st, NULL, "message", 1U, 1U, 14, c1_e_y)));
    }
  }

  c1_st.site = &c1_sg_emlrtRSI;
  for (c1_i = 0; c1_i < 9; c1_i++) {
    c1_conn[c1_i] = true;
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_imSizeT[c1_i1] = 120.0 + 40.0 * (real_T)c1_i1;
  }

  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_connSizeT[c1_i2] = 3.0;
  }

  imregionalmax_real64(&c1_d_varargin_1[0], &c1_c_BW[0], 2.0, &c1_imSizeT[0],
                       &c1_conn[0], 2.0, &c1_connSizeT[0]);
}

static void c1_regionprops(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200], real_T
  c1_b_varargin_2[19200], c1_emxArray_sBO2RC5RVZVTbundPSRqHn *c1_outstats)
{
  static char_T c1_b_cv[31] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'r', 'e', 'g',
    'i', 'o', 'n', 'p', 'r', 'o', 'p', 's', ':', 's', 'i', 'z', 'e', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h' };

  c1_emxArray_int32_T *c1_b_regionLengths;
  c1_emxArray_int32_T *c1_idxCount;
  c1_emxArray_int32_T *c1_regionLengths;
  c1_emxArray_real_T *c1_regionIndices;
  c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_stats;
  c1_sHtk0WM4OMtyqkehwQYcq2 c1_statsAlreadyComputed;
  c1_s_VSLwMee4Kv1oTF0BcoITHB c1_CC;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_imageSize[2];
  real_T c1_b_k;
  real_T c1_b_numObjs;
  real_T c1_b_vIdx;
  real_T c1_c_numObjs;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d_k;
  real_T c1_d_numObjs;
  real_T c1_f_k;
  real_T c1_numObjs;
  real_T c1_x1;
  real_T c1_x2;
  int32_T c1_b_loop_ub;
  int32_T c1_b_stats;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_dim;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_vIdx;
  boolean_T c1_e_varargin_1[19200];
  boolean_T c1_b;
  boolean_T c1_b_p;
  boolean_T c1_c_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_emxInitStruct_s_VSLwMee4Kv1oTF0(chartInstance, c1_sp, &c1_CC,
    &c1_we_emlrtRTEI);
  c1_st.site = &c1_tg_emlrtRSI;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_e_varargin_1[c1_i] = c1_d_varargin_1[c1_i];
  }

  c1_bwconncomp(chartInstance, &c1_st, c1_e_varargin_1, &c1_CC);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_imageSize[c1_i1] = c1_CC.ImageSize[c1_i1];
  }

  c1_numObjs = c1_CC.NumObjects;
  c1_st.site = &c1_ug_emlrtRSI;
  c1_b_numObjs = c1_numObjs;
  c1_p = false;
  c1_b_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 2)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_x1 = c1_imageSize[(int32_T)c1_b_k - 1];
    c1_x2 = 120.0 + 40.0 * (real_T)((int32_T)c1_b_k - 1);
    c1_c_p = (c1_x1 == c1_x2);
    if (!c1_c_p) {
      c1_b_p = false;
      c1_exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (c1_b_p) {
    c1_p = true;
  }

  if (!c1_p) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c1_st, &c1_n_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_b_y)));
  }

  c1_emxInit_s_nrlUwWofUDGxo1t78e6dw(chartInstance, &c1_st, &c1_stats, 1,
    &c1_xe_emlrtRTEI);
  c1_b_st.site = &c1_wh_emlrtRSI;
  c1_c_numObjs = c1_b_numObjs;
  c1_c_st.site = &c1_xh_emlrtRSI;
  c1_repmat(chartInstance, &c1_c_st, c1_c_numObjs, c1_outstats);
  c1_st.site = &c1_vg_emlrtRSI;
  c1_initializeStatsStruct(chartInstance, &c1_st, c1_numObjs, c1_stats,
    &c1_statsAlreadyComputed);
  c1_st.site = &c1_wg_emlrtRSI;
  c1_d_numObjs = c1_numObjs;
  c1_statsAlreadyComputed.PixelIdxList = true;
  if (c1_d_numObjs != 0.0) {
    c1_emxInit_real_T1(chartInstance, &c1_st, &c1_regionIndices, 1,
                       &c1_af_emlrtRTEI);
    c1_i2 = c1_regionIndices->size[0];
    c1_regionIndices->size[0] = c1_CC.RegionIndices->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_regionIndices, c1_i2,
      &c1_re_emlrtRTEI);
    c1_loop_ub = c1_CC.RegionIndices->size[0] - 1;
    for (c1_i4 = 0; c1_i4 <= c1_loop_ub; c1_i4++) {
      c1_regionIndices->data[c1_i4] = c1_CC.RegionIndices->data[c1_i4];
    }

    c1_emxInit_int32_T(chartInstance, &c1_st, &c1_regionLengths, 1,
                       &c1_ye_emlrtRTEI);
    c1_i6 = c1_regionLengths->size[0];
    c1_regionLengths->size[0] = c1_CC.RegionLengths->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_regionLengths, c1_i6,
      &c1_se_emlrtRTEI);
    c1_b_loop_ub = c1_CC.RegionLengths->size[0] - 1;
    for (c1_i7 = 0; c1_i7 <= c1_b_loop_ub; c1_i7++) {
      c1_regionLengths->data[c1_i7] = c1_CC.RegionLengths->data[c1_i7];
    }

    c1_b_st.site = &c1_bi_emlrtRSI;
    c1_c_st.site = &c1_qh_emlrtRSI;
    c1_dim = 2;
    if ((real_T)c1_regionLengths->size[0] != 1.0) {
      c1_dim = 1;
    }

    c1_emxInit_int32_T(chartInstance, &c1_c_st, &c1_b_regionLengths, 1,
                       &c1_te_emlrtRTEI);
    c1_i12 = c1_b_regionLengths->size[0];
    c1_b_regionLengths->size[0] = c1_regionLengths->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_regionLengths,
      c1_i12, &c1_te_emlrtRTEI);
    c1_c_loop_ub = c1_regionLengths->size[0] - 1;
    for (c1_i16 = 0; c1_i16 <= c1_c_loop_ub; c1_i16++) {
      c1_b_regionLengths->data[c1_i16] = c1_regionLengths->data[c1_i16];
    }

    c1_emxInit_int32_T(chartInstance, &c1_c_st, &c1_idxCount, 1,
                       &c1_bf_emlrtRTEI);
    c1_d_st.site = &c1_rh_emlrtRSI;
    c1_useConstantDim(chartInstance, &c1_d_st, c1_b_regionLengths, c1_dim,
                      c1_regionLengths);
    c1_i20 = c1_idxCount->size[0];
    c1_idxCount->size[0] = 1 + c1_regionLengths->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_idxCount, c1_i20,
      &c1_ue_emlrtRTEI);
    c1_idxCount->data[0] = 0;
    c1_d_loop_ub = c1_regionLengths->size[0] - 1;
    c1_emxFree_int32_T(chartInstance, &c1_b_regionLengths);
    for (c1_i21 = 0; c1_i21 <= c1_d_loop_ub; c1_i21++) {
      c1_idxCount->data[c1_i21 + 1] = c1_regionLengths->data[c1_i21];
    }

    c1_emxFree_int32_T(chartInstance, &c1_regionLengths);
    c1_d1 = (real_T)c1_stats->size[0];
    c1_i22 = (int32_T)c1_d1 - 1;
    for (c1_e_k = 0; c1_e_k <= c1_i22; c1_e_k++) {
      c1_f_k = (real_T)c1_e_k + 1.0;
      c1_i23 = c1_idxCount->size[0];
      c1_i24 = (int32_T)c1_f_k;
      c1_i25 = c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_i24, 1, c1_i23,
        &c1_wc_emlrtBCI, &c1_st) - 1] + 1;
      c1_i26 = c1_idxCount->size[0];
      c1_i27 = (int32_T)(c1_f_k + 1.0);
      c1_i28 = c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_i27, 1, c1_i26,
        &c1_xc_emlrtBCI, &c1_st) - 1];
      c1_b = (c1_i25 > c1_i28);
      if (c1_b) {
        c1_i30 = 0;
        c1_i31 = -1;
      } else {
        c1_i29 = c1_regionIndices->size[0];
        c1_i30 = emlrtDynamicBoundsCheckR2012b(c1_i25, 1, c1_i29,
          &c1_wc_emlrtBCI, &c1_st) - 1;
        c1_i32 = c1_regionIndices->size[0];
        c1_i31 = emlrtDynamicBoundsCheckR2012b(c1_i28, 1, c1_i32,
          &c1_xc_emlrtBCI, &c1_st) - 1;
      }

      c1_b_stats = c1_stats->size[0];
      c1_i33 = (int32_T)c1_f_k;
      c1_i34 = emlrtDynamicBoundsCheckR2012b(c1_i33, 1, c1_b_stats,
        &c1_dd_emlrtBCI, &c1_st) - 1;
      c1_i35 = c1_stats->data[c1_i34].PixelIdxList->size[0];
      c1_stats->data[c1_i34].PixelIdxList->size[0] = (c1_i31 - c1_i30) + 1;
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_stats->data[c1_i34].
        PixelIdxList, c1_i35, &c1_ve_emlrtRTEI);
      c1_e_loop_ub = c1_i31 - c1_i30;
      for (c1_i36 = 0; c1_i36 <= c1_e_loop_ub; c1_i36++) {
        c1_i37 = (int32_T)c1_f_k;
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i37, 1, c1_b_stats,
          &c1_dd_emlrtBCI, &c1_st) - 1].PixelIdxList->data[c1_i36] =
          c1_regionIndices->data[c1_i30 + c1_i36];
      }
    }

    c1_emxFree_int32_T(chartInstance, &c1_idxCount);
    c1_emxFree_real_T(chartInstance, &c1_regionIndices);
  }

  c1_emxFreeStruct_s_VSLwMee4Kv1oTF0(chartInstance, &c1_CC);
  c1_st.site = &c1_xg_emlrtRSI;
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    chartInstance->c1_varargin_2[c1_i3] = c1_b_varargin_2[c1_i3];
  }

  c1_b_ComputeWeightedCentroid(chartInstance, &c1_st,
    chartInstance->c1_varargin_2, c1_stats, &c1_statsAlreadyComputed);
  c1_st.site = &c1_yg_emlrtRSI;
  c1_d = (real_T)c1_stats->size[0];
  c1_i5 = (int32_T)c1_d - 1;
  for (c1_c_k = 0; c1_c_k <= c1_i5; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_i8 = c1_stats->size[0];
    c1_i9 = (int32_T)c1_d_k;
    emlrtDynamicBoundsCheckR2012b(c1_i9, 1, c1_i8, &c1_yc_emlrtBCI, &c1_st);
    c1_i10 = c1_outstats->size[0];
    c1_i11 = (int32_T)c1_d_k;
    emlrtDynamicBoundsCheckR2012b(c1_i11, 1, c1_i10, &c1_ad_emlrtBCI, &c1_st);
    for (c1_vIdx = 0; c1_vIdx < 2; c1_vIdx++) {
      c1_b_vIdx = (real_T)c1_vIdx + 1.0;
      c1_i13 = c1_stats->size[0];
      c1_i14 = (int32_T)c1_d_k;
      c1_i15 = emlrtDynamicBoundsCheckR2012b(c1_i14, 1, c1_i13, &c1_cd_emlrtBCI,
        &c1_st) - 1;
      c1_i17 = c1_outstats->size[0];
      c1_i18 = (int32_T)c1_d_k;
      c1_i19 = emlrtDynamicBoundsCheckR2012b(c1_i18, 1, c1_i17, &c1_bd_emlrtBCI,
        &c1_st) - 1;
      c1_outstats->data[c1_i19].WeightedCentroid[(int32_T)c1_b_vIdx - 1] =
        c1_stats->data[c1_i15].WeightedCentroid[(int32_T)c1_b_vIdx - 1];
    }
  }

  c1_emxFree_s_nrlUwWofUDGxo1t78e6dw(chartInstance, &c1_stats);
}

static void c1_bwconncomp(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200],
  c1_s_VSLwMee4Kv1oTF0BcoITHB *c1_CC)
{
  c1_emxArray_int32_T *c1_c_x;
  c1_emxArray_int32_T *c1_d_x;
  c1_emxArray_int32_T *c1_endRow;
  c1_emxArray_int32_T *c1_idxCount;
  c1_emxArray_int32_T *c1_labelsRenumbered;
  c1_emxArray_int32_T *c1_regionLengths;
  c1_emxArray_int32_T *c1_startCol;
  c1_emxArray_int32_T *c1_startRow;
  c1_emxArray_real_T *c1_pixelIdxList;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_st;
  real_T c1_b_col;
  real_T c1_b_k;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d_col;
  real_T c1_numComponents;
  real_T c1_y;
  int32_T c1_iv[1];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_c;
  int32_T c1_b_idx;
  int32_T c1_b_loop_ub;
  int32_T c1_b_node;
  int32_T c1_b_p;
  int32_T c1_b_root_k;
  int32_T c1_b_root_p;
  int32_T c1_b_vlen;
  int32_T c1_c;
  int32_T c1_c_b;
  int32_T c1_c_col;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_p;
  int32_T c1_col;
  int32_T c1_column_offset;
  int32_T c1_currentColumn;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_dim;
  int32_T c1_e_b;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_exitg1;
  int32_T c1_f_b;
  int32_T c1_f_k;
  int32_T c1_f_loop_ub;
  int32_T c1_firstRunOnPreviousColumn;
  int32_T c1_firstRunOnThisColumn;
  int32_T c1_g_a;
  int32_T c1_g_b;
  int32_T c1_g_k;
  int32_T c1_g_loop_ub;
  int32_T c1_h_a;
  int32_T c1_h_b;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_a;
  int32_T c1_i_b;
  int32_T c1_i_k;
  int32_T c1_ix;
  int32_T c1_j_a;
  int32_T c1_j_b;
  int32_T c1_j_k;
  int32_T c1_k;
  int32_T c1_k_a;
  int32_T c1_lastRunOnPreviousColumn;
  int32_T c1_loop_ub;
  int32_T c1_nextLabel;
  int32_T c1_node;
  int32_T c1_numRuns;
  int32_T c1_p;
  int32_T c1_root_k;
  int32_T c1_root_p;
  int32_T c1_row;
  int32_T c1_rowidx;
  int32_T c1_runCounter;
  int32_T c1_vlen;
  int32_T c1_xoffset;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_d_overflow;
  boolean_T c1_e_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_gh_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_numRuns = 0;
  for (c1_col = 0; c1_col < 160; c1_col++) {
    c1_b_col = (real_T)c1_col + 1.0;
    if (c1_d_varargin_1[120 * ((int32_T)c1_b_col - 1)]) {
      c1_numRuns++;
    }

    for (c1_k = 0; c1_k < 119; c1_k++) {
      c1_b_k = (real_T)c1_k + 2.0;
      if (c1_d_varargin_1[((int32_T)c1_b_k + 120 * ((int32_T)c1_b_col - 1)) - 1]
          && (!c1_d_varargin_1[((int32_T)(c1_b_k - 1.0) + 120 * ((int32_T)
             c1_b_col - 1)) - 1])) {
        c1_numRuns++;
      }
    }
  }

  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_regionLengths, 1,
                     &c1_pf_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_startRow, 1, &c1_rf_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_endRow, 1, &c1_sf_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_startCol, 1, &c1_tf_emlrtRTEI);
  if (c1_numRuns == 0) {
    c1_startRow->size[0] = 0;
    c1_endRow->size[0] = 0;
    c1_startCol->size[0] = 0;
    c1_regionLengths->size[0] = 0;
    c1_numRuns = 0;
  } else {
    c1_i = c1_startRow->size[0];
    c1_d = (real_T)c1_numRuns;
    c1_startRow->size[0] = (int32_T)emlrtNonNegativeCheckR2012b(c1_d,
      &c1_h_emlrtDCI, &c1_st);
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_startRow, c1_i,
      &c1_cf_emlrtRTEI);
    c1_i1 = c1_endRow->size[0];
    c1_endRow->size[0] = c1_numRuns;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_endRow, c1_i1,
      &c1_df_emlrtRTEI);
    c1_i2 = c1_startCol->size[0];
    c1_startCol->size[0] = c1_numRuns;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_startCol, c1_i2,
      &c1_ef_emlrtRTEI);
    c1_b_st.site = &c1_hh_emlrtRSI;
    c1_runCounter = 1;
    for (c1_c_col = 0; c1_c_col < 160; c1_c_col++) {
      c1_d_col = (real_T)c1_c_col + 1.0;
      c1_row = 1;
      while (c1_row <= 120) {
        while ((c1_row <= 120) && (!c1_d_varargin_1[(c1_row + 120 * ((int32_T)
                  c1_d_col - 1)) - 1])) {
          c1_row++;
        }

        if ((c1_row <= 120) && c1_d_varargin_1[(c1_row + 120 * ((int32_T)
              c1_d_col - 1)) - 1]) {
          c1_i8 = c1_startCol->size[0];
          c1_startCol->data[emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1,
            c1_i8, &c1_ed_emlrtBCI, &c1_b_st) - 1] = (int32_T)c1_d_col;
          c1_i9 = c1_startRow->size[0];
          c1_startRow->data[emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1,
            c1_i9, &c1_gd_emlrtBCI, &c1_b_st) - 1] = c1_row;
          while ((c1_row <= 120) && c1_d_varargin_1[(c1_row + 120 * ((int32_T)
                   c1_d_col - 1)) - 1]) {
            c1_row++;
          }

          c1_i12 = c1_endRow->size[0];
          c1_endRow->data[emlrtDynamicBoundsCheckR2012b(c1_runCounter, 1, c1_i12,
            &c1_jd_emlrtBCI, &c1_b_st) - 1] = c1_row - 1;
          c1_runCounter++;
        }
      }
    }

    c1_i6 = c1_regionLengths->size[0];
    c1_regionLengths->size[0] = c1_numRuns;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_regionLengths, c1_i6,
      &c1_ff_emlrtRTEI);
    c1_loop_ub = c1_numRuns - 1;
    for (c1_i7 = 0; c1_i7 <= c1_loop_ub; c1_i7++) {
      c1_regionLengths->data[c1_i7] = 0;
    }

    c1_c_k = 1;
    c1_currentColumn = 2;
    c1_nextLabel = 1;
    c1_firstRunOnPreviousColumn = -1;
    c1_lastRunOnPreviousColumn = 0;
    c1_firstRunOnThisColumn = 1;
    while (c1_c_k <= c1_numRuns) {
      c1_i13 = c1_startCol->size[0];
      if (c1_startCol->data[emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i13,
           &c1_fd_emlrtBCI, &c1_st) - 1] == c1_currentColumn) {
        c1_firstRunOnPreviousColumn = c1_firstRunOnThisColumn;
        c1_firstRunOnThisColumn = c1_c_k;
        c1_lastRunOnPreviousColumn = c1_c_k;
        c1_i21 = c1_startCol->size[0];
        c1_currentColumn = c1_startCol->data[emlrtDynamicBoundsCheckR2012b
          (c1_c_k, 1, c1_i21, &c1_id_emlrtBCI, &c1_st) - 1] + 1;
      } else {
        c1_i18 = c1_startCol->size[0];
        if (c1_startCol->data[emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i18,
             &c1_hd_emlrtBCI, &c1_st) - 1] > c1_currentColumn) {
          c1_firstRunOnPreviousColumn = -1;
          c1_lastRunOnPreviousColumn = 0;
          c1_firstRunOnThisColumn = c1_c_k;
          c1_i22 = c1_startCol->size[0];
          c1_currentColumn = c1_startCol->data[emlrtDynamicBoundsCheckR2012b
            (c1_c_k, 1, c1_i22, &c1_ld_emlrtBCI, &c1_st) - 1] + 1;
        }
      }

      if (c1_firstRunOnPreviousColumn >= 0) {
        for (c1_p = c1_firstRunOnPreviousColumn; c1_p <
             c1_lastRunOnPreviousColumn; c1_p++) {
          c1_i25 = c1_endRow->size[0];
          c1_i26 = c1_startRow->size[0];
          if (c1_endRow->data[emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i25,
               &c1_rd_emlrtBCI, &c1_st) - 1] >= c1_startRow->
              data[emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i26,
               &c1_sd_emlrtBCI, &c1_st) - 1] - 1) {
            c1_i27 = c1_startRow->size[0];
            c1_i28 = c1_endRow->size[0];
            if (c1_startRow->data[emlrtDynamicBoundsCheckR2012b(c1_c_k, 1,
                 c1_i27, &c1_td_emlrtBCI, &c1_st) - 1] <= c1_endRow->
                data[emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i28,
                 &c1_ud_emlrtBCI, &c1_st) - 1] + 1) {
              c1_i30 = c1_regionLengths->size[0];
              if (c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_c_k, 1,
                   c1_i30, &c1_vd_emlrtBCI, &c1_st) - 1] == 0) {
                c1_i33 = c1_regionLengths->size[0];
                c1_i36 = c1_regionLengths->size[0];
                c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_c_k, 1,
                  c1_i36, &c1_ae_emlrtBCI, &c1_st) - 1] = c1_regionLengths->
                  data[emlrtDynamicBoundsCheckR2012b(c1_p, 1, c1_i33,
                  &c1_yd_emlrtBCI, &c1_st) - 1];
                c1_nextLabel++;
              } else {
                c1_i32 = c1_regionLengths->size[0];
                c1_i35 = c1_regionLengths->size[0];
                if (c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_c_k,
                     1, c1_i32, &c1_wd_emlrtBCI, &c1_st) - 1] !=
                    c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_p, 1,
                     c1_i35, &c1_xd_emlrtBCI, &c1_st) - 1]) {
                  c1_b_st.site = &c1_ih_emlrtRSI;
                  c1_g_k = c1_c_k;
                  c1_b_p = c1_p;
                  c1_c_st.site = &c1_jh_emlrtRSI;
                  c1_node = c1_g_k;
                  c1_root_k = c1_node;
                  do {
                    c1_exitg1 = 0;
                    c1_i40 = c1_regionLengths->size[0];
                    if (c1_root_k != c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i40,
                         &c1_ce_emlrtBCI, &c1_c_st) - 1]) {
                      c1_i42 = c1_regionLengths->size[0];
                      c1_i43 = c1_regionLengths->size[0];
                      c1_i44 = c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i43,
                        &c1_he_emlrtBCI, &c1_c_st) - 1];
                      c1_i45 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_root_k, 1, c1_i45, &c1_ie_emlrtBCI, &c1_c_st) - 1] =
                        c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_i44, 1, c1_i42, &c1_he_emlrtBCI, &c1_c_st) - 1];
                      c1_i47 = c1_regionLengths->size[0];
                      c1_root_k = c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_k, 1, c1_i47,
                        &c1_je_emlrtBCI, &c1_c_st) - 1];
                    } else {
                      c1_exitg1 = 1;
                    }
                  } while (c1_exitg1 == 0);

                  c1_c_st.site = &c1_kh_emlrtRSI;
                  c1_b_node = c1_b_p;
                  c1_root_p = c1_b_node;
                  do {
                    c1_exitg1 = 0;
                    c1_i48 = c1_regionLengths->size[0];
                    if (c1_root_p != c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i48,
                         &c1_ce_emlrtBCI, &c1_c_st) - 1]) {
                      c1_i49 = c1_regionLengths->size[0];
                      c1_i50 = c1_regionLengths->size[0];
                      c1_i52 = c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i50,
                        &c1_he_emlrtBCI, &c1_c_st) - 1];
                      c1_i53 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_root_p, 1, c1_i53, &c1_ie_emlrtBCI, &c1_c_st) - 1] =
                        c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_i52, 1, c1_i49, &c1_he_emlrtBCI, &c1_c_st) - 1];
                      c1_i54 = c1_regionLengths->size[0];
                      c1_root_p = c1_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c1_root_p, 1, c1_i54,
                        &c1_je_emlrtBCI, &c1_c_st) - 1];
                    } else {
                      c1_exitg1 = 1;
                    }
                  } while (c1_exitg1 == 0);

                  if (c1_root_k != c1_root_p) {
                    c1_c_st.site = &c1_lh_emlrtRSI;
                    c1_b_root_k = c1_root_k;
                    c1_b_root_p = c1_root_p;
                    c1_i_k = c1_g_k;
                    c1_c_p = c1_b_p;
                    if (c1_b_root_p < c1_b_root_k) {
                      c1_i57 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_b_root_k, 1, c1_i57, &c1_le_emlrtBCI, &c1_c_st) - 1]
                        = c1_b_root_p;
                      c1_i60 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_i_k, 1, c1_i60, &c1_ne_emlrtBCI, &c1_c_st) - 1] =
                        c1_b_root_p;
                    } else {
                      c1_i56 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_b_root_p, 1, c1_i56, &c1_ke_emlrtBCI, &c1_c_st) - 1]
                        = c1_b_root_k;
                      c1_i59 = c1_regionLengths->size[0];
                      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c1_c_p, 1, c1_i59, &c1_me_emlrtBCI, &c1_c_st) - 1] =
                        c1_b_root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      c1_i23 = c1_regionLengths->size[0];
      if (c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i23,
           &c1_md_emlrtBCI, &c1_st) - 1] == 0) {
        c1_i24 = c1_regionLengths->size[0];
        c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_c_k, 1, c1_i24,
          &c1_qd_emlrtBCI, &c1_st) - 1] = c1_nextLabel;
        c1_nextLabel++;
      }

      c1_c_k++;
    }
  }

  if (c1_numRuns == 0) {
    c1_CC->Connectivity = 8.0;
    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      c1_CC->ImageSize[c1_i4] = 120.0 + 40.0 * (real_T)c1_i4;
    }

    c1_CC->NumObjects = 0.0;
    c1_CC->RegionIndices->size[0] = 0;
    c1_i5 = c1_CC->RegionLengths->size[0];
    c1_CC->RegionLengths->size[0] = 1;
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_CC->RegionLengths,
      c1_i5, &c1_hf_emlrtRTEI);
    c1_CC->RegionLengths->data[0] = 0;
  } else {
    c1_emxInit_int32_T(chartInstance, c1_sp, &c1_labelsRenumbered, 1,
                       &c1_qf_emlrtRTEI);
    c1_i3 = c1_labelsRenumbered->size[0];
    c1_labelsRenumbered->size[0] = c1_regionLengths->size[0];
    c1_st.site = &c1_wl_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_labelsRenumbered,
      c1_i3, &c1_gf_emlrtRTEI);
    c1_numComponents = 0.0;
    c1_st.site = &c1_fh_emlrtRSI;
    c1_b = c1_numRuns;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_d_k = 1; c1_d_k - 1 < c1_numRuns; c1_d_k++) {
      c1_e_k = c1_d_k;
      c1_i11 = c1_regionLengths->size[0];
      if (c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i11,
           &c1_kd_emlrtBCI, c1_sp) - 1] == c1_e_k) {
        c1_numComponents++;
        c1_i15 = c1_labelsRenumbered->size[0];
        c1_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
          c1_i15, &c1_pd_emlrtBCI, c1_sp) - 1] = (int32_T)c1_numComponents;
      }

      c1_i14 = c1_labelsRenumbered->size[0];
      c1_i17 = c1_regionLengths->size[0];
      c1_i19 = c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
        c1_i17, &c1_nd_emlrtBCI, c1_sp) - 1];
      c1_i20 = c1_labelsRenumbered->size[0];
      c1_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i20,
        &c1_od_emlrtBCI, c1_sp) - 1] = c1_labelsRenumbered->
        data[emlrtDynamicBoundsCheckR2012b(c1_i19, 1, c1_i14, &c1_nd_emlrtBCI,
        c1_sp) - 1];
    }

    c1_i10 = c1_regionLengths->size[0];
    c1_regionLengths->size[0] = (int32_T)emlrtIntegerCheckR2012b
      (c1_numComponents, &c1_i_emlrtDCI, c1_sp);
    c1_st.site = &c1_vl_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_regionLengths, c1_i10,
      &c1_if_emlrtRTEI);
    c1_b_loop_ub = (int32_T)emlrtIntegerCheckR2012b(c1_numComponents,
      &c1_i_emlrtDCI, c1_sp) - 1;
    for (c1_i16 = 0; c1_i16 <= c1_b_loop_ub; c1_i16++) {
      c1_regionLengths->data[c1_i16] = 0;
    }

    c1_st.site = &c1_eh_emlrtRSI;
    c1_c_b = c1_numRuns;
    c1_d_b = c1_c_b;
    if (1 > c1_d_b) {
      c1_b_overflow = false;
    } else {
      c1_b_overflow = (c1_d_b > 2147483646);
    }

    if (c1_b_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_f_k = 1; c1_f_k - 1 < c1_numRuns; c1_f_k++) {
      c1_e_k = c1_f_k;
      c1_i29 = c1_labelsRenumbered->size[0];
      c1_b_idx = c1_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c1_e_k,
        1, c1_i29, &c1_be_emlrtBCI, c1_sp) - 1];
      c1_i31 = c1_regionLengths->size[0];
      c1_i34 = c1_endRow->size[0];
      c1_i37 = c1_startRow->size[0];
      c1_i38 = c1_regionLengths->size[0];
      c1_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c1_b_idx, 1, c1_i38,
        &c1_ge_emlrtBCI, c1_sp) - 1] = ((c1_regionLengths->
        data[emlrtDynamicBoundsCheckR2012b(c1_b_idx, 1, c1_i31, &c1_de_emlrtBCI,
        c1_sp) - 1] + c1_endRow->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1,
        c1_i34, &c1_ee_emlrtBCI, c1_sp) - 1]) - c1_startRow->
        data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i37, &c1_fe_emlrtBCI,
        c1_sp) - 1]) + 1;
    }

    c1_st.site = &c1_dh_emlrtRSI;
    c1_b_st.site = &c1_mh_emlrtRSI;
    c1_c_st.site = &c1_nh_emlrtRSI;
    c1_vlen = c1_regionLengths->size[0];
    if ((c1_regionLengths->size[0] == 0) || (c1_vlen == 0)) {
      c1_y = 0.0;
    } else {
      c1_d_st.site = &c1_oh_emlrtRSI;
      c1_b_vlen = c1_vlen;
      c1_y = (real_T)c1_regionLengths->data[0];
      c1_e_st.site = &c1_ph_emlrtRSI;
      c1_e_b = c1_b_vlen;
      c1_f_b = c1_e_b;
      if (2 > c1_f_b) {
        c1_c_overflow = false;
      } else {
        c1_c_overflow = (c1_f_b > 2147483646);
      }

      if (c1_c_overflow) {
        c1_f_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
      }

      for (c1_h_k = 1; c1_h_k < c1_b_vlen; c1_h_k++) {
        c1_xoffset = c1_h_k + 1;
        c1_ix = c1_xoffset - 1;
        c1_y += (real_T)c1_regionLengths->data[c1_ix];
      }
    }

    c1_emxInit_real_T1(chartInstance, &c1_c_st, &c1_pixelIdxList, 1,
                       &c1_of_emlrtRTEI);
    c1_emxInit_int32_T(chartInstance, &c1_c_st, &c1_c_x, 1, &c1_kf_emlrtRTEI);
    c1_d1 = emlrtNonNegativeCheckR2012b(c1_y, &c1_k_emlrtDCI, c1_sp);
    c1_iv[0] = (int32_T)emlrtIntegerCheckR2012b(c1_d1, &c1_j_emlrtDCI, c1_sp);
    c1_i39 = c1_pixelIdxList->size[0];
    c1_pixelIdxList->size[0] = c1_iv[0];
    c1_st.site = &c1_dh_emlrtRSI;
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_pixelIdxList, c1_i39,
      &c1_jf_emlrtRTEI);
    c1_st.site = &c1_ch_emlrtRSI;
    c1_i41 = c1_c_x->size[0];
    c1_c_x->size[0] = c1_regionLengths->size[0];
    c1_b_st.site = &c1_ch_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_c_x, c1_i41,
      &c1_kf_emlrtRTEI);
    c1_c_loop_ub = c1_regionLengths->size[0] - 1;
    for (c1_i46 = 0; c1_i46 <= c1_c_loop_ub; c1_i46++) {
      c1_c_x->data[c1_i46] = c1_regionLengths->data[c1_i46];
    }

    c1_b_st.site = &c1_qh_emlrtRSI;
    c1_dim = 2;
    if ((real_T)c1_c_x->size[0] != 1.0) {
      c1_dim = 1;
    }

    c1_emxInit_int32_T(chartInstance, &c1_b_st, &c1_d_x, 1, &c1_te_emlrtRTEI);
    c1_i51 = c1_d_x->size[0];
    c1_d_x->size[0] = c1_c_x->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_b_st, c1_d_x, c1_i51,
      &c1_te_emlrtRTEI);
    c1_d_loop_ub = c1_c_x->size[0] - 1;
    for (c1_i55 = 0; c1_i55 <= c1_d_loop_ub; c1_i55++) {
      c1_d_x->data[c1_i55] = c1_c_x->data[c1_i55];
    }

    c1_emxInit_int32_T(chartInstance, &c1_b_st, &c1_idxCount, 1,
                       &c1_lf_emlrtRTEI);
    c1_c_st.site = &c1_rh_emlrtRSI;
    c1_useConstantDim(chartInstance, &c1_c_st, c1_d_x, c1_dim, c1_c_x);
    c1_i58 = c1_idxCount->size[0];
    c1_idxCount->size[0] = 1 + c1_c_x->size[0];
    c1_st.site = &c1_ch_emlrtRSI;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_idxCount, c1_i58,
      &c1_lf_emlrtRTEI);
    c1_idxCount->data[0] = 0;
    c1_e_loop_ub = c1_c_x->size[0] - 1;
    c1_emxFree_int32_T(chartInstance, &c1_d_x);
    for (c1_i61 = 0; c1_i61 <= c1_e_loop_ub; c1_i61++) {
      c1_idxCount->data[c1_i61 + 1] = c1_c_x->data[c1_i61];
    }

    c1_emxFree_int32_T(chartInstance, &c1_c_x);
    c1_st.site = &c1_bh_emlrtRSI;
    c1_g_b = c1_numRuns;
    c1_h_b = c1_g_b;
    if (1 > c1_h_b) {
      c1_d_overflow = false;
    } else {
      c1_d_overflow = (c1_h_b > 2147483646);
    }

    if (c1_d_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_j_k = 1; c1_j_k - 1 < c1_numRuns; c1_j_k++) {
      c1_e_k = c1_j_k;
      c1_i62 = c1_startCol->size[0];
      c1_g_a = c1_startCol->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i62,
        &c1_oe_emlrtBCI, c1_sp) - 1] - 1;
      c1_c = c1_g_a;
      c1_h_a = c1_c;
      c1_column_offset = c1_h_a * 120;
      c1_i65 = c1_labelsRenumbered->size[0];
      c1_b_idx = c1_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c1_e_k,
        1, c1_i65, &c1_pe_emlrtBCI, c1_sp) - 1];
      c1_i66 = c1_startRow->size[0];
      c1_i67 = c1_startRow->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i66,
        &c1_qe_emlrtBCI, c1_sp) - 1];
      c1_i69 = c1_endRow->size[0];
      c1_i70 = c1_endRow->data[emlrtDynamicBoundsCheckR2012b(c1_e_k, 1, c1_i69,
        &c1_re_emlrtBCI, c1_sp) - 1];
      c1_st.site = &c1_ah_emlrtRSI;
      c1_i_a = c1_i67;
      c1_i_b = c1_i70;
      c1_j_a = c1_i_a;
      c1_j_b = c1_i_b;
      if (c1_j_a > c1_j_b) {
        c1_e_overflow = false;
      } else {
        c1_e_overflow = (c1_j_b > 2147483646);
      }

      if (c1_e_overflow) {
        c1_b_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
      }

      for (c1_rowidx = c1_i67; c1_rowidx <= c1_i70; c1_rowidx++) {
        c1_i73 = c1_idxCount->size[0];
        c1_k_a = c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_b_idx, 1,
          c1_i73, &c1_se_emlrtBCI, c1_sp) - 1] + 1;
        c1_b_c = c1_k_a;
        c1_i74 = c1_idxCount->size[0];
        c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_b_idx, 1, c1_i74,
          &c1_te_emlrtBCI, c1_sp) - 1] = c1_b_c;
        c1_i75 = c1_pixelIdxList->size[0];
        c1_i76 = c1_idxCount->size[0];
        c1_i77 = c1_idxCount->data[emlrtDynamicBoundsCheckR2012b(c1_b_idx, 1,
          c1_i76, &c1_ue_emlrtBCI, c1_sp) - 1];
        c1_pixelIdxList->data[emlrtDynamicBoundsCheckR2012b(c1_i77, 1, c1_i75,
          &c1_ue_emlrtBCI, c1_sp) - 1] = (real_T)(c1_rowidx + c1_column_offset);
      }
    }

    c1_emxFree_int32_T(chartInstance, &c1_idxCount);
    c1_emxFree_int32_T(chartInstance, &c1_labelsRenumbered);
    c1_CC->Connectivity = 8.0;
    for (c1_i63 = 0; c1_i63 < 2; c1_i63++) {
      c1_CC->ImageSize[c1_i63] = 120.0 + 40.0 * (real_T)c1_i63;
    }

    c1_CC->NumObjects = c1_numComponents;
    c1_i64 = c1_CC->RegionIndices->size[0];
    c1_CC->RegionIndices->size[0] = c1_pixelIdxList->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, c1_CC->RegionIndices,
      c1_i64, &c1_mf_emlrtRTEI);
    c1_f_loop_ub = c1_pixelIdxList->size[0] - 1;
    for (c1_i68 = 0; c1_i68 <= c1_f_loop_ub; c1_i68++) {
      c1_CC->RegionIndices->data[c1_i68] = c1_pixelIdxList->data[c1_i68];
    }

    c1_emxFree_real_T(chartInstance, &c1_pixelIdxList);
    c1_i71 = c1_CC->RegionLengths->size[0];
    c1_CC->RegionLengths->size[0] = c1_regionLengths->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_CC->RegionLengths,
      c1_i71, &c1_nf_emlrtRTEI);
    c1_g_loop_ub = c1_regionLengths->size[0] - 1;
    for (c1_i72 = 0; c1_i72 <= c1_g_loop_ub; c1_i72++) {
      c1_CC->RegionLengths->data[c1_i72] = c1_regionLengths->data[c1_i72];
    }
  }

  c1_emxFree_int32_T(chartInstance, &c1_startCol);
  c1_emxFree_int32_T(chartInstance, &c1_endRow);
  c1_emxFree_int32_T(chartInstance, &c1_startRow);
  c1_emxFree_int32_T(chartInstance, &c1_regionLengths);
}

static void c1_useConstantDim(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_varargin_2,
  int32_T c1_varargin_3, c1_emxArray_int32_T *c1_varargout_1)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_nx;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  if (1 == c1_varargin_3) {
    c1_st.site = &c1_sh_emlrtRSI;
    c1_i1 = c1_varargout_1->size[0];
    c1_varargout_1->size[0] = c1_b_varargin_2->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_varargout_1, c1_i1,
      &c1_uf_emlrtRTEI);
    c1_b_loop_ub = c1_b_varargin_2->size[0] - 1;
    for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
      c1_varargout_1->data[c1_i3] = c1_b_varargin_2->data[c1_i3];
    }

    c1_b_st.site = &c1_th_emlrtRSI;
    if (c1_varargout_1->size[0] != 0) {
      c1_c_st.site = &c1_uh_emlrtRSI;
      c1_nx = c1_varargout_1->size[0] - 1;
      if (!((real_T)c1_varargout_1->size[0] == 1.0)) {
        c1_i4 = c1_nx;
        c1_d_st.site = &c1_vh_emlrtRSI;
        c1_b = c1_i4;
        c1_b_b = c1_b;
        if (1 > c1_b_b) {
          c1_overflow = false;
        } else {
          c1_overflow = (c1_b_b > 2147483646);
        }

        if (c1_overflow) {
          c1_e_st.site = &c1_kb_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
        }

        for (c1_k = 1; c1_k - 1 < c1_i4; c1_k++) {
          c1_b_k = c1_k;
          c1_varargout_1->data[c1_b_k] += c1_varargout_1->data[c1_b_k - 1];
        }
      }
    }
  } else {
    c1_i = c1_varargout_1->size[0];
    c1_varargout_1->size[0] = c1_b_varargin_2->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_varargout_1, c1_i,
      &c1_uf_emlrtRTEI);
    c1_loop_ub = c1_b_varargin_2->size[0] - 1;
    for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
      c1_varargout_1->data[c1_i2] = c1_b_varargin_2->data[c1_i2];
    }
  }
}

static void c1_repmat(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real_T c1_d_varargin_1,
                      c1_emxArray_sBO2RC5RVZVTbundPSRqHn *c1_b)
{
  c1_emxArray_boolean_T *c1_tile;
  c1_sBO2RC5RVZVTbundPSRqHnH c1_b_s;
  emlrtStack c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_outsize[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_loop_ub;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_emxInit_boolean_T1(chartInstance, c1_sp, &c1_tile, 1, &c1_vf_emlrtRTEI);
  c1_st.site = &c1_yh_emlrtRSI;
  c1_assertValidSizeArg(chartInstance, &c1_st, c1_d_varargin_1);
  c1_i = c1_tile->size[0];
  c1_tile->size[0] = (int32_T)c1_d_varargin_1;
  c1_st.site = &c1_rl_emlrtRSI;
  c1_emxEnsureCapacity_boolean_T1(chartInstance, &c1_st, c1_tile, c1_i,
    &c1_vf_emlrtRTEI);
  c1_loop_ub = (int32_T)c1_d_varargin_1 - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_tile->data[c1_i1] = false;
  }

  c1_outsize[0] = c1_tile->size[0];
  if (!((real_T)c1_outsize[0] == (real_T)c1_tile->size[0])) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv5, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c1_sp, &c1_o_emlrtMCI, "error", 0U, 1U, 14, c1_y);
  }

  c1_emxFree_boolean_T(chartInstance, &c1_tile);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_b_s.WeightedCentroid[c1_i2] = 0.0;
  }

  c1_i3 = c1_b->size[0];
  c1_b->size[0] = c1_outsize[0];
  c1_st.site = &c1_im_emlrtRSI;
  c1_emxEnsureCapacity_sBO2RC5RVZVTb(chartInstance, &c1_st, c1_b, c1_i3,
    &c1_wf_emlrtRTEI);
  c1_b_loop_ub = c1_outsize[0] - 1;
  for (c1_i4 = 0; c1_i4 <= c1_b_loop_ub; c1_i4++) {
    c1_b->data[c1_i4] = c1_b_s;
  }
}

static void c1_assertValidSizeArg(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_d_varargin_1)
{
  static char_T c1_b_cv[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n',
    'p', 'u', 't' };

  static char_T c1_b_cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_arg;
  real_T c1_b_arg;
  real_T c1_c_x;
  real_T c1_e_varargin_1;
  real_T c1_n;
  int32_T c1_c_u;
  int32_T c1_d_u;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_p;
  (void)chartInstance;
  c1_arg = c1_d_varargin_1;
  if (c1_arg != c1_arg) {
    c1_p = false;
  } else {
    c1_c_x = c1_arg;
    c1_b = muDoubleScalarIsInf(c1_c_x);
    if (c1_b) {
      c1_p = false;
    } else {
      c1_p = true;
    }
  }

  if (c1_p) {
    c1_b_arg = c1_d_varargin_1;
    if (c1_b_arg > 2.147483647E+9) {
      c1_b_p = false;
    } else {
      c1_b_p = true;
    }

    if (c1_b_p) {
      c1_b_b = true;
    } else {
      c1_b_b = false;
    }
  } else {
    c1_b_b = false;
  }

  if (!c1_b_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c1_c_u = MIN_int32_T;
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
    c1_d_u = MAX_int32_T;
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_call(c1_sp, &c1_p_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 3U, 14, c1_b_y, 14, c1_c_y, 14, c1_f_y)));
  }

  c1_e_varargin_1 = c1_d_varargin_1;
  if (c1_e_varargin_1 <= 0.0) {
    c1_n = 0.0;
  } else {
    c1_n = c1_e_varargin_1;
  }

  if (!(c1_n <= 2.147483647E+9)) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call(c1_sp, &c1_q_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 1U, 14, c1_e_y)));
  }
}

static void c1_initializeStatsStruct(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_numObjs,
  c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_statsAlreadyComputed)
{
  c1_emxArray_boolean_T *c1_tile;
  c1_s_nrlUwWofUDGxo1t78e6dwC c1_statsOneObj;
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_d_varargin_1;
  int32_T c1_outsize[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_loop_ub;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_emxInitStruct_s_nrlUwWofUDGxo1t(chartInstance, c1_sp, &c1_statsOneObj,
    &c1_yf_emlrtRTEI);
  c1_statsAlreadyComputed->Area = false;
  c1_statsOneObj.Area = 0.0;
  c1_statsAlreadyComputed->Centroid = false;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_statsOneObj.Centroid[c1_i] = 0.0;
  }

  c1_statsAlreadyComputed->BoundingBox = false;
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    c1_statsOneObj.BoundingBox[c1_i1] = 0.0;
  }

  c1_statsAlreadyComputed->MajorAxisLength = false;
  c1_statsOneObj.MajorAxisLength = 0.0;
  c1_statsAlreadyComputed->MinorAxisLength = false;
  c1_statsOneObj.MinorAxisLength = 0.0;
  c1_statsAlreadyComputed->Eccentricity = false;
  c1_statsOneObj.Eccentricity = 0.0;
  c1_statsAlreadyComputed->Orientation = false;
  c1_statsOneObj.Orientation = 0.0;
  c1_statsAlreadyComputed->Image = false;
  c1_statsOneObj.Image.size[0] = 0;
  c1_statsOneObj.Image.size[1] = 0;
  c1_statsAlreadyComputed->FilledImage = false;
  c1_statsOneObj.FilledImage.size[0] = 0;
  c1_statsOneObj.FilledImage.size[1] = 0;
  c1_statsAlreadyComputed->FilledArea = false;
  c1_statsOneObj.FilledArea = 0.0;
  c1_statsAlreadyComputed->EulerNumber = false;
  c1_statsOneObj.EulerNumber = 0.0;
  c1_statsAlreadyComputed->Extrema = false;
  for (c1_i2 = 0; c1_i2 < 16; c1_i2++) {
    c1_statsOneObj.Extrema[c1_i2] = 0.0;
  }

  c1_statsAlreadyComputed->EquivDiameter = false;
  c1_statsOneObj.EquivDiameter = 0.0;
  c1_statsAlreadyComputed->Extent = false;
  c1_statsOneObj.Extent = 0.0;
  c1_statsAlreadyComputed->PixelIdxList = false;
  c1_statsOneObj.PixelIdxList->size[0] = 0;
  c1_statsAlreadyComputed->PixelList = false;
  c1_statsOneObj.PixelList->size[0] = 0;
  c1_statsOneObj.PixelList->size[1] = 2;
  c1_statsAlreadyComputed->Perimeter = false;
  c1_statsOneObj.Perimeter = 0.0;
  c1_statsAlreadyComputed->Circularity = false;
  c1_statsOneObj.Circularity = 0.0;
  c1_statsAlreadyComputed->PixelValues = false;
  c1_statsOneObj.PixelValues->size[0] = 0;
  c1_statsAlreadyComputed->WeightedCentroid = false;
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_statsOneObj.WeightedCentroid[c1_i3] = 0.0;
  }

  c1_statsAlreadyComputed->MeanIntensity = false;
  c1_statsOneObj.MeanIntensity = 0.0;
  c1_statsAlreadyComputed->MinIntensity = false;
  c1_statsOneObj.MinIntensity = 0.0;
  c1_statsAlreadyComputed->MaxIntensity = false;
  c1_statsOneObj.MaxIntensity = 0.0;
  c1_statsAlreadyComputed->SubarrayIdx = false;
  c1_statsOneObj.SubarrayIdx.size[0] = 1;
  c1_statsOneObj.SubarrayIdx.size[1] = 0;
  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    c1_statsOneObj.SubarrayIdxLengths[c1_i4] = 0.0;
  }

  c1_emxInit_boolean_T1(chartInstance, c1_sp, &c1_tile, 1, &c1_vf_emlrtRTEI);
  c1_st.site = &c1_ai_emlrtRSI;
  c1_d_varargin_1 = c1_numObjs;
  c1_b_st.site = &c1_yh_emlrtRSI;
  c1_assertValidSizeArg(chartInstance, &c1_b_st, c1_d_varargin_1);
  c1_i5 = c1_tile->size[0];
  c1_tile->size[0] = (int32_T)c1_d_varargin_1;
  c1_emxEnsureCapacity_boolean_T1(chartInstance, &c1_st, c1_tile, c1_i5,
    &c1_vf_emlrtRTEI);
  c1_loop_ub = (int32_T)c1_d_varargin_1 - 1;
  for (c1_i6 = 0; c1_i6 <= c1_loop_ub; c1_i6++) {
    c1_tile->data[c1_i6] = false;
  }

  c1_outsize[0] = c1_tile->size[0];
  if (!((real_T)c1_outsize[0] == (real_T)c1_tile->size[0])) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv5, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c1_st, &c1_o_emlrtMCI, "error", 0U, 1U, 14, c1_y);
  }

  c1_emxFree_boolean_T(chartInstance, &c1_tile);
  c1_i7 = c1_stats->size[0];
  c1_stats->size[0] = c1_outsize[0];
  c1_emxEnsureCapacity_s_nrlUwWofUDG(chartInstance, &c1_st, c1_stats, c1_i7,
    &c1_xf_emlrtRTEI);
  c1_b_loop_ub = c1_outsize[0] - 1;
  for (c1_i8 = 0; c1_i8 <= c1_b_loop_ub; c1_i8++) {
    c1_emxCopyStruct_s_nrlUwWofUDGxo1t(chartInstance, &c1_st, &c1_stats->
      data[c1_i8], &c1_statsOneObj, &c1_xf_emlrtRTEI);
  }

  c1_emxFreeStruct_s_nrlUwWofUDGxo1t(chartInstance, &c1_statsOneObj);
}

static void c1_ComputeWeightedCentroid(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_I[19200],
  c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  c1_statsAlreadyComputed, c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_b_stats,
  c1_sHtk0WM4OMtyqkehwQYcq2 *c1_b_statsAlreadyComputed)
{
  real_T c1_b_I[19200];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_loop_ub;
  c1_i = c1_b_stats->size[0];
  c1_b_stats->size[0] = c1_stats->size[0];
  c1_emxEnsureCapacity_s_nrlUwWofUDG(chartInstance, c1_sp, c1_b_stats, c1_i,
    &c1_ag_emlrtRTEI);
  c1_loop_ub = c1_stats->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_emxCopyStruct_s_nrlUwWofUDGxo1t(chartInstance, c1_sp, &c1_b_stats->
      data[c1_i1], &c1_stats->data[c1_i1], &c1_ag_emlrtRTEI);
  }

  *c1_b_statsAlreadyComputed = c1_statsAlreadyComputed;
  for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
    c1_b_I[c1_i2] = c1_I[c1_i2];
  }

  c1_b_ComputeWeightedCentroid(chartInstance, c1_sp, c1_b_I, c1_b_stats,
    c1_b_statsAlreadyComputed);
}

static real_T c1_b_sum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x)
{
  static char_T c1_b_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  real_T c1_y;
  int32_T c1_b_b;
  int32_T c1_b_vlen;
  int32_T c1_c_b;
  int32_T c1_ix;
  int32_T c1_k;
  int32_T c1_vlen;
  int32_T c1_xoffset;
  boolean_T c1_b;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_st.site = &c1_mh_emlrtRSI;
  if ((c1_c_x->size[0] == 1) || ((real_T)c1_c_x->size[0] != 1.0)) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c1_st, &c1_t_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  c1_b_st.site = &c1_nh_emlrtRSI;
  c1_vlen = c1_c_x->size[0];
  if ((c1_c_x->size[0] == 0) || (c1_vlen == 0)) {
    c1_y = 0.0;
  } else {
    c1_c_st.site = &c1_oh_emlrtRSI;
    c1_b_vlen = c1_vlen;
    c1_y = c1_c_x->data[0];
    c1_d_st.site = &c1_ph_emlrtRSI;
    c1_b_b = c1_b_vlen;
    c1_c_b = c1_b_b;
    if (2 > c1_c_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_e_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
    }

    for (c1_k = 1; c1_k < c1_b_vlen; c1_k++) {
      c1_xoffset = c1_k + 1;
      c1_ix = c1_xoffset - 1;
      c1_y += c1_c_x->data[c1_ix];
    }
  }

  return c1_y;
}

static void c1_round(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x,
                     c1_emxArray_real_T *c1_d_x)
{
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_loop_ub;
  c1_i = c1_d_x->size[0];
  c1_d_x->size[0] = c1_c_x->size[0];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, c1_d_x, c1_i,
    &c1_bg_emlrtRTEI);
  c1_loop_ub = c1_c_x->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_d_x->data[c1_i1] = c1_c_x->data[c1_i1];
  }

  c1_b_round(chartInstance, c1_sp, c1_d_x);
}

static void c1_b_sort(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x,
                      c1_emxArray_real_T *c1_d_x, c1_emxArray_int32_T *c1_b_idx)
{
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_loop_ub;
  c1_i = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = c1_c_x->size[0];
  c1_d_x->size[1] = 1;
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_d_x, c1_i,
    &c1_md_emlrtRTEI);
  c1_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_d_x->data[c1_i1] = c1_c_x->data[c1_i1];
  }

  c1_d_sort(chartInstance, c1_sp, c1_d_x, c1_b_idx);
}

static void c1_b_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real_T *c1_c_x, int32_T c1_offset, c1_emxArray_int32_T *c1_c_idx,
  c1_emxArray_real_T *c1_d_x)
{
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_loop_ub;
  c1_i = c1_c_idx->size[0] * c1_c_idx->size[1];
  c1_c_idx->size[0] = c1_b_idx->size[0];
  c1_c_idx->size[1] = 1;
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_c_idx, c1_i,
    &c1_nd_emlrtRTEI);
  c1_loop_ub = c1_b_idx->size[0] * c1_b_idx->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_c_idx->data[c1_i1] = c1_b_idx->data[c1_i1];
  }

  c1_i2 = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = c1_c_x->size[0];
  c1_d_x->size[1] = 1;
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_d_x, c1_i2,
    &c1_nd_emlrtRTEI);
  c1_b_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_d_x->data[c1_i3] = c1_c_x->data[c1_i3];
  }

  c1_d_merge_pow2_block(chartInstance, c1_sp, c1_c_idx, c1_d_x, c1_offset);
}

static void c1_b_merge_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real_T *c1_c_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_emxArray_int32_T *c1_b_iwork, c1_emxArray_real_T *c1_xwork,
  c1_emxArray_int32_T *c1_c_idx, c1_emxArray_real_T *c1_d_x, c1_emxArray_int32_T
  *c1_c_iwork, c1_emxArray_real_T *c1_b_xwork)
{
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_loop_ub;
  c1_i = c1_c_idx->size[0] * c1_c_idx->size[1];
  c1_c_idx->size[0] = c1_b_idx->size[0];
  c1_c_idx->size[1] = 1;
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_c_idx, c1_i,
    &c1_od_emlrtRTEI);
  c1_loop_ub = c1_b_idx->size[0] * c1_b_idx->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_c_idx->data[c1_i1] = c1_b_idx->data[c1_i1];
  }

  c1_i2 = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = c1_c_x->size[0];
  c1_d_x->size[1] = 1;
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_d_x, c1_i2,
    &c1_od_emlrtRTEI);
  c1_b_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_d_x->data[c1_i3] = c1_c_x->data[c1_i3];
  }

  c1_i4 = c1_c_iwork->size[0];
  c1_c_iwork->size[0] = c1_b_iwork->size[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_c_iwork, c1_i4,
    &c1_od_emlrtRTEI);
  c1_c_loop_ub = c1_b_iwork->size[0] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_c_loop_ub; c1_i5++) {
    c1_c_iwork->data[c1_i5] = c1_b_iwork->data[c1_i5];
  }

  c1_i6 = c1_b_xwork->size[0];
  c1_b_xwork->size[0] = c1_xwork->size[0];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, c1_b_xwork, c1_i6,
    &c1_od_emlrtRTEI);
  c1_d_loop_ub = c1_xwork->size[0] - 1;
  for (c1_i7 = 0; c1_i7 <= c1_d_loop_ub; c1_i7++) {
    c1_b_xwork->data[c1_i7] = c1_xwork->data[c1_i7];
  }

  c1_d_merge_block(chartInstance, c1_sp, c1_c_idx, c1_d_x, c1_offset, c1_n,
                   c1_preSortLevel, c1_c_iwork, c1_b_xwork);
}

static void c1_b_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_real_T
  *c1_c_x, int32_T c1_offset, int32_T c1_np, int32_T c1_nq, c1_emxArray_int32_T *
  c1_b_iwork, c1_emxArray_real_T *c1_xwork, c1_emxArray_int32_T *c1_c_idx,
  c1_emxArray_real_T *c1_d_x, c1_emxArray_int32_T *c1_c_iwork,
  c1_emxArray_real_T *c1_b_xwork)
{
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_loop_ub;
  c1_i = c1_c_idx->size[0] * c1_c_idx->size[1];
  c1_c_idx->size[0] = c1_b_idx->size[0];
  c1_c_idx->size[1] = 1;
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_c_idx, c1_i,
    &c1_pd_emlrtRTEI);
  c1_loop_ub = c1_b_idx->size[0] * c1_b_idx->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_c_idx->data[c1_i1] = c1_b_idx->data[c1_i1];
  }

  c1_i2 = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = c1_c_x->size[0];
  c1_d_x->size[1] = 1;
  c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, c1_d_x, c1_i2,
    &c1_pd_emlrtRTEI);
  c1_b_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_d_x->data[c1_i3] = c1_c_x->data[c1_i3];
  }

  c1_i4 = c1_c_iwork->size[0];
  c1_c_iwork->size[0] = c1_b_iwork->size[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_c_iwork, c1_i4,
    &c1_pd_emlrtRTEI);
  c1_c_loop_ub = c1_b_iwork->size[0] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_c_loop_ub; c1_i5++) {
    c1_c_iwork->data[c1_i5] = c1_b_iwork->data[c1_i5];
  }

  c1_i6 = c1_b_xwork->size[0];
  c1_b_xwork->size[0] = c1_xwork->size[0];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, c1_b_xwork, c1_i6,
    &c1_pd_emlrtRTEI);
  c1_d_loop_ub = c1_xwork->size[0] - 1;
  for (c1_i7 = 0; c1_i7 <= c1_d_loop_ub; c1_i7++) {
    c1_b_xwork->data[c1_i7] = c1_xwork->data[c1_i7];
  }

  c1_d_merge(chartInstance, c1_sp, c1_c_idx, c1_d_x, c1_offset, c1_np, c1_nq,
             c1_c_iwork, c1_b_xwork);
}

static void c1_chradiiphcode(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_d_varargin_1,
  creal_T c1_b_varargin_2[19200], c1_emxArray_real_T *c1_r_estimated)
{
  static char_T c1_b_cv3[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c1_b_cv6[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e',
    'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c1_b_cv8[38] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'f', 'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'o', 'u', 't',
    'O', 'f', 'B', 'o', 'u', 'n', 'd', 'C', 'e', 'n', 't', 'e', 'r', 's' };

  static char_T c1_b_cv[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv2[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c1_b_cv4[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'i', 'n', 'c',
    'o', 'r', 'r', 'e', 'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c1_b_cv1[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c1_b_cv5[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c1_b_cv7[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  c1_emxArray_boolean_T *c1_e_varargin_1;
  c1_emxArray_boolean_T *c1_f_varargin_1;
  c1_emxArray_creal_T *c1_d_varargin_2;
  c1_emxArray_int32_T *c1_r;
  c1_emxArray_real_T *c1_c_varargin_2;
  c1_emxArray_real_T *c1_ndx;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_j_y = NULL;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_l_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_b_k;
  real_T c1_c_u;
  real_T c1_c_x;
  real_T c1_d;
  real_T c1_d_x;
  real_T c1_e_x;
  int32_T c1_b_b;
  int32_T c1_b_loop_ub;
  int32_T c1_c_b;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_e_loop_ub;
  int32_T c1_f_loop_ub;
  int32_T c1_g_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_loop_ub;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_nx;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_st.site = &c1_cj_emlrtRSI;
  c1_b_st.site = &c1_fj_emlrtRSI;
  c1_c_st.site = &c1_hj_emlrtRSI;
  c1_d_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_d = (real_T)(c1_d_varargin_1->size[0] * c1_d_varargin_1->size[1]);
  c1_i = (int32_T)c1_d - 1;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k <= c1_i)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_c_x = c1_d_varargin_1->data[(int32_T)c1_b_k - 1];
    c1_b_p = !(c1_c_x <= 0.0);
    if (c1_b_p) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv6, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call(&c1_d_st, &c1_y_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  c1_d_st.site = &c1_s_emlrtRSI;
  c1_b1 = (c1_d_varargin_1->size[0] == 0);
  c1_b2 = (c1_d_varargin_1->size[1] == 0);
  if (!((!c1_b1) && (!c1_b2))) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv5, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call(&c1_d_st, &c1_ab_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_e_y, 14, c1_g_y)));
  }

  c1_d_st.site = &c1_s_emlrtRSI;
  if (!((real_T)c1_d_varargin_1->size[1] == 2.0)) {
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv4, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_b_cv6, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_b_cv7, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    c1_c_u = 2.0;
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call(&c1_d_st, &c1_bb_emlrtMCI, "error", 0U, 2U, 14, c1_f_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 3U, 14, c1_h_y, 14, c1_i_y, 14, c1_j_y)));
  }

  c1_emxInit_boolean_T1(chartInstance, &c1_d_st, &c1_e_varargin_1, 1,
                        &c1_cg_emlrtRTEI);
  c1_b_st.site = &c1_gj_emlrtRSI;
  c1_i1 = c1_d_varargin_1->size[1];
  c1_i2 = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i2, 1, c1_i1, &c1_xe_emlrtBCI, &c1_b_st);
  c1_i3 = c1_d_varargin_1->size[0] - 1;
  c1_i4 = c1_e_varargin_1->size[0];
  c1_e_varargin_1->size[0] = c1_i3 + 1;
  c1_emxEnsureCapacity_boolean_T1(chartInstance, &c1_b_st, c1_e_varargin_1,
    c1_i4, &c1_cg_emlrtRTEI);
  c1_loop_ub = c1_i3;
  for (c1_i5 = 0; c1_i5 <= c1_loop_ub; c1_i5++) {
    c1_e_varargin_1->data[c1_i5] = (c1_d_varargin_1->data[c1_i5] <= 160.0);
  }

  c1_emxInit_boolean_T1(chartInstance, &c1_b_st, &c1_f_varargin_1, 1,
                        &c1_dg_emlrtRTEI);
  c1_c_st.site = &c1_ij_emlrtRSI;
  if (c1_all(chartInstance, &c1_c_st, c1_e_varargin_1)) {
    c1_i6 = c1_d_varargin_1->size[1];
    c1_i7 = 2;
    emlrtDynamicBoundsCheckR2012b(c1_i7, 1, c1_i6, &c1_ye_emlrtBCI, &c1_b_st);
    c1_i8 = c1_d_varargin_1->size[0] - 1;
    c1_i9 = c1_f_varargin_1->size[0];
    c1_f_varargin_1->size[0] = c1_i8 + 1;
    c1_emxEnsureCapacity_boolean_T1(chartInstance, &c1_b_st, c1_f_varargin_1,
      c1_i9, &c1_dg_emlrtRTEI);
    c1_b_loop_ub = c1_i8;
    for (c1_i12 = 0; c1_i12 <= c1_b_loop_ub; c1_i12++) {
      c1_f_varargin_1->data[c1_i12] = (c1_d_varargin_1->data[c1_i12 +
        c1_d_varargin_1->size[0]] <= 120.0);
    }

    c1_c_st.site = &c1_jj_emlrtRSI;
    if (c1_all(chartInstance, &c1_c_st, c1_f_varargin_1)) {
      c1_b3 = true;
    } else {
      c1_b3 = false;
    }
  } else {
    c1_b3 = false;
  }

  c1_emxFree_boolean_T(chartInstance, &c1_f_varargin_1);
  c1_emxFree_boolean_T(chartInstance, &c1_e_varargin_1);
  if (!c1_b3) {
    c1_k_y = NULL;
    sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_b_cv8, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    c1_l_y = NULL;
    sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_b_cv8, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    sf_mex_call(&c1_b_st, &c1_cb_emlrtMCI, "error", 0U, 2U, 14, c1_k_y, 14,
                sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_b_st, NULL, "message", 1U, 1U, 14, c1_l_y)));
  }

  c1_emxInit_real_T1(chartInstance, &c1_b_st, &c1_ndx, 1, &c1_jg_emlrtRTEI);
  c1_i10 = c1_d_varargin_1->size[1];
  c1_i11 = 2;
  emlrtDynamicBoundsCheckR2012b(c1_i11, 1, c1_i10, &c1_ve_emlrtBCI, c1_sp);
  c1_i13 = c1_d_varargin_1->size[1];
  c1_i14 = 1;
  emlrtDynamicBoundsCheckR2012b(c1_i14, 1, c1_i13, &c1_we_emlrtBCI, c1_sp);
  c1_st.site = &c1_dj_emlrtRSI;
  c1_i15 = c1_d_varargin_1->size[0] - 1;
  c1_i16 = c1_ndx->size[0];
  c1_ndx->size[0] = c1_i15 + 1;
  c1_b_st.site = &c1_dj_emlrtRSI;
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_ndx, c1_i16,
    &c1_eg_emlrtRTEI);
  c1_c_loop_ub = c1_i15;
  for (c1_i17 = 0; c1_i17 <= c1_c_loop_ub; c1_i17++) {
    c1_ndx->data[c1_i17] = c1_d_varargin_1->data[c1_i17 + c1_d_varargin_1->size
      [0]];
  }

  c1_emxInit_real_T1(chartInstance, &c1_st, &c1_c_varargin_2, 1,
                     &c1_fg_emlrtRTEI);
  c1_b_st.site = &c1_dj_emlrtRSI;
  c1_b_round(chartInstance, &c1_b_st, c1_ndx);
  c1_i18 = c1_d_varargin_1->size[0] - 1;
  c1_i19 = c1_c_varargin_2->size[0];
  c1_c_varargin_2->size[0] = c1_i18 + 1;
  c1_b_st.site = &c1_dj_emlrtRSI;
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_c_varargin_2, c1_i19,
    &c1_fg_emlrtRTEI);
  c1_d_loop_ub = c1_i18;
  for (c1_i20 = 0; c1_i20 <= c1_d_loop_ub; c1_i20++) {
    c1_c_varargin_2->data[c1_i20] = c1_d_varargin_1->data[c1_i20];
  }

  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_r, 1, &c1_ec_emlrtRTEI);
  c1_b_st.site = &c1_dj_emlrtRSI;
  c1_b_round(chartInstance, &c1_b_st, c1_c_varargin_2);
  c1_b_st.site = &c1_wf_emlrtRSI;
  c1_eml_sub2ind(chartInstance, &c1_b_st, c1_ndx, c1_c_varargin_2, c1_r);
  c1_i21 = c1_ndx->size[0];
  c1_ndx->size[0] = c1_r->size[0];
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_ndx, c1_i21,
    &c1_cb_emlrtRTEI);
  c1_e_loop_ub = c1_r->size[0] - 1;
  c1_emxFree_real_T(chartInstance, &c1_c_varargin_2);
  for (c1_i22 = 0; c1_i22 <= c1_e_loop_ub; c1_i22++) {
    c1_ndx->data[c1_i22] = (real_T)c1_r->data[c1_i22];
  }

  c1_emxFree_int32_T(chartInstance, &c1_r);
  c1_emxInit_creal_T(chartInstance, &c1_st, &c1_d_varargin_2, 1,
                     &c1_gg_emlrtRTEI);
  c1_i23 = c1_d_varargin_2->size[0];
  c1_d_varargin_2->size[0] = c1_ndx->size[0];
  c1_st.site = &c1_dj_emlrtRSI;
  c1_emxEnsureCapacity_creal_T(chartInstance, &c1_st, c1_d_varargin_2, c1_i23,
    &c1_gg_emlrtRTEI);
  c1_f_loop_ub = c1_ndx->size[0] - 1;
  for (c1_i24 = 0; c1_i24 <= c1_f_loop_ub; c1_i24++) {
    c1_i25 = (int32_T)c1_ndx->data[c1_i24];
    c1_d_varargin_2->data[c1_i24].re =
      c1_b_varargin_2[emlrtDynamicBoundsCheckR2012b(c1_i25, 1, 19200,
      &c1_af_emlrtBCI, c1_sp) - 1].re;
    c1_i26 = (int32_T)c1_ndx->data[c1_i24];
    c1_d_varargin_2->data[c1_i24].im =
      c1_b_varargin_2[emlrtDynamicBoundsCheckR2012b(c1_i26, 1, 19200,
      &c1_af_emlrtBCI, c1_sp) - 1].im;
  }

  c1_emxFree_real_T(chartInstance, &c1_ndx);
  c1_st.site = &c1_dj_emlrtRSI;
  c1_angle(chartInstance, &c1_st, c1_d_varargin_2, c1_r_estimated);
  c1_i27 = c1_r_estimated->size[0];
  c1_st.site = &c1_ej_emlrtRSI;
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_r_estimated, c1_i27,
    &c1_hg_emlrtRTEI);
  c1_g_loop_ub = c1_r_estimated->size[0] - 1;
  c1_emxFree_creal_T(chartInstance, &c1_d_varargin_2);
  for (c1_i28 = 0; c1_i28 <= c1_g_loop_ub; c1_i28++) {
    c1_r_estimated->data[c1_i28] = (c1_r_estimated->data[c1_i28] +
      3.1415926535897931) / 6.2831853071795862;
  }

  c1_i29 = c1_r_estimated->size[0];
  c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, c1_r_estimated, c1_i29,
    &c1_g_emlrtRTEI);
  c1_h_loop_ub = c1_r_estimated->size[0] - 1;
  for (c1_i30 = 0; c1_i30 <= c1_h_loop_ub; c1_i30++) {
    c1_r_estimated->data[c1_i30] *= 0.98082925301172619;
  }

  c1_st.site = &c1_ej_emlrtRSI;
  c1_i31 = c1_r_estimated->size[0];
  c1_b_st.site = &c1_ej_emlrtRSI;
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_r_estimated, c1_i31,
    &c1_ig_emlrtRTEI);
  c1_i_loop_ub = c1_r_estimated->size[0] - 1;
  for (c1_i32 = 0; c1_i32 <= c1_i_loop_ub; c1_i32++) {
    c1_r_estimated->data[c1_i32] += 2.70805020110221;
  }

  c1_b_st.site = &c1_mj_emlrtRSI;
  c1_nx = c1_r_estimated->size[0];
  c1_c_st.site = &c1_ri_emlrtRSI;
  c1_b_b = c1_nx;
  c1_c_b = c1_b_b;
  if (1 > c1_c_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_c_b > 2147483646);
  }

  if (c1_overflow) {
    c1_d_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
  }

  for (c1_c_k = 1; c1_c_k - 1 < c1_nx; c1_c_k++) {
    c1_d_k = c1_c_k - 1;
    c1_d_x = c1_r_estimated->data[c1_d_k];
    c1_e_x = c1_d_x;
    c1_e_x = muDoubleScalarExp(c1_e_x);
    c1_r_estimated->data[c1_d_k] = c1_e_x;
  }
}

static boolean_T c1_all(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_boolean_T *c1_c_x)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  real_T c1_g_a;
  real_T c1_vlen;
  int32_T c1_b_b;
  int32_T c1_c;
  int32_T c1_c_b;
  int32_T c1_d_b;
  int32_T c1_h_a;
  int32_T c1_i2;
  int32_T c1_i_a;
  int32_T c1_ix;
  int32_T c1_vspread;
  boolean_T c1_b;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_y;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_st.site = &c1_kj_emlrtRSI;
  if ((c1_c_x->size[0] == 1) || ((real_T)c1_c_x->size[0] != 1.0)) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c1_st, &c1_i_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  c1_y = true;
  c1_vlen = (real_T)c1_c_x->size[0];
  c1_g_a = c1_vlen;
  c1_c = (int32_T)c1_g_a;
  c1_h_a = c1_c - 1;
  c1_vspread = c1_h_a;
  c1_b_b = c1_vspread;
  c1_i2 = c1_b_b;
  c1_i_a = c1_i2 + 1;
  c1_i2 = c1_i_a;
  c1_b_st.site = &c1_ve_emlrtRSI;
  c1_c_b = c1_i2;
  c1_d_b = c1_c_b;
  if (1 > c1_d_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_d_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  c1_ix = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_ix + 1 <= c1_i2)) {
    if (!c1_c_x->data[c1_ix]) {
      c1_y = false;
      c1_exitg1 = true;
    } else {
      c1_ix++;
    }
  }

  return c1_y;
}

static void c1_angle(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, c1_emxArray_creal_T *c1_c_x,
                     c1_emxArray_real_T *c1_y)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  creal_T c1_d_x;
  real_T c1_b_dv[2];
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_e_x;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_i;
  int32_T c1_k;
  int32_T c1_nx;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_lj_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_nx = c1_c_x->size[0];
  c1_b_dv[0] = (real_T)c1_c_x->size[0];
  c1_i = c1_y->size[0];
  c1_y->size[0] = (int32_T)c1_b_dv[0];
  c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_y, c1_i,
    &c1_ld_emlrtRTEI);
  c1_b_st.site = &c1_te_emlrtRSI;
  c1_b = c1_nx;
  c1_b_b = c1_b;
  if (1 > c1_b_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  for (c1_k = 1; c1_k - 1 < c1_nx; c1_k++) {
    c1_b_k = c1_k - 1;
    c1_d_x = c1_c_x->data[c1_b_k];
    c1_b_y = c1_d_x.im;
    c1_e_x = c1_d_x.re;
    c1_c_y = muDoubleScalarAtan2(c1_b_y, c1_e_x);
    c1_y->data[c1_b_k] = c1_c_y;
  }
}

static void c1_hough(SFc1_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200],
                     real_T c1_h[71820])
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_cost[180];
  real_T c1_sint[180];
  real_T c1_tempBin[120];
  real_T c1_b_j;
  real_T c1_b_k;
  real_T c1_c_x;
  real_T c1_d_j;
  real_T c1_d_x;
  real_T c1_e_i;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_myRho;
  real_T c1_tempNum;
  int32_T c1_nonZeroPixelMatrix[19200];
  int32_T c1_rhoIdxVector[399];
  int32_T c1_numNonZeros[160];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_i;
  int32_T c1_b_thetaIdx;
  int32_T c1_c;
  int32_T c1_c_i;
  int32_T c1_c_j;
  int32_T c1_d_i;
  int32_T c1_f_i;
  int32_T c1_g_a;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_n;
  int32_T c1_rhoIdx;
  int32_T c1_thetaIdx;
  int32_T c1_y;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_nj_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  for (c1_i = 0; c1_i < 180; c1_i++) {
    c1_b_i = c1_i;
    c1_c_x = (-90.0 + (real_T)c1_b_i) * 3.1415926535897931 / 180.0;
    c1_d_x = c1_c_x;
    c1_d_x = muDoubleScalarCos(c1_d_x);
    c1_cost[c1_b_i] = c1_d_x;
    c1_e_x = (-90.0 + (real_T)c1_b_i) * 3.1415926535897931 / 180.0;
    c1_f_x = c1_e_x;
    c1_f_x = muDoubleScalarSin(c1_f_x);
    c1_sint[c1_b_i] = c1_f_x;
  }

  c1_b_st.site = &c1_oj_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    c1_tempNum = 0.0;
    for (c1_c_i = 0; c1_c_i < 120; c1_c_i++) {
      c1_e_i = (real_T)c1_c_i + 1.0;
      if (c1_d_varargin_1[((int32_T)c1_e_i + 120 * ((int32_T)c1_b_j - 1)) - 1])
      {
        c1_tempNum++;
        c1_i2 = (int32_T)c1_tempNum;
        c1_tempBin[emlrtDynamicBoundsCheckR2012b(c1_i2, 1, 120, &c1_cf_emlrtBCI,
          &c1_b_st) - 1] = c1_e_i;
      }
    }

    c1_numNonZeros[(int32_T)c1_b_j - 1] = (int32_T)c1_tempNum;
    c1_k = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 120)) {
      c1_b_k = (real_T)c1_k + 1.0;
      if (c1_b_k > c1_tempNum) {
        c1_exitg1 = true;
      } else {
        c1_nonZeroPixelMatrix[((int32_T)c1_b_k + 120 * ((int32_T)c1_b_j - 1)) -
          1] = (int32_T)c1_tempBin[(int32_T)c1_b_k - 1];
        c1_k++;
      }
    }
  }

  for (c1_thetaIdx = 0; c1_thetaIdx < 180; c1_thetaIdx++) {
    c1_b_thetaIdx = c1_thetaIdx;
    for (c1_d_i = 0; c1_d_i < 399; c1_d_i++) {
      c1_rhoIdxVector[c1_d_i] = 0;
    }

    for (c1_c_j = 0; c1_c_j < 160; c1_c_j++) {
      c1_d_j = (real_T)c1_c_j + 1.0;
      c1_i3 = c1_numNonZeros[(int32_T)c1_d_j - 1];
      c1_b_st.site = &c1_pj_emlrtRSI;
      c1_b = c1_i3;
      c1_b_b = c1_b;
      if (1 > c1_b_b) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_b_b > 2147483646);
      }

      if (c1_overflow) {
        c1_c_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_f_i = 1; c1_f_i - 1 < c1_i3; c1_f_i++) {
        c1_b_i = c1_f_i - 1;
        c1_n = c1_nonZeroPixelMatrix[c1_b_i + 120 * ((int32_T)c1_d_j - 1)];
        c1_myRho = (c1_d_j - 1.0) * c1_cost[c1_b_thetaIdx] + ((real_T)c1_n - 1.0)
          * c1_sint[c1_b_thetaIdx];
        c1_g_x = c1_myRho - -199.0;
        c1_y = (int32_T)(c1_g_x + 0.5) + 1;
        c1_rhoIdx = c1_y;
        c1_g_a = c1_rhoIdxVector[emlrtDynamicBoundsCheckR2012b(c1_rhoIdx, 1, 399,
          &c1_df_emlrtBCI, &c1_st) - 1] + 1;
        c1_c = c1_g_a;
        c1_rhoIdxVector[emlrtDynamicBoundsCheckR2012b(c1_rhoIdx, 1, 399,
          &c1_bf_emlrtBCI, &c1_st) - 1] = c1_c;
      }
    }

    for (c1_i1 = 0; c1_i1 < 399; c1_i1++) {
      c1_h[c1_i1 + 399 * c1_b_thetaIdx] = (real_T)c1_rhoIdxVector[c1_i1];
    }
  }
}

static void c1_houghpeaks(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_d_varargin_1[71820], real_T c1_varargin_4,
  c1_emxArray_real_T *c1_peaks)
{
  static char_T c1_b_cv5[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv8[43] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i',
    'd', 'T', 'h', 'e', 't', 'a', 'V', 'e', 'c', 't', 'o', 'r', 'S', 'p', 'a',
    'c', 'i', 'n', 'g' };

  static char_T c1_b_cv4[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'N', 'o', 'n', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv2[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c1_b_cv[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  static char_T c1_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  static char_T c1_b_cv3[9] = { 'T', 'h', 'r', 'e', 's', 'h', 'o', 'l', 'd' };

  static char_T c1_b_cv6[9] = { 'T', 'h', 'r', 'e', 's', 'h', 'o', 'l', 'd' };

  static char_T c1_b_cv7[5] = { 'T', 'h', 'e', 't', 'a' };

  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_j_y = NULL;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_l_y = NULL;
  const mxArray *c1_m_y = NULL;
  const mxArray *c1_n_y = NULL;
  const mxArray *c1_o_y = NULL;
  const mxArray *c1_r_y = NULL;
  const mxArray *c1_s_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_b_dv1[180];
  real_T c1_b_dv2[180];
  real_T c1_dv3[180];
  real_T c1_dv4[180];
  real_T c1_dv5[180];
  real_T c1_thetaInterval[179];
  real_T c1_r_x[178];
  real_T c1_b_dv[2];
  real_T c1_ab_x;
  real_T c1_b_k;
  real_T c1_b_threshold;
  real_T c1_b_varargin_2;
  real_T c1_b_varargin_4;
  real_T c1_bb_x;
  real_T c1_c_threshold;
  real_T c1_c_varargin_2;
  real_T c1_c_x;
  real_T c1_d_k;
  real_T c1_d_varargin_2;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_k;
  real_T c1_f_x;
  real_T c1_g_a;
  real_T c1_g_x;
  real_T c1_h_a;
  real_T c1_h_x;
  real_T c1_i_a;
  real_T c1_i_x;
  real_T c1_j_a;
  real_T c1_j_x;
  real_T c1_k_a;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_maxTheta;
  real_T c1_maxVal;
  real_T c1_minTheta;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_p_y;
  real_T c1_q_x;
  real_T c1_q_y;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_t_y;
  real_T c1_thetaResolution;
  real_T c1_threshold;
  real_T c1_u_x;
  real_T c1_u_y;
  real_T c1_v_x;
  real_T c1_val;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_y_x;
  int32_T c1_b_i;
  int32_T c1_b_j;
  int32_T c1_c_i;
  int32_T c1_c_k;
  int32_T c1_e_k;
  int32_T c1_g_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_iPeak;
  int32_T c1_ix;
  int32_T c1_j;
  int32_T c1_jPeak;
  int32_T c1_k;
  int32_T c1_l_a;
  int32_T c1_l_b;
  int32_T c1_loop_ub;
  int32_T c1_m_a;
  int32_T c1_m_b;
  int32_T c1_n_a;
  int32_T c1_n_b;
  int32_T c1_o_a;
  int32_T c1_o_b;
  int32_T c1_peakIdx;
  int32_T c1_rho;
  int32_T c1_rhoMax;
  int32_T c1_rhoMin;
  int32_T c1_rhoToRemove;
  int32_T c1_theta;
  int32_T c1_thetaMax;
  int32_T c1_thetaMin;
  int32_T c1_thetaToRemove;
  int32_T c1_xoffset;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b10;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b6;
  boolean_T c1_b7;
  boolean_T c1_b8;
  boolean_T c1_b9;
  boolean_T c1_b_b;
  boolean_T c1_b_overflow;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_d_b;
  boolean_T c1_d_p;
  boolean_T c1_e_b;
  boolean_T c1_e_p;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_f_p;
  boolean_T c1_g_b;
  boolean_T c1_g_p;
  boolean_T c1_h_b;
  boolean_T c1_h_p;
  boolean_T c1_i_b;
  boolean_T c1_i_p;
  boolean_T c1_isDone;
  boolean_T c1_isThetaAntisymmetric;
  boolean_T c1_j_b;
  boolean_T c1_k_b;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_st.site = &c1_uj_emlrtRSI;
  c1_b_varargin_4 = c1_varargin_4;
  c1_b_st.site = &c1_vj_emlrtRSI;
  c1_c_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 71820)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_c_x = c1_d_varargin_1[(int32_T)c1_b_k - 1];
    c1_d_x = c1_c_x;
    c1_b_b = muDoubleScalarIsInf(c1_d_x);
    c1_b1 = !c1_b_b;
    c1_e_x = c1_c_x;
    c1_c_b = muDoubleScalarIsNaN(c1_e_x);
    c1_b2 = !c1_c_b;
    c1_d_b = (c1_b1 && c1_b2);
    if (c1_d_b) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv7, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c1_c_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_c_st, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  c1_c_st.site = &c1_s_emlrtRSI;
  c1_b_p = true;
  c1_c_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k < 71820)) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_f_x = c1_d_varargin_1[(int32_T)c1_d_k - 1];
    c1_g_x = c1_f_x;
    c1_h_x = c1_g_x;
    c1_e_b = muDoubleScalarIsInf(c1_h_x);
    c1_b4 = !c1_e_b;
    c1_i_x = c1_g_x;
    c1_f_b = muDoubleScalarIsNaN(c1_i_x);
    c1_b5 = !c1_f_b;
    c1_g_b = (c1_b4 && c1_b5);
    if (c1_g_b) {
      c1_j_x = c1_f_x;
      c1_k_x = c1_j_x;
      c1_k_x = muDoubleScalarFloor(c1_k_x);
      if (c1_k_x == c1_f_x) {
        c1_c_p = true;
      } else {
        c1_c_p = false;
      }
    } else {
      c1_c_p = false;
    }

    c1_d_p = c1_c_p;
    if (c1_d_p) {
      c1_c_k++;
    } else {
      c1_b_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_b_p) {
    c1_b3 = true;
  } else {
    c1_b3 = false;
  }

  if (!c1_b3) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv8, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv9, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c1_c_st, &c1_db_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                sf_mex_call(&c1_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_c_st, NULL, "message", 1U, 2U, 14, c1_e_y, 14, c1_f_y)));
  }

  c1_b_varargin_2 = c1_b_varargin_4;
  c1_c_varargin_2 = c1_b_varargin_2;
  c1_d_varargin_2 = c1_c_varargin_2;
  c1_threshold = c1_d_varargin_2;
  c1_b_threshold = c1_threshold;
  c1_b_st.site = &c1_wj_emlrtRSI;
  c1_c_threshold = c1_threshold;
  c1_c_st.site = &c1_ak_emlrtRSI;
  c1_g_a = c1_c_threshold;
  c1_d_st.site = &c1_s_emlrtRSI;
  c1_h_a = c1_g_a;
  c1_i_a = c1_h_a;
  c1_e_p = true;
  c1_l_x = c1_i_a;
  c1_m_x = c1_l_x;
  c1_h_b = muDoubleScalarIsNaN(c1_m_x);
  c1_f_p = !c1_h_b;
  if (!c1_f_p) {
    c1_e_p = false;
  }

  if (c1_e_p) {
    c1_b6 = true;
  } else {
    c1_b6 = false;
  }

  if (!c1_b6) {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv4, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_d_st, &c1_m_emlrtMCI, "error", 0U, 2U, 14, c1_g_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_h_y, 14, c1_i_y)));
  }

  c1_d_st.site = &c1_s_emlrtRSI;
  c1_j_a = c1_g_a;
  c1_k_a = c1_j_a;
  c1_g_p = true;
  c1_n_x = c1_k_a;
  c1_h_p = !(c1_n_x < 0.0);
  if (!c1_h_p) {
    c1_g_p = false;
  }

  if (c1_g_p) {
    c1_b7 = true;
  } else {
    c1_b7 = false;
  }

  if (!c1_b7) {
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_b_cv4, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c1_k_y = NULL;
    sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_b_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c1_l_y = NULL;
    sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_b_cv6, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_d_st, &c1_b_emlrtMCI, "error", 0U, 2U, 14, c1_j_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_k_y, 14, c1_l_y)));
  }

  c1_b_st.site = &c1_xj_emlrtRSI;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_b_dv[c1_i] = 9.0 + -4.0 * (real_T)c1_i;
  }

  c1_c_st.site = &c1_bk_emlrtRSI;
  c1_b_validateattributes(chartInstance, &c1_c_st, c1_b_dv);
  c1_b_st.site = &c1_yj_emlrtRSI;
  c1_c_st.site = &c1_fk_emlrtRSI;
  c1_d_st.site = &c1_s_emlrtRSI;
  c1_i_p = true;
  c1_e_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_e_k < 180)) {
    c1_f_k = (real_T)c1_e_k + 1.0;
    c1_o_x = -90.0 + (real_T)((int32_T)c1_f_k - 1);
    c1_p_x = c1_o_x;
    c1_i_b = muDoubleScalarIsInf(c1_p_x);
    c1_b9 = !c1_i_b;
    c1_q_x = c1_o_x;
    c1_j_b = muDoubleScalarIsNaN(c1_q_x);
    c1_b10 = !c1_j_b;
    c1_k_b = (c1_b9 && c1_b10);
    if (c1_k_b) {
      c1_e_k++;
    } else {
      c1_i_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_i_p) {
    c1_b8 = true;
  } else {
    c1_b8 = false;
  }

  if (!c1_b8) {
    c1_m_y = NULL;
    sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_cv7, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c1_n_y = NULL;
    sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c1_o_y = NULL;
    sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_b_cv7, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c1_d_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_m_y, 14,
                sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_d_st, NULL, "message", 1U, 2U, 14, c1_n_y, 14, c1_o_y)));
  }

  c1_c_st.site = &c1_ek_emlrtRSI;
  c1_d_st.site = &c1_md_emlrtRSI;
  for (c1_i1 = 0; c1_i1 < 180; c1_i1++) {
    c1_b_dv1[c1_i1] = -90.0 + (real_T)c1_i1;
  }

  c1_e_st.site = &c1_nd_emlrtRSI;
  c1_b_minimum(chartInstance, &c1_e_st, c1_b_dv1);
  c1_c_st.site = &c1_dk_emlrtRSI;
  c1_d_st.site = &c1_fc_emlrtRSI;
  for (c1_i2 = 0; c1_i2 < 180; c1_i2++) {
    c1_b_dv2[c1_i2] = -90.0 + (real_T)c1_i2;
  }

  c1_e_st.site = &c1_gc_emlrtRSI;
  c1_c_maximum(chartInstance, &c1_e_st, c1_b_dv2);
  for (c1_i3 = 0; c1_i3 < 180; c1_i3++) {
    c1_dv3[c1_i3] = -90.0 + (real_T)c1_i3;
  }

  c1_diff(chartInstance, c1_dv3, c1_thetaInterval);
  c1_c_st.site = &c1_ck_emlrtRSI;
  c1_b_diff(chartInstance, c1_thetaInterval, c1_r_x);
  c1_p_y = c1_r_x[0];
  for (c1_g_k = 0; c1_g_k < 177; c1_g_k++) {
    c1_xoffset = c1_g_k;
    c1_ix = c1_xoffset;
    c1_p_y += c1_r_x[c1_ix + 1];
  }

  c1_s_x = c1_p_y;
  c1_t_x = c1_s_x;
  c1_u_x = c1_t_x;
  c1_q_y = muDoubleScalarAbs(c1_u_x);
  if (c1_q_y > 1.4901161193847656E-8) {
    c1_r_y = NULL;
    sf_mex_assign(&c1_r_y, sf_mex_create("y", c1_b_cv8, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c1_s_y = NULL;
    sf_mex_assign(&c1_s_y, sf_mex_create("y", c1_b_cv8, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    sf_mex_call(&c1_b_st, &c1_gb_emlrtMCI, "error", 0U, 2U, 14, c1_r_y, 14,
                sf_mex_call(&c1_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_b_st, NULL, "message", 1U, 1U, 14, c1_s_y)));
  }

  c1_isDone = false;
  for (c1_i4 = 0; c1_i4 < 71820; c1_i4++) {
    chartInstance->c1_hnew[c1_i4] = c1_d_varargin_1[c1_i4];
  }

  c1_peakIdx = 0;
  c1_st.site = &c1_tj_emlrtRSI;
  c1_b_st.site = &c1_md_emlrtRSI;
  for (c1_i5 = 0; c1_i5 < 180; c1_i5++) {
    c1_dv4[c1_i5] = -90.0 + (real_T)c1_i5;
  }

  c1_c_st.site = &c1_nd_emlrtRSI;
  c1_minTheta = c1_b_minimum(chartInstance, &c1_c_st, c1_dv4);
  c1_st.site = &c1_sj_emlrtRSI;
  c1_b_st.site = &c1_fc_emlrtRSI;
  for (c1_i6 = 0; c1_i6 < 180; c1_i6++) {
    c1_dv5[c1_i6] = -90.0 + (real_T)c1_i6;
  }

  c1_c_st.site = &c1_gc_emlrtRSI;
  c1_maxTheta = c1_c_maximum(chartInstance, &c1_c_st, c1_dv5);
  c1_v_x = c1_maxTheta - c1_minTheta;
  c1_w_x = c1_v_x;
  c1_x_x = c1_w_x;
  c1_t_y = muDoubleScalarAbs(c1_x_x);
  c1_thetaResolution = c1_t_y / 179.0;
  c1_y_x = c1_minTheta + c1_thetaResolution * 5.0;
  c1_ab_x = c1_y_x;
  c1_bb_x = c1_ab_x;
  c1_u_y = muDoubleScalarAbs(c1_bb_x);
  c1_isThetaAntisymmetric = (c1_u_y <= c1_maxTheta);
  while (!c1_isDone) {
    c1_iPeak = 0;
    c1_jPeak = 0;
    c1_maxVal = -1.0;
    for (c1_j = 0; c1_j < 180; c1_j++) {
      c1_b_j = c1_j;
      for (c1_b_i = 0; c1_b_i < 399; c1_b_i++) {
        c1_c_i = c1_b_i;
        c1_val = chartInstance->c1_hnew[c1_c_i + 399 * c1_b_j];
        if (c1_val > c1_maxVal) {
          c1_iPeak = c1_c_i + 1;
          c1_jPeak = c1_b_j + 1;
          c1_maxVal = c1_val;
        }
      }
    }

    if (chartInstance->c1_hnew[(emlrtDynamicBoundsCheckR2012b(c1_iPeak, 1, 399,
          &c1_ff_emlrtBCI, c1_sp) + 399 * (emlrtDynamicBoundsCheckR2012b
          (c1_jPeak, 1, 180, &c1_gf_emlrtBCI, c1_sp) - 1)) - 1] >=
        c1_b_threshold) {
      c1_peakIdx++;
      chartInstance->c1_peakCoordinates[emlrtDynamicBoundsCheckR2012b(c1_peakIdx,
        1, 71820, &c1_ef_emlrtBCI, c1_sp) - 1] = (real_T)c1_iPeak;
      chartInstance->c1_peakCoordinates[c1_peakIdx + 71819] = (real_T)c1_jPeak;
      c1_rhoMin = c1_iPeak - 4;
      c1_rhoMax = c1_iPeak + 4;
      c1_thetaMin = c1_jPeak - 2;
      c1_thetaMax = c1_jPeak + 2;
      if (c1_rhoMin < 1) {
        c1_rhoMin = 1;
      }

      if (c1_rhoMax > 399) {
        c1_rhoMax = 399;
      }

      c1_st.site = &c1_rj_emlrtRSI;
      c1_l_a = c1_thetaMin;
      c1_l_b = c1_thetaMax;
      c1_m_a = c1_l_a;
      c1_m_b = c1_l_b;
      if (c1_m_a > c1_m_b) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_m_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
      }

      for (c1_theta = c1_thetaMin; c1_theta <= c1_thetaMax; c1_theta++) {
        c1_st.site = &c1_qj_emlrtRSI;
        c1_n_a = c1_rhoMin;
        c1_n_b = c1_rhoMax;
        c1_o_a = c1_n_a;
        c1_o_b = c1_n_b;
        if (c1_o_a > c1_o_b) {
          c1_b_overflow = false;
        } else {
          c1_b_overflow = (c1_o_b > 2147483646);
        }

        if (c1_b_overflow) {
          c1_b_st.site = &c1_kb_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
        }

        for (c1_rho = c1_rhoMin; c1_rho <= c1_rhoMax; c1_rho++) {
          c1_rhoToRemove = c1_rho;
          c1_thetaToRemove = c1_theta;
          if (c1_isThetaAntisymmetric) {
            if (c1_theta > 180) {
              c1_rhoToRemove = 400 - c1_rho;
              c1_thetaToRemove = c1_theta - 180;
            } else {
              if (c1_theta < 1) {
                c1_rhoToRemove = 400 - c1_rho;
                c1_thetaToRemove = c1_theta + 180;
              }
            }
          }

          if ((c1_thetaToRemove > 180) || (c1_thetaToRemove < 1)) {
          } else {
            chartInstance->c1_hnew[(c1_rhoToRemove + 399 * (c1_thetaToRemove - 1))
              - 1] = 0.0;
          }
        }
      }

      c1_isDone = (c1_peakIdx == 5);
    } else {
      c1_isDone = true;
    }
  }

  if (c1_peakIdx == 0) {
    c1_peaks->size[0] = 0;
    c1_peaks->size[1] = 0;
  } else {
    c1_i7 = c1_peakIdx - 1;
    c1_i8 = c1_peaks->size[0] * c1_peaks->size[1];
    c1_peaks->size[0] = c1_i7 + 1;
    c1_peaks->size[1] = 2;
    c1_st.site = &c1_ll_emlrtRSI;
    c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_peaks, c1_i8,
      &c1_kg_emlrtRTEI);
    for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
      c1_loop_ub = c1_i7;
      for (c1_i10 = 0; c1_i10 <= c1_loop_ub; c1_i10++) {
        c1_peaks->data[c1_i10 + c1_peaks->size[0] * c1_i9] =
          chartInstance->c1_peakCoordinates[c1_i10 + 71820 * c1_i9];
      }
    }
  }
}

static void c1_b_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, real_T c1_g_a[2])
{
  static char_T c1_b_cv5[43] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'O', 'd', 'd' };

  static char_T c1_b_cv2[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv4[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'O', 'd', 'd' };

  static char_T c1_b_cv[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c1_b_cv1[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c1_b_cv3[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c1_b_cv6[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_j_y = NULL;
  const mxArray *c1_k_y = NULL;
  const mxArray *c1_l_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_b_k;
  real_T c1_c_x;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_k;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_k;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r;
  real_T c1_r_x;
  real_T c1_s_x;
  int32_T c1_c_k;
  int32_T c1_e_k;
  int32_T c1_g_k;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  boolean_T c1_b6;
  boolean_T c1_b7;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_d_b;
  boolean_T c1_d_p;
  boolean_T c1_e_b;
  boolean_T c1_e_p;
  boolean_T c1_exitg1;
  boolean_T c1_f_b;
  boolean_T c1_f_p;
  boolean_T c1_g_b;
  boolean_T c1_g_p;
  boolean_T c1_h_b;
  boolean_T c1_h_p;
  boolean_T c1_i_b;
  boolean_T c1_p;
  boolean_T c1_rEQ0;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_s_emlrtRSI;
  c1_p = true;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k < 2)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_c_x = c1_g_a[(int32_T)c1_b_k - 1];
    c1_d_x = c1_c_x;
    c1_b_b = muDoubleScalarIsInf(c1_d_x);
    c1_b1 = !c1_b_b;
    c1_e_x = c1_c_x;
    c1_c_b = muDoubleScalarIsNaN(c1_e_x);
    c1_b2 = !c1_c_b;
    c1_d_b = (c1_b1 && c1_b2);
    if (c1_d_b) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv7, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_st, &c1_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14, sf_mex_call
                (&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(&c1_st, NULL,
      "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_b_p = true;
  c1_c_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k < 2)) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_f_x = c1_g_a[(int32_T)c1_d_k - 1];
    c1_g_x = c1_f_x;
    c1_h_x = c1_g_x;
    c1_e_b = muDoubleScalarIsInf(c1_h_x);
    c1_b4 = !c1_e_b;
    c1_i_x = c1_g_x;
    c1_f_b = muDoubleScalarIsNaN(c1_i_x);
    c1_b5 = !c1_f_b;
    c1_g_b = (c1_b4 && c1_b5);
    if (c1_g_b) {
      c1_j_x = c1_f_x;
      c1_l_x = c1_j_x;
      c1_l_x = muDoubleScalarFloor(c1_l_x);
      if (c1_l_x == c1_f_x) {
        c1_d_p = true;
      } else {
        c1_d_p = false;
      }
    } else {
      c1_d_p = false;
    }

    c1_f_p = c1_d_p;
    if (c1_f_p) {
      c1_c_k++;
    } else {
      c1_b_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_b_p) {
    c1_b3 = true;
  } else {
    c1_b3 = false;
  }

  if (!c1_b3) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv8, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv9, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_st, &c1_db_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_e_y, 14, c1_f_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_c_p = true;
  c1_e_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_e_k < 2)) {
    c1_f_k = (real_T)c1_e_k + 1.0;
    c1_k_x = c1_g_a[(int32_T)c1_f_k - 1];
    c1_e_p = !(c1_k_x <= 0.0);
    if (c1_e_p) {
      c1_e_k++;
    } else {
      c1_c_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_c_p) {
    c1_b6 = true;
  } else {
    c1_b6 = false;
  }

  if (!c1_b6) {
    c1_g_y = NULL;
    sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c1_h_y = NULL;
    sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_cv6, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c1_i_y = NULL;
    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_st, &c1_y_emlrtMCI, "error", 0U, 2U, 14, c1_g_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_h_y, 14, c1_i_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_g_p = true;
  c1_g_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_g_k < 2)) {
    c1_h_k = (real_T)c1_g_k + 1.0;
    c1_m_x = c1_g_a[(int32_T)c1_h_k - 1];
    c1_n_x = c1_m_x;
    c1_o_x = c1_n_x;
    c1_p_x = c1_o_x;
    c1_q_x = c1_p_x;
    c1_r_x = c1_q_x;
    c1_h_b = muDoubleScalarIsNaN(c1_r_x);
    if (c1_h_b) {
      c1_r = rtNaN;
    } else {
      c1_s_x = c1_q_x;
      c1_i_b = muDoubleScalarIsInf(c1_s_x);
      if (c1_i_b) {
        c1_r = rtNaN;
      } else {
        c1_r = muDoubleScalarRem(c1_q_x, 2.0);
        c1_rEQ0 = (c1_r == 0.0);
        if (c1_rEQ0) {
          c1_r = 0.0;
        }
      }
    }

    c1_h_p = (c1_r == 1.0);
    if (c1_h_p) {
      c1_g_k++;
    } else {
      c1_g_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_g_p) {
    c1_b7 = true;
  } else {
    c1_b7 = false;
  }

  if (!c1_b7) {
    c1_j_y = NULL;
    sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_b_cv4, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c1_k_y = NULL;
    sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_b_cv5, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c1_l_y = NULL;
    sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_b_cv6, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c1_st, &c1_fb_emlrtMCI, "error", 0U, 2U, 14, c1_j_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_k_y, 14, c1_l_y)));
  }
}

static real_T c1_b_minimum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_c_x[180])
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_st;
  real_T c1_b_x_data[180];
  real_T c1_b_ex;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_ex;
  real_T c1_f_x;
  real_T c1_g_x;
  int32_T c1_b_idx;
  int32_T c1_b_k;
  int32_T c1_first;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_od_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_b_st.site = &c1_pd_emlrtRSI;
  for (c1_i = 0; c1_i < 180; c1_i++) {
    c1_b_x_data[c1_i] = c1_c_x[c1_i];
  }

  c1_c_st.site = &c1_qd_emlrtRSI;
  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_d_x = c1_b_x_data[0];
  c1_e_x = c1_d_x;
  c1_b = muDoubleScalarIsNaN(c1_e_x);
  c1_p = !c1_b;
  if (c1_p) {
    c1_b_idx = 1;
  } else {
    c1_b_idx = 0;
    c1_e_st.site = &c1_jb_emlrtRSI;
    c1_k = 2;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 181)) {
      c1_f_x = c1_b_x_data[c1_k - 1];
      c1_g_x = c1_f_x;
      c1_b_b = muDoubleScalarIsNaN(c1_g_x);
      c1_b_p = !c1_b_b;
      if (c1_b_p) {
        c1_b_idx = c1_k;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }
  }

  if (c1_b_idx == 0) {
    c1_ex = c1_b_x_data[0];
  } else {
    c1_d_st.site = &c1_hb_emlrtRSI;
    c1_first = c1_b_idx - 1;
    c1_b_ex = c1_b_x_data[c1_first];
    c1_i1 = c1_first;
    c1_e_st.site = &c1_lb_emlrtRSI;
    c1_overflow = false;
    if (c1_overflow) {
      c1_f_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
    }

    for (c1_b_k = c1_i1 + 1; c1_b_k + 1 < 181; c1_b_k++) {
      if (c1_b_ex > c1_b_x_data[c1_b_k]) {
        c1_b_ex = c1_b_x_data[c1_b_k];
      }
    }

    c1_ex = c1_b_ex;
  }

  return c1_ex;
}

static real_T c1_c_maximum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real_T c1_c_x[180])
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_f_st;
  emlrtStack c1_st;
  real_T c1_b_x_data[180];
  real_T c1_b_ex;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_ex;
  real_T c1_f_x;
  real_T c1_g_x;
  int32_T c1_b_idx;
  int32_T c1_b_k;
  int32_T c1_first;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_k;
  boolean_T c1_b;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_hc_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_f_st.prev = &c1_e_st;
  c1_f_st.tls = c1_e_st.tls;
  c1_b_st.site = &c1_ic_emlrtRSI;
  for (c1_i = 0; c1_i < 180; c1_i++) {
    c1_b_x_data[c1_i] = c1_c_x[c1_i];
  }

  c1_c_st.site = &c1_gb_emlrtRSI;
  c1_d_st.site = &c1_ib_emlrtRSI;
  c1_d_x = c1_b_x_data[0];
  c1_e_x = c1_d_x;
  c1_b = muDoubleScalarIsNaN(c1_e_x);
  c1_p = !c1_b;
  if (c1_p) {
    c1_b_idx = 1;
  } else {
    c1_b_idx = 0;
    c1_e_st.site = &c1_jb_emlrtRSI;
    c1_k = 2;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 181)) {
      c1_f_x = c1_b_x_data[c1_k - 1];
      c1_g_x = c1_f_x;
      c1_b_b = muDoubleScalarIsNaN(c1_g_x);
      c1_b_p = !c1_b_b;
      if (c1_b_p) {
        c1_b_idx = c1_k;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }
  }

  if (c1_b_idx == 0) {
    c1_ex = c1_b_x_data[0];
  } else {
    c1_d_st.site = &c1_hb_emlrtRSI;
    c1_first = c1_b_idx - 1;
    c1_b_ex = c1_b_x_data[c1_first];
    c1_i1 = c1_first;
    c1_e_st.site = &c1_lb_emlrtRSI;
    c1_overflow = false;
    if (c1_overflow) {
      c1_f_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_f_st);
    }

    for (c1_b_k = c1_i1 + 1; c1_b_k + 1 < 181; c1_b_k++) {
      if (c1_b_ex < c1_b_x_data[c1_b_k]) {
        c1_b_ex = c1_b_x_data[c1_b_k];
      }
    }

    c1_ex = c1_b_ex;
  }

  return c1_ex;
}

static void c1_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                    real_T c1_c_x[180], real_T c1_y[179])
{
  real_T c1_tmp1;
  real_T c1_tmp2;
  real_T c1_work;
  int32_T c1_ixLead;
  int32_T c1_iyLead;
  int32_T c1_m;
  (void)chartInstance;
  c1_ixLead = 1;
  c1_iyLead = 0;
  c1_work = c1_c_x[0];
  for (c1_m = 0; c1_m < 179; c1_m++) {
    c1_tmp1 = c1_c_x[c1_ixLead];
    c1_tmp2 = c1_work;
    c1_work = c1_tmp1;
    c1_tmp1 -= c1_tmp2;
    c1_ixLead++;
    c1_y[c1_iyLead] = c1_tmp1;
    c1_iyLead++;
  }
}

static void c1_b_diff(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      real_T c1_c_x[179], real_T c1_y[178])
{
  real_T c1_tmp1;
  real_T c1_tmp2;
  real_T c1_work;
  int32_T c1_ixLead;
  int32_T c1_iyLead;
  int32_T c1_m;
  (void)chartInstance;
  c1_ixLead = 1;
  c1_iyLead = 0;
  c1_work = c1_c_x[0];
  for (c1_m = 0; c1_m < 178; c1_m++) {
    c1_tmp1 = c1_c_x[c1_ixLead];
    c1_tmp2 = c1_work;
    c1_work = c1_tmp1;
    c1_tmp1 -= c1_tmp2;
    c1_ixLead++;
    c1_y[c1_iyLead] = c1_tmp1;
    c1_iyLead++;
  }
}

static void c1_houghlines(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, boolean_T c1_d_varargin_1[19200], c1_emxArray_real_T *
  c1_varargin_4, c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *c1_lines)
{
  static real_T c1_b_dv[399] = { -199.0, -198.0, -197.0, -196.0, -195.0, -194.0,
    -193.0, -192.0, -191.0, -190.0, -189.0, -188.0, -187.0, -186.0, -185.0,
    -184.0, -183.0, -182.0, -181.0, -180.0, -179.0, -178.0, -177.0, -176.0,
    -175.0, -174.0, -173.0, -172.0, -171.0, -170.0, -169.0, -168.0, -167.0,
    -166.0, -165.0, -164.0, -163.0, -162.0, -161.0, -160.0, -159.0, -158.0,
    -157.0, -156.0, -155.0, -154.0, -153.0, -152.0, -151.0, -150.0, -149.0,
    -148.0, -147.0, -146.0, -145.0, -144.0, -143.0, -142.0, -141.0, -140.0,
    -139.0, -138.0, -137.0, -136.0, -135.0, -134.0, -133.0, -132.0, -131.0,
    -130.0, -129.0, -128.0, -127.0, -126.0, -125.00000000000001, -124.0, -123.0,
    -122.0, -121.0, -119.99999999999999, -119.0, -118.0, -117.0, -116.0,
    -114.99999999999999, -114.00000000000001, -113.0, -112.0, -111.0,
    -109.99999999999999, -109.00000000000001, -108.0, -107.0, -106.0,
    -104.99999999999999, -104.00000000000001, -103.0, -102.0, -101.0,
    -99.999999999999986, -99.0, -98.0, -97.0, -96.0, -95.0, -94.0, -93.0, -92.0,
    -91.0, -90.0, -89.0, -88.0, -87.0, -86.0, -85.0, -84.0, -83.0, -82.0, -81.0,
    -80.0, -79.0, -78.0, -77.0, -76.0, -75.0, -74.0, -73.0, -72.0, -71.0, -70.0,
    -69.0, -68.0, -67.0, -66.0, -65.0, -64.0, -63.0, -62.0, -61.0,
    -59.999999999999993, -59.0, -58.0, -57.000000000000007, -56.0,
    -54.999999999999993, -54.0, -53.0, -52.000000000000007, -51.0,
    -49.999999999999993, -49.0, -48.0, -47.0, -46.0, -45.0, -44.0, -43.0, -42.0,
    -41.0, -40.0, -39.0, -38.0, -37.0, -36.0, -35.0, -34.0, -33.0, -32.0, -31.0,
    -29.999999999999996, -29.0, -28.0, -27.0, -26.000000000000004,
    -24.999999999999996, -24.0, -23.0, -22.0, -21.0, -20.0, -19.0, -18.0, -17.0,
    -16.0, -14.999999999999998, -14.0, -13.000000000000002, -12.0, -11.0, -10.0,
    -9.0, -8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0,
    4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.000000000000002, 14.0,
    14.999999999999998, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0,
    24.999999999999996, 26.000000000000004, 27.0, 28.0, 29.0, 29.999999999999996,
    31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0,
    44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 49.999999999999993, 51.0,
    52.000000000000007, 53.0, 54.0, 54.999999999999993, 56.0, 57.000000000000007,
    58.0, 59.0, 59.999999999999993, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0,
    68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0, 80.0,
    81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0, 93.0,
    94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 99.999999999999986, 101.0, 102.0, 103.0,
    104.00000000000001, 104.99999999999999, 106.0, 107.0, 108.0,
    109.00000000000001, 109.99999999999999, 111.0, 112.0, 113.0,
    114.00000000000001, 114.99999999999999, 116.0, 117.0, 118.0, 119.0,
    119.99999999999999, 121.0, 122.0, 123.0, 124.0, 125.00000000000001, 126.0,
    127.0, 128.0, 129.0, 130.0, 131.0, 132.0, 133.0, 134.0, 135.0, 136.0, 137.0,
    138.0, 139.0, 140.0, 141.0, 142.0, 143.0, 144.0, 145.0, 146.0, 147.0, 148.0,
    149.0, 150.0, 151.0, 152.0, 153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0,
    160.0, 161.0, 162.0, 163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0,
    171.0, 172.0, 173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0,
    182.0, 183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
    193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0 };

  static char_T c1_b_cv[30] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'P', 'E', 'A', 'K', 'S' };

  c1_emxArray_int32_T *c1_b_point1Array;
  c1_emxArray_int32_T *c1_b_point2Array;
  c1_emxArray_int32_T *c1_houghPix;
  c1_emxArray_int32_T *c1_point1Array;
  c1_emxArray_int32_T *c1_point2Array;
  c1_emxArray_int32_T *c1_r;
  c1_emxArray_real32_T *c1_b_rhoArray;
  c1_emxArray_real32_T *c1_b_thetaArray;
  c1_emxArray_real32_T *c1_rhoArray;
  c1_emxArray_real32_T *c1_thetaArray;
  c1_emxArray_real_T *c1_b_varargin_4;
  c1_emxArray_real_T *c1_distances2;
  c1_emxArray_real_T *c1_indices;
  c1_emxArray_real_T *c1_peaks;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_tempBin[120];
  real_T c1_sortingOrder[2];
  real_T c1_ab_x;
  real_T c1_b_j;
  real_T c1_b_n;
  real_T c1_b_numHoughPix;
  real_T c1_b_peakIdx;
  real_T c1_b_varargin_2;
  real_T c1_b_y;
  real_T c1_bb_x;
  real_T c1_c_i;
  real_T c1_c_k;
  real_T c1_c_varargin_2;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_cb_x;
  real_T c1_colMax;
  real_T c1_colMin;
  real_T c1_colRange;
  real_T c1_cosTheta;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d_varargin_2;
  real_T c1_d_x;
  real_T c1_d_y;
  real_T c1_db_x;
  real_T c1_e_varargin_1;
  real_T c1_e_varargin_2;
  real_T c1_e_x;
  real_T c1_e_y;
  real_T c1_f_i;
  real_T c1_f_varargin_1;
  real_T c1_f_x;
  real_T c1_f_y;
  real_T c1_g_k;
  real_T c1_g_varargin_1;
  real_T c1_g_x;
  real_T c1_g_y;
  real_T c1_h_varargin_1;
  real_T c1_h_x;
  real_T c1_h_y;
  real_T c1_i_x;
  real_T c1_i_y;
  real_T c1_j_k;
  real_T c1_j_x;
  real_T c1_j_y;
  real_T c1_k_x;
  real_T c1_k_y;
  real_T c1_l_x;
  real_T c1_l_y;
  real_T c1_m_k;
  real_T c1_m_x;
  real_T c1_m_y;
  real_T c1_n;
  real_T c1_n_x;
  real_T c1_n_y;
  real_T c1_numPairs;
  real_T c1_numPeaks;
  real_T c1_o_x;
  real_T c1_o_y;
  real_T c1_p_x;
  real_T c1_p_y;
  real_T c1_q_x;
  real_T c1_q_y;
  real_T c1_r_x;
  real_T c1_r_y;
  real_T c1_rhoVal;
  real_T c1_rowMax;
  real_T c1_rowMin;
  real_T c1_rowRange;
  real_T c1_s_x;
  real_T c1_s_y;
  real_T c1_sinTheta;
  real_T c1_t_x;
  real_T c1_t_y;
  real_T c1_tempNum;
  real_T c1_thetaVal;
  real_T c1_u_x;
  real_T c1_u_y;
  real_T c1_v_x;
  real_T c1_v_y;
  real_T c1_w_x;
  real_T c1_w_y;
  real_T c1_x_x;
  real_T c1_x_y;
  real_T c1_y;
  real_T c1_y_x;
  int32_T c1_houghPixTemp[19200];
  int32_T c1_nonZeroPixelMatrix[19200];
  int32_T c1_tempHoughPixNumsVector[160];
  int32_T c1_tempNumsVector[160];
  int32_T c1_b_tempBin[120];
  int32_T c1_point1_data[2];
  int32_T c1_point1_size[2];
  int32_T c1_point2_data[2];
  int32_T c1_point2_size[2];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_c;
  int32_T c1_b_i;
  int32_T c1_b_indices;
  int32_T c1_b_k;
  int32_T c1_b_lines;
  int32_T c1_b_loop_ub;
  int32_T c1_b_numLines;
  int32_T c1_b_peak1;
  int32_T c1_b_peak2;
  int32_T c1_b_tempNum;
  int32_T c1_c;
  int32_T c1_c_b;
  int32_T c1_c_c;
  int32_T c1_c_indices;
  int32_T c1_c_j;
  int32_T c1_c_lines;
  int32_T c1_c_loop_ub;
  int32_T c1_c_numLines;
  int32_T c1_d_b;
  int32_T c1_d_c;
  int32_T c1_d_i;
  int32_T c1_d_j;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_e_b;
  int32_T c1_e_i;
  int32_T c1_e_j;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_f_b;
  int32_T c1_f_k;
  int32_T c1_f_loop_ub;
  int32_T c1_g_a;
  int32_T c1_g_loop_ub;
  int32_T c1_h_a;
  int32_T c1_h_k;
  int32_T c1_h_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i9;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i_a;
  int32_T c1_i_k;
  int32_T c1_i_loop_ub;
  int32_T c1_j;
  int32_T c1_j_a;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_k_k;
  int32_T c1_k_loop_ub;
  int32_T c1_l_k;
  int32_T c1_l_loop_ub;
  int32_T c1_lineLength2;
  int32_T c1_loop_ub;
  int32_T c1_m_loop_ub;
  int32_T c1_n_loop_ub;
  int32_T c1_numHoughPix;
  int32_T c1_numLines;
  int32_T c1_peak1;
  int32_T c1_peak2;
  int32_T c1_peakIdx;
  int32_T c1_rhoBinIdx;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_exitg1;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_emxInit_real_T(chartInstance, c1_sp, &c1_b_varargin_4, 2, &c1_lg_emlrtRTEI);
  c1_st.site = &c1_gk_emlrtRSI;
  c1_i = c1_b_varargin_4->size[0] * c1_b_varargin_4->size[1];
  c1_b_varargin_4->size[0] = c1_varargin_4->size[0];
  c1_b_varargin_4->size[1] = c1_varargin_4->size[1];
  c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_b_varargin_4, c1_i,
    &c1_lg_emlrtRTEI);
  c1_loop_ub = c1_varargin_4->size[0] * c1_varargin_4->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_b_varargin_4->data[c1_i1] = c1_varargin_4->data[c1_i1];
  }

  c1_b_st.site = &c1_mk_emlrtRSI;
  c1_c_validateattributes(chartInstance, &c1_b_st, c1_b_varargin_4);
  c1_emxFree_real_T(chartInstance, &c1_b_varargin_4);
  if ((real_T)c1_varargin_4->size[1] != 2.0) {
    sf_mex_call(&c1_st, &c1_hb_emlrtMCI, "error", 0U, 2U, 14,
                c1_emlrt_marshallOut(chartInstance, c1_b_cv), 14, sf_mex_call
                (&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(&c1_st, NULL,
      "message", 1U, 1U, 14, c1_emlrt_marshallOut(chartInstance, c1_b_cv))));
  }

  c1_emxInit_real_T(chartInstance, &c1_st, &c1_peaks, 2, &c1_hh_emlrtRTEI);
  c1_i2 = c1_peaks->size[0] * c1_peaks->size[1];
  c1_peaks->size[0] = c1_varargin_4->size[0];
  c1_peaks->size[1] = c1_varargin_4->size[1];
  c1_st.site = &c1_gk_emlrtRSI;
  c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_peaks, c1_i2,
    &c1_mg_emlrtRTEI);
  c1_b_loop_ub = c1_varargin_4->size[0] * c1_varargin_4->size[1] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_peaks->data[c1_i3] = c1_varargin_4->data[c1_i3];
  }

  c1_st.site = &c1_hk_emlrtRSI;
  for (c1_j = 0; c1_j < 160; c1_j++) {
    c1_b_j = (real_T)c1_j + 1.0;
    c1_tempNum = 0.0;
    for (c1_b_i = 0; c1_b_i < 120; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i + 1.0;
      if (c1_d_varargin_1[((int32_T)c1_c_i + 120 * ((int32_T)c1_b_j - 1)) - 1])
      {
        c1_tempNum++;
        c1_i4 = (int32_T)c1_tempNum;
        c1_tempBin[emlrtDynamicBoundsCheckR2012b(c1_i4, 1, 120, &c1_nf_emlrtBCI,
          &c1_st) - 1] = c1_c_i - 1.0;
      }
    }

    c1_tempNumsVector[(int32_T)c1_b_j - 1] = (int32_T)c1_tempNum;
    c1_d_i = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_d_i < 120)) {
      c1_c_i = (real_T)c1_d_i + 1.0;
      if (c1_c_i > c1_tempNum) {
        c1_exitg1 = true;
      } else {
        c1_nonZeroPixelMatrix[((int32_T)c1_c_i + 120 * ((int32_T)c1_b_j - 1)) -
          1] = (int32_T)c1_tempBin[(int32_T)c1_c_i - 1];
        c1_d_i++;
      }
    }
  }

  c1_emxInit_int32_T1(chartInstance, &c1_st, &c1_point1Array, 2,
                      &c1_ch_emlrtRTEI);
  c1_numLines = 0;
  c1_point1Array->size[0] = 0;
  c1_point1Array->size[1] = 2;
  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_point2Array, 2, &c1_dh_emlrtRTEI);
  c1_point2Array->size[0] = 0;
  c1_point2Array->size[1] = 2;
  c1_emxInit_real32_T(chartInstance, c1_sp, &c1_thetaArray, 1, &c1_eh_emlrtRTEI);
  c1_thetaArray->size[0] = 0;
  c1_emxInit_real32_T(chartInstance, c1_sp, &c1_rhoArray, 1, &c1_fh_emlrtRTEI);
  c1_rhoArray->size[0] = 0;
  c1_numPeaks = (real_T)c1_peaks->size[0];
  c1_i5 = (int32_T)c1_numPeaks - 1;
  c1_peakIdx = 0;
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_indices, 1, &c1_gh_emlrtRTEI);
  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_houghPix, 2, &c1_ih_emlrtRTEI);
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_distances2, 1, &c1_jh_emlrtRTEI);
  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_r, 2, &c1_ng_emlrtRTEI);
  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_b_point1Array, 2,
                      &c1_tg_emlrtRTEI);
  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_b_point2Array, 2,
                      &c1_vg_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, c1_sp, &c1_b_thetaArray, 1,
                      &c1_xg_emlrtRTEI);
  c1_emxInit_real32_T(chartInstance, c1_sp, &c1_b_rhoArray, 1, &c1_ah_emlrtRTEI);
  while (c1_peakIdx <= c1_i5) {
    c1_b_peakIdx = (real_T)c1_peakIdx + 1.0;
    c1_i6 = c1_peaks->size[0];
    c1_i7 = (int32_T)c1_b_peakIdx;
    c1_peak1 = (int32_T)c1_peaks->data[emlrtDynamicBoundsCheckR2012b(c1_i7, 1,
      c1_i6, &c1_bg_emlrtBCI, c1_sp) - 1];
    c1_i8 = c1_peaks->size[0];
    c1_i9 = (int32_T)c1_b_peakIdx;
    c1_peak2 = (int32_T)c1_peaks->data[(emlrtDynamicBoundsCheckR2012b(c1_i9, 1,
      c1_i8, &c1_cg_emlrtBCI, c1_sp) + c1_peaks->size[0]) - 1];
    c1_st.site = &c1_ik_emlrtRSI;
    c1_b_peak1 = c1_peak1;
    c1_b_peak2 = c1_peak2;
    c1_numHoughPix = 0;
    c1_thetaVal = (-90.0 + (real_T)(emlrtDynamicBoundsCheckR2012b(c1_b_peak2, 1,
      180, &c1_rf_emlrtBCI, &c1_st) - 1)) * 3.1415926535897931 / 180.0;
    c1_c_x = c1_thetaVal;
    c1_cosTheta = c1_c_x;
    c1_cosTheta = muDoubleScalarCos(c1_cosTheta);
    c1_d_x = c1_thetaVal;
    c1_sinTheta = c1_d_x;
    c1_sinTheta = muDoubleScalarSin(c1_sinTheta);
    c1_rowMax = 0.0;
    c1_rowMin = rtInf;
    c1_colMax = 0.0;
    c1_colMin = rtInf;
    for (c1_k = 0; c1_k < 160; c1_k++) {
      c1_c_k = (real_T)c1_k + 1.0;
      c1_b_tempNum = 0;
      c1_i10 = c1_tempNumsVector[(int32_T)c1_c_k - 1];
      c1_b_st.site = &c1_pk_emlrtRSI;
      c1_c_b = c1_i10;
      c1_d_b = c1_c_b;
      if (1 > c1_d_b) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_d_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_c_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
      }

      for (c1_c_j = 1; c1_c_j - 1 < c1_i10; c1_c_j++) {
        c1_e_j = c1_c_j - 1;
        c1_rhoVal = (c1_c_k - 1.0) * c1_cosTheta + (real_T)
          c1_nonZeroPixelMatrix[c1_e_j + 120 * ((int32_T)c1_c_k - 1)] *
          c1_sinTheta;
        c1_e_x = (c1_rhoVal - -199.0) + 1.0;
        c1_rhoBinIdx = (int32_T)(c1_e_x + 0.5);
        if (c1_rhoBinIdx == c1_b_peak1) {
          c1_b_tempNum++;
          c1_b_tempBin[emlrtDynamicBoundsCheckR2012b(c1_b_tempNum, 1, 120,
            &c1_kg_emlrtBCI, &c1_st) - 1] = c1_nonZeroPixelMatrix[c1_e_j + 120 *
            ((int32_T)c1_c_k - 1)] + 1;
        }
      }

      c1_tempHoughPixNumsVector[(int32_T)c1_c_k - 1] = c1_b_tempNum;
      c1_numHoughPix += c1_b_tempNum;
      if (c1_b_tempNum != 0) {
        c1_e_varargin_1 = c1_rowMax;
        c1_b_varargin_2 = (real_T)c1_b_tempBin[c1_b_tempNum - 1];
        c1_f_x = c1_e_varargin_1;
        c1_y = c1_b_varargin_2;
        c1_g_x = c1_f_x;
        c1_b_y = c1_y;
        c1_h_x = c1_g_x;
        c1_c_y = c1_b_y;
        c1_i_x = c1_h_x;
        c1_d_y = c1_c_y;
        c1_j_x = c1_i_x;
        c1_e_y = c1_d_y;
        c1_k_x = c1_j_x;
        c1_f_y = c1_e_y;
        c1_rowMax = muDoubleScalarMax(c1_k_x, c1_f_y);
        c1_f_varargin_1 = c1_rowMin;
        c1_c_varargin_2 = (real_T)c1_b_tempBin[0];
        c1_l_x = c1_f_varargin_1;
        c1_g_y = c1_c_varargin_2;
        c1_m_x = c1_l_x;
        c1_h_y = c1_g_y;
        c1_n_x = c1_m_x;
        c1_i_y = c1_h_y;
        c1_o_x = c1_n_x;
        c1_j_y = c1_i_y;
        c1_p_x = c1_o_x;
        c1_k_y = c1_j_y;
        c1_q_x = c1_p_x;
        c1_l_y = c1_k_y;
        c1_rowMin = muDoubleScalarMin(c1_q_x, c1_l_y);
        c1_g_varargin_1 = c1_colMax;
        c1_d_varargin_2 = c1_c_k;
        c1_r_x = c1_g_varargin_1;
        c1_m_y = c1_d_varargin_2;
        c1_s_x = c1_r_x;
        c1_n_y = c1_m_y;
        c1_t_x = c1_s_x;
        c1_o_y = c1_n_y;
        c1_u_x = c1_t_x;
        c1_p_y = c1_o_y;
        c1_v_x = c1_u_x;
        c1_q_y = c1_p_y;
        c1_w_x = c1_v_x;
        c1_r_y = c1_q_y;
        c1_colMax = muDoubleScalarMax(c1_w_x, c1_r_y);
        c1_h_varargin_1 = c1_colMin;
        c1_e_varargin_2 = c1_c_k;
        c1_x_x = c1_h_varargin_1;
        c1_s_y = c1_e_varargin_2;
        c1_y_x = c1_x_x;
        c1_t_y = c1_s_y;
        c1_ab_x = c1_y_x;
        c1_u_y = c1_t_y;
        c1_bb_x = c1_ab_x;
        c1_v_y = c1_u_y;
        c1_cb_x = c1_bb_x;
        c1_w_y = c1_v_y;
        c1_db_x = c1_cb_x;
        c1_x_y = c1_w_y;
        c1_colMin = muDoubleScalarMin(c1_db_x, c1_x_y);
      }

      c1_e_i = 0;
      c1_exitg1 = false;
      while ((!c1_exitg1) && (c1_e_i < 120)) {
        c1_f_i = (real_T)c1_e_i + 1.0;
        if (c1_f_i > (real_T)c1_b_tempNum) {
          c1_exitg1 = true;
        } else {
          c1_houghPixTemp[((int32_T)c1_f_i + 120 * ((int32_T)c1_c_k - 1)) - 1] =
            c1_b_tempBin[(int32_T)c1_f_i - 1];
          c1_e_i++;
        }
      }
    }

    if (c1_numHoughPix < 1) {
      c1_houghPix->size[0] = 0;
      c1_houghPix->size[1] = 0;
    } else {
      c1_n = 0.0;
      for (c1_e_k = 0; c1_e_k < 160; c1_e_k++) {
        c1_g_k = (real_T)c1_e_k + 1.0;
        c1_i12 = c1_tempHoughPixNumsVector[(int32_T)c1_g_k - 1];
        c1_b_st.site = &c1_ok_emlrtRSI;
        c1_e_b = c1_i12;
        c1_f_b = c1_e_b;
        if (1 > c1_f_b) {
          c1_c_overflow = false;
        } else {
          c1_c_overflow = (c1_f_b > 2147483646);
        }

        if (c1_c_overflow) {
          c1_c_st.site = &c1_kb_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
        }

        for (c1_d_j = 1; c1_d_j - 1 < c1_i12; c1_d_j++) {
          c1_e_j = c1_d_j - 1;
          c1_n++;
          c1_i29 = (int32_T)c1_n;
          chartInstance->c1_houghPixIdx[emlrtDynamicBoundsCheckR2012b(c1_i29, 1,
            19200, &c1_jg_emlrtBCI, &c1_st) - 1] = c1_houghPixTemp[c1_e_j + 120 *
            ((int32_T)c1_g_k - 1)];
          chartInstance->c1_houghPixIdx[(int32_T)c1_n + 19199] = (int32_T)c1_g_k;
        }
      }

      c1_rowRange = c1_rowMax - c1_rowMin;
      c1_colRange = c1_colMax - c1_colMin;
      if (c1_rowRange > c1_colRange) {
        for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
          c1_sortingOrder[c1_i15] = 1.0 + (real_T)c1_i15;
        }
      } else {
        for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
          c1_sortingOrder[c1_i14] = 2.0 - (real_T)c1_i14;
        }
      }

      c1_i18 = emlrtDynamicBoundsCheckR2012b(c1_numHoughPix, 1, 19200,
        &c1_qf_emlrtBCI, &c1_st) - 1;
      c1_i20 = c1_r->size[0] * c1_r->size[1];
      c1_r->size[0] = c1_i18 + 1;
      c1_r->size[1] = 2;
      c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_r, c1_i20,
        &c1_ng_emlrtRTEI);
      for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
        c1_c_loop_ub = c1_i18;
        for (c1_i27 = 0; c1_i27 <= c1_c_loop_ub; c1_i27++) {
          c1_r->data[c1_i27 + c1_r->size[0] * c1_i23] =
            chartInstance->c1_houghPixIdx[c1_i27 + 19200 * c1_i23];
        }
      }

      c1_b_st.site = &c1_nk_emlrtRSI;
      c1_b_sortrows(chartInstance, &c1_b_st, c1_r, c1_sortingOrder);
      c1_i28 = c1_houghPix->size[0] * c1_houghPix->size[1];
      c1_houghPix->size[0] = c1_r->size[0];
      c1_houghPix->size[1] = 2;
      c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_houghPix, c1_i28,
        &c1_pg_emlrtRTEI);
      c1_d_loop_ub = c1_r->size[0] * c1_r->size[1] - 1;
      for (c1_i34 = 0; c1_i34 <= c1_d_loop_ub; c1_i34++) {
        c1_houghPix->data[c1_i34] = c1_r->data[c1_i34];
      }
    }

    if (!(c1_numHoughPix < 1)) {
      c1_st.site = &c1_jk_emlrtRSI;
      c1_b_numHoughPix = (real_T)c1_houghPix->size[0];
      c1_b_st.site = &c1_wk_emlrtRSI;
      c1_c_st.site = &c1_t_emlrtRSI;
      c1_i17 = c1_distances2->size[0];
      c1_d = c1_b_numHoughPix - 1.0;
      c1_distances2->size[0] = (int32_T)emlrtNonNegativeCheckR2012b(c1_d,
        &c1_l_emlrtDCI, &c1_st);
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_distances2, c1_i17,
        &c1_og_emlrtRTEI);
      c1_numPairs = 0.0;
      c1_d1 = c1_b_numHoughPix - 1.0;
      c1_i24 = (int32_T)c1_d1 - 1;
      for (c1_i_k = 0; c1_i_k <= c1_i24; c1_i_k++) {
        c1_j_k = (real_T)c1_i_k + 1.0;
        c1_i31 = c1_houghPix->size[1];
        c1_i32 = 1;
        emlrtDynamicBoundsCheckR2012b(c1_i32, 1, c1_i31, &c1_sf_emlrtBCI, &c1_st);
        c1_i33 = c1_houghPix->size[1];
        c1_i36 = 1;
        emlrtDynamicBoundsCheckR2012b(c1_i36, 1, c1_i33, &c1_tf_emlrtBCI, &c1_st);
        c1_i38 = c1_houghPix->size[1];
        c1_i39 = 2;
        emlrtDynamicBoundsCheckR2012b(c1_i39, 1, c1_i38, &c1_uf_emlrtBCI, &c1_st);
        c1_i41 = c1_houghPix->size[1];
        c1_i42 = 2;
        emlrtDynamicBoundsCheckR2012b(c1_i42, 1, c1_i41, &c1_vf_emlrtBCI, &c1_st);
        c1_i43 = c1_houghPix->size[0];
        c1_i44 = (int32_T)(c1_j_k + 1.0);
        c1_i47 = c1_houghPix->size[0];
        c1_i49 = (int32_T)c1_j_k;
        c1_g_a = c1_houghPix->data[emlrtDynamicBoundsCheckR2012b(c1_i44, 1,
          c1_i43, &c1_mg_emlrtBCI, &c1_st) - 1] - c1_houghPix->
          data[emlrtDynamicBoundsCheckR2012b(c1_i49, 1, c1_i47, &c1_ng_emlrtBCI,
          &c1_st) - 1];
        c1_c = c1_b_power(chartInstance, c1_g_a);
        c1_i51 = c1_houghPix->size[0];
        c1_i54 = (int32_T)(c1_j_k + 1.0);
        c1_i56 = c1_houghPix->size[0];
        c1_i58 = (int32_T)c1_j_k;
        c1_h_a = c1_houghPix->data[(emlrtDynamicBoundsCheckR2012b(c1_i54, 1,
          c1_i51, &c1_og_emlrtBCI, &c1_st) + c1_houghPix->size[0]) - 1] -
          c1_houghPix->data[(emlrtDynamicBoundsCheckR2012b(c1_i58, 1, c1_i56,
          &c1_pg_emlrtBCI, &c1_st) + c1_houghPix->size[0]) - 1];
        c1_b_c = c1_b_power(chartInstance, c1_h_a);
        c1_i61 = c1_distances2->size[0];
        c1_i62 = (int32_T)c1_j_k;
        c1_distances2->data[emlrtDynamicBoundsCheckR2012b(c1_i62, 1, c1_i61,
          &c1_qg_emlrtBCI, &c1_st) - 1] = (real_T)(c1_c + c1_b_c);
        c1_i64 = c1_distances2->size[0];
        c1_i65 = (int32_T)c1_j_k;
        if (c1_distances2->data[emlrtDynamicBoundsCheckR2012b(c1_i65, 1, c1_i64,
             &c1_rg_emlrtBCI, &c1_st) - 1] > 25.0) {
          c1_numPairs++;
        }
      }

      c1_i30 = c1_indices->size[0];
      c1_d2 = c1_numPairs + 2.0;
      c1_indices->size[0] = (int32_T)emlrtIntegerCheckR2012b(c1_d2,
        &c1_m_emlrtDCI, &c1_st);
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_indices, c1_i30,
        &c1_qg_emlrtRTEI);
      c1_indices->data[0] = 0.0;
      c1_i35 = c1_indices->size[0];
      c1_i37 = c1_indices->size[0];
      c1_indices->data[emlrtDynamicBoundsCheckR2012b(c1_i37, 1, c1_i35,
        &c1_lg_emlrtBCI, &c1_st) - 1] = c1_b_numHoughPix;
      c1_b_n = 1.0;
      c1_d3 = c1_b_numHoughPix - 1.0;
      c1_i40 = (int32_T)c1_d3 - 1;
      for (c1_k_k = 0; c1_k_k <= c1_i40; c1_k_k++) {
        c1_j_k = (real_T)c1_k_k + 1.0;
        c1_i46 = c1_distances2->size[0];
        c1_i48 = (int32_T)c1_j_k;
        if (c1_distances2->data[emlrtDynamicBoundsCheckR2012b(c1_i48, 1, c1_i46,
             &c1_sg_emlrtBCI, &c1_st) - 1] > 25.0) {
          c1_b_n++;
          c1_i50 = c1_indices->size[0];
          c1_i53 = (int32_T)c1_b_n;
          c1_indices->data[emlrtDynamicBoundsCheckR2012b(c1_i53, 1, c1_i50,
            &c1_tg_emlrtBCI, &c1_st) - 1] = c1_j_k;
        }
      }

      c1_d4 = (real_T)c1_indices->size[0] - 1.0;
      c1_i45 = (int32_T)c1_d4 - 1;
      for (c1_l_k = 0; c1_l_k <= c1_i45; c1_l_k++) {
        c1_m_k = (real_T)c1_l_k + 1.0;
        c1_i52 = c1_houghPix->size[0];
        c1_i55 = c1_indices->size[0];
        c1_i57 = (int32_T)c1_m_k;
        c1_i59 = (int32_T)(c1_indices->data[emlrtDynamicBoundsCheckR2012b(c1_i57,
          1, c1_i55, &c1_hf_emlrtBCI, c1_sp) - 1] + 1.0);
        c1_b_indices = emlrtDynamicBoundsCheckR2012b(c1_i59, 1, c1_i52,
          &c1_hf_emlrtBCI, c1_sp) - 1;
        c1_i60 = c1_houghPix->size[1] - 1;
        c1_point1_size[1] = c1_i60 + 1;
        c1_e_loop_ub = c1_i60;
        for (c1_i63 = 0; c1_i63 <= c1_e_loop_ub; c1_i63++) {
          c1_point1_data[c1_i63] = c1_houghPix->data[c1_b_indices +
            c1_houghPix->size[0] * c1_i63];
        }

        c1_i66 = c1_houghPix->size[0];
        c1_i67 = c1_indices->size[0];
        c1_i68 = (int32_T)(c1_m_k + 1.0);
        c1_i69 = (int32_T)c1_indices->data[emlrtDynamicBoundsCheckR2012b(c1_i68,
          1, c1_i67, &c1_if_emlrtBCI, c1_sp) - 1];
        c1_c_indices = emlrtDynamicBoundsCheckR2012b(c1_i69, 1, c1_i66,
          &c1_if_emlrtBCI, c1_sp) - 1;
        c1_i70 = c1_houghPix->size[1] - 1;
        c1_point2_size[1] = c1_i70 + 1;
        c1_f_loop_ub = c1_i70;
        for (c1_i71 = 0; c1_i71 <= c1_f_loop_ub; c1_i71++) {
          c1_point2_data[c1_i71] = c1_houghPix->data[c1_c_indices +
            c1_houghPix->size[0] * c1_i71];
        }

        c1_st.site = &c1_kk_emlrtRSI;
        c1_i72 = 1;
        emlrtDynamicBoundsCheckR2012b(c1_i72, 1, c1_point2_size[1],
          &c1_wf_emlrtBCI, &c1_st);
        c1_i73 = 1;
        emlrtDynamicBoundsCheckR2012b(c1_i73, 1, c1_point1_size[1],
          &c1_xf_emlrtBCI, &c1_st);
        c1_i74 = 2;
        emlrtDynamicBoundsCheckR2012b(c1_i74, 1, c1_point2_size[1],
          &c1_yf_emlrtBCI, &c1_st);
        c1_i75 = 2;
        emlrtDynamicBoundsCheckR2012b(c1_i75, 1, c1_point1_size[1],
          &c1_ag_emlrtBCI, &c1_st);
        c1_i_a = c1_point2_data[0] - c1_point1_data[0];
        c1_c_c = c1_b_power(chartInstance, c1_i_a);
        c1_j_a = c1_point2_data[1] - c1_point1_data[1];
        c1_d_c = c1_b_power(chartInstance, c1_j_a);
        c1_lineLength2 = c1_c_c + c1_d_c;
        if (c1_lineLength2 >= 100) {
          c1_numLines++;
          c1_i76 = 2;
          emlrtDynamicBoundsCheckR2012b(c1_i76, 1, c1_point1_size[1],
            &c1_jf_emlrtBCI, c1_sp);
          c1_i77 = 1;
          emlrtDynamicBoundsCheckR2012b(c1_i77, 1, c1_point1_size[1],
            &c1_kf_emlrtBCI, c1_sp);
          c1_i78 = c1_b_point1Array->size[0] * c1_b_point1Array->size[1];
          c1_b_point1Array->size[0] = c1_point1Array->size[0] + 1;
          c1_b_point1Array->size[1] = 2;
          c1_st.site = &c1_hm_emlrtRSI;
          c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_b_point1Array,
            c1_i78, &c1_tg_emlrtRTEI);
          for (c1_i79 = 0; c1_i79 < 2; c1_i79++) {
            c1_g_loop_ub = c1_point1Array->size[0] - 1;
            for (c1_i80 = 0; c1_i80 <= c1_g_loop_ub; c1_i80++) {
              c1_b_point1Array->data[c1_i80 + c1_b_point1Array->size[0] * c1_i79]
                = c1_point1Array->data[c1_i80 + c1_point1Array->size[0] * c1_i79];
            }
          }

          c1_b_point1Array->data[c1_point1Array->size[0]] = c1_point1_data[1];
          c1_b_point1Array->data[c1_point1Array->size[0] +
            c1_b_point1Array->size[0]] = c1_point1_data[0];
          c1_i81 = c1_point1Array->size[0] * c1_point1Array->size[1];
          c1_point1Array->size[0] = c1_b_point1Array->size[0];
          c1_point1Array->size[1] = 2;
          c1_st.site = &c1_hm_emlrtRSI;
          c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_point1Array,
            c1_i81, &c1_ug_emlrtRTEI);
          c1_h_loop_ub = c1_b_point1Array->size[0] * c1_b_point1Array->size[1] -
            1;
          for (c1_i82 = 0; c1_i82 <= c1_h_loop_ub; c1_i82++) {
            c1_point1Array->data[c1_i82] = c1_b_point1Array->data[c1_i82];
          }

          c1_i83 = 2;
          emlrtDynamicBoundsCheckR2012b(c1_i83, 1, c1_point2_size[1],
            &c1_lf_emlrtBCI, c1_sp);
          c1_i84 = 1;
          emlrtDynamicBoundsCheckR2012b(c1_i84, 1, c1_point2_size[1],
            &c1_mf_emlrtBCI, c1_sp);
          c1_i85 = c1_b_point2Array->size[0] * c1_b_point2Array->size[1];
          c1_b_point2Array->size[0] = c1_point2Array->size[0] + 1;
          c1_b_point2Array->size[1] = 2;
          c1_st.site = &c1_gm_emlrtRSI;
          c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_b_point2Array,
            c1_i85, &c1_vg_emlrtRTEI);
          for (c1_i86 = 0; c1_i86 < 2; c1_i86++) {
            c1_i_loop_ub = c1_point2Array->size[0] - 1;
            for (c1_i87 = 0; c1_i87 <= c1_i_loop_ub; c1_i87++) {
              c1_b_point2Array->data[c1_i87 + c1_b_point2Array->size[0] * c1_i86]
                = c1_point2Array->data[c1_i87 + c1_point2Array->size[0] * c1_i86];
            }
          }

          c1_b_point2Array->data[c1_point2Array->size[0]] = c1_point2_data[1];
          c1_b_point2Array->data[c1_point2Array->size[0] +
            c1_b_point2Array->size[0]] = c1_point2_data[0];
          c1_i88 = c1_point2Array->size[0] * c1_point2Array->size[1];
          c1_point2Array->size[0] = c1_b_point2Array->size[0];
          c1_point2Array->size[1] = 2;
          c1_st.site = &c1_gm_emlrtRSI;
          c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_point2Array,
            c1_i88, &c1_wg_emlrtRTEI);
          c1_j_loop_ub = c1_b_point2Array->size[0] * c1_b_point2Array->size[1] -
            1;
          for (c1_i89 = 0; c1_i89 <= c1_j_loop_ub; c1_i89++) {
            c1_point2Array->data[c1_i89] = c1_b_point2Array->data[c1_i89];
          }

          c1_i90 = c1_b_thetaArray->size[0];
          c1_b_thetaArray->size[0] = c1_thetaArray->size[0] + 1;
          c1_st.site = &c1_hl_emlrtRSI;
          c1_emxEnsureCapacity_real32_T(chartInstance, &c1_st, c1_b_thetaArray,
            c1_i90, &c1_xg_emlrtRTEI);
          c1_k_loop_ub = c1_thetaArray->size[0] - 1;
          for (c1_i91 = 0; c1_i91 <= c1_k_loop_ub; c1_i91++) {
            c1_b_thetaArray->data[c1_i91] = c1_thetaArray->data[c1_i91];
          }

          c1_b_thetaArray->data[c1_thetaArray->size[0]] = (real32_T)(-90.0 +
            (real_T)(emlrtDynamicBoundsCheckR2012b(c1_peak2, 1, 180,
            &c1_ug_emlrtBCI, c1_sp) - 1));
          c1_i92 = c1_thetaArray->size[0];
          c1_thetaArray->size[0] = c1_b_thetaArray->size[0];
          c1_st.site = &c1_hl_emlrtRSI;
          c1_emxEnsureCapacity_real32_T(chartInstance, &c1_st, c1_thetaArray,
            c1_i92, &c1_yg_emlrtRTEI);
          c1_l_loop_ub = c1_b_thetaArray->size[0] - 1;
          for (c1_i93 = 0; c1_i93 <= c1_l_loop_ub; c1_i93++) {
            c1_thetaArray->data[c1_i93] = c1_b_thetaArray->data[c1_i93];
          }

          c1_i94 = c1_b_rhoArray->size[0];
          c1_b_rhoArray->size[0] = c1_rhoArray->size[0] + 1;
          c1_st.site = &c1_gl_emlrtRSI;
          c1_emxEnsureCapacity_real32_T(chartInstance, &c1_st, c1_b_rhoArray,
            c1_i94, &c1_ah_emlrtRTEI);
          c1_m_loop_ub = c1_rhoArray->size[0] - 1;
          for (c1_i95 = 0; c1_i95 <= c1_m_loop_ub; c1_i95++) {
            c1_b_rhoArray->data[c1_i95] = c1_rhoArray->data[c1_i95];
          }

          c1_b_rhoArray->data[c1_rhoArray->size[0]] = (real32_T)c1_b_dv[c1_peak1
            - 1];
          c1_i96 = c1_rhoArray->size[0];
          c1_rhoArray->size[0] = c1_b_rhoArray->size[0];
          c1_st.site = &c1_gl_emlrtRSI;
          c1_emxEnsureCapacity_real32_T(chartInstance, &c1_st, c1_rhoArray,
            c1_i96, &c1_bh_emlrtRTEI);
          c1_n_loop_ub = c1_b_rhoArray->size[0] - 1;
          for (c1_i97 = 0; c1_i97 <= c1_n_loop_ub; c1_i97++) {
            c1_rhoArray->data[c1_i97] = c1_b_rhoArray->data[c1_i97];
          }
        }
      }
    }

    c1_peakIdx++;
  }

  c1_emxFree_real32_T(chartInstance, &c1_b_rhoArray);
  c1_emxFree_real32_T(chartInstance, &c1_b_thetaArray);
  c1_emxFree_int32_T(chartInstance, &c1_b_point2Array);
  c1_emxFree_int32_T(chartInstance, &c1_b_point1Array);
  c1_emxFree_int32_T(chartInstance, &c1_r);
  c1_emxFree_real_T(chartInstance, &c1_distances2);
  c1_emxFree_int32_T(chartInstance, &c1_houghPix);
  c1_emxFree_real_T(chartInstance, &c1_peaks);
  c1_emxFree_real_T(chartInstance, &c1_indices);
  c1_st.site = &c1_lk_emlrtRSI;
  c1_b_numLines = c1_numLines;
  c1_b_st.site = &c1_xk_emlrtRSI;
  c1_c_numLines = c1_b_numLines;
  c1_c_st.site = &c1_al_emlrtRSI;
  c1_b_repmat(chartInstance, &c1_c_st, c1_c_numLines, c1_lines);
  c1_b_st.site = &c1_yk_emlrtRSI;
  c1_b = c1_b_numLines;
  c1_b_b = c1_b;
  if (1 > c1_b_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  for (c1_b_k = 1; c1_b_k - 1 < c1_b_numLines; c1_b_k++) {
    c1_d_k = c1_b_k;
    c1_i11 = c1_point1Array->size[0];
    c1_f_k = emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i11, &c1_of_emlrtBCI,
      &c1_st) - 1;
    c1_b_lines = c1_lines->size[1];
    for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
      c1_lines->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_b_lines,
        &c1_dg_emlrtBCI, &c1_st) - 1].point1[c1_i13] = (real_T)
        c1_point1Array->data[c1_f_k + c1_point1Array->size[0] * c1_i13];
    }

    c1_i16 = c1_point2Array->size[0];
    c1_h_k = emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i16, &c1_pf_emlrtBCI,
      &c1_st) - 1;
    c1_c_lines = c1_lines->size[1];
    for (c1_i19 = 0; c1_i19 < 2; c1_i19++) {
      c1_lines->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_c_lines,
        &c1_eg_emlrtBCI, &c1_st) - 1].point2[c1_i19] = (real_T)
        c1_point2Array->data[c1_h_k + c1_point2Array->size[0] * c1_i19];
    }

    c1_i21 = c1_thetaArray->size[0];
    c1_i22 = c1_lines->size[1];
    c1_lines->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i22,
      &c1_gg_emlrtBCI, &c1_st) - 1].theta = c1_thetaArray->
      data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i21, &c1_fg_emlrtBCI,
      &c1_st) - 1];
    c1_i25 = c1_rhoArray->size[0];
    c1_i26 = c1_lines->size[1];
    c1_lines->data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i26,
      &c1_ig_emlrtBCI, &c1_st) - 1].rho = c1_rhoArray->
      data[emlrtDynamicBoundsCheckR2012b(c1_d_k, 1, c1_i25, &c1_hg_emlrtBCI,
      &c1_st) - 1];
  }

  c1_emxFree_real32_T(chartInstance, &c1_rhoArray);
  c1_emxFree_real32_T(chartInstance, &c1_thetaArray);
  c1_emxFree_int32_T(chartInstance, &c1_point2Array);
  c1_emxFree_int32_T(chartInstance, &c1_point1Array);
}

static void c1_c_validateattributes(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_g_a)
{
  static char_T c1_b_cv[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c1_b_cv2[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c1_b_cv1[22] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '4', ',', ' ', 'P', 'E', 'A', 'K', 'S', ',' };

  static char_T c1_b_cv3[22] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '4', ',', ' ', 'P', 'E', 'A', 'K', 'S', ',' };

  c1_emxArray_real_T *c1_h_a;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_b_k;
  real_T c1_c_x;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d_k;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  int32_T c1_c_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_k;
  int32_T c1_loop_ub;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  boolean_T c1_b_b;
  boolean_T c1_b_p;
  boolean_T c1_c_b;
  boolean_T c1_c_p;
  boolean_T c1_d_b;
  boolean_T c1_d_p;
  boolean_T c1_e_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_emxInit_real_T(chartInstance, c1_sp, &c1_h_a, 2, &c1_kh_emlrtRTEI);
  c1_st.site = &c1_s_emlrtRSI;
  c1_i = c1_h_a->size[0] * c1_h_a->size[1];
  c1_h_a->size[0] = c1_g_a->size[0];
  c1_h_a->size[1] = c1_g_a->size[1];
  c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_h_a, c1_i,
    &c1_kh_emlrtRTEI);
  c1_loop_ub = c1_g_a->size[0] * c1_g_a->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_h_a->data[c1_i1] = c1_g_a->data[c1_i1];
  }

  c1_p = true;
  c1_d = (real_T)(c1_h_a->size[0] * c1_h_a->size[1]);
  c1_i2 = (int32_T)c1_d - 1;
  c1_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k <= c1_i2)) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_c_x = c1_h_a->data[(int32_T)c1_b_k - 1];
    c1_b_p = !(c1_c_x <= 0.0);
    if (c1_b_p) {
      c1_k++;
    } else {
      c1_p = false;
      c1_exitg1 = true;
    }
  }

  c1_emxFree_real_T(chartInstance, &c1_h_a);
  if (c1_p) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv6, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv1, 10, 0U, 1U, 0U, 2, 1, 22),
                  false);
    sf_mex_call(&c1_st, &c1_y_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  c1_st.site = &c1_s_emlrtRSI;
  c1_c_p = true;
  c1_d1 = (real_T)(c1_g_a->size[0] * c1_g_a->size[1]);
  c1_i3 = (int32_T)c1_d1 - 1;
  c1_c_k = 0;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_c_k <= c1_i3)) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_d_x = c1_g_a->data[(int32_T)c1_d_k - 1];
    c1_e_x = c1_d_x;
    c1_f_x = c1_e_x;
    c1_b_b = muDoubleScalarIsInf(c1_f_x);
    c1_b2 = !c1_b_b;
    c1_g_x = c1_e_x;
    c1_c_b = muDoubleScalarIsNaN(c1_g_x);
    c1_b3 = !c1_c_b;
    c1_d_b = (c1_b2 && c1_b3);
    if (c1_d_b) {
      c1_h_x = c1_d_x;
      c1_i_x = c1_h_x;
      c1_i_x = muDoubleScalarFloor(c1_i_x);
      if (c1_i_x == c1_d_x) {
        c1_d_p = true;
      } else {
        c1_d_p = false;
      }
    } else {
      c1_d_p = false;
    }

    c1_e_p = c1_d_p;
    if (c1_e_p) {
      c1_c_k++;
    } else {
      c1_c_p = false;
      c1_exitg1 = true;
    }
  }

  if (c1_c_p) {
    c1_b1 = true;
  } else {
    c1_b1 = false;
  }

  if (!c1_b1) {
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv2, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c1_e_y = NULL;
    sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_cv9, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c1_f_y = NULL;
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_b_cv3, 10, 0U, 1U, 0U, 2, 1, 22),
                  false);
    sf_mex_call(&c1_st, &c1_db_emlrtMCI, "error", 0U, 2U, 14, c1_d_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 2U, 14, c1_e_y, 14, c1_f_y)));
  }
}

static void c1_sortrows(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_y, real_T c1_d_varargin_1[2],
  c1_emxArray_int32_T *c1_b_y)
{
  real_T c1_e_varargin_1[2];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_loop_ub;
  c1_i = c1_b_y->size[0] * c1_b_y->size[1];
  c1_b_y->size[0] = c1_y->size[0];
  c1_b_y->size[1] = 2;
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_b_y, c1_i,
    &c1_lh_emlrtRTEI);
  c1_loop_ub = c1_y->size[0] * c1_y->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_b_y->data[c1_i1] = c1_y->data[c1_i1];
  }

  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_e_varargin_1[c1_i2] = c1_d_varargin_1[c1_i2];
  }

  c1_b_sortrows(chartInstance, c1_sp, c1_b_y, c1_e_varargin_1);
}

static void c1_b_mergesort(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_int32_T
  *c1_c_x, int32_T c1_dir[2], int32_T c1_n, c1_emxArray_int32_T *c1_c_idx)
{
  c1_emxArray_int32_T *c1_d_x;
  int32_T c1_b_dir[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_loop_ub;
  c1_i = c1_c_idx->size[0];
  c1_c_idx->size[0] = c1_b_idx->size[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_c_idx, c1_i,
    &c1_mh_emlrtRTEI);
  c1_loop_ub = c1_b_idx->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_c_idx->data[c1_i1] = c1_b_idx->data[c1_i1];
  }

  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_d_x, 2, &c1_mh_emlrtRTEI);
  c1_i2 = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = c1_c_x->size[0];
  c1_d_x->size[1] = 2;
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_d_x, c1_i2,
    &c1_mh_emlrtRTEI);
  c1_b_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_d_x->data[c1_i3] = c1_c_x->data[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    c1_b_dir[c1_i4] = c1_dir[c1_i4];
  }

  c1_d_mergesort(chartInstance, c1_sp, c1_c_idx, c1_d_x, c1_b_dir, c1_n);
  c1_emxFree_int32_T(chartInstance, &c1_d_x);
}

static boolean_T c1_sortLE(SFc1_flightControlSystemInstanceStruct *chartInstance,
  c1_emxArray_int32_T *c1_v, int32_T c1_dir[2], int32_T c1_idx1, int32_T c1_idx2)
{
  int32_T c1_abscolk;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_c_x;
  int32_T c1_colk;
  int32_T c1_d_x;
  int32_T c1_e_x;
  int32_T c1_g_a;
  int32_T c1_h_a;
  int32_T c1_irow1;
  int32_T c1_irow2;
  int32_T c1_k;
  int32_T c1_v1;
  int32_T c1_v2;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  boolean_T c1_v1eqv2;
  (void)chartInstance;
  c1_irow1 = c1_idx1 - 1;
  c1_irow2 = c1_idx2 - 1;
  c1_p = true;
  c1_k = 1;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_k - 1 < 2)) {
    c1_b_k = c1_k - 1;
    c1_colk = c1_dir[c1_b_k];
    c1_c_x = c1_colk;
    c1_d_x = c1_c_x;
    c1_e_x = c1_d_x;
    c1_abscolk = c1_e_x - 1;
    c1_v1 = c1_v->data[c1_irow1 + c1_v->size[0] * c1_abscolk];
    c1_v2 = c1_v->data[c1_irow2 + c1_v->size[0] * c1_abscolk];
    c1_v1eqv2 = (c1_v1 == c1_v2);
    if (c1_v1eqv2) {
      c1_k++;
    } else {
      c1_g_a = c1_v1;
      c1_b = c1_v2;
      c1_h_a = c1_g_a;
      c1_b_b = c1_b;
      c1_p = (c1_h_a <= c1_b_b);
      c1_exitg1 = true;
    }
  }

  return c1_p;
}

static void c1_apply_row_permutation(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_y,
  c1_emxArray_int32_T *c1_b_idx, c1_emxArray_int32_T *c1_b_y)
{
  c1_emxArray_int32_T *c1_c_idx;
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_loop_ub;
  c1_i = c1_b_y->size[0] * c1_b_y->size[1];
  c1_b_y->size[0] = c1_y->size[0];
  c1_b_y->size[1] = 2;
  c1_emxEnsureCapacity_int32_T1(chartInstance, c1_sp, c1_b_y, c1_i,
    &c1_nh_emlrtRTEI);
  c1_loop_ub = c1_y->size[0] * c1_y->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_b_y->data[c1_i1] = c1_y->data[c1_i1];
  }

  c1_emxInit_int32_T(chartInstance, c1_sp, &c1_c_idx, 1, &c1_nh_emlrtRTEI);
  c1_i2 = c1_c_idx->size[0];
  c1_c_idx->size[0] = c1_b_idx->size[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_c_idx, c1_i2,
    &c1_nh_emlrtRTEI);
  c1_b_loop_ub = c1_b_idx->size[0] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    c1_c_idx->data[c1_i3] = c1_b_idx->data[c1_i3];
  }

  c1_b_apply_row_permutation(chartInstance, c1_sp, c1_b_y, c1_c_idx);
  c1_emxFree_int32_T(chartInstance, &c1_c_idx);
}

static int32_T c1_b_power(SFc1_flightControlSystemInstanceStruct *chartInstance,
  int32_T c1_g_a)
{
  int32_T c1_bu;
  int32_T c1_c_x;
  int32_T c1_exitg1;
  int32_T c1_h_a;
  int32_T c1_i_a;
  int32_T c1_y;
  (void)chartInstance;
  c1_h_a = c1_g_a;
  c1_c_x = c1_h_a;
  c1_i_a = c1_c_x;
  c1_y = 1;
  c1_bu = 2;
  do {
    c1_exitg1 = 0;
    if ((c1_bu & 1) != 0) {
      c1_y *= c1_i_a;
    }

    c1_bu >>= 1;
    if (c1_bu == 0) {
      c1_exitg1 = 1;
    } else {
      c1_i_a *= c1_i_a;
    }
  } while (c1_exitg1 == 0);

  return c1_y;
}

static void c1_b_repmat(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, int32_T c1_b_varargin_2,
  c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *c1_b)
{
  c1_emxArray_boolean_T *c1_tile;
  c1_skoeQIuVNKJRHNtBIlOCZhD c1_b_s;
  emlrtStack c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_d;
  real_T c1_d1;
  int32_T c1_outsize[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_loop_ub;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_emxInit_boolean_T(chartInstance, c1_sp, &c1_tile, 2, &c1_vf_emlrtRTEI);
  c1_st.site = &c1_yh_emlrtRSI;
  c1_i = c1_tile->size[0] * c1_tile->size[1];
  c1_tile->size[0] = 1;
  c1_d = (real_T)c1_b_varargin_2;
  c1_tile->size[1] = (int32_T)emlrtNonNegativeCheckR2012b(c1_d, &c1_n_emlrtDCI,
    c1_sp);
  c1_st.site = &c1_rl_emlrtRSI;
  c1_emxEnsureCapacity_boolean_T(chartInstance, &c1_st, c1_tile, c1_i,
    &c1_vf_emlrtRTEI);
  c1_d1 = (real_T)c1_b_varargin_2;
  c1_loop_ub = (int32_T)emlrtNonNegativeCheckR2012b(c1_d1, &c1_o_emlrtDCI, c1_sp)
    - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_tile->data[c1_i1] = false;
  }

  c1_outsize[1] = c1_tile->size[1];
  if (!((real_T)c1_outsize[1] == (real_T)c1_tile->size[1])) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv5, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c1_sp, &c1_o_emlrtMCI, "error", 0U, 1U, 14, c1_y);
  }

  c1_emxFree_boolean_T(chartInstance, &c1_tile);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_b_s.point1[c1_i2] = 0.0;
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_b_s.point2[c1_i3] = 0.0;
  }

  c1_b_s.theta = 0.0;
  c1_b_s.rho = 0.0;
  c1_i4 = c1_b->size[0] * c1_b->size[1];
  c1_b->size[0] = 1;
  c1_b->size[1] = c1_outsize[1];
  c1_st.site = &c1_im_emlrtRSI;
  c1_emxEnsureCapacity_skoeQIuVNKJRH(chartInstance, &c1_st, c1_b, c1_i4,
    &c1_wf_emlrtRTEI);
  c1_b_loop_ub = c1_outsize[1] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_b_loop_ub; c1_i5++) {
    c1_b->data[c1_i5] = c1_b_s;
  }
}

static const mxArray *c1_emlrt_marshallOut
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const char_T c1_c_u[30])
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_c_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  return c1_y;
}

static real_T c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_angelina, const char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_angelina),
    &c1_thisId);
  sf_mex_destroy(&c1_b_angelina);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_d;
  real_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_c_u), &c1_d, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d;
  sf_mex_destroy(&c1_c_u);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_flightControlSystem, const
  char_T *c1_identifier)
{
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_flightControlSystem), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_flightControlSystem);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_c_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_d_u;
  uint8_T c1_y;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_c_u), &c1_d_u, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_d_u;
  sf_mex_destroy(&c1_c_u);
  return c1_y;
}

static const mxArray *c1_chart_data_browse_helper
  (SFc1_flightControlSystemInstanceStruct *chartInstance, int32_T c1_ssIdNumber)
{
  const mxArray *c1_mxData = NULL;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d5;
  c1_mxData = NULL;
  switch (c1_ssIdNumber) {
   case 4U:
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", *chartInstance->c1_b_u, 0,
      0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 12U:
    c1_d = *chartInstance->c1_data;
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", &c1_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    c1_d1 = *chartInstance->c1_output_angle;
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", &c1_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 13U:
    c1_d2 = *chartInstance->c1_mode;
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", &c1_d2, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 9U:
    c1_d3 = *chartInstance->c1_data1;
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", &c1_d3, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 10U:
    c1_d4 = *chartInstance->c1_angle_;
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", &c1_d4, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 11U:
    c1_d5 = *chartInstance->c1_angelina;
    sf_mex_assign(&c1_mxData, sf_mex_create("mxData", &c1_d5, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }

  return c1_mxData;
}

static const mxArray *c1_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1)
{
  const mxArray *c1_ = NULL;
  (void)chartInstance;
  c1_ = NULL;
  sf_mex_assign(&c1_, sf_mex_call(c1_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c1_input0), 14, sf_mex_dup(c1_input1)), false);
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
  return c1_;
}

static void c1_b_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1)
{
  (void)chartInstance;
  sf_mex_call(c1_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c1_input0), 14,
              sf_mex_dup(c1_input1));
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
}

static const mxArray *c1_c_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1, const mxArray *c1_input2)
{
  const mxArray *c1_ = NULL;
  (void)chartInstance;
  c1_ = NULL;
  sf_mex_assign(&c1_, sf_mex_call(c1_sp, NULL, "feval", 1U, 3U, 14, sf_mex_dup
    (c1_input0), 14, sf_mex_dup(c1_input1), 14, sf_mex_dup(c1_input2)), false);
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
  sf_mex_destroy(&c1_input2);
  return c1_;
}

static void c1_d_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1)
{
  (void)chartInstance;
  sf_mex_call(c1_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c1_input0), 14,
              sf_mex_dup(c1_input1));
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
}

static const mxArray *c1_e_feval(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, const mxArray *c1_input0, const
  mxArray *c1_input1)
{
  const mxArray *c1_ = NULL;
  (void)chartInstance;
  c1_ = NULL;
  sf_mex_assign(&c1_, sf_mex_call(c1_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c1_input0), 14, sf_mex_dup(c1_input1)), false);
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
  return c1_;
}

static void c1_f_feval(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, const mxArray *c1_input0, const mxArray *c1_input1)
{
  (void)chartInstance;
  sf_mex_call(c1_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c1_input0), 14,
              sf_mex_dup(c1_input1));
  sf_mex_destroy(&c1_input0);
  sf_mex_destroy(&c1_input1);
}

static void c1_b_bwmorphApplyOnce(SFc1_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c1_bw[19200])
{
  int32_T c1_i;
  boolean_T c1_b_bw[19200];
  boolean_T c1_image_iter1[19200];
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_b_bw[c1_i] = c1_bw[c1_i];
  }

  c1_bwlookup(chartInstance, c1_b_bw, c1_image_iter1);
  c1_b_bwlookup(chartInstance, c1_image_iter1, c1_bw);
}

static void c1_c_mergesort(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, int32_T c1_b_idx[19200], real32_T c1_c_x[19200])
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b_idx1;
  int32_T c1_b_idx2;
  int32_T c1_b_k;
  int32_T c1_b_p;
  int32_T c1_c_k;
  int32_T c1_e_b;
  int32_T c1_f_b;
  int32_T c1_h_a;
  int32_T c1_i;
  int32_T c1_i2;
  int32_T c1_idx1;
  int32_T c1_idx2;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_kEnd;
  int32_T c1_pEnd;
  int32_T c1_q;
  int32_T c1_qEnd;
  real32_T c1_b;
  real32_T c1_b_b;
  real32_T c1_c_b;
  real32_T c1_d_x;
  real32_T c1_e_x;
  real32_T c1_g_a;
  real32_T c1_g_b;
  real32_T c1_h_b;
  real32_T c1_i_a;
  real32_T c1_i_b;
  real32_T c1_j_a;
  real32_T c1_k_a;
  real32_T c1_l_a;
  real32_T c1_m_a;
  boolean_T c1_c_p;
  boolean_T c1_d_b;
  boolean_T c1_d_p;
  boolean_T c1_e_p;
  boolean_T c1_f_p;
  boolean_T c1_g_p;
  boolean_T c1_j_b;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_k = 0; c1_k <= 19199; c1_k += 2) {
    c1_idx1 = c1_k;
    c1_idx2 = c1_k;
    c1_g_a = c1_c_x[c1_idx1];
    c1_b = c1_c_x[c1_idx2 + 1];
    c1_i_a = c1_g_a;
    c1_b_b = c1_b;
    c1_j_a = c1_i_a;
    c1_c_b = c1_b_b;
    c1_p = (c1_j_a <= c1_c_b);
    if (c1_p) {
      c1_c_p = true;
    } else {
      c1_d_x = c1_b_b;
      c1_d_b = muSingleScalarIsNaN(c1_d_x);
      if (c1_d_b) {
        c1_c_p = true;
      } else {
        c1_c_p = false;
      }
    }

    c1_d_p = c1_c_p;
    if (c1_d_p) {
      c1_b_idx[c1_k] = c1_k + 1;
      c1_b_idx[c1_k + 1] = c1_k + 2;
    } else {
      c1_b_idx[c1_k] = c1_k + 2;
      c1_b_idx[c1_k + 1] = c1_k + 1;
    }
  }

  c1_i = 2;
  while (c1_i < 19200) {
    c1_h_a = c1_i;
    c1_i2 = c1_h_a << 1;
    c1_j = 1;
    for (c1_pEnd = 1 + c1_i; c1_pEnd < 19201; c1_pEnd = c1_qEnd + c1_i) {
      c1_b_p = c1_j - 1;
      c1_q = c1_pEnd - 1;
      c1_qEnd = c1_j + c1_i2;
      if (c1_qEnd > 19201) {
        c1_qEnd = 19201;
      }

      c1_b_k = 0;
      c1_kEnd = c1_qEnd - c1_j;
      while (c1_b_k + 1 <= c1_kEnd) {
        c1_b_idx1 = c1_b_idx[c1_b_p] - 1;
        c1_b_idx2 = c1_b_idx[c1_q] - 1;
        c1_k_a = c1_c_x[c1_b_idx1];
        c1_g_b = c1_c_x[c1_b_idx2];
        c1_l_a = c1_k_a;
        c1_h_b = c1_g_b;
        c1_m_a = c1_l_a;
        c1_i_b = c1_h_b;
        c1_e_p = (c1_m_a <= c1_i_b);
        if (c1_e_p) {
          c1_f_p = true;
        } else {
          c1_e_x = c1_h_b;
          c1_j_b = muSingleScalarIsNaN(c1_e_x);
          if (c1_j_b) {
            c1_f_p = true;
          } else {
            c1_f_p = false;
          }
        }

        c1_g_p = c1_f_p;
        if (c1_g_p) {
          chartInstance->c1_iwork[c1_b_k] = c1_b_idx[c1_b_p];
          c1_b_p++;
          if (c1_b_p + 1 == c1_pEnd) {
            while (c1_q + 1 < c1_qEnd) {
              c1_b_k++;
              chartInstance->c1_iwork[c1_b_k] = c1_b_idx[c1_q];
              c1_q++;
            }
          }
        } else {
          chartInstance->c1_iwork[c1_b_k] = c1_b_idx[c1_q];
          c1_q++;
          if (c1_q + 1 == c1_qEnd) {
            while (c1_b_p + 1 < c1_pEnd) {
              c1_b_k++;
              chartInstance->c1_iwork[c1_b_k] = c1_b_idx[c1_b_p];
              c1_b_p++;
            }
          }
        }

        c1_b_k++;
      }

      c1_b_p = c1_j - 2;
      c1_st.site = &c1_ud_emlrtRSI;
      c1_e_b = c1_kEnd;
      c1_f_b = c1_e_b;
      if (1 > c1_f_b) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_f_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
      }

      for (c1_c_k = 1; c1_c_k - 1 < c1_kEnd; c1_c_k++) {
        c1_b_k = c1_c_k;
        c1_b_idx[c1_b_p + c1_b_k] = chartInstance->c1_iwork[c1_b_k - 1];
      }

      c1_j = c1_qEnd;
    }

    c1_i = c1_i2;
  }
}

static void c1_b_nullAssignment(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T *c1_c_x,
  boolean_T c1_idx_data[], int32_T c1_idx_size[2])
{
  c1_emxArray_real32_T *c1_d_x;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_b_n;
  int32_T c1_c_b;
  int32_T c1_c_k;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_e_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_k;
  int32_T c1_k0;
  int32_T c1_loop_ub;
  int32_T c1_n;
  int32_T c1_nb;
  int32_T c1_nxin;
  int32_T c1_nxout;
  boolean_T c1_b_overflow;
  boolean_T c1_e_b;
  boolean_T c1_overflow;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_emxInit_real32_T1(chartInstance, c1_sp, &c1_d_x, 2, &c1_oh_emlrtRTEI);
  c1_st.site = &c1_ke_emlrtRSI;
  c1_i = c1_d_x->size[0] * c1_d_x->size[1];
  c1_d_x->size[0] = 1;
  c1_d_x->size[1] = c1_c_x->size[1];
  c1_b_st.site = &c1_ke_emlrtRSI;
  c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_b_st, c1_d_x, c1_i,
    &c1_oh_emlrtRTEI);
  c1_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_d_x->data[c1_i1] = c1_c_x->data[c1_i1];
  }

  c1_n = c1_d_x->size[1];
  c1_k = c1_idx_size[1];
  c1_emxFree_real32_T(chartInstance, &c1_d_x);
  while ((c1_k >= 1) && (!c1_idx_data[c1_k - 1])) {
    c1_k--;
  }

  c1_p = (c1_k <= c1_n);
  if (!c1_p) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv3, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call(&c1_st, &c1_g_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_b_y)));
  }

  c1_st.site = &c1_le_emlrtRSI;
  c1_nxin = c1_c_x->size[1];
  c1_b_st.site = &c1_me_emlrtRSI;
  c1_b_n = 0;
  c1_i2 = c1_idx_size[1];
  c1_c_st.site = &c1_oe_emlrtRSI;
  c1_b = c1_i2;
  c1_b_b = c1_b;
  if (1 > c1_b_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_d_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
  }

  for (c1_b_k = 1; c1_b_k - 1 < c1_i2; c1_b_k++) {
    c1_c_k = c1_b_k - 1;
    c1_b_n += (int32_T)c1_idx_data[c1_c_k];
  }

  c1_nxout = c1_nxin - c1_b_n;
  c1_nb = c1_idx_size[1];
  c1_k0 = -1;
  c1_b_st.site = &c1_ne_emlrtRSI;
  c1_c_b = c1_nxin;
  c1_d_b = c1_c_b;
  if (1 > c1_d_b) {
    c1_b_overflow = false;
  } else {
    c1_b_overflow = (c1_d_b > 2147483646);
  }

  if (c1_b_overflow) {
    c1_c_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  for (c1_d_k = 1; c1_d_k - 1 < c1_nxin; c1_d_k++) {
    c1_e_k = c1_d_k - 1;
    if ((c1_e_k + 1 > c1_nb) || (!c1_idx_data[c1_e_k])) {
      c1_k0++;
      c1_c_x->data[c1_k0] = c1_c_x->data[c1_e_k];
    }
  }

  if (!(c1_nxout <= c1_nxin)) {
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c1_st, &c1_h_emlrtMCI, "error", 0U, 2U, 14, c1_c_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_d_y)));
  }

  c1_e_b = (1 > c1_nxout);
  if (c1_e_b) {
    c1_i3 = 0;
  } else {
    c1_i3 = c1_nxout;
  }

  c1_i4 = c1_c_x->size[0] * c1_c_x->size[1];
  c1_c_x->size[1] = c1_i3;
  c1_emxEnsureCapacity_real32_T1(chartInstance, &c1_st, c1_c_x, c1_i4,
    &c1_ph_emlrtRTEI);
}

static void c1_c_sort(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_emxArray_real32_T *c1_c_x)
{
  c1_emxArray_int32_T *c1_b_idx;
  c1_emxArray_int32_T *c1_b_iwork;
  c1_emxArray_real32_T *c1_xwork;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  real_T c1_b_dv[2];
  int32_T c1_idx4[4];
  int32_T c1_perm[4];
  int32_T c1_iv[1];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_i1;
  int32_T c1_b_i2;
  int32_T c1_b_i3;
  int32_T c1_b_i4;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_b_n;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_n;
  int32_T c1_d_b;
  int32_T c1_d_k;
  int32_T c1_e_b;
  int32_T c1_f_b;
  int32_T c1_g_b;
  int32_T c1_h_b;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_b;
  int32_T c1_ib;
  int32_T c1_itmp;
  int32_T c1_j_b;
  int32_T c1_k;
  int32_T c1_k_b;
  int32_T c1_loop_ub;
  int32_T c1_m;
  int32_T c1_n;
  int32_T c1_nBlocks;
  int32_T c1_nLastBlock;
  int32_T c1_nNaNs;
  int32_T c1_nNonNaN;
  int32_T c1_preSortLevel;
  int32_T c1_quartetOffset;
  int32_T c1_tailOffset;
  int32_T c1_wOffset;
  real32_T c1_x4[4];
  real32_T c1_d_x;
  boolean_T c1_b_overflow;
  boolean_T c1_c_b;
  boolean_T c1_c_overflow;
  boolean_T c1_d_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_b_idx, 2, &c1_xh_emlrtRTEI);
  c1_st.site = &c1_xe_emlrtRSI;
  c1_i = c1_b_idx->size[0] * c1_b_idx->size[1];
  c1_b_idx->size[0] = 1;
  c1_b_idx->size[1] = c1_c_x->size[1];
  c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_b_idx, c1_i,
    &c1_qh_emlrtRTEI);
  c1_loop_ub = c1_c_x->size[1] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_b_idx->data[c1_i1] = 0;
  }

  c1_b_st.site = &c1_ye_emlrtRSI;
  c1_n = c1_c_x->size[1];
  c1_c_st.site = &c1_af_emlrtRSI;
  c1_b_n = c1_c_x->size[1];
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    c1_x4[c1_i2] = 0.0F;
  }

  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    c1_idx4[c1_i3] = 0;
  }

  c1_emxInit_int32_T(chartInstance, &c1_c_st, &c1_b_iwork, 1, &c1_sh_emlrtRTEI);
  c1_i4 = c1_b_iwork->size[0];
  c1_b_iwork->size[0] = c1_b_idx->size[1];
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_iwork, c1_i4,
    &c1_rh_emlrtRTEI);
  c1_iv[0] = c1_b_iwork->size[0];
  c1_i5 = c1_b_iwork->size[0];
  c1_b_iwork->size[0] = c1_iv[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_iwork, c1_i5,
    &c1_sh_emlrtRTEI);
  c1_i6 = c1_b_iwork->size[0];
  c1_i7 = c1_b_iwork->size[0];
  c1_b_iwork->size[0] = c1_i6;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_iwork, c1_i7,
    &c1_th_emlrtRTEI);
  c1_b_loop_ub = c1_i6 - 1;
  for (c1_i8 = 0; c1_i8 <= c1_b_loop_ub; c1_i8++) {
    c1_b_iwork->data[c1_i8] = 0;
  }

  c1_emxInit_real32_T(chartInstance, &c1_c_st, &c1_xwork, 1, &c1_vh_emlrtRTEI);
  c1_b_dv[0] = (real_T)c1_c_x->size[1];
  c1_i9 = c1_xwork->size[0];
  c1_xwork->size[0] = (int32_T)c1_b_dv[0];
  c1_emxEnsureCapacity_real32_T(chartInstance, &c1_c_st, c1_xwork, c1_i9,
    &c1_uh_emlrtRTEI);
  c1_iv[0] = c1_xwork->size[0];
  c1_i10 = c1_xwork->size[0];
  c1_xwork->size[0] = c1_iv[0];
  c1_emxEnsureCapacity_real32_T(chartInstance, &c1_c_st, c1_xwork, c1_i10,
    &c1_vh_emlrtRTEI);
  c1_i11 = c1_xwork->size[0];
  c1_i12 = c1_xwork->size[0];
  c1_xwork->size[0] = c1_i11;
  c1_emxEnsureCapacity_real32_T(chartInstance, &c1_c_st, c1_xwork, c1_i12,
    &c1_wh_emlrtRTEI);
  c1_c_loop_ub = c1_i11 - 1;
  for (c1_i13 = 0; c1_i13 <= c1_c_loop_ub; c1_i13++) {
    c1_xwork->data[c1_i13] = 0.0F;
  }

  c1_nNaNs = 0;
  c1_ib = 0;
  c1_d_st.site = &c1_ff_emlrtRSI;
  c1_b = c1_b_n;
  c1_b_b = c1_b;
  if (1 > c1_b_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_e_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
  }

  for (c1_k = 1; c1_k - 1 < c1_b_n; c1_k++) {
    c1_b_k = c1_k - 1;
    c1_d_x = c1_c_x->data[c1_b_k];
    c1_c_b = muSingleScalarIsNaN(c1_d_x);
    if (c1_c_b) {
      c1_b_idx->data[(c1_b_n - c1_nNaNs) - 1] = c1_b_k + 1;
      c1_xwork->data[(c1_b_n - c1_nNaNs) - 1] = c1_c_x->data[c1_b_k];
      c1_nNaNs++;
    } else {
      c1_ib++;
      c1_idx4[c1_ib - 1] = c1_b_k + 1;
      c1_x4[c1_ib - 1] = c1_c_x->data[c1_b_k];
      if (c1_ib == 4) {
        c1_quartetOffset = c1_b_k - c1_nNaNs;
        if (c1_x4[0] <= c1_x4[1]) {
          c1_b_i1 = 1;
          c1_b_i2 = 2;
        } else {
          c1_b_i1 = 2;
          c1_b_i2 = 1;
        }

        if (c1_x4[2] <= c1_x4[3]) {
          c1_b_i3 = 3;
          c1_b_i4 = 4;
        } else {
          c1_b_i3 = 4;
          c1_b_i4 = 3;
        }

        if (c1_x4[c1_b_i1 - 1] <= c1_x4[c1_b_i3 - 1]) {
          if (c1_x4[c1_b_i2 - 1] <= c1_x4[c1_b_i3 - 1]) {
            c1_perm[0] = c1_b_i1;
            c1_perm[1] = c1_b_i2;
            c1_perm[2] = c1_b_i3;
            c1_perm[3] = c1_b_i4;
          } else if (c1_x4[c1_b_i2 - 1] <= c1_x4[c1_b_i4 - 1]) {
            c1_perm[0] = c1_b_i1;
            c1_perm[1] = c1_b_i3;
            c1_perm[2] = c1_b_i2;
            c1_perm[3] = c1_b_i4;
          } else {
            c1_perm[0] = c1_b_i1;
            c1_perm[1] = c1_b_i3;
            c1_perm[2] = c1_b_i4;
            c1_perm[3] = c1_b_i2;
          }
        } else if (c1_x4[c1_b_i1 - 1] <= c1_x4[c1_b_i4 - 1]) {
          if (c1_x4[c1_b_i2 - 1] <= c1_x4[c1_b_i4 - 1]) {
            c1_perm[0] = c1_b_i3;
            c1_perm[1] = c1_b_i1;
            c1_perm[2] = c1_b_i2;
            c1_perm[3] = c1_b_i4;
          } else {
            c1_perm[0] = c1_b_i3;
            c1_perm[1] = c1_b_i1;
            c1_perm[2] = c1_b_i4;
            c1_perm[3] = c1_b_i2;
          }
        } else {
          c1_perm[0] = c1_b_i3;
          c1_perm[1] = c1_b_i4;
          c1_perm[2] = c1_b_i1;
          c1_perm[3] = c1_b_i2;
        }

        c1_b_idx->data[c1_quartetOffset - 3] = c1_idx4[c1_perm[0] - 1];
        c1_b_idx->data[c1_quartetOffset - 2] = c1_idx4[c1_perm[1] - 1];
        c1_b_idx->data[c1_quartetOffset - 1] = c1_idx4[c1_perm[2] - 1];
        c1_b_idx->data[c1_quartetOffset] = c1_idx4[c1_perm[3] - 1];
        c1_c_x->data[c1_quartetOffset - 3] = c1_x4[c1_perm[0] - 1];
        c1_c_x->data[c1_quartetOffset - 2] = c1_x4[c1_perm[1] - 1];
        c1_c_x->data[c1_quartetOffset - 1] = c1_x4[c1_perm[2] - 1];
        c1_c_x->data[c1_quartetOffset] = c1_x4[c1_perm[3] - 1];
        c1_ib = 0;
      }
    }
  }

  c1_wOffset = (c1_b_n - c1_nNaNs) - 1;
  if (c1_ib > 0) {
    c1_c_n = c1_ib;
    for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
      c1_perm[c1_i14] = 0;
    }

    if (c1_c_n == 1) {
      c1_perm[0] = 1;
    } else if (c1_c_n == 2) {
      if (c1_x4[0] <= c1_x4[1]) {
        c1_perm[0] = 1;
        c1_perm[1] = 2;
      } else {
        c1_perm[0] = 2;
        c1_perm[1] = 1;
      }
    } else if (c1_x4[0] <= c1_x4[1]) {
      if (c1_x4[1] <= c1_x4[2]) {
        c1_perm[0] = 1;
        c1_perm[1] = 2;
        c1_perm[2] = 3;
      } else if (c1_x4[0] <= c1_x4[2]) {
        c1_perm[0] = 1;
        c1_perm[1] = 3;
        c1_perm[2] = 2;
      } else {
        c1_perm[0] = 3;
        c1_perm[1] = 1;
        c1_perm[2] = 2;
      }
    } else if (c1_x4[0] <= c1_x4[2]) {
      c1_perm[0] = 2;
      c1_perm[1] = 1;
      c1_perm[2] = 3;
    } else if (c1_x4[1] <= c1_x4[2]) {
      c1_perm[0] = 2;
      c1_perm[1] = 3;
      c1_perm[2] = 1;
    } else {
      c1_perm[0] = 3;
      c1_perm[1] = 2;
      c1_perm[2] = 1;
    }

    c1_d_st.site = &c1_gf_emlrtRSI;
    c1_f_b = c1_ib;
    c1_g_b = c1_f_b;
    if (1 > c1_g_b) {
      c1_c_overflow = false;
    } else {
      c1_c_overflow = (c1_g_b > 2147483646);
    }

    if (c1_c_overflow) {
      c1_e_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
    }

    for (c1_d_k = 1; c1_d_k - 1 < c1_ib; c1_d_k++) {
      c1_b_k = c1_d_k;
      c1_b_idx->data[(c1_wOffset - c1_ib) + c1_b_k] = c1_idx4[c1_perm[c1_b_k - 1]
        - 1];
      c1_c_x->data[(c1_wOffset - c1_ib) + c1_b_k] = c1_x4[c1_perm[c1_b_k - 1] -
        1];
    }
  }

  c1_m = c1_nNaNs >> 1;
  c1_d_st.site = &c1_hf_emlrtRSI;
  c1_d_b = c1_m;
  c1_e_b = c1_d_b;
  if (1 > c1_e_b) {
    c1_b_overflow = false;
  } else {
    c1_b_overflow = (c1_e_b > 2147483646);
  }

  if (c1_b_overflow) {
    c1_e_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
  }

  for (c1_c_k = 1; c1_c_k - 1 < c1_m; c1_c_k++) {
    c1_b_k = c1_c_k;
    c1_itmp = c1_b_idx->data[c1_wOffset + c1_b_k];
    c1_b_idx->data[c1_wOffset + c1_b_k] = c1_b_idx->data[c1_b_n - c1_b_k];
    c1_b_idx->data[c1_b_n - c1_b_k] = c1_itmp;
    c1_c_x->data[c1_wOffset + c1_b_k] = c1_xwork->data[c1_b_n - c1_b_k];
    c1_c_x->data[c1_b_n - c1_b_k] = c1_xwork->data[c1_wOffset + c1_b_k];
  }

  if ((c1_nNaNs & 1) != 0) {
    c1_c_x->data[(c1_wOffset + c1_m) + 1] = c1_xwork->data[(c1_wOffset + c1_m) +
      1];
  }

  c1_nNonNaN = c1_n - c1_nNaNs;
  c1_preSortLevel = 2;
  if (c1_nNonNaN > 1) {
    if (c1_n >= 256) {
      c1_nBlocks = c1_nNonNaN >> 8;
      if (c1_nBlocks > 0) {
        c1_c_st.site = &c1_bf_emlrtRSI;
        c1_h_b = c1_nBlocks;
        c1_i_b = c1_h_b;
        if (1 > c1_i_b) {
          c1_d_overflow = false;
        } else {
          c1_d_overflow = (c1_i_b > 2147483646);
        }

        if (c1_d_overflow) {
          c1_d_st.site = &c1_kb_emlrtRSI;
          c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
        }

        for (c1_j_b = 1; c1_j_b - 1 < c1_nBlocks; c1_j_b++) {
          c1_k_b = c1_j_b - 1;
          c1_c_st.site = &c1_cf_emlrtRSI;
          c1_c_merge_pow2_block(chartInstance, &c1_c_st, c1_b_idx, c1_c_x,
                                c1_k_b << 8);
        }

        c1_tailOffset = c1_nBlocks << 8;
        c1_nLastBlock = c1_nNonNaN - c1_tailOffset;
        if (c1_nLastBlock > 0) {
          c1_c_st.site = &c1_df_emlrtRSI;
          c1_c_merge_block(chartInstance, &c1_c_st, c1_b_idx, c1_c_x,
                           c1_tailOffset, c1_nLastBlock, 2, c1_b_iwork, c1_xwork);
        }

        c1_preSortLevel = 8;
      }
    }

    c1_c_st.site = &c1_ef_emlrtRSI;
    c1_c_merge_block(chartInstance, &c1_c_st, c1_b_idx, c1_c_x, 0, c1_nNonNaN,
                     c1_preSortLevel, c1_b_iwork, c1_xwork);
  }

  c1_emxFree_real32_T(chartInstance, &c1_xwork);
  c1_emxFree_int32_T(chartInstance, &c1_b_iwork);
  c1_emxFree_int32_T(chartInstance, &c1_b_idx);
}

static void c1_c_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real32_T *c1_c_x, int32_T c1_offset)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b_iwork[256];
  int32_T c1_b;
  int32_T c1_bLen;
  int32_T c1_bLen2;
  int32_T c1_b_b;
  int32_T c1_b_j;
  int32_T c1_b_k;
  int32_T c1_blockOffset;
  int32_T c1_c_b;
  int32_T c1_c_j;
  int32_T c1_d_b;
  int32_T c1_e_b;
  int32_T c1_exitg1;
  int32_T c1_f_b;
  int32_T c1_g_a;
  int32_T c1_g_b;
  int32_T c1_h_a;
  int32_T c1_iout;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_nPairs;
  int32_T c1_offset1;
  int32_T c1_p;
  int32_T c1_q;
  real32_T c1_xwork[256];
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_b = 0; c1_b < 6; c1_b++) {
    c1_bLen = 1 << (c1_b + 2);
    c1_bLen2 = c1_bLen << 1;
    c1_nPairs = 256 >> (c1_b + 3);
    c1_st.site = &c1_if_emlrtRSI;
    c1_b_b = c1_nPairs;
    c1_c_b = c1_b_b;
    if (1 > c1_c_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_k = 1; c1_k - 1 < c1_nPairs; c1_k++) {
      c1_b_k = c1_k - 1;
      c1_blockOffset = (c1_offset + c1_b_k * c1_bLen2) - 1;
      c1_st.site = &c1_jf_emlrtRSI;
      c1_d_b = c1_bLen2;
      c1_e_b = c1_d_b;
      if (1 > c1_e_b) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_e_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_b_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
      }

      for (c1_j = 1; c1_j - 1 < c1_bLen2; c1_j++) {
        c1_b_j = c1_j;
        c1_b_iwork[c1_b_j - 1] = c1_b_idx->data[c1_blockOffset + c1_b_j];
        c1_xwork[c1_b_j - 1] = c1_c_x->data[c1_blockOffset + c1_b_j];
      }

      c1_p = 0;
      c1_q = c1_bLen;
      c1_iout = c1_blockOffset;
      do {
        c1_exitg1 = 0;
        c1_iout++;
        if (c1_xwork[c1_p] <= c1_xwork[c1_q]) {
          c1_b_idx->data[c1_iout] = c1_b_iwork[c1_p];
          c1_c_x->data[c1_iout] = c1_xwork[c1_p];
          if (c1_p + 1 < c1_bLen) {
            c1_p++;
          } else {
            c1_exitg1 = 1;
          }
        } else {
          c1_b_idx->data[c1_iout] = c1_b_iwork[c1_q];
          c1_c_x->data[c1_iout] = c1_xwork[c1_q];
          if (c1_q + 1 < c1_bLen2) {
            c1_q++;
          } else {
            c1_offset1 = c1_iout - c1_p;
            c1_st.site = &c1_kf_emlrtRSI;
            c1_g_a = c1_p + 1;
            c1_f_b = c1_bLen;
            c1_h_a = c1_g_a;
            c1_g_b = c1_f_b;
            if (c1_h_a > c1_g_b) {
              c1_c_overflow = false;
            } else {
              c1_c_overflow = (c1_g_b > 2147483646);
            }

            if (c1_c_overflow) {
              c1_b_st.site = &c1_kb_emlrtRSI;
              c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
            }

            for (c1_c_j = c1_p + 1; c1_c_j <= c1_bLen; c1_c_j++) {
              c1_b_idx->data[c1_offset1 + c1_c_j] = c1_b_iwork[c1_c_j - 1];
              c1_c_x->data[c1_offset1 + c1_c_j] = c1_xwork[c1_c_j - 1];
            }

            c1_exitg1 = 1;
          }
        }
      } while (c1_exitg1 == 0);
    }
  }
}

static void c1_c_merge_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real32_T *c1_c_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_emxArray_int32_T *c1_b_iwork, c1_emxArray_real32_T
  *c1_xwork)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b;
  int32_T c1_bLen;
  int32_T c1_bLen2;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_k;
  int32_T c1_nBlocks;
  int32_T c1_nPairs;
  int32_T c1_nTail;
  int32_T c1_tailOffset;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_nBlocks = c1_n >> c1_preSortLevel;
  c1_bLen = 1 << c1_preSortLevel;
  while (c1_nBlocks > 1) {
    if ((c1_nBlocks & 1) != 0) {
      c1_nBlocks--;
      c1_tailOffset = c1_bLen * c1_nBlocks;
      c1_nTail = c1_n - c1_tailOffset;
      if (c1_nTail > c1_bLen) {
        c1_st.site = &c1_lf_emlrtRSI;
        c1_c_merge(chartInstance, &c1_st, c1_b_idx, c1_c_x, c1_offset +
                   c1_tailOffset, c1_bLen, c1_nTail - c1_bLen, c1_b_iwork,
                   c1_xwork);
      }
    }

    c1_bLen2 = c1_bLen << 1;
    c1_nPairs = c1_nBlocks >> 1;
    c1_st.site = &c1_mf_emlrtRSI;
    c1_b = c1_nPairs;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_k = 1; c1_k - 1 < c1_nPairs; c1_k++) {
      c1_b_k = c1_k - 1;
      c1_st.site = &c1_nf_emlrtRSI;
      c1_c_merge(chartInstance, &c1_st, c1_b_idx, c1_c_x, c1_offset + c1_b_k *
                 c1_bLen2, c1_bLen, c1_bLen, c1_b_iwork, c1_xwork);
    }

    c1_bLen = c1_bLen2;
    c1_nBlocks = c1_nPairs;
  }

  if (c1_n > c1_bLen) {
    c1_st.site = &c1_of_emlrtRSI;
    c1_c_merge(chartInstance, &c1_st, c1_b_idx, c1_c_x, c1_offset, c1_bLen, c1_n
               - c1_bLen, c1_b_iwork, c1_xwork);
  }
}

static void c1_c_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_real32_T
  *c1_c_x, int32_T c1_offset, int32_T c1_np, int32_T c1_nq, c1_emxArray_int32_T *
  c1_b_iwork, c1_emxArray_real32_T *c1_xwork)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_j;
  int32_T c1_c_b;
  int32_T c1_c_j;
  int32_T c1_d_b;
  int32_T c1_exitg1;
  int32_T c1_g_a;
  int32_T c1_h_a;
  int32_T c1_iout;
  int32_T c1_j;
  int32_T c1_n;
  int32_T c1_offset1;
  int32_T c1_p;
  int32_T c1_q;
  int32_T c1_qend;
  boolean_T c1_b_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  if (c1_nq != 0) {
    c1_n = c1_np + c1_nq;
    c1_st.site = &c1_qf_emlrtRSI;
    c1_b = c1_n;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_j = 1; c1_j - 1 < c1_n; c1_j++) {
      c1_b_j = c1_j - 1;
      c1_b_iwork->data[c1_b_j] = c1_b_idx->data[c1_offset + c1_b_j];
      c1_xwork->data[c1_b_j] = c1_c_x->data[c1_offset + c1_b_j];
    }

    c1_p = 0;
    c1_q = c1_np;
    c1_qend = c1_np + c1_nq;
    c1_iout = c1_offset - 1;
    do {
      c1_exitg1 = 0;
      c1_iout++;
      if (c1_xwork->data[c1_p] <= c1_xwork->data[c1_q]) {
        c1_b_idx->data[c1_iout] = c1_b_iwork->data[c1_p];
        c1_c_x->data[c1_iout] = c1_xwork->data[c1_p];
        if (c1_p + 1 < c1_np) {
          c1_p++;
        } else {
          c1_exitg1 = 1;
        }
      } else {
        c1_b_idx->data[c1_iout] = c1_b_iwork->data[c1_q];
        c1_c_x->data[c1_iout] = c1_xwork->data[c1_q];
        if (c1_q + 1 < c1_qend) {
          c1_q++;
        } else {
          c1_offset1 = c1_iout - c1_p;
          c1_st.site = &c1_pf_emlrtRSI;
          c1_g_a = c1_p + 1;
          c1_c_b = c1_np;
          c1_h_a = c1_g_a;
          c1_d_b = c1_c_b;
          if (c1_h_a > c1_d_b) {
            c1_b_overflow = false;
          } else {
            c1_b_overflow = (c1_d_b > 2147483646);
          }

          if (c1_b_overflow) {
            c1_b_st.site = &c1_kb_emlrtRSI;
            c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
          }

          for (c1_c_j = c1_p + 1; c1_c_j <= c1_np; c1_c_j++) {
            c1_b_idx->data[c1_offset1 + c1_c_j] = c1_b_iwork->data[c1_c_j - 1];
            c1_c_x->data[c1_offset1 + c1_c_j] = c1_xwork->data[c1_c_j - 1];
          }

          c1_exitg1 = 1;
        }
      }
    } while (c1_exitg1 == 0);
  }
}

static void c1_b_ComputeWeightedCentroid(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, real_T c1_I[19200],
  c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_stats, c1_sHtk0WM4OMtyqkehwQYcq2
  *c1_statsAlreadyComputed)
{
  static char_T c1_b_cv[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  c1_cell_wrap_52 c1_reshapes[2];
  c1_emxArray_int32_T *c1_b_idx;
  c1_emxArray_int32_T *c1_varargout_4;
  c1_emxArray_int32_T *c1_vk;
  c1_emxArray_real_T *c1_Intensity;
  c1_emxArray_real_T *c1_b_Intensity;
  c1_emxArray_real_T *c1_c;
  c1_emxArray_real_T *c1_r;
  c1_emxArray_real_T *c1_r1;
  c1_emxArray_real_T *c1_r2;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_wc[2];
  real_T c1_M;
  real_T c1_b_k;
  real_T c1_b_n;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d_idx;
  real_T c1_d_k;
  real_T c1_f_k;
  real_T c1_sumIntensity;
  int32_T c1_sizes[2];
  int32_T c1_ab_loop_ub;
  int32_T c1_b_loop_ub;
  int32_T c1_b_stats;
  int32_T c1_bb_loop_ub;
  int32_T c1_c_idx;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_n;
  int32_T c1_c_stats;
  int32_T c1_cb_loop_ub;
  int32_T c1_d_loop_ub;
  int32_T c1_d_stats;
  int32_T c1_db_loop_ub;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_e_stats;
  int32_T c1_eb_loop_ub;
  int32_T c1_expected;
  int32_T c1_f_loop_ub;
  int32_T c1_fb_loop_ub;
  int32_T c1_g_loop_ub;
  int32_T c1_gb_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_hb_loop_ub;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  int32_T c1_i104;
  int32_T c1_i105;
  int32_T c1_i106;
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  int32_T c1_i11;
  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  int32_T c1_i114;
  int32_T c1_i115;
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  int32_T c1_i119;
  int32_T c1_i12;
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  int32_T c1_i123;
  int32_T c1_i124;
  int32_T c1_i125;
  int32_T c1_i126;
  int32_T c1_i127;
  int32_T c1_i128;
  int32_T c1_i129;
  int32_T c1_i13;
  int32_T c1_i130;
  int32_T c1_i131;
  int32_T c1_i132;
  int32_T c1_i133;
  int32_T c1_i134;
  int32_T c1_i135;
  int32_T c1_i136;
  int32_T c1_i137;
  int32_T c1_i138;
  int32_T c1_i139;
  int32_T c1_i14;
  int32_T c1_i140;
  int32_T c1_i141;
  int32_T c1_i142;
  int32_T c1_i143;
  int32_T c1_i144;
  int32_T c1_i145;
  int32_T c1_i146;
  int32_T c1_i147;
  int32_T c1_i148;
  int32_T c1_i149;
  int32_T c1_i15;
  int32_T c1_i150;
  int32_T c1_i151;
  int32_T c1_i152;
  int32_T c1_i153;
  int32_T c1_i154;
  int32_T c1_i155;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i9;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i_loop_ub;
  int32_T c1_ib_loop_ub;
  int32_T c1_j_loop_ub;
  int32_T c1_k;
  int32_T c1_k_loop_ub;
  int32_T c1_l_loop_ub;
  int32_T c1_loop_ub;
  int32_T c1_m_loop_ub;
  int32_T c1_n;
  int32_T c1_n_loop_ub;
  int32_T c1_o_loop_ub;
  int32_T c1_p_loop_ub;
  int32_T c1_q_loop_ub;
  int32_T c1_r_loop_ub;
  int32_T c1_result;
  int32_T c1_s_loop_ub;
  int32_T c1_t_loop_ub;
  int32_T c1_u_loop_ub;
  int32_T c1_v_loop_ub;
  int32_T c1_w_loop_ub;
  int32_T c1_x_loop_ub;
  int32_T c1_y_loop_ub;
  boolean_T c1_b;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_statsAlreadyComputed->WeightedCentroid = true;
  c1_st.site = &c1_fi_emlrtRSI;
  c1_statsAlreadyComputed->PixelList = true;
  c1_d = (real_T)c1_stats->size[0];
  c1_i = (int32_T)c1_d - 1;
  c1_k = 0;
  c1_emxInit_real_T1(chartInstance, &c1_st, &c1_Intensity, 1, &c1_ei_emlrtRTEI);
  c1_emxInit_real_T1(chartInstance, &c1_st, &c1_r, 1, &c1_ag_emlrtRTEI);
  c1_emxInitMatrix_cell_wrap_52(chartInstance, &c1_st, c1_reshapes,
    &c1_ui_emlrtRTEI);
  c1_emxInit_real_T1(chartInstance, &c1_st, &c1_c, 1, &c1_vi_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_varargout_4, 1, &c1_ag_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_b_idx, 1, &c1_di_emlrtRTEI);
  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_vk, 1, &c1_ji_emlrtRTEI);
  while (c1_k <= c1_i) {
    c1_b_k = (real_T)c1_k + 1.0;
    c1_i1 = c1_r->size[0];
    c1_i2 = c1_stats->size[0];
    c1_i3 = (int32_T)c1_b_k;
    c1_r->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i3, 1, c1_i2,
      &c1_hh_emlrtBCI, &c1_st) - 1].PixelIdxList->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_r, c1_i1,
      &c1_yh_emlrtRTEI);
    c1_i5 = c1_stats->size[0];
    c1_i6 = (int32_T)c1_b_k;
    c1_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i6, 1, c1_i5,
      &c1_hh_emlrtBCI, &c1_st) - 1].PixelIdxList->size[0] - 1;
    for (c1_i8 = 0; c1_i8 <= c1_loop_ub; c1_i8++) {
      c1_i11 = c1_stats->size[0];
      c1_i13 = (int32_T)c1_b_k;
      c1_r->data[c1_i8] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i13, 1,
        c1_i11, &c1_hh_emlrtBCI, &c1_st) - 1].PixelIdxList->data[c1_i8];
    }

    if (c1_r->size[0] != 0) {
      c1_b_st.site = &c1_hi_emlrtRSI;
      c1_i16 = c1_Intensity->size[0];
      c1_i19 = c1_stats->size[0];
      c1_i21 = (int32_T)c1_b_k;
      c1_Intensity->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b
        (c1_i21, 1, c1_i19, &c1_ih_emlrtBCI, &c1_b_st) - 1].PixelIdxList->size[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_Intensity, c1_i16,
        &c1_ai_emlrtRTEI);
      c1_i26 = c1_stats->size[0];
      c1_i29 = (int32_T)c1_b_k;
      c1_c_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i29, 1,
        c1_i26, &c1_ih_emlrtBCI, &c1_b_st) - 1].PixelIdxList->size[0] - 1;
      for (c1_i34 = 0; c1_i34 <= c1_c_loop_ub; c1_i34++) {
        c1_i40 = c1_stats->size[0];
        c1_i42 = (int32_T)c1_b_k;
        c1_Intensity->data[c1_i34] = c1_stats->
          data[emlrtDynamicBoundsCheckR2012b(c1_i42, 1, c1_i40, &c1_ih_emlrtBCI,
          &c1_b_st) - 1].PixelIdxList->data[c1_i34];
      }

      c1_c_st.site = &c1_ii_emlrtRSI;
      c1_i41 = c1_b_idx->size[0];
      c1_b_idx->size[0] = c1_Intensity->size[0];
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_idx, c1_i41,
        &c1_di_emlrtRTEI);
      c1_d_loop_ub = c1_Intensity->size[0] - 1;
      for (c1_i48 = 0; c1_i48 <= c1_d_loop_ub; c1_i48++) {
        c1_b_idx->data[c1_i48] = (int32_T)c1_Intensity->data[c1_i48];
      }

      c1_i51 = c1_b_idx->size[0];
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_idx, c1_i51,
        &c1_gi_emlrtRTEI);
      c1_f_loop_ub = c1_b_idx->size[0] - 1;
      for (c1_i57 = 0; c1_i57 <= c1_f_loop_ub; c1_i57++) {
        c1_b_idx->data[c1_i57]--;
      }

      c1_i59 = c1_vk->size[0];
      c1_vk->size[0] = c1_b_idx->size[0];
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_vk, c1_i59,
        &c1_ji_emlrtRTEI);
      c1_i_loop_ub = c1_b_idx->size[0] - 1;
      for (c1_i64 = 0; c1_i64 <= c1_i_loop_ub; c1_i64++) {
        c1_vk->data[c1_i64] = c1_div_nzp_s32(chartInstance, c1_b_idx->
          data[c1_i64], 120, 0, 1U, 0, 0);
      }

      c1_i66 = c1_varargout_4->size[0];
      c1_varargout_4->size[0] = c1_vk->size[0];
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_varargout_4,
        c1_i66, &c1_ki_emlrtRTEI);
      c1_k_loop_ub = c1_vk->size[0] - 1;
      for (c1_i70 = 0; c1_i70 <= c1_k_loop_ub; c1_i70++) {
        c1_varargout_4->data[c1_i70] = c1_vk->data[c1_i70] + 1;
      }

      c1_i74 = c1_vk->size[0];
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_vk, c1_i74,
        &c1_li_emlrtRTEI);
      c1_m_loop_ub = c1_vk->size[0] - 1;
      for (c1_i80 = 0; c1_i80 <= c1_m_loop_ub; c1_i80++) {
        c1_vk->data[c1_i80] *= 120;
      }

      c1_i81 = c1_b_idx->size[0];
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_idx, c1_i81,
        &c1_ni_emlrtRTEI);
      c1_o_loop_ub = c1_b_idx->size[0] - 1;
      for (c1_i85 = 0; c1_i85 <= c1_o_loop_ub; c1_i85++) {
        c1_b_idx->data[c1_i85] -= c1_vk->data[c1_i85];
      }

      c1_i88 = c1_b_idx->size[0];
      c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_idx, c1_i88,
        &c1_oi_emlrtRTEI);
      c1_q_loop_ub = c1_b_idx->size[0] - 1;
      for (c1_i93 = 0; c1_i93 <= c1_q_loop_ub; c1_i93++) {
        c1_b_idx->data[c1_i93]++;
      }

      c1_i96 = c1_Intensity->size[0];
      c1_Intensity->size[0] = c1_b_idx->size[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_Intensity, c1_i96,
        &c1_pi_emlrtRTEI);
      c1_t_loop_ub = c1_b_idx->size[0] - 1;
      for (c1_i103 = 0; c1_i103 <= c1_t_loop_ub; c1_i103++) {
        c1_Intensity->data[c1_i103] = (real_T)c1_b_idx->data[c1_i103];
      }

      c1_i104 = c1_c->size[0];
      c1_c->size[0] = c1_varargout_4->size[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_c, c1_i104,
        &c1_pi_emlrtRTEI);
      c1_w_loop_ub = c1_varargout_4->size[0] - 1;
      for (c1_i108 = 0; c1_i108 <= c1_w_loop_ub; c1_i108++) {
        c1_c->data[c1_i108] = (real_T)c1_varargout_4->data[c1_i108];
      }

      c1_b_st.site = &c1_gi_emlrtRSI;
      c1_c_st.site = &c1_ji_emlrtRSI;
      c1_result = c1_c->size[0];
      c1_sizes[0] = c1_result;
      c1_d_st.site = &c1_ki_emlrtRSI;
      c1_expected = c1_sizes[0];
      if (c1_c->size[0] == c1_expected) {
        c1_b = true;
      } else {
        c1_b = false;
      }

      if (!c1_b) {
        c1_y = NULL;
        sf_mex_assign(&c1_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c1_d_st, &c1_s_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                    sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c1_d_st, NULL, "message", 1U, 1U, 14, c1_b_y)));
      }

      if (c1_Intensity->size[0] == c1_expected) {
        c1_b = true;
      } else {
        c1_b = false;
      }

      if (!c1_b) {
        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c1_d_y = NULL;
        sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c1_d_st, &c1_s_emlrtMCI, "error", 0U, 2U, 14, c1_c_y, 14,
                    sf_mex_call(&c1_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c1_d_st, NULL, "message", 1U, 1U, 14, c1_d_y)));
      }

      c1_i121 = c1_reshapes[0].f1->size[0];
      c1_reshapes[0].f1->size[0] = c1_c->size[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_c_st, c1_reshapes[0].f1,
        c1_i121, &c1_ri_emlrtRTEI);
      c1_cb_loop_ub = c1_c->size[0] - 1;
      for (c1_i124 = 0; c1_i124 <= c1_cb_loop_ub; c1_i124++) {
        c1_reshapes[0].f1->data[c1_i124] = c1_c->data[c1_i124];
      }

      c1_i126 = c1_reshapes[1].f1->size[0];
      c1_reshapes[1].f1->size[0] = c1_Intensity->size[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_c_st, c1_reshapes[1].f1,
        c1_i126, &c1_ri_emlrtRTEI);
      c1_eb_loop_ub = c1_Intensity->size[0] - 1;
      for (c1_i130 = 0; c1_i130 <= c1_eb_loop_ub; c1_i130++) {
        c1_reshapes[1].f1->data[c1_i130] = c1_Intensity->data[c1_i130];
      }

      c1_i131 = c1_Intensity->size[0];
      c1_Intensity->size[0] = c1_reshapes[0].f1->size[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_c_st, c1_Intensity, c1_i131,
        &c1_si_emlrtRTEI);
      c1_fb_loop_ub = c1_reshapes[0].f1->size[0] - 1;
      for (c1_i135 = 0; c1_i135 <= c1_fb_loop_ub; c1_i135++) {
        c1_Intensity->data[c1_i135] = c1_reshapes[0].f1->data[c1_i135];
      }

      c1_i138 = c1_c->size[0];
      c1_c->size[0] = c1_reshapes[1].f1->size[0];
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_c_st, c1_c, c1_i138,
        &c1_si_emlrtRTEI);
      c1_gb_loop_ub = c1_reshapes[1].f1->size[0] - 1;
      for (c1_i143 = 0; c1_i143 <= c1_gb_loop_ub; c1_i143++) {
        c1_c->data[c1_i143] = c1_reshapes[1].f1->data[c1_i143];
      }

      c1_e_stats = c1_stats->size[0];
      c1_i146 = (int32_T)c1_b_k;
      c1_i147 = emlrtDynamicBoundsCheckR2012b(c1_i146, 1, c1_e_stats,
        &c1_gh_emlrtBCI, &c1_c_st) - 1;
      c1_i148 = c1_stats->data[c1_i147].PixelList->size[0] * c1_stats->
        data[c1_i147].PixelList->size[1];
      c1_stats->data[c1_i147].PixelList->size[0] = c1_Intensity->size[0];
      c1_i149 = (int32_T)c1_b_k;
      c1_i150 = emlrtDynamicBoundsCheckR2012b(c1_i149, 1, c1_e_stats,
        &c1_gh_emlrtBCI, &c1_c_st) - 1;
      c1_stats->data[c1_i150].PixelList->size[1] = 2;
      c1_emxEnsureCapacity_real_T1(chartInstance, &c1_c_st, c1_stats->
        data[c1_i150].PixelList, c1_i148, &c1_ti_emlrtRTEI);
      c1_hb_loop_ub = c1_Intensity->size[0] - 1;
      for (c1_i151 = 0; c1_i151 <= c1_hb_loop_ub; c1_i151++) {
        c1_i152 = (int32_T)c1_b_k;
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i152, 1, c1_e_stats,
          &c1_gh_emlrtBCI, &c1_c_st) - 1].PixelList->data[c1_i151] =
          c1_Intensity->data[c1_i151];
      }

      c1_ib_loop_ub = c1_c->size[0] - 1;
      for (c1_i153 = 0; c1_i153 <= c1_ib_loop_ub; c1_i153++) {
        c1_i154 = (int32_T)c1_b_k;
        c1_i155 = (int32_T)c1_b_k;
        c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i154, 1, c1_e_stats,
          &c1_gh_emlrtBCI, &c1_c_st) - 1].PixelList->data[c1_i153 +
          c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i155, 1, c1_e_stats,
          &c1_gh_emlrtBCI, &c1_c_st) - 1].PixelList->size[0]] = c1_c->
          data[c1_i153];
      }
    } else {
      c1_i12 = c1_stats->size[0];
      c1_i15 = (int32_T)c1_b_k;
      c1_i18 = emlrtDynamicBoundsCheckR2012b(c1_i15, 1, c1_i12, &c1_yg_emlrtBCI,
        &c1_st) - 1;
      c1_stats->data[c1_i18].PixelList->size[0] = 0;
      c1_i22 = c1_stats->size[0];
      c1_i24 = (int32_T)c1_b_k;
      c1_i25 = emlrtDynamicBoundsCheckR2012b(c1_i24, 1, c1_i22, &c1_yg_emlrtBCI,
        &c1_st) - 1;
      c1_i28 = c1_stats->data[c1_i25].PixelList->size[0] * c1_stats->data[c1_i25]
        .PixelList->size[1];
      c1_stats->data[c1_i25].PixelList->size[1] = 2;
      c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_stats->data[c1_i25]
        .PixelList, c1_i28, &c1_ci_emlrtRTEI);
      c1_b_stats = c1_stats->size[0];
      c1_i39 = (int32_T)c1_b_k;
      emlrtDynamicBoundsCheckR2012b(c1_i39, 1, c1_b_stats, &c1_yg_emlrtBCI,
        &c1_st);
      c1_c_stats = c1_stats->size[0];
      c1_i43 = (int32_T)c1_b_k;
      emlrtDynamicBoundsCheckR2012b(c1_i43, 1, c1_c_stats, &c1_yg_emlrtBCI,
        &c1_st);
    }

    c1_k++;
  }

  c1_emxFreeMatrix_cell_wrap_52(chartInstance, c1_reshapes);
  c1_st.site = &c1_ei_emlrtRSI;
  c1_statsAlreadyComputed->PixelValues = true;
  c1_d1 = (real_T)c1_stats->size[0];
  c1_i4 = (int32_T)c1_d1 - 1;
  for (c1_c_k = 0; c1_c_k <= c1_i4; c1_c_k++) {
    c1_d_k = (real_T)c1_c_k + 1.0;
    c1_i7 = c1_r->size[0];
    c1_i9 = c1_stats->size[0];
    c1_i10 = (int32_T)c1_d_k;
    c1_r->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i10, 1,
      c1_i9, &c1_jh_emlrtBCI, &c1_st) - 1].PixelIdxList->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_r, c1_i7,
      &c1_bi_emlrtRTEI);
    c1_i17 = c1_stats->size[0];
    c1_i20 = (int32_T)c1_d_k;
    c1_b_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i20, 1,
      c1_i17, &c1_jh_emlrtBCI, &c1_st) - 1].PixelIdxList->size[0] - 1;
    for (c1_i23 = 0; c1_i23 <= c1_b_loop_ub; c1_i23++) {
      c1_i27 = c1_stats->size[0];
      c1_i31 = (int32_T)c1_d_k;
      c1_r->data[c1_i23] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i31,
        1, c1_i27, &c1_jh_emlrtBCI, &c1_st) - 1].PixelIdxList->data[c1_i23];
    }

    c1_wc[0] = (real_T)c1_r->size[0];
    c1_i30 = c1_stats->size[0];
    c1_i33 = (int32_T)c1_d_k;
    c1_i36 = emlrtDynamicBoundsCheckR2012b(c1_i33, 1, c1_i30, &c1_xg_emlrtBCI,
      &c1_st);
    c1_i38 = c1_stats->data[c1_i36 - 1].PixelValues->size[0];
    c1_stats->data[c1_i36 - 1].PixelValues->size[0] = (int32_T)c1_wc[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_stats->data[c1_i36 - 1]
      .PixelValues, c1_i38, &c1_fi_emlrtRTEI);
    c1_b_st.site = &c1_li_emlrtRSI;
    c1_i45 = c1_Intensity->size[0];
    c1_i47 = c1_stats->size[0];
    c1_i49 = (int32_T)c1_d_k;
    c1_Intensity->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i49,
      1, c1_i47, &c1_mh_emlrtBCI, &c1_b_st) - 1].PixelIdxList->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_Intensity, c1_i45,
      &c1_hi_emlrtRTEI);
    c1_i54 = c1_stats->size[0];
    c1_i56 = (int32_T)c1_d_k;
    c1_g_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i56, 1,
      c1_i54, &c1_mh_emlrtBCI, &c1_b_st) - 1].PixelIdxList->size[0] - 1;
    for (c1_i58 = 0; c1_i58 <= c1_g_loop_ub; c1_i58++) {
      c1_i61 = c1_stats->size[0];
      c1_i63 = (int32_T)c1_d_k;
      c1_Intensity->data[c1_i58] = c1_stats->data[emlrtDynamicBoundsCheckR2012b
        (c1_i63, 1, c1_i61, &c1_mh_emlrtBCI, &c1_b_st) - 1].PixelIdxList->
        data[c1_i58];
    }

    c1_c_st.site = &c1_ii_emlrtRSI;
    c1_i62 = c1_b_idx->size[0];
    c1_b_idx->size[0] = c1_Intensity->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_idx, c1_i62,
      &c1_di_emlrtRTEI);
    c1_j_loop_ub = c1_Intensity->size[0] - 1;
    for (c1_i68 = 0; c1_i68 <= c1_j_loop_ub; c1_i68++) {
      c1_b_idx->data[c1_i68] = (int32_T)c1_Intensity->data[c1_i68];
    }

    c1_i69 = c1_b_idx->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_idx, c1_i69,
      &c1_gi_emlrtRTEI);
    c1_l_loop_ub = c1_b_idx->size[0] - 1;
    for (c1_i73 = 0; c1_i73 <= c1_l_loop_ub; c1_i73++) {
      c1_b_idx->data[c1_i73]--;
    }

    c1_i78 = c1_vk->size[0];
    c1_vk->size[0] = c1_b_idx->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_vk, c1_i78,
      &c1_ji_emlrtRTEI);
    c1_n_loop_ub = c1_b_idx->size[0] - 1;
    for (c1_i82 = 0; c1_i82 <= c1_n_loop_ub; c1_i82++) {
      c1_vk->data[c1_i82] = c1_div_nzp_s32(chartInstance, c1_b_idx->data[c1_i82],
        120, 0, 1U, 0, 0);
    }

    c1_i84 = c1_varargout_4->size[0];
    c1_varargout_4->size[0] = c1_vk->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_varargout_4, c1_i84,
      &c1_ki_emlrtRTEI);
    c1_p_loop_ub = c1_vk->size[0] - 1;
    for (c1_i91 = 0; c1_i91 <= c1_p_loop_ub; c1_i91++) {
      c1_varargout_4->data[c1_i91] = c1_vk->data[c1_i91] + 1;
    }

    c1_i94 = c1_vk->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_vk, c1_i94,
      &c1_li_emlrtRTEI);
    c1_s_loop_ub = c1_vk->size[0] - 1;
    for (c1_i98 = 0; c1_i98 <= c1_s_loop_ub; c1_i98++) {
      c1_vk->data[c1_i98] *= 120;
    }

    c1_i102 = c1_b_idx->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_idx, c1_i102,
      &c1_ni_emlrtRTEI);
    c1_u_loop_ub = c1_b_idx->size[0] - 1;
    for (c1_i105 = 0; c1_i105 <= c1_u_loop_ub; c1_i105++) {
      c1_b_idx->data[c1_i105] -= c1_vk->data[c1_i105];
    }

    c1_i107 = c1_b_idx->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_idx, c1_i107,
      &c1_oi_emlrtRTEI);
    c1_x_loop_ub = c1_b_idx->size[0] - 1;
    for (c1_i111 = 0; c1_i111 <= c1_x_loop_ub; c1_i111++) {
      c1_b_idx->data[c1_i111]++;
    }

    c1_i113 = c1_Intensity->size[0];
    c1_Intensity->size[0] = c1_b_idx->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_Intensity, c1_i113,
      &c1_pi_emlrtRTEI);
    c1_y_loop_ub = c1_b_idx->size[0] - 1;
    for (c1_i114 = 0; c1_i114 <= c1_y_loop_ub; c1_i114++) {
      c1_Intensity->data[c1_i114] = (real_T)c1_b_idx->data[c1_i114];
    }

    c1_i116 = c1_c->size[0];
    c1_c->size[0] = c1_varargout_4->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_b_st, c1_c, c1_i116,
      &c1_pi_emlrtRTEI);
    c1_bb_loop_ub = c1_varargout_4->size[0] - 1;
    for (c1_i117 = 0; c1_i117 <= c1_bb_loop_ub; c1_i117++) {
      c1_c->data[c1_i117] = (real_T)c1_varargout_4->data[c1_i117];
    }

    c1_i118 = c1_r->size[0];
    c1_i119 = c1_stats->size[0];
    c1_i120 = (int32_T)c1_d_k;
    c1_r->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i120, 1,
      c1_i119, &c1_oh_emlrtBCI, &c1_st) - 1].PixelValues->size[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_r, c1_i118,
      &c1_qi_emlrtRTEI);
    c1_i122 = c1_stats->size[0];
    c1_i123 = (int32_T)c1_d_k;
    c1_db_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i123, 1,
      c1_i122, &c1_oh_emlrtBCI, &c1_st) - 1].PixelValues->size[0] - 1;
    for (c1_i125 = 0; c1_i125 <= c1_db_loop_ub; c1_i125++) {
      c1_i127 = c1_stats->size[0];
      c1_i129 = (int32_T)c1_d_k;
      c1_r->data[c1_i125] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i129,
        1, c1_i127, &c1_oh_emlrtBCI, &c1_st) - 1].PixelValues->data[c1_i125];
    }

    c1_d3 = (real_T)c1_r->size[0];
    c1_i128 = (int32_T)c1_d3 - 1;
    for (c1_c_idx = 0; c1_c_idx <= c1_i128; c1_c_idx++) {
      c1_d_idx = (real_T)c1_c_idx + 1.0;
      c1_i132 = c1_stats->size[0];
      c1_i133 = (int32_T)c1_d_k;
      c1_i134 = emlrtDynamicBoundsCheckR2012b(c1_i133, 1, c1_i132,
        &c1_wg_emlrtBCI, &c1_st) - 1;
      c1_i136 = c1_Intensity->size[0];
      c1_i137 = (int32_T)c1_d_idx;
      c1_i139 = (int32_T)c1_Intensity->data[emlrtDynamicBoundsCheckR2012b
        (c1_i137, 1, c1_i136, &c1_dh_emlrtBCI, &c1_st) - 1];
      c1_i140 = c1_c->size[0];
      c1_i141 = (int32_T)c1_d_idx;
      c1_i142 = (int32_T)c1_c->data[emlrtDynamicBoundsCheckR2012b(c1_i141, 1,
        c1_i140, &c1_dh_emlrtBCI, &c1_st) - 1];
      c1_i144 = c1_stats->data[c1_i134].PixelValues->size[0];
      c1_i145 = (int32_T)c1_d_idx;
      c1_stats->data[c1_i134].PixelValues->data[emlrtDynamicBoundsCheckR2012b
        (c1_i145, 1, c1_i144, &c1_fh_emlrtBCI, &c1_st) - 1] = c1_I
        [(emlrtDynamicBoundsCheckR2012b(c1_i139, 1, 120, &c1_ch_emlrtBCI, &c1_st)
          + 120 * (emlrtDynamicBoundsCheckR2012b(c1_i142, 1, 160,
            &c1_eh_emlrtBCI, &c1_st) - 1)) - 1];
    }
  }

  c1_emxFree_int32_T(chartInstance, &c1_vk);
  c1_emxFree_int32_T(chartInstance, &c1_b_idx);
  c1_emxFree_int32_T(chartInstance, &c1_varargout_4);
  c1_emxFree_real_T(chartInstance, &c1_c);
  c1_d2 = (real_T)c1_stats->size[0];
  c1_i14 = (int32_T)c1_d2 - 1;
  c1_e_k = 0;
  c1_emxInit_real_T(chartInstance, c1_sp, &c1_r1, 2, &c1_ag_emlrtRTEI);
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_r2, 1, &c1_mi_emlrtRTEI);
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_b_Intensity, 1, &c1_ii_emlrtRTEI);
  while (c1_e_k <= c1_i14) {
    c1_f_k = (real_T)c1_e_k + 1.0;
    c1_i32 = c1_Intensity->size[0];
    c1_i35 = c1_stats->size[0];
    c1_i37 = (int32_T)c1_f_k;
    c1_Intensity->size[0] = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i37,
      1, c1_i35, &c1_kh_emlrtBCI, c1_sp) - 1].PixelValues->size[0];
    c1_st.site = &c1_bl_emlrtRSI;
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_Intensity, c1_i32,
      &c1_ei_emlrtRTEI);
    c1_i44 = c1_stats->size[0];
    c1_i46 = (int32_T)c1_f_k;
    c1_e_loop_ub = c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i46, 1,
      c1_i44, &c1_kh_emlrtBCI, c1_sp) - 1].PixelValues->size[0] - 1;
    for (c1_i50 = 0; c1_i50 <= c1_e_loop_ub; c1_i50++) {
      c1_i53 = c1_stats->size[0];
      c1_i55 = (int32_T)c1_f_k;
      c1_Intensity->data[c1_i50] = c1_stats->data[emlrtDynamicBoundsCheckR2012b
        (c1_i55, 1, c1_i53, &c1_lh_emlrtBCI, c1_sp) - 1].PixelValues->
        data[c1_i50];
    }

    c1_i52 = c1_b_Intensity->size[0];
    c1_b_Intensity->size[0] = c1_Intensity->size[0];
    c1_st.site = &c1_di_emlrtRSI;
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_b_Intensity, c1_i52,
      &c1_ii_emlrtRTEI);
    c1_h_loop_ub = c1_Intensity->size[0] - 1;
    for (c1_i60 = 0; c1_i60 <= c1_h_loop_ub; c1_i60++) {
      c1_b_Intensity->data[c1_i60] = c1_Intensity->data[c1_i60];
    }

    c1_st.site = &c1_di_emlrtRSI;
    c1_sumIntensity = c1_b_sum(chartInstance, &c1_st, c1_b_Intensity);
    c1_i65 = c1_stats->size[0];
    c1_i67 = (int32_T)c1_f_k;
    emlrtDynamicBoundsCheckR2012b(c1_i67, 1, c1_i65, &c1_vg_emlrtBCI, c1_sp);
    for (c1_n = 0; c1_n < 2; c1_n++) {
      c1_b_n = (real_T)c1_n + 1.0;
      c1_i72 = c1_stats->size[0];
      c1_i75 = (int32_T)c1_f_k;
      c1_i77 = emlrtDynamicBoundsCheckR2012b(c1_i75, 1, c1_i72, &c1_ah_emlrtBCI,
        c1_sp) - 1;
      c1_i79 = c1_r1->size[0] * c1_r1->size[1];
      c1_r1->size[0] = c1_stats->data[c1_i77].PixelList->size[0];
      c1_r1->size[1] = 2;
      c1_st.site = &c1_ci_emlrtRSI;
      c1_emxEnsureCapacity_real_T1(chartInstance, &c1_st, c1_r1, c1_i79,
        &c1_mi_emlrtRTEI);
      c1_i83 = c1_stats->size[0];
      c1_i86 = (int32_T)c1_f_k;
      c1_i87 = emlrtDynamicBoundsCheckR2012b(c1_i86, 1, c1_i83, &c1_ah_emlrtBCI,
        c1_sp) - 1;
      c1_i89 = c1_stats->size[0];
      c1_i90 = (int32_T)c1_f_k;
      c1_i92 = emlrtDynamicBoundsCheckR2012b(c1_i90, 1, c1_i89, &c1_ah_emlrtBCI,
        c1_sp) - 1;
      c1_r_loop_ub = c1_stats->data[c1_i87].PixelList->size[0] * c1_stats->
        data[c1_i92].PixelList->size[1] - 1;
      for (c1_i95 = 0; c1_i95 <= c1_r_loop_ub; c1_i95++) {
        c1_i97 = c1_stats->size[0];
        c1_i100 = (int32_T)c1_f_k;
        c1_r1->data[c1_i95] = c1_stats->data[emlrtDynamicBoundsCheckR2012b
          (c1_i100, 1, c1_i97, &c1_nh_emlrtBCI, c1_sp) - 1].PixelList->
          data[c1_i95];
      }

      c1_c_n = (int32_T)c1_b_n - 1;
      c1_i99 = c1_r1->size[0] - 1;
      c1_i101 = c1_r->size[0];
      c1_r->size[0] = c1_i99 + 1;
      c1_st.site = &c1_ci_emlrtRSI;
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_r, c1_i101,
        &c1_mi_emlrtRTEI);
      c1_v_loop_ub = c1_i99;
      for (c1_i106 = 0; c1_i106 <= c1_v_loop_ub; c1_i106++) {
        c1_r->data[c1_i106] = c1_r1->data[c1_i106 + c1_r1->size[0] * c1_c_n];
      }

      c1_i109 = c1_r->size[0];
      c1_i110 = c1_Intensity->size[0];
      emlrtSizeEqCheck1DR2012b(c1_i109, c1_i110, &c1_c_emlrtECI, c1_sp);
      c1_i112 = c1_r2->size[0];
      c1_r2->size[0] = c1_r->size[0];
      c1_st.site = &c1_ci_emlrtRSI;
      c1_emxEnsureCapacity_real_T(chartInstance, &c1_st, c1_r2, c1_i112,
        &c1_mi_emlrtRTEI);
      c1_ab_loop_ub = c1_r->size[0] - 1;
      for (c1_i115 = 0; c1_i115 <= c1_ab_loop_ub; c1_i115++) {
        c1_r2->data[c1_i115] = c1_r->data[c1_i115] * c1_Intensity->data[c1_i115];
      }

      c1_st.site = &c1_ci_emlrtRSI;
      c1_M = c1_b_sum(chartInstance, &c1_st, c1_r2);
      c1_wc[(int32_T)c1_b_n - 1] = c1_M / c1_sumIntensity;
    }

    c1_d_stats = c1_stats->size[0];
    for (c1_i71 = 0; c1_i71 < 2; c1_i71++) {
      c1_i76 = (int32_T)c1_f_k;
      c1_stats->data[emlrtDynamicBoundsCheckR2012b(c1_i76, 1, c1_d_stats,
        &c1_bh_emlrtBCI, c1_sp) - 1].WeightedCentroid[c1_i71] = c1_wc[c1_i71];
    }

    c1_e_k++;
  }

  c1_emxFree_real_T(chartInstance, &c1_b_Intensity);
  c1_emxFree_real_T(chartInstance, &c1_r2);
  c1_emxFree_real_T(chartInstance, &c1_r);
  c1_emxFree_real_T(chartInstance, &c1_r1);
  c1_emxFree_real_T(chartInstance, &c1_Intensity);
}

static void c1_b_round(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_st;
  real_T c1_d_x;
  real_T c1_e_x;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_k;
  int32_T c1_nx;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_qi_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_nx = c1_c_x->size[0];
  c1_b_st.site = &c1_ri_emlrtRSI;
  c1_b = c1_nx;
  c1_b_b = c1_b;
  if (1 > c1_b_b) {
    c1_overflow = false;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_c_st.site = &c1_kb_emlrtRSI;
    c1_check_forloop_overflow_error(chartInstance, &c1_c_st);
  }

  for (c1_k = 1; c1_k - 1 < c1_nx; c1_k++) {
    c1_b_k = c1_k - 1;
    c1_d_x = c1_c_x->data[c1_b_k];
    c1_e_x = c1_d_x;
    c1_e_x = muDoubleScalarRound(c1_e_x);
    c1_c_x->data[c1_b_k] = c1_e_x;
  }
}

static void c1_d_sort(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, c1_emxArray_real_T *c1_c_x,
                      c1_emxArray_int32_T *c1_b_idx)
{
  c1_emxArray_int32_T *c1_b_iwork;
  c1_emxArray_real_T *c1_xwork;
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_e_st;
  emlrtStack c1_st;
  real_T c1_x4[4];
  real_T c1_b_dv[2];
  real_T c1_d_x;
  int32_T c1_idx4[4];
  int32_T c1_perm[4];
  int32_T c1_iv[1];
  int32_T c1_b_b;
  int32_T c1_b_i1;
  int32_T c1_b_i2;
  int32_T c1_b_i3;
  int32_T c1_b_i4;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_b_n;
  int32_T c1_b_nNaNs;
  int32_T c1_b_nNonNaN;
  int32_T c1_c_b;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_c_n;
  int32_T c1_d_k;
  int32_T c1_e_b;
  int32_T c1_e_k;
  int32_T c1_f_b;
  int32_T c1_f_k;
  int32_T c1_g_b;
  int32_T c1_g_k;
  int32_T c1_h_b;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i_b;
  int32_T c1_ib;
  int32_T c1_itmp;
  int32_T c1_j_b;
  int32_T c1_k;
  int32_T c1_k_b;
  int32_T c1_l_b;
  int32_T c1_loop_ub;
  int32_T c1_m;
  int32_T c1_m_b;
  int32_T c1_n;
  int32_T c1_nBlocks;
  int32_T c1_nLastBlock;
  int32_T c1_nNaNs;
  int32_T c1_nNonNaN;
  int32_T c1_n_b;
  int32_T c1_o_b;
  int32_T c1_p_b;
  int32_T c1_preSortLevel;
  int32_T c1_quartetOffset;
  int32_T c1_tailOffset;
  int32_T c1_wOffset;
  boolean_T c1_b;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_d_b;
  boolean_T c1_d_overflow;
  boolean_T c1_e_overflow;
  boolean_T c1_f_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_xe_emlrtRSI;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  c1_e_st.prev = &c1_d_st;
  c1_e_st.tls = c1_d_st.tls;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_b_dv[c1_i] = (real_T)c1_c_x->size[c1_i];
  }

  c1_i1 = c1_b_idx->size[0] * c1_b_idx->size[1];
  c1_b_idx->size[0] = (int32_T)c1_b_dv[0];
  c1_b_idx->size[1] = 1;
  c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_b_idx, c1_i1,
    &c1_wi_emlrtRTEI);
  c1_loop_ub = (int32_T)c1_b_dv[0] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
    c1_b_idx->data[c1_i2] = 0;
  }

  c1_b = (c1_c_x->size[0] == 0);
  if (!c1_b) {
    c1_b_st.site = &c1_ti_emlrtRSI;
    c1_b_st.site = &c1_ye_emlrtRSI;
    c1_n = c1_c_x->size[0];
    c1_c_st.site = &c1_af_emlrtRSI;
    c1_b_n = c1_c_x->size[0];
    for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
      c1_x4[c1_i3] = 0.0;
    }

    for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
      c1_idx4[c1_i4] = 0;
    }

    c1_emxInit_int32_T(chartInstance, &c1_c_st, &c1_b_iwork, 1, &c1_sh_emlrtRTEI);
    c1_i5 = c1_b_iwork->size[0];
    c1_b_iwork->size[0] = c1_b_idx->size[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_iwork, c1_i5,
      &c1_rh_emlrtRTEI);
    c1_iv[0] = c1_b_iwork->size[0];
    c1_i6 = c1_b_iwork->size[0];
    c1_b_iwork->size[0] = c1_iv[0];
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_iwork, c1_i6,
      &c1_sh_emlrtRTEI);
    c1_i7 = c1_b_iwork->size[0];
    c1_i8 = c1_b_iwork->size[0];
    c1_b_iwork->size[0] = c1_i7;
    c1_emxEnsureCapacity_int32_T(chartInstance, &c1_c_st, c1_b_iwork, c1_i8,
      &c1_th_emlrtRTEI);
    c1_b_loop_ub = c1_i7 - 1;
    for (c1_i9 = 0; c1_i9 <= c1_b_loop_ub; c1_i9++) {
      c1_b_iwork->data[c1_i9] = 0;
    }

    c1_emxInit_real_T1(chartInstance, &c1_c_st, &c1_xwork, 1, &c1_vh_emlrtRTEI);
    c1_b_dv[0] = (real_T)c1_c_x->size[0];
    c1_i10 = c1_xwork->size[0];
    c1_xwork->size[0] = (int32_T)c1_b_dv[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_c_st, c1_xwork, c1_i10,
      &c1_uh_emlrtRTEI);
    c1_iv[0] = c1_xwork->size[0];
    c1_i11 = c1_xwork->size[0];
    c1_xwork->size[0] = c1_iv[0];
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_c_st, c1_xwork, c1_i11,
      &c1_vh_emlrtRTEI);
    c1_i12 = c1_xwork->size[0];
    c1_i13 = c1_xwork->size[0];
    c1_xwork->size[0] = c1_i12;
    c1_emxEnsureCapacity_real_T(chartInstance, &c1_c_st, c1_xwork, c1_i13,
      &c1_wh_emlrtRTEI);
    c1_c_loop_ub = c1_i12 - 1;
    for (c1_i14 = 0; c1_i14 <= c1_c_loop_ub; c1_i14++) {
      c1_xwork->data[c1_i14] = 0.0;
    }

    c1_nNaNs = 0;
    c1_ib = 0;
    c1_d_st.site = &c1_ff_emlrtRSI;
    c1_b_b = c1_b_n;
    c1_c_b = c1_b_b;
    if (1 > c1_c_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_e_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
    }

    for (c1_k = 1; c1_k - 1 < c1_b_n; c1_k++) {
      c1_b_k = c1_k - 1;
      c1_d_x = c1_c_x->data[c1_b_k];
      c1_d_b = muDoubleScalarIsNaN(c1_d_x);
      if (c1_d_b) {
        c1_b_idx->data[(c1_b_n - c1_nNaNs) - 1] = c1_b_k + 1;
        c1_xwork->data[(c1_b_n - c1_nNaNs) - 1] = c1_c_x->data[c1_b_k];
        c1_nNaNs++;
      } else {
        c1_ib++;
        c1_idx4[c1_ib - 1] = c1_b_k + 1;
        c1_x4[c1_ib - 1] = c1_c_x->data[c1_b_k];
        if (c1_ib == 4) {
          c1_quartetOffset = c1_b_k - c1_nNaNs;
          if (c1_x4[0] >= c1_x4[1]) {
            c1_b_i1 = 1;
            c1_b_i2 = 2;
          } else {
            c1_b_i1 = 2;
            c1_b_i2 = 1;
          }

          if (c1_x4[2] >= c1_x4[3]) {
            c1_b_i3 = 3;
            c1_b_i4 = 4;
          } else {
            c1_b_i3 = 4;
            c1_b_i4 = 3;
          }

          if (c1_x4[c1_b_i1 - 1] >= c1_x4[c1_b_i3 - 1]) {
            if (c1_x4[c1_b_i2 - 1] >= c1_x4[c1_b_i3 - 1]) {
              c1_perm[0] = c1_b_i1;
              c1_perm[1] = c1_b_i2;
              c1_perm[2] = c1_b_i3;
              c1_perm[3] = c1_b_i4;
            } else if (c1_x4[c1_b_i2 - 1] >= c1_x4[c1_b_i4 - 1]) {
              c1_perm[0] = c1_b_i1;
              c1_perm[1] = c1_b_i3;
              c1_perm[2] = c1_b_i2;
              c1_perm[3] = c1_b_i4;
            } else {
              c1_perm[0] = c1_b_i1;
              c1_perm[1] = c1_b_i3;
              c1_perm[2] = c1_b_i4;
              c1_perm[3] = c1_b_i2;
            }
          } else if (c1_x4[c1_b_i1 - 1] >= c1_x4[c1_b_i4 - 1]) {
            if (c1_x4[c1_b_i2 - 1] >= c1_x4[c1_b_i4 - 1]) {
              c1_perm[0] = c1_b_i3;
              c1_perm[1] = c1_b_i1;
              c1_perm[2] = c1_b_i2;
              c1_perm[3] = c1_b_i4;
            } else {
              c1_perm[0] = c1_b_i3;
              c1_perm[1] = c1_b_i1;
              c1_perm[2] = c1_b_i4;
              c1_perm[3] = c1_b_i2;
            }
          } else {
            c1_perm[0] = c1_b_i3;
            c1_perm[1] = c1_b_i4;
            c1_perm[2] = c1_b_i1;
            c1_perm[3] = c1_b_i2;
          }

          c1_b_idx->data[c1_quartetOffset - 3] = c1_idx4[c1_perm[0] - 1];
          c1_b_idx->data[c1_quartetOffset - 2] = c1_idx4[c1_perm[1] - 1];
          c1_b_idx->data[c1_quartetOffset - 1] = c1_idx4[c1_perm[2] - 1];
          c1_b_idx->data[c1_quartetOffset] = c1_idx4[c1_perm[3] - 1];
          c1_c_x->data[c1_quartetOffset - 3] = c1_x4[c1_perm[0] - 1];
          c1_c_x->data[c1_quartetOffset - 2] = c1_x4[c1_perm[1] - 1];
          c1_c_x->data[c1_quartetOffset - 1] = c1_x4[c1_perm[2] - 1];
          c1_c_x->data[c1_quartetOffset] = c1_x4[c1_perm[3] - 1];
          c1_ib = 0;
        }
      }
    }

    c1_wOffset = (c1_b_n - c1_nNaNs) - 1;
    if (c1_ib > 0) {
      c1_c_n = c1_ib;
      for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
        c1_perm[c1_i15] = 0;
      }

      if (c1_c_n == 1) {
        c1_perm[0] = 1;
      } else if (c1_c_n == 2) {
        if (c1_x4[0] >= c1_x4[1]) {
          c1_perm[0] = 1;
          c1_perm[1] = 2;
        } else {
          c1_perm[0] = 2;
          c1_perm[1] = 1;
        }
      } else if (c1_x4[0] >= c1_x4[1]) {
        if (c1_x4[1] >= c1_x4[2]) {
          c1_perm[0] = 1;
          c1_perm[1] = 2;
          c1_perm[2] = 3;
        } else if (c1_x4[0] >= c1_x4[2]) {
          c1_perm[0] = 1;
          c1_perm[1] = 3;
          c1_perm[2] = 2;
        } else {
          c1_perm[0] = 3;
          c1_perm[1] = 1;
          c1_perm[2] = 2;
        }
      } else if (c1_x4[0] >= c1_x4[2]) {
        c1_perm[0] = 2;
        c1_perm[1] = 1;
        c1_perm[2] = 3;
      } else if (c1_x4[1] >= c1_x4[2]) {
        c1_perm[0] = 2;
        c1_perm[1] = 3;
        c1_perm[2] = 1;
      } else {
        c1_perm[0] = 3;
        c1_perm[1] = 2;
        c1_perm[2] = 1;
      }

      c1_d_st.site = &c1_gf_emlrtRSI;
      c1_g_b = c1_ib;
      c1_h_b = c1_g_b;
      if (1 > c1_h_b) {
        c1_c_overflow = false;
      } else {
        c1_c_overflow = (c1_h_b > 2147483646);
      }

      if (c1_c_overflow) {
        c1_e_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
      }

      for (c1_d_k = 1; c1_d_k - 1 < c1_ib; c1_d_k++) {
        c1_b_k = c1_d_k;
        c1_b_idx->data[(c1_wOffset - c1_ib) + c1_b_k] = c1_idx4[c1_perm[c1_b_k -
          1] - 1];
        c1_c_x->data[(c1_wOffset - c1_ib) + c1_b_k] = c1_x4[c1_perm[c1_b_k - 1]
          - 1];
      }
    }

    c1_m = c1_nNaNs >> 1;
    c1_d_st.site = &c1_hf_emlrtRSI;
    c1_e_b = c1_m;
    c1_f_b = c1_e_b;
    if (1 > c1_f_b) {
      c1_b_overflow = false;
    } else {
      c1_b_overflow = (c1_f_b > 2147483646);
    }

    if (c1_b_overflow) {
      c1_e_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
    }

    for (c1_c_k = 1; c1_c_k - 1 < c1_m; c1_c_k++) {
      c1_b_k = c1_c_k;
      c1_itmp = c1_b_idx->data[c1_wOffset + c1_b_k];
      c1_b_idx->data[c1_wOffset + c1_b_k] = c1_b_idx->data[c1_b_n - c1_b_k];
      c1_b_idx->data[c1_b_n - c1_b_k] = c1_itmp;
      c1_c_x->data[c1_wOffset + c1_b_k] = c1_xwork->data[c1_b_n - c1_b_k];
      c1_c_x->data[c1_b_n - c1_b_k] = c1_xwork->data[c1_wOffset + c1_b_k];
    }

    if ((c1_nNaNs & 1) != 0) {
      c1_c_x->data[(c1_wOffset + c1_m) + 1] = c1_xwork->data[(c1_wOffset + c1_m)
        + 1];
    }

    c1_nNonNaN = c1_n - c1_nNaNs;
    c1_preSortLevel = 2;
    if (c1_nNonNaN > 1) {
      if (c1_n >= 256) {
        c1_nBlocks = c1_nNonNaN >> 8;
        if (c1_nBlocks > 0) {
          c1_c_st.site = &c1_bf_emlrtRSI;
          c1_i_b = c1_nBlocks;
          c1_j_b = c1_i_b;
          if (1 > c1_j_b) {
            c1_d_overflow = false;
          } else {
            c1_d_overflow = (c1_j_b > 2147483646);
          }

          if (c1_d_overflow) {
            c1_d_st.site = &c1_kb_emlrtRSI;
            c1_check_forloop_overflow_error(chartInstance, &c1_d_st);
          }

          for (c1_m_b = 1; c1_m_b - 1 < c1_nBlocks; c1_m_b++) {
            c1_n_b = c1_m_b - 1;
            c1_c_st.site = &c1_cf_emlrtRSI;
            c1_d_merge_pow2_block(chartInstance, &c1_c_st, c1_b_idx, c1_c_x,
                                  c1_n_b << 8);
          }

          c1_tailOffset = c1_nBlocks << 8;
          c1_nLastBlock = c1_nNonNaN - c1_tailOffset;
          if (c1_nLastBlock > 0) {
            c1_c_st.site = &c1_df_emlrtRSI;
            c1_d_merge_block(chartInstance, &c1_c_st, c1_b_idx, c1_c_x,
                             c1_tailOffset, c1_nLastBlock, 2, c1_b_iwork,
                             c1_xwork);
          }

          c1_preSortLevel = 8;
        }
      }

      c1_c_st.site = &c1_ef_emlrtRSI;
      c1_d_merge_block(chartInstance, &c1_c_st, c1_b_idx, c1_c_x, 0, c1_nNonNaN,
                       c1_preSortLevel, c1_b_iwork, c1_xwork);
    }

    if ((c1_nNaNs > 0) && (c1_nNonNaN > 0)) {
      c1_c_st.site = &c1_ui_emlrtRSI;
      c1_b_nNonNaN = c1_nNonNaN - 1;
      c1_b_nNaNs = c1_nNaNs - 1;
      c1_d_st.site = &c1_vi_emlrtRSI;
      c1_k_b = c1_b_nNaNs + 1;
      c1_l_b = c1_k_b;
      if (1 > c1_l_b) {
        c1_e_overflow = false;
      } else {
        c1_e_overflow = (c1_l_b > 2147483646);
      }

      if (c1_e_overflow) {
        c1_e_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
      }

      for (c1_e_k = 1; c1_e_k - 1 <= c1_b_nNaNs; c1_e_k++) {
        c1_g_k = c1_e_k;
        c1_xwork->data[c1_g_k - 1] = c1_c_x->data[c1_b_nNonNaN + c1_g_k];
        c1_b_iwork->data[c1_g_k - 1] = c1_b_idx->data[c1_b_nNonNaN + c1_g_k];
      }

      for (c1_f_k = c1_b_nNonNaN + 1; c1_f_k > 0; c1_f_k--) {
        c1_c_x->data[c1_b_nNaNs + c1_f_k] = c1_c_x->data[c1_f_k - 1];
        c1_b_idx->data[c1_b_nNaNs + c1_f_k] = c1_b_idx->data[c1_f_k - 1];
      }

      c1_d_st.site = &c1_wi_emlrtRSI;
      c1_o_b = c1_b_nNaNs + 1;
      c1_p_b = c1_o_b;
      if (1 > c1_p_b) {
        c1_f_overflow = false;
      } else {
        c1_f_overflow = (c1_p_b > 2147483646);
      }

      if (c1_f_overflow) {
        c1_e_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_e_st);
      }

      for (c1_h_k = 1; c1_h_k - 1 <= c1_b_nNaNs; c1_h_k++) {
        c1_g_k = c1_h_k - 1;
        c1_c_x->data[c1_g_k] = c1_xwork->data[c1_g_k];
        c1_b_idx->data[c1_g_k] = c1_b_iwork->data[c1_g_k];
      }
    }

    c1_emxFree_real_T(chartInstance, &c1_xwork);
    c1_emxFree_int32_T(chartInstance, &c1_b_iwork);
  }
}

static void c1_d_merge_pow2_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real_T *c1_c_x, int32_T c1_offset)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  real_T c1_xwork[256];
  int32_T c1_b_iwork[256];
  int32_T c1_b;
  int32_T c1_bLen;
  int32_T c1_bLen2;
  int32_T c1_b_b;
  int32_T c1_b_j;
  int32_T c1_b_k;
  int32_T c1_blockOffset;
  int32_T c1_c_b;
  int32_T c1_c_j;
  int32_T c1_d_b;
  int32_T c1_e_b;
  int32_T c1_exitg1;
  int32_T c1_f_b;
  int32_T c1_g_a;
  int32_T c1_g_b;
  int32_T c1_h_a;
  int32_T c1_iout;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_nPairs;
  int32_T c1_offset1;
  int32_T c1_p;
  int32_T c1_q;
  boolean_T c1_b_overflow;
  boolean_T c1_c_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  for (c1_b = 0; c1_b < 6; c1_b++) {
    c1_bLen = 1 << (c1_b + 2);
    c1_bLen2 = c1_bLen << 1;
    c1_nPairs = 256 >> (c1_b + 3);
    c1_st.site = &c1_if_emlrtRSI;
    c1_b_b = c1_nPairs;
    c1_c_b = c1_b_b;
    if (1 > c1_c_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_k = 1; c1_k - 1 < c1_nPairs; c1_k++) {
      c1_b_k = c1_k - 1;
      c1_blockOffset = (c1_offset + c1_b_k * c1_bLen2) - 1;
      c1_st.site = &c1_jf_emlrtRSI;
      c1_d_b = c1_bLen2;
      c1_e_b = c1_d_b;
      if (1 > c1_e_b) {
        c1_b_overflow = false;
      } else {
        c1_b_overflow = (c1_e_b > 2147483646);
      }

      if (c1_b_overflow) {
        c1_b_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
      }

      for (c1_j = 1; c1_j - 1 < c1_bLen2; c1_j++) {
        c1_b_j = c1_j;
        c1_b_iwork[c1_b_j - 1] = c1_b_idx->data[c1_blockOffset + c1_b_j];
        c1_xwork[c1_b_j - 1] = c1_c_x->data[c1_blockOffset + c1_b_j];
      }

      c1_p = 0;
      c1_q = c1_bLen;
      c1_iout = c1_blockOffset;
      do {
        c1_exitg1 = 0;
        c1_iout++;
        if (c1_xwork[c1_p] >= c1_xwork[c1_q]) {
          c1_b_idx->data[c1_iout] = c1_b_iwork[c1_p];
          c1_c_x->data[c1_iout] = c1_xwork[c1_p];
          if (c1_p + 1 < c1_bLen) {
            c1_p++;
          } else {
            c1_exitg1 = 1;
          }
        } else {
          c1_b_idx->data[c1_iout] = c1_b_iwork[c1_q];
          c1_c_x->data[c1_iout] = c1_xwork[c1_q];
          if (c1_q + 1 < c1_bLen2) {
            c1_q++;
          } else {
            c1_offset1 = c1_iout - c1_p;
            c1_st.site = &c1_kf_emlrtRSI;
            c1_g_a = c1_p + 1;
            c1_f_b = c1_bLen;
            c1_h_a = c1_g_a;
            c1_g_b = c1_f_b;
            if (c1_h_a > c1_g_b) {
              c1_c_overflow = false;
            } else {
              c1_c_overflow = (c1_g_b > 2147483646);
            }

            if (c1_c_overflow) {
              c1_b_st.site = &c1_kb_emlrtRSI;
              c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
            }

            for (c1_c_j = c1_p + 1; c1_c_j <= c1_bLen; c1_c_j++) {
              c1_b_idx->data[c1_offset1 + c1_c_j] = c1_b_iwork[c1_c_j - 1];
              c1_c_x->data[c1_offset1 + c1_c_j] = c1_xwork[c1_c_j - 1];
            }

            c1_exitg1 = 1;
          }
        }
      } while (c1_exitg1 == 0);
    }
  }
}

static void c1_d_merge_block(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx,
  c1_emxArray_real_T *c1_c_x, int32_T c1_offset, int32_T c1_n, int32_T
  c1_preSortLevel, c1_emxArray_int32_T *c1_b_iwork, c1_emxArray_real_T *c1_xwork)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b;
  int32_T c1_bLen;
  int32_T c1_bLen2;
  int32_T c1_b_b;
  int32_T c1_b_k;
  int32_T c1_k;
  int32_T c1_nBlocks;
  int32_T c1_nPairs;
  int32_T c1_nTail;
  int32_T c1_tailOffset;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_nBlocks = c1_n >> c1_preSortLevel;
  c1_bLen = 1 << c1_preSortLevel;
  while (c1_nBlocks > 1) {
    if ((c1_nBlocks & 1) != 0) {
      c1_nBlocks--;
      c1_tailOffset = c1_bLen * c1_nBlocks;
      c1_nTail = c1_n - c1_tailOffset;
      if (c1_nTail > c1_bLen) {
        c1_st.site = &c1_lf_emlrtRSI;
        c1_d_merge(chartInstance, &c1_st, c1_b_idx, c1_c_x, c1_offset +
                   c1_tailOffset, c1_bLen, c1_nTail - c1_bLen, c1_b_iwork,
                   c1_xwork);
      }
    }

    c1_bLen2 = c1_bLen << 1;
    c1_nPairs = c1_nBlocks >> 1;
    c1_st.site = &c1_mf_emlrtRSI;
    c1_b = c1_nPairs;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_k = 1; c1_k - 1 < c1_nPairs; c1_k++) {
      c1_b_k = c1_k - 1;
      c1_st.site = &c1_nf_emlrtRSI;
      c1_d_merge(chartInstance, &c1_st, c1_b_idx, c1_c_x, c1_offset + c1_b_k *
                 c1_bLen2, c1_bLen, c1_bLen, c1_b_iwork, c1_xwork);
    }

    c1_bLen = c1_bLen2;
    c1_nBlocks = c1_nPairs;
  }

  if (c1_n > c1_bLen) {
    c1_st.site = &c1_of_emlrtRSI;
    c1_d_merge(chartInstance, &c1_st, c1_b_idx, c1_c_x, c1_offset, c1_bLen, c1_n
               - c1_bLen, c1_b_iwork, c1_xwork);
  }
}

static void c1_d_merge(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_real_T
  *c1_c_x, int32_T c1_offset, int32_T c1_np, int32_T c1_nq, c1_emxArray_int32_T *
  c1_b_iwork, c1_emxArray_real_T *c1_xwork)
{
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_j;
  int32_T c1_c_b;
  int32_T c1_c_j;
  int32_T c1_d_b;
  int32_T c1_exitg1;
  int32_T c1_g_a;
  int32_T c1_h_a;
  int32_T c1_iout;
  int32_T c1_j;
  int32_T c1_n;
  int32_T c1_offset1;
  int32_T c1_p;
  int32_T c1_q;
  int32_T c1_qend;
  boolean_T c1_b_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  if (c1_nq != 0) {
    c1_n = c1_np + c1_nq;
    c1_st.site = &c1_qf_emlrtRSI;
    c1_b = c1_n;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_j = 1; c1_j - 1 < c1_n; c1_j++) {
      c1_b_j = c1_j - 1;
      c1_b_iwork->data[c1_b_j] = c1_b_idx->data[c1_offset + c1_b_j];
      c1_xwork->data[c1_b_j] = c1_c_x->data[c1_offset + c1_b_j];
    }

    c1_p = 0;
    c1_q = c1_np;
    c1_qend = c1_np + c1_nq;
    c1_iout = c1_offset - 1;
    do {
      c1_exitg1 = 0;
      c1_iout++;
      if (c1_xwork->data[c1_p] >= c1_xwork->data[c1_q]) {
        c1_b_idx->data[c1_iout] = c1_b_iwork->data[c1_p];
        c1_c_x->data[c1_iout] = c1_xwork->data[c1_p];
        if (c1_p + 1 < c1_np) {
          c1_p++;
        } else {
          c1_exitg1 = 1;
        }
      } else {
        c1_b_idx->data[c1_iout] = c1_b_iwork->data[c1_q];
        c1_c_x->data[c1_iout] = c1_xwork->data[c1_q];
        if (c1_q + 1 < c1_qend) {
          c1_q++;
        } else {
          c1_offset1 = c1_iout - c1_p;
          c1_st.site = &c1_pf_emlrtRSI;
          c1_g_a = c1_p + 1;
          c1_c_b = c1_np;
          c1_h_a = c1_g_a;
          c1_d_b = c1_c_b;
          if (c1_h_a > c1_d_b) {
            c1_b_overflow = false;
          } else {
            c1_b_overflow = (c1_d_b > 2147483646);
          }

          if (c1_b_overflow) {
            c1_b_st.site = &c1_kb_emlrtRSI;
            c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
          }

          for (c1_c_j = c1_p + 1; c1_c_j <= c1_np; c1_c_j++) {
            c1_b_idx->data[c1_offset1 + c1_c_j] = c1_b_iwork->data[c1_c_j - 1];
            c1_c_x->data[c1_offset1 + c1_c_j] = c1_xwork->data[c1_c_j - 1];
          }

          c1_exitg1 = 1;
        }
      }
    } while (c1_exitg1 == 0);
  }
}

static void c1_b_sortrows(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_y, real_T c1_d_varargin_1[2])
{
  static char_T c1_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 's', 's',
    'o', 'r', 't', 'e', 'd', 'r', 'o', 'w', 's', ':', 'C', 'o', 'l', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h', 'X' };

  c1_emxArray_int32_T *c1_b_idx;
  c1_emxArray_int32_T *c1_h_x;
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  real_T c1_b_k;
  real_T c1_c_x;
  real_T c1_ck;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  int32_T c1_col[2];
  int32_T c1_b_loop_ub;
  int32_T c1_exitg1;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_n;
  boolean_T c1_p;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_st.site = &c1_qk_emlrtRSI;
  c1_k = 0;
  do {
    c1_exitg1 = 0;
    if (c1_k < 2) {
      c1_b_k = (real_T)c1_k + 1.0;
      c1_c_x = c1_d_varargin_1[(int32_T)c1_b_k - 1];
      c1_d_x = c1_c_x;
      c1_e_x = c1_d_x;
      c1_ck = muDoubleScalarAbs(c1_e_x);
      c1_f_x = c1_ck;
      c1_g_x = c1_f_x;
      c1_g_x = muDoubleScalarFloor(c1_g_x);
      if ((c1_g_x != c1_ck) || (c1_ck < 1.0) || (c1_ck > 2.0)) {
        c1_p = false;
        c1_exitg1 = 1;
      } else {
        c1_k++;
      }
    } else {
      c1_p = true;
      c1_exitg1 = 1;
    }
  } while (c1_exitg1 == 0);

  if (!c1_p) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_cv, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    sf_mex_call(&c1_st, &c1_ib_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_col[c1_i] = (int32_T)c1_d_varargin_1[c1_i];
  }

  c1_emxInit_int32_T1(chartInstance, &c1_st, &c1_h_x, 2, &c1_xi_emlrtRTEI);
  c1_st.site = &c1_rk_emlrtRSI;
  c1_i1 = c1_h_x->size[0] * c1_h_x->size[1];
  c1_h_x->size[0] = c1_y->size[0];
  c1_h_x->size[1] = 2;
  c1_b_st.site = &c1_rk_emlrtRSI;
  c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_b_st, c1_h_x, c1_i1,
    &c1_xi_emlrtRTEI);
  c1_loop_ub = c1_y->size[0] * c1_y->size[1] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
    c1_h_x->data[c1_i2] = c1_y->data[c1_i2];
  }

  c1_emxInit_int32_T(chartInstance, &c1_st, &c1_b_idx, 1, &c1_yi_emlrtRTEI);
  c1_n = c1_h_x->size[0];
  c1_i3 = c1_b_idx->size[0];
  c1_b_idx->size[0] = c1_h_x->size[0];
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_b_idx, c1_i3,
    &c1_yi_emlrtRTEI);
  c1_b_loop_ub = c1_h_x->size[0] - 1;
  for (c1_i4 = 0; c1_i4 <= c1_b_loop_ub; c1_i4++) {
    c1_b_idx->data[c1_i4] = 0;
  }

  c1_b_st.site = &c1_tk_emlrtRSI;
  c1_d_mergesort(chartInstance, &c1_b_st, c1_b_idx, c1_h_x, c1_col, c1_n);
  c1_st.site = &c1_sk_emlrtRSI;
  c1_b_apply_row_permutation(chartInstance, &c1_st, c1_y, c1_b_idx);
  c1_emxFree_int32_T(chartInstance, &c1_h_x);
  c1_emxFree_int32_T(chartInstance, &c1_b_idx);
}

static void c1_d_mergesort(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_b_idx, c1_emxArray_int32_T
  *c1_c_x, int32_T c1_dir[2], int32_T c1_n)
{
  c1_emxArray_int32_T *c1_b_iwork;
  c1_emxArray_int32_T *c1_d_x;
  c1_emxArray_int32_T *c1_e_x;
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_b_dir[2];
  int32_T c1_c_dir[2];
  int32_T c1_iv[1];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_i;
  int32_T c1_b_i2;
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_c_k;
  int32_T c1_c_loop_ub;
  int32_T c1_g_a;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_j;
  int32_T c1_k;
  int32_T c1_kEnd;
  int32_T c1_len;
  int32_T c1_loop_ub;
  int32_T c1_np1;
  int32_T c1_p;
  int32_T c1_pEnd;
  int32_T c1_q;
  int32_T c1_qEnd;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_emxInit_int32_T(chartInstance, c1_sp, &c1_b_iwork, 1, &c1_cj_emlrtRTEI);
  c1_i = c1_b_iwork->size[0];
  c1_b_iwork->size[0] = c1_b_idx->size[0];
  c1_st.site = &c1_ul_emlrtRSI;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_b_iwork, c1_i,
    &c1_aj_emlrtRTEI);
  c1_loop_ub = c1_b_idx->size[0] - 1;
  for (c1_i1 = 0; c1_i1 <= c1_loop_ub; c1_i1++) {
    c1_b_iwork->data[c1_i1] = c1_b_idx->data[c1_i1];
  }

  c1_len = c1_b_iwork->size[0];
  c1_i2 = c1_b_iwork->size[0];
  c1_b_iwork->size[0] = c1_len;
  c1_emxEnsureCapacity_int32_T(chartInstance, c1_sp, c1_b_iwork, c1_i2,
    &c1_bj_emlrtRTEI);
  c1_iv[0] = c1_b_iwork->size[0];
  c1_i3 = c1_b_iwork->size[0];
  c1_b_iwork->size[0] = c1_iv[0];
  c1_st.site = &c1_ul_emlrtRSI;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_b_iwork, c1_i3,
    &c1_cj_emlrtRTEI);
  c1_np1 = c1_n + 1;
  c1_i4 = c1_n;
  c1_k = 1;
  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_d_x, 2, &c1_dj_emlrtRTEI);
  while (c1_k <= c1_i4 - 1) {
    c1_i5 = c1_d_x->size[0] * c1_d_x->size[1];
    c1_d_x->size[0] = c1_c_x->size[0];
    c1_d_x->size[1] = 2;
    c1_st.site = &c1_fm_emlrtRSI;
    c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_d_x, c1_i5,
      &c1_dj_emlrtRTEI);
    c1_b_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
    for (c1_i6 = 0; c1_i6 <= c1_b_loop_ub; c1_i6++) {
      c1_d_x->data[c1_i6] = c1_c_x->data[c1_i6];
    }

    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_b_dir[c1_i7] = c1_dir[c1_i7];
    }

    if (c1_sortLE(chartInstance, c1_d_x, c1_b_dir, c1_k, c1_k + 1)) {
      c1_b_idx->data[c1_k - 1] = c1_k;
      c1_b_idx->data[c1_k] = c1_k + 1;
    } else {
      c1_b_idx->data[c1_k - 1] = c1_k + 1;
      c1_b_idx->data[c1_k] = c1_k;
    }

    c1_k += 2;
  }

  c1_emxFree_int32_T(chartInstance, &c1_d_x);
  if ((c1_n & 1) != 0) {
    c1_b_idx->data[c1_n - 1] = c1_n;
  }

  c1_b_i = 2;
  c1_emxInit_int32_T1(chartInstance, c1_sp, &c1_e_x, 2, &c1_dj_emlrtRTEI);
  while (c1_b_i < c1_n) {
    c1_g_a = c1_b_i;
    c1_b_i2 = c1_g_a << 1;
    c1_j = 1;
    for (c1_pEnd = 1 + c1_b_i; c1_pEnd < c1_np1; c1_pEnd = c1_qEnd + c1_b_i) {
      c1_p = c1_j - 1;
      c1_q = c1_pEnd - 1;
      c1_qEnd = c1_j + c1_b_i2;
      if (c1_qEnd > c1_np1) {
        c1_qEnd = c1_np1;
      }

      c1_b_k = 0;
      c1_kEnd = c1_qEnd - c1_j;
      while (c1_b_k + 1 <= c1_kEnd) {
        c1_i8 = c1_e_x->size[0] * c1_e_x->size[1];
        c1_e_x->size[0] = c1_c_x->size[0];
        c1_e_x->size[1] = 2;
        c1_st.site = &c1_fm_emlrtRSI;
        c1_emxEnsureCapacity_int32_T1(chartInstance, &c1_st, c1_e_x, c1_i8,
          &c1_dj_emlrtRTEI);
        c1_c_loop_ub = c1_c_x->size[0] * c1_c_x->size[1] - 1;
        for (c1_i9 = 0; c1_i9 <= c1_c_loop_ub; c1_i9++) {
          c1_e_x->data[c1_i9] = c1_c_x->data[c1_i9];
        }

        for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
          c1_c_dir[c1_i10] = c1_dir[c1_i10];
        }

        if (c1_sortLE(chartInstance, c1_e_x, c1_c_dir, c1_b_idx->data[c1_p],
                      c1_b_idx->data[c1_q])) {
          c1_b_iwork->data[c1_b_k] = c1_b_idx->data[c1_p];
          c1_p++;
          if (c1_p + 1 == c1_pEnd) {
            while (c1_q + 1 < c1_qEnd) {
              c1_b_k++;
              c1_b_iwork->data[c1_b_k] = c1_b_idx->data[c1_q];
              c1_q++;
            }
          }
        } else {
          c1_b_iwork->data[c1_b_k] = c1_b_idx->data[c1_q];
          c1_q++;
          if (c1_q + 1 == c1_qEnd) {
            while (c1_p + 1 < c1_pEnd) {
              c1_b_k++;
              c1_b_iwork->data[c1_b_k] = c1_b_idx->data[c1_p];
              c1_p++;
            }
          }
        }

        c1_b_k++;
      }

      c1_p = c1_j - 2;
      c1_st.site = &c1_ud_emlrtRSI;
      c1_b = c1_kEnd;
      c1_b_b = c1_b;
      if (1 > c1_b_b) {
        c1_overflow = false;
      } else {
        c1_overflow = (c1_b_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_st.site = &c1_kb_emlrtRSI;
        c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
      }

      for (c1_c_k = 1; c1_c_k - 1 < c1_kEnd; c1_c_k++) {
        c1_b_k = c1_c_k;
        c1_b_idx->data[c1_p + c1_b_k] = c1_b_iwork->data[c1_b_k - 1];
      }

      c1_j = c1_qEnd;
    }

    c1_b_i = c1_b_i2;
  }

  c1_emxFree_int32_T(chartInstance, &c1_e_x);
  c1_emxFree_int32_T(chartInstance, &c1_b_iwork);
}

static void c1_b_apply_row_permutation(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_y,
  c1_emxArray_int32_T *c1_b_idx)
{
  c1_emxArray_int32_T *c1_ycol;
  emlrtStack c1_b_st;
  emlrtStack c1_st;
  int32_T c1_iv[2];
  int32_T c1_b;
  int32_T c1_b_b;
  int32_T c1_b_i;
  int32_T c1_b_j;
  int32_T c1_c_b;
  int32_T c1_c_i;
  int32_T c1_d_b;
  int32_T c1_d_i;
  int32_T c1_i;
  int32_T c1_j;
  int32_T c1_m;
  boolean_T c1_b_overflow;
  boolean_T c1_overflow;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_emxInit_int32_T(chartInstance, c1_sp, &c1_ycol, 1, &c1_fj_emlrtRTEI);
  c1_m = c1_y->size[0];
  c1_iv[0] = c1_m;
  c1_i = c1_ycol->size[0];
  c1_ycol->size[0] = c1_iv[0];
  c1_st.site = &c1_tl_emlrtRSI;
  c1_emxEnsureCapacity_int32_T(chartInstance, &c1_st, c1_ycol, c1_i,
    &c1_ej_emlrtRTEI);
  for (c1_j = 0; c1_j < 2; c1_j++) {
    c1_b_j = c1_j;
    c1_st.site = &c1_uk_emlrtRSI;
    c1_b = c1_m;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = false;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_b_i = 1; c1_b_i - 1 < c1_m; c1_b_i++) {
      c1_c_i = c1_b_i - 1;
      c1_ycol->data[c1_c_i] = c1_y->data[(c1_b_idx->data[c1_c_i] + c1_y->size[0]
        * c1_b_j) - 1];
    }

    c1_st.site = &c1_vk_emlrtRSI;
    c1_c_b = c1_m;
    c1_d_b = c1_c_b;
    if (1 > c1_d_b) {
      c1_b_overflow = false;
    } else {
      c1_b_overflow = (c1_d_b > 2147483646);
    }

    if (c1_b_overflow) {
      c1_b_st.site = &c1_kb_emlrtRSI;
      c1_check_forloop_overflow_error(chartInstance, &c1_b_st);
    }

    for (c1_d_i = 1; c1_d_i - 1 < c1_m; c1_d_i++) {
      c1_c_i = c1_d_i - 1;
      c1_y->data[c1_c_i + c1_y->size[0] * c1_b_j] = c1_ycol->data[c1_c_i];
    }
  }

  c1_emxFree_int32_T(chartInstance, &c1_ycol);
}

static void c1_emxEnsureCapacity_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(real_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_real_T *)emlrtMallocMex(sizeof(c1_emxArray_real_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_skoeQIuVNKJRHNtBIlOCZhD
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_skoeQIuVNKJRHNtBIlOCZh **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *)emlrtMallocMex(sizeof
    (c1_emxArray_skoeQIuVNKJRHNtBIlOCZh));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (c1_skoeQIuVNKJRHNtBIlOCZhD *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_real_T *)emlrtMallocMex(sizeof(c1_emxArray_real_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFree_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_real_T *)NULL) {
    if (((*c1_pEmxArray)->data != (real_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_real_T *)NULL;
  }
}

static void c1_emxFree_skoeQIuVNKJRHNtBIlOCZhD
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_skoeQIuVNKJRHNtBIlOCZh **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *)NULL) {
    if (((*c1_pEmxArray)->data != (c1_skoeQIuVNKJRHNtBIlOCZhD *)NULL) &&
        (*c1_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *)NULL;
  }
}

static void c1_emxEnsureCapacity_real32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(real32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_real32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real32_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_real32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFree_real32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real32_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_real32_T *)NULL) {
    if (((*c1_pEmxArray)->data != (real32_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_real32_T *)NULL;
  }
}

static void c1_emxEnsureCapacity_creal_T(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_creal_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(creal_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(creal_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (creal_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_real_T1(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(real_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_boolean_T
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_boolean_T *c1_emxArray, int32_T c1_oldNumel, const
   emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(boolean_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (boolean_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_int32_T(SFc1_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(int32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(int32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (int32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_boolean_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_boolean_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_boolean_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c1_emxArray_boolean_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (boolean_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_int32_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_int32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (int32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_creal_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_creal_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_creal_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c1_emxArray_creal_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (creal_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFree_boolean_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_boolean_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_boolean_T *)NULL) {
    if (((*c1_pEmxArray)->data != (boolean_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_boolean_T *)NULL;
  }
}

static void c1_emxFree_int32_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_int32_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_int32_T *)NULL) {
    if (((*c1_pEmxArray)->data != (int32_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_int32_T *)NULL;
  }
}

static void c1_emxFree_creal_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_creal_T **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_creal_T *)NULL) {
    if (((*c1_pEmxArray)->data != (creal_T *)NULL) && (*c1_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_creal_T *)NULL;
  }
}

static void c1_emxEnsureCapacity_real32_T1
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_real32_T *c1_emxArray, int32_T c1_oldNumel, const
   emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(real32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(real32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (real32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_creal_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_creal_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(creal_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(creal_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (creal_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_real32_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_real32_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_real32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (real32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_creal_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_creal_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_creal_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c1_emxArray_creal_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (creal_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxEnsureCapacity_int32_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T *c1_emxArray,
  int32_T c1_oldNumel, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(int32_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(int32_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (int32_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_sBO2RC5RVZVTbundPSRqHnH
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_sBO2RC5RVZVTbundPSRqHn **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_sBO2RC5RVZVTbundPSRqHn *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_sBO2RC5RVZVTbundPSRqHn *)emlrtMallocMex(sizeof
    (c1_emxArray_sBO2RC5RVZVTbundPSRqHn));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (c1_sBO2RC5RVZVTbundPSRqHnH *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxInit_int32_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_int32_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_int32_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c1_emxArray_int32_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (int32_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFree_sBO2RC5RVZVTbundPSRqHnH
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_sBO2RC5RVZVTbundPSRqHn **c1_pEmxArray)
{
  (void)chartInstance;
  if (*c1_pEmxArray != (c1_emxArray_sBO2RC5RVZVTbundPSRqHn *)NULL) {
    if (((*c1_pEmxArray)->data != (c1_sBO2RC5RVZVTbundPSRqHnH *)NULL) &&
        (*c1_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c1_pEmxArray)->data);
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_sBO2RC5RVZVTbundPSRqHn *)NULL;
  }
}

static void c1_emxInitStruct_s_VSLwMee4Kv1oTF0
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s_VSLwMee4Kv1oTF0BcoITHB *c1_pStruct, const emlrtRTEInfo
   *c1_srcLocation)
{
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_pStruct->RegionIndices, 1,
                     c1_srcLocation);
  c1_emxInit_int32_T(chartInstance, c1_sp, &c1_pStruct->RegionLengths, 1,
                     c1_srcLocation);
}

static void c1_emxInit_s_nrlUwWofUDGxo1t78e6dw
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s_nrlUwWofUDGxo1t78e6d **c1_pEmxArray, int32_T
   c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_s_nrlUwWofUDGxo1t78e6d *)emlrtMallocMex(sizeof
    (c1_emxArray_s_nrlUwWofUDGxo1t78e6d));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (c1_s_nrlUwWofUDGxo1t78e6dwC *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxFreeStruct_s_VSLwMee4Kv1oTF0
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_VSLwMee4Kv1oTF0BcoITHB *c1_pStruct)
{
  c1_emxFree_real_T(chartInstance, &c1_pStruct->RegionIndices);
  c1_emxFree_int32_T(chartInstance, &c1_pStruct->RegionLengths);
}

static void c1_emxFree_s_nrlUwWofUDGxo1t78e6dw
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_s_nrlUwWofUDGxo1t78e6d **c1_pEmxArray)
{
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_numEl;
  if (*c1_pEmxArray != (c1_emxArray_s_nrlUwWofUDGxo1t78e6d *)NULL) {
    if ((*c1_pEmxArray)->data != (c1_s_nrlUwWofUDGxo1t78e6dwC *)NULL) {
      c1_numEl = 1;
      for (c1_i = 0; c1_i < (*c1_pEmxArray)->numDimensions; c1_i++) {
        c1_numEl *= (*c1_pEmxArray)->size[c1_i];
      }

      for (c1_b_i = 0; c1_b_i < c1_numEl; c1_b_i++) {
        c1_emxFreeStruct_s_nrlUwWofUDGxo1t(chartInstance, &(*c1_pEmxArray)->
          data[c1_b_i]);
      }

      if ((*c1_pEmxArray)->canFreeData) {
        emlrtFreeMex((*c1_pEmxArray)->data);
      }
    }

    emlrtFreeMex((*c1_pEmxArray)->size);
    emlrtFreeMex(*c1_pEmxArray);
    *c1_pEmxArray = (c1_emxArray_s_nrlUwWofUDGxo1t78e6d *)NULL;
  }
}

static void c1_emxFreeStruct_s_nrlUwWofUDGxo1t
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_s_nrlUwWofUDGxo1t78e6dwC *c1_pStruct)
{
  c1_emxFree_real_T(chartInstance, &c1_pStruct->PixelIdxList);
  c1_emxFree_real_T(chartInstance, &c1_pStruct->PixelList);
  c1_emxFree_real_T(chartInstance, &c1_pStruct->PixelValues);
}

static void c1_emxEnsureCapacity_boolean_T1
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_boolean_T *c1_emxArray, int32_T c1_oldNumel, const
   emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof(boolean_T));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (boolean_T *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxEnsureCapacity_sBO2RC5RVZVTb
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_sBO2RC5RVZVTbundPSRqHn *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof
      (c1_sBO2RC5RVZVTbundPSRqHnH));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(c1_sBO2RC5RVZVTbundPSRqHnH) *
             (uint32_T)c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (c1_sBO2RC5RVZVTbundPSRqHnH *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInit_boolean_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_boolean_T **c1_pEmxArray,
  int32_T c1_numDimensions, const emlrtRTEInfo *c1_srcLocation)
{
  c1_emxArray_boolean_T *c1_emxArray;
  int32_T c1_i;
  (void)chartInstance;
  *c1_pEmxArray = (c1_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c1_emxArray_boolean_T));
  if ((void *)*c1_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray = *c1_pEmxArray;
  c1_emxArray->data = (boolean_T *)NULL;
  c1_emxArray->numDimensions = c1_numDimensions;
  c1_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c1_numDimensions);
  if ((void *)c1_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
  }

  c1_emxArray->allocatedSize = 0;
  c1_emxArray->canFreeData = true;
  for (c1_i = 0; c1_i < c1_numDimensions; c1_i++) {
    c1_emxArray->size[c1_i] = 0;
  }
}

static void c1_emxTrim_s_nrlUwWofUDGxo1t78e6dw
  (SFc1_flightControlSystemInstanceStruct *chartInstance,
   c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_emxArray, int32_T c1_fromIndex,
   int32_T c1_toIndex)
{
  int32_T c1_i;
  for (c1_i = c1_fromIndex; c1_i < c1_toIndex; c1_i++) {
    c1_emxFreeStruct_s_nrlUwWofUDGxo1t(chartInstance, &c1_emxArray->data[c1_i]);
  }
}

static void c1_emxInitStruct_s_nrlUwWofUDGxo1t
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s_nrlUwWofUDGxo1t78e6dwC *c1_pStruct, const emlrtRTEInfo
   *c1_srcLocation)
{
  c1_pStruct->Image.size[0] = 0;
  c1_pStruct->Image.size[1] = 0;
  c1_pStruct->FilledImage.size[0] = 0;
  c1_pStruct->FilledImage.size[1] = 0;
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_pStruct->PixelIdxList, 1,
                     c1_srcLocation);
  c1_emxInit_real_T(chartInstance, c1_sp, &c1_pStruct->PixelList, 2,
                    c1_srcLocation);
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_pStruct->PixelValues, 1,
                     c1_srcLocation);
  c1_pStruct->SubarrayIdx.size[0] = 0;
  c1_pStruct->SubarrayIdx.size[1] = 0;
}

static void c1_emxExpand_s_nrlUwWofUDGxo1t78e6
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_emxArray, int32_T c1_fromIndex,
   int32_T c1_toIndex, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  for (c1_i = c1_fromIndex; c1_i < c1_toIndex; c1_i++) {
    c1_emxInitStruct_s_nrlUwWofUDGxo1t(chartInstance, c1_sp, &c1_emxArray->
      data[c1_i], c1_srcLocation);
  }
}

static void c1_emxEnsureCapacity_s_nrlUwWofUDG
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_s_nrlUwWofUDGxo1t78e6d *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof
      (c1_s_nrlUwWofUDGxo1t78e6dwC));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(c1_s_nrlUwWofUDGxo1t78e6dwC) *
             (uint32_T)c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (c1_s_nrlUwWofUDGxo1t78e6dwC *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }

  if (c1_oldNumel > c1_newNumel) {
    c1_emxTrim_s_nrlUwWofUDGxo1t78e6dw(chartInstance, c1_emxArray, c1_newNumel,
      c1_oldNumel);
  } else {
    if (c1_oldNumel < c1_newNumel) {
      c1_emxExpand_s_nrlUwWofUDGxo1t78e6(chartInstance, c1_sp, c1_emxArray,
        c1_oldNumel, c1_newNumel, c1_srcLocation);
    }
  }
}

static void c1_emxCopyStruct_s_nrlUwWofUDGxo1t
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_s_nrlUwWofUDGxo1t78e6dwC *c1_dst, const
   c1_s_nrlUwWofUDGxo1t78e6dwC *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  c1_dst->Area = c1_src->Area;
  c1_emxCopyMatrix_real_T(chartInstance, c1_dst->Centroid, c1_src->Centroid);
  c1_emxCopyMatrix_real_T1(chartInstance, c1_dst->BoundingBox,
    c1_src->BoundingBox);
  c1_dst->MajorAxisLength = c1_src->MajorAxisLength;
  c1_dst->MinorAxisLength = c1_src->MinorAxisLength;
  c1_dst->Eccentricity = c1_src->Eccentricity;
  c1_dst->Orientation = c1_src->Orientation;
  c1_emxCopy_boolean_T_0x0(chartInstance, &c1_dst->Image, &c1_src->Image);
  c1_emxCopy_boolean_T_0x0(chartInstance, &c1_dst->FilledImage,
    &c1_src->FilledImage);
  c1_dst->FilledArea = c1_src->FilledArea;
  c1_dst->EulerNumber = c1_src->EulerNumber;
  c1_emxCopyMatrix_real_T2(chartInstance, c1_dst->Extrema, c1_src->Extrema);
  c1_dst->EquivDiameter = c1_src->EquivDiameter;
  c1_dst->Extent = c1_src->Extent;
  c1_emxCopy_real_T(chartInstance, c1_sp, &c1_dst->PixelIdxList,
                    &c1_src->PixelIdxList, c1_srcLocation);
  c1_emxCopy_real_T1(chartInstance, c1_sp, &c1_dst->PixelList,
                     &c1_src->PixelList, c1_srcLocation);
  c1_dst->Perimeter = c1_src->Perimeter;
  c1_dst->Circularity = c1_src->Circularity;
  c1_emxCopy_real_T(chartInstance, c1_sp, &c1_dst->PixelValues,
                    &c1_src->PixelValues, c1_srcLocation);
  c1_emxCopyMatrix_real_T(chartInstance, c1_dst->WeightedCentroid,
    c1_src->WeightedCentroid);
  c1_dst->MeanIntensity = c1_src->MeanIntensity;
  c1_dst->MinIntensity = c1_src->MinIntensity;
  c1_dst->MaxIntensity = c1_src->MaxIntensity;
  c1_emxCopy_real_T_1x0(chartInstance, &c1_dst->SubarrayIdx,
                        &c1_src->SubarrayIdx);
  c1_emxCopyMatrix_real_T(chartInstance, c1_dst->SubarrayIdxLengths,
    c1_src->SubarrayIdxLengths);
}

static void c1_emxCopyMatrix_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[2], const real_T c1_src[2])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_emxCopyMatrix_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[4], const real_T c1_src[4])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 4; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_emxCopy_boolean_T_0x0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_boolean_T_0x0 *c1_dst, const
  c1_emxArray_boolean_T_0x0 *c1_src)
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dst->size[c1_i] = c1_src->size[c1_i];
  }
}

static void c1_emxCopyMatrix_real_T2(SFc1_flightControlSystemInstanceStruct
  *chartInstance, real_T c1_dst[16], const real_T c1_src[16])
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 16; c1_i++) {
    c1_dst[c1_i] = c1_src[c1_i];
  }
}

static void c1_emxCopy_real_T(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_dst,
  c1_emxArray_real_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_numElDst;
  int32_T c1_numElSrc;
  c1_numElDst = 1;
  c1_numElSrc = 1;
  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    c1_numElDst *= (*c1_dst)->size[c1_i];
    c1_numElSrc *= (*c1_src)->size[c1_i];
  }

  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    (*c1_dst)->size[c1_i] = (*c1_src)->size[c1_i];
  }

  c1_emxEnsureCapacity_real_T(chartInstance, c1_sp, *c1_dst, c1_numElDst,
    c1_srcLocation);
  for (c1_i = 0; c1_i < c1_numElSrc; c1_i++) {
    (*c1_dst)->data[c1_i] = (*c1_src)->data[c1_i];
  }
}

static void c1_emxCopy_real_T1(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_emxArray_real_T **c1_dst,
  c1_emxArray_real_T * const *c1_src, const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_numElDst;
  int32_T c1_numElSrc;
  c1_numElDst = 1;
  c1_numElSrc = 1;
  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    c1_numElDst *= (*c1_dst)->size[c1_i];
    c1_numElSrc *= (*c1_src)->size[c1_i];
  }

  for (c1_i = 0; c1_i < (*c1_dst)->numDimensions; c1_i++) {
    (*c1_dst)->size[c1_i] = (*c1_src)->size[c1_i];
  }

  c1_emxEnsureCapacity_real_T1(chartInstance, c1_sp, *c1_dst, c1_numElDst,
    c1_srcLocation);
  for (c1_i = 0; c1_i < c1_numElSrc; c1_i++) {
    (*c1_dst)->data[c1_i] = (*c1_src)->data[c1_i];
  }
}

static void c1_emxCopy_real_T_1x0(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_emxArray_real_T_1x0 *c1_dst, const c1_emxArray_real_T_1x0
  *c1_src)
{
  int32_T c1_i;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_dst->size[c1_i] = c1_src->size[c1_i];
  }
}

static void c1_emxEnsureCapacity_skoeQIuVNKJRH
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c1_sp, c1_emxArray_skoeQIuVNKJRHNtBIlOCZh *c1_emxArray, int32_T c1_oldNumel,
   const emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  int32_T c1_newCapacity;
  int32_T c1_newNumel;
  void *c1_newData;
  (void)chartInstance;
  if (c1_oldNumel < 0) {
    c1_oldNumel = 0;
  }

  c1_newNumel = 1;
  for (c1_i = 0; c1_i < c1_emxArray->numDimensions; c1_i++) {
    c1_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c1_newNumel, (uint32_T)
      c1_emxArray->size[c1_i], c1_srcLocation, c1_sp);
  }

  if (c1_newNumel > c1_emxArray->allocatedSize) {
    c1_newCapacity = c1_emxArray->allocatedSize;
    if (c1_newCapacity < 16) {
      c1_newCapacity = 16;
    }

    while (c1_newCapacity < c1_newNumel) {
      if (c1_newCapacity > 1073741823) {
        c1_newCapacity = MAX_int32_T;
      } else {
        c1_newCapacity <<= 1;
      }
    }

    c1_newData = emlrtCallocMex((uint32_T)c1_newCapacity, sizeof
      (c1_skoeQIuVNKJRHNtBIlOCZhD));
    if (c1_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c1_srcLocation, c1_sp);
    }

    if (c1_emxArray->data != NULL) {
      memcpy(c1_newData, c1_emxArray->data, sizeof(c1_skoeQIuVNKJRHNtBIlOCZhD) *
             (uint32_T)c1_oldNumel);
      if (c1_emxArray->canFreeData) {
        emlrtFreeMex(c1_emxArray->data);
      }
    }

    c1_emxArray->data = (c1_skoeQIuVNKJRHNtBIlOCZhD *)c1_newData;
    c1_emxArray->allocatedSize = c1_newCapacity;
    c1_emxArray->canFreeData = true;
  }
}

static void c1_emxInitMatrix_cell_wrap_52(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_52 c1_pMatrix[2], const
  emlrtRTEInfo *c1_srcLocation)
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_emxInitStruct_cell_wrap_52(chartInstance, c1_sp, &c1_pMatrix[c1_i],
      c1_srcLocation);
  }
}

static void c1_emxInitStruct_cell_wrap_52(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c1_sp, c1_cell_wrap_52 *c1_pStruct, const
  emlrtRTEInfo *c1_srcLocation)
{
  c1_emxInit_real_T1(chartInstance, c1_sp, &c1_pStruct->f1, 1, c1_srcLocation);
}

static void c1_emxFreeMatrix_cell_wrap_52(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_cell_wrap_52 c1_pMatrix[2])
{
  int32_T c1_i;
  for (c1_i = 0; c1_i < 2; c1_i++) {
    c1_emxFreeStruct_cell_wrap_52(chartInstance, &c1_pMatrix[c1_i]);
  }
}

static void c1_emxFreeStruct_cell_wrap_52(SFc1_flightControlSystemInstanceStruct
  *chartInstance, c1_cell_wrap_52 *c1_pStruct)
{
  c1_emxFree_real_T(chartInstance, &c1_pStruct->f1);
}

static int32_T c1_div_nzp_s32(SFc1_flightControlSystemInstanceStruct
  *chartInstance, int32_T c1_numerator, int32_T c1_denominator, int32_T
  c1_EMLOvCount_src_loc, uint32_T c1_ssid_src_loc, int32_T c1_offset_src_loc,
  int32_T c1_length_src_loc)
{
  int32_T c1_quotient;
  uint32_T c1_absDenominator;
  uint32_T c1_absNumerator;
  uint32_T c1_tempAbsQuotient;
  boolean_T c1_quotientNeedsNegation;
  (void)chartInstance;
  (void)c1_EMLOvCount_src_loc;
  (void)c1_ssid_src_loc;
  (void)c1_offset_src_loc;
  (void)c1_length_src_loc;
  if (c1_numerator < 0) {
    c1_absNumerator = ~(uint32_T)c1_numerator + 1U;
  } else {
    c1_absNumerator = (uint32_T)c1_numerator;
  }

  if (c1_denominator < 0) {
    c1_absDenominator = ~(uint32_T)c1_denominator + 1U;
  } else {
    c1_absDenominator = (uint32_T)c1_denominator;
  }

  c1_quotientNeedsNegation = ((c1_numerator < 0) != (c1_denominator < 0));
  c1_tempAbsQuotient = c1_absNumerator / c1_absDenominator;
  if (c1_quotientNeedsNegation) {
    c1_quotient = -(int32_T)c1_tempAbsQuotient;
  } else {
    c1_quotient = (int32_T)c1_tempAbsQuotient;
  }

  return c1_quotient;
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_b_u = (real_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_data = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_output_angle = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_mode = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_data1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_angle_ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_angelina = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2434211055U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3122814856U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1753695946U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1553973715U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,11);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.CannyThresholdingTbbBuildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 6, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  mxSetCell(mxcell3p, 7, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 8, mxCreateString(
             "images.internal.coder.buildable.TbbhistBuildable"));
  mxSetCell(mxcell3p, 9, mxCreateString(
             "images.internal.coder.buildable.Ordfilt2Buildable"));
  mxSetCell(mxcell3p, 10, mxCreateString(
             "images.internal.coder.buildable.ImregionalmaxBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("grayto8_real64");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCOYGFgYAPSHEDMxAABrFA+I5TNCBdngYsrAHFJZUEqSLy4KNkzBUjnJeaC+Ym"
    "lFZ55aflg8y0YEOazYTGfEcl8Tqg4BHywp0y/mgO6fhYs+jmQ9AtA+Yl56ak5mXmJfFDxgfWHEl"
    "H+YEXzB4ifkliSaAh1/8D7QwvsDwMC/mBB8QcLQ25+SurgcL8I2P0OBNzPgxYPIH5+aUlBaUk8M"
    "FnlpDJQLT4UHCjTD7E/gIB/FND8A+JnFscnJpdklqXGJxvGp+VkpmeUOOfnlRTl5wRXFpek5sL8"
    "BwCFdTDY"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sVLnEaUYmsVrvEPcpjeIhmF";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrtV0tv41QUdtp01JFK1cVIbJCoWAyIFSMEYgWZ5iEipdMIpwVW1a19El9yH+Y+3GbJCokd/2J",
    "+ABL7+RX8BzazRkLiXNtNU8d2GsLMFIQl1732d7573vfEa/SPPbz28X75yPMe4HMX7y0vu3bydW",
    "Phzt43vffz9S8oJCwfEkW49movQTh8BVoya6gUfTGWpTAqxqBABIiNpTJVbJpyy6iY9qwIHJ/+O",
    "qJB5EfSsvAIZUl4ItgM2WJrhsjToQoC0wMITaSknUQ9RiZzjZW5bEcQTLXldSZoML6NnVr62DJD",
    "YwbdKwj6QhuCGusb3XxDDLTNVaWZzlLtXwMljxklotTaiGgfYnSwgdM4xL8n1qBRRVgQEWWOICI",
    "J6AGdppxSQJGTavxwQQUxUlHCupy1neCybkOG+hzLEFiNQ1C3IwVkGksqTHX8/R5a2hXkgkEHLu",
    "ykms2H760L/hmFS1CVfhu3ZQKKTOBEVG6aOqR7lUZrniXLMEM5nBH1NMD4aQgrsxczR/sE4wQjl",
    "KiCQWpkX48UTdC9lWyW911mrioZy7Ng61WwlK2bQF0U5my9QLQJY7oSNpLxABJgKWuHGFIPy1jL",
    "cVrTcCTRwS69q6vBCoqBz2FtKUJaGq6kAEj7zjNsLLeRgdVG8jYmb2cwWP68DOsLA2pMAijrAop",
    "QDeiz1L3VbCHVLvYIRK1Mql4ZOMuQVShPj63oXEo1RZ/UNJEbE1xEK4FcTzCWWAmnGoumDuZiuQ",
    "oXkCCC0DUYyuAYywaxJT7RrrU9xbpLqJl1QAeKxiVRtVh12Ia6LqFmMZyKqZCXoqck9/Men0UBO",
    "wP2cI4xGKU1JgKkotpgu6A324cAmJRECSomR9jm1KyHSpZGzJ17H3k3597eHc69a7ni84MFnkYJ",
    "j7fwLO77cOs2fruw7xa+aTQaqVxrQe6twj7NgpzDHeD96e/bPw7++PPjHz759acXz/d+XrV/Y2n",
    "/Rvq/k9vdWW9O2M/X71w35HmBJUt57bBfLujVLOF/e4H/IF/rs4HoktNvuT5TSXcYxN9BP+K9lO",
    "+bZr2+OwV9r98fupMBszHNYxX0w3yAcWtis2Pd8X+2oO+DFf54mL/PrpdfbCb/uFWUL/PXbsFfb",
    "k3EBLCsyGL+vjk73ruTHTsFO9waZyHypFCHb86OD1vFuiqzo3nLjqbHsXPfD/0ftYr9pUz/vUIc",
    "3Fqmx/85phUD7x+Lx2FrM/ls/+EKew4L9hym8+U5cacWnAdPzseMTiI3cBglmT/D44bv37GP1/X",
    "RdeW81yz3b9Hzf7+8evvuMhdt/0255oZz2OuS29S+defD+4avO9e8Av7gHtux6dz+qvG/eevN1+",
    "/m68/nP7XbEWVhya+u/DP+NhqXff2P5Ok6+L8A+yLV/g==",
    ""
  };

  static char newstr [1397] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2265180982U));
  ssSetChecksum1(S,(872282700U));
  ssSetChecksum2(S,(2327262593U));
  ssSetChecksum3(S,(2433525954U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c1_JITStateAnimation,
    chartInstance->c1_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
