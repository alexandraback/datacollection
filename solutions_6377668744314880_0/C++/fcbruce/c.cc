/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 18 Apr 2015 10:53:45 AM CST
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
#define maxn 233

using namespace std;

int dcmp(double x,double y)
{
  if (fabs(x-y)<1e-6) return 0;
  if (x<y) return -1;
  return 1;
}

struct point
{
  int id;
  double x,y;
  point(){}
  point(double x,double y) : x(x) ,y(y) {}
  void read(int i)
  {
    id=i;
    scanf("%lf%lf",&x,&y);
  }
  point operator + (point p)
  {
    return point(x+p.x,y+p.y);
  }
  point operator - (point p)
  {
    return point(x-p.x,y-p.y);
  }
  point operator * (double  d)
  {
    return point(x*d,y*d);
  }
  double dot(point p)
  {
    return x*p.x+y*p.y;
  }
  double det(point p)
  {
    return x*p.y-y*p.x;
  }
}p[maxn],q[maxn];

bool cmp(const point &p,const point &q)
{
  if (dcmp(p.x,q.x)!=0) return p.x<q.x;
  return p.y<q.y;
}

vector<point> convex(point *ps,int n)
{
  sort(ps,ps+n,cmp);
  int k=0;
  vector<point> qs(n*2);
  for (int i=0;i<n;i++) 
  {
    while (k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<eps) k--;
    qs[k++]=ps[i];
  }

  for (int i=n-2,t=k;i>=0;i--)
  {
    while (k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<eps) k--;
    qs[k++]=ps[i];
  }

  if (k>1)qs.resize(k-1);
  return qs;
}

int ans[maxn];

int main()
{
#ifdef FCBRUCE
  //freopen("/home/fcbruce/code/t","r",stdin);
  freopen("C-small-attempt1.in","r",stdin);
  freopen("C1.out","w",stdout);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) p[i].read(i);


    memset(ans,0x3f,sizeof ans);
    for (int i=1;i<(1<<n)-1;i++)
    {
      int k=0;
      for (int j=0;j<n;j++)
      {
        if (i&(1<<j)) q[k++]=p[j];

      }
      auto res=convex(q,k);
      for (auto e:res) 
      {
        ans[e.id]=min(ans[e.id],n-k);
      }
       
    }

    printf("Case #%d:\n",++__);
    for (int i=0;i<n;i++) printf("%d\n",ans[i]-1);
  }



  return 0;
}
