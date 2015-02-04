/*
 *	N个数确定其中最大的K个数
 */

#include <stdio.h>
#include <stdlib.h>


//交换
void swap(int *data1,int *data2)
{
	int tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}

// 冒泡排序
// 思想: 从第一个元素开始，拿第一个元素和后面的所有元素一一比较，小于第一个元素的就交换
// 最后保证第一个元素是最小的，依次类推，直到倒数第二个元素为止。
void bubblesort(int *data,int len)
{
	int i = 0;
	int j = 0;
	for(i = 0;i < len-1;i++)
	for(j = i+1;j < len;j++)
		if(data[i] >= data[j])
			swap(&data[i],&data[j]);
}



//算法一:
//思路: N个数进行排序，选择其中最大的K个即可
int* GetTopKV1(int *data,int len,int k)
{
	int size;
	if(k > len)
		return NULL;
	if(k == len)
		return data;
	else
		size = len-k;
	bubblesort(data,len);
	return (data+size);
}



void insert(int *data,int len,int elem)
{
	int i = 0;
	for(i = 0;i < len;i++)
	{
		if(data[i] < elem){
			data[i] = elem;
			break;
		}
	}
}


//算法二:
//思路: 先取其中的K个元素读入数组,然后排序,然后对剩下的N-K个元素做处理,
//如果元素小于第K个元素则继续，如果大于第K个元素
//则放入数组中的正确位置，同时将数组中的一个元素挤出数组

int * GetTopKV2(int *data,int *result,int len,int k)
{
	int i = 0,j;
	//复制K个元素
	for(i = 0;i < k;i++)
		result[i] = data[i];
	
	//排序
	bubblesort(result,k);
	
	//剩下的len-k个进行处理
	for(i = k;i <len;i++)
	{
		if(data[i] < result[0])
			continue;
		else{
			result[0] = data[i];
			bubblesort(result,k);
		}
	}
	return result;
}



int main()
{
	int i = 0;
	int data[] = {2,1,3,4,6,7,5};
	int len = sizeof(data)/sizeof(data[0]);
	int k = 4;
//GetTopKV1 测试
/*
	int *result = NULL;
	if((result = GetTopKV1(data,len,k)) == NULL) {
		printf("error get top k data\n");
		exit(-1);
	}
	for(i = 0;i < k;i++)
		printf("data[%d]:%d\n",i,result[i]);
*/	

//GetTopKV2测试
	int *result2 = (int *)malloc(k*sizeof(int));
	GetTopKV2(data,result2,len,k);
	
	for(i = 0;i < k;i++)
		printf("data[%d]:%d\n",i,result2[i]);
	
	
}
