#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);
	ll t, test; scanf("%lld",&test);
	for (ll t = 0; t < test; t++){
		ll n; scanf("%lld", &n);
		ll a[n+1];
		ll i;
		for (i = 0; i < n; i++) scanf("%lld", &a[i]);
		ll mxd = 0, sd = 0;
		for (i = 0; i < n - 1; i++){
			if (a[i] > a[i+1]) sd += a[i] - a[i+1];
			mxd = max(mxd, a[i] - a[i+1]);
		}
		ll res=0;
		for (i = 0; i < n - 1; i++) res += min(a[i], mxd);
		printf("Case #%lld: %lld %lld\n",t+1,sd,res);
	}
	return 0;
}
