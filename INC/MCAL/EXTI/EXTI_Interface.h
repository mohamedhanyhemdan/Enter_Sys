/*
 * EXTI_Interface.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef INC_MCAL_EXTI_EXTI_INTERFACE_H_
#define INC_MCAL_EXTI_EXTI_INTERFACE_H_

/*EXTI_Private.h*/
#define EXTI_LowLevel    0
#define EXTI_AnyChange   1
#define EXTI_Falling     2
#define EXTI_Rising      3
/*EXTI_Private.h -> Name OF SIE For Specific EXTI */
#define EXTI_ISC00       0
#define EXTI_ISC01       1
#define EXTI_ISC10       2
#define EXTI_ISC11       3

#define EXTI_ISC2         6

#define EXTI_INT1        7
#define EXTI_INT0        6
#define EXTI_INT2        5
/**
 * SensControl:
 * 	LowLevel  = 0
 * 	AnyChange = 1
 * 	Falling   = 2
 * 	Rising    = 3
 * 	 Sudo Code for mEXTI0_Enable (uint8_t SensControl)
 * 	 {
 * 	 	1- Check on the SensControl  Option
 * 	 		if SensControl == 0
 * 	 			Bit1  And Bit 0 in MCUCR Register must be zero
 * 	 		if SensControl == 1
 * 	 			Bit 1 in MCUCR Register must be Zero    And
 * 	 			Bit 0  in MCUCR Register must be One
 * 	 		if SensControl == 2
 * 	 			Bit 1 in MCUCR Register must be One    And
 * 	 			Bit 0  in MCUCR Register must be Zero
 * 	 		if SensControl == 3
 * 	 			Bit 1 in MCUCR Register must be One    And
 * 	 			Bit 0  in MCUCR Register must be One
 * 	 	2- Enable the SIE For EXTI0
 * 	 		Bit 6 in GICR Register Must be one
 * 	 }
 * 	 */
void mEXTI0_Enable(uint8_t SensControl);

void mEXTI1_Enable(uint8_t SensControl);
/**
 * SensControl:
 * 	1- Falling  = 2
 * 	2- Rising   = 3
 * 	Sudo Code for mEXTI0_Enable (uint8_t SensControl)
 * 	{
 * 		1- Check on SensControl
 * 			if SensControl == 2
 * 				Bit 6 in MCUCSR Register must be 0
 * 			if SensControl == 3
 * 				Bit 6 in MCUCSR Register must be 1
 * 		2- Enable the SIE For EXTI2
 * 			Bit 5 in GICR Resister  must be One
 * 	}
 */
void mEXTI2_Enable(uint8_t SensControl);
//ISR
void __vector_1(void) __attribute__((signal)); // ISR For EXTI0 ;
void __vector_2(void) __attribute__((signal)); // ISR For EXTI1 ;

#endif /* INC_MCAL_EXTI_EXTI_INTERFACE_H_ */
