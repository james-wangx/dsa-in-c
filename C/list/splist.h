//
// Created by pineapple on 2021/7/11.
// Simple linked list

#ifndef _SPLIST_H_
#define _SPLIST_H_

#include <stdio.h>

struct list_head {
	struct list_head *next;
};

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 */
#define container_of(ptr, type, member)                                        \
	({                                                                     \
		const typeof(((type *)0)->member) *__mptr = (ptr);             \
		(type *)((char *)__mptr - offsetof(type, member));             \
	})

static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = NULL;
}

/**
 * list_add - add a new entry
 * @new: 	new entry to be added
 * @head: 	list head to add it after
 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
	while (head->next != NULL)
		head = head->next;

	head->next = new;
	new->next = NULL;
}

/**
 * list_del - delete a specified entry
 * @entry:	an unlucky entry to be deleted
 * @head:	the head for your list
 */
static inline void list_del(struct list_head *entry, struct list_head *head)
{
	while (head->next != entry)
		head = head->next;

	head->next = entry->next;
}

/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
static inline int list_empty(const struct list_head *head)
{
	return head->next == NULL;
}

/**
 * list_entry - get the struct of the entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded it.
 * @member:	the name of the list_head within the struct.
 */
#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define list_first_entry(ptr, type, member)                                    \
	list_entry((ptr)->next, type, member)

#define list_next_entry(ptr, member)                                           \
	list_entry((ptr)->member.next, typeof(*(ptr)), member)

/**
 * list_for_each - iterate over a list
 * @pos: 	the &struct list_head to use as a loop cursor
 * @head:	the head for your list
 */
#define list_for_each(pos, head)                                               \
	for ((pos) = (head)->next; (pos) != NULL; (pos) = (pos)->next)

#define list_for_each_entry(pos, head, member)                                 \
	for ((pos) = list_first_entry(head, typeof(*(pos)), member);           \
	     &((pos)->member) != NULL; (pos) = list_next_entry(pos, member))

#endif //_SPLIST_H_
