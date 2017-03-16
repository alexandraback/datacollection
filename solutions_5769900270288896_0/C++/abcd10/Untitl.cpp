#include <bits/stdc++.h>

using namespace std;
 
int cnt[1 << 18];
int R, C, N;
 
int compute(int i)
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
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> R >> C >> N;
 
		int best = R * C * N * 100;
		for (int i = 1; i < (1 << (R * C)); i++)
		{
			cnt[i] = cnt[i - (i & -i)] + 1;
			if (cnt[i] == N) best = min(best, compute(i));
		}
		printf("Case #%d: %d\n", t, best);
	}
}
