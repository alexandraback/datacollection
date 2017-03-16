#include <bits/stdc++.h>		//ry

using namespace std;

int qw[1 << 18],R,C,N;


int pre(int i)
{
	int ans = 0;
	
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (c > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - 1))))
				ans++;
			if (r > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - C))))
				ans++;
		}
	}
	
	return ans;
}


int main() 
{
	int test;
	scanf("%d",&test);
	
	for (int t = 1; t <= test; t++)
	{
		scanf("%d %d %d",&R,&C,&N);
		//cin >> R >> C >> N;
		
		int best = R * C * N * 100;
		
		for (int i = 1; i < (1 << (R * C)); i++)
		{
			qw[i] = qw[i - (i & -i)] + 1;
			if (qw[i] == N) 
			best = min(best, pre(i));
		}
		
		printf("Case #%d: %d\n", t, best);
	}
}