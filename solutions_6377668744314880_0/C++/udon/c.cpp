#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<int(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
typedef complex<double> point;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

typedef vector<P> G;

struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return +2;       // a--b--c on line
  return 0;
}
set<point> convex_hull(vector<point> &ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<point> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  set<point> st;
  rep(i, k-1){
    st.insert(ch[i]);
  }
  return st;
}

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    ll n;
    vector<P> vec;
    cin>>n;
    rep(i, n){
      double x, y;
      cin>>x>>y;
      vec.PB(P(x, y));
    }
    printf("Case #%d:\n", times);
    vector<int> ans;
    rep(i, n){
      ans.PB(n-1);
    }
    for(unsigned i=0; i< (1u<<n); ++i){
      vector<P> tv;
      rep(j, n){
        if(i&(1<<j)) {
          tv.PB(vec[j]);
        }
      }
      if(tv.size()<=3) {
        int s = n-(int)tv.size();
        rep(pnum,n){
          if(!(i&(1<<pnum))) continue;
          ans[pnum] = min(ans[pnum], s);
        }
        continue;
      }
      set<P> st = convex_hull(tv);

      rep(pnum, n){
        if(!(i&(1<<pnum))) continue;
        if(st.find(vec[pnum]) != st.end()) {
          int s = n-__builtin_popcount(i);
          ans[pnum] = min(ans[pnum], s);
        }
      }

    }

    rep(i, n){
      cout<<ans[i]<<endl;
    }


  }

}
