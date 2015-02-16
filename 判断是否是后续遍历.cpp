/*
 =====================================================================================
        Filename:  判断是否是后续遍历.cpp
     	Description:  判断是否是一个合法的后续遍历
        Version:  1.0
        Created:  16/02/15 18:41:04
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include "bsttree.h"

using namespace std;
bool Is_after(int *data,int start,int end)
{
	if(start < end){
		int root = data[end];//根
		int i ,j;
		for(i = start;i <= end;i++)
		{
			if (data[i] > root) {
				break;
			}
	
		}

		for(j = i+1;j <= end;j++ )
		{
			if (data[j] < root) {
				return false;
			}
		}
		bool lret,rlet;
		lret = Is_after(data,start,i-1);
		rlet = Is_after(data,i,end-1);
		return (lret && rlet);
	}
}

int main()
{
	int data[] = {5,7,6,1,11,10,8};
	bool _ret = Is_after(data,0,6);
	cout << _ret << endl;
}
