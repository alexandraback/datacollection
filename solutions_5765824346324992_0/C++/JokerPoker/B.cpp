#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	// freopen("A-large.in", "r", stdin);
	// freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++)
	{
		ll m;
		int n;
		scanf("%d %I64d", &n, &m);
		vector<ll> a;
		for (int i = 0; i < n; i++)
		{
			ll x;
			scanf("%I64d", &x);
			a.push_back(x);
		}
		ll l = 0, r = *max_element(a.begin(), a.end()) * m;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			ll cnt = 0;
			for (int i = 0; i < n; i++)
			{
				cnt += mid / a[i];
				if (mid % a[i])
					cnt++;
			}
			if (cnt < m)
				l = mid + 1;
			else
				r = mid - 1;
		}
		ll res = 0;
		for (int i = 0; i < n; i++)
		{
			res += r / a[i];
			if (r % a[i])
				res++;
		}
		for (int i = 0; i < n; i++)
			if (r % a[i] == 0)
			{
				res++;
				if (res == m)
				{
					printf("Case #%d: %d\n", ca, i + 1);
					break;
				}
			}
	}
	return 0;
}