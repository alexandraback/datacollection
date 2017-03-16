#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN=1000+10;
int a[MAXN];
int b,n;
ll jd(ll t)
{
   ll ans=0;
   for(int i=0;i<b;i++)
   {
      ans+=t/a[i];
      if(t%a[i]) ans++;
   }
   return ans;
}
int main()
{
//   freopen("in.txt","r",stdin);
//   freopen("out.txt","w",stdout);
    int t,kcase=0;
    cin>>t;
    while(t--)
    {
       cin>>b>>n;
       for(int i=0;i<b;i++) scanf("%d",a+i);
       ll l=0,r=1e16+1;
       ll tim=0;
       while(l<=r)
       {
            ll mid=l+(r-l)/2;
            if(jd(mid)<=n-1)
            {
               l=mid+1;
               tim=mid;
            }
            else
               r=mid-1;
       }
//       cout<<tim<<endl;
//       cout<<jd(tim)<<endl;
       ll ed=n-jd(tim);
       int ans=0,cnt=0;
       for(int i=0;i<b;i++)
       {
            if(tim%a[i]==0)
            {
               cnt++;
               if(cnt==ed)
                  ans=i+1;
            }
       }
       printf("Case #%d: ",++kcase);
       cout<<ans<<endl;
    }
    return 0;
}
