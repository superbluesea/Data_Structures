#include<stdio.h>
#include<stdlib.h>

struct SNode{
	int Data;
	struct SNode *Next;
};

typedef struct SNode *Stack;

Stack CreateStack();
void Push(int Item, Stack S);
int Pop(Stack S);
int IsEmpty(Stack S);

int main()
{

	return 0;
}

Stack CreateStack()
{
	Stack stack = (Stack)malloc(sizeof(struct SNode));
	stack->Next = NULL;
	return stack;
}

void Push(int Item, Stack stack)
{
	struct SNode *TmpCell = (struct SNode*)malloc(sizeof(struct SNode));
	TmpCell->Data = Item;
	TmpCell->Next = stack->Next;
	stack->Next = TmpCell;
}

int Pop(Stack stack)
{
	int TopElement;
	if (IsEmpty(stack))
	{
		printf("Stack is NULL\n");
		return 0;
	}
	else
	{
		struct SNode *TmpCell = stack->Next;
		TopElement = TmpCell->Data;
		stack->Next = TmpCell->Next;
		free(TmpCell);
		return TopElement;
	}
}

int IsEmpty(Stack stack)
{
	return stack->Next == NULL ? 1 : 0;
}