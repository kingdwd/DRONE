/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'NMPC_Controller'.
 *
 * Model version                  : 1.654
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Mon Apr 27 19:38:57 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Emulation hardware selection:
 *    Differs from embedded hardware (Generic->MATLAB Host Computer)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/**************************************************************************
 * Conditional Compilation Options
 **************************************************************************/
#define DEBUG 1
#define SAVEFILE 1

/**************************************************************************
 * Included Files
 **************************************************************************/
#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include <time.h>
#include <unistd.h>
#include <inttypes.h>
#include <unistd.h>
#include <getopt.h>

#include "NMPC_Controller.h"                 /* Model's header file */
#include "rtwtypes.h"
#include "imu.h"

#include "rt_logging.h"
#define QUOTE1(name)                   #name
#define QUOTE(name)                    QUOTE1(name)              /* need to expand name */
#ifndef SAVEFILE
# define MATFILE2(file)                #file ".mat"
# define MATFILE1(file)                MATFILE2(file)
# define MATFILE                       MATFILE1(MODEL)
#else
# define MATFILE                       QUOTE(SAVEFILE)
#endif

/**************************************************************************
 * Public Definitions
 **************************************************************************/
#define PDEBUG(fmt, ...)						\
	do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

/**************************************************************************
 * Public Types
 **************************************************************************/

/**************************************************************************
 * Global Variables
 **************************************************************************/

/**************************************************************************
 * Public Function Prototypes
 **************************************************************************/
void usage(int argc, char *argv[])
{
	_exit(0);
}

uint64_t get_elapsed(struct timespec *start, struct timespec *end)
{
	uint64_t dur = (end->tv_sec * 1000000000 + end->tv_nsec) -
		(start->tv_sec * 1000000000 + start->tv_nsec);
	return dur;
}

int main(int argc, char *argv[])
{
	long iter, repeat = 0;
	double interval_sec = (double)1/20;
	struct timespec start, end;
	int opt,sock;
         /*
	 * get command line options 
	 */
	while ((opt = getopt(argc, argv, "i:h")) != -1) {
		switch (opt) {
		case 'i': /* iterations */
			repeat = strtol(optarg, NULL, 0);
			PDEBUG("repeat=%ld\n", repeat);
			break;
		case 'h':
			usage(argc, argv);
			break;
		}
	}

	/* Initialize model */
	NMPC_Controller_initialize();
	/* Get moving points Data */
        InitMovingWaypoints(&NMPC_Controller_U);
	InitMovingWaypoints1(&NMPC_Controller_U);
        /* Get waypoints Data */
        InitStaticWaypoints(&NMPC_Controller_U);
        /* Get Servo deflection Data */
        InitOther(&NMPC_Controller_U);
	/* Initialize hardware */
	InitIMU(); /* vectornav */

	InitSerial(); /* arduino */
	sock=InitMicroHard();
	clock_gettime(CLOCK_REALTIME, &start);
	iter =  0;
	while (1) {
		double remain_us;
		uint64_t tmpdiff;

		/* Get sensor data */
		GetIMUData(&NMPC_Controller_U);
		
		/* Get Arduino Data */
		GetSerialData(&NMPC_Controller_U); 

		/* Step the model */
		NMPC_Controller_step();

		/* Output to the motor controller */
		SendSerialData(&NMPC_Controller_Y); 
		 /* Send MicroHard */
		
		Create_packets(&NMPC_Controller_U,sock);	
		/* Time book keeping */
		clock_gettime(CLOCK_REALTIME, &end);
		tmpdiff = get_elapsed(&start, &end);
		remain_us = (interval_sec * 1000000 - tmpdiff / 1000);
		if (remain_us > 0) {
			usleep((useconds_t)remain_us);
		}
		clock_gettime(CLOCK_REALTIME, &start);

		iter++;
		PDEBUG("iter %ld took %" PRIu64 "us\n", iter, tmpdiff/1000);
		PDEBUG("Out: throttle=%f elevator=%f aileron=%f rudder=%f\n",
		       NMPC_Controller_Y.ControlSurfaceCommands.throttle_cmd,
		       NMPC_Controller_Y.ControlSurfaceCommands.elevator_cmd,
		       NMPC_Controller_Y.ControlSurfaceCommands.aileron_cmd,
		       NMPC_Controller_Y.ControlSurfaceCommands.rudder_cmd);
		
		if (iter >= repeat)
			break;
	}

	/* Matfile logging */
	rt_StopDataLogging(MATFILE, NMPC_Controller_M->rtwLogInfo);

	/* Terminate model */
	NMPC_Controller_terminate();
	/* Close hardware */
	CloseIMU();
	
	CloseSerial();
	return 0;
}
