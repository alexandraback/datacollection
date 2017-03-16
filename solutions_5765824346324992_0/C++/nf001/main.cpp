#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define N 200000
#define M 1001
#define mm 100007
#define ll long long
int A,B;
int b,n,m[1001],ans;
bool check(ll p)
{
    int rd=0;
    ll cnt=0;
    if (p==0) {
        rd=b;
        cnt=0;
    }
    else
    for (int i=1;i<=b;i++)
    {
        cnt+=(p-1)/m[i]+1;
        if (p%m[i]==0) rd++;
    }
    if (cnt>=n) return 1;
    for (int i=1;i<=b;i++)
    {
        if (p%m[i]==0) cnt++;
        if (cnt==n) {
            ans=i;
            break;
        }
    }
    return 0;
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T,cas=0;
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&b,&n);
        for (int i=1;i<=b;i++)
            scanf("%d",&m[i]);
        ll l,r;
        l=0;r=1ll<<61;
        while (l<r)
        {
            ll mid=(l+r+1)>>1;
            if (check(mid)) r=mid-1;
            else l=mid;
        }
        check(l);
      //  cout<<l<<endl;
        printf("Case #%d: %d\n",++cas,ans);
    }
}
