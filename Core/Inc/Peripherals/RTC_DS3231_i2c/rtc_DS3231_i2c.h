/** rtc_DS3231_i2c.h
  *
  *  Created on: May 30, 2022
  *      Author: snkYmkrct
  *
  ******************************************************************************
  *
 **/

#ifndef INC_PERIPHERALS_RTC_DS3231_I2C_RTC_DS3231_I2C_H_
#define INC_PERIPHERALS_RTC_DS3231_I2C_RTC_DS3231_I2C_H_

#include <stdint.h>
#include <stdbool.h>

#define DS3231_I2CADDR  0xD0 // 0x68 left shifted by 1 bit
#define DS3231_STATUSREG 0x0F // Status register

typedef struct DS3232data {
	uint32_t seconds,
			 minutes,
			 hour,
			 dayofweek,
			 dayofmonth,
			 month,
			 year;
} RTC_DS3232_Data;

bool rtc_DS3231_setTime(uint32_t sec, uint32_t min, uint32_t hour, uint32_t dow, uint32_t dom, uint32_t month, uint32_t year);

bool rtc_DS3231_getTime(RTC_DS3232_Data* data);

uint8_t rtc_DS3231_lostPower(void);

#endif
