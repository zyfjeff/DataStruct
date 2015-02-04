#include "arraystack.h"
#include <stdio.h>

int main()
{
	ElemType data;
	ArrayStack p  = NULL;
	p = InitStack();
	Push(p,2);
	Push(p,4);
	Push(p,5);
	Push(p,6);
	Push(p,7);
	printf("%d\n",p->top);
	printf("%d\n",StackEmpty(p));
	while(StackEmpty(p)){
		Pop(p,&data);
		printf("%d\n",data);
	}
	DestroyStack(p);
}
