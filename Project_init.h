/*
 * Project_init.h
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef PROJECT_INIT_H_
#define PROJECT_INIT_H_

#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
/* MCAL & HAL Includes */
#include "INC/MCAL/DIO/DIO.h"
#include "INC/MCAL/EXTI/EXTI_Interface.h"
#include "INC/MCAL/UART/Uart_Interface.h"
#include "INC/HAL/LCD/LCD.h"
#include "INC/HAL/KEYPAD/KPD_Interface.h"
#include "INC/HAL/LED/LED.h"

/*  System Config  */
#define MAX_ATTEMPTS     3
#define PASSWORD_LENGTH  4
#define LOCK_TIME_MS     10000

#define GREEN_LED_PORT   GroupD
#define GREEN_LED_PIN    Pin4

#define RED_LED_PORT     GroupD
#define RED_LED_PIN      Pin5

#define ADMIN_BUTTON_PORT GroupD
#define ADMIN_BUTTON_PIN  Pin3

extern volatile uint8_t motionDetected;
extern char storedPassword[PASSWORD_LENGTH + 1];

/*  Function Prototypes  */
void System_Init();
void EnterPassword(char* input);
bool CheckPassword(char* input);
void GrantAccess();
void DenyAccess();
void LockSystem();
void WaitForAdmin();
void mUART_SendString(const char* str);

#endif /* PROJECT_INIT_H_ */
