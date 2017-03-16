#include <iostream>
#include <stdio.h>

using namespace std;
int n, maxn, a[1009], T;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        int ans1 = 0, ans2 = 0, maxn = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] < a[i - 1])
            {
                ans1 += a[i - 1] - a[i];
                if (a[i - 1] - a[i] > maxn)
                {
                    maxn = a[i - 1] - a[i];
                }
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            if (a[i - 1] >= maxn)
            {
                ans2 += maxn;
            }
            else
            {
                ans2 += a[i - 1];
            }
        }
        printf("Case #%d: %d %d\n", cas, ans1, ans2);

    }
    return 0;
}
