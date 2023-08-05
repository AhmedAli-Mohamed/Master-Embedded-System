#include<stdio.h>
#include"types.h"

extern uint32 E_text;
extern uint32 S_data;
extern uint32 E_data;
extern uint32 S_bss;
extern uint32 E_bss;
 extern int main ();
 
 /*Reset section*/
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

/*interrupt vector functions*/
void Default_Handler()
{
	Rest_Handler();
}
void NMI_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void H_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void Bus_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void MM_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;



static uint32 stack_top[256];  //creating 1000B for stack_top


/*vector section*/
void (* const p_vectors[])()__attribute__((section(".vectors")))=
{
	(void (*)()) (stack_top+sizeof(stack_top)),
	 &Rest_Handler,
	 &NMI_Handler,
	 &MM_Handler,
	 &Bus_Fault_Handler,
	 &H_Fault_Handler,
	 &Usage_Fault_Handler
};
	
