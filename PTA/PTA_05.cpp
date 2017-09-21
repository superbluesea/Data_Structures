#include<stdio.h>

int main()
{
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	while (K--)
	{
		int a[1000], stack[1000];
		int count = 0, flag = 1,top = -1, pos = 0;
		for (int i = 0; i < N; ++i)scanf("%d", &a[i]);
		for (int i = 0; i < N; ++i)
		{
			if (top != M - 1)
			{
				stack[++top] = i + 1;
			}
			while (stack[top] == a[pos])
			{
				--top;
				++pos;
				if (top == -1)break;
			}
		}
		if (top != -1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}