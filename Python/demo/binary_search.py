#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys

INT_MIN = -sys.maxsize - 1


def binary_search(arr, x):
    """
    二分查找
    """
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if x > arr[mid]:
            low = mid + 1
        elif x < arr[mid]:
            high = mid - 1
        else:
            return mid

    return -1


def test():
    ints = [-2, 99, 0, -743, 2, INT_MIN, 4]
    # 升序排序
    ints.sort()
    print(ints)

    x = 0
    print(f'find {x} in {binary_search(ints, x)}.')


if __name__ == '__main__':
    test()