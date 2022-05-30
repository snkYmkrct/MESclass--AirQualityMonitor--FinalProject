################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Peripherals/CO2_SCD4x_i2c/scd4x_i2c.c \
../Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_common.c \
../Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c.c \
../Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c_hal.c 

C_DEPS += \
./Core/Src/Peripherals/CO2_SCD4x_i2c/scd4x_i2c.d \
./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_common.d \
./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c.d \
./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c_hal.d 

OBJS += \
./Core/Src/Peripherals/CO2_SCD4x_i2c/scd4x_i2c.o \
./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_common.o \
./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c.o \
./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c_hal.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Peripherals/CO2_SCD4x_i2c/%.o Core/Src/Peripherals/CO2_SCD4x_i2c/%.su: ../Core/Src/Peripherals/CO2_SCD4x_i2c/%.c Core/Src/Peripherals/CO2_SCD4x_i2c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/Battery_monitor_LC709203F_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/RTC_DS3231_i2c" -I../Core/Inc -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/CO2_SCD4x_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Console" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/Aiq_PMSA003I_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/stm32-stmpe811-main" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/Common" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Peripherals-2f-CO2_SCD4x_i2c

clean-Core-2f-Src-2f-Peripherals-2f-CO2_SCD4x_i2c:
	-$(RM) ./Core/Src/Peripherals/CO2_SCD4x_i2c/scd4x_i2c.d ./Core/Src/Peripherals/CO2_SCD4x_i2c/scd4x_i2c.o ./Core/Src/Peripherals/CO2_SCD4x_i2c/scd4x_i2c.su ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_common.d ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_common.o ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_common.su ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c.d ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c.o ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c.su ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c_hal.d ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c_hal.o ./Core/Src/Peripherals/CO2_SCD4x_i2c/sensirion_i2c_hal.su

.PHONY: clean-Core-2f-Src-2f-Peripherals-2f-CO2_SCD4x_i2c

