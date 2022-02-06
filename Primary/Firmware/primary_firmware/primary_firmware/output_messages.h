/*
 * output_messages.h
 *
 * Created: 2/02/2022 9:15:43 PM
 *  Author: Suzanne Lo
 */ 


#ifndef OUTPUT_MESSAGES_H_
#define OUTPUT_MESSAGES_H_

void transmit_confirmation_cancel();
void transmit_confirmation_dc(uint8_t duty_cycle);
void transmit_confirmation_off();
void transmit_confirmation_resume();
void transmit_help();



#endif /* OUTPUT_MESSAGES_H_ */