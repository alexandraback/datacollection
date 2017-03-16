#include <bits/stdc++.h>

#define ll long long
#define __(x) cout << #x << " : " << x << endl;
#define out(a, i, n) for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

#define INOUT
//#define TIME	

using namespace std;

void print(int test, ll ans)
{
	cout << "Case #" << test << ": " << ans << endl;
	//printf("Case #%d: %d\n", test, ans);
}

ll ans1(ll r, ll c, ll n)
{
	ll t1 = (r * c + 1) / 2;
	ll ans = 0;
	if (n <= t1)
		ans = 0;
	else
	{
			ll rest = n - t1;
			ll d2 = (2 * (r + c) - 4) / 2;
			if (rest <= d2)
				ans = rest * 3;
			else 
			{
				rest -= d2;
				ans += d2 * 3;
				ans += rest * 4;
			}
	}
	return ans;
}

ll ans2(ll r, ll c, ll n)
{
	ll ans = 0;
	ll t1 = r * c - ( r * c + 1) / 2;
	if (n <= t1)
		ans = 0;
	else 
	{
		ll rest = n - t1;
		ll d2 = (2 * (r + c) - 4) / 2;
		ll minus = 1 + (r & 1 ? 1 : 0) + (c & 1 ? 1 : 0) + ((r + c) & 1 ? 0 : 1);
		if (rest <= d2)
		{
			
				if (rest <= minus)
					ans = rest * 2;
				else 
					ans = (rest - minus) * 3 + minus * 2;
		}
		else 
		{
			rest -= d2;
			ans += d2 * 3 - minus;
			ans += rest * 4;
		}
	}
	return ans;
}

int main()
{
#ifdef INOUT
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	
	int tests;
	cin >> tests;
	ll ans = 0;
	ll r, c, n;
	for (int test = 1; test <= tests; test++)
	{
		cin >> r >> c >> n;
		if (r > c) swap(r, c);
		ans = 0;
		if (r == 1)
		{
			//cout << "asdfgsdh" << endl;
			if (n * 2 <= c)	ans = 0;
			else 
			{
				if (n == c)
					ans = c - 1;
				else 
				{
					ll t = (c + 1) / 2;
					n -= t;
					//cout << n << "::" << endl;
					if (c % 2 == 0)
					{
						ans = 1; n--;
						//cout << " privet" << endl;
					}
					ans += n * 2;
				}
			}
		}
		else 
			ans = min(ans1(r, c, n), ans2(r, c, n));
		print(test, ans);
	}

#ifdef TIME
	cout << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
