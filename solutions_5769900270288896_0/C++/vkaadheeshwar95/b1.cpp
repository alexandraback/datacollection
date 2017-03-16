#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define ll long long int
ll ans[1 << 18];
ll R, C, N;
 
ll calculate(ll x)
{
	ll count = 0;
	for (ll r = 0; r < R; r++)
	{
		for (ll c = 0; c < C; c++)
		{
			if (r >= 1)
			{
				ll sub=(1 << (r * C + c));
				if(x & sub)
				{
					ll sub2= (1 << (r * C + c - C));
					if(x & sub2)
						count++;
				}
			}
			if (c >= 1 )
			{
				ll sub=(1 << (r * C + c));
				if(x & sub)
				{
					ll sub2= (1 << (r * C + c - 1));
					if(x & sub2)
						count++;
				}
			}
			
		}
	}
	return count;
}
 
int main() 
{
	ll T, i, cases;
	scanf("%lld",&T);
	for ( cases = 1;  cases <= T;  cases++)
	{
		scanf("%lld%lld%lld",&R,&C,&N);
 
		ll prod = R * C * N * 100;
		for (i = 1; i < (1 << (R * C)); i++)
		{
			ll ind = i - (i & -i);
			ans[i] = ans[ind] + 1;
			if (ans[i] == N) prod = min(prod, calculate(i));
		}
		printf("Case #%lld: %lld\n",  cases, prod);
	}
	return 0;
}