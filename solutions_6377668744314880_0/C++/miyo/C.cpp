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


#define sqr(x) ((x)*(x))
#define fi frist
#define se second

const double Eps=1e-6;
const double PI=acos(-1.0);

inline int sig(double x, double eps = Eps)
{
  return x<-eps?-1:x>eps;
}

inline double deg2rad(double d)
{
  return d*PI/180.0;
}
inline double rad2deg(double r)
{
  return r*180.0/PI;
}

struct Point
{
  double x,y;
  Point(){};
  Point(double x,double y):x(x),y(y){};
  Point operator + (const Point& b)
  {
    return Point(x+b.x,y+b.y);
  }
  Point operator - (const Point& b)
  {
    return Point(x-b.x,y-b.y);
  }
  Point operator * (const double& a)
  {
    return Point(x*a,y*a);
  }
  Point operator / (const double& a)
  {
    return Point(x/a,y/a);
  }
  double operator * (const Point& b)
  {
    return x*b.x+y*b.y;
  }
  double operator % (const Point& b)
  {
    return x*b.y-y*b.x;
  }
  double dis()
  {
    return hypot(x,y);
  }
  double dis2()
  {
    return sqr(x)+sqr(y);
  }
  double alpha() 
  {
    return atan2(y,x);
  }
  double disTo(const Point& a) 
  {
    double dx=x-a.x,dy=y-a.y;
    return hypot(dx,dy);
  }
  double alphaTo(const Point& a)
  {
    double dx=x-a.x,dy=y-a.y;
    return atan2(dy,dx);
  }
  Point rot90()
  {
    return Point(y,-x);
  }
  Point rot(double al)//radian measure---- counter-clockwise
  {
    return Point(x*cos(al)-y*sin(al),x*sin(al)+y*cos(al));
  }
  void read()
  {
    scanf("%lf%lf",&x,&y);
  }
  void print()
  {
    printf("%.3lf %.3lf\n",x,y);
  }
  bool operator<(const Point&p) const {
    int c = sig(x - p.x);
    if (c) return c == -1;
    return sig(y - p.y) == -1;
  }
  
};
const Point O=Point(0,0);

typedef vector<Point> vP;

bool cmp_cH(const Point& a,const Point& b)
{
  if(sig(a.x-b.x)==0)return a.y<b.y;
  return a.x<b.x;
}

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sig(cross(p1,p2,p3))

//Í¹°ü ÄæÊ±Õë
vP _convexHull(vP ps)
{
  int n=ps.size(),k=0;
  if(n<=1)return ps;
  //sort(ps.begin(),ps.end(),cmp_cH);
  vP qs;
  for(int i=0;i<n;qs[k++]=ps[i++])
    while(k>1 && (qs[k-1]-qs[k-1])%(ps[i]-qs[k-1])<Eps)k--;
  for(int i=n-2,t=k;i>=0;qs[k++]=ps[i--])
    while(k>t && (qs[k-1]-qs[k-2])%(ps[i]-qs[k-1])<Eps)k--;
  vP ret;
  for(int i=0;i<k-1;i++)
    ret.push_back(qs[i]);
  return ret;
}

vP convexHull(vP ps) 
{
  int n = ps.size();
  if (n <= 1) return ps;
  sort(ps.begin(), ps.end());
  vector<Point> qs;
  for (int i = 0; i < n; qs.push_back(ps[i++])) 
  {
    while (qs.size() > 1 && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
      qs.pop_back();
  }
  for (int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--])) {
    while ((int)qs.size() > t && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
    qs.pop_back();
  }
  qs.pop_back();
  return qs;
}

const int maxN=100;

int T,N;
Point a[maxN];

int main()
{
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);

  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
    printf("Case #%d:\n",cas);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
      a[i].read();
    for(int i=1;i<=N;i++)
    {
      int ans=100+13;;
      //cout<<"i:"<<i<<endl;
      for(int j=1;j<=N;j++)if(i!=j)
      {
        if(sig(a[i].x-a[j].x)==0)
        {
          int l=0,r=0;
          for(int k=1;k<=N;k++)
          {
            if(k==i || k==j)continue;
            if(sig(a[k].x-a[i].x)==-1) l++;
            else if(sig(a[k].x-a[i].x)==1) r++;
          }
          //a[i].print();a[j].print();
          //cout<<l<<' '<<r<<endl;
          upd_min(ans,min(l,r));
        }
        else
        {
          double k,b;
          int l=0,r=0;
          k=(a[i].y-a[j].y)/(a[i].x-a[j].x);
          b=-k*a[i].x+a[i].y;
          //cout<<"j:"<<j<<endl;
          //a[j].print();
          //cout<<k<<' '<<b<<endl;
          for(int tt=1;tt<=N;tt++) 
          {
            if(tt==i || tt==j)continue;
            double td=k*a[tt].x+b-a[tt].y;
            //cout<<tt<<' '<<a[tt].x<<' '<<a[tt].y<<' '<<td<<endl;
            if(sig(td)==1) l++;
            else if(sig(td)==-1) r++;
          }
          upd_min(ans,min(l,r));
          //a[i].print();a[j].print();
          //cout<<l<<' '<<r<<endl;
          upd_min(ans,min(l,r));
        }
      }
      printf("%d\n",ans);
    }
    //vP tt;
    //for(int i=1;i<=N;i++)
    //  tt.push_back(a[i]);
    //tt=convexHull(tt);
    //for(int i=0;i<(int)tt.size();i++)
    //  tt[i].print();
  }
  return 0;
}

