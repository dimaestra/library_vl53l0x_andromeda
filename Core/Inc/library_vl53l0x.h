#ifndef LIB_VL53L0X_H
#define LIB_VL53L0X_H

#include "stm32f4xx_hal.h"
#include "vl53l0x_api.h"

typedef struct {
	VL53L0X_RangingMeasurementData_t RangingData;
	VL53L0X_Dev_t  vl53l0x_c;
	uint32_t refSpadCount;
  uint8_t isApertureSpads;
  uint8_t VhvSettings;
  uint8_t PhaseCal;
}vl53l0x_t;

void vl53l0x_init(I2C_HandleTypeDef *i2c_handler, IRQn_Type interruptPin, vl53l0x_t tof, VL53L0X_DEV Dev);
#endif
