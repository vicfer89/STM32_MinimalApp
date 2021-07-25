/*
 * startup.c
 *
 *  Created on: 17 jul 2021
 *      Author: Vic
 */

#include "../inc/startup.h"

void __initialize_data(
		uint32_t * flash_begin,
	    uint32_t * data_begin,
	    uint32_t * data_end
		){

	uint32_t *p = data_begin;

	while(p < data_end) // Recorro la memoria Ram que ha de ser copiada
	{
		*p++ = *flash_begin++; // Copio datos de Flash a Ram
	}
}

void __initialize_bss(
		uint32_t * bss_begin,
	    uint32_t * bss_end
		){

	uint32_t *p = bss_begin;

	while(p < bss_end) // Recorro la memoria Ram para BSS
		*p++ = 0; // Se almacena 0 en la región de memoria

}

void __start(void)
{
	__initialize_data(&_sidata, &_sdata, &_edata);
	__initialize_bss(&_sbss, &_ebss);

	main(); // Call to main function

	for(;;); // Wait forever
}

/* Vectores de interrupción */
__attribute__((weak)) void __NMI(void)
{
	asm("nop");
}

__attribute__((weak)) void __systick(void)
{
	asm("nop");
}

