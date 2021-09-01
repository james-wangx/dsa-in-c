cmake_minimum_required(VERSION 3.16)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)


add_executable(hello C/demo/hello.c)
add_executable(s_list C/list/s_list.h C/list/s_list.c)
add_executable(demo C/demo/demo.c)