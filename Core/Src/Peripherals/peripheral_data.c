/*
 * peripheral_data.c
 *
 *  Created on: Jun 10, 2022
 *      Author: snkYmkrct
 */

#include "peripheral_data.h"

// peripherals sampling rates in milliseconds
#define RTC_SAMPLING 1000
#define AQI_SAMPLING 2300
#define BAT_SAMPLING 10000
#define CO2_SAMPLING 5000
#define PIXEL_SAMPLING 1000

static uint32_t printTick = 0u;

static RTC_DS3232_Data timeData_DS3231 = {0};
static uint32_t rtcTick = 0u;

static PM25_AQI_Data aqiData_PMSA003I = {0};
static uint32_t aqiTick = 0u;

static uint16_t co2_SCD4X;
static float temperature_SCD4X;
static float humidity_SCD4X;
static uint32_t co2Tick = 0u;

static float voltageValue_LC709203F;
static float voltagePercent_LC709203F;
static uint32_t voltageTick = 0u;

static uint32_t pixelTick = 0u;
const uint8_t gamma8[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

void peripheralInitValues(){

	  // Clean up potential SCD40 states
	  scd4x_wake_up();
	  scd4x_stop_periodic_measurement();
	  scd4x_reinit();

	  uint16_t serial_0;
	  uint16_t serial_1;
	  uint16_t serial_2;
	  int16_t error = 0;
	  error = scd4x_get_serial_number(&serial_0, &serial_1, &serial_2);
	  if (error) {
	      printf("Error executing scd4x_get_serial_number(): %i \r\n", error);
	  } else {
	      printf("co2 serial: 0x%04x%04x%04x\r\n", serial_0, serial_1, serial_2);
	  }
	  // Start Measurement
	  error = scd4x_start_periodic_measurement();
	  if (error) {
	      printf("Error executing scd4x_start_periodic_measurement(): %i \r\n",
	             error);
	  }
	  printf("Waiting for first co2 measurement... (5 sec)\r\n");


	  if (!battery_monitor_LC709203F_begin()) {
	    printf("\r\nCouldnt find Adafruit LC709203F ?\r\nMake sure a battery is plugged in!\r\n");
	  }

	  printf("\r\nFound battery monitor LC709203F\r\n");
	  printf("Version: 0x");
	  printf("%x \r\n", battery_monitor_LC709203F_getICversion());
	  //battery_monitor_LC709203F_setAlarmVoltage(3.8);

}

void peripheralUpdateValues(){

	uint32_t currentTick = HAL_GetTick();

	if ( (currentTick - rtcTick) >= RTC_SAMPLING ){  // update every second
		if ( rtc_DS3231_getTime(&timeData_DS3231) ){
			rtcTick = currentTick;
		}
	}

	if ( (currentTick - aqiTick) >= AQI_SAMPLING ){  // new data is valid after 2.3 seconds
		if ( aiq_PMSA003I_i2c_read(&aqiData_PMSA003I) ){
			aqiTick = currentTick;
		}
	}

	if ( (currentTick - voltageTick) >= BAT_SAMPLING){  // get value every 10 seconds
		voltageTick = currentTick;
		voltageValue_LC709203F = battery_monitor_LC709203F_cellVoltage();
		voltagePercent_LC709203F = battery_monitor_LC709203F_cellPercent();
	}

	if ( (currentTick - co2Tick) >= CO2_SAMPLING ){  // new data is valid after 5 seconds
		int16_t error = 0;
		bool data_ready_flag = false;
		uint16_t co2;
		int32_t temperature;
		int32_t humidity;

		error = scd4x_get_data_ready_flag(&data_ready_flag);
		if (!error){
		  if (data_ready_flag) {
			  error = scd4x_read_measurement(&co2, &temperature, &humidity);
			  if ( (!error) && (co2 != 0) ) {
				  co2Tick = currentTick;
				  co2_SCD4X = co2;
				  temperature_SCD4X = (float)temperature/1000.0;
				  humidity_SCD4X = (float)humidity/1000.0;
			  }
		  }
		}
	}
/*
	if ( (currentTick - printTick) >= 5000){
		printTick = currentTick;

		peripheralPrintTime();

		printf("\r\n\r\n  tick now: %ld    %ld  \r\n\r\n",currentTick, HAL_GetTick());

		peripheralPrintBattery();

		peripheralPrintCo2();

		peripheralPrintAQI();
	}
*/
}

void peripheralUpdateNeopixelsfromCO2(){
	  uint8_t red, green, blue;
	  uint32_t currentTick = HAL_GetTick();

	  if ( (currentTick - pixelTick) >= PIXEL_SAMPLING){
		  pixelTick = currentTick;
		  if (co2_SCD4X < 900){
			  //green
			  red = gamma8[0];
			  green = gamma8[125];
			  blue = gamma8[0];
		  } else {
			  if (co2_SCD4X > 1600){
				  // red
				  red = gamma8[125];
				  green = gamma8[0];
				  blue = gamma8[0];
			  }
			  else {
				  // orange
				  red = gamma8[125];
				  green = gamma8[65];
				  blue = gamma8[0];
			  }
		  }
		  for (uint8_t i=0; i<NEOPIXEL_NUMBER; i++){
			  Set_Neopixel(i, red, green, blue);
		  }
		  Neopixel_Send();
	  }
}

void peripheralPrintTime(){

	printf("````````````````````````````````````````\r\n");
	char days[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	printf(" %02ld:%02ld:%02ld \r\n", timeData_DS3231.hour, timeData_DS3231.minutes, timeData_DS3231.seconds);
	// check for valid data on dayofweek TODO
	printf(" %s, %02ld-%02ld-20%02ld\r\n", days[timeData_DS3231.dayofweek-1], timeData_DS3231.dayofmonth, timeData_DS3231.month, timeData_DS3231.year);
	printf("````````````````````````````````````````\r\n");
}

void peripheralPrintBattery(){

	printf("\r\n=======================================\r\n");
	printf("Batt Voltage: %.3f  \r\n", voltageValue_LC709203F);
	printf("Batt Percent: %.3f %% \r\n", voltagePercent_LC709203F);
	printf("=======================================\r\n");
}

void peripheralPrintCo2(){

	printf(" \r\nCO2: %u \r\n", co2_SCD4X);
	printf("Temperature: %.2f °C \r\n", temperature_SCD4X);
	printf("Humidity: %.2f %% \r\n", humidity_SCD4X);
}

void peripheralPrintAQI(){

	printf("---------------------------------------\r\n");
	printf("Concentration Units (standard)\r\n");
	printf("---------------------------------------\r\n");
	printf("PM 1.0: %d \r\n", aqiData_PMSA003I.pm10_standard);
	printf("PM 2.5: %d \r\n", aqiData_PMSA003I.pm25_standard);
	printf("PM 10: %d \r\n", aqiData_PMSA003I.pm100_standard);

	printf("\r\nConcentration Units (environmental)\r\n");
	printf("---------------------------------------\r\n");
	printf("PM 1.0: %d \r\n", aqiData_PMSA003I.pm10_env);
	printf("PM 2.5: %d \r\n", aqiData_PMSA003I.pm25_env);
	printf("PM 10: %d \r\n", aqiData_PMSA003I.pm100_env);

	printf("\r\n---------------------------------------\r\n");
	printf("Particles > 0.3um / 0.1L air: %d \r\n", aqiData_PMSA003I.particles_03um);
	printf("Particles > 0.5um / 0.1L air: %d \r\n", aqiData_PMSA003I.particles_05um);
	printf("Particles > 1.0um / 0.1L air: %d \r\n", aqiData_PMSA003I.particles_10um);
	printf("Particles > 2.5um / 0.1L air: %d \r\n", aqiData_PMSA003I.particles_25um);
	printf("Particles > 5.0um / 0.1L air: %d \r\n", aqiData_PMSA003I.particles_50um);
	printf("Particles > 10 um / 0.1L air: %d \r\n", aqiData_PMSA003I.particles_100um);
	printf("\r\n---------------------------------------\r\n");

}

/* -----------------RTC interface--------------------------- */
void peripheralGetTime(uint32_t *hour, uint32_t *minute, uint32_t *second){

	*hour = timeData_DS3231.hour;
	*minute = timeData_DS3231.minutes;
	*second = timeData_DS3231.seconds;
}

void peripheralGetDate(uint32_t *dayofweek, uint32_t *dayofmonth, uint32_t *month, uint32_t *year){

	*dayofweek = timeData_DS3231.dayofweek;
	*dayofmonth = timeData_DS3231.dayofmonth;
	*month = timeData_DS3231.month;
	*year = timeData_DS3231.year;
}

void peripheralSetDateANDTime(uint32_t sec, uint32_t min, uint32_t hour, uint32_t dow, uint32_t dom, uint32_t month, uint32_t year){
	rtc_DS3231_setTime(sec, min, hour, dow, dom, month, year);
}
/* ------------------------------------------------------------ */


/* --------------------AQI interface--------------------------- */
uint16_t peripheralGetAQIpm25(){

	return aqiData_PMSA003I.pm25_env;
}
/* ------------------------------------------------------------ */


/* --------------------CO2 interface--------------------------- */
void peripheralGetCO2TempHum(uint16_t *co2, float *temperature, float *humidity){

	*co2 = co2_SCD4X;
	*temperature = temperature_SCD4X;
	*humidity = humidity_SCD4X;
}
/* ------------------------------------------------------------ */


/* ----------------Battery interface--------------------------- */
void peripheralGetBattery(float *voltage, float *percentage){

	*voltage = voltageValue_LC709203F;
	*percentage = voltagePercent_LC709203F;
}
/* ------------------------------------------------------------ */


/* ---------------Neopixel interface--------------------------- */
void peripheralSetAllNeopixels(uint32_t colorHexRGB){

	uint8_t red = gamma8[(colorHexRGB >> 16) & 0xFF];
	uint8_t green = gamma8[(colorHexRGB >> 8) & 0xFF];
	uint8_t blue = gamma8[colorHexRGB & 0xFF];
	for (uint8_t i=0; i<NEOPIXEL_NUMBER; i++){
		Set_Neopixel(i, red, green, blue);
	}
	Neopixel_Send();
}

void peripheralSetAllNeopixelsToRandom(){

	uint8_t red = gamma8[(uint8_t)(rand() % 256)];
	uint8_t green = gamma8[(uint8_t)(rand() % 256)];
	uint8_t blue = gamma8[(uint8_t)(rand() % 256)];
	printf("\r\n\r\n   red 0x%x  green 0x%x  blue 0x%x \r\n\r\n", red, green, blue);
	  for (uint8_t i=0; i<NEOPIXEL_NUMBER; i++){
		  Set_Neopixel(i, red, green, blue);
	  }
	Neopixel_Send();
}
/* ------------------------------------------------------------ */
