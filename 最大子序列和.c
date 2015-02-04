#include <stdio.h>
#include <stdlib.h>

//三者求最大的一个
#define MAX(a,b,c) (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c))

/*
 *	求解最大子序列和的四种解法
 *	问题:给一个整数序列(有正有负)，求出这一整数序列中的连续子序列的最大和
 *	例如: 给定整数序列 -1 1 2 3 4 -4 -5  则最大和10序列为1 2 3 4
 */


//解法一:暴力求解
//利用三层循环 实现遍历所有的子序列,保存最大的一个子序列的和即可
//第一层循环，保存子序列的起始，第二层循环保存子序列的结束,第三层循环计算这一子序列的和。
//三层循环，复杂度近似为O(n^3) 
int GetMaxSumV1(int *data,int length)
{
	int thissum = 0,maxsum = 0,i,j,k;
	
	for(i = 0;i < length;i++)
		for(j = i;j < length;j++)
		{
			thissum = 0;
			for(k = i;k <= j;k++)
				thissum += data[k];

			if(thissum > maxsum)
				maxsum = thissum;
		}
	return maxsum;
}


//解法二 暴力求解，简化解法一的求法
//解法一种先是用二层循环确定了子序列的起始和结尾，然后循环相加最后判断最大，其实没有必要这样做
//只需要确定子序列的其实位置即可，从起始位置的数开始统计，每统计一次判断最值。直到统计到末尾，
//然后再次变化起始位置即可
//二层循环,复杂度变为了O(n^2)

int GetMaxSumV2(int *data,int length)
{
	int thissum = 0,maxsum = 0,i,j;
	for(i = 0;i < length;i++){
		thissum = 0;
		for(j = i;j< length;j++){
			thissum += data[j];
			if(thissum > maxsum)
				maxsum = thissum;
		}
	}
	return maxsum;	
}


//解法三:使用分恰的策略(把问题分成两个大致相等的问题)
//思路:把序列分成两半，最大和子序列可能出现在左边，也可能出现在右边，也有可能出现在中间
//计算出这三种情况，判断三者的大小即可
//列子: 1 2 3 4 5 首先 判断左边1 2 3求出最大, 再次递归左边是1,最大是1,右边是3 最大是3,中间是1 2 3 最大是6
//这三个求最大，是6，然后递归到右边的 4 5，左边是4最大，右边是5最大，中间是4 5和为9最大，所以右边最大是9
//最后看中间 1 2 3 4 5最大为15 判断三者 6 15 9 最大的就是15了.
//复杂度: O(nlogn)

int GetMaxSumV3(int *data,int left,int right)
{
	int maxleftsum,maxrightsum;
	int maxleftbordersum,maxrightbordersum;
	int leftbordersum,rightbordersum;
	int center,i;
	printf("left:%d,right:%d\n",left,right);
	if(left == right)
		if(data[left] > 0)
			return data[left];
		else
			return 0;
	center = (left+right)/2;
	maxleftsum = GetMaxSumV3(data,left,center);
	maxrightsum = GetMaxSumV3(data,center+1,right);
	
	maxleftbordersum = 0;
	leftbordersum =0;
	for(i = center;i >= left;i--){
		leftbordersum += data[i];
		if(leftbordersum > maxleftbordersum)
			maxleftbordersum = leftbordersum;
	}

	maxrightbordersum = 0;
	rightbordersum = 0;
	for(i = center+1;i <= right;i++) {
		rightbordersum += data[i];
		if(rightbordersum > maxrightbordersum)
			maxrightbordersum = rightbordersum;
	}
	return MAX(maxrightsum,maxleftsum,maxrightbordersum+maxleftbordersum);
}



//解法四 ，最高效，最简单的解法
// 思路: 最大和子序列有一个特征就是，最大和子序列的起始位置之前的元素相加和肯定是小于0的，否则如果大于0
// 那么起始点就是前面元素的起始点了，只要大于0就会对子序列起到增加最大值的作用。
// 本算法正式利用这一特点，只计算所有可能出现最大和的子序列。看下面这个例子:
// -1 -2 -3 1 2 3 4 -11 7 8 9 这个序列中-1 -2 -3都可以忽略,对最大和没有贡献,所以第一个可能是最大和序列的起始位置
//  是1，1 2 3 4  是可能的最大子序列 计算到-11后，最大和变成了负数，所以下一个可能最大和的子序列的开始是从7开始
//  最后比较各个可能是最大和的子序列的最大和，求出最大即可。

int GetMaxSumV4(int *data,int length)
{
	int thissum,maxsum,j;
	thissum = maxsum = 0;
	for(j = 0;j < length;j++)
	{
		thissum += data[j];
		if(thissum > maxsum)
			maxsum = thissum;
		else if(thissum < 0)
			thissum = 0;
	}
	return maxsum;
}

int main()
{
	int data[] = {1,2,3,5,6,-1,7,-9};
	//printf("maxsum:%d\n",GetMaxSumV1(data,8));
	//printf("maxsum:%d\n",GetMaxSumV2(data,8));
	printf("maxsum:%d\n",GetMaxSumV3(data,0,7));
	//printf("maxsum:%d\n",GetMaxSumV4(data,8));
}
