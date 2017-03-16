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

const int maxN=100+13;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
const int inf=0x7f7f7f7f;
int N,R,C;

int main()
{
  freopen("B.in","r",stdin);
  freopen("B1.out","w",stdout);
  int T;
  cin>>T;
  for(int cas=1;cas<=T;cas++)
  {
    cin>>R>>C>>N;
    int pN=N;
    cout<<"Case #"<<cas<<": ";
    int tt=(R*C+1)/2;
    if(N<=tt)
    {
      cout<<0<<endl;
      continue;
    }
    int c0=0,c1=0;
    int ans=0;
    if(R==1 || C==1)
    {
      if((R*C)&1){c0=0;c1=R*C-tt;}
      else {c0=1;c1=R*C-tt-1;}
      N-=tt;
      for(;N>0 && c0>0;c0--,N--) ans+=1;
      for(;N>0 && c1>0;c1--,N--) ans+=2;
      if((R*C)%2==0)
        cout<<ans<<endl;
      else
      {
        int ans2=0;
        N=pN;tt=N-tt;
        c0=2;c1=R*C-tt-c0;
        for(;N>0 && c0>0;c0--,N--) ans2+=1;
        for(;N>0 && c1>0;c1--,N--) ans2+=2;
        upd_min(ans,ans2);
        cout<<ans<<endl;
      }
      continue;
    }
    else if(R==2 || C==2){c0=2;c1=R*C-tt-2;}
    else
    {
      if(R&1)
      {
        if(C&1) c1+=(R/2)*2+(C/2)*2;
        else {c0=2;c1+=(R/2)*2-1+2*(C/2-1);}
      }
      else
      {
        c0=2;
        c1=(R/2-1)*2;
        if(C&1) c1+=(C/2)*2-1;
        else    c1+=(C/2-1)*2;
      }
    }
    N-=tt;
    for(;N>0 && c0>0;c0--,N--) ans+=2;
    for(;N>0 && c1>0;c1--,N--) ans+=3;
    ans+=N*4;
    if((R*C)%2==0)
    {
      cout<<ans<<endl;
      continue;
    }
    int ans2=0;
    if(R==2 || C==2 || (R*C)%2==0) cout<<ans<<endl;
    else
    {
      int dt=0,d0=0,d1=0;
      dt=(R*C-tt);
      if(R&1)
      {
        d0=4;d1=(R-2)/2*2;
        d1+=(C-2)/2*2;
      }
      pN-=dt;
      for(;pN>0 && d0>0;d0--,pN--) ans2+=2;
      for(;pN>0 && d1>0;d1--,pN--) ans2+=3;
      ans2+=pN*4;
    }
    upd_min(ans,ans2);
    cout<<ans<<endl;
  }
  return 0;
}

