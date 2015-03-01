/*
 =====================================================================================
        Filename:  顺序打印二叉树.cpp
     	Description:  按层从上往下 从左往右打印数据
        Version:  1.0
        Created:  01/03/15 03:53:01
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <queue>
#include "bsttree.h"

using namespace std;

void Print_tree(SearchTree p)
{
	queue<SearchTree> que;
	if(!p)
		return;
	que.push(p);
	while(que.size())
	{

		SearchTree t = que.front();
		cout << t->Element << endl;
		que.pop();
		if(t->Left != NULL)
			que.push(t->Left);
		if(t->Right != NULL)
			que.push(t->Right);
	}
	
	
}


int main()
{
	SearchTree p;
        p = MakeEmpty(p);
        p = Insert(4,p);
        p = Insert(5,p);
        p = Insert(6,p);
        p = Insert(1,p);
        p = Insert(2,p);
        p = Insert(3,p);
        
	MidPrint(p);

	cout << "befor change " << endl;
	Print_tree(p);
}
