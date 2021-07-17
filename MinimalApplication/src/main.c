#include "main.h"

volatile uint32_t DataVar = 0xFF;
volatile uint32_t BSSVar;

int main(){
	*RCC_AHB1ENR = 0x1; // Habilitamos el reloj en GPIOA
	/* NOTA: Para PA5 */
	*GPIOA_MODER |= 0x400; //Se configura PA5 como pull-up y salida

	while(1)
	{
		*GPIOA_ODR = 0x20;
		delay(1000000);
		*GPIOA_ODR = 0x00;
		delay(1000000);
	}

}
