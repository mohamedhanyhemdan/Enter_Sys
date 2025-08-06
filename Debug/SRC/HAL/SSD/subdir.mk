################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/HAL/SSD/SSD.c 

OBJS += \
./SRC/HAL/SSD/SSD.o 

C_DEPS += \
./SRC/HAL/SSD/SSD.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/HAL/SSD/%.o: ../SRC/HAL/SSD/%.c SRC/HAL/SSD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


