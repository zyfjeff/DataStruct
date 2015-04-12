/*
 =====================================================================================
        Filename:  插入排序.cpp
     	Description:  插入排序
        Version:  1.0
        Created:  27/02/15 23:37:34
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

void InsertSort4(int *data,int len)
{
	int i,j;
	for(i = 1;i < len;i++)
	{
		int tmp = data[i]; //待排序元素
		for(j = i; j > 0 && data[j-1] > tmp;j--)
			data[j] = data[j-1]
		data[j] = tmp;
	}

}

void InsertSort3(int *data,int length)
{
	int p,tmp;
	for(int i = 1; i < length; i++)
	{
		tmp = data[i]; //待插入排序的数
		for(p = i; p > 0 && data[p - 1] > tmp;p--)
			data[p] = data[p - 1];
		data[p] = tmp;
	}
}


void InsertSort2(int *data,int length)
{
	int tmp;
	int p;
	for(int i = 1; i < length;i++)
	{
		tmp = data[i];
		for(p = i; p > 0 && data[p-1] > tmp;p--)
			data[p] = data[p - 1];
		data[p] = tmp;	
	}

}


void InsertSort(int *data,int length)
{
	int j,p;
	int tmp;
	//length-1趟
	for(p = 1;p < length;p++)
	{
		tmp = data[p]; //将这个元素依次插入到之前的p-1个序列中
		for(j= p;j > 0 && data[j -1] > tmp;j--) //找到第一个小于data[p]
			data[j] = data[j-1];
		data[j] = tmp;
	}		
}

int main()
{
	int data[] = {1,3,4,5,2,7,6};
	InsertSort2(data,7);
	for(auto elem : data)
	std::cout << elem << std::endl;	
}
