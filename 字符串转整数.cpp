/*
 =====================================================================================
        Filename:  字符串转整数.cpp
     	Description:  字符串转换为整数，要考虑的情况比较复杂
        Version:  1.0
        Created:  04/03/15 05:39:20
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <limits>
using namespace std;


//最简单的情况，不考虑任何异常情况
int StrtoInt_v1(const string str)
{
	int sum = 0;
	for(auto ch : str)
	{
		sum = sum*10 + (ch - '0');
	}
	//cout << sum << endl;	
	return sum;
}

//考虑含有特殊字符
int StrtoInt_v2(const string str)
{
	int sum = 0;
	for(auto ch : str)
	{
		if(ch >= '0' && ch <= '9')
			sum = sum*10 + (ch - '0');
		else
			return sum;
	}
	//cout << sum << endl;	
	return sum;
}



//考虑正负数符号问题
int StrtoInt_v3(const string str)
{
	int sum = 0;
	int flag = 1;
	auto start = str.begin();
	//设置符号的
	if (str[0] == '-') {
		flag = -1;
		start = ++start;
	}
	for(auto ch = start;ch != str.end();ch++)
	{
		if (*ch >= '0' && *ch <= '9') {
			sum = sum*10 + (*ch - '0');
		}	
		else
			return sum*flag;
	}
	//cout << sum << endl;	
	return sum*flag;
}

//考虑输入的空字符串的问题 

int StrtoInt_v4(const string str)
{
	if (str.empty())
		return 0;

	int sum = 0;
	int flag = 1;
	auto start = str.begin();
	//设置符号
	if (str[0] == '-') {
		flag = -1;
		start = ++start;
	}
	for(auto ch = start;ch != str.end();ch++)
	{
		if (*ch >= '0' && *ch <= '9') {
			sum = sum*10 + (*ch - '0');
		}	
		else
			return sum*flag;
	}
	//cout << sum << endl;	
	return sum*flag;
}

//考虑整型溢出问题
long long StrtoInt_v5(const string str)
{
	if (str.empty())
		return 0;

	long long sum = 0; //改成long long类型
	int flag = 1;
	auto start = str.begin();
	//设置符号位
	if (str[0] == '-') {
		flag = -1;
		start = ++start;
	}
	for(auto ch = start;ch != str.end();ch++)
	{
		if (*ch >= '0' && *ch <= '9') {
			if(((numeric_limits<long long>::max() / 10)- (*ch -0)) <= sum)   //判断是否越界
				sum = sum*10 + (*ch - '0');
			else  //越界
				return numeric_limits<long long>::max()*flag;
		}	
		else
			return sum*flag;
	}
	//cout << sum << endl;	
	return sum*flag;
}
int main()
{
	cout << StrtoInt_v1("545456") << endl;
	cout << StrtoInt_v2("54a5456") << endl;
	cout << StrtoInt_v3("-54a5456") << endl;
	cout << StrtoInt_v4("") << endl;
	cout << StrtoInt_v5("423432435435465767687687979808098654643") << endl;
}
