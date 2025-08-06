/*
 * BUTTON.h
 *
 *  Created on: ٠١‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef INC_HAL_BUTTON_BUTTON_H_
#define INC_HAL_BUTTON_BUTTON_H_

#include <stdint.h>

void hButton_Init(uint8_t ButtonGroup, uint8_t ButtonPin);
uint8_t hButton_IsPressed(uint8_t ButtonGroup, uint8_t ButtonPin);


#endif /* INC_HAL_BUTTON_BUTTON_H_ */
