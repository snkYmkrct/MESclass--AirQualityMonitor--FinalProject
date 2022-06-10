/*
 * peripheral_data.h
 *
 *  Created on: Jun 10, 2022
 *      Author: snkYmkrct
 */

#ifndef INC_PERIPHERALS_PERIPHERAL_DATA_H_
#define INC_PERIPHERALS_PERIPHERAL_DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"
#include "aiq_PMSA003I_i2c.h"
#include "scd4x_i2c.h"
#include "rtc_DS3231_i2c.h"
#include "battery_monitor_LC709203F.h"
#include "neopixel.h"

void peripheralInitValues();

void peripheralUpdateValues();

void peripheralGetTime(uint32_t *hour, uint32_t *minute, uint32_t *second);

void peripheralGetDate(uint32_t *dayofweek, uint32_t *dayofmonth, uint32_t *month, uint32_t *year);

void peripheralSetDateANDTime(uint32_t sec, uint32_t min, uint32_t hour, uint32_t dow, uint32_t dom, uint32_t month, uint32_t year);

uint16_t peripheralGetAQIpm25();

void peripheralGetCO2TempHum(uint16_t *co2, float *temperature, float *humidity);

void peripheralGetBattery(float *voltage, float *percentage);

void peripheralSetAllNeopixels(uint32_t colorHexRGB);

#endif /* INC_PERIPHERALS_PERIPHERAL_DATA_H_ */
