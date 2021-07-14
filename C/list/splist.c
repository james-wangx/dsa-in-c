//
// Created by pineapple on 2021/7/11.
//

#include <stdlib.h>
#include "splist.h"

struct person {
	int age;
	struct list_head list;
};

int main(void)
{
	struct person per;
	struct person *temp;
	//	struct list_head *pos;
	struct person *pos;

	// 初始化链表
	INIT_LIST_HEAD(&per.list);

	// 添加元素
	for (int i = 0; i < 5; ++i) {
		temp = (struct person *)malloc(sizeof(struct person));
		temp->age = i * 10;
		list_add(&temp->list, &per.list);
	}

	// 删除元素
	//	list_for_each (pos, &per.list) {
	//		temp = list_entry(pos, struct person, list);
	//		if (temp->age == 40) {
	//			list_del(pos, &per.list);
	//			free(temp);
	//			// list_for_each是不安全的，删掉元素后无法继续获取下一个元素
	//			break;
	//		}
	//	}
	list_for_each_entry (pos, &per.list, list) {
		if (pos->age == 40) {
			list_del(&pos->list, &per.list);
			free(pos);
			break;
		}
	}

	// 遍历打印链表
	list_for_each_entry (pos, &per.list, list) {
		printf("%d ", pos->age);
	}

	return 0;
}
