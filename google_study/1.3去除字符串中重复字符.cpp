/*
 =====================================================================================
        Filename:  1.3去除字符串中重复字符.cpp
     	Description:  
        Version:  1.0
        Created:  07/03/15 09:38:10
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


/*
 * 	去除字符串中重复的字符，不能使用额外的缓存空间，可以使用额外的一个两个变量，
 * 	但是不允许额外再开一个数组拷贝
 *	
 *	编程思路:
 *		思路一:遍历字符，将与这个字符相同的字符置为*号,对于非空字符依次从0开始填入
 *		思路二:借助一个大小为256的辅助数组，来判断字符是否重复。
 *
 *
 *
 */

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void repeat1(char *str)
{
	
	int p = 0;
	int leng = strlen(str);
	char *strnext = str+1;
	for(int i = 0;i < leng;i++)
	{
		if (str[i] == '*') {
			continue;
		} else {
			str[p++] = str[i];
			for(int j = i+1;j < leng;j++)
			{
				if(str[i] == str[j])
					str[j] = '*';
			}
		}
	}
	str[p] = '\0'; //结束
}

//借用辅助数组

void repeat2(char *str)
{
	
	int p = 0;
	bool data[257];
	memset(data,0,sizeof(data));
	int leng = strlen(str);
	char *strnext = str+1;
	for(int i = 0;i < leng;i++)
	{
		if( !data[str[i]] )
		{
			str[p++] = str[i]; //
			data[str[i]] = true;
		}else {
			continue;
		}
	}
	str[p] = '\0'; //结束

}

int main()
{
	
	char buf[] = "zhangyifei";
//	repeat1(buf);
	repeat2(buf);
	cout << buf << endl;
}
