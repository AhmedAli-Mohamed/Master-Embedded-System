/*
 * I2C_EEPROM.c
 *
 *  Created on: 31 Oct 2023
 *      Author: ahmed
 */
#include"I2C_EEPROM.h"

void EEPROM_INIT()
{
	I2C_PINCONFIG i2c;
	i2c.ACK_CTRL = I2C_ACK_EN ;
	i2c.CLCK_Freq = I2C_CLCK_Freq_SM_100k ;
	i2c.CLCK_STRETCH = I2C_CLCK_STRTCH_EN ;
	i2c.GEN_CALL = I2C_GEN_CALL_EN ;
	i2c.MODE = I2C_MODE_I2C ;
	i2c.P_IRQ_SLAVE_CALLBACK = NULL ;


	MCAL_I2C_GPIO_SET_PINS(I2C1);
	MCAL_I2C_INIT(I2C1, &i2c);
}

void EEPROM_SEND_NBYTES(I2C_TYPEDEF* I2CX , uint16_t MEMORY_LOCATION , uint8_t * bytes , uint16_t data_len )
{
	uint16_t i;
	uint8_t buffer[256];
	buffer[0] = (uint8_t)(MEMORY_LOCATION >>8) ;
	buffer[1] = (uint8_t)(MEMORY_LOCATION) ;

	for(i=2 ; i< data_len +2 ; i++)
	{
		buffer[i] = bytes[i-2] ;
	}

	MCAL_I2C_MASTER_TX(I2C1, EEPROM_SLAVE_ADDRESS, buffer, data_len +2 , START, with_stop) ;

}

void EEPROM_RECIEVE_NBYTES(I2C_TYPEDEF* I2CX , uint16_t MEMORY_LOCATION , uint8_t * bytes , uint16_t data_len )
{
	uint16_t i;
	uint8_t buffer[2];
	buffer[0] =(uint8_t)(MEMORY_LOCATION >>8)  ;
	buffer[1] =(uint8_t)(MEMORY_LOCATION) ;

	MCAL_I2C_MASTER_TX(I2C1, EEPROM_SLAVE_ADDRESS, buffer, 2 , START, without_stop) ;
	MCAL_I2C_MASTER_RX(I2C1, EEPROM_SLAVE_ADDRESS, bytes, data_len, repeated_START, with_stop);

}
