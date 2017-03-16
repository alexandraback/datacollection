#include <bits/stdc++.h>//{{{
#define all(x) begin(x),end(x)
#define rall(x) (x).rbegin(),(x).rend()
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define repsz(i,v) rep(i,(v).size())
#define aur auto&
#define bit(n) (1LL<<(n))
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;
typedef long long ll;
//#define int long long
template<class C>int size(const C &c){ return c.size(); }
template<class T>bool chmin(T&a,const T&b){if(a<=b)return false;a=b;return true;}
template<class T>bool chmax(T&a,const T&b){if(a>=b)return false;a=b;return true;}//}}}
template<typename T> T s_to(string s){ //{{{
    stringstream ss;
    T res;
    ss << s;
    ss >> res;
    return res;
} //}}}


// 幾何.//{{{
typedef long double R;
const R INF = 1E40;
const R EPS = 1E-11;
const R PI = acos(R(-1));
typedef complex<R> P;
#define X real()
#define Y imag()
inline int sgn(const R& r){ return (r > EPS) - (r < -EPS); }
inline int sgn(const R& a, const R &b){ return sgn(a - b); }
namespace std {//{{{
    bool operator < (const P& a, const P& b) {
        return sgn(a.X, b.X) ? a.X < b.X : sgn(a.Y, b.Y) < 0;
    }
    istream& operator >> (istream& is, P& p) {
        R x, y; is >> x >> y;
        p = P(x, y);
        return is;
    }
}//}}}
typedef pair<P, P> L;
//}}}
// 基本.//{{{
inline R dot(const P& a, const P& b) { return real(conj(a)*b); }
inline R cross(const P& a, const P& b) { return imag(conj(a)*b); }
inline P vec(const L& l){ return l.snd - l.fst; }
enum CCW{FRONT = 1, RIGHT = 2, BACK = 4, LEFT = 8, ON = 16, };
inline int ccw(const L& l, const P& p){//{{{
    P b = p - l.fst, c = l.snd - l.fst;
    int scr = sgn(cross(c, b));
    if(scr) return scr < 0 ? RIGHT : LEFT;
    if(sgn(dot(c, b)) < 0) return BACK;
    if(sgn(norm(c) - norm(b)) < 0) return FRONT;
    return ON;
}//}}}
// not verified
R angle(const P &p){ R theta = arg(p); return sgn(theta - PI) < 0 ? theta : -PI; }
R angle(const P &base, const P &a, const P &b){ return angle((b - base) / (a - base)); }
// p が a から b の角に入ってるなら +1, 境界なら 0, 入ってないなら -1
// AOJ 0269, AOJ 2484
int sgnPPP(const P &p, const P &a, const P &b){//{{{
    return sgn(cross(a, p)) + sgn(cross(p, b)) + sgn(cross(b, a));
}//}}}
//}}}
// ccw 多角形.//{{{
// 全て counter clock wise で扱う. ccw か不明なら, sgn(area) >= 0 で check.
typedef vector<P> Poly;
#define Mod(a, m) (((a)%(m)+(m))%(m))
#define prev(P, i) P[Mod(i-1, size(P))]
#define curr(P, i) P[Mod( i , size(P))]
#define next(P, i) P[Mod(i+1, size(P))]
#define line(P, i) L(curr(P, i), next(P, i))
// 点の集合に対する ccw凸包.//{{{
// AOJ0068 (点の個数だけ), 2404
Poly convex_hull(vector<P> ps){
    int n = size(ps), k = 0;
    if(n < 3) return ps;
    sort(all(ps));
    Poly ch(2*n);
    for(int i = 0; i < n; ch[k++] = ps[i++]) // lower
        while(k >= 2 && !(ccw(L(ch[k-2], ch[k-1]), ps[i]) & LEFT)) --k;
    for(int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper
        while(k >= t && !(ccw(L(ch[k-2], ch[k-1]), ps[i]) & LEFT)) --k;
    ch.resize(k-1);
    return ch;
}
//}}}
inline bool iSP(const L& s, const P& p){ return ccw(s, p) & ON; }
int contains(const Poly& pol, const P& p){
    R sum = 0;
    repsz(i, pol){
        if(iSP(line(pol, i), p)) return 1;
        sum += arg((next(pol, i)-p)/(curr(pol, i)-p));
    }
    return (abs(sum) > 1) * 2;
}
//}}}

bool solve(){
    int n; cin >> n;
    vector<P> ps(n);
    for(aur p : ps) cin >> p;
    vector<int> res(n, max(n-2, 0));
    rep(A, 1<<n){
        vector<P> use;
        rep(i, n) if(A>>i&1) use.eb(ps[i]);
        vector<P> tmp = convex_hull(use);
        rep(i, n) if(contains(tmp, ps[i]) == 1) chmin(res[i], n - __builtin_popcount(A));
    }
    rep(i, n) cout << res[i] << endl;
    return true;
}
signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    string s;
    getline(cin, s);
    int T = s_to<int>(s);
    rep(i, T){
        cout << "Case #" << (i+1) << ":" << endl;
        solve();
    }
    return 0;
}
// vim:set foldmethod=marker commentstring=//%s:
