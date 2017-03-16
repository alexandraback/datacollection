#include <bits/stdc++.h>
#define For(i,l,r) for (int i=(l),r__=(r);i<=r__;i++)
using namespace std;
int a[1100000];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.in.out","w",stdout);
    int ta;
    cin>>ta;
    For(tz,1,ta)
    {
        int n;
        cin>>n;
        For(i,1,n)
            cin>>a[i];
        int ans1=0,md2=0;
        For(i,2,n)
        {
            ans1=ans1+max(0,a[i-1]-a[i]);
            md2=max(md2,a[i-1]-a[i]);
        }
        int ans2=0;
        For(i,2,n)
            ans2+=min(a[i-1],md2);
        printf("Case #%d: %d %d\n",tz,ans1,ans2);
    }
}
