/*
 =====================================================================================
        Filename:  1.6字符串压缩.cpp
     	Description:  
        Version:  1.0
        Created:  15/03/15 09:09:26
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

void strzip(string &str)
{
	char c;
	vector<char> back;
	char last = str[0];
	int count = 0;
	
	for(auto ch : str)
	{	
		printf("%c",ch);
		if (ch == last) {
			count++;
		} else {
			sprintf(&c,"%d",count);
			back.push_back(last);
			back.push_back(c);
			count = 1;
			last = ch;
		}
	}
}


int main()
{
	string test="ddddddddddssssssaaddsadsassssss";
	strzip(test);
}
