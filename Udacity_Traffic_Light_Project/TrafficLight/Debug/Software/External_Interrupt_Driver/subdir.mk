################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Software/External_Interrupt_Driver/External_Interrupt_Driver.c 

OBJS += \
./Software/External_Interrupt_Driver/External_Interrupt_Driver.o 

C_DEPS += \
./Software/External_Interrupt_Driver/External_Interrupt_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Software/External_Interrupt_Driver/%.o: ../Software/External_Interrupt_Driver/%.c Software/External_Interrupt_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega323 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


