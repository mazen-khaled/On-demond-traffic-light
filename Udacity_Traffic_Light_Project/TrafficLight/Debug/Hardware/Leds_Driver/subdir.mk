################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hardware/Leds_Driver/leds.c 

OBJS += \
./Hardware/Leds_Driver/leds.o 

C_DEPS += \
./Hardware/Leds_Driver/leds.d 


# Each subdirectory must supply rules for building sources it contributes
Hardware/Leds_Driver/%.o: ../Hardware/Leds_Driver/%.c Hardware/Leds_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega323 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


