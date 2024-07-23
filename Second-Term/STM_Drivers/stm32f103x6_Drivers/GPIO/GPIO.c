/*
 * GPIO.c
 *
 *  Created on: Aug 31, 2023
 *      Author: ahmed
 */
#include"GPIO.h"


//get position in CRL & CRH to write MODE & CNF
uint8_t GET_POS(uint16_t pin_num)
{
	uint8_t pos;
	if(pin_num < 8)
	{
		pos = 4 * pin_num;
	}
	else
	{
		pos = 4* (pin_num -8 );
	}
	return pos;
}
/**================================================================
 * @Fn			-MCAL_GPIO_INIT
 * @brief	    -initialize GPIOX pin according to pinconfig
 * @param [in]   -GPIOX where x can be (A...G)
  @param [in]   -pinconf determine number and mode of pin
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_INIT(GPIO_TYPEDEF* GPIOX , GPIO_PINCONFIG* pinconf)
{
	uint32_t *confreg = (pinconf->Pin_Number < GPIO_PIN_8)?(&GPIOX->CRL):(&GPIOX->CRH);
	uint8_t pin;

	// clear CNFy[1:0]: & MODEy[1:0]
	(*confreg) &= ~(0x0f<<GET_POS(pinconf->Pin_Number));

	// if mode is output
	if((pinconf->MODE == GPIO_MODE_OUTPUT_PP) ||(pinconf->MODE == GPIO_MODE_OUTPUT_OP) || (pinconf->MODE == GPIO_MODE_OUTPUT_AF_OP) ||(pinconf->MODE == GPIO_MODE_OUTPUT_AF_PP))
	{
		pin = (((pinconf->Speed) | ((pinconf->MODE - 4)<<2 )) & (0x0f));

	}

	// if mode is input but not pull up or pull down
	else if((pinconf->MODE == GPIO_MODE_INPUT_Analog) || (pinconf->MODE == GPIO_MODE_INPUT_AF) || (pinconf->MODE == GPIO_MODE_INPUT_FLO))
	{
		pin = (((pinconf->MODE)<<2) & (0x0f));

	}

	else // if mode is GPIO_MODE_INPUT_PU or GPIO_MODE_INPUT_PD
	{
		pin = (((0b10)<<2) & (0x0f));

		if (pinconf->MODE == GPIO_MODE_INPUT_PU )
		{
			GPIOX->ODR |=(1<<pinconf->Pin_Number);
		}
		else
		{
			GPIOX->ODR &= ~(1<<pinconf->Pin_Number);
		}

	}
	//write on GPIO_CRL or CRH
	(*confreg) |= (pin<<GET_POS(pinconf->Pin_Number));


}
/**================================================================
 * @Fn			-MCAL_GPIO_DEINIT
 * @brief	    -reset GPIOX to the defukt values
 * @param [in]   -GPIOX where x can be (A...G)
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_DEINIT(GPIO_TYPEDEF* GPIOX )
{
	if(GPIOX == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	if(GPIOX == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	if(GPIOX == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	if(GPIOX == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}


}
/**================================================================
 * @Fn			-MCAL_GPIO_Readpin
 * @brief	    -read specific piny from  GPIOX
 * @param [in]   -GPIOX where x can be (A...G)
 * @param [in]   -pinnumber determine number  of pin
 * @retval 		 -pin read
 * Note			-none
 */

uint8_t MCAL_GPIO_Readpin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber)
{
	uint8_t pinread;
	pinread = READ_BIT(GPIOX->IDR,pinnumber);
	return pinread;

}
/**================================================================
 * @Fn			-MCAL_GPIO_Readport
 * @brief	    -read specific port GPIOX
 * @param [in]   -GPIOX where x can be (A...G)
 * @retval 		 -port read
 * Note			-none
 */
uint16_t MCAL_GPIO_Readport(GPIO_TYPEDEF* GPIOX )
{
	uint16_t portread;
	portread = (uint16_t) GPIOX->IDR;
	return portread;
}

/**================================================================
 * @Fn			-MCAL_GPIO_Writepin
 * @brief	    -read specific piny from  GPIOX
 * @param [in]   -GPIOX where x can be (A...G)
 * @param [in]   -pinnumber determine numberof pin
 * @param [in]   -value determine value pin
 * @retval 		 -none
 * Note			-none			-none
 */
void MCAL_GPIO_Writepin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber,uint8_t value)
{
	if(value == 1)
	{
		SET_BIT(GPIOX->ODR,pinnumber);
	}
	else
	{
		RESET_BIT(GPIOX->ODR,pinnumber);
	}

}

/**================================================================
 * @Fn			-MCAL_GPIO_Writeport
 * @brief	    -read specific port GPIOX
 * @param [in]   -GPIOX where x can be (A...G)
 * @param [in]   -value which written on port
 * @retval 		 -none
 * Note			-none
 */
void MCAL_GPIO_Writeport(GPIO_TYPEDEF* GPIOX ,uint16_t value )
{
	GPIOX->ODR = value;

}

/**================================================================
 * @Fn			-MCAL_GPIO_Readpin
 * @brief	    -read specific piny from  GPIOX
 * @param [in]   -GPIOX where x can be (A...G)
 * @param [in]   -pinnumber determine numberof pin
 * @param [in]   -value determine value pin
 * @retval 		 -none
 * Note			-none			-none
 */
void MCAL_GPIO_Togglepin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber)
{
	TOGGLE_BIT(GPIOX->ODR , pinnumber);
}


