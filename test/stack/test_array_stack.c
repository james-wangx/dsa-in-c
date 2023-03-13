/**
 * @file array_stack.c
 * @date 2023-03-13
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Test array stack
 */
#include <assert.h>

#include "stack/array_stack.h"

#define MAX_SIZE 10


Stack stack;


Stack test_stack_init(void) {
    stack = stack_init(MAX_SIZE);
    assert(stack->top == -1);
    assert(stack->max_size == MAX_SIZE);

    return stack;
}


void test_stack_push(void) {
    for (int i = 1; i <= MAX_SIZE; ++i)
        assert(stack_push(stack, i * 10) == 0);
    assert(stack_push(stack, 1) == -1);
    assert(stack_size(stack) == MAX_SIZE);
}


void test_stack_pop(void) {
    for (int i = 10; i >= 1; ++i)
        assert(stack_pop(stack) == i * 10);
    assert(stack_pop(stack) == -1);
    assert(stack_size(stack) == 0);
}


void test_stack_peek(void) {
    stack_push(stack, 1);
    assert(stack_peek(stack) == 1);
    assert(stack_size(stack) == 1);
    stack_pop(stack);
}


void test_stack_clear(void) {
    assert(stack_clear(stack) == 0);
}


int main(void) {
    test_stack_init();
    test_stack_push();
    test_stack_pop();
    test_stack_peek();
    test_stack_clear();

    return 0;
}
