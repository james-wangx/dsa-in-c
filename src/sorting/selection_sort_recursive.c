/**
 * @file selection_sort_recursive.c
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 选择排序的递归实现
 */

#include <assert.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 交换函数
 * 
 * @param pos 未排序数组的第一个元素
 * @param min 未排序数组的最小元素
 */
static inline void swap(int *pos, int *min)
{
	int temp = *pos;
	*pos = *min;
	*min = temp;
}

/**
 * @brief 查找最小值的索引
 * 
 * @param arr 带查找的数组
 * @param size 数组大小
 * @return int 最小值的索引
 */
static int find_index(const int *arr, const int size)
{
	if (size == 1)
		return 0;

	int min_index = find_index(arr, size - 1);

	if (arr[min_index] > arr[size - 1])
		min_index = size - 1;

	return min_index;
}

/**
 * @brief 选择排序的递归实现
 * 
 * @param arr 待排序数组
 * @param size 数组大小
 */
static void selection_sort_recursive(int *arr, const int size)
{
	if (size == 1)
		return;

	int min_index = find_index(arr, size);

	if (min_index != 0)
		swap(arr, arr + min_index);

	selection_sort_recursive(arr + 1, size - 1);
}

/**
 * @brief 测试函数
 * 
 */
static void test()
{
	// 随机数组大小
	const int size = rand() % 500;
	int *arr = (int *)calloc(size, sizeof(int));

	// 数组元素值的范围 -50 到 49
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 - 50;

	selection_sort_recursive(arr, size);

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
