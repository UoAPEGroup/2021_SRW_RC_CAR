/*
 * USART.c
 *
 * Created: 18/01/2022 1:46:55 PM
 *  Author: Suzanne Lo
 */ 

//header files
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "USART.h"

//macros
#define UBRR 12

//global variables
uint8_t data = 0; //received through usart

void usart_init() { 
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
	UBRR0 = UBRR;
}

uint8_t usart_receive() {
	while (~UCSR0A & (1<<RXC0)) {
		;
	}
	
	PORTD ^= 1<<PIND5;
	return 1; //return UDR0
}

ISR(USART_RX_vect) {
	data = UDR0;
}

//void usart_transmit() {
	//while (~UCSR0A & (1<<UDRE0)) {
		//;
	//}
	//
	//PORTD |= 1<<PIND5;
	//UDR0 = 49;
//}