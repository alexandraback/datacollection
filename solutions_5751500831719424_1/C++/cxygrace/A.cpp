#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110;

char dat[maxn][maxn];
int n, cnt[maxn][maxn], slen[maxn];

void getcnt()
{
	for (int i = 0; i < n; i++)
	{
		int len = strlen(dat[i]);
		int p = 1;
		cnt[0][i] = 1;
		for (int j = 1; j < len; j++)
		{
			if (dat[i][j] != dat[i][p-1])
			{
				dat[i][p++] = dat[i][j];
				cnt[p-1][i] = 1;
			}
			else
				cnt[p-1][i]++;
		}
		slen[i] = p;
	}
}

bool check()
{
	for (int i = 1; i < n; i++)
		if (slen[i] != slen[0]) return false;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < slen[0]; j++)
			if (dat[i][j] != dat[0][j]) return false;
	return true;
}

int getmin()
{
	int res = 0;
	for (int i = 0; i < slen[0]; i++)
	{
		sort(cnt[i], cnt[i] + n);
		int mid = cnt[i][n/2];
		for (int j = 0; j < n; j++)
			res += abs(cnt[i][j] - mid);
	}
	return res;
}

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", dat[i]);
}

void work()
{
	getcnt();
	if (check()) printf("%d\n", getmin());
	else printf("Fegla Won\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		init();
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}
