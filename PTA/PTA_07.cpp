#include<stdio.h>

#define MAXSIZE 10
#define Null -1

struct TreeNode{
	int Left;
	int Right;
}T[MAXSIZE];

typedef struct TreeNode Tree;

int BuildTree(Tree T[]);
void TravelTree(Tree T[], int R);
int flag = 1;

int main()
{
	int R = BuildTree(T);
	TravelTree(T, R);
	return 0;
}

int BuildTree(Tree T[])
{
	int N, check[MAXSIZE], Root;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; ++i)check[i] = 0;
	for (int i = 0; i < N; ++i)
	{
		char tmpl, tmpr;
		scanf("%c %c", &tmpl, &tmpr);
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

void TravelTree(Tree T[], int R)
{
	int queue[MAXSIZE], front = -1, rear = -1;
	queue[++rear] = R;
	while (front != rear)
	{
		int r = queue[++front];
		if (T[r].Left == Null&&T[r].Right == Null)
		{
			if (flag)
			{
				printf("%d", r);
				flag = 0;
			}
			else
				printf(" %d", r);		
		}
		else
		{
			if (T[r].Left != Null)
				queue[++rear] = T[r].Left;
			if (T[r].Right != Null)
				queue[++rear] = T[r].Right;
		}
	}
}