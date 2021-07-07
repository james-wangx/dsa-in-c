//
// Created by pineapple on 2021/7/6.
//
#include <stdio.h>

// 简单穷举
int max_subsequence_sum1(const int arr[], int n) {
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
int max_subsequence_sum2(const int *arr, int n) {
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

int main(void) {
    int array[] = {-2, 11, -4, 13, -5, -2};
    int size = sizeof array / sizeof *array;
//    int max_sum = max_subsequence_sum1(array, size);
    int max_sum = max_subsequence_sum2(array, size);
    printf("max subsequence sum: %d\n", max_sum);
}
