# library_vl53l0x_andromeda
1. setup main dulu \
vl53l0x_t tof; \
VL53L0X_DEV    Dev = &tof.vl53l0x_c; \
2. callback \
VL53L0X_GetRangingMeasurementData(Dev, &tof.RangingData); \
VL53L0X_ClearInterruptMask(Dev, VL53L0X_REG_SYSTEM_INTERRUPT_GPIO_NEW_SAMPLE_READY);
