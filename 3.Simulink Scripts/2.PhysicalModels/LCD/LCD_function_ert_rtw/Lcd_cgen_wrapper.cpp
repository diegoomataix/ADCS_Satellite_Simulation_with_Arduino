#include <string.h>
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "Lcd_cgen_wrapper.h"

extern void Lcd_Outputs_wrapper(const uint16_T *char_val,
  const real_T *xD);
extern void Lcd_Update_wrapper(const uint16_T *char_val,
  real_T *xD);
void Lcd_Outputs_wrapper_cgen(const uint16_T *char_val,
  const real_T *xD)
{
  Lcd_Outputs_wrapper(char_val,
                      xD);
}

void Lcd_Update_wrapper_cgen(const uint16_T *char_val,
  real_T *xD)
{
  Lcd_Update_wrapper(char_val,
                     xD);
}
