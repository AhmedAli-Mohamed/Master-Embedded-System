/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include"stm32f103x6.h"
#include"GPIO.h"
#include"EXTI.h"
void GPIO_init()
{


	//PA.1 as input floating
	GPIO_PINCONFIG pin_conf;
	pin_conf.Pin_Number = 1;
	pin_conf.MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &pin_conf);

	//PB.1 as output push pull
	pin_conf.Pin_Number = 1;
	pin_conf.MODE = GPIO_MODE_OUTPUT_PP;
	pin_conf.Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB,&pin_conf);


	//PB.13 as output push pull
	pin_conf.Pin_Number = 13;
	pin_conf.MODE = GPIO_MODE_OUTPUT_PP;
	pin_conf.Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_INIT(GPIOB, &pin_conf);
}


void delay(int m)
{
	int i;
	for(i=0;i< m * 255;i++);
}
void EXTI13_CALLBACK(void)
{
	MCAL_GPIO_Togglepin(GPIOB,13);
}


int main(void)
{
   CLOCK_ENABLE_GPIOA;
   CLOCK_ENABLE_GPIOB;
   CLOCK_ENABLE_AFIO;
   GPIO_init();
   EXTI_PIN_CONFIG EXTI_PIN;
   EXTI_PIN.EXTI_PIN = EXTI13PA13;
   EXTI_PIN.IR_EN = IR_ENABLE;
   EXTI_PIN.Trigger_MODE = EXTI_TRMODE_RISING;
   EXTI_PIN.P_IRQ_CALLBACK = EXTI13_CALLBACK;
   MCAL_EXTI_INIT(&EXTI_PIN);



	while(1)
	{

	}
}
