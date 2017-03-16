#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define MAXN 1010

int mk[MAXN];
int n, b;

ll calc(ll t)
{
	ll res = 0;
	ll waiting = 0;
	for (int i = 1; i <= b; ++i)
	{
		if(t % mk[i] == 0) 
			waiting++;
		res += t / mk[i] + ((t % mk[i]) == 0 ? 0 : 1);
	}
	return res + waiting;
}

int main()
{
	int T;
	int ca = 0;
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &b, &n);
		int maxx = 0;
		for (int i = 1; i <= b; ++i)
		{
			scanf("%d", &mk[i]);
			maxx = max(mk[i], maxx);
		}
		ll left = 0;
		ll right = 1e15;
		while(left < right)
		{
			ll mid = (right + left) / 2;
			if(calc(mid) < n)
				left = mid + 1;
			else
				right = mid;
		}
		//printf("%lld %lld\n", left, calc(left));
		int last = calc(left) - n;

		int res = -1;
		for (int j = b; j >= 1; --j)
		{
			if(left % mk[j] == 0)
			{
				if(last == 0)
				{
					res = j;
					break;
				}
				last--;
			}
		}

		printf("Case #%d: %d\n", ++ca, res);
	}
	return 0;
}