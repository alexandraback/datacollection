#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<fstream>
using namespace std;
const int N=1010;
#define ll long long
ll INF=100000010000000;
ll a[N];
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll n;
ll b;
bool ok(ll t)
{
    ll ans=0;
    for(int i=1;i<=b;i++)
    {
        ans+=(t-1)/a[i];
        ans++;
    }
    if(ans>=n)
        return true;
    return false;
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        ll Max=-1;
        scanf("%d%d",&b,&n);
        for(int i=1;i<=b;i++)
        {
            scanf("%d",&a[i]);
            Max=max(Max,a[i]);
        }
        ll l=0;ll r=n*Max;
        ll mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            //cout<<"mid="<<mid<<endl;
            if(ok(mid))
                r=mid-1;
            else
                l=mid+1;
        }
        l--;
        ll ans=0;
        for(int i=1;i<=b;i++)
        {
            ans+=(l-1)/a[i]+1;
        }
        //cout<<"ans="<<ans<<endl;
        //cout<<"l="<<l<<endl;
        ans=n-ans;
        if(ans==0)
        {
            printf("Case #%d: %d\n",cas++,b);
            continue;
        }
        int cur=0;
        int i;
        for(i=1;i<=b;i++)
        {
            if(l%a[i]==0)
                cur++;
            if(cur==ans)
                break;
        }
        if(i==b+1)
            i=b;
        printf("Case #%d: %d\n",cas++,i);
    }
    return 0;
}






