// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pci;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100 + 10;

int n;
string s[maxn];

vector<pci> norm(string str) {
	vector<pci> ret;
	for(char c: str) {
		if(ret.empty() || ret.back().first != c)
			ret.pb({c, 0});
		ret.back().second++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tt; cin >> tt;
	for(int tc = 1; tc <= tt; tc++) {
		cin >> n;
		rep(i, n) cin >> s[i];

		bool ok = true;

		auto tmp = norm(s[0]);
		vector<vector<int>> v(sz(tmp), vector<int>());
		rep(i, n) {
			auto cur = norm(s[i]);
			if(sz(cur) != sz(tmp)) ok = false;
			else {
				rep(j, sz(tmp)) {
					if(cur[j].first != tmp[j].first) ok = false;
					v[j].pb(cur[j].second);
				}
			}
		}

		cout << "Case #" << tc << ": ";
		if(!ok) {
			cout << "Fegla Won" << endl;
			continue;
		}
		
		int ans = 0;
		for(auto &t: v) {
			sort(all(t));
			int p = t[sz(t)/2];
			for(int x: t) ans += abs(x - p);
		}

		cout << ans << endl;
	}

	{ return 0; }
}

