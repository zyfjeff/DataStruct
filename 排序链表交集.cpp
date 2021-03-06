/*
 =====================================================================================
        Filename:  排序链表交集.cpp
     	Description:  求两个排序的链表的交集
        Version:  1.0
        Created:  10/02/15 12:41:44
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <stdlib.h>
#include <iostream>
#include "linknode.h"


using namespace std;


List Intersect(List A,List B)
{
	List head1,head2,head3;
	head1 = A->Next;
	head2 = B->Next;
	head3 = MakeEmpty(NULL);
	Position headpos = head3;
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->Element == head2->Element){
			Insert(head1->Element,head3,headpos);
			headpos = headpos->Next;
			head1 = head1->Next;
			head2 = head2->Next;
		}else if(head1->Element > head2->Element)
		{
			head2 = head2->Next;
		}else
			head1 = head1->Next;
	}
	return head3;
	
}


int main()
{
	//头结点
	List head = (List)malloc(sizeof(struct Node));
	List head2 = (List)malloc(sizeof(struct Node));
	Insert(9,head,head);
	Insert(8,head,head);
	Insert(7,head,head);
	Insert(6,head,head);
	Insert(5,head,head);
	Insert(4,head,head);
	Insert(3,head,head);
	
	Insert(12,head2,head2);
	Insert(11,head2,head2);
	Insert(6,head2,head2);
	Insert(5,head2,head2);
	Insert(4,head2,head2);
	Insert(3,head2,head2);
	Insert(2,head2,head2);
	
	List p = Intersect(head,head2);

	while(!IsEmpty(p))
	{
		cout << p->Next->Element << endl;
		p = p->Next;
	}
}	
