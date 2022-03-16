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
	char *expression = "6523+8*+3+*8-";

	while (*expression != '\0') {
		switch (*expression) {
		case '+':
			StackPush(stack, StackTopAndPop(stack) +
						 StackTopAndPop(stack));
			break;
		case '-':
			int subtrahend = StackTopAndPop(stack);
			StackPush(stack, StackTopAndPop(stack) - subtrahend);
			break;
		case '*':
			StackPush(stack, StackTopAndPop(stack) *
						 StackTopAndPop(stack));
			break;
		default:
			StackPush(stack, *expression - '0');
		}
		expression++;
	}

	printf("The result is: %d.\n", StackTop(stack));

	StackDispose(stack);

	return EXIT_SUCCESS;
}
