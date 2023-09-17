/*
 * GPIO.c
 *
 * Created: 2023/09/02 18:11:59
 *  Author: ahmed
 */ 
#include"Atmega32.h"
#include "GPIO.h"
/**================================================================
 * @Fn			-MCAL_GPIO_INIT
 * @brief	    -initialize GPIOX pin according to pinconfig
 * @param [in]   -GPIOX where x can be (A...D)
  @param [in]   -pinconf determine number and mode of pin
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_INIT(GPIO_TYPEDEF* GPIOX , GPIO_PINCONFIG* pinconf)
{
	//CHECK IF MODE is OUTPUT
	if(pinconf->MODE == GPIO_MODE_OUTPUT)
	{
		SET_BIT(GPIOX->DDR , pinconf ->Pin_Number) ;
	}
	else
	{
		//check if input is floating or pullup
		if(pinconf->MODE == GPIO_MODE_INPUT_PU)
		{
			SET_BIT(GPIOX->PORT , pinconf ->Pin_Number) ;
		}
		RESET_BIT(GPIOX->DDR , pinconf ->Pin_Number) ;
	}
}

/**================================================================
 * @Fn			-MCAL_GPIO_DEINIT
 * @brief	    -reset GPIOX to the defuLt values
 * @param [in]   -GPIOX where x can be (A...D)
 * @retval 		-none
 * Note			-none
 */

void MCAL_GPIO_DEINIT(GPIO_TYPEDEF* GPIOX )
{
	GPIOX->DDR = 0X00;
	GPIOX->PORT = 0X00;
	
}

/**================================================================
 * @Fn			-MCAL_GPIO_Readpin
 * @brief	    -read specific piny from  GPIOX
 * @param [in]   -GPIOX where x can be (A...D)
 * @param [in]   -pinnumber determine number  of pin
 * @retval 		 -pin read
 * Note			-none
 */
uint8_t MCAL_GPIO_Readpin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber)
{
	uint8_t pinread;
	pinread = READ_BIT(GPIOX->PIN , pinnumber);
	return pinread;
}
/**================================================================
 * @Fn			-MCAL_GPIO_Readport
 * @brief	    -read specific port GPIOX
 * @param [in]   -GPIOX where x can be (A...D)
 * @retval 		 -port read
 * Note			-none
 */
uint8_t MCAL_GPIO_Readport(GPIO_TYPEDEF* GPIOX )
{
	uint8_t portread;
	portread = GPIOX->PIN ;
	return portread;
}

/**================================================================
 * @Fn			-MCAL_GPIO_Writepin
 * @brief	    -read specific piny from  GPIOX
 * @param [in]   -GPIOX where x can be (A...D)
 * @param [in]   -pinnumber determine numberof pin
 * @param [in]   -value determine value pin
 * @retval 		 -none
 * Note			-none			-none
 */
void MCAL_GPIO_Writepin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber,uint8_t value)
{
	if(value == 1)
	{
		SET_BIT(GPIOX->PORT , pinnumber);
	}
	else
	{
		RESET_BIT(GPIOX->PORT , pinnumber);
	}
}
/**================================================================
 * @Fn			-MCAL_GPIO_Writeport
 * @brief	    -read specific port GPIOX
 * @param [in]   -GPIOX where x can be (A...D)
 * @param [in]   -value which written on port
 * @retval 		 -none
 * Note			-none
 */
void MCAL_GPIO_Writeport(GPIO_TYPEDEF* GPIOX ,uint8_t value )
{
	GPIOX->PORT = value ;
}

/**================================================================
 * @Fn			-MCAL_GPIO_Readpin
 * @brief	    -read specific piny from  GPIOX
 * @param [in]   -GPIOX where x can be (A...D)
 * @param [in]   -pinnumber determine number of pin
 * @param [in]   -value determine value pin
 * @retval 		 -none
 * Note			-none			-none
 */
void MCAL_GPIO_Togglepin(GPIO_TYPEDEF* GPIOX , uint8_t pinnumber)
{
	TOGGLE_BIT(GPIOX->PORT , pinnumber) ;
}

void MCAL_GPIO_WriteNibble(GPIO_TYPEDEF* GPIOX ,uint8_t value , uint8_t pos)
{
	uint8_t i;
	if(pos == LOW_Nible)
	{
		for(i=0; i<= 3 ; i++)
		{
			MCAL_GPIO_Writepin(GPIOX , i , READ_BIT(value , i));
		} 
	}
	if(pos == HIGH_Nibble)
	{
		for(i=0; i<= 3 ; i++)
		{
	    	MCAL_GPIO_Writepin(GPIOX , i+4 , READ_BIT(value , i));
		}
	}
	
}