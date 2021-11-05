// d_list.h - 2021/11/4
// 双链表ADT

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

void list_for_each (List list, void(*pf)(Item * pi));

#endif //DSAA_D_LIST_H
