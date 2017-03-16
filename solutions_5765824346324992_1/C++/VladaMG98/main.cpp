#include <bits/stdc++.h>
#define mid (lo+hi)/2
using namespace std;
const bool SUBMIT=true;
const int INF=0x3f3f3f3f;
const int MAXN=1010;
int a[MAXN];
long long fun(int n,long long x)
{
    long long ret=0;
    for(int i=0;i<n;i++) {ret+=(x)/(1ll*a[i]);}
    return ret+n;
}
int get(long long x,int n,int diff)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(x%a[i]==0)
        {
            if(cnt==diff) return i+1;
            cnt++;
        }
    }
    return -1;
}
int main()
{
    if(SUBMIT)
    {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    }
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        int b,n;
        scanf("%d%d",&b,&n);
        for(int i=0;i<b;i++) scanf("%d",&a[i]);
        long long lo=0;
        long long hi=10000000000000000ll;
        while(lo+1<hi)
        {
            if(fun(b,mid)>=n)
            {
                hi=mid;
            }
            else lo=mid+1;
        }
        long long enter;
        if(fun(b,lo)>=n) enter=lo;
        else enter=hi;
         long long laststep=fun(b,enter-1);
        printf("Case #%d: %d\n",tt,get(enter,b,n-laststep-1));
    }
    return 0;
}
