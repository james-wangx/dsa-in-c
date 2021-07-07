#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def sum_subsequence_max1(arr):
    """
    简单穷举
    """
    max_sum = 0
    for i in range(0, len(arr)):  # 遍历所有元素作为子序列的第一项
        for j in range(i, len(arr)):  # 确定子序列的最后一项
            this_sum = 0
            for k in arr[i: j + 1]:  # 遍历子序列求和
                this_sum += k
            if this_sum > max_sum:
                max_sum = this_sum

    return max_sum


def sum_subsequence_max2(arr):
    """
    在构造子序列的同时求和
    """
    max_sum = 0
    for i in range(0, len(arr)):  # 遍历所有元素作为子序列的第一项
        this_sum = 0
        for j in range(i, len(arr)):  # 确定子序列最后一项
            this_sum += arr[j]  # 求和
            if this_sum > max_sum:
                max_sum = this_sum

    return max_sum


def test():
    array = [-2, 11, -4, 13, -5, -2]
    # max_sum = sum_subsequence_max1(array)
    max_sum = sum_subsequence_max2(array)
    print(f'max subsequence sum: {max_sum}')


if __name__ == '__main__':
    test()
