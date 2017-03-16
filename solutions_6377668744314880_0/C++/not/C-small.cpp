#include <iostream>
#include <vector>

using namespace std;

class range {
private:
  struct Iterator {
    int val;
    int operator*() {return val;}
    bool operator!=(Iterator& itr) {return val < itr.val;}
    void operator++() {++val;}
  };
  Iterator i, n;
public:
  range(int n) : i({0}), n({n}) {}
  range(int i, int n) : i({i}), n({n}) {}
  Iterator& begin() {return i;}
  Iterator& end() {return n;}
};

template<class T> inline T at(const vector<T> &v, int i) {return v[(i % (int)v.size() + v.size()) % v.size()];}

template<class T> inline bool is_max(T &a, const T &b) {return a < b ? a = b, true : false;}
template<class T> inline bool is_min(T &a, const T &b) {return a > b ? a = b, true : false;}

#include <algorithm>
#include <complex>

#define X real()
#define Y imag()

typedef long double Real;
typedef complex<Real> Point;
struct Line{Point a, b;};
typedef vector<Point> Polygon;

const Real EPS = 1e-8;
const Real PI = acos(-1);

// 比較関数
inline int sgn(Real a, Real b = 0) {return a < b - EPS ? -1 : a > b + EPS ? 1 : 0;}
inline bool near(Point a, Point b) {return !sgn(abs(a - b));}
namespace std {
  inline bool operator<(Point a, Point b) {return sgn(a.X, b.X) ? a.X < b.X : a.Y < b.Y;}
  inline bool operator<(Line a, Line b) {return !near(a.a, b.a) ? a.a < b.a : a.b < b.b;}
}

// 平方根
inline Real sr(Real a) {return sqrt(max(a, (Real)0));}

// 内積
inline Real dot(const Point& a, const Point& b) {return a.X * b.X + a.Y * b.Y;}
// 外積
inline Real det(const Point& a, const Point& b) {return a.X * b.Y - a.Y * b.X;}

// 線分のベクトル
inline Point vec(const Line& a) {return a.b - a.a;}

// 線分abに対する点cの位置
enum CCW{FRONT = 1, RIGHT = 2, BACK = 4, LEFT = 8, ON = 16};
inline int ccw(const Point& a, const Point& b, const Point& c) {
  if (near(a, c) || near(b, c)) return ON;
  int s = sgn(det(b - a, c - a));
  if (s) return s > 0 ? LEFT : RIGHT;
  return (a < b) == (b < c) ? FRONT : (c < a) == (a < b) ? BACK : ON;
}

// 有向角度
inline Real arg(const Point& base, const Point& a, const Point& b) {return arg((b - base) / (a - base));}
Line sortBase;
inline bool lessArg(const Point& a, const Point& b) {
  Real ang1 = arg(sortBase.a, sortBase.b, a);
  Real ang2 = arg(sortBase.a, sortBase.b, b);
  return sgn(ang1, ang2) ? ang1 < ang2 : norm(a) > norm(b);
}

// 射影
inline Point proj(const Point& a, const Point& b) {return a * dot(a, b) / norm(a);}
inline Point perp(const Line& l, const Point& p) {return l.a + proj(vec(l), p - l.a);}
inline Point refl(const Line& l, const Point& p) {return perp(l, p) * (Real)2 - p;}

// 交差判定
inline bool eqL(const Line& a, const Line& b) {return !sgn(det(vec(a), vec(b))) && !sgn(det(vec(a), b.a - a.a));}
inline bool iLL(const Line& a, const Line& b, bool strict = false) {
  if (sgn(det(vec(a), vec(b)))) return true;
  return !strict && !sgn(det(vec(a), b.a - a.a));
}
inline bool iLS(const Line& a, const Line& b, bool strict = false) {
  if (strict) return sgn(det(vec(a), b.a - a.a)) * sgn(det(vec(a), b.b - a.a)) < 0;
  return sgn(det(vec(a), b.a - a.a)) * sgn(det(vec(a), b.b - a.a)) <= 0;
}
inline bool iSS(const Line& a, const Line& b, bool strict = false) {
  int cwa = ccw(a.a, a.b, b.a) | ccw(a.a, a.b, b.b);
  int cwb = ccw(b.a, b.b, a.a) | ccw(b.a, b.b, a.b);
  if ((cwa & cwb) == (LEFT | RIGHT)) return true;
  return !strict && ((cwa | cwb) & ON);
}

// 交点
inline Point pLL(const Line& a, const Line& b) {return a.a + vec(a) * (det(vec(b), b.a - a.a) / det(vec(b), vec(a)));}

// 距離
inline Real dLP(const Line& l, const Point& p) {return abs(det(vec(l), p - l.a) / vec(l));}
inline Real dSP(const Line& s, const Point& p) {
  if (dot(vec(s), p - s.a) < 0) return abs(p - s.a);
  if (dot(vec(s), p - s.b) > 0) return abs(p - s.b);
  return dLP(s, p);
}
inline Real dLL(const Line& a, const Line& b) {return iLL(a, b) ? 0 : dLP(a, b.a);}
inline Real dLS(const Line& a, const Line& b) {return iLS(a, b) ? 0 : min(dLP(a, b.a), dLP(a, b.b));}
inline Real dSS(const Line& a, const Line& b) {return iSS(a, b) ? 0 : min(min(dSP(a, b.a), dSP(a, b.b)), min(dSP(b, a.a), dSP(b, a.b)));}

// 角の内外判定 角abの内部にあれば正、辺上は0、外部は負
inline int sAP(const Point& a, const Point& b, const Point& c) {return sgn(det(a, c)) - sgn(det(b, c)) - sgn(det(a, b));}

// 多角形の面積
inline Real aPol(const Polygon& vp) {Real ret = 0; for (int i : range(vp.size())) ret += det(vp[i], at(vp, i + 1)); return ret / 2;}

// 多角形の内外判定 内部:1、周上:0、外部:-1
inline int sGP(const Polygon& pol, const Point& p) {
  int side = -1;
  for (int i : range(pol.size())) {
    Point p0 = pol[i] - p, p1 = at(pol, i + 1) - p;
    if (ccw(p0, p1, 0) == ON) return 0;
    if (p0.Y > p1.Y) swap(p0, p1);
    if (sgn(p0.Y) <= 0 && 0 < sgn(p1.Y) && sgn(det(p0, p1)) > 0) side *= -1;
  }
  return side;
}

// 凸包
inline Polygon convexHull(Polygon p) {
  int m = -1, n = p.size();
  if (n < 3) return p;
  vector<Point> q(n * 2);
  sort(p.begin(), p.end());
  for (int i = 0; i < n; q[++m] = p[i++]) for (; m > 0 && ccw(q[m - 1], q[m], p[i]) != LEFT; --m);
  for (int i = n - 2, r = m; i >= 0; q[++m] = p[i--]) for (; m > r && ccw(q[m - 1], q[m], p[i]) != LEFT; --m);
  q.resize(m);
  return q;
}

// 凸多角形カット
inline Polygon convexCut(const Polygon& p, const Line& l) {
  vector<Point> q;
  for (int i : range(p.size())) {
    if (ccw(l.a, l.b, p[i]) != RIGHT) q.emplace_back(p[i]);
    Line s = {p[i], at(p, i + 1)};
    if (iLS(l, s, true)) q.emplace_back(pLL(l, s));
  }
  return q;
}

void solve() {
  int n;
  cin >> n;
  vector<Point> trees;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    trees.emplace_back(x, y);
  }
  auto all = convexHull(trees);
  for (int k = 0; k < n; ++k) {
    int res = 1e9;
    for (int bit = 0; bit < (1 << n); ++bit) {
      vector<Point> t;
      for (int i = 0; i < n; ++i) {
        if (bit & 1 << i) t.emplace_back(trees[i]);
      }
      auto convex = convexHull(t);
      for (int i = 0; i < int(convex.size()); ++i) {
        if (ccw(convex[i], at(convex, i + 1), trees[k]) == ON) res = min(res, n - __builtin_popcount(bit));
      }
    }
    cout << res << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cerr << i << endl;
    cout << "Case #" << i << ":" << endl;
    solve();
  }
}
