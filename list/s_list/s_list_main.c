/**
 * @file s_list_main.c
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 测试单链表
 */

#include <string.h>
#include "s_list.h"

void show_books(Item *pi);

char get_choice(void);

char get_first(void);

void eat_line(void);

void add_book(List *pl);

void delete_book(List *pl);

void insert_book(List list);

Item get_book(void);

Item *search_book(List list);

char *s_gets(char *string, int len);

int main(void)
{
	List books;
	Item *pi;
	int choice;

	// 初始化链表
	list_init(&books);

	printf("======欢迎来到图书管理系统！======\n");

	while ((choice = get_choice()) != 'q') {
		switch (choice) {
		case 'a': // 添加书籍
			add_book(&books);
			break;
		case 'b': // 查看书籍
			printf("---------书籍列表----------\n");
			list_for_each (books, show_books)
				;
			break;
		case 'c': // 书籍个数
			printf("书籍个数：%d\n", list_count(books));
			break;
		case 'd': // 清空书籍
			list_clean(&books);
			break;
		case 'e': // 删除书籍
			delete_book(&books);
			break;
		case 'f': // 查找书籍
			pi = search_book(books);
			if (pi != NULL)
				printf("title: %s\nauthor: %s\nprice: %.2f\n",
				       pi->title, pi->author, pi->price);
			break;
		case 'g': // 插入书籍
			puts("请输入要插入的位置的书名");
			insert_book(books);
			break;
		default:
			//			fprintf(stderr, "程序错误！\n");
			puts("程序错误！\n");
			break;
		}
	}
	list_clean(&books);
	printf("再见！\n");

	return 0;
}

void show_books(Item *pi)
{
	printf("title: %s\nauthor: %s\nprice: %.2f\n", pi->title, pi->author,
	       pi->price);
	printf("---------------------------\n");
}

char get_choice(void)
{
	int ch;

	printf("\n");
	printf("a. 添加书籍		b. 查看书籍\n");
	printf("c. 书籍个数		d. 清空书籍\n");
	printf("e. 删除书籍		f. 查找书籍\n");
	printf("g. 插入书籍\n");
	printf("q. 退出程序\n");
	printf("输入您的选择：");
	ch = get_first();
	while ((ch < 'a' || ch > 'g') && ch != 'q') {
		printf("输入错误，请重新输入：\n");
		ch = get_first();
	}

	return ch;
}

char get_first(void)
{
	int ch;

	ch = getchar();
	eat_line();

	return ch;
}

inline void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

void add_book(List *pl)
{
	Item item = get_book();
	list_append(pl, &item);
}

void delete_book(List *pl)
{
	Item *pi = search_book(*pl);

	if (pi == NULL)
		return;
	list_delete(pl, pi);
}

void insert_book(List list)
{
	Item *pos = search_book(list);

	if (pos == NULL)
		return;

	Item item = get_book();
	list_insert(list, &item, pos);
}

inline Item get_book(void)
{
	Item item;

	printf("请输入将要添加/插入书籍的相关信息\n");
	printf("书名：");
	s_gets(item.title, MAX_TITLE);
	printf("作者：");
	s_gets(item.author, MAX_AUTHOR);
	printf("价格：");
	scanf("%lf", &item.price);
	eat_line();

	return item;
}

Item *search_book(List list)
{
	char title[MAX_TITLE];

	printf("书名：");
	s_gets(title, MAX_TITLE);
	while ((list != NULL) && strcmp(list->item.title, title))
		list = list->next;

	if (list == NULL) {
		//		fprintf(stderr, "书籍不存在！\n");
		puts("书籍不存在！");
		return NULL;
	}

	return &list->item;
}

char *s_gets(char *string, int len)
{
	char *ret_val;
	int i = 0;

	ret_val = fgets(string, len, stdin);
	if (ret_val) { // ret_val != NULL
		while (string[i] != '\0' && string[i] != '\n')
			i++;
		if (string[i] == '\n')
			string[i] = '\0';
		else
			eat_line();
	}

	return ret_val;
}