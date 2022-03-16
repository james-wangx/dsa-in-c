cmake_minimum_required(VERSION 3.15)

project(dsaa C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(list)
add_subdirectory(sorting)
add_subdirectory(stack)

add_executable(test test.c)
