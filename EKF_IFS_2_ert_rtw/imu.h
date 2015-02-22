
#ifndef IMU_H
#define IMU_H

#include "EKF_IFS_2.h"

extern void InitIMU(void);
extern void GetIMUData(ExtU_EKF_IFS_2_T *data);
extern void CloseIMU(void);

#endif
