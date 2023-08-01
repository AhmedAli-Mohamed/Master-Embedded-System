#include<stdio.h>
#include"types.h"
extern uint32 stack_top;
extern uint32 E_text;
extern uint32 S_data;
extern uint32 E_data;
extern uint32 S_bss;
extern uint32 E_bss;
 extern int main ();
void Rest_Handler(void)
{
	uint32 DATA_SIZE= (uint8 *)&E_data - (uint8 *)&S_data ;
	uint32 BSS_SIZE = (uint8 *)&E_bss - (uint8 *)&S_bss ;
	uint8 *ptr_SRC = (uint8 * )&E_text;
	uint8 *ptr_DST = (uint8 * )&S_data;
	
	/*copying data section*/
	for (int i=0;i<DATA_SIZE;i++)
	{
		*ptr_DST++ = *ptr_SRC++;
	}
	
	/*initializing  bss_section*/
	ptr_DST =(uint8 *)&S_bss;
	for (int i=0;i<BSS_SIZE;i++)
	{
		*ptr_DST++ = 0;
	}
	
	main();
}
void Default_Handler()
{
	Rest_Handler();
}
void NMI_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void H_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void Bus_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void MM_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;

vuint32 vectors[]__attribute__((section(".vectors")))={
	(uint32) &stack_top,
	(uint32) &Rest_Handler,
	(uint32) &NMI_Handler,
	(uint32) &MM_Handler,
	(uint32) &Bus_Fault_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &Usage_Fault_Handler,
};

	
	