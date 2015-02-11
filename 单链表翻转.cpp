/*
 =====================================================================================
        Filename:  单链表翻转.cpp
     	Description:  递归和非递归实现链表翻转
        Version:  1.0
        Created:  10/02/15 23:44:51
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <stdio.h>
#include <iostream>
#include "linknode.h"

using namespace std;

//非递归版本，头插法插入即可
List reverse(List L)
{
	List head;
	head = L->Next;
	L->Next = NULL;
	while(head != NULL) //遍历所有元素依次插入
	{
		Insert(head->Element,L,L);
		head = head->Next;
	}
	return L;
}

//递归版本,只是递归输出，并没有修改链表的结构
void reverse1(List node) //node是元素节点，不是头结点
{
	if(!node)
		return;
	else{
		reverse1(node->Next);
		printf("data:%d\n",node->Element);
	}
}

//递归版本,修改链表的结构

List reverse4(List Node) //Node是元素节点，非头结点
{
	if(Node == NULL || Node->Next == NULL)
		return Node;
	List New_Node = reverse4(Node->Next); //指向后续节点的尾部节点
	Node->Next->Next = Node; //前后节点翻转
	Node->Next = NULL;
	return New_Node;  //总是返回最后一个节点，最后的节点就是翻转后的头结点
} 



//O(1)空间 实现翻转
//思路摘节点，接上节点
List reverse2(List L)
{
	List head = L->Next;
	L->Next = NULL;
	List t;
	while(head != NULL)
	{
		t = head->Next;//保存下一个节点
		head->Next = L->Next; //接入到头结点L后
		L->Next = head;
		head = t; //继续遍历下一个节点
	}
	return L;
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
	
//	head = reverse2(head);
//	head = reverse(head);
//	head->Next = reverse4(head->Next);
	head->Next = reverse4(head->Next);

	List p = head;
	while(!IsEmpty(p))
	{
		cout << p->Next->Element << endl;
		p = p->Next;
	}

}

