/**
 * @file array_list.c
 * @date 2023-03-12
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 
 */
#include <stdio.h>
#include <stdlib.h>

#include "list/array_list.h"


List list_init(int size) {
    List list = (List) malloc(sizeof(struct ArrayList));
    list->array = (ElementType *) malloc(sizeof(ElementType) * size);
    list->last = -1;
    list->max_size = size;

    return list;
}


bool list_is_empty(List list) {
    return list->last == -1;
}


static inline bool __list_is_full(List list) {
    return list->last + 1 == list->max_size;
}


static inline int __list_search_by_ele(List list, ElementType ele) {
    for (int i = 0; i <= list->last; i++)
        if (list->array[i] == ele)
            return i;

    return -1;
}


int list_add(List list, ElementType ele) {
    if (__list_is_full(list)) {
        fprintf(stderr, "List is full!\n");
        return -1;
    }

    list->array[++(list->last)] = ele;

    return 0;
}


int list_del(List list, ElementType ele) {
    if (list_is_empty(list)) {
        fprintf(stderr, "List is empty!\n");
        return -1;
    }

    int index;
    if ((index = __list_search_by_ele(list, ele)) == -1) {
        fprintf(stderr, "Can't find this element!\n");
        return -2;
    }

    for (int i = index; i < list->last; i++)
        list->array[i] = list->array[i + 1]; // move forward
    list->last--;

    return 0;
}


int list_size(List list) {
    return list->last + 1;
}


void list_show(List list) {
    for (int i = 0; i <= list->last; ++i) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}


bool list_clear(List list) {
    free(list->array);
    free(list);

    return true;
}
