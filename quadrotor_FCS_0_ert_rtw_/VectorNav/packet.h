#include<stdint.h>
#include<stdio.h>
#include<string.h>
typdef struct 
{
	char a,p,d,s;
}header;
struct pdata
{
	uint32_t MPCClockCount=0;
	uint32_t CycleCount=0;
	float    DistancetoWaypoint=0;
	uint8_t  WaypointIndex=0;
	int8_t   WaypointUploadStatus=0;
	uint8_t  PIC_CIC;
	float    PilotThrottle;
	float    PilotElevatorRad;
	float    PilotAileronRad;
	float    PilotRudderRad;
	uint8_t  SPIStatus=0;
	uint8_t  UpPacketCnt=0;
	uint8_t  NAVstatus=0;
	uint8_t  RadarCommand=0;
	uint8_t  RadarStatus=0;
	double   EtaLat=0;
	double   EtaLon=0;
	float    VTCommandState=0;
	float    ThetaCommandState=0;
	float    PhiCommandState=0;
	float    HomeCommand=0;
	uint8_t  DebugSwEn=0;
	uint8_t  DebugCalibration=0;
	float    IFSThrottleCmd;
	float	 IFSElevatorCmd;
	float	 IFSAileronCmd;
	float	 IFSRudderCmd;
	double	 SPLatitude;
	double	 SPLongitude;
	double 	 SPAltitude;
	float	 SPVnorth;
	float	 SPVeast;
	float	 SPVdown;
	float	 SPPhi;
	float	 SPTheta;
	float 	 SPPsi;
	float	 SPVT=0;
	float	 SPAlpha=0;
	float	 SPBeta=0;
	float	 SPP;
	float	 SPQ;
	float	 SPR;
	uint8_t  SPNovaPosType=0;
	uint8_t	 SPNovaSolType=0;
	uint8_t  SPNovaNumSats=0;
	float	 SPVT2=0;
};
struct checksum
{
	uint16_t checksum;
};


