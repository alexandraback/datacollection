#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 1005

int cas, tc, n;
int a[MAXN];
int ans1, ans2, v;

int main()
{
	freopen("A.in", "r", stdin); freopen("A.out", "w", stdout);
	scanf("%d", &cas);
	for (tc = 1; tc <= cas; tc ++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		ans1 = ans2 = 0;
		for (int i = 1; i < n; i ++)
			if (a[i] > a[i + 1])
				ans1 += a[i] - a[i + 1];
		v = 0;
		for (int i = 1; i < n; i ++)
			v = max(a[i] - a[i + 1], v);
		for (int i = 1; i < n; i ++)
			ans2 += min(a[i], v);
		printf("Case #%d: %d %d\n", tc, ans1, ans2);
	}
	return 0;
}
