#include <bits/stdc++.h>
using namespace std;
#if defined(ILIKEGENTOO)
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')
#else
#define E($...) ;
#endif
#define all(x) begin(x), end(x)

void solve() {
	int64_t b, n;
	cin >> b >> n;
	vector<int64_t> m(b);
	for (auto &v: m)
		cin >> v;
	int64_t tl = 0, tr = n * m.front() + 1;
	while (tl + 1 < tr) {
		int64_t tm = (tl + tr) / 2;
		int64_t sum = 0;
		for (auto v: m)
			sum += 1 + tm / v;
		if (sum < n)
			tl = tm;
		else
			tr = tm;
	}
	int64_t sum = 0;
	for (auto v: m) sum += 1 + tl / v;
	if (tl == 0) {
		cout << n;
		return;
	}
	assert(sum < n);
	//E(tl, sum);
	++tl;
	int64_t ans = -1;
	for (int64_t i = 0; i < b; ++i) if (tl % m[i] == 0) {
		if (++sum == n) {
			ans = i;
			break;
		}
	}
	assert(ans >= 0);
	cout << (ans + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tcase;
	cin >> tcase;
	for (int t = 0; t < tcase; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}

