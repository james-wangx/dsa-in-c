/**
 * @file array_queue.h
 * @date 2023-02-15
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 数组模拟队列
 */
#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQueue {
    int max_size; // 队列的最大容量
    int *arr;     // 数组模拟队列，存放数据
    int front;    // 头指针
    int rear;     // 尾指针
} *ArrayQueue;


/**
 * 初始化队列，设置队列大小
 * @param size 队列大小
 * @return 队列
 */
ArrayQueue init(int size) {
    ArrayQueue queue = (struct ArrayQueue *) malloc(sizeof(struct ArrayQueue));
    queue->max_size = size;
    queue->arr = (int *) malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;

    return queue;
}


/**
 * 判断队列是否已满
 * @param queue 队列
 * @return true or false
 */
bool is_full(ArrayQueue queue) {
    return queue->rear == queue->max_size - 1;
}


/**
 * 判断队列是否是空的
 * @param queue 队列
 * @return true or false
 */
bool is_empty(ArrayQueue queue) {
    return queue->front == queue->rear;
}


/**
 * 添加元素
 * @param queue 队列
 * @param item 元素
 */
void add(ArrayQueue queue, int item) {
    if (is_full(queue)) {
        printf("队列已满！\n");
        return;
    }

    queue->arr[++queue->rear] = item;
}


/**
 * 出队列
 * @param queue 队列
 * @return 第一个元素
 */
int del(ArrayQueue queue) {
    if (is_empty(queue)) {
        printf("队列为空\n");
        return 0;
    }

    return queue->arr[++queue->front];
}


/**
 * 获取第一个元素
 * @param queue 队列
 * @return 第一个元素
 */
int head(ArrayQueue queue) {
    if (is_empty(queue)) {
        printf("队列为空\n");
        return 0;
    }

    return queue->arr[queue->front + 1];
}


/**
 * 显示当前队列
 * @param queue 队列
 */
void show(ArrayQueue queue) {
    if (is_empty(queue)) {
        printf("队列为空\n");
        return;
    }

    for (int i = queue->front + 1; i <= queue->rear; ++i) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}


#endif // DSA_QUEUE_H