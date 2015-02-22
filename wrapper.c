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
#include "../EKF_IFS_2.h"
#include "vectornav.h"
#include <errno.h>
#include <termios.h>

/**************************************************************************
 * Public Definitions
 **************************************************************************/
const char* const COM_PORT = "//dev//ttyUSB0";
#define MODEM "/dev/ttyACM0" 
#define BAUD_RATE B9600     /*rate for IMU*/
#define BAUDRATE B115200    /*rate for usb serial*/
/**************************************************************************
 * Public Types
 **************************************************************************/

/**************************************************************************
 * Global Variables
 **************************************************************************/
static Vn200 vn200;
struct termios tio; 
struct termios stdio; 
struct termios old_stdio; 
int tty_fd, flags; 
unsigned char c='D'; 
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

void InitSerial()
{
	int i;
	
	tcgetattr(STDOUT_FILENO,&old_stdio); 
	memset(&stdio,0,sizeof(stdio)); 
	stdio.c_iflag=0; 
	stdio.c_oflag=0; 
	stdio.c_cflag=0; 
	stdio.c_lflag=0; 
	stdio.c_cc[VMIN]=1; 
	stdio.c_cc[VTIME]=0; 
	tcsetattr(STDOUT_FILENO,TCSANOW,&stdio); 
	tcsetattr(STDOUT_FILENO,TCSAFLUSH,&stdio); 
	fcntl(STDIN_FILENO, F_SETFL,O_NONBLOCK);       /*/ make the reads non-blocking changed from O_NONBLOCK*/
	memset(&tio,0,sizeof(tio)); 
	tio.c_iflag=0; 
	tio.c_oflag=0; 
	tio.c_cflag=CS8|CREAD|CLOCAL;            
	tio.c_lflag=0; 
	tio.c_cc[VMIN]=1; 
	tio.c_cc[VTIME]=5; 
	if((tty_fd = open(MODEM , O_RDWR | O_NONBLOCK )) == -1){ 
	printf("Error while opening serial port\n"); /*/ Just if you want user interface error control */
	return -1; 
	} 
	cfsetospeed(&tio,BAUDRATE);     
	cfsetispeed(&tio,BAUDRATE);            /*/ baudrate is declarated above */
	tcsetattr(tty_fd,TCSANOW,&tio); 
	tcsetattr(tty_fd,TCSAFLUSH,&tio);  
	/*receive "Ping" and print to terminal */
	printf("\n receive ping: \n"); 
	
	for (i=0; i<4; i++)
	{
		if (read(tty_fd,&c,1)>0){ 
		    write(STDOUT_FILENO,&c,1); /*/ if new data is available on the serial port, print it out */	
		}	
	}

	/* need to send a byte of data to establish bi-directional comms - this puts Arduino from Ping mode to sample mode*/
	
	/* NOTE - THIS WORKS FROM COMMAND LINE INTERFACE WITH ARDUINO BUT NOT THIS PROGRAM - IT'S LIKE THE NEWLINE CHARACTER IS NOT BEING RECOGNIZED LIKE THE 'RETURN' CHARACTER FROM THE TERMINAL */
	
}


void GetSerialData(ExtU_EKF_IFS_2_T *data)
{
	int i;	
	char input_buf[4];

	printf("in get serial data\n");

	/*/ 6 rc input values and vt ARE MEASURED ON THE ARDUINO - WE NEED THEM */
	/* GET 4 BYTES - PER INPUT VALUE */
	
	for (i=0; i<4; i++)
	{
		if (read(tty_fd,&c,1)>0){ 
		    write(STDOUT_FILENO,&c,1); /*/ if new data is available on the serial port, print it out */	
		    write(input_buf[i],&c,1);
		}	
	}
	/*this should be cast to a bool */
	data->PICCIC = (bool)input_buf;
	
	for (i=0; i<4; i++)
	{
		if (read(tty_fd,&c,1)>0){ 
		    write(STDOUT_FILENO,&c,1); /*/ if new data is available on the serial port, print it out */	
		    write(input_buf[i],&c,1);
		}	
	}
	/*this should be cast to a bool */
	data->HomeCmd = (bool)input_buf;
	
	for (i=0; i<4; i++)
	{
		if (read(tty_fd,&c,1)>0){ 
		    write(STDOUT_FILENO,&c,1); /*/ if new data is available on the serial port, print it out */	
		    write(input_buf[i],&c,1);
		}	
	}
	data->ServoCommands.throttle_cmd = atof(input_buf);
	for (i=0; i<4; i++)
	{
		if (read(tty_fd,&c,1)>0){ 
		    write(STDOUT_FILENO,&c,1); /*/ if new data is available on the serial port, print it out */	
		    write(input_buf[i],&c,1);
		}	
	}
	data->ServoCommands.elevator_cmd = atof(input_buf);
	for (i=0; i<4; i++)
	{
		if (read(tty_fd,&c,1)>0){ 
		    write(STDOUT_FILENO,&c,1); /*/ if new data is available on the serial port, print it out */	
		    write(input_buf[i],&c,1);
		}	
	}
	data->ServoCommands.aileron_cmd = atof(input_buf);
	for (i=0; i<4; i++)
	{
		if (read(tty_fd,&c,1)>0){ 
		    write(STDOUT_FILENO,&c,1); /*/ if new data is available on the serial port, print it out */	
		    write(input_buf[i],&c,1);
		}	
	}
	data->ServoCommands.rudder_cmd = atof(input_buf);
	for (i=0; i<4; i++)
	{
		if (read(tty_fd,&c,1)>0){ 
		    write(STDOUT_FILENO,&c,1); /*/ if new data is available on the serial port, print it out */	
		    write(input_buf[i],&c,1);
		}	
	}
	data->VTalphabetameas.VT = atof(input_buf);
	

}

void SendSerialData(ExtY_EKF_IFS_2_T *data)
{
	/* this function is to send the control command output 
	to the Arduino for output to the control surfaces 
	The Arduino decides if we use conrtoller commands or 
	rc commands based on the RC input of PIC/CIC line */

	
	int x;
		
	/* this is building a space deliminated string of 4 - 4 byte numbers
		this is how I would enter the data via the command line:
		>0.00 0.00 0.00 0.00  */
	int i;	
	double input_buf[4];
	input_buf[0]=data->ControlSurfaceCommands.throttle_cmd;
	input_buf[1]=data->ControlSurfaceCommands.elevator_cmd;
	input_buf[2]=data->ControlSurfaceCommands.aileron_cmd;
 	input_buf[3]=data->ControlSurfaceCommands.rudder_cmd;

	
	printf("in get serial data\n");

	/*/ 6 rc input values and vt ARE MEASURED ON THE ARDUINO - WE NEED THEM */
	/* GET 4 BYTES - PER INPUT VALUE */
  	
	for (i=0; i<4; i++)
	{
    c=input_buf[i];
		 
		while (write(tty_fd,&c,1)>0)/*/ if new data is available on the serial port, print it out */	
		   printf("\n data is being sent");
		}	
	
	
	
}

void CloseSerial()
{
	close(tty_fd); 
	tcsetattr(STDOUT_FILENO,TCSAFLUSH,&old_stdio); 
}
