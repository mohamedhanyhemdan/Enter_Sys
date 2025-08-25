/*
 * Uart_Private.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H


/*BitName*/
// UCSRA
#define    MPCM_Bit    0
#define    U2X_Bit     1
#define    PE_Bit      2
#define    DOR_Bit     3
#define    FE_Bit      4
#define    UDRE_Bit    5
#define    TXC_Bit     6
#define    RXC_Bit     7

/*UCSRA*/
#define    TXB8_Bit      0
#define    RXB8_Bit      1
#define    UCSZ2_Bit     2
#define    TXEN_Bit      3
#define    RXEN_Bit      4
#define    UDRIE_Bit     5
#define    TXCIE_Bit     6
#define    RXCIE_Bit     7

/*UCSRC */
#define    USPOL_Bit          0
#define    UCSZ0_Bit          1
#define    UCSZ1_Bit          2
#define    USBS_Bit           3
#define    UPM0_Bit           4
#define    UPM1_Bit           5
#define    UMSEL_Bit          6
#define    URSEL_Bit          7


/**
 * Parity Options
 */

#define Disabled   0
#define EVEN       1

/** StopBit Option:  */
#define Stop1Bit    0
#define Stop2Bit    1


/*Character Size Option*/
#define Size8Bit    0
#define Size9Bit    1



      /*Speed Options*/
#define NormalSpeed  0
#define DoubleSpeed  1

/* Uart Circuits Options */
#define  TxEnable         0
#define  RxEnable         1
#define  TxAndRxEnable   2
#endif /*_UART_PRIVATE_H*/
