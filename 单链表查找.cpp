/*
 =====================================================================================
        Filename:  单链表查找.cpp
     	Description:  单链表查找特定元素
        Version:  1.0
        Created:  10/02/15 23:23:58
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include "linknode.h"


//查找特定元素,递归版本
int Find(List L,ElementType data)
{
	if(L != NULL){
		if(L->Element == data)
			return 1;
		else
			Find(L->Next,data);
	}
	else
	{
		return 0;
	}
		
}

//非递归版本
int Find2(List L,ElementType data)
{
	while(!IsEmpty(L))
	{
		if(L->Element == data)
			return 1;
		else
			L = L->Next;
	}
	if(L->Element == data)
		return 1;
	return 0;
}

int main()
{
	List head;
	head = MakeEmpty(NULL);
	Insert(4,head,head);
	Insert(5,head,head);
	Insert(6,head,head);
	Insert(7,head,head);
	Insert(8,head,head);
	Insert(9,head,head);
	Insert(10,head,head);
	printf("%d\n",Find(head->Next,4));
	printf("%d\n",Find(head->Next,11));
	printf("%d\n",Find2(head->Next,4));
	printf("%d\n",Find2(head->Next,11));
}
