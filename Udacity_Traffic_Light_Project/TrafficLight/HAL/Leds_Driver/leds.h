/*********************************************************************************************
  Project Name		:	leds.h
  Description		:
  Created on		: 	Feb 12, 2023
  Author			: 	Mazen
*********************************************************************************************/
#ifndef HARDWARE_LEDS_H_
#define HARDWARE_LEDS_H_

/********************************************************************************************/
/*									Used Libraries											*/
/********************************************************************************************/
#include <avr/io.h>
#include "../../MCAL/Timer0_Module/Timer_Module.h"
#include "../../MCAL/External_Interrupt_Driver/External_Interrupt_Driver.h"
#include "Common_Macros/Common_Macros.h"
/********************************************************************************************/

/********************************************************************************************/
/*									Function Declaration									*/
/********************************************************************************************/
void led_Init(void);
/*										Car traffic											*/
void carTraffic_YELLOW_LED(void);
void carTraffic_GREEN_LED(void);
void carTraffic_RED_LED(void);
/*									Pedestrian traffic										*/
void Traffics_YELLOW_LED_TOGGLE(void);
void pedTraffic_GREEN_LED(void);
void pedTraffic_RED_LED(void);
/********************************************************************************************/

#endif /* HARDWARE_LEDS_H_ */
