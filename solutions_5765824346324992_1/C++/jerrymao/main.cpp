#include <cstdio>

typedef long long ll;

ll m[1005];
ll n;
int b;
int t;

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%d%lld", &b, &n);
		for (int i = 0;i < b;i++)
			scanf("%lld", m+i);
		ll lo = 0, hi = 1ll << 50;
		while (lo+1 < hi)
		{
			ll mid = (lo + hi) >> 1;
			ll res = 0;
			for (int i = 0;i < b;i++)
				res += ((mid+m[i]-1)/m[i]);
			if (res > n-1)
				hi = mid;
			else
				lo = mid;
		}
		hi = 0ll;
		printf("Case #%d: ", _);
		for (int i = 0;i < b;i++)
			hi += (lo+m[i]-1)/m[i];
		hi = n-hi-1ll;
		for (int i = 0;i < b;i++) if ((lo%m[i]) == 0)
		{
			if (hi == 0)
			{
				printf("%d", i+1);
				break;
			} else
				hi--;
		}
		printf("\n");
	}
	return 0;
}
