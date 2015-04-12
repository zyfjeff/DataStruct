/*
 =====================================================================================
        Filename:  找第一次出现一次的字符.cpp
     	Description:  一串字符中，找处第一次只出现一次的字符
        Version:  1.0
        Created:  01/03/15 07:43:56
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char FirstNotRepeatingChar(const string pString)
{
	if(pString.empty())
		return 0;
	const int tablesize = 256;
	int hashtab[tablesize];
	
	//初始化,清零
	memset(hashtab,0,sizeof(hashtab));
	
	//第一次统计出现的次数
	for(auto ch : pString)
	{
		++hashtab[ch];
	}
	
	for(auto ch : pString)
	{
		if (hashtab[ch] == 1)
			return ch;
	}
}


int main()
{
	cout << FirstNotRepeatingChar("zhdhwjkhdgwdwqkxlhsjkahxjgashxgjksahxw") << endl;
}

