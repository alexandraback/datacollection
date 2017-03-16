#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-12;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll ccw(pii a, pii b, pii c) {
	ll cc = (b.xx-a.xx)*(c.yy-a.yy) - (b.yy-a.xx)*(c.xx-a.xx);
	if (cc == 0) return 0;
	return (cc > 0) ? 1 : -1;
}

const double pi = 2*acos(0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {
		ll n; cin >> n;
		vector<pii> p(n);
		FOR(i,0,n) cin >> p[i].xx >> p[i].yy;

		cout << "Case #" << tc << ":" << endl;
		FOR(k,0,n) {
			ll res = n-1;
			vector<double> q(2*n-1);
			FOR(i,0,n-1) {
				pii pp = p[i+(i>=k)];
				double dx = pp.xx - p[k].xx, dy = pp.yy - p[k].yy;
				q[i] = atan2(dy,dx);
			}
			FOR(i,n-1,2*n-2) q[i] = q[i-n+1]+2*pi;
			q[2*n-2] = 4*pi;
			sort(all(q));
			ll i = 0, j = 0;
			for (; i < n-1; i++) {
				while (j < 2*n-2 && q[j] < q[i]+pi-eps) j++;
				while (abs(q[i+1]-q[i]) < eps) i++;
				res = min(res,j-i-1);
			}
			cout << res << endl;
		}
	}


}

