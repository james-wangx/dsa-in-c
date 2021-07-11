//
// Created by pineapple on 2021/7/8.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * qsort() 的比较函数，若a < b 返回负数，否则返回正数，相等返回0
 * 默认为升序排序，若 a < b 返回正数，则为降序排序
 */
int compare_ints(const void *a, const void *b)
{
	int arg1 = *(const int *)a;
	int arg2 = *(const int *)b;

	return (arg1 > arg2) - (arg1 < arg2);
	//    return (arg1 < arg2) - (arg1 > arg2);
}

// 对分查找、二分查找、折半查找
int binary_search(const int arr[], int x, int n)
{
	int low, mid, high;
	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] < x)
			low = mid + 1;
		else if (arr[mid] > x)
			high = mid - 1;
		else
			return mid; // 找到
	}

	return -1; // 未找到
}

int main(void)
{
	int ints[] = { -2, 99, 0, -743, 2, INT_MIN, 4 };
	int size = sizeof ints / sizeof *ints;
	// 升序排序
	qsort(ints, size, sizeof(int), compare_ints);
	for (int i = 0; i < size; i++) {
		printf("%d ", ints[i]);
	}

	int x = 0;
	printf("\nfind %d at %d.\n", x, binary_search(ints, x, size));

	printf("\n");
}
