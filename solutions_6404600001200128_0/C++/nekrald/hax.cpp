#include <bits/stdc++.h>
using namespace std;

const int SZ = 1111;
typedef long long ll;

int a[SZ], n;

ll sum1() {
    ll ans  = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) ans += a[i - 1] - a[i];
    }
    return ans;
}

ll sum2() {
    ll ans = 0;
    int dff = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) dff = max(dff, a[i - 1] - a[i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > dff) ans += dff;
        else ans += a[i];
    }
    return ans;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    printf("%lld %lld\n", sum1(), sum2());
}


int main() {
    int T; scanf("%d", &T);
    for (int _ = 1; _ <= T; ++_) {
        printf("Case #%d: ", _);
        solve();
    }
    return 0;
}
