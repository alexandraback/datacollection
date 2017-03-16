#include <bits/stdc++.h>

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define REP(i, a, b) for(int i = (a); i < int(b); ++i)
#define rep(i, n) REP(i, 0, n)
#define ALL(x) begin(x), end(x)

template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

int solve_method1(const vector<int> &m) {
	const int n = m.size();
	int res = 0;
	for(int i = 0; i < n - 1; ++i) {
		const int diff = m[i] - m[i + 1];
		if(diff > 0) res += diff;
	}
	return res;
}

int solve_method2(const vector<int> &m) {
	const int n = m.size();
	int mx = 0;
	for(int i = 0; i < n - 1; ++i) {
		const int diff = m[i] - m[i + 1];
		chmax(mx, diff);
	}

	int res = 0;
	for(int i = 0; i < n - 1; ++i) {
		const int eat = min(m[i], mx);
		res += eat;
	}

	return res;
}

string solve() {
	int n;
	cin >> n;

	vector<int> m(n);
	for(auto &e : m) cin >> e;
	return to_string(solve_method1(m)) + ' ' + to_string(solve_method2(m));
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t) {
		const auto ans = solve();
		cout << "Case #" << t << ": " << ans << "\n";
	}

	return EXIT_SUCCESS;
}
