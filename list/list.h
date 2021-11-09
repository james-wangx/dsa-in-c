// list.h - 2021/11/7
// Linux 内核链表

#ifndef _DSAA_LIST_H
#define _DSAA_LIST_H

/**
 * 获取结构或枚举中成员的偏移量
 *
 * @param TYPE 结构或枚举
 * @param MEMBER 结构或枚举中的成员
 */
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

/**
 * 获取 type 结构或枚举的地址
 *
 * @param ptr 指向成员的指针
 * @param type 结构或枚举类型
 * @param member 结构或枚举的成员名
 */
#define container_of(ptr, type, member)                                        \
	({                                                                     \
		const typeof(((type *)0)->member) *__mptr = (ptr);             \
		(type *)((char *)__mptr - offsetof(type, member));             \
	})

struct list_head {
	struct list_head *next, *prev;
};
/**
 * 初始化一个 list_head 结构
 * @param list 将被初始化的 list_head 结构
 *
 * 初始化 list_head 指向它自己。如果它是一个表头，结果是一个空链表。
 */
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

/**
 * 在两个已知的结点间插入一个新的结点。
 *
 * 这仅适用于我们已经知道前驱或后继的内部链表操作。
 */
static inline void __list_add(struct list_head *new, struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

/**
 * 添加一个新的结点
 * @param new 将被添加的新结点
 * @param head 将要添加结点的链表头
 *
 * 在指定的链表头后插入一个新结点。这对实现堆栈有帮助。
 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

/**
 * 添加一个新结点
 * @param new 将被添加的新结点
 * @param head 将要添加结点的链表头
 *
 * 在指定的链表头前插入一个新节点。这对实现堆栈有帮助。
 */
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}

/**
 * 通过将待删除结点的前驱和后继指向彼此来删除结点。
 * @param prev 待删除结点的前驱
 * @param next 待删除结点的后继
 *
 * 这仅适用于我们已经知道前驱和后继的内部链表操作。
 */
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

/**
 * 删除链表中的结点
 * @param entry 将被删除的结点
 *
 * 注意：在此之后 list_empty() 将不会返回 true，entry 处于未定义状态。
 */
static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	entry->next = NULL;
	entry->prev = NULL;
}

/**
 * 替换链表内的结点
 * @param old 将被替换的旧结点
 * @param new 将要插入的新节点
 *
 * 如果旧结点是空的，它将被重写。
 */
static inline void list_replace(struct list_head *old, struct list_head *new)
{
	new->next = old->next;
	new->next->prev = new;
	new->prev = old->prev;
	new->prev->next = new;
}

/**
 * 获取该结点的结构
 *
 * @param ptr 指向成员的指针
 * @param type 结构或枚举类型
 * @param member 结构或枚举的成员名
 */
#define list_entry(ptr, type, member) container_of(ptr, type, member)

/**
 * 获取链表的首个结点
 *
 * @param ptr 链表头
 * @param type 链表父容器类型
 * @param member 链表在容器结构中的名称
 */
#define list_first_entry(ptr, type, member)                                    \
	list_entry((ptr)->next, type, member)

/**
 * 获取链表的下一个结点
 *
 * @param pos 指向链表容器的指针
 * @param member 链表在容器结构中的名称
 */
#define list_next_entry(pos, member)                                           \
	list_entry((pos)->member.next, typeof(*(pos)), member)

/**
 * 判断此结点是否是链表的头结点
 *
 * @param pos 指向链表容器的指针
 * @param head 你的链表头
 * @param member 链表在容器结构中的名称
 */
#define list_entry_is_head(pos, head, member) (&(pos)->member == (head))

/**
 * 遍历链表
 *
 * @param pos 一个链表头的地址，可以作为循环的游标
 * @param head 你的链表头
 */
#define list_for_each(pos, head)                                               \
	for ((pos) = (head)->next; (pos) != (head); (pos) = (pos)->next)

/**
 * 遍历链表
 *
 * @param pos 指向容器结构的指针
 * @param head 链表头指针
 * @param member 链表在容器结构中的名称
 */
#define list_for_each_entry(pos, head, member)                                 \
	for ((pos) = list_entry((head)->next, typeof(*(pos)), member);         \
	     &(pos)->member != (head);                                         \
	     (pos) = list_entry((pos)->member.next, typeof(*(pos)), member))

/**
 * 安全地遍历链表，避免删除结点后无法继续
 *
 * @param pos 指向容器结构体的临时位置指针
 * @param n 临时存储下一个位置
 * @param head 你的链表头
 * @param member 链表在容器结构体中的名称
 */
#define list_for_each_entry_safe(pos, n, head, member)                         \
	for ((pos) = list_first_entry(head, typeof(*(pos)), member),           \
	    (n) = list_next_entry(pos, member);                                \
	     !list_entry_is_head(pos, head, member);                           \
	     (pos) = (n), (n) = list_next_entry(n, member))

#endif // _DSAA_LIST_H