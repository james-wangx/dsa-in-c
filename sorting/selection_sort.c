// selection_sort.c - 2021/11/9
// 选择排序

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 交换两个值
 * 
 * @param pos 当前数组中第一个元素
 * @param min 当前数组中最小的元素
 */
static inline void swap(int *pos, int *min)
{
	int temp = *pos;
	*pos = *min;
	*min = temp;
}

/**
 * @brief 选择排序
 * 
 * @param arr 待排序的数组
 * @param size 数组大小
 */
static void selection_sort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		int j = i + 1;
		for (; j < size; j++)
			if (arr[j] < arr[min])
				min = j;
		if (i != min)
			swap(arr + i, arr + min);
	}
}

/**
 * @brief 测试函数
 * 
 */
static void test()
{
	const int size = rand() % 500; // 随机数组大小
	int *arr = (int *)calloc(size, sizeof(int));

	// 生成 -50 到 49 之间的随机数
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 100) - 50;
	}
	selection_sort(arr, size);
	for (int i = 0; i < size - 1; ++i) {
		assert(arr[i] <= arr[i + 1]);
	}
	free(arr);
}

int main(void)
{
	// 初始化随机数种子
	srand(time(NULL));
	test();

	return 0;
}
