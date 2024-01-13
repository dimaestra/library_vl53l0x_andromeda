#include "library_vl53l0x.h"

void vl53l0x_init(I2C_HandleTypeDef *i2c_handler, IRQn_Type interruptPin, vl53l0x_t tof, VL53L0X_DEV Dev) {
	Dev->I2cHandle = i2c_handler;
	Dev->I2cDevAddr = 0x52;
	
	HAL_NVIC_DisableIRQ(interruptPin);
	VL53L0X_WaitDeviceBooted( Dev );
  VL53L0X_DataInit( Dev );
  VL53L0X_StaticInit( Dev );
  VL53L0X_PerformRefCalibration(Dev, &tof.VhvSettings, &tof.PhaseCal);
  VL53L0X_PerformRefSpadManagement(Dev, &tof.refSpadCount, &tof.isApertureSpads);
  VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);
  VL53L0X_StartMeasurement(Dev);
	HAL_NVIC_EnableIRQ(interruptPin);
};
/* ------------------------setup main dulu:----------------------------------------------------------------------------
vl53l0x_t tof;
VL53L0X_DEV    Dev = &vl53l0x_c;
*/
