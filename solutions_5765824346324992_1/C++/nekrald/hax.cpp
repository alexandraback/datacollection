#include <bits/stdc++.h>
using namespace std;

const int SZ = 1111;
typedef long long ll;
int b, n, m[SZ];

ll check(int i, int j) {
    assert(j >= 1 && j <= n);
    ll jj = j - 1;
    ll hgt = ll(m[i]) * jj;
    ll ocnt = 0;
    for (int ni = 0; ni < b; ++ni) {
        if (ni < i) {
            ll rct = (hgt + m[ni] - 1) / m[ni];
            if (m[ni] * rct <= hgt) ++rct;
            ocnt += rct;
        }
        if (ni > i) {
            ll rct = (hgt + m[ni] - 1) / m[ni];
            if (m[ni] * rct < hgt) ++rct;
            ocnt += rct;
        }
    }
    return ocnt + j;
}

void solve() {
    scanf("%d%d", &b, &n);
    for (int i = 0; i < b; ++i) scanf("%d", m + i);
    //sort(m, m + n);
    int ans = 0;
    bool fnd = false;
    for (int ti = 0; ti < b && !fnd; ++ti) {
        int l = 1, r = n;
        while (r - l >= 3 && !fnd) {
            int m = (r + l + 1) / 2;
            ll val = check(ti, m);
            if (val > n) {
                r = m - 1;
            }
            if (val < n) {
                l = m + 1;
            }
            if (val == n) {
                ans = ti;
                fnd = true;
            }
        }
        for (int x = l; x <= r && !fnd; ++x) {
            if (check(ti, x) == n) {
                ans = ti;
                fnd = true;
            }
        }

    }
    printf("%d\n", ans + 1);
}


int main() {
    int T; scanf("%d", &T);
    for (int _ = 1; _ <= T; ++_) {
        printf("Case #%d: ", _);
        solve();
    }
}
