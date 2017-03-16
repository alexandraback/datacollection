#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}

ll w, h, n;
ll calc1() {
  ll v = (w - 1) * (h - 1) * 2 + (w - 1) + (h - 1);
  ll m = w * h;
  ll d = ((w - 2) * (h - 2) + 1) / 2;
  d = min(d, m - n);
  v -= d * 4;
  m -= d;
  if (m == n) { return v; }

  d = (w - 2) / 2 * 2 + (h - 2) / 2 * 2;
  if (h % 2 == 0) { d += w % 2; }
  if (w % 2 == 0) { d += h % 2; }
  d = min(d, m - n);
  v -= d * 3;
  m -= d;
  if (m == n) { return v; }

  d = 1;
  if (w % 2 == 1) { d++; }
  if (h % 2 == 1) { d++; }
  if (w % 2 == 1 && h % 2 == 1) { d++; }
  d = min(d, m - n);
  v -= d * 2;
  m -= d;
  if (m == n) { return v; }

  assert(false);
  d = m - n;
  v -= d * 1;
  return v;
}

ll calc2() {
  ll v = (w - 1) * (h - 1) * 2 + (w - 1) + (h - 1);
  ll m = w * h;
  ll d = (w - 2) * (h - 2) / 2;
  d = min(d, m - n);
  v -= d * 4;
  m -= d;
  if (m == n) { return v; }

  d = (w - 2) / 2 * 2 + (h - 2) / 2 * 2;
  d += w % 2;
  d += h % 2;
  if (h % 2 == 1) { d += w % 2; }
  if (w % 2 == 1) { d += h % 2; }
  d = min(d, m - n);
  v -= d * 3;
  m -= d;
  if (m == n) { return v; }

  d = 0;
  if (w % 2 == 0) { d++; }
  if (h % 2 == 0) { d++; }
  if (w % 2 == 0 && h % 2 == 0) { d++; }
  d = min(d, m - n);
  v -= d * 2;
  m -= d;
  if (m == n) { return v; }

  assert(false);
  d = m - n;
  assert(d <= 4);
  v -= d * 1;
  return v;
}

void solve() {
  scanf("%lld %lld %lld", &w, &h, &n);
  ll ans = n * 4;
  if (w < h) { swap(w, h); }
  if (n <= 1 || w == 1 || n <= ((w * h) + 1) / 2) {
    ans = 0;
    goto end;
  }
  if (h == 1) {
    ll d = n - (w + 1) / 2;
    ans = 0;
    if (w % 2 == 0) { ans++; d--; }
    ans += 2 * d;
  } else {
    ans = min(ans, calc1());
    ans = min(ans, calc2());
  }
end:
  printf("%lld\n", ans);
}
