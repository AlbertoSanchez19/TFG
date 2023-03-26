/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stm32.c
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

#include "stm32.h"
#include "rtwtypes.h"
#include "stm32_types.h"
#include <string.h>
#include <math.h>
#include "stm32_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_stm32_T stm32_B;

/* Block states (default storage) */
DW_stm32_T stm32_DW;

/* Real-time model */
static RT_MODEL_stm32_T stm32_M_;
RT_MODEL_stm32_T *const stm32_M = &stm32_M_;

/* Forward declaration for local functions */
static void stm32_contributions(real_T weights_data[], int32_T weights_size[2],
  int32_T indices_data[], int32_T indices_size[2]);
static void stm32_convolutionKernel(const real32_T *inputBufferPtr, real32_T
  *outputBufferPtr, const real32_T *weightsPtr, boolean_T outputChannelTailCase);
static void stm32_convolution(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias);
static void s_conv2dDirectOptimizedColMajor(const real32_T X[150528], real32_T
  Z[150528]);
static void stm32_MaxPooling2DLayer_predict(const real32_T X[150528], real32_T
  Z[37632]);
static void stm32_convolutionKernel_d(const real32_T *inputBufferPtr, real32_T
  *outputBufferPtr, const real32_T *weightsPtr, boolean_T outputChannelTailCase);
static void stm32_convolution_d(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias);
static void conv2dDirectOptimizedColMajor_a(const real32_T X[37632], real32_T Z
  [3136]);
static void stm32_convolutionKernel_di(const real32_T *inputBufferPtr, real32_T *
  outputBufferPtr, const real32_T *weightsPtr, boolean_T outputChannelTailCase);
static void stm32_convolution_di(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias);
static void conv2dDirectOptimizedColMajo_ai(const real32_T X[3136], real32_T Z
  [119168]);
static void stm_MaxPooling2DLayer_predict_n(const real32_T X[119168], real32_T
  Z[29792]);
static void stm32_convolutionKernel_die(const real32_T *inputBufferPtr, real32_T
  *outputBufferPtr, const real32_T *weightsPtr, boolean_T outputChannelTailCase);
static void stm32_convolution_die(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias);
static void conv2dDirectOptimizedColMaj_aie(const real32_T X[29792], real32_T Z
  [784]);
static void conv2dDirectOptimizedColMa_aiel(const real32_T layer_Weights[48],
  const real32_T X[29792], real32_T Z[784]);
static void Convolution2DActivation_predict(const real32_T X[29792], real32_T Z
  [784]);
static void stm32_convolutionKernel_dieq(const real32_T *inputBufferPtr,
  real32_T *outputBufferPtr, const real32_T *weightsPtr, boolean_T
  outputChannelTailCase);
static void stm32_convolution_dieq(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias);
static void conv2dDirectOptimizedColM_aiel1(const real32_T X[784], real32_T Z
  [784]);
static void conv2dDirectOptimizedCol_aiel1d(const real32_T layer_Weights[48],
  const real32_T X[29792], real32_T Z[784]);
static void Convolution2DActivation_predi_h(const real32_T X[29792], real32_T Z
  [784]);
static void stm32_convolutionKernel_dieqb(const real32_T *inputBufferPtr,
  real32_T *outputBufferPtr, const real32_T *weightsPtr, boolean_T
  outputChannelTailCase);
static void stm32_convolution_dieqb(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias);
static void conv2dDirectOptimizedCo_aiel1da(const real32_T layer_Weights[400],
  const real32_T X[784], real32_T Z[784]);
static void Convolution2DActivation_pred_hu(const real32_T X[784], real32_T Z
  [784]);
static void st_MaxPooling2DLayer_predict_no(const real32_T X[29792], real32_T Z
  [29792]);
static void conv2dDirectOptimizedC_aiel1da3(const real32_T layer_Weights[48],
  const real32_T X[29792], real32_T Z[784]);
static void Convolution2DActivation_pre_hur(const real32_T X[29792], real32_T Z
  [784]);
static void stm32_cat(const real32_T varargin_1[784], const real32_T varargin_2
                      [784], const real32_T varargin_3[784], const real32_T
                      varargin_4[784], real32_T y[3136]);
static void stm32_convolutionKernel_dieqbr(const real32_T *inputBufferPtr,
  real32_T *outputBufferPtr, const real32_T *weightsPtr, boolean_T
  outputChannelTailCase);
static void stm32_convolution_dieqbr(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias);
static void conv2dDirectOptimized_aiel1da3p(const real32_T X[3136], real32_T Z
  [784]);
static void conv2dDirectOptimize_aiel1da3pi(const real32_T layer_Weights[16],
  const real32_T X[3136], real32_T Z[784]);
static void Convolution2DActivation_pr_hurc(const real32_T X[3136], real32_T Z
  [784]);
static void conv2dDirectOptimiz_aiel1da3piw(const real32_T layer_Weights[144],
  const real32_T X[784], real32_T Z[784]);
static void Convolution2DActivation_p_hurcm(const real32_T X[784], real32_T Z
  [784]);
static void conv2dDirectOptimi_aiel1da3piwz(const real32_T layer_Weights[16],
  const real32_T X[3136], real32_T Z[784]);
static void Convolution2DActivation__hurcml(const real32_T X[3136], real32_T Z
  [784]);
static void conv2dDirectOptim_aiel1da3piwz0(const real32_T layer_Weights[400],
  const real32_T X[784], real32_T Z[784]);
static void Convolution2DActivation_hurcmlu(const real32_T X[784], real32_T Z
  [784]);
static void s_MaxPooling2DLayer_predict_nor(const real32_T X[3136], real32_T Z
  [3136]);
static void conv2dDirectOpti_aiel1da3piwz0d(const real32_T layer_Weights[16],
  const real32_T X[3136], real32_T Z[784]);
static void Convolution2DActivatio_hurcmlun(const real32_T X[3136], real32_T Z
  [784]);
static void s_AveragePooling2DLayer_predict(const real32_T X[3136], real32_T Z[4]);
static void stm32_microKernel_die(int32_T K, const real32_T *A, int32_T LDA,
  const real32_T *B, real32_T *C);
static void stm32_microKernel_di(int32_T K, const real32_T *A, int32_T LDA,
  const real32_T *B, real32_T *C);
static void stm32_microKernel_d(int32_T K, const real32_T *A, int32_T LDA, const
  real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
static void stm32_microKernel(int32_T K, const real32_T *A, int32_T LDA, const
  real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
static void stm32_macroKernel(int32_T M, int32_T K, int32_T N, const real32_T *A,
  int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
static void stm32_matrixMultiply(int32_T M, int32_T K, int32_T N, int32_T
  blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A, const
  real32_T *B, real32_T *C);
static void stm_FullyConnectedLayer_predict(const real32_T X[4], real32_T Z[2]);
static void stm32_SoftmaxLayer_predict(const real32_T X1[2], real32_T Z1[2]);
static void stm32_iGetActivations(const cell_wrap_13_stm32_T *inputsT,
  cell_wrap_16_stm32_T *outputs);
static void stm_DeepLearningNetwork_predict(c_coder_internal_ctarget_Deep_T *obj,
  const uint8_T varargin_1[150528], real32_T varargout_1[2]);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absDenominator;
  uint32_T absNumerator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
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

/* Function for MATLAB Function: '<S1>/MLFB' */
static void stm32_contributions(real_T weights_data[], int32_T weights_size[2],
  int32_T indices_data[], int32_T indices_size[2])
{
  real_T absx;
  real_T absx2;
  real_T absx3;
  int32_T a;
  int32_T i2;
  int32_T ix;
  int32_T k;
  int32_T xoffset;
  int8_T b_data[8];
  int8_T c_data[8];
  boolean_T copyCols[8];
  static const int16_T e[224] = { -2, -1, 1, 2, 4, 5, 6, 8, 9, 11, 12, 14, 15,
    16, 18, 19, 21, 22, 23, 25, 26, 28, 29, 31, 32, 33, 35, 36, 38, 39, 41, 42,
    43, 45, 46, 48, 49, 51, 52, 53, 55, 56, 58, 59, 61, 62, 63, 65, 66, 68, 69,
    70, 72, 73, 75, 76, 78, 79, 80, 82, 83, 85, 86, 88, 89, 90, 92, 93, 95, 96,
    98, 99, 100, 102, 103, 105, 106, 108, 109, 110, 112, 113, 115, 116, 117, 119,
    120, 122, 123, 125, 126, 127, 129, 130, 132, 133, 135, 136, 137, 139, 140,
    142, 143, 145, 146, 147, 149, 150, 152, 153, 155, 156, 157, 159, 160, 162,
    163, 164, 166, 167, 169, 170, 172, 173, 174, 176, 177, 179, 180, 182, 183,
    184, 186, 187, 189, 190, 192, 193, 194, 196, 197, 199, 200, 202, 203, 204,
    206, 207, 209, 210, 211, 213, 214, 216, 217, 219, 220, 221, 223, 224, 226,
    227, 229, 230, 231, 233, 234, 236, 237, 239, 240, 241, 243, 244, 246, 247,
    249, 250, 251, 253, 254, 256, 257, 258, 260, 261, 263, 264, 266, 267, 268,
    270, 271, 273, 274, 276, 277, 278, 280, 281, 283, 284, 286, 287, 288, 290,
    291, 293, 294, 296, 297, 298, 300, 301, 303, 304, 305, 307, 308, 310, 311,
    313, 314, 315 };

  static const real_T f[224] = { 1.2120535714285714, 2.6361607142857144,
    4.0602678571428577, 5.484375, 6.9084821428571432, 8.3325892857142865,
    9.7566964285714288, 11.180803571428571, 12.604910714285715,
    14.029017857142858, 15.453125, 16.877232142857142, 18.301339285714285,
    19.725446428571427, 21.149553571428569, 22.573660714285712,
    23.997767857142854, 25.421875, 26.845982142857142, 28.270089285714285,
    29.694196428571427, 31.118303571428569, 32.542410714285715,
    33.966517857142861, 35.390625, 36.814732142857146, 38.238839285714285,
    39.662946428571431, 41.087053571428577, 42.511160714285715,
    43.935267857142861, 45.359375, 46.783482142857146, 48.207589285714285,
    49.631696428571431, 51.055803571428577, 52.479910714285715,
    53.904017857142861, 55.328125, 56.752232142857146, 58.176339285714285,
    59.600446428571431, 61.024553571428577, 62.448660714285715,
    63.872767857142861, 65.296875, 66.720982142857139, 68.145089285714292,
    69.569196428571431, 70.993303571428569, 72.417410714285722,
    73.841517857142861, 75.265625, 76.689732142857139, 78.113839285714292,
    79.537946428571431, 80.962053571428569, 82.386160714285722,
    83.810267857142861, 85.234375, 86.658482142857139, 88.082589285714292,
    89.506696428571431, 90.930803571428569, 92.354910714285722,
    93.779017857142861, 95.203125, 96.627232142857139, 98.051339285714292,
    99.475446428571431, 100.89955357142857, 102.32366071428572,
    103.74776785714286, 105.171875, 106.59598214285714, 108.02008928571429,
    109.44419642857143, 110.86830357142857, 112.29241071428572,
    113.71651785714286, 115.140625, 116.56473214285714, 117.98883928571429,
    119.41294642857143, 120.83705357142857, 122.26116071428572,
    123.68526785714286, 125.109375, 126.53348214285714, 127.95758928571429,
    129.38169642857142, 130.80580357142856, 132.22991071428569,
    133.65401785714283, 135.078125, 136.50223214285714, 137.92633928571428,
    139.35044642857142, 140.77455357142856, 142.19866071428569,
    143.62276785714283, 145.046875, 146.47098214285714, 147.89508928571428,
    149.31919642857142, 150.74330357142856, 152.16741071428569,
    153.59151785714283, 155.015625, 156.43973214285714, 157.86383928571428,
    159.28794642857142, 160.71205357142856, 162.13616071428569,
    163.56026785714283, 164.984375, 166.40848214285714, 167.83258928571428,
    169.25669642857142, 170.68080357142856, 172.10491071428569,
    173.52901785714283, 174.953125, 176.37723214285714, 177.80133928571428,
    179.22544642857142, 180.64955357142856, 182.07366071428569,
    183.49776785714283, 184.921875, 186.34598214285714, 187.77008928571428,
    189.19419642857142, 190.61830357142856, 192.04241071428569,
    193.46651785714283, 194.890625, 196.31473214285714, 197.73883928571428,
    199.16294642857142, 200.58705357142856, 202.01116071428569,
    203.43526785714283, 204.859375, 206.28348214285714, 207.70758928571428,
    209.13169642857142, 210.55580357142856, 211.97991071428569,
    213.40401785714283, 214.828125, 216.25223214285714, 217.67633928571428,
    219.10044642857142, 220.52455357142856, 221.94866071428569,
    223.37276785714283, 224.796875, 226.22098214285714, 227.64508928571428,
    229.06919642857142, 230.49330357142856, 231.91741071428569,
    233.34151785714283, 234.765625, 236.18973214285714, 237.61383928571428,
    239.03794642857142, 240.46205357142856, 241.88616071428569,
    243.31026785714283, 244.734375, 246.15848214285714, 247.58258928571428,
    249.00669642857142, 250.43080357142856, 251.85491071428569,
    253.27901785714283, 254.703125, 256.12723214285717, 257.55133928571428,
    258.97544642857144, 260.39955357142861, 261.82366071428572,
    263.24776785714289, 264.671875, 266.09598214285717, 267.52008928571428,
    268.94419642857144, 270.36830357142861, 271.79241071428572,
    273.21651785714289, 274.640625, 276.06473214285717, 277.48883928571428,
    278.91294642857144, 280.33705357142861, 281.76116071428572,
    283.18526785714289, 284.609375, 286.03348214285717, 287.45758928571428,
    288.88169642857144, 290.30580357142861, 291.72991071428572,
    293.15401785714289, 294.578125, 296.00223214285717, 297.42633928571428,
    298.85044642857144, 300.27455357142861, 301.69866071428572,
    303.12276785714289, 304.546875, 305.97098214285717, 307.39508928571428,
    308.81919642857144, 310.24330357142861, 311.66741071428572,
    313.09151785714289, 314.515625, 315.93973214285717, 317.36383928571428,
    318.78794642857144 };

  boolean_T exitg1;
  for (i2 = 0; i2 < 8; i2++) {
    for (xoffset = 0; xoffset < 224; xoffset++) {
      stm32_B.b_indices[xoffset + 224 * i2] = e[xoffset] + i2;
    }
  }

  for (i2 = 0; i2 < 1792; i2++) {
    stm32_B.absx2[i2] = stm32_B.b_indices[i2];
  }

  for (xoffset = 0; xoffset < 8; xoffset++) {
    for (k = 0; k < 224; k++) {
      i2 = 224 * xoffset + k;
      stm32_B.absx3[i2] = f[k] - stm32_B.absx2[i2];
    }
  }

  for (i2 = 0; i2 < 1792; i2++) {
    absx = fabs(0.70219435736677116 * stm32_B.absx3[i2]);
    absx2 = absx * absx;
    absx3 = rt_powd_snf(absx, 3.0);
    stm32_B.absx3[i2] = ((((-0.5 * absx3 + 2.5 * absx2) - 4.0 * absx) + 2.0) *
                         (real_T)((absx > 1.0) && (absx <= 2.0)) + ((1.5 * absx3
      - 2.5 * absx2) + 1.0) * (real_T)(absx <= 1.0)) * 0.70219435736677116;
  }

  memcpy(&stm32_B.y_c[0], &stm32_B.absx3[0], 224U * sizeof(real_T));
  for (i2 = 0; i2 < 7; i2++) {
    xoffset = (i2 + 1) * 224;
    for (k = 0; k < 224; k++) {
      stm32_B.y_c[k] += stm32_B.absx3[xoffset + k];
    }
  }

  memcpy(&stm32_B.absx2[0], &stm32_B.absx3[0], 1792U * sizeof(real_T));
  for (xoffset = 0; xoffset < 8; xoffset++) {
    for (k = 0; k < 224; k++) {
      i2 = 224 * xoffset + k;
      stm32_B.absx3[i2] = stm32_B.absx2[i2] / stm32_B.y_c[k];
    }
  }

  stm32_B.aux[0] = 1;
  stm32_B.aux[319] = 319;
  for (i2 = 0; i2 < 318; i2++) {
    stm32_B.aux[i2 + 1] = stm32_B.aux[i2] + 1;
    stm32_B.aux[i2 + 320] = stm32_B.aux[i2 + 319] - 1;
  }

  for (i2 = 0; i2 < 1792; i2++) {
    xoffset = stm32_B.b_indices[i2];
    if ((real_T)xoffset - 1.0 == 0.0) {
      k = 0;
    } else {
      k = (int32_T)fmod((real_T)xoffset - 1.0, 638.0);
      if ((k != 0) && ((real_T)xoffset - 1.0 < 0.0)) {
        k += 638;
      }
    }

    stm32_B.b_indices[i2] = stm32_B.aux[k];
  }

  i2 = 0;
  xoffset = 0;
  for (k = 0; k < 8; k++) {
    copyCols[k] = false;
    a = i2 + 224;
    ix = i2;
    i2 += 224;
    exitg1 = false;
    while ((!exitg1) && (ix + 1 <= a)) {
      if ((!(stm32_B.absx3[ix] == 0.0)) && (!rtIsNaN(stm32_B.absx3[ix]))) {
        copyCols[k] = true;
        exitg1 = true;
      } else {
        ix++;
      }
    }

    if (copyCols[k]) {
      xoffset++;
    }
  }

  a = xoffset;
  i2 = 0;
  for (xoffset = 0; xoffset < 8; xoffset++) {
    if (copyCols[xoffset]) {
      b_data[i2] = (int8_T)(xoffset + 1);
      i2++;
    }
  }

  weights_size[0] = a;
  weights_size[1] = 224;
  for (i2 = 0; i2 < 224; i2++) {
    for (k = 0; k < a; k++) {
      weights_data[k + a * i2] = stm32_B.absx3[(b_data[k] - 1) * 224 + i2];
    }
  }

  i2 = 0;
  for (xoffset = 0; xoffset < 8; xoffset++) {
    if (copyCols[xoffset]) {
      i2++;
    }
  }

  a = i2;
  i2 = 0;
  for (xoffset = 0; xoffset < 8; xoffset++) {
    if (copyCols[xoffset]) {
      c_data[i2] = (int8_T)(xoffset + 1);
      i2++;
    }
  }

  indices_size[0] = a;
  indices_size[1] = 224;
  for (i2 = 0; i2 < 224; i2++) {
    for (k = 0; k < a; k++) {
      indices_data[k + a * i2] = stm32_B.b_indices[(c_data[k] - 1) * 224 + i2];
    }
  }
}

static void stm32_convolutionKernel(const real32_T *inputBufferPtr, real32_T
  *outputBufferPtr, const real32_T *weightsPtr, boolean_T outputChannelTailCase)
{
  int32_T inputChannelIdx;
  int32_T kernelHeightIdx;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  int32_T weightsIdx;
  real32_T inputRegister;
  real32_T inputRegister_0;
  real32_T inputRegister_1;
  real32_T inputRegister_2;
  real32_T inputRegister_3;
  real32_T inputRegister_4;
  real32_T inputRegister_5;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_10;
  real32_T outputRegister_11;
  real32_T outputRegister_12;
  real32_T outputRegister_13;
  real32_T outputRegister_14;
  real32_T outputRegister_15;
  real32_T outputRegister_16;
  real32_T outputRegister_17;
  real32_T outputRegister_18;
  real32_T outputRegister_19;
  real32_T outputRegister_1a;
  real32_T outputRegister_1b;
  real32_T outputRegister_1c;
  real32_T outputRegister_1d;
  real32_T outputRegister_1e;
  real32_T outputRegister_1f;
  real32_T outputRegister_1g;
  real32_T outputRegister_1h;
  real32_T outputRegister_1i;
  real32_T outputRegister_1j;
  real32_T outputRegister_1k;
  real32_T outputRegister_1l;
  real32_T outputRegister_1m;
  real32_T outputRegister_1n;
  real32_T outputRegister_1o;
  real32_T outputRegister_1p;
  real32_T outputRegister_1q;
  real32_T outputRegister_1r;
  real32_T outputRegister_1s;
  real32_T outputRegister_1t;
  real32_T outputRegister_1u;
  real32_T outputRegister_1v;
  real32_T outputRegister_1w;
  real32_T outputRegister_1x;
  real32_T outputRegister_1y;
  real32_T outputRegister_1z;
  real32_T outputRegister_2;
  real32_T outputRegister_20;
  real32_T outputRegister_21;
  real32_T outputRegister_22;
  real32_T outputRegister_23;
  real32_T outputRegister_24;
  real32_T outputRegister_25;
  real32_T outputRegister_26;
  real32_T outputRegister_27;
  real32_T outputRegister_28;
  real32_T outputRegister_29;
  real32_T outputRegister_2a;
  real32_T outputRegister_2b;
  real32_T outputRegister_2c;
  real32_T outputRegister_2d;
  real32_T outputRegister_2e;
  real32_T outputRegister_2f;
  real32_T outputRegister_2g;
  real32_T outputRegister_2h;
  real32_T outputRegister_2i;
  real32_T outputRegister_2j;
  real32_T outputRegister_2k;
  real32_T outputRegister_2l;
  real32_T outputRegister_2m;
  real32_T outputRegister_2n;
  real32_T outputRegister_2o;
  real32_T outputRegister_2p;
  real32_T outputRegister_2q;
  real32_T outputRegister_2r;
  real32_T outputRegister_2s;
  real32_T outputRegister_2t;
  real32_T outputRegister_2u;
  real32_T outputRegister_2v;
  real32_T outputRegister_2w;
  real32_T outputRegister_2x;
  real32_T outputRegister_2y;
  real32_T outputRegister_2z;
  real32_T outputRegister_3;
  real32_T outputRegister_30;
  real32_T outputRegister_31;
  real32_T outputRegister_32;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  real32_T outputRegister_f;
  real32_T outputRegister_g;
  real32_T outputRegister_h;
  real32_T outputRegister_i;
  real32_T outputRegister_j;
  real32_T outputRegister_k;
  real32_T outputRegister_l;
  real32_T outputRegister_m;
  real32_T outputRegister_n;
  real32_T outputRegister_o;
  real32_T outputRegister_p;
  real32_T outputRegister_q;
  real32_T outputRegister_r;
  real32_T outputRegister_s;
  real32_T outputRegister_t;
  real32_T outputRegister_u;
  real32_T outputRegister_v;
  real32_T outputRegister_w;
  real32_T outputRegister_x;
  real32_T outputRegister_y;
  real32_T outputRegister_z;
  real32_T weightsRegister;
  if (outputChannelTailCase) {
    stm32_B.inputBufferIdx1_c = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 16;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 12544];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 12545];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 12546];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 12547];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 12548];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 12549];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 12550];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 25088];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 25089];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 25090];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 25091];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 25092];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 25093];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 25094];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 37632];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 37633];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 37634];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 37635];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 37636];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 37637];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 37638];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 50176];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 50177];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 50178];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 50179];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 50180];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 50181];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 50182];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 62720];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 62721];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 62722];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 62723];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 62724];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 62725];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 62726];
      outputRegister_15 = outputBufferPtr[outputHeightBlockIdx * 7 + 75264];
      outputRegister_16 = outputBufferPtr[outputHeightBlockIdx * 7 + 75265];
      outputRegister_17 = outputBufferPtr[outputHeightBlockIdx * 7 + 75266];
      outputRegister_18 = outputBufferPtr[outputHeightBlockIdx * 7 + 75267];
      outputRegister_19 = outputBufferPtr[outputHeightBlockIdx * 7 + 75268];
      outputRegister_1a = outputBufferPtr[outputHeightBlockIdx * 7 + 75269];
      outputRegister_1b = outputBufferPtr[outputHeightBlockIdx * 7 + 75270];
      outputRegister_1c = outputBufferPtr[outputHeightBlockIdx * 7 + 87808];
      outputRegister_1d = outputBufferPtr[outputHeightBlockIdx * 7 + 87809];
      outputRegister_1e = outputBufferPtr[outputHeightBlockIdx * 7 + 87810];
      outputRegister_1f = outputBufferPtr[outputHeightBlockIdx * 7 + 87811];
      outputRegister_1g = outputBufferPtr[outputHeightBlockIdx * 7 + 87812];
      outputRegister_1h = outputBufferPtr[outputHeightBlockIdx * 7 + 87813];
      outputRegister_1i = outputBufferPtr[outputHeightBlockIdx * 7 + 87814];
      outputRegister_1j = outputBufferPtr[outputHeightBlockIdx * 7 + 100352];
      outputRegister_1k = outputBufferPtr[outputHeightBlockIdx * 7 + 100353];
      outputRegister_1l = outputBufferPtr[outputHeightBlockIdx * 7 + 100354];
      outputRegister_1m = outputBufferPtr[outputHeightBlockIdx * 7 + 100355];
      outputRegister_1n = outputBufferPtr[outputHeightBlockIdx * 7 + 100356];
      outputRegister_1o = outputBufferPtr[outputHeightBlockIdx * 7 + 100357];
      outputRegister_1p = outputBufferPtr[outputHeightBlockIdx * 7 + 100358];
      outputRegister_1q = outputBufferPtr[outputHeightBlockIdx * 7 + 112896];
      outputRegister_1r = outputBufferPtr[outputHeightBlockIdx * 7 + 112897];
      outputRegister_1s = outputBufferPtr[outputHeightBlockIdx * 7 + 112898];
      outputRegister_1t = outputBufferPtr[outputHeightBlockIdx * 7 + 112899];
      outputRegister_1u = outputBufferPtr[outputHeightBlockIdx * 7 + 112900];
      outputRegister_1v = outputBufferPtr[outputHeightBlockIdx * 7 + 112901];
      outputRegister_1w = outputBufferPtr[outputHeightBlockIdx * 7 + 112902];
      outputRegister_1x = outputBufferPtr[outputHeightBlockIdx * 7 + 125440];
      outputRegister_1y = outputBufferPtr[outputHeightBlockIdx * 7 + 125441];
      outputRegister_1z = outputBufferPtr[outputHeightBlockIdx * 7 + 125442];
      outputRegister_20 = outputBufferPtr[outputHeightBlockIdx * 7 + 125443];
      outputRegister_21 = outputBufferPtr[outputHeightBlockIdx * 7 + 125444];
      outputRegister_22 = outputBufferPtr[outputHeightBlockIdx * 7 + 125445];
      outputRegister_23 = outputBufferPtr[outputHeightBlockIdx * 7 + 125446];
      outputRegister_24 = outputBufferPtr[outputHeightBlockIdx * 7 + 137984];
      outputRegister_25 = outputBufferPtr[outputHeightBlockIdx * 7 + 137985];
      outputRegister_26 = outputBufferPtr[outputHeightBlockIdx * 7 + 137986];
      outputRegister_27 = outputBufferPtr[outputHeightBlockIdx * 7 + 137987];
      outputRegister_28 = outputBufferPtr[outputHeightBlockIdx * 7 + 137988];
      outputRegister_29 = outputBufferPtr[outputHeightBlockIdx * 7 + 137989];
      outputRegister_2a = outputBufferPtr[outputHeightBlockIdx * 7 + 137990];
      stm32_B.inputBufferIdx2_c = stm32_B.inputBufferIdx1_c;
      weightsIdx = 784;
      for (kernelWidthIdx = 0; kernelWidthIdx < 7; kernelWidthIdx++) {
        stm32_B.inputBufferIdx3_p = stm32_B.inputBufferIdx2_c;
        for (kernelHeightIdx = 0; kernelHeightIdx < 7; kernelHeightIdx++) {
          for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
            inputRegister = inputBufferPtr[stm32_B.inputBufferIdx3_p +
              inputChannelIdx];
            inputRegister_0 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 32];
            inputRegister_1 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 64];
            inputRegister_2 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 96];
            inputRegister_3 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 128];
            inputRegister_4 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 160];
            inputRegister_5 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 192];
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) - 784];
            outputRegister += inputRegister * weightsRegister;
            outputRegister_0 += inputRegister_0 * weightsRegister;
            outputRegister_1 += inputRegister_1 * weightsRegister;
            outputRegister_2 += inputRegister_2 * weightsRegister;
            outputRegister_3 += inputRegister_3 * weightsRegister;
            outputRegister_4 += inputRegister_4 * weightsRegister;
            outputRegister_5 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[weightsIdx + inputChannelIdx];
            outputRegister_6 += inputRegister * weightsRegister;
            outputRegister_7 += inputRegister_0 * weightsRegister;
            outputRegister_8 += inputRegister_1 * weightsRegister;
            outputRegister_9 += inputRegister_2 * weightsRegister;
            outputRegister_a += inputRegister_3 * weightsRegister;
            outputRegister_b += inputRegister_4 * weightsRegister;
            outputRegister_c += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 784];
            outputRegister_d += inputRegister * weightsRegister;
            outputRegister_e += inputRegister_0 * weightsRegister;
            outputRegister_f += inputRegister_1 * weightsRegister;
            outputRegister_g += inputRegister_2 * weightsRegister;
            outputRegister_h += inputRegister_3 * weightsRegister;
            outputRegister_i += inputRegister_4 * weightsRegister;
            outputRegister_j += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1568];
            outputRegister_k += inputRegister * weightsRegister;
            outputRegister_l += inputRegister_0 * weightsRegister;
            outputRegister_m += inputRegister_1 * weightsRegister;
            outputRegister_n += inputRegister_2 * weightsRegister;
            outputRegister_o += inputRegister_3 * weightsRegister;
            outputRegister_p += inputRegister_4 * weightsRegister;
            outputRegister_q += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 2352];
            outputRegister_r += inputRegister * weightsRegister;
            outputRegister_s += inputRegister_0 * weightsRegister;
            outputRegister_t += inputRegister_1 * weightsRegister;
            outputRegister_u += inputRegister_2 * weightsRegister;
            outputRegister_v += inputRegister_3 * weightsRegister;
            outputRegister_w += inputRegister_4 * weightsRegister;
            outputRegister_x += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 3136];
            outputRegister_y += inputRegister * weightsRegister;
            outputRegister_z += inputRegister_0 * weightsRegister;
            outputRegister_10 += inputRegister_1 * weightsRegister;
            outputRegister_11 += inputRegister_2 * weightsRegister;
            outputRegister_12 += inputRegister_3 * weightsRegister;
            outputRegister_13 += inputRegister_4 * weightsRegister;
            outputRegister_14 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 3920];
            outputRegister_15 += inputRegister * weightsRegister;
            outputRegister_16 += inputRegister_0 * weightsRegister;
            outputRegister_17 += inputRegister_1 * weightsRegister;
            outputRegister_18 += inputRegister_2 * weightsRegister;
            outputRegister_19 += inputRegister_3 * weightsRegister;
            outputRegister_1a += inputRegister_4 * weightsRegister;
            outputRegister_1b += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 4704];
            outputRegister_1c += inputRegister * weightsRegister;
            outputRegister_1d += inputRegister_0 * weightsRegister;
            outputRegister_1e += inputRegister_1 * weightsRegister;
            outputRegister_1f += inputRegister_2 * weightsRegister;
            outputRegister_1g += inputRegister_3 * weightsRegister;
            outputRegister_1h += inputRegister_4 * weightsRegister;
            outputRegister_1i += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 5488];
            outputRegister_1j += inputRegister * weightsRegister;
            outputRegister_1k += inputRegister_0 * weightsRegister;
            outputRegister_1l += inputRegister_1 * weightsRegister;
            outputRegister_1m += inputRegister_2 * weightsRegister;
            outputRegister_1n += inputRegister_3 * weightsRegister;
            outputRegister_1o += inputRegister_4 * weightsRegister;
            outputRegister_1p += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 6272];
            outputRegister_1q += inputRegister * weightsRegister;
            outputRegister_1r += inputRegister_0 * weightsRegister;
            outputRegister_1s += inputRegister_1 * weightsRegister;
            outputRegister_1t += inputRegister_2 * weightsRegister;
            outputRegister_1u += inputRegister_3 * weightsRegister;
            outputRegister_1v += inputRegister_4 * weightsRegister;
            outputRegister_1w += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 7056];
            outputRegister_1x += inputRegister * weightsRegister;
            outputRegister_1y += inputRegister_0 * weightsRegister;
            outputRegister_1z += inputRegister_1 * weightsRegister;
            outputRegister_20 += inputRegister_2 * weightsRegister;
            outputRegister_21 += inputRegister_3 * weightsRegister;
            outputRegister_22 += inputRegister_4 * weightsRegister;
            outputRegister_23 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 7840];
            outputRegister_24 += inputRegister * weightsRegister;
            outputRegister_25 += inputRegister_0 * weightsRegister;
            outputRegister_26 += inputRegister_1 * weightsRegister;
            outputRegister_27 += inputRegister_2 * weightsRegister;
            outputRegister_28 += inputRegister_3 * weightsRegister;
            outputRegister_29 += inputRegister_4 * weightsRegister;
            outputRegister_2a += inputRegister_5 * weightsRegister;
          }

          weightsIdx += 16;
          stm32_B.inputBufferIdx3_p += 16;
        }

        stm32_B.inputBufferIdx2_c += 3680;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12544] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12545] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12546] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12547] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12548] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12549] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12550] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25088] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25089] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25090] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25091] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25092] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25093] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25094] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37632] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37633] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37634] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37635] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37636] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37637] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37638] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50176] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50177] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50178] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50179] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50180] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50181] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50182] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62720] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62721] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62722] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62723] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62724] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62725] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62726] = outputRegister_14;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75264] = outputRegister_15;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75265] = outputRegister_16;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75266] = outputRegister_17;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75267] = outputRegister_18;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75268] = outputRegister_19;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75269] = outputRegister_1a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75270] = outputRegister_1b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87808] = outputRegister_1c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87809] = outputRegister_1d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87810] = outputRegister_1e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87811] = outputRegister_1f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87812] = outputRegister_1g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87813] = outputRegister_1h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87814] = outputRegister_1i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100352] = outputRegister_1j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100353] = outputRegister_1k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100354] = outputRegister_1l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100355] = outputRegister_1m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100356] = outputRegister_1n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100357] = outputRegister_1o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100358] = outputRegister_1p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112896] = outputRegister_1q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112897] = outputRegister_1r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112898] = outputRegister_1s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112899] = outputRegister_1t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112900] = outputRegister_1u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112901] = outputRegister_1v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112902] = outputRegister_1w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125440] = outputRegister_1x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125441] = outputRegister_1y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125442] = outputRegister_1z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125443] = outputRegister_20;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125444] = outputRegister_21;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125445] = outputRegister_22;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125446] = outputRegister_23;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137984] = outputRegister_24;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137985] = outputRegister_25;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137986] = outputRegister_26;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137987] = outputRegister_27;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137988] = outputRegister_28;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137989] = outputRegister_29;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137990] = outputRegister_2a;
      stm32_B.inputBufferIdx1_c += 224;
    }
  } else {
    stm32_B.inputBufferIdx1_c = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 16;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 12544];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 12545];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 12546];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 12547];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 12548];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 12549];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 12550];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 25088];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 25089];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 25090];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 25091];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 25092];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 25093];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 25094];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 37632];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 37633];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 37634];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 37635];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 37636];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 37637];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 37638];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 50176];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 50177];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 50178];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 50179];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 50180];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 50181];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 50182];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 62720];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 62721];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 62722];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 62723];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 62724];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 62725];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 62726];
      outputRegister_15 = outputBufferPtr[outputHeightBlockIdx * 7 + 75264];
      outputRegister_16 = outputBufferPtr[outputHeightBlockIdx * 7 + 75265];
      outputRegister_17 = outputBufferPtr[outputHeightBlockIdx * 7 + 75266];
      outputRegister_18 = outputBufferPtr[outputHeightBlockIdx * 7 + 75267];
      outputRegister_19 = outputBufferPtr[outputHeightBlockIdx * 7 + 75268];
      outputRegister_1a = outputBufferPtr[outputHeightBlockIdx * 7 + 75269];
      outputRegister_1b = outputBufferPtr[outputHeightBlockIdx * 7 + 75270];
      outputRegister_1c = outputBufferPtr[outputHeightBlockIdx * 7 + 87808];
      outputRegister_1d = outputBufferPtr[outputHeightBlockIdx * 7 + 87809];
      outputRegister_1e = outputBufferPtr[outputHeightBlockIdx * 7 + 87810];
      outputRegister_1f = outputBufferPtr[outputHeightBlockIdx * 7 + 87811];
      outputRegister_1g = outputBufferPtr[outputHeightBlockIdx * 7 + 87812];
      outputRegister_1h = outputBufferPtr[outputHeightBlockIdx * 7 + 87813];
      outputRegister_1i = outputBufferPtr[outputHeightBlockIdx * 7 + 87814];
      outputRegister_1j = outputBufferPtr[outputHeightBlockIdx * 7 + 100352];
      outputRegister_1k = outputBufferPtr[outputHeightBlockIdx * 7 + 100353];
      outputRegister_1l = outputBufferPtr[outputHeightBlockIdx * 7 + 100354];
      outputRegister_1m = outputBufferPtr[outputHeightBlockIdx * 7 + 100355];
      outputRegister_1n = outputBufferPtr[outputHeightBlockIdx * 7 + 100356];
      outputRegister_1o = outputBufferPtr[outputHeightBlockIdx * 7 + 100357];
      outputRegister_1p = outputBufferPtr[outputHeightBlockIdx * 7 + 100358];
      outputRegister_1q = outputBufferPtr[outputHeightBlockIdx * 7 + 112896];
      outputRegister_1r = outputBufferPtr[outputHeightBlockIdx * 7 + 112897];
      outputRegister_1s = outputBufferPtr[outputHeightBlockIdx * 7 + 112898];
      outputRegister_1t = outputBufferPtr[outputHeightBlockIdx * 7 + 112899];
      outputRegister_1u = outputBufferPtr[outputHeightBlockIdx * 7 + 112900];
      outputRegister_1v = outputBufferPtr[outputHeightBlockIdx * 7 + 112901];
      outputRegister_1w = outputBufferPtr[outputHeightBlockIdx * 7 + 112902];
      outputRegister_1x = outputBufferPtr[outputHeightBlockIdx * 7 + 125440];
      outputRegister_1y = outputBufferPtr[outputHeightBlockIdx * 7 + 125441];
      outputRegister_1z = outputBufferPtr[outputHeightBlockIdx * 7 + 125442];
      outputRegister_20 = outputBufferPtr[outputHeightBlockIdx * 7 + 125443];
      outputRegister_21 = outputBufferPtr[outputHeightBlockIdx * 7 + 125444];
      outputRegister_22 = outputBufferPtr[outputHeightBlockIdx * 7 + 125445];
      outputRegister_23 = outputBufferPtr[outputHeightBlockIdx * 7 + 125446];
      outputRegister_24 = outputBufferPtr[outputHeightBlockIdx * 7 + 137984];
      outputRegister_25 = outputBufferPtr[outputHeightBlockIdx * 7 + 137985];
      outputRegister_26 = outputBufferPtr[outputHeightBlockIdx * 7 + 137986];
      outputRegister_27 = outputBufferPtr[outputHeightBlockIdx * 7 + 137987];
      outputRegister_28 = outputBufferPtr[outputHeightBlockIdx * 7 + 137988];
      outputRegister_29 = outputBufferPtr[outputHeightBlockIdx * 7 + 137989];
      outputRegister_2a = outputBufferPtr[outputHeightBlockIdx * 7 + 137990];
      outputRegister_2b = outputBufferPtr[outputHeightBlockIdx * 7 + 150528];
      outputRegister_2c = outputBufferPtr[outputHeightBlockIdx * 7 + 150529];
      outputRegister_2d = outputBufferPtr[outputHeightBlockIdx * 7 + 150530];
      outputRegister_2e = outputBufferPtr[outputHeightBlockIdx * 7 + 150531];
      outputRegister_2f = outputBufferPtr[outputHeightBlockIdx * 7 + 150532];
      outputRegister_2g = outputBufferPtr[outputHeightBlockIdx * 7 + 150533];
      outputRegister_2h = outputBufferPtr[outputHeightBlockIdx * 7 + 150534];
      outputRegister_2i = outputBufferPtr[outputHeightBlockIdx * 7 + 163072];
      outputRegister_2j = outputBufferPtr[outputHeightBlockIdx * 7 + 163073];
      outputRegister_2k = outputBufferPtr[outputHeightBlockIdx * 7 + 163074];
      outputRegister_2l = outputBufferPtr[outputHeightBlockIdx * 7 + 163075];
      outputRegister_2m = outputBufferPtr[outputHeightBlockIdx * 7 + 163076];
      outputRegister_2n = outputBufferPtr[outputHeightBlockIdx * 7 + 163077];
      outputRegister_2o = outputBufferPtr[outputHeightBlockIdx * 7 + 163078];
      outputRegister_2p = outputBufferPtr[outputHeightBlockIdx * 7 + 175616];
      outputRegister_2q = outputBufferPtr[outputHeightBlockIdx * 7 + 175617];
      outputRegister_2r = outputBufferPtr[outputHeightBlockIdx * 7 + 175618];
      outputRegister_2s = outputBufferPtr[outputHeightBlockIdx * 7 + 175619];
      outputRegister_2t = outputBufferPtr[outputHeightBlockIdx * 7 + 175620];
      outputRegister_2u = outputBufferPtr[outputHeightBlockIdx * 7 + 175621];
      outputRegister_2v = outputBufferPtr[outputHeightBlockIdx * 7 + 175622];
      outputRegister_2w = outputBufferPtr[outputHeightBlockIdx * 7 + 188160];
      outputRegister_2x = outputBufferPtr[outputHeightBlockIdx * 7 + 188161];
      outputRegister_2y = outputBufferPtr[outputHeightBlockIdx * 7 + 188162];
      outputRegister_2z = outputBufferPtr[outputHeightBlockIdx * 7 + 188163];
      outputRegister_30 = outputBufferPtr[outputHeightBlockIdx * 7 + 188164];
      outputRegister_31 = outputBufferPtr[outputHeightBlockIdx * 7 + 188165];
      outputRegister_32 = outputBufferPtr[outputHeightBlockIdx * 7 + 188166];
      stm32_B.inputBufferIdx2_c = stm32_B.inputBufferIdx1_c;
      weightsIdx = 784;
      for (kernelWidthIdx = 0; kernelWidthIdx < 7; kernelWidthIdx++) {
        stm32_B.inputBufferIdx3_p = stm32_B.inputBufferIdx2_c;
        for (kernelHeightIdx = 0; kernelHeightIdx < 7; kernelHeightIdx++) {
          for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
            inputRegister = inputBufferPtr[stm32_B.inputBufferIdx3_p +
              inputChannelIdx];
            inputRegister_0 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 32];
            inputRegister_1 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 64];
            inputRegister_2 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 96];
            inputRegister_3 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 128];
            inputRegister_4 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 160];
            inputRegister_5 = inputBufferPtr[(stm32_B.inputBufferIdx3_p +
              inputChannelIdx) + 192];
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) - 784];
            outputRegister += inputRegister * weightsRegister;
            outputRegister_0 += inputRegister_0 * weightsRegister;
            outputRegister_1 += inputRegister_1 * weightsRegister;
            outputRegister_2 += inputRegister_2 * weightsRegister;
            outputRegister_3 += inputRegister_3 * weightsRegister;
            outputRegister_4 += inputRegister_4 * weightsRegister;
            outputRegister_5 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[weightsIdx + inputChannelIdx];
            outputRegister_6 += inputRegister * weightsRegister;
            outputRegister_7 += inputRegister_0 * weightsRegister;
            outputRegister_8 += inputRegister_1 * weightsRegister;
            outputRegister_9 += inputRegister_2 * weightsRegister;
            outputRegister_a += inputRegister_3 * weightsRegister;
            outputRegister_b += inputRegister_4 * weightsRegister;
            outputRegister_c += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 784];
            outputRegister_d += inputRegister * weightsRegister;
            outputRegister_e += inputRegister_0 * weightsRegister;
            outputRegister_f += inputRegister_1 * weightsRegister;
            outputRegister_g += inputRegister_2 * weightsRegister;
            outputRegister_h += inputRegister_3 * weightsRegister;
            outputRegister_i += inputRegister_4 * weightsRegister;
            outputRegister_j += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1568];
            outputRegister_k += inputRegister * weightsRegister;
            outputRegister_l += inputRegister_0 * weightsRegister;
            outputRegister_m += inputRegister_1 * weightsRegister;
            outputRegister_n += inputRegister_2 * weightsRegister;
            outputRegister_o += inputRegister_3 * weightsRegister;
            outputRegister_p += inputRegister_4 * weightsRegister;
            outputRegister_q += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 2352];
            outputRegister_r += inputRegister * weightsRegister;
            outputRegister_s += inputRegister_0 * weightsRegister;
            outputRegister_t += inputRegister_1 * weightsRegister;
            outputRegister_u += inputRegister_2 * weightsRegister;
            outputRegister_v += inputRegister_3 * weightsRegister;
            outputRegister_w += inputRegister_4 * weightsRegister;
            outputRegister_x += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 3136];
            outputRegister_y += inputRegister * weightsRegister;
            outputRegister_z += inputRegister_0 * weightsRegister;
            outputRegister_10 += inputRegister_1 * weightsRegister;
            outputRegister_11 += inputRegister_2 * weightsRegister;
            outputRegister_12 += inputRegister_3 * weightsRegister;
            outputRegister_13 += inputRegister_4 * weightsRegister;
            outputRegister_14 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 3920];
            outputRegister_15 += inputRegister * weightsRegister;
            outputRegister_16 += inputRegister_0 * weightsRegister;
            outputRegister_17 += inputRegister_1 * weightsRegister;
            outputRegister_18 += inputRegister_2 * weightsRegister;
            outputRegister_19 += inputRegister_3 * weightsRegister;
            outputRegister_1a += inputRegister_4 * weightsRegister;
            outputRegister_1b += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 4704];
            outputRegister_1c += inputRegister * weightsRegister;
            outputRegister_1d += inputRegister_0 * weightsRegister;
            outputRegister_1e += inputRegister_1 * weightsRegister;
            outputRegister_1f += inputRegister_2 * weightsRegister;
            outputRegister_1g += inputRegister_3 * weightsRegister;
            outputRegister_1h += inputRegister_4 * weightsRegister;
            outputRegister_1i += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 5488];
            outputRegister_1j += inputRegister * weightsRegister;
            outputRegister_1k += inputRegister_0 * weightsRegister;
            outputRegister_1l += inputRegister_1 * weightsRegister;
            outputRegister_1m += inputRegister_2 * weightsRegister;
            outputRegister_1n += inputRegister_3 * weightsRegister;
            outputRegister_1o += inputRegister_4 * weightsRegister;
            outputRegister_1p += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 6272];
            outputRegister_1q += inputRegister * weightsRegister;
            outputRegister_1r += inputRegister_0 * weightsRegister;
            outputRegister_1s += inputRegister_1 * weightsRegister;
            outputRegister_1t += inputRegister_2 * weightsRegister;
            outputRegister_1u += inputRegister_3 * weightsRegister;
            outputRegister_1v += inputRegister_4 * weightsRegister;
            outputRegister_1w += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 7056];
            outputRegister_1x += inputRegister * weightsRegister;
            outputRegister_1y += inputRegister_0 * weightsRegister;
            outputRegister_1z += inputRegister_1 * weightsRegister;
            outputRegister_20 += inputRegister_2 * weightsRegister;
            outputRegister_21 += inputRegister_3 * weightsRegister;
            outputRegister_22 += inputRegister_4 * weightsRegister;
            outputRegister_23 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 7840];
            outputRegister_24 += inputRegister * weightsRegister;
            outputRegister_25 += inputRegister_0 * weightsRegister;
            outputRegister_26 += inputRegister_1 * weightsRegister;
            outputRegister_27 += inputRegister_2 * weightsRegister;
            outputRegister_28 += inputRegister_3 * weightsRegister;
            outputRegister_29 += inputRegister_4 * weightsRegister;
            outputRegister_2a += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 8624];
            outputRegister_2b += inputRegister * weightsRegister;
            outputRegister_2c += inputRegister_0 * weightsRegister;
            outputRegister_2d += inputRegister_1 * weightsRegister;
            outputRegister_2e += inputRegister_2 * weightsRegister;
            outputRegister_2f += inputRegister_3 * weightsRegister;
            outputRegister_2g += inputRegister_4 * weightsRegister;
            outputRegister_2h += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 9408];
            outputRegister_2i += inputRegister * weightsRegister;
            outputRegister_2j += inputRegister_0 * weightsRegister;
            outputRegister_2k += inputRegister_1 * weightsRegister;
            outputRegister_2l += inputRegister_2 * weightsRegister;
            outputRegister_2m += inputRegister_3 * weightsRegister;
            outputRegister_2n += inputRegister_4 * weightsRegister;
            outputRegister_2o += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 10192];
            outputRegister_2p += inputRegister * weightsRegister;
            outputRegister_2q += inputRegister_0 * weightsRegister;
            outputRegister_2r += inputRegister_1 * weightsRegister;
            outputRegister_2s += inputRegister_2 * weightsRegister;
            outputRegister_2t += inputRegister_3 * weightsRegister;
            outputRegister_2u += inputRegister_4 * weightsRegister;
            outputRegister_2v += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 10976];
            outputRegister_2w += inputRegister * weightsRegister;
            outputRegister_2x += inputRegister_0 * weightsRegister;
            outputRegister_2y += inputRegister_1 * weightsRegister;
            outputRegister_2z += inputRegister_2 * weightsRegister;
            outputRegister_30 += inputRegister_3 * weightsRegister;
            outputRegister_31 += inputRegister_4 * weightsRegister;
            outputRegister_32 += inputRegister_5 * weightsRegister;
          }

          weightsIdx += 16;
          stm32_B.inputBufferIdx3_p += 16;
        }

        stm32_B.inputBufferIdx2_c += 3680;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12544] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12545] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12546] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12547] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12548] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12549] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12550] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25088] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25089] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25090] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25091] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25092] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25093] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25094] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37632] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37633] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37634] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37635] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37636] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37637] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37638] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50176] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50177] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50178] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50179] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50180] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50181] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 50182] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62720] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62721] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62722] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62723] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62724] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62725] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 62726] = outputRegister_14;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75264] = outputRegister_15;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75265] = outputRegister_16;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75266] = outputRegister_17;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75267] = outputRegister_18;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75268] = outputRegister_19;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75269] = outputRegister_1a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 75270] = outputRegister_1b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87808] = outputRegister_1c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87809] = outputRegister_1d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87810] = outputRegister_1e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87811] = outputRegister_1f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87812] = outputRegister_1g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87813] = outputRegister_1h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 87814] = outputRegister_1i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100352] = outputRegister_1j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100353] = outputRegister_1k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100354] = outputRegister_1l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100355] = outputRegister_1m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100356] = outputRegister_1n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100357] = outputRegister_1o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 100358] = outputRegister_1p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112896] = outputRegister_1q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112897] = outputRegister_1r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112898] = outputRegister_1s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112899] = outputRegister_1t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112900] = outputRegister_1u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112901] = outputRegister_1v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 112902] = outputRegister_1w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125440] = outputRegister_1x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125441] = outputRegister_1y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125442] = outputRegister_1z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125443] = outputRegister_20;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125444] = outputRegister_21;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125445] = outputRegister_22;
      outputBufferPtr[outputHeightBlockIdx * 7 + 125446] = outputRegister_23;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137984] = outputRegister_24;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137985] = outputRegister_25;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137986] = outputRegister_26;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137987] = outputRegister_27;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137988] = outputRegister_28;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137989] = outputRegister_29;
      outputBufferPtr[outputHeightBlockIdx * 7 + 137990] = outputRegister_2a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 150528] = outputRegister_2b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 150529] = outputRegister_2c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 150530] = outputRegister_2d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 150531] = outputRegister_2e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 150532] = outputRegister_2f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 150533] = outputRegister_2g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 150534] = outputRegister_2h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 163072] = outputRegister_2i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 163073] = outputRegister_2j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 163074] = outputRegister_2k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 163075] = outputRegister_2l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 163076] = outputRegister_2m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 163077] = outputRegister_2n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 163078] = outputRegister_2o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 175616] = outputRegister_2p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 175617] = outputRegister_2q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 175618] = outputRegister_2r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 175619] = outputRegister_2s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 175620] = outputRegister_2t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 175621] = outputRegister_2u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 175622] = outputRegister_2v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 188160] = outputRegister_2w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 188161] = outputRegister_2x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 188162] = outputRegister_2y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 188163] = outputRegister_2z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 188164] = outputRegister_30;
      outputBufferPtr[outputHeightBlockIdx * 7 + 188165] = outputRegister_31;
      outputBufferPtr[outputHeightBlockIdx * 7 + 188166] = outputRegister_32;
      stm32_B.inputBufferIdx1_c += 224;
    }
  }
}

static void stm32_convolution(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias)
{
  static real32_T inputScratchpadBuffer[846400];
  static real32_T outputScratchpadBuffer[150528];
  static boolean_T bufferInitialized;
  real32_T *elemRefOutputBufferVar;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, 3385600U);
    bufferInitialized = true;
  }

  memset(&outputScratchpadBuffer[0], 0, 602112U);
  for (stm32_B.bufferChannelMiniblockIdx_c = 1;
       stm32_B.bufferChannelMiniblockIdx_c < 2;
       stm32_B.bufferChannelMiniblockIdx_c++) {
    for (stm32_B.fusedInputWidthAndHeightIdx_m = 0;
         stm32_B.fusedInputWidthAndHeightIdx_m < 50176;
         stm32_B.fusedInputWidthAndHeightIdx_m++) {
      stm32_B.inputWidthIdx_m = div_nde_s32_floor
        (stm32_B.fusedInputWidthAndHeightIdx_m, 224);
      stm32_B.inputChannelMiniblockBaseIdx_j =
        stm32_B.fusedInputWidthAndHeightIdx_m % 224 + stm32_B.inputWidthIdx_m *
        224;
      stm32_B.inputScratchpadBufferBaseIdx_h =
        (((stm32_B.fusedInputWidthAndHeightIdx_m % 224) << 4) +
         stm32_B.inputWidthIdx_m * 3680) + 11088;
      for (stm32_B.inputWidthIdx_m = 1; stm32_B.inputWidthIdx_m < 4;
           stm32_B.inputWidthIdx_m++) {
        inputScratchpadBuffer[(stm32_B.inputScratchpadBufferBaseIdx_h +
          stm32_B.inputWidthIdx_m) - 1] = inputTensor[(stm32_B.inputWidthIdx_m -
          1) * 50176 + stm32_B.inputChannelMiniblockBaseIdx_j];
      }
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_c = 0;
       stm32_B.bufferChannelMiniblockIdx_c < 112;
       stm32_B.bufferChannelMiniblockIdx_c++) {
    stm32_B.fusedInputWidthAndHeightIdx_m = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_c, 112);
    stm32_B.inputWidthIdx_m = stm32_B.fusedInputWidthAndHeightIdx_m * 12544;
    outputChannelTailCase = (stm32_B.fusedInputWidthAndHeightIdx_m == 0);
    stm32_B.inputChannelMiniblockBaseIdx_j = stm32_B.bufferChannelMiniblockIdx_c
      % 112 * 112 + stm32_B.fusedInputWidthAndHeightIdx_m * 200704;
    stm32_B.inputScratchpadBufferBaseIdx_h = stm32_B.bufferChannelMiniblockIdx_c
      % 112 * 7360;
    for (stm32_B.fusedInputWidthAndHeightIdx_m = 1;
         stm32_B.fusedInputWidthAndHeightIdx_m < 2;
         stm32_B.fusedInputWidthAndHeightIdx_m++) {
      stm32_convolutionKernel
        (&inputScratchpadBuffer[stm32_B.inputScratchpadBufferBaseIdx_h],
         &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_j],
         &weights[stm32_B.inputWidthIdx_m], outputChannelTailCase);
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_c = 0;
       stm32_B.bufferChannelMiniblockIdx_c < 150528;
       stm32_B.bufferChannelMiniblockIdx_c++) {
    stm32_B.fusedInputWidthAndHeightIdx_m = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_c, 12544);
    stm32_B.biasRegister_m = bias[stm32_B.fusedInputWidthAndHeightIdx_m];
    stm32_B.inputChannelMiniblockBaseIdx_j = stm32_B.bufferChannelMiniblockIdx_c
      % 12544;
    stm32_B.inputWidthIdx_m = stm32_B.fusedInputWidthAndHeightIdx_m * 12544 +
      stm32_B.inputChannelMiniblockBaseIdx_j;
    stm32_B.inputChannelMiniblockBaseIdx_j +=
      stm32_B.fusedInputWidthAndHeightIdx_m * 12544;
    elemRefOutputBufferVar =
      &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_j];
    stm32_B.biasRegister_m += *elemRefOutputBufferVar;
    if (stm32_B.biasRegister_m >= 0.0F) {
      *elemRefOutputBufferVar = stm32_B.biasRegister_m;
    } else {
      *elemRefOutputBufferVar = 0.0F;
    }

    for (stm32_B.fusedInputWidthAndHeightIdx_m = 1;
         stm32_B.fusedInputWidthAndHeightIdx_m < 2;
         stm32_B.fusedInputWidthAndHeightIdx_m++) {
      outputTensor[stm32_B.inputWidthIdx_m] =
        outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_j];
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void s_conv2dDirectOptimizedColMajor(const real32_T X[150528], real32_T
  Z[150528])
{
  static const real32_T b[9408] = { 0.00584277F, -0.0932676047F, 0.0355632976F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0123470332F, -0.0965776816F, 0.0321067423F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0537502356F,
    -0.0667273328F, 0.0534068272F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0855223835F, -0.0470609777F,
    0.0681623518F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.113040075F, -0.0264144745F, 0.0806519911F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.141683698F, 0.00389121426F, 0.0935546532F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.161548451F, 0.0260615684F,
    0.100493155F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.00525316689F, -0.108454078F, 0.0373690091F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00859105F, -0.12646693F, 0.0251152497F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0232136827F, -0.108613752F,
    0.0362079106F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0544856042F, -0.0890568569F, 0.0454109348F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0756521F,
    -0.0728902668F, 0.0510269329F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.109449551F, -0.0385726355F,
    0.0679418519F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.136427164F, -0.00552264F, 0.0822294727F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00387373962F, -0.107909456F, 0.0447147079F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.000778864953F, -0.130226F,
    0.0273094699F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0173416249F, -0.127776444F, 0.0252596755F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0318529867F, -0.124143079F, 0.0191557035F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0436717F, -0.1154036F,
    0.0159760956F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0624451227F, -0.0942876264F, 0.0215489119F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.095013015F, -0.054200843F, 0.0432763547F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0228529889F, -0.101083912F,
    0.052796077F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0183721054F, -0.12558566F, 0.0299505591F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0200465973F, -0.139361665F, 0.0112293316F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0221825894F, -0.143003657F,
    -0.00192773843F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.024246702F, -0.138361141F, -0.0111796707F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0335267931F, -0.123866394F, -0.0105357105F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0638049F, -0.0852340609F,
    0.0107390331F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0401929654F, -0.0853808597F, 0.0582555756F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0350390077F, -0.112929016F, 0.0286032837F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0289031342F, -0.128757432F,
    0.00863084197F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.024896415F, -0.132905915F, -0.00305536645F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0187928416F, -0.132202744F, -0.014507249F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0246779714F, -0.119083218F,
    -0.0177530926F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0535669252F, -0.0847458392F, -3.92051588E-5F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0357565917F, -0.0807437673F, 0.0451865718F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0313310064F, -0.102981612F,
    0.0183947F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0282451734F, -0.110912472F, 0.00587712135F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0161806047F,
    -0.119508266F, -0.0113490354F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00588156516F, -0.122293055F,
    -0.0273929238F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0333278365F, -0.0899120718F, -0.0122346617F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0662202612F, -0.0530124679F, 0.0117607638F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0298689455F,
    -0.0627558157F, 0.0429908596F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0323589742F, -0.0723513886F,
    0.028384015F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0266498271F, -0.0818722844F, 0.0116075631F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0208979491F, -0.0844813287F, -0.00102224853F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0365641266F,
    -0.0652027726F, 0.00560170878F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.074849546F, -0.025886F, 0.0273264926F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.100830697F, -9.69148459E-5F, 0.0412950255F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0556939617F,
    -0.0181698967F, -0.0069039925F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0612589233F, -0.023246251F,
    -0.010113067F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0413992591F, -0.00147911021F, 0.0132201472F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0238559563F, 0.0192814395F, 0.0313401F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00524023036F,
    0.0370010026F, 0.0537073053F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0051273494F, 0.0399799533F, 0.0414625965F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -4.52069726E-5F, 0.037232656F, 0.0389978066F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0618541054F,
    -0.026590094F, -0.0159649067F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0638376474F, -0.0273156706F,
    -0.0173840728F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0392583236F, -0.000828258F, 0.0118397456F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0212519858F, 0.0211882573F, 0.0296995398F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00702582439F,
    0.0347617306F, 0.0469931476F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00325233606F, 0.0415757746F, 0.0566562898F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00268116035F, 0.0363592729F, 0.0342444368F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0523045771F,
    -0.0195780452F, -0.0172072984F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0522399768F, -0.0189969353F,
    -0.018626634F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0335367881F, 0.00149752654F, 0.000592199038F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0212554112F, 0.0156669449F, 0.01606673F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0146919247F,
    0.0226134304F, 0.0212199315F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.000577066792F, 0.0328067429F, 0.0409171395F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.000534017F, 0.0326600857F, 0.0321209468F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0472387299F,
    -0.0189961903F, -0.0286903195F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0488146096F, -0.0215329397F,
    -0.0362319F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0305455942F, -0.00187382381F, -0.0218814239F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0174599122F, 0.0111329081F, -0.00491127651F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0140487906F,
    0.0139227584F, -0.00172629114F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00516903866F, 0.0214366913F,
    0.00752068264F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00151147647F, 0.0283485074F, 0.0129379388F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0445101559F, -0.0182855111F, -0.0354153924F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0540654F, -0.0294200983F,
    -0.0533611439F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0359550379F, -0.011423381F, -0.0393555351F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0212734491F, 0.00382446195F, -0.0233361125F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0144499242F,
    0.00970432442F, -0.0150906891F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0083390912F, 0.0160112809F,
    -0.00997996517F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.00518095F, 0.02006579F, -0.0045383079F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00626828149F, 0.0230110791F, -0.00990029611F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0202384032F,
    0.00707047293F, -0.0320467614F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0068605491F, 0.0204322208F,
    -0.0258647054F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0137942126F, 0.040981818F, -0.00558975246F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0252047852F, 0.0516360477F, 0.00700748758F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0248355921F, 0.0507820696F,
    0.00766401552F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0131902294F, 0.039298404F, 0.00142515881F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0276090018F, 0.0666440055F, 0.0198830646F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0181189887F, 0.0565383956F,
    0.00414299034F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0291230027F, 0.0665987805F, 0.00934135634F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0513541922F, 0.0858694538F, 0.032381542F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0599845648F, 0.093491964F,
    0.0428906865F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0518445075F, 0.0827859789F, 0.0375416093F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0287605822F, 0.0576315336F, 0.0165476296F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.08408162F, -0.074834615F,
    -0.0565787889F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0850695744F, -0.0767210051F, -0.0675447136F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0467441082F, -0.0416450873F, -0.0352812298F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00336136296F,
    -0.00891411863F, 0.00459933234F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00465018908F, -0.00686197309F,
    0.0173297916F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0208451468F, -0.0322606824F, 0.0152372979F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.031967219F, -0.0517414585F, 0.00717671774F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0679037273F,
    -0.0501826778F, -0.0448728614F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0736940801F, -0.0460312478F,
    -0.0568318553F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0333930925F, -0.00316826813F, -0.0199396312F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.014416025F, 0.031954769F, 0.0229521859F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0130346082F, 0.0191382635F,
    0.0291676279F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0393760838F, -0.0345882736F, 0.0113358432F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0616168045F, -0.0677175298F, -0.00408759341F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0327605978F,
    -0.00189271406F, -0.0227659792F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0182109755F, 0.0214341134F,
    -0.00982783269F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0490185283F, 0.0772983953F, 0.0357018746F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0901252255F, 0.104776353F, 0.0619885586F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.029967593F, 0.0491124764F,
    0.0297609176F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0637516677F, -0.0363462754F, -0.0108239418F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0763265F, -0.0625259057F, -0.0159910358F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0125998138F,
    0.0317288376F, -0.0166203F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.05379555F, 0.0956755504F, 0.0390801951F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.150074109F, 0.170702636F, 0.10063F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.148382023F, 0.162564427F,
    0.0949580297F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0100849904F, 0.0434268974F, -0.00351311895F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0903692916F, -0.0453721806F, -0.0523558632F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0904362798F,
    -0.0618316457F, -0.0412852354F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0286589526F, 0.0244386345F,
    -0.0301475059F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0368253551F, 0.0925922841F, 0.0260255709F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.100272074F, 0.142148793F, 0.0665662214F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0561322868F, 0.094880864F,
    0.0288534258F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.037307892F, 0.0105002057F, -0.0447992161F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0928858519F, -0.0469742343F, -0.0677946135F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0798439831F,
    -0.0507342108F, -0.0435319468F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0611421727F, -0.00902018696F,
    -0.0572205186F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0267253574F, 0.0299567431F, -0.031003464F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00118839182F, 0.0543341488F, -0.0127689876F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0109600984F,
    0.0345176309F, -0.0208508074F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0318958201F, 0.00821805932F,
    -0.041840367F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.042975992F, -0.00769776292F, -0.0257992987F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0355116315F, -0.0123321954F, -0.0165532269F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0645364374F,
    -0.0176804271F, -0.0606293604F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.045696605F, 0.00198129425F,
    -0.051866211F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0160124097F, 0.0257851556F, -0.0281486511F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0113023063F, 0.0232916195F, -0.0257680658F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0120974742F, 0.018533567F,
    -0.0308113154F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0192407966F, 0.00855024904F, -0.0144000864F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0136395525F, 0.00829219259F, -0.00731926598F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0662689283F,
    -0.00471066171F, 0.0834089294F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0631225556F, -0.0182218123F,
    0.0695229694F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0585103929F, -0.0352218449F, 0.0488341F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0611749962F, -0.0461718217F, 0.0322974399F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0734012648F,
    -0.0411004797F, 0.0267095789F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.11106842F, -0.0106028132F,
    0.0362187177F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.118471153F, -0.0027280068F, 0.0374311022F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0238180049F, -0.0326862596F, 0.0560228787F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0263659768F, -0.038928777F,
    0.0497847497F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0319859385F, -0.047928758F, 0.041602686F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0400102213F, -0.0571249053F, 0.0326713584F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0566811711F,
    -0.0518373549F, 0.0303377882F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0922634155F, -0.0233800728F,
    0.0366275124F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.10024213F, -0.0151397744F, 0.0296365954F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00111043022F, -0.0475972705F, 0.0353369564F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00331419613F,
    -0.0479357727F, 0.0321420357F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0219039768F, -0.0404970981F,
    0.0385722667F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0344633311F, -0.0483474024F, 0.035652861F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0461550467F, -0.0525192F, 0.0308900699F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0828236267F, -0.028375648F,
    0.0393268429F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0932474583F, -0.0166994911F, 0.0354796648F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0466137268F, -0.0672294348F, 0.00667477632F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0383082218F,
    -0.0672544837F, -0.00129393244F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00831979141F, -0.0469894148F,
    0.0148501387F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0102130715F, -0.0479192287F, 0.0203551427F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0206108037F, -0.0579346418F, 0.0188516174F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0609209873F,
    -0.0351220891F, 0.0355125144F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.074066855F, -0.0205726903F,
    0.0403298773F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0680476502F, -0.0692805052F, -0.016083112F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.070848614F, -0.0795145333F, -0.0390635505F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0319623537F,
    -0.0512489043F, -0.0164331868F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00219325931F, -0.0361367092F,
    0.0048850826F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0227337629F, -0.0372008644F, 0.014131749F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0631288067F, -0.0159044303F, 0.0354001969F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0735568702F,
    -0.00527431257F, 0.045419F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0831241608F, -0.0673183575F, -0.0291386861F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0959345326F, -0.0863919929F, -0.0589023903F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0590463132F,
    -0.0579011627F, -0.03807538F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0178242791F, -0.0351597108F, -0.0120625701F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0075777797F, -0.0303513259F, -0.000384025101F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0461897887F,
    -0.0105706248F, 0.0213300083F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0589548051F, -0.000392362213F,
    0.0386056229F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0795905963F, -0.0501848757F, -0.00824955665F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0897696316F, -0.0662573F, -0.0310737F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0612565503F, -0.0457809381F,
    -0.0195008852F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0288139153F, -0.0273342412F, -0.00270068878F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0046694437F, -0.0194250271F, 0.00655816123F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0297106393F,
    -0.00311040017F, 0.0227840506F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0406860411F, 0.00112780381F,
    0.0379183628F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.00889110379F, 0.000589509436F, 0.0195138268F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0100622904F, -0.00162105937F, 0.016527554F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00914328F,
    -0.00292643695F, 0.0166735612F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0114628403F, -0.00622944348F,
    0.0141195217F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0103759272F, -0.00696605397F, 0.0157598332F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00662769F, -0.00528849F, 0.0193000827F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.000944310508F,
    -0.0013751951F, 0.0250697304F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0147347581F, -0.000773027074F,
    0.0166790616F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0156952422F, -0.00215747743F, 0.0138900848F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0148773184F, -0.00353224087F, 0.014301694F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0146749457F,
    -0.00587734068F, 0.0148696778F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0128796594F, -0.00695072114F,
    0.017704336F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.00908383448F, -0.00548829325F, 0.020719707F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00493883109F, -0.00301105739F, 0.0242593102F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0223133247F,
    -0.00350592588F, 0.0108269984F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0223922301F, -0.0036606777F,
    0.0114838155F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0209546667F, -0.00415318599F, 0.0136375269F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0182448868F, -0.00460201F, 0.0176116303F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.01310807F,
    -0.00286821369F, 0.0228000972F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00784860644F, -0.000650137081F,
    0.0257714018F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.00535294879F, 0.000490305247F, 0.0253138877F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0288876835F, -0.0058592516F, 0.0120147588F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0260649268F,
    -0.00291795423F, 0.0177519713F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.021826094F, -0.000453410234F,
    0.0235930309F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0185032971F, -0.000107527878F, 0.0265778806F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0118348086F, 0.00220601913F, 0.0333877914F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00630554045F,
    0.00416724524F, 0.0360392705F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00578501634F, 0.0034867411F,
    0.0298728496F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0320118442F, -0.00630943337F, 0.0154451486F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0233233888F, 0.00139842322F, 0.0308894124F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0181613956F,
    0.00478003686F, 0.038334664F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0169472508F, 0.00319069228F, 0.0345524624F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0131428903F, 0.00303453067F, 0.0377287492F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00974780601F,
    0.00347894826F, 0.0388358049F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0107255327F, 0.00125531037F,
    0.0305911768F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0323176794F, -0.00584687199F, 0.0197250582F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0243335199F, 0.000754242F, 0.0348649696F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0198287927F,
    0.00349760847F, 0.0413603075F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0205516983F, 0.00035461993F,
    0.0355831645F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0192742962F, -0.0014399112F, 0.0373298489F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0183884762F, -0.00251812534F, 0.0352564938F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0204241071F,
    -0.00500894245F, 0.0251351725F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.032054659F, -0.00489916839F,
    0.0213202592F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0270437691F, -0.00130298338F, 0.0317202881F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0226629917F, 0.00061922922F, 0.0400573388F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0237764735F,
    -0.00256950129F, 0.0374171361F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0248674471F, -0.00603189971F,
    0.0382690243F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0250107907F, -0.0073384922F, 0.0362759233F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0265707672F, -0.00928478409F, 0.027954299F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0430673771F, -0.00575419F,
    0.070188269F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0458909161F, -0.00492975954F, 0.0835668072F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.043604739F, -0.0100795412F, 0.0903265476F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.040423952F, -0.0174992196F,
    0.0925389379F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0379853919F, -0.0239102598F, 0.0881219208F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0349841304F, -0.0291885324F, 0.076242961F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0383046828F,
    -0.0320281759F, 0.0710879043F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0418332107F, -0.00101512554F,
    0.075758107F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.037055F, -0.0042249416F, 0.0789016858F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0301465634F,
    -0.0126880463F, 0.0809570327F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0244050846F, -0.0230036713F,
    0.0812972188F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0204702988F, -0.0322138183F, 0.0776857287F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.018657485F, -0.0387401804F, 0.0699104071F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0191474762F,
    -0.0428995714F, 0.0587657318F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0336582474F, -0.00448117778F,
    0.0650772601F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0307015218F, -0.00797369052F, 0.0689444244F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0244533066F, -0.0177136026F, 0.0721257F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0121130617F,
    -0.0308144018F, 0.0572646633F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00106392254F, -0.0429574F,
    0.0348584726F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.00346969161F, -0.0488894F, 0.0307743046F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00421199F, -0.0487402454F, 0.0338708684F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0252132546F,
    -0.00931377802F, 0.0469340533F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0225957222F, -0.0124936439F,
    0.0459044911F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0168684293F, -0.0215161163F, 0.041037403F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0133112986F, -0.0295550209F, 0.0424282439F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0105693759F, -0.0346946F,
    0.0383461192F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00882909633F, -0.0384813249F, 0.0348918475F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0124739809F, -0.038407743F, 0.0339328796F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0151154613F,
    -0.0169694293F, 0.0300921F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.014634178F, -0.0178450756F, 0.027333742F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0116349747F, -0.0229000766F, 0.0189527739F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0100970985F,
    -0.0271046031F, 0.0143061941F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0162819587F, -0.0254487488F,
    0.0242715273F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0204780232F, -0.024076879F, 0.0310380552F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0234104693F, -0.0252583604F, 0.0327885337F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.000107517895F,
    -0.0292184334F, 0.00841050316F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.000461626158F, -0.0288511142F,
    0.00479108F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.000275578786F, -0.0287673082F, 0.000322072039F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0024978898F, -0.0292617735F, -0.00144260156F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0100341765F,
    -0.0257062167F, 0.0102067795F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0186027773F, -0.020935189F,
    0.0190927889F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0230530556F, -0.0206117444F, 0.0214004181F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0084696617F, -0.0334739685F, 0.00129758089F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0073181889F,
    -0.0312678814F, -0.00124530355F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00646912027F, -0.0298016109F,
    -0.00669812F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.00436532591F, -0.0295460336F, -0.00758478744F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0024625822F, -0.0260930583F, -0.000557518564F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0162570886F,
    -0.0184971113F, 0.0150557337F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0248259492F, -0.0152955204F,
    0.0214184F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.00448872382F, -0.0129199009F, -0.038808424F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00200037402F,
    -0.0126216793F, -0.0431641676F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.000730583037F, -0.0112079484F,
    -0.0432815477F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00161184638F, -0.00742702F, -0.0405944027F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00215654704F, -0.00373807969F, -0.03666218F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00262379507F,
    -0.00255640573F, -0.0348525457F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00847742427F, 0.00188036181F,
    -0.0290663801F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00987919606F, -0.0153485276F, -0.0338954106F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00892611407F, -0.0141844498F, -0.0350488313F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0081684906F,
    -0.0140896821F, -0.0338028893F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0103959832F, -0.0117057022F,
    -0.0279746968F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0136605F, -0.00599724567F, -0.0188298244F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0155469254F, -0.00122863264F, -0.0153201735F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0228950977F,
    0.00672018481F, -0.00922043808F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.013954239F, -0.0205054767F,
    -0.0309250429F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0150346095F, -0.0191135705F, -0.028463671F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0196651388F, -0.01556536F, -0.0219569616F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0263882615F, -0.010642455F,
    -0.0129385032F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0331525914F, -0.00394840306F, -7.37683513E-5F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0343548469F, 0.000541504123F, 0.00082551362F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0375708863F,
    0.00658284593F, 0.000452104141F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0173481386F, -0.0322224088F,
    -0.023280751F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0218337346F, -0.03055254F, -0.0163272303F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.030160252F, -0.0235777553F, -0.00744106388F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0384090729F,
    -0.0163412392F, 0.00158437248F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0439258553F, -0.0109876581F,
    0.0105357571F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0464780405F, -0.00720855268F, 0.00775770657F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0501515605F, 0.000362053514F, 0.00227694586F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0163599364F, -0.044597175F,
    -0.00312776212F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0214523859F, -0.0451390222F, 0.00772499247F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0277174488F, -0.0413926132F, 0.0161763504F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0348864309F, -0.03315809F,
    0.0216362905F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0405233428F, -0.0257750303F, 0.0264342092F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0447770581F, -0.0203771964F, 0.0202341173F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0502369553F, -0.010360253F,
    0.0115420688F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0185589325F, -0.0534839667F, 0.0234994795F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0150728682F, -0.0634915754F, 0.0306918379F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0166228227F,
    -0.0654986426F, 0.0385341644F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0235163514F, -0.0588102713F,
    0.0426040888F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0299591161F, -0.0496974811F, 0.0443672203F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0348191522F, -0.0411124639F, 0.0334067941F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0447675586F,
    -0.0248556342F, 0.0257168673F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0240416769F, -0.0553388372F,
    0.0388545357F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0193679966F, -0.0688435957F, 0.0486216731F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0210949F,
    -0.0717923194F, 0.0574509278F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0259361956F, -0.0687069595F,
    0.0586708747F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0301536117F, -0.0622191802F, 0.0568046533F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0369588807F, -0.0516930893F, 0.0464777462F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.046977248F, -0.0334788561F,
    0.0383226722F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0531110317F, 0.0214394685F, 0.117868759F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0437503308F, 0.00442353636F, 0.112584069F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0456279442F, -0.013863991F,
    0.110226825F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0520836301F, -0.0302762743F, 0.0988608152F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0769717395F, -0.0231683254F, 0.103835218F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0767104104F,
    -0.0174527839F, 0.111055709F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0782509446F, -0.0143415052F, 0.111677773F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0216403622F, 0.0102863954F, 0.094491072F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00417694263F,
    -0.0116335787F, 0.0796183199F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00585053395F, -0.0287660751F,
    0.0809848234F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00728944456F, -0.0477435328F, 0.0709190741F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0123418132F, -0.0550821051F, 0.0606566146F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0165181514F,
    -0.0525846519F, 0.0671299174F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0328679271F, -0.0380232073F,
    0.0789130405F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0101224566F, 0.00713531254F, 0.0758408606F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00831923913F, -0.0115664452F, 0.0530315749F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.014029243F,
    -0.0271905567F, 0.0489811227F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.011344023F, -0.0410666764F,
    0.0485207587F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0109214801F, -0.0487123057F, 0.0383995026F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00220754487F, -0.0464826375F, 0.0491617881F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0151375411F, -0.031037163F,
    0.0526548252F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0349906385F, 0.0430763476F, 0.0746929F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0158133879F,
    0.0243873037F, 0.044184F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0031611633F, 0.00429939851F, 0.0222389102F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0020889889F, -0.0135882171F, 0.0184847545F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00304478663F,
    -0.0126010096F, 0.0261964165F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00673290575F, -0.0109169874F,
    0.0433767363F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0296352413F, 0.00508451F, 0.0560522303F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0512821898F, 0.0760794804F, 0.075176321F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0376367681F, 0.0613007545F,
    0.0453762487F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0153863281F, 0.0327026919F, 0.0137409754F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.000532466162F, 0.00724128122F, 0.000161780976F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00502197724F,
    0.00802337099F, 0.0122415479F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.010484389F, 0.0117334276F,
    0.034487959F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0330489911F, 0.0269413F, 0.0513335913F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0774126276F,
    0.110717043F, 0.0745999292F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0575054921F, 0.0915846527F, 0.0408460125F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0217334963F, 0.0518551134F, -0.00100750651F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00882257521F,
    0.0143952882F, -0.0305183921F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00431262469F, 0.012042949F,
    -0.0208003279F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0031587535F, 0.0107057458F, -0.00859581213F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0272657294F, 0.0287281312F, 0.0226936433F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0993367508F, 0.138926849F,
    0.0766095743F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.078147091F, 0.121359862F, 0.0478306189F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0353267267F, 0.0750463903F, -0.00177458837F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.000332660304F,
    0.031621296F, -0.0416644439F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00401322683F, 0.0273580924F, -0.0392498709F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00322628906F, 0.0239859801F, -0.027248716F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0222441647F, 0.0319606587F,
    -0.000887401344F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0615856089F, 0.0152726294F, 0.0479842238F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0478664339F, 0.0325267911F, 0.0110575296F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0624086373F,
    0.0507741235F, -0.0121864453F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0658444092F, 0.0857031494F,
    0.00321921753F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0765117109F, 0.0935826F, -0.0199485831F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0804785788F, 0.0937654749F, -0.00720997388F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0857356936F,
    0.0701880231F, 0.0159329772F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.037738394F, -2.08614438E-6F, 0.0310376883F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0161988065F, 0.0173481163F, 0.00616752636F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0224187635F,
    0.0410745814F, -0.0211794581F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0435059331F, 0.0680053234F,
    -0.0189048313F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0501652472F, 0.0882561505F, -0.0417685658F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0437540263F, 0.0920437276F, -0.0388083532F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0431726165F,
    0.0711306557F, 0.00225636293F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0129326079F, -0.021448696F,
    0.0234406479F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.000199488582F, -0.0118659055F, 0.0141588766F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.000914558885F, 0.00910427701F, -0.0104562463F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00896500051F,
    0.0383436233F, -0.01283109F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00890919846F, 0.0578869395F, -0.0162047464F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00408829236F, 0.0705487356F, -0.0198329724F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00991857797F,
    0.0573302656F, -0.00512319105F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.03632956F, -0.0574927106F,
    0.0475856289F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0218016673F, -0.0703261793F, 0.0410095602F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0186838955F, -0.0550673679F, 0.0277628452F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0133688711F,
    -0.0255490206F, 0.0213398449F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0198448952F, -0.0012765195F,
    0.0118990624F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0107798129F, 0.0103758099F, -0.0132130841F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0104816733F, 0.00622844184F, -0.00896999706F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0322962329F,
    -0.122729383F, 0.106790602F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0263825115F, -0.141558424F, 0.105395973F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0358144902F, -0.122282848F, 0.1111058F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0270467568F, -0.0948691592F,
    0.109405115F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0252610594F, -0.0684120506F, 0.0708417743F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0250448734F, -0.0366402157F, 0.0581821129F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0159447622F,
    -0.0144170951F, 0.0744369179F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0385896415F, -0.181666568F,
    0.144319445F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0599303469F, -0.205973551F, 0.154248759F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0385257863F, -0.223137453F, 0.133060426F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00309795281F,
    -0.191084012F, 0.136149734F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0279026628F, -0.125980705F, 0.124547079F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00929452851F, -0.094487384F, 0.0765403137F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.000512002094F,
    -0.0623578466F, 0.0860221162F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0727225095F, -0.203432724F,
    0.175250098F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0689318553F, -0.241985962F, 0.189064503F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0664972588F, -0.230686098F, 0.210156679F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0345949084F, -0.201131791F,
    0.213379696F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0274906382F, -0.154369786F, 0.172102481F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0103168506F, -0.120063446F, 0.110211574F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0184563659F, -0.0645775F,
    0.135447711F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0271999612F, -0.0215623826F, -0.00962453522F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0169807598F, -0.0245430246F, -0.013774367F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01234362F, -0.0220340565F,
    -0.0182068646F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0118090473F, -0.0150203537F, -0.018422557F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00685935F, -0.0135329822F, -0.0236265603F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00734265F, -0.00910791289F,
    -0.0305537F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0129721062F, -0.00322119775F, -0.0431201234F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0360372961F, -0.030149743F, -0.000800499402F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0230158065F,
    -0.0325927474F, -0.00161103206F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0177907012F, -0.0303891022F,
    -0.00317595596F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0152064366F, -0.0253947042F, -0.00563334953F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00960416719F, -0.0229468774F, -0.0106999641F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0113873035F,
    -0.0152602522F, -0.0149966842F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0185085908F, -0.00647653546F,
    -0.0262866206F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0516175628F, -0.0312430449F, 0.00663718814F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0397276208F, -0.033053644F, 0.00983276684F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0364613608F,
    -0.0295861121F, 0.0128678968F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0360181481F, -0.0245170072F,
    0.0132555654F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0281441174F, -0.0253649745F, 0.00726002408F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0251217503F, -0.0207421388F, 0.000623338216F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0284330249F,
    -0.0127664488F, -0.0132036349F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0593788624F, -0.0414696597F,
    0.00501422584F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0497503504F, -0.0427913144F, 0.00822341628F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0487588F,
    -0.0385889262F, 0.0153134121F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0485731F, -0.0345299095F,
    0.0155628938F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0408622622F, -0.035668321F, 0.0116468342F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0389094874F, -0.0311260931F, 0.00586628588F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0418127626F,
    -0.0212958511F, -0.00655328948F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0603046529F, -0.0541832894F,
    0.00769929448F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0510244779F, -0.0574621297F, 0.00687007839F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.046912007F, -0.057532642F, 0.00949566811F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.051311966F, -0.0508819297F,
    0.0124446768F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0468842313F, -0.0485464334F, 0.0111166239F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0456996709F, -0.0436188057F, 0.00610719575F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0504820347F,
    -0.0315551981F, -0.00282214559F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0475600511F, -0.0711380616F,
    0.0160421375F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0378867909F, -0.0776754F, 0.0122214472F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0376230702F, -0.0763838515F, 0.0180171523F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0413335115F,
    -0.0707705244F, 0.0185942389F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0415967181F, -0.0642968118F,
    0.0161897335F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.043351125F, -0.0562515259F, 0.0103665795F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0485714152F, -0.0426445343F, 0.00141183578F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0476094522F,
    -0.0699905455F, 0.0383721776F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.037803404F, -0.0785826F, 0.0318055376F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0363390669F, -0.0790432096F, 0.0322443731F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0384747535F,
    -0.0750702322F, 0.028483713F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.039990548F, -0.0688376054F, 0.0223459788F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0455531888F, -0.057042066F, 0.018095322F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0525026F, -0.0404150523F,
    0.0118969185F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00706989318F, -0.00860071182F, -0.0139946667F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00330450456F, -0.00650462694F, -0.0160755571F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00668052305F,
    -0.0010957754F, -0.0109182568F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00757438457F, 0.00371121988F,
    -0.00822938606F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.00846216269F, 0.00799368508F, -0.00662408F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00748124532F, 0.0103796339F, -0.00496002892F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0040130429F,
    0.0177563149F, -0.00407903874F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0254734401F, -0.0255495012F,
    -0.0154311247F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.018809231F, -0.0203851666F, -0.00914675649F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.010597459F, -0.0176929682F, -0.0100248884F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0107750371F,
    -0.0139937326F, -0.00421107933F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0112173352F, -0.00879288744F,
    0.00132261391F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0140842749F, -0.00459860219F, 0.0028290248F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0174762327F, 0.00528342556F, 0.00683251768F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0446303152F,
    -0.0392090753F, -0.00359750539F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0339673683F, -0.0411614142F,
    -0.000180777701F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0282866806F, -0.0350997671F, 0.00475305F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0257043708F, -0.0289822798F, 0.00670649763F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.032230664F, -0.0216122735F,
    0.0102835605F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0303127039F, -0.0208675191F, 0.00383530394F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0325252712F, -0.00842928234F, 0.00299167703F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0627961159F,
    -0.0630591586F, 0.00413167477F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0521015F, -0.0773579851F,
    0.00814155489F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0485697053F, -0.0723891631F, 0.0220929049F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0378384367F, -0.0673349127F, 0.017454749F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0415659621F,
    -0.0488319434F, 0.0216370188F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0430824F, -0.0375071876F,
    0.0100586042F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0533376075F, -0.0193819627F, 0.00330603146F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0682053342F, -0.0927052423F, 0.0430694F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0609957278F, -0.116565943F,
    0.0382595062F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0791401714F, -0.116814539F, 0.043615941F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0835376829F, -0.106220938F, 0.0405193344F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0650533289F,
    -0.0803820714F, 0.054079026F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0539022F, -0.063382633F, 0.0408881716F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0609486327F, -0.0386404209F, 0.020458499F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0579145811F, -0.123344153F,
    0.0803756267F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0529142767F, -0.144001365F, 0.0888739154F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0952272117F, -0.153865814F, 0.061791081F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.102867886F, -0.151407048F,
    0.0260537751F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0656283125F, -0.113101736F, 0.0470282324F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0534679405F, -0.0907997042F, 0.0490733758F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0592688099F,
    -0.0597186051F, 0.0293591097F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.068393521F, -0.126383021F,
    0.101137571F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0562181324F, -0.152463526F, 0.103546239F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0740681812F, -0.151168406F, 0.0955449939F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0863972083F, -0.137052536F,
    0.0819389671F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0714031607F, -0.119579032F, 0.0731229112F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0674298853F, -0.0974774212F, 0.0578440242F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0805741847F,
    -0.0667018518F, 0.0375865139F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0778450221F, -0.0506693907F,
    0.029646052F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0564885065F, -0.0747792497F, 0.0263161305F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0356779546F, -0.0821961686F, 0.0465082452F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00095576921F,
    -0.117302611F, 0.0477227792F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0232828185F, -0.161950529F, 0.0452571623F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0847632438F, -0.215963125F, 0.0884132311F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0769716203F,
    -0.203692481F, 0.106174462F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0402016342F, -0.0778296068F, -0.0160858463F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0207774732F, -0.0963115245F, -0.0186091103F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.000838412729F,
    -0.0997619703F, 0.00884844176F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00954804F, -0.103104413F,
    0.0444852486F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, -0.0263300892F, -0.131468281F, 0.0553166233F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0615332797F, -0.179230362F, 0.111260645F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0455375537F,
    -0.159110129F, 0.141208604F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.046722915F, -0.068414852F, -0.0368416F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0327956565F, -0.0797818378F, -0.042749688F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0335293226F,
    -0.0584926605F, -0.00416187476F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0424012169F, -0.0428928696F,
    0.0490245074F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0295630507F, -0.049602516F, 0.0656938851F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0245246217F, -0.107991062F, 0.114512302F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0147317126F,
    -0.107096903F, 0.125616223F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0770900473F, -0.0387760028F, -0.0611783F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0656310171F, -0.051426392F, -0.0775533691F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0745296478F,
    -0.0317177661F, -0.0489101447F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0778602883F, -0.0146477968F,
    -0.00667416165F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0903819501F, -0.0017066088F, 0.0252207443F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0169359334F, -0.0548810177F, 0.0670416579F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0333942473F,
    -0.0508360676F, 0.0954257548F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0726838F, -0.038767077F,
    -0.0771201253F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0603589043F, -0.0610914044F, -0.103879377F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0667217895F, -0.0469030291F, -0.0978091508F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0678114444F,
    -0.0371342599F, -0.0579756312F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0829580501F, -0.024908185F,
    -0.0244637523F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0207017604F, -0.0575381033F, 0.0326535366F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.030610498F, -0.0490084849F, 0.0532916114F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0873608F, -0.00941834413F,
    -0.0873770565F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0618576519F, -0.0487876274F, -0.125733957F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0658786371F, -0.0435899086F, -0.118191205F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0718983412F,
    -0.0336467773F, -0.0811036378F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0925515F, -0.0140115283F,
    -0.0326561742F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0436410904F, -0.0436643139F, 0.0293676183F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0409409031F, -0.0442142785F, 0.0254372377F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.135524705F, 0.0497678891F,
    -0.0657352507F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0959631801F, 0.00189295446F, -0.0924196243F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0805126876F, -0.0124504641F, -0.097109668F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0754927322F, -0.014515603F,
    -0.0846302F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0869643241F, -0.00640110625F, -0.0524232909F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0402721353F, -0.0397264473F, 0.00879542623F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0318937786F, -0.052077733F,
    -0.0007076771F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F };

  static const real32_T c[12] = { -0.746836066F, 5.20534086F, 0.41934F,
    6.8670435F, 3.58874607F, -0.446030319F, -3.47687626F, -2.4647975F,
    -7.16816044F, -0.83232373F, -6.83254576F, -3.80249906F };

  stm32_convolution(&X[0], &Z[0], &b[0], &c[0]);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void stm32_MaxPooling2DLayer_predict(const real32_T X[150528], real32_T
  Z[37632])
{
  int32_T b_filterWidthIdx;
  int32_T inputWidthIdx;
  int32_T outChannelIdx;
  int32_T outHeightIdx;
  int32_T outWidthIdx;
  int32_T tmp;
  int32_T tmp_0;
  real32_T opValue;
  real32_T y;
  for (outChannelIdx = 0; outChannelIdx < 12; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 56; outWidthIdx++) {
      for (outHeightIdx = 0; outHeightIdx < 56; outHeightIdx++) {
        opValue = -3.402823466E+38F;
        tmp_0 = outHeightIdx << 1;
        tmp = outWidthIdx << 1;
        if ((tmp_0 + 4 <= 112) && (tmp + 4 <= 112)) {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = ((tmp + b_filterWidthIdx) * 112 + tmp_0) + 12544 *
              outChannelIdx;
            y = X[inputWidthIdx];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            y = X[inputWidthIdx + 1];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            y = X[inputWidthIdx + 2];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }
          }
        } else {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = tmp + b_filterWidthIdx;
            if (inputWidthIdx + 1 <= 112) {
              y = X[(112 * inputWidthIdx + tmp_0) + 12544 * outChannelIdx];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            if (inputWidthIdx + 1 <= 112) {
              y = X[(((outHeightIdx << 1) + 112 * inputWidthIdx) + 12544 *
                     outChannelIdx) + 1];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            if ((tmp_0 + 3 <= 112) && (inputWidthIdx + 1 <= 112)) {
              y = X[((112 * inputWidthIdx + tmp_0) + 12544 * outChannelIdx) + 2];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }
          }
        }

        Z[(outHeightIdx + 56 * outWidthIdx) + 3136 * outChannelIdx] = opValue;
      }
    }
  }
}

static void stm32_convolutionKernel_d(const real32_T *inputBufferPtr, real32_T
  *outputBufferPtr, const real32_T *weightsPtr, boolean_T outputChannelTailCase)
{
  int32_T inputBufferIdx1;
  int32_T inputChannelIdx;
  int32_T outputHeightBlockIdx;
  real32_T inputRegister;
  real32_T inputRegister_0;
  real32_T inputRegister_1;
  real32_T inputRegister_2;
  real32_T inputRegister_3;
  real32_T inputRegister_4;
  real32_T inputRegister_5;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_10;
  real32_T outputRegister_11;
  real32_T outputRegister_12;
  real32_T outputRegister_13;
  real32_T outputRegister_14;
  real32_T outputRegister_15;
  real32_T outputRegister_16;
  real32_T outputRegister_17;
  real32_T outputRegister_18;
  real32_T outputRegister_19;
  real32_T outputRegister_1a;
  real32_T outputRegister_1b;
  real32_T outputRegister_1c;
  real32_T outputRegister_1d;
  real32_T outputRegister_1e;
  real32_T outputRegister_1f;
  real32_T outputRegister_1g;
  real32_T outputRegister_1h;
  real32_T outputRegister_1i;
  real32_T outputRegister_1j;
  real32_T outputRegister_1k;
  real32_T outputRegister_1l;
  real32_T outputRegister_1m;
  real32_T outputRegister_1n;
  real32_T outputRegister_1o;
  real32_T outputRegister_1p;
  real32_T outputRegister_1q;
  real32_T outputRegister_1r;
  real32_T outputRegister_1s;
  real32_T outputRegister_1t;
  real32_T outputRegister_1u;
  real32_T outputRegister_1v;
  real32_T outputRegister_1w;
  real32_T outputRegister_1x;
  real32_T outputRegister_1y;
  real32_T outputRegister_1z;
  real32_T outputRegister_2;
  real32_T outputRegister_20;
  real32_T outputRegister_21;
  real32_T outputRegister_22;
  real32_T outputRegister_23;
  real32_T outputRegister_24;
  real32_T outputRegister_25;
  real32_T outputRegister_26;
  real32_T outputRegister_27;
  real32_T outputRegister_28;
  real32_T outputRegister_29;
  real32_T outputRegister_2a;
  real32_T outputRegister_2b;
  real32_T outputRegister_2c;
  real32_T outputRegister_2d;
  real32_T outputRegister_2e;
  real32_T outputRegister_2f;
  real32_T outputRegister_2g;
  real32_T outputRegister_2h;
  real32_T outputRegister_2i;
  real32_T outputRegister_2j;
  real32_T outputRegister_2k;
  real32_T outputRegister_2l;
  real32_T outputRegister_2m;
  real32_T outputRegister_2n;
  real32_T outputRegister_2o;
  real32_T outputRegister_2p;
  real32_T outputRegister_2q;
  real32_T outputRegister_2r;
  real32_T outputRegister_2s;
  real32_T outputRegister_2t;
  real32_T outputRegister_2u;
  real32_T outputRegister_2v;
  real32_T outputRegister_2w;
  real32_T outputRegister_2x;
  real32_T outputRegister_2y;
  real32_T outputRegister_2z;
  real32_T outputRegister_3;
  real32_T outputRegister_30;
  real32_T outputRegister_31;
  real32_T outputRegister_32;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  real32_T outputRegister_f;
  real32_T outputRegister_g;
  real32_T outputRegister_h;
  real32_T outputRegister_i;
  real32_T outputRegister_j;
  real32_T outputRegister_k;
  real32_T outputRegister_l;
  real32_T outputRegister_m;
  real32_T outputRegister_n;
  real32_T outputRegister_o;
  real32_T outputRegister_p;
  real32_T outputRegister_q;
  real32_T outputRegister_r;
  real32_T outputRegister_s;
  real32_T outputRegister_t;
  real32_T outputRegister_u;
  real32_T outputRegister_v;
  real32_T outputRegister_w;
  real32_T outputRegister_x;
  real32_T outputRegister_y;
  real32_T outputRegister_z;
  real32_T weightsRegister;
  if (outputChannelTailCase) {
    inputBufferIdx1 = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 8;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
        inputRegister = inputBufferPtr[inputBufferIdx1 + inputChannelIdx];
        inputRegister_0 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          16];
        inputRegister_1 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          32];
        inputRegister_2 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          48];
        inputRegister_3 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          64];
        inputRegister_4 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          80];
        inputRegister_5 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          96];
        weightsRegister = weightsPtr[inputChannelIdx];
        outputRegister += inputRegister * weightsRegister;
        outputRegister_0 += inputRegister_0 * weightsRegister;
        outputRegister_1 += inputRegister_1 * weightsRegister;
        outputRegister_2 += inputRegister_2 * weightsRegister;
        outputRegister_3 += inputRegister_3 * weightsRegister;
        outputRegister_4 += inputRegister_4 * weightsRegister;
        outputRegister_5 += inputRegister_5 * weightsRegister;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      inputBufferIdx1 += 112;
    }
  } else {
    inputBufferIdx1 = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 8;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 3136];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 3137];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 3138];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 3139];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 3140];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 3141];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 3142];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 6272];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 6273];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 6274];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 6275];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 6276];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 6277];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 6278];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 9408];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 9409];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 9410];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 9411];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 9412];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 9413];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 9414];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 12544];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 12545];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 12546];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 12547];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 12548];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 12549];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 12550];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 15680];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 15681];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 15682];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 15683];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 15684];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 15685];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 15686];
      outputRegister_15 = outputBufferPtr[outputHeightBlockIdx * 7 + 18816];
      outputRegister_16 = outputBufferPtr[outputHeightBlockIdx * 7 + 18817];
      outputRegister_17 = outputBufferPtr[outputHeightBlockIdx * 7 + 18818];
      outputRegister_18 = outputBufferPtr[outputHeightBlockIdx * 7 + 18819];
      outputRegister_19 = outputBufferPtr[outputHeightBlockIdx * 7 + 18820];
      outputRegister_1a = outputBufferPtr[outputHeightBlockIdx * 7 + 18821];
      outputRegister_1b = outputBufferPtr[outputHeightBlockIdx * 7 + 18822];
      outputRegister_1c = outputBufferPtr[outputHeightBlockIdx * 7 + 21952];
      outputRegister_1d = outputBufferPtr[outputHeightBlockIdx * 7 + 21953];
      outputRegister_1e = outputBufferPtr[outputHeightBlockIdx * 7 + 21954];
      outputRegister_1f = outputBufferPtr[outputHeightBlockIdx * 7 + 21955];
      outputRegister_1g = outputBufferPtr[outputHeightBlockIdx * 7 + 21956];
      outputRegister_1h = outputBufferPtr[outputHeightBlockIdx * 7 + 21957];
      outputRegister_1i = outputBufferPtr[outputHeightBlockIdx * 7 + 21958];
      outputRegister_1j = outputBufferPtr[outputHeightBlockIdx * 7 + 25088];
      outputRegister_1k = outputBufferPtr[outputHeightBlockIdx * 7 + 25089];
      outputRegister_1l = outputBufferPtr[outputHeightBlockIdx * 7 + 25090];
      outputRegister_1m = outputBufferPtr[outputHeightBlockIdx * 7 + 25091];
      outputRegister_1n = outputBufferPtr[outputHeightBlockIdx * 7 + 25092];
      outputRegister_1o = outputBufferPtr[outputHeightBlockIdx * 7 + 25093];
      outputRegister_1p = outputBufferPtr[outputHeightBlockIdx * 7 + 25094];
      outputRegister_1q = outputBufferPtr[outputHeightBlockIdx * 7 + 28224];
      outputRegister_1r = outputBufferPtr[outputHeightBlockIdx * 7 + 28225];
      outputRegister_1s = outputBufferPtr[outputHeightBlockIdx * 7 + 28226];
      outputRegister_1t = outputBufferPtr[outputHeightBlockIdx * 7 + 28227];
      outputRegister_1u = outputBufferPtr[outputHeightBlockIdx * 7 + 28228];
      outputRegister_1v = outputBufferPtr[outputHeightBlockIdx * 7 + 28229];
      outputRegister_1w = outputBufferPtr[outputHeightBlockIdx * 7 + 28230];
      outputRegister_1x = outputBufferPtr[outputHeightBlockIdx * 7 + 31360];
      outputRegister_1y = outputBufferPtr[outputHeightBlockIdx * 7 + 31361];
      outputRegister_1z = outputBufferPtr[outputHeightBlockIdx * 7 + 31362];
      outputRegister_20 = outputBufferPtr[outputHeightBlockIdx * 7 + 31363];
      outputRegister_21 = outputBufferPtr[outputHeightBlockIdx * 7 + 31364];
      outputRegister_22 = outputBufferPtr[outputHeightBlockIdx * 7 + 31365];
      outputRegister_23 = outputBufferPtr[outputHeightBlockIdx * 7 + 31366];
      outputRegister_24 = outputBufferPtr[outputHeightBlockIdx * 7 + 34496];
      outputRegister_25 = outputBufferPtr[outputHeightBlockIdx * 7 + 34497];
      outputRegister_26 = outputBufferPtr[outputHeightBlockIdx * 7 + 34498];
      outputRegister_27 = outputBufferPtr[outputHeightBlockIdx * 7 + 34499];
      outputRegister_28 = outputBufferPtr[outputHeightBlockIdx * 7 + 34500];
      outputRegister_29 = outputBufferPtr[outputHeightBlockIdx * 7 + 34501];
      outputRegister_2a = outputBufferPtr[outputHeightBlockIdx * 7 + 34502];
      outputRegister_2b = outputBufferPtr[outputHeightBlockIdx * 7 + 37632];
      outputRegister_2c = outputBufferPtr[outputHeightBlockIdx * 7 + 37633];
      outputRegister_2d = outputBufferPtr[outputHeightBlockIdx * 7 + 37634];
      outputRegister_2e = outputBufferPtr[outputHeightBlockIdx * 7 + 37635];
      outputRegister_2f = outputBufferPtr[outputHeightBlockIdx * 7 + 37636];
      outputRegister_2g = outputBufferPtr[outputHeightBlockIdx * 7 + 37637];
      outputRegister_2h = outputBufferPtr[outputHeightBlockIdx * 7 + 37638];
      outputRegister_2i = outputBufferPtr[outputHeightBlockIdx * 7 + 40768];
      outputRegister_2j = outputBufferPtr[outputHeightBlockIdx * 7 + 40769];
      outputRegister_2k = outputBufferPtr[outputHeightBlockIdx * 7 + 40770];
      outputRegister_2l = outputBufferPtr[outputHeightBlockIdx * 7 + 40771];
      outputRegister_2m = outputBufferPtr[outputHeightBlockIdx * 7 + 40772];
      outputRegister_2n = outputBufferPtr[outputHeightBlockIdx * 7 + 40773];
      outputRegister_2o = outputBufferPtr[outputHeightBlockIdx * 7 + 40774];
      outputRegister_2p = outputBufferPtr[outputHeightBlockIdx * 7 + 43904];
      outputRegister_2q = outputBufferPtr[outputHeightBlockIdx * 7 + 43905];
      outputRegister_2r = outputBufferPtr[outputHeightBlockIdx * 7 + 43906];
      outputRegister_2s = outputBufferPtr[outputHeightBlockIdx * 7 + 43907];
      outputRegister_2t = outputBufferPtr[outputHeightBlockIdx * 7 + 43908];
      outputRegister_2u = outputBufferPtr[outputHeightBlockIdx * 7 + 43909];
      outputRegister_2v = outputBufferPtr[outputHeightBlockIdx * 7 + 43910];
      outputRegister_2w = outputBufferPtr[outputHeightBlockIdx * 7 + 47040];
      outputRegister_2x = outputBufferPtr[outputHeightBlockIdx * 7 + 47041];
      outputRegister_2y = outputBufferPtr[outputHeightBlockIdx * 7 + 47042];
      outputRegister_2z = outputBufferPtr[outputHeightBlockIdx * 7 + 47043];
      outputRegister_30 = outputBufferPtr[outputHeightBlockIdx * 7 + 47044];
      outputRegister_31 = outputBufferPtr[outputHeightBlockIdx * 7 + 47045];
      outputRegister_32 = outputBufferPtr[outputHeightBlockIdx * 7 + 47046];
      for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
        inputRegister = inputBufferPtr[inputBufferIdx1 + inputChannelIdx];
        inputRegister_0 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          16];
        inputRegister_1 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          32];
        inputRegister_2 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          48];
        inputRegister_3 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          64];
        inputRegister_4 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          80];
        inputRegister_5 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          96];
        weightsRegister = weightsPtr[inputChannelIdx];
        outputRegister += inputRegister * weightsRegister;
        outputRegister_0 += inputRegister_0 * weightsRegister;
        outputRegister_1 += inputRegister_1 * weightsRegister;
        outputRegister_2 += inputRegister_2 * weightsRegister;
        outputRegister_3 += inputRegister_3 * weightsRegister;
        outputRegister_4 += inputRegister_4 * weightsRegister;
        outputRegister_5 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 16];
        outputRegister_6 += inputRegister * weightsRegister;
        outputRegister_7 += inputRegister_0 * weightsRegister;
        outputRegister_8 += inputRegister_1 * weightsRegister;
        outputRegister_9 += inputRegister_2 * weightsRegister;
        outputRegister_a += inputRegister_3 * weightsRegister;
        outputRegister_b += inputRegister_4 * weightsRegister;
        outputRegister_c += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 32];
        outputRegister_d += inputRegister * weightsRegister;
        outputRegister_e += inputRegister_0 * weightsRegister;
        outputRegister_f += inputRegister_1 * weightsRegister;
        outputRegister_g += inputRegister_2 * weightsRegister;
        outputRegister_h += inputRegister_3 * weightsRegister;
        outputRegister_i += inputRegister_4 * weightsRegister;
        outputRegister_j += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 48];
        outputRegister_k += inputRegister * weightsRegister;
        outputRegister_l += inputRegister_0 * weightsRegister;
        outputRegister_m += inputRegister_1 * weightsRegister;
        outputRegister_n += inputRegister_2 * weightsRegister;
        outputRegister_o += inputRegister_3 * weightsRegister;
        outputRegister_p += inputRegister_4 * weightsRegister;
        outputRegister_q += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 64];
        outputRegister_r += inputRegister * weightsRegister;
        outputRegister_s += inputRegister_0 * weightsRegister;
        outputRegister_t += inputRegister_1 * weightsRegister;
        outputRegister_u += inputRegister_2 * weightsRegister;
        outputRegister_v += inputRegister_3 * weightsRegister;
        outputRegister_w += inputRegister_4 * weightsRegister;
        outputRegister_x += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 80];
        outputRegister_y += inputRegister * weightsRegister;
        outputRegister_z += inputRegister_0 * weightsRegister;
        outputRegister_10 += inputRegister_1 * weightsRegister;
        outputRegister_11 += inputRegister_2 * weightsRegister;
        outputRegister_12 += inputRegister_3 * weightsRegister;
        outputRegister_13 += inputRegister_4 * weightsRegister;
        outputRegister_14 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 96];
        outputRegister_15 += inputRegister * weightsRegister;
        outputRegister_16 += inputRegister_0 * weightsRegister;
        outputRegister_17 += inputRegister_1 * weightsRegister;
        outputRegister_18 += inputRegister_2 * weightsRegister;
        outputRegister_19 += inputRegister_3 * weightsRegister;
        outputRegister_1a += inputRegister_4 * weightsRegister;
        outputRegister_1b += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 112];
        outputRegister_1c += inputRegister * weightsRegister;
        outputRegister_1d += inputRegister_0 * weightsRegister;
        outputRegister_1e += inputRegister_1 * weightsRegister;
        outputRegister_1f += inputRegister_2 * weightsRegister;
        outputRegister_1g += inputRegister_3 * weightsRegister;
        outputRegister_1h += inputRegister_4 * weightsRegister;
        outputRegister_1i += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 128];
        outputRegister_1j += inputRegister * weightsRegister;
        outputRegister_1k += inputRegister_0 * weightsRegister;
        outputRegister_1l += inputRegister_1 * weightsRegister;
        outputRegister_1m += inputRegister_2 * weightsRegister;
        outputRegister_1n += inputRegister_3 * weightsRegister;
        outputRegister_1o += inputRegister_4 * weightsRegister;
        outputRegister_1p += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 144];
        outputRegister_1q += inputRegister * weightsRegister;
        outputRegister_1r += inputRegister_0 * weightsRegister;
        outputRegister_1s += inputRegister_1 * weightsRegister;
        outputRegister_1t += inputRegister_2 * weightsRegister;
        outputRegister_1u += inputRegister_3 * weightsRegister;
        outputRegister_1v += inputRegister_4 * weightsRegister;
        outputRegister_1w += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 160];
        outputRegister_1x += inputRegister * weightsRegister;
        outputRegister_1y += inputRegister_0 * weightsRegister;
        outputRegister_1z += inputRegister_1 * weightsRegister;
        outputRegister_20 += inputRegister_2 * weightsRegister;
        outputRegister_21 += inputRegister_3 * weightsRegister;
        outputRegister_22 += inputRegister_4 * weightsRegister;
        outputRegister_23 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 176];
        outputRegister_24 += inputRegister * weightsRegister;
        outputRegister_25 += inputRegister_0 * weightsRegister;
        outputRegister_26 += inputRegister_1 * weightsRegister;
        outputRegister_27 += inputRegister_2 * weightsRegister;
        outputRegister_28 += inputRegister_3 * weightsRegister;
        outputRegister_29 += inputRegister_4 * weightsRegister;
        outputRegister_2a += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 192];
        outputRegister_2b += inputRegister * weightsRegister;
        outputRegister_2c += inputRegister_0 * weightsRegister;
        outputRegister_2d += inputRegister_1 * weightsRegister;
        outputRegister_2e += inputRegister_2 * weightsRegister;
        outputRegister_2f += inputRegister_3 * weightsRegister;
        outputRegister_2g += inputRegister_4 * weightsRegister;
        outputRegister_2h += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 208];
        outputRegister_2i += inputRegister * weightsRegister;
        outputRegister_2j += inputRegister_0 * weightsRegister;
        outputRegister_2k += inputRegister_1 * weightsRegister;
        outputRegister_2l += inputRegister_2 * weightsRegister;
        outputRegister_2m += inputRegister_3 * weightsRegister;
        outputRegister_2n += inputRegister_4 * weightsRegister;
        outputRegister_2o += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 224];
        outputRegister_2p += inputRegister * weightsRegister;
        outputRegister_2q += inputRegister_0 * weightsRegister;
        outputRegister_2r += inputRegister_1 * weightsRegister;
        outputRegister_2s += inputRegister_2 * weightsRegister;
        outputRegister_2t += inputRegister_3 * weightsRegister;
        outputRegister_2u += inputRegister_4 * weightsRegister;
        outputRegister_2v += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 240];
        outputRegister_2w += inputRegister * weightsRegister;
        outputRegister_2x += inputRegister_0 * weightsRegister;
        outputRegister_2y += inputRegister_1 * weightsRegister;
        outputRegister_2z += inputRegister_2 * weightsRegister;
        outputRegister_30 += inputRegister_3 * weightsRegister;
        outputRegister_31 += inputRegister_4 * weightsRegister;
        outputRegister_32 += inputRegister_5 * weightsRegister;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3136] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3137] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3138] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3139] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3140] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3141] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3142] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6272] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6273] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6274] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6275] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6276] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6277] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6278] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9408] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9409] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9410] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9411] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9412] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9413] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9414] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12544] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12545] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12546] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12547] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12548] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12549] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12550] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15680] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15681] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15682] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15683] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15684] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15685] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15686] = outputRegister_14;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18816] = outputRegister_15;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18817] = outputRegister_16;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18818] = outputRegister_17;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18819] = outputRegister_18;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18820] = outputRegister_19;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18821] = outputRegister_1a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18822] = outputRegister_1b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21952] = outputRegister_1c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21953] = outputRegister_1d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21954] = outputRegister_1e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21955] = outputRegister_1f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21956] = outputRegister_1g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21957] = outputRegister_1h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21958] = outputRegister_1i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25088] = outputRegister_1j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25089] = outputRegister_1k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25090] = outputRegister_1l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25091] = outputRegister_1m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25092] = outputRegister_1n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25093] = outputRegister_1o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25094] = outputRegister_1p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28224] = outputRegister_1q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28225] = outputRegister_1r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28226] = outputRegister_1s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28227] = outputRegister_1t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28228] = outputRegister_1u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28229] = outputRegister_1v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28230] = outputRegister_1w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31360] = outputRegister_1x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31361] = outputRegister_1y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31362] = outputRegister_1z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31363] = outputRegister_20;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31364] = outputRegister_21;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31365] = outputRegister_22;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31366] = outputRegister_23;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34496] = outputRegister_24;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34497] = outputRegister_25;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34498] = outputRegister_26;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34499] = outputRegister_27;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34500] = outputRegister_28;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34501] = outputRegister_29;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34502] = outputRegister_2a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37632] = outputRegister_2b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37633] = outputRegister_2c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37634] = outputRegister_2d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37635] = outputRegister_2e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37636] = outputRegister_2f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37637] = outputRegister_2g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37638] = outputRegister_2h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40768] = outputRegister_2i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40769] = outputRegister_2j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40770] = outputRegister_2k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40771] = outputRegister_2l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40772] = outputRegister_2m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40773] = outputRegister_2n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40774] = outputRegister_2o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43904] = outputRegister_2p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43905] = outputRegister_2q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43906] = outputRegister_2r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43907] = outputRegister_2s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43908] = outputRegister_2t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43909] = outputRegister_2u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43910] = outputRegister_2v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47040] = outputRegister_2w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47041] = outputRegister_2x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47042] = outputRegister_2y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47043] = outputRegister_2z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47044] = outputRegister_30;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47045] = outputRegister_31;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47046] = outputRegister_32;
      inputBufferIdx1 += 112;
    }
  }
}

static void stm32_convolution_d(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias)
{
  static real32_T inputScratchpadBuffer[50176];
  static real32_T outputScratchpadBuffer[3136];
  static boolean_T bufferInitialized;
  int32_T inputScratchpadBufferBaseIdx;
  real32_T biasRegister;
  real32_T *elemRefOutputBufferVar;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, 200704U);
    bufferInitialized = true;
  }

  memset(&outputScratchpadBuffer[0], 0, 12544U);
  for (stm32_B.bufferChannelMiniblockIdx_a = 1;
       stm32_B.bufferChannelMiniblockIdx_a < 2;
       stm32_B.bufferChannelMiniblockIdx_a++) {
    for (stm32_B.fusedInputWidthAndHeightIdx_i = 0;
         stm32_B.fusedInputWidthAndHeightIdx_i < 3136;
         stm32_B.fusedInputWidthAndHeightIdx_i++) {
      stm32_B.inputWidthIdx_l = div_nde_s32_floor
        (stm32_B.fusedInputWidthAndHeightIdx_i, 56);
      stm32_B.inputChannelMiniblockBaseIdx_o =
        stm32_B.fusedInputWidthAndHeightIdx_i % 56 + stm32_B.inputWidthIdx_l *
        56;
      inputScratchpadBufferBaseIdx = ((stm32_B.fusedInputWidthAndHeightIdx_i %
        56) << 4) + stm32_B.inputWidthIdx_l * 896;
      for (stm32_B.inputWidthIdx_l = 1; stm32_B.inputWidthIdx_l < 13;
           stm32_B.inputWidthIdx_l++) {
        inputScratchpadBuffer[(inputScratchpadBufferBaseIdx +
          stm32_B.inputWidthIdx_l) - 1] = inputTensor[(stm32_B.inputWidthIdx_l -
          1) * 3136 + stm32_B.inputChannelMiniblockBaseIdx_o];
      }
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_a = 0;
       stm32_B.bufferChannelMiniblockIdx_a < 56;
       stm32_B.bufferChannelMiniblockIdx_a++) {
    stm32_B.fusedInputWidthAndHeightIdx_i = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_a, 56);
    stm32_B.inputWidthIdx_l = stm32_B.fusedInputWidthAndHeightIdx_i << 8;
    outputChannelTailCase = (stm32_B.fusedInputWidthAndHeightIdx_i == 0);
    stm32_B.inputChannelMiniblockBaseIdx_o = stm32_B.bufferChannelMiniblockIdx_a
      % 56 * 56 + stm32_B.fusedInputWidthAndHeightIdx_i * 50176;
    inputScratchpadBufferBaseIdx = stm32_B.bufferChannelMiniblockIdx_a % 56 *
      896;
    for (stm32_B.fusedInputWidthAndHeightIdx_i = 1;
         stm32_B.fusedInputWidthAndHeightIdx_i < 2;
         stm32_B.fusedInputWidthAndHeightIdx_i++) {
      stm32_convolutionKernel_d
        (&inputScratchpadBuffer[inputScratchpadBufferBaseIdx],
         &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_o],
         &weights[stm32_B.inputWidthIdx_l], outputChannelTailCase);
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_a = 0;
       stm32_B.bufferChannelMiniblockIdx_a < 3136;
       stm32_B.bufferChannelMiniblockIdx_a++) {
    stm32_B.fusedInputWidthAndHeightIdx_i = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_a, 3136);
    biasRegister = bias[stm32_B.fusedInputWidthAndHeightIdx_i];
    stm32_B.inputChannelMiniblockBaseIdx_o = stm32_B.bufferChannelMiniblockIdx_a
      % 3136;
    stm32_B.inputWidthIdx_l = stm32_B.fusedInputWidthAndHeightIdx_i * 3136 +
      stm32_B.inputChannelMiniblockBaseIdx_o;
    stm32_B.inputChannelMiniblockBaseIdx_o +=
      stm32_B.fusedInputWidthAndHeightIdx_i * 3136;
    elemRefOutputBufferVar =
      &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_o];
    biasRegister += *elemRefOutputBufferVar;
    if (biasRegister >= 0.0F) {
      *elemRefOutputBufferVar = biasRegister;
    } else {
      *elemRefOutputBufferVar = 0.0F;
    }

    for (stm32_B.fusedInputWidthAndHeightIdx_i = 1;
         stm32_B.fusedInputWidthAndHeightIdx_i < 2;
         stm32_B.fusedInputWidthAndHeightIdx_i++) {
      outputTensor[stm32_B.inputWidthIdx_l] =
        outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_o];
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimizedColMajor_a(const real32_T X[37632], real32_T Z
  [3136])
{
  static const real32_T b[16] = { 0.243391231F, 0.191047058F, 0.149638891F,
    0.386258245F, 0.161906078F, 0.131632343F, -0.152135253F, 0.299876124F,
    -0.417130142F, -0.196147472F, -0.416258842F, 0.392103881F, 0.0F, 0.0F, 0.0F,
    0.0F };

  stm32_B.biasReformatted_p = 0.957348943F;
  stm32_convolution_d(&X[0], &Z[0], &b[0], &stm32_B.biasReformatted_p);
}

static void stm32_convolutionKernel_di(const real32_T *inputBufferPtr, real32_T *
  outputBufferPtr, const real32_T *weightsPtr, boolean_T outputChannelTailCase)
{
  int32_T inputChannelIdx;
  int32_T kernelHeightIdx;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  int32_T weightsIdx;
  real32_T inputRegister;
  real32_T inputRegister_0;
  real32_T inputRegister_1;
  real32_T inputRegister_2;
  real32_T inputRegister_3;
  real32_T inputRegister_4;
  real32_T inputRegister_5;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_10;
  real32_T outputRegister_11;
  real32_T outputRegister_12;
  real32_T outputRegister_13;
  real32_T outputRegister_14;
  real32_T outputRegister_15;
  real32_T outputRegister_16;
  real32_T outputRegister_17;
  real32_T outputRegister_18;
  real32_T outputRegister_19;
  real32_T outputRegister_1a;
  real32_T outputRegister_1b;
  real32_T outputRegister_1c;
  real32_T outputRegister_1d;
  real32_T outputRegister_1e;
  real32_T outputRegister_1f;
  real32_T outputRegister_1g;
  real32_T outputRegister_1h;
  real32_T outputRegister_1i;
  real32_T outputRegister_1j;
  real32_T outputRegister_1k;
  real32_T outputRegister_1l;
  real32_T outputRegister_1m;
  real32_T outputRegister_1n;
  real32_T outputRegister_1o;
  real32_T outputRegister_1p;
  real32_T outputRegister_1q;
  real32_T outputRegister_1r;
  real32_T outputRegister_1s;
  real32_T outputRegister_1t;
  real32_T outputRegister_1u;
  real32_T outputRegister_1v;
  real32_T outputRegister_1w;
  real32_T outputRegister_1x;
  real32_T outputRegister_1y;
  real32_T outputRegister_1z;
  real32_T outputRegister_2;
  real32_T outputRegister_20;
  real32_T outputRegister_21;
  real32_T outputRegister_22;
  real32_T outputRegister_23;
  real32_T outputRegister_24;
  real32_T outputRegister_25;
  real32_T outputRegister_26;
  real32_T outputRegister_27;
  real32_T outputRegister_28;
  real32_T outputRegister_29;
  real32_T outputRegister_2a;
  real32_T outputRegister_2b;
  real32_T outputRegister_2c;
  real32_T outputRegister_2d;
  real32_T outputRegister_2e;
  real32_T outputRegister_2f;
  real32_T outputRegister_2g;
  real32_T outputRegister_2h;
  real32_T outputRegister_2i;
  real32_T outputRegister_2j;
  real32_T outputRegister_2k;
  real32_T outputRegister_2l;
  real32_T outputRegister_2m;
  real32_T outputRegister_2n;
  real32_T outputRegister_2o;
  real32_T outputRegister_2p;
  real32_T outputRegister_2q;
  real32_T outputRegister_2r;
  real32_T outputRegister_2s;
  real32_T outputRegister_2t;
  real32_T outputRegister_2u;
  real32_T outputRegister_2v;
  real32_T outputRegister_2w;
  real32_T outputRegister_2x;
  real32_T outputRegister_2y;
  real32_T outputRegister_2z;
  real32_T outputRegister_3;
  real32_T outputRegister_30;
  real32_T outputRegister_31;
  real32_T outputRegister_32;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  real32_T outputRegister_f;
  real32_T outputRegister_g;
  real32_T outputRegister_h;
  real32_T outputRegister_i;
  real32_T outputRegister_j;
  real32_T outputRegister_k;
  real32_T outputRegister_l;
  real32_T outputRegister_m;
  real32_T outputRegister_n;
  real32_T outputRegister_o;
  real32_T outputRegister_p;
  real32_T outputRegister_q;
  real32_T outputRegister_r;
  real32_T outputRegister_s;
  real32_T outputRegister_t;
  real32_T outputRegister_u;
  real32_T outputRegister_v;
  real32_T outputRegister_w;
  real32_T outputRegister_x;
  real32_T outputRegister_y;
  real32_T outputRegister_z;
  real32_T weightsRegister;
  if (outputChannelTailCase) {
    stm32_B.inputBufferIdx1_o = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 8;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 3136];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 3137];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 3138];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 3139];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 3140];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 3141];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 3142];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 6272];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 6273];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 6274];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 6275];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 6276];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 6277];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 6278];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 9408];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 9409];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 9410];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 9411];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 9412];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 9413];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 9414];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 12544];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 12545];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 12546];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 12547];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 12548];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 12549];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 12550];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 15680];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 15681];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 15682];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 15683];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 15684];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 15685];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 15686];
      stm32_B.inputBufferIdx2_n = stm32_B.inputBufferIdx1_o;
      weightsIdx = 144;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        stm32_B.inputBufferIdx3_m = stm32_B.inputBufferIdx2_n;
        for (kernelHeightIdx = 0; kernelHeightIdx < 3; kernelHeightIdx++) {
          for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
            inputRegister = inputBufferPtr[stm32_B.inputBufferIdx3_m +
              inputChannelIdx];
            inputRegister_0 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 16];
            inputRegister_1 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 32];
            inputRegister_2 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 48];
            inputRegister_3 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 64];
            inputRegister_4 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 80];
            inputRegister_5 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 96];
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) - 144];
            outputRegister += inputRegister * weightsRegister;
            outputRegister_0 += inputRegister_0 * weightsRegister;
            outputRegister_1 += inputRegister_1 * weightsRegister;
            outputRegister_2 += inputRegister_2 * weightsRegister;
            outputRegister_3 += inputRegister_3 * weightsRegister;
            outputRegister_4 += inputRegister_4 * weightsRegister;
            outputRegister_5 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[weightsIdx + inputChannelIdx];
            outputRegister_6 += inputRegister * weightsRegister;
            outputRegister_7 += inputRegister_0 * weightsRegister;
            outputRegister_8 += inputRegister_1 * weightsRegister;
            outputRegister_9 += inputRegister_2 * weightsRegister;
            outputRegister_a += inputRegister_3 * weightsRegister;
            outputRegister_b += inputRegister_4 * weightsRegister;
            outputRegister_c += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 144];
            outputRegister_d += inputRegister * weightsRegister;
            outputRegister_e += inputRegister_0 * weightsRegister;
            outputRegister_f += inputRegister_1 * weightsRegister;
            outputRegister_g += inputRegister_2 * weightsRegister;
            outputRegister_h += inputRegister_3 * weightsRegister;
            outputRegister_i += inputRegister_4 * weightsRegister;
            outputRegister_j += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 288];
            outputRegister_k += inputRegister * weightsRegister;
            outputRegister_l += inputRegister_0 * weightsRegister;
            outputRegister_m += inputRegister_1 * weightsRegister;
            outputRegister_n += inputRegister_2 * weightsRegister;
            outputRegister_o += inputRegister_3 * weightsRegister;
            outputRegister_p += inputRegister_4 * weightsRegister;
            outputRegister_q += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 432];
            outputRegister_r += inputRegister * weightsRegister;
            outputRegister_s += inputRegister_0 * weightsRegister;
            outputRegister_t += inputRegister_1 * weightsRegister;
            outputRegister_u += inputRegister_2 * weightsRegister;
            outputRegister_v += inputRegister_3 * weightsRegister;
            outputRegister_w += inputRegister_4 * weightsRegister;
            outputRegister_x += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 576];
            outputRegister_y += inputRegister * weightsRegister;
            outputRegister_z += inputRegister_0 * weightsRegister;
            outputRegister_10 += inputRegister_1 * weightsRegister;
            outputRegister_11 += inputRegister_2 * weightsRegister;
            outputRegister_12 += inputRegister_3 * weightsRegister;
            outputRegister_13 += inputRegister_4 * weightsRegister;
            outputRegister_14 += inputRegister_5 * weightsRegister;
          }

          weightsIdx += 16;
          stm32_B.inputBufferIdx3_m += 16;
        }

        stm32_B.inputBufferIdx2_n += 928;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3136] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3137] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3138] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3139] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3140] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3141] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3142] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6272] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6273] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6274] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6275] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6276] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6277] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6278] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9408] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9409] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9410] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9411] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9412] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9413] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9414] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12544] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12545] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12546] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12547] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12548] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12549] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12550] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15680] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15681] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15682] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15683] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15684] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15685] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15686] = outputRegister_14;
      stm32_B.inputBufferIdx1_o += 112;
    }
  } else {
    stm32_B.inputBufferIdx1_o = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 8;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 3136];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 3137];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 3138];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 3139];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 3140];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 3141];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 3142];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 6272];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 6273];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 6274];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 6275];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 6276];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 6277];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 6278];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 9408];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 9409];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 9410];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 9411];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 9412];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 9413];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 9414];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 12544];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 12545];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 12546];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 12547];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 12548];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 12549];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 12550];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 15680];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 15681];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 15682];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 15683];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 15684];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 15685];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 15686];
      outputRegister_15 = outputBufferPtr[outputHeightBlockIdx * 7 + 18816];
      outputRegister_16 = outputBufferPtr[outputHeightBlockIdx * 7 + 18817];
      outputRegister_17 = outputBufferPtr[outputHeightBlockIdx * 7 + 18818];
      outputRegister_18 = outputBufferPtr[outputHeightBlockIdx * 7 + 18819];
      outputRegister_19 = outputBufferPtr[outputHeightBlockIdx * 7 + 18820];
      outputRegister_1a = outputBufferPtr[outputHeightBlockIdx * 7 + 18821];
      outputRegister_1b = outputBufferPtr[outputHeightBlockIdx * 7 + 18822];
      outputRegister_1c = outputBufferPtr[outputHeightBlockIdx * 7 + 21952];
      outputRegister_1d = outputBufferPtr[outputHeightBlockIdx * 7 + 21953];
      outputRegister_1e = outputBufferPtr[outputHeightBlockIdx * 7 + 21954];
      outputRegister_1f = outputBufferPtr[outputHeightBlockIdx * 7 + 21955];
      outputRegister_1g = outputBufferPtr[outputHeightBlockIdx * 7 + 21956];
      outputRegister_1h = outputBufferPtr[outputHeightBlockIdx * 7 + 21957];
      outputRegister_1i = outputBufferPtr[outputHeightBlockIdx * 7 + 21958];
      outputRegister_1j = outputBufferPtr[outputHeightBlockIdx * 7 + 25088];
      outputRegister_1k = outputBufferPtr[outputHeightBlockIdx * 7 + 25089];
      outputRegister_1l = outputBufferPtr[outputHeightBlockIdx * 7 + 25090];
      outputRegister_1m = outputBufferPtr[outputHeightBlockIdx * 7 + 25091];
      outputRegister_1n = outputBufferPtr[outputHeightBlockIdx * 7 + 25092];
      outputRegister_1o = outputBufferPtr[outputHeightBlockIdx * 7 + 25093];
      outputRegister_1p = outputBufferPtr[outputHeightBlockIdx * 7 + 25094];
      outputRegister_1q = outputBufferPtr[outputHeightBlockIdx * 7 + 28224];
      outputRegister_1r = outputBufferPtr[outputHeightBlockIdx * 7 + 28225];
      outputRegister_1s = outputBufferPtr[outputHeightBlockIdx * 7 + 28226];
      outputRegister_1t = outputBufferPtr[outputHeightBlockIdx * 7 + 28227];
      outputRegister_1u = outputBufferPtr[outputHeightBlockIdx * 7 + 28228];
      outputRegister_1v = outputBufferPtr[outputHeightBlockIdx * 7 + 28229];
      outputRegister_1w = outputBufferPtr[outputHeightBlockIdx * 7 + 28230];
      outputRegister_1x = outputBufferPtr[outputHeightBlockIdx * 7 + 31360];
      outputRegister_1y = outputBufferPtr[outputHeightBlockIdx * 7 + 31361];
      outputRegister_1z = outputBufferPtr[outputHeightBlockIdx * 7 + 31362];
      outputRegister_20 = outputBufferPtr[outputHeightBlockIdx * 7 + 31363];
      outputRegister_21 = outputBufferPtr[outputHeightBlockIdx * 7 + 31364];
      outputRegister_22 = outputBufferPtr[outputHeightBlockIdx * 7 + 31365];
      outputRegister_23 = outputBufferPtr[outputHeightBlockIdx * 7 + 31366];
      outputRegister_24 = outputBufferPtr[outputHeightBlockIdx * 7 + 34496];
      outputRegister_25 = outputBufferPtr[outputHeightBlockIdx * 7 + 34497];
      outputRegister_26 = outputBufferPtr[outputHeightBlockIdx * 7 + 34498];
      outputRegister_27 = outputBufferPtr[outputHeightBlockIdx * 7 + 34499];
      outputRegister_28 = outputBufferPtr[outputHeightBlockIdx * 7 + 34500];
      outputRegister_29 = outputBufferPtr[outputHeightBlockIdx * 7 + 34501];
      outputRegister_2a = outputBufferPtr[outputHeightBlockIdx * 7 + 34502];
      outputRegister_2b = outputBufferPtr[outputHeightBlockIdx * 7 + 37632];
      outputRegister_2c = outputBufferPtr[outputHeightBlockIdx * 7 + 37633];
      outputRegister_2d = outputBufferPtr[outputHeightBlockIdx * 7 + 37634];
      outputRegister_2e = outputBufferPtr[outputHeightBlockIdx * 7 + 37635];
      outputRegister_2f = outputBufferPtr[outputHeightBlockIdx * 7 + 37636];
      outputRegister_2g = outputBufferPtr[outputHeightBlockIdx * 7 + 37637];
      outputRegister_2h = outputBufferPtr[outputHeightBlockIdx * 7 + 37638];
      outputRegister_2i = outputBufferPtr[outputHeightBlockIdx * 7 + 40768];
      outputRegister_2j = outputBufferPtr[outputHeightBlockIdx * 7 + 40769];
      outputRegister_2k = outputBufferPtr[outputHeightBlockIdx * 7 + 40770];
      outputRegister_2l = outputBufferPtr[outputHeightBlockIdx * 7 + 40771];
      outputRegister_2m = outputBufferPtr[outputHeightBlockIdx * 7 + 40772];
      outputRegister_2n = outputBufferPtr[outputHeightBlockIdx * 7 + 40773];
      outputRegister_2o = outputBufferPtr[outputHeightBlockIdx * 7 + 40774];
      outputRegister_2p = outputBufferPtr[outputHeightBlockIdx * 7 + 43904];
      outputRegister_2q = outputBufferPtr[outputHeightBlockIdx * 7 + 43905];
      outputRegister_2r = outputBufferPtr[outputHeightBlockIdx * 7 + 43906];
      outputRegister_2s = outputBufferPtr[outputHeightBlockIdx * 7 + 43907];
      outputRegister_2t = outputBufferPtr[outputHeightBlockIdx * 7 + 43908];
      outputRegister_2u = outputBufferPtr[outputHeightBlockIdx * 7 + 43909];
      outputRegister_2v = outputBufferPtr[outputHeightBlockIdx * 7 + 43910];
      outputRegister_2w = outputBufferPtr[outputHeightBlockIdx * 7 + 47040];
      outputRegister_2x = outputBufferPtr[outputHeightBlockIdx * 7 + 47041];
      outputRegister_2y = outputBufferPtr[outputHeightBlockIdx * 7 + 47042];
      outputRegister_2z = outputBufferPtr[outputHeightBlockIdx * 7 + 47043];
      outputRegister_30 = outputBufferPtr[outputHeightBlockIdx * 7 + 47044];
      outputRegister_31 = outputBufferPtr[outputHeightBlockIdx * 7 + 47045];
      outputRegister_32 = outputBufferPtr[outputHeightBlockIdx * 7 + 47046];
      stm32_B.inputBufferIdx2_n = stm32_B.inputBufferIdx1_o;
      weightsIdx = 144;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        stm32_B.inputBufferIdx3_m = stm32_B.inputBufferIdx2_n;
        for (kernelHeightIdx = 0; kernelHeightIdx < 3; kernelHeightIdx++) {
          for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
            inputRegister = inputBufferPtr[stm32_B.inputBufferIdx3_m +
              inputChannelIdx];
            inputRegister_0 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 16];
            inputRegister_1 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 32];
            inputRegister_2 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 48];
            inputRegister_3 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 64];
            inputRegister_4 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 80];
            inputRegister_5 = inputBufferPtr[(stm32_B.inputBufferIdx3_m +
              inputChannelIdx) + 96];
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) - 144];
            outputRegister += inputRegister * weightsRegister;
            outputRegister_0 += inputRegister_0 * weightsRegister;
            outputRegister_1 += inputRegister_1 * weightsRegister;
            outputRegister_2 += inputRegister_2 * weightsRegister;
            outputRegister_3 += inputRegister_3 * weightsRegister;
            outputRegister_4 += inputRegister_4 * weightsRegister;
            outputRegister_5 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[weightsIdx + inputChannelIdx];
            outputRegister_6 += inputRegister * weightsRegister;
            outputRegister_7 += inputRegister_0 * weightsRegister;
            outputRegister_8 += inputRegister_1 * weightsRegister;
            outputRegister_9 += inputRegister_2 * weightsRegister;
            outputRegister_a += inputRegister_3 * weightsRegister;
            outputRegister_b += inputRegister_4 * weightsRegister;
            outputRegister_c += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 144];
            outputRegister_d += inputRegister * weightsRegister;
            outputRegister_e += inputRegister_0 * weightsRegister;
            outputRegister_f += inputRegister_1 * weightsRegister;
            outputRegister_g += inputRegister_2 * weightsRegister;
            outputRegister_h += inputRegister_3 * weightsRegister;
            outputRegister_i += inputRegister_4 * weightsRegister;
            outputRegister_j += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 288];
            outputRegister_k += inputRegister * weightsRegister;
            outputRegister_l += inputRegister_0 * weightsRegister;
            outputRegister_m += inputRegister_1 * weightsRegister;
            outputRegister_n += inputRegister_2 * weightsRegister;
            outputRegister_o += inputRegister_3 * weightsRegister;
            outputRegister_p += inputRegister_4 * weightsRegister;
            outputRegister_q += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 432];
            outputRegister_r += inputRegister * weightsRegister;
            outputRegister_s += inputRegister_0 * weightsRegister;
            outputRegister_t += inputRegister_1 * weightsRegister;
            outputRegister_u += inputRegister_2 * weightsRegister;
            outputRegister_v += inputRegister_3 * weightsRegister;
            outputRegister_w += inputRegister_4 * weightsRegister;
            outputRegister_x += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 576];
            outputRegister_y += inputRegister * weightsRegister;
            outputRegister_z += inputRegister_0 * weightsRegister;
            outputRegister_10 += inputRegister_1 * weightsRegister;
            outputRegister_11 += inputRegister_2 * weightsRegister;
            outputRegister_12 += inputRegister_3 * weightsRegister;
            outputRegister_13 += inputRegister_4 * weightsRegister;
            outputRegister_14 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 720];
            outputRegister_15 += inputRegister * weightsRegister;
            outputRegister_16 += inputRegister_0 * weightsRegister;
            outputRegister_17 += inputRegister_1 * weightsRegister;
            outputRegister_18 += inputRegister_2 * weightsRegister;
            outputRegister_19 += inputRegister_3 * weightsRegister;
            outputRegister_1a += inputRegister_4 * weightsRegister;
            outputRegister_1b += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 864];
            outputRegister_1c += inputRegister * weightsRegister;
            outputRegister_1d += inputRegister_0 * weightsRegister;
            outputRegister_1e += inputRegister_1 * weightsRegister;
            outputRegister_1f += inputRegister_2 * weightsRegister;
            outputRegister_1g += inputRegister_3 * weightsRegister;
            outputRegister_1h += inputRegister_4 * weightsRegister;
            outputRegister_1i += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1008];
            outputRegister_1j += inputRegister * weightsRegister;
            outputRegister_1k += inputRegister_0 * weightsRegister;
            outputRegister_1l += inputRegister_1 * weightsRegister;
            outputRegister_1m += inputRegister_2 * weightsRegister;
            outputRegister_1n += inputRegister_3 * weightsRegister;
            outputRegister_1o += inputRegister_4 * weightsRegister;
            outputRegister_1p += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1152];
            outputRegister_1q += inputRegister * weightsRegister;
            outputRegister_1r += inputRegister_0 * weightsRegister;
            outputRegister_1s += inputRegister_1 * weightsRegister;
            outputRegister_1t += inputRegister_2 * weightsRegister;
            outputRegister_1u += inputRegister_3 * weightsRegister;
            outputRegister_1v += inputRegister_4 * weightsRegister;
            outputRegister_1w += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1296];
            outputRegister_1x += inputRegister * weightsRegister;
            outputRegister_1y += inputRegister_0 * weightsRegister;
            outputRegister_1z += inputRegister_1 * weightsRegister;
            outputRegister_20 += inputRegister_2 * weightsRegister;
            outputRegister_21 += inputRegister_3 * weightsRegister;
            outputRegister_22 += inputRegister_4 * weightsRegister;
            outputRegister_23 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1440];
            outputRegister_24 += inputRegister * weightsRegister;
            outputRegister_25 += inputRegister_0 * weightsRegister;
            outputRegister_26 += inputRegister_1 * weightsRegister;
            outputRegister_27 += inputRegister_2 * weightsRegister;
            outputRegister_28 += inputRegister_3 * weightsRegister;
            outputRegister_29 += inputRegister_4 * weightsRegister;
            outputRegister_2a += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1584];
            outputRegister_2b += inputRegister * weightsRegister;
            outputRegister_2c += inputRegister_0 * weightsRegister;
            outputRegister_2d += inputRegister_1 * weightsRegister;
            outputRegister_2e += inputRegister_2 * weightsRegister;
            outputRegister_2f += inputRegister_3 * weightsRegister;
            outputRegister_2g += inputRegister_4 * weightsRegister;
            outputRegister_2h += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1728];
            outputRegister_2i += inputRegister * weightsRegister;
            outputRegister_2j += inputRegister_0 * weightsRegister;
            outputRegister_2k += inputRegister_1 * weightsRegister;
            outputRegister_2l += inputRegister_2 * weightsRegister;
            outputRegister_2m += inputRegister_3 * weightsRegister;
            outputRegister_2n += inputRegister_4 * weightsRegister;
            outputRegister_2o += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1872];
            outputRegister_2p += inputRegister * weightsRegister;
            outputRegister_2q += inputRegister_0 * weightsRegister;
            outputRegister_2r += inputRegister_1 * weightsRegister;
            outputRegister_2s += inputRegister_2 * weightsRegister;
            outputRegister_2t += inputRegister_3 * weightsRegister;
            outputRegister_2u += inputRegister_4 * weightsRegister;
            outputRegister_2v += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 2016];
            outputRegister_2w += inputRegister * weightsRegister;
            outputRegister_2x += inputRegister_0 * weightsRegister;
            outputRegister_2y += inputRegister_1 * weightsRegister;
            outputRegister_2z += inputRegister_2 * weightsRegister;
            outputRegister_30 += inputRegister_3 * weightsRegister;
            outputRegister_31 += inputRegister_4 * weightsRegister;
            outputRegister_32 += inputRegister_5 * weightsRegister;
          }

          weightsIdx += 16;
          stm32_B.inputBufferIdx3_m += 16;
        }

        stm32_B.inputBufferIdx2_n += 928;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3136] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3137] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3138] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3139] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3140] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3141] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3142] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6272] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6273] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6274] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6275] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6276] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6277] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6278] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9408] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9409] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9410] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9411] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9412] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9413] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9414] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12544] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12545] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12546] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12547] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12548] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12549] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 12550] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15680] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15681] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15682] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15683] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15684] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15685] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 15686] = outputRegister_14;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18816] = outputRegister_15;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18817] = outputRegister_16;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18818] = outputRegister_17;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18819] = outputRegister_18;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18820] = outputRegister_19;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18821] = outputRegister_1a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 18822] = outputRegister_1b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21952] = outputRegister_1c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21953] = outputRegister_1d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21954] = outputRegister_1e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21955] = outputRegister_1f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21956] = outputRegister_1g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21957] = outputRegister_1h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 21958] = outputRegister_1i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25088] = outputRegister_1j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25089] = outputRegister_1k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25090] = outputRegister_1l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25091] = outputRegister_1m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25092] = outputRegister_1n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25093] = outputRegister_1o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 25094] = outputRegister_1p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28224] = outputRegister_1q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28225] = outputRegister_1r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28226] = outputRegister_1s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28227] = outputRegister_1t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28228] = outputRegister_1u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28229] = outputRegister_1v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 28230] = outputRegister_1w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31360] = outputRegister_1x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31361] = outputRegister_1y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31362] = outputRegister_1z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31363] = outputRegister_20;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31364] = outputRegister_21;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31365] = outputRegister_22;
      outputBufferPtr[outputHeightBlockIdx * 7 + 31366] = outputRegister_23;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34496] = outputRegister_24;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34497] = outputRegister_25;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34498] = outputRegister_26;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34499] = outputRegister_27;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34500] = outputRegister_28;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34501] = outputRegister_29;
      outputBufferPtr[outputHeightBlockIdx * 7 + 34502] = outputRegister_2a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37632] = outputRegister_2b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37633] = outputRegister_2c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37634] = outputRegister_2d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37635] = outputRegister_2e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37636] = outputRegister_2f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37637] = outputRegister_2g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 37638] = outputRegister_2h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40768] = outputRegister_2i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40769] = outputRegister_2j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40770] = outputRegister_2k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40771] = outputRegister_2l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40772] = outputRegister_2m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40773] = outputRegister_2n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 40774] = outputRegister_2o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43904] = outputRegister_2p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43905] = outputRegister_2q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43906] = outputRegister_2r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43907] = outputRegister_2s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43908] = outputRegister_2t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43909] = outputRegister_2u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 43910] = outputRegister_2v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47040] = outputRegister_2w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47041] = outputRegister_2x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47042] = outputRegister_2y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47043] = outputRegister_2z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47044] = outputRegister_30;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47045] = outputRegister_31;
      outputBufferPtr[outputHeightBlockIdx * 7 + 47046] = outputRegister_32;
      stm32_B.inputBufferIdx1_o += 112;
    }
  }
}

static void stm32_convolution_di(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias)
{
  static real32_T outputScratchpadBuffer[119168];
  static real32_T inputScratchpadBuffer[53824];
  static boolean_T bufferInitialized;
  real32_T *elemRefOutputBufferVar;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, 215296U);
    bufferInitialized = true;
  }

  memset(&outputScratchpadBuffer[0], 0, 476672U);
  for (stm32_B.bufferChannelMiniblockIdx_j = 1;
       stm32_B.bufferChannelMiniblockIdx_j < 2;
       stm32_B.bufferChannelMiniblockIdx_j++) {
    for (stm32_B.fusedInputWidthAndHeightIdx_jz = 0;
         stm32_B.fusedInputWidthAndHeightIdx_jz < 3136;
         stm32_B.fusedInputWidthAndHeightIdx_jz++) {
      stm32_B.inputWidthIdx_o = div_nde_s32_floor
        (stm32_B.fusedInputWidthAndHeightIdx_jz, 56);
      stm32_B.inputChannelMiniblockBaseIdx_n =
        stm32_B.fusedInputWidthAndHeightIdx_jz % 56 + stm32_B.inputWidthIdx_o *
        56;
      stm32_B.inputScratchpadBufferBaseIdx_i =
        (((stm32_B.fusedInputWidthAndHeightIdx_jz % 56) << 4) +
         stm32_B.inputWidthIdx_o * 928) + 944;
      for (stm32_B.inputWidthIdx_o = 1; stm32_B.inputWidthIdx_o < 2;
           stm32_B.inputWidthIdx_o++) {
        inputScratchpadBuffer[stm32_B.inputScratchpadBufferBaseIdx_i] =
          inputTensor[stm32_B.inputChannelMiniblockBaseIdx_n];
      }
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_j = 0;
       stm32_B.bufferChannelMiniblockIdx_j < 168;
       stm32_B.bufferChannelMiniblockIdx_j++) {
    stm32_B.fusedInputWidthAndHeightIdx_jz = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_j, 56);
    stm32_B.inputWidthIdx_o = stm32_B.fusedInputWidthAndHeightIdx_jz * 2304;
    outputChannelTailCase = (stm32_B.fusedInputWidthAndHeightIdx_jz == 2);
    stm32_B.inputChannelMiniblockBaseIdx_n = stm32_B.bufferChannelMiniblockIdx_j
      % 56 * 56 + stm32_B.fusedInputWidthAndHeightIdx_jz * 50176;
    stm32_B.inputScratchpadBufferBaseIdx_i = stm32_B.bufferChannelMiniblockIdx_j
      % 56 * 928;
    for (stm32_B.fusedInputWidthAndHeightIdx_jz = 1;
         stm32_B.fusedInputWidthAndHeightIdx_jz < 2;
         stm32_B.fusedInputWidthAndHeightIdx_jz++) {
      stm32_convolutionKernel_di
        (&inputScratchpadBuffer[stm32_B.inputScratchpadBufferBaseIdx_i],
         &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_n],
         &weights[stm32_B.inputWidthIdx_o], outputChannelTailCase);
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_j = 0;
       stm32_B.bufferChannelMiniblockIdx_j < 119168;
       stm32_B.bufferChannelMiniblockIdx_j++) {
    stm32_B.fusedInputWidthAndHeightIdx_jz = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_j, 3136);
    stm32_B.biasRegister_g = bias[stm32_B.fusedInputWidthAndHeightIdx_jz];
    stm32_B.inputChannelMiniblockBaseIdx_n = stm32_B.bufferChannelMiniblockIdx_j
      % 3136;
    stm32_B.inputWidthIdx_o = stm32_B.fusedInputWidthAndHeightIdx_jz * 3136 +
      stm32_B.inputChannelMiniblockBaseIdx_n;
    stm32_B.inputChannelMiniblockBaseIdx_n +=
      stm32_B.fusedInputWidthAndHeightIdx_jz * 3136;
    elemRefOutputBufferVar =
      &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_n];
    stm32_B.biasRegister_g += *elemRefOutputBufferVar;
    if (stm32_B.biasRegister_g >= 0.0F) {
      *elemRefOutputBufferVar = stm32_B.biasRegister_g;
    } else {
      *elemRefOutputBufferVar = 0.0F;
    }

    for (stm32_B.fusedInputWidthAndHeightIdx_jz = 1;
         stm32_B.fusedInputWidthAndHeightIdx_jz < 2;
         stm32_B.fusedInputWidthAndHeightIdx_jz++) {
      outputTensor[stm32_B.inputWidthIdx_o] =
        outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_n];
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimizedColMajo_ai(const real32_T X[3136], real32_T Z
  [119168])
{
  static const real32_T b[5472] = { -0.0146430358F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00620875554F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00985228736F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0136362715F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00427120831F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00825731363F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0152714718F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00971737318F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0111153824F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0351001099F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0436541624F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.056731239F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.046973642F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0984372273F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0829428583F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0797119662F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0248855744F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0405237973F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0481941F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0298033115F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0580159202F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.078002274F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0895927772F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0978568718F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0677840859F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0035735413F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0490271337F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0194972269F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0249161981F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0214619562F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.014527197F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0195369851F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00912288949F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0180632211F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0137770036F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00876818318F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0107562309F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0188494399F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0540988259F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0792646408F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0981070772F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0568134F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00353092514F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0285828318F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.041460745F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0161355324F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00784227625F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0139037929F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0182487983F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00689723203F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00940433238F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0111396117F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0076121809F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00867840182F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0212420821F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0468833745F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0646268576F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0600341186F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.118072547F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.106169358F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0600816831F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.051331941F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0263009556F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00704102125F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00414826535F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00556664169F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0106775993F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00134719652F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00450001564F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00971983187F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00632923562F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00674354052F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0480998121F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00505866716F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0226738974F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00622760598F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0304557774F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0643618703F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.050973136F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00819352269F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0688004866F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0115891881F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00439936621F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00832590461F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0124089289F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00346225058F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00680440059F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0125452848F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0071628443F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0085003823F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0107767666F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0505305417F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.039509397F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0379663929F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0577588305F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0405179076F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0669262633F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00362111232F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0469661F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00680815708F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00349401031F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00523569202F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00693745F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00280312472F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00433835527F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00760896318F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00503279828F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00581821892F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0223118141F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0416227356F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.101673767F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.148830578F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.193683431F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0261067469F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0377509706F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.104543269F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0268847179F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0280460902F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0425020829F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0907465294F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.130225375F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.177327409F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0566574112F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0277062524F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0801306069F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0551048927F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0133393584F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0389128365F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0560138822F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0588166155F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0944024846F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0814632401F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.05202296F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0398408361F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0198114663F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0164999254F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0187679864F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.00260413694F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0119959712F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0122952312F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00222518714F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00958028063F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0154322162F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0158116259F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.030403737F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.020772526F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0637555569F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.124840401F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.149895921F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.075609F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0173914749F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0407087058F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, -0.0544409081F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00638606353F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00230353884F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00419713836F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00446401164F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00132023171F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00776840281F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00788733084F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0077841403F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00376190036F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0392850563F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.069798328F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.086751774F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.079891637F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.102636263F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0885227695F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0704642F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.048473563F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00748900324F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0136470562F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00605487F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00904566329F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0127483206F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00405764254F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00773372501F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.014221251F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00905701052F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0103811724F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.015587749F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0621227138F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.118151307F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.188128114F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.21453853F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.02507798F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0826408491F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.156157434F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0343399569F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0515511222F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0810751F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0953379646F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0713737085F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.132197723F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.139909074F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0917241946F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0499662831F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.017304739F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00337236305F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00231314055F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00414083619F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00583606726F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.000720691751F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00165213249F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00516661443F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00356316799F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00454799226F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0151216201F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0114507172F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0131015833F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0201771632F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00977913849F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0100455452F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0225971099F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0155610237F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0225654803F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00790457055F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00347071327F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00567843905F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00818664394F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00273346133F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0047479677F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00807415228F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00517251296F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00620975764F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0195531175F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0216025468F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0190926362F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0261265F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0258503743F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0196848214F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.033902131F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00286336569F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0337439924F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.016996F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, -0.00495015876F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0117257182F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.00616578292F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00972244609F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0195547435F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0203066915F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00924298819F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0315545648F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00784804206F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00390186813F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00598036079F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00810513552F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00326023437F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00507209264F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0085171219F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00566065824F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00659937318F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00793713F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00351151126F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00542170042F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00804471318F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00253704865F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00474996306F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00813544448F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00528645F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00629258156F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00976910256F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00398898451F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00686963089F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0100122737F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0029554381F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00586550776F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0100333057F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00601097476F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00720556639F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0342622027F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0401810259F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0875868201F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.140469253F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.17489627F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0814738348F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0245437603F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0326246545F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0535653792F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0702292621F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.112782195F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0865638778F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.26008448F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.29867214F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.15963386F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.161636814F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.267156929F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0432940237F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00977926888F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00544032734F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00804591831F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0133401472F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00408313097F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00741498126F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00207312033F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00999825634F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00797993317F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0227973983F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.037921194F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0281833354F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0887082443F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0930202529F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0807375386F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0434885956F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00515483553F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0331457444F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0936664939F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0244930368F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0759004653F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0828539655F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.119390801F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0130838882F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0449693F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0570417F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0921689793F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00379032199F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0023856936F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00361523335F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00556898F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.000862034562F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00216854853F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00557557447F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00313932449F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0042656404F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0404312909F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00379411853F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0136302114F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0694922432F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.074876F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0563326888F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0315174721F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0427376628F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0495181642F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0115575492F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.00514155F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00839113444F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0120882F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.00402843812F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00717842206F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0125239771F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00805995706F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00940644927F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F };

  static const real32_T c[38] = { 1.24995446F, -0.195991427F, 0.0436732471F,
    -0.0502870716F, -0.156828642F, 0.546022117F, -0.278955311F, 0.708684206F,
    0.517444193F, 1.00819719F, 0.179683283F, 0.732088327F, -0.20702751F,
    0.0428608321F, -0.160714254F, 0.446182698F, 0.354670018F, 0.396062136F,
    -0.111427434F, 1.16386247F, 1.66518867F, -0.30056408F, 0.398561F,
    0.779286563F, 0.759862661F, 0.619701207F, 0.0530339368F, 0.827632427F,
    0.702383F, 0.877729595F, 0.14989014F, 0.842604876F, 0.704051197F,
    0.114641681F, -0.208476901F, 0.4331761F, 0.927229047F, 1.16205311F };

  stm32_convolution_di(&X[0], &Z[0], &b[0], &c[0]);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void stm_MaxPooling2DLayer_predict_n(const real32_T X[119168], real32_T
  Z[29792])
{
  int32_T b_filterWidthIdx;
  int32_T inputWidthIdx;
  int32_T outChannelIdx;
  int32_T outHeightIdx;
  int32_T outWidthIdx;
  int32_T tmp;
  int32_T tmp_0;
  real32_T opValue;
  real32_T y;
  for (outChannelIdx = 0; outChannelIdx < 38; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 28; outWidthIdx++) {
      for (outHeightIdx = 0; outHeightIdx < 28; outHeightIdx++) {
        opValue = -3.402823466E+38F;
        tmp_0 = outHeightIdx << 1;
        tmp = outWidthIdx << 1;
        if ((tmp_0 + 4 <= 56) && (tmp + 4 <= 56)) {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = ((tmp + b_filterWidthIdx) * 56 + tmp_0) + 3136 *
              outChannelIdx;
            y = X[inputWidthIdx];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            y = X[inputWidthIdx + 1];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            y = X[inputWidthIdx + 2];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }
          }
        } else {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = tmp + b_filterWidthIdx;
            if (inputWidthIdx + 1 <= 56) {
              y = X[(56 * inputWidthIdx + tmp_0) + 3136 * outChannelIdx];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            if (inputWidthIdx + 1 <= 56) {
              y = X[(((outHeightIdx << 1) + 56 * inputWidthIdx) + 3136 *
                     outChannelIdx) + 1];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            if ((tmp_0 + 3 <= 56) && (inputWidthIdx + 1 <= 56)) {
              y = X[((56 * inputWidthIdx + tmp_0) + 3136 * outChannelIdx) + 2];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }
          }
        }

        Z[(outHeightIdx + 28 * outWidthIdx) + 784 * outChannelIdx] = opValue;
      }
    }
  }
}

static void stm32_convolutionKernel_die(const real32_T *inputBufferPtr, real32_T
  *outputBufferPtr, const real32_T *weightsPtr, boolean_T outputChannelTailCase)
{
  int32_T inputBufferIdx1;
  int32_T inputChannelIdx;
  int32_T outputHeightBlockIdx;
  real32_T inputRegister;
  real32_T inputRegister_0;
  real32_T inputRegister_1;
  real32_T inputRegister_2;
  real32_T inputRegister_3;
  real32_T inputRegister_4;
  real32_T inputRegister_5;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_10;
  real32_T outputRegister_11;
  real32_T outputRegister_12;
  real32_T outputRegister_13;
  real32_T outputRegister_14;
  real32_T outputRegister_15;
  real32_T outputRegister_16;
  real32_T outputRegister_17;
  real32_T outputRegister_18;
  real32_T outputRegister_19;
  real32_T outputRegister_1a;
  real32_T outputRegister_1b;
  real32_T outputRegister_1c;
  real32_T outputRegister_1d;
  real32_T outputRegister_1e;
  real32_T outputRegister_1f;
  real32_T outputRegister_1g;
  real32_T outputRegister_1h;
  real32_T outputRegister_1i;
  real32_T outputRegister_1j;
  real32_T outputRegister_1k;
  real32_T outputRegister_1l;
  real32_T outputRegister_1m;
  real32_T outputRegister_1n;
  real32_T outputRegister_1o;
  real32_T outputRegister_1p;
  real32_T outputRegister_1q;
  real32_T outputRegister_1r;
  real32_T outputRegister_1s;
  real32_T outputRegister_1t;
  real32_T outputRegister_1u;
  real32_T outputRegister_1v;
  real32_T outputRegister_1w;
  real32_T outputRegister_1x;
  real32_T outputRegister_1y;
  real32_T outputRegister_1z;
  real32_T outputRegister_2;
  real32_T outputRegister_20;
  real32_T outputRegister_21;
  real32_T outputRegister_22;
  real32_T outputRegister_23;
  real32_T outputRegister_24;
  real32_T outputRegister_25;
  real32_T outputRegister_26;
  real32_T outputRegister_27;
  real32_T outputRegister_28;
  real32_T outputRegister_29;
  real32_T outputRegister_2a;
  real32_T outputRegister_2b;
  real32_T outputRegister_2c;
  real32_T outputRegister_2d;
  real32_T outputRegister_2e;
  real32_T outputRegister_2f;
  real32_T outputRegister_2g;
  real32_T outputRegister_2h;
  real32_T outputRegister_2i;
  real32_T outputRegister_2j;
  real32_T outputRegister_2k;
  real32_T outputRegister_2l;
  real32_T outputRegister_2m;
  real32_T outputRegister_2n;
  real32_T outputRegister_2o;
  real32_T outputRegister_2p;
  real32_T outputRegister_2q;
  real32_T outputRegister_2r;
  real32_T outputRegister_2s;
  real32_T outputRegister_2t;
  real32_T outputRegister_2u;
  real32_T outputRegister_2v;
  real32_T outputRegister_2w;
  real32_T outputRegister_2x;
  real32_T outputRegister_2y;
  real32_T outputRegister_2z;
  real32_T outputRegister_3;
  real32_T outputRegister_30;
  real32_T outputRegister_31;
  real32_T outputRegister_32;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  real32_T outputRegister_f;
  real32_T outputRegister_g;
  real32_T outputRegister_h;
  real32_T outputRegister_i;
  real32_T outputRegister_j;
  real32_T outputRegister_k;
  real32_T outputRegister_l;
  real32_T outputRegister_m;
  real32_T outputRegister_n;
  real32_T outputRegister_o;
  real32_T outputRegister_p;
  real32_T outputRegister_q;
  real32_T outputRegister_r;
  real32_T outputRegister_s;
  real32_T outputRegister_t;
  real32_T outputRegister_u;
  real32_T outputRegister_v;
  real32_T outputRegister_w;
  real32_T outputRegister_x;
  real32_T outputRegister_y;
  real32_T outputRegister_z;
  real32_T weightsRegister;
  if (outputChannelTailCase) {
    inputBufferIdx1 = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 4;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
        inputRegister = inputBufferPtr[inputBufferIdx1 + inputChannelIdx];
        inputRegister_0 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          16];
        inputRegister_1 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          32];
        inputRegister_2 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          48];
        inputRegister_3 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          64];
        inputRegister_4 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          80];
        inputRegister_5 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          96];
        weightsRegister = weightsPtr[inputChannelIdx];
        outputRegister += inputRegister * weightsRegister;
        outputRegister_0 += inputRegister_0 * weightsRegister;
        outputRegister_1 += inputRegister_1 * weightsRegister;
        outputRegister_2 += inputRegister_2 * weightsRegister;
        outputRegister_3 += inputRegister_3 * weightsRegister;
        outputRegister_4 += inputRegister_4 * weightsRegister;
        outputRegister_5 += inputRegister_5 * weightsRegister;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      inputBufferIdx1 += 112;
    }
  } else {
    inputBufferIdx1 = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 4;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 784];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 785];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 786];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 787];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 788];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 789];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 790];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 1568];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 1569];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 1570];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 1571];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 1572];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 1573];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 1574];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 2352];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 2353];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 2354];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 2355];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 2356];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 2357];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 2358];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 3136];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 3137];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 3138];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 3139];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 3140];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 3141];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 3142];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 3920];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 3921];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 3922];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 3923];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 3924];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 3925];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 3926];
      outputRegister_15 = outputBufferPtr[outputHeightBlockIdx * 7 + 4704];
      outputRegister_16 = outputBufferPtr[outputHeightBlockIdx * 7 + 4705];
      outputRegister_17 = outputBufferPtr[outputHeightBlockIdx * 7 + 4706];
      outputRegister_18 = outputBufferPtr[outputHeightBlockIdx * 7 + 4707];
      outputRegister_19 = outputBufferPtr[outputHeightBlockIdx * 7 + 4708];
      outputRegister_1a = outputBufferPtr[outputHeightBlockIdx * 7 + 4709];
      outputRegister_1b = outputBufferPtr[outputHeightBlockIdx * 7 + 4710];
      outputRegister_1c = outputBufferPtr[outputHeightBlockIdx * 7 + 5488];
      outputRegister_1d = outputBufferPtr[outputHeightBlockIdx * 7 + 5489];
      outputRegister_1e = outputBufferPtr[outputHeightBlockIdx * 7 + 5490];
      outputRegister_1f = outputBufferPtr[outputHeightBlockIdx * 7 + 5491];
      outputRegister_1g = outputBufferPtr[outputHeightBlockIdx * 7 + 5492];
      outputRegister_1h = outputBufferPtr[outputHeightBlockIdx * 7 + 5493];
      outputRegister_1i = outputBufferPtr[outputHeightBlockIdx * 7 + 5494];
      outputRegister_1j = outputBufferPtr[outputHeightBlockIdx * 7 + 6272];
      outputRegister_1k = outputBufferPtr[outputHeightBlockIdx * 7 + 6273];
      outputRegister_1l = outputBufferPtr[outputHeightBlockIdx * 7 + 6274];
      outputRegister_1m = outputBufferPtr[outputHeightBlockIdx * 7 + 6275];
      outputRegister_1n = outputBufferPtr[outputHeightBlockIdx * 7 + 6276];
      outputRegister_1o = outputBufferPtr[outputHeightBlockIdx * 7 + 6277];
      outputRegister_1p = outputBufferPtr[outputHeightBlockIdx * 7 + 6278];
      outputRegister_1q = outputBufferPtr[outputHeightBlockIdx * 7 + 7056];
      outputRegister_1r = outputBufferPtr[outputHeightBlockIdx * 7 + 7057];
      outputRegister_1s = outputBufferPtr[outputHeightBlockIdx * 7 + 7058];
      outputRegister_1t = outputBufferPtr[outputHeightBlockIdx * 7 + 7059];
      outputRegister_1u = outputBufferPtr[outputHeightBlockIdx * 7 + 7060];
      outputRegister_1v = outputBufferPtr[outputHeightBlockIdx * 7 + 7061];
      outputRegister_1w = outputBufferPtr[outputHeightBlockIdx * 7 + 7062];
      outputRegister_1x = outputBufferPtr[outputHeightBlockIdx * 7 + 7840];
      outputRegister_1y = outputBufferPtr[outputHeightBlockIdx * 7 + 7841];
      outputRegister_1z = outputBufferPtr[outputHeightBlockIdx * 7 + 7842];
      outputRegister_20 = outputBufferPtr[outputHeightBlockIdx * 7 + 7843];
      outputRegister_21 = outputBufferPtr[outputHeightBlockIdx * 7 + 7844];
      outputRegister_22 = outputBufferPtr[outputHeightBlockIdx * 7 + 7845];
      outputRegister_23 = outputBufferPtr[outputHeightBlockIdx * 7 + 7846];
      outputRegister_24 = outputBufferPtr[outputHeightBlockIdx * 7 + 8624];
      outputRegister_25 = outputBufferPtr[outputHeightBlockIdx * 7 + 8625];
      outputRegister_26 = outputBufferPtr[outputHeightBlockIdx * 7 + 8626];
      outputRegister_27 = outputBufferPtr[outputHeightBlockIdx * 7 + 8627];
      outputRegister_28 = outputBufferPtr[outputHeightBlockIdx * 7 + 8628];
      outputRegister_29 = outputBufferPtr[outputHeightBlockIdx * 7 + 8629];
      outputRegister_2a = outputBufferPtr[outputHeightBlockIdx * 7 + 8630];
      outputRegister_2b = outputBufferPtr[outputHeightBlockIdx * 7 + 9408];
      outputRegister_2c = outputBufferPtr[outputHeightBlockIdx * 7 + 9409];
      outputRegister_2d = outputBufferPtr[outputHeightBlockIdx * 7 + 9410];
      outputRegister_2e = outputBufferPtr[outputHeightBlockIdx * 7 + 9411];
      outputRegister_2f = outputBufferPtr[outputHeightBlockIdx * 7 + 9412];
      outputRegister_2g = outputBufferPtr[outputHeightBlockIdx * 7 + 9413];
      outputRegister_2h = outputBufferPtr[outputHeightBlockIdx * 7 + 9414];
      outputRegister_2i = outputBufferPtr[outputHeightBlockIdx * 7 + 10192];
      outputRegister_2j = outputBufferPtr[outputHeightBlockIdx * 7 + 10193];
      outputRegister_2k = outputBufferPtr[outputHeightBlockIdx * 7 + 10194];
      outputRegister_2l = outputBufferPtr[outputHeightBlockIdx * 7 + 10195];
      outputRegister_2m = outputBufferPtr[outputHeightBlockIdx * 7 + 10196];
      outputRegister_2n = outputBufferPtr[outputHeightBlockIdx * 7 + 10197];
      outputRegister_2o = outputBufferPtr[outputHeightBlockIdx * 7 + 10198];
      outputRegister_2p = outputBufferPtr[outputHeightBlockIdx * 7 + 10976];
      outputRegister_2q = outputBufferPtr[outputHeightBlockIdx * 7 + 10977];
      outputRegister_2r = outputBufferPtr[outputHeightBlockIdx * 7 + 10978];
      outputRegister_2s = outputBufferPtr[outputHeightBlockIdx * 7 + 10979];
      outputRegister_2t = outputBufferPtr[outputHeightBlockIdx * 7 + 10980];
      outputRegister_2u = outputBufferPtr[outputHeightBlockIdx * 7 + 10981];
      outputRegister_2v = outputBufferPtr[outputHeightBlockIdx * 7 + 10982];
      outputRegister_2w = outputBufferPtr[outputHeightBlockIdx * 7 + 11760];
      outputRegister_2x = outputBufferPtr[outputHeightBlockIdx * 7 + 11761];
      outputRegister_2y = outputBufferPtr[outputHeightBlockIdx * 7 + 11762];
      outputRegister_2z = outputBufferPtr[outputHeightBlockIdx * 7 + 11763];
      outputRegister_30 = outputBufferPtr[outputHeightBlockIdx * 7 + 11764];
      outputRegister_31 = outputBufferPtr[outputHeightBlockIdx * 7 + 11765];
      outputRegister_32 = outputBufferPtr[outputHeightBlockIdx * 7 + 11766];
      for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
        inputRegister = inputBufferPtr[inputBufferIdx1 + inputChannelIdx];
        inputRegister_0 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          16];
        inputRegister_1 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          32];
        inputRegister_2 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          48];
        inputRegister_3 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          64];
        inputRegister_4 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          80];
        inputRegister_5 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          96];
        weightsRegister = weightsPtr[inputChannelIdx];
        outputRegister += inputRegister * weightsRegister;
        outputRegister_0 += inputRegister_0 * weightsRegister;
        outputRegister_1 += inputRegister_1 * weightsRegister;
        outputRegister_2 += inputRegister_2 * weightsRegister;
        outputRegister_3 += inputRegister_3 * weightsRegister;
        outputRegister_4 += inputRegister_4 * weightsRegister;
        outputRegister_5 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 48];
        outputRegister_6 += inputRegister * weightsRegister;
        outputRegister_7 += inputRegister_0 * weightsRegister;
        outputRegister_8 += inputRegister_1 * weightsRegister;
        outputRegister_9 += inputRegister_2 * weightsRegister;
        outputRegister_a += inputRegister_3 * weightsRegister;
        outputRegister_b += inputRegister_4 * weightsRegister;
        outputRegister_c += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 96];
        outputRegister_d += inputRegister * weightsRegister;
        outputRegister_e += inputRegister_0 * weightsRegister;
        outputRegister_f += inputRegister_1 * weightsRegister;
        outputRegister_g += inputRegister_2 * weightsRegister;
        outputRegister_h += inputRegister_3 * weightsRegister;
        outputRegister_i += inputRegister_4 * weightsRegister;
        outputRegister_j += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 144];
        outputRegister_k += inputRegister * weightsRegister;
        outputRegister_l += inputRegister_0 * weightsRegister;
        outputRegister_m += inputRegister_1 * weightsRegister;
        outputRegister_n += inputRegister_2 * weightsRegister;
        outputRegister_o += inputRegister_3 * weightsRegister;
        outputRegister_p += inputRegister_4 * weightsRegister;
        outputRegister_q += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 192];
        outputRegister_r += inputRegister * weightsRegister;
        outputRegister_s += inputRegister_0 * weightsRegister;
        outputRegister_t += inputRegister_1 * weightsRegister;
        outputRegister_u += inputRegister_2 * weightsRegister;
        outputRegister_v += inputRegister_3 * weightsRegister;
        outputRegister_w += inputRegister_4 * weightsRegister;
        outputRegister_x += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 240];
        outputRegister_y += inputRegister * weightsRegister;
        outputRegister_z += inputRegister_0 * weightsRegister;
        outputRegister_10 += inputRegister_1 * weightsRegister;
        outputRegister_11 += inputRegister_2 * weightsRegister;
        outputRegister_12 += inputRegister_3 * weightsRegister;
        outputRegister_13 += inputRegister_4 * weightsRegister;
        outputRegister_14 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 288];
        outputRegister_15 += inputRegister * weightsRegister;
        outputRegister_16 += inputRegister_0 * weightsRegister;
        outputRegister_17 += inputRegister_1 * weightsRegister;
        outputRegister_18 += inputRegister_2 * weightsRegister;
        outputRegister_19 += inputRegister_3 * weightsRegister;
        outputRegister_1a += inputRegister_4 * weightsRegister;
        outputRegister_1b += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 336];
        outputRegister_1c += inputRegister * weightsRegister;
        outputRegister_1d += inputRegister_0 * weightsRegister;
        outputRegister_1e += inputRegister_1 * weightsRegister;
        outputRegister_1f += inputRegister_2 * weightsRegister;
        outputRegister_1g += inputRegister_3 * weightsRegister;
        outputRegister_1h += inputRegister_4 * weightsRegister;
        outputRegister_1i += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 384];
        outputRegister_1j += inputRegister * weightsRegister;
        outputRegister_1k += inputRegister_0 * weightsRegister;
        outputRegister_1l += inputRegister_1 * weightsRegister;
        outputRegister_1m += inputRegister_2 * weightsRegister;
        outputRegister_1n += inputRegister_3 * weightsRegister;
        outputRegister_1o += inputRegister_4 * weightsRegister;
        outputRegister_1p += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 432];
        outputRegister_1q += inputRegister * weightsRegister;
        outputRegister_1r += inputRegister_0 * weightsRegister;
        outputRegister_1s += inputRegister_1 * weightsRegister;
        outputRegister_1t += inputRegister_2 * weightsRegister;
        outputRegister_1u += inputRegister_3 * weightsRegister;
        outputRegister_1v += inputRegister_4 * weightsRegister;
        outputRegister_1w += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 480];
        outputRegister_1x += inputRegister * weightsRegister;
        outputRegister_1y += inputRegister_0 * weightsRegister;
        outputRegister_1z += inputRegister_1 * weightsRegister;
        outputRegister_20 += inputRegister_2 * weightsRegister;
        outputRegister_21 += inputRegister_3 * weightsRegister;
        outputRegister_22 += inputRegister_4 * weightsRegister;
        outputRegister_23 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 528];
        outputRegister_24 += inputRegister * weightsRegister;
        outputRegister_25 += inputRegister_0 * weightsRegister;
        outputRegister_26 += inputRegister_1 * weightsRegister;
        outputRegister_27 += inputRegister_2 * weightsRegister;
        outputRegister_28 += inputRegister_3 * weightsRegister;
        outputRegister_29 += inputRegister_4 * weightsRegister;
        outputRegister_2a += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 576];
        outputRegister_2b += inputRegister * weightsRegister;
        outputRegister_2c += inputRegister_0 * weightsRegister;
        outputRegister_2d += inputRegister_1 * weightsRegister;
        outputRegister_2e += inputRegister_2 * weightsRegister;
        outputRegister_2f += inputRegister_3 * weightsRegister;
        outputRegister_2g += inputRegister_4 * weightsRegister;
        outputRegister_2h += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 624];
        outputRegister_2i += inputRegister * weightsRegister;
        outputRegister_2j += inputRegister_0 * weightsRegister;
        outputRegister_2k += inputRegister_1 * weightsRegister;
        outputRegister_2l += inputRegister_2 * weightsRegister;
        outputRegister_2m += inputRegister_3 * weightsRegister;
        outputRegister_2n += inputRegister_4 * weightsRegister;
        outputRegister_2o += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 672];
        outputRegister_2p += inputRegister * weightsRegister;
        outputRegister_2q += inputRegister_0 * weightsRegister;
        outputRegister_2r += inputRegister_1 * weightsRegister;
        outputRegister_2s += inputRegister_2 * weightsRegister;
        outputRegister_2t += inputRegister_3 * weightsRegister;
        outputRegister_2u += inputRegister_4 * weightsRegister;
        outputRegister_2v += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 720];
        outputRegister_2w += inputRegister * weightsRegister;
        outputRegister_2x += inputRegister_0 * weightsRegister;
        outputRegister_2y += inputRegister_1 * weightsRegister;
        outputRegister_2z += inputRegister_2 * weightsRegister;
        outputRegister_30 += inputRegister_3 * weightsRegister;
        outputRegister_31 += inputRegister_4 * weightsRegister;
        outputRegister_32 += inputRegister_5 * weightsRegister;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 784] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 785] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 786] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 787] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 788] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 789] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 790] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1568] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1569] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1570] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1571] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1572] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1573] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1574] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2352] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2353] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2354] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2355] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2356] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2357] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2358] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3136] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3137] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3138] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3139] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3140] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3141] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3142] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3920] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3921] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3922] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3923] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3924] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3925] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3926] = outputRegister_14;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4704] = outputRegister_15;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4705] = outputRegister_16;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4706] = outputRegister_17;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4707] = outputRegister_18;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4708] = outputRegister_19;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4709] = outputRegister_1a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4710] = outputRegister_1b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5488] = outputRegister_1c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5489] = outputRegister_1d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5490] = outputRegister_1e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5491] = outputRegister_1f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5492] = outputRegister_1g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5493] = outputRegister_1h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5494] = outputRegister_1i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6272] = outputRegister_1j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6273] = outputRegister_1k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6274] = outputRegister_1l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6275] = outputRegister_1m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6276] = outputRegister_1n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6277] = outputRegister_1o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6278] = outputRegister_1p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7056] = outputRegister_1q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7057] = outputRegister_1r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7058] = outputRegister_1s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7059] = outputRegister_1t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7060] = outputRegister_1u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7061] = outputRegister_1v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7062] = outputRegister_1w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7840] = outputRegister_1x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7841] = outputRegister_1y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7842] = outputRegister_1z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7843] = outputRegister_20;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7844] = outputRegister_21;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7845] = outputRegister_22;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7846] = outputRegister_23;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8624] = outputRegister_24;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8625] = outputRegister_25;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8626] = outputRegister_26;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8627] = outputRegister_27;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8628] = outputRegister_28;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8629] = outputRegister_29;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8630] = outputRegister_2a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9408] = outputRegister_2b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9409] = outputRegister_2c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9410] = outputRegister_2d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9411] = outputRegister_2e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9412] = outputRegister_2f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9413] = outputRegister_2g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9414] = outputRegister_2h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10192] = outputRegister_2i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10193] = outputRegister_2j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10194] = outputRegister_2k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10195] = outputRegister_2l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10196] = outputRegister_2m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10197] = outputRegister_2n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10198] = outputRegister_2o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10976] = outputRegister_2p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10977] = outputRegister_2q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10978] = outputRegister_2r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10979] = outputRegister_2s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10980] = outputRegister_2t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10981] = outputRegister_2u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10982] = outputRegister_2v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11760] = outputRegister_2w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11761] = outputRegister_2x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11762] = outputRegister_2y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11763] = outputRegister_2z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11764] = outputRegister_30;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11765] = outputRegister_31;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11766] = outputRegister_32;
      inputBufferIdx1 += 112;
    }
  }
}

static void stm32_convolution_die(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias)
{
  static real32_T inputScratchpadBuffer[12544];
  static real32_T outputScratchpadBuffer[784];
  static boolean_T bufferInitialized;
  int32_T inputScratchpadBufferBaseIdx;
  real32_T biasRegister;
  real32_T *elemRefOutputBufferVar;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, 50176U);
    bufferInitialized = true;
  }

  memset(&outputScratchpadBuffer[0], 0, 3136U);
  stm32_B.inputIdx = 0;
  stm32_B.weightsIdx = 0;
  for (stm32_B.inputChannelBlockIdx = 0; stm32_B.inputChannelBlockIdx < 3;
       stm32_B.inputChannelBlockIdx++) {
    if (stm32_B.inputChannelBlockIdx + 1 == 3) {
      stm32_B.numInputChannelMiniblockSizeAct = 6;
    } else {
      stm32_B.numInputChannelMiniblockSizeAct = 16;
    }

    for (stm32_B.bufferChannelMiniblockIdx_e = 1;
         stm32_B.bufferChannelMiniblockIdx_e < 2;
         stm32_B.bufferChannelMiniblockIdx_e++) {
      for (stm32_B.fusedInputWidthAndHeightIdx_j = 0;
           stm32_B.fusedInputWidthAndHeightIdx_j < 784;
           stm32_B.fusedInputWidthAndHeightIdx_j++) {
        stm32_B.inputWidthIdx_f = div_nde_s32_floor
          (stm32_B.fusedInputWidthAndHeightIdx_j, 28);
        stm32_B.inputChannelMiniblockBaseIdx_a =
          (stm32_B.fusedInputWidthAndHeightIdx_j % 28 + stm32_B.inputWidthIdx_f *
           28) + stm32_B.inputIdx;
        inputScratchpadBufferBaseIdx = ((stm32_B.fusedInputWidthAndHeightIdx_j %
          28) << 4) + stm32_B.inputWidthIdx_f * 448;
        for (stm32_B.inputWidthIdx_f = 1; stm32_B.inputWidthIdx_f <=
             stm32_B.numInputChannelMiniblockSizeAct; stm32_B.inputWidthIdx_f++)
        {
          inputScratchpadBuffer[(inputScratchpadBufferBaseIdx +
            stm32_B.inputWidthIdx_f) - 1] = inputTensor[(stm32_B.inputWidthIdx_f
            - 1) * 784 + stm32_B.inputChannelMiniblockBaseIdx_a];
        }
      }
    }

    for (stm32_B.bufferChannelMiniblockIdx_e = 0;
         stm32_B.bufferChannelMiniblockIdx_e < 28;
         stm32_B.bufferChannelMiniblockIdx_e++) {
      stm32_B.fusedInputWidthAndHeightIdx_j = div_nde_s32_floor
        (stm32_B.bufferChannelMiniblockIdx_e, 28);
      stm32_B.inputWidthIdx_f = stm32_B.fusedInputWidthAndHeightIdx_j * 768 +
        stm32_B.weightsIdx;
      outputChannelTailCase = (stm32_B.fusedInputWidthAndHeightIdx_j == 0);
      stm32_B.numInputChannelMiniblockSizeAct =
        stm32_B.bufferChannelMiniblockIdx_e % 28 * 28 +
        stm32_B.fusedInputWidthAndHeightIdx_j * 12544;
      stm32_B.inputChannelMiniblockBaseIdx_a =
        stm32_B.bufferChannelMiniblockIdx_e % 28 * 448;
      for (stm32_B.fusedInputWidthAndHeightIdx_j = 1;
           stm32_B.fusedInputWidthAndHeightIdx_j < 2;
           stm32_B.fusedInputWidthAndHeightIdx_j++) {
        stm32_convolutionKernel_die
          (&inputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_a],
           &outputScratchpadBuffer[stm32_B.numInputChannelMiniblockSizeAct],
           &weights[stm32_B.inputWidthIdx_f], outputChannelTailCase);
      }
    }

    stm32_B.inputIdx += 12544;
    stm32_B.weightsIdx += 16;
  }

  for (stm32_B.inputChannelBlockIdx = 0; stm32_B.inputChannelBlockIdx < 784;
       stm32_B.inputChannelBlockIdx++) {
    stm32_B.inputIdx = div_nde_s32_floor(stm32_B.inputChannelBlockIdx, 784);
    biasRegister = bias[stm32_B.inputIdx];
    stm32_B.bufferChannelMiniblockIdx_e = stm32_B.inputChannelBlockIdx % 784;
    stm32_B.weightsIdx = stm32_B.inputIdx * 784 +
      stm32_B.bufferChannelMiniblockIdx_e;
    stm32_B.bufferChannelMiniblockIdx_e += stm32_B.inputIdx * 784;
    elemRefOutputBufferVar =
      &outputScratchpadBuffer[stm32_B.bufferChannelMiniblockIdx_e];
    biasRegister += *elemRefOutputBufferVar;
    if (biasRegister >= 0.0F) {
      *elemRefOutputBufferVar = biasRegister;
    } else {
      *elemRefOutputBufferVar = 0.0F;
    }

    for (stm32_B.inputIdx = 1; stm32_B.inputIdx < 2; stm32_B.inputIdx++) {
      outputTensor[stm32_B.weightsIdx] =
        outputScratchpadBuffer[stm32_B.bufferChannelMiniblockIdx_e];
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimizedColMaj_aie(const real32_T X[29792], real32_T Z
  [784])
{
  static const real32_T b[48] = { -0.0113543114F, -0.0229601674F, 0.0876188204F,
    0.00012209182F, -0.0274850633F, -0.0112753548F, -0.0253224429F,
    -0.0126246298F, -0.0224762093F, -0.00193790765F, 0.00429735426F,
    -0.00373667106F, -0.0247881431F, -0.0569290593F, -0.0242280327F,
    -2.92356144E-5F, -0.0486189201F, -0.00587327406F, -0.0391589701F,
    -0.0124485055F, -0.0786409527F, -0.0274260025F, -0.0059161922F,
    -0.0114459768F, -0.00366071053F, -0.00046286F, -0.005923199F,
    -0.00430146279F, -0.00508459192F, -0.00366981328F, -0.0537442788F,
    -0.0670617595F, -0.000724677811F, -0.0276814736F, 0.513926864F,
    -0.00495788828F, -0.0332062282F, -0.00572505919F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  stm32_B.biasReformatted_lx = -0.47263357F;
  stm32_convolution_die(&X[0], &Z[0], &b[0], &stm32_B.biasReformatted_lx);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimizedColMa_aiel(const real32_T layer_Weights[48],
  const real32_T X[29792], real32_T Z[784])
{
  stm32_B.biasReformatted_dy = 1.44094372F;
  stm32_convolution_die(&X[0], &Z[0], &layer_Weights[0],
                        &stm32_B.biasReformatted_dy);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivation_predict(const real32_T X[29792], real32_T Z
  [784])
{
  static const real32_T b[48] = { -0.00295046507F, -3.75167583E-5F,
    -0.00203853566F, -4.91985484E-5F, -0.000572180899F, -0.000826750882F,
    -0.00019783368F, -0.00144869823F, 0.00559863402F, -0.00215184852F,
    -0.000554595084F, -0.00161134184F, -0.00092370552F, -0.00769313378F,
    -0.000283098867F, -0.000557018793F, -0.00170855911F, -0.000496494758F,
    -0.000617756392F, -0.00277163577F, -0.00308530754F, -0.00042460332F,
    -0.000634631F, -0.00125577766F, -0.00153267221F, -0.000877421233F,
    0.00210705F, -0.00193422474F, -0.00136815617F, -0.00178348529F,
    -0.00260344241F, -0.0012573729F, -0.00133866735F, -0.000710940745F,
    -0.00187001447F, -0.000718493888F, -0.00153775746F, -0.00279232417F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  conv2dDirectOptimizedColMa_aiel(b, X, Z);
}

static void stm32_convolutionKernel_dieq(const real32_T *inputBufferPtr,
  real32_T *outputBufferPtr, const real32_T *weightsPtr, boolean_T
  outputChannelTailCase)
{
  int32_T inputChannelIdx;
  int32_T kernelHeightIdx;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  int32_T weightsIdx;
  real32_T inputRegister;
  real32_T inputRegister_0;
  real32_T inputRegister_1;
  real32_T inputRegister_2;
  real32_T inputRegister_3;
  real32_T inputRegister_4;
  real32_T inputRegister_5;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_10;
  real32_T outputRegister_11;
  real32_T outputRegister_12;
  real32_T outputRegister_13;
  real32_T outputRegister_14;
  real32_T outputRegister_15;
  real32_T outputRegister_16;
  real32_T outputRegister_17;
  real32_T outputRegister_18;
  real32_T outputRegister_19;
  real32_T outputRegister_1a;
  real32_T outputRegister_1b;
  real32_T outputRegister_1c;
  real32_T outputRegister_1d;
  real32_T outputRegister_1e;
  real32_T outputRegister_1f;
  real32_T outputRegister_1g;
  real32_T outputRegister_1h;
  real32_T outputRegister_1i;
  real32_T outputRegister_1j;
  real32_T outputRegister_1k;
  real32_T outputRegister_1l;
  real32_T outputRegister_1m;
  real32_T outputRegister_1n;
  real32_T outputRegister_1o;
  real32_T outputRegister_1p;
  real32_T outputRegister_1q;
  real32_T outputRegister_1r;
  real32_T outputRegister_1s;
  real32_T outputRegister_1t;
  real32_T outputRegister_1u;
  real32_T outputRegister_1v;
  real32_T outputRegister_1w;
  real32_T outputRegister_1x;
  real32_T outputRegister_1y;
  real32_T outputRegister_1z;
  real32_T outputRegister_2;
  real32_T outputRegister_20;
  real32_T outputRegister_21;
  real32_T outputRegister_22;
  real32_T outputRegister_23;
  real32_T outputRegister_24;
  real32_T outputRegister_25;
  real32_T outputRegister_26;
  real32_T outputRegister_27;
  real32_T outputRegister_28;
  real32_T outputRegister_29;
  real32_T outputRegister_2a;
  real32_T outputRegister_2b;
  real32_T outputRegister_2c;
  real32_T outputRegister_2d;
  real32_T outputRegister_2e;
  real32_T outputRegister_2f;
  real32_T outputRegister_2g;
  real32_T outputRegister_2h;
  real32_T outputRegister_2i;
  real32_T outputRegister_2j;
  real32_T outputRegister_2k;
  real32_T outputRegister_2l;
  real32_T outputRegister_2m;
  real32_T outputRegister_2n;
  real32_T outputRegister_2o;
  real32_T outputRegister_2p;
  real32_T outputRegister_2q;
  real32_T outputRegister_2r;
  real32_T outputRegister_2s;
  real32_T outputRegister_2t;
  real32_T outputRegister_2u;
  real32_T outputRegister_2v;
  real32_T outputRegister_2w;
  real32_T outputRegister_2x;
  real32_T outputRegister_2y;
  real32_T outputRegister_2z;
  real32_T outputRegister_3;
  real32_T outputRegister_30;
  real32_T outputRegister_31;
  real32_T outputRegister_32;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  real32_T outputRegister_f;
  real32_T outputRegister_g;
  real32_T outputRegister_h;
  real32_T outputRegister_i;
  real32_T outputRegister_j;
  real32_T outputRegister_k;
  real32_T outputRegister_l;
  real32_T outputRegister_m;
  real32_T outputRegister_n;
  real32_T outputRegister_o;
  real32_T outputRegister_p;
  real32_T outputRegister_q;
  real32_T outputRegister_r;
  real32_T outputRegister_s;
  real32_T outputRegister_t;
  real32_T outputRegister_u;
  real32_T outputRegister_v;
  real32_T outputRegister_w;
  real32_T outputRegister_x;
  real32_T outputRegister_y;
  real32_T outputRegister_z;
  real32_T weightsRegister;
  if (outputChannelTailCase) {
    stm32_B.inputBufferIdx1_h = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 4;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      stm32_B.inputBufferIdx2_b = stm32_B.inputBufferIdx1_h;
      weightsIdx = 0;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        stm32_B.inputBufferIdx3_d = stm32_B.inputBufferIdx2_b;
        for (kernelHeightIdx = 0; kernelHeightIdx < 3; kernelHeightIdx++) {
          for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
            inputRegister = inputBufferPtr[stm32_B.inputBufferIdx3_d +
              inputChannelIdx];
            inputRegister_0 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 16];
            inputRegister_1 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 32];
            inputRegister_2 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 48];
            inputRegister_3 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 64];
            inputRegister_4 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 80];
            inputRegister_5 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 96];
            weightsRegister = weightsPtr[weightsIdx + inputChannelIdx];
            outputRegister += inputRegister * weightsRegister;
            outputRegister_0 += inputRegister_0 * weightsRegister;
            outputRegister_1 += inputRegister_1 * weightsRegister;
            outputRegister_2 += inputRegister_2 * weightsRegister;
            outputRegister_3 += inputRegister_3 * weightsRegister;
            outputRegister_4 += inputRegister_4 * weightsRegister;
            outputRegister_5 += inputRegister_5 * weightsRegister;
          }

          weightsIdx += 16;
          stm32_B.inputBufferIdx3_d += 16;
        }

        stm32_B.inputBufferIdx2_b += 480;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      stm32_B.inputBufferIdx1_h += 112;
    }
  } else {
    stm32_B.inputBufferIdx1_h = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 4;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 784];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 785];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 786];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 787];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 788];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 789];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 790];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 1568];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 1569];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 1570];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 1571];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 1572];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 1573];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 1574];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 2352];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 2353];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 2354];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 2355];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 2356];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 2357];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 2358];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 3136];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 3137];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 3138];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 3139];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 3140];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 3141];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 3142];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 3920];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 3921];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 3922];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 3923];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 3924];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 3925];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 3926];
      outputRegister_15 = outputBufferPtr[outputHeightBlockIdx * 7 + 4704];
      outputRegister_16 = outputBufferPtr[outputHeightBlockIdx * 7 + 4705];
      outputRegister_17 = outputBufferPtr[outputHeightBlockIdx * 7 + 4706];
      outputRegister_18 = outputBufferPtr[outputHeightBlockIdx * 7 + 4707];
      outputRegister_19 = outputBufferPtr[outputHeightBlockIdx * 7 + 4708];
      outputRegister_1a = outputBufferPtr[outputHeightBlockIdx * 7 + 4709];
      outputRegister_1b = outputBufferPtr[outputHeightBlockIdx * 7 + 4710];
      outputRegister_1c = outputBufferPtr[outputHeightBlockIdx * 7 + 5488];
      outputRegister_1d = outputBufferPtr[outputHeightBlockIdx * 7 + 5489];
      outputRegister_1e = outputBufferPtr[outputHeightBlockIdx * 7 + 5490];
      outputRegister_1f = outputBufferPtr[outputHeightBlockIdx * 7 + 5491];
      outputRegister_1g = outputBufferPtr[outputHeightBlockIdx * 7 + 5492];
      outputRegister_1h = outputBufferPtr[outputHeightBlockIdx * 7 + 5493];
      outputRegister_1i = outputBufferPtr[outputHeightBlockIdx * 7 + 5494];
      outputRegister_1j = outputBufferPtr[outputHeightBlockIdx * 7 + 6272];
      outputRegister_1k = outputBufferPtr[outputHeightBlockIdx * 7 + 6273];
      outputRegister_1l = outputBufferPtr[outputHeightBlockIdx * 7 + 6274];
      outputRegister_1m = outputBufferPtr[outputHeightBlockIdx * 7 + 6275];
      outputRegister_1n = outputBufferPtr[outputHeightBlockIdx * 7 + 6276];
      outputRegister_1o = outputBufferPtr[outputHeightBlockIdx * 7 + 6277];
      outputRegister_1p = outputBufferPtr[outputHeightBlockIdx * 7 + 6278];
      outputRegister_1q = outputBufferPtr[outputHeightBlockIdx * 7 + 7056];
      outputRegister_1r = outputBufferPtr[outputHeightBlockIdx * 7 + 7057];
      outputRegister_1s = outputBufferPtr[outputHeightBlockIdx * 7 + 7058];
      outputRegister_1t = outputBufferPtr[outputHeightBlockIdx * 7 + 7059];
      outputRegister_1u = outputBufferPtr[outputHeightBlockIdx * 7 + 7060];
      outputRegister_1v = outputBufferPtr[outputHeightBlockIdx * 7 + 7061];
      outputRegister_1w = outputBufferPtr[outputHeightBlockIdx * 7 + 7062];
      outputRegister_1x = outputBufferPtr[outputHeightBlockIdx * 7 + 7840];
      outputRegister_1y = outputBufferPtr[outputHeightBlockIdx * 7 + 7841];
      outputRegister_1z = outputBufferPtr[outputHeightBlockIdx * 7 + 7842];
      outputRegister_20 = outputBufferPtr[outputHeightBlockIdx * 7 + 7843];
      outputRegister_21 = outputBufferPtr[outputHeightBlockIdx * 7 + 7844];
      outputRegister_22 = outputBufferPtr[outputHeightBlockIdx * 7 + 7845];
      outputRegister_23 = outputBufferPtr[outputHeightBlockIdx * 7 + 7846];
      outputRegister_24 = outputBufferPtr[outputHeightBlockIdx * 7 + 8624];
      outputRegister_25 = outputBufferPtr[outputHeightBlockIdx * 7 + 8625];
      outputRegister_26 = outputBufferPtr[outputHeightBlockIdx * 7 + 8626];
      outputRegister_27 = outputBufferPtr[outputHeightBlockIdx * 7 + 8627];
      outputRegister_28 = outputBufferPtr[outputHeightBlockIdx * 7 + 8628];
      outputRegister_29 = outputBufferPtr[outputHeightBlockIdx * 7 + 8629];
      outputRegister_2a = outputBufferPtr[outputHeightBlockIdx * 7 + 8630];
      outputRegister_2b = outputBufferPtr[outputHeightBlockIdx * 7 + 9408];
      outputRegister_2c = outputBufferPtr[outputHeightBlockIdx * 7 + 9409];
      outputRegister_2d = outputBufferPtr[outputHeightBlockIdx * 7 + 9410];
      outputRegister_2e = outputBufferPtr[outputHeightBlockIdx * 7 + 9411];
      outputRegister_2f = outputBufferPtr[outputHeightBlockIdx * 7 + 9412];
      outputRegister_2g = outputBufferPtr[outputHeightBlockIdx * 7 + 9413];
      outputRegister_2h = outputBufferPtr[outputHeightBlockIdx * 7 + 9414];
      outputRegister_2i = outputBufferPtr[outputHeightBlockIdx * 7 + 10192];
      outputRegister_2j = outputBufferPtr[outputHeightBlockIdx * 7 + 10193];
      outputRegister_2k = outputBufferPtr[outputHeightBlockIdx * 7 + 10194];
      outputRegister_2l = outputBufferPtr[outputHeightBlockIdx * 7 + 10195];
      outputRegister_2m = outputBufferPtr[outputHeightBlockIdx * 7 + 10196];
      outputRegister_2n = outputBufferPtr[outputHeightBlockIdx * 7 + 10197];
      outputRegister_2o = outputBufferPtr[outputHeightBlockIdx * 7 + 10198];
      outputRegister_2p = outputBufferPtr[outputHeightBlockIdx * 7 + 10976];
      outputRegister_2q = outputBufferPtr[outputHeightBlockIdx * 7 + 10977];
      outputRegister_2r = outputBufferPtr[outputHeightBlockIdx * 7 + 10978];
      outputRegister_2s = outputBufferPtr[outputHeightBlockIdx * 7 + 10979];
      outputRegister_2t = outputBufferPtr[outputHeightBlockIdx * 7 + 10980];
      outputRegister_2u = outputBufferPtr[outputHeightBlockIdx * 7 + 10981];
      outputRegister_2v = outputBufferPtr[outputHeightBlockIdx * 7 + 10982];
      outputRegister_2w = outputBufferPtr[outputHeightBlockIdx * 7 + 11760];
      outputRegister_2x = outputBufferPtr[outputHeightBlockIdx * 7 + 11761];
      outputRegister_2y = outputBufferPtr[outputHeightBlockIdx * 7 + 11762];
      outputRegister_2z = outputBufferPtr[outputHeightBlockIdx * 7 + 11763];
      outputRegister_30 = outputBufferPtr[outputHeightBlockIdx * 7 + 11764];
      outputRegister_31 = outputBufferPtr[outputHeightBlockIdx * 7 + 11765];
      outputRegister_32 = outputBufferPtr[outputHeightBlockIdx * 7 + 11766];
      stm32_B.inputBufferIdx2_b = stm32_B.inputBufferIdx1_h;
      weightsIdx = 144;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        stm32_B.inputBufferIdx3_d = stm32_B.inputBufferIdx2_b;
        for (kernelHeightIdx = 0; kernelHeightIdx < 3; kernelHeightIdx++) {
          for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
            inputRegister = inputBufferPtr[stm32_B.inputBufferIdx3_d +
              inputChannelIdx];
            inputRegister_0 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 16];
            inputRegister_1 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 32];
            inputRegister_2 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 48];
            inputRegister_3 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 64];
            inputRegister_4 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 80];
            inputRegister_5 = inputBufferPtr[(stm32_B.inputBufferIdx3_d +
              inputChannelIdx) + 96];
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) - 144];
            outputRegister += inputRegister * weightsRegister;
            outputRegister_0 += inputRegister_0 * weightsRegister;
            outputRegister_1 += inputRegister_1 * weightsRegister;
            outputRegister_2 += inputRegister_2 * weightsRegister;
            outputRegister_3 += inputRegister_3 * weightsRegister;
            outputRegister_4 += inputRegister_4 * weightsRegister;
            outputRegister_5 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[weightsIdx + inputChannelIdx];
            outputRegister_6 += inputRegister * weightsRegister;
            outputRegister_7 += inputRegister_0 * weightsRegister;
            outputRegister_8 += inputRegister_1 * weightsRegister;
            outputRegister_9 += inputRegister_2 * weightsRegister;
            outputRegister_a += inputRegister_3 * weightsRegister;
            outputRegister_b += inputRegister_4 * weightsRegister;
            outputRegister_c += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 144];
            outputRegister_d += inputRegister * weightsRegister;
            outputRegister_e += inputRegister_0 * weightsRegister;
            outputRegister_f += inputRegister_1 * weightsRegister;
            outputRegister_g += inputRegister_2 * weightsRegister;
            outputRegister_h += inputRegister_3 * weightsRegister;
            outputRegister_i += inputRegister_4 * weightsRegister;
            outputRegister_j += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 288];
            outputRegister_k += inputRegister * weightsRegister;
            outputRegister_l += inputRegister_0 * weightsRegister;
            outputRegister_m += inputRegister_1 * weightsRegister;
            outputRegister_n += inputRegister_2 * weightsRegister;
            outputRegister_o += inputRegister_3 * weightsRegister;
            outputRegister_p += inputRegister_4 * weightsRegister;
            outputRegister_q += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 432];
            outputRegister_r += inputRegister * weightsRegister;
            outputRegister_s += inputRegister_0 * weightsRegister;
            outputRegister_t += inputRegister_1 * weightsRegister;
            outputRegister_u += inputRegister_2 * weightsRegister;
            outputRegister_v += inputRegister_3 * weightsRegister;
            outputRegister_w += inputRegister_4 * weightsRegister;
            outputRegister_x += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 576];
            outputRegister_y += inputRegister * weightsRegister;
            outputRegister_z += inputRegister_0 * weightsRegister;
            outputRegister_10 += inputRegister_1 * weightsRegister;
            outputRegister_11 += inputRegister_2 * weightsRegister;
            outputRegister_12 += inputRegister_3 * weightsRegister;
            outputRegister_13 += inputRegister_4 * weightsRegister;
            outputRegister_14 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 720];
            outputRegister_15 += inputRegister * weightsRegister;
            outputRegister_16 += inputRegister_0 * weightsRegister;
            outputRegister_17 += inputRegister_1 * weightsRegister;
            outputRegister_18 += inputRegister_2 * weightsRegister;
            outputRegister_19 += inputRegister_3 * weightsRegister;
            outputRegister_1a += inputRegister_4 * weightsRegister;
            outputRegister_1b += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 864];
            outputRegister_1c += inputRegister * weightsRegister;
            outputRegister_1d += inputRegister_0 * weightsRegister;
            outputRegister_1e += inputRegister_1 * weightsRegister;
            outputRegister_1f += inputRegister_2 * weightsRegister;
            outputRegister_1g += inputRegister_3 * weightsRegister;
            outputRegister_1h += inputRegister_4 * weightsRegister;
            outputRegister_1i += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1008];
            outputRegister_1j += inputRegister * weightsRegister;
            outputRegister_1k += inputRegister_0 * weightsRegister;
            outputRegister_1l += inputRegister_1 * weightsRegister;
            outputRegister_1m += inputRegister_2 * weightsRegister;
            outputRegister_1n += inputRegister_3 * weightsRegister;
            outputRegister_1o += inputRegister_4 * weightsRegister;
            outputRegister_1p += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1152];
            outputRegister_1q += inputRegister * weightsRegister;
            outputRegister_1r += inputRegister_0 * weightsRegister;
            outputRegister_1s += inputRegister_1 * weightsRegister;
            outputRegister_1t += inputRegister_2 * weightsRegister;
            outputRegister_1u += inputRegister_3 * weightsRegister;
            outputRegister_1v += inputRegister_4 * weightsRegister;
            outputRegister_1w += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1296];
            outputRegister_1x += inputRegister * weightsRegister;
            outputRegister_1y += inputRegister_0 * weightsRegister;
            outputRegister_1z += inputRegister_1 * weightsRegister;
            outputRegister_20 += inputRegister_2 * weightsRegister;
            outputRegister_21 += inputRegister_3 * weightsRegister;
            outputRegister_22 += inputRegister_4 * weightsRegister;
            outputRegister_23 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1440];
            outputRegister_24 += inputRegister * weightsRegister;
            outputRegister_25 += inputRegister_0 * weightsRegister;
            outputRegister_26 += inputRegister_1 * weightsRegister;
            outputRegister_27 += inputRegister_2 * weightsRegister;
            outputRegister_28 += inputRegister_3 * weightsRegister;
            outputRegister_29 += inputRegister_4 * weightsRegister;
            outputRegister_2a += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1584];
            outputRegister_2b += inputRegister * weightsRegister;
            outputRegister_2c += inputRegister_0 * weightsRegister;
            outputRegister_2d += inputRegister_1 * weightsRegister;
            outputRegister_2e += inputRegister_2 * weightsRegister;
            outputRegister_2f += inputRegister_3 * weightsRegister;
            outputRegister_2g += inputRegister_4 * weightsRegister;
            outputRegister_2h += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1728];
            outputRegister_2i += inputRegister * weightsRegister;
            outputRegister_2j += inputRegister_0 * weightsRegister;
            outputRegister_2k += inputRegister_1 * weightsRegister;
            outputRegister_2l += inputRegister_2 * weightsRegister;
            outputRegister_2m += inputRegister_3 * weightsRegister;
            outputRegister_2n += inputRegister_4 * weightsRegister;
            outputRegister_2o += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1872];
            outputRegister_2p += inputRegister * weightsRegister;
            outputRegister_2q += inputRegister_0 * weightsRegister;
            outputRegister_2r += inputRegister_1 * weightsRegister;
            outputRegister_2s += inputRegister_2 * weightsRegister;
            outputRegister_2t += inputRegister_3 * weightsRegister;
            outputRegister_2u += inputRegister_4 * weightsRegister;
            outputRegister_2v += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 2016];
            outputRegister_2w += inputRegister * weightsRegister;
            outputRegister_2x += inputRegister_0 * weightsRegister;
            outputRegister_2y += inputRegister_1 * weightsRegister;
            outputRegister_2z += inputRegister_2 * weightsRegister;
            outputRegister_30 += inputRegister_3 * weightsRegister;
            outputRegister_31 += inputRegister_4 * weightsRegister;
            outputRegister_32 += inputRegister_5 * weightsRegister;
          }

          weightsIdx += 16;
          stm32_B.inputBufferIdx3_d += 16;
        }

        stm32_B.inputBufferIdx2_b += 480;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 784] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 785] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 786] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 787] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 788] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 789] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 790] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1568] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1569] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1570] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1571] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1572] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1573] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1574] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2352] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2353] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2354] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2355] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2356] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2357] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2358] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3136] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3137] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3138] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3139] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3140] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3141] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3142] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3920] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3921] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3922] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3923] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3924] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3925] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3926] = outputRegister_14;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4704] = outputRegister_15;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4705] = outputRegister_16;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4706] = outputRegister_17;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4707] = outputRegister_18;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4708] = outputRegister_19;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4709] = outputRegister_1a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4710] = outputRegister_1b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5488] = outputRegister_1c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5489] = outputRegister_1d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5490] = outputRegister_1e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5491] = outputRegister_1f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5492] = outputRegister_1g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5493] = outputRegister_1h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5494] = outputRegister_1i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6272] = outputRegister_1j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6273] = outputRegister_1k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6274] = outputRegister_1l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6275] = outputRegister_1m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6276] = outputRegister_1n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6277] = outputRegister_1o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6278] = outputRegister_1p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7056] = outputRegister_1q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7057] = outputRegister_1r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7058] = outputRegister_1s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7059] = outputRegister_1t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7060] = outputRegister_1u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7061] = outputRegister_1v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7062] = outputRegister_1w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7840] = outputRegister_1x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7841] = outputRegister_1y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7842] = outputRegister_1z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7843] = outputRegister_20;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7844] = outputRegister_21;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7845] = outputRegister_22;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7846] = outputRegister_23;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8624] = outputRegister_24;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8625] = outputRegister_25;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8626] = outputRegister_26;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8627] = outputRegister_27;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8628] = outputRegister_28;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8629] = outputRegister_29;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8630] = outputRegister_2a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9408] = outputRegister_2b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9409] = outputRegister_2c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9410] = outputRegister_2d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9411] = outputRegister_2e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9412] = outputRegister_2f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9413] = outputRegister_2g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9414] = outputRegister_2h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10192] = outputRegister_2i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10193] = outputRegister_2j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10194] = outputRegister_2k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10195] = outputRegister_2l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10196] = outputRegister_2m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10197] = outputRegister_2n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10198] = outputRegister_2o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10976] = outputRegister_2p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10977] = outputRegister_2q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10978] = outputRegister_2r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10979] = outputRegister_2s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10980] = outputRegister_2t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10981] = outputRegister_2u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10982] = outputRegister_2v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11760] = outputRegister_2w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11761] = outputRegister_2x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11762] = outputRegister_2y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11763] = outputRegister_2z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11764] = outputRegister_30;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11765] = outputRegister_31;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11766] = outputRegister_32;
      stm32_B.inputBufferIdx1_h += 112;
    }
  }
}

static void stm32_convolution_dieq(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias)
{
  static real32_T inputScratchpadBuffer[14400];
  static real32_T outputScratchpadBuffer[784];
  static boolean_T bufferInitialized;
  real32_T *elemRefOutputBufferVar;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, 57600U);
    bufferInitialized = true;
  }

  memset(&outputScratchpadBuffer[0], 0, 3136U);
  for (stm32_B.bufferChannelMiniblockIdx_o = 1;
       stm32_B.bufferChannelMiniblockIdx_o < 2;
       stm32_B.bufferChannelMiniblockIdx_o++) {
    for (stm32_B.fusedInputWidthAndHeightIdx_b = 0;
         stm32_B.fusedInputWidthAndHeightIdx_b < 784;
         stm32_B.fusedInputWidthAndHeightIdx_b++) {
      stm32_B.inputWidthIdx_n = div_nde_s32_floor
        (stm32_B.fusedInputWidthAndHeightIdx_b, 28);
      stm32_B.inputChannelMiniblockBaseIdx_b =
        stm32_B.fusedInputWidthAndHeightIdx_b % 28 + stm32_B.inputWidthIdx_n *
        28;
      stm32_B.inputScratchpadBufferBaseIdx_l =
        (((stm32_B.fusedInputWidthAndHeightIdx_b % 28) << 4) +
         stm32_B.inputWidthIdx_n * 480) + 496;
      for (stm32_B.inputWidthIdx_n = 1; stm32_B.inputWidthIdx_n < 2;
           stm32_B.inputWidthIdx_n++) {
        inputScratchpadBuffer[stm32_B.inputScratchpadBufferBaseIdx_l] =
          inputTensor[stm32_B.inputChannelMiniblockBaseIdx_b];
      }
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_o = 0;
       stm32_B.bufferChannelMiniblockIdx_o < 28;
       stm32_B.bufferChannelMiniblockIdx_o++) {
    stm32_B.fusedInputWidthAndHeightIdx_b = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_o, 28);
    stm32_B.inputWidthIdx_n = stm32_B.fusedInputWidthAndHeightIdx_b * 2304;
    outputChannelTailCase = (stm32_B.fusedInputWidthAndHeightIdx_b == 0);
    stm32_B.inputChannelMiniblockBaseIdx_b = stm32_B.bufferChannelMiniblockIdx_o
      % 28 * 28 + stm32_B.fusedInputWidthAndHeightIdx_b * 12544;
    stm32_B.inputScratchpadBufferBaseIdx_l = stm32_B.bufferChannelMiniblockIdx_o
      % 28 * 480;
    for (stm32_B.fusedInputWidthAndHeightIdx_b = 1;
         stm32_B.fusedInputWidthAndHeightIdx_b < 2;
         stm32_B.fusedInputWidthAndHeightIdx_b++) {
      stm32_convolutionKernel_dieq
        (&inputScratchpadBuffer[stm32_B.inputScratchpadBufferBaseIdx_l],
         &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_b],
         &weights[stm32_B.inputWidthIdx_n], outputChannelTailCase);
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_o = 0;
       stm32_B.bufferChannelMiniblockIdx_o < 784;
       stm32_B.bufferChannelMiniblockIdx_o++) {
    stm32_B.fusedInputWidthAndHeightIdx_b = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_o, 784);
    stm32_B.biasRegister_f = bias[stm32_B.fusedInputWidthAndHeightIdx_b];
    stm32_B.inputChannelMiniblockBaseIdx_b = stm32_B.bufferChannelMiniblockIdx_o
      % 784;
    stm32_B.inputWidthIdx_n = stm32_B.fusedInputWidthAndHeightIdx_b * 784 +
      stm32_B.inputChannelMiniblockBaseIdx_b;
    stm32_B.inputChannelMiniblockBaseIdx_b +=
      stm32_B.fusedInputWidthAndHeightIdx_b * 784;
    elemRefOutputBufferVar =
      &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_b];
    stm32_B.biasRegister_f += *elemRefOutputBufferVar;
    if (stm32_B.biasRegister_f >= 0.0F) {
      *elemRefOutputBufferVar = stm32_B.biasRegister_f;
    } else {
      *elemRefOutputBufferVar = 0.0F;
    }

    for (stm32_B.fusedInputWidthAndHeightIdx_b = 1;
         stm32_B.fusedInputWidthAndHeightIdx_b < 2;
         stm32_B.fusedInputWidthAndHeightIdx_b++) {
      outputTensor[stm32_B.inputWidthIdx_n] =
        outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_b];
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimizedColM_aiel1(const real32_T X[784], real32_T Z
  [784])
{
  static const real32_T b[144] = { 0.0137699097F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0133703F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.013289704F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0137457494F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0133359954F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0131712817F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0138499402F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0134591507F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0132958526F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  stm32_B.biasReformatted_dh = 0.631676197F;
  stm32_convolution_dieq(&X[0], &Z[0], &b[0], &stm32_B.biasReformatted_dh);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimizedCol_aiel1d(const real32_T layer_Weights[48],
  const real32_T X[29792], real32_T Z[784])
{
  stm32_B.biasReformatted_ld = -0.130686656F;
  stm32_convolution_die(&X[0], &Z[0], &layer_Weights[0],
                        &stm32_B.biasReformatted_ld);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivation_predi_h(const real32_T X[29792], real32_T Z
  [784])
{
  static const real32_T b[48] = { -2.26974382E-32F, 8.26565606E-27F,
    2.78799179E-15F, 4.83448E-43F, -2.60642E-43F, -6.12367E-43F, -5.70328E-43F,
    -2.2701E-43F, -2.73338208E-26F, -8.11352E-43F, -2.28584022E-27F,
    2.73396048E-36F, -8.28170594E-33F, 2.00386E-43F, -5.03066E-43F,
    -6.23578E-43F, 2.10195E-43F, 6.09565E-43F, -3.09687E-43F, 2.4945254E-30F,
    -1.75516416E-39F, -9.38860579E-32F, 6.13769E-43F, 7.73517E-43F,
    -7.76319E-43F, 4.34403E-43F, 2.0038113E-28F, 2.1901846E-31F, 2.36819E-43F,
    -1.31862E-42F, -7.07656E-43F, -6.52032192E-24F, -6.64215E-43F, -4.52619E-43F,
    8.674337E-5F, -6.19374E-43F, 4.21791E-43F, -4.30063617E-30F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  conv2dDirectOptimizedCol_aiel1d(b, X, Z);
}

static void stm32_convolutionKernel_dieqb(const real32_T *inputBufferPtr,
  real32_T *outputBufferPtr, const real32_T *weightsPtr, boolean_T
  outputChannelTailCase)
{
  int32_T inputChannelIdx;
  int32_T kernelHeightIdx;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  int32_T weightsIdx;
  real32_T inputRegister;
  real32_T inputRegister_0;
  real32_T inputRegister_1;
  real32_T inputRegister_2;
  real32_T inputRegister_3;
  real32_T inputRegister_4;
  real32_T inputRegister_5;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_10;
  real32_T outputRegister_11;
  real32_T outputRegister_12;
  real32_T outputRegister_13;
  real32_T outputRegister_14;
  real32_T outputRegister_15;
  real32_T outputRegister_16;
  real32_T outputRegister_17;
  real32_T outputRegister_18;
  real32_T outputRegister_19;
  real32_T outputRegister_1a;
  real32_T outputRegister_1b;
  real32_T outputRegister_1c;
  real32_T outputRegister_1d;
  real32_T outputRegister_1e;
  real32_T outputRegister_1f;
  real32_T outputRegister_1g;
  real32_T outputRegister_1h;
  real32_T outputRegister_1i;
  real32_T outputRegister_1j;
  real32_T outputRegister_1k;
  real32_T outputRegister_1l;
  real32_T outputRegister_1m;
  real32_T outputRegister_1n;
  real32_T outputRegister_1o;
  real32_T outputRegister_1p;
  real32_T outputRegister_1q;
  real32_T outputRegister_1r;
  real32_T outputRegister_1s;
  real32_T outputRegister_1t;
  real32_T outputRegister_1u;
  real32_T outputRegister_1v;
  real32_T outputRegister_1w;
  real32_T outputRegister_1x;
  real32_T outputRegister_1y;
  real32_T outputRegister_1z;
  real32_T outputRegister_2;
  real32_T outputRegister_20;
  real32_T outputRegister_21;
  real32_T outputRegister_22;
  real32_T outputRegister_23;
  real32_T outputRegister_24;
  real32_T outputRegister_25;
  real32_T outputRegister_26;
  real32_T outputRegister_27;
  real32_T outputRegister_28;
  real32_T outputRegister_29;
  real32_T outputRegister_2a;
  real32_T outputRegister_2b;
  real32_T outputRegister_2c;
  real32_T outputRegister_2d;
  real32_T outputRegister_2e;
  real32_T outputRegister_2f;
  real32_T outputRegister_2g;
  real32_T outputRegister_2h;
  real32_T outputRegister_2i;
  real32_T outputRegister_2j;
  real32_T outputRegister_2k;
  real32_T outputRegister_2l;
  real32_T outputRegister_2m;
  real32_T outputRegister_2n;
  real32_T outputRegister_2o;
  real32_T outputRegister_2p;
  real32_T outputRegister_2q;
  real32_T outputRegister_2r;
  real32_T outputRegister_2s;
  real32_T outputRegister_2t;
  real32_T outputRegister_2u;
  real32_T outputRegister_2v;
  real32_T outputRegister_2w;
  real32_T outputRegister_2x;
  real32_T outputRegister_2y;
  real32_T outputRegister_2z;
  real32_T outputRegister_3;
  real32_T outputRegister_30;
  real32_T outputRegister_31;
  real32_T outputRegister_32;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  real32_T outputRegister_f;
  real32_T outputRegister_g;
  real32_T outputRegister_h;
  real32_T outputRegister_i;
  real32_T outputRegister_j;
  real32_T outputRegister_k;
  real32_T outputRegister_l;
  real32_T outputRegister_m;
  real32_T outputRegister_n;
  real32_T outputRegister_o;
  real32_T outputRegister_p;
  real32_T outputRegister_q;
  real32_T outputRegister_r;
  real32_T outputRegister_s;
  real32_T outputRegister_t;
  real32_T outputRegister_u;
  real32_T outputRegister_v;
  real32_T outputRegister_w;
  real32_T outputRegister_x;
  real32_T outputRegister_y;
  real32_T outputRegister_z;
  real32_T weightsRegister;
  if (outputChannelTailCase) {
    stm32_B.inputBufferIdx1 = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 4;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      stm32_B.inputBufferIdx2 = stm32_B.inputBufferIdx1;
      weightsIdx = 0;
      for (kernelWidthIdx = 0; kernelWidthIdx < 5; kernelWidthIdx++) {
        stm32_B.inputBufferIdx3 = stm32_B.inputBufferIdx2;
        for (kernelHeightIdx = 0; kernelHeightIdx < 5; kernelHeightIdx++) {
          for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
            inputRegister = inputBufferPtr[stm32_B.inputBufferIdx3 +
              inputChannelIdx];
            inputRegister_0 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 16];
            inputRegister_1 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 32];
            inputRegister_2 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 48];
            inputRegister_3 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 64];
            inputRegister_4 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 80];
            inputRegister_5 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 96];
            weightsRegister = weightsPtr[weightsIdx + inputChannelIdx];
            outputRegister += inputRegister * weightsRegister;
            outputRegister_0 += inputRegister_0 * weightsRegister;
            outputRegister_1 += inputRegister_1 * weightsRegister;
            outputRegister_2 += inputRegister_2 * weightsRegister;
            outputRegister_3 += inputRegister_3 * weightsRegister;
            outputRegister_4 += inputRegister_4 * weightsRegister;
            outputRegister_5 += inputRegister_5 * weightsRegister;
          }

          weightsIdx += 16;
          stm32_B.inputBufferIdx3 += 16;
        }

        stm32_B.inputBufferIdx2 += 512;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      stm32_B.inputBufferIdx1 += 112;
    }
  } else {
    stm32_B.inputBufferIdx1 = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 4;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 784];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 785];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 786];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 787];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 788];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 789];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 790];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 1568];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 1569];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 1570];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 1571];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 1572];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 1573];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 1574];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 2352];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 2353];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 2354];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 2355];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 2356];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 2357];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 2358];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 3136];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 3137];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 3138];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 3139];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 3140];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 3141];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 3142];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 3920];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 3921];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 3922];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 3923];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 3924];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 3925];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 3926];
      outputRegister_15 = outputBufferPtr[outputHeightBlockIdx * 7 + 4704];
      outputRegister_16 = outputBufferPtr[outputHeightBlockIdx * 7 + 4705];
      outputRegister_17 = outputBufferPtr[outputHeightBlockIdx * 7 + 4706];
      outputRegister_18 = outputBufferPtr[outputHeightBlockIdx * 7 + 4707];
      outputRegister_19 = outputBufferPtr[outputHeightBlockIdx * 7 + 4708];
      outputRegister_1a = outputBufferPtr[outputHeightBlockIdx * 7 + 4709];
      outputRegister_1b = outputBufferPtr[outputHeightBlockIdx * 7 + 4710];
      outputRegister_1c = outputBufferPtr[outputHeightBlockIdx * 7 + 5488];
      outputRegister_1d = outputBufferPtr[outputHeightBlockIdx * 7 + 5489];
      outputRegister_1e = outputBufferPtr[outputHeightBlockIdx * 7 + 5490];
      outputRegister_1f = outputBufferPtr[outputHeightBlockIdx * 7 + 5491];
      outputRegister_1g = outputBufferPtr[outputHeightBlockIdx * 7 + 5492];
      outputRegister_1h = outputBufferPtr[outputHeightBlockIdx * 7 + 5493];
      outputRegister_1i = outputBufferPtr[outputHeightBlockIdx * 7 + 5494];
      outputRegister_1j = outputBufferPtr[outputHeightBlockIdx * 7 + 6272];
      outputRegister_1k = outputBufferPtr[outputHeightBlockIdx * 7 + 6273];
      outputRegister_1l = outputBufferPtr[outputHeightBlockIdx * 7 + 6274];
      outputRegister_1m = outputBufferPtr[outputHeightBlockIdx * 7 + 6275];
      outputRegister_1n = outputBufferPtr[outputHeightBlockIdx * 7 + 6276];
      outputRegister_1o = outputBufferPtr[outputHeightBlockIdx * 7 + 6277];
      outputRegister_1p = outputBufferPtr[outputHeightBlockIdx * 7 + 6278];
      outputRegister_1q = outputBufferPtr[outputHeightBlockIdx * 7 + 7056];
      outputRegister_1r = outputBufferPtr[outputHeightBlockIdx * 7 + 7057];
      outputRegister_1s = outputBufferPtr[outputHeightBlockIdx * 7 + 7058];
      outputRegister_1t = outputBufferPtr[outputHeightBlockIdx * 7 + 7059];
      outputRegister_1u = outputBufferPtr[outputHeightBlockIdx * 7 + 7060];
      outputRegister_1v = outputBufferPtr[outputHeightBlockIdx * 7 + 7061];
      outputRegister_1w = outputBufferPtr[outputHeightBlockIdx * 7 + 7062];
      outputRegister_1x = outputBufferPtr[outputHeightBlockIdx * 7 + 7840];
      outputRegister_1y = outputBufferPtr[outputHeightBlockIdx * 7 + 7841];
      outputRegister_1z = outputBufferPtr[outputHeightBlockIdx * 7 + 7842];
      outputRegister_20 = outputBufferPtr[outputHeightBlockIdx * 7 + 7843];
      outputRegister_21 = outputBufferPtr[outputHeightBlockIdx * 7 + 7844];
      outputRegister_22 = outputBufferPtr[outputHeightBlockIdx * 7 + 7845];
      outputRegister_23 = outputBufferPtr[outputHeightBlockIdx * 7 + 7846];
      outputRegister_24 = outputBufferPtr[outputHeightBlockIdx * 7 + 8624];
      outputRegister_25 = outputBufferPtr[outputHeightBlockIdx * 7 + 8625];
      outputRegister_26 = outputBufferPtr[outputHeightBlockIdx * 7 + 8626];
      outputRegister_27 = outputBufferPtr[outputHeightBlockIdx * 7 + 8627];
      outputRegister_28 = outputBufferPtr[outputHeightBlockIdx * 7 + 8628];
      outputRegister_29 = outputBufferPtr[outputHeightBlockIdx * 7 + 8629];
      outputRegister_2a = outputBufferPtr[outputHeightBlockIdx * 7 + 8630];
      outputRegister_2b = outputBufferPtr[outputHeightBlockIdx * 7 + 9408];
      outputRegister_2c = outputBufferPtr[outputHeightBlockIdx * 7 + 9409];
      outputRegister_2d = outputBufferPtr[outputHeightBlockIdx * 7 + 9410];
      outputRegister_2e = outputBufferPtr[outputHeightBlockIdx * 7 + 9411];
      outputRegister_2f = outputBufferPtr[outputHeightBlockIdx * 7 + 9412];
      outputRegister_2g = outputBufferPtr[outputHeightBlockIdx * 7 + 9413];
      outputRegister_2h = outputBufferPtr[outputHeightBlockIdx * 7 + 9414];
      outputRegister_2i = outputBufferPtr[outputHeightBlockIdx * 7 + 10192];
      outputRegister_2j = outputBufferPtr[outputHeightBlockIdx * 7 + 10193];
      outputRegister_2k = outputBufferPtr[outputHeightBlockIdx * 7 + 10194];
      outputRegister_2l = outputBufferPtr[outputHeightBlockIdx * 7 + 10195];
      outputRegister_2m = outputBufferPtr[outputHeightBlockIdx * 7 + 10196];
      outputRegister_2n = outputBufferPtr[outputHeightBlockIdx * 7 + 10197];
      outputRegister_2o = outputBufferPtr[outputHeightBlockIdx * 7 + 10198];
      outputRegister_2p = outputBufferPtr[outputHeightBlockIdx * 7 + 10976];
      outputRegister_2q = outputBufferPtr[outputHeightBlockIdx * 7 + 10977];
      outputRegister_2r = outputBufferPtr[outputHeightBlockIdx * 7 + 10978];
      outputRegister_2s = outputBufferPtr[outputHeightBlockIdx * 7 + 10979];
      outputRegister_2t = outputBufferPtr[outputHeightBlockIdx * 7 + 10980];
      outputRegister_2u = outputBufferPtr[outputHeightBlockIdx * 7 + 10981];
      outputRegister_2v = outputBufferPtr[outputHeightBlockIdx * 7 + 10982];
      outputRegister_2w = outputBufferPtr[outputHeightBlockIdx * 7 + 11760];
      outputRegister_2x = outputBufferPtr[outputHeightBlockIdx * 7 + 11761];
      outputRegister_2y = outputBufferPtr[outputHeightBlockIdx * 7 + 11762];
      outputRegister_2z = outputBufferPtr[outputHeightBlockIdx * 7 + 11763];
      outputRegister_30 = outputBufferPtr[outputHeightBlockIdx * 7 + 11764];
      outputRegister_31 = outputBufferPtr[outputHeightBlockIdx * 7 + 11765];
      outputRegister_32 = outputBufferPtr[outputHeightBlockIdx * 7 + 11766];
      stm32_B.inputBufferIdx2 = stm32_B.inputBufferIdx1;
      weightsIdx = 400;
      for (kernelWidthIdx = 0; kernelWidthIdx < 5; kernelWidthIdx++) {
        stm32_B.inputBufferIdx3 = stm32_B.inputBufferIdx2;
        for (kernelHeightIdx = 0; kernelHeightIdx < 5; kernelHeightIdx++) {
          for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
            inputRegister = inputBufferPtr[stm32_B.inputBufferIdx3 +
              inputChannelIdx];
            inputRegister_0 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 16];
            inputRegister_1 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 32];
            inputRegister_2 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 48];
            inputRegister_3 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 64];
            inputRegister_4 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 80];
            inputRegister_5 = inputBufferPtr[(stm32_B.inputBufferIdx3 +
              inputChannelIdx) + 96];
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) - 400];
            outputRegister += inputRegister * weightsRegister;
            outputRegister_0 += inputRegister_0 * weightsRegister;
            outputRegister_1 += inputRegister_1 * weightsRegister;
            outputRegister_2 += inputRegister_2 * weightsRegister;
            outputRegister_3 += inputRegister_3 * weightsRegister;
            outputRegister_4 += inputRegister_4 * weightsRegister;
            outputRegister_5 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[weightsIdx + inputChannelIdx];
            outputRegister_6 += inputRegister * weightsRegister;
            outputRegister_7 += inputRegister_0 * weightsRegister;
            outputRegister_8 += inputRegister_1 * weightsRegister;
            outputRegister_9 += inputRegister_2 * weightsRegister;
            outputRegister_a += inputRegister_3 * weightsRegister;
            outputRegister_b += inputRegister_4 * weightsRegister;
            outputRegister_c += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 400];
            outputRegister_d += inputRegister * weightsRegister;
            outputRegister_e += inputRegister_0 * weightsRegister;
            outputRegister_f += inputRegister_1 * weightsRegister;
            outputRegister_g += inputRegister_2 * weightsRegister;
            outputRegister_h += inputRegister_3 * weightsRegister;
            outputRegister_i += inputRegister_4 * weightsRegister;
            outputRegister_j += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 800];
            outputRegister_k += inputRegister * weightsRegister;
            outputRegister_l += inputRegister_0 * weightsRegister;
            outputRegister_m += inputRegister_1 * weightsRegister;
            outputRegister_n += inputRegister_2 * weightsRegister;
            outputRegister_o += inputRegister_3 * weightsRegister;
            outputRegister_p += inputRegister_4 * weightsRegister;
            outputRegister_q += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1200];
            outputRegister_r += inputRegister * weightsRegister;
            outputRegister_s += inputRegister_0 * weightsRegister;
            outputRegister_t += inputRegister_1 * weightsRegister;
            outputRegister_u += inputRegister_2 * weightsRegister;
            outputRegister_v += inputRegister_3 * weightsRegister;
            outputRegister_w += inputRegister_4 * weightsRegister;
            outputRegister_x += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 1600];
            outputRegister_y += inputRegister * weightsRegister;
            outputRegister_z += inputRegister_0 * weightsRegister;
            outputRegister_10 += inputRegister_1 * weightsRegister;
            outputRegister_11 += inputRegister_2 * weightsRegister;
            outputRegister_12 += inputRegister_3 * weightsRegister;
            outputRegister_13 += inputRegister_4 * weightsRegister;
            outputRegister_14 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 2000];
            outputRegister_15 += inputRegister * weightsRegister;
            outputRegister_16 += inputRegister_0 * weightsRegister;
            outputRegister_17 += inputRegister_1 * weightsRegister;
            outputRegister_18 += inputRegister_2 * weightsRegister;
            outputRegister_19 += inputRegister_3 * weightsRegister;
            outputRegister_1a += inputRegister_4 * weightsRegister;
            outputRegister_1b += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 2400];
            outputRegister_1c += inputRegister * weightsRegister;
            outputRegister_1d += inputRegister_0 * weightsRegister;
            outputRegister_1e += inputRegister_1 * weightsRegister;
            outputRegister_1f += inputRegister_2 * weightsRegister;
            outputRegister_1g += inputRegister_3 * weightsRegister;
            outputRegister_1h += inputRegister_4 * weightsRegister;
            outputRegister_1i += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 2800];
            outputRegister_1j += inputRegister * weightsRegister;
            outputRegister_1k += inputRegister_0 * weightsRegister;
            outputRegister_1l += inputRegister_1 * weightsRegister;
            outputRegister_1m += inputRegister_2 * weightsRegister;
            outputRegister_1n += inputRegister_3 * weightsRegister;
            outputRegister_1o += inputRegister_4 * weightsRegister;
            outputRegister_1p += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 3200];
            outputRegister_1q += inputRegister * weightsRegister;
            outputRegister_1r += inputRegister_0 * weightsRegister;
            outputRegister_1s += inputRegister_1 * weightsRegister;
            outputRegister_1t += inputRegister_2 * weightsRegister;
            outputRegister_1u += inputRegister_3 * weightsRegister;
            outputRegister_1v += inputRegister_4 * weightsRegister;
            outputRegister_1w += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 3600];
            outputRegister_1x += inputRegister * weightsRegister;
            outputRegister_1y += inputRegister_0 * weightsRegister;
            outputRegister_1z += inputRegister_1 * weightsRegister;
            outputRegister_20 += inputRegister_2 * weightsRegister;
            outputRegister_21 += inputRegister_3 * weightsRegister;
            outputRegister_22 += inputRegister_4 * weightsRegister;
            outputRegister_23 += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 4000];
            outputRegister_24 += inputRegister * weightsRegister;
            outputRegister_25 += inputRegister_0 * weightsRegister;
            outputRegister_26 += inputRegister_1 * weightsRegister;
            outputRegister_27 += inputRegister_2 * weightsRegister;
            outputRegister_28 += inputRegister_3 * weightsRegister;
            outputRegister_29 += inputRegister_4 * weightsRegister;
            outputRegister_2a += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 4400];
            outputRegister_2b += inputRegister * weightsRegister;
            outputRegister_2c += inputRegister_0 * weightsRegister;
            outputRegister_2d += inputRegister_1 * weightsRegister;
            outputRegister_2e += inputRegister_2 * weightsRegister;
            outputRegister_2f += inputRegister_3 * weightsRegister;
            outputRegister_2g += inputRegister_4 * weightsRegister;
            outputRegister_2h += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 4800];
            outputRegister_2i += inputRegister * weightsRegister;
            outputRegister_2j += inputRegister_0 * weightsRegister;
            outputRegister_2k += inputRegister_1 * weightsRegister;
            outputRegister_2l += inputRegister_2 * weightsRegister;
            outputRegister_2m += inputRegister_3 * weightsRegister;
            outputRegister_2n += inputRegister_4 * weightsRegister;
            outputRegister_2o += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 5200];
            outputRegister_2p += inputRegister * weightsRegister;
            outputRegister_2q += inputRegister_0 * weightsRegister;
            outputRegister_2r += inputRegister_1 * weightsRegister;
            outputRegister_2s += inputRegister_2 * weightsRegister;
            outputRegister_2t += inputRegister_3 * weightsRegister;
            outputRegister_2u += inputRegister_4 * weightsRegister;
            outputRegister_2v += inputRegister_5 * weightsRegister;
            weightsRegister = weightsPtr[(weightsIdx + inputChannelIdx) + 5600];
            outputRegister_2w += inputRegister * weightsRegister;
            outputRegister_2x += inputRegister_0 * weightsRegister;
            outputRegister_2y += inputRegister_1 * weightsRegister;
            outputRegister_2z += inputRegister_2 * weightsRegister;
            outputRegister_30 += inputRegister_3 * weightsRegister;
            outputRegister_31 += inputRegister_4 * weightsRegister;
            outputRegister_32 += inputRegister_5 * weightsRegister;
          }

          weightsIdx += 16;
          stm32_B.inputBufferIdx3 += 16;
        }

        stm32_B.inputBufferIdx2 += 512;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 784] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 785] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 786] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 787] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 788] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 789] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 790] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1568] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1569] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1570] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1571] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1572] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1573] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1574] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2352] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2353] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2354] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2355] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2356] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2357] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2358] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3136] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3137] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3138] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3139] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3140] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3141] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3142] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3920] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3921] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3922] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3923] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3924] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3925] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3926] = outputRegister_14;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4704] = outputRegister_15;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4705] = outputRegister_16;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4706] = outputRegister_17;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4707] = outputRegister_18;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4708] = outputRegister_19;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4709] = outputRegister_1a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4710] = outputRegister_1b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5488] = outputRegister_1c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5489] = outputRegister_1d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5490] = outputRegister_1e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5491] = outputRegister_1f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5492] = outputRegister_1g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5493] = outputRegister_1h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5494] = outputRegister_1i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6272] = outputRegister_1j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6273] = outputRegister_1k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6274] = outputRegister_1l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6275] = outputRegister_1m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6276] = outputRegister_1n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6277] = outputRegister_1o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6278] = outputRegister_1p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7056] = outputRegister_1q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7057] = outputRegister_1r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7058] = outputRegister_1s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7059] = outputRegister_1t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7060] = outputRegister_1u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7061] = outputRegister_1v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7062] = outputRegister_1w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7840] = outputRegister_1x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7841] = outputRegister_1y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7842] = outputRegister_1z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7843] = outputRegister_20;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7844] = outputRegister_21;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7845] = outputRegister_22;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7846] = outputRegister_23;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8624] = outputRegister_24;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8625] = outputRegister_25;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8626] = outputRegister_26;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8627] = outputRegister_27;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8628] = outputRegister_28;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8629] = outputRegister_29;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8630] = outputRegister_2a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9408] = outputRegister_2b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9409] = outputRegister_2c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9410] = outputRegister_2d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9411] = outputRegister_2e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9412] = outputRegister_2f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9413] = outputRegister_2g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9414] = outputRegister_2h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10192] = outputRegister_2i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10193] = outputRegister_2j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10194] = outputRegister_2k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10195] = outputRegister_2l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10196] = outputRegister_2m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10197] = outputRegister_2n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10198] = outputRegister_2o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10976] = outputRegister_2p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10977] = outputRegister_2q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10978] = outputRegister_2r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10979] = outputRegister_2s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10980] = outputRegister_2t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10981] = outputRegister_2u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10982] = outputRegister_2v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11760] = outputRegister_2w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11761] = outputRegister_2x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11762] = outputRegister_2y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11763] = outputRegister_2z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11764] = outputRegister_30;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11765] = outputRegister_31;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11766] = outputRegister_32;
      stm32_B.inputBufferIdx1 += 112;
    }
  }
}

static void stm32_convolution_dieqb(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias)
{
  static real32_T inputScratchpadBuffer[16384];
  static real32_T outputScratchpadBuffer[784];
  static boolean_T bufferInitialized;
  real32_T *elemRefOutputBufferVar;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, 65536U);
    bufferInitialized = true;
  }

  memset(&outputScratchpadBuffer[0], 0, 3136U);
  for (stm32_B.bufferChannelMiniblockIdx = 1; stm32_B.bufferChannelMiniblockIdx <
       2; stm32_B.bufferChannelMiniblockIdx++) {
    for (stm32_B.fusedInputWidthAndHeightIdx = 0;
         stm32_B.fusedInputWidthAndHeightIdx < 784;
         stm32_B.fusedInputWidthAndHeightIdx++) {
      stm32_B.inputWidthIdx = div_nde_s32_floor
        (stm32_B.fusedInputWidthAndHeightIdx, 28);
      stm32_B.inputChannelMiniblockBaseIdx = stm32_B.fusedInputWidthAndHeightIdx
        % 28 + stm32_B.inputWidthIdx * 28;
      stm32_B.inputScratchpadBufferBaseIdx =
        (((stm32_B.fusedInputWidthAndHeightIdx % 28) << 4) +
         (stm32_B.inputWidthIdx << 9)) + 1056;
      for (stm32_B.inputWidthIdx = 1; stm32_B.inputWidthIdx < 2;
           stm32_B.inputWidthIdx++) {
        inputScratchpadBuffer[stm32_B.inputScratchpadBufferBaseIdx] =
          inputTensor[stm32_B.inputChannelMiniblockBaseIdx];
      }
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx = 0; stm32_B.bufferChannelMiniblockIdx <
       28; stm32_B.bufferChannelMiniblockIdx++) {
    stm32_B.fusedInputWidthAndHeightIdx = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx, 28);
    stm32_B.inputWidthIdx = stm32_B.fusedInputWidthAndHeightIdx * 6400;
    outputChannelTailCase = (stm32_B.fusedInputWidthAndHeightIdx == 0);
    stm32_B.inputChannelMiniblockBaseIdx = stm32_B.bufferChannelMiniblockIdx %
      28 * 28 + stm32_B.fusedInputWidthAndHeightIdx * 12544;
    stm32_B.inputScratchpadBufferBaseIdx = (stm32_B.bufferChannelMiniblockIdx %
      28) << 9;
    for (stm32_B.fusedInputWidthAndHeightIdx = 1;
         stm32_B.fusedInputWidthAndHeightIdx < 2;
         stm32_B.fusedInputWidthAndHeightIdx++) {
      stm32_convolutionKernel_dieqb
        (&inputScratchpadBuffer[stm32_B.inputScratchpadBufferBaseIdx],
         &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx],
         &weights[stm32_B.inputWidthIdx], outputChannelTailCase);
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx = 0; stm32_B.bufferChannelMiniblockIdx <
       784; stm32_B.bufferChannelMiniblockIdx++) {
    stm32_B.fusedInputWidthAndHeightIdx = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx, 784);
    stm32_B.biasRegister = bias[stm32_B.fusedInputWidthAndHeightIdx];
    stm32_B.inputChannelMiniblockBaseIdx = stm32_B.bufferChannelMiniblockIdx %
      784;
    stm32_B.inputWidthIdx = stm32_B.fusedInputWidthAndHeightIdx * 784 +
      stm32_B.inputChannelMiniblockBaseIdx;
    stm32_B.inputChannelMiniblockBaseIdx += stm32_B.fusedInputWidthAndHeightIdx *
      784;
    elemRefOutputBufferVar =
      &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx];
    stm32_B.biasRegister += *elemRefOutputBufferVar;
    if (stm32_B.biasRegister >= 0.0F) {
      *elemRefOutputBufferVar = stm32_B.biasRegister;
    } else {
      *elemRefOutputBufferVar = 0.0F;
    }

    for (stm32_B.fusedInputWidthAndHeightIdx = 1;
         stm32_B.fusedInputWidthAndHeightIdx < 2;
         stm32_B.fusedInputWidthAndHeightIdx++) {
      outputTensor[stm32_B.inputWidthIdx] =
        outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx];
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimizedCo_aiel1da(const real32_T layer_Weights[400],
  const real32_T X[784], real32_T Z[784])
{
  stm32_B.biasReformatted_gu = 0.490374774F;
  stm32_convolution_dieqb(&X[0], &Z[0], &layer_Weights[0],
    &stm32_B.biasReformatted_gu);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivation_pred_hu(const real32_T X[784], real32_T Z
  [784])
{
  static const real32_T b[400] = { -1.32005704E-8F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -2.36245032E-8F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -1.36987053E-8F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -2.55637422E-9F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -1.06847886E-9F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -4.59565612E-8F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 5.13903728E-7F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 9.56024223E-7F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -9.9052011E-9F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -9.14016751E-10F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -2.37590587E-8F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.42172019E-6F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 2.54471547E-6F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -3.53112029E-8F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -3.00057312E-9F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -2.21568452E-9F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -4.55701965E-9F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -1.37043132E-8F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -5.47904255E-9F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -1.07524223E-9F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -5.76438175E-10F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -1.34986222E-9F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -1.99567629E-9F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -6.42485676E-10F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -1.93340718E-10F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  conv2dDirectOptimizedCo_aiel1da(b, X, Z);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void st_MaxPooling2DLayer_predict_no(const real32_T X[29792], real32_T Z
  [29792])
{
  int32_T b_filterWidthIdx;
  int32_T inputWidthIdx;
  int32_T outChannelIdx;
  int32_T outHeightIdx;
  int32_T outWidthIdx;
  real32_T opValue;
  real32_T y;
  for (outChannelIdx = 0; outChannelIdx < 38; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 28; outWidthIdx++) {
      for (outHeightIdx = 0; outHeightIdx < 28; outHeightIdx++) {
        opValue = -3.402823466E+38F;
        if ((outHeightIdx > 0) && (outWidthIdx > 0) && (outHeightIdx + 3 <= 28) &&
            (outWidthIdx + 3 <= 28)) {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = (((b_filterWidthIdx + outWidthIdx) - 1) * 28 +
                             outHeightIdx) + 784 * outChannelIdx;
            y = X[inputWidthIdx - 1];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            y = X[inputWidthIdx];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            y = X[inputWidthIdx + 1];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }
          }
        } else {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = b_filterWidthIdx + outWidthIdx;
            if ((outHeightIdx > 0) && (inputWidthIdx > 0) && (inputWidthIdx <=
                 28)) {
              y = X[(((inputWidthIdx - 1) * 28 + outHeightIdx) + 784 *
                     outChannelIdx) - 1];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            if ((inputWidthIdx > 0) && (inputWidthIdx <= 28)) {
              y = X[((inputWidthIdx - 1) * 28 + outHeightIdx) + 784 *
                outChannelIdx];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            if ((inputWidthIdx > 0) && (outHeightIdx + 2 <= 28) &&
                (inputWidthIdx <= 28)) {
              y = X[(((inputWidthIdx - 1) * 28 + outHeightIdx) + 784 *
                     outChannelIdx) + 1];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }
          }
        }

        Z[(outHeightIdx + 28 * outWidthIdx) + 784 * outChannelIdx] = opValue;
      }
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimizedC_aiel1da3(const real32_T layer_Weights[48],
  const real32_T X[29792], real32_T Z[784])
{
  stm32_B.biasReformatted_g = 0.312850654F;
  stm32_convolution_die(&X[0], &Z[0], &layer_Weights[0],
                        &stm32_B.biasReformatted_g);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivation_pre_hur(const real32_T X[29792], real32_T Z
  [784])
{
  static const real32_T b[48] = { 0.114729092F, 0.133482754F, 0.109935008F,
    0.0304809269F, 0.0504614376F, 0.0764774457F, 0.11326047F, 0.0858073831F,
    0.0407040864F, 0.0998663902F, 0.119294263F, 0.0551618449F, 0.09314733F,
    0.093190141F, 0.0947773755F, 0.0654770657F, 0.103891172F, 0.0480261259F,
    0.149237543F, 0.106946766F, 0.291970551F, 0.147465348F, 0.0484447069F,
    0.106564231F, 0.0638550445F, 0.0935613066F, 0.00785475597F, 0.0631369948F,
    0.0641623363F, 0.080103457F, 0.107201777F, 0.44154653F, 0.0773505941F,
    0.0790210515F, 0.126675621F, 0.0475001447F, 0.125338227F, 0.0951251835F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  conv2dDirectOptimizedC_aiel1da3(b, X, Z);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void stm32_cat(const real32_T varargin_1[784], const real32_T varargin_2
                      [784], const real32_T varargin_3[784], const real32_T
                      varargin_4[784], real32_T y[3136])
{
  int32_T j;
  for (j = 0; j < 784; j++) {
    y[j] = varargin_1[j];
    y[j + 784] = varargin_2[j];
    y[j + 1568] = varargin_3[j];
    y[j + 2352] = varargin_4[j];
  }
}

static void stm32_convolutionKernel_dieqbr(const real32_T *inputBufferPtr,
  real32_T *outputBufferPtr, const real32_T *weightsPtr, boolean_T
  outputChannelTailCase)
{
  int32_T inputBufferIdx1;
  int32_T inputChannelIdx;
  int32_T outputHeightBlockIdx;
  real32_T inputRegister;
  real32_T inputRegister_0;
  real32_T inputRegister_1;
  real32_T inputRegister_2;
  real32_T inputRegister_3;
  real32_T inputRegister_4;
  real32_T inputRegister_5;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_10;
  real32_T outputRegister_11;
  real32_T outputRegister_12;
  real32_T outputRegister_13;
  real32_T outputRegister_14;
  real32_T outputRegister_15;
  real32_T outputRegister_16;
  real32_T outputRegister_17;
  real32_T outputRegister_18;
  real32_T outputRegister_19;
  real32_T outputRegister_1a;
  real32_T outputRegister_1b;
  real32_T outputRegister_1c;
  real32_T outputRegister_1d;
  real32_T outputRegister_1e;
  real32_T outputRegister_1f;
  real32_T outputRegister_1g;
  real32_T outputRegister_1h;
  real32_T outputRegister_1i;
  real32_T outputRegister_1j;
  real32_T outputRegister_1k;
  real32_T outputRegister_1l;
  real32_T outputRegister_1m;
  real32_T outputRegister_1n;
  real32_T outputRegister_1o;
  real32_T outputRegister_1p;
  real32_T outputRegister_1q;
  real32_T outputRegister_1r;
  real32_T outputRegister_1s;
  real32_T outputRegister_1t;
  real32_T outputRegister_1u;
  real32_T outputRegister_1v;
  real32_T outputRegister_1w;
  real32_T outputRegister_1x;
  real32_T outputRegister_1y;
  real32_T outputRegister_1z;
  real32_T outputRegister_2;
  real32_T outputRegister_20;
  real32_T outputRegister_21;
  real32_T outputRegister_22;
  real32_T outputRegister_23;
  real32_T outputRegister_24;
  real32_T outputRegister_25;
  real32_T outputRegister_26;
  real32_T outputRegister_27;
  real32_T outputRegister_28;
  real32_T outputRegister_29;
  real32_T outputRegister_2a;
  real32_T outputRegister_2b;
  real32_T outputRegister_2c;
  real32_T outputRegister_2d;
  real32_T outputRegister_2e;
  real32_T outputRegister_2f;
  real32_T outputRegister_2g;
  real32_T outputRegister_2h;
  real32_T outputRegister_2i;
  real32_T outputRegister_2j;
  real32_T outputRegister_2k;
  real32_T outputRegister_2l;
  real32_T outputRegister_2m;
  real32_T outputRegister_2n;
  real32_T outputRegister_2o;
  real32_T outputRegister_2p;
  real32_T outputRegister_2q;
  real32_T outputRegister_2r;
  real32_T outputRegister_2s;
  real32_T outputRegister_2t;
  real32_T outputRegister_2u;
  real32_T outputRegister_2v;
  real32_T outputRegister_2w;
  real32_T outputRegister_2x;
  real32_T outputRegister_2y;
  real32_T outputRegister_2z;
  real32_T outputRegister_3;
  real32_T outputRegister_30;
  real32_T outputRegister_31;
  real32_T outputRegister_32;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  real32_T outputRegister_f;
  real32_T outputRegister_g;
  real32_T outputRegister_h;
  real32_T outputRegister_i;
  real32_T outputRegister_j;
  real32_T outputRegister_k;
  real32_T outputRegister_l;
  real32_T outputRegister_m;
  real32_T outputRegister_n;
  real32_T outputRegister_o;
  real32_T outputRegister_p;
  real32_T outputRegister_q;
  real32_T outputRegister_r;
  real32_T outputRegister_s;
  real32_T outputRegister_t;
  real32_T outputRegister_u;
  real32_T outputRegister_v;
  real32_T outputRegister_w;
  real32_T outputRegister_x;
  real32_T outputRegister_y;
  real32_T outputRegister_z;
  real32_T weightsRegister;
  if (outputChannelTailCase) {
    inputBufferIdx1 = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 4;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
        inputRegister = inputBufferPtr[inputBufferIdx1 + inputChannelIdx];
        inputRegister_0 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          16];
        inputRegister_1 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          32];
        inputRegister_2 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          48];
        inputRegister_3 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          64];
        inputRegister_4 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          80];
        inputRegister_5 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          96];
        weightsRegister = weightsPtr[inputChannelIdx];
        outputRegister += inputRegister * weightsRegister;
        outputRegister_0 += inputRegister_0 * weightsRegister;
        outputRegister_1 += inputRegister_1 * weightsRegister;
        outputRegister_2 += inputRegister_2 * weightsRegister;
        outputRegister_3 += inputRegister_3 * weightsRegister;
        outputRegister_4 += inputRegister_4 * weightsRegister;
        outputRegister_5 += inputRegister_5 * weightsRegister;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      inputBufferIdx1 += 112;
    }
  } else {
    inputBufferIdx1 = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 4;
         outputHeightBlockIdx++) {
      outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
      outputRegister_0 = outputBufferPtr[outputHeightBlockIdx * 7 + 1];
      outputRegister_1 = outputBufferPtr[outputHeightBlockIdx * 7 + 2];
      outputRegister_2 = outputBufferPtr[outputHeightBlockIdx * 7 + 3];
      outputRegister_3 = outputBufferPtr[outputHeightBlockIdx * 7 + 4];
      outputRegister_4 = outputBufferPtr[outputHeightBlockIdx * 7 + 5];
      outputRegister_5 = outputBufferPtr[outputHeightBlockIdx * 7 + 6];
      outputRegister_6 = outputBufferPtr[outputHeightBlockIdx * 7 + 784];
      outputRegister_7 = outputBufferPtr[outputHeightBlockIdx * 7 + 785];
      outputRegister_8 = outputBufferPtr[outputHeightBlockIdx * 7 + 786];
      outputRegister_9 = outputBufferPtr[outputHeightBlockIdx * 7 + 787];
      outputRegister_a = outputBufferPtr[outputHeightBlockIdx * 7 + 788];
      outputRegister_b = outputBufferPtr[outputHeightBlockIdx * 7 + 789];
      outputRegister_c = outputBufferPtr[outputHeightBlockIdx * 7 + 790];
      outputRegister_d = outputBufferPtr[outputHeightBlockIdx * 7 + 1568];
      outputRegister_e = outputBufferPtr[outputHeightBlockIdx * 7 + 1569];
      outputRegister_f = outputBufferPtr[outputHeightBlockIdx * 7 + 1570];
      outputRegister_g = outputBufferPtr[outputHeightBlockIdx * 7 + 1571];
      outputRegister_h = outputBufferPtr[outputHeightBlockIdx * 7 + 1572];
      outputRegister_i = outputBufferPtr[outputHeightBlockIdx * 7 + 1573];
      outputRegister_j = outputBufferPtr[outputHeightBlockIdx * 7 + 1574];
      outputRegister_k = outputBufferPtr[outputHeightBlockIdx * 7 + 2352];
      outputRegister_l = outputBufferPtr[outputHeightBlockIdx * 7 + 2353];
      outputRegister_m = outputBufferPtr[outputHeightBlockIdx * 7 + 2354];
      outputRegister_n = outputBufferPtr[outputHeightBlockIdx * 7 + 2355];
      outputRegister_o = outputBufferPtr[outputHeightBlockIdx * 7 + 2356];
      outputRegister_p = outputBufferPtr[outputHeightBlockIdx * 7 + 2357];
      outputRegister_q = outputBufferPtr[outputHeightBlockIdx * 7 + 2358];
      outputRegister_r = outputBufferPtr[outputHeightBlockIdx * 7 + 3136];
      outputRegister_s = outputBufferPtr[outputHeightBlockIdx * 7 + 3137];
      outputRegister_t = outputBufferPtr[outputHeightBlockIdx * 7 + 3138];
      outputRegister_u = outputBufferPtr[outputHeightBlockIdx * 7 + 3139];
      outputRegister_v = outputBufferPtr[outputHeightBlockIdx * 7 + 3140];
      outputRegister_w = outputBufferPtr[outputHeightBlockIdx * 7 + 3141];
      outputRegister_x = outputBufferPtr[outputHeightBlockIdx * 7 + 3142];
      outputRegister_y = outputBufferPtr[outputHeightBlockIdx * 7 + 3920];
      outputRegister_z = outputBufferPtr[outputHeightBlockIdx * 7 + 3921];
      outputRegister_10 = outputBufferPtr[outputHeightBlockIdx * 7 + 3922];
      outputRegister_11 = outputBufferPtr[outputHeightBlockIdx * 7 + 3923];
      outputRegister_12 = outputBufferPtr[outputHeightBlockIdx * 7 + 3924];
      outputRegister_13 = outputBufferPtr[outputHeightBlockIdx * 7 + 3925];
      outputRegister_14 = outputBufferPtr[outputHeightBlockIdx * 7 + 3926];
      outputRegister_15 = outputBufferPtr[outputHeightBlockIdx * 7 + 4704];
      outputRegister_16 = outputBufferPtr[outputHeightBlockIdx * 7 + 4705];
      outputRegister_17 = outputBufferPtr[outputHeightBlockIdx * 7 + 4706];
      outputRegister_18 = outputBufferPtr[outputHeightBlockIdx * 7 + 4707];
      outputRegister_19 = outputBufferPtr[outputHeightBlockIdx * 7 + 4708];
      outputRegister_1a = outputBufferPtr[outputHeightBlockIdx * 7 + 4709];
      outputRegister_1b = outputBufferPtr[outputHeightBlockIdx * 7 + 4710];
      outputRegister_1c = outputBufferPtr[outputHeightBlockIdx * 7 + 5488];
      outputRegister_1d = outputBufferPtr[outputHeightBlockIdx * 7 + 5489];
      outputRegister_1e = outputBufferPtr[outputHeightBlockIdx * 7 + 5490];
      outputRegister_1f = outputBufferPtr[outputHeightBlockIdx * 7 + 5491];
      outputRegister_1g = outputBufferPtr[outputHeightBlockIdx * 7 + 5492];
      outputRegister_1h = outputBufferPtr[outputHeightBlockIdx * 7 + 5493];
      outputRegister_1i = outputBufferPtr[outputHeightBlockIdx * 7 + 5494];
      outputRegister_1j = outputBufferPtr[outputHeightBlockIdx * 7 + 6272];
      outputRegister_1k = outputBufferPtr[outputHeightBlockIdx * 7 + 6273];
      outputRegister_1l = outputBufferPtr[outputHeightBlockIdx * 7 + 6274];
      outputRegister_1m = outputBufferPtr[outputHeightBlockIdx * 7 + 6275];
      outputRegister_1n = outputBufferPtr[outputHeightBlockIdx * 7 + 6276];
      outputRegister_1o = outputBufferPtr[outputHeightBlockIdx * 7 + 6277];
      outputRegister_1p = outputBufferPtr[outputHeightBlockIdx * 7 + 6278];
      outputRegister_1q = outputBufferPtr[outputHeightBlockIdx * 7 + 7056];
      outputRegister_1r = outputBufferPtr[outputHeightBlockIdx * 7 + 7057];
      outputRegister_1s = outputBufferPtr[outputHeightBlockIdx * 7 + 7058];
      outputRegister_1t = outputBufferPtr[outputHeightBlockIdx * 7 + 7059];
      outputRegister_1u = outputBufferPtr[outputHeightBlockIdx * 7 + 7060];
      outputRegister_1v = outputBufferPtr[outputHeightBlockIdx * 7 + 7061];
      outputRegister_1w = outputBufferPtr[outputHeightBlockIdx * 7 + 7062];
      outputRegister_1x = outputBufferPtr[outputHeightBlockIdx * 7 + 7840];
      outputRegister_1y = outputBufferPtr[outputHeightBlockIdx * 7 + 7841];
      outputRegister_1z = outputBufferPtr[outputHeightBlockIdx * 7 + 7842];
      outputRegister_20 = outputBufferPtr[outputHeightBlockIdx * 7 + 7843];
      outputRegister_21 = outputBufferPtr[outputHeightBlockIdx * 7 + 7844];
      outputRegister_22 = outputBufferPtr[outputHeightBlockIdx * 7 + 7845];
      outputRegister_23 = outputBufferPtr[outputHeightBlockIdx * 7 + 7846];
      outputRegister_24 = outputBufferPtr[outputHeightBlockIdx * 7 + 8624];
      outputRegister_25 = outputBufferPtr[outputHeightBlockIdx * 7 + 8625];
      outputRegister_26 = outputBufferPtr[outputHeightBlockIdx * 7 + 8626];
      outputRegister_27 = outputBufferPtr[outputHeightBlockIdx * 7 + 8627];
      outputRegister_28 = outputBufferPtr[outputHeightBlockIdx * 7 + 8628];
      outputRegister_29 = outputBufferPtr[outputHeightBlockIdx * 7 + 8629];
      outputRegister_2a = outputBufferPtr[outputHeightBlockIdx * 7 + 8630];
      outputRegister_2b = outputBufferPtr[outputHeightBlockIdx * 7 + 9408];
      outputRegister_2c = outputBufferPtr[outputHeightBlockIdx * 7 + 9409];
      outputRegister_2d = outputBufferPtr[outputHeightBlockIdx * 7 + 9410];
      outputRegister_2e = outputBufferPtr[outputHeightBlockIdx * 7 + 9411];
      outputRegister_2f = outputBufferPtr[outputHeightBlockIdx * 7 + 9412];
      outputRegister_2g = outputBufferPtr[outputHeightBlockIdx * 7 + 9413];
      outputRegister_2h = outputBufferPtr[outputHeightBlockIdx * 7 + 9414];
      outputRegister_2i = outputBufferPtr[outputHeightBlockIdx * 7 + 10192];
      outputRegister_2j = outputBufferPtr[outputHeightBlockIdx * 7 + 10193];
      outputRegister_2k = outputBufferPtr[outputHeightBlockIdx * 7 + 10194];
      outputRegister_2l = outputBufferPtr[outputHeightBlockIdx * 7 + 10195];
      outputRegister_2m = outputBufferPtr[outputHeightBlockIdx * 7 + 10196];
      outputRegister_2n = outputBufferPtr[outputHeightBlockIdx * 7 + 10197];
      outputRegister_2o = outputBufferPtr[outputHeightBlockIdx * 7 + 10198];
      outputRegister_2p = outputBufferPtr[outputHeightBlockIdx * 7 + 10976];
      outputRegister_2q = outputBufferPtr[outputHeightBlockIdx * 7 + 10977];
      outputRegister_2r = outputBufferPtr[outputHeightBlockIdx * 7 + 10978];
      outputRegister_2s = outputBufferPtr[outputHeightBlockIdx * 7 + 10979];
      outputRegister_2t = outputBufferPtr[outputHeightBlockIdx * 7 + 10980];
      outputRegister_2u = outputBufferPtr[outputHeightBlockIdx * 7 + 10981];
      outputRegister_2v = outputBufferPtr[outputHeightBlockIdx * 7 + 10982];
      outputRegister_2w = outputBufferPtr[outputHeightBlockIdx * 7 + 11760];
      outputRegister_2x = outputBufferPtr[outputHeightBlockIdx * 7 + 11761];
      outputRegister_2y = outputBufferPtr[outputHeightBlockIdx * 7 + 11762];
      outputRegister_2z = outputBufferPtr[outputHeightBlockIdx * 7 + 11763];
      outputRegister_30 = outputBufferPtr[outputHeightBlockIdx * 7 + 11764];
      outputRegister_31 = outputBufferPtr[outputHeightBlockIdx * 7 + 11765];
      outputRegister_32 = outputBufferPtr[outputHeightBlockIdx * 7 + 11766];
      for (inputChannelIdx = 0; inputChannelIdx < 16; inputChannelIdx++) {
        inputRegister = inputBufferPtr[inputBufferIdx1 + inputChannelIdx];
        inputRegister_0 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          16];
        inputRegister_1 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          32];
        inputRegister_2 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          48];
        inputRegister_3 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          64];
        inputRegister_4 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          80];
        inputRegister_5 = inputBufferPtr[(inputBufferIdx1 + inputChannelIdx) +
          96];
        weightsRegister = weightsPtr[inputChannelIdx];
        outputRegister += inputRegister * weightsRegister;
        outputRegister_0 += inputRegister_0 * weightsRegister;
        outputRegister_1 += inputRegister_1 * weightsRegister;
        outputRegister_2 += inputRegister_2 * weightsRegister;
        outputRegister_3 += inputRegister_3 * weightsRegister;
        outputRegister_4 += inputRegister_4 * weightsRegister;
        outputRegister_5 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 16];
        outputRegister_6 += inputRegister * weightsRegister;
        outputRegister_7 += inputRegister_0 * weightsRegister;
        outputRegister_8 += inputRegister_1 * weightsRegister;
        outputRegister_9 += inputRegister_2 * weightsRegister;
        outputRegister_a += inputRegister_3 * weightsRegister;
        outputRegister_b += inputRegister_4 * weightsRegister;
        outputRegister_c += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 32];
        outputRegister_d += inputRegister * weightsRegister;
        outputRegister_e += inputRegister_0 * weightsRegister;
        outputRegister_f += inputRegister_1 * weightsRegister;
        outputRegister_g += inputRegister_2 * weightsRegister;
        outputRegister_h += inputRegister_3 * weightsRegister;
        outputRegister_i += inputRegister_4 * weightsRegister;
        outputRegister_j += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 48];
        outputRegister_k += inputRegister * weightsRegister;
        outputRegister_l += inputRegister_0 * weightsRegister;
        outputRegister_m += inputRegister_1 * weightsRegister;
        outputRegister_n += inputRegister_2 * weightsRegister;
        outputRegister_o += inputRegister_3 * weightsRegister;
        outputRegister_p += inputRegister_4 * weightsRegister;
        outputRegister_q += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 64];
        outputRegister_r += inputRegister * weightsRegister;
        outputRegister_s += inputRegister_0 * weightsRegister;
        outputRegister_t += inputRegister_1 * weightsRegister;
        outputRegister_u += inputRegister_2 * weightsRegister;
        outputRegister_v += inputRegister_3 * weightsRegister;
        outputRegister_w += inputRegister_4 * weightsRegister;
        outputRegister_x += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 80];
        outputRegister_y += inputRegister * weightsRegister;
        outputRegister_z += inputRegister_0 * weightsRegister;
        outputRegister_10 += inputRegister_1 * weightsRegister;
        outputRegister_11 += inputRegister_2 * weightsRegister;
        outputRegister_12 += inputRegister_3 * weightsRegister;
        outputRegister_13 += inputRegister_4 * weightsRegister;
        outputRegister_14 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 96];
        outputRegister_15 += inputRegister * weightsRegister;
        outputRegister_16 += inputRegister_0 * weightsRegister;
        outputRegister_17 += inputRegister_1 * weightsRegister;
        outputRegister_18 += inputRegister_2 * weightsRegister;
        outputRegister_19 += inputRegister_3 * weightsRegister;
        outputRegister_1a += inputRegister_4 * weightsRegister;
        outputRegister_1b += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 112];
        outputRegister_1c += inputRegister * weightsRegister;
        outputRegister_1d += inputRegister_0 * weightsRegister;
        outputRegister_1e += inputRegister_1 * weightsRegister;
        outputRegister_1f += inputRegister_2 * weightsRegister;
        outputRegister_1g += inputRegister_3 * weightsRegister;
        outputRegister_1h += inputRegister_4 * weightsRegister;
        outputRegister_1i += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 128];
        outputRegister_1j += inputRegister * weightsRegister;
        outputRegister_1k += inputRegister_0 * weightsRegister;
        outputRegister_1l += inputRegister_1 * weightsRegister;
        outputRegister_1m += inputRegister_2 * weightsRegister;
        outputRegister_1n += inputRegister_3 * weightsRegister;
        outputRegister_1o += inputRegister_4 * weightsRegister;
        outputRegister_1p += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 144];
        outputRegister_1q += inputRegister * weightsRegister;
        outputRegister_1r += inputRegister_0 * weightsRegister;
        outputRegister_1s += inputRegister_1 * weightsRegister;
        outputRegister_1t += inputRegister_2 * weightsRegister;
        outputRegister_1u += inputRegister_3 * weightsRegister;
        outputRegister_1v += inputRegister_4 * weightsRegister;
        outputRegister_1w += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 160];
        outputRegister_1x += inputRegister * weightsRegister;
        outputRegister_1y += inputRegister_0 * weightsRegister;
        outputRegister_1z += inputRegister_1 * weightsRegister;
        outputRegister_20 += inputRegister_2 * weightsRegister;
        outputRegister_21 += inputRegister_3 * weightsRegister;
        outputRegister_22 += inputRegister_4 * weightsRegister;
        outputRegister_23 += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 176];
        outputRegister_24 += inputRegister * weightsRegister;
        outputRegister_25 += inputRegister_0 * weightsRegister;
        outputRegister_26 += inputRegister_1 * weightsRegister;
        outputRegister_27 += inputRegister_2 * weightsRegister;
        outputRegister_28 += inputRegister_3 * weightsRegister;
        outputRegister_29 += inputRegister_4 * weightsRegister;
        outputRegister_2a += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 192];
        outputRegister_2b += inputRegister * weightsRegister;
        outputRegister_2c += inputRegister_0 * weightsRegister;
        outputRegister_2d += inputRegister_1 * weightsRegister;
        outputRegister_2e += inputRegister_2 * weightsRegister;
        outputRegister_2f += inputRegister_3 * weightsRegister;
        outputRegister_2g += inputRegister_4 * weightsRegister;
        outputRegister_2h += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 208];
        outputRegister_2i += inputRegister * weightsRegister;
        outputRegister_2j += inputRegister_0 * weightsRegister;
        outputRegister_2k += inputRegister_1 * weightsRegister;
        outputRegister_2l += inputRegister_2 * weightsRegister;
        outputRegister_2m += inputRegister_3 * weightsRegister;
        outputRegister_2n += inputRegister_4 * weightsRegister;
        outputRegister_2o += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 224];
        outputRegister_2p += inputRegister * weightsRegister;
        outputRegister_2q += inputRegister_0 * weightsRegister;
        outputRegister_2r += inputRegister_1 * weightsRegister;
        outputRegister_2s += inputRegister_2 * weightsRegister;
        outputRegister_2t += inputRegister_3 * weightsRegister;
        outputRegister_2u += inputRegister_4 * weightsRegister;
        outputRegister_2v += inputRegister_5 * weightsRegister;
        weightsRegister = weightsPtr[inputChannelIdx + 240];
        outputRegister_2w += inputRegister * weightsRegister;
        outputRegister_2x += inputRegister_0 * weightsRegister;
        outputRegister_2y += inputRegister_1 * weightsRegister;
        outputRegister_2z += inputRegister_2 * weightsRegister;
        outputRegister_30 += inputRegister_3 * weightsRegister;
        outputRegister_31 += inputRegister_4 * weightsRegister;
        outputRegister_32 += inputRegister_5 * weightsRegister;
      }

      outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1] = outputRegister_0;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2] = outputRegister_1;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3] = outputRegister_2;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4] = outputRegister_3;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5] = outputRegister_4;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6] = outputRegister_5;
      outputBufferPtr[outputHeightBlockIdx * 7 + 784] = outputRegister_6;
      outputBufferPtr[outputHeightBlockIdx * 7 + 785] = outputRegister_7;
      outputBufferPtr[outputHeightBlockIdx * 7 + 786] = outputRegister_8;
      outputBufferPtr[outputHeightBlockIdx * 7 + 787] = outputRegister_9;
      outputBufferPtr[outputHeightBlockIdx * 7 + 788] = outputRegister_a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 789] = outputRegister_b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 790] = outputRegister_c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1568] = outputRegister_d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1569] = outputRegister_e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1570] = outputRegister_f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1571] = outputRegister_g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1572] = outputRegister_h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1573] = outputRegister_i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 1574] = outputRegister_j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2352] = outputRegister_k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2353] = outputRegister_l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2354] = outputRegister_m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2355] = outputRegister_n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2356] = outputRegister_o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2357] = outputRegister_p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 2358] = outputRegister_q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3136] = outputRegister_r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3137] = outputRegister_s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3138] = outputRegister_t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3139] = outputRegister_u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3140] = outputRegister_v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3141] = outputRegister_w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3142] = outputRegister_x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3920] = outputRegister_y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3921] = outputRegister_z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3922] = outputRegister_10;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3923] = outputRegister_11;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3924] = outputRegister_12;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3925] = outputRegister_13;
      outputBufferPtr[outputHeightBlockIdx * 7 + 3926] = outputRegister_14;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4704] = outputRegister_15;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4705] = outputRegister_16;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4706] = outputRegister_17;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4707] = outputRegister_18;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4708] = outputRegister_19;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4709] = outputRegister_1a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 4710] = outputRegister_1b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5488] = outputRegister_1c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5489] = outputRegister_1d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5490] = outputRegister_1e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5491] = outputRegister_1f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5492] = outputRegister_1g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5493] = outputRegister_1h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 5494] = outputRegister_1i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6272] = outputRegister_1j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6273] = outputRegister_1k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6274] = outputRegister_1l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6275] = outputRegister_1m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6276] = outputRegister_1n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6277] = outputRegister_1o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 6278] = outputRegister_1p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7056] = outputRegister_1q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7057] = outputRegister_1r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7058] = outputRegister_1s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7059] = outputRegister_1t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7060] = outputRegister_1u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7061] = outputRegister_1v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7062] = outputRegister_1w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7840] = outputRegister_1x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7841] = outputRegister_1y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7842] = outputRegister_1z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7843] = outputRegister_20;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7844] = outputRegister_21;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7845] = outputRegister_22;
      outputBufferPtr[outputHeightBlockIdx * 7 + 7846] = outputRegister_23;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8624] = outputRegister_24;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8625] = outputRegister_25;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8626] = outputRegister_26;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8627] = outputRegister_27;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8628] = outputRegister_28;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8629] = outputRegister_29;
      outputBufferPtr[outputHeightBlockIdx * 7 + 8630] = outputRegister_2a;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9408] = outputRegister_2b;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9409] = outputRegister_2c;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9410] = outputRegister_2d;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9411] = outputRegister_2e;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9412] = outputRegister_2f;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9413] = outputRegister_2g;
      outputBufferPtr[outputHeightBlockIdx * 7 + 9414] = outputRegister_2h;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10192] = outputRegister_2i;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10193] = outputRegister_2j;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10194] = outputRegister_2k;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10195] = outputRegister_2l;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10196] = outputRegister_2m;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10197] = outputRegister_2n;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10198] = outputRegister_2o;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10976] = outputRegister_2p;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10977] = outputRegister_2q;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10978] = outputRegister_2r;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10979] = outputRegister_2s;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10980] = outputRegister_2t;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10981] = outputRegister_2u;
      outputBufferPtr[outputHeightBlockIdx * 7 + 10982] = outputRegister_2v;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11760] = outputRegister_2w;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11761] = outputRegister_2x;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11762] = outputRegister_2y;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11763] = outputRegister_2z;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11764] = outputRegister_30;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11765] = outputRegister_31;
      outputBufferPtr[outputHeightBlockIdx * 7 + 11766] = outputRegister_32;
      inputBufferIdx1 += 112;
    }
  }
}

static void stm32_convolution_dieqbr(const real32_T *inputTensor, real32_T
  *outputTensor, const real32_T *weights, const real32_T *bias)
{
  static real32_T inputScratchpadBuffer[12544];
  static real32_T outputScratchpadBuffer[784];
  static boolean_T bufferInitialized;
  int32_T inputScratchpadBufferBaseIdx;
  real32_T biasRegister;
  real32_T *elemRefOutputBufferVar;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, 50176U);
    bufferInitialized = true;
  }

  memset(&outputScratchpadBuffer[0], 0, 3136U);
  for (stm32_B.bufferChannelMiniblockIdx_p = 1;
       stm32_B.bufferChannelMiniblockIdx_p < 2;
       stm32_B.bufferChannelMiniblockIdx_p++) {
    for (stm32_B.fusedInputWidthAndHeightIdx_a = 0;
         stm32_B.fusedInputWidthAndHeightIdx_a < 784;
         stm32_B.fusedInputWidthAndHeightIdx_a++) {
      stm32_B.inputWidthIdx_e = div_nde_s32_floor
        (stm32_B.fusedInputWidthAndHeightIdx_a, 28);
      stm32_B.inputChannelMiniblockBaseIdx_ax =
        stm32_B.fusedInputWidthAndHeightIdx_a % 28 + stm32_B.inputWidthIdx_e *
        28;
      inputScratchpadBufferBaseIdx = ((stm32_B.fusedInputWidthAndHeightIdx_a %
        28) << 4) + stm32_B.inputWidthIdx_e * 448;
      for (stm32_B.inputWidthIdx_e = 1; stm32_B.inputWidthIdx_e < 5;
           stm32_B.inputWidthIdx_e++) {
        inputScratchpadBuffer[(inputScratchpadBufferBaseIdx +
          stm32_B.inputWidthIdx_e) - 1] = inputTensor[(stm32_B.inputWidthIdx_e -
          1) * 784 + stm32_B.inputChannelMiniblockBaseIdx_ax];
      }
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_p = 0;
       stm32_B.bufferChannelMiniblockIdx_p < 28;
       stm32_B.bufferChannelMiniblockIdx_p++) {
    stm32_B.fusedInputWidthAndHeightIdx_a = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_p, 28);
    stm32_B.inputWidthIdx_e = stm32_B.fusedInputWidthAndHeightIdx_a << 8;
    outputChannelTailCase = (stm32_B.fusedInputWidthAndHeightIdx_a == 0);
    stm32_B.inputChannelMiniblockBaseIdx_ax =
      stm32_B.bufferChannelMiniblockIdx_p % 28 * 28 +
      stm32_B.fusedInputWidthAndHeightIdx_a * 12544;
    inputScratchpadBufferBaseIdx = stm32_B.bufferChannelMiniblockIdx_p % 28 *
      448;
    for (stm32_B.fusedInputWidthAndHeightIdx_a = 1;
         stm32_B.fusedInputWidthAndHeightIdx_a < 2;
         stm32_B.fusedInputWidthAndHeightIdx_a++) {
      stm32_convolutionKernel_dieqbr
        (&inputScratchpadBuffer[inputScratchpadBufferBaseIdx],
         &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_ax],
         &weights[stm32_B.inputWidthIdx_e], outputChannelTailCase);
    }
  }

  for (stm32_B.bufferChannelMiniblockIdx_p = 0;
       stm32_B.bufferChannelMiniblockIdx_p < 784;
       stm32_B.bufferChannelMiniblockIdx_p++) {
    stm32_B.fusedInputWidthAndHeightIdx_a = div_nde_s32_floor
      (stm32_B.bufferChannelMiniblockIdx_p, 784);
    biasRegister = bias[stm32_B.fusedInputWidthAndHeightIdx_a];
    stm32_B.inputChannelMiniblockBaseIdx_ax =
      stm32_B.bufferChannelMiniblockIdx_p % 784;
    stm32_B.inputWidthIdx_e = stm32_B.fusedInputWidthAndHeightIdx_a * 784 +
      stm32_B.inputChannelMiniblockBaseIdx_ax;
    stm32_B.inputChannelMiniblockBaseIdx_ax +=
      stm32_B.fusedInputWidthAndHeightIdx_a * 784;
    elemRefOutputBufferVar =
      &outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_ax];
    biasRegister += *elemRefOutputBufferVar;
    if (biasRegister >= 0.0F) {
      *elemRefOutputBufferVar = biasRegister;
    } else {
      *elemRefOutputBufferVar = 0.0F;
    }

    for (stm32_B.fusedInputWidthAndHeightIdx_a = 1;
         stm32_B.fusedInputWidthAndHeightIdx_a < 2;
         stm32_B.fusedInputWidthAndHeightIdx_a++) {
      outputTensor[stm32_B.inputWidthIdx_e] =
        outputScratchpadBuffer[stm32_B.inputChannelMiniblockBaseIdx_ax];
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimized_aiel1da3p(const real32_T X[3136], real32_T Z
  [784])
{
  static const real32_T b[16] = { 0.248641431F, -0.057822451F, -0.0462505221F,
    0.340180486F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F };

  stm32_B.biasReformatted_d = -0.138215721F;
  stm32_convolution_dieqbr(&X[0], &Z[0], &b[0], &stm32_B.biasReformatted_d);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimize_aiel1da3pi(const real32_T layer_Weights[16],
  const real32_T X[3136], real32_T Z[784])
{
  stm32_B.biasReformatted_j = -0.0998230278F;
  stm32_convolution_dieqbr(&X[0], &Z[0], &layer_Weights[0],
    &stm32_B.biasReformatted_j);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivation_pr_hurc(const real32_T X[3136], real32_T Z
  [784])
{
  static const real32_T b[16] = { 0.030477237F, -0.019330781F, -0.0154159339F,
    0.36149013F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F };

  conv2dDirectOptimize_aiel1da3pi(b, X, Z);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimiz_aiel1da3piw(const real32_T layer_Weights[144],
  const real32_T X[784], real32_T Z[784])
{
  stm32_B.biasReformatted_c = -0.0767148659F;
  stm32_convolution_dieq(&X[0], &Z[0], &layer_Weights[0],
    &stm32_B.biasReformatted_c);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivation_p_hurcm(const real32_T X[784], real32_T Z
  [784])
{
  static const real32_T b[144] = { 0.110475771F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.12762776F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.12094187F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.113342337F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.129818842F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.124015741F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.099767074F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.116122194F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.109561712F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  conv2dDirectOptimiz_aiel1da3piw(b, X, Z);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptimi_aiel1da3piwz(const real32_T layer_Weights[16],
  const real32_T X[3136], real32_T Z[784])
{
  stm32_B.biasReformatted_l = 1.70566916F;
  stm32_convolution_dieqbr(&X[0], &Z[0], &layer_Weights[0],
    &stm32_B.biasReformatted_l);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivation__hurcml(const real32_T X[3136], real32_T Z
  [784])
{
  static const real32_T b[16] = { 0.000473966211F, 0.00100333872F,
    0.000602641434F, 0.000101572652F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  conv2dDirectOptimi_aiel1da3piwz(b, X, Z);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOptim_aiel1da3piwz0(const real32_T layer_Weights[400],
  const real32_T X[784], real32_T Z[784])
{
  stm32_B.biasReformatted = 0.61535418F;
  stm32_convolution_dieqb(&X[0], &Z[0], &layer_Weights[0],
    &stm32_B.biasReformatted);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivation_hurcmlu(const real32_T X[784], real32_T Z
  [784])
{
  static const real32_T b[400] = { -0.0120326215F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0132019855F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0144753959F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0131286541F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0120396772F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0131442053F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0143613666F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0156751443F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.01428058F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0131452428F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.014439865F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0156981386F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0170335863F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0156042622F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0144293457F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0131448079F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0143590691F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0156645887F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0142745776F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0131421546F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0119912317F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.013158272F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -0.0144278193F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0130843231F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    -0.0119983833F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  conv2dDirectOptim_aiel1da3piwz0(b, X, Z);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void s_MaxPooling2DLayer_predict_nor(const real32_T X[3136], real32_T Z
  [3136])
{
  int32_T b_filterWidthIdx;
  int32_T inputWidthIdx;
  int32_T outChannelIdx;
  int32_T outHeightIdx;
  int32_T outWidthIdx;
  real32_T opValue;
  real32_T y;
  for (outChannelIdx = 0; outChannelIdx < 4; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 28; outWidthIdx++) {
      for (outHeightIdx = 0; outHeightIdx < 28; outHeightIdx++) {
        opValue = -3.402823466E+38F;
        if ((outHeightIdx > 0) && (outWidthIdx > 0) && (outHeightIdx + 3 <= 28) &&
            (outWidthIdx + 3 <= 28)) {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = (((b_filterWidthIdx + outWidthIdx) - 1) * 28 +
                             outHeightIdx) + 784 * outChannelIdx;
            y = X[inputWidthIdx - 1];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            y = X[inputWidthIdx];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            y = X[inputWidthIdx + 1];
            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }
          }
        } else {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = b_filterWidthIdx + outWidthIdx;
            if ((outHeightIdx > 0) && (inputWidthIdx > 0) && (inputWidthIdx <=
                 28)) {
              y = X[(((inputWidthIdx - 1) * 28 + outHeightIdx) + 784 *
                     outChannelIdx) - 1];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            if ((inputWidthIdx > 0) && (inputWidthIdx <= 28)) {
              y = X[((inputWidthIdx - 1) * 28 + outHeightIdx) + 784 *
                outChannelIdx];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }

            if ((inputWidthIdx > 0) && (outHeightIdx + 2 <= 28) &&
                (inputWidthIdx <= 28)) {
              y = X[(((inputWidthIdx - 1) * 28 + outHeightIdx) + 784 *
                     outChannelIdx) + 1];
            } else {
              y = -3.402823466E+38F;
            }

            if ((!(opValue >= y)) && (!rtIsNaNF(y))) {
              opValue = y;
            }
          }
        }

        Z[(outHeightIdx + 28 * outWidthIdx) + 784 * outChannelIdx] = opValue;
      }
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void conv2dDirectOpti_aiel1da3piwz0d(const real32_T layer_Weights[16],
  const real32_T X[3136], real32_T Z[784])
{
  stm32_B.biasReformatted_n = 0.514739871F;
  stm32_convolution_dieqbr(&X[0], &Z[0], &layer_Weights[0],
    &stm32_B.biasReformatted_n);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void Convolution2DActivatio_hurcmlun(const real32_T X[3136], real32_T Z
  [784])
{
  static const real32_T b[16] = { 0.141171634F, 0.106922F, 0.0833272338F,
    -0.256924808F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F };

  conv2dDirectOpti_aiel1da3piwz0d(b, X, Z);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void s_AveragePooling2DLayer_predict(const real32_T X[3136], real32_T Z[4])
{
  int32_T filterHeightIdx;
  int32_T filterWidthIdx;
  int32_T outChannelIdx;
  real32_T opValue;
  for (outChannelIdx = 0; outChannelIdx < 4; outChannelIdx++) {
    opValue = 0.0F;
    for (filterWidthIdx = 0; filterWidthIdx < 28; filterWidthIdx++) {
      for (filterHeightIdx = 0; filterHeightIdx < 28; filterHeightIdx++) {
        opValue += X[(28 * filterWidthIdx + filterHeightIdx) + 784 *
          outChannelIdx];
      }
    }

    Z[outChannelIdx] = 0.00127551018F * opValue;
  }
}

static void stm32_microKernel_die(int32_T K, const real32_T *A, int32_T LDA,
  const real32_T *B, real32_T *C)
{
  int32_T A_idx;
  int32_T B_idx;
  int32_T k;
  real32_T a;
  real32_T b;
  real32_T c;
  A_idx = 0;
  B_idx = 0;
  c = C[0];
  for (k = 0; k < K; k++) {
    a = A[A_idx];
    b = B[B_idx];
    c += a * b;
    A_idx += LDA;
    B_idx++;
  }

  C[0] = c;
}

static void stm32_microKernel_di(int32_T K, const real32_T *A, int32_T LDA,
  const real32_T *B, real32_T *C)
{
  int32_T A_idx;
  int32_T B_idx;
  int32_T k;
  real32_T a;
  real32_T a_0;
  real32_T b;
  real32_T c;
  real32_T c_0;
  A_idx = 0;
  B_idx = 0;
  c = C[0];
  c_0 = C[1];
  for (k = 0; k < K; k++) {
    a = A[A_idx];
    a_0 = A[A_idx + 1];
    b = B[B_idx];
    c += a * b;
    c_0 += a_0 * b;
    A_idx += LDA;
    B_idx++;
  }

  C[0] = c;
  C[1] = c_0;
}

static void stm32_microKernel_d(int32_T K, const real32_T *A, int32_T LDA, const
  real32_T *B, int32_T LDB, real32_T *C, int32_T LDC)
{
  int32_T A_idx;
  int32_T B_idx;
  int32_T k;
  real32_T a;
  real32_T b;
  real32_T b_0;
  real32_T c;
  real32_T c_0;
  A_idx = 0;
  B_idx = 0;
  c = C[0];
  c_0 = C[LDC];
  for (k = 0; k < K; k++) {
    a = A[A_idx];
    b = B[B_idx];
    b_0 = B[B_idx + LDB];
    c += a * b;
    c_0 += a * b_0;
    A_idx += LDA;
    B_idx++;
  }

  C[0] = c;
  C[LDC] = c_0;
}

static void stm32_microKernel(int32_T K, const real32_T *A, int32_T LDA, const
  real32_T *B, int32_T LDB, real32_T *C, int32_T LDC)
{
  int32_T A_idx;
  int32_T B_idx;
  int32_T k;
  real32_T a;
  real32_T a_0;
  real32_T b;
  real32_T b_0;
  real32_T c;
  real32_T c_0;
  real32_T c_1;
  real32_T c_2;
  A_idx = 0;
  B_idx = 0;
  c = C[0];
  c_0 = C[1];
  c_1 = C[LDC];
  c_2 = C[LDC + 1];
  for (k = 0; k < K; k++) {
    a = A[A_idx];
    a_0 = A[A_idx + 1];
    b = B[B_idx];
    b_0 = B[B_idx + LDB];
    c += a * b;
    c_0 += a_0 * b;
    c_1 += a * b_0;
    c_2 += a_0 * b_0;
    A_idx += LDA;
    B_idx++;
  }

  C[0] = c;
  C[1] = c_0;
  C[LDC] = c_1;
  C[LDC + 1] = c_2;
}

static void stm32_macroKernel(int32_T M, int32_T K, int32_T N, const real32_T *A,
  int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C, int32_T LDC)
{
  int32_T A_idx;
  int32_T B_idx;
  int32_T C_idx;
  int32_T i;
  int32_T j;
  j = 0;
  B_idx = 0;
  while (j <= N - 2) {
    C_idx = LDC * j;
    i = 0;
    A_idx = 0;
    while (i <= M - 2) {
      stm32_microKernel(K, &A[A_idx], LDA, &B[B_idx], LDB, &C[C_idx], LDC);
      A_idx += 2;
      C_idx += 2;
      i += 2;
    }

    while (i <= M - 1) {
      stm32_microKernel_d(K, &A[A_idx], LDA, &B[B_idx], LDB, &C[C_idx], LDC);
      A_idx++;
      C_idx++;
      i++;
    }

    B_idx += LDB << 1;
    j += 2;
  }

  while (j <= N - 1) {
    C_idx = LDC * j;
    i = 0;
    A_idx = 0;
    while (i <= M - 2) {
      stm32_microKernel_di(K, &A[A_idx], LDA, &B[B_idx], &C[C_idx]);
      A_idx += 2;
      C_idx += 2;
      i += 2;
    }

    while (i <= M - 1) {
      stm32_microKernel_die(K, &A[A_idx], LDA, &B[B_idx], &C[C_idx]);
      A_idx++;
      C_idx++;
      i++;
    }

    B_idx += LDB;
    j++;
  }
}

static void stm32_matrixMultiply(int32_T M, int32_T K, int32_T N, int32_T
  blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A, const
  real32_T *B, real32_T *C)
{
  int32_T K2;
  int32_T N2;
  int32_T i;
  int32_T i0;
  int32_T i0_ub;
  int32_T j1;
  int32_T k;
  int32_T k0;
  int32_T k0_ub;
  int32_T tmp;
  if (blockSizeM >= M) {
    blockSizeM = M;
  } else {
    blockSizeM = (blockSizeM >> 1) << 1;
    if (blockSizeM <= 0) {
      blockSizeM = 1;
    }
  }

  if (blockSizeN >= N) {
    blockSizeN = N;
  } else {
    blockSizeN = (blockSizeN >> 1) << 1;
    if (blockSizeN <= 0) {
      blockSizeN = 1;
    }
  }

  i0_ub = div_s32_floor(M - 1, blockSizeM);
  k0_ub = div_s32_floor(K - 1, blockSizeK);
  for (j1 = 0; j1 < N; j1 += blockSizeN) {
    if (j1 > N - blockSizeN) {
      N2 = N - j1;
    } else {
      N2 = blockSizeN;
    }

    for (k0 = 1; k0 <= k0_ub + 1; k0++) {
      k = (k0 - 1) * blockSizeK;
      if (k > K - blockSizeK) {
        K2 = K - k;
      } else {
        K2 = blockSizeK;
      }

      for (i0 = 1; i0 <= i0_ub + 1; i0++) {
        i = (i0 - 1) * blockSizeM;
        if (i > M - blockSizeM) {
          tmp = M - i;
        } else {
          tmp = blockSizeM;
        }

        stm32_macroKernel(tmp, K2, N2, &A[i + M * k], M, &B[k + K * j1], K, &C[i
                          + M * j1], M);
      }
    }
  }
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void stm_FullyConnectedLayer_predict(const real32_T X[4], real32_T Z[2])
{
  static const real32_T b[8] = { 0.446009F, -0.449192077F, 0.458876103F,
    -0.460187048F, -0.00794181228F, 0.00794173311F, -0.377587885F, 0.365449548F
  };

  Z[0] = -0.494756132F;
  Z[1] = 0.494757801F;
  stm32_matrixMultiply(2, 4, 1, 64, 64, 64, &b[0], &X[0], &Z[0]);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void stm32_SoftmaxLayer_predict(const real32_T X1[2], real32_T Z1[2])
{
  real32_T Z1_0;
  real32_T maxVal;
  real32_T y;
  if ((X1[0] >= X1[1]) || rtIsNaNF(X1[1])) {
    maxVal = X1[0];
  } else {
    maxVal = X1[1];
  }

  Z1_0 = (real32_T)exp(X1[0] - maxVal);
  maxVal = (real32_T)exp(X1[1] - maxVal);
  y = Z1_0 + maxVal;
  Z1[0] = Z1_0 / y;
  Z1[1] = maxVal / y;
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void stm32_iGetActivations(const cell_wrap_13_stm32_T *inputsT,
  cell_wrap_16_stm32_T *outputs)
{
  for (stm32_B.i1 = 0; stm32_B.i1 < 50176; stm32_B.i1++) {
    stm32_B.inputsT[stm32_B.i1] = inputsT->f1[stm32_B.i1] - 130.025833F;
    stm32_B.inputsT[stm32_B.i1 + 50176] = inputsT->f1[stm32_B.i1 + 50176] -
      122.070312F;
    stm32_B.inputsT[stm32_B.i1 + 100352] = inputsT->f1[stm32_B.i1 + 100352] -
      96.2365265F;
  }

  s_conv2dDirectOptimizedColMajor(stm32_B.inputsT, stm32_B.outT_f2.f1);
  stm32_MaxPooling2DLayer_predict(stm32_B.outT_f2.f1, stm32_B.fv);
  conv2dDirectOptimizedColMajor_a(stm32_B.fv, stm32_B.outT_f4.f1);
  conv2dDirectOptimizedColMajo_ai(stm32_B.outT_f4.f1, stm32_B.outT_f5.f1);
  stm_MaxPooling2DLayer_predict_n(stm32_B.outT_f5.f1, stm32_B.outT_f6.f1);
  conv2dDirectOptimizedColMaj_aie(stm32_B.outT_f6.f1, stm32_B.outT_f7.f1);
  Convolution2DActivation_predict(stm32_B.outT_f6.f1, stm32_B.outT_f8.f1);
  conv2dDirectOptimizedColM_aiel1(stm32_B.outT_f8.f1, stm32_B.outT_f9.f1);
  Convolution2DActivation_predi_h(stm32_B.outT_f6.f1, stm32_B.outT_f10.f1);
  Convolution2DActivation_pred_hu(stm32_B.outT_f10.f1, stm32_B.outT_f11.f1);
  st_MaxPooling2DLayer_predict_no(stm32_B.outT_f6.f1, stm32_B.fv1);
  Convolution2DActivation_pre_hur(stm32_B.fv1, stm32_B.outT_f13.f1);
  stm32_cat(stm32_B.outT_f7.f1, stm32_B.outT_f9.f1, stm32_B.outT_f11.f1,
            stm32_B.outT_f13.f1, stm32_B.outT_f14.f1);
  conv2dDirectOptimized_aiel1da3p(stm32_B.outT_f14.f1, stm32_B.outT_f15.f1);
  Convolution2DActivation_pr_hurc(stm32_B.outT_f14.f1, stm32_B.outT_f16.f1);
  Convolution2DActivation_p_hurcm(stm32_B.outT_f16.f1, stm32_B.outT_f17.f1);
  Convolution2DActivation__hurcml(stm32_B.outT_f14.f1, stm32_B.outT_f18.f1);
  Convolution2DActivation_hurcmlu(stm32_B.outT_f18.f1, stm32_B.outT_f19.f1);
  s_MaxPooling2DLayer_predict_nor(stm32_B.outT_f14.f1, stm32_B.fv2);
  Convolution2DActivatio_hurcmlun(stm32_B.fv2, stm32_B.outT_f21.f1);
  stm32_cat(stm32_B.outT_f15.f1, stm32_B.outT_f17.f1, stm32_B.outT_f19.f1,
            stm32_B.outT_f21.f1, stm32_B.fv2);
  s_AveragePooling2DLayer_predict(stm32_B.fv2, stm32_B.fv3);
  stm_FullyConnectedLayer_predict(stm32_B.fv3, stm32_B.outT_f25.f1);
  stm32_SoftmaxLayer_predict(stm32_B.outT_f25.f1, outputs->f1);
}

/* Function for MATLAB Function: '<S1>/MLFB' */
static void stm_DeepLearningNetwork_predict(c_coder_internal_ctarget_Deep_T *obj,
  const uint8_T varargin_1[150528], real32_T varargout_1[2])
{
  for (stm32_B.i = 0; stm32_B.i < 150528; stm32_B.i++) {
    stm32_B.inMiniBatchGroup.f1[stm32_B.i] = varargin_1[stm32_B.i];
  }

  if (!obj->IsNetworkInitialized) {
    obj->IsNetworkInitialized = true;
  }

  stm32_iGetActivations(&stm32_B.inMiniBatchGroup, &stm32_B.outMiniBatchGroup);
  varargout_1[0] = stm32_B.outMiniBatchGroup.f1[0];
  varargout_1[1] = stm32_B.outMiniBatchGroup.f1[1];
}

/* Model step function */
void stm32_step(void)
{
  static const int16_T g[1568] = { -2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 49, 50, 51, 52, 53,
    54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 65, 66, 67, 68, 69, 70, 71, 72, 73,
    74, 75, 76, 77, 78, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93,
    94, 95, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
    111, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126,
    128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142,
    144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158,
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174,
    176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190,
    192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206,
    208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222,
    224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, -1, 0, 2, 3,
    4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66,
    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 82, 83, 84, 85, 86,
    87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 114, 115, 116, 117, 118, 119, 120, 121,
    122, 123, 124, 125, 126, 127, 129, 130, 131, 132, 133, 134, 135, 136, 137,
    138, 139, 140, 141, 142, 143, 145, 146, 147, 148, 149, 150, 151, 152, 153,
    154, 155, 156, 157, 158, 159, 161, 162, 163, 164, 165, 166, 167, 168, 169,
    170, 171, 172, 173, 174, 175, 177, 178, 179, 180, 181, 182, 183, 184, 185,
    186, 187, 188, 189, 190, 191, 193, 194, 195, 196, 197, 198, 199, 200, 201,
    202, 203, 204, 205, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217,
    218, 219, 220, 221, 222, 223, 225, 226, 227, 228, 229, 230, 231, 232, 233,
    234, 235, 236, 237, 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 35, 36, 37,
    38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 52, 53, 54, 55, 56, 57,
    58, 59, 60, 61, 62, 63, 64, 65, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
    78, 79, 80, 81, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97,
    99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
    115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 130,
    131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 146,
    147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 162,
    163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 178,
    179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 210,
    211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 226,
    227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 1, 2, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
    49, 50, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 84, 85, 86, 87, 88, 89,
    90, 91, 92, 93, 94, 95, 96, 97, 98, 100, 101, 102, 103, 104, 105, 106, 107,
    108, 109, 110, 111, 112, 113, 114, 116, 117, 118, 119, 120, 121, 122, 123,
    124, 125, 126, 127, 128, 129, 131, 132, 133, 134, 135, 136, 137, 138, 139,
    140, 141, 142, 143, 144, 145, 147, 148, 149, 150, 151, 152, 153, 154, 155,
    156, 157, 158, 159, 160, 161, 163, 164, 165, 166, 167, 168, 169, 170, 171,
    172, 173, 174, 175, 176, 177, 179, 180, 181, 182, 183, 184, 185, 186, 187,
    188, 189, 190, 191, 192, 193, 195, 196, 197, 198, 199, 200, 201, 202, 203,
    204, 205, 206, 207, 208, 209, 211, 212, 213, 214, 215, 216, 217, 218, 219,
    220, 221, 222, 223, 224, 225, 227, 228, 229, 230, 231, 232, 233, 234, 235,
    236, 237, 238, 239, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
    19, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 64, 65, 66, 67, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
    101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
    117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 132,
    133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 148,
    149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 164,
    165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 180,
    181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 196,
    197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 212,
    213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 228,
    229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 3, 4, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 102, 103, 104, 105, 106, 107, 108,
    109, 110, 111, 112, 113, 114, 115, 116, 118, 119, 120, 121, 122, 123, 124,
    125, 126, 127, 128, 129, 130, 131, 133, 134, 135, 136, 137, 138, 139, 140,
    141, 142, 143, 144, 145, 146, 147, 149, 150, 151, 152, 153, 154, 155, 156,
    157, 158, 159, 160, 161, 162, 163, 165, 166, 167, 168, 169, 170, 171, 172,
    173, 174, 175, 176, 177, 178, 179, 181, 182, 183, 184, 185, 186, 187, 188,
    189, 190, 191, 192, 193, 194, 195, 197, 198, 199, 200, 201, 202, 203, 204,
    205, 206, 207, 208, 209, 210, 211, 213, 214, 215, 216, 217, 218, 219, 220,
    221, 222, 223, 224, 225, 226, 227, 229, 230, 231, 232, 233, 234, 235, 236,
    237, 238, 239, 240, 241, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
    19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
    100, 101, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
    116, 117, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
    132, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147,
    148, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163,
    164, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195,
    196, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211,
    212, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227,
    228, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242 };

  static const real_T h[1568] = { 2.8430962343096233, 2.9058577405857742,
    2.0313807531380754, 2.0941422594142258, 2.1569037656903767,
    2.2196652719665271, 2.2824267782426775, 2.3451882845188297,
    2.4079497907949792, 2.4707112970711305, 2.5334728033472804,
    2.5962343096234317, 2.6589958158995812, 2.7217573221757325,
    2.7845188284518825, 2.8472803347280355, 2.9100418410041851,
    2.0355648535564854, 2.0983263598326349, 2.161087866108788,
    2.2238493723849375, 2.2866108786610875, 2.3493723849372405, 2.41213389121339,
    2.4748953974895396, 2.5376569037656895, 2.6004184100418426,
    2.6631799163179921, 2.7259414225941416, 2.7887029288702916,
    2.851464435146438, 2.9142259414225942, 2.0397489539748945, 2.102510460251044,
    2.165271966527194, 2.2280334728033435, 2.290794979079493, 2.353556485355643,
    2.4163179916317992, 2.4790794979079487, 2.5418410041840986,
    2.6046025104602482, 2.6673640167363977, 2.7301255230125476,
    2.7928870292886971, 2.8556485355648538, 2.9184100418410033,
    2.0439330543933036, 2.1066945606694532, 2.1694560669456031,
    2.2322175732217526, 2.2949790794979021, 2.3577405857740588,
    2.4205020920502083, 2.4832635983263578, 2.5460251046025077,
    2.6087866108786573, 2.6715481171548068, 2.7343096234309567,
    2.7970711297071063, 2.8598326359832695, 2.9225941422594124,
    2.0481171548117194, 2.1108786610878756, 2.1736401673640184,
    2.2364016736401751, 2.2991631799163179, 2.3619246861924745,
    2.4246861924686174, 2.4874476987447736, 2.55020920502093, 2.612970711297073,
    2.6757322175732292, 2.7384937238493725, 2.8012552301255287,
    2.8640167364016715, 2.9267782426778282, 2.0523012552301352,
    2.115062761506278, 2.1778242677824342, 2.2405857740585775,
    2.3033472803347337, 2.366108786610877, 2.4288702928870332,
    2.4916317991631893, 2.5543933054393326, 2.6171548117154888,
    2.6799163179916317, 2.7426778242677883, 2.8054393305439311,
    2.8682008368200873, 2.9309623430962439, 2.0564853556485376,
    2.1192468619246938, 2.1820083682008367, 2.2447698744769933,
    2.3075313807531361, 2.3702928870292923, 2.4330543933054489,
    2.4958158995815918, 2.5585774058577484, 2.6213389121338913,
    2.6841004184100474, 2.7468619246861907, 2.8096234309623469,
    2.8723849372385031, 2.9351464435146464, 2.0606694560669534,
    2.1234309623430963, 2.1861924686192524, 2.2489539748953957,
    2.3117154811715519, 2.3744769874477081, 2.4372384937238514,
    2.5000000000000075, 2.5627615062761508, 2.625523012552307, 2.68828451882845,
    2.7510460251046065, 2.8138075313807493, 2.8765690376569188,
    2.0020920502092125, 2.0648535564853558, 2.1276150627614987,
    2.1903765690376682, 2.2531380753138115, 2.3158995815899543,
    2.3786610878661238, 2.4414225941422671, 2.50418410041841, 2.5669456066945529,
    2.6297071129707228, 2.6924686192468656, 2.7552301255230089,
    2.8179916317991784, 2.8807531380753213, 2.006276150627615,
    2.0690376569037583, 2.1317991631799278, 2.1945606694560706,
    2.2573221757322139, 2.3200836820083834, 2.3828451882845263,
    2.4456066945606696, 2.5083682008368124, 2.5711297071129819,
    2.6338912133891252, 2.6966527196652681, 2.759414225941438,
    2.8221757322175809, 2.8849372384937237, 2.0104602510460174,
    2.0732217573221869, 2.1359832635983302, 2.1987447698744731,
    2.261506276150643, 2.3242677824267859, 2.3870292887029287, 2.449790794979072,
    2.5125523012552415, 2.5753138075313844, 2.6380753138075277,
    2.7008368200836972, 2.76359832635984, 2.8263598326359833, 2.8891213389121262,
    2.0146443514644465, 2.0774058577405894, 2.1401673640167327,
    2.2029288702929022, 2.2656903765690455, 2.3284518828451883,
    2.3912133891213312, 2.4539748953975011, 2.516736401673644,
    2.5794979079497868, 2.6422594142259568, 2.7050209205020996,
    2.7677824267782425, 2.8305439330543858, 2.8933054393305553,
    2.018828451882849, 2.0815899581589918, 2.1443514644351618,
    2.2071129707113046, 2.2698744769874475, 2.3326359832635908,
    2.3953974895397603, 2.4581589958159036, 2.5209205020920464,
    2.5836820083682159, 2.6464435146443592, 2.7092050209205021,
    2.7719665271966449, 2.8347280334728149, 2.8974895397489577,
    2.0230125523012514, 2.0857740585774209, 2.1485355648535642,
    2.2112970711297071, 2.27405857740585, 2.33682008368202, 2.3995815899581627,
    2.462343096234306, 2.5251046025104755, 2.5878661087866184,
    2.6506276150627617, 2.7133891213389045, 2.776150627615074,
    2.8389121338912173, 2.90167364016736, 2.0271966527196805, 2.0899581589958234,
    2.1527196652719667, 2.2154811715481095, 2.278242677824279,
    2.3410041841004223, 2.4037656903765652, 2.4665271966527347,
    2.529288702928878, 2.5920502092050208, 2.6548117154811641,
    2.7175732217573336, 2.7803347280334765, 1.905857740585774, 1.968619246861925,
    1.094142259414226, 1.1569037656903767, 1.2196652719665271,
    1.2824267782426777, 1.3451882845188281, 1.4079497907949803, 1.47071129707113,
    1.5334728033472813, 1.596234309623431, 1.6589958158995823,
    1.7217573221757321, 1.7845188284518834, 1.8472803347280331,
    1.9100418410041859, 1.9728033472803357, 1.098326359832636,
    1.1610878661087856, 1.2238493723849386, 1.2866108786610884,
    1.3493723849372381, 1.4121338912133909, 1.4748953974895407,
    1.5376569037656904, 1.6004184100418402, 1.663179916317993,
    1.7259414225941427, 1.7887029288702925, 1.851464435146442,
    1.9142259414225884, 1.9769874476987448, 1.1025104602510452,
    1.1652719665271947, 1.2280334728033444, 1.2907949790794941,
    1.3535564853556439, 1.4163179916317934, 1.4790794979079498,
    1.5418410041840995, 1.604602510460249, 1.6673640167363988,
    1.7301255230125485, 1.7928870292886983, 1.8556485355648478,
    1.9184100418410042, 1.9811715481171539, 1.1066945606694543,
    1.1694560669456038, 1.2322175732217535, 1.2949790794979033,
    1.3577405857740528, 1.4205020920502092, 1.4832635983263589,
    1.5460251046025086, 1.6087866108786582, 1.6715481171548079,
    1.7343096234309576, 1.7970711297071074, 1.8598326359832569, 1.92259414225942,
    1.985355648535563, 1.1108786610878698, 1.1736401673640262,
    1.2364016736401693, 1.2991631799163257, 1.3619246861924685,
    1.4246861924686249, 1.487447698744768, 1.5502092050209244,
    1.6129707112970806, 1.6757322175732237, 1.73849372384938, 1.8012552301255229,
    1.8640167364016793, 1.9267782426778224, 1.9895397489539788,
    1.1150627615062856, 1.1778242677824287, 1.2405857740585851,
    1.3033472803347281, 1.3661087866108843, 1.4288702928870274,
    1.4916317991631838, 1.55439330543934, 1.617154811715483, 1.6799163179916394,
    1.7426778242677825, 1.8054393305439387, 1.8682008368200818,
    1.9309623430962382, 1.9937238493723946, 1.119246861924688,
    1.1820083682008444, 1.2447698744769875, 1.3075313807531437,
    1.3702928870292868, 1.4330543933054432, 1.4958158995815996,
    1.5585774058577424, 1.6213389121338988, 1.6841004184100419,
    1.7468619246861983, 1.8096234309623411, 1.8723849372384975,
    1.9351464435146539, 1.9979079497907968, 1.1234309623431038,
    1.1861924686192469, 1.2489539748954033, 1.3117154811715461,
    1.3744769874477025, 1.4372384937238589, 1.500000000000002,
    1.5627615062761582, 1.6255230125523012, 1.6882845188284576,
    1.7510460251046007, 1.8138075313807569, 1.8765690376569, 1.9393305439330697,
    1.0648535564853632, 1.1276150627615062, 1.1903765690376493,
    1.253138075313819, 1.3158995815899619, 1.378661087866105, 1.4414225941422747,
    1.5041841004184175, 1.5669456066945606, 1.6297071129707037,
    1.6924686192468734, 1.7552301255230163, 1.8179916317991593,
    1.8807531380753291, 1.9435146443514721, 1.0690376569037656,
    1.1317991631799087, 1.1945606694560784, 1.2573221757322215,
    1.3200836820083643, 1.3828451882845341, 1.4456066945606771, 1.50836820083682,
    1.5711297071129631, 1.6338912133891328, 1.6966527196652759,
    1.7594142259414187, 1.8221757322175884, 1.8849372384937315,
    1.9476987447698746, 1.0732217573221681, 1.1359832635983378,
    1.1987447698744809, 1.2615062761506237, 1.3242677824267934,
    1.3870292887029365, 1.4497907949790796, 1.5125523012552224,
    1.5753138075313922, 1.6380753138075352, 1.7008368200836783,
    1.7635983263598478, 1.8263598326359909, 1.889121338912134,
    1.9518828451882768, 1.0774058577405972, 1.1401673640167402,
    1.2029288702928833, 1.2656903765690528, 1.3284518828451959,
    1.391213389121339, 1.453974895397482, 1.5167364016736515, 1.5794979079497946,
    1.6422594142259377, 1.7050209205021072, 1.7677824267782503,
    1.8305439330543933, 1.8933054393305364, 1.9560669456067059,
    1.0815899581589996, 1.1443514644351427, 1.2071129707113124,
    1.2698744769874553, 1.3326359832635983, 1.3953974895397414,
    1.4581589958159109, 1.520920502092054, 1.5836820083681971,
    1.6464435146443668, 1.7092050209205096, 1.7719665271966527,
    1.8347280334727958, 1.8974895397489655, 1.9602510460251084,
    1.0857740585774021, 1.1485355648535718, 1.2112970711297146,
    1.2740585774058577, 1.3368200836820008, 1.3995815899581705,
    1.4623430962343134, 1.5251046025104564, 1.5878661087866262,
    1.6506276150627692, 1.7133891213389121, 1.7761506276150552,
    1.8389121338912249, 1.9016736401673677, 1.9644351464435108,
    1.0899581589958312, 1.1527196652719742, 1.2154811715481171,
    1.2782426778242602, 1.3410041841004299, 1.4037656903765729,
    1.4665271966527158, 1.5292887029288855, 1.5920502092050286,
    1.6548117154811715, 1.7175732217573145, 1.7803347280334842,
    1.8430962343096273, 0.96861924686192458, 1.0313807531380756,
    0.1569037656903767, 0.21966527196652719, 0.2824267782426777,
    0.34518828451882821, 0.40794979079497873, 0.47071129707113091,
    0.53347280334728053, 0.59623430962343194, 0.65899581589958156,
    0.721757322175733, 0.78451882845188259, 0.847280334728034,
    0.91004184100418362, 0.97280334728033668, 1.0355648535564863,
    0.16108786610878661, 0.2238493723849363, 0.28661087866108931,
    0.349372384937239, 0.41213389121338867, 0.47489539748954163,
    0.53765690376569131, 0.600418410041841, 0.66317991631799067,
    0.72594142259414374, 0.78870292887029336, 0.851464435146443,
    0.91422594142259272, 0.976987447698739, 1.0397489539748954,
    0.1652719665271957, 0.22803347280334538, 0.29079497907949503,
    0.35355648535564471, 0.41631799163179439, 0.47907949790794407,
    0.54184100418410042, 0.60460251046025, 0.66736401673639978,
    0.7301255230125494, 0.79288702928869914, 0.85564853556484877,
    0.9184100418409985, 0.98117154811715479, 1.0439330543933045,
    0.16945606694560481, 0.23221757322175446, 0.29497907949790414,
    0.35774058577405382, 0.4205020920502035, 0.48326359832635984,
    0.54602510460250953, 0.60878661087865915, 0.67154811715480889,
    0.73430962343095851, 0.79707112970710825, 0.85983263598325788,
    0.92259414225940761, 0.98535564853557056, 1.0481171548117136,
    0.17364016736402055, 0.23640167364017689, 0.29916317991631991,
    0.36192468619247625, 0.42468619246861927, 0.48744769874477556,
    0.55020920502091863, 0.61297071129707492, 0.67573221757323132,
    0.73849372384937428, 0.80125523012553057, 0.86401673640167365,
    0.92677824267782993, 0.989539748953973, 1.0523012552301294,
    0.17782426778243629, 0.24058577405857931, 0.30334728033473563,
    0.36610878661087864, 0.428870292887035, 0.491631799163178,
    0.55439330543933441, 0.61715481171549069, 0.67991631799163366,
    0.74267782426779, 0.805439330543933, 0.86820083682008942,
    0.93096234309623238, 0.99372384937238878, 1.0564853556485452,
    0.18200836820083871, 0.24476987447699505, 0.30753138075313807,
    0.37029288702929442, 0.43305439330543744, 0.49581589958159378,
    0.55857740585775006, 0.62133891213389314, 0.68410041841004943,
    0.7468619246861925, 0.80962343096234879, 0.87238493723849186,
    0.93514644351464815, 0.99790794979080455, 1.0606694560669474,
    0.18619246861925448, 0.2489539748953975, 0.31171548117155384,
    0.37447698744769686, 0.43723849372385321, 0.50000000000000955,
    0.56276150627615251, 0.62552301255230891, 0.68828451882845187,
    0.75104602510460827, 0.81380753138075124, 0.87656903765690752,
    0.9393305439330506, 1.0020920502092203, 0.12761506276151388,
    0.1903765690376569, 0.25313807531379995, 0.31589958158996956,
    0.37866108786611258, 0.4414225941422556, 0.50418410041842532,
    0.56694560669456828, 0.62970711297071125, 0.69246861924685432,
    0.75523012552302393, 0.817991631799167, 0.88075313807531,
    0.94351464435147969, 1.0062761506276228, 0.13179916317991633,
    0.19456066945605935, 0.257322175732229, 0.320083682008372, 0.382845188284515,
    0.44560669456068469, 0.50836820083682766, 0.57112970711297073,
    0.63389121338911369, 0.69665271966528342, 0.75941422594142638,
    0.82217573221756945, 0.88493723849373906, 0.94769874476988214,
    1.0104602510460252, 0.13598326359831875, 0.19874476987448841,
    0.26150627615063143, 0.32426778242677445, 0.38702928870294412,
    0.44979079497908708, 0.5125523012552301, 0.57531380753137318,
    0.63807531380754279, 0.70083682008368586, 0.76359832635982883,
    0.82635983263599844, 0.88912133891214151, 0.95188284518828448,
    1.0146443514644274, 0.14016736401674781, 0.20292887029289083,
    0.26569037656903383, 0.32845188284520349, 0.39121338912134651,
    0.45397489539748953, 0.51673640167363255, 0.57949790794980216,
    0.64225941422594524, 0.7050209205020882, 0.76778242677825792,
    0.83054393305440088, 0.893305439330544, 0.95606694560668692,
    1.0188284518828565, 0.14435146443515026, 0.20711297071129325,
    0.26987447698746292, 0.33263598326360594, 0.39539748953974896,
    0.458158995815892, 0.52092050209206164, 0.58368200836820461,
    0.64644351464434768, 0.70920502092051729, 0.77196652719666037,
    0.83472803347280333, 0.89748953974894641, 0.960251046025116,
    1.023012552301259, 0.14853556485355268, 0.21129707112972235,
    0.27405857740586537, 0.33682008368200839, 0.39958158995815141,
    0.462343096234321, 0.52510460251046409, 0.58786610878660706,
    0.65062761506277678, 0.71338912133891974, 0.77615062761506282,
    0.83891213389120578, 0.90167364016737539, 0.96443514644351847,
    1.0271966527196614, 0.15271966527198175, 0.21548117154812477,
    0.27824267782426776, 0.34100418410041078, 0.40376569037658044,
    0.46652719665272346, 0.52928870292886654, 0.59205020920503615,
    0.65481171548117911, 0.71757322175732219, 0.78033472803346515,
    0.84309623430963487, 0.90585774058577784, 0.031380753138075257,
    0.094142259414226173, -0.7803347280334727, -0.71757322175732219,
    -0.65481171548117167, -0.59205020920502116, -0.52928870292887065,
    -0.46652719665271847, -0.40376569037656879, -0.34100418410041744,
    -0.27824267782426776, -0.21548117154811644, -0.15271966527196676,
    -0.089958158995815427, -0.027196652719665749, 0.035564853556487259,
    0.098326359832636934, -0.77615062761506282, -0.71338912133891308,
    -0.65062761506276012, -0.58786610878661039, -0.52510460251046076,
    -0.46234309623430775, -0.39958158995815807, -0.33682008368200839,
    -0.27405857740585871, -0.21129707112970569, -0.148535564853556,
    -0.085774058577406331, -0.023012552301256657, 0.039748953974889686,
    0.10251046025104603, -0.77196652719665371, -0.709205020920504,
    -0.64644351464435434, -0.58368200836820461, -0.520920502092055,
    -0.4581589958159053, -0.39539748953974896, -0.33263598326359928,
    -0.2698744769874496, -0.20711297071129992, -0.14435146443515026,
    -0.081589958159000567, -0.018828451882850896, 0.043933054393305443,
    0.10669456066945511, -0.7677824267782446, -0.70502092050209486,
    -0.64225941422594524, -0.5794979079497955, -0.51673640167364587,
    -0.45397489539748953, -0.39121338912133985, -0.32845188284519017,
    -0.26569037656904049, -0.20292887029289083, -0.14016736401674115,
    -0.077405857740591485, -0.014644351464441806, 0.048117154811721193,
    0.11087866108786421, -0.76359832635982883, -0.70083682008367254,
    -0.63807531380752947, -0.57531380753137318, -0.5125523012552301,
    -0.44979079497907382, -0.3870292887029308, -0.32426778242677445,
    -0.26150627615061811, -0.19874476987447509, -0.13598326359831875,
    -0.073221757322175729, -0.010460251046019397, 0.052301255230123619,
    0.11506276150627996, -0.75941422594141306, -0.69665271966527009,
    -0.63389121338911369, -0.57112970711297073, -0.50836820083681433,
    -0.44560669456067137, -0.382845188284515, -0.32008368200835868,
    -0.25732217573221566, -0.19456066945605935, -0.13179916317991633,
    -0.069037656903759986, -0.0062761506276169656, 0.056485355648539369,
    0.1192468619246957, -0.75523012552301061, -0.69246861924685432,
    -0.62970711297071125, -0.566945606694555, -0.504184100418412,
    -0.4414225941422556, -0.37866108786609926, -0.31589958158995624,
    -0.25313807531379995, -0.1903765690376569, -0.12761506276150056,
    -0.064853556485357552, -0.0020920502092012156, 0.060669456066955119,
    0.12343096234309814, -0.751046025104595, -0.68828451882845187,
    -0.62552301255229559, -0.56276150627615251, -0.49999999999999617,
    -0.43723849372383988, -0.37447698744769686, -0.31171548117154052,
    -0.2489539748953975, -0.18619246861924116, -0.12343096234309814,
    -0.0606694560669418, 0.0020920502092012156, 0.064853556485370875,
    -0.80962343096233547, -0.7468619246861925, -0.68410041841004943,
    -0.62133891213387982, -0.55857740585773674, -0.49581589958159378,
    -0.43305439330542411, -0.37029288702928109, -0.30753138075313807,
    -0.24476987447699505, -0.18200836820082542, -0.11924686192468238,
    -0.056485355648539369, 0.0062761506276302849, 0.0690376569037733,
    -0.805439330543933, -0.74267782426779, -0.67991631799162033,
    -0.61715481171547737, -0.55439330543933441, -0.49163179916316468,
    -0.42887029288702166, -0.36610878661087864, -0.30334728033473563,
    -0.240585774058566, -0.17782426778242297, -0.11506276150627996,
    -0.052301255230110304, 0.010460251046032716, 0.073221757322175729,
    -0.80125523012553057, -0.738493723849361, -0.675732217573218,
    -0.61297071129707492, -0.55020920502090531, -0.48744769874476229,
    -0.42468619246861927, -0.36192468619247625, -0.29916317991630659,
    -0.23640167364016357, -0.17364016736402055, -0.11087866108785088,
    -0.04811715481170787, 0.014644351464435146, 0.077405857740578163,
    -0.79707112970710159, -0.73430962343095851, -0.67154811715481555,
    -0.60878661087864583, -0.54602510460250286, -0.48326359832635984,
    -0.42050209205021682, -0.35774058577404716, -0.29497907949790414,
    -0.23221757322176112, -0.16945606694559148, -0.10669456066944846,
    -0.043933054393305443, 0.018828451882837577, 0.081589958159007228,
    -0.79288702928869914, -0.73012552301255607, -0.66736401673638646,
    -0.60460251046024349, -0.54184100418410042, -0.4790794979079574,
    -0.41631799163178773, -0.35355648535564471, -0.29079497907950169,
    -0.22803347280333205, -0.16527196652718903, -0.10251046025104603,
    -0.039748953974903009, 0.023012552301266646, 0.085774058577409662,
    -0.78870292887029669, -0.72594142259412708, -0.663179916317984,
    -0.600418410041841, -0.537656903765698, -0.47489539748952836,
    -0.41213389121338534, -0.34937238493724232, -0.28661087866107265,
    -0.22384937238492963, -0.16108786610878661, -0.0983263598326436,
    -0.035564853556473937, 0.027196652719669076, 0.0899581589958121,
    -0.7845188284518676, -0.72175732217572464, -0.65899581589958156,
    -0.5962343096234386, -0.53347280334726888, -0.47071129707112591,
    -0.40794979079498289, -0.34518828451881323, -0.28242677824267021,
    -0.21966527196652719, -0.15690376569038417, -0.09414225941421453,
    -0.03138075313807151, -0.90585774058577417, -0.84309623430962322,
    -1.7175732217573221, -1.6548117154811715, -1.592050209205021,
    -1.5292887029288704, -1.46652719665272, -1.4037656903765678,
    -1.3410041841004181, -1.2782426778242668, -1.2154811715481171,
    -1.1527196652719658, -1.0899581589958161, -1.0271966527196648,
    -0.96443514644351513, -0.90167364016736207, -0.83891213389121244,
    -1.7133891213389121, -1.6506276150627626, -1.5878661087866095,
    -1.5251046025104598, -1.46234309623431, -1.3995815899581572,
    -1.3368200836820074, -1.2740585774058577, -1.211297071129708,
    -1.1485355648535551, -1.0857740585774054, -1.0230125523012557,
    -0.960251046025106, -0.89748953974895973, -0.83472803347280333,
    -1.709205020920503, -1.6464435146443535, -1.5836820083682037,
    -1.520920502092054, -1.4581589958159042, -1.3953974895397547,
    -1.3326359832635983, -1.2698744769874486, -1.2071129707112991,
    -1.1443514644351493, -1.0815899581589996, -1.0188284518828499,
    -0.95606694560670025, -0.893305439330544, -0.83054393305439422,
    -1.7050209205020939, -1.6422594142259443, -1.5794979079497946,
    -1.5167364016736449, -1.4539748953974954, -1.391213389121339,
    -1.3284518828451892, -1.2656903765690395, -1.20292887029289,
    -1.1401673640167402, -1.0774058577405905, -1.0146443514644408,
    -0.95188284518829114, -0.88912133891212819, -0.82635983263598511,
    -1.7008368200836783, -1.6380753138075219, -1.5753138075313788,
    -1.5125523012552224, -1.4497907949790796, -1.3870292887029232,
    -1.3242677824267801, -1.2615062761506237, -1.1987447698744675,
    -1.1359832635983245, -1.0732217573221681, -1.0104602510460252,
    -0.94769874476986882, -0.88493723849372574, -0.82217573221756945,
    -1.6966527196652625, -1.6338912133891195, -1.5711297071129631,
    -1.50836820083682, -1.4456066945606638, -1.3828451882845207,
    -1.3200836820083643, -1.2573221757322082, -1.1945606694560651,
    -1.1317991631799087, -1.0690376569037656, -1.0062761506276094,
    -0.94351464435146637, -0.88075313807531, -0.81799163179915368,
    -1.69246861924686, -1.6297071129707037, -1.5669456066945606,
    -1.5041841004184044, -1.4414225941422614, -1.378661087866105,
    -1.3158995815899486, -1.2531380753138057, -1.1903765690376493,
    -1.1276150627615062, -1.0648535564853499, -1.002092050209207,
    -0.9393305439330506, -0.8765690376568942, -0.81380753138075124,
    -1.6882845188284443, -1.6255230125523012, -1.5627615062761449,
    -1.500000000000002, -1.4372384937238456, -1.3744769874476892,
    -1.3117154811715461, -1.24895397489539, -1.1861924686192469,
    -1.1234309623430905, -1.0606694560669474, -0.99790794979079123,
    -0.93514644351464815, -0.87238493723847854, -1.746861924686185,
    -1.6841004184100419, -1.6213389121338988, -1.5585774058577291,
    -1.4958158995815862, -1.4330543933054432, -1.3702928870292734,
    -1.3075313807531306, -1.2447698744769875, -1.1820083682008444,
    -1.1192468619246747, -1.0564853556485319, -0.99372384937238878,
    -0.93096234309621906, -0.86820083682007609, -1.7426778242677825,
    -1.6799163179916394, -1.6171548117154697, -1.5543933054393266,
    -1.4916317991631838, -1.4288702928870141, -1.366108786610871,
    -1.3033472803347281, -1.2405857740585851, -1.1778242677824153,
    -1.1150627615062723, -1.0523012552301294, -0.98953974895395969,
    -0.92677824267781661, -0.86401673640167365, -1.73849372384938,
    -1.6757322175732103, -1.6129707112970673, -1.5502092050209244,
    -1.4874476987447547, -1.4246861924686116, -1.3619246861924685,
    -1.2991631799163257, -1.236401673640156, -1.1736401673640129,
    -1.1108786610878698, -1.0481171548117003, -0.98535564853555724,
    -0.92259414225941427, -0.8598326359832712, -1.734309623430951,
    -1.6715481171548079, -1.6087866108786648, -1.5460251046024953,
    -1.4832635983263522, -1.4205020920502092, -1.3577405857740661,
    -1.2949790794978966, -1.2322175732217535, -1.1694560669456104,
    -1.1066945606694409, -1.0439330543932979, -0.98117154811715479,
    -0.91841004184101183, -0.85564853556484211, -1.7301255230125485,
    -1.6673640167364054, -1.6046025104602357, -1.5418410041840929,
    -1.4790794979079498, -1.4163179916318067, -1.3535564853556372,
    -1.2907949790794941, -1.2280334728033511, -1.1652719665271813,
    -1.1025104602510385, -1.0397489539748954, -0.97698744769875234,
    -0.91422594142258273, -0.85146443514643966, -1.7259414225941461,
    -1.6631799163179763, -1.6004184100418335, -1.5376569037656904,
    -1.4748953974895473, -1.4121338912133776, -1.3493723849372348,
    -1.2866108786610917, -1.223849372384922, -1.1610878661087789,
    -1.098326359832636, -1.035564853556493, -0.97280334728032336,
    -0.91004184100418029, -0.84728033472803732, -1.721757322175717,
    -1.6589958158995739, -1.596234309623431, -1.533472803347288,
    -1.4707112970711183, -1.4079497907949752, -1.3451882845188323,
    -1.2824267782426626, -1.2196652719665195, -1.1569037656903767,
    -1.0941422594142336, -1.0313807531380639, -0.96861924686192091,
    -1.8430962343096235, -1.7803347280334725, -2.6548117154811712,
    -2.5920502092050208, -2.5292887029288704, -2.46652719665272,
    -2.4037656903765696, -2.3410041841004174, -2.2782426778242675,
    -2.2154811715481162, -2.1527196652719667, -2.0899581589958154,
    -2.0271966527196654, -1.9644351464435141, -1.9016736401673644,
    -1.8389121338912116, -1.7761506276150618, -2.6506276150627617,
    -2.5878661087866117, -2.5251046025104587, -2.4623430962343091,
    -2.3995815899581596, -2.3368200836820066, -2.2740585774058566,
    -2.2112970711297071, -2.1485355648535576, -2.0857740585774045,
    -2.0230125523012545, -1.960251046025105, -1.8974895397489555,
    -1.8347280334728091, -1.7719665271966527, -2.6464435146443526,
    -2.5836820083682026, -2.5209205020920531, -2.4581589958159036,
    -2.3953974895397536, -2.3326359832636041, -2.2698744769874475,
    -2.207112970711298, -2.1443514644351485, -2.0815899581589985,
    -2.018828451882849, -1.9560669456066992, -1.8933054393305497,
    -1.8305439330543933, -1.7677824267782436, -2.6422594142259435,
    -2.5794979079497935, -2.516736401673644, -2.4539748953974945,
    -2.3912133891213445, -2.3284518828451883, -2.2656903765690388,
    -2.2029288702928889, -2.1401673640167393, -2.0774058577405894,
    -2.01464435146444, -1.9518828451882901, -1.8891213389121406,
    -1.8263598326359776, -1.7635983263598345, -2.6380753138075277,
    -2.5753138075313711, -2.5125523012552282, -2.449790794979072,
    -2.3870292887029287, -2.3242677824267726, -2.2615062761506297,
    -2.1987447698744731, -2.1359832635983169, -2.0732217573221736,
    -2.0104602510460174, -1.9476987447698746, -1.8849372384937182,
    -1.8221757322175751, -1.7594142259414187, -2.6338912133891119,
    -2.5711297071129686, -2.5083682008368124, -2.4456066945606696,
    -2.382845188284513, -2.32008368200837, -2.2573221757322139,
    -2.1945606694560573, -2.1317991631799145, -2.0690376569037583,
    -2.006276150627615, -1.9435146443514588, -1.8807531380753157,
    -1.8179916317991593, -1.7552301255230029, -2.6297071129707095,
    -2.5669456066945529, -2.50418410041841, -2.4414225941422538,
    -2.3786610878661105, -2.3158995815899543, -2.2531380753137982,
    -2.1903765690376549, -2.1276150627614987, -2.0648535564853558,
    -2.0020920502091992, -1.9393305439330564, -1.8765690376569,
    -1.8138075313807436, -1.7510460251046007, -2.6255230125522937,
    -2.5627615062761508, -2.4999999999999942, -2.4372384937238514,
    -2.3744769874476948, -2.3117154811715386, -2.2489539748953957,
    -2.1861924686192391, -2.1234309623430963, -2.06066945606694,
    -1.9979079497907968, -1.9351464435146406, -1.8723849372384975,
    -1.8096234309623278, -2.6841004184100341, -2.6213389121338913,
    -2.5585774058577484, -2.4958158995815785, -2.4330543933054356,
    -2.3702928870292923, -2.3075313807531228, -2.24476987447698,
    -2.1820083682008367, -2.1192468619246938, -2.0564853556485243,
    -1.9937238493723812, -1.9309623430962382, -1.8682008368200684,
    -1.8054393305439254, -2.6799163179916317, -2.6171548117154888,
    -2.5543933054393193, -2.491631799163176, -2.4288702928870332,
    -2.3661087866108637, -2.3033472803347204, -2.2405857740585775,
    -2.1778242677824342, -2.1150627615062647, -2.0523012552301219,
    -1.9895397489539788, -1.9267782426778091, -1.864016736401666,
    -1.8012552301255229, -2.6757322175732292, -2.6129707112970597,
    -2.5502092050209169, -2.4874476987447736, -2.4246861924686041,
    -2.3619246861924612, -2.2991631799163179, -2.2364016736401751,
    -2.1736401673640051, -2.1108786610878623, -2.0481171548117194,
    -1.9853556485355497, -1.9225941422594066, -1.8598326359832635,
    -1.7970711297071207, -2.6715481171548, -2.6087866108786573,
    -2.5460251046025144, -2.4832635983263445, -2.4205020920502016,
    -2.3577405857740588, -2.2949790794979155, -2.232217573221746,
    -2.1694560669456031, -2.10669456066946, -2.0439330543932903,
    -1.9811715481171472, -1.9184100418410042, -1.8556485355648611,
    -1.7928870292886916, -2.6673640167363977, -2.6046025104602548,
    -2.5418410041840853, -2.479079497907942, -2.4163179916317992,
    -2.3535564853556563, -2.2907949790794864, -2.2280334728033435,
    -2.1652719665272007, -2.1025104602510307, -2.0397489539748879,
    -1.9769874476987448, -1.9142259414226017, -1.851464435146432,
    -1.7887029288702891, -2.6631799163179957, -2.6004184100418257,
    -2.5376569037656829, -2.4748953974895396, -2.4121338912133967,
    -2.3493723849372272, -2.2866108786610839, -2.2238493723849411,
    -2.1610878661087716, -2.0983263598326283, -2.0355648535564854,
    -1.9728033472803423, -1.9100418410041726, -1.8472803347280298,
    -1.7845188284518867, -2.6589958158995666, -2.5962343096234233,
    -2.5334728033472804, -2.4707112970711371, -2.4079497907949676,
    -2.3451882845188248, -2.2824267782426815, -2.219665271966512,
    -2.1569037656903691, -2.0941422594142258, -2.031380753138083,
    -1.9686192468619133, -1.9058577405857702, -2.7803347280334729,
    -2.7175732217573221, -3.5920502092050208, -3.5292887029288704,
    -3.4665271966527196, -3.4037656903765692, -3.3410041841004188,
    -3.2782426778242666, -3.2154811715481171, -3.1527196652719658,
    -3.0899581589958158, -3.0271966527196645, -2.964435146443515,
    -2.9016736401673637, -2.8389121338912138, -2.7761506276150607,
    -2.7133891213389112, -3.5878661087866108, -3.5251046025104613,
    -3.4623430962343082, -3.3995815899581587, -3.3368200836820088,
    -3.2740585774058557, -3.2112970711297062, -3.1485355648535567,
    -3.0857740585774067, -3.0230125523012537, -2.9602510460251041,
    -2.8974895397489546, -2.8347280334728047, -2.7719665271966583,
    -2.7092050209205021, -3.5836820083682017, -3.5209205020920522,
    -3.4581589958159022, -3.3953974895397527, -3.3326359832636032,
    -3.2698744769874533, -3.2071129707112971, -3.1443514644351476,
    -3.0815899581589976, -3.0188284518828481, -2.9560669456066986,
    -2.8933054393305486, -2.8305439330543991, -2.7677824267782425,
    -2.705020920502093, -3.5794979079497926, -3.5167364016736431,
    -3.4539748953974931, -3.3912133891213436, -3.3284518828451941,
    -3.2656903765690375, -3.202928870292888, -3.1401673640167385,
    -3.0774058577405885, -3.014644351464439, -2.9518828451882895,
    -2.8891213389121395, -2.82635983263599, -2.7635983263598267,
    -2.7008368200836839, -3.5753138075313768, -3.5125523012552207,
    -3.4497907949790778, -3.3870292887029212, -3.3242677824267783,
    -3.2615062761506217, -3.1987447698744789, -3.1359832635983227,
    -3.0732217573221661, -3.0104602510460232, -2.947698744769867,
    -2.8849372384937237, -2.8221757322175676, -2.7594142259414247,
    -2.6966527196652681, -3.5711297071129611, -3.5083682008368182,
    -3.445606694560662, -3.3828451882845187, -3.3200836820083626,
    -3.2573221757322193, -3.1945606694560631, -3.1317991631799069,
    -3.0690376569037636, -3.0062761506276074, -2.9435146443514646,
    -2.880753138075308, -2.8179916317991651, -2.7552301255230089,
    -2.6924686192468523, -3.5669456066945586, -3.5041841004184024,
    -3.4414225941422596, -3.378661087866103, -3.31589958158996,
    -3.2531380753138039, -3.1903765690376473, -3.1276150627615045,
    -3.0648535564853479, -3.002092050209205, -2.9393305439330488,
    -2.8765690376569055, -2.8138075313807493, -2.7510460251045932,
    -2.68828451882845, -3.5627615062761429, -3.5, -3.4372384937238438,
    -3.3744769874477005, -3.3117154811715444, -3.2489539748953882,
    -3.1861924686192449, -3.1234309623430887, -3.0606694560669454,
    -2.9979079497907892, -2.9351464435146464, -2.8723849372384898,
    -2.8096234309623469, -2.7468619246861774, -3.6213389121338837,
    -3.5585774058577404, -3.4958158995815976, -3.4330543933054281,
    -3.3702928870292848, -3.3075313807531419, -3.2447698744769724,
    -3.1820083682008291, -3.1192468619246863, -3.0564853556485434,
    -2.9937238493723735, -2.9309623430962306, -2.8682008368200873,
    -2.8054393305439178, -2.742677824267775, -3.6171548117154813,
    -3.554393305439338, -3.4916317991631685, -3.4288702928870256,
    -3.3661087866108823, -3.3033472803347128, -3.24058577405857,
    -3.1778242677824267, -3.1150627615062838, -3.0523012552301143,
    -2.989539748953971, -2.9267782426778282, -2.8640167364016582,
    -2.8012552301255154, -2.7384937238493725, -3.6129707112970788,
    -3.5502092050209093, -3.487447698744766, -3.4246861924686232,
    -3.3619246861924532, -3.2991631799163104, -3.2364016736401675,
    -3.1736401673640242, -3.1108786610878547, -3.0481171548117119,
    -2.9853556485355686, -2.9225941422593991, -2.8598326359832562,
    -2.7970711297071129, -2.73430962343097, -3.6087866108786497,
    -3.5460251046025069, -3.4832635983263636, -3.4205020920501941,
    -3.3577405857740508, -3.2949790794979079, -3.2322175732217651,
    -3.1694560669455951, -3.1066945606694523, -3.0439330543933094,
    -2.9811715481171395, -2.9184100418409966, -2.8556485355648538,
    -2.7928870292887105, -2.730125523012541, -3.6046025104602473,
    -3.5418410041841044, -3.4790794979079345, -3.4163179916317916,
    -3.3535564853556488, -3.2907949790795055, -3.228033472803336,
    -3.1652719665271927, -3.10251046025105, -3.0397489539748803,
    -2.976987447698737, -2.9142259414225942, -2.8514644351464513,
    -2.7887029288702814, -2.7259414225941385, -3.6004184100418448,
    -3.5376569037656753, -3.474895397489532, -3.4121338912133892,
    -3.3493723849372463, -3.2866108786610764, -3.2238493723849335,
    -3.1610878661087902, -3.0983263598326207, -3.0355648535564779,
    -2.9728033472803346, -2.9100418410041917, -2.8472803347280222,
    -2.7845188284518789, -2.7217573221757361, -3.5962343096234157,
    -3.5334728033472729, -3.4707112970711296, -3.4079497907949867,
    -3.3451882845188172, -3.2824267782426739, -3.2196652719665311,
    -3.1569037656903616, -3.0941422594142183, -3.0313807531380754,
    -2.9686192468619321, -2.9058577405857626, -2.8430962343096198 };

  boolean_T exitg1;

  /* MATLAB Function: '<S1>/MLFB' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  if (!stm32_DW.network_not_empty) {
    stm32_DW.network.IsNetworkInitialized = false;
    stm32_DW.network.matlabCodegenIsDeleted = false;
    stm32_DW.network_not_empty = true;
  }

  stm32_contributions(stm32_B.b_weights_data, stm32_B.b_weights_size,
                      stm32_B.indices_data, stm32_B.indices_size);
  stm32_B.i2 = stm32_B.b_weights_size[0];
  for (stm32_B.xoffset = 0; stm32_B.xoffset < 3; stm32_B.xoffset++) {
    for (stm32_B.b_k = 0; stm32_B.b_k < 239; stm32_B.b_k++) {
      stm32_B.b_linearInds = 76241 * stm32_B.xoffset + stm32_B.b_k;
      for (stm32_B.outCInd = 0; stm32_B.outCInd < 224; stm32_B.outCInd++) {
        stm32_B.sumVal1 = 0.0;
        stm32_B.linearInds = stm32_B.b_weights_size[0] * stm32_B.outCInd;
        for (stm32_B.k = 0; stm32_B.k < stm32_B.i2; stm32_B.k++) {
          stm32_B.sumVal1_tmp = stm32_B.linearInds + stm32_B.k;
          stm32_B.sumVal1 += (real_T)stm32_P.Constant1_Value
            [(stm32_B.indices_data[stm32_B.sumVal1_tmp] - 1) * 239 +
            stm32_B.b_linearInds] * stm32_B.b_weights_data[stm32_B.sumVal1_tmp];
        }

        if (stm32_B.sumVal1 > 255.0) {
          stm32_B.APartialResize[(stm32_B.b_k + 239 * stm32_B.outCInd) + 53536 *
            stm32_B.xoffset] = MAX_uint8_T;
        } else if (stm32_B.sumVal1 < 0.0) {
          stm32_B.APartialResize[(stm32_B.b_k + 239 * stm32_B.outCInd) + 53536 *
            stm32_B.xoffset] = 0U;
        } else if (stm32_B.sumVal1 < 4.503599627370496E+15) {
          if (stm32_B.sumVal1 >= 0.5) {
            stm32_B.APartialResize[(stm32_B.b_k + 239 * stm32_B.outCInd) + 53536
              * stm32_B.xoffset] = (uint8_T)floor(stm32_B.sumVal1 + 0.5);
          } else {
            stm32_B.APartialResize[(stm32_B.b_k + 239 * stm32_B.outCInd) + 53536
              * stm32_B.xoffset] = (uint8_T)(stm32_B.sumVal1 * 0.0);
          }
        } else {
          stm32_B.APartialResize[(stm32_B.b_k + 239 * stm32_B.outCInd) + 53536 *
            stm32_B.xoffset] = (uint8_T)stm32_B.sumVal1;
        }
      }
    }
  }

  for (stm32_B.i2 = 0; stm32_B.i2 < 1568; stm32_B.i2++) {
    stm32_B.b_indices_c[stm32_B.i2] = g[stm32_B.i2];
    stm32_B.sumVal1 = fabs(h[stm32_B.i2]);
    stm32_B.absx2_b = stm32_B.sumVal1 * stm32_B.sumVal1;
    stm32_B.absx3_p = rt_powd_snf(stm32_B.sumVal1, 3.0);
    stm32_B.absx3_m[stm32_B.i2] = ((((-0.5 * stm32_B.absx3_p + 2.5 *
      stm32_B.absx2_b) - 4.0 * stm32_B.sumVal1) + 2.0) * (real_T)
      ((stm32_B.sumVal1 > 1.0) && (stm32_B.sumVal1 <= 2.0)) + ((1.5 *
      stm32_B.absx3_p - 2.5 * stm32_B.absx2_b) + 1.0) * (real_T)(stm32_B.sumVal1
      <= 1.0)) * 0.93723849372384938;
  }

  memcpy(&stm32_B.y[0], &stm32_B.absx3_m[0], 224U * sizeof(real_T));
  for (stm32_B.i2 = 0; stm32_B.i2 < 6; stm32_B.i2++) {
    stm32_B.xoffset = (stm32_B.i2 + 1) * 224;
    for (stm32_B.b_k = 0; stm32_B.b_k < 224; stm32_B.b_k++) {
      stm32_B.y[stm32_B.b_k] += stm32_B.absx3_m[stm32_B.xoffset + stm32_B.b_k];
    }
  }

  memcpy(&stm32_B.absx[0], &stm32_B.absx3_m[0], 1568U * sizeof(real_T));
  for (stm32_B.i2 = 0; stm32_B.i2 < 7; stm32_B.i2++) {
    for (stm32_B.xoffset = 0; stm32_B.xoffset < 224; stm32_B.xoffset++) {
      stm32_B.b_k = 224 * stm32_B.i2 + stm32_B.xoffset;
      stm32_B.absx3_m[stm32_B.b_k] = stm32_B.absx[stm32_B.b_k] /
        stm32_B.y[stm32_B.xoffset];
    }
  }

  stm32_B.aux_k[0] = 1;
  stm32_B.aux_k[239] = 239;
  for (stm32_B.i2 = 0; stm32_B.i2 < 238; stm32_B.i2++) {
    stm32_B.aux_k[stm32_B.i2 + 1] = stm32_B.aux_k[stm32_B.i2] + 1;
    stm32_B.aux_k[stm32_B.i2 + 240] = stm32_B.aux_k[stm32_B.i2 + 239] - 1;
  }

  for (stm32_B.i2 = 0; stm32_B.i2 < 1568; stm32_B.i2++) {
    stm32_B.xoffset = stm32_B.b_indices_c[stm32_B.i2];
    if ((real_T)stm32_B.xoffset - 1.0 == 0.0) {
      stm32_B.b_k = 0;
    } else {
      stm32_B.b_k = (int32_T)fmod((real_T)stm32_B.xoffset - 1.0, 478.0);
      if ((stm32_B.b_k != 0) && ((real_T)stm32_B.xoffset - 1.0 < 0.0)) {
        stm32_B.b_k += 478;
      }
    }

    stm32_B.b_indices_c[stm32_B.i2] = stm32_B.aux_k[stm32_B.b_k];
  }

  stm32_B.i2 = 0;
  stm32_B.xoffset = 0;
  for (stm32_B.b_k = 0; stm32_B.b_k < 7; stm32_B.b_k++) {
    stm32_B.copyCols[stm32_B.b_k] = false;
    stm32_B.b_linearInds = stm32_B.i2 + 224;
    stm32_B.outCInd = stm32_B.i2;
    stm32_B.i2 += 224;
    exitg1 = false;
    while ((!exitg1) && (stm32_B.outCInd + 1 <= stm32_B.b_linearInds)) {
      if ((!(stm32_B.absx3_m[stm32_B.outCInd] == 0.0)) && (!rtIsNaN
           (stm32_B.absx3_m[stm32_B.outCInd]))) {
        stm32_B.copyCols[stm32_B.b_k] = true;
        exitg1 = true;
      } else {
        stm32_B.outCInd++;
      }
    }

    if (stm32_B.copyCols[stm32_B.b_k]) {
      stm32_B.xoffset++;
    }
  }

  stm32_B.k = stm32_B.xoffset;
  stm32_B.i2 = 0;
  for (stm32_B.xoffset = 0; stm32_B.xoffset < 7; stm32_B.xoffset++) {
    if (stm32_B.copyCols[stm32_B.xoffset]) {
      stm32_B.c_data[stm32_B.i2] = (int8_T)(stm32_B.xoffset + 1);
      stm32_B.i2++;
    }
  }

  stm32_B.i2 = 0;
  for (stm32_B.xoffset = 0; stm32_B.xoffset < 7; stm32_B.xoffset++) {
    if (stm32_B.copyCols[stm32_B.xoffset]) {
      stm32_B.i2++;
    }
  }

  stm32_B.b_linearInds = stm32_B.i2;
  stm32_B.i2 = 0;
  for (stm32_B.xoffset = 0; stm32_B.xoffset < 7; stm32_B.xoffset++) {
    if (stm32_B.copyCols[stm32_B.xoffset]) {
      stm32_B.d_data[stm32_B.i2] = (int8_T)(stm32_B.xoffset + 1);
      stm32_B.i2++;
    }
  }

  for (stm32_B.i2 = 0; stm32_B.i2 < 224; stm32_B.i2++) {
    for (stm32_B.b_k = 0; stm32_B.b_k < stm32_B.k; stm32_B.b_k++) {
      stm32_B.b_weights_data[stm32_B.b_k + stm32_B.k * stm32_B.i2] =
        stm32_B.absx3_m[(stm32_B.c_data[stm32_B.b_k] - 1) * 224 + stm32_B.i2];
    }

    for (stm32_B.b_k = 0; stm32_B.b_k < stm32_B.b_linearInds; stm32_B.b_k++) {
      stm32_B.indices_data[stm32_B.b_k + stm32_B.b_linearInds * stm32_B.i2] =
        stm32_B.b_indices_c[(stm32_B.d_data[stm32_B.b_k] - 1) * 224 + stm32_B.i2];
    }
  }

  for (stm32_B.xoffset = 0; stm32_B.xoffset < 672; stm32_B.xoffset++) {
    for (stm32_B.b_k = 0; stm32_B.b_k < 224; stm32_B.b_k++) {
      stm32_B.sumVal1 = 0.0;
      stm32_B.b_linearInds = stm32_B.k * stm32_B.b_k;
      for (stm32_B.outCInd = 0; stm32_B.outCInd < stm32_B.k; stm32_B.outCInd++)
      {
        stm32_B.linearInds = stm32_B.b_linearInds + stm32_B.outCInd;
        stm32_B.sumVal1 += (real_T)stm32_B.APartialResize[(239 * stm32_B.xoffset
          + stm32_B.indices_data[stm32_B.linearInds]) - 1] *
          stm32_B.b_weights_data[stm32_B.linearInds];
      }

      if (stm32_B.sumVal1 > 255.0) {
        stm32_B.B[stm32_B.b_k + 224 * stm32_B.xoffset] = MAX_uint8_T;
      } else if (stm32_B.sumVal1 < 0.0) {
        stm32_B.B[stm32_B.b_k + 224 * stm32_B.xoffset] = 0U;
      } else if (stm32_B.sumVal1 < 4.503599627370496E+15) {
        if (stm32_B.sumVal1 >= 0.5) {
          stm32_B.B[stm32_B.b_k + 224 * stm32_B.xoffset] = (uint8_T)floor
            (stm32_B.sumVal1 + 0.5);
        } else {
          stm32_B.B[stm32_B.b_k + 224 * stm32_B.xoffset] = (uint8_T)
            (stm32_B.sumVal1 * 0.0);
        }
      } else {
        stm32_B.B[stm32_B.b_k + 224 * stm32_B.xoffset] = (uint8_T)
          stm32_B.sumVal1;
      }
    }
  }

  stm_DeepLearningNetwork_predict(&stm32_DW.network, stm32_B.B,
    stm32_B.unusedExpr);

  /* End of MATLAB Function: '<S1>/MLFB' */
}

/* Model initialize function */
void stm32_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for MATLAB Function: '<S1>/MLFB' */
  stm32_DW.network.matlabCodegenIsDeleted = true;
}

/* Model terminate function */
void stm32_terminate(void)
{
  /* Terminate for MATLAB Function: '<S1>/MLFB' */
  if (!stm32_DW.network.matlabCodegenIsDeleted) {
    stm32_DW.network.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLAB Function: '<S1>/MLFB' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
