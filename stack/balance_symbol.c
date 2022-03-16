/**
 * @file balance_symbol.c
 * @date 2022-03-16
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Stack application -- balance symbol
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack_array.h"

#define max_element 20

#define fatal_error(str) fprintf(stderr, "%s\n", str), exit(EXIT_FAILURE)

int main(void)
{
	FILE *file;
	int ch;
	char *file_path =
		"/home/pineapple/codes/c-project/dsaa/stack/balance_symbol.txt";

	if ((file = fopen(file_path, "r")) == NULL)
		fatal_error("File is not exist!");

	Stack stack = StackInit(max_element);

	// Traverse file characters
	while ((ch = getc(file)) != EOF) {
		if (ch == '{' || ch == '[' || ch == '(')
			StackPush(stack, ch);
		else {
			int top = StackTop(stack);
			int sum = top + ch;
			// '(' + ')' = 81, '[' + ']' = 184, '{' + '}' = 248
			if (sum == 81 || sum == 184 || sum == 248)
				StackPop(stack);
			else
				throw_error("Error, symbol is not balance.");
		}
	}

	if (!StackIsEmpty(stack))
		throw_error("Error, stack is not empty.");

	StackDispose(stack);
	fclose(file);

	return EXIT_SUCCESS;
}
