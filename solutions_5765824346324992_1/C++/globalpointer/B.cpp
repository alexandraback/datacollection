#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int B; ll N;
ll m[1005];

ll f(ll k) {
    ll r = 0ll;
    for (int i = 0; i < B; i++) r += (k+m[i])/m[i];
    return r;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%lld", &B, &N);
        for (int i = 0; i < B; i++) scanf("%lld", &m[i]);
        ll lo = -1ll, hi = 1000ll*1000ll*1000ll*1000ll*1000ll+1ll;
        while (hi-lo > 1ll) {
            ll mid = (lo+hi)/2ll;
            if (f(mid) >= N) hi = mid;
            else lo = mid;
        }
        ll count = 0ll; int ans = -1ll;
        for (int i = 0; i < B; i++) count += (lo+m[i])/m[i];
        lo++;
        //printf("%lld %lld\n", lo, count);
        for (int i = 0; i < B; i++) {
            if ((lo % m[i]) == 0) {
                count++;
                if (count == N) ans = i+1;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
}

