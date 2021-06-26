/*
 * xbee.c
 *
 *  Created on: Mar. 19, 2021
 *      Author: rleeu
 */

#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <xbee.h>

XBEE_t XBEE;

//interrupt routine - only calls if successful transmit
void xbee_Callback(UART_HandleTypeDef *huart)
{
	XBEE.LastTime=HAL_GetTick();

	if(XBEE.txIndex < sizeof(XBEE.txBuffer))
	{
		XBEE.txTmp = XBEE.txBuffer[XBEE.txIndex]; //move data to tmp
		XBEE.txIndex++;
	}
	HAL_UART_Transmit_IT(&huart,&XBEE.txTmp,1); //ssend another byte from txtmp
}

void xbee_Process(UART_HandleTypeDef *huart, char *to_output)
{
	XBEE.txIndex=0;  //init index to 0
	//XBEE.txBuffer = to_output; //move data to buffer

	XBEE.txTmp = to_output[XBEE.txIndex]; //move data to tmp
	XBEE.txIndex++;

	HAL_UART_Transmit_IT(&huart,&XBEE.txTmp,1); //transmit 1 byte from txtmp

	//sleep maybe??
}
