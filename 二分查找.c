#include <stdio.h>

/*
 *	二分查找
 *	思路:二分查找是针对有序序列进行查找的，先判断，要查找的数和序列的中间元素的大小关系
 *	以确定数据最终在哪个部分，依次递归进行
 */



//解法一:非递归版本
//注意: 退出条件 left <= right
// 返回0 表示查找到，返回1表示没有查找到



int binnaryfindv1(int *data,int length,int key)
{
	int mid;
	int left = 0,right = length-1;
	while(left <= right)
	{
		mid = (right+left)/2;
		if(key == data[mid])
			return 1;
		if(key < data[mid]) {
			right = mid-1;
		}
		else left = mid+1;
	}
	return 0;
}

//解法二:递归版本
int binnaryfind(int *data,int left,int right,int key)
{
	int mid = 0;
	if(left <= right){
		mid = (left+right)/2;
		if(key == data[mid])
			return 1;
		else if(key < data[mid])
			binnaryfind(data,left,mid-1,key);
		else binnaryfind(data,mid+1,right,key);
	}else
		return 0;
	
}

int binnaryfindv2(int *data,int length,int key)
{
	binnaryfind(data,0,length-1,key);
}


int main()
{
	int data[] = {1,2,3,4,5,6,7,8,10};
	printf("%d\n",binnaryfindv1(data,9,7));
	printf("%d\n",binnaryfindv2(data,9,7));
	
}
