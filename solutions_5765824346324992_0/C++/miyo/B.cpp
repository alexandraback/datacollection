#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

template <typename T>
inline void upd_max(T &dest,const T& src){if(dest<src)dest=src;return ;}
template <typename T>
inline void upd_min(T &dest,const T& src){if(dest>src)dest=src;return ;}

const int maxB=1000+13;

int T,B;
long long N,m[maxB];

bool check(long long t)
{
  long long ts=0ll;//long long fi=0ll;
  for(int i=1;i<=B;i++)
  {
    ts+=t/m[i]+1ll;
    //if(t%m[i]==0ll) fi++;
  }
  //if(ts+fi>=N)
  if(ts>=N)
    return true;
  else
    return false;
}

int getans(long long t)
{
  long long ts=0ll;
  for(int i=1;i<=B;i++)
  {
    ts+=t/m[i];
    if(t%m[i]>0)ts++;
  }
  int k=(int)(N-ts);
  //cout<<ts<<endl;
  //cout<<N<<endl;
  //cout<<k<<endl;
  if(k==0)k+=B;
  int ind=0;
  for(int i=1;i<=B;i++)
  {
    if(t%m[i]==0)
      ind++;
    if(ind==k) return i;
  }
  //cout<<ind<<endl;
  return -1;
}

int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);

  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
    scanf("%d%I64d",&B,&N);
    printf("Case #%d: ",cas);
    if(N==1ll)
    {
      printf("1\n");
      continue;
    }
    long long ll=-1,rr=100000ll;
    for(int i=1;i<=B;i++)
    {
      scanf("%I64d",&m[i]);
      upd_min(rr,m[i]);
    }
    rr*=N;
    while(ll<rr-1ll)
    {
      long long mid=(ll+rr)>>1;
      if(check(mid))
        rr=mid;
      else
        ll=mid;
    }
    //cout<<"rr:";cout<<rr<<endl;
    //cout<<check(rr-1)<<endl;
    int ans=getans(rr);
    printf("%d\n",ans);
  }

  return 0;
}

