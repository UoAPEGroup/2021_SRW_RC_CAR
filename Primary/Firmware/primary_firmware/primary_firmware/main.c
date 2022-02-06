/*
* primary_firmware.c
*
* Created: 18/01/2022 12:50:42 PM
* Author : Suzanne Lo
*/
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "usart.h"
#include "timer.h"
#include "adc.h"
#include "processing.h"
#include "output_messages.h"
#include "global.h"

//Static variables
static uint8_t duty_cycle = 0;

//Functions
uint8_t get_duty_cycle() {
	return duty_cycle;
}

int main(void) {
		
	sei();
	usart_init();
	timer1_init(duty_cycle); //PWM to gate drivers
	//adc_init();
	//timer0_init();
	
	DDRD |= (1<<PIND5);
	
	transmit_help();
	
	while (1)
	{
		if (process_duty_cycle == 2) {
			duty_cycle = extract_duty_cycle(receive_array);
			change_duty_cycle(duty_cycle);
			transmit_confirmation_dc(duty_cycle);
			process_duty_cycle = 0;
			receive_index = 0;
		}
	}
}

