/*
 * EXTI.h
 *
 *  Created on: 11 Sep 2023
 *      Author: ahmed
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

//-----------------------------
//Includes

#include"stm32f103x6.h"
#include"GPIO.h"
//-----------------------------
//-----------------------------
//User type definitions (structures)
typedef struct
{
	uint8_t          EXTI_LineNumber ;
	GPIO_TYPEDEF*    GPIOX           ;
	uint8_t      	 IVT_IRQ_Number  ;

}EXTI_GPIO_MAPPING_t;

typedef struct
{
	EXTI_GPIO_MAPPING_t   EXTI_PIN       ; // Specifies EXTI GPIO Mapping
										   // this parameter must be set from @ref_EXTI_GPIO_MAPPING

	uint8_t 			 Trigger_MODE	 ;// Specifies EXTI trigger mode
										  // this parameter must be set from @ref_EXTI_TRIGGER_MODE

	uint8_t   			 IR_EN			; // Specifies enabling of EXTI by interfacing with maskbit and enable bit in NVIC
										  //this parameter must be set from @ref_EXTI_IQ_EN

	void(*P_IRQ_CALLBACK)(void) ;

}EXTI_PIN_CONFIG;

#endif /* INC_EXTI_H_ */



//-----------------------------
//-----------------------------
//Macros Configuration References
//-----------------------------------------

//@ref_EXTI_Line_number
#define EXTI0     0
#define EXTI1     1
#define EXTI2     2
#define EXTI3     3
#define EXTI4     4
#define EXTI5     5
#define EXTI6     6
#define EXTI7     7
#define EXTI8     8
#define EXTI9     9
#define EXTI10    10
#define EXTI11    11
#define EXTI12    12
#define EXTI13    13
#define EXTI14    14
#define EXTI15    15
//--------------------------------------

//@ref_EXTI_TRIGGER_MODE
#define EXTI_TRMODE_RISING				0
#define EXTI_TRMODE_FALLING				1
#define EXTI_TRMODE_RISING_FALLING		2

//--------------------------------------------
//@ref_EXTI_IQ_EN
#define IR_DISABLE			0
#define IR_ENABLE			1

//------------------------------------------------


//@ref_EXTI_GPIO_MAPPING
//EXTI0
#define EXTI0PA0       (EXTI_GPIO_MAPPING_t){EXTI0,GPIOA,EXTI0_IRQ}
#define EXTI0PB0       (EXTI_GPIO_MAPPING_t){EXTI0,GPIOB,EXTI0_IRQ}
#define EXTI0PC0       (EXTI_GPIO_MAPPING_t){EXTI0,GPIOC,EXTI0_IRQ}
#define EXTI0PD0       (EXTI_GPIO_MAPPING_t){EXTI0,GPIOD,EXTI0_IRQ}
//EXTI1
#define EXTI1PA1       (EXTI_GPIO_MAPPING_t){EXTI1,GPIOA,EXTI1_IRQ}
#define EXTI1PB1       (EXTI_GPIO_MAPPING_t){EXTI1,GPIOB,EXTI1_IRQ}
#define EXTI1PC1       (EXTI_GPIO_MAPPING_t){EXTI1,GPIOC,EXTI1_IRQ}
#define EXTI1PD1       (EXTI_GPIO_MAPPING_t){EXTI1,GPIOD,EXTI1_IRQ}
//EXTI2
#define EXTI2PA2       (EXTI_GPIO_MAPPING_t){EXTI2,GPIOA,EXTI2_IRQ}
#define EXTI2PB2       (EXTI_GPIO_MAPPING_t){EXTI2,GPIOB,EXTI2_IRQ}
#define EXTI2PC2       (EXTI_GPIO_MAPPING_t){EXTI2,GPIOC,EXTI2_IRQ}
#define EXTI2PD2       (EXTI_GPIO_MAPPING_t){EXTI2,GPIOD,EXTI2_IRQ}
//EXTI3
#define EXTI3PA3       (EXTI_GPIO_MAPPING_t){EXTI3,GPIOA,EXTI3_IRQ}
#define EXTI3PB3       (EXTI_GPIO_MAPPING_t){EXTI3,GPIOB,EXTI3_IRQ}
#define EXTI3PC3       (EXTI_GPIO_MAPPING_t){EXTI3,GPIOC,EXTI3_IRQ}
#define EXTI3PD3       (EXTI_GPIO_MAPPING_t){EXTI3,GPIOD,EXTI3_IRQ}
//EXTI4
#define EXTI4PA4       (EXTI_GPIO_MAPPING_t){EXTI4,GPIOA,EXTI4_IRQ}
#define EXTI4PB4       (EXTI_GPIO_MAPPING_t){EXTI4,GPIOB,EXTI4_IRQ}
#define EXTI4PC4       (EXTI_GPIO_MAPPING_t){EXTI4,GPIOC,EXTI4_IRQ}
#define EXTI4PD4       (EXTI_GPIO_MAPPING_t){EXTI4,GPIOD,EXTI4_IRQ}
//EXTI5
#define EXTI5PA5       (EXTI_GPIO_MAPPING_t){EXTI5,GPIOA,EXTI5_IRQ}
#define EXTI5PB5       (EXTI_GPIO_MAPPING_t){EXTI5,GPIOB,EXTI5_IRQ}
#define EXTI5PC5       (EXTI_GPIO_MAPPING_t){EXTI5,GPIOC,EXTI5_IRQ}
#define EXTI5PD5       (EXTI_GPIO_MAPPING_t){EXTI5,GPIOD,EXTI5_IRQ}
//EXTI6
#define EXTI6PA6       (EXTI_GPIO_MAPPING_t){EXTI6,GPIOA,EXTI6_IRQ}
#define EXTI6PB6       (EXTI_GPIO_MAPPING_t){EXTI6,GPIOB,EXTI6_IRQ}
#define EXTI6PC6       (EXTI_GPIO_MAPPING_t){EXTI6,GPIOC,EXTI6_IRQ}
#define EXTI6PD6       (EXTI_GPIO_MAPPING_t){EXTI6,GPIOD,EXTI6_IRQ}
//EXTI7
#define EXTI7PA7       (EXTI_GPIO_MAPPING_t){EXTI7,GPIOA,EXTI7_IRQ}
#define EXTI7PB7       (EXTI_GPIO_MAPPING_t){EXTI7,GPIOB,EXTI7_IRQ}
#define EXTI7PC7       (EXTI_GPIO_MAPPING_t){EXTI7,GPIOC,EXTI7_IRQ}
#define EXTI7PD7       (EXTI_GPIO_MAPPING_t){EXTI7,GPIOD,EXTI7_IRQ}
//EXTI8
#define EXTI8PA8       (EXTI_GPIO_MAPPING_t){EXTI8,GPIOA,EXTI8_IRQ}
#define EXTI8PB8       (EXTI_GPIO_MAPPING_t){EXTI8,GPIOB,EXTI8_IRQ}
#define EXTI8PC8       (EXTI_GPIO_MAPPING_t){EXTI8,GPIOC,EXTI8_IRQ}
#define EXTI8PD8       (EXTI_GPIO_MAPPING_t){EXTI8,GPIOD,EXTI8_IRQ}
//EXTI9
#define EXTI9PA9       (EXTI_GPIO_MAPPING_t){EXTI9,GPIOA,EXTI9_IRQ}
#define EXTI9PB9       (EXTI_GPIO_MAPPING_t){EXTI9,GPIOB,EXTI9_IRQ}
#define EXTI9PC9       (EXTI_GPIO_MAPPING_t){EXTI9,GPIOC,EXTI9_IRQ}
#define EXTI9PD9       (EXTI_GPIO_MAPPING_t){EXTI9,GPIOD,EXTI9_IRQ}
//EXTI10
#define EXTI10PA10       (EXTI_GPIO_MAPPING_t){EXTI10,GPIOA,EXTI10_IRQ}
#define EXTI10PB10       (EXTI_GPIO_MAPPING_t){EXTI10,GPIOB,EXTI10_IRQ}
#define EXTI10PC10       (EXTI_GPIO_MAPPING_t){EXTI10,GPIOC,EXTI10_IRQ}
#define EXTI10PD10       (EXTI_GPIO_MAPPING_t){EXTI10,GPIOD,EXTI10_IRQ}
//EXTI11
#define EXTI11PA11       (EXTI_GPIO_MAPPING_t){EXTI11,GPIOA,EXTI11_IRQ}
#define EXTI11PB11       (EXTI_GPIO_MAPPING_t){EXTI11,GPIOB,EXTI11_IRQ}
#define EXTI11PC11       (EXTI_GPIO_MAPPING_t){EXTI11,GPIOC,EXTI11_IRQ}
#define EXTI11PD11       (EXTI_GPIO_MAPPING_t){EXTI11,GPIOD,EXTI11_IRQ}
//EXTI12
#define EXTI12PA12       (EXTI_GPIO_MAPPING_t){EXTI12,GPIOA,EXTI12_IRQ}
#define EXTI12PB12       (EXTI_GPIO_MAPPING_t){EXTI12,GPIOB,EXTI12_IRQ}
#define EXTI12PC12       (EXTI_GPIO_MAPPING_t){EXTI12,GPIOC,EXTI12_IRQ}
#define EXTI12PD12       (EXTI_GPIO_MAPPING_t){EXTI12,GPIOD,EXTI12_IRQ}
//EXTI13
#define EXTI13PA13       (EXTI_GPIO_MAPPING_t){EXTI13,GPIOA,EXTI13_IRQ}
#define EXTI13PB13       (EXTI_GPIO_MAPPING_t){EXTI13,GPIOB,EXTI13_IRQ}
#define EXTI13PC13       (EXTI_GPIO_MAPPING_t){EXTI13,GPIOC,EXTI13_IRQ}
#define EXTI13PD13       (EXTI_GPIO_MAPPING_t){EXTI13,GPIOD,EXTI13_IRQ}
//EXTI14
#define EXTI14PA14       (EXTI_GPIO_MAPPING_t){EXTI14,GPIOA,EXTI14_IRQ}
#define EXTI14PB14       (EXTI_GPIO_MAPPING_t){EXTI14,GPIOB,EXTI14_IRQ}
#define EXTI14PC14       (EXTI_GPIO_MAPPING_t){EXTI14,GPIOC,EXTI14_IRQ}
#define EXTI14PD14       (EXTI_GPIO_MAPPING_t){EXTI14,GPIOD,EXTI14_IRQ}
//EXTI15
#define EXTI15PA15       (EXTI_GPIO_MAPPING_t){EXTI15,GPIOA,EXTI15_IRQ}
#define EXTI15PB15       (EXTI_GPIO_MAPPING_t){EXTI15,GPIOB,EXTI15_IRQ}
#define EXTI15PC15       (EXTI_GPIO_MAPPING_t){EXTI15,GPIOC,EXTI15_IRQ}
#define EXTI15PD15       (EXTI_GPIO_MAPPING_t){EXTI15,GPIOD,EXTI15_IRQ}


/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_EXTI_INIT(EXTI_PIN_CONFIG * pinconfig);
void MCAL_EXTI_UPDATE(EXTI_PIN_CONFIG * pinconfig);
void MCAL_EXTI_DEINIT(EXTI_PIN_CONFIG * pinconfig);
