// s_list.c - 2021年 八月 30日
// 最简单的单向链表

#ifndef S_LIST_H_
#define S_LIST_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE 50
#define MAX_AUTHOR 50

/**
 * 书籍结构
 */
struct book {
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	double price;
};

typedef struct book Item;

/**
 * 链表的节点
 */
typedef struct node {
	Item item;
	struct node *next;
} Node;

typedef Node *List;

/**
 * 初始化链表为空
 * @param pl 链表指针
 */
static inline void list_init(List *pl)
{
	*pl = NULL;
}

/**
 * 判断链表是否为空
 * @param list 链表
 * @return
 */
static inline int list_is_empty(List list)
{
	if (list == NULL)
		return 1;
	return 0;
}

/**
 * 判断链表是否已满
 * @param plist 链表指针
 * @return
 */
static inline int list_is_full()
{
	Node *pn = (Node *)malloc(sizeof(Node));

	if (pn == NULL)
		return 1;
	free(pn);

	return 0;
}

/**
 * 计算链表内节点个数
 * @param list 链表
 * @return
 */
unsigned int list_count(List list)
{
	unsigned int count = 0;

	Node *pn = list;
	while (pn != NULL) {
		pn = pn->next;
		count++;
	}

	return count;
}

/**
 * 向链表末尾添加一个节点
 * @param pl 链表指针
 * @param pi 节点内数据的指针
 */
void list_append(List *pl, Item *pi)
{
	// 1 创建一个节点并分配内存（判断内存是否已满）
	Node *pn_new = (Node *)malloc(sizeof(Node));
	if (pn_new == NULL) {
		fprintf(stderr, "分配内存失败！内存不足！\n");
		return;
	}

	// 2 将数据放入节点
	pn_new->item = *pi;
	pn_new->next = NULL;

	// 3 判断是否为空节点，若是，则直接赋值；如不是，则遍历到最后一个节点再连接
	Node *pn = *pl;
	if (pn == NULL)
		*pl = pn_new;
	else {
		while (pn->next != NULL)
			pn = pn->next;
		pn->next = pn_new;
	}
	fprintf(stdout, "添加节点成功！\n");
}

/**
 * 传递给定函数遍历链表
 * @param list 链表
 * @param pf 函数指针
 */
void list_for_each (List list, void(*pf)(Item *))
{
	Node *pn = list;

	while (pn != NULL) {
		(*pf)(&pn->item); // 执行函数
		pn = pn->next;
	}
}

/**
 * 清空链表
 * @param pl 链表指针
 */
void list_clean(List *pl)
{
	Node *pn_save;

	while (*pl != NULL) {
		pn_save = (*pl)->next; // 保存下一节点的地址
		free(*pl);
		*pl = pn_save;
	}
	printf("清空链表成功！\n");
}

#endif // S_LIST_H_