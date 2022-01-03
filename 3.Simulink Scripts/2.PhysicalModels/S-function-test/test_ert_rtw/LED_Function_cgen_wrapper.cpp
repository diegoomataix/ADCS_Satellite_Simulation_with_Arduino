#include <string.h>
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "LED_Function_cgen_wrapper.h"

extern void LED_Function_Outputs_wrapper(const real_T *xD);
extern void LED_Function_Update_wrapper(real_T *xD);
void LED_Function_Outputs_wrapper_cgen(const real_T *xD)
{
  LED_Function_Outputs_wrapper(xD);
}

void LED_Function_Update_wrapper_cgen(real_T *xD)
{
  LED_Function_Update_wrapper(xD);
}
