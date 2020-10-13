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

int count = 0;                                          // count is a variable that take trace of how many times I clicked the button
int main(void)
{

    CyGlobalIntEnable;                                  // Enable global interrupts
    PWM_RedLed_Start();                                 // Initializes the PWM linked to the Red channel of the RGB
    PWM_GreenLed_Start();                               // Initializes the PWM linked to the Green channel of the RGB
    
    ISR_Button_StartEx(ButtonPressed_ISR);              // Sets up the interrupt and enables it. Each time I click the button the interrupt starts
    ISR_Button_SetPending();                            // The interrupt is generated via software only the first time so that when we turn on the system we are in the first configuration
    
    for(;;)
    { 

    }
    
}

/* [] END OF FILE */
