#include <bits/stdc++.h>

#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define each(it,n) for(__typeof((n).begin()) it=(n).begin();it!=(n).end();++it)

using namespace std;

typedef long long ll;

// primitives
typedef long double Real;
typedef complex<Real> Point;
typedef pair<Point, Point> Line;
typedef pair<Point, Real> Circle;
typedef vector<Point> Poly;

Real eps = 1e-9;

inline bool near(const Point& p, const Point& q){return abs(p - q) < eps;}

inline Real dot(const Point& p, const Point& q){return p.real() * q.real() + p.imag() * q.imag();}
inline Real cross(const Point& p, const Point& q){return p.real() * q.imag() - p.imag() * q.real();}

// ccw_b : old version of ccw.
inline Real ccw_b(const Point& p, const Point& q, const Point& r) {return cross(q - p, r - p);}

/* ccw :
CD  : counter direction
CW  : clock wise
OS  : on segment
CCW : counter clock wise
D   : direction
 */
enum LPposit { P_CD = -2, P_CW = -1, P_OS = 0, P_CCW = 1, P_D = 2};
LPposit ccw(const Point& p, const Point& q, const Point& r) {
  Real c = ccw_b(p, q, r);
  if (c < -eps) return P_CW;
  if (c >  eps) return P_CCW;
  if (dot(q - p, r - p) < -eps) return P_CD;
  if (dot(p - q, r - q) < -eps) return P_D;
  return P_OS;
}

// convex-hull                                                                  
// return minimum convex polygon that contains every point in vs.               
// depend on ccw                                                                
namespace std{
  bool operator<(const Point& a, const Point& b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
  }
}

Poly convexHull(vector<Point> ps) {
  int n = ps.size();
  sort(ps.begin(), ps.end());

  Poly ret(2 * n);
  int m = 0;
  for (int i = 0; i < n; i++) {
    while (m >= 2 && ccw(ret[m-2], ret[m-1], ps[i]) < 0) m--;
    ret[m++] = ps[i];
  }

  int t = m;
  for (int i = n-2; i >= 0; i--) {
    while (m >= t && ccw(ret[m-2], ret[m-1], ps[i]) < 0) m--;
    ret[m++] = ps[i];
  }

  ret.resize(m - 1);
  return ret;
}

int N;
vector<Point> P;

bool onConvexHull(int index, int bit) {
    if (__builtin_popcount(bit) < 3) return true;
    vector<Point> pts;
    rep(i, N) {
        if ((bit >> i) & 1) pts.push_back(P[i]);
    }
    Poly hull = convexHull(pts);
    rep(i, hull.size()) {
        int j = (i + 1) % hull.size();
        if (ccw(P[index], hull[i], hull[j]) == P_OS) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> N;
    P = vector<Point>(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        P[i] = Point(x, y);
    }

    cout << endl;
    rep(i, N) {
        int ans = 0;
        rep(j, 1 << N) {
            if (onConvexHull(i, j)) {
                ans = max(ans, __builtin_popcount(j));
            }
        }
        cout << N - ans << endl;
    }
}

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case #" << i + 1 << ": "; 
        solve();
    }
    return 0;
}
