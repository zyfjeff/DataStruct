/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  队列的数组实现
 *
 *        Version:  1.0
 *        Created:  10/02/15 11:20:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeff (), zyfforlinux@163.com
 *   Organization:  Linux
 *
 * =====================================================================================
 */
#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int ElementType;
struct QueueRecord
{
	int Capacity;
	int front;
	int rear;
	int size;
	ElementType *data;
};
typedef struct QueueRecord* Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X,Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);


#endif//end _QUEUE_H_

