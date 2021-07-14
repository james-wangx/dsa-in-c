#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct person {
	int age;
	struct list_head list;
};

int main(void)
{
	struct person *p;
	struct person head;
	//		struct list_head *pos;
	struct person *pos;
	struct person replace = { .age = 100 }; // 结构初始化器

	// 初始化链表
	INIT_LIST_HEAD(&head.list);

	// 添加元素（头插法）
	//	for (int i = 0; i < 5; ++i) {
	//		p = (struct person *)malloc(sizeof(struct person));
	//		p->age = i * 10;
	//		list_add(&p->list, &head.list);
	//	}
	// 添加元素（尾插法）
	for (int i = 0; i < 5; ++i) {
		p = (struct person *)malloc(sizeof(struct person));
		p->age = i * 10;
		list_add_tail(&p->list, &head.list);
	}

	// 删除元素
	list_for_each_entry (pos, &head.list, list) {
		if (pos->age == 30) {
			list_del(&pos->list);
			free(pos);
			break;
		}
	}
	// 安全的删除方式，指定p临时存放下一个元素
	list_for_each_entry_safe (pos, p, &head.list, list) {
		if (pos->age == 0) {
			list_del(&pos->list);
			free(pos);
		}
	}

	// 替换元素
	list_for_each_entry (pos, &head.list, list) {
		if (pos->age == 40)
			list_replace(&pos->list, &replace.list);
	}

	// 遍历打印链表
	//	list_for_each (pos, &head.list) {
	//		p = list_entry(pos, struct person, list);
	//		printf("%d ", p->age);
	//	}
	list_for_each_entry (pos, &head.list, list)
		printf("%d ", pos->age);

	return 0;
}
