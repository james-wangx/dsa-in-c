/**
 * @file infix2postfix.c
 * @date 2022-03-16
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Stack application: transform infix expressions to postfix.
 */

#include <stdio.h>
#include <stdlib.h>

// Don't output any errors about the stack, such as 'Stacks is empty.'
#define hide_error

#include "stack.h"

#define max_element 20

int main(void)
{
	// char *infix = "a+b*c+(d*e+f)*g";
	char *infix = "a+b*c+(d+e*f)*g";

	Stack stack = StackInit(max_element);

	while (*infix != '\0') {
		switch (*infix) {
		case '+':
			//Never pop '(' from the stack, except when processing ')'
			while (!StackIsEmpty(stack) & StackTop(stack) != '(')
				putc(StackTopAndPop(stack), stdout);
			StackPush(stack, '+');
			break;
		case '*':
			//Can't pop '+' and '(', only '*'
			if (StackTop(stack) == '*')
				putc(StackTopAndPop(stack), stdout);
			StackPush(stack, '*');
			break;
		case '(':
			// Highest priority, push it directly
			StackPush(stack, '(');
			break;
		case ')':
			// Pop all operators untill find '('
			// Pop '(', but don't output
			char temp;
			while ((temp = StackTopAndPop(stack)) != '(')
				putc(temp, stdout);
			break;
		default:
			putc(*infix, stdout);
		}
		infix++;
	}

	// Pop all operators
	while (!StackIsEmpty(stack))
		putc(StackTopAndPop(stack), stdout);

	StackDispose(stack);

	return EXIT_SUCCESS;
}
