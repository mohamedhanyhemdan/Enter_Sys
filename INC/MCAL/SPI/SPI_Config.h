/*
 * SPI_Config.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef _SPI_CONFIG_H
#define _SPI_CONFIG_H




/**
 * @Mode Options
 * SlaveMode,
 * MasterMode
 *
 */
#define SPI_SelectMode      SlaveMode

/**
 * @Data Order
 * SendMSB_First,
 * SendLSB_First,
 * Note: USing this Macro In Master/ Slave Mode
 */
#define SPI_DataOrder     SendLSB_First

/*
    1- IdelLow     // CPOL = 0
    2- IdelHigh    // CPOL = 1
     * Note: USing this Macro In Master/ Slave Mode
*/
#define SPI_ClkPOL        IdelLow
    /* MasterRxFirst,
       MasterTxFirst,
     * Note: USing this Macro In Master/ Slave Mode
    */

#define SPI_ClkPHA        MasterTxFirst
/**
 *SPI_FCPU_4,
 SPI_FCPU_16
 SPI_FCPU_64
 SPI_FCPU_128
 SPI_FCPU_2,
 SPI_FCPU_8,
 SPI_FCPU_32
    Note the Clock Rate Genetrate From Master Only So this Macro Will define
    if Select the SPI Master Mode
 */

#if   SPI_SelectMode==MasterMode
    #define SPI_CLKRate        SPI_FCPU_8
#endif


#endif /* _SPI_CONFIG_H*/
