/*
 * Uart_Program.c
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */


#include "../../../Inc/MCAL/NTI_Atmega32Reg.h"
#include "../../../Inc/Common/Macros.h"
#include "../../../Inc/MCAL/Uart/Uart_Interface.h"
void mUART_Init()
{
    uint8_t UCSRC_Temp = 0 ;
    // Mode (Synch Or Asynch)
        // this Driver Support Asynch Only
        // UMSEL_Bit in  UCSRC must be zero
        ClearBit(UCSRC_Temp,UMSEL_Bit);
    // Parity Mode
        // This Driver Support Disable / Enable Even Only
        //Disable ->  UPM1_Bit & UPM0_Bit in  UCSRC Must be 0 0
        //Even    ->   UPM1_Bit in UCSRC must be   1
        //             UPM1_Bit in UCSRC must be   0
        if(ParityMode==Disabled)
        {
            ClearBit(UCSRC_Temp,UPM0_Bit);
            ClearBit(UCSRC_Temp,UPM1_Bit);
        }
        else if (ParityMode==EVEN)
        {
            ClearBit(UCSRC_Temp,UPM0_Bit);
            SetBit(UCSRC_Temp,UPM1_Bit);
        }
    // Stop Bit
        //1 Stop USBS_Bit in UCSRC -> 0
        //2 Stop USBS_Bit in UCSRC -> 1
        if(StopBitSize==Stop1Bit)
        {
            ClearBit(UCSRC_Temp,USBS_Bit);
        }
        else if (StopBitSize==Stop2Bit)
        {
            SetBit(UCSRC_Temp,USBS_Bit);
        }
    // Size Character
        // Support  8bit or 9 bit only
        // 8bit size ->
            // UCSZ0_Bit   in   UCSRC = 1
            // UCSZ1_Bit   in   UCSRC = 1
            // UCSZ2_Bit   in   UCSRB = 0
        // 9bit size ->
            // UCSZ0_Bit   in   UCSRC = 1
            // UCSZ1_Bit   in   UCSRC = 1
            // UCSZ2_Bit   in   UCSRB = 1
        if(CharacterSize==Size8Bit)
        {
            SetBit(UCSRC_Temp,UCSZ0_Bit);
            SetBit(UCSRC_Temp,UCSZ1_Bit);
            ClearBit(UCSRB_Reg,UCSZ2_Bit);
        }
        else if (CharacterSize==Size9Bit)
        {
            SetBit(UCSRC_Temp,UCSZ0_Bit);
            SetBit(UCSRC_Temp,UCSZ1_Bit);
            SetBit(UCSRB_Reg,UCSZ2_Bit);
        }
    // Disable Interrupt
        // 1- Disable For RXCIE - > 0 in UCSRB
            ClearBit(UCSRB_Reg,RXCIE_Bit);
        // 2- Disable For TXCIE - > 0
            ClearBit(UCSRB_Reg,TXCIE_Bit);
        // 3- Disable For UDRIE - > 0
            ClearBit(UCSRB_Reg,UDRIE_Bit);

    // Speed
        // 1- NormalSpeed -> U2X_Bit in UCSRA = 0
        // 2- DoubleSpeed -> U2X_Bit  in UCSRA = 1
        if(UARTSpeed==NormalSpeed)
        {
            ClearBit(UCSRA_Reg,U2X_Bit);
        }
        else if(UARTSpeed==DoubleSpeed)
        {
            SetBit(UCSRA_Reg,U2X_Bit);
        }
    // Baud Rate
        // UBRRL & UBRRH
        if(UBRR_Value<=255)
        {
            UBRRL_Reg=UBRR_Value;
        }
        else if (UBRR_Value>255)
        {
            /*
                UBRR_Value

                0000 0011
                1111 1101
                (UBRR_Value>>8)
                0000 0000
                0000 0011
            */
            UBRRL_Reg = UBRR_Value; // 1111 1101
            UBRRH_Reg = (UBRR_Value>>8); // 0000 0011
        }
    // Tx & Rx Enable
        //1- Tx Enable Only
        //2- RX Enable Only
        //Both Enable
        if(UartCircuitEnabled==TxEnable)
        {
            SetBit(UCSRB_Reg,TXEN_Bit);
            ClearBit(UCSRB_Reg,RXEN_Bit);
        }
        else if(UartCircuitEnabled==RxEnable)
        {
            SetBit(UCSRB_Reg,RXEN_Bit);
            ClearBit(UCSRB_Reg,TXEN_Bit);
        }
        else if(UartCircuitEnabled==TxAndRxEnable)
        {
            SetBit(UCSRB_Reg,TXEN_Bit);
            SetBit(UCSRB_Reg,RXEN_Bit);
        }

        UCSRC_Reg=UCSRC_Temp;
}

void mUART_Send(uint16_t Data)
{
    //check DataSize   // Update txBuffer
    if(CharacterSize==Size8Bit)
    {
        UDR_Reg=(uint8_t)Data; // tx Buffer
    }
    else if(CharacterSize==Size9Bit)
    {
        UDR_Reg=(uint8_t)Data;
        uint8_t NineBit = GetBit(Data,8);
        // TXB8_Bit in UCSRB
        if(NineBit==1)
        {
            SetBit(UCSRB_Reg,TXB8_Bit);
        }
        else if (NineBit==0)
        {
            ClearBit(UCSRB_Reg,TXB8_Bit);
        }
    }
    // wait until Flag set
    while(GetBit(UCSRA_Reg,UDRE_Bit)==0);
    // Clear flag
    SetBit(UCSRA_Reg,UDRE_Bit);
}


uint16_t mUART_Recivie()
{
    uint16_t RxData = 0 ;
    while(GetBit(UCSRA_Reg,RXC_Bit)==0);
    SetBit(UCSRA_Reg,RXC_Bit);
    if(CharacterSize==Size8Bit)
    {
        RxData=UDR_Reg;
    }
    else if (CharacterSize==Size9Bit)
    {
        RxData =UDR_Reg;
        uint8_t NineBit=GetBit(UCSRB_Reg,RXB8_Bit);
        if(NineBit==1)
        {
            SetBit(RxData,8);
        }
        else if (NineBit==0)
        {
            ClearBit(RxData,8);
        }
    }


    return RxData;
}
