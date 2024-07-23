/*
 * I2C.c
 *
 *  Created on: 30 Oct 2023
 *      Author: ahmed
 */
#include"stm32f103x6.h"
#include"I2C.h"
/* ==============================================================================
 *                            GENARIC Variables
 * ==============================================================================
 */


I2C_PINCONFIG G_pinconfig[2];


/* ==============================================================================
 *                            GENARIC Functions
 * ==============================================================================
 */
FLAG_STATUS I2C_FLAG_STATUS(I2C_TYPEDEF* I2CX ,EVENT_SRC event)
{
	uint32_t flag1=0,flag2=0,lastread=0;

	FLAG_STATUS bit_status = RESET;

	switch (event)
	{
	case BUSY :
	{
		if ( READ_BIT(I2CX->SR2 , 1))
		{
			bit_status = SET;

		}
		else
			bit_status = RESET;

		break ;
	}

	case EV_5 :
	{
		if ( READ_BIT(I2CX->SR1 , 0))
		{
			bit_status = SET;

		}
		else
			bit_status = RESET;

		break ;
	}
	case EV_6 :
	{
		if ( READ_BIT(I2CX->SR1 , 1))
		{
			bit_status = SET;

		}
		else
			bit_status = RESET;

		break ;
	}

	case EV_8 :
	{
		if ( READ_BIT(I2CX->SR1 , 7))
		{
			bit_status = SET;

		}
		else
			bit_status = RESET;

		break ;
	}
	case MASTER_BYTE_TRANSMISSION :
	{
		flag1 = I2CX->SR1 ;
		flag2 = I2CX->SR2 ;
		lastread = (flag1 | flag2) & 0x00FFFFFF ;
		if( (lastread & event) == event)
		{
			bit_status = SET;

		}
		else
			bit_status = RESET;

		break ;
	}

	case EV_7 :
	{
		if ( READ_BIT(I2CX->SR1 , 6))
		{
			bit_status = SET;

		}
		else
			bit_status = RESET;

		break ;
	}
	}



	return bit_status;
}

void I2C_GENERATE_START(I2C_TYPEDEF* I2CX ,START_STATUS start )
{
	//check if bus is not busy
	if (start == START)
	{
		while(I2C_FLAG_STATUS(I2CX, BUSY));
	}

	// Send start condition
	SET_BIT(I2CX->CR1 , 8) ;

}

void I2C_SEND_ADDREESS(I2C_TYPEDEF* I2CX ,uint16_t dev_add , I2C_DIRECTION dir )
{
	uint16_t ADDRESS;

	ADDRESS = dev_add << 1 ;

	if ( dir == READ)
	{
		SET_BIT(ADDRESS , 0) ;

	}
	else if (dir == WRITE)
	{
		RESET_BIT(ADDRESS , 0);
	}

	I2CX->DR = ADDRESS ;
}
/* ==============================================================================
 *                            APIs
 * ==============================================================================
 */
//--------------------------------------
/* @Fn			-MCAL_I2C_INIT
 * @brief	    -INIT all I2C REGISTERS
 * @param [in]   -I2CX ,which x could be (1,2)
 * @param [in]   -pin_conf
 * @retval 		-none
 * Note			-none
 */
void MCAL_I2C_INIT(I2C_TYPEDEF* I2CX , I2C_PINCONFIG* pin_conf)
{
	uint32_t pclck1=0, temp_reg =0 ,freq_in_mega=0;


	//RCC CLOCK ENABLE
	if(I2CX == I2C1)
	{
		CLOCK_ENABLE_I2C1;
		G_pinconfig[0] = *pin_conf ;

	}
	else
	{
		CLOCK_ENABLE_I2C2;
		G_pinconfig[1] = *pin_conf ;
	}

	if (pin_conf->MODE != I2C_MODE_SMBUS)
	{
		//***********************    INIT CLOCK     ************************

		//1-  SET FREQ IN CR2_REG
		pclck1 = MCAL_RCC_GETPCLK1Freq();
		freq_in_mega = pclck1 / 1000000UL;
		I2CX->CR2 = (freq_in_mega & 0x3F) ;


		//2-  SET CCR IN CCR_REG
		if ( (pin_conf->CLCK_Freq ==I2C_CLCK_Freq_SM_100k)   )
		{


			temp_reg = (pclck1) / ( 2 * 100000 ) ;
			I2CX->CCR = (temp_reg & 0x7FF ) ;


		}
		else
		{
			//FM NOT SUPPORTED YET ;
		}


		//3- SET TRISE IN TRISE_REG
		temp_reg = freq_in_mega +1 ;
		I2CX->TRISE = ( temp_reg & 0x3F);


		//***********************    INIT SLAVE     ************************
		temp_reg = 0;
		if(pin_conf->slave.ADD_MODE != I2C_SLAVE_ADD_MODE_10BIT)
		{
			temp_reg = pin_conf->slave.PRIMARY_ADD << 1 ;
			I2CX->OAR1 = temp_reg & 0xFF ;

			if(pin_conf->slave.ENDUAL_ADD == I2C_SLAVE_DUAL_ADD_EN)
			{
				temp_reg = pin_conf->slave.SECONDARY_ADD | pin_conf->slave.ENDUAL_ADD ;
				I2CX->OAR2 = temp_reg & 0xFF ;
			}
		}
		else
		{
			temp_reg = pin_conf->slave.PRIMARY_ADD ;
			I2CX->OAR1 = temp_reg & 0x3FF ;
		}



		//**************************** CR1 CONF ******************************

		temp_reg = 0;
		temp_reg = pin_conf->ACK_CTRL | pin_conf->CLCK_STRETCH | pin_conf->GEN_CALL ;
		I2CX->CR1 = temp_reg ;



	}
	else
	{
		//SMBUS NOT SUPPORTED YET ;
	}

	//****************************INTERRUPT CONF******************************

	if(pin_conf->P_IRQ_SLAVE_CALLBACK != NULL)
	{
		temp_reg = 0;
		temp_reg = (1<<8) | (1<<9) | (1<<10) ;
		I2CX->CR2 = temp_reg ;
		if (I2CX == I2C1)
		{
			NVIC_I2C1_ER_ENABLE ;
			NVIC_I2C1_EV_ENABLE ;
		}
		else
		{
			NVIC_I2C2_ER_ENABLE ;
			NVIC_I2C2_EV_ENABLE ;
		}
	}


	// ENABLE I2C

	SET_BIT(I2CX->CR1 , 0) ;

}
/* @Fn			-MCAL_I2C_DEINIT
 * @brief	    -DEINIT all I2C REGISTERS
 * @param [in]   -I2CX ,which x could be (1,2)
 * @retval 		-none
 * Note			-none
 */
void MCAL_I2C_DEINIT(I2C_TYPEDEF* I2CX )
{
	if(I2CX ==I2C1)
	{
		RCC->APB1RSTR |= (1<<21);

		NVIC_I2C1_EV_DISABLE;
		NVIC_I2C1_ER_DISABLE;
	}
	else if (I2CX ==I2C2)
	{
		RCC->APB1RSTR |= (1<<22);

		NVIC_I2C2_EV_DISABLE;
		NVIC_I2C2_ER_DISABLE;
	}
}

//--------------------------------------------------------
/* @Fn			-MCAL_I2C_GPIO_SET_PINS
 * @brief	    -initialize send and receive and clock pins of specific I2C
 * @param [in]   -I2CX ,which x could be (1,2)
 * @retval 		-none
 * Note			-none
 */
void MCAL_I2C_GPIO_SET_PINS(I2C_TYPEDEF* I2CX )
{
	GPIO_PINCONFIG pinconf;

	//PB.6 		I2C1_SCL
	//PB.7		I2C1_SDA
	if(I2CX ==I2C1)
	{
		//PB.6
		pinconf.Pin_Number = GPIO_PIN_6 ;
		pinconf.MODE = GPIO_MODE_OUTPUT_AF_OP ;
		pinconf.Speed = GPIO_SPEED_10M ;
		MCAL_GPIO_INIT(GPIOB, &pinconf);

		//PB.7
		pinconf.Pin_Number = GPIO_PIN_7 ;
		pinconf.MODE = GPIO_MODE_OUTPUT_AF_OP ;
		pinconf.Speed = GPIO_SPEED_10M ;
		MCAL_GPIO_INIT(GPIOB, &pinconf);

	}

	//PB.10 		I2C1_SCL
	//PB.11		    I2C1_SDA
	else if (I2CX ==I2C2)
	{
		//PB.10
		pinconf.Pin_Number = GPIO_PIN_10 ;
		pinconf.MODE = GPIO_MODE_OUTPUT_AF_OP ;
		pinconf.Speed = GPIO_SPEED_10M ;
		MCAL_GPIO_INIT(GPIOB, &pinconf);

		//PB.11
		pinconf.Pin_Number = GPIO_PIN_11 ;
		pinconf.MODE = GPIO_MODE_OUTPUT_AF_OP ;
		pinconf.Speed = GPIO_SPEED_10M ;
		MCAL_GPIO_INIT(GPIOB, &pinconf);


	}
}

//--------------------------------------------------------
/* @Fn			-MCAL_I2C_MASTER_TX
 * @brief	    -SENDING data
 * @param [in]   -I2CX ,which x could be (1,2)
 * @param [in]   -data_Buffer
 * @param [in]   -datalen
 * @param [in]   - start status
 * @param [in]	 -stop status
 * @retval 		-none
 * Note			-none
 */
void MCAL_I2C_MASTER_TX(I2C_TYPEDEF* I2CX ,uint16_t dev_add, uint8_t * data , uint16_t data_len ,START_STATUS start,STOP_STATUS stop )
{
	uint16_t dummy_read,i;
	//1- SEND START BIT
	I2C_GENERATE_START(I2CX, start);

	//2-WAIT UNTIL SB=1
	while( !I2C_FLAG_STATUS(I2CX, EV_5));

	//3-SEND ADDRESS
	I2C_SEND_ADDREESS(I2CX, dev_add , WRITE);

	//4-WAIT UNTIL ADDR=1
	while( !I2C_FLAG_STATUS(I2CX, EV_6));
	dummy_read = I2CX->SR2 ;

	//5- check MSL,TRA,TXE
	while( !I2C_FLAG_STATUS(I2CX, EV_8));


	//5-SEND DATA
	for(i=0 ; i< data_len ; i++)
	{
		//write data on DR
		I2CX->DR = data[i];
		// check if buffer is empty
		while( !I2C_FLAG_STATUS(I2CX, EV_8));


	}

	//6- SEND STOP CONDITION
	if(stop == with_stop)
		SET_BIT(I2CX->CR1 , 9) ;

}

void MCAL_I2C_MASTER_RX(I2C_TYPEDEF* I2CX ,uint16_t dev_add, uint8_t * data , uint16_t data_len ,START_STATUS start,STOP_STATUS stop )
{
	uint16_t dummy_read,i;
	//1-SEND START CONDITION

	I2C_GENERATE_START(I2CX, start);

	//2-WAIT UNTIL SB=1
	while( !I2C_FLAG_STATUS(I2CX, EV_5));


	//3-SEND ADDRESS
	I2C_SEND_ADDREESS(I2CX, dev_add , READ);

	//4-WAIT UNTIL ADDR=1
	while( !I2C_FLAG_STATUS(I2CX, EV_6));
	dummy_read = I2CX->SR2 ;

	//5- ENABLE ACK
	SET_BIT(I2CX->CR1 , 10) ;

	//6-RECEIVE DATA
	for(i=0; i< data_len ; i++)
	{
		// check if buffer is empty
		while( !I2C_FLAG_STATUS(I2CX, EV_7));
		//READ data from DR
		data[i] =I2CX->DR;
	}

	//7-SEND NACK
	RESET_BIT(I2CX->CR1 , 10) ;

	//8- SEND STOP CONDITION
	if(stop == with_stop)
		SET_BIT(I2CX->CR1 , 9) ;

}

