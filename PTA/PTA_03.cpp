#include<stdio.h>
#include<stdlib.h>

typedef struct Node *PtrToNode;

struct Node{
	int Coefficient;
	int Exponent;
	PtrToNode Next;
};

typedef PtrToNode Polynomial;

void Read(Polynomial L)
{
	PtrToNode tmp = L;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		PtrToNode Ptr = (PtrToNode)malloc(sizeof(struct Node));
		int c, e;
		scanf("%d %d", &c, &e);
		Ptr->Exponent = e;
		Ptr->Coefficient = c;
		Ptr->Next = NULL;
		tmp->Next = Ptr;
		tmp = Ptr;
	}
}

void Attach(PtrToNode *Ptr,int e,int c)
{
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	p->Next = (*Ptr)->Next;
	p->Exponent = e;
	p->Coefficient = c;
	(*Ptr)->Next = p;
	*Ptr = p;
}

Polynomial Add(Polynomial L1, Polynomial L2)
{
	Polynomial PA = (Polynomial)malloc(sizeof(struct Node));
	PA->Next = NULL;
	Polynomial t1 = L1->Next, t2 = L2->Next, t3 = PA;
	while (t1&&t2)
	{
		if (t1->Exponent == t2->Exponent)
		{
			if (t1->Coefficient+t2->Coefficient!=0)
				Attach(&t3, t1->Exponent, t1->Coefficient + t2->Coefficient);
			t1 = t1->Next;
			t2 = t2->Next;
		}
		else if (t1->Exponent > t2->Exponent)
		{
			Attach(&t3, t1->Exponent, t1->Coefficient);
			t1 = t1->Next;
		}
		else
		{
			Attach(&t3, t2->Exponent, t2->Coefficient);
			t2 = t2->Next;
		}
	}
	while (t1)
	{
		Attach(&t3, t1->Exponent, t1->Coefficient);
		t1 = t1->Next;
	}
	while (t2)
	{
		Attach(&t3, t2->Exponent, t2->Coefficient);
		t2 = t2->Next;
	}
	return PA;
}

Polynomial Mult(Polynomial L1, Polynomial L2)
{
	Polynomial PM = (Polynomial)malloc(sizeof(struct Node));
	PM->Next = NULL;
	PtrToNode t1 = L1->Next, t2 = L2->Next, t3 = PM;
	if (!t1 || !t2)return PM;
	while (t2)
	{
		Attach(&t3, t1->Exponent + t2->Exponent, t1->Coefficient * t2->Coefficient);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1)
	{
		t2 = L2->Next;
		t3 = PM;
		while (t2)
		{
			int e = t1->Exponent + t2->Exponent, c = t1->Coefficient * t2->Coefficient;
			while (t3->Next&&t3->Next->Exponent > e)
				t3 = t3->Next;
			if (t3->Next&&t3->Next->Exponent == e)
			{
				t3->Next->Coefficient += c;
				if (t3->Next->Coefficient == 0)
				{
					PtrToNode tmp = t3->Next;
					t3->Next = tmp->Next;
					free(tmp);
				}
			}
			else
			{
				Attach(&t3, e, c);
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	return PM;
}

void Print(Polynomial L)
{
	PtrToNode tmp = L->Next;
	int flag = 1;
	if (tmp == NULL)
	{
		printf("0 0\n");
		return;
	}
	while (tmp)
	{
		if (flag)
			flag = 0;
		else
			printf(" ");
		printf("%d %d", tmp->Coefficient, tmp->Exponent);
		tmp = tmp->Next;
	}
	printf("\n");
}

int main()
{
	Polynomial P1, P2, PA, PM;
	P1 = (Polynomial)malloc(sizeof(struct Node));
	P1->Next = NULL;
	P2 = (Polynomial)malloc(sizeof(struct Node));
	P2->Next = NULL;
	Read(P1);
	Read(P2);
	PA = Add(P1, P2);
	PM = Mult(P1, P2);
	Print(PM);
	Print(PA);
	return 0;
}