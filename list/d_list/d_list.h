/**
 * @file d_list.h
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 双链表ADT
 */

#ifndef DSAA_D_LIST_H
#define DSAA_D_LIST_H

typedef int Item;

typedef struct node Node;

typedef Node *List;

void list_init(List *pl);

void list_append(List *pl, const Item *pi);

void list_delete(List *pl, const Item *pi);

void list_insert(List list, const Item *pi, const Item *pos);

void list_clean(List *pl);

unsigned int list_count(List list);

Item *list_search(List list, const Item *pi);

void list_for_each (List list, void (*pf)(Item *pi));

#endif //DSAA_D_LIST_H
