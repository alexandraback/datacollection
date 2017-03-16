#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
typedef vector < vll > matrix;
 
#define rep(i,n) for(ll i = 0; i < n; i++)
#define reps(i,a,n) for(ll i = a; i < n; i++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define l(x) (((x) << 1) | 1)
#define r(x) ((l(x)) + 1)
#define mp make_pair
#define fst first
#define snd second
 
ll t, n, u, v, m, q, r, ql, qr, k, d, l, w;
const int N = 3e5 + 500;
const ll mod = 1e9 + 7;
const ll INF = ((1LL << 57LL));
const bool JUDGE = true;
ll f[N];
ll cnt(ll ff) {
	ll ret = 0;
	reps (i, 1, n + 1) { ret += ff / f[i]; if (ff % f[i] != 0) ret++; }
	return ret;
}
int main(){
    csl;
    if (JUDGE) {
        freopen("B-small-attempt1.in", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
	cin >> t;
	for (int sdd = 1; sdd <= t; sdd++) {
		cout << "Case #" << sdd << ": ";
		cin >> n >> m;
		rep (i, n) cin >> f[i + 1];
		ll lo = 1, hi = f[1] * m;
		while (lo < hi) {
			ll mid = lo + (hi - lo) / 2LL;
			if (cnt(mid) < m) lo = mid + 1;
			else hi = mid;
		}
		ll tar = INF;
		lo--;
		ll fr = m - cnt(lo) - 1;
		ll ans = 0;
		vector < pii > pv;
		//cout << lo << '\n';
		reps (i, 1, n + 1) {
			if (lo % f[i] == 0) {
				pv.push_back(mp(0, i));
			}
			else {
				pv.push_back(mp((f[i] - (lo % f[i])), i));
			}
		}
		sort(pv.begin(), pv.end());
		//cout << n << " " << m << " " << pv.size() << '\n';
		cout << pv[fr].snd << '\n';
		//if (fr >= n) cout << fr << '\n';
	}
    return 0;
} 