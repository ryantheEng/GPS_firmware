/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "xbee.h"
#include "gps.h"
#include "can.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define MAX_CAN_MESSAGES	4
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define GPS_TX_Pin GPIO_PIN_2
#define GPS_TX_GPIO_Port GPIOA
#define GPS_RX_Pin GPIO_PIN_3
#define GPS_RX_GPIO_Port GPIOA
#define GPS_nRST_Pin GPIO_PIN_5
#define GPS_nRST_GPIO_Port GPIOA
#define RADIO_nRST_Pin GPIO_PIN_7
#define RADIO_nRST_GPIO_Port GPIOA
#define CELL_PWM_Pin GPIO_PIN_1
#define CELL_PWM_GPIO_Port GPIOB
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define RADIO_TX_Pin GPIO_PIN_10
#define RADIO_TX_GPIO_Port GPIOB
#define RADIO_RX_Pin GPIO_PIN_11
#define RADIO_RX_GPIO_Port GPIOB
#define CELL_SLEEP_Pin GPIO_PIN_13
#define CELL_SLEEP_GPIO_Port GPIOB
#define CELL_nRTS_Pin GPIO_PIN_14
#define CELL_nRTS_GPIO_Port GPIOB
#define CELL_nRST_Pin GPIO_PIN_15
#define CELL_nRST_GPIO_Port GPIOB
#define CELL_TX_Pin GPIO_PIN_9
#define CELL_TX_GPIO_Port GPIOA
#define CELL_RX_Pin GPIO_PIN_10
#define CELL_RX_GPIO_Port GPIOA
#define RADIO_PWM_Pin GPIO_PIN_11
#define RADIO_PWM_GPIO_Port GPIOA
#define RADIO_SLEEP_Pin GPIO_PIN_12
#define RADIO_SLEEP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWDCLK_Pin GPIO_PIN_14
#define SWDCLK_GPIO_Port GPIOA
#define RADIO_nRTS_Pin GPIO_PIN_15
#define RADIO_nRTS_GPIO_Port GPIOA
#define GPS_SCL_Pin GPIO_PIN_6
#define GPS_SCL_GPIO_Port GPIOB
#define GPS_SDA_Pin GPIO_PIN_7
#define GPS_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
