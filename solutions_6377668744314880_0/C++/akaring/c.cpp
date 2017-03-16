#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double EPS = 1E-10;
const double PI = acos(-1.0);
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS; }

struct Point {
  int id;
  double x, y;
  Point() {}
  Point(double a, double b): x(a), y(b) {}
  Point operator+(const Point &p) const {
    return Point(x + p.x, y + p.y);
  }
  Point operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
  }
  Point operator*(double d) const {
    return Point(x * d, y * d);
  }
  Point operator/(double d) const {
    return Point(x / d, y / d);
  }
  bool operator<(const Point &p) const {
    int c = sgn(x - p.x);
    return c ? c < 0 : sgn(y - p.y) < 0;
  }
  double dot(const Point &p) const {
    return x * p.x + y * p.y;
  }
  double det(const Point &p) const {
    return x * p.y - y * p.x;
  }
  double al() const {
    return atan2(y, x);
  }
  //%*有向角度*)
  double ang(const Point &p) const {
    return atan2(det(p), dot(p));
  }
  double abs() {
    return hypot(x, y);
  }
  double abs2() {
    return x * x + y * y;
  }
  int read() {
    return scanf("%lf%lf", &x, &y);
  }
  void write() {
    cout << "(" << x << "," << y << ")" << endl;
  }
  //%*当前点绕原点逆时针旋转d弧度*)
  Point rot(double d) const {
    double c = cos(d), s = sin(d);
    return Point(x * c - y * s, y * c + x * s);
  }
  Point rotleft() {
    return Point(-y, x);
  }
};

inline double crs(const Point &o, const Point &s, const Point &t) {
  return (s.x - o.x) * (t.y - o.y) - (s.y - o.y) * (t.x - o.x);
}
#define CRS(o,s,t) sgn(crs(o,s,t))

vector<Point> convex_hull(vector<Point> ps) {
  int n = SZ(ps);
  if (n <= 1) {
    return ps;
  }
  sort(ps.begin(), ps.end());
  vector<Point> qs;
  for (int i = 0; i < n; qs.PB(ps[i++])) {
    while (SZ(qs) > 1 && CRS(qs[SZ(qs) - 2], qs.back(), ps[i]) < 0) {
      qs.pop_back();
    }
  }
  for (int i = n - 2, t = SZ(qs); i >= 0; qs.PB(ps[i--])) {
    while (SZ(qs) > t && CRS(qs[SZ(qs) - 2], qs.back(), ps[i]) < 0) {
      qs.pop_back();
    }
  }
  qs.pop_back();
  return qs;
}

int n;
vector<Point> ps;

bool check(int id, int mask) {
  if (((mask >> id) & 1) == 0) {
    return false;
  }
  vector<Point> tp;
  REP (i, n) {
    if ((mask >> i) & 1) {
      tp.PB(ps[i]);
    }
  }
  auto qs = convex_hull(tp);
  for (auto p: qs) {
    if (p.id == id) {
      return true;
    }
  }
  return false;
}

void solve() {
  ps.clear();

  scanf("%d", &n);
  REP (i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    ps.PB(Point(x, y));
    ps.back().id = i;
  }

  map<int, int> ans;
  auto qs = convex_hull(ps);
  for (auto p: qs) {
    ans[p.id] = 0;
  }

  REP (i, n) {
    if (!ans.count(i)) {
      int c = n - 1;
      REP (mask, 1 << n) {
        if (n - __builtin_popcount(mask) < c && check(i, mask)) {
          c = n - __builtin_popcount(mask);
        }
      }
      ans[i] = c;
    }
  }

  for (auto p: ans) {
    printf("%d\n", p.Y);
  }
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d:\n", index);
    solve();
  }
  return 0;
}
