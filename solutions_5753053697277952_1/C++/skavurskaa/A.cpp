#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	int N, V[27], X;
	for (int t = 1; t <= T; t++)
	{
		memset(V,0,sizeof(V));
		scanf("%d", &N);
		int has = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", V+i);
			has += V[i];
		}

		printf("Case #%d:", t);
		set<int> tie;

		while (has)
		{
			int best = 0;
			for (int i = 0; i < N; i++)
			{
				if (V[i] > best)
				{
					best = V[i];
					tie.clear();
					tie.insert(i);
				}
				else if (V[i] == best)
					tie.insert(i);
			}
			if (tie.size() != 2)
			{
				printf(" %c", *tie.begin()+'A');
				V[*tie.begin()]--;
				has--;
			}
			else
			{
				printf(" %c%c", *tie.begin()+'A', *prev(tie.end())+'A');
				V[*tie.begin()]--;
				V[*prev(tie.end())]--;
				has -= 2;
			}
		}
		printf("\n");
	}
}
