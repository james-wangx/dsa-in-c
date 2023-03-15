/**
 * @file test_infix_exp_calc.c
 * @date 2023-03-15
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Test Infix Expression Calculator
 */
#include <assert.h>

#include "stack/infix_exp_calc.h"

void test_calc(void) {
    assert(calc("3+2*6-2") == 13);
    assert(calc("30+2*6-2") == 40);
    assert(calc("7*2*2-5+1-5+3-4") == 18);
    assert(calc("3-2*5+4") == -3);
    assert(calc("(30+2)*6-20/2+7") == 189);
}

int main(void) {
    test_calc();

    return 0;
}
