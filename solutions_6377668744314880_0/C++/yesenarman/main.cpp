#include <bits/stdc++.h>
#define vec vector
#define sz(c) int(c.size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forr(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define fori(i, a, b) for (int i = a; i <= (b); ++i)
#define ford(i, a, b) for (int i = a; i >= (b); --i)
#define x first
#define y second
using namespace std;
typedef long long int64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pnt;

int n;
vec<pnt> p;

pnt operator-(const pnt &a, const pnt &b) {
  return pnt(a.x - b.x, a.y - b.y);
}

int64 cp(pnt a, pnt b) {
  return a.x * b.y - b.x * a.y;
}

int slv(int k) {
  if (n == 1) return 0;
  int res = n;
  forn(i, n) {
    if (i == k) continue;
    int l = 0, r = 0;
    forn(j, n) {
      if (j == i || j == k) continue;
      int64 s = cp(p[i] - p[k], p[j] - p[k]);
      if (s < 0) l += 1; else if (s > 0) r += 1;
    }
    res = min(res, l);
    res = min(res, r);
  }
  return res;
  //vec<pair<double,pnt>> ps;
  //forn(i, n)
  //  if (i != k) {
  //    double a = atan2(p[i].y - p[k].y, p[i].x - p[k].x);
  //    if (a < 0) a += 2 * M_PI;
  //    ps.emplace_back(a, p[i] - p[k]);
  //  }
  //sort(ps.begin(), ps.end());
  //int l = 0, r = 0, ml = 0, mr = 0;
  //forn(i, sz(ps)) {
  //  int64 s = cross(ps[i].second, ps[0].second);
  //  if (s == 0) {
  //    int64 s2 = sign(dot(ps[i].second, ps[0].second));
  //    assert(s2 != 0);
  //    if (s2 < 0) ml += 1; else mr += 1;
  //  } else {
  //    if (s > 0) l += 1; else r += 1;
  //  }
  //}
  //int i = 1;
  //while (i < sz(ps) && cross(ps[i].second, ps[0].second) == 0) i += 1;
  //while (i < sz(ps)) {
  //  l += ml;
  //  r += mr;
  //  ml = mr = 0;
  //  int j = i;
  //  i += 1;
  //  while (i < sz(ps) && cross(ps[j].second, ps[i].second) == 0) {
  //    int64 s = dot(ps[i
  //  }
  //}
}

void solve(int testcase) {
  cout << "Case #" << testcase << ": " << endl;
  cin >> n;
  p = vec<pnt>(n);
  forn(i, n) cin >> p[i].x >> p[i].y;
  forn(i, n) cout << slv(i) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int testcases;
  cin >> testcases;
  fori(testcase, 1, testcases) {
    cerr << "Case " << testcase << "/" << testcases << endl;
    solve(testcase);
  }

  return 0;
}
