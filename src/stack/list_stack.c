/**
 * @file list_stack.c
 * @date 2023-03-13
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Simulating stack with linked list
 */
#include <stdio.h>
#include <stdlib.h>

#include "stack/list_stack.h"


Stack stack_init(int size) {
    Stack stack = (Stack) malloc(sizeof(struct ListStack));
    stack->max_size = size;
    stack->size = 0;

    return stack;
}


inline int stack_is_empty(Stack stack) {
    return stack->next == NULL;
}


int stack_is_full(Stack stack) {
    return stack_size(stack) == stack->max_size;
}


int stack_push(Stack stack, ElementType ele) {
    if (stack_is_full(stack)) {
        fprintf(stderr, "Stack is full!\n");
        return -1;
    }

    Stack node = (Stack) malloc(sizeof(struct ListStack));
    node->ele = ele;
    stack->size++;
    if (stack_is_empty(stack)) {
        stack->next = node;
        return 0;
    }

    Stack top = stack->next;
    node->next = top;
    stack->next = node;

    return 0;
}


ElementType stack_pop(Stack stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty!\n");
        return -1;
    }

    Stack top = stack->next;
    ElementType ele = top->ele;
    stack->next = top->next;
    free(top);
    stack->size--;

    return ele;
}


ElementType stack_peek(Stack stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty!\n");
        return -1;
    }

    ElementType ele = stack->next->ele;

    return ele;
}


inline int stack_size(Stack stack) {
    return stack->size;
}


int stack_clear(Stack stack) {
    Stack top = stack->next;

    while (top != NULL) {
        Stack next = top->next;
        free(top);
        top = next;
    }

    return 0;
}
