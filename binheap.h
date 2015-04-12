/*
 * =====================================================================================
 *
 *       Filename:  binheap.h
 *
 *    Description:  优先队列(堆)的实现
 *
 *        Version:  1.0
 *        Created:  28/02/15 10:19:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeff (), zyfforlinux@163.com
 *   Organization:  Linux
 *
 * =====================================================================================
 */

#ifndef _BINHEAP_H
#define _BINHEAP_H

typedef int ElementType;

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};

typedef struct HeapStruct *PrioriityQueue;

PrioriityQueue Initialize(int MaxElements);
void Destory(PrioriityQueue H);
void MakeEmpty(PrioriityQueue H);
void Insert(ElementType X,PrioriityQueue H);
ElementType DeleteMin(PrioriityQueue H);
ElementType FindMin(PrioriityQueue H);
int IsEmpty(PrioriityQueue H);
int IsFull(PrioriityQueue H);

#endif // end _BINHEAP_H
