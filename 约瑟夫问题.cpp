/*
 =====================================================================================
        Filename:  约瑟夫问题.cpp
     	Description:  使用单链表解决约瑟夫问题
        Version:  1.0
        Created:  10/02/15 13:30:40
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include "linknode.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//单循环链表实现更简单，单链表实现需要考虑边界条件。
int main()
{
	List head = NULL;
	head = MakeEmpty(NULL);
	int M = 6,N = 5;
	//初始化
	for(int i = N;i >0;i--)
	{
		Insert(i,head,head);
	}
	int stop = 0;
	int count = 1;
	List tmp = head->Next;
	List prev = head;
	List t;
	if(M == 0){
		printf("data:%d\n",N);
		return 0;
	}
	while(!IsEmpty(head))
	{
		if((count % M) == 0)
		{
			printf("data:%d\n",tmp->Element);
			//删除中间节点
			//单链表情况下要考虑边界条件
			if(tmp->Next != NULL)
			{
				t = tmp->Next;
				prev->Next = t;
				free(tmp);
				tmp = t;
			}
			else
			{
				prev->Next = NULL;
				free(tmp);
				tmp = head->Next;
			}			
				count = 1;
				continue;
		}
		//单链表情况下要考虑边界条件
		if(tmp->Next == NULL && head->Next != NULL)
		{
			prev = head;
			tmp = head->Next;
		}
		else if(head->Next)
		{
			prev = tmp;
			tmp = tmp->Next;
		}
		count++;
	}
}
