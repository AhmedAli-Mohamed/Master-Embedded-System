/*
 * USART.c
 *
 *  Created on: 18 Sep 2023
 *      Author: ahmed
 */
#include"USART.h"
#include"GPIO.h"
#include"RCC.h"
/* ==============================================================================
 *                            GENARIC Variables
 * ==============================================================================
 */


USART_PINCONFIG * GP_pinconfig;
void (*GP_IRQ_CALLBACK[3])(void);


/* ==============================================================================
 *                            GENARIC Functions
 * ==============================================================================
 */
#define USARTDIV(_PCLC_,_BAUD_)             	 	(uint32_t)(_PCLC_ / (16 * _BAUD_))
#define USARTDIV_MUL100(_PCLC_,_BAUD_)				(uint32_t)((_PCLC_ * 25) / (4 * _BAUD_))
#define USARTMANTISSA_MUL100(_PCLC_,_BAUD_)			(uint32_t)(USARTDIV(_PCLC_,_BAUD_) * 100)
#define USARTFRAC(_PCLC_,_BAUD_)					(uint32_t)( (USARTDIV_MUL100(_PCLC_,_BAUD_) - USARTMANTISSA_MUL100(_PCLC_,_BAUD_)) *16 / 100 )
#define USARTBRR(_PCLC_,_BAUD_)						(uint32_t) ( ((USARTDIV(_PCLC_,_BAUD_)) << 4 ) | (USARTFRAC(_PCLC_,_BAUD_) & 0xf) )

/* ==============================================================================
 *                            APIs
 * ==============================================================================
 */

/* @Fn			-MCAL_USART_DEINIT
 * @brief	    -DEINIT all USART REGISTERS
 * @param [in]   -USARTX ,which x could be (1,2,3)
 * @retval 		-none
 * Note			-none
 */
void MCAL_USART_DEINIT(USART_TYPEDEF* USARTX )
{
	if (USARTX == USART1)
	{
		RCC->APB2RSTR |= (1<<14);
		NVIC_USART1_DISABLE;
	}

	else if(USARTX == USART2)
	{
		RCC->APB1RSTR |= (1<<17);
		NVIC_USART2_DISABLE;
	}

	else if(USARTX == USART3)
	{
		RCC->APB1RSTR |= (1<<18);
		NVIC_USART3_DISABLE;
	}
}
//-----------------------------------------------------
/* @Fn			-MCAL_USART_INIT
 * @brief	    -INIT all USART REGISTERS
 * @param [in]   -USARTX ,which x could be (1,2,3)
 * @param [in]   -pin_conf
 * @retval 		-none
 * Note			-none
 */
void MCAL_USART_INIT(USART_TYPEDEF* USARTX , USART_PINCONFIG* pin_conf)
{
	GP_pinconfig = pin_conf;
	uint32_t Pclc,BRR;

	if(USARTX==USART1)
	{
		CLOCK_ENABLE_USART1;
	}
	else if(USARTX==USART2)
	{
		CLOCK_ENABLE_USART2;
	}
	else if (USARTX==USART3)
	{
		CLOCK_ENABLE_USART3;
	}


	//0-enable USART
	USARTX->CR1 |= (1<<13);
	//1-initialize mode
	USARTX->CR1 |= pin_conf->mode;

	//2-initialize stop bit
	USARTX->CR2 |= pin_conf->stop_bit;

	//3-initialize parity
	USARTX->CR1 |=pin_conf->parity;

	//4-initialize pay load length
	USARTX->CR1 |=pin_conf->payload_length;

	//5-initialize flow control
	USARTX->CR3 |=pin_conf->FW_control;

	//6-initialize interrupt
	if(pin_conf->IRQ_ENABLE != USART_IRQ_NONE)
	{
		USARTX->CR1 |=pin_conf->IRQ_ENABLE;

		if(USARTX == USART1)
		{
			NVIC_USART1_ENABLE;
			GP_IRQ_CALLBACK[0] = pin_conf->P_IRQ_CALLBACK ;
		}

		else if (USARTX == USART2)
		{
			NVIC_USART2_ENABLE;
			GP_IRQ_CALLBACK[1] = pin_conf->P_IRQ_CALLBACK ;
		}

		else if (USARTX == USART3)
		{
			NVIC_USART3_ENABLE;
			GP_IRQ_CALLBACK[2] = pin_conf->P_IRQ_CALLBACK ;
		}
	}

	//7-initialize BAUD RATE
	if(USARTX == USART1)
	{
		Pclc = MCAL_RCC_GETPCLK2Freq();

	}
	else
	{
		Pclc = MCAL_RCC_GETPCLK1Freq();
	}
	BRR = USARTBRR(Pclc,pin_conf->Baud_Rate);
	USARTX->BRR = BRR;



}
//--------------------------------------------------------
/* @Fn			-MCAL_USART_GPIO_SET_PINS
 * @brief	    -initialize send and receive and clock pins of specific USART
 * @param [in]   -USARTX ,which x could be (1,2,3)
 * @retval 		-none
 * Note			-none
 */
void MCAL_USART_GPIO_SET_PINS(USART_TYPEDEF* USARTX )
{
	//USARTx_RX				Full duplex					Input floating / Input pull-up
	// USARTx_CK			Synchronous mode			Alternate function push-pull
	//USARTx_TX				 Full duplex 				Alternate function push-pull
	// USARTx_RTS 			Hardware flow control 		Alternate function push-pull
	//USARTx_CTS 			Hardware flow control 		Input floating/ Input pull-up

	GPIO_PINCONFIG pinconfig;

	if (USARTX == USART1)
	{


		//PA.9(TX)
		pinconfig.Pin_Number = GPIO_PIN_9;
		pinconfig.MODE = GPIO_MODE_OUTPUT_AF_PP;
		pinconfig.Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(GPIOA,& pinconfig);

		//PA.10(RX)
		pinconfig.Pin_Number = GPIO_PIN_10;
		pinconfig.MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOA,& pinconfig);

		if( (GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE) || (GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE_RTSE))
		{
			//PA.11(CTS)
			pinconfig.Pin_Number = GPIO_PIN_11;
			pinconfig.MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOA,& pinconfig);
		}


		if( (GP_pinconfig->FW_control == USART_FW_CONTROL_RTSE) || (GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE_RTSE))
		{
			//PA.12(RTS)
			pinconfig.Pin_Number = GPIO_PIN_12;
			pinconfig.MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.Speed = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA,& pinconfig);
		}



	}

	else if (USARTX == USART2)
	{

		//PA.2(TX)
		pinconfig.Pin_Number = GPIO_PIN_2;
		pinconfig.MODE = GPIO_MODE_OUTPUT_AF_PP;
		pinconfig.Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(GPIOA,& pinconfig);

		//PA.3(RX)
		pinconfig.Pin_Number = GPIO_PIN_3;
		pinconfig.MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOA,& pinconfig);


		if ( GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE || GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE_RTSE )
		{
			//PA.0(CTS)
			pinconfig.Pin_Number = GPIO_PIN_0;
			pinconfig.MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOA,& pinconfig);
		}

		if( ( GP_pinconfig->FW_control == USART_FW_CONTROL_RTSE) || ( GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE_RTSE))
		{
			//PA.1(RTS)
			pinconfig.Pin_Number = GPIO_PIN_1;
			pinconfig.MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.Speed = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOA,& pinconfig);
		}



	}
	else if (USARTX == USART3)
	{

		//PB.10(TX)
		pinconfig.Pin_Number = GPIO_PIN_10;
		pinconfig.MODE = GPIO_MODE_OUTPUT_AF_PP;
		pinconfig.Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(GPIOB,& pinconfig);

		//PB.11(RX)
		pinconfig.Pin_Number = GPIO_PIN_11;
		pinconfig.MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOB,& pinconfig);

		//PB.12(CLC)
		pinconfig.Pin_Number = GPIO_PIN_12;
		pinconfig.MODE = GPIO_MODE_OUTPUT_AF_PP;
		pinconfig.Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(GPIOB,& pinconfig);
		if( (GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE) || (GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE_RTSE))
		{
			//PB.13(CTS)
			pinconfig.Pin_Number = GPIO_PIN_13;
			pinconfig.MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOB,& pinconfig);
		}

		if( (GP_pinconfig->FW_control == USART_FW_CONTROL_RTSE) || (GP_pinconfig->FW_control == USART_FW_CONTROL_CTSE_RTSE))
		{
			//PB.14(RTS)
			pinconfig.Pin_Number = GPIO_PIN_14;
			pinconfig.MODE = GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.Speed = GPIO_SPEED_10M;
			MCAL_GPIO_INIT(GPIOB,& pinconfig);
		}




	}


}

//--------------------------------------------------------
/* @Fn			-MCAL_USART_SEND_DATA
 * @brief	    -SENDING data
 * @param [in]   -USARTX ,which x could be (1,2,3)
 * @param [in]   -pTx_Buffer
 * @param [in]   -polling_mechanis
 * @retval 		-none
 * Note			-none
 */
void MCAL_USART_SEND_DATA(USART_TYPEDEF* USARTX , uint16_t* pTx_Buffer , enum polling_mechanism pollen)
{
	if(pollen == enable)
	{
		while(READ_BIT(USARTX->SR , 7) == 0);
	}

	if ( GP_pinconfig -> payload_length == USART_WORD_LEN_8b)
	{
		USARTX->DR = ( (*pTx_Buffer) & 0xff );
	}

	else if (GP_pinconfig -> payload_length == USART_WORD_LEN_9b)
	{
		USARTX->DR = ( (*pTx_Buffer) & 0x1ff );
	}

}

void MCAL_USART_RECIEVE_DATA(USART_TYPEDEF* USARTX , uint16_t *pRx_Buffer , enum polling_mechanism pollen)
{
	if(pollen == enable)
	{
		while(READ_BIT(USARTX->SR , 5) == 0);
	}
	if(GP_pinconfig ->parity == USART_PARITY_NONE)
	{
		if(GP_pinconfig -> payload_length == USART_WORD_LEN_8b)
		{
			*pRx_Buffer = (USARTX->DR & (uint8_t)0xff ) ;
		}

		else if (GP_pinconfig -> payload_length == USART_WORD_LEN_9b)
		{
			*pRx_Buffer = (USARTX->DR & 0x1ff ) ;
		}

	}
	else
	{
		if(GP_pinconfig -> payload_length == USART_WORD_LEN_8b)
		{
			*pRx_Buffer = (USARTX->DR & (uint8_t)0x7f ) ;
		}

		else if (GP_pinconfig -> payload_length == USART_WORD_LEN_9b)
		{
			*pRx_Buffer = (USARTX->DR & (uint8_t)0xff ) ;
		}
	}

}

void USART1_IRQHandler(void)
{
	GP_IRQ_CALLBACK[0]();
}
void USART2_IRQHandler(void)
{
	GP_IRQ_CALLBACK[1]();
}
void USART3_IRQHandler(void)
{
	GP_IRQ_CALLBACK[2]();
}




