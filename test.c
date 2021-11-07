// test.c - 2021/11/7
//

#include <stdio.h>

#include "list/list.h"

struct person {
	int age;
	short ch;
	short ch2;
	struct list_head list;
};

static void for_test1(struct person *p)
{
	printf("%u\n%u\n", (unsigned int)&p->ch2, (unsigned int)&p->list);
}

int main(void)
{
	struct person head;
	for_test1(NULL);

	printf("%u\n", &((struct person *)0)->ch);

	return 0;
}