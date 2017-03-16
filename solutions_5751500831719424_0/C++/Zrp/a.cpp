#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;
#define N 5000000
#define oo 1000000000
#define mod 1000000007
char a[201][201] = {0};
int al[201] = {0}, sl;
char s[201] = {0};
int b[201][201] = {0};
int check(int vi)
{
	char p[201] = {0};
		int pl = 0;
		for (int i = 0; i < al[vi]; i++)
		{
			if (pl == 0 || a[vi][i] != p[pl-1])
				p[pl++] = a[vi][i];
		}
	p[pl] = '\0';
	if (strcmp(p, s) != 0) return 0;
	int j = 0, now = 1;
	for (int i = 1; i <= al[vi]; i++)
		if (i == al[vi] || a[vi][i] != a[vi][i-1])
		{
			b[j][now]++;
			now = 1;
			j++;
		} else
			now++;
	return 1;
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int tot;
	scanf("%d", &tot);
	for (int tt = 1; tt <= tot; tt++)
	{
		int n;
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		printf("Case #%d: ", tt);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", a[i]);
			al[i] = strlen(a[i]);
		}
		sl = 0;
		for (int i = 0; i < al[1]; i++)
		{
			if (sl == 0 || a[1][i] != s[sl-1])
				s[sl++] = a[1][i];
		}
		int flag = 1;
		s[sl] = '\0';
		for (int i = 1; i <= n; i++)
		{
			if (!check(i))
			{
				flag = 0;
				break;
			}
		}
		int ans = 0;
		if (flag)
		{
			for (int i = 0; i < sl; i++)
			{
				int bes = oo;
				for (int now = 1; now <= 100; now++)
				{
					int pop = 0;
					for (int j = 1; j <= 100; j++)
						pop += b[i][j] * abs(now - j);
					if (pop < bes) bes = pop;
				}
				ans += bes;
			}
			printf("%d\n", ans);
		} else
			printf("Fegla Won\n");
	}
	return 0;
}
