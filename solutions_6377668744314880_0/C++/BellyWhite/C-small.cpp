#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
struct VEC {LL x, y;};
const VEC operator-(const VEC &a, const VEC &b) {
    return (VEC){a.x - b.x, a.y - b.y};
}
LL operator%(const VEC &a, const VEC &b) {
    return a.x * b.x + a.y * b.y;
}
LL operator*(const VEC &a, const VEC &b) {
    return a.x * b.y - a.y * b.x;
}

int T, n;
VEC p[20];

bool onSegment(const VEC &u, const VEC &v, const VEC &p) {
    return (u - p) % (v - p) < 0;
}
int count(int msk) {
    if (__builtin_popcount(msk) <= 3) return msk;
    int ret = 0;
    for (int i = 0; i < n; i++) if (msk & 1<<i) {
        for (int j = 0; j < n; j++) if (msk & 1<<j) if (j != i) {
            bool flag = true;
            for (int k = 0; k < n; k++) if (msk & 1<<k) if (k != i && k != j) {
                LL xp = (p[j] - p[i]) * (p[k] - p[i]);
//                printf("(%d, %d, %d): xp=%lld\n", i, j, k, xp);
                if (xp < 0 || !xp && onSegment(p[i], p[j], p[k])) {
                    flag = false;
                    break;
                }
            }
            if (flag) ret |= 1<<i | 1<<j;
        }
    }
    return ret;
}
int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
        int num[20] = {};
        for (int msk = 1; msk < 1<<n; msk++) {
            int cnt = __builtin_popcount(msk);
            int ch = count(msk);
            for (int i = 0; i < n; i++) {
                if (ch & 1<<i) num[i] = max(num[i], cnt);
            }
        }
        printf("Case #%d:\n", cas);
        for (int i = 0; i < n; i++) printf("%d\n", n - num[i]);
    }
}
