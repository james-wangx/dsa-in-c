/**
 * @file list.c
 * @date 2022-01-26
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 链表实现
 */

#include <stdlib.h>

#include "list.h"

inline void ListInit(List head)
{
	head->next = head;
	head->prev = head;
}

static inline void __list_add(Position new, Position prev, Position next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

inline void ListAddTail(List head, int digit)
{
	Position new = (struct node *)malloc(sizeof(struct node));
	new->digit = digit;

	__list_add(new, head->prev, head);
}

void ListEmpty(List head)
{
	Position pos = head->next;

	while (pos != head)
	{
		Position next = pos->next;
		free(pos);
		pos = next;
	}
}
