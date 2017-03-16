#include <iostream>
#include <cstdio>

using namespace std;
const int Maxn = 1010;
typedef long long ll;
int b, n;
int a[Maxn];
int ans[Maxn];
int solve(int id)
{
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = l + r >> 1;
		ll time = mid * 1ll * a[id];
		int nn = 0;
		for (int i = 0; i < b; ++i)
		{
			nn += time / a[i];
			if (time % a[i] == 0) nn += (i <= id);
		}
		if (nn < n) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
int main() 
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		scanf("%d %d", &b, &n);
		for (int i = 0; i < b; ++i) {
			scanf("%d", a + i);
		}
		if (n <= b) {
			printf("Case #%d: %d\n", cas, n);
			continue;
		}
		n -= b;
		for (int i = 0; i < b; ++i) {
			ans[i] = solve(i);
		}
		int res = 0;
		for (int i = 1; i < b; ++i) {
			if (ans[res] * 1ll * a[i] > ans[i] * 1ll * a[i]) 
				res = i;
		}
		printf("Case #%d: %d\n", cas, res + 1);
	}
	return 0;
}