#ifndef _LCD_CGEN_WRAPPER_H_
#define _LCD_CGEN_WRAPPER_H_
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void Lcd_Outputs_wrapper_cgen(const uint16_T *char_val,
  const real_T *xD);
SFB_EXTERN_C void Lcd_Update_wrapper_cgen(const uint16_T *char_val,
  real_T *xD);

#undef SFB_EXTERN_C
#endif
