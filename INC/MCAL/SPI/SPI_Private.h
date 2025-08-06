/*
 * SPI_Private.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H

/* Bit Name*/

typedef enum
{
    /*SPCR*/
    SPR0_Bit,
    SPR1_Bit,
    CPHA_Bit,
    CPOL_Bit,
    MSTR_Bit,
    DORD_Bit,
    SPE_Bit,
    SPIE_Bit,
    /*SPSR*/
    SPI2X_Bit=0,
    WCOL_Bit=6,
    SPIF_Bit,
}SPI_BitName_t;

/*Options*/

typedef enum
{
    SendMSB_First,
    SendLSB_First,
}DataOrderOption_t;

/**
 * 1- SS as Input
 * 2- SS and  Input Value is Low
 * -> MCU as Slave even if MSTR Bit 1
 *
 */
/**
 * To MCU as Master must be Following this Steps :
 * 1- SS as Output
 * 2- MSTR Bit Write Logic One
 */
/**
 * To MCU as Slave must be Following this Steps :
 * 1- SS as Input
 * 2- MSTR Bit Write Logic Zero
 */
#define MasterMode 1
#define SlaveMode  0
/**/
typedef enum
{
    IdelLow, // CPOL = 0
    IdelHigh,// CPOL = 1
}ClkPolarityOption_t;


typedef  enum
{
    MasterRxFirst,
    MasterTxFirst,
}ClkPhaseOption_t;

/**
 * Master Init the Communicate by
 *  is Generate Clock
 *
 */
typedef enum
{
    SPI_FCPU_4,
    SPI_FCPU_16,
    SPI_FCPU_64,
    SPI_FCPU_128,
    SPI_FCPU_2, // 0100
    SPI_FCPU_8,
    SPI_FCPU_32,
}ClockRateOptions;


#endif /* _SPI_INTERFACE_H*/
