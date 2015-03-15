/*
 =====================================================================================
        Filename:  1.1判断一个字符串中的字符是否唯一.cpp
     	Description:  
        Version:  1.0
        Created:  07/03/15 06:36:51
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

/*
 * 	两种思路:
 * 	思路一:
 * 		1.使用一个256大小的数组保存，初始化false
 * 		2.循环字符串，如果发现数组中的内容是true，则是重复的，否则不重复
 *
 * 	思路二:(减少存储空间)
 * 		1.使用一个int型数组，8个元素总共256位
 * 		下标0 1-4字节存储1~32
 *		小标1 5-8字节存储33~64
 *		....
 * 		2.例如'b'对应的数字是98,则应该存储在98/32 = 3存在data[3],放在其中的98%32个位上。
 *
 *	//纯字符串的情况使用一个整形存放即可
 */


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isUnique1(string s)
{
	
	bool data[257];
	memset(data,0,sizeof(data));
	for(auto ch : s)
	{
		if(data[ch] == false) 
			data[ch] = true;
		else
			return false;
	}
	
	return true;

}

bool isUnique2(string s)
{
	int data[8];
	memset(data,0,sizeof(data));
	for(auto ch : s)
	{
		int index = ch / 32;
		int bits = ch % 32;
		if(data[index] &(1 << bits)) 
			return false;
		else
			data[index] |= (1 << bits);
	}
	return true;
}

int main()
{
	cout << isUnique1("zhangyi") << endl;
	cout << isUnique2("zhangyi") << endl;
	cout << isUnique1("zhangyiz") << endl;
	cout << isUnique2("zhangyiz") << endl;

}
