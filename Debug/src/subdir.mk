################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/C/STM32/Ethernet/src/EtherShield.c \
D:/C/STM32/Ethernet/src/dhcp.c \
D:/C/STM32/Ethernet/src/dnslkup.c \
D:/C/STM32/Ethernet/src/enc28j60.c \
D:/C/STM32/Ethernet/src/ip_arp_udp_tcp.c \
D:/C/STM32/Ethernet/src/websrv_help_functions.c 

OBJS += \
./src/EtherShield.o \
./src/dhcp.o \
./src/dnslkup.o \
./src/enc28j60.o \
./src/ip_arp_udp_tcp.o \
./src/websrv_help_functions.o 

C_DEPS += \
./src/EtherShield.d \
./src/dhcp.d \
./src/dnslkup.d \
./src/enc28j60.d \
./src/ip_arp_udp_tcp.d \
./src/websrv_help_functions.d 


# Each subdirectory must supply rules for building sources it contributes
src/EtherShield.o: D:/C/STM32/Ethernet/src/EtherShield.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/C/STM32/Ethernet/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/dhcp.o: D:/C/STM32/Ethernet/src/dhcp.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/C/STM32/Ethernet/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/dnslkup.o: D:/C/STM32/Ethernet/src/dnslkup.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/C/STM32/Ethernet/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/enc28j60.o: D:/C/STM32/Ethernet/src/enc28j60.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/C/STM32/Ethernet/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/ip_arp_udp_tcp.o: D:/C/STM32/Ethernet/src/ip_arp_udp_tcp.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/C/STM32/Ethernet/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/websrv_help_functions.o: D:/C/STM32/Ethernet/src/websrv_help_functions.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/C/STM32/Ethernet/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/EtherShield.cyclo ./src/EtherShield.d ./src/EtherShield.o ./src/EtherShield.su ./src/dhcp.cyclo ./src/dhcp.d ./src/dhcp.o ./src/dhcp.su ./src/dnslkup.cyclo ./src/dnslkup.d ./src/dnslkup.o ./src/dnslkup.su ./src/enc28j60.cyclo ./src/enc28j60.d ./src/enc28j60.o ./src/enc28j60.su ./src/ip_arp_udp_tcp.cyclo ./src/ip_arp_udp_tcp.d ./src/ip_arp_udp_tcp.o ./src/ip_arp_udp_tcp.su ./src/websrv_help_functions.cyclo ./src/websrv_help_functions.d ./src/websrv_help_functions.o ./src/websrv_help_functions.su

.PHONY: clean-src

