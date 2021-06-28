// choicek.c -- 确定一组数中第k个最大者
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    return (arg1 < arg2) - (arg1 > arg2);
}

int main(void)
{
    int k = 3;
    int ints[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
    int size = sizeof ints / sizeof *ints;

    qsort(ints, size, sizeof(int), compare_ints);

    printf("choice k = %d\n", ints[k - 1]);

    return 0;
}
