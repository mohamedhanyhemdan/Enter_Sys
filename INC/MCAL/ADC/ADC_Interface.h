/*
 * ADC_Interface.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef INC_MCAL_ADC_ADC_INTERFACE_H_
#define INC_MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_Private.h"
#include <stdint.h>

/*1- ADIE= 0 -> ADC No Interrupt
 *2- By ADATE :  Single Mode Conversion
 *3- Aref = AVCC
 *4- Right Adjust
 *4- Seclect Prescaller
 *5- Enable ADC
 *-  */
void mADC_Init();
/*
 * Mux4:Mux0
 * Start Conversion
 * wait until flag on ADIF:
 * read the ADCH And ADCL */
uint16_t mADC_SignleEndedConversion(uint8_t Channel);

#endif /* INC_MCAL_ADC_ADC_INTERFACE_H_ */
