#include "bsp.h"

/* Funciones de usuario */
void delay(uint32_t count);

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

void delay(uint32_t count)
{
	while(count--);
}

