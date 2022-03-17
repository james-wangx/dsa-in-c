/**
 * @file queue.h
 * @date 2022-03-17
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Queue ADT
 */

#ifndef _DSAA_QUEUE_H
#define _DSAA_QUEUE_H

#include <stdbool.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

Queue QueueInit(int max_element);
bool QueueIsEmpty(const Queue queue);
bool QueueIsFull(const Queue queue);
void QueueIn(Queue queue, ElementType element);
void QueueOut(Queue queue);
void QueueEmpty(Queue queue);
void QueueDispose(Queue queue);
ElementType QueueFront(const Queue queue);
ElementType QueueFrontAndOut(Queue queue);

#endif // _DSAA_QUEUE_H
