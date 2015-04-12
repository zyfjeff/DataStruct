/*
 =====================================================================================
        Filename:  cursor.cpp
     	Description:  游标的实现,链表的实现
        Version:  1.0
        Created:  09/02/15 06:00:57
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include <iostream>
#include "cursor.h"

// 分配空间
static Position CursorAlloc(void)
{
	Position P;
	P =  CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;
	return p;
}

//释放空间
static void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[P].Next;
	CursorSpace[0].Next = P;
}
