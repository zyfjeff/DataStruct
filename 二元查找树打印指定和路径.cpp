/*
 =====================================================================================
        Filename:  二元查找树打印指定和路径.cpp
     	Description:  查找从根节点到叶节点和等于某个指定值的路径
        Version:  1.0
        Created:  16/02/15 00:04:54
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <vector>
#include "bsttree.h"

using namespace std;

vector<ElementType> path;
ElementType destinonvalue = 9;


void printpath(const vector<ElementType> &path)
{
	for(int i = 0;i < path.size();i++)
		cout << path[i] << endl;
}
	
void findpath(SearchTree T,int count)
{
	if (T != NULL) {
		if(T->Left == NULL && T->Right == NULL && (count+T->Element == destinonvalue))
		{
			path.push_back(T->Element);
			printpath(path);
		}else
			path.push_back(T->Element);
		findpath(T->Left,count+T->Element);
		findpath(T->Right,count+T->Element);
	}
}


int main()
{
	SearchTree T;
	T = MakeEmpty(T);
	T = Insert(4,T);
	T = Insert(5,T);
	T = Insert(6,T);
	T = Insert(3,T);
	T = Insert(2,T);
	T = Insert(1,T);

	findpath(T,0);
	
}
