#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int T, b, n, a[1005];

LL count(LL t) {
    LL ret = 0;
    for (int i = 0; i < b; i++) ret += t / a[i] + 1;
    return ret;
}
int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d", &b, &n);
        for (int i = 0; i < b; i++) scanf("%d", a+i);
        int ans;
        if (n <= b) ans = n;
        else {
            LL l = 0, r = INF;
            while (l + 1 < r) {
                LL m = (l + r) >> 1;
                count(m) < n ? l = m : r = m;
            }
            n -= count(l);
            for (int i = 0; i < b; i++) {
                if (r % a[i]) continue;
                if (!--n) {ans = i + 1; break;}
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
