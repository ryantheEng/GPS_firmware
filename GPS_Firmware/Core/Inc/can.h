
#include "stm32f1xx_hal.h"

#ifndef CAN_H_
#define CAN_H_

#define DEBUG   1

typedef struct
{
    /* data */
	CAN_RxHeaderTypeDef     rxheader; //rx message header
    HAL_StatusTypeDef       ret; //status return for CAN

    uint8_t     rxBuffer[512]; //CAN Buffer
    uint8_t     rxIndex;   
}CAN_r;


typedef struct
{
    /* data */
    uint8_t		rxBuffer[512];
	uint16_t	rxIndex;
	uint8_t		rxTmp;
	uint32_t	LastTime;
	uint8_t*	msgpointer;

    CAN_r       r;

}CAN_t;

extern CAN_t CAN;

void	can_Process(CAN_HandleTypeDef *hcan,CAN_RxHeaderTypeDef *rxheader, HAL_StatusTypeDef ret);

#endif /* CAN_H_ */
