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
#include "../EKF_IFS_2.h"
#include "vectornav.h"
#include <errno.h>
#include <termios.h>

/**************************************************************************
 * Public Definitions
 **************************************************************************/
const char* const COM_PORT = "//dev//ttyUSB0";
const int VN_BAUDRATE = 115200;


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
	errorCode = vn200_connect(&vn200, COM_PORT, VN_BAUDRATE);

	/* Make sure the user has permission to use the COM port. */
	if (errorCode == VNERR_PERMISSION_DENIED) {
		printf("Current user does not have permission to open the COM port.\n");
		printf("Try running again using 'sudo'.\n");
	} else if (errorCode != VNERR_NO_ERROR) {
		printf("%d Error encountered when trying to connect to the sensor.\n",errorCode);
	}
        printf("%d\n",errorCode);
}

void GetIMUData(ExtU_EKF_IFS_2_T *data)
{
	
	VnVector3 ypr, latitudeLognitudeAltitude, Velocity, accel, angularRate;
	
    
	vn200_getInsStateLla(
		&vn200,
		&ypr,
		&latitudeLognitudeAltitude,
		&Velocity,
		&accel,
		&angularRate);
       
        //printf("GPS POSITION: %lf %lf %lf\n", latitudeLognitudeAltitude.c0, latitudeLognitudeAltitude.c1,    latitudeLognitudeAltitude.c2);        
	data->GPSPosition.Latitude = latitudeLognitudeAltitude.c0;
	data->GPSPosition.Longitude = latitudeLognitudeAltitude.c1;
	data->GPSPosition.Altitude = latitudeLognitudeAltitude.c2;
       // printf("GPS VELOCITY: %f %f %f\n", Velocity.c0, Velocity.c1, Velocity.c2);
	data->GPSVelocity.V_north= Velocity.c0;
	data->GPSVelocity.V_east = Velocity.c1;
	data->GPSVelocity.V_down = Velocity.c2;
        printf("ypr (or) Euler angles: %f %f %f\n", ypr.c0, ypr.c1, ypr.c2);
        data->EulerAngles.phi= ypr.c0;
	data->EulerAngles.theta= ypr.c1;
	data->EulerAngles.psi= ypr.c2;
	//printf("Body rates: %f %f %f\n", angularRate.c0, angularRate.c1, angularRate.c2);
	data->BodyRatesmeas.P= angularRate.c0;
	data->BodyRatesmeas.Q= angularRate.c1;
	data->BodyRatesmeas.R= angularRate.c2;
	//printf("Accelerometer measurements: %f %f %f\n", accel.c0, accel.c1, accel.c2);
	data->Accelerometermeas.Axb= accel.c0;
	data->Accelerometermeas.Ayb= accel.c1;
	data->Accelerometermeas.Azb= accel.c2;
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
  usleep(3000000);
	tcflush(tty_fd, TCIFLUSH);
	tcsetattr(tty_fd, TCSANOW, &tio); 
	tcsetattr(tty_fd,TCSAFLUSH,&tio);  
	/* handshake */
	char buf[BUF_SIZE]; 
 // usleep(200000);

	WriteLine(tty_fd, "INIT\n");
 // usleep(5000000);
	while(!ReadLine(tty_fd, buf));
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
	int recv = 0,check=0;
	int tmp = 0; 
	while (check=read(fd, buf + recv, 1)) {
		recv++;
		if (buf[recv-1] == '\n')
			break;
	}
	return --recv;
}

void GetSerialData(ExtU_EKF_IFS_2_T *data)
{
	int len;
	char buf[BUF_SIZE];

	WriteLine(tty_fd, "GETRC\n");
        
	while(!ReadLine(tty_fd, buf));
        sscanf(buf, "1 1 %f %f %f %f %d", 
		&data->PICCIC, 
		&data->HomeCmd,
		&data->RC.throttle_cmd, /* float? */
		&data->RC.elevator_cmd,  /*float? */
		&data->RC.aileron_cmd,  /* float? */
		&data->RC.rudder_cmd,   /* float? */
		&data->VTalphabetameas.VT); 
	PDEBUG(0, "%s", buf);
  printf("\n The input pwm signals are %d %d %f %f %f %f  :", &data->PICCIC, data->HomeCmd, data->ServoCommands.throttle_cmd, data->ServoCommands.elevator_cmd,  data->ServoCommands.aileron_cmd, data->ServoCommands.rudder_cmd);

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
	char buf[BUF_SIZE],buf1[BUF_SIZE];
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
       
        sprintf(buf, "%f %f %f %f\n", 
		data->ControlSurfaceCommands.throttle_cmd, 
		data->ControlSurfaceCommands.elevator_cmd,
		data->ControlSurfaceCommands.aileron_cmd, 
		data->ControlSurfaceCommands.rudder_cmd);
	WriteLine(tty_fd, "OUTPUT\n");
	WriteLine(tty_fd, buf);
        WriteLine(tty_fd, "VERIFY\n");
        while(!ReadLine(tty_fd, buf1));
	PDEBUG(0, "%s", buf1);

}

void CloseSerial()
{
	close(tty_fd); 
}
void InitMovingWaypoints(ExtU_EKF_IFS_2_T *data)
{
	int i;
	for(i=0; i<22; i++)
	{
		data->n_op[i] = 0;
		data->e_op[i] = 0;
		data->h_op[i] = 0;
		data->vn_op[i] = 0;
		data->ve_op[i] = 0;
		data->vh_op[i] = 0;
	}
}

void InitStaticWaypoints(ExtU_EKF_IFS_2_T *data)
{
	/* eventually we might want the user (on ground station) to be prompted to 
	choose options: 1. a set of predefined waypoint tracks	
	2. user defined waypoint track where they enter the data by hand
	3. modify waypoint track where they load a pre-defined track then 
	manually adjust a subset of those */

	data->WaypointsIN.ref_lat = 0;
	data->WaypointsIN.ref_lon = 0;
	data->WaypointsIN.ref_alt = 500;/*500 feet*/
	data->WaypointsIN.fp = 0;
	data->WaypointsIN.rp = 0;
	/* there is space for 32 waypoints */
	data->WaypointsIN.h[0] = 500;
	data->WaypointsIN.n[0] = 0;
	data->WaypointsIN.v[0] = 0;
	data->WaypointsIN.cmd[0] = 0;
	/*params - 256*/
	data->WaypointsIN.params[0] = 0;
	data->WaypointsIN.fact_lat = 0;
	data->WaypointsIN.fact_lon = 0;	
}

void InitOther(ExtU_EKF_IFS_2_T *data)
{
	data->State_outputfeedbackselection = 0;
	data->EnableDisable = 1;
	data->Servodeflection[0] = 0;
	data->Servodeflection[1] = 0;
	data->Servodeflection[2] = 0;
	data->Servodeflection[3] = 0;
}
void GetOther(ExtU_EKF_IFS_2_T *data)
{
	data->State_outputfeedbackselection = 0;
	data->EnableDisable = 1;
	data->Servodeflection[0] = 0;
	data->Servodeflection[1] = 0;
	data->Servodeflection[2] = 0;
}


