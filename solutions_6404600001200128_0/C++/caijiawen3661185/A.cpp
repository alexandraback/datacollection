#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 10010
#define ll long long
using namespace std;

int t,n;
ll a[N];
int T;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    scanf("%d",&T);
    int ca=1;
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
        ll ans1=0;
        ll ans2=0;
        ll num=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]<a[i-1])
            {
                ans1+=(a[i-1]-a[i]);

            }
            num=max(num,a[i-1]-a[i]);
        }
        for(int i=1;i<n;i++)
        {
            ans2+=min(num,a[i]);
        }
        printf("Case #%d: %I64d %I64d\n",ca++,ans1,ans2);
    }
    return 0;
}
