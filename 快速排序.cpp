/*
 =====================================================================================
        Filename:  快速排序.cpp
     	Description:  快速排序及改进版本
        Version:  1.0
        Created:  01/03/15 17:03:12
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

void Swap(int *data1,int *data2)
{
	int tmp = *data1;
	*data2 = *data1;
	*data1 = tmp;
}

//版本一，简单版本
int QuickSort(int *data,int left,int right)
{
	int i = left,j = right;
	int key = data[left];  
	while(i < j)
	{
		while(i < j && data[j] >= key) j--;
		if(i < j)
			data[i++] = data[j];
	
		while(i < j && data[i] < key) i++;
		if(i < j)
			data[j--] = data[i];
	}
	data[i] = key;

	return i;
}

void Sort(int *data,int l,int r)
{
	if(l < r)
	{
		int ret = QuickSort(data,l,r);
		Sort(data,l,ret-1);
		Sort(data,ret+1,r);
	}
}


//第二版本
int Partition(int *data,int low,int high)
{
	//三数取中
	int m = low+(high-low)/2;
	if(data[low] > data[high])
		swap(data[low],data[high]);
	if(data[m] > data[high])
		swap(data[high],data[m]);
	if(data[m] > data[low])
		swap(data[low],data[m]);

	int pivotkey = data[low]; //选取中枢元

	while(low < high)
	{
		//从右向左 找到第一个小于中枢元的值，和low交换
		while(low < high && data[high] >= pivotkey)
			high--;
		data[low] = data[high];
		//swap(data[low],data[high]);

		while(low < high && data[low] <= pivotkey)
			low++;
		data[high] = data[low];
		//	swap(data[low],data[high]);
	}
	data[low] = pivotkey;
	return low;
}

void QSort(int *data,int low,int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(data,low,high); //获得中枢元的位置
		QSort(data,low,pivot-1);
		QSort(data,pivot+1,high);
	}
}

void QuickSort(int *data,int length)
{
	QSort(data,1,length);
}

int main()
{
	int data[] = {6,3,4,5,1,7,8,9,10};
	QuickSort(data,8);
	for(auto ch :  data)
		std::cout << ch << std::endl;
}
