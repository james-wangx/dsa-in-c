/**
 * @file splist.h
 * @author Pineapple (pineapple_cpp@163.com)
 * @brief Simple list ADT
 * @version 0.1
 * @date 2021-06-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdbool.h>

/**
 * @brief 实际存储数据的结构
 * 
 */
typedef int Item;

/**
 * @brief 链表节点，包括一个Item结构和指向下一个节点的指针
 * 
 */
typedef struct node
{
    Item item;
    struct node *next;
} Node;

/**
 * @brief 链表，指向头节点
 * 
 */
typedef Node *List;

/**
 * @brief 初始化链表为空
 * 
 * @param plist 指向一个链表
 */
void InitializeList(List *plist);

/**
 * @brief 判断链表是否为空
 * 
 * @param plist 指向一个链表
 * @return true 链表为空
 * @return false 链表不为空
 */
bool ListIsEmpty(const List *plist);

/**
 * @brief 判断链表是否已满
 * 
 * @param plist 指向一个列表
 * @return true 链表已满
 * @return false 链表未满
 */
bool ListIsFull(const List *plist);

/**
 * @brief 查找某一项是否存在
 * 
 * @param pitem 待查找的项
 * @param plist 该项所在链表的指针
 * @return true 该项存在
 * @return false 该项不存在
 */
bool FindItem(const Item *pitem, const List *plist);

/**
 * @brief 添加一项
 * 
 * @param pitem 指向该项的指针
 * @param plist 指向要存储的链表
 * @return Item* 返回添加这一项的指针，如果添加失败则返回NULL
 */
void *AddItem(Item *pitem, List *plist);

/**
 * @brief 在某一项的后面插入一项
 * 
 * @param fitem 
 * @param pitem 
 * @param plist 
 */
void InsertItem(Item *fitem, Item *pitem, List *plist);

/**
 * @brief 删除一项
 * 
 * @param pitem 指向该项的指针
 * @param plist 指向存储该项的链表
 * @return Item* 
 */
Item *DeleteItem(Item *pitem, List *plist);

/**
 * @brief 将函数作用于链表的每一项
 * 
 * @param plist 指向一个链表
 * @param func 指向一个函数
 */
void Traverse(const List *plist, void (*func)(Item *pitem));

/**
 * @brief 计算链表中有多少项
 * 
 * @param plist 指向一个链表
 * @return int 链表中的项目数
 */
int CountItem(const List *plist);

/**
 * @brief 清空链表
 * 
 * @param plist 指向一个链表
 */
void EmptyTheList(List *plist);
