#include "main.h"

volatile uint32_t DataVar = 0xFF;
volatile uint32_t BSSVar;

int main(){

	RCC.AHB1ENR = 0x1; // Habilitamos GPIO A
	GPIOA.MODER |= 0x400; // PA5 configurado como Pull-Up

	while(1)
	{
		GPIOA.ODR = 0x20; // Activamos PA5
		delay(1000000);
		GPIOA.ODR = 0x00; // Apagamos PA5
		delay(1000000);
	}

}
