#include<stdio.h>
#include<set>
#pragma warning(disable:4996)
int m[1001];
int b, n;
bool chk(long long t)
{
	int i;
	long long c1 = 0, c2 = 0;
	for (i = 1; i <= b; i++)
	{
		if (t%m[i] == 0)
		{
			c1 += t / m[i];
			c2++;
		}
		else c1 += t / m[i] + 1;
	}
	if (c1 < n) return true;
	return false;
}
int solve()
{
	int i;
	scanf("%d%d", &b, &n);
	for (i = 1; i <= b; i++)scanf("%d", m + i);
	long long f=0, r=1ll*n*100001, M;
	while (f < r)
	{
		M = (f + r + 1) / 2;
		if (chk(M)) f = M;
		else r = M - 1;
	}
	long long T = f;
	long long c1 = 0, c2 = 0;
	std::set<int> W;
	for (i = 1; i <= b; i++)
	{
		if (T%m[i] == 0)
		{
			c1 += T / m[i];
			c2++;
			W.insert(i);
		}
		else c1 += T / m[i] + 1;
	}
	for (c1++; c1 < n; c1++) W.erase(W.begin());
	return *W.begin();
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)printf("Case #%d: %d\n", i, solve());
	return 0;
}