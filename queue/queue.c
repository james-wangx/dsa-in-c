/**
 * @file queue.c
 * @date 2022-03-17
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief The implementation of queue ADT
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define min_queue_size 5

#define throw_error(str) fprintf(stderr, "%s\n", str)

// Queue implementation is a dynamically allocated array.
struct QueueRecord {
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *array;
};

/**
 * @brief 
 * 
 * @param queue 
 * @param pos 
 * @return int 
 */
static inline int __queue_succ(Queue queue, int pos)
{
	if (++pos == queue->capacity)
		pos = 0;

	return pos;
}

/**
 * @brief Create an empty queue and return it.
 * 
 * @param max_element 
 * @return Queue 
 */
Queue QueueInit(int max_element)
{
	if (max_element < min_queue_size) {
		throw_error("Queue size is too small.");
		exit(EXIT_FAILURE);
	}

	Queue queue = malloc(sizeof(struct QueueRecord));
	queue->array = malloc(sizeof(ElementType) * max_element);
	queue->capacity = max_element;
	QueueEmpty(queue);

	return queue;
}

/**
 * @brief Return true if queue is empty.
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool QueueIsEmpty(const Queue queue)
{
	return queue->size == 0;
}

/**
 * @brief Return true if queue is full.
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool QueueIsFull(const Queue queue)
{
	return queue->size == queue->capacity;
}

/**
 * @brief Let element enter queue.
 * 
 * @param queue 
 * @param element 
 */
void QueueIn(Queue queue, ElementType element)
{
	if (QueueIsFull(queue))
		throw_error("Queue is full");
	else {
		queue->rear = __queue_succ(queue, queue->rear);
		queue->array[queue->rear] = element;
		queue->size++;
	}
}

/**
 * @brief Let element out queue.
 * 
 * @param queue 
 */
void QueueOut(Queue queue)
{
	if (QueueIsEmpty(queue))
		throw_error("Queue is Empty");
	else {
		queue->front = __queue_succ(queue, queue->front);
		queue->size--;
	}
}

/**
 * @brief Make queue empty.
 * 
 * @param queue 
 */
void QueueEmpty(Queue queue)
{
	queue->front = 1;
	queue->rear = 0;
	queue->size = 0;
}

/**
 * @brief Dispose queue.
 * 
 * @param queue 
 */
void QueueDispose(Queue queue)
{
	if (queue != NULL) {
		free(queue->array);
		free(queue);
	}
}

/**
 * @brief Find front element of the queue.
 * 
 * @param queue 
 * @return ElementType 
 */
ElementType QueueFront(const Queue queue)
{
	if (QueueIsEmpty(queue)) {
		throw_error("Queue is empty.");
		return 0; // Return value used to avoid warning
	}

	return queue->array[queue->front];
}

/**
 * @brief Find front element of the queue and let it out.
 * 
 * @param queue 
 * @return ElementType 
 */
ElementType QueueFrontAndOut(Queue queue)
{
	if (QueueIsEmpty(queue)) {
		throw_error("Queue is empty.");
		return 0; // Return value used to avoid warning
	}

	return queue->array[queue->front--];
}
