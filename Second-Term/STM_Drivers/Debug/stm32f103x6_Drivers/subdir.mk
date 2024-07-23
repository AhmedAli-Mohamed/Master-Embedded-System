################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103x6_Drivers/EXTI.c \
../stm32f103x6_Drivers/I2C.c \
../stm32f103x6_Drivers/RCC.c \
../stm32f103x6_Drivers/SPI.c \
../stm32f103x6_Drivers/USART.c 

OBJS += \
./stm32f103x6_Drivers/EXTI.o \
./stm32f103x6_Drivers/I2C.o \
./stm32f103x6_Drivers/RCC.o \
./stm32f103x6_Drivers/SPI.o \
./stm32f103x6_Drivers/USART.o 

C_DEPS += \
./stm32f103x6_Drivers/EXTI.d \
./stm32f103x6_Drivers/I2C.d \
./stm32f103x6_Drivers/RCC.d \
./stm32f103x6_Drivers/SPI.d \
./stm32f103x6_Drivers/USART.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103x6_Drivers/EXTI.o: ../stm32f103x6_Drivers/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Arm_workspace/Drivers/HAL/includes" -I"E:/Arm_workspace/Drivers/stm32f103x6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_Drivers/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_Drivers/I2C.o: ../stm32f103x6_Drivers/I2C.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Arm_workspace/Drivers/HAL/includes" -I"E:/Arm_workspace/Drivers/stm32f103x6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_Drivers/I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_Drivers/RCC.o: ../stm32f103x6_Drivers/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Arm_workspace/Drivers/HAL/includes" -I"E:/Arm_workspace/Drivers/stm32f103x6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_Drivers/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_Drivers/SPI.o: ../stm32f103x6_Drivers/SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Arm_workspace/Drivers/HAL/includes" -I"E:/Arm_workspace/Drivers/stm32f103x6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_Drivers/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_Drivers/USART.o: ../stm32f103x6_Drivers/USART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Arm_workspace/Drivers/HAL/includes" -I"E:/Arm_workspace/Drivers/stm32f103x6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_Drivers/USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

