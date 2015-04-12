/*
 =====================================================================================
        Filename:  堆排序.cpp
     	Description:  
        Version:  1.0
        Created:  04/03/15 14:44:25
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include "binheap.h"
#include <iostream>

using namespace std;

//向下调整
void HeapAdjust(int *data,int s,int m)
{
	int temp,j;
	temp = data[s];
	//遍历子进程
	for(j = 2*s;j <= m;j*=2)
	{
		//左右子进程，找处值较大的子进程
		if(j < m && data[j] < data[j+1])
			++j;

		if(temp >= data[j]) //找到合适的位置插入
			break;
		data[s] = data[j];
		s = j;
	}
	data[s] = temp;
}

void HeapSort(int *data,int length)
{
	int i = 0;
	for(i = length/2;i > 0;i--)
		HeapAdjust(data,i,length);
	
	for(i = length;i > 1;i--)
	{
		swap(data[1],data[i]);
		HeapAdjust(data,1,i-1);
	}
}

int main()
{
	int data[] = {0,2,3,4,5,6,7};
	HeapSort(data,6);
	for(int i = 1;i < 7;i++)
		cout << data[i];

}
