/**
 * @file list.h
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 用于基数排序的链表
 */

#ifndef DSAA_LIST_H
#define DSAA_LIST_H

#include <stdbool.h>

typedef struct node {
	int digit;
	struct node *next;
	struct node *prev;
} Node;

typedef struct node *List, *Position;

void ListInit(List head);
void ListAddTail(List head, int digit);
void ListEmpty(List head);

#define ListForEach(head, pos)                                                 \
	for (pos = (head)->next; pos != head; pos = pos->next)

#define ListForEachSafe(head, pos, next)                                       \
	for (pos = (head)->next, next = pos->next; pos != head;                    \
		 pos = next, next = pos->next)

#endif //DSAA_LIST_H
