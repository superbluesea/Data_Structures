#include<stdio.h>
#include"Cursor.h"

#define SpaceSize 10

struct Node
{
	ElementType Element;
	Position Next;
};

struct Node CursorSpace[SpaceSize];

static Position CursorAlloc(void)
{
	Position P;
	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;
	return P;
}

static void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

int IsEmpty(List L)
{
	return CursorSpace[0].Next == 0;
}

int IsLast(Position P, List L)
{
	return CursorSpace[P].Next == 0;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;
		CursorFree(TmpCell);
	}
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = CursorAlloc();
	if (TmpCell == 0)
		printf("Out of space");
	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;
}

void InitializeCursorSpace(void)
{
	for (int i = 0; i < SpaceSize; ++i)
	{
		if (i == SpaceSize - 1)
			CursorSpace[i].Next = 0;
		else
			CursorSpace[i].Next = i + 1;
	}
}

int main()
{

	return 0;
}