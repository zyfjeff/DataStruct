/*
 =====================================================================================
        Filename:  并查集.cpp
     	Description:  
        Version:  1.0
        Created:  12/03/15 03:50:51
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */


#include<iostream>
#define MAXN 100001
using namespace std;
 
 
void getfather(int *father,int v,int k,int &count){
    if (father[v]==v)
       return ;
    count++;
    getfather(father[v]);
}
 

void get(int *data,int length)
{
	for(int i = 0;i < length;i++)
	{
		if(data[i] == i) //根节点
		{
			
		}
	}
}
