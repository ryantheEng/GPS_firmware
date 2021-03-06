/*
 * gps.c
 *
 *  Created on: Feb. 13, 2021
 *      Author: rleeu
 */

//include
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gps.h>
#include "stm32f1xx_hal.h"

GPS_t GPS;

//init
void gps_Init(UART_HandleTypeDef *huart)
{
	GPS.rxIndex=0; //init counter to 0
	HAL_UART_Receive_IT(huart,&GPS.rxTmp,1); //get 1 byte
	GPS.to_output = NULL; //null pointer
}

//interrupt routine - //only calls if successful transmit
void gps_Callback(UART_HandleTypeDef *huart)
{
	GPS.LastTime=HAL_GetTick();

	if(GPS.rxIndex < sizeof(GPS.rxBuffer)-2) 
	{
		GPS.rxBuffer[GPS.rxIndex] = GPS.rxTmp; //save to buffer
		GPS.rxIndex++; //increment counter
	}
	HAL_UART_Receive_IT(huart,&GPS.rxTmp,1); //get 1 byte
}

double convertDegMinToDecDeg (float degMin)
{
  double min = 0.0;
  double decDeg = 0.0;

  //get the minutes, fmod() requires double
  min = fmod((double)degMin, 100.0);

  //rebuild coordinates in decimal degrees
  degMin = (int) ( degMin / 100 );
  decDeg = degMin + ( min / 60 );

  return decDeg;
}

//main GPS process - return pointer to GPGGA string for output via UART to XBEE
char * gps_Process(UART_HandleTypeDef *huart)
{

#if (DEBUG==1)
		printf('%s',GPS.rxBuffer);
#endif

	if( (HAL_GetTick()-GPS.LastTime>50) && (GPS.rxIndex>0))
	{
		char *str;

		//convert to string and unpack data
		str=strstr((char*)GPS.rxBuffer,'$GPGGA,');
		if (str!=NULL)
		{
			memset(&GPS.GPGGA,0,sizeof(GPS.GPGGA)); //clear GPGGA (set to 0)
			sscanf(str,"$GPGGA,%2hhd%2hhd%2hhd.%3hd,%f,%c,%f,%c,%hhd,%hhd,%f,%f,%c,%hd,%s,*%2s\r\n",
										&GPS.GPGGA.UTC_Hour,&GPS.GPGGA.UTC_Min,&GPS.GPGGA.UTC_Sec,
										&GPS.GPGGA.UTC_MicroSec,&GPS.GPGGA.Latitude,&GPS.GPGGA.NS_Indicator,&GPS.GPGGA.Longitude,
										&GPS.GPGGA.EW_Indicator,&GPS.GPGGA.PositionFixIndicator,
										&GPS.GPGGA.SatellitesUsed,&GPS.GPGGA.HDOP,&GPS.GPGGA.MSL_Altitude,&GPS.GPGGA.MSL_Units,
										&GPS.GPGGA.AgeofDiffCorr,GPS.GPGGA.DiffRefStationID,GPS.GPGGA.CheckSum); //reads formatted data to GPGGA
			if(GPS.GPGGA.NS_Indicator==0)
				GPS.GPGGA.NS_Indicator='-';
			if(GPS.GPGGA.EW_Indicator==0)
				GPS.GPGGA.EW_Indicator='-';
			if(GPS.GPGGA.Geoid_Units==0)
				GPS.GPGGA.Geoid_Units='-';
			if(GPS.GPGGA.MSL_Units==0)
				GPS.GPGGA.MSL_Units='-';
			GPS.GPGGA.LatitudeDecimal=convertDegMinToDecDeg(GPS.GPGGA.Latitude);
			GPS.GPGGA.LongitudeDecimal=convertDegMinToDecDeg(GPS.GPGGA.Longitude);

			//put data back into string only UTC, latitude, longitude
			sprintf(GPS.to_output,"$GPGGA,%2hhd%2hhd%2hhd.%3hd,%f,%c,%f,%c,%hhd,%hhd,%f,%f,%c\r\n",
					&GPS.GPGGA.UTC_Hour,&GPS.GPGGA.UTC_Min,&GPS.GPGGA.UTC_Sec,
					&GPS.GPGGA.UTC_MicroSec,&GPS.GPGGA.Latitude,&GPS.GPGGA.NS_Indicator,&GPS.GPGGA.Longitude,
					&GPS.GPGGA.EW_Indicator,&GPS.GPGGA.PositionFixIndicator,
					&GPS.GPGGA.SatellitesUsed,&GPS.GPGGA.HDOP,&GPS.GPGGA.MSL_Altitude,&GPS.GPGGA.MSL_Units
					//,&GPS.GPGGA.AgeofDiffCorr,GPS.GPGGA.DiffRefStationID,GPS.GPGGA.CheckSum
					);
		}
		memset(GPS.rxBuffer,0,sizeof(GPS.rxBuffer)); //reset rx buffer
		GPS.rxIndex=0; //reset rx index
	}

	//sleep maybe??
	
	//HAL_UART_Receive_IT(huart,&GPS.rxTmp,1);
}
