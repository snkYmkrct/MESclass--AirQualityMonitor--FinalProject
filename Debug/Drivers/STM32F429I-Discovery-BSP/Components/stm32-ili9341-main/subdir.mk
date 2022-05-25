################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/ili9341.c 

C_DEPS += \
./Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/ili9341.d 

OBJS += \
./Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/ili9341.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/%.o Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/%.su: ../Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/%.c Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Console" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/Aiq_PMSA003I_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/stm32-stmpe811-main" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/Common" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F429I-2d-Discovery-2d-BSP-2f-Components-2f-stm32-2d-ili9341-2d-main

clean-Drivers-2f-STM32F429I-2d-Discovery-2d-BSP-2f-Components-2f-stm32-2d-ili9341-2d-main:
	-$(RM) ./Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/ili9341.d ./Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/ili9341.o ./Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main/ili9341.su

.PHONY: clean-Drivers-2f-STM32F429I-2d-Discovery-2d-BSP-2f-Components-2f-stm32-2d-ili9341-2d-main

