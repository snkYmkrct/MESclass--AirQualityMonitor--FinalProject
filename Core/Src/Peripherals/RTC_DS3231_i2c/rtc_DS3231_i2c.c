/** rtc_DS3231_i2c.c
  *
  *  Created on: May 30, 2022
  *      Author: snkYmkrct
  *
  ******************************************************************************
  *
 **/


#include "rtc_DS3231_i2c.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c3;

// Convert normal decimal numbers to binary coded decimal
static uint8_t decToBcd(uint32_t val)
{
  return (uint8_t)( (val/10*16) + (val%10) );
}

// Convert binary coded decimal to normal decimal numbers
static uint32_t bcdToDec(uint8_t val)
{
  return (uint32_t)( (val/16*10) + (val%16) );
}

bool rtc_DS3231_setTime(uint32_t sec, uint32_t min, uint32_t hour, uint32_t dow, uint32_t dom, uint32_t month, uint32_t year)
{
	uint8_t set_time[7];
	set_time[0] = decToBcd(sec);
	set_time[1] = decToBcd(min);
	set_time[2] = decToBcd(hour);
	set_time[3] = decToBcd(dow);
	set_time[4] = decToBcd(dom);
	set_time[5] = decToBcd(month);
	set_time[6] = decToBcd(year);

	if (HAL_I2C_Mem_Write(&hi2c3, DS3231_I2CADDR, 0x00, 1, set_time, 7, HAL_MAX_DELAY) != HAL_OK){
		return false;
	}

	return true;
}

bool rtc_DS3231_getTime(RTC_DS3232_Data* data)
{
	uint8_t get_time[7];

	if (!data) {
	return false;
	}

	if (HAL_I2C_IsDeviceReady(&hi2c3, DS3231_I2CADDR, 1, HAL_MAX_DELAY) != HAL_OK){
	  return false;
	}

	if (HAL_I2C_Mem_Read(&hi2c3, DS3231_I2CADDR, 0x00, I2C_MEMADD_SIZE_8BIT, get_time, 7, HAL_MAX_DELAY) != HAL_OK){
	  return false;
	}

	data->seconds = bcdToDec(get_time[0]);
	data->minutes = bcdToDec(get_time[1]);
	data->hour = bcdToDec(get_time[2]);
	data->dayofweek = bcdToDec(get_time[3]);
	data->dayofmonth = bcdToDec(get_time[4]);
	data->month = bcdToDec(get_time[5]);
	data->year = bcdToDec(get_time[6]);

	return true;
}

uint8_t rtc_DS3231_lostPower(void) {
	uint8_t rtc_status = 0;

	HAL_I2C_Mem_Read(&hi2c3, DS3231_I2CADDR, DS3231_STATUSREG >> 7, I2C_MEMADD_SIZE_8BIT, &rtc_status, 1, HAL_MAX_DELAY);

	return rtc_status;
}

