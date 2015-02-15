/*
 * =====================================================================================
 *
 *       Filename:  bsttree.cpp
 *
 *    Description:  二叉查找树的实现
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

#include <iostream>
#include <assert.h>
#include "bsttree.h"

using namespace std;

/*
 *  二叉树置空
 */
SearchTree MakeEmpty(SearchTree T)
{
	if(NULL != T)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}


/*
 *二叉排序树的查找
 *
 */
Position Find(ElementType X,SearchTree T)
{
	if(T == NULL)
		return NULL;
	if(X < T->Element)
		return Find(X,T->Left);
	else
	if(X > T->Element)
		return Find(X,T->Right);
	else
		return T;
}

/*
 * 二叉排序树查找最小值
 * 思路:一直往左，叶子节点即为最小
 *
 */
Position FindMin(SearchTree T)
{
	if(T == NULL)
		return NULL;
	else
	if(T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

/*
 * 	二叉树查找最大值
 *	思路:一直往右子树遍历即可
 */
Position FindMax(SearchTree T)
{
/*
//递归实现
	if(T == NULL)
		return NULL;
	else
	if(T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
*/
//非递归实现
	if(T == NULL)
		return NULL;
	while(T->Right != NULL)
		T = T->Right;
	return T;
}


/*
 *	二叉排序树的插入 
 *
 */
SearchTree Insert(ElementType X,SearchTree T)
{
	if(T == NULL)
	{
		T = (SearchTree)malloc(sizeof(struct TreeNode));
			assert(T != NULL);
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	else
	if(X < T->Element)
		T->Left = Insert(X,T->Left);
	else if(X > T->Element)
		T->Right = Insert(X,T->Right);
	return T;
}

/*
 * 	删除节点的几种情况:
 * 	删除节点是叶子节点-->直接删除
 * 	删除节点是有两个儿子节点-->替换为其右子树最小元素的值，并递归删除右子树的最小元素
 * 	删除节点有一个儿子节点-->让其父节点指向其儿子节点即可
 *
 */

SearchTree Delete(ElementType X,SearchTree T)
{
	Position TmpCell;
	if (T == NULL) {
		cout << "Element not found" << endl;
		return T;
	}else if (X < T->Element) {
		
		T->Left = Delete(X,T->Left);
	}else if (X > T->Element) {
		
		T->Right = Delete(X,T->Right);
	}else if (T->Left && T->Right) {	
		//不是叶子节点
		TmpCell = FindMin(T->Right);//找到右子树最小元素
		T->Element = TmpCell->Element;  //将其设置为右子树的最小元素
		T->Right = Delete(T->Element,T->Right); 
	}else {
		
		TmpCell = T;
		//右子树为空,
		if(T->Left == NULL)
			T = T->Right;
		else if(T->Right == NULL)
			T = T->Left;
		//直接释放
		free(TmpCell);
	}
	return T;
}

void MidPrint(SearchTree T)
{
	if (T != NULL) {
		MidPrint(T->Left);
		cout << T->Element << endl;
		MidPrint(T->Right);
	}
}

void PrePrint(SearchTree T)
{
	if (T != NULL) {
		cout << T->Element << endl;
		MidPrint(T->Left);
		MidPrint(T->Right);
	}
}

void AfterPrint(SearchTree T)
{
	if (T != NULL) {
		MidPrint(T->Left);
		MidPrint(T->Right);
		cout << T->Element << endl;
	}	
}



ElementType Retrieve(Position P)
{
	ElementType tmp;
	return tmp;
}

