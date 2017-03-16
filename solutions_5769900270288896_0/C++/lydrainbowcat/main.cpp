#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<cmath>
using namespace std;
int T, n, m, tot, ans;

int calc(int tot, int a, int b, int c,int pa=2,int pb=3,int pc=4)
{
	int d = n*m - a - b - c;
	if (tot <= a) return 0;
	tot -= a;
	if (tot <= b) return pa * tot;
	tot -= b;
	if (tot <= c) return pa * b + pb * tot;
	tot -= c;
	return pa * b + pb * c + pc * tot;
}

int main()
{
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("B-small-attempt3.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> m >> tot;
		if (n == 1 || m == 1)
		{
			if (m == 1) swap(n, m);
			if (m == 1) ans = 0;
			else if (m & 1)
			{
				ans = calc(tot, m / 2, 2, m / 2 - 1, 1, 2, 3);
				ans = min(ans, calc(tot, m / 2 + 1, 0, m / 2, 1, 2, 3));
			}
			else{
				ans = calc(tot, m / 2, 1, m / 2 - 1, 1, 2, 3);
			}
		}
		else if (n % 2 && m % 2)
		{
			ans = calc(tot, n*m / 2, 4, 2 * (n / 2 - 1 + m / 2 - 1));
			ans = min(ans, calc(tot, n*m / 2 + 1, 0, 2 * (n / 2 + m / 2)));
		}
		else ans = calc(tot, n*m / 2, 2, n + m - 4);
		printf("Case #%d: %d\n", t, ans);
	}
}