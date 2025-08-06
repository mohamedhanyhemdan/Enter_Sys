/*
 * SPI_Program.c
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */


#include "../../../Inc/Common/Macros.h"
#include "../../../Inc/MCAL/SPI/SPI_Interface.h"





 #if   SPI_SelectMode==MasterMode
    void mSPI_MasterInit()
    {
        // Disable Interrupt
            ClearBit(SPCR_Reg,SPIE_Bit);
        // Select Master Bit
            SetBit(SPCR_Reg,MSTR_Bit);
        // Select Data Order
            if(SPI_DataOrder==SendMSB_First)
            {
                ClearBit(SPCR_Reg,DORD_Bit);
            }
            else if(SPI_DataOrder==SendLSB_First)
            {
                SetBit(SPCR_Reg,DORD_Bit);
            }
        // Select Clock POL
            if(SPI_ClkPOL==IdelLow)
            {
                ClearBit(SPCR_Reg,CPOL_Bit);
            }
            else if(SPI_ClkPOL==IdelHigh)
            {
                SetBit(SPCR_Reg,CPOL_Bit);
            }
        // Select Clock PHA
            if (SPI_ClkPHA==MasterRxFirst)
            {
                ClearBit(SPCR_Reg,CPHA_Bit);
            }
            else if(SPI_ClkPHA==MasterTxFirst)
            {
                SetBit(SPCR_Reg,CPHA_Bit);
            }
        // Select Clock Rate
            if(SPI_CLKRate<SPI_FCPU_2)
            {
                /*SPI2X_Bit = Must Be Zero */
                ClearBit(SPSR_Reg,SPI2X_Bit);
                // SPR0_Bit  & SPR1_Bit
                /**
                 *       7 6 5 4 3 2 1 0   SPCR->
                 *       1 1 1 0 0 0 1 0
                 *       1 1 1 1 1 1 0 0
                 * |
                 *       0 0 0 0 0 0 0 0    SPI_FCPU_4
                 * -----------------------------------------
                 *       1 1 1 0 0 0 1 0
                 *
                 */
                SPCR_Reg = SPCR_Reg & 0b11111100; // 0xFC
                SPCR_Reg = SPCR_Reg | SPI_CLKRate ;
            }
            else if (SPI_CLKRate>=SPI_FCPU_2)
            {
                /*SPI2X_Bit = Must Be One */
                SetBit(SPSR_Reg,SPI2X_Bit);
                SPCR_Reg = SPCR_Reg & 0b11111100; // 0xFC
                SPCR_Reg = SPCR_Reg | (SPI_CLKRate-4) ;

            }
            DDRB_Reg |= (1 << 4) | (1 << 5) | (1 << 7); // SS, MOSI, SCK as output
            DDRB_Reg &= ~(1 << 6);                         // MISO as input



        // Enable SPI
            SetBit(SPCR_Reg,SPE_Bit);
    }
    uint8_t mSPI_MasterTrnsiever(uint8_t Data)
    	{
    	    // Load data into SPI Data Register
    	    SPDR_Reg = Data;

    	    // Wait until transmission complete (SPIF = 1)
    	    while (GetBit(SPSR_Reg, SPIF_Bit) == 0);

    	    // (Optional) Clear the SPIF flag by writing 1 (only needed if using polling + datasheet recommends)
    	    SetBit(SPSR_Reg, SPIF_Bit);

    	    // Return received data from slave (simultaneous to master sending)
    	    return SPDR_Reg;
    	}



#elif SPI_SelectMode==SlaveMode
void mSPI_SlaveInit()
{
    ClearBit(SPCR_Reg, SPIE_Bit);
    ClearBit(SPCR_Reg, MSTR_Bit);
    //order
    if (SPI_DataOrder == SendMSB_First)
    {
        ClearBit(SPCR_Reg, DORD_Bit);
    }
    else if (SPI_DataOrder == SendLSB_First)
    {
        SetBit(SPCR_Reg, DORD_Bit);
    }
    //cpl
    if (SPI_ClkPOL == IdelLow)
    {
        ClearBit(SPCR_Reg, CPOL_Bit);
    }
    else if (SPI_ClkPOL == IdelHigh)
    {
        SetBit(SPCR_Reg, CPOL_Bit);
    }
    //cpha
    if (SPI_ClkPHA == MasterRxFirst)
    {
        ClearBit(SPCR_Reg, CPHA_Bit);
    }
    else if (SPI_ClkPHA == MasterTxFirst)
    {
        SetBit(SPCR_Reg, CPHA_Bit);
    }
    DDRB_Reg |= (1 << 6);

    SetBit(SPCR_Reg, SPE_Bit);
}


uint8_t mSPI_SlaveTrnsiever(uint8_t Data)
{
	SPDR_Reg = Data;
	while (GetBit(SPSR_Reg, SPIF_Bit) == 0);
	return SPDR_Reg;

}


#endif /**/
