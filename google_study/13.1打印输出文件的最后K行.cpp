/*
 =====================================================================================
        Filename:  13.1打印输出文件的最后K行.cpp
     	Description:  
        Version:  1.0
        Created:  08/03/15 23:51:25
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


/*
 * 	输出文件的最后K行，
 * 	编程思路:
 * 		1.使用链栈保存读取到的所有行，最后输出K行，有点浪费空间，并且是倒序输出了最后K行
 *		2.暴力求解，读取文件一次计算行数N，然后再次读取从N-K行开始输出
 *		3.使用一个可以保存K行内容大小的数组，循环读取数据存入进去，最后留在这个
 *		数组中的K行就是最后的K行，记录最后一行在数组中的位置，从数组的下一个位置
 *		开始循环读取K此输出即可。
 *
 *
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void PrintK(string filename,int k)
{
	string data[k];
	string tmp;
	int size = 0;
	ifstream file(filename);
	if(!file)
		return;
	
	while(file.good())
	{	getline(file,data[size%k]);
		size++;
	}
	int count = (size > k ? k:size);//min(k,size)
	int lastpos = (size > k? (size%k):0);
	
	for(int i = 0;i < count;i++)
	{
		cout << data[(lastpos+i)%k] << endl;
	}
	file.close();

}

int main()
{

	PrintK("1.txt",5);

}
