/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 18 Apr 2015 09:33:02 AM CST
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 1007

using namespace std;

struct B
{
  int id;
  long long t;
  bool operator < (const B &rhs) const
  {
    if (t==rhs.t) return id<rhs.id;
    return t<rhs.t;
  }
}b[maxn];
int n,m;

long long check(long long mid)
{
  long long res=0;
  for (int i=0;i<n;i++)
  {
      res+=mid/b[i].t+1;
  }
  return res;
}

int calc(long long mid)
{
  for (int i=0;i<n;i++)
  {
    if (mid%b[i].t==0) return i+1;
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("B-large.in","r",stdin);
  freopen("Blar.out","w",stdout);
  //freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%d%d",&n,&m);

    for (int i=0;i<n;i++) 
    {
      long long v;
      scanf("%lld",&v);
      b[i]={i+1,v};
    }

    long long l=0,r=1ll<<50;
    long long ans;

    while (l<=r)
    {
      long long mid=l+r>>1;

      long long res=check(mid);

      if (res>=m)
      {
        ans=mid;
        r=mid-1;
      }
      else
      {
        l=mid+1;
      }
    }

    long long  cnt=0;
    int ass=-1;
    for (int i=0;i<n;i++)
    {
      if (ans%b[i].t) cnt++;
      cnt+=ans/b[i].t;
    }
    for (int i=0;i<n;i++)
    {
      if (ans%b[i].t==0)
      {
        cnt++;
        if (cnt==m)
        {
          ass=i+1;
        }
      }
    }

    printf("Case #%d: %d\n",++__,ass);
  }




  return 0;
}
