/*
* primary_firmware.c
*
* Created: 18/01/2022 12:50:42 PM
* Author : Suzanne Lo
*/
#define F_CPU 2000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "usart.h"
#include "timer.h"
#include "adc.h"
#include <util/delay.h>

int main(void) {
	sei();
	usart_init();
	timer1_init(40); //PWM to gate drivers, input parameter = duty cycle
	//adc_init();
	//timer0_init();
	
	DDRD |= (1<<PIND5);
	
	while (1)
	{
		if (process_current == 2) {
			; 
			//make duty cycle 
			//enter it into timer
			} else if (process_duty_cycle == 2) {
			;
			//make duty cycle
			//enter it into timer
		}
	}
}

