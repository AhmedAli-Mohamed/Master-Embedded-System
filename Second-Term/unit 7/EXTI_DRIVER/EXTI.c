/*
 * GPIO.c
 *
 *  Created on: Aug 31, 2023
 *      Author: ahmed
 */
#include"EXTI.h"




void(*GP_IRQ_CALLBACK[16])(void) ;
/*
 * ===============================================
 *               GENIRIC MACROS
 * ===============================================
 */

#define GPIO_GET(x)			(		(x==GPIOA)?0:\
									(x==GPIOB)?1:\
									(x==GPIOC)?2:\
									(x==GPIOD)?3:0  )



/*
 * ===============================================
 *               GENIRIC FUNCTIONS
 * ===============================================
 */

void UPDATE_EXTI(EXTI_PIN_CONFIG * pinconfig)
{
	//1- set GPIO CONFIG
	GPIO_PINCONFIG pin;
	pin.MODE = GPIO_MODE_INPUT_AF;
	pin.Pin_Number = pinconfig->EXTI_PIN.EXTI_LineNumber;
	MCAL_GPIO_INIT(pinconfig->EXTI_PIN.GPIOX, &pin);
	//======================================================

	//2-set AFIO to select specific port

	uint8_t AFIO_index = (pinconfig->EXTI_PIN.EXTI_LineNumber / 4 ) ;
	uint8_t AFIO_pos = (pinconfig->EXTI_PIN.EXTI_LineNumber % 4 ) * 4 ;

	// clear location

	AFIO->EXTICR[AFIO_index] &= ~(0XF << AFIO_pos);

	//write val
	AFIO->EXTICR[AFIO_index] |= ( GPIO_GET(pinconfig->EXTI_PIN.GPIOX) &0xf << AFIO_pos );

	//======================================================
	//3- select trigger mode
	if(pinconfig->Trigger_MODE == EXTI_TRMODE_RISING)
	{
		EXTI->RTSR |= (1<<pinconfig->EXTI_PIN.EXTI_LineNumber);
	}

	else if (pinconfig->Trigger_MODE == EXTI_TRMODE_FALLING)
	{
		EXTI->FTSR |= (1<<pinconfig->EXTI_PIN.EXTI_LineNumber);

	}

	else if (pinconfig->Trigger_MODE == EXTI_TRMODE_RISING_FALLING)
	{
		EXTI->RTSR |= (1<<pinconfig->EXTI_PIN.EXTI_LineNumber);
		EXTI->FTSR |= (1<<pinconfig->EXTI_PIN.EXTI_LineNumber);
	}

	//=============================================================
	//4-enable corresponding bit in IMR
	if(pinconfig->IR_EN == IR_ENABLE)
	{

		EXTI->IMR |= (1<<pinconfig->EXTI_PIN.EXTI_LineNumber);

		// enable NVIC
		switch(pinconfig->EXTI_PIN.EXTI_LineNumber)
		{
		case 0 :
			NVIC_EXTI0_ENABLE ;
			break;
		case 1 :
			NVIC_EXTI1_ENABLE ;
			break;
		case 2 :
			NVIC_EXTI2_ENABLE ;
			break;
		case 3 :
			NVIC_EXTI3_ENABLE ;
			break;
		case 4 :
			NVIC_EXTI4_ENABLE ;
			break;
		case 5 ... 9  :
		NVIC_EXTI5_EXTI9_ENABLE ;
		break;
		case 10 ... 15  :
		NVIC_EXTI10_EXTI15_ENABLE ;
		break;

		}
	}

	else
	{
		EXTI->IMR &= ~(1<<pinconfig->EXTI_PIN.EXTI_LineNumber);

		switch(pinconfig->EXTI_PIN.EXTI_LineNumber)
				{
				case 0 :
					NVIC_EXTI0_DISABLE ;
					break;
				case 1 :
					NVIC_EXTI1_DISABLE ;
					break;
				case 2 :
					NVIC_EXTI2_DISABLE ;
					break;
				case 3 :
					NVIC_EXTI3_DISABLE ;
					break;
				case 4 :
					NVIC_EXTI4_DISABLE ;
					break;
				case 5 ... 9  :
				NVIC_EXTI5_EXTI9_DISABLE ;
				break;
				case 10 ... 15  :
				NVIC_EXTI10_EXTI15_DISABLE ;
				break;

				}

	}

	//========================================================
	//5-CALLback function Handling
	GP_IRQ_CALLBACK[pinconfig->EXTI_PIN.EXTI_LineNumber] = pinconfig->P_IRQ_CALLBACK;



}




/*
 * ===============================================
 *       APIs Supported by "MCAL EXTI FUNCTION"
 * ===============================================
 *

 * @Fn			-MCAL_EXTI_DEINIT
 * @brief	    -DEINIT all EXTI REGISTERS
 * @param [in]   -pinconfig , which is set according to @ref_EXTI_GPIO_MAPPING , @ref_EXTI_IQ_EN , @ref_EXTI_TRIGGER_MODE
 * @retval 		-none
 * Note			-none
 */
void MCAL_EXTI_DEINIT(EXTI_PIN_CONFIG * pinconfig)
{
	// reset all EXTI registers
	EXTI->EMR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->IMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR = 0xffffffff;

	// disable NVIC IR
	NVIC_EXTI0_DISABLE	;
	NVIC_EXTI1_DISABLE	;
	NVIC_EXTI2_DISABLE	;
	NVIC_EXTI3_DISABLE	;
	NVIC_EXTI4_DISABLE	;
	NVIC_EXTI5_EXTI9_DISABLE	;
	NVIC_EXTI10_EXTI15_DISABLE	 ;

}

/* @Fn			-MCAL_EXTI_INIT
 * @brief	    -DEINIT all EXTI REGISTERS
 * @param [in]   -pinconfig , which is set according to @ref_EXTI_GPIO_MAPPING , @ref_EXTI_IQ_EN , @ref_EXTI_TRIGGER_MODE
 * @retval 		-none
 * Note			-you must set clock and Gpio configuration for specific pin you want to use first
 */
void MCAL_EXTI_INIT(EXTI_PIN_CONFIG * pinconfig)
{
	UPDATE_EXTI(pinconfig);

}

/* @Fn			-MCAL_EXTI_UPDATE
 * @brief	    -DEINIT all EXTI REGISTERS
 * @param [in]   -pinconfig , which is set according to @ref_EXTI_GPIO_MAPPING , @ref_EXTI_IQ_EN , @ref_EXTI_TRIGGER_MODE
 * @retval 		-none
 * Note			-none
 */
void MCAL_EXTI_UPDATE(EXTI_PIN_CONFIG * pinconfig)
{
	UPDATE_EXTI(pinconfig);

}



/*
 * ===============================================
 *                ISR FUNCTIONS
 * ===============================================
 */



void EXTI0_IRQHandler (void)
{
	EXTI->PR |= (1<<0);
	GP_IRQ_CALLBACK[0]();
}
void EXTI1_IRQHandler (void)
{
	EXTI->PR |= (1<<1);
	GP_IRQ_CALLBACK[1]();
}
void EXTI2_IRQHandler (void)
{
	EXTI->PR |= (1<<2);
	GP_IRQ_CALLBACK[2]();
}
void EXTI3_IRQHandler (void)
{
	EXTI->PR |= (1<<3);
	GP_IRQ_CALLBACK[3]();
}
void EXTI4_IRQHandler (void)
{
	EXTI->PR |= (1<<4);
	GP_IRQ_CALLBACK[4]();
}
void EXTI9_5_IRQHandler (void)
{
	if (READ_BIT(EXTI->PR,5)) 		{EXTI->PR |= (1<<5);  GP_IRQ_CALLBACK[5]();}
	if (READ_BIT(EXTI->PR,6)) 		{EXTI->PR |= (1<<6);  GP_IRQ_CALLBACK[6]();}
	if (READ_BIT(EXTI->PR,7)) 		{EXTI->PR |= (1<<7);  GP_IRQ_CALLBACK[7]();}
	if (READ_BIT(EXTI->PR,8)) 		{EXTI->PR |= (1<<8);  GP_IRQ_CALLBACK[8]();}
	if (READ_BIT(EXTI->PR,9)) 		{EXTI->PR |= (1<<9);  GP_IRQ_CALLBACK[9]();}
}
void EXTI15_10_IRQHandler (void)
{
	    if (READ_BIT(EXTI->PR,10)) 		{EXTI->PR |= (1<<10);  GP_IRQ_CALLBACK[10]();}
		if (READ_BIT(EXTI->PR,11)) 		{EXTI->PR |= (1<<11);  GP_IRQ_CALLBACK[11]();}
		if (READ_BIT(EXTI->PR,12)) 		{EXTI->PR |= (1<<12);  GP_IRQ_CALLBACK[12]();}
		if (READ_BIT(EXTI->PR,13)) 		{EXTI->PR |= (1<<13);  GP_IRQ_CALLBACK[13]();}
		if (READ_BIT(EXTI->PR,14)) 		{EXTI->PR |= (1<<14);  GP_IRQ_CALLBACK[14]();}
		if (READ_BIT(EXTI->PR,15)) 		{EXTI->PR |= (1<<15);  GP_IRQ_CALLBACK[15]();}
}

