/**
 * @file infix_exp_calc.c
 * @date 2023-03-15
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Infix Expression Calculator
 */
#include "stack/infix_exp_calc.h"
#include "stack/list_stack.h"

static inline int __is_num(const char ch) {
    return ch >= '0' && ch <= '9';
}

static inline int __is_ope(const char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static inline int __higher_priority(const char ch1, const char ch2) {
    return (ch1 == '*' || ch1 == '/') && (ch2 == '+' || ch2 == '-');
}

static inline void __calc(Stack num_stack, Stack ope_stack) {
    int num1 = stack_pop(num_stack);
    int num2 = stack_pop(num_stack);
    char ope = stack_pop(ope_stack);

    int res;
    switch (ope) {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num2 - num1;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '/':
            res = num2 / num1;
            break;
        default:
            res = 0;
    }

    stack_push(num_stack, res);
}


// TODO: 1 处理多位数问题
// TODO: 2 解决运算符运算顺序问题
// TODO: 3 解决括号 '()' 问题
// TODO: 4 以上能通过测试
int calc(const char *exp) {
    Stack num_stack = stack_init(20);
    Stack ope_stack = stack_init(20);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (__is_num(exp[i])) {
            stack_push(num_stack, exp[i] - 48);
            continue;
        }
        if (__is_ope(exp[i])) {
            if (stack_is_empty(ope_stack)) {
                stack_push(ope_stack, exp[i]);
                continue;
            }
            int top = stack_peek(ope_stack);
            if (__higher_priority(exp[i], top)) {
                stack_push(ope_stack, exp[i]);
                continue;
            }
            __calc(num_stack, ope_stack);
            stack_push(ope_stack, exp[i]);
        }
    }

    while (stack_size(num_stack) != 1) {
        __calc(num_stack, ope_stack);
    }

    int res = stack_pop(num_stack);

    stack_clear(num_stack);
    stack_clear(ope_stack);

    return res;
}
