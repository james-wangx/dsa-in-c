/**
 * @file bubble_sort_recursive.c
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 冒泡排序的递归实现
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 交换两个元素的值
 * 
 * @param left 左边的元素
 * @param right 右边的元素
 */
static inline void swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

/**
 * @brief 冒泡排序的递归实现
 * 
 * @param arr 待排序的数组
 * @param size 未排序数组的大小
 */
static void bubble_sort_recursive(int *arr, const int size)
{
	if (size == 1)
		return;

	bool swapped = false;

	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			swap(arr + i, arr + i + 1);
			swapped = true;
		}
	}

	if (swapped)
		bubble_sort_recursive(arr, size - 1);
}

/**
 * @brief 测试函数
 * 
 */
static void test()
{
	const int size = rand() % 500; // 生成随机数组大小
	int *arr = (int *)calloc(size, sizeof(int));

	// 生成范围 -50 到 49 的随机值
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 - 50;

	bubble_sort_recursive(arr, size);

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
