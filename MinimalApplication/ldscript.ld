/* Esquema de memoria */

MEMORY
{
	FLASH (rx)	: ORIGIN = 0x08000000, LENGTH = 512K
	SRAM (xrw)	: ORIGIN = 0x20000000, LENGTH = 128K
}

ENTRY(__start)

/* Secciones de salida */
SECTIONS
{

	/* Codigo en Flash */
	.text : ALIGN(4)
	{
		*(.isr_vector) /* Tabla de vectores */
		. = ALIGN(4);
		*(.romessage)
		. = ALIGN(4);
		/**(.text) /* Codigo de programa */*/
		*(.text*) /* Juntar todas las secciones .text en esta seccion */	
		KEEP(*(.romessage))	
		KEEP(*(.isr_vector))
	} >FLASH
	
	/* Datos a SRAM */
	_sidata = LOADADDR(.data);
	
	.data : ALIGN(4)
	{
		. = ALIGN(4);
		_sdata = .;
				
		*(.data)
		*(.data*)
		
		. = ALIGN(4);
		_edata = .;
	} >SRAM AT>FLASH
	
	/* Region para BSS */
	.bss : ALIGN(4)
	{
		_sbss = .;
		
		*(.bss .bss*)
		*(COMMON)
		
		. = ALIGN(4);
		_ebss = .;
	} >SRAM AT>FLASH

}