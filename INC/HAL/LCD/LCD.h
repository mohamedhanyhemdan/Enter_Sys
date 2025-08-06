/*
 * LCD.h
 *
 *  Created on: ٠١‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef INC_HAL_LCD_H_
#define INC_HAL_LCD_H_

#define LCD_RSGroup    GroupA
#define LCD_RWGroup    GroupA
#define LCD_EGroup     GroupA
#define LCD_DataGroup  GroupC

#define LCD_RSPin      Pin0
#define LCD_RWPin      Pin1
#define LCD_EPin       Pin2

#define FirstLine 1
#define SecondeLine 2
#define FirstLineAddress  0x00
#define SecondeLineAddress  0x40
#define SetDDRAMCommand     0x80


void hLCD_SendCommand(uint8_t Command); //
void hLCD_SendChar(uint8_t Character);
void hLCD_Init();
void hLCD_SendString(uint8_t Str[]);
void hLCD_SendNumber(uint32_t Number);
void hLCD_StoreSpecialChar(uint8_t *Pattern , uint8_t Location);
void hLCD_MoveCursor(uint8_t Line ,uint8_t Digit);

#endif /* INC_HAL_LCD_H_ */
