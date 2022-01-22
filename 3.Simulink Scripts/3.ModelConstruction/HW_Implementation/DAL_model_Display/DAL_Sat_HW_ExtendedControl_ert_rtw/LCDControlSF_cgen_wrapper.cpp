#include <string.h>
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "LCDControlSF_cgen_wrapper.h"

extern void LCDControlSF_Outputs_wrapper(const uint16_T *char_val,
  const real_T *xD);
extern void LCDControlSF_Update_wrapper(const uint16_T *char_val,
  real_T *xD);
void LCDControlSF_Outputs_wrapper_cgen(const uint16_T *char_val,
  const real_T *xD)
{
  LCDControlSF_Outputs_wrapper(char_val,
    xD);
}

void LCDControlSF_Update_wrapper_cgen(const uint16_T *char_val,
  real_T *xD)
{
  LCDControlSF_Update_wrapper(char_val,
    xD);
}
