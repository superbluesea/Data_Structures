#include<stdio.h>
#include<stdlib.h>

int main()
{
	int First, N, K, Node[100000][2], List[100000], count = 0;
	scanf("%d %d %d", &First, &N, &K);
	while (N--)
	{
		int address, data, next;
		scanf("%d %d %d", &address, &data, &next);
		Node[address][0] = data;
		Node[address][1] = next;
	}
	while (First != -1)
	{
		List[count++] = First;
		First = Node[First][1];
	}
	for (int i = 0; i < count/K; ++i)
	{
		int s = i*K, e = s + K - 1;
		while (e>s)
		{
			int tmp = List[e];
			List[e] = List[s];
			List[s] = tmp;
			++s;
			--e;
		}
	}
	for (int i = 0; i < count; ++i)
	{
		if (i < count - 1)
			printf("%05d %d %05d\n", List[i], Node[List[i]][0], List[i + 1]);
		else
			printf("%05d %d -1", List[i], Node[List[i]][0]);
	}
	return 0;
}