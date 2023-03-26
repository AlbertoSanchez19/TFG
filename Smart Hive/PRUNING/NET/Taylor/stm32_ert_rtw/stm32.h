/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stm32.h
 *
 * Code generated for Simulink model 'stm32'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Mar 17 15:51:17 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stm32_h_
#define RTW_HEADER_stm32_h_
#ifndef stm32_COMMON_INCLUDES_
#define stm32_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* stm32_COMMON_INCLUDES_ */

#include "stm32_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  cell_wrap_23_stm32_T outT_f2;
  real32_T inputsT[150528];
  cell_wrap_13_stm32_T inMiniBatchGroup;
  cell_wrap_26_stm32_T outT_f5;
  uint8_T APartialResize[160608];
  real32_T fv[37632];
  uint8_T B[150528];
  cell_wrap_27_stm32_T outT_f6;
  real32_T fv1[29792];
  real_T b_weights_data[1792];
  real_T absx2[1792];
  real_T absx3[1792];
  real_T absx[1568];
  real_T absx3_m[1568];
  cell_wrap_25_stm32_T outT_f4;
  cell_wrap_29_stm32_T outT_f14;
  real32_T fv2[3136];
  int32_T indices_data[1792];
  int32_T b_indices[1792];
  int32_T b_indices_c[1568];
  cell_wrap_28_stm32_T outT_f7;
  cell_wrap_28_stm32_T outT_f8;
  cell_wrap_28_stm32_T outT_f9;
  cell_wrap_28_stm32_T outT_f10;
  cell_wrap_28_stm32_T outT_f11;
  cell_wrap_28_stm32_T outT_f13;
  cell_wrap_28_stm32_T outT_f15;
  cell_wrap_28_stm32_T outT_f16;
  cell_wrap_28_stm32_T outT_f17;
  cell_wrap_28_stm32_T outT_f18;
  cell_wrap_28_stm32_T outT_f19;
  cell_wrap_28_stm32_T outT_f21;
  int32_T aux[638];
  int32_T aux_k[478];
  real_T y[224];
  real_T y_c[224];
  real32_T fv3[4];
  real_T sumVal1;
  real_T absx2_b;
  real_T absx3_p;
  int32_T b_weights_size[2];
  int32_T indices_size[2];
  real32_T unusedExpr[2];
  cell_wrap_16_stm32_T outMiniBatchGroup;
  cell_wrap_16_stm32_T outT_f25;
  boolean_T copyCols[7];
  int8_T c_data[7];
  int8_T d_data[7];
  real32_T biasReformatted;
  real32_T biasRegister;
  real32_T biasReformatted_c;
  real32_T biasRegister_f;
  real32_T biasReformatted_g;
  real32_T biasRegister_g;
  real32_T biasRegister_m;
  real32_T biasReformatted_n;
  real32_T biasReformatted_p;
  real32_T biasReformatted_l;
  real32_T biasReformatted_j;
  real32_T biasReformatted_d;
  real32_T biasReformatted_gu;
  real32_T biasReformatted_ld;
  real32_T biasReformatted_dh;
  real32_T biasReformatted_dy;
  real32_T biasReformatted_lx;
  int32_T linearInds;
  int32_T outCInd;
  int32_T k;
  int32_T b_k;
  int32_T b_linearInds;
  int32_T i2;
  int32_T xoffset;
  int32_T sumVal1_tmp;
  int32_T i;
  int32_T i1;
  int32_T bufferChannelMiniblockIdx;
  int32_T fusedInputWidthAndHeightIdx;
  int32_T inputWidthIdx;
  int32_T inputChannelMiniblockBaseIdx;
  int32_T inputScratchpadBufferBaseIdx;
  int32_T inputBufferIdx1;
  int32_T inputBufferIdx2;
  int32_T inputBufferIdx3;
  int32_T bufferChannelMiniblockIdx_o;
  int32_T fusedInputWidthAndHeightIdx_b;
  int32_T inputWidthIdx_n;
  int32_T inputChannelMiniblockBaseIdx_b;
  int32_T inputScratchpadBufferBaseIdx_l;
  int32_T inputBufferIdx1_h;
  int32_T inputBufferIdx2_b;
  int32_T inputBufferIdx3_d;
  int32_T inputIdx;
  int32_T weightsIdx;
  int32_T inputChannelBlockIdx;
  int32_T bufferChannelMiniblockIdx_e;
  int32_T numInputChannelMiniblockSizeAct;
  int32_T fusedInputWidthAndHeightIdx_j;
  int32_T inputWidthIdx_f;
  int32_T inputChannelMiniblockBaseIdx_a;
  int32_T bufferChannelMiniblockIdx_j;
  int32_T fusedInputWidthAndHeightIdx_jz;
  int32_T inputWidthIdx_o;
  int32_T inputChannelMiniblockBaseIdx_n;
  int32_T inputScratchpadBufferBaseIdx_i;
  int32_T inputBufferIdx1_o;
  int32_T inputBufferIdx2_n;
  int32_T inputBufferIdx3_m;
  int32_T bufferChannelMiniblockIdx_c;
  int32_T fusedInputWidthAndHeightIdx_m;
  int32_T inputWidthIdx_m;
  int32_T inputChannelMiniblockBaseIdx_j;
  int32_T inputScratchpadBufferBaseIdx_h;
  int32_T inputBufferIdx1_c;
  int32_T inputBufferIdx2_c;
  int32_T inputBufferIdx3_p;
  int32_T bufferChannelMiniblockIdx_p;
  int32_T fusedInputWidthAndHeightIdx_a;
  int32_T inputWidthIdx_e;
  int32_T inputChannelMiniblockBaseIdx_ax;
  int32_T bufferChannelMiniblockIdx_a;
  int32_T fusedInputWidthAndHeightIdx_i;
  int32_T inputWidthIdx_l;
  int32_T inputChannelMiniblockBaseIdx_o;
} B_stm32_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  c_coder_internal_ctarget_Deep_T network;/* '<S1>/MLFB' */
  boolean_T network_not_empty;         /* '<S1>/MLFB' */
} DW_stm32_T;

/* Parameters (default storage) */
struct P_stm32_T_ {
  uint8_T Constant1_Value[228723];     /* Expression: ImageValue
                                        * Referenced by: '<S2>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_stm32_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_stm32_T stm32_P;

/* Block signals (default storage) */
extern B_stm32_T stm32_B;

/* Block states (default storage) */
extern DW_stm32_T stm32_DW;

/* Model entry point functions */
extern void stm32_initialize(void);
extern void stm32_step(void);
extern void stm32_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stm32_T *const stm32_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'stm32'
 * '<S1>'   : 'stm32/Image Classifier'
 * '<S2>'   : 'stm32/Image From File'
 * '<S3>'   : 'stm32/Image Classifier/MLFB'
 */
#endif                                 /* RTW_HEADER_stm32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
