/*
 =====================================================================================
        Filename:  test_bsttree.cpp
     	Description:  测试二叉排序树
        Version:  1.0
        Created:  15/02/15 17:15:41
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include "bsttree.h"

using namespace std;

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
	
}
