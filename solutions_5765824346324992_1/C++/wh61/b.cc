#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1111;
typedef long long LL;
const LL inf = 1000000000000000LL;
int t[maxn];

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, ca = 0;
	cin >> T;
	while (T--) {
		int n, B;
		cin >> B >> n;
		for (int i = 0; i < B; ++i) {
			cin >> t[i];
		}
		LL L = 1, R = inf;
		while (L < R) {
			LL mid = (L + R) / 2;
			LL have_cuted = 0;
			for (int i = 0; i < B; ++i) {
				have_cuted += (mid - 1) / t[i] + 1;
			}
			if (have_cuted >= n) R = mid; else L = mid + 1;
		}
		LL start_time = L;
		LL m = 0;
		if (start_time > 1) {
			for (int i = 0; i < B; ++i) {
				m += (start_time - 2) / t[i] + 1;
			}
		}
		int dt = n - m;
		int ans = 0;
		for (int i = 0; i < B; ++i) {
			if ((start_time - 1) % t[i] == 0) {
				if (--dt == 0) {
					ans = i + 1;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", ++ca, ans);
	}
	return 0;
}
