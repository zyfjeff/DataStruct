/*
 =====================================================================================
        Filename:  求三数中值.cpp
     	Description:  
        Version:  1.0
        Created:  01/03/15 17:51:30
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

//求三数中值
int Median3(int *data,int Left,int Right)
{
	int Center = (Left + Right) /2;
	if(data[Left] > data[Right])
		Swap(&data[Left],&data[Center]);
	if(data[Left] > data[Right])
		Swap(&data[Left],&data[Right]);
	if(data[Center] > data[Right])
		Swap(&data[Center],&data[Right]);
	Swap(&data[Center],&data[Right - 1]);
	return data[Right - 1];
}
