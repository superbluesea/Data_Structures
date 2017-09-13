#include<stdio.h>

#define MaxDegree 2000

typedef struct{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
}*Polynomial;

void ZeroPolynomial(Polynomial Poly)
{
	for (int i = 0; i <= MaxDegree; ++i)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
	PolySum->HighPower = Poly1->HighPower > Poly2->HighPower ? Poly1->HighPower : Poly2->HighPower;
	for (int i = 0; i <= PolySum->HighPower; ++i)
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
	PolyProd->HighPower = Poly1->HighPower*Poly2->HighPower;
	for (int i = 0; i <= Poly1->HighPower; ++i)
	{
		for (int j = 0; j <= Poly2->HighPower; ++j)
		{
			PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
		}
	}
}

int main()
{
	Polynomial p1, p2;
	ZeroPolynomial(p1);
	ZeroPolynomial(p2);
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		p1->CoeffArray[tmp2] = tmp1;
		if (tmp2>p1->HighPower)
			p1->HighPower = tmp2;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		p2->CoeffArray[tmp2] = tmp1;
		if (tmp2>p2->HighPower)
			p2->HighPower = tmp2;
	}

	return 0;
}