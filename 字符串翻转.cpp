/*
 =====================================================================================
        Filename:  字符串翻转.cpp
     	Description:  翻转一个字符串
        Version:  1.0
        Created:  16/02/15 04:40:52
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <string>
using namespace std;


//方法一
//递归翻转

void reverse1(std::string &str,int i,int j)
{
	if (i <= j) {
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
		reverse1(str,++i,--j);
	}
		
}


//方法二
//从两边开始交换

void reverse2(std::string &str)
{
	int i = 0;
	int j = str.size()-1;
	while(i <=j )
	{	
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}

int main()
{
	std::string name = "zhangyifei";
	//reverse2(name);
	reverse1(name,0,name.size()-1);
	std::cout << name << std::endl;
}
