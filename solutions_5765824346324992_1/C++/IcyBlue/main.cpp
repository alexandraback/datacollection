#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int bb[1000];
int gcd(int a,int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main()
{
    int times;
    freopen("B-large.in","r",stdin);
    freopen("B-large.txt","w",stdout);
    scanf("%d\n",&times);
    for (int t = 1; t <= times; t++)
    {
        int b,n;
        scanf("%d %d",&b,&n);
        int max = 0;
        for (int i = 0; i < b; i++)
        {
            scanf("%d",&bb[i]);
            if (bb[i]> max) max = bb[i];
        }
        long long temp = (long long) max * n;
        long long l = 0, r = temp;
        long long mid;
        long long ltt = 0;
        long long rtt = 0;
        long long tt = 0;
        while (r - l != 1)
        {
            mid = (l+r) / 2;
            tt = 0;
            for (int i = 0; i < b; i++)
            {
                long long kk = mid / ((long long)bb[i]);
                tt = tt + kk;
                if (mid % (long long)bb[i] != 0) tt ++;
            }
            if (tt > n-1)
            {
                r = mid;
                rtt = tt;
            }
            else
            {
                l = mid;
                ltt = tt;
            }
        }
        int ans;
        int ll = n - ltt;
        for (int i = 0; i < b; i++)
        {
            if (l % bb[i] == 0) ll--;
            if (ll == 0)
            {
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n", t,ans+1);
    }
}
