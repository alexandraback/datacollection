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

const int MAXN = 1e4 + 123;

struct Pt { int x, y; };
vector<Pt> pts;

struct Ev {
  Pt delta;
  double aval;
  int tip;
  int idx;
};

llint ccw(const Pt &a, const Pt &b, const Pt &c) {
  llint ccw = a.x*llint(b.y-c.y) 
    + b.x*llint(c.y-a.y) 
    + c.x*llint(a.y-b.y);
  return ccw < 0 ? -1 : ccw > 0;
};

enum { OUT = 0, IN = 1 };

int main(void) {
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    int np; scanf("%d", &np);

    pts.clear(); pts.resize(np);
    REP(i, np) scanf("%d %d", &pts[i].x, &pts[i].y);

    printf("Case #%d:\n", tc+1);

    REP(ip, np) {
      int ans = np - 1;

      static vector<Ev> es; es.clear();
      REP(i, np) if (i != ip) {
        Pt delta = {pts[i].x-pts[ip].x, pts[i].y-pts[ip].y};
        Pt m_delta = {-delta.x, -delta.y};
        es.push_back({delta, atan2(delta.y, delta.x), IN, i});
        es.push_back({m_delta, atan2(m_delta.y, m_delta.x), OUT, i});
      }
      sort(es.begin(), es.end(), [](const Ev& a, const Ev& b) {
          if (a.aval != b.aval) return a.aval < b.aval;
          if (a.tip != b.tip) return a.tip < b.tip;
          return a.idx < b.idx;
        });

      static int bio[MAXN] = {0};
      static int cookie = 123; ++cookie;

      int inside = 0;
      REP(r, 2) {
        for (auto e : es) {
          if (e.tip == OUT) {
            if (bio[e.idx] == cookie) {
              --inside;
            }
          } else { // IN
            bio[e.idx] = cookie;
            ++inside;
          }
          if (r > 0) ans = min(ans, inside);
        }
      }

      printf("%d\n", ans);
    }

    fflush(stdout);
  }
  return 0;
}   
