/*
 * gps.h
 *
 *  Created on: Feb. 13, 2021
 *      Author: rleeu
 *      code refactored from github here @ https://github.com/nimaltd/GPS
 */

#ifndef GPS_H_
#define GPS_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"

#define DEBUG	1

//init data struct for NMEA data transmision
typedef struct
{
	uint8_t			UTC_Hour;
	uint8_t			UTC_Min;
	uint8_t			UTC_Sec;
	uint16_t		UTC_MicroSec;

	float				Latitude;
	double			LatitudeDecimal;
	char				NS_Indicator;
	float				Longitude;
	double			LongitudeDecimal;
	char				EW_Indicator;

	uint8_t			PositionFixIndicator;
	uint8_t			SatellitesUsed;
	float				HDOP;
	float				MSL_Altitude;
	char				MSL_Units;
	float				Geoid_Separation;
	char				Geoid_Units;

	uint16_t		AgeofDiffCorr;
	char				DiffRefStationID[4];
	char				CheckSum[2];
}GPGGA_t;

typedef struct
{
	uint8_t		rxBuffer[512];
	uint16_t	rxIndex;
	uint8_t		rxTmp;
	uint32_t	LastTime;
	char*		to_output; // so I can access from different functions

	GPGGA_t		GPGGA;

}GPS_t;

extern GPS_t GPS;

void	gps_Init(UART_HandleTypeDef *huart);
void	gps_CallBack(UART_HandleTypeDef *huart);
char*	gps_Process(UART_HandleTypeDef *huart);


#endif /* GPS_H_ */
