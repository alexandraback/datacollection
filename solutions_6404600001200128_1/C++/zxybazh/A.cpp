#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i <=n; i++)
#define N 1001010

int T, n, m, a[N], x, y, z;

void solve() {
    cin >> n; x = y = z = 0;
    rep(i, n) cin >>a[i];
    for (int i = 1; i  < n; i++) {
        x += max(0, a[i-1] - a[i]);
    }
    for (int i = 1; i < n; i++) {
        y = max(y, a[i-1] - a[i]);
    }
    for (int i = 0; i < n-1; i++) {
        z += min(y, a[i]);
    }
    cout << x << " " << z <<endl;
}

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.ou", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	kep(_, T) {
		cout << "Case #" << _ << ": ";
		solve();
	}
}
