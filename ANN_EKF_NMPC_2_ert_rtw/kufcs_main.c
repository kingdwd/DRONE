/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'ANN_EKF_NMPC_2'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Jun 16 09:17:13 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#define DEBUG 1
#define SAVEFILE 1

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "ANN_EKF_NMPC_2.h"            /* Model's header file */
#include "rtwtypes.h"
#include <time.h>
#include <unistd.h>
#include <inttypes.h>
#include <unistd.h>
#include <getopt.h>
#include "imu.h"
#include "rt_logging.h"

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
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

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustates how you do this relative to initializing the model.
 */
int main(int argc, char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);
  long iter, repeat = 0;
  double interval_sec = (double)1/20;
  struct timespec start, end;
  int opt,sock;
  char fname[128]="waypoints_conversion.txt";
  FILE *fp=fopen(fname,"w");
  fprintf(fp,"#,lat(in deg),lon(in deg),alt(from gs),north(feet),east(feet),height(feet),velocity\n");
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
  ANN_EKF_NMPC_2_initialize();
  /* Get moving points Data */
  InitMovingWaypoints(&ANN_EKF_NMPC_2_U);
  //InitMovingWaypoints1(&ANN_EKF_NMPC_2_U);
  /* Get waypoints Data */
  InitStaticWaypoints(&ANN_EKF_NMPC_2_U);
  /* Get Servo deflection Data */
  InitOther(&ANN_EKF_NMPC_2_U);
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
		GetIMUData(&ANN_EKF_NMPC_2_U);
		
		/* Get Arduino Data */
		GetSerialData(&ANN_EKF_NMPC_2_U); 
			
		/* Step the model */
		ANN_EKF_NMPC_2_step();
		/* Output to the motor controller */
		SendSerialData(&ANN_EKF_NMPC_2_Y); 
		 /* Send MicroHard */
		
		Create_packets(&ANN_EKF_NMPC_2_U,sock);	
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
		       ANN_EKF_NMPC_2_Y.ControlSurfaceCommands.throttle_cmd,
		       ANN_EKF_NMPC_2_Y.ControlSurfaceCommands.elevator_cmd,
		       ANN_EKF_NMPC_2_Y.ControlSurfaceCommands.aileron_cmd,
		       ANN_EKF_NMPC_2_Y.ControlSurfaceCommands.rudder_cmd);
		
		if (iter >= repeat)
			break;
	}

	/* Matfile logging */
	rt_StopDataLogging(MATFILE, ANN_EKF_NMPC_2_M->rtwLogInfo);

  /* Disable rt_OneStep() here */
  int cn=1;
  for(cn;cn<=ANN_EKF_NMPC_2_U.wcn;cn++)
  {
	fprintf(fp,"%d,%f,%f,%f,%f,%f,%f,%f\n",cn,ANN_EKF_NMPC_2_U.lat[cn],ANN_EKF_NMPC_2_U.lon[cn],ANN_EKF_NMPC_2_U.alt[cn],ANN_EKF_NMPC_2_U.WaypointsIN.n[cn-1],ANN_EKF_NMPC_2_U.WaypointsIN.e[cn-1],ANN_EKF_NMPC_2_U.WaypointsIN.h[cn-1],ANN_EKF_NMPC_2_U.WaypointsIN.v[cn]);
  }
  /* Terminate model */
  ANN_EKF_NMPC_2_terminate();
  /* Close hardware */
  CloseIMU();	
  CloseSerial();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
