/*	Author: terry
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
//Demo: https://drive.google.com/open?id=1zUX5Xzoqq9iWar2JXJUjxfpwv2DbAZ0P
void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1<< ADATE);
}
int main(void) {
    ADC_init();
    
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    while (1) {
	unsigned short val = ADC;
	unsigned char low  = (char)val;
	unsigned char high = (char)(val >> 8);
	unsigned char max = 0x3F;

	if(val < max/2){
		PORTB = 0x01;
	}
	else{
		PORTB = 0x00;
	}
	

    }
    return 1;
}
