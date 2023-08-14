

MEMORY
{
 FLASH(RX): ORIGIN = 0x08000000 , LENGTH = 128K
 SRAM(RWX): ORIGIN = 0x20000000 , LENGTH = 20K

}
SECTIONS
{
  .text :
      {
	    *(.vectors)
		startup.o(.text)
	    *(.text)
		*(.rodata)
		E_text = . ;
           
       }>FLASH
	   
	.data :
	{
	   S_data = . ;
	   *(.data)
	   . = ALIGN(4) ;
	   E_data = . ;
	   
	}>SRAM AT> FLASH
	
	.bss :
	{
	 S_bss = . ;
	 *(.bss)
	 . = ALIGN(4) ;
	E_bss = . ;
	 . = . + 0x2000 ;
	 STACK_TOP = . ;
	}>SRAM
	




}
