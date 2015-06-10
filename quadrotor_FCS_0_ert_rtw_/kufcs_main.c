/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'quadrotor_FCS_0'.
 *
 * Model version                  : 1.48
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Jun 02 14:15:35 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "quadrotor_FCS_0.h"           /* Model's header file */
#include "rtwtypes.h"
#include <time.h>
#include <unistd.h>
#include <inttypes.h>
#include <unistd.h>
#include <getopt.h>
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
#define DEBUG 1
#define SAVEFILE 1
#define PDEBUG(fmt, ...)						\
	do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

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
	time_t ftime;
	time(&ftime);	
	char fname[128];
	//printf("\n enter the file name for storing number of operations");
  	//scanf("%s",fname);
	sprintf(fname,"%s.txt",ctime(&ftime));
	FILE *fp=fopen(fname,"w");
	fprintf(fp,"ITER,TIME DIFF(us),LAT,LONG,ALT,P,Q,R,Vx,Vy,Vz,Phi,Theta,Psi,Ax,Ay,Az,motor1,motor2,motor3,motor4,OPmotor1,OPmotor2,OPmotor3,OPmotor4\n");
	long iter, repeat = 0;
	double interval_sec = (double)1/20;
	struct timespec start, end;
	int opt;
	/*
	 * get command line options 
	 */
	/*while ((opt = getopt(argc, argv, "i:h")) != -1) {
		switch (opt) {
		case 'i': /* iterations */
	/*		repeat = strtol(optarg, NULL, 0);
			PDEBUG("repeat=%ld\n", repeat);
			break;
		case 'h':
			usage(argc, argv);
			break;
		}
	}

	/* Initialize model */
	quadrotor_FCS_0_initialize();
	
	InitIMU(); /* vectornav */

	InitSerial(); /* arduino & movingpoints & waypoints*/
	
	clock_gettime(CLOCK_REALTIME, &start);
	iter =  0;
	while (1) {
		double remain_us;
		uint64_t tmpdiff;
		PDEBUG("\n\niter %ld starts\n", iter+1);
		/* Get sensor data */
		GetIMUData(&quadrotor_FCS_0_U);
		/* Get Arduino Data */
		GetSerialData(&quadrotor_FCS_0_U); 
               

		/* Step the model */
	       quadrotor_FCS_0_step();

		/* Output to the motor controller */
		SendSerialData(&quadrotor_FCS_0_U); 
                /* Send MicroHard */
		InitMicroHard();
		//Create_packets(&quadrotor_FCS_0_U);	
		/* Time book keeping */
		clock_gettime(CLOCK_REALTIME, &end);
		tmpdiff = get_elapsed(&start, &end);
		remain_us = (interval_sec * 1000000 - tmpdiff / 1000);
		if (remain_us > 0) {
			usleep((useconds_t)remain_us);
		}
		clock_gettime(CLOCK_REALTIME, &start);
		
/* Writing to a file */
		fprintf(fp,"%ld,%llu,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",iter,tmpdiff/1000,quadrotor_FCS_0_U.lla[0],quadrotor_FCS_0_U.lla[1],quadrotor_FCS_0_U.lla[2],quadrotor_FCS_0_U.Internalstates[6],quadrotor_FCS_0_U.Internalstates[7],quadrotor_FCS_0_U.Internalstates[8],quadrotor_FCS_0_U.Internalstates[0],quadrotor_FCS_0_U.Internalstates[1],quadrotor_FCS_0_U.Internalstates[2],quadrotor_FCS_0_U.Internalstates[3],quadrotor_FCS_0_U.Internalstates[4],quadrotor_FCS_0_U.Internalstates[5],quadrotor_FCS_0_U.Acc[0],quadrotor_FCS_0_U.Acc[1],quadrotor_FCS_0_U.Acc[2],quadrotor_FCS_0_U.RC[1],quadrotor_FCS_0_U.RC[2],quadrotor_FCS_0_U.RC[3],quadrotor_FCS_0_U.RC[4],quadrotor_FCS_0_U.RC[0],quadrotor_FCS_0_U.ORC[0],quadrotor_FCS_0_U.ORC[1],quadrotor_FCS_0_U.ORC[2],quadrotor_FCS_0_U.ORC[3]);
		printf("\n pwm in main are %f %f %f \n",quadrotor_FCS_0_U.RC[1],quadrotor_FCS_0_U.RC[2],quadrotor_FCS_0_U.RC[3]);

		iter++;
		PDEBUG("iter %ld took %" PRIu64 "us\n", iter, tmpdiff/1000);
		/*PDEBUG("Out: throttle=%f elevator=%f aileron=%f rudder=%f\n",
		       EKF_IFS_2_Y.ControlSurfaceCommands.throttle_cmd,
		       EKF_IFS_2_Y.ControlSurfaceCommands.elevator_cmd,
		       EKF_IFS_2_Y.ControlSurfaceCommands.aileron_cmd,
		       EKF_IFS_2_Y.ControlSurfaceCommands.rudder_cmd);*/

		//if (iter >= repeat)
		//	break;
	}

	/* Matfile logging */
	rt_StopDataLogging(MATFILE, quadrotor_FCS_0->rtwLogInfo);

	/* Terminate model */
	quadrotor_FCS_0_terminate();
	fclose(fp);
	/* Close hardware */
	CloseIMU();
	CloseSerial();
	CloseMicroHard();
	return 0;
}
