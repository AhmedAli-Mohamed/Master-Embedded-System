/*
 * SPI.c
 *
 *  Created on: 26 Sep 2023
 *      Author: ahmed
 */
#include"SPI.h"
#include"GPIO.h"
#include"RCC.h"
/* ==============================================================================
 *                            GENARIC Variables
 * ==============================================================================
 */


SPI_PINCONFIG * GP_pinconfig;
SPI_PINCONFIG  G_pinconfig;
void (*GP_IRQ_CALLBACK[2])(S_IRQ_SRC irq_src);


/* ==============================================================================
 *                            APIs
 * ==============================================================================
 */
/* @Fn			-MCAL_USART_DEINIT
 * @brief	    -DEINIT all SPI REGISTERS
 * @param [in]   -SPIX ,which x could be (1,2)
 * @retval 		-none
 * Note			-none
 */
void MCAL_SPI_DEINIT(SPI_TYPEDEF* SPIX )
{
	if(SPIX == SPI1)
	{
		RCC->APB2RSTR |= (1<<12) ;
		NVIC_SPI1_DISABLE ;
	}
	else if (SPIX == SPI2)
	{
		RCC->APB1RSTR |= (1<<14) ;
		NVIC_SPI2_DISABLE ;
	}

}


/* @Fn			-MCAL_SPI_INIT
 * @brief	    -INIT all SPIX REGISTERS
 * @param [in]   -SPIX ,which x could be (1,2)
 * @param [in]   -pin_conf
 * @retval 		-none
 * Note			-none
 */
void MCAL_SPI_INIT(SPI_TYPEDEF* SPIX , SPI_PINCONFIG* pin_conf)
{
	uint16_t temp_CR1 =0 , temp_CR2 =0 ;
	G_pinconfig = * pin_conf ;
	GP_pinconfig =  & G_pinconfig;

	//enable clock & interrupt
	if(SPIX == SPI1)
	{
		CLOCK_ENABLE_SPI1;
		if(pin_conf->IRQ_ENABLE != SPI_IRQ_NONE)
		{
			NVIC_SPI1_ENABLE;
			temp_CR2 |= pin_conf->IRQ_ENABLE;
			GP_IRQ_CALLBACK[0] = pin_conf->P_IRQ_CALLBACK;

		}

	}
	else if (SPIX == SPI1)
	{
		CLOCK_ENABLE_SPI2;
		if(pin_conf->IRQ_ENABLE != SPI_IRQ_NONE)
		{
			NVIC_SPI2_ENABLE;
			temp_CR2 |= pin_conf->IRQ_ENABLE;
			GP_IRQ_CALLBACK[1] = pin_conf->P_IRQ_CALLBACK;

		}
	}

	//initialize polarity & phase
	temp_CR1 |= pin_conf->polarity ;
	temp_CR1 |= pin_conf->phase ;

	//initialize data size & frame format
	temp_CR1 |= pin_conf->DATA_SIZE ;
	temp_CR1 |= pin_conf->FRAME_FORMAT ;

	//initialize clock frequency
	temp_CR1 |= pin_conf->CLCK ;

	//initialize device mode & COMM_mode
	temp_CR1 |= pin_conf->Device_MODE ;
	temp_CR1 |= pin_conf->COMM_MODE ;

	//initialize NSS
	if((pin_conf->NSS == SPI_NSS_HARD_MASTER_SS_OUTPUT) || (pin_conf->NSS == SPI_NSS_HARD_MASTER_SS_INPUT) )
	{
		temp_CR2 |= pin_conf->NSS;

	}

	else
	{
		temp_CR1 |= pin_conf->NSS;
	}

	//enable SPI
	temp_CR1 |= (1<<6) ;

	//feeling REGS with values
	SPIX->CR1 = (uint32_t)temp_CR1 ;
	SPIX->CR2 = (uint32_t)temp_CR2 ;



}

void MCAL_SPI_SEND_DATA(SPI_TYPEDEF* SPIX , uint16_t *pTx_Buffer , enum polling_mechanism pollen)
{
	if(pollen == enable)
	{
		while(READ_BIT(SPIX->SR , 1) == 0 );
	}

	SPIX->DR = *pTx_Buffer ;

}

void MCAL_SPI_RECIEVE_DATA(SPI_TYPEDEF* SPIX , uint16_t *pRx_Buffer , enum polling_mechanism pollen)
{
	if(pollen == enable)
	{
		while(READ_BIT(SPIX->SR , 0) == 0 );
	}

	*pRx_Buffer =  SPIX->DR ;
}

void MCAL_SPI_SEND_RECIEVE_DATA(SPI_TYPEDEF* SPIX , uint16_t *pRx_Buffer , enum polling_mechanism pollen)
{
	if(pollen == enable)
	{
		while(READ_BIT(SPIX->SR , 1) == 0 );
	}

	SPIX->DR = *pRx_Buffer ;

	if(pollen == enable)
	{
		while(READ_BIT(SPIX->SR , 0) == 0 );
	}
	*pRx_Buffer =  SPIX->DR ;

}

void MCAL_SPI_GPIO_SET_PINS(SPI_TYPEDEF* SPIX )
{
	GPIO_PINCONFIG pinconf;
	if(SPIX ==SPI1)
	{
		//PA.4  NSS
		//PA.5  SCLK
		//PA.6  MISO
		//PA.7	MOSI


		// MASTER CONFIGURATION
		if(GP_pinconfig->Device_MODE == SPI_DEVICE_MODE_MASTER)
		{
			//PA.4  NSS
			switch(GP_pinconfig->NSS)
			{
			case SPI_NSS_HARD_MASTER_SS_OUTPUT :
				pinconf.Pin_Number = GPIO_PIN_4 ;
				pinconf.MODE = GPIO_MODE_OUTPUT_AF_PP ;
				pinconf.Speed = GPIO_SPEED_10M ;
				MCAL_GPIO_INIT(GPIOA, &pinconf);

				break;


			case SPI_NSS_HARD_MASTER_SS_INPUT :
				pinconf.Pin_Number = GPIO_PIN_4 ;
				pinconf.MODE = GPIO_MODE_INPUT_FLO ;
				MCAL_GPIO_INIT(GPIOA, &pinconf);

				break;

			}

			//PA.5  SCLK
			pinconf.Pin_Number = GPIO_PIN_5 ;
			pinconf.MODE = GPIO_MODE_OUTPUT_AF_PP ;
			pinconf.Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_INIT(GPIOA, &pinconf);


			//PA.6  MISO
			pinconf.Pin_Number = GPIO_PIN_6 ;
			pinconf.MODE = GPIO_MODE_INPUT_FLO ;
			MCAL_GPIO_INIT(GPIOA, &pinconf);


			//PA.7	MOSI
			pinconf.Pin_Number = GPIO_PIN_7 ;
			pinconf.MODE = GPIO_MODE_OUTPUT_AF_PP ;
			pinconf.Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_INIT(GPIOA, &pinconf);



		}

		//SLAVE CONFIGURATION
		else
		{

			//PA.4  NSS

			if(GP_pinconfig->NSS == SPI_NSS_HARD_SLAVE)
			{
				pinconf.Pin_Number = GPIO_PIN_4 ;
				pinconf.MODE = GPIO_MODE_INPUT_FLO ;
				MCAL_GPIO_INIT(GPIOA, &pinconf);
			}

			//PA.5  SCLK
			pinconf.Pin_Number = GPIO_PIN_5 ;
			pinconf.MODE = GPIO_MODE_INPUT_FLO ;
			MCAL_GPIO_INIT(GPIOA, &pinconf);

			//PA.7	MOSI
			pinconf.Pin_Number = GPIO_PIN_7 ;
			pinconf.MODE = GPIO_MODE_INPUT_FLO ;
			MCAL_GPIO_INIT(GPIOA, &pinconf);


			//PA.6  MISO
			pinconf.Pin_Number = GPIO_PIN_6 ;
			pinconf.MODE = GPIO_MODE_OUTPUT_AF_PP ;
			pinconf.Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_INIT(GPIOA, &pinconf);



		}


	}
	else if(SPIX == SPI2)
	{
		//PB.12	NSS
		//PB.13  SCLK
		//PB.14  MISO
		//PB.15	MOSI

		// MASTER CONFIGURATION
		if(GP_pinconfig->Device_MODE == SPI_DEVICE_MODE_MASTER)
		{
			//PB.12	NSS
			switch(GP_pinconfig->NSS)
			{
			case SPI_NSS_HARD_MASTER_SS_OUTPUT :
				pinconf.Pin_Number = GPIO_PIN_12 ;
				pinconf.MODE = GPIO_MODE_OUTPUT_AF_PP ;
				pinconf.Speed = GPIO_SPEED_10M ;
				MCAL_GPIO_INIT(GPIOB, &pinconf);

				break;


			case SPI_NSS_HARD_MASTER_SS_INPUT :
				pinconf.Pin_Number = GPIO_PIN_12 ;
				pinconf.MODE = GPIO_MODE_INPUT_FLO ;
				MCAL_GPIO_INIT(GPIOB, &pinconf);

				break;

			}

			//PB.13  SCLK
			pinconf.Pin_Number = GPIO_PIN_13 ;
			pinconf.MODE = GPIO_MODE_OUTPUT_AF_PP ;
			pinconf.Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_INIT(GPIOB, &pinconf);


			//PB.14  MISO
			pinconf.Pin_Number = GPIO_PIN_14 ;
			pinconf.MODE = GPIO_MODE_INPUT_FLO ;
			MCAL_GPIO_INIT(GPIOB, &pinconf);


			//PB.15	MOSI
			pinconf.Pin_Number = GPIO_PIN_15 ;
			pinconf.MODE = GPIO_MODE_OUTPUT_AF_PP ;
			pinconf.Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_INIT(GPIOB, &pinconf);



		}

		//SLAVE CONFIGURATION
		else
		{

			//PB.12	NSS

			if(GP_pinconfig->NSS == SPI_NSS_HARD_SLAVE)
			{
				pinconf.Pin_Number = GPIO_PIN_12 ;
				pinconf.MODE = GPIO_MODE_INPUT_FLO ;
				MCAL_GPIO_INIT(GPIOB, &pinconf);
			}

			//PB.13  SCLK
			pinconf.Pin_Number = GPIO_PIN_13 ;
			pinconf.MODE = GPIO_MODE_INPUT_FLO ;
			MCAL_GPIO_INIT(GPIOB, &pinconf);

			//PB.15	MOSI
			pinconf.Pin_Number = GPIO_PIN_15 ;
			pinconf.MODE = GPIO_MODE_INPUT_FLO ;
			MCAL_GPIO_INIT(GPIOB, &pinconf);


			//PB.14  MISO
			pinconf.Pin_Number = GPIO_PIN_14 ;
			pinconf.MODE = GPIO_MODE_OUTPUT_AF_PP ;
			pinconf.Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_INIT(GPIOB, &pinconf);



		}

	}


}




/*
 * ==============================================================================
 *                            IRQ
 * ==============================================================================
 */

void SPI1_IRQHandler (void)
{
	S_IRQ_SRC irq_src;
	irq_src.TXE = READ_BIT(SPI1->SR , 1);
	irq_src.RXNE = READ_BIT(SPI1->SR , 0);
	GP_IRQ_CALLBACK[0](irq_src);
}

void SPI2_IRQHandler (void)
{
	S_IRQ_SRC irq_src;
	irq_src.TXE = READ_BIT(SPI2->SR , 1);
	irq_src.RXNE = READ_BIT(SPI2->SR , 0);
	GP_IRQ_CALLBACK[1](irq_src);
}
