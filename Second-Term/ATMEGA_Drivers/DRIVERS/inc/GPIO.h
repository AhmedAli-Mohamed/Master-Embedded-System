/*
 * GPIO.h
 *
 * Created: 2023/09/02 18:13:08
 *  Author: ahmed
 */ 


#ifndef GPIO_H_
#define GPIO_H_

//----------------------------- 
//Includes
#include "Atmega32.h"

//===========================================================================
//User type definitions (structures)

typedef struct
{
	uint8_t Pin_Number;//Specifies pin number to be configured
					   // this parameter can be value of @ref GPIO_PINS _define
	uint8_t MODE;//Specifies Mode to be configured
				 // this parameter can be value of @ref GPIO_PIN_MODE
	
	}GPIO_PINCONFIG;
	
//================================================================================

//Macros Configuration References
//--------------------------------------
 //@ref GPIO_PINS _define
 #define GPIO_PIN_0		0UL
 #define GPIO_PIN_1		1UL
 #define GPIO_PIN_2		2UL
 #define GPIO_PIN_3		3UL
 #define GPIO_PIN_4		4UL
 #define GPIO_PIN_5		5UL
 #define GPIO_PIN_6		6UL
 #define GPIO_PIN_7		7UL
 
 
//-----------------------------
//@ref GPIO_PIN_MODE
#define  GPIO_MODE_INPUT_FLO		0UL
#define  GPIO_MODE_OUTPUT		    1UL
#define  GPIO_MODE_INPUT_PU			2UL

//--------------------------------------------
//@refGPIO_NibblePOS
#define LOW_Nible			0
#define HIGH_Nibble         1


/* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
===============================================*/

void MCAL_GPIO_INIT(GPIO_TYPEDEF* GPIOX , GPIO_PINCONFIG* pinconf);
void MCAL_GPIO_DEINIT(GPIO_TYPEDEF* GPIOX );

//Read APIS
uint8_t MCAL_GPIO_Readpin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber);
uint8_t MCAL_GPIO_Readport(GPIO_TYPEDEF* GPIOX );

//write APIS
void MCAL_GPIO_Writepin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber,uint8_t value);
void MCAL_GPIO_Writeport(GPIO_TYPEDEF* GPIOX ,uint8_t value );

void MCAL_GPIO_Togglepin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber);
void MCAL_GPIO_WriteNibble(GPIO_TYPEDEF* GPIOX ,uint8_t value , uint8_t pos); // pos can be @refGPIO_NibblePOS


#endif  GPIO_H_ 