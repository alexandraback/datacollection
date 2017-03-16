#include <cstdio>
#include <cstring>

typedef long long LL;
const int N = 1010;
LL mk[N];

bool judge(LL minx, LL x, LL n, LL b)
{
    LL tt = minx * x;
    LL tmp = 0;
    for (int i = 1; i <= b; ++i)
        tmp += (tt + mk[i] - 1) / mk[i];
    if (tmp < n) return 1;
    return 0;
}

LL ttt[N];

int main()
{
    freopen("21in.txt", "r", stdin);
    freopen("22out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        LL b, n;
        scanf("%lld%lld", &b, &n);
        for (int i = 1; i <= b; ++i) scanf("%lld", &mk[i]);
        printf("Case #%d: ", cas);
        if (n <= b)
        {
            printf("%lld\n", n);
            continue;
        }
        int minx = -1;
        int index = -1;
        for (int i = 1; i <= b; ++i)
            if (minx == -1 || minx > mk[i])
            {
                minx = mk[i];
                index = i;
            }
        LL low = 1, high = n;
        while (low < high)
        {
            LL mid = (low + high + 1) >> 1;
            bool ret = judge(minx, mid, n, b);
            if (ret) low = mid;
            else high = mid - 1;
        }
        LL cnt = 0;
        LL tt = low * minx;
        for (int i = 1; i <= b; ++i)
            cnt +=  (tt + mk[i] - 1) / mk[i];
        n -= cnt;
        for (int i = 1; i <= b; ++i)
        {
            ttt[i] = tt % mk[i];
            if (ttt[i] == 0) ttt[i] = -1;
        }
        int ans = -1;
        for (int i = 1; i <= n; ++i)
        {
            bool yes = 0;
            for (int j = 1; j <= b; ++j)
                if (ttt[j] == -1)
                {
                    yes = 1;
                    ttt[j]  = 0;
                    if (i == n) ans = j;
                    break;
                }
            if (yes) continue;
            LL mm = -1;
            int index = -1;
            for (int j = 1; j <= b; ++j)
            {
                if (mm == -1 || mm > mk[j] - ttt[j])
                {
                    mm = mk[j] - ttt[j];
                    index = j;
                }
            }
            for (int j = 1; j <= b; ++j)
            {
                ttt[j] += mm;
                if (ttt[j] >= mk[j]) ttt[j] = -1;
            }
            ttt[index] = 0;
            if (i == n) ans = index;
        }
        printf("%d\n", ans);
    }
    return 0;
}
