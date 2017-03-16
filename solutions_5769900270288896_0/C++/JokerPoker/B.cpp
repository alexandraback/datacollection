#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	// freopen("1.in", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++)
	{
		int R, C, n;
		scanf("%d %d %d", &R, &C, &n);
		int N = R * C;
		int tot = 1 << N;
		int ans = 999999;
		for (int k = 0; k < tot; k++)
		{
			int num = __builtin_popcount(k);
			if (num != n)
				continue;
			int cnt = 0;
			for (int i = 0; i < N; i++)
				if (k & (1 << i))
				{
					int x1 = i / R;
					int y1 = i % R;
					for (int j = i + 1; j < N; j++)
						if (k & (1 << j))
						{
							int x2 = j / R;
							int y2 = j % R;
							if (x1 == x2 && abs(y1 - y2) == 1)
								cnt++;
							if (y1 == y2 && abs(x1 - x2) == 1)
								cnt++;
						}
				}
			ans = min(ans, cnt);
		}
		printf("Case #%d: %d\n", ca, ans);
	}

	return 0;
}