#include <stdio.h>
#include <queue>


using namespace std;


typedef long long ll;


ll b,n, bb[1010];

ll calc(ll x, ll c)
{
	ll ans = 0, i;
	
	ll t = bb[x]*(c-1);
	for (i = 0; i < x; i++)
		ans += t / bb[i] + 1;
	 ans += c-1;
	for (i = x+1; i < b; i++)
	{
		ans += t/bb[i]+1;
		if (t%bb[i]==0) ans --;
	}
	return ans+1;
}


int judge(ll x)
{
	ll l = 1, r = n, m;
	while (l < r)
	{
		m = (l+r+1)/2;
		if (calc(x, m)<=n) l = m;
		else r = m-1;
	}
	if (calc(x,l)==n)
		return 1;
	return 0;
}


int main()
{
	int T, cas;
	int i;
	freopen ("B-large.in", "r", stdin);
	freopen ("blarge.txt", "w", stdout);
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%I64d%I64dd", &b, &n);
		for (i = 0; i < b; i++)
			scanf ("%I64d", &bb[i]);
		for (i = 0; i < b; i++)
			if (judge(i)) break;
		printf ("Case #%d: %d\n", cas, i+1);
	}
	return 0;
}


