/**
 * @file array_stack.c
 * @date 2023-03-13
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Simulating stack with array
 */
#include <stdio.h>
#include <stdlib.h>

#include "stack/array_stack.h"


Stack stack_init(int size) {
    Stack stack = (Stack) malloc(sizeof(struct ArrayStack));
    stack->array = (ElementType *) malloc(sizeof(ElementType) * size);
    stack->top = -1;
    stack->max_size = size;

    return stack;
}


inline int stack_is_empty(Stack stack) {
    return stack->top == -1;
}


inline int stack_is_full(Stack stack) {
    return stack->top + 1 == stack->max_size;
}


int stack_push(Stack stack, ElementType ele) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "Stack is full!\n");
        return -1;
    }

    stack->array[++stack->top] = ele;

    return 0;
}


ElementType stack_pop(Stack stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }

    return stack->array[stack->top--];
}


ElementType stack_peek(Stack stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }

    return stack->array[stack->top];
}


inline int stack_size(Stack stack) {
    return stack->top + 1;
}


int stack_clear(Stack stack) {
    free(stack->array);
    free(stack);

    return 0;
}
