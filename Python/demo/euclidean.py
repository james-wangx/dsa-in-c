#!/usr/bin/env python3
# -*- coding:utf-8 -*-

def gcd(m, n):
    while n > 0:
        rem = m % n
        m = n
        n = rem

    return m


def test():
    print(f'gcd(50, 15) = {gcd(50, 15)}')
    print(f'gcd(1989, 1590) = {gcd(1989, 1590)}')


if __name__ == '__main__':
    test()