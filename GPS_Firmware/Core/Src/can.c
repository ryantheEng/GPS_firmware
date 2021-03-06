/*
Source file for CAN receive process
*/

//include
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <can.h>
#include "stm32f1xx_hal.h"

CAN_t CAN;

//can init done in main

void can_Process(CAN_HandleTypeDef *hcan,CAN_RxHeaderTypeDef *rxheader, HAL_StatusTypeDef ret)
{
    uint8_t message[8];
    CAN.msgpointer = NULL;

    if (HAL_CAN_GetRxFifoFillLevel(hcan, CAN_RX_FIFO0) > 0)
    {
        //get can message and store in message
        ret = HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0,rxheader,message);
    }

#if (DEBUG==1)
		printf('%s',message);
#endif

    if (ret != HAL_OK)
    {
		printf("\r\n Error TX \r\n");
    }
    else
    {
    	CAN.msgpointer = &message; //save address of can message
    }
}
