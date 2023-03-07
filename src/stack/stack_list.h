/**
 * @file stack_list.h
 * @date 2022-03-12
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Stack of single linked list ADT
 */

#ifndef _DSAA_STACK_LIST_H
#define _DSAA_STACK_LIST_H

#include <stdbool.h>

struct node;
typedef struct node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

Stack StackInit(void);
bool StackIsEmpty(const Stack stack);
void StackEmpty(Stack stack);
void StackPush(Stack stack, const ElementType element);
void StackPop(Stack stack);
ElementType StackTop(const Stack stack);

#endif // _DSAA_STACK_LIST_H
