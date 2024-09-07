/******************************************************************************************
  Project Name		:	External_Interrupt_Driver.c
  Description		:	External Interrupt Module Source file
  Created on		: 	Feb 11, 2023
  Author			: 	Mazen
******************************************************************************************/

#include "External_Interrupt_Driver.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/*Global Variables*/
uint8 INT0_FLAG = 0;
uint8 i = 0;

extern uint8 HALF_SEC_TICKS;
extern uint8 FIVE_SEC_TICKS;
/*Functions Definitions*/

/*Description : Initialization INT0 For Interrupt
 *Parameters  : Trigger type (LOW_LEVEL - HIGH_LEVEL - RISING_EDGE - FALLING_EDGE)
 * */
void INT0_Init(trigger_type typ){
	//Setting PD2/INT0 Pin to be an Input
	CLEAR_BIT(DDRD,PD2);

	//Enable Global Interrupt unit
	SET_BIT(SREG,7);

	//Check the needed Trigger level
	switch(typ){
	//Low Level Trigger
	case 0:
		CLEAR_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01);
		break;

		//High Level Trigger
	case 1:
		SET_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01);
		break;

		//Rising Edge Trigger
	case 2:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;

		//Falling Edge Trigger
	case 3:
		CLEAR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;
	default: return;
	}
	//Enable INT0 Interrupt unit
	SET_BIT(GICR,INT0);
}

/*Description : Initialization INT1 For Interrupt*/
void INT1_Init(trigger_type typ){
	//Setting PD3/INT1 Pin to be an Input
	CLEAR_BIT(DDRD,PD3);

	//Enable Global Interrupt unit
	SET_BIT(SREG,7);

	//Check the needed Trigger level
	switch(typ){
	//Low Level Trigger
	case 0:
		CLEAR_BIT(MCUCR,ISC10);
		CLEAR_BIT(MCUCR,ISC11);
		break;

		//High Level Trigger
	case 1:
		SET_BIT(MCUCR,ISC10);
		CLEAR_BIT(MCUCR,ISC11);
		break;

		//Rising Edge Trigger
	case 2:
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		break;

		//Falling Edge Trigger
	case 3:
		CLEAR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		break;
	default: return;
	}
	//Enable INT0 Interrupt unit
	SET_BIT(GICR,INT1);
}

/*Description : Initialization INT2 For Interrupt*/
void INT2_Init(trigger_type typ){
	//Setting PB2/INT2 Pin to be an Input
	CLEAR_BIT(DDRB,PB2);

	//Enable Global Interrupt unit (I-BIT)
	SET_BIT(SREG,7);

	//Check the needed Trigger level
	switch(typ){
		//Rising Edge Trigger
	case 2:
		SET_BIT(MCUCSR,ISC2);
		break;
		//Falling Edge Trigger
	case 3:
		CLEAR_BIT(MCUCSR,ISC2);
		break;
	default: return;
	}
	//Enable INT2 Interrupt unit
	SET_BIT(GICR,INT2);
}

/*ISR Code*/

/*Description : Interrupted code for INT0*/
ISR (INT0_vect){
	if(i == 1){
		// for double click or long press Interrupt canceling
	}
	else{
		INT0_FLAG = 1;
		HALF_SEC_TICKS = 0;
		FIVE_SEC_TICKS = 0;
		i = 1;
	}
}

/*Description : Interrupted code for INT1*/
ISR (INT1_vect){

}

/*Description : Interrupted code for INT2*/
ISR (INT2_vect){

}

