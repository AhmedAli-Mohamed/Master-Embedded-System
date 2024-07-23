################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_EEPROM.c \
../HAL/KEYPAD.c \
../HAL/LCD.c 

OBJS += \
./HAL/I2C_EEPROM.o \
./HAL/KEYPAD.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/I2C_EEPROM.d \
./HAL/KEYPAD.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/I2C_EEPROM.o: ../HAL/I2C_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Arm_workspace/Drivers/HAL/includes" -I"E:/Arm_workspace/Drivers/stm32f103x6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/I2C_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/KEYPAD.o: ../HAL/KEYPAD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Arm_workspace/Drivers/HAL/includes" -I"E:/Arm_workspace/Drivers/stm32f103x6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Arm_workspace/Drivers/HAL/includes" -I"E:/Arm_workspace/Drivers/stm32f103x6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

