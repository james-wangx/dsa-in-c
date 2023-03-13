add_executable(test_array_stack test_array_stack.c)
add_executable(test_list_stack test_list_stack.c)

target_link_libraries(test_array_stack array_stack)
target_link_libraries(test_list_stack list_stack)

add_test(test_array_stack ${EXECUTABLE_OUTPUT_PATH}/test_array_stack)
add_test(test_list_stack ${EXECUTABLE_OUTPUT_PATH}/test_list_stack)
