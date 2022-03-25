/**
 * @file d_list.c
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 实现双链表
 */

#include <stdio.h>
#include <stdlib.h>
#include "d_list.h"

struct node {
	Item item;
	struct node *next;
	struct node *prev;
};

/**
 * 初始化链表
 */
void list_init(List *pl)
{
	*pl = NULL;
}

/**
 * 向链表末尾添加一个节点
 */
void list_append(List *pl, const Item *pi)
{
	Node *pn_new = (Node *)malloc(sizeof(Node));

	if (pn_new == NULL) {
		puts("内存不足，无法添加节点！");
		return;
	}

	pn_new->item = *pi;
	pn_new->next = NULL;

	if (*pl == NULL) {
		pn_new->prev = NULL;
		*pl = pn_new;
	} else {
		Node *pn = *pl;
		while (pn->next != NULL)
			pn = pn->next;
		pn->next = pn_new;
		pn_new->prev = pn;
	}
	puts("添加节点成功！");
}

/**
 * 删除指定节点
 */
void list_delete(List *pl, const Item *pi)
{
	// 删除头节点
	if ((*pl)->item == *pi) {
		if (list_count(*pl) == 1) {
			free(*pl);
			*pl = NULL;
		} else {
			List head = (*pl)->next;
			head->prev = NULL;
			free(*pl);
			// 重新设置表头
			*pl = head;
		}
	} else {
		Node *pn = *pl;
		while (pn->item != *pi)
			pn = pn->next;
		pn->prev->next = pn->next;
		pn->next->prev = pn->prev;
		free(pn);
	}
	puts("删除节点成功！");
}

/**
 * 向链表的指定位置处插入节点
 */
void list_insert(List list, const Item *pi, const Item *pos)
{
	Node *pn = list;
	Node *pn_new = (Node *)malloc(sizeof(Node));

	pn_new->item = *pi;

	while (pn->item != *pos)
		pn = pn->next;

	// 先改变新节点，再改变旧节点
	pn_new->prev = pn;
	pn_new->next = pn->next;
	// 如果pn为最后一个节点，则不用考虑下一个节点的prev
	if (pn->next != NULL)
		pn->next->prev = pn_new;
	pn->next = pn_new;
}

/**
 * 清空链表
 */
void list_clean(List *pl)
{
	Node *pn = *pl;
	Node *pn_save;

	while (pn != NULL) {
		pn_save = pn->next;
		free(pn);
		pn = pn_save;
	}
	puts("清空链表成功！");
}

/**
 * 统计链表的节点数
 */
unsigned int list_count(List list)
{
	Node *pn = list;
	unsigned int count = 0;

	while (pn != NULL) {
		pn = pn->next;
		count++;
	}

	return count;
}

/**
 * 查找指定元素并返回
 */
Item *list_search(List list, const Item *pi)
{
	Node *pn = list;

	while ((pn != NULL) && (pn->item != *pi))
		pn = pn->next;

	return &pn->item;
}

/**
 * 将指定的函数作用与列表的每一个节点
 */
void list_for_each (List list, void (*pf)(Item *))
{
	Node *pn = list;

	while (pn != NULL) {
		(*pf)(&pn->item);
		pn = pn->next;
	}
}