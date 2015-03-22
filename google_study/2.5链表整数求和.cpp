/*
 =====================================================================================
        Filename:  2.5链表整数求和.cpp
     	Description:  
        Version:  1.0
        Created:  21/03/15 01:56:49
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


/*
 * 	给定两个链表，位数按倒序/正序排列.求两个链表表示的数的和
 *
 *
 */

#include <iostream>
#include "linknode.h"
#include <math.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int getSum(List head1,List head2)
{
	int sum1 = 0;
	int sum2 = 0;
	int count = 0;
	while(head1->Next != NULL)
	{
		sum1 = sum1+(head1->Next->Element*pow(10,count));
		count++;
		head1 = head1->Next;
	}
	count = 0;
	while(head2->Next != NULL)
	{
		sum2 = sum2+(head2->Next->Element*pow(10,count));
		count++;
		head2 = head2->Next;
	}
	return sum1+sum2;
}


int main()
{
	List head = (List)malloc(sizeof(struct Node));
        Insert(5,head,head);
        Insert(4,head,head);
        Insert(7,head,head);
	List head2 = (List)malloc(sizeof(struct Node));
        Insert(1,head2,head2);
        Insert(1,head2,head2);
        Insert(1,head2,head2);
	cout << "sum:" << getSum(head,head2)<<endl;
}
