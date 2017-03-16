#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Pt { int x, y; };
vector<Pt> pts;

llint ccw(const Pt &a, const Pt &b, const Pt &c) {
  llint ccw = a.x*llint(b.y-c.y) 
    + b.x*llint(c.y-a.y) 
    + c.x*llint(a.y-b.y);
  return ccw < 0 ? -1 : ccw > 0;
};

int main(void) {
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    int np; scanf("%d", &np);

    pts.clear(); pts.resize(np);
    REP(i, np) scanf("%d %d", &pts[i].x, &pts[i].y);

    printf("Case #%d:\n", tc+1);

    REP(ip, np) {
      int ans = np - 1;

      REP(jp, np) if (jp != ip) {
        int L = 0, R = 0;
        REP(i, np) {
          int t = ccw(pts[ip], pts[jp], pts[i]);
          if (t > 0) ++L;
          else if (t < 0) ++R;
        }
        ans = min(ans, min(L, R));
      }

      printf("%d\n", ans);
    }

    fflush(stdout);
  }
  return 0;
}   
