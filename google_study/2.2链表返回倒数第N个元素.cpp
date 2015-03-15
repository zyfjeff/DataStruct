/*
 =====================================================================================
        Filename:  2.2链表返回倒数第N个元素.cpp
     	Description:  
        Version:  1.0
        Created:  07/03/15 21:31:37
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

/*
 * 	链表返回倒数第N个元素:
 * 		编程思路一: 两个指针，第一个指针向前移动N个位置，此后两个指针同步向后移动。
 * 		直到移动到结束为止，此时第一个第二个指针指向的就是倒数第N个元素。
 *		
 *		编程思路二: 递归，递归到最后节点，然后N开始递减。
 *
 */


#include <iostream>



struct Node
{
	int data;
	struct Node* next;
};

typedef struct Node*  list;


inline void LIST_INIE(list head)
{
	head->data = -1;
	head->next = NULL;
} 


int main()
{
	
	

}


