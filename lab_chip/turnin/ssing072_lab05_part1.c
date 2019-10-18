#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tempA = 0x00;
	unsigned char C = 0x00;
	
	while(1){
		tempA = ~PINA;
		C = 0x00;
		if(tempA == 0x01 || tempA == 0x02){
			C = 0x60;
		}
		else if(tempA == 0x03 || tempA == 0x04){
			C = 0x70;
		}
		else if(tempA == 0x05 || tempA == 0x06){
			C = 0x38;
		}
		else if(tempA == 0x07 || tempA == 0x08 || tempA == 0x09){
			C = 0x3C;
		}
		else if(tempA == 0x0A || tempA == 0x0B || tempA == 0x0C){
			C = 0x3E;
		}
		else if(tempA == 0x0D || tempA == 0x0E || tempA == 0x0F){
			C = 0x3F;
		}
		PORTC = C;
	}
	return 1;
  }
