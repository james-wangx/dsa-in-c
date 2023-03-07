/**
 * @file seq_list.c
 * @date 2023-03-01
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 数组模拟顺序表
 */
#include "seq_list.h"

int main(void) {
    SeqList list = init(10);

    insert(list, 0, 10);
    insert(list, 1, 20);
    insert(list, 1, 30);
    insert(list, 1, 40);
    insert(list, 1, 50);

    del_by_index(list, 0);

    show(list);

    return 0;
}
