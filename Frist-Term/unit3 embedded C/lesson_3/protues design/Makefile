#ALL copy rightes are reserved for Beshtiques
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
project_name=Lab

all: $(project_name).bin
	@echo ">>>>>Build finished<<<<<" 
	
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o:%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
$(project_name).elf: $(ASOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(OBJ) -o $@  -Map=MAP_OUTPUT.map
	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary  $<  $@
	
clean:
	rm *.elf *.bin
	
clean_all:
	rm *.elf *.bin *.o
	@echo ">>>>>Every things ok <<<<<<<"