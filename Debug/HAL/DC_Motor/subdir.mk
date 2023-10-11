################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/DC_Motor/DC_Motor.c 

OBJS += \
./HAL/DC_Motor/DC_Motor.o 

C_DEPS += \
./HAL/DC_Motor/DC_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/DC_Motor/%.o HAL/DC_Motor/%.su HAL/DC_Motor/%.cyclo: ../HAL/DC_Motor/%.c HAL/DC_Motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/hp/Desktop/NTI/Auto Parking_Final Update/HAL/UltraSonic" -I"C:/Users/hp/Desktop/NTI/Auto Parking_Final Update/HAL/DC_Motor" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-DC_Motor

clean-HAL-2f-DC_Motor:
	-$(RM) ./HAL/DC_Motor/DC_Motor.cyclo ./HAL/DC_Motor/DC_Motor.d ./HAL/DC_Motor/DC_Motor.o ./HAL/DC_Motor/DC_Motor.su

.PHONY: clean-HAL-2f-DC_Motor

