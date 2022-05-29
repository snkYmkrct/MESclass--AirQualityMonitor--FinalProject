################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/fonts/src/ApplicationFontProvider.cpp \
../TouchGFX/generated/fonts/src/CachedFont.cpp \
../TouchGFX/generated/fonts/src/FontCache.cpp \
../TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.cpp \
../TouchGFX/generated/fonts/src/Font_verdana_15_4bpp_0.cpp \
../TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.cpp \
../TouchGFX/generated/fonts/src/GeneratedFont.cpp \
../TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.cpp \
../TouchGFX/generated/fonts/src/Kerning_verdana_15_4bpp.cpp \
../TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.cpp \
../TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.cpp \
../TouchGFX/generated/fonts/src/Table_verdana_15_4bpp.cpp \
../TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.cpp \
../TouchGFX/generated/fonts/src/UnmappedDataFont.cpp 

OBJS += \
./TouchGFX/generated/fonts/src/ApplicationFontProvider.o \
./TouchGFX/generated/fonts/src/CachedFont.o \
./TouchGFX/generated/fonts/src/FontCache.o \
./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.o \
./TouchGFX/generated/fonts/src/Font_verdana_15_4bpp_0.o \
./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.o \
./TouchGFX/generated/fonts/src/GeneratedFont.o \
./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.o \
./TouchGFX/generated/fonts/src/Kerning_verdana_15_4bpp.o \
./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.o \
./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.o \
./TouchGFX/generated/fonts/src/Table_verdana_15_4bpp.o \
./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.o \
./TouchGFX/generated/fonts/src/UnmappedDataFont.o 

CPP_DEPS += \
./TouchGFX/generated/fonts/src/ApplicationFontProvider.d \
./TouchGFX/generated/fonts/src/CachedFont.d \
./TouchGFX/generated/fonts/src/FontCache.d \
./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.d \
./TouchGFX/generated/fonts/src/Font_verdana_15_4bpp_0.d \
./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.d \
./TouchGFX/generated/fonts/src/GeneratedFont.d \
./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.d \
./TouchGFX/generated/fonts/src/Kerning_verdana_15_4bpp.d \
./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.d \
./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.d \
./TouchGFX/generated/fonts/src/Table_verdana_15_4bpp.d \
./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.d \
./TouchGFX/generated/fonts/src/UnmappedDataFont.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/fonts/src/%.o TouchGFX/generated/fonts/src/%.su: ../TouchGFX/generated/fonts/src/%.cpp TouchGFX/generated/fonts/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/CO2_SCD4x_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/Battery_monitor_LC709203F" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Console" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Core/Inc/Peripherals/Aiq_PMSA003I_i2c" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/stm32-stmpe811-main" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/Common" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components/stm32-ili9341-main" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP" -I"C:/Users/silvi/STM32CubeIDE/workspace_1.9.0/AirQualityMonitor__MES__Final_Project/Drivers/STM32F429I-Discovery-BSP/Components" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-fonts-2f-src

clean-TouchGFX-2f-generated-2f-fonts-2f-src:
	-$(RM) ./TouchGFX/generated/fonts/src/ApplicationFontProvider.d ./TouchGFX/generated/fonts/src/ApplicationFontProvider.o ./TouchGFX/generated/fonts/src/ApplicationFontProvider.su ./TouchGFX/generated/fonts/src/CachedFont.d ./TouchGFX/generated/fonts/src/CachedFont.o ./TouchGFX/generated/fonts/src/CachedFont.su ./TouchGFX/generated/fonts/src/FontCache.d ./TouchGFX/generated/fonts/src/FontCache.o ./TouchGFX/generated/fonts/src/FontCache.su ./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.d ./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.o ./TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.su ./TouchGFX/generated/fonts/src/Font_verdana_15_4bpp_0.d ./TouchGFX/generated/fonts/src/Font_verdana_15_4bpp_0.o ./TouchGFX/generated/fonts/src/Font_verdana_15_4bpp_0.su ./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.d ./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.o ./TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.su ./TouchGFX/generated/fonts/src/GeneratedFont.d ./TouchGFX/generated/fonts/src/GeneratedFont.o ./TouchGFX/generated/fonts/src/GeneratedFont.su ./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.d ./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.o ./TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.su ./TouchGFX/generated/fonts/src/Kerning_verdana_15_4bpp.d ./TouchGFX/generated/fonts/src/Kerning_verdana_15_4bpp.o ./TouchGFX/generated/fonts/src/Kerning_verdana_15_4bpp.su ./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.d ./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.o ./TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.su ./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.d ./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.o ./TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.su ./TouchGFX/generated/fonts/src/Table_verdana_15_4bpp.d ./TouchGFX/generated/fonts/src/Table_verdana_15_4bpp.o ./TouchGFX/generated/fonts/src/Table_verdana_15_4bpp.su ./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.d ./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.o ./TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.su ./TouchGFX/generated/fonts/src/UnmappedDataFont.d ./TouchGFX/generated/fonts/src/UnmappedDataFont.o ./TouchGFX/generated/fonts/src/UnmappedDataFont.su

.PHONY: clean-TouchGFX-2f-generated-2f-fonts-2f-src

