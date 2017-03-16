#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int ans = 1e9;
		for (int mask = 0; mask < (1 << (n * m)); mask++)
			if (__builtin_popcount(mask) == k)
			{
				int res = 0;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m - 1; j++)
						res += (((1LL << (i * m + j)) & mask) && ((1LL << (i * m + j + 1)) & mask));
				for (int i = 0; i < n - 1; i++)
					for (int j = 0; j < m; j++)
						res += (((1LL << (i * m + j)) & mask) && ((1LL << (i * m + j + m)) & mask));
				ans = min(ans, res);
			}
		cout << "Case #" << _ << ": " << ans << endl;
	}
	return 0;
}
