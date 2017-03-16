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
const double eps = 1e-9;
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

ll res() {
	ll b, n; cin >> b >> n;
	vi m(b);
	FOR(i,0,b) cin >> m[i];
	if (n <= b) return n;
	n -= b;
	ll tmin = -1, tmax = 1e18;
	while (tmax-tmin > 1) {
		ll t = (tmin+tmax)/2;
		ll k = 0;
		FOR(i,0,b) k += t/m[i];
		if (k >= n) tmax = t;
		else tmin = t;
	}
	if (tmax == 0) return -1;
	FOR(i,0,b) n -= (tmax-1)/m[i];
	FOR(i,0,b) if (tmax % m[i] == 0 && --n == 0) return i+1;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {
		cout << "Case #" << tc << ": " << res() << endl;
	}


}

