/**
 * @file test_polynomial.c
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 一元多项式 ADT 测试
 */

#include <stdio.h>

#include "polynomial.h"

void print_list(Pitem item)
{
	if (item->coefficient > 0)
		printf(" + %dx^%d", item->coefficient, item->exponent);
	else if (item->coefficient < 0)
		printf(" - %dx^%d", -item->coefficient, item->exponent);
}

int main(void)
{
	Node list1, list2, new;
	ListInit(&list1);
	ListInit(&list2);

	for (int i = 1; i < 3; i++) {
		Item item = { i, i };
		ListAdd(&list1, &item);
	}

	for (int i = 1; i < 4; i++) {
		Item item = { i, i };
		ListAdd(&list2, &item);
	}

	printf("list1: ");
	ListForEach(&list1, print_list);
	printf("\n");

	printf("list2: ");
	ListForEach(&list2, print_list);
	printf("\n");

	// List poly = PolyAdd(&list1, &list2, &new);
	// List poly = PolyMin(&list1, &list2, &new);
	List poly = PolyMul(&list1, &list2, &new);

	printf("new: ");
	ListForEach(poly, print_list);
	printf("\n");

	ListClean(&list1);
	ListClean(&list2);
	ListClean(poly);

	return 0;
}
