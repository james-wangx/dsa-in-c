//
// Created by pineapple on 2021/7/10.
//

#include "splist.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * 初始化列表
 */
void InitializeList(List list)
{
	list = NULL;
}

/*
 * 判断链表是否为空
 */
bool IsEmpty(List list)
{
	if (list == NULL)
		return true;
	return false;
}

/*
 * 判断列表是否已满
 */
bool IsFull(List list)
{
	//    Node *temp = (Node *) malloc(sizeof(Node));
	//    if (temp == NULL)
	//        return true;
	//    free(temp);
	//    return false;
	if (CountItem(list) > LIST_LEN)
		return true;
	return false;
}

/*
 * 统计链表的项目数
 */
int CountItem(List list)
{
	int count = 0;
	while (list->next != NULL) {
		list = list->next;
		count++;
	}

	return count;
}

/*
 * 查找一项并返回
 */
Item FindItem(List list, const Item *pitem)
{
	while (list->next != NULL && list->item != *pitem) {
		list = list->next;
	}
	if (list->item == *pitem)
		return list->item;
	else {
		fprintf(stderr, "Not find, return NULL.");
		return NULL;
	}
}

void demo()
{
	for (int i = 0; i < 10; ++i) {
	}
}