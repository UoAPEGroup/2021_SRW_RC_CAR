/*
 * adc.c
 *
 * Created: 20/01/2022 3:00:57 PM
 *  Author: Suzanne Lo
 */ 

#include "adc.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void adc_init() {
	ADCSRA |= (1<<ADEN) | (1<<ADSC) | () |
}