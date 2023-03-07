/**
 * @file stack_list.c
 * @date 2022-03-12
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief The implementaion of stack_list.h
 */

#include "stdio.h"
#include "stdlib.h"

#include "stack_list.h"

// Stack implementaion is a single linked list with a header
typedef struct node {
	ElementType element;
	PtrToNode next;
} Node;

/**
 * @brief Create a empty stack
 * 
 * @return Stack 
 */
Stack StackInit(void)
{
	Stack stack = malloc(sizeof(Node));
	stack->next = NULL;

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
	return stack->next == NULL;
}

/**
 * @brief Make stack empty
 * 
 * @param stack 
 */
void StackEmpty(Stack stack)
{
	if (stack == NULL)
		fprintf(stderr, "Must use StackInit first.");
	else
		while (!StackIsEmpty(stack))
			StackPop(stack);
}

/**
 * @brief Push a emlement in stack
 * 
 * @param stack 
 * @param element 
 */
void StackPush(Stack stack, const ElementType element)
{
	PtrToNode temp = malloc(sizeof(Node));
	temp->element = element;
	temp->next = stack->next;
	stack->next = temp;
}

/**
 * @brief Pop a element from stack
 * 
 * @param stack 
 */
void StackPop(Stack stack)
{
	if (StackIsEmpty(stack)) {
		fprintf(stderr, "Stack is empty.");
		return;
	}

	PtrToNode temp = stack->next;
	stack->next = temp->next;
	free(temp);
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
		fprintf(stderr, "Stack is empty.");
		return 0; // Return value used to avoid warning
	}

	return stack->next->element;
}
