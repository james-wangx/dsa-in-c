/**
 * @file infix_exp_calc.c
 * @date 2023-03-15
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Infix Expression Calculator
 */
#include "stack/infix_exp_calc.h"
#include "stack/list_stack.h"

static Stack num_stack;
static Stack ope_stack;
static int result;

static inline int __is_ope(const char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')';
}

static inline void __calc(void) {
    int num1 = stack_pop(num_stack);
    int num2 = stack_pop(num_stack);
    char ope = stack_pop(ope_stack);

    switch (ope) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num2 - num1;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num2 / num1;
            break;
        default:
            result = 0;
    }

    stack_push(num_stack, result);
}

static void __calc_before(void) {
    do {
        __calc();
    } while (!stack_is_empty(ope_stack));
}

static void __calc_brackets(void) {
    do {
        __calc();
    } while (stack_peek(ope_stack) != '(');

    stack_pop(ope_stack);
}

int calc(const char *exp) {
    num_stack = stack_init(20);
    ope_stack = stack_init(20);
    int num = 0;
    int i = 0;
    char ch;

    while (1) {
        ch = exp[i];
        if (__is_ope(ch)) {
            if (!stack_is_empty(ope_stack) && stack_peek(ope_stack) != '(' && (ch == '+' || ch == '-')) {
                __calc_before();
                stack_push(ope_stack, ch);
            } else if (ch == ')') {
                __calc_brackets();
            } else {
                stack_push(ope_stack, ch);
            }
        } else {
            num = num * 10 + ch - 48;
            if (exp[i + 1] == '\0') {
                stack_push(num_stack, num);
                break;
            }
            if (__is_ope(exp[i + 1])) {
                stack_push(num_stack, num);
                num = 0;
            }
        }
        i++;
    }

    __calc();

    stack_clear(num_stack);
    stack_clear(ope_stack);

    return result;
}
