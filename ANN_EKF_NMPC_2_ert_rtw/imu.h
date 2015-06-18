
#ifndef IMU_H
#define IMU_H

#include "ANN_EKF_NMPC_2.h"

extern void InitIMU(void);
extern void GetIMUData(ExtU_ANN_EKF_NMPC_2_T *data);
extern void CloseIMU(void);

#endif
