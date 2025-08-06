/*
 * BUTTON.c
 *
 *  Created on: ٠١‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */


#include "../../../Inc/MCAL/DIO/DIO.h"
#include "../../../Inc/HAL/BUTTON/BUTTON.h"
#include "../../../Inc/Common/Macros.h"

void hButton_Init(uint8_t ButtonGroup, uint8_t ButtonPin) {
    mDIO_ChangeDirectionForPin(ButtonGroup, ButtonPin, DIO_Input);
    mDIO_WriteValueForPin(ButtonGroup, ButtonPin, DIO_Output); // Enable internal pull-up
}

uint8_t hButton_IsPressed(uint8_t ButtonGroup, uint8_t ButtonPin) {
    return (mDIO_ReadValueFromPin(ButtonGroup, ButtonPin) == 0); // Active Low
}
