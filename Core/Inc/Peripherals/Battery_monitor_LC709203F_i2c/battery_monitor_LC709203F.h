/** battery_monitor_LC709203F.h
  *
  *  Created on: May 25, 2022
  *      Code ported by: snkYmkrct
  *
  *  Ported from Adafruit_LC709203F.h
  *  	in the Adafruit LC709203F Battery Monitor Arduino library
  *
  *  	https://github.com/adafruit/Adafruit_LC709203F
  *
  ******************************************************************************
  *  @file Adafruit_LC709203F.h
  *
  * 	I2C Driver for the Adafruit LC709203F Battery Monitor
  *
  * 	This is a library for the Adafruit LC709203F breakout:
  * 	https://www.adafruit.com/products/4712
  *
  *  Adafruit invests time and resources providing this open source code,
  *  please support Adafruit and open-source hardware by purchasing products from
  *  Adafruit!
  *
  *
  *	BSD license (see license.txt)
 */

#ifndef INC_PERIPHERALS_BATTERY_MONITOR_LC709203F_I2C_BATTERY_MONITOR_LC709203F_H_
#define INC_PERIPHERALS_BATTERY_MONITOR_LC709203F_I2C_BATTERY_MONITOR_LC709203F_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define LC709203F_I2CADDR 0x16  // vendor address 0x0B left shifted by 1 bit

#define LC709203F_I2CADDR_DEFAULT 0x0B     ///< LC709203F default i2c address
#define LC709203F_CMD_THERMISTORB 0x06     ///< Read/write thermistor B
#define LC709203F_CMD_INITRSOC 0x07        ///< Initialize RSOC calculation
#define LC709203F_CMD_CELLTEMPERATURE 0x08 ///< Read/write batt temperature
#define LC709203F_CMD_CELLVOLTAGE 0x09     ///< Read batt voltage
#define LC709203F_CMD_APA 0x0B             ///< Adjustment Pack Application
#define LC709203F_CMD_RSOC 0x0D            ///< Read state of charge
#define LC709203F_CMD_CELLITE 0x0F         ///< Read batt indicator to empty
#define LC709203F_CMD_ICVERSION 0x11       ///< Read IC version
#define LC709203F_CMD_BATTPROF 0x12        ///< Set the battery profile
#define LC709203F_CMD_ALARMRSOC 0x13       ///< Alarm on percent threshold
#define LC709203F_CMD_ALARMVOLT 0x14       ///< Alarm on voltage threshold
#define LC709203F_CMD_POWERMODE 0x15       ///< Sets sleep/power mode
#define LC709203F_CMD_STATUSBIT 0x16       ///< Temperature obtaining method
#define LC709203F_CMD_PARAMETER 0x1A       ///< Batt profile code

/*!  Battery temperature source */
typedef enum {
  LC709203F_TEMPERATURE_I2C = 0x0000,
  LC709203F_TEMPERATURE_THERMISTOR = 0x0001,
} lc709203_tempmode_t;

/*!  Chip power state */
typedef enum {
  LC709203F_POWER_OPERATE = 0x0001,
  LC709203F_POWER_SLEEP = 0x0002,
} lc709203_powermode_t;

/*!  Approx battery pack size */
typedef enum {
  LC709203F_APA_100MAH = 0x08,
  LC709203F_APA_200MAH = 0x0B,
  LC709203F_APA_500MAH = 0x10,
  LC709203F_APA_1000MAH = 0x19,
  LC709203F_APA_2000MAH = 0x2D,
  LC709203F_APA_3000MAH = 0x36,
} lc709203_adjustment_t;


  bool battery_monitor_LC709203F_begin();
  bool battery_monitor_LC709203F_initRSOC(void);

  bool battery_monitor_LC709203F_setPowerMode(lc709203_powermode_t t);
  bool battery_monitor_LC709203F_setPackSize(lc709203_adjustment_t apa);
  bool battery_monitor_LC709203F_setPackAPA(uint8_t apa_value);

  uint16_t battery_monitor_LC709203F_getICversion(void);
  float battery_monitor_LC709203F_cellVoltage(void);
  float battery_monitor_LC709203F_cellPercent(void);

  uint16_t battery_monitor_LC709203F_getThermistorB(void);
  bool battery_monitor_LC709203F_setThermistorB(uint16_t b);

  uint16_t battery_monitor_LC709203F_getBattProfile(void);
  bool battery_monitor_LC709203F_setBattProfile(uint16_t b);

  bool battery_monitor_LC709203F_setTemperatureMode(lc709203_tempmode_t t);
  float battery_monitor_LC709203F_getCellTemperature(void);

  bool battery_monitor_LC709203F_setAlarmRSOC(uint8_t percent);
  bool battery_monitor_LC709203F_setAlarmVoltage(float voltage);




#endif /* INC_PERIPHERALS_BATTERY_MONITOR_LC709203F_I2C_BATTERY_MONITOR_LC709203F_H_ */
