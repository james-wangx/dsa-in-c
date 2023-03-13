/**
 * @file list_stack.h
 * @date 2023-03-13
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Simulating stack with linked list
 */
#ifndef DSA_LIST_STACK_H
#define DSA_LIST_STACK_H

typedef int ElementType;
typedef struct ListStack {
    ElementType ele;
    struct ListStack *next;
    int max_size;
    int size;
} *Stack;

Stack stack_init(int size);
int stack_is_empty(Stack stack);
int stack_is_full(Stack stack);
int stack_push(Stack stack, ElementType ele);
ElementType stack_pop(Stack stack);
ElementType stack_peek(Stack stack);
int stack_size(Stack stack);
int stack_clear(Stack stack);

#endif // DSA_LIST_STACK_H