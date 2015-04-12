/*
 =====================================================================================
        Filename:  求整数和为M的序列.cpp
     	Description:  输入n 求1....n中随意取几个数 使其和为M
	既然是面试题，应该不能直接暴力破解吧
        Version:  1.0
        Created:  04/03/15 06:39:52
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length;

void findCombination(int n,int m,int *flag)
{
  if(n < 1 || m < 1)
    return;
  if(n > m)
    n = m;
  if(n == m)
  {
    flag[n-1] = 1;
    for(int i=0;i<length;i++)
    {
      if(flag[i] == 1)
        printf("%d\t",i+1);
    }
    printf("\n");
    flag[n-1] = 0;
  }
  flag[n-1] = 1;
  findCombination(n-1,m-n,flag);
  flag[n-1] = 0;

  findCombination(n-1,m,flag);
}

int main()
{
  int n, m;
  scanf("%d%d",&n,&m);
  length = n;
  int *flag = (int*)malloc(sizeof(int)*length);
  findCombination(n,m,flag);
  free(flag);
  return 0;
}
