/*
 * neopixel.h
 *
 *  Created on: Jun 9, 2022
 *      Author: snkYmkrct
 */

#ifndef INC_PERIPHERALS_NEOPIXEL_NEOPIXEL_H_
#define INC_PERIPHERALS_NEOPIXEL_NEOPIXEL_H_


#define NEOPIXEL_NUMBER 23


void Set_Neopixel(int LEDnum, int Red, int Green, int Blue);

void Neopixel_Send(void);

#endif /* INC_PERIPHERALS_NEOPIXEL_NEOPIXEL_H_ */
