#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define D(x...) fprintf(stderr,x) 
#else
#define D(x...)
#endif 
int T, N;
int main()
{
	freopen("infile.txt", "r", stdin);
	freopen("outfile.txt", "w", stdout);
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		int V[30];
		int left=0, mn=3000;
		scanf("%d", &N);
		for(int n=0; n<N; n++)
		{
			scanf("%d", &V[n]);
			left+= V[n];
			mn = min(mn, V[n]);
		}
		printf("Case #%d: ", t);
		while(true)
		{
			int MX=0, m;
			for(int n=0; n<N; n++)
			{
				if(V[n] > MX)
				{
					MX = V[n];
					m=n;
				}
			}
			if(MX> mn)
			{
				printf("%c ", m+'A');
				V[m]--;
			}
			else
			{
				break;
			}
		}
		for(int n=2; n<N; n++)
		{
			for(int i=0; i<V[n]; i++)
			{
				printf("%c ",n+'A');
			}
		}
		for(int i=0; i<V[0]; i++)
		{
			printf("AB ");
		}
		printf("\n");
	}
}