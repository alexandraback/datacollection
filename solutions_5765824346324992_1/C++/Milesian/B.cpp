#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <ctime>
#define ll long long
using namespace std;
int n,m,T;
int ans,aug;
int a[1020];
ll lft,rgt,mid;
int getpd(ll x)
{
    int now=0;
    ll numb=0;
    for(int i=1;i<=n;++i)
    {
        numb+=(x-1)/a[i]+1;
        if((x%a[i])==0)++now;
    }
    if(numb+now<m)return 0;
    else
    {
        if(m<=numb)return n;
        numb=m-numb;
        for(int i=1;i<=n;++i)
        {
            if(x%a[i]==0)
            {
                --numb;
                if(numb==0)return i;
            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    for(int ii=1;ii<=T;++ii)
    {
        scanf("%d%d",&n,&m);
        lft=rgt=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            if(a[i]>rgt)rgt=a[i];
        }
        rgt=rgt*m;
        while(lft<=rgt)
        {
            mid=(lft+rgt)/2;
            aug=getpd(mid);
            if(aug)
            {
                ans=aug;
                rgt=mid-1;
            }else lft=mid+1;
        }
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
