/**
 * @file cursor.h
 * @date 2022-03-11
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief cursor ADT
 */

#ifndef _DSAA_CURSOR_H
#define _DSAA_CURSOR_H

#include <stdbool.h>

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

void InitCursorSpace(void);

List ListInit(List list);
bool ListIsEmpty(const List list);
bool ListIsLast(const List list, const Position pos);
Position ListFind(const List list, const ElementType elemnt);
Position ListFindPrev(const List list, const ElementType element);
void ListDelete(List list, const ElementType element);
void ListInsert(List list, const ElementType elment, const Position pos);
void ListEmpty(List list);

#endif // _DSAA_CURSOR_H
