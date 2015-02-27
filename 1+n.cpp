/*
 =====================================================================================
        Filename:  1+n.cpp
     	Description:  1+2+3....n 不使用if else
        Version:  1.0
        Created:  27/02/15 12:44:34
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

int add_sum(int n,int &sum)
{
	n && add_sum(n-1,sum);
	return sum += n;
}

int main()
{
	int sum = 0;
	std::cout << add_sum(100,sum) << std::endl;
}
