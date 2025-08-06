/*
 * NTI_Atmega32Reg.h
 *
 *  Created on:
 *      Author: DELL
 */

#ifndef NTI_ATMEGA32REG_H_
#define NTI_ATMEGA32REG_H_
#include <stdint.h>

#define SREG_Reg 					*((volatile uint8_t *)0x5F)
/*EXTI*/
#define MCUCR_Reg 	                *((volatile uint8_t *)0x55)
#define MCUCSR_Reg 	                *((volatile uint8_t *)0x54)
#define GICR_Reg 	                *((volatile uint8_t *)0x5B)
#define GIFR_Reg 	                *((volatile uint8_t *)0x5A)

/*ADC*/
#define ADMUX_Reg 					*((volatile uint8_t  *)0x27)
#define ADCSRA_Reg 					*((volatile uint8_t  *)0x26)
#define ADCData_Reg 				*((volatile uint16_t *)0x24)
#define SFIOR_Reg 					*((volatile uint8_t  *)0x50)


/*Timer0*/
#define TCCR0_Reg                   *((volatile uint8_t  *)0x53)
#define TCNT0_Reg					*((volatile uint8_t  *)0x52)
#define OCR0_Reg                    *((volatile uint8_t  *)0x5C)
#define TIMSK_Reg                   *((volatile uint8_t  *)0x59)
#define TIFR_Reg					*((volatile uint8_t  *)0x58)

/*UART*/
#define  UDR_Reg                         *((volatile uint8_t *)0x2C)
#define  UCSRA_Reg                       *((volatile uint8_t *)0x2B)
#define  UCSRB_Reg                       *((volatile uint8_t *)0x2A)
#define  UCSRC_Reg                       *((volatile uint8_t *)0x40)
#define  UBRRH_Reg                       *((volatile uint8_t *)0x40)
#define  UBRRL_Reg                       *((volatile uint8_t *)0x29)

/* SPI*/
#define SPCR_Reg *((volatile uint8_t *)0x2D)
#define SPSR_Reg *((volatile uint8_t *)0x2E)
#define SPDR_Reg *((volatile uint8_t *)0x2F)


/*Direction DIO*/
#define DDRA_Reg *((volatile uint8_t*)0x3A)
#define DDRB_Reg *((volatile uint8_t*)0x37)
#define DDRC_Reg *((volatile uint8_t*)0x34)
#define DDRD_Reg *((volatile uint8_t*)0x31)

/*Output DIO*/
#define PORTA_Reg *((volatile uint8_t*)0x3B)
#define PORTB_Reg *((volatile uint8_t*)0x38)
#define PORTC_Reg *((volatile uint8_t*)0x35)
#define PORTD_Reg *((volatile uint8_t*)0x32)

/*Input DIO*/
#define PINA_Reg *((volatile uint8_t*)0x39)
#define PINB_Reg *((volatile uint8_t*)0x36)
#define PINC_Reg *((volatile uint8_t*)0x33)
#define PIND_Reg *((volatile uint8_t*)0x30)
#endif  NTI_ATMEGA32REG_H_
