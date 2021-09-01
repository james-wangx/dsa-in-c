// s_list.c - 2021年 八月 30日
// 测试单链表

#include "s_list.h"

void show_books(Item *pi) {
    printf("title: %s\nauthor: %s\nprice: %.2f", pi->title, pi->author, pi->price);
    printf("\n------------------------------\n");
}

int main() {
    List books;
    Item temp;

    // 初始化链表
    list_init(&books);

    // 链表应该为空
    if (list_is_empty(books))
        printf("链表为空\n");

    printf("链表中的节点数：%d\n", list_count(books));

    // 加入一个节点
    temp.title = "C Primer Plus 第6版";
    temp.author = "史蒂芬·普拉达";
    temp.price = 108.00;
    list_append(&books, &temp);

    printf("链表中的节点数：%d\n", list_count(books));

    list_for_each(books, show_books);

    if (list_is_full())
        printf("链表已满");

    list_clean(&books);

    printf("链表中的节点数：%d\n", list_count(books));


    return 0;
}