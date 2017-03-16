//In the name of God
//...
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double LD;

int n, m, k;

int main() {
	int test = 0;
	cin >> test;
	for (int tt = 1; tt <= test; tt++) {
		cin >> n >> m >> k;
		int a = n * m;
		int ans = n * m * 10;
		for (int mask = 0; mask < (1 << a); mask++) {
			if (__builtin_popcount(mask) != k)
				continue;
			int tmp = 0;
			for (int i = 0; i < a; i++) {
				if (i % m != m - 1 && (mask >> i & 1) && (mask >> (i + 1) & 1))
					tmp++;
				if (i / m < n - 1 && (mask >> i & 1) && (mask >> (i + m) & 1))
					tmp++;
			}
			ans = min(ans, tmp);
		}
		cout << "Case #" << tt << ": ";
		cout << ans << '\n';
	}
	return 0;
}
