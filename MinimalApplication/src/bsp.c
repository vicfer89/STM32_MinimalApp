/*
 * bsp.c
 *
 *  Created on: 17 jul 2021
 *      Author: Vic
 */

#include "bsp.h"
#include "stm32f4xx.h"

void RA5_off(void)
{
	GPIOA.ODR = 0x00;
}

void RA5_on(void)
{
	GPIOA.ODR = 0x20; // Activamos PA5
}

/* Delay function */
void delay(uint32_t count)
{
	while(count--);
}
