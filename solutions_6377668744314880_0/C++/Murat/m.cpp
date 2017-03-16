#include<bits/stdc++.h>
  
using namespace std;

template<class T> inline T sqr(const T& a) { return a * a; }
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
constexpr ld EPS = 1e-9;
constexpr ld PI = 2 * acos(0.0);
constexpr int N = 100;

pt Diff(const pt &u, const pt &v) {
  return {u.first - v.first, u.second - v.second};
}

li vp(pt u, pt v) {
  return u.first * li(v.second) - u.second * li(v.first);
}

bool Good(const vector<pt> &ps, int id) {
  int n = int(ps.size());
  pt u = ps[id];
  for (int i = 0; i < n; ++i) {
    if (i == id)
      continue;
    pt v = ps[i];
    bool sign, known = false;
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (j == i || j == id)
        continue;
      li val = vp(Diff(v, u), Diff(ps[j], u));
      if (val == 0)
        continue;
      if (known) {
        if (sign != (val > 0)) {
          ok = false;
          break;
        }
      } else {
        sign = val > 0;
        known = true;
      }
    }
    if (ok)
      return true;
  }
  return false;
}

vector<int> Solve(const vector<pt> &ps, int n) {
  if (n <= 3) {
    return vector<int>(n, 0);
  }
  vector<int> result(n, n - 3);
  int mend = (1 << n);
  for (int mask = 1; mask < mend; ++mask) {
    vector<pt> cur;
    vector<int> ids;
    int cut = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        cur.push_back(ps[i]);
        ids.push_back(i);
      } else {
        ++cut;
      }
    }
    if (int(cur.size()) < 3)
      continue;
    for (int i = 0; i < int(cur.size()); ++i) {
      int tree = ids[i];
      if (result[tree] > cut && Good(cur, i)) {
        result[tree] = cut;
      }
    }
  }
  return result;
}

int main() {
  int ts;
  scanf("%d", &ts);
  for (int it = 1; it <= ts; ++it) {
    int n;
    scanf("%d", &n);
    vector<pt> ps;
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      ps.push_back({x, y});
    }
    vector<int> ans = Solve(ps, n);
    printf("Case #%d:\n", it);
    for (int i = 0; i < n; ++i) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
