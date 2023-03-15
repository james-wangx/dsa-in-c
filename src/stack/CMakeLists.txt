add_library(array_stack array_stack.c)

add_library(list_stack list_stack.c)

add_library(infix_exp_calc infix_exp_calc.c)
target_link_libraries(infix_exp_calc list_stack)
