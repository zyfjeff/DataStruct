/*
 =====================================================================================
        Filename:  queue.cpp
     	Description:  队列的数组实现
        Version:  1.0
        Created:  10/02/15 11:42:54
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

static int Succ(int Value,Queue Q)
{
	if(++Value == Q->Capacity)
		Value = 0;
	return Value;
}


int IsEmpty(Queue Q)
{
	return Q->size == 0;
}

int IsFull(Queue Q)
{
	return Q->size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
	Queue ue = (Queue)malloc(sizeof(struct QueueRecord));
	ue->Capacity = MaxElements;
	ue->data = (ElementType*)malloc(sizeof(ElementType)*MaxElements);
	MakeEmpty(ue);
	return ue;
}

void DisposeQueue(Queue Q)
{
	free(Q->data);
	free(Q);	
}

//从下标1开始存放数据
void MakeEmpty(Queue Q)
{
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;
}

void Enqueue(ElementType X,Queue Q)
{
	assert(!IsFull(Q));
	Q->size++;
	Q->rear = Succ(Q->rear,Q);
	Q->data[Q->rear] = X;
}

ElementType Front(Queue Q)
{
	if(Q->size != 0)
		return Q->data[Q->front];
	return (ElementType)0;
}
void Dequeue(Queue Q)
{
	assert(!IsEmpty(Q));
	Q->size--;
	Q->front = Succ(Q->front,Q);
}

ElementType FrontAndDequeue(Queue Q)
{
	ElementType data = Front(Q);
	Dequeue(Q);
	return data;
}
