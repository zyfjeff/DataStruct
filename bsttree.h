/*
 * =====================================================================================
 *
 *       Filename:  bsttree.h
 *
 *    Description:  二叉查找树
 *
 *        Version:  1.0
 *        Created:  11/02/15 13:22:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeff (), zyfforlinux@163.com
 *   Organization:  Linux
 *
 * =====================================================================================
 */

#ifndef _BSTTREE_H_
#define _BSTTREE_H_

#include <stdlib.h>
#include <iostream>

typedef int ElementType;

struct TreeNode
{
	ElementType Element;
	struct TreeNode *Left;
	struct TreeNode *Right;	
};

typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
ElementType Retrieve(Position P);
void MidPrint(SearchTree T);
void PrePrint(SearchTree T);
void AfterPrint(SearchTree T);
#endif //end _BSTTREE_H_
