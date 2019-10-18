/*	Author: ssing072
 *  Partner(s) Name: Neha Gupta
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	enum states {INIT, WAIT, RELEASE, LIGHT1, LIGHT2, LIGHT3, LIGHT4, LIGHT5, LIGHT6, LIGHT135, LIGHT246} state;
	state = INIT;
	unsigned char C = 0x00;
	unsigned char A1 = 0x00;
	while (1) {
		A1 = PINA & 0x01;
		switch(state){
			case INIT:
				state = WAIT;
				break;
			case WAIT:
				if(A1 && (C == 0x00)){
					state = LIGHT1;
				}
				else if(A1 && (C == 0x01)){
					state = LIGHT2;
				}
				else if(A1 && (C == 0x02)){
					state = LIGHT3;
				}
				else if(A1 && (C == 0x04)){
					state = LIGHT4;
				}
				else if(A1 && (C == 0x08)){
					state = LIGHT5;
				}
				else if(A1 && (C == 0x10)){
					state = LIGHT6;
				}
				else if(A1 && (C == 0x20)){
					state = LIGHT135;
				}
				else if(A1 && (C == 0x15)){
					state = LIGHT246;
				}
				else if(A1 && (C == 0x2A)){
					state = INIT;
				}
				else{
					state = WAIT;
				}
				break;
			case RELEASE:
				if(!A1){
					state = WAIT;
				else{
					state = RELEASE;
				}
			case LIGHT1:
				state = RELEASE;
				break;
			case LIGHT2:
				state = RELEASE;
				break;
			case LIGHT3:
				state = RELEASE;
				break;
			case LIGHT4:
				state = RELEASE;
				break;
			case LIGHT5:
				state = RELEASE;
				break;
			case LIGHT6:
				state = RELEASE;
				break;
			case LIGHT135:
				state = RELEASE;
				break;
			case LIGHT246:
				state = RELEASE;
				break;
		}
		switch(state){
			case INIT:
				C = 0x00;
				break;
			case WAIT:
				break;
			case RELEASE:
				break;
			case LIGHT1:
				C = 0x01;
				break;
			case LIGHT2:
				C = 0x02;
				break;
			case LIGHT3:
				C = 0x04;
				break;
			case LIGHT4:
				C = 0x08;
				break;
			case LIGHT5:
				C = 0x10;
				break;
			case LIGHT6:
				C = 0x20;
				break;
			case LIGHT135:
				C = 0x15;
				break;
			case LIGHT246:
				C = 0x2A;
				break;
		}
		PORTC = C;
	}
	return 1;
}
