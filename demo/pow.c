//
// Created by pineapple on 2021/7/9.
//
#include <stdio.h>
#include <stdbool.h>

bool is_even(int n) {
    if (n % 2)
        return false;
    return true;
}

long int my_pow(int x, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (is_even(n))
        return my_pow(x * x, n / 2);
    else
        return my_pow(x * x, n / 2) * x;
}

int main(void) {
    printf("pow(2, 62) = %ld", my_pow(2, 10));
}
