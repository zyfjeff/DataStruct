#ifndef ARRAYSTACK_INCLUDE
#define ARRAYSTACK_INCLUDE
#define T ArrayStack
#define MAXSIZE 1024
typedef int ElemType;

struct T {
	ElemType data[MAXSIZE];
	int top;	
};

unsigned int DATASIZE=sizeof(struct T);

typedef struct T *T;
extern T InitStack();
extern void DestroyStack(T s);
extern void ClearStack(T s);
extern int StackEmpty(T s);
extern void GetTop(T s,ElemType *e);
extern void Push(T s,ElemType e);
extern void Pop(T s,ElemType *e);
extern int StackLength(T s);

#undef T
#endif
