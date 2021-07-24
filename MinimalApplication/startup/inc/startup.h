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

/* Initial Vector table */
uint32_t * vector_table[] __attribute__((section(".isr_vector"))) = {
		(uint32_t *) SRAM_END, // Stack pointer
		(uint32_t *) __start //Reset_Handler
};

#endif /* STARTUP_H_ */
