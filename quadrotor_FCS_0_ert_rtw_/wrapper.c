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
#include "../quadrotor_FCS_0.h"
#include "vectornav.h"
//#include "packet.h"
#include <errno.h>
#include <termios.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <time.h>
#include <arpa/inet.h>

#include <mavlink.h>

#include<stdint.h>
/**************************************************************************
 * Public Definitions
 **************************************************************************/
const char* const COM_PORT = "//dev//ttyUSB0";
const int VN_BAUDRATE = 115200;

#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

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
#define sock  socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)
struct sockaddr_in gcAddr; 
struct sockaddr_in locAddr;
ssize_t recsize;
socklen_t fromlen;
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

void GetIMUData(ExtU_quadrotor_FCS_0_T *data)
{
	
	VnVector3 ypr, latitudeLognitudeAltitude, Velocity, accel, angularRate;
	
    
	vn200_getInsStateLla(
		&vn200,
		&ypr,
		&latitudeLognitudeAltitude,
		&Velocity,
		&accel,
		&angularRate);
        data->lla[0] = latitudeLognitudeAltitude.c0;
	data->lla[1] = latitudeLognitudeAltitude.c1;
	data->lla[2] = latitudeLognitudeAltitude.c2;
    printf("GPS VELOCITY: %f %f %f\n", Velocity.c0, Velocity.c1, Velocity.c2);
	data->Internalstates[0]= Velocity.c0;
	data->Internalstates[1] = Velocity.c1;
	data->Internalstates[2] = Velocity.c2;
    printf("ypr (or) Euler angles: %f %f %f\n", ypr.c0, ypr.c1, ypr.c2);
        data->Internalstates[3]= ypr.c0;
	data->Internalstates[4]= ypr.c1;
	data->Internalstates[5]= ypr.c2;
	printf("Body rates: %f %f %f\n", angularRate.c0, angularRate.c1, angularRate.c2);
	data->Internalstates[6]= angularRate.c0;
	data->Internalstates[7]= angularRate.c1;
	data->Internalstates[8]= angularRate.c2;
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
	tio.c_cflag =  AR_BAUDRATE | CS8 | CREAD | CLOCAL;
	tio.c_oflag = 0; 
	tio.c_lflag = ICANON; 
	tio.c_cc[VMIN] = 1; 
	tio.c_cc[VTIME] = 0; 
        usleep(5000000);
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
        char target_ip[100];
        strcpy(target_ip, "10.0.0.32");
	memset(&locAddr, 0, sizeof(locAddr));
	locAddr.sin_family = AF_INET;
	locAddr.sin_addr.s_addr = INADDR_ANY;
	locAddr.sin_port = htons(14555);
	/* Bind the socket to port 14551 - necessary to receive packets from qgroundcontrol */ 
	if (-1 == bind(sock,(struct sockaddr *)&locAddr, sizeof(struct sockaddr)))
    {
		perror("error bind failed");
		//DEBUG
    }
	else 
    {
		printf("BOUND:\n");
    } 
	
	/* Attempt to make it non blocking */
	if (fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
    {
		fprintf(stderr, "error setting nonblocking: %s\n", strerror(errno));
		//DEBUG
		printf("BOUND:\n");
		//DEBUG
		close(sock);
		exit(EXIT_FAILURE);
    }
	
	
	memset(&gcAddr, 0, sizeof(gcAddr));
	gcAddr.sin_family = AF_INET;
	gcAddr.sin_addr.s_addr = inet_addr(target_ip);
	gcAddr.sin_port = htons(14550);
         
         
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

void GetSerialData(ExtU_quadrotor_FCS_0_T *data)
{
	int len;
	char buf[BUF_SIZE];

	WriteLine(tty_fd, "GETRC\n");
        
	while(!ReadLine(tty_fd, buf));
        sscanf(buf, "%f %f %f %f %f", 
		&data->RC[0], 
		&data->RC[1],
		&data->RC[2],
		&data->RC[3],
		&data->RC[4]
		); 
	PDEBUG(0, "%s", buf);
	printf("\n pwm are %f %f %f \n",data->RC[1],data->RC[2],data->RC[3]);
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

void SendSerialData (ExtY_quadrotor_FCS_0_T *data)
{
	int ret;
	char buf[BUF_SIZE],buf1[BUF_SIZE];
	
        sprintf(buf, "%f %f %f %f\n", 
		data-> Auto[0],
		data-> Auto[1],
		data-> Auto[2],
		data-> Auto[3]);
	WriteLine(tty_fd, "\rOUTPUT\n");
	WriteLine(tty_fd, buf);
        
}

void CloseSerial()
{
	close(tty_fd); 
}

/* QNX timer version */
#if (defined __QNX__) | (defined __QNXNTO__)
uint64_t microsSinceEpoch()
{
    
    struct timespec time;
    
    uint64_t micros = 0;
    
    clock_gettime(CLOCK_REALTIME, &time);
    micros = (uint64_t)time.tv_sec * 1000000 + time.tv_nsec/1000;
    
    return micros;
}
#else
uint64_t microsSinceEpoch()
{
    
    struct timeval tv;
    
    uint64_t micros = 0;
    
    gettimeofday(&tv, NULL);
    micros =  ((uint64_t)tv.tv_sec) * 1000000 + tv.tv_usec;
    
    return micros;
}
#endif
void Create_packets(ExtU_quadrotor_FCS_0_T *data)
{
    int bytes_sent;
    unsigned int temp = 0;
    int i;
    uint8_t buf[BUFFER_LENGTH];
    mavlink_message_t msg;
    uint16_t len;
    mavlink_msg_heartbeat_pack(3, 200, &msg, 2, 12, 65, 0, 3);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    int len1  = strlen(buf);
    bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
    mavlink_msg_attitude_pack(3, 200, &msg, microsSinceEpoch(),data->Internalstates[3], data->Internalstates[4], data->Internalstates[5], data->Internalstates[6], data->Internalstates[7], data->Internalstates[8]);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    len1  = strlen(buf);
    bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
    mavlink_msg_gps_raw_int_pack(3, 200, &msg, microsSinceEpoch(),2,390000000,-950000000,data->lla[2],UINT16_MAX,UINT16_MAX,UINT16_MAX,UINT16_MAX,255);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
    memset(buf, 0, BUFFER_LENGTH);
    
}

