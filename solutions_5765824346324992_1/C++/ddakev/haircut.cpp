#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long t,b,n,a[1001];
long long find_div(long long m)
{
    long long ans=0;
    for(int i=1; i<=b; i++)
    {
        ans+=m/a[i]+1;
    }
    return ans;
}
long long bin_search(long long ll, long long rr)
{
    long long l=ll, r=rr;
    long long m,k;
    while(l<=r)
    {
        m=(l+r)/2;
        k=find_div(m);
        if(k>=n) r=m-1;
        else if(k<n) l=m+1;
    }
    k=n-find_div(l-1);
    //cout<<l<<endl;
   // printf("%lld %lld\n",n,k);
    for(int i=1; i<=b; i++)
    {
        if(l%a[i]==0) k--;
        if(k==0) return i;
    }
    return 0;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    for(int o=1; o<=t; o++)
    {
        scanf("%lld%lld",&b,&n);
        long long max1=0;
        for(int i=1; i<=b; i++)
        {
            scanf("%lld",&a[i]);
            max1=max(max1,a[i]);
        }
        printf("Case #%d: %d\n",o,bin_search(0,max1*n));
    }
    return 0;
}
