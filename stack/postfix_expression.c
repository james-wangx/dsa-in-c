/**
 * @file postfix_expression.c
 * @date 2022-03-16
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Stack application -- postfix expression
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_array.h"

#define max_element 10

int main(void)
{
	Stack stack = StackInit(max_element);
	char expression[] = { '6', '5', '2', '3', '+', '8', '*',
			      '+', '3', '+', '*', '8', '-' };
	int size = sizeof(expression);

	for (int i = 0; i < size; i++) {
		switch (expression[i]) {
		case '+':
			StackPush(stack, StackTopAndPop(stack) +
						 StackTopAndPop(stack));
			continue;
		case '-':
			int subtrahend = StackTopAndPop(stack);
			StackPush(stack, StackTopAndPop(stack) - subtrahend);
			continue;
		case '*':
			StackPush(stack, StackTopAndPop(stack) *
						 StackTopAndPop(stack));
			continue;
		default:
			StackPush(stack, expression[i] - '0');
		}
	}

	printf("The result is: %d.\n", StackTop(stack));

	StackDispose(stack);

	return EXIT_SUCCESS;
}
