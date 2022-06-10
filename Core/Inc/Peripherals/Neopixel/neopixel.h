/*
 * neopixel.h
 *
 *  Created on: Jun 9, 2022
 *      Author: snkYmkrct
 */

#ifndef INC_PERIPHERALS_NEOPIXEL_NEOPIXEL_H_
#define INC_PERIPHERALS_NEOPIXEL_NEOPIXEL_H_

#include <stdint.h>

#define NEOPIXEL_NUMBER 23


void Set_Neopixel(uint32_t LEDnum, uint8_t Red, uint8_t Green, uint8_t Blue);

void Neopixel_Send(void);

#endif /* INC_PERIPHERALS_NEOPIXEL_NEOPIXEL_H_ */
