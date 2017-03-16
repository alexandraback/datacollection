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
typedef long long LL;

int T, n, m, a[N], tmp;

int calc(int x, LL b) {
    long long ans = 0;
    rep(i, n) {
        ans += b*a[x]/a[i] + (b*a[x]%a[i]>0 || i < x);
    }
    return (int)min(ans, (LL)(1e9+10));
}

void tc(int x, int l, int r) {
    int mid = (l+r)/2;
    while (l <= r) {
        mid = (l+r)/2;
        if (calc(x, mid) >= m-1) {
            tmp = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
}

bool mycheck(int i) {
    tmp = 1e9+1;
    tc(i, 0, 1e9);
    return (calc(i, tmp) == m-1);
}

int solve() {
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    if (n >= m) return m;
    rep(i, n) if (mycheck(i)) return i+1;
}

int main() {
	freopen("B1.in", "r", stdin);
	freopen("B.ou", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	kep(_, T) {
		cout << "Case #" << _ << ": " << solve() << endl;
	}
}
