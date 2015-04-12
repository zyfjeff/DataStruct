/*
 =====================================================================================
        Filename:  希尔排序.cpp
     	Description:  好的增量
        Version:  1.0
        Created:  28/02/15 09:56:53
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

void ShellSort3(int *data,int length)
{
	int j = 0;
	for(int Increment = length/2;Increment > 0;Increment = Increment /2) //外层增量
	//内部是一个插入排序的结构 
	  for(int p = Increment; p < length;p++) {

		int tmp = data[p];
		for(j = p;j > 0 && (data[j-Increment] > tmp);j = j-Increment)
			data[j] = data[j-Increment];
	
		data[j] = tmp;
	   }
	
}

//希尔排序
// 三层循环
// 最外层是增量循环,一直是length/2
// 第二层循环是从增量到最后一个元素
void ShellSort2(int *data,int length)
{
	int Increment,p,j;
	//增量
	for(Increment = length/2;Increment > 0; Increment = Increment/2)
	{
		// 要交换的数据
		for(p = Increment; p < length;p++)
		{
			int tmp = data[p];
			//交换数据
			for(j = p; j >= Increment; j -= Increment)
			{	
				if(tmp < data[j - Increment])
					data[j] = data[j - Increment];
				else
					break;
			}
			
			data[j] = tmp;
		}
	}
}




// 希尔排序
void Shellsort(int *data,int length)
{
	int i,j,Increment;
	int tmp;
	//增量序列
	for(Increment = length/2; Increment > 0; Increment = Increment/2)
		for(i = Increment;i < length;i++) //待排序的每一个元素
		{
			tmp = data[i]; //和
			for(j = i; j >= Increment;j -= Increment) {
				if(tmp < data[j - Increment])
					data[j] = data[j - Increment];
				else
					break;
			}
			data[j] = tmp;
		}
}

int main()
{
	int data[] = {1,3,5,7,2,4,6,8,10,9};
	//Shellsort2(data,10);
	ShellSort3(data,10);
	for(auto elem : data)
		cout << elem << endl;
}
