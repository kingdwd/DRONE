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
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <assert.h>
#include "EKF_IFS_2.h"
#include "vectornav.h"
#include <errno.h>
#include <termios.h>

/**************************************************************************
 * Public Definitions
 **************************************************************************/
#define VECTORNAV_COM "/dev/ttyUSB0"
#define VN_BAUDRATE B9600    /*rate for IMU*/

#define ARDUINO_COM "/dev/ttyACM0"
#define AR_BAUDRATE B115200  /*rate for usb serial*/

#define PDEBUG(lvl, fmt, ...)						\
	do { if (g_debug_level > lvl) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

#define BUF_SIZE 80
/**************************************************************************
 * Public Types
 **************************************************************************/

/**************************************************************************
 * Global Variables
 **************************************************************************/
static Vn200 vn200;
int tty_fd;
int g_debug_level = 1;

/**************************************************************************
 * Public Function Prototypes
 **************************************************************************/
void InitIMU(void)
{
	VN_ERROR_CODE errorCode;
	errorCode = vn200_connect(&vn200, VECTORNAV_COM, VN_BAUDRATE);

	/* Make sure the user has permission to use the COM port. */
	if (errorCode == VNERR_PERMISSION_DENIED) {
		printf("Current user does not have permission to open the COM port.\n");
		printf("Try running again using 'sudo'.\n");
	} else if (errorCode != VNERR_NO_ERROR) {
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

void InitSerial()
{
	int i;
	struct termios tio;

	if((tty_fd = open(ARDUINO_COM , O_RDWR | O_NOCTTY)) < 0 ) { 
		perror("Error while opening serial port\n"); 
		exit(-11);
	}

	memset(&tio, 0, sizeof(tio));

	tio.c_iflag = IGNPAR | ICRNL;
	tio.c_cflag = AR_BAUDRATE | CS8 | CREAD | CLOCAL;
	tio.c_oflag = 0; 
	tio.c_lflag = ICANON; 
	tio.c_cc[VMIN] = 1; 
	tio.c_cc[VTIME] = 0; 

	tcflush(tty_fd, TCIFLUSH);
	tcsetattr(tty_fd, TCSANOW, &tio); 
	tcsetattr(tty_fd,TCSAFLUSH,&tio);  

	/* handshake */
	char buf[BUF_SIZE];
	WriteLine(tty_fd, "INIT\n");
	ReadLine(tty_fd, buf);
	PDEBUG(0, "Recv %s", buf);
}


int ReadN(int fd, char *buf, int len)
{
	int recv = 0;
	while (recv < len) {
		int tmp = read(fd, buf + recv, len - recv);
		recv += tmp;
	} 
	return recv;
}

int WriteLine(int fd, char *buf)
{
	int len  = strlen(buf);
	int tmp;
	tmp = write(tty_fd, buf, len);
	PDEBUG(0, "Send %s", buf);
	assert(tmp == len);
	return tmp;
}

int ReadLine(int fd, char *buf)
{
	int recv = 0;
	int tmp = 0; 
	while (read(fd, buf + recv, 1)) {
		recv++;
		if (buf[recv-1] == '\n')
			break;
	}
	return recv;
}

void GetSerialData(ExtU_EKF_IFS_2_T *data)
{
	int len;
	char buf[BUF_SIZE];

	WriteLine(tty_fd, "GETRC\n");
	ReadLine(tty_fd, buf);
	PDEBUG(0, "%s", buf);

	/* 6 RC values:
	   data->HomeCmd
	   data->ServoCommands.throttle_cmd
	   data->ServoCommands.elevator_cmd
	   data->ServoCommands.aileron_cmd
	   data->ServoCommands.rudder_cmd
	   data->VTalphabetameas.VT
	*/
}

void SendSerialData(ExtY_EKF_IFS_2_T *data)
{
	int ret;
	char buf[BUF_SIZE];
	/* 
	   this function is to send the control command output 
	   to the Arduino for output to the control surfaces 
	   The Arduino decides if we use conrtoller commands or 
	   rc commands based on the RC input of PIC/CIC line 

	   ch[0] = (int16_t)data->ControlSurfaceCommands.throttle_cmd;
	   ch[1] = (int16_t)data->ControlSurfaceCommands.elevator_cmd;
	   ch[2] = (int16_t)data->ControlSurfaceCommands.aileron_cmd;
	   ch[3] = (int16_t)data->ControlSurfaceCommands.rudder_cmd;
	*/

	WriteLine(tty_fd, "OUTPUT\n");
	WriteLine(tty_fd, "1 2 3 4\n");
}

void CloseSerial()
{
	close(tty_fd); 
}
