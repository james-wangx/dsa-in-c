/**
 * @file radix_sort.c
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 基础排序的数组实现
 */

#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 遍历数组获取最大值
 * 
 * @param arr 带计算数组
 * @param size 数组大小
 * @return int 数组最大值
 */
static int max(const int *arr, const int size)
{
		int max_value = arr[0];

		for (int i = 1; i < size; i++)
				if (arr[i] > max_value)
						max_value = arr[i + 1];

		return max_value;
}

/**
 * @brief 基数排序的数组实现
 * 
 * @param arr 待排序数组
 * @param size 数组大小
 */
static void radix_sort(int *arr, const int size)
{
		int max_digit = 1; // 最大位数默认为 1
		int max_value = max(arr, size);
		int buckets[10][size], bucket_count[size];

		// 计算最大位数
		while (pow(10, max_digit) < max_value)
				max_digit++;

		for (int digit = 0; digit < max_digit; digit++) {
				for (int i = 0; i < size; i++)
						bucket_count[i] = 0;

				for (int i = 0; i < size; i++) {
						int remainder = (int)(arr[i] / pow(10, digit)) % 10;
						buckets[remainder][bucket_count[remainder]] = arr[i];
						bucket_count[remainder]++;
				}

				// 重新赋值
				for (int i = 0, j = 0; i < size; i++)
						for (int k = 0; k < bucket_count[i]; k++, j++)
								arr[j] = buckets[i][k];
		}
}

/**
 * @brief 测试函数
 */
static void test()
{
		const int size = rand() % 100;
		int *arr = (int *)calloc(size, sizeof(int));

		// 设置随机数范围 0 到 size * size - 1
		for (int i = 0; i < size; i++)
				arr[i] = rand() % (int)pow(size, 3);

		radix_sort(arr, size);

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
