#include<stdio.h>

#define ElementType char
#define MAXSIZE 10
#define Tree int
#define Null -1

struct TreeNode{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MAXSIZE], T2[MAXSIZE];

Tree BuildTree(struct TreeNode T[]);
int IsSameStructure(Tree R1, Tree R2);

int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (IsSameStructure(R1, R2))printf("Yes");
	else printf("No");
	return 0;
}

Tree BuildTree(struct TreeNode T[])
{
	int N, check[MAXSIZE], Root = -1;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < MAXSIZE; ++i)check[i] = 0;
	for (int i = 0; i < N; ++i)
	{
		char tmpl, tmpr;
		scanf("%c %c %c", &T[i].Element, &tmpl, &tmpr);
		getchar();
		if (tmpl != '-')
		{
			T[i].Left = tmpl - '0';
			check[T[i].Left] = 1;
		}
		else
			T[i].Left = Null;
		if (tmpr != '-')
		{
			T[i].Right = tmpr - '0';
			check[T[i].Right] = 1;
		}
		else
			T[i].Right = Null;
	}
	for (int i = 0;i<N;++i)
		if (!check[i]){ Root = i; break; }
	return Root;
}

int IsSameStructure(Tree R1, Tree R2)
{
	//先判断是否为空,不然会越界
	if (R1 == Null&&R2 == Null)
		return 1;
	//其中一棵树为空,另外一棵树不为空
	if ((R1 == Null&&R2 != Null) || (R1 != Null&&R2 == Null))
		return 0;
	//根节点不同
	if (T1[R1].Element != T2[R2].Element)
		return 0;
	//
	if (T1[R1].Left == Null && T2[R2].Left == Null)
		return IsSameStructure(T1[R1].Right, T2[R2].Right);
	//
	if (T1[R1].Left != Null&&T2[R2].Left != Null&&T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)
		return IsSameStructure(T1[R1].Left, T2[R2].Left) && IsSameStructure(T1[R1].Right, T2[R2].Right);
	else
		return IsSameStructure(T1[R1].Left, T2[R2].Right) && IsSameStructure(T1[R1].Right, T2[R2].Left);
}