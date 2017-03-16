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
const ll INF = ((1LL << 32LL));
const bool JUDGE = true;
ll f[N];
int main(){
    csl;
    if (JUDGE) {
        freopen("A-small-attempt0.in", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
	cin >> t;
	for (int sdd = 1; sdd <= t; sdd++) {
		cin >> n;
		cout << "Case #" << sdd << ": ";
		rep (i, n) cin >> f[i];
		ll ans1 = 0, ans2 = 0;
		rep (i, n - 1) ans1 += max(0LL, f[i] - f[i + 1]);
		cout << ans1 << " ";
		ll x = 0;
		rep (i, n - 1) x = max(x, f[i] - f[i + 1]);
		ld rate;
		if (x == 0) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 0; i < n - 1; ++i) {
			if (f[i] > x) ans2 += x;
			else ans2 += f[i];
		}
		cout << ans2 << '\n';
	}
    return 0;
} 