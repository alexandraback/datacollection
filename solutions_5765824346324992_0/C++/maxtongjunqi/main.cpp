#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#define mod 1000000007
#define nn 110000
const int inf=0x3fffffff;
typedef long long LL;
using namespace std;
int b,n;
int m[1100];
bool check(LL x)
{
    int i;
    LL ix=0;
    LL fc=0;
    for(i=1;i<=b;i++)
    {
        ix+=x/m[i];
        if(x%m[i]==0)
        {
            fc++;
        }
        else
            ix++;
    }
    return ix+fc>=n;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
    int t,i,j,x;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        scanf("%d%d",&b,&n);
        int lp=0;
        LL mn=inf;
        for(i=1;i<=b;i++)
        {
            scanf("%d",&m[i]);
            mn=min(mn,(LL)m[i]);
        }
        LL l=0,r=mn*n;
        LL mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(check(mid))
            {
                r=mid;
            }
            else
                l=mid+1;
        }
        LL ix=0;
        for(i=1;i<=b;i++)
        {
            ix+=l/m[i];
            if(l%m[i])
                ix++;
        }
        for(i=1;i<=b;i++)
        {
            if(l%m[i]==0)
            {
                ix++;
                if(ix==n)
                    break;
            }
        }
        printf("Case #%d: %d\n",cas++,i);
    }
    return 0;
}
