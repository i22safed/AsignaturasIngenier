################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Agenda.cpp \
../Cliente.cpp \
../Fichero.cpp \
../Menu.cpp \
../main.cpp 

OBJS += \
./Agenda.o \
./Cliente.o \
./Fichero.o \
./Menu.o \
./main.o 

CPP_DEPS += \
./Agenda.d \
./Cliente.d \
./Fichero.d \
./Menu.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


