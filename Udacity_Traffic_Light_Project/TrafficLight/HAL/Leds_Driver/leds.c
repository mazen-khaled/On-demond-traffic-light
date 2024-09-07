/*********************************************************************************************
  Project Name		:	leds.c
  Description		:
  Created on		: 	Feb 12, 2023
  Author			: 	Mazen
 *********************************************************************************************/

#include "leds.h"
extern unsigned char TIMER0_FLAG_HALF_SEC;

/*********************************************************************************************
*									Initialize light
*********************************************************************************************/

/* Description:
 * Setting all pins (0-1-2) in PORTA & PORTB To be OUTPUT Pins
 * return type: Void
 */
void led_Init(void){
	DDRA  |= (1<<PA0)|(1<<PA1)|(1<<PA2);
	DDRB  |= (1<<PB0)|(1<<PB1)|(1<<PB2);
}

/*********************************************************************************************
*									Car Traffic light
*********************************************************************************************/
/* Description:
 * Setting GREEN led at pin 2 PORTA
 * return type: Void
 */
void carTraffic_GREEN_LED(void){
	PORTA = (1<<PA2);
}

/* Description:
 * Setting RED led at pin 0 PORTA
 * return type: Void
 */
void carTraffic_RED_LED(void){
	PORTA = (1<<PA0);
}

/* Description:
 * Toggling yellow led at pin 1 PORTA
 * return type: Void
 */
void carTraffic_YELLOW_LED(void){
	if(TIMER0_FLAG_HALF_SEC == 1){
		//Reset PORTA PIN PA0
		PORTA &= ~(1<<PA0);
		//Toggle PORTA PIN PA1 & Same as PB1
		TOGGLE_BIT(PORTA,PA1);
		//Reset Timer half sec flag
		TIMER0_FLAG_HALF_SEC = 0;
	}
}

/********************************************************************************************
									Pedestrian Traffic lights
*********************************************************************************************/

/* Description:
 * Toggling yellow led at pin 1 PORTA & pin 1 PORTB
 * return type: Void
 */
void Traffics_YELLOW_LED_TOGGLE(void){
	if(TIMER0_FLAG_HALF_SEC == 1){

		//Reset PORTA PIN PA0
		CLEAR_BIT(PORTA,PA0);

		//Toggle PORTA PIN PA1 & Same as PB1
		TOGGLE_BIT(PORTA,PA1);
		TOGGLE_BIT(PORTB,PB1);

		//Reset Timer half sec flag
		TIMER0_FLAG_HALF_SEC = 0;
	}
}

/* Description:
 * Setting Green led at pin 2 PORTB
 * return type: Void
 */
void pedTraffic_GREEN_LED(void){
	PORTB = (1<<PB2);
}

/* Description:
 * Setting Red led at pin 0 PORTB
 * return type: Void
 */
void pedTraffic_RED_LED(void){
	SET_BIT(PORTB,PB0);
}
