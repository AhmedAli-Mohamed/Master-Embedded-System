#include"types.h"

extern uint32 STACK_TOP;
extern uint32 E_text;
extern uint32 S_data;
extern uint32 E_data;
extern uint32 S_bss;
extern uint32 E_bss;

extern int main();
//RESET SECTION
void RESET_HANDLER()
{
	uint32 count;
	uint8 * P_SRC;
	uint8 * P_DST;
	uint32 Data_Size = (uint8 *)&E_data - (uint8 *)&S_data;
	P_SRC = (uint8 * )&E_text;
	P_DST = (uint8 * )&S_data;
	for(count=0;count <Data_Size ; count ++)
	{
		*(P_DST++) = *(P_SRC++);
	}
	
	uint32 BSS_Size = (uint8 *)&E_bss - (uint8 *)&S_bss;
	
	P_DST = (uint8 * )&S_bss;
	for(count=0;count <BSS_Size ; count ++)
	{
		*(P_DST++) = 0;
	}
	main();
}


//VECTOR SECTION
void DEFULT_HANDLER()
{
	RESET_HANDLER();
}

void NMI_HANDLER()__attribute__((weak,alias("DEFULT_HANDLER")));;
void H_fault_HANDLER()__attribute__((weak,alias("DEFULT_HANDLER")));;


uint32 vector[]__attribute__((section(".vectors"))) =
{
	(uint32) &STACK_TOP,
	(uint32) &RESET_HANDLER,
	(uint32) &NMI_HANDLER,
	(uint32) &H_fault_HANDLER,
	
};