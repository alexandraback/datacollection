#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 1005
ll a[N];
int n, m;

void solve()
{
    ll lcm = 1, g = 1;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
    {
        scanf("%lld", &a[i]);
        if (i == 0)
            g = a[0];
        else
            g = __gcd(g, a[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        a[i] /= g;
        lcm = lcm * a[i] / __gcd(lcm, a[i]);
    }
    ll T = 0;
    for (int i = 0; i < m; ++i)
    {
        T += lcm / a[i];
        if (T > n)
            break;
    }
    n %= T;
    if (n == 0)
        n = T;
    int tot = 0;
    for (ll t = 0; tot < n; ++t)
    {
        for (int i = 0; i < m; ++i)
        {
            if (t % a[i] == 0)
            {
                ++tot;
                if (tot >= n)
                {
                    printf("%d\n", i + 1);
                    break;
                }
            }
        }
    }
}

int main()
{
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}