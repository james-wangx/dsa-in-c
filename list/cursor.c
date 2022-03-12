/**
 * @file cursor.c
 * @date 2022-03-12
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief implemention of the cursor 
 */

#include <stdio.h>

#include "cursor.h"

#define SpaceSize 11

typedef struct node {
	ElementType element;
	Position next;
} Node;

Node CursorSpace[SpaceSize];

/**
 * @brief Initialize cursor space
 * 
 */
void InitCursorSpace(void)
{
	for (int i = 0; i < SpaceSize - 1; i++)
		CursorSpace[i].next = i + 1;

	CursorSpace[SpaceSize - 1].next = 0;
}

/**
 * @brief Allocate "memory" to node
 * 
 * @return Position 
 */
static inline Position __cursor_alloc(void)
{
	Position pos = CursorSpace[0].next;
	CursorSpace[0].next = CursorSpace[pos].next;

	return pos;
}

/**
 * @brief Free "memory"
 * 
 * @param pos 
 */
static inline void __cursor_free(const Position pos)
{
	CursorSpace[pos].next = CursorSpace[0].next;
	CursorSpace[0].next = pos;
}

/**
 * @brief Return true if list is empty
 * 
 * @param list 
 * @return true 
 * @return false 
 */
bool ListIsEmpty(const List list)
{
	return CursorSpace[list].next == 0;
}

/**
 * @brief Return true if pos is the last position in the list
 * 
 * @param list 
 * @param pos 
 * @return true 
 * @return false 
 */
bool ListIsLast(const List list, const Position pos)
{
	return CursorSpace[pos].next == 0;
}

/**
 * @brief Return position of element in list, 0 is not find.
 * 
 * @param list 
 * @param element 
 * @return Position 
 */
Position ListFind(const List list, const ElementType element)
{
	Position pos = CursorSpace[list].next;

	while (pos && CursorSpace[pos].element != element)
		pos = CursorSpace[pos].next;

	return pos;
}

/**
 * @brief Return the previous position of element in list
 * 
 * @param list 
 * @param element 
 * @return Position 
 */
Position ListFindPrev(const List list, const ElementType element)
{
	Position pos = CursorSpace[list].next;

	while (!ListIsLast(list, pos) &&
	       CursorSpace[CursorSpace[pos].next].element == element)
		pos == CursorSpace[pos].next;

	return pos;
}

/**
 * @brief Delete first occurence of element from a list
 * 
 * @param list 
 * @param element 
 */
void ListDelete(List list, const ElementType element)
{
	Position prev = ListFindPrev(list, element);

	if (!ListIsLast(list, prev)) {
		Position temp = CursorSpace[prev].next;
		CursorSpace[prev].next = CursorSpace[temp].next;
		__cursor_free(temp);
	}
}

/**
 * @brief Insert (after legal position pos)
 * 
 * @param list 
 * @param element 
 * @param pos 
 */
void ListInsert(List list, const ElementType element, const Position pos)
{
	Position temp = __cursor_alloc();

	if (temp == 0)
		fprintf(stderr, "Out of space!");

	CursorSpace[temp].element = element;
	CursorSpace[temp].next = CursorSpace[pos].next;
	CursorSpace[pos].next = temp;
}
