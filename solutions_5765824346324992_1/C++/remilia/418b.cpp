#include <cstdio>
#include <cstring>

typedef long long ll;

const int N = 1005;

int t, n, b[N];
ll v;

ll cal(ll x) {
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += x / b[i] + 1;
    return ans;
}

int main() {
    int cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &n, &v);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        ll l = 0LL, r = (1LL<<50) - 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (cal(mid) >= v) r = mid;
            else l = mid + 1;
        }
        if (l == 0) {
            printf("Case #%d: %d\n", ++cas, (int)v);
            continue;
        }
        int ans = 0;
        ll tot1 = 0, tot2 = 0;
        for (int i = 0; i < n; i++) {
            tot1 += l / b[i] + 1;
            tot2 += (l - 1) / b[i] + 1;
        }
        ll sb = v - tot2;
        for (int i = 0; i < n; i++) {
            if (l / b[i] > (l - 1) / b[i]) {
                sb--;
                if (sb == 0) {
                    ans = i;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", ++cas, ans + 1);
    }
    return 0;
}
