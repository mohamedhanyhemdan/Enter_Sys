/*
 * main.c
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#include "Project_init.h"

/*  Global Variables  */
volatile uint8_t motionDetected = 1;
char storedPassword[PASSWORD_LENGTH + 1] = "1234";
uint8_t attemptCount = 0;

int main() {
    System_Init();
    char enteredPassword[5];

    while (1) {
        if (motionDetected) {
            motionDetected = 0;

            hLCD_SendCommand(0x01); // Clear LCD
            hLCD_MoveCursor(FirstLine, 1);
            hLCD_SendString("Enter Password:");
            hLCD_MoveCursor(SecondeLine, 1);
            EnterPassword(enteredPassword);

            if (CheckPassword(enteredPassword)) {
                GrantAccess();
                attemptCount = 0;
            }
            else {
                attemptCount++;
                DenyAccess();
                if (attemptCount >= MAX_ATTEMPTS) {
                    LockSystem();
                    WaitForAdmin();
                    attemptCount = 0;
                }
            }
        }
    }

    return 0;
}



