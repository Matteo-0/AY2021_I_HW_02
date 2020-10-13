/*
*   \file InterruptRoutines.c
*   \Brief InterruptRoutines header file for the second assignment.
*
*   This interrupt is called every time I push the button and its task is to update the variable count.
*
*   Author: Matteo Boles
*   Date: October 13, 2020
*/

#include "InterruptRoutines.h"
#define PWMClockFrequency 30000                                 // define the clock frequency of the PWM

CY_ISR(ButtonPressed_ISR)
{
    count++;                                                    // count in incremented each time we click the button
    CyDelay(50);                                                // Delay of 50 ms before entering the next configuration

        switch (count)                                          // Each time I click the button I will enter a different configuration 
        {
            case (1):
            PWM_RedLed_WriteCompare(2*PWMClockFrequency);       // Sets how much time the wave, driving the Red channel, stays high with respect to the whole period
            PWM_GreenLed_WriteCompare(2*PWMClockFrequency);     // Sets how much time the wave, driving the Green channel, stays high with respect to the whole period 
            PWM_RedLed_SetCompareMode(3);                       // Sets if the wave, driving the Red channel, starts with a low or high value
            PWM_GreenLed_SetCompareMode(3);                     // Sets if the wave, driving the Green channel, starts with a low or high value
            PWM_RedLed_WritePeriod(2*PWMClockFrequency);        // Sets the period value used by the PWM hardware for the Red channel
            PWM_GreenLed_WritePeriod(2*PWMClockFrequency);      // Sets the period value used by the PWM hardware for the Green channel
            break;
            case (2):
            PWM_RedLed_WriteCompare(2*PWMClockFrequency);
            PWM_GreenLed_WriteCompare(PWMClockFrequency);
            PWM_RedLed_SetCompareMode(3);
            PWM_GreenLed_SetCompareMode(3);  
            PWM_RedLed_WritePeriod(2*PWMClockFrequency);
            PWM_GreenLed_WritePeriod(2*PWMClockFrequency);    
            break;
            case (3):
            PWM_RedLed_WriteCompare(PWMClockFrequency);
            PWM_GreenLed_WriteCompare(2*PWMClockFrequency);
            PWM_RedLed_SetCompareMode(2);
            PWM_GreenLed_SetCompareMode(3); 
            PWM_RedLed_WritePeriod(2*PWMClockFrequency);
            PWM_GreenLed_WritePeriod(2*PWMClockFrequency);
            break;
            case (4):
            PWM_RedLed_WriteCompare(PWMClockFrequency/2);
            PWM_GreenLed_WriteCompare(PWMClockFrequency/2);    
            PWM_RedLed_SetCompareMode(3);
            PWM_GreenLed_SetCompareMode(2); 
            PWM_RedLed_WritePeriod(PWMClockFrequency);
            PWM_GreenLed_WritePeriod(PWMClockFrequency);
            break;
            case (5):
            PWM_RedLed_WriteCompare((PWMClockFrequency/4));
            PWM_GreenLed_WriteCompare((PWMClockFrequency/4));
            PWM_RedLed_SetCompareMode(2);
            PWM_GreenLed_SetCompareMode(3);  
            PWM_RedLed_WritePeriod(PWMClockFrequency/2);
            PWM_GreenLed_WritePeriod(PWMClockFrequency/2);  
            break;
            case (6):
            PWM_RedLed_WriteCompare(PWMClockFrequency/2);
            PWM_GreenLed_WriteCompare(PWMClockFrequency);
            PWM_RedLed_SetCompareMode(2);
            PWM_GreenLed_SetCompareMode(2);  
            PWM_RedLed_WritePeriod(2*PWMClockFrequency);
            PWM_GreenLed_WritePeriod(2*PWMClockFrequency); 
            break;
            case (7):
            PWM_RedLed_WriteCompare(PWMClockFrequency);
            PWM_GreenLed_WriteCompare(PWMClockFrequency/2);
            PWM_RedLed_SetCompareMode(2);
            PWM_GreenLed_SetCompareMode(2); 
            PWM_RedLed_WritePeriod(2*PWMClockFrequency);
            PWM_GreenLed_WritePeriod(PWMClockFrequency);
            count=0;                                           // In the last case I update count to zero so that when I press the button again I restart from the first case
            break;
            
        } 
}
/* [] END OF FILE */

