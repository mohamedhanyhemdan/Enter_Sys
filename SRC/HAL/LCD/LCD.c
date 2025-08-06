/*
 * LCD.c
 *
 *  Created on: ٠١‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */


#include "../../../Inc/MCAL/DIO/DIO.h"
#include "../../../Inc/HAL/LCD/LCD.h"
#include "../../../Inc/Common/Macros.h"
#include <util/delay.h>
void hLCD_Init()
{
	// Set Dirtection
	mDIO_ChangeDirectionForPin(LCD_RSGroup,LCD_RSPin,DIO_Output);
	mDIO_ChangeDirectionForPin(LCD_RWGroup,LCD_RWPin,DIO_Output);
	mDIO_ChangeDirectionForPin(LCD_EGroup,LCD_EPin,DIO_Output);
	//	mDIO_ChangeDirectionforGroup(LCD_DataGroup,DIO_Output); 0000 0001
	mDIO_ChangeDirectionforGroup(LCD_DataGroup,0xFF);

	/*Initaliaztion 8Bit Mode */
	//Delay More Than 30ms
	_delay_ms(35);
	// Function Set
	hLCD_SendCommand(0x38);
	//Delay More than 39us -> 1ms
	_delay_ms(1);
	//Display ON/OFF Control
	hLCD_SendCommand(0x0E);
	//Delay More than 39us -> 1ms
	_delay_ms(1);
	//Display Clear
	hLCD_SendCommand(0x01);
	//Delay More than 1.53ms ->2ms
	_delay_ms(2);
	//	Entry Mode Set
	hLCD_SendCommand(0x06);
	_delay_ms(1);



}
void hLCD_SendCommand(uint8_t Command)
{
	// RS -> 0
	mDIO_WriteValueForPin(LCD_RSGroup,LCD_RSPin,DIO_Low);
	// RW -> 0
	mDIO_WriteValueForPin(LCD_RWGroup,LCD_RWPin,DIO_Low);
	// E  -> 1
	mDIO_WriteValueForPin(LCD_EGroup,LCD_EPin,DIO_High);
	// UpdateCommand
	mDIO_WriteValueForGroup(LCD_DataGroup,Command);
	// E  -> 0
	mDIO_WriteValueForPin(LCD_EGroup,LCD_EPin,DIO_Low);
}

void hLCD_SendChar(uint8_t Character)
{
	//	RS ->1
	mDIO_WriteValueForPin(LCD_RSGroup,LCD_RSPin,DIO_High);
	//RW -> 0
	mDIO_WriteValueForPin(LCD_RWGroup,LCD_RWPin,DIO_Low);
	// E -1
	mDIO_WriteValueForPin(LCD_EGroup,LCD_EPin,DIO_High);
	//Updata data
	mDIO_WriteValueForGroup(LCD_DataGroup,Character);
	//E - 0
	mDIO_WriteValueForPin(LCD_EGroup,LCD_EPin,DIO_Low);

}



void hLCD_SendString(uint8_t Str[])
{
	uint8_t Index = 0 ;
	if(Str!=NULL)
	{
		while(Str[Index]!=NULLChar)
		{
			hLCD_SendChar(Str[Index]);
			Index++;
		}
	}
}

void hLCD_SendNumber(uint32_t Number)
{
    if (Number == 0)
    {
        hLCD_SendChar('0');
        return;
    }

    char buffer[11];
    uint8_t i = 0;


    while (Number > 0)
    {
        buffer[i++] = (Number % 10) + '0';
        Number /= 10;
    }


    while (i > 0)
    {
        hLCD_SendChar(buffer[--i]);
    }
}

void hLCD_StoreSpecialChar(uint8_t *Pattern, uint8_t Location)
{
    if (Location > 7){
    	return;
    }



    hLCD_SendCommand(0x40 + (Location * 8));

    for (uint8_t i = 0; i < 8; i++)
    {
        hLCD_SendChar(Pattern[i]);
    }

    hLCD_SendCommand(0x80);
}


void hLCD_MoveCursor(uint8_t Line ,uint8_t Digit)
{


	uint8_t DDRAM_Address = 0 ;
	switch(Line)
	{
	case 1 :  DDRAM_Address = 0x00 + Digit ;break;
	case 2 :  DDRAM_Address = 0x40 + Digit ;break;
	default:
			break;
	}


	hLCD_SendCommand(128+DDRAM_Address);
	_delay_ms(1);
}
