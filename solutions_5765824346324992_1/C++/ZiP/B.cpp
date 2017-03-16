#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define PI acos(-1.0)
#define M 1000005  //10^6
#define eps 1e-8
#define LL long long
#define moo 1000000007
#define INF -999999999
using namespace std;
long long a[2000];
long long Max(long long x,long long y)
{
    if(x>=y)
        return x;
    return y;
}
long long teo(long long wei,long long m,long long w)
{
    long long le=0;
    long long ri=wei;
    long long ans;
    while(le<=ri)
    {
        long long mid=(le+ri)/2;
        long long an=0;
        for(int i=1;i<=m;i++)
        {
            an+=(mid/a[i]+1);
        }
        if(an>=w)
        {
            ri=mid-1;
            ans=mid;
        }
        else
        {
            le=mid+1;
        }
    }
    return ans;
}

int main()
{
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int T;
    cin>>T;
    int dd=T;
    while(T--)
    {
        long long n,m;
        cin>>n>>m;
        long long ma=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            ma=Max(a[i],ma);
        }
        ma*=m;
        long long num=teo(ma,n,m);
        long long pick=0;
        long long fuck=0;
        for(int i=1;i<=n;i++)
        {
            fuck+=(num/a[i]);
            if(num%a[i])
                fuck++;
        }

        for(int i=1;i<=n;i++)
        {
            if(num%a[i]==0)
            {
                fuck++;
                if(fuck==m)
                {
                    pick=i;
                    break;
                }
            }
        }
        cout<<"Case #"<<dd-T<<": "<<pick<<endl;
    }
}
