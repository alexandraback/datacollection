#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <deque>
using namespace std;

#define REP(i, m, n) for(int i=(m); i<int(n); ++i)
#define rep(i, n) for(int i=0; i<int(n); ++i)
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back                                                                          
#define mp make_pair
#define def(a, x) __typeof(x) a = x
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> PI;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const int INF = 1<<29;
void solve() {
	int N;
	cin >> N;
	string s[N];
	rep(i, N) cin >> s[i];

	vector<int> v[N];
	string xs[N];
	rep(i, N) {
		for(int j=0; j<sz(s[i]);) {
			char c = s[i][j];
			int k=j;
			for(; k<sz(s[i]); k++) {
				if (s[i][k] != c) break;
			}
			xs[i] += c;
			v[i].push_back(k-j);
			j = k;
		}
	}

	rep(i, N) rep(j, N) {
		bool ok = true;
		if (sz(v[i]) != sz(v[j])) ok = false;
		if (xs[i] != xs[j]) ok = false;
		if (!ok) {
			cout << "Fegla Won" << endl;
			return;
		}
	}

	int ans = 0;
	rep(i, sz(v[0])) {
		int res = 1<<29;
		rep(k, 110) {
			int cnt = 0;
			rep(j, N) {
				cnt += abs(v[j][i] - k);
			}
			res = min(res, cnt);
		}
		ans += res;
	}
	cout << ans << endl;

}
int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}

