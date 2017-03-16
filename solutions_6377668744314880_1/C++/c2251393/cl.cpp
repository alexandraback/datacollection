
// default code for competitive programming
// c2251393 ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define DEBUG 1
#define fst first
#define snd second
 
using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef tuple<ll, int> tli;
typedef pair<int, int> pii;
typedef tuple<int, int> tii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);
 
// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

// }}}
// start ~~QAQ~~

const int MAXN = 3010;
struct Point{
  typedef long long T;
  T x, y;
  
  Point() : x(0), y(0) {}
  Point(T _x, T _y) : x(_x), y(_y) {}

  bool operator < (const Point &b) const{
    return tie(x,y) < tie(b.x,b.y);
  }
  bool operator == (const Point &b) const{
    return tie(x,y) == tie(b.x,b.y);
  }
  Point operator + (const Point &b) const{
    return Point(x+b.x, y+b.y);
  }
  Point operator - (const Point &b) const{
    return Point(x-b.x, y-b.y);
  }
  T operator * (const Point &b) const{
    return x*b.x + y*b.y;
  }
  T operator % (const Point &b) const{
    return x*b.y - y*b.x;
  }
  Point operator * (const T &b) const{
    return Point(x*b, y*b);
  }
  T abs(){
    return sqrt(abs2());
  }
  T abs2(){
    return x*x + y*y;
  }
};
ll cross(Point o, Point a, Point b){
  return (a-o) % (b-o);
}
vector<Point> convex_hull(vector<Point> pt){
  sort(pt.begin(),pt.end());
  int top=0;
  vector<Point> stk(2*pt.size());
  for (int i=0; i<(int)pt.size(); i++){
    while (top >= 2 && cross(stk[top-2],stk[top-1],pt[i]) <= 0)
      top--;
    stk[top++] = pt[i];
  }
  for (int i=pt.size()-2, t=top+1; i>=0; i--){
    while (top >= t && cross(stk[top-2],stk[top-1],pt[i]) <= 0)
      top--;
    stk[top++] = pt[i];
  }
  stk.resize(top-1);
  return stk;
}
struct Cmp
{
  Point o;
  Cmp(Point _o) : o(_o) {}
  bool operator()(Point a, Point b)
  {
    a = a-o;
    b = b-o;
    if(b == o) return 1;
    if(a == o) return 0;
    if(a.y > 0 && b.y < 0) return 1;
    if(a.y < 0 && b.y > 0) return 0;
    return (a % b) > 0;
  }
};
int n;
Point in[MAXN], in2[MAXN];
int main()
{
  int tc;scanf("%d", &tc);
  REP(_, 1, tc)
  {printf("Case #%d:\n", _);
    scanf("%d", &n);
    REP(i, 1, n)
    {
      scanf("%lld%lld", &in[i].x, &in[i].y);
      in2[i] = in[i];
    }
    //vector<Point> ch = convex_hull(tmp);
    REP(i, 1, n)
    {
      auto nxt = [&](int x){
        if(x == n-1) return 1;
        return x + 1;
      };
      Cmp cmp(in[i]);
      REP(j, 1, n) in2[j] = in[j];
      swap(in2[i], in2[n]);
      sort(in2+1, in2+1+n-1, cmp);
      int l = 1, r = 2, cnt = 0, ans = 100000;
      if(n <= 3)
      {
        printf("0\n");
        continue ;
      }
      //printf("  o %d\n", i);
      //REP(j, 1, n) printf("   (%lld, %lld)\n", in2[j].x, in2[j].y);
      for(; l < n; l++, cnt--)
      {
        while(cross(in[i], in2[l], in2[r]) > 0)
        {
          cnt++;
          r = nxt(r);
        }
        ans = min(ans, max(cnt, 0));
      }
      if(n <= 3) ans = 0;
      printf("%d\n", ans);
    }
  }
}


