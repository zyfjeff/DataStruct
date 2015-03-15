/*
 =====================================================================================
        Filename:  2.1链表去除重复.cpp
     	Description:  
        Version:  1.0
        Created:  07/03/15 21:08:36
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

/*
 * 	编程思路:
 * 		使用一个数组来保存访问过的元素。如果元素的值不是整形那么最好使用哈希表来保存
 * 		使用尾插法一个一个插入已经访问过的并且没有重复的元素
 *
 *
 *
 */

#include <iostream>
#include <list>
#include <map>

using namespace std;


int main()
{
	list<int> data;
	list<int> back;
	map<int,bool> flag;
	data.push_back(7);
	data.push_back(8);
	data.push_back(9);
	data.push_back(6);
	data.push_back(7);
	
	for(auto ch : data) {
		if (flag.find(ch) == flag.end()) { //不存在
			flag.insert({ch,true});
			back.push_back(ch);
		} else {
			continue;
		}
	}
	
	for(auto ch : back) {
		cout << ch << endl;
	}
	
}
