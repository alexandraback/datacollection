#include <bits/stdc++.h>

using namespace std;

int main()
{
	// freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-small-attempt0.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++)
	{
		int n;
		scanf("%d", &n);
		vector<int> a;
		int maxi = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			a.push_back(x);
			if (i && a[i] < a[i - 1])
				maxi = max(maxi, a[i - 1] - a[i]);
		}
		int x = 0;
		for (int i = 1; i < n; i++)
			x += (a[i] < a[i - 1]) ? (a[i - 1] - a[i]) : 0;
		int y = 0;
		for (int i = 0; i < n - 1; i++)
			y += min(maxi, a[i]);
		printf("Case #%d: %d %d\n", ca, x, y);
	}
	return 0;
}