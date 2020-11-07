################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/Cdd/VirtulComPort/VirtualComPort.c 

OBJS += \
./Source/Cdd/VirtulComPort/VirtualComPort.o 

C_DEPS += \
./Source/Cdd/VirtulComPort/VirtualComPort.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Cdd/VirtulComPort/VirtualComPort.o: ../Source/Cdd/VirtulComPort/VirtualComPort.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/App/TheApp" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Cdd/Led" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Cdd/VirtulComPort" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Services/Kernel" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Services/SchM" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Utils/CircularFIFOBuffer" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Utils" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Common" -I"D:/oleg/Repositories/ControlSocketViaUSB/Software/EmbeddedSoft/ControlSocketViaUSB/Source/Inlude" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Source/Cdd/VirtulComPort/VirtualComPort.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

