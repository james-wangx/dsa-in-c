/**
 * @file doubly_linked_list.c
 * @date 2021-11-23
 * @author Pineapple (pineapple_cpp@163.com)
 * 
 * @brief 实现双链表
 */

#include <stdlib.h>

#include "doubly_linked_list.h"

struct Node {
	ElementType Element;
	Position Prev;
	Position Next;
};

/**
 * @brief 初始化链表为空
 * 
 * @param L 带初始化的链表
 * @return List 初始化后的链表
 */
List MakeEmpty(List L)
{
	L->Prev = NULL;
	L->Next = NULL;

	return L;
}

/**
 * @brief 判断链表是否为空
 * 
 * @param L 待判断的链表
 * @return int 0为空，1为非空
 */
int IsEmpty(List L)
{
	return L->Next == NULL;
}

/**
 * @brief 判断位置P是否为最后一个结点
 * 
 * @param P 带判断的结点
 * @param L 节点所在的链表
 * @return int 0为是，1为否
 */
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

/**
 * @brief 查找元素所在的结点并返回
 * 
 * @param X 待查找的元素
 * @param L 带查找的链表
 * @return Position 
 */
Position Find(ElementType X, List L)
{
	if (IsEmpty(L))
		return NULL;

	Position P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;

	return P;
}

/**
 * @brief 在指定位置P后插入元素X
 * 
 * @param X 待插入的元素
 * @param L 待插入的链表
 * @param P 待插入的位置
 */
void Insert(ElementType X, List L, Position P)
{
	Position New = (Position)malloc(sizeof(struct Node));
	New->Element = X;
	New->Next = P->Next;
	if (!IsLast(P, L))
		P->Next->Prev = New;
	New->Prev = P;
	P->Next = New;
}

/**
 * @brief 删除指定元素X
 * 
 * @param X 待删除的元素
 * @param L 元素所在的链表
 */
void Delete(ElementType X, List L)
{
	if (IsEmpty(L))
		return;

	Position P = Find(X, L);
	P->Prev->Next = P->Next;
	if (!IsLast(P, L))
		P->Next->Prev = P->Prev;

	free(P);
}

/**
 * @brief 删除链表
 * 
 * @param L 待删除的链表
 */
void DeleteList(List L)
{
	if (IsEmpty(L))
		return;

	Position P = L->Next;
	while (P != NULL) {
		P->Prev->Next = P->Next;
		if (!IsLast(P, L))
			P->Next->Prev = P->Next;
		free(P);
	}
}

/**
 * @brief 获取链表头节点
 * 
 * @param L 目标节点
 * @return Position 头节点的位置
 */
Position Header(List L)
{
	return L;
}

/**
 * @brief 获取链表的第一个结点
 * 
 * @param L 目标节点
 * @return Position 第一个节点的位置
 */
Position First(List L)
{
	if (IsEmpty(L))
		return NULL;

	return L->Next;
}