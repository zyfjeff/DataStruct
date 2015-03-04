/*
 =====================================================================================
        Filename:  Fibonacci.cpp
     	Description:  数列
        Version:  1.0
        Created:  01/03/15 20:07:44
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>

using namespace std;

//递归求解
int fib(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return (fib(n-1)+fib(n-2));
}

//直接求解
int fib2(int n)
{
	const int value = n + 1;
	int data[value];
	data[0] = 0;
	data[1] = 1;
	int count = 2;
	while(count <= n)
	{
		data[count] = data[count-1] + data[count-2];
		count++;
	}
	return data[n];
	//std::cout << data[n] << std::endl;
}

int main()
{
	int sum = 0;
	std::cout << fib2(10) << std::endl;
}
