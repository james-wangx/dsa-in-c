cmake_minimum_required(VERSION 3.16)
project(dsaa C)

set(CMAKE_C_STANDARD 11)

add_executable(s_list list/s_list/s_list.c list/s_list/s_list_main.c)
add_executable(d_list list/d_list/d_list.c list/d_list/d_list_main.c)

add_executable(demo demo/demo.c)