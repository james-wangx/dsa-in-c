cmake_minimum_required(VERSION 3.15)
project(dsaa C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(list)

add_executable(linked_list list/list.c)

add_executable(test test.c)

add_executable(selection_sort sorting/selection_sort.c)
add_executable(bubble_sort sorting/bubble_sort.c)
