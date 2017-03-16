#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

bool a[111][111];

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int ans = n*m*4;
    REP(s, 1<<(n*m)) {
      REP(i, n) REP(j, m)
        if (s & (1<<(i*m+j))) a[i][j] = true; else
          a[i][j] = false;
      
      int cnt = 0, cnt2 = 0;
      REP(i, n) REP(j, m)
        if (a[i][j]) {
          cnt++;
          if (i+1 < n && a[i+1][j]) cnt2++;
          if (j+1 < m && a[i][j+1]) cnt2++;
        }
      if (cnt == k) ans = min(ans, cnt2);
    }

    printf("Case #%d: ", tp);
    printf("%d\n", ans);
  }
  return 0;
}
