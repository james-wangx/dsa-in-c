/**
 * @file radix_sort_list.c
 * @date 2022-01-26
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 基数排序的链表实现
 */

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"

/**
 * @brief 获取数组最大值
 *
 * @param arr 待计算的数组
 * @param size 数组大小
 */
static int max(const int *arr, const int size)
{
	int max_value = arr[0];

	for (int i = 1; i < size; i++)
		if (arr[i] > max_value)
			max_value = arr[i];

	return max_value;
}

/**
 * @brief 基数排序的链表实现
 *
 * @param arr 待排序的数组
 * @param size 数组大小
 */
static void radix_sort_list(int *arr, const int size)
{
	int max_digit = 1; // 最大位数默认为 1
	int max_value = max(arr, size);
	struct node buckets[10]; // 链表数组

	// 计算最大位数
	while (pow(10, max_digit) < max_value)
		max_digit++;

	for (int digit = 0; digit < max_digit; digit++) {
		// 初始化链表
		for (int i = 0; i < 10; i++)
			ListInit(buckets + i);

		for (int i = 0; i < size; i++) {
			int remainder = (int)(arr[i] / pow(10, digit)) % 10;
			ListAddTail(buckets + remainder, arr[i]);
		}

		// 重新赋值
		for (int i = 0, j = 0; i < 10; i++) {
			Position pos;
			ListForEach(buckets + i, pos)
				arr[j++] = pos->digit;
		}

		// 清空链表
		for (int i = 0; i < 10; i++)
			ListEmpty(buckets + i);
	}
}

/**
 * @brief 测试函数
 */
void test(void)
{
	const int size = rand() % 500;
	int *arr = (int *)calloc(size, sizeof(int));

	for (int i = 0; i < size; i++)
		arr[i] = rand() % (int)pow(size, 3);

	radix_sort_list(arr, size);

	for (int i = 0; i < size - 1; i++)
		assert(arr[i] <= arr[i + 1]);

	free(arr);
}

int main(void)
{
	srand(time(NULL));
	test();

	return 0;
}
