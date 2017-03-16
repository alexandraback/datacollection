#include <bits/stdc++.h>
using namespace std;
#define For(i,l,r) for (int i=(l),r__=(r);i<=r__;i++)
typedef long long LL;
int b,n;
int t[1100];
bool tru(LL x)
{
    LL sum=0;
    For(i,1,b)
        sum+=x/t[i]+1;
    return (sum>=n);
}
int get(LL x)
{
    int sum=0;
    For(i,1,b)
        sum+=(x-1)/t[i]+1;
    For(i,1,b)
        if (x%t[i]==0)
        {
            sum++;
            if (sum==n)
                return i;
        }
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int ta;
    cin>>ta;
    For(tz,1,ta)
    {
        cin>>b>>n;
        For(i,1,b)
            cin>>t[i];
        LL l=0,r=1e18;
        while (l<r)
        {
            LL mid=(r-l)/2+l;
            if (tru(mid))
                r=mid;
            else
                l=mid+1;
        }
//        cout<<"l="<<l<<endl;
        int ans=get(l);
        printf("Case #%d: %d\n",tz,ans);
    }
}


