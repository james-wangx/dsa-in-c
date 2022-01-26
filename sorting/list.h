/**
 * @file list.h
 * @date 2022-01-26
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 用于基数排序的链表
 */

#ifndef DSAA_LIST_H
#define DSAA_LIST_H

#include <stdbool.h>

struct node {
	int digit;
	struct node *next;
	struct node *prev;
} Node;

typedef struct node *List, *Position;

void ListInit(List head);
void ListAddTail(List head, int digit);
void ListEmpty(List head);

#endif //DSAA_LIST_H
