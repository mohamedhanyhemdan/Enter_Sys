/*
 * LED.h
 *
 *  Created on: ٠١‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef INC_HAL_LED_LED_H_
#define INC_HAL_LED_LED_H_

#include <stdint.h>

void hLed_Init(uint8_t LedGroup, uint8_t LedPin);
void hLed_On(uint8_t LedGroup, uint8_t LedPin);
void hLed_Off(uint8_t LedGroup, uint8_t LedPin);


#endif /* INC_HAL_LED_LED_H_ */
