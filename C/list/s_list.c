// s_list.c - 2021年 八月 30日
// 测试单链表

#include "s_list.h"

void show_books(Item *pi);

char get_choice(void);

char get_first(void);

void eat_line(void);

void add_book(List *pl);

char *s_gets(char *string, int len);

int main()
{
	List books;
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
			list_for_each (books, show_books)
				;
			break;
		case 'c': // 书记个数
			printf("书籍个数：%d\n", list_count(books));
			break;
		case 'd': // 清空书籍
			list_clean(&books);
			break;
		default:
			fprintf(stderr, "程序错误！\n");
			break;
		}
	}
	printf("再见！\n");

	return 0;
}

void show_books(Item *pi)
{
	printf("title: %s\nauthor: %s\nprice: %.2f", pi->title, pi->author,
	       pi->price);
	printf("\n------------------------------\n");
}

char get_choice(void)
{
	int ch;

	printf("输入您的选择：\n");
	printf("a. 添加书籍		b. 查看书籍\n");
	printf("c. 书籍个数		d. 清空书籍\n");
	printf("q. 退出程序\n");
	ch = get_first();
	while ((ch < 'a' || ch > 'd') && ch != 'q') {
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
	Item item;

	printf("书名：");
	s_gets(item.title, MAX_TITLE);
	printf("作者：");
	s_gets(item.author, MAX_AUTHOR);
	printf("价格：");
	scanf("%lf", &item.price);
	eat_line();

	list_append(pl, &item);
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