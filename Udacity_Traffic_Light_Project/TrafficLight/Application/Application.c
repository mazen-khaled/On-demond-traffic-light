/******************************************************************************************
  Project Name		:	Application.c
  Description		:
  Created on		: 	Feb 11, 2023
  Author			: 	Mazen
 ******************************************************************************************/

#include "Application.h"

/*Flag indicate the person crossed the street */
uint8 FINISH_FLAG = 0;
extern uint8 i;

/*Interrupt flag*/
extern uint8 INT0_FLAG;

/*Timer flags*/
extern uint8 TIMER0_FLAG_5_SEC;

/*Car Traffic light initial color*/
uint8 trafficLight = RED;

int main(void){
	// Configure the led pin as output pin.
	led_Init();

	//Enable global interrupts in MC by setting the I-Bit.
	SET_BIT(SREG,7);

	//start the timer.
	Timer0_Init_Normal_Mode();
	//Enable External Interrupt
	INT0_Init(2);

	while(1){
		//Check for Interrupt Happened or not
		if(INT0_FLAG == 1){

			//Change Car Traffic color every 5 sec.
			if(TIMER0_FLAG_5_SEC == 1){
				trafficLight++;			//Change the traffic color every 5 sec.
				TIMER0_FLAG_5_SEC = 0;	//Reset timer 5 sec flag
			}

			//The person crossed the street when pedestrian was green so know the interrupt finished
			if( (trafficLight==YELLOW)&&(FINISH_FLAG == 1) ) {
				INT0_FLAG = 0 ;		//For exit the Interrupt
				FINISH_FLAG = 0;	//Reseting the Finishing flag to 0
				i=0;				//Finished last Interrupt code Begain new Interrupt
			}

			//The car traffic is Red then pedestrian is Green
			if(trafficLight == RED){
				carTraffic_RED_LED(); //Red car traffic is on
				pedTraffic_GREEN_LED(); //Green pedestrian traffic is on
				FINISH_FLAG = 1;	//Rising finished flag
			}

			//The car traffic is Green Or Yellow
			else {
				CLEAR_BIT(PORTA,PA2);
				//Flashing Yellow led in both pedestrian & car Traffic
				Traffics_YELLOW_LED_TOGGLE();
				pedTraffic_RED_LED();	//Red pedestrian traffic is on
				trafficLight = -1;	//reset car traffic light
			}
		}

		//Car traffic without any Interrupt
		else{
			//Setting PORTB To 0
			CLEAR_BIT(PORTB,0);
			CLEAR_BIT(PORTB,1);
			CLEAR_BIT(PORTB,2);

			//Change Car Traffic color every 5 sec.
			if(TIMER0_FLAG_5_SEC == 1){
				trafficLight++;			//Change the traffic color every 5 sec.
				TIMER0_FLAG_5_SEC = 0;	//Reset timer 5 sec flag
			}

			//The car traffic is Red then pedestrian is Green
			if(trafficLight == RED){
				carTraffic_RED_LED(); //Red car traffic is on
			}
			//The car traffic is Yellow
			else if(trafficLight == YELLOW){
				//Flashing Yellow led in car Traffic
				carTraffic_YELLOW_LED();
			}
			//The car traffic is Green
			else {
				carTraffic_GREEN_LED();	//Green car traffic is on
				trafficLight = -1;	//reset car traffic light
			}
		}
	}
}
