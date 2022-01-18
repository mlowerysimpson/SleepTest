cmake_minimum_required(VERSION 2.8)
project(SleepTest)
# Locate libraries and headers
find_library(wiringPi_LIB wiringPi)
find_package(Threads REQUIRED)

# Include headers
include_directories(${WIRINGPI_INCLUDE_DIRS}) 
include_directories("../RemoteControlTest")

#the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "./*.cpp")
add_executable(SleepTest ${SOURCES} "../RemoteControlTest/DiagnosticsSensor.cpp" "../RemoteControlTest/Util.cpp" "../RemoteControlTest/Sensor.cpp" "../RemoteControlTest/HumiditySensor.cpp" "../RemoteControlTest/Util.cpp" "../RemoteControlTest/AToD.cpp" "../RemoteControlTest/ShipLog.cpp" "../RemoteControlTest/BatteryCharge.cpp" "../RemoteControlTest/CommandList.cpp" "../RemoteControlTest/filedata.cpp")

# Link against libraries
target_link_libraries(SleepTest ${wiringPi_LIB} )
target_link_libraries(SleepTest ${CMAKE_THREAD_LIBS_INIT})


