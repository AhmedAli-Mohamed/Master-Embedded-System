/*
 * KEYPAD.c
 *
 *  Created on: 17 Sep 2023
 *      Author: ahmed
 */
/*
 * KEYPAD.c
 *
 * Created: 2023/09/05 23:33:05
 *  Author: ahmed
 */

#include "KEYPAD.h"

void KEYPAD_INIT()
{
	int KP_ROW[]={R0,R1,R2,R3};
	int KP_COL[]={C0,C1,C2,C3};
	uint8_t i;
	GPIO_PINCONFIG pinconf;
	for(i=0 ; i<=3 ; i++)
	{
		pinconf.Pin_Number = KP_ROW[i];
		pinconf.MODE = GPIO_MODE_OUTPUT_PP;
		pinconf.Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(KEYPAD_DATAPORT , &pinconf);
	}
	for(i=0 ; i<=3 ; i++)
	{
		pinconf.Pin_Number = KP_COL[i];
		pinconf.MODE = GPIO_MODE_OUTPUT_PP;
		MCAL_GPIO_INIT(KEYPAD_DATAPORT ,& pinconf);
	}
	MCAL_GPIO_Writeport(GPIOB, 0x1ff);

}

uint8_t KEYPAD_READ()
{
	int KP_ROW[]={R0,R1,R2,R3};
	int KP_COL[]={C0,C1,C2,C3};
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	uint8_t row,col,return_val = 0xff;

	for(row = 0 ;row <= 3 ; row++)
	{
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , KP_ROW[0] , 1);
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , KP_ROW[1] , 1);
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , KP_ROW[2] , 1);
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , KP_ROW[3] , 1);
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , KP_ROW[row] , 0);

		for(col =0 ; col <= 3 ; col++)
		{

			if(MCAL_GPIO_Readpin(KEYPAD_DATAPORT , KP_COL[col]) == 0)
			{
				return_val = arr[row][col];
				break;
			}
		}
		if(return_val != 0xff)
		break;

	}

	return return_val;
}

