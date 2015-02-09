/*
 =====================================================================================
        Filename:  linkstack1.cpp
     	Description:  链栈的实现
        Version:  1.0
        Created:  09/02/15 15:30:23
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "linkstack1.h"

using namespace std;
int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	assert(S != NULL);
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S)
{
	Stack tmp;
	while(S->Next != NULL)
	{	
		tmp = S->Next;
		S->Next = S->Next->Next;
		free(tmp);
	}
	free(S);
}
void MakeEmpty(Stack S)
{
	assert(S != NULL);
	while(!IsEmpty(S))
		Pop(S);
}

void Push(ElementType X,Stack S)
{
	Stack node = (Stack)malloc(sizeof(struct Node));
	assert(node != NULL);
	node->Element = X;
	node->Next = S->Next;
	S->Next = node;
}

ElementType Top(Stack S)
{
	ElementType value;
	value = S->Next->Element;
	return value;
	
}

void Pop(Stack S)
{
	if(!IsEmpty(S)){
		Stack tmp = S->Next;
		S->Next = S->Next->Next;
		free(tmp);
	}
}

