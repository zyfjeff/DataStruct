/*
 =====================================================================================
        Filename:  1.2字符串翻转.cpp
     	Description:  
        Version:  1.0
        Created:  07/03/15 07:03:40
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


/*
 * 	编程思路:
 *		思路一: 首指针指向字符串头部，尾指针指向字符串尾部。从两头遍历，交换字符
 *		思路二: 只是用一个指针，使用其长度来计算对应要交换元素的位置。
 *
 *
 *
 *
 */
#include <iostream>
#include <cstring>

using namespace std;

void swap(char *data1,char *data2)
{
	int tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;

}

void reverse1(char *str)
{
	char *start = str;
	char *end = str+(strlen(str)-1);
	while(start < end)
	{
		swap(start,end);
		start++;
		end--;
	}
	
}

void reverse2(char *str)
{
	char *start = str;
	int n = strlen(str);
	for(int i = 0;i < n/2;++i)
	{
		swap(&str[i],&str[n-i-1]);
	}
}

int main()
{

	char buf[] = "zhangyifei";
	reverse1(buf);
	reverse2(buf);
	cout << buf << endl;
}


