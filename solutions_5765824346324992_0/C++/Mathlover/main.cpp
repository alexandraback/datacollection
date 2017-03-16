#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<time.h>
using namespace std;
long long m[1005];
int b;
long long check(long long t)
{
    long long ans=0;
    for(int i=1;i<=b;++i)
        ans+=t/m[i]+!!(t%m[i]);
    return ans;
}
struct p
{
    long long a,b;
    bool operator<(const p&x)const
    {
        if(a!=x.a)
        return a<x.a;
        return b<x.b;
    }
}pp[100005];
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,ca=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d%d",&b,&n);
        for(int i=1;i<=b;++i)
            scanf("%I64d",m+i);
        long long low=1,high=1LL<<52,mid;
        while(low<=high)
        {
            mid=low+high>>1;
            long long num=check(mid);
            if(num>=n)
                high=mid-1;
            else if(num<n)
                low=mid+1;
        }
        //printf("%I64d %I64d %I64d\n",low,high,check(low));
        low--;
        long long p=check(low);
        for(int i=1;i<=b;++i)
        {
            if(low%m[i]==0)
            pp[i].a=0;
            else pp[i].a=m[i]-low%m[i];
            pp[i].b=i;
        }
        sort(pp+1,pp+b+1);
//        for(int i=1;i<=b;++i)
//            printf("%I64d %I64d\n",pp[i].a,pp[i].b);
        printf("Case #%d: %I64d\n",++ca,pp[n-p].b);



    }
}
