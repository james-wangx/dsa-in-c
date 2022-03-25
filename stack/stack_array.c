/**
 * @file stack_array.c
 * @date 2022-03-12
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief The implementation of stack_array.h
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack_array.h"

// Stack implementation is a dynamically allocated array
#define empty_tos	   (-1)
#define min_stack_size (5)

struct StackRecord {
	int capacity;
	int top_of_stack;
	ElementType *array;
};

/**
 * @brief Initailize stack
 * 
 * @param max_element 
 * @return Stack 
 */
Stack StackInit(const int max_element)
{
	if (max_element < min_stack_size)
		throw_error("Stack size is too small.");

	Stack stack = malloc(sizeof(struct StackRecord));
	stack->array = malloc(sizeof(ElementType) * max_element);
	stack->capacity = max_element;
	StackEmpty(stack);

	return stack;
}

/**
 * @brief Return true if stack is empty
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool StackIsEmpty(const Stack stack)
{
	return stack->top_of_stack == empty_tos;
}

/**
 * @brief Return true if stack is full
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool StackIsFull(const Stack stack)
{
	return stack->top_of_stack == stack->capacity - 1;
}

/**
 * @brief Make stack empty
 * 
 * @param stack 
 */
void StackEmpty(Stack stack)
{
	stack->top_of_stack = empty_tos;
}

/**
 * @brief Push a element in stack
 * 
 * @param stack 
 * @param element 
 */
void StackPush(Stack stack, ElementType element)
{
	if (StackIsFull(stack))
		throw_error("Stack is full.");
	else
		stack->array[++stack->top_of_stack] = element;
}

/**
 * @brief Pop a element from stack
 * 
 * @param stack 
 */
void StackPop(Stack stack)
{
	if (StackIsEmpty(stack))
		throw_error("Stack is empty.");
	else
		stack->top_of_stack--;
}

/**
 * @brief Dispose stack
 * 
 * @param stack 
 */
void StackDispose(Stack stack)
{
	if (stack != NULL) {
		free(stack->array);
		free(stack);
	}
}

/**
 * @brief Find top element of stack
 * 
 * @param stack 
 * @return ElementType 
 */
ElementType StackTop(const Stack stack)
{
	if (StackIsEmpty(stack)) {
		throw_error("Stack is empty.");
		return 0; // Return value used to avoid warning
	}

	return stack->array[stack->top_of_stack];
}

/**
 * @brief Find top element of stack and pop it
 * 
 * @param stack 
 * @return ElementType 
 */
ElementType StackTopAndPop(Stack stack)
{
	if (StackIsEmpty(stack)) {
		throw_error("Stack is empty.");
		return 0; // Return value used to avoid warning
	}

	return stack->array[stack->top_of_stack--];
}
