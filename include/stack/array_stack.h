/**
 * @file array_stack.h
 * @date 2023-03-13
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Simulating stack with array
 */
#ifndef DSA_ARRAY_STACK_H
#define DSA_ARRAY_STACK_H

typedef int ElementType;
typedef struct ArrayStack {
    ElementType *array;
    int top;
    int max_size;
} *Stack;

Stack stack_init(int size);
int stack_is_empty(Stack stack);
int stack_is_full(Stack stack);
int stack_push(Stack stack, ElementType ele);
ElementType stack_pop(Stack stack);
ElementType stack_peek(Stack stack);
int stack_size(Stack stack);
int stack_clear(Stack stack);

#endif // DSA_ARRAY_STACK_H