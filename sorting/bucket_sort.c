/**
 * @file bucket_sort.c
 * @date 2021-01-18
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 桶排序
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int bucket[MAX];

/**
 * @brief 桶式排序
 * 
 * @param arr 待排序数组
 * @param size 数组大小
 */
static void bucket_sort(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		bucket[arr[i]]++;

	for (int i = 0, j = 0; i < MAX; i++)
		if (bucket[i] >= 1)
			for (int k = 0; k < bucket[i]; k++) // 遍历重复值
				arr[j++] = i; // 重新赋值
}

/**
 * @brief 测试函数
 * 
 */
static void test()
{
	const int size = rand() % 500; // 生成随机数组大小
	int *arr = (int *)calloc(size, sizeof(int));

	// 生成 0 ~ 99 内的随机数
	for (int i = 0; i < size; i++)
		arr[i] = rand() % MAX;

	bucket_sort(arr, size);

	for (int i = 0; i < size - 1; i++)
		assert(arr[i] <= arr[i + 1]);
}

int main()
{
	srand(time(NULL));
	test();

	return 0;
}
