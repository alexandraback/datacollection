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

const int maxN=1000+13;

int T,N;
int m[maxN];

int main()
{
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);

  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
      scanf("%d",&m[i]);
    int ans1=0,ans2=0;
    for(int i=2;i<=N;i++)
      if(m[i]<m[i-1]) ans1+=m[i-1]-m[i];
    int tt=0;
    for(int i=2;i<=N;i++)
      upd_max(tt,m[i-1]-m[i]);
    for(int i=1;i<N;i++)
    {
      if(m[i]<=tt)
        ans2+=m[i];
      else
        ans2+=tt;
    }
    printf("Case #%d: %d %d\n",cas,ans1,ans2);
  }
  return 0;
}

