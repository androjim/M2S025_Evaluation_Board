################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/at25df641/at25df641.c 

OBJS += \
./drivers/at25df641/at25df641.o 

C_DEPS += \
./drivers/at25df641/at25df641.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/at25df641/%.o: ../drivers/at25df641/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -I../hal -I../hal/CortexM3 -I../hal/CortexM3/GNU -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


