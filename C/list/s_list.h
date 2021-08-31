// s_list.c - 2021年 八月 30日
// 最简单的单向链表

#ifndef S_LIST_H_
#define S_LIST_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_DONG 22
#define MAX_ROOM 625
#define MIN_BALANCE 0.0

typedef char *String;

/**
 * 书籍结构
 */
struct book {
	String title;
	String author;
	double price;
};

typedef struct bbook Item;

/**
 * 链表的节点
 */
typedef struct node {
	Item item;
	struct node *next;
} Node;

typedef Node *List;

/**
 * 初始化链表，初始化所有宿舍
 * @param plist 链表指针
 */
static inline void list_init(List *plist)
{
	*plist = NULL;
}

/**
 * 判断链表是否为空
 * @param plist 链表指针
 * @return
 */
static inline int list_is_empty(List *plist)
{
	if (*plist == NULL)
		return 1;
	return 0;
}

/**
 * 判断链表是否已满
 * @param plist 链表指针
 * @return
 */
static inline int list_is_full(List *plist)
{
	Node *pn = (Node *)malloc(sizeof(Node));
	if (pn == NULL)
		return 1;
	free(pn);
	return 0;
}

/**
 * 计算链表内节点个数
 * @param plist 链表指针
 * @return
 */
static inline unsigned int list_count(List *plist)
{
	unsigned int count = 0;

	Node *pn = *plist;
	while (pn != NULL) {
		pn = pn->next;
		count++;
	}

	return count;
}

/**
 * 向链表添加一个节点
 * @param plist 链表指针
 * @param pi 节点内数据的指针
 */
void list_add(List *plist, Item *pi)
{
	// 1 创建一个节点并分配内存（判断内存是否已满）
	Node *pn_new = (Node *)malloc(sizeof(Node));
	if (pn_new == NULL) {
		fprintf(stderr, "分配内存失败！内存不足！");
		return;
	}

	// 2 将数据放入节点
	pn_new->item = pi, pn_new->next = NULL;

	// 3 判断是否为空节点，若是，则直接赋值；如不是，则遍历到最后一个节点再连接
	Node *pn = *plist;
	if (pn == NULL)
		pn = pn_new;
	else {
		while (pn->next != NULL)
			pn = pn->next;
		pn->next = pn_new;
	}
	fprintf(stdout, "添加成功！")
}

#endif // S_LIST_H_