################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/App/TheApp/TheApp.c 

OBJS += \
./Source/App/TheApp/TheApp.o 

C_DEPS += \
./Source/App/TheApp/TheApp.d 


# Each subdirectory must supply rules for building sources it contributes
Source/App/TheApp/TheApp.o: ../Source/App/TheApp/TheApp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/App/TheApp" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Cdd/Led" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Cdd/VirtulComPort" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Services/Kernel" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Services/SchM" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Utils/CircularFIFOBuffer" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Utils" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Common" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Inlude" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Source/App/TheApp/TheApp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

