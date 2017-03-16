#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int r, c, n;
		cin >> r >> c >> n;
		int ans = 1e9;
		for (int mask = 0; mask < 1 << (r * c); mask++) {
			if (__builtin_popcount(mask) != n) continue;
			vector<vector<int> > a(r + 2, vector<int>(c + 2));
			for (int i = 0; i < (r * c); i++) {
				if ((1 << i) & mask) {
					a[i / c + 1][i % c + 1] = 1;
				}
				
			}
			int cur = 0;
				for (int i = 1; i <= r; i++) 
					for (int j = 1; j <= c; j++)
						if (a[i][j] == 1) cur += a[i][j + 1] == 1, cur += a[i + 1][j] == 1;
				ans = min(ans, cur);
			
		}
		cout << ans << endl;
	}
}