#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T, w, n, a[110][110], c[110], len, ans;
int flag;
char s[110], b[110][110];
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s);
			len = strlen(s);
			a[i][0] = 0;
			a[i][++a[i][0]] = 1;
			b[i][a[i][0]] = s[0];
			for (int j = 1; j < len; j++)
			{
				if (s[j] == s[j - 1]) a[i][a[i][0]]++;
				else a[i][++a[i][0]] = 1, b[i][a[i][0]] = s[j];
			}
		}
		flag = 1;
		for (int i = 2; i <= n; i++) if (a[i][0] != a[1][0]) flag = 0;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= a[i][0]; j++) if (b[i][j] != b[1][j]) flag = 0;
		if (!flag) printf("Case #%d: Fegla Won\n", ++w);
		else
		{
			ans = 0;
			for (int i = 1; i <= a[1][0]; i++)
			{
				//ans += abs(a[1][i] - a[2][i]);
				for (int j = 1; j <= n; j++) c[j] = a[j][i];
				sort(c + 1, c + n + 1);
				for (int j = 1; j <= n; j++) ans += abs(c[j] - c[n + 1 >> 1]);
			}
			printf("Case #%d: %d\n", ++w, ans);
		}
	}
	return 0;
}
