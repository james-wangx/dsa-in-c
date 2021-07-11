//
// Created by pineapple on 2021/7/10.
//

#ifndef DATASTRUCTURE_SPLIST_H
#define DATASTRUCTURE_SPLIST_H

#include <stdbool.h>

#define LIST_LEN 100

typedef int Item;
typedef struct node {
	Item item;
	struct node *next;
} Node;
typedef struct node *List;

void InitializeList(List list);

bool IsEmpty(List list);

bool IsFull(List list);

int CountItem(List list);

Item FindItem(List list, const Item *pitem);

void AddItem(List list, Item *pitem);

void DeleteItem(List list, Item *pitem);

void InsertItem(List list, Item *position, Item *pitem);

void EmptyTheList(List list);

#endif //DATASTRUCTURE_SPLIST_H
