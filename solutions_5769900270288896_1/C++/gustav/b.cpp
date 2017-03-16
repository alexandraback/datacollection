#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

int r, c, n;

int id(int i, int j) { return i * c + j; }

void solve() {
  scanf("%d%d%d", &r, &c, &n);
  
  int M = 1 << (r * c);
  int sol = 1000000000;
  REP(mask, M) {
    if (__builtin_popcount(mask) != n) 
      continue;

    int csol = 0;
    REP(i, r) REP(j, c) {
      if (((mask >> id(i, j)) & 1) == 0)
	continue;
      REP(d, 4) {
	int ni = i + di[d]; if (ni < 0 || ni >= r) continue;
	int nj = j + dj[d]; if (nj < 0 || nj >= c) continue;
	if (((mask >> id(ni, nj)) & 1) == 0)
	  continue;
	++csol;
      }
    }

    sol = min(sol, csol / 2);
  }

  printf("%d\n", sol);
}

void solve_fast() {
  scanf("%d%d%d", &r, &c, &n);


  int sol = r * (c - 1) + c * (r - 1);
  
  REP(it, 2) {
    int cnt[5];
    REP(i, 5) cnt[i] = 0;

    REP(i, r) REP(j, c) {
      if (i % 2 != (j + it) % 2) continue;
      int deg = 0;
      REP(d, 4) {
	int ni = i + di[d]; if (ni < 0 || ni >= r) continue;
	int nj = j + dj[d]; if (nj < 0 || nj >= c) continue;
	++deg;
      }
      ++cnt[deg];
    }

    int csol = r * (c - 1) + (r - 1) * c;
    int remove = r * c - n;
  
    for (int i = 4; i >= 0; --i) {
      int take = min(remove, cnt[i]);
      csol -= take * i;
      remove -= take;
    }

    csol = max(csol, 0);
    sol = min(sol, csol);
  }

  printf("%d\n", sol);
}

int main(void) 
{
  int T;
  scanf("%d", &T);
  FOR(tc, 1, T + 1) {
    printf("Case #%d: ", tc);
    solve_fast();
    //    solve();
  }
  return 0;
}
