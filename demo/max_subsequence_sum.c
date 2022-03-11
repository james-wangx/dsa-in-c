//
// Created by James Wang on 2021/7/6.
//
#include <stdio.h>

// 简单穷举
__attribute__((unused)) int max_subsequence_sum1(const int arr[], int n)
{
	int this_sum, max_sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			this_sum = 0;
			for (int k = i; k <= j; k++)
				this_sum += arr[k];
			if (this_sum > max_sum)
				max_sum = this_sum;
		}

	return max_sum;
}

// 在构造子序列的同时求和
__attribute__((unused)) int max_subsequence_sum2(const int *arr, int n)
{
	int this_sum, max_sum = 0;
	for (int i = 0; i < n; i++) {
		this_sum = 0;
		for (int j = i; j < n; j++) {
			this_sum += arr[j];
			if (this_sum > max_sum)
				max_sum = this_sum;
		}
	}

	return max_sum;
}

static int max3(const int left, const int right, const int center)
{
	int max;
	if (left > right)
		max = left;
	else
		max = right;
	if (center > max)
		max = center;

	return max;
}

// 采用分而治之，递归的思想
static int max_sub_sum(const int arr[], int left, int right)
{
	int max_left_sum, max_right_sum;
	int max_left_border_sum, max_right_border_sum;
	int left_border_sum, right_border_sum;
	int center, i;

	if (left == right) // 基准情形
		if (arr[left] > 0)
			return arr[left];
		else
			return 0;

	center = (left + right) / 2;
	max_left_sum = max_sub_sum(arr, left, center);
	max_right_sum = max_sub_sum(arr, center + 1, right);

	max_left_border_sum = 0;
	left_border_sum = 0;
	for (i = center; i >= left; i--) {
		left_border_sum += arr[i];
		if (left_border_sum > max_left_border_sum)
			max_left_border_sum = left_border_sum;
	}

	max_right_border_sum = 0;
	right_border_sum = 0;
	for (i = center + 1; i <= right; i++) {
		right_border_sum += arr[i];
		if (right_border_sum > max_right_border_sum)
			max_right_border_sum = right_border_sum;
	}

	return max3(max_left_sum, max_right_sum,
		    max_left_border_sum + max_right_border_sum);
}

__attribute__((unused)) int max_subsequence_sum3(const int arr[], int n)
{
	return max_sub_sum(arr, 0, n - 1);
}

// 几乎完美的算法：仅需要常量空间并以线性时间运行的联机算法
int max_subsequence_sum4(const int arr[], int n)
{
	int this_sum = 0, max_sum = 0;
	for (int i = 0; i <= n; i++) {
		this_sum += arr[i];
		if (this_sum > max_sum)
			max_sum = this_sum;
		else if (this_sum <
			 0) // 0很关键，因为我们认为子序列的和一定是大于0的
			this_sum =
				0; // 所以当子序列和小于0时，重置其为0,抛弃索引i之前的所有元素
	}

	return max_sum;
}

int main(void)
{
	//    int array[] = {-2, 11, -4, 13, -5, -2};
	//    int array[] = {4, -3, 5, -2, -1, 2, 6, -2};
	int array[] = { 9, 9, -9, -9 };
	int size = sizeof array / sizeof *array;
	//    int max_sum = max_subsequence_sum1(array, size);
	//    int max_sum = max_subsequence_sum2(array, size);
	//    int max_sum = bigO_logn(array, 0, size - 1);
	//    int max_sum = max_subsequence_sum3(array, size);
	int max_sum = max_subsequence_sum4(array, size);
	printf("max subsequence sum: %d\n", max_sum);
}
