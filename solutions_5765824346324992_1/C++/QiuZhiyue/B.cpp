#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[1005];
int B,N;
long long erfen()
{
    long long l=0,r=1000000000000000000LL;
    long long ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        long long sum=0;
        for(int i=1;i<=B;i++)
        {
            sum+=mid/a[i];
            if(mid%a[i]) sum++;
        }
        if(sum<=N-1)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
main()
{
    freopen("B-large (1).in","r",stdin);
    freopen("B-large (1).out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--)
    {

        scanf("%d%d",&B,&N);
        for(int i=1;i<=B;i++) scanf("%d",&a[i]);
        long long k=erfen();
        int u,g=0;
        for(int i=1;i<=B;i++)
        {
            g+=k/a[i];
            if(k%a[i]) g++;
        }
        for(int i=1;i<=B;i++)
        if(k%a[i]==0)
        {
            g++;
            if(g==N) {u=i;break;}
        }
        printf("Case #%d: %d\n",++cas,u);
    }
}
