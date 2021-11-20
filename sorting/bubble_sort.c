/**
 * @file bubble_sort.c
 * @date 2021-11-20
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 冒泡排序
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 交换函数
 * 
 * @param pos 当前元素位置
 * @param next 下一个元素位置
 */
static inline void swap(int *pos, int *next)
{
	int temp = *pos;
	*pos = *next;
	*next = temp;
}

/**
 * @brief 冒泡排序
 * 
 * @param arr 待排序的数组
 * @param size 数组大小
 */
static void bubble_sort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		_Bool swapped = 0; // 设置标记，用于检查是否已排好序
		for (int j = 0; j < size - i; j++)
			if (arr[j] > arr[j + 1]) {
				swap(arr + j, arr + j + 1);
				swapped = 1;
			}
		if (!swapped) // 未交换则排序完毕，跳出循环
			break;
	}
}

/**
 * @brief 测试函数
 * 
 */
static void test()
{
	const int size = rand() % 500; // 生成随机数组大小
	int *arr = (int *)calloc(size, sizeof(int));

	// 生成范围 -50 到 49 的随机数组
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 - 50;

	bubble_sort(arr, size);

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
