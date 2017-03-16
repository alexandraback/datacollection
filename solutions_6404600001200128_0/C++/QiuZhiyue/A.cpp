#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[1005];
main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("A-small-attempt0 (1).out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans1=0,ans2=0,ma=0;
        for(int i=1;i<n;i++) if(a[i+1]<a[i])
        {
            ans1+=a[i]-a[i+1];
            ma=max(ma,a[i]-a[i+1]);
        }
        for(int i=1;i<n;i++)
        ans2+=min(ma,a[i]);
        printf("Case #%d: %d %d\n",++cas,ans1,ans2);


    }
}
