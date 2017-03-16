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

constexpr long long MAX_N = 1000000000;
constexpr long long MAX_M = 100000;

long long calc(long long t, const vector<int> &m) {
	if(t < 0) return 0;
	long long res = 0;
	for(const auto &e : m) {
		res += t / e + 1;
	}
	return res;
}

string solve() {
	int b, n;
	cin >> b >> n;

	vector<int> m(b);
	for(auto &e : m) cin >> e;

	long long L = -1, R = MAX_N * MAX_M * 10;
	while(L + 1 < R) {
		const auto M = (L + R) / 2;
		if(calc(M, m) < n) {
			L = M;
		}
		else {
			R = M;
		}
	}

    long long num = calc(L, m);
	assert(num < n);
	for(int i = 0; i < b; ++i) {
		if((L + 1) % m[i] == 0) {
			if(++num == n) return to_string(i + 1);
		}
	}
	assert(false);
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
