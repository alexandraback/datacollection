#include<bits/stdc++.h>
#define pb push_back
#define tr(c,i) for(typeof((c).begin() )i = (c).begin(); i != (c).end(); i++)
#define mod 1000000007
#define ii  pair<int,int>

using namespace std;
typedef long long ll;



using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int a[1010];

int main()
{
  int n,m,i,j,k,ans1,ans2,mn,mx,tst,t;

freopen("A-large.in", "r", stdin);
freopen("AlargeOUT.txt", "w", stdout);
scanf("%d",&t);
for(tst=1;tst<=t;tst++)
{
     scanf("%d",&n);
     ans1=ans2=0;
     mx=0;
     for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     for(i=n-1;i>0;i--)
     {
         if(a[i-1]-a[i]>mx)
         mx=a[i-1]-a[i];
     }
     for(i=0;i<n-1;i++)
     {
         if(a[i]<=mx)
         ans2+=a[i];
         else
         ans2+=mx;
     }
     for(i=0;i<n-1;i++)
     {
         if(a[i]>a[i+1])
         ans1+=(a[i]-a[i+1]);
     }
     printf("Case #%d: %d %d\n",tst,ans1,ans2);
}



    return 0;
}
