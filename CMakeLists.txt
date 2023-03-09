cmake_minimum_required(VERSION 3.20)

project(dsa C)

set(CMAKE_C_STANDARD 11)
set( EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set( LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

enable_testing()

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/test)
