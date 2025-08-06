/*
 * SPI_Interface.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H
#include <stdint.h>
#include "../NTI_Atmega32Reg.h"
#include "SPI_Private.h"
#include "SPI_Config.h"



#if   SPI_SelectMode==MasterMode
    void mSPI_MasterInit();
    uint8_t mSPI_MasterTrnsiever(uint8_t Data);

#elif SPI_SelectMode==SlaveMode
    void mSPI_SlaveInit();
    uint8_t mSPI_SlaveTrnsiever(uint8_t Data);
#endif /**/
#endif /* _SPI_INTERFACE_H*/
