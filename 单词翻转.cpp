/*
 =====================================================================================
        Filename:  单词翻转.cpp
     	Description:  翻转一句英文中的单词
        Version:  1.0
        Created:  16/02/15 19:39:07
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <ctype.h>

using namespace std;

void reverse(char *str,int start,int end);

void parse_word(char *data,int start,int len)
{
	int i = start;
	int firstpos = start;
	int lastpos = start;
	if(start < len-1)
	{
		while(i < (len-1))
		{
			if(!isalpha(data[i]))
				i++;
			else
				break;
		}
		if(i >= (len-1))
			return;
		else
			firstpos = i;

		while(i <= (len-1))
		{
			if(isalpha(data[i]))
				i++;
			else
				break;
		}
		if((i-1) > (len-1))
			return;
		else
			lastpos = i-1;
		reverse(data,firstpos,lastpos);
		parse_word(data,lastpos+1,len);
	}

}
	
void reverse(char *str,int start,int end)
{
        int i = start;
        int j = end;
        while(i <= j )
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
	
	char str[] = " zhang yi fei";
	parse_word(str,0,13);
	cout << str << endl;
}
