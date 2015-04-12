/*
 =====================================================================================
        Filename:  判断链表相交.cpp
     	Description:  带头指针，判断两个链表是否相交
        Version:  1.0
        Created:  16/02/15 02:15:58
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <stdlib.h>
#include "linknode.h"

using namespace std;

int getlistlen(List data)
{
	int count = 0;
	while(data != NULL) {
		count++;
		data = data->Next;
	}
	return count;
}


List Is_intersect(List headA,List headB)
{
	List A = headA->Next;
	List B = headB->Next;
	int lenA = getlistlen(A);
	int lenB = getlistlen(B);
	int len = (lenA > lenB ? lenA-lenB : lenB-lenA);
	
	while(len > 0) {
		A = A->Next;
		len--;
	}
	
	while(A != NULL && B != NULL)
	{
		if(A == B)
			break;
		else{
			A = A->Next;
			B = B->Next;
			continue;
		}
	}
	if(A != NULL && B != NULL)
		return A;
	else
		return NULL;
}


int main()
{
	List head1;
	head1 = MakeEmpty(NULL);
	List head2;
	head2 = MakeEmpty(NULL);
	Insert(4,head1,head1);
	Insert(5,head1,head1);
	Insert(6,head1,head1);
	Insert(7,head1,head1);
//	PrintList(head1);
	head2->Next = head1->Next->Next;
	List newlist = Is_intersect(head1,head2);
	while(newlist != NULL) {
		cout << newlist->Element << endl;
		newlist = newlist->Next;
	}
	
}
