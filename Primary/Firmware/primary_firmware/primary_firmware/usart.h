/*
 * USART.h
 *
 * Created: 18/01/2022 1:47:09 PM
 *  Author: Suzanne Lo
 */ 


#ifndef USART_H_
#define USART_H_

//global variables
uint8_t data;


//functions
void usart_init();
uint8_t usart_receive();
void usart_transmit();

#endif /* USART_H_ */