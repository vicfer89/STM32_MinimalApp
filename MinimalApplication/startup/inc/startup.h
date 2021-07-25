/*
 * startup.h
 *
 *  Created on: 17 jul 2021
 *      Author: Vic
 */

#ifndef STARTUP_H_
#define STARTUP_H_

#include "bsp.h"
#include "main.h"

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

void __start(void) __attribute__((weak, noreturn));

void __initialize_data(uint32_t * flash_begin,
					   uint32_t * data_begin,
					   uint32_t * data_end) __attribute__((weak));

void __initialize_bss(uint32_t * bss_begin,
					  uint32_t * bss_end) __attribute__((weak));

/* Definición de vectores */
void __NMI(void);
void __systick(void);

/* Initial Vector table */
uint32_t * vector_table[] __attribute__((section(".isr_vector"))) = {
		(uint32_t *) SRAM_END, // Stack pointer 0
		(uint32_t *) __start, //Reset_Handler 1
		(uint32_t *) __NMI, // NMI handler 2
		(uint32_t *) 0, // 3
		(uint32_t *) 0, // 4
		(uint32_t *) 0, //5
		(uint32_t *) 0, //6
		(uint32_t *) 0, //7
		(uint32_t *) 0, //8
		(uint32_t *) 0, //9
		(uint32_t *) 0, //10
		(uint32_t *) 0, //11
		(uint32_t *) 0, //12
		(uint32_t *) 0, //13
		(uint32_t *) 0, //14
		(uint32_t *) __systick, //15
};

#endif /* STARTUP_H_ */
