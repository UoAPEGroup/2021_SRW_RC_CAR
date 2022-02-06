/*
 * output_messages.c
 *
 * Created: 2/02/2022 9:15:24 PM
 *  Author: Suzanne Lo
 */ 

#include <stdio.h>
#include "output_messages.h"
#include "usart.h"
#include "global.h"


void transmit_confirmation_cancel() {
	char cancel_message[26];
	sprintf(cancel_message, "\n\r-> User input canceled\n\r");
	usart_transmit_string(cancel_message);
}

void transmit_confirmation_dc(uint8_t duty_cycle)
{
	char dc_message[24];
	sprintf(dc_message, "-> New duty cycle: %d%%\n\r", duty_cycle);
	usart_transmit_string(dc_message);
}

void transmit_confirmation_off() {
	char off_message[17];
	sprintf(off_message, "\n\r-> PWM halted\n\r");
	usart_transmit_string(off_message);
}

void transmit_confirmation_resume() {
	char resume_message[51];
	sprintf(resume_message, "\n\r-> Inverter operation resumed. Duty cycle = %d%%\n\r", get_duty_cycle());
	usart_transmit_string(resume_message);
}

void transmit_help() {
	char help_message[184];
	sprintf(help_message, "\n\r-> Available commands:\n\r"
							"D: enter new duty cycle\n\r"
							"O: get Vrms output of the inverter\n\r"
							"V: enter desired Vrms output of the inverter\n\r"
							"X: stop PWM generation\n\r"
							"Y: resume PWM generation\n\r");
	usart_transmit_string(help_message);
}

