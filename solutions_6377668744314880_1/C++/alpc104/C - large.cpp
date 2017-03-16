#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <limits>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define x first
#define y second
#define sf scanf
#define pf printf
#define vec vector
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define clr(a,b) memset(a,b,sizeof(a))
#define bin_cnt(x) __builtin_popcount(x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define srep(sub,s) for(int sub=s&(s-1);sub;sub=(sub-1)&s)
#define irep(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define irrep(i,a) for(__typeof(a.rbegin()) i=a.rbegin();i!=a.rend();i++)
#define inf numeric_limits<int>::max()
#define finf numeric_limits<double>::infinity()
#define eps 1e-8
#pragma GCC optimize ("O3")
#define o3 __attribute__((optimize("O3")))
#pragma comment(linker, "/STACK:32505856")

template<class T> inline T sqr(T a) {return a*a;}
template<class T> inline void gmin(T&a,T b) {if(a>b)a=b;}
template<class T> inline void gmax(T&a,T b) {if(a<b)a=b;}
inline int dcmp(const double &a) {return a>eps?1:(a<-eps?-1:0);}
struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}}initializer;


typedef double dat;
struct dot {
  dat x,y;
  dot(dat x,dat y) : x(x),y(y) {}
  bool operator<(const dot &b) const {return mp(y,x)<mp(b.y,b.x);}
  bool operator==(const dot &b) const {return mp(y,x)==mp(b.y,b.x);}
};

dat cross(dot p,dot q) {return p.x*q.y-p.y*q.x;}
dat area2(dot a,dot b,dot c) {return cross(a,b)+cross(b,c)+cross(c,a);}

void ConvexHull(vector<dot> &pts) {
  sort(all(pts));
  pts.erase(unique(all(pts)),pts.end());
  vector<dot> up,dn;
  for (int i=0;i<sz(pts);i++) {
    while (sz(up)>1 && area2(up[sz(up)-2],up.back(),pts[i])>=0) up.pop_back();
    while (sz(dn)>1 && area2(dn[sz(dn)-2],dn.back(),pts[i])<=0) dn.pop_back();
    up.pb(pts[i]);
    dn.pb(pts[i]);
  }
  pts=dn;
  for (int i=sz(up)-2;i>=1;i--) pts.pb(up[i]);
}

inline double multi(const dot &a, const dot &b, const dot &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}


int n,flag,self,ans,cnt;
int cut[3100];
vec<dot> a;

inline double dist(const dot &a, const dot &b) {
  return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

void check() {
  vec<dot> ta;
  rep(i,0,n-1)
    if (!cut[i]) {
      ta.pb(a[i]);
    }

  ConvexHull(ta);
  rep(i,0,sz(ta)-1) {
    double
      d0=dist(ta[i],ta[(i+1)%sz(ta)]),
      d1=dist(a[self],ta[i]),
      d2=dist(a[self],ta[(i+1)%sz(ta)]);
    if (dcmp(d0-d1-d2)==0) {
      ans=cnt;
      return;
    }
  }
}

int main() {
//  freopen("in.txt","r",stdin);
  freopen("C-large.in","r",stdin);
  freopen("l-out.txt","w",stdout);

  int T;
  sf("%d",&T);
  rep(cas,1,T) {
    pf("Case #%d:\n",cas);

    sf("%d",&n);
    a.clear();
    rep(i,1,n) {
      int x,y;
      sf("%d%d",&x,&y);
      a.pb(dot(x,y));
    }

    rep(i,0,n-1) {
      ans=inf;
      self=i;
      clr(cut,0);
      check();

      if (ans)
        rep(j,0,n-1)
          if (i!=j) {
            clr(cut,0);
            cnt=0;
            rep(k,0,n-1)
              if (multi(a[i],a[j],a[k])>eps) {
                cut[k]=1;
                cnt++;
                if (cnt>=ans) break;
              }
            if (cnt<ans) check();

            clr(cut,0);
            cnt=0;
            rep(k,0,n-1)
              if (!(multi(a[i],a[j],a[k])>eps)) {
                cut[k]=1;
                cnt++;
                if (cnt>=ans) break;
              }
            if (cnt<ans) check();
          }
      pf("%d\n",ans);
    }
  }
  return 0;
}
