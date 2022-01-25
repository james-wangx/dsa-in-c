/**
 * @file bubble_sort.c
 * @date 2022-01-16
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 冒泡排序
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 交换函数
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
 * @brief 冒泡排序
 * 
 * @param arr 待排序的数组
 * @param size 数组大小
 */
static void bubble_sort(int *arr, const int size)
{
	for (int i = 0; i < size - 1; i++) {
		bool swapped = false; // 设置标记，用于检查是否已排好序
		for (int j = 0; j < size - i; j++)
			if (arr[j] > arr[j + 1]) {
				swap(arr + j, arr + j + 1);
				swapped = true;
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
