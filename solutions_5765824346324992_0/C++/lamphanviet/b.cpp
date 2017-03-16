//============================================================================
// Author    : LAM PHAN VIET - lamphanviet@gmail.com
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI  3.1415926535897932385
#define EPS 1e-7
#define MOD 1000000007
#define INF 1500111222
#define MAX 100111

int n, m, a[MAX];

int get(int k, int p) {
	int64 res = 0;
	int64 minTime = p * (int64)a[k];
	rep(i, n) {
		if (res > m) break;
		if (i == k) {
			res += p + 1;
			continue;
		}
		int64 t = minTime / a[i];
		if (i < k) {
			while (t * a[i] <= minTime) t++;
		}
		else {
			while (t * a[i] < minTime) t++;
		}
		res += t;
	}
	return res > m ? 1 : res < m ? -1 : 0;
}

int solve() {
	vi res;
	rep(k, n) {
		int lo = 0, hi = m;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int val = get(k, mid);
			if (val == 0) {
				res.pb(k);
				break;
			}
			else if (val > 0) hi = mid - 1;
			else lo = mid + 1;
		}
	}
	if (res.size() != 1) {
		printf("res %d\n", res.size());
	}
	assert(res.size() == 1);
	return res[0] + 1;
}

int main() {
	#ifndef ONLINE_JUDGE
	    freopen("test.inp", "r", stdin);
	    freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		rep(i, n) scanf("%d", &a[i]);
		printf("Case #%d: %d\n", ++caseNo, solve());
	}
	return 0;
}