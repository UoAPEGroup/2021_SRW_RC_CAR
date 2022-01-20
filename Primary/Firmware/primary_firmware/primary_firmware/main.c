/*
 * primary_firmware.c
 *
 * Created: 18/01/2022 12:50:42 PM
 * Author : Suzanne Lo
 */ 
#define F_CPU 2000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include "usart.h"
#include "timer.h"
#include "adc.h"
#include <util/delay.h>

int main(void)
{
	usart_init();
	timer1_init(70);
	adc_init();
	//timer0_init();
	sei();
	
	DDRD |= (1<<PIND5);
	
    while (1)
    {
    }
}

