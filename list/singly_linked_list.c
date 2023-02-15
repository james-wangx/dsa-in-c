/**
 * @file singly_linked_list.c
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief 实现单链表
 */

#include <stdio.h>
#include <stdlib.h>

#include "singly_linked_list.h"

struct Node {
		ElementType Element;
		Position Next;
};

/**
 * @brief 初始化链表为空
 *
 * @param L 要初始化的链表
 * @return List 初始化后的空链表
 */
List MakeEmpty(List L)
{
		L->Next == NULL;
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
 * @brief 判断是否为链表最后一个节点
 * 
 * @param P 链表中的结点
 * @param L 链表
 * @return int 0为是，1为否
 */
int IsLast(Position P, List L)
{
		return P->Next == NULL;
}

/**
 * @brief 查找元素在链表中的位置
 * 
 * @param X 待查找的元素
 * @param L 元素所在的链表
 * @return Position 元素所在结点的位置
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
 * @brief 删除结点
 * 
 * @param X 节点中的元素
 * @param L 节点所在的链表
 */
void Delete(ElementType X, List L)
{
		Position Prev = FindPrevious(X, L);
		Position P = Prev->Next;
		Prev->Next = P->Next;
		free(P);
}

/**
 * @brief 查找元素的前一个结点
 * 
 * @param X 带查找的元素
 * @param L 元素所在的结点
 * @return Position 元素前一个结点所在的位置
 */
Position FindPrevious(ElementType X, List L)
{
		if (IsEmpty(L))
				return NULL;

		Position P = L->Next;
		while (P->Next != NULL && P->Next->Element != X)
				P = P->Next;

		return P;
}

/**
 * @brief 在指定位置P后插入元素X
 * 
 * @param X 待插入的元素
 * @param L 待插入的结点
 * @param P 待插入的节点位置
 */
void Insert(ElementType X, List L, Position P)
{
		Position New = (Position)malloc(sizeof(struct Node));
		New->Element = X;
		New->Next = P->Next;
		P->Next = New;
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
				Position Next = P->Next;
				free(P);
				P = Next;
		}

		MakeEmpty(L);
}

/**
 * @brief 获取链表头节点
 * 
 * @param L 链表
 * @return Position 头节点的位置
 */
Position Header(List L)
{
		return L;
}

/**
 * @brief 获取链表的第一个结点
 * 
 * @param L 链表
 * @return Position 第一个节点的位置
 */
Position First(List L)
{
		if (IsEmpty(L))
				return NULL;

		return L->Next;
}
