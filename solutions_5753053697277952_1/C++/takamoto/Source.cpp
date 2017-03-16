#include <bits/stdc++.h>
using namespace std;

using ll = long long; using ld = long double; using ull = unsigned long long; using uint = unsigned int;
using vi  = vector<int>; using vb  = vector<bool>; using vd  = vector<double>; using vl  = vector<ll>;
using vvi = vector<vi>;  using vvb = vector<vb>;   using vvd = vector<vd>;     using vvl = vector<vl>;

#define REP(i,n) for(ll i=0; i<(n); ++i)
#define FOR(i,b,n) for(ll i=(b); i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define TEN(x) ((ll)1e##x)

template<typename T> inline string join(const vector<T>& vec, string sep = " ") { stringstream ss; REP(i, vec.size()) ss << vec[i] << ( i+1 == vec.size() ? "" : sep ); return ss.str(); }

int main() {
#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);

	ll t; cin >> t;
	REP(_, t) {
		ll n; cin >> n;
		vl p(n); REP(i, n) cin >> p[i];
		ll sum = 0; REP(i, n) sum += p[i];
		priority_queue<pair<ll, char>> que;
		REP(i, n) que.push({p[i], i+'A'});

		cout << "Case #" << _ + 1 << ":";
		while (sum!=0) {
			string s;
			auto p = que.top(); que.pop();
			p.first--;
			que.push(p);
			sum--;
			s.push_back(p.second);
			if (sum < 2 * que.top().first) {
				auto q = que.top(); que.pop();
				q.first--;
				que.push(q);
				sum--;
				s.push_back(q.second);
			}
			cout << " " << s;
		}
		cout << endl;
	}

	return 0;
}