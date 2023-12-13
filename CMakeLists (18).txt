cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Lab_ArifmeticList) 
project(${PROJECT_NAME})
 
set(StackLib StackLib)
set(PolishTest PolishTest)
set(PolishLib PolishLib)



set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE) 
 set(CMAKE_BUILD_TYPE Release) 
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
add_subdirectory(StackLib)
add_subdirectory(PolishLib)
add_subdirectory(PolishTest)
add_subdirectory(gtest)
