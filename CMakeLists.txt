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

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
add_subdirectory(StackLib)
add_subdirectory(PolishLib)
add_subdirectory(PolishTest)
add_subdirectory(gtest)
