/*
 =====================================================================================
        Filename:  linknode.c
     	Description: 链表的实现 
        Version:  1.0
        Created:  04/02/15 02:05:28
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include "linknode.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void PrintList(List L)
{
	List p = L;
        while(!IsEmpty(p))
        {
                cout << p->Next->Element << endl;
                p = p->Next;
        }
}

bool IsEmpty(List L)
{
	return (L->Next == NULL);
}

// Return true if P is the last position in L
// Parameter L  is unused in this implementation

bool IsLast(Position P,List L)
{
	return (P->Next == NULL);
}

// Return Position of X in L ; NULL if not found;
Position Find(ElementType X,List L)
{
	Position P;
	P = L->Next;
	while(P != NULL && P->Element != X){
		P = P->Next;
	}
	return P;
}

// Delete first occurrence of X from a list
// Assume use of a header node *
void Delete(ElementType X,List L)
{
	Position P,tmp;
	P  = FindPrevious(X,L);
	if( !IsLast(P,L) ){
		tmp = P->Next;
		P->Next = P->Next->Next;
		free(tmp);
	}
}



// If X is not found,then Next field of returned
// Position is NULL
// Assumes a header
Position FindPrevious(ElementType X,List L)
{
	Position P;
	P = L;
	while(P->Next != NULL && P->Next->Element != X){
		P = P->Next;
	}
	return P;
}


// Insert(after legal position p)
// Header implementation assumed
// Parameter L is unsed in this implementation
void Insert(ElementType X,List L,Position P)
{
	Position node = (Position)malloc(sizeof(struct Node));	
	assert(node != NULL);
	node->Element = X;
	node->Next = P->Next;
	P->Next = node;
}

// Delete a list
void DeleteList(List L)
{	
	Position tmp;
	Position P = L->Next;
	L->Next = NULL;	
	while(P != NULL) {
		tmp = P->Next;
		free(P);
		P = tmp;
	}
}

// Get List Head
Position Header(List L)
{
	return NULL;
}

// Get List first node
Position First(List L)
{
	return L->Next;
}

Position Advance(Position P)
{
	return NULL;
}

ElementType Retrieve(Position P)
{
	return 0;
}

List MakeEmpty(List L)
{
	if(L != NULL)
		DeleteList(L);
	L = (List)malloc(sizeof(struct Node));
	assert(L != NULL);
	L->Next = NULL;
	return L;
}
