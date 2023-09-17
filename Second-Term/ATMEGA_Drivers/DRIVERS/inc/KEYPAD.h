/*
 * KEYPAD.h
 *
 * Created: 2023/09/05 23:33:17
 *  Author: ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
//-----------------------------
//Includes
#include "GPIO.h"

/* ===============================================
* KEYPAD CONFIGRATION
===============================================*/
#define KEYPAD_DATAPORT			 GPIOD          //GPIOX , X can be (A....D)



/* ===============================================
* APIs Supported by "HAL KEYPAD DRIVER"
===============================================*/
void KEYPAD_INIT();
uint8_t KEYPAD_READ();




#endif /* KEYPAD_H_ */