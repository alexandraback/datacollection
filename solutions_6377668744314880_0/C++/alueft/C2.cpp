#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

const ld EPS = 1e-8;

ld cp(const pt &a, const pt &b) { return imag(conj(a)*b); }
ld dp(const pt &a, const pt &b) { return real(conj(a)*b); }
inline bool cmp_lex_i(const pt &a, const pt &b)
{ return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real()); }

// Does NOT include points on the ends of the segment.
inline bool on_segment(const pt &a, const pt &b, const pt &p) {
  return abs(cp(b-a, p-a)) < EPS && dp(b-a, p-a) > 0 && dp(a-b, p-b) > 0; }
 
// Checks if p lies on the boundary of a polygon v.
inline bool on_boundary(const pol &v, const pt &p) { bool res = false;
  for(int i=v.size()-1,j=0;j<v.size();i=j++) res |= (on_segment(v[i], v[j], p) || abs(v[i]-p) < EPS || abs(v[j]-p) < EPS);
  return res; }
 
pol chull(pol p) { // change <= 0 to < 0 to find collinear convex hull points
  sort(p.begin(), p.end(), cmp_lex_i); int top=0, bot=1; pol ch(2*p.size());
  for (int i=0, d=1; i < p.size() && i >= 0; i += d) {
    while (top > bot && cp(ch[top-1]-ch[top-2], p[i]-ch[top-2]) < 0) top--;
    ch[top++] = p[i]; if (i == p.size()-1) d = -1, bot = top;
  } ch.resize(max(1, top-1)); return ch; } // pts returned in ccw order.

pt pts[3000];

int main() {
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    cout << "Case #" << T << ":\n";
    int n; cin >> n;
    pol p;
    ld x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      pts[i] = pt(x,y);
      p.push_back(pt(x,y));
    }
    p = chull(p);
    for (int i = 0; i < n; i++) {
      if (on_boundary(p,pts[i]))
        cout << "0\n";
      else {
        int mn = 4242;
        for (int j = 1; j < (1<<n); j++) {
          if (!((1<<i) & j))
            continue;
          pol pp;
          int sz = __builtin_popcount(j);
          if (n-sz > mn)
            continue;
          for (int k = 0; k < n; k++) {
            if ((1<<k) & j) {
              pp.push_back(pts[k]);
            }
          }
          pp = chull(pp);
          //cout << "at " << j << " " << sz << endl;
          if (on_boundary(pp,pts[i])) {
            mn = min(mn,n-sz);
            //cout << " OK with size " << sz << endl;
          }
        }
        cout << mn << "\n";
      }
    }
  }
  return 0;
}
