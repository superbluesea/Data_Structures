#include<stdio.h>
#include<string.h>

#define MAXSIZE 30

int PrevOrder[MAXSIZE], InOrder[MAXSIZE], PostOrder[MAXSIZE],top = -1;

int Read();
void GetPostOrder(int Root, int Start, int End);


int main()
{
	int N = Read();
	GetPostOrder(0, 0, N - 1);
	printf("%d", PostOrder[0]);
	for (int i = 1; i < N; ++i)printf(" %d", PostOrder[i]);
	return 0;
}

int Read()
{
	int tmps[MAXSIZE], N, topPrev, topIn, topt;
	topPrev = topIn = topt = -1;
	scanf("%d", &N);
	for (int i = 0; i < 2 * N; ++i)
	{
		char str[5];
		scanf("%s", str);
		if (!strcmp(str, "Push"))
		{
			int tmp;
			scanf("%d", &tmp);
			PrevOrder[++topPrev] = tmp;
			tmps[++topt] = tmp;
		}
		else
		{
			int tmp = tmps[topt--];
			InOrder[++topIn] = tmp;
		}
	}
	return N;
}

void GetPostOrder(int Root, int Start, int End)
{
	if (Start > End)return;
	int i = 0;
	while (PrevOrder[Root] != InOrder[i])++i;
	GetPostOrder(Root + 1, Start, i - 1);
	GetPostOrder(Root + i - Start + 1, i + 1, End);
	PostOrder[++top] = PrevOrder[Root];
}