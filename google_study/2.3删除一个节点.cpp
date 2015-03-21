/*
 =====================================================================================
        Filename:  2.3删除一个节点.cpp
     	Description:  
        Version:  1.0
        Created:  20/03/15 01:07:47
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


/*
 * 
 *
 *
 */

#include "linknode.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void deletenode(List head,List pos)
{
	if(head == NULL)return;;
	if (pos->Next != NULL) {
		pos->Element = pos->Next->Element;
		pos->Next = pos->Next->Next;
	}
}


int main()
{
	List head = (List)malloc(sizeof(struct Node));
        Insert(5,head,head);
        Insert(6,head,head);
        Insert(7,head,head);
        Insert(8,head,head);
        Insert(9,head,head);
	List first = head->Next;
        List P = head->Next->Next->Next;
	deletenode(head,P);
	
        while(!IsLast(first,head))
        {
                cout << first->Element << endl;
                first = first->Next;
        }
               cout << first->Element << endl;
}	
