/**
 * @file stack.h
 * @date 2022-03-16
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Stack of array
 */

#ifndef _DSAA_STACK_H
#define _DSAA_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define empty_tos (-1)
#define min_stack_size (5)

#define throw_error(str) fprintf(stderr, "%s\n", str)

typedef int ElementType;

struct StackRecord {
	int capacity;
	int top_of_stack;
	ElementType *array;
};

typedef struct StackRecord *Stack;

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
 * @brief Initailize stack
 * 
 * @param max_element 
 * @return Stack 
 */
Stack StackInit(const int max_element)
{
	if (max_element < min_stack_size) {
#ifndef hide_error
		throw_error("Stack size is too small.");
#endif
		exit(EXIT_FAILURE);
	}

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
 * @brief Push a element in stack
 * 
 * @param stack 
 * @param element 
 */
void StackPush(Stack stack, ElementType element)
{
#ifndef hide_error

	if (StackIsFull(stack))
		throw_error("Stack is full.");
	else
#endif

		stack->array[++stack->top_of_stack] = element;
}

/**
 * @brief Pop a element from stack
 * 
 * @param stack 
 */
void StackPop(Stack stack)
{
#ifndef hide_error

	if (StackIsEmpty(stack))
		throw_error("Stack is empty.");
	else
#endif

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
#ifndef hide_error
		throw_error("Stack is empty.");
#endif
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
#ifndef hide_error
		throw_error("Stack is empty.");
#endif
		return 0; // Return value used to avoid warning
	}

	return stack->array[stack->top_of_stack--];
}

#endif // _DSAA_STACK_H
