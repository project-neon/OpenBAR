################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/aruco.cpp \
../src/detect_markers.cpp \
../src/dictionary.cpp 

OBJS += \
./src/aruco.o \
./src/detect_markers.o \
./src/dictionary.o 

CPP_DEPS += \
./src/aruco.d \
./src/detect_markers.d \
./src/dictionary.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/local/include/opencv2 -I/usr/local/include/aruco -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


