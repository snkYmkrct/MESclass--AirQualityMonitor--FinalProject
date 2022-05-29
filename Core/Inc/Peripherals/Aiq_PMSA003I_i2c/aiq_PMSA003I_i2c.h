/** aiq_PMSA003I_i2c.h
  *
  *  Created on: May 11, 2022
  *      Code ported by: snkYmkrct
  *
  *  Ported from Adafruit_PM25AQI.h
  *  	in the Adafruit PM2.5 Air Quality sensor Arduino library
  *
  *  	https://github.com/adafruit/Adafruit_PM25AQI
  *
  ******************************************************************************
  * Original file text:
  *
  * @file Adafruit_PM25AQI.h
  *
  * This is the documentation for Adafruit's PM25 AQI driver for the
  * Arduino platform.  It is designed specifically to work with the
  * Adafruit PM25 air quality sensors: http://www.adafruit.com/products/4632
  *
  * These sensors use I2C or UART to communicate.
  *
  * Adafruit invests time and resources providing this open source code,
  * please support Adafruit and open-source hardware by purchasing
  * products from Adafruit!
  *
  * Written by Ladyada for Adafruit Industries.
  *
  * BSD license, all text here must be included in any redistribution.
  *
 **/

#ifndef SRC_SENSORS_AIQ_PMSA003I_I2C_H_
#define SRC_SENSORS_AIQ_PMSA003I_I2C_H_

#include <stdint.h>
#include <stdbool.h>

#define PMSA003I_I2CADDR 0x24  // vendor address 0x12 left shifted by 1 bit

typedef struct PMSAQIdata {
  uint16_t framelen;       ///< How long this data chunk is
  uint16_t pm10_standard,  ///< Standard PM1.0
      pm25_standard,       ///< Standard PM2.5
      pm100_standard;      ///< Standard PM10.0
  uint16_t pm10_env,       ///< Environmental PM1.0
      pm25_env,            ///< Environmental PM2.5
      pm100_env;           ///< Environmental PM10.0
  uint16_t particles_03um, ///< 0.3um Particle Count
      particles_05um,      ///< 0.5um Particle Count
      particles_10um,      ///< 1.0um Particle Count
      particles_25um,      ///< 2.5um Particle Count
      particles_50um,      ///< 5.0um Particle Count
      particles_100um;     ///< 10.0um Particle Count
  uint16_t unused;         ///< Unused
  uint16_t checksum;       ///< Packet checksum
} PM25_AQI_Data;

bool aiq_PMSA003I_i2c_read(PM25_AQI_Data *data);

#endif /* SRC_SENSORS_AIQ_PMSA003I_I2C_H_ */
