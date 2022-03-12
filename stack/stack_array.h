/**
 * @file stack_array.h
 * @date 2022-03-12
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Stack of array ADT
 */

#ifndef _DSAA_STACK_ARRSY_H
#define DSAA_STACK_ARRSY_H

#include <stdbool.h>

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

Stack StackInit(const int max_element);
bool StackIsEmpty(const Stack stack);
bool StackIsFull(const Stack stack);
void StackEmpty(Stack stack);
void StackPush(Stack stack, ElementType element);
void StackPop(Stack stack);
void StackDispose(Stack stack);
ElementType StackTop(const Stack stack);
ElementType StackTopAndPop(Stack stack);

#endif // DSAA_STACK_ARRSY_H