/*
*   \file main.c
*   \Brief main source file for the second assignment.
*
*   This file allows to change the blinking state of an RGB Led by clicking a button.
*
*   Author: Matteo Boles
*   Date: October 13, 2020
*/

#include "project.h"                                         
#include "InterruptRoutines.h" 
#define PWMClockFrequency 30000                         // define the clock frequency of the PWM

int count = 1;                                          // count is a variable that take trace of how many times I clicked the button
int main(void)
{

    CyGlobalIntEnable;                                  // Enable global interruptsù
    PWM_RedLed_Start();                                 // Initializes the PWM linked to the Red channel of the RGB
    PWM_GreenLed_Start();                               // Initializes the PWM linked to the Green channel of the RGB
    
    // I set the parameter of the PWM so that when we start the system we enter directly the first configuration where both channels (Red and Green) are active
    PWM_RedLed_WriteCompare(2*PWMClockFrequency);       // Sets how much time the wave, driving the Red channel, stays high with respect to the whole period
    PWM_GreenLed_WriteCompare(2*PWMClockFrequency);     // Sets how much time the wave, driving the Green channel, stays high with respect to the whole period 
    PWM_RedLed_SetCompareMode(4);                       // Sets if the wave, driving the Red channel, starts with a low or high value
    PWM_GreenLed_SetCompareMode(4);                     // Sets if the wave, driving the Green channel, starts with a low or high value
    PWM_RedLed_WritePeriod(2*PWMClockFrequency);        // Sets the period value used by the PWM hardware for the Red channel
    PWM_GreenLed_WritePeriod(2*PWMClockFrequency);      // Sets the period value used by the PWM hardware for the Green channel
    
    ISR_Button_StartEx(ButtonPressed_ISR);              // Sets up the interrupt and enables it. Each time I click the button the interrupt starts

    for(;;)
    { 

    }
    
}

/* [] END OF FILE */
