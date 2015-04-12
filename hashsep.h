/*
 * =====================================================================================
 *
 *       Filename:  hashsep.h
 *
 *    Description:  分离链接散列表
 *
 *        Version:  1.0
 *        Created:  27/02/15 02:19:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeff (), zyfforlinux@163.com
 *   Organization:  Linux
 *
 * =====================================================================================
 */
#ifndef _HASHSEP_H_
#define _HASHSEP_H_

typedef const char* ElementType;

struct ListNode
{
	ElementType Element;
	ListNode* Next;
	int value;
};
struct HashTbl
{
	int TableSize;
	ListNode **TheLists;
};
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType key,HashTable H);
void Insert(ElementType key,HashTable H);

#endif //end _HASHSEP_H_
