/*
 =====================================================================================
        Filename:  二元查找树转排序链表.c
     	Description:  二元查找树，转变成排序的双向链表
        Version:  1.0
        Created:  08/02/15 07:41:33
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include "bsttree.h"

using namespace std;

//指向新双向链表的头节点和尾节点
SearchTree pListIndex = NULL;
SearchTree pHead = NULL;

void convertToDoubleList(SearchTree pCurrent)
{

    pCurrent->Left = pListIndex;
    if (NULL != pListIndex)
    {
        pListIndex->Right = pCurrent;
    }
    else
    {
        pHead = pCurrent;
    }
        pListIndex = pCurrent;
}

void ChangeList(SearchTree T)
{
	if (T != NULL) {
	    ChangeList(T->Left);
	    //进行转化
	    convertToDoubleList(T);
	    ChangeList(T->Right);
	}
	
}


int main()
{
	SearchTree p;
	p = MakeEmpty(NULL);

	p = Insert(4,p);
	p = Insert(3,p);
	p = Insert(2,p);
	p = Insert(5,p);
	p = Insert(6,p);
	ChangeList(p);

	while(pHead != pListIndex)
	{
		cout << pHead->Element << endl;
		pHead =  pHead->Right;
	}
	
}
