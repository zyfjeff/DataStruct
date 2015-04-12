/*
 =====================================================================================
        Filename:  binheap.cpp
     	Description:  优先队列
        Version:  1.0
        Created:  28/02/15 20:14:15
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include "binheap.h"
#define MinPoSize 15

/*
 * 	优先队列的初始化
 *
 */
PrioriityQueue Initialize(int MaxElements)
{
	PrioriityQueue H;
	assert(MaxElements > MinPoSize);
	H = (PrioriityQueue)malloc(sizeof(struct HeapStruct));
	assert(H != NULL);
	H->Elements = (ElementType*)malloc((MaxElements+1) * sizeof(ElementType));
	assert(H->Elements != NULL);
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = -1;
	return H;
}

void Destory(PrioriityQueue H)
{
	free(H->Elements);
	free(H);
}

void MakeEmpty(PrioriityQueue H)
{

}

/*
 *	优先队列的插入
 *	等同于插入排序
 */
void Insert(ElementType X,PrioriityQueue H)
{
	int i;
	if (IsFull(H)) {
		std::cout << "Priority queue is full" <<std::endl;
		return ;
	}
	for(i = ++H->Size;H->Elements[i / 2] > X;i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}
	
/*
 *	优先队列的删除最小值
 *	
 */
ElementType DeleteMin(PrioriityQueue H)
{
	int i,Child;
	ElementType MinElement,LastElement;
	if(IsEmpty(H))
	{
		std::cout << "PrioriityQueue is Empty" << std::endl;
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	for(i = 1;i*2 <= H->Size;i = Child)
	{
		Child = i*2;
		//找最小孩子节点
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
			Child++;
		//比较大小
		if (LastElement > H->Elements[Child])
			H->Elements[i] = H->Elements[Child];
		else
			break;
	}
	H->Elements[i] = LastElement; //最后节点放到最终位置上
	return MinElement;
}

ElementType FindMin(PrioriityQueue H)
{
	if (!IsEmpty(H))
	{
		return H->Elements[1]; //堆顶元素为最小
	
	} else {

		return -1;
	}
}

/*
 * 	优先队列是否为空
 *
 */
int IsEmpty(PrioriityQueue H)
{
	return H->Size == 0;
}

/*
 *	优先队列是否满 
 *
 */

int IsFull(PrioriityQueue H)
{
	return H->Size == H->Capacity;
}
