#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 1005
int a[N];
int n;

int solve()
{
    ll ans1 = 0, ans2 = 0;
    int d = 0;
    scanf("%d", &n);
    scanf("%d", &a[0]);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] < a[i - 1])
        {
            ans1 += a[i - 1] - a[i];
            d = max(d, a[i - 1] - a[i]);
        }
    }
    for (int i = 1; i < n; ++i)
    {
        ans2 += min(a[i - 1], d);
    }
    printf("%lld %lld\n", ans1, ans2);
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