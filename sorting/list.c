/**
 * @file list.c
 * @date 2022-01-26
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 链表实现
 */

#include <stdlib.h>

#include "list.h"

/**
 * @brief 初始化链表
 *
 * @param head 待初始化的链表头
 */
inline void ListInit(List head)
{
	head->next = head;
	head->prev = head;
}

/**
 * @brief 向链表中添加元素，此函数为内部函数，近在此文件使用
 *
 * @param new 新元素
 * @param prev 新元素的前驱
 * @param next 新元素的后继
 */
static inline void __list_add(Position new, Position prev, Position next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

/**
 * @brief 尾插法插入元素
 *
 * @param head 待插入的链表头
 * @param digit 待插入的数值
 */
inline void ListAddTail(List head, int digit)
{
	Position new = (struct node *)malloc(sizeof(struct node));
	new->digit = digit;

	__list_add(new, head->prev, head);
}

/**
 * @brief 清空链表，释放内存（不是仅做摘链的操作）
 *
 * @param head 待清空的链表的头
 */
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
