/*
 =====================================================================================
        Filename:  test_linkstack1.cpp
     	Description:  测试链栈
        Version:  1.0
        Created:  09/02/15 15:40:36
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include "linkstack1.h"

using namespace std;

int main()
{
	Stack S = CreateStack();
	Push(54,S);
	Push(55,S);
	cout << Top(S); // 输出55 
	cout << endl;
	Push(56,S);
	Push(57,S);
	Push(58,S);
	Push(59,S);
	// 59 58 57 56 55 54
	while(!IsEmpty(S))
	{
		cout << "top:";
		cout << Top(S) << endl;
		Pop(S);
	}
	Push(44,S);
	DisposeStack(S);

}

