#include "arraystack.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>


ArrayStack InitStack() {
	ArrayStack s;
	s = (ArrayStack)malloc(struct ArrayStack);
	bzero(s->data,MAXSIZE);
	s->top = -1;
	return s;
}

void DestroyStack(ArrayStack s){
	if(s == NULL)
		return;
	else
		free(s);
}
void ClearStack(ArrayStack s) {
	assert(s != NULL);
	bzero(s->data,MAXSIZE);
	s->top = -1;
	return;
}

//return 0 present empty return 1 present not empty
int StackEmpty(ArrayStack s) {
	if(s == NULL)
		return 0;
	else
		return (s->top >= 0?1:0);
}

void GetTop(ArrayStack s,ElemType *e) {
	assert(s != NULL);
	*e = s->data[s->top];
}

void Push(ArrayStack s,ElemType e) {
	if(s == NULL || s->top+1 >= MAXSIZE)
		return;
	else {
		s->data[++s->top] = e;
	}
}

void Pop(ArrayStack s,ElemType *e) {
	if(s == NULL || s->top == -1)
		return;
	else
		*e = s->data[s->top--];
}

int StackLength(ArrayStack s) {
	if(s == NULL || s->top == -1)
		return 0;
	else
		return (s->top+1);
}

