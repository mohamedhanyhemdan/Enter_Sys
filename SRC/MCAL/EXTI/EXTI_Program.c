/*
 * EXTI_Program.c
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */


#include "../../../Inc/MCAL/NTI_Atmega32Reg.h"
#include "../../../Inc/MCAL/EXTI/EXTI_Interface.h"
#include "../../../Inc/Common/Macros.h"


void mEXTI0_Enable(uint8_t SensControl)
{
    // Clear ISC00 and ISC01 bits (MCUCR bits 0 and 1)
    MCUCR_Reg &= ~((1 << EXTI_ISC00) | (1 << EXTI_ISC01));

    // Set ISC00 and ISC01 according to SensControl
    switch (SensControl) {
        case EXTI_LowLevel:
            // ISC01 = 0, ISC00 = 0
            break;

        case EXTI_AnyChange:
            // ISC01 = 0, ISC00 = 1
        	MCUCR_Reg |= (1 << EXTI_ISC00);
            break;

        case EXTI_Falling:
            // ISC01 = 1, ISC00 = 0
        	MCUCR_Reg |= (1 << EXTI_ISC01);
            break;

        case EXTI_Rising:
            // ISC01 = 1, ISC00 = 1
        	MCUCR_Reg |= (1 << EXTI_ISC00) | (1 << EXTI_ISC01);
            break;

        default:
            // Default to low level if invalid value
            break;
    }

    // Enable INT0 (bit 6 in GICR)
    GICR_Reg |= (1 << EXTI_INT0);
}

void mEXTI1_Enable(uint8_t SensControl)
{

}

void mEXTI2_Enable(uint8_t SensControl)
{
//	 * 		1- Check on SensControl
//	 * 			if SensControl == 2
//	 * 				Bit 6 in MCUCSR Register must be 0
//	 * 			if SensControl == 3
//	 * 				Bit 6 in MCUCSR Register must be 1
//	 * 		2- Enable the SIE For EXTI2
//	 * 			Bit 5 in GICR Resister  must be One
	if(SensControl==EXTI_Falling)
	{
		ClearBit(MCUCSR_Reg,EXTI_ISC2);
	}
	else if (SensControl==EXTI_Rising)
	{
		SetBit(MCUCSR_Reg,EXTI_ISC2);
	}
	else
	{
		// Not Vaild Options
	}
	SetBit(GICR_Reg,EXTI_INT2);
}
