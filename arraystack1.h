/*
 * =====================================================================================
 *
 *       Filename:  arraystack1.h
 *
 *    Description:  栈的数组方式的实现
 *
 *        Version:  1.0
 *        Created:  09/02/15 15:25:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeff (), zyfforlinux@163.com
 *   Organization:  Linux
 *
 * =====================================================================================
 */
#ifndef _ARRAYSTACK1_H_
#define _ARRAYSTACK1_H_

typedef int ElementType;
struct Node
{
	ElementType *data;
	int Top;
	int maxsize;
};

typedef struct Node* Stack;

int IsEmpty(Stack S);
Stack CreateStack(int maxelements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
#define STACKEMPTY (-1)
#define MINISTACKSIZE 5


#endif // _LINKSTACK1_H_ 
