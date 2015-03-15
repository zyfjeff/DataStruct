/*
 =====================================================================================
        Filename:  1.4检测旋转字符串.cpp
     	Description:  
        Version:  1.0
        Created:  07/03/15 20:38:44
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


/*
 * 	判定一个字符串是否是另外一个字符串的旋转字符串(只能使用一次strchr)
 * 	例如: s1 = "waterbottle" 是 s2 = "erbottlewat"的旋转字符串 
 * 	编程思路:
 * 		思路: 对s1每旋转一次判断是下是否是s2的子串，但是题目要求只能使用一次求子串的方法
 * 		,那么只能先改变s1使得可以一次性判断s1是否是s2的子串了，可以考虑加长s1，
 * 		s1 + s1 = waterbottlewaterbottle 发现这样一加使得s1中的每一个字符都旋转了一遍.
 * 		再次判断s2是否是s1的子串即可。
 * 		
 *
 */

#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

bool IsRotating(const char *s1,const char *s2)
{
	char buf[strlen(s1)*2+1];
	snprintf(buf,sizeof(buf),"%s%s",s1,s1);
	char *p = strstr(buf,s2);
	return p != NULL;

}


int main()
{
	cout << IsRotating("waterbottle","erbottlewat") << endl;
}
