#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() { _
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		int n, a[1111];
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		// method 1.
		int ans1 = 0;
		for (int i = 0; i < n - 1; ++i)
			ans1 += max(a[i] - a[i + 1], 0);
		// method 2.
		int ans2 = 0, mx = 0;
		for (int i = 0; i < n - 1; ++i)
			mx = max(mx, a[i] - a[i + 1]);
		for (int i = 0; i < n - 1; ++i)
			ans2 += max(min(mx, a[i]), 0);
		cout << ans1 << ' ' << ans2 << '\n';
	}
}
