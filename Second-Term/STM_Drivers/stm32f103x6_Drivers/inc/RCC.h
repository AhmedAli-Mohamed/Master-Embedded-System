/*
 * RCC.h
 *
 *  Created on: 18 Sep 2023
 *      Author: ahmed
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_
#include"stm32f103x6.h"

/*
* ==============================================================================
*                 CLOCK CONFIGURATION
* ==============================================================================
*/

#define HSI_CLC				8000000UL
#define HSE_CLC				8000000UL // configure HSE CLOCK
#define PLL_CLC				16000000UL



/*
* ==============================================================================
*                           APIs
* ==============================================================================
*/

uint32_t MCAL_RCC_GETSYS_CLCFreq(void);
uint32_t MCAL_RCC_GETHCL_CLCFreq(void);
uint32_t MCAL_RCC_GETPCLK1Freq(void);
uint32_t MCAL_RCC_GETPCLK2Freq(void);

#endif /* INC_RCC_H_ */
