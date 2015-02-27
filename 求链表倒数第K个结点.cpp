/*
 =====================================================================================
        Filename:  求链表倒数第K个结点.cpp
     	Description:  
        Version:  1.0
        Created:  27/02/15 12:55:23
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include "linknode.h"

Position GetK(List head,int k)
{
	List pos1,pos2;
	pos1 = head->Next;
	pos2 = head->Next;
	while(pos2 != NULL && k != 0)
	{
		pos2 = pos2->Next;
		k--;
	}
	if (pos2 != NULL) {
		while(pos2 != NULL)
		{
			pos2 = pos2->Next;
			pos1 = pos1->Next;
		}
	}
	else
		return NULL;
	return pos1;
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
	Position p = GetK(head,4);
	std::cout << p->Element << std::endl;
}
