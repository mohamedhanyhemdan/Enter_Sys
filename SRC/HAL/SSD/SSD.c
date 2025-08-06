/*
 * SSD.c
 *
 *  Created on: ٠١‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */


#include "../../../Inc/MCAL/DIO/DIO.h"
#include "../../../Inc/HAL/SSD/SSD.h"
#include "../../../Inc/Common/Macros.h"

static const uint8_t SSD_LookupTable[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

void hSSD_Init(uint8_t SSD_Group) {
    mDIO_ChangeDirectionforGroup(SSD_Group, 0xFF); // All 8 pins as output
}

void hSSD_DisplayNumber(uint8_t Number, uint8_t SSD_Group) {
    if (Number < 10) {
        mDIO_WriteValueForGroup(SSD_Group, SSD_LookupTable[Number]);
    }
}
