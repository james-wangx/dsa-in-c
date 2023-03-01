/**
 * @file array_queue.c
 * @date 2023-02-15
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 数组模拟队列
 */
#include "array_queue.h"

int main(void) {
    ArrayQueue queue = init(5);

    char choice;
    int item;
    while (true) {
        printf("\n用数组模拟队列\n");
        printf("a(add)： 添 加\n");
        printf("d(del)： 删 除\n");
        printf("h(head)：头 部\n");
        printf("s(show)：显 示\n");
        printf("e(exit)：退 出\n");
        printf("请输入：");
        if (scanf("%c", &choice) != 1) {
            printf("输入不正确，请重新输入\n");
            getchar();
            break;
        }
        getchar();
        switch (choice) {
            case 'a':
                scanf("%d", &item);
                getchar();
                add(queue, item);
                break;
            case 'd':
                del(queue);
                break;
            case 'h':
                item = head(queue);
                printf("%d\n", item);
                break;
            case 's':
                show(queue);
                break;
            case 'e':
                printf("Bye~");
                exit(EXIT_SUCCESS);
            default:
                printf("输入不正确，请重新输入\n");
                break;
        }
    }

    exit(EXIT_SUCCESS);
}
