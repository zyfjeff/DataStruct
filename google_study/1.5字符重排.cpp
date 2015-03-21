/*
 =====================================================================================
        Filename:  1.5字符重排.cpp
     	Description:  
        Version:  1.0
        Created:  15/03/15 07:21:09
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

/*
 * 	两个字符串,重新排列下其中一个字符串，能否变成另外一个字符串
 * 	编程思路:
 * 		1.256的数组，初始为0.开始对第一个字符串hash，没遇见一次+1
 * 		 再对另外一个字符hash，如果遇到-1则return.如果没有遇到-1,遍历下255的数组判断是否有不为0的。
 *
 * 		2.排序字符串
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


bool rearrange(string &str1,string &str2)
{
	int data[256];
	bzero(data,sizeof(data));

	for(auto ch:str1)
	{
		data[ch]++;
	}
	for(auto ch:str2)
	{
		data[ch]--;
		if(data[ch] < 0)
			return false;
	}
	for(int i = 0;i < 256;i++)
		if(data[i] > 0)
			return false;
	return true;
}

int main()
{
	string zhang = "zhangyifei";
	string wang = "zhangfyiei";
	cout << rearrange(zhang,wang) << endl;
}
