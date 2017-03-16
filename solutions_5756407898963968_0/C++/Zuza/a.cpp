#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    static int cnt[16]; memset(cnt, 0, sizeof cnt);
    REP(rep, 2) {
      int r; scanf("%d", &r); --r;
      REP(i, 4) REP(j, 4) { 
        int val; scanf("%d", &val); --val;
        if (i == r) ++cnt[val];
      }
    }
    int kol = 0, which = -1;
    REP(i, 16) if (cnt[i] == 2) { ++kol; which = i; }
    printf("Case #%d: ", tc+1);
    if (kol == 0)
      printf("Volunteer cheated!");
    else if (kol == 1) {
      assert(which != -1);
      printf("%d", which+1);
    } else {
      printf("Bad magician!");
    }
    putchar('\n');
  }
  return 0;
}
