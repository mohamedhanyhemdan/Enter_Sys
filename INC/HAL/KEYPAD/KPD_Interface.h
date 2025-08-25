/*
 * KPD_Interface.h
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#ifndef INC_HAL_KPD_KPD_INTERFACE_H_
#define INC_HAL_KPD_KPD_INTERFACE_H_
#include <stdint.h>

/*KPD_Config.h */
#include "../../MCAL/DIO/DIO.h"
#define KPD_Row    3
#define KPD_Coloum 3

#define KPD_R0Group    GroupA
#define KPD_R1Group    GroupA
#define KPD_R2Group    GroupA
#define KPD_R0Pin      Pin0
#define KPD_R1Pin      Pin1
#define KPD_R2Pin      Pin2

#define KPD_C0Group    GroupA
#define KPD_C1Group    GroupA
#define KPD_C2Group    GroupA

#define KPD_C0Pin      Pin3
#define KPD_C1Pin      Pin4
#define KPD_C2Pin      Pin5



#define Pressed      0
#define NotPressed   1

void hKPD_Init();
uint8_t hKPD_GetButton();

#endif /* INC_HAL_KPD_KPD_INTERFACE_H_ */
