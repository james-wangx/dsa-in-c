/**
 * @file splist.c
 * @author Pineapple (pineapple_cpp@163.com)
 * @brief Simple list function definitions
 * @version 0.1
 * @date 2021-06-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "splist.h"

void InitailizeList(List *plist)
{
    plist = NULL;
}

bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
        return true;
    return false;
}

bool ListIsFull(const List *plist)
{
    Node *pnode = (Node *)malloc(sizeof(Node));
    if (pnode == NULL) // 如果返回空指针则表示链表已满
        return true;
    free(pnode);

    return false;
}

bool FindItem(const Item *pitem, const List *plist)
{
    Node *pnode = *plist;
    while (pnode->item != *pitem)
        pnode = pnode->next;
    if (pnode->item == *pitem)
        return true;
    return false;
}

void *AddItem(Item *pitem, List *plist)
{
    Node *pnew = (Node *)malloc(sizeof(Node));
    pnew->item = *pitem;
    pnew->next = NULL;
    // 如果链表为空
    if (ListIsEmpty(plist))
        *plist = pnew;
    else
    {
        Node *pnode = *plist;
        while (pnode->next != NULL)
            pnode = pnode->next;
        pnode->next = pnew;
    }
}
