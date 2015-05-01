
#ifndef IMU_H
#define IMU_H

#include "NMPC_Controller.h"

extern void InitIMU(void);
extern void GetIMUData(ExtU_NMPC_Controller_T *data);
extern void CloseIMU(void);

#endif
