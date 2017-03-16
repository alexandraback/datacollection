#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argv, char** argc)
{
    int T;
    if (argv > 1)
        freopen(argc[1], "r", stdin);
    if (argv > 2)
        freopen(argc[2], "w", stdout);
    scanf("%d",&T);
    for (int t = 1; t <= T; ++t)
    {
        int ans1 = 0, ans2 = 0, mxn = 0, n;
        int a[1111];
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",a+i);
            if (i)
            {
                if (a[i] < a[i-1])
                {
                    ans1 += a[i-1]-a[i];
                    mxn = max(mxn, a[i-1]-a[i]);
                }
            }
        }
        for (int i = 1; i < n; ++i)
        {
            ans2 += min(mxn,a[i-1]);
        }
        printf("Case #%d: %d %d\n", t, ans1, ans2);
    }
    return 0;
}