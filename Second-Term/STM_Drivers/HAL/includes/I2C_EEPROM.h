/*
 * I2C_EEPROM.h
 *
 *  Created on: 31 Oct 2023
 *      Author: ahmed
 */

#ifndef INCLUDES_I2C_EEPROM_H_
#define INCLUDES_I2C_EEPROM_H_

#include"I2C.h"

#define EEPROM_SLAVE_ADDRESS				0x2A



void EEPROM_INIT();
void EEPROM_SEND_NBYTES(I2C_TYPEDEF* I2CX , uint16_t MEMORY_LOCATION , uint8_t * bytes , uint16_t data_len );
void EEPROM_RECIEVE_NBYTES(I2C_TYPEDEF* I2CX , uint16_t MEMORY_LOCATION , uint8_t * bytes , uint16_t data_len );

#endif /* INCLUDES_I2C_EEPROM_H_ */
