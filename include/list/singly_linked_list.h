/**
 * @file singly_linked_list.h
 * @date 2023-03-07
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 单链表声明
 */
#ifndef DSA_SINGLY_LINKED_LIST_H
#define DSA_SINGLY_LINKED_LIST_H

#include <stdbool.h>

typedef int ElementType;
typedef struct node Node;
typedef struct node *List;
typedef struct node *Pos;

struct node {
    ElementType ele;
    Pos next;
};

List list_init(void);
bool list_is_empty(List list);
int list_add(List list, ElementType ele);
int list_del(List list, ElementType ele);
int list_size(List list);
int list_clear(List list);

#define list_for_each(list, pos) \
    for((pos) = (list)->next; (pos) != NULL; (pos) = (pos)->next)

#endif // DSA_SINGLY_LINKED_LIST_H