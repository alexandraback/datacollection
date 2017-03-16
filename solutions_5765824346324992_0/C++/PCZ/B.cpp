#include <stdio.h>
#include <iostream>
using namespace std;

long long b,n,t;
long long m[1010];

long long check_num(long long k,long long x)
{
    long long i,num,tmp;
    num=0ll;
    tmp=m[k]*(x-1ll);
    for(i=1ll;i<=k;i++)
    {
        num+=tmp/m[i]+1ll;
        if(num>n) return(1ll);
    }
    for(;i<=b;i++)
    {
        num+=(tmp+m[i]-1ll)/m[i];
        if(num>n) return(1ll);
    }
    if(num==n) return(0ll);
    else return(-1ll);
}

long long test(long long k)
{
    int i,x,tmp,l,r;
    l=1ll;
    r=n;
    while(l<=r)
    {
        x=(l+r)/2ll;
        tmp=check_num(k,x);
        //cout<<k<<"\t"<<x<<"\t"<<tmp<<endl;
        if(tmp==0ll) return(1ll);
        else if(tmp==1ll){
            r=x-1ll;
        }else{
            l=x+1ll;
        }
    }
    return(0ll);
}

int main()
{
    long long tt,i,k;
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%lld",&t);
    for(tt=1;tt<=t;tt++)
    {
        scanf("%lld%lld",&b,&n);
        for(i=1;i<=b;i++)
        {
            scanf("%lld",&m[i]);
        }
        for(k=1;k<=b;k++)
        {
            if(test(k))
            {
                printf("Case #%lld: %lld\n",tt,k);
                break;
            }
        }
    }
    return 0;
}
