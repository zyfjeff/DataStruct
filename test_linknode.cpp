/*
 =====================================================================================
        Filename:  test_linknode.c
     	Description:  测试单链表
        Version:  1.0
        Created:  04/02/15 06:08:00
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include "linknode.h"
#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST(EmptyTest,Demo)
{
	List head = (List)malloc(sizeof(struct Node));
	Insert(5,head,head);
	Insert(6,head,head);
	Insert(7,head,head);
	Insert(8,head,head);
	Insert(9,head,head);
	EXPECT_EQ(false,IsEmpty(head));
	List P = head->Next;
	while(!IsLast(P,head))
	{
		cout << P->Element << endl;
		P = P->Next;
	}
}
