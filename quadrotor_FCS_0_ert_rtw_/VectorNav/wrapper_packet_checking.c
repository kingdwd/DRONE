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
#include <arpa/inet.h> 
#include <string.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <assert.h>
#include "../EKF_IFS_2.h"
#include "vectornav.h"
//#include "packet.h"
#include <errno.h>
#include <termios.h>
#include<stdint.h>
#include <byteswap.h>
/**************************************************************************
 * Public Definitions
 **************************************************************************/
const char* const COM_PORT = "//dev//ttyUSB0";
const int VN_BAUDRATE = 115200;


#define ARDUINO_COM "/dev/ttyACM0"
#define AR_BAUDRATE B115200  /*rate for usb serial*/
#define MICROHARD_COM "/dev/ttyS0"
#define MH_BAUDRATE B115200  /*rate for usb serial*/

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
int tty_fd1;
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
       
        printf("GPS POSITION: %lf %lf %lf\n", latitudeLognitudeAltitude.c0, latitudeLognitudeAltitude.c1,    latitudeLognitudeAltitude.c2);        
	data->GPSPosition.Latitude = latitudeLognitudeAltitude.c0;
	data->GPSPosition.Longitude = latitudeLognitudeAltitude.c1;
	data->GPSPosition.Altitude = latitudeLognitudeAltitude.c2;
        printf("GPS VELOCITY: %f %f %f\n", Velocity.c0, Velocity.c1, Velocity.c2);
	data->GPSVelocity.V_north= Velocity.c0;
	data->GPSVelocity.V_east = Velocity.c1;
	data->GPSVelocity.V_down = Velocity.c2;
        printf("ypr (or) Euler angles: %f %f %f\n", ypr.c0, ypr.c1, ypr.c2);
        data->EulerAngles.phi= ypr.c0;
	data->EulerAngles.theta= ypr.c1;
	data->EulerAngles.psi= ypr.c2;
	printf("Body rates: %f %f %f\n", angularRate.c0, angularRate.c1, angularRate.c2);
	data->BodyRatesmeas.P= angularRate.c0;
	data->BodyRatesmeas.Q= angularRate.c1;
	data->BodyRatesmeas.R= angularRate.c2;
	printf("Accelerometer measurements: %f %f %f\n", accel.c0, accel.c1, accel.c2);
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
        usleep(4000000);
	tcflush(tty_fd, TCIFLUSH);
	tcsetattr(tty_fd, TCSANOW, &tio); 
	tcsetattr(tty_fd,TCSAFLUSH,&tio);  
	/* handshake */
	char buf[BUF_SIZE];
	WriteLine(tty_fd, "INIT\n");
	while(!ReadLine(tty_fd, buf));
	PDEBUG(0, "Recv %s", buf);
	
}
void InitMicroHard()
{
        int i;
	struct termios tio1;

	if((tty_fd1 = open(MICROHARD_COM , O_RDWR | O_NOCTTY)) < 0 ) { 
		perror("Error while opening RS232 port\n"); 
		exit(-11);
	}

	memset(&tio1, 0, sizeof(tio1));

	tio1.c_iflag = IGNPAR | ICRNL;
	tio1.c_cflag = MH_BAUDRATE | CS8 | CREAD | CLOCAL;
	tio1.c_oflag = 0; 
	tio1.c_lflag = ICANON; 
	tio1.c_cc[VMIN] = 1; 
	tio1.c_cc[VTIME] = 0; 

	tcflush(tty_fd1, TCIFLUSH);
	tcsetattr(tty_fd1, TCSANOW, &tio1); 
	tcsetattr(tty_fd1,TCSAFLUSH,&tio1);  
        Create_packets(&EKF_IFS_2_U);	 
}
void CloseMicroHard()
{
	close(tty_fd1); 
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
        
	while(!ReadLine(tty_fd, buf))WriteLine(tty_fd, "GETRC\n");
        sscanf(buf, "1 1 %f %f %f %f %d", 
		&data->PICCIC, 
		&data->HomeCmd,
		&data->RC.throttle_cmd, /* float? */
		&data->RC.elevator_cmd,  /*float? */
		&data->RC.aileron_cmd,  /* float? */
		&data->RC.rudder_cmd,   /* float? */
		&data->VTalphabetameas.VT); 
	PDEBUG(0, "%s", buf);
  //printf("\n The input pwm signals are %d %d %f %f %f %f  :", data->PICCIC, data->HomeCmd, data->ServoCommands.throttle_cmd, data->ServoCommands.elevator_cmd,  data->ServoCommands.aileron_cmd, data->ServoCommands.rudder_cmd);

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
void Create_packets(ExtU_EKF_IFS_2_T *data)
{	header packet1;
	pdata  packet2;
	checksum packet3;
	char sum[168] ;
	//sum[169]=0;
	
	packet1.a = 'A';
	packet1.p = 'P';
	packet1.d = 'D';
	packet1.s = 'S';
	packet2.MPCClockCount = __bswap_32 (0);
	packet2.CycleCount = __bswap_32 (0);
	packet2.DistancetoWaypoint = __bswap_32 (0);	
	packet2.WaypointIndex =  0;
	packet2.WaypointUploadStatus = 0;
	packet2.SPIStatus = 0;
	packet2.UpPacketCnt =0;
	packet2.NAVstatus = 0;
	packet2.RadarCommand = 0;
	packet2.RadarStatus =0;
	packet2.EtaLat = __bswap_64 (0);
	packet2.EtaLon = __bswap_64 (0);
	packet2.VTCommandState =  __bswap_32 (0);
	packet2.ThetaCommandState =  __bswap_32 (0);
	packet2.PhiCommandState =  __bswap_32 (0);
	packet2.HomeCommand =  __bswap_32 (0);
	packet2.DebugSwEn = 0;
	packet2.DebugCalibration = 0;
	packet2.SPVT = __bswap_32 (0);
	packet2.SPAlpha = 134;
	packet2.SPBeta = __bswap_32 (0);
	packet2.SPNovaPosType = 0;
	packet2.SPNovaSolType =0;
	packet2.SPNovaNumSats =  0;
	packet2.SPVT2 =__bswap_32 (0);

	packet2.PIC_CIC            = (uint8_t)data->PICCIC;
	packet2.PilotThrottle      = __bswap_32((float)data->RC.throttle_cmd);
	packet2.PilotElevatorRad   = __bswap_32((float)data->RC.elevator_cmd);
	packet2.PilotAileronRad    = __bswap_32((float)data->RC.aileron_cmd);
	packet2.PilotRudderRad     = __bswap_32((float)data->RC.rudder_cmd);
	packet2.IFSThrottleCmd     = __bswap_32((float)data->ServoCommands.throttle_cmd);
	packet2.IFSElevatorCmd     = __bswap_32((float)data->ServoCommands.elevator_cmd);
	packet2.IFSAileronCmd      = __bswap_32((float)data->ServoCommands.aileron_cmd);
	packet2.IFSRudderCmd       = __bswap_32((float)data->ServoCommands.rudder_cmd);
	packet2.SPLatitude         = __bswap_64(data->GPSPosition.Latitude);
	packet2.SPLongitude        = __bswap_64(data->GPSPosition.Longitude);	
	packet2.SPAltitude         = __bswap_64(data->GPSPosition.Altitude);
	printf("\n\n the lat and lon and alt is %f %f %f ",packet2.SPLatitude,packet2.SPLongitude,packet2.SPAltitude);
	packet2.SPVnorth	   = __bswap_32((float)data->GPSVelocity.V_north);	
	packet2.SPVeast	           = __bswap_32((float)data->GPSVelocity.V_east);
	packet2.SPVdown	           = __bswap_32((float)data->GPSVelocity.V_down);
	printf("\n\n the north and east and down is %f %f %f ",packet2.SPVnorth,packet2.SPVeast,packet2.SPVdown	);
	packet2.SPPhi   	   = __bswap_32((float)data->EulerAngles.phi);
	packet2.SPTheta   	   = __bswap_32((float)data->EulerAngles.theta);
	packet2.SPPsi   	   = __bswap_32((float)data->EulerAngles.psi);
	packet2.SPP		   = __bswap_32((float)data->BodyRatesmeas.P);
	packet2.SPQ		   = __bswap_32((float)data->BodyRatesmeas.Q);
	packet2.SPR		   = __bswap_32((float)data->BodyRatesmeas.R);
	packet3.checksums	   = 0;
	memcpy(sum+0,  &packet1.a, 1);
	memcpy(sum+1,  &packet1.p, 1);	
	memcpy(sum+2,  &packet1.d, 1);
	memcpy(sum+3,  &packet1.s, 1);
	memcpy(sum+4,  &packet2.MPCClockCount, 4);
	memcpy(sum+8,  &packet2.CycleCount, 4);
	memcpy(sum+12, &packet2.DistancetoWaypoint, 4);
	memcpy(sum+16, &packet2.WaypointIndex, 1);	
	memcpy(sum+17, &packet2.WaypointUploadStatus, 1);
	memcpy(sum+18, &packet2.PIC_CIC, 1);
	memcpy(sum+19, &packet2.PilotThrottle, 4);
	memcpy(sum+23, &packet2.PilotElevatorRad, 4);
	memcpy(sum+27, &packet2.PilotAileronRad, 4);
	memcpy(sum+31, &packet2.PilotRudderRad, 4);
	memcpy(sum+35, &packet2.SPIStatus, 1);
	memcpy(sum+36, &packet2.UpPacketCnt, 1);
	memcpy(sum+37, &packet2.NAVstatus, 1);
	memcpy(sum+38, &packet2.RadarCommand, 1);
	memcpy(sum+39, &packet2.RadarStatus, 1);
	memcpy(sum+40, &packet2.EtaLat, 8);	
	memcpy(sum+48, &packet2.EtaLon, 8);
	memcpy(sum+56, &packet2.VTCommandState, 4);
	memcpy(sum+60, &packet2.ThetaCommandState, 4);
	memcpy(sum+64, &packet2.PhiCommandState, 4);
	memcpy(sum+68, &packet2.HomeCommand, 1);
	memcpy(sum+69, &packet2.DebugSwEn, 1);
	//memcpy(sum+70, &packet2.DebugCalibration, 1);
	memcpy(sum+70, &packet2.IFSThrottleCmd, 4);
	memcpy(sum+74, &packet2.IFSElevatorCmd, 4);
	memcpy(sum+78, &packet2.IFSAileronCmd, 4);
	memcpy(sum+82, &packet2.IFSRudderCmd, 4);
	memcpy(sum+86,&packet2.SPLatitude, 8);
	memcpy(sum+94,&packet2.SPLongitude, 8);
	memcpy(sum+102,&packet2.SPAltitude, 8);
	memcpy(sum+110,&packet2.SPVnorth, 4);
//	printf("the velocity in bytes are %d%d%d%d",sum[114],sum[115],sum[116],sum[117]);
	memcpy(sum+114,&packet2.SPVeast, 4);
//	printf("\n\nthe east velocity in bytes are %d%d%d%d",sum[118],sum[119],sum[120],sum[121]);
	memcpy(sum+118,&packet2.SPVdown, 4);
	memcpy(sum+122,&packet2.SPPhi, 4);
	memcpy(sum+126,&packet2.SPTheta, 4);
	memcpy(sum+130,&packet2.SPPsi, 4);
	memcpy(sum+134,&packet2.SPVT, 4);
	char b[4];
	memcpy(b+0,&packet2.SPAlpha, 4);
	b=strrev(b);
	strncpy(sum+138,b, 4);
//	memcpy(sum+138,&b[3], 1);
//	memcpy(sum+139,&b[2], 1);
//	memcpy(sum+140,&b[1], 1);
//	memcpy(sum+141,&b[0], 1);
//	memcpy(sum+138,&packet2.SPAlpha, 4);
	memcpy(b+0,&packet2.SPBeta, 4);
	memcpy(sum+142,&b[3], 1);
	memcpy(sum+143,&b[2], 1);
	memcpy(sum+144,&b[1], 1);
	memcpy(sum+145,&b[0], 1);
//	memcpy(sum+142,&packet2.SPBeta, 4);
	memcpy(sum+146,&packet2.SPP, 4);
	memcpy(b+0,&packet2.SPP, 4);
	memcpy(sum+142,&b[3], 1);
	memcpy(sum+143,&b[2], 1);
	memcpy(sum+144,&b[1], 1);
	memcpy(sum+145,&b[0], 1);
	memcpy(sum+150,&packet2.SPQ, 4);
	memcpy(sum+154,&packet2.SPR, 4);
	memcpy(sum+158,&packet2.SPNovaPosType, 1);
	memcpy(sum+159,&packet2.SPNovaSolType, 1);
	memcpy(sum+160,&packet2.SPNovaNumSats, 1);
	memcpy(sum+161,&packet2.SPVT2, 4);	
	int index=2;
	for(index;index<165;index++)
	packet3.checksums += (uint16_t)sum[index];
	printf("\n\nChecksum : %d\n\n",packet3.checksums);
	packet3.checksums =__bswap_16(packet3.checksums);
	int e=0;
	printf("\n\nPacket checking   ");
//	uint8_t b[2];
	memcpy(sum+165, &packet3.checksums, 2);
//	memcpy(b+0, &packet3.checksums, 2);
//	memcpy(sum+165, &b[1], 1);
//	memcpy(sum+166, &b[0], 1);
	for(e;e<167;e++)
	printf("\t%d",sum[e]);
//	b=packet3.checksums;
	int size;
        size =sizeof(sum);
	printf("\n\n the sum size is %d",size);
//	sum = hton(sum);
//	printf("\n\nthe checksum length is%d \n\n ",q);
	write(tty_fd1,sum, 167);
	printf("\n\nthe recent values are %d",sum[168]);
//	write(STDOUT_FILENO,sum, 167);
	printf("\nGround Station's data :%s\n\r", sum);
	
//	printf("\n\nChecksum 1: %d\n\n",b);
}


