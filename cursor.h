/*
 * =====================================================================================
 *
 *       Filename:  cursor.h
 *
 *    Description:  静态链表头文件，也就是游标
 *
 *        Version:  1.0
 *        Created:  03/02/15 12:10:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeff (), zyfforlinux@163.com
 *   Organization:  Linux
 *
 * =====================================================================================
 */

#ifndef CURSOR_H_
#define CURSOR_H_

#define Spacesize 1024
struct Node;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node
{
        ElementType Element;
        Position Next;
};

struct Node CursorSpace[Spacesize];

void InitializeCursorSpace(void);
List MakeEmpty(List L);
bool IsEmpty(List L);
bool IsLast(Position P,List L);
Position Find(ElementType X,List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif //DATASTRUCT_LINKNODE_H_
