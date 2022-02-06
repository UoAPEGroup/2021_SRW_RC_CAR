/*
 * calculations.c
 *
 * Created: 3/02/2022 8:34:57 PM
 *  Author: Suzanne Lo
 */ 

#include "processing.h"
#include "usart.h"

uint8_t extract_duty_cycle(uint8_t array[4]) {
	switch (receive_index) {
		case 1:
			return array[0];
		case 2:
			return array[0]*10 + array[1];
		case 3:
			return array[0]*100 + array[1]*10 + array[2];
		default:
		return 0;
	}
}
