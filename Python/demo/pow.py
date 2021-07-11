#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def is_even(n):
    if n % 2:
        return False
    return True


def my_pow(x, n):
    if n == 0:
        return 1
    if n == 1:
        return x
    if is_even(n):
        return my_pow(x * x, n // 2)
    else:
        return my_pow(x * x, n // 2) * x
        # return my_pow(x, n - 1) * x


def test():
    print(f'pow(2, 10) = {my_pow(2, 10)}')


if __name__ == '__main__':
    test()
