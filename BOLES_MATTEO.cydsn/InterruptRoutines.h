/*
*   \file InterruptRoutines.h
*   \Brief InterruptRoutines source file for the second assignment.
*
*   In this file there is the declaration of the function.
*
*   Author: Matteo Boles
*   Date: October 13, 2020
*/

#ifndef __INTERRUPT_ROUTINES_H 
    #define __INTERRUPT_ROUTINES_H
    #include "project.h"
    
    extern int count;                       // Declaration of a global variable
    CY_ISR_PROTO(ButtonPressed_ISR);        // Declaration of the function
#endif
/* [] END OF FILE */
