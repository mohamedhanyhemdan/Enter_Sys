/*
 * LED.c
 *
 *  Created on: ٠١‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */


#include "../../../Inc/MCAL/DIO/DIO.h"
#include "../../../Inc/HAL/LED/LED.h"
#include "../../../Inc/Common/Macros.h"

void hLed_Init(uint8_t LedGroup, uint8_t LedPin) {
    mDIO_ChangeDirectionForPin(LedGroup, LedPin, DIO_Output);
}

void hLed_On(uint8_t LedGroup, uint8_t LedPin) {
    mDIO_WriteValueForPin(LedGroup, LedPin, DIO_Output);
}

void hLed_Off(uint8_t LedGroup, uint8_t LedPin) {
    mDIO_WriteValueForPin(LedGroup, LedPin, DIO_Input);
}
