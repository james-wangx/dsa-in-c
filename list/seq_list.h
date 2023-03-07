/**
 * @file seq_list.h
 * @date 2023-03-01
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 数组模拟顺序表
 */
#ifndef DSA_SEQ_LIST_H
#define DSA_SEQ_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct SeqList {
    ElemType *elem; // 数组模拟顺序表
    int last;       // 最后元素的索引
    int max_size;   // 最大元素个数
} *SeqList;


SeqList init(int size) {
    SeqList list = (SeqList) malloc(sizeof(struct SeqList));
    list->elem = (ElemType *) malloc(sizeof(ElemType) * size);
    list->last = -1;
    list->max_size = size;

    return list;
}


bool is_full(SeqList list) {
    return list->last + 1 == list->max_size;
}


bool is_empty(SeqList list) {
    return list->last == -1;
}


bool verify_index(SeqList list, int index) {
    return index < 0 || index > list->last + 1;
}


int insert(SeqList list, int index, ElemType elem) {
    if (verify_index(list, index)) {
        fprintf(stderr, "插入索引非法！\n");
        return -1;
    }

    if (is_full(list)) {
        fprintf(stderr, "表中元素已满！\n");
        return -2;
    }

    // 后移
    for (int i = list->last + 1; i > index; i--) {
        list->elem[i] = list->elem[i - 1];
    }

    // 插入
    list->elem[index] = elem;
    list->last++;

    return 0;
}


int del_by_index(SeqList list, int index) {
    if (verify_index(list, index)) {
        fprintf(stderr, "删除索引非法！\n");
        return -1;
    }

    if (is_empty(list)) {
        fprintf(stderr, "顺序表为空！\n");
        return -2;
    }

    // 删除
    int res = list->elem[index];
    list->last--;

    // 前移
    for (int i = index; i <= list->last; i++) {
        list->elem[i] = list->elem[i + 1];
    }

    return res;
}


void show(SeqList list) {
    if (is_empty(list)) {
        fprintf(stderr, "顺序表为空！\n");
        return;
    }

    for (int i = 0; i <= list->last; ++i) {
        fprintf(stdout, "%d ", list->elem[i]);
    }
}


#endif // DSA_SEQ_LIST_H