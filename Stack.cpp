#include<stdio.h>

#define MAXSIZE 10

struct SNode{
	int Data[MAXSIZE];
	int Top;
};

typedef struct SNode *Stack;

void Push(Stack PtrS, int item);
int Pop(Stack PtrS);
int IsEmpty(Stack PtrS);
int IsFull(Stack PtrS);
void InitStack(Stack PtrS);

int main()
{

	return 0;
}

void Push(Stack PtrS, int item)
{
	if (IsFull(PtrS))
	{
		printf("Stack is Full\n");
		return;
	}
	else
	{
		PtrS->Data[++PtrS->Top] = item;
	}
}

int Pop(Stack PtrS)
{
	if (IsEmpty(PtrS))
	{
		printf("Stack is Empty\n");
		return -1;
	}
	else
	{
		return PtrS->Data[PtrS->Top--];
	}
}

int IsEmpty(Stack PtrS)
{
	return PtrS->Top == -1 ? 1 : 0;
}

int IsFull(Stack PtrS)
{
	return PtrS->Top == MAXSIZE - 1 ? 1 : 0;
}

void InitStack(Stack PtrS)
{
	PtrS->Top = -1;
}