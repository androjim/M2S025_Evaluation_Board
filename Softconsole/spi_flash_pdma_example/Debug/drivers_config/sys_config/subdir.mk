################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers_config/sys_config/sys_config.c \
../drivers_config/sys_config/sys_config_SERDESIF_0.c 

OBJS += \
./drivers_config/sys_config/sys_config.o \
./drivers_config/sys_config/sys_config_SERDESIF_0.o 

C_DEPS += \
./drivers_config/sys_config/sys_config.d \
./drivers_config/sys_config/sys_config_SERDESIF_0.d 


# Each subdirectory must supply rules for building sources it contributes
drivers_config/sys_config/%.o: ../drivers_config/sys_config/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -I../hal -I../hal/CortexM3 -I../hal/CortexM3/GNU -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


