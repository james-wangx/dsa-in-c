cmake_minimum_required(VERSION 3.19)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(C/list)

add_executable(DataStructure
        C/list/splist.c
        C/list/splist.h
        demo/choicek1.c
        demo/choicek2.c)
