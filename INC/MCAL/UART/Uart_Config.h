/*
 * Uart_Config.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef _UART_CONFIG_H_
#define _UART_CONFIG_H_


/*Configuration*/
/**
 * Parity Option :
 * 1- Disabled
 * 2- EVEN
 *
 */
#define ParityMode    Disabled

/**
 * StopBit Option:
 *  1- Stop1Bit
 *  2- Stop2Bit
 *
 */
#define StopBitSize   Stop1Bit


/**
 *  Character Size Option:
 *  1- Size8Bit
 *  2- Size9Bit
 *
 */
#define CharacterSize    Size8Bit

/**
 * Speed Options
 * 1-NormalSpeed
 * 2-DoubleSpeed
 *
 */
#define UARTSpeed NormalSpeed


/**
 * Baud Rate Value :
 *
 * Normal Speed :
 *  UBRR = ((F_CPU)/16*BaudRate)-1
 * Double Speed :
 *  UBRR = ((F_CPU)/8*BaudRate)-1
 *
 */

#define UBRR_Value     100


/* Uart Circuits Options
    1-TxEnable
    2-RxEnable
    3-TxAndRxEnable
*/

#define  UartCircuitEnabled TxEnable









#endif /**/
