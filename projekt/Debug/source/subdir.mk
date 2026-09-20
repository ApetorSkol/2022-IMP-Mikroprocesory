################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/skuska.c 

C_DEPS += \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/skuska.d 

OBJS += \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/skuska.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL27Z64VLH4 -DCPU_MKL27Z64VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\board" -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\source" -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\drivers" -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\CMSIS" -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\device" -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\component\serial_manager" -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\component\uart" -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\utilities" -I"C:\Users\matej\Documents\MCUXpressoIDE_11.6.1_8255\workspace\skuska\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/skuska.d ./source/skuska.o

.PHONY: clean-source

