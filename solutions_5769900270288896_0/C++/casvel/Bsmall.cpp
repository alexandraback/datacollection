#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

int R, C, S, N;
int dp[16][16][1<<16];

int f(int r, int c, int S)
{
	if (__builtin_popcount(S) > N)
		return INF;

	if (r == R-1 and c == C)
		return __builtin_popcount(S) == N ? 0 : INF;

	if (c == C)
		return f(r+1, 0, S);

	if (dp[r][c][S] != -1)
		return dp[r][c][S];

	int i = r*C + c;
	int add = (i % C > 0 ? (S & (1 << (i-1))) != 0: 0) + (i/C > 0 ? (S & (1 << (i-C))) != 0 : 0);
	
	return dp[r][c][S] = min(f(r, c+1, S), f(r, c+1, S | (1 << i)) + add);
}

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		scanf("%d %d %d", &R, &C, &N);
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %d\n", caso++, f(0, 0, 0));
	}

	return 0;
}