/*
 =====================================================================================
        Filename:  test_queue.cpp
     	Description:  测试队列
        Version:  1.0
        Created:  10/02/15 11:54:49
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include "queue.h"

int main()
{
	Queue qe = CreateQueue(100);
	Enqueue(4,qe);
	Enqueue(5,qe);
	Enqueue(6,qe);
	Enqueue(7,qe);
	Dequeue(qe);
	while(!IsEmpty(qe))
	{
		printf("data:%d\n",FrontAndDequeue(qe));
	}
}
