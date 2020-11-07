################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_DEVICE/Target/subdir.mk
-include USB_DEVICE/App/subdir.mk
-include Source/Utils/CircularFIFOBuffer/subdir.mk
-include Source/Utils/subdir.mk
-include Source/Services/SchM/subdir.mk
-include Source/Services/Kernel/subdir.mk
-include Source/Cdd/VirtulComPort/subdir.mk
-include Source/Cdd/Led/subdir.mk
-include Source/App/TheApp/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ControlSocketViaUSB.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ControlSocketViaUSB.list \

OBJCOPY_BIN += \
ControlSocketViaUSB.bin \


# All Target
all: ControlSocketViaUSB.elf secondary-outputs

# Tool invocations
ControlSocketViaUSB.elf: $(OBJS) $(USER_OBJS) D:\oleg\Repositories\ControlSocketViaUSB\Software\EmbeddedSoft\ControlSocketViaUSB\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "ControlSocketViaUSB.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\oleg\Repositories\ControlSocketViaUSB\Software\EmbeddedSoft\ControlSocketViaUSB\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ControlSocketViaUSB.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ControlSocketViaUSB.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ControlSocketViaUSB.list"
	@echo 'Finished building: $@'
	@echo ' '

ControlSocketViaUSB.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ControlSocketViaUSB.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
