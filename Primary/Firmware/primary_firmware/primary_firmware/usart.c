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
#include <string.h>
#include "usart.h"
#include "output_messages.h"

//macros
#define UBRR 103 //for setting the baud rate
#define BACKSPACE 8 //ascii
#define CARRIAGE_RETURN 13 //ascii


//global variables
uint8_t input = 0; //received through usart
uint8_t process_duty_cycle = 0;
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

void usart_transmit_string(char string[]) {
	for (uint8_t i = 0; i < strlen(string); i++) {
		usart_transmit_byte(string[i]);
	}
}

ISR(USART0_RX_vect) {
	
	uint8_t input = UDR0;
	
	if (input == 'C') { //cancel 'D' or 'I' operation
		process_duty_cycle = 0;
		receive_index = 0;
		//transmit confirmation
		transmit_confirmation_cancel();
		
/////////////////////////////////////////////////
		
	} else if (process_duty_cycle) {
		if (48 <= input && input <= 57) { //a number is being transmitted
			receive_array[receive_index] = input - 48; //decode ascii and store
			receive_index++;
			
		} else {
			switch (input) {
				case BACKSPACE:
				receive_index--;
				break;
				
				case CARRIAGE_RETURN:
				if (receive_index > 0) {
					process_duty_cycle++;
				}
				break;
			}
		}
		
/////////////////////////////////////////////////
		
	} else {
		
		switch (input) {
			
			case 'D': //user will enter new duty cycle
			process_duty_cycle = 1;
			break;
			
			case '?': //show available user commands
			process_duty_cycle = 0;
					//transmit confirmation
					transmit_help();
			break;
			
			case 'X': //turn primary inverter off
			TCCR1B &= ~((1<<CS10) | (1<<CS11) | (1<<CS12));
			process_duty_cycle = 0;
			transmit_confirmation_off();
			break;
			
			case 'Y': //resume PWM with previous duty cycle
			TCCR1B |= (1<<CS10);
			process_duty_cycle = 0;
			transmit_confirmation_resume();
			break;

		} //end of switch(UDR0)
	}
} //end of ISR