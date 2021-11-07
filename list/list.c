// list.c - 2021/11/7
// Linux 内核链表

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 * 头结点
 * 使用头结点的数据域记录链表长度
 */
struct person_head {
	struct list_head list;
	int len;
};

/**
 * 普通结点
 */
struct person {
	struct list_head list;
	int age;
};

int main(void)
{
	int i;
	struct person *p;
	struct person_head head;
	struct list_head *pos;

	INIT_LIST_HEAD(&head.list);
	head.len = 0;

	for (i = 0; i < 5; i++) {
		p = (struct person *)malloc(sizeof(struct person));
		p->age = i * 10;
		list_add(&p->list, &head.list);
	}

	list_for_each (pos, &head.list) {
		printf("age = %d\n", ((struct person *)pos)->age);
		head.len++;
	}

	printf("list len = %d\n", head.len);

	return 0;
}
