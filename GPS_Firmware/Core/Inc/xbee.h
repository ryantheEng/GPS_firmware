/*
 * xbee.h
 *
 *  Created on: Mar. 19, 2021
 *      Author: rleeu
 */

#include "stm32f1xx_hal.h"

#ifndef INC_XBEE_H_
#define INC_XBEE_H_

#define DEBUG	1

typedef struct
{
	uint8_t		txBuffer[512];
	uint8_t		txTmp;
	uint16_t	txIndex;
	uint32_t	LastTime;

}XBEE_t;

extern XBEE_t XBEE;


void	xbee_Callback(UART_HandleTypeDef *huart);
void 	xbee_Process(UART_HandleTypeDef *huart, char *to_output);

#endif /* INC_XBEE_H_ */
