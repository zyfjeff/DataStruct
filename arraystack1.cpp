/*
 =====================================================================================
        Filename:  arraystack1.cpp
     	Description:  栈的数组实现
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
#include "arraystack1.h"

using namespace std;
int IsEmpty(Stack S)
{
	return S->Top == STACKEMPTY;
}

Stack CreateStack(int maxelements)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	assert(S != NULL);
	S->data = (ElementType *)malloc(sizeof(ElementType)*maxelements);
	S->maxsize = maxelements;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S)
{
	free(S->data);
	free(S);
}

void MakeEmpty(Stack S)
{
	S->Top = STACKEMPTY;
}

void Push(ElementType X,Stack S)
{
	if(S->Top+1 <= S->maxsize)
		S->data[++S->Top] = X;
}

ElementType Top(Stack S)
{
	assert(!IsEmpty(S));
	return S->data[S->Top];
	
}

void Pop(Stack S)
{
	if(!IsEmpty(S)){
		S->Top--;
	}
}

