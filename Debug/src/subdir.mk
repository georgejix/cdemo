################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/fushu.cpp \
../src/main.cpp \
../src/myString.cpp \
../src/nvGui1.cpp \
../src/nvGui2.cpp 

C_SRCS += \
../src/test.c 

OBJS += \
./src/fushu.o \
./src/main.o \
./src/myString.o \
./src/nvGui1.o \
./src/nvGui2.o \
./src/test.o 

CPP_DEPS += \
./src/fushu.d \
./src/main.d \
./src/myString.d \
./src/nvGui1.d \
./src/nvGui2.d 

C_DEPS += \
./src/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


