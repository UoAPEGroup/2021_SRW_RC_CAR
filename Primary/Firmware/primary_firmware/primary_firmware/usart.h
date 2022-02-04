/*
 * USART.h
 *
 * Created: 18/01/2022 1:47:09 PM
 *  Author: Suzanne Lo
 */ 


#ifndef USART_H_
#define USART_H_

//global variables
uint8_t input;
uint8_t process_duty_cycle;
uint8_t process_current;
uint8_t receive_array[4];
uint8_t receive_index;

//functions
void usart_init();
uint8_t usart_receive();
void usart_transmit_byte(uint8_t byte);

#endif /* USART_H_ */