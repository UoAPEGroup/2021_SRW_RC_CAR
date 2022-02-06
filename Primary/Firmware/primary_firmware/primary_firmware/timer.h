/*
 * timer.h
 *
 * Created: 18/01/2022 9:21:40 PM
 *  Author: Suzanne Lo
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

void timer1_init(uint8_t duty_cycle);
void timer0_init();
void change_duty_cycle(uint8_t duty_cycle);



#endif /* TIMER_H_ */