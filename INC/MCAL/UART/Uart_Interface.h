/*
 * Uart_Interface.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H
#include <stdint.h>
#include "Uart_Private.h"
#include "Uart_Config.h"

/* Polling Type */
void mUART_Init();
void mUART_Send(uint16_t Data);
uint16_t mUART_Recivie();

#endif /*_UART_INTERFACE_H*/
