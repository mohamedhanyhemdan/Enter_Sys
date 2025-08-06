/*
 * ADC_Program.c
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */



#include "../../../Inc/MCAL/NTI_Atmega32Reg.h"
#include "../../../Inc/MCAL/ADC/ADC_Interface.h"
#include "../../../Inc/Common/Macros.h"

/*
 * Zero : ClearBit
 * One  : SetBit */
/*1- ADIE= 0 -> ADC No Interrupt
 *2- By ADATE :  Single Mode Conversion
 *3- Aref = AVCC
 *4- Right Adjust
 *4- Seclect Prescaller / 8
 *5- Enable ADC
 *-  */
void mADC_Init()
{
	/* No Interrupt
		1- ADIE in ADCSRA  Must be Zero
	*/
	ClearBit(ADCSRA_Reg,ADIE_Bit);
	/*
	 * Single Mode Conversion
	 * 1- ADATE in ADCSRA Must be Zero */
	ClearBit(ADCSRA_Reg,ADATE_Bit);
	/*
	 * Aref == AVCC
	 * 1- REFS1 in ADMUX Must be 0
	 * 2- REFS0 in ADMUX Must be 1
	 * */
	ClearBit(ADMUX_Reg,REFS1_Bit);
	SetBit(ADMUX_Reg,REFS0_Bit);
	/*
	 *Right Adjust
	 *ADLAR in ADMUX Must be 0  */
	ClearBit(ADMUX_Reg,ADLAR_Bit);
	/*Prescaller =  8
	 * 1- ADPS0 in ADCSRA Must be  1
	 * 2- ADPS1 in ADCSRA Must be  1
	 * 1- ADPS2 in ADCSRA Must be  0
	 * */
	SetBit(ADCSRA_Reg,ADPS0_Bit);
	SetBit(ADCSRA_Reg,ADPS1_Bit);
	ClearBit(ADCSRA_Reg,ADPS2_Bit);
	/*
	 * ADC Enbale
	 * 1- ADEN in ADCSRA Must be 1 */
	SetBit(ADCSRA_Reg,ADEN_Bit);
}




/*
 * Mux4:Mux0 -> Select Channel
 * Start Conversion
 * wait until flag on ADIF:
 * read the ADCH And ADCL */

//mADC_SignleEndedConversion(5);
//mADC_SignleEndedConversion(7);

uint16_t mADC_SignleEndedConversion(uint8_t Channel)// 0 - 7 (00000111)
{
	/*
	 * InputChannel -> Last 5 Bit Must be Zero
	 * Channel  ->    1 0 1 0 1 1 1 0
	 * &
	 *                0 0 0 0 0 1 1 1
	 *              --------------------
	 *                0 0 0 0 0 1 1  0
	 * */
	/*
	 * ADMUX: 7 6 5 M4 M3 M2 M1 M0
	 * |      0 0 0 C4 C3 C2 C1 C0  ->
	 *
	 * */
	/*Channel */
//	Channel   = Channel & (0b00000111);
	Channel   = Channel & (0x07);
	ADMUX_Reg = ADMUX_Reg| Channel ;
	/*
	 * mADC_SignleEndedConversion(5)
	 * Channel  -> 000 0 0101
	 * ADMUX    -> 101 0 0000
	 * Ch|ADMUX -> 101 0 0101
	 * New ADMUX -> 101 0 0101
	 * ------------------------------------
	 * mADC_SignleEndedConversion(7)
	 * Channel  ->  000 0 0111
	 * ADMUX    ->  101 0 0101
	 * Ch|ADMUX ->  101 0 0111
	 *
	 * */
	/*Start Conversion
	 * 1- ADSC in ADCSRA must be 1 */
	SetBit(ADCSRA_Reg,ADSC_Bit);
	while(GetBit(ADCSRA_Reg,ADIF_Bit)==0)
	{
		// Waiting
		// this loop will terminated when the ADIF = 1
	}
	// Clear ADIF By SW
		// Write Logic 1 on ADIF
	SetBit(ADCSRA_Reg,ADIF_Bit);
	return ADCData_Reg;

}
