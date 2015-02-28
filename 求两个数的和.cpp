/*
 =====================================================================================
        Filename:  求两个数的和.cpp
     	Description: 
	题目：输入一个已经按升序排序过的数组和一个数字，
	在数组中查找两个数，使得它们的和正好是输入的那个数字。
	要求时间复杂度是 O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。
	例如输入数组 1 、 2、 4、 7、 11 、 15 和数字 15。由于 4+11=15，因此输出 4 和 11 。
        Version:  1.0
        Created:  28/02/15 00:28:06
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <vector>


bool GetSum(int *data,int length,int key)
{
	std::vector<int> back;
	int count = -1;
	for(int i = 0;i < length;i++)
	{
		if ((key - data[i]) > data[i]) {
			count++;
			back.push_back(data[i]); //储备元素,有可能是结果 
		}
		//求和
		for(int j = 0;j <= count && count > 0;j++)
		{
			if ((back[j] + data[i]) == key) {
			   std::cout << back[j] << "+" << data[i] << "=" <<key << std::endl;
			   return true;
			}
		}
			
	}
	return false;

}
int main()
{
		int data[] = {1,2,4,7,11,15};
		GetSum(data,6,15);
}
