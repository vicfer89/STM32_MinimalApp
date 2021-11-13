#include "main.h"

volatile uint32_t DataVar = 0xFF;
volatile uint32_t BSSVar;

/**
 * Funcion main que tiene contenido DoXyGeN
 * @fn int main()
 * @pre
 * @post
 * @return
 */
int main(){

	RCC.AHB1ENR = 0x1; // Habilitamos GPIO A
	GPIOA.MODER |= 0x400; // PA5 configurado como Pull-Up

	while(1)
	{
		RA5_on();
		delay(1000000);
		RA5_off();
		delay(1000000);
	}

}
