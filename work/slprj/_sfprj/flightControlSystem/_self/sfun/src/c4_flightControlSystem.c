/* Include files */

#include "flightControlSystem_sfun.h"
#include "c4_flightControlSystem.h"
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
static emlrtMCInfo c4_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatefinite.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnegative",               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnegative.m"/* pName */
};

static emlrtMCInfo c4_c_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtMCInfo c4_d_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtMCInfo c4_e_emlrtMCI = { 88,/* lineNo */
  9,                                   /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c4_f_emlrtMCI = { 121,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c4_g_emlrtMCI = { 85,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c4_h_emlrtMCI = { 184,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c4_i_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

static emlrtMCInfo c4_j_emlrtMCI = { 41,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtMCInfo c4_k_emlrtMCI = { 31,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtMCInfo c4_l_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c4_m_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnan.m"/* pName */
};

static emlrtMCInfo c4_n_emlrtMCI = { 1271,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtMCInfo c4_o_emlrtMCI = { 47,/* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtMCInfo c4_p_emlrtMCI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c4_q_emlrtMCI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c4_r_emlrtMCI = { 38,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtMCInfo c4_s_emlrtMCI = { 283,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtMCInfo c4_t_emlrtMCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pName */
};

static emlrtMCInfo c4_u_emlrtMCI = { 81,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c4_v_emlrtMCI = { 297,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c4_w_emlrtMCI = { 81,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtMCInfo c4_x_emlrtMCI = { 392,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtMCInfo c4_y_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validateinteger.m"/* pName */
};

static emlrtMCInfo c4_ab_emlrtMCI = { 395,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pName */
};

static emlrtMCInfo c4_bb_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validatepositive.m"/* pName */
};

static emlrtMCInfo c4_cb_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validateodd",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/+valattr/validateodd.m"/* pName */
};

static emlrtMCInfo c4_db_emlrtMCI = { 415,/* lineNo */
  1,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pName */
};

static emlrtMCInfo c4_eb_emlrtMCI = { 642,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtMCInfo c4_fb_emlrtMCI = { 56,/* lineNo */
  27,                                  /* colNo */
  "parseSortrowsOptions",              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/parseSortrowsOptions.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 26, /* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 27,/* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 28,/* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 31,/* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 34,/* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 35,/* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 36,/* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 42,/* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 43,/* lineNo */
  "Image Processing System/Image Processing Function",/* fcnName */
  "#flightControlSystem:2687"          /* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 70,/* lineNo */
  "imbinarize",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imbinarize.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 102,/* lineNo */
  "imbinarize",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imbinarize.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 39,/* lineNo */
  "im2uint8",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 138,/* lineNo */
  "im2uint8",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 19,/* lineNo */
  "grayto8",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/grayto8.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 207,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 37,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/otsuthresh.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 71,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/otsuthresh.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 76,/* lineNo */
  "validateattributes",                /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 45,/* lineNo */
  "mpower",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 70,/* lineNo */
  "power",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 112,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 128,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 134,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI = { 698,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI = { 699,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI = { 704,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI = { 705,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI = { 106,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI = { 110,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI = { 849,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI = { 1021,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_jb_emlrtRSI = { 934,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_kb_emlrtRSI = { 926,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_lb_emlrtRSI = { 977,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_mb_emlrtRSI = { 21,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c4_nb_emlrtRSI = { 994,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_ob_emlrtRSI = { 923,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c4_pb_emlrtRSI = { 997,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c4_qb_emlrtRSI = { 1025,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c4_rb_emlrtRSI = { 1037,/* lineNo */
  "imfilter",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c4_sb_emlrtRSI = { 14,/* lineNo */
  "max",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo c4_tb_emlrtRSI = { 44,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c4_ub_emlrtRSI = { 79,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c4_vb_emlrtRSI = { 147,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_wb_emlrtRSI = { 714,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_xb_emlrtRSI = { 456,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c4_yb_emlrtRSI = { 757,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_ac_emlrtRSI = { 751,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_bc_emlrtRSI = { 859,/* lineNo */
  "edge",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pathName */
};

static emlrtRSInfo c4_cc_emlrtRSI = { 76,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c4_dc_emlrtRSI = { 77,/* lineNo */
  "bwmorph",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwmorph.m"/* pathName */
};

static emlrtRSInfo c4_ec_emlrtRSI = { 33,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c4_fc_emlrtRSI = { 322,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c4_gc_emlrtRSI = { 325,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/algbwmorph.m"/* pathName */
};

static emlrtRSInfo c4_hc_emlrtRSI = { 145,/* lineNo */
  "bwlookup",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwlookup.m"/* pathName */
};

static emlrtRSInfo c4_ic_emlrtRSI = { 216,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_jc_emlrtRSI = { 174,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_kc_emlrtRSI = { 175,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_lc_emlrtRSI = { 28,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_mc_emlrtRSI = { 38,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_nc_emlrtRSI = { 46,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_oc_emlrtRSI = { 24,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_pc_emlrtRSI = { 28,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_qc_emlrtRSI = { 31,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_rc_emlrtRSI = { 32,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_sc_emlrtRSI = { 76,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_tc_emlrtRSI = { 136,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_uc_emlrtRSI = { 187,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_vc_emlrtRSI = { 190,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_wc_emlrtRSI = { 195,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_xc_emlrtRSI = { 35,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_yc_emlrtRSI = { 40,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_ad_emlrtRSI = { 60,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_bd_emlrtRSI = { 101,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_cd_emlrtRSI = { 103,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_dd_emlrtRSI = { 105,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_ed_emlrtRSI = { 107,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_fd_emlrtRSI = { 149,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_gd_emlrtRSI = { 151,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_hd_emlrtRSI = { 152,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_id_emlrtRSI = { 155,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_jd_emlrtRSI = { 575,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_kd_emlrtRSI = { 576,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_ld_emlrtRSI = { 754,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_md_emlrtRSI = { 755,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_nd_emlrtRSI = { 14,/* lineNo */
  "min",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo c4_od_emlrtRSI = { 46,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c4_pd_emlrtRSI = { 92,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c4_qd_emlrtRSI = { 157,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_rd_emlrtRSI = { 1017,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo c4_sd_emlrtRSI = { 452,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c4_td_emlrtRSI = { 196,/* lineNo */
  "imhist",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c4_ud_emlrtRSI = { 145,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_vd_emlrtRSI = { 113,/* lineNo */
  "mergesort",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo c4_wd_emlrtRSI = { 40,/* lineNo */
  "safeEq",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/safeEq.m"/* pathName */
};

static emlrtRSInfo c4_xd_emlrtRSI = { 46,/* lineNo */
  "eps",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/eps.m"/* pathName */
};

static emlrtRSInfo c4_yd_emlrtRSI = { 912,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_ae_emlrtRSI = { 917,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_be_emlrtRSI = { 44,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_ce_emlrtRSI = { 240,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_de_emlrtRSI = { 234,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_ee_emlrtRSI = { 226,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_fe_emlrtRSI = { 215,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_ge_emlrtRSI = { 202,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_he_emlrtRSI = { 195,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_ie_emlrtRSI = { 177,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_je_emlrtRSI = { 158,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_ke_emlrtRSI = { 43,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c4_le_emlrtRSI = { 13,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_me_emlrtRSI = { 17,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_ne_emlrtRSI = { 169,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_oe_emlrtRSI = { 172,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_pe_emlrtRSI = { 132,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_qe_emlrtRSI = { 1027,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_re_emlrtRSI = { 1028,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_se_emlrtRSI = { 1037,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_te_emlrtRSI = { 18,/* lineNo */
  "abs",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo c4_ue_emlrtRSI = { 75,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo c4_ve_emlrtRSI = { 13,/* lineNo */
  "any",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/any.m"/* pathName */
};

static emlrtRSInfo c4_we_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pathName */
};

static emlrtRSInfo c4_xe_emlrtRSI = { 32,/* lineNo */
  "sort",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo c4_ye_emlrtRSI = { 72,/* lineNo */
  "sort",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c4_af_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_bf_emlrtRSI = { 308,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_cf_emlrtRSI = { 316,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_df_emlrtRSI = { 317,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ef_emlrtRSI = { 325,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_ff_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_gf_emlrtRSI = { 392,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_hf_emlrtRSI = { 420,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_if_emlrtRSI = { 427,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_jf_emlrtRSI = { 587,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_kf_emlrtRSI = { 589,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_lf_emlrtRSI = { 617,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_mf_emlrtRSI = { 499,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_nf_emlrtRSI = { 506,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_of_emlrtRSI = { 507,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_pf_emlrtRSI = { 514,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_qf_emlrtRSI = { 561,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_rf_emlrtRSI = { 530,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_sf_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_tf_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_uf_emlrtRSI = { 255,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_vf_emlrtRSI = { 254,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_wf_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_xf_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_yf_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_ag_emlrtRSI = { 103,/* lineNo */
  "colon",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_bg_emlrtRSI = { 305,/* lineNo */
  "colon",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c4_cg_emlrtRSI = { 161,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_dg_emlrtRSI = { 37,/* lineNo */
  "medfilt2",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/medfilt2.m"/* pathName */
};

static emlrtRSInfo c4_eg_emlrtRSI = { 25,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c4_fg_emlrtRSI = { 155,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c4_gg_emlrtRSI = { 179,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c4_hg_emlrtRSI = { 29,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_ig_emlrtRSI = { 34,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_jg_emlrtRSI = { 35,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_kg_emlrtRSI = { 36,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_lg_emlrtRSI = { 48,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_mg_emlrtRSI = { 53,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_ng_emlrtRSI = { 55,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_og_emlrtRSI = { 66,/* lineNo */
  "imhmax",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/imhmax.m"/* pathName */
};

static emlrtRSInfo c4_pg_emlrtRSI = { 10,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c4_qg_emlrtRSI = { 14,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c4_rg_emlrtRSI = { 14,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c4_sg_emlrtRSI = { 35,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c4_tg_emlrtRSI = { 37,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c4_ug_emlrtRSI = { 32,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_vg_emlrtRSI = { 73,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_wg_emlrtRSI = { 75,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_xg_emlrtRSI = { 78,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_yg_emlrtRSI = { 168,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ah_emlrtRSI = { 197,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_bh_emlrtRSI = { 79,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_ch_emlrtRSI = { 71,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_dh_emlrtRSI = { 70,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_eh_emlrtRSI = { 69,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_fh_emlrtRSI = { 57,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_gh_emlrtRSI = { 44,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_hh_emlrtRSI = { 23,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_ih_emlrtRSI = { 51,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_jh_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_kh_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_lh_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_mh_emlrtRSI = { 153,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c4_nh_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo c4_oh_emlrtRSI = { 99,/* lineNo */
  "sumprod",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo c4_ph_emlrtRSI = { 133,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c4_qh_emlrtRSI = { 194,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c4_rh_emlrtRSI = { 14,/* lineNo */
  "cumsum",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/cumsum.m"/* pathName */
};

static emlrtRSInfo c4_sh_emlrtRSI = { 16,/* lineNo */
  "cumop",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c4_th_emlrtRSI = { 32,/* lineNo */
  "useConstantDim",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/useConstantDim.m"/* pathName */
};

static emlrtRSInfo c4_uh_emlrtRSI = { 99,/* lineNo */
  "cumop",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c4_vh_emlrtRSI = { 125,/* lineNo */
  "cumop",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c4_wh_emlrtRSI = { 290,/* lineNo */
  "cumop",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c4_xh_emlrtRSI = { 1283,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_yh_emlrtRSI = { 1468,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ai_emlrtRSI = { 28,/* lineNo */
  "repmat",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo c4_bi_emlrtRSI = { 1840,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ci_emlrtRSI = { 295,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_di_emlrtRSI = { 1152,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ei_emlrtRSI = { 1143,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_fi_emlrtRSI = { 1138,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_gi_emlrtRSI = { 1135,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_hi_emlrtRSI = { 772,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ii_emlrtRSI = { 770,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ji_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pathName */
};

static emlrtRSInfo c4_ki_emlrtRSI = { 22,/* lineNo */
  "cat",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo c4_li_emlrtRSI = { 102,/* lineNo */
  "cat",                               /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo c4_mi_emlrtRSI = { 1121,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ni_emlrtRSI = { 22,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_oi_emlrtRSI = { 26,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_pi_emlrtRSI = { 274,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_qi_emlrtRSI = { 275,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c4_ri_emlrtRSI = { 10,/* lineNo */
  "round",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/round.m"/* pathName */
};

static emlrtRSInfo c4_si_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c4_ti_emlrtRSI = { 27,/* lineNo */
  "sort",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo c4_ui_emlrtRSI = { 104,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_vi_emlrtRSI = { 340,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_wi_emlrtRSI = { 354,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_xi_emlrtRSI = { 363,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_yi_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_aj_emlrtRSI = { 144,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_bj_emlrtRSI = { 382,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_cj_emlrtRSI = { 402,/* lineNo */
  "find",                              /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c4_dj_emlrtRSI = { 58,/* lineNo */
  "hough",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m"/* pathName */
};

static emlrtRSInfo c4_ej_emlrtRSI = { 288,/* lineNo */
  "hough",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m"/* pathName */
};

static emlrtRSInfo c4_fj_emlrtRSI = { 295,/* lineNo */
  "hough",                             /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m"/* pathName */
};

static emlrtRSInfo c4_gj_emlrtRSI = { 138,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_hj_emlrtRSI = { 137,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_ij_emlrtRSI = { 91,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_jj_emlrtRSI = { 90,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_kj_emlrtRSI = { 61,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_lj_emlrtRSI = { 219,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_mj_emlrtRSI = { 262,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_nj_emlrtRSI = { 265,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_oj_emlrtRSI = { 268,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_pj_emlrtRSI = { 371,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_qj_emlrtRSI = { 383,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_rj_emlrtRSI = { 415,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_sj_emlrtRSI = { 410,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_tj_emlrtRSI = { 407,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_uj_emlrtRSI = { 404,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_vj_emlrtRSI = { 74,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_wj_emlrtRSI = { 91,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_xj_emlrtRSI = { 127,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_yj_emlrtRSI = { 137,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_ak_emlrtRSI = { 145,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_bk_emlrtRSI = { 159,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_ck_emlrtRSI = { 638,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_dk_emlrtRSI = { 531,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_ek_emlrtRSI = { 501,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_fk_emlrtRSI = { 420,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_gk_emlrtRSI = { 24,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c4_hk_emlrtRSI = { 27,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c4_ik_emlrtRSI = { 28,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c4_jk_emlrtRSI = { 86,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c4_kk_emlrtRSI = { 40,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c4_lk_emlrtRSI = { 43,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c4_mk_emlrtRSI = { 543,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_nk_emlrtRSI = { 587,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_ok_emlrtRSI = { 590,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_pk_emlrtRSI = { 608,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRTEInfo c4_emlrtRTEI = { 147,/* lineNo */
  38,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c4_b_emlrtRTEI = { 926,/* lineNo */
  31,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c4_c_emlrtRTEI = { 934,/* lineNo */
  51,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c4_d_emlrtRTEI = { 157,/* lineNo */
  38,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c4_e_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687"          /* pName */
};

static emlrtRTEInfo c4_f_emlrtRTEI = { 35,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687"          /* pName */
};

static emlrtRTEInfo c4_g_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687"          /* pName */
};

static emlrtRTEInfo c4_h_emlrtRTEI = { 729,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c4_i_emlrtRTEI = { 730,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c4_j_emlrtRTEI = { 65,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c4_k_emlrtRTEI = { 730,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c4_l_emlrtRTEI = { 128,/* lineNo */
  6,                                   /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c4_m_emlrtRTEI = { 128,/* lineNo */
  17,                                  /* colNo */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m"/* pName */
};

static emlrtRTEInfo c4_n_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

static emlrtRTEInfo c4_o_emlrtRTEI = { 38,/* lineNo */
  2,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_p_emlrtRTEI = { 46,/* lineNo */
  17,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_q_emlrtRTEI = { 369,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_r_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_s_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_t_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_u_emlrtRTEI = { 1,/* lineNo */
  43,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c4_v_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_w_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_x_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_y_emlrtRTEI = { 32,/* lineNo */
  35,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_ab_emlrtRTEI = { 32,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_bb_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_cb_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_db_emlrtRTEI = { 76,/* lineNo */
  23,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_eb_emlrtRTEI = { 77,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_fb_emlrtRTEI = { 78,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_gb_emlrtRTEI = { 79,/* lineNo */
  33,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_hb_emlrtRTEI = { 91,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_ib_emlrtRTEI = { 92,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_jb_emlrtRTEI = { 94,/* lineNo */
  24,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_kb_emlrtRTEI = { 95,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_lb_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_mb_emlrtRTEI = { 120,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_nb_emlrtRTEI = { 121,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_ob_emlrtRTEI = { 122,/* lineNo */
  28,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_pb_emlrtRTEI = { 298,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c4_qb_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_rb_emlrtRTEI = { 78,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_sb_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_tb_emlrtRTEI = { 91,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_ub_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_vb_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_wb_emlrtRTEI = { 95,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_xb_emlrtRTEI = { 120,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_yb_emlrtRTEI = { 121,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_ac_emlrtRTEI = { 122,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_bc_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_cc_emlrtRTEI = { 32,/* lineNo */
  8,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c4_dc_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_ec_emlrtRTEI = { 35,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_fc_emlrtRTEI = { 585,/* lineNo */
  15,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_gc_emlrtRTEI = { 12,/* lineNo */
  20,                                  /* colNo */
  "grayto8",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/grayto8.m"/* pName */
};

static emlrtRTEInfo c4_hc_emlrtRTEI = { 94,/* lineNo */
  13,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_ic_emlrtRTEI = { 912,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_jc_emlrtRTEI = { 917,/* lineNo */
  16,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_kc_emlrtRTEI = { 903,/* lineNo */
  28,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_lc_emlrtRTEI = { 917,/* lineNo */
  36,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_mc_emlrtRTEI = { 903,/* lineNo */
  1,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_nc_emlrtRTEI = { 141,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_oc_emlrtRTEI = { 995,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_pc_emlrtRTEI = { 1044,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_qc_emlrtRTEI = { 1011,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_rc_emlrtRTEI = { 107,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_sc_emlrtRTEI = { 152,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_tc_emlrtRTEI = { 1039,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_uc_emlrtRTEI = { 1020,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_vc_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c4_wc_emlrtRTEI = { 1021,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_xc_emlrtRTEI = { 1008,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_yc_emlrtRTEI = { 157,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_ad_emlrtRTEI = { 1027,/* lineNo */
  24,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_bd_emlrtRTEI = { 1027,/* lineNo */
  20,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_cd_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_dd_emlrtRTEI = { 917,/* lineNo */
  22,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_ed_emlrtRTEI = { 585,/* lineNo */
  17,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c4_fd_emlrtRTEI = { 159,/* lineNo */
  20,                                  /* colNo */
  "unique",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c4_gd_emlrtRTEI = { 170,/* lineNo */
  50,                                  /* colNo */
  "unique",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c4_hd_emlrtRTEI = { 234,/* lineNo */
  1,                                   /* colNo */
  "unique",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c4_id_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c4_jd_emlrtRTEI = { 31,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pName */
};

static emlrtRTEInfo c4_kd_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c4_ld_emlrtRTEI = { 572,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_md_emlrtRTEI = { 482,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_nd_emlrtRTEI = { 520,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_od_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_pd_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_qd_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_rd_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c4_sd_emlrtRTEI = { 41,/* lineNo */
  30,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_td_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_ud_emlrtRTEI = { 48,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_vd_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_wd_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c4_xd_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_yd_emlrtRTEI = { 42,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_ae_emlrtRTEI = { 53,/* lineNo */
  38,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_be_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_ce_emlrtRTEI = { 53,/* lineNo */
  58,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_de_emlrtRTEI = { 53,/* lineNo */
  18,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_ee_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_fe_emlrtRTEI = { 55,/* lineNo */
  33,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_ge_emlrtRTEI = { 298,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c4_he_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sort.m"/* pName */
};

static emlrtRTEInfo c4_ie_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c4_je_emlrtRTEI = { 55,/* lineNo */
  10,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_ke_emlrtRTEI = { 56,/* lineNo */
  19,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_le_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_me_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_ne_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_oe_emlrtRTEI = { 53,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_pe_emlrtRTEI = { 291,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_qe_emlrtRTEI = { 292,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_re_emlrtRTEI = { 17,/* lineNo */
  25,                                  /* colNo */
  "cumop",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pName */
};

static emlrtRTEInfo c4_se_emlrtRTEI = { 295,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_te_emlrtRTEI = { 298,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ue_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ve_emlrtRTEI = { 75,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_we_emlrtRTEI = { 220,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_xe_emlrtRTEI = { 233,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ye_emlrtRTEI = { 234,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_af_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_bf_emlrtRTEI = { 49,/* lineNo */
  25,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_cf_emlrtRTEI = { 50,/* lineNo */
  28,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_df_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_ef_emlrtRTEI = { 39,/* lineNo */
  35,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_ff_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_gf_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_hf_emlrtRTEI = { 69,/* lineNo */
  31,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_if_emlrtRTEI = { 70,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_jf_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_kf_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_lf_emlrtRTEI = { 90,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_mf_emlrtRTEI = { 11,/* lineNo */
  6,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_nf_emlrtRTEI = { 11,/* lineNo */
  19,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_of_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c4_pf_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_qf_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_rf_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c4_sf_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "useConstantDim",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/useConstantDim.m"/* pName */
};

static emlrtRTEInfo c4_tf_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo c4_uf_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo c4_vf_emlrtRTEI = { 1840,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_wf_emlrtRTEI = { 1719,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_xf_emlrtRTEI = { 1130,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_yf_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "round",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elfun/round.m"/* pName */
};

static emlrtRTEInfo c4_ag_emlrtRTEI = { 181,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pName */
};

static emlrtRTEInfo c4_bg_emlrtRTEI = { 637,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_cg_emlrtRTEI = { 74,/* lineNo */
  15,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_dg_emlrtRTEI = { 531,/* lineNo */
  12,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_eg_emlrtRTEI = { 547,/* lineNo */
  29,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_fg_emlrtRTEI = { 531,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_gg_emlrtRTEI = { 560,/* lineNo */
  31,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_hg_emlrtRTEI = { 142,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_ig_emlrtRTEI = { 143,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_jg_emlrtRTEI = { 150,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_kg_emlrtRTEI = { 150,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_lg_emlrtRTEI = { 151,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_mg_emlrtRTEI = { 151,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_ng_emlrtRTEI = { 152,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_og_emlrtRTEI = { 152,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_pg_emlrtRTEI = { 153,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_qg_emlrtRTEI = { 153,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_rg_emlrtRTEI = { 102,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_sg_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_tg_emlrtRTEI = { 108,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_ug_emlrtRTEI = { 111,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_vg_emlrtRTEI = { 137,/* lineNo */
  5,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_wg_emlrtRTEI = { 1,/* lineNo */
  18,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_xg_emlrtRTEI = { 127,/* lineNo */
  22,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_yg_emlrtRTEI = { 547,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pName */
};

static emlrtRTEInfo c4_ah_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c4_bh_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c4_ch_emlrtRTEI = { 33,/* lineNo */
  14,                                  /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c4_dh_emlrtRTEI = { 13,/* lineNo */
  21,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c4_eh_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c4_fh_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_gh_emlrtRTEI = { 267,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_hh_emlrtRTEI = { 385,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_ih_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_jh_emlrtRTEI = { 274,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_kh_emlrtRTEI = { 387,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_lh_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_mh_emlrtRTEI = { 105,/* lineNo */
  40,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_nh_emlrtRTEI = { 769,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_oh_emlrtRTEI = { 770,/* lineNo */
  41,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ph_emlrtRTEI = { 1120,/* lineNo */
  57,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_qh_emlrtRTEI = { 774,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_rh_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_sh_emlrtRTEI = { 1142,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_th_emlrtRTEI = { 1120,/* lineNo */
  47,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_uh_emlrtRTEI = { 40,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_vh_emlrtRTEI = { 1121,/* lineNo */
  33,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_wh_emlrtRTEI = { 1143,/* lineNo */
  28,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_xh_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_yh_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_ai_emlrtRTEI = { 44,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_bi_emlrtRTEI = { 1152,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ci_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_di_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_ei_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c4_fi_emlrtRTEI = { 1122,/* lineNo */
  27,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_gi_emlrtRTEI = { 110,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c4_hi_emlrtRTEI = { 117,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c4_ii_emlrtRTEI = { 772,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_ji_emlrtRTEI = { 105,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c4_ki_emlrtRTEI = { 770,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c4_li_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c4_mi_emlrtRTEI = { 27,/* lineNo */
  30,                                  /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c4_ni_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c4_oi_emlrtRTEI = { 52,/* lineNo */
  20,                                  /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c4_pi_emlrtRTEI = { 148,/* lineNo */
  24,                                  /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c4_qi_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c4_ri_emlrtRTEI = { 1,/* lineNo */
  34,                                  /* colNo */
  "mergesort",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pName */
};

static emlrtRTEInfo c4_si_emlrtRTEI = { 38,/* lineNo */
  23,                                  /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c4_ti_emlrtRTEI = { 38,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pName */
};

static emlrtRTEInfo c4_ui_emlrtRTEI = { 41,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687"          /* pName */
};

static emlrtRTEInfo c4_vi_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687"          /* pName */
};

static emlrtBCInfo c4_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  32,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_emlrtDCI = { 52, /* lineNo */
  32,                                  /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  32,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_b_emlrtDCI = { 42,/* lineNo */
  32,                                  /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  23,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_c_emlrtDCI = { 49,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  21,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_d_emlrtDCI = { 51,/* lineNo */
  21,                                  /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  33,                                  /* colNo */
  "lines",                             /* aName */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_e_emlrtDCI = { 43,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/Image Processing Function",/* fName */
  "#flightControlSystem:2687",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_f_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1049,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_g_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1050,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_h_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1051,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_i_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1052,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  138,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_l_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_m_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  756,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  751,                                 /* lineNo */
  70,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c4_wi_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtBCInfo c4_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ob_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_tb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ub_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_wb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  81,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  104,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_dc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ec_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1022,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1008,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1005,                                /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_emlrtECI = { 2,  /* nDims */
  917,                                 /* lineNo */
  16,                                  /* colNo */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtBCInfo c4_hc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ic_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1032,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1049,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1050,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1064,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1051,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_nc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1052,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_oc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c4_b_emlrtECI = { -1,/* nDims */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c4_xi_emlrtRTEI = { 46,/* lineNo */
  15,                                  /* colNo */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtBCInfo c4_pc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sc_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_tc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_uc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_wc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1896,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1898,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ad_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_f_emlrtDCI = { 48,/* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c4_cd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_dd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ed_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_g_emlrtDCI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_gd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_id_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ld_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_md_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_nd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_od_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_td_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ud_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_wd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ae_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_be_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ce_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_de_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ee_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ge_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_he_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_h_emlrtDCI = { 69,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c4_i_emlrtDCI = { 69,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c4_ie_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_je_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ke_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_le_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_me_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ne_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_oe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_re_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_se_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_te_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  299,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_ue_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  346,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_ve_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  299,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "hough",                             /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/hough.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_we_emlrtBCI = { 1,/* iFirst */
  71820,                               /* iLast */
  110,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_xe_emlrtBCI = { 1,/* iFirst */
  399,                                 /* iLast */
  107,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ye_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  107,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "houghpeaks",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_af_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  142,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  150,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_df_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  150,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ef_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ff_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  248,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_hf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  591,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_if_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  592,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jf_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  531,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kf_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  398,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_lf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_nf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_of_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  578,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_tf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  122,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_uf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  591,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_wf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  592,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  593,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  593,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ag_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  594,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  594,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_j_emlrtDCI = { 547,/* lineNo */
  35,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c4_cg_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  503,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_dg_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  429,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_k_emlrtDCI = { 560,/* lineNo */
  37,                                  /* colNo */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_eg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ig_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  551,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  554,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_lg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  565,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  567,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ng_emlrtBCI = { 1,/* iFirst */
  180,                                 /* iLast */
  152,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "houghlines",                        /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_l_emlrtDCI = { 31,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c4_m_emlrtDCI = { 31,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo c4_c_emlrtECI = { -1,/* nDims */
  1152,                                /* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtBCInfo c4_og_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1144,                                /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1120,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  774,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1152,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_tg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1156,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ug_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_wg_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  772,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ah_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  769,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  770,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ch_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1120,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_dh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1142,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_eh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1142,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1121,                                /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1152,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hh_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1122,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c4_qk_emlrtRSI = { 153,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_rk_emlrtRSI = { 152,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_sk_emlrtRSI = { 170,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_tk_emlrtRSI = { 159,/* lineNo */
  "unique",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c4_uk_emlrtRSI = { 122,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_vk_emlrtRSI = { 181,/* lineNo */
  "houghpeaks",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghpeaks.m"/* pathName */
};

static emlrtRSInfo c4_wk_emlrtRSI = { 56,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_xk_emlrtRSI = { 40,/* lineNo */
  "chcenters",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c4_yk_emlrtRSI = { 94,/* lineNo */
  "multithresh",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c4_al_emlrtRSI = { 47,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c4_bl_emlrtRSI = { 31,/* lineNo */
  "repmat",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo c4_cl_emlrtRSI = { 95,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_dl_emlrtRSI = { 38,/* lineNo */
  "sortrows",                          /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/datafun/sortrows.m"/* pathName */
};

static emlrtRSInfo c4_el_emlrtRSI = { 52,/* lineNo */
  "mergesort",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo c4_fl_emlrtRSI = { 55,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_gl_emlrtRSI = { 39,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c4_hl_emlrtRSI = { 48,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_il_emlrtRSI = { 46,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_jl_emlrtRSI = { 121,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_kl_emlrtRSI = { 120,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_ll_emlrtRSI = { 1142,/* lineNo */
  "regionprops",                       /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c4_ml_emlrtRSI = { 41,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c4_nl_emlrtRSI = { 79,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_ol_emlrtRSI = { 78,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_pl_emlrtRSI = { 77,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_ql_emlrtRSI = { 92,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_rl_emlrtRSI = { 91,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_sl_emlrtRSI = { 94,/* lineNo */
  "chaccum",                           /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c4_tl_emlrtRSI = { 1,/* lineNo */
  "mergesort",                         /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo c4_ul_emlrtRSI = { 151,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_vl_emlrtRSI = { 150,/* lineNo */
  "houghlines",                        /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/images/images/eml/houghlines.m"/* pathName */
};

static emlrtRSInfo c4_wl_emlrtRSI = { 53,/* lineNo */
  "repmat",                            /* fcnName */
  "/home/yogesh/MATLAB/R2020b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static const char_T c4_cv[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
  'i', 'n', 'i', 't', 'e' };

static const real_T c4_dv[13] = { 3.4813359214923059E-5, 0.00054457256285105158,
  0.0051667606200595222, 0.029732654490475543, 0.10377716120747747,
  0.21969625200024598, 0.28209557151935094, 0.21969625200024598,
  0.10377716120747747, 0.029732654490475543, 0.0051667606200595222,
  0.00054457256285105158, 3.4813359214923059E-5 };

static const real_T c4_dv1[13] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, 0.0, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static const real_T c4_dv2[12] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static const boolean_T c4_bv[13] = { true, true, true, true, true, true, false,
  true, true, true, true, true, true };

static const char_T c4_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i',
  'l', 't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
  'a', 'i', 'l', 'e', 'd' };

static const char_T c4_cv2[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c', 'h'
};

static const char_T c4_cv3[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N',
  'o', 'n', 'N', 'a', 'N' };

static const char_T c4_cv4[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
  'a', 'x', 's', 'i', 'z', 'e' };

static const char_T c4_cv5[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
  'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
  'd', 'F', 'i', 'n', 'i', 't', 'e' };

static const char_T c4_cv6[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
  'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
  'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

static const char_T c4_cv7[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
  'n', 't', 'e', 'g', 'e', 'r' };

/* Function Declarations */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_update_jit_animation_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st);
static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, uint8_T c4_d_varargin_1[19200],
                      real_T c4_yout[256]);
static real_T c4_otsuthresh(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_counts[256]);
static void c4_edge(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200],
                    boolean_T c4_varargout_1[19200]);
static void c4_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200]);
static void c4_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[19200], real32_T c4_g_a[21120]);
static void c4_check_forloop_overflow_error
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp);
static void c4_b_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200]);
static void c4_b_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[19200], real32_T c4_g_a[20640]);
static void c4_c_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200]);
static void c4_d_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200]);
static void c4_b_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real_T c4_yout[64]);
static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp);
static void c4_thinAndThreshold(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_E[19200], real32_T
  c4_c_dx[19200], real32_T c4_c_dy[19200], real32_T c4_magGrad[19200], real_T
  c4_lowThresh_data[], int32_T c4_lowThresh_size[1], real_T c4_highThresh_data[],
  int32_T c4_highThresh_size[1], boolean_T c4_b_H[19200]);
static void c4_imreconstruct(SFc4_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c4_marker[19200], boolean_T c4_mask[19200],
  boolean_T c4_im[19200]);
static void c4_bwmorph(SFc4_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c4_bwin[19200], boolean_T c4_bw[19200]);
static void c4_bwmorphApplyOnce(SFc4_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c4_bw[19200], boolean_T c4_b_bw[19200]);
static void c4_bwlookup(SFc4_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c4_bwin[19200], boolean_T c4_B[19200]);
static void c4_b_bwlookup(SFc4_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c4_bwin[19200], boolean_T c4_B[19200]);
static void c4_e_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200]);
static void c4_c_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[19200], real32_T c4_g_a[20336]);
static void c4_f_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200]);
static void c4_d_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[19200], real32_T c4_g_a[19764]);
static void c4_g_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200]);
static void c4_hypot(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     real32_T c4_c_x[19200], real32_T c4_y[19200], real32_T
                     c4_r[19200]);
static real32_T c4_maximum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_c_x[19200]);
static void c4_imfindcircles(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200],
  c4_emxArray_real_T *c4_centers);
static void c4_chaccum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200], creal_T
  c4_b_accumMatrix[19200], real32_T c4_b_gradientImg[19200]);
static real32_T c4_multithresh(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200]);
static real32_T c4_minimum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_c_x[19200]);
static void c4_c_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, uint8_T c4_varargin_1_data[], int32_T
  c4_varargin_1_size[1], real_T c4_yout[256]);
static real_T c4_sum(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     real_T c4_c_x[256]);
static void c4_b_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp);
static void c4_power(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     real_T c4_g_a[256], real_T c4_y[256]);
static real_T c4_b_maximum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_x[256]);
static void c4_mergesort(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_b_idx[19200], real32_T c4_c_x[19200],
  int32_T c4_c_idx[19200]);
static void c4_unique_vector(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real32_T c4_g_a[19200],
  c4_emxArray_real32_T *c4_b);
static void c4_indexShapeCheck(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T
  c4_indexSize[2]);
static void c4_nullAssignment(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_c_x,
  boolean_T c4_idx_data[], int32_T c4_idx_size[2], c4_emxArray_real32_T *c4_d_x);
static void c4_c_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp);
static void c4_abs(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x,
                   c4_emxArray_real_T *c4_y);
static real_T c4_eps(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     real_T c4_c_x);
static boolean_T c4_any(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_b_x_data[], int32_T c4_x_size[1]);
static void c4_sort(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c4_sp, c4_emxArray_real32_T *c4_c_x,
                    c4_emxArray_real32_T *c4_d_x);
static void c4_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_c_x, int32_T c4_offset, c4_emxArray_int32_T *c4_c_idx,
  c4_emxArray_real32_T *c4_d_x);
static void c4_merge_block(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real32_T
  *c4_c_x, int32_T c4_offset, int32_T c4_n, int32_T c4_preSortLevel,
  c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T *c4_xwork,
  c4_emxArray_int32_T *c4_c_idx, c4_emxArray_real32_T *c4_d_x,
  c4_emxArray_int32_T *c4_c_iwork, c4_emxArray_real32_T *c4_b_xwork);
static void c4_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
                     c4_emxArray_real32_T *c4_c_x, int32_T c4_offset, int32_T
                     c4_np, int32_T c4_nq, c4_emxArray_int32_T *c4_b_iwork,
                     c4_emxArray_real32_T *c4_xwork, c4_emxArray_int32_T
                     *c4_c_idx, c4_emxArray_real32_T *c4_d_x,
                     c4_emxArray_int32_T *c4_c_iwork, c4_emxArray_real32_T
                     *c4_b_xwork);
static void c4_eml_find(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_c_x[19200], c4_emxArray_int32_T *c4_i,
  c4_emxArray_int32_T *c4_j);
static boolean_T c4_allinrange(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T *c4_c_x, int32_T c4_hi);
static void c4_eml_sub2ind(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real_T *c4_d_varargin_1,
  c4_emxArray_real_T *c4_b_varargin_2, c4_emxArray_int32_T *c4_b_idx);
static void c4_medfilt2(SFc4_flightControlSystemInstanceStruct *chartInstance,
  real_T c4_d_varargin_1[19200], real_T c4_b[19200]);
static void c4_chcenters(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, creal_T c4_d_varargin_1[19200], c4_emxArray_real_T
  *c4_centers, c4_emxArray_real_T *c4_metric);
static void c4_imhmax(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real_T c4_I[19200], real_T
                      c4_b_J[19200]);
static void c4_validateattributes(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_g_a[19200]);
static void c4_imregionalmax(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_d_varargin_1[19200],
  boolean_T c4_BW[19200]);
static void c4_regionprops(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200], real_T
  c4_b_varargin_2[19200], c4_emxArray_sBO2RC5RVZVTbundPSRqHn *c4_outstats);
static void c4_bwconncomp(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200],
  c4_s_VSLwMee4Kv1oTF0BcoITHB *c4_CC);
static void c4_useConstantDim(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_varargin_2,
  int32_T c4_varargin_3, c4_emxArray_int32_T *c4_varargout_1);
static void c4_repmat(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real_T c4_d_varargin_1,
                      c4_emxArray_sBO2RC5RVZVTbundPSRqHn *c4_b);
static void c4_assertValidSizeArg(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_d_varargin_1);
static void c4_initializeStatsStruct(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_numObjs,
  c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_stats, c4_sHtk0WM4OMtyqkehwQYcq2
  *c4_statsAlreadyComputed);
static void c4_ComputeWeightedCentroid(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_I[19200],
  c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_stats, c4_sHtk0WM4OMtyqkehwQYcq2
  c4_statsAlreadyComputed, c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_b_stats,
  c4_sHtk0WM4OMtyqkehwQYcq2 *c4_b_statsAlreadyComputed);
static real_T c4_b_sum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x);
static void c4_round(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x,
                     c4_emxArray_real_T *c4_d_x);
static void c4_b_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x,
                      c4_emxArray_real_T *c4_d_x, c4_emxArray_int32_T *c4_b_idx);
static void c4_b_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real_T *c4_c_x, int32_T c4_offset, c4_emxArray_int32_T *c4_c_idx,
  c4_emxArray_real_T *c4_d_x);
static void c4_b_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real_T *c4_c_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real_T *c4_xwork,
  c4_emxArray_int32_T *c4_c_idx, c4_emxArray_real_T *c4_d_x, c4_emxArray_int32_T
  *c4_c_iwork, c4_emxArray_real_T *c4_b_xwork);
static void c4_b_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real_T
  *c4_c_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T *
  c4_b_iwork, c4_emxArray_real_T *c4_xwork, c4_emxArray_int32_T *c4_c_idx,
  c4_emxArray_real_T *c4_d_x, c4_emxArray_int32_T *c4_c_iwork,
  c4_emxArray_real_T *c4_b_xwork);
static void c4_hough(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200],
                     real_T c4_h[71820]);
static real_T c4_c_maximum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_x[71820]);
static void c4_houghpeaks(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_d_varargin_1[71820], real_T c4_varargin_4,
  c4_emxArray_real_T *c4_peaks);
static void c4_b_validateattributes(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_g_a[2]);
static real_T c4_b_minimum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_x[180]);
static real_T c4_d_maximum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_x[180]);
static void c4_diff(SFc4_flightControlSystemInstanceStruct *chartInstance,
                    real_T c4_c_x[180], real_T c4_y[179]);
static void c4_b_diff(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      real_T c4_c_x[179], real_T c4_y[178]);
static void c4_houghlines(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200], c4_emxArray_real_T *
  c4_varargin_4, c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *c4_lines);
static void c4_c_validateattributes(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_g_a);
static void c4_sortrows(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_y, real_T c4_d_varargin_1[2],
  c4_emxArray_int32_T *c4_b_y);
static void c4_b_mergesort(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_int32_T
  *c4_c_x, int32_T c4_dir[2], int32_T c4_n, c4_emxArray_int32_T *c4_c_idx);
static boolean_T c4_sortLE(SFc4_flightControlSystemInstanceStruct *chartInstance,
  c4_emxArray_int32_T *c4_v, int32_T c4_dir[2], int32_T c4_idx1, int32_T c4_idx2);
static void c4_apply_row_permutation(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_y,
  c4_emxArray_int32_T *c4_b_idx, c4_emxArray_int32_T *c4_b_y);
static int32_T c4_b_power(SFc4_flightControlSystemInstanceStruct *chartInstance,
  int32_T c4_g_a);
static void c4_b_repmat(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_b_varargin_2,
  c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *c4_b);
static const mxArray *c4_emlrt_marshallOut
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const char_T c4_b_u[30]);
static real_T c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_mode, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId);
static uint8_T c4_c_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_flightControlSystem, const
  char_T *c4_identifier);
static uint8_T c4_d_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *c4_chart_data_browse_helper
  (SFc4_flightControlSystemInstanceStruct *chartInstance, int32_T c4_ssIdNumber);
static const mxArray *c4_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1);
static void c4_b_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static const mxArray *c4_c_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1, const mxArray *c4_input2);
static void c4_d_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static const mxArray *c4_e_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1);
static void c4_f_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_b_bwmorphApplyOnce(SFc4_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c4_bw[19200]);
static void c4_c_mergesort(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_b_idx[19200], real32_T c4_c_x[19200]);
static void c4_b_nullAssignment(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_c_x,
  boolean_T c4_idx_data[], int32_T c4_idx_size[2]);
static void c4_c_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_c_x);
static void c4_c_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_c_x, int32_T c4_offset);
static void c4_c_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_c_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T
  *c4_xwork);
static void c4_c_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real32_T
  *c4_c_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T *
  c4_b_iwork, c4_emxArray_real32_T *c4_xwork);
static void c4_b_ComputeWeightedCentroid(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, real_T c4_I[19200],
  c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_stats, c4_sHtk0WM4OMtyqkehwQYcq2
  *c4_statsAlreadyComputed);
static void c4_b_round(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x);
static void c4_d_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x,
                      c4_emxArray_int32_T *c4_b_idx);
static void c4_d_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real_T *c4_c_x, int32_T c4_offset);
static void c4_d_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real_T *c4_c_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real_T *c4_xwork);
static void c4_d_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real_T
  *c4_c_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T *
  c4_b_iwork, c4_emxArray_real_T *c4_xwork);
static void c4_b_sortrows(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_y, real_T c4_d_varargin_1[2]);
static void c4_d_mergesort(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_int32_T
  *c4_c_x, int32_T c4_dir[2], int32_T c4_n);
static void c4_b_apply_row_permutation(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_y,
  c4_emxArray_int32_T *c4_b_idx);
static void c4_emxInit_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_skoeQIuVNKJRHNtBIlOCZhD
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_skoeQIuVNKJRHNtBIlOCZh **c4_pEmxArray, int32_T
   c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFree_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T **c4_pEmxArray);
static void c4_emxFree_skoeQIuVNKJRHNtBIlOCZhD
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_emxArray_skoeQIuVNKJRHNtBIlOCZh **c4_pEmxArray);
static void c4_emxEnsureCapacity_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFree_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real32_T **c4_pEmxArray);
static void c4_emxEnsureCapacity_creal_T(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_creal_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_boolean_T
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_boolean_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_int32_T(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_real_T1(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_real_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_boolean_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_boolean_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_int32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_creal_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_creal_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFree_boolean_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_boolean_T **c4_pEmxArray);
static void c4_emxFree_int32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_int32_T **c4_pEmxArray);
static void c4_emxFree_creal_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_creal_T **c4_pEmxArray);
static void c4_emxEnsureCapacity_real32_T1
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_real32_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_creal_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_creal_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_real32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_creal_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_creal_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_int32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_sBO2RC5RVZVTbundPSRqHnH
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_sBO2RC5RVZVTbundPSRqHn **c4_pEmxArray, int32_T
   c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_int32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFree_sBO2RC5RVZVTbundPSRqHnH
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_emxArray_sBO2RC5RVZVTbundPSRqHn **c4_pEmxArray);
static void c4_emxInitStruct_s_VSLwMee4Kv1oTF0
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_VSLwMee4Kv1oTF0BcoITHB *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation);
static void c4_emxInit_s_nrlUwWofUDGxo1t78e6dw
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_s_nrlUwWofUDGxo1t78e6d **c4_pEmxArray, int32_T
   c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxFreeStruct_s_VSLwMee4Kv1oTF0
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_VSLwMee4Kv1oTF0BcoITHB *c4_pStruct);
static void c4_emxFree_s_nrlUwWofUDGxo1t78e6dw
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_emxArray_s_nrlUwWofUDGxo1t78e6d **c4_pEmxArray);
static void c4_emxFreeStruct_s_nrlUwWofUDGxo1t
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_nrlUwWofUDGxo1t78e6dwC *c4_pStruct);
static void c4_emxEnsureCapacity_boolean_T1
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_boolean_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_sBO2RC5RVZVTb
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_sBO2RC5RVZVTbundPSRqHn *c4_emxArray, int32_T c4_oldNumel,
   const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInit_boolean_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_boolean_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxTrim_s_nrlUwWofUDGxo1t78e6dw
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_emxArray, int32_T c4_fromIndex,
   int32_T c4_toIndex);
static void c4_emxInitStruct_s_nrlUwWofUDGxo1t
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_nrlUwWofUDGxo1t78e6dwC *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation);
static void c4_emxExpand_s_nrlUwWofUDGxo1t78e6
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_emxArray, int32_T c4_fromIndex,
   int32_T c4_toIndex, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxEnsureCapacity_s_nrlUwWofUDG
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_emxArray, int32_T c4_oldNumel,
   const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopyStruct_s_nrlUwWofUDGxo1t
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_nrlUwWofUDGxo1t78e6dwC *c4_dst, const
   c4_s_nrlUwWofUDGxo1t78e6dwC *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopyMatrix_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[2], const real_T c4_src[2]);
static void c4_emxCopyMatrix_real_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[4], const real_T c4_src[4]);
static void c4_emxCopy_boolean_T_0x0(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_boolean_T_0x0 *c4_dst, const
  c4_emxArray_boolean_T_0x0 *c4_src);
static void c4_emxCopyMatrix_real_T2(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[16], const real_T c4_src[16]);
static void c4_emxCopy_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_dst,
  c4_emxArray_real_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopy_real_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_dst,
  c4_emxArray_real_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation);
static void c4_emxCopy_real_T_1x0(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T_1x0 *c4_dst, const c4_emxArray_real_T_1x0
  *c4_src);
static void c4_emxEnsureCapacity_skoeQIuVNKJRH
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *c4_emxArray, int32_T c4_oldNumel,
   const emlrtRTEInfo *c4_srcLocation);
static void c4_emxInitMatrix_cell_wrap_52(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_52 c4_pMatrix[2], const
  emlrtRTEInfo *c4_srcLocation);
static void c4_emxInitStruct_cell_wrap_52(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_52 *c4_pStruct, const
  emlrtRTEInfo *c4_srcLocation);
static void c4_emxFreeMatrix_cell_wrap_52(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_cell_wrap_52 c4_pMatrix[2]);
static void c4_emxFreeStruct_cell_wrap_52(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_cell_wrap_52 *c4_pStruct);
static int32_T c4_div_nzp_s32(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int32_T c4_numerator, int32_T c4_denominator, int32_T
  c4_EMLOvCount_src_loc, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc,
  int32_T c4_length_src_loc);
static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c4_st, "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_flightControlSystem = 0U;
}

static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_jit_animation_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(3, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", chartInstance->c4_mode, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", chartInstance->c4_output_angle, 0,
    0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y",
    &chartInstance->c4_is_active_c4_flightControlSystem, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_b_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_b_u = sf_mex_dup(c4_st);
  *chartInstance->c4_mode = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_b_u, 0)), "mode");
  *chartInstance->c4_output_angle = c4_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_b_u, 1)), "output_angle");
  chartInstance->c4_is_active_c4_flightControlSystem = c4_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_b_u, 2)),
     "is_active_c4_flightControlSystem");
  sf_mex_destroy(&c4_b_u);
  sf_mex_destroy(&c4_st);
}

static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  c4_emxArray_real_T *c4_P;
  c4_emxArray_real_T *c4_centers;
  c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *c4_lines;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_g_st;
  emlrtStack c4_h_st;
  emlrtStack c4_i_st;
  emlrtStack c4_j_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c4_b_dv[256];
  real_T c4_b_x_data[180];
  real_T c4_c_x_data[180];
  real_T c4_d_varargin_1[2];
  real_T c4_T;
  real_T c4_angle;
  real_T c4_angle_temp;
  real_T c4_b_ex;
  real_T c4_b_mode;
  real_T c4_b_n;
  real_T c4_b_output_angle;
  real_T c4_c_i;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_x;
  real_T c4_e_n;
  real_T c4_e_x;
  real_T c4_ex;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_hough_angle;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_max_angle;
  real_T c4_maxval;
  real_T c4_min_angle;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_t;
  real_T c4_temp_;
  int32_T c4_x_size[2];
  int32_T c4_b_first;
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_varargin_2;
  int32_T c4_c_idx;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_n;
  int32_T c4_c_varargin_2;
  int32_T c4_d_i;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_d_n;
  int32_T c4_d_varargin_2;
  int32_T c4_e_varargin_1;
  int32_T c4_e_varargin_2;
  int32_T c4_f_n;
  int32_T c4_f_varargin_1;
  int32_T c4_first;
  int32_T c4_g_varargin_1;
  int32_T c4_h_varargin_1;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_n;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_d_p;
  boolean_T c4_e_b;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_g_b;
  boolean_T c4_h_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  boolean_T c4_temp;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_g_st.prev = &c4_f_st;
  c4_g_st.tls = c4_f_st.tls;
  c4_h_st.prev = &c4_g_st;
  c4_h_st.tls = c4_g_st.tls;
  c4_i_st.prev = &c4_h_st;
  c4_i_st.tls = c4_h_st.tls;
  c4_j_st.prev = &c4_i_st;
  c4_j_st.tls = c4_i_st.tls;
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U,
                      (*chartInstance->c4_image)[c4_i]);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  c4_angle = 0.0;
  c4_b_mode = 0.0;
  c4_angle_temp = 0.0;
  c4_temp = false;
  c4_temp_ = 0.0;
  c4_b_st.site = &c4_emlrtRSI;
  c4_c_st.site = &c4_j_emlrtRSI;
  c4_d_st.site = &c4_k_emlrtRSI;
  c4_e_st.site = &c4_l_emlrtRSI;
  c4_f_st.site = &c4_m_emlrtRSI;
  c4_g_st.site = &c4_n_emlrtRSI;
  grayto8_real64(&(*chartInstance->c4_image)[0], &chartInstance->c4_u[0],
                 19200.0);
  c4_d_st.site = &c4_k_emlrtRSI;
  c4_imhist(chartInstance, &c4_d_st, chartInstance->c4_u, c4_b_dv);
  c4_d_st.site = &c4_k_emlrtRSI;
  c4_t = c4_otsuthresh(chartInstance, &c4_d_st, c4_b_dv);
  c4_T = c4_t;
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    chartInstance->c4_binary_img[c4_i1] = ((*chartInstance->c4_image)[c4_i1] >
      c4_T);
  }

  c4_emxInit_real_T(chartInstance, &c4_b_st, &c4_centers, 2, &c4_e_emlrtRTEI);
  c4_b_st.site = &c4_b_emlrtRSI;
  for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
    chartInstance->c4_b_binary_img[c4_i2] = chartInstance->c4_binary_img[c4_i2];
  }

  c4_edge(chartInstance, &c4_b_st, chartInstance->c4_b_binary_img,
          chartInstance->c4_canny_output);
  c4_b_st.site = &c4_c_emlrtRSI;
  for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
    chartInstance->c4_b_canny_output[c4_i3] = chartInstance->
      c4_canny_output[c4_i3];
  }

  c4_bwmorph(chartInstance, chartInstance->c4_b_canny_output,
             chartInstance->c4_morphed_output);
  c4_b_st.site = &c4_d_emlrtRSI;
  c4_imfindcircles(chartInstance, &c4_b_st, chartInstance->c4_binary_img,
                   c4_centers);
  c4_b_st.site = &c4_e_emlrtRSI;
  c4_hough(chartInstance, &c4_b_st, chartInstance->c4_morphed_output,
           chartInstance->c4_H);
  c4_b_st.site = &c4_f_emlrtRSI;
  for (c4_i4 = 0; c4_i4 < 71820; c4_i4++) {
    chartInstance->c4_varargin_1[c4_i4] = chartInstance->c4_H[c4_i4];
  }

  c4_emxInit_real_T(chartInstance, &c4_b_st, &c4_P, 2, &c4_f_emlrtRTEI);
  c4_emxInit_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c4_b_st, &c4_lines, 2,
    &c4_g_emlrtRTEI);
  c4_c_st.site = &c4_sb_emlrtRSI;
  c4_d_st.site = &c4_tb_emlrtRSI;
  c4_maxval = c4_c_maximum(chartInstance, &c4_d_st, chartInstance->c4_varargin_1);
  c4_c_x = 0.3 * c4_maxval;
  c4_d_x = c4_c_x;
  c4_d_x = muDoubleScalarCeil(c4_d_x);
  c4_b_st.site = &c4_f_emlrtRSI;
  c4_houghpeaks(chartInstance, &c4_b_st, chartInstance->c4_H, c4_d_x, c4_P);
  c4_b_st.site = &c4_g_emlrtRSI;
  c4_houghlines(chartInstance, &c4_b_st, chartInstance->c4_canny_output, c4_P,
                c4_lines);
  c4_max_angle = 0.0;
  c4_min_angle = 0.0;
  c4_d = (real_T)c4_lines->size[1];
  c4_i5 = (int32_T)c4_d;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, c4_d, mxDOUBLE_CLASS, c4_i5,
    &c4_ui_emlrtRTEI, &c4_st);
  c4_b_i = 0;
  c4_emxFree_real_T(chartInstance, &c4_P);
  while (c4_b_i <= c4_i5 - 1) {
    c4_c_i = 1.0 + (real_T)c4_b_i;
    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 0, 1);
    c4_b_st.site = &c4_h_emlrtRSI;
    c4_d_varargin_1[0] = c4_max_angle;
    c4_i7 = c4_lines->size[1];
    c4_i8 = (int32_T)emlrtIntegerCheckR2012b(c4_c_i, &c4_b_emlrtDCI, &c4_b_st);
    c4_d_varargin_1[1] = c4_lines->data[emlrtDynamicBoundsCheckR2012b(c4_i8, 1,
      c4_i7, &c4_b_emlrtBCI, &c4_b_st) - 1].theta;
    c4_c_st.site = &c4_sb_emlrtRSI;
    c4_d_st.site = &c4_tb_emlrtRSI;
    c4_e_st.site = &c4_ub_emlrtRSI;
    c4_f_st.site = &c4_vb_emlrtRSI;
    c4_x_size[0] = 1;
    c4_x_size[1] = 2;
    for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
      c4_b_x_data[c4_i11] = c4_d_varargin_1[c4_i11];
    }

    c4_g_st.site = &c4_ib_emlrtRSI;
    c4_c_n = c4_x_size[1];
    if (c4_c_n <= 2) {
      if (c4_b_x_data[0] < c4_b_x_data[1]) {
        c4_max_angle = c4_b_x_data[1];
      } else {
        c4_e_x = c4_b_x_data[0];
        c4_b = muDoubleScalarIsNaN(c4_e_x);
        if (c4_b) {
          c4_g_x = c4_b_x_data[1];
          c4_b_b = muDoubleScalarIsNaN(c4_g_x);
          if (!c4_b_b) {
            c4_max_angle = c4_b_x_data[1];
          } else {
            c4_max_angle = c4_b_x_data[0];
          }
        } else {
          c4_max_angle = c4_b_x_data[0];
        }
      }
    } else {
      c4_h_st.site = &c4_kb_emlrtRSI;
      c4_loop_ub = c4_x_size[0] * c4_x_size[1] - 1;
      for (c4_i15 = 0; c4_i15 <= c4_loop_ub; c4_i15++) {
        c4_c_x_data[c4_i15] = c4_b_x_data[c4_i15];
      }

      c4_f_x = c4_c_x_data[0];
      c4_i_x = c4_f_x;
      c4_c_b = muDoubleScalarIsNaN(c4_i_x);
      c4_p = !c4_c_b;
      if (c4_p) {
        c4_b_idx = 1;
      } else {
        c4_b_idx = 0;
        c4_i_st.site = &c4_lb_emlrtRSI;
        c4_k = 2;
        c4_exitg1 = false;
        while ((!c4_exitg1) && (c4_k < 181)) {
          c4_j_x = c4_c_x_data[c4_k - 1];
          c4_k_x = c4_j_x;
          c4_d_b = muDoubleScalarIsNaN(c4_k_x);
          c4_b_p = !c4_d_b;
          if (c4_b_p) {
            c4_b_idx = c4_k;
            c4_exitg1 = true;
          } else {
            c4_k++;
          }
        }
      }

      if (c4_b_idx == 0) {
        c4_max_angle = c4_b_x_data[0];
      } else {
        c4_h_st.site = &c4_jb_emlrtRSI;
        c4_b_loop_ub = c4_x_size[0] * c4_x_size[1] - 1;
        for (c4_i20 = 0; c4_i20 <= c4_b_loop_ub; c4_i20++) {
          c4_c_x_data[c4_i20] = c4_b_x_data[c4_i20];
        }

        c4_first = c4_b_idx - 1;
        c4_ex = c4_c_x_data[c4_first];
        c4_i22 = c4_first;
        c4_i_st.site = &c4_nb_emlrtRSI;
        c4_overflow = false;
        if (c4_overflow) {
          c4_j_st.site = &c4_mb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_j_st);
        }

        for (c4_b_k = c4_i22 + 1; c4_b_k + 1 < 181; c4_b_k++) {
          if (c4_ex < c4_c_x_data[c4_b_k]) {
            c4_ex = c4_c_x_data[c4_b_k];
          }
        }

        c4_max_angle = c4_ex;
      }
    }

    c4_b_st.site = &c4_i_emlrtRSI;
    c4_d_varargin_1[0] = c4_min_angle;
    c4_i18 = c4_lines->size[1];
    c4_i19 = (int32_T)emlrtIntegerCheckR2012b(c4_c_i, &c4_e_emlrtDCI, &c4_b_st);
    c4_d_varargin_1[1] = c4_lines->data[emlrtDynamicBoundsCheckR2012b(c4_i19, 1,
      c4_i18, &c4_e_emlrtBCI, &c4_b_st) - 1].theta;
    c4_c_st.site = &c4_nd_emlrtRSI;
    c4_d_st.site = &c4_od_emlrtRSI;
    c4_e_st.site = &c4_pd_emlrtRSI;
    c4_f_st.site = &c4_qd_emlrtRSI;
    c4_x_size[0] = 1;
    c4_x_size[1] = 2;
    for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
      c4_b_x_data[c4_i21] = c4_d_varargin_1[c4_i21];
    }

    c4_g_st.site = &c4_rd_emlrtRSI;
    c4_f_n = c4_x_size[1];
    if (c4_f_n <= 2) {
      if (c4_b_x_data[0] > c4_b_x_data[1]) {
        c4_min_angle = c4_b_x_data[1];
      } else {
        c4_l_x = c4_b_x_data[0];
        c4_e_b = muDoubleScalarIsNaN(c4_l_x);
        if (c4_e_b) {
          c4_n_x = c4_b_x_data[1];
          c4_f_b = muDoubleScalarIsNaN(c4_n_x);
          if (!c4_f_b) {
            c4_min_angle = c4_b_x_data[1];
          } else {
            c4_min_angle = c4_b_x_data[0];
          }
        } else {
          c4_min_angle = c4_b_x_data[0];
        }
      }
    } else {
      c4_h_st.site = &c4_kb_emlrtRSI;
      c4_c_loop_ub = c4_x_size[0] * c4_x_size[1] - 1;
      for (c4_i23 = 0; c4_i23 <= c4_c_loop_ub; c4_i23++) {
        c4_c_x_data[c4_i23] = c4_b_x_data[c4_i23];
      }

      c4_m_x = c4_c_x_data[0];
      c4_o_x = c4_m_x;
      c4_g_b = muDoubleScalarIsNaN(c4_o_x);
      c4_c_p = !c4_g_b;
      if (c4_c_p) {
        c4_c_idx = 1;
      } else {
        c4_c_idx = 0;
        c4_i_st.site = &c4_lb_emlrtRSI;
        c4_c_k = 2;
        c4_exitg1 = false;
        while ((!c4_exitg1) && (c4_c_k < 181)) {
          c4_p_x = c4_c_x_data[c4_c_k - 1];
          c4_q_x = c4_p_x;
          c4_h_b = muDoubleScalarIsNaN(c4_q_x);
          c4_d_p = !c4_h_b;
          if (c4_d_p) {
            c4_c_idx = c4_c_k;
            c4_exitg1 = true;
          } else {
            c4_c_k++;
          }
        }
      }

      if (c4_c_idx == 0) {
        c4_min_angle = c4_b_x_data[0];
      } else {
        c4_h_st.site = &c4_jb_emlrtRSI;
        c4_d_loop_ub = c4_x_size[0] * c4_x_size[1] - 1;
        for (c4_i24 = 0; c4_i24 <= c4_d_loop_ub; c4_i24++) {
          c4_c_x_data[c4_i24] = c4_b_x_data[c4_i24];
        }

        c4_b_first = c4_c_idx - 1;
        c4_b_ex = c4_c_x_data[c4_b_first];
        c4_i25 = c4_b_first;
        c4_i_st.site = &c4_nb_emlrtRSI;
        c4_b_overflow = false;
        if (c4_b_overflow) {
          c4_j_st.site = &c4_mb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_j_st);
        }

        for (c4_d_k = c4_i25 + 1; c4_d_k + 1 < 181; c4_d_k++) {
          if (c4_b_ex > c4_c_x_data[c4_d_k]) {
            c4_b_ex = c4_c_x_data[c4_d_k];
          }
        }

        c4_min_angle = c4_b_ex;
      }
    }

    c4_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 0, 0);
  if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c4_covrtInstance,
        4U, 0U, 0U, (real_T)c4_lines->size[1], 4.0, -1, 0U, (real_T)
        c4_lines->size[1] == 4.0))) {
    c4_b_mode = 1.0;
    c4_d1 = (real_T)c4_lines->size[1];
    c4_i6 = (int32_T)c4_d1;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, c4_d1, mxDOUBLE_CLASS, c4_i6,
      &c4_vi_emlrtRTEI, &c4_st);
    c4_d_i = 0;
    while (c4_d_i <= c4_i6 - 1) {
      c4_c_i = 1.0 + (real_T)c4_d_i;
      covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 1, 1);
      c4_i9 = c4_lines->size[1];
      c4_i10 = (int32_T)emlrtIntegerCheckR2012b(c4_c_i, &c4_c_emlrtDCI, &c4_st);
      c4_hough_angle = c4_lines->data[emlrtDynamicBoundsCheckR2012b(c4_i10, 1,
        c4_i9, &c4_c_emlrtBCI, &c4_st) - 1].theta;
      if (covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c4_covrtInstance, 4U, 0U, 1U,
                            c4_hough_angle, c4_angle_temp - 10.0, -1, 4U,
                            c4_hough_angle > c4_angle_temp - 10.0)) ||
          covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0, 1,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c4_covrtInstance, 4U, 0U, 2U,
                            c4_hough_angle, c4_angle_temp + 10.0, -1, 2U,
                            c4_hough_angle < c4_angle_temp + 10.0))) {
        covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 0, true);
        covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 1, true);
        c4_i12 = c4_lines->size[1];
        c4_i13 = (int32_T)emlrtIntegerCheckR2012b(c4_c_i, &c4_d_emlrtDCI, &c4_st);
        c4_angle = c4_lines->data[emlrtDynamicBoundsCheckR2012b(c4_i13, 1,
          c4_i12, &c4_d_emlrtBCI, &c4_st) - 1].theta;
        c4_i14 = c4_lines->size[1];
        c4_i16 = (int32_T)emlrtIntegerCheckR2012b(c4_c_i, &c4_emlrtDCI, &c4_st);
        c4_i17 = emlrtDynamicBoundsCheckR2012b(c4_i16, 1, c4_i14, &c4_emlrtBCI,
          &c4_st) - 1;
        c4_h_x = c4_lines->data[c4_i17].point1[0] + c4_angle;
        c4_temp_ = c4_h_x;
        c4_temp_ = muDoubleScalarSign(c4_temp_);
      } else {
        covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 0, false);
        covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 1, false);
      }

      if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 2, !c4_temp)) {
        c4_temp = true;
        c4_angle_temp = c4_angle;
      }

      c4_d_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c4_covrtInstance, 4U, 0, 1, 0);
    if (covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0, 2,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c4_covrtInstance, 4U, 0U, 4U, c4_angle,
                          0.0, -1, 2U, c4_angle < 0.0)) && covrtEmlCondEval
        (chartInstance->c4_covrtInstance, 4U, 0, 3, covrtRelationalopUpdateFcn
         (chartInstance->c4_covrtInstance, 4U, 0U, 5U, c4_temp_, 1.0, -1, 0U,
          c4_temp_ == 1.0))) {
      covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 1, true);
      covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 3, true);
      c4_angle += 180.0;
    } else {
      covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 1, false);
      covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 3, false);
      if (covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0, 4,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c4_covrtInstance, 4U, 0U, 6U,
                            c4_angle, 0.0, -1, 4U, c4_angle > 0.0)) &&
          covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0, 5,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c4_covrtInstance, 4U, 0U, 7U,
                            c4_temp_, -1.0, -1, 0U, c4_temp_ == -1.0))) {
        covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 2, true);
        covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 4, true);
        c4_angle -= 180.0;
      } else {
        covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 2, false);
        covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 4, false);
      }
    }
  }

  c4_emxFree_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c4_lines);
  c4_e_varargin_1 = c4_centers->size[0];
  c4_b_varargin_2 = c4_centers->size[1];
  c4_f_varargin_1 = c4_e_varargin_1;
  c4_c_varargin_2 = c4_b_varargin_2;
  if ((c4_f_varargin_1 == 0) || (c4_c_varargin_2 == 0)) {
    c4_n = 0;
  } else if (c4_f_varargin_1 > c4_c_varargin_2) {
    c4_n = c4_f_varargin_1;
  } else {
    c4_n = c4_c_varargin_2;
  }

  c4_b_n = (real_T)c4_n;
  c4_g_varargin_1 = c4_centers->size[0];
  c4_d_varargin_2 = c4_centers->size[1];
  c4_h_varargin_1 = c4_g_varargin_1;
  c4_e_varargin_2 = c4_d_varargin_2;
  c4_emxFree_real_T(chartInstance, &c4_centers);
  if ((c4_h_varargin_1 == 0) || (c4_e_varargin_2 == 0)) {
    c4_d_n = 0;
  } else if (c4_h_varargin_1 > c4_e_varargin_2) {
    c4_d_n = c4_h_varargin_1;
  } else {
    c4_d_n = c4_e_varargin_2;
  }

  c4_e_n = (real_T)c4_d_n;
  if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 5,
                     covrtRelationalopUpdateFcn(chartInstance->c4_covrtInstance,
        4U, 0U, 8U, c4_b_n, 2.0, -1, 0U, c4_e_n == 2.0))) {
    c4_b_mode = 2.0;
  }

  c4_b_output_angle = c4_angle;
  *chartInstance->c4_output_angle = c4_b_output_angle;
  *chartInstance->c4_mode = c4_b_mode;
  c4_do_animation_call_c4_flightControlSystem(chartInstance);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U,
                    *chartInstance->c4_output_angle);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 2U, *chartInstance->c4_mode);
}

static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c4_b_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c4_c_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c4_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c4_b_condTxtEndIdx[2] = { 1615, 1629 };

  static const int32_T c4_b_condTxtStartIdx[2] = { 1606, 1619 };

  static const int32_T c4_c_condTxtEndIdx[2] = { 1679, 1694 };

  static const int32_T c4_c_condTxtStartIdx[2] = { 1670, 1683 };

  static const int32_T c4_condTxtEndIdx[2] = { 1349, 1384 };

  static const int32_T c4_condTxtStartIdx[2] = { 1320, 1355 };

  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c4_chart_data_browse_helper);
  chartInstance->c4_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c4_RuntimeVar,
    &chartInstance->c4_IsDebuggerActive,
    &chartInstance->c4_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c4_mlFcnLineNumber, &chartInstance->c4_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    105U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 6U, 0U,
                  0U, 0U, 2U, 0U, 6U, 3U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 485, -1, 1801);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1206, 1227, -1,
                    1735);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 1316, 1385, -1,
                    1491);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 1500, 1516, -1,
                    1585);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 3U, 1603, 1629,
                    1663, 1694);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 4U, 1663, 1694, -1,
                    1694);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 5U, 1737, 1760, -1,
                    1778);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1078, 1102,
                     1204);
  covrtEmlForInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 1246, 1270,
                     1593);
  covrtEmlMCDCInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1319, 1385,
                      2U, 0U, c4_condTxtStartIdx, c4_condTxtEndIdx, 3U,
                      c4_postfixPredicateTree);
  covrtEmlMCDCInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 1606, 1629,
                      2U, 2U, c4_b_condTxtStartIdx, c4_b_condTxtEndIdx, 3U,
                      c4_b_postfixPredicateTree);
  covrtEmlMCDCInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 1670, 1694,
                      2U, 4U, c4_c_condTxtStartIdx, c4_c_condTxtEndIdx, 3U,
                      c4_c_postfixPredicateTree);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1209,
    1227, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 1320,
    1349, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 1355,
    1384, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 4U, 1606,
    1615, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 5U, 1619,
    1629, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 6U, 1670,
    1679, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 7U, 1683,
    1694, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 8U, 1740,
    1760, -1, 0U);
}

static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void initSimStructsc4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c4_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, uint8_T c4_d_varargin_1[19200],
                      real_T c4_yout[256])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_localBins1[256];
  real_T c4_localBins2[256];
  real_T c4_localBins3[256];
  real_T c4_b_out;
  real_T c4_d_i;
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_c;
  int32_T c4_c_c;
  int32_T c4_c_i;
  int32_T c4_d_c;
  int32_T c4_e_c;
  int32_T c4_f_c;
  int32_T c4_g_a;
  int32_T c4_g_c;
  int32_T c4_h_a;
  int32_T c4_h_c;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i_a;
  int32_T c4_i_c;
  int32_T c4_idx1;
  int32_T c4_idx2;
  int32_T c4_idx3;
  int32_T c4_idx4;
  int32_T c4_j_a;
  int32_T c4_j_c;
  int32_T c4_k_a;
  int32_T c4_l_a;
  int32_T c4_m_a;
  int32_T c4_n_a;
  int32_T c4_o_a;
  int32_T c4_p_a;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_o_emlrtRSI;
  c4_b_st.site = &c4_q_emlrtRSI;
  c4_b_out = 1.0;
  getnumcores(&c4_b_out);
  c4_b_st.site = &c4_p_emlrtRSI;
  for (c4_i = 0; c4_i < 256; c4_i++) {
    c4_yout[c4_i] = 0.0;
  }

  for (c4_i1 = 0; c4_i1 < 256; c4_i1++) {
    c4_localBins1[c4_i1] = 0.0;
  }

  for (c4_i2 = 0; c4_i2 < 256; c4_i2++) {
    c4_localBins2[c4_i2] = 0.0;
  }

  for (c4_i3 = 0; c4_i3 < 256; c4_i3++) {
    c4_localBins3[c4_i3] = 0.0;
  }

  for (c4_b_i = 4; c4_b_i <= 19200; c4_b_i += 4) {
    c4_i4 = c4_b_i - 3;
    c4_idx1 = c4_d_varargin_1[emlrtDynamicBoundsCheckR2012b(c4_i4, 1, 19200,
      &c4_f_emlrtBCI, &c4_b_st) - 1];
    c4_i5 = c4_b_i - 2;
    c4_idx2 = c4_d_varargin_1[emlrtDynamicBoundsCheckR2012b(c4_i5, 1, 19200,
      &c4_g_emlrtBCI, &c4_b_st) - 1];
    c4_i6 = c4_b_i - 1;
    c4_idx3 = c4_d_varargin_1[emlrtDynamicBoundsCheckR2012b(c4_i6, 1, 19200,
      &c4_h_emlrtBCI, &c4_b_st) - 1];
    c4_idx4 = c4_d_varargin_1[emlrtDynamicBoundsCheckR2012b(c4_b_i, 1, 19200,
      &c4_i_emlrtBCI, &c4_b_st) - 1];
    c4_i_a = c4_idx1 + 1;
    c4_c_c = c4_i_a - 1;
    c4_j_a = c4_idx1 + 1;
    c4_d_c = c4_j_a - 1;
    c4_localBins1[c4_c_c] = c4_localBins1[c4_d_c] + 1.0;
    c4_k_a = c4_idx2 + 1;
    c4_e_c = c4_k_a - 1;
    c4_l_a = c4_idx2 + 1;
    c4_f_c = c4_l_a - 1;
    c4_localBins2[c4_e_c] = c4_localBins2[c4_f_c] + 1.0;
    c4_m_a = c4_idx3 + 1;
    c4_g_c = c4_m_a - 1;
    c4_n_a = c4_idx3 + 1;
    c4_h_c = c4_n_a - 1;
    c4_localBins3[c4_g_c] = c4_localBins3[c4_h_c] + 1.0;
    c4_o_a = c4_idx4 + 1;
    c4_i_c = c4_o_a - 1;
    c4_p_a = c4_idx4 + 1;
    c4_j_c = c4_p_a - 1;
    c4_yout[c4_i_c] = c4_yout[c4_j_c] + 1.0;
  }

  while (c4_b_i - 3 <= 19200) {
    c4_b_idx = c4_d_varargin_1[c4_b_i - 4];
    c4_g_a = c4_b_idx + 1;
    c4_c = c4_g_a - 1;
    c4_h_a = c4_b_idx + 1;
    c4_b_c = c4_h_a - 1;
    c4_yout[c4_c] = c4_yout[c4_b_c] + 1.0;
    c4_b_i++;
  }

  for (c4_c_i = 0; c4_c_i < 256; c4_c_i++) {
    c4_d_i = (real_T)c4_c_i + 1.0;
    c4_yout[(int32_T)c4_d_i - 1] = ((c4_yout[(int32_T)c4_d_i - 1] +
      c4_localBins1[(int32_T)c4_d_i - 1]) + c4_localBins2[(int32_T)c4_d_i - 1])
      + c4_localBins3[(int32_T)c4_d_i - 1];
  }
}

static real_T c4_otsuthresh(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_counts[256])
{
  static char_T c4_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 't', 's',
    'u', 't', 'h', 'r', 'e', 's', 'h', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c4_b_cv1[6] = { 'C', 'O', 'U', 'N', 'T', 'S' };

  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_mu[256];
  real_T c4_omega[256];
  real_T c4_sigma_b_squared[256];
  real_T c4_b_idx;
  real_T c4_b_k;
  real_T c4_b_p;
  real_T c4_b_varargin_2;
  real_T c4_c;
  real_T c4_c_x;
  real_T c4_d_k;
  real_T c4_d_varargin_1;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_a;
  real_T c4_g_x;
  real_T c4_g_y;
  real_T c4_h_a;
  real_T c4_h_x;
  real_T c4_h_y;
  real_T c4_i_a;
  real_T c4_i_x;
  real_T c4_i_y;
  real_T c4_j_a;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_maxval;
  real_T c4_mu_t;
  real_T c4_n_x;
  real_T c4_num_elems;
  real_T c4_num_maxval;
  real_T c4_o_x;
  real_T c4_t;
  int32_T c4_c_k;
  int32_T c4_e_k;
  int32_T c4_f_k;
  int32_T c4_g_k;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b_b;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_e_b;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_isfinite_maxval;
  boolean_T c4_p;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_s_emlrtRSI;
  c4_b_st.site = &c4_u_emlrtRSI;
  c4_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 256)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_c_x = c4_counts[(int32_T)c4_b_k - 1];
    c4_d_x = c4_c_x;
    c4_b_b = muDoubleScalarIsInf(c4_d_x);
    c4_b1 = !c4_b_b;
    c4_e_x = c4_c_x;
    c4_c_b = muDoubleScalarIsNaN(c4_e_x);
    c4_b2 = !c4_c_b;
    c4_d_b = (c4_b1 && c4_b2);
    if (c4_d_b) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c4_b_st, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_b_st.site = &c4_u_emlrtRSI;
  c4_num_elems = 0.0;
  for (c4_c_k = 0; c4_c_k < 256; c4_c_k++) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    c4_num_elems += c4_counts[(int32_T)c4_d_k - 1];
  }

  c4_omega[0] = c4_counts[0] / c4_num_elems;
  c4_mu[0] = c4_omega[0];
  for (c4_e_k = 0; c4_e_k < 255; c4_e_k++) {
    c4_d_k = (real_T)c4_e_k + 2.0;
    c4_b_p = c4_counts[(int32_T)c4_d_k - 1] / c4_num_elems;
    c4_omega[(int32_T)c4_d_k - 1] = c4_omega[(int32_T)(c4_d_k - 1.0) - 1] +
      c4_b_p;
    c4_mu[(int32_T)c4_d_k - 1] = c4_mu[(int32_T)(c4_d_k - 1.0) - 1] + c4_b_p *
      c4_d_k;
  }

  c4_mu_t = c4_mu[255];
  c4_maxval = rtMinusInf;
  for (c4_f_k = 0; c4_f_k < 256; c4_f_k++) {
    c4_d_k = (real_T)c4_f_k + 1.0;
    c4_st.site = &c4_t_emlrtRSI;
    c4_g_a = c4_mu_t * c4_omega[(int32_T)c4_d_k - 1] - c4_mu[(int32_T)c4_d_k - 1];
    c4_b_st.site = &c4_v_emlrtRSI;
    c4_h_a = c4_g_a;
    c4_i_a = c4_h_a;
    c4_i_x = c4_i_a;
    c4_j_a = c4_i_x;
    c4_c = c4_j_a * c4_j_a;
    c4_sigma_b_squared[(int32_T)c4_d_k - 1] = c4_c / (c4_omega[(int32_T)c4_d_k -
      1] * (1.0 - c4_omega[(int32_T)c4_d_k - 1]));
    c4_d_varargin_1 = c4_maxval;
    c4_b_varargin_2 = c4_sigma_b_squared[(int32_T)c4_d_k - 1];
    c4_j_x = c4_d_varargin_1;
    c4_d_y = c4_b_varargin_2;
    c4_k_x = c4_j_x;
    c4_e_y = c4_d_y;
    c4_l_x = c4_k_x;
    c4_f_y = c4_e_y;
    c4_m_x = c4_l_x;
    c4_g_y = c4_f_y;
    c4_n_x = c4_m_x;
    c4_h_y = c4_g_y;
    c4_o_x = c4_n_x;
    c4_i_y = c4_h_y;
    c4_maxval = muDoubleScalarMax(c4_o_x, c4_i_y);
  }

  c4_f_x = c4_maxval;
  c4_g_x = c4_f_x;
  c4_e_b = muDoubleScalarIsInf(c4_g_x);
  c4_b3 = !c4_e_b;
  c4_h_x = c4_f_x;
  c4_f_b = muDoubleScalarIsNaN(c4_h_x);
  c4_b4 = !c4_f_b;
  c4_isfinite_maxval = (c4_b3 && c4_b4);
  if (c4_isfinite_maxval) {
    c4_b_idx = 0.0;
    c4_num_maxval = 0.0;
    for (c4_g_k = 0; c4_g_k < 256; c4_g_k++) {
      c4_d_k = (real_T)c4_g_k + 1.0;
      c4_b_idx += c4_d_k * (real_T)(c4_sigma_b_squared[(int32_T)c4_d_k - 1] ==
        c4_maxval);
      c4_num_maxval += (real_T)(c4_sigma_b_squared[(int32_T)c4_d_k - 1] ==
        c4_maxval);
    }

    c4_b_idx /= c4_num_maxval;
    c4_t = (c4_b_idx - 1.0) / 255.0;
  } else {
    c4_t = 0.0;
  }

  return c4_t;
}

static void c4_edge(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200],
                    boolean_T c4_varargout_1[19200])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_counts[64];
  real_T c4_b_data[1];
  real_T c4_b_highThresh_data[1];
  real_T c4_b_lowThresh_data[1];
  real_T c4_highThresh_data[1];
  real_T c4_lowThresh_data[1];
  real_T c4_c_idx;
  real_T c4_c_sum;
  real_T c4_highThreshTemp;
  int32_T c4_b_highThresh_size[1];
  int32_T c4_b_lowThresh_size[1];
  int32_T c4_highThresh_size[1];
  int32_T c4_lowThresh_size[1];
  int32_T c4_b_idx;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_loop_ub;
  real32_T c4_b;
  real32_T c4_b_b;
  real32_T c4_b_r;
  real32_T c4_b_varargin_2;
  real32_T c4_b_x1;
  real32_T c4_b_x2;
  real32_T c4_b_y;
  real32_T c4_c_x;
  real32_T c4_c_y;
  real32_T c4_d_x;
  real32_T c4_d_y;
  real32_T c4_e_varargin_1;
  real32_T c4_e_x;
  real32_T c4_e_y;
  real32_T c4_f_x;
  real32_T c4_f_y;
  real32_T c4_g_a;
  real32_T c4_g_x;
  real32_T c4_g_y;
  real32_T c4_h_a;
  real32_T c4_h_x;
  real32_T c4_h_y;
  real32_T c4_i_x;
  real32_T c4_i_y;
  real32_T c4_j_x;
  real32_T c4_j_y;
  real32_T c4_k_x;
  real32_T c4_k_y;
  real32_T c4_l_x;
  real32_T c4_l_y;
  real32_T c4_m_x;
  real32_T c4_m_y;
  real32_T c4_magmax;
  real32_T c4_n_x;
  real32_T c4_n_y;
  real32_T c4_r;
  real32_T c4_x1;
  real32_T c4_x2;
  real32_T c4_y;
  int8_T c4_d_idx;
  boolean_T c4_b_bv[19200];
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    chartInstance->c4_c_a[c4_i] = (real32_T)c4_d_varargin_1[c4_i];
  }

  c4_st.site = &c4_x_emlrtRSI;
  c4_b_st.site = &c4_bb_emlrtRSI;
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    chartInstance->c4_d_a[c4_i1] = chartInstance->c4_c_a[c4_i1];
  }

  c4_imfilter(chartInstance, &c4_b_st, chartInstance->c4_d_a,
              chartInstance->c4_dx);
  c4_b_st.site = &c4_cb_emlrtRSI;
  for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
    chartInstance->c4_b_dx[c4_i2] = chartInstance->c4_dx[c4_i2];
  }

  c4_b_imfilter(chartInstance, &c4_b_st, chartInstance->c4_b_dx,
                chartInstance->c4_dx);
  c4_b_st.site = &c4_db_emlrtRSI;
  c4_c_imfilter(chartInstance, &c4_b_st, chartInstance->c4_c_a,
                chartInstance->c4_dy);
  c4_b_st.site = &c4_eb_emlrtRSI;
  for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
    chartInstance->c4_b_dy[c4_i3] = chartInstance->c4_dy[c4_i3];
  }

  c4_d_imfilter(chartInstance, &c4_b_st, chartInstance->c4_b_dy,
                chartInstance->c4_dy);
  c4_c_x = chartInstance->c4_dx[0];
  c4_y = chartInstance->c4_dy[0];
  c4_d_x = c4_c_x;
  c4_b_y = c4_y;
  c4_e_x = c4_d_x;
  c4_c_y = c4_b_y;
  c4_x1 = c4_e_x;
  c4_x2 = c4_c_y;
  c4_g_a = c4_x1;
  c4_b = c4_x2;
  c4_r = muSingleScalarHypot(c4_g_a, c4_b);
  chartInstance->c4_c_a[0] = c4_r;
  c4_magmax = chartInstance->c4_c_a[0];
  for (c4_b_idx = 0; c4_b_idx < 19199; c4_b_idx++) {
    c4_c_idx = (real_T)c4_b_idx + 2.0;
    c4_f_x = chartInstance->c4_dx[(int32_T)c4_c_idx - 1];
    c4_f_y = chartInstance->c4_dy[(int32_T)c4_c_idx - 1];
    c4_g_x = c4_f_x;
    c4_g_y = c4_f_y;
    c4_h_x = c4_g_x;
    c4_h_y = c4_g_y;
    c4_b_x1 = c4_h_x;
    c4_b_x2 = c4_h_y;
    c4_h_a = c4_b_x1;
    c4_b_b = c4_b_x2;
    c4_b_r = muSingleScalarHypot(c4_h_a, c4_b_b);
    chartInstance->c4_c_a[(int32_T)c4_c_idx - 1] = c4_b_r;
    c4_e_varargin_1 = chartInstance->c4_c_a[(int32_T)c4_c_idx - 1];
    c4_b_varargin_2 = c4_magmax;
    c4_i_x = c4_e_varargin_1;
    c4_i_y = c4_b_varargin_2;
    c4_j_x = c4_i_x;
    c4_j_y = c4_i_y;
    c4_k_x = c4_j_x;
    c4_k_y = c4_j_y;
    c4_l_x = c4_k_x;
    c4_l_y = c4_k_y;
    c4_m_x = c4_l_x;
    c4_m_y = c4_l_y;
    c4_n_x = c4_m_x;
    c4_n_y = c4_m_y;
    c4_magmax = muSingleScalarMax(c4_n_x, c4_n_y);
  }

  if (c4_magmax > 0.0F) {
    c4_d_y = c4_magmax;
    c4_e_y = c4_d_y;
    for (c4_i4 = 0; c4_i4 < 19200; c4_i4++) {
      chartInstance->c4_c_a[c4_i4] /= c4_e_y;
    }
  }

  c4_st.site = &c4_y_emlrtRSI;
  c4_b_st.site = &c4_wb_emlrtRSI;
  for (c4_i5 = 0; c4_i5 < 19200; c4_i5++) {
    chartInstance->c4_f_a[c4_i5] = chartInstance->c4_c_a[c4_i5];
  }

  c4_b_imhist(chartInstance, &c4_b_st, chartInstance->c4_f_a, c4_counts);
  c4_c_sum = 0.0;
  c4_d_idx = 1;
  while ((!(c4_c_sum > 13440.0)) && ((real_T)c4_d_idx <= 64.0)) {
    c4_c_sum += c4_counts[c4_d_idx - 1];
    c4_i7 = c4_d_idx + 1;
    if (c4_i7 > 127) {
      c4_i7 = 127;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    } else {
      if (c4_i7 < -128) {
        c4_i7 = -128;
        sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
      }
    }

    c4_d_idx = (int8_T)c4_i7;
  }

  c4_i6 = c4_d_idx - 1;
  if (c4_i6 > 127) {
    c4_i6 = 127;
    sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
  } else {
    if (c4_i6 < -128) {
      c4_i6 = -128;
      sf_data_saturate_error(chartInstance->S, 1U, 0, 0);
    }
  }

  c4_highThreshTemp = (real_T)(int8_T)c4_i6 / 64.0;
  if (((real_T)c4_d_idx > 64.0) && (!(c4_c_sum > 13440.0))) {
    c4_highThresh_size[0] = 0;
    c4_lowThresh_size[0] = 0;
  } else {
    c4_highThresh_size[0] = 1;
    c4_highThresh_data[0] = c4_highThreshTemp;
    c4_loop_ub = c4_highThresh_size[0] - 1;
    for (c4_i8 = 0; c4_i8 <= c4_loop_ub; c4_i8++) {
      c4_b_data[c4_i8] = c4_highThresh_data[c4_i8];
    }

    c4_b_data[0] *= 0.4;
    c4_lowThresh_size[0] = 1;
    c4_lowThresh_data[0] = c4_b_data[0];
  }

  for (c4_i9 = 0; c4_i9 < 19200; c4_i9++) {
    c4_b_bv[c4_i9] = false;
  }

  c4_b_lowThresh_size[0] = c4_lowThresh_size[0];
  c4_b_loop_ub = c4_lowThresh_size[0] - 1;
  for (c4_i10 = 0; c4_i10 <= c4_b_loop_ub; c4_i10++) {
    c4_b_lowThresh_data[c4_i10] = c4_lowThresh_data[c4_i10];
  }

  c4_b_highThresh_size[0] = c4_highThresh_size[0];
  c4_c_loop_ub = c4_highThresh_size[0] - 1;
  for (c4_i11 = 0; c4_i11 <= c4_c_loop_ub; c4_i11++) {
    c4_b_highThresh_data[c4_i11] = c4_highThresh_data[c4_i11];
  }

  c4_st.site = &c4_ab_emlrtRSI;
  c4_thinAndThreshold(chartInstance, &c4_st, c4_b_bv, chartInstance->c4_dx,
                      chartInstance->c4_dy, chartInstance->c4_c_a,
                      c4_b_lowThresh_data, c4_b_lowThresh_size,
                      c4_b_highThresh_data, c4_b_highThresh_size, c4_varargout_1);
  c4_i12 = 1;
  emlrtDynamicBoundsCheckR2012b(c4_i12, 1, c4_lowThresh_size[0], &c4_j_emlrtBCI,
    c4_sp);
  c4_i13 = 1;
  emlrtDynamicBoundsCheckR2012b(c4_i13, 1, c4_highThresh_size[0], &c4_k_emlrtBCI,
    c4_sp);
}

static void c4_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200])
{
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  real32_T c4_e_varargin_1[19200];
  boolean_T c4_conn[13];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_fb_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_e_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_padImage(chartInstance, &c4_st, c4_e_varargin_1, chartInstance->c4_b_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 132.0 + 28.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 13.0 + -12.0 * (real_T)c4_i6;
    }

    ippfilter_real32(&chartInstance->c4_b_a[0], &c4_b[0], &c4_outSizeT[0], 2.0,
                     &c4_padSizeT[0], &c4_dv[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 13; c4_i1++) {
      c4_conn[c4_i1] = true;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_padSizeT[c4_i3] = 132.0 + 28.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_outSizeT[c4_i5] = 120.0 + 40.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_connDimsT[c4_i7] = 13.0 + -12.0 * (real_T)c4_i7;
    }

    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_startT[c4_i8] = 6.0 + -6.0 * (real_T)c4_i8;
    }

    imfilter_real32(&chartInstance->c4_b_a[0], &c4_b[0], 2.0, &c4_outSizeT[0],
                    2.0, &c4_padSizeT[0], &c4_dv[0], 13.0, &c4_conn[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[19200], real32_T c4_g_a[21120])
{
  static int32_T c4_idxA[320] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,
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

  emlrtStack c4_st;
  real_T c4_b_i;
  real_T c4_b_j;
  int32_T c4_c_i;
  int32_T c4_i;
  int32_T c4_j;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_hb_emlrtRSI;
  for (c4_j = 0; c4_j < 160; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 132; c4_i++) {
      c4_b_i = (real_T)c4_i + 1.0;
      c4_c_i = c4_idxA[(int32_T)c4_b_j + 159];
      c4_g_a[((int32_T)c4_b_i + 132 * ((int32_T)c4_b_j - 1)) - 1] = c4_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c4_idxA[(int32_T)c4_b_i - 1], 1, 120,
           &c4_l_emlrtBCI, &c4_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c4_c_i,
            1, 160, &c4_m_emlrtBCI, &c4_st) - 1)) - 1];
    }
  }
}

static void c4_check_forloop_overflow_error
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp)
{
  static char_T c4_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c4_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c4_sp, &c4_e_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14, sf_mex_call
              (c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c4_sp, NULL,
    "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
}

static void c4_b_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200])
{
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  real32_T c4_g_a[20640];
  real32_T c4_e_varargin_1[19200];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_fb_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_e_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_b_padImage(chartInstance, &c4_st, c4_e_varargin_1, c4_g_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 120.0 + 52.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 1.0 + 12.0 * (real_T)c4_i6;
    }

    ippfilter_real32(&c4_g_a[0], &c4_b[0], &c4_outSizeT[0], 2.0, &c4_padSizeT[0],
                     &c4_dv1[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      c4_padSizeT[c4_i1] = 120.0 + 52.0 * (real_T)c4_i1;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_outSizeT[c4_i3] = 120.0 + 40.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_connDimsT[c4_i5] = 1.0 + 12.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_startT[c4_i7] = 6.0 * (real_T)c4_i7;
    }

    imfilter_real32(&c4_g_a[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_dv2[0], 12.0, &c4_bv[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_b_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[19200], real32_T c4_g_a[20640])
{
  static int32_T c4_idxA[344] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
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

  emlrtStack c4_st;
  real_T c4_b_i;
  real_T c4_b_j;
  int32_T c4_c_i;
  int32_T c4_i;
  int32_T c4_j;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_hb_emlrtRSI;
  for (c4_j = 0; c4_j < 172; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 120; c4_i++) {
      c4_b_i = (real_T)c4_i + 1.0;
      c4_c_i = c4_idxA[(int32_T)c4_b_j + 171];
      c4_g_a[((int32_T)c4_b_i + 120 * ((int32_T)c4_b_j - 1)) - 1] = c4_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c4_idxA[(int32_T)c4_b_i - 1], 1, 120,
           &c4_l_emlrtBCI, &c4_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c4_c_i,
            1, 160, &c4_m_emlrtBCI, &c4_st) - 1)) - 1];
    }
  }
}

static void c4_c_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200])
{
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  real32_T c4_g_a[20640];
  real32_T c4_e_varargin_1[19200];
  boolean_T c4_conn[13];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_fb_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_e_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_b_padImage(chartInstance, &c4_st, c4_e_varargin_1, c4_g_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 120.0 + 52.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 1.0 + 12.0 * (real_T)c4_i6;
    }

    ippfilter_real32(&c4_g_a[0], &c4_b[0], &c4_outSizeT[0], 2.0, &c4_padSizeT[0],
                     &c4_dv[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 13; c4_i1++) {
      c4_conn[c4_i1] = true;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_padSizeT[c4_i3] = 120.0 + 52.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_outSizeT[c4_i5] = 120.0 + 40.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_connDimsT[c4_i7] = 1.0 + 12.0 * (real_T)c4_i7;
    }

    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_startT[c4_i8] = 6.0 * (real_T)c4_i8;
    }

    imfilter_real32(&c4_g_a[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_dv[0], 13.0, &c4_conn[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_d_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200])
{
  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  real32_T c4_e_varargin_1[19200];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_fb_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_e_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_padImage(chartInstance, &c4_st, c4_e_varargin_1, chartInstance->c4_e_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 132.0 + 28.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 13.0 + -12.0 * (real_T)c4_i6;
    }

    ippfilter_real32(&chartInstance->c4_e_a[0], &c4_b[0], &c4_outSizeT[0], 2.0,
                     &c4_padSizeT[0], &c4_dv1[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      c4_padSizeT[c4_i1] = 132.0 + 28.0 * (real_T)c4_i1;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_outSizeT[c4_i3] = 120.0 + 40.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_connDimsT[c4_i5] = 13.0 + -12.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_startT[c4_i7] = 6.0 + -6.0 * (real_T)c4_i7;
    }

    imfilter_real32(&chartInstance->c4_e_a[0], &c4_b[0], 2.0, &c4_outSizeT[0],
                    2.0, &c4_padSizeT[0], &c4_dv2[0], 12.0, &c4_bv[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_b_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real_T c4_yout[64])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_b_out;
  real_T c4_c_i;
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_c;
  int32_T c4_i;
  real32_T c4_b_idx;
  real32_T c4_c_x;
  real32_T c4_d_x;
  real32_T c4_g_a;
  real32_T c4_h_a;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_nanFlag;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_o_emlrtRSI;
  c4_b_st.site = &c4_q_emlrtRSI;
  c4_b_out = 1.0;
  getnumcores(&c4_b_out);
  for (c4_i = 0; c4_i < 64; c4_i++) {
    c4_yout[c4_i] = 0.0;
  }

  c4_nanFlag = false;
  for (c4_b_i = 0; c4_b_i < 19200; c4_b_i++) {
    c4_c_i = (real_T)c4_b_i + 1.0;
    c4_c_x = c4_d_varargin_1[(int32_T)c4_c_i - 1];
    c4_b = muSingleScalarIsNaN(c4_c_x);
    if (c4_b) {
      c4_nanFlag = true;
      c4_b_idx = 0.0F;
    } else {
      c4_b_idx = c4_d_varargin_1[(int32_T)c4_c_i - 1] * 63.0F + 0.5F;
    }

    if (c4_b_idx > 63.0F) {
      c4_yout[63]++;
    } else {
      c4_d_x = c4_d_varargin_1[(int32_T)c4_c_i - 1];
      c4_b_b = muSingleScalarIsInf(c4_d_x);
      if (c4_b_b) {
        c4_yout[63]++;
      } else {
        c4_g_a = c4_b_idx;
        c4_c = (int32_T)c4_g_a;
        c4_h_a = c4_b_idx;
        c4_b_c = (int32_T)c4_h_a;
        c4_yout[c4_c] = c4_yout[c4_b_c] + 1.0;
      }
    }
  }

  if (c4_nanFlag) {
    c4_b_st.site = &c4_xb_emlrtRSI;
    c4_warning(chartInstance, &c4_b_st);
  }
}

static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp)
{
  static char_T c4_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  static char_T c4_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  c4_st.site = &c4_r_emlrtRSI;
  c4_b_feval(chartInstance, &c4_st, c4_y, c4_feval(chartInstance, &c4_st, c4_b_y,
              c4_c_y));
}

static void c4_thinAndThreshold(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_E[19200], real32_T
  c4_c_dx[19200], real32_T c4_c_dy[19200], real32_T c4_magGrad[19200], real_T
  c4_lowThresh_data[], int32_T c4_lowThresh_size[1], real_T c4_highThresh_data[],
  int32_T c4_highThresh_size[1], boolean_T c4_b_H[19200])
{
  real_T c4_szT[2];
  real_T c4_b_lowThresh;
  real_T c4_highThresh;
  real_T c4_lowThresh;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  boolean_T c4_b_E[19200];
  boolean_T c4_marker[19200];
  c4_i = 1;
  emlrtDynamicBoundsCheckR2012b(c4_i, 1, c4_lowThresh_size[0], &c4_o_emlrtBCI,
    c4_sp);
  c4_lowThresh = c4_lowThresh_data[0];
  c4_b_lowThresh = c4_lowThresh;
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_szT[c4_i1] = 120.0 + 40.0 * (real_T)c4_i1;
  }

  cannythresholding_real32_tbb(&c4_c_dx[0], &c4_c_dy[0], &c4_magGrad[0],
    &c4_szT[0], c4_b_lowThresh, &c4_E[0]);
  c4_i2 = 1;
  emlrtDynamicBoundsCheckR2012b(c4_i2, 1, c4_highThresh_size[0], &c4_n_emlrtBCI,
    c4_sp);
  c4_highThresh = c4_highThresh_data[0];
  for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
    c4_marker[c4_i3] = ((real_T)c4_magGrad[c4_i3] > c4_highThresh);
  }

  for (c4_i4 = 0; c4_i4 < 19200; c4_i4++) {
    c4_b_E[c4_i4] = c4_E[c4_i4];
  }

  c4_imreconstruct(chartInstance, c4_marker, c4_b_E, c4_b_H);
}

static void c4_imreconstruct(SFc4_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c4_marker[19200], boolean_T c4_mask[19200],
  boolean_T c4_im[19200])
{
  real_T c4_imSizeT[2];
  int32_T c4_i;
  int32_T c4_i1;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_im[c4_i] = c4_marker[c4_i];
  }

  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_imSizeT[c4_i1] = 120.0 + 40.0 * (real_T)c4_i1;
  }

  ippreconstruct_uint8((uint8_T *)&c4_im[0], (uint8_T *)&c4_mask[0],
                       &c4_imSizeT[0], 2.0);
}

static void c4_bwmorph(SFc4_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c4_bwin[19200], boolean_T c4_bw[19200])
{
  real_T c4_b_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_k;
  boolean_T c4_last_aout[19200];
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  boolean_T c4_x1;
  boolean_T c4_x2;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_bw[c4_i] = c4_bwin[c4_i];
  }

  do {
    for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
      c4_last_aout[c4_i1] = c4_bw[c4_i1];
    }

    c4_b_bwmorphApplyOnce(chartInstance, c4_bw);
    c4_p = false;
    c4_b_p = true;
    c4_k = 0;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k < 19200)) {
      c4_b_k = (real_T)c4_k + 1.0;
      c4_x1 = c4_last_aout[(int32_T)c4_b_k - 1];
      c4_x2 = c4_bw[(int32_T)c4_b_k - 1];
      c4_c_p = ((int32_T)c4_x1 == (int32_T)c4_x2);
      if (!c4_c_p) {
        c4_b_p = false;
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }

    if (c4_b_p) {
      c4_p = true;
    }
  } while (!c4_p);
}

static void c4_bwmorphApplyOnce(SFc4_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c4_bw[19200], boolean_T c4_b_bw[19200])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_b_bw[c4_i] = c4_bw[c4_i];
  }

  c4_b_bwmorphApplyOnce(chartInstance, c4_b_bw);
}

static void c4_bwlookup(SFc4_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c4_bwin[19200], boolean_T c4_B[19200])
{
  static boolean_T c4_lut[512] = { false, false, false, false, false, false,
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

  real_T c4_sizeIn[2];
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_sizeIn[c4_i] = 120.0 + 40.0 * (real_T)c4_i;
  }

  bwlookup_tbb_boolean(&c4_bwin[0], &c4_sizeIn[0], 2.0, &c4_lut[0], 512.0,
                       &c4_B[0]);
}

static void c4_b_bwlookup(SFc4_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c4_bwin[19200], boolean_T c4_B[19200])
{
  static boolean_T c4_lut[512] = { false, false, false, false, false, false,
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

  real_T c4_sizeIn[2];
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_sizeIn[c4_i] = 120.0 + 40.0 * (real_T)c4_i;
  }

  bwlookup_tbb_boolean(&c4_bwin[0], &c4_sizeIn[0], 2.0, &c4_lut[0], 512.0,
                       &c4_B[0]);
}

static void c4_e_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200])
{
  static real_T c4_kernel[25] = { 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822,
    0.028084023356349175, 0.054700208300935887, 0.068312293270780214,
    0.054700208300935887, 0.028084023356349175, 0.0350727008055935,
    0.068312293270780214, 0.085311730190125085, 0.068312293270780214,
    0.0350727008055935, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.0350727008055935,
    0.028084023356349175, 0.014418818362460822 };

  static real_T c4_nonZeroKernel[25] = { 0.014418818362460822,
    0.028084023356349175, 0.0350727008055935, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.0350727008055935, 0.068312293270780214, 0.085311730190125085,
    0.068312293270780214, 0.0350727008055935, 0.028084023356349175,
    0.054700208300935887, 0.068312293270780214, 0.054700208300935887,
    0.028084023356349175, 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822 };

  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  real32_T c4_g_a[20336];
  real32_T c4_e_varargin_1[19200];
  boolean_T c4_conn[25];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_fb_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_e_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_c_padImage(chartInstance, &c4_st, c4_e_varargin_1, c4_g_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 124.0 + 40.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 5.0;
    }

    ippfilter_real32(&c4_g_a[0], &c4_b[0], &c4_outSizeT[0], 2.0, &c4_padSizeT[0],
                     &c4_kernel[0], &c4_connDimsT[0], false);
  } else {
    for (c4_i1 = 0; c4_i1 < 25; c4_i1++) {
      c4_conn[c4_i1] = true;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_padSizeT[c4_i3] = 124.0 + 40.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_outSizeT[c4_i5] = 120.0 + 40.0 * (real_T)c4_i5;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_connDimsT[c4_i7] = 5.0;
    }

    for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
      c4_startT[c4_i8] = 2.0;
    }

    imfilter_real32(&c4_g_a[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_nonZeroKernel[0], 25.0, &c4_conn[0],
                    2.0, &c4_connDimsT[0], &c4_startT[0], 2.0, true, false);
  }
}

static void c4_c_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[19200], real32_T c4_g_a[20336])
{
  static int32_T c4_idxA[328] = { 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
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

  emlrtStack c4_st;
  real_T c4_b_i;
  real_T c4_b_j;
  int32_T c4_c_i;
  int32_T c4_i;
  int32_T c4_j;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_hb_emlrtRSI;
  for (c4_j = 0; c4_j < 164; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 124; c4_i++) {
      c4_b_i = (real_T)c4_i + 1.0;
      c4_c_i = c4_idxA[(int32_T)c4_b_j + 163];
      c4_g_a[((int32_T)c4_b_i + 124 * ((int32_T)c4_b_j - 1)) - 1] = c4_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c4_idxA[(int32_T)c4_b_i - 1], 1, 120,
           &c4_l_emlrtBCI, &c4_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c4_c_i,
            1, 160, &c4_m_emlrtBCI, &c4_st) - 1)) - 1];
    }
  }
}

static void c4_f_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200])
{
  static real_T c4_kernel[9] = { -1.0, -2.0, -1.0, -0.0, -0.0, -0.0, 1.0, 2.0,
    1.0 };

  static real_T c4_nonZeroKernel[6] = { -1.0, -2.0, -1.0, 1.0, 2.0, 1.0 };

  static boolean_T c4_conn[9] = { true, true, true, false, false, false, true,
    true, true };

  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  real32_T c4_g_a[19764];
  real32_T c4_e_varargin_1[19200];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_fb_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_e_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_d_padImage(chartInstance, &c4_st, c4_e_varargin_1, c4_g_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 122.0 + 40.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 3.0;
    }

    ippfilter_real32(&c4_g_a[0], &c4_b[0], &c4_outSizeT[0], 2.0, &c4_padSizeT[0],
                     &c4_kernel[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      c4_padSizeT[c4_i1] = 122.0 + 40.0 * (real_T)c4_i1;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_outSizeT[c4_i3] = 120.0 + 40.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_connDimsT[c4_i5] = 3.0;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_startT[c4_i7] = 1.0;
    }

    imfilter_real32(&c4_g_a[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_nonZeroKernel[0], 6.0, &c4_conn[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_d_padImage(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_a_tmp[19200], real32_T c4_g_a[19764])
{
  static int32_T c4_idxA[324] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
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

  emlrtStack c4_st;
  real_T c4_b_i;
  real_T c4_b_j;
  int32_T c4_c_i;
  int32_T c4_i;
  int32_T c4_j;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_hb_emlrtRSI;
  for (c4_j = 0; c4_j < 162; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 122; c4_i++) {
      c4_b_i = (real_T)c4_i + 1.0;
      c4_c_i = c4_idxA[(int32_T)c4_b_j + 161];
      c4_g_a[((int32_T)c4_b_i + 122 * ((int32_T)c4_b_j - 1)) - 1] = c4_a_tmp
        [(emlrtDynamicBoundsCheckR2012b(c4_idxA[(int32_T)c4_b_i - 1], 1, 120,
           &c4_l_emlrtBCI, &c4_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c4_c_i,
            1, 160, &c4_m_emlrtBCI, &c4_st) - 1)) - 1];
    }
  }
}

static void c4_g_imfilter(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200], real32_T c4_b[19200])
{
  static real_T c4_kernel[9] = { -1.0, -0.0, 1.0, -2.0, -0.0, 2.0, -1.0, -0.0,
    1.0 };

  static real_T c4_nonZeroKernel[6] = { -1.0, 1.0, -2.0, 2.0, -1.0, 1.0 };

  static boolean_T c4_conn[9] = { true, false, true, true, false, true, true,
    false, true };

  emlrtStack c4_st;
  real_T c4_connDimsT[2];
  real_T c4_outSizeT[2];
  real_T c4_padSizeT[2];
  real_T c4_startT[2];
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  real32_T c4_g_a[19764];
  real32_T c4_e_varargin_1[19200];
  boolean_T c4_b_modeFlag;
  boolean_T c4_c_modeFlag;
  boolean_T c4_modeFlag;
  boolean_T c4_tooBig;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_fb_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_e_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_d_padImage(chartInstance, &c4_st, c4_e_varargin_1, c4_g_a);
  c4_tooBig = true;
  for (c4_b_i = 0; c4_b_i < 2; c4_b_i++) {
    c4_tooBig = false;
  }

  if (!c4_tooBig) {
    c4_modeFlag = true;
  } else {
    c4_modeFlag = false;
  }

  if (c4_modeFlag) {
    c4_b_modeFlag = true;
  } else {
    c4_b_modeFlag = false;
  }

  c4_c_modeFlag = c4_b_modeFlag;
  if (c4_c_modeFlag) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_padSizeT[c4_i2] = 122.0 + 40.0 * (real_T)c4_i2;
    }

    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_outSizeT[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
      c4_connDimsT[c4_i6] = 3.0;
    }

    ippfilter_real32(&c4_g_a[0], &c4_b[0], &c4_outSizeT[0], 2.0, &c4_padSizeT[0],
                     &c4_kernel[0], &c4_connDimsT[0], true);
  } else {
    for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
      c4_padSizeT[c4_i1] = 122.0 + 40.0 * (real_T)c4_i1;
    }

    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_outSizeT[c4_i3] = 120.0 + 40.0 * (real_T)c4_i3;
    }

    for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
      c4_connDimsT[c4_i5] = 3.0;
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_startT[c4_i7] = 1.0;
    }

    imfilter_real32(&c4_g_a[0], &c4_b[0], 2.0, &c4_outSizeT[0], 2.0,
                    &c4_padSizeT[0], &c4_nonZeroKernel[0], 6.0, &c4_conn[0], 2.0,
                    &c4_connDimsT[0], &c4_startT[0], 2.0, true, true);
  }
}

static void c4_hypot(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     real32_T c4_c_x[19200], real32_T c4_y[19200], real32_T
                     c4_r[19200])
{
  int32_T c4_b_k;
  int32_T c4_k;
  real32_T c4_b;
  real32_T c4_b_y;
  real32_T c4_d_x;
  real32_T c4_g_a;
  real32_T c4_x1;
  real32_T c4_x2;
  real32_T c4_z;
  (void)chartInstance;
  for (c4_k = 0; c4_k < 19200; c4_k++) {
    c4_b_k = c4_k;
    c4_d_x = c4_c_x[c4_b_k];
    c4_b_y = c4_y[c4_b_k];
    c4_x1 = c4_d_x;
    c4_x2 = c4_b_y;
    c4_g_a = c4_x1;
    c4_b = c4_x2;
    c4_z = muSingleScalarHypot(c4_g_a, c4_b);
    c4_r[c4_b_k] = c4_z;
  }
}

static real32_T c4_maximum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_c_x[19200])
{
  c4_emxArray_real32_T *c4_d_x;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_first;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  real32_T c4_b_ex;
  real32_T c4_e_x;
  real32_T c4_ex;
  real32_T c4_f_x;
  real32_T c4_g_x;
  real32_T c4_h_x;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_d_x, 1, &c4_emlrtRTEI);
  c4_st.site = &c4_ub_emlrtRSI;
  c4_b_st.site = &c4_vb_emlrtRSI;
  c4_i = c4_d_x->size[0];
  c4_d_x->size[0] = 19200;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_d_x, c4_i,
    &c4_emlrtRTEI);
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x[c4_i1];
  }

  c4_c_st.site = &c4_ib_emlrtRSI;
  c4_d_st.site = &c4_kb_emlrtRSI;
  c4_e_x = c4_d_x->data[0];
  c4_f_x = c4_e_x;
  c4_b = muSingleScalarIsNaN(c4_f_x);
  c4_p = !c4_b;
  if (c4_p) {
    c4_b_idx = 1;
  } else {
    c4_b_idx = 0;
    c4_e_st.site = &c4_lb_emlrtRSI;
    c4_k = 2;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k < 19201)) {
      c4_g_x = c4_d_x->data[c4_k - 1];
      c4_h_x = c4_g_x;
      c4_b_b = muSingleScalarIsNaN(c4_h_x);
      c4_b_p = !c4_b_b;
      if (c4_b_p) {
        c4_b_idx = c4_k;
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }
  }

  if (c4_b_idx == 0) {
    c4_ex = c4_d_x->data[0];
  } else {
    c4_d_st.site = &c4_jb_emlrtRSI;
    c4_first = c4_b_idx - 1;
    c4_b_ex = c4_d_x->data[c4_first];
    c4_i2 = c4_first;
    c4_e_st.site = &c4_nb_emlrtRSI;
    c4_overflow = false;
    if (c4_overflow) {
      c4_f_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
    }

    for (c4_b_k = c4_i2 + 1; c4_b_k + 1 < 19201; c4_b_k++) {
      if (c4_b_ex < c4_d_x->data[c4_b_k]) {
        c4_b_ex = c4_d_x->data[c4_b_k];
      }
    }

    c4_ex = c4_b_ex;
  }

  c4_emxFree_real32_T(chartInstance, &c4_d_x);
  return c4_ex;
}

static void c4_imfindcircles(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200],
  c4_emxArray_real_T *c4_centers)
{
  static creal_T c4_dc = { 0.0,        /* re */
    0.0                                /* im */
  };

  c4_emxArray_boolean_T *c4_f_x;
  c4_emxArray_creal_T *c4_c_x;
  c4_emxArray_int32_T *c4_ii;
  c4_emxArray_real_T *c4_b_centers;
  c4_emxArray_real_T *c4_idx2Keep;
  c4_emxArray_real_T *c4_metric;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  creal_T c4_e_x;
  real_T c4_b_k;
  int32_T c4_iv[2];
  int32_T c4_b_idx;
  int32_T c4_b_ii;
  int32_T c4_b_loop_ub;
  int32_T c4_b_metric;
  int32_T c4_b_nx;
  int32_T c4_c_b;
  int32_T c4_c_centers;
  int32_T c4_c_ii;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_d_b;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_nx;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b_b;
  boolean_T c4_d_x;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_y;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_centers->size[0] = 0;
  c4_centers->size[1] = 0;
  c4_st.site = &c4_lc_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    chartInstance->c4_c_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_chaccum(chartInstance, &c4_st, chartInstance->c4_c_varargin_1,
             chartInstance->c4_accumMatrix, chartInstance->c4_gradientImg);
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    chartInstance->c4_x[c4_i1] = chartInstance->c4_accumMatrix[c4_i1];
  }

  c4_emxInit_creal_T(chartInstance, c4_sp, &c4_c_x, 1, &c4_n_emlrtRTEI);
  c4_i2 = c4_c_x->size[0];
  c4_c_x->size[0] = 19200;
  c4_emxEnsureCapacity_creal_T(chartInstance, c4_sp, c4_c_x, c4_i2,
    &c4_n_emlrtRTEI);
  for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
    c4_c_x->data[c4_i3] = chartInstance->c4_x[c4_i3];
  }

  c4_y = false;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 19200)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_d_x = ((c4_c_x->data[(int32_T)c4_b_k - 1].re == c4_dc.re) &&
              (c4_c_x->data[(int32_T)c4_b_k - 1].im == c4_dc.im));
    if (c4_d_x) {
      c4_b = true;
    } else {
      c4_e_x = c4_c_x->data[(int32_T)c4_b_k - 1];
      c4_b1 = muDoubleScalarIsNaN(c4_e_x.re);
      c4_b2 = muDoubleScalarIsNaN(c4_e_x.im);
      c4_b_b = (c4_b1 || c4_b2);
      if (c4_b_b) {
        c4_b = true;
      } else {
        c4_b = false;
      }
    }

    if (!c4_b) {
      c4_y = true;
      c4_exitg1 = true;
    } else {
      c4_k++;
    }
  }

  c4_emxFree_creal_T(chartInstance, &c4_c_x);
  if (c4_y) {
    c4_emxInit_real_T(chartInstance, c4_sp, &c4_b_centers, 2, &c4_u_emlrtRTEI);
    c4_emxInit_real_T(chartInstance, c4_sp, &c4_metric, 2, &c4_u_emlrtRTEI);
    c4_st.site = &c4_mc_emlrtRSI;
    c4_chcenters(chartInstance, &c4_st, chartInstance->c4_accumMatrix,
                 c4_b_centers, c4_metric);
    c4_i4 = c4_centers->size[0] * c4_centers->size[1];
    c4_centers->size[0] = c4_b_centers->size[0];
    c4_centers->size[1] = c4_b_centers->size[1];
    c4_st.site = &c4_mc_emlrtRSI;
    c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_centers, c4_i4,
      &c4_o_emlrtRTEI);
    c4_loop_ub = c4_b_centers->size[0] * c4_b_centers->size[1] - 1;
    for (c4_i5 = 0; c4_i5 <= c4_loop_ub; c4_i5++) {
      c4_centers->data[c4_i5] = c4_b_centers->data[c4_i5];
    }

    c4_b3 = (c4_b_centers->size[0] == 0);
    c4_b4 = (c4_b_centers->size[1] == 0);
    if (!(c4_b3 || c4_b4)) {
      c4_emxInit_boolean_T(chartInstance, c4_sp, &c4_f_x, 2, &c4_p_emlrtRTEI);
      c4_st.site = &c4_nc_emlrtRSI;
      c4_i6 = c4_f_x->size[0] * c4_f_x->size[1];
      c4_f_x->size[0] = c4_metric->size[0];
      c4_f_x->size[1] = c4_metric->size[1];
      c4_b_st.site = &c4_nc_emlrtRSI;
      c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_b_st, c4_f_x, c4_i6,
        &c4_p_emlrtRTEI);
      c4_b_loop_ub = c4_metric->size[0] * c4_metric->size[1] - 1;
      for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
        c4_f_x->data[c4_i7] = (c4_metric->data[c4_i7] >= 0.15000000000000002);
      }

      c4_emxInit_int32_T(chartInstance, &c4_st, &c4_ii, 1, &c4_v_emlrtRTEI);
      c4_b_st.site = &c4_yi_emlrtRSI;
      c4_nx = c4_f_x->size[0] * c4_f_x->size[1];
      c4_c_st.site = &c4_aj_emlrtRSI;
      c4_c_k = c4_nx;
      c4_b_nx = c4_nx;
      c4_b_idx = 0;
      c4_i8 = c4_ii->size[0];
      c4_ii->size[0] = c4_c_k;
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_ii, c4_i8,
        &c4_q_emlrtRTEI);
      c4_d_st.site = &c4_bj_emlrtRSI;
      c4_c_b = c4_b_nx;
      c4_d_b = c4_c_b;
      if (1 > c4_d_b) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_d_b > 2147483646);
      }

      if (c4_overflow) {
        c4_e_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      c4_b_ii = 1;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_b_ii - 1 <= c4_b_nx - 1)) {
        c4_c_ii = c4_b_ii;
        if (c4_f_x->data[c4_c_ii - 1]) {
          c4_b_idx++;
          c4_ii->data[c4_b_idx - 1] = c4_c_ii;
          if (c4_b_idx >= c4_c_k) {
            c4_exitg1 = true;
          } else {
            c4_b_ii++;
          }
        } else {
          c4_b_ii++;
        }
      }

      c4_emxFree_boolean_T(chartInstance, &c4_f_x);
      if (!(c4_b_idx <= c4_c_k)) {
        c4_b_y = NULL;
        sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        c4_c_y = NULL;
        sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call(&c4_c_st, &c4_x_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                    sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c4_c_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
      }

      if (c4_c_k == 1) {
        if (c4_b_idx == 0) {
          c4_ii->size[0] = 0;
        }
      } else {
        c4_b5 = (1 > c4_b_idx);
        if (c4_b5) {
          c4_i9 = 0;
        } else {
          c4_i9 = c4_b_idx;
        }

        c4_iv[0] = 1;
        c4_iv[1] = c4_i9;
        c4_d_st.site = &c4_cj_emlrtRSI;
        c4_indexShapeCheck(chartInstance, &c4_d_st, c4_ii->size[0], c4_iv);
        c4_i11 = c4_ii->size[0];
        c4_ii->size[0] = c4_i9;
        c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_ii, c4_i11,
          &c4_s_emlrtRTEI);
      }

      c4_emxInit_real_T1(chartInstance, &c4_c_st, &c4_idx2Keep, 1,
                         &c4_r_emlrtRTEI);
      c4_i10 = c4_idx2Keep->size[0];
      c4_idx2Keep->size[0] = c4_ii->size[0];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_idx2Keep, c4_i10,
        &c4_r_emlrtRTEI);
      c4_c_loop_ub = c4_ii->size[0] - 1;
      for (c4_i12 = 0; c4_i12 <= c4_c_loop_ub; c4_i12++) {
        c4_idx2Keep->data[c4_i12] = (real_T)c4_ii->data[c4_i12];
      }

      c4_emxFree_int32_T(chartInstance, &c4_ii);
      c4_c_centers = c4_b_centers->size[0];
      c4_i13 = c4_b_centers->size[1] - 1;
      c4_i14 = c4_centers->size[0] * c4_centers->size[1];
      c4_centers->size[0] = c4_idx2Keep->size[0];
      c4_centers->size[1] = c4_i13 + 1;
      c4_st.site = &c4_al_emlrtRSI;
      c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_centers, c4_i14,
        &c4_t_emlrtRTEI);
      c4_d_loop_ub = c4_i13;
      for (c4_i15 = 0; c4_i15 <= c4_d_loop_ub; c4_i15++) {
        c4_e_loop_ub = c4_idx2Keep->size[0] - 1;
        for (c4_i16 = 0; c4_i16 <= c4_e_loop_ub; c4_i16++) {
          c4_i18 = (int32_T)c4_idx2Keep->data[c4_i16];
          c4_centers->data[c4_i16 + c4_centers->size[0] * c4_i15] =
            c4_b_centers->data[(emlrtDynamicBoundsCheckR2012b(c4_i18, 1,
            c4_c_centers, &c4_p_emlrtBCI, c4_sp) + c4_b_centers->size[0] *
                                c4_i15) - 1];
        }
      }

      c4_b_metric = c4_metric->size[0];
      c4_f_loop_ub = c4_idx2Keep->size[0] - 1;
      for (c4_i17 = 0; c4_i17 <= c4_f_loop_ub; c4_i17++) {
        c4_i19 = (int32_T)c4_idx2Keep->data[c4_i17];
        emlrtDynamicBoundsCheckR2012b(c4_i19, 1, c4_b_metric, &c4_q_emlrtBCI,
          c4_sp);
      }

      c4_emxFree_real_T(chartInstance, &c4_idx2Keep);
      c4_b6 = (c4_centers->size[0] == 0);
      c4_b7 = (c4_centers->size[1] == 0);
      if (c4_b6 || c4_b7) {
        c4_centers->size[0] = 0;
        c4_centers->size[1] = 0;
      }
    }

    c4_emxFree_real_T(chartInstance, &c4_metric);
    c4_emxFree_real_T(chartInstance, &c4_b_centers);
  }
}

static void c4_chaccum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200], creal_T
  c4_b_accumMatrix[19200], real32_T c4_b_gradientImg[19200])
{
  static creal_T c4_Opca[51] = { { -1.0,/* re */
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

  static real_T c4_b_dv[51] = { 94.247779607693786, 97.389372261283583,
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

  c4_emxArray_boolean_T *c4_inside;
  c4_emxArray_creal_T *c4_w;
  c4_emxArray_creal_T *c4_wkeep;
  c4_emxArray_int32_T *c4_ii;
  c4_emxArray_int32_T *c4_jj;
  c4_emxArray_int32_T *c4_r;
  c4_emxArray_int32_T *c4_xckeep;
  c4_emxArray_int32_T *c4_yckeep;
  c4_emxArray_real32_T *c4_xc;
  c4_emxArray_real32_T *c4_yc;
  c4_emxArray_real_T *c4_Ex;
  c4_emxArray_real_T *c4_Ex_chunk;
  c4_emxArray_real_T *c4_Ey;
  c4_emxArray_real_T *c4_Ey_chunk;
  c4_emxArray_real_T *c4_b_varargin_2;
  c4_emxArray_real_T *c4_idxE;
  c4_emxArray_real_T *c4_idxE_chunk;
  c4_emxArray_real_T *c4_ndx;
  c4_emxArray_real_T *c4_r1;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  creal_T c4_w0[51];
  real_T c4_a1;
  real_T c4_absa;
  real_T c4_absb;
  real_T c4_ai;
  real_T c4_apnd;
  real_T c4_ar;
  real_T c4_b;
  real_T c4_b1;
  real_T c4_b_d;
  real_T c4_b_idx1;
  real_T c4_b_idx2;
  real_T c4_b_k;
  real_T c4_b_s;
  real_T c4_bi;
  real_T c4_bim;
  real_T c4_br;
  real_T c4_brm;
  real_T c4_c;
  real_T c4_c_i;
  real_T c4_c_idx;
  real_T c4_c_varargin_2;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_cdiff;
  real_T c4_d;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_dim1;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_b;
  real_T c4_f_varargin_1;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_g_x;
  real_T c4_g_y;
  real_T c4_h_a;
  real_T c4_h_b;
  real_T c4_h_x;
  real_T c4_h_y;
  real_T c4_i_a;
  real_T c4_i_x;
  real_T c4_i_y;
  real_T c4_j_a;
  real_T c4_j_x;
  real_T c4_k_a;
  real_T c4_k_x;
  real_T c4_kd;
  real_T c4_l_x;
  real_T c4_lenE;
  real_T c4_m_a;
  real_T c4_m_x;
  real_T c4_minval;
  real_T c4_n_a;
  real_T c4_n_x;
  real_T c4_ndbl;
  real_T c4_ni;
  real_T c4_nr;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_s_x;
  real_T c4_sgnbi;
  real_T c4_sgnbr;
  real_T c4_sizeChunk;
  real_T c4_t_x;
  real_T c4_thresh;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_w_x;
  real_T c4_x_x;
  int32_T c4_rows_to_keep_size[1];
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_b_loop_ub;
  int32_T c4_c_idx1;
  int32_T c4_c_idx2;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_d_idx;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_e_idx;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i100;
  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i108;
  int32_T c4_i109;
  int32_T c4_i11;
  int32_T c4_i110;
  int32_T c4_i111;
  int32_T c4_i112;
  int32_T c4_i113;
  int32_T c4_i114;
  int32_T c4_i115;
  int32_T c4_i116;
  int32_T c4_i117;
  int32_T c4_i118;
  int32_T c4_i119;
  int32_T c4_i12;
  int32_T c4_i120;
  int32_T c4_i121;
  int32_T c4_i122;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i9;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  int32_T c4_i99;
  int32_T c4_i_b;
  int32_T c4_idx1;
  int32_T c4_idx2;
  int32_T c4_idxEdge;
  int32_T c4_idxkeep;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_l_a;
  int32_T c4_l_b;
  int32_T c4_loop_ub;
  int32_T c4_m_b;
  int32_T c4_m_y;
  int32_T c4_n;
  int32_T c4_n_b;
  int32_T c4_nm1;
  int32_T c4_nm1d2;
  int32_T c4_szxc;
  real32_T c4_Gmax;
  real32_T c4_ab_x;
  real32_T c4_b_y;
  real32_T c4_b_z;
  real32_T c4_bb_x;
  real32_T c4_cb_x;
  real32_T c4_db_x;
  real32_T c4_eb_x;
  real32_T c4_edgeThresh;
  real32_T c4_j_y;
  real32_T c4_k_b;
  real32_T c4_k_y;
  real32_T c4_l_y;
  real32_T c4_n_y;
  real32_T c4_o_b;
  real32_T c4_o_y;
  real32_T c4_p_y;
  real32_T c4_q_y;
  real32_T c4_r_y;
  real32_T c4_t;
  real32_T c4_y;
  real32_T c4_y_x;
  real32_T c4_z;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b_b;
  boolean_T c4_b_b1;
  boolean_T c4_b_overflow;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_e_b;
  boolean_T c4_e_varargin_1;
  boolean_T c4_exitg1;
  boolean_T c4_flat;
  boolean_T c4_guard1 = false;
  boolean_T c4_guard2 = false;
  boolean_T c4_guard3 = false;
  boolean_T c4_overflow;
  boolean_T c4_p_b;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_e_varargin_1 = c4_d_varargin_1[0];
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    chartInstance->c4_b_x[c4_i] = ((int32_T)c4_d_varargin_1[c4_i] == (int32_T)
      c4_e_varargin_1);
  }

  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    chartInstance->c4_x_data[c4_i1] = chartInstance->c4_b_x[c4_i1];
  }

  c4_flat = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 19200)) {
    c4_b_k = (real_T)c4_k + 1.0;
    if (!chartInstance->c4_x_data[(int32_T)c4_b_k - 1]) {
      c4_flat = false;
      c4_exitg1 = true;
    } else {
      c4_k++;
    }
  }

  if (c4_flat) {
    for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
      c4_b_accumMatrix[c4_i2].re = 0.0;
      c4_b_accumMatrix[c4_i2].im = 0.0;
    }

    for (c4_i4 = 0; c4_i4 < 19200; c4_i4++) {
      c4_b_gradientImg[c4_i4] = 0.0F;
    }
  } else {
    c4_st.site = &c4_oc_emlrtRSI;
    for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
      chartInstance->c4_s[c4_i3] = (real32_T)c4_d_varargin_1[c4_i3];
    }

    c4_b_st.site = &c4_ic_emlrtRSI;
    c4_e_imfilter(chartInstance, &c4_b_st, chartInstance->c4_s,
                  chartInstance->c4_A);
    c4_st.site = &c4_pc_emlrtRSI;
    c4_b_st.site = &c4_jc_emlrtRSI;
    for (c4_i5 = 0; c4_i5 < 19200; c4_i5++) {
      chartInstance->c4_b_A[c4_i5] = chartInstance->c4_A[c4_i5];
    }

    c4_f_imfilter(chartInstance, &c4_b_st, chartInstance->c4_b_A,
                  chartInstance->c4_Gx);
    c4_b_st.site = &c4_kc_emlrtRSI;
    c4_g_imfilter(chartInstance, &c4_b_st, chartInstance->c4_A,
                  chartInstance->c4_Gy);
    for (c4_i6 = 0; c4_i6 < 19200; c4_i6++) {
      chartInstance->c4_b_Gx[c4_i6] = chartInstance->c4_Gx[c4_i6];
    }

    for (c4_i7 = 0; c4_i7 < 19200; c4_i7++) {
      chartInstance->c4_b_Gy[c4_i7] = chartInstance->c4_Gy[c4_i7];
    }

    c4_hypot(chartInstance, chartInstance->c4_b_Gx, chartInstance->c4_b_Gy,
             c4_b_gradientImg);
    c4_st.site = &c4_qc_emlrtRSI;
    c4_b_st.site = &c4_uc_emlrtRSI;
    for (c4_i8 = 0; c4_i8 < 19200; c4_i8++) {
      chartInstance->c4_s[c4_i8] = c4_b_gradientImg[c4_i8];
    }

    c4_c_st.site = &c4_sb_emlrtRSI;
    c4_d_st.site = &c4_tb_emlrtRSI;
    c4_Gmax = c4_maximum(chartInstance, &c4_d_st, chartInstance->c4_s);
    c4_y = c4_Gmax;
    c4_b_y = c4_y;
    for (c4_i9 = 0; c4_i9 < 19200; c4_i9++) {
      chartInstance->c4_s[c4_i9] = c4_b_gradientImg[c4_i9] / c4_b_y;
    }

    c4_b_st.site = &c4_vc_emlrtRSI;
    c4_edgeThresh = c4_multithresh(chartInstance, &c4_b_st, chartInstance->c4_s);
    c4_t = c4_Gmax * c4_edgeThresh;
    c4_b_st.site = &c4_wc_emlrtRSI;
    for (c4_i10 = 0; c4_i10 < 19200; c4_i10++) {
      chartInstance->c4_b_x[c4_i10] = (c4_b_gradientImg[c4_i10] > c4_t);
    }

    c4_emxInit_real_T1(chartInstance, &c4_b_st, &c4_Ey, 1, &c4_bc_emlrtRTEI);
    c4_emxInit_int32_T(chartInstance, &c4_b_st, &c4_ii, 1, &c4_bc_emlrtRTEI);
    c4_emxInit_int32_T(chartInstance, &c4_b_st, &c4_jj, 1, &c4_bc_emlrtRTEI);
    c4_c_st.site = &c4_sf_emlrtRSI;
    c4_eml_find(chartInstance, &c4_c_st, chartInstance->c4_b_x, c4_ii, c4_jj);
    c4_i11 = c4_Ey->size[0];
    c4_Ey->size[0] = c4_ii->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_Ey, c4_i11,
      &c4_w_emlrtRTEI);
    c4_loop_ub = c4_ii->size[0] - 1;
    for (c4_i12 = 0; c4_i12 <= c4_loop_ub; c4_i12++) {
      c4_Ey->data[c4_i12] = (real_T)c4_ii->data[c4_i12];
    }

    c4_emxFree_int32_T(chartInstance, &c4_ii);
    c4_emxInit_real_T1(chartInstance, &c4_b_st, &c4_Ex, 1, &c4_bc_emlrtRTEI);
    c4_i13 = c4_Ex->size[0];
    c4_Ex->size[0] = c4_jj->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_Ex, c4_i13,
      &c4_x_emlrtRTEI);
    c4_b_loop_ub = c4_jj->size[0] - 1;
    for (c4_i14 = 0; c4_i14 <= c4_b_loop_ub; c4_i14++) {
      c4_Ex->data[c4_i14] = (real_T)c4_jj->data[c4_i14];
    }

    c4_emxFree_int32_T(chartInstance, &c4_jj);
    c4_emxInit_real_T1(chartInstance, &c4_b_st, &c4_ndx, 1, &c4_cc_emlrtRTEI);
    c4_st.site = &c4_rc_emlrtRSI;
    c4_i15 = c4_ndx->size[0];
    c4_ndx->size[0] = c4_Ey->size[0];
    c4_b_st.site = &c4_rc_emlrtRSI;
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_ndx, c4_i15,
      &c4_y_emlrtRTEI);
    c4_c_loop_ub = c4_Ey->size[0] - 1;
    for (c4_i16 = 0; c4_i16 <= c4_c_loop_ub; c4_i16++) {
      c4_ndx->data[c4_i16] = c4_Ey->data[c4_i16];
    }

    c4_emxInit_real_T1(chartInstance, &c4_st, &c4_b_varargin_2, 1,
                       &c4_ab_emlrtRTEI);
    c4_i17 = c4_b_varargin_2->size[0];
    c4_b_varargin_2->size[0] = c4_Ex->size[0];
    c4_b_st.site = &c4_rc_emlrtRSI;
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_b_varargin_2,
      c4_i17, &c4_ab_emlrtRTEI);
    c4_d_loop_ub = c4_Ex->size[0] - 1;
    for (c4_i18 = 0; c4_i18 <= c4_d_loop_ub; c4_i18++) {
      c4_b_varargin_2->data[c4_i18] = c4_Ex->data[c4_i18];
    }

    c4_emxInit_int32_T(chartInstance, &c4_st, &c4_r, 1, &c4_dc_emlrtRTEI);
    c4_b_st.site = &c4_xf_emlrtRSI;
    c4_eml_sub2ind(chartInstance, &c4_b_st, c4_ndx, c4_b_varargin_2, c4_r);
    c4_i19 = c4_ndx->size[0];
    c4_ndx->size[0] = c4_r->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_ndx, c4_i19,
      &c4_bb_emlrtRTEI);
    c4_e_loop_ub = c4_r->size[0] - 1;
    c4_emxFree_real_T(chartInstance, &c4_b_varargin_2);
    for (c4_i20 = 0; c4_i20 <= c4_e_loop_ub; c4_i20++) {
      c4_ndx->data[c4_i20] = (real_T)c4_r->data[c4_i20];
    }

    c4_emxFree_int32_T(chartInstance, &c4_r);
    c4_emxInit_real_T1(chartInstance, &c4_st, &c4_idxE, 1, &c4_cb_emlrtRTEI);
    c4_i21 = c4_idxE->size[0];
    c4_idxE->size[0] = c4_ndx->size[0];
    c4_st.site = &c4_rc_emlrtRSI;
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_idxE, c4_i21,
      &c4_cb_emlrtRTEI);
    c4_f_loop_ub = c4_ndx->size[0] - 1;
    for (c4_i22 = 0; c4_i22 <= c4_f_loop_ub; c4_i22++) {
      c4_idxE->data[c4_i22] = c4_ndx->data[c4_i22];
    }

    c4_emxFree_real_T(chartInstance, &c4_ndx);
    for (c4_i23 = 0; c4_i23 < 51; c4_i23++) {
      c4_ar = c4_Opca[c4_i23].re;
      c4_ai = c4_Opca[c4_i23].im;
      c4_br = c4_b_dv[c4_i23];
      c4_bi = 0.0;
      if (c4_bi == 0.0) {
        if (c4_ai == 0.0) {
          c4_w0[c4_i23].re = c4_ar / c4_br;
          c4_w0[c4_i23].im = 0.0;
        } else if (c4_ar == 0.0) {
          c4_w0[c4_i23].re = 0.0;
          c4_w0[c4_i23].im = c4_ai / c4_br;
        } else {
          c4_w0[c4_i23].re = c4_ar / c4_br;
          c4_w0[c4_i23].im = c4_ai / c4_br;
        }
      } else if (c4_br == 0.0) {
        if (c4_ar == 0.0) {
          c4_w0[c4_i23].re = c4_ai / c4_bi;
          c4_w0[c4_i23].im = 0.0;
        } else if (c4_ai == 0.0) {
          c4_w0[c4_i23].re = 0.0;
          c4_w0[c4_i23].im = -(c4_ar / c4_bi);
        } else {
          c4_w0[c4_i23].re = c4_ai / c4_bi;
          c4_w0[c4_i23].im = -(c4_ar / c4_bi);
        }
      } else {
        c4_brm = muDoubleScalarAbs(c4_br);
        c4_bim = muDoubleScalarAbs(c4_bi);
        if (c4_brm > c4_bim) {
          c4_b_s = c4_bi / c4_br;
          c4_d = c4_br + c4_b_s * c4_bi;
          c4_nr = c4_ar + c4_b_s * c4_ai;
          c4_ni = c4_ai - c4_b_s * c4_ar;
          c4_w0[c4_i23].re = c4_nr / c4_d;
          c4_w0[c4_i23].im = c4_ni / c4_d;
        } else if (c4_bim == c4_brm) {
          if (c4_br > 0.0) {
            c4_sgnbr = 0.5;
          } else {
            c4_sgnbr = -0.5;
          }

          if (c4_bi > 0.0) {
            c4_sgnbi = 0.5;
          } else {
            c4_sgnbi = -0.5;
          }

          c4_nr = c4_ar * c4_sgnbr + c4_ai * c4_sgnbi;
          c4_ni = c4_ai * c4_sgnbr - c4_ar * c4_sgnbi;
          c4_w0[c4_i23].re = c4_nr / c4_brm;
          c4_w0[c4_i23].im = c4_ni / c4_brm;
        } else {
          c4_b_s = c4_br / c4_bi;
          c4_d = c4_bi + c4_b_s * c4_br;
          c4_nr = c4_b_s * c4_ar + c4_ai;
          c4_ni = c4_b_s * c4_ai - c4_ar;
          c4_w0[c4_i23].re = c4_nr / c4_d;
          c4_w0[c4_i23].im = c4_ni / c4_d;
        }
      }
    }

    c4_lenE = (real_T)c4_Ex->size[0];
    for (c4_i24 = 0; c4_i24 < 19200; c4_i24++) {
      c4_b_accumMatrix[c4_i24].re = 0.0;
      c4_b_accumMatrix[c4_i24].im = 0.0;
    }

    c4_i25 = (int32_T)((c4_lenE + 19606.0) / 19607.0);
    emlrtForLoopVectorCheckR2012b(1.0, 19607.0, c4_lenE, mxDOUBLE_CLASS, c4_i25,
      &c4_wi_emlrtRTEI, c4_sp);
    c4_b_i = 0;
    c4_emxInit_real_T1(chartInstance, c4_sp, &c4_Ex_chunk, 1, &c4_qb_emlrtRTEI);
    c4_emxInit_real_T1(chartInstance, c4_sp, &c4_Ey_chunk, 1, &c4_rb_emlrtRTEI);
    c4_emxInit_real_T1(chartInstance, c4_sp, &c4_idxE_chunk, 1, &c4_sb_emlrtRTEI);
    c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_xc, 2, &c4_tb_emlrtRTEI);
    c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_yc, 2, &c4_ub_emlrtRTEI);
    c4_emxInit_creal_T1(chartInstance, c4_sp, &c4_w, 2, &c4_vb_emlrtRTEI);
    c4_emxInit_boolean_T(chartInstance, c4_sp, &c4_inside, 2, &c4_wb_emlrtRTEI);
    c4_emxInit_int32_T(chartInstance, c4_sp, &c4_xckeep, 1, &c4_xb_emlrtRTEI);
    c4_emxInit_int32_T(chartInstance, c4_sp, &c4_yckeep, 1, &c4_yb_emlrtRTEI);
    c4_emxInit_creal_T(chartInstance, c4_sp, &c4_wkeep, 1, &c4_ac_emlrtRTEI);
    c4_emxInit_real_T(chartInstance, c4_sp, &c4_r1, 2, &c4_bc_emlrtRTEI);
    while (c4_b_i <= c4_i25 - 1) {
      c4_c_i = (real_T)c4_b_i * 19607.0 + 1.0;
      c4_f_varargin_1 = (c4_c_i + 19607.0) - 1.0;
      c4_c_varargin_2 = c4_lenE;
      c4_c_x = c4_f_varargin_1;
      c4_c_y = c4_c_varargin_2;
      c4_d_x = c4_c_x;
      c4_d_y = c4_c_y;
      c4_e_x = c4_d_x;
      c4_e_y = c4_d_y;
      c4_f_x = c4_e_x;
      c4_f_y = c4_e_y;
      c4_g_x = c4_f_x;
      c4_g_y = c4_f_y;
      c4_h_x = c4_g_x;
      c4_h_y = c4_g_y;
      c4_minval = muDoubleScalarMin(c4_h_x, c4_h_y);
      c4_st.site = &c4_sc_emlrtRSI;
      c4_g_a = c4_c_i;
      c4_b_d = c4_minval;
      c4_b_st.site = &c4_yf_emlrtRSI;
      c4_h_a = c4_g_a;
      c4_b = c4_b_d;
      c4_i_x = c4_h_a;
      c4_b_b = muDoubleScalarIsNaN(c4_i_x);
      c4_guard1 = false;
      c4_guard2 = false;
      c4_guard3 = false;
      if (c4_b_b) {
        c4_guard2 = true;
      } else {
        c4_j_x = c4_b;
        c4_c_b = muDoubleScalarIsNaN(c4_j_x);
        if (c4_c_b) {
          c4_guard2 = true;
        } else if (c4_b < c4_h_a) {
          c4_r1->size[0] = 1;
          c4_r1->size[1] = 0;
        } else {
          c4_k_x = c4_h_a;
          c4_d_b = muDoubleScalarIsInf(c4_k_x);
          if (c4_d_b) {
            c4_guard3 = true;
          } else {
            c4_l_x = c4_b;
            c4_e_b = muDoubleScalarIsInf(c4_l_x);
            if (c4_e_b) {
              c4_guard3 = true;
            } else {
              c4_guard1 = true;
            }
          }
        }
      }

      if (c4_guard3) {
        if (c4_h_a == c4_b) {
          c4_i26 = c4_r1->size[0] * c4_r1->size[1];
          c4_r1->size[0] = 1;
          c4_r1->size[1] = 1;
          c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_r1, c4_i26,
            &c4_db_emlrtRTEI);
          c4_r1->data[0] = rtNaN;
        } else {
          c4_guard1 = true;
        }
      }

      if (c4_guard2) {
        c4_i27 = c4_r1->size[0] * c4_r1->size[1];
        c4_r1->size[0] = 1;
        c4_r1->size[1] = 1;
        c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_r1, c4_i27,
          &c4_db_emlrtRTEI);
        c4_r1->data[0] = rtNaN;
      }

      if (c4_guard1) {
        c4_m_x = c4_h_a;
        c4_n_x = c4_m_x;
        c4_n_x = muDoubleScalarFloor(c4_n_x);
        if (c4_n_x == c4_h_a) {
          c4_i29 = c4_r1->size[0] * c4_r1->size[1];
          c4_r1->size[0] = 1;
          c4_r1->size[1] = (int32_T)muDoubleScalarFloor(c4_b - c4_h_a) + 1;
          c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_r1, c4_i29,
            &c4_db_emlrtRTEI);
          c4_g_loop_ub = (int32_T)muDoubleScalarFloor(c4_b - c4_h_a);
          for (c4_i31 = 0; c4_i31 <= c4_g_loop_ub; c4_i31++) {
            c4_r1->data[c4_i31] = c4_h_a + (real_T)c4_i31;
          }
        } else {
          c4_c_st.site = &c4_ag_emlrtRSI;
          c4_i_a = c4_h_a;
          c4_f_b = c4_b;
          c4_j_a = c4_i_a;
          c4_g_b = c4_f_b;
          c4_a1 = c4_j_a;
          c4_o_x = (c4_g_b - c4_j_a) + 0.5;
          c4_ndbl = c4_o_x;
          c4_ndbl = muDoubleScalarFloor(c4_ndbl);
          c4_apnd = c4_j_a + c4_ndbl;
          c4_cdiff = c4_apnd - c4_g_b;
          c4_k_a = c4_j_a;
          c4_h_b = c4_g_b;
          c4_p_x = c4_k_a;
          c4_q_x = c4_p_x;
          c4_r_x = c4_q_x;
          c4_absa = muDoubleScalarAbs(c4_r_x);
          c4_s_x = c4_h_b;
          c4_t_x = c4_s_x;
          c4_u_x = c4_t_x;
          c4_absb = muDoubleScalarAbs(c4_u_x);
          if (c4_absa > c4_absb) {
            c4_c = c4_absa;
          } else {
            c4_c = c4_absb;
          }

          c4_thresh = 4.4408920985006262E-16 * c4_c;
          c4_v_x = c4_cdiff;
          c4_w_x = c4_v_x;
          c4_x_x = c4_w_x;
          c4_i_y = muDoubleScalarAbs(c4_x_x);
          if (c4_i_y < c4_thresh) {
            c4_ndbl++;
            c4_b1 = c4_g_b;
          } else if (c4_cdiff > 0.0) {
            c4_b1 = c4_j_a + (c4_ndbl - 1.0);
          } else {
            c4_ndbl++;
            c4_b1 = c4_apnd;
          }

          if (c4_ndbl >= 0.0) {
            c4_n = (int32_T)muDoubleScalarFloor(c4_ndbl);
          } else {
            c4_n = 0;
          }

          c4_i47 = c4_r1->size[0] * c4_r1->size[1];
          c4_r1->size[0] = 1;
          c4_r1->size[1] = c4_n;
          c4_emxEnsureCapacity_real_T(chartInstance, &c4_c_st, c4_r1, c4_i47,
            &c4_pb_emlrtRTEI);
          if (c4_n > 0) {
            c4_r1->data[0] = c4_a1;
            if (c4_n > 1) {
              c4_r1->data[c4_n - 1] = c4_b1;
              c4_nm1 = c4_n - 1;
              c4_l_a = c4_nm1;
              c4_nm1d2 = c4_div_nzp_s32(chartInstance, c4_l_a, 2, 0, 1U, 0, 0);
              c4_i52 = c4_nm1d2 - 2;
              c4_d_st.site = &c4_bg_emlrtRSI;
              c4_i_b = c4_i52 + 1;
              c4_j_b = c4_i_b;
              if (1 > c4_j_b) {
                c4_overflow = false;
              } else {
                c4_overflow = (c4_j_b > 2147483646);
              }

              if (c4_overflow) {
                c4_e_st.site = &c4_mb_emlrtRSI;
                c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
              }

              for (c4_c_k = 1; c4_c_k - 1 <= c4_i52; c4_c_k++) {
                c4_d_k = c4_c_k;
                c4_kd = (real_T)c4_d_k;
                c4_r1->data[c4_d_k] = c4_a1 + c4_kd;
                c4_r1->data[(c4_n - c4_d_k) - 1] = c4_b1 - c4_kd;
              }

              c4_l_b = c4_nm1d2;
              c4_m_y = c4_l_b << 1;
              if (c4_m_y == c4_nm1) {
                c4_r1->data[c4_nm1d2] = (c4_a1 + c4_b1) / 2.0;
              } else {
                c4_kd = (real_T)c4_nm1d2;
                c4_r1->data[c4_nm1d2] = c4_a1 + c4_kd;
                c4_r1->data[c4_nm1d2 + 1] = c4_b1 - c4_kd;
              }
            }
          }
        }
      }

      c4_sizeChunk = (real_T)c4_r1->size[1];
      c4_i28 = c4_Ex_chunk->size[0];
      c4_Ex_chunk->size[0] = (int32_T)c4_sizeChunk;
      c4_st.site = &c4_pl_emlrtRSI;
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_Ex_chunk, c4_i28,
        &c4_eb_emlrtRTEI);
      c4_i30 = c4_Ey_chunk->size[0];
      c4_Ey_chunk->size[0] = (int32_T)c4_sizeChunk;
      c4_st.site = &c4_ol_emlrtRSI;
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_Ey_chunk, c4_i30,
        &c4_fb_emlrtRTEI);
      c4_i32 = c4_idxE_chunk->size[0];
      c4_idxE_chunk->size[0] = (int32_T)c4_sizeChunk;
      c4_st.site = &c4_nl_emlrtRSI;
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_idxE_chunk, c4_i32,
        &c4_gb_emlrtRTEI);
      c4_idxEdge = (int32_T)c4_c_i;
      c4_i33 = (int32_T)c4_sizeChunk - 1;
      for (c4_b_idx = 0; c4_b_idx <= c4_i33; c4_b_idx++) {
        c4_c_idx = (real_T)c4_b_idx + 1.0;
        c4_i35 = c4_Ex->size[0];
        c4_i36 = c4_Ex_chunk->size[0];
        c4_i37 = (int32_T)c4_c_idx;
        c4_Ex_chunk->data[emlrtDynamicBoundsCheckR2012b(c4_i37, 1, c4_i36,
          &c4_s_emlrtBCI, c4_sp) - 1] = c4_Ex->
          data[emlrtDynamicBoundsCheckR2012b(c4_idxEdge, 1, c4_i35,
          &c4_r_emlrtBCI, c4_sp) - 1];
        c4_i38 = c4_Ey->size[0];
        c4_i40 = c4_Ey_chunk->size[0];
        c4_i41 = (int32_T)c4_c_idx;
        c4_Ey_chunk->data[emlrtDynamicBoundsCheckR2012b(c4_i41, 1, c4_i40,
          &c4_u_emlrtBCI, c4_sp) - 1] = c4_Ey->
          data[emlrtDynamicBoundsCheckR2012b(c4_idxEdge, 1, c4_i38,
          &c4_t_emlrtBCI, c4_sp) - 1];
        c4_i42 = c4_idxE->size[0];
        c4_i43 = c4_idxE_chunk->size[0];
        c4_i45 = (int32_T)c4_c_idx;
        c4_idxE_chunk->data[emlrtDynamicBoundsCheckR2012b(c4_i45, 1, c4_i43,
          &c4_w_emlrtBCI, c4_sp) - 1] = c4_idxE->
          data[emlrtDynamicBoundsCheckR2012b(c4_idxEdge, 1, c4_i42,
          &c4_v_emlrtBCI, c4_sp) - 1];
        c4_idxEdge++;
      }

      c4_dim1 = (real_T)c4_idxE_chunk->size[0];
      c4_i34 = c4_xc->size[0] * c4_xc->size[1];
      c4_xc->size[0] = (int32_T)c4_dim1;
      c4_xc->size[1] = 51;
      c4_st.site = &c4_rl_emlrtRSI;
      c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_xc, c4_i34,
        &c4_hb_emlrtRTEI);
      c4_i39 = c4_yc->size[0] * c4_yc->size[1];
      c4_yc->size[0] = (int32_T)c4_dim1;
      c4_yc->size[1] = 51;
      c4_st.site = &c4_ql_emlrtRSI;
      c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_yc, c4_i39,
        &c4_ib_emlrtRTEI);
      c4_i44 = c4_w->size[0] * c4_w->size[1];
      c4_w->size[0] = (int32_T)c4_dim1;
      c4_w->size[1] = 51;
      c4_st.site = &c4_sl_emlrtRSI;
      c4_emxEnsureCapacity_creal_T1(chartInstance, &c4_st, c4_w, c4_i44,
        &c4_jb_emlrtRTEI);
      c4_i46 = c4_inside->size[0] * c4_inside->size[1];
      c4_inside->size[0] = (int32_T)c4_dim1;
      c4_inside->size[1] = 51;
      c4_st.site = &c4_cl_emlrtRSI;
      c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_st, c4_inside, c4_i46,
        &c4_kb_emlrtRTEI);
      c4_rows_to_keep_size[0] = (int32_T)c4_dim1;
      c4_h_loop_ub = (int32_T)c4_dim1 - 1;
      for (c4_i48 = 0; c4_i48 <= c4_h_loop_ub; c4_i48++) {
        chartInstance->c4_rows_to_keep_data[c4_i48] = false;
      }

      for (c4_idx2 = 0; c4_idx2 < 51; c4_idx2++) {
        c4_b_idx2 = (real_T)c4_idx2 + 1.0;
        c4_i50 = (int32_T)c4_dim1 - 1;
        for (c4_idx1 = 0; c4_idx1 <= c4_i50; c4_idx1++) {
          c4_b_idx1 = (real_T)c4_idx1 + 1.0;
          c4_i53 = c4_idxE_chunk->size[0];
          c4_i54 = (int32_T)c4_b_idx1;
          c4_y_x = chartInstance->c4_Gx[(int32_T)c4_idxE_chunk->
            data[emlrtDynamicBoundsCheckR2012b(c4_i54, 1, c4_i53, &c4_x_emlrtBCI,
            c4_sp) - 1] - 1];
          c4_i56 = c4_idxE_chunk->size[0];
          c4_i57 = (int32_T)c4_b_idx1;
          c4_j_y = c4_b_gradientImg[(int32_T)c4_idxE_chunk->
            data[emlrtDynamicBoundsCheckR2012b(c4_i57, 1, c4_i56, &c4_y_emlrtBCI,
            c4_sp) - 1] - 1];
          c4_ab_x = c4_y_x;
          c4_k_y = c4_j_y;
          c4_z = c4_ab_x / c4_k_y;
          c4_m_a = -(15.0 + 0.5 * (real_T)((int32_T)c4_b_idx2 - 1));
          c4_k_b = c4_z;
          c4_l_y = (real32_T)c4_m_a * c4_k_b;
          c4_i60 = c4_Ex_chunk->size[0];
          c4_i61 = (int32_T)c4_b_idx1;
          c4_bb_x = (real32_T)c4_Ex_chunk->data[emlrtDynamicBoundsCheckR2012b
            (c4_i61, 1, c4_i60, &c4_ab_emlrtBCI, c4_sp) - 1] + c4_l_y;
          if (c4_bb_x > 0.0F) {
            c4_n_y = c4_bb_x + 0.5F;
          } else if (c4_bb_x < 0.0F) {
            c4_n_y = c4_bb_x - 0.5F;
          } else {
            c4_n_y = 0.0F;
          }

          c4_i65 = c4_xc->size[0];
          c4_i66 = (int32_T)c4_b_idx1;
          c4_xc->data[(emlrtDynamicBoundsCheckR2012b(c4_i66, 1, c4_i65,
            &c4_db_emlrtBCI, c4_sp) + c4_xc->size[0] * ((int32_T)c4_b_idx2 - 1))
            - 1] = c4_n_y;
          c4_i68 = c4_idxE_chunk->size[0];
          c4_i70 = (int32_T)c4_b_idx1;
          c4_cb_x = chartInstance->c4_Gy[(int32_T)c4_idxE_chunk->
            data[emlrtDynamicBoundsCheckR2012b(c4_i70, 1, c4_i68,
            &c4_gb_emlrtBCI, c4_sp) - 1] - 1];
          c4_i73 = c4_idxE_chunk->size[0];
          c4_i76 = (int32_T)c4_b_idx1;
          c4_o_y = c4_b_gradientImg[(int32_T)c4_idxE_chunk->
            data[emlrtDynamicBoundsCheckR2012b(c4_i76, 1, c4_i73,
            &c4_hb_emlrtBCI, c4_sp) - 1] - 1];
          c4_db_x = c4_cb_x;
          c4_p_y = c4_o_y;
          c4_b_z = c4_db_x / c4_p_y;
          c4_n_a = -(15.0 + 0.5 * (real_T)((int32_T)c4_b_idx2 - 1));
          c4_o_b = c4_b_z;
          c4_q_y = (real32_T)c4_n_a * c4_o_b;
          c4_i91 = c4_Ey_chunk->size[0];
          c4_i93 = (int32_T)c4_b_idx1;
          c4_eb_x = (real32_T)c4_Ey_chunk->data[emlrtDynamicBoundsCheckR2012b
            (c4_i93, 1, c4_i91, &c4_tb_emlrtBCI, c4_sp) - 1] + c4_q_y;
          if (c4_eb_x > 0.0F) {
            c4_r_y = c4_eb_x + 0.5F;
          } else if (c4_eb_x < 0.0F) {
            c4_r_y = c4_eb_x - 0.5F;
          } else {
            c4_r_y = 0.0F;
          }

          c4_i100 = c4_yc->size[0];
          c4_i102 = (int32_T)c4_b_idx1;
          c4_yc->data[(emlrtDynamicBoundsCheckR2012b(c4_i102, 1, c4_i100,
            &c4_ub_emlrtBCI, c4_sp) + c4_yc->size[0] * ((int32_T)c4_b_idx2 - 1))
            - 1] = c4_r_y;
          c4_i105 = c4_w->size[0];
          c4_i107 = (int32_T)c4_b_idx1;
          c4_w->data[(emlrtDynamicBoundsCheckR2012b(c4_i107, 1, c4_i105,
            &c4_vb_emlrtBCI, c4_sp) + c4_w->size[0] * ((int32_T)c4_b_idx2 - 1))
            - 1].re = c4_w0[(int32_T)c4_b_idx2 - 1].re;
          c4_i108 = c4_w->size[0];
          c4_i109 = (int32_T)c4_b_idx1;
          c4_w->data[(emlrtDynamicBoundsCheckR2012b(c4_i109, 1, c4_i108,
            &c4_vb_emlrtBCI, c4_sp) + c4_w->size[0] * ((int32_T)c4_b_idx2 - 1))
            - 1].im = c4_w0[(int32_T)c4_b_idx2 - 1].im;
          c4_i110 = c4_xc->size[0];
          c4_i111 = (int32_T)c4_b_idx1;
          c4_p_b = (c4_xc->data[(emlrtDynamicBoundsCheckR2012b(c4_i111, 1,
                      c4_i110, &c4_wb_emlrtBCI, c4_sp) + c4_xc->size[0] *
                     ((int32_T)c4_b_idx2 - 1)) - 1] >= 1.0F);
          c4_i112 = c4_xc->size[0];
          c4_i113 = (int32_T)c4_b_idx1;
          c4_b_b1 = (c4_xc->data[(emlrtDynamicBoundsCheckR2012b(c4_i113, 1,
            c4_i112, &c4_xb_emlrtBCI, c4_sp) + c4_xc->size[0] * ((int32_T)
            c4_b_idx2 - 1)) - 1] <= 160.0F);
          c4_b2 = (c4_p_b && c4_b_b1);
          c4_i114 = c4_yc->size[0];
          c4_i115 = (int32_T)c4_b_idx1;
          c4_b3 = (c4_yc->data[(emlrtDynamicBoundsCheckR2012b(c4_i115, 1,
                     c4_i114, &c4_yb_emlrtBCI, c4_sp) + c4_yc->size[0] *
                                ((int32_T)c4_b_idx2 - 1)) - 1] >= 1.0F);
          c4_b4 = (c4_b2 && c4_b3);
          c4_i116 = c4_yc->size[0];
          c4_i117 = (int32_T)c4_b_idx1;
          c4_b5 = (c4_yc->data[(emlrtDynamicBoundsCheckR2012b(c4_i117, 1,
                     c4_i116, &c4_ac_emlrtBCI, c4_sp) + c4_yc->size[0] *
                                ((int32_T)c4_b_idx2 - 1)) - 1] < 120.0F);
          c4_i118 = c4_inside->size[0];
          c4_i119 = (int32_T)c4_b_idx1;
          c4_inside->data[(emlrtDynamicBoundsCheckR2012b(c4_i119, 1, c4_i118,
            &c4_bc_emlrtBCI, c4_sp) + c4_inside->size[0] * ((int32_T)c4_b_idx2 -
            1)) - 1] = (c4_b4 && c4_b5);
          c4_i120 = c4_inside->size[0];
          c4_i121 = (int32_T)c4_b_idx1;
          if (c4_inside->data[(emlrtDynamicBoundsCheckR2012b(c4_i121, 1, c4_i120,
                &c4_cc_emlrtBCI, c4_sp) + c4_inside->size[0] * ((int32_T)
                c4_b_idx2 - 1)) - 1]) {
            c4_i122 = (int32_T)c4_b_idx1;
            chartInstance->c4_rows_to_keep_data[emlrtDynamicBoundsCheckR2012b
              (c4_i122, 1, c4_rows_to_keep_size[0], &c4_dc_emlrtBCI, c4_sp) - 1]
              = true;
          }
        }
      }

      c4_i49 = c4_xckeep->size[0];
      c4_xckeep->size[0] = c4_xc->size[0] * 51;
      c4_st.site = &c4_kl_emlrtRSI;
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_xckeep, c4_i49,
        &c4_mb_emlrtRTEI);
      c4_i51 = c4_yckeep->size[0];
      c4_yckeep->size[0] = c4_yc->size[0] * 51;
      c4_st.site = &c4_jl_emlrtRSI;
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_yckeep, c4_i51,
        &c4_nb_emlrtRTEI);
      c4_i55 = c4_wkeep->size[0];
      c4_wkeep->size[0] = c4_w->size[0] * 51;
      c4_st.site = &c4_uk_emlrtRSI;
      c4_emxEnsureCapacity_creal_T(chartInstance, &c4_st, c4_wkeep, c4_i55,
        &c4_ob_emlrtRTEI);
      c4_idxkeep = 0;
      for (c4_c_idx2 = 0; c4_c_idx2 < 51; c4_c_idx2++) {
        c4_b_idx2 = (real_T)c4_c_idx2 + 1.0;
        c4_i58 = (int32_T)c4_dim1 - 1;
        for (c4_c_idx1 = 0; c4_c_idx1 <= c4_i58; c4_c_idx1++) {
          c4_b_idx1 = (real_T)c4_c_idx1 + 1.0;
          c4_i62 = (int32_T)c4_b_idx1;
          if (chartInstance->c4_rows_to_keep_data[emlrtDynamicBoundsCheckR2012b
              (c4_i62, 1, c4_rows_to_keep_size[0], &c4_bb_emlrtBCI, c4_sp) - 1])
          {
            c4_i63 = c4_inside->size[0];
            c4_i64 = (int32_T)c4_b_idx1;
            if (c4_inside->data[(emlrtDynamicBoundsCheckR2012b(c4_i64, 1, c4_i63,
                  &c4_cb_emlrtBCI, c4_sp) + c4_inside->size[0] * ((int32_T)
                  c4_b_idx2 - 1)) - 1]) {
              c4_idxkeep++;
              c4_i67 = c4_xc->size[0];
              c4_i69 = (int32_T)c4_b_idx1;
              c4_i71 = c4_xckeep->size[0];
              c4_xckeep->data[emlrtDynamicBoundsCheckR2012b(c4_idxkeep, 1,
                c4_i71, &c4_fb_emlrtBCI, c4_sp) - 1] = (int32_T)c4_xc->data
                [(emlrtDynamicBoundsCheckR2012b(c4_i69, 1, c4_i67,
                   &c4_eb_emlrtBCI, c4_sp) + c4_xc->size[0] * ((int32_T)
                   c4_b_idx2 - 1)) - 1];
              c4_i75 = c4_yc->size[0];
              c4_i78 = (int32_T)c4_b_idx1;
              c4_i80 = c4_yckeep->size[0];
              c4_yckeep->data[emlrtDynamicBoundsCheckR2012b(c4_idxkeep, 1,
                c4_i80, &c4_jb_emlrtBCI, c4_sp) - 1] = (int32_T)c4_yc->data
                [(emlrtDynamicBoundsCheckR2012b(c4_i78, 1, c4_i75,
                   &c4_ib_emlrtBCI, c4_sp) + c4_yc->size[0] * ((int32_T)
                   c4_b_idx2 - 1)) - 1];
              c4_i83 = c4_wkeep->size[0];
              c4_i85 = c4_w->size[0];
              c4_i87 = (int32_T)c4_b_idx1;
              c4_wkeep->data[emlrtDynamicBoundsCheckR2012b(c4_idxkeep, 1, c4_i83,
                &c4_lb_emlrtBCI, c4_sp) - 1].re = c4_w->data
                [(emlrtDynamicBoundsCheckR2012b(c4_i87, 1, c4_i85,
                   &c4_kb_emlrtBCI, c4_sp) + c4_w->size[0] * ((int32_T)c4_b_idx2
                   - 1)) - 1].re;
              c4_i90 = c4_w->size[0];
              c4_i92 = (int32_T)c4_b_idx1;
              c4_i95 = c4_wkeep->size[0];
              c4_wkeep->data[emlrtDynamicBoundsCheckR2012b(c4_idxkeep, 1, c4_i95,
                &c4_lb_emlrtBCI, c4_sp) - 1].im = c4_w->data
                [(emlrtDynamicBoundsCheckR2012b(c4_i92, 1, c4_i90,
                   &c4_kb_emlrtBCI, c4_sp) + c4_w->size[0] * ((int32_T)c4_b_idx2
                   - 1)) - 1].im;
            }
          }
        }
      }

      c4_st.site = &c4_tc_emlrtRSI;
      c4_szxc = c4_idxkeep;
      for (c4_i59 = 0; c4_i59 < 19200; c4_i59++) {
        chartInstance->c4_out[c4_i59].re = 0.0;
        chartInstance->c4_out[c4_i59].im = 0.0;
      }

      c4_b_st.site = &c4_cg_emlrtRSI;
      c4_m_b = c4_szxc;
      c4_n_b = c4_m_b;
      if (1 > c4_n_b) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_n_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_c_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_d_idx = 1; c4_d_idx - 1 < c4_szxc; c4_d_idx++) {
        c4_e_idx = c4_d_idx;
        c4_i74 = c4_yckeep->size[0];
        c4_i77 = c4_yckeep->data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1,
          c4_i74, &c4_rb_emlrtBCI, &c4_st) - 1];
        c4_i79 = c4_xckeep->size[0];
        c4_i81 = c4_xckeep->data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1,
          c4_i79, &c4_rb_emlrtBCI, &c4_st) - 1];
        c4_i82 = c4_yckeep->size[0];
        c4_i84 = c4_yckeep->data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1,
          c4_i82, &c4_nb_emlrtBCI, &c4_st) - 1];
        c4_i86 = c4_xckeep->size[0];
        c4_i88 = c4_xckeep->data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1,
          c4_i86, &c4_nb_emlrtBCI, &c4_st) - 1];
        c4_i89 = c4_wkeep->size[0];
        chartInstance->c4_out[(emlrtDynamicBoundsCheckR2012b(c4_i77, 1, 120,
          &c4_qb_emlrtBCI, &c4_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c4_i81,
          1, 160, &c4_sb_emlrtBCI, &c4_st) - 1)) - 1].re = chartInstance->
          c4_out[(emlrtDynamicBoundsCheckR2012b(c4_i84, 1, 120, &c4_mb_emlrtBCI,
                   &c4_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c4_i88, 1, 160,
                    &c4_ob_emlrtBCI, &c4_st) - 1)) - 1].re + c4_wkeep->
          data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i89,
          &c4_pb_emlrtBCI, &c4_st) - 1].re;
        c4_i94 = c4_yckeep->size[0];
        c4_i96 = c4_yckeep->data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1,
          c4_i94, &c4_nb_emlrtBCI, &c4_st) - 1];
        c4_i97 = c4_xckeep->size[0];
        c4_i98 = c4_xckeep->data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1,
          c4_i97, &c4_nb_emlrtBCI, &c4_st) - 1];
        c4_i99 = c4_wkeep->size[0];
        c4_i101 = c4_yckeep->size[0];
        c4_i103 = c4_yckeep->data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1,
          c4_i101, &c4_rb_emlrtBCI, &c4_st) - 1];
        c4_i104 = c4_xckeep->size[0];
        c4_i106 = c4_xckeep->data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1,
          c4_i104, &c4_rb_emlrtBCI, &c4_st) - 1];
        chartInstance->c4_out[(emlrtDynamicBoundsCheckR2012b(c4_i103, 1, 120,
          &c4_qb_emlrtBCI, &c4_st) + 120 * (emlrtDynamicBoundsCheckR2012b
          (c4_i106, 1, 160, &c4_sb_emlrtBCI, &c4_st) - 1)) - 1].im =
          chartInstance->c4_out[(emlrtDynamicBoundsCheckR2012b(c4_i96, 1, 120,
          &c4_mb_emlrtBCI, &c4_st) + 120 * (emlrtDynamicBoundsCheckR2012b(c4_i98,
          1, 160, &c4_ob_emlrtBCI, &c4_st) - 1)) - 1].im + c4_wkeep->
          data[emlrtDynamicBoundsCheckR2012b(c4_e_idx, 1, c4_i99,
          &c4_pb_emlrtBCI, &c4_st) - 1].im;
      }

      for (c4_i72 = 0; c4_i72 < 19200; c4_i72++) {
        c4_b_accumMatrix[c4_i72].re += chartInstance->c4_out[c4_i72].re;
        c4_b_accumMatrix[c4_i72].im += chartInstance->c4_out[c4_i72].im;
      }

      c4_b_i++;
    }

    c4_emxFree_real_T(chartInstance, &c4_Ex);
    c4_emxFree_real_T(chartInstance, &c4_Ey);
    c4_emxFree_real_T(chartInstance, &c4_r1);
    c4_emxFree_creal_T(chartInstance, &c4_wkeep);
    c4_emxFree_int32_T(chartInstance, &c4_yckeep);
    c4_emxFree_int32_T(chartInstance, &c4_xckeep);
    c4_emxFree_boolean_T(chartInstance, &c4_inside);
    c4_emxFree_creal_T(chartInstance, &c4_w);
    c4_emxFree_real32_T(chartInstance, &c4_yc);
    c4_emxFree_real32_T(chartInstance, &c4_xc);
    c4_emxFree_real_T(chartInstance, &c4_idxE_chunk);
    c4_emxFree_real_T(chartInstance, &c4_Ey_chunk);
    c4_emxFree_real_T(chartInstance, &c4_Ex_chunk);
    c4_emxFree_real_T(chartInstance, &c4_idxE);
  }
}

static real32_T c4_multithresh(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real32_T c4_d_varargin_1[19200])
{
  c4_emxArray_int32_T *c4_r;
  c4_emxArray_real32_T *c4_b_threshout;
  c4_emxArray_real32_T *c4_img;
  c4_emxArray_real32_T *c4_threshL;
  c4_emxArray_real32_T *c4_uniqueVals;
  c4_emxArray_real_T *c4_b_uniqueVals_d;
  c4_emxArray_real_T *c4_d_uniqueVals_d;
  c4_emxArray_real_T *c4_r1;
  c4_emxArray_real_T *c4_threshRaw;
  c4_emxArray_real_T *c4_uniqueVals_d;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  real_T c4_b_counts[256];
  real_T c4_c_counts[256];
  real_T c4_counts[256];
  real_T c4_d_counts[256];
  real_T c4_mu[256];
  real_T c4_omega[256];
  real_T c4_b_ind;
  real_T c4_b_lenThreshOrig;
  real_T c4_b_mu_t;
  real_T c4_b_numElems;
  real_T c4_b_q;
  real_T c4_b_thNeeded1;
  real_T c4_b_thNeeded2;
  real_T c4_b_threshCandidate_d;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_h_a;
  real_T c4_idxNum;
  real_T c4_idxSum;
  real_T c4_lenThreshOrig;
  real_T c4_m_x;
  real_T c4_maxval;
  real_T c4_mu_t;
  real_T c4_n_b;
  real_T c4_n_x;
  real_T c4_numElems;
  real_T c4_o_b;
  real_T c4_o_x;
  real_T c4_q;
  real_T c4_thNeeded1;
  real_T c4_thNeeded2;
  real_T c4_threshCandidate_d;
  int32_T c4_b_tmp_size[2];
  int32_T c4_c_tmp_size[2];
  int32_T c4_d_tmp_size[2];
  int32_T c4_tmp_size[2];
  int32_T c4_y_size[2];
  int32_T c4_Auint8_size[1];
  int32_T c4_c_uniqueVals_d[1];
  int32_T c4_e_tmp_size[1];
  int32_T c4_e_uniqueVals_d[1];
  int32_T c4_f_tmp_size[1];
  int32_T c4_g_tmp_size[1];
  int32_T c4_h_tmp_size[1];
  int32_T c4_ab_loop_ub;
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_trueCount;
  int32_T c4_bb_loop_ub;
  int32_T c4_c_i;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_cb_loop_ub;
  int32_T c4_d_i;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_db_loop_ub;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_eb_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_fb_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_gb_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_hb_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i100;
  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i108;
  int32_T c4_i109;
  int32_T c4_i11;
  int32_T c4_i110;
  int32_T c4_i111;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i9;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  int32_T c4_i99;
  int32_T c4_i_loop_ub;
  int32_T c4_ib_loop_ub;
  int32_T c4_ind;
  int32_T c4_j_loop_ub;
  int32_T c4_jb_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_kb_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_partialTrueCount;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  int32_T c4_s_loop_ub;
  int32_T c4_t_loop_ub;
  int32_T c4_trueCount;
  int32_T c4_u_loop_ub;
  int32_T c4_v_loop_ub;
  int32_T c4_w_loop_ub;
  int32_T c4_x_loop_ub;
  int32_T c4_y_loop_ub;
  real32_T c4_y_data[1];
  real32_T c4_ab_x;
  real32_T c4_b_d;
  real32_T c4_b_maxA;
  real32_T c4_b_minA;
  real32_T c4_b_minval;
  real32_T c4_b_threshCandidate;
  real32_T c4_b_varargin_2;
  real32_T c4_b_y;
  real32_T c4_bb_x;
  real32_T c4_c_d;
  real32_T c4_c_maxA;
  real32_T c4_c_minA;
  real32_T c4_c_varargin_2;
  real32_T c4_c_x;
  real32_T c4_c_y;
  real32_T c4_cb_x;
  real32_T c4_d_minA;
  real32_T c4_d_x;
  real32_T c4_d_y;
  real32_T c4_db_x;
  real32_T c4_e_varargin_1;
  real32_T c4_e_x;
  real32_T c4_e_y;
  real32_T c4_eb_x;
  real32_T c4_f_varargin_1;
  real32_T c4_f_x;
  real32_T c4_f_y;
  real32_T c4_fb_x;
  real32_T c4_g_a;
  real32_T c4_g_x;
  real32_T c4_g_y;
  real32_T c4_gb_x;
  real32_T c4_h_x;
  real32_T c4_h_y;
  real32_T c4_hb_x;
  real32_T c4_i_x;
  real32_T c4_i_y;
  real32_T c4_ib_x;
  real32_T c4_j_x;
  real32_T c4_j_y;
  real32_T c4_jb_x;
  real32_T c4_k_x;
  real32_T c4_k_y;
  real32_T c4_l_x;
  real32_T c4_l_y;
  real32_T c4_m_y;
  real32_T c4_maxA;
  real32_T c4_minA;
  real32_T c4_minval;
  real32_T c4_n_y;
  real32_T c4_p_b;
  real32_T c4_p_x;
  real32_T c4_q_x;
  real32_T c4_r_b;
  real32_T c4_r_x;
  real32_T c4_s_x;
  real32_T c4_t_x;
  real32_T c4_thresh;
  real32_T c4_threshCandidate;
  real32_T c4_threshout;
  real32_T c4_u_x;
  real32_T c4_v_x;
  real32_T c4_w_x;
  real32_T c4_x_x;
  real32_T c4_y;
  real32_T c4_y_x;
  uint8_T c4_Auint8_data[19200];
  boolean_T c4_b_tmp_data[19200];
  boolean_T c4_c_tmp_data[19200];
  boolean_T c4_d_tmp_data[19200];
  boolean_T c4_e_tmp_data[19200];
  boolean_T c4_f_tmp_data[19200];
  boolean_T c4_nans[19200];
  boolean_T c4_tmp_data[19200];
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b8;
  boolean_T c4_b9;
  boolean_T c4_b_b;
  boolean_T c4_b_isDegenerate;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_e_b;
  boolean_T c4_emptyp;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_g_b;
  boolean_T c4_guard1 = false;
  boolean_T c4_h_b;
  boolean_T c4_i_b;
  boolean_T c4_isDegenerate;
  boolean_T c4_isvalid_maxval;
  boolean_T c4_j_b;
  boolean_T c4_k_b;
  boolean_T c4_l_b;
  boolean_T c4_m_b;
  boolean_T c4_q_b;
  boolean_T c4_s_b;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_st.site = &c4_xc_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    chartInstance->c4_c_A[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_emptyp = true;
  c4_b_idx = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_b_idx + 1 <= 19200)) {
    c4_c_x = chartInstance->c4_c_A[c4_b_idx];
    c4_d_x = c4_c_x;
    c4_b = muSingleScalarIsInf(c4_d_x);
    c4_b_b = !c4_b;
    c4_e_x = c4_c_x;
    c4_c_b = muSingleScalarIsNaN(c4_e_x);
    c4_b1 = !c4_c_b;
    c4_d_b = (c4_b_b && c4_b1);
    if (!c4_d_b) {
      c4_b_idx++;
    } else {
      c4_exitg1 = true;
    }
  }

  c4_emxInit_real32_T(chartInstance, &c4_st, &c4_img, 1, &c4_fc_emlrtRTEI);
  if (c4_b_idx + 1 <= 19200) {
    c4_minA = chartInstance->c4_c_A[c4_b_idx];
    c4_maxA = chartInstance->c4_c_A[c4_b_idx];
    c4_i2 = c4_b_idx;
    for (c4_k = c4_i2 + 2; c4_k < 19201; c4_k++) {
      c4_g_a = chartInstance->c4_c_A[c4_k - 1];
      c4_guard1 = false;
      if (c4_g_a < c4_minA) {
        c4_f_x = c4_g_a;
        c4_g_x = c4_f_x;
        c4_e_b = muSingleScalarIsInf(c4_g_x);
        c4_b2 = !c4_e_b;
        c4_j_x = c4_f_x;
        c4_g_b = muSingleScalarIsNaN(c4_j_x);
        c4_b3 = !c4_g_b;
        c4_i_b = (c4_b2 && c4_b3);
        if (c4_i_b) {
          c4_minA = c4_g_a;
        } else {
          c4_guard1 = true;
        }
      } else {
        c4_guard1 = true;
      }

      if (c4_guard1 && (c4_g_a > c4_maxA)) {
        c4_i_x = c4_g_a;
        c4_k_x = c4_i_x;
        c4_h_b = muSingleScalarIsInf(c4_k_x);
        c4_b4 = !c4_h_b;
        c4_l_x = c4_i_x;
        c4_j_b = muSingleScalarIsNaN(c4_l_x);
        c4_b5 = !c4_j_b;
        c4_k_b = (c4_b4 && c4_b5);
        if (c4_k_b) {
          c4_maxA = c4_g_a;
        }
      }
    }

    if (!(c4_minA == c4_maxA)) {
      for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
        chartInstance->c4_c_A[c4_i3] -= c4_minA;
      }

      c4_y = c4_maxA - c4_minA;
      c4_b_y = c4_y;
      for (c4_i5 = 0; c4_i5 < 19200; c4_i5++) {
        chartInstance->c4_c_A[c4_i5] /= c4_b_y;
      }

      for (c4_i6 = 0; c4_i6 < 19200; c4_i6++) {
        c4_nans[c4_i6] = muSingleScalarIsNaN(chartInstance->c4_c_A[c4_i6]);
      }

      c4_trueCount = 0;
      for (c4_b_i = 0; c4_b_i < 19200; c4_b_i++) {
        if (!c4_nans[c4_b_i]) {
          c4_trueCount++;
        }
      }

      if (c4_trueCount != 0) {
        c4_b_trueCount = 0;
        for (c4_c_i = 0; c4_c_i < 19200; c4_c_i++) {
          if (!c4_nans[c4_c_i]) {
            c4_b_trueCount++;
          }
        }

        c4_emxInit_int32_T(chartInstance, &c4_st, &c4_r, 1, &c4_ed_emlrtRTEI);
        c4_i10 = c4_r->size[0];
        c4_r->size[0] = c4_b_trueCount;
        c4_b_st.site = &c4_xc_emlrtRSI;
        c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_r, c4_i10,
          &c4_ec_emlrtRTEI);
        c4_partialTrueCount = 0;
        for (c4_d_i = 0; c4_d_i < 19200; c4_d_i++) {
          if (!c4_nans[c4_d_i]) {
            c4_r->data[c4_partialTrueCount] = c4_d_i + 1;
            c4_partialTrueCount++;
          }
        }

        c4_b_st.site = &c4_ld_emlrtRSI;
        c4_i13 = c4_img->size[0];
        c4_img->size[0] = c4_r->size[0];
        c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_img, c4_i13,
          &c4_fc_emlrtRTEI);
        c4_loop_ub = c4_r->size[0] - 1;
        for (c4_i14 = 0; c4_i14 <= c4_loop_ub; c4_i14++) {
          c4_img->data[c4_i14] = chartInstance->c4_c_A[c4_r->data[c4_i14] - 1];
        }

        c4_emxFree_int32_T(chartInstance, &c4_r);
        c4_c_st.site = &c4_l_emlrtRSI;
        c4_Auint8_size[0] = c4_img->size[0];
        c4_numElems = (real_T)c4_img->size[0];
        c4_b_numElems = c4_numElems;
        grayto8_real32(&c4_img->data[0], &c4_Auint8_data[0], c4_b_numElems);
        c4_b_st.site = &c4_md_emlrtRSI;
        c4_c_imhist(chartInstance, &c4_b_st, c4_Auint8_data, c4_Auint8_size,
                    c4_counts);
        for (c4_i15 = 0; c4_i15 < 256; c4_i15++) {
          c4_d_counts[c4_i15] = c4_counts[c4_i15];
        }

        c4_d = c4_sum(chartInstance, c4_d_counts);
        for (c4_i17 = 0; c4_i17 < 256; c4_i17++) {
          c4_mu[c4_i17] = c4_counts[c4_i17] / c4_d;
        }

        c4_emptyp = false;
      }
    }
  } else {
    c4_b_st.site = &c4_jd_emlrtRSI;
    for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
      chartInstance->c4_b_varargin_1[c4_i1] = chartInstance->c4_c_A[c4_i1];
    }

    c4_c_st.site = &c4_nd_emlrtRSI;
    c4_d_st.site = &c4_od_emlrtRSI;
    c4_minA = c4_minimum(chartInstance, &c4_d_st, chartInstance->c4_b_varargin_1);
    c4_b_st.site = &c4_kd_emlrtRSI;
    c4_c_st.site = &c4_sb_emlrtRSI;
    c4_d_st.site = &c4_tb_emlrtRSI;
    c4_maxA = c4_maximum(chartInstance, &c4_d_st, chartInstance->c4_c_A);
  }

  if (c4_emptyp) {
    c4_st.site = &c4_yc_emlrtRSI;
    c4_b_warning(chartInstance, &c4_st);
    c4_b_minA = c4_minA;
    c4_h_x = c4_b_minA;
    c4_f_b = muSingleScalarIsNaN(c4_h_x);
    if (c4_f_b) {
      c4_b_minA = 1.0F;
    }

    c4_threshout = c4_b_minA;
    c4_thresh = c4_threshout;
  } else {
    for (c4_i4 = 0; c4_i4 < 256; c4_i4++) {
      c4_omega[c4_i4] = c4_mu[c4_i4];
    }

    for (c4_b_k = 0; c4_b_k < 255; c4_b_k++) {
      c4_c_k = c4_b_k;
      c4_omega[c4_c_k + 1] += c4_omega[c4_c_k];
    }

    for (c4_i7 = 0; c4_i7 < 256; c4_i7++) {
      c4_mu[c4_i7] *= 1.0 + (real_T)c4_i7;
    }

    for (c4_d_k = 0; c4_d_k < 255; c4_d_k++) {
      c4_e_k = c4_d_k;
      c4_mu[c4_e_k + 1] += c4_mu[c4_e_k];
    }

    c4_mu_t = c4_mu[255];
    c4_b_mu_t = c4_mu_t;
    c4_h_a = c4_b_mu_t;
    for (c4_i8 = 0; c4_i8 < 256; c4_i8++) {
      c4_counts[c4_i8] = c4_h_a * c4_omega[c4_i8];
    }

    for (c4_i9 = 0; c4_i9 < 256; c4_i9++) {
      c4_b_counts[c4_i9] = c4_counts[c4_i9] - c4_mu[c4_i9];
    }

    c4_power(chartInstance, c4_b_counts, c4_counts);
    for (c4_i11 = 0; c4_i11 < 256; c4_i11++) {
      c4_counts[c4_i11] /= c4_omega[c4_i11] * (1.0 - c4_omega[c4_i11]);
    }

    c4_st.site = &c4_ad_emlrtRSI;
    c4_b_st.site = &c4_sb_emlrtRSI;
    c4_c_st.site = &c4_tb_emlrtRSI;
    for (c4_i12 = 0; c4_i12 < 256; c4_i12++) {
      c4_c_counts[c4_i12] = c4_counts[c4_i12];
    }

    c4_maxval = c4_b_maximum(chartInstance, &c4_c_st, c4_c_counts);
    c4_m_x = c4_maxval;
    c4_n_x = c4_m_x;
    c4_l_b = muDoubleScalarIsInf(c4_n_x);
    c4_b6 = !c4_l_b;
    c4_o_x = c4_m_x;
    c4_m_b = muDoubleScalarIsNaN(c4_o_x);
    c4_b7 = !c4_m_b;
    c4_isvalid_maxval = (c4_b6 && c4_b7);
    c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_b_threshout, 2,
                         &c4_cd_emlrtRTEI);
    c4_emxInit_real_T(chartInstance, c4_sp, &c4_threshRaw, 2, &c4_hc_emlrtRTEI);
    c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_uniqueVals, 2,
                         &c4_dd_emlrtRTEI);
    c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_threshL, 2, &c4_xc_emlrtRTEI);
    c4_emxInit_real_T(chartInstance, c4_sp, &c4_uniqueVals_d, 2,
                      &c4_wc_emlrtRTEI);
    c4_emxInit_real_T1(chartInstance, c4_sp, &c4_r1, 1, &c4_bd_emlrtRTEI);
    if (c4_isvalid_maxval) {
      c4_idxSum = 0.0;
      c4_idxNum = 0.0;
      for (c4_ind = 0; c4_ind < 256; c4_ind++) {
        c4_b_ind = (real_T)c4_ind + 1.0;
        if (c4_counts[(int32_T)c4_b_ind - 1] == c4_maxval) {
          c4_idxSum += c4_b_ind;
          c4_idxNum++;
        }
      }

      c4_i18 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
      c4_threshRaw->size[0] = 1;
      c4_threshRaw->size[1] = 1;
      c4_st.site = &c4_yk_emlrtRSI;
      c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_threshRaw, c4_i18,
        &c4_hc_emlrtRTEI);
      c4_threshRaw->data[0] = c4_idxSum / c4_idxNum - 1.0;
    } else {
      c4_st.site = &c4_bd_emlrtRSI;
      c4_b_st.site = &c4_yd_emlrtRSI;
      for (c4_i16 = 0; c4_i16 < 19200; c4_i16++) {
        chartInstance->c4_b_varargin_1[c4_i16] = c4_d_varargin_1[c4_i16];
      }

      c4_c_st.site = &c4_be_emlrtRSI;
      c4_unique_vector(chartInstance, &c4_c_st, chartInstance->c4_b_varargin_1,
                       c4_img);
      c4_i19 = c4_uniqueVals->size[0] * c4_uniqueVals->size[1];
      c4_uniqueVals->size[0] = 1;
      c4_uniqueVals->size[1] = c4_img->size[0];
      c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_uniqueVals,
        c4_i19, &c4_ic_emlrtRTEI);
      c4_b_loop_ub = c4_img->size[0] - 1;
      for (c4_i20 = 0; c4_i20 <= c4_b_loop_ub; c4_i20++) {
        c4_uniqueVals->data[c4_i20] = c4_img->data[c4_i20];
      }

      c4_tmp_size[0] = 1;
      c4_tmp_size[1] = c4_uniqueVals->size[1];
      c4_c_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
      for (c4_i24 = 0; c4_i24 <= c4_c_loop_ub; c4_i24++) {
        c4_tmp_data[c4_i24] = muSingleScalarIsInf(c4_uniqueVals->data[c4_i24]);
      }

      c4_b_tmp_size[0] = 1;
      c4_b_tmp_size[1] = c4_uniqueVals->size[1];
      c4_e_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
      for (c4_i28 = 0; c4_i28 <= c4_e_loop_ub; c4_i28++) {
        c4_b_tmp_data[c4_i28] = muSingleScalarIsNaN(c4_uniqueVals->data[c4_i28]);
      }

      emlrtSizeEqCheckNDR2012b(c4_tmp_size, c4_b_tmp_size, &c4_emlrtECI, &c4_st);
      c4_c_tmp_size[0] = 1;
      c4_c_tmp_size[1] = c4_tmp_size[1];
      c4_g_loop_ub = c4_tmp_size[0] * c4_tmp_size[1] - 1;
      for (c4_i32 = 0; c4_i32 <= c4_g_loop_ub; c4_i32++) {
        c4_c_tmp_data[c4_i32] = (c4_tmp_data[c4_i32] || c4_b_tmp_data[c4_i32]);
      }

      c4_b_st.site = &c4_ae_emlrtRSI;
      c4_b_nullAssignment(chartInstance, &c4_b_st, c4_uniqueVals, c4_c_tmp_data,
                          c4_c_tmp_size);
      c4_isDegenerate = ((real_T)c4_uniqueVals->size[1] <= 1.0);
      if (c4_isDegenerate) {
        c4_st.site = &c4_cd_emlrtRSI;
        c4_b_warning(chartInstance, &c4_st);
      } else {
        c4_st.site = &c4_dd_emlrtRSI;
        c4_c_warning(chartInstance, &c4_st);
      }

      c4_st.site = &c4_ed_emlrtRSI;
      c4_b8 = (c4_uniqueVals->size[1] == 0);
      if (c4_b8) {
        c4_i41 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
        c4_b_threshout->size[0] = 1;
        c4_b_threshout->size[1] = 1;
        c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_b_threshout,
          c4_i41, &c4_oc_emlrtRTEI);
        c4_b_threshout->data[0] = 1.0F;
      } else {
        c4_thNeeded1 = 1.0 - (real_T)c4_uniqueVals->size[1];
        if (c4_thNeeded1 > 0.0) {
          c4_i45 = c4_uniqueVals->size[1];
          c4_i46 = 1;
          emlrtDynamicBoundsCheckR2012b(c4_i46, 1, c4_i45, &c4_gc_emlrtBCI,
            &c4_st);
          if (c4_uniqueVals->data[0] > 1.0F) {
            c4_i49 = c4_uniqueVals->size[1];
            c4_i52 = 1;
            emlrtDynamicBoundsCheckR2012b(c4_i52, 1, c4_i49, &c4_fc_emlrtBCI,
              &c4_st);
            c4_p_x = c4_uniqueVals->data[0];
            c4_q_x = c4_p_x;
            c4_q_x = muSingleScalarCeil(c4_q_x);
            c4_b_varargin_2 = c4_q_x - 1.0F;
            c4_c_y = c4_b_varargin_2;
            c4_d_y = c4_c_y;
            c4_e_y = c4_d_y;
            c4_f_y = c4_e_y;
            c4_g_y = c4_f_y;
            c4_h_y = c4_g_y;
            c4_minval = muSingleScalarMin(1.0F, c4_h_y);
            c4_b_d = c4_minval;
            c4_p_b = c4_b_d;
            c4_t_x = c4_p_b;
            c4_q_b = muSingleScalarIsNaN(c4_t_x);
            if (c4_q_b) {
              c4_y_size[1] = 1;
              c4_y_data[0] = rtNaNF;
            } else if (c4_p_b < 1.0F) {
              c4_y_size[1] = 0;
            } else {
              c4_y_size[1] = 1;
              c4_y_data[0] = 1.0F;
            }

            c4_i81 = c4_threshL->size[0] * c4_threshL->size[1];
            c4_threshL->size[0] = 1;
            c4_threshL->size[1] = c4_y_size[1] + c4_uniqueVals->size[1];
            c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_threshL,
              c4_i81, &c4_xc_emlrtRTEI);
            c4_y_loop_ub = c4_y_size[1] - 1;
            for (c4_i89 = 0; c4_i89 <= c4_y_loop_ub; c4_i89++) {
              c4_threshL->data[c4_i89] = c4_y_data[c4_i89];
            }

            c4_cb_loop_ub = c4_uniqueVals->size[1] - 1;
            for (c4_i93 = 0; c4_i93 <= c4_cb_loop_ub; c4_i93++) {
              c4_threshL->data[c4_i93 + c4_y_size[1]] = c4_uniqueVals->
                data[c4_i93];
            }
          } else {
            c4_i48 = c4_threshL->size[0] * c4_threshL->size[1];
            c4_threshL->size[0] = 1;
            c4_threshL->size[1] = c4_uniqueVals->size[1];
            c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_threshL,
              c4_i48, &c4_qc_emlrtRTEI);
            c4_o_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
            for (c4_i54 = 0; c4_i54 <= c4_o_loop_ub; c4_i54++) {
              c4_threshL->data[c4_i54] = c4_uniqueVals->data[c4_i54];
            }
          }

          c4_thNeeded2 = 1.0 - (real_T)c4_threshL->size[1];
          if (c4_thNeeded2 > 0.0) {
            c4_lenThreshOrig = (real_T)c4_threshL->size[1];
            c4_i66 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
            c4_b_threshout->size[0] = 1;
            c4_b_threshout->size[1] = c4_threshL->size[1] + 1;
            c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_b_threshout,
              c4_i66, &c4_uc_emlrtRTEI);
            c4_t_loop_ub = c4_threshL->size[1] - 1;
            for (c4_i74 = 0; c4_i74 <= c4_t_loop_ub; c4_i74++) {
              c4_b_threshout->data[c4_i74] = c4_threshL->data[c4_i74];
            }

            c4_b_threshout->data[c4_threshL->size[1]] = 0.0F;
            c4_i77 = c4_uniqueVals_d->size[0] * c4_uniqueVals_d->size[1];
            c4_uniqueVals_d->size[0] = 1;
            c4_uniqueVals_d->size[1] = c4_uniqueVals->size[1];
            c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_uniqueVals_d,
              c4_i77, &c4_wc_emlrtRTEI);
            c4_w_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
            for (c4_i84 = 0; c4_i84 <= c4_w_loop_ub; c4_i84++) {
              c4_uniqueVals_d->data[c4_i84] = c4_uniqueVals->data[c4_i84];
            }

            c4_i86 = c4_uniqueVals->size[1];
            c4_i88 = 1;
            emlrtDynamicBoundsCheckR2012b(c4_i88, 1, c4_i86, &c4_ec_emlrtBCI,
              &c4_st);
            c4_v_x = c4_uniqueVals->data[0];
            c4_e_varargin_1 = c4_v_x;
            c4_e_varargin_1 = muSingleScalarFloor(c4_e_varargin_1);
            c4_w_x = c4_e_varargin_1;
            c4_x_x = c4_w_x;
            c4_y_x = c4_x_x;
            c4_ab_x = c4_y_x;
            c4_bb_x = c4_ab_x;
            c4_cb_x = c4_bb_x;
            c4_threshCandidate = muSingleScalarMax(c4_cb_x, 0.0F);
            c4_q = 1.0;
            c4_emxInit_real_T1(chartInstance, &c4_st, &c4_b_uniqueVals_d, 1,
                               &c4_ad_emlrtRTEI);
            while (c4_q <= 1.0) {
              c4_threshCandidate++;
              c4_threshCandidate_d = c4_threshCandidate;
              c4_c_uniqueVals_d[0] = c4_uniqueVals_d->size[1];
              c4_i102 = c4_b_uniqueVals_d->size[0];
              c4_b_uniqueVals_d->size[0] = c4_c_uniqueVals_d[0];
              c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st,
                c4_b_uniqueVals_d, c4_i102, &c4_ad_emlrtRTEI);
              c4_hb_loop_ub = c4_c_uniqueVals_d[0] - 1;
              for (c4_i103 = 0; c4_i103 <= c4_hb_loop_ub; c4_i103++) {
                c4_b_uniqueVals_d->data[c4_i103] = c4_uniqueVals_d->data[c4_i103]
                  - c4_threshCandidate_d;
              }

              c4_b_st.site = &c4_qe_emlrtRSI;
              c4_abs(chartInstance, &c4_b_st, c4_b_uniqueVals_d, c4_r1);
              c4_b_st.site = &c4_re_emlrtRSI;
              c4_d1 = c4_eps(chartInstance, c4_threshCandidate_d);
              c4_e_tmp_size[0] = c4_r1->size[0];
              c4_ib_loop_ub = c4_r1->size[0] - 1;
              for (c4_i105 = 0; c4_i105 <= c4_ib_loop_ub; c4_i105++) {
                c4_e_tmp_data[c4_i105] = (c4_r1->data[c4_i105] < c4_d1);
              }

              c4_b_st.site = &c4_qe_emlrtRSI;
              c4_f_tmp_size[0] = c4_e_tmp_size[0];
              if (!c4_any(chartInstance, &c4_b_st, c4_e_tmp_data, c4_f_tmp_size))
              {
                c4_i107 = c4_b_threshout->size[1];
                c4_i108 = (int32_T)(c4_lenThreshOrig + 1.0);
                c4_b_threshout->data[emlrtDynamicBoundsCheckR2012b(c4_i108, 1,
                  c4_i107, &c4_ic_emlrtBCI, &c4_st) - 1] = c4_threshCandidate;
                c4_q = 2.0;
              }
            }

            c4_emxFree_real_T(chartInstance, &c4_b_uniqueVals_d);
            c4_b_st.site = &c4_se_emlrtRSI;
            c4_c_st.site = &c4_xe_emlrtRSI;
            c4_c_sort(chartInstance, &c4_c_st, c4_b_threshout);
          } else {
            c4_i64 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
            c4_b_threshout->size[0] = 1;
            c4_b_threshout->size[1] = c4_threshL->size[1];
            c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_b_threshout,
              c4_i64, &c4_tc_emlrtRTEI);
            c4_s_loop_ub = c4_threshL->size[0] * c4_threshL->size[1] - 1;
            for (c4_i73 = 0; c4_i73 <= c4_s_loop_ub; c4_i73++) {
              c4_b_threshout->data[c4_i73] = c4_threshL->data[c4_i73];
            }
          }
        } else {
          c4_i44 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
          c4_b_threshout->size[0] = 1;
          c4_b_threshout->size[1] = c4_uniqueVals->size[1];
          c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_b_threshout,
            c4_i44, &c4_pc_emlrtRTEI);
          c4_n_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
          for (c4_i51 = 0; c4_i51 <= c4_n_loop_ub; c4_i51++) {
            c4_b_threshout->data[c4_i51] = c4_uniqueVals->data[c4_i51];
          }
        }
      }

      c4_i50 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
      c4_threshRaw->size[0] = 1;
      c4_threshRaw->size[1] = c4_b_threshout->size[1];
      c4_st.site = &c4_ed_emlrtRSI;
      c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_threshRaw, c4_i50,
        &c4_rc_emlrtRTEI);
      c4_p_loop_ub = c4_b_threshout->size[0] * c4_b_threshout->size[1] - 1;
      for (c4_i57 = 0; c4_i57 <= c4_p_loop_ub; c4_i57++) {
        c4_threshRaw->data[c4_i57] = c4_b_threshout->data[c4_i57];
      }
    }

    if (c4_isvalid_maxval) {
      c4_c_minA = c4_minA;
      c4_b_maxA = c4_maxA;
      c4_i22 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
      c4_i23 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
      c4_threshRaw->size[0] = 1;
      c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_threshRaw, c4_i23,
        &c4_kc_emlrtRTEI);
      c4_i26 = c4_i22;
      c4_d_loop_ub = c4_i26 - 1;
      for (c4_i27 = 0; c4_i27 <= c4_d_loop_ub; c4_i27++) {
        c4_threshRaw->data[c4_i27] /= 255.0;
      }

      c4_n_b = (real_T)c4_b_maxA - (real_T)c4_c_minA;
      c4_i30 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
      c4_i31 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
      c4_threshRaw->size[0] = 1;
      c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_threshRaw, c4_i31,
        &c4_j_emlrtRTEI);
      c4_i33 = c4_i30;
      c4_i_loop_ub = c4_i33 - 1;
      for (c4_i35 = 0; c4_i35 <= c4_i_loop_ub; c4_i35++) {
        c4_threshRaw->data[c4_i35] *= c4_n_b;
      }

      c4_i36 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
      c4_i37 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
      c4_threshRaw->size[0] = 1;
      c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_threshRaw, c4_i37,
        &c4_mc_emlrtRTEI);
      c4_i39 = c4_i36;
      c4_k_loop_ub = c4_i39 - 1;
      for (c4_i40 = 0; c4_i40 <= c4_k_loop_ub; c4_i40++) {
        c4_threshRaw->data[c4_i40] += (real_T)c4_c_minA;
      }

      c4_i43 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
      c4_b_threshout->size[0] = 1;
      c4_b_threshout->size[1] = c4_threshRaw->size[1];
      c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_threshout,
        c4_i43, &c4_nc_emlrtRTEI);
      c4_m_loop_ub = c4_threshRaw->size[0] * c4_threshRaw->size[1] - 1;
      for (c4_i47 = 0; c4_i47 <= c4_m_loop_ub; c4_i47++) {
        c4_b_threshout->data[c4_i47] = (real32_T)c4_threshRaw->data[c4_i47];
      }
    } else {
      c4_st.site = &c4_fd_emlrtRSI;
      c4_b_st.site = &c4_yd_emlrtRSI;
      for (c4_i21 = 0; c4_i21 < 19200; c4_i21++) {
        chartInstance->c4_b_varargin_1[c4_i21] = c4_d_varargin_1[c4_i21];
      }

      c4_c_st.site = &c4_be_emlrtRSI;
      c4_unique_vector(chartInstance, &c4_c_st, chartInstance->c4_b_varargin_1,
                       c4_img);
      c4_i25 = c4_uniqueVals->size[0] * c4_uniqueVals->size[1];
      c4_uniqueVals->size[0] = 1;
      c4_uniqueVals->size[1] = c4_img->size[0];
      c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_uniqueVals,
        c4_i25, &c4_ic_emlrtRTEI);
      c4_f_loop_ub = c4_img->size[0] - 1;
      for (c4_i29 = 0; c4_i29 <= c4_f_loop_ub; c4_i29++) {
        c4_uniqueVals->data[c4_i29] = c4_img->data[c4_i29];
      }

      c4_tmp_size[0] = 1;
      c4_tmp_size[1] = c4_uniqueVals->size[1];
      c4_h_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
      for (c4_i34 = 0; c4_i34 <= c4_h_loop_ub; c4_i34++) {
        c4_tmp_data[c4_i34] = muSingleScalarIsInf(c4_uniqueVals->data[c4_i34]);
      }

      c4_b_tmp_size[0] = 1;
      c4_b_tmp_size[1] = c4_uniqueVals->size[1];
      c4_j_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
      for (c4_i38 = 0; c4_i38 <= c4_j_loop_ub; c4_i38++) {
        c4_b_tmp_data[c4_i38] = muSingleScalarIsNaN(c4_uniqueVals->data[c4_i38]);
      }

      emlrtSizeEqCheckNDR2012b(c4_tmp_size, c4_b_tmp_size, &c4_emlrtECI, &c4_st);
      c4_d_tmp_size[0] = 1;
      c4_d_tmp_size[1] = c4_tmp_size[1];
      c4_l_loop_ub = c4_tmp_size[0] * c4_tmp_size[1] - 1;
      for (c4_i42 = 0; c4_i42 <= c4_l_loop_ub; c4_i42++) {
        c4_d_tmp_data[c4_i42] = (c4_tmp_data[c4_i42] || c4_b_tmp_data[c4_i42]);
      }

      c4_b_st.site = &c4_ae_emlrtRSI;
      c4_b_nullAssignment(chartInstance, &c4_b_st, c4_uniqueVals, c4_d_tmp_data,
                          c4_d_tmp_size);
      c4_b_isDegenerate = ((real_T)c4_uniqueVals->size[1] <= 1.0);
      if (c4_b_isDegenerate) {
        c4_st.site = &c4_gd_emlrtRSI;
        c4_b_warning(chartInstance, &c4_st);
        c4_st.site = &c4_hd_emlrtRSI;
        c4_b9 = (c4_uniqueVals->size[1] == 0);
        if (c4_b9) {
          c4_i56 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
          c4_b_threshout->size[0] = 1;
          c4_b_threshout->size[1] = 1;
          c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_b_threshout,
            c4_i56, &c4_sc_emlrtRTEI);
          c4_b_threshout->data[0] = 1.0F;
        } else {
          c4_b_thNeeded1 = 1.0 - (real_T)c4_uniqueVals->size[1];
          if (c4_b_thNeeded1 > 0.0) {
            c4_i59 = c4_uniqueVals->size[1];
            c4_i62 = 1;
            emlrtDynamicBoundsCheckR2012b(c4_i62, 1, c4_i59, &c4_gc_emlrtBCI,
              &c4_st);
            if (c4_uniqueVals->data[0] > 1.0F) {
              c4_i68 = c4_uniqueVals->size[1];
              c4_i70 = 1;
              emlrtDynamicBoundsCheckR2012b(c4_i70, 1, c4_i68, &c4_fc_emlrtBCI,
                &c4_st);
              c4_r_x = c4_uniqueVals->data[0];
              c4_s_x = c4_r_x;
              c4_s_x = muSingleScalarCeil(c4_s_x);
              c4_c_varargin_2 = c4_s_x - 1.0F;
              c4_i_y = c4_c_varargin_2;
              c4_j_y = c4_i_y;
              c4_k_y = c4_j_y;
              c4_l_y = c4_k_y;
              c4_m_y = c4_l_y;
              c4_n_y = c4_m_y;
              c4_b_minval = muSingleScalarMin(1.0F, c4_n_y);
              c4_c_d = c4_b_minval;
              c4_r_b = c4_c_d;
              c4_u_x = c4_r_b;
              c4_s_b = muSingleScalarIsNaN(c4_u_x);
              if (c4_s_b) {
                c4_y_size[1] = 1;
                c4_y_data[0] = rtNaNF;
              } else if (c4_r_b < 1.0F) {
                c4_y_size[1] = 0;
              } else {
                c4_y_size[1] = 1;
                c4_y_data[0] = 1.0F;
              }

              c4_i95 = c4_threshL->size[0] * c4_threshL->size[1];
              c4_threshL->size[0] = 1;
              c4_threshL->size[1] = c4_y_size[1] + c4_uniqueVals->size[1];
              c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_threshL,
                c4_i95, &c4_xc_emlrtRTEI);
              c4_fb_loop_ub = c4_y_size[1] - 1;
              for (c4_i100 = 0; c4_i100 <= c4_fb_loop_ub; c4_i100++) {
                c4_threshL->data[c4_i100] = c4_y_data[c4_i100];
              }

              c4_gb_loop_ub = c4_uniqueVals->size[1] - 1;
              for (c4_i101 = 0; c4_i101 <= c4_gb_loop_ub; c4_i101++) {
                c4_threshL->data[c4_i101 + c4_y_size[1]] = c4_uniqueVals->
                  data[c4_i101];
              }
            } else {
              c4_i67 = c4_threshL->size[0] * c4_threshL->size[1];
              c4_threshL->size[0] = 1;
              c4_threshL->size[1] = c4_uniqueVals->size[1];
              c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_threshL,
                c4_i67, &c4_qc_emlrtRTEI);
              c4_u_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
              for (c4_i75 = 0; c4_i75 <= c4_u_loop_ub; c4_i75++) {
                c4_threshL->data[c4_i75] = c4_uniqueVals->data[c4_i75];
              }
            }

            c4_b_thNeeded2 = 1.0 - (real_T)c4_threshL->size[1];
            if (c4_b_thNeeded2 > 0.0) {
              c4_b_lenThreshOrig = (real_T)c4_threshL->size[1];
              c4_i83 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
              c4_b_threshout->size[0] = 1;
              c4_b_threshout->size[1] = c4_threshL->size[1] + 1;
              c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st,
                c4_b_threshout, c4_i83, &c4_sc_emlrtRTEI);
              c4_bb_loop_ub = c4_threshL->size[1] - 1;
              for (c4_i91 = 0; c4_i91 <= c4_bb_loop_ub; c4_i91++) {
                c4_b_threshout->data[c4_i91] = c4_threshL->data[c4_i91];
              }

              c4_b_threshout->data[c4_threshL->size[1]] = 0.0F;
              c4_i94 = c4_uniqueVals_d->size[0] * c4_uniqueVals_d->size[1];
              c4_uniqueVals_d->size[0] = 1;
              c4_uniqueVals_d->size[1] = c4_uniqueVals->size[1];
              c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_uniqueVals_d,
                c4_i94, &c4_wc_emlrtRTEI);
              c4_eb_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] -
                1;
              for (c4_i97 = 0; c4_i97 <= c4_eb_loop_ub; c4_i97++) {
                c4_uniqueVals_d->data[c4_i97] = c4_uniqueVals->data[c4_i97];
              }

              c4_i98 = c4_uniqueVals->size[1];
              c4_i99 = 1;
              emlrtDynamicBoundsCheckR2012b(c4_i99, 1, c4_i98, &c4_ec_emlrtBCI,
                &c4_st);
              c4_db_x = c4_uniqueVals->data[0];
              c4_f_varargin_1 = c4_db_x;
              c4_f_varargin_1 = muSingleScalarFloor(c4_f_varargin_1);
              c4_eb_x = c4_f_varargin_1;
              c4_fb_x = c4_eb_x;
              c4_gb_x = c4_fb_x;
              c4_hb_x = c4_gb_x;
              c4_ib_x = c4_hb_x;
              c4_jb_x = c4_ib_x;
              c4_b_threshCandidate = muSingleScalarMax(c4_jb_x, 0.0F);
              c4_b_q = 1.0;
              c4_emxInit_real_T1(chartInstance, &c4_st, &c4_d_uniqueVals_d, 1,
                                 &c4_ad_emlrtRTEI);
              while (c4_b_q <= 1.0) {
                c4_b_threshCandidate++;
                c4_b_threshCandidate_d = c4_b_threshCandidate;
                c4_e_uniqueVals_d[0] = c4_uniqueVals_d->size[1];
                c4_i104 = c4_d_uniqueVals_d->size[0];
                c4_d_uniqueVals_d->size[0] = c4_e_uniqueVals_d[0];
                c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st,
                  c4_d_uniqueVals_d, c4_i104, &c4_ad_emlrtRTEI);
                c4_jb_loop_ub = c4_e_uniqueVals_d[0] - 1;
                for (c4_i106 = 0; c4_i106 <= c4_jb_loop_ub; c4_i106++) {
                  c4_d_uniqueVals_d->data[c4_i106] = c4_uniqueVals_d->
                    data[c4_i106] - c4_b_threshCandidate_d;
                }

                c4_b_st.site = &c4_qe_emlrtRSI;
                c4_abs(chartInstance, &c4_b_st, c4_d_uniqueVals_d, c4_r1);
                c4_b_st.site = &c4_re_emlrtRSI;
                c4_d2 = c4_eps(chartInstance, c4_b_threshCandidate_d);
                c4_g_tmp_size[0] = c4_r1->size[0];
                c4_kb_loop_ub = c4_r1->size[0] - 1;
                for (c4_i109 = 0; c4_i109 <= c4_kb_loop_ub; c4_i109++) {
                  c4_f_tmp_data[c4_i109] = (c4_r1->data[c4_i109] < c4_d2);
                }

                c4_b_st.site = &c4_qe_emlrtRSI;
                c4_h_tmp_size[0] = c4_g_tmp_size[0];
                if (!c4_any(chartInstance, &c4_b_st, c4_f_tmp_data,
                            c4_h_tmp_size)) {
                  c4_i110 = c4_b_threshout->size[1];
                  c4_i111 = (int32_T)(c4_b_lenThreshOrig + 1.0);
                  c4_b_threshout->data[emlrtDynamicBoundsCheckR2012b(c4_i111, 1,
                    c4_i110, &c4_ic_emlrtBCI, &c4_st) - 1] =
                    c4_b_threshCandidate;
                  c4_b_q = 2.0;
                }
              }

              c4_emxFree_real_T(chartInstance, &c4_d_uniqueVals_d);
              c4_b_st.site = &c4_se_emlrtRSI;
              c4_c_st.site = &c4_xe_emlrtRSI;
              c4_c_sort(chartInstance, &c4_c_st, c4_b_threshout);
            } else {
              c4_i80 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
              c4_b_threshout->size[0] = 1;
              c4_b_threshout->size[1] = c4_threshL->size[1];
              c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st,
                c4_b_threshout, c4_i80, &c4_sc_emlrtRTEI);
              c4_x_loop_ub = c4_threshL->size[0] * c4_threshL->size[1] - 1;
              for (c4_i87 = 0; c4_i87 <= c4_x_loop_ub; c4_i87++) {
                c4_b_threshout->data[c4_i87] = c4_threshL->data[c4_i87];
              }
            }
          } else {
            c4_i58 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
            c4_b_threshout->size[0] = 1;
            c4_b_threshout->size[1] = c4_uniqueVals->size[1];
            c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_b_threshout,
              c4_i58, &c4_sc_emlrtRTEI);
            c4_r_loop_ub = c4_uniqueVals->size[0] * c4_uniqueVals->size[1] - 1;
            for (c4_i69 = 0; c4_i69 <= c4_r_loop_ub; c4_i69++) {
              c4_b_threshout->data[c4_i69] = c4_uniqueVals->data[c4_i69];
            }
          }
        }
      } else {
        c4_st.site = &c4_id_emlrtRSI;
        c4_c_warning(chartInstance, &c4_st);
        c4_d_minA = c4_minA;
        c4_c_maxA = c4_maxA;
        c4_i53 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
        c4_i55 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
        c4_threshRaw->size[0] = 1;
        c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_threshRaw, c4_i55,
          &c4_kc_emlrtRTEI);
        c4_i61 = c4_i53;
        c4_q_loop_ub = c4_i61 - 1;
        for (c4_i65 = 0; c4_i65 <= c4_q_loop_ub; c4_i65++) {
          c4_threshRaw->data[c4_i65] /= 255.0;
        }

        c4_o_b = (real_T)c4_c_maxA - (real_T)c4_d_minA;
        c4_i71 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
        c4_i72 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
        c4_threshRaw->size[0] = 1;
        c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_threshRaw, c4_i72,
          &c4_j_emlrtRTEI);
        c4_i76 = c4_i71;
        c4_v_loop_ub = c4_i76 - 1;
        for (c4_i78 = 0; c4_i78 <= c4_v_loop_ub; c4_i78++) {
          c4_threshRaw->data[c4_i78] *= c4_o_b;
        }

        c4_i79 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
        c4_i82 = c4_threshRaw->size[0] * c4_threshRaw->size[1];
        c4_threshRaw->size[0] = 1;
        c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_threshRaw, c4_i82,
          &c4_mc_emlrtRTEI);
        c4_i85 = c4_i79;
        c4_ab_loop_ub = c4_i85 - 1;
        for (c4_i90 = 0; c4_i90 <= c4_ab_loop_ub; c4_i90++) {
          c4_threshRaw->data[c4_i90] += (real_T)c4_d_minA;
        }

        c4_i92 = c4_b_threshout->size[0] * c4_b_threshout->size[1];
        c4_b_threshout->size[0] = 1;
        c4_b_threshout->size[1] = c4_threshRaw->size[1];
        c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_b_threshout,
          c4_i92, &c4_yc_emlrtRTEI);
        c4_db_loop_ub = c4_threshRaw->size[0] * c4_threshRaw->size[1] - 1;
        for (c4_i96 = 0; c4_i96 <= c4_db_loop_ub; c4_i96++) {
          c4_b_threshout->data[c4_i96] = (real32_T)c4_threshRaw->data[c4_i96];
        }
      }
    }

    c4_emxFree_real_T(chartInstance, &c4_r1);
    c4_emxFree_real_T(chartInstance, &c4_uniqueVals_d);
    c4_emxFree_real32_T(chartInstance, &c4_threshL);
    c4_emxFree_real32_T(chartInstance, &c4_uniqueVals);
    c4_emxFree_real_T(chartInstance, &c4_threshRaw);
    c4_i60 = c4_b_threshout->size[1];
    c4_i63 = 1;
    emlrtDynamicBoundsCheckR2012b(c4_i63, 1, c4_i60, &c4_hc_emlrtBCI, c4_sp);
    c4_thresh = c4_b_threshout->data[0];
    c4_emxFree_real32_T(chartInstance, &c4_b_threshout);
  }

  c4_emxFree_real32_T(chartInstance, &c4_img);
  return c4_thresh;
}

static real32_T c4_minimum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real32_T c4_c_x[19200])
{
  c4_emxArray_real32_T *c4_d_x;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_first;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  real32_T c4_b_ex;
  real32_T c4_e_x;
  real32_T c4_ex;
  real32_T c4_f_x;
  real32_T c4_g_x;
  real32_T c4_h_x;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_d_x, 1, &c4_d_emlrtRTEI);
  c4_st.site = &c4_pd_emlrtRSI;
  c4_b_st.site = &c4_qd_emlrtRSI;
  c4_i = c4_d_x->size[0];
  c4_d_x->size[0] = 19200;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_b_st, c4_d_x, c4_i,
    &c4_d_emlrtRTEI);
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x[c4_i1];
  }

  c4_c_st.site = &c4_rd_emlrtRSI;
  c4_d_st.site = &c4_kb_emlrtRSI;
  c4_e_x = c4_d_x->data[0];
  c4_f_x = c4_e_x;
  c4_b = muSingleScalarIsNaN(c4_f_x);
  c4_p = !c4_b;
  if (c4_p) {
    c4_b_idx = 1;
  } else {
    c4_b_idx = 0;
    c4_e_st.site = &c4_lb_emlrtRSI;
    c4_k = 2;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k < 19201)) {
      c4_g_x = c4_d_x->data[c4_k - 1];
      c4_h_x = c4_g_x;
      c4_b_b = muSingleScalarIsNaN(c4_h_x);
      c4_b_p = !c4_b_b;
      if (c4_b_p) {
        c4_b_idx = c4_k;
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }
  }

  if (c4_b_idx == 0) {
    c4_ex = c4_d_x->data[0];
  } else {
    c4_d_st.site = &c4_jb_emlrtRSI;
    c4_first = c4_b_idx - 1;
    c4_b_ex = c4_d_x->data[c4_first];
    c4_i2 = c4_first;
    c4_e_st.site = &c4_nb_emlrtRSI;
    c4_overflow = false;
    if (c4_overflow) {
      c4_f_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
    }

    for (c4_b_k = c4_i2 + 1; c4_b_k + 1 < 19201; c4_b_k++) {
      if (c4_b_ex > c4_d_x->data[c4_b_k]) {
        c4_b_ex = c4_d_x->data[c4_b_k];
      }
    }

    c4_ex = c4_b_ex;
  }

  c4_emxFree_real32_T(chartInstance, &c4_d_x);
  return c4_ex;
}

static void c4_c_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, uint8_T c4_varargin_1_data[], int32_T
  c4_varargin_1_size[1], real_T c4_yout[256])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_localBins1[256];
  real_T c4_localBins2[256];
  real_T c4_localBins3[256];
  real_T c4_b_out;
  real_T c4_d_i;
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_c;
  int32_T c4_c_c;
  int32_T c4_c_i;
  int32_T c4_d_c;
  int32_T c4_e_c;
  int32_T c4_f_c;
  int32_T c4_g_a;
  int32_T c4_g_c;
  int32_T c4_h_a;
  int32_T c4_h_c;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i_a;
  int32_T c4_i_c;
  int32_T c4_idx1;
  int32_T c4_idx2;
  int32_T c4_idx3;
  int32_T c4_idx4;
  int32_T c4_j_a;
  int32_T c4_j_c;
  int32_T c4_k_a;
  int32_T c4_l_a;
  int32_T c4_m_a;
  int32_T c4_n_a;
  int32_T c4_o_a;
  int32_T c4_p_a;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_o_emlrtRSI;
  c4_b_st.site = &c4_q_emlrtRSI;
  c4_b_out = 1.0;
  getnumcores(&c4_b_out);
  c4_b_st.site = &c4_p_emlrtRSI;
  for (c4_i = 0; c4_i < 256; c4_i++) {
    c4_yout[c4_i] = 0.0;
  }

  for (c4_i1 = 0; c4_i1 < 256; c4_i1++) {
    c4_localBins1[c4_i1] = 0.0;
  }

  for (c4_i2 = 0; c4_i2 < 256; c4_i2++) {
    c4_localBins2[c4_i2] = 0.0;
  }

  for (c4_i3 = 0; c4_i3 < 256; c4_i3++) {
    c4_localBins3[c4_i3] = 0.0;
  }

  for (c4_b_i = 1; c4_b_i + 3 <= c4_varargin_1_size[0]; c4_b_i += 4) {
    c4_idx1 = c4_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c4_b_i, 1,
      c4_varargin_1_size[0], &c4_jc_emlrtBCI, &c4_b_st) - 1];
    c4_i4 = c4_b_i + 1;
    c4_idx2 = c4_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c4_i4, 1,
      c4_varargin_1_size[0], &c4_kc_emlrtBCI, &c4_b_st) - 1];
    c4_i5 = c4_b_i + 2;
    c4_idx3 = c4_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c4_i5, 1,
      c4_varargin_1_size[0], &c4_mc_emlrtBCI, &c4_b_st) - 1];
    c4_i6 = c4_b_i + 3;
    c4_idx4 = c4_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c4_i6, 1,
      c4_varargin_1_size[0], &c4_nc_emlrtBCI, &c4_b_st) - 1];
    c4_i_a = c4_idx1 + 1;
    c4_c_c = c4_i_a - 1;
    c4_j_a = c4_idx1 + 1;
    c4_d_c = c4_j_a - 1;
    c4_localBins1[c4_c_c] = c4_localBins1[c4_d_c] + 1.0;
    c4_k_a = c4_idx2 + 1;
    c4_e_c = c4_k_a - 1;
    c4_l_a = c4_idx2 + 1;
    c4_f_c = c4_l_a - 1;
    c4_localBins2[c4_e_c] = c4_localBins2[c4_f_c] + 1.0;
    c4_m_a = c4_idx3 + 1;
    c4_g_c = c4_m_a - 1;
    c4_n_a = c4_idx3 + 1;
    c4_h_c = c4_n_a - 1;
    c4_localBins3[c4_g_c] = c4_localBins3[c4_h_c] + 1.0;
    c4_o_a = c4_idx4 + 1;
    c4_i_c = c4_o_a - 1;
    c4_p_a = c4_idx4 + 1;
    c4_j_c = c4_p_a - 1;
    c4_yout[c4_i_c] = c4_yout[c4_j_c] + 1.0;
  }

  while (c4_b_i <= c4_varargin_1_size[0]) {
    c4_b_idx = c4_varargin_1_data[emlrtDynamicBoundsCheckR2012b(c4_b_i, 1,
      c4_varargin_1_size[0], &c4_lc_emlrtBCI, &c4_b_st) - 1];
    c4_g_a = c4_b_idx + 1;
    c4_c = c4_g_a - 1;
    c4_h_a = c4_b_idx + 1;
    c4_b_c = c4_h_a - 1;
    c4_yout[c4_c] = c4_yout[c4_b_c] + 1.0;
    c4_b_i++;
  }

  for (c4_c_i = 0; c4_c_i < 256; c4_c_i++) {
    c4_d_i = (real_T)c4_c_i + 1.0;
    c4_yout[(int32_T)c4_d_i - 1] = ((c4_yout[(int32_T)c4_d_i - 1] +
      c4_localBins1[(int32_T)c4_d_i - 1]) + c4_localBins2[(int32_T)c4_d_i - 1])
      + c4_localBins3[(int32_T)c4_d_i - 1];
  }
}

static real_T c4_sum(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     real_T c4_c_x[256])
{
  real_T c4_y;
  int32_T c4_ix;
  int32_T c4_k;
  int32_T c4_xoffset;
  (void)chartInstance;
  c4_y = c4_c_x[0];
  for (c4_k = 0; c4_k < 255; c4_k++) {
    c4_xoffset = c4_k;
    c4_ix = c4_xoffset;
    c4_y += c4_c_x[c4_ix + 1];
  }

  return c4_y;
}

static void c4_b_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp)
{
  static char_T c4_msgID[34] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'm', 'u',
    'l', 't', 'i', 't', 'h', 'r', 'e', 's', 'h', ':', 'd', 'e', 'g', 'e', 'n',
    'e', 'r', 'a', 't', 'e', 'I', 'n', 'p', 'u', 't' };

  static char_T c4_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c4_b_u = 1.0;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  c4_st.site = &c4_r_emlrtRSI;
  c4_d_feval(chartInstance, &c4_st, c4_y, c4_c_feval(chartInstance, &c4_st,
              c4_b_y, c4_c_y, c4_d_y));
}

static void c4_power(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     real_T c4_g_a[256], real_T c4_y[256])
{
  real_T c4_b_y;
  real_T c4_h_a;
  int32_T c4_b_k;
  int32_T c4_k;
  (void)chartInstance;
  for (c4_k = 0; c4_k < 256; c4_k++) {
    c4_b_k = c4_k;
    c4_h_a = c4_g_a[c4_b_k];
    c4_b_y = c4_h_a * c4_h_a;
    c4_y[c4_b_k] = c4_b_y;
  }
}

static real_T c4_b_maximum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_x[256])
{
  c4_emxArray_real_T *c4_d_x;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  real_T c4_b_ex;
  real_T c4_e_x;
  real_T c4_ex;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  int32_T c4_b_b;
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_b_n;
  int32_T c4_c_b;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_first;
  int32_T c4_g_a;
  int32_T c4_h_a;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  int32_T c4_last;
  int32_T c4_n;
  boolean_T c4_b;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_d_x, 1, &c4_emlrtRTEI);
  c4_st.site = &c4_ub_emlrtRSI;
  c4_b_st.site = &c4_vb_emlrtRSI;
  c4_i = c4_d_x->size[0];
  c4_d_x->size[0] = 256;
  c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_d_x, c4_i,
    &c4_emlrtRTEI);
  for (c4_i1 = 0; c4_i1 < 256; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x[c4_i1];
  }

  c4_c_st.site = &c4_ib_emlrtRSI;
  c4_n = c4_d_x->size[0];
  c4_d_st.site = &c4_kb_emlrtRSI;
  c4_b_n = c4_d_x->size[0];
  c4_e_x = c4_d_x->data[0];
  c4_f_x = c4_e_x;
  c4_b = muDoubleScalarIsNaN(c4_f_x);
  c4_p = !c4_b;
  if (c4_p) {
    c4_b_idx = 1;
  } else {
    c4_b_idx = 0;
    c4_e_st.site = &c4_lb_emlrtRSI;
    c4_b_b = c4_b_n;
    c4_c_b = c4_b_b;
    if (2 > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_f_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
    }

    c4_k = 2;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k <= c4_b_n)) {
      c4_g_x = c4_d_x->data[c4_k - 1];
      c4_h_x = c4_g_x;
      c4_f_b = muDoubleScalarIsNaN(c4_h_x);
      c4_b_p = !c4_f_b;
      if (c4_b_p) {
        c4_b_idx = c4_k;
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }
  }

  if (c4_b_idx == 0) {
    c4_ex = c4_d_x->data[0];
  } else {
    c4_d_st.site = &c4_jb_emlrtRSI;
    c4_first = c4_b_idx - 1;
    c4_last = c4_n;
    c4_b_ex = c4_d_x->data[c4_first];
    c4_i2 = c4_first + 2;
    c4_e_st.site = &c4_nb_emlrtRSI;
    c4_g_a = c4_i2;
    c4_d_b = c4_last;
    c4_h_a = c4_g_a;
    c4_e_b = c4_d_b;
    if (c4_h_a > c4_e_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_e_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_f_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
    }

    for (c4_b_k = c4_i2 - 1; c4_b_k < c4_last; c4_b_k++) {
      if (c4_b_ex < c4_d_x->data[c4_b_k]) {
        c4_b_ex = c4_d_x->data[c4_b_k];
      }
    }

    c4_ex = c4_b_ex;
  }

  c4_emxFree_real_T(chartInstance, &c4_d_x);
  return c4_ex;
}

static void c4_mergesort(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_b_idx[19200], real32_T c4_c_x[19200],
  int32_T c4_c_idx[19200])
{
  int32_T c4_i;
  int32_T c4_i1;
  real32_T c4_d_x[19200];
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_c_idx[c4_i] = c4_b_idx[c4_i];
  }

  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_d_x[c4_i1] = c4_c_x[c4_i1];
  }

  c4_c_mergesort(chartInstance, c4_sp, c4_c_idx, c4_d_x);
}

static void c4_unique_vector(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real32_T c4_g_a[19200],
  c4_emxArray_real32_T *c4_b)
{
  c4_emxArray_real32_T *c4_b_b;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_iv[2];
  int32_T c4_b_c;
  int32_T c4_b_exponent;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_c;
  int32_T c4_c_b;
  int32_T c4_c_c;
  int32_T c4_c_k;
  int32_T c4_e_b;
  int32_T c4_exitg2;
  int32_T c4_exponent;
  int32_T c4_g_b;
  int32_T c4_h_a;
  int32_T c4_h_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i_a;
  int32_T c4_i_b;
  int32_T c4_j;
  int32_T c4_j_a;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k0;
  int32_T c4_k_a;
  int32_T c4_k_b;
  int32_T c4_khi;
  int32_T c4_l_a;
  int32_T c4_l_b;
  int32_T c4_loop_ub;
  int32_T c4_m_a;
  int32_T c4_m_b;
  int32_T c4_nFinite;
  int32_T c4_nInf;
  int32_T c4_nNaN;
  int32_T c4_n_a;
  int32_T c4_nb;
  int32_T c4_o_a;
  int32_T c4_p_b;
  int32_T c4_q_a;
  int32_T c4_q_b;
  int32_T c4_r_a;
  int32_T c4_r_b;
  int32_T c4_s_a;
  int32_T c4_t_a;
  int32_T c4_t_b;
  int32_T c4_u_a;
  int32_T c4_v_a;
  int32_T c4_v_b;
  real32_T c4_absx;
  real32_T c4_c_x;
  real32_T c4_d_x;
  real32_T c4_e_x;
  real32_T c4_f_x;
  real32_T c4_g_x;
  real32_T c4_h_x;
  real32_T c4_i_x;
  real32_T c4_j_x;
  real32_T c4_k_x;
  real32_T c4_l_x;
  real32_T c4_m_x;
  real32_T c4_n_b;
  real32_T c4_n_x;
  real32_T c4_o_x;
  real32_T c4_p_a;
  real32_T c4_p_x;
  real32_T c4_q_x;
  real32_T c4_r;
  real32_T c4_r_x;
  real32_T c4_s_x;
  real32_T c4_t_x;
  real32_T c4_y;
  real32_T c4_z;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_overflow;
  boolean_T c4_d_b;
  boolean_T c4_d_overflow;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_o_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  boolean_T c4_s_b;
  boolean_T c4_u_b;
  boolean_T c4_w_b;
  boolean_T c4_x_b;
  boolean_T c4_y_b;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_je_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    chartInstance->c4_idx[c4_i] = 0;
  }

  c4_b_st.site = &c4_ud_emlrtRSI;
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    chartInstance->c4_a[c4_i1] = c4_g_a[c4_i1];
  }

  c4_c_mergesort(chartInstance, &c4_b_st, chartInstance->c4_idx,
                 chartInstance->c4_a);
  c4_i2 = c4_b->size[0];
  c4_b->size[0] = 19200;
  c4_st.site = &c4_tk_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b, c4_i2,
    &c4_fd_emlrtRTEI);
  for (c4_k = 0; c4_k < 19200; c4_k++) {
    c4_b_k = c4_k;
    c4_b->data[c4_b_k] = c4_g_a[chartInstance->c4_idx[c4_b_k] - 1];
  }

  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_b, 1, &c4_gd_emlrtRTEI);
  c4_i3 = c4_b_b->size[0];
  c4_b_b->size[0] = c4_b->size[0];
  c4_st.site = &c4_sk_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_b, c4_i3,
    &c4_gd_emlrtRTEI);
  c4_loop_ub = c4_b->size[0] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_loop_ub; c4_i4++) {
    c4_b_b->data[c4_i4] = c4_b->data[c4_i4];
  }

  c4_c_k = 19200;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_k >= 1)) {
    c4_c_x = c4_b_b->data[c4_c_k - 1];
    c4_d_b = muSingleScalarIsNaN(c4_c_x);
    if (c4_d_b) {
      c4_h_a = c4_c_k - 1;
      c4_c_k = c4_h_a;
    } else {
      c4_exitg1 = true;
    }
  }

  c4_c_b = c4_c_k;
  c4_nNaN = 19200 - c4_c_b;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_k >= 1)) {
    c4_d_x = c4_b_b->data[c4_c_k - 1];
    c4_f_b = muSingleScalarIsInf(c4_d_x);
    if (c4_f_b && (c4_b_b->data[c4_c_k - 1] > 0.0F)) {
      c4_j_a = c4_c_k - 1;
      c4_c_k = c4_j_a;
    } else {
      c4_exitg1 = true;
    }
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_b);
  c4_e_b = c4_c_k;
  c4_c = 19200 - c4_e_b;
  c4_i_a = c4_c;
  c4_g_b = c4_nNaN;
  c4_nInf = c4_i_a - c4_g_b;
  c4_k_a = c4_c_k;
  c4_nFinite = c4_k_a;
  c4_nb = -1;
  c4_h_b = c4_nFinite;
  c4_khi = c4_h_b;
  c4_b_k = 1;
  while (c4_b_k <= c4_khi) {
    c4_e_x = c4_b->data[c4_b_k - 1];
    c4_k0 = c4_b_k;
    do {
      c4_exitg2 = 0;
      c4_o_a = c4_b_k + 1;
      c4_b_k = c4_o_a;
      if (c4_b_k > c4_khi) {
        c4_exitg2 = 1;
      } else {
        c4_st.site = &c4_he_emlrtRSI;
        c4_p_a = c4_b->data[c4_b_k - 1];
        c4_n_b = c4_e_x;
        c4_f_x = c4_n_b;
        c4_g_x = c4_f_x;
        c4_z = c4_g_x / 2.0F;
        c4_h_x = c4_n_b - c4_p_a;
        c4_i_x = c4_h_x;
        c4_j_x = c4_i_x;
        c4_y = muSingleScalarAbs(c4_j_x);
        c4_b_st.site = &c4_wd_emlrtRSI;
        c4_k_x = c4_z;
        c4_l_x = c4_k_x;
        c4_m_x = c4_l_x;
        c4_n_x = c4_m_x;
        c4_o_x = c4_n_x;
        c4_absx = muSingleScalarAbs(c4_o_x);
        c4_p_x = c4_absx;
        c4_q_x = c4_p_x;
        c4_s_b = muSingleScalarIsInf(c4_q_x);
        c4_b1 = !c4_s_b;
        c4_r_x = c4_p_x;
        c4_u_b = muSingleScalarIsNaN(c4_r_x);
        c4_b2 = !c4_u_b;
        c4_w_b = (c4_b1 && c4_b2);
        if (c4_w_b) {
          if (c4_absx <= 1.17549435E-38F) {
            c4_r = 1.4013E-45F;
          } else {
            frexpf(c4_absx, &c4_exponent);
            c4_b_exponent = c4_exponent;
            c4_r = ldexpf(1.0F, c4_b_exponent - 24);
          }
        } else {
          c4_r = rtNaNF;
        }

        if (c4_y < c4_r) {
          c4_p = true;
        } else {
          c4_s_x = c4_p_a;
          c4_x_b = muSingleScalarIsInf(c4_s_x);
          if (c4_x_b) {
            c4_t_x = c4_n_b;
            c4_y_b = muSingleScalarIsInf(c4_t_x);
            if (c4_y_b && ((c4_p_a > 0.0F) == (c4_n_b > 0.0F))) {
              c4_p = true;
            } else {
              c4_p = false;
            }
          } else {
            c4_p = false;
          }
        }

        c4_b_p = c4_p;
        if (!c4_b_p) {
          c4_exitg2 = 1;
        }
      }
    } while (c4_exitg2 == 0);

    c4_q_a = c4_nb + 1;
    c4_nb = c4_q_a;
    c4_b->data[c4_nb] = c4_e_x;
    c4_r_a = c4_b_k - 1;
    c4_i5 = c4_r_a;
    c4_st.site = &c4_ge_emlrtRSI;
    c4_s_a = c4_k0;
    c4_p_b = c4_i5;
    c4_u_a = c4_s_a;
    c4_q_b = c4_p_b;
    if (c4_u_a > c4_q_b) {
      c4_c_overflow = false;
    } else {
      c4_c_overflow = (c4_q_b > 2147483646);
    }

    if (c4_c_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }
  }

  if (c4_nInf > 0) {
    c4_l_a = c4_nb + 1;
    c4_nb = c4_l_a;
    c4_n_a = c4_khi + 1;
    c4_b_c = c4_n_a - 1;
    c4_b->data[c4_nb] = c4_b->data[c4_b_c];
    c4_st.site = &c4_fe_emlrtRSI;
    c4_l_b = c4_nInf;
    c4_m_b = c4_l_b;
    if (1 > c4_m_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_m_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }
  }

  c4_m_a = c4_khi;
  c4_i_b = c4_nInf;
  c4_b_k = c4_m_a + c4_i_b;
  c4_st.site = &c4_ee_emlrtRSI;
  c4_j_b = c4_nNaN;
  c4_k_b = c4_j_b;
  if (1 > c4_k_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_k_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  for (c4_j = 1; c4_j - 1 < c4_nNaN; c4_j++) {
    c4_b_j = c4_j;
    c4_t_a = c4_nb + 1;
    c4_nb = c4_t_a;
    c4_v_a = c4_b_k;
    c4_r_b = c4_b_j;
    c4_c_c = (c4_v_a + c4_r_b) - 1;
    c4_b->data[c4_nb] = c4_b->data[c4_c_c];
  }

  c4_o_b = (1 > c4_nb + 1);
  if (c4_o_b) {
    c4_i6 = 0;
  } else {
    c4_i6 = c4_nb + 1;
  }

  c4_iv[0] = 1;
  c4_iv[1] = c4_i6;
  c4_st.site = &c4_de_emlrtRSI;
  c4_indexShapeCheck(chartInstance, &c4_st, 19200, c4_iv);
  c4_i7 = c4_b->size[0];
  c4_b->size[0] = c4_i6;
  c4_st.site = &c4_de_emlrtRSI;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b, c4_i7,
    &c4_hd_emlrtRTEI);
  c4_st.site = &c4_ce_emlrtRSI;
  c4_t_b = c4_nb + 1;
  c4_v_b = c4_t_b;
  if (1 > c4_v_b) {
    c4_d_overflow = false;
  } else {
    c4_d_overflow = (c4_v_b > 2147483646);
  }

  if (c4_d_overflow) {
    c4_b_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }
}

static void c4_indexShapeCheck(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, int32_T c4_matrixSize, int32_T
  c4_indexSize[2])
{
  static char_T c4_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_size1;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_c;
  boolean_T c4_c;
  boolean_T c4_nonSingletonDimFound;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_size1 = c4_matrixSize;
  if (c4_size1 != 1) {
    c4_b = false;
  } else {
    c4_b = true;
  }

  if (c4_b) {
    c4_nonSingletonDimFound = false;
    if (c4_indexSize[1] != 1) {
      c4_nonSingletonDimFound = true;
    }

    c4_b_b = c4_nonSingletonDimFound;
    if (c4_b_b) {
      c4_c = true;
    } else {
      c4_c = false;
    }
  } else {
    c4_c = false;
  }

  c4_st.site = &c4_ke_emlrtRSI;
  c4_b_c = c4_c;
  if (c4_b_c) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_f_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }
}

static void c4_nullAssignment(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_c_x,
  boolean_T c4_idx_data[], int32_T c4_idx_size[2], c4_emxArray_real32_T *c4_d_x)
{
  int32_T c4_b_idx_size[2];
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_loop_ub;
  boolean_T c4_b_idx_data[19200];
  c4_i = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = 1;
  c4_d_x->size[1] = c4_c_x->size[1];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_d_x, c4_i,
    &c4_id_emlrtRTEI);
  c4_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x->data[c4_i1];
  }

  c4_b_idx_size[0] = 1;
  c4_b_idx_size[1] = c4_idx_size[1];
  c4_b_loop_ub = c4_idx_size[0] * c4_idx_size[1] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
    c4_b_idx_data[c4_i2] = c4_idx_data[c4_i2];
  }

  c4_b_nullAssignment(chartInstance, c4_sp, c4_d_x, c4_b_idx_data, c4_b_idx_size);
}

static void c4_c_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp)
{
  static char_T c4_msgID[32] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'm', 'u',
    'l', 't', 'i', 't', 'h', 'r', 'e', 's', 'h', ':', 'n', 'o', 'C', 'o', 'n',
    'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  static char_T c4_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1U, 0U, 2, 1, 32),
                false);
  c4_st.site = &c4_r_emlrtRSI;
  c4_f_feval(chartInstance, &c4_st, c4_y, c4_e_feval(chartInstance, &c4_st,
              c4_b_y, c4_c_y));
}

static void c4_abs(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x,
                   c4_emxArray_real_T *c4_y)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_b_dv[2];
  real_T c4_b_y;
  real_T c4_d_x;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_i;
  int32_T c4_k;
  int32_T c4_nx;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_te_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_nx = c4_c_x->size[0];
  c4_b_dv[0] = (real_T)c4_c_x->size[0];
  c4_i = c4_y->size[0];
  c4_y->size[0] = (int32_T)c4_b_dv[0];
  c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_y, c4_i,
    &c4_jd_emlrtRTEI);
  c4_b_st.site = &c4_ue_emlrtRSI;
  c4_b = c4_nx;
  c4_b_b = c4_b;
  if (1 > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  for (c4_k = 1; c4_k - 1 < c4_nx; c4_k++) {
    c4_b_k = c4_k - 1;
    c4_d_x = c4_c_x->data[c4_b_k];
    c4_b_y = muDoubleScalarAbs(c4_d_x);
    c4_y->data[c4_b_k] = c4_b_y;
  }
}

static real_T c4_eps(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     real_T c4_c_x)
{
  real_T c4_absx;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_r;
  int32_T c4_b_exponent;
  int32_T c4_exponent;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b_b;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  (void)chartInstance;
  c4_d_x = c4_c_x;
  c4_e_x = c4_d_x;
  c4_f_x = c4_e_x;
  c4_g_x = c4_f_x;
  c4_absx = muDoubleScalarAbs(c4_g_x);
  c4_h_x = c4_absx;
  c4_i_x = c4_h_x;
  c4_b = muDoubleScalarIsInf(c4_i_x);
  c4_b_b = !c4_b;
  c4_j_x = c4_h_x;
  c4_c_b = muDoubleScalarIsNaN(c4_j_x);
  c4_b1 = !c4_c_b;
  c4_d_b = (c4_b_b && c4_b1);
  if (c4_d_b) {
    if (c4_absx <= 2.2250738585072014E-308) {
      c4_r = 4.94065645841247E-324;
    } else {
      frexp(c4_absx, &c4_exponent);
      c4_b_exponent = c4_exponent;
      c4_r = ldexp(1.0, c4_b_exponent - 53);
    }
  } else {
    c4_r = rtNaN;
  }

  return c4_r;
}

static boolean_T c4_any(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_b_x_data[], int32_T c4_x_size[1])
{
  static char_T c4_b_cv[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  real_T c4_g_a;
  real_T c4_vlen;
  int32_T c4_b_b;
  int32_T c4_c;
  int32_T c4_c_b;
  int32_T c4_d_b;
  int32_T c4_h_a;
  int32_T c4_i2;
  int32_T c4_i_a;
  int32_T c4_ix;
  int32_T c4_vspread;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_y;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_st.site = &c4_ve_emlrtRSI;
  if ((c4_x_size[0] == 1) || ((real_T)c4_x_size[0] != 1.0)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c4_st, &c4_i_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_y = false;
  c4_vlen = (real_T)c4_x_size[0];
  c4_g_a = c4_vlen;
  c4_c = (int32_T)c4_g_a;
  c4_h_a = c4_c - 1;
  c4_vspread = c4_h_a;
  c4_b_b = c4_vspread;
  c4_i2 = c4_b_b;
  c4_i_a = c4_i2 + 1;
  c4_i2 = c4_i_a;
  c4_b_st.site = &c4_we_emlrtRSI;
  c4_c_b = c4_i2;
  c4_d_b = c4_c_b;
  if (1 > c4_d_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_d_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  c4_ix = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_ix + 1 <= c4_i2)) {
    if (!c4_b_x_data[c4_ix]) {
      c4_b1 = true;
    } else {
      c4_b1 = false;
    }

    if (!c4_b1) {
      c4_y = true;
      c4_exitg1 = true;
    } else {
      c4_ix++;
    }
  }

  return c4_y;
}

static void c4_sort(SFc4_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c4_sp, c4_emxArray_real32_T *c4_c_x,
                    c4_emxArray_real32_T *c4_d_x)
{
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_i = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = 1;
  c4_d_x->size[1] = c4_c_x->size[1];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_d_x, c4_i,
    &c4_kd_emlrtRTEI);
  c4_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x->data[c4_i1];
  }

  c4_c_sort(chartInstance, c4_sp, c4_d_x);
}

static void c4_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_c_x, int32_T c4_offset, c4_emxArray_int32_T *c4_c_idx,
  c4_emxArray_real32_T *c4_d_x)
{
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  c4_i = c4_c_idx->size[0] * c4_c_idx->size[1];
  c4_c_idx->size[0] = 1;
  c4_c_idx->size[1] = c4_b_idx->size[1];
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_c_idx, c4_i,
    &c4_ld_emlrtRTEI);
  c4_loop_ub = c4_b_idx->size[0] * c4_b_idx->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_c_idx->data[c4_i1] = c4_b_idx->data[c4_i1];
  }

  c4_i2 = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = 1;
  c4_d_x->size[1] = c4_c_x->size[1];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_d_x, c4_i2,
    &c4_ld_emlrtRTEI);
  c4_b_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_d_x->data[c4_i3] = c4_c_x->data[c4_i3];
  }

  c4_c_merge_pow2_block(chartInstance, c4_sp, c4_c_idx, c4_d_x, c4_offset);
}

static void c4_merge_block(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real32_T
  *c4_c_x, int32_T c4_offset, int32_T c4_n, int32_T c4_preSortLevel,
  c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T *c4_xwork,
  c4_emxArray_int32_T *c4_c_idx, c4_emxArray_real32_T *c4_d_x,
  c4_emxArray_int32_T *c4_c_iwork, c4_emxArray_real32_T *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_loop_ub;
  c4_i = c4_c_idx->size[0] * c4_c_idx->size[1];
  c4_c_idx->size[0] = 1;
  c4_c_idx->size[1] = c4_b_idx->size[1];
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_c_idx, c4_i,
    &c4_md_emlrtRTEI);
  c4_loop_ub = c4_b_idx->size[0] * c4_b_idx->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_c_idx->data[c4_i1] = c4_b_idx->data[c4_i1];
  }

  c4_i2 = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = 1;
  c4_d_x->size[1] = c4_c_x->size[1];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_d_x, c4_i2,
    &c4_md_emlrtRTEI);
  c4_b_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_d_x->data[c4_i3] = c4_c_x->data[c4_i3];
  }

  c4_i4 = c4_c_iwork->size[0];
  c4_c_iwork->size[0] = c4_b_iwork->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_c_iwork, c4_i4,
    &c4_md_emlrtRTEI);
  c4_c_loop_ub = c4_b_iwork->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_c_iwork->data[c4_i5] = c4_b_iwork->data[c4_i5];
  }

  c4_i6 = c4_b_xwork->size[0];
  c4_b_xwork->size[0] = c4_xwork->size[0];
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_b_xwork, c4_i6,
    &c4_md_emlrtRTEI);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b_xwork->data[c4_i7] = c4_xwork->data[c4_i7];
  }

  c4_c_merge_block(chartInstance, c4_sp, c4_c_idx, c4_d_x, c4_offset, c4_n,
                   c4_preSortLevel, c4_c_iwork, c4_b_xwork);
}

static void c4_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
                     c4_emxArray_real32_T *c4_c_x, int32_T c4_offset, int32_T
                     c4_np, int32_T c4_nq, c4_emxArray_int32_T *c4_b_iwork,
                     c4_emxArray_real32_T *c4_xwork, c4_emxArray_int32_T
                     *c4_c_idx, c4_emxArray_real32_T *c4_d_x,
                     c4_emxArray_int32_T *c4_c_iwork, c4_emxArray_real32_T
                     *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_loop_ub;
  c4_i = c4_c_idx->size[0] * c4_c_idx->size[1];
  c4_c_idx->size[0] = 1;
  c4_c_idx->size[1] = c4_b_idx->size[1];
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_c_idx, c4_i,
    &c4_nd_emlrtRTEI);
  c4_loop_ub = c4_b_idx->size[0] * c4_b_idx->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_c_idx->data[c4_i1] = c4_b_idx->data[c4_i1];
  }

  c4_i2 = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = 1;
  c4_d_x->size[1] = c4_c_x->size[1];
  c4_emxEnsureCapacity_real32_T1(chartInstance, c4_sp, c4_d_x, c4_i2,
    &c4_nd_emlrtRTEI);
  c4_b_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_d_x->data[c4_i3] = c4_c_x->data[c4_i3];
  }

  c4_i4 = c4_c_iwork->size[0];
  c4_c_iwork->size[0] = c4_b_iwork->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_c_iwork, c4_i4,
    &c4_nd_emlrtRTEI);
  c4_c_loop_ub = c4_b_iwork->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_c_iwork->data[c4_i5] = c4_b_iwork->data[c4_i5];
  }

  c4_i6 = c4_b_xwork->size[0];
  c4_b_xwork->size[0] = c4_xwork->size[0];
  c4_emxEnsureCapacity_real32_T(chartInstance, c4_sp, c4_b_xwork, c4_i6,
    &c4_nd_emlrtRTEI);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b_xwork->data[c4_i7] = c4_xwork->data[c4_i7];
  }

  c4_c_merge(chartInstance, c4_sp, c4_c_idx, c4_d_x, c4_offset, c4_np, c4_nq,
             c4_c_iwork, c4_b_xwork);
}

static void c4_eml_find(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_c_x[19200], c4_emxArray_int32_T *c4_i,
  c4_emxArray_int32_T *c4_j)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_iv[2];
  int32_T c4_iv1[2];
  int32_T c4_iv2[2];
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_ii;
  int32_T c4_jj;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_exitg1;
  boolean_T c4_guard1 = false;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_tf_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_b_idx = 0;
  c4_b_i = c4_i->size[0];
  c4_i->size[0] = 19200;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_i, c4_b_i,
    &c4_od_emlrtRTEI);
  c4_i1 = c4_j->size[0];
  c4_j->size[0] = 19200;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_j, c4_i1,
    &c4_pd_emlrtRTEI);
  c4_ii = 1;
  c4_jj = 1;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_jj <= 160)) {
    c4_guard1 = false;
    if (c4_c_x[(c4_ii + 120 * (c4_jj - 1)) - 1]) {
      c4_b_idx++;
      c4_i->data[c4_b_idx - 1] = c4_ii;
      c4_j->data[c4_b_idx - 1] = c4_jj;
      if (c4_b_idx >= 19200) {
        c4_exitg1 = true;
      } else {
        c4_guard1 = true;
      }
    } else {
      c4_guard1 = true;
    }

    if (c4_guard1) {
      c4_ii++;
      if (c4_ii > 120) {
        c4_ii = 1;
        c4_jj++;
      }
    }
  }

  c4_b = (1 > c4_b_idx);
  if (c4_b) {
    c4_i2 = 0;
  } else {
    c4_i2 = c4_b_idx;
  }

  c4_iv[0] = 1;
  c4_iv[1] = c4_i2;
  c4_b_st.site = &c4_wf_emlrtRSI;
  c4_indexShapeCheck(chartInstance, &c4_b_st, 19200, c4_iv);
  c4_i3 = c4_i->size[0];
  c4_i->size[0] = c4_i2;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_i, c4_i3,
    &c4_qd_emlrtRTEI);
  c4_b1 = (1 > c4_b_idx);
  if (c4_b1) {
    c4_i4 = 0;
  } else {
    c4_i4 = c4_b_idx;
  }

  c4_iv1[0] = 1;
  c4_iv1[1] = c4_i4;
  c4_b_st.site = &c4_vf_emlrtRSI;
  c4_indexShapeCheck(chartInstance, &c4_b_st, 19200, c4_iv1);
  c4_i5 = c4_j->size[0];
  c4_j->size[0] = c4_i4;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_j, c4_i5,
    &c4_rd_emlrtRTEI);
  c4_b2 = (1 > c4_b_idx);
  if (c4_b2) {
    c4_i6 = 0;
  } else {
    c4_i6 = c4_b_idx;
  }

  c4_iv2[0] = 1;
  c4_iv2[1] = c4_i6;
  c4_b_st.site = &c4_uf_emlrtRSI;
  c4_indexShapeCheck(chartInstance, &c4_b_st, 19200, c4_iv2);
}

static boolean_T c4_allinrange(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T *c4_c_x, int32_T c4_hi)
{
  real_T c4_b_k;
  real_T c4_d;
  int32_T c4_exitg1;
  int32_T c4_i;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_p;
  (void)chartInstance;
  c4_d = (real_T)c4_c_x->size[0];
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  do {
    c4_exitg1 = 0;
    if (c4_k <= c4_i) {
      c4_b_k = (real_T)c4_k + 1.0;
      if ((c4_c_x->data[(int32_T)c4_b_k - 1] >= 1.0) && (c4_c_x->data[(int32_T)
           c4_b_k - 1] <= (real_T)c4_hi)) {
        c4_b = true;
      } else {
        c4_b = false;
      }

      if (!c4_b) {
        c4_p = false;
        c4_exitg1 = 1;
      } else {
        c4_k++;
      }
    } else {
      c4_p = true;
      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  return c4_p;
}

static void c4_eml_sub2ind(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real_T *c4_d_varargin_1,
  c4_emxArray_real_T *c4_b_varargin_2, c4_emxArray_int32_T *c4_b_idx)
{
  static char_T c4_b_cv1[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't',
    'V', 'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  static char_T c4_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  c4_emxArray_int32_T *c4_b;
  c4_emxArray_real_T *c4_d_varargin_2;
  c4_emxArray_real_T *c4_e_varargin_1;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_c_varargin_2[2];
  real_T c4_f_varargin_1[2];
  real_T c4_b_k;
  real_T c4_x1;
  real_T c4_x2;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_e_loop_ub;
  int32_T c4_f_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_k;
  int32_T c4_loop_ub;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_e_varargin_1, 1, &c4_sd_emlrtRTEI);
  c4_i = c4_e_varargin_1->size[0];
  c4_e_varargin_1->size[0] = c4_d_varargin_1->size[0];
  c4_st.site = &c4_ml_emlrtRSI;
  c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_e_varargin_1, c4_i,
    &c4_sd_emlrtRTEI);
  c4_loop_ub = c4_d_varargin_1->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_e_varargin_1->data[c4_i1] = c4_d_varargin_1->data[c4_i1];
  }

  if (!c4_allinrange(chartInstance, c4_e_varargin_1, 120)) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c4_sp, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }

  c4_emxFree_real_T(chartInstance, &c4_e_varargin_1);
  c4_f_varargin_1[0] = (real_T)c4_d_varargin_1->size[0];
  c4_f_varargin_1[1] = 1.0;
  c4_c_varargin_2[0] = (real_T)c4_b_varargin_2->size[0];
  c4_c_varargin_2[1] = 1.0;
  c4_p = false;
  c4_b_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 2)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x1 = c4_f_varargin_1[(int32_T)c4_b_k - 1];
    c4_x2 = c4_c_varargin_2[(int32_T)c4_b_k - 1];
    c4_c_p = (c4_x1 == c4_x2);
    if (!c4_c_p) {
      c4_b_p = false;
      c4_exitg1 = true;
    } else {
      c4_k++;
    }
  }

  if (c4_b_p) {
    c4_p = true;
  }

  if (!c4_p) {
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    sf_mex_call(c4_sp, &c4_k_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_d_y)));
  }

  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_d_varargin_2, 1, &c4_sd_emlrtRTEI);
  c4_i2 = c4_d_varargin_2->size[0];
  c4_d_varargin_2->size[0] = c4_b_varargin_2->size[0];
  c4_st.site = &c4_ml_emlrtRSI;
  c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_d_varargin_2, c4_i2,
    &c4_sd_emlrtRTEI);
  c4_b_loop_ub = c4_b_varargin_2->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_d_varargin_2->data[c4_i3] = c4_b_varargin_2->data[c4_i3];
  }

  if (!c4_allinrange(chartInstance, c4_d_varargin_2, 160)) {
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c4_sp, &c4_j_emlrtMCI, "error", 0U, 2U, 14, c4_e_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_f_y)));
  }

  c4_emxFree_real_T(chartInstance, &c4_d_varargin_2);
  c4_i4 = c4_b_idx->size[0];
  c4_b_idx->size[0] = c4_d_varargin_1->size[0];
  c4_st.site = &c4_il_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_b_idx, c4_i4,
    &c4_td_emlrtRTEI);
  c4_c_loop_ub = c4_d_varargin_1->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_b_idx->data[c4_i5] = (int32_T)c4_d_varargin_1->data[c4_i5];
  }

  c4_emxInit_int32_T(chartInstance, c4_sp, &c4_b, 1, &c4_ud_emlrtRTEI);
  c4_i6 = c4_b->size[0];
  c4_b->size[0] = c4_b_varargin_2->size[0];
  c4_st.site = &c4_hl_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_b, c4_i6,
    &c4_ud_emlrtRTEI);
  c4_d_loop_ub = c4_b_varargin_2->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b->data[c4_i7] = (int32_T)c4_b_varargin_2->data[c4_i7] - 1;
  }

  c4_i8 = c4_b->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b, c4_i8,
    &c4_vd_emlrtRTEI);
  c4_e_loop_ub = c4_b->size[0] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_e_loop_ub; c4_i9++) {
    c4_b->data[c4_i9] *= 120;
  }

  c4_i10 = c4_b_idx->size[0];
  c4_st.site = &c4_hl_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_b_idx, c4_i10,
    &c4_wd_emlrtRTEI);
  c4_f_loop_ub = c4_b_idx->size[0] - 1;
  for (c4_i11 = 0; c4_i11 <= c4_f_loop_ub; c4_i11++) {
    c4_b_idx->data[c4_i11] += c4_b->data[c4_i11];
  }

  c4_emxFree_int32_T(chartInstance, &c4_b);
}

static void c4_medfilt2(SFc4_flightControlSystemInstanceStruct *chartInstance,
  real_T c4_d_varargin_1[19200], real_T c4_b[19200])
{
  static int32_T c4_offsets[25] = { -250, -249, -248, -247, -246, -126, -125,
    -124, -123, -122, -2, -1, 0, 1, 2, 122, 123, 124, 125, 126, 246, 247, 248,
    249, 250 };

  real_T c4_domainSizeT[2];
  real_T c4_sizeB[2];
  real_T c4_startIdxT[2];
  real_T c4_c_i;
  real_T c4_c_j;
  real_T c4_g_a;
  real_T c4_h_a;
  real_T c4_i_a;
  real_T c4_j_a;
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_b_j;
  int32_T c4_c;
  int32_T c4_c_c;
  int32_T c4_d_c;
  int32_T c4_d_i;
  int32_T c4_d_j;
  int32_T c4_e_i;
  int32_T c4_e_j;
  int32_T c4_f_i;
  int32_T c4_f_j;
  int32_T c4_g_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_j;
  for (c4_j = 0; c4_j < 2; c4_j++) {
    c4_c_j = (real_T)c4_j + 1.0;
    for (c4_i = 0; c4_i < 124; c4_i++) {
      c4_c_i = (real_T)c4_i + 1.0;
      chartInstance->c4_Apad[((int32_T)c4_c_i + 124 * ((int32_T)c4_c_j - 1)) - 1]
        = 0.0;
    }
  }

  for (c4_b_j = 0; c4_b_j < 2; c4_b_j++) {
    for (c4_b_i = 0; c4_b_i < 124; c4_b_i++) {
      c4_c_i = (real_T)c4_b_i + 1.0;
      chartInstance->c4_Apad[((int32_T)c4_c_i + 124 * (c4_b_j + 162)) - 1] = 0.0;
    }
  }

  for (c4_d_j = 0; c4_d_j < 160; c4_d_j++) {
    c4_c_j = (real_T)c4_d_j + 1.0;
    for (c4_d_i = 0; c4_d_i < 2; c4_d_i++) {
      c4_c_i = (real_T)c4_d_i + 1.0;
      c4_g_a = c4_c_j;
      c4_c = (int32_T)c4_g_a;
      chartInstance->c4_Apad[((int32_T)c4_c_i + 124 * (c4_c + 1)) - 1] = 0.0;
    }
  }

  for (c4_e_j = 0; c4_e_j < 160; c4_e_j++) {
    c4_c_j = (real_T)c4_e_j + 1.0;
    for (c4_e_i = 0; c4_e_i < 2; c4_e_i++) {
      c4_h_a = c4_c_j;
      c4_b_c = (int32_T)c4_h_a;
      chartInstance->c4_Apad[(c4_e_i + 124 * (c4_b_c + 1)) + 122] = 0.0;
    }
  }

  for (c4_f_j = 0; c4_f_j < 160; c4_f_j++) {
    c4_c_j = (real_T)c4_f_j + 1.0;
    for (c4_g_i = 0; c4_g_i < 120; c4_g_i++) {
      c4_c_i = (real_T)c4_g_i + 1.0;
      c4_i_a = c4_c_i;
      c4_c_c = (int32_T)c4_i_a;
      c4_j_a = c4_c_j;
      c4_d_c = (int32_T)c4_j_a;
      chartInstance->c4_Apad[(c4_c_c + 124 * (c4_d_c + 1)) + 1] =
        c4_d_varargin_1[((int32_T)c4_c_i + 120 * ((int32_T)c4_c_j - 1)) - 1];
    }
  }

  for (c4_f_i = 0; c4_f_i < 2; c4_f_i++) {
    c4_domainSizeT[c4_f_i] = 5.0;
  }

  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_startIdxT[c4_i1] = 2.0;
  }

  for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
    c4_sizeB[c4_i2] = 120.0 + 40.0 * (real_T)c4_i2;
  }

  ordfilt2_real64(&chartInstance->c4_Apad[0], 124.0, &c4_startIdxT[0],
                  &c4_offsets[0], 25.0, &c4_domainSizeT[0], 12.0, &c4_b[0],
                  &c4_sizeB[0], true);
}

static void c4_chcenters(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, creal_T c4_d_varargin_1[19200], c4_emxArray_real_T
  *c4_centers, c4_emxArray_real_T *c4_metric)
{
  c4_emxArray_int32_T *c4_iidx;
  c4_emxArray_int32_T *c4_r;
  c4_emxArray_real_T *c4_b_centers;
  c4_emxArray_real_T *c4_b_varargin_2;
  c4_emxArray_real_T *c4_d_x;
  c4_emxArray_real_T *c4_e_x;
  c4_emxArray_real_T *c4_j_x;
  c4_emxArray_real_T *c4_ndx;
  c4_emxArray_real_T *c4_sortIdx;
  c4_emxArray_sBO2RC5RVZVTbundPSRqHn *c4_b_s;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  creal_T c4_c_x;
  real_T c4_b;
  real_T c4_c_accumMatrixRe;
  real_T c4_c_idx;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d_k;
  real_T c4_f_x;
  real_T c4_g_a;
  real_T c4_g_x;
  real_T c4_x1;
  real_T c4_x2;
  real_T c4_y;
  int32_T c4_iv[2];
  int32_T c4_iv1[2];
  int32_T c4_tmp_data[2];
  int32_T c4_b_sortIdx[1];
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_c_centers;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_d_idx;
  int32_T c4_d_loop_ub;
  int32_T c4_e_b;
  int32_T c4_e_idx;
  int32_T c4_e_loop_ub;
  int32_T c4_f_b;
  int32_T c4_f_idx;
  int32_T c4_f_loop_ub;
  int32_T c4_g_idx;
  int32_T c4_g_loop_ub;
  int32_T c4_h_a;
  int32_T c4_h_idx;
  int32_T c4_h_loop_ub;
  int32_T c4_h_x;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_a;
  int32_T c4_i_loop_ub;
  int32_T c4_i_x;
  int32_T c4_j;
  int32_T c4_j_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n;
  int32_T c4_n_loop_ub;
  int32_T c4_nrows;
  int32_T c4_nrowx;
  boolean_T c4_b_x_data[19200];
  boolean_T c4_bw[19200];
  boolean_T c4_b1;
  boolean_T c4_b_b;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_exitg1;
  boolean_T c4_flat;
  boolean_T c4_guard1 = false;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_centers->size[0] = 0;
  c4_centers->size[1] = 0;
  c4_metric->size[0] = 0;
  c4_metric->size[1] = 0;
  for (c4_k = 0; c4_k < 19200; c4_k++) {
    c4_b_k = c4_k;
    c4_c_x = c4_d_varargin_1[c4_b_k];
    c4_x1 = c4_c_x.re;
    c4_x2 = c4_c_x.im;
    c4_g_a = c4_x1;
    c4_b = c4_x2;
    c4_y = muDoubleScalarHypot(c4_g_a, c4_b);
    chartInstance->c4_accumMatrixRe[c4_b_k] = c4_y;
  }

  c4_c_accumMatrixRe = chartInstance->c4_accumMatrixRe[0];
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_bw[c4_i] = (chartInstance->c4_accumMatrixRe[c4_i] == c4_c_accumMatrixRe);
  }

  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_b_x_data[c4_i1] = c4_bw[c4_i1];
  }

  c4_flat = true;
  c4_c_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_k < 19200)) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    if (!c4_b_x_data[(int32_T)c4_d_k - 1]) {
      c4_flat = false;
      c4_exitg1 = true;
    } else {
      c4_c_k++;
    }
  }

  if (!c4_flat) {
    c4_emxInit_sBO2RC5RVZVTbundPSRqHnH(chartInstance, c4_sp, &c4_b_s, 1,
      &c4_me_emlrtRTEI);
    c4_st.site = &c4_hg_emlrtRSI;
    for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
      chartInstance->c4_b_accumMatrixRe[c4_i2] = chartInstance->
        c4_accumMatrixRe[c4_i2];
    }

    c4_medfilt2(chartInstance, chartInstance->c4_b_accumMatrixRe,
                chartInstance->c4_Hd);
    c4_st.site = &c4_ig_emlrtRSI;
    for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
      chartInstance->c4_b_Hd[c4_i3] = chartInstance->c4_Hd[c4_i3];
    }

    c4_imhmax(chartInstance, &c4_st, chartInstance->c4_b_Hd,
              chartInstance->c4_Hd);
    c4_st.site = &c4_jg_emlrtRSI;
    for (c4_i4 = 0; c4_i4 < 19200; c4_i4++) {
      chartInstance->c4_c_Hd[c4_i4] = chartInstance->c4_Hd[c4_i4];
    }

    c4_imregionalmax(chartInstance, &c4_st, chartInstance->c4_c_Hd, c4_bw);
    c4_st.site = &c4_kg_emlrtRSI;
    c4_regionprops(chartInstance, &c4_st, c4_bw, chartInstance->c4_accumMatrixRe,
                   c4_b_s);
    if (c4_b_s->size[0] != 0) {
      c4_i5 = c4_centers->size[0] * c4_centers->size[1];
      c4_centers->size[0] = c4_b_s->size[0];
      c4_centers->size[1] = 2;
      c4_st.site = &c4_xk_emlrtRSI;
      c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_centers, c4_i5,
        &c4_xd_emlrtRTEI);
      c4_d = (real_T)c4_b_s->size[0];
      c4_i6 = (int32_T)c4_d - 1;
      for (c4_b_idx = 0; c4_b_idx <= c4_i6; c4_b_idx++) {
        c4_c_idx = (real_T)c4_b_idx + 1.0;
        c4_i8 = c4_centers->size[0];
        c4_i9 = (int32_T)c4_c_idx;
        c4_i10 = emlrtDynamicBoundsCheckR2012b(c4_i9, 1, c4_i8, &c4_oc_emlrtBCI,
          c4_sp);
        for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
          c4_tmp_data[c4_i11] = c4_i11;
        }

        for (c4_i12 = 0; c4_i12 < 2; c4_i12++) {
          c4_iv[c4_i12] = 1 + c4_i12;
        }

        for (c4_i13 = 0; c4_i13 < 2; c4_i13++) {
          c4_iv1[c4_i13] = 1 + c4_i13;
        }

        emlrtSubAssignSizeCheckR2012b(c4_iv, 2, c4_iv1, 2, &c4_b_emlrtECI, c4_sp);
        c4_i16 = c4_i10 - 1;
        for (c4_i17 = 0; c4_i17 < 2; c4_i17++) {
          c4_i19 = c4_b_s->size[0];
          c4_i22 = (int32_T)c4_c_idx;
          c4_centers->data[c4_i16 + c4_centers->size[0] * c4_tmp_data[c4_i17]] =
            c4_b_s->data[emlrtDynamicBoundsCheckR2012b(c4_i22, 1, c4_i19,
            &c4_qc_emlrtBCI, c4_sp) - 1].WeightedCentroid[c4_i17];
        }
      }

      c4_d1 = (real_T)c4_centers->size[0];
      c4_i7 = (int32_T)(((-1.0 - c4_d1) + 1.0) / -1.0);
      emlrtForLoopVectorCheckR2012b(c4_d1, -1.0, 1.0, mxDOUBLE_CLASS, c4_i7,
        &c4_xi_emlrtRTEI, c4_sp);
      c4_d_idx = 0;
      c4_emxInit_real_T(chartInstance, c4_sp, &c4_d_x, 2, &c4_be_emlrtRTEI);
      c4_emxInit_real_T(chartInstance, c4_sp, &c4_e_x, 2, &c4_ge_emlrtRTEI);
      while (c4_d_idx <= c4_i7 - 1) {
        c4_c_idx = c4_d1 + -(real_T)c4_d_idx;
        c4_i14 = c4_centers->size[0];
        c4_i15 = (int32_T)c4_c_idx;
        c4_f_x = c4_centers->data[emlrtDynamicBoundsCheckR2012b(c4_i15, 1,
          c4_i14, &c4_pc_emlrtBCI, c4_sp) - 1];
        c4_c_b = muDoubleScalarIsNaN(c4_f_x);
        c4_guard1 = false;
        if (c4_c_b) {
          c4_guard1 = true;
        } else {
          c4_i21 = c4_centers->size[0];
          c4_i23 = (int32_T)c4_c_idx;
          c4_g_x = c4_centers->data[(emlrtDynamicBoundsCheckR2012b(c4_i23, 1,
            c4_i21, &c4_rc_emlrtBCI, c4_sp) + c4_centers->size[0]) - 1];
          c4_d_b = muDoubleScalarIsNaN(c4_g_x);
          if (c4_d_b) {
            c4_guard1 = true;
          }
        }

        if (c4_guard1) {
          c4_st.site = &c4_lg_emlrtRSI;
          c4_i24 = c4_d_x->size[0] * c4_d_x->size[1];
          c4_d_x->size[0] = c4_centers->size[0];
          c4_d_x->size[1] = c4_centers->size[1];
          c4_b_st.site = &c4_lg_emlrtRSI;
          c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_d_x, c4_i24,
            &c4_be_emlrtRTEI);
          c4_b_loop_ub = c4_centers->size[0] * c4_centers->size[1] - 1;
          for (c4_i27 = 0; c4_i27 <= c4_b_loop_ub; c4_i27++) {
            c4_d_x->data[c4_i27] = c4_centers->data[c4_i27];
          }

          c4_e_idx = (int32_T)c4_c_idx;
          c4_b_st.site = &c4_ni_emlrtRSI;
          c4_f_idx = c4_e_idx;
          c4_g_idx = c4_f_idx;
          c4_d2 = (real_T)c4_d_x->size[0];
          c4_n = (int32_T)c4_d2;
          c4_p = true;
          if (c4_g_idx > c4_n) {
            c4_p = false;
          } else {
            c4_h_x = c4_g_idx;
            c4_i_x = c4_h_x;
            if (c4_g_idx != c4_i_x) {
              c4_p = false;
            }
          }

          if (!c4_p) {
            c4_b_y = NULL;
            sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2,
              1, 25), false);
            c4_c_y = NULL;
            sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2,
              1, 25), false);
            sf_mex_call(&c4_b_st, &c4_u_emlrtMCI, "error", 0U, 2U, 14, c4_b_y,
                        14, sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c4_b_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
          }

          c4_b_st.site = &c4_oi_emlrtRSI;
          c4_h_idx = c4_e_idx;
          c4_nrowx = c4_d_x->size[0];
          c4_nrows = c4_nrowx - 1;
          c4_c_st.site = &c4_pi_emlrtRSI;
          for (c4_j = 0; c4_j < 2; c4_j++) {
            c4_b_j = c4_j;
            c4_c_st.site = &c4_qi_emlrtRSI;
            c4_h_a = c4_h_idx;
            c4_e_b = c4_nrows;
            c4_i_a = c4_h_a;
            c4_f_b = c4_e_b;
            if (c4_i_a > c4_f_b) {
              c4_overflow = false;
            } else {
              c4_overflow = (c4_f_b > 2147483646);
            }

            if (c4_overflow) {
              c4_d_st.site = &c4_mb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
            }

            for (c4_b_i = c4_h_idx; c4_b_i <= c4_nrows; c4_b_i++) {
              c4_d_x->data[(c4_b_i + c4_d_x->size[0] * c4_b_j) - 1] =
                c4_d_x->data[c4_b_i + c4_d_x->size[0] * c4_b_j];
            }
          }

          if (!(c4_nrows <= c4_nrowx)) {
            c4_d_y = NULL;
            sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            c4_e_y = NULL;
            sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            sf_mex_call(&c4_b_st, &c4_v_emlrtMCI, "error", 0U, 2U, 14, c4_d_y,
                        14, sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c4_b_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
          }

          c4_b1 = (1 > c4_nrows);
          if (c4_b1) {
            c4_i34 = -1;
          } else {
            c4_i34 = c4_nrows - 1;
          }

          c4_i36 = c4_e_x->size[0] * c4_e_x->size[1];
          c4_e_x->size[0] = c4_i34 + 1;
          c4_e_x->size[1] = 2;
          c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_e_x, c4_i36,
            &c4_ge_emlrtRTEI);
          for (c4_i38 = 0; c4_i38 < 2; c4_i38++) {
            c4_g_loop_ub = c4_i34;
            for (c4_i41 = 0; c4_i41 <= c4_g_loop_ub; c4_i41++) {
              c4_e_x->data[c4_i41 + c4_e_x->size[0] * c4_i38] = c4_d_x->
                data[c4_i41 + c4_d_x->size[0] * c4_i38];
            }
          }

          c4_i39 = c4_d_x->size[0] * c4_d_x->size[1];
          c4_d_x->size[0] = c4_e_x->size[0];
          c4_d_x->size[1] = 2;
          c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_d_x, c4_i39,
            &c4_ie_emlrtRTEI);
          c4_h_loop_ub = c4_e_x->size[0] * c4_e_x->size[1] - 1;
          for (c4_i42 = 0; c4_i42 <= c4_h_loop_ub; c4_i42++) {
            c4_d_x->data[c4_i42] = c4_e_x->data[c4_i42];
          }

          c4_i44 = c4_centers->size[0] * c4_centers->size[1];
          c4_centers->size[0] = c4_d_x->size[0];
          c4_centers->size[1] = 2;
          c4_st.site = &c4_lg_emlrtRSI;
          c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_centers, c4_i44,
            &c4_be_emlrtRTEI);
          c4_j_loop_ub = c4_d_x->size[0] * c4_d_x->size[1] - 1;
          for (c4_i46 = 0; c4_i46 <= c4_j_loop_ub; c4_i46++) {
            c4_centers->data[c4_i46] = c4_d_x->data[c4_i46];
          }
        }

        c4_d_idx++;
      }

      c4_emxFree_real_T(chartInstance, &c4_e_x);
      c4_emxFree_real_T(chartInstance, &c4_d_x);
      c4_b_b = (c4_centers->size[0] == 0);
      if (!c4_b_b) {
        c4_emxInit_real_T1(chartInstance, c4_sp, &c4_ndx, 1, &c4_oe_emlrtRTEI);
        c4_st.site = &c4_mg_emlrtRSI;
        c4_i18 = c4_centers->size[0] - 1;
        c4_i20 = c4_ndx->size[0];
        c4_ndx->size[0] = c4_i18 + 1;
        c4_b_st.site = &c4_mg_emlrtRSI;
        c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_ndx, c4_i20,
          &c4_ae_emlrtRTEI);
        c4_loop_ub = c4_i18;
        for (c4_i25 = 0; c4_i25 <= c4_loop_ub; c4_i25++) {
          c4_ndx->data[c4_i25] = c4_centers->data[c4_i25 + c4_centers->size[0]];
        }

        c4_emxInit_real_T1(chartInstance, &c4_st, &c4_b_varargin_2, 1,
                           &c4_ce_emlrtRTEI);
        c4_b_st.site = &c4_mg_emlrtRSI;
        c4_b_round(chartInstance, &c4_b_st, c4_ndx);
        c4_i26 = c4_centers->size[0] - 1;
        c4_i28 = c4_b_varargin_2->size[0];
        c4_b_varargin_2->size[0] = c4_i26 + 1;
        c4_b_st.site = &c4_mg_emlrtRSI;
        c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_b_varargin_2,
          c4_i28, &c4_ce_emlrtRTEI);
        c4_c_loop_ub = c4_i26;
        for (c4_i29 = 0; c4_i29 <= c4_c_loop_ub; c4_i29++) {
          c4_b_varargin_2->data[c4_i29] = c4_centers->data[c4_i29];
        }

        c4_emxInit_int32_T(chartInstance, &c4_st, &c4_r, 1, &c4_dc_emlrtRTEI);
        c4_b_st.site = &c4_mg_emlrtRSI;
        c4_b_round(chartInstance, &c4_b_st, c4_b_varargin_2);
        c4_b_st.site = &c4_xf_emlrtRSI;
        c4_eml_sub2ind(chartInstance, &c4_b_st, c4_ndx, c4_b_varargin_2, c4_r);
        c4_i30 = c4_ndx->size[0];
        c4_ndx->size[0] = c4_r->size[0];
        c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_ndx, c4_i30,
          &c4_bb_emlrtRTEI);
        c4_d_loop_ub = c4_r->size[0] - 1;
        for (c4_i31 = 0; c4_i31 <= c4_d_loop_ub; c4_i31++) {
          c4_ndx->data[c4_i31] = (real_T)c4_r->data[c4_i31];
        }

        c4_emxFree_int32_T(chartInstance, &c4_r);
        c4_i32 = c4_b_varargin_2->size[0];
        c4_b_varargin_2->size[0] = c4_ndx->size[0];
        c4_st.site = &c4_mg_emlrtRSI;
        c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_b_varargin_2,
          c4_i32, &c4_de_emlrtRTEI);
        c4_e_loop_ub = c4_ndx->size[0] - 1;
        for (c4_i33 = 0; c4_i33 <= c4_e_loop_ub; c4_i33++) {
          c4_i35 = (int32_T)c4_ndx->data[c4_i33];
          c4_b_varargin_2->data[c4_i33] = chartInstance->
            c4_Hd[emlrtDynamicBoundsCheckR2012b(c4_i35, 1, 19200,
            &c4_sc_emlrtBCI, c4_sp) - 1];
        }

        c4_emxFree_real_T(chartInstance, &c4_ndx);
        c4_i37 = c4_metric->size[0] * c4_metric->size[1];
        c4_metric->size[0] = c4_b_varargin_2->size[0];
        c4_metric->size[1] = 1;
        c4_st.site = &c4_mg_emlrtRSI;
        c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_metric, c4_i37,
          &c4_ee_emlrtRTEI);
        c4_f_loop_ub = c4_b_varargin_2->size[0] - 1;
        for (c4_i40 = 0; c4_i40 <= c4_f_loop_ub; c4_i40++) {
          c4_metric->data[c4_i40] = c4_b_varargin_2->data[c4_i40];
        }

        c4_emxFree_real_T(chartInstance, &c4_b_varargin_2);
        c4_emxInit_real_T(chartInstance, c4_sp, &c4_j_x, 2, &c4_fe_emlrtRTEI);
        c4_st.site = &c4_ng_emlrtRSI;
        c4_i43 = c4_j_x->size[0] * c4_j_x->size[1];
        c4_j_x->size[0] = c4_metric->size[0];
        c4_j_x->size[1] = c4_metric->size[1];
        c4_b_st.site = &c4_ng_emlrtRSI;
        c4_emxEnsureCapacity_real_T(chartInstance, &c4_b_st, c4_j_x, c4_i43,
          &c4_fe_emlrtRTEI);
        c4_i_loop_ub = c4_metric->size[0] * c4_metric->size[1] - 1;
        for (c4_i45 = 0; c4_i45 <= c4_i_loop_ub; c4_i45++) {
          c4_j_x->data[c4_i45] = c4_metric->data[c4_i45];
        }

        c4_emxInit_real_T(chartInstance, &c4_st, &c4_sortIdx, 2,
                          &c4_ne_emlrtRTEI);
        c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_iidx, 2, &c4_ne_emlrtRTEI);
        c4_b_st.site = &c4_ti_emlrtRSI;
        c4_d_sort(chartInstance, &c4_b_st, c4_j_x, c4_iidx);
        c4_i47 = c4_sortIdx->size[0] * c4_sortIdx->size[1];
        c4_sortIdx->size[0] = c4_iidx->size[0];
        c4_sortIdx->size[1] = 1;
        c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_sortIdx, c4_i47,
          &c4_he_emlrtRTEI);
        c4_k_loop_ub = c4_iidx->size[0] * c4_iidx->size[1] - 1;
        for (c4_i48 = 0; c4_i48 <= c4_k_loop_ub; c4_i48++) {
          c4_sortIdx->data[c4_i48] = (real_T)c4_iidx->data[c4_i48];
        }

        c4_emxFree_int32_T(chartInstance, &c4_iidx);
        c4_i49 = c4_metric->size[0] * c4_metric->size[1];
        c4_metric->size[0] = c4_j_x->size[0];
        c4_metric->size[1] = 1;
        c4_st.site = &c4_ng_emlrtRSI;
        c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_metric, c4_i49,
          &c4_je_emlrtRTEI);
        c4_l_loop_ub = c4_j_x->size[0] * c4_j_x->size[1] - 1;
        for (c4_i50 = 0; c4_i50 <= c4_l_loop_ub; c4_i50++) {
          c4_metric->data[c4_i50] = c4_j_x->data[c4_i50];
        }

        c4_emxFree_real_T(chartInstance, &c4_j_x);
        c4_emxInit_real_T(chartInstance, c4_sp, &c4_b_centers, 2,
                          &c4_ke_emlrtRTEI);
        c4_c_centers = c4_centers->size[0];
        c4_b_sortIdx[0] = c4_sortIdx->size[0];
        c4_i51 = c4_b_centers->size[0] * c4_b_centers->size[1];
        c4_b_centers->size[0] = c4_b_sortIdx[0];
        c4_b_centers->size[1] = 2;
        c4_st.site = &c4_wk_emlrtRSI;
        c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_b_centers, c4_i51,
          &c4_ke_emlrtRTEI);
        for (c4_i52 = 0; c4_i52 < 2; c4_i52++) {
          c4_m_loop_ub = c4_b_sortIdx[0] - 1;
          for (c4_i54 = 0; c4_i54 <= c4_m_loop_ub; c4_i54++) {
            c4_i55 = (int32_T)c4_sortIdx->data[c4_i54];
            c4_b_centers->data[c4_i54 + c4_b_centers->size[0] * c4_i52] =
              c4_centers->data[(emlrtDynamicBoundsCheckR2012b(c4_i55, 1,
              c4_c_centers, &c4_tc_emlrtBCI, c4_sp) + c4_centers->size[0] *
                                c4_i52) - 1];
          }
        }

        c4_emxFree_real_T(chartInstance, &c4_sortIdx);
        c4_i53 = c4_centers->size[0] * c4_centers->size[1];
        c4_centers->size[0] = c4_b_centers->size[0];
        c4_centers->size[1] = c4_b_centers->size[1];
        c4_st.site = &c4_wk_emlrtRSI;
        c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_centers, c4_i53,
          &c4_le_emlrtRTEI);
        c4_n_loop_ub = c4_b_centers->size[0] * c4_b_centers->size[1] - 1;
        for (c4_i56 = 0; c4_i56 <= c4_n_loop_ub; c4_i56++) {
          c4_centers->data[c4_i56] = c4_b_centers->data[c4_i56];
        }

        c4_emxFree_real_T(chartInstance, &c4_b_centers);
      }
    }

    c4_emxFree_sBO2RC5RVZVTbundPSRqHnH(chartInstance, &c4_b_s);
  }
}

static void c4_imhmax(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real_T c4_I[19200], real_T
                      c4_b_J[19200])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_b_I[19200];
  real_T c4_imSizeT[2];
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_og_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_b_J[c4_i] = c4_I[c4_i] - 0.15;
  }

  c4_b_st.site = &c4_pg_emlrtRSI;
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    chartInstance->c4_J[c4_i1] = c4_b_J[c4_i1];
  }

  c4_validateattributes(chartInstance, &c4_b_st, chartInstance->c4_J);
  c4_b_st.site = &c4_qg_emlrtRSI;
  for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
    c4_b_I[c4_i2] = c4_I[c4_i2];
  }

  c4_validateattributes(chartInstance, &c4_b_st, c4_b_I);
  for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
    c4_imSizeT[c4_i3] = 120.0 + 40.0 * (real_T)c4_i3;
  }

  ippreconstruct_real64(&c4_b_J[0], &c4_I[0], &c4_imSizeT[0], 2.0);
}

static void c4_validateattributes(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_g_a[19200])
{
  static char_T c4_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'c', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c4_b_cv1[5] = { 'i', 'n', 'p', 'u', 't' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_c_x;
  real_T c4_d_x;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_u_emlrtRSI;
  c4_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 19200)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_c_x = c4_g_a[(int32_T)c4_b_k - 1];
    c4_d_x = c4_c_x;
    c4_b_b = muDoubleScalarIsNaN(c4_d_x);
    c4_b_p = !c4_b_b;
    if (c4_b_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_st, &c4_m_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }
}

static void c4_imregionalmax(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_d_varargin_1[19200],
  boolean_T c4_BW[19200])
{
  static char_T c4_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'g', 'i', 'o', 'n', 'a', 'l', 'm', 'a', 'x', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c4_b_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c4_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'I', ',' };

  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_connSizeT[2];
  real_T c4_imSizeT[2];
  real_T c4_b_k;
  real_T c4_c_x;
  real_T c4_d_k;
  real_T c4_d_x;
  real_T c4_e_x;
  int32_T c4_c_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  boolean_T c4_conn[9];
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_rg_emlrtRSI;
  c4_b_st.site = &c4_u_emlrtRSI;
  c4_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 19200)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_c_x = c4_d_varargin_1[(int32_T)c4_b_k - 1];
    c4_d_x = c4_c_x;
    c4_b_b = muDoubleScalarIsNaN(c4_d_x);
    c4_b_p = !c4_b_b;
    if (c4_b_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c4_b_st, &c4_m_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_st.site = &c4_sg_emlrtRSI;
  for (c4_c_k = 0; c4_c_k < 19200; c4_c_k++) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    c4_e_x = c4_d_varargin_1[(int32_T)c4_d_k - 1];
    c4_c_b = muDoubleScalarIsNaN(c4_e_x);
    if (c4_c_b) {
      c4_d_y = NULL;
      sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        19), false);
      c4_e_y = NULL;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        19), false);
      sf_mex_call(&c4_st, &c4_l_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                  sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c4_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
    }
  }

  c4_st.site = &c4_tg_emlrtRSI;
  for (c4_i = 0; c4_i < 9; c4_i++) {
    c4_conn[c4_i] = true;
  }

  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_imSizeT[c4_i1] = 120.0 + 40.0 * (real_T)c4_i1;
  }

  for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
    c4_connSizeT[c4_i2] = 3.0;
  }

  imregionalmax_real64(&c4_d_varargin_1[0], &c4_BW[0], 2.0, &c4_imSizeT[0],
                       &c4_conn[0], 2.0, &c4_connSizeT[0]);
}

static void c4_regionprops(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200], real_T
  c4_b_varargin_2[19200], c4_emxArray_sBO2RC5RVZVTbundPSRqHn *c4_outstats)
{
  static char_T c4_b_cv[31] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'r', 'e', 'g',
    'i', 'o', 'n', 'p', 'r', 'o', 'p', 's', ':', 's', 'i', 'z', 'e', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h' };

  c4_emxArray_int32_T *c4_b_regionLengths;
  c4_emxArray_int32_T *c4_idxCount;
  c4_emxArray_int32_T *c4_regionLengths;
  c4_emxArray_real_T *c4_regionIndices;
  c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_stats;
  c4_sHtk0WM4OMtyqkehwQYcq2 c4_statsAlreadyComputed;
  c4_s_VSLwMee4Kv1oTF0BcoITHB c4_CC;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_imageSize[2];
  real_T c4_b_k;
  real_T c4_b_numObjs;
  real_T c4_b_vIdx;
  real_T c4_c_numObjs;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_k;
  real_T c4_d_numObjs;
  real_T c4_f_k;
  real_T c4_numObjs;
  real_T c4_x1;
  real_T c4_x2;
  int32_T c4_b_loop_ub;
  int32_T c4_b_stats;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_dim;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_vIdx;
  boolean_T c4_e_varargin_1[19200];
  boolean_T c4_b;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_emxInitStruct_s_VSLwMee4Kv1oTF0(chartInstance, c4_sp, &c4_CC,
    &c4_ue_emlrtRTEI);
  c4_st.site = &c4_ug_emlrtRSI;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_e_varargin_1[c4_i] = c4_d_varargin_1[c4_i];
  }

  c4_bwconncomp(chartInstance, &c4_st, c4_e_varargin_1, &c4_CC);
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_imageSize[c4_i1] = c4_CC.ImageSize[c4_i1];
  }

  c4_numObjs = c4_CC.NumObjects;
  c4_st.site = &c4_vg_emlrtRSI;
  c4_b_numObjs = c4_numObjs;
  c4_p = false;
  c4_b_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 2)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_x1 = c4_imageSize[(int32_T)c4_b_k - 1];
    c4_x2 = 120.0 + 40.0 * (real_T)((int32_T)c4_b_k - 1);
    c4_c_p = (c4_x1 == c4_x2);
    if (!c4_c_p) {
      c4_b_p = false;
      c4_exitg1 = true;
    } else {
      c4_k++;
    }
  }

  if (c4_b_p) {
    c4_p = true;
  }

  if (!c4_p) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c4_st, &c4_n_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }

  c4_emxInit_s_nrlUwWofUDGxo1t78e6dw(chartInstance, &c4_st, &c4_stats, 1,
    &c4_ve_emlrtRTEI);
  c4_b_st.site = &c4_xh_emlrtRSI;
  c4_c_numObjs = c4_b_numObjs;
  c4_c_st.site = &c4_yh_emlrtRSI;
  c4_repmat(chartInstance, &c4_c_st, c4_c_numObjs, c4_outstats);
  c4_st.site = &c4_wg_emlrtRSI;
  c4_initializeStatsStruct(chartInstance, &c4_st, c4_numObjs, c4_stats,
    &c4_statsAlreadyComputed);
  c4_st.site = &c4_xg_emlrtRSI;
  c4_d_numObjs = c4_numObjs;
  c4_statsAlreadyComputed.PixelIdxList = true;
  if (c4_d_numObjs != 0.0) {
    c4_emxInit_real_T1(chartInstance, &c4_st, &c4_regionIndices, 1,
                       &c4_xe_emlrtRTEI);
    c4_i2 = c4_regionIndices->size[0];
    c4_regionIndices->size[0] = c4_CC.RegionIndices->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_regionIndices, c4_i2,
      &c4_pe_emlrtRTEI);
    c4_loop_ub = c4_CC.RegionIndices->size[0] - 1;
    for (c4_i4 = 0; c4_i4 <= c4_loop_ub; c4_i4++) {
      c4_regionIndices->data[c4_i4] = c4_CC.RegionIndices->data[c4_i4];
    }

    c4_emxInit_int32_T(chartInstance, &c4_st, &c4_regionLengths, 1,
                       &c4_we_emlrtRTEI);
    c4_i6 = c4_regionLengths->size[0];
    c4_regionLengths->size[0] = c4_CC.RegionLengths->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_regionLengths, c4_i6,
      &c4_qe_emlrtRTEI);
    c4_b_loop_ub = c4_CC.RegionLengths->size[0] - 1;
    for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
      c4_regionLengths->data[c4_i7] = c4_CC.RegionLengths->data[c4_i7];
    }

    c4_b_st.site = &c4_ci_emlrtRSI;
    c4_c_st.site = &c4_rh_emlrtRSI;
    c4_dim = 2;
    if ((real_T)c4_regionLengths->size[0] != 1.0) {
      c4_dim = 1;
    }

    c4_emxInit_int32_T(chartInstance, &c4_c_st, &c4_b_regionLengths, 1,
                       &c4_re_emlrtRTEI);
    c4_i12 = c4_b_regionLengths->size[0];
    c4_b_regionLengths->size[0] = c4_regionLengths->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_regionLengths,
      c4_i12, &c4_re_emlrtRTEI);
    c4_c_loop_ub = c4_regionLengths->size[0] - 1;
    for (c4_i16 = 0; c4_i16 <= c4_c_loop_ub; c4_i16++) {
      c4_b_regionLengths->data[c4_i16] = c4_regionLengths->data[c4_i16];
    }

    c4_emxInit_int32_T(chartInstance, &c4_c_st, &c4_idxCount, 1,
                       &c4_ye_emlrtRTEI);
    c4_d_st.site = &c4_sh_emlrtRSI;
    c4_useConstantDim(chartInstance, &c4_d_st, c4_b_regionLengths, c4_dim,
                      c4_regionLengths);
    c4_i20 = c4_idxCount->size[0];
    c4_idxCount->size[0] = 1 + c4_regionLengths->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_idxCount, c4_i20,
      &c4_se_emlrtRTEI);
    c4_idxCount->data[0] = 0;
    c4_d_loop_ub = c4_regionLengths->size[0] - 1;
    c4_emxFree_int32_T(chartInstance, &c4_b_regionLengths);
    for (c4_i21 = 0; c4_i21 <= c4_d_loop_ub; c4_i21++) {
      c4_idxCount->data[c4_i21 + 1] = c4_regionLengths->data[c4_i21];
    }

    c4_emxFree_int32_T(chartInstance, &c4_regionLengths);
    c4_d1 = (real_T)c4_stats->size[0];
    c4_i22 = (int32_T)c4_d1 - 1;
    for (c4_e_k = 0; c4_e_k <= c4_i22; c4_e_k++) {
      c4_f_k = (real_T)c4_e_k + 1.0;
      c4_i23 = c4_idxCount->size[0];
      c4_i24 = (int32_T)c4_f_k;
      c4_i25 = c4_idxCount->data[emlrtDynamicBoundsCheckR2012b(c4_i24, 1, c4_i23,
        &c4_uc_emlrtBCI, &c4_st) - 1] + 1;
      c4_i26 = c4_idxCount->size[0];
      c4_i27 = (int32_T)(c4_f_k + 1.0);
      c4_i28 = c4_idxCount->data[emlrtDynamicBoundsCheckR2012b(c4_i27, 1, c4_i26,
        &c4_vc_emlrtBCI, &c4_st) - 1];
      c4_b = (c4_i25 > c4_i28);
      if (c4_b) {
        c4_i30 = 0;
        c4_i31 = -1;
      } else {
        c4_i29 = c4_regionIndices->size[0];
        c4_i30 = emlrtDynamicBoundsCheckR2012b(c4_i25, 1, c4_i29,
          &c4_uc_emlrtBCI, &c4_st) - 1;
        c4_i32 = c4_regionIndices->size[0];
        c4_i31 = emlrtDynamicBoundsCheckR2012b(c4_i28, 1, c4_i32,
          &c4_vc_emlrtBCI, &c4_st) - 1;
      }

      c4_b_stats = c4_stats->size[0];
      c4_i33 = (int32_T)c4_f_k;
      c4_i34 = emlrtDynamicBoundsCheckR2012b(c4_i33, 1, c4_b_stats,
        &c4_bd_emlrtBCI, &c4_st) - 1;
      c4_i35 = c4_stats->data[c4_i34].PixelIdxList->size[0];
      c4_stats->data[c4_i34].PixelIdxList->size[0] = (c4_i31 - c4_i30) + 1;
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_stats->data[c4_i34]
        .PixelIdxList, c4_i35, &c4_te_emlrtRTEI);
      c4_e_loop_ub = c4_i31 - c4_i30;
      for (c4_i36 = 0; c4_i36 <= c4_e_loop_ub; c4_i36++) {
        c4_i37 = (int32_T)c4_f_k;
        c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i37, 1, c4_b_stats,
          &c4_bd_emlrtBCI, &c4_st) - 1].PixelIdxList->data[c4_i36] =
          c4_regionIndices->data[c4_i30 + c4_i36];
      }
    }

    c4_emxFree_int32_T(chartInstance, &c4_idxCount);
    c4_emxFree_real_T(chartInstance, &c4_regionIndices);
  }

  c4_emxFreeStruct_s_VSLwMee4Kv1oTF0(chartInstance, &c4_CC);
  c4_st.site = &c4_yg_emlrtRSI;
  for (c4_i3 = 0; c4_i3 < 19200; c4_i3++) {
    chartInstance->c4_varargin_2[c4_i3] = c4_b_varargin_2[c4_i3];
  }

  c4_b_ComputeWeightedCentroid(chartInstance, &c4_st,
    chartInstance->c4_varargin_2, c4_stats, &c4_statsAlreadyComputed);
  c4_st.site = &c4_ah_emlrtRSI;
  c4_d = (real_T)c4_stats->size[0];
  c4_i5 = (int32_T)c4_d - 1;
  for (c4_c_k = 0; c4_c_k <= c4_i5; c4_c_k++) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    c4_i8 = c4_stats->size[0];
    c4_i9 = (int32_T)c4_d_k;
    emlrtDynamicBoundsCheckR2012b(c4_i9, 1, c4_i8, &c4_wc_emlrtBCI, &c4_st);
    c4_i10 = c4_outstats->size[0];
    c4_i11 = (int32_T)c4_d_k;
    emlrtDynamicBoundsCheckR2012b(c4_i11, 1, c4_i10, &c4_xc_emlrtBCI, &c4_st);
    for (c4_vIdx = 0; c4_vIdx < 2; c4_vIdx++) {
      c4_b_vIdx = (real_T)c4_vIdx + 1.0;
      c4_i13 = c4_stats->size[0];
      c4_i14 = (int32_T)c4_d_k;
      c4_i15 = emlrtDynamicBoundsCheckR2012b(c4_i14, 1, c4_i13, &c4_ad_emlrtBCI,
        &c4_st) - 1;
      c4_i17 = c4_outstats->size[0];
      c4_i18 = (int32_T)c4_d_k;
      c4_i19 = emlrtDynamicBoundsCheckR2012b(c4_i18, 1, c4_i17, &c4_yc_emlrtBCI,
        &c4_st) - 1;
      c4_outstats->data[c4_i19].WeightedCentroid[(int32_T)c4_b_vIdx - 1] =
        c4_stats->data[c4_i15].WeightedCentroid[(int32_T)c4_b_vIdx - 1];
    }
  }

  c4_emxFree_s_nrlUwWofUDGxo1t78e6dw(chartInstance, &c4_stats);
}

static void c4_bwconncomp(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200],
  c4_s_VSLwMee4Kv1oTF0BcoITHB *c4_CC)
{
  c4_emxArray_int32_T *c4_c_x;
  c4_emxArray_int32_T *c4_d_x;
  c4_emxArray_int32_T *c4_endRow;
  c4_emxArray_int32_T *c4_idxCount;
  c4_emxArray_int32_T *c4_labelsRenumbered;
  c4_emxArray_int32_T *c4_regionLengths;
  c4_emxArray_int32_T *c4_startCol;
  c4_emxArray_int32_T *c4_startRow;
  c4_emxArray_real_T *c4_pixelIdxList;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  real_T c4_b_col;
  real_T c4_b_k;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_col;
  real_T c4_numComponents;
  real_T c4_y;
  int32_T c4_iv[1];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_c;
  int32_T c4_b_idx;
  int32_T c4_b_loop_ub;
  int32_T c4_b_node;
  int32_T c4_b_p;
  int32_T c4_b_root_k;
  int32_T c4_b_root_p;
  int32_T c4_b_vlen;
  int32_T c4_c;
  int32_T c4_c_b;
  int32_T c4_c_col;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_p;
  int32_T c4_col;
  int32_T c4_column_offset;
  int32_T c4_currentColumn;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_dim;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_exitg1;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_f_loop_ub;
  int32_T c4_firstRunOnPreviousColumn;
  int32_T c4_firstRunOnThisColumn;
  int32_T c4_g_a;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_g_loop_ub;
  int32_T c4_h_a;
  int32_T c4_h_b;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_a;
  int32_T c4_i_b;
  int32_T c4_i_k;
  int32_T c4_ix;
  int32_T c4_j_a;
  int32_T c4_j_b;
  int32_T c4_j_k;
  int32_T c4_k;
  int32_T c4_k_a;
  int32_T c4_lastRunOnPreviousColumn;
  int32_T c4_loop_ub;
  int32_T c4_nextLabel;
  int32_T c4_node;
  int32_T c4_numRuns;
  int32_T c4_p;
  int32_T c4_root_k;
  int32_T c4_root_p;
  int32_T c4_row;
  int32_T c4_rowidx;
  int32_T c4_runCounter;
  int32_T c4_vlen;
  int32_T c4_xoffset;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_d_overflow;
  boolean_T c4_e_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_hh_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_numRuns = 0;
  for (c4_col = 0; c4_col < 160; c4_col++) {
    c4_b_col = (real_T)c4_col + 1.0;
    if (c4_d_varargin_1[120 * ((int32_T)c4_b_col - 1)]) {
      c4_numRuns++;
    }

    for (c4_k = 0; c4_k < 119; c4_k++) {
      c4_b_k = (real_T)c4_k + 2.0;
      if (c4_d_varargin_1[((int32_T)c4_b_k + 120 * ((int32_T)c4_b_col - 1)) - 1]
          && (!c4_d_varargin_1[((int32_T)(c4_b_k - 1.0) + 120 * ((int32_T)
             c4_b_col - 1)) - 1])) {
        c4_numRuns++;
      }
    }
  }

  c4_emxInit_int32_T(chartInstance, &c4_st, &c4_regionLengths, 1,
                     &c4_nf_emlrtRTEI);
  c4_emxInit_int32_T(chartInstance, &c4_st, &c4_startRow, 1, &c4_pf_emlrtRTEI);
  c4_emxInit_int32_T(chartInstance, &c4_st, &c4_endRow, 1, &c4_qf_emlrtRTEI);
  c4_emxInit_int32_T(chartInstance, &c4_st, &c4_startCol, 1, &c4_rf_emlrtRTEI);
  if (c4_numRuns == 0) {
    c4_startRow->size[0] = 0;
    c4_endRow->size[0] = 0;
    c4_startCol->size[0] = 0;
    c4_regionLengths->size[0] = 0;
    c4_numRuns = 0;
  } else {
    c4_i = c4_startRow->size[0];
    c4_d = (real_T)c4_numRuns;
    c4_startRow->size[0] = (int32_T)emlrtNonNegativeCheckR2012b(c4_d,
      &c4_f_emlrtDCI, &c4_st);
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_startRow, c4_i,
      &c4_af_emlrtRTEI);
    c4_i1 = c4_endRow->size[0];
    c4_endRow->size[0] = c4_numRuns;
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_endRow, c4_i1,
      &c4_bf_emlrtRTEI);
    c4_i2 = c4_startCol->size[0];
    c4_startCol->size[0] = c4_numRuns;
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_startCol, c4_i2,
      &c4_cf_emlrtRTEI);
    c4_b_st.site = &c4_ih_emlrtRSI;
    c4_runCounter = 1;
    for (c4_c_col = 0; c4_c_col < 160; c4_c_col++) {
      c4_d_col = (real_T)c4_c_col + 1.0;
      c4_row = 1;
      while (c4_row <= 120) {
        while ((c4_row <= 120) && (!c4_d_varargin_1[(c4_row + 120 * ((int32_T)
                  c4_d_col - 1)) - 1])) {
          c4_row++;
        }

        if ((c4_row <= 120) && c4_d_varargin_1[(c4_row + 120 * ((int32_T)
              c4_d_col - 1)) - 1]) {
          c4_i8 = c4_startCol->size[0];
          c4_startCol->data[emlrtDynamicBoundsCheckR2012b(c4_runCounter, 1,
            c4_i8, &c4_cd_emlrtBCI, &c4_b_st) - 1] = (int32_T)c4_d_col;
          c4_i9 = c4_startRow->size[0];
          c4_startRow->data[emlrtDynamicBoundsCheckR2012b(c4_runCounter, 1,
            c4_i9, &c4_ed_emlrtBCI, &c4_b_st) - 1] = c4_row;
          while ((c4_row <= 120) && c4_d_varargin_1[(c4_row + 120 * ((int32_T)
                   c4_d_col - 1)) - 1]) {
            c4_row++;
          }

          c4_i12 = c4_endRow->size[0];
          c4_endRow->data[emlrtDynamicBoundsCheckR2012b(c4_runCounter, 1, c4_i12,
            &c4_hd_emlrtBCI, &c4_b_st) - 1] = c4_row - 1;
          c4_runCounter++;
        }
      }
    }

    c4_i6 = c4_regionLengths->size[0];
    c4_regionLengths->size[0] = c4_numRuns;
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_regionLengths, c4_i6,
      &c4_df_emlrtRTEI);
    c4_loop_ub = c4_numRuns - 1;
    for (c4_i7 = 0; c4_i7 <= c4_loop_ub; c4_i7++) {
      c4_regionLengths->data[c4_i7] = 0;
    }

    c4_c_k = 1;
    c4_currentColumn = 2;
    c4_nextLabel = 1;
    c4_firstRunOnPreviousColumn = -1;
    c4_lastRunOnPreviousColumn = 0;
    c4_firstRunOnThisColumn = 1;
    while (c4_c_k <= c4_numRuns) {
      c4_i13 = c4_startCol->size[0];
      if (c4_startCol->data[emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i13,
           &c4_dd_emlrtBCI, &c4_st) - 1] == c4_currentColumn) {
        c4_firstRunOnPreviousColumn = c4_firstRunOnThisColumn;
        c4_firstRunOnThisColumn = c4_c_k;
        c4_lastRunOnPreviousColumn = c4_c_k;
        c4_i21 = c4_startCol->size[0];
        c4_currentColumn = c4_startCol->data[emlrtDynamicBoundsCheckR2012b
          (c4_c_k, 1, c4_i21, &c4_gd_emlrtBCI, &c4_st) - 1] + 1;
      } else {
        c4_i18 = c4_startCol->size[0];
        if (c4_startCol->data[emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i18,
             &c4_fd_emlrtBCI, &c4_st) - 1] > c4_currentColumn) {
          c4_firstRunOnPreviousColumn = -1;
          c4_lastRunOnPreviousColumn = 0;
          c4_firstRunOnThisColumn = c4_c_k;
          c4_i22 = c4_startCol->size[0];
          c4_currentColumn = c4_startCol->data[emlrtDynamicBoundsCheckR2012b
            (c4_c_k, 1, c4_i22, &c4_jd_emlrtBCI, &c4_st) - 1] + 1;
        }
      }

      if (c4_firstRunOnPreviousColumn >= 0) {
        for (c4_p = c4_firstRunOnPreviousColumn; c4_p <
             c4_lastRunOnPreviousColumn; c4_p++) {
          c4_i25 = c4_endRow->size[0];
          c4_i26 = c4_startRow->size[0];
          if (c4_endRow->data[emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i25,
               &c4_pd_emlrtBCI, &c4_st) - 1] >= c4_startRow->
              data[emlrtDynamicBoundsCheckR2012b(c4_p, 1, c4_i26,
               &c4_qd_emlrtBCI, &c4_st) - 1] - 1) {
            c4_i27 = c4_startRow->size[0];
            c4_i28 = c4_endRow->size[0];
            if (c4_startRow->data[emlrtDynamicBoundsCheckR2012b(c4_c_k, 1,
                 c4_i27, &c4_rd_emlrtBCI, &c4_st) - 1] <= c4_endRow->
                data[emlrtDynamicBoundsCheckR2012b(c4_p, 1, c4_i28,
                 &c4_sd_emlrtBCI, &c4_st) - 1] + 1) {
              c4_i30 = c4_regionLengths->size[0];
              if (c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_c_k, 1,
                   c4_i30, &c4_td_emlrtBCI, &c4_st) - 1] == 0) {
                c4_i33 = c4_regionLengths->size[0];
                c4_i36 = c4_regionLengths->size[0];
                c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_c_k, 1,
                  c4_i36, &c4_xd_emlrtBCI, &c4_st) - 1] = c4_regionLengths->
                  data[emlrtDynamicBoundsCheckR2012b(c4_p, 1, c4_i33,
                  &c4_wd_emlrtBCI, &c4_st) - 1];
                c4_nextLabel++;
              } else {
                c4_i32 = c4_regionLengths->size[0];
                c4_i35 = c4_regionLengths->size[0];
                if (c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_c_k,
                     1, c4_i32, &c4_ud_emlrtBCI, &c4_st) - 1] !=
                    c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_p, 1,
                     c4_i35, &c4_vd_emlrtBCI, &c4_st) - 1]) {
                  c4_b_st.site = &c4_jh_emlrtRSI;
                  c4_g_k = c4_c_k;
                  c4_b_p = c4_p;
                  c4_c_st.site = &c4_kh_emlrtRSI;
                  c4_node = c4_g_k;
                  c4_root_k = c4_node;
                  do {
                    c4_exitg1 = 0;
                    c4_i40 = c4_regionLengths->size[0];
                    if (c4_root_k != c4_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c4_root_k, 1, c4_i40,
                         &c4_ae_emlrtBCI, &c4_c_st) - 1]) {
                      c4_i42 = c4_regionLengths->size[0];
                      c4_i43 = c4_regionLengths->size[0];
                      c4_i44 = c4_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c4_root_k, 1, c4_i43,
                        &c4_fe_emlrtBCI, &c4_c_st) - 1];
                      c4_i45 = c4_regionLengths->size[0];
                      c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c4_root_k, 1, c4_i45, &c4_ge_emlrtBCI, &c4_c_st) - 1] =
                        c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c4_i44, 1, c4_i42, &c4_fe_emlrtBCI, &c4_c_st) - 1];
                      c4_i47 = c4_regionLengths->size[0];
                      c4_root_k = c4_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c4_root_k, 1, c4_i47,
                        &c4_he_emlrtBCI, &c4_c_st) - 1];
                    } else {
                      c4_exitg1 = 1;
                    }
                  } while (c4_exitg1 == 0);

                  c4_c_st.site = &c4_lh_emlrtRSI;
                  c4_b_node = c4_b_p;
                  c4_root_p = c4_b_node;
                  do {
                    c4_exitg1 = 0;
                    c4_i48 = c4_regionLengths->size[0];
                    if (c4_root_p != c4_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c4_root_p, 1, c4_i48,
                         &c4_ae_emlrtBCI, &c4_c_st) - 1]) {
                      c4_i49 = c4_regionLengths->size[0];
                      c4_i50 = c4_regionLengths->size[0];
                      c4_i52 = c4_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c4_root_p, 1, c4_i50,
                        &c4_fe_emlrtBCI, &c4_c_st) - 1];
                      c4_i53 = c4_regionLengths->size[0];
                      c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c4_root_p, 1, c4_i53, &c4_ge_emlrtBCI, &c4_c_st) - 1] =
                        c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c4_i52, 1, c4_i49, &c4_fe_emlrtBCI, &c4_c_st) - 1];
                      c4_i54 = c4_regionLengths->size[0];
                      c4_root_p = c4_regionLengths->
                        data[emlrtDynamicBoundsCheckR2012b(c4_root_p, 1, c4_i54,
                        &c4_he_emlrtBCI, &c4_c_st) - 1];
                    } else {
                      c4_exitg1 = 1;
                    }
                  } while (c4_exitg1 == 0);

                  if (c4_root_k != c4_root_p) {
                    c4_c_st.site = &c4_mh_emlrtRSI;
                    c4_b_root_k = c4_root_k;
                    c4_b_root_p = c4_root_p;
                    c4_i_k = c4_g_k;
                    c4_c_p = c4_b_p;
                    if (c4_b_root_p < c4_b_root_k) {
                      c4_i57 = c4_regionLengths->size[0];
                      c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c4_b_root_k, 1, c4_i57, &c4_je_emlrtBCI, &c4_c_st) - 1]
                        = c4_b_root_p;
                      c4_i60 = c4_regionLengths->size[0];
                      c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c4_i_k, 1, c4_i60, &c4_le_emlrtBCI, &c4_c_st) - 1] =
                        c4_b_root_p;
                    } else {
                      c4_i56 = c4_regionLengths->size[0];
                      c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c4_b_root_p, 1, c4_i56, &c4_ie_emlrtBCI, &c4_c_st) - 1]
                        = c4_b_root_k;
                      c4_i59 = c4_regionLengths->size[0];
                      c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b
                        (c4_c_p, 1, c4_i59, &c4_ke_emlrtBCI, &c4_c_st) - 1] =
                        c4_b_root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      c4_i23 = c4_regionLengths->size[0];
      if (c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i23,
           &c4_kd_emlrtBCI, &c4_st) - 1] == 0) {
        c4_i24 = c4_regionLengths->size[0];
        c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_c_k, 1, c4_i24,
          &c4_od_emlrtBCI, &c4_st) - 1] = c4_nextLabel;
        c4_nextLabel++;
      }

      c4_c_k++;
    }
  }

  if (c4_numRuns == 0) {
    c4_CC->Connectivity = 8.0;
    for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
      c4_CC->ImageSize[c4_i4] = 120.0 + 40.0 * (real_T)c4_i4;
    }

    c4_CC->NumObjects = 0.0;
    c4_CC->RegionIndices->size[0] = 0;
    c4_i5 = c4_CC->RegionLengths->size[0];
    c4_CC->RegionLengths->size[0] = 1;
    c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_CC->RegionLengths,
      c4_i5, &c4_ff_emlrtRTEI);
    c4_CC->RegionLengths->data[0] = 0;
  } else {
    c4_emxInit_int32_T(chartInstance, c4_sp, &c4_labelsRenumbered, 1,
                       &c4_of_emlrtRTEI);
    c4_i3 = c4_labelsRenumbered->size[0];
    c4_labelsRenumbered->size[0] = c4_regionLengths->size[0];
    c4_st.site = &c4_gl_emlrtRSI;
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_labelsRenumbered,
      c4_i3, &c4_ef_emlrtRTEI);
    c4_numComponents = 0.0;
    c4_st.site = &c4_gh_emlrtRSI;
    c4_b = c4_numRuns;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_d_k = 1; c4_d_k - 1 < c4_numRuns; c4_d_k++) {
      c4_e_k = c4_d_k;
      c4_i11 = c4_regionLengths->size[0];
      if (c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i11,
           &c4_id_emlrtBCI, c4_sp) - 1] == c4_e_k) {
        c4_numComponents++;
        c4_i15 = c4_labelsRenumbered->size[0];
        c4_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1,
          c4_i15, &c4_nd_emlrtBCI, c4_sp) - 1] = (int32_T)c4_numComponents;
      }

      c4_i14 = c4_labelsRenumbered->size[0];
      c4_i17 = c4_regionLengths->size[0];
      c4_i19 = c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1,
        c4_i17, &c4_ld_emlrtBCI, c4_sp) - 1];
      c4_i20 = c4_labelsRenumbered->size[0];
      c4_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i20,
        &c4_md_emlrtBCI, c4_sp) - 1] = c4_labelsRenumbered->
        data[emlrtDynamicBoundsCheckR2012b(c4_i19, 1, c4_i14, &c4_ld_emlrtBCI,
        c4_sp) - 1];
    }

    c4_i10 = c4_regionLengths->size[0];
    c4_regionLengths->size[0] = (int32_T)emlrtIntegerCheckR2012b
      (c4_numComponents, &c4_g_emlrtDCI, c4_sp);
    c4_st.site = &c4_fl_emlrtRSI;
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_regionLengths, c4_i10,
      &c4_gf_emlrtRTEI);
    c4_b_loop_ub = (int32_T)emlrtIntegerCheckR2012b(c4_numComponents,
      &c4_g_emlrtDCI, c4_sp) - 1;
    for (c4_i16 = 0; c4_i16 <= c4_b_loop_ub; c4_i16++) {
      c4_regionLengths->data[c4_i16] = 0;
    }

    c4_st.site = &c4_fh_emlrtRSI;
    c4_c_b = c4_numRuns;
    c4_d_b = c4_c_b;
    if (1 > c4_d_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_d_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_f_k = 1; c4_f_k - 1 < c4_numRuns; c4_f_k++) {
      c4_e_k = c4_f_k;
      c4_i29 = c4_labelsRenumbered->size[0];
      c4_b_idx = c4_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c4_e_k,
        1, c4_i29, &c4_yd_emlrtBCI, c4_sp) - 1];
      c4_i31 = c4_regionLengths->size[0];
      c4_i34 = c4_endRow->size[0];
      c4_i37 = c4_startRow->size[0];
      c4_i38 = c4_regionLengths->size[0];
      c4_regionLengths->data[emlrtDynamicBoundsCheckR2012b(c4_b_idx, 1, c4_i38,
        &c4_ee_emlrtBCI, c4_sp) - 1] = ((c4_regionLengths->
        data[emlrtDynamicBoundsCheckR2012b(c4_b_idx, 1, c4_i31, &c4_be_emlrtBCI,
        c4_sp) - 1] + c4_endRow->data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1,
        c4_i34, &c4_ce_emlrtBCI, c4_sp) - 1]) - c4_startRow->
        data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i37, &c4_de_emlrtBCI,
        c4_sp) - 1]) + 1;
    }

    c4_st.site = &c4_eh_emlrtRSI;
    c4_b_st.site = &c4_nh_emlrtRSI;
    c4_c_st.site = &c4_oh_emlrtRSI;
    c4_vlen = c4_regionLengths->size[0];
    if ((c4_regionLengths->size[0] == 0) || (c4_vlen == 0)) {
      c4_y = 0.0;
    } else {
      c4_d_st.site = &c4_ph_emlrtRSI;
      c4_b_vlen = c4_vlen;
      c4_y = (real_T)c4_regionLengths->data[0];
      c4_e_st.site = &c4_qh_emlrtRSI;
      c4_e_b = c4_b_vlen;
      c4_f_b = c4_e_b;
      if (2 > c4_f_b) {
        c4_c_overflow = false;
      } else {
        c4_c_overflow = (c4_f_b > 2147483646);
      }

      if (c4_c_overflow) {
        c4_f_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
      }

      for (c4_h_k = 1; c4_h_k < c4_b_vlen; c4_h_k++) {
        c4_xoffset = c4_h_k + 1;
        c4_ix = c4_xoffset - 1;
        c4_y += (real_T)c4_regionLengths->data[c4_ix];
      }
    }

    c4_emxInit_real_T1(chartInstance, &c4_c_st, &c4_pixelIdxList, 1,
                       &c4_mf_emlrtRTEI);
    c4_emxInit_int32_T(chartInstance, &c4_c_st, &c4_c_x, 1, &c4_if_emlrtRTEI);
    c4_d1 = emlrtNonNegativeCheckR2012b(c4_y, &c4_i_emlrtDCI, c4_sp);
    c4_iv[0] = (int32_T)emlrtIntegerCheckR2012b(c4_d1, &c4_h_emlrtDCI, c4_sp);
    c4_i39 = c4_pixelIdxList->size[0];
    c4_pixelIdxList->size[0] = c4_iv[0];
    c4_st.site = &c4_eh_emlrtRSI;
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_pixelIdxList, c4_i39,
      &c4_hf_emlrtRTEI);
    c4_st.site = &c4_dh_emlrtRSI;
    c4_i41 = c4_c_x->size[0];
    c4_c_x->size[0] = c4_regionLengths->size[0];
    c4_b_st.site = &c4_dh_emlrtRSI;
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_c_x, c4_i41,
      &c4_if_emlrtRTEI);
    c4_c_loop_ub = c4_regionLengths->size[0] - 1;
    for (c4_i46 = 0; c4_i46 <= c4_c_loop_ub; c4_i46++) {
      c4_c_x->data[c4_i46] = c4_regionLengths->data[c4_i46];
    }

    c4_b_st.site = &c4_rh_emlrtRSI;
    c4_dim = 2;
    if ((real_T)c4_c_x->size[0] != 1.0) {
      c4_dim = 1;
    }

    c4_emxInit_int32_T(chartInstance, &c4_b_st, &c4_d_x, 1, &c4_re_emlrtRTEI);
    c4_i51 = c4_d_x->size[0];
    c4_d_x->size[0] = c4_c_x->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_b_st, c4_d_x, c4_i51,
      &c4_re_emlrtRTEI);
    c4_d_loop_ub = c4_c_x->size[0] - 1;
    for (c4_i55 = 0; c4_i55 <= c4_d_loop_ub; c4_i55++) {
      c4_d_x->data[c4_i55] = c4_c_x->data[c4_i55];
    }

    c4_emxInit_int32_T(chartInstance, &c4_b_st, &c4_idxCount, 1,
                       &c4_jf_emlrtRTEI);
    c4_c_st.site = &c4_sh_emlrtRSI;
    c4_useConstantDim(chartInstance, &c4_c_st, c4_d_x, c4_dim, c4_c_x);
    c4_i58 = c4_idxCount->size[0];
    c4_idxCount->size[0] = 1 + c4_c_x->size[0];
    c4_st.site = &c4_dh_emlrtRSI;
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_idxCount, c4_i58,
      &c4_jf_emlrtRTEI);
    c4_idxCount->data[0] = 0;
    c4_e_loop_ub = c4_c_x->size[0] - 1;
    c4_emxFree_int32_T(chartInstance, &c4_d_x);
    for (c4_i61 = 0; c4_i61 <= c4_e_loop_ub; c4_i61++) {
      c4_idxCount->data[c4_i61 + 1] = c4_c_x->data[c4_i61];
    }

    c4_emxFree_int32_T(chartInstance, &c4_c_x);
    c4_st.site = &c4_ch_emlrtRSI;
    c4_g_b = c4_numRuns;
    c4_h_b = c4_g_b;
    if (1 > c4_h_b) {
      c4_d_overflow = false;
    } else {
      c4_d_overflow = (c4_h_b > 2147483646);
    }

    if (c4_d_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_j_k = 1; c4_j_k - 1 < c4_numRuns; c4_j_k++) {
      c4_e_k = c4_j_k;
      c4_i62 = c4_startCol->size[0];
      c4_g_a = c4_startCol->data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i62,
        &c4_me_emlrtBCI, c4_sp) - 1] - 1;
      c4_c = c4_g_a;
      c4_h_a = c4_c;
      c4_column_offset = c4_h_a * 120;
      c4_i65 = c4_labelsRenumbered->size[0];
      c4_b_idx = c4_labelsRenumbered->data[emlrtDynamicBoundsCheckR2012b(c4_e_k,
        1, c4_i65, &c4_ne_emlrtBCI, c4_sp) - 1];
      c4_i66 = c4_startRow->size[0];
      c4_i67 = c4_startRow->data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i66,
        &c4_oe_emlrtBCI, c4_sp) - 1];
      c4_i69 = c4_endRow->size[0];
      c4_i70 = c4_endRow->data[emlrtDynamicBoundsCheckR2012b(c4_e_k, 1, c4_i69,
        &c4_pe_emlrtBCI, c4_sp) - 1];
      c4_st.site = &c4_bh_emlrtRSI;
      c4_i_a = c4_i67;
      c4_i_b = c4_i70;
      c4_j_a = c4_i_a;
      c4_j_b = c4_i_b;
      if (c4_j_a > c4_j_b) {
        c4_e_overflow = false;
      } else {
        c4_e_overflow = (c4_j_b > 2147483646);
      }

      if (c4_e_overflow) {
        c4_b_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      for (c4_rowidx = c4_i67; c4_rowidx <= c4_i70; c4_rowidx++) {
        c4_i73 = c4_idxCount->size[0];
        c4_k_a = c4_idxCount->data[emlrtDynamicBoundsCheckR2012b(c4_b_idx, 1,
          c4_i73, &c4_qe_emlrtBCI, c4_sp) - 1] + 1;
        c4_b_c = c4_k_a;
        c4_i74 = c4_idxCount->size[0];
        c4_idxCount->data[emlrtDynamicBoundsCheckR2012b(c4_b_idx, 1, c4_i74,
          &c4_re_emlrtBCI, c4_sp) - 1] = c4_b_c;
        c4_i75 = c4_pixelIdxList->size[0];
        c4_i76 = c4_idxCount->size[0];
        c4_i77 = c4_idxCount->data[emlrtDynamicBoundsCheckR2012b(c4_b_idx, 1,
          c4_i76, &c4_se_emlrtBCI, c4_sp) - 1];
        c4_pixelIdxList->data[emlrtDynamicBoundsCheckR2012b(c4_i77, 1, c4_i75,
          &c4_se_emlrtBCI, c4_sp) - 1] = (real_T)(c4_rowidx + c4_column_offset);
      }
    }

    c4_emxFree_int32_T(chartInstance, &c4_idxCount);
    c4_emxFree_int32_T(chartInstance, &c4_labelsRenumbered);
    c4_CC->Connectivity = 8.0;
    for (c4_i63 = 0; c4_i63 < 2; c4_i63++) {
      c4_CC->ImageSize[c4_i63] = 120.0 + 40.0 * (real_T)c4_i63;
    }

    c4_CC->NumObjects = c4_numComponents;
    c4_i64 = c4_CC->RegionIndices->size[0];
    c4_CC->RegionIndices->size[0] = c4_pixelIdxList->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, c4_sp, c4_CC->RegionIndices,
      c4_i64, &c4_kf_emlrtRTEI);
    c4_f_loop_ub = c4_pixelIdxList->size[0] - 1;
    for (c4_i68 = 0; c4_i68 <= c4_f_loop_ub; c4_i68++) {
      c4_CC->RegionIndices->data[c4_i68] = c4_pixelIdxList->data[c4_i68];
    }

    c4_emxFree_real_T(chartInstance, &c4_pixelIdxList);
    c4_i71 = c4_CC->RegionLengths->size[0];
    c4_CC->RegionLengths->size[0] = c4_regionLengths->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_CC->RegionLengths,
      c4_i71, &c4_lf_emlrtRTEI);
    c4_g_loop_ub = c4_regionLengths->size[0] - 1;
    for (c4_i72 = 0; c4_i72 <= c4_g_loop_ub; c4_i72++) {
      c4_CC->RegionLengths->data[c4_i72] = c4_regionLengths->data[c4_i72];
    }
  }

  c4_emxFree_int32_T(chartInstance, &c4_startCol);
  c4_emxFree_int32_T(chartInstance, &c4_endRow);
  c4_emxFree_int32_T(chartInstance, &c4_startRow);
  c4_emxFree_int32_T(chartInstance, &c4_regionLengths);
}

static void c4_useConstantDim(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_varargin_2,
  int32_T c4_varargin_3, c4_emxArray_int32_T *c4_varargout_1)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_nx;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  if (1 == c4_varargin_3) {
    c4_st.site = &c4_th_emlrtRSI;
    c4_i1 = c4_varargout_1->size[0];
    c4_varargout_1->size[0] = c4_b_varargin_2->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_varargout_1, c4_i1,
      &c4_sf_emlrtRTEI);
    c4_b_loop_ub = c4_b_varargin_2->size[0] - 1;
    for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
      c4_varargout_1->data[c4_i3] = c4_b_varargin_2->data[c4_i3];
    }

    c4_b_st.site = &c4_uh_emlrtRSI;
    if (c4_varargout_1->size[0] != 0) {
      c4_c_st.site = &c4_vh_emlrtRSI;
      c4_nx = c4_varargout_1->size[0] - 1;
      if (!((real_T)c4_varargout_1->size[0] == 1.0)) {
        c4_i4 = c4_nx;
        c4_d_st.site = &c4_wh_emlrtRSI;
        c4_b = c4_i4;
        c4_b_b = c4_b;
        if (1 > c4_b_b) {
          c4_overflow = false;
        } else {
          c4_overflow = (c4_b_b > 2147483646);
        }

        if (c4_overflow) {
          c4_e_st.site = &c4_mb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
        }

        for (c4_k = 1; c4_k - 1 < c4_i4; c4_k++) {
          c4_b_k = c4_k;
          c4_varargout_1->data[c4_b_k] += c4_varargout_1->data[c4_b_k - 1];
        }
      }
    }
  } else {
    c4_i = c4_varargout_1->size[0];
    c4_varargout_1->size[0] = c4_b_varargin_2->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_varargout_1, c4_i,
      &c4_sf_emlrtRTEI);
    c4_loop_ub = c4_b_varargin_2->size[0] - 1;
    for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
      c4_varargout_1->data[c4_i2] = c4_b_varargin_2->data[c4_i2];
    }
  }
}

static void c4_repmat(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real_T c4_d_varargin_1,
                      c4_emxArray_sBO2RC5RVZVTbundPSRqHn *c4_b)
{
  c4_emxArray_boolean_T *c4_tile;
  c4_sBO2RC5RVZVTbundPSRqHnH c4_b_s;
  emlrtStack c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_outsize[2];
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_loop_ub;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_emxInit_boolean_T1(chartInstance, c4_sp, &c4_tile, 1, &c4_tf_emlrtRTEI);
  c4_st.site = &c4_ai_emlrtRSI;
  c4_assertValidSizeArg(chartInstance, &c4_st, c4_d_varargin_1);
  c4_i = c4_tile->size[0];
  c4_tile->size[0] = (int32_T)c4_d_varargin_1;
  c4_st.site = &c4_bl_emlrtRSI;
  c4_emxEnsureCapacity_boolean_T1(chartInstance, &c4_st, c4_tile, c4_i,
    &c4_tf_emlrtRTEI);
  c4_loop_ub = (int32_T)c4_d_varargin_1 - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_tile->data[c4_i1] = false;
  }

  c4_outsize[0] = c4_tile->size[0];
  if (!((real_T)c4_outsize[0] == (real_T)c4_tile->size[0])) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv4, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c4_sp, &c4_o_emlrtMCI, "error", 0U, 1U, 14, c4_y);
  }

  c4_emxFree_boolean_T(chartInstance, &c4_tile);
  for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
    c4_b_s.WeightedCentroid[c4_i2] = 0.0;
  }

  c4_i3 = c4_b->size[0];
  c4_b->size[0] = c4_outsize[0];
  c4_st.site = &c4_wl_emlrtRSI;
  c4_emxEnsureCapacity_sBO2RC5RVZVTb(chartInstance, &c4_st, c4_b, c4_i3,
    &c4_uf_emlrtRTEI);
  c4_b_loop_ub = c4_outsize[0] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_b_loop_ub; c4_i4++) {
    c4_b->data[c4_i4] = c4_b_s;
  }
}

static void c4_assertValidSizeArg(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_d_varargin_1)
{
  static char_T c4_b_cv[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n',
    'p', 'u', 't' };

  static char_T c4_b_cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_arg;
  real_T c4_b_arg;
  real_T c4_c_x;
  real_T c4_e_varargin_1;
  real_T c4_n;
  int32_T c4_b_u;
  int32_T c4_c_u;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_p;
  (void)chartInstance;
  c4_arg = c4_d_varargin_1;
  if (c4_arg != c4_arg) {
    c4_p = false;
  } else {
    c4_c_x = c4_arg;
    c4_b = muDoubleScalarIsInf(c4_c_x);
    if (c4_b) {
      c4_p = false;
    } else {
      c4_p = true;
    }
  }

  if (c4_p) {
    c4_b_arg = c4_d_varargin_1;
    if (c4_b_arg > 2.147483647E+9) {
      c4_b_p = false;
    } else {
      c4_b_p = true;
    }

    if (c4_b_p) {
      c4_b_b = true;
    } else {
      c4_b_b = false;
    }
  } else {
    c4_b_b = false;
  }

  if (!c4_b_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c4_b_u = MIN_int32_T;
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 6, 0U, 0U, 0U, 0), false);
    c4_c_u = MAX_int32_T;
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_c_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_call(c4_sp, &c4_p_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 3U, 14, c4_b_y, 14, c4_c_y, 14, c4_f_y)));
  }

  c4_e_varargin_1 = c4_d_varargin_1;
  if (c4_e_varargin_1 <= 0.0) {
    c4_n = 0.0;
  } else {
    c4_n = c4_e_varargin_1;
  }

  if (!(c4_n <= 2.147483647E+9)) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call(c4_sp, &c4_q_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_e_y)));
  }
}

static void c4_initializeStatsStruct(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_numObjs,
  c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_stats, c4_sHtk0WM4OMtyqkehwQYcq2
  *c4_statsAlreadyComputed)
{
  c4_emxArray_boolean_T *c4_tile;
  c4_s_nrlUwWofUDGxo1t78e6dwC c4_statsOneObj;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_d_varargin_1;
  int32_T c4_outsize[2];
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_loop_ub;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_emxInitStruct_s_nrlUwWofUDGxo1t(chartInstance, c4_sp, &c4_statsOneObj,
    &c4_wf_emlrtRTEI);
  c4_statsAlreadyComputed->Area = false;
  c4_statsOneObj.Area = 0.0;
  c4_statsAlreadyComputed->Centroid = false;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_statsOneObj.Centroid[c4_i] = 0.0;
  }

  c4_statsAlreadyComputed->BoundingBox = false;
  for (c4_i1 = 0; c4_i1 < 4; c4_i1++) {
    c4_statsOneObj.BoundingBox[c4_i1] = 0.0;
  }

  c4_statsAlreadyComputed->MajorAxisLength = false;
  c4_statsOneObj.MajorAxisLength = 0.0;
  c4_statsAlreadyComputed->MinorAxisLength = false;
  c4_statsOneObj.MinorAxisLength = 0.0;
  c4_statsAlreadyComputed->Eccentricity = false;
  c4_statsOneObj.Eccentricity = 0.0;
  c4_statsAlreadyComputed->Orientation = false;
  c4_statsOneObj.Orientation = 0.0;
  c4_statsAlreadyComputed->Image = false;
  c4_statsOneObj.Image.size[0] = 0;
  c4_statsOneObj.Image.size[1] = 0;
  c4_statsAlreadyComputed->FilledImage = false;
  c4_statsOneObj.FilledImage.size[0] = 0;
  c4_statsOneObj.FilledImage.size[1] = 0;
  c4_statsAlreadyComputed->FilledArea = false;
  c4_statsOneObj.FilledArea = 0.0;
  c4_statsAlreadyComputed->EulerNumber = false;
  c4_statsOneObj.EulerNumber = 0.0;
  c4_statsAlreadyComputed->Extrema = false;
  for (c4_i2 = 0; c4_i2 < 16; c4_i2++) {
    c4_statsOneObj.Extrema[c4_i2] = 0.0;
  }

  c4_statsAlreadyComputed->EquivDiameter = false;
  c4_statsOneObj.EquivDiameter = 0.0;
  c4_statsAlreadyComputed->Extent = false;
  c4_statsOneObj.Extent = 0.0;
  c4_statsAlreadyComputed->PixelIdxList = false;
  c4_statsOneObj.PixelIdxList->size[0] = 0;
  c4_statsAlreadyComputed->PixelList = false;
  c4_statsOneObj.PixelList->size[0] = 0;
  c4_statsOneObj.PixelList->size[1] = 2;
  c4_statsAlreadyComputed->Perimeter = false;
  c4_statsOneObj.Perimeter = 0.0;
  c4_statsAlreadyComputed->Circularity = false;
  c4_statsOneObj.Circularity = 0.0;
  c4_statsAlreadyComputed->PixelValues = false;
  c4_statsOneObj.PixelValues->size[0] = 0;
  c4_statsAlreadyComputed->WeightedCentroid = false;
  for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
    c4_statsOneObj.WeightedCentroid[c4_i3] = 0.0;
  }

  c4_statsAlreadyComputed->MeanIntensity = false;
  c4_statsOneObj.MeanIntensity = 0.0;
  c4_statsAlreadyComputed->MinIntensity = false;
  c4_statsOneObj.MinIntensity = 0.0;
  c4_statsAlreadyComputed->MaxIntensity = false;
  c4_statsOneObj.MaxIntensity = 0.0;
  c4_statsAlreadyComputed->SubarrayIdx = false;
  c4_statsOneObj.SubarrayIdx.size[0] = 1;
  c4_statsOneObj.SubarrayIdx.size[1] = 0;
  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    c4_statsOneObj.SubarrayIdxLengths[c4_i4] = 0.0;
  }

  c4_emxInit_boolean_T1(chartInstance, c4_sp, &c4_tile, 1, &c4_tf_emlrtRTEI);
  c4_st.site = &c4_bi_emlrtRSI;
  c4_d_varargin_1 = c4_numObjs;
  c4_b_st.site = &c4_ai_emlrtRSI;
  c4_assertValidSizeArg(chartInstance, &c4_b_st, c4_d_varargin_1);
  c4_i5 = c4_tile->size[0];
  c4_tile->size[0] = (int32_T)c4_d_varargin_1;
  c4_emxEnsureCapacity_boolean_T1(chartInstance, &c4_st, c4_tile, c4_i5,
    &c4_tf_emlrtRTEI);
  c4_loop_ub = (int32_T)c4_d_varargin_1 - 1;
  for (c4_i6 = 0; c4_i6 <= c4_loop_ub; c4_i6++) {
    c4_tile->data[c4_i6] = false;
  }

  c4_outsize[0] = c4_tile->size[0];
  if (!((real_T)c4_outsize[0] == (real_T)c4_tile->size[0])) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv4, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c4_st, &c4_o_emlrtMCI, "error", 0U, 1U, 14, c4_y);
  }

  c4_emxFree_boolean_T(chartInstance, &c4_tile);
  c4_i7 = c4_stats->size[0];
  c4_stats->size[0] = c4_outsize[0];
  c4_emxEnsureCapacity_s_nrlUwWofUDG(chartInstance, &c4_st, c4_stats, c4_i7,
    &c4_vf_emlrtRTEI);
  c4_b_loop_ub = c4_outsize[0] - 1;
  for (c4_i8 = 0; c4_i8 <= c4_b_loop_ub; c4_i8++) {
    c4_emxCopyStruct_s_nrlUwWofUDGxo1t(chartInstance, &c4_st, &c4_stats->
      data[c4_i8], &c4_statsOneObj, &c4_vf_emlrtRTEI);
  }

  c4_emxFreeStruct_s_nrlUwWofUDGxo1t(chartInstance, &c4_statsOneObj);
}

static void c4_ComputeWeightedCentroid(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_I[19200],
  c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_stats, c4_sHtk0WM4OMtyqkehwQYcq2
  c4_statsAlreadyComputed, c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_b_stats,
  c4_sHtk0WM4OMtyqkehwQYcq2 *c4_b_statsAlreadyComputed)
{
  real_T c4_b_I[19200];
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_loop_ub;
  c4_i = c4_b_stats->size[0];
  c4_b_stats->size[0] = c4_stats->size[0];
  c4_emxEnsureCapacity_s_nrlUwWofUDG(chartInstance, c4_sp, c4_b_stats, c4_i,
    &c4_xf_emlrtRTEI);
  c4_loop_ub = c4_stats->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_emxCopyStruct_s_nrlUwWofUDGxo1t(chartInstance, c4_sp, &c4_b_stats->
      data[c4_i1], &c4_stats->data[c4_i1], &c4_xf_emlrtRTEI);
  }

  *c4_b_statsAlreadyComputed = c4_statsAlreadyComputed;
  for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
    c4_b_I[c4_i2] = c4_I[c4_i2];
  }

  c4_b_ComputeWeightedCentroid(chartInstance, c4_sp, c4_b_I, c4_b_stats,
    c4_b_statsAlreadyComputed);
}

static real_T c4_b_sum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x)
{
  static char_T c4_b_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  real_T c4_y;
  int32_T c4_b_b;
  int32_T c4_b_vlen;
  int32_T c4_c_b;
  int32_T c4_ix;
  int32_T c4_k;
  int32_T c4_vlen;
  int32_T c4_xoffset;
  boolean_T c4_b;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_st.site = &c4_nh_emlrtRSI;
  if ((c4_c_x->size[0] == 1) || ((real_T)c4_c_x->size[0] != 1.0)) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c4_st, &c4_t_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_b_st.site = &c4_oh_emlrtRSI;
  c4_vlen = c4_c_x->size[0];
  if ((c4_c_x->size[0] == 0) || (c4_vlen == 0)) {
    c4_y = 0.0;
  } else {
    c4_c_st.site = &c4_ph_emlrtRSI;
    c4_b_vlen = c4_vlen;
    c4_y = c4_c_x->data[0];
    c4_d_st.site = &c4_qh_emlrtRSI;
    c4_b_b = c4_b_vlen;
    c4_c_b = c4_b_b;
    if (2 > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_e_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
    }

    for (c4_k = 1; c4_k < c4_b_vlen; c4_k++) {
      c4_xoffset = c4_k + 1;
      c4_ix = c4_xoffset - 1;
      c4_y += c4_c_x->data[c4_ix];
    }
  }

  return c4_y;
}

static void c4_round(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x,
                     c4_emxArray_real_T *c4_d_x)
{
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_i = c4_d_x->size[0];
  c4_d_x->size[0] = c4_c_x->size[0];
  c4_emxEnsureCapacity_real_T1(chartInstance, c4_sp, c4_d_x, c4_i,
    &c4_yf_emlrtRTEI);
  c4_loop_ub = c4_c_x->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x->data[c4_i1];
  }

  c4_b_round(chartInstance, c4_sp, c4_d_x);
}

static void c4_b_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x,
                      c4_emxArray_real_T *c4_d_x, c4_emxArray_int32_T *c4_b_idx)
{
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_loop_ub;
  c4_i = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = c4_c_x->size[0];
  c4_d_x->size[1] = 1;
  c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_d_x, c4_i,
    &c4_kd_emlrtRTEI);
  c4_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x->data[c4_i1];
  }

  c4_d_sort(chartInstance, c4_sp, c4_d_x, c4_b_idx);
}

static void c4_b_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real_T *c4_c_x, int32_T c4_offset, c4_emxArray_int32_T *c4_c_idx,
  c4_emxArray_real_T *c4_d_x)
{
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  c4_i = c4_c_idx->size[0] * c4_c_idx->size[1];
  c4_c_idx->size[0] = c4_b_idx->size[0];
  c4_c_idx->size[1] = 1;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_c_idx, c4_i,
    &c4_ld_emlrtRTEI);
  c4_loop_ub = c4_b_idx->size[0] * c4_b_idx->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_c_idx->data[c4_i1] = c4_b_idx->data[c4_i1];
  }

  c4_i2 = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = c4_c_x->size[0];
  c4_d_x->size[1] = 1;
  c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_d_x, c4_i2,
    &c4_ld_emlrtRTEI);
  c4_b_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_d_x->data[c4_i3] = c4_c_x->data[c4_i3];
  }

  c4_d_merge_pow2_block(chartInstance, c4_sp, c4_c_idx, c4_d_x, c4_offset);
}

static void c4_b_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real_T *c4_c_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real_T *c4_xwork,
  c4_emxArray_int32_T *c4_c_idx, c4_emxArray_real_T *c4_d_x, c4_emxArray_int32_T
  *c4_c_iwork, c4_emxArray_real_T *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_loop_ub;
  c4_i = c4_c_idx->size[0] * c4_c_idx->size[1];
  c4_c_idx->size[0] = c4_b_idx->size[0];
  c4_c_idx->size[1] = 1;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_c_idx, c4_i,
    &c4_md_emlrtRTEI);
  c4_loop_ub = c4_b_idx->size[0] * c4_b_idx->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_c_idx->data[c4_i1] = c4_b_idx->data[c4_i1];
  }

  c4_i2 = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = c4_c_x->size[0];
  c4_d_x->size[1] = 1;
  c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_d_x, c4_i2,
    &c4_md_emlrtRTEI);
  c4_b_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_d_x->data[c4_i3] = c4_c_x->data[c4_i3];
  }

  c4_i4 = c4_c_iwork->size[0];
  c4_c_iwork->size[0] = c4_b_iwork->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_c_iwork, c4_i4,
    &c4_md_emlrtRTEI);
  c4_c_loop_ub = c4_b_iwork->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_c_iwork->data[c4_i5] = c4_b_iwork->data[c4_i5];
  }

  c4_i6 = c4_b_xwork->size[0];
  c4_b_xwork->size[0] = c4_xwork->size[0];
  c4_emxEnsureCapacity_real_T1(chartInstance, c4_sp, c4_b_xwork, c4_i6,
    &c4_md_emlrtRTEI);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b_xwork->data[c4_i7] = c4_xwork->data[c4_i7];
  }

  c4_d_merge_block(chartInstance, c4_sp, c4_c_idx, c4_d_x, c4_offset, c4_n,
                   c4_preSortLevel, c4_c_iwork, c4_b_xwork);
}

static void c4_b_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real_T
  *c4_c_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T *
  c4_b_iwork, c4_emxArray_real_T *c4_xwork, c4_emxArray_int32_T *c4_c_idx,
  c4_emxArray_real_T *c4_d_x, c4_emxArray_int32_T *c4_c_iwork,
  c4_emxArray_real_T *c4_b_xwork)
{
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_loop_ub;
  c4_i = c4_c_idx->size[0] * c4_c_idx->size[1];
  c4_c_idx->size[0] = c4_b_idx->size[0];
  c4_c_idx->size[1] = 1;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_c_idx, c4_i,
    &c4_nd_emlrtRTEI);
  c4_loop_ub = c4_b_idx->size[0] * c4_b_idx->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_c_idx->data[c4_i1] = c4_b_idx->data[c4_i1];
  }

  c4_i2 = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = c4_c_x->size[0];
  c4_d_x->size[1] = 1;
  c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, c4_d_x, c4_i2,
    &c4_nd_emlrtRTEI);
  c4_b_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_d_x->data[c4_i3] = c4_c_x->data[c4_i3];
  }

  c4_i4 = c4_c_iwork->size[0];
  c4_c_iwork->size[0] = c4_b_iwork->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_c_iwork, c4_i4,
    &c4_nd_emlrtRTEI);
  c4_c_loop_ub = c4_b_iwork->size[0] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_c_loop_ub; c4_i5++) {
    c4_c_iwork->data[c4_i5] = c4_b_iwork->data[c4_i5];
  }

  c4_i6 = c4_b_xwork->size[0];
  c4_b_xwork->size[0] = c4_xwork->size[0];
  c4_emxEnsureCapacity_real_T1(chartInstance, c4_sp, c4_b_xwork, c4_i6,
    &c4_nd_emlrtRTEI);
  c4_d_loop_ub = c4_xwork->size[0] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_b_xwork->data[c4_i7] = c4_xwork->data[c4_i7];
  }

  c4_d_merge(chartInstance, c4_sp, c4_c_idx, c4_d_x, c4_offset, c4_np, c4_nq,
             c4_c_iwork, c4_b_xwork);
}

static void c4_hough(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200],
                     real_T c4_h[71820])
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_cost[180];
  real_T c4_sint[180];
  real_T c4_tempBin[120];
  real_T c4_b_j;
  real_T c4_b_k;
  real_T c4_c_x;
  real_T c4_d_j;
  real_T c4_d_x;
  real_T c4_e_i;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_myRho;
  real_T c4_tempNum;
  int32_T c4_nonZeroPixelMatrix[19200];
  int32_T c4_rhoIdxVector[399];
  int32_T c4_numNonZeros[160];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_i;
  int32_T c4_b_thetaIdx;
  int32_T c4_c;
  int32_T c4_c_i;
  int32_T c4_c_j;
  int32_T c4_d_i;
  int32_T c4_f_i;
  int32_T c4_g_a;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_n;
  int32_T c4_rhoIdx;
  int32_T c4_thetaIdx;
  int32_T c4_y;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_dj_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  for (c4_i = 0; c4_i < 180; c4_i++) {
    c4_b_i = c4_i;
    c4_c_x = (-90.0 + (real_T)c4_b_i) * 3.1415926535897931 / 180.0;
    c4_d_x = c4_c_x;
    c4_d_x = muDoubleScalarCos(c4_d_x);
    c4_cost[c4_b_i] = c4_d_x;
    c4_e_x = (-90.0 + (real_T)c4_b_i) * 3.1415926535897931 / 180.0;
    c4_f_x = c4_e_x;
    c4_f_x = muDoubleScalarSin(c4_f_x);
    c4_sint[c4_b_i] = c4_f_x;
  }

  c4_b_st.site = &c4_ej_emlrtRSI;
  for (c4_j = 0; c4_j < 160; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    c4_tempNum = 0.0;
    for (c4_c_i = 0; c4_c_i < 120; c4_c_i++) {
      c4_e_i = (real_T)c4_c_i + 1.0;
      if (c4_d_varargin_1[((int32_T)c4_e_i + 120 * ((int32_T)c4_b_j - 1)) - 1])
      {
        c4_tempNum++;
        c4_i2 = (int32_T)c4_tempNum;
        c4_tempBin[emlrtDynamicBoundsCheckR2012b(c4_i2, 1, 120, &c4_ue_emlrtBCI,
          &c4_b_st) - 1] = c4_e_i;
      }
    }

    c4_numNonZeros[(int32_T)c4_b_j - 1] = (int32_T)c4_tempNum;
    c4_k = 0;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k < 120)) {
      c4_b_k = (real_T)c4_k + 1.0;
      if (c4_b_k > c4_tempNum) {
        c4_exitg1 = true;
      } else {
        c4_nonZeroPixelMatrix[((int32_T)c4_b_k + 120 * ((int32_T)c4_b_j - 1)) -
          1] = (int32_T)c4_tempBin[(int32_T)c4_b_k - 1];
        c4_k++;
      }
    }
  }

  for (c4_thetaIdx = 0; c4_thetaIdx < 180; c4_thetaIdx++) {
    c4_b_thetaIdx = c4_thetaIdx;
    for (c4_d_i = 0; c4_d_i < 399; c4_d_i++) {
      c4_rhoIdxVector[c4_d_i] = 0;
    }

    for (c4_c_j = 0; c4_c_j < 160; c4_c_j++) {
      c4_d_j = (real_T)c4_c_j + 1.0;
      c4_i3 = c4_numNonZeros[(int32_T)c4_d_j - 1];
      c4_b_st.site = &c4_fj_emlrtRSI;
      c4_b = c4_i3;
      c4_b_b = c4_b;
      if (1 > c4_b_b) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_b_b > 2147483646);
      }

      if (c4_overflow) {
        c4_c_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_f_i = 1; c4_f_i - 1 < c4_i3; c4_f_i++) {
        c4_b_i = c4_f_i - 1;
        c4_n = c4_nonZeroPixelMatrix[c4_b_i + 120 * ((int32_T)c4_d_j - 1)];
        c4_myRho = (c4_d_j - 1.0) * c4_cost[c4_b_thetaIdx] + ((real_T)c4_n - 1.0)
          * c4_sint[c4_b_thetaIdx];
        c4_g_x = c4_myRho - -199.0;
        c4_y = (int32_T)(c4_g_x + 0.5) + 1;
        c4_rhoIdx = c4_y;
        c4_g_a = c4_rhoIdxVector[emlrtDynamicBoundsCheckR2012b(c4_rhoIdx, 1, 399,
          &c4_ve_emlrtBCI, &c4_st) - 1] + 1;
        c4_c = c4_g_a;
        c4_rhoIdxVector[emlrtDynamicBoundsCheckR2012b(c4_rhoIdx, 1, 399,
          &c4_te_emlrtBCI, &c4_st) - 1] = c4_c;
      }
    }

    for (c4_i1 = 0; c4_i1 < 399; c4_i1++) {
      c4_h[c4_i1 + 399 * c4_b_thetaIdx] = (real_T)c4_rhoIdxVector[c4_i1];
    }
  }
}

static real_T c4_c_maximum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_x[71820])
{
  c4_emxArray_real_T *c4_d_x;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  real_T c4_b_ex;
  real_T c4_e_x;
  real_T c4_ex;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  int32_T c4_b_b;
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_b_n;
  int32_T c4_c_b;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_first;
  int32_T c4_g_a;
  int32_T c4_h_a;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_k;
  int32_T c4_last;
  int32_T c4_n;
  boolean_T c4_b;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_d_x, 1, &c4_emlrtRTEI);
  c4_st.site = &c4_ub_emlrtRSI;
  c4_b_st.site = &c4_vb_emlrtRSI;
  c4_i = c4_d_x->size[0];
  c4_d_x->size[0] = 71820;
  c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_d_x, c4_i,
    &c4_emlrtRTEI);
  for (c4_i1 = 0; c4_i1 < 71820; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x[c4_i1];
  }

  c4_c_st.site = &c4_ib_emlrtRSI;
  c4_n = c4_d_x->size[0];
  c4_d_st.site = &c4_kb_emlrtRSI;
  c4_b_n = c4_d_x->size[0];
  c4_e_x = c4_d_x->data[0];
  c4_f_x = c4_e_x;
  c4_b = muDoubleScalarIsNaN(c4_f_x);
  c4_p = !c4_b;
  if (c4_p) {
    c4_b_idx = 1;
  } else {
    c4_b_idx = 0;
    c4_e_st.site = &c4_lb_emlrtRSI;
    c4_b_b = c4_b_n;
    c4_c_b = c4_b_b;
    if (2 > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_f_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
    }

    c4_k = 2;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k <= c4_b_n)) {
      c4_g_x = c4_d_x->data[c4_k - 1];
      c4_h_x = c4_g_x;
      c4_f_b = muDoubleScalarIsNaN(c4_h_x);
      c4_b_p = !c4_f_b;
      if (c4_b_p) {
        c4_b_idx = c4_k;
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }
  }

  if (c4_b_idx == 0) {
    c4_ex = c4_d_x->data[0];
  } else {
    c4_d_st.site = &c4_jb_emlrtRSI;
    c4_first = c4_b_idx - 1;
    c4_last = c4_n;
    c4_b_ex = c4_d_x->data[c4_first];
    c4_i2 = c4_first + 2;
    c4_e_st.site = &c4_nb_emlrtRSI;
    c4_g_a = c4_i2;
    c4_d_b = c4_last;
    c4_h_a = c4_g_a;
    c4_e_b = c4_d_b;
    if (c4_h_a > c4_e_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_e_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_f_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
    }

    for (c4_b_k = c4_i2 - 1; c4_b_k < c4_last; c4_b_k++) {
      if (c4_b_ex < c4_d_x->data[c4_b_k]) {
        c4_b_ex = c4_d_x->data[c4_b_k];
      }
    }

    c4_ex = c4_b_ex;
  }

  c4_emxFree_real_T(chartInstance, &c4_d_x);
  return c4_ex;
}

static void c4_houghpeaks(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_d_varargin_1[71820], real_T c4_varargin_4,
  c4_emxArray_real_T *c4_peaks)
{
  static char_T c4_b_cv5[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e' };

  static char_T c4_cv8[43] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'h', 'e', 't', 'a', 'V', 'e', 'c', 't', 'o', 'r', 'S', 'p', 'a', 'c',
    'i', 'n', 'g' };

  static char_T c4_b_cv4[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'N', 'o', 'n', 'n', 'e', 'g', 'a', 't', 'i', 'v', 'e' };

  static char_T c4_b_cv2[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c4_b_cv[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  static char_T c4_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  static char_T c4_b_cv3[9] = { 'T', 'h', 'r', 'e', 's', 'h', 'o', 'l', 'd' };

  static char_T c4_b_cv6[9] = { 'T', 'h', 'r', 'e', 's', 'h', 'o', 'l', 'd' };

  static char_T c4_b_cv7[5] = { 'T', 'h', 'e', 't', 'a' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_m_y = NULL;
  const mxArray *c4_n_y = NULL;
  const mxArray *c4_o_y = NULL;
  const mxArray *c4_r_y = NULL;
  const mxArray *c4_s_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_dv1[180];
  real_T c4_b_dv2[180];
  real_T c4_dv3[180];
  real_T c4_dv4[180];
  real_T c4_dv5[180];
  real_T c4_thetaInterval[179];
  real_T c4_r_x[178];
  real_T c4_b_dv[2];
  real_T c4_ab_x;
  real_T c4_b_k;
  real_T c4_b_threshold;
  real_T c4_b_varargin_2;
  real_T c4_b_varargin_4;
  real_T c4_bb_x;
  real_T c4_c_threshold;
  real_T c4_c_varargin_2;
  real_T c4_c_x;
  real_T c4_d_k;
  real_T c4_d_varargin_2;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_k;
  real_T c4_f_x;
  real_T c4_g_a;
  real_T c4_g_x;
  real_T c4_h_a;
  real_T c4_h_x;
  real_T c4_i_a;
  real_T c4_i_x;
  real_T c4_j_a;
  real_T c4_j_x;
  real_T c4_k_a;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_maxTheta;
  real_T c4_maxVal;
  real_T c4_minTheta;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_p_y;
  real_T c4_q_x;
  real_T c4_q_y;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_t_y;
  real_T c4_thetaResolution;
  real_T c4_threshold;
  real_T c4_u_x;
  real_T c4_u_y;
  real_T c4_v_x;
  real_T c4_val;
  real_T c4_w_x;
  real_T c4_x_x;
  real_T c4_y_x;
  int32_T c4_b_i;
  int32_T c4_b_j;
  int32_T c4_c_i;
  int32_T c4_c_k;
  int32_T c4_e_k;
  int32_T c4_g_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_iPeak;
  int32_T c4_ix;
  int32_T c4_j;
  int32_T c4_jPeak;
  int32_T c4_k;
  int32_T c4_l_a;
  int32_T c4_l_b;
  int32_T c4_loop_ub;
  int32_T c4_m_a;
  int32_T c4_m_b;
  int32_T c4_n_a;
  int32_T c4_n_b;
  int32_T c4_o_a;
  int32_T c4_o_b;
  int32_T c4_peakIdx;
  int32_T c4_rho;
  int32_T c4_rhoMax;
  int32_T c4_rhoMin;
  int32_T c4_rhoToRemove;
  int32_T c4_theta;
  int32_T c4_thetaMax;
  int32_T c4_thetaMin;
  int32_T c4_thetaToRemove;
  int32_T c4_xoffset;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b10;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b8;
  boolean_T c4_b9;
  boolean_T c4_b_b;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_d_p;
  boolean_T c4_e_b;
  boolean_T c4_e_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_f_p;
  boolean_T c4_g_b;
  boolean_T c4_g_p;
  boolean_T c4_h_b;
  boolean_T c4_h_p;
  boolean_T c4_i_b;
  boolean_T c4_i_p;
  boolean_T c4_isDone;
  boolean_T c4_isThetaAntisymmetric;
  boolean_T c4_j_b;
  boolean_T c4_k_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_st.site = &c4_kj_emlrtRSI;
  c4_b_varargin_4 = c4_varargin_4;
  c4_b_st.site = &c4_lj_emlrtRSI;
  c4_c_st.site = &c4_u_emlrtRSI;
  c4_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 71820)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_c_x = c4_d_varargin_1[(int32_T)c4_b_k - 1];
    c4_d_x = c4_c_x;
    c4_b_b = muDoubleScalarIsInf(c4_d_x);
    c4_b1 = !c4_b_b;
    c4_e_x = c4_c_x;
    c4_c_b = muDoubleScalarIsNaN(c4_e_x);
    c4_b2 = !c4_c_b;
    c4_d_b = (c4_b1 && c4_b2);
    if (c4_d_b) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv5, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c4_c_st, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_c_st.site = &c4_u_emlrtRSI;
  c4_b_p = true;
  c4_c_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_k < 71820)) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    c4_f_x = c4_d_varargin_1[(int32_T)c4_d_k - 1];
    c4_g_x = c4_f_x;
    c4_h_x = c4_g_x;
    c4_e_b = muDoubleScalarIsInf(c4_h_x);
    c4_b4 = !c4_e_b;
    c4_i_x = c4_g_x;
    c4_f_b = muDoubleScalarIsNaN(c4_i_x);
    c4_b5 = !c4_f_b;
    c4_g_b = (c4_b4 && c4_b5);
    if (c4_g_b) {
      c4_j_x = c4_f_x;
      c4_k_x = c4_j_x;
      c4_k_x = muDoubleScalarFloor(c4_k_x);
      if (c4_k_x == c4_f_x) {
        c4_c_p = true;
      } else {
        c4_c_p = false;
      }
    } else {
      c4_c_p = false;
    }

    c4_d_p = c4_c_p;
    if (c4_d_p) {
      c4_c_k++;
    } else {
      c4_b_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_b_p) {
    c4_b3 = true;
  } else {
    c4_b3 = false;
  }

  if (!c4_b3) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv6, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv7, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c4_c_st, &c4_y_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_c_st, NULL, "message", 1U, 2U, 14, c4_e_y, 14, c4_f_y)));
  }

  c4_b_varargin_2 = c4_b_varargin_4;
  c4_c_varargin_2 = c4_b_varargin_2;
  c4_d_varargin_2 = c4_c_varargin_2;
  c4_threshold = c4_d_varargin_2;
  c4_b_threshold = c4_threshold;
  c4_b_st.site = &c4_mj_emlrtRSI;
  c4_c_threshold = c4_threshold;
  c4_c_st.site = &c4_pj_emlrtRSI;
  c4_g_a = c4_c_threshold;
  c4_d_st.site = &c4_u_emlrtRSI;
  c4_h_a = c4_g_a;
  c4_i_a = c4_h_a;
  c4_e_p = true;
  c4_l_x = c4_i_a;
  c4_m_x = c4_l_x;
  c4_h_b = muDoubleScalarIsNaN(c4_m_x);
  c4_f_p = !c4_h_b;
  if (!c4_f_p) {
    c4_e_p = false;
  }

  if (c4_e_p) {
    c4_b6 = true;
  } else {
    c4_b6 = false;
  }

  if (!c4_b6) {
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c4_h_y = NULL;
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_i_y = NULL;
    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c4_d_st, &c4_m_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_d_st, NULL, "message", 1U, 2U, 14, c4_h_y, 14, c4_i_y)));
  }

  c4_d_st.site = &c4_u_emlrtRSI;
  c4_j_a = c4_g_a;
  c4_k_a = c4_j_a;
  c4_g_p = true;
  c4_n_x = c4_k_a;
  c4_h_p = !(c4_n_x < 0.0);
  if (!c4_h_p) {
    c4_g_p = false;
  }

  if (c4_g_p) {
    c4_b7 = true;
  } else {
    c4_b7 = false;
  }

  if (!c4_b7) {
    c4_j_y = NULL;
    sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_b_cv4, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c4_k_y = NULL;
    sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_b_cv5, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c4_l_y = NULL;
    sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_b_cv6, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c4_d_st, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_j_y, 14,
                sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_d_st, NULL, "message", 1U, 2U, 14, c4_k_y, 14, c4_l_y)));
  }

  c4_b_st.site = &c4_nj_emlrtRSI;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_b_dv[c4_i] = 9.0 + -4.0 * (real_T)c4_i;
  }

  c4_c_st.site = &c4_qj_emlrtRSI;
  c4_b_validateattributes(chartInstance, &c4_c_st, c4_b_dv);
  c4_b_st.site = &c4_oj_emlrtRSI;
  c4_c_st.site = &c4_uj_emlrtRSI;
  c4_d_st.site = &c4_u_emlrtRSI;
  c4_i_p = true;
  c4_e_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_e_k < 180)) {
    c4_f_k = (real_T)c4_e_k + 1.0;
    c4_o_x = -90.0 + (real_T)((int32_T)c4_f_k - 1);
    c4_p_x = c4_o_x;
    c4_i_b = muDoubleScalarIsInf(c4_p_x);
    c4_b9 = !c4_i_b;
    c4_q_x = c4_o_x;
    c4_j_b = muDoubleScalarIsNaN(c4_q_x);
    c4_b10 = !c4_j_b;
    c4_k_b = (c4_b9 && c4_b10);
    if (c4_k_b) {
      c4_e_k++;
    } else {
      c4_i_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_i_p) {
    c4_b8 = true;
  } else {
    c4_b8 = false;
  }

  if (!c4_b8) {
    c4_m_y = NULL;
    sf_mex_assign(&c4_m_y, sf_mex_create("y", c4_cv5, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c4_n_y = NULL;
    sf_mex_assign(&c4_n_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_o_y = NULL;
    sf_mex_assign(&c4_o_y, sf_mex_create("y", c4_b_cv7, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c4_d_st, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_m_y, 14,
                sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_d_st, NULL, "message", 1U, 2U, 14, c4_n_y, 14, c4_o_y)));
  }

  c4_c_st.site = &c4_tj_emlrtRSI;
  c4_d_st.site = &c4_nd_emlrtRSI;
  for (c4_i1 = 0; c4_i1 < 180; c4_i1++) {
    c4_b_dv1[c4_i1] = -90.0 + (real_T)c4_i1;
  }

  c4_e_st.site = &c4_od_emlrtRSI;
  c4_b_minimum(chartInstance, &c4_e_st, c4_b_dv1);
  c4_c_st.site = &c4_sj_emlrtRSI;
  c4_d_st.site = &c4_sb_emlrtRSI;
  for (c4_i2 = 0; c4_i2 < 180; c4_i2++) {
    c4_b_dv2[c4_i2] = -90.0 + (real_T)c4_i2;
  }

  c4_e_st.site = &c4_tb_emlrtRSI;
  c4_d_maximum(chartInstance, &c4_e_st, c4_b_dv2);
  for (c4_i3 = 0; c4_i3 < 180; c4_i3++) {
    c4_dv3[c4_i3] = -90.0 + (real_T)c4_i3;
  }

  c4_diff(chartInstance, c4_dv3, c4_thetaInterval);
  c4_c_st.site = &c4_rj_emlrtRSI;
  c4_b_diff(chartInstance, c4_thetaInterval, c4_r_x);
  c4_p_y = c4_r_x[0];
  for (c4_g_k = 0; c4_g_k < 177; c4_g_k++) {
    c4_xoffset = c4_g_k;
    c4_ix = c4_xoffset;
    c4_p_y += c4_r_x[c4_ix + 1];
  }

  c4_s_x = c4_p_y;
  c4_t_x = c4_s_x;
  c4_u_x = c4_t_x;
  c4_q_y = muDoubleScalarAbs(c4_u_x);
  if (c4_q_y > 1.4901161193847656E-8) {
    c4_r_y = NULL;
    sf_mex_assign(&c4_r_y, sf_mex_create("y", c4_cv8, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c4_s_y = NULL;
    sf_mex_assign(&c4_s_y, sf_mex_create("y", c4_cv8, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    sf_mex_call(&c4_b_st, &c4_db_emlrtMCI, "error", 0U, 2U, 14, c4_r_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 1U, 14, c4_s_y)));
  }

  c4_isDone = false;
  for (c4_i4 = 0; c4_i4 < 71820; c4_i4++) {
    chartInstance->c4_hnew[c4_i4] = c4_d_varargin_1[c4_i4];
  }

  c4_peakIdx = 0;
  c4_st.site = &c4_jj_emlrtRSI;
  c4_b_st.site = &c4_nd_emlrtRSI;
  for (c4_i5 = 0; c4_i5 < 180; c4_i5++) {
    c4_dv4[c4_i5] = -90.0 + (real_T)c4_i5;
  }

  c4_c_st.site = &c4_od_emlrtRSI;
  c4_minTheta = c4_b_minimum(chartInstance, &c4_c_st, c4_dv4);
  c4_st.site = &c4_ij_emlrtRSI;
  c4_b_st.site = &c4_sb_emlrtRSI;
  for (c4_i6 = 0; c4_i6 < 180; c4_i6++) {
    c4_dv5[c4_i6] = -90.0 + (real_T)c4_i6;
  }

  c4_c_st.site = &c4_tb_emlrtRSI;
  c4_maxTheta = c4_d_maximum(chartInstance, &c4_c_st, c4_dv5);
  c4_v_x = c4_maxTheta - c4_minTheta;
  c4_w_x = c4_v_x;
  c4_x_x = c4_w_x;
  c4_t_y = muDoubleScalarAbs(c4_x_x);
  c4_thetaResolution = c4_t_y / 179.0;
  c4_y_x = c4_minTheta + c4_thetaResolution * 5.0;
  c4_ab_x = c4_y_x;
  c4_bb_x = c4_ab_x;
  c4_u_y = muDoubleScalarAbs(c4_bb_x);
  c4_isThetaAntisymmetric = (c4_u_y <= c4_maxTheta);
  while (!c4_isDone) {
    c4_iPeak = 0;
    c4_jPeak = 0;
    c4_maxVal = -1.0;
    for (c4_j = 0; c4_j < 180; c4_j++) {
      c4_b_j = c4_j;
      for (c4_b_i = 0; c4_b_i < 399; c4_b_i++) {
        c4_c_i = c4_b_i;
        c4_val = chartInstance->c4_hnew[c4_c_i + 399 * c4_b_j];
        if (c4_val > c4_maxVal) {
          c4_iPeak = c4_c_i + 1;
          c4_jPeak = c4_b_j + 1;
          c4_maxVal = c4_val;
        }
      }
    }

    if (chartInstance->c4_hnew[(emlrtDynamicBoundsCheckR2012b(c4_iPeak, 1, 399,
          &c4_xe_emlrtBCI, c4_sp) + 399 * (emlrtDynamicBoundsCheckR2012b
          (c4_jPeak, 1, 180, &c4_ye_emlrtBCI, c4_sp) - 1)) - 1] >=
        c4_b_threshold) {
      c4_peakIdx++;
      chartInstance->c4_peakCoordinates[emlrtDynamicBoundsCheckR2012b(c4_peakIdx,
        1, 71820, &c4_we_emlrtBCI, c4_sp) - 1] = (real_T)c4_iPeak;
      chartInstance->c4_peakCoordinates[c4_peakIdx + 71819] = (real_T)c4_jPeak;
      c4_rhoMin = c4_iPeak - 4;
      c4_rhoMax = c4_iPeak + 4;
      c4_thetaMin = c4_jPeak - 2;
      c4_thetaMax = c4_jPeak + 2;
      if (c4_rhoMin < 1) {
        c4_rhoMin = 1;
      }

      if (c4_rhoMax > 399) {
        c4_rhoMax = 399;
      }

      c4_st.site = &c4_hj_emlrtRSI;
      c4_l_a = c4_thetaMin;
      c4_l_b = c4_thetaMax;
      c4_m_a = c4_l_a;
      c4_m_b = c4_l_b;
      if (c4_m_a > c4_m_b) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_m_b > 2147483646);
      }

      if (c4_overflow) {
        c4_b_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      for (c4_theta = c4_thetaMin; c4_theta <= c4_thetaMax; c4_theta++) {
        c4_st.site = &c4_gj_emlrtRSI;
        c4_n_a = c4_rhoMin;
        c4_n_b = c4_rhoMax;
        c4_o_a = c4_n_a;
        c4_o_b = c4_n_b;
        if (c4_o_a > c4_o_b) {
          c4_b_overflow = false;
        } else {
          c4_b_overflow = (c4_o_b > 2147483646);
        }

        if (c4_b_overflow) {
          c4_b_st.site = &c4_mb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
        }

        for (c4_rho = c4_rhoMin; c4_rho <= c4_rhoMax; c4_rho++) {
          c4_rhoToRemove = c4_rho;
          c4_thetaToRemove = c4_theta;
          if (c4_isThetaAntisymmetric) {
            if (c4_theta > 180) {
              c4_rhoToRemove = 400 - c4_rho;
              c4_thetaToRemove = c4_theta - 180;
            } else {
              if (c4_theta < 1) {
                c4_rhoToRemove = 400 - c4_rho;
                c4_thetaToRemove = c4_theta + 180;
              }
            }
          }

          if ((c4_thetaToRemove > 180) || (c4_thetaToRemove < 1)) {
          } else {
            chartInstance->c4_hnew[(c4_rhoToRemove + 399 * (c4_thetaToRemove - 1))
              - 1] = 0.0;
          }
        }
      }

      c4_isDone = (c4_peakIdx == 5);
    } else {
      c4_isDone = true;
    }
  }

  if (c4_peakIdx == 0) {
    c4_peaks->size[0] = 0;
    c4_peaks->size[1] = 0;
  } else {
    c4_i7 = c4_peakIdx - 1;
    c4_i8 = c4_peaks->size[0] * c4_peaks->size[1];
    c4_peaks->size[0] = c4_i7 + 1;
    c4_peaks->size[1] = 2;
    c4_st.site = &c4_vk_emlrtRSI;
    c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_peaks, c4_i8,
      &c4_ag_emlrtRTEI);
    for (c4_i9 = 0; c4_i9 < 2; c4_i9++) {
      c4_loop_ub = c4_i7;
      for (c4_i10 = 0; c4_i10 <= c4_loop_ub; c4_i10++) {
        c4_peaks->data[c4_i10 + c4_peaks->size[0] * c4_i9] =
          chartInstance->c4_peakCoordinates[c4_i10 + 71820 * c4_i9];
      }
    }
  }
}

static void c4_b_validateattributes(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_g_a[2])
{
  static char_T c4_b_cv3[43] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'O', 'd', 'd' };

  static char_T c4_b_cv2[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
    'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't',
    'e', 'd', 'O', 'd', 'd' };

  static char_T c4_b_cv[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c4_b_cv1[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  static char_T c4_b_cv4[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_c_x;
  real_T c4_d_k;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_k;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_r;
  real_T c4_r_x;
  int32_T c4_c_k;
  int32_T c4_e_k;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_d_p;
  boolean_T c4_e_b;
  boolean_T c4_e_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_b;
  boolean_T c4_f_p;
  boolean_T c4_g_b;
  boolean_T c4_h_b;
  boolean_T c4_i_b;
  boolean_T c4_p;
  boolean_T c4_rEQ0;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_u_emlrtRSI;
  c4_p = true;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k < 2)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_c_x = c4_g_a[(int32_T)c4_b_k - 1];
    c4_d_x = c4_c_x;
    c4_b_b = muDoubleScalarIsInf(c4_d_x);
    c4_b1 = !c4_b_b;
    c4_e_x = c4_c_x;
    c4_c_b = muDoubleScalarIsNaN(c4_e_x);
    c4_b2 = !c4_c_b;
    c4_d_b = (c4_b1 && c4_b2);
    if (c4_d_b) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv5, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c4_st, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14, sf_mex_call
                (&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(&c4_st, NULL,
      "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }

  c4_st.site = &c4_u_emlrtRSI;
  c4_b_p = true;
  c4_c_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_k < 2)) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    c4_f_x = c4_g_a[(int32_T)c4_d_k - 1];
    c4_g_x = c4_f_x;
    c4_h_x = c4_g_x;
    c4_e_b = muDoubleScalarIsInf(c4_h_x);
    c4_b4 = !c4_e_b;
    c4_i_x = c4_g_x;
    c4_f_b = muDoubleScalarIsNaN(c4_i_x);
    c4_b5 = !c4_f_b;
    c4_g_b = (c4_b4 && c4_b5);
    if (c4_g_b) {
      c4_j_x = c4_f_x;
      c4_k_x = c4_j_x;
      c4_k_x = muDoubleScalarFloor(c4_k_x);
      if (c4_k_x == c4_f_x) {
        c4_d_p = true;
      } else {
        c4_d_p = false;
      }
    } else {
      c4_d_p = false;
    }

    c4_e_p = c4_d_p;
    if (c4_e_p) {
      c4_c_k++;
    } else {
      c4_b_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_b_p) {
    c4_b3 = true;
  } else {
    c4_b3 = false;
  }

  if (!c4_b3) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv6, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv7, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c4_st, &c4_y_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_e_y, 14, c4_f_y)));
  }

  c4_st.site = &c4_u_emlrtRSI;
  c4_st.site = &c4_u_emlrtRSI;
  c4_c_p = true;
  c4_e_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_e_k < 2)) {
    c4_f_k = (real_T)c4_e_k + 1.0;
    c4_l_x = c4_g_a[(int32_T)c4_f_k - 1];
    c4_m_x = c4_l_x;
    c4_n_x = c4_m_x;
    c4_o_x = c4_n_x;
    c4_p_x = c4_o_x;
    c4_q_x = c4_p_x;
    c4_h_b = muDoubleScalarIsNaN(c4_q_x);
    if (c4_h_b) {
      c4_r = rtNaN;
    } else {
      c4_r_x = c4_p_x;
      c4_i_b = muDoubleScalarIsInf(c4_r_x);
      if (c4_i_b) {
        c4_r = rtNaN;
      } else {
        c4_r = muDoubleScalarRem(c4_p_x, 2.0);
        c4_rEQ0 = (c4_r == 0.0);
        if (c4_rEQ0) {
          c4_r = 0.0;
        }
      }
    }

    c4_f_p = (c4_r == 1.0);
    if (c4_f_p) {
      c4_e_k++;
    } else {
      c4_c_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_c_p) {
    c4_b6 = true;
  } else {
    c4_b6 = false;
  }

  if (!c4_b6) {
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_b_cv2, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c4_h_y = NULL;
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_b_cv3, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c4_i_y = NULL;
    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_b_cv4, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c4_st, &c4_cb_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_h_y, 14, c4_i_y)));
  }
}

static real_T c4_b_minimum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_x[180])
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  real_T c4_b_x_data[180];
  real_T c4_c_x_data[180];
  real_T c4_b_ex;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_ex;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  int32_T c4_x_size[2];
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_first;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_n;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_pd_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_b_st.site = &c4_qd_emlrtRSI;
  c4_x_size[0] = 1;
  c4_x_size[1] = 180;
  for (c4_i = 0; c4_i < 180; c4_i++) {
    c4_b_x_data[c4_i] = c4_c_x[c4_i];
  }

  c4_c_st.site = &c4_rd_emlrtRSI;
  c4_n = c4_x_size[1];
  if (c4_n <= 2) {
    if (c4_b_x_data[0] > c4_b_x_data[1]) {
      c4_ex = c4_b_x_data[1];
    } else {
      c4_d_x = c4_b_x_data[0];
      c4_b = muDoubleScalarIsNaN(c4_d_x);
      if (c4_b) {
        c4_f_x = c4_b_x_data[1];
        c4_b_b = muDoubleScalarIsNaN(c4_f_x);
        if (!c4_b_b) {
          c4_ex = c4_b_x_data[1];
        } else {
          c4_ex = c4_b_x_data[0];
        }
      } else {
        c4_ex = c4_b_x_data[0];
      }
    }
  } else {
    c4_d_st.site = &c4_kb_emlrtRSI;
    c4_loop_ub = c4_x_size[0] * c4_x_size[1] - 1;
    for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
      c4_c_x_data[c4_i1] = c4_b_x_data[c4_i1];
    }

    c4_e_x = c4_c_x_data[0];
    c4_g_x = c4_e_x;
    c4_c_b = muDoubleScalarIsNaN(c4_g_x);
    c4_p = !c4_c_b;
    if (c4_p) {
      c4_b_idx = 1;
    } else {
      c4_b_idx = 0;
      c4_e_st.site = &c4_lb_emlrtRSI;
      c4_k = 2;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_k < 181)) {
        c4_h_x = c4_c_x_data[c4_k - 1];
        c4_i_x = c4_h_x;
        c4_d_b = muDoubleScalarIsNaN(c4_i_x);
        c4_b_p = !c4_d_b;
        if (c4_b_p) {
          c4_b_idx = c4_k;
          c4_exitg1 = true;
        } else {
          c4_k++;
        }
      }
    }

    if (c4_b_idx == 0) {
      c4_ex = c4_b_x_data[0];
    } else {
      c4_d_st.site = &c4_jb_emlrtRSI;
      c4_b_loop_ub = c4_x_size[0] * c4_x_size[1] - 1;
      for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
        c4_c_x_data[c4_i2] = c4_b_x_data[c4_i2];
      }

      c4_first = c4_b_idx - 1;
      c4_b_ex = c4_c_x_data[c4_first];
      c4_i3 = c4_first;
      c4_e_st.site = &c4_nb_emlrtRSI;
      c4_overflow = false;
      if (c4_overflow) {
        c4_f_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
      }

      for (c4_b_k = c4_i3 + 1; c4_b_k + 1 < 181; c4_b_k++) {
        if (c4_b_ex > c4_c_x_data[c4_b_k]) {
          c4_b_ex = c4_c_x_data[c4_b_k];
        }
      }

      c4_ex = c4_b_ex;
    }
  }

  return c4_ex;
}

static real_T c4_d_maximum(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_x[180])
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  real_T c4_b_x_data[180];
  real_T c4_c_x_data[180];
  real_T c4_b_ex;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_ex;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  int32_T c4_x_size[2];
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_first;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_n;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_d_b;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_ub_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  c4_b_st.site = &c4_vb_emlrtRSI;
  c4_x_size[0] = 1;
  c4_x_size[1] = 180;
  for (c4_i = 0; c4_i < 180; c4_i++) {
    c4_b_x_data[c4_i] = c4_c_x[c4_i];
  }

  c4_c_st.site = &c4_ib_emlrtRSI;
  c4_n = c4_x_size[1];
  if (c4_n <= 2) {
    if (c4_b_x_data[0] < c4_b_x_data[1]) {
      c4_ex = c4_b_x_data[1];
    } else {
      c4_d_x = c4_b_x_data[0];
      c4_b = muDoubleScalarIsNaN(c4_d_x);
      if (c4_b) {
        c4_f_x = c4_b_x_data[1];
        c4_b_b = muDoubleScalarIsNaN(c4_f_x);
        if (!c4_b_b) {
          c4_ex = c4_b_x_data[1];
        } else {
          c4_ex = c4_b_x_data[0];
        }
      } else {
        c4_ex = c4_b_x_data[0];
      }
    }
  } else {
    c4_d_st.site = &c4_kb_emlrtRSI;
    c4_loop_ub = c4_x_size[0] * c4_x_size[1] - 1;
    for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
      c4_c_x_data[c4_i1] = c4_b_x_data[c4_i1];
    }

    c4_e_x = c4_c_x_data[0];
    c4_g_x = c4_e_x;
    c4_c_b = muDoubleScalarIsNaN(c4_g_x);
    c4_p = !c4_c_b;
    if (c4_p) {
      c4_b_idx = 1;
    } else {
      c4_b_idx = 0;
      c4_e_st.site = &c4_lb_emlrtRSI;
      c4_k = 2;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_k < 181)) {
        c4_h_x = c4_c_x_data[c4_k - 1];
        c4_i_x = c4_h_x;
        c4_d_b = muDoubleScalarIsNaN(c4_i_x);
        c4_b_p = !c4_d_b;
        if (c4_b_p) {
          c4_b_idx = c4_k;
          c4_exitg1 = true;
        } else {
          c4_k++;
        }
      }
    }

    if (c4_b_idx == 0) {
      c4_ex = c4_b_x_data[0];
    } else {
      c4_d_st.site = &c4_jb_emlrtRSI;
      c4_b_loop_ub = c4_x_size[0] * c4_x_size[1] - 1;
      for (c4_i2 = 0; c4_i2 <= c4_b_loop_ub; c4_i2++) {
        c4_c_x_data[c4_i2] = c4_b_x_data[c4_i2];
      }

      c4_first = c4_b_idx - 1;
      c4_b_ex = c4_c_x_data[c4_first];
      c4_i3 = c4_first;
      c4_e_st.site = &c4_nb_emlrtRSI;
      c4_overflow = false;
      if (c4_overflow) {
        c4_f_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_f_st);
      }

      for (c4_b_k = c4_i3 + 1; c4_b_k + 1 < 181; c4_b_k++) {
        if (c4_b_ex < c4_c_x_data[c4_b_k]) {
          c4_b_ex = c4_c_x_data[c4_b_k];
        }
      }

      c4_ex = c4_b_ex;
    }
  }

  return c4_ex;
}

static void c4_diff(SFc4_flightControlSystemInstanceStruct *chartInstance,
                    real_T c4_c_x[180], real_T c4_y[179])
{
  real_T c4_tmp1;
  real_T c4_tmp2;
  real_T c4_work;
  int32_T c4_ixLead;
  int32_T c4_iyLead;
  int32_T c4_m;
  (void)chartInstance;
  c4_ixLead = 1;
  c4_iyLead = 0;
  c4_work = c4_c_x[0];
  for (c4_m = 0; c4_m < 179; c4_m++) {
    c4_tmp1 = c4_c_x[c4_ixLead];
    c4_tmp2 = c4_work;
    c4_work = c4_tmp1;
    c4_tmp1 -= c4_tmp2;
    c4_ixLead++;
    c4_y[c4_iyLead] = c4_tmp1;
    c4_iyLead++;
  }
}

static void c4_b_diff(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      real_T c4_c_x[179], real_T c4_y[178])
{
  real_T c4_tmp1;
  real_T c4_tmp2;
  real_T c4_work;
  int32_T c4_ixLead;
  int32_T c4_iyLead;
  int32_T c4_m;
  (void)chartInstance;
  c4_ixLead = 1;
  c4_iyLead = 0;
  c4_work = c4_c_x[0];
  for (c4_m = 0; c4_m < 178; c4_m++) {
    c4_tmp1 = c4_c_x[c4_ixLead];
    c4_tmp2 = c4_work;
    c4_work = c4_tmp1;
    c4_tmp1 -= c4_tmp2;
    c4_ixLead++;
    c4_y[c4_iyLead] = c4_tmp1;
    c4_iyLead++;
  }
}

static void c4_houghlines(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_d_varargin_1[19200], c4_emxArray_real_T *
  c4_varargin_4, c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *c4_lines)
{
  static real_T c4_b_dv[399] = { -199.0, -198.0, -197.0, -196.0, -195.0, -194.0,
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

  static char_T c4_b_cv[30] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'P', 'E', 'A', 'K', 'S' };

  c4_emxArray_int32_T *c4_b_point1Array;
  c4_emxArray_int32_T *c4_b_point2Array;
  c4_emxArray_int32_T *c4_houghPix;
  c4_emxArray_int32_T *c4_point1Array;
  c4_emxArray_int32_T *c4_point2Array;
  c4_emxArray_int32_T *c4_r;
  c4_emxArray_real32_T *c4_b_rhoArray;
  c4_emxArray_real32_T *c4_b_thetaArray;
  c4_emxArray_real32_T *c4_rhoArray;
  c4_emxArray_real32_T *c4_thetaArray;
  c4_emxArray_real_T *c4_b_varargin_4;
  c4_emxArray_real_T *c4_distances2;
  c4_emxArray_real_T *c4_indices;
  c4_emxArray_real_T *c4_peaks;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_tempBin[120];
  real_T c4_sortingOrder[2];
  real_T c4_ab_x;
  real_T c4_b_j;
  real_T c4_b_n;
  real_T c4_b_numHoughPix;
  real_T c4_b_peakIdx;
  real_T c4_b_varargin_2;
  real_T c4_b_y;
  real_T c4_bb_x;
  real_T c4_c_i;
  real_T c4_c_k;
  real_T c4_c_varargin_2;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_cb_x;
  real_T c4_colMax;
  real_T c4_colMin;
  real_T c4_colRange;
  real_T c4_cosTheta;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d_varargin_2;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_db_x;
  real_T c4_e_varargin_1;
  real_T c4_e_varargin_2;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_i;
  real_T c4_f_varargin_1;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_k;
  real_T c4_g_varargin_1;
  real_T c4_g_x;
  real_T c4_g_y;
  real_T c4_h_varargin_1;
  real_T c4_h_x;
  real_T c4_h_y;
  real_T c4_i_x;
  real_T c4_i_y;
  real_T c4_j_k;
  real_T c4_j_x;
  real_T c4_j_y;
  real_T c4_k_x;
  real_T c4_k_y;
  real_T c4_l_x;
  real_T c4_l_y;
  real_T c4_m_k;
  real_T c4_m_x;
  real_T c4_m_y;
  real_T c4_n;
  real_T c4_n_x;
  real_T c4_n_y;
  real_T c4_numPairs;
  real_T c4_numPeaks;
  real_T c4_o_x;
  real_T c4_o_y;
  real_T c4_p_x;
  real_T c4_p_y;
  real_T c4_q_x;
  real_T c4_q_y;
  real_T c4_r_x;
  real_T c4_r_y;
  real_T c4_rhoVal;
  real_T c4_rowMax;
  real_T c4_rowMin;
  real_T c4_rowRange;
  real_T c4_s_x;
  real_T c4_s_y;
  real_T c4_sinTheta;
  real_T c4_t_x;
  real_T c4_t_y;
  real_T c4_tempNum;
  real_T c4_thetaVal;
  real_T c4_u_x;
  real_T c4_u_y;
  real_T c4_v_x;
  real_T c4_v_y;
  real_T c4_w_x;
  real_T c4_w_y;
  real_T c4_x_x;
  real_T c4_x_y;
  real_T c4_y;
  real_T c4_y_x;
  int32_T c4_houghPixTemp[19200];
  int32_T c4_nonZeroPixelMatrix[19200];
  int32_T c4_tempHoughPixNumsVector[160];
  int32_T c4_tempNumsVector[160];
  int32_T c4_b_tempBin[120];
  int32_T c4_point1_data[2];
  int32_T c4_point1_size[2];
  int32_T c4_point2_data[2];
  int32_T c4_point2_size[2];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_b_indices;
  int32_T c4_b_k;
  int32_T c4_b_lines;
  int32_T c4_b_loop_ub;
  int32_T c4_b_numLines;
  int32_T c4_b_peak1;
  int32_T c4_b_peak2;
  int32_T c4_b_tempNum;
  int32_T c4_c;
  int32_T c4_c_b;
  int32_T c4_c_c;
  int32_T c4_c_indices;
  int32_T c4_c_j;
  int32_T c4_c_lines;
  int32_T c4_c_loop_ub;
  int32_T c4_c_numLines;
  int32_T c4_d_b;
  int32_T c4_d_c;
  int32_T c4_d_i;
  int32_T c4_d_j;
  int32_T c4_d_k;
  int32_T c4_d_loop_ub;
  int32_T c4_e_b;
  int32_T c4_e_i;
  int32_T c4_e_j;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_f_loop_ub;
  int32_T c4_g_a;
  int32_T c4_g_loop_ub;
  int32_T c4_h_a;
  int32_T c4_h_k;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i9;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i_a;
  int32_T c4_i_k;
  int32_T c4_i_loop_ub;
  int32_T c4_j;
  int32_T c4_j_a;
  int32_T c4_j_loop_ub;
  int32_T c4_k;
  int32_T c4_k_k;
  int32_T c4_k_loop_ub;
  int32_T c4_l_k;
  int32_T c4_l_loop_ub;
  int32_T c4_lineLength2;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n_loop_ub;
  int32_T c4_numHoughPix;
  int32_T c4_numLines;
  int32_T c4_peak1;
  int32_T c4_peak2;
  int32_T c4_peakIdx;
  int32_T c4_rhoBinIdx;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_exitg1;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_emxInit_real_T(chartInstance, c4_sp, &c4_b_varargin_4, 2, &c4_bg_emlrtRTEI);
  c4_st.site = &c4_vj_emlrtRSI;
  c4_i = c4_b_varargin_4->size[0] * c4_b_varargin_4->size[1];
  c4_b_varargin_4->size[0] = c4_varargin_4->size[0];
  c4_b_varargin_4->size[1] = c4_varargin_4->size[1];
  c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_b_varargin_4, c4_i,
    &c4_bg_emlrtRTEI);
  c4_loop_ub = c4_varargin_4->size[0] * c4_varargin_4->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_varargin_4->data[c4_i1] = c4_varargin_4->data[c4_i1];
  }

  c4_b_st.site = &c4_ck_emlrtRSI;
  c4_c_validateattributes(chartInstance, &c4_b_st, c4_b_varargin_4);
  c4_emxFree_real_T(chartInstance, &c4_b_varargin_4);
  if ((real_T)c4_varargin_4->size[1] != 2.0) {
    sf_mex_call(&c4_st, &c4_eb_emlrtMCI, "error", 0U, 2U, 14,
                c4_emlrt_marshallOut(chartInstance, c4_b_cv), 14, sf_mex_call
                (&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call(&c4_st, NULL,
      "message", 1U, 1U, 14, c4_emlrt_marshallOut(chartInstance, c4_b_cv))));
  }

  c4_emxInit_real_T(chartInstance, &c4_st, &c4_peaks, 2, &c4_wg_emlrtRTEI);
  c4_i2 = c4_peaks->size[0] * c4_peaks->size[1];
  c4_peaks->size[0] = c4_varargin_4->size[0];
  c4_peaks->size[1] = c4_varargin_4->size[1];
  c4_st.site = &c4_vj_emlrtRSI;
  c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_peaks, c4_i2,
    &c4_cg_emlrtRTEI);
  c4_b_loop_ub = c4_varargin_4->size[0] * c4_varargin_4->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_peaks->data[c4_i3] = c4_varargin_4->data[c4_i3];
  }

  c4_st.site = &c4_wj_emlrtRSI;
  for (c4_j = 0; c4_j < 160; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    c4_tempNum = 0.0;
    for (c4_b_i = 0; c4_b_i < 120; c4_b_i++) {
      c4_c_i = (real_T)c4_b_i + 1.0;
      if (c4_d_varargin_1[((int32_T)c4_c_i + 120 * ((int32_T)c4_b_j - 1)) - 1])
      {
        c4_tempNum++;
        c4_i4 = (int32_T)c4_tempNum;
        c4_tempBin[emlrtDynamicBoundsCheckR2012b(c4_i4, 1, 120, &c4_gf_emlrtBCI,
          &c4_st) - 1] = c4_c_i - 1.0;
      }
    }

    c4_tempNumsVector[(int32_T)c4_b_j - 1] = (int32_T)c4_tempNum;
    c4_d_i = 0;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_d_i < 120)) {
      c4_c_i = (real_T)c4_d_i + 1.0;
      if (c4_c_i > c4_tempNum) {
        c4_exitg1 = true;
      } else {
        c4_nonZeroPixelMatrix[((int32_T)c4_c_i + 120 * ((int32_T)c4_b_j - 1)) -
          1] = (int32_T)c4_tempBin[(int32_T)c4_c_i - 1];
        c4_d_i++;
      }
    }
  }

  c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_point1Array, 2,
                      &c4_rg_emlrtRTEI);
  c4_numLines = 0;
  c4_point1Array->size[0] = 0;
  c4_point1Array->size[1] = 2;
  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_point2Array, 2, &c4_sg_emlrtRTEI);
  c4_point2Array->size[0] = 0;
  c4_point2Array->size[1] = 2;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_thetaArray, 1, &c4_tg_emlrtRTEI);
  c4_thetaArray->size[0] = 0;
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_rhoArray, 1, &c4_ug_emlrtRTEI);
  c4_rhoArray->size[0] = 0;
  c4_numPeaks = (real_T)c4_peaks->size[0];
  c4_i5 = (int32_T)c4_numPeaks - 1;
  c4_peakIdx = 0;
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_indices, 1, &c4_vg_emlrtRTEI);
  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_houghPix, 2, &c4_xg_emlrtRTEI);
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_distances2, 1, &c4_yg_emlrtRTEI);
  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_r, 2, &c4_dg_emlrtRTEI);
  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_b_point1Array, 2,
                      &c4_jg_emlrtRTEI);
  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_b_point2Array, 2,
                      &c4_lg_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_thetaArray, 1,
                      &c4_ng_emlrtRTEI);
  c4_emxInit_real32_T(chartInstance, c4_sp, &c4_b_rhoArray, 1, &c4_pg_emlrtRTEI);
  while (c4_peakIdx <= c4_i5) {
    c4_b_peakIdx = (real_T)c4_peakIdx + 1.0;
    c4_i6 = c4_peaks->size[0];
    c4_i7 = (int32_T)c4_b_peakIdx;
    c4_peak1 = (int32_T)c4_peaks->data[emlrtDynamicBoundsCheckR2012b(c4_i7, 1,
      c4_i6, &c4_tf_emlrtBCI, c4_sp) - 1];
    c4_i8 = c4_peaks->size[0];
    c4_i9 = (int32_T)c4_b_peakIdx;
    c4_peak2 = (int32_T)c4_peaks->data[(emlrtDynamicBoundsCheckR2012b(c4_i9, 1,
      c4_i8, &c4_uf_emlrtBCI, c4_sp) + c4_peaks->size[0]) - 1];
    c4_st.site = &c4_xj_emlrtRSI;
    c4_b_peak1 = c4_peak1;
    c4_b_peak2 = c4_peak2;
    c4_numHoughPix = 0;
    c4_thetaVal = (-90.0 + (real_T)(emlrtDynamicBoundsCheckR2012b(c4_b_peak2, 1,
      180, &c4_kf_emlrtBCI, &c4_st) - 1)) * 3.1415926535897931 / 180.0;
    c4_c_x = c4_thetaVal;
    c4_cosTheta = c4_c_x;
    c4_cosTheta = muDoubleScalarCos(c4_cosTheta);
    c4_d_x = c4_thetaVal;
    c4_sinTheta = c4_d_x;
    c4_sinTheta = muDoubleScalarSin(c4_sinTheta);
    c4_rowMax = 0.0;
    c4_rowMin = rtInf;
    c4_colMax = 0.0;
    c4_colMin = rtInf;
    for (c4_k = 0; c4_k < 160; c4_k++) {
      c4_c_k = (real_T)c4_k + 1.0;
      c4_b_tempNum = 0;
      c4_i10 = c4_tempNumsVector[(int32_T)c4_c_k - 1];
      c4_b_st.site = &c4_fk_emlrtRSI;
      c4_c_b = c4_i10;
      c4_d_b = c4_c_b;
      if (1 > c4_d_b) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_d_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_c_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
      }

      for (c4_c_j = 1; c4_c_j - 1 < c4_i10; c4_c_j++) {
        c4_e_j = c4_c_j - 1;
        c4_rhoVal = (c4_c_k - 1.0) * c4_cosTheta + (real_T)
          c4_nonZeroPixelMatrix[c4_e_j + 120 * ((int32_T)c4_c_k - 1)] *
          c4_sinTheta;
        c4_e_x = (c4_rhoVal - -199.0) + 1.0;
        c4_rhoBinIdx = (int32_T)(c4_e_x + 0.5);
        if (c4_rhoBinIdx == c4_b_peak1) {
          c4_b_tempNum++;
          c4_b_tempBin[emlrtDynamicBoundsCheckR2012b(c4_b_tempNum, 1, 120,
            &c4_dg_emlrtBCI, &c4_st) - 1] = c4_nonZeroPixelMatrix[c4_e_j + 120 *
            ((int32_T)c4_c_k - 1)] + 1;
        }
      }

      c4_tempHoughPixNumsVector[(int32_T)c4_c_k - 1] = c4_b_tempNum;
      c4_numHoughPix += c4_b_tempNum;
      if (c4_b_tempNum != 0) {
        c4_e_varargin_1 = c4_rowMax;
        c4_b_varargin_2 = (real_T)c4_b_tempBin[c4_b_tempNum - 1];
        c4_f_x = c4_e_varargin_1;
        c4_y = c4_b_varargin_2;
        c4_g_x = c4_f_x;
        c4_b_y = c4_y;
        c4_h_x = c4_g_x;
        c4_c_y = c4_b_y;
        c4_i_x = c4_h_x;
        c4_d_y = c4_c_y;
        c4_j_x = c4_i_x;
        c4_e_y = c4_d_y;
        c4_k_x = c4_j_x;
        c4_f_y = c4_e_y;
        c4_rowMax = muDoubleScalarMax(c4_k_x, c4_f_y);
        c4_f_varargin_1 = c4_rowMin;
        c4_c_varargin_2 = (real_T)c4_b_tempBin[0];
        c4_l_x = c4_f_varargin_1;
        c4_g_y = c4_c_varargin_2;
        c4_m_x = c4_l_x;
        c4_h_y = c4_g_y;
        c4_n_x = c4_m_x;
        c4_i_y = c4_h_y;
        c4_o_x = c4_n_x;
        c4_j_y = c4_i_y;
        c4_p_x = c4_o_x;
        c4_k_y = c4_j_y;
        c4_q_x = c4_p_x;
        c4_l_y = c4_k_y;
        c4_rowMin = muDoubleScalarMin(c4_q_x, c4_l_y);
        c4_g_varargin_1 = c4_colMax;
        c4_d_varargin_2 = c4_c_k;
        c4_r_x = c4_g_varargin_1;
        c4_m_y = c4_d_varargin_2;
        c4_s_x = c4_r_x;
        c4_n_y = c4_m_y;
        c4_t_x = c4_s_x;
        c4_o_y = c4_n_y;
        c4_u_x = c4_t_x;
        c4_p_y = c4_o_y;
        c4_v_x = c4_u_x;
        c4_q_y = c4_p_y;
        c4_w_x = c4_v_x;
        c4_r_y = c4_q_y;
        c4_colMax = muDoubleScalarMax(c4_w_x, c4_r_y);
        c4_h_varargin_1 = c4_colMin;
        c4_e_varargin_2 = c4_c_k;
        c4_x_x = c4_h_varargin_1;
        c4_s_y = c4_e_varargin_2;
        c4_y_x = c4_x_x;
        c4_t_y = c4_s_y;
        c4_ab_x = c4_y_x;
        c4_u_y = c4_t_y;
        c4_bb_x = c4_ab_x;
        c4_v_y = c4_u_y;
        c4_cb_x = c4_bb_x;
        c4_w_y = c4_v_y;
        c4_db_x = c4_cb_x;
        c4_x_y = c4_w_y;
        c4_colMin = muDoubleScalarMin(c4_db_x, c4_x_y);
      }

      c4_e_i = 0;
      c4_exitg1 = false;
      while ((!c4_exitg1) && (c4_e_i < 120)) {
        c4_f_i = (real_T)c4_e_i + 1.0;
        if (c4_f_i > (real_T)c4_b_tempNum) {
          c4_exitg1 = true;
        } else {
          c4_houghPixTemp[((int32_T)c4_f_i + 120 * ((int32_T)c4_c_k - 1)) - 1] =
            c4_b_tempBin[(int32_T)c4_f_i - 1];
          c4_e_i++;
        }
      }
    }

    if (c4_numHoughPix < 1) {
      c4_houghPix->size[0] = 0;
      c4_houghPix->size[1] = 0;
    } else {
      c4_n = 0.0;
      for (c4_e_k = 0; c4_e_k < 160; c4_e_k++) {
        c4_g_k = (real_T)c4_e_k + 1.0;
        c4_i12 = c4_tempHoughPixNumsVector[(int32_T)c4_g_k - 1];
        c4_b_st.site = &c4_ek_emlrtRSI;
        c4_e_b = c4_i12;
        c4_f_b = c4_e_b;
        if (1 > c4_f_b) {
          c4_c_overflow = false;
        } else {
          c4_c_overflow = (c4_f_b > 2147483646);
        }

        if (c4_c_overflow) {
          c4_c_st.site = &c4_mb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
        }

        for (c4_d_j = 1; c4_d_j - 1 < c4_i12; c4_d_j++) {
          c4_e_j = c4_d_j - 1;
          c4_n++;
          c4_i29 = (int32_T)c4_n;
          chartInstance->c4_houghPixIdx[emlrtDynamicBoundsCheckR2012b(c4_i29, 1,
            19200, &c4_cg_emlrtBCI, &c4_st) - 1] = c4_houghPixTemp[c4_e_j + 120 *
            ((int32_T)c4_g_k - 1)];
          chartInstance->c4_houghPixIdx[(int32_T)c4_n + 19199] = (int32_T)c4_g_k;
        }
      }

      c4_rowRange = c4_rowMax - c4_rowMin;
      c4_colRange = c4_colMax - c4_colMin;
      if (c4_rowRange > c4_colRange) {
        for (c4_i15 = 0; c4_i15 < 2; c4_i15++) {
          c4_sortingOrder[c4_i15] = 1.0 + (real_T)c4_i15;
        }
      } else {
        for (c4_i14 = 0; c4_i14 < 2; c4_i14++) {
          c4_sortingOrder[c4_i14] = 2.0 - (real_T)c4_i14;
        }
      }

      c4_i18 = emlrtDynamicBoundsCheckR2012b(c4_numHoughPix, 1, 19200,
        &c4_jf_emlrtBCI, &c4_st) - 1;
      c4_i20 = c4_r->size[0] * c4_r->size[1];
      c4_r->size[0] = c4_i18 + 1;
      c4_r->size[1] = 2;
      c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_r, c4_i20,
        &c4_dg_emlrtRTEI);
      for (c4_i23 = 0; c4_i23 < 2; c4_i23++) {
        c4_c_loop_ub = c4_i18;
        for (c4_i27 = 0; c4_i27 <= c4_c_loop_ub; c4_i27++) {
          c4_r->data[c4_i27 + c4_r->size[0] * c4_i23] =
            chartInstance->c4_houghPixIdx[c4_i27 + 19200 * c4_i23];
        }
      }

      c4_b_st.site = &c4_dk_emlrtRSI;
      c4_b_sortrows(chartInstance, &c4_b_st, c4_r, c4_sortingOrder);
      c4_i28 = c4_houghPix->size[0] * c4_houghPix->size[1];
      c4_houghPix->size[0] = c4_r->size[0];
      c4_houghPix->size[1] = 2;
      c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_houghPix, c4_i28,
        &c4_fg_emlrtRTEI);
      c4_d_loop_ub = c4_r->size[0] * c4_r->size[1] - 1;
      for (c4_i34 = 0; c4_i34 <= c4_d_loop_ub; c4_i34++) {
        c4_houghPix->data[c4_i34] = c4_r->data[c4_i34];
      }
    }

    if (!(c4_numHoughPix < 1)) {
      c4_st.site = &c4_yj_emlrtRSI;
      c4_b_numHoughPix = (real_T)c4_houghPix->size[0];
      c4_b_st.site = &c4_mk_emlrtRSI;
      c4_c_st.site = &c4_v_emlrtRSI;
      c4_i17 = c4_distances2->size[0];
      c4_d = c4_b_numHoughPix - 1.0;
      c4_distances2->size[0] = (int32_T)emlrtNonNegativeCheckR2012b(c4_d,
        &c4_j_emlrtDCI, &c4_st);
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_distances2, c4_i17,
        &c4_eg_emlrtRTEI);
      c4_numPairs = 0.0;
      c4_d1 = c4_b_numHoughPix - 1.0;
      c4_i24 = (int32_T)c4_d1 - 1;
      for (c4_i_k = 0; c4_i_k <= c4_i24; c4_i_k++) {
        c4_j_k = (real_T)c4_i_k + 1.0;
        c4_i31 = c4_houghPix->size[1];
        c4_i32 = 1;
        emlrtDynamicBoundsCheckR2012b(c4_i32, 1, c4_i31, &c4_lf_emlrtBCI, &c4_st);
        c4_i33 = c4_houghPix->size[1];
        c4_i36 = 1;
        emlrtDynamicBoundsCheckR2012b(c4_i36, 1, c4_i33, &c4_mf_emlrtBCI, &c4_st);
        c4_i38 = c4_houghPix->size[1];
        c4_i39 = 2;
        emlrtDynamicBoundsCheckR2012b(c4_i39, 1, c4_i38, &c4_nf_emlrtBCI, &c4_st);
        c4_i41 = c4_houghPix->size[1];
        c4_i42 = 2;
        emlrtDynamicBoundsCheckR2012b(c4_i42, 1, c4_i41, &c4_of_emlrtBCI, &c4_st);
        c4_i43 = c4_houghPix->size[0];
        c4_i44 = (int32_T)(c4_j_k + 1.0);
        c4_i47 = c4_houghPix->size[0];
        c4_i49 = (int32_T)c4_j_k;
        c4_g_a = c4_houghPix->data[emlrtDynamicBoundsCheckR2012b(c4_i44, 1,
          c4_i43, &c4_fg_emlrtBCI, &c4_st) - 1] - c4_houghPix->
          data[emlrtDynamicBoundsCheckR2012b(c4_i49, 1, c4_i47, &c4_gg_emlrtBCI,
          &c4_st) - 1];
        c4_c = c4_b_power(chartInstance, c4_g_a);
        c4_i51 = c4_houghPix->size[0];
        c4_i54 = (int32_T)(c4_j_k + 1.0);
        c4_i56 = c4_houghPix->size[0];
        c4_i58 = (int32_T)c4_j_k;
        c4_h_a = c4_houghPix->data[(emlrtDynamicBoundsCheckR2012b(c4_i54, 1,
          c4_i51, &c4_hg_emlrtBCI, &c4_st) + c4_houghPix->size[0]) - 1] -
          c4_houghPix->data[(emlrtDynamicBoundsCheckR2012b(c4_i58, 1, c4_i56,
          &c4_ig_emlrtBCI, &c4_st) + c4_houghPix->size[0]) - 1];
        c4_b_c = c4_b_power(chartInstance, c4_h_a);
        c4_i61 = c4_distances2->size[0];
        c4_i62 = (int32_T)c4_j_k;
        c4_distances2->data[emlrtDynamicBoundsCheckR2012b(c4_i62, 1, c4_i61,
          &c4_jg_emlrtBCI, &c4_st) - 1] = (real_T)(c4_c + c4_b_c);
        c4_i64 = c4_distances2->size[0];
        c4_i65 = (int32_T)c4_j_k;
        if (c4_distances2->data[emlrtDynamicBoundsCheckR2012b(c4_i65, 1, c4_i64,
             &c4_kg_emlrtBCI, &c4_st) - 1] > 25.0) {
          c4_numPairs++;
        }
      }

      c4_i30 = c4_indices->size[0];
      c4_d2 = c4_numPairs + 2.0;
      c4_indices->size[0] = (int32_T)emlrtIntegerCheckR2012b(c4_d2,
        &c4_k_emlrtDCI, &c4_st);
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_indices, c4_i30,
        &c4_gg_emlrtRTEI);
      c4_indices->data[0] = 0.0;
      c4_i35 = c4_indices->size[0];
      c4_i37 = c4_indices->size[0];
      c4_indices->data[emlrtDynamicBoundsCheckR2012b(c4_i37, 1, c4_i35,
        &c4_eg_emlrtBCI, &c4_st) - 1] = c4_b_numHoughPix;
      c4_b_n = 1.0;
      c4_d3 = c4_b_numHoughPix - 1.0;
      c4_i40 = (int32_T)c4_d3 - 1;
      for (c4_k_k = 0; c4_k_k <= c4_i40; c4_k_k++) {
        c4_j_k = (real_T)c4_k_k + 1.0;
        c4_i46 = c4_distances2->size[0];
        c4_i48 = (int32_T)c4_j_k;
        if (c4_distances2->data[emlrtDynamicBoundsCheckR2012b(c4_i48, 1, c4_i46,
             &c4_lg_emlrtBCI, &c4_st) - 1] > 25.0) {
          c4_b_n++;
          c4_i50 = c4_indices->size[0];
          c4_i53 = (int32_T)c4_b_n;
          c4_indices->data[emlrtDynamicBoundsCheckR2012b(c4_i53, 1, c4_i50,
            &c4_mg_emlrtBCI, &c4_st) - 1] = c4_j_k;
        }
      }

      c4_d4 = (real_T)c4_indices->size[0] - 1.0;
      c4_i45 = (int32_T)c4_d4 - 1;
      for (c4_l_k = 0; c4_l_k <= c4_i45; c4_l_k++) {
        c4_m_k = (real_T)c4_l_k + 1.0;
        c4_i52 = c4_houghPix->size[0];
        c4_i55 = c4_indices->size[0];
        c4_i57 = (int32_T)c4_m_k;
        c4_i59 = (int32_T)(c4_indices->data[emlrtDynamicBoundsCheckR2012b(c4_i57,
          1, c4_i55, &c4_af_emlrtBCI, c4_sp) - 1] + 1.0);
        c4_b_indices = emlrtDynamicBoundsCheckR2012b(c4_i59, 1, c4_i52,
          &c4_af_emlrtBCI, c4_sp) - 1;
        c4_i60 = c4_houghPix->size[1] - 1;
        c4_point1_size[1] = c4_i60 + 1;
        c4_e_loop_ub = c4_i60;
        for (c4_i63 = 0; c4_i63 <= c4_e_loop_ub; c4_i63++) {
          c4_point1_data[c4_i63] = c4_houghPix->data[c4_b_indices +
            c4_houghPix->size[0] * c4_i63];
        }

        c4_i66 = c4_houghPix->size[0];
        c4_i67 = c4_indices->size[0];
        c4_i68 = (int32_T)(c4_m_k + 1.0);
        c4_i69 = (int32_T)c4_indices->data[emlrtDynamicBoundsCheckR2012b(c4_i68,
          1, c4_i67, &c4_bf_emlrtBCI, c4_sp) - 1];
        c4_c_indices = emlrtDynamicBoundsCheckR2012b(c4_i69, 1, c4_i66,
          &c4_bf_emlrtBCI, c4_sp) - 1;
        c4_i70 = c4_houghPix->size[1] - 1;
        c4_point2_size[1] = c4_i70 + 1;
        c4_f_loop_ub = c4_i70;
        for (c4_i71 = 0; c4_i71 <= c4_f_loop_ub; c4_i71++) {
          c4_point2_data[c4_i71] = c4_houghPix->data[c4_c_indices +
            c4_houghPix->size[0] * c4_i71];
        }

        c4_st.site = &c4_ak_emlrtRSI;
        c4_i72 = 1;
        emlrtDynamicBoundsCheckR2012b(c4_i72, 1, c4_point2_size[1],
          &c4_pf_emlrtBCI, &c4_st);
        c4_i73 = 1;
        emlrtDynamicBoundsCheckR2012b(c4_i73, 1, c4_point1_size[1],
          &c4_qf_emlrtBCI, &c4_st);
        c4_i74 = 2;
        emlrtDynamicBoundsCheckR2012b(c4_i74, 1, c4_point2_size[1],
          &c4_rf_emlrtBCI, &c4_st);
        c4_i75 = 2;
        emlrtDynamicBoundsCheckR2012b(c4_i75, 1, c4_point1_size[1],
          &c4_sf_emlrtBCI, &c4_st);
        c4_i_a = c4_point2_data[0] - c4_point1_data[0];
        c4_c_c = c4_b_power(chartInstance, c4_i_a);
        c4_j_a = c4_point2_data[1] - c4_point1_data[1];
        c4_d_c = c4_b_power(chartInstance, c4_j_a);
        c4_lineLength2 = c4_c_c + c4_d_c;
        if (c4_lineLength2 >= 100) {
          c4_numLines++;
          c4_i76 = 2;
          emlrtDynamicBoundsCheckR2012b(c4_i76, 1, c4_point1_size[1],
            &c4_cf_emlrtBCI, c4_sp);
          c4_i77 = 1;
          emlrtDynamicBoundsCheckR2012b(c4_i77, 1, c4_point1_size[1],
            &c4_df_emlrtBCI, c4_sp);
          c4_i78 = c4_b_point1Array->size[0] * c4_b_point1Array->size[1];
          c4_b_point1Array->size[0] = c4_point1Array->size[0] + 1;
          c4_b_point1Array->size[1] = 2;
          c4_st.site = &c4_vl_emlrtRSI;
          c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_b_point1Array,
            c4_i78, &c4_jg_emlrtRTEI);
          for (c4_i79 = 0; c4_i79 < 2; c4_i79++) {
            c4_g_loop_ub = c4_point1Array->size[0] - 1;
            for (c4_i80 = 0; c4_i80 <= c4_g_loop_ub; c4_i80++) {
              c4_b_point1Array->data[c4_i80 + c4_b_point1Array->size[0] * c4_i79]
                = c4_point1Array->data[c4_i80 + c4_point1Array->size[0] * c4_i79];
            }
          }

          c4_b_point1Array->data[c4_point1Array->size[0]] = c4_point1_data[1];
          c4_b_point1Array->data[c4_point1Array->size[0] +
            c4_b_point1Array->size[0]] = c4_point1_data[0];
          c4_i81 = c4_point1Array->size[0] * c4_point1Array->size[1];
          c4_point1Array->size[0] = c4_b_point1Array->size[0];
          c4_point1Array->size[1] = 2;
          c4_st.site = &c4_vl_emlrtRSI;
          c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_point1Array,
            c4_i81, &c4_kg_emlrtRTEI);
          c4_h_loop_ub = c4_b_point1Array->size[0] * c4_b_point1Array->size[1] -
            1;
          for (c4_i82 = 0; c4_i82 <= c4_h_loop_ub; c4_i82++) {
            c4_point1Array->data[c4_i82] = c4_b_point1Array->data[c4_i82];
          }

          c4_i83 = 2;
          emlrtDynamicBoundsCheckR2012b(c4_i83, 1, c4_point2_size[1],
            &c4_ef_emlrtBCI, c4_sp);
          c4_i84 = 1;
          emlrtDynamicBoundsCheckR2012b(c4_i84, 1, c4_point2_size[1],
            &c4_ff_emlrtBCI, c4_sp);
          c4_i85 = c4_b_point2Array->size[0] * c4_b_point2Array->size[1];
          c4_b_point2Array->size[0] = c4_point2Array->size[0] + 1;
          c4_b_point2Array->size[1] = 2;
          c4_st.site = &c4_ul_emlrtRSI;
          c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_b_point2Array,
            c4_i85, &c4_lg_emlrtRTEI);
          for (c4_i86 = 0; c4_i86 < 2; c4_i86++) {
            c4_i_loop_ub = c4_point2Array->size[0] - 1;
            for (c4_i87 = 0; c4_i87 <= c4_i_loop_ub; c4_i87++) {
              c4_b_point2Array->data[c4_i87 + c4_b_point2Array->size[0] * c4_i86]
                = c4_point2Array->data[c4_i87 + c4_point2Array->size[0] * c4_i86];
            }
          }

          c4_b_point2Array->data[c4_point2Array->size[0]] = c4_point2_data[1];
          c4_b_point2Array->data[c4_point2Array->size[0] +
            c4_b_point2Array->size[0]] = c4_point2_data[0];
          c4_i88 = c4_point2Array->size[0] * c4_point2Array->size[1];
          c4_point2Array->size[0] = c4_b_point2Array->size[0];
          c4_point2Array->size[1] = 2;
          c4_st.site = &c4_ul_emlrtRSI;
          c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_point2Array,
            c4_i88, &c4_mg_emlrtRTEI);
          c4_j_loop_ub = c4_b_point2Array->size[0] * c4_b_point2Array->size[1] -
            1;
          for (c4_i89 = 0; c4_i89 <= c4_j_loop_ub; c4_i89++) {
            c4_point2Array->data[c4_i89] = c4_b_point2Array->data[c4_i89];
          }

          c4_i90 = c4_b_thetaArray->size[0];
          c4_b_thetaArray->size[0] = c4_thetaArray->size[0] + 1;
          c4_st.site = &c4_rk_emlrtRSI;
          c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_thetaArray,
            c4_i90, &c4_ng_emlrtRTEI);
          c4_k_loop_ub = c4_thetaArray->size[0] - 1;
          for (c4_i91 = 0; c4_i91 <= c4_k_loop_ub; c4_i91++) {
            c4_b_thetaArray->data[c4_i91] = c4_thetaArray->data[c4_i91];
          }

          c4_b_thetaArray->data[c4_thetaArray->size[0]] = (real32_T)(-90.0 +
            (real_T)(emlrtDynamicBoundsCheckR2012b(c4_peak2, 1, 180,
            &c4_ng_emlrtBCI, c4_sp) - 1));
          c4_i92 = c4_thetaArray->size[0];
          c4_thetaArray->size[0] = c4_b_thetaArray->size[0];
          c4_st.site = &c4_rk_emlrtRSI;
          c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_thetaArray,
            c4_i92, &c4_og_emlrtRTEI);
          c4_l_loop_ub = c4_b_thetaArray->size[0] - 1;
          for (c4_i93 = 0; c4_i93 <= c4_l_loop_ub; c4_i93++) {
            c4_thetaArray->data[c4_i93] = c4_b_thetaArray->data[c4_i93];
          }

          c4_i94 = c4_b_rhoArray->size[0];
          c4_b_rhoArray->size[0] = c4_rhoArray->size[0] + 1;
          c4_st.site = &c4_qk_emlrtRSI;
          c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_b_rhoArray,
            c4_i94, &c4_pg_emlrtRTEI);
          c4_m_loop_ub = c4_rhoArray->size[0] - 1;
          for (c4_i95 = 0; c4_i95 <= c4_m_loop_ub; c4_i95++) {
            c4_b_rhoArray->data[c4_i95] = c4_rhoArray->data[c4_i95];
          }

          c4_b_rhoArray->data[c4_rhoArray->size[0]] = (real32_T)c4_b_dv[c4_peak1
            - 1];
          c4_i96 = c4_rhoArray->size[0];
          c4_rhoArray->size[0] = c4_b_rhoArray->size[0];
          c4_st.site = &c4_qk_emlrtRSI;
          c4_emxEnsureCapacity_real32_T(chartInstance, &c4_st, c4_rhoArray,
            c4_i96, &c4_qg_emlrtRTEI);
          c4_n_loop_ub = c4_b_rhoArray->size[0] - 1;
          for (c4_i97 = 0; c4_i97 <= c4_n_loop_ub; c4_i97++) {
            c4_rhoArray->data[c4_i97] = c4_b_rhoArray->data[c4_i97];
          }
        }
      }
    }

    c4_peakIdx++;
  }

  c4_emxFree_real32_T(chartInstance, &c4_b_rhoArray);
  c4_emxFree_real32_T(chartInstance, &c4_b_thetaArray);
  c4_emxFree_int32_T(chartInstance, &c4_b_point2Array);
  c4_emxFree_int32_T(chartInstance, &c4_b_point1Array);
  c4_emxFree_int32_T(chartInstance, &c4_r);
  c4_emxFree_real_T(chartInstance, &c4_distances2);
  c4_emxFree_int32_T(chartInstance, &c4_houghPix);
  c4_emxFree_real_T(chartInstance, &c4_peaks);
  c4_emxFree_real_T(chartInstance, &c4_indices);
  c4_st.site = &c4_bk_emlrtRSI;
  c4_b_numLines = c4_numLines;
  c4_b_st.site = &c4_nk_emlrtRSI;
  c4_c_numLines = c4_b_numLines;
  c4_c_st.site = &c4_pk_emlrtRSI;
  c4_b_repmat(chartInstance, &c4_c_st, c4_c_numLines, c4_lines);
  c4_b_st.site = &c4_ok_emlrtRSI;
  c4_b = c4_b_numLines;
  c4_b_b = c4_b;
  if (1 > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  for (c4_b_k = 1; c4_b_k - 1 < c4_b_numLines; c4_b_k++) {
    c4_d_k = c4_b_k;
    c4_i11 = c4_point1Array->size[0];
    c4_f_k = emlrtDynamicBoundsCheckR2012b(c4_d_k, 1, c4_i11, &c4_hf_emlrtBCI,
      &c4_st) - 1;
    c4_b_lines = c4_lines->size[1];
    for (c4_i13 = 0; c4_i13 < 2; c4_i13++) {
      c4_lines->data[emlrtDynamicBoundsCheckR2012b(c4_d_k, 1, c4_b_lines,
        &c4_vf_emlrtBCI, &c4_st) - 1].point1[c4_i13] = (real_T)
        c4_point1Array->data[c4_f_k + c4_point1Array->size[0] * c4_i13];
    }

    c4_i16 = c4_point2Array->size[0];
    c4_h_k = emlrtDynamicBoundsCheckR2012b(c4_d_k, 1, c4_i16, &c4_if_emlrtBCI,
      &c4_st) - 1;
    c4_c_lines = c4_lines->size[1];
    for (c4_i19 = 0; c4_i19 < 2; c4_i19++) {
      c4_lines->data[emlrtDynamicBoundsCheckR2012b(c4_d_k, 1, c4_c_lines,
        &c4_wf_emlrtBCI, &c4_st) - 1].point2[c4_i19] = (real_T)
        c4_point2Array->data[c4_h_k + c4_point2Array->size[0] * c4_i19];
    }

    c4_i21 = c4_thetaArray->size[0];
    c4_i22 = c4_lines->size[1];
    c4_lines->data[emlrtDynamicBoundsCheckR2012b(c4_d_k, 1, c4_i22,
      &c4_yf_emlrtBCI, &c4_st) - 1].theta = c4_thetaArray->
      data[emlrtDynamicBoundsCheckR2012b(c4_d_k, 1, c4_i21, &c4_xf_emlrtBCI,
      &c4_st) - 1];
    c4_i25 = c4_rhoArray->size[0];
    c4_i26 = c4_lines->size[1];
    c4_lines->data[emlrtDynamicBoundsCheckR2012b(c4_d_k, 1, c4_i26,
      &c4_bg_emlrtBCI, &c4_st) - 1].rho = c4_rhoArray->
      data[emlrtDynamicBoundsCheckR2012b(c4_d_k, 1, c4_i25, &c4_ag_emlrtBCI,
      &c4_st) - 1];
  }

  c4_emxFree_real32_T(chartInstance, &c4_rhoArray);
  c4_emxFree_real32_T(chartInstance, &c4_thetaArray);
  c4_emxFree_int32_T(chartInstance, &c4_point2Array);
  c4_emxFree_int32_T(chartInstance, &c4_point1Array);
}

static void c4_c_validateattributes(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_g_a)
{
  static char_T c4_b_cv[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c4_b_cv1[22] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '4', ',', ' ', 'P', 'E', 'A', 'K', 'S', ',' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_k;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  int32_T c4_i;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_u_emlrtRSI;
  c4_st.site = &c4_u_emlrtRSI;
  c4_p = true;
  c4_d = (real_T)(c4_g_a->size[0] * c4_g_a->size[1]);
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k <= c4_i)) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_c_x = c4_g_a->data[(int32_T)c4_b_k - 1];
    c4_d_x = c4_c_x;
    c4_e_x = c4_d_x;
    c4_b_b = muDoubleScalarIsInf(c4_e_x);
    c4_b1 = !c4_b_b;
    c4_f_x = c4_d_x;
    c4_c_b = muDoubleScalarIsNaN(c4_f_x);
    c4_b2 = !c4_c_b;
    c4_d_b = (c4_b1 && c4_b2);
    if (c4_d_b) {
      c4_g_x = c4_c_x;
      c4_h_x = c4_g_x;
      c4_h_x = muDoubleScalarFloor(c4_h_x);
      if (c4_h_x == c4_c_x) {
        c4_b_p = true;
      } else {
        c4_b_p = false;
      }
    } else {
      c4_b_p = false;
    }

    c4_c_p = c4_b_p;
    if (c4_c_p) {
      c4_k++;
    } else {
      c4_p = false;
      c4_exitg1 = true;
    }
  }

  if (c4_p) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  if (!c4_b) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv7, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv1, 10, 0U, 1U, 0U, 2, 1, 22),
                  false);
    sf_mex_call(&c4_st, &c4_y_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
  }
}

static void c4_sortrows(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_y, real_T c4_d_varargin_1[2],
  c4_emxArray_int32_T *c4_b_y)
{
  real_T c4_e_varargin_1[2];
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_loop_ub;
  c4_i = c4_b_y->size[0] * c4_b_y->size[1];
  c4_b_y->size[0] = c4_y->size[0];
  c4_b_y->size[1] = 2;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_b_y, c4_i,
    &c4_ah_emlrtRTEI);
  c4_loop_ub = c4_y->size[0] * c4_y->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_y->data[c4_i1] = c4_y->data[c4_i1];
  }

  for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
    c4_e_varargin_1[c4_i2] = c4_d_varargin_1[c4_i2];
  }

  c4_b_sortrows(chartInstance, c4_sp, c4_b_y, c4_e_varargin_1);
}

static void c4_b_mergesort(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_int32_T
  *c4_c_x, int32_T c4_dir[2], int32_T c4_n, c4_emxArray_int32_T *c4_c_idx)
{
  c4_emxArray_int32_T *c4_d_x;
  int32_T c4_b_dir[2];
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_loop_ub;
  c4_i = c4_c_idx->size[0];
  c4_c_idx->size[0] = c4_b_idx->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_c_idx, c4_i,
    &c4_bh_emlrtRTEI);
  c4_loop_ub = c4_b_idx->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_c_idx->data[c4_i1] = c4_b_idx->data[c4_i1];
  }

  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_d_x, 2, &c4_bh_emlrtRTEI);
  c4_i2 = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = c4_c_x->size[0];
  c4_d_x->size[1] = 2;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_d_x, c4_i2,
    &c4_bh_emlrtRTEI);
  c4_b_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_d_x->data[c4_i3] = c4_c_x->data[c4_i3];
  }

  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    c4_b_dir[c4_i4] = c4_dir[c4_i4];
  }

  c4_d_mergesort(chartInstance, c4_sp, c4_c_idx, c4_d_x, c4_b_dir, c4_n);
  c4_emxFree_int32_T(chartInstance, &c4_d_x);
}

static boolean_T c4_sortLE(SFc4_flightControlSystemInstanceStruct *chartInstance,
  c4_emxArray_int32_T *c4_v, int32_T c4_dir[2], int32_T c4_idx1, int32_T c4_idx2)
{
  int32_T c4_abscolk;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_c_x;
  int32_T c4_colk;
  int32_T c4_d_x;
  int32_T c4_e_x;
  int32_T c4_g_a;
  int32_T c4_h_a;
  int32_T c4_irow1;
  int32_T c4_irow2;
  int32_T c4_k;
  int32_T c4_v1;
  int32_T c4_v2;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  boolean_T c4_v1eqv2;
  (void)chartInstance;
  c4_irow1 = c4_idx1 - 1;
  c4_irow2 = c4_idx2 - 1;
  c4_p = true;
  c4_k = 1;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k - 1 < 2)) {
    c4_b_k = c4_k - 1;
    c4_colk = c4_dir[c4_b_k];
    c4_c_x = c4_colk;
    c4_d_x = c4_c_x;
    c4_e_x = c4_d_x;
    c4_abscolk = c4_e_x - 1;
    c4_v1 = c4_v->data[c4_irow1 + c4_v->size[0] * c4_abscolk];
    c4_v2 = c4_v->data[c4_irow2 + c4_v->size[0] * c4_abscolk];
    c4_v1eqv2 = (c4_v1 == c4_v2);
    if (c4_v1eqv2) {
      c4_k++;
    } else {
      c4_g_a = c4_v1;
      c4_b = c4_v2;
      c4_h_a = c4_g_a;
      c4_b_b = c4_b;
      c4_p = (c4_h_a <= c4_b_b);
      c4_exitg1 = true;
    }
  }

  return c4_p;
}

static void c4_apply_row_permutation(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_y,
  c4_emxArray_int32_T *c4_b_idx, c4_emxArray_int32_T *c4_b_y)
{
  c4_emxArray_int32_T *c4_c_idx;
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_loop_ub;
  c4_i = c4_b_y->size[0] * c4_b_y->size[1];
  c4_b_y->size[0] = c4_y->size[0];
  c4_b_y->size[1] = 2;
  c4_emxEnsureCapacity_int32_T1(chartInstance, c4_sp, c4_b_y, c4_i,
    &c4_ch_emlrtRTEI);
  c4_loop_ub = c4_y->size[0] * c4_y->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_y->data[c4_i1] = c4_y->data[c4_i1];
  }

  c4_emxInit_int32_T(chartInstance, c4_sp, &c4_c_idx, 1, &c4_ch_emlrtRTEI);
  c4_i2 = c4_c_idx->size[0];
  c4_c_idx->size[0] = c4_b_idx->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_c_idx, c4_i2,
    &c4_ch_emlrtRTEI);
  c4_b_loop_ub = c4_b_idx->size[0] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_b_loop_ub; c4_i3++) {
    c4_c_idx->data[c4_i3] = c4_b_idx->data[c4_i3];
  }

  c4_b_apply_row_permutation(chartInstance, c4_sp, c4_b_y, c4_c_idx);
  c4_emxFree_int32_T(chartInstance, &c4_c_idx);
}

static int32_T c4_b_power(SFc4_flightControlSystemInstanceStruct *chartInstance,
  int32_T c4_g_a)
{
  int32_T c4_bu;
  int32_T c4_c_x;
  int32_T c4_exitg1;
  int32_T c4_h_a;
  int32_T c4_i_a;
  int32_T c4_y;
  (void)chartInstance;
  c4_h_a = c4_g_a;
  c4_c_x = c4_h_a;
  c4_i_a = c4_c_x;
  c4_y = 1;
  c4_bu = 2;
  do {
    c4_exitg1 = 0;
    if ((c4_bu & 1) != 0) {
      c4_y *= c4_i_a;
    }

    c4_bu >>= 1;
    if (c4_bu == 0) {
      c4_exitg1 = 1;
    } else {
      c4_i_a *= c4_i_a;
    }
  } while (c4_exitg1 == 0);

  return c4_y;
}

static void c4_b_repmat(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_b_varargin_2,
  c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *c4_b)
{
  c4_emxArray_boolean_T *c4_tile;
  c4_skoeQIuVNKJRHNtBIlOCZhD c4_b_s;
  emlrtStack c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_d;
  real_T c4_d1;
  int32_T c4_outsize[2];
  int32_T c4_b_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_loop_ub;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_emxInit_boolean_T(chartInstance, c4_sp, &c4_tile, 2, &c4_tf_emlrtRTEI);
  c4_st.site = &c4_ai_emlrtRSI;
  c4_i = c4_tile->size[0] * c4_tile->size[1];
  c4_tile->size[0] = 1;
  c4_d = (real_T)c4_b_varargin_2;
  c4_tile->size[1] = (int32_T)emlrtNonNegativeCheckR2012b(c4_d, &c4_l_emlrtDCI,
    c4_sp);
  c4_st.site = &c4_bl_emlrtRSI;
  c4_emxEnsureCapacity_boolean_T(chartInstance, &c4_st, c4_tile, c4_i,
    &c4_tf_emlrtRTEI);
  c4_d1 = (real_T)c4_b_varargin_2;
  c4_loop_ub = (int32_T)emlrtNonNegativeCheckR2012b(c4_d1, &c4_m_emlrtDCI, c4_sp)
    - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_tile->data[c4_i1] = false;
  }

  c4_outsize[1] = c4_tile->size[1];
  if (!((real_T)c4_outsize[1] == (real_T)c4_tile->size[1])) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv4, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c4_sp, &c4_o_emlrtMCI, "error", 0U, 1U, 14, c4_y);
  }

  c4_emxFree_boolean_T(chartInstance, &c4_tile);
  for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
    c4_b_s.point1[c4_i2] = 0.0;
  }

  for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
    c4_b_s.point2[c4_i3] = 0.0;
  }

  c4_b_s.theta = 0.0;
  c4_b_s.rho = 0.0;
  c4_i4 = c4_b->size[0] * c4_b->size[1];
  c4_b->size[0] = 1;
  c4_b->size[1] = c4_outsize[1];
  c4_st.site = &c4_wl_emlrtRSI;
  c4_emxEnsureCapacity_skoeQIuVNKJRH(chartInstance, &c4_st, c4_b, c4_i4,
    &c4_uf_emlrtRTEI);
  c4_b_loop_ub = c4_outsize[1] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_b_loop_ub; c4_i5++) {
    c4_b->data[c4_i5] = c4_b_s;
  }
}

static const mxArray *c4_emlrt_marshallOut
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const char_T c4_b_u[30])
{
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  return c4_y;
}

static real_T c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_mode, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_mode), &c4_thisId);
  sf_mex_destroy(&c4_b_mode);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_d;
  real_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_b_u), &c4_d, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d;
  sf_mex_destroy(&c4_b_u);
  return c4_y;
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_flightControlSystem, const
  char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_flightControlSystem), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_flightControlSystem);
  return c4_y;
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_b_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_c_u;
  uint8_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_b_u), &c4_c_u, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_c_u;
  sf_mex_destroy(&c4_b_u);
  return c4_y;
}

static const mxArray *c4_chart_data_browse_helper
  (SFc4_flightControlSystemInstanceStruct *chartInstance, int32_T c4_ssIdNumber)
{
  const mxArray *c4_mxData = NULL;
  real_T c4_d;
  real_T c4_d1;
  c4_mxData = NULL;
  switch (c4_ssIdNumber) {
   case 4U:
    sf_mex_assign(&c4_mxData, sf_mex_create("mxData", *chartInstance->c4_image,
      0, 0U, 1U, 0U, 2, 120, 160), false);
    break;

   case 5U:
    c4_d = *chartInstance->c4_output_angle;
    sf_mex_assign(&c4_mxData, sf_mex_create("mxData", &c4_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 7U:
    c4_d1 = *chartInstance->c4_mode;
    sf_mex_assign(&c4_mxData, sf_mex_create("mxData", &c4_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }

  return c4_mxData;
}

static const mxArray *c4_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1)
{
  const mxArray *c4_ = NULL;
  (void)chartInstance;
  c4_ = NULL;
  sf_mex_assign(&c4_, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_;
}

static void c4_b_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static const mxArray *c4_c_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1, const mxArray *c4_input2)
{
  const mxArray *c4_ = NULL;
  (void)chartInstance;
  c4_ = NULL;
  sf_mex_assign(&c4_, sf_mex_call(c4_sp, NULL, "feval", 1U, 3U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1), 14, sf_mex_dup(c4_input2)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  sf_mex_destroy(&c4_input2);
  return c4_;
}

static void c4_d_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static const mxArray *c4_e_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1)
{
  const mxArray *c4_ = NULL;
  (void)chartInstance;
  c4_ = NULL;
  sf_mex_assign(&c4_, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_;
}

static void c4_f_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static void c4_b_bwmorphApplyOnce(SFc4_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c4_bw[19200])
{
  int32_T c4_i;
  boolean_T c4_b_bw[19200];
  boolean_T c4_image_iter1[19200];
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_b_bw[c4_i] = c4_bw[c4_i];
  }

  c4_bwlookup(chartInstance, c4_b_bw, c4_image_iter1);
  c4_b_bwlookup(chartInstance, c4_image_iter1, c4_bw);
}

static void c4_c_mergesort(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, int32_T c4_b_idx[19200], real32_T c4_c_x[19200])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b_idx1;
  int32_T c4_b_idx2;
  int32_T c4_b_k;
  int32_T c4_b_p;
  int32_T c4_c_k;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_h_a;
  int32_T c4_i;
  int32_T c4_i2;
  int32_T c4_idx1;
  int32_T c4_idx2;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_kEnd;
  int32_T c4_pEnd;
  int32_T c4_q;
  int32_T c4_qEnd;
  real32_T c4_b;
  real32_T c4_b_b;
  real32_T c4_c_b;
  real32_T c4_d_x;
  real32_T c4_e_x;
  real32_T c4_g_a;
  real32_T c4_g_b;
  real32_T c4_h_b;
  real32_T c4_i_a;
  real32_T c4_i_b;
  real32_T c4_j_a;
  real32_T c4_k_a;
  real32_T c4_l_a;
  real32_T c4_m_a;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_d_p;
  boolean_T c4_e_p;
  boolean_T c4_f_p;
  boolean_T c4_g_p;
  boolean_T c4_j_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_k = 0; c4_k <= 19199; c4_k += 2) {
    c4_idx1 = c4_k;
    c4_idx2 = c4_k;
    c4_g_a = c4_c_x[c4_idx1];
    c4_b = c4_c_x[c4_idx2 + 1];
    c4_i_a = c4_g_a;
    c4_b_b = c4_b;
    c4_j_a = c4_i_a;
    c4_c_b = c4_b_b;
    c4_p = (c4_j_a <= c4_c_b);
    if (c4_p) {
      c4_c_p = true;
    } else {
      c4_d_x = c4_b_b;
      c4_d_b = muSingleScalarIsNaN(c4_d_x);
      if (c4_d_b) {
        c4_c_p = true;
      } else {
        c4_c_p = false;
      }
    }

    c4_d_p = c4_c_p;
    if (c4_d_p) {
      c4_b_idx[c4_k] = c4_k + 1;
      c4_b_idx[c4_k + 1] = c4_k + 2;
    } else {
      c4_b_idx[c4_k] = c4_k + 2;
      c4_b_idx[c4_k + 1] = c4_k + 1;
    }
  }

  c4_i = 2;
  while (c4_i < 19200) {
    c4_h_a = c4_i;
    c4_i2 = c4_h_a << 1;
    c4_j = 1;
    for (c4_pEnd = 1 + c4_i; c4_pEnd < 19201; c4_pEnd = c4_qEnd + c4_i) {
      c4_b_p = c4_j - 1;
      c4_q = c4_pEnd - 1;
      c4_qEnd = c4_j + c4_i2;
      if (c4_qEnd > 19201) {
        c4_qEnd = 19201;
      }

      c4_b_k = 0;
      c4_kEnd = c4_qEnd - c4_j;
      while (c4_b_k + 1 <= c4_kEnd) {
        c4_b_idx1 = c4_b_idx[c4_b_p] - 1;
        c4_b_idx2 = c4_b_idx[c4_q] - 1;
        c4_k_a = c4_c_x[c4_b_idx1];
        c4_g_b = c4_c_x[c4_b_idx2];
        c4_l_a = c4_k_a;
        c4_h_b = c4_g_b;
        c4_m_a = c4_l_a;
        c4_i_b = c4_h_b;
        c4_e_p = (c4_m_a <= c4_i_b);
        if (c4_e_p) {
          c4_f_p = true;
        } else {
          c4_e_x = c4_h_b;
          c4_j_b = muSingleScalarIsNaN(c4_e_x);
          if (c4_j_b) {
            c4_f_p = true;
          } else {
            c4_f_p = false;
          }
        }

        c4_g_p = c4_f_p;
        if (c4_g_p) {
          chartInstance->c4_iwork[c4_b_k] = c4_b_idx[c4_b_p];
          c4_b_p++;
          if (c4_b_p + 1 == c4_pEnd) {
            while (c4_q + 1 < c4_qEnd) {
              c4_b_k++;
              chartInstance->c4_iwork[c4_b_k] = c4_b_idx[c4_q];
              c4_q++;
            }
          }
        } else {
          chartInstance->c4_iwork[c4_b_k] = c4_b_idx[c4_q];
          c4_q++;
          if (c4_q + 1 == c4_qEnd) {
            while (c4_b_p + 1 < c4_pEnd) {
              c4_b_k++;
              chartInstance->c4_iwork[c4_b_k] = c4_b_idx[c4_b_p];
              c4_b_p++;
            }
          }
        }

        c4_b_k++;
      }

      c4_b_p = c4_j - 2;
      c4_st.site = &c4_vd_emlrtRSI;
      c4_e_b = c4_kEnd;
      c4_f_b = c4_e_b;
      if (1 > c4_f_b) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_f_b > 2147483646);
      }

      if (c4_overflow) {
        c4_b_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      for (c4_c_k = 1; c4_c_k - 1 < c4_kEnd; c4_c_k++) {
        c4_b_k = c4_c_k;
        c4_b_idx[c4_b_p + c4_b_k] = chartInstance->c4_iwork[c4_b_k - 1];
      }

      c4_j = c4_qEnd;
    }

    c4_i = c4_i2;
  }
}

static void c4_b_nullAssignment(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_c_x,
  boolean_T c4_idx_data[], int32_T c4_idx_size[2])
{
  c4_emxArray_real32_T *c4_d_x;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_y = NULL;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_n;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_e_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  int32_T c4_k0;
  int32_T c4_loop_ub;
  int32_T c4_n;
  int32_T c4_nb;
  int32_T c4_nxin;
  int32_T c4_nxout;
  boolean_T c4_b_overflow;
  boolean_T c4_e_b;
  boolean_T c4_overflow;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_emxInit_real32_T1(chartInstance, c4_sp, &c4_d_x, 2, &c4_dh_emlrtRTEI);
  c4_st.site = &c4_le_emlrtRSI;
  c4_i = c4_d_x->size[0] * c4_d_x->size[1];
  c4_d_x->size[0] = 1;
  c4_d_x->size[1] = c4_c_x->size[1];
  c4_b_st.site = &c4_le_emlrtRSI;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_b_st, c4_d_x, c4_i,
    &c4_dh_emlrtRTEI);
  c4_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_d_x->data[c4_i1] = c4_c_x->data[c4_i1];
  }

  c4_n = c4_d_x->size[1];
  c4_k = c4_idx_size[1];
  c4_emxFree_real32_T(chartInstance, &c4_d_x);
  while ((c4_k >= 1) && (!c4_idx_data[c4_k - 1])) {
    c4_k--;
  }

  c4_p = (c4_k <= c4_n);
  if (!c4_p) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call(&c4_st, &c4_g_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }

  c4_st.site = &c4_me_emlrtRSI;
  c4_nxin = c4_c_x->size[1];
  c4_b_st.site = &c4_ne_emlrtRSI;
  c4_b_n = 0;
  c4_i2 = c4_idx_size[1];
  c4_c_st.site = &c4_pe_emlrtRSI;
  c4_b = c4_i2;
  c4_b_b = c4_b;
  if (1 > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_d_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
  }

  for (c4_b_k = 1; c4_b_k - 1 < c4_i2; c4_b_k++) {
    c4_c_k = c4_b_k - 1;
    c4_b_n += (int32_T)c4_idx_data[c4_c_k];
  }

  c4_nxout = c4_nxin - c4_b_n;
  c4_nb = c4_idx_size[1];
  c4_k0 = -1;
  c4_b_st.site = &c4_oe_emlrtRSI;
  c4_c_b = c4_nxin;
  c4_d_b = c4_c_b;
  if (1 > c4_d_b) {
    c4_b_overflow = false;
  } else {
    c4_b_overflow = (c4_d_b > 2147483646);
  }

  if (c4_b_overflow) {
    c4_c_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  for (c4_d_k = 1; c4_d_k - 1 < c4_nxin; c4_d_k++) {
    c4_e_k = c4_d_k - 1;
    if ((c4_e_k + 1 > c4_nb) || (!c4_idx_data[c4_e_k])) {
      c4_k0++;
      c4_c_x->data[c4_k0] = c4_c_x->data[c4_e_k];
    }
  }

  if (!(c4_nxout <= c4_nxin)) {
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c4_st, &c4_h_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_d_y)));
  }

  c4_e_b = (1 > c4_nxout);
  if (c4_e_b) {
    c4_i3 = 0;
  } else {
    c4_i3 = c4_nxout;
  }

  c4_i4 = c4_c_x->size[0] * c4_c_x->size[1];
  c4_c_x->size[1] = c4_i3;
  c4_emxEnsureCapacity_real32_T1(chartInstance, &c4_st, c4_c_x, c4_i4,
    &c4_eh_emlrtRTEI);
}

static void c4_c_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_c_x)
{
  c4_emxArray_int32_T *c4_b_idx;
  c4_emxArray_int32_T *c4_b_iwork;
  c4_emxArray_real32_T *c4_xwork;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  real_T c4_b_dv[2];
  int32_T c4_idx4[4];
  int32_T c4_perm[4];
  int32_T c4_iv[1];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_i1;
  int32_T c4_b_i2;
  int32_T c4_b_i3;
  int32_T c4_b_i4;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_n;
  int32_T c4_d_b;
  int32_T c4_d_k;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_h_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_b;
  int32_T c4_ib;
  int32_T c4_itmp;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_n;
  int32_T c4_nBlocks;
  int32_T c4_nLastBlock;
  int32_T c4_nNaNs;
  int32_T c4_nNonNaN;
  int32_T c4_preSortLevel;
  int32_T c4_quartetOffset;
  int32_T c4_tailOffset;
  int32_T c4_wOffset;
  real32_T c4_x4[4];
  real32_T c4_d_x;
  boolean_T c4_b_overflow;
  boolean_T c4_c_b;
  boolean_T c4_c_overflow;
  boolean_T c4_d_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_b_idx, 2, &c4_mh_emlrtRTEI);
  c4_st.site = &c4_ye_emlrtRSI;
  c4_i = c4_b_idx->size[0] * c4_b_idx->size[1];
  c4_b_idx->size[0] = 1;
  c4_b_idx->size[1] = c4_c_x->size[1];
  c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_b_idx, c4_i,
    &c4_fh_emlrtRTEI);
  c4_loop_ub = c4_c_x->size[1] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_idx->data[c4_i1] = 0;
  }

  c4_b_st.site = &c4_af_emlrtRSI;
  c4_n = c4_c_x->size[1];
  c4_c_st.site = &c4_bf_emlrtRSI;
  c4_b_n = c4_c_x->size[1];
  for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
    c4_x4[c4_i2] = 0.0F;
  }

  for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
    c4_idx4[c4_i3] = 0;
  }

  c4_emxInit_int32_T(chartInstance, &c4_c_st, &c4_b_iwork, 1, &c4_hh_emlrtRTEI);
  c4_i4 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_b_idx->size[1];
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_iwork, c4_i4,
    &c4_gh_emlrtRTEI);
  c4_iv[0] = c4_b_iwork->size[0];
  c4_i5 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_iv[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_iwork, c4_i5,
    &c4_hh_emlrtRTEI);
  c4_i6 = c4_b_iwork->size[0];
  c4_i7 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_i6;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_iwork, c4_i7,
    &c4_ih_emlrtRTEI);
  c4_b_loop_ub = c4_i6 - 1;
  for (c4_i8 = 0; c4_i8 <= c4_b_loop_ub; c4_i8++) {
    c4_b_iwork->data[c4_i8] = 0;
  }

  c4_emxInit_real32_T(chartInstance, &c4_c_st, &c4_xwork, 1, &c4_kh_emlrtRTEI);
  c4_b_dv[0] = (real_T)c4_c_x->size[1];
  c4_i9 = c4_xwork->size[0];
  c4_xwork->size[0] = (int32_T)c4_b_dv[0];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_xwork, c4_i9,
    &c4_jh_emlrtRTEI);
  c4_iv[0] = c4_xwork->size[0];
  c4_i10 = c4_xwork->size[0];
  c4_xwork->size[0] = c4_iv[0];
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_xwork, c4_i10,
    &c4_kh_emlrtRTEI);
  c4_i11 = c4_xwork->size[0];
  c4_i12 = c4_xwork->size[0];
  c4_xwork->size[0] = c4_i11;
  c4_emxEnsureCapacity_real32_T(chartInstance, &c4_c_st, c4_xwork, c4_i12,
    &c4_lh_emlrtRTEI);
  c4_c_loop_ub = c4_i11 - 1;
  for (c4_i13 = 0; c4_i13 <= c4_c_loop_ub; c4_i13++) {
    c4_xwork->data[c4_i13] = 0.0F;
  }

  c4_nNaNs = 0;
  c4_ib = 0;
  c4_d_st.site = &c4_gf_emlrtRSI;
  c4_b = c4_b_n;
  c4_b_b = c4_b;
  if (1 > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_e_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
  }

  for (c4_k = 1; c4_k - 1 < c4_b_n; c4_k++) {
    c4_b_k = c4_k - 1;
    c4_d_x = c4_c_x->data[c4_b_k];
    c4_c_b = muSingleScalarIsNaN(c4_d_x);
    if (c4_c_b) {
      c4_b_idx->data[(c4_b_n - c4_nNaNs) - 1] = c4_b_k + 1;
      c4_xwork->data[(c4_b_n - c4_nNaNs) - 1] = c4_c_x->data[c4_b_k];
      c4_nNaNs++;
    } else {
      c4_ib++;
      c4_idx4[c4_ib - 1] = c4_b_k + 1;
      c4_x4[c4_ib - 1] = c4_c_x->data[c4_b_k];
      if (c4_ib == 4) {
        c4_quartetOffset = c4_b_k - c4_nNaNs;
        if (c4_x4[0] <= c4_x4[1]) {
          c4_b_i1 = 1;
          c4_b_i2 = 2;
        } else {
          c4_b_i1 = 2;
          c4_b_i2 = 1;
        }

        if (c4_x4[2] <= c4_x4[3]) {
          c4_b_i3 = 3;
          c4_b_i4 = 4;
        } else {
          c4_b_i3 = 4;
          c4_b_i4 = 3;
        }

        if (c4_x4[c4_b_i1 - 1] <= c4_x4[c4_b_i3 - 1]) {
          if (c4_x4[c4_b_i2 - 1] <= c4_x4[c4_b_i3 - 1]) {
            c4_perm[0] = c4_b_i1;
            c4_perm[1] = c4_b_i2;
            c4_perm[2] = c4_b_i3;
            c4_perm[3] = c4_b_i4;
          } else if (c4_x4[c4_b_i2 - 1] <= c4_x4[c4_b_i4 - 1]) {
            c4_perm[0] = c4_b_i1;
            c4_perm[1] = c4_b_i3;
            c4_perm[2] = c4_b_i2;
            c4_perm[3] = c4_b_i4;
          } else {
            c4_perm[0] = c4_b_i1;
            c4_perm[1] = c4_b_i3;
            c4_perm[2] = c4_b_i4;
            c4_perm[3] = c4_b_i2;
          }
        } else if (c4_x4[c4_b_i1 - 1] <= c4_x4[c4_b_i4 - 1]) {
          if (c4_x4[c4_b_i2 - 1] <= c4_x4[c4_b_i4 - 1]) {
            c4_perm[0] = c4_b_i3;
            c4_perm[1] = c4_b_i1;
            c4_perm[2] = c4_b_i2;
            c4_perm[3] = c4_b_i4;
          } else {
            c4_perm[0] = c4_b_i3;
            c4_perm[1] = c4_b_i1;
            c4_perm[2] = c4_b_i4;
            c4_perm[3] = c4_b_i2;
          }
        } else {
          c4_perm[0] = c4_b_i3;
          c4_perm[1] = c4_b_i4;
          c4_perm[2] = c4_b_i1;
          c4_perm[3] = c4_b_i2;
        }

        c4_b_idx->data[c4_quartetOffset - 3] = c4_idx4[c4_perm[0] - 1];
        c4_b_idx->data[c4_quartetOffset - 2] = c4_idx4[c4_perm[1] - 1];
        c4_b_idx->data[c4_quartetOffset - 1] = c4_idx4[c4_perm[2] - 1];
        c4_b_idx->data[c4_quartetOffset] = c4_idx4[c4_perm[3] - 1];
        c4_c_x->data[c4_quartetOffset - 3] = c4_x4[c4_perm[0] - 1];
        c4_c_x->data[c4_quartetOffset - 2] = c4_x4[c4_perm[1] - 1];
        c4_c_x->data[c4_quartetOffset - 1] = c4_x4[c4_perm[2] - 1];
        c4_c_x->data[c4_quartetOffset] = c4_x4[c4_perm[3] - 1];
        c4_ib = 0;
      }
    }
  }

  c4_wOffset = (c4_b_n - c4_nNaNs) - 1;
  if (c4_ib > 0) {
    c4_c_n = c4_ib;
    for (c4_i14 = 0; c4_i14 < 4; c4_i14++) {
      c4_perm[c4_i14] = 0;
    }

    if (c4_c_n == 1) {
      c4_perm[0] = 1;
    } else if (c4_c_n == 2) {
      if (c4_x4[0] <= c4_x4[1]) {
        c4_perm[0] = 1;
        c4_perm[1] = 2;
      } else {
        c4_perm[0] = 2;
        c4_perm[1] = 1;
      }
    } else if (c4_x4[0] <= c4_x4[1]) {
      if (c4_x4[1] <= c4_x4[2]) {
        c4_perm[0] = 1;
        c4_perm[1] = 2;
        c4_perm[2] = 3;
      } else if (c4_x4[0] <= c4_x4[2]) {
        c4_perm[0] = 1;
        c4_perm[1] = 3;
        c4_perm[2] = 2;
      } else {
        c4_perm[0] = 3;
        c4_perm[1] = 1;
        c4_perm[2] = 2;
      }
    } else if (c4_x4[0] <= c4_x4[2]) {
      c4_perm[0] = 2;
      c4_perm[1] = 1;
      c4_perm[2] = 3;
    } else if (c4_x4[1] <= c4_x4[2]) {
      c4_perm[0] = 2;
      c4_perm[1] = 3;
      c4_perm[2] = 1;
    } else {
      c4_perm[0] = 3;
      c4_perm[1] = 2;
      c4_perm[2] = 1;
    }

    c4_d_st.site = &c4_hf_emlrtRSI;
    c4_f_b = c4_ib;
    c4_g_b = c4_f_b;
    if (1 > c4_g_b) {
      c4_c_overflow = false;
    } else {
      c4_c_overflow = (c4_g_b > 2147483646);
    }

    if (c4_c_overflow) {
      c4_e_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
    }

    for (c4_d_k = 1; c4_d_k - 1 < c4_ib; c4_d_k++) {
      c4_b_k = c4_d_k;
      c4_b_idx->data[(c4_wOffset - c4_ib) + c4_b_k] = c4_idx4[c4_perm[c4_b_k - 1]
        - 1];
      c4_c_x->data[(c4_wOffset - c4_ib) + c4_b_k] = c4_x4[c4_perm[c4_b_k - 1] -
        1];
    }
  }

  c4_m = c4_nNaNs >> 1;
  c4_d_st.site = &c4_if_emlrtRSI;
  c4_d_b = c4_m;
  c4_e_b = c4_d_b;
  if (1 > c4_e_b) {
    c4_b_overflow = false;
  } else {
    c4_b_overflow = (c4_e_b > 2147483646);
  }

  if (c4_b_overflow) {
    c4_e_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
  }

  for (c4_c_k = 1; c4_c_k - 1 < c4_m; c4_c_k++) {
    c4_b_k = c4_c_k;
    c4_itmp = c4_b_idx->data[c4_wOffset + c4_b_k];
    c4_b_idx->data[c4_wOffset + c4_b_k] = c4_b_idx->data[c4_b_n - c4_b_k];
    c4_b_idx->data[c4_b_n - c4_b_k] = c4_itmp;
    c4_c_x->data[c4_wOffset + c4_b_k] = c4_xwork->data[c4_b_n - c4_b_k];
    c4_c_x->data[c4_b_n - c4_b_k] = c4_xwork->data[c4_wOffset + c4_b_k];
  }

  if ((c4_nNaNs & 1) != 0) {
    c4_c_x->data[(c4_wOffset + c4_m) + 1] = c4_xwork->data[(c4_wOffset + c4_m) +
      1];
  }

  c4_nNonNaN = c4_n - c4_nNaNs;
  c4_preSortLevel = 2;
  if (c4_nNonNaN > 1) {
    if (c4_n >= 256) {
      c4_nBlocks = c4_nNonNaN >> 8;
      if (c4_nBlocks > 0) {
        c4_c_st.site = &c4_cf_emlrtRSI;
        c4_h_b = c4_nBlocks;
        c4_i_b = c4_h_b;
        if (1 > c4_i_b) {
          c4_d_overflow = false;
        } else {
          c4_d_overflow = (c4_i_b > 2147483646);
        }

        if (c4_d_overflow) {
          c4_d_st.site = &c4_mb_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
        }

        for (c4_j_b = 1; c4_j_b - 1 < c4_nBlocks; c4_j_b++) {
          c4_k_b = c4_j_b - 1;
          c4_c_st.site = &c4_df_emlrtRSI;
          c4_c_merge_pow2_block(chartInstance, &c4_c_st, c4_b_idx, c4_c_x,
                                c4_k_b << 8);
        }

        c4_tailOffset = c4_nBlocks << 8;
        c4_nLastBlock = c4_nNonNaN - c4_tailOffset;
        if (c4_nLastBlock > 0) {
          c4_c_st.site = &c4_ef_emlrtRSI;
          c4_c_merge_block(chartInstance, &c4_c_st, c4_b_idx, c4_c_x,
                           c4_tailOffset, c4_nLastBlock, 2, c4_b_iwork, c4_xwork);
        }

        c4_preSortLevel = 8;
      }
    }

    c4_c_st.site = &c4_ff_emlrtRSI;
    c4_c_merge_block(chartInstance, &c4_c_st, c4_b_idx, c4_c_x, 0, c4_nNonNaN,
                     c4_preSortLevel, c4_b_iwork, c4_xwork);
  }

  c4_emxFree_real32_T(chartInstance, &c4_xwork);
  c4_emxFree_int32_T(chartInstance, &c4_b_iwork);
  c4_emxFree_int32_T(chartInstance, &c4_b_idx);
}

static void c4_c_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_c_x, int32_T c4_offset)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b_iwork[256];
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_blockOffset;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_exitg1;
  int32_T c4_f_b;
  int32_T c4_g_a;
  int32_T c4_g_b;
  int32_T c4_h_a;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_nPairs;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  real32_T c4_xwork[256];
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_b = 0; c4_b < 6; c4_b++) {
    c4_bLen = 1 << (c4_b + 2);
    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = 256 >> (c4_b + 3);
    c4_st.site = &c4_jf_emlrtRSI;
    c4_b_b = c4_nPairs;
    c4_c_b = c4_b_b;
    if (1 > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_nPairs; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_blockOffset = (c4_offset + c4_b_k * c4_bLen2) - 1;
      c4_st.site = &c4_kf_emlrtRSI;
      c4_d_b = c4_bLen2;
      c4_e_b = c4_d_b;
      if (1 > c4_e_b) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_b_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      for (c4_j = 1; c4_j - 1 < c4_bLen2; c4_j++) {
        c4_b_j = c4_j;
        c4_b_iwork[c4_b_j - 1] = c4_b_idx->data[c4_blockOffset + c4_b_j];
        c4_xwork[c4_b_j - 1] = c4_c_x->data[c4_blockOffset + c4_b_j];
      }

      c4_p = 0;
      c4_q = c4_bLen;
      c4_iout = c4_blockOffset;
      do {
        c4_exitg1 = 0;
        c4_iout++;
        if (c4_xwork[c4_p] <= c4_xwork[c4_q]) {
          c4_b_idx->data[c4_iout] = c4_b_iwork[c4_p];
          c4_c_x->data[c4_iout] = c4_xwork[c4_p];
          if (c4_p + 1 < c4_bLen) {
            c4_p++;
          } else {
            c4_exitg1 = 1;
          }
        } else {
          c4_b_idx->data[c4_iout] = c4_b_iwork[c4_q];
          c4_c_x->data[c4_iout] = c4_xwork[c4_q];
          if (c4_q + 1 < c4_bLen2) {
            c4_q++;
          } else {
            c4_offset1 = c4_iout - c4_p;
            c4_st.site = &c4_lf_emlrtRSI;
            c4_g_a = c4_p + 1;
            c4_f_b = c4_bLen;
            c4_h_a = c4_g_a;
            c4_g_b = c4_f_b;
            if (c4_h_a > c4_g_b) {
              c4_c_overflow = false;
            } else {
              c4_c_overflow = (c4_g_b > 2147483646);
            }

            if (c4_c_overflow) {
              c4_b_st.site = &c4_mb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
            }

            for (c4_c_j = c4_p + 1; c4_c_j <= c4_bLen; c4_c_j++) {
              c4_b_idx->data[c4_offset1 + c4_c_j] = c4_b_iwork[c4_c_j - 1];
              c4_c_x->data[c4_offset1 + c4_c_j] = c4_xwork[c4_c_j - 1];
            }

            c4_exitg1 = 1;
          }
        }
      } while (c4_exitg1 == 0);
    }
  }
}

static void c4_c_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real32_T *c4_c_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real32_T
  *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_k;
  int32_T c4_nBlocks;
  int32_T c4_nPairs;
  int32_T c4_nTail;
  int32_T c4_tailOffset;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_nBlocks = c4_n >> c4_preSortLevel;
  c4_bLen = 1 << c4_preSortLevel;
  while (c4_nBlocks > 1) {
    if ((c4_nBlocks & 1) != 0) {
      c4_nBlocks--;
      c4_tailOffset = c4_bLen * c4_nBlocks;
      c4_nTail = c4_n - c4_tailOffset;
      if (c4_nTail > c4_bLen) {
        c4_st.site = &c4_mf_emlrtRSI;
        c4_c_merge(chartInstance, &c4_st, c4_b_idx, c4_c_x, c4_offset +
                   c4_tailOffset, c4_bLen, c4_nTail - c4_bLen, c4_b_iwork,
                   c4_xwork);
      }
    }

    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = c4_nBlocks >> 1;
    c4_st.site = &c4_nf_emlrtRSI;
    c4_b = c4_nPairs;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_nPairs; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_st.site = &c4_of_emlrtRSI;
      c4_c_merge(chartInstance, &c4_st, c4_b_idx, c4_c_x, c4_offset + c4_b_k *
                 c4_bLen2, c4_bLen, c4_bLen, c4_b_iwork, c4_xwork);
    }

    c4_bLen = c4_bLen2;
    c4_nBlocks = c4_nPairs;
  }

  if (c4_n > c4_bLen) {
    c4_st.site = &c4_pf_emlrtRSI;
    c4_c_merge(chartInstance, &c4_st, c4_b_idx, c4_c_x, c4_offset, c4_bLen, c4_n
               - c4_bLen, c4_b_iwork, c4_xwork);
  }
}

static void c4_c_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real32_T
  *c4_c_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T *
  c4_b_iwork, c4_emxArray_real32_T *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_exitg1;
  int32_T c4_g_a;
  int32_T c4_h_a;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_n;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  int32_T c4_qend;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  if (c4_nq != 0) {
    c4_n = c4_np + c4_nq;
    c4_st.site = &c4_rf_emlrtRSI;
    c4_b = c4_n;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_j = 1; c4_j - 1 < c4_n; c4_j++) {
      c4_b_j = c4_j - 1;
      c4_b_iwork->data[c4_b_j] = c4_b_idx->data[c4_offset + c4_b_j];
      c4_xwork->data[c4_b_j] = c4_c_x->data[c4_offset + c4_b_j];
    }

    c4_p = 0;
    c4_q = c4_np;
    c4_qend = c4_np + c4_nq;
    c4_iout = c4_offset - 1;
    do {
      c4_exitg1 = 0;
      c4_iout++;
      if (c4_xwork->data[c4_p] <= c4_xwork->data[c4_q]) {
        c4_b_idx->data[c4_iout] = c4_b_iwork->data[c4_p];
        c4_c_x->data[c4_iout] = c4_xwork->data[c4_p];
        if (c4_p + 1 < c4_np) {
          c4_p++;
        } else {
          c4_exitg1 = 1;
        }
      } else {
        c4_b_idx->data[c4_iout] = c4_b_iwork->data[c4_q];
        c4_c_x->data[c4_iout] = c4_xwork->data[c4_q];
        if (c4_q + 1 < c4_qend) {
          c4_q++;
        } else {
          c4_offset1 = c4_iout - c4_p;
          c4_st.site = &c4_qf_emlrtRSI;
          c4_g_a = c4_p + 1;
          c4_c_b = c4_np;
          c4_h_a = c4_g_a;
          c4_d_b = c4_c_b;
          if (c4_h_a > c4_d_b) {
            c4_b_overflow = false;
          } else {
            c4_b_overflow = (c4_d_b > 2147483646);
          }

          if (c4_b_overflow) {
            c4_b_st.site = &c4_mb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
          }

          for (c4_c_j = c4_p + 1; c4_c_j <= c4_np; c4_c_j++) {
            c4_b_idx->data[c4_offset1 + c4_c_j] = c4_b_iwork->data[c4_c_j - 1];
            c4_c_x->data[c4_offset1 + c4_c_j] = c4_xwork->data[c4_c_j - 1];
          }

          c4_exitg1 = 1;
        }
      }
    } while (c4_exitg1 == 0);
  }
}

static void c4_b_ComputeWeightedCentroid(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, real_T c4_I[19200],
  c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_stats, c4_sHtk0WM4OMtyqkehwQYcq2
  *c4_statsAlreadyComputed)
{
  static char_T c4_b_cv[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  c4_cell_wrap_52 c4_reshapes[2];
  c4_emxArray_int32_T *c4_b_idx;
  c4_emxArray_int32_T *c4_varargout_4;
  c4_emxArray_int32_T *c4_vk;
  c4_emxArray_real_T *c4_Intensity;
  c4_emxArray_real_T *c4_b_Intensity;
  c4_emxArray_real_T *c4_c;
  c4_emxArray_real_T *c4_r;
  c4_emxArray_real_T *c4_r1;
  c4_emxArray_real_T *c4_r2;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_wc[2];
  real_T c4_M;
  real_T c4_b_k;
  real_T c4_b_n;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d_idx;
  real_T c4_d_k;
  real_T c4_f_k;
  real_T c4_sumIntensity;
  int32_T c4_sizes[2];
  int32_T c4_ab_loop_ub;
  int32_T c4_b_loop_ub;
  int32_T c4_b_stats;
  int32_T c4_bb_loop_ub;
  int32_T c4_c_idx;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_n;
  int32_T c4_c_stats;
  int32_T c4_cb_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_d_stats;
  int32_T c4_db_loop_ub;
  int32_T c4_e_k;
  int32_T c4_e_loop_ub;
  int32_T c4_e_stats;
  int32_T c4_eb_loop_ub;
  int32_T c4_expected;
  int32_T c4_f_loop_ub;
  int32_T c4_fb_loop_ub;
  int32_T c4_g_loop_ub;
  int32_T c4_gb_loop_ub;
  int32_T c4_h_loop_ub;
  int32_T c4_hb_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i100;
  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i108;
  int32_T c4_i109;
  int32_T c4_i11;
  int32_T c4_i110;
  int32_T c4_i111;
  int32_T c4_i112;
  int32_T c4_i113;
  int32_T c4_i114;
  int32_T c4_i115;
  int32_T c4_i116;
  int32_T c4_i117;
  int32_T c4_i118;
  int32_T c4_i119;
  int32_T c4_i12;
  int32_T c4_i120;
  int32_T c4_i121;
  int32_T c4_i122;
  int32_T c4_i123;
  int32_T c4_i124;
  int32_T c4_i125;
  int32_T c4_i126;
  int32_T c4_i127;
  int32_T c4_i128;
  int32_T c4_i129;
  int32_T c4_i13;
  int32_T c4_i130;
  int32_T c4_i131;
  int32_T c4_i132;
  int32_T c4_i133;
  int32_T c4_i134;
  int32_T c4_i135;
  int32_T c4_i136;
  int32_T c4_i137;
  int32_T c4_i138;
  int32_T c4_i139;
  int32_T c4_i14;
  int32_T c4_i140;
  int32_T c4_i141;
  int32_T c4_i142;
  int32_T c4_i143;
  int32_T c4_i144;
  int32_T c4_i145;
  int32_T c4_i146;
  int32_T c4_i147;
  int32_T c4_i148;
  int32_T c4_i149;
  int32_T c4_i15;
  int32_T c4_i150;
  int32_T c4_i151;
  int32_T c4_i152;
  int32_T c4_i153;
  int32_T c4_i154;
  int32_T c4_i155;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i7;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  int32_T c4_i79;
  int32_T c4_i8;
  int32_T c4_i80;
  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i9;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  int32_T c4_i99;
  int32_T c4_i_loop_ub;
  int32_T c4_ib_loop_ub;
  int32_T c4_j_loop_ub;
  int32_T c4_k;
  int32_T c4_k_loop_ub;
  int32_T c4_l_loop_ub;
  int32_T c4_loop_ub;
  int32_T c4_m_loop_ub;
  int32_T c4_n;
  int32_T c4_n_loop_ub;
  int32_T c4_o_loop_ub;
  int32_T c4_p_loop_ub;
  int32_T c4_q_loop_ub;
  int32_T c4_r_loop_ub;
  int32_T c4_result;
  int32_T c4_s_loop_ub;
  int32_T c4_t_loop_ub;
  int32_T c4_u_loop_ub;
  int32_T c4_v_loop_ub;
  int32_T c4_w_loop_ub;
  int32_T c4_x_loop_ub;
  int32_T c4_y_loop_ub;
  boolean_T c4_b;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_statsAlreadyComputed->WeightedCentroid = true;
  c4_st.site = &c4_gi_emlrtRSI;
  c4_statsAlreadyComputed->PixelList = true;
  c4_d = (real_T)c4_stats->size[0];
  c4_i = (int32_T)c4_d - 1;
  c4_k = 0;
  c4_emxInit_real_T1(chartInstance, &c4_st, &c4_Intensity, 1, &c4_sh_emlrtRTEI);
  c4_emxInit_real_T1(chartInstance, &c4_st, &c4_r, 1, &c4_xf_emlrtRTEI);
  c4_emxInitMatrix_cell_wrap_52(chartInstance, &c4_st, c4_reshapes,
    &c4_ji_emlrtRTEI);
  c4_emxInit_real_T1(chartInstance, &c4_st, &c4_c, 1, &c4_ki_emlrtRTEI);
  c4_emxInit_int32_T(chartInstance, &c4_st, &c4_varargout_4, 1, &c4_xf_emlrtRTEI);
  c4_emxInit_int32_T(chartInstance, &c4_st, &c4_b_idx, 1, &c4_rh_emlrtRTEI);
  c4_emxInit_int32_T(chartInstance, &c4_st, &c4_vk, 1, &c4_xh_emlrtRTEI);
  while (c4_k <= c4_i) {
    c4_b_k = (real_T)c4_k + 1.0;
    c4_i1 = c4_r->size[0];
    c4_i2 = c4_stats->size[0];
    c4_i3 = (int32_T)c4_b_k;
    c4_r->size[0] = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i3, 1, c4_i2,
      &c4_ah_emlrtBCI, &c4_st) - 1].PixelIdxList->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_r, c4_i1,
      &c4_nh_emlrtRTEI);
    c4_i5 = c4_stats->size[0];
    c4_i6 = (int32_T)c4_b_k;
    c4_loop_ub = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i6, 1, c4_i5,
      &c4_ah_emlrtBCI, &c4_st) - 1].PixelIdxList->size[0] - 1;
    for (c4_i8 = 0; c4_i8 <= c4_loop_ub; c4_i8++) {
      c4_i11 = c4_stats->size[0];
      c4_i13 = (int32_T)c4_b_k;
      c4_r->data[c4_i8] = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i13, 1,
        c4_i11, &c4_ah_emlrtBCI, &c4_st) - 1].PixelIdxList->data[c4_i8];
    }

    if (c4_r->size[0] != 0) {
      c4_b_st.site = &c4_ii_emlrtRSI;
      c4_i16 = c4_Intensity->size[0];
      c4_i19 = c4_stats->size[0];
      c4_i21 = (int32_T)c4_b_k;
      c4_Intensity->size[0] = c4_stats->data[emlrtDynamicBoundsCheckR2012b
        (c4_i21, 1, c4_i19, &c4_bh_emlrtBCI, &c4_b_st) - 1].PixelIdxList->size[0];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_Intensity, c4_i16,
        &c4_oh_emlrtRTEI);
      c4_i26 = c4_stats->size[0];
      c4_i29 = (int32_T)c4_b_k;
      c4_c_loop_ub = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i29, 1,
        c4_i26, &c4_bh_emlrtBCI, &c4_b_st) - 1].PixelIdxList->size[0] - 1;
      for (c4_i34 = 0; c4_i34 <= c4_c_loop_ub; c4_i34++) {
        c4_i40 = c4_stats->size[0];
        c4_i42 = (int32_T)c4_b_k;
        c4_Intensity->data[c4_i34] = c4_stats->
          data[emlrtDynamicBoundsCheckR2012b(c4_i42, 1, c4_i40, &c4_bh_emlrtBCI,
          &c4_b_st) - 1].PixelIdxList->data[c4_i34];
      }

      c4_c_st.site = &c4_ji_emlrtRSI;
      c4_i41 = c4_b_idx->size[0];
      c4_b_idx->size[0] = c4_Intensity->size[0];
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_idx, c4_i41,
        &c4_rh_emlrtRTEI);
      c4_d_loop_ub = c4_Intensity->size[0] - 1;
      for (c4_i48 = 0; c4_i48 <= c4_d_loop_ub; c4_i48++) {
        c4_b_idx->data[c4_i48] = (int32_T)c4_Intensity->data[c4_i48];
      }

      c4_i51 = c4_b_idx->size[0];
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_idx, c4_i51,
        &c4_uh_emlrtRTEI);
      c4_f_loop_ub = c4_b_idx->size[0] - 1;
      for (c4_i57 = 0; c4_i57 <= c4_f_loop_ub; c4_i57++) {
        c4_b_idx->data[c4_i57]--;
      }

      c4_i59 = c4_vk->size[0];
      c4_vk->size[0] = c4_b_idx->size[0];
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_vk, c4_i59,
        &c4_xh_emlrtRTEI);
      c4_i_loop_ub = c4_b_idx->size[0] - 1;
      for (c4_i64 = 0; c4_i64 <= c4_i_loop_ub; c4_i64++) {
        c4_vk->data[c4_i64] = c4_div_nzp_s32(chartInstance, c4_b_idx->
          data[c4_i64], 120, 0, 1U, 0, 0);
      }

      c4_i66 = c4_varargout_4->size[0];
      c4_varargout_4->size[0] = c4_vk->size[0];
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_varargout_4,
        c4_i66, &c4_yh_emlrtRTEI);
      c4_k_loop_ub = c4_vk->size[0] - 1;
      for (c4_i70 = 0; c4_i70 <= c4_k_loop_ub; c4_i70++) {
        c4_varargout_4->data[c4_i70] = c4_vk->data[c4_i70] + 1;
      }

      c4_i74 = c4_vk->size[0];
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_vk, c4_i74,
        &c4_ai_emlrtRTEI);
      c4_m_loop_ub = c4_vk->size[0] - 1;
      for (c4_i80 = 0; c4_i80 <= c4_m_loop_ub; c4_i80++) {
        c4_vk->data[c4_i80] *= 120;
      }

      c4_i81 = c4_b_idx->size[0];
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_idx, c4_i81,
        &c4_ci_emlrtRTEI);
      c4_o_loop_ub = c4_b_idx->size[0] - 1;
      for (c4_i85 = 0; c4_i85 <= c4_o_loop_ub; c4_i85++) {
        c4_b_idx->data[c4_i85] -= c4_vk->data[c4_i85];
      }

      c4_i88 = c4_b_idx->size[0];
      c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_idx, c4_i88,
        &c4_di_emlrtRTEI);
      c4_q_loop_ub = c4_b_idx->size[0] - 1;
      for (c4_i93 = 0; c4_i93 <= c4_q_loop_ub; c4_i93++) {
        c4_b_idx->data[c4_i93]++;
      }

      c4_i96 = c4_Intensity->size[0];
      c4_Intensity->size[0] = c4_b_idx->size[0];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_Intensity, c4_i96,
        &c4_ei_emlrtRTEI);
      c4_t_loop_ub = c4_b_idx->size[0] - 1;
      for (c4_i103 = 0; c4_i103 <= c4_t_loop_ub; c4_i103++) {
        c4_Intensity->data[c4_i103] = (real_T)c4_b_idx->data[c4_i103];
      }

      c4_i104 = c4_c->size[0];
      c4_c->size[0] = c4_varargout_4->size[0];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_c, c4_i104,
        &c4_ei_emlrtRTEI);
      c4_w_loop_ub = c4_varargout_4->size[0] - 1;
      for (c4_i108 = 0; c4_i108 <= c4_w_loop_ub; c4_i108++) {
        c4_c->data[c4_i108] = (real_T)c4_varargout_4->data[c4_i108];
      }

      c4_b_st.site = &c4_hi_emlrtRSI;
      c4_c_st.site = &c4_ki_emlrtRSI;
      c4_result = c4_c->size[0];
      c4_sizes[0] = c4_result;
      c4_d_st.site = &c4_li_emlrtRSI;
      c4_expected = c4_sizes[0];
      if (c4_c->size[0] == c4_expected) {
        c4_b = true;
      } else {
        c4_b = false;
      }

      if (!c4_b) {
        c4_y = NULL;
        sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c4_b_y = NULL;
        sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c4_d_st, &c4_s_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                    sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c4_d_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
      }

      if (c4_Intensity->size[0] == c4_expected) {
        c4_b = true;
      } else {
        c4_b = false;
      }

      if (!c4_b) {
        c4_c_y = NULL;
        sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c4_d_y = NULL;
        sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c4_d_st, &c4_s_emlrtMCI, "error", 0U, 2U, 14, c4_c_y, 14,
                    sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c4_d_st, NULL, "message", 1U, 1U, 14, c4_d_y)));
      }

      c4_i121 = c4_reshapes[0].f1->size[0];
      c4_reshapes[0].f1->size[0] = c4_c->size[0];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_reshapes[0].f1,
        c4_i121, &c4_gi_emlrtRTEI);
      c4_cb_loop_ub = c4_c->size[0] - 1;
      for (c4_i124 = 0; c4_i124 <= c4_cb_loop_ub; c4_i124++) {
        c4_reshapes[0].f1->data[c4_i124] = c4_c->data[c4_i124];
      }

      c4_i126 = c4_reshapes[1].f1->size[0];
      c4_reshapes[1].f1->size[0] = c4_Intensity->size[0];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_reshapes[1].f1,
        c4_i126, &c4_gi_emlrtRTEI);
      c4_eb_loop_ub = c4_Intensity->size[0] - 1;
      for (c4_i130 = 0; c4_i130 <= c4_eb_loop_ub; c4_i130++) {
        c4_reshapes[1].f1->data[c4_i130] = c4_Intensity->data[c4_i130];
      }

      c4_i131 = c4_Intensity->size[0];
      c4_Intensity->size[0] = c4_reshapes[0].f1->size[0];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_Intensity,
        c4_i131, &c4_hi_emlrtRTEI);
      c4_fb_loop_ub = c4_reshapes[0].f1->size[0] - 1;
      for (c4_i135 = 0; c4_i135 <= c4_fb_loop_ub; c4_i135++) {
        c4_Intensity->data[c4_i135] = c4_reshapes[0].f1->data[c4_i135];
      }

      c4_i138 = c4_c->size[0];
      c4_c->size[0] = c4_reshapes[1].f1->size[0];
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_c, c4_i138,
        &c4_hi_emlrtRTEI);
      c4_gb_loop_ub = c4_reshapes[1].f1->size[0] - 1;
      for (c4_i143 = 0; c4_i143 <= c4_gb_loop_ub; c4_i143++) {
        c4_c->data[c4_i143] = c4_reshapes[1].f1->data[c4_i143];
      }

      c4_e_stats = c4_stats->size[0];
      c4_i146 = (int32_T)c4_b_k;
      c4_i147 = emlrtDynamicBoundsCheckR2012b(c4_i146, 1, c4_e_stats,
        &c4_yg_emlrtBCI, &c4_c_st) - 1;
      c4_i148 = c4_stats->data[c4_i147].PixelList->size[0] * c4_stats->
        data[c4_i147].PixelList->size[1];
      c4_stats->data[c4_i147].PixelList->size[0] = c4_Intensity->size[0];
      c4_i149 = (int32_T)c4_b_k;
      c4_i150 = emlrtDynamicBoundsCheckR2012b(c4_i149, 1, c4_e_stats,
        &c4_yg_emlrtBCI, &c4_c_st) - 1;
      c4_stats->data[c4_i150].PixelList->size[1] = 2;
      c4_emxEnsureCapacity_real_T(chartInstance, &c4_c_st, c4_stats->
        data[c4_i150].PixelList, c4_i148, &c4_ii_emlrtRTEI);
      c4_hb_loop_ub = c4_Intensity->size[0] - 1;
      for (c4_i151 = 0; c4_i151 <= c4_hb_loop_ub; c4_i151++) {
        c4_i152 = (int32_T)c4_b_k;
        c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i152, 1, c4_e_stats,
          &c4_yg_emlrtBCI, &c4_c_st) - 1].PixelList->data[c4_i151] =
          c4_Intensity->data[c4_i151];
      }

      c4_ib_loop_ub = c4_c->size[0] - 1;
      for (c4_i153 = 0; c4_i153 <= c4_ib_loop_ub; c4_i153++) {
        c4_i154 = (int32_T)c4_b_k;
        c4_i155 = (int32_T)c4_b_k;
        c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i154, 1, c4_e_stats,
          &c4_yg_emlrtBCI, &c4_c_st) - 1].PixelList->data[c4_i153 +
          c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i155, 1, c4_e_stats,
          &c4_yg_emlrtBCI, &c4_c_st) - 1].PixelList->size[0]] = c4_c->
          data[c4_i153];
      }
    } else {
      c4_i12 = c4_stats->size[0];
      c4_i15 = (int32_T)c4_b_k;
      c4_i18 = emlrtDynamicBoundsCheckR2012b(c4_i15, 1, c4_i12, &c4_rg_emlrtBCI,
        &c4_st) - 1;
      c4_stats->data[c4_i18].PixelList->size[0] = 0;
      c4_i22 = c4_stats->size[0];
      c4_i24 = (int32_T)c4_b_k;
      c4_i25 = emlrtDynamicBoundsCheckR2012b(c4_i24, 1, c4_i22, &c4_rg_emlrtBCI,
        &c4_st) - 1;
      c4_i28 = c4_stats->data[c4_i25].PixelList->size[0] * c4_stats->data[c4_i25]
        .PixelList->size[1];
      c4_stats->data[c4_i25].PixelList->size[1] = 2;
      c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_stats->data[c4_i25].
        PixelList, c4_i28, &c4_qh_emlrtRTEI);
      c4_b_stats = c4_stats->size[0];
      c4_i39 = (int32_T)c4_b_k;
      emlrtDynamicBoundsCheckR2012b(c4_i39, 1, c4_b_stats, &c4_rg_emlrtBCI,
        &c4_st);
      c4_c_stats = c4_stats->size[0];
      c4_i43 = (int32_T)c4_b_k;
      emlrtDynamicBoundsCheckR2012b(c4_i43, 1, c4_c_stats, &c4_rg_emlrtBCI,
        &c4_st);
    }

    c4_k++;
  }

  c4_emxFreeMatrix_cell_wrap_52(chartInstance, c4_reshapes);
  c4_st.site = &c4_fi_emlrtRSI;
  c4_statsAlreadyComputed->PixelValues = true;
  c4_d1 = (real_T)c4_stats->size[0];
  c4_i4 = (int32_T)c4_d1 - 1;
  for (c4_c_k = 0; c4_c_k <= c4_i4; c4_c_k++) {
    c4_d_k = (real_T)c4_c_k + 1.0;
    c4_i7 = c4_r->size[0];
    c4_i9 = c4_stats->size[0];
    c4_i10 = (int32_T)c4_d_k;
    c4_r->size[0] = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i10, 1,
      c4_i9, &c4_ch_emlrtBCI, &c4_st) - 1].PixelIdxList->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_r, c4_i7,
      &c4_ph_emlrtRTEI);
    c4_i17 = c4_stats->size[0];
    c4_i20 = (int32_T)c4_d_k;
    c4_b_loop_ub = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i20, 1,
      c4_i17, &c4_ch_emlrtBCI, &c4_st) - 1].PixelIdxList->size[0] - 1;
    for (c4_i23 = 0; c4_i23 <= c4_b_loop_ub; c4_i23++) {
      c4_i27 = c4_stats->size[0];
      c4_i31 = (int32_T)c4_d_k;
      c4_r->data[c4_i23] = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i31,
        1, c4_i27, &c4_ch_emlrtBCI, &c4_st) - 1].PixelIdxList->data[c4_i23];
    }

    c4_wc[0] = (real_T)c4_r->size[0];
    c4_i30 = c4_stats->size[0];
    c4_i33 = (int32_T)c4_d_k;
    c4_i36 = emlrtDynamicBoundsCheckR2012b(c4_i33, 1, c4_i30, &c4_qg_emlrtBCI,
      &c4_st);
    c4_i38 = c4_stats->data[c4_i36 - 1].PixelValues->size[0];
    c4_stats->data[c4_i36 - 1].PixelValues->size[0] = (int32_T)c4_wc[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_stats->data[c4_i36 -
      1].PixelValues, c4_i38, &c4_th_emlrtRTEI);
    c4_b_st.site = &c4_mi_emlrtRSI;
    c4_i45 = c4_Intensity->size[0];
    c4_i47 = c4_stats->size[0];
    c4_i49 = (int32_T)c4_d_k;
    c4_Intensity->size[0] = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i49,
      1, c4_i47, &c4_fh_emlrtBCI, &c4_b_st) - 1].PixelIdxList->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_Intensity, c4_i45,
      &c4_vh_emlrtRTEI);
    c4_i54 = c4_stats->size[0];
    c4_i56 = (int32_T)c4_d_k;
    c4_g_loop_ub = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i56, 1,
      c4_i54, &c4_fh_emlrtBCI, &c4_b_st) - 1].PixelIdxList->size[0] - 1;
    for (c4_i58 = 0; c4_i58 <= c4_g_loop_ub; c4_i58++) {
      c4_i61 = c4_stats->size[0];
      c4_i63 = (int32_T)c4_d_k;
      c4_Intensity->data[c4_i58] = c4_stats->data[emlrtDynamicBoundsCheckR2012b
        (c4_i63, 1, c4_i61, &c4_fh_emlrtBCI, &c4_b_st) - 1].PixelIdxList->
        data[c4_i58];
    }

    c4_c_st.site = &c4_ji_emlrtRSI;
    c4_i62 = c4_b_idx->size[0];
    c4_b_idx->size[0] = c4_Intensity->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_idx, c4_i62,
      &c4_rh_emlrtRTEI);
    c4_j_loop_ub = c4_Intensity->size[0] - 1;
    for (c4_i68 = 0; c4_i68 <= c4_j_loop_ub; c4_i68++) {
      c4_b_idx->data[c4_i68] = (int32_T)c4_Intensity->data[c4_i68];
    }

    c4_i69 = c4_b_idx->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_idx, c4_i69,
      &c4_uh_emlrtRTEI);
    c4_l_loop_ub = c4_b_idx->size[0] - 1;
    for (c4_i73 = 0; c4_i73 <= c4_l_loop_ub; c4_i73++) {
      c4_b_idx->data[c4_i73]--;
    }

    c4_i78 = c4_vk->size[0];
    c4_vk->size[0] = c4_b_idx->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_vk, c4_i78,
      &c4_xh_emlrtRTEI);
    c4_n_loop_ub = c4_b_idx->size[0] - 1;
    for (c4_i82 = 0; c4_i82 <= c4_n_loop_ub; c4_i82++) {
      c4_vk->data[c4_i82] = c4_div_nzp_s32(chartInstance, c4_b_idx->data[c4_i82],
        120, 0, 1U, 0, 0);
    }

    c4_i84 = c4_varargout_4->size[0];
    c4_varargout_4->size[0] = c4_vk->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_varargout_4, c4_i84,
      &c4_yh_emlrtRTEI);
    c4_p_loop_ub = c4_vk->size[0] - 1;
    for (c4_i91 = 0; c4_i91 <= c4_p_loop_ub; c4_i91++) {
      c4_varargout_4->data[c4_i91] = c4_vk->data[c4_i91] + 1;
    }

    c4_i94 = c4_vk->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_vk, c4_i94,
      &c4_ai_emlrtRTEI);
    c4_s_loop_ub = c4_vk->size[0] - 1;
    for (c4_i98 = 0; c4_i98 <= c4_s_loop_ub; c4_i98++) {
      c4_vk->data[c4_i98] *= 120;
    }

    c4_i102 = c4_b_idx->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_idx, c4_i102,
      &c4_ci_emlrtRTEI);
    c4_u_loop_ub = c4_b_idx->size[0] - 1;
    for (c4_i105 = 0; c4_i105 <= c4_u_loop_ub; c4_i105++) {
      c4_b_idx->data[c4_i105] -= c4_vk->data[c4_i105];
    }

    c4_i107 = c4_b_idx->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_idx, c4_i107,
      &c4_di_emlrtRTEI);
    c4_x_loop_ub = c4_b_idx->size[0] - 1;
    for (c4_i111 = 0; c4_i111 <= c4_x_loop_ub; c4_i111++) {
      c4_b_idx->data[c4_i111]++;
    }

    c4_i113 = c4_Intensity->size[0];
    c4_Intensity->size[0] = c4_b_idx->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_Intensity, c4_i113,
      &c4_ei_emlrtRTEI);
    c4_y_loop_ub = c4_b_idx->size[0] - 1;
    for (c4_i114 = 0; c4_i114 <= c4_y_loop_ub; c4_i114++) {
      c4_Intensity->data[c4_i114] = (real_T)c4_b_idx->data[c4_i114];
    }

    c4_i116 = c4_c->size[0];
    c4_c->size[0] = c4_varargout_4->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_b_st, c4_c, c4_i116,
      &c4_ei_emlrtRTEI);
    c4_bb_loop_ub = c4_varargout_4->size[0] - 1;
    for (c4_i117 = 0; c4_i117 <= c4_bb_loop_ub; c4_i117++) {
      c4_c->data[c4_i117] = (real_T)c4_varargout_4->data[c4_i117];
    }

    c4_i118 = c4_r->size[0];
    c4_i119 = c4_stats->size[0];
    c4_i120 = (int32_T)c4_d_k;
    c4_r->size[0] = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i120, 1,
      c4_i119, &c4_hh_emlrtBCI, &c4_st) - 1].PixelValues->size[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_r, c4_i118,
      &c4_fi_emlrtRTEI);
    c4_i122 = c4_stats->size[0];
    c4_i123 = (int32_T)c4_d_k;
    c4_db_loop_ub = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i123, 1,
      c4_i122, &c4_hh_emlrtBCI, &c4_st) - 1].PixelValues->size[0] - 1;
    for (c4_i125 = 0; c4_i125 <= c4_db_loop_ub; c4_i125++) {
      c4_i127 = c4_stats->size[0];
      c4_i129 = (int32_T)c4_d_k;
      c4_r->data[c4_i125] = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i129,
        1, c4_i127, &c4_hh_emlrtBCI, &c4_st) - 1].PixelValues->data[c4_i125];
    }

    c4_d3 = (real_T)c4_r->size[0];
    c4_i128 = (int32_T)c4_d3 - 1;
    for (c4_c_idx = 0; c4_c_idx <= c4_i128; c4_c_idx++) {
      c4_d_idx = (real_T)c4_c_idx + 1.0;
      c4_i132 = c4_stats->size[0];
      c4_i133 = (int32_T)c4_d_k;
      c4_i134 = emlrtDynamicBoundsCheckR2012b(c4_i133, 1, c4_i132,
        &c4_pg_emlrtBCI, &c4_st) - 1;
      c4_i136 = c4_Intensity->size[0];
      c4_i137 = (int32_T)c4_d_idx;
      c4_i139 = (int32_T)c4_Intensity->data[emlrtDynamicBoundsCheckR2012b
        (c4_i137, 1, c4_i136, &c4_vg_emlrtBCI, &c4_st) - 1];
      c4_i140 = c4_c->size[0];
      c4_i141 = (int32_T)c4_d_idx;
      c4_i142 = (int32_T)c4_c->data[emlrtDynamicBoundsCheckR2012b(c4_i141, 1,
        c4_i140, &c4_vg_emlrtBCI, &c4_st) - 1];
      c4_i144 = c4_stats->data[c4_i134].PixelValues->size[0];
      c4_i145 = (int32_T)c4_d_idx;
      c4_stats->data[c4_i134].PixelValues->data[emlrtDynamicBoundsCheckR2012b
        (c4_i145, 1, c4_i144, &c4_xg_emlrtBCI, &c4_st) - 1] = c4_I
        [(emlrtDynamicBoundsCheckR2012b(c4_i139, 1, 120, &c4_ug_emlrtBCI, &c4_st)
          + 120 * (emlrtDynamicBoundsCheckR2012b(c4_i142, 1, 160,
            &c4_wg_emlrtBCI, &c4_st) - 1)) - 1];
    }
  }

  c4_emxFree_int32_T(chartInstance, &c4_vk);
  c4_emxFree_int32_T(chartInstance, &c4_b_idx);
  c4_emxFree_int32_T(chartInstance, &c4_varargout_4);
  c4_emxFree_real_T(chartInstance, &c4_c);
  c4_d2 = (real_T)c4_stats->size[0];
  c4_i14 = (int32_T)c4_d2 - 1;
  c4_e_k = 0;
  c4_emxInit_real_T(chartInstance, c4_sp, &c4_r1, 2, &c4_xf_emlrtRTEI);
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_r2, 1, &c4_bi_emlrtRTEI);
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_b_Intensity, 1, &c4_wh_emlrtRTEI);
  while (c4_e_k <= c4_i14) {
    c4_f_k = (real_T)c4_e_k + 1.0;
    c4_i32 = c4_Intensity->size[0];
    c4_i35 = c4_stats->size[0];
    c4_i37 = (int32_T)c4_f_k;
    c4_Intensity->size[0] = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i37,
      1, c4_i35, &c4_dh_emlrtBCI, c4_sp) - 1].PixelValues->size[0];
    c4_st.site = &c4_ll_emlrtRSI;
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_Intensity, c4_i32,
      &c4_sh_emlrtRTEI);
    c4_i44 = c4_stats->size[0];
    c4_i46 = (int32_T)c4_f_k;
    c4_e_loop_ub = c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i46, 1,
      c4_i44, &c4_dh_emlrtBCI, c4_sp) - 1].PixelValues->size[0] - 1;
    for (c4_i50 = 0; c4_i50 <= c4_e_loop_ub; c4_i50++) {
      c4_i53 = c4_stats->size[0];
      c4_i55 = (int32_T)c4_f_k;
      c4_Intensity->data[c4_i50] = c4_stats->data[emlrtDynamicBoundsCheckR2012b
        (c4_i55, 1, c4_i53, &c4_eh_emlrtBCI, c4_sp) - 1].PixelValues->
        data[c4_i50];
    }

    c4_i52 = c4_b_Intensity->size[0];
    c4_b_Intensity->size[0] = c4_Intensity->size[0];
    c4_st.site = &c4_ei_emlrtRSI;
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_b_Intensity, c4_i52,
      &c4_wh_emlrtRTEI);
    c4_h_loop_ub = c4_Intensity->size[0] - 1;
    for (c4_i60 = 0; c4_i60 <= c4_h_loop_ub; c4_i60++) {
      c4_b_Intensity->data[c4_i60] = c4_Intensity->data[c4_i60];
    }

    c4_st.site = &c4_ei_emlrtRSI;
    c4_sumIntensity = c4_b_sum(chartInstance, &c4_st, c4_b_Intensity);
    c4_i65 = c4_stats->size[0];
    c4_i67 = (int32_T)c4_f_k;
    emlrtDynamicBoundsCheckR2012b(c4_i67, 1, c4_i65, &c4_og_emlrtBCI, c4_sp);
    for (c4_n = 0; c4_n < 2; c4_n++) {
      c4_b_n = (real_T)c4_n + 1.0;
      c4_i72 = c4_stats->size[0];
      c4_i75 = (int32_T)c4_f_k;
      c4_i77 = emlrtDynamicBoundsCheckR2012b(c4_i75, 1, c4_i72, &c4_sg_emlrtBCI,
        c4_sp) - 1;
      c4_i79 = c4_r1->size[0] * c4_r1->size[1];
      c4_r1->size[0] = c4_stats->data[c4_i77].PixelList->size[0];
      c4_r1->size[1] = 2;
      c4_st.site = &c4_di_emlrtRSI;
      c4_emxEnsureCapacity_real_T(chartInstance, &c4_st, c4_r1, c4_i79,
        &c4_bi_emlrtRTEI);
      c4_i83 = c4_stats->size[0];
      c4_i86 = (int32_T)c4_f_k;
      c4_i87 = emlrtDynamicBoundsCheckR2012b(c4_i86, 1, c4_i83, &c4_sg_emlrtBCI,
        c4_sp) - 1;
      c4_i89 = c4_stats->size[0];
      c4_i90 = (int32_T)c4_f_k;
      c4_i92 = emlrtDynamicBoundsCheckR2012b(c4_i90, 1, c4_i89, &c4_sg_emlrtBCI,
        c4_sp) - 1;
      c4_r_loop_ub = c4_stats->data[c4_i87].PixelList->size[0] * c4_stats->
        data[c4_i92].PixelList->size[1] - 1;
      for (c4_i95 = 0; c4_i95 <= c4_r_loop_ub; c4_i95++) {
        c4_i97 = c4_stats->size[0];
        c4_i100 = (int32_T)c4_f_k;
        c4_r1->data[c4_i95] = c4_stats->data[emlrtDynamicBoundsCheckR2012b
          (c4_i100, 1, c4_i97, &c4_gh_emlrtBCI, c4_sp) - 1].PixelList->
          data[c4_i95];
      }

      c4_c_n = (int32_T)c4_b_n - 1;
      c4_i99 = c4_r1->size[0] - 1;
      c4_i101 = c4_r->size[0];
      c4_r->size[0] = c4_i99 + 1;
      c4_st.site = &c4_di_emlrtRSI;
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_r, c4_i101,
        &c4_bi_emlrtRTEI);
      c4_v_loop_ub = c4_i99;
      for (c4_i106 = 0; c4_i106 <= c4_v_loop_ub; c4_i106++) {
        c4_r->data[c4_i106] = c4_r1->data[c4_i106 + c4_r1->size[0] * c4_c_n];
      }

      c4_i109 = c4_r->size[0];
      c4_i110 = c4_Intensity->size[0];
      emlrtSizeEqCheck1DR2012b(c4_i109, c4_i110, &c4_c_emlrtECI, c4_sp);
      c4_i112 = c4_r2->size[0];
      c4_r2->size[0] = c4_r->size[0];
      c4_st.site = &c4_di_emlrtRSI;
      c4_emxEnsureCapacity_real_T1(chartInstance, &c4_st, c4_r2, c4_i112,
        &c4_bi_emlrtRTEI);
      c4_ab_loop_ub = c4_r->size[0] - 1;
      for (c4_i115 = 0; c4_i115 <= c4_ab_loop_ub; c4_i115++) {
        c4_r2->data[c4_i115] = c4_r->data[c4_i115] * c4_Intensity->data[c4_i115];
      }

      c4_st.site = &c4_di_emlrtRSI;
      c4_M = c4_b_sum(chartInstance, &c4_st, c4_r2);
      c4_wc[(int32_T)c4_b_n - 1] = c4_M / c4_sumIntensity;
    }

    c4_d_stats = c4_stats->size[0];
    for (c4_i71 = 0; c4_i71 < 2; c4_i71++) {
      c4_i76 = (int32_T)c4_f_k;
      c4_stats->data[emlrtDynamicBoundsCheckR2012b(c4_i76, 1, c4_d_stats,
        &c4_tg_emlrtBCI, c4_sp) - 1].WeightedCentroid[c4_i71] = c4_wc[c4_i71];
    }

    c4_e_k++;
  }

  c4_emxFree_real_T(chartInstance, &c4_b_Intensity);
  c4_emxFree_real_T(chartInstance, &c4_r2);
  c4_emxFree_real_T(chartInstance, &c4_r);
  c4_emxFree_real_T(chartInstance, &c4_r1);
  c4_emxFree_real_T(chartInstance, &c4_Intensity);
}

static void c4_b_round(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_d_x;
  real_T c4_e_x;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_k;
  int32_T c4_nx;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_ri_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_nx = c4_c_x->size[0];
  c4_b_st.site = &c4_si_emlrtRSI;
  c4_b = c4_nx;
  c4_b_b = c4_b;
  if (1 > c4_b_b) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_b_b > 2147483646);
  }

  if (c4_overflow) {
    c4_c_st.site = &c4_mb_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
  }

  for (c4_k = 1; c4_k - 1 < c4_nx; c4_k++) {
    c4_b_k = c4_k - 1;
    c4_d_x = c4_c_x->data[c4_b_k];
    c4_e_x = c4_d_x;
    c4_e_x = muDoubleScalarRound(c4_e_x);
    c4_c_x->data[c4_b_k] = c4_e_x;
  }
}

static void c4_d_sort(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, c4_emxArray_real_T *c4_c_x,
                      c4_emxArray_int32_T *c4_b_idx)
{
  c4_emxArray_int32_T *c4_b_iwork;
  c4_emxArray_real_T *c4_xwork;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  real_T c4_x4[4];
  real_T c4_b_dv[2];
  real_T c4_d_x;
  int32_T c4_idx4[4];
  int32_T c4_perm[4];
  int32_T c4_iv[1];
  int32_T c4_b_b;
  int32_T c4_b_i1;
  int32_T c4_b_i2;
  int32_T c4_b_i3;
  int32_T c4_b_i4;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_b_n;
  int32_T c4_b_nNaNs;
  int32_T c4_b_nNonNaN;
  int32_T c4_c_b;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_n;
  int32_T c4_d_k;
  int32_T c4_e_b;
  int32_T c4_e_k;
  int32_T c4_f_b;
  int32_T c4_f_k;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_h_b;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_b;
  int32_T c4_ib;
  int32_T c4_itmp;
  int32_T c4_j_b;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_l_b;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_m_b;
  int32_T c4_n;
  int32_T c4_nBlocks;
  int32_T c4_nLastBlock;
  int32_T c4_nNaNs;
  int32_T c4_nNonNaN;
  int32_T c4_n_b;
  int32_T c4_o_b;
  int32_T c4_p_b;
  int32_T c4_preSortLevel;
  int32_T c4_quartetOffset;
  int32_T c4_tailOffset;
  int32_T c4_wOffset;
  boolean_T c4_b;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_d_b;
  boolean_T c4_d_overflow;
  boolean_T c4_e_overflow;
  boolean_T c4_f_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_ye_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_b_dv[c4_i] = (real_T)c4_c_x->size[c4_i];
  }

  c4_i1 = c4_b_idx->size[0] * c4_b_idx->size[1];
  c4_b_idx->size[0] = (int32_T)c4_b_dv[0];
  c4_b_idx->size[1] = 1;
  c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_b_idx, c4_i1,
    &c4_li_emlrtRTEI);
  c4_loop_ub = (int32_T)c4_b_dv[0] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_b_idx->data[c4_i2] = 0;
  }

  c4_b = (c4_c_x->size[0] == 0);
  if (!c4_b) {
    c4_b_st.site = &c4_ui_emlrtRSI;
    c4_b_st.site = &c4_af_emlrtRSI;
    c4_n = c4_c_x->size[0];
    c4_c_st.site = &c4_bf_emlrtRSI;
    c4_b_n = c4_c_x->size[0];
    for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
      c4_x4[c4_i3] = 0.0;
    }

    for (c4_i4 = 0; c4_i4 < 4; c4_i4++) {
      c4_idx4[c4_i4] = 0;
    }

    c4_emxInit_int32_T(chartInstance, &c4_c_st, &c4_b_iwork, 1, &c4_hh_emlrtRTEI);
    c4_i5 = c4_b_iwork->size[0];
    c4_b_iwork->size[0] = c4_b_idx->size[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_iwork, c4_i5,
      &c4_gh_emlrtRTEI);
    c4_iv[0] = c4_b_iwork->size[0];
    c4_i6 = c4_b_iwork->size[0];
    c4_b_iwork->size[0] = c4_iv[0];
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_iwork, c4_i6,
      &c4_hh_emlrtRTEI);
    c4_i7 = c4_b_iwork->size[0];
    c4_i8 = c4_b_iwork->size[0];
    c4_b_iwork->size[0] = c4_i7;
    c4_emxEnsureCapacity_int32_T(chartInstance, &c4_c_st, c4_b_iwork, c4_i8,
      &c4_ih_emlrtRTEI);
    c4_b_loop_ub = c4_i7 - 1;
    for (c4_i9 = 0; c4_i9 <= c4_b_loop_ub; c4_i9++) {
      c4_b_iwork->data[c4_i9] = 0;
    }

    c4_emxInit_real_T1(chartInstance, &c4_c_st, &c4_xwork, 1, &c4_kh_emlrtRTEI);
    c4_b_dv[0] = (real_T)c4_c_x->size[0];
    c4_i10 = c4_xwork->size[0];
    c4_xwork->size[0] = (int32_T)c4_b_dv[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_xwork, c4_i10,
      &c4_jh_emlrtRTEI);
    c4_iv[0] = c4_xwork->size[0];
    c4_i11 = c4_xwork->size[0];
    c4_xwork->size[0] = c4_iv[0];
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_xwork, c4_i11,
      &c4_kh_emlrtRTEI);
    c4_i12 = c4_xwork->size[0];
    c4_i13 = c4_xwork->size[0];
    c4_xwork->size[0] = c4_i12;
    c4_emxEnsureCapacity_real_T1(chartInstance, &c4_c_st, c4_xwork, c4_i13,
      &c4_lh_emlrtRTEI);
    c4_c_loop_ub = c4_i12 - 1;
    for (c4_i14 = 0; c4_i14 <= c4_c_loop_ub; c4_i14++) {
      c4_xwork->data[c4_i14] = 0.0;
    }

    c4_nNaNs = 0;
    c4_ib = 0;
    c4_d_st.site = &c4_gf_emlrtRSI;
    c4_b_b = c4_b_n;
    c4_c_b = c4_b_b;
    if (1 > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_e_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_b_n; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_d_x = c4_c_x->data[c4_b_k];
      c4_d_b = muDoubleScalarIsNaN(c4_d_x);
      if (c4_d_b) {
        c4_b_idx->data[(c4_b_n - c4_nNaNs) - 1] = c4_b_k + 1;
        c4_xwork->data[(c4_b_n - c4_nNaNs) - 1] = c4_c_x->data[c4_b_k];
        c4_nNaNs++;
      } else {
        c4_ib++;
        c4_idx4[c4_ib - 1] = c4_b_k + 1;
        c4_x4[c4_ib - 1] = c4_c_x->data[c4_b_k];
        if (c4_ib == 4) {
          c4_quartetOffset = c4_b_k - c4_nNaNs;
          if (c4_x4[0] >= c4_x4[1]) {
            c4_b_i1 = 1;
            c4_b_i2 = 2;
          } else {
            c4_b_i1 = 2;
            c4_b_i2 = 1;
          }

          if (c4_x4[2] >= c4_x4[3]) {
            c4_b_i3 = 3;
            c4_b_i4 = 4;
          } else {
            c4_b_i3 = 4;
            c4_b_i4 = 3;
          }

          if (c4_x4[c4_b_i1 - 1] >= c4_x4[c4_b_i3 - 1]) {
            if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_b_i3 - 1]) {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i2;
              c4_perm[2] = c4_b_i3;
              c4_perm[3] = c4_b_i4;
            } else if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_b_i4 - 1]) {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i3;
              c4_perm[2] = c4_b_i2;
              c4_perm[3] = c4_b_i4;
            } else {
              c4_perm[0] = c4_b_i1;
              c4_perm[1] = c4_b_i3;
              c4_perm[2] = c4_b_i4;
              c4_perm[3] = c4_b_i2;
            }
          } else if (c4_x4[c4_b_i1 - 1] >= c4_x4[c4_b_i4 - 1]) {
            if (c4_x4[c4_b_i2 - 1] >= c4_x4[c4_b_i4 - 1]) {
              c4_perm[0] = c4_b_i3;
              c4_perm[1] = c4_b_i1;
              c4_perm[2] = c4_b_i2;
              c4_perm[3] = c4_b_i4;
            } else {
              c4_perm[0] = c4_b_i3;
              c4_perm[1] = c4_b_i1;
              c4_perm[2] = c4_b_i4;
              c4_perm[3] = c4_b_i2;
            }
          } else {
            c4_perm[0] = c4_b_i3;
            c4_perm[1] = c4_b_i4;
            c4_perm[2] = c4_b_i1;
            c4_perm[3] = c4_b_i2;
          }

          c4_b_idx->data[c4_quartetOffset - 3] = c4_idx4[c4_perm[0] - 1];
          c4_b_idx->data[c4_quartetOffset - 2] = c4_idx4[c4_perm[1] - 1];
          c4_b_idx->data[c4_quartetOffset - 1] = c4_idx4[c4_perm[2] - 1];
          c4_b_idx->data[c4_quartetOffset] = c4_idx4[c4_perm[3] - 1];
          c4_c_x->data[c4_quartetOffset - 3] = c4_x4[c4_perm[0] - 1];
          c4_c_x->data[c4_quartetOffset - 2] = c4_x4[c4_perm[1] - 1];
          c4_c_x->data[c4_quartetOffset - 1] = c4_x4[c4_perm[2] - 1];
          c4_c_x->data[c4_quartetOffset] = c4_x4[c4_perm[3] - 1];
          c4_ib = 0;
        }
      }
    }

    c4_wOffset = (c4_b_n - c4_nNaNs) - 1;
    if (c4_ib > 0) {
      c4_c_n = c4_ib;
      for (c4_i15 = 0; c4_i15 < 4; c4_i15++) {
        c4_perm[c4_i15] = 0;
      }

      if (c4_c_n == 1) {
        c4_perm[0] = 1;
      } else if (c4_c_n == 2) {
        if (c4_x4[0] >= c4_x4[1]) {
          c4_perm[0] = 1;
          c4_perm[1] = 2;
        } else {
          c4_perm[0] = 2;
          c4_perm[1] = 1;
        }
      } else if (c4_x4[0] >= c4_x4[1]) {
        if (c4_x4[1] >= c4_x4[2]) {
          c4_perm[0] = 1;
          c4_perm[1] = 2;
          c4_perm[2] = 3;
        } else if (c4_x4[0] >= c4_x4[2]) {
          c4_perm[0] = 1;
          c4_perm[1] = 3;
          c4_perm[2] = 2;
        } else {
          c4_perm[0] = 3;
          c4_perm[1] = 1;
          c4_perm[2] = 2;
        }
      } else if (c4_x4[0] >= c4_x4[2]) {
        c4_perm[0] = 2;
        c4_perm[1] = 1;
        c4_perm[2] = 3;
      } else if (c4_x4[1] >= c4_x4[2]) {
        c4_perm[0] = 2;
        c4_perm[1] = 3;
        c4_perm[2] = 1;
      } else {
        c4_perm[0] = 3;
        c4_perm[1] = 2;
        c4_perm[2] = 1;
      }

      c4_d_st.site = &c4_hf_emlrtRSI;
      c4_g_b = c4_ib;
      c4_h_b = c4_g_b;
      if (1 > c4_h_b) {
        c4_c_overflow = false;
      } else {
        c4_c_overflow = (c4_h_b > 2147483646);
      }

      if (c4_c_overflow) {
        c4_e_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      for (c4_d_k = 1; c4_d_k - 1 < c4_ib; c4_d_k++) {
        c4_b_k = c4_d_k;
        c4_b_idx->data[(c4_wOffset - c4_ib) + c4_b_k] = c4_idx4[c4_perm[c4_b_k -
          1] - 1];
        c4_c_x->data[(c4_wOffset - c4_ib) + c4_b_k] = c4_x4[c4_perm[c4_b_k - 1]
          - 1];
      }
    }

    c4_m = c4_nNaNs >> 1;
    c4_d_st.site = &c4_if_emlrtRSI;
    c4_e_b = c4_m;
    c4_f_b = c4_e_b;
    if (1 > c4_f_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_f_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_e_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
    }

    for (c4_c_k = 1; c4_c_k - 1 < c4_m; c4_c_k++) {
      c4_b_k = c4_c_k;
      c4_itmp = c4_b_idx->data[c4_wOffset + c4_b_k];
      c4_b_idx->data[c4_wOffset + c4_b_k] = c4_b_idx->data[c4_b_n - c4_b_k];
      c4_b_idx->data[c4_b_n - c4_b_k] = c4_itmp;
      c4_c_x->data[c4_wOffset + c4_b_k] = c4_xwork->data[c4_b_n - c4_b_k];
      c4_c_x->data[c4_b_n - c4_b_k] = c4_xwork->data[c4_wOffset + c4_b_k];
    }

    if ((c4_nNaNs & 1) != 0) {
      c4_c_x->data[(c4_wOffset + c4_m) + 1] = c4_xwork->data[(c4_wOffset + c4_m)
        + 1];
    }

    c4_nNonNaN = c4_n - c4_nNaNs;
    c4_preSortLevel = 2;
    if (c4_nNonNaN > 1) {
      if (c4_n >= 256) {
        c4_nBlocks = c4_nNonNaN >> 8;
        if (c4_nBlocks > 0) {
          c4_c_st.site = &c4_cf_emlrtRSI;
          c4_i_b = c4_nBlocks;
          c4_j_b = c4_i_b;
          if (1 > c4_j_b) {
            c4_d_overflow = false;
          } else {
            c4_d_overflow = (c4_j_b > 2147483646);
          }

          if (c4_d_overflow) {
            c4_d_st.site = &c4_mb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
          }

          for (c4_m_b = 1; c4_m_b - 1 < c4_nBlocks; c4_m_b++) {
            c4_n_b = c4_m_b - 1;
            c4_c_st.site = &c4_df_emlrtRSI;
            c4_d_merge_pow2_block(chartInstance, &c4_c_st, c4_b_idx, c4_c_x,
                                  c4_n_b << 8);
          }

          c4_tailOffset = c4_nBlocks << 8;
          c4_nLastBlock = c4_nNonNaN - c4_tailOffset;
          if (c4_nLastBlock > 0) {
            c4_c_st.site = &c4_ef_emlrtRSI;
            c4_d_merge_block(chartInstance, &c4_c_st, c4_b_idx, c4_c_x,
                             c4_tailOffset, c4_nLastBlock, 2, c4_b_iwork,
                             c4_xwork);
          }

          c4_preSortLevel = 8;
        }
      }

      c4_c_st.site = &c4_ff_emlrtRSI;
      c4_d_merge_block(chartInstance, &c4_c_st, c4_b_idx, c4_c_x, 0, c4_nNonNaN,
                       c4_preSortLevel, c4_b_iwork, c4_xwork);
    }

    if ((c4_nNaNs > 0) && (c4_nNonNaN > 0)) {
      c4_c_st.site = &c4_vi_emlrtRSI;
      c4_b_nNonNaN = c4_nNonNaN - 1;
      c4_b_nNaNs = c4_nNaNs - 1;
      c4_d_st.site = &c4_wi_emlrtRSI;
      c4_k_b = c4_b_nNaNs + 1;
      c4_l_b = c4_k_b;
      if (1 > c4_l_b) {
        c4_e_overflow = false;
      } else {
        c4_e_overflow = (c4_l_b > 2147483646);
      }

      if (c4_e_overflow) {
        c4_e_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      for (c4_e_k = 1; c4_e_k - 1 <= c4_b_nNaNs; c4_e_k++) {
        c4_g_k = c4_e_k;
        c4_xwork->data[c4_g_k - 1] = c4_c_x->data[c4_b_nNonNaN + c4_g_k];
        c4_b_iwork->data[c4_g_k - 1] = c4_b_idx->data[c4_b_nNonNaN + c4_g_k];
      }

      for (c4_f_k = c4_b_nNonNaN + 1; c4_f_k > 0; c4_f_k--) {
        c4_c_x->data[c4_b_nNaNs + c4_f_k] = c4_c_x->data[c4_f_k - 1];
        c4_b_idx->data[c4_b_nNaNs + c4_f_k] = c4_b_idx->data[c4_f_k - 1];
      }

      c4_d_st.site = &c4_xi_emlrtRSI;
      c4_o_b = c4_b_nNaNs + 1;
      c4_p_b = c4_o_b;
      if (1 > c4_p_b) {
        c4_f_overflow = false;
      } else {
        c4_f_overflow = (c4_p_b > 2147483646);
      }

      if (c4_f_overflow) {
        c4_e_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      for (c4_h_k = 1; c4_h_k - 1 <= c4_b_nNaNs; c4_h_k++) {
        c4_g_k = c4_h_k - 1;
        c4_c_x->data[c4_g_k] = c4_xwork->data[c4_g_k];
        c4_b_idx->data[c4_g_k] = c4_b_iwork->data[c4_g_k];
      }
    }

    c4_emxFree_real_T(chartInstance, &c4_xwork);
    c4_emxFree_int32_T(chartInstance, &c4_b_iwork);
  }
}

static void c4_d_merge_pow2_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real_T *c4_c_x, int32_T c4_offset)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_xwork[256];
  int32_T c4_b_iwork[256];
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_b_k;
  int32_T c4_blockOffset;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_e_b;
  int32_T c4_exitg1;
  int32_T c4_f_b;
  int32_T c4_g_a;
  int32_T c4_g_b;
  int32_T c4_h_a;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_nPairs;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  boolean_T c4_b_overflow;
  boolean_T c4_c_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  for (c4_b = 0; c4_b < 6; c4_b++) {
    c4_bLen = 1 << (c4_b + 2);
    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = 256 >> (c4_b + 3);
    c4_st.site = &c4_jf_emlrtRSI;
    c4_b_b = c4_nPairs;
    c4_c_b = c4_b_b;
    if (1 > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_nPairs; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_blockOffset = (c4_offset + c4_b_k * c4_bLen2) - 1;
      c4_st.site = &c4_kf_emlrtRSI;
      c4_d_b = c4_bLen2;
      c4_e_b = c4_d_b;
      if (1 > c4_e_b) {
        c4_b_overflow = false;
      } else {
        c4_b_overflow = (c4_e_b > 2147483646);
      }

      if (c4_b_overflow) {
        c4_b_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      for (c4_j = 1; c4_j - 1 < c4_bLen2; c4_j++) {
        c4_b_j = c4_j;
        c4_b_iwork[c4_b_j - 1] = c4_b_idx->data[c4_blockOffset + c4_b_j];
        c4_xwork[c4_b_j - 1] = c4_c_x->data[c4_blockOffset + c4_b_j];
      }

      c4_p = 0;
      c4_q = c4_bLen;
      c4_iout = c4_blockOffset;
      do {
        c4_exitg1 = 0;
        c4_iout++;
        if (c4_xwork[c4_p] >= c4_xwork[c4_q]) {
          c4_b_idx->data[c4_iout] = c4_b_iwork[c4_p];
          c4_c_x->data[c4_iout] = c4_xwork[c4_p];
          if (c4_p + 1 < c4_bLen) {
            c4_p++;
          } else {
            c4_exitg1 = 1;
          }
        } else {
          c4_b_idx->data[c4_iout] = c4_b_iwork[c4_q];
          c4_c_x->data[c4_iout] = c4_xwork[c4_q];
          if (c4_q + 1 < c4_bLen2) {
            c4_q++;
          } else {
            c4_offset1 = c4_iout - c4_p;
            c4_st.site = &c4_lf_emlrtRSI;
            c4_g_a = c4_p + 1;
            c4_f_b = c4_bLen;
            c4_h_a = c4_g_a;
            c4_g_b = c4_f_b;
            if (c4_h_a > c4_g_b) {
              c4_c_overflow = false;
            } else {
              c4_c_overflow = (c4_g_b > 2147483646);
            }

            if (c4_c_overflow) {
              c4_b_st.site = &c4_mb_emlrtRSI;
              c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
            }

            for (c4_c_j = c4_p + 1; c4_c_j <= c4_bLen; c4_c_j++) {
              c4_b_idx->data[c4_offset1 + c4_c_j] = c4_b_iwork[c4_c_j - 1];
              c4_c_x->data[c4_offset1 + c4_c_j] = c4_xwork[c4_c_j - 1];
            }

            c4_exitg1 = 1;
          }
        }
      } while (c4_exitg1 == 0);
    }
  }
}

static void c4_d_merge_block(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx,
  c4_emxArray_real_T *c4_c_x, int32_T c4_offset, int32_T c4_n, int32_T
  c4_preSortLevel, c4_emxArray_int32_T *c4_b_iwork, c4_emxArray_real_T *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_bLen;
  int32_T c4_bLen2;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_k;
  int32_T c4_nBlocks;
  int32_T c4_nPairs;
  int32_T c4_nTail;
  int32_T c4_tailOffset;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_nBlocks = c4_n >> c4_preSortLevel;
  c4_bLen = 1 << c4_preSortLevel;
  while (c4_nBlocks > 1) {
    if ((c4_nBlocks & 1) != 0) {
      c4_nBlocks--;
      c4_tailOffset = c4_bLen * c4_nBlocks;
      c4_nTail = c4_n - c4_tailOffset;
      if (c4_nTail > c4_bLen) {
        c4_st.site = &c4_mf_emlrtRSI;
        c4_d_merge(chartInstance, &c4_st, c4_b_idx, c4_c_x, c4_offset +
                   c4_tailOffset, c4_bLen, c4_nTail - c4_bLen, c4_b_iwork,
                   c4_xwork);
      }
    }

    c4_bLen2 = c4_bLen << 1;
    c4_nPairs = c4_nBlocks >> 1;
    c4_st.site = &c4_nf_emlrtRSI;
    c4_b = c4_nPairs;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_k = 1; c4_k - 1 < c4_nPairs; c4_k++) {
      c4_b_k = c4_k - 1;
      c4_st.site = &c4_of_emlrtRSI;
      c4_d_merge(chartInstance, &c4_st, c4_b_idx, c4_c_x, c4_offset + c4_b_k *
                 c4_bLen2, c4_bLen, c4_bLen, c4_b_iwork, c4_xwork);
    }

    c4_bLen = c4_bLen2;
    c4_nBlocks = c4_nPairs;
  }

  if (c4_n > c4_bLen) {
    c4_st.site = &c4_pf_emlrtRSI;
    c4_d_merge(chartInstance, &c4_st, c4_b_idx, c4_c_x, c4_offset, c4_bLen, c4_n
               - c4_bLen, c4_b_iwork, c4_xwork);
  }
}

static void c4_d_merge(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_real_T
  *c4_c_x, int32_T c4_offset, int32_T c4_np, int32_T c4_nq, c4_emxArray_int32_T *
  c4_b_iwork, c4_emxArray_real_T *c4_xwork)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_j;
  int32_T c4_c_b;
  int32_T c4_c_j;
  int32_T c4_d_b;
  int32_T c4_exitg1;
  int32_T c4_g_a;
  int32_T c4_h_a;
  int32_T c4_iout;
  int32_T c4_j;
  int32_T c4_n;
  int32_T c4_offset1;
  int32_T c4_p;
  int32_T c4_q;
  int32_T c4_qend;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  if (c4_nq != 0) {
    c4_n = c4_np + c4_nq;
    c4_st.site = &c4_rf_emlrtRSI;
    c4_b = c4_n;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_j = 1; c4_j - 1 < c4_n; c4_j++) {
      c4_b_j = c4_j - 1;
      c4_b_iwork->data[c4_b_j] = c4_b_idx->data[c4_offset + c4_b_j];
      c4_xwork->data[c4_b_j] = c4_c_x->data[c4_offset + c4_b_j];
    }

    c4_p = 0;
    c4_q = c4_np;
    c4_qend = c4_np + c4_nq;
    c4_iout = c4_offset - 1;
    do {
      c4_exitg1 = 0;
      c4_iout++;
      if (c4_xwork->data[c4_p] >= c4_xwork->data[c4_q]) {
        c4_b_idx->data[c4_iout] = c4_b_iwork->data[c4_p];
        c4_c_x->data[c4_iout] = c4_xwork->data[c4_p];
        if (c4_p + 1 < c4_np) {
          c4_p++;
        } else {
          c4_exitg1 = 1;
        }
      } else {
        c4_b_idx->data[c4_iout] = c4_b_iwork->data[c4_q];
        c4_c_x->data[c4_iout] = c4_xwork->data[c4_q];
        if (c4_q + 1 < c4_qend) {
          c4_q++;
        } else {
          c4_offset1 = c4_iout - c4_p;
          c4_st.site = &c4_qf_emlrtRSI;
          c4_g_a = c4_p + 1;
          c4_c_b = c4_np;
          c4_h_a = c4_g_a;
          c4_d_b = c4_c_b;
          if (c4_h_a > c4_d_b) {
            c4_b_overflow = false;
          } else {
            c4_b_overflow = (c4_d_b > 2147483646);
          }

          if (c4_b_overflow) {
            c4_b_st.site = &c4_mb_emlrtRSI;
            c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
          }

          for (c4_c_j = c4_p + 1; c4_c_j <= c4_np; c4_c_j++) {
            c4_b_idx->data[c4_offset1 + c4_c_j] = c4_b_iwork->data[c4_c_j - 1];
            c4_c_x->data[c4_offset1 + c4_c_j] = c4_xwork->data[c4_c_j - 1];
          }

          c4_exitg1 = 1;
        }
      }
    } while (c4_exitg1 == 0);
  }
}

static void c4_b_sortrows(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_y, real_T c4_d_varargin_1[2])
{
  static char_T c4_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 's', 's',
    'o', 'r', 't', 'e', 'd', 'r', 'o', 'w', 's', ':', 'C', 'o', 'l', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h', 'X' };

  c4_emxArray_int32_T *c4_b_idx;
  c4_emxArray_int32_T *c4_h_x;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  real_T c4_b_k;
  real_T c4_c_x;
  real_T c4_ck;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  int32_T c4_col[2];
  int32_T c4_b_loop_ub;
  int32_T c4_exitg1;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  int32_T c4_loop_ub;
  int32_T c4_n;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_gk_emlrtRSI;
  c4_k = 0;
  do {
    c4_exitg1 = 0;
    if (c4_k < 2) {
      c4_b_k = (real_T)c4_k + 1.0;
      c4_c_x = c4_d_varargin_1[(int32_T)c4_b_k - 1];
      c4_d_x = c4_c_x;
      c4_e_x = c4_d_x;
      c4_ck = muDoubleScalarAbs(c4_e_x);
      c4_f_x = c4_ck;
      c4_g_x = c4_f_x;
      c4_g_x = muDoubleScalarFloor(c4_g_x);
      if ((c4_g_x != c4_ck) || (c4_ck < 1.0) || (c4_ck > 2.0)) {
        c4_p = false;
        c4_exitg1 = 1;
      } else {
        c4_k++;
      }
    } else {
      c4_p = true;
      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  if (!c4_p) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    sf_mex_call(&c4_st, &c4_fb_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_st, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_col[c4_i] = (int32_T)c4_d_varargin_1[c4_i];
  }

  c4_emxInit_int32_T1(chartInstance, &c4_st, &c4_h_x, 2, &c4_mi_emlrtRTEI);
  c4_st.site = &c4_hk_emlrtRSI;
  c4_i1 = c4_h_x->size[0] * c4_h_x->size[1];
  c4_h_x->size[0] = c4_y->size[0];
  c4_h_x->size[1] = 2;
  c4_b_st.site = &c4_hk_emlrtRSI;
  c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_b_st, c4_h_x, c4_i1,
    &c4_mi_emlrtRTEI);
  c4_loop_ub = c4_y->size[0] * c4_y->size[1] - 1;
  for (c4_i2 = 0; c4_i2 <= c4_loop_ub; c4_i2++) {
    c4_h_x->data[c4_i2] = c4_y->data[c4_i2];
  }

  c4_emxInit_int32_T(chartInstance, &c4_st, &c4_b_idx, 1, &c4_ni_emlrtRTEI);
  c4_n = c4_h_x->size[0];
  c4_i3 = c4_b_idx->size[0];
  c4_b_idx->size[0] = c4_h_x->size[0];
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_b_idx, c4_i3,
    &c4_ni_emlrtRTEI);
  c4_b_loop_ub = c4_h_x->size[0] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_b_loop_ub; c4_i4++) {
    c4_b_idx->data[c4_i4] = 0;
  }

  c4_b_st.site = &c4_jk_emlrtRSI;
  c4_d_mergesort(chartInstance, &c4_b_st, c4_b_idx, c4_h_x, c4_col, c4_n);
  c4_st.site = &c4_ik_emlrtRSI;
  c4_b_apply_row_permutation(chartInstance, &c4_st, c4_y, c4_b_idx);
  c4_emxFree_int32_T(chartInstance, &c4_h_x);
  c4_emxFree_int32_T(chartInstance, &c4_b_idx);
}

static void c4_d_mergesort(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_b_idx, c4_emxArray_int32_T
  *c4_c_x, int32_T c4_dir[2], int32_T c4_n)
{
  c4_emxArray_int32_T *c4_b_iwork;
  c4_emxArray_int32_T *c4_d_x;
  c4_emxArray_int32_T *c4_e_x;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b_dir[2];
  int32_T c4_c_dir[2];
  int32_T c4_iv[1];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_i;
  int32_T c4_b_i2;
  int32_T c4_b_k;
  int32_T c4_b_loop_ub;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_g_a;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_kEnd;
  int32_T c4_len;
  int32_T c4_loop_ub;
  int32_T c4_np1;
  int32_T c4_p;
  int32_T c4_pEnd;
  int32_T c4_q;
  int32_T c4_qEnd;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_emxInit_int32_T(chartInstance, c4_sp, &c4_b_iwork, 1, &c4_qi_emlrtRTEI);
  c4_i = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_b_idx->size[0];
  c4_st.site = &c4_el_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_b_iwork, c4_i,
    &c4_oi_emlrtRTEI);
  c4_loop_ub = c4_b_idx->size[0] - 1;
  for (c4_i1 = 0; c4_i1 <= c4_loop_ub; c4_i1++) {
    c4_b_iwork->data[c4_i1] = c4_b_idx->data[c4_i1];
  }

  c4_len = c4_b_iwork->size[0];
  c4_i2 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_len;
  c4_emxEnsureCapacity_int32_T(chartInstance, c4_sp, c4_b_iwork, c4_i2,
    &c4_pi_emlrtRTEI);
  c4_iv[0] = c4_b_iwork->size[0];
  c4_i3 = c4_b_iwork->size[0];
  c4_b_iwork->size[0] = c4_iv[0];
  c4_st.site = &c4_el_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_b_iwork, c4_i3,
    &c4_qi_emlrtRTEI);
  c4_np1 = c4_n + 1;
  c4_i4 = c4_n;
  c4_k = 1;
  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_d_x, 2, &c4_ri_emlrtRTEI);
  while (c4_k <= c4_i4 - 1) {
    c4_i5 = c4_d_x->size[0] * c4_d_x->size[1];
    c4_d_x->size[0] = c4_c_x->size[0];
    c4_d_x->size[1] = 2;
    c4_st.site = &c4_tl_emlrtRSI;
    c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_d_x, c4_i5,
      &c4_ri_emlrtRTEI);
    c4_b_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
    for (c4_i6 = 0; c4_i6 <= c4_b_loop_ub; c4_i6++) {
      c4_d_x->data[c4_i6] = c4_c_x->data[c4_i6];
    }

    for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
      c4_b_dir[c4_i7] = c4_dir[c4_i7];
    }

    if (c4_sortLE(chartInstance, c4_d_x, c4_b_dir, c4_k, c4_k + 1)) {
      c4_b_idx->data[c4_k - 1] = c4_k;
      c4_b_idx->data[c4_k] = c4_k + 1;
    } else {
      c4_b_idx->data[c4_k - 1] = c4_k + 1;
      c4_b_idx->data[c4_k] = c4_k;
    }

    c4_k += 2;
  }

  c4_emxFree_int32_T(chartInstance, &c4_d_x);
  if ((c4_n & 1) != 0) {
    c4_b_idx->data[c4_n - 1] = c4_n;
  }

  c4_b_i = 2;
  c4_emxInit_int32_T1(chartInstance, c4_sp, &c4_e_x, 2, &c4_ri_emlrtRTEI);
  while (c4_b_i < c4_n) {
    c4_g_a = c4_b_i;
    c4_b_i2 = c4_g_a << 1;
    c4_j = 1;
    for (c4_pEnd = 1 + c4_b_i; c4_pEnd < c4_np1; c4_pEnd = c4_qEnd + c4_b_i) {
      c4_p = c4_j - 1;
      c4_q = c4_pEnd - 1;
      c4_qEnd = c4_j + c4_b_i2;
      if (c4_qEnd > c4_np1) {
        c4_qEnd = c4_np1;
      }

      c4_b_k = 0;
      c4_kEnd = c4_qEnd - c4_j;
      while (c4_b_k + 1 <= c4_kEnd) {
        c4_i8 = c4_e_x->size[0] * c4_e_x->size[1];
        c4_e_x->size[0] = c4_c_x->size[0];
        c4_e_x->size[1] = 2;
        c4_st.site = &c4_tl_emlrtRSI;
        c4_emxEnsureCapacity_int32_T1(chartInstance, &c4_st, c4_e_x, c4_i8,
          &c4_ri_emlrtRTEI);
        c4_c_loop_ub = c4_c_x->size[0] * c4_c_x->size[1] - 1;
        for (c4_i9 = 0; c4_i9 <= c4_c_loop_ub; c4_i9++) {
          c4_e_x->data[c4_i9] = c4_c_x->data[c4_i9];
        }

        for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
          c4_c_dir[c4_i10] = c4_dir[c4_i10];
        }

        if (c4_sortLE(chartInstance, c4_e_x, c4_c_dir, c4_b_idx->data[c4_p],
                      c4_b_idx->data[c4_q])) {
          c4_b_iwork->data[c4_b_k] = c4_b_idx->data[c4_p];
          c4_p++;
          if (c4_p + 1 == c4_pEnd) {
            while (c4_q + 1 < c4_qEnd) {
              c4_b_k++;
              c4_b_iwork->data[c4_b_k] = c4_b_idx->data[c4_q];
              c4_q++;
            }
          }
        } else {
          c4_b_iwork->data[c4_b_k] = c4_b_idx->data[c4_q];
          c4_q++;
          if (c4_q + 1 == c4_qEnd) {
            while (c4_p + 1 < c4_pEnd) {
              c4_b_k++;
              c4_b_iwork->data[c4_b_k] = c4_b_idx->data[c4_p];
              c4_p++;
            }
          }
        }

        c4_b_k++;
      }

      c4_p = c4_j - 2;
      c4_st.site = &c4_vd_emlrtRSI;
      c4_b = c4_kEnd;
      c4_b_b = c4_b;
      if (1 > c4_b_b) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_b_b > 2147483646);
      }

      if (c4_overflow) {
        c4_b_st.site = &c4_mb_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
      }

      for (c4_c_k = 1; c4_c_k - 1 < c4_kEnd; c4_c_k++) {
        c4_b_k = c4_c_k;
        c4_b_idx->data[c4_p + c4_b_k] = c4_b_iwork->data[c4_b_k - 1];
      }

      c4_j = c4_qEnd;
    }

    c4_b_i = c4_b_i2;
  }

  c4_emxFree_int32_T(chartInstance, &c4_e_x);
  c4_emxFree_int32_T(chartInstance, &c4_b_iwork);
}

static void c4_b_apply_row_permutation(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_y,
  c4_emxArray_int32_T *c4_b_idx)
{
  c4_emxArray_int32_T *c4_ycol;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_iv[2];
  int32_T c4_b;
  int32_T c4_b_b;
  int32_T c4_b_i;
  int32_T c4_b_j;
  int32_T c4_c_b;
  int32_T c4_c_i;
  int32_T c4_d_b;
  int32_T c4_d_i;
  int32_T c4_i;
  int32_T c4_j;
  int32_T c4_m;
  boolean_T c4_b_overflow;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_emxInit_int32_T(chartInstance, c4_sp, &c4_ycol, 1, &c4_ti_emlrtRTEI);
  c4_m = c4_y->size[0];
  c4_iv[0] = c4_m;
  c4_i = c4_ycol->size[0];
  c4_ycol->size[0] = c4_iv[0];
  c4_st.site = &c4_dl_emlrtRSI;
  c4_emxEnsureCapacity_int32_T(chartInstance, &c4_st, c4_ycol, c4_i,
    &c4_si_emlrtRTEI);
  for (c4_j = 0; c4_j < 2; c4_j++) {
    c4_b_j = c4_j;
    c4_st.site = &c4_kk_emlrtRSI;
    c4_b = c4_m;
    c4_b_b = c4_b;
    if (1 > c4_b_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_b_b > 2147483646);
    }

    if (c4_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_b_i = 1; c4_b_i - 1 < c4_m; c4_b_i++) {
      c4_c_i = c4_b_i - 1;
      c4_ycol->data[c4_c_i] = c4_y->data[(c4_b_idx->data[c4_c_i] + c4_y->size[0]
        * c4_b_j) - 1];
    }

    c4_st.site = &c4_lk_emlrtRSI;
    c4_c_b = c4_m;
    c4_d_b = c4_c_b;
    if (1 > c4_d_b) {
      c4_b_overflow = false;
    } else {
      c4_b_overflow = (c4_d_b > 2147483646);
    }

    if (c4_b_overflow) {
      c4_b_st.site = &c4_mb_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
    }

    for (c4_d_i = 1; c4_d_i - 1 < c4_m; c4_d_i++) {
      c4_c_i = c4_d_i - 1;
      c4_y->data[c4_c_i + c4_y->size[0] * c4_b_j] = c4_ycol->data[c4_c_i];
    }
  }

  c4_emxFree_int32_T(chartInstance, &c4_ycol);
}

static void c4_emxInit_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_real_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_real_T *)emlrtMallocMex(sizeof(c4_emxArray_real_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (real_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_skoeQIuVNKJRHNtBIlOCZhD
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_skoeQIuVNKJRHNtBIlOCZh **c4_pEmxArray, int32_T
   c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *)emlrtMallocMex(sizeof
    (c4_emxArray_skoeQIuVNKJRHNtBIlOCZh));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (c4_skoeQIuVNKJRHNtBIlOCZhD *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFree_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_real_T *)NULL) {
    if (((*c4_pEmxArray)->data != (real_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_real_T *)NULL;
  }
}

static void c4_emxFree_skoeQIuVNKJRHNtBIlOCZhD
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_emxArray_skoeQIuVNKJRHNtBIlOCZh **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *)NULL) {
    if (((*c4_pEmxArray)->data != (c4_skoeQIuVNKJRHNtBIlOCZhD *)NULL) &&
        (*c4_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *)NULL;
  }
}

static void c4_emxEnsureCapacity_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(real32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(real32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (real32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInit_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_real32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_real32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (real32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFree_real32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real32_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_real32_T *)NULL) {
    if (((*c4_pEmxArray)->data != (real32_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_real32_T *)NULL;
  }
}

static void c4_emxEnsureCapacity_creal_T(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_creal_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(creal_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(creal_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (creal_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(real_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(real_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (real_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_boolean_T
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_boolean_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(boolean_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (boolean_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_int32_T(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(int32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(int32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (int32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_real_T1(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(real_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(real_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (real_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInit_real_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_real_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_real_T *)emlrtMallocMex(sizeof(c4_emxArray_real_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (real_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_boolean_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_boolean_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_boolean_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c4_emxArray_boolean_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (boolean_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_int32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_int32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_int32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (int32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_creal_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_creal_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_creal_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c4_emxArray_creal_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (creal_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFree_boolean_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_boolean_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_boolean_T *)NULL) {
    if (((*c4_pEmxArray)->data != (boolean_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_boolean_T *)NULL;
  }
}

static void c4_emxFree_int32_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_int32_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_int32_T *)NULL) {
    if (((*c4_pEmxArray)->data != (int32_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_int32_T *)NULL;
  }
}

static void c4_emxFree_creal_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_creal_T **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_creal_T *)NULL) {
    if (((*c4_pEmxArray)->data != (creal_T *)NULL) && (*c4_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_creal_T *)NULL;
  }
}

static void c4_emxEnsureCapacity_real32_T1
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_real32_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(real32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(real32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (real32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_creal_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_creal_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(creal_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(creal_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (creal_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInit_real32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_real32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_real32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (real32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_creal_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_creal_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_creal_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c4_emxArray_creal_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (creal_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxEnsureCapacity_int32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T *c4_emxArray,
  int32_T c4_oldNumel, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(int32_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(int32_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (int32_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInit_sBO2RC5RVZVTbundPSRqHnH
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_sBO2RC5RVZVTbundPSRqHn **c4_pEmxArray, int32_T
   c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_sBO2RC5RVZVTbundPSRqHn *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_sBO2RC5RVZVTbundPSRqHn *)emlrtMallocMex(sizeof
    (c4_emxArray_sBO2RC5RVZVTbundPSRqHn));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (c4_sBO2RC5RVZVTbundPSRqHnH *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxInit_int32_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_int32_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_int32_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c4_emxArray_int32_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (int32_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFree_sBO2RC5RVZVTbundPSRqHnH
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_emxArray_sBO2RC5RVZVTbundPSRqHn **c4_pEmxArray)
{
  (void)chartInstance;
  if (*c4_pEmxArray != (c4_emxArray_sBO2RC5RVZVTbundPSRqHn *)NULL) {
    if (((*c4_pEmxArray)->data != (c4_sBO2RC5RVZVTbundPSRqHnH *)NULL) &&
        (*c4_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c4_pEmxArray)->data);
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_sBO2RC5RVZVTbundPSRqHn *)NULL;
  }
}

static void c4_emxInitStruct_s_VSLwMee4Kv1oTF0
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_VSLwMee4Kv1oTF0BcoITHB *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation)
{
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_pStruct->RegionIndices, 1,
                     c4_srcLocation);
  c4_emxInit_int32_T(chartInstance, c4_sp, &c4_pStruct->RegionLengths, 1,
                     c4_srcLocation);
}

static void c4_emxInit_s_nrlUwWofUDGxo1t78e6dw
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_s_nrlUwWofUDGxo1t78e6d **c4_pEmxArray, int32_T
   c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_s_nrlUwWofUDGxo1t78e6d *)emlrtMallocMex(sizeof
    (c4_emxArray_s_nrlUwWofUDGxo1t78e6d));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (c4_s_nrlUwWofUDGxo1t78e6dwC *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxFreeStruct_s_VSLwMee4Kv1oTF0
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_VSLwMee4Kv1oTF0BcoITHB *c4_pStruct)
{
  c4_emxFree_real_T(chartInstance, &c4_pStruct->RegionIndices);
  c4_emxFree_int32_T(chartInstance, &c4_pStruct->RegionLengths);
}

static void c4_emxFree_s_nrlUwWofUDGxo1t78e6dw
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_emxArray_s_nrlUwWofUDGxo1t78e6d **c4_pEmxArray)
{
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_numEl;
  if (*c4_pEmxArray != (c4_emxArray_s_nrlUwWofUDGxo1t78e6d *)NULL) {
    if ((*c4_pEmxArray)->data != (c4_s_nrlUwWofUDGxo1t78e6dwC *)NULL) {
      c4_numEl = 1;
      for (c4_i = 0; c4_i < (*c4_pEmxArray)->numDimensions; c4_i++) {
        c4_numEl *= (*c4_pEmxArray)->size[c4_i];
      }

      for (c4_b_i = 0; c4_b_i < c4_numEl; c4_b_i++) {
        c4_emxFreeStruct_s_nrlUwWofUDGxo1t(chartInstance, &(*c4_pEmxArray)->
          data[c4_b_i]);
      }

      if ((*c4_pEmxArray)->canFreeData) {
        emlrtFreeMex((*c4_pEmxArray)->data);
      }
    }

    emlrtFreeMex((*c4_pEmxArray)->size);
    emlrtFreeMex(*c4_pEmxArray);
    *c4_pEmxArray = (c4_emxArray_s_nrlUwWofUDGxo1t78e6d *)NULL;
  }
}

static void c4_emxFreeStruct_s_nrlUwWofUDGxo1t
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_s_nrlUwWofUDGxo1t78e6dwC *c4_pStruct)
{
  c4_emxFree_real_T(chartInstance, &c4_pStruct->PixelIdxList);
  c4_emxFree_real_T(chartInstance, &c4_pStruct->PixelList);
  c4_emxFree_real_T(chartInstance, &c4_pStruct->PixelValues);
}

static void c4_emxEnsureCapacity_boolean_T1
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_boolean_T *c4_emxArray, int32_T c4_oldNumel, const
   emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof(boolean_T));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (boolean_T *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxEnsureCapacity_sBO2RC5RVZVTb
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_sBO2RC5RVZVTbundPSRqHn *c4_emxArray, int32_T c4_oldNumel,
   const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof
      (c4_sBO2RC5RVZVTbundPSRqHnH));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(c4_sBO2RC5RVZVTbundPSRqHnH) *
             (uint32_T)c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (c4_sBO2RC5RVZVTbundPSRqHnH *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInit_boolean_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_boolean_T **c4_pEmxArray,
  int32_T c4_numDimensions, const emlrtRTEInfo *c4_srcLocation)
{
  c4_emxArray_boolean_T *c4_emxArray;
  int32_T c4_i;
  (void)chartInstance;
  *c4_pEmxArray = (c4_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c4_emxArray_boolean_T));
  if ((void *)*c4_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray = *c4_pEmxArray;
  c4_emxArray->data = (boolean_T *)NULL;
  c4_emxArray->numDimensions = c4_numDimensions;
  c4_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c4_numDimensions);
  if ((void *)c4_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
  }

  c4_emxArray->allocatedSize = 0;
  c4_emxArray->canFreeData = true;
  for (c4_i = 0; c4_i < c4_numDimensions; c4_i++) {
    c4_emxArray->size[c4_i] = 0;
  }
}

static void c4_emxTrim_s_nrlUwWofUDGxo1t78e6dw
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_emxArray, int32_T c4_fromIndex,
   int32_T c4_toIndex)
{
  int32_T c4_i;
  for (c4_i = c4_fromIndex; c4_i < c4_toIndex; c4_i++) {
    c4_emxFreeStruct_s_nrlUwWofUDGxo1t(chartInstance, &c4_emxArray->data[c4_i]);
  }
}

static void c4_emxInitStruct_s_nrlUwWofUDGxo1t
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_nrlUwWofUDGxo1t78e6dwC *c4_pStruct, const emlrtRTEInfo
   *c4_srcLocation)
{
  c4_pStruct->Image.size[0] = 0;
  c4_pStruct->Image.size[1] = 0;
  c4_pStruct->FilledImage.size[0] = 0;
  c4_pStruct->FilledImage.size[1] = 0;
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_pStruct->PixelIdxList, 1,
                     c4_srcLocation);
  c4_emxInit_real_T(chartInstance, c4_sp, &c4_pStruct->PixelList, 2,
                    c4_srcLocation);
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_pStruct->PixelValues, 1,
                     c4_srcLocation);
  c4_pStruct->SubarrayIdx.size[0] = 0;
  c4_pStruct->SubarrayIdx.size[1] = 0;
}

static void c4_emxExpand_s_nrlUwWofUDGxo1t78e6
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_emxArray, int32_T c4_fromIndex,
   int32_T c4_toIndex, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  for (c4_i = c4_fromIndex; c4_i < c4_toIndex; c4_i++) {
    c4_emxInitStruct_s_nrlUwWofUDGxo1t(chartInstance, c4_sp, &c4_emxArray->
      data[c4_i], c4_srcLocation);
  }
}

static void c4_emxEnsureCapacity_s_nrlUwWofUDG
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_s_nrlUwWofUDGxo1t78e6d *c4_emxArray, int32_T c4_oldNumel,
   const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof
      (c4_s_nrlUwWofUDGxo1t78e6dwC));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(c4_s_nrlUwWofUDGxo1t78e6dwC) *
             (uint32_T)c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (c4_s_nrlUwWofUDGxo1t78e6dwC *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }

  if (c4_oldNumel > c4_newNumel) {
    c4_emxTrim_s_nrlUwWofUDGxo1t78e6dw(chartInstance, c4_emxArray, c4_newNumel,
      c4_oldNumel);
  } else {
    if (c4_oldNumel < c4_newNumel) {
      c4_emxExpand_s_nrlUwWofUDGxo1t78e6(chartInstance, c4_sp, c4_emxArray,
        c4_oldNumel, c4_newNumel, c4_srcLocation);
    }
  }
}

static void c4_emxCopyStruct_s_nrlUwWofUDGxo1t
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_s_nrlUwWofUDGxo1t78e6dwC *c4_dst, const
   c4_s_nrlUwWofUDGxo1t78e6dwC *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  c4_dst->Area = c4_src->Area;
  c4_emxCopyMatrix_real_T(chartInstance, c4_dst->Centroid, c4_src->Centroid);
  c4_emxCopyMatrix_real_T1(chartInstance, c4_dst->BoundingBox,
    c4_src->BoundingBox);
  c4_dst->MajorAxisLength = c4_src->MajorAxisLength;
  c4_dst->MinorAxisLength = c4_src->MinorAxisLength;
  c4_dst->Eccentricity = c4_src->Eccentricity;
  c4_dst->Orientation = c4_src->Orientation;
  c4_emxCopy_boolean_T_0x0(chartInstance, &c4_dst->Image, &c4_src->Image);
  c4_emxCopy_boolean_T_0x0(chartInstance, &c4_dst->FilledImage,
    &c4_src->FilledImage);
  c4_dst->FilledArea = c4_src->FilledArea;
  c4_dst->EulerNumber = c4_src->EulerNumber;
  c4_emxCopyMatrix_real_T2(chartInstance, c4_dst->Extrema, c4_src->Extrema);
  c4_dst->EquivDiameter = c4_src->EquivDiameter;
  c4_dst->Extent = c4_src->Extent;
  c4_emxCopy_real_T(chartInstance, c4_sp, &c4_dst->PixelIdxList,
                    &c4_src->PixelIdxList, c4_srcLocation);
  c4_emxCopy_real_T1(chartInstance, c4_sp, &c4_dst->PixelList,
                     &c4_src->PixelList, c4_srcLocation);
  c4_dst->Perimeter = c4_src->Perimeter;
  c4_dst->Circularity = c4_src->Circularity;
  c4_emxCopy_real_T(chartInstance, c4_sp, &c4_dst->PixelValues,
                    &c4_src->PixelValues, c4_srcLocation);
  c4_emxCopyMatrix_real_T(chartInstance, c4_dst->WeightedCentroid,
    c4_src->WeightedCentroid);
  c4_dst->MeanIntensity = c4_src->MeanIntensity;
  c4_dst->MinIntensity = c4_src->MinIntensity;
  c4_dst->MaxIntensity = c4_src->MaxIntensity;
  c4_emxCopy_real_T_1x0(chartInstance, &c4_dst->SubarrayIdx,
                        &c4_src->SubarrayIdx);
  c4_emxCopyMatrix_real_T(chartInstance, c4_dst->SubarrayIdxLengths,
    c4_src->SubarrayIdxLengths);
}

static void c4_emxCopyMatrix_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[2], const real_T c4_src[2])
{
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_dst[c4_i] = c4_src[c4_i];
  }
}

static void c4_emxCopyMatrix_real_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[4], const real_T c4_src[4])
{
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 4; c4_i++) {
    c4_dst[c4_i] = c4_src[c4_i];
  }
}

static void c4_emxCopy_boolean_T_0x0(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_boolean_T_0x0 *c4_dst, const
  c4_emxArray_boolean_T_0x0 *c4_src)
{
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_dst->size[c4_i] = c4_src->size[c4_i];
  }
}

static void c4_emxCopyMatrix_real_T2(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_dst[16], const real_T c4_src[16])
{
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 16; c4_i++) {
    c4_dst[c4_i] = c4_src[c4_i];
  }
}

static void c4_emxCopy_real_T(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_dst,
  c4_emxArray_real_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_numElDst;
  int32_T c4_numElSrc;
  c4_numElDst = 1;
  c4_numElSrc = 1;
  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    c4_numElDst *= (*c4_dst)->size[c4_i];
    c4_numElSrc *= (*c4_src)->size[c4_i];
  }

  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    (*c4_dst)->size[c4_i] = (*c4_src)->size[c4_i];
  }

  c4_emxEnsureCapacity_real_T1(chartInstance, c4_sp, *c4_dst, c4_numElDst,
    c4_srcLocation);
  for (c4_i = 0; c4_i < c4_numElSrc; c4_i++) {
    (*c4_dst)->data[c4_i] = (*c4_src)->data[c4_i];
  }
}

static void c4_emxCopy_real_T1(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_emxArray_real_T **c4_dst,
  c4_emxArray_real_T * const *c4_src, const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_numElDst;
  int32_T c4_numElSrc;
  c4_numElDst = 1;
  c4_numElSrc = 1;
  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    c4_numElDst *= (*c4_dst)->size[c4_i];
    c4_numElSrc *= (*c4_src)->size[c4_i];
  }

  for (c4_i = 0; c4_i < (*c4_dst)->numDimensions; c4_i++) {
    (*c4_dst)->size[c4_i] = (*c4_src)->size[c4_i];
  }

  c4_emxEnsureCapacity_real_T(chartInstance, c4_sp, *c4_dst, c4_numElDst,
    c4_srcLocation);
  for (c4_i = 0; c4_i < c4_numElSrc; c4_i++) {
    (*c4_dst)->data[c4_i] = (*c4_src)->data[c4_i];
  }
}

static void c4_emxCopy_real_T_1x0(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_emxArray_real_T_1x0 *c4_dst, const c4_emxArray_real_T_1x0
  *c4_src)
{
  int32_T c4_i;
  (void)chartInstance;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_dst->size[c4_i] = c4_src->size[c4_i];
  }
}

static void c4_emxEnsureCapacity_skoeQIuVNKJRH
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_emxArray_skoeQIuVNKJRHNtBIlOCZh *c4_emxArray, int32_T c4_oldNumel,
   const emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  void *c4_newData;
  (void)chartInstance;
  if (c4_oldNumel < 0) {
    c4_oldNumel = 0;
  }

  c4_newNumel = 1;
  for (c4_i = 0; c4_i < c4_emxArray->numDimensions; c4_i++) {
    c4_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c4_newNumel, (uint32_T)
      c4_emxArray->size[c4_i], c4_srcLocation, c4_sp);
  }

  if (c4_newNumel > c4_emxArray->allocatedSize) {
    c4_newCapacity = c4_emxArray->allocatedSize;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = emlrtCallocMex((uint32_T)c4_newCapacity, sizeof
      (c4_skoeQIuVNKJRHNtBIlOCZhD));
    if (c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, c4_sp);
    }

    if (c4_emxArray->data != NULL) {
      memcpy(c4_newData, c4_emxArray->data, sizeof(c4_skoeQIuVNKJRHNtBIlOCZhD) *
             (uint32_T)c4_oldNumel);
      if (c4_emxArray->canFreeData) {
        emlrtFreeMex(c4_emxArray->data);
      }
    }

    c4_emxArray->data = (c4_skoeQIuVNKJRHNtBIlOCZhD *)c4_newData;
    c4_emxArray->allocatedSize = c4_newCapacity;
    c4_emxArray->canFreeData = true;
  }
}

static void c4_emxInitMatrix_cell_wrap_52(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_52 c4_pMatrix[2], const
  emlrtRTEInfo *c4_srcLocation)
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_emxInitStruct_cell_wrap_52(chartInstance, c4_sp, &c4_pMatrix[c4_i],
      c4_srcLocation);
  }
}

static void c4_emxInitStruct_cell_wrap_52(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_cell_wrap_52 *c4_pStruct, const
  emlrtRTEInfo *c4_srcLocation)
{
  c4_emxInit_real_T1(chartInstance, c4_sp, &c4_pStruct->f1, 1, c4_srcLocation);
}

static void c4_emxFreeMatrix_cell_wrap_52(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_cell_wrap_52 c4_pMatrix[2])
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 2; c4_i++) {
    c4_emxFreeStruct_cell_wrap_52(chartInstance, &c4_pMatrix[c4_i]);
  }
}

static void c4_emxFreeStruct_cell_wrap_52(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_cell_wrap_52 *c4_pStruct)
{
  c4_emxFree_real_T(chartInstance, &c4_pStruct->f1);
}

static int32_T c4_div_nzp_s32(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int32_T c4_numerator, int32_T c4_denominator, int32_T
  c4_EMLOvCount_src_loc, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc,
  int32_T c4_length_src_loc)
{
  int32_T c4_quotient;
  uint32_T c4_absDenominator;
  uint32_T c4_absNumerator;
  uint32_T c4_tempAbsQuotient;
  boolean_T c4_quotientNeedsNegation;
  (void)chartInstance;
  (void)c4_EMLOvCount_src_loc;
  (void)c4_ssid_src_loc;
  (void)c4_offset_src_loc;
  (void)c4_length_src_loc;
  if (c4_numerator < 0) {
    c4_absNumerator = ~(uint32_T)c4_numerator + 1U;
  } else {
    c4_absNumerator = (uint32_T)c4_numerator;
  }

  if (c4_denominator < 0) {
    c4_absDenominator = ~(uint32_T)c4_denominator + 1U;
  } else {
    c4_absDenominator = (uint32_T)c4_denominator;
  }

  c4_quotientNeedsNegation = ((c4_numerator < 0) != (c4_denominator < 0));
  c4_tempAbsQuotient = c4_absNumerator / c4_absDenominator;
  if (c4_quotientNeedsNegation) {
    c4_quotient = -(int32_T)c4_tempAbsQuotient;
  } else {
    c4_quotient = (int32_T)c4_tempAbsQuotient;
  }

  return c4_quotient;
}

static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_image = (real_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_output_angle = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_mode = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2854254732U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1394163017U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2532511658U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1265124517U);
}

mxArray *sf_c4_flightControlSystem_third_party_uses_info(void)
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

mxArray *sf_c4_flightControlSystem_jit_fallback_info(void)
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

mxArray *sf_c4_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiA+wcTAwAakOYCYiQECWKF8RiBmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Ms4gPQbIOlnwaKfBUm/AJCXm5+SygflD6z7Rc"
    "DudyDgfh4U90P4+aUlBaUl8Yl56TmpMH9Q7h8FB8r0Q+wPIOAfBTT/gPiZxfGJySWZZanxySbxa"
    "TmZ6Rklzvl5JUX5OcGVxSWpuTD/AQAlSCX5"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sWVGuJotpXiB7O5F2PfkVID";
}

static void sf_opaque_initialize_c4_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_flightControlSystem(void *chartInstanceVar)
{
  enable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_flightControlSystem(void *chartInstanceVar)
{
  disable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c4_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [19] = {
    "eNrtV82O21QU9qShomoZjUSlbip1drCsEAgWCKb5K0EzTIQzU3bDneuT+Cr3x9wfZ7Jlw2vwAuz",
    "gHXgENrwDG/aca3syqWM7TUNLQVjyeK79ne+e/3MT7A1PArz28f723SC4jc+38W4F+fVWsd5buf",
    "P37eC9Yv0zCkknRkQTYYLGSxIBX4NR3Fmm5FBOVCWMyQlokBSxidK2js0w4TiTs4GT1POZZzGjc",
    "Rgrx6MOypLoVPIFsiXOjpCnxzRQOwCIbKyVm8YDTqZLjbWdd2OgM+NEkwkGbOgSr5Y5cdyyhEP/",
    "CuhQGktQY3OjW2iJha69qjXTW2rCa6ASCWdEVlobExNCgg62cJZE+PfUWTSqDKMx0bYDMUnBHLN",
    "ZxqkklDmZwQ+XTBKrNCO8L3jXC67rNuKoz4mKgDc4BHXraCCzRDFp6+MfDtDSviSXHHpw6ab1bC",
    "F853zwzxnMQdf6bdJVKWgyhVNZu2nmkP5VFq1llqzDLBNwTvQTivEzENVmL2aOCQnGCcYoUQeDz",
    "MihGWuWontr2ZwY+szcVDJO5ME2m2AZWz+Fpigs2QZUdgnnphY2VskxpMAz1h6xpBmWs1bjjGHR",
    "WKGDfXrXV4OTDANfwLpKRqwyXGkJkPWdr7CxPI+kzlglupi8vePj9c/rsKG0oCeEQlUX0IQZQJ9",
    "l7q1ni5jxsUcgamUz9arAeYZsQgVm4mRvrvQMfdLQRG5M8BGtBQozxVhiJZwZLJommI/lJhwlNI",
    "bINxjG4QTLBrEVPjG+tT3BukuZXfTAUM2Siqg6rDpsQ32fUIsEzuRMqrkcaCXCosfnUcDOgD1cY",
    "AzGWY1JilTMWGwX7Gb7CACTkmjJ5LSDbU4vBqhkZcT83Hsc3My9ey8w967lys/3V3j2KniClWd5",
    "3zut5n1b+N9eIXe0IvdOaZ92Sc7jDvD+cZ5+au5+f/ex+OX3Hx789Ocu+1/d2u6csF+sH1435GW",
    "BpWt57bFfrOjVruB/sMJ/UKzNs/On7ktlk29Y5+PTjwYfjCaz82Ev4/u11azvrZK+1+8P/WTAbM",
    "zyWNNhVBxg/Jq4fKx7/k9W9L29wR93ivf59cfnu8k/PCrHscpf7ef81Q4EdorVvP3n9L9/VM7nK",
    "v3vleLt1yobNxdETjmU6/Dl9Tk82k0+33+0wZ7Dkj2H2XnmgvguCRf0w4sJZ9PYDzirFQ8X2N7E",
    "/t/QN7aVC16z3L9Fz//98urte5E5/LJyrR3n/uuS29W+bc8jbxq+aa4FJfzBG2zHrufEV43/Ldj",
    "uPPeoWH+2/GnXjRmPKk75xWc8i0+qvv5H8nQb/F9pmMk1",
    ""
  };

  static char newstr [1321] = "";
  newstr[0] = '\0';
  for (i = 0; i < 19; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c4_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1014396832U));
  ssSetChecksum1(S,(193071987U));
  ssSetChecksum2(S,(3719654704U));
  ssSetChecksum3(S,(4121761671U));
}

static void mdlRTW_c4_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_flightControlSystem(SimStruct *S)
{
  SFc4_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc4_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc4_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c4_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_flightControlSystem;
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
    chartInstance->c4_JITStateAnimation,
    chartInstance->c4_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_flightControlSystem(chartInstance);
}

void c4_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
