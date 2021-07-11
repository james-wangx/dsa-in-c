#!/usr/bin/env python3
# -*- coding:utf-8 -*-

LEN = 10000


def gcd(m, n):
    while n > 0:
        rem = m % n
        m = n
        n = rem

    return m


def test():
    tot = rel = 0

    for i in range(1, LEN + 1):
        for j in range(i, LEN + 1):
            tot += 1
            if gcd(i, j) == 1:
                rel += 1

    print(f'Percentage of relatively prime pairs is {rel / tot:.6f}')


if __name__ == '__main__':
    test()