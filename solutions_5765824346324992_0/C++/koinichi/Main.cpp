#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll cuttable(ll m, ll n, ll b, ll *M)
{
	ll count = 0;
	for (ll i=1; i<=b; i++) {
		count += m/M[i] + 1;
	}
	return count - n;
}

ll bywho(ll m, ll n, ll b, ll *M)
{
	ll count = 0;
	vector<ll> B;
	for (ll i=1; i<=b; i++) {
		count += m/M[i] + 1;
		if (m%M[i] == 0) {
			count--;
			B.push_back(i);
		}
	}
	return B[n-count - 1];
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int Test;
	scanf("%d",&Test);
	for (int test=1; test<=Test; test++) {
		ll n,b,M[1010] = {0};
		ll l=0, h=0;
		scanf("%lld%lld",&b,&n);
		for (ll i=1; i<=b; i++) {
			scanf("%lld", M+i);
			if (h < M[i]) { h = M[i]; }
		}

		h*=n;
		ll ret=0;
		ll min_time;
		while (l<=h)
		{
			ll m = (l+h)/2;
			if (cuttable(m, n,b,M) >= 0) {
				min_time = m;
				h = m-1;
			}
			else {
				l = m+1;
			}
		}
		ret = bywho(min_time, n,b,M);
			
		printf("Case #%d: %lld\n",test, ret);

	}


}

