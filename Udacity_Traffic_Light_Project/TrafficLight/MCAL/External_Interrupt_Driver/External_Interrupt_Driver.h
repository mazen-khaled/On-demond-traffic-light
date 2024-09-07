/*********************************************************************************************
  Project Name		:	External_Interrupt_Driver.h
  Description		:	External Interrupt Module header file
  Created on		: 	Feb 11, 2023
  Author			: 	Mazen
*********************************************************************************************/


#ifndef EXTERNAL_INTERRUPT_DRIVER_EXTERNAL_INTERRUPT_DRIVER_H_
#define EXTERNAL_INTERRUPT_DRIVER_EXTERNAL_INTERRUPT_DRIVER_H_

///////////////////////////////////////////////////////////////////////////////////////////
/*								Common Used Header Files								*/
#include "Common_Macros/Common_Macros.h"
#include "../GPIO/gpio.h"
//////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////
/*									Types Definitions									*/
typedef enum {
	LOW_LEVEL,HIGH_LEVEL,RISING_EDGE,FALLING_EDGE
}trigger_type;
//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
/*									Functions Prototypes								*/
void INT0_Init(trigger_type typ);
void INT1_Init(trigger_type typ);
void INT2_Init(trigger_type typ);
///////////////////////////////////////////////////////////////////////////////////////////


#endif /* EXTERNAL_INTERRUPT_DRIVER_EXTERNAL_INTERRUPT_DRIVER_H_ */
