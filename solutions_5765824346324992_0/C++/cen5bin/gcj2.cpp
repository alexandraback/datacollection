#include <cstdio>
#include <cstring>

const int B = 1010;
typedef long long LL;
LL mk[B];

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

LL cal(int b)
{
    LL ret = mk[1];
    for (int i = 2; i <= b; ++i)
        ret = ret * mk[i] / gcd(ret, mk[i]);
    return ret;
}
int tt[B];
int main()
{
    freopen("2in.txt", "r", stdin);
    freopen("2out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int n, b;
        scanf("%d%d", &b, &n);
        for (int i = 1; i <= b; ++i) scanf("%lld", &mk[i]);
        LL ret = cal(b);
        LL tol = 0;
        for (int i = 1; i <= b; ++i)
            tol += ret / mk[i];
        n %= tol;
        //printf("%d %d\n", ret, n);
        printf("Case #%d: ", cas);
        if (n <= b && n)
        {
            printf("%d\n", n);
            continue;
        }
        if (n == 0) n = tol;
        memset(tt, -1, sizeof(tt));
        int ans = -1;
        for (int i = 1; i <= n; ++i)
        {
            bool yes = 0;
            for (int j = 1; j <= b; ++j)
                if (tt[j] == -1)
                {
                    yes = 1;
                    tt[j] = 0;
                    if (i == n) ans = j;
                    break;
                }
            if (yes) continue;
            int minx = -1, index;
            for (int j = 1; j <= b; ++j)
                if (minx == -1 || mk[j] - tt[j] < minx)
                {
                    minx = mk[j] - tt[j];
                    index = j;
                }
            for (int j = 1; j <= b; ++j)
            {
                tt[j] += minx;
                if (mk[j] - tt[j] <= 0) tt[j] = -1;
            }
            tt[index] = 0;
            if (i == n) ans = index;
        }
        printf("%d\n", ans);
    }
    return 0;
}
