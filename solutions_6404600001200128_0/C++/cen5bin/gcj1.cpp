#include <cstdio>
#include <cstring>

const int N = 1010;
int a[N];
int main()
{
    freopen("1in.txt", "r", stdin);
    freopen("1out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int ans1 = 0, ans2 = 0;
        for (int i = 1; i < n; ++i)
            if (a[i] < a[i-1]) ans1 += a[i-1] - a[i];
        int minx = 0;
        for (int i = 1; i < n; ++i)
            if (a[i-1] - a[i] > minx) minx = a[i-1] - a[i];
        for (int i = 1; i < n; ++i)
        {
            if (a[i-1] < minx) ans2 += a[i-1];
            else ans2 += minx;
        }
        printf("Case #%d: %d %d\n", cas, ans1, ans2);
    }
    return 0;
}
