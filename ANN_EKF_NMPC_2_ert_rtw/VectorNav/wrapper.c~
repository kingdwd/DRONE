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
#include "../ANN_EKF_NMPC_2.h"
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
#include "vn200.h"
#include "vn_errorCodes.h"
#include <mavlink.h>

/**************************************************************************
 * Public Definitions
 **************************************************************************/
const char* const COM_PORT = "//dev//ttyUSB0";
const int VN_BAUDRATE = 115200;


#define ARDUINO_COM "/dev/ttyACM0"
#define AR_BAUDRATE B115200  /*rate for usb serial*/

#define PDEBUG(lvl, fmt, ...)						\
	do { if (g_debug_level > lvl) fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)
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
struct sockaddr_in gcAddr; 
struct sockaddr_in locAddr;
ssize_t recsize,recsize1;
socklen_t fromlen;
//#define sock socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)
/**************************************************************************
 * Public Function Prototypes
 **************************************************************************/

void InitIMU(void)
{       struct timespec start, end;double interval_sec = (double)1/20;
	VN_ERROR_CODE errorCode;
	clock_gettime(CLOCK_REALTIME, &start);
	errorCode = vn200_connect(&vn200, COM_PORT, VN_BAUDRATE);
	clock_gettime(CLOCK_REALTIME, &end);
	uint64_t tmpdiff;
	double remain_us;
	tmpdiff = get_elapsed(&start, &end);
	remain_us = (interval_sec * 1000000 - tmpdiff / 1000);
	printf("\nVectornav initialization took %llu  us\n", tmpdiff/1000);

	/* Make sure the user has permission to use the COM port. */
	if (errorCode == VNERR_PERMISSION_DENIED) {
		printf("Current user does not have permission to open the COM port.\n");
		printf("Try running again using 'sudo'.\n");
	} else if (errorCode != VNERR_NO_ERROR) {
		printf("%d Error encountered when trying to connect to the sensor.\n",errorCode);
	}
        printf("%d\n",errorCode);
}
VN_ERROR_CODE vn200_getInsStateLla(
	Vn200* vn200,
	VnVector3* ypr,
	VnVector3* lla,
	VnVector3* velocity,
	VnVector3* accel,
	VnVector3* angularRate)
{
	struct timespec start, end;double interval_sec = (double)1/20;
	const char* cmdToSend = "$VNRRG,72";
	char delims[] = ",*";
	char* result;
	int errorCode;
	const char* responseMatch = "VNRRG,";

	if (!vn200->isConnected)
		return VNERR_NOT_CONNECTED;
	clock_gettime(CLOCK_REALTIME, &start);
	errorCode = vndevice_transaction(&vn200->vndevice, cmdToSend, responseMatch);
	clock_gettime(CLOCK_REALTIME, &end);
	uint64_t tmpdiff;
	double remain_us;
	tmpdiff = get_elapsed(&start, &end);
	remain_us = (interval_sec * 1000000 - tmpdiff / 1000);
	printf("\nVectornav vndevice_transaction took %llu  us\n", tmpdiff/1000);
	if (errorCode != VNERR_NO_ERROR)
		return errorCode;

	result = strtok(vndevice_getResponseBuffer(&vn200->vndevice), delims);  /* Returns VNRRG */
	result = strtok(0, delims);                            /* Returns register ID */
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	ypr->c0 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	ypr->c1 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	ypr->c2 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	lla->c0 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	lla->c1 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	lla->c2 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	velocity->c0 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	velocity->c1 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	velocity->c2 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	accel->c0 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	accel->c1 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	accel->c2 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	angularRate->c0 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	angularRate->c1 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;
	angularRate->c2 = atof(result);
	result = strtok(0, delims);
	if (result == NULL)
		return VNERR_INVALID_VALUE;

	return VNERR_NO_ERROR;
}
void GetIMUData(ExtU_ANN_EKF_NMPC_2_T *data)
{
	VnVector3 ypr, latitudeLognitudeAltitude, Velocity, accel, angularRate;
	struct timespec start, end;double interval_sec = (double)1/20;
        clock_gettime(CLOCK_REALTIME, &start);
	vn200_getInsStateLla(
		&vn200,
		&ypr,
		&latitudeLognitudeAltitude,
		&Velocity,
		&accel,
		&angularRate);
        clock_gettime(CLOCK_REALTIME, &end);
	uint64_t tmpdiff;
	double remain_us;
	tmpdiff = get_elapsed(&start, &end);
	remain_us = (interval_sec * 1000000 - tmpdiff / 1000);
	printf("\nVectornav function call took %llu  us\n", tmpdiff/1000);
        //printf("GPS POSITION: %lf %lf %lf\n", latitudeLognitudeAltitude.c0, latitudeLognitudeAltitude.c1,    latitudeLognitudeAltitude.c2);        
	data->GPSPositionmeas.Latitude = latitudeLognitudeAltitude.c0;
	data->GPSPositionmeas.Longitude = latitudeLognitudeAltitude.c1;
	data->GPSPositionmeas.Altitude = latitudeLognitudeAltitude.c2;
       // printf("GPS VELOCITY: %f %f %f\n", Velocity.c0, Velocity.c1, Velocity.c2);
	data->GPSVelocitymeas.V_north= Velocity.c0;
	data->GPSVelocitymeas.V_east = Velocity.c1;
	data->GPSVelocitymeas.V_down = Velocity.c2;
        printf("ypr (or) Euler angles: %f %f %f\n", ypr.c0, ypr.c1, ypr.c2);
        data->EulerAnglesmeas.phi= ypr.c0;
	data->EulerAnglesmeas.theta= ypr.c1;
	data->EulerAnglesmeas.psi= ypr.c2;
	//printf("Body rates: %f %f %f\n", angularRate.c0, angularRate.c1, angularRate.c2);
	data->BodyRatesmeas.P= angularRate.c0;
	data->BodyRatesmeas.Q= angularRate.c1;
	data->BodyRatesmeas.R= angularRate.c2;
	//printf("Accelerometer measurements: %f %f %f\n", accel.c0, accel.c1, accel.c2);
	//data->Accelerometermeas.Axb= accel.c0;
	//data->Accelerometermeas.Ayb= accel.c1;
	//data->Accelerometermeas.Azb= accel.c2;
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
  	usleep(2000000);
	tcflush(tty_fd, TCIFLUSH);
	tcsetattr(tty_fd, TCSANOW, &tio); 
	tcsetattr(tty_fd,TCSAFLUSH,&tio);  
	/* handshake */
	char buf[BUF_SIZE]; 
 	WriteLine(tty_fd, "INIT\n");
	while(!ReadLine(tty_fd, buf));
	PDEBUG(0, "Recv %s", buf);
}

int InitMicroHard()
{
	int sock=socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
        char target_ip[100];
        strcpy(target_ip, "192.168.0.5");
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
	if (fcntl(sock, F_SETFL) < 0)
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
        return sock;
        //close(sock);
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

void GetSerialData(ExtU_ANN_EKF_NMPC_2_T *data)
{
	int len;
	char buf[BUF_SIZE];

	WriteLine(tty_fd, "GETRC\n");
        
	while(!ReadLine(tty_fd, buf));
        sscanf(buf, "%d %d %f %f %f %f %d", 
		&data->PICCIC, 
		&data->HomeCmd,
		&data->RC.throttle_cmd, /* float? */
		&data->RC.elevator_cmd,  /*float? */
		&data->RC.aileron_cmd,  /* float? */
		&data->RC.rudder_cmd,   /* float? */
		&data->VTalphabetameas.VT); 
	PDEBUG(0, "%s", buf);
  printf("\n The input pwm signals are %d %d %f %f %f %f  :", &data->PICCIC, data->HomeCmd, data->RC.throttle_cmd, data->RC.elevator_cmd,  data->RC.aileron_cmd, data->RC.rudder_cmd);

	/* 6 RC values:
	   data->HomeCmd
	   data->ServoCommands.throttle_cmd
	   data->ServoCommands.elevator_cmd
	   data->ServoCommands.aileron_cmd
	   data->ServoCommands.rudder_cmd
	   data->VTalphabetameas.VT
	*/
}

void SendSerialData(ExtY_ANN_EKF_NMPC_2_T *data)
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
void InitMovingWaypoints(ExtU_ANN_EKF_NMPC_2_T *data)
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
/*void InitMovingWaypoints1(ExtU_NMPC_Controller_T *data)
{
	data->FL_ann = 0;
	data->c_ann_X = 0;
	data->c_ann_Y = 0;
	data->c_ann_Z = 0;
	int i;
	for(i=0; i<40; i++)
	{
		data->a_ann_X[i] = 0;
		data->b_ann_X[i] = 0;
		data->a_ann_Y[i] = 0;
		data->b_ann_Y[i] = 0;
		data->a_ann_Z[i] = 0;
		data->b_ann_Z[i] = 0;
	}
	for(i=0; i<280; i++)
	{
		data->w_ann_X[i]=0;
		data->w_ann_Y[i]=0;
		data->w_ann_Z[i]=0;
	}
}*/

void InitStaticWaypoints(ExtU_ANN_EKF_NMPC_2_T *data)
{
	/* eventually we might want the user (on ground station) to be prompted to 
	choose options: 1. a set of predefined waypoint tracks	
	2. user defined waypoint track where they enter the data by hand
	3. modify waypoint track where they load a pre-defined track then 
	manually adjust a subset of those */

	data->WaypointsIN.fp = 0;
	data->WaypointsIN.rp = 0;
	/* there is space for 32 waypoints */
	data->WaypointsIN.h[0] = 500;
	data->WaypointsIN.n[0] = 0;
	data->WaypointsIN.v[0] = 0;
	data->WaypointsIN.e[0] = 0;
		
}

void InitOther(ExtU_ANN_EKF_NMPC_2_T *data)
{
	//data->State_outputfeedbackselection = 0;
	data->EnableDisable = 1;
	data->Servodeflection[0] = 0;
	data->Servodeflection[1] = 0;
	data->Servodeflection[2] = 0;
	data->Servodeflection[3] = 0;
}
void GetOther(ExtU_ANN_EKF_NMPC_2_T *data)
{
	//data->State_outputfeedbackselection = 0;
	data->EnableDisable = 1;
	data->Servodeflection[0] = 0;
	data->Servodeflection[1] = 0;
	data->Servodeflection[2] = 0;
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
void Create_packets(ExtU_ANN_EKF_NMPC_2_T *data,int sock)
{   int i=0;
    int bytes_sent;
    uint8_t buf[BUFFER_LENGTH];
    uint8_t buf1[BUFFER_LENGTH];
    uint8_t buf2[BUFFER_LENGTH];
    mavlink_message_t msg,msg1,msg2;
    uint16_t len;
    mavlink_msg_heartbeat_pack(2, 200, &msg, 2, 12, 65, 0, 3);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    int len1  = strlen(buf);
     bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
    mavlink_msg_attitude_pack(2, 200, &msg, microsSinceEpoch(),data->EulerAnglesmeas.phi, data->EulerAnglesmeas.theta, data->EulerAnglesmeas.psi, data->BodyRatesmeas.P,data->BodyRatesmeas.Q, data->BodyRatesmeas.R);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    len1  = strlen(buf);
     bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
//    mavlink_msg_hil_state_pack(1, 200, &msg, microsSinceEpoch(),data->EulerAngles.phi, data->EulerAngles.theta, data->EulerAngles.psi, data->BodyRatesmeas.P, data->BodyRatesmeas.Q, data->BodyRatesmeas.R,data->GPSPosition.Latitude,data->GPSPosition.Longitude,data->GPSPosition.Altitude,0,0,0,data->Accelerometermeas.Axb,data->Accelerometermeas.Ayb,data->Accelerometermeas.Azb);
   // mavlink_msg_hil_state_pack(2, 200, &msg, microsSinceEpoch(),data->EulerAngles.phi, data->EulerAngles.theta, data->EulerAngles.psi, data->BodyRatesmeas.P, data->BodyRatesmeas.Q, data->BodyRatesmeas.R,39,-95,data->GPSPosition.Altitude,0,0,0,data->Accelerometermeas.Axb,data->Accelerometermeas.Ayb,data->Accelerometermeas.Azb);
    //len = mavlink_msg_to_send_buffer(buf, &msg);
  //  bytes_sent = write(tty_fd1,buf,len);
    mavlink_msg_gps_raw_int_pack(2, 200, &msg, microsSinceEpoch(),2,data->GPSPositionmeas.Latitude,data->GPSPositionmeas.Longitude,data->GPSPositionmeas.Altitude,UINT16_MAX,UINT16_MAX,UINT16_MAX,UINT16_MAX,255);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    bytes_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
    
		memset(buf, 0, BUFFER_LENGTH);
		//mavlink_message_t msg;
		mavlink_status_t status,status1;
		mavlink_mission_count_t mission_count;
		int cn;
		recsize = recvfrom(sock, (void *)buf, BUFFER_LENGTH, 0, (struct sockaddr *)&gcAddr, &fromlen);
		if (recsize > 0)
      	        {
			// Something received - print out all bytes and parse packet
			
			
			printf("Bytes Received: %d\nDatagram: ", (int)recsize);
			for (i = 0; i < recsize; ++i)
			{
				//temp = buf[i];
			//	printf("%02x ", (unsigned char)temp);
				if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status))
				{
					// Packet received
					printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);		
					printf("\n\n Incomming packet\n\n");
		if(msg.msgid ==  44)
		{				
			mavlink_msg_mission_count_decode( &msg, &mission_count);
			printf("\n\n the # of wypts received is %d########\n\n",mission_count.count);
			data->wcn=mission_count.count;
			for(cn=0;cn<data->wcn;cn++)
			{
				//sendrequest(sock,cn);
				memset(buf1, 0, BUFFER_LENGTH);
				mavlink_msg_mission_request_pack(2, 200, &msg1,255,0,cn);
				len = mavlink_msg_to_send_buffer(buf1, &msg1);
				bytes_sent = sendto(sock, buf1, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
				printf("\n\n @@@@@ sent successfull\n\n");
				memset(buf2, 0, BUFFER_LENGTH);
				//receive_waypoints(sock,cn);
				while( (recsize1 = recvfrom(sock, (void *)buf2, BUFFER_LENGTH, 0, (struct sockaddr *)&gcAddr, &fromlen)) <= 0);
	 if (recsize1 > 0)
	
      	{	
		int ii;
		mavlink_mission_item_t mission_item;		
	  	for (ii = 0; ii < recsize1; ++ii)
		{
			if (mavlink_parse_char(MAVLINK_COMM_0, buf2[ii], &msg2, &status1))
			{
				printf("\n\n reading waypoint # %d",cn);
			}
		}//if (msg2.msgid==0)
			//goto loop;
		if(msg2.msgid ==  39)
		{
			mavlink_msg_mission_item_decode(&msg2, &mission_item);
			printf("\n\nthe waypoint # %d is lat:%f lon:%f alt:%f",cn,mission_item.x,mission_item.y,mission_item.z);
			data->WaypointsIN.n[cn]=mission_item.x;
			data->WaypointsIN.h[cn] =mission_item.z;
			data->WaypointsIN.v[cn] = mission_item.y;
		}
	}else printf("!!!!!!!!\n\n receiving failed \n\n "); 
			}
			if(cn == mission_count.count)
			{
				//sendack(sock,cn);
				mavlink_msg_mission_ack_pack(2, 200, &msg2,255,0,0);
				memset(buf2, 0, BUFFER_LENGTH);
				len = mavlink_msg_to_send_buffer(buf2, &msg2);
				bytes_sent = sendto(sock, buf2, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
				printf("\n\n ***** sent acknowledgement *****\n\n");
			} 		
		}        // for msg id 44
		if(msg.msgid ==  43)
		{       
			int j=0; 
			
			//sendcn(sock,cn);
			mavlink_msg_mission_count_pack(2, 200, &msg2,255,0,data->wcn);
			memset(buf2, 0, BUFFER_LENGTH);
			len = mavlink_msg_to_send_buffer(buf2, &msg2);
			bytes_sent = sendto(sock, buf2, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
			memset(buf2, 0, BUFFER_LENGTH);
			for(j=0; j<data->wcn;j++)
			{
				//receive_request(sock);
				//sendwyp(sock,-95,95);
				mavlink_msg_mission_item_pack(2, 200, &msg2,255,0,j,0,16,0,1,.149999999999999994,0,0,0,data->WaypointsIN.n[j],data->WaypointsIN.v[j],data->WaypointsIN.h[j]);
				len = mavlink_msg_to_send_buffer(buf2, &msg2);
				bytes_sent = sendto(sock, buf2, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
				printf("\n\n @@@@@ sent count successfull\n\n");
			}
			//rec_ack(sock);
		}// for msg id 43
		}	//parse - if
				}//for
			}else printf("\n\n 12121212not good");//recsize - if
		//	printf("\n");
		
		//memset(buf, 0, BUFFER_LENGTH);
		
		printf("\n\n !!!@@##$$ end of a loop\n\n");




}//for Createpacket
    



