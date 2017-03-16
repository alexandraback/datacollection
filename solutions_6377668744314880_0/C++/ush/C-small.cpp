
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <complex>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define ALLOF(c) (c).begin(),(c).end()
using namespace std;
typedef long long ll;
typedef complex<double> P;
typedef vector<P> G;
struct L{
  P pos, dir;
};
const double PI = acos(-1);
const double EPS = 1e-8;

bool xy_less(const P& a, const P& b) {
    if (abs(a.imag()-b.imag()) < EPS) return (a.real() < b.real());
    return (a.imag() < b.imag());
}
double ccw(P a, P b, P c) {
    return (conj(b-a)*(c-a)).imag();
}
template<class IN>
void walk_rightside(IN begin, IN end, vector<P>& v) {
    IN cur = begin;
    v.push_back(*cur++);
    vector<P>::size_type s = v.size();
    v.push_back(*cur++);
    while(cur != end) {
        if (v.size() == s || ccw(v[v.size()-2], v.back(), *cur) > -EPS)
            v.push_back(*cur++);
        else
            v.pop_back();
    }
    v.pop_back();
}
vector<P> convex_hull(vector<P> v) {
    if (v.size() <= 1)
        return v; // EXCEPTIONAL
    sort(ALLOF(v), xy_less);
    vector<P> cv;
    walk_rightside(v.begin(), v.end(), cv);
    walk_rightside(v.rbegin(), v.rend(), cv);
    return cv;
}

G cut_polygon(const G& g, L cut) {
    int n = g.size();
 
    G res;
 
    REP(i, n) {
        P from(g[i]), to(g[(i+1)%n]);
        double p1 = (conj(cut.dir)*(from-cut.pos)).imag();
        double p2 = (conj(cut.dir)*(to-cut.pos)).imag();
        if (p1 > -EPS) {
            res.push_back(from);
            if (p2 < -EPS && p1 > EPS)
                res.push_back(from - (to-from)*p1/(conj(cut.dir)*(to-from)).imag());
        }
        else if (p2 > EPS) {
            res.push_back(from - (to-from)*p1/(conj(cut.dir)*(to-from)).imag());
        }
    }
 
    return res;
}





P ps[3010];
int ans[3010];
vector<P> tmpps;
int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    int n;
    scanf("%d", &n);
    REP(i, n){
      int x, y;
      scanf("%d%d", &x, &y);
      ps[i] = P(x, y);
      ans[i] = n;
    }
    
    REP(pat, 1 << n){
      tmpps.clear();
      int cnt = n - __builtin_popcount(pat);
      REP(i, n){
	if(pat & (1 << i)){
	  tmpps.push_back(ps[i]);
	}
      }
      tmpps = convex_hull(tmpps);
      REP(i, n){
	REP(j, tmpps.size()){
	  if(tmpps[j].real() == ps[i].real() && tmpps[j].imag() == ps[i].imag()){
	    ans[i] = min(ans[i], cnt);
	    break;
	  }
	}
      }
    }
    
    
    
    printf("Case #%d:\n", iCase+1);
    REP(i, n){
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
