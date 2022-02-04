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
#include "output_messages.h"

//macros
#define UBRR 12 //for setting the baud rate
#define BACKSPACE 8 //ascii
#define CARRIAGE_RETURN 13 //ascii


//global variables
uint8_t input = 0; //received through usart
uint8_t process_duty_cycle = 0;
uint8_t process_current = 0;
uint8_t receive_array[4] = {0};
uint8_t receive_index = 0;

void usart_init() {
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0); //enable receiver and its interrupt, as well as transmitter
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); //select 8-bit data frame, no parity, one stop bit
	UBRR0 = UBRR; //set baud rate to 9600 bits/second
}

void usart_transmit_byte(uint8_t byte) {
	while (~UCSR0A & (1<<UDRE0)) {
		;
	}
	UDR0 = byte;
}

//uint8_t usart_receive() {
//while (~UCSR0A & (1<<RXC0)) {
//;
//}
//usart_transmit();
//PORTD ^= 1<<PIND5;
//return UDR0; //return UDR0
//}

ISR(USART0_RX_vect) {
	
	if (process_duty_cycle) {
		if (48 <= UDR0 && UDR0 <= 57) { //a number is being transmitted
			receive_array[receive_index] = UDR0 - 47; //decode ascii and store
			receive_index++;
			
		} else {
			switch (UDR0) {
				case BACKSPACE:
				receive_index--;
				break;
				
				case CARRIAGE_RETURN:
				process_duty_cycle++;
				//transmit confirmation
				break;
			}
	
	} else if (process_current) {
		if (48 <= UDR0 && UDR0 <= 57) { //a number is being transmitted
			receive_array[receive_index] = UDR0 - 47; //decode ascii and store
			receive_index++;
			
			} else {
			switch (UDR0) {
				case BACKSPACE:
				receive_index--;
				break;
				
				case CARRIAGE_RETURN:
				process_current++;
				//transmit confirmation
				break;
			}	
		
	} else {
		switch(UDR0) {
			case 'D': //user will enter new duty cycle
			process_duty_cycle = 1;
			process_current = 0;
			//transmit confirmation
			break;
			
			case 'I': //user will enter new secondary short circuit current
			process_current = 1;
			process_duty_cycle = 0;
			//transmit confirmation
			break;
			
			case 'X': //turn primary inverter off
			TCCR1A &= ~((1<<COM1A1) | (1<<COM1B1) | (1<<COM1B0));
			process_current = 0;
			process_duty_cycle = 0;
			//transmit confirmation
			break;
			
			case 'Y': //resume PWM with previous duty cycle
			TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<COM1B0);
			process_current = 0;
			process_duty_cycle = 0;
			//transmit confirmation
			break;
			
			case 'C': //cancel 'D' or 'I' operation
			process_duty_cycle = 0;
			process_current = 0;
			//transmit confirmation
			break;

		} //end of switch(UDR0)
	}
	usart_transmit_byte(48);
}