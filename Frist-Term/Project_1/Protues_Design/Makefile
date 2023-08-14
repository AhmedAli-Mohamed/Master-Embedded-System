# ALL copyrights are reserved for Ahmed_Ali
CC=arm-none-eabi-
INCS=-I .
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
project_name=first_project

all:$(project_name).bin
	@echo " >>>>>>Build finished <<<<<<<<"

%.o:%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	@echo " >>>>>>compiling finished <<<<<<<<"
	 
$(project_name).elf: $(ASOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(OBJ) -o $(project_name).elf  -Map=MAP_OUTPUT.map
	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary  $<  $@

	
clean_all:
	rm *.elf *.bin *.o
	@echo ">>>>>Every things ok <<<<<<<"
