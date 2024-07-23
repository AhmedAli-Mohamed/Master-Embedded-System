/*
 * RCC.c
 *
 *  Created on: 18 Sep 2023
 *      Author: ahmed
 */
#include"RCC.h"


/*
* ==============================================================================
*                           APIs
* ==============================================================================
*/
uint32_t MCAL_RCC_GETSYS_CLCFreq(void)
{
	uint32_t return_val;
	switch ((RCC->CFGR >>2) & 0b11 )
	{
	case 0 :
		return_val= HSI_CLC;
		 break;

	case 1 :
		return_val= HSE_CLC	;
		break;

	case 2 :
		return_val= PLL_CLC	;
		break;

	}
	return return_val;
}
uint32_t MCAL_RCC_GETHCL_CLCFreq(void)
{
	uint8_t AHBTable[]={0,0,0,0,1,2,3,4,5,6,7,8,9};
	return   ( MCAL_RCC_GETSYS_CLCFreq() >>  AHBTable[ ((RCC->CFGR >> 4) & 0xf) ] );

}



uint32_t MCAL_RCC_GETPCLK1Freq(void)
{
	uint8_t APB1Table[]={0,0,0,0,1,2,3,4};

	return   ( MCAL_RCC_GETHCL_CLCFreq() >>  APB1Table[ ((RCC->CFGR >> 8) & 0b111) ] );
}
uint32_t MCAL_RCC_GETPCLK2Freq(void)
{
	uint8_t APB2Table[]={0,0,0,0,1,2,3,4};

	return   ( MCAL_RCC_GETHCL_CLCFreq() >>  APB2Table[ ((RCC->CFGR >> 11) & 0b111) ] );
}
