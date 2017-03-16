#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
void checkmax(int&a, int b) { if (b>a) a=b; }
void checkmin(int&a, int b) { if (b<a) a=b; }
double eps = 1e-8;
const int N = 3010;
int n;
struct Point
{
  long long x, y;
  Point() {}
  Point(long long X, long long Y):x(X), y(Y){}
  void init()
  {
    cin >> x >> y;
  }
  double len()
  {
    return sqrt(1.0*x*x+1.0*y*y);
  }
}P[N], Q[N], O;
Point operator-(const Point&a, const Point&b)
{
  return Point(a.x-b.x, a.y-b.y);
}
long long operator*(const Point&a, const Point&b)
{
  return a.x*b.y-a.y*b.x;
}
bool operator==(const Point&A, const Point&B)
{
  return A.x==B.x && A.y==B.y;
}
bool operator<(const Point&A, const Point&B)
{
  if (A==O)
    return true;
  if (B==O)
    return false;
  Point a = A-O;
  Point b = B-O;
  return atan2(a.y,a.x) < atan2(b.y,b.x);
}
void init()
{
  cin >> n;
  for(int i=1; i<=n; ++i)
  {
    P[i].init();
    Q[i] = P[i];
  }
}
int ans[N];
double angle[N];
bool at(double a, double l, double r)
{
  if (fabs(l-a) < eps)
    return true;
  if (fabs(r-a) < eps)
    return true;
  return false;
}
bool between(double a, double l, double r)
{
  if (at(a,l,r))
    return false;
  if (l < r)
    return l<a && a<r;
  return r<a && a<l;
}
const double PI = acos(0)*2;
double half(double p)
{
  if (p>=PI/2)
    return p-PI;
  return p+PI;
}
void work()
{
  for(int i=1; i<=n; ++i)
    ans[i] = N*2;
  for(int i=1; i<=n; ++i)
  {
    int tot = 0;
    for(int j=1; j<=n; ++j)
      if (j!=i)
      {
        Point q = P[j]-P[i];
        angle[++tot] = atan2(q.y, q.x);
      }
    sort(angle+1, angle+1+tot);
    for(int j=1; j<=tot; ++j)
    {
      int bet = 0;
      int line = 0;
      double L = angle[j];
      double R = half(angle[j]);
      for(int k=1; k<=tot; ++k)
        if (between(angle[k], L, R))
          bet++;
        else if(at(angle[k], L, R))
          line++;
      checkmin(ans[i], min(bet, n-1-line-bet));
    }
  }
  for(int i=1; i<=n; ++i)
    printf("%d\n", ans[i]);
}
int main()
{
//  freopen("in","r",stdin);
  int T;
  cin >> T;
  for(int i=1; i<=T; ++i)
  {
    init();
    printf("Case #%d:\n", i);
    work();
  }
}
