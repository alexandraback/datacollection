#include <iostream>
#include <algorithm>

using namespace std;

using LL = long long;

const int MaxN = 1000;

int test_case, n, b, m[MaxN];

LL l, r;

LL calc(LL mid) {
	LL res = 0;
	for (int i = 0; i < b; ++i) {
		res += (LL) (mid / m[i] + 1);
	}
	return res;
}

int main() {
	cin >> test_case;
	for (int cur_case = 1; cur_case <= test_case; ++cur_case) {
		cin >> b >> n;
		for (int i = 0; i < b; ++i) {
			cin >> m[i];
		}
		l = 1ll;
		r = 1e18;
		while (l < r) {
			LL mid = (l + r) / 2, cnt = 0;
			calc((l + r) / 2) >= n ? r = mid : l = mid + 1;
		}
		while (calc(l) < n) {
			++l;
		}
		while (calc(l - 1) >= n) {
			--l;
		}
		for (int i = 0; i < b; ++i) {
			n -= (l - 1) / m[i] + 1;
		}
		//cout << l << endl;
		for (int i = 0; i < b; ++i) {
			if (l % m[i] == 0 && --n == 0) {
				cout << "Case #" << cur_case << ": " << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}
