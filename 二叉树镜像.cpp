/*
 =====================================================================================
        Filename:  二叉树镜像.cpp
     	Description:  递归和非递归，实现左右子树交换
        Version:  1.0
        Created:  28/02/15 04:49:52
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include "bsttree.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


//递归解法
void GetMirror_r(SearchTree pRoot)
{
	if (pRoot == NULL)
		return;
	GetMirror_r(pRoot->Left);
	GetMirror_r(pRoot->Right);
	SearchTree left = pRoot->Left;
	pRoot->Left = pRoot->Right;
	pRoot->Right = left;
}

//非递归解法

void GetMirror(SearchTree pRoot)
{
	if(!pRoot)
		return;
	stack<SearchTree> back;
	back.push(pRoot);
	while(back.size())
	{
		SearchTree pnode = back.top();
		back.pop();
		//交换左右子树
		SearchTree left = pnode->Left;
  	        pnode->Left = pnode->Right;
       		pnode->Right = left;
		
		if(pnode->Left != NULL)
			back.push(pnode->Left);
		if(pnode->Right != NULL)
			back.push(pnode->Right);
	}
	
}





int main()
{
	SearchTree p;
        p = MakeEmpty(NULL);
        p = Insert(4,p);
        p = Insert(2,p);
        p = Insert(3,p);
        p = Insert(1,p);
        p = Insert(6,p);
        p = Insert(5,p);
        p = Insert(7,p);
	MidPrint(p);
	GetMirror(p);
	cout << "-----------" << endl;
	MidPrint(p); 
}
