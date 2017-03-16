#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        int ans1 = 0;
        int interval = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (i > 0 && a[i] < a[i - 1])
            {
                ans1 += a[i - 1] - a[i];
                interval = max(interval, a[i - 1] - a[i]);
            }
        }
        int ans2 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans2 += min(a[i], interval);
        }
        printf("Case #%d: %d %d\n", cases, ans1, ans2);
    }
    return 0;
}
