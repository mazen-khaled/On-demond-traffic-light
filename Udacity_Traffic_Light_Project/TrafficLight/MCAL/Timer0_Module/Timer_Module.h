/******************************************************************************************
  Project Name		:	Timer_Module.h
  Description		:	Timer0 Module header file
  Created on		: 	Feb 11, 2023
  Author			: 	Mazen
******************************************************************************************/

#ifndef TIMER0_MODULE_TIMER_MODULE_H_
#define TIMER0_MODULE_TIMER_MODULE_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../GPIO/gpio.h"

#define NUMBER_OF_OVERFLOWS_PER_5_SECOND 20
#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

void Timer0_Init_Normal_Mode(void);

#endif /* TIMER0_MODULE_TIMER_MODULE_H_ */
