#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn = 1010;
int a[maxn];
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		printf("Case #%d: ", cas);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		long long ans1 = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1])
				ans1 += a[i - 1] - a[i];
		}
		long long ans2 = 0;
		int d = 0;
		for (int i = 1; i < n; i++)
			d = max(a[i - 1] - a[i], d);
		//cout << d << endl;
		for (int i = 0; i < n - 1; i++)
			ans2 += min(a[i], d);
		
		cout << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}