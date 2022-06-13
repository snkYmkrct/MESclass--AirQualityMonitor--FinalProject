################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/BitmapDatabase.cpp \
../TouchGFX/generated/images/src/image_air-pollution_1_mic.cpp \
../TouchGFX/generated/images/src/image_arrow-left_mic.cpp \
../TouchGFX/generated/images/src/image_arrow-right_mic.cpp \
../TouchGFX/generated/images/src/image_background_gray_vertical.cpp \
../TouchGFX/generated/images/src/image_battery_3q_mic.cpp \
../TouchGFX/generated/images/src/image_battery_full_mic.cpp \
../TouchGFX/generated/images/src/image_battery_half_mic.cpp \
../TouchGFX/generated/images/src/image_battery_low_mic.cpp \
../TouchGFX/generated/images/src/image_co2_mic.cpp \
../TouchGFX/generated/images/src/image_humidity_2_mic.cpp \
../TouchGFX/generated/images/src/image_setting_mic.cpp \
../TouchGFX/generated/images/src/image_thermometer_2_mic.cpp 

OBJS += \
./TouchGFX/generated/images/src/BitmapDatabase.o \
./TouchGFX/generated/images/src/image_air-pollution_1_mic.o \
./TouchGFX/generated/images/src/image_arrow-left_mic.o \
./TouchGFX/generated/images/src/image_arrow-right_mic.o \
./TouchGFX/generated/images/src/image_background_gray_vertical.o \
./TouchGFX/generated/images/src/image_battery_3q_mic.o \
./TouchGFX/generated/images/src/image_battery_full_mic.o \
./TouchGFX/generated/images/src/image_battery_half_mic.o \
./TouchGFX/generated/images/src/image_battery_low_mic.o \
./TouchGFX/generated/images/src/image_co2_mic.o \
./TouchGFX/generated/images/src/image_humidity_2_mic.o \
./TouchGFX/generated/images/src/image_setting_mic.o \
./TouchGFX/generated/images/src/image_thermometer_2_mic.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/BitmapDatabase.d \
./TouchGFX/generated/images/src/image_air-pollution_1_mic.d \
./TouchGFX/generated/images/src/image_arrow-left_mic.d \
./TouchGFX/generated/images/src/image_arrow-right_mic.d \
./TouchGFX/generated/images/src/image_background_gray_vertical.d \
./TouchGFX/generated/images/src/image_battery_3q_mic.d \
./TouchGFX/generated/images/src/image_battery_full_mic.d \
./TouchGFX/generated/images/src/image_battery_half_mic.d \
./TouchGFX/generated/images/src/image_battery_low_mic.d \
./TouchGFX/generated/images/src/image_co2_mic.d \
./TouchGFX/generated/images/src/image_humidity_2_mic.d \
./TouchGFX/generated/images/src/image_setting_mic.d \
./TouchGFX/generated/images/src/image_thermometer_2_mic.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/%.o TouchGFX/generated/images/src/%.su: ../TouchGFX/generated/images/src/%.cpp TouchGFX/generated/images/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/Battery_monitor_LC709203F_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/Neopixel" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/RTC_DS3231_i2c" -I../Core/Inc -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/CO2_SCD4x_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Console" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/Aiq_PMSA003I_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/stm32-stmpe811-main" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/Common" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src

clean-TouchGFX-2f-generated-2f-images-2f-src:
	-$(RM) ./TouchGFX/generated/images/src/BitmapDatabase.d ./TouchGFX/generated/images/src/BitmapDatabase.o ./TouchGFX/generated/images/src/BitmapDatabase.su ./TouchGFX/generated/images/src/image_air-pollution_1_mic.d ./TouchGFX/generated/images/src/image_air-pollution_1_mic.o ./TouchGFX/generated/images/src/image_air-pollution_1_mic.su ./TouchGFX/generated/images/src/image_arrow-left_mic.d ./TouchGFX/generated/images/src/image_arrow-left_mic.o ./TouchGFX/generated/images/src/image_arrow-left_mic.su ./TouchGFX/generated/images/src/image_arrow-right_mic.d ./TouchGFX/generated/images/src/image_arrow-right_mic.o ./TouchGFX/generated/images/src/image_arrow-right_mic.su ./TouchGFX/generated/images/src/image_background_gray_vertical.d ./TouchGFX/generated/images/src/image_background_gray_vertical.o ./TouchGFX/generated/images/src/image_background_gray_vertical.su ./TouchGFX/generated/images/src/image_battery_3q_mic.d ./TouchGFX/generated/images/src/image_battery_3q_mic.o ./TouchGFX/generated/images/src/image_battery_3q_mic.su ./TouchGFX/generated/images/src/image_battery_full_mic.d ./TouchGFX/generated/images/src/image_battery_full_mic.o ./TouchGFX/generated/images/src/image_battery_full_mic.su ./TouchGFX/generated/images/src/image_battery_half_mic.d ./TouchGFX/generated/images/src/image_battery_half_mic.o ./TouchGFX/generated/images/src/image_battery_half_mic.su ./TouchGFX/generated/images/src/image_battery_low_mic.d ./TouchGFX/generated/images/src/image_battery_low_mic.o ./TouchGFX/generated/images/src/image_battery_low_mic.su ./TouchGFX/generated/images/src/image_co2_mic.d ./TouchGFX/generated/images/src/image_co2_mic.o ./TouchGFX/generated/images/src/image_co2_mic.su ./TouchGFX/generated/images/src/image_humidity_2_mic.d ./TouchGFX/generated/images/src/image_humidity_2_mic.o ./TouchGFX/generated/images/src/image_humidity_2_mic.su ./TouchGFX/generated/images/src/image_setting_mic.d ./TouchGFX/generated/images/src/image_setting_mic.o ./TouchGFX/generated/images/src/image_setting_mic.su ./TouchGFX/generated/images/src/image_thermometer_2_mic.d ./TouchGFX/generated/images/src/image_thermometer_2_mic.o ./TouchGFX/generated/images/src/image_thermometer_2_mic.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src

