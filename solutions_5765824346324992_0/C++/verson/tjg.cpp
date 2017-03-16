#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string>
#pragma warning(disable:4996)

#define ll long long
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

ll a[1000];
int b, n;

ll work(ll x)
{
	ll ans = b;
	for (int i = 0; i < b; i++) ans += x / a[i];
	return ans;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> b >> n;
		for (int i = 0; i < b; i++) cin >> a[i];
		ll l = 0, r = a[0] * n, m;
		while (l <= r) {
			m = (l + r) / 2;
			if (work(m) >= n) r = m - 1; else l = m + 1;
		}
		int w = work(r), ans = 0;
		for (int i = 0; i < b; i++) if (l % a[i] == 0)
		{
			w++;
			if (w == n) {
				ans = i; break;
			}
		}
		cout << "Case #" << t << ": " << ans+1 << endl;
	}
}