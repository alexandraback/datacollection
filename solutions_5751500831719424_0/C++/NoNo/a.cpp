#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>

#define lld long long
#define INF 210000000
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int, int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

using namespace std;

char s[200][200];
int part[200];
char h[200][200];
int q[200][200];
int cal(int x)
{
	int l = strlen(s[x]);
	int i;
	int ret = 1;

	if (l == 1)
	{
		h[x][0] = s[x][0];
		q[x][0] = 1;
		return 1;
	}

	h[x][0] = s[x][0];
	q[x][0] = 1;

	for (i = 1; i < l; i++)
		if (s[x][i] != s[x][i - 1])
		{
			ret++;
			h[x][ret - 1] = s[x][i];
			q[x][ret - 1] = 1;
		}
		else
		{
			q[x][ret - 1]++;
		}

	return ret;
}

int abs(int x)
{
	return x < 0 ? -x : x;
}

int main()
{
	int T, n, i, j, k, cas = 0;
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> T;

	while (T--)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}

		mem(part, 0);
		mem(q, 0);

		for (i = 0; i < n; i++)
		{
			part[i] = cal(i);
		}

//		cout<<part[0]<<endl<<part[1]<<endl;
		int ok = 1;

		for (i = 0; i < n - 1; i++)
			if (part[i] != part[i + 1])
			{
				ok = 0;
			}

		printf("Case #%d: ", ++cas);

		if (!ok)
		{
			puts("Fegla Won");
			continue;
		}

		for (i = 0; i < n; i++)
			for (k = 0; k < n; k++)
			{
				for (j = 0; j < part[i]; j++)
					if (h[i][j] != h[k][j])
					{
						ok = 0;
					}
			}

		if (!ok)
		{
			puts("Fegla Won");
			continue;
		}

		int ans = 0;

		for (j = 0; j < part[0]; j++)
		{
			int maxl = 0;
			int tmp = INF;

			for (i = 0; i < n; i++)
			{
				maxl = max(maxl, q[i][j]);
			}

			for (k = 1; k <= maxl; k++)
			{
				int now = 0;

				for (i = 0; i < n; i++)
				{
					now += abs(q[i][j] - k);
				}

				tmp = min(tmp, now);
			}

			ans += tmp;
		}

		printf("%d\n", ans);
	}

	return 0;
}
