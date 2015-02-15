/*
 =====================================================================================
        Filename:  包含min函数的栈.cpp
     	Description:  定义栈的数据结构，要求添加一个min函数
	能够得到栈的最小元素
        Version:  1.0
        Created:  15/02/15 22:06:06
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <stdlib.h>

using namespace std;
#define MAXSIZE 100

typedef int ElementType;
ElementType MINVALUE  = 10000000;

struct Stack
{
	ElementType *data;
	ElementType *Mindata;
	ElementType min;
	int top;
	int mintop;
	int size;
	
};

void StackInit(Stack *p)
{
	p->data = (ElementType*)malloc(MAXSIZE*sizeof(ElementType));
	p->Mindata = (ElementType*)malloc(MAXSIZE*sizeof(ElementType));
	p->min  = MINVALUE;
	p->top = -1;
	p->mintop = -1;
	p->size = MAXSIZE;
	
}

ElementType Mindata(Stack *p)
{
	return p->min;
}


bool IsEmpty(Stack *p)
{
	return p->top == -1;	
}

bool IsFull(Stack *p)
{
 	return p->top == p->size-1;
}

ElementType StackTop(Stack *p)
{
	if(!IsEmpty(p))
		return p->data[p->top];
}
void StackPush(Stack *p,ElementType data)
{
	if (!IsFull(p)) {
		p->data[++(p->top)] = data;
		if (data < p->min) { //update min value
			p->min = data;
			p->Mindata[++p->mintop] = data;
		}
	}
}	

void StackPop(Stack *p)
{
	if (!IsEmpty(p)) {
		if(StackTop(p) == p->min) { //update min value
			p->mintop--;
			if(p->mintop != -1)
				p->min = p->Mindata[p->mintop];
			else
				p->min = MINVALUE;
		}	
		p->top--;
	}
}


int main()
{
	Stack p;
	StackInit(&p);
	StackPush(&p,4);
	StackPush(&p,5);
	StackPush(&p,1);
	StackPush(&p,2);
	StackPush(&p,3);
	StackPush(&p,6);
	while(!IsEmpty(&p))
	{
		cout << StackTop(&p)<< endl;
		cout <<"minvalue: "<<Mindata(&p)<< endl;
		StackPop(&p);
	}
}
