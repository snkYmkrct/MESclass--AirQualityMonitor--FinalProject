/** battery_monitor_LC709203F.c
  *
  *  Created on: May 25, 2022
  *      Code ported by: snkYmkrct
  *
  *  Ported from Adafruit_LC709203F.cpp
  *  	in the Adafruit LC709203F Battery Monitor Arduino library
  *
  *  	https://github.com/adafruit/Adafruit_LC709203F
  *
  ******************************************************************************
  *
  *  @file Adafruit_LC709203F.cpp
  *
  *  @mainpage Adafruit LC709203F Battery Monitor library
  *
  *  @section intro_sec Introduction
  *
  * 	I2C Driver for the Adafruit LC709203F Battery Monitor library
  *
  * 	This is a library for the Adafruit LC709203F breakout:
  * 	https://www.adafruit.com/product/4712
  *
  *  Adafruit invests time and resources providing this open source code,
  *  please support Adafruit and open-source hardware by purchasing products from
  *  Adafruit!
  *
  *  @section dependencies Dependencies
  *  This library depends on the Adafruit BusIO library
  *
  *  @section author Author
  *
  *  Limor Fried (Adafruit Industries)
  *
  * 	@section license License
  *
  * 	BSD (see license.txt)
  *
  * 	@section  HISTORY
  *
  *     v1.0 - First release
 **/

#include <Peripherals/Battery_monitor_LC709203F_i2c/battery_monitor_LC709203F.h>
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c3;

/**
 * Performs a CRC8 calculation on the supplied values.
 *
 * @param data  Pointer to the data to use when calculating the CRC8.
 * @param len   The number of bytes in 'data'.
 *
 * @return The computed CRC8 value.
 */
static uint8_t crc8(uint8_t *data, int len) {
  const uint8_t POLYNOMIAL = 0x07;
  uint8_t crc = 0x00;

  for (int j = len; j; --j) {
    crc ^= *data++;

    for (int i = 8; i; --i) {
      crc = (crc & 0x80) ? (crc << 1) ^ POLYNOMIAL : (crc << 1);
    }
  }
  return crc;
}

/*!
 *    @brief  Helper that reads 16 bits of CRC data from the chip. Note
 *            this function performs a CRC on data that includes the I2C
 *            write address, command, read address and 2 bytes of response
 *    @param command The I2C register/command
 *    @param data Pointer to uint16_t value we will store response
 *    @return true on successful I2C read
 */
static bool battery_monitor_LC709203F_readWord(uint8_t command, uint16_t *data) {
  uint8_t reply[6];
  reply[0] = LC709203F_I2CADDR_DEFAULT * 2; // write byte
  reply[1] = command;                       // command / register
  reply[2] = reply[0] | 0x1;                // read byte

  if (HAL_I2C_IsDeviceReady(&hi2c3, LC709203F_I2CADDR ,1, HAL_MAX_DELAY) != HAL_OK){
	  return false;
  }
  /*
  if (HAL_I2C_Master_Transmit(&hi2c3, LC709203F_I2CADDR, &command, 1, HAL_MAX_DELAY)  != HAL_OK){
	  return false;
  }

  /// doesn't work like this, because a repeated start condition is necessary ... only hal_mem_read can do that

  if (HAL_I2C_Master_Receive (&hi2c3, reply[2], reply + 3, 3, HAL_MAX_DELAY) != HAL_OK){
	  return false;
  }*/


  if (HAL_I2C_Mem_Read(&hi2c3, reply[2], reply[1], I2C_MEMADD_SIZE_8BIT, reply+3, 3, HAL_MAX_DELAY) != HAL_OK)  {
         return false;
     }

  uint8_t crc = crc8(reply, 5);
  // CRC failure?
  if (crc != reply[5])
    return false;

  *data = reply[4];
  *data <<= 8;
  *data |= reply[3];

  return true;
}

/*!
 *    @brief  Helper that writes 16 bits of CRC data to the chip. Note
 *            this function performs a CRC on data that includes the I2C
 *            write address, command, and 2 bytes of response
 *    @param command The I2C register/command
 *    @param data Pointer to uint16_t value we will write to register
 *    @return true on successful I2C write
 */
static bool battery_monitor_LC709203F_writeWord(uint8_t command, uint16_t data) {
  uint8_t send[5];
  send[0] = LC709203F_I2CADDR_DEFAULT * 2; // write byte
  send[1] = command;                       // command / register
  send[2] = data & 0xFF;
  send[3] = data >> 8;
  send[4] = crc8(send, 4);

  if (HAL_I2C_IsDeviceReady(&hi2c3, LC709203F_I2CADDR ,1, HAL_MAX_DELAY) != HAL_OK){
	  return false;
  }

  if (HAL_I2C_Master_Transmit(&hi2c3, LC709203F_I2CADDR, send + 1, 4, HAL_MAX_DELAY)  != HAL_OK){
	  return false;
  }
  return true;
}


bool battery_monitor_LC709203F_begin() {

  if (!battery_monitor_LC709203F_setPowerMode(LC709203F_POWER_OPERATE))
    return false;

  if (!battery_monitor_LC709203F_setPackSize(LC709203F_APA_1000MAH))
    return false;

  // use 4.2V profile
  if (!battery_monitor_LC709203F_setBattProfile(0x1))
    return false;

  if (!battery_monitor_LC709203F_setTemperatureMode(LC709203F_TEMPERATURE_THERMISTOR))
    return false;

  return true;
}

/*!
 *    @brief  Get IC LSI version
 *    @return 16-bit value read from LC709203F_CMD_ICVERSION register
 */
uint16_t battery_monitor_LC709203F_getICversion(void) {
  uint16_t vers = 0;
  battery_monitor_LC709203F_readWord(LC709203F_CMD_ICVERSION, &vers);
  return vers;
}

/*!
 *    @brief  Initialize the RSOC algorithm
 *    @return true on I2C command success
 */
bool battery_monitor_LC709203F_initRSOC(void) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_INITRSOC, 0xAA55);
}

/*!
 *    @brief  Get battery voltage
 *    @return Floating point value read in Volts
 */
float battery_monitor_LC709203F_cellVoltage(void) {
  uint16_t voltage = 0;
  battery_monitor_LC709203F_readWord(LC709203F_CMD_CELLVOLTAGE, &voltage);
  return voltage / 1000.0;
}

/*!
 *    @brief  Get battery state in percent (0-100%)
 *    @return Floating point value from 0 to 100.0
 */
float battery_monitor_LC709203F_cellPercent(void) {
  uint16_t percent = 0;
  battery_monitor_LC709203F_readWord(LC709203F_CMD_CELLITE, &percent);
  return percent / 10.0;
}

/*!
 *    @brief  Get battery thermistor temperature
 *    @return Floating point value from -20 to 60 *C
 */
static float map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max) {
  return (float)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
float battery_monitor_LC709203F_getCellTemperature(void) {
  uint16_t temp = 0;
  battery_monitor_LC709203F_readWord(LC709203F_CMD_CELLTEMPERATURE, &temp);
  float tempf = map(temp, 0x9E4, 0xD04, -200, 600);
  return tempf / 10.0;
}

/*!
 *    @brief  Set the temperature mode (external or internal)
 *    @param t The desired mode: LC709203F_TEMPERATURE_I2C or
 * LC709203F_TEMPERATURE_THERMISTOR
 *    @return true on successful I2C write
 */
bool battery_monitor_LC709203F_setTemperatureMode(lc709203_tempmode_t t) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_STATUSBIT, (uint16_t)t);
}

/*!
 *    @brief  Set the approximate pack size, helps RSOC calculation
 *    @param apa The lc709203_adjustment_t enumerated approximate cell size
 *    @return true on successful I2C write
 */
bool battery_monitor_LC709203F_setPackSize(lc709203_adjustment_t apa) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_APA, (uint16_t)apa);
}

/*!
 *    @brief  Set battery APA value, per LC709203F datasheet
 *    @param apa_value 8-bit APA value to use for the attached battery
 *    @return true on successful I2C write
 */
bool battery_monitor_LC709203F_setPackAPA(uint8_t apa_value) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_APA, (uint16_t)apa_value);
}

/*!
 *    @brief  Set the alarm pin to respond to an RSOC percentage level
 *    @param percent The threshold value, set to 0 to disable alarm
 *    @return true on successful I2C write
 */
bool battery_monitor_LC709203F_setAlarmRSOC(uint8_t percent) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_ALARMRSOC, percent);
}

/*!
 *    @brief  Set the alarm pin to respond to a battery voltage level
 *    @param voltage The threshold value, set to 0 to disable alarm
 *    @return true on successful I2C write
 */
bool battery_monitor_LC709203F_setAlarmVoltage(float voltage) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_ALARMVOLT, voltage * 1000);
}

/*!
 *    @brief  Set the power mode, LC709203F_POWER_OPERATE or
 * LC709203F_POWER_SLEEP
 *    @param t The power mode desired
 *    @return true on successful I2C write
 */
bool battery_monitor_LC709203F_setPowerMode(lc709203_powermode_t t) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_POWERMODE, (uint16_t)t);
}

/*!
 *    @brief  Get the thermistor B value (e.g. 3950)
 *    @return The uint16_t B value
 */
uint16_t battery_monitor_LC709203F_getThermistorB(void) {
  uint16_t val = 0;
  battery_monitor_LC709203F_readWord(LC709203F_CMD_THERMISTORB, &val);
  return val;
}

/*!
 *    @brief  Set the thermistor B value (e.g. 3950)
 *    @param b The value to set it to
 *    @return true on successful I2C write
 */
bool battery_monitor_LC709203F_setThermistorB(uint16_t b) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_THERMISTORB, b);
}

/*!
 *    @brief  Get the battery profile parameter
 *    @return The uint16_t profile value (0 or 1)
 */
uint16_t battery_monitor_LC709203F_getBattProfile(void) {
  uint16_t val = 0;
  battery_monitor_LC709203F_readWord(LC709203F_CMD_BATTPROF, &val);
  return val;
}

/*!
 *    @brief  Set the battery profile parameter
 *    @param b The value to set it to (0 or 1)
 *    @return true on successful I2C write
 */
bool battery_monitor_LC709203F_setBattProfile(uint16_t b) {
  return battery_monitor_LC709203F_writeWord(LC709203F_CMD_BATTPROF, b);
}

