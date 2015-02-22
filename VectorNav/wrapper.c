/**
 * VectorNav IMU wrapper
 *
 * Copyright (C) 2015  Heechul Yun <heechul.yun@ku.edu> 
 *
 * This file is distributed under the GPLv2 License. 
 */ 

/**************************************************************************
 * Conditional Compilation Options
 **************************************************************************/

/**************************************************************************
 * Included Files
 **************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include "EKF_IFS_2.h"
#include "vectornav.h"

/**************************************************************************
 * Public Definitions
 **************************************************************************/
const char* const COM_PORT = "//dev//ttyUSB0";
const int BAUD_RATE = 115200;

/**************************************************************************
 * Public Types
 **************************************************************************/

/**************************************************************************
 * Global Variables
 **************************************************************************/
static Vn200 vn200;

/**************************************************************************
 * Public Function Prototypes
 **************************************************************************/

void InitIMU(void)
{
	VN_ERROR_CODE errorCode;
	errorCode = vn200_connect(
		&vn200,
		COM_PORT,
		BAUD_RATE);

	/* Make sure the user has permission to use the COM port. */
	if (errorCode == VNERR_PERMISSION_DENIED) {
		printf("Current user does not have permission to open the COM port.\n");
		printf("Try running again using 'sudo'.\n");
	}
	else if (errorCode != VNERR_NO_ERROR)
	{
		printf("Error encountered when trying to connect to the sensor.\n");
	}
}

void GetIMUData(ExtU_EKF_IFS_2_T *data)
{
	double gpsTime;
	unsigned short gpsWeek, status;
	VnVector3 ypr, latitudeLognitudeAltitude, nedVelocity;
	float attitudeUncertainty, positionUncertainty, velocityUncertainty;

	vn200_getInsSolutionLla(
		&vn200,
		&gpsTime,
		&gpsWeek,
		&status,
		&ypr,
		&latitudeLognitudeAltitude,
		&nedVelocity,
		&attitudeUncertainty,
		&positionUncertainty,
		&velocityUncertainty);

	data->GPSPosition.Latitude = latitudeLognitudeAltitude.c0;
	data->GPSPosition.Longitude = latitudeLognitudeAltitude.c1;
	data->GPSPosition.Altitude = latitudeLognitudeAltitude.c2;

	data->GPSVelocity.V_north= latitudeLognitudeAltitude.c0;
	data->GPSVelocity.V_east = latitudeLognitudeAltitude.c1;
	data->GPSVelocity.V_down = latitudeLognitudeAltitude.c2;
}

void CloseIMU()
{
	int errorCode = vn200_disconnect(&vn200);
	if (errorCode != VNERR_NO_ERROR) {
		printf("Error encountered when trying to disconnect from the sensor.\n");
	}
}
