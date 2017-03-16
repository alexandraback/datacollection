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
int a[maxN][maxN];

inline int count(int x)
{
  //cout<<x<<' ';
  int ret=0;
  for(int i=1;i<=R;i++)
  {
    for(int j=1;j<=C;j++)
    {
      a[i][j]=x&1;
      if(x&1)ret++;
      x>>=1;
    }
  }
  //cout<<ret<<endl;
  if(ret!=N)return inf;
  ret=0;
  for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++)
      for(int k=0;k<4;k++)
        if(a[i][j]+a[i+dx[k]][j+dy[k]]==2)
          ret++;
  return ret;
}

int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int T;
  cin>>T;
  for(int cas=1;cas<=T;cas++)
  {
    cin>>R>>C>>N;
    for(int i=0;i<=R+1;i++)
      a[i][0]=a[i][C+1]=-1;
    for(int i=0;i<=C+1;i++)
      a[0][i]=a[R+1][i]=-1;
    int tt=(1<<(R*C))-1;
    cout<<"Case #"<<cas<<": ";
    if(N==0)
    {
      cout<<0<<endl;
      continue;
    }
    int ans=0x7f7f7f7f;
    for(int i=0;i<=tt;i++)
      upd_min(ans,count(i));
    cout<<ans/2<<endl;
  }
  return 0;
}

