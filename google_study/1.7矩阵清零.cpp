/*
 =====================================================================================
        Filename:  1.7矩阵清零.cpp
     	Description:  
        Version:  1.0
        Created:  15/03/15 08:24:28
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


/*
 * 	若MxN的矩阵中某个元素为0，则将其所在行与例清零
 * 	思路:
 * 		遍历所有元素,用另外两个数组记录有零的行和列。
 * 		遍历另外的数组，对其清零
 */

#include <iostream>
#include <cstring>

using namespace std;

void changezero(int *data[],int M,int N)
{
	int row[M];
	int col[N];
	bzero(row,M);
	bzero(col,N);
	for(int i = 0;i < M;i++)
		for(int j = 0;j < N;j++)
		{
			if(data[i][j] == 0)
				row[i]++;
				col[j]++;
		}
	for(int i=0;i < M;i++)
		for(int j = 0;j < N;j++)
		{
			if(row[i]== 0 || col[j] == 0)
				data[i][j] = 0;
		}
}


int main()
{
	int data[4][3]={1,2,3,4,0,5,1,2,5,0,9,0};
	changezero(data,4,3);
}
