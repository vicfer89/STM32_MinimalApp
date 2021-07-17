/* Esquema de memoria */

MEMORY
{
	FLASH (rx)	: ORIGIN = 0x08000000, LENGTH = 512K
	SRAM (xrw)	: ORIGIN = 0x20000000, LENGTH = 128K
}

ENTRY(main)

/* Secciones de salida */
SECTIONS
{

	/* Codigo en Flash */
	.text : ALIGN(4)
	{
		*(.isr_vector) /* Tabla de vectores */
		*(.text) /* Codigo de programa */
		/* *(.text*) /* Juntar todas las secciones .text en esta seccion */ */
		KEEP(*(.isr_vector))
	} >FLASH
	
	/* Datos a SRAM */
	.data :
	{
		*(.data)
	} >SRAM

}