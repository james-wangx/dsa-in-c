cmake_minimum_required(VERSION 3.20)

project(dsa C)

set(CMAKE_C_STANDARD 11)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
