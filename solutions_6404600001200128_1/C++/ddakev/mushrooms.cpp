#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long t,n,a[1001];
int main()
{
    freopen("output.txt","w",stdout);
    freopen("A-large.in","r",stdin);
    scanf("%lld",&t);
    for(int o=1; o<=t; o++)
    {
        scanf("%lld",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
        }
        printf("Case #%d: ",o);
        long long ans=0,max1=0;
        for(int i=2; i<=n; i++)
        {
            if(a[i]<a[i-1]) {ans+=a[i-1]-a[i];}
        }
        printf("%lld ",ans);
        ans=0;
        for(int i=2; i<=n; i++)
        {
            max1=max(max1,a[i-1]-a[i]);
        }
        for(int i=1; i<=n-1; i++)
        {
            ans+=min(max1,a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
