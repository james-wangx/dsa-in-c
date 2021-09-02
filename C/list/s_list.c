// s_list.c - 2021年 八月 30日
// 实现单链表

#include <string.h>
#include "s_list.h"

static Node *find_pre(List list, Node *pn);

/**
 * 初始化链表为空
 * @param pl 链表指针
 */
inline void list_init(List *pl)
{
	*pl = NULL;
}

/**
 * 判断链表是否为空
 * @param list 链表
 * @return
 */
inline int list_is_empty(List list)
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
inline int list_is_full()
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
 * 删除一个节点
 * @param pl 链表指针
 * @param pi 指向待删除的节点元素
 */
void list_delete(List *pl, Item *pi)
{
	Node *pn = *pl;

	if (&pn->item == pi) {
		free(*pl);
		list_init(pl); // 表头被free掉，需要重新指向NULL，即初始化
	} else {
		while (&pn->item != pi)
			pn = pn->next;
		Node *pn_pre = find_pre(*pl, pn);
		pn_pre->next = pn->next;
		free(pn);
	}
	printf("删除节点成功！");
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

/**
 * 找到给定节点的上一个节点
 * @param list 链表
 * @param pn 结点指针
 * @return
 */
static Node *find_pre(List list, Node *pn)
{
	Node *pn_pre = list;

	while (pn_pre->next != pn)
		pn_pre = pn->next;

	return pn_pre;
}