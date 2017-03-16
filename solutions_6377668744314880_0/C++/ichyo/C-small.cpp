// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}
typedef complex<double> P;
const double EPS = 1e-8;

// 誤差を加味した符号判定
int sign(double x){ return (x > EPS) - (x < -EPS); }
int comp(double x, double y) { return sign(x - y); }

// 内積・外積
double dot(P a, P b){return real(conj(a) * b);}
double cross(P a, P b){return imag(conj(a) * b);}

// OAとOBのなす符号付き角度 [-pi, pi]
// example : (1, 0), (0, 1) -> pi/2
double angle(P a, P b){return arg(conj(a) * b);}

// aをc中心にb[rad]回転
P rotate(P a, double b, P c = P()){return (a - c) * polar(1.0, b) + c;}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > +EPS)   return +1; // 反時計回り
    if (cross(b, c) < -EPS)   return -1; // 時計回り
    if (dot(b, c) < 0)     return +2; // c--a--b の順番で一直線上
    if (norm(b) < norm(c)) return -2; // a--b--c の順番で一直線上
    return 0;                         // 点が線分ab上にある
}

enum{ OUT, ON, IN };

// Pointの比較をしたいときだけ定義する．
namespace std{
    bool operator < (const P& a, const P& b) {
        return comp(a.real(), b.real()) ? a.real() < b.real() : a.imag() < b.imag();
    }
};
typedef vector<P> Pol;
Pol convex_hull(vector<P> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());

    vector<P> ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++]){ // lower-hull
        while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) == -1) --k;
    }
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]){ // upper-hull
        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) == -1) --k;
    }
    ch.resize(k-1);
    return ch;
}
void solve() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    REP(i, N) cin >> X[i] >> Y[i];

    vector<int> ans(N, N-1);

    REP(s, 1 << N) {
        int C = N - __builtin_popcount(s);
        if(C >= N-1) continue;
        Pol pol;
        REP(i, N) if(s >> i & 1) pol.push_back(P(X[i], Y[i]));
        pol = convex_hull(pol);
        for(auto p : pol) {
            REP(i, N) if(comp(1.0 * X[i], p.real()) == 0 && comp(1.0 * Y[i], p.imag()) == 0) {
                ans[i] = min(ans[i], C);
            }
        }
    }
    REP(i, N) {
        cout << ans[i] << endl;
    }
}
int main(){
    iostream_init();
    int TEST_CASE; cin >> TEST_CASE;
    for(int i = 1; i <= TEST_CASE; i++){
        cout << "Case #" << i << ":" << endl;
        solve();
    }
    return 0;
}

/* vim:set foldmethod=marker: */

