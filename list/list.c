/**
 * @file list.c
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 链表测试
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
// #include "singly_linked_list.h"
// #include "doubly_linked_list.h"

struct book_head {
	int number; // 记录链表元素数
	struct list_head head;
};

struct book {
	int id;
	struct list_head head;
};

static void test()
{
	struct book_head book_list_head;
	struct list_head *list_cursor; // 链表游标
	struct book *book_entry;
	struct book *book_temp;
	const int count = 100;
	int temp = 0;

	INIT_LIST_HEAD(&book_list_head.head); // 初始化链表

	for (int i = 0; i < count; i++) { // 尾插法插入元素
		book_entry = (struct book *)malloc(sizeof(struct book));
		book_entry->id = i;
		list_add_tail(&book_entry->head, &book_list_head.head);
		book_list_head.number++;
	}

	printf("Testing list_add_tail......");
	list_for_each (list_cursor, &book_list_head.head) {
		book_entry = list_entry(list_cursor, struct book, head);
		assert(temp == book_entry->id);
		temp++;
	}
	puts(" OK!");

	printf("Testing list_del......");
	list_for_each_entry_safe (book_entry, book_temp, &book_list_head.head,
				  head) {
		list_del(&book_entry->head);
		free(book_entry);
		book_list_head.number--;
	}
	if (list_empty(&book_list_head.head))
		puts(" OK!");
}

int main(void)
{
	test();

	return 0;
}
