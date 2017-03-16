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

long long lcm(const vector<int> &m) {
	long long res = 1;
	for(const auto &e : m) {
		res = res / __gcd<long long>(res, e) * e;
	}
	return res;
}

string solve() {
	int b, n;
	cin >> b >> n;
	--n;

	vector<int> m(b);
	for(auto &e : m) cin >> e;

	const auto l = lcm(m);

	long long T = 0;
	for(const auto &e : m) {
		T += l / e;
	}

	if(n >= T) n %= T;

	typedef pair<int, int> P;
	priority_queue<P, vector<P>, greater<P>> que;
	for(int i = 0; i < b; ++i) {
		que.emplace(0, i);
	}

	while(true) {
		int t, id;
		tie(t, id) = que.top();
		que.pop();

		if(n == 0) return to_string(id + 1);
		--n;
		que.emplace(t + m[id], id);
	}
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
