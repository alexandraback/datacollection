#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll v(ll n, ll m, ll bm, ll req){
	ll g[n+1][m+1];
	ll c = 0;
	ll count = 0;
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < m; j++){
			if ( (bm & (1<<c) ) > 0 ){ g[i][j] = 1; count++; }
			else g[i][j] = 0;
			c++;
		}
	}
	if (count != req) return 10000000;
	//~ printf("%lld\n", bm);
	//~ for (ll i = 0; i < n; i++){
		//~ for (ll j = 0; j < m; j++){
			//~ printf("%lld ", g[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	//~ printf("\n");
	ll res = 0;
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < m; j++){
			if (g[i][j] == 1){
				if (i + 1 < n && g[i+1][j] == 1) res++;
				if (j + 1 < m && g[i][j+1] == 1) res++;
			}
		}
	}
	return res;
}
int main()
{
	ll t; scanf("%lld", &t);
	for (ll test = 1; test <= t; test++){
		ll r,c,n; scanf("%lld %lld %lld", &r, &c, &n);
		ll res = 10000000;
		for (ll i = 0; i <= (1LL<<16) - 1; i++) if (__builtin_popcountll(i) == n) res = min(res, v(r,c,i,n));
		printf("Case #%lld: %lld\n", test, res);
	}
	return 0;
}
