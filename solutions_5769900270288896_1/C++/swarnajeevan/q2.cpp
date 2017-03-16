#include<stdio.h>
#include <iostream>
#define ll long long
using namespace std;

ll cnt[1 << 19];
ll nr, nc, nn;

ll cmp(ll i)
{
	ll res = 0;
	for (ll r = 0; r < nr; r++)
	{
		for (ll c = 0; c < nc; c++)
		{
			if (c > 0 && (i & (1 << (r * nc + c))) && (i & (1 << (r * nc + c - 1))))
				res++;
			if (r > 0 && (i & (1 << (r * nc + c))) && (i & (1 << (r * nc + c - nc))))
				res++;
		}
	}
	return res;
}

int main() 
{
	ll tt;
	cin >> tt;
	for (ll t = 1; t <= tt; t++)
	{
		scanf("%lld %lld %lld",&nr,&nc,&nn);
		printf("Case #%lld: ",t);
		ll best = nr * nc * nn * 10;
		for (int i = 1; i < (1 << (nr * nc)); i++)
		{
			cnt[i] = cnt[i - (i & -i)] + 1;
			if (cnt[i] == nn) best = min(best, cmp(i));
		}
		printf("%lld\n",best);
	}
	return 0;
}
