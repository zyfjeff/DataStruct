/*
 =====================================================================================
        Filename:  字符串移动.cpp
     	Description:  指定要移动的字符串个数
        Version:  1.0
        Created:  16/02/15 05:59:26
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

//解法一
//暴力移位法
//移动1位
void _movestr1(char *str,int n)
{
	int tmp = str[0];
	for(int i = 0;i < n-1;i++)
		str[i] = str[i+1];
	str[n-1] = tmp;
}
//移动N位
void movestr1(char *str,int n,int k)
{
	for(int i = 0;i < k;i++)
		_movestr1(str,n);
}

//三步翻转法
//字符串翻转
void _movestr2(char *str,int start,int end)
{
	while(start <= end)
	{
		char c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}
}

void movestr2(char *str,int n,int k)
{
	_movestr2(str,0,k-1);
	_movestr2(str,k,n-1);
	_movestr2(str,0,n-1);
	
}

/*
 *
 *	相关翻转类型的题
 *	1.链表翻转
 *
 */

int main()
{
	char name[]= "zhangyifei";
//	movestr1(name,10,5);
	movestr2(name,10,5);
	cout << name << endl;		
}


