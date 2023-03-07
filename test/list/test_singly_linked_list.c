/**
 * @file test_singly_linked_list.c
 * @date 2023-03-07
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 测试单链表
 */
#include <stdio.h>
#include <stdlib.h>

#include "list/singly_linked_list.h"

int main(void) {
    List list = list_init();
    free(list);

    return 0;
}
