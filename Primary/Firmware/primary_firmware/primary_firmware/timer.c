/*
 * timer.c
 *
 * Created: 18/01/2022 9:21:51 PM
 *  Author: Suzanne Lo
 */ 

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define TOP_COUNTS 1024

//void timer0_init() {
//DDRD |= (1<<PIND5) | (1<<PIND6); //pwm pins set as outputs
//TCCR0A |= (1<<COM0A1) | (1<<COM0B0) | (1<<COM0B1) | (1<<WGM00);
//TCCR0B |= (1<<CS01) | (1<<CS02);
//OCR0A = 127;
//OCR0B = 127;
//}

void timer1_init(uint8_t duty_cycle) {
	DDRB |= (1<<PINB1) | (1<<PINB2); //pwm pins set as outputs
	TCCR1A |= (1<<COM1A1) | /*(1<<COM1A0) |*/ (1<<COM1B1) | (1<<COM1B0) |(1<<WGM10) | (1<<WGM11);
	TCCR1B |= (1<<CS10) /*| (1<<WGM13)*/;
	OCR1A = (uint16_t)TOP_COUNTS*(100-duty_cycle)/100;
	OCR1B = (uint16_t)TOP_COUNTS*(100-duty_cycle)/100;
}

void change_duty_cycle(uint8_t duty_cycle) {
	TCCR1B &= ~(1<<CS10) | ~(1<<CS11) | ~(1<<CS12);
	OCR1A = (uint16_t)TOP_COUNTS*(100-duty_cycle)/100;
	OCR1B = (uint16_t)TOP_COUNTS*(100-duty_cycle)/100;
	TCCR1B |= (1<<CS10);
}