/*
 * GPIO.h
 *
 *  Created on: Aug 31, 2023
 *      Author: Ahmed Ali
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_


//-----------------------------
//Includes

#include"stm32f103x6.h"
//-----------------------------
//-----------------------------
//User type definitions (structures)
typedef struct
{
	uint16_t Pin_Number;//Specifies pin number to be configured
	                    // this parameter can be value of @ref GPIO_PINS _define
	uint8_t MODE; //Specifies Mode to be configured
    			  // this parameter can be value of @ref GPIO_PIN_MODE
	uint8_t Speed; //Specifies Speed to be configured
	               // this parameter can be value of @ref GPIO_PIN_Speed
}GPIO_PINCONFIG;
//-----------------------------
//-----------------------------
//Macros Configuration References
//-----------------------------------------
//@ref GPIO_PINS _define
#define GPIO_PIN_0		0UL
#define GPIO_PIN_1		1UL
#define GPIO_PIN_2		2UL
#define GPIO_PIN_3		3UL
#define GPIO_PIN_4		4UL
#define GPIO_PIN_5		5UL
#define GPIO_PIN_6		6UL
#define GPIO_PIN_7		7UL
#define GPIO_PIN_8		8UL
#define GPIO_PIN_9		9UL
#define GPIO_PIN_10		10UL
#define GPIO_PIN_11		11UL
#define GPIO_PIN_12		12UL
#define GPIO_PIN_13		13UL
#define GPIO_PIN_14		14UL
#define GPIO_PIN_15		15UL

//---------------------------------
//@ref GPIO_PIN_MODE
/*
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with pull-down
In output mode (MODE[1:0] > 00):
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain*/

#define  GPIO_MODE_INPUT_Analog		0UL
#define  GPIO_MODE_INPUT_FLO	    1UL
#define  GPIO_MODE_INPUT_PU			2UL
#define  GPIO_MODE_INPUT_PD			3UL
#define  GPIO_MODE_OUTPUT_PP		4UL
#define  GPIO_MODE_OUTPUT_OP		5UL
#define  GPIO_MODE_OUTPUT_AF_PP		6UL
#define  GPIO_MODE_OUTPUT_AF_OP		7UL
#define  GPIO_MODE_INPUT_AF			1UL

//-----------------------------------------
//@ref GPIO_PIN_Speed
#define GPIO_SPEED_10M		1UL
#define GPIO_SPEED_2M		2UL
#define GPIO_SPEED_50M		3UL
//-----------------------------

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_GPIO_INIT(GPIO_TYPEDEF* GPIOX , GPIO_PINCONFIG* pinconf);
void MCAL_GPIO_DEINIT(GPIO_TYPEDEF* GPIOX );

//Read APIS
uint8_t MCAL_GPIO_Readpin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber);
uint16_t MCAL_GPIO_Readport(GPIO_TYPEDEF* GPIOX );

//write APIS
void MCAL_GPIO_Writepin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber,uint8_t value);
 void MCAL_GPIO_Writeport(GPIO_TYPEDEF* GPIOX ,uint16_t value );

 void MCAL_GPIO_Togglepin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber);

#endif /* INC_GPIO_H_ */
