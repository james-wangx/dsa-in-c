//
// Created by pineapple on 2021/7/9.
//
#include <stdio.h>

#define LEN 10000

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
	int rel = 0, tot = 0;
	for (int i = 1; i <= LEN; ++i) {
		for (int j = i + 1; j <= LEN; ++j) {
			tot++;
			if (gcd(i, j) == 1)
				rel++;
		}
	}
	printf("Percentage of relatively prime pairs is %f\n",
	       (double)rel / tot);
}
