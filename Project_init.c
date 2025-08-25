/*
 * Project_init.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */
#include "Project_init.h"

/*  System Initialization  */
void System_Init() {
    hLCD_Init();
    hKPD_Init();
    mUART_Init();
    hLed_Init(GREEN_LED_PORT, GREEN_LED_PIN);
    hLed_Init(RED_LED_PORT, RED_LED_PIN);
    mDIO_ChangeDirectionForPin(ADMIN_BUTTON_PORT, ADMIN_BUTTON_PIN, DIO_Input);

    mEXTI0_Enable(EXTI_Falling);
    mGIE_Enable();

    hLCD_SendString("System Ready");
    _delay_ms(1000);
}

/*  Get Password from Keypad  */
void EnterPassword(char* input) {
    uint8_t i = 0;
    while (i < PASSWORD_LENGTH) {
        uint8_t key = hKPD_GetButton();
        if (key != 0xFF) {
            input[i] = key;
            hLCD_SendChar('*');
            i++;
            _delay_ms(200);
        }
    }
    input[i] = '\0';
}

/*  Compare Input with Stored Password  */
bool CheckPassword(char* input) {
    return strcmp(input, storedPassword) == 0;
}

/*  Access Granted  */
void GrantAccess() {
    hLCD_SendCommand(0x01);
    hLCD_MoveCursor(FirstLine, 1);
    hLCD_SendString("Access Succesfully");
    hLed_On(GREEN_LED_PORT, GREEN_LED_PIN);
    mUART_SendString("Access Succesfully");
    _delay_ms(5000);
    hLed_Off(GREEN_LED_PORT, GREEN_LED_PIN);
}

/*  Access Denied  */
void DenyAccess() {
    hLCD_SendCommand(0x01);
    hLCD_MoveCursor(FirstLine, 1);
    hLCD_SendString("Access Denied");
    hLed_On(RED_LED_PORT, RED_LED_PIN);
    mUART_SendString("Access Denied");
    _delay_ms(2000);
    hLed_Off(RED_LED_PORT, RED_LED_PIN);
}

/*  Lock the System  */
void LockSystem() {
    hLCD_SendCommand(0x01);
    hLCD_MoveCursor(FirstLine, 1);
    hLCD_SendString("System Locked");
    mUART_SendString("System Locked");
    hLed_On(RED_LED_PORT, RED_LED_PIN);
    _delay_ms(LOCK_TIME_MS);
    hLed_Off(RED_LED_PORT, RED_LED_PIN);
}

/*  Wait for Admin Button to Reset  */
void WaitForAdmin() {
    hLCD_SendCommand(0x01);
    hLCD_MoveCursor(FirstLine, 1);
    hLCD_SendString("Wait Admin Btn");
    while (mDIO_ReadValueFromPin(ADMIN_BUTTON_PORT, ADMIN_BUTTON_PIN) == DIO_Low);
    hLCD_SendCommand(0x01);
    hLCD_MoveCursor(FirstLine, 1);
    hLCD_SendString("System Reset");
    _delay_ms(2000);
    hLCD_SendCommand(0x01);
    hLCD_MoveCursor(FirstLine, 1);
    hLCD_SendString("System Ready");
}

/*  ISR for Motion Detection (EXTI0)  */
void __vector_1(void) {
    motionDetected = 1;
}

/*  UART Send String (Helper)  */
void mUART_SendString(const char* str) {
    while (*str) {
        mUART_Send(*str++);
    }
}
