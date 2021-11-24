/**
 * @file doubly_linked_list.h
 * @date 2021-11-23
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 双链表
 */

#ifndef _DSAA_DOUBLY_LINKED_LIST_H
#define _DSAA_DOUBLY_LINKED_LIST_H

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void Delete(ElementType X, List L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);

#endif // _DSAA_DOUBLY_LINKED_LIST_H
