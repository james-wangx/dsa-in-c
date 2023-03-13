/**
 * @file array_list.h
 * @date 2023-03-12
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 
 */
#ifndef DSA_ARRAY_LIST_H
#define DSA_ARRAY_LIST_H

#include <stdbool.h>

typedef int ElementType;
typedef struct ArrayList {
    ElementType *array;
    int last;
    int max_size;
} *List;

List list_init(int size);
bool list_is_empty(List list);
int list_add(List list, ElementType ele);
int list_del(List list, ElementType ele);
int list_size(List list);
void list_show(List list);
bool list_clear(List list);

#endif // DSA_ARRAY_LIST_H