/*
 * GIE.c
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */


#include "../../../Inc/MCAL/GIE/GIE_Interface.h"
#include "../../../Inc/Common/Macros.h"



void mGIE_Enable()
{
	SetBit(SREG_Reg,GIE_Bit);
}
void mGIE_Disable()
{
	ClearBit(SREG_Reg,GIE_Bit);
}
