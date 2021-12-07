/**
 * @file bucket_sort.c
 * @date 2021-12-07
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 桶排序
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int bucket[MAX];

static void bucket_sort(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		bucket[arr[i]]++;

	for (int i = 0, j = 0; i < MAX; i++)
		if (bucket[i] >= 1)
			for (int k = 0; k < bucket[i]; k++) // 遍历重复值
				arr[j++] = i; // 重新赋值
}

static void test()
{
	const int size = rand() % 500; // 生成随机数组大小
	int *arr = (int *)calloc(size, sizeof(int));

	printf("原数组：\n");
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % MAX; // 生成 0 ~ 99 内的随机数
		printf("%d ", arr[i]);
	}

	bucket_sort(arr, size);

	printf("\n排序后：\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	srand(time(NULL));
	test();

	return 0;
}
