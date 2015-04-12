/*
 =====================================================================================
        Filename:  hashsep.cpp
     	Description:  实现
        Version:  1.0
        Created:  27/02/15 09:42:17
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include "hashsep.h"
#include "simplehash.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MinTableSize 15

unsigned long NextPrime( unsigned long n )   
{   
        return n/2+1;  
}


HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i = 0;
	assert(TableSize > MinTableSize);
	H = (HashTable)malloc(sizeof(struct HashTbl));
	assert(H != NULL);
	H->TableSize = NextPrime(TableSize);

	H->TheLists = (ListNode**)malloc(sizeof(struct ListNode*)*H->TableSize);
	assert(H->TheLists != NULL);
	
	for(i = 0;i < H->TableSize;i++)
	{
		H->TheLists[i] = (ListNode*)malloc(sizeof(struct ListNode));
		H->TheLists[i] = NULL;
	}
	return H;
}

void DestoryTable(HashTable H)
{

}

Position Find(ElementType key,HashTable H)
{
	Position p;
	struct ListNode *L;
	L = H->TheLists[Hash3(key,H->TableSize)];
	p = L->Next;
	while(p != NULL && (strcmp(p->Element,key) != 0))
		p = p->Next;
	return p;
}

void Insert(ElementType key,HashTable H)
{
	Position Pos,NewCell;
	struct ListNode *L;
	Pos = Find(key,H); 
	if (Pos == NULL) {
		NewCell = (Position)malloc(sizeof(struct ListNode));
		assert(NewCell != NULL);
	} else {
		L = H->TheLists[Hash3(key,H->TableSize)];
		NewCell->Next = L->Next;
		NewCell->Element = key;
		L->Next = NewCell;
	}
}

int main()
{
	HashTable H = InitializeTable(10000);
	Insert("zhang",H);
	Insert("wang",H);
}
