/*
 =====================================================================================
        Filename:  自调整表.cpp
     	Description:  所有的插入都在表头进行，当一个元素被访问后将被移到表头，
	其余的项不改变
        Version:  1.0
        Created:  11/02/15 11:56:53
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "linknode.h"

using namespace std;


void self_adjust(Position pos,List head)
{
	Position befor = FindPrevious(pos->Element,head);
	befor->Next = pos->Next;
	pos->Next = head->Next;
	head->Next = pos;
}


bool find(ElementType x,List L)
{
	Position pos;
	if((pos = Find(x,L)) == NULL)
		return false;
	else{
		self_adjust(pos,L);
		return true;
	}
}


int main()
{
	List head = MakeEmpty(NULL);
	Insert(1,head,head);	
	Insert(2,head,head);	
	Insert(3,head,head);	
	Insert(4,head,head);	
	Insert(5,head,head);	
	Insert(6,head,head);	
	Insert(7,head,head);	
	Insert(8,head,head);	
	PrintList(head);
	find(4,head);
	cout <<"===========" <<endl;
	PrintList(head);
}
