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

int main(void) {
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    int nb, rank; scanf("%d %d", &nb, &rank); --rank;
    const int MAXN = 1e3 + 123;
    static int M[MAXN];
    REP(i, nb) scanf("%d", M+i);

    auto calc = [&](llint t) {
      if (t < 0) return 0LL;
      llint ans = 0;
      REP(i, nb) {
        ans += 1 + t/M[i];
      }
      return ans;
    };

    llint lo = 0, hi = 1e17;
    while (lo < hi) {
      llint mid = (lo + hi) / 2;
      if (calc(mid) > rank)
        hi = mid;
      else
        lo = mid + 1;
    }

    rank -= calc(lo-1);

    printf("Case #%d: ", tc+1);
    REP(i, nb) if (lo%M[i] == 0) {
      if (--rank < 0) {
        printf("%d\n", i+1);
        break;
      }
    }

    fflush(stdout);
  }
  return 0;
}   
