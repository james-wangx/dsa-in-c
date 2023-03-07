/**
 * @file singly_linked_list.c
 * @date 2023-03-07
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 单链表实现
 */
#include <stdio.h>
#include <stdlib.h>

#include "singly_linked_list.h"

struct node {
    ElementType ele;
    List next;
};


List list_init(void) {
    List list = (List) malloc(sizeof(Node));

    return list;
}


bool list_is_empty(List list) {
    return list->next == NULL;
}


int list_add(List list, ElementType ele) {
    Pos pos = list;

    while (pos->next != NULL)
        pos = pos->next;

    Pos tmp = (List) malloc(sizeof(Node));
    tmp->ele = ele;
    pos->next = tmp;

    return 0;
}


static Pos __list_search(List list, ElementType ele) {
    if (list_is_empty(list)) {
        fprintf(stderr, "链表为空！");
        return NULL;
    }

    Pos pos = list->next;
    while (pos != NULL) {
        if (pos->ele == ele)
            return pos;
        pos = pos->next;
    }

    fprintf(stderr, "未找到该节点");
    return NULL;
}


int list_del(List list, ElementType ele) {
    Pos pos = __list_search(list, ele);

    if (pos != NULL)
        return 0;

    return -1;
}


int list_size(List list) {
    Pos pos = list;

    int size = 0;
    while (pos->next != NULL) {
        pos = pos->next;
        size++;
    }

    return size;
}
