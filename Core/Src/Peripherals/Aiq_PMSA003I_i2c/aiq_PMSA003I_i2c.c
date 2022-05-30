/** aiq_PMSA003I_i2c.c
  *
  *  Created on: May 11, 2022
  *      Code ported by: snkYmkrct
  *
  *  Ported from Adafruit_PM25AQI.cpp
  *  	in the Adafruit PM2.5 Air Quality sensor Arduino library
  *
  *  	https://github.com/adafruit/Adafruit_PM25AQI
  *
  ******************************************************************************
  * Original file text:
  *
  * @file Adafruit_PM25AQI.cpp
  *
  * @mainpage Adafruit PM2.5 air quality sensor driver
  *
  * @section intro_sec Introduction
  *
  * This is the documentation for Adafruit's PM2.5 AQI driver for the
  * Arduino platform.  It is designed specifically to work with the
  * Adafruit PM2.5 Air quality sensors: http://www.adafruit.com/products/4632
  *
  * These sensors use I2C or UART to communicate.
  *
  * Adafruit invests time and resources providing this open source code,
  * please support Adafruit and open-source hardware by purchasing
  * products from Adafruit!
  *
  *
  * @section author Author
  * Written by Ladyada for Adafruit Industries.
  *
  * @section license License
  * BSD license, all text here must be included in any redistribution.
  *
 **/


#include "aiq_PMSA003I_i2c.h"
#include "stm32f4xx_hal.h"
#include <string.h>

extern I2C_HandleTypeDef hi2c3;



bool aiq_PMSA003I_i2c_read(PM25_AQI_Data *data) {
  uint8_t buffer[32];
  uint16_t sum = 0;

  if (!data) {
    return false;
  }

  if (HAL_I2C_IsDeviceReady(&hi2c3, PMSA003I_I2CADDR ,1, HAL_MAX_DELAY) != HAL_OK){
	  return false;
  }

  if (HAL_I2C_Master_Receive (&hi2c3, PMSA003I_I2CADDR, buffer, 32, HAL_MAX_DELAY) != HAL_OK){
	  return false;
  }

  // Check that start byte is correct!
  if (buffer[0] != 0x42) {
	  return false;
  }

  // get checksum ready
  for (uint8_t i = 0; i < 30; i++) {
    sum += buffer[i];
  }

  // The data comes in endian'd, this solves it so it works on all platforms
  uint16_t buffer_u16[15];
  for (uint8_t i = 0; i < 15; i++) {
    buffer_u16[i] = buffer[2 + i * 2 + 1];
    buffer_u16[i] += (buffer[2 + i * 2] << 8);
  }

  // put it into a nice struct :)
  memcpy((void *)data, (void *)buffer_u16, 30);

  if (sum != data->checksum) {
	  return false;
  }

  // success!
  return true;
}
