// d_list_main.c - 2021年 九月 02日
// 测试双链表

#include <stdio.h>
#include "d_list.h"

void show_items(Item *pi);

int main(void)
{
	List list;
	Item item;

	// 初始化链表
	list_init(&list);

	// 添加元素
	item = 1;
	list_append(&list, &item);
	item = 2;
	list_append(&list, &item);
	item = 4;
	list_append(&list, &item);

	// 插入一项
	item = 2;
	Item *pi = list_search(list, &item);
	item = 3;
	list_insert(list, &item, pi);

	// 打印每一项
	list_for_each (list, show_items)
		;
	printf("\n");

	// 删掉一项
	item = 1;
	Item *pi2 = list_search(list, &item);
	list_delete(&list, pi2);

	// 打印每一项
	list_for_each (list, show_items)
		;
	printf("\n");

	// 删掉一项
	item = 3;
	Item *pi3 = list_search(list, &item);
	list_delete(&list, pi3);

	// 打印每一项
	list_for_each (list, show_items)
		;
	printf("\n");

	// 清空链表
	list_clean(&list);

	return 0;
}

void show_items(Item *pi)
{
	printf("%d ", *pi);
}