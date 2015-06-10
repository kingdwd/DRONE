
#ifndef IMU_H
#define IMU_H

#include "quadrotor_FCS_0.h"

extern void InitIMU(void);
extern void GetIMUData(ExtU_quadrotor_FCS_0_T *data);
extern void CloseIMU(void);

#endif
