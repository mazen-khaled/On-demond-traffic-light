/******************************************************************************************
  Project Name		:	Timer_Module.c
  Description		:	Timer0 Module Source file
  Created on		: 	Feb 11, 2023
  Author			: 	Mazen
******************************************************************************************/
#include "Timer_Module.h"

uint8 FIVE_SEC_TICKS = 0;
uint8 TIMER0_FLAG_5_SEC = 0;

uint8 HALF_SEC_TICKS = 0;
uint8 TIMER0_FLAG_HALF_SEC = 0;

/* Description:
 * For System Clock=1Mhz and timer prescaler is F_CPU/1024.
 * Timer frequency will be around 1Khz, Ttimer = 1ms
 * For initial timer counter = 6, overflow will occur every 250ms (6 --> 255 --> 6)
 * Overflow interrupt will be generated every 250ms, so we need two overflow interrupts to count 0.5second.
 */
void Timer0_Init_Normal_Mode(void){
	TCNT0 = 6; //Set Timer initial value to 6
	TIMSK |= (1<<TOIE0); // Enable Timer0 Overflow Interrupt

	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
}

ISR(TIMER0_OVF_vect){
	TCNT0 = 6; 			// start the timer counting again after every overflow from 6.
	HALF_SEC_TICKS++;	//Ticks for 1/2 sec
	FIVE_SEC_TICKS++;	//Ticks every 5 sec

	/*Half Second Clock Flag Generation*/
	if (HALF_SEC_TICKS == NUMBER_OF_OVERFLOWS_PER_HALF_SECOND){
		TIMER0_FLAG_HALF_SEC = 1;
		HALF_SEC_TICKS = 0;
	}

	/*5 Second End Clock Flag Generation*/
	if(FIVE_SEC_TICKS == NUMBER_OF_OVERFLOWS_PER_5_SECOND){
		TIMER0_FLAG_5_SEC = 1;
		FIVE_SEC_TICKS = 0;
	}
}
