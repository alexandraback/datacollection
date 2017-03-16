#include <iostream>
#include <stdio.h>

using namespace std;
const long long INF = 100000000000000LL;
long long n, a[1009], T;
int B;
bool check(long long x)
{
    long long tmp = 0;
    for (int i = 1; i <= B; ++i)
    {
        tmp = x / a[i] + 1;
    }
    return tmp < n;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "W", stdout);
    scanf("%d", &T);
    for (int cas = 1;  cas <= T; ++cas)
    {
        scanf("%d %I64d", &B, &n);
        for (int i = 1; i <= B; ++i)
        {
            scanf("%I64d", &a[i]);
        }
        long long l = 0, r = INF;
        long long ti;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
            {
                l = mid + 1;
                ti = r;
            }
            else
            {
                r = mid - 1;
            }
        }
        for (int i = 1; i <= B; ++i)
        {
            if (ti % a[i] == 0)
            {
                printf("Case #%d: %d\n", cas, i);
                break;
            }
        }
    }
    return 0;
}
