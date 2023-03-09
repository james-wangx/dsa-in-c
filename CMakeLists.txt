cmake_minimum_required(VERSION 3.20)

project(dsa C)

set(CMAKE_C_STANDARD 11)
set( EXECUTABLE_OUTPUT_PATH bin)
set( LIBRARY_OUTPUT_PATH lib)

include_directories(include)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
