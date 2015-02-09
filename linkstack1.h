/*
 * =====================================================================================
 *
 *       Filename:  linkstack1.h
 *
 *    Description:  链栈的实现
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
#ifndef _LINKSTACK1_H_
#define _LINKSTACK1_H_

typedef int ElementType;
struct Node
{
	ElementType Element;
	struct Node* Next;
};

typedef struct Node* Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif // _LINKSTACK1_H_ 
