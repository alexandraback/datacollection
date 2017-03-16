#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10010;

int a[MAXN], r[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n, b;
        scanf("%d%d", &b, &n);
        for (int i = 0; i < b; ++i)
            scanf("%d", &a[i]);
        long long L = 0, R = 1000000000000000LL;
        while (L <= R) {
            long long mid = (L + R) / 2;
            long long cnt = 0;

            for (int i = 0; i < b; ++i) {
                cnt += mid / a[i] + 1;
                if (cnt >= n)
                    break;
            }
            if (cnt >= n)
                R = mid - 1;
            else {
                L = mid + 1;
            }
        }
        //printf("%lld\n", R);
        long long cnt = 0;
        for (int i = 0; i < b; ++i) {
            cnt += R / a[i] + 1;
            r[i] = a[i] - R % a[i];
        }
        n -= cnt;
        int ans;
        while (n > 0) {
            int p = 0;
            for (int i = 0; i < b; ++i) {
                if (r[i] < r[p]) {
                    p = i;
                }
            }
            //printf("%d %d\n", n, p);
            r[p] += a[p];
            ans = p;
            --n;
        }

        printf("Case #%d: %d\n", t, ans + 1);
    }
    return 0;
}
