#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char s[1024][1024];
int c[1024][1024];
int k;
char p[1024];

int l;
char pat[1024];

bool gp(char s[], int id)
{
	l = 0;
	int ln = strlen(s);
	for (int i = 0; i < ln; i++)
	{
		if (i == 0 || s[i] != s[i-1])
		{
			c[id][l] = i;
			pat[l++] = s[i];
		}
	}

	if (k == -1)
	{
		k = l;
		memcpy(p, pat, sizeof(p));
	}
	if (k != l)
		return 0;
	for (int i = 0; i < k; i++)
	{
		if (p[i] != pat[i])
			return 0;
	}

	return 1;
}

long long ia(long long x)
{
	if (x < 0)
		return -x;
	return x;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; ++t)
	{
		scanf("%d", &n);
		long long ans;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}

		k = -1;
		for (int i = 0; i < n; i++)
		{
			if (!gp(s[i], i))
			{
				goto fail;
			}
		}
		//~ printf("%d\n", k);
		
		for (int i = 0; i < n; i++)
		{
			int m = strlen(s[i]);
			c[i][k] = m;
			for (int j = 0; j < k; ++j)
			{
				c[i][j] = c[i][j+1] - c[i][j];
			}
		}

		ans = 0;
		for (int i = 0; i < k; ++i)
		{
			vector<int> v;
			for (int j = 0; j < n; ++j)
				v.push_back(c[j][i]);
			sort(v.begin(), v.end());
			int m = v[n / 2];
			for (int j = 0; j < n; ++j)
				ans += ia(m - v[j]);
		}
		printf("Case #%d: %lld\n", t, ans);
		continue;

		fail:;
		printf("Case #%d: Fegla Won\n", t);
	}
	return 0;
}
