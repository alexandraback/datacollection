#include <bits/stdc++.h>

#define rep2(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define squere(x) ((x)*(x))
const double EPS = 1e-8;
const double INF = 1e12;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

typedef double Real;

// 点
typedef complex<Real> Pt;
typedef pair<Pt,int> Q;
namespace std {
  bool operator < (const Pt& a, const Pt& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

Real cross(const Pt& a, const Pt& b) {
  return imag(conj(a)*b);
}
Real dot(const Pt& a, const Pt& b) {
  return real(conj(a)*b);
}

inline istream& operator>>(istream& s, Pt& p) {return s >> p.real() >> p.imag();}
inline bool near(const Pt& p, const Pt& q){return abs(p - q) < EPS;}

// 線分
typedef pair<Pt,Pt> Line;

// 多角形
typedef vector<Pt> Poly;

// 円
struct Cir {
  Pt p; Real r;
  Cir(const Pt &p, Real r) : p(p), r(r) { }
};

/* ccw :
CD  : counter direction
CW  : clock wise
OS  : on segment
CCW : counter clock wise
D   : direction
 */
enum LPposit { P_CD = -2, P_CW = -1, P_OS = 0, P_CCW = 1, P_D = 2};
LPposit ccw(const Pt& p, const Pt& q, const Pt& r) {
  Real c = cross(q-p,r-p);
  if (c < -EPS) return P_CW;
  if (c >  EPS) return P_CCW;
  if (dot(q - p, r - p) < -EPS) return P_CD;
  if (dot(p - q, r - q) < -EPS) return P_D;
  return P_OS;
}

// 線分の長さ
inline Real Sabs(const Line& l) {return abs(l.first - l.second); }
// 直線と点の距離
inline Real LPdist(const Line& l, const Pt& p) {return abs(cross(l.second-l.first,p-l.first)) / Sabs(l); }
// 点と線分の距離
inline Real SPdist(Line l, Pt p) {
    Real a = abs(l.first  - p);
    Real b = abs(l.second - p);
    Real c = Sabs(l);
    if (b * b + c * c > a * a && a * a + c * c > b * b){
        return LPdist(l, p);
    }
    return min(a, b);
}

// 線分交差判定
bool crossS(const Line& p, const Line& q){
  return
    ccw(p.first, p.second, q.first) * ccw(p.first, p.second, q.second) <= 0 &&
    ccw(q.first, q.second, p.first) * ccw(q.first, q.second, p.second) <= 0;
}

// 直線の交差判定
Pt intersect(const Line& p, const Line& q) {
  Pt vp = p.second - p.first;
  Pt vq = q.second - q.first;
  Pt c(cross(vp, p.first), cross(vq, q.first));
  return Pt(cross(c, Pt(vp.real(), vq.real())), cross(c, Pt(vp.imag(), vq.imag()))) / cross(vp, vq);
}

// 直線の交点
// tested: AOJ 2003
Pt line_line_intersect(const Line &p, const Line &q)
{
    Pt b = q.second-q.first;
    Real d1 = abs(cross(b, p.first-q.first));
    Real d2 = abs(cross(b, p.second-q.first));
    Real t = d1 / (d1 + d2);
    return p.first+(p.second-p.first)*t;
}

// 多角形の面積
// tested: AOJ 1100
Real area(const Poly& p) {
  Real ret = 0.0;
  rep(i,p.size()-1) ret += cross(p[i],p[i+1]);
  ret += cross(p[p.size()-1],p[0]);
  return abs(ret / 2);
}

// 円と直線の交点
vector<Pt> circle_line_intersect(Line l,Cir c){
  vector<Pt> ret;
  Real di = LPdist(l,c.p);
  Real r=c.r;
  if(di+EPS > r) return ret;
  Pt v=(l.second-l.first);
  v/=abs(v);  
  Pt rv=v*Pt(0,1);
  rv*=di;  
  if(LPdist(l,c.p+rv) > di+EPS) rv = -rv;
  v*=sqrt(r*r-di*di);
  ret.push_back(c.p+rv-v);
  ret.push_back(c.p+rv+v);
  return ret;
}

// 円同士の交点
vector<Pt> circle_circle_intersect (Cir c, Cir d) {
    vector<Pt> ret;
    const Real dist = abs(c.p - d.p);
    const Real cr = c.r;
    const Real dr = d.r;

    if (dist > cr + dr) return ret;
    if (dist < abs(cr - dr)) return ret;

    const Real s = (cr + dr + dist) / 2.;
    const Real area = sqrt(s * (s - cr) * (s - dr) * (s - dist));
    const Real h = 2 * area / dist;

    Pt v = d.p - c.p; v /= abs(v);
    const Pt m = c.p + sqrt(cr * cr - h * h) * v;
    const Pt n = v * Pt(0, 1);

    ret.push_back(m + n * h);
    ret.push_back(m - n * h);
    return ret;
}

bool eq(Real l, Real r)
{
    return (abs(l-r) < EPS);
}

// 多角形の面積の2倍を求める
// tested: AOJ 0079
Real area2(const Poly &po)
{
    Real res = 0;
    rep(i,po.size()){
        res += cross(po[i],po[(i+1)%po.size()]);
    }
    return res;
}

// 凸包を求める
// tested: AOJ 0068
vector<int> convex_hull(vector<Pt> &ps_tmp) {
  int n = ps_tmp.size(), k = 0;
  vector<Q> ps(ps_tmp.size());
  rep(i,ps_tmp.size()) ps[i] = make_pair(ps_tmp[i],i);
  sort(ps.begin(), ps.end());
  vector<Pt> ch(2*n);
  vector<int> id(2*n);
  for (int i = 0; i < n; id[k] = ps[i].second,ch[k++] = ps[i++].first) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i].first) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; id[k] = ps[i].second ,ch[k++] = ps[i--].first) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i].first) <= 0) --k;
  id.resize(k-1);
  return id;
}

int main()
{
    int T;
    cin >> T;
    rep(case_num,T){
        int n;
        cin >> n;
        vector<Pt> pt(n);
        rep(i,n) cin >> pt[i];
        vector<int> res(n,max(n-3,0));
        rep(i,1 << n){
            vector<Pt> in;
            vector<int> id;
            rep(j,n) if(i&(1 << j)) {
                in.push_back(pt[j]);
                id.push_back(j);
            }
            // cout << "#i :" << i << endl;
            if(in.size()<3) {
                continue;
            }
            vector<int> tmp = convex_hull(in);
            rep(j,tmp.size()) {
                int tar = id[tmp[j]];
                // cout << "#included" << tar << endl;
                res[tar] = min(res[tar],n-(int)in.size());
            }
        }

        cout << "Case #" << case_num+1 << ":" << endl;
        rep(i,n) cout << res[i] << endl;
    }
    return 0;
}

