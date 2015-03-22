/*
 =====================================================================================
        Filename:  2.4链表分割.cpp
     	Description:  
        Version:  1.0
        Created:  21/03/15 00:49:50
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


/*
 * 链表分割
 * 	编程思路:
 * 		将链表按照中间节点的大小进行分割，最后再合并两个链表
 *
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "linknode.h"

using namespace std;

List split_list(List head,ElementType data)
{
	List head2 = (List)malloc(sizeof(struct Node));
	List tmp = head->Next;
	head->Next = NULL;
	List tmp2;
	while(tmp)
	{
		if(tmp->Element >= data)
		{	
			//大于data的节点
			tmp2 = tmp->Next;
			tmp->Next = head->Next;
			head->Next = tmp;
			tmp = tmp2;	
		}else {
			//小于data的节点
			tmp2 = tmp->Next;
			tmp->Next = head2->Next;
			head2->Next = tmp;
			tmp = tmp2;
		}
	}
	List pos = head2;
	while(head2->Next != NULL)head2=head2->Next;
	head2->Next = head->Next;
	head = pos;
	free(pos);
	return head;
}

int main()
{
	List head = (List)malloc(sizeof(struct Node));
        Insert(5,head,head);
        Insert(4,head,head);
        Insert(7,head,head);
        Insert(3,head,head);
        Insert(9,head,head);
	head = split_list(head,5);
	List P = head->Next;  

        while(!IsLast(P,head))
        {
                cout << P->Element << endl;
                P = P->Next;
        }
}
