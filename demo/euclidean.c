//
// Created by pineapple on 2021/7/9.
//
#include <stdio.h>

unsigned int gcd(unsigned int m, unsigned int n)
{
	unsigned int rem;

	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}

	return m;
}

int main(void)
{
	printf("gcd(50, 15) = %d\n", gcd(50, 15));
	printf("gcd(1989, 1590) = %d\n", gcd(1989, 1590));
}
