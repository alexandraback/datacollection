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
        int n,k;
        int a[1111];
        scanf("%d%d",&n,&k);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",a+i);
        }
        long long L, R, mid, tot = k, cur;
        for (L = -1, R = k*100000ll; L < R-1;)
        {
            mid = (L+R)/2;
            cur = 0;
            for (int i = 0; i < n; ++i)
                cur += mid/a[i]+1;
            if (cur >= tot)
                R = mid;
            else
                L = mid;
        }
        mid = R;
        cur = 0;
        for (int i = 0; i < n; ++i)
            cur += (mid-1)/a[i]+1;
        tot -= cur;
        int ans;
        for (int i = 0; i < n; ++i)
        {
            if (mid%a[i] == 0 && !--tot)
            {
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n", t, ans+1);
    }
    return 0;
}