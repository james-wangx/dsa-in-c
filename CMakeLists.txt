cmake_minimum_required(VERSION 3.19)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(splist C/list/splist.h C/list/splist.c)
add_executable(list C/list/list.c C/list/list.h)
add_executable(demo C/demo/demo.c)