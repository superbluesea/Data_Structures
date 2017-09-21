#include<stdio.h>

#define MAXSIZE 10

struct DSNode{
	int Data[MAXSIZE];
	int Top1;
	int Top2;
};

typedef struct DSNode *DStack;

void Push(DStack PtrDS, int item, int Tag);
int Pop(DStack PtrDS, int Tag);
int IsEmpty(DStack PtrDS, int Tag);
int IsFull(DStack PtrDS, int Tag);
void InitDStack(DStack PtrDS);

int main()
{
	
	return 0;
}

void Push(DStack PtrDS, int item, int Tag)
{
	if (IsFull(PtrDS, Tag))
	{
		printf("DStack is Full\n");
		return;
	}
	else
	{
		if (Tag == 1)
			PtrDS->Data[++PtrDS->Top1] = item;
		else
			PtrDS->Data[++PtrDS->Top2] = item;
	}
}

int Pop(DStack PtrDS, int Tag)
{
	if (IsEmpty(PtrDS, Tag))
	{
		printf("DStack is Empty\n");
		return -1;
	}
	else
	{
		if (Tag == 1)
			return PtrDS->Data[PtrDS->Top1--];
		else
			return PtrDS->Data[PtrDS->Top2--];
	}
}

int IsEmpty(DStack PtrDS, int Tag)
{
	if (Tag == 1)
		return PtrDS->Top1 == -1 ? 1 : 0;
	else
		return PtrDS->Top2 == MAXSIZE ? 1 : 0;
}

int IsFull(DStack PtrDS, int Tag)
{
	if (Tag == 1)
		return PtrDS->Top1 + 1 == PtrDS->Top2 ? 1 : 0;
	else
		return PtrDS->Top2 - 1 == PtrDS->Top1 ? 1 : 0;
}

void InitDStack(DStack PtrDS)
{
	PtrDS->Top1 = -1;
	PtrDS->Top2 = MAXSIZE;
}