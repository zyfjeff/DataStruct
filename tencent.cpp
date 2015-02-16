/*
 =====================================================================================
        Filename:  tencent.cpp
     	Description:  腾讯面试题,根据上排十个数，在其下排填出对应的十个数
        Version:  1.0
        Created:  16/02/15 01:52:22
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

int getcount(int *data,int len,int key)
{
	int count = 0;
	for(int i = 0;i < len;i++)
		if(data[i] == key)count++;
	return count;
}

int main()
{
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	int downarray[10];
	int changeflag = 0;
	bool flag = true;
	for(int i= 0;i < 10;i++)
		downarray[i] = 1;
	while(flag){
		changeflag = 0;
		for(int i = 0;i < 10;i++){
			int count =getcount(downarray,10,array[i]);
			if(count == downarray[i])
				continue;
			downarray[i] = count;
			changeflag = 1;
		}
		if(changeflag == 1)
			flag = true;
		else
			flag = false;
	}
	for(int i = 0;i < 10;i++)
	{
		cout << downarray[i] << endl;
	}
}
