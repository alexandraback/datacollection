#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector < ll > vll;
typedef pair < ll, ll > pll;
typedef pair < int , int > pii;
typedef vector < int > vii;

#define rep(i, n) for(ll i = 0; i < n; ++i)
#define reps(i, a, n) for (int i = a; i < n; ++i)
#define l(x) (((x) << 1) | 1)
#define r(x) ((l(x)) + 1)
#define fst first
#define snd second
#define ajd adj
#define prev fsdklfjalsdflsdafjl

const int N = 1e5 + 500;
const ll mod = 1e9 + 7;
ll INF = 1LL << 57LL;

ll n, u, v, c, d, t, l, r, q, m, x, k;
queue < int > Q;
bool f[20][20];
int ans = INT_MAX;
void solve (int r, int c, int x) {
	if (x > n) return;
	if (r == u + 1 && x == n) {
		int cnt = 0;
		reps (i, 1, u + 1) reps (j, 1, v + 1) { if (f[i][j] && f[i - 1][j]) cnt++; if (f[i][j - 1] && f[i][j]) cnt++; }
		if (cnt < ans) ans = cnt;
		return;
	}
	if (r == u + 1) return;
	f[r][c] = true;
	if (c == v) solve(r + 1, 1, x + 1);
	else solve(r, c + 1, x + 1);
	f[r][c] = false;
	if (c == v) solve(r + 1, 1, x);
	else solve(r, c + 1, x);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for (int xx = 1; xx <= t; ++xx) {
		cout << "Case #" << xx << ": ";
		cin >> u >> v >> n;
		ans = INT_MAX;
		solve(1, 1, 0);
		cout << ans << '\n';
	}
	return 0;
}
