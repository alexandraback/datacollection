#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

ll a[100][100];

ll f(ll x, ll y) {
	ll ret = 0;
	if (a[x - 1][y] == 1) ret++;
	if (a[x][y - 1] == 1) ret++;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin>>T;
	for (ll qq = 1; qq<=T; qq++) {
		ll R, C, N;
		cin >> R >> C >> N;
		ll res = INF;
		ll m = R * C;
		for (ll i = 1; i < (1<<m) ; i++) {
			memset(a, 0, sizeof(a));
			ll tmp = 0;
			for (ll j = 0; j < m; j++)
				if ((i>>j)&1) tmp++;
			if (tmp == N) { // bitset where we have N set bits
				for (ll j = 0 ; j < m ; j++) {
					if (( i >> j) & 1) {
						ll x = j + 1;
						ll var = (x % C != 0);
						ll X = (x / C) + var;
						ll Y = x - (X - 1) * C;
						a[X][Y] = 1;
					}
				}
				ll ans = 0;
				for (ll foo = 1; foo<=R; foo++) {
					for (ll bar = 1; bar<=C; bar++) {
						if (a[foo][bar] == 1) {
							ans += f(foo, bar);
						}
					}
				}
				res = min(res, ans);
			}
		}
		if (N == 0) res = 0;
		cout << "Case #" << qq << ": " << res << "\n";
	}
}
