
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>

#ifndef MATLAB_MEX_FILE
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal.cpp>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void LCDControlSF_Outputs_wrapper(const uint16_T *char_val,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] == 1)
{
#ifndef MATLAB_MEX_FILE
lcd.setCursor(0, 1);
if(char_val[0] < 100) lcd.print("      ");
if(char_val[0] < 10) lcd.print("       ");
lcd.print(char_val[0]);
#endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void LCDControlSF_Update_wrapper(const uint16_T *char_val,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] != 1)
{
    #ifndef MATLAB_MEX_FILE
      // set up the LCD's number of columns and rorws:
    lcd.begin(16, 2);
      // print a message to the LCD
    lcd.print("Incidence Angle [deg]:");
    #endif
      // done with initialization
xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

