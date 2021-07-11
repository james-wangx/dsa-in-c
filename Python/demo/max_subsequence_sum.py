#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def max_subsequence_sum1(arr):
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


def max_subsequence_sum2(arr):
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


def max3(left, right, center):
    return max((left, right, center))


def max_sub_sum(arr, left, right):
    """
    采用分而治之，递归的思想
    """
    # 基准情形
    if left == right:
        return arr[left] if arr[left] > 0 else 0

    center = (left + right) // 2  # Python 的整除符号为 //
    max_left_sum = max_sub_sum(arr, left, center)
    max_right_sum = max_sub_sum(arr, center + 1, right)

    left_border_sum = max_left_border_sum = 0
    for i in reversed(arr[left: center + 1]):
        left_border_sum += i
        if left_border_sum > max_left_border_sum:
            max_left_border_sum = left_border_sum

    right_border_sum = max_right_border_sum = 0
    for i in arr[center + 1: right + 1]:
        right_border_sum += i
        if right_border_sum > max_right_border_sum:
            max_right_border_sum = right_border_sum

    return max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum)


def max_subsequence_sum3(arr):
    return max_sub_sum(arr, 0, len(arr) - 1)


def max_subsequence_sum4(arr):
    """
    几乎完美的算法：仅需要常量空间并以线性时间运行的联机算法
    """
    max_sum = this_sum = 0
    for i in arr:
        this_sum += i
        if this_sum > max_sum:
            max_sum = this_sum
        elif this_sum < 0:
            this_sum = 0

    return max_sum


def test():
    array = [-2, 11, -4, 13, -5, -2]
    # array = [9, 9, -9, -9]
    # max_sum = max_subsequence_sum1(array)
    # max_sum = max_subsequence_sum2(array)
    # max_sum = max_subsequence_sum3(array)
    max_sum = max_subsequence_sum4(array)
    print(f'max subsequence sum: {max_sum}')


if __name__ == '__main__':
    test()