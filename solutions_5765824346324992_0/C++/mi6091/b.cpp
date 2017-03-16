#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long

int b, n;
ll a[1024];

pair <ll, ll> check(ll pos)
{
	pair <ll, ll> ret = make_pair(0, 0);
	
	int i;
	for(i =0 ; i < b; i ++)
	{
		ret.first += (pos + a[i])/a[i];
		ret.second += ((pos + a[i] - 1)/ a[i]);
	}
	return ret;
}
ll solve()
{
	scanf ("%d%d", &b, &n);

	int i;
	for(i =0; i <b ; i++)
	{
		scanf ("%lld", &a[i]);
	}


	ll f = 0, l = 1001001001001023ll;

	while(f < l)
	{
		ll mid = f + (l - f)/ 2;

		pair <ll, ll> temp = check(mid);
		ll s = temp.first;

		if (s >= n)
		{
			l = mid;
		}
		else
			f = mid + 1;
	}

	n -= check(f).second;

	//cout << f << " " << n << endl;

	for(i = 0; i < b && n; i++)
	{
		n -= ((f % a[i]) == 0);
	}

	return i;

}
int main ()
{
	int t;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++)
	{
		printf("Case #%d: %lld\n", i, solve());
	}
	return 0;
}