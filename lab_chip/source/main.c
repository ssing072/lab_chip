#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	enum states {INIT, WAIT, INCREMENT, DECREMENT, RESET, WAITRELEASE, WAITRELEASE2} state;
	state = INIT;
	unsigned char tempOut = 0x00;
	tempOut = 7;
	unsigned char A0 = 0x00;
	unsigned char A1 = 0x00;
	
	/* Insert your solution below */
	while (1) {
		A0 = PINA & 0x01;
		A1 = PINA & 0x02;
		switch(state){
			case INIT:
			state = WAIT;
			break;
			case WAIT:
				if(A1 && A0){
					state = RESET;
				}
				else if(A1){
					state = WAITRELEASE2;
				}
				else if(A0){
					state = WAITRELEASE;
				}
				else{
					state = WAIT;
				}
			break;
			case INCREMENT:
				state = WAIT;
				break;
			case WAITRELEASE:
				if(A1){
					state = RESET;
				}
				else if (!A0) {
					state = INCREMENT;
				} 
				else {
					state = WAITRELEASE;
				}
				break;
			case DECREMENT:
				state = WAIT;
				break;
			case WAITRELEASE2:
				if(A0){
					state = RESET;
				}
				else if (!A1) {
					state = DECREMENT;
					} 
				else {
					state = WAITRELEASE2;
				}
			break;
			case RESET:
				if((!A0) && (!A1)){
					state = WAIT;
				}
				else{
					state = RESET;
				}
				break;
		}
		switch(state){
			case INIT:
				tempOut = 7;
				break;
			case WAIT:
				break;
			case WAITRELEASE:
				break;
			case RESET:
				tempOut = 0;
				break;
			case WAITRELEASE2:
				break;
			case INCREMENT:
				if(tempOut < 9){
					tempOut = tempOut + 1;
				}
				break;
			case DECREMENT:
				if(tempOut > 0){
					tempOut = tempOut - 1;
				}
				break;
		}
		PORTC = tempOut;
	}
	return 1;
}
