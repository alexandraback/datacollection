#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int b, n;
		cin >> b >> n;
		vector<long long> m(b);
		for (int i = 0; i < b; ++i) {
			cin >> m[i];
		}

		long long lo = -1;
		long long cntlo = 0;
		long long hi = 2 * 1000000000ll * 1000000000ll;
		long long cnthi = hi;

		while (hi - lo > 1) {
			long long mid = (lo + hi) / 2;
			long long cnt = 0;
			for (int i = 0; i < b; ++i) {
				cnt += mid / m[i] + 1;
			}
			if (cnt >= n) {
				hi = mid;
				cnthi = cnt;
			} else {
				lo = mid;
				cntlo = cnt;
			}
		}

		int x = n - cntlo;
		int ans = -1;
		for (int i = 0; i < b; ++i) {
			if (hi % m[i] == 0 && --x == 0) {
				ans = i;
				break;
			}
		}

		cout << "Case #" << test << ": " << ans + 1 << endl;
	}
}
