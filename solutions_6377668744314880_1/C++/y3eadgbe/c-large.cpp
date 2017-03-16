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

int N;
vector<Point> P;

const long double PI = 4 * atan(1);

int doit(int index) {
    vector<long double> args;
    rep(i, N) {
        if (i == index) continue;
        Point p = P[i] - P[index];
        long double a = arg(p);
        args.push_back(a);
        args.push_back(a + 2 * PI);
    }

    if (args.size() == 0) return 0;

    int ans = N;
    sort(args.begin(), args.end());
    int j = 0;
    rep(i, N - 1) {
        while (args[j] - args[i] - PI < eps) {
            j++;
        }
        ans = min((ll)ans, N - 1 - (j - i));
    }
    return ans;
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
        cout << doit(i) << endl;
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
