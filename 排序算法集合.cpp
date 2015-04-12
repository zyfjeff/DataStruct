/*
 =====================================================================================
        Filename:  排序算法集合.cpp
     	Description:  
        Version:  1.0
        Created:  19/03/15 02:40:42
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>


//冒泡排序,从第一个元素开始，在后面的元素中查找最小的元素不停的替换第一个元素
//依次类推
template<typename Item>
void bubbleSort(Item a[],int left,int right)
{
	int x = 0;
	//每轮从右到左找处最小元素替换到最左边
	for(int i = left;i < right;++i)
		for(int j = right;j >i;--j)
			if(a[j] < a[j-1])
				swap(a[j],a[j-1]);
}

//选择排序
//每次选择最小的元素位置，替换
template<typename Item>
void selectionSort(Item a[],int left,int right)
{
	for(int i = left,i < right;++i) {
		int min = i;
		for(int j = i+1;j <=right;++j)
			if(a[j] < a[min])
				min = j;
		swap(a[i],a[min]);
	}
}

//插入排序
template<typename Item>
void InsertionSort(Item a[],int left,int right)
{
	int i,j;
	for(i = left+1,i <= right;i++)
	{
		int data = a[i];
		for(j = i;j > 0 && a[j-1] > data;j--)
			data[j] = data[j-1];
		a[j] = data;
	}
}


int main()
{
}
