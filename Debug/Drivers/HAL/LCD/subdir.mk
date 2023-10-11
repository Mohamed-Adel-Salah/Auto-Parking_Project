################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/HAL/LCD/LCD_program.c 

OBJS += \
./Drivers/HAL/LCD/LCD_program.o 

C_DEPS += \
./Drivers/HAL/LCD/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL/LCD/%.o Drivers/HAL/LCD/%.su Drivers/HAL/LCD/%.cyclo: ../Drivers/HAL/LCD/%.c Drivers/HAL/LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-HAL-2f-LCD

clean-Drivers-2f-HAL-2f-LCD:
	-$(RM) ./Drivers/HAL/LCD/LCD_program.cyclo ./Drivers/HAL/LCD/LCD_program.d ./Drivers/HAL/LCD/LCD_program.o ./Drivers/HAL/LCD/LCD_program.su

.PHONY: clean-Drivers-2f-HAL-2f-LCD

