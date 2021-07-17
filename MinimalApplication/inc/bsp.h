/*
 * bsp.h
 *
 *  Created on: 17 jul 2021
 *      Author: Vic
 */

#ifndef BSP_H_
#define BSP_H_

#include "types.h"

/* Direcciones de memoria y periféricos */
#define FLASH_BASE	0x08000000
#define SRAM_BASE	0x20000000
#define PERIPH_BASE	0x40000000

/* Establecemos el final de RAM como inicio para el puntero del stack */
#define SRAM_SIZE	128*1024 // From STM32F411RE datasheet
#define SRAM_END	(SRAM_BASE + SRAM_SIZE)

/* Direcciones base de memoria de perifericos para RCC */
#define RCC_BASE	(PERIPH_BASE + 0x23800) // From STM32F411RE datasheet
#define RCC_AHB1ENR	((uint32_t *)(RCC_BASE + 0x30)) // RCC AHB1 peripheral clock enable register (from reference manual)

/* GPIO A Direcciones y registros */
#define GPIOA_BASE	(PERIPH_BASE + 0x20000) // From STM32F411RE Datasheet
#define GPIOA_MODER	((uint32_t *) (GPIOA_BASE + 0x00)) // From Reference Manual
#define GPIOA_ODR	((uint32_t *) (GPIOA_BASE + 0x14)) // From Reference Manual

#endif /* BSP_H_ */
