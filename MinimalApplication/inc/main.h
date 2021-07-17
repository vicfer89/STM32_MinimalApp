/*
 * main.h
 *
 *  Created on: 17 jul 2021
 *      Author: Vic
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "bsp.h"
#include "types.h"

int main(void);
/* Vector table */
uint32_t * vector_table[] __attribute__((section(".isr_vector"))) = {
		(uint32_t *) SRAM_END, // Stack pointer
		(uint32_t *) main //Reset_Handler
};


#endif /* MAIN_H_ */
