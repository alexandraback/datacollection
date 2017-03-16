#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN=1000+10;
int a[MAXN];
int main()
{
//   freopen("in.txt","r",stdin);
//   freopen("out.txt","w",stdout);
    int t,kcase=0;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       ll ans1=0,ans2=0;
       ll rate=0;
       for(int i=0;i<n;i++) scanf("%d",a+i);
       for(int i=1;i<n;i++)
       {
          if(a[i-1]>a[i])
          {
            ans1+=a[i-1]-a[i];
            rate=max(rate,(ll)a[i-1]-a[i]);
          }
       }
        for(int i=0;i<n-1;i++)
        {
           ans2+=min(rate,(ll)a[i]);
        }
//       ans2=rate*(n-1);
       printf("Case #%d: ",++kcase);
       cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}
