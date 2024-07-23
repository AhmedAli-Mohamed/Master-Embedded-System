/*
 * KEYPAD.h
 *
 *  Created on: 17 Sep 2023
 *      Author: ahmed
 */

#ifndef INCLUDES_KEYPAD_H_
#define INCLUDES_KEYPAD_H_
//-----------------------------
//Includes
#include "GPIO.h"

/* ===============================================
* KEYPAD CONFIGRATION
===============================================*/
#define KEYPAD_DATAPORT			 GPIOB          //GPIOX , X can be (A....D)


//--------------------------------------
//KEYPAD ROWS & COL
#define R0      0
#define R1      1
#define R2      3
#define R3      4
#define C0      5
#define C1      6
#define C2      7
#define C3      8




/* ===============================================
* APIs Supported by "HAL KEYPAD DRIVER"
===============================================*/
void KEYPAD_INIT();
uint8_t KEYPAD_READ();



#endif /* INCLUDES_KEYPAD_H_ */
