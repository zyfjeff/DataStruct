/*
 =====================================================================================
        Filename:  选择排序.cpp
     	Description:  
        Version:  1.0
        Created:  08/03/15 15:59:05
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
using namespace std;

void ChooseSort(int *data,int size)
{
	int min;
	int index;
	for(int i = 0;i < size;i++)
	{	
		min = data[i];
		index = i;
		for(int j = i+1;j < size;j++)
		{
			if(data[j] < min)
			{
				min = data[j];
				index = j;	
			}
		}
		//交换两个数
		int tmp = data[index];
		data[index] = data[i];
		data[i] = tmp;
	}
	
}


int main()
{
	int data[] = {1,4,5,7,2,3,8};
	ChooseSort(data,sizeof(data)/sizeof(data[0]));
	for(int i = 0;i < sizeof(data)/sizeof(data[0]);i++)
		cout << data[i] << endl;
}
