/*
 * neopixel.c
 *
 *  Created on: Jun 9, 2022
 *      Author: snkYmkrct
 */

#include "neopixel.h"
#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim2;

#define NEOPIXEL_BITS 24
#define DMA_BUFF_SIZE (NEOPIXEL_BITS * NEOPIXEL_NUMBER) + 50
#define NEOPIXEL_HIGH 60
#define NEOPIXEL_LOW  30

static uint8_t neopixelData[NEOPIXEL_NUMBER][3];
static uint32_t pwmData[DMA_BUFF_SIZE] = {0}; // last 50 bytes in buffer will stay 0 for reset


void Set_Neopixel(uint32_t LEDnum, uint8_t Red, uint8_t Green, uint8_t Blue)
{
	neopixelData[LEDnum][0] = Green;
	neopixelData[LEDnum][1] = Red;
	neopixelData[LEDnum][2] = Blue;
}

void Neopixel_Send(void)
{
	uint32_t indx=0;
	uint32_t color;

	for (int i=0; i<NEOPIXEL_NUMBER; i++)
	{
		color = ((neopixelData[i][0]<<16) | (neopixelData[i][1]<<8) | (neopixelData[i][2]));

		for (int j=23; j>=0; j--)
		{
			if (color&(1<<j)) {
				pwmData[indx] = NEOPIXEL_HIGH;  // 2/3 of 90
			}
			else {
				pwmData[indx] = NEOPIXEL_LOW;  // 1/3 of 90
			}

			indx++;
		}
	}

	HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_2, (uint32_t *)pwmData, DMA_BUFF_SIZE);

}



