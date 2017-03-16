#include <cstdio>
#include <cstdlib>

int T, Test;
int b, n, bt[1010];

long long count(long long t, int add = 1) {
    long long ret = 0;
    for (int i = 0; i < b; ++i)
        ret += t / bt[i] + add;
    return ret;
}

int main() {
    scanf("%d", &Test);
    for (int T = 1; T <= Test; ++T) {
        scanf("%d%d", &b, &n);
        for (int i = 0; i < b; ++i) scanf("%d", bt + i);
        long long l = 0, r = 1e18;
        while (l < r) {
            long long m = (l + r) / 2;
            long long cnt = count(m);
            if (cnt >= n) r = m;
            else l = m + 1;
        }
        int ans = -1;
        long long cnt = count(r - 1);
        for (int i = 0; i < b; ++i) {
            if (r % bt[i] == 0) ++cnt;
            if (cnt == n) {
                ans = i + 1;
                break;
            }
        }
        printf("Case #%d: %d\n", T, ans);
    }
}
